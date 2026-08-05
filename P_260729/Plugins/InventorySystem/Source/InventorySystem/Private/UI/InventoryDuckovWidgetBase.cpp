#include "UI/InventoryDuckovWidgetBase.h"

#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/BackgroundBlur.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/ButtonSlot.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/ContentWidget.h"
#include "Components/InventoryComponent.h"
#include "Components/InventoryContainerComponent.h"
#include "Components/PanelWidget.h"
#include "Components/ScrollBox.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "Components/UniformGridPanel.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Components/Widget.h"
#include "Blueprint/WidgetTree.h"
#include "Brushes/SlateColorBrush.h"
#include "Brushes/SlateRoundedBoxBrush.h"
#include "Input/Events.h"
#include "InputCoreTypes.h"
#include "UI/InventoryContextActionWidgetBase.h"
#include "UI/InventoryContextMenuWidgetBase.h"
#include "UI/InventoryDuckovSlotWidgetBase.h"
#include "UI/InventoryTooltipWidgetBase.h"

UInventoryDuckovWidgetBase::UInventoryDuckovWidgetBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SlotWidgetClass = UInventoryDuckovSlotWidgetBase::StaticClass();
	TooltipWidgetClass = UInventoryTooltipWidgetBase::StaticClass();
	ContextMenuWidgetClass = UInventoryContextMenuWidgetBase::StaticClass();
	ContextActionWidgetClass = UInventoryContextActionWidgetBase::StaticClass();
}

void UInventoryDuckovWidgetBase::NativePreConstruct()
{
	Super::NativePreConstruct();
	EnsureExternalContainerWidgets();
	PrepareInventoryLayout();
	BuildPanelBlurIfNeeded();
	BuildSortButtonIfNeeded();
	ApplyDuckovPanelStyle();
	ApplySortButtonStyle();
}

void UInventoryDuckovWidgetBase::EnsureExternalContainerWidgets()
{
	if (UniformGridPanel_ContainerItems || !Panel_ExternalContainer || !WidgetTree)
	{
		return;
	}

	RuntimeExternalContainerBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("Border_ExternalContainerRuntime"));
	RuntimeExternalContainerBorder->SetBrush(FSlateRoundedBoxBrush(
		FLinearColor(0.025f, 0.075f, 0.125f, 0.82f),
		14.0f,
		FLinearColor(0.33f, 0.48f, 0.58f, 0.88f),
		1.5f));
	RuntimeExternalContainerBorder->SetBrushColor(FLinearColor::White);
	RuntimeExternalContainerBorder->SetPadding(FMargin(16.0f));

	UVerticalBox* ContainerLayout = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("VerticalBox_ExternalContainerRuntime"));
	Text_ContainerName = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("Text_ContainerName"));
	Text_ContainerName->SetText(ExternalContainer ? ExternalContainer->ContainerName : NSLOCTEXT("InventorySystem", "LootContainerTitle", "Loot"));
	FSlateFontInfo HeaderFont = Text_ContainerName->GetFont();
	HeaderFont.Size = 21;
	HeaderFont.OutlineSettings.OutlineSize = 1;
	HeaderFont.OutlineSettings.OutlineColor = FLinearColor(0.01f, 0.025f, 0.04f, 0.92f);
	Text_ContainerName->SetFont(HeaderFont);
	Text_ContainerName->SetColorAndOpacity(FSlateColor(FLinearColor(0.93f, 0.97f, 0.98f, 1.0f)));
	Text_ContainerName->SetShadowOffset(FVector2D(1.0f, 1.0f));
	Text_ContainerName->SetShadowColorAndOpacity(FLinearColor(0.0f, 0.0f, 0.0f, 0.72f));
	if (UVerticalBoxSlot* HeaderSlot = ContainerLayout->AddChildToVerticalBox(Text_ContainerName))
	{
		HeaderSlot->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 10.0f));
		HeaderSlot->SetHorizontalAlignment(HAlign_Left);
	}

	UScrollBox* ScrollBox = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("ScrollBox_ExternalContainerRuntime"));
	UniformGridPanel_ContainerItems = WidgetTree->ConstructWidget<UUniformGridPanel>(UUniformGridPanel::StaticClass(), TEXT("UniformGridPanel_ContainerItems"));
	UniformGridPanel_ContainerItems->SetMinDesiredSlotWidth(80.0f);
	UniformGridPanel_ContainerItems->SetMinDesiredSlotHeight(80.0f);
	UniformGridPanel_ContainerItems->SetSlotPadding(FMargin(4.0f));
	ScrollBox->SetScrollBarVisibility(ESlateVisibility::Collapsed);
	ScrollBox->AddChild(UniformGridPanel_ContainerItems);
	if (UVerticalBoxSlot* ScrollSlot = ContainerLayout->AddChildToVerticalBox(ScrollBox))
	{
		ScrollSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
		ScrollSlot->SetHorizontalAlignment(HAlign_Fill);
		ScrollSlot->SetVerticalAlignment(VAlign_Fill);
	}
	RuntimeExternalContainerBorder->SetContent(ContainerLayout);

	if (UContentWidget* ContentHost = Cast<UContentWidget>(Panel_ExternalContainer))
	{
		ContentHost->SetContent(RuntimeExternalContainerBorder);
	}
	else if (UPanelWidget* PanelHost = Cast<UPanelWidget>(Panel_ExternalContainer))
	{
		PanelHost->AddChild(RuntimeExternalContainerBorder);
	}
}

void UInventoryDuckovWidgetBase::PrepareInventoryLayout()
{
	// Blueprint defaults may contain an older column count. Keep every rebuild deterministic.
	GridColumnCount = 5;
	bShowEmptySlots = true;
	if (UniformGridPanel_Items)
	{
		UniformGridPanel_Items->SetMinDesiredSlotWidth(88.0f);
		UniformGridPanel_Items->SetMinDesiredSlotHeight(88.0f);
		UniformGridPanel_Items->SetSlotPadding(FMargin(4.0f));
	}
}

void UInventoryDuckovWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();
	if (Button_Sort)
	{
		Button_Sort->OnClicked.AddUniqueDynamic(this, &UInventoryDuckovWidgetBase::HandleSortClicked);
	}
	if (Panel_PlayerInventory)
	{
		Panel_PlayerInventory->SetVisibility(ESlateVisibility::Visible);
	}
	if (Panel_ExternalContainer)
	{
		Panel_ExternalContainer->SetVisibility(ExternalContainer ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	}
	if (Text_PlayerContainerName && Text_PlayerContainerName->GetText().IsEmpty())
	{
		Text_PlayerContainerName->SetText(NSLOCTEXT("InventorySystem", "PlayerInventoryName", "인벤토리"));
	}
	if (CanvasPanel_TooltipLayer)
	{
		CanvasPanel_TooltipLayer->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	}
	if (CanvasPanel_ContextMenuLayer)
	{
		// Ignore the full-screen layer itself while keeping menu children interactive.
		CanvasPanel_ContextMenuLayer->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	}
	UpdateBackpackHeader();
	CloseTransientWidgets();
	RebuildExternalContainerGrid();
}

void UInventoryDuckovWidgetBase::NativeDestruct()
{
	if (ExternalContainer)
	{
		ExternalContainer->OnInventoryChanged.RemoveDynamic(this, &UInventoryDuckovWidgetBase::HandleExternalContainerChanged);
	}
	if (Button_Sort)
	{
		Button_Sort->OnClicked.RemoveDynamic(this, &UInventoryDuckovWidgetBase::HandleSortClicked);
	}
	CloseTransientWidgets();
	Super::NativeDestruct();
}

void UInventoryDuckovWidgetBase::RefreshInventory()
{
	HideTooltip();
	HideContextMenu();
	Super::RefreshInventory();
	UpdateBackpackHeader();
	if (Panel_ExternalContainer)
	{
		Panel_ExternalContainer->SetVisibility(ExternalContainer ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	}
	RebuildExternalContainerGrid();
}

void UInventoryDuckovWidgetBase::SetExternalContainer(UInventoryContainerComponent* InContainer)
{
	if (ExternalContainer == InContainer)
	{
		RebuildExternalContainerGrid();
		return;
	}
	if (ExternalContainer)
	{
		ExternalContainer->OnInventoryChanged.RemoveDynamic(this, &UInventoryDuckovWidgetBase::HandleExternalContainerChanged);
	}
	ExternalContainer = InContainer;
	if (ExternalContainer)
	{
		ExternalContainer->OnInventoryChanged.AddUniqueDynamic(this, &UInventoryDuckovWidgetBase::HandleExternalContainerChanged);
	}
	if (Panel_ExternalContainer)
	{
		Panel_ExternalContainer->SetVisibility(ExternalContainer ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	}
	if (Text_ContainerName)
	{
		Text_ContainerName->SetText(ExternalContainer ? ExternalContainer->ContainerName : FText::GetEmpty());
	}
	RebuildExternalContainerGrid();
}

void UInventoryDuckovWidgetBase::HandleExternalContainerChanged()
{
	RebuildExternalContainerGrid();
}

void UInventoryDuckovWidgetBase::RebuildExternalContainerGrid()
{
	if (!UniformGridPanel_ContainerItems)
	{
		return;
	}
	UniformGridPanel_ContainerItems->ClearChildren();
	if (!ExternalContainer || !SlotWidgetClass)
	{
		return;
	}
	const TArray<FInventorySlot>& ContainerSlots = ExternalContainer->GetSlotsNative();
	const int32 SlotCount = bShowEmptySlots ? ExternalContainer->GetMaxInventorySlots() : ContainerSlots.Num();
	for (int32 SlotIndex = 0; SlotIndex < SlotCount; ++SlotIndex)
	{
		const FInventorySlot SlotData = ContainerSlots.IsValidIndex(SlotIndex) ? ContainerSlots[SlotIndex] : FInventorySlot();
		UInventorySlotWidgetBase* SlotWidget = CreateWidget<UInventorySlotWidgetBase>(GetOwningPlayer(), SlotWidgetClass);
		if (!SlotWidget)
		{
			continue;
		}
		SlotWidget->InitializeSlotForInventory(this, ExternalContainer, SlotIndex, SlotData.ItemDefinition, SlotData.Quantity);
		UniformGridPanel_ContainerItems->AddChildToUniformGrid(SlotWidget, SlotIndex / GridColumnCount, SlotIndex % GridColumnCount);
	}
}

void UInventoryDuckovWidgetBase::HandleSlotDragStarted()
{
	HideTooltip();
	HideContextMenu();
	ResetAllSlotHoverStates();
}

void UInventoryDuckovWidgetBase::HandleSlotDragFinished()
{
	ResetAllSlotHoverStates();
}

bool UInventoryDuckovWidgetBase::HandleSlotDrop(UInventoryComponent* SourceInventory, int32 SourceSlotIndex, UInventoryComponent* DestinationInventory, int32 DestinationSlotIndex, bool bSplitStack)
{
	HideTooltip();
	HideContextMenu();
	ResetAllSlotHoverStates();
	if (!SourceInventory || !DestinationInventory)
	{
		return false;
	}
	FInventorySlot SourceSlot;
	if (!SourceInventory->GetSlot(SourceSlotIndex, SourceSlot))
	{
		return false;
	}
	const int32 Quantity = bSplitStack && SourceSlot.Quantity > 1 ? FMath::Max(1, SourceSlot.Quantity / 2) : SourceSlot.Quantity;
	const EInventoryOperationResult Result = SourceInventory->MoveItem(DestinationInventory, SourceSlotIndex, DestinationSlotIndex, Quantity);
	if (Result != EInventoryOperationResult::Success)
	{
		OnInventoryOperationFailed(Result);
		return false;
	}
	return true;
}

bool UInventoryDuckovWidgetBase::TransferSlotToPairedInventory(UInventoryComponent* SourceInventory, int32 SourceSlotIndex, bool bSplitStack)
{
	if (!SourceInventory || !InventoryComponent || !ExternalContainer)
	{
		return false;
	}
	UInventoryComponent* Destination = SourceInventory == ExternalContainer
		? InventoryComponent.Get()
		: static_cast<UInventoryComponent*>(ExternalContainer.Get());
	if (Destination == SourceInventory)
	{
		return false;
	}
	FInventorySlot SourceSlot;
	if (!SourceInventory->GetSlot(SourceSlotIndex, SourceSlot))
	{
		return false;
	}
	const int32 Quantity = bSplitStack && SourceSlot.Quantity > 1 ? FMath::Max(1, SourceSlot.Quantity / 2) : SourceSlot.Quantity;
	const EInventoryOperationResult Result = SourceInventory->MoveItem(Destination, SourceSlotIndex, INDEX_NONE, Quantity);
	if (Result != EInventoryOperationResult::Success)
	{
		OnInventoryOperationFailed(Result);
		return false;
	}
	return true;
}

void UInventoryDuckovWidgetBase::ResetAllSlotHoverStates()
{
	RegisteredSlotWidgets.RemoveAll([](const TWeakObjectPtr<UInventorySlotWidgetBase>& Entry)
	{
		return !Entry.IsValid();
	});
	for (const TWeakObjectPtr<UInventorySlotWidgetBase>& Entry : RegisteredSlotWidgets)
	{
		if (UInventoryDuckovSlotWidgetBase* SlotWidget = Cast<UInventoryDuckovSlotWidgetBase>(Entry.Get()))
		{
			SlotWidget->ResetHoverState();
		}
	}
}

void UInventoryDuckovWidgetBase::HandleSortClicked()
{
	HideTooltip();
	HideContextMenu();
	if (InventoryComponent)
	{
		InventoryComponent->SortItemsByQuantityDescending();
	}
}

void UInventoryDuckovWidgetBase::BuildSortButtonIfNeeded()
{
	if (Button_Sort || !HorizontalBox_Header || !WidgetTree)
	{
		return;
	}

	Button_Sort = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("Button_Sort"));
	UTextBlock* Label = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("Text_SortLabel"));
	Label->SetText(NSLOCTEXT("InventorySystem", "SortByQuantity", "Sort"));
	Label->SetJustification(ETextJustify::Center);
	Label->SetColorAndOpacity(FSlateColor(FLinearColor(0.04f, 0.13f, 0.17f, 1.0f)));
	Button_Sort->SetBackgroundColor(FLinearColor(0.76f, 0.91f, 0.94f, 1.0f));
	Button_Sort->AddChild(Label);
	if (UButtonSlot* LabelSlot = Cast<UButtonSlot>(Label->Slot))
	{
		LabelSlot->SetPadding(FMargin(16.0f, 7.0f));
	}
	UWidget* CloseBox = WidgetTree->FindWidget(TEXT("SizeBox_Close"));
	if (CloseBox && CloseBox->GetParent() == HorizontalBox_Header)
	{
		HorizontalBox_Header->RemoveChild(CloseBox);
	}
	if (UHorizontalBoxSlot* SortSlot = HorizontalBox_Header->AddChildToHorizontalBox(Button_Sort))
	{
		SortSlot->SetVerticalAlignment(VAlign_Center);
		SortSlot->SetPadding(FMargin(0.0f, 0.0f, 8.0f, 0.0f));
	}
	if (CloseBox)
	{
		if (UHorizontalBoxSlot* CloseSlot = HorizontalBox_Header->AddChildToHorizontalBox(CloseBox))
		{
			CloseSlot->SetVerticalAlignment(VAlign_Center);
		}
	}
}

void UInventoryDuckovWidgetBase::BuildPanelBlurIfNeeded()
{
	if (PlayerPanelBackgroundBlur || !Panel_PlayerInventory || !WidgetTree)
	{
		return;
	}
	UCanvasPanel* ParentCanvas = Cast<UCanvasPanel>(Panel_PlayerInventory->GetParent());
	if (!ParentCanvas)
	{
		return;
	}

	PlayerPanelBackgroundBlur = WidgetTree->ConstructWidget<UBackgroundBlur>(
		UBackgroundBlur::StaticClass(),
		TEXT("BackgroundBlur_PlayerPanel"));
	PlayerPanelBackgroundBlur->SetBlurStrength(6.0f);
	PlayerPanelBackgroundBlur->SetBlurRadius(12);
	PlayerPanelBackgroundBlur->SetApplyAlphaToBlur(true);
	PlayerPanelBackgroundBlur->SetCornerRadius(FVector4(14.0f));
	PlayerPanelBackgroundBlur->SetLowQualityFallbackBrush(
		FSlateColorBrush(FLinearColor(0.025f, 0.075f, 0.125f, 0.82f)));
	PlayerPanelBackgroundBlur->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	if (UCanvasPanelSlot* BlurSlot = ParentCanvas->AddChildToCanvas(PlayerPanelBackgroundBlur))
	{
		if (const UCanvasPanelSlot* PlayerCanvasSlot = Cast<UCanvasPanelSlot>(Panel_PlayerInventory->Slot))
		{
			BlurSlot->SetAnchors(PlayerCanvasSlot->GetAnchors());
			BlurSlot->SetAlignment(PlayerCanvasSlot->GetAlignment());
			BlurSlot->SetPosition(PlayerCanvasSlot->GetPosition());
			BlurSlot->SetSize(PlayerCanvasSlot->GetSize());
			BlurSlot->SetAutoSize(PlayerCanvasSlot->GetAutoSize());
			BlurSlot->SetZOrder(PlayerCanvasSlot->GetZOrder() - 1);
		}
	}
}

void UInventoryDuckovWidgetBase::ApplyDuckovPanelStyle()
{
	if (Border_PlayerPanel)
	{
		Border_PlayerPanel->SetBrush(FSlateRoundedBoxBrush(
			FLinearColor(0.025f, 0.075f, 0.125f, 0.74f),
			14.0f,
			FLinearColor(0.33f, 0.48f, 0.58f, 0.82f),
			1.5f));
		Border_PlayerPanel->SetBrushColor(FLinearColor::White);
		Border_PlayerPanel->SetPadding(FMargin(16.0f));
	}
	if (Text_PlayerContainerName)
	{
		FSlateFontInfo HeaderFont = Text_PlayerContainerName->GetFont();
		HeaderFont.Size = 21;
		HeaderFont.OutlineSettings.OutlineSize = 1;
		HeaderFont.OutlineSettings.OutlineColor = FLinearColor(0.01f, 0.025f, 0.04f, 0.92f);
		Text_PlayerContainerName->SetFont(HeaderFont);
		Text_PlayerContainerName->SetColorAndOpacity(FSlateColor(FLinearColor(0.93f, 0.97f, 0.98f, 1.0f)));
		Text_PlayerContainerName->SetShadowOffset(FVector2D(1.0f, 1.0f));
		Text_PlayerContainerName->SetShadowColorAndOpacity(FLinearColor(0.0f, 0.0f, 0.0f, 0.72f));
	}
}

void UInventoryDuckovWidgetBase::ApplySortButtonStyle()
{
	if (Button_Sort)
	{
		FButtonStyle Style = Button_Sort->GetStyle();
		Style.SetNormal(FSlateRoundedBoxBrush(FLinearColor(0.70f, 0.84f, 0.87f, 0.96f), 7.0f));
		Style.SetHovered(FSlateRoundedBoxBrush(
			FLinearColor(0.82f, 0.96f, 0.96f, 1.0f),
			7.0f,
			FLinearColor(0.08f, 0.82f, 0.76f, 1.0f),
			1.5f));
		Style.SetPressed(FSlateRoundedBoxBrush(FLinearColor(0.32f, 0.70f, 0.70f, 1.0f), 7.0f));
		Style.SetDisabled(FSlateRoundedBoxBrush(FLinearColor(0.22f, 0.31f, 0.34f, 0.55f), 7.0f));
		Style.SetNormalPadding(FMargin(14.0f, 7.0f));
		Style.SetPressedPadding(FMargin(14.0f, 8.0f, 14.0f, 6.0f));
		Button_Sort->SetStyle(Style);
		Button_Sort->SetBackgroundColor(FLinearColor::White);
	}
	if (Button_Close)
	{
		FButtonStyle CloseStyle = Button_Close->GetStyle();
		CloseStyle.SetNormal(FSlateRoundedBoxBrush(FLinearColor(0.32f, 0.40f, 0.44f, 0.86f), 6.0f));
		CloseStyle.SetHovered(FSlateRoundedBoxBrush(FLinearColor(0.18f, 0.66f, 0.65f, 0.95f), 6.0f));
		CloseStyle.SetPressed(FSlateRoundedBoxBrush(FLinearColor(0.10f, 0.45f, 0.46f, 1.0f), 6.0f));
		Button_Close->SetStyle(CloseStyle);
		Button_Close->SetBackgroundColor(FLinearColor::White);
	}
}

void UInventoryDuckovWidgetBase::UpdateBackpackHeader()
{
	const int32 Occupied = InventoryComponent ? InventoryComponent->GetOccupiedSlotCount() : 0;
	const int32 Capacity = InventoryComponent ? InventoryComponent->GetMaxInventorySlots() : 0;
	if (Text_PlayerContainerName)
	{
		Text_PlayerContainerName->SetText(FText::Format(
			NSLOCTEXT("InventorySystem", "BackpackCapacity", "Backpack ({0}/{1})"),
			FText::AsNumber(Occupied),
			FText::AsNumber(Capacity)));
	}
	if (Text_Capacity)
	{
		Text_Capacity->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UInventoryDuckovWidgetBase::BeginCloseTransition()
{
	CloseTransientWidgets();
	Super::BeginCloseTransition();
}

void UInventoryDuckovWidgetBase::BeginInspectTransition()
{
	CloseTransientWidgets();
	Super::BeginInspectTransition();
}

FReply UInventoryDuckovWidgetBase::NativeOnPreviewKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	if (InKeyEvent.GetKey() == EKeys::Escape
		&& ContextMenuWidget
		&& ContextMenuWidget->GetVisibility() != ESlateVisibility::Collapsed)
	{
		HideContextMenu();
		return FReply::Handled();
	}
	return Super::NativeOnPreviewKeyDown(InGeometry, InKeyEvent);
}

FReply UInventoryDuckovWidgetBase::NativeOnMouseButtonDown(
	const FGeometry& InGeometry,
	const FPointerEvent& InMouseEvent)
{
	if (InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton
		&& ContextMenuWidget
		&& ContextMenuWidget->GetVisibility() != ESlateVisibility::Collapsed)
	{
		HideContextMenu();
	}
	return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
}

void UInventoryDuckovWidgetBase::HandleSlotHovered(
	UInventoryDuckovSlotWidgetBase* SlotWidget,
	const FVector2D& ScreenPosition)
{
	if (!IsValid(SlotWidget)
		|| (ContextMenuWidget && ContextMenuWidget->GetVisibility() != ESlateVisibility::Collapsed))
	{
		return;
	}

	FInventorySlotViewData Data;
	if (!MakeSlotViewData(SlotWidget->GetSlotIndex(), Data) || !EnsureTooltipWidget())
	{
		HideTooltip();
		return;
	}

	ActiveTooltipWidget->SetTooltipData(Data);
	PositionPopup(ActiveTooltipWidget, CanvasPanel_TooltipLayer, ScreenPosition, FVector2D(22.0f, 18.0f));
}

void UInventoryDuckovWidgetBase::HandleSlotUnhovered(UInventoryDuckovSlotWidgetBase* SlotWidget)
{
	if (!ActiveTooltipWidget || !IsValid(SlotWidget))
	{
		return;
	}
	if (ActiveTooltipWidget->GetTooltipData().SlotIndex == SlotWidget->GetSlotIndex())
	{
		HideTooltip();
	}
}

bool UInventoryDuckovWidgetBase::HandleSlotContextRequested(
	UInventoryDuckovSlotWidgetBase* SlotWidget,
	const FVector2D& ScreenPosition)
{
	if (!IsValid(SlotWidget))
	{
		return false;
	}

	FInventorySlotViewData Data;
	if (!MakeSlotViewData(SlotWidget->GetSlotIndex(), Data))
	{
		return false;
	}
	const TArray<FInventoryContextAction> Actions = FInventoryUIPresentationUtils::BuildContextActions(Data);
	if (Actions.IsEmpty() || !EnsureContextMenuWidget())
	{
		HideContextMenu();
		return false;
	}

	SelectSlot(Data.SlotIndex);
	HideTooltip();
	if (!ContextMenuWidget->SetMenuData(Data, Actions))
	{
		return false;
	}
	PositionPopup(ContextMenuWidget, CanvasPanel_ContextMenuLayer, ScreenPosition, FVector2D(8.0f, 8.0f));
	return true;
}

void UInventoryDuckovWidgetBase::HandleContextActionRequested(
	EInventoryContextActionId ActionId,
	FGuid InstanceId)
{
	if (!InventoryComponent)
	{
		HideContextMenu();
		return;
	}

	const int32 CurrentSlotIndex = FInventoryUIPresentationUtils::FindSlotIndexByInstanceId(
		InventoryComponent->GetSlotsNative(),
		InstanceId);
	if (CurrentSlotIndex == INDEX_NONE || !SelectSlot(CurrentSlotIndex))
	{
		HideContextMenu();
		return;
	}

	HideContextMenu();
	switch (ActionId)
	{
	case EInventoryContextActionId::Use:
		UseSelectedItem();
		break;
	case EInventoryContextActionId::Drop:
		DropSelectedItem(1);
		break;
	case EInventoryContextActionId::Inspect:
		InspectSelectedItem();
		break;
	default:
		break;
	}
}

void UInventoryDuckovWidgetBase::CloseTransientWidgets()
{
	if (ContextMenuWidget)
	{
		ContextMenuWidget->OnActionRequested.RemoveDynamic(this, &UInventoryDuckovWidgetBase::HandleContextActionRequested);
		ContextMenuWidget->ClearMenu();
		ContextMenuWidget->RemoveFromParent();
		ContextMenuWidget = nullptr;
	}
	if (ActiveTooltipWidget)
	{
		ActiveTooltipWidget->ClearTooltipData();
		ActiveTooltipWidget->RemoveFromParent();
		ActiveTooltipWidget = nullptr;
	}
}

bool UInventoryDuckovWidgetBase::EnsureTooltipWidget()
{
	if (ActiveTooltipWidget)
	{
		return true;
	}
	if (!CanvasPanel_TooltipLayer || !TooltipWidgetClass)
	{
		return false;
	}
	ActiveTooltipWidget = CreateWidget<UInventoryTooltipWidgetBase>(GetOwningPlayer(), TooltipWidgetClass);
	if (!ActiveTooltipWidget)
	{
		return false;
	}
	if (UCanvasPanelSlot* CanvasChildSlot = CanvasPanel_TooltipLayer->AddChildToCanvas(ActiveTooltipWidget))
	{
		CanvasChildSlot->SetAutoSize(true);
		CanvasChildSlot->SetZOrder(100);
	}
	ActiveTooltipWidget->SetVisibility(ESlateVisibility::Collapsed);
	return true;
}

bool UInventoryDuckovWidgetBase::EnsureContextMenuWidget()
{
	if (ContextMenuWidget)
	{
		return true;
	}
	if (!CanvasPanel_ContextMenuLayer || !ContextMenuWidgetClass)
	{
		return false;
	}
	ContextMenuWidget = CreateWidget<UInventoryContextMenuWidgetBase>(GetOwningPlayer(), ContextMenuWidgetClass);
	if (!ContextMenuWidget)
	{
		return false;
	}
	if (!ContextMenuWidget->ActionWidgetClass)
	{
		ContextMenuWidget->ActionWidgetClass = ContextActionWidgetClass;
	}
	ContextMenuWidget->OnActionRequested.AddUniqueDynamic(this, &UInventoryDuckovWidgetBase::HandleContextActionRequested);
	if (UCanvasPanelSlot* CanvasChildSlot = CanvasPanel_ContextMenuLayer->AddChildToCanvas(ContextMenuWidget))
	{
		CanvasChildSlot->SetAutoSize(true);
		CanvasChildSlot->SetZOrder(110);
	}
	ContextMenuWidget->SetVisibility(ESlateVisibility::Collapsed);
	return true;
}

void UInventoryDuckovWidgetBase::HideTooltip()
{
	if (ActiveTooltipWidget)
	{
		ActiveTooltipWidget->ClearTooltipData();
	}
}

void UInventoryDuckovWidgetBase::HideContextMenu()
{
	if (ContextMenuWidget)
	{
		ContextMenuWidget->ClearMenu();
	}
}

void UInventoryDuckovWidgetBase::PositionPopup(
	UWidget* Popup,
	UCanvasPanel* Layer,
	const FVector2D& ScreenPosition,
	const FVector2D& Offset)
{
	if (!Popup || !Layer)
	{
		return;
	}
	UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(Popup->Slot);
	if (!CanvasSlot)
	{
		return;
	}

	ForceLayoutPrepass();
	const FGeometry& LayerGeometry = Layer->GetCachedGeometry();
	const FVector2D LocalPosition = LayerGeometry.AbsoluteToLocal(ScreenPosition) + Offset;
	const FVector2D ClampedPosition = FInventoryUIPresentationUtils::ClampPopupPosition(
		LocalPosition,
		Popup->GetDesiredSize(),
		LayerGeometry.GetLocalSize());
	CanvasSlot->SetPosition(ClampedPosition);
}

bool UInventoryDuckovWidgetBase::MakeSlotViewData(int32 SlotIndex, FInventorySlotViewData& OutData) const
{
	FInventorySlot InventorySlot;
	if (!InventoryComponent || !InventoryComponent->GetSlot(SlotIndex, InventorySlot))
	{
		OutData = FInventorySlotViewData();
		return false;
	}
	OutData = FInventoryUIPresentationUtils::MakeSlotViewData(InventorySlot, SlotIndex);
	return OutData.IsValid();
}
