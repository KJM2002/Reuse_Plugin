#pragma once

#include "CoreMinimal.h"
#include "Payloads/JMGameplayEventPayloadBase.h"
#include "Subsystems/JMObjectiveFlowSubsystem.h"
#include "Subsystems/JMObjectiveSubsystem.h"
#include "Types/JMGameplayEventTypes.h"
#include "JMObjectiveTestReceiver.generated.h"

UCLASS()
class UJMObjectiveTestPayload : public UJMGameplayEventPayloadBase
{
    GENERATED_BODY()
};

UCLASS()
class UJMObjectiveTestReceiver : public UObject
{
    GENERATED_BODY()

public:
    int32 ReceivedCount = 0;
    void Receive(const FJMGameplayEventMessage& Message) { ++ReceivedCount; }
};

UCLASS()
class UJMObjectiveReentrancyReceiver : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY()
    TObjectPtr<UJMObjectiveSubsystem> Objectives;

    UPROPERTY()
    TObjectPtr<UJMObjectiveDefinition> ReplacementDefinition;

    UPROPERTY()
    TObjectPtr<UJMObjectiveFlowSubsystem> Flows;

    UPROPERTY()
    TObjectPtr<UJMObjectiveFlowDefinition> OtherFlow;

    int32 ProgressAction = 0;
    int32 CallbackCount = 0;

    UFUNCTION()
    void UnregisterOnState(FGameplayTag ObjectiveId, const FJMObjectiveRuntimeState& RuntimeState)
    {
        ++CallbackCount;
        if (Objectives)
        {
            Objectives->UnregisterObjective(ObjectiveId);
        }
    }

    UFUNCTION()
    void MutateOnProgress(FGameplayTag ObjectiveId, const FJMObjectiveRuntimeState& RuntimeState, int32 AppliedDelta)
    {
        ++CallbackCount;
        if (!Objectives)
        {
            return;
        }
        if (ProgressAction == 1)
        {
            Objectives->UnregisterObjective(ObjectiveId);
        }
        else if (ProgressAction == 2)
        {
            Objectives->UnregisterObjective(ObjectiveId);
            Objectives->RegisterObjectiveInactive(ReplacementDefinition);
        }
        else if (ProgressAction == 3)
        {
            Objectives->CompleteObjective(ObjectiveId);
        }
    }

    UFUNCTION()
    void StartOtherFlow(FGameplayTag FlowId, const FJMObjectiveFlowRuntimeState& RuntimeState)
    {
        ++CallbackCount;
        if (Flows && OtherFlow)
        {
            Flows->StartObjectiveFlow(OtherFlow);
        }
    }
};
