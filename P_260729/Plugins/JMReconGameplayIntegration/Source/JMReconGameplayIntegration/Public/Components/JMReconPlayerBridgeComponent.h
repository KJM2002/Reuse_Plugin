#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Types/JMReconTypes.h"
#include "JMReconPlayerBridgeComponent.generated.h"

class ACameraActor;
class APlayerController;
class UInputComponent;
class UJMInteractionComponent;
class UJMReconInteractorComponent;
class UJMReconPromptWidgetBase;
class UJMReconTargetComponent;
class USpotLightComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
    FJMReconFlashlightStateChangedSignature, bool, bEnabled);

/**
 * Consumer-side bridge that reuses JMInteraction focus, binds the project's
 * default Recon keys, and applies camera requests without Blueprint glue.
 */
UCLASS(ClassGroup=(JM), meta=(BlueprintSpawnableComponent), BlueprintType)
class JMRECONGAMEPLAYINTEGRATION_API UJMReconPlayerBridgeComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UJMReconPlayerBridgeComponent();

    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void TickComponent(
        float DeltaTime,
        ELevelTick TickType,
        FActorComponentTickFunction* ThisTickFunction) override;

    UFUNCTION(BlueprintCallable, Category="JM Recon|Integration")
    FJMReconRequestResult TryStartReconFromFocusedTarget();

    UFUNCTION(BlueprintCallable, Category="JM Recon|Integration")
    FJMReconRequestResult TryStartReconWithTarget(UJMReconTargetComponent* Target);

    UFUNCTION(BlueprintPure, Category="JM Recon|Integration")
    UJMReconTargetComponent* FindFocusedReconTarget() const;

    /** Accumulates the shortest per-frame control delta without flipping at +/-180 degrees. */
    static float AccumulateClampedLookAngle(
        float CurrentOffset,
        float PreviousControlAngle,
        float CurrentControlAngle,
        float Limit);

    UPROPERTY(BlueprintAssignable, Category="JM Recon|Integration")
    FJMReconFlashlightStateChangedSignature OnFlashlightStateChanged;

private:
    void CacheComponents();
    void TryBindInput();
    void CreatePromptWidget();
    void UpdatePrompt();
    void ShowFailure(EJMReconFailureReason FailureReason);
    void RestoreFocusPromptSuppression();
    void HandleStartOrFinishInput();
    void HandleIlluminatePressed();
    void HandleIlluminateReleased();
    void HandleExitInput();
    void HandleCancelInput();
    void SetIlluminateInputCaptured(bool bCaptured);
    void ReleaseIlluminateInputWhenSafe();
    void ForcePlayerFlashlightsOff();
    APlayerController* ResolvePlayerController() const;
    UJMReconTargetComponent* FindReconTargetOnActor(AActor* Actor) const;
    bool IsCameraPlacementValid(UJMReconTargetComponent* Target) const;
    void BeginPlayerReturn();
    void BeginCameraReturn(float BlendTime);
    void RestorePlayerState();

    UFUNCTION()
    void HandleFocusedInteractableChanged(UObject* OldInteractable, UObject* NewInteractable);

    UFUNCTION()
    void HandleStateChanged(EJMReconState OldState, EJMReconState NewState);

    UFUNCTION()
    void HandleSessionStarted(FGuid SessionId, UJMReconTargetComponent* Target);

    UFUNCTION()
    void HandleSessionEnded(FGuid SessionId, EJMReconEndReason Reason);

    UFUNCTION()
    void HandleCameraTransformRequested(
        const FTransform& WorldTransform,
        EJMReconState State,
        float BlendTime);

    UFUNCTION()
    void HandleCameraRestoreRequested();

    UFUNCTION()
    void HandleIlluminateRequested(bool bEnabled);

    UPROPERTY(Transient)
    TObjectPtr<UJMInteractionComponent> InteractionComponent;

    UPROPERTY(Transient)
    TObjectPtr<UJMReconInteractorComponent> ReconInteractor;

    UPROPERTY(Transient)
    TObjectPtr<ACameraActor> ReconCameraActor;

    UPROPERTY(Transient)
    TObjectPtr<USpotLightComponent> ReconIlluminateLight;

    UPROPERTY(Transient)
    TObjectPtr<UJMReconPromptWidgetBase> ReconPromptWidget;

    /** Separate high-priority input layer so Recon can exclusively own its flashlight key. */
    UPROPERTY(Transient)
    TObjectPtr<UInputComponent> ReconInputComponent;

    TWeakObjectPtr<AActor> PreviousViewTarget;
    FTransform PeekBaseTransform = FTransform::Identity;
    FTransform AlignmentStartTransform = FTransform::Identity;
    FTransform AlignmentTargetTransform = FTransform::Identity;
    FTransform ReturnStartTransform = FTransform::Identity;
    FRotator PeekControlRotationOrigin = FRotator::ZeroRotator;
    FRotator LastObservedControlRotation = FRotator::ZeroRotator;
    FRotator SavedControlRotation = FRotator::ZeroRotator;
    FTimerHandle InputBindingRetryHandle;
    FTimerHandle PromptFailureTimerHandle;
    float AlignmentElapsed = 0.0f;
    float AlignmentDuration = 0.0f;
    float ReturnElapsed = 0.0f;
    float ReturnDuration = 0.0f;
    float FlashlightCurrentIntensity = 0.0f;
    float FlashlightTargetIntensity = 0.0f;
    float ReconLookYaw = 0.0f;
    float ReconLookPitch = 0.0f;
    int32 IlluminatePressedBindingIndex = INDEX_NONE;
    int32 IlluminateReleasedBindingIndex = INDEX_NONE;
    bool bInputBound = false;
    bool bIlluminateInputCaptured = false;
    bool bAwaitingIlluminateRelease = false;
    bool bAligningPlayer = false;
    bool bReturningPlayer = false;
    bool bPlayerTransformCaptured = false;
    bool bCameraReturnStarted = false;
    bool bMovementLockApplied = false;
    bool bReturnLookLockApplied = false;
    bool bSessionStateCaptured = false;
    bool bFocusPromptSuppressionApplied = false;
    bool bPromptSuppressedBeforeFocus = false;
    bool bFailurePromptActive = false;
    bool bPreviousInteractionEnabled = true;
    bool bPreviousPromptSuppressed = false;
};
