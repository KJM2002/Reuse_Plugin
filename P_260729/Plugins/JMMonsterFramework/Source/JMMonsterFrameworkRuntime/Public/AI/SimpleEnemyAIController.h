#pragma once

#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "SimpleEnemyAIController.generated.h"

/**
 * Minimal controller that tracks whether it currently sees a player-controlled pawn.
 * Movement and behavior systems intentionally belong to later phases.
 */
UCLASS(BlueprintType, Blueprintable)
class JMMONSTERFRAMEWORKRUNTIME_API ASimpleEnemyAIController : public AAIController
{
    GENERATED_BODY()

public:
    ASimpleEnemyAIController();

    /** Player-controlled pawn currently confirmed by AI Sight. */
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "JM Monster Framework|Perception")
    TObjectPtr<AActor> TargetActor = nullptr;

    /** True only while AI Sight currently confirms TargetActor. */
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "JM Monster Framework|Perception")
    bool bCanSeeTarget = false;

private:
    UFUNCTION()
    void HandleTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

    void ApplySightState(AActor* Actor, bool bIsVisible);

#if WITH_DEV_AUTOMATION_TESTS
    friend class FJMSimpleEnemySightStateTransitionsTest;
#endif
};
