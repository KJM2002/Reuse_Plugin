#include "Settings/JMFootstepSettings.h"

UJMFootstepSettings::UJMFootstepSettings()
{
    CategoryName = TEXT("JM Plugins");
    SectionName = TEXT("Footstep");
}

const UJMFootstepSettings* UJMFootstepSettings::Get()
{
    return GetDefault<UJMFootstepSettings>();
}

FName UJMFootstepSettings::GetCategoryName() const
{
    return TEXT("JM Plugins");
}
