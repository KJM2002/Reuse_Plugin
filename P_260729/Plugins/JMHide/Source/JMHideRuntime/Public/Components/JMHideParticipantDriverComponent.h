#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Types/JMHideTypes.h"
#include "JMHideParticipantDriverComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FJMHideOperationCompletedNative, const FJMHideOperationCompletion&);

/**
 * Player-side capability boundary. Implementations must complete every accepted
 * operation exactly once through CompleteOperation.
 */
UCLASS(Abstract, Blueprintable, ClassGroup=(JMHide), meta=(BlueprintSpawnableComponent))
class JMHIDERUNTIME_API UJMHideParticipantDriverComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UJMHideParticipantDriverComponent();

    virtual bool SupportsParticipant(AActor* Participant) const;
    virtual FJMHideResult CaptureState(FJMHideParticipantSnapshot& OutSnapshot);
    virtual FJMHideResult PrepareForHide(const FGuid& SessionId, const FJMHideOperationContext& Context,
        FJMHideParticipantSnapshot& InOutSnapshot);
    virtual bool StartOperation(const FGuid& SessionId, EJMHideOperation Operation, const FJMHideOperationContext& Context);
    virtual void CancelOperation(const FGuid& SessionId);
    virtual void ApplyHiddenState(const FGuid& SessionId, const FJMHideOperationContext& Context);
    virtual void RestoreState(const FGuid& SessionId, const FJMHideParticipantSnapshot& Snapshot);
    virtual bool CanOccupyTransform(const FTransform& Transform) const;
    virtual FTransform GetViewTransform() const;

    FJMHideOperationCompletedNative OnOperationCompleted;

protected:
    void CompleteOperation(const FGuid& SessionId, EJMHideOperation Operation, bool bSucceeded,
        EJMHideFailureCode FailureCode = EJMHideFailureCode::None);
};
