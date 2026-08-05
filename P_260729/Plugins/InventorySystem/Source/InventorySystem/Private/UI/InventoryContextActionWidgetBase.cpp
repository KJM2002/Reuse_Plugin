#include "UI/InventoryContextActionWidgetBase.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Brushes/SlateRoundedBoxBrush.h"

void UInventoryContextActionWidgetBase::NativePreConstruct()
{
	Super::NativePreConstruct();
	if (Button_Action)
	{
		FButtonStyle Style = Button_Action->GetStyle();
		Style.SetNormal(FSlateRoundedBoxBrush(FLinearColor(0.045f, 0.09f, 0.12f, 0.94f), 6.0f));
		Style.SetHovered(FSlateRoundedBoxBrush(
			FLinearColor(0.05f, 0.20f, 0.21f, 1.0f),
			6.0f,
			FLinearColor(0.08f, 0.82f, 0.76f, 1.0f),
			1.0f));
		Style.SetPressed(FSlateRoundedBoxBrush(FLinearColor(0.04f, 0.34f, 0.32f, 1.0f), 6.0f));
		Style.SetDisabled(FSlateRoundedBoxBrush(FLinearColor(0.03f, 0.05f, 0.065f, 0.55f), 6.0f));
		Button_Action->SetStyle(Style);
		Button_Action->SetBackgroundColor(FLinearColor::White);
	}
	if (Text_ActionLabel)
	{
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
