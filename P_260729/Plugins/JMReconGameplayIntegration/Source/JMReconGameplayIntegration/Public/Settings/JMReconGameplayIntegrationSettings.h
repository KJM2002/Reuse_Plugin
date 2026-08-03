#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "InputCoreTypes.h"
#include "Types/JMInteractionTypes.h"
#include "JMReconGameplayIntegrationSettings.generated.h"

class UJMReconPromptWidgetBase;
class USoundBase;

UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="JM Recon Gameplay Integration"))
class JMRECONGAMEPLAYINTEGRATION_API UJMReconGameplayIntegrationSettings : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    UJMReconGameplayIntegrationSettings();

    UPROPERTY(Config, EditAnywhere, Category="Automatic Setup")
    bool bAutoAddPlayerBridge = true;

    UPROPERTY(Config, EditAnywhere, Category="Automatic Setup")
    bool bAutoBindInput = true;

    UPROPERTY(Config, EditAnywhere, Category="Automatic Setup")
    bool bAutoManageCamera = true;

    UPROPERTY(Config, EditAnywhere, Category="Automatic Setup")
    bool bAutoManageIlluminate = true;

    UPROPERTY(Config, EditAnywhere, Category="Automatic Setup")
    bool bAlignPlayerToTarget = true;

    UPROPERTY(Config, EditAnywhere, Category="Automatic Setup")
    bool bLockMovementDuringRecon = true;

    UPROPERTY(Config, EditAnywhere, Category="Input")
    FKey StartOrFinishKey = EKeys::R;

    /** Display-only key used beside the existing host interaction prompt. */
    UPROPERTY(Config, EditAnywhere, Category="Input")
    FKey InteractionDisplayKey = EKeys::E;

    UPROPERTY(Config, EditAnywhere, Category="Input", meta=(DeprecatedProperty, DeprecationMessage="Peek is entered automatically."))
    FKey PeekKey = EKeys::RightMouseButton;

    UPROPERTY(Config, EditAnywhere, Category="Input")
    FKey IlluminateKey = EKeys::F;

    UPROPERTY(Config, EditAnywhere, Category="Input")
    FKey CancelKey = EKeys::Q;

    UPROPERTY(Config, EditAnywhere, Category="Input")
    FKey ExitKey = EKeys::Escape;

    UPROPERTY(Config, EditAnywhere, Category="Camera", meta=(ClampMin="0.0", Units="s"))
    float RestoreBlendTime = 0.2f;

    UPROPERTY(Config, EditAnywhere, Category="Camera", meta=(ClampMin="0.0"))
    float CameraLookInterpSpeed = 14.0f;

    UPROPERTY(Config, EditAnywhere, Category="Camera", meta=(ClampMin="0.0", ClampMax="170.0", Units="deg"))
    float ReconFieldOfView = 80.0f;

    UPROPERTY(Config, EditAnywhere, Category="Camera|Validation")
    bool bValidateCameraPlacement = true;

    UPROPERTY(Config, EditAnywhere, Category="Camera|Validation", meta=(ClampMin="0.0", Units="cm"))
    float CameraCollisionRadius = 8.0f;

    UPROPERTY(Config, EditAnywhere, Category="Illuminate", AdvancedDisplay, meta=(ClampMin="0.0"))
    float IlluminateIntensity = 5000.0f;

    UPROPERTY(Config, EditAnywhere, Category="Illuminate", AdvancedDisplay, meta=(ClampMin="0.0", Units="cm"))
    float IlluminateAttenuationRadius = 1200.0f;

    UPROPERTY(Config, EditAnywhere, Category="Illuminate", AdvancedDisplay, meta=(ClampMin="1.0", ClampMax="89.0", Units="deg"))
    float IlluminateOuterConeAngle = 32.0f;

    UPROPERTY(Config, EditAnywhere, Category="Illuminate", AdvancedDisplay, meta=(ClampMin="0.0", ClampMax="89.0", Units="deg"))
    float IlluminateInnerConeAngle = 18.0f;

    UPROPERTY(Config, EditAnywhere, Category="Illuminate", AdvancedDisplay)
    FLinearColor IlluminateColor = FLinearColor(1.0f, 0.88f, 0.72f);

    UPROPERTY(Config, EditAnywhere, Category="Illuminate", meta=(ClampMin="0.0", Units="s"))
    float IlluminateFadeDuration = 0.08f;

    UPROPERTY(Config, EditAnywhere, Category="Illuminate", AdvancedDisplay)
    TSoftObjectPtr<USoundBase> FlashlightOnSound;

    UPROPERTY(Config, EditAnywhere, Category="Illuminate", AdvancedDisplay)
    TSoftObjectPtr<USoundBase> FlashlightOffSound;

    UPROPERTY(Config, EditAnywhere, Category="Prompt UI")
    bool bCreateReconPromptWidget = true;

    UPROPERTY(Config, EditAnywhere, Category="Prompt UI")
    TSoftClassPtr<UJMReconPromptWidgetBase> ReconPromptWidgetClass;

    UPROPERTY(Config, EditAnywhere, Category="Prompt UI")
    FJMInteractionPromptStyle ReconPromptStyle;

    /** Supports {0}=interaction key and {1}=recon/start key. */
    UPROPERTY(Config, EditAnywhere, Category="Prompt Text")
    FText FocusedTargetPromptFormat;

    UPROPERTY(Config, EditAnywhere, Category="Prompt Text")
    FText EnteringPrompt;

    /** Supports {0}=flashlight key and {1}=recon/start key. */
    UPROPERTY(Config, EditAnywhere, Category="Prompt Text")
    FText FlashlightActivePromptFormat;

    /** Supports {0}=flashlight key and {1}=recon/start key. */
    UPROPERTY(Config, EditAnywhere, Category="Prompt Text")
    FText ObservingPromptFormat;

    UPROPERTY(Config, EditAnywhere, Category="Prompt Text|Failure")
    FText DoorMovingFailurePrompt;

    UPROPERTY(Config, EditAnywhere, Category="Prompt Text|Failure")
    FText DoorOpenFailurePrompt;

    UPROPERTY(Config, EditAnywhere, Category="Prompt Text|Failure")
    FText BlockedFailurePrompt;

    UPROPERTY(Config, EditAnywhere, Category="Prompt Text|Failure")
    FText OutOfRangeFailurePrompt;

    UPROPERTY(Config, EditAnywhere, Category="Prompt Text|Failure")
    FText GenericFailurePrompt;

    virtual FName GetCategoryName() const override { return TEXT("Plugins"); }
};
