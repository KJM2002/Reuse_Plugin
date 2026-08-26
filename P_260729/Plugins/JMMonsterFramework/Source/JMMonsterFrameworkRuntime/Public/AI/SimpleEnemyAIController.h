#pragma once

#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "UObject/SoftObjectPtr.h"
#include "SimpleEnemyAIController.generated.h"

class UStateTree;
class UStateTreeAIComponent;

/**
 * Minimal controller that chases a visible player and investigates the last sight location.
 */
UCLASS(BlueprintType, Blueprintable)
class JMMONSTERFRAMEWORKRUNTIME_API ASimpleEnemyAIController : public AAIController
{
    GENERATED_BODY()

public:
    ASimpleEnemyAIController();

    virtual void OnPossess(APawn* InPawn) override;
    virtual void Tick(float DeltaSeconds) override;

    /** Player-controlled pawn currently confirmed by AI Sight. */
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "JM Monster Framework|Perception")
    TObjectPtr<AActor> TargetActor = nullptr;

    /** True only while AI Sight currently confirms TargetActor. */
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "JM Monster Framework|Perception")
    bool bCanSeeTarget = false;

    /** Most recent location reported by AI Sight for the current/previous player target. */
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "JM Monster Framework|Perception")
    FVector LastSeenLocation = FVector::ZeroVector;

    /** Velocity sampled only while AI Sight confirms the player is visible. */
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "JM Monster Framework|Perception")
    FVector LastSeenVelocity = FVector::ZeroVector;

    /** World time of the most recent visible observation. */
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "JM Monster Framework|Perception")
    float LastSeenTime = 0.0f;

    /** One-shot destination predicted from the final visible location and velocity. */
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "JM Monster Framework|Tracking")
    FVector EstimatedTrackingLocation = FVector::ZeroVector;

    /** Short window in which RecentTracking follows its cached prediction. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "JM Monster Framework|Tracking", meta = (ClampMin = "0.0"))
    float TrackingMemoryDuration = 1.5f;

    /** Prevents a fast final observation from producing an excessive prediction. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "JM Monster Framework|Tracking", meta = (ClampMin = "0.0"))
    float MaximumPredictionDistance = 700.0f;

    /** True between a confirmed sight loss and RecentTracking expiry/reacquisition. */
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "JM Monster Framework|Tracking")
    bool bHasRecentTrackingMemory = false;

    /** Player retained only for the independently selected Live Grace StateTree. */
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "JM Monster Framework|Live Grace")
    TWeakObjectPtr<AActor> LiveGraceTargetActor;

    /** Maximum time the Live Grace StateTree may follow the hidden player's live position. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "JM Monster Framework|Live Grace", meta = (ClampMin = "0.0"))
    float LiveGraceDuration = 1.5f;

    /** True after sight loss until reacquisition or explicit Live Grace expiry. */
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "JM Monster Framework|Live Grace")
    bool bHasLiveGraceTracking = false;

    /** Updates LastSeenLocation from the live target only while Live Grace is valid. */
    bool UpdateLiveGraceLastKnownLocation();

    /** Irreversibly stops live target access for the current sight-loss event. */
    void EndLiveGraceTracking();

private:
    UPROPERTY(VisibleAnywhere, Category = "JM Monster Framework|StateTree")
    TObjectPtr<UStateTreeAIComponent> StateTreeComponent;

    UPROPERTY(EditDefaultsOnly, Category = "JM Monster Framework|StateTree")
    TSoftObjectPtr<UStateTree> StateTreeAsset;

    UFUNCTION()
    void HandleTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

    void ApplySightState(
        AActor* Actor,
        bool bIsVisible,
        const FVector& ObservedLocation,
        const FVector& ObservedVelocity);

    void UpdateVisibleObservation(AActor& VisibleActor, const FVector& ObservedLocation);

#if WITH_DEV_AUTOMATION_TESTS
    friend class FJMSimpleEnemySightStateTransitionsTest;
    friend class FJMSimpleEnemyStateTreeAssetTest;
    friend class FJMSimpleEnemyLiveGraceAssetsTest;
    friend class FJMSimpleEnemyLiveGraceStateTest;
#endif
};
