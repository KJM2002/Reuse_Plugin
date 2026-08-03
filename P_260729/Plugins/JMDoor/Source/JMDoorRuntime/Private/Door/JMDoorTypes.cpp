#include "Door/JMDoorTypes.h"

bool FJMDoorAccessRequirement::IsSatisfiedBy(const FGameplayTagContainer& AvailableTags) const
{
    if (RequiredTags.IsEmpty())
    {
        return true;
    }

    if (!MasterAccessTags.IsEmpty() && AvailableTags.HasAny(MasterAccessTags))
    {
        return true;
    }

    return MatchMode == EJMDoorAccessMatchMode::AllRequired
        ? AvailableTags.HasAll(RequiredTags)
        : AvailableTags.HasAny(RequiredTags);
}

FJMDoorResult FJMDoorResult::Success(const FText& Message)
{
    FJMDoorResult Result;
    Result.bSucceeded = true;
    Result.Code = EJMDoorResultCode::Succeeded;
    Result.Message = Message;
    return Result;
}

FJMDoorResult FJMDoorResult::Failure(EJMDoorResultCode Code, const FText& Message)
{
    FJMDoorResult Result;
    Result.Code = Code;
    Result.Message = Message;
    return Result;
}
