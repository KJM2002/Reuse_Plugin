#include "Components/JMPhysicalGrabberComponent.h"

#include "Components/PrimitiveComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

UJMPhysicalGrabberComponent::UJMPhysicalGrabberComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.TickGroup = TG_PrePhysics;
}

void UJMPhysicalGrabberComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Release();
    Super::EndPlay(EndPlayReason);
}

void UJMPhysicalGrabberComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    const APawn* Pawn = Cast<APawn>(GetOwner());
    APlayerController* Controller = Pawn ? Cast<APlayerController>(Pawn->GetController()) : nullptr;
    if (!Controller || !Controller->IsLocalController())
    {
        return;
    }

    if (Controller->WasInputKeyJustPressed(GrabKey))
    {
        if (bToggleGrab && IsHoldingObject())
        {
            Release();
        }
        else
        {
            TryGrab();
        }
    }

    if (!bToggleGrab && Controller->WasInputKeyJustReleased(GrabKey))
    {
        Release();
    }

    ApplyGrabForce(DeltaTime);
}

bool UJMPhysicalGrabberComponent::TryGrab()
{
    UWorld* World = GetWorld();
    if (!IsValid(GetOwner()) || !World || World->bIsTearingDown || IsHoldingObject())
    {
        return false;
    }

    FVector ViewLocation;
    FVector ViewDirection;
    if (!GetPlayerView(ViewLocation, ViewDirection))
    {
        return false;
    }

    const FVector TraceEnd = ViewLocation + ViewDirection * GrabDistance;
    FCollisionQueryParams Params(SCENE_QUERY_STAT(JMPhysicalGrabberTrace), false, GetOwner());
    FHitResult Hit;
    const bool bHit = World->LineTraceSingleByChannel(Hit, ViewLocation, TraceEnd, TraceChannel, Params);

    if (bDrawDebug)
    {
        DrawDebugLine(World, ViewLocation, TraceEnd, bHit ? FColor::Green : FColor::Red, false, 1.0f, 0, 1.5f);
        if (bHit)
        {
            DrawDebugSphere(World, Hit.ImpactPoint, 8.0f, 12, FColor::Green, false, 1.0f);
        }
    }

    UPrimitiveComponent* HitComponent = Hit.GetComponent();
    if (!HitComponent || !HitComponent->IsSimulatingPhysics(Hit.BoneName))
    {
        return false;
    }

    const float Mass = HitComponent->GetMass();
    if (MaxGrabbableMass > 0.0f && Mass > MaxGrabbableMass)
    {
        return false;
    }

    GrabbedComponent = HitComponent;
    GrabbedBone = Hit.BoneName;
    LocalGrabPoint = HitComponent->GetComponentTransform().InverseTransformPosition(Hit.ImpactPoint);
    PreviousPawnResponse = HitComponent->GetCollisionResponseToChannel(ECC_Pawn);

    if (bIgnorePawnCollisionWhileHeld)
    {
        HitComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
    }

    HitComponent->WakeAllRigidBodies();
    OnGrabbed.Broadcast(HitComponent);
    return true;
}

void UJMPhysicalGrabberComponent::Release()
{
    UPrimitiveComponent* ReleasedComponent = GrabbedComponent.Get();
    if (!ReleasedComponent)
    {
        GrabbedComponent = nullptr;
        return;
    }

    if (bIgnorePawnCollisionWhileHeld)
    {
        ReleasedComponent->SetCollisionResponseToChannel(ECC_Pawn, PreviousPawnResponse);
    }

    GrabbedComponent = nullptr;
    GrabbedBone = NAME_None;
    LocalGrabPoint = FVector::ZeroVector;
    OnReleased.Broadcast(ReleasedComponent);
}

bool UJMPhysicalGrabberComponent::IsHoldingObject() const
{
    return IsValid(GrabbedComponent) && GrabbedComponent->IsSimulatingPhysics(GrabbedBone);
}

UPrimitiveComponent* UJMPhysicalGrabberComponent::GetGrabbedComponent() const
{
    return IsHoldingObject() ? GrabbedComponent.Get() : nullptr;
}

bool UJMPhysicalGrabberComponent::GetPlayerView(FVector& OutLocation, FVector& OutDirection) const
{
    const APawn* Pawn = Cast<APawn>(GetOwner());
    const APlayerController* Controller = Pawn ? Cast<APlayerController>(Pawn->GetController()) : nullptr;
    if (!Controller)
    {
        return false;
    }

    FRotator ViewRotation;
    Controller->GetPlayerViewPoint(OutLocation, ViewRotation);
    OutDirection = ViewRotation.Vector();
    return true;
}

void UJMPhysicalGrabberComponent::ApplyGrabForce(float DeltaTime)
{
    if (!IsHoldingObject())
    {
        if (GrabbedComponent)
        {
            Release();
        }
        return;
    }

    FVector ViewLocation;
    FVector ViewDirection;
    if (!GetPlayerView(ViewLocation, ViewDirection))
    {
        Release();
        return;
    }

    UPrimitiveComponent* Component = GrabbedComponent.Get();
    const FVector TargetLocation = ViewLocation + ViewDirection * HoldDistance;
    const FVector GrabPoint = Component->GetComponentTransform().TransformPosition(LocalGrabPoint);
    const FVector Error = TargetLocation - GrabPoint;

    if (Error.SizeSquared() > FMath::Square(BreakDistance))
    {
        Release();
        return;
    }

    const FVector PointVelocity = Component->GetPhysicsLinearVelocityAtPoint(GrabPoint, GrabbedBone);
    const FVector RequestedForce = Error * SpringStrength - PointVelocity * Damping;
    const FVector AppliedForce = RequestedForce.GetClampedToMaxSize(MaxGrabForce);
    Component->AddForceAtLocation(AppliedForce, GrabPoint, GrabbedBone);

    if (bDrawDebug)
    {
        DrawDebugSphere(GetWorld(), TargetLocation, 6.0f, 12, FColor::Cyan, false, DeltaTime * 1.5f);
        DrawDebugLine(GetWorld(), GrabPoint, TargetLocation, FColor::Cyan, false, DeltaTime * 1.5f, 0, 1.0f);
    }
}
