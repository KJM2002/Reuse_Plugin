#include "StateTree/JMEnemyStateTreeConditions.h"

#include "Action/JMEnemyActionComponent.h"
#include "Core/JMEnemyBase.h"
#include "Core/JMEnemyDefinition.h"
#include "GameFramework/Pawn.h"
#include "Memory/JMEnemyMemoryComponent.h"
#include "Perception/JMEnemyPerceptionComponent.h"
#include "State/JMEnemyStateComponent.h"
#include "StateTreeExecutionContext.h"
#include "StateTreeLinker.h"

namespace JMEnemyStateTreeConditions
{
    bool Compare(const float Value, const float Threshold, const EJMStateTreeCompare Operation)
    {
        switch (Operation)
        {
        case EJMStateTreeCompare::Equal: return FMath::IsNearlyEqual(Value, Threshold);
        case EJMStateTreeCompare::Less: return Value < Threshold;
        case EJMStateTreeCompare::LessOrEqual: return Value <= Threshold;
        case EJMStateTreeCompare::Greater: return Value > Threshold;
        case EJMStateTreeCompare::GreaterOrEqual: return Value >= Threshold;
        }
        return false;
    }

    bool Compare(const int32 Value, const int32 Threshold, const EJMStateTreeCompare Operation)
    {
        switch (Operation)
        {
        case EJMStateTreeCompare::Equal: return Value == Threshold;
        case EJMStateTreeCompare::Less: return Value < Threshold;
        case EJMStateTreeCompare::LessOrEqual: return Value <= Threshold;
        case EJMStateTreeCompare::Greater: return Value > Threshold;
        case EJMStateTreeCompare::GreaterOrEqual: return Value >= Threshold;
        }
        return false;
    }

    bool HasTarget(const UJMEnemyMemoryComponent& Memory) { return IsValid(Memory.GetCurrentTarget()); }
    bool HasRecentHearing(const UJMEnemyMemoryComponent& Memory, const float MaximumAge)
    {
        return MaximumAge >= 0.0f && Memory.HasHeardStimulusRecently(MaximumAge);
    }
    bool HasRecentVision(const UJMEnemyMemoryComponent& Memory, const float MaximumAge)
    {
        return MaximumAge >= 0.0f && Memory.HasSeenTargetRecently(MaximumAge);
    }
    bool HasGaze(const UJMEnemyPerceptionComponent& Perception,
        const float MinimumStrength, const float MinimumDuration)
    {
        return Perception.IsPlayerLookingAtMe() && Perception.GetGazeStrength() >= MinimumStrength &&
            Perception.GetGazeDuration() >= MinimumDuration;
    }
}

bool FJMStateTreeHasTargetCondition::Link(FStateTreeLinker& Linker) { Linker.LinkExternalData(MemoryHandle); return true; }
bool FJMStateTreeHasTargetCondition::TestCondition(FStateTreeExecutionContext& Context) const
{
    return JMEnemyStateTreeConditions::HasTarget(Context.GetExternalData(MemoryHandle));
}
bool FJMStateTreeCanSeeTargetCondition::Link(FStateTreeLinker& Linker) { Linker.LinkExternalData(MemoryHandle); return true; }
bool FJMStateTreeCanSeeTargetCondition::TestCondition(FStateTreeExecutionContext& Context) const
{
    return Context.GetExternalData(MemoryHandle).CanCurrentlySeeTarget();
}
bool FJMStateTreeActorVisionCondition::Link(FStateTreeLinker& Linker) { Linker.LinkExternalData(MemoryHandle); return true; }
bool FJMStateTreeActorVisionCondition::TestCondition(FStateTreeExecutionContext& Context) const
{
    const FInstanceDataType& Data = Context.GetInstanceData(*this);
    const UJMEnemyMemoryComponent& Memory = Context.GetExternalData(MemoryHandle);
    const AActor* Actor = Data.bUseLastSeenSource ? Memory.GetLastSeenSource() : Data.Actor.Get();
    return Data.bInvert != Memory.CanCurrentlySeeActor(Actor);
}
bool FJMStateTreeRecentHearingCondition::Link(FStateTreeLinker& Linker) { Linker.LinkExternalData(MemoryHandle); return true; }
bool FJMStateTreeRecentHearingCondition::TestCondition(FStateTreeExecutionContext& Context) const
{
    const FInstanceDataType& Data = Context.GetInstanceData(*this);
    return Data.bInvert != JMEnemyStateTreeConditions::HasRecentHearing(
        Context.GetExternalData(MemoryHandle), Data.MaximumAge);
}
bool FJMStateTreeHearingStrengthCondition::Link(FStateTreeLinker& Linker) { Linker.LinkExternalData(MemoryHandle); return true; }
bool FJMStateTreeHearingStrengthCondition::TestCondition(FStateTreeExecutionContext& Context) const
{
    const FInstanceDataType& Data = Context.GetInstanceData(*this);
    return JMEnemyStateTreeConditions::Compare(Context.GetExternalData(MemoryHandle).GetLastHeardStrength(),
        Data.Strength, Data.Comparison);
}
bool FJMStateTreeGazeCondition::Link(FStateTreeLinker& Linker) { Linker.LinkExternalData(PerceptionHandle); return true; }
bool FJMStateTreeGazeCondition::TestCondition(FStateTreeExecutionContext& Context) const
{
    const FInstanceDataType& Data = Context.GetInstanceData(*this);
    const bool bHasGaze = JMEnemyStateTreeConditions::HasGaze(Context.GetExternalData(PerceptionHandle),
        Data.MinimumStrength, Data.MinimumDuration);
    return Data.bInvert != bHasGaze;
}
bool FJMStateTreeRecentVisionCondition::Link(FStateTreeLinker& Linker) { Linker.LinkExternalData(MemoryHandle); return true; }
bool FJMStateTreeRecentVisionCondition::TestCondition(FStateTreeExecutionContext& Context) const
{
    const FInstanceDataType& Data = Context.GetInstanceData(*this);
    return Data.bInvert != JMEnemyStateTreeConditions::HasRecentVision(
        Context.GetExternalData(MemoryHandle), Data.MaximumAge);
}
bool FJMStateTreeDistanceCondition::Link(FStateTreeLinker& Linker) { Linker.LinkExternalData(MemoryHandle); return true; }
bool FJMStateTreeDistanceCondition::TestCondition(FStateTreeExecutionContext& Context) const
{
    const FInstanceDataType& Data = Context.GetInstanceData(*this);
    const AActor* Owner = Context.GetExternalData(MemoryHandle).GetOwner();
    return Owner && IsValid(Data.TargetActor) && JMEnemyStateTreeConditions::Compare(
        FVector::Dist(Owner->GetActorLocation(), Data.TargetActor->GetActorLocation()), Data.Distance, Data.Comparison);
}
bool FJMStateTreeEncounterCondition::Link(FStateTreeLinker& Linker) { Linker.LinkExternalData(MemoryHandle); return true; }
bool FJMStateTreeEncounterCondition::TestCondition(FStateTreeExecutionContext& Context) const
{
    const FInstanceDataType& Data = Context.GetInstanceData(*this);
    return JMEnemyStateTreeConditions::Compare(Context.GetExternalData(MemoryHandle).GetEncounterCount(),
        Data.Threshold, Data.Comparison);
}
bool FJMStateTreeStateTagCondition::Link(FStateTreeLinker& Linker) { Linker.LinkExternalData(StateHandle); return true; }
bool FJMStateTreeStateTagCondition::TestCondition(FStateTreeExecutionContext& Context) const
{
    return Context.GetExternalData(StateHandle).IsInState(Context.GetInstanceData<FInstanceDataType>(*this).State);
}

bool FJMStateTreeContextEvaluator::Link(FStateTreeLinker& Linker)
{
    Linker.LinkExternalData(MemoryHandle);
    Linker.LinkExternalData(PerceptionHandle);
    return true;
}

void FJMStateTreeContextEvaluator::TreeStart(FStateTreeExecutionContext& Context) const { Tick(Context, 0.0f); }
void FJMStateTreeContextEvaluator::Tick(FStateTreeExecutionContext& Context, float) const
{
    FInstanceDataType& Data = Context.GetInstanceData(*this);
    const UJMEnemyMemoryComponent& Memory = Context.GetExternalData(MemoryHandle);
    const UJMEnemyPerceptionComponent& Perception = Context.GetExternalData(PerceptionHandle);
    Data.CurrentTarget = Memory.GetCurrentTarget();
    Data.LastHeardSource = Memory.GetLastHeardSource();
    Data.LastSeenSource = Memory.GetLastSeenSource();
    Data.LastKnownLocation = Memory.GetLastKnownTargetLocation();
    Data.LastSeenLocation = Memory.GetLastSeenLocation();
    Data.LastHeardLocation = Memory.GetLastHeardLocation();
    Data.bCanSeeTarget = Memory.CanCurrentlySeeTarget();
    Data.GazeStrength = Perception.GetGazeStrength();
    Data.GazeDuration = Perception.GetGazeDuration();
    Data.EncounterCount = Memory.GetEncounterCount();
    Data.TimeSinceLastHeard = static_cast<float>(Memory.GetTimeSinceLastHeard());
    Data.TimeSinceLastSeen = static_cast<float>(Memory.GetTimeSinceLastSeen());
    Data.LastHeardStrength = Memory.GetLastHeardStrength();
    if (const AJMEnemyBase* Enemy = Cast<AJMEnemyBase>(Memory.GetOwner()))
    {
        if (const UJMEnemyDefinition* Definition = Enemy->GetEnemyDefinition())
        {
            const FJMEnemyBehaviorTuning& Tuning = Definition->BehaviorTuning;
            Data.AcquireGraceTime = Tuning.AcquireGraceTime;
            Data.LostSightPursuitDuration = Tuning.LostSightPursuitDuration;
            Data.LostSightGraceTime = Tuning.LostSightGraceTime;
            Data.LastKnownLocationPause = Tuning.LastKnownLocationPause;
            Data.SearchDuration = Tuning.SearchDuration;
            Data.SearchPointCount = Tuning.SearchPointCount;
            Data.SearchRadius = Tuning.SearchRadius;
            Data.StrongHearingStrength = Tuning.StrongHearingStrength;
            Data.HideMinimumDuration = Tuning.HideMinimumDuration;
            Data.FrenzySearchDuration = Tuning.FrenzySearchDuration;
        }
    }
}

bool FJMStateTreeCombatTargetCondition::Link(FStateTreeLinker& Linker)
{
    Linker.LinkExternalData(MemoryHandle);
    return true;
}

bool FJMStateTreeCombatTargetCondition::TestCondition(FStateTreeExecutionContext& Context) const
{
    const FInstanceDataType& Data = Context.GetInstanceData(*this);
    AActor* Actor = Data.bUseLastSeenSource
        ? Context.GetExternalData(MemoryHandle).GetLastSeenSource() : Data.Actor.Get();
    if (!IsValid(Actor) || Actor->IsActorBeingDestroyed())
    {
        return false;
    }
    const APawn* Pawn = Cast<APawn>(Actor);
    return (!Data.bRequirePawn || Pawn) &&
        (!Data.bRequirePlayerControlled || (Pawn && Pawn->IsPlayerControlled())) &&
        (!Data.bRequireDamageable || Actor->CanBeDamaged());
}

bool FJMStateTreeTargetHearingCondition::Link(FStateTreeLinker& Linker)
{
    Linker.LinkExternalData(MemoryHandle);
    return true;
}

bool FJMStateTreeTargetHearingCondition::TestCondition(FStateTreeExecutionContext& Context) const
{
    const FInstanceDataType& Data = Context.GetInstanceData(*this);
    const UJMEnemyMemoryComponent& Memory = Context.GetExternalData(MemoryHandle);
    const bool bRecent = IsValid(Memory.GetCurrentTarget()) &&
        Memory.GetLastHeardSource() == Memory.GetCurrentTarget() &&
        Memory.HasHeardStimulusRecently(Data.MaximumAge);
    return Data.bInvert != bRecent;
}

bool FJMStateTreeActionReadyCondition::Link(FStateTreeLinker& Linker)
{
    Linker.LinkExternalData(ActionHandle);
    return true;
}

bool FJMStateTreeActionReadyCondition::TestCondition(FStateTreeExecutionContext& Context) const
{
    const FInstanceDataType& Data = Context.GetInstanceData(*this);
    FJMEnemyActionContext ActionContext;
    ActionContext.TargetActor = Data.TargetActor;
    ActionContext.TargetLocation = Data.TargetLocation;
    ActionContext.bHasTargetLocation = Data.bHasTargetLocation;
    return Context.GetExternalData(ActionHandle).CanExecuteAction(Data.ActionId, ActionContext);
}
