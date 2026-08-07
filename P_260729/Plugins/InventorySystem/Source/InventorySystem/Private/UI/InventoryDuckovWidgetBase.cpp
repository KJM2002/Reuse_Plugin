#include "UI/InventoryDuckovWidgetBase.h"

#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/BackgroundBlur.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/ButtonSlot.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/Image.h"
#include "Components/ContentWidget.h"
#include "Components/InventoryComponent.h"
#include "Components/InventoryContainerComponent.h"
#include "Components/InventoryUIComponent.h"
#include "Components/PanelWidget.h"
#include "Components/ScrollBox.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "Components/UniformGridPanel.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Components/Widget.h"
#include "Engine/Font.h"
#include "Blueprint/WidgetTree.h"
#include "Brushes/SlateColorBrush.h"
#include "Brushes/SlateRoundedBoxBrush.h"
#include "Input/Events.h"
#include "InputCoreTypes.h"
#include "UI/InventoryContextActionWidgetBase.h"
#include "UI/InventoryContextMenuWidgetBase.h"
#include "UI/InventoryDuckovSlotWidgetBase.h"
#include "UI/InventoryQuantityDialogWidgetBase.h"
#include "UI/InventoryTooltipWidgetBase.h"

UInventoryDuckovWidgetBase::UInventoryDuckovWidgetBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SlotWidgetClass = UInventoryDuckovSlotWidgetBase::StaticClass();
	TooltipWidgetClass = UInventoryTooltipWidgetBase::StaticClass();
	ContextMenuWidgetClass = UInventoryContextMenuWidgetBase::StaticClass();
	ContextActionWidgetClass = UInventoryContextActionWidgetBase::StaticClass();
	QuantityDialogWidgetClass = UInventoryQuantityDialogWidgetBase::StaticClass();
	ContainerHeaderTextFormat = NSLOCTEXT("InventorySystem", "ContainerHeaderFormat", "{0}");
	DefaultLootContainerText = NSLOCTEXT("InventorySystem", "LootContainerTitle", "Loot");
	SortButtonText = NSLOCTEXT("InventorySystem", "SortByQuantity", "Sort");
	CurrencyTextFormat = NSLOCTEXT("InventorySystem", "CurrencyAmountFormat", "{0}");
}

void UInventoryDuckovWidgetBase::NativePreConstruct()
{
	Super::NativePreConstruct();
	EnsureExternalContainerWidgets();
	PrepareInventoryLayout();
	BuildPanelBlurIfNeeded();
	EnsureCurrencyHeader();
	BuildSortButtonIfNeeded();
	ApplyDuckovPanelStyle();
	ApplySortButtonStyle();
	ApplyDuckovTypography();
	ApplyHeaderLayout();
	ApplyCurrencyDisplay();
	ApplyReferencePanelSizing();
}

void UInventoryDuckovWidgetBase::EnsureExternalContainerWidgets()
{
	if (UniformGridPanel_ContainerItems || !Panel_ExternalContainer || !WidgetTree)
	{
		return;
	}

	RuntimeExternalContainerBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("Border_ExternalContainerRuntime"));
	RuntimeExternalContainerBorder->SetBrush(FSlateRoundedBoxBrush(
		FLinearColor(0.012f, 0.036f, 0.068f, 0.94f),
		8.0f,
		FLinearColor(0.34f, 0.56f, 0.68f, 0.92f),
		1.25f));
	RuntimeExternalContainerBorder->SetBrushColor(FLinearColor::White);
	RuntimeExternalContainerBorder->SetPadding(FMargin(10.0f));

	UVerticalBox* ContainerLayout = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("VerticalBox_ExternalContainerRuntime"));
	Text_ContainerName = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("Text_ContainerName"));
	UpdateContainerHeader();
	FSlateFontInfo HeaderFont = Text_ContainerName->GetFont();
	if (UFont* LoadedSemiBoldFont = SemiBoldFont.LoadSynchronous()) HeaderFont.FontObject = LoadedSemiBoldFont;
	HeaderFont.Size = FMath::Max(1, LootHeaderFontSize);
	HeaderFont.OutlineSettings.OutlineSize = 1;
	HeaderFont.OutlineSettings.OutlineColor = FLinearColor(0.01f, 0.025f, 0.04f, 0.92f);
	Text_ContainerName->SetFont(HeaderFont);
	Text_ContainerName->SetColorAndOpacity(FSlateColor(FLinearColor(0.93f, 0.97f, 0.98f, 1.0f)));
	Text_ContainerName->SetShadowOffset(FVector2D(1.0f, 1.0f));
	Text_ContainerName->SetShadowColorAndOpacity(FLinearColor(0.0f, 0.0f, 0.0f, 0.72f));
	if (UVerticalBoxSlot* HeaderSlot = ContainerLayout->AddChildToVerticalBox(Text_ContainerName))
	{
		HeaderSlot->SetPadding(LootHeaderPadding);
		HeaderSlot->SetHorizontalAlignment(HAlign_Left);
	}
	Text_ContainerName->SetRenderTranslation(LootHeaderPositionOffset);

	UScrollBox* ScrollBox = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("ScrollBox_ExternalContainerRuntime"));
	UniformGridPanel_ContainerItems = WidgetTree->ConstructWidget<UUniformGridPanel>(UUniformGridPanel::StaticClass(), TEXT("UniformGridPanel_ContainerItems"));
	UniformGridPanel_ContainerItems->SetMinDesiredSlotWidth(CompactGridSlotSize);
	UniformGridPanel_ContainerItems->SetMinDesiredSlotHeight(CompactGridSlotSize);
	UniformGridPanel_ContainerItems->SetSlotPadding(FMargin(CompactGridPadding));
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
		UniformGridPanel_Items->SetMinDesiredSlotWidth(CompactGridSlotSize);
		UniformGridPanel_Items->SetMinDesiredSlotHeight(CompactGridSlotSize);
		UniformGridPanel_Items->SetSlotPadding(FMargin(CompactGridPadding));
	}
	if (UniformGridPanel_ContainerItems)
	{
		UniformGridPanel_ContainerItems->SetMinDesiredSlotWidth(CompactGridSlotSize);
		UniformGridPanel_ContainerItems->SetMinDesiredSlotHeight(CompactGridSlotSize);
		UniformGridPanel_ContainerItems->SetSlotPadding(FMargin(CompactGridPadding));
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
	ApplyCurrencyDisplay();
	UpdateContainerHeader();
	CloseTransientWidgets();
	RebuildExternalContainerGrid();
	ApplyReferencePanelSizing();
}

void UInventoryDuckovWidgetBase::SetCurrencyAmount(const int32 InCurrencyAmount)
{
	CurrencyAmount = FMath::Max(0, InCurrencyAmount);
	EnsureCurrencyHeader();
	ApplyCurrencyDisplay();
}

void UInventoryDuckovWidgetBase::EnsureCurrencyHeader()
{
	if (HorizontalBox_Currency || !HorizontalBox_Header || !WidgetTree)
	{
		return;
	}
	HorizontalBox_Currency = WidgetTree->ConstructWidget<UHorizontalBox>(
		UHorizontalBox::StaticClass(), TEXT("HorizontalBox_Currency"));
	USizeBox* IconBox = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("SizeBox_CurrencyIcon"));
	IconBox->SetWidthOverride(CurrencyIconSize);
	IconBox->SetHeightOverride(CurrencyIconSize);
	Image_CurrencyIcon = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("Image_CurrencyIcon"));
	IconBox->SetContent(Image_CurrencyIcon);
	if (UHorizontalBoxSlot* IconSlot = HorizontalBox_Currency->AddChildToHorizontalBox(IconBox))
	{
		IconSlot->SetVerticalAlignment(VAlign_Center);
		IconSlot->SetPadding(FMargin(0.0f, 0.0f, 6.0f, 0.0f));
	}
	Text_CurrencyAmount = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("Text_CurrencyAmount"));
	if (UHorizontalBoxSlot* AmountSlot = HorizontalBox_Currency->AddChildToHorizontalBox(Text_CurrencyAmount))
	{
		AmountSlot->SetVerticalAlignment(VAlign_Center);
	}
	const int32 InsertIndex = Text_PlayerContainerName
		? FMath::Max(0, HorizontalBox_Header->GetChildIndex(Text_PlayerContainerName) + 1)
		: 0;
	HorizontalBox_Header->InsertChildAt(InsertIndex, HorizontalBox_Currency);
	if (UHorizontalBoxSlot* CurrencySlot = Cast<UHorizontalBoxSlot>(HorizontalBox_Currency->Slot))
	{
		CurrencySlot->SetVerticalAlignment(VAlign_Center);
		CurrencySlot->SetPadding(CurrencyPadding);
	}
}

void UInventoryDuckovWidgetBase::ApplyCurrencyDisplay()
{
	if (HorizontalBox_Currency)
	{
		HorizontalBox_Currency->SetVisibility(bShowCurrencyDisplay ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed);
	}
	if (Image_CurrencyIcon)
	{
		if (UTexture2D* Icon = CurrencyIconTexture.LoadSynchronous())
		{
			Image_CurrencyIcon->SetBrushFromTexture(Icon, true);
			Image_CurrencyIcon->SetColorAndOpacity(FLinearColor::White);
		}
		else
		{
			// Gold placeholder remains visible until final currency art is assigned in the Widget Blueprint.
			Image_CurrencyIcon->SetColorAndOpacity(CurrencyColor);
		}
	}
	if (Text_CurrencyAmount)
	{
		Text_CurrencyAmount->SetText(FText::Format(CurrencyTextFormat, FText::AsNumber(CurrencyAmount)));
		Text_CurrencyAmount->SetColorAndOpacity(FSlateColor(CurrencyColor));
		FSlateFontInfo Font = Text_CurrencyAmount->GetFont();
		if (UFont* LoadedSemiBoldFont = SemiBoldFont.LoadSynchronous()) Font.FontObject = LoadedSemiBoldFont;
		Font.Size = FMath::Max(1, CurrencyFontSize);
		Text_CurrencyAmount->SetFont(Font);
	}
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
	ApplyReferencePanelSizing();
}

void UInventoryDuckovWidgetBase::SetExternalContainer(UInventoryContainerComponent* InContainer)
{
	if (ExternalContainer == InContainer)
	{
		RebuildExternalContainerGrid();
		ApplyReferencePanelSizing();
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
	UpdateContainerHeader();
	RebuildExternalContainerGrid();
	ApplyReferencePanelSizing();
}

void UInventoryDuckovWidgetBase::HandleExternalContainerChanged()
{
	HideTooltip();
	HideContextMenu();
	UpdateContainerHeader();
	RebuildExternalContainerGrid();
	ApplyReferencePanelSizing();
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
		SlotWidget->InitializeSlotForInventory(
			this,
			ExternalContainer,
			SlotIndex,
			SlotData.ItemDefinition,
			SlotData.Quantity,
			SlotData.InstanceId);
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
	Label->SetText(SortButtonText);
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
			FLinearColor(0.012f, 0.036f, 0.068f, 0.92f),
			8.0f,
			FLinearColor(0.34f, 0.56f, 0.68f, 0.92f),
			1.25f));
		Border_PlayerPanel->SetBrushColor(FLinearColor::White);
		Border_PlayerPanel->SetPadding(FMargin(10.0f));
	}
	if (RuntimeExternalContainerBorder)
	{
		RuntimeExternalContainerBorder->SetBrush(FSlateRoundedBoxBrush(
			FLinearColor(0.012f, 0.036f, 0.068f, 0.94f),
			8.0f,
			FLinearColor(0.34f, 0.56f, 0.68f, 0.92f),
			1.25f));
		RuntimeExternalContainerBorder->SetPadding(FMargin(10.0f));
	}
}

void UInventoryDuckovWidgetBase::ApplyDuckovTypography()
{
	UFont* LoadedSemiBoldFont = SemiBoldFont.LoadSynchronous();
	auto ApplyHeaderFont = [LoadedSemiBoldFont](UTextBlock* TextBlock, int32 FontSize)
	{
		if (!TextBlock) return;
		FSlateFontInfo HeaderFont = TextBlock->GetFont();
		if (LoadedSemiBoldFont) HeaderFont.FontObject = LoadedSemiBoldFont;
		HeaderFont.Size = FMath::Max(1, FontSize);
		HeaderFont.OutlineSettings.OutlineSize = 1;
		HeaderFont.OutlineSettings.OutlineColor = FLinearColor(0.005f, 0.018f, 0.032f, 0.96f);
		TextBlock->SetFont(HeaderFont);
		TextBlock->SetColorAndOpacity(FSlateColor(FLinearColor(0.94f, 0.98f, 1.0f, 1.0f)));
		TextBlock->SetShadowOffset(FVector2D(1.0f, 1.0f));
		TextBlock->SetShadowColorAndOpacity(FLinearColor(0.0f, 0.0f, 0.0f, 0.82f));
	};
	ApplyHeaderFont(Text_PlayerContainerName, PlayerHeaderFontSize);
	ApplyHeaderFont(Text_ContainerName, LootHeaderFontSize);

	if (Button_Sort)
	{
		if (UTextBlock* SortLabel = Cast<UTextBlock>(Button_Sort->GetContent()))
		{
			FSlateFontInfo FontInfo = SortLabel->GetFont();
			if (LoadedSemiBoldFont) FontInfo.FontObject = LoadedSemiBoldFont;
			FontInfo.Size = 12;
			SortLabel->SetFont(FontInfo);
			SortLabel->SetColorAndOpacity(FSlateColor(FLinearColor(0.025f, 0.11f, 0.16f, 1.0f)));
		}
	}
}

void UInventoryDuckovWidgetBase::ApplyHeaderLayout()
{
	if (Text_PlayerContainerName)
	{
		Text_PlayerContainerName->SetRenderTranslation(PlayerHeaderPositionOffset);
		if (UHorizontalBoxSlot* HeaderSlot = Cast<UHorizontalBoxSlot>(Text_PlayerContainerName->Slot))
		{
			HeaderSlot->SetPadding(PlayerHeaderPadding);
		}
	}
	if (Text_ContainerName)
	{
		Text_ContainerName->SetRenderTranslation(LootHeaderPositionOffset);
		if (UVerticalBoxSlot* HeaderSlot = Cast<UVerticalBoxSlot>(Text_ContainerName->Slot))
		{
			HeaderSlot->SetPadding(LootHeaderPadding);
		}
	}
}

void UInventoryDuckovWidgetBase::ApplyReferencePanelSizing()
{
	if (!bAutoSizePanelsToContent)
	{
		return;
	}

	const int32 PlayerSlotCount = InventoryComponent ? InventoryComponent->GetMaxInventorySlots() : 20;
	const int32 ContainerSlotCount = ExternalContainer ? ExternalContainer->GetMaxInventorySlots() : 1;
	const int32 SafeColumns = FMath::Max(1, GridColumnCount);
	const float CellStride = FMath::Max(1.0f, CompactGridSlotSize) + FMath::Max(0.0f, CompactGridPadding) * 2.0f;
	const float ResolvedPanelWidth = bFitPanelWidthToGrid
		? SafeColumns * CellStride + FMath::Max(0.0f, CompactPanelHorizontalPadding) * 2.0f
		: CompactPanelWidth;
	FVector2D PlayerSize = FInventoryUIPresentationUtils::CalculateGridPanelSize(
		PlayerSlotCount,
		GridColumnCount,
		CompactGridSlotSize,
		CompactGridPadding,
		ResolvedPanelWidth,
		CompactPanelChromeHeight,
		CompactPanelMinVisibleRows,
		CompactPanelMaxVisibleRows,
		CompactPanelMinHeight,
		CompactPanelMaxHeight);
	FVector2D ContainerSize = FInventoryUIPresentationUtils::CalculateGridPanelSize(
		ContainerSlotCount,
		GridColumnCount,
		CompactGridSlotSize,
		CompactGridPadding,
		ResolvedPanelWidth,
		CompactPanelChromeHeight,
		CompactPanelMinVisibleRows,
		CompactPanelMaxVisibleRows,
		CompactPanelMinHeight,
		CompactPanelMaxHeight);
	auto GetCurrentPanelHeight = [this](UWidget* Panel) -> float
	{
		if (Panel)
		{
			if (const UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(Panel->Slot))
			{
				if (CanvasSlot->GetSize().Y > 0.0f)
				{
					return static_cast<float>(CanvasSlot->GetSize().Y);
				}
			}
		}
		return CompactPanelMaxHeight;
	};
	if (!bAutoSizePlayerPanelHeight)
	{
		PlayerSize.Y = GetCurrentPanelHeight(Panel_PlayerInventory);
	}
	if (!bAutoSizeContainerPanelHeight)
	{
		ContainerSize.Y = GetCurrentPanelHeight(Panel_ExternalContainer);
	}
	if (bMatchPlayerAndContainerPanelHeight)
	{
		const float SharedHeight = FMath::Max(PlayerSize.Y, ContainerSize.Y);
		PlayerSize.Y = SharedHeight;
		ContainerSize.Y = SharedHeight;
	}

	auto SizePanel = [](UWidget* Panel, const FVector2D& DesiredSize, bool bApplyHeightOverride)
	{
		if (!Panel)
		{
			return;
		}
		if (USizeBox* SizeBox = Cast<USizeBox>(Panel))
		{
			SizeBox->SetWidthOverride(DesiredSize.X);
			if (bApplyHeightOverride)
			{
				SizeBox->SetHeightOverride(DesiredSize.Y);
			}
		}
		// A fixed Canvas slot overrides the child's DesiredSize, which was the source
		// of the large empty region in WBP_InventoryDuckov. Keep both layers in sync.
		if (UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(Panel->Slot))
		{
			CanvasSlot->SetAutoSize(false);
			CanvasSlot->SetSize(DesiredSize);
		}
	};

	SizePanel(Panel_PlayerInventory, PlayerSize, bAutoSizePlayerPanelHeight || bMatchPlayerAndContainerPanelHeight);
	SizePanel(Panel_ExternalContainer, ContainerSize, bAutoSizeContainerPanelHeight || bMatchPlayerAndContainerPanelHeight);
	if (PlayerPanelBackgroundBlur)
	{
		SizePanel(PlayerPanelBackgroundBlur, PlayerSize, true);
	}
}

void UInventoryDuckovWidgetBase::ApplySortButtonStyle()
{
	if (Button_Sort)
	{
		FButtonStyle Style = Button_Sort->GetStyle();
		Style.SetNormal(FSlateRoundedBoxBrush(
			FLinearColor(0.70f, 0.88f, 0.94f, 0.98f),
			6.0f,
			FLinearColor(0.18f, 0.72f, 0.90f, 0.96f),
			1.25f));
		Style.SetHovered(FSlateRoundedBoxBrush(
			FLinearColor(0.90f, 1.10f, 1.20f, 1.0f),
			6.0f,
			FLinearColor(0.10f, 1.10f, 1.35f, 1.0f),
			2.5f));
		Style.SetPressed(FSlateRoundedBoxBrush(FLinearColor(0.32f, 0.78f, 0.88f, 1.0f), 6.0f));
		Style.SetDisabled(FSlateRoundedBoxBrush(FLinearColor(0.22f, 0.31f, 0.34f, 0.55f), 6.0f));
		Style.SetNormalPadding(FMargin(10.0f, 4.0f));
		Style.SetPressedPadding(FMargin(10.0f, 5.0f, 10.0f, 3.0f));
		Button_Sort->SetStyle(Style);
		Button_Sort->SetBackgroundColor(FLinearColor::White);
	}
	if (Button_Close)
	{
		FButtonStyle CloseStyle = Button_Close->GetStyle();
		CloseStyle.SetNormal(FSlateRoundedBoxBrush(FLinearColor(0.08f, 0.16f, 0.21f, 0.94f), 5.0f));
		CloseStyle.SetHovered(FSlateRoundedBoxBrush(
			FLinearColor(0.16f, 0.56f, 0.68f, 1.0f),
			5.0f,
			FLinearColor(0.10f, 1.10f, 1.35f, 1.0f),
			2.0f));
		CloseStyle.SetPressed(FSlateRoundedBoxBrush(FLinearColor(0.08f, 0.38f, 0.48f, 1.0f), 5.0f));
		Button_Close->SetStyle(CloseStyle);
		Button_Close->SetBackgroundColor(FLinearColor::White);
	}
}

void UInventoryDuckovWidgetBase::UpdateBackpackHeader()
{
	// Text_PlayerContainerName is authored by the Widget Blueprint and must never be
	// overwritten here. Runtime capacity belongs to the dedicated Text_Capacity field.
	if (Text_Capacity)
	{
		UpdateCapacityText();
		Text_Capacity->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	}
}

void UInventoryDuckovWidgetBase::UpdateContainerHeader()
{
	if (!Text_ContainerName)
	{
		return;
	}
	const FText ContainerName = ExternalContainer && !ExternalContainer->ContainerName.IsEmpty()
		? ExternalContainer->ContainerName
		: DefaultLootContainerText;
	Text_ContainerName->SetText(FText::Format(ContainerHeaderTextFormat, ContainerName));
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
		&& ActiveQuantityDialog
		&& ActiveQuantityDialog->GetVisibility() != ESlateVisibility::Collapsed)
	{
		CloseDropQuantityDialog();
		return FReply::Handled();
	}
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

	UInventoryComponent* SourceInventory = SlotWidget->GetSourceInventory();
	const FGuid& DisplayedInstanceId = SlotWidget->GetDisplayedInstanceId();
	if (!SourceInventory || !DisplayedInstanceId.IsValid())
	{
		HideTooltip();
		return;
	}

	// SlotIndex alone is not stable across transfer/sort rebuilds. A stale MouseEnter can
	// arrive after the same index already contains another stack, so resolve the exact
	// stack this widget rendered inside its original inventory.
	const int32 CurrentSlotIndex = FInventoryUIPresentationUtils::ResolveSlotIndexForPresentation(
		SourceInventory->GetSlotsNative(),
		SlotWidget->GetSlotIndex(),
		DisplayedInstanceId);
	FInventorySlotViewData Data;
	if (CurrentSlotIndex == INDEX_NONE || !MakeSlotViewData(SourceInventory, CurrentSlotIndex, Data) || !EnsureTooltipWidget())
	{
		HideTooltip();
		return;
	}

	HoveredTooltipSlot = SlotWidget;
	ActiveTooltipWidget->SetTooltipData(Data);
	PositionPopup(ActiveTooltipWidget, CanvasPanel_TooltipLayer, ScreenPosition, FVector2D(22.0f, 18.0f));
}

void UInventoryDuckovWidgetBase::HandleSlotUnhovered(UInventoryDuckovSlotWidgetBase* SlotWidget)
{
	if (!ActiveTooltipWidget || !IsValid(SlotWidget))
	{
		return;
	}
	if (HoveredTooltipSlot.Get() == SlotWidget)
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
	UInventoryComponent* SourceInventory = SlotWidget->GetSourceInventory();
	if (!MakeSlotViewData(SourceInventory, SlotWidget->GetSlotIndex(), Data))
	{
		return false;
	}
	const TArray<FInventoryContextAction> Actions = FInventoryUIPresentationUtils::BuildContextActions(Data);
	if (Actions.IsEmpty() || !EnsureContextMenuWidget())
	{
		HideContextMenu();
		return false;
	}

	if (SourceInventory == InventoryComponent)
	{
		SelectSlot(Data.SlotIndex);
	}
	ContextMenuSourceInventory = SourceInventory;
	HideTooltip();
	if (!ContextMenuWidget->SetMenuData(Data, Actions))
	{
		HideContextMenu();
		return false;
	}
	PositionPopup(ContextMenuWidget, CanvasPanel_ContextMenuLayer, ScreenPosition, FVector2D(8.0f, 8.0f));
	return true;
}

void UInventoryDuckovWidgetBase::HandleContextActionRequested(
	EInventoryContextActionId ActionId,
	FGuid InstanceId)
{
	UInventoryComponent* ActionInventory = ContextMenuSourceInventory.Get();
	if (!ActionInventory)
	{
		HideContextMenu();
		return;
	}

	const int32 CurrentSlotIndex = FInventoryUIPresentationUtils::FindSlotIndexByInstanceId(
		ActionInventory->GetSlotsNative(),
		InstanceId);
	if (CurrentSlotIndex == INDEX_NONE)
	{
		HideContextMenu();
		return;
	}
	if (ActionInventory == InventoryComponent && !SelectSlot(CurrentSlotIndex))
	{
		HideContextMenu();
		return;
	}

	HideContextMenu();
	switch (ActionId)
	{
	case EInventoryContextActionId::Use:
		if (ActionInventory == InventoryComponent)
		{
			UseSelectedItem();
		}
		else
		{
			ActionInventory->UseItemAtSlot(CurrentSlotIndex, GetOwningPlayerPawn());
		}
		break;
	case EInventoryContextActionId::Drop:
		{
			FInventorySlot SlotData;
			if (!ActionInventory->GetSlot(CurrentSlotIndex, SlotData))
			{
				break;
			}
			if (SlotData.Quantity > 1)
			{
				OpenDropQuantityDialog(ActionInventory, CurrentSlotIndex);
				break;
			}
			const EInventoryOperationResult DropResult = ActionInventory->DropItemAtSlot(CurrentSlotIndex, 1, GetOwningPlayerPawn());
			if (DropResult != EInventoryOperationResult::Success)
			{
				OnInventoryOperationFailed(DropResult);
			}
		}
		break;
	case EInventoryContextActionId::Inspect:
		if (ActionInventory == InventoryComponent)
		{
			InspectSelectedItem();
		}
		else
		{
			FInventorySlot SlotData;
			if (ActionInventory->GetSlot(CurrentSlotIndex, SlotData) && Coordinator)
			{
				Coordinator->InspectItem(SlotData.ItemDefinition);
			}
		}
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
	if (ActiveQuantityDialog)
	{
		ActiveQuantityDialog->OnConfirmed.RemoveDynamic(this, &UInventoryDuckovWidgetBase::HandleDropQuantityConfirmed);
		ActiveQuantityDialog->OnCancelled.RemoveDynamic(this, &UInventoryDuckovWidgetBase::HandleDropQuantityCancelled);
		ActiveQuantityDialog->RemoveFromParent();
		ActiveQuantityDialog = nullptr;
	}
	HoveredTooltipSlot.Reset();
	ContextMenuSourceInventory.Reset();
	PendingDropInventory.Reset();
	PendingDropInstanceId.Invalidate();
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

bool UInventoryDuckovWidgetBase::OpenDropQuantityDialog(UInventoryComponent* SourceInventory, int32 SlotIndex)
{
	FInventorySlot SlotData;
	if (!SourceInventory || !SourceInventory->GetSlot(SlotIndex, SlotData) || SlotData.Quantity <= 1
		|| !CanvasPanel_ContextMenuLayer || !QuantityDialogWidgetClass)
	{
		return false;
	}

	if (!ActiveQuantityDialog)
	{
		ActiveQuantityDialog = CreateWidget<UInventoryQuantityDialogWidgetBase>(GetOwningPlayer(), QuantityDialogWidgetClass);
		if (!ActiveQuantityDialog)
		{
			return false;
		}
		ActiveQuantityDialog->OnConfirmed.AddUniqueDynamic(this, &UInventoryDuckovWidgetBase::HandleDropQuantityConfirmed);
		ActiveQuantityDialog->OnCancelled.AddUniqueDynamic(this, &UInventoryDuckovWidgetBase::HandleDropQuantityCancelled);
		if (UCanvasPanelSlot* DialogSlot = CanvasPanel_ContextMenuLayer->AddChildToCanvas(ActiveQuantityDialog))
		{
			DialogSlot->SetAnchors(FAnchors(0.5f, 0.5f));
			DialogSlot->SetAlignment(FVector2D(0.5f, 0.5f));
			DialogSlot->SetPosition(FVector2D::ZeroVector);
			DialogSlot->SetAutoSize(true);
			DialogSlot->SetZOrder(120);
		}
	}

	PendingDropInventory = SourceInventory;
	PendingDropInstanceId = SlotData.InstanceId;
	ActiveQuantityDialog->ShowQuantityPicker(SlotData.Quantity, 1);
	return true;
}

void UInventoryDuckovWidgetBase::CloseDropQuantityDialog()
{
	PendingDropInventory.Reset();
	PendingDropInstanceId.Invalidate();
	if (ActiveQuantityDialog)
	{
		ActiveQuantityDialog->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UInventoryDuckovWidgetBase::HandleDropQuantityConfirmed(int32 Quantity)
{
	UInventoryComponent* SourceInventory = PendingDropInventory.Get();
	const FGuid InstanceId = PendingDropInstanceId;
	CloseDropQuantityDialog();
	if (!SourceInventory || !InstanceId.IsValid())
	{
		return;
	}

	const int32 SlotIndex = FInventoryUIPresentationUtils::FindSlotIndexByInstanceId(
		SourceInventory->GetSlotsNative(),
		InstanceId);
	FInventorySlot SlotData;
	if (SlotIndex == INDEX_NONE || !SourceInventory->GetSlot(SlotIndex, SlotData))
	{
		return;
	}

	const int32 DropQuantity = FMath::Clamp(Quantity, 1, SlotData.Quantity);
	const EInventoryOperationResult Result = SourceInventory->DropItemAtSlot(SlotIndex, DropQuantity, GetOwningPlayerPawn());
	if (Result != EInventoryOperationResult::Success)
	{
		OnInventoryOperationFailed(Result);
	}
}

void UInventoryDuckovWidgetBase::HandleDropQuantityCancelled()
{
	CloseDropQuantityDialog();
}

void UInventoryDuckovWidgetBase::HideTooltip()
{
	HoveredTooltipSlot.Reset();
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
	ContextMenuSourceInventory.Reset();
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

bool UInventoryDuckovWidgetBase::MakeSlotViewData(UInventoryComponent* SourceInventory, int32 SlotIndex, FInventorySlotViewData& OutData) const
{
	FInventorySlot InventorySlot;
	if (!SourceInventory || !SourceInventory->GetSlot(SlotIndex, InventorySlot))
	{
		OutData = FInventorySlotViewData();
		return false;
	}
	OutData = FInventoryUIPresentationUtils::MakeSlotViewData(InventorySlot, SlotIndex);
	return OutData.IsValid();
}
