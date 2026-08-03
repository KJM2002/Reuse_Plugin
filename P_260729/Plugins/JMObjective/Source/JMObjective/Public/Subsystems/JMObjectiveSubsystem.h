#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Types/JMGameplayEventTypes.h"
#include "Types/JMObjectiveTypes.h"
#include "JMObjectiveSubsystem.generated.h"

class UJMGameplayEventSubsystem;
class UJMObjectiveDefinition;

UCLASS()
class JMOBJECTIVE_API UJMObjectiveSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    UPROPERTY(BlueprintAssignable, Category = "JM Objective|Events")
    FJMObjectiveStateChangedSignature OnObjectiveRegistered;

    UPROPERTY(BlueprintAssignable, Category = "JM Objective|Events")
    FJMObjectiveStateChangedSignature OnObjectiveActivated;

    UPROPERTY(BlueprintAssignable, Category = "JM Objective|Events")
    FJMObjectiveProgressedSignature OnObjectiveProgressed;

    UPROPERTY(BlueprintAssignable, Category = "JM Objective|Events")
    FJMObjectiveStateChangedSignature OnObjectiveCompleted;

    UPROPERTY(BlueprintAssignable, Category = "JM Objective|Events")
    FJMObjectiveStateChangedSignature OnObjectiveFailed;

    UPROPERTY(BlueprintAssignable, Category = "JM Objective|Events")
    FJMObjectiveStateChangedSignature OnObjectiveDeactivated;

    UPROPERTY(BlueprintAssignable, Category = "JM Objective|Events")
    FJMObjectiveStateChangedSignature OnObjectiveReset;

    UPROPERTY(BlueprintAssignable, Category = "JM Objective|Events")
    FJMObjectiveStateChangedSignature OnObjectiveRemoved;

    UFUNCTION(BlueprintCallable, Category = "JM Objective")
    bool RegisterObjective(UJMObjectiveDefinition* Definition);

    /** Registers an Objective in Inactive state regardless of its bAutoActivate value. Used by data-driven Flow setup. */
    bool RegisterObjectiveInactive(UJMObjectiveDefinition* Definition);

    UFUNCTION(BlueprintCallable, Category = "JM Objective")
    bool UnregisterObjective(FGameplayTag ObjectiveId);

    UFUNCTION(BlueprintCallable, Category = "JM Objective")
    bool ActivateObjective(FGameplayTag ObjectiveId);

    UFUNCTION(BlueprintCallable, Category = "JM Objective")
    bool DeactivateObjective(FGameplayTag ObjectiveId);

    UFUNCTION(BlueprintCallable, Category = "JM Objective")
    bool CompleteObjective(FGameplayTag ObjectiveId);

    UFUNCTION(BlueprintCallable, Category = "JM Objective")
    bool FailObjective(FGameplayTag ObjectiveId);

    UFUNCTION(BlueprintCallable, Category = "JM Objective")
    bool ResetObjective(FGameplayTag ObjectiveId);

    UFUNCTION(BlueprintCallable, Category = "JM Objective")
    bool AddObjectiveProgress(FGameplayTag ObjectiveId, int32 Amount = 1);

    UFUNCTION(BlueprintPure, Category = "JM Objective")
    bool GetObjectiveState(FGameplayTag ObjectiveId, FJMObjectiveRuntimeState& OutState) const;

    UFUNCTION(BlueprintPure, Category = "JM Objective")
    bool GetObjectiveProgress(FGameplayTag ObjectiveId, int32& OutCurrentCount, int32& OutRequiredCount) const;

    UFUNCTION(BlueprintPure, Category = "JM Objective")
    TArray<FJMObjectiveRuntimeState> GetActiveObjectives() const;

    UFUNCTION(BlueprintPure, Category = "JM Objective")
    TArray<FJMObjectiveRuntimeState> GetCompletedObjectives() const;

    UFUNCTION(BlueprintPure, Category = "JM Objective")
    bool IsObjectiveActive(FGameplayTag ObjectiveId) const;

    UFUNCTION(BlueprintPure, Category = "JM Objective")
    bool IsObjectiveCompleted(FGameplayTag ObjectiveId) const;

    UFUNCTION(BlueprintPure, Category = "JM Objective|Save")
    TArray<FJMObjectiveSaveData> CaptureObjectiveStates() const;

    UFUNCTION(BlueprintCallable, Category = "JM Objective|Save")
    bool RestoreObjectiveStates(const TArray<FJMObjectiveSaveData>& SavedStates);

#if WITH_DEV_AUTOMATION_TESTS
    void SetGameplayEventSubsystemForTesting(UJMGameplayEventSubsystem* InSubsystem);
#endif

private:
    UPROPERTY(Transient)
    TMap<FGameplayTag, FJMObjectiveRuntimeState> ObjectiveStates;

    UPROPERTY(Transient)
    TObjectPtr<UJMGameplayEventSubsystem> CachedEventSubsystem = nullptr;

    TMap<FGameplayTag, FJMGameplayEventSubscriptionHandle> SubscriptionHandles;

    UJMGameplayEventSubsystem* ResolveEventSubsystem();
    bool SubscribeObjective(FGameplayTag ObjectiveId);
    void UnsubscribeObjective(FGameplayTag ObjectiveId);
    void HandleGameplayEvent(const FJMGameplayEventMessage& Message, FGameplayTag ObjectiveId);
    bool DoesEventPassFilters(const FJMObjectiveRuntimeState& RuntimeState, const FJMGameplayEventMessage& Message, FName& OutReceivedTarget, FString& OutFailureReason) const;
    bool ApplyProgress(FGameplayTag ObjectiveId, int32 Amount, const FJMGameplayEventMessage* SourceMessage, FName ReceivedTarget);
    void PublishObjectiveEvent(FGameplayTag EventTag, const FJMObjectiveRuntimeState& RuntimeState, int32 ProgressDelta, const FJMGameplayEventMessage* SourceMessage);
    bool ShouldLog() const;
    bool RegisterObjectiveInternal(UJMObjectiveDefinition* Definition, bool bHonorAutoActivate);
};
