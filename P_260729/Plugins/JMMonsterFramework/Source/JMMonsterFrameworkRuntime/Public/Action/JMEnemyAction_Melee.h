#pragma once

#include "Action/JMEnemyAction.h"
#include "JMEnemyAction_Melee.generated.h"

/** Standard damage action. It never selects, faces, or moves toward its target. */
UCLASS(Blueprintable)
class JMMONSTERFRAMEWORKRUNTIME_API UJMEnemyAction_Melee : public UJMEnemyAction
{
    GENERATED_BODY()

protected:
    virtual bool CanExecuteAction(const FJMEnemyActionContext& InContext) const override;
    virtual void ExecuteActive() override;

    UFUNCTION(BlueprintImplementableEvent, Category="JM Enemy|Action|Melee", meta=(DisplayName="On Melee Resolved"))
    void K2_OnMeleeResolved(AActor* TargetActor, bool bDamageApplied);
};
