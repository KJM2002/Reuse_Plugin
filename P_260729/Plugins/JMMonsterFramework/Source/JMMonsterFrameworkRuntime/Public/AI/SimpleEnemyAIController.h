#pragma once

#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "UObject/SoftObjectPtr.h"
#include "SimpleEnemyAIController.generated.h"

class UStateTree;
class UStateTreeAIComponent;
class UAISenseConfig_Hearing;

/** Runtime perception and tracking facts owned by one enemy. Contains no behavior decisions. */
USTRUCT(BlueprintType)
struct JMMONSTERFRAMEWORKRUNTIME_API FJMSimpleEnemyMemory
{
    GENERATED_BODY()

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sight")
    TObjectPtr<AActor> TargetActor = nullptr;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sight")
    bool bCanSeeTarget = false;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sight")
    FVector LastSeenLocation = FVector::ZeroVector;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sight")
    FVector LastSeenVelocity = FVector::ZeroVector;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sight")
    float LastSeenTime = 0.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Predictive Tracking")
    FVector EstimatedTrackingLocation = FVector::ZeroVector;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Predictive Tracking")
    bool bHasRecentTrackingMemory = false;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Live Grace Tracking")
    TWeakObjectPtr<AActor> LiveGraceTargetActor;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Live Grace Tracking")
    bool bHasLiveGraceTracking = false;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Hearing")
    FVector LastHeardLocation = FVector::ZeroVector;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Hearing")
    bool bHasHeardSound = false;
};

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

    /** Single owner of the perception and tracking facts currently used by the enemy. */
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "JM Monster Framework|Memory")
    FJMSimpleEnemyMemory EnemyMemory;

    /** Short window in which RecentTracking follows its cached prediction. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "JM Monster Framework|Tracking", meta = (ClampMin = "0.0"))
    float TrackingMemoryDuration = 1.5f;

    /** Prevents a fast final observation from producing an excessive prediction. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "JM Monster Framework|Tracking", meta = (ClampMin = "0.0"))
    float MaximumPredictionDistance = 700.0f;

    /** Maximum time the Live Grace StateTree may follow the hidden player's live position. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "JM Monster Framework|Live Grace", meta = (ClampMin = "0.0"))
    float LiveGraceDuration = 1.5f;

    /** Updates LastSeenLocation from the live target only while Live Grace is valid. */
    bool UpdateLiveGraceLastKnownLocation();

    /** Irreversibly stops live target access for the current sight-loss event. */
    void EndLiveGraceTracking();

    /** Maximum distance at which the visible player can be attacked. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "JM Monster Framework|Attack", meta = (ClampMin = "0.0"))
    float AttackRange = 150.0f;

    /** Minimum time between consecutive basic attacks. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "JM Monster Framework|Attack", meta = (ClampMin = "0.01"))
    float AttackCooldown = 1.0f;

    /** Damage passed to the visible player for each successful basic attack. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "JM Monster Framework|Attack", meta = (ClampMin = "0.0"))
    float Damage = 10.0f;

    /** World time of the last successful hit; persists across Attack/Chase transitions. */
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "JM Monster Framework|Attack")
    float LastBasicAttackTime = -1.0f;

    /** True only when the currently visible player is within AttackRange. */
    bool IsTargetInAttackRange() const;

    /** Applies one basic attack to the currently visible in-range player. */
    bool PerformBasicAttack();

    /** Clears the single pending sound after investigation or Sight preemption. */
    void ClearHeardSound();

protected:
    /** Native Hearing config reapplied on possess so stale Blueprint SensesConfig overrides cannot remove it. */
    UPROPERTY(VisibleAnywhere, Category = "JM Monster Framework|Hearing")
    TObjectPtr<UAISenseConfig_Hearing> HearingConfig;

    UPROPERTY(VisibleAnywhere, Category = "JM Monster Framework|StateTree")
    TObjectPtr<UStateTreeAIComponent> StateTreeComponent;

    UPROPERTY(EditDefaultsOnly, Category = "JM Monster Framework|StateTree")
    TSoftObjectPtr<UStateTree> StateTreeAsset;

private:

    UFUNCTION()
    void HandleTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

    void ApplySightState(
        AActor* Actor,
        bool bIsVisible,
        const FVector& ObservedLocation,
        const FVector& ObservedVelocity);

    void ApplyHearingState(
        AActor* Actor,
        bool bWasSuccessfullySensed,
        const FVector& HeardLocation,
        float Strength = 1.0f);

    void UpdateVisibleObservation(AActor& VisibleActor, const FVector& ObservedLocation);

#if WITH_DEV_AUTOMATION_TESTS
    friend class FJMSimpleEnemySightStateTransitionsTest;
    friend class FJMSimpleEnemyStateTreeAssetTest;
    friend class FJMSimpleEnemyLiveGraceAssetsTest;
    friend class FJMSimpleEnemyLiveGraceStateTest;
    friend class FJMSimpleEnemyHearingStateTest;
    friend class FJMSimpleEnemyMemoryRuntimeTest;
    friend class FJMListenerEnemyAssetsTest;
#endif
};
