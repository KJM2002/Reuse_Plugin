#pragma once

#include "Conditions/StateTreeAIConditionBase.h"
#include "Tasks/StateTreeAITask.h"
#include "SimpleEnemyStateTreeNodes.generated.h"

struct FStateTreeExecutionContext;
struct FStateTreeTransitionResult;
class ASimpleEnemyAIController;

/** Per-execution storage required by StateTree for the sight condition. */
USTRUCT()
struct FJMSimpleEnemyCanSeeTargetInstanceData
{
    GENERATED_BODY()
};

/** Per-execution storage required by the recent tracking condition. */
USTRUCT()
struct FJMSimpleEnemyHasRecentTrackingMemoryInstanceData
{
    GENERATED_BODY()
};

/** Per-execution storage required by the Live Grace condition. */
USTRUCT()
struct FJMSimpleEnemyHasLiveGraceTrackingInstanceData
{
    GENERATED_BODY()
};

/** Per-execution storage required by the pending sound condition. */
USTRUCT()
struct FJMSimpleEnemyHasHeardSoundInstanceData
{
    GENERATED_BODY()
};

/** Per-execution storage required by StateTree for the chase task. */
USTRUCT()
struct FJMSimpleEnemyMoveToTargetInstanceData
{
    GENERATED_BODY()
};

/** Runtime timer for the short cached-prediction movement. */
USTRUCT()
struct FJMSimpleEnemyRecentTrackingInstanceData
{
    GENERATED_BODY()

    UPROPERTY(Transient)
    float ElapsedTime = 0.0f;
};

/** Runtime timer for live target access after sight loss. */
USTRUCT()
struct FJMSimpleEnemyLiveGraceTrackingInstanceData
{
    GENERATED_BODY()

    UPROPERTY(Transient)
    float ElapsedTime = 0.0f;
};

/** Per-execution wait state between NavMesh patrol moves. */
USTRUCT()
struct FJMSimpleEnemyPatrolInstanceData
{
    GENERATED_BODY()

    UPROPERTY(Transient)
    float ElapsedWaitTime = 0.0f;

    UPROPERTY(Transient)
    bool bWaiting = false;
};

/** Per-execution cooldown for repeated basic attacks. */
USTRUCT()
struct FJMSimpleEnemyBasicAttackInstanceData
{
    GENERATED_BODY()
};

/** Per-execution storage required by the one-shot sound investigation. */
USTRUCT()
struct FJMSimpleEnemyInvestigateSoundInstanceData
{
    GENERATED_BODY()

    UPROPERTY(Transient)
    FVector ActiveSoundLocation = FVector::ZeroVector;
};

/** Per-execution storage required by StateTree for the investigation task. */
USTRUCT()
struct FJMSimpleEnemyMoveToLastSeenLocationInstanceData
{
    GENERATED_BODY()
};

/** Runtime timer for the finite in-place search. */
USTRUCT()
struct FJMSimpleEnemySearchInstanceData
{
    GENERATED_BODY()

    UPROPERTY(Transient)
    float ElapsedTime = 0.0f;
};

/** Selects a state when the owning SimpleEnemy controller's sight flag matches the expected value. */
USTRUCT(meta = (DisplayName = "Can See Target", Category = "JM Monster Framework"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMSimpleEnemyCanSeeTargetCondition : public FStateTreeAIConditionBase
{
    GENERATED_BODY()

    using FInstanceDataType = FJMSimpleEnemyCanSeeTargetInstanceData;

    virtual const UStruct* GetInstanceDataType() const override
    {
        return FInstanceDataType::StaticStruct();
    }

    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;

    UPROPERTY(EditAnywhere, Category = "Condition")
    bool bExpectedValue = true;
};

/** Moves the controlled pawn toward the controller's live TargetActor through navigation. */
USTRUCT(meta = (DisplayName = "Move To TargetActor", Category = "JM Monster Framework"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMSimpleEnemyMoveToTargetTask : public FStateTreeAIActionTaskBase
{
    GENERATED_BODY()

    using FInstanceDataType = FJMSimpleEnemyMoveToTargetInstanceData;

    FJMSimpleEnemyMoveToTargetTask();

    virtual const UStruct* GetInstanceDataType() const override
    {
        return FInstanceDataType::StaticStruct();
    }

    virtual EStateTreeRunStatus EnterState(
        FStateTreeExecutionContext& Context,
        const FStateTreeTransitionResult& Transition) const override;

    virtual EStateTreeRunStatus Tick(
        FStateTreeExecutionContext& Context,
        float DeltaTime) const override;

    virtual void ExitState(
        FStateTreeExecutionContext& Context,
        const FStateTreeTransitionResult& Transition) const override;

    UPROPERTY(EditAnywhere, Category = "Movement", meta = (ClampMin = "0.0"))
    float AcceptanceRadius = 75.0f;
};

/** Selects Attack or Chase according to the visible target's current distance. */
USTRUCT(meta = (DisplayName = "Target In Attack Range", Category = "JM Monster Framework"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMSimpleEnemyTargetInAttackRangeCondition
    : public FStateTreeAIConditionBase
{
    GENERATED_BODY()

    using FInstanceDataType = FJMSimpleEnemyCanSeeTargetInstanceData;

    virtual const UStruct* GetInstanceDataType() const override
    {
        return FInstanceDataType::StaticStruct();
    }

    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;

    UPROPERTY(EditAnywhere, Category = "Condition")
    bool bExpectedValue = true;
};

/** Selects RecentTracking only after a confirmed sight loss created a prediction snapshot. */
USTRUCT(meta = (DisplayName = "Has Recent Tracking Memory", Category = "JM Monster Framework"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMSimpleEnemyHasRecentTrackingMemoryCondition
    : public FStateTreeAIConditionBase
{
    GENERATED_BODY()

    using FInstanceDataType = FJMSimpleEnemyHasRecentTrackingMemoryInstanceData;

    virtual const UStruct* GetInstanceDataType() const override
    {
        return FInstanceDataType::StaticStruct();
    }

    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;
};

/** Selects LiveGraceTracking only for a valid, unexpired live target reference. */
USTRUCT(meta = (DisplayName = "Has Live Grace Tracking", Category = "JM Monster Framework"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMSimpleEnemyHasLiveGraceTrackingCondition
    : public FStateTreeAIConditionBase
{
    GENERATED_BODY()

    using FInstanceDataType = FJMSimpleEnemyHasLiveGraceTrackingInstanceData;

    virtual const UStruct* GetInstanceDataType() const override
    {
        return FInstanceDataType::StaticStruct();
    }

    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;
};

/** Selects sound investigation only when Sight is not currently active. */
USTRUCT(meta = (DisplayName = "Has Heard Sound", Category = "JM Monster Framework"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMSimpleEnemyHasHeardSoundCondition
    : public FStateTreeAIConditionBase
{
    GENERATED_BODY()

    using FInstanceDataType = FJMSimpleEnemyHasHeardSoundInstanceData;

    virtual const UStruct* GetInstanceDataType() const override
    {
        return FInstanceDataType::StaticStruct();
    }

    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;
};

/** Moves toward the prediction snapshot created at sight loss without reading the hidden Actor. */
USTRUCT(meta = (DisplayName = "Recent Tracking", Category = "JM Monster Framework"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMSimpleEnemyRecentTrackingTask : public FStateTreeAIActionTaskBase
{
    GENERATED_BODY()

    using FInstanceDataType = FJMSimpleEnemyRecentTrackingInstanceData;

    FJMSimpleEnemyRecentTrackingTask();

    virtual const UStruct* GetInstanceDataType() const override
    {
        return FInstanceDataType::StaticStruct();
    }

    virtual EStateTreeRunStatus EnterState(
        FStateTreeExecutionContext& Context,
        const FStateTreeTransitionResult& Transition) const override;

    virtual EStateTreeRunStatus Tick(
        FStateTreeExecutionContext& Context,
        float DeltaTime) const override;

    virtual void ExitState(
        FStateTreeExecutionContext& Context,
        const FStateTreeTransitionResult& Transition) const override;

    UPROPERTY(EditAnywhere, Category = "Movement", meta = (ClampMin = "0.0"))
    float AcceptanceRadius = 75.0f;
};

/** Follows the hidden player's live Actor only until the configured grace duration expires. */
USTRUCT(meta = (DisplayName = "Live Grace Tracking", Category = "JM Monster Framework"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMSimpleEnemyLiveGraceTrackingTask : public FStateTreeAIActionTaskBase
{
    GENERATED_BODY()

    using FInstanceDataType = FJMSimpleEnemyLiveGraceTrackingInstanceData;

    FJMSimpleEnemyLiveGraceTrackingTask();

    virtual const UStruct* GetInstanceDataType() const override
    {
        return FInstanceDataType::StaticStruct();
    }

    virtual EStateTreeRunStatus EnterState(
        FStateTreeExecutionContext& Context,
        const FStateTreeTransitionResult& Transition) const override;

    virtual EStateTreeRunStatus Tick(
        FStateTreeExecutionContext& Context,
        float DeltaTime) const override;

    virtual void ExitState(
        FStateTreeExecutionContext& Context,
        const FStateTreeTransitionResult& Transition) const override;

    UPROPERTY(EditAnywhere, Category = "Movement", meta = (ClampMin = "0.0"))
    float AcceptanceRadius = 75.0f;
};

/** Repeatedly visits random reachable NavMesh points and waits briefly at each destination. */
USTRUCT(meta = (DisplayName = "Patrol NavMesh Area", Category = "JM Monster Framework"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMSimpleEnemyPatrolTask : public FStateTreeAIActionTaskBase
{
    GENERATED_BODY()

    using FInstanceDataType = FJMSimpleEnemyPatrolInstanceData;

    FJMSimpleEnemyPatrolTask();

    virtual const UStruct* GetInstanceDataType() const override
    {
        return FInstanceDataType::StaticStruct();
    }

    virtual EStateTreeRunStatus EnterState(
        FStateTreeExecutionContext& Context,
        const FStateTreeTransitionResult& Transition) const override;

    virtual EStateTreeRunStatus Tick(
        FStateTreeExecutionContext& Context,
        float DeltaTime) const override;

    virtual void ExitState(
        FStateTreeExecutionContext& Context,
        const FStateTreeTransitionResult& Transition) const override;

    UPROPERTY(EditAnywhere, Category = "Patrol", meta = (ClampMin = "0.0"))
    float PatrolRadius = 800.0f;

    UPROPERTY(EditAnywhere, Category = "Patrol", meta = (ClampMin = "0.0"))
    float AcceptanceRadius = 75.0f;

    UPROPERTY(EditAnywhere, Category = "Patrol", meta = (ClampMin = "0.0"))
    float WaitDuration = 1.5f;

private:
    bool RequestPatrolMove(ASimpleEnemyAIController& Controller) const;
};

/** Stops movement and applies one basic attack per controller cooldown while valid. */
USTRUCT(meta = (DisplayName = "Basic Attack", Category = "JM Monster Framework"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMSimpleEnemyBasicAttackTask : public FStateTreeAIActionTaskBase
{
    GENERATED_BODY()

    using FInstanceDataType = FJMSimpleEnemyBasicAttackInstanceData;

    FJMSimpleEnemyBasicAttackTask();

    virtual const UStruct* GetInstanceDataType() const override
    {
        return FInstanceDataType::StaticStruct();
    }

    virtual EStateTreeRunStatus EnterState(
        FStateTreeExecutionContext& Context,
        const FStateTreeTransitionResult& Transition) const override;

    virtual EStateTreeRunStatus Tick(
        FStateTreeExecutionContext& Context,
        float DeltaTime) const override;
};

/** Moves once to the remembered hearing location, then consumes it. */
USTRUCT(meta = (DisplayName = "Investigate Heard Sound", Category = "JM Monster Framework"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMSimpleEnemyInvestigateSoundTask : public FStateTreeAIActionTaskBase
{
    GENERATED_BODY()

    using FInstanceDataType = FJMSimpleEnemyInvestigateSoundInstanceData;

    FJMSimpleEnemyInvestigateSoundTask();

    virtual const UStruct* GetInstanceDataType() const override
    {
        return FInstanceDataType::StaticStruct();
    }

    virtual EStateTreeRunStatus EnterState(
        FStateTreeExecutionContext& Context,
        const FStateTreeTransitionResult& Transition) const override;

    virtual EStateTreeRunStatus Tick(
        FStateTreeExecutionContext& Context,
        float DeltaTime) const override;

    virtual void ExitState(
        FStateTreeExecutionContext& Context,
        const FStateTreeTransitionResult& Transition) const override;

    UPROPERTY(EditAnywhere, Category = "Movement", meta = (ClampMin = "0.0"))
    float AcceptanceRadius = 75.0f;
};

/** Moves to a snapshot of LastSeenLocation without following the hidden Actor. */
USTRUCT(meta = (DisplayName = "Move To Last Seen Location", Category = "JM Monster Framework"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMSimpleEnemyMoveToLastSeenLocationTask : public FStateTreeAIActionTaskBase
{
    GENERATED_BODY()

    using FInstanceDataType = FJMSimpleEnemyMoveToLastSeenLocationInstanceData;

    FJMSimpleEnemyMoveToLastSeenLocationTask();

    virtual const UStruct* GetInstanceDataType() const override
    {
        return FInstanceDataType::StaticStruct();
    }

    virtual EStateTreeRunStatus EnterState(
        FStateTreeExecutionContext& Context,
        const FStateTreeTransitionResult& Transition) const override;

    virtual EStateTreeRunStatus Tick(
        FStateTreeExecutionContext& Context,
        float DeltaTime) const override;

    virtual void ExitState(
        FStateTreeExecutionContext& Context,
        const FStateTreeTransitionResult& Transition) const override;

    UPROPERTY(EditAnywhere, Category = "Movement", meta = (ClampMin = "0.0"))
    float AcceptanceRadius = 75.0f;
};

/** Rotates in place for a fixed duration so AI Sight can scan the surroundings. */
USTRUCT(meta = (DisplayName = "Search Surroundings", Category = "JM Monster Framework"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMSimpleEnemySearchTask : public FStateTreeAIActionTaskBase
{
    GENERATED_BODY()

    using FInstanceDataType = FJMSimpleEnemySearchInstanceData;

    FJMSimpleEnemySearchTask();

    virtual const UStruct* GetInstanceDataType() const override
    {
        return FInstanceDataType::StaticStruct();
    }

    virtual EStateTreeRunStatus EnterState(
        FStateTreeExecutionContext& Context,
        const FStateTreeTransitionResult& Transition) const override;

    virtual EStateTreeRunStatus Tick(
        FStateTreeExecutionContext& Context,
        float DeltaTime) const override;

    UPROPERTY(EditAnywhere, Category = "Search", meta = (ClampMin = "0.0"))
    float SearchDuration = 4.0f;

    UPROPERTY(EditAnywhere, Category = "Search", meta = (ClampMin = "0.0"))
    float RotationSpeedDegrees = 90.0f;
};
