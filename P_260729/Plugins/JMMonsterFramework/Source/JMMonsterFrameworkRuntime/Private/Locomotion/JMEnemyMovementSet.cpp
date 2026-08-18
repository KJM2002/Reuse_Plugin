#include "Locomotion/JMEnemyMovementSet.h"

#if WITH_EDITOR
#include "Misc/DataValidation.h"
#endif

const FJMEnemyMovementProfile* UJMEnemyMovementSet::FindProfile(const FName ProfileName) const
{
    return Profiles.FindByPredicate(
        [ProfileName](const FJMEnemyMovementProfile& Profile) { return Profile.ProfileName == ProfileName; });
}

bool UJMEnemyMovementSet::GetProfile(const FName ProfileName, FJMEnemyMovementProfile& OutProfile) const
{
    if (const FJMEnemyMovementProfile* Profile = FindProfile(ProfileName))
    {
        OutProfile = *Profile;
        return true;
    }
    return false;
}

#if WITH_EDITOR
EDataValidationResult UJMEnemyMovementSet::IsDataValid(FDataValidationContext& Context) const
{
    EDataValidationResult Result = Super::IsDataValid(Context);
    TSet<FName> Names;
    for (const FJMEnemyMovementProfile& Profile : Profiles)
    {
        if (!Profile.IsValid())
        {
            Context.AddError(NSLOCTEXT("JMMonsterFramework", "InvalidMovementProfile",
                "Every movement profile requires a name and non-negative movement values."));
            Result = EDataValidationResult::Invalid;
        }
        else if (Names.Contains(Profile.ProfileName))
        {
            Context.AddError(FText::Format(NSLOCTEXT("JMMonsterFramework", "DuplicateMovementProfile",
                "Movement profile name '{0}' is duplicated."), FText::FromName(Profile.ProfileName)));
            Result = EDataValidationResult::Invalid;
        }
        Names.Add(Profile.ProfileName);
    }
    return Result == EDataValidationResult::NotValidated ? EDataValidationResult::Valid : Result;
}
#endif
