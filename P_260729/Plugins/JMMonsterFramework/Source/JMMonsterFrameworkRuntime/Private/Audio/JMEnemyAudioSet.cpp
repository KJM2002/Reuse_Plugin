#include "Audio/JMEnemyAudioSet.h"

#if WITH_EDITOR
#include "Misc/DataValidation.h"
#endif

bool FJMEnemyAudioVariant::IsValid() const
{
    return Sound && VolumeRange.X >= 0.0 && VolumeRange.Y >= VolumeRange.X &&
        PitchRange.X > 0.0 && PitchRange.Y >= PitchRange.X;
}

const FJMEnemyAudioEventEntry* UJMEnemyAudioSet::FindEvent(const EJMEnemyAudioEvent Event) const
{
    return Events.FindByPredicate(
        [Event](const FJMEnemyAudioEventEntry& Entry) { return Entry.Event == Event; });
}

#if WITH_EDITOR
EDataValidationResult UJMEnemyAudioSet::IsDataValid(FDataValidationContext& Context) const
{
    EDataValidationResult Result = Super::IsDataValid(Context);
    TSet<EJMEnemyAudioEvent> EventIds;
    for (const FJMEnemyAudioEventEntry& Entry : Events)
    {
        if (EventIds.Contains(Entry.Event))
        {
            Context.AddError(NSLOCTEXT("JMMonsterFramework", "DuplicateAudioEvent",
                "An Audio Event is configured more than once."));
            Result = EDataValidationResult::Invalid;
        }
        EventIds.Add(Entry.Event);

        for (const FJMEnemyAudioVariant& Variant : Entry.Variants)
        {
            if (!Variant.IsValid())
            {
                Context.AddError(NSLOCTEXT("JMMonsterFramework", "InvalidAudioVariant",
                    "Audio variants require a Sound and ordered, non-negative volume/positive pitch ranges."));
                Result = EDataValidationResult::Invalid;
            }
        }
    }
    return Result == EDataValidationResult::NotValidated ? EDataValidationResult::Valid : Result;
}
#endif
