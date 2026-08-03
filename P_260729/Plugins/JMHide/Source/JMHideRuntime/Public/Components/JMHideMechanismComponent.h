#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Types/JMHideTypes.h"
#include "Components/JMHideParticipantDriverComponent.h"
#include "JMHideMechanismComponent.generated.h"

/** Spot-side presentation boundary. It never changes Session or occupancy state. */
UCLASS(Abstract, Blueprintable, ClassGroup=(JMHide), meta=(BlueprintSpawnableComponent))
class JMHIDERUNTIME_API UJMHideMechanismComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UJMHideMechanismComponent();

    virtual bool CanStartOperation(EJMHideOperation Operation, const FJMHideOperationContext& Context,
        EJMHideFailureCode& OutFailure) const;
    virtual bool StartOperation(const FGuid& SessionId, EJMHideOperation Operation, const FJMHideOperationContext& Context);
    virtual void CancelOperation(const FGuid& SessionId);
    virtual void Restore(const FGuid& SessionId);
    virtual void GetOwnedSceneComponents(TArray<USceneComponent*>& OutComponents) const;

    FJMHideOperationCompletedNative OnOperationCompleted;

protected:
    void CompleteOperation(const FGuid& SessionId, EJMHideOperation Operation, bool bSucceeded,
        EJMHideFailureCode FailureCode = EJMHideFailureCode::None);
};
