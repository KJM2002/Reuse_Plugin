#include "Subsystems/JMObjectiveUISubsystem.h"

#include "Blueprint/UserWidget.h"
#include "Engine/GameInstance.h"
#include "Engine/LocalPlayer.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "JMGameplayUIEventTags.h"
#include "Settings/JMObjectiveSettings.h"
#include "Subsystems/JMObjectiveSubsystem.h"
#include "Subsystems/JMGameplayEventSubsystem.h"
#include "TimerManager.h"
#include "UI/JMObjectiveDefaultWidget.h"
#include "UI/JMObjectiveWidgetBase.h"

void UJMObjectiveUISubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    ULocalPlayer* LocalPlayer = GetLocalPlayer();
    UGameInstance* GameInstance = LocalPlayer ? LocalPlayer->GetGameInstance() : nullptr;
    ObjectiveSubsystem = GameInstance ? GameInstance->GetSubsystem<UJMObjectiveSubsystem>() : nullptr;
    if (UJMGameplayEventSubsystem* EventSubsystem = GameInstance ? GameInstance->GetSubsystem<UJMGameplayEventSubsystem>() : nullptr)
    {
        FJMGameplayEventNativeDelegate OpenedCallback;
        OpenedCallback.BindUObject(this, &UJMObjectiveUISubsystem::HandleModalOpened);
        ModalOpenedHandle = EventSubsystem->SubscribeEvent(
            JMGameplayUIEventTags::ModalOpened, this, EJMGameplayEventMatchType::Exact, MoveTemp(OpenedCallback));
        FJMGameplayEventNativeDelegate ClosedCallback;
        ClosedCallback.BindUObject(this, &UJMObjectiveUISubsystem::HandleModalClosed);
        ModalClosedHandle = EventSubsystem->SubscribeEvent(
            JMGameplayUIEventTags::ModalClosed, this, EJMGameplayEventMatchType::Exact, MoveTemp(ClosedCallback));
    }
    BindObjectiveDelegates();
    RefreshMostRecentActiveObjective();
}

void UJMObjectiveUISubsystem::Deinitialize()
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(CompletedDisplayTimer);
    }
    UnbindObjectiveDelegates();
    if (UGameInstance* GameInstance = GetLocalPlayer() ? GetLocalPlayer()->GetGameInstance() : nullptr)
    {
        if (UJMGameplayEventSubsystem* EventSubsystem = GameInstance->GetSubsystem<UJMGameplayEventSubsystem>())
        {
            EventSubsystem->UnsubscribeAll(this);
        }
    }
    if (ObjectiveWidget)
    {
        ObjectiveWidget->RemoveFromParent();
        ObjectiveWidget = nullptr;
    }
    ObjectiveSubsystem = nullptr;
    bHasLatestActiveState = false;
    Super::Deinitialize();
}

void UJMObjectiveUISubsystem::PlayerControllerChanged(APlayerController* NewPlayerController)
{
    Super::PlayerControllerChanged(NewPlayerController);
    if (ObjectiveWidget && ObjectiveWidget->GetOwningPlayer() != NewPlayerController)
    {
        ObjectiveWidget->RemoveFromParent();
        ObjectiveWidget = nullptr;
    }
    RefreshMostRecentActiveObjective();
}

void UJMObjectiveUISubsystem::BindObjectiveDelegates()
{
    if (!ObjectiveSubsystem)
    {
        return;
    }
    ObjectiveSubsystem->OnObjectiveRegistered.AddUniqueDynamic(this, &UJMObjectiveUISubsystem::HandleRegistered);
    ObjectiveSubsystem->OnObjectiveActivated.AddUniqueDynamic(this, &UJMObjectiveUISubsystem::HandleActivated);
    ObjectiveSubsystem->OnObjectiveProgressed.AddUniqueDynamic(this, &UJMObjectiveUISubsystem::HandleProgressed);
    ObjectiveSubsystem->OnObjectiveCompleted.AddUniqueDynamic(this, &UJMObjectiveUISubsystem::HandleCompleted);
    ObjectiveSubsystem->OnObjectiveFailed.AddUniqueDynamic(this, &UJMObjectiveUISubsystem::HandleFailed);
    ObjectiveSubsystem->OnObjectiveRemoved.AddUniqueDynamic(this, &UJMObjectiveUISubsystem::HandleRemoved);
}

void UJMObjectiveUISubsystem::UnbindObjectiveDelegates()
{
    if (!ObjectiveSubsystem)
    {
        return;
    }
    ObjectiveSubsystem->OnObjectiveRegistered.RemoveDynamic(this, &UJMObjectiveUISubsystem::HandleRegistered);
    ObjectiveSubsystem->OnObjectiveActivated.RemoveDynamic(this, &UJMObjectiveUISubsystem::HandleActivated);
    ObjectiveSubsystem->OnObjectiveProgressed.RemoveDynamic(this, &UJMObjectiveUISubsystem::HandleProgressed);
    ObjectiveSubsystem->OnObjectiveCompleted.RemoveDynamic(this, &UJMObjectiveUISubsystem::HandleCompleted);
    ObjectiveSubsystem->OnObjectiveFailed.RemoveDynamic(this, &UJMObjectiveUISubsystem::HandleFailed);
    ObjectiveSubsystem->OnObjectiveRemoved.RemoveDynamic(this, &UJMObjectiveUISubsystem::HandleRemoved);
}

bool UJMObjectiveUISubsystem::EnsureWidget()
{
    const UJMObjectiveSettings* Settings = GetDefault<UJMObjectiveSettings>();
    UWorld* World = GetWorld();
    ULocalPlayer* LocalPlayer = GetLocalPlayer();
    if (!Settings || !Settings->bAutomaticallyCreateObjectiveUI || !World || World->GetNetMode() == NM_DedicatedServer || !LocalPlayer)
    {
        return false;
    }

    APlayerController* PlayerController = LocalPlayer->GetPlayerController(World);
    if (!IsValid(PlayerController))
    {
        return false;
    }
    if (IsValid(ObjectiveWidget))
    {
        return true;
    }

    TSubclassOf<UJMObjectiveWidgetBase> WidgetClass = UJMObjectiveDefaultWidget::StaticClass();
    if (!Settings->DefaultObjectiveWidgetClass.IsNull())
    {
        if (TSubclassOf<UJMObjectiveWidgetBase> ConfiguredClass = Settings->DefaultObjectiveWidgetClass.LoadSynchronous())
        {
            WidgetClass = ConfiguredClass;
        }
    }
    ObjectiveWidget = CreateWidget<UJMObjectiveWidgetBase>(PlayerController, WidgetClass);
    if (!ObjectiveWidget)
    {
        return false;
    }
    ObjectiveWidget->AddToPlayerScreen(Settings->ObjectiveWidgetZOrder);
    return true;
}

void UJMObjectiveUISubsystem::ShowState(const FJMObjectiveRuntimeState& RuntimeState)
{
    if (!EnsureWidget())
    {
        return;
    }
    ObjectiveWidget->SetVisibility(bModalSuppressed
        ? ESlateVisibility::Collapsed
        : ESlateVisibility::SelfHitTestInvisible);
    ObjectiveWidget->SetObjectiveState(RuntimeState);
}

void UJMObjectiveUISubsystem::HandleModalOpened(const FJMGameplayEventMessage& Message)
{
    ++ModalSuppressionDepth;
    bModalSuppressed = true;
    if (ObjectiveWidget)
    {
        ObjectiveWidget->SetVisibility(ESlateVisibility::Collapsed);
    }
}

void UJMObjectiveUISubsystem::HandleModalClosed(const FJMGameplayEventMessage& Message)
{
    ModalSuppressionDepth = FMath::Max(0, ModalSuppressionDepth - 1);
    bModalSuppressed = ModalSuppressionDepth > 0;
    if (!bModalSuppressed)
    {
        RefreshMostRecentActiveObjective();
    }
}

void UJMObjectiveUISubsystem::RefreshMostRecentActiveObjective()
{
    if (!ObjectiveSubsystem)
    {
        return;
    }
    TArray<FJMObjectiveRuntimeState> ActiveObjectives = ObjectiveSubsystem->GetActiveObjectives();
    ActiveObjectives.Sort([](const FJMObjectiveRuntimeState& A, const FJMObjectiveRuntimeState& B)
    {
        return A.ActivationTime < B.ActivationTime;
    });
    if (!ActiveObjectives.IsEmpty())
    {
        LatestActiveState = ActiveObjectives.Last();
        bHasLatestActiveState = true;
        ShowState(LatestActiveState);
        return;
    }
    bHasLatestActiveState = false;
    if (ObjectiveWidget && GetDefault<UJMObjectiveSettings>()->bHideWidgetWhenNoActiveObjective)
    {
        ObjectiveWidget->SetVisibility(ESlateVisibility::Collapsed);
    }
}

void UJMObjectiveUISubsystem::FinishCompletedDisplay()
{
    RefreshMostRecentActiveObjective();
}

bool UJMObjectiveUISubsystem::IsShowingCompletedState() const
{
    const UWorld* World = GetWorld();
    return World && World->GetTimerManager().IsTimerActive(CompletedDisplayTimer);
}

void UJMObjectiveUISubsystem::HandleRegistered(FGameplayTag ObjectiveId, const FJMObjectiveRuntimeState& RuntimeState)
{
    if (ObjectiveWidget)
    {
        ObjectiveWidget->OnObjectiveAdded(RuntimeState);
    }
}

void UJMObjectiveUISubsystem::HandleActivated(FGameplayTag ObjectiveId, const FJMObjectiveRuntimeState& RuntimeState)
{
    LatestActiveState = RuntimeState;
    bHasLatestActiveState = true;
    if (!IsShowingCompletedState())
    {
        ShowState(RuntimeState);
        if (ObjectiveWidget)
        {
            ObjectiveWidget->OnObjectiveActivated(RuntimeState);
        }
    }
}

void UJMObjectiveUISubsystem::HandleProgressed(FGameplayTag ObjectiveId, const FJMObjectiveRuntimeState& RuntimeState, int32 ProgressDelta)
{
    if (!IsShowingCompletedState() && bHasLatestActiveState && LatestActiveState.ObjectiveId == ObjectiveId)
    {
        LatestActiveState = RuntimeState;
        ShowState(RuntimeState);
    }
}

void UJMObjectiveUISubsystem::HandleCompleted(FGameplayTag ObjectiveId, const FJMObjectiveRuntimeState& RuntimeState)
{
    ShowState(RuntimeState);
    if (ObjectiveWidget)
    {
        ObjectiveWidget->OnObjectiveCompleted(RuntimeState);
    }
    const float Duration = FMath::Max(0.0f, GetDefault<UJMObjectiveSettings>()->CompletedDisplayDuration);
    if (UWorld* World = GetWorld(); World && Duration > 0.0f)
    {
        World->GetTimerManager().SetTimer(CompletedDisplayTimer, this, &UJMObjectiveUISubsystem::FinishCompletedDisplay, Duration, false);
    }
    else
    {
        FinishCompletedDisplay();
    }
}

void UJMObjectiveUISubsystem::HandleFailed(FGameplayTag ObjectiveId, const FJMObjectiveRuntimeState& RuntimeState)
{
    ShowState(RuntimeState);
    if (ObjectiveWidget)
    {
        ObjectiveWidget->OnObjectiveFailed(RuntimeState);
    }
    RefreshMostRecentActiveObjective();
}

void UJMObjectiveUISubsystem::HandleRemoved(FGameplayTag ObjectiveId, const FJMObjectiveRuntimeState& RuntimeState)
{
    if (ObjectiveWidget)
    {
        ObjectiveWidget->OnObjectiveRemoved(ObjectiveId);
    }
    if (bHasLatestActiveState && LatestActiveState.ObjectiveId == ObjectiveId)
    {
        RefreshMostRecentActiveObjective();
    }
}
