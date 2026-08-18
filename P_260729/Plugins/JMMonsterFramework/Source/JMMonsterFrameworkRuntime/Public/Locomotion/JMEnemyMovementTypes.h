#pragma once

#include "CoreMinimal.h"
#include "JMEnemyMovementTypes.generated.h"

/** A small, definition-local set of values that materially changes ground movement character. */
USTRUCT(BlueprintType)
struct JMMONSTERFRAMEWORKRUNTIME_API FJMEnemyMovementProfile
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Movement")
    FName ProfileName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Movement", meta=(ClampMin="0.0"))
    float MaxSpeed = 300.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Movement", meta=(ClampMin="0.0"))
    float MaxAcceleration = 1200.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Movement")
    FRotator RotationRate = FRotator(0.0, 360.0, 0.0);

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Movement", meta=(ClampMin="0.0"))
    float AcceptanceRadius = 75.0f;

    bool IsValid() const
    {
        return !ProfileName.IsNone() && MaxSpeed >= 0.0f && MaxAcceleration >= 0.0f &&
            AcceptanceRadius >= 0.0f;
    }
};

UENUM(BlueprintType)
enum class EJMEnemyMoveRequestResult : uint8
{
    RequestFailed,
    AlreadyAtGoal,
    RequestStarted
};

UENUM(BlueprintType)
enum class EJMEnemyMoveStatus : uint8
{
    Idle,
    Moving,
    Succeeded,
    Failed,
    Aborted
};

UENUM(BlueprintType)
enum class EJMEnemyFacingMode : uint8
{
    ControllerFocus,
    Immediate
};

/** Minimal options shared by actor and location moves. Negative radius uses the active profile. */
USTRUCT(BlueprintType)
struct JMMONSTERFRAMEWORKRUNTIME_API FJMEnemyMoveOptions
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta=(ClampMin="-1.0"))
    float AcceptanceRadius = -1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
    bool bStopOnOverlap = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
    bool bUsePathfinding = true;

    /** Conservative V1 default: an unreachable final goal is a failure. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
    bool bAllowPartialPath = false;
};
