#include "Components/JMHideMechanismComponent.h"

UJMHideMechanismComponent::UJMHideMechanismComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

bool UJMHideMechanismComponent::CanStartOperation(EJMHideOperation Operation,
    const FJMHideOperationContext& Context, EJMHideFailureCode& OutFailure) const
{
    OutFailure = EJMHideFailureCode::None;
    return true;
}

bool UJMHideMechanismComponent::StartOperation(const FGuid& SessionId, EJMHideOperation Operation,
    const FJMHideOperationContext& Context)
{
    CompleteOperation(SessionId, Operation, true);
    return true;
}

void UJMHideMechanismComponent::CancelOperation(const FGuid& SessionId)
{
}

void UJMHideMechanismComponent::Restore(const FGuid& SessionId)
{
}

void UJMHideMechanismComponent::GetOwnedSceneComponents(TArray<USceneComponent*>& OutComponents) const
{
}

void UJMHideMechanismComponent::CompleteOperation(const FGuid& SessionId, EJMHideOperation Operation,
    bool bSucceeded, EJMHideFailureCode FailureCode)
{
    FJMHideOperationCompletion Completion;
    Completion.SessionId = SessionId;
    Completion.Operation = Operation;
    Completion.bSucceeded = bSucceeded;
    Completion.FailureCode = bSucceeded ? EJMHideFailureCode::None : FailureCode;
    OnOperationCompleted.Broadcast(Completion);
}
