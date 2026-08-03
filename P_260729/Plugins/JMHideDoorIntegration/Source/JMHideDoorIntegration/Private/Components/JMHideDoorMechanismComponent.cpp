#include "Components/JMHideDoorMechanismComponent.h"

#include "Door/JMDoorComponent.h"
#include "Movement/JMDoorMovementComponent.h"

UJMHideDoorMechanismComponent::UJMHideDoorMechanismComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UJMHideDoorMechanismComponent::BeginPlay()
{
    Super::BeginPlay();
    if (UJMDoorComponent* Door = ResolveDoor())
    {
        Door->OnDoorStateChanged.AddDynamic(this, &UJMHideDoorMechanismComponent::HandleDoorStateChanged);
    }
}

void UJMHideDoorMechanismComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (UJMDoorComponent* Door = ResolveDoor())
    {
        Door->OnDoorStateChanged.RemoveDynamic(this, &UJMHideDoorMechanismComponent::HandleDoorStateChanged);
    }
    if (ActiveSessionId.IsValid())
    {
        Finish(false, EJMHideFailureCode::TargetDestroyed);
    }
    Super::EndPlay(EndPlayReason);
}

UJMDoorComponent* UJMHideDoorMechanismComponent::ResolveDoor() const
{
    return GetOwner() ? GetOwner()->FindComponentByClass<UJMDoorComponent>() : nullptr;
}

bool UJMHideDoorMechanismComponent::CanStartOperation(EJMHideOperation Operation,
    const FJMHideOperationContext& Context, EJMHideFailureCode& OutFailure) const
{
    const UJMDoorComponent* Door = ResolveDoor();
    if (!Door || Door->GetState() == EJMDoorState::Broken || Door->GetState() == EJMDoorState::Jammed)
    {
        OutFailure = EJMHideFailureCode::InvalidMechanism;
        return false;
    }
    OutFailure = EJMHideFailureCode::None;
    return true;
}

bool UJMHideDoorMechanismComponent::StartOperation(const FGuid& SessionId, EJMHideOperation Operation,
    const FJMHideOperationContext& Context)
{
    EJMHideFailureCode Failure;
    UJMDoorComponent* Door = ResolveDoor();
    if (!SessionId.IsValid() || ActiveSessionId.IsValid() || !Door ||
        !CanStartOperation(Operation, Context, Failure))
    {
        return false;
    }
    ActiveSessionId = SessionId;
    ActiveOperation = Operation;
    ActiveDoorContext = FJMDoorUseContext();
    ActiveDoorContext.InstigatorActor = Context.Participant;
    ActiveDoorContext.InteractionLocation = Context.Participant
        ? Context.Participant->GetActorLocation() : FVector::ZeroVector;

    const bool bOpen = Operation == EJMHideOperation::PrepareEnter || Operation == EJMHideOperation::PrepareExit;
    const FJMDoorResult Result = bOpen ? Door->OpenDoor(ActiveDoorContext) : Door->CloseDoor(ActiveDoorContext);
    const EJMDoorState State = Door->GetState();
    if (Result.bSucceeded || Result.Code == EJMDoorResultCode::AlreadyAtTarget)
    {
        if ((bOpen && State == EJMDoorState::Open) || (!bOpen && State == EJMDoorState::Closed))
        {
            Finish(true);
        }
        return true;
    }
    Finish(false, EJMHideFailureCode::OperationFailed);
    return true;
}

void UJMHideDoorMechanismComponent::HandleDoorStateChanged(EJMDoorState OldState, EJMDoorState NewState)
{
    if (!ActiveSessionId.IsValid())
    {
        return;
    }
    const bool bOpen = ActiveOperation == EJMHideOperation::PrepareEnter ||
        ActiveOperation == EJMHideOperation::PrepareExit;
    if ((bOpen && NewState == EJMDoorState::Open) || (!bOpen && NewState == EJMDoorState::Closed))
    {
        Finish(true);
    }
    else if (NewState == EJMDoorState::Blocked || NewState == EJMDoorState::Jammed ||
        NewState == EJMDoorState::Broken)
    {
        Finish(false, EJMHideFailureCode::OperationFailed);
    }
}

void UJMHideDoorMechanismComponent::Finish(bool bSucceeded, EJMHideFailureCode Failure)
{
    const FGuid SessionId = ActiveSessionId;
    const EJMHideOperation Operation = ActiveOperation;
    ActiveSessionId.Invalidate();
    ActiveOperation = EJMHideOperation::None;
    CompleteOperation(SessionId, Operation, bSucceeded, Failure);
}

void UJMHideDoorMechanismComponent::CancelOperation(const FGuid& SessionId)
{
    if (SessionId != ActiveSessionId)
    {
        return;
    }
    ActiveSessionId.Invalidate();
    ActiveOperation = EJMHideOperation::None;
    if (UJMDoorComponent* Door = ResolveDoor())
    {
        Door->CloseDoor(ActiveDoorContext);
    }
}

void UJMHideDoorMechanismComponent::Restore(const FGuid& SessionId)
{
    CancelOperation(SessionId);
    if (UJMDoorComponent* Door = ResolveDoor())
    {
        Door->CloseDoor(ActiveDoorContext);
    }
}

void UJMHideDoorMechanismComponent::GetOwnedSceneComponents(TArray<USceneComponent*>& OutComponents) const
{
    const UJMDoorComponent* Door = ResolveDoor();
    if (Door && Door->MovementComponent && Door->MovementComponent->GetMovingComponent())
    {
        OutComponents.AddUnique(Door->MovementComponent->GetMovingComponent());
    }
}
