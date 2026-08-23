#pragma once

#include "AITypes.h"
#include "Action/JMEnemyActionTypes.h"
#include "Locomotion/JMEnemyMovementTypes.h"
#include "StateTreeTaskBase.h"
#include "StateTreeExecutionTypes.h"
#include "JMEnemyStateTreeTasks.generated.h"

class AJMEnemyBase;
class UJMEnemyAction;
class UJMEnemyActionComponent;
class UJMEnemyLocomotionComponent;
class UJMEnemyMemoryComponent;
class UJMEnemyPatrolComponent;
class UJMEnemyPerceptionComponent;
class UJMEnemyStateComponent;

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeEmptyTaskInstanceData
{
    GENERATED_BODY()
};

/** Keeps a state active until one of its transitions fires. */
USTRUCT(meta=(DisplayName="Wait For Transition", Category="JM Monster Framework|Flow"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeWaitForTransitionTask : public FStateTreeTaskCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeEmptyTaskInstanceData;
    FJMStateTreeWaitForTransitionTask();
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext&, const FStateTreeTransitionResult&) const override;
};

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeWaitInstanceData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, Category=Parameter, meta=(ClampMin="0.0")) float Duration = 3.0f;
    float Elapsed = 0.0f;
};

USTRUCT(meta=(DisplayName="Wait", Category="JM Monster Framework|Flow"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeWaitTask : public FStateTreeTaskCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeWaitInstanceData;
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext&, const FStateTreeTransitionResult&) const override;
    virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext&, float DeltaTime) const override;
};

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeSetStateInstanceData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, Category=Parameter, meta=(Categories="JM.Enemy.State")) FGameplayTag State;
};

USTRUCT(meta=(DisplayName="Set Enemy State", Category="JM Monster Framework|State"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeSetStateTask : public FStateTreeTaskCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeSetStateInstanceData;
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const override;
    TStateTreeExternalDataHandle<UJMEnemyStateComponent> StateHandle;
};

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeMoveToActorInstanceData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, Category=Parameter) TObjectPtr<AActor> TargetActor;
    UPROPERTY(EditAnywhere, Category=Parameter) FJMEnemyMoveOptions Options;
    FAIRequestID RequestID = FAIRequestID::InvalidRequest;
    FDelegateHandle DelegateHandle;
    bool bEntering = false;
    bool bCompletedDuringEnter = false;
    EJMEnemyMoveStatus Completion = EJMEnemyMoveStatus::Idle;
};

USTRUCT(meta=(DisplayName="Move To Actor", Category="JM Monster Framework|Movement"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeMoveToActorTask : public FStateTreeTaskCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeMoveToActorInstanceData;
    FJMStateTreeMoveToActorTask();
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const override;
    virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const override;
    TStateTreeExternalDataHandle<UJMEnemyLocomotionComponent> LocomotionHandle;
};

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeMoveToLocationInstanceData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, Category=Parameter) FVector Location = FVector::ZeroVector;
    UPROPERTY(EditAnywhere, Category=Parameter) FJMEnemyMoveOptions Options;
    FAIRequestID RequestID = FAIRequestID::InvalidRequest;
    FDelegateHandle DelegateHandle;
    FVector SubmittedLocation = FVector::ZeroVector;
    bool bRetargeting = false;
    bool bEntering = false;
    bool bCompletedDuringEnter = false;
    EJMEnemyMoveStatus Completion = EJMEnemyMoveStatus::Idle;
};

USTRUCT(meta=(DisplayName="Move To Location", Category="JM Monster Framework|Movement"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeMoveToLocationTask : public FStateTreeTaskCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeMoveToLocationInstanceData;
    FJMStateTreeMoveToLocationTask();
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const override;
    virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;
    virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const override;
    TStateTreeExternalDataHandle<UJMEnemyLocomotionComponent> LocomotionHandle;
};

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeFaceActorInstanceData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, Category=Parameter) TObjectPtr<AActor> TargetActor;
    UPROPERTY(EditAnywhere, Category=Parameter) EJMEnemyFacingMode Mode = EJMEnemyFacingMode::ControllerFocus;
};

USTRUCT(meta=(DisplayName="Stop Movement", Category="JM Monster Framework|Movement"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeStopMovementTask : public FStateTreeTaskCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeEmptyTaskInstanceData;
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const override;
    TStateTreeExternalDataHandle<UJMEnemyLocomotionComponent> LocomotionHandle;
};

USTRUCT(meta=(DisplayName="Face Actor", Category="JM Monster Framework|Movement"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeFaceActorTask : public FStateTreeTaskCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeFaceActorInstanceData;
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const override;
    TStateTreeExternalDataHandle<UJMEnemyLocomotionComponent> LocomotionHandle;
};

USTRUCT(meta=(DisplayName="Clear Facing Focus", Category="JM Monster Framework|Movement"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeClearFocusTask : public FStateTreeTaskCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeEmptyTaskInstanceData;
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const override;
    TStateTreeExternalDataHandle<UJMEnemyLocomotionComponent> LocomotionHandle;
};

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeMovementProfileInstanceData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, Category=Parameter) FName ProfileName;
};

USTRUCT(meta=(DisplayName="Set Movement Profile", Category="JM Monster Framework|Movement"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeMovementProfileTask : public FStateTreeTaskCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeMovementProfileInstanceData;
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const override;
    TStateTreeExternalDataHandle<AJMEnemyBase> EnemyHandle;
    TStateTreeExternalDataHandle<UJMEnemyLocomotionComponent> LocomotionHandle;
};

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeFindEscapeInstanceData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, Category=Parameter) TObjectPtr<AActor> ThreatActor;
    UPROPERTY(EditAnywhere, Category=Parameter, meta=(ClampMin="0.0")) float EscapeDistance = 1000.0f;
    UPROPERTY(EditAnywhere, Category=Output) FVector EscapeLocation = FVector::ZeroVector;
};

USTRUCT(meta=(DisplayName="Find Escape Location", Category="JM Monster Framework|Movement"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeFindEscapeTask : public FStateTreeTaskCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeFindEscapeInstanceData;
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const override;
    TStateTreeExternalDataHandle<UJMEnemyLocomotionComponent> LocomotionHandle;
};

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeExecuteActionInstanceData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, Category=Parameter, meta=(Categories="JM.Enemy.Action")) FGameplayTag ActionId;
    UPROPERTY(EditAnywhere, Category=Parameter) TObjectPtr<AActor> TargetActor;
    UPROPERTY(EditAnywhere, Category=Parameter) FVector TargetLocation = FVector::ZeroVector;
    UPROPERTY(EditAnywhere, Category=Parameter) bool bHasTargetLocation = false;
    UPROPERTY(Transient) TObjectPtr<UJMEnemyAction> StartedAction;
    FDelegateHandle FinishedHandle;
    FDelegateHandle CancelledHandle;
    bool bEntering = false;
    bool bCompletedDuringEnter = false;
    bool bCompletedSuccessfully = false;
};

USTRUCT(meta=(DisplayName="Execute Enemy Action", Category="JM Monster Framework|Action"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeExecuteActionTask : public FStateTreeTaskCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeExecuteActionInstanceData;
    FJMStateTreeExecuteActionTask();
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const override;
    virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const override;
    TStateTreeExternalDataHandle<UJMEnemyActionComponent> ActionHandle;
};

USTRUCT(meta=(DisplayName="Increment Encounter Count", Category="JM Monster Framework|Memory"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeIncrementEncounterTask : public FStateTreeTaskCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeEmptyTaskInstanceData;
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const override;
    TStateTreeExternalDataHandle<UJMEnemyMemoryComponent> MemoryHandle;
};

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeSetTargetInstanceData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, Category=Parameter) TObjectPtr<AActor> TargetActor;
    UPROPERTY(EditAnywhere, Category=Parameter) bool bUseLastSeenSource = false;
};

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeWaitForGazeReleaseInstanceData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, Category=Parameter, meta=(ClampMin="0.0")) float MinimumDuration = 0.0f;
    float Elapsed = 0.0f;
};

/** Finishes only after the minimum hide time has elapsed and the player is no longer observing the enemy. */
USTRUCT(meta=(DisplayName="Wait For Gaze Release", Category="JM Monster Framework|Perception"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeWaitForGazeReleaseTask : public FStateTreeTaskCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeWaitForGazeReleaseInstanceData;
    FJMStateTreeWaitForGazeReleaseTask();
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext&, const FStateTreeTransitionResult&) const override;
    virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, float DeltaTime) const override;
    TStateTreeExternalDataHandle<UJMEnemyPerceptionComponent> PerceptionHandle;
};

USTRUCT(meta=(DisplayName="Set Current Target", Category="JM Monster Framework|Target"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeSetTargetTask : public FStateTreeTaskCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeSetTargetInstanceData;
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const override;
    TStateTreeExternalDataHandle<UJMEnemyMemoryComponent> MemoryHandle;
};

USTRUCT(meta=(DisplayName="Clear Current Target", Category="JM Monster Framework|Target"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeClearTargetTask : public FStateTreeTaskCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeEmptyTaskInstanceData;
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const override;
    TStateTreeExternalDataHandle<UJMEnemyMemoryComponent> MemoryHandle;
};

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeMoveRandomInstanceData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, Category=Parameter) FVector Center = FVector::ZeroVector;
    /** Uses the locomotion component's spawn anchor. Preferred for patrol/roam loops. */
    UPROPERTY(EditAnywhere, Category=Parameter) bool bUseHomeAsCenter = true;
    /** Legacy/current-position mode for search behavior. Ignored when bUseHomeAsCenter is true. */
    UPROPERTY(EditAnywhere, Category=Parameter) bool bUseOwnerAsCenter = false;
    UPROPERTY(EditAnywhere, Category=Parameter, meta=(ClampMin="1.0")) float Radius = 600.0f;
    UPROPERTY(EditAnywhere, Category=Parameter, meta=(ClampMin="0.0")) float MinWaitTime = 0.25f;
    UPROPERTY(EditAnywhere, Category=Parameter, meta=(ClampMin="0.0")) float MaxWaitTime = 1.0f;
    UPROPERTY(EditAnywhere, Category=Parameter, meta=(ClampMin="0.01")) float RetryBackoff = 0.25f;
    UPROPERTY(EditAnywhere, Category=Parameter, meta=(ClampMin="0", ClampMax="10")) int32 MaxRetries = 3;
    /** Number of destinations to inspect before this task succeeds. One preserves legacy patrol behavior. */
    UPROPERTY(EditAnywhere, Category=Parameter, meta=(ClampMin="1", ClampMax="8")) int32 NumberOfLocations = 1;
    UPROPERTY(EditAnywhere, Category=Parameter) FJMEnemyMoveOptions Options;
    UPROPERTY(VisibleAnywhere, Category=Output) FVector ChosenLocation = FVector::ZeroVector;
    FAIRequestID RequestID = FAIRequestID::InvalidRequest;
    float RemainingTime = 0.0f;
    int32 RetryCount = 0;
    int32 CompletedLocations = 0;
    uint8 Phase = 0;
    EJMEnemyMoveRequestResult LastRequestResult = EJMEnemyMoveRequestResult::RequestFailed;
};

/** Selects and moves to a reachable point as one atomic async command, suitable for patrol/search loops. */
USTRUCT(meta=(DisplayName="Move To Random Reachable Location", Category="JM Monster Framework|Movement"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeMoveRandomTask : public FStateTreeTaskCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeMoveRandomInstanceData;
    FJMStateTreeMoveRandomTask();
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const override;
    virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, float DeltaTime) const override;
    virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const override;
    TStateTreeExternalDataHandle<UJMEnemyLocomotionComponent> LocomotionHandle;
};

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreePatrolInstanceData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, Category=Parameter, meta=(ClampMin="0.01")) float RetryBackoff = 0.25f;
    UPROPERTY(EditAnywhere, Category=Parameter, meta=(ClampMin="0", ClampMax="10")) int32 MaxRetries = 3;
    UPROPERTY(EditAnywhere, Category=Parameter) FJMEnemyMoveOptions Options;
    UPROPERTY(VisibleAnywhere, Category=Output) FVector ChosenLocation = FVector::ZeroVector;
    float RemainingTime = 0.0f;
    int32 RetryCount = 0;
    FAIRequestID RequestID = FAIRequestID::InvalidRequest;
    uint8 Phase = 0;
};

/** Executes exactly one destination supplied by Patrol, then waits once. */
USTRUCT(meta=(DisplayName="Move Along Patrol", Category="JM Monster Framework|Patrol"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeMovePatrolTask : public FStateTreeTaskCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreePatrolInstanceData;
    FJMStateTreeMovePatrolTask();
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const override;
    virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, float DeltaTime) const override;
    virtual void ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult&) const override;
    TStateTreeExternalDataHandle<UJMEnemyLocomotionComponent> LocomotionHandle;
    TStateTreeExternalDataHandle<UJMEnemyPatrolComponent> PatrolHandle;
};
