#include "Action/JMEnemyAction.h"

#include "Action/JMEnemyActionComponent.h"
#include "Action/JMEnemyActionDefinition.h"
#include "Core/JMEnemyBase.h"
#include "Engine/World.h"
#include "HAL/PlatformTime.h"
#include "TimerManager.h"

UWorld* UJMEnemyAction::GetWorld() const
{
    return ActionComponent ? ActionComponent->GetWorld() : nullptr;
}

FGameplayTag UJMEnemyAction::GetActionId() const
{
    return Definition ? Definition->ActionId : FGameplayTag::EmptyTag;
}

bool UJMEnemyAction::IsOnCooldown() const
{
    return CooldownEndTime > GetCurrentTime();
}

float UJMEnemyAction::GetRemainingCooldown() const
{
    return static_cast<float>(FMath::Max(0.0, CooldownEndTime - GetCurrentTime()));
}

bool UJMEnemyAction::CanExecuteAction(const FJMEnemyActionContext& InContext) const
{
    return true;
}

void UJMEnemyAction::ActionStarted()
{
}

void UJMEnemyAction::ExecuteActive()
{
}

void UJMEnemyAction::ActionFinished()
{
}

void UJMEnemyAction::ActionCancelled()
{
}

bool UJMEnemyAction::WantsUpdate() const
{
    return false;
}

void UJMEnemyAction::UpdateAction(const float DeltaTime)
{
}

bool UJMEnemyAction::K2_CanExecute_Implementation(const FJMEnemyActionContext& InContext) const
{
    return true;
}

bool UJMEnemyAction::K2_WantsUpdate_Implementation() const
{
    return false;
}

void UJMEnemyAction::Initialize(
    UJMEnemyActionComponent* InComponent, UJMEnemyActionDefinition* InDefinition)
{
    ClearTimer();
    ActionComponent = InComponent;
    Definition = InDefinition;
    EnemyOwner = InComponent ? Cast<AJMEnemyBase>(InComponent->GetOwner()) : nullptr;
    ExecutionContext = FJMEnemyActionContext();
    Phase = EJMEnemyActionPhase::Idle;
    CooldownEndTime = -1.0;
    ++ExecutionGeneration;
    bRunning = false;
    bWantsRuntimeUpdate = false;
}

bool UJMEnemyAction::CanExecute(const FJMEnemyActionContext& InContext) const
{
    return Definition && Definition->IsRuntimeConfigValid() && EnemyOwner.IsValid() &&
        !bRunning && !IsOnCooldown() && CanExecuteAction(InContext) && K2_CanExecute(InContext);
}

bool UJMEnemyAction::Start(const FJMEnemyActionContext& InContext)
{
    if (!CanExecute(InContext))
    {
        return false;
    }

    ClearTimer();
    ExecutionContext = InContext;
    bRunning = true;
    bWantsRuntimeUpdate = WantsUpdate() || K2_WantsUpdate();
    const uint32 Generation = ++ExecutionGeneration;

    ActionComponent->NotifyActionStarted(*this);
    ActionStarted();
    K2_OnStarted(ExecutionContext);
    if (!bRunning || Generation != ExecutionGeneration)
    {
        return true;
    }

    SetPhase(EJMEnemyActionPhase::Windup);
    ScheduleTransition(Definition->WindupDuration, EJMEnemyActionPhase::Windup, Generation);
    return true;
}

bool UJMEnemyAction::Cancel()
{
    if (!bRunning)
    {
        return false;
    }

    ClearTimer();
    ++ExecutionGeneration;
    bRunning = false;
    bWantsRuntimeUpdate = false;
    SetPhase(EJMEnemyActionPhase::Idle);
    ActionCancelled();
    K2_OnCancelled();
    if (ActionComponent)
    {
        ActionComponent->NotifyActionCancelled(*this);
    }
    ExecutionContext = FJMEnemyActionContext();
    return true;
}

bool UJMEnemyAction::NeedsUpdate() const
{
    return bRunning && bWantsRuntimeUpdate;
}

void UJMEnemyAction::Update(const float DeltaTime)
{
    if (bRunning && NeedsUpdate())
    {
        UpdateAction(DeltaTime);
        if (bRunning)
        {
            K2_Update(DeltaTime);
        }
    }
}

void UJMEnemyAction::ClearTimer()
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(PhaseTimer);
    }
    PhaseTimer.Invalidate();
}

void UJMEnemyAction::SetPhase(const EJMEnemyActionPhase NewPhase)
{
    if (Phase == NewPhase)
    {
        return;
    }
    const EJMEnemyActionPhase Previous = Phase;
    Phase = NewPhase;
    if (ActionComponent)
    {
        ActionComponent->NotifyActionPhaseChanged(*this, Previous, NewPhase);
    }
    K2_OnPhaseChanged(Previous, NewPhase);
}

void UJMEnemyAction::ScheduleTransition(
    const float Duration, const EJMEnemyActionPhase ExpectedPhase, const uint32 Generation)
{
    if (!bRunning || Generation != ExecutionGeneration || Phase != ExpectedPhase)
    {
        return;
    }
    if (Duration <= UE_KINDA_SMALL_NUMBER)
    {
        AdvancePhase(ExpectedPhase, Generation);
        return;
    }
    if (UWorld* World = GetWorld())
    {
        const FTimerDelegate Delegate = FTimerDelegate::CreateUObject(
            this, &ThisClass::AdvancePhase, ExpectedPhase, Generation);
        World->GetTimerManager().SetTimer(PhaseTimer, Delegate, Duration, false);
    }
}

void UJMEnemyAction::AdvancePhase(
    const EJMEnemyActionPhase ExpectedPhase, const uint32 Generation)
{
    if (!bRunning || Generation != ExecutionGeneration || Phase != ExpectedPhase)
    {
        return;
    }

    if (ExpectedPhase == EJMEnemyActionPhase::Windup)
    {
        SetPhase(EJMEnemyActionPhase::Active);
        ExecuteActive();
        K2_OnActive(ExecutionContext);
        if (bRunning && Generation == ExecutionGeneration)
        {
            ScheduleTransition(Definition->ActiveDuration, EJMEnemyActionPhase::Active, Generation);
        }
    }
    else if (ExpectedPhase == EJMEnemyActionPhase::Active)
    {
        SetPhase(EJMEnemyActionPhase::Recovery);
        ScheduleTransition(Definition->RecoveryDuration, EJMEnemyActionPhase::Recovery, Generation);
    }
    else if (ExpectedPhase == EJMEnemyActionPhase::Recovery)
    {
        Finish(Generation);
    }
}

void UJMEnemyAction::Finish(const uint32 Generation)
{
    if (!bRunning || Generation != ExecutionGeneration)
    {
        return;
    }

    ClearTimer();
    bRunning = false;
    bWantsRuntimeUpdate = false;
    CooldownEndTime = GetCurrentTime() + static_cast<double>(Definition->Cooldown);
    SetPhase(EJMEnemyActionPhase::Idle);
    ActionFinished();
    K2_OnFinished();
    if (ActionComponent)
    {
        ActionComponent->NotifyActionFinished(*this);
    }
    ExecutionContext = FJMEnemyActionContext();
}

double UJMEnemyAction::GetCurrentTime() const
{
    return GetWorld() ? static_cast<double>(GetWorld()->GetTimeSeconds()) : FPlatformTime::Seconds();
}
