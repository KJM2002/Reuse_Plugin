#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Types/JMObjectiveTypes.h"
#include "Types/JMObjectiveFlowTypes.h"
#include "JMObjectiveBlueprintLibrary.generated.h"

class UJMObjectiveDefinition;
class UJMObjectiveSubsystem;
class UJMObjectiveFlowDefinition;
class UJMObjectiveFlowSubsystem;

UCLASS()
class JMOBJECTIVE_API UJMObjectiveBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, Category = "JM Objective", meta = (WorldContext = "WorldContextObject"))
    static UJMObjectiveSubsystem* GetObjectiveSubsystem(const UObject* WorldContextObject);

    UFUNCTION(BlueprintCallable, Category = "JM Objective", meta = (WorldContext = "WorldContextObject"))
    static bool RegisterObjective(const UObject* WorldContextObject, UJMObjectiveDefinition* Definition);

    UFUNCTION(BlueprintCallable, Category = "JM Objective", meta = (WorldContext = "WorldContextObject"))
    static bool ActivateObjective(const UObject* WorldContextObject, FGameplayTag ObjectiveId);

    UFUNCTION(BlueprintCallable, Category = "JM Objective", meta = (WorldContext = "WorldContextObject"))
    static bool CompleteObjective(const UObject* WorldContextObject, FGameplayTag ObjectiveId);

    UFUNCTION(BlueprintCallable, Category = "JM Objective", meta = (WorldContext = "WorldContextObject"))
    static bool FailObjective(const UObject* WorldContextObject, FGameplayTag ObjectiveId);

    UFUNCTION(BlueprintCallable, Category = "JM Objective", meta = (WorldContext = "WorldContextObject"))
    static bool ResetObjective(const UObject* WorldContextObject, FGameplayTag ObjectiveId);

    UFUNCTION(BlueprintCallable, Category = "JM Objective", meta = (WorldContext = "WorldContextObject"))
    static bool AddObjectiveProgress(const UObject* WorldContextObject, FGameplayTag ObjectiveId, int32 Amount = 1);

    UFUNCTION(BlueprintPure, Category = "JM Objective", meta = (WorldContext = "WorldContextObject"))
    static bool GetObjectiveState(const UObject* WorldContextObject, FGameplayTag ObjectiveId, FJMObjectiveRuntimeState& OutState);

    UFUNCTION(BlueprintPure, Category = "JM Objective", meta = (WorldContext = "WorldContextObject"))
    static bool IsObjectiveCompleted(const UObject* WorldContextObject, FGameplayTag ObjectiveId);

    UFUNCTION(BlueprintPure, Category = "JM Objective Flow", meta = (WorldContext = "WorldContextObject"))
    static UJMObjectiveFlowSubsystem* GetObjectiveFlowSubsystem(const UObject* WorldContextObject);

    UFUNCTION(BlueprintCallable, Category = "JM Objective Flow", meta = (WorldContext = "WorldContextObject", DisplayName = "Start Objective Flow"))
    static bool StartObjectiveFlow(const UObject* WorldContextObject, UJMObjectiveFlowDefinition* FlowDefinition);

    UFUNCTION(BlueprintCallable, Category = "JM Objective Flow", meta = (WorldContext = "WorldContextObject"))
    static bool StopObjectiveFlow(const UObject* WorldContextObject, FGameplayTag FlowId);

    UFUNCTION(BlueprintCallable, Category = "JM Objective Flow", meta = (WorldContext = "WorldContextObject"))
    static bool ResetObjectiveFlow(const UObject* WorldContextObject, FGameplayTag FlowId);

    UFUNCTION(BlueprintCallable, Category = "JM Objective Flow", meta = (WorldContext = "WorldContextObject"))
    static bool RestartObjectiveFlow(const UObject* WorldContextObject, FGameplayTag FlowId);

    UFUNCTION(BlueprintPure, Category = "JM Objective Flow", meta = (WorldContext = "WorldContextObject"))
    static bool GetObjectiveFlowState(const UObject* WorldContextObject, FGameplayTag FlowId, FJMObjectiveFlowRuntimeState& OutState);

    UFUNCTION(BlueprintPure, Category = "JM Objective Flow|Save", meta = (WorldContext = "WorldContextObject"))
    static TArray<FJMObjectiveFlowSaveData> CaptureObjectiveFlowStates(const UObject* WorldContextObject);

    UFUNCTION(BlueprintCallable, Category = "JM Objective Flow|Save", meta = (WorldContext = "WorldContextObject"))
    static bool RestoreObjectiveFlowStates(const UObject* WorldContextObject, const TArray<FJMObjectiveFlowSaveData>& SavedStates);
};
