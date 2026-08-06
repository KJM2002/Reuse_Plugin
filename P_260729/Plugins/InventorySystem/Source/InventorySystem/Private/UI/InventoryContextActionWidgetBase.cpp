#include "UI/InventoryContextActionWidgetBase.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Brushes/SlateRoundedBoxBrush.h"
#include "Engine/Font.h"

void UInventoryContextActionWidgetBase::NativePreConstruct()
{
	Super::NativePreConstruct();
	if (Button_Action)
	{
		FButtonStyle Style = Button_Action->GetStyle();
		Style.SetNormal(FSlateRoundedBoxBrush(
			FLinearColor(0.025f, 0.065f, 0.10f, 0.96f),
			5.0f,
			FLinearColor(0.22f, 0.48f, 0.60f, 0.88f),
			1.0f));
		Style.SetHovered(FSlateRoundedBoxBrush(
			FLinearColor(0.025f, 0.24f, 0.32f, 1.0f),
			5.0f,
			FLinearColor(0.10f, 1.10f, 1.35f, 1.0f),
			2.5f));
		Style.SetPressed(FSlateRoundedBoxBrush(FLinearColor(0.03f, 0.42f, 0.48f, 1.0f), 5.0f));
		Style.SetDisabled(FSlateRoundedBoxBrush(FLinearColor(0.03f, 0.05f, 0.065f, 0.55f), 5.0f));
		Button_Action->SetStyle(Style);
		Button_Action->SetBackgroundColor(FLinearColor::White);
	}
	if (Text_ActionLabel)
	{
		FSlateFontInfo FontInfo = Text_ActionLabel->GetFont();
		if (UFont* LoadedFont = SemiBoldFont.LoadSynchronous()) FontInfo.FontObject = LoadedFont;
		FontInfo.Size = 12;
		FontInfo.OutlineSettings.OutlineSize = 1;
		FontInfo.OutlineSettings.OutlineColor = FLinearColor(0.0f, 0.0f, 0.0f, 0.90f);
		Text_ActionLabel->SetFont(FontInfo);
		Text_ActionLabel->SetColorAndOpacity(FSlateColor(FLinearColor(0.92f, 0.98f, 1.0f, 1.0f)));
		Text_ActionLabel->SetShadowOffset(FVector2D(1.0f, 1.0f));
		Text_ActionLabel->SetShadowColorAndOpacity(FLinearColor(0.0f, 0.0f, 0.0f, 0.72f));
	}
}

void UInventoryContextActionWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();
	if (Button_Action)
	{
		Button_Action->OnClicked.AddUniqueDynamic(this, &UInventoryContextActionWidgetBase::HandleActionClicked);
	}
}

void UInventoryContextActionWidgetBase::NativeDestruct()
{
	if (Button_Action)
	{
		Button_Action->OnClicked.RemoveDynamic(this, &UInventoryContextActionWidgetBase::HandleActionClicked);
	}
	OnActionRequested.Clear();
	Super::NativeDestruct();
}

void UInventoryContextActionWidgetBase::SetActionData(const FInventoryContextAction& InAction)
{
	ActionData = InAction;
	if (Text_ActionLabel)
	{
		Text_ActionLabel->SetText(ActionData.DisplayText);
	}
	if (Button_Action)
	{
		Button_Action->SetIsEnabled(ActionData.bEnabled);
	}
	if (Text_DisabledReason)
	{
		Text_DisabledReason->SetText(ActionData.DisabledReason);
		Text_DisabledReason->SetVisibility(!ActionData.bEnabled && !ActionData.DisabledReason.IsEmpty()
			? ESlateVisibility::SelfHitTestInvisible
			: ESlateVisibility::Collapsed);
	}
}

void UInventoryContextActionWidgetBase::HandleActionClicked()
{
	if (ActionData.bEnabled)
	{
		OnActionRequested.Broadcast(ActionData.ActionId);
	}
}
