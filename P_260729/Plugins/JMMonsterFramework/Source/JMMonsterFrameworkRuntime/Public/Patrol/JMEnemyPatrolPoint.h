#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JMEnemyPatrolPoint.generated.h"

/** A lightweight, level-placed waypoint. Ordering is owned by the enemy Patrol component. */
UCLASS(BlueprintType)
class JMMONSTERFRAMEWORKRUNTIME_API AJMEnemyPatrolPoint : public AActor
{
    GENERATED_BODY()

public:
    AJMEnemyPatrolPoint();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Enemy|Patrol", meta=(ClampMin="0.0"))
    float WaitTime = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Enemy|Patrol", meta=(ClampMin="0.0"))
    float AcceptanceRadius = 75.0f;
};
