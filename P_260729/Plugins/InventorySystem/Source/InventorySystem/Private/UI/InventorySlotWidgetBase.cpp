#include "UI/InventorySlotWidgetBase.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/Overlay.h"
#include "Components/OverlaySlot.h"
#include "Components/ScaleBox.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "Engine/Texture2D.h"
#include "Brushes/SlateRoundedBoxBrush.h"
#include "Styling/SlateBrush.h"
#include "Items/InventoryItemDefinition.h"
#include "UI/InventoryWidgetBase.h"

UInventorySlotWidgetBase::UInventorySlotWidgetBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// The former Grid texture was authored for a much larger cell and its 9-slice
	// margins collapse when displayed at the compact 96 px size. The portable
	// default is now a resolution-independent rounded Slate brush.
	SlotBackgroundTexture.Reset();
}

void UInventorySlotWidgetBase::BuildDefaultWidgetTreeIfNeeded()
{
	if (!WidgetTree || WidgetTree->RootWidget)
	{
		return;
	}

	SizeBox_Slot = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("SizeBox_Slot"));
	Button_Select = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("Button_Select"));
	Overlay_Slot = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass(), TEXT("Overlay_Slot"));
	Border_Background = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("Border_Background"));
	SizeBox_Icon = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("SizeBox_Icon"));
	ScaleBox_Icon = WidgetTree->ConstructWidget<UScaleBox>(UScaleBox::StaticClass(), TEXT("ScaleBox_Icon"));
	Image_ItemIcon = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("Image_ItemIcon"));
	Image_Selection = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("Image_Selection"));
	Text_Quantity = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("Text_Quantity"));

	WidgetTree->RootWidget = SizeBox_Slot;
	SizeBox_Slot->AddChild(Button_Select);
	Button_Select->AddChild(Overlay_Slot);
	Overlay_Slot->AddChildToOverlay(Border_Background);
	ScaleBox_Icon->AddChild(Image_ItemIcon);
	SizeBox_Icon->AddChild(ScaleBox_Icon);
	Overlay_Slot->AddChildToOverlay(SizeBox_Icon);
	Overlay_Slot->AddChildToOverlay(Image_Selection);
	Overlay_Slot->AddChildToOverlay(Text_Quantity);

	FButtonStyle ButtonStyle = Button_Select->GetStyle();
	const FSlateBrush TransparentBrush = FSlateColorBrush(FLinearColor::Transparent);
	ButtonStyle.SetNormal(TransparentBrush);
	ButtonStyle.SetHovered(TransparentBrush);
	ButtonStyle.SetPressed(TransparentBrush);
	ButtonStyle.SetDisabled(TransparentBrush);
	Button_Select->SetStyle(ButtonStyle);
	Button_Select->SetClickMethod(EButtonClickMethod::MouseDown);

	Border_Background->SetPadding(FMargin(1.0f));
	Text_Quantity->SetColorAndOpacity(FSlateColor(FLinearColor(0.87f, 0.86f, 0.82f, 0.95f)));
	Text_Quantity->SetFont(FSlateFontInfo(FCoreStyle::GetDefaultFont(), 14));
}

void UInventorySlotWidgetBase::NativePreConstruct()
{
	BuildDefaultWidgetTreeIfNeeded();
	Super::NativePreConstruct();

	// 이전 WBP처럼 Image_ItemIcon이 Overlay에 직접 들어 있으면 안전 영역을 런타임에 만든다.
	if (Overlay_Slot && Image_ItemIcon && Image_ItemIcon->GetParent() == Overlay_Slot && WidgetTree)
	{
		Overlay_Slot->RemoveChild(Image_ItemIcon);

		if (!SizeBox_Icon)
		{
			SizeBox_Icon = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass());
		}
		if (!ScaleBox_Icon)
		{
			ScaleBox_Icon = WidgetTree->ConstructWidget<UScaleBox>(UScaleBox::StaticClass());
		}

		if (SizeBox_Icon && ScaleBox_Icon)
		{
			ScaleBox_Icon->AddChild(Image_ItemIcon);
			SizeBox_Icon->AddChild(ScaleBox_Icon);
			Overlay_Slot->AddChildToOverlay(SizeBox_Icon);
		}
	}
	// Blueprint에 안전 영역이 이미 있어도 Overlay에 다시 연결해 Slot 설정을 정규화한다.
	else if (Overlay_Slot && SizeBox_Icon && SizeBox_Icon->GetParent() == Overlay_Slot)
	{
		Overlay_Slot->RemoveChild(SizeBox_Icon);
		Overlay_Slot->AddChildToOverlay(SizeBox_Icon);
	}

	// 아이콘 안전 영역을 런타임에 만들면 아이콘이 Overlay의 마지막 자식이 된다.
	// 상태 표시와 수량을 순서대로 다시 앞에 올려 선택 여부와 관계없이 동일한 Z Order를 보장한다.
	if (Overlay_Slot)
	{
		auto MoveToOverlayFront = [this](UWidget* Widget) -> UOverlaySlot*
		{
			if (!Widget || Widget->GetParent() != Overlay_Slot)
			{
				return nullptr;
			}

			Overlay_Slot->RemoveChild(Widget);
			return Overlay_Slot->AddChildToOverlay(Widget);
		};

		if (UOverlaySlot* BackgroundSlot = Cast<UOverlaySlot>(Border_Background ? Border_Background->Slot : nullptr))
		{
			BackgroundSlot->SetHorizontalAlignment(HAlign_Fill);
			BackgroundSlot->SetVerticalAlignment(VAlign_Fill);
			BackgroundSlot->SetPadding(FMargin(0.0f));
		}

		if (UOverlaySlot* UnavailableSlot = MoveToOverlayFront(Border_Unavailable))
		{
			UnavailableSlot->SetHorizontalAlignment(HAlign_Fill);
			UnavailableSlot->SetVerticalAlignment(VAlign_Fill);
		}
		if (UOverlaySlot* SelectionSlot = MoveToOverlayFront(Image_Selection))
		{
			SelectionSlot->SetHorizontalAlignment(HAlign_Fill);
			SelectionSlot->SetVerticalAlignment(VAlign_Fill);
		}
		if (UOverlaySlot* QuantitySlot = MoveToOverlayFront(Text_Quantity))
		{
			QuantitySlot->SetHorizontalAlignment(HAlign_Right);
			QuantitySlot->SetVerticalAlignment(VAlign_Bottom);
			QuantitySlot->SetPadding(QuantityPadding);
		}
		if (UOverlaySlot* SelectSlot = MoveToOverlayFront(Button_Select))
		{
			SelectSlot->SetHorizontalAlignment(HAlign_Fill);
			SelectSlot->SetVerticalAlignment(VAlign_Fill);
			SelectSlot->SetPadding(FMargin(0.0f));
		}
	}

	if (Button_Select)
	{
		FButtonStyle ButtonStyle = Button_Select->GetStyle();
		const FSlateBrush TransparentBrush = FSlateColorBrush(FLinearColor::Transparent);
		ButtonStyle.SetNormal(TransparentBrush);
		ButtonStyle.SetHovered(TransparentBrush);
		ButtonStyle.SetPressed(TransparentBrush);
		ButtonStyle.SetDisabled(TransparentBrush);
		Button_Select->SetStyle(ButtonStyle);
		Button_Select->SetClickMethod(EButtonClickMethod::MouseDown);
		Button_Select->SetVisibility(ESlateVisibility::Visible);
	}

	const FString BackgroundTexturePath = SlotBackgroundTexture.ToSoftObjectPath().ToString();
	const bool bUsesLegacyGridTexture =
		BackgroundTexturePath == TEXT("/InventorySystem/Widget/Grid.Grid")
		|| BackgroundTexturePath.StartsWith(TEXT("/InventorySystem/Widget/Grid."));
	if (Border_Background && !SlotBackgroundTexture.IsNull() && !bUsesLegacyGridTexture)
	{
		if (UTexture2D* BackgroundTexture = SlotBackgroundTexture.LoadSynchronous())
		{
			Border_Background->SetBrushFromTexture(BackgroundTexture);
			Border_Background->SetBrushColor(FLinearColor::White);
			Border_Background->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		}
	}
	else if (Border_Background)
	{
		const FSlateRoundedBoxBrush BackgroundBrush(
			FLinearColor::White,
			2.0f,
			FLinearColor(0.16f, 0.17f, 0.17f, 0.55f),
			1.0f);
		Border_Background->SetBrush(BackgroundBrush);
		Border_Background->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	}

	if (Image_Selection)
	{
		const FSlateRoundedBoxBrush SelectionBrush(
			FLinearColor::Transparent,
			2.0f,
			FLinearColor::White,
			1.5f);
		Image_Selection->SetBrush(SelectionBrush);
	}

	const float SafeSlotSize = FMath::Max(1.0f, SlotDisplaySize);
	if (SizeBox_Slot)
	{
		SizeBox_Slot->SetWidthOverride(SafeSlotSize);
		SizeBox_Slot->SetHeightOverride(SafeSlotSize);
		SizeBox_Slot->SetClipping(EWidgetClipping::ClipToBounds);
	}

	const float SafeIconSize = FMath::Max(1.0f, IconDisplaySize);
	if (SizeBox_Icon)
	{
		SizeBox_Icon->SetWidthOverride(SafeIconSize);
		SizeBox_Icon->SetHeightOverride(SafeIconSize);
		SizeBox_Icon->SetClipping(EWidgetClipping::ClipToBounds);
		if (UOverlaySlot* OverlaySlot = Cast<UOverlaySlot>(SizeBox_Icon->Slot))
		{
			OverlaySlot->SetHorizontalAlignment(HAlign_Center);
			OverlaySlot->SetVerticalAlignment(VAlign_Center);
		}
	}

	if (ScaleBox_Icon)
	{
		ScaleBox_Icon->SetStretch(EStretch::ScaleToFit);
		ScaleBox_Icon->SetStretchDirection(EStretchDirection::Both);
		ScaleBox_Icon->SetClipping(EWidgetClipping::ClipToBounds);
	}

	if (Image_ItemIcon)
	{
		Image_ItemIcon->SetRenderTransform(FWidgetTransform());
		Image_ItemIcon->SetRenderTransformPivot(FVector2D(0.5f, 0.5f));
		Image_ItemIcon->SetDesiredSizeOverride(FVector2D(SafeIconSize, SafeIconSize));
		Image_ItemIcon->SetClipping(EWidgetClipping::ClipToBounds);
		if (!SizeBox_Icon)
		{
			if (UOverlaySlot* OverlaySlot = Cast<UOverlaySlot>(Image_ItemIcon->Slot))
			{
				OverlaySlot->SetHorizontalAlignment(HAlign_Center);
				OverlaySlot->SetVerticalAlignment(VAlign_Center);
			}
		}
	}

	if (Text_Quantity)
	{
		Text_Quantity->SetJustification(ETextJustify::Center);
	}
	ApplyVisualState();
}

void UInventorySlotWidgetBase::NativeOnInitialized()
{
	// A native UUserWidget must have its root tree before RebuildWidget creates
	// the Slate hierarchy. Building only in PreConstruct is too late and leaves
	// dynamically-created inventory slots with an empty SObjectWidget.
	BuildDefaultWidgetTreeIfNeeded();
	Super::NativeOnInitialized();
	if (Button_Select)
	{
		Button_Select->OnClicked.AddUniqueDynamic(this, &UInventorySlotWidgetBase::HandleSelectClicked);
	}
}

void UInventorySlotWidgetBase::NativeDestruct()
{
	if (Button_Select)
	{
		Button_Select->OnClicked.RemoveDynamic(this, &UInventorySlotWidgetBase::HandleSelectClicked);
	}
	if (OwnerInventoryWidget)
	{
		OwnerInventoryWidget->UnregisterSlotWidget(this);
	}
	Super::NativeDestruct();
}

void UInventorySlotWidgetBase::InitializeSlot(UInventoryWidgetBase* InOwnerInventoryWidget, int32 InSlotIndex, UInventoryItemDefinition* InItemDefinition, int32 InQuantity)

{
	InitializeSlotForInventory(InOwnerInventoryWidget, InOwnerInventoryWidget ? InOwnerInventoryWidget->GetInventoryComponent() : nullptr, InSlotIndex, InItemDefinition, InQuantity);
}

void UInventorySlotWidgetBase::InitializeSlotForInventory(UInventoryWidgetBase* InOwnerInventoryWidget, UInventoryComponent* InSourceInventory, int32 InSlotIndex, UInventoryItemDefinition* InItemDefinition, int32 InQuantity)
{
	if (OwnerInventoryWidget && OwnerInventoryWidget != InOwnerInventoryWidget)
	{
		OwnerInventoryWidget->UnregisterSlotWidget(this);
	}

	OwnerInventoryWidget = InOwnerInventoryWidget;
	SourceInventory = InSourceInventory;
	SlotIndex = InSlotIndex;
	ItemDefinition = InItemDefinition;
	Quantity = FMath::Max(0, InQuantity);
	if (OwnerInventoryWidget)
	{
		OwnerInventoryWidget->RegisterSlotWidget(this);
	}
	RefreshSlot();
}

void UInventorySlotWidgetBase::RefreshSlot()
{
	const bool bHasValidItem = IsValid(ItemDefinition) && Quantity > 0;
	if (Image_ItemIcon)
	{
		UTexture2D* IconTexture = bHasValidItem && !ItemDefinition->Icon.IsNull()
			? ItemDefinition->Icon.LoadSynchronous()
			: nullptr;
		if (IconTexture)
		{
			Image_ItemIcon->SetBrushFromTexture(IconTexture, false);
			Image_ItemIcon->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		}
		else
		{
			Image_ItemIcon->SetBrushFromTexture(nullptr);
			Image_ItemIcon->SetVisibility(ESlateVisibility::Collapsed);
		}
	}

	if (Text_Quantity)
	{
		Text_Quantity->SetText(FText::Format(
			NSLOCTEXT("InventorySystem", "SlotQuantityFormat", "x{0}"),
			FText::AsNumber(Quantity)));
		Text_Quantity->SetVisibility(bHasValidItem && Quantity > 1
			? ESlateVisibility::SelfHitTestInvisible
			: ESlateVisibility::Collapsed);
	}

	if (Image_Selection)
	{
		Image_Selection->SetVisibility(bHasValidItem && bSelected
			? ESlateVisibility::SelfHitTestInvisible
			: ESlateVisibility::Collapsed);
	}

	if (Border_Unavailable)
	{
		Border_Unavailable->SetVisibility(bHasValidItem && ShouldShowUnavailable()
			? ESlateVisibility::SelfHitTestInvisible
			: ESlateVisibility::Collapsed);
	}

	if (Button_Select)
	{
		// Empty cells remain focusable/clickable so selecting one reliably clears
		// stale detail content.
		Button_Select->SetIsEnabled(true);
	}
	ApplyVisualState();
	OnSlotRefreshed();
}

void UInventorySlotWidgetBase::SetSelected(bool bInSelected)
{
	bSelected = bInSelected;
	if (Image_Selection)
	{
		Image_Selection->SetVisibility(IsValid(ItemDefinition) && Quantity > 0 && bSelected
			? ESlateVisibility::SelfHitTestInvisible
			: ESlateVisibility::Collapsed);
	}
	ApplyVisualState();
	OnSelectionVisualChanged(bSelected);
}

bool UInventorySlotWidgetBase::ShouldShowUnavailable_Implementation() const
{
	return IsValid(ItemDefinition) && !ItemDefinition->bCanUse;
}

void UInventorySlotWidgetBase::FocusSlot()
{
	if (Button_Select)
	{
		Button_Select->SetUserFocus(GetOwningPlayer());
	}
}

void UInventorySlotWidgetBase::HandleSelectClicked()
{
	if (OwnerInventoryWidget)
	{
		OwnerInventoryWidget->SelectSlot(SlotIndex);
		if (IsValid(ItemDefinition) && Quantity > 0)
		{
			OwnerInventoryWidget->NotifySlotSelected();
		}
	}
}

void UInventorySlotWidgetBase::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);
	bHovered = true;
	ApplyVisualState();
	if (OwnerInventoryWidget && IsValid(ItemDefinition) && Quantity > 0)
	{
		OwnerInventoryWidget->NotifySlotHovered();
	}
}

void UInventorySlotWidgetBase::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	bHovered = false;
	ApplyVisualState();
	Super::NativeOnMouseLeave(InMouseEvent);
}

void UInventorySlotWidgetBase::ApplyVisualState()
{
	const bool bHasItem = IsValid(ItemDefinition) && Quantity > 0;
	FLinearColor Background(0.035f, 0.039f, 0.043f, bHasItem ? 0.96f : 0.62f);
	if (bHovered)
	{
		Background = FLinearColor(0.075f, 0.082f, 0.086f, 0.98f);
	}
	if (bSelected && bHasItem)
	{
		Background = FLinearColor(0.105f, 0.105f, 0.092f, 1.0f);
	}
	if (Border_Background)
	{
		Border_Background->SetBrushColor(Background);
	}
	if (Image_Selection)
	{
		// Existing Blueprint selection textures are deliberately subdued.
		Image_Selection->SetColorAndOpacity(FLinearColor(0.68f, 0.61f, 0.42f, bSelected ? 0.72f : 0.0f));
	}
	if (Image_ItemIcon)
	{
		const float Scale = bSelected && bHasItem ? 1.04f : 1.0f;
		Image_ItemIcon->SetRenderScale(FVector2D(Scale));
		Image_ItemIcon->SetColorAndOpacity(bHasItem
			? FLinearColor(0.94f, 0.93f, 0.88f, 1.0f)
			: FLinearColor::Transparent);
	}
}
