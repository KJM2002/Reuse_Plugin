#pragma once

#include "CoreMinimal.h"
#include "Components/JMHideMechanismComponent.h"
#include "Door/JMDoorTypes.h"
#include "JMHideDoorMechanismComponent.generated.h"

class UJMDoorComponent;

UCLASS(ClassGroup=(JMHide), meta=(BlueprintSpawnableComponent), BlueprintType)
class JMHIDEDOORINTEGRATION_API UJMHideDoorMechanismComponent final : public UJMHideMechanismComponent
{
    GENERATED_BODY()

public:
    UJMHideDoorMechanismComponent();

    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual bool CanStartOperation(EJMHideOperation Operation, const FJMHideOperationContext& Context,
        EJMHideFailureCode& OutFailure) const override;
    virtual bool StartOperation(const FGuid& SessionId, EJMHideOperation Operation,
        const FJMHideOperationContext& Context) override;
    virtual void CancelOperation(const FGuid& SessionId) override;
    virtual void Restore(const FGuid& SessionId) override;
    virtual void GetOwnedSceneComponents(TArray<USceneComponent*>& OutComponents) const override;

private:
    UFUNCTION()
    void HandleDoorStateChanged(EJMDoorState OldState, EJMDoorState NewState);

    UJMDoorComponent* ResolveDoor() const;
    void Finish(bool bSucceeded, EJMHideFailureCode Failure = EJMHideFailureCode::None);

    FGuid ActiveSessionId;
    EJMHideOperation ActiveOperation = EJMHideOperation::None;
    FJMDoorUseContext ActiveDoorContext;
};
