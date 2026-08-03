#include "Tests/JMHideTestDoubles.h"

FJMHideResult UJMHideTestDriverComponent::CaptureState(FJMHideParticipantSnapshot& OutSnapshot)
{
    if (bFailCapture)
    {
        return FJMHideResult::Failure(EJMHideFailureCode::OperationFailed);
    }
    OutSnapshot.bCaptured = true;
    return FJMHideResult::Success();
}

FJMHideResult UJMHideTestDriverComponent::PrepareForHide(const FGuid&, const FJMHideOperationContext&,
    FJMHideParticipantSnapshot& InOutSnapshot)
{
    if (bFailPrepare)
    {
        return FJMHideResult::Failure(EJMHideFailureCode::OperationFailed);
    }
    InOutSnapshot.bChangedMovement = true;
    return FJMHideResult::Success();
}

bool UJMHideTestDriverComponent::StartOperation(const FGuid& SessionId, EJMHideOperation Operation,
    const FJMHideOperationContext&)
{
    if (Operation == HoldOperation)
    {
        return true;
    }
    CompleteOperation(SessionId, Operation, Operation != FailOperation,
        Operation == FailOperation ? EJMHideFailureCode::OperationFailed : EJMHideFailureCode::None);
    return true;
}

void UJMHideTestDriverComponent::Emit(const FGuid& SessionId, EJMHideOperation Operation, bool bSucceeded)
{
    CompleteOperation(SessionId, Operation, bSucceeded,
        bSucceeded ? EJMHideFailureCode::None : EJMHideFailureCode::OperationFailed);
}

bool UJMHideTestMechanismComponent::StartOperation(const FGuid& SessionId, EJMHideOperation Operation,
    const FJMHideOperationContext&)
{
    if (Operation == HoldOperation)
    {
        return true;
    }
    CompleteOperation(SessionId, Operation, Operation != FailOperation,
        Operation == FailOperation ? EJMHideFailureCode::OperationFailed : EJMHideFailureCode::None);
    return true;
}

void UJMHideTestMechanismComponent::Emit(const FGuid& SessionId, EJMHideOperation Operation, bool bSucceeded)
{
    CompleteOperation(SessionId, Operation, bSucceeded,
        bSucceeded ? EJMHideFailureCode::None : EJMHideFailureCode::OperationFailed);
}
