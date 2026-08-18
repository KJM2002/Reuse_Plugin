#pragma once

#include "Action/JMEnemyAction.h"
#include "JMEnemyAction_Scream.generated.h"

/** Event-only reference action. Audio integration subscribes or extends this hook later. */
UCLASS(Blueprintable)
class JMMONSTERFRAMEWORKRUNTIME_API UJMEnemyAction_Scream : public UJMEnemyAction
{
    GENERATED_BODY()

protected:
    virtual void ExecuteActive() override;

    UFUNCTION(BlueprintImplementableEvent, Category="JM Enemy|Action|Scream", meta=(DisplayName="On Scream Triggered"))
    void K2_OnScreamTriggered();
};
