#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Types/JMReconTypes.h"
#include "JMReconInteractorComponent.generated.h"

class USoundMix;
class UJMReconDefinition;
class UJMReconTargetComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FJMReconStateChangedSignature, EJMReconState, OldState, EJMReconState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FJMReconSessionStartedSignature, FGuid, SessionId, UJMReconTargetComponent*, Target);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FJMReconSessionEndedSignature, FGuid, SessionId, EJMReconEndReason, Reason);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJMReconIlluminateRequestedSignature, bool, bEnabled);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJMReconNoiseGeneratedSignature, const FJMReconNoiseEvent&, Noise);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FJMReconCameraRequestedSignature, const FTransform&, WorldTransform, EJMReconState, State, float, BlendTime);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FJMReconCameraRestoreRequestedSignature);

UCLASS(ClassGroup=(JM), meta=(BlueprintSpawnableComponent), BlueprintType)
class JMRECONRUNTIME_API UJMReconInteractorComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UJMReconInteractorComponent();

    UPROPERTY(BlueprintAssignable, Category="JM Recon|Events")
    FJMReconStateChangedSignature OnStateChanged;

    UPROPERTY(BlueprintAssignable, Category="JM Recon|Events")
    FJMReconSessionStartedSignature OnSessionStarted;

    UPROPERTY(BlueprintAssignable, Category="JM Recon|Events")
    FJMReconSessionEndedSignature OnSessionEnded;

    UPROPERTY(BlueprintAssignable, Category="JM Recon|Events")
    FJMReconIlluminateRequestedSignature OnIlluminateRequested;

    UPROPERTY(BlueprintAssignable, Category="JM Recon|Events")
    FJMReconNoiseGeneratedSignature OnNoiseGenerated;

    UPROPERTY(BlueprintAssignable, Category="JM Recon|Camera")
    FJMReconCameraRequestedSignature OnCameraTransformRequested;

    UPROPERTY(BlueprintAssignable, Category="JM Recon|Camera")
    FJMReconCameraRestoreRequestedSignature OnCameraRestoreRequested;

    UFUNCTION(BlueprintCallable, Category="JM Recon")
    FJMReconRequestResult TryStartRecon(UJMReconTargetComponent* Target);

    UFUNCTION(BlueprintCallable, Category="JM Recon")
    FJMReconRequestResult StartListen();

    UFUNCTION(BlueprintCallable, Category="JM Recon")
    FJMReconRequestResult StopListen();

    UFUNCTION(BlueprintCallable, Category="JM Recon")
    FJMReconRequestResult StartPeek();

    UFUNCTION(BlueprintCallable, Category="JM Recon")
    FJMReconRequestResult StopPeek();

    UFUNCTION(BlueprintCallable, Category="JM Recon")
    FJMReconRequestResult SetIlluminate(bool bEnabled);

    UFUNCTION(BlueprintCallable, Category="JM Recon")
    FJMReconRequestResult CancelRecon();

    UFUNCTION(BlueprintCallable, Category="JM Recon")
    FJMReconRequestResult FinishRecon();

    UFUNCTION(BlueprintPure, Category="JM Recon")
    EJMReconState GetCurrentState() const { return ActiveSession.CurrentState; }

    UFUNCTION(BlueprintPure, Category="JM Recon")
    FGuid GetSessionId() const { return ActiveSession.SessionId; }

    UFUNCTION(BlueprintPure, Category="JM Recon")
    bool IsReconActive() const { return ActiveSession.IsActive(); }

    UFUNCTION(BlueprintPure, Category="JM Recon")
    bool IsIlluminating() const { return ActiveSession.bIsIlluminating; }

    UFUNCTION(BlueprintPure, Category="JM Recon")
    UJMReconTargetComponent* GetCurrentTarget() const { return ActiveSession.Target.Get(); }

    UFUNCTION(BlueprintPure, Category="JM Recon|Debug")
    EJMReconFailureReason GetLastFailureReason() const { return LastFailureReason; }

    UFUNCTION(BlueprintPure, Category="JM Recon|Debug")
    FString GetDebugStatus() const;

protected:
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
    void CompleteEntering(FGuid ExpectedSessionId);
    void CompleteExit(FGuid ExpectedSessionId, EJMReconEndReason Reason);
    void TransitionTo(EJMReconState NewState);
    void EnterListening();
    void LeaveListening();
    void EnterPeeking();
    void LeavePeeking();
    void BeginExit(EJMReconEndReason Reason);
    void EndActiveReconSession(EJMReconEndReason Reason);
    void EmitNoise(float Loudness, FName Type);
    void ScheduleTransition(float Delay, TFunction<void()> Callback);
    UObject* ResolveTargetContract(AActor* TargetActor) const;
    UObject* GetActiveTargetContract() const;
    bool IsCurrentSession(const FGuid& ExpectedSessionId, EJMReconState ExpectedState) const;
    FJMReconRequestResult Fail(EJMReconFailureReason Reason);

    UFUNCTION()
    void HandleTargetDestroyed(AActor* DestroyedActor);

    FJMReconSession ActiveSession;
    EJMReconFailureReason LastFailureReason = EJMReconFailureReason::None;
    FTimerHandle TransitionTimer;
    EJMReconEndReason PendingEndReason = EJMReconEndReason::Completed;

    UPROPERTY(Transient)
    TObjectPtr<USoundMix> ActiveListenSoundMix = nullptr;
};
