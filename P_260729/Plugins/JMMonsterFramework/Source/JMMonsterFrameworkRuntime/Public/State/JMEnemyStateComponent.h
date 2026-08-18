#pragma once

#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "JMEnemyStateComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FJMEnemyStateChangedSignature,
    FGameplayTag, PreviousState, FGameplayTag, NewState);

/** Owns the enemy's single current state and publishes meaningful transitions. */
UCLASS(ClassGroup=(JMEnemy), meta=(BlueprintSpawnableComponent))
class JMMONSTERFRAMEWORKRUNTIME_API UJMEnemyStateComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UJMEnemyStateComponent();

    /** Returns true only when a concrete, different enemy state was applied. */
    UFUNCTION(BlueprintCallable, Category="JM Enemy|State")
    bool SetState(FGameplayTag NewState);

    UFUNCTION(BlueprintPure, Category="JM Enemy|State")
    FGameplayTag GetCurrentState() const { return CurrentState; }

    /** Supports parent queries such as JM.Enemy.State as well as exact leaf queries. */
    UFUNCTION(BlueprintPure, Category="JM Enemy|State")
    bool IsInState(FGameplayTag State) const;

    UPROPERTY(BlueprintAssignable, Category="JM Enemy|State")
    FJMEnemyStateChangedSignature OnStateChanged;

private:
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="JM Enemy|State", meta=(AllowPrivateAccess="true"))
    FGameplayTag CurrentState;
};
