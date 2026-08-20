#include "Subsystems/JMJumpScareSubsystem.h"

#include "Blueprint/UserWidget.h"
#include "Camera/CameraComponent.h"
#include "Camera/PlayerCameraManager.h"
#include "Components/AudioComponent.h"
#include "Data/JMJumpScareDefinition.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "JMJumpScare.h"
#include "Kismet/GameplayStatics.h"
#include "Materials/MaterialInterface.h"
#include "Payloads/JMJumpScareEventPayload.h"
#include "Settings/JMJumpScareSettings.h"
#include "Subsystems/JMGameplayEventSubsystem.h"
#include "TimerManager.h"
#include "Types/JMGameplayEventTypes.h"
#include "Types/JMJumpScareEventTags.h"
#include "UI/JMJumpScareOverlayWidget.h"

bool UJMJumpScareSubsystem::DoesSupportWorldType(EWorldType::Type WorldType) const
{
    return WorldType == EWorldType::Game || WorldType == EWorldType::PIE || WorldType == EWorldType::GamePreview;
}

void UJMJumpScareSubsystem::Deinitialize()
{
    if (IsJumpScarePlaying())
    {
        Cleanup(true, false, EJMJumpScarePlayResult::Started);
    }
    TriggeredOnceKeys.Reset();
    Super::Deinitialize();
}

EJMJumpScarePlayResult UJMJumpScareSubsystem::PlayJumpScare(UJMJumpScareDefinition* Definition, const FJMJumpScarePlayContext& Context)
{
    PruneTriggeredOnceKeys();
    const EJMJumpScarePlayResult Validation = ValidateRequest(Definition, Context);
    if (Validation != EJMJumpScarePlayResult::Started)
    {
        if (Validation != EJMJumpScarePlayResult::AlreadyPlaying && Validation != EJMJumpScarePlayResult::AlreadyTriggered)
        {
            ActiveDefinition = Definition;
            ActiveContext = Context;
            PublishEvent(JMJumpScareEventTags::Failed, Validation);
            ActiveDefinition = nullptr;
            ActiveContext = FJMJumpScarePlayContext();
        }
        return Validation;
    }

    const EJMJumpScareTriggerPolicy Policy =
        Context.bOverrideTriggerPolicy ? Context.TriggerPolicyOverride : Definition->TriggerPolicy;
    UObject* OnceKey = ResolveOnceKey(Definition, Context);
    if (Policy == EJMJumpScareTriggerPolicy::Once && OnceKey && TriggeredOnceKeys.Contains(OnceKey))
    {
        return EJMJumpScarePlayResult::AlreadyTriggered;
    }

    ActiveDefinition = Definition;
    ActiveContext = Context;
    ActiveOnceKey = OnceKey;
    const uint64 SessionId = ++SessionSerial;
    if (Policy == EJMJumpScareTriggerPolicy::Once && OnceKey)
    {
        TriggeredOnceKeys.Add(OnceKey);
    }

    if (!SetPhase(EJMJumpScarePhase::Preparing, SessionId))
    {
        return EJMJumpScarePlayResult::Started;
    }
    if (Definition->StartDelay > 0.0f)
    {
        GetWorld()->GetTimerManager().SetTimer(StartTimer, this, &UJMJumpScareSubsystem::ShowOverlay, Definition->StartDelay, false);
    }
    else
    {
        ShowOverlay();
    }
    return EJMJumpScarePlayResult::Started;
}

bool UJMJumpScareSubsystem::CancelJumpScare()
{
    if (!IsJumpScarePlaying())
    {
        return false;
    }

    Cleanup(true, false, EJMJumpScarePlayResult::Started);
    return true;
}

FJMJumpScareActiveInfo UJMJumpScareSubsystem::GetActiveJumpScare() const
{
    FJMJumpScareActiveInfo Info;
    Info.State = State;
    Info.Phase = Phase;
    Info.JumpScareId = ActiveDefinition ? ActiveDefinition->JumpScareId : FGameplayTag();
    Info.SpawnedActor = nullptr;
    Info.Anchor = ActiveContext.Anchor;
    return Info;
}

void UJMJumpScareSubsystem::ResetOncePolicy(UObject* SourceOrDefinition)
{
    if (SourceOrDefinition)
    {
        TriggeredOnceKeys.Remove(SourceOrDefinition);
    }
    else
    {
        TriggeredOnceKeys.Reset();
    }
}

FTransform UJMJumpScareSubsystem::CalculateCameraRelativeTransform(
    const FTransform& CameraTransform,
    float Forward,
    float Right,
    float Up,
    const FRotator& RotationOffset,
    const FTransform& ActorOffset)
{
    return ActorOffset * FTransform(RotationOffset, FVector(Forward, Right, Up)) * CameraTransform;
}

FTransform UJMJumpScareSubsystem::CalculateWorldAnchorTransform(const FTransform& AnchorTransform, const FTransform& ActorOffset)
{
    return ActorOffset * AnchorTransform;
}

bool UJMJumpScareSubsystem::SetState(EJMJumpScareState NewState, uint64 ExpectedSession)
{
    if (ExpectedSession != 0 && SessionSerial != ExpectedSession)
    {
        return false;
    }
    if (State == NewState)
    {
        return true;
    }
    const EJMJumpScareState OldState = State;
    State = NewState;
    OnStateChanged.Broadcast(OldState, NewState);
    return ExpectedSession == 0 || SessionSerial == ExpectedSession;
}

bool UJMJumpScareSubsystem::SetPhase(EJMJumpScarePhase NewPhase, uint64 ExpectedSession)
{
    if (ExpectedSession != 0 && SessionSerial != ExpectedSession)
    {
        return false;
    }
    if (Phase == NewPhase)
    {
        return true;
    }

    const EJMJumpScarePhase OldPhase = Phase;
    Phase = NewPhase;
    OnPhaseChanged.Broadcast(OldPhase, NewPhase);
    if (ExpectedSession != 0 && (SessionSerial != ExpectedSession || Phase != NewPhase))
    {
        return false;
    }

    bool bStateCurrent = true;
    switch (NewPhase)
    {
    case EJMJumpScarePhase::Idle:
        bStateCurrent = SetState(EJMJumpScareState::Idle, ExpectedSession);
        break;
    case EJMJumpScarePhase::Preparing:
        bStateCurrent = SetState(EJMJumpScareState::Waiting, ExpectedSession);
        break;
    case EJMJumpScarePhase::Finishing:
        bStateCurrent = SetState(EJMJumpScareState::Finishing, ExpectedSession);
        break;
    default:
        bStateCurrent = SetState(EJMJumpScareState::Playing, ExpectedSession);
        break;
    }

    const UJMJumpScareSettings* Settings = GetDefault<UJMJumpScareSettings>();
    if (Settings && Settings->bEnableDebugLogging)
    {
        UE_LOG(LogJMJumpScare, Log, TEXT("2D JumpScare phase %d -> %d"), static_cast<int32>(OldPhase), static_cast<int32>(NewPhase));
    }
    return bStateCurrent && (ExpectedSession == 0 || SessionSerial == ExpectedSession);
}

EJMJumpScarePlayResult UJMJumpScareSubsystem::ValidateRequest(
    UJMJumpScareDefinition* Definition,
    const FJMJumpScarePlayContext& Context) const
{
    if (!GetWorld())
    {
        return EJMJumpScarePlayResult::InvalidWorld;
    }
    if (IsJumpScarePlaying())
    {
        return EJMJumpScarePlayResult::AlreadyPlaying;
    }
    if (!Definition)
    {
        return EJMJumpScarePlayResult::InvalidDefinition;
    }
    if (!Definition->Image)
    {
        return EJMJumpScarePlayResult::MissingImage;
    }
    if (!Definition->IsDefinitionValid())
    {
        return EJMJumpScarePlayResult::InvalidDefinition;
    }
    return ResolveTargetPlayer(Context)
        ? EJMJumpScarePlayResult::Started
        : EJMJumpScarePlayResult::MissingTargetPlayer;
}

UObject* UJMJumpScareSubsystem::ResolveOnceKey(
    UJMJumpScareDefinition* Definition,
    const FJMJumpScarePlayContext& Context) const
{
    return IsValid(Context.Source) ? Context.Source.Get() : Definition;
}

APlayerController* UJMJumpScareSubsystem::ResolveTargetPlayer(const FJMJumpScarePlayContext& Context) const
{
    if (IsValid(Context.TargetPlayer))
    {
        return Context.TargetPlayer;
    }
    if (const APawn* Pawn = Cast<APawn>(Context.Instigator))
    {
        if (APlayerController* Controller = Cast<APlayerController>(Pawn->GetController()))
        {
            return Controller;
        }
    }
    return GetWorld() ? GetWorld()->GetFirstPlayerController() : nullptr;
}

UCameraComponent* UJMJumpScareSubsystem::ResolveCameraComponent(APlayerController* Player) const
{
    if (!Player)
    {
        return nullptr;
    }

    if (Player->PlayerCameraManager)
    {
        if (AActor* ViewTarget = Player->PlayerCameraManager->GetViewTarget())
        {
            if (UCameraComponent* Camera = ViewTarget->FindComponentByClass<UCameraComponent>())
            {
                return Camera;
            }
        }
    }

    return Player->GetPawn() ? Player->GetPawn()->FindComponentByClass<UCameraComponent>() : nullptr;
}

void UJMJumpScareSubsystem::LockPlayerInput(APlayerController* Player)
{
    if (!Player)
    {
        return;
    }

    InputLockedPlayer = Player;
    if (!Player->IsMoveInputIgnored())
    {
        Player->SetIgnoreMoveInput(true);
        bAppliedMoveInputLock = true;
    }
    if (!Player->IsLookInputIgnored())
    {
        Player->SetIgnoreLookInput(true);
        bAppliedLookInputLock = true;
    }
}

void UJMJumpScareSubsystem::RestorePlayerInput()
{
    if (APlayerController* Player = InputLockedPlayer.Get())
    {
        if (bAppliedMoveInputLock)
        {
            Player->SetIgnoreMoveInput(false);
        }
        if (bAppliedLookInputLock)
        {
            Player->SetIgnoreLookInput(false);
        }
    }

    InputLockedPlayer.Reset();
    bAppliedMoveInputLock = false;
    bAppliedLookInputLock = false;
}

void UJMJumpScareSubsystem::ShowOverlay()
{
    const uint64 SessionId = SessionSerial;
    if (!ActiveDefinition || !GetWorld())
    {
        Cleanup(false, true, EJMJumpScarePlayResult::InvalidDefinition);
        return;
    }

    APlayerController* Player = ResolveTargetPlayer(ActiveContext);
    if (!Player)
    {
        Cleanup(false, true, EJMJumpScarePlayResult::MissingTargetPlayer);
        return;
    }

    LockPlayerInput(Player);

    OverlayWidget = CreateWidget<UJMJumpScareOverlayWidget>(Player, UJMJumpScareOverlayWidget::StaticClass());
    if (!OverlayWidget)
    {
        Cleanup(false, true, EJMJumpScarePlayResult::SpawnFailed);
        return;
    }

    OverlayWidget->AddToPlayerScreen(ActiveDefinition->ZOrder);
    OverlayWidget->Configure(
        ActiveDefinition->Image,
        ActiveDefinition->ImageTint,
        ActiveDefinition->ImageResolution,
        ActiveDefinition->RiseDuration);

    if (!SetPhase(EJMJumpScarePhase::Impact, SessionId))
    {
        return;
    }
    PublishEvent(JMJumpScareEventTags::Started, EJMJumpScarePlayResult::Started);
    if (SessionSerial != SessionId) return;
    PublishEvent(JMJumpScareEventTags::Impact, EJMJumpScarePlayResult::Started);
    if (SessionSerial != SessionId) return;

    if (ActiveDefinition->JumpScareSound)
    {
        if (ActiveDefinition->SoundDelay > 0.0f)
        {
            GetWorld()->GetTimerManager().SetTimer(SoundTimer, this, &UJMJumpScareSubsystem::PlaySound, ActiveDefinition->SoundDelay, false);
        }
        else
        {
            PlaySound();
        }
    }

    if (!SetPhase(EJMJumpScarePhase::Holding, SessionId))
    {
        return;
    }
    if (ActiveDefinition->Duration > 0.0f)
    {
        GetWorld()->GetTimerManager().SetTimer(DurationTimer, this, &UJMJumpScareSubsystem::FinishJumpScare, ActiveDefinition->Duration, false);
    }
    else
    {
        FinishJumpScare();
    }
}

void UJMJumpScareSubsystem::PlaySound()
{
    if (!ActiveDefinition || !ActiveDefinition->JumpScareSound)
    {
        return;
    }

    SpawnedAudio = UGameplayStatics::SpawnSound2D(
        this,
        ActiveDefinition->JumpScareSound,
        ActiveDefinition->VolumeMultiplier,
        ActiveDefinition->PitchMultiplier);
}

void UJMJumpScareSubsystem::FinishJumpScare()
{
    if (!IsJumpScarePlaying())
    {
        return;
    }

    const uint64 SessionId = SessionSerial;
    if (!SetPhase(EJMJumpScarePhase::Exiting, SessionId))
    {
        return;
    }
    PublishEvent(JMJumpScareEventTags::Exiting, EJMJumpScarePlayResult::Started);
    if (SessionSerial != SessionId) return;

    if (OverlayWidget)
    {
        OverlayWidget->RemoveFromParent();
        OverlayWidget = nullptr;
    }
    if (SpawnedAudio)
    {
        SpawnedAudio->Stop();
        SpawnedAudio = nullptr;
    }

    StartGlitch();
}

void UJMJumpScareSubsystem::StartGlitch()
{
    if (!ActiveDefinition)
    {
        Cleanup(false, true, EJMJumpScarePlayResult::InvalidDefinition);
        return;
    }

    ActiveGlitchMaterial = ActiveDefinition->GlitchMaterial.LoadSynchronous();
    GlitchCamera = ResolveCameraComponent(ResolveTargetPlayer(ActiveContext));
    if (ActiveGlitchMaterial && GlitchCamera.IsValid())
    {
        GlitchCamera->AddOrUpdateBlendable(ActiveGlitchMaterial, 1.0f);
    }
    else if (ActiveGlitchMaterial)
    {
        UE_LOG(LogJMJumpScare, Warning, TEXT("M_Glitch could not be applied because the target player has no Camera Component."));
    }

    if (ActiveDefinition->GlitchSound)
    {
        GlitchAudio = UGameplayStatics::SpawnSound2D(
            this,
            ActiveDefinition->GlitchSound,
            ActiveDefinition->GlitchVolumeMultiplier,
            ActiveDefinition->GlitchPitchMultiplier);
    }

    if (ActiveDefinition->GlitchDuration > 0.0f && (ActiveGlitchMaterial || ActiveDefinition->GlitchSound))
    {
        GetWorld()->GetTimerManager().SetTimer(
            GlitchTimer,
            this,
            &UJMJumpScareSubsystem::CompleteJumpScare,
            ActiveDefinition->GlitchDuration,
            false);
    }
    else
    {
        CompleteJumpScare();
    }
}

void UJMJumpScareSubsystem::CompleteJumpScare()
{
    RemoveGlitch();
    Cleanup(false, false, EJMJumpScarePlayResult::Started);
}

void UJMJumpScareSubsystem::RemoveGlitch()
{
    if (ActiveGlitchMaterial && GlitchCamera.IsValid())
    {
        GlitchCamera->RemoveBlendable(ActiveGlitchMaterial);
    }
    ActiveGlitchMaterial = nullptr;
    GlitchCamera.Reset();
}

void UJMJumpScareSubsystem::Cleanup(bool bCancelled, bool bFailed, EJMJumpScarePlayResult Result)
{
    if (bCleanupInProgress)
    {
        return;
    }
    bCleanupInProgress = true;
    const uint64 CleanupSession = ++SessionSerial;
    ClearTimers();
    RemoveGlitch();
    RestorePlayerInput();
    SetPhase(EJMJumpScarePhase::Finishing, CleanupSession);

    if (OverlayWidget)
    {
        OverlayWidget->RemoveFromParent();
        OverlayWidget = nullptr;
    }
    if (SpawnedAudio)
    {
        SpawnedAudio->Stop();
        SpawnedAudio = nullptr;
    }
    if (GlitchAudio)
    {
        GlitchAudio->Stop();
        GlitchAudio = nullptr;
    }

    if (bFailed)
    {
        PublishEvent(JMJumpScareEventTags::Failed, Result);
    }
    else if (bCancelled)
    {
        PublishEvent(JMJumpScareEventTags::Cancelled, Result);
    }
    else
    {
        PublishEvent(JMJumpScareEventTags::Finished, Result);
    }

    ActiveDefinition = nullptr;
    ActiveContext = FJMJumpScarePlayContext();
    ActiveOnceKey.Reset();
    SetPhase(EJMJumpScarePhase::Idle, CleanupSession);
    bCleanupInProgress = false;
}

void UJMJumpScareSubsystem::ClearTimers()
{
    if (!GetWorld())
    {
        return;
    }

    FTimerManager& Timers = GetWorld()->GetTimerManager();
    Timers.ClearTimer(StartTimer);
    Timers.ClearTimer(SoundTimer);
    Timers.ClearTimer(DurationTimer);
    Timers.ClearTimer(GlitchTimer);
}

void UJMJumpScareSubsystem::PublishEvent(FGameplayTag EventTag, EJMJumpScarePlayResult Result)
{
    UWorld* World = GetWorld();
    UGameInstance* GameInstance = World ? World->GetGameInstance() : nullptr;
    UJMGameplayEventSubsystem* Events = GameInstance ? GameInstance->GetSubsystem<UJMGameplayEventSubsystem>() : nullptr;
    if (!Events || !EventTag.IsValid())
    {
        return;
    }

    UJMJumpScareEventPayload* Payload = NewObject<UJMJumpScareEventPayload>(this);
    APlayerController* Player = ResolveTargetPlayer(ActiveContext);
    Payload->JumpScareId = ActiveDefinition ? ActiveDefinition->JumpScareId : FGameplayTag();
    Payload->Definition = ActiveDefinition;
    Payload->CurrentState = State;
    Payload->CurrentPhase = Phase;
    Payload->SpawnedActor = nullptr;
    Payload->Anchor = ActiveContext.Anchor;
    Payload->Result = Result;
    Payload->Trigger = ActiveContext.Source;
    if (Player)
    {
        Payload->TargetPawn = Player->GetPawn();
    }
    else
    {
        Payload->TargetPawn = Cast<APawn>(ActiveContext.Instigator.Get());
    }
    Payload->PlayerController = Player;

    FJMGameplayEventMessage Message;
    Message.EventTag = EventTag;
    Message.Source = this;
    Message.Instigator = ActiveContext.Instigator;
    Message.Target = Player;
    Message.ContextTags = ActiveContext.ContextTags;
    Message.Payload = Payload;
    Events->PublishEvent(Message);
}

void UJMJumpScareSubsystem::PruneTriggeredOnceKeys()
{
    for (auto It = TriggeredOnceKeys.CreateIterator(); It; ++It)
    {
        if (!It->IsValid())
        {
            It.RemoveCurrent();
        }
    }
}
