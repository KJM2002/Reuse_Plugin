#pragma once

#include "Components/JMHideMechanismComponent.h"
#include "Components/JMHideParticipantDriverComponent.h"
#include "JMHideTestDoubles.generated.h"

UCLASS()
class UJMHideTestDriverComponent final : public UJMHideParticipantDriverComponent
{
    GENERATED_BODY()

public:
    bool bFailCapture = false;
    bool bFailPrepare = false;
    bool bCanFit = true;
    EJMHideOperation HoldOperation = EJMHideOperation::None;
    EJMHideOperation FailOperation = EJMHideOperation::None;
    int32 RestoreCount = 0;
    int32 HiddenApplyCount = 0;

    virtual bool SupportsParticipant(AActor* Participant) const override { return IsValid(Participant); }
    virtual FJMHideResult CaptureState(FJMHideParticipantSnapshot& OutSnapshot) override;
    virtual FJMHideResult PrepareForHide(const FGuid&, const FJMHideOperationContext&,
        FJMHideParticipantSnapshot& InOutSnapshot) override;
    virtual bool StartOperation(const FGuid& SessionId, EJMHideOperation Operation,
        const FJMHideOperationContext&) override;
    virtual void ApplyHiddenState(const FGuid&, const FJMHideOperationContext&) override { ++HiddenApplyCount; }
    virtual void RestoreState(const FGuid&, const FJMHideParticipantSnapshot&) override { ++RestoreCount; }
    virtual bool CanOccupyTransform(const FTransform&) const override { return bCanFit; }

    void Emit(const FGuid& SessionId, EJMHideOperation Operation, bool bSucceeded);
};

UCLASS()
class UJMHideTestMechanismComponent final : public UJMHideMechanismComponent
{
    GENERATED_BODY()

public:
    EJMHideOperation HoldOperation = EJMHideOperation::None;
    EJMHideOperation FailOperation = EJMHideOperation::None;
    int32 RestoreCount = 0;
    int32 CancelCount = 0;

    virtual bool StartOperation(const FGuid& SessionId, EJMHideOperation Operation,
        const FJMHideOperationContext&) override;
    virtual void CancelOperation(const FGuid&) override { ++CancelCount; }
    virtual void Restore(const FGuid&) override { ++RestoreCount; }

    void Emit(const FGuid& SessionId, EJMHideOperation Operation, bool bSucceeded);
};
