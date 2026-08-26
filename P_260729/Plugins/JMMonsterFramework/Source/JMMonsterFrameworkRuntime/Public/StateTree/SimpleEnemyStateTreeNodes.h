#pragma once

#include "Conditions/StateTreeAIConditionBase.h"
#include "Tasks/StateTreeAITask.h"
#include "SimpleEnemyStateTreeNodes.generated.h"

struct FStateTreeExecutionContext;
struct FStateTreeTransitionResult;

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
