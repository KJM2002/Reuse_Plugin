#include "UI/InventoryDuckovSlotWidgetBase.h"

#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "Engine/Font.h"
#include "Engine/Texture2D.h"
#include "InputCoreTypes.h"
#include "Items/InventoryItemDefinition.h"
#include "Brushes/SlateRoundedBoxBrush.h"
#include "UI/InventoryDuckovWidgetBase.h"
#include "UI/InventorySlotDragDropOperation.h"

void UInventoryDuckovSlotWidgetBase::NativePreConstruct()
{
	Super::NativePreConstruct();
	if (SizeBox_Slot)
	{
		// Allow the glow frame to extend slightly beyond the slot bounds.
		SizeBox_Slot->SetClipping(EWidgetClipping::Inherit);
	}
	if (Button_Select)
	{
		// The full-cell button remains a hit target for click fallback. The parent
		// UUserWidget receives preview input first and starts drag detection.
		Button_Select->SetVisibility(ESlateVisibility::Visible);
	}
	if (Border_NameGradient)
	{
		Border_NameGradient->SetBrush(FSlateRoundedBoxBrush(FLinearColor(0.008f, 0.025f, 0.045f, 0.82f), 5.0f));
		Border_NameGradient->SetBrushColor(FLinearColor::White);
		Border_NameGradient->SetPadding(FMargin(5.0f, 2.0f, 5.0f, 3.0f));
	}
	if (Border_QuantityBadge)
	{
		Border_QuantityBadge->SetBrush(FSlateRoundedBoxBrush(
			FLinearColor(0.005f, 0.018f, 0.025f, 0.82f),
			6.0f,
			FLinearColor(0.08f, 0.82f, 0.76f, 0.88f),
			1.0f));
		Border_QuantityBadge->SetBrushColor(FLinearColor::White);
		Border_QuantityBadge->SetPadding(FMargin(5.0f, 1.0f));
	}
	if (UTexture2D* FrameTexture = SlotFrameTexture.LoadSynchronous())
	{
		if (Border_Hover)
		{
			Border_Hover->SetBrushFromTexture(FrameTexture);
			Border_Hover->SetPadding(FMargin(0.0f));
		}
		if (Image_Selection)
		{
			Image_Selection->SetBrushFromTexture(FrameTexture, false);
		}
	}
	ApplyDuckovTypography();
	ApplyDuckovVisualState();
}

void UInventoryDuckovSlotWidgetBase::ApplyDuckovTypography()
{
	UFont* LoadedRegularFont = RegularFont.LoadSynchronous();
	UFont* LoadedSemiBoldFont = SemiBoldFont.LoadSynchronous();
	if (Text_ItemName)
	{
		FSlateFontInfo NameFont = Text_ItemName->GetFont();
		if (LoadedRegularFont) NameFont.FontObject = LoadedRegularFont;
		NameFont.Size = 9;
		NameFont.OutlineSettings.OutlineSize = 1;
		NameFont.OutlineSettings.OutlineColor = FLinearColor(0.0f, 0.0f, 0.0f, 0.92f);
		Text_ItemName->SetFont(NameFont);
		Text_ItemName->SetShadowOffset(FVector2D(1.0f, 1.0f));
		Text_ItemName->SetShadowColorAndOpacity(FLinearColor(0.0f, 0.0f, 0.0f, 0.82f));
	}
	if (Text_Quantity)
	{
		FSlateFontInfo QuantityFont = Text_Quantity->GetFont();
		if (LoadedSemiBoldFont) QuantityFont.FontObject = LoadedSemiBoldFont;
		QuantityFont.Size = 10;
		QuantityFont.OutlineSettings.OutlineSize = 1;
		QuantityFont.OutlineSettings.OutlineColor = FLinearColor(0.0f, 0.0f, 0.0f, 0.95f);
		Text_Quantity->SetFont(QuantityFont);
		Text_Quantity->SetShadowOffset(FVector2D(1.0f, 1.0f));
		Text_Quantity->SetShadowColorAndOpacity(FLinearColor(0.0f, 0.0f, 0.0f, 0.88f));
	}
}

void UInventoryDuckovSlotWidgetBase::RefreshSlot()
{
	Super::RefreshSlot();
	const bool bHasItem = IsValid(ItemDefinition) && Quantity > 0;
	if (Text_ItemName)
	{
		const FText Name = bHasItem
			? (ItemDefinition->DisplayName.IsEmpty() ? FText::FromName(ItemDefinition->ItemId) : ItemDefinition->DisplayName)
			: FText::GetEmpty();
		Text_ItemName->SetText(Name);
		Text_ItemName->SetVisibility(bHasItem ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed);
	}
	ApplyDuckovVisualState();
}

void UInventoryDuckovSlotWidgetBase::SetSelected(bool bInSelected)
{
	Super::SetSelected(bInSelected);
	ApplyDuckovVisualState();
}

void UInventoryDuckovSlotWidgetBase::ResetHoverState()
{
	bHovered = false;
	bDragHovered = false;
	ApplyDuckovVisualState();
}

void UInventoryDuckovSlotWidgetBase::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);
	if (UInventoryDuckovWidgetBase* DuckovOwner = Cast<UInventoryDuckovWidgetBase>(OwnerInventoryWidget))
	{
		DuckovOwner->HandleSlotHovered(this, InMouseEvent.GetScreenSpacePosition());
	}
	ApplyDuckovVisualState();
}

void UInventoryDuckovSlotWidgetBase::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	if (UInventoryDuckovWidgetBase* DuckovOwner = Cast<UInventoryDuckovWidgetBase>(OwnerInventoryWidget))
	{
		DuckovOwner->HandleSlotUnhovered(this);
	}
	Super::NativeOnMouseLeave(InMouseEvent);
	bHovered = false;
	bDragHovered = false;
	ApplyDuckovVisualState();
}

FReply UInventoryDuckovSlotWidgetBase::NativeOnPreviewMouseButtonDown(
	const FGeometry& InGeometry,
	const FPointerEvent& InMouseEvent)
{
	if (InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton && OwnerInventoryWidget)
	{
		if (InMouseEvent.IsShiftDown())
		{
			if (UInventoryDuckovWidgetBase* DuckovOwner = Cast<UInventoryDuckovWidgetBase>(OwnerInventoryWidget))
			{
				return DuckovOwner->TransferSlotToPairedInventory(SourceInventory, SlotIndex, false)
					? FReply::Handled()
					: FReply::Unhandled();
			}
		}
		const bool bSelectedItem = SourceInventory != OwnerInventoryWidget->GetInventoryComponent()
			? IsValid(ItemDefinition) && Quantity > 0
			: OwnerInventoryWidget->SelectSlot(SlotIndex);
		if (bSelectedItem)
		{
			bPendingQuickTransfer = SourceInventory != OwnerInventoryWidget->GetInventoryComponent();
			OwnerInventoryWidget->NotifySlotSelected();
			// The slot can contain a Button that consumes Mouse Up. Capture the mouse here so
			// a short click is always completed by this widget while DetectDrag still keeps
			// the existing drag-and-drop path available.
			return FReply::Handled()
				.CaptureMouse(TakeWidget())
				.DetectDrag(TakeWidget(), EKeys::LeftMouseButton);
		}
		return FReply::Handled();
	}
	return Super::NativeOnPreviewMouseButtonDown(InGeometry, InMouseEvent);
}

FReply UInventoryDuckovSlotWidgetBase::NativeOnMouseButtonDoubleClick(
	const FGeometry& InGeometry,
	const FPointerEvent& InMouseEvent)
{
	if (InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton && OwnerInventoryWidget)
	{
		if (UInventoryDuckovWidgetBase* DuckovOwner = Cast<UInventoryDuckovWidgetBase>(OwnerInventoryWidget))
		{
			return DuckovOwner->TransferSlotToPairedInventory(SourceInventory, SlotIndex, false)
				? FReply::Handled()
				: FReply::Unhandled();
		}
	}
	return Super::NativeOnMouseButtonDoubleClick(InGeometry, InMouseEvent);
}

FReply UInventoryDuckovSlotWidgetBase::NativeOnMouseButtonDown(
	const FGeometry& InGeometry,
	const FPointerEvent& InMouseEvent)
{
	if (InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton && OwnerInventoryWidget)
	{
		const bool bSelectedItem = SourceInventory != OwnerInventoryWidget->GetInventoryComponent()
			? IsValid(ItemDefinition) && Quantity > 0
			: OwnerInventoryWidget->SelectSlot(SlotIndex);
		if (bSelectedItem)
		{
			bPendingQuickTransfer = SourceInventory != OwnerInventoryWidget->GetInventoryComponent();
			OwnerInventoryWidget->NotifySlotSelected();
			return FReply::Handled()
				.CaptureMouse(TakeWidget())
				.DetectDrag(TakeWidget(), EKeys::LeftMouseButton);
		}
		return FReply::Handled();
	}
	if (InMouseEvent.GetEffectingButton() == EKeys::RightMouseButton)
	{
		if (UInventoryDuckovWidgetBase* DuckovOwner = Cast<UInventoryDuckovWidgetBase>(OwnerInventoryWidget))
		{
			return DuckovOwner->HandleSlotContextRequested(this, InMouseEvent.GetScreenSpacePosition())
				? FReply::Handled()
				: FReply::Unhandled();
		}
	}
	return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
}

FReply UInventoryDuckovSlotWidgetBase::NativeOnMouseButtonUp(
	const FGeometry& InGeometry,
	const FPointerEvent& InMouseEvent)
{
	if (InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		const bool bShouldQuickTransfer = bPendingQuickTransfer;
		bPendingQuickTransfer = false;
		if (bShouldQuickTransfer)
		{
			if (UInventoryDuckovWidgetBase* DuckovOwner = Cast<UInventoryDuckovWidgetBase>(OwnerInventoryWidget))
			{
				DuckovOwner->TransferSlotToPairedInventory(SourceInventory, SlotIndex, false);
			}
		}
		return FReply::Handled().ReleaseMouseCapture();
	}
	bPendingQuickTransfer = false;
	return Super::NativeOnMouseButtonUp(InGeometry, InMouseEvent);
}

void UInventoryDuckovSlotWidgetBase::NativeOnDragDetected(
	const FGeometry& InGeometry,
	const FPointerEvent& InMouseEvent,
	UDragDropOperation*& OutOperation)
{
	Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);
	bPendingQuickTransfer = false;
	if (!OwnerInventoryWidget || !IsValid(ItemDefinition) || Quantity <= 0)
	{
		return;
	}

	UInventorySlotDragDropOperation* Operation = NewObject<UInventorySlotDragDropOperation>(this);
	Operation->SourceInventoryWidget = OwnerInventoryWidget;
	Operation->SourceInventory = SourceInventory;
	Operation->SourceSlotIndex = SlotIndex;
	Operation->Pivot = EDragPivot::MouseDown;
	if (UInventoryDuckovSlotWidgetBase* DragVisual = CreateWidget<UInventoryDuckovSlotWidgetBase>(GetOwningPlayer(), GetClass()))
	{
		DragVisual->InitializeSlot(nullptr, SlotIndex, ItemDefinition, Quantity);
		DragVisual->SetVisibility(ESlateVisibility::HitTestInvisible);
		DragVisual->SetRenderOpacity(0.90f);
		DragVisual->SetRenderScale(FVector2D(0.96f));
		Operation->DefaultDragVisual = DragVisual;
	}
	OutOperation = Operation;

	if (UInventoryDuckovWidgetBase* DuckovOwner = Cast<UInventoryDuckovWidgetBase>(OwnerInventoryWidget))
	{
		DuckovOwner->HandleSlotDragStarted();
	}
	SetRenderOpacity(0.35f);
}

void UInventoryDuckovSlotWidgetBase::NativeOnDragEnter(
	const FGeometry& InGeometry,
	const FDragDropEvent& InDragDropEvent,
	UDragDropOperation* InOperation)
{
	Super::NativeOnDragEnter(InGeometry, InDragDropEvent, InOperation);
	if (const UInventorySlotDragDropOperation* Operation = Cast<UInventorySlotDragDropOperation>(InOperation);
		Operation && OwnerInventoryWidget)
	{
		bHovered = false;
		bDragHovered = true;
		ApplyDuckovVisualState();
	}
}

void UInventoryDuckovSlotWidgetBase::NativeOnDragLeave(
	const FDragDropEvent& InDragDropEvent,
	UDragDropOperation* InOperation)
{
	bHovered = false;
	bDragHovered = false;
	ApplyDuckovVisualState();
	Super::NativeOnDragLeave(InDragDropEvent, InOperation);
}

bool UInventoryDuckovSlotWidgetBase::NativeOnDrop(
	const FGeometry& InGeometry,
	const FDragDropEvent& InDragDropEvent,
	UDragDropOperation* InOperation)
{
	if (UInventorySlotDragDropOperation* Operation = Cast<UInventorySlotDragDropOperation>(InOperation))
	{
		if (OwnerInventoryWidget && SourceInventory)
		{
			if (UInventoryDuckovWidgetBase* DuckovOwner = Cast<UInventoryDuckovWidgetBase>(OwnerInventoryWidget))
			{
				return DuckovOwner->HandleSlotDrop(Operation->SourceInventory, Operation->SourceSlotIndex, SourceInventory, SlotIndex, InDragDropEvent.IsControlDown());
			}
		}
	}
	return Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);
}

void UInventoryDuckovSlotWidgetBase::NativeOnDragCancelled(
	const FDragDropEvent& InDragDropEvent,
	UDragDropOperation* InOperation)
{
	bPendingQuickTransfer = false;
	SetRenderOpacity(1.0f);
	ResetHoverState();
	if (UInventoryDuckovWidgetBase* DuckovOwner = Cast<UInventoryDuckovWidgetBase>(OwnerInventoryWidget))
	{
		DuckovOwner->HandleSlotDragFinished();
	}
	Super::NativeOnDragCancelled(InDragDropEvent, InOperation);
}

void UInventoryDuckovSlotWidgetBase::ApplyDuckovVisualState()
{
	const bool bHasItem = IsValid(ItemDefinition) && Quantity > 0;
	FLinearColor FillColor = bHasItem
		? FLinearColor(0.025f, 0.075f, 0.105f, 0.88f)
		: FLinearColor(0.035f, 0.11f, 0.15f, 0.66f);
	FLinearColor OutlineColor(0.48f, 0.62f, 0.68f, bHasItem ? 0.90f : 0.78f);
	float OutlineWidth = 1.5f;
	if (bHovered || bDragHovered)
	{
		FillColor = FLinearColor(0.035f, 0.15f, 0.17f, 0.92f);
		OutlineColor = FLinearColor(0.08f, 0.82f, 0.76f, 1.0f);
		OutlineWidth = 2.0f;
	}
	if (bSelected && bHasItem)
	{
		FillColor = FLinearColor(0.035f, 0.17f, 0.18f, 0.96f);
		OutlineColor = FLinearColor(0.08f, 0.92f, 0.84f, 1.0f);
		OutlineWidth = 2.5f;
	}
	if (Border_Background)
	{
		Border_Background->SetBrush(FSlateRoundedBoxBrush(FillColor, 5.0f, OutlineColor, OutlineWidth));
		Border_Background->SetBrushColor(FLinearColor::White);
		Border_Background->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	}
	const bool bActiveGlow = bHovered || bDragHovered || (bSelected && bHasItem);
	if (Border_Hover)
	{
		const FLinearColor FrameColor = bActiveGlow
			? FLinearColor(SlotGlowColor.R * 0.62f, SlotGlowColor.G * 0.62f, SlotGlowColor.B * 0.62f, 0.68f)
			: FLinearColor(0.50f, 0.63f, 0.70f, bHasItem ? 0.86f : 0.58f);
		Border_Hover->SetBrushColor(FrameColor);
		Border_Hover->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		Border_Hover->SetRenderTransformPivot(FVector2D(0.5f));
		Border_Hover->SetRenderScale(FVector2D(bActiveGlow ? 1.075f : 1.0f));
		Border_Hover->SetRenderOpacity(bActiveGlow ? 0.78f : 0.90f);
	}
	if (Image_Selection)
	{
		Image_Selection->SetColorAndOpacity(FLinearColor(
			SlotGlowColor.R * 1.35f,
			SlotGlowColor.G * 1.35f,
			SlotGlowColor.B * 1.35f,
			bSelected && bHasItem ? 1.0f : 0.0f));
		Image_Selection->SetRenderTransformPivot(FVector2D(0.5f));
		Image_Selection->SetRenderScale(FVector2D(1.025f));
	}
	SetRenderTransformPivot(FVector2D(0.5f, 0.5f));
	const float SlotScale = (bHovered || bDragHovered) ? 1.025f : (bSelected && bHasItem ? 1.01f : 1.0f);
	SetRenderScale(FVector2D(SlotScale));
}
