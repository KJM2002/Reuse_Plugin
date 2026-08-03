#include "Data/JMJumpScareDefinition.h"

bool UJMJumpScareDefinition::IsDefinitionValid() const
{
    return Image != nullptr
        && ImageResolution.X > 0.0f
        && ImageResolution.Y > 0.0f
        && Duration >= 0.0f
        && StartDelay >= 0.0f
        && SoundDelay >= 0.0f
        && RiseDuration >= 0.0f
        && GlitchDuration >= 0.0f;
}
