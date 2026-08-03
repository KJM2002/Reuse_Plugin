#include "Movement/JMCustomDoorMovementComponent.h"

FTransform UJMCustomDoorMovementComponent::CalculateRelativeTransform_Implementation(float OpenFraction, int32 DirectionSign) const
{
    return Super::CalculateRelativeTransform_Implementation(OpenFraction, DirectionSign);
}
