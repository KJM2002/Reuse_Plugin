#pragma once

#include "AI/SimpleEnemyAIController.h"
#include "WatcherEnemyAIController.generated.h"

/** Enemy that moves toward the player only while the player's camera is not watching it. */
UCLASS(BlueprintType, Blueprintable)
class JMMONSTERFRAMEWORKRUNTIME_API AWatcherEnemyAIController : public ASimpleEnemyAIController
{
    GENERATED_BODY()

public:
    AWatcherEnemyAIController();

    virtual void OnPossess(APawn* InPawn) override;
    virtual void Tick(float DeltaSeconds) override;

    /** Fraction of the camera half-screen, from center (0) to edge (1), accepted as watched. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "JM Monster Framework|Watcher", meta = (ClampMin = "0.1", ClampMax = "1.0"))
    float GazeScreenEdgeFraction = 0.85f;

    /** Prevents a single unstable frame from releasing a watched Watcher. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "JM Monster Framework|Watcher", meta = (ClampMin = "0.0", ClampMax = "0.5"))
    float GazeLostGraceDuration = 0.12f;

    /** Result of the actual camera angle and Visibility trace evaluated this frame. */
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "JM Monster Framework|Watcher")
    bool bPlayerIsWatchingWatcher = false;

    /** Returns the player Pawn used by both Gaze evaluation and Watcher movement. */
    APawn* GetGazePlayerPawn() const;

private:
    void UpdatePlayerGaze(float DeltaSeconds);

    float GazeLostElapsedTime = 0.0f;

#if WITH_DEV_AUTOMATION_TESTS
    friend class FJMWatcherEnemyAssetsTest;
#endif
};
