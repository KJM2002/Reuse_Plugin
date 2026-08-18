#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "JMEnemyPerceptionTypes.generated.h"

/** Built-in sensory channels normalized by the framework. */
UENUM(BlueprintType)
enum class EJMStimulusType : uint8
{
    Vision,
    Hearing,
    PlayerGaze,
    Damage
};

/** Engine-independent evidence passed from sensing to memory and later behavior layers. */
USTRUCT(BlueprintType)
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStimulus
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stimulus")
    EJMStimulusType Type = EJMStimulusType::Vision;

    /** Weak ownership prevents historical evidence from extending an Actor's lifetime. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stimulus")
    TWeakObjectPtr<AActor> SourceActor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stimulus")
    FVector WorldLocation = FVector::ZeroVector;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stimulus")
    float Strength = 0.0f;

    /** Reliability of the observation, independent from whether it is currently active. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stimulus", meta=(ClampMin="0.0", ClampMax="1.0"))
    float Confidence = 0.0f;

    /** World time at normalization. Memory never increments this value with Tick. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stimulus")
    double Timestamp = -1.0;

    /** False represents an explicit end such as losing sight or the player looking away. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stimulus")
    bool bSuccessfullySensed = false;

    bool IsValid() const { return Timestamp >= 0.0 && Confidence >= 0.0f && Confidence <= 1.0f; }
};

USTRUCT(BlueprintType)
struct JMMONSTERFRAMEWORKRUNTIME_API FJMEnemyVisionConfig
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vision")
    bool bEnabled = true;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vision", meta=(ClampMin="0.0"))
    float SightRadius = 1500.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vision", meta=(ClampMin="0.0"))
    float LoseSightRadius = 1800.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vision", meta=(ClampMin="0.0", ClampMax="180.0"))
    float PeripheralVisionAngle = 60.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vision", meta=(ClampMin="0.0"))
    float StimulusMaxAge = 5.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vision|Affiliation")
    bool bDetectEnemies = true;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vision|Affiliation")
    bool bDetectFriendlies = true;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vision|Affiliation")
    bool bDetectNeutrals = true;
};

USTRUCT(BlueprintType)
struct JMMONSTERFRAMEWORKRUNTIME_API FJMEnemyHearingConfig
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Hearing")
    bool bEnabled = true;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Hearing", meta=(ClampMin="0.0"))
    float HearingRange = 2500.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Hearing", meta=(ClampMin="0.0"))
    float StimulusMaxAge = 5.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Hearing", meta=(ClampMin="0.0"))
    float MinimumStrength = 0.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Hearing|Affiliation")
    bool bDetectEnemies = true;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Hearing|Affiliation")
    bool bDetectFriendlies = true;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Hearing|Affiliation")
    bool bDetectNeutrals = true;
};

USTRUCT(BlueprintType)
struct JMMONSTERFRAMEWORKRUNTIME_API FJMEnemyGazeConfig
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Player Gaze")
    bool bEnabled = false;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Player Gaze", meta=(ClampMin="0.05"))
    float UpdateInterval = 0.2f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Player Gaze", meta=(ClampMin="0.0"))
    float MaximumDistance = 3000.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Player Gaze", meta=(ClampMin="-1.0", ClampMax="1.0"))
    float DotThreshold = 0.85f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Player Gaze")
    bool bRequireLineOfSight = true;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Player Gaze")
    TEnumAsByte<ECollisionChannel> TraceChannel = ECC_Visibility;
};

USTRUCT(BlueprintType)
struct JMMONSTERFRAMEWORKRUNTIME_API FJMEnemyPerceptionConfig
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Perception")
    FJMEnemyVisionConfig Vision;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Perception")
    FJMEnemyHearingConfig Hearing;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Perception")
    FJMEnemyGazeConfig PlayerGaze;
};
