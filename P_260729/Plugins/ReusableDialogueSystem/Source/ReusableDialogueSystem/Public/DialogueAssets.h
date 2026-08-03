#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ReusableDialogueTypes.h"
#include "DialogueAssets.generated.h"

class USoundBase;
class USoundConcurrency;
class UTexture2D;

UCLASS(BlueprintType)
class REUSABLEDIALOGUESYSTEM_API UDialogueTextSoundSet : public UPrimaryDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio") TArray<TObjectPtr<USoundBase>> Sounds;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio", meta=(ClampMin="0.0")) float VolumeMin = .85f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio", meta=(ClampMin="0.0")) float VolumeMax = 1.f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio", meta=(ClampMin="0.01")) float PitchMin = .96f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio", meta=(ClampMin="0.01")) float PitchMax = 1.04f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio", meta=(ClampMin="0.0")) float MinimumPlaybackInterval = .05f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio", meta=(ClampMin="1")) int32 SoundEveryNCharacters = 2;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio") bool bSkipWhitespace = true;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio") bool bSkipPunctuation = true;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio") bool bStopPreviousSound = false;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio") bool bDisableWhileVoiceIsPlaying = false;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio") TObjectPtr<USoundConcurrency> SoundConcurrency = nullptr;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio") TObjectPtr<USoundBase> LineCompleteSound = nullptr;
};

UCLASS(BlueprintType)
class REUSABLEDIALOGUESYSTEM_API UDialogueSpeakerProfile : public UPrimaryDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Speaker") FName SpeakerId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Speaker") FText DisplayName;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Speaker") FLinearColor NameColor = FLinearColor::White;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Speaker") TObjectPtr<UTexture2D> Portrait = nullptr;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio") TObjectPtr<USoundBase> DefaultVoiceSound = nullptr;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio") TObjectPtr<UDialogueTextSoundSet> TextSoundSet = nullptr;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio") bool bEnableTextSound = true;
};

UCLASS(BlueprintType)
class REUSABLEDIALOGUESYSTEM_API UDialogueSequence : public UPrimaryDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Dialogue") FName SequenceId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Dialogue") TArray<FDialogueLine> Lines;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Dialogue") FGameplayTag SequenceTag;
};
