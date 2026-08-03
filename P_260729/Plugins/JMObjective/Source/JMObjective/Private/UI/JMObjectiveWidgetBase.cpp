#include "UI/JMObjectiveWidgetBase.h"

#include "Components/TextBlock.h"
#include "Data/JMObjectiveDefinition.h"

void UJMObjectiveWidgetBase::SetObjectiveState(const FJMObjectiveRuntimeState& InRuntimeState)
{
    RuntimeState = InRuntimeState;
    UpdateNativeTextFields();
    OnObjectiveProgressChanged(RuntimeState);
}

void UJMObjectiveWidgetBase::NativePreConstruct()
{
    Super::NativePreConstruct();
    UpdateNativeTextFields();
}

void UJMObjectiveWidgetBase::UpdateNativeTextFields()
{
    const UJMObjectiveDefinition* Definition = RuntimeState.Definition;
    if (ObjectiveNameText)
    {
        ObjectiveNameText->SetText(Definition ? Definition->DisplayName : FText::GetEmpty());
    }
    if (ObjectiveDescriptionText)
    {
        ObjectiveDescriptionText->SetText(Definition ? Definition->Description : FText::GetEmpty());
    }
    if (ObjectiveProgressText)
    {
        ObjectiveProgressText->SetText(FText::Format(NSLOCTEXT("JMObjective", "ObjectiveProgress", "{0} / {1}"), FText::AsNumber(RuntimeState.CurrentCount), FText::AsNumber(RuntimeState.RequiredCount)));
    }
    if (ObjectiveStateText)
    {
        FText StateText;
        switch (RuntimeState.State)
        {
        case EJMObjectiveState::Active: StateText = NSLOCTEXT("JMObjective", "StateActive", "Active"); break;
        case EJMObjectiveState::Completed: StateText = NSLOCTEXT("JMObjective", "StateCompleted", "Completed"); break;
        case EJMObjectiveState::Failed: StateText = NSLOCTEXT("JMObjective", "StateFailed", "Failed"); break;
        default: StateText = NSLOCTEXT("JMObjective", "StateInactive", "Inactive"); break;
        }
        ObjectiveStateText->SetText(StateText);
    }
}
