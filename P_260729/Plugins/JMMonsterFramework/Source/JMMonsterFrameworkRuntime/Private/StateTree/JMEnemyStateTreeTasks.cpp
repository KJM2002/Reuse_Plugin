#include "StateTree/JMEnemyStateTreeTasks.h"

#include "Action/JMEnemyAction.h"
#include "Action/JMEnemyActionComponent.h"
#include "Core/JMEnemyBase.h"
#include "Core/JMEnemyDefinition.h"
#include "JMMonsterFrameworkRuntime.h"
#include "Locomotion/JMEnemyLocomotionComponent.h"
#include "Memory/JMEnemyMemoryComponent.h"
#include "NavigationSystem.h"
#include "State/JMEnemyStateComponent.h"
#include "StateTreeAsyncExecutionContext.h"
#include "StateTreeExecutionContext.h"
#include "StateTreeLinker.h"

namespace JMStateTree
{
    static EStateTreeRunStatus ToMoveStatus(const EJMEnemyMoveStatus Status)
    {
        return Status == EJMEnemyMoveStatus::Succeeded
            ? EStateTreeRunStatus::Succeeded : EStateTreeRunStatus::Failed;
    }

    enum class ERandomMovePhase : uint8
    {
        Selecting,
        Backoff,
        Moving,
        Waiting
    };

    static const TCHAR* MoveRequestResultName(const EJMEnemyMoveRequestResult Result)
    {
        switch (Result)
        {
        case EJMEnemyMoveRequestResult::RequestStarted: return TEXT("RequestStarted");
        case EJMEnemyMoveRequestResult::AlreadyAtGoal: return TEXT("AlreadyAtGoal");
        default: return TEXT("RequestFailed");
        }
    }

    static FString EnemyStateName(const UJMEnemyLocomotionComponent& Locomotion)
    {
        const AJMEnemyBase* Enemy = Cast<AJMEnemyBase>(Locomotion.GetOwner());
        const UJMEnemyStateComponent* State = Enemy ? Enemy->GetEnemyStateComponent() : nullptr;
        return State ? State->GetCurrentState().ToString() : TEXT("Unknown");
    }

    static void LogRandomMoveFailure(const UJMEnemyLocomotionComponent& Locomotion,
        const FVector& Center, const float Radius, const EJMEnemyMoveRequestResult Result,
        const int32 RetryCount, const int32 MaxRetries, const TCHAR* Reason, const bool bFinal)
    {
        const AActor* Owner = Locomotion.GetOwner();
        if (bFinal)
        {
            UE_LOG(LogJMMonsterFramework, Warning,
                TEXT("AutonomousMove %s: Enemy=%s State=%s Center=%s Radius=%.1f Controller=%s NavSystem=%s Request=%s Retry=%d/%d"),
                Reason, Owner ? *Owner->GetName() : TEXT("None"), *EnemyStateName(Locomotion),
                *Center.ToCompactString(), Radius, Locomotion.IsControllerReady() ? TEXT("Valid") : TEXT("Invalid"),
                Locomotion.IsNavigationReady() ? TEXT("Valid") : TEXT("Invalid"), MoveRequestResultName(Result),
                RetryCount, MaxRetries);
        }
        else
        {
            UE_LOG(LogJMMonsterFramework, Verbose,
                TEXT("AutonomousMove %s; retrying: Enemy=%s State=%s Center=%s Radius=%.1f Controller=%s NavSystem=%s Request=%s Retry=%d/%d"),
                Reason, Owner ? *Owner->GetName() : TEXT("None"), *EnemyStateName(Locomotion),
                *Center.ToCompactString(), Radius, Locomotion.IsControllerReady() ? TEXT("Valid") : TEXT("Invalid"),
                Locomotion.IsNavigationReady() ? TEXT("Valid") : TEXT("Invalid"), MoveRequestResultName(Result),
                RetryCount, MaxRetries);
        }
    }
}

FJMStateTreeWaitForTransitionTask::FJMStateTreeWaitForTransitionTask()
{
    bShouldCallTick = false;
    bShouldCopyBoundPropertiesOnTick = false;
}

EStateTreeRunStatus FJMStateTreeWaitForTransitionTask::EnterState(
    FStateTreeExecutionContext&, const FStateTreeTransitionResult&) const
{
    return EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FJMStateTreeWaitTask::EnterState(
    FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const
{
    FInstanceDataType& Data = Context.GetInstanceData(*this);
    Data.Elapsed = 0.0f;
    return Data.Duration <= 0.0f ? EStateTreeRunStatus::Succeeded : EStateTreeRunStatus::Running;
}

EStateTreeRunStatus FJMStateTreeWaitTask::Tick(
    FStateTreeExecutionContext& Context, const float DeltaTime) const
{
    FInstanceDataType& Data = Context.GetInstanceData(*this);
    Data.Elapsed += FMath::Max(DeltaTime, 0.0f);
    return Data.Elapsed >= Data.Duration ? EStateTreeRunStatus::Succeeded : EStateTreeRunStatus::Running;
}

bool FJMStateTreeSetStateTask::Link(FStateTreeLinker& Linker)
{
    Linker.LinkExternalData(StateHandle);
    return true;
}

EStateTreeRunStatus FJMStateTreeSetStateTask::EnterState(
    FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const
{
    const FInstanceDataType& Data = Context.GetInstanceData(*this);
    UJMEnemyStateComponent& State = Context.GetExternalData(StateHandle);
    return (State.SetState(Data.State) || State.GetCurrentState() == Data.State)
        ? EStateTreeRunStatus::Succeeded : EStateTreeRunStatus::Failed;
}

FJMStateTreeMoveToActorTask::FJMStateTreeMoveToActorTask()
{
    bShouldCallTick = false;
    bShouldCopyBoundPropertiesOnTick = false;
}

bool FJMStateTreeMoveToActorTask::Link(FStateTreeLinker& Linker)
{
    Linker.LinkExternalData(LocomotionHandle);
    return true;
}

EStateTreeRunStatus FJMStateTreeMoveToActorTask::EnterState(
    FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const
{
    FInstanceDataType& Data = Context.GetInstanceData(*this);
    UJMEnemyLocomotionComponent& Locomotion = Context.GetExternalData(LocomotionHandle);
    Data.RequestID = FAIRequestID::InvalidRequest;
    Data.bEntering = true;
    Data.bCompletedDuringEnter = false;
    Data.Completion = EJMEnemyMoveStatus::Idle;
    Data.DelegateHandle = Locomotion.OnMoveFinishedNative.AddLambda(
        [WeakContext = Context.MakeWeakExecutionContext()](const FAIRequestID FinishedID,
            const EJMEnemyMoveStatus Result, AActor*, FVector)
        {
            const FStateTreeStrongExecutionContext Strong = WeakContext.MakeStrongExecutionContext();
            FInstanceDataType* Instance = Strong.GetInstanceDataPtr<FInstanceDataType>();
            if (!Instance || (!Instance->RequestID.IsValid() && FinishedID.IsValid()) ||
                (Instance->RequestID.IsValid() && !Instance->RequestID.IsEquivalent(FinishedID)))
            {
                return;
            }
            if (Instance->bEntering)
            {
                Instance->bCompletedDuringEnter = true;
                Instance->Completion = Result;
            }
            else
            {
                Strong.FinishTask(Result == EJMEnemyMoveStatus::Succeeded
                    ? EStateTreeFinishTaskType::Succeeded : EStateTreeFinishTaskType::Failed);
            }
        });

    const EJMEnemyMoveRequestResult Result = Locomotion.MoveToActor(Data.TargetActor, Data.Options);
    if (Result == EJMEnemyMoveRequestResult::RequestStarted)
    {
        Data.RequestID = Locomotion.GetCurrentRequestID();
    }
    Data.bEntering = false;
    if (Data.bCompletedDuringEnter)
    {
        Locomotion.OnMoveFinishedNative.Remove(Data.DelegateHandle);
        return JMStateTree::ToMoveStatus(Data.Completion);
    }
    if (Result == EJMEnemyMoveRequestResult::AlreadyAtGoal)
    {
        Locomotion.OnMoveFinishedNative.Remove(Data.DelegateHandle);
        return EStateTreeRunStatus::Succeeded;
    }
    if (Result != EJMEnemyMoveRequestResult::RequestStarted)
    {
        Locomotion.OnMoveFinishedNative.Remove(Data.DelegateHandle);
    }
    return Result == EJMEnemyMoveRequestResult::RequestStarted
        ? EStateTreeRunStatus::Running : EStateTreeRunStatus::Failed;
}

void FJMStateTreeMoveToActorTask::ExitState(
    FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const
{
    FInstanceDataType& Data = Context.GetInstanceData(*this);
    UJMEnemyLocomotionComponent& Locomotion = Context.GetExternalData(LocomotionHandle);
    Locomotion.OnMoveFinishedNative.Remove(Data.DelegateHandle);
    if (Data.RequestID.IsValid() && Locomotion.GetCurrentRequestID().IsEquivalent(Data.RequestID))
    {
        Locomotion.StopMovement();
    }
    Data.RequestID = FAIRequestID::InvalidRequest;
}

FJMStateTreeMoveToLocationTask::FJMStateTreeMoveToLocationTask()
{
    bShouldCallTick = false;
    bShouldCopyBoundPropertiesOnTick = false;
}

bool FJMStateTreeMoveToLocationTask::Link(FStateTreeLinker& Linker)
{
    Linker.LinkExternalData(LocomotionHandle);
    return true;
}

EStateTreeRunStatus FJMStateTreeMoveToLocationTask::EnterState(
    FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const
{
    FInstanceDataType& Data = Context.GetInstanceData(*this);
    UJMEnemyLocomotionComponent& Locomotion = Context.GetExternalData(LocomotionHandle);
    Data.RequestID = FAIRequestID::InvalidRequest;
    Data.bEntering = true;
    Data.bCompletedDuringEnter = false;
    Data.Completion = EJMEnemyMoveStatus::Idle;
    Data.DelegateHandle = Locomotion.OnMoveFinishedNative.AddLambda(
        [WeakContext = Context.MakeWeakExecutionContext()](const FAIRequestID FinishedID,
            const EJMEnemyMoveStatus Result, AActor*, FVector)
        {
            const FStateTreeStrongExecutionContext Strong = WeakContext.MakeStrongExecutionContext();
            FInstanceDataType* Instance = Strong.GetInstanceDataPtr<FInstanceDataType>();
            if (!Instance || (!Instance->RequestID.IsValid() && FinishedID.IsValid()) ||
                (Instance->RequestID.IsValid() && !Instance->RequestID.IsEquivalent(FinishedID)))
            {
                return;
            }
            if (Instance->bEntering)
            {
                Instance->bCompletedDuringEnter = true;
                Instance->Completion = Result;
            }
            else
            {
                Strong.FinishTask(Result == EJMEnemyMoveStatus::Succeeded
                    ? EStateTreeFinishTaskType::Succeeded : EStateTreeFinishTaskType::Failed);
            }
        });

    const EJMEnemyMoveRequestResult Result = Locomotion.MoveToLocation(Data.Location, Data.Options);
    if (Result == EJMEnemyMoveRequestResult::RequestStarted)
    {
        Data.RequestID = Locomotion.GetCurrentRequestID();
    }
    Data.bEntering = false;
    if (Data.bCompletedDuringEnter)
    {
        Locomotion.OnMoveFinishedNative.Remove(Data.DelegateHandle);
        return JMStateTree::ToMoveStatus(Data.Completion);
    }
    if (Result == EJMEnemyMoveRequestResult::AlreadyAtGoal)
    {
        Locomotion.OnMoveFinishedNative.Remove(Data.DelegateHandle);
        return EStateTreeRunStatus::Succeeded;
    }
    if (Result != EJMEnemyMoveRequestResult::RequestStarted)
    {
        Locomotion.OnMoveFinishedNative.Remove(Data.DelegateHandle);
    }
    return Result == EJMEnemyMoveRequestResult::RequestStarted
        ? EStateTreeRunStatus::Running : EStateTreeRunStatus::Failed;
}

void FJMStateTreeMoveToLocationTask::ExitState(
    FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const
{
    FInstanceDataType& Data = Context.GetInstanceData(*this);
    UJMEnemyLocomotionComponent& Locomotion = Context.GetExternalData(LocomotionHandle);
    Locomotion.OnMoveFinishedNative.Remove(Data.DelegateHandle);
    if (Data.RequestID.IsValid() && Locomotion.GetCurrentRequestID().IsEquivalent(Data.RequestID))
    {
        Locomotion.StopMovement();
    }
    Data.RequestID = FAIRequestID::InvalidRequest;
}

bool FJMStateTreeStopMovementTask::Link(FStateTreeLinker& Linker)
{
    Linker.LinkExternalData(LocomotionHandle);
    return true;
}

EStateTreeRunStatus FJMStateTreeStopMovementTask::EnterState(
    FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const
{
    Context.GetExternalData(LocomotionHandle).StopMovement();
    return EStateTreeRunStatus::Succeeded;
}

bool FJMStateTreeFaceActorTask::Link(FStateTreeLinker& Linker)
{
    Linker.LinkExternalData(LocomotionHandle);
    return true;
}

EStateTreeRunStatus FJMStateTreeFaceActorTask::EnterState(
    FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const
{
    const FInstanceDataType& Data = Context.GetInstanceData(*this);
    return Context.GetExternalData(LocomotionHandle).FaceActor(Data.TargetActor, Data.Mode)
        ? EStateTreeRunStatus::Succeeded : EStateTreeRunStatus::Failed;
}

bool FJMStateTreeClearFocusTask::Link(FStateTreeLinker& Linker)
{
    Linker.LinkExternalData(LocomotionHandle);
    return true;
}

EStateTreeRunStatus FJMStateTreeClearFocusTask::EnterState(
    FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const
{
    Context.GetExternalData(LocomotionHandle).ClearFacingFocus();
    return EStateTreeRunStatus::Succeeded;
}

bool FJMStateTreeMovementProfileTask::Link(FStateTreeLinker& Linker)
{
    Linker.LinkExternalData(EnemyHandle);
    Linker.LinkExternalData(LocomotionHandle);
    return true;
}

EStateTreeRunStatus FJMStateTreeMovementProfileTask::EnterState(
    FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const
{
    const FInstanceDataType& Data = Context.GetInstanceData(*this);
    const UJMEnemyDefinition* Definition = Context.GetExternalData(EnemyHandle).GetEnemyDefinition();
    return Definition && Context.GetExternalData(LocomotionHandle).ApplyMovementProfile(
        Definition->MovementSet, Data.ProfileName)
        ? EStateTreeRunStatus::Succeeded : EStateTreeRunStatus::Failed;
}

bool FJMStateTreeFindEscapeTask::Link(FStateTreeLinker& Linker)
{
    Linker.LinkExternalData(LocomotionHandle);
    return true;
}

EStateTreeRunStatus FJMStateTreeFindEscapeTask::EnterState(
    FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const
{
    FInstanceDataType& Data = Context.GetInstanceData(*this);
    return Context.GetExternalData(LocomotionHandle).FindEscapeLocation(
        Data.ThreatActor, Data.EscapeDistance, Data.EscapeLocation)
        ? EStateTreeRunStatus::Succeeded : EStateTreeRunStatus::Failed;
}

FJMStateTreeExecuteActionTask::FJMStateTreeExecuteActionTask()
{
    bShouldCallTick = false;
    bShouldCopyBoundPropertiesOnTick = false;
}

bool FJMStateTreeExecuteActionTask::Link(FStateTreeLinker& Linker)
{
    Linker.LinkExternalData(ActionHandle);
    return true;
}

EStateTreeRunStatus FJMStateTreeExecuteActionTask::EnterState(
    FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const
{
    FInstanceDataType& Data = Context.GetInstanceData(*this);
    UJMEnemyActionComponent& Actions = Context.GetExternalData(ActionHandle);
    Data.StartedAction = Actions.GetAction(Data.ActionId);
    if (!Data.StartedAction)
    {
        return EStateTreeRunStatus::Failed;
    }

    Data.bEntering = true;
    Data.bCompletedDuringEnter = false;
    Data.bCompletedSuccessfully = false;
    Data.FinishedHandle = Actions.OnActionFinishedNative.AddLambda(
        [WeakContext = Context.MakeWeakExecutionContext()](FGameplayTag, UJMEnemyAction* Action)
        {
            const FStateTreeStrongExecutionContext Strong = WeakContext.MakeStrongExecutionContext();
            FInstanceDataType* Instance = Strong.GetInstanceDataPtr<FInstanceDataType>();
            if (!Instance || Instance->StartedAction != Action) return;
            if (Instance->bEntering)
            {
                Instance->bCompletedDuringEnter = true;
                Instance->bCompletedSuccessfully = true;
            }
            else Strong.FinishTask(EStateTreeFinishTaskType::Succeeded);
        });
    Data.CancelledHandle = Actions.OnActionCancelledNative.AddLambda(
        [WeakContext = Context.MakeWeakExecutionContext()](FGameplayTag, UJMEnemyAction* Action)
        {
            const FStateTreeStrongExecutionContext Strong = WeakContext.MakeStrongExecutionContext();
            FInstanceDataType* Instance = Strong.GetInstanceDataPtr<FInstanceDataType>();
            if (!Instance || Instance->StartedAction != Action) return;
            if (Instance->bEntering)
            {
                Instance->bCompletedDuringEnter = true;
                Instance->bCompletedSuccessfully = false;
            }
            else Strong.FinishTask(EStateTreeFinishTaskType::Failed);
        });

    FJMEnemyActionContext ActionContext;
    ActionContext.TargetActor = Data.TargetActor;
    ActionContext.TargetLocation = Data.TargetLocation;
    ActionContext.bHasTargetLocation = Data.bHasTargetLocation;
    const EJMEnemyActionExecuteResult Result = Actions.ExecuteAction(Data.ActionId, ActionContext);
    Data.bEntering = false;
    if (Data.bCompletedDuringEnter)
    {
        Actions.OnActionFinishedNative.Remove(Data.FinishedHandle);
        Actions.OnActionCancelledNative.Remove(Data.CancelledHandle);
        return Data.bCompletedSuccessfully ? EStateTreeRunStatus::Succeeded : EStateTreeRunStatus::Failed;
    }
    if (Result != EJMEnemyActionExecuteResult::Started)
    {
        Actions.OnActionFinishedNative.Remove(Data.FinishedHandle);
        Actions.OnActionCancelledNative.Remove(Data.CancelledHandle);
    }
    return Result == EJMEnemyActionExecuteResult::Started
        ? EStateTreeRunStatus::Running : EStateTreeRunStatus::Failed;
}

void FJMStateTreeExecuteActionTask::ExitState(
    FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const
{
    FInstanceDataType& Data = Context.GetInstanceData(*this);
    UJMEnemyActionComponent& Actions = Context.GetExternalData(ActionHandle);
    Actions.OnActionFinishedNative.Remove(Data.FinishedHandle);
    Actions.OnActionCancelledNative.Remove(Data.CancelledHandle);
    if (Data.StartedAction && Actions.GetCurrentAction() == Data.StartedAction)
    {
        Actions.CancelCurrentAction();
    }
    Data.StartedAction = nullptr;
}

bool FJMStateTreeIncrementEncounterTask::Link(FStateTreeLinker& Linker)
{
    Linker.LinkExternalData(MemoryHandle);
    return true;
}

EStateTreeRunStatus FJMStateTreeIncrementEncounterTask::EnterState(
    FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const
{
    Context.GetExternalData(MemoryHandle).IncrementEncounterCount();
    return EStateTreeRunStatus::Succeeded;
}

bool FJMStateTreeSetTargetTask::Link(FStateTreeLinker& Linker)
{
    Linker.LinkExternalData(MemoryHandle);
    return true;
}

EStateTreeRunStatus FJMStateTreeSetTargetTask::EnterState(
    FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const
{
    const FInstanceDataType& Data = Context.GetInstanceData(*this);
    UJMEnemyMemoryComponent& Memory = Context.GetExternalData(MemoryHandle);
    AActor* TargetActor = Data.bUseLastSeenSource ? Memory.GetLastSeenSource() : Data.TargetActor.Get();
    if (!IsValid(TargetActor) || TargetActor->IsActorBeingDestroyed())
    {
        return EStateTreeRunStatus::Failed;
    }
    return (Memory.SetCurrentTarget(TargetActor) || Memory.GetCurrentTarget() == TargetActor)
        ? EStateTreeRunStatus::Succeeded : EStateTreeRunStatus::Failed;
}

bool FJMStateTreeClearTargetTask::Link(FStateTreeLinker& Linker)
{
    Linker.LinkExternalData(MemoryHandle);
    return true;
}

EStateTreeRunStatus FJMStateTreeClearTargetTask::EnterState(
    FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const
{
    Context.GetExternalData(MemoryHandle).ClearCurrentTarget();
    return EStateTreeRunStatus::Succeeded;
}

FJMStateTreeMoveRandomTask::FJMStateTreeMoveRandomTask()
{
    bShouldCallTick = true;
    bShouldCopyBoundPropertiesOnTick = false;
}

bool FJMStateTreeMoveRandomTask::Link(FStateTreeLinker& Linker)
{
    Linker.LinkExternalData(LocomotionHandle);
    return true;
}

EStateTreeRunStatus FJMStateTreeMoveRandomTask::EnterState(
    FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const
{
    FInstanceDataType& Data = Context.GetInstanceData(*this);
    UJMEnemyLocomotionComponent& Locomotion = Context.GetExternalData(LocomotionHandle);
    const AActor* Owner = Locomotion.GetOwner();
    const FVector Origin = Data.bUseHomeAsCenter ? Locomotion.GetHomeLocation() :
        (Data.bUseOwnerAsCenter && Owner ? Owner->GetActorLocation() : Data.Center);

    Data.RequestID = FAIRequestID::InvalidRequest;
    Data.RetryCount = 0;
    Data.RemainingTime = 0.0f;
    Data.Phase = static_cast<uint8>(JMStateTree::ERandomMovePhase::Selecting);
    Data.LastRequestResult = EJMEnemyMoveRequestResult::RequestFailed;

    if (Data.Radius <= 0.0f ||
        !Locomotion.FindRandomReachableLocation(Origin, Data.Radius, Data.ChosenLocation))
    {
        Data.RetryCount = 1;
        Data.RemainingTime = FMath::Max(Data.RetryBackoff, 0.01f);
        Data.Phase = static_cast<uint8>(JMStateTree::ERandomMovePhase::Backoff);
        JMStateTree::LogRandomMoveFailure(Locomotion, Origin, Data.Radius, Data.LastRequestResult,
            Data.RetryCount, Data.MaxRetries, TEXT("destination selection failed"), Data.MaxRetries <= 0);
        return Data.MaxRetries > 0 ? EStateTreeRunStatus::Running : EStateTreeRunStatus::Failed;
    }

    FJMEnemyMoveOptions ReachableOptions = Data.Options;
    ReachableOptions.bProjectGoalLocation = false;
    Data.LastRequestResult = Locomotion.MoveToLocation(Data.ChosenLocation, ReachableOptions);
    if (Data.LastRequestResult == EJMEnemyMoveRequestResult::RequestStarted)
    {
        Data.RequestID = Locomotion.GetCurrentRequestID();
        Data.Phase = static_cast<uint8>(JMStateTree::ERandomMovePhase::Moving);
        return EStateTreeRunStatus::Running;
    }
    if (Data.LastRequestResult == EJMEnemyMoveRequestResult::AlreadyAtGoal)
    {
        Data.RemainingTime = FMath::FRandRange(FMath::Min(Data.MinWaitTime, Data.MaxWaitTime),
            FMath::Max(Data.MinWaitTime, Data.MaxWaitTime));
        Data.Phase = static_cast<uint8>(JMStateTree::ERandomMovePhase::Waiting);
        return Data.RemainingTime > 0.0f ? EStateTreeRunStatus::Running : EStateTreeRunStatus::Succeeded;
    }

    Data.RetryCount = 1;
    Data.RemainingTime = FMath::Max(Data.RetryBackoff, 0.01f);
    Data.Phase = static_cast<uint8>(JMStateTree::ERandomMovePhase::Backoff);
    JMStateTree::LogRandomMoveFailure(Locomotion, Origin, Data.Radius, Data.LastRequestResult,
        Data.RetryCount, Data.MaxRetries, TEXT("MoveTo request failed"), Data.MaxRetries <= 0);
    return Data.MaxRetries > 0 ? EStateTreeRunStatus::Running : EStateTreeRunStatus::Failed;
}

EStateTreeRunStatus FJMStateTreeMoveRandomTask::Tick(
    FStateTreeExecutionContext& Context, const float DeltaTime) const
{
    FInstanceDataType& Data = Context.GetInstanceData(*this);
    UJMEnemyLocomotionComponent& Locomotion = Context.GetExternalData(LocomotionHandle);
    const AActor* Owner = Locomotion.GetOwner();
    const FVector Origin = Data.bUseHomeAsCenter ? Locomotion.GetHomeLocation() :
        (Data.bUseOwnerAsCenter && Owner ? Owner->GetActorLocation() : Data.Center);
    const JMStateTree::ERandomMovePhase Phase = static_cast<JMStateTree::ERandomMovePhase>(Data.Phase);

    if (Phase == JMStateTree::ERandomMovePhase::Moving)
    {
        if (Data.RequestID.IsValid() && Locomotion.GetCurrentRequestID().IsEquivalent(Data.RequestID) &&
            Locomotion.GetMoveStatus() == EJMEnemyMoveStatus::Moving)
        {
            return EStateTreeRunStatus::Running;
        }
        if (Locomotion.GetLastMoveResult() == EJMEnemyMoveStatus::Succeeded)
        {
            Data.RemainingTime = FMath::FRandRange(FMath::Min(Data.MinWaitTime, Data.MaxWaitTime),
                FMath::Max(Data.MinWaitTime, Data.MaxWaitTime));
            Data.Phase = static_cast<uint8>(JMStateTree::ERandomMovePhase::Waiting);
            return Data.RemainingTime > 0.0f ? EStateTreeRunStatus::Running : EStateTreeRunStatus::Succeeded;
        }
        Data.LastRequestResult = EJMEnemyMoveRequestResult::RequestFailed;
        ++Data.RetryCount;
        JMStateTree::LogRandomMoveFailure(Locomotion, Origin, Data.Radius, Data.LastRequestResult,
            Data.RetryCount, Data.MaxRetries, TEXT("asynchronous move failed"), Data.RetryCount > Data.MaxRetries);
        if (Data.RetryCount > Data.MaxRetries)
        {
            return EStateTreeRunStatus::Failed;
        }
        Data.RemainingTime = FMath::Max(Data.RetryBackoff * Data.RetryCount, 0.01f);
        Data.Phase = static_cast<uint8>(JMStateTree::ERandomMovePhase::Backoff);
        return EStateTreeRunStatus::Running;
    }

    Data.RemainingTime = FMath::Max(0.0f, Data.RemainingTime - DeltaTime);
    if (Data.RemainingTime > 0.0f)
    {
        return EStateTreeRunStatus::Running;
    }
    if (Phase == JMStateTree::ERandomMovePhase::Waiting)
    {
        return EStateTreeRunStatus::Succeeded;
    }

    if (!Locomotion.FindRandomReachableLocation(Origin, Data.Radius, Data.ChosenLocation))
    {
        ++Data.RetryCount;
        JMStateTree::LogRandomMoveFailure(Locomotion, Origin, Data.Radius, Data.LastRequestResult,
            Data.RetryCount, Data.MaxRetries, TEXT("destination retry failed"), Data.RetryCount > Data.MaxRetries);
        if (Data.RetryCount > Data.MaxRetries)
        {
            return EStateTreeRunStatus::Failed;
        }
        Data.RemainingTime = FMath::Max(Data.RetryBackoff * Data.RetryCount, 0.01f);
        return EStateTreeRunStatus::Running;
    }

    FJMEnemyMoveOptions ReachableOptions = Data.Options;
    ReachableOptions.bProjectGoalLocation = false;
    Data.LastRequestResult = Locomotion.MoveToLocation(Data.ChosenLocation, ReachableOptions);
    if (Data.LastRequestResult == EJMEnemyMoveRequestResult::RequestStarted)
    {
        Data.RequestID = Locomotion.GetCurrentRequestID();
        Data.Phase = static_cast<uint8>(JMStateTree::ERandomMovePhase::Moving);
        return EStateTreeRunStatus::Running;
    }
    if (Data.LastRequestResult == EJMEnemyMoveRequestResult::AlreadyAtGoal)
    {
        Data.RemainingTime = FMath::FRandRange(FMath::Min(Data.MinWaitTime, Data.MaxWaitTime),
            FMath::Max(Data.MinWaitTime, Data.MaxWaitTime));
        Data.Phase = static_cast<uint8>(JMStateTree::ERandomMovePhase::Waiting);
        return Data.RemainingTime > 0.0f ? EStateTreeRunStatus::Running : EStateTreeRunStatus::Succeeded;
    }

    ++Data.RetryCount;
    JMStateTree::LogRandomMoveFailure(Locomotion, Origin, Data.Radius, Data.LastRequestResult,
        Data.RetryCount, Data.MaxRetries, TEXT("MoveTo retry failed"), Data.RetryCount > Data.MaxRetries);
    if (Data.RetryCount > Data.MaxRetries)
    {
        return EStateTreeRunStatus::Failed;
    }
    Data.RemainingTime = FMath::Max(Data.RetryBackoff * Data.RetryCount, 0.01f);
    Data.Phase = static_cast<uint8>(JMStateTree::ERandomMovePhase::Backoff);
    return EStateTreeRunStatus::Running;
}

void FJMStateTreeMoveRandomTask::ExitState(
    FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const
{
    FInstanceDataType& Data = Context.GetInstanceData(*this);
    UJMEnemyLocomotionComponent& Locomotion = Context.GetExternalData(LocomotionHandle);
    if (Data.RequestID.IsValid() && Locomotion.GetCurrentRequestID().IsEquivalent(Data.RequestID))
    {
        Locomotion.StopMovement();
    }
    Data.RequestID = FAIRequestID::InvalidRequest;
}
