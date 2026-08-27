#include "StateTree/StalkerEnemyStateTreeNodes.h"

#include "GameFramework/Pawn.h"
#include "Navigation/PathFollowingComponent.h"
#include "NavigationSystem.h"
#include "StateTreeExecutionContext.h"

bool FJMStalkerDistanceBandCondition::TestCondition(FStateTreeExecutionContext& Context) const
{
    const AStalkerEnemyAIController* Controller = Cast<AStalkerEnemyAIController>(Context.GetOwner());
    return IsValid(Controller) && Controller->CurrentDistanceBand == ExpectedBand;
}

FJMStalkerApproachTask::FJMStalkerApproachTask()
{
    bShouldCallTick = true;
}

EStateTreeRunStatus FJMStalkerApproachTask::EnterState(
    FStateTreeExecutionContext& Context,
    const FStateTreeTransitionResult& Transition) const
{
    AStalkerEnemyAIController* Controller = Cast<AStalkerEnemyAIController>(Context.GetOwner());
    if (IsValid(Controller) && IsValid(Controller->EnemyMemory.TargetActor))
    {
        Controller->SetFocus(Controller->EnemyMemory.TargetActor);
        const float AcceptanceDistance = FMath::Max(
            Controller->MaximumFollowDistance - Controller->DistanceHysteresis,
            Controller->MinimumFollowDistance);
        Controller->MoveToActor(Controller->EnemyMemory.TargetActor, AcceptanceDistance);
    }
    return EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FJMStalkerApproachTask::Tick(
    FStateTreeExecutionContext& Context,
    const float DeltaTime) const
{
    AStalkerEnemyAIController* Controller = Cast<AStalkerEnemyAIController>(Context.GetOwner());
    if (IsValid(Controller)
        && Controller->CurrentDistanceBand == EJMStalkerDistanceBand::TooFar
        && Controller->GetMoveStatus() == EPathFollowingStatus::Idle
        && IsValid(Controller->EnemyMemory.TargetActor))
    {
        const float AcceptanceDistance = FMath::Max(
            Controller->MaximumFollowDistance - Controller->DistanceHysteresis,
            Controller->MinimumFollowDistance);
        Controller->MoveToActor(Controller->EnemyMemory.TargetActor, AcceptanceDistance);
    }
    return EStateTreeRunStatus::Running;
}

void FJMStalkerApproachTask::ExitState(
    FStateTreeExecutionContext& Context,
    const FStateTreeTransitionResult& Transition) const
{
    if (AStalkerEnemyAIController* Controller = Cast<AStalkerEnemyAIController>(Context.GetOwner()))
    {
        Controller->StopMovement();
        Controller->ClearFocus(EAIFocusPriority::Gameplay);
    }
}

FJMStalkerHoldDistanceTask::FJMStalkerHoldDistanceTask()
{
    bShouldCallTick = true;
}

EStateTreeRunStatus FJMStalkerHoldDistanceTask::EnterState(
    FStateTreeExecutionContext& Context,
    const FStateTreeTransitionResult& Transition) const
{
    if (AStalkerEnemyAIController* Controller = Cast<AStalkerEnemyAIController>(Context.GetOwner()))
    {
        Controller->StopMovement();
        if (IsValid(Controller->EnemyMemory.TargetActor))
        {
            Controller->SetFocus(Controller->EnemyMemory.TargetActor);
        }
    }
    return EStateTreeRunStatus::Running;
}

void FJMStalkerHoldDistanceTask::ExitState(
    FStateTreeExecutionContext& Context,
    const FStateTreeTransitionResult& Transition) const
{
    if (AStalkerEnemyAIController* Controller = Cast<AStalkerEnemyAIController>(Context.GetOwner()))
    {
        Controller->ClearFocus(EAIFocusPriority::Gameplay);
    }
}

EStateTreeRunStatus FJMStalkerHoldDistanceTask::Tick(
    FStateTreeExecutionContext& Context,
    const float DeltaTime) const
{
    if (AStalkerEnemyAIController* Controller = Cast<AStalkerEnemyAIController>(Context.GetOwner()))
    {
        Controller->StopMovement();
    }
    return EStateTreeRunStatus::Running;
}

FJMStalkerRetreatTask::FJMStalkerRetreatTask()
{
    bShouldCallTick = true;
}

EStateTreeRunStatus FJMStalkerRetreatTask::EnterState(
    FStateTreeExecutionContext& Context,
    const FStateTreeTransitionResult& Transition) const
{
    AStalkerEnemyAIController* Controller = Cast<AStalkerEnemyAIController>(Context.GetOwner());
    FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
    InstanceData.TimeSinceMoveRequest = 0.0f;
    if (IsValid(Controller))
    {
        if (IsValid(Controller->EnemyMemory.TargetActor))
        {
            Controller->SetFocus(Controller->EnemyMemory.TargetActor);
        }
        RequestRetreatMove(*Controller);
    }
    return EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FJMStalkerRetreatTask::Tick(
    FStateTreeExecutionContext& Context,
    const float DeltaTime) const
{
    AStalkerEnemyAIController* Controller = Cast<AStalkerEnemyAIController>(Context.GetOwner());
    if (!IsValid(Controller))
    {
        return EStateTreeRunStatus::Failed;
    }

    FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
    InstanceData.TimeSinceMoveRequest += FMath::Max(DeltaTime, 0.0f);
    if (Controller->CurrentDistanceBand == EJMStalkerDistanceBand::TooClose
        && (InstanceData.TimeSinceMoveRequest >= 0.25f
            || Controller->GetMoveStatus() == EPathFollowingStatus::Idle))
    {
        InstanceData.TimeSinceMoveRequest = 0.0f;
        RequestRetreatMove(*Controller);
    }
    return EStateTreeRunStatus::Running;
}

void FJMStalkerRetreatTask::ExitState(
    FStateTreeExecutionContext& Context,
    const FStateTreeTransitionResult& Transition) const
{
    if (AStalkerEnemyAIController* Controller = Cast<AStalkerEnemyAIController>(Context.GetOwner()))
    {
        Controller->StopMovement();
        Controller->ClearFocus(EAIFocusPriority::Gameplay);
    }
}

bool FJMStalkerRetreatTask::RequestRetreatMove(AStalkerEnemyAIController& Controller) const
{
    APawn* ControlledPawn = Controller.GetPawn();
    AActor* TargetActor = Controller.EnemyMemory.TargetActor;
    UWorld* World = Controller.GetWorld();
    UNavigationSystemV1* NavigationSystem = IsValid(World)
        ? FNavigationSystem::GetCurrent<UNavigationSystemV1>(World)
        : nullptr;
    if (!IsValid(ControlledPawn) || !IsValid(TargetActor) || !IsValid(NavigationSystem))
    {
        return false;
    }

    FVector AwayDirection = ControlledPawn->GetActorLocation() - TargetActor->GetActorLocation();
    AwayDirection.Z = 0.0f;
    AwayDirection = AwayDirection.GetSafeNormal();
    if (AwayDirection.IsNearlyZero())
    {
        AwayDirection = -ControlledPawn->GetActorForwardVector().GetSafeNormal2D();
    }

    const float DesiredDistance = Controller.MinimumFollowDistance + Controller.DistanceHysteresis;
    const FVector DesiredLocation = TargetActor->GetActorLocation() + AwayDirection * DesiredDistance;
    FNavLocation RetreatLocation;
    if (!NavigationSystem->ProjectPointToNavigation(
        DesiredLocation,
        RetreatLocation,
        FVector(200.0, 200.0, 300.0)))
    {
        return false;
    }

    const EPathFollowingRequestResult::Type MoveResult = Controller.MoveToLocation(
        RetreatLocation.Location,
        50.0f,
        true,
        true,
        true,
        true,
        nullptr,
        true);
    return MoveResult != EPathFollowingRequestResult::Failed;
}
