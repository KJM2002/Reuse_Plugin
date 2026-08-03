#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "JMObjectiveTypes.generated.h"

class UJMObjectiveDefinition;

UENUM(BlueprintType)
enum class EJMObjectiveState : uint8
{
    Inactive,
    Active,
    Completed,
    Failed
};

UENUM(BlueprintType)
enum class EJMObjectiveProgressIncrementMode : uint8
{
    FixedAmount,
    PayloadAmount
};

USTRUCT(BlueprintType)
struct JMOBJECTIVE_API FJMObjectiveRuntimeState
{
    GENERATED_BODY()

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JM Objective")
    FGameplayTag ObjectiveId;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JM Objective")
    TObjectPtr<UJMObjectiveDefinition> Definition = nullptr;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JM Objective")
    EJMObjectiveState State = EJMObjectiveState::Inactive;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JM Objective")
    int32 CurrentCount = 0;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JM Objective")
    int32 RequiredCount = 1;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JM Objective")
    FDateTime ActivationTime;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JM Objective")
    FDateTime CompletionTime;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JM Objective")
    FDateTime FailureTime;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JM Objective|Debug")
    FGameplayTag LastEventTag;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JM Objective|Debug")
    FName LastTargetIdentifier;
};

USTRUCT(BlueprintType)
struct JMOBJECTIVE_API FJMObjectiveSaveData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "JM Objective")
    FGameplayTag ObjectiveId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "JM Objective")
    EJMObjectiveState State = EJMObjectiveState::Inactive;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "JM Objective")
    int32 CurrentCount = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "JM Objective")
    FDateTime ActivationTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "JM Objective")
    FDateTime CompletionTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "JM Objective")
    FDateTime FailureTime;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FJMObjectiveStateChangedSignature, FGameplayTag, ObjectiveId, const FJMObjectiveRuntimeState&, RuntimeState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FJMObjectiveProgressedSignature, FGameplayTag, ObjectiveId, const FJMObjectiveRuntimeState&, RuntimeState, int32, ProgressDelta);
