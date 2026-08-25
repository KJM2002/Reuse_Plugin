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

/** Per-execution storage required by StateTree for the chase task. */
USTRUCT()
struct FJMSimpleEnemyMoveToTargetInstanceData
{
    GENERATED_BODY()
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
