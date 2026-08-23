#pragma once

#include "CoreMinimal.h"
#include "JMEnemyPatrolTypes.generated.h"

/** Selects how an enemy supplies destinations while it is in a Patrol StateTree state. */
UENUM(BlueprintType)
enum class EJMEnemyPatrolMode : uint8
{
    Random UMETA(DisplayName="Random around home"),
    PatrolPoints UMETA(DisplayName="Ordered patrol points"),
    Disabled UMETA(DisplayName="Disabled (idle)")
};

/** A destination selected by Patrol. Movement ownership remains with Locomotion/StateTree. */
USTRUCT(BlueprintType)
struct JMMONSTERFRAMEWORKRUNTIME_API FJMEnemyPatrolDestination
{
    GENERATED_BODY()

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Patrol")
    FVector Location = FVector::ZeroVector;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Patrol")
    float AcceptanceRadius = -1.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Patrol")
    float WaitTime = 0.0f;
};
