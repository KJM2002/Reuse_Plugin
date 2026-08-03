#include "Blueprint/JMObjectiveBlueprintLibrary.h"

#include "Data/JMObjectiveDefinition.h"
#include "Data/JMObjectiveFlowDefinition.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Subsystems/JMObjectiveSubsystem.h"
#include "Subsystems/JMObjectiveFlowSubsystem.h"

UJMObjectiveSubsystem* UJMObjectiveBlueprintLibrary::GetObjectiveSubsystem(const UObject* WorldContextObject)
{
    if (!IsValid(WorldContextObject)) return nullptr;
    const UWorld* World = WorldContextObject->GetWorld();
    UGameInstance* GameInstance = World ? World->GetGameInstance() : Cast<UGameInstance>(const_cast<UObject*>(WorldContextObject));
    return GameInstance ? GameInstance->GetSubsystem<UJMObjectiveSubsystem>() : nullptr;
}

bool UJMObjectiveBlueprintLibrary::RegisterObjective(const UObject* WorldContextObject, UJMObjectiveDefinition* Definition)
{
    UJMObjectiveSubsystem* Subsystem = GetObjectiveSubsystem(WorldContextObject);
    return Subsystem && Subsystem->RegisterObjective(Definition);
}

bool UJMObjectiveBlueprintLibrary::ActivateObjective(const UObject* WorldContextObject, FGameplayTag ObjectiveId)
{
    UJMObjectiveSubsystem* Subsystem = GetObjectiveSubsystem(WorldContextObject);
    return Subsystem && Subsystem->ActivateObjective(ObjectiveId);
}

bool UJMObjectiveBlueprintLibrary::CompleteObjective(const UObject* WorldContextObject, FGameplayTag ObjectiveId)
{
    UJMObjectiveSubsystem* Subsystem = GetObjectiveSubsystem(WorldContextObject);
    return Subsystem && Subsystem->CompleteObjective(ObjectiveId);
}

bool UJMObjectiveBlueprintLibrary::FailObjective(const UObject* WorldContextObject, FGameplayTag ObjectiveId)
{
    UJMObjectiveSubsystem* Subsystem = GetObjectiveSubsystem(WorldContextObject);
    return Subsystem && Subsystem->FailObjective(ObjectiveId);
}

bool UJMObjectiveBlueprintLibrary::ResetObjective(const UObject* WorldContextObject, FGameplayTag ObjectiveId)
{
    UJMObjectiveSubsystem* Subsystem = GetObjectiveSubsystem(WorldContextObject);
    return Subsystem && Subsystem->ResetObjective(ObjectiveId);
}

bool UJMObjectiveBlueprintLibrary::AddObjectiveProgress(const UObject* WorldContextObject, FGameplayTag ObjectiveId, int32 Amount)
{
    UJMObjectiveSubsystem* Subsystem = GetObjectiveSubsystem(WorldContextObject);
    return Subsystem && Subsystem->AddObjectiveProgress(ObjectiveId, Amount);
}

bool UJMObjectiveBlueprintLibrary::GetObjectiveState(const UObject* WorldContextObject, FGameplayTag ObjectiveId, FJMObjectiveRuntimeState& OutState)
{
    UJMObjectiveSubsystem* Subsystem = GetObjectiveSubsystem(WorldContextObject);
    return Subsystem && Subsystem->GetObjectiveState(ObjectiveId, OutState);
}

bool UJMObjectiveBlueprintLibrary::IsObjectiveCompleted(const UObject* WorldContextObject, FGameplayTag ObjectiveId)
{
    UJMObjectiveSubsystem* Subsystem = GetObjectiveSubsystem(WorldContextObject);
    return Subsystem && Subsystem->IsObjectiveCompleted(ObjectiveId);
}

UJMObjectiveFlowSubsystem* UJMObjectiveBlueprintLibrary::GetObjectiveFlowSubsystem(const UObject* WorldContextObject)
{
    if (!IsValid(WorldContextObject)) return nullptr;
    const UWorld* World = WorldContextObject->GetWorld();
    UGameInstance* GameInstance = World ? World->GetGameInstance() : Cast<UGameInstance>(const_cast<UObject*>(WorldContextObject));
    return GameInstance ? GameInstance->GetSubsystem<UJMObjectiveFlowSubsystem>() : nullptr;
}

bool UJMObjectiveBlueprintLibrary::StartObjectiveFlow(const UObject* WorldContextObject, UJMObjectiveFlowDefinition* FlowDefinition)
{
    UJMObjectiveFlowSubsystem* Subsystem = GetObjectiveFlowSubsystem(WorldContextObject);
    return Subsystem && Subsystem->StartObjectiveFlow(FlowDefinition);
}

bool UJMObjectiveBlueprintLibrary::StopObjectiveFlow(const UObject* WorldContextObject, FGameplayTag FlowId)
{
    UJMObjectiveFlowSubsystem* Subsystem = GetObjectiveFlowSubsystem(WorldContextObject);
    return Subsystem && Subsystem->StopObjectiveFlow(FlowId);
}

bool UJMObjectiveBlueprintLibrary::ResetObjectiveFlow(const UObject* WorldContextObject, FGameplayTag FlowId)
{
    UJMObjectiveFlowSubsystem* Subsystem = GetObjectiveFlowSubsystem(WorldContextObject);
    return Subsystem && Subsystem->ResetObjectiveFlow(FlowId);
}

bool UJMObjectiveBlueprintLibrary::RestartObjectiveFlow(const UObject* WorldContextObject, FGameplayTag FlowId)
{
    UJMObjectiveFlowSubsystem* Subsystem = GetObjectiveFlowSubsystem(WorldContextObject);
    return Subsystem && Subsystem->RestartObjectiveFlow(FlowId);
}

bool UJMObjectiveBlueprintLibrary::GetObjectiveFlowState(const UObject* WorldContextObject, FGameplayTag FlowId, FJMObjectiveFlowRuntimeState& OutState)
{
    UJMObjectiveFlowSubsystem* Subsystem = GetObjectiveFlowSubsystem(WorldContextObject);
    return Subsystem && Subsystem->GetObjectiveFlowState(FlowId, OutState);
}

TArray<FJMObjectiveFlowSaveData> UJMObjectiveBlueprintLibrary::CaptureObjectiveFlowStates(const UObject* WorldContextObject)
{
    UJMObjectiveFlowSubsystem* Subsystem = GetObjectiveFlowSubsystem(WorldContextObject);
    return Subsystem ? Subsystem->CaptureObjectiveFlowStates() : TArray<FJMObjectiveFlowSaveData>();
}

bool UJMObjectiveBlueprintLibrary::RestoreObjectiveFlowStates(const UObject* WorldContextObject, const TArray<FJMObjectiveFlowSaveData>& SavedStates)
{
    UJMObjectiveFlowSubsystem* Subsystem = GetObjectiveFlowSubsystem(WorldContextObject);
    return Subsystem && Subsystem->RestoreObjectiveFlowStates(SavedStates);
}
