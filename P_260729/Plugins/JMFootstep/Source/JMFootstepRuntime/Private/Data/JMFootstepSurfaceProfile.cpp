#include "Data/JMFootstepSurfaceProfile.h"

#include "Sound/SoundBase.h"

bool FJMFootstepSoundVariant::HasValidSound() const
{
    return Sounds.ContainsByPredicate([](const TObjectPtr<USoundBase>& Sound)
    {
        return IsValid(Sound);
    });
}

int32 FJMFootstepSoundVariant::GetValidSoundCount() const
{
    int32 Count = 0;
    for (const TObjectPtr<USoundBase>& Sound : Sounds)
    {
        if (IsValid(Sound))
        {
            ++Count;
        }
    }
    return Count;
}

bool UJMFootstepSurfaceProfile::ResolveVariant(
    const EJMFootstepLocomotionState RequestedState,
    FJMFootstepSoundVariant& OutVariant,
    EJMFootstepLocomotionState& OutSelectedVariantState,
    bool& bOutUsedFallback,
    bool& bOutUsedLegacyVariant) const
{
    OutVariant = FJMFootstepSoundVariant();
    OutSelectedVariantState = EJMFootstepLocomotionState::Idle;
    bOutUsedFallback = false;
    bOutUsedLegacyVariant = false;

    const FJMFootstepSoundVariant* RequestedVariant = nullptr;
    switch (RequestedState)
    {
    case EJMFootstepLocomotionState::Walk:
        RequestedVariant = &WalkVariant;
        break;
    case EJMFootstepLocomotionState::Run:
        RequestedVariant = &RunVariant;
        break;
    case EJMFootstepLocomotionState::CrouchWalk:
        RequestedVariant = &CrouchWalkVariant;
        break;
    case EJMFootstepLocomotionState::Idle:
    default:
        return false;
    }

    if (RequestedVariant->HasValidSound())
    {
        OutVariant = *RequestedVariant;
        OutSelectedVariantState = RequestedState;
        return true;
    }

    if (RequestedState != EJMFootstepLocomotionState::Walk && WalkVariant.HasValidSound())
    {
        OutVariant = WalkVariant;
        OutSelectedVariantState = EJMFootstepLocomotionState::Walk;
        bOutUsedFallback = true;
        return true;
    }

    if (!HasValidLegacySound())
    {
        return false;
    }

    OutVariant.Sounds = Sounds;
    OutVariant.VolumeMin = VolumeMin;
    OutVariant.VolumeMax = VolumeMax;
    OutVariant.PitchMin = PitchMin;
    OutVariant.PitchMax = PitchMax;
    OutSelectedVariantState = EJMFootstepLocomotionState::Walk;
    bOutUsedFallback = true;
    bOutUsedLegacyVariant = true;
    return true;
}

bool UJMFootstepSurfaceProfile::HasValidLegacySound() const
{
    return Sounds.ContainsByPredicate([](const TObjectPtr<USoundBase>& Sound)
    {
        return IsValid(Sound);
    });
}
