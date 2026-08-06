#include "UI/InventoryContextMenuWidgetBase.h"

#include "Components/TextBlock.h"
#include "Components/Border.h"
#include "Components/VerticalBox.h"
#include "Brushes/SlateRoundedBoxBrush.h"
#include "Engine/Font.h"
#include "UI/InventoryContextActionWidgetBase.h"

void UInventoryContextMenuWidgetBase::NativePreConstruct()
{
	Super::NativePreConstruct();
	if (Border_ContextMenu)
	{
		Border_ContextMenu->SetBrush(FSlateRoundedBoxBrush(
			FLinearColor(0.010f, 0.030f, 0.058f, 0.98f),
			7.0f,
			FLinearColor(0.24f, 0.62f, 0.76f, 0.96f),
			1.25f));
		Border_ContextMenu->SetBrushColor(FLinearColor::White);
		Border_ContextMenu->SetPadding(FMargin(8.0f));
	}
	if (Text_ContextMenuTitle)
	{
		FSlateFontInfo FontInfo = Text_ContextMenuTitle->GetFont();
		if (UFont* LoadedFont = SemiBoldFont.LoadSynchronous()) FontInfo.FontObject = LoadedFont;
		FontInfo.Size = 13;
		FontInfo.OutlineSettings.OutlineSize = 1;
		FontInfo.OutlineSettings.OutlineColor = FLinearColor(0.0f, 0.0f, 0.0f, 0.92f);
		Text_ContextMenuTitle->SetFont(FontInfo);
	}
}

bool UInventoryContextMenuWidgetBase::SetMenuData(
	const FInventorySlotViewData& InSlotData,
	const TArray<FInventoryContextAction>& InActions)
{
	ClearActionWidgets();
	TargetInstanceId = InSlotData.InstanceId;
	if (!InSlotData.IsValid() || InActions.IsEmpty() || !VerticalBox_Actions || !ActionWidgetClass)
	{
		ClearMenu();
		return false;
	}

	if (Text_ContextMenuTitle)
	{
		Text_ContextMenuTitle->SetText(InSlotData.DisplayName);
		Text_ContextMenuTitle->SetVisibility(InSlotData.DisplayName.IsEmpty()
			? ESlateVisibility::Collapsed
			: ESlateVisibility::SelfHitTestInvisible);
	}

	for (const FInventoryContextAction& Action : InActions)
	{
		UInventoryContextActionWidgetBase* ActionWidget = CreateWidget<UInventoryContextActionWidgetBase>(GetOwningPlayer(), ActionWidgetClass);
		if (!ActionWidget)
		{
			continue;
		}
		FInventoryContextAction DisplayAction = Action;
		DisplayAction.DisplayText = ResolveActionDisplayText(Action);
		ActionWidget->SetActionData(DisplayAction);
		ActionWidget->OnActionRequested.AddUniqueDynamic(this, &UInventoryContextMenuWidgetBase::HandleActionRequested);
		VerticalBox_Actions->AddChildToVerticalBox(ActionWidget);
		ActionWidgets.Add(ActionWidget);
	}

	const bool bHasActions = !ActionWidgets.IsEmpty();
	SetVisibility(bHasActions ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
	return bHasActions;
}

FText UInventoryContextMenuWidgetBase::ResolveActionDisplayText(const FInventoryContextAction& Action) const
{
	const FText* OverrideText = nullptr;
	switch (Action.ActionId)
	{
	case EInventoryContextActionId::Use:
		OverrideText = &UseActionTextOverride;
		break;
	case EInventoryContextActionId::Drop:
		OverrideText = &DropActionTextOverride;
		break;
	case EInventoryContextActionId::Inspect:
		OverrideText = &InspectActionTextOverride;
		break;
	default:
		break;
	}

	return OverrideText && !OverrideText->IsEmpty() ? *OverrideText : Action.DisplayText;
}

void UInventoryContextMenuWidgetBase::ClearMenu()
{
	ClearActionWidgets();
	TargetInstanceId.Invalidate();
	if (Text_ContextMenuTitle)
	{
		Text_ContextMenuTitle->SetText(FText::GetEmpty());
		Text_ContextMenuTitle->SetVisibility(ESlateVisibility::Collapsed);
	}
	SetVisibility(ESlateVisibility::Collapsed);
}

void UInventoryContextMenuWidgetBase::NativeDestruct()
{
	ClearMenu();
	OnActionRequested.Clear();
	Super::NativeDestruct();
}

void UInventoryContextMenuWidgetBase::HandleActionRequested(EInventoryContextActionId ActionId)
{
	if (TargetInstanceId.IsValid())
	{
		OnActionRequested.Broadcast(ActionId, TargetInstanceId);
	}
}

void UInventoryContextMenuWidgetBase::ClearActionWidgets()
{
	for (UInventoryContextActionWidgetBase* ActionWidget : ActionWidgets)
	{
		if (ActionWidget)
		{
			ActionWidget->OnActionRequested.RemoveDynamic(this, &UInventoryContextMenuWidgetBase::HandleActionRequested);
		}
	}
	ActionWidgets.Reset();
	if (VerticalBox_Actions)
	{
		VerticalBox_Actions->ClearChildren();
	}
}
