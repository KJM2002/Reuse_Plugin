#include "Components/JMHideParticipantDriverComponent.h"

UJMHideParticipantDriverComponent::UJMHideParticipantDriverComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

bool UJMHideParticipantDriverComponent::SupportsParticipant(AActor* Participant) const
{
    return false;
}

FJMHideResult UJMHideParticipantDriverComponent::CaptureState(FJMHideParticipantSnapshot& OutSnapshot)
{
    return FJMHideResult::Failure(EJMHideFailureCode::UnsupportedParticipant);
}

FJMHideResult UJMHideParticipantDriverComponent::PrepareForHide(const FGuid& SessionId,
    const FJMHideOperationContext& Context, FJMHideParticipantSnapshot& InOutSnapshot)
{
    return FJMHideResult::Failure(EJMHideFailureCode::UnsupportedParticipant);
}

bool UJMHideParticipantDriverComponent::StartOperation(const FGuid& SessionId, EJMHideOperation Operation,
    const FJMHideOperationContext& Context)
{
    return false;
}

void UJMHideParticipantDriverComponent::CancelOperation(const FGuid& SessionId)
{
}

void UJMHideParticipantDriverComponent::ApplyHiddenState(const FGuid& SessionId, const FJMHideOperationContext& Context)
{
}

void UJMHideParticipantDriverComponent::RestoreState(const FGuid& SessionId, const FJMHideParticipantSnapshot& Snapshot)
{
}

bool UJMHideParticipantDriverComponent::CanOccupyTransform(const FTransform& Transform) const
{
    return false;
}

FTransform UJMHideParticipantDriverComponent::GetViewTransform() const
{
    return GetOwner() ? GetOwner()->GetActorTransform() : FTransform::Identity;
}

void UJMHideParticipantDriverComponent::CompleteOperation(const FGuid& SessionId, EJMHideOperation Operation,
    bool bSucceeded, EJMHideFailureCode FailureCode)
{
    FJMHideOperationCompletion Completion;
    Completion.SessionId = SessionId;
    Completion.Operation = Operation;
    Completion.bSucceeded = bSucceeded;
    Completion.FailureCode = bSucceeded ? EJMHideFailureCode::None : FailureCode;
    OnOperationCompleted.Broadcast(Completion);
}
