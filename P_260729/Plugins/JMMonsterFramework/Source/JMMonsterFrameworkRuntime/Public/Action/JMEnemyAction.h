#pragma once

#include "Action/JMEnemyActionTypes.h"
#include "UObject/Object.h"
#include "JMEnemyAction.generated.h"

class AJMEnemyBase;
class UJMEnemyActionComponent;
class UJMEnemyActionDefinition;

/** Per-enemy runtime action instance. Shared DataAssets never hold lifecycle state. */
UCLASS(Blueprintable, Abstract)
class JMMONSTERFRAMEWORKRUNTIME_API UJMEnemyAction : public UObject
{
    GENERATED_BODY()

public:
    virtual UWorld* GetWorld() const override;

    UFUNCTION(BlueprintPure, Category="JM Enemy|Action")
    FGameplayTag GetActionId() const;

    UFUNCTION(BlueprintPure, Category="JM Enemy|Action")
    EJMEnemyActionPhase GetPhase() const { return Phase; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Action")
    bool IsRunning() const { return bRunning; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Action")
    bool IsOnCooldown() const;

    UFUNCTION(BlueprintPure, Category="JM Enemy|Action")
    float GetRemainingCooldown() const;

    UFUNCTION(BlueprintPure, Category="JM Enemy|Action")
    AJMEnemyBase* GetEnemyOwner() const { return EnemyOwner.Get(); }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Action")
    const UJMEnemyActionDefinition* GetDefinition() const { return Definition; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Action")
    FJMEnemyActionContext GetExecutionContext() const { return ExecutionContext; }

protected:
    virtual bool CanExecuteAction(const FJMEnemyActionContext& InContext) const;
    virtual void ActionStarted();
    virtual void ExecuteActive();
    virtual void ActionFinished();
    virtual void ActionCancelled();
    virtual bool WantsUpdate() const;
    virtual void UpdateAction(float DeltaTime);

    UFUNCTION(BlueprintNativeEvent, Category="JM Enemy|Action", meta=(DisplayName="Can Execute Action"))
    bool K2_CanExecute(const FJMEnemyActionContext& InContext) const;
    virtual bool K2_CanExecute_Implementation(const FJMEnemyActionContext& InContext) const;

    UFUNCTION(BlueprintImplementableEvent, Category="JM Enemy|Action", meta=(DisplayName="On Action Started"))
    void K2_OnStarted(const FJMEnemyActionContext& InContext);

    UFUNCTION(BlueprintImplementableEvent, Category="JM Enemy|Action", meta=(DisplayName="On Action Active"))
    void K2_OnActive(const FJMEnemyActionContext& InContext);

    UFUNCTION(BlueprintImplementableEvent, Category="JM Enemy|Action", meta=(DisplayName="On Action Phase Changed"))
    void K2_OnPhaseChanged(EJMEnemyActionPhase PreviousPhase, EJMEnemyActionPhase NewPhase);

    UFUNCTION(BlueprintImplementableEvent, Category="JM Enemy|Action", meta=(DisplayName="On Action Finished"))
    void K2_OnFinished();

    UFUNCTION(BlueprintImplementableEvent, Category="JM Enemy|Action", meta=(DisplayName="On Action Cancelled"))
    void K2_OnCancelled();

    UFUNCTION(BlueprintNativeEvent, Category="JM Enemy|Action", meta=(DisplayName="Wants Action Update"))
    bool K2_WantsUpdate() const;
    virtual bool K2_WantsUpdate_Implementation() const;

    UFUNCTION(BlueprintImplementableEvent, Category="JM Enemy|Action", meta=(DisplayName="Update Action"))
    void K2_Update(float DeltaTime);

private:
    friend class UJMEnemyActionComponent;

    void Initialize(UJMEnemyActionComponent* InComponent, UJMEnemyActionDefinition* InDefinition);
    bool CanExecute(const FJMEnemyActionContext& InContext) const;
    bool Start(const FJMEnemyActionContext& InContext);
    bool Cancel();
    bool NeedsUpdate() const;
    void Update(float DeltaTime);
    void ClearTimer();
    void SetPhase(EJMEnemyActionPhase NewPhase);
    void ScheduleTransition(float Duration, EJMEnemyActionPhase ExpectedPhase, uint32 Generation);
    void AdvancePhase(EJMEnemyActionPhase ExpectedPhase, uint32 Generation);
    void Finish(uint32 Generation);
    double GetCurrentTime() const;

    UPROPERTY(Transient)
    TObjectPtr<UJMEnemyActionComponent> ActionComponent;

    UPROPERTY(Transient)
    TObjectPtr<UJMEnemyActionDefinition> Definition;

    UPROPERTY(Transient)
    TWeakObjectPtr<AJMEnemyBase> EnemyOwner;

    UPROPERTY(Transient)
    FJMEnemyActionContext ExecutionContext;

    EJMEnemyActionPhase Phase = EJMEnemyActionPhase::Idle;
    FTimerHandle PhaseTimer;
    double CooldownEndTime = -1.0;
    uint32 ExecutionGeneration = 0;
    bool bRunning = false;
    bool bWantsRuntimeUpdate = false;
};
