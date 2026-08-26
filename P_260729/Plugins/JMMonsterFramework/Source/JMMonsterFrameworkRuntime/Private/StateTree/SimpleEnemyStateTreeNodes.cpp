#include "StateTree/SimpleEnemyStateTreeNodes.h"

#include "AI/SimpleEnemyAIController.h"
#include "GameFramework/Pawn.h"
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
        // The Chase OnTick transition owns loss handling and moves to RecentTracking.
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

bool FJMSimpleEnemyHasRecentTrackingMemoryCondition::TestCondition(
    FStateTreeExecutionContext& Context) const
{
    const ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner());
    return IsValid(Controller)
        && !Controller->bCanSeeTarget
        && Controller->bHasRecentTrackingMemory;
}

FJMSimpleEnemyRecentTrackingTask::FJMSimpleEnemyRecentTrackingTask()
{
    bShouldCallTick = true;
}

EStateTreeRunStatus FJMSimpleEnemyRecentTrackingTask::EnterState(
    FStateTreeExecutionContext& Context,
    const FStateTreeTransitionResult& Transition) const
{
    ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner());
    if (!IsValid(Controller) || !Controller->bHasRecentTrackingMemory)
    {
        return EStateTreeRunStatus::Failed;
    }

    Context.GetInstanceData(*this).ElapsedTime = 0.0f;
    const EPathFollowingRequestResult::Type MoveResult = Controller->MoveToLocation(
        Controller->EstimatedTrackingLocation,
        AcceptanceRadius,
        true,
        true,
        true,
        true,
        nullptr,
        true);

    return MoveResult == EPathFollowingRequestResult::Failed
        ? EStateTreeRunStatus::Failed
        : EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FJMSimpleEnemyRecentTrackingTask::Tick(
    FStateTreeExecutionContext& Context,
    const float DeltaTime) const
{
    ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner());
    if (!IsValid(Controller))
    {
        return EStateTreeRunStatus::Failed;
    }

    // Keep running for this tick so the StateTree's reacquisition transition wins.
    if (Controller->bCanSeeTarget && IsValid(Controller->TargetActor))
    {
        return EStateTreeRunStatus::Running;
    }

    FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
    InstanceData.ElapsedTime += FMath::Max(DeltaTime, 0.0f);
    if (InstanceData.ElapsedTime >= Controller->TrackingMemoryDuration)
    {
        Controller->bHasRecentTrackingMemory = false;
        return EStateTreeRunStatus::Succeeded;
    }

    return EStateTreeRunStatus::Running;
}

void FJMSimpleEnemyRecentTrackingTask::ExitState(
    FStateTreeExecutionContext& Context,
    const FStateTreeTransitionResult& Transition) const
{
    if (ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner()))
    {
        Controller->StopMovement();
        Controller->bHasRecentTrackingMemory = false;
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

FJMSimpleEnemySearchTask::FJMSimpleEnemySearchTask()
{
    bShouldCallTick = true;
}

EStateTreeRunStatus FJMSimpleEnemySearchTask::EnterState(
    FStateTreeExecutionContext& Context,
    const FStateTreeTransitionResult& Transition) const
{
    ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner());
    if (!IsValid(Controller) || !IsValid(Controller->GetPawn()))
    {
        return EStateTreeRunStatus::Failed;
    }

    Controller->StopMovement();
    Context.GetInstanceData(*this).ElapsedTime = 0.0f;

    return SearchDuration <= 0.0f
        ? EStateTreeRunStatus::Succeeded
        : EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FJMSimpleEnemySearchTask::Tick(
    FStateTreeExecutionContext& Context,
    const float DeltaTime) const
{
    ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner());
    APawn* ControlledPawn = IsValid(Controller) ? Controller->GetPawn() : nullptr;
    if (!IsValid(Controller) || !IsValid(ControlledPawn))
    {
        return EStateTreeRunStatus::Failed;
    }

    // Keep Search running for this tick so its sight transition can win immediately.
    if (Controller->bCanSeeTarget && IsValid(Controller->TargetActor))
    {
        return EStateTreeRunStatus::Running;
    }

    FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
    InstanceData.ElapsedTime += FMath::Max(DeltaTime, 0.0f);
    if (InstanceData.ElapsedTime >= SearchDuration)
    {
        return EStateTreeRunStatus::Succeeded;
    }

    const float DeltaYaw = RotationSpeedDegrees * FMath::Max(DeltaTime, 0.0f);
    const FRotator SearchRotation(0.0f, ControlledPawn->GetActorRotation().Yaw + DeltaYaw, 0.0f);
    ControlledPawn->SetActorRotation(SearchRotation);
    Controller->SetControlRotation(SearchRotation);

    return EStateTreeRunStatus::Running;
}
