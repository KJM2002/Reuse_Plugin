#include "Components/JMRoomPortComponent.h"
#include "Blueprint/JMRoomGridLibrary.h"

UJMRoomPortComponent::UJMRoomPortComponent()
{
    ArrowSize = 0.75f;
    ArrowLength = 80.0f;
    ArrowColor = FColor::Cyan;
    SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

EJMRoomDirection UJMRoomPortComponent::GetWorldDirection() const
{
    return UJMRoomGridLibrary::RotateDirectionMask(LocalDirection, GetOwner() ? FMath::RoundToInt(GetOwner()->GetActorRotation().Yaw) : 0);
}
