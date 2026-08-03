#pragma once

#include "CoreMinimal.h"
#include "Door/JMDoorTypes.h"
#include "Engine/DataAsset.h"
#include "Sound/SoundBase.h"
#include "JMDoorConfigData.generated.h"

UCLASS(BlueprintType)
class JMDOORRUNTIME_API UJMDoorConfigData : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Movement", meta=(ClampMin="0.01", Units="s"))
    float OpenDuration = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Movement", meta=(ClampMin="0.01", Units="s"))
    float CloseDuration = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Movement", meta=(ClampMin="0.01"))
    float FastSpeedMultiplier = 2.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Movement", meta=(ClampMin="0.01"))
    float QuietSpeedMultiplier = 0.5f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Movement")
    EJMDoorOpenDirectionMode OpenDirectionMode = EJMDoorOpenDirectionMode::AwayFromInteractor;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Movement")
    TObjectPtr<UCurveFloat> MovementCurve = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Slide Door|Opening Behavior")
    EJMSlideDoorOpenMode SlideDoorOpenMode = EJMSlideDoorOpenMode::OpenDoorA;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Slide Door|Opening Behavior")
    EJMSlideDoorPanelSelectionMode SlideDoorPanelSelectionMode = EJMSlideDoorPanelSelectionMode::ConfiguredPanel;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Automatic")
    bool bAutoClose = false;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Automatic", meta=(ClampMin="0.0", Units="s", EditCondition="bAutoClose"))
    float AutoCloseDelay = 3.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Access")
    bool bInitiallyLocked = false;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Access")
    FJMDoorAccessRequirement AccessRequirement;

    /**
     * Direct asset links accepted by this lock, such as Inventory Item Definitions.
     * Use this for Blueprint-friendly key setup without Gameplay Tags.
     */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Access", meta=(DisplayName="Accepted Access Items"))
    TArray<TSoftObjectPtr<UObject>> AcceptedAccessObjects;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Durability")
    bool bBreakable = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Durability", meta=(ClampMin="0.0"))
    float MaxDoorDurability = 100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Durability")
    bool bLockBreakable = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Durability", meta=(ClampMin="0.0"))
    float MaxLockDurability = 50.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Blocking")
    bool bDetectObstructions = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Blocking")
    EJMDoorBlockBehavior BlockBehavior = EJMDoorBlockBehavior::Reverse;

    /**
     * Moves characters out of the leaf's next pose before the door is advanced.
     * This keeps the character capsule, rather than the camera, as the primary
     * point of contact with an automatically closing door.
     */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Blocking")
    bool bPushCharacters = true;

    /** Deprecated. Continuous pushes now use the exact swept leaf displacement without per-frame padding. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Blocking", meta=(DeprecatedProperty, DeprecationMessage="Continuous character push no longer adds per-frame padding."))
    float CharacterPushPadding = 1.0f;

    /** Deprecated. Large leaf deltas are divided into swept substeps instead of clamped. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Blocking", meta=(DeprecatedProperty, DeprecationMessage="Use Character Push Max Substep Distance instead."))
    float MaxCharacterPushDistancePerTick = 30.0f;

    /** Maximum translation covered by one predictive leaf sweep. The full frame delta is always applied. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Blocking", meta=(ClampMin="0.1", Units="cm", EditCondition="bPushCharacters"))
    float CharacterPushMaxSubstepDistance = 5.0f;

    /** Maximum rotation covered by one predictive leaf sweep. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Blocking", meta=(ClampMin="0.1", ClampMax="45.0", Units="deg", EditCondition="bPushCharacters"))
    float CharacterPushMaxSubstepAngle = 2.0f;

    /** Upper bound for predictive push work during an unusually long frame. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Blocking", meta=(ClampMin="1", ClampMax="128", EditCondition="bPushCharacters"))
    int32 CharacterPushMaxSubsteps = 32;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Blocking", meta=(ClampMin="0.01", Units="s"))
    float RetryDelay = 0.5f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Blocking", meta=(ClampMin="0"))
    int32 MaxRetryCount = 3;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Noise", meta=(ClampMin="0.0"))
    float OpenNoiseLoudness = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Noise", meta=(ClampMin="0.0", Units="cm"))
    float OpenNoiseRange = 1200.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Noise", meta=(ClampMin="0.0"))
    float CloseNoiseLoudness = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Noise", meta=(ClampMin="0.0", Units="cm"))
    float CloseNoiseRange = 1200.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Noise", meta=(ClampMin="0.0"))
    float BreakNoiseLoudness = 4.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Noise", meta=(ClampMin="0.0", Units="cm"))
    float BreakNoiseRange = 2500.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio")
    TSoftObjectPtr<USoundBase> OpenSound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio")
    TSoftObjectPtr<USoundBase> CloseSound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio")
    TSoftObjectPtr<USoundBase> LockedSound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio")
    TSoftObjectPtr<USoundBase> BreakSound;
};
