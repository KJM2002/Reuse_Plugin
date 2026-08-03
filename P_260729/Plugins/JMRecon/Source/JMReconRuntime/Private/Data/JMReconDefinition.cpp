#include "Data/JMReconDefinition.h"

#if WITH_EDITOR
#include "Misc/DataValidation.h"

EDataValidationResult UJMReconDefinition::IsDataValid(FDataValidationContext& Context) const
{
    EDataValidationResult Result = Super::IsDataValid(Context);
    if (!bAllowListen && !bAllowPeek)
    {
        Context.AddError(NSLOCTEXT("JMRecon", "NoModes", "At least Listen or Peek must be enabled."));
        Result = EDataValidationResult::Invalid;
    }
    if (!FMath::IsWithinInclusive(PeekOpenFraction, 0.0f, 1.0f))
    {
        Context.AddError(NSLOCTEXT("JMRecon", "PeekFraction", "Peek Open Fraction must be between 0 and 1."));
        Result = EDataValidationResult::Invalid;
    }
    if (!FMath::IsWithinInclusive(CameraYawLimit, 0.0f, 180.0f) ||
        !FMath::IsWithinInclusive(CameraPitchLimit, 0.0f, 89.9f))
    {
        Context.AddError(NSLOCTEXT("JMRecon", "CameraLimits", "Camera yaw or pitch limit is outside its supported range."));
        Result = EDataValidationResult::Invalid;
    }
    return Result;
}
#endif
