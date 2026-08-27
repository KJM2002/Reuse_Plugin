#pragma once

#include "AI/StalkerEnemyAIController.h"
#include "Conditions/StateTreeAIConditionBase.h"
#include "Tasks/StateTreeAITask.h"
#include "StalkerEnemyStateTreeNodes.generated.h"

struct FStateTreeExecutionContext;
struct FStateTreeTransitionResult;

USTRUCT()
struct FJMStalkerStateInstanceData
{
    GENERATED_BODY()

    UPROPERTY(Transient)
    float TimeSinceMoveRequest = 0.0f;
};

USTRUCT(meta = (DisplayName = "Stalker Distance Band", Category = "JM Monster Framework"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStalkerDistanceBandCondition : public FStateTreeAIConditionBase
{
    GENERATED_BODY()

    using FInstanceDataType = FJMStalkerStateInstanceData;

    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;

    UPROPERTY(EditAnywhere, Category = "Condition")
    EJMStalkerDistanceBand ExpectedBand = EJMStalkerDistanceBand::Preferred;
};

USTRUCT(meta = (DisplayName = "Stalker Approach", Category = "JM Monster Framework"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStalkerApproachTask : public FStateTreeAIActionTaskBase
{
    GENERATED_BODY()

    using FInstanceDataType = FJMStalkerStateInstanceData;

    FJMStalkerApproachTask();

    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual EStateTreeRunStatus EnterState(
        FStateTreeExecutionContext& Context,
        const FStateTreeTransitionResult& Transition) const override;
    virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, float DeltaTime) const override;
    virtual void ExitState(
        FStateTreeExecutionContext& Context,
        const FStateTreeTransitionResult& Transition) const override;
};

USTRUCT(meta = (DisplayName = "Stalker Hold Distance", Category = "JM Monster Framework"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStalkerHoldDistanceTask : public FStateTreeAIActionTaskBase
{
    GENERATED_BODY()

    using FInstanceDataType = FJMStalkerStateInstanceData;

    FJMStalkerHoldDistanceTask();

    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual EStateTreeRunStatus EnterState(
        FStateTreeExecutionContext& Context,
        const FStateTreeTransitionResult& Transition) const override;
    virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, float DeltaTime) const override;
    virtual void ExitState(
        FStateTreeExecutionContext& Context,
        const FStateTreeTransitionResult& Transition) const override;
};

USTRUCT(meta = (DisplayName = "Stalker Retreat", Category = "JM Monster Framework"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStalkerRetreatTask : public FStateTreeAIActionTaskBase
{
    GENERATED_BODY()

    using FInstanceDataType = FJMStalkerStateInstanceData;

    FJMStalkerRetreatTask();

    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual EStateTreeRunStatus EnterState(
        FStateTreeExecutionContext& Context,
        const FStateTreeTransitionResult& Transition) const override;
    virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, float DeltaTime) const override;
    virtual void ExitState(
        FStateTreeExecutionContext& Context,
        const FStateTreeTransitionResult& Transition) const override;

private:
    bool RequestRetreatMove(AStalkerEnemyAIController& Controller) const;
};
