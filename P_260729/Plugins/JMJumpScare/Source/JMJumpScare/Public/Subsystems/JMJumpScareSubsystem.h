#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Types/JMJumpScareTypes.h"
#include "JMJumpScareSubsystem.generated.h"

class UAudioComponent;
class UCameraComponent;
class UJMJumpScareDefinition;
class UJMJumpScareOverlayWidget;
class UMaterialInterface;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FJMJumpScareStateChanged, EJMJumpScareState, OldState, EJMJumpScareState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FJMJumpScarePhaseChanged, EJMJumpScarePhase, OldPhase, EJMJumpScarePhase, NewPhase);

/** World-owned service that presents one full-screen 2D JumpScare at a time. */
UCLASS()
class JMJUMPSCARE_API UJMJumpScareSubsystem : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    virtual bool DoesSupportWorldType(EWorldType::Type WorldType) const override;
    virtual void Deinitialize() override;

    EJMJumpScarePlayResult PlayJumpScare(UJMJumpScareDefinition* Definition, const FJMJumpScarePlayContext& Context);

    UFUNCTION(BlueprintCallable, Category="JM JumpScare")
    bool CancelJumpScare();

    UFUNCTION(BlueprintPure, Category="JM JumpScare")
    bool IsJumpScarePlaying() const { return State != EJMJumpScareState::Idle || Phase != EJMJumpScarePhase::Idle || ActiveDefinition != nullptr; }

    UFUNCTION(BlueprintPure, Category="JM JumpScare")
    EJMJumpScareState GetState() const { return State; }

    UFUNCTION(BlueprintPure, Category="JM JumpScare")
    EJMJumpScarePhase GetPhase() const { return Phase; }

    UFUNCTION(BlueprintPure, Category="JM JumpScare")
    FJMJumpScareActiveInfo GetActiveJumpScare() const;

    UFUNCTION(BlueprintCallable, Category="JM JumpScare")
    void ResetOncePolicy(UObject* SourceOrDefinition);

    UPROPERTY(BlueprintAssignable, Category="JM JumpScare")
    FJMJumpScareStateChanged OnStateChanged;

    UPROPERTY(BlueprintAssignable, Category="JM JumpScare")
    FJMJumpScarePhaseChanged OnPhaseChanged;

    /** Deprecated transform helpers kept so existing native callers still compile. */
    static FTransform CalculateCameraRelativeTransform(const FTransform& CameraTransform, float Forward, float Right, float Up, const FRotator& RotationOffset, const FTransform& ActorOffset);
    static FTransform CalculateWorldAnchorTransform(const FTransform& AnchorTransform, const FTransform& ActorOffset);

private:
    UPROPERTY(Transient)
    TObjectPtr<UJMJumpScareDefinition> ActiveDefinition = nullptr;

    UPROPERTY(Transient)
    FJMJumpScarePlayContext ActiveContext;

    UPROPERTY(Transient)
    TObjectPtr<UJMJumpScareOverlayWidget> OverlayWidget = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UAudioComponent> SpawnedAudio = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UAudioComponent> GlitchAudio = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UMaterialInterface> ActiveGlitchMaterial = nullptr;

    UPROPERTY(Transient)
    EJMJumpScareState State = EJMJumpScareState::Idle;

    UPROPERTY(Transient)
    EJMJumpScarePhase Phase = EJMJumpScarePhase::Idle;

    TSet<TWeakObjectPtr<UObject>> TriggeredOnceKeys;
    TWeakObjectPtr<UObject> ActiveOnceKey;
    FTimerHandle StartTimer;
    FTimerHandle SoundTimer;
    FTimerHandle DurationTimer;
    FTimerHandle GlitchTimer;
    TWeakObjectPtr<UCameraComponent> GlitchCamera;
    TWeakObjectPtr<APlayerController> InputLockedPlayer;
    bool bAppliedMoveInputLock = false;
    bool bAppliedLookInputLock = false;

    bool SetState(EJMJumpScareState NewState, uint64 ExpectedSession = 0);
    bool SetPhase(EJMJumpScarePhase NewPhase, uint64 ExpectedSession = 0);
    EJMJumpScarePlayResult ValidateRequest(UJMJumpScareDefinition* Definition, const FJMJumpScarePlayContext& Context) const;
    UObject* ResolveOnceKey(UJMJumpScareDefinition* Definition, const FJMJumpScarePlayContext& Context) const;
    APlayerController* ResolveTargetPlayer(const FJMJumpScarePlayContext& Context) const;
    UCameraComponent* ResolveCameraComponent(APlayerController* Player) const;
    void LockPlayerInput(APlayerController* Player);
    void RestorePlayerInput();
    void ShowOverlay();
    void PlaySound();
    void FinishJumpScare();
    void StartGlitch();
    void CompleteJumpScare();
    void RemoveGlitch();
    void Cleanup(bool bCancelled, bool bFailed, EJMJumpScarePlayResult Result);
    void ClearTimers();
    void PublishEvent(FGameplayTag EventTag, EJMJumpScarePlayResult Result);
    void PruneTriggeredOnceKeys();

    uint64 SessionSerial = 0;
    bool bCleanupInProgress = false;
};
