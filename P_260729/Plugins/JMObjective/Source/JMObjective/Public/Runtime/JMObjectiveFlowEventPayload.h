#pragma once

#include "CoreMinimal.h"
#include "Payloads/JMGameplayEventPayloadBase.h"
#include "Types/JMObjectiveFlowTypes.h"
#include "JMObjectiveFlowEventPayload.generated.h"

UCLASS(BlueprintType)
class JMOBJECTIVE_API UJMObjectiveFlowEventPayload : public UJMGameplayEventPayloadBase
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadOnly, Category = "JM Objective Flow|Events")
    FGameplayTag FlowId;

    UPROPERTY(BlueprintReadOnly, Category = "JM Objective Flow|Events")
    EJMObjectiveFlowState FlowState = EJMObjectiveFlowState::Inactive;

    UPROPERTY(BlueprintReadOnly, Category = "JM Objective Flow|Events")
    int32 CurrentStepIndex = INDEX_NONE;

    UPROPERTY(BlueprintReadOnly, Category = "JM Objective Flow|Events")
    FGameplayTag CurrentObjectiveId;

    UPROPERTY(BlueprintReadOnly, Category = "JM Objective Flow|Events")
    int32 TotalStepCount = 0;
};

