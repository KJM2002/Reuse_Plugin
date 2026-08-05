#include "UI/InventoryTooltipWidgetBase.h"

#include "Components/Image.h"
#include "Components/Border.h"
#include "Components/TextBlock.h"
#include "Brushes/SlateRoundedBoxBrush.h"
#include "Engine/Texture2D.h"
#include "Items/InventoryItemDefinition.h"

namespace
{
	void SetOptionalText(UTextBlock* TextBlock, const FText& Text)
	{
		if (!TextBlock)
		{
			return;
		}
		TextBlock->SetText(Text);
		TextBlock->SetVisibility(Text.IsEmpty() ? ESlateVisibility::Collapsed : ESlateVisibility::SelfHitTestInvisible);
	}
}

void UInventoryTooltipWidgetBase::NativePreConstruct()
{
	Super::NativePreConstruct();
	if (Border_Tooltip)
	{
		Border_Tooltip->SetBrush(FSlateRoundedBoxBrush(
			FLinearColor(0.018f, 0.05f, 0.085f, 0.96f),
			10.0f,
			FLinearColor(0.24f, 0.53f, 0.60f, 0.92f),
			1.5f));
		Border_Tooltip->SetBrushColor(FLinearColor::White);
		Border_Tooltip->SetPadding(FMargin(14.0f));
	}
	if (Text_TooltipName)
	{
		FSlateFontInfo NameFont = Text_TooltipName->GetFont();
		NameFont.OutlineSettings.OutlineSize = 1;
		NameFont.OutlineSettings.OutlineColor = FLinearColor(0.0f, 0.0f, 0.0f, 0.9f);
		Text_TooltipName->SetFont(NameFont);
		Text_TooltipName->SetShadowOffset(FVector2D(1.0f, 1.0f));
		Text_TooltipName->SetShadowColorAndOpacity(FLinearColor(0.0f, 0.0f, 0.0f, 0.72f));
	}
}

void UInventoryTooltipWidgetBase::SetTooltipData(const FInventorySlotViewData& InData)
{
	TooltipData = InData;
	if (!TooltipData.IsValid())
	{
		ClearTooltipData();
		return;
	}

	SetOptionalText(Text_TooltipName, TooltipData.DisplayName);
	SetOptionalText(Text_TooltipQuantity, FInventoryUIPresentationUtils::FormatQuantityText(TooltipData.Quantity));
	SetOptionalText(Text_TooltipDescription, TooltipData.Description);
	SetOptionalText(Text_TooltipCategory, TooltipData.CategoryText);
	SetOptionalText(Text_TooltipFlavor, TooltipData.FlavorText);
	SetOptionalText(Text_TooltipDisabledReason, TooltipData.CannotUseReason);

	if (Image_TooltipIcon)
	{
		UTexture2D* Icon = TooltipData.ItemDefinition && !TooltipData.ItemDefinition->Icon.IsNull()
			? TooltipData.ItemDefinition->Icon.LoadSynchronous()
			: nullptr;
		Image_TooltipIcon->SetBrushFromTexture(Icon, false);
		Image_TooltipIcon->SetVisibility(Icon ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed);
	}
	SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UInventoryTooltipWidgetBase::ClearTooltipData()
{
	TooltipData = FInventorySlotViewData();
	SetOptionalText(Text_TooltipName, FText::GetEmpty());
	SetOptionalText(Text_TooltipQuantity, FText::GetEmpty());
	SetOptionalText(Text_TooltipDescription, FText::GetEmpty());
	SetOptionalText(Text_TooltipCategory, FText::GetEmpty());
	SetOptionalText(Text_TooltipFlavor, FText::GetEmpty());
	SetOptionalText(Text_TooltipDisabledReason, FText::GetEmpty());
	if (Image_TooltipIcon)
	{
		Image_TooltipIcon->SetBrushFromTexture(nullptr);
		Image_TooltipIcon->SetVisibility(ESlateVisibility::Collapsed);
	}
	SetVisibility(ESlateVisibility::Collapsed);
}

void UInventoryTooltipWidgetBase::NativeDestruct()
{
	ClearTooltipData();
	Super::NativeDestruct();
}
