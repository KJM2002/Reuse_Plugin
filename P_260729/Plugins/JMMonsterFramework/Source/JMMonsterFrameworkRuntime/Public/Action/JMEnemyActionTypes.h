#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "JMEnemyActionTypes.generated.h"

/** Execution-time arguments remain deliberately small; specialized actions can subclass later. */
USTRUCT(BlueprintType)
struct JMMONSTERFRAMEWORKRUNTIME_API FJMEnemyActionContext
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Action")
    TWeakObjectPtr<AActor> TargetActor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Action")
    FVector TargetLocation = FVector::ZeroVector;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Action")
    bool bHasTargetLocation = false;
};

UENUM(BlueprintType)
enum class EJMEnemyActionPhase : uint8
{
    Idle,
    Windup,
    Active,
    Recovery
};

UENUM(BlueprintType)
enum class EJMEnemyActionExecuteResult : uint8
{
    NotFound,
    CannotExecute,
    AlreadyRunning,
    Started
};
