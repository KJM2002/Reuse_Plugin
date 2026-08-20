#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Types/JMObjectiveFlowTypes.h"
#include "JMObjectiveFlowSubsystem.generated.h"

class UJMGameplayEventSubsystem;
class UJMObjectiveDefinition;
class UJMObjectiveFlowDefinition;
class UJMObjectiveSubsystem;

UCLASS()
class JMOBJECTIVE_API UJMObjectiveFlowSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    UPROPERTY(BlueprintAssignable, Category = "JM Objective Flow|Events")
    FJMObjectiveFlowStateChangedSignature OnObjectiveFlowStarted;

    UPROPERTY(BlueprintAssignable, Category = "JM Objective Flow|Events")
    FJMObjectiveFlowStateChangedSignature OnObjectiveFlowStepChanged;

    UPROPERTY(BlueprintAssignable, Category = "JM Objective Flow|Events")
    FJMObjectiveFlowStateChangedSignature OnObjectiveFlowCompleted;

    UPROPERTY(BlueprintAssignable, Category = "JM Objective Flow|Events")
    FJMObjectiveFlowStateChangedSignature OnObjectiveFlowFailed;

    UPROPERTY(BlueprintAssignable, Category = "JM Objective Flow|Events")
    FJMObjectiveFlowStateChangedSignature OnObjectiveFlowStopped;

    UFUNCTION(BlueprintCallable, Category = "JM Objective Flow")
    bool StartObjectiveFlow(UJMObjectiveFlowDefinition* Definition);

    UFUNCTION(BlueprintCallable, Category = "JM Objective Flow")
    bool StopObjectiveFlow(FGameplayTag FlowId);

    UFUNCTION(BlueprintCallable, Category = "JM Objective Flow")
    bool ResetObjectiveFlow(FGameplayTag FlowId);

    UFUNCTION(BlueprintCallable, Category = "JM Objective Flow")
    bool RestartObjectiveFlow(FGameplayTag FlowId);

    UFUNCTION(BlueprintPure, Category = "JM Objective Flow")
    bool GetObjectiveFlowState(FGameplayTag FlowId, FJMObjectiveFlowRuntimeState& OutState) const;

    UFUNCTION(BlueprintPure, Category = "JM Objective Flow")
    TArray<FJMObjectiveFlowRuntimeState> GetActiveObjectiveFlows() const;

    UFUNCTION(BlueprintPure, Category = "JM Objective Flow")
    bool IsObjectiveFlowActive(FGameplayTag FlowId) const;

    UFUNCTION(BlueprintPure, Category = "JM Objective Flow")
    bool IsObjectiveFlowCompleted(FGameplayTag FlowId) const;

    UFUNCTION(BlueprintPure, Category = "JM Objective Flow|Save")
    TArray<FJMObjectiveFlowSaveData> CaptureObjectiveFlowStates() const;

    UFUNCTION(BlueprintCallable, Category = "JM Objective Flow|Save")
    bool RestoreObjectiveFlowStates(const TArray<FJMObjectiveFlowSaveData>& SavedStates);

#if WITH_DEV_AUTOMATION_TESTS
    void SetSubsystemsForTesting(UJMObjectiveSubsystem* InObjectives, UJMGameplayEventSubsystem* InEvents);
#endif

private:
    UPROPERTY(Transient)
    TMap<FGameplayTag, FJMObjectiveFlowRuntimeState> FlowStates;

    UPROPERTY(Transient)
    TObjectPtr<UJMObjectiveSubsystem> ObjectiveSubsystem = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UJMGameplayEventSubsystem> EventSubsystem = nullptr;

    void BindObjectiveDelegates();
    void UnbindObjectiveDelegates();
    bool PrepareObjectives(UJMObjectiveFlowDefinition* Definition, bool bResetExisting);
    bool ActivateCurrentStep(FGameplayTag FlowId, bool bBroadcastStepChanged);
    bool AdvanceFlow(FGameplayTag FlowId);
    bool DoesAnotherActiveFlowUseObjective(FGameplayTag FlowId, FGameplayTag ObjectiveId) const;
    void PublishFlowEvent(FGameplayTag EventTag, const FJMObjectiveFlowRuntimeState& RuntimeState) const;

    UFUNCTION()
    void HandleObjectiveCompleted(FGameplayTag ObjectiveId, const FJMObjectiveRuntimeState& RuntimeState);

    UFUNCTION()
    void HandleObjectiveFailed(FGameplayTag ObjectiveId, const FJMObjectiveRuntimeState& RuntimeState);
};

