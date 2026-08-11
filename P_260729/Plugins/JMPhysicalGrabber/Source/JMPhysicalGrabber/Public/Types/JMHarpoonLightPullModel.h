#pragma once

#include "CoreMinimal.h"

/** Pure, deterministic calculations used by the light-physics-target recall path. */
struct JMPHYSICALGRABBER_API FJMHarpoonLightPullModel
{
    static bool IsLightMass(float MassKg, float ThresholdKg);

    static float CalculateTargetSpeed(
        float DistanceToRelease,
        float MinimumSpeed,
        float MaximumSpeed,
        float ApproachSlowDistance);

    static float CalculatePullRamp(float RecallElapsed, float RampTime);

    static FVector CalculateAcceleration(
        const FVector& PullDirection,
        const FVector& CurrentVelocity,
        float DistanceToRelease,
        float MinimumSpeed,
        float MaximumSpeed,
        float ApproachSlowDistance,
        float TangentialRetention,
        float VelocityGain,
        float MaximumAcceleration,
        float PullRamp);

    static FVector CalculateAngularDeceleration(
        const FVector& AngularVelocityRadians,
        float AngularDamping,
        float MaximumAngularDeceleration);
};
