#pragma once

#include "CoreMinimal.h"
#include "Payloads/JMGameplayEventPayloadBase.h"
#include "Types/JMObjectiveTypes.h"
#include "JMObjectiveEventPayload.generated.h"

UCLASS(BlueprintType)
class JMOBJECTIVE_API UJMObjectiveEventPayload : public UJMGameplayEventPayloadBase
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadOnly, Category = "JM Objective|Events")
    FGameplayTag ObjectiveId;

    UPROPERTY(BlueprintReadOnly, Category = "JM Objective|Events")
    EJMObjectiveState State = EJMObjectiveState::Inactive;

    UPROPERTY(BlueprintReadOnly, Category = "JM Objective|Events")
    int32 CurrentCount = 0;

    UPROPERTY(BlueprintReadOnly, Category = "JM Objective|Events")
    int32 RequiredCount = 1;

    UPROPERTY(BlueprintReadOnly, Category = "JM Objective|Events")
    int32 ProgressDelta = 0;
};
