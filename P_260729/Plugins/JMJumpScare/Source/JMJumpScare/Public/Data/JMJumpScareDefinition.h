#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Types/JMJumpScareTypes.h"
#include "JMJumpScareDefinition.generated.h"

class AActor;
class UMaterialInterface;
class USoundBase;
class UTexture2D;

/**
 * A deliberately small JumpScare definition.
 * The runtime presents Image as a full-screen 2D overlay on the target player's view.
 */
UCLASS(BlueprintType, meta=(DisplayName="JM JumpScare Definition"))
class JMJUMPSCARE_API UJMJumpScareDefinition : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpScare", meta=(Categories="JumpScare"))
    FGameplayTag JumpScareId;

    /** Image placed over the target player's camera view. Alpha is supported. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpScare")
    TObjectPtr<UTexture2D> Image = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpScare")
    FLinearColor ImageTint = FLinearColor::White;

    /** On-screen size in viewport pixels. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpScare", meta=(ClampMin="1.0"))
    FVector2D ImageResolution = FVector2D(1920.0f, 1080.0f);

    /** Time for the image to rise from below the screen to the center. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpScare", meta=(ClampMin="0.0", Units="s"))
    float RiseDuration = 0.2f;

    /** Draw order on the player's screen. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpScare")
    int32 ZOrder = 1000;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpScare", meta=(ClampMin="0.0", Units="s"))
    float StartDelay = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpScare", meta=(ClampMin="0.0", Units="s"))
    float Duration = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpScare")
    TObjectPtr<USoundBase> JumpScareSound = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpScare", meta=(ClampMin="0.0", Units="s"))
    float SoundDelay = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpScare", meta=(ClampMin="0.0"))
    float VolumeMultiplier = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpScare", meta=(ClampMin="0.01"))
    float PitchMultiplier = 1.0f;

    /** Post-process material played after the image disappears. Defaults to /Game/Jumpscare/M_Glitch. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpScare | Glitch")
    TSoftObjectPtr<UMaterialInterface> GlitchMaterial =
        TSoftObjectPtr<UMaterialInterface>(FSoftObjectPath(TEXT("/Game/Jumpscare/M_Glitch.M_Glitch")));

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpScare | Glitch", meta=(ClampMin="0.0", Units="s"))
    float GlitchDuration = 0.25f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpScare | Glitch")
    TObjectPtr<USoundBase> GlitchSound = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpScare | Glitch", meta=(ClampMin="0.0"))
    float GlitchVolumeMultiplier = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpScare | Glitch", meta=(ClampMin="0.01"))
    float GlitchPitchMultiplier = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JumpScare")
    EJMJumpScareTriggerPolicy TriggerPolicy = EJMJumpScareTriggerPolicy::Once;

    /**
     * Retained only for source compatibility with JMRecon integration.
     * The 2D overlay appears immediately after StartDelay.
     */
    UPROPERTY(meta=(DeprecatedProperty, DeprecationMessage="2D JumpScares no longer use an entering phase."))
    float EnteringDuration = 0.0f;

    UFUNCTION(BlueprintPure, Category="JM JumpScare")
    bool IsDefinitionValid() const;
};
