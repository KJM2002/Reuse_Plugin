#include "UI/InventoryWidgetBase.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/ButtonSlot.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/Image.h"
#include "Components/InventoryComponent.h"
#include "Components/InventoryUIComponent.h"
#include "Components/Overlay.h"
#include "Components/OverlaySlot.h"
#include "Components/ScaleBox.h"
#include "Components/ScrollBox.h"
#include "Components/ScrollBoxSlot.h"
#include "Components/SizeBox.h"
#include "Components/Spacer.h"
#include "Components/TextBlock.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Engine/Texture2D.h"
#include "Kismet/GameplayStatics.h"
#include "Input/Events.h"
#include "InputCoreTypes.h"
#include "Items/InventoryItemDefinition.h"
#include "Items/InventoryItemUseEffect.h"
#include "Settings/InventorySystemSettings.h"
#include "Sound/SoundBase.h"
#include "Styling/CoreStyle.h"
#include "UI/InventorySlotWidgetBase.h"

namespace
{
	const FLinearColor InventoryTextPrimary(0.91f, 0.90f, 0.86f, 1.0f);
	const FLinearColor InventoryTextSecondary(0.56f, 0.57f, 0.56f, 1.0f);
	const FLinearColor InventoryAccent(0.60f, 0.54f, 0.38f, 1.0f);

	UTextBlock* MakeText(UWidgetTree* Tree, const FName Name, const FText& Text, int32 Size, const FLinearColor& Color)
	{
		UTextBlock* Result = Tree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), Name);
		Result->SetText(Text);
		Result->SetFont(FSlateFontInfo(FCoreStyle::GetDefaultFont(), Size));
		Result->SetColorAndOpacity(FSlateColor(Color));
		return Result;
	}

	UButton* MakeActionButton(UWidgetTree* Tree, const FName Name, const FText& Label)
	{
		UButton* Button = Tree->ConstructWidget<UButton>(UButton::StaticClass(), Name);
		Button->SetBackgroundColor(FLinearColor(0.10f, 0.105f, 0.105f, 0.96f));
		Button->SetColorAndOpacity(InventoryTextPrimary);
		UTextBlock* LabelText = MakeText(Tree, *FString::Printf(TEXT("%s_Label"), *Name.ToString()), Label, 16, InventoryTextPrimary);
		LabelText->SetJustification(ETextJustify::Center);
		Button->AddChild(LabelText);
		if (UButtonSlot* ButtonSlot = Cast<UButtonSlot>(LabelText->Slot))
		{
			ButtonSlot->SetPadding(FMargin(18.0f, 10.0f));
		}
		return Button;
	}
}

UInventoryWidgetBase::UInventoryWidgetBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SlotWidgetClass = UInventorySlotWidgetBase::StaticClass();
	GridColumnCount = 5;
	bShowEmptySlots = true;
	SetIsFocusable(true);
}

void UInventoryWidgetBase::BuildDefaultWidgetTreeIfNeeded()
{
	if (!WidgetTree || WidgetTree->RootWidget)
	{
		return;
	}

	Overlay_Root = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass(), TEXT("Overlay_Root"));
	Border_BackgroundDim = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("Border_BackgroundDim"));
	USizeBox* WindowSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("SizeBox_InventoryWindow"));
	Border_InventoryWindow = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("Border_InventoryWindow"));
	UVerticalBox* Main = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("VerticalBox_Main"));

	WidgetTree->RootWidget = Overlay_Root;
	Overlay_Root->AddChildToOverlay(Border_BackgroundDim);
	UOverlaySlot* WindowOverlaySlot = Overlay_Root->AddChildToOverlay(WindowSize);
	WindowOverlaySlot->SetHorizontalAlignment(HAlign_Center);
	WindowOverlaySlot->SetVerticalAlignment(VAlign_Center);
	WindowSize->SetWidthOverride(1220.0f);
	WindowSize->SetHeightOverride(760.0f);
	WindowSize->AddChild(Border_InventoryWindow);
	Border_InventoryWindow->AddChild(Main);

	Border_BackgroundDim->SetBrushColor(FLinearColor(0.0f, 0.0f, 0.0f, 0.78f));
	Border_InventoryWindow->SetBrushColor(FLinearColor(0.018f, 0.020f, 0.021f, 0.985f));
	Border_InventoryWindow->SetPadding(FMargin(34.0f, 24.0f, 34.0f, 20.0f));

	UHorizontalBox* Header = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("Header"));
	UVerticalBoxSlot* HeaderSlot = Main->AddChildToVerticalBox(Header);
	HeaderSlot->SetSize(FSlateChildSize(ESlateSizeRule::Automatic));
	HeaderSlot->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 18.0f));
	UTextBlock* Title = MakeText(WidgetTree, TEXT("Text_InventoryTitle"), NSLOCTEXT("InventorySystem", "InventoryTitle", "인벤토리"), 29, InventoryTextPrimary);
	Header->AddChildToHorizontalBox(Title)->SetVerticalAlignment(VAlign_Center);
	USpacer* HeaderSpacer = WidgetTree->ConstructWidget<USpacer>(USpacer::StaticClass());
	Header->AddChildToHorizontalBox(HeaderSpacer)->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
	Text_Capacity = MakeText(WidgetTree, TEXT("Text_Capacity"), FText::GetEmpty(), 15, InventoryTextSecondary);
	UHorizontalBoxSlot* CapacitySlot = Header->AddChildToHorizontalBox(Text_Capacity);
	CapacitySlot->SetVerticalAlignment(VAlign_Center);
	CapacitySlot->SetPadding(FMargin(0.0f, 0.0f, 22.0f, 0.0f));
	Button_Close = MakeActionButton(WidgetTree, TEXT("Button_Close"), NSLOCTEXT("InventorySystem", "CloseGlyph", "×"));
	UHorizontalBoxSlot* CloseSlot = Header->AddChildToHorizontalBox(Button_Close);
	CloseSlot->SetVerticalAlignment(VAlign_Center);

	UHorizontalBox* Content = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("Content"));
	UVerticalBoxSlot* ContentSlot = Main->AddChildToVerticalBox(Content);
	ContentSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));

	UBorder* GridPanel = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("LeftInventoryPanel"));
	GridPanel->SetBrushColor(FLinearColor(0.028f, 0.031f, 0.032f, 0.96f));
	GridPanel->SetPadding(FMargin(18.0f));
	UScrollBox* GridScroll = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("ScrollBox_Items"));
	GridScroll->SetScrollBarVisibility(ESlateVisibility::Collapsed);
	UniformGridPanel_Items = WidgetTree->ConstructWidget<UUniformGridPanel>(UUniformGridPanel::StaticClass(), TEXT("UniformGridPanel_Items"));
	GridScroll->AddChild(UniformGridPanel_Items);
	GridPanel->AddChild(GridScroll);
	UHorizontalBoxSlot* GridPanelSlot = Content->AddChildToHorizontalBox(GridPanel);
	GridPanelSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
	GridPanelSlot->SetPadding(FMargin(0.0f, 0.0f, 28.0f, 0.0f));

	UBorder* DetailPanel = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("ItemDetailPanel"));
	DetailPanel->SetBrushColor(FLinearColor(0.025f, 0.027f, 0.028f, 0.98f));
	DetailPanel->SetPadding(FMargin(24.0f, 18.0f));
	USizeBox* DetailSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass());
	DetailSize->SetWidthOverride(390.0f);
	UVerticalBox* Detail = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("VerticalBox_Detail"));
	DetailSize->AddChild(Detail);
	DetailPanel->AddChild(DetailSize);
	Content->AddChildToHorizontalBox(DetailPanel)->SetSize(FSlateChildSize(ESlateSizeRule::Automatic));

	USizeBox* PreviewSize = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("SizeBox_SelectedIcon"));
	PreviewSize->SetWidthOverride(220.0f);
	PreviewSize->SetHeightOverride(220.0f);
	UScaleBox* PreviewScale = WidgetTree->ConstructWidget<UScaleBox>(UScaleBox::StaticClass(), TEXT("ScaleBox_SelectedIcon"));
	PreviewScale->SetStretch(EStretch::ScaleToFit);
	PreviewScale->SetStretchDirection(EStretchDirection::DownOnly);
	PreviewScale->SetClipping(EWidgetClipping::ClipToBounds);
	Image_SelectedIcon = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("Image_SelectedIcon"));
	PreviewScale->AddChild(Image_SelectedIcon);
	PreviewSize->AddChild(PreviewScale);
	UVerticalBoxSlot* PreviewSlot = Detail->AddChildToVerticalBox(PreviewSize);
	PreviewSlot->SetHorizontalAlignment(HAlign_Center);
	PreviewSlot->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 18.0f));

	Text_SelectedName = MakeText(WidgetTree, TEXT("Text_SelectedName"), FText::GetEmpty(), 26, InventoryTextPrimary);
	Detail->AddChildToVerticalBox(Text_SelectedName)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 3.0f));
	Text_SelectedCategory = MakeText(WidgetTree, TEXT("Text_SelectedCategory"), FText::GetEmpty(), 13, InventoryAccent);
	Detail->AddChildToVerticalBox(Text_SelectedCategory)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 10.0f));
	Text_SelectedQuantity = MakeText(WidgetTree, TEXT("Text_SelectedQuantity"), FText::GetEmpty(), 14, InventoryTextSecondary);
	Detail->AddChildToVerticalBox(Text_SelectedQuantity)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 18.0f));

	UScrollBox* DescriptionScroll = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("ScrollBox_Description"));
	UVerticalBox* DescriptionStack = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass());
	Text_SelectedDescription = MakeText(WidgetTree, TEXT("Text_SelectedDescription"), FText::GetEmpty(), 16, InventoryTextPrimary);
	Text_SelectedDescription->SetAutoWrapText(true);
	Text_SelectedFlavor = MakeText(WidgetTree, TEXT("Text_SelectedFlavor"), FText::GetEmpty(), 14, InventoryTextSecondary);
	Text_SelectedFlavor->SetAutoWrapText(true);
	DescriptionStack->AddChildToVerticalBox(Text_SelectedDescription)->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 16.0f));
	DescriptionStack->AddChildToVerticalBox(Text_SelectedFlavor);
	DescriptionScroll->AddChild(DescriptionStack);
	UVerticalBoxSlot* DescriptionSlot = Detail->AddChildToVerticalBox(DescriptionScroll);
	DescriptionSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));

	Text_EmptyHint = MakeText(WidgetTree, TEXT("Text_EmptyHint"), NSLOCTEXT("InventorySystem", "EmptyDetailHint", "아이템을 선택하면 상세 정보가 표시됩니다."), 14, InventoryTextSecondary);
	Text_EmptyHint->SetAutoWrapText(true);
	Detail->AddChildToVerticalBox(Text_EmptyHint)->SetPadding(FMargin(0.0f, 12.0f));
	Text_DisabledReason = MakeText(WidgetTree, TEXT("Text_DisabledReason"), FText::GetEmpty(), 13, FLinearColor(0.68f, 0.45f, 0.40f, 1.0f));
	Detail->AddChildToVerticalBox(Text_DisabledReason)->SetPadding(FMargin(0.0f, 8.0f));

	HorizontalBox_Actions = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("HorizontalBox_Actions"));
	Button_Use = MakeActionButton(WidgetTree, TEXT("Button_Use"), NSLOCTEXT("InventorySystem", "UseAction", "사용"));
	Button_Inspect = MakeActionButton(WidgetTree, TEXT("Button_Inspect"), NSLOCTEXT("InventorySystem", "InspectAction", "조사"));
	Button_Drop = MakeActionButton(WidgetTree, TEXT("Button_Drop"), NSLOCTEXT("InventorySystem", "DropAction", "버리기"));
	HorizontalBox_Actions->AddChildToHorizontalBox(Button_Use)->SetPadding(FMargin(0.0f, 0.0f, 8.0f, 0.0f));
	HorizontalBox_Actions->AddChildToHorizontalBox(Button_Inspect)->SetPadding(FMargin(0.0f, 0.0f, 8.0f, 0.0f));
	HorizontalBox_Actions->AddChildToHorizontalBox(Button_Drop);
	Detail->AddChildToVerticalBox(HorizontalBox_Actions)->SetPadding(FMargin(0.0f, 18.0f, 0.0f, 0.0f));

	UHorizontalBox* Footer = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("Footer"));
	UVerticalBoxSlot* FooterSlot = Main->AddChildToVerticalBox(Footer);
	FooterSlot->SetPadding(FMargin(0.0f, 18.0f, 0.0f, 0.0f));
	Footer->AddChildToHorizontalBox(MakeText(WidgetTree, TEXT("Text_InputHint"), NSLOCTEXT("InventorySystem", "InputHint", "ENTER 선택"), 13, InventoryTextSecondary));
	Footer->AddChildToHorizontalBox(WidgetTree->ConstructWidget<USpacer>(USpacer::StaticClass()))->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
	Footer->AddChildToHorizontalBox(MakeText(WidgetTree, TEXT("Text_CloseHint"), NSLOCTEXT("InventorySystem", "CloseHint", "ESC 닫기"), 13, InventoryTextSecondary));
}

void UInventoryWidgetBase::NativePreConstruct()
{
	BuildDefaultWidgetTreeIfNeeded();
	Super::NativePreConstruct();

	if (UniformGridPanel_Items)
	{
		// Compact 108 px cells with 12 px inter-cell spacing.
		UniformGridPanel_Items->SetMinDesiredSlotWidth(108.0f);
		UniformGridPanel_Items->SetMinDesiredSlotHeight(108.0f);
		UniformGridPanel_Items->SetSlotPadding(FMargin(6.0f));

		if (UScrollBoxSlot* ScrollSlot = Cast<UScrollBoxSlot>(UniformGridPanel_Items->Slot))
		{
			ScrollSlot->SetHorizontalAlignment(HAlign_Left);
			ScrollSlot->SetVerticalAlignment(VAlign_Top);
			ScrollSlot->SetSize(FSlateChildSize(ESlateSizeRule::Automatic));
			ScrollSlot->SetPadding(FMargin(0.0f));
		}
	}
}

void UInventoryWidgetBase::NativeOnInitialized()
{
	BuildDefaultWidgetTreeIfNeeded();
	Super::NativeOnInitialized();
	if (Button_Use)
	{
		Button_Use->OnClicked.AddUniqueDynamic(this, &UInventoryWidgetBase::HandleUseClicked);
	}
	if (Button_Drop)
	{
		Button_Drop->OnClicked.AddUniqueDynamic(this, &UInventoryWidgetBase::HandleDropClicked);
	}
	if (Button_Inspect)
	{
		Button_Inspect->OnClicked.AddUniqueDynamic(this, &UInventoryWidgetBase::HandleInspectClicked);
	}
	if (Button_Close)
	{
		Button_Close->OnClicked.AddUniqueDynamic(this, &UInventoryWidgetBase::HandleCloseClicked);
	}
}

void UInventoryWidgetBase::InitializeInventory(UInventoryComponent* InInventory, UInventoryUIComponent* InCoordinator)
{
	if (InventoryComponent)
	{
		InventoryComponent->OnInventoryChanged.RemoveDynamic(this, &UInventoryWidgetBase::HandleInventoryChanged);
	}

	InventoryComponent = InInventory;
	Coordinator = InCoordinator;
	PrepareInventoryLayout();
	if (InventoryComponent)
	{
		InventoryComponent->OnInventoryChanged.AddUniqueDynamic(this, &UInventoryWidgetBase::HandleInventoryChanged);
	}
	RefreshInventory();
	BeginOpenTransition();
}

void UInventoryWidgetBase::NativeDestruct()
{
	if (InventoryComponent)
	{
		InventoryComponent->OnInventoryChanged.RemoveDynamic(this, &UInventoryWidgetBase::HandleInventoryChanged);
	}
	if (Button_Use)
	{
		Button_Use->OnClicked.RemoveDynamic(this, &UInventoryWidgetBase::HandleUseClicked);
	}
	if (Button_Drop)
	{
		Button_Drop->OnClicked.RemoveDynamic(this, &UInventoryWidgetBase::HandleDropClicked);
	}
	if (Button_Inspect)
	{
		Button_Inspect->OnClicked.RemoveDynamic(this, &UInventoryWidgetBase::HandleInspectClicked);
	}
	if (Button_Close)
	{
		Button_Close->OnClicked.RemoveDynamic(this, &UInventoryWidgetBase::HandleCloseClicked);
	}
	RegisteredSlotWidgets.Reset();
	bTransitionActive = false;
	Super::NativeDestruct();
}

void UInventoryWidgetBase::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	if (!bTransitionActive)
	{
		return;
	}

	TransitionElapsed += FMath::Max(0.0f, InDeltaTime);
	const float Duration = (bClosing || bInspectTransition) ? CloseTransitionDuration : OpenTransitionDuration;
	const float LinearAlpha = FMath::Clamp(TransitionElapsed / FMath::Max(0.01f, Duration), 0.0f, 1.0f);
	const float EasedAlpha = FMath::InterpEaseOut(TransitionStartAlpha, TransitionTargetAlpha, LinearAlpha, 3.0f);
	ApplyTransitionVisual(EasedAlpha);
	if (LinearAlpha >= 1.0f)
	{
		bTransitionActive = false;
		if (bClosing)
		{
			OnCloseTransitionFinished.Broadcast();
		}
		else if (bInspectTransition)
		{
			bInspectTransition = false;
			OnInspectTransitionFinished.Broadcast();
		}
		if (!bInspectTransition)
		{
			bPreserveBackdropDuringTransition = false;
		}
	}
}

FReply UInventoryWidgetBase::NativeOnPreviewKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	const FKey Key = InKeyEvent.GetKey();
	if (Key == EKeys::Escape || (Coordinator && Coordinator->IsToggleInventoryKey(Key)))
	{
		RequestClose();
		return FReply::Handled();
	}
	return Super::NativeOnPreviewKeyDown(InGeometry, InKeyEvent);
}

FReply UInventoryWidgetBase::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	if (InKeyEvent.GetKey() == EKeys::Escape)
	{
		RequestClose();
		return FReply::Handled();
	}
	return Super::NativeOnKeyDown(InGeometry, InKeyEvent);
}

bool UInventoryWidgetBase::SelectSlot(int32 SlotIndex)
{
	FInventorySlot InventorySlot;
	if (!InventoryComponent || !InventoryComponent->GetSlot(SlotIndex, InventorySlot))
	{
		SelectedSlotIndex = INDEX_NONE;
		SelectedItemInstanceId.Invalidate();
		UpdateRegisteredSlotSelection();
		ClearSelectedItemDetails();
		OnSelectionChanged(SelectedSlotIndex, FInventorySlot());
		return false;
	}

	SelectedSlotIndex = SlotIndex;
	SelectedItemInstanceId = InventorySlot.InstanceId;
	UpdateRegisteredSlotSelection();
	RefreshSelectedItemDetails();
	OnSelectionChanged(SelectedSlotIndex, InventorySlot);
	return true;
}

bool UInventoryWidgetBase::GetSelectedSlot(FInventorySlot& OutSlot) const
{
	return InventoryComponent && InventoryComponent->GetSlot(SelectedSlotIndex, OutSlot);
}

EInventoryOperationResult UInventoryWidgetBase::UseSelectedItem()
{
	const EInventoryOperationResult Result = InventoryComponent
		? InventoryComponent->UseItemAtSlot(SelectedSlotIndex, GetOwningPlayerPawn())
		: EInventoryOperationResult::InvalidSlot;
	if (Result != EInventoryOperationResult::Success)
	{
		OnInventoryOperationFailed(Result);
	}
	return Result;
}

EInventoryOperationResult UInventoryWidgetBase::DropSelectedItem(int32 Quantity)
{
	const EInventoryOperationResult Result = InventoryComponent
		? InventoryComponent->DropItemAtSlot(SelectedSlotIndex, Quantity, GetOwningPlayerPawn())
		: EInventoryOperationResult::InvalidSlot;
	if (Result != EInventoryOperationResult::Success)
	{
		OnInventoryOperationFailed(Result);
	}
	return Result;
}

bool UInventoryWidgetBase::InspectSelectedItem()
{
	FInventorySlot InventorySlot;
	if (!Coordinator || !GetSelectedSlot(InventorySlot))
	{
		return false;
	}
	return Coordinator->InspectItem(InventorySlot.ItemDefinition);
}

void UInventoryWidgetBase::RequestClose()
{
	OnCloseRequested.Broadcast();
}

void UInventoryWidgetBase::RefreshInventory()
{
	const int32 PreviousSelectedSlotIndex = SelectedSlotIndex;
	const FGuid PreviousSelectedItemInstanceId = SelectedItemInstanceId;
	RebuildSlotGrid();

	FInventorySlot SelectedSlot;
	bool bSelectionValid = SelectedSlotIndex != INDEX_NONE
		&& InventoryComponent
		&& InventoryComponent->GetSlot(SelectedSlotIndex, SelectedSlot)
		&& (!SelectedItemInstanceId.IsValid() || SelectedSlot.InstanceId == SelectedItemInstanceId);

	if (!bSelectionValid && InventoryComponent && SelectedItemInstanceId.IsValid())
	{
		const TArray<FInventorySlot>& Slots = InventoryComponent->GetSlotsNative();
		for (int32 Index = 0; Index < Slots.Num(); ++Index)
		{
			if (Slots[Index].IsValid() && Slots[Index].InstanceId == SelectedItemInstanceId)
			{
				SelectedSlotIndex = Index;
				SelectedSlot = Slots[Index];
				bSelectionValid = true;
				break;
			}
		}
	}

	if (!bSelectionValid)
	{
		SelectedSlotIndex = INDEX_NONE;
		SelectedItemInstanceId.Invalidate();
		if (InventoryComponent)
		{
			const TArray<FInventorySlot>& Slots = InventoryComponent->GetSlotsNative();
			for (int32 Index = 0; Index < Slots.Num(); ++Index)
			{
				if (Slots[Index].IsValid())
				{
					SelectedSlotIndex = Index;
					SelectedItemInstanceId = Slots[Index].InstanceId;
					break;
				}
			}
	}
	}

	if (SelectedSlotIndex == INDEX_NONE)
	{
		ClearSelectedItemDetails();
	}
	else
	{
		RefreshSelectedItemDetails();
	}
	UpdateCapacityText();
	UpdateRegisteredSlotSelection();
	if (PreviousSelectedSlotIndex != SelectedSlotIndex || PreviousSelectedItemInstanceId != SelectedItemInstanceId)
	{
		FInventorySlot CurrentSelection;
		GetSelectedSlot(CurrentSelection);
		OnSelectionChanged(SelectedSlotIndex, CurrentSelection);
	}
	OnInventoryRefreshed(InventoryComponent ? InventoryComponent->GetInventorySlots() : TArray<FInventorySlot>());
}

void UInventoryWidgetBase::RegisterSlotWidget(UInventorySlotWidgetBase* SlotWidget)
{
	if (IsValid(SlotWidget))
	{
		RegisteredSlotWidgets.AddUnique(SlotWidget);
		SlotWidget->SetSelected(SlotWidget->GetSlotIndex() == SelectedSlotIndex);
	}
}

void UInventoryWidgetBase::UnregisterSlotWidget(UInventorySlotWidgetBase* SlotWidget)
{
	RegisteredSlotWidgets.RemoveAll([SlotWidget](const TWeakObjectPtr<UInventorySlotWidgetBase>& Entry)
	{
		return !Entry.IsValid() || Entry.Get() == SlotWidget;
	});
}

void UInventoryWidgetBase::HandleInventoryChanged()
{
	RefreshInventory();
}

void UInventoryWidgetBase::HandleUseClicked()
{
	if (UseSelectedItem() == EInventoryOperationResult::Success)
	{
		if (const UInventorySystemSettings* Settings = GetDefault<UInventorySystemSettings>())
		{
			PlayConfiguredSound(Settings->ConfirmSound);
		}
	}
}

void UInventoryWidgetBase::HandleDropClicked()
{
	if (DropSelectedItem(1) == EInventoryOperationResult::Success)
	{
		if (const UInventorySystemSettings* Settings = GetDefault<UInventorySystemSettings>())
		{
			PlayConfiguredSound(Settings->ConfirmSound);
		}
	}
}

void UInventoryWidgetBase::HandleInspectClicked()
{
	if (InspectSelectedItem())
	{
		if (const UInventorySystemSettings* Settings = GetDefault<UInventorySystemSettings>())
		{
			PlayConfiguredSound(Settings->ConfirmSound);
		}
	}
}

void UInventoryWidgetBase::HandleCloseClicked()
{
	RequestClose();
}

void UInventoryWidgetBase::RebuildSlotGrid()
{
	PrepareInventoryLayout();
	RegisteredSlotWidgets.Reset();
	if (!UniformGridPanel_Items)
	{
		return;
	}
	UniformGridPanel_Items->ClearChildren();

	if (!InventoryComponent || !SlotWidgetClass)
	{
		return;
	}

	const int32 ColumnCount = FMath::Max(1, GridColumnCount);
	int32 DisplayIndex = 0;
	const TArray<FInventorySlot>& InventorySlots = InventoryComponent->GetSlotsNative();
	for (int32 SlotIndex = 0; SlotIndex < InventorySlots.Num(); ++SlotIndex)
	{
		const FInventorySlot& InventorySlot = InventorySlots[SlotIndex];
		if (!bShowEmptySlots && !InventorySlot.IsValid())
		{
			continue;
		}

		UInventorySlotWidgetBase* SlotWidget = CreateWidget<UInventorySlotWidgetBase>(GetOwningPlayer(), SlotWidgetClass);
		if (!SlotWidget)
		{
			continue;
		}

		SlotWidget->InitializeSlot(this, SlotIndex, InventorySlot.ItemDefinition, InventorySlot.Quantity);
		if (UUniformGridSlot* GridSlot = UniformGridPanel_Items->AddChildToUniformGrid(SlotWidget, DisplayIndex / ColumnCount, DisplayIndex % ColumnCount))
		{
			// UniformGrid의 남는 폭으로 슬롯 Widget을 늘리지 않는다.
			// 슬롯 크기는 WBP_InventorySlot의 루트 SizeBox가 결정한다.
			GridSlot->SetHorizontalAlignment(HAlign_Left);
			GridSlot->SetVerticalAlignment(VAlign_Top);
		}
		++DisplayIndex;
	}
}

void UInventoryWidgetBase::PrepareInventoryLayout()
{
}

void UInventoryWidgetBase::RefreshSelectedItemDetails()
{
	FInventorySlot InventorySlot;
	if (!GetSelectedSlot(InventorySlot) || !IsValid(InventorySlot.ItemDefinition))
	{
		ClearSelectedItemDetails();
		return;
	}

	UInventoryItemDefinition* ItemDefinition = InventorySlot.ItemDefinition;
	if (Text_SelectedName)
	{
		Text_SelectedName->SetText(ItemDefinition->DisplayName);
	}
	if (Text_SelectedDescription)
	{
		Text_SelectedDescription->SetText(ItemDefinition->Description);
	}
	if (Text_SelectedCategory)
	{
		Text_SelectedCategory->SetText(ItemDefinition->CategoryText);
		Text_SelectedCategory->SetVisibility(ItemDefinition->CategoryText.IsEmpty()
			? ESlateVisibility::Collapsed
			: ESlateVisibility::SelfHitTestInvisible);
	}
	if (Text_SelectedFlavor)
	{
		Text_SelectedFlavor->SetText(ItemDefinition->FlavorText);
		Text_SelectedFlavor->SetVisibility(ItemDefinition->FlavorText.IsEmpty()
			? ESlateVisibility::Collapsed
			: ESlateVisibility::SelfHitTestInvisible);
	}
	if (Text_SelectedQuantity)
	{
		Text_SelectedQuantity->SetText(FText::Format(NSLOCTEXT("InventorySystem", "SelectedQuantity", "수량: {0}"), FText::AsNumber(InventorySlot.Quantity)));
	}
	if (Image_SelectedIcon)
	{
		UTexture2D* IconTexture = ItemDefinition->Icon.IsNull() ? nullptr : ItemDefinition->Icon.LoadSynchronous();
		// Match the source dimensions so the surrounding ScaleBox can preserve
		// aspect ratio and avoid enlarging a low-resolution icon.
		Image_SelectedIcon->SetBrushFromTexture(IconTexture, true);
		Image_SelectedIcon->SetVisibility(IconTexture ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed);
	}

    const bool bCanUse = ItemDefinition->bCanUse;
	const bool bCanDrop = ItemDefinition->bCanDrop;
	const bool bCanInspect = ItemDefinition->bCanInspect && !ItemDefinition->InspectMesh.IsNull();
	if (Button_Use)
	{
		Button_Use->SetIsEnabled(bCanUse);
		Button_Use->SetVisibility(bCanUse ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	}
	if (Button_Drop)
	{
		Button_Drop->SetIsEnabled(bCanDrop);
		Button_Drop->SetVisibility(bCanDrop ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	}
	if (Button_Inspect)
	{
		Button_Inspect->SetIsEnabled(bCanInspect);
		Button_Inspect->SetVisibility(bCanInspect ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	}
	if (HorizontalBox_Actions)
	{
		HorizontalBox_Actions->SetVisibility(bCanUse || bCanDrop || bCanInspect
			? ESlateVisibility::Visible
			: ESlateVisibility::Collapsed);
	}
	if (Text_EmptyHint)
	{
		Text_EmptyHint->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (Text_DisabledReason)
	{
		const bool bShowReason = !bCanUse && !ItemDefinition->CannotUseReason.IsEmpty();
		Text_DisabledReason->SetText(bShowReason ? ItemDefinition->CannotUseReason : FText::GetEmpty());
		Text_DisabledReason->SetVisibility(bShowReason ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed);
	}
}

void UInventoryWidgetBase::ClearSelectedItemDetails()
{
	if (Image_SelectedIcon)
	{
		Image_SelectedIcon->SetBrushFromTexture(nullptr);
		Image_SelectedIcon->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (Text_SelectedName)
	{
		Text_SelectedName->SetText(FText::GetEmpty());
	}
	if (Text_SelectedQuantity)
	{
		Text_SelectedQuantity->SetText(FText::GetEmpty());
	}
	if (Text_SelectedDescription)
	{
		Text_SelectedDescription->SetText(FText::GetEmpty());
	}
	if (Text_SelectedCategory)
	{
		Text_SelectedCategory->SetText(FText::GetEmpty());
		Text_SelectedCategory->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (Text_SelectedFlavor)
	{
		Text_SelectedFlavor->SetText(FText::GetEmpty());
		Text_SelectedFlavor->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (Text_EmptyHint)
	{
		const bool bInventoryEmpty = !InventoryComponent || InventoryComponent->GetOccupiedSlotCount() == 0;
		Text_EmptyHint->SetText(bInventoryEmpty
			? NSLOCTEXT("InventorySystem", "InventoryEmptyHint", "보관 중인 아이템이 없습니다.")
			: NSLOCTEXT("InventorySystem", "EmptyDetailHint", "아이템을 선택하면 상세 정보가 표시됩니다."));
		Text_EmptyHint->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	}
	if (Text_DisabledReason)
	{
		Text_DisabledReason->SetText(FText::GetEmpty());
		Text_DisabledReason->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (Button_Use)
	{
		Button_Use->SetIsEnabled(false);
		Button_Use->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (Button_Drop)
	{
		Button_Drop->SetIsEnabled(false);
		Button_Drop->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (Button_Inspect)
	{
		Button_Inspect->SetIsEnabled(false);
		Button_Inspect->SetVisibility(ESlateVisibility::Collapsed);
	}
	if (HorizontalBox_Actions)
	{
		HorizontalBox_Actions->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UInventoryWidgetBase::BeginOpenTransition()
{
	const bool bWasClosing = bClosing;
	bClosing = false;
	bInspectTransition = false;
	bPreserveBackdropDuringTransition = false;
	bTransitionActive = true;
	TransitionElapsed = 0.0f;
	TransitionStartAlpha = bWasClosing ? GetRenderOpacity() : 0.0f;
	if (TransitionStartAlpha <= KINDA_SMALL_NUMBER)
	{
		TransitionStartAlpha = 0.0f;
	}
	TransitionTargetAlpha = 1.0f;
	ApplyTransitionVisual(TransitionStartAlpha);
}

void UInventoryWidgetBase::BeginCloseTransition()
{
	if (bClosing && bTransitionActive)
	{
		return;
	}
	bClosing = true;
	bInspectTransition = false;
	bPreserveBackdropDuringTransition = false;
	bTransitionActive = true;
	TransitionElapsed = 0.0f;
	TransitionStartAlpha = FMath::Clamp(GetRenderOpacity(), 0.0f, 1.0f);
	TransitionTargetAlpha = 0.0f;
}

void UInventoryWidgetBase::BeginInspectTransition()
{
	if (bInspectTransition && bTransitionActive)
	{
		return;
	}
	bClosing = false;
	bInspectTransition = true;
	bPreserveBackdropDuringTransition = true;
	bTransitionActive = true;
	TransitionElapsed = 0.0f;
	TransitionStartAlpha = FMath::Clamp(GetRenderOpacity(), 0.0f, 1.0f);
	TransitionTargetAlpha = 0.0f;
}

void UInventoryWidgetBase::BeginInspectorReturnTransition()
{
	bClosing = false;
	bInspectTransition = false;
	bPreserveBackdropDuringTransition = true;
	bTransitionActive = true;
	TransitionElapsed = 0.0f;
	TransitionStartAlpha = 0.0f;
	TransitionTargetAlpha = 1.0f;
	ApplyTransitionVisual(0.0f);
}

void UInventoryWidgetBase::FocusSelectedSlot()
{
	for (const TWeakObjectPtr<UInventorySlotWidgetBase>& Entry : RegisteredSlotWidgets)
	{
		if (UInventorySlotWidgetBase* SlotWidget = Entry.Get();
			SlotWidget && SlotWidget->GetSlotIndex() == SelectedSlotIndex)
		{
			SlotWidget->FocusSlot();
			return;
		}
	}
	SetKeyboardFocus();
}

void UInventoryWidgetBase::ApplyTransitionVisual(float Alpha)
{
	const float SafeAlpha = FMath::Clamp(Alpha, 0.0f, 1.0f);
	if (bPreserveBackdropDuringTransition && Border_InventoryWindow)
	{
		SetRenderOpacity(1.0f);
		SetRenderScale(FVector2D::UnitVector);
		SetRenderTranslation(FVector2D::ZeroVector);
		Border_InventoryWindow->SetRenderOpacity(SafeAlpha);
		Border_InventoryWindow->SetRenderScale(FVector2D(FMath::Lerp(0.975f, 1.0f, SafeAlpha)));
		Border_InventoryWindow->SetRenderTranslation(FVector2D(0.0f, FMath::Lerp(12.0f, 0.0f, SafeAlpha)));
		if (Border_BackgroundDim)
		{
			Border_BackgroundDim->SetRenderOpacity(1.0f);
		}
		return;
	}

	SetRenderOpacity(SafeAlpha);
	SetRenderScale(FVector2D(FMath::Lerp(0.975f, 1.0f, SafeAlpha)));
	SetRenderTranslation(FVector2D(0.0f, FMath::Lerp(12.0f, 0.0f, SafeAlpha)));
	if (Border_BackgroundDim)
	{
		Border_BackgroundDim->SetRenderOpacity(SafeAlpha);
	}
}

void UInventoryWidgetBase::UpdateCapacityText()
{
	if (!Text_Capacity)
	{
		return;
	}
	const int32 Occupied = InventoryComponent ? InventoryComponent->GetOccupiedSlotCount() : 0;
	const int32 Capacity = InventoryComponent ? InventoryComponent->GetMaxInventorySlots() : 0;
	Text_Capacity->SetText(FText::Format(
		NSLOCTEXT("InventorySystem", "CapacityFormat", "{0} / {1}"),
		FText::AsNumber(Occupied),
		FText::AsNumber(Capacity)));
}

void UInventoryWidgetBase::NotifySlotHovered()
{
	const UInventorySystemSettings* Settings = GetDefault<UInventorySystemSettings>();
	if (Settings)
	{
		PlayConfiguredSound(Settings->SlotHoverSound);
	}
}

void UInventoryWidgetBase::NotifySlotSelected()
{
	const UInventorySystemSettings* Settings = GetDefault<UInventorySystemSettings>();
	if (Settings)
	{
		PlayConfiguredSound(Settings->SlotSelectSound);
	}
}

void UInventoryWidgetBase::PlayConfiguredSound(const TSoftObjectPtr<USoundBase>& Sound) const
{
	if (!Sound.IsNull())
	{
		if (USoundBase* LoadedSound = Sound.LoadSynchronous())
		{
			UGameplayStatics::PlaySound2D(this, LoadedSound);
		}
	}
}

void UInventoryWidgetBase::UpdateRegisteredSlotSelection()
{
	RegisteredSlotWidgets.RemoveAll([](const TWeakObjectPtr<UInventorySlotWidgetBase>& Entry)
	{
		return !Entry.IsValid();
	});
	for (const TWeakObjectPtr<UInventorySlotWidgetBase>& Entry : RegisteredSlotWidgets)
	{
		if (UInventorySlotWidgetBase* SlotWidget = Entry.Get())
		{
			SlotWidget->SetSelected(SlotWidget->GetSlotIndex() == SelectedSlotIndex);
		}
	}
}
