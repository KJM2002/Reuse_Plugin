#pragma once

#include "StateTreeConditionBase.h"
#include "StateTreeEvaluatorBase.h"
#include "JMEnemyStateTreeConditions.generated.h"

class UJMEnemyMemoryComponent;
class UJMEnemyPerceptionComponent;
class UJMEnemyStateComponent;
class UJMEnemyActionComponent;

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeEmptyConditionInstanceData
{
    GENERATED_BODY()
};

UENUM()
enum class EJMStateTreeCompare : uint8
{
    Equal,
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual
};

namespace JMEnemyStateTreeConditions
{
    JMMONSTERFRAMEWORKRUNTIME_API bool Compare(float Value, float Threshold, EJMStateTreeCompare Operation);
    JMMONSTERFRAMEWORKRUNTIME_API bool Compare(int32 Value, int32 Threshold, EJMStateTreeCompare Operation);
    JMMONSTERFRAMEWORKRUNTIME_API bool HasTarget(const UJMEnemyMemoryComponent& Memory);
    JMMONSTERFRAMEWORKRUNTIME_API bool HasRecentHearing(const UJMEnemyMemoryComponent& Memory, float MaximumAge);
    JMMONSTERFRAMEWORKRUNTIME_API bool HasRecentVision(const UJMEnemyMemoryComponent& Memory, float MaximumAge);
    JMMONSTERFRAMEWORKRUNTIME_API bool HasGaze(const UJMEnemyPerceptionComponent& Perception,
        float MinimumStrength, float MinimumDuration);
}

USTRUCT(meta=(DisplayName="Has Target", Category="JM Monster Framework|Memory"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeHasTargetCondition : public FStateTreeConditionCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeEmptyConditionInstanceData;
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;
    TStateTreeExternalDataHandle<UJMEnemyMemoryComponent> MemoryHandle;
};

USTRUCT(meta=(DisplayName="Can See Target", Category="JM Monster Framework|Perception"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeCanSeeTargetCondition : public FStateTreeConditionCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeEmptyConditionInstanceData;
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;
    TStateTreeExternalDataHandle<UJMEnemyMemoryComponent> MemoryHandle;
};

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeActorVisionInstanceData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, Category=Parameter) TObjectPtr<AActor> Actor;
    UPROPERTY(EditAnywhere, Category=Parameter) bool bUseLastSeenSource = false;
};

USTRUCT(meta=(DisplayName="Can See Actor", Category="JM Monster Framework|Perception"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeActorVisionCondition : public FStateTreeConditionCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeActorVisionInstanceData;
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;
    TStateTreeExternalDataHandle<UJMEnemyMemoryComponent> MemoryHandle;
};

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeRecentHearingInstanceData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, Category=Parameter, meta=(ClampMin="0.0")) float MaximumAge = 2.0f;
    UPROPERTY(EditAnywhere, Category=Parameter) bool bInvert = false;
};

USTRUCT(meta=(DisplayName="Has Heard Recently", Category="JM Monster Framework|Memory"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeRecentHearingCondition : public FStateTreeConditionCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeRecentHearingInstanceData;
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;
    TStateTreeExternalDataHandle<UJMEnemyMemoryComponent> MemoryHandle;
};

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeGazeInstanceData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, Category=Parameter, meta=(ClampMin="0.0", ClampMax="1.0")) float MinimumStrength = 0.0f;
    UPROPERTY(EditAnywhere, Category=Parameter, meta=(ClampMin="0.0")) float MinimumDuration = 0.0f;
    UPROPERTY(EditAnywhere, Category=Parameter) bool bInvert = false;
};

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeRecentVisionInstanceData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, Category=Parameter, meta=(ClampMin="0.0")) float MaximumAge = 1.5f;
    UPROPERTY(EditAnywhere, Category=Parameter) bool bInvert = false;
};

USTRUCT(meta=(DisplayName="Has Seen Current Target Recently", Category="JM Monster Framework|Memory"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeRecentVisionCondition : public FStateTreeConditionCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeRecentVisionInstanceData;
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;
    TStateTreeExternalDataHandle<UJMEnemyMemoryComponent> MemoryHandle;
};

USTRUCT(meta=(DisplayName="Player Looking At Enemy", Category="JM Monster Framework|Perception"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeGazeCondition : public FStateTreeConditionCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeGazeInstanceData;
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;
    TStateTreeExternalDataHandle<UJMEnemyPerceptionComponent> PerceptionHandle;
};

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeDistanceInstanceData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, Category=Parameter) TObjectPtr<AActor> TargetActor;
    UPROPERTY(EditAnywhere, Category=Parameter, meta=(ClampMin="0.0")) float Distance = 500.0f;
    UPROPERTY(EditAnywhere, Category=Parameter) EJMStateTreeCompare Comparison = EJMStateTreeCompare::LessOrEqual;
};

USTRUCT(meta=(DisplayName="Target Distance", Category="JM Monster Framework|Perception"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeDistanceCondition : public FStateTreeConditionCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeDistanceInstanceData;
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;
    TStateTreeExternalDataHandle<UJMEnemyMemoryComponent> MemoryHandle;
};

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeEncounterInstanceData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, Category=Parameter) int32 Threshold = 1;
    UPROPERTY(EditAnywhere, Category=Parameter) EJMStateTreeCompare Comparison = EJMStateTreeCompare::GreaterOrEqual;
};

USTRUCT(meta=(DisplayName="Encounter Count", Category="JM Monster Framework|Memory"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeEncounterCondition : public FStateTreeConditionCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeEncounterInstanceData;
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;
    TStateTreeExternalDataHandle<UJMEnemyMemoryComponent> MemoryHandle;
};

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeStateTagInstanceData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, Category=Parameter, meta=(Categories="JM.Enemy.State")) FGameplayTag State;
};

USTRUCT(meta=(DisplayName="Enemy Is In State", Category="JM Monster Framework|State"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeStateTagCondition : public FStateTreeConditionCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeStateTagInstanceData;
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;
    TStateTreeExternalDataHandle<UJMEnemyStateComponent> StateHandle;
};

/** Lightweight binding snapshot. Truth-testing conditions still query their owning components directly. */
USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeContextInstanceData
{
    GENERATED_BODY()
    UPROPERTY(VisibleAnywhere, Category=Output) TObjectPtr<AActor> CurrentTarget;
    UPROPERTY(VisibleAnywhere, Category=Output) TObjectPtr<AActor> LastHeardSource;
    UPROPERTY(VisibleAnywhere, Category=Output) TObjectPtr<AActor> LastSeenSource;
    UPROPERTY(VisibleAnywhere, Category=Output) FVector LastKnownLocation = FVector::ZeroVector;
    UPROPERTY(VisibleAnywhere, Category=Output) FVector LastSeenLocation = FVector::ZeroVector;
    UPROPERTY(VisibleAnywhere, Category=Output) FVector LastHeardLocation = FVector::ZeroVector;
    UPROPERTY(VisibleAnywhere, Category=Output) bool bCanSeeTarget = false;
    UPROPERTY(VisibleAnywhere, Category=Output) float GazeStrength = 0.0f;
    UPROPERTY(VisibleAnywhere, Category=Output) float GazeDuration = 0.0f;
    UPROPERTY(VisibleAnywhere, Category=Output) int32 EncounterCount = 0;
    UPROPERTY(VisibleAnywhere, Category=Output) float TimeSinceLastHeard = -1.0f;
    UPROPERTY(VisibleAnywhere, Category=Output) float TimeSinceLastSeen = -1.0f;
};

USTRUCT(meta=(DisplayName="JM Enemy Context", Category="JM Monster Framework|Context"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeContextEvaluator : public FStateTreeEvaluatorCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeContextInstanceData;
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual void TreeStart(FStateTreeExecutionContext& Context) const override;
    virtual void Tick(FStateTreeExecutionContext& Context, float DeltaTime) const override;
    TStateTreeExternalDataHandle<UJMEnemyMemoryComponent> MemoryHandle;
    TStateTreeExternalDataHandle<UJMEnemyPerceptionComponent> PerceptionHandle;
};

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeCombatTargetInstanceData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, Category=Parameter) TObjectPtr<AActor> Actor;
    UPROPERTY(EditAnywhere, Category=Parameter) bool bUseLastSeenSource = false;
    UPROPERTY(EditAnywhere, Category=Policy) bool bRequirePawn = true;
    UPROPERTY(EditAnywhere, Category=Policy) bool bRequirePlayerControlled = true;
    UPROPERTY(EditAnywhere, Category=Policy) bool bRequireDamageable = true;
};

/** Generic V1 eligibility policy; it never assigns the target. */
USTRUCT(meta=(DisplayName="Actor Is Combat Target", Category="JM Monster Framework|Target"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeCombatTargetCondition : public FStateTreeConditionCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeCombatTargetInstanceData;
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;
    TStateTreeExternalDataHandle<UJMEnemyMemoryComponent> MemoryHandle;
};

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeTargetHearingInstanceData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, Category=Parameter, meta=(ClampMin="0.0")) float MaximumAge = 2.0f;
    UPROPERTY(EditAnywhere, Category=Parameter) bool bInvert = false;
};

USTRUCT(meta=(DisplayName="Has Heard Current Target Recently", Category="JM Monster Framework|Memory"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeTargetHearingCondition : public FStateTreeConditionCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeTargetHearingInstanceData;
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;
    TStateTreeExternalDataHandle<UJMEnemyMemoryComponent> MemoryHandle;
};

USTRUCT()
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeActionReadyInstanceData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, Category=Parameter, meta=(Categories="JM.Enemy.Action")) FGameplayTag ActionId;
    UPROPERTY(EditAnywhere, Category=Parameter) TObjectPtr<AActor> TargetActor;
    UPROPERTY(EditAnywhere, Category=Parameter) FVector TargetLocation = FVector::ZeroVector;
    UPROPERTY(EditAnywhere, Category=Parameter) bool bHasTargetLocation = false;
};

USTRUCT(meta=(DisplayName="Can Execute Enemy Action", Category="JM Monster Framework|Action"))
struct JMMONSTERFRAMEWORKRUNTIME_API FJMStateTreeActionReadyCondition : public FStateTreeConditionCommonBase
{
    GENERATED_BODY()
    using FInstanceDataType = FJMStateTreeActionReadyInstanceData;
    virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
    virtual bool Link(FStateTreeLinker& Linker) override;
    virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;
    TStateTreeExternalDataHandle<UJMEnemyActionComponent> ActionHandle;
};
