#include "Action/JMEnemyAction_Melee.h"

#include "Action/JMEnemyActionDefinition.h"
#include "Core/JMEnemyBase.h"
#include "Kismet/GameplayStatics.h"

namespace
{
    bool IsValidMeleeTarget(const AJMEnemyBase* Enemy, const AActor* Target, const float Range)
    {
        return Enemy && IsValid(Target) && Target != Enemy && !Target->IsActorBeingDestroyed() &&
            Target->CanBeDamaged() && FVector::Dist(Enemy->GetActorLocation(), Target->GetActorLocation()) <= Range;
    }
}

bool UJMEnemyAction_Melee::CanExecuteAction(const FJMEnemyActionContext& InContext) const
{
    const UJMEnemyActionDefinition_Melee* MeleeDefinition =
        Cast<UJMEnemyActionDefinition_Melee>(GetDefinition());
    return MeleeDefinition &&
        IsValidMeleeTarget(GetEnemyOwner(), InContext.TargetActor.Get(), MeleeDefinition->AttackRange);
}

void UJMEnemyAction_Melee::ExecuteActive()
{
    AJMEnemyBase* Enemy = GetEnemyOwner();
    AActor* Target = GetExecutionContext().TargetActor.Get();
    const UJMEnemyActionDefinition_Melee* MeleeDefinition =
        Cast<UJMEnemyActionDefinition_Melee>(GetDefinition());

    bool bDamageApplied = false;
    if (MeleeDefinition && IsValidMeleeTarget(Enemy, Target, MeleeDefinition->AttackRange))
    {
        const float AppliedDamage = UGameplayStatics::ApplyDamage(
            Target, MeleeDefinition->Damage, Enemy ? Enemy->GetController() : nullptr,
            Enemy, MeleeDefinition->DamageType);
        bDamageApplied = AppliedDamage > 0.0f;
    }
    K2_OnMeleeResolved(Target, bDamageApplied);
}
