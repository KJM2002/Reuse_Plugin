#include "Subsystems/JMObjectiveSubsystem.h"

#include "Data/JMObjectiveDefinition.h"
#include "Engine/GameInstance.h"
#include "JMObjective.h"
#include "Payloads/JMGameplayEventPayloadBase.h"
#include "Runtime/JMObjectiveEventPayload.h"
#include "Runtime/JMObjectiveEventTags.h"
#include "Settings/JMObjectiveSettings.h"
#include "Subsystems/JMGameplayEventSubsystem.h"

void UJMObjectiveSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    Collection.InitializeDependency<UJMGameplayEventSubsystem>();
    CachedEventSubsystem = GetGameInstance() ? GetGameInstance()->GetSubsystem<UJMGameplayEventSubsystem>() : nullptr;
}

void UJMObjectiveSubsystem::Deinitialize()
{
    if (CachedEventSubsystem)
    {
        CachedEventSubsystem->UnsubscribeAll(this);
    }
    SubscriptionHandles.Reset();
    ObjectiveStates.Reset();
    CachedEventSubsystem = nullptr;
    Super::Deinitialize();
}

bool UJMObjectiveSubsystem::RegisterObjective(UJMObjectiveDefinition* Definition)
{
    return RegisterObjectiveInternal(Definition, true);
}

bool UJMObjectiveSubsystem::RegisterObjectiveInactive(UJMObjectiveDefinition* Definition)
{
    return RegisterObjectiveInternal(Definition, false);
}

bool UJMObjectiveSubsystem::RegisterObjectiveInternal(UJMObjectiveDefinition* Definition, bool bHonorAutoActivate)
{
    if (!IsValid(Definition) || !Definition->ObjectiveId.IsValid() || !Definition->ListeningEventTag.IsValid() || Definition->RequiredCount < 1)
    {
        UE_LOG(LogJMObjective, Warning, TEXT("RegisterObjective rejected an invalid definition."));
        return false;
    }
    if (ObjectiveStates.Contains(Definition->ObjectiveId))
    {
        if (const UJMObjectiveSettings* Settings = GetDefault<UJMObjectiveSettings>(); Settings && Settings->bWarnDuplicateObjectiveId)
        {
            UE_LOG(LogJMObjective, Warning, TEXT("Duplicate Objective ID rejected: %s"), *Definition->ObjectiveId.ToString());
        }
        return false;
    }

    FJMObjectiveRuntimeState& RuntimeState = ObjectiveStates.Add(Definition->ObjectiveId);
    RuntimeState.ObjectiveId = Definition->ObjectiveId;
    RuntimeState.Definition = Definition;
    RuntimeState.RequiredCount = FMath::Max(1, Definition->RequiredCount);

    const UJMObjectiveSettings* Settings = GetDefault<UJMObjectiveSettings>();
    if (ShouldLog() && Settings->bLogObjectiveRegistration)
    {
        UE_LOG(LogJMObjective, Log, TEXT("[JMObjective] Registered: %s State: Inactive Required: %d"), *Definition->ObjectiveId.ToString(), RuntimeState.RequiredCount);
    }
    const FJMObjectiveRuntimeState RegisteredState = RuntimeState;
    OnObjectiveRegistered.Broadcast(RegisteredState.ObjectiveId, RegisteredState);
    PublishObjectiveEvent(JMObjectiveEventTags::Registered, RegisteredState, 0, nullptr);
    if (!bHonorAutoActivate || !Definition->bAutoActivate)
    {
        return true;
    }
    const FJMObjectiveRuntimeState* CurrentState = ObjectiveStates.Find(Definition->ObjectiveId);
    return !CurrentState || CurrentState->Definition != Definition
        ? true
        : ActivateObjective(Definition->ObjectiveId);
}

bool UJMObjectiveSubsystem::UnregisterObjective(FGameplayTag ObjectiveId)
{
    FJMObjectiveRuntimeState* RuntimeState = ObjectiveStates.Find(ObjectiveId);
    if (!RuntimeState)
    {
        return false;
    }
    UnsubscribeObjective(ObjectiveId);
    const FJMObjectiveRuntimeState RemovedState = *RuntimeState;
    ObjectiveStates.Remove(ObjectiveId);
    OnObjectiveRemoved.Broadcast(ObjectiveId, RemovedState);
    PublishObjectiveEvent(JMObjectiveEventTags::Removed, RemovedState, 0, nullptr);
    return true;
}

bool UJMObjectiveSubsystem::ActivateObjective(FGameplayTag ObjectiveId)
{
    FJMObjectiveRuntimeState* RuntimeState = ObjectiveStates.Find(ObjectiveId);
    if (!RuntimeState || RuntimeState->State != EJMObjectiveState::Inactive || !IsValid(RuntimeState->Definition))
    {
        return false;
    }
    RuntimeState->State = EJMObjectiveState::Active;
    RuntimeState->ActivationTime = FDateTime::UtcNow();
    if (!SubscribeObjective(ObjectiveId))
    {
        RuntimeState->State = EJMObjectiveState::Inactive;
        RuntimeState->ActivationTime = FDateTime();
        UE_LOG(LogJMObjective, Warning, TEXT("Activation failed because JMGameplayEvent is unavailable: %s"), *ObjectiveId.ToString());
        return false;
    }
    if (ShouldLog() && GetDefault<UJMObjectiveSettings>()->bLogStateChanges)
    {
        UE_LOG(LogJMObjective, Log, TEXT("[JMObjective] Activated: %s Listening: %s"), *ObjectiveId.ToString(), *RuntimeState->Definition->ListeningEventTag.ToString());
    }
    const FJMObjectiveRuntimeState ActivatedState = *RuntimeState;
    OnObjectiveActivated.Broadcast(ObjectiveId, ActivatedState);
    PublishObjectiveEvent(JMObjectiveEventTags::Activated, ActivatedState, 0, nullptr);
    return true;
}

bool UJMObjectiveSubsystem::DeactivateObjective(FGameplayTag ObjectiveId)
{
    FJMObjectiveRuntimeState* RuntimeState = ObjectiveStates.Find(ObjectiveId);
    if (!RuntimeState || RuntimeState->State != EJMObjectiveState::Active)
    {
        return false;
    }
    UnsubscribeObjective(ObjectiveId);
    RuntimeState->State = EJMObjectiveState::Inactive;
    const FJMObjectiveRuntimeState DeactivatedState = *RuntimeState;
    OnObjectiveDeactivated.Broadcast(ObjectiveId, DeactivatedState);
    PublishObjectiveEvent(JMObjectiveEventTags::Deactivated, DeactivatedState, 0, nullptr);
    return true;
}

bool UJMObjectiveSubsystem::CompleteObjective(FGameplayTag ObjectiveId)
{
    FJMObjectiveRuntimeState* RuntimeState = ObjectiveStates.Find(ObjectiveId);
    if (!RuntimeState || RuntimeState->State != EJMObjectiveState::Active)
    {
        return false;
    }
    UnsubscribeObjective(ObjectiveId);
    RuntimeState->CurrentCount = RuntimeState->RequiredCount;
    RuntimeState->State = EJMObjectiveState::Completed;
    RuntimeState->CompletionTime = FDateTime::UtcNow();
    if (ShouldLog() && GetDefault<UJMObjectiveSettings>()->bLogStateChanges)
    {
        UE_LOG(LogJMObjective, Log, TEXT("[JMObjective] Completed: %s"), *ObjectiveId.ToString());
    }
    const FJMObjectiveRuntimeState CompletedState = *RuntimeState;
    OnObjectiveCompleted.Broadcast(ObjectiveId, CompletedState);
    PublishObjectiveEvent(JMObjectiveEventTags::Completed, CompletedState, 0, nullptr);
    return true;
}

bool UJMObjectiveSubsystem::FailObjective(FGameplayTag ObjectiveId)
{
    FJMObjectiveRuntimeState* RuntimeState = ObjectiveStates.Find(ObjectiveId);
    if (!RuntimeState || RuntimeState->State != EJMObjectiveState::Active || !IsValid(RuntimeState->Definition) || !RuntimeState->Definition->bCanFail)
    {
        return false;
    }
    UnsubscribeObjective(ObjectiveId);
    RuntimeState->State = EJMObjectiveState::Failed;
    RuntimeState->FailureTime = FDateTime::UtcNow();
    const FJMObjectiveRuntimeState FailedState = *RuntimeState;
    OnObjectiveFailed.Broadcast(ObjectiveId, FailedState);
    PublishObjectiveEvent(JMObjectiveEventTags::Failed, FailedState, 0, nullptr);
    return true;
}

bool UJMObjectiveSubsystem::ResetObjective(FGameplayTag ObjectiveId)
{
    FJMObjectiveRuntimeState* RuntimeState = ObjectiveStates.Find(ObjectiveId);
    if (!RuntimeState)
    {
        return false;
    }
    UnsubscribeObjective(ObjectiveId);
    RuntimeState->State = EJMObjectiveState::Inactive;
    RuntimeState->CurrentCount = 0;
    RuntimeState->ActivationTime = FDateTime();
    RuntimeState->CompletionTime = FDateTime();
    RuntimeState->FailureTime = FDateTime();
    RuntimeState->LastEventTag = FGameplayTag();
    RuntimeState->LastTargetIdentifier = NAME_None;
    const FJMObjectiveRuntimeState ResetState = *RuntimeState;
    OnObjectiveReset.Broadcast(ObjectiveId, ResetState);
    PublishObjectiveEvent(JMObjectiveEventTags::Reset, ResetState, 0, nullptr);
    return true;
}

bool UJMObjectiveSubsystem::AddObjectiveProgress(FGameplayTag ObjectiveId, int32 Amount)
{
    return ApplyProgress(ObjectiveId, Amount, nullptr, NAME_None);
}

bool UJMObjectiveSubsystem::GetObjectiveState(FGameplayTag ObjectiveId, FJMObjectiveRuntimeState& OutState) const
{
    const FJMObjectiveRuntimeState* RuntimeState = ObjectiveStates.Find(ObjectiveId);
    if (!RuntimeState)
    {
        return false;
    }
    OutState = *RuntimeState;
    return true;
}

bool UJMObjectiveSubsystem::GetObjectiveProgress(FGameplayTag ObjectiveId, int32& OutCurrentCount, int32& OutRequiredCount) const
{
    const FJMObjectiveRuntimeState* RuntimeState = ObjectiveStates.Find(ObjectiveId);
    if (!RuntimeState)
    {
        OutCurrentCount = 0;
        OutRequiredCount = 0;
        return false;
    }
    OutCurrentCount = RuntimeState->CurrentCount;
    OutRequiredCount = RuntimeState->RequiredCount;
    return true;
}

TArray<FJMObjectiveRuntimeState> UJMObjectiveSubsystem::GetActiveObjectives() const
{
    TArray<FJMObjectiveRuntimeState> Result;
    for (const TPair<FGameplayTag, FJMObjectiveRuntimeState>& Pair : ObjectiveStates)
    {
        if (Pair.Value.State == EJMObjectiveState::Active) Result.Add(Pair.Value);
    }
    return Result;
}

TArray<FJMObjectiveRuntimeState> UJMObjectiveSubsystem::GetCompletedObjectives() const
{
    TArray<FJMObjectiveRuntimeState> Result;
    for (const TPair<FGameplayTag, FJMObjectiveRuntimeState>& Pair : ObjectiveStates)
    {
        if (Pair.Value.State == EJMObjectiveState::Completed) Result.Add(Pair.Value);
    }
    return Result;
}

bool UJMObjectiveSubsystem::IsObjectiveActive(FGameplayTag ObjectiveId) const
{
    const FJMObjectiveRuntimeState* State = ObjectiveStates.Find(ObjectiveId);
    return State && State->State == EJMObjectiveState::Active;
}

bool UJMObjectiveSubsystem::IsObjectiveCompleted(FGameplayTag ObjectiveId) const
{
    const FJMObjectiveRuntimeState* State = ObjectiveStates.Find(ObjectiveId);
    return State && State->State == EJMObjectiveState::Completed;
}

TArray<FJMObjectiveSaveData> UJMObjectiveSubsystem::CaptureObjectiveStates() const
{
    TArray<FJMObjectiveSaveData> Result;
    Result.Reserve(ObjectiveStates.Num());
    for (const TPair<FGameplayTag, FJMObjectiveRuntimeState>& Pair : ObjectiveStates)
    {
        FJMObjectiveSaveData& Data = Result.AddDefaulted_GetRef();
        Data.ObjectiveId = Pair.Key;
        Data.State = Pair.Value.State;
        Data.CurrentCount = Pair.Value.CurrentCount;
        Data.ActivationTime = Pair.Value.ActivationTime;
        Data.CompletionTime = Pair.Value.CompletionTime;
        Data.FailureTime = Pair.Value.FailureTime;
    }
    return Result;
}

bool UJMObjectiveSubsystem::RestoreObjectiveStates(const TArray<FJMObjectiveSaveData>& SavedStates)
{
    bool bAllRestored = true;
    for (const FJMObjectiveSaveData& Data : SavedStates)
    {
        FJMObjectiveRuntimeState* RuntimeState = ObjectiveStates.Find(Data.ObjectiveId);
        if (!RuntimeState)
        {
            bAllRestored = false;
            continue;
        }
        UnsubscribeObjective(Data.ObjectiveId);
        RuntimeState->CurrentCount = FMath::Clamp(Data.CurrentCount, 0, RuntimeState->RequiredCount);
        RuntimeState->State = Data.State;
        RuntimeState->ActivationTime = Data.ActivationTime;
        RuntimeState->CompletionTime = Data.CompletionTime;
        RuntimeState->FailureTime = Data.FailureTime;
        if (RuntimeState->State == EJMObjectiveState::Active && !SubscribeObjective(Data.ObjectiveId))
        {
            RuntimeState->State = EJMObjectiveState::Inactive;
            bAllRestored = false;
        }
    }
    return bAllRestored;
}

UJMGameplayEventSubsystem* UJMObjectiveSubsystem::ResolveEventSubsystem()
{
    if (!CachedEventSubsystem && GetGameInstance())
    {
        CachedEventSubsystem = GetGameInstance()->GetSubsystem<UJMGameplayEventSubsystem>();
    }
    return CachedEventSubsystem;
}

bool UJMObjectiveSubsystem::SubscribeObjective(FGameplayTag ObjectiveId)
{
    if (SubscriptionHandles.Contains(ObjectiveId))
    {
        return true;
    }
    const FJMObjectiveRuntimeState* RuntimeState = ObjectiveStates.Find(ObjectiveId);
    UJMGameplayEventSubsystem* EventSubsystem = ResolveEventSubsystem();
    if (!RuntimeState || !IsValid(RuntimeState->Definition) || !EventSubsystem)
    {
        return false;
    }
    FJMGameplayEventNativeDelegate Delegate = FJMGameplayEventNativeDelegate::CreateUObject(this, &UJMObjectiveSubsystem::HandleGameplayEvent, ObjectiveId);
    FJMGameplayEventSubscriptionHandle Handle = EventSubsystem->SubscribeEvent(RuntimeState->Definition->ListeningEventTag, this, RuntimeState->Definition->EventMatchType, MoveTemp(Delegate));
    if (!Handle.IsValid())
    {
        return false;
    }
    SubscriptionHandles.Add(ObjectiveId, Handle);
    return true;
}

void UJMObjectiveSubsystem::UnsubscribeObjective(FGameplayTag ObjectiveId)
{
    if (FJMGameplayEventSubscriptionHandle* Handle = SubscriptionHandles.Find(ObjectiveId))
    {
        if (UJMGameplayEventSubsystem* EventSubsystem = ResolveEventSubsystem())
        {
            EventSubsystem->UnsubscribeEvent(*Handle);
        }
        SubscriptionHandles.Remove(ObjectiveId);
    }
}

void UJMObjectiveSubsystem::HandleGameplayEvent(const FJMGameplayEventMessage& Message, FGameplayTag ObjectiveId)
{
    FJMObjectiveRuntimeState* RuntimeState = ObjectiveStates.Find(ObjectiveId);
    if (!RuntimeState || RuntimeState->State != EJMObjectiveState::Active || !IsValid(RuntimeState->Definition))
    {
        return;
    }
    FName ReceivedTarget;
    FString FailureReason;
    if (!DoesEventPassFilters(*RuntimeState, Message, ReceivedTarget, FailureReason))
    {
        if (ShouldLog() && GetDefault<UJMObjectiveSettings>()->bLogEventFiltering)
        {
            UE_LOG(LogJMObjective, Log, TEXT("[JMObjective] Ignored %s Objective: %s Reason: %s Expected: %s Received: %s"),
                *Message.EventTag.ToString(), *ObjectiveId.ToString(), *FailureReason,
                *RuntimeState->Definition->RequiredTargetIdentifier.ToString(), *ReceivedTarget.ToString());
        }
        return;
    }
    int32 Amount = RuntimeState->Definition->FixedProgressAmount;
    if (RuntimeState->Definition->ProgressIncrementMode == EJMObjectiveProgressIncrementMode::PayloadAmount)
    {
        const UJMGameplayEventPayloadBase* Payload = Cast<UJMGameplayEventPayloadBase>(Message.Payload);
        Amount = Payload ? Payload->ObjectiveProgressAmount : 0;
    }
    ApplyProgress(ObjectiveId, Amount, &Message, ReceivedTarget);
}

bool UJMObjectiveSubsystem::DoesEventPassFilters(const FJMObjectiveRuntimeState& RuntimeState, const FJMGameplayEventMessage& Message, FName& OutReceivedTarget, FString& OutFailureReason) const
{
    const UJMObjectiveDefinition* Definition = RuntimeState.Definition;
    if (!Definition)
    {
        OutFailureReason = TEXT("Definition unavailable");
        return false;
    }
    const bool bTagMatches = Definition->EventMatchType == EJMGameplayEventMatchType::Exact
        ? Message.EventTag == Definition->ListeningEventTag
        : Message.EventTag.MatchesTag(Definition->ListeningEventTag);
    if (!bTagMatches)
    {
        OutFailureReason = TEXT("Event tag mismatch");
        return false;
    }

    FGameplayTagContainer CombinedContext = Message.ContextTags;
    if (const UJMGameplayEventPayloadBase* Payload = Cast<UJMGameplayEventPayloadBase>(Message.Payload))
    {
        OutReceivedTarget = Payload->ObjectiveTargetIdentifier;
        CombinedContext.AppendTags(Payload->ObjectiveContextTags);
    }
    if (!CombinedContext.HasAll(Definition->RequiredContextTags))
    {
        OutFailureReason = TEXT("Required context tags missing");
        return false;
    }
    if (CombinedContext.HasAny(Definition->BlockedContextTags))
    {
        OutFailureReason = TEXT("Blocked context tag present");
        return false;
    }
    if (!Definition->RequiredTargetIdentifier.IsNone() && Definition->RequiredTargetIdentifier != OutReceivedTarget)
    {
        OutFailureReason = TEXT("Target identifier mismatch");
        return false;
    }
    return true;
}

bool UJMObjectiveSubsystem::ApplyProgress(FGameplayTag ObjectiveId, int32 Amount, const FJMGameplayEventMessage* SourceMessage, FName ReceivedTarget)
{
    FJMObjectiveRuntimeState* RuntimeState = ObjectiveStates.Find(ObjectiveId);
    if (!RuntimeState || RuntimeState->State != EJMObjectiveState::Active || Amount <= 0)
    {
        return false;
    }
    const int32 OldCount = RuntimeState->CurrentCount;
    RuntimeState->CurrentCount = FMath::Clamp(OldCount + Amount, 0, RuntimeState->RequiredCount);
    const int32 AppliedDelta = RuntimeState->CurrentCount - OldCount;
    if (AppliedDelta <= 0)
    {
        return false;
    }
    RuntimeState->LastEventTag = SourceMessage ? SourceMessage->EventTag : FGameplayTag();
    RuntimeState->LastTargetIdentifier = ReceivedTarget;
    if (ShouldLog() && GetDefault<UJMObjectiveSettings>()->bLogProgressChanges)
    {
        UE_LOG(LogJMObjective, Log, TEXT("[JMObjective] Progressed: %s %d -> %d / %d"), *ObjectiveId.ToString(), OldCount, RuntimeState->CurrentCount, RuntimeState->RequiredCount);
    }
    const FJMObjectiveRuntimeState ProgressedState = *RuntimeState;
    OnObjectiveProgressed.Broadcast(ObjectiveId, ProgressedState, AppliedDelta);
    PublishObjectiveEvent(JMObjectiveEventTags::Progressed, ProgressedState, AppliedDelta, SourceMessage);

    RuntimeState = ObjectiveStates.Find(ObjectiveId);
    if (RuntimeState
        && RuntimeState->State == EJMObjectiveState::Active
        && RuntimeState->Definition == ProgressedState.Definition
        && RuntimeState->ActivationTime == ProgressedState.ActivationTime
        && RuntimeState->CurrentCount == ProgressedState.CurrentCount
        && RuntimeState->CurrentCount >= RuntimeState->RequiredCount)
    {
        UnsubscribeObjective(ObjectiveId);
        RuntimeState->State = EJMObjectiveState::Completed;
        RuntimeState->CompletionTime = FDateTime::UtcNow();
        const FJMObjectiveRuntimeState CompletedState = *RuntimeState;
        OnObjectiveCompleted.Broadcast(ObjectiveId, CompletedState);
        PublishObjectiveEvent(JMObjectiveEventTags::Completed, CompletedState, 0, SourceMessage);
    }
    return true;
}

void UJMObjectiveSubsystem::PublishObjectiveEvent(FGameplayTag EventTag, const FJMObjectiveRuntimeState& RuntimeState, int32 ProgressDelta, const FJMGameplayEventMessage* SourceMessage)
{
    UJMGameplayEventSubsystem* EventSubsystem = ResolveEventSubsystem();
    if (!EventSubsystem || !EventTag.IsValid())
    {
        return;
    }
    UJMObjectiveEventPayload* Payload = NewObject<UJMObjectiveEventPayload>(this);
    Payload->ObjectiveId = RuntimeState.ObjectiveId;
    Payload->State = RuntimeState.State;
    Payload->CurrentCount = RuntimeState.CurrentCount;
    Payload->RequiredCount = RuntimeState.RequiredCount;
    Payload->ProgressDelta = ProgressDelta;
    Payload->ObjectiveTargetIdentifier = RuntimeState.ObjectiveId.GetTagName();
    Payload->ObjectiveProgressAmount = ProgressDelta;
    FJMGameplayEventMessage Message;
    Message.EventTag = EventTag;
    Message.Source = this;
    Message.Instigator = SourceMessage ? SourceMessage->Instigator : nullptr;
    Message.Target = SourceMessage ? SourceMessage->Target : RuntimeState.Definition.Get();
    Message.Payload = Payload;
    EventSubsystem->PublishEvent(Message);
}

bool UJMObjectiveSubsystem::ShouldLog() const
{
#if UE_BUILD_SHIPPING
    return false;
#else
    const UJMObjectiveSettings* Settings = GetDefault<UJMObjectiveSettings>();
    return Settings && Settings->bEnableDebugLogging;
#endif
}

#if WITH_DEV_AUTOMATION_TESTS
void UJMObjectiveSubsystem::SetGameplayEventSubsystemForTesting(UJMGameplayEventSubsystem* InSubsystem)
{
    CachedEventSubsystem = InSubsystem;
}
#endif
