#include "Components/JMReconInteractorComponent.h"

#include "Components/JMReconTargetComponent.h"
#include "Components/ActorComponent.h"
#include "Data/JMReconDefinition.h"
#include "DrawDebugHelpers.h"
#include "HAL/IConsoleManager.h"
#include "Interfaces/JMReconTarget.h"
#include "JMReconRuntime.h"
#include "Kismet/GameplayStatics.h"
#include "Settings/JMReconSettings.h"
#include "Sound/SoundMix.h"
#include "TimerManager.h"

#if !UE_BUILD_SHIPPING
namespace
{
    TAutoConsoleVariable<int32> CVarJMReconDebug(
        TEXT("jm.Recon.Debug"),
        -1,
        TEXT("-1: use Project Settings, 0: disabled, 1: enabled"),
        ECVF_Default);

    bool IsJMReconDebugEnabled()
    {
        const int32 Override = CVarJMReconDebug.GetValueOnGameThread();
        return Override >= 0 ? Override != 0 : GetDefault<UJMReconSettings>()->bDebugEnabled;
    }
}
#endif

UJMReconInteractorComponent::UJMReconInteractorComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

UObject* UJMReconInteractorComponent::ResolveTargetContract(AActor* TargetActor) const
{
    if (!TargetActor)
    {
        return nullptr;
    }
    if (TargetActor->GetClass()->ImplementsInterface(UJMReconTarget::StaticClass()))
    {
        return TargetActor;
    }
    TInlineComponentArray<UActorComponent*> Components(TargetActor);
    for (UActorComponent* Component : Components)
    {
        if (IsValid(Component) &&
            Component->GetClass()->ImplementsInterface(UJMReconTarget::StaticClass()))
        {
            return Component;
        }
    }
    return nullptr;
}

UObject* UJMReconInteractorComponent::GetActiveTargetContract() const
{
    return ActiveSession.TargetContract.Get();
}

FJMReconRequestResult UJMReconInteractorComponent::Fail(EJMReconFailureReason Reason)
{
    LastFailureReason = Reason;
    return FJMReconRequestResult::Failure(Reason);
}

FJMReconRequestResult UJMReconInteractorComponent::TryStartRecon(UJMReconTargetComponent* Target)
{
    if (ActiveSession.IsActive())
    {
        return Fail(EJMReconFailureReason::AlreadyActive);
    }
    AActor* InteractorActor = GetOwner();
    AActor* TargetActor = IsValid(Target) ? Target->GetOwner() : nullptr;
    if (!IsValid(InteractorActor))
    {
        return Fail(EJMReconFailureReason::InvalidInteractor);
    }
    if (!IsValid(Target) || !IsValid(TargetActor))
    {
        return Fail(EJMReconFailureReason::InvalidTarget);
    }
    if (!Target->bEnabled)
    {
        return Fail(EJMReconFailureReason::Disabled);
    }
    UJMReconDefinition* Definition = Target->GetEffectiveDefinition();
    if (!Definition || (!Definition->bAllowListen && !Definition->bAllowPeek))
    {
        return Fail(EJMReconFailureReason::DefinitionInvalid);
    }
    if (Target->MaximumStartDistance > 0.0f &&
        FVector::DistSquared(InteractorActor->GetActorLocation(), Target->GetPlayerWorldTransform().GetLocation()) >
        FMath::Square(Target->MaximumStartDistance))
    {
        return Fail(EJMReconFailureReason::OutOfRange);
    }

    const FGuid NewSessionId = FGuid::NewGuid();
    UObject* TargetContract = ResolveTargetContract(TargetActor);
    if (TargetContract)
    {
        const FJMReconRequestResult TargetResult = IJMReconTarget::Execute_CanStartRecon(TargetContract, InteractorActor, NewSessionId);
        if (!TargetResult.bSucceeded)
        {
            return Fail(TargetResult.FailureReason);
        }
    }

    const FJMReconRequestResult Reservation = Target->TryReserve(NewSessionId);
    if (!Reservation.bSucceeded)
    {
        return Fail(Reservation.FailureReason);
    }

    ActiveSession.SessionId = NewSessionId;
    ActiveSession.Interactor = this;
    ActiveSession.Target = Target;
    ActiveSession.TargetContract = TargetContract;
    ActiveSession.CurrentState = EJMReconState::Idle;
    ActiveSession.bIsIlluminating = false;
    LastFailureReason = EJMReconFailureReason::None;

    TargetActor->OnDestroyed.AddUniqueDynamic(this, &UJMReconInteractorComponent::HandleTargetDestroyed);
    if (TargetContract)
    {
        IJMReconTarget::Execute_BeginRecon(TargetContract, InteractorActor, NewSessionId);
    }

    OnSessionStarted.Broadcast(NewSessionId, Target);
    TransitionTo(EJMReconState::Entering);

    const bool bStartWithPeek =
        (Definition->InitialObservationMode == EJMReconInitialObservationMode::Peek ||
         !Definition->bAllowListen || !Target->SupportsMode(EJMReconMode::Listen)) &&
        Definition->bAllowPeek && Target->SupportsMode(EJMReconMode::Peek);
    const FTransform InitialCamera = bStartWithPeek
        ? Target->GetPeekCameraWorldTransform()
        : Target->GetListenCameraWorldTransform();
    const UJMReconSettings* Settings = GetDefault<UJMReconSettings>();
    OnCameraTransformRequested.Broadcast(
        InitialCamera,
        EJMReconState::Entering,
        Settings ? Settings->DefaultCameraBlendTime : 0.2f);

    const TWeakObjectPtr<UJMReconInteractorComponent> WeakThis(this);
    ScheduleTransition(Definition->EnteringDuration, [WeakThis, NewSessionId]()
    {
        if (WeakThis.IsValid())
        {
            WeakThis->CompleteEntering(NewSessionId);
        }
    });
    return FJMReconRequestResult::Success();
}

void UJMReconInteractorComponent::CompleteEntering(FGuid ExpectedSessionId)
{
    if (!IsCurrentSession(ExpectedSessionId, EJMReconState::Entering))
    {
        return;
    }
    UJMReconTargetComponent* Target = ActiveSession.Target.Get();
    UJMReconDefinition* Definition = Target ? Target->GetEffectiveDefinition() : nullptr;
    if (!Target || !Definition)
    {
        EndActiveReconSession(EJMReconEndReason::TargetDestroyed);
        return;
    }

    if (Definition->InitialObservationMode == EJMReconInitialObservationMode::Peek &&
        Definition->bAllowPeek && Target->SupportsMode(EJMReconMode::Peek))
    {
        StartPeek();
    }
    else if (Definition->bAllowListen && Target->SupportsMode(EJMReconMode::Listen))
    {
        StartListen();
    }
    else if (Definition->bAllowPeek && Target->SupportsMode(EJMReconMode::Peek))
    {
        StartPeek();
    }
    else
    {
        EndActiveReconSession(EJMReconEndReason::TargetInvalidated);
    }
}

FJMReconRequestResult UJMReconInteractorComponent::StartListen()
{
    UJMReconTargetComponent* Target = ActiveSession.Target.Get();
    UJMReconDefinition* Definition = Target ? Target->GetEffectiveDefinition() : nullptr;
    if (!ActiveSession.IsActive() || !Target || !Definition)
    {
        return Fail(EJMReconFailureReason::InvalidState);
    }
    if (ActiveSession.CurrentState == EJMReconState::Listening)
    {
        return FJMReconRequestResult::Success();
    }
    if (ActiveSession.CurrentState != EJMReconState::Entering &&
        ActiveSession.CurrentState != EJMReconState::Peeking)
    {
        return Fail(EJMReconFailureReason::InvalidState);
    }
    if (!Definition->bAllowListen || !Target->SupportsMode(EJMReconMode::Listen))
    {
        return Fail(EJMReconFailureReason::NotSupported);
    }

    UObject* TargetContract = GetActiveTargetContract();
    if (TargetContract &&
        !IJMReconTarget::Execute_CanEnterListen(TargetContract, GetOwner(), ActiveSession.SessionId))
    {
        return Fail(EJMReconFailureReason::Blocked);
    }
    TransitionTo(EJMReconState::Listening);
    return FJMReconRequestResult::Success();
}

FJMReconRequestResult UJMReconInteractorComponent::StopListen()
{
    if (ActiveSession.CurrentState != EJMReconState::Listening)
    {
        return Fail(EJMReconFailureReason::InvalidState);
    }
    BeginExit(EJMReconEndReason::Completed);
    return FJMReconRequestResult::Success();
}

FJMReconRequestResult UJMReconInteractorComponent::StartPeek()
{
    UJMReconTargetComponent* Target = ActiveSession.Target.Get();
    UJMReconDefinition* Definition = Target ? Target->GetEffectiveDefinition() : nullptr;
    if (!ActiveSession.IsActive() || !Target || !Definition)
    {
        return Fail(EJMReconFailureReason::InvalidState);
    }
    if (ActiveSession.CurrentState == EJMReconState::Peeking)
    {
        return FJMReconRequestResult::Success();
    }
    if (ActiveSession.CurrentState != EJMReconState::Entering &&
        ActiveSession.CurrentState != EJMReconState::Listening)
    {
        return Fail(EJMReconFailureReason::InvalidState);
    }
    if (!Definition->bAllowPeek || !Target->SupportsMode(EJMReconMode::Peek))
    {
        return Fail(EJMReconFailureReason::NotSupported);
    }

    UObject* TargetContract = GetActiveTargetContract();
    if (TargetContract &&
        !IJMReconTarget::Execute_CanEnterPeek(TargetContract, GetOwner(), ActiveSession.SessionId))
    {
        return Fail(EJMReconFailureReason::Blocked);
    }
    TransitionTo(EJMReconState::Peeking);
    return FJMReconRequestResult::Success();
}

FJMReconRequestResult UJMReconInteractorComponent::StopPeek()
{
    if (ActiveSession.CurrentState != EJMReconState::Peeking)
    {
        return Fail(EJMReconFailureReason::InvalidState);
    }

    UJMReconTargetComponent* Target = ActiveSession.Target.Get();
    UJMReconDefinition* Definition = Target ? Target->GetEffectiveDefinition() : nullptr;
    if (Target && Definition && Definition->bAllowListen && Target->SupportsMode(EJMReconMode::Listen))
    {
        TransitionTo(EJMReconState::Listening);
    }
    else
    {
        BeginExit(EJMReconEndReason::Completed);
    }
    return FJMReconRequestResult::Success();
}

FJMReconRequestResult UJMReconInteractorComponent::SetIlluminate(bool bEnabled)
{
    UJMReconTargetComponent* Target = ActiveSession.Target.Get();
    UJMReconDefinition* Definition = Target ? Target->GetEffectiveDefinition() : nullptr;
    if (ActiveSession.CurrentState != EJMReconState::Peeking || !Target || !Definition)
    {
        return Fail(EJMReconFailureReason::InvalidState);
    }
    if (!Definition->bAllowIlluminate || !Target->SupportsMode(EJMReconMode::Illuminate))
    {
        return Fail(EJMReconFailureReason::NotSupported);
    }
    if (ActiveSession.bIsIlluminating == bEnabled)
    {
        return FJMReconRequestResult::Success();
    }

    ActiveSession.bIsIlluminating = bEnabled;
    OnIlluminateRequested.Broadcast(bEnabled);
    if (bEnabled)
    {
        EmitNoise(0.0f, Definition->IlluminateEvent);
    }
    return FJMReconRequestResult::Success();
}

FJMReconRequestResult UJMReconInteractorComponent::CancelRecon()
{
    if (!ActiveSession.IsActive())
    {
        return FJMReconRequestResult::Success();
    }
    EndActiveReconSession(EJMReconEndReason::Cancelled);
    return FJMReconRequestResult::Success();
}

FJMReconRequestResult UJMReconInteractorComponent::FinishRecon()
{
    if (!ActiveSession.IsActive())
    {
        return Fail(EJMReconFailureReason::InvalidState);
    }
    if (ActiveSession.CurrentState == EJMReconState::Exiting)
    {
        return FJMReconRequestResult::Success();
    }
    BeginExit(EJMReconEndReason::Completed);
    return FJMReconRequestResult::Success();
}

void UJMReconInteractorComponent::BeginExit(EJMReconEndReason Reason)
{
    UJMReconTargetComponent* Target = ActiveSession.Target.Get();
    UJMReconDefinition* Definition = Target ? Target->GetEffectiveDefinition() : nullptr;
    if (!ActiveSession.IsActive())
    {
        return;
    }
    PendingEndReason = Reason;
    TransitionTo(EJMReconState::Exiting);
    const FGuid ExpectedId = ActiveSession.SessionId;
    const TWeakObjectPtr<UJMReconInteractorComponent> WeakThis(this);
    ScheduleTransition(Definition ? Definition->ExitingDuration : 0.0f, [WeakThis, ExpectedId, Reason]()
    {
        if (WeakThis.IsValid())
        {
            WeakThis->CompleteExit(ExpectedId, Reason);
        }
    });
}

void UJMReconInteractorComponent::CompleteExit(FGuid ExpectedSessionId, EJMReconEndReason Reason)
{
    if (IsCurrentSession(ExpectedSessionId, EJMReconState::Exiting))
    {
        EndActiveReconSession(Reason);
    }
}

void UJMReconInteractorComponent::TransitionTo(EJMReconState NewState)
{
    const EJMReconState OldState = ActiveSession.CurrentState;
    if (OldState == NewState)
    {
        return;
    }

    if (OldState == EJMReconState::Listening)
    {
        LeaveListening();
    }
    else if (OldState == EJMReconState::Peeking)
    {
        LeavePeeking();
    }

    ActiveSession.CurrentState = NewState;
    OnStateChanged.Broadcast(OldState, NewState);

#if !UE_BUILD_SHIPPING
    if (IsJMReconDebugEnabled())
    {
        UE_LOG(
            LogJMRecon,
            Display,
            TEXT("%s: %s -> %s (%s)"),
            *GetNameSafe(GetOwner()),
            *UEnum::GetValueAsString(OldState),
            *UEnum::GetValueAsString(NewState),
            *ActiveSession.SessionId.ToString());
        if (const UJMReconTargetComponent* DebugTarget = ActiveSession.Target.Get())
        {
            const FTransform DebugTransform = NewState == EJMReconState::Peeking
                ? DebugTarget->GetPeekCameraWorldTransform()
                : DebugTarget->GetListenCameraWorldTransform();
            DrawDebugCoordinateSystem(
                GetWorld(),
                DebugTransform.GetLocation(),
                DebugTransform.Rotator(),
                35.0f,
                false,
                2.0f,
                0,
                1.5f);
        }
    }
#endif

    if (NewState == EJMReconState::Listening)
    {
        EnterListening();
    }
    else if (NewState == EJMReconState::Peeking)
    {
        EnterPeeking();
    }
}

void UJMReconInteractorComponent::EnterListening()
{
    UJMReconTargetComponent* Target = ActiveSession.Target.Get();
    UJMReconDefinition* Definition = Target ? Target->GetEffectiveDefinition() : nullptr;
    if (!Target || !Definition)
    {
        return;
    }
    if (!Definition->ListenAudioMix.IsNull())
    {
        ActiveListenSoundMix = Definition->ListenAudioMix.LoadSynchronous();
        if (ActiveListenSoundMix)
        {
            UGameplayStatics::PushSoundMixModifier(this, ActiveListenSoundMix);
        }
    }
    OnCameraTransformRequested.Broadcast(Target->GetListenCameraWorldTransform(), EJMReconState::Listening, Definition->ListenFadeDuration);
    EmitNoise(Definition->ListenNoise, TEXT("Listen"));
}

void UJMReconInteractorComponent::LeaveListening()
{
    if (ActiveListenSoundMix)
    {
        UGameplayStatics::PopSoundMixModifier(this, ActiveListenSoundMix);
        ActiveListenSoundMix = nullptr;
    }
}

void UJMReconInteractorComponent::EnterPeeking()
{
    UJMReconTargetComponent* Target = ActiveSession.Target.Get();
    UJMReconDefinition* Definition = Target ? Target->GetEffectiveDefinition() : nullptr;
    if (!Target || !Definition)
    {
        return;
    }
    UObject* TargetContract = GetActiveTargetContract();
    if (TargetContract)
    {
        IJMReconTarget::Execute_BeginPeekPose(TargetContract, ActiveSession.SessionId, Definition->PeekOpenFraction);
    }
    OnCameraTransformRequested.Broadcast(Target->GetPeekCameraWorldTransform(), EJMReconState::Peeking, Definition->PeekBlendTime);
    EmitNoise(Definition->PeekNoise, TEXT("Peek"));
}

void UJMReconInteractorComponent::LeavePeeking()
{
    if (ActiveSession.bIsIlluminating)
    {
        ActiveSession.bIsIlluminating = false;
        OnIlluminateRequested.Broadcast(false);
    }
    UJMReconTargetComponent* Target = ActiveSession.Target.Get();
    UObject* TargetContract = GetActiveTargetContract();
    if (TargetContract)
    {
        IJMReconTarget::Execute_EndPeekPose(TargetContract, ActiveSession.SessionId);
    }
}

void UJMReconInteractorComponent::EndActiveReconSession(EJMReconEndReason Reason)
{
    if (!ActiveSession.SessionId.IsValid())
    {
        return;
    }

    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(TransitionTimer);
    }

    const FGuid EndedSessionId = ActiveSession.SessionId;
    UJMReconTargetComponent* Target = ActiveSession.Target.Get();
    AActor* TargetActor = Target ? Target->GetOwner() : nullptr;
    UObject* TargetContract = GetActiveTargetContract();

    if (ActiveSession.CurrentState == EJMReconState::Listening)
    {
        LeaveListening();
    }
    else if (ActiveSession.CurrentState == EJMReconState::Peeking)
    {
        LeavePeeking();
    }
    else if (ActiveSession.bIsIlluminating)
    {
        ActiveSession.bIsIlluminating = false;
        OnIlluminateRequested.Broadcast(false);
    }

    if (TargetActor)
    {
        TargetActor->OnDestroyed.RemoveDynamic(this, &UJMReconInteractorComponent::HandleTargetDestroyed);
        if (TargetContract)
        {
            IJMReconTarget::Execute_EndRecon(TargetContract, GetOwner(), EndedSessionId, Reason);
        }
    }
    if (Target)
    {
        Target->ReleaseReservation(EndedSessionId);
    }

    OnCameraRestoreRequested.Broadcast();
    const EJMReconState OldState = ActiveSession.CurrentState;
    ActiveSession = FJMReconSession();
    PendingEndReason = EJMReconEndReason::Completed;
    OnStateChanged.Broadcast(OldState, EJMReconState::Idle);
    OnSessionEnded.Broadcast(EndedSessionId, Reason);
}

void UJMReconInteractorComponent::EmitNoise(float Loudness, FName Type)
{
    if (Loudness <= 0.0f && Type != TEXT("Illuminate"))
    {
        return;
    }
    UJMReconTargetComponent* Target = ActiveSession.Target.Get();
    FJMReconNoiseEvent Noise;
    Noise.Location = Target ? Target->GetComponentLocation() : FVector::ZeroVector;
    Noise.Loudness = Loudness;
    Noise.NoiseType = Type;
    Noise.Instigator = GetOwner();
    Noise.Target = Target ? Target->GetOwner() : nullptr;
    OnNoiseGenerated.Broadcast(Noise);
}

void UJMReconInteractorComponent::ScheduleTransition(float Delay, TFunction<void()> Callback)
{
    if (UWorld* World = GetWorld(); World && Delay > 0.0f)
    {
        World->GetTimerManager().ClearTimer(TransitionTimer);
        FTimerDelegate Delegate;
        Delegate.BindLambda(MoveTemp(Callback));
        World->GetTimerManager().SetTimer(TransitionTimer, Delegate, Delay, false);
    }
    else
    {
        Callback();
    }
}

bool UJMReconInteractorComponent::IsCurrentSession(const FGuid& ExpectedSessionId, EJMReconState ExpectedState) const
{
    return ActiveSession.SessionId == ExpectedSessionId &&
           ActiveSession.CurrentState == ExpectedState &&
           ActiveSession.Target.IsValid();
}

void UJMReconInteractorComponent::HandleTargetDestroyed(AActor* DestroyedActor)
{
    EndActiveReconSession(EJMReconEndReason::TargetDestroyed);
}

void UJMReconInteractorComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    EndActiveReconSession(EJMReconEndReason::EndPlay);
    Super::EndPlay(EndPlayReason);
}

FString UJMReconInteractorComponent::GetDebugStatus() const
{
    return FString::Printf(
        TEXT("State=%s Target=%s Session=%s Illuminate=%s Reserved=%s LastFailure=%s"),
        *UEnum::GetValueAsString(ActiveSession.CurrentState),
        *GetNameSafe(ActiveSession.Target.Get()),
        *ActiveSession.SessionId.ToString(EGuidFormats::DigitsWithHyphens),
        ActiveSession.bIsIlluminating ? TEXT("true") : TEXT("false"),
        ActiveSession.Target.IsValid() && ActiveSession.Target->IsReservedBy(ActiveSession.SessionId) ? TEXT("true") : TEXT("false"),
        *UEnum::GetValueAsString(LastFailureReason));
}
