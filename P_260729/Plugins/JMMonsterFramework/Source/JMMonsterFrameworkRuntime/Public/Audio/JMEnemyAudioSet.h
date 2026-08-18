#pragma once

#include "Engine/DataAsset.h"
#include "JMEnemyAudioSet.generated.h"

class USoundBase;

UENUM(BlueprintType)
enum class EJMEnemyAudioEvent : uint8
{
    Idle,
    Alert,
    Investigate,
    Chase,
    Flee,
    Frozen,
    Enrage,
    Frenzy,
    AttackWindup,
    Attack,
    Pain,
    Death,
    Scream
};

USTRUCT(BlueprintType)
struct JMMONSTERFRAMEWORKRUNTIME_API FJMEnemyAudioVariant
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="JM Monster|Audio")
    TObjectPtr<USoundBase> Sound;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="JM Monster|Audio", meta=(ClampMin="0.0"))
    FVector2D VolumeRange = FVector2D(1.0, 1.0);

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="JM Monster|Audio", meta=(ClampMin="0.01"))
    FVector2D PitchRange = FVector2D(1.0, 1.0);

    bool IsValid() const;
};

USTRUCT(BlueprintType)
struct JMMONSTERFRAMEWORKRUNTIME_API FJMEnemyAudioEventEntry
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="JM Monster|Audio")
    EJMEnemyAudioEvent Event = EJMEnemyAudioEvent::Idle;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="JM Monster|Audio")
    TArray<FJMEnemyAudioVariant> Variants;
};

/** Immutable event-to-sound presentation data. Runtime playback state belongs to the component. */
UCLASS(BlueprintType)
class JMMONSTERFRAMEWORKRUNTIME_API UJMEnemyAudioSet : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="JM Monster|Audio")
    TArray<FJMEnemyAudioEventEntry> Events;

    const FJMEnemyAudioEventEntry* FindEvent(EJMEnemyAudioEvent Event) const;

#if WITH_EDITOR
    virtual EDataValidationResult IsDataValid(class FDataValidationContext& Context) const override;
#endif
};
