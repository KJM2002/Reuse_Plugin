#include "Types/JMFootstepRuntimeLogic.h"

int32 FJMFootstepDistanceAccumulator::AddMovement(
    const float Distance2D,
    const bool bGrounded,
    const float RequiredStepDistance,
    const float TeleportDistanceThreshold,
    const int32 MaxSteps)
{
    if (!bGrounded)
    {
        Reset();
        return 0;
    }

    const float SafeDistance = FMath::Max(0.0f, Distance2D);
    if (TeleportDistanceThreshold > 0.0f && SafeDistance >= TeleportDistanceThreshold)
    {
        Reset();
        return 0;
    }

    if (RequiredStepDistance <= UE_KINDA_SMALL_NUMBER || MaxSteps <= 0)
    {
        return 0;
    }

    AccumulatedDistance += SafeDistance;

    int32 StepCount = 0;
    while (AccumulatedDistance >= RequiredStepDistance && StepCount < MaxSteps)
    {
        AccumulatedDistance -= RequiredStepDistance;
        ++StepCount;
    }

    if (StepCount == MaxSteps && AccumulatedDistance >= RequiredStepDistance)
    {
        AccumulatedDistance = FMath::Fmod(AccumulatedDistance, RequiredStepDistance);
    }

    return StepCount;
}

void FJMFootstepDistanceAccumulator::Reset()
{
    AccumulatedDistance = 0.0f;
}

EJMFootstepLocomotionState FJMFootstepRuntimeLogic::ResolveRequestedLocomotionState(
    const FJMFootstepContext& Context,
    const EJMFootstepLocomotionState DetectedState)
{
    return Context.bOverrideLocomotionState ? Context.LocomotionState : DetectedState;
}

EJMFootstepLocomotionState FJMFootstepRuntimeLogic::ResolveLocomotionState(
    const float ActualSpeed2D,
    const bool bCrouched,
    const bool bGrounded,
    const float MinimumMovementSpeed,
    const float RunSpeedThreshold)
{
    if (!bGrounded || ActualSpeed2D < FMath::Max(0.0f, MinimumMovementSpeed))
    {
        return EJMFootstepLocomotionState::Idle;
    }

    if (bCrouched)
    {
        return EJMFootstepLocomotionState::CrouchWalk;
    }

    return ActualSpeed2D >= FMath::Max(MinimumMovementSpeed, RunSpeedThreshold)
        ? EJMFootstepLocomotionState::Run
        : EJMFootstepLocomotionState::Walk;
}

float FJMFootstepRuntimeLogic::ResolveStepDistance(
    const EJMFootstepLocomotionState State,
    const float WalkStepDistance,
    const float RunStepDistance,
    const float CrouchStepDistance)
{
    switch (State)
    {
    case EJMFootstepLocomotionState::Run:
        return RunStepDistance;
    case EJMFootstepLocomotionState::CrouchWalk:
        return CrouchStepDistance;
    case EJMFootstepLocomotionState::Walk:
    default:
        return WalkStepDistance;
    }
}

float FJMFootstepRuntimeLogic::ResolveStateVolumeMultiplier(
    const EJMFootstepLocomotionState State,
    const float WalkVolumeMultiplier,
    const float RunVolumeMultiplier,
    const float CrouchVolumeMultiplier)
{
    switch (State)
    {
    case EJMFootstepLocomotionState::Run:
        return RunVolumeMultiplier;
    case EJMFootstepLocomotionState::CrouchWalk:
        return CrouchVolumeMultiplier;
    case EJMFootstepLocomotionState::Walk:
        return WalkVolumeMultiplier;
    default:
        return 0.0f;
    }
}

int32 FJMFootstepRuntimeLogic::SelectSoundIndex(
    const int32 SoundCount,
    const int32 LastIndex,
    const int32 RandomValue)
{
    if (SoundCount <= 0)
    {
        return INDEX_NONE;
    }

    if (SoundCount == 1)
    {
        return 0;
    }

    int32 Candidate = static_cast<int32>(static_cast<uint32>(RandomValue) % static_cast<uint32>(SoundCount));
    if (Candidate == LastIndex)
    {
        Candidate = (Candidate + 1) % SoundCount;
    }
    return Candidate;
}
