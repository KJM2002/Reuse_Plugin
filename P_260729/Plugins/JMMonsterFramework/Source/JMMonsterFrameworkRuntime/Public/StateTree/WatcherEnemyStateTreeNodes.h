#pragma once

#include "Conditions/StateTreeAIConditionBase.h"
#include "Tasks/StateTreeAITask.h"
#include "WatcherEnemyStateTreeNodes.generated.h"

struct FStateTreeExecutionContext;
struct FStateTreeTransitionResult;

USTRUCT()
struct FJMWatcherGazeInstanceData
{
    GENERATED_BODY()
};

USTRUCT(meta = (DisplayName = "Player Is Watching Watcher", Category = "JM Monster Framework"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMWatcherIsWatchedCondition : public FStateTreeAIConditionBase
{
    GENERATED_BODY()

    using FInstanceDataType = FJMWatcherGazeInstanceData;

    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;

    UPROPERTY(EditAnywhere, Category = "Condition")
    bool bExpectedValue = true;
};

USTRUCT(meta = (DisplayName = "Stop While Watched", Category = "JM Monster Framework"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMWatcherStopTask : public FStateTreeAIActionTaskBase
{
    GENERATED_BODY()

    using FInstanceDataType = FJMWatcherGazeInstanceData;

    FJMWatcherStopTask();

    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual EStateTreeRunStatus EnterState(
        FStateTreeExecutionContext& Context,
        const FStateTreeTransitionResult& Transition) const override;
    virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, float DeltaTime) const override;
};

USTRUCT(meta = (DisplayName = "Move While Unwatched", Category = "JM Monster Framework"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMWatcherMoveTask : public FStateTreeAIActionTaskBase
{
    GENERATED_BODY()

    using FInstanceDataType = FJMWatcherGazeInstanceData;

    FJMWatcherMoveTask();

    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual EStateTreeRunStatus EnterState(
        FStateTreeExecutionContext& Context,
        const FStateTreeTransitionResult& Transition) const override;
    virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, float DeltaTime) const override;
    virtual void ExitState(
        FStateTreeExecutionContext& Context,
        const FStateTreeTransitionResult& Transition) const override;

    UPROPERTY(EditAnywhere, Category = "Movement", meta = (ClampMin = "0.0"))
    float AcceptanceRadius = 100.0f;
};
