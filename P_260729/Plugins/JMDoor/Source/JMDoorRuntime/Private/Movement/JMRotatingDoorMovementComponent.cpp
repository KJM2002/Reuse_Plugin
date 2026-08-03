#include "Movement/JMRotatingDoorMovementComponent.h"

FTransform UJMRotatingDoorMovementComponent::CalculateRelativeTransform_Implementation(float OpenFraction, int32 DirectionSign) const
{
    FTransform Result = ClosedRelativeTransform;
    const FVector SafeAxis = LocalRotationAxis.GetSafeNormal(KINDA_SMALL_NUMBER, FVector::UpVector);
    const FQuat Delta(SafeAxis, FMath::DegreesToRadians(OpenAngle * OpenFraction * static_cast<float>(DirectionSign)));
    Result.SetRotation(ClosedRelativeTransform.GetRotation() * Delta);
    return Result;
}
