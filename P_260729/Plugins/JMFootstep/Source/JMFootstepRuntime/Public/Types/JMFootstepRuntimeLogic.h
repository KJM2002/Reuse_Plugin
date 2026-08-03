#pragma once

#include "CoreMinimal.h"
#include "Types/JMFootstepTypes.h"

/**
 * Small world-independent helpers used by the runtime component and fast tests.
 */
struct JMFOOTSTEPRUNTIME_API FJMFootstepDistanceAccumulator
{
    int32 AddMovement(
        float Distance2D,
        bool bGrounded,
        float RequiredStepDistance,
        float TeleportDistanceThreshold,
        int32 MaxSteps);

    void Reset();
    float GetAccumulatedDistance() const { return AccumulatedDistance; }

private:
    float AccumulatedDistance = 0.0f;
};

struct JMFOOTSTEPRUNTIME_API FJMFootstepRuntimeLogic
{
    static EJMFootstepLocomotionState ResolveRequestedLocomotionState(
        const FJMFootstepContext& Context,
        EJMFootstepLocomotionState DetectedState);

    static EJMFootstepLocomotionState ResolveLocomotionState(
        float ActualSpeed2D,
        bool bCrouched,
        bool bGrounded,
        float MinimumMovementSpeed,
        float RunSpeedThreshold);

    static float ResolveStepDistance(
        EJMFootstepLocomotionState State,
        float WalkStepDistance,
        float RunStepDistance,
        float CrouchStepDistance);

    static float ResolveStateVolumeMultiplier(
        EJMFootstepLocomotionState State,
        float WalkVolumeMultiplier,
        float RunVolumeMultiplier,
        float CrouchVolumeMultiplier);

    static int32 SelectSoundIndex(int32 SoundCount, int32 LastIndex, int32 RandomValue);
};
