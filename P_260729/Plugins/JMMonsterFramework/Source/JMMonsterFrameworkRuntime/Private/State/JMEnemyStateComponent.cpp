#include "State/JMEnemyStateComponent.h"

#include "JMMonsterFrameworkRuntime.h"
#include "Types/JMEnemyTags.h"

UJMEnemyStateComponent::UJMEnemyStateComponent()
    : CurrentState(JMEnemyTags::State_Idle)
{
    PrimaryComponentTick.bCanEverTick = false;
}

bool UJMEnemyStateComponent::SetState(const FGameplayTag NewState)
{
    if (!JMEnemyTags::IsConcreteState(NewState))
    {
        UE_LOG(LogJMMonsterFramework, Warning,
            TEXT("Rejected invalid enemy state '%s' on %s."),
            *NewState.ToString(), *GetNameSafe(GetOwner()));
        return false;
    }

    if (CurrentState == NewState)
    {
        return false;
    }

    const FGameplayTag PreviousState = CurrentState;
    CurrentState = NewState;
    OnStateChanged.Broadcast(PreviousState, CurrentState);
    return true;
}

bool UJMEnemyStateComponent::IsInState(const FGameplayTag State) const
{
    return State.IsValid() && CurrentState.MatchesTag(State);
}
