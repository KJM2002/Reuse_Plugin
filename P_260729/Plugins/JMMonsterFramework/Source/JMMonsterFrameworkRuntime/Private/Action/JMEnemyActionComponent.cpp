#include "Action/JMEnemyActionComponent.h"

#include "Action/JMEnemyAction.h"
#include "Action/JMEnemyActionDefinition.h"
#include "JMMonsterFrameworkRuntime.h"

UJMEnemyActionComponent::UJMEnemyActionComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = false;
}

int32 UJMEnemyActionComponent::InitializeActions(
    const TArray<TObjectPtr<UJMEnemyActionDefinition>>& Definitions)
{
    CancelCurrentAction();
    Actions.Empty();
    CurrentAction = nullptr;
    SetComponentTickEnabled(false);

    for (UJMEnemyActionDefinition* Definition : Definitions)
    {
        if (!Definition || !Definition->IsRuntimeConfigValid() || Actions.Contains(Definition->ActionId))
        {
            UE_LOG(LogJMMonsterFramework, Warning,
                TEXT("Enemy '%s' skipped a null, invalid, or duplicate Action Definition."),
                *GetNameSafe(GetOwner()));
            continue;
        }

        UJMEnemyAction* Action = NewObject<UJMEnemyAction>(
            this, Definition->ActionClass, NAME_None, RF_Transient);
        if (!Action)
        {
            continue;
        }
        Action->Initialize(this, Definition);
        Actions.Add(Definition->ActionId, Action);
    }
    return Actions.Num();
}

bool UJMEnemyActionComponent::CanExecuteAction(
    const FGameplayTag ActionId, const FJMEnemyActionContext Context) const
{
    UJMEnemyAction* Action = GetAction(ActionId);
    return Action && !IsActionRunning() && Action->CanExecute(Context);
}

EJMEnemyActionExecuteResult UJMEnemyActionComponent::ExecuteAction(
    const FGameplayTag ActionId, const FJMEnemyActionContext Context)
{
    UJMEnemyAction* Action = GetAction(ActionId);
    if (!Action)
    {
        return EJMEnemyActionExecuteResult::NotFound;
    }
    if (IsActionRunning())
    {
        return EJMEnemyActionExecuteResult::AlreadyRunning;
    }
    if (!Action->CanExecute(Context))
    {
        return EJMEnemyActionExecuteResult::CannotExecute;
    }

    CurrentAction = Action;
    if (!Action->Start(Context))
    {
        CurrentAction = nullptr;
        return EJMEnemyActionExecuteResult::CannotExecute;
    }
    return EJMEnemyActionExecuteResult::Started;
}

bool UJMEnemyActionComponent::CancelCurrentAction()
{
    return CurrentAction && CurrentAction->Cancel();
}

UJMEnemyAction* UJMEnemyActionComponent::GetAction(const FGameplayTag ActionId) const
{
    if (const TObjectPtr<UJMEnemyAction>* Found = Actions.Find(ActionId))
    {
        return Found->Get();
    }
    return nullptr;
}

bool UJMEnemyActionComponent::IsActionRunning() const
{
    // The primary slot stays occupied through terminal hooks and phase notifications.
    return CurrentAction != nullptr;
}

bool UJMEnemyActionComponent::IsActionOnCooldown(const FGameplayTag ActionId) const
{
    const UJMEnemyAction* Action = GetAction(ActionId);
    return Action && Action->IsOnCooldown();
}

void UJMEnemyActionComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    CancelCurrentAction();
    Actions.Empty();
    CurrentAction = nullptr;
    Super::EndPlay(EndPlayReason);
}

void UJMEnemyActionComponent::TickComponent(
    const float DeltaTime, const ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    if (CurrentAction)
    {
        CurrentAction->Update(DeltaTime);
    }
}

void UJMEnemyActionComponent::NotifyActionStarted(UJMEnemyAction& Action)
{
    if (CurrentAction == &Action)
    {
        SetComponentTickEnabled(Action.NeedsUpdate());
        OnActionStarted.Broadcast(Action.GetActionId(), &Action);
    }
}

void UJMEnemyActionComponent::NotifyActionPhaseChanged(
    UJMEnemyAction& Action, const EJMEnemyActionPhase PreviousPhase, const EJMEnemyActionPhase NewPhase)
{
    if (CurrentAction == &Action)
    {
        OnActionPhaseChanged.Broadcast(Action.GetActionId(), &Action, PreviousPhase, NewPhase);
    }
}

void UJMEnemyActionComponent::NotifyActionFinished(UJMEnemyAction& Action)
{
    if (CurrentAction != &Action)
    {
        return;
    }
    CurrentAction = nullptr;
    SetComponentTickEnabled(false);
    OnActionFinished.Broadcast(Action.GetActionId(), &Action);
    OnActionFinishedNative.Broadcast(Action.GetActionId(), &Action);
}

void UJMEnemyActionComponent::NotifyActionCancelled(UJMEnemyAction& Action)
{
    if (CurrentAction != &Action)
    {
        return;
    }
    CurrentAction = nullptr;
    SetComponentTickEnabled(false);
    OnActionCancelled.Broadcast(Action.GetActionId(), &Action);
    OnActionCancelledNative.Broadcast(Action.GetActionId(), &Action);
}
