#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "ReusableDialogueTypes.generated.h"

class UDialogueSpeakerProfile;
class UDialogueTextSoundSet;
class USoundBase;

UENUM(BlueprintType)
enum class EDialogueState : uint8 { Inactive, Opening, Revealing, WaitingForAdvance, Transitioning, Paused, Closing };

UENUM(BlueprintType)
enum class EDialogueRevealMode : uint8 { Word, Character, Instant };

UENUM(BlueprintType)
enum class EDialogueInteractionMode : uint8 { Modal, Overlay, Cinematic };

UENUM(BlueprintType)
enum class EExistingDialoguePolicy : uint8 { Reject, ReplaceCurrent };

UENUM(BlueprintType)
enum class EDialogueTextSoundTriggerMode : uint8 { PerRevealToken, EveryNCharacters, None };

UENUM(BlueprintType)
enum class EDialogueEndReason : uint8 { Completed, Cancelled, Replaced, InvalidData, WidgetCreationFailed };

UENUM()
enum class EDialogueTokenType : uint8 { Word, Whitespace, Punctuation, Mixed };

USTRUCT(BlueprintType)
struct REUSABLEDIALOGUESYSTEM_API FDialogueLine
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Dialogue") FName LineId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Dialogue") TObjectPtr<UDialogueSpeakerProfile> Speaker = nullptr;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Dialogue") FText SpeakerNameOverride;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Dialogue", meta=(MultiLine=true)) FText DialogueText;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Reveal") EDialogueRevealMode RevealMode = EDialogueRevealMode::Character;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Reveal", meta=(ClampMin="-1.0")) float WordIntervalOverride = -1.f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Reveal", meta=(ClampMin="-1.0")) float CharacterIntervalOverride = -1.f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Timing", meta=(ClampMin="0.0")) float StartDelay = 0.f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Timing", meta=(ClampMin="0.0")) float EndDelay = 0.f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Flow") bool bWaitForPlayerInput = true;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Flow") bool bCanSkipReveal = true;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Flow") bool bAutoAdvance = false;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Flow", meta=(ClampMin="0.0")) float AutoAdvanceDelay = 1.f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio") TObjectPtr<USoundBase> VoiceSound = nullptr;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio") TObjectPtr<UDialogueTextSoundSet> TextSoundSetOverride = nullptr;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio") bool bDisableTextSound = false;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio") EDialogueTextSoundTriggerMode TextSoundTriggerMode = EDialogueTextSoundTriggerMode::PerRevealToken;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio", meta=(ClampMin="-1")) int32 SoundEveryNCharactersOverride = -1;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Audio", meta=(ClampMin="-1.0")) float MinimumTextSoundIntervalOverride = -1.f;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Dialogue") FGameplayTagContainer LineTags;
};

USTRUCT(BlueprintType)
struct REUSABLEDIALOGUESYSTEM_API FDialogueHistoryEntry
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadOnly, Category="Dialogue") FPrimaryAssetId SequenceId;
    UPROPERTY(BlueprintReadOnly, Category="Dialogue") FName LineId;
    UPROPERTY(BlueprintReadOnly, Category="Dialogue") int32 LineIndex = INDEX_NONE;
    UPROPERTY(BlueprintReadOnly, Category="Dialogue") FText SpeakerName;
    UPROPERTY(BlueprintReadOnly, Category="Dialogue") FText DialogueText;
    UPROPERTY(BlueprintReadOnly, Category="Dialogue") FDateTime Timestamp;
    UPROPERTY(BlueprintReadOnly, Category="Dialogue") TObjectPtr<USoundBase> VoiceSound = nullptr;
};

struct REUSABLEDIALOGUESYSTEM_API FDialogueRevealToken
{
    FString Text;
    EDialogueTokenType Type = EDialogueTokenType::Mixed;
    float AdditionalDelay = 0.f;
    bool bCanTriggerSound = false;
};
