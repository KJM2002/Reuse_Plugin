#include "StateTree/SimpleEnemyStateTreeNodes.h"

#include "AI/ListenerEnemyAIController.h"
#include "AI/SimpleEnemyAIController.h"
#include "JMMonsterFrameworkRuntime.h"
#include "GameFramework/Pawn.h"
#include "Navigation/PathFollowingComponent.h"
#include "NavigationSystem.h"
#include "StateTreeExecutionContext.h"

bool FJMSimpleEnemyCanSeeTargetCondition::TestCondition(FStateTreeExecutionContext& Context) const
{
    const ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner());
    const bool bHasVisibleTarget = IsValid(Controller)
        && Controller->EnemyMemory.bCanSeeTarget
        && IsValid(Controller->EnemyMemory.TargetActor);
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
    if (!IsValid(Controller) || !Controller->EnemyMemory.bCanSeeTarget || !IsValid(Controller->EnemyMemory.TargetActor))
    {
        // The Chase OnTick transition owns loss handling and moves to RecentTracking.
        return EStateTreeRunStatus::Running;
    }

    const EPathFollowingRequestResult::Type MoveResult = Controller->MoveToActor(
        Controller->EnemyMemory.TargetActor,
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
    if (!IsValid(Controller) || !Controller->EnemyMemory.bCanSeeTarget || !IsValid(Controller->EnemyMemory.TargetActor))
    {
        return EStateTreeRunStatus::Failed;
    }

    // MoveToActor observes a moving goal while its request is active. If the enemy
    // already reached the player and the player moves away again, start a new request.
    if (Controller->GetMoveStatus() == EPathFollowingStatus::Idle)
    {
        const EPathFollowingRequestResult::Type MoveResult = Controller->MoveToActor(
            Controller->EnemyMemory.TargetActor,
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

bool FJMSimpleEnemyTargetInAttackRangeCondition::TestCondition(
    FStateTreeExecutionContext& Context) const
{
    const ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner());
    const bool bIsInRange = IsValid(Controller) && Controller->IsTargetInAttackRange();
    return bIsInRange == bExpectedValue;
}

bool FJMSimpleEnemyHasRecentTrackingMemoryCondition::TestCondition(
    FStateTreeExecutionContext& Context) const
{
    const ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner());
    return IsValid(Controller)
        && !Controller->EnemyMemory.bCanSeeTarget
        && Controller->EnemyMemory.bHasRecentTrackingMemory;
}

bool FJMSimpleEnemyHasLiveGraceTrackingCondition::TestCondition(
    FStateTreeExecutionContext& Context) const
{
    const ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner());
    return IsValid(Controller)
        && !Controller->EnemyMemory.bCanSeeTarget
        && Controller->EnemyMemory.bHasLiveGraceTracking
        && Controller->EnemyMemory.LiveGraceTargetActor.IsValid();
}

bool FJMSimpleEnemyHasHeardSoundCondition::TestCondition(
    FStateTreeExecutionContext& Context) const
{
    const ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner());
    return IsValid(Controller)
        && !Controller->EnemyMemory.bCanSeeTarget
        && Controller->EnemyMemory.bHasHeardSound;
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
    if (!IsValid(Controller) || !Controller->EnemyMemory.bHasRecentTrackingMemory)
    {
        return EStateTreeRunStatus::Failed;
    }

    Context.GetInstanceData(*this).ElapsedTime = 0.0f;
    const EPathFollowingRequestResult::Type MoveResult = Controller->MoveToLocation(
        Controller->EnemyMemory.EstimatedTrackingLocation,
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
    if (Controller->EnemyMemory.bCanSeeTarget && IsValid(Controller->EnemyMemory.TargetActor))
    {
        return EStateTreeRunStatus::Running;
    }

    FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
    InstanceData.ElapsedTime += FMath::Max(DeltaTime, 0.0f);
    if (InstanceData.ElapsedTime >= Controller->TrackingMemoryDuration)
    {
        Controller->EnemyMemory.bHasRecentTrackingMemory = false;
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
        Controller->EnemyMemory.bHasRecentTrackingMemory = false;
    }
}

FJMSimpleEnemyLiveGraceTrackingTask::FJMSimpleEnemyLiveGraceTrackingTask()
{
    bShouldCallTick = true;
}

EStateTreeRunStatus FJMSimpleEnemyLiveGraceTrackingTask::EnterState(
    FStateTreeExecutionContext& Context,
    const FStateTreeTransitionResult& Transition) const
{
    ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner());
    AActor* GraceTarget = IsValid(Controller) ? Controller->EnemyMemory.LiveGraceTargetActor.Get() : nullptr;
    if (!IsValid(Controller)
        || Controller->EnemyMemory.bCanSeeTarget
        || !Controller->EnemyMemory.bHasLiveGraceTracking
        || !IsValid(GraceTarget))
    {
        return EStateTreeRunStatus::Failed;
    }

    Context.GetInstanceData(*this).ElapsedTime = 0.0f;
    const EPathFollowingRequestResult::Type MoveResult = Controller->MoveToActor(
        GraceTarget,
        AcceptanceRadius,
        true,
        true,
        true,
        nullptr,
        true);

    if (MoveResult == EPathFollowingRequestResult::Failed)
    {
        Controller->EndLiveGraceTracking();
        return EStateTreeRunStatus::Failed;
    }

    return EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FJMSimpleEnemyLiveGraceTrackingTask::Tick(
    FStateTreeExecutionContext& Context,
    const float DeltaTime) const
{
    ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner());
    if (!IsValid(Controller))
    {
        return EStateTreeRunStatus::Failed;
    }

    // Reacquisition must win before any further hidden-target sampling.
    if (Controller->EnemyMemory.bCanSeeTarget && IsValid(Controller->EnemyMemory.TargetActor))
    {
        return EStateTreeRunStatus::Running;
    }

    if (!Controller->UpdateLiveGraceLastKnownLocation())
    {
        Controller->EndLiveGraceTracking();
        return EStateTreeRunStatus::Failed;
    }

    FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
    InstanceData.ElapsedTime += FMath::Max(DeltaTime, 0.0f);
    if (InstanceData.ElapsedTime >= Controller->LiveGraceDuration)
    {
        Controller->EndLiveGraceTracking();
        return EStateTreeRunStatus::Succeeded;
    }

    // MoveToActor stops after reaching the live goal. Restart it if the hidden
    // player moves away again while the same Grace window is still valid.
    if (Controller->GetMoveStatus() == EPathFollowingStatus::Idle)
    {
        AActor* GraceTarget = Controller->EnemyMemory.LiveGraceTargetActor.Get();
        const EPathFollowingRequestResult::Type MoveResult = IsValid(GraceTarget)
            ? Controller->MoveToActor(
                GraceTarget,
                AcceptanceRadius,
                true,
                true,
                true,
                nullptr,
                true)
            : EPathFollowingRequestResult::Failed;
        if (MoveResult == EPathFollowingRequestResult::Failed)
        {
            Controller->EndLiveGraceTracking();
            return EStateTreeRunStatus::Failed;
        }
    }

    return EStateTreeRunStatus::Running;
}

void FJMSimpleEnemyLiveGraceTrackingTask::ExitState(
    FStateTreeExecutionContext& Context,
    const FStateTreeTransitionResult& Transition) const
{
    if (ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner()))
    {
        Controller->StopMovement();
        Controller->EndLiveGraceTracking();
    }
}

FJMSimpleEnemyPatrolTask::FJMSimpleEnemyPatrolTask()
{
    bShouldCallTick = true;
}

EStateTreeRunStatus FJMSimpleEnemyPatrolTask::EnterState(
    FStateTreeExecutionContext& Context,
    const FStateTreeTransitionResult& Transition) const
{
    ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner());
    if (!IsValid(Controller) || !IsValid(Controller->GetPawn()))
    {
        return EStateTreeRunStatus::Failed;
    }

    if (AListenerEnemyAIController* ListenerController = Cast<AListenerEnemyAIController>(Controller))
    {
        ListenerController->SetSightConfirmationEnabled(false);
    }

    FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
    InstanceData.ElapsedWaitTime = 0.0f;
    InstanceData.bWaiting = !RequestPatrolMove(*Controller);
    return EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FJMSimpleEnemyPatrolTask::Tick(
    FStateTreeExecutionContext& Context,
    const float DeltaTime) const
{
    ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner());
    if (!IsValid(Controller) || !IsValid(Controller->GetPawn()))
    {
        return EStateTreeRunStatus::Failed;
    }

    // Keep Patrol alive for this tick so its sight transition can preempt immediately.
    if (Controller->EnemyMemory.bCanSeeTarget && IsValid(Controller->EnemyMemory.TargetActor))
    {
        return EStateTreeRunStatus::Running;
    }

    FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
    if (!InstanceData.bWaiting && Controller->GetMoveStatus() == EPathFollowingStatus::Idle)
    {
        InstanceData.bWaiting = true;
        InstanceData.ElapsedWaitTime = 0.0f;
    }

    if (InstanceData.bWaiting)
    {
        InstanceData.ElapsedWaitTime += FMath::Max(DeltaTime, 0.0f);
        if (InstanceData.ElapsedWaitTime >= WaitDuration)
        {
            InstanceData.ElapsedWaitTime = 0.0f;
            InstanceData.bWaiting = !RequestPatrolMove(*Controller);
        }
    }

    return EStateTreeRunStatus::Running;
}

void FJMSimpleEnemyPatrolTask::ExitState(
    FStateTreeExecutionContext& Context,
    const FStateTreeTransitionResult& Transition) const
{
    if (ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner()))
    {
        Controller->StopMovement();
    }
}

bool FJMSimpleEnemyPatrolTask::RequestPatrolMove(ASimpleEnemyAIController& Controller) const
{
    APawn* ControlledPawn = Controller.GetPawn();
    UWorld* World = Controller.GetWorld();
    UNavigationSystemV1* NavigationSystem = IsValid(World)
        ? FNavigationSystem::GetCurrent<UNavigationSystemV1>(World)
        : nullptr;
    if (!IsValid(ControlledPawn) || !IsValid(NavigationSystem))
    {
        return false;
    }

    FNavLocation PatrolLocation;
    if (!NavigationSystem->GetRandomReachablePointInRadius(
        ControlledPawn->GetActorLocation(),
        PatrolRadius,
        PatrolLocation))
    {
        return false;
    }

    const EPathFollowingRequestResult::Type MoveResult = Controller.MoveToLocation(
        PatrolLocation.Location,
        AcceptanceRadius,
        true,
        true,
        true,
        true,
        nullptr,
        true);
    return MoveResult != EPathFollowingRequestResult::Failed;
}

FJMSimpleEnemyBasicAttackTask::FJMSimpleEnemyBasicAttackTask()
{
    bShouldCallTick = true;
}

EStateTreeRunStatus FJMSimpleEnemyBasicAttackTask::EnterState(
    FStateTreeExecutionContext& Context,
    const FStateTreeTransitionResult& Transition) const
{
    ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner());
    if (!IsValid(Controller))
    {
        return EStateTreeRunStatus::Failed;
    }

    Controller->StopMovement();
    Controller->PerformBasicAttack();
    return EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FJMSimpleEnemyBasicAttackTask::Tick(
    FStateTreeExecutionContext& Context,
    const float DeltaTime) const
{
    ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner());
    if (!IsValid(Controller))
    {
        return EStateTreeRunStatus::Failed;
    }

    // Transitions own range exit and sight loss; never start a movement request here.
    if (!Controller->IsTargetInAttackRange())
    {
        return EStateTreeRunStatus::Running;
    }

    // The controller timestamp keeps cooldown valid even if range changes cause
    // rapid Attack -> Chase -> Attack state re-entry.
    Controller->PerformBasicAttack();

    return EStateTreeRunStatus::Running;
}

FJMSimpleEnemyInvestigateSoundTask::FJMSimpleEnemyInvestigateSoundTask()
{
    bShouldCallTick = true;
}

EStateTreeRunStatus FJMSimpleEnemyInvestigateSoundTask::EnterState(
    FStateTreeExecutionContext& Context,
    const FStateTreeTransitionResult& Transition) const
{
    ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner());
    if (!IsValid(Controller) || !Controller->EnemyMemory.bHasHeardSound || Controller->EnemyMemory.bCanSeeTarget)
    {
        return EStateTreeRunStatus::Failed;
    }


    if (AListenerEnemyAIController* ListenerController = Cast<AListenerEnemyAIController>(Controller))
    {
        ListenerController->SetSightConfirmationEnabled(true);
    }

    FJMSimpleEnemyInvestigateSoundInstanceData& InstanceData = Context.GetInstanceData(*this);
    InstanceData.ActiveSoundLocation = Controller->EnemyMemory.LastHeardLocation;
    const EPathFollowingRequestResult::Type MoveResult = Controller->MoveToLocation(
        InstanceData.ActiveSoundLocation,
        AcceptanceRadius,
        true,
        true,
        true,
        true,
        nullptr,
        true);
    if (MoveResult == EPathFollowingRequestResult::Failed)
    {
        Controller->ClearHeardSound();
        return EStateTreeRunStatus::Failed;
    }
    if (MoveResult == EPathFollowingRequestResult::AlreadyAtGoal)
    {
        Controller->ClearHeardSound();
        return EStateTreeRunStatus::Succeeded;
    }
    return EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FJMSimpleEnemyInvestigateSoundTask::Tick(
    FStateTreeExecutionContext& Context,
    const float DeltaTime) const
{
    ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner());
    if (!IsValid(Controller))
    {
        return EStateTreeRunStatus::Failed;
    }

    // Sight transitions must preempt before the pending sound is consumed.
    if (Controller->EnemyMemory.bCanSeeTarget && IsValid(Controller->EnemyMemory.TargetActor))
    {
        return EStateTreeRunStatus::Running;
    }

    FJMSimpleEnemyInvestigateSoundInstanceData& InstanceData = Context.GetInstanceData(*this);
    if (Controller->EnemyMemory.bHasHeardSound
        && !Controller->EnemyMemory.LastHeardLocation.Equals(InstanceData.ActiveSoundLocation, 1.0f))
    {
        InstanceData.ActiveSoundLocation = Controller->EnemyMemory.LastHeardLocation;
        const EPathFollowingRequestResult::Type MoveResult = Controller->MoveToLocation(
            InstanceData.ActiveSoundLocation,
            AcceptanceRadius,
            true,
            true,
            true,
            true,
            nullptr,
            true);
        UE_LOG(
            LogJMMonsterFramework,
            Log,
            TEXT("[JM HEARING REDIRECT] Enemy=%s Location=%s State=InvestigateSound"),
            *GetNameSafe(Controller->GetPawn()),
            *InstanceData.ActiveSoundLocation.ToCompactString());
        if (MoveResult == EPathFollowingRequestResult::Failed)
        {
            Controller->ClearHeardSound();
            return EStateTreeRunStatus::Failed;
        }
        if (MoveResult == EPathFollowingRequestResult::AlreadyAtGoal)
        {
            Controller->ClearHeardSound();
            return EStateTreeRunStatus::Succeeded;
        }
    }

    if (Controller->GetMoveStatus() == EPathFollowingStatus::Idle)
    {
        Controller->ClearHeardSound();
        return EStateTreeRunStatus::Succeeded;
    }
    return EStateTreeRunStatus::Running;
}

void FJMSimpleEnemyInvestigateSoundTask::ExitState(
    FStateTreeExecutionContext& Context,
    const FStateTreeTransitionResult& Transition) const
{
    if (ASimpleEnemyAIController* Controller = Cast<ASimpleEnemyAIController>(Context.GetOwner()))
    {
        Controller->StopMovement();
        Controller->ClearHeardSound();
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
        Controller->EnemyMemory.LastSeenLocation,
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
    if (Controller->EnemyMemory.bCanSeeTarget && IsValid(Controller->EnemyMemory.TargetActor))
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
    if (Controller->EnemyMemory.bCanSeeTarget && IsValid(Controller->EnemyMemory.TargetActor))
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
