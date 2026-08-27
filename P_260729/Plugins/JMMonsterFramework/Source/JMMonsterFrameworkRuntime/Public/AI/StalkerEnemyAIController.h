#pragma once

#include "AI/SimpleEnemyAIController.h"
#include "StalkerEnemyAIController.generated.h"

UENUM(BlueprintType)
enum class EJMStalkerDistanceBand : uint8
{
    None,
    TooClose,
    Preferred,
    TooFar
};

/** Sight-driven enemy that follows the player while preserving a preferred distance band. */
UCLASS(BlueprintType, Blueprintable)
class JMMONSTERFRAMEWORKRUNTIME_API AStalkerEnemyAIController : public ASimpleEnemyAIController
{
    GENERATED_BODY()

public:
    AStalkerEnemyAIController();

    virtual void OnPossess(APawn* InPawn) override;
    virtual void Tick(float DeltaSeconds) override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "JM Monster Framework|Stalker", meta = (ClampMin = "0.0"))
    float MinimumFollowDistance = 450.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "JM Monster Framework|Stalker", meta = (ClampMin = "0.0"))
    float MaximumFollowDistance = 750.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "JM Monster Framework|Stalker", meta = (ClampMin = "0.0"))
    float DistanceHysteresis = 75.0f;

    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "JM Monster Framework|Stalker")
    float CurrentTargetDistance = 0.0f;

    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "JM Monster Framework|Stalker")
    EJMStalkerDistanceBand CurrentDistanceBand = EJMStalkerDistanceBand::None;

private:
    void UpdateDistanceBand();

#if WITH_DEV_AUTOMATION_TESTS
    friend class FJMStalkerEnemyAssetsTest;
#endif
};
