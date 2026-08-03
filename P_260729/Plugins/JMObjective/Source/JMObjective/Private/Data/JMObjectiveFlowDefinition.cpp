#include "Data/JMObjectiveFlowDefinition.h"

#include "Data/JMObjectiveDefinition.h"
#if WITH_EDITOR
#include "Misc/DataValidation.h"
#endif

bool UJMObjectiveFlowDefinition::IsFlowDefinitionValid(FText& OutError) const
{
    if (!FlowId.IsValid())
    {
        OutError = NSLOCTEXT("JMObjective", "FlowIdInvalid", "Flow ID must be a valid Gameplay Tag.");
        return false;
    }
    if (ObjectiveDefinitions.IsEmpty())
    {
        OutError = NSLOCTEXT("JMObjective", "FlowObjectivesEmpty", "Objective Definitions must contain at least one Objective.");
        return false;
    }

    TSet<FGameplayTag> SeenIds;
    for (int32 Index = 0; Index < ObjectiveDefinitions.Num(); ++Index)
    {
        const UJMObjectiveDefinition* Definition = ObjectiveDefinitions[Index];
        if (!IsValid(Definition))
        {
            OutError = FText::Format(NSLOCTEXT("JMObjective", "FlowObjectiveNull", "Objective Definitions[{0}] is null."), FText::AsNumber(Index));
            return false;
        }
        if (!Definition->ObjectiveId.IsValid() || !Definition->ListeningEventTag.IsValid() || Definition->RequiredCount < 1)
        {
            OutError = FText::Format(NSLOCTEXT("JMObjective", "FlowObjectiveInvalid", "Objective Definitions[{0}] is invalid."), FText::AsNumber(Index));
            return false;
        }
        if (SeenIds.Contains(Definition->ObjectiveId))
        {
            OutError = FText::Format(NSLOCTEXT("JMObjective", "FlowObjectiveDuplicate", "Objective ID {0} is duplicated."), FText::FromName(Definition->ObjectiveId.GetTagName()));
            return false;
        }
        SeenIds.Add(Definition->ObjectiveId);
    }

    OutError = FText::GetEmpty();
    return true;
}

FPrimaryAssetId UJMObjectiveFlowDefinition::GetPrimaryAssetId() const
{
    return FPrimaryAssetId(TEXT("JMObjectiveFlow"), FlowId.IsValid() ? FlowId.GetTagName() : GetFName());
}

#if WITH_EDITOR
EDataValidationResult UJMObjectiveFlowDefinition::IsDataValid(FDataValidationContext& Context) const
{
    FText Error;
    if (!IsFlowDefinitionValid(Error))
    {
        Context.AddError(Error);
        return EDataValidationResult::Invalid;
    }
    return EDataValidationResult::Valid;
}
#endif

