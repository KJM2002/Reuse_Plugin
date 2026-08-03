#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ReusableDialogueTypes.h"
#include "DialogueSettings.generated.h"

class UDialogueWidgetBase;
class UDialogueTextSoundSet;

UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="Dialogue", ToolTip="Configure the reusable JM dialogue system."))
class REUSABLEDIALOGUESYSTEM_API UDialogueSettings : public UDeveloperSettings
{
    GENERATED_BODY()
public:
    UDialogueSettings();
    virtual FName GetCategoryName() const override { return TEXT("JM Plugins"); }

    UPROPERTY(Config, EditAnywhere, Category="UI") TSoftClassPtr<UDialogueWidgetBase> DefaultDialogueWidgetClass;
    UPROPERTY(Config, EditAnywhere, Category="Reveal") EDialogueRevealMode DefaultRevealMode = EDialogueRevealMode::Character;
    /** Keeps previously-authored Word lines on character reveal. Instant lines remain instant. */
    UPROPERTY(Config, EditAnywhere, Category="Reveal") bool bForceCharacterReveal = true;
    UPROPERTY(Config, EditAnywhere, Category="Reveal", meta=(ClampMin="0.001")) float DefaultWordInterval = .12f;
    UPROPERTY(Config, EditAnywhere, Category="Reveal", meta=(ClampMin="0.001")) float DefaultCharacterInterval = .035f;
    UPROPERTY(Config, EditAnywhere, Category="Reveal|Smoothing") bool bSmoothCharacterReveal = true;
    UPROPERTY(Config, EditAnywhere, Category="Reveal|Smoothing", meta=(ClampMin="0.001", ClampMax="0.25")) float CharacterRevealBlendDuration = .03f;
    UPROPERTY(Config, EditAnywhere, Category="Reveal|Smoothing", meta=(ClampMin="0.0", ClampMax="1.0")) float CharacterRevealStartOpacity = .9f;
    UPROPERTY(Config, EditAnywhere, Category="Reveal", meta=(ClampMin="0.0")) float CommaDelay = .12f;
    UPROPERTY(Config, EditAnywhere, Category="Reveal", meta=(ClampMin="0.0")) float SentenceEndDelay = .25f;
    UPROPERTY(Config, EditAnywhere, Category="Reveal", meta=(ClampMin="0.0")) float EllipsisDelay = .4f;
    UPROPERTY(Config, EditAnywhere, Category="Reveal", meta=(ClampMin="0.0")) float NewLineDelay = .15f;
    UPROPERTY(Config, EditAnywhere, Category="Flow") EDialogueInteractionMode DefaultInteractionMode = EDialogueInteractionMode::Modal;
    UPROPERTY(Config, EditAnywhere, Category="Flow") EExistingDialoguePolicy DefaultExistingDialoguePolicy = EExistingDialoguePolicy::Reject;
    UPROPERTY(Config, EditAnywhere, Category="Input") bool bAllowMouseAdvance = true;
    UPROPERTY(Config, EditAnywhere, Category="Input") bool bAllowKeyboardAdvance = true;
    UPROPERTY(Config, EditAnywhere, Category="Input") bool bAllowGamepadAdvance = true;
    UPROPERTY(Config, EditAnywhere, Category="Input", meta=(ClampMin="0.0")) float InputDebounceTime = .08f;
    UPROPERTY(Config, EditAnywhere, Category="Audio") TSoftObjectPtr<UDialogueTextSoundSet> DefaultTextSoundSet;
    UPROPERTY(Config, EditAnywhere, Category="Audio", meta=(ClampMin="0.0")) float DefaultTextSoundVolume = 1.f;
    UPROPERTY(Config, EditAnywhere, Category="Audio", meta=(ClampMin="0.01")) float DefaultTextSoundPitchMin = .96f;
    UPROPERTY(Config, EditAnywhere, Category="Audio", meta=(ClampMin="0.01")) float DefaultTextSoundPitchMax = 1.04f;
    UPROPERTY(Config, EditAnywhere, Category="Audio", meta=(ClampMin="0.0")) float DefaultMinimumTextSoundInterval = .05f;
    UPROPERTY(Config, EditAnywhere, Category="Audio", meta=(ClampMin="1")) int32 DefaultSoundEveryNCharacters = 2;
    UPROPERTY(Config, EditAnywhere, Category="UI", meta=(ClampMin="0.1")) float DefaultTextScale = 1.f;
};
