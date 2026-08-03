#include "Components/JMDoorReconTargetAdapterComponent.h"

#include "Components/JMReconInteractorComponent.h"
#include "Components/JMReconTargetComponent.h"
#include "Data/JMReconDefinition.h"
#include "Door/JMDoorComponent.h"
#include "Movement/JMDoorMovementComponent.h"
#include "Movement/JMSlidingDoorMovementComponent.h"
#include "Settings/JMDoorReconIntegrationSettings.h"

namespace
{
    FTransform RelativeFromWorld(USceneComponent* Component, const FTransform& WorldTransform)
    {
        return Component && Component->GetAttachParent()
            ? WorldTransform.GetRelativeTransform(Component->GetAttachParent()->GetComponentTransform())
            : WorldTransform;
    }
}

UJMDoorReconTargetAdapterComponent::UJMDoorReconTargetAdapterComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = false;
}

void UJMDoorReconTargetAdapterComponent::BeginPlay()
{
    Super::BeginPlay();
    CacheComponents();
    if (DoorComponent)
    {
        DoorComponent->OnDoorStateChanged.AddUniqueDynamic(
            this, &UJMDoorReconTargetAdapterComponent::HandleDoorStateChanged);
    }
}

void UJMDoorReconTargetAdapterComponent::CacheComponents()
{
    DoorComponent = GetOwner() ? GetOwner()->FindComponentByClass<UJMDoorComponent>() : nullptr;
    ReconTarget = GetOwner() ? GetOwner()->FindComponentByClass<UJMReconTargetComponent>() : nullptr;
}

void UJMDoorReconTargetAdapterComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    BeginRestore(true);
    if (DoorComponent)
    {
        DoorComponent->OnDoorStateChanged.RemoveDynamic(
            this, &UJMDoorReconTargetAdapterComponent::HandleDoorStateChanged);
    }
    Super::EndPlay(EndPlayReason);
}

FJMReconRequestResult UJMDoorReconTargetAdapterComponent::ValidateDoorState() const
{
    UJMDoorComponent* EffectiveDoor = DoorComponent
        ? DoorComponent.Get()
        : (GetOwner() ? GetOwner()->FindComponentByClass<UJMDoorComponent>() : nullptr);
    if (!EffectiveDoor || !EffectiveDoor->MovementComponent)
    {
        return FJMReconRequestResult::Failure(EJMReconFailureReason::InvalidTarget);
    }

    switch (EffectiveDoor->GetState())
    {
    case EJMDoorState::Opening:
    case EJMDoorState::Closing:
        return FJMReconRequestResult::Failure(EJMReconFailureReason::DoorMoving);
    case EJMDoorState::Locked:
    case EJMDoorState::Blocked:
    case EJMDoorState::Jammed:
    case EJMDoorState::Broken:
        return FJMReconRequestResult::Failure(EJMReconFailureReason::Blocked);
    default:
        break;
    }

    if (EffectiveDoor->GetOpenFraction() >=
        GetDefault<UJMDoorReconIntegrationSettings>()->MaximumExistingOpenFraction)
    {
        return FJMReconRequestResult::Failure(EJMReconFailureReason::DoorOpen);
    }
    return FJMReconRequestResult::Success();
}

FJMReconRequestResult UJMDoorReconTargetAdapterComponent::CanStartRecon_Implementation(
    AActor* Interactor, const FGuid& SessionId) const
{
    return ValidateDoorState();
}

bool UJMDoorReconTargetAdapterComponent::CanEnterListen_Implementation(
    AActor* Interactor, const FGuid& SessionId) const
{
    return ValidateDoorState().bSucceeded;
}

bool UJMDoorReconTargetAdapterComponent::CanEnterPeek_Implementation(
    AActor* Interactor, const FGuid& SessionId) const
{
    return ValidateDoorState().bSucceeded;
}

void UJMDoorReconTargetAdapterComponent::BeginRecon_Implementation(
    AActor* Interactor, const FGuid& SessionId)
{
    CacheComponents();
    ActiveSessionId = SessionId;
    SessionInteractor = Interactor;
    ReconInteractor = Interactor
        ? Interactor->FindComponentByClass<UJMReconInteractorComponent>()
        : nullptr;

    UJMReconDefinition* Definition = ReconTarget ? ReconTarget->GetEffectiveDefinition() : nullptr;
    if (Definition &&
        Definition->InitialObservationMode == EJMReconInitialObservationMode::Peek)
    {
        BeginTemporaryPose(Definition->PeekOpenFraction);
    }
}

void UJMDoorReconTargetAdapterComponent::EndRecon_Implementation(
    AActor* Interactor, const FGuid& SessionId, EJMReconEndReason Reason)
{
    if (ActiveSessionId == SessionId && !bRestoring)
    {
        BeginRestore(false);
    }
    ActiveSessionId.Invalidate();
    SessionInteractor.Reset();
    ReconInteractor.Reset();
}

void UJMDoorReconTargetAdapterComponent::BeginPeekPose_Implementation(
    const FGuid& SessionId, float OpenFraction)
{
    if (ActiveSessionId == SessionId && !bPoseCaptured)
    {
        BeginTemporaryPose(OpenFraction);
    }
}

void UJMDoorReconTargetAdapterComponent::EndPeekPose_Implementation(const FGuid& SessionId)
{
    if (ActiveSessionId == SessionId && !bRestoring)
    {
        BeginRestore(false);
    }
}

int32 UJMDoorReconTargetAdapterComponent::ResolveOpenDirection() const
{
    UJMDoorMovementComponent* Movement = DoorComponent ? DoorComponent->MovementComponent : nullptr;
    USceneComponent* Moving = Movement ? Movement->GetMovingComponent() : nullptr;
    AActor* Interactor = SessionInteractor.Get();
    if (!Movement || !Moving || !Interactor)
    {
        return 1;
    }

    const float Fraction = ReconTarget && ReconTarget->GetEffectiveDefinition()
        ? ReconTarget->GetEffectiveDefinition()->PeekOpenFraction
        : 0.1f;
    const FVector Positive = Movement->GetWorldTransformAtFraction(Fraction, 1).GetLocation();
    const FVector Negative = Movement->GetWorldTransformAtFraction(Fraction, -1).GetLocation();
    return FVector::DistSquared(Positive, Interactor->GetActorLocation()) >=
           FVector::DistSquared(Negative, Interactor->GetActorLocation()) ? 1 : -1;
}

void UJMDoorReconTargetAdapterComponent::BeginTemporaryPose(float OpenFraction)
{
    CacheComponents();
    if (bPoseCaptured || !ValidateDoorState().bSucceeded)
    {
        return;
    }

    UJMDoorMovementComponent* Movement = DoorComponent->MovementComponent;
    USceneComponent* ComponentA = Movement ? Movement->GetMovingComponent() : nullptr;
    if (!ComponentA)
    {
        return;
    }

    MovingA = ComponentA;
    OriginalA = ComponentA->GetRelativeTransform();
    BlendStartA = OriginalA;
    bHasPanelB = false;

    const float DesiredFraction = FMath::Max(OpenFraction, DoorComponent->GetOpenFraction());
    if (UJMSlidingDoorMovementComponent* Sliding =
        Cast<UJMSlidingDoorMovementComponent>(Movement))
    {
        BlendTargetA = RelativeFromWorld(
            ComponentA,
            Sliding->GetPanelWorldTransformAtFraction(
                EJMSlideDoorPanel::DoorA,
                FMath::Max(DesiredFraction, DoorComponent->GetSlideDoorPanelOpenFraction(EJMSlideDoorPanel::DoorA))));
        if (Sliding->HasPanel(EJMSlideDoorPanel::DoorB) && Sliding->MovingComponentB)
        {
            MovingB = Sliding->MovingComponentB;
            OriginalB = Sliding->MovingComponentB->GetRelativeTransform();
            BlendStartB = OriginalB;
            BlendTargetB = RelativeFromWorld(
                Sliding->MovingComponentB,
                Sliding->GetPanelWorldTransformAtFraction(
                    EJMSlideDoorPanel::DoorB,
                    FMath::Max(DesiredFraction, DoorComponent->GetSlideDoorPanelOpenFraction(EJMSlideDoorPanel::DoorB))));
            bHasPanelB = true;
        }
    }
    else
    {
        BlendTargetA = Movement->GetRelativeTransformAtFraction(
            DesiredFraction, ResolveOpenDirection());
    }

    bPoseCaptured = true;
    bRestoring = false;
    BlendElapsed = 0.0f;
    BlendDuration = GetDefault<UJMDoorReconIntegrationSettings>()->OpenBlendDuration;
    SetComponentTickEnabled(true);
    if (BlendDuration <= 0.0f)
    {
        ApplyBlend(1.0f);
        FinishBlend();
    }
}

void UJMDoorReconTargetAdapterComponent::BeginRestore(bool bImmediate)
{
    if (!bPoseCaptured)
    {
        return;
    }

    if (USceneComponent* ComponentA = MovingA.Get())
    {
        BlendStartA = ComponentA->GetRelativeTransform();
    }
    if (bHasPanelB)
    {
        if (USceneComponent* ComponentB = MovingB.Get())
        {
            BlendStartB = ComponentB->GetRelativeTransform();
        }
    }
    BlendTargetA = OriginalA;
    BlendTargetB = OriginalB;
    BlendElapsed = 0.0f;
    UJMReconDefinition* Definition =
        ReconTarget ? ReconTarget->GetEffectiveDefinition() : nullptr;
    BlendDuration = bImmediate
        ? 0.0f
        : (Definition
            ? FMath::Max(0.0f, Definition->ExitingDuration)
            : GetDefault<UJMDoorReconIntegrationSettings>()->RestoreBlendDuration);
    bRestoring = true;
    SetComponentTickEnabled(true);
    if (BlendDuration <= 0.0f)
    {
        ApplyBlend(1.0f);
        FinishBlend();
    }
}

void UJMDoorReconTargetAdapterComponent::ApplyBlend(float Alpha)
{
    const float EasedAlpha = FMath::InterpEaseInOut(0.0f, 1.0f, Alpha, 2.0f);
    if (USceneComponent* ComponentA = MovingA.Get())
    {
        FTransform Transform;
        Transform.Blend(BlendStartA, BlendTargetA, EasedAlpha);
        ComponentA->SetRelativeTransform(Transform);
    }
    if (bHasPanelB)
    {
        if (USceneComponent* ComponentB = MovingB.Get())
        {
            FTransform Transform;
            Transform.Blend(BlendStartB, BlendTargetB, EasedAlpha);
            ComponentB->SetRelativeTransform(Transform);
        }
    }
}

void UJMDoorReconTargetAdapterComponent::FinishBlend()
{
    SetComponentTickEnabled(false);
    if (bRestoring)
    {
        bPoseCaptured = false;
        bRestoring = false;
        MovingA.Reset();
        MovingB.Reset();
        bHasPanelB = false;
    }
}

void UJMDoorReconTargetAdapterComponent::TickComponent(
    float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    BlendElapsed += DeltaTime;
    const float Alpha = BlendDuration > 0.0f
        ? FMath::Clamp(BlendElapsed / BlendDuration, 0.0f, 1.0f)
        : 1.0f;
    ApplyBlend(Alpha);
    if (Alpha >= 1.0f)
    {
        FinishBlend();
    }
}

void UJMDoorReconTargetAdapterComponent::HandleDoorStateChanged(
    EJMDoorState OldState, EJMDoorState NewState)
{
    if (!bPoseCaptured)
    {
        return;
    }
    BeginRestore(true);
    if (UJMReconInteractorComponent* Interactor = ReconInteractor.Get())
    {
        Interactor->CancelRecon();
    }
}
