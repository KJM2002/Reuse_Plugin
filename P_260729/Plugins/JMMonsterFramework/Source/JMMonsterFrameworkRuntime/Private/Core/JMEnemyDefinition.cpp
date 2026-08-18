#include "Core/JMEnemyDefinition.h"

#include "Action/JMEnemyActionDefinition.h"
#include "Locomotion/JMEnemyMovementSet.h"
#include "Types/JMEnemyTags.h"

#if WITH_EDITOR
#include "Misc/DataValidation.h"
#endif

UJMEnemyDefinition::UJMEnemyDefinition()
    : InitialState(JMEnemyTags::State_Idle)
{
}

#if WITH_EDITOR
EDataValidationResult UJMEnemyDefinition::IsDataValid(FDataValidationContext& Context) const
{
    EDataValidationResult Result = Super::IsDataValid(Context);

    if (EnemyId.IsNone())
    {
        Context.AddWarning(NSLOCTEXT("JMMonsterFramework", "MissingEnemyId", "Enemy Id is not set."));
    }
    if (DisplayName.IsEmpty())
    {
        Context.AddWarning(NSLOCTEXT("JMMonsterFramework", "MissingDisplayName", "Display Name is not set."));
    }
    if (MaxHealth <= 0.0f)
    {
        Context.AddError(NSLOCTEXT("JMMonsterFramework", "InvalidMaxHealth", "Max Health must be greater than zero."));
        Result = EDataValidationResult::Invalid;
    }
    if (BaseDamage < 0.0f)
    {
        Context.AddError(NSLOCTEXT("JMMonsterFramework", "InvalidBaseDamage", "Base Damage cannot be negative."));
        Result = EDataValidationResult::Invalid;
    }
    if (!JMEnemyTags::IsConcreteState(InitialState))
    {
        Context.AddError(NSLOCTEXT("JMMonsterFramework", "InvalidInitialState",
            "Initial State must be a concrete tag below JM.Enemy.State."));
        Result = EDataValidationResult::Invalid;
    }
    if (Perception.Vision.bEnabled &&
        (Perception.Vision.SightRadius <= 0.0f ||
            Perception.Vision.LoseSightRadius < Perception.Vision.SightRadius ||
            Perception.Vision.PeripheralVisionAngle < 0.0f ||
            Perception.Vision.PeripheralVisionAngle > 180.0f))
    {
        Context.AddError(NSLOCTEXT("JMMonsterFramework", "InvalidVisionConfig",
            "Enabled Vision requires a positive Sight Radius, a matching or larger Lose Sight Radius, and a valid angle."));
        Result = EDataValidationResult::Invalid;
    }
    if (Perception.Hearing.bEnabled && Perception.Hearing.HearingRange <= 0.0f)
    {
        Context.AddError(NSLOCTEXT("JMMonsterFramework", "InvalidHearingConfig",
            "Enabled Hearing requires a positive Hearing Range."));
        Result = EDataValidationResult::Invalid;
    }
    if (Perception.PlayerGaze.bEnabled &&
        (Perception.PlayerGaze.UpdateInterval < 0.05f || Perception.PlayerGaze.MaximumDistance <= 0.0f))
    {
        Context.AddError(NSLOCTEXT("JMMonsterFramework", "InvalidGazeConfig",
            "Enabled Player Gaze requires a positive distance and an update interval of at least 0.05 seconds."));
        Result = EDataValidationResult::Invalid;
    }
    if ((MovementSet == nullptr) != DefaultMovementProfile.IsNone())
    {
        Context.AddError(NSLOCTEXT("JMMonsterFramework", "IncompleteDefaultMovement",
            "Movement Set and Default Movement Profile must either both be configured or both be empty."));
        Result = EDataValidationResult::Invalid;
    }
    else if (MovementSet && !MovementSet->FindProfile(DefaultMovementProfile))
    {
        Context.AddError(NSLOCTEXT("JMMonsterFramework", "MissingDefaultMovementProfile",
            "Default Movement Profile was not found in the selected Movement Set."));
        Result = EDataValidationResult::Invalid;
    }

    TSet<FGameplayTag> ActionIds;
    for (const UJMEnemyActionDefinition* ActionDefinition : Actions)
    {
        if (!ActionDefinition)
        {
            Context.AddError(NSLOCTEXT("JMMonsterFramework", "NullActionDefinition",
                "Action list contains a null Action Definition."));
            Result = EDataValidationResult::Invalid;
            continue;
        }
        if (!ActionDefinition->IsRuntimeConfigValid())
        {
            Context.AddError(FText::Format(NSLOCTEXT("JMMonsterFramework", "InvalidEnemyActionDefinition",
                "Action Definition '{0}' has invalid identity, class, timing, or action-specific configuration."),
                FText::FromString(GetNameSafe(ActionDefinition))));
            Result = EDataValidationResult::Invalid;
        }
        if (ActionIds.Contains(ActionDefinition->ActionId))
        {
            Context.AddError(FText::Format(NSLOCTEXT("JMMonsterFramework", "DuplicateEnemyActionId",
                "Action Id '{0}' is duplicated in this Enemy Definition."),
                FText::FromString(ActionDefinition->ActionId.ToString())));
            Result = EDataValidationResult::Invalid;
        }
        ActionIds.Add(ActionDefinition->ActionId);
    }

    return Result == EDataValidationResult::NotValidated ? EDataValidationResult::Valid : Result;
}
#endif
