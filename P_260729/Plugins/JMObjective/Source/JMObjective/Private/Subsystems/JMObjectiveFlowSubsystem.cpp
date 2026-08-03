#include "Subsystems/JMObjectiveFlowSubsystem.h"

#include "Data/JMObjectiveDefinition.h"
#include "Data/JMObjectiveFlowDefinition.h"
#include "Engine/GameInstance.h"
#include "JMObjective.h"
#include "Runtime/JMObjectiveFlowEventPayload.h"
#include "Runtime/JMObjectiveFlowEventTags.h"
#include "Subsystems/JMGameplayEventSubsystem.h"
#include "Subsystems/JMObjectiveSubsystem.h"

void UJMObjectiveFlowSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    Collection.InitializeDependency<UJMObjectiveSubsystem>();
    Collection.InitializeDependency<UJMGameplayEventSubsystem>();
    ObjectiveSubsystem = GetGameInstance() ? GetGameInstance()->GetSubsystem<UJMObjectiveSubsystem>() : nullptr;
    EventSubsystem = GetGameInstance() ? GetGameInstance()->GetSubsystem<UJMGameplayEventSubsystem>() : nullptr;
    BindObjectiveDelegates();
}

void UJMObjectiveFlowSubsystem::Deinitialize()
{
    UnbindObjectiveDelegates();
    FlowStates.Reset();
    ObjectiveSubsystem = nullptr;
    EventSubsystem = nullptr;
    Super::Deinitialize();
}

void UJMObjectiveFlowSubsystem::BindObjectiveDelegates()
{
    if (!ObjectiveSubsystem)
    {
        return;
    }
    ObjectiveSubsystem->OnObjectiveCompleted.AddUniqueDynamic(this, &UJMObjectiveFlowSubsystem::HandleObjectiveCompleted);
    ObjectiveSubsystem->OnObjectiveFailed.AddUniqueDynamic(this, &UJMObjectiveFlowSubsystem::HandleObjectiveFailed);
}

void UJMObjectiveFlowSubsystem::UnbindObjectiveDelegates()
{
    if (!ObjectiveSubsystem)
    {
        return;
    }
    ObjectiveSubsystem->OnObjectiveCompleted.RemoveDynamic(this, &UJMObjectiveFlowSubsystem::HandleObjectiveCompleted);
    ObjectiveSubsystem->OnObjectiveFailed.RemoveDynamic(this, &UJMObjectiveFlowSubsystem::HandleObjectiveFailed);
}

bool UJMObjectiveFlowSubsystem::StartObjectiveFlow(UJMObjectiveFlowDefinition* Definition)
{
    FText ValidationError;
    if (!IsValid(Definition) || !Definition->IsFlowDefinitionValid(ValidationError) || !ObjectiveSubsystem)
    {
        UE_LOG(LogJMObjective, Warning, TEXT("StartObjectiveFlow rejected: %s"), *ValidationError.ToString());
        return false;
    }

    if (const FJMObjectiveFlowRuntimeState* Existing = FlowStates.Find(Definition->FlowId))
    {
        if (Existing->Definition != Definition || Existing->State == EJMObjectiveFlowState::Active || !Definition->bAllowRestart)
        {
            return false;
        }
        return RestartObjectiveFlow(Definition->FlowId);
    }

    if (!PrepareObjectives(Definition, true))
    {
        return false;
    }

    FJMObjectiveFlowRuntimeState& RuntimeState = FlowStates.Add(Definition->FlowId);
    RuntimeState.FlowId = Definition->FlowId;
    RuntimeState.Definition = Definition;
    RuntimeState.State = EJMObjectiveFlowState::Active;
    RuntimeState.CurrentStepIndex = 0;
    RuntimeState.CurrentObjectiveId = Definition->ObjectiveDefinitions[0]->ObjectiveId;
    RuntimeState.StartTime = FDateTime::UtcNow();

    if (!ActivateCurrentStep(RuntimeState, false))
    {
        FlowStates.Remove(Definition->FlowId);
        return false;
    }

    OnObjectiveFlowStarted.Broadcast(RuntimeState.FlowId, RuntimeState);
    PublishFlowEvent(JMObjectiveFlowEventTags::Started, RuntimeState);
    return true;
}

bool UJMObjectiveFlowSubsystem::StopObjectiveFlow(FGameplayTag FlowId)
{
    FJMObjectiveFlowRuntimeState* RuntimeState = FlowStates.Find(FlowId);
    if (!RuntimeState || RuntimeState->State != EJMObjectiveFlowState::Active || !ObjectiveSubsystem)
    {
        return false;
    }
    ObjectiveSubsystem->DeactivateObjective(RuntimeState->CurrentObjectiveId);
    RuntimeState->State = EJMObjectiveFlowState::Inactive;
    OnObjectiveFlowStopped.Broadcast(FlowId, *RuntimeState);
    PublishFlowEvent(JMObjectiveFlowEventTags::Stopped, *RuntimeState);
    return true;
}

bool UJMObjectiveFlowSubsystem::ResetObjectiveFlow(FGameplayTag FlowId)
{
    FJMObjectiveFlowRuntimeState* RuntimeState = FlowStates.Find(FlowId);
    if (!RuntimeState || !IsValid(RuntimeState->Definition) || !ObjectiveSubsystem)
    {
        return false;
    }
    bool bSuccess = true;
    for (UJMObjectiveDefinition* Definition : RuntimeState->Definition->ObjectiveDefinitions)
    {
        FJMObjectiveRuntimeState ObjectiveState;
        if (IsValid(Definition) && ObjectiveSubsystem->GetObjectiveState(Definition->ObjectiveId, ObjectiveState))
        {
            bSuccess &= ObjectiveSubsystem->ResetObjective(Definition->ObjectiveId);
        }
    }
    RuntimeState->State = EJMObjectiveFlowState::Inactive;
    RuntimeState->CurrentStepIndex = INDEX_NONE;
    RuntimeState->CurrentObjectiveId = FGameplayTag();
    RuntimeState->StartTime = FDateTime();
    RuntimeState->CompletionTime = FDateTime();
    RuntimeState->FailureTime = FDateTime();
    return bSuccess;
}

bool UJMObjectiveFlowSubsystem::RestartObjectiveFlow(FGameplayTag FlowId)
{
    FJMObjectiveFlowRuntimeState* RuntimeState = FlowStates.Find(FlowId);
    if (!RuntimeState || !IsValid(RuntimeState->Definition) || !RuntimeState->Definition->bAllowRestart || RuntimeState->State == EJMObjectiveFlowState::Active || !ObjectiveSubsystem)
    {
        return false;
    }

    UJMObjectiveFlowDefinition* Definition = RuntimeState->Definition;
    if (!PrepareObjectives(Definition, true))
    {
        return false;
    }
    RuntimeState->State = EJMObjectiveFlowState::Active;
    RuntimeState->CurrentStepIndex = 0;
    RuntimeState->CurrentObjectiveId = Definition->ObjectiveDefinitions[0]->ObjectiveId;
    RuntimeState->StartTime = FDateTime::UtcNow();
    RuntimeState->CompletionTime = FDateTime();
    RuntimeState->FailureTime = FDateTime();
    if (!ActivateCurrentStep(*RuntimeState, false))
    {
        RuntimeState->State = EJMObjectiveFlowState::Inactive;
        return false;
    }
    OnObjectiveFlowStarted.Broadcast(FlowId, *RuntimeState);
    PublishFlowEvent(JMObjectiveFlowEventTags::Started, *RuntimeState);
    return true;
}

bool UJMObjectiveFlowSubsystem::GetObjectiveFlowState(FGameplayTag FlowId, FJMObjectiveFlowRuntimeState& OutState) const
{
    const FJMObjectiveFlowRuntimeState* RuntimeState = FlowStates.Find(FlowId);
    if (!RuntimeState)
    {
        return false;
    }
    OutState = *RuntimeState;
    return true;
}

TArray<FJMObjectiveFlowRuntimeState> UJMObjectiveFlowSubsystem::GetActiveObjectiveFlows() const
{
    TArray<FJMObjectiveFlowRuntimeState> Result;
    for (const TPair<FGameplayTag, FJMObjectiveFlowRuntimeState>& Pair : FlowStates)
    {
        if (Pair.Value.State == EJMObjectiveFlowState::Active)
        {
            Result.Add(Pair.Value);
        }
    }
    Result.Sort([](const FJMObjectiveFlowRuntimeState& A, const FJMObjectiveFlowRuntimeState& B) { return A.StartTime < B.StartTime; });
    return Result;
}

bool UJMObjectiveFlowSubsystem::IsObjectiveFlowActive(FGameplayTag FlowId) const
{
    const FJMObjectiveFlowRuntimeState* RuntimeState = FlowStates.Find(FlowId);
    return RuntimeState && RuntimeState->State == EJMObjectiveFlowState::Active;
}

bool UJMObjectiveFlowSubsystem::IsObjectiveFlowCompleted(FGameplayTag FlowId) const
{
    const FJMObjectiveFlowRuntimeState* RuntimeState = FlowStates.Find(FlowId);
    return RuntimeState && RuntimeState->State == EJMObjectiveFlowState::Completed;
}

bool UJMObjectiveFlowSubsystem::PrepareObjectives(UJMObjectiveFlowDefinition* Definition, bool bResetExisting)
{
    // Validate the complete set before mutating any Objective state.
    for (UJMObjectiveDefinition* ObjectiveDefinition : Definition->ObjectiveDefinitions)
    {
        if (DoesAnotherActiveFlowUseObjective(Definition->FlowId, ObjectiveDefinition->ObjectiveId))
        {
            UE_LOG(LogJMObjective, Warning, TEXT("Flow %s cannot use Objective %s while another Flow is active."), *Definition->FlowId.ToString(), *ObjectiveDefinition->ObjectiveId.ToString());
            return false;
        }

        FJMObjectiveRuntimeState Existing;
        if (ObjectiveSubsystem->GetObjectiveState(ObjectiveDefinition->ObjectiveId, Existing))
        {
            if (Existing.Definition != ObjectiveDefinition)
            {
                UE_LOG(LogJMObjective, Error, TEXT("Objective ID %s is already registered with a different Definition."), *ObjectiveDefinition->ObjectiveId.ToString());
                return false;
            }
        }
    }

    for (UJMObjectiveDefinition* ObjectiveDefinition : Definition->ObjectiveDefinitions)
    {
        FJMObjectiveRuntimeState Existing;
        if (ObjectiveSubsystem->GetObjectiveState(ObjectiveDefinition->ObjectiveId, Existing))
        {
            if (bResetExisting && (Existing.State != EJMObjectiveState::Inactive || Existing.CurrentCount != 0))
            {
                ObjectiveSubsystem->ResetObjective(ObjectiveDefinition->ObjectiveId);
            }
        }
        else if (!ObjectiveSubsystem->RegisterObjectiveInactive(ObjectiveDefinition))
        {
            return false;
        }
    }
    return true;
}

bool UJMObjectiveFlowSubsystem::ActivateCurrentStep(FJMObjectiveFlowRuntimeState& RuntimeState, bool bBroadcastStepChanged)
{
    if (!ObjectiveSubsystem || !IsValid(RuntimeState.Definition) || !RuntimeState.Definition->ObjectiveDefinitions.IsValidIndex(RuntimeState.CurrentStepIndex))
    {
        return false;
    }
    RuntimeState.CurrentObjectiveId = RuntimeState.Definition->ObjectiveDefinitions[RuntimeState.CurrentStepIndex]->ObjectiveId;
    if (!ObjectiveSubsystem->ActivateObjective(RuntimeState.CurrentObjectiveId))
    {
        return false;
    }
    if (bBroadcastStepChanged)
    {
        OnObjectiveFlowStepChanged.Broadcast(RuntimeState.FlowId, RuntimeState);
        PublishFlowEvent(JMObjectiveFlowEventTags::StepChanged, RuntimeState);
    }
    return true;
}

bool UJMObjectiveFlowSubsystem::AdvanceFlow(FJMObjectiveFlowRuntimeState& RuntimeState)
{
    if (RuntimeState.State != EJMObjectiveFlowState::Active || !IsValid(RuntimeState.Definition))
    {
        return false;
    }
    const int32 NextStep = RuntimeState.CurrentStepIndex + 1;
    if (!RuntimeState.Definition->ObjectiveDefinitions.IsValidIndex(NextStep))
    {
        RuntimeState.State = EJMObjectiveFlowState::Completed;
        RuntimeState.CompletionTime = FDateTime::UtcNow();
        OnObjectiveFlowCompleted.Broadcast(RuntimeState.FlowId, RuntimeState);
        PublishFlowEvent(JMObjectiveFlowEventTags::Completed, RuntimeState);
        return true;
    }
    RuntimeState.CurrentStepIndex = NextStep;
    if (ActivateCurrentStep(RuntimeState, true))
    {
        return true;
    }
    RuntimeState.State = EJMObjectiveFlowState::Failed;
    RuntimeState.FailureTime = FDateTime::UtcNow();
    OnObjectiveFlowFailed.Broadcast(RuntimeState.FlowId, RuntimeState);
    PublishFlowEvent(JMObjectiveFlowEventTags::Failed, RuntimeState);
    return false;
}

void UJMObjectiveFlowSubsystem::HandleObjectiveCompleted(FGameplayTag ObjectiveId, const FJMObjectiveRuntimeState& RuntimeState)
{
    TArray<FGameplayTag> MatchingFlows;
    for (const TPair<FGameplayTag, FJMObjectiveFlowRuntimeState>& Pair : FlowStates)
    {
        if (Pair.Value.State == EJMObjectiveFlowState::Active && Pair.Value.CurrentObjectiveId == ObjectiveId)
        {
            MatchingFlows.Add(Pair.Key);
        }
    }
    for (const FGameplayTag FlowId : MatchingFlows)
    {
        if (FJMObjectiveFlowRuntimeState* FlowState = FlowStates.Find(FlowId); FlowState && FlowState->CurrentObjectiveId == ObjectiveId)
        {
            AdvanceFlow(*FlowState);
        }
    }
}

void UJMObjectiveFlowSubsystem::HandleObjectiveFailed(FGameplayTag ObjectiveId, const FJMObjectiveRuntimeState& RuntimeState)
{
    TArray<FGameplayTag> MatchingFlows;
    for (const TPair<FGameplayTag, FJMObjectiveFlowRuntimeState>& Pair : FlowStates)
    {
        if (Pair.Value.State == EJMObjectiveFlowState::Active && Pair.Value.CurrentObjectiveId == ObjectiveId)
        {
            MatchingFlows.Add(Pair.Key);
        }
    }
    for (const FGameplayTag FlowId : MatchingFlows)
    {
        FJMObjectiveFlowRuntimeState* FlowState = FlowStates.Find(FlowId);
        if (!FlowState || !IsValid(FlowState->Definition) || FlowState->CurrentObjectiveId != ObjectiveId)
        {
            continue;
        }
        if (FlowState->Definition->bStopOnObjectiveFailure)
        {
            FlowState->State = EJMObjectiveFlowState::Failed;
            FlowState->FailureTime = FDateTime::UtcNow();
            OnObjectiveFlowFailed.Broadcast(FlowId, *FlowState);
            PublishFlowEvent(JMObjectiveFlowEventTags::Failed, *FlowState);
        }
        else
        {
            AdvanceFlow(*FlowState);
        }
    }
}

bool UJMObjectiveFlowSubsystem::DoesAnotherActiveFlowUseObjective(FGameplayTag FlowId, FGameplayTag ObjectiveId) const
{
    for (const TPair<FGameplayTag, FJMObjectiveFlowRuntimeState>& Pair : FlowStates)
    {
        if (Pair.Key != FlowId && Pair.Value.State == EJMObjectiveFlowState::Active && IsValid(Pair.Value.Definition))
        {
            for (const UJMObjectiveDefinition* Definition : Pair.Value.Definition->ObjectiveDefinitions)
            {
                if (IsValid(Definition) && Definition->ObjectiveId == ObjectiveId)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void UJMObjectiveFlowSubsystem::PublishFlowEvent(FGameplayTag EventTag, const FJMObjectiveFlowRuntimeState& RuntimeState) const
{
    if (!EventSubsystem || !EventTag.IsValid())
    {
        return;
    }
    UJMObjectiveFlowEventPayload* Payload = NewObject<UJMObjectiveFlowEventPayload>(const_cast<UJMObjectiveFlowSubsystem*>(this));
    Payload->FlowId = RuntimeState.FlowId;
    Payload->FlowState = RuntimeState.State;
    Payload->CurrentStepIndex = RuntimeState.CurrentStepIndex;
    Payload->CurrentObjectiveId = RuntimeState.CurrentObjectiveId;
    Payload->TotalStepCount = IsValid(RuntimeState.Definition) ? RuntimeState.Definition->ObjectiveDefinitions.Num() : 0;
    Payload->ObjectiveTargetIdentifier = RuntimeState.FlowId.GetTagName();
    FJMGameplayEventMessage Message;
    Message.EventTag = EventTag;
    Message.Source = const_cast<UJMObjectiveFlowSubsystem*>(this);
    Message.Target = RuntimeState.Definition;
    Message.Payload = Payload;
    EventSubsystem->PublishEvent(Message);
}

TArray<FJMObjectiveFlowSaveData> UJMObjectiveFlowSubsystem::CaptureObjectiveFlowStates() const
{
    TArray<FJMObjectiveFlowSaveData> Result;
    if (!ObjectiveSubsystem)
    {
        return Result;
    }
    for (const TPair<FGameplayTag, FJMObjectiveFlowRuntimeState>& Pair : FlowStates)
    {
        const FJMObjectiveFlowRuntimeState& State = Pair.Value;
        if (!IsValid(State.Definition))
        {
            continue;
        }
        FJMObjectiveFlowSaveData& Data = Result.AddDefaulted_GetRef();
        Data.FlowId = State.FlowId;
        Data.Definition = State.Definition;
        Data.State = State.State;
        Data.CurrentStepIndex = State.CurrentStepIndex;
        Data.CurrentObjectiveId = State.CurrentObjectiveId;
        Data.StartTime = State.StartTime;
        Data.CompletionTime = State.CompletionTime;
        Data.FailureTime = State.FailureTime;
        for (const UJMObjectiveDefinition* Definition : State.Definition->ObjectiveDefinitions)
        {
            FJMObjectiveRuntimeState ObjectiveState;
            if (IsValid(Definition) && ObjectiveSubsystem->GetObjectiveState(Definition->ObjectiveId, ObjectiveState))
            {
                FJMObjectiveSaveData& ObjectiveData = Data.ObjectiveStates.AddDefaulted_GetRef();
                ObjectiveData.ObjectiveId = ObjectiveState.ObjectiveId;
                ObjectiveData.State = ObjectiveState.State;
                ObjectiveData.CurrentCount = ObjectiveState.CurrentCount;
                ObjectiveData.ActivationTime = ObjectiveState.ActivationTime;
                ObjectiveData.CompletionTime = ObjectiveState.CompletionTime;
                ObjectiveData.FailureTime = ObjectiveState.FailureTime;
            }
        }
    }
    return Result;
}

bool UJMObjectiveFlowSubsystem::RestoreObjectiveFlowStates(const TArray<FJMObjectiveFlowSaveData>& SavedStates)
{
    if (!ObjectiveSubsystem)
    {
        return false;
    }
    bool bAllRestored = true;
    for (const FJMObjectiveFlowSaveData& Data : SavedStates)
    {
        UJMObjectiveFlowDefinition* Definition = Data.Definition.Get();
        if (!Definition)
        {
            Definition = Data.Definition.LoadSynchronous();
        }
        FText Error;
        if (!IsValid(Definition) || Definition->FlowId != Data.FlowId || !Definition->IsFlowDefinitionValid(Error) || !PrepareObjectives(Definition, true))
        {
            bAllRestored = false;
            continue;
        }
        if (!ObjectiveSubsystem->RestoreObjectiveStates(Data.ObjectiveStates))
        {
            bAllRestored = false;
            continue;
        }
        FJMObjectiveFlowRuntimeState& RuntimeState = FlowStates.FindOrAdd(Data.FlowId);
        RuntimeState.FlowId = Data.FlowId;
        RuntimeState.Definition = Definition;
        RuntimeState.State = Data.State;
        RuntimeState.CurrentStepIndex = Data.CurrentStepIndex;
        RuntimeState.CurrentObjectiveId = Data.CurrentObjectiveId;
        RuntimeState.StartTime = Data.StartTime;
        RuntimeState.CompletionTime = Data.CompletionTime;
        RuntimeState.FailureTime = Data.FailureTime;
        if (RuntimeState.State == EJMObjectiveFlowState::Active &&
            (!Definition->ObjectiveDefinitions.IsValidIndex(RuntimeState.CurrentStepIndex) ||
             Definition->ObjectiveDefinitions[RuntimeState.CurrentStepIndex]->ObjectiveId != RuntimeState.CurrentObjectiveId))
        {
            FlowStates.Remove(Data.FlowId);
            bAllRestored = false;
        }
    }
    return bAllRestored;
}

#if WITH_DEV_AUTOMATION_TESTS
void UJMObjectiveFlowSubsystem::SetSubsystemsForTesting(UJMObjectiveSubsystem* InObjectives, UJMGameplayEventSubsystem* InEvents)
{
    UnbindObjectiveDelegates();
    ObjectiveSubsystem = InObjectives;
    EventSubsystem = InEvents;
    BindObjectiveDelegates();
}
#endif
