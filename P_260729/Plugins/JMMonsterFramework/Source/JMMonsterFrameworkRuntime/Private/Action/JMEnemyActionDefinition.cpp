#include "Action/JMEnemyActionDefinition.h"

#include "Action/JMEnemyAction.h"
#include "Action/JMEnemyAction_Melee.h"
#include "Action/JMEnemyAction_Scream.h"
#include "Types/JMEnemyTags.h"

#if WITH_EDITOR
#include "Misc/DataValidation.h"
#endif

bool UJMEnemyActionDefinition::IsRuntimeConfigValid() const
{
    return JMEnemyTags::IsConcreteAction(ActionId) && ActionClass &&
        WindupDuration >= 0.0f && ActiveDuration >= 0.0f && RecoveryDuration >= 0.0f && Cooldown >= 0.0f;
}

#if WITH_EDITOR
EDataValidationResult UJMEnemyActionDefinition::IsDataValid(FDataValidationContext& Context) const
{
    EDataValidationResult Result = Super::IsDataValid(Context);
    if (!IsRuntimeConfigValid())
    {
        Context.AddError(NSLOCTEXT("JMMonsterFramework", "InvalidActionDefinition",
            "Action Definition requires a concrete JM.Enemy.Action tag, an Action Class, and non-negative timing values."));
        Result = EDataValidationResult::Invalid;
    }
    return Result == EDataValidationResult::NotValidated ? EDataValidationResult::Valid : Result;
}
#endif

UJMEnemyActionDefinition_Melee::UJMEnemyActionDefinition_Melee()
{
    ActionId = JMEnemyTags::Action_Melee;
    ActionClass = UJMEnemyAction_Melee::StaticClass();
    WindupDuration = 0.35f;
    ActiveDuration = 0.1f;
    RecoveryDuration = 0.4f;
    Cooldown = 1.0f;
}

bool UJMEnemyActionDefinition_Melee::IsRuntimeConfigValid() const
{
    return Super::IsRuntimeConfigValid() && Damage >= 0.0f && AttackRange > 0.0f;
}

UJMEnemyActionDefinition_Scream::UJMEnemyActionDefinition_Scream()
{
    ActionId = JMEnemyTags::Action_Scream;
    ActionClass = UJMEnemyAction_Scream::StaticClass();
    WindupDuration = 0.2f;
    ActiveDuration = 0.75f;
    RecoveryDuration = 0.25f;
    Cooldown = 3.0f;
}
