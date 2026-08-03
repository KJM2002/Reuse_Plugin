#include "Data/JMHideDefinition.h"

#if WITH_EDITOR
#include "Misc/DataValidation.h"

EDataValidationResult UJMHideDefinition::IsDataValid(FDataValidationContext& Context) const
{
    EDataValidationResult Result = Super::IsDataValid(Context);
    if (!HideType.IsValid())
    {
        Context.AddWarning(NSLOCTEXT("JMHide", "DefinitionMissingType", "Hide Type is not set."));
        Result = EDataValidationResult::Invalid;
    }
    return Result;
}
#endif
