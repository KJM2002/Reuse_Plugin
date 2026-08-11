#include "Types/JMHarpoonLightPullModel.h"

bool FJMHarpoonLightPullModel::IsLightMass(float MassKg, float ThresholdKg)
{
    return FMath::IsFinite(MassKg)
        && FMath::IsFinite(ThresholdKg)
        && MassKg >= 0.0f
        && MassKg < FMath::Max(0.0f, ThresholdKg);
}

float FJMHarpoonLightPullModel::CalculateTargetSpeed(
    float DistanceToRelease,
    float MinimumSpeed,
    float MaximumSpeed,
    float ApproachSlowDistance)
{
    const float SafeMinimum = FMath::Max(0.0f, MinimumSpeed);
    const float SafeMaximum = FMath::Max(SafeMinimum, MaximumSpeed);
    const float Alpha = FMath::Clamp(
        FMath::Max(0.0f, DistanceToRelease) / FMath::Max(ApproachSlowDistance, 1.0f),
        0.0f,
        1.0f);
    return FMath::Lerp(SafeMinimum, SafeMaximum, Alpha);
}

float FJMHarpoonLightPullModel::CalculatePullRamp(float RecallElapsed, float RampTime)
{
    if (RampTime <= KINDA_SMALL_NUMBER)
    {
        return 1.0f;
    }
    const float Alpha = FMath::Clamp(RecallElapsed / RampTime, 0.0f, 1.0f);
    return Alpha * Alpha * (3.0f - 2.0f * Alpha);
}

FVector FJMHarpoonLightPullModel::CalculateAcceleration(
    const FVector& PullDirection,
    const FVector& CurrentVelocity,
    float DistanceToRelease,
    float MinimumSpeed,
    float MaximumSpeed,
    float ApproachSlowDistance,
    float TangentialRetention,
    float VelocityGain,
    float MaximumAcceleration,
    float PullRamp)
{
    const FVector SafeDirection = PullDirection.GetSafeNormal();
    if (SafeDirection.IsNearlyZero())
    {
        return FVector::ZeroVector;
    }

    const float RadialSpeed = FVector::DotProduct(CurrentVelocity, SafeDirection);
    const FVector TangentialVelocity = CurrentVelocity - SafeDirection * RadialSpeed;
    const float TargetSpeed = CalculateTargetSpeed(
        DistanceToRelease,
        MinimumSpeed,
        MaximumSpeed,
        ApproachSlowDistance);
    const FVector DesiredVelocity = SafeDirection * TargetSpeed
        + TangentialVelocity * FMath::Clamp(TangentialRetention, 0.0f, 1.0f);
    const FVector DesiredAcceleration = (DesiredVelocity - CurrentVelocity)
        * FMath::Max(0.0f, VelocityGain)
        * FMath::Clamp(PullRamp, 0.0f, 1.0f);
    return DesiredAcceleration.GetClampedToMaxSize(FMath::Max(0.0f, MaximumAcceleration));
}

FVector FJMHarpoonLightPullModel::CalculateAngularDeceleration(
    const FVector& AngularVelocityRadians,
    float AngularDamping,
    float MaximumAngularDeceleration)
{
    return (-AngularVelocityRadians * FMath::Max(0.0f, AngularDamping))
        .GetClampedToMaxSize(FMath::Max(0.0f, MaximumAngularDeceleration));
}
