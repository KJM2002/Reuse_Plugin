#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Types/JMObjectiveTypes.h"
#include "JMObjectiveFlowTypes.generated.h"

class UJMObjectiveFlowDefinition;

UENUM(BlueprintType)
enum class EJMObjectiveFlowState : uint8
{
    Inactive,
    Active,
    Completed,
    Failed
};

USTRUCT(BlueprintType)
struct JMOBJECTIVE_API FJMObjectiveFlowRuntimeState
{
    GENERATED_BODY()

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JM Objective Flow")
    FGameplayTag FlowId;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JM Objective Flow")
    TObjectPtr<UJMObjectiveFlowDefinition> Definition = nullptr;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JM Objective Flow")
    EJMObjectiveFlowState State = EJMObjectiveFlowState::Inactive;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JM Objective Flow")
    int32 CurrentStepIndex = INDEX_NONE;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JM Objective Flow")
    FGameplayTag CurrentObjectiveId;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JM Objective Flow")
    FDateTime StartTime;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JM Objective Flow")
    FDateTime CompletionTime;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JM Objective Flow")
    FDateTime FailureTime;
};

USTRUCT(BlueprintType)
struct JMOBJECTIVE_API FJMObjectiveFlowSaveData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "JM Objective Flow")
    FGameplayTag FlowId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "JM Objective Flow")
    TSoftObjectPtr<UJMObjectiveFlowDefinition> Definition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "JM Objective Flow")
    EJMObjectiveFlowState State = EJMObjectiveFlowState::Inactive;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "JM Objective Flow")
    int32 CurrentStepIndex = INDEX_NONE;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "JM Objective Flow")
    FGameplayTag CurrentObjectiveId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "JM Objective Flow")
    FDateTime StartTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "JM Objective Flow")
    FDateTime CompletionTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "JM Objective Flow")
    FDateTime FailureTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "JM Objective Flow")
    TArray<FJMObjectiveSaveData> ObjectiveStates;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FJMObjectiveFlowStateChangedSignature, FGameplayTag, FlowId, const FJMObjectiveFlowRuntimeState&, RuntimeState);

