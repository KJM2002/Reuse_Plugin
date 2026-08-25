#include "StateTree/SimpleEnemyStateTreeNodes.h"

#include "AI/SimpleEnemyAIController.h"
#include "Navigation/PathFollowingComponent.h"
#include "StateTreeExecutionContext.h"

bool FJMSimpleEnemyCanSeeTargetCondition::TestCondition(FStateTreeExecutionContext& Context) const
{
    const ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner());
    const bool bHasVisibleTarget = IsValid(Controller)
        && Controller->bCanSeeTarget
        && IsValid(Controller->TargetActor);
    return bHasVisibleTarget == bExpectedValue;
}

FJMSimpleEnemyMoveToTargetTask::FJMSimpleEnemyMoveToTargetTask()
{
    bShouldCallTick = true;
}

EStateTreeRunStatus FJMSimpleEnemyMoveToTargetTask::EnterState(
    FStateTreeExecutionContext& Context,
    const FStateTreeTransitionResult& Transition) const
{
    ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner());
    if (!IsValid(Controller) || !Controller->bCanSeeTarget || !IsValid(Controller->TargetActor))
    {
        // The Chase OnTick transition owns loss handling and moves to Investigate.
        return EStateTreeRunStatus::Running;
    }

    const EPathFollowingRequestResult::Type MoveResult = Controller->MoveToActor(
        Controller->TargetActor,
        AcceptanceRadius,
        true,
        true,
        true,
        nullptr,
        true);

    return MoveResult == EPathFollowingRequestResult::Failed
        ? EStateTreeRunStatus::Failed
        : EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FJMSimpleEnemyMoveToTargetTask::Tick(
    FStateTreeExecutionContext& Context,
    const float DeltaTime) const
{
    ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner());
    if (!IsValid(Controller) || !Controller->bCanSeeTarget || !IsValid(Controller->TargetActor))
    {
        return EStateTreeRunStatus::Failed;
    }

    // MoveToActor observes a moving goal while its request is active. If the enemy
    // already reached the player and the player moves away again, start a new request.
    if (Controller->GetMoveStatus() == EPathFollowingStatus::Idle)
    {
        const EPathFollowingRequestResult::Type MoveResult = Controller->MoveToActor(
            Controller->TargetActor,
            AcceptanceRadius,
            true,
            true,
            true,
            nullptr,
            true);

        if (MoveResult == EPathFollowingRequestResult::Failed)
        {
            return EStateTreeRunStatus::Failed;
        }
    }

    return EStateTreeRunStatus::Running;
}

void FJMSimpleEnemyMoveToTargetTask::ExitState(
    FStateTreeExecutionContext& Context,
    const FStateTreeTransitionResult& Transition) const
{
    if (ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner()))
    {
        Controller->StopMovement();
    }
}

FJMSimpleEnemyMoveToLastSeenLocationTask::FJMSimpleEnemyMoveToLastSeenLocationTask()
{
    bShouldCallTick = true;
}

EStateTreeRunStatus FJMSimpleEnemyMoveToLastSeenLocationTask::EnterState(
    FStateTreeExecutionContext& Context,
    const FStateTreeTransitionResult& Transition) const
{
    ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner());
    if (!IsValid(Controller))
    {
        return EStateTreeRunStatus::Failed;
    }

    const EPathFollowingRequestResult::Type MoveResult = Controller->MoveToLocation(
        Controller->LastSeenLocation,
        AcceptanceRadius,
        true,
        true,
        true,
        true,
        nullptr,
        true);

    if (MoveResult == EPathFollowingRequestResult::Failed)
    {
        return EStateTreeRunStatus::Failed;
    }

    return MoveResult == EPathFollowingRequestResult::AlreadyAtGoal
        ? EStateTreeRunStatus::Succeeded
        : EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FJMSimpleEnemyMoveToLastSeenLocationTask::Tick(
    FStateTreeExecutionContext& Context,
    const float DeltaTime) const
{
    const ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner());
    if (!IsValid(Controller))
    {
        return EStateTreeRunStatus::Failed;
    }

    // Give the StateTree's OnTick transition a chance to resume Chase immediately.
    if (Controller->bCanSeeTarget && IsValid(Controller->TargetActor))
    {
        return EStateTreeRunStatus::Running;
    }

    return Controller->GetMoveStatus() == EPathFollowingStatus::Idle
        ? EStateTreeRunStatus::Succeeded
        : EStateTreeRunStatus::Running;
}

void FJMSimpleEnemyMoveToLastSeenLocationTask::ExitState(
    FStateTreeExecutionContext& Context,
    const FStateTreeTransitionResult& Transition) const
{
    if (ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner()))
    {
        Controller->StopMovement();
    }
}
