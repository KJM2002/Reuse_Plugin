#include "Data/JMFootstepSet.h"

#include "Data/JMFootstepSurfaceProfile.h"

UJMFootstepSurfaceProfile* UJMFootstepSet::FindProfile(
    const EPhysicalSurface SurfaceType,
    bool& bUsedFallback) const
{
    for (const FJMFootstepSurfaceEntry& Entry : SurfaceProfiles)
    {
        if (Entry.SurfaceType == SurfaceType && IsValid(Entry.Profile))
        {
            bUsedFallback = false;
            return Entry.Profile;
        }
    }

    bUsedFallback = true;
    return IsValid(DefaultProfile) ? DefaultProfile.Get() : nullptr;
}
