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

    /** Player-controlled pawn currently confirmed by AI Sight. */
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "JM Monster Framework|Perception")
    TObjectPtr<AActor> TargetActor = nullptr;

    /** True only while AI Sight currently confirms TargetActor. */
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "JM Monster Framework|Perception")
    bool bCanSeeTarget = false;

    /** Most recent location reported by AI Sight for the current/previous player target. */
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "JM Monster Framework|Perception")
    FVector LastSeenLocation = FVector::ZeroVector;

private:
    UPROPERTY(VisibleAnywhere, Category = "JM Monster Framework|StateTree")
    TObjectPtr<UStateTreeAIComponent> StateTreeComponent;

    UPROPERTY(EditDefaultsOnly, Category = "JM Monster Framework|StateTree")
    TSoftObjectPtr<UStateTree> StateTreeAsset;

    UFUNCTION()
    void HandleTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

    void ApplySightState(AActor* Actor, bool bIsVisible, const FVector& ObservedLocation);

#if WITH_DEV_AUTOMATION_TESTS
    friend class FJMSimpleEnemySightStateTransitionsTest;
    friend class FJMSimpleEnemyStateTreeAssetTest;
#endif
};
