#pragma once

#include "Components/ActorComponent.h"
#include "Patrol/JMEnemyPatrolTypes.h"
#include "JMEnemyPatrolComponent.generated.h"

class AJMEnemyPatrolPoint;
class UJMEnemyLocomotionComponent;

/** Supplies patrol destinations only; it never starts, aborts, or owns a movement request. */
UCLASS(ClassGroup=(JMEnemy), meta=(BlueprintSpawnableComponent))
class JMMONSTERFRAMEWORKRUNTIME_API UJMEnemyPatrolComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UJMEnemyPatrolComponent();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Enemy|Patrol")
    EJMEnemyPatrolMode PatrolMode = EJMEnemyPatrolMode::Random;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Enemy|Patrol", meta=(ClampMin="1.0", EditCondition="PatrolMode == EJMEnemyPatrolMode::Random"))
    float RandomRadius = 900.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Enemy|Patrol", meta=(ClampMin="0.0", EditCondition="PatrolMode == EJMEnemyPatrolMode::Random"))
    float MinWaitTime = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Enemy|Patrol", meta=(ClampMin="0.0", EditCondition="PatrolMode == EJMEnemyPatrolMode::Random"))
    float MaxWaitTime = 0.0f;

    UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="JM Enemy|Patrol", meta=(EditCondition="PatrolMode == EJMEnemyPatrolMode::PatrolPoints"))
    TArray<TObjectPtr<AJMEnemyPatrolPoint>> PatrolPoints;

    UFUNCTION(BlueprintPure, Category="JM Enemy|Patrol")
    bool IsPatrolEnabled() const { return PatrolMode != EJMEnemyPatrolMode::Disabled; }

    /** Selects exactly one next leg. Call only when the previous leg has completed or failed. */
    UFUNCTION(BlueprintCallable, Category="JM Enemy|Patrol")
    bool SelectNextDestination(UJMEnemyLocomotionComponent* Locomotion, FJMEnemyPatrolDestination& OutDestination);

    UFUNCTION(BlueprintCallable, Category="JM Enemy|Patrol")
    void ResetPatrol() { NextPatrolPointIndex = 0; }

private:
    int32 NextPatrolPointIndex = 0;
};
