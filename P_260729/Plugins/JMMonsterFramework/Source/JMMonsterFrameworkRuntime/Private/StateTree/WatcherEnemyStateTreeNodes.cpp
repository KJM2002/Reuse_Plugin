#include "StateTree/WatcherEnemyStateTreeNodes.h"

#include "AI/WatcherEnemyAIController.h"
#include "Navigation/PathFollowingComponent.h"
#include "StateTreeExecutionContext.h"

bool FJMWatcherIsWatchedCondition::TestCondition(FStateTreeExecutionContext& Context) const
{
    const AWatcherEnemyAIController* Controller = Cast<AWatcherEnemyAIController>(Context.GetOwner());
    return IsValid(Controller)
        && Controller->bPlayerIsWatchingWatcher == bExpectedValue;
}

FJMWatcherStopTask::FJMWatcherStopTask()
{
    bShouldCallTick = true;
}

EStateTreeRunStatus FJMWatcherStopTask::EnterState(
    FStateTreeExecutionContext& Context,
    const FStateTreeTransitionResult& Transition) const
{
    AWatcherEnemyAIController* Controller = Cast<AWatcherEnemyAIController>(Context.GetOwner());
    if (!IsValid(Controller))
    {
        return EStateTreeRunStatus::Failed;
    }

    Controller->StopMovement();
    return EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FJMWatcherStopTask::Tick(
    FStateTreeExecutionContext& Context,
    const float DeltaTime) const
{
    AWatcherEnemyAIController* Controller = Cast<AWatcherEnemyAIController>(Context.GetOwner());
    if (!IsValid(Controller))
    {
        return EStateTreeRunStatus::Failed;
    }

    Controller->StopMovement();
    return EStateTreeRunStatus::Running;
}

FJMWatcherMoveTask::FJMWatcherMoveTask()
{
    bShouldCallTick = true;
}

EStateTreeRunStatus FJMWatcherMoveTask::EnterState(
    FStateTreeExecutionContext& Context,
    const FStateTreeTransitionResult& Transition) const
{
    AWatcherEnemyAIController* Controller = Cast<AWatcherEnemyAIController>(Context.GetOwner());
    APawn* PlayerPawn = IsValid(Controller) ? Controller->GetGazePlayerPawn() : nullptr;
    if (!IsValid(Controller) || !IsValid(PlayerPawn))
    {
        return EStateTreeRunStatus::Running;
    }

    Controller->MoveToActor(PlayerPawn, AcceptanceRadius);
    return EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FJMWatcherMoveTask::Tick(
    FStateTreeExecutionContext& Context,
    const float DeltaTime) const
{
    AWatcherEnemyAIController* Controller = Cast<AWatcherEnemyAIController>(Context.GetOwner());
    if (!IsValid(Controller))
    {
        return EStateTreeRunStatus::Failed;
    }

    if (Controller->bPlayerIsWatchingWatcher)
    {
        Controller->StopMovement();
    }
    else if (Controller->GetMoveStatus() == EPathFollowingStatus::Idle)
    {
        if (APawn* PlayerPawn = Controller->GetGazePlayerPawn())
        {
            Controller->MoveToActor(PlayerPawn, AcceptanceRadius);
        }
    }
    return EStateTreeRunStatus::Running;
}

void FJMWatcherMoveTask::ExitState(
    FStateTreeExecutionContext& Context,
    const FStateTreeTransitionResult& Transition) const
{
    if (AWatcherEnemyAIController* Controller = Cast<AWatcherEnemyAIController>(Context.GetOwner()))
    {
        Controller->StopMovement();
    }
}
