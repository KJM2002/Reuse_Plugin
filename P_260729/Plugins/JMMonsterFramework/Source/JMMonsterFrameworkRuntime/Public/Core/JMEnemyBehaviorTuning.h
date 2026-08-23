#pragma once

#include "CoreMinimal.h"
#include "JMEnemyBehaviorTuning.generated.h"

/** Designer-owned timings shared by StateTree reference behaviors. No enemy identity is encoded here. */
USTRUCT(BlueprintType)
struct JMMONSTERFRAMEWORKRUNTIME_API FJMEnemyBehaviorTuning
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Patrol", meta=(ClampMin="0.0"))
    float PatrolMinWaitTime = 0.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Patrol", meta=(ClampMin="0.0"))
    float PatrolMaxWaitTime = 0.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Detection", meta=(ClampMin="0.0"))
    float AcquireGraceTime = 0.35f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Lost Target", meta=(ClampMin="0.0"))
    float LostSightPursuitDuration = 5.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Lost Target", meta=(ClampMin="0.0"))
    float LostSightGraceTime = 0.35f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Search", meta=(ClampMin="0.0"))
    float LastKnownLocationPause = 3.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Search", meta=(ClampMin="0.0"))
    float SearchDuration = 5.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Search", meta=(ClampMin="1", ClampMax="8"))
    int32 SearchPointCount = 2;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Search", meta=(ClampMin="1.0"))
    float SearchRadius = 600.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Hearing", meta=(ClampMin="0.0"))
    float StrongHearingStrength = 0.85f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Hearing", meta=(ClampMin="0.0"))
    float HearingRefreshMinimumDistance = 75.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Hearing", meta=(ClampMin="0.0"))
    float HearingRefreshMinimumInterval = 0.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Crawler", meta=(ClampMin="0.0"))
    float HideMinimumDuration = 0.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Crawler", meta=(ClampMin="0.0"))
    float FrenzySearchDuration = 8.0f;
};
