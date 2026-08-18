#pragma once

#include "Action/JMEnemyActionTypes.h"
#include "Components/ActorComponent.h"
#include "JMEnemyActionComponent.generated.h"

class UJMEnemyAction;
class UJMEnemyActionDefinition;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FJMEnemyActionStartedSignature, FGameplayTag, ActionId, UJMEnemyAction*, Action);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(
    FJMEnemyActionPhaseChangedSignature, FGameplayTag, ActionId, UJMEnemyAction*, Action,
    EJMEnemyActionPhase, PreviousPhase, EJMEnemyActionPhase, NewPhase);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FJMEnemyActionFinishedSignature, FGameplayTag, ActionId, UJMEnemyAction*, Action);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FJMEnemyActionCancelledSignature, FGameplayTag, ActionId, UJMEnemyAction*, Action);
DECLARE_MULTICAST_DELEGATE_TwoParams(
    FJMEnemyActionFinishedNativeSignature, FGameplayTag, UJMEnemyAction*);
DECLARE_MULTICAST_DELEGATE_TwoParams(
    FJMEnemyActionCancelledNativeSignature, FGameplayTag, UJMEnemyAction*);
DECLARE_MULTICAST_DELEGATE_TwoParams(
    FJMEnemyActionStartedNativeSignature, FGameplayTag, UJMEnemyAction*);
DECLARE_MULTICAST_DELEGATE_FourParams(
    FJMEnemyActionPhaseChangedNativeSignature, FGameplayTag, UJMEnemyAction*,
    EJMEnemyActionPhase, EJMEnemyActionPhase);

/** Owns runtime action instances and enforces the single-primary-action V1 policy. */
UCLASS(ClassGroup=(JMEnemy), meta=(BlueprintSpawnableComponent))
class JMMONSTERFRAMEWORKRUNTIME_API UJMEnemyActionComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UJMEnemyActionComponent();

    int32 InitializeActions(const TArray<TObjectPtr<UJMEnemyActionDefinition>>& Definitions);

    UFUNCTION(BlueprintPure, Category="JM Enemy|Action")
    bool CanExecuteAction(FGameplayTag ActionId, FJMEnemyActionContext Context) const;

    UFUNCTION(BlueprintCallable, Category="JM Enemy|Action")
    EJMEnemyActionExecuteResult ExecuteAction(FGameplayTag ActionId, FJMEnemyActionContext Context);

    UFUNCTION(BlueprintCallable, Category="JM Enemy|Action")
    bool CancelCurrentAction();

    UFUNCTION(BlueprintPure, Category="JM Enemy|Action")
    UJMEnemyAction* GetAction(FGameplayTag ActionId) const;

    UFUNCTION(BlueprintPure, Category="JM Enemy|Action")
    UJMEnemyAction* GetCurrentAction() const { return CurrentAction; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Action")
    bool IsActionRunning() const;

    UFUNCTION(BlueprintPure, Category="JM Enemy|Action")
    bool IsActionOnCooldown(FGameplayTag ActionId) const;

    UFUNCTION(BlueprintPure, Category="JM Enemy|Action")
    int32 GetActionCount() const { return Actions.Num(); }

    UPROPERTY(BlueprintAssignable, Category="JM Enemy|Action")
    FJMEnemyActionStartedSignature OnActionStarted;

    UPROPERTY(BlueprintAssignable, Category="JM Enemy|Action")
    FJMEnemyActionPhaseChangedSignature OnActionPhaseChanged;

    UPROPERTY(BlueprintAssignable, Category="JM Enemy|Action")
    FJMEnemyActionFinishedSignature OnActionFinished;

    UPROPERTY(BlueprintAssignable, Category="JM Enemy|Action")
    FJMEnemyActionCancelledSignature OnActionCancelled;

    FJMEnemyActionFinishedNativeSignature OnActionFinishedNative;
    FJMEnemyActionCancelledNativeSignature OnActionCancelledNative;
    FJMEnemyActionStartedNativeSignature OnActionStartedNative;
    FJMEnemyActionPhaseChangedNativeSignature OnActionPhaseChangedNative;

protected:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType,
        FActorComponentTickFunction* ThisTickFunction) override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
    friend class UJMEnemyAction;

    void NotifyActionStarted(UJMEnemyAction& Action);
    void NotifyActionPhaseChanged(UJMEnemyAction& Action,
        EJMEnemyActionPhase PreviousPhase, EJMEnemyActionPhase NewPhase);
    void NotifyActionFinished(UJMEnemyAction& Action);
    void NotifyActionCancelled(UJMEnemyAction& Action);

    UPROPERTY(Transient)
    TMap<FGameplayTag, TObjectPtr<UJMEnemyAction>> Actions;

    UPROPERTY(Transient)
    TObjectPtr<UJMEnemyAction> CurrentAction;
};
