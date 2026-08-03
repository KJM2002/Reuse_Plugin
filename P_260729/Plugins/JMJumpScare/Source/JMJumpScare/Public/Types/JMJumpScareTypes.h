#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "JMJumpScareTypes.generated.h"

class AJMJumpScareAnchor;
class AActor;
class APlayerController;
class USoundBase;

UENUM(BlueprintType)
enum class EJMJumpScareSpawnMode : uint8
{
    WorldAnchor,
    CameraRelative
};

/** UseLegacySpawnMode preserves every pre-1.1 Definition without asset migration. */
UENUM(BlueprintType)
enum class EJMJumpScarePresentationMode : uint8
{
    UseLegacySpawnMode,
    WorldActor,
    CameraRelative,
    CameraAttached,
    ForcedLookAt
};

UENUM(BlueprintType)
enum class EJMJumpScarePhase : uint8
{
    Idle,
    Preparing,
    Entering,
    Impact,
    Holding,
    Exiting,
    Finishing
};

UENUM(BlueprintType)
enum class EJMJumpScareCameraControlMode : uint8
{
    None,
    LockCurrentView,
    LookAtActor,
    LookAtFocusPoint
};

UENUM(BlueprintType)
enum class EJMJumpScareVanishMode : uint8
{
    None,
    InstantHide,
    InterfaceDriven
};

UENUM(BlueprintType)
enum class EJMJumpScareTriggerPolicy : uint8
{
    Once,
    Repeatable
};

UENUM(BlueprintType)
enum class EJMJumpScareConcurrentPolicy : uint8
{
    IgnoreNew
};

UENUM(BlueprintType)
enum class EJMJumpScareOverlapFilter : uint8
{
    PlayerControlledPawn,
    AnyPawn,
    GameplayTags
};

UENUM(BlueprintType)
enum class EJMJumpScareState : uint8
{
    Idle,
    Waiting,
    Playing,
    Finishing
};

UENUM(BlueprintType)
enum class EJMJumpScarePlayResult : uint8
{
    Started,
    AlreadyPlaying,
    AlreadyTriggered,
    InvalidWorld,
    InvalidDefinition,
    MissingImage,
    InvalidActorClass,
    MissingAnchor,
    MissingTargetPlayer,
    MissingCamera,
    SpawnFailed
};

/** Runtime-only inputs. Persistent design data belongs to UJMJumpScareDefinition. */
USTRUCT(BlueprintType)
struct JMJUMPSCARE_API FJMJumpScarePlayContext
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM JumpScare | Context", meta=(WorldContext))
    TObjectPtr<UObject> WorldContextObject = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM JumpScare | Context")
    TObjectPtr<AActor> Instigator = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM JumpScare | Context")
    TObjectPtr<APlayerController> TargetPlayer = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM JumpScare | Context")
    TObjectPtr<AJMJumpScareAnchor> Anchor = nullptr;

    /** Optional existing world Actor used by ForcedLookAt. Its focus component is preferred when present. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM JumpScare | Context")
    TObjectPtr<AActor> FocusTarget = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM JumpScare | Context")
    bool bOverrideSpawnTransform = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM JumpScare | Context", meta=(EditCondition="bOverrideSpawnTransform"))
    FTransform SpawnTransformOverride = FTransform::Identity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM JumpScare | Context")
    TObjectPtr<UObject> Source = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM JumpScare | Context")
    FGameplayTagContainer ContextTags;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM JumpScare | Context")
    bool bOverrideTriggerPolicy = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM JumpScare | Context", meta=(EditCondition="bOverrideTriggerPolicy"))
    EJMJumpScareTriggerPolicy TriggerPolicyOverride = EJMJumpScareTriggerPolicy::Once;
};

USTRUCT(BlueprintType)
struct JMJUMPSCARE_API FJMJumpScareActiveInfo
{
    GENERATED_BODY()

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM JumpScare")
    EJMJumpScareState State = EJMJumpScareState::Idle;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM JumpScare")
    EJMJumpScarePhase Phase = EJMJumpScarePhase::Idle;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM JumpScare")
    FGameplayTag JumpScareId;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM JumpScare")
    TObjectPtr<AActor> SpawnedActor = nullptr;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM JumpScare")
    TObjectPtr<AJMJumpScareAnchor> Anchor = nullptr;
};

USTRUCT(BlueprintType)
struct JMJUMPSCARE_API FJMJumpScareAudioEvent
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM JumpScare | Audio")
    TObjectPtr<USoundBase> Sound = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM JumpScare | Audio")
    EJMJumpScarePhase Phase = EJMJumpScarePhase::Impact;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM JumpScare | Audio", meta=(ClampMin="0.0", Units="s"))
    float Delay = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM JumpScare | Audio", meta=(ClampMin="0.0"))
    float VolumeMultiplier = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM JumpScare | Audio", meta=(ClampMin="0.01"))
    float PitchMultiplier = 1.0f;
};

USTRUCT(BlueprintType)
struct JMJUMPSCARE_API FJMJumpScareTriggerSaveState
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM JumpScare | Save")
    FGameplayTag TriggerId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM JumpScare | Save")
    bool bHasTriggered = false;
};
