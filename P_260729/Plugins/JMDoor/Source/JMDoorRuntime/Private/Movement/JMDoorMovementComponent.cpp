#include "Movement/JMDoorMovementComponent.h"

#include "Components/PrimitiveComponent.h"
#include "Components/SceneComponent.h"

UJMDoorMovementComponent::UJMDoorMovementComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UJMDoorMovementComponent::BeginPlay()
{
    Super::BeginPlay();
    if (MovingComponent)
    {
        ClosedRelativeTransform = MovingComponent->GetRelativeTransform();
    }
}

void UJMDoorMovementComponent::InitializeMovingComponent(USceneComponent* InMovingComponent)
{
    MovingComponent = InMovingComponent;
    if (MovingComponent)
    {
        ClosedRelativeTransform = MovingComponent->GetRelativeTransform();
    }
}

void UJMDoorMovementComponent::SetCollisionComponent(UPrimitiveComponent* InCollisionComponent)
{
    CollisionComponent = InCollisionComponent;
}

void UJMDoorMovementComponent::SetDirectionProbeComponent(USceneComponent* InDirectionProbeComponent)
{
    DirectionProbeComponent = InDirectionProbeComponent;
}

void UJMDoorMovementComponent::SetOpenFraction(float OpenFraction, int32 DirectionSign)
{
    if (MovingComponent)
    {
        MovingComponent->SetRelativeTransform(GetRelativeTransformAtFraction(OpenFraction, DirectionSign));
    }
}

FTransform UJMDoorMovementComponent::GetRelativeTransformAtFraction(float OpenFraction, int32 DirectionSign) const
{
    return CalculateRelativeTransform(FMath::Clamp(OpenFraction, 0.0f, 1.0f), DirectionSign >= 0 ? 1 : -1);
}

FTransform UJMDoorMovementComponent::GetWorldTransformAtFraction(float OpenFraction, int32 DirectionSign) const
{
    const FTransform Relative = GetRelativeTransformAtFraction(OpenFraction, DirectionSign);
    if (MovingComponent && MovingComponent->GetAttachParent())
    {
        return Relative * MovingComponent->GetAttachParent()->GetComponentTransform();
    }
    return Relative;
}

FTransform UJMDoorMovementComponent::GetCollisionWorldTransformAtFraction(float OpenFraction, int32 DirectionSign) const
{
    const FTransform ProposedMovingWorld = GetWorldTransformAtFraction(OpenFraction, DirectionSign);
    if (!MovingComponent || !CollisionComponent || CollisionComponent == MovingComponent)
    {
        return ProposedMovingWorld;
    }

    const FTransform CollisionRelativeToMoving = CollisionComponent->GetComponentTransform().GetRelativeTransform(MovingComponent->GetComponentTransform());
    return CollisionRelativeToMoving * ProposedMovingWorld;
}

FVector UJMDoorMovementComponent::GetDirectionProbeWorldLocationAtFraction(float OpenFraction, int32 DirectionSign) const
{
    const FTransform ProposedMovingWorld = GetWorldTransformAtFraction(OpenFraction, DirectionSign);
    if (!MovingComponent || !DirectionProbeComponent || DirectionProbeComponent == MovingComponent)
    {
        return ProposedMovingWorld.GetLocation();
    }

    const FTransform ProbeRelativeToMoving = DirectionProbeComponent->GetComponentTransform().GetRelativeTransform(MovingComponent->GetComponentTransform());
    return (ProbeRelativeToMoving * ProposedMovingWorld).GetLocation();
}

FTransform UJMDoorMovementComponent::CalculateRelativeTransform_Implementation(float OpenFraction, int32 DirectionSign) const
{
    return ClosedRelativeTransform;
}
