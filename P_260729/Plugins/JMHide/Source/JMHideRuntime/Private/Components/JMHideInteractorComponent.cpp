#include "Components/JMHideInteractorComponent.h"

#include "Components/JMHideAnchorComponent.h"
#include "Components/JMHideMechanismComponent.h"
#include "Components/JMHideParticipantDriverComponent.h"
#include "Components/JMHideSpotComponent.h"
#include "GameFramework/Actor.h"

DEFINE_LOG_CATEGORY_STATIC(LogJMHideDebug, Log, All);

UJMHideInteractorComponent::UJMHideInteractorComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UJMHideInteractorComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (ActiveSession.IsActive())
    {
        if (UJMHideMechanismComponent* Mechanism = ActiveSession.MechanismProvider.Get())
        {
            Mechanism->CancelOperation(ActiveSession.SessionId);
            Mechanism->Restore(ActiveSession.SessionId);
        }
        if (UJMHideParticipantDriverComponent* Driver = ActiveSession.ParticipantDriver.Get())
        {
            Driver->CancelOperation(ActiveSession.SessionId);
        }
        Cleanup(EJMHidePhase::Cancelled, true, true);
    }
    Super::EndPlay(EndPlayReason);
}

FJMHideResult UJMHideInteractorComponent::TryEnterHideSpot(UJMHideSpotComponent* HideSpot)
{
    return BeginEnter(HideSpot, FJMHideRequest());
}

FJMHideResult UJMHideInteractorComponent::TryEnterHideSpotWithRequest(UJMHideSpotComponent* HideSpot,
    const FJMHideRequest& Request)
{
    return BeginEnter(HideSpot, Request);
}

UJMHideParticipantDriverComponent* UJMHideInteractorComponent::ResolveDriver() const
{
    if (!GetOwner())
    {
        return nullptr;
    }
    TInlineComponentArray<UJMHideParticipantDriverComponent*> Drivers(GetOwner());
    for (UJMHideParticipantDriverComponent* Driver : Drivers)
    {
        if (IsValid(Driver) && Driver->SupportsParticipant(GetOwner()))
        {
            return Driver;
        }
    }
    return nullptr;
}

FJMHideResult UJMHideInteractorComponent::BeginEnter(UJMHideSpotComponent* HideSpot,
    const FJMHideRequest& Request)
{
    if (ActiveSession.IsActive())
    {
        return FJMHideResult::Failure(EJMHideFailureCode::AlreadyActive);
    }
    if (!IsValid(HideSpot) || !IsValid(HideSpot->GetOwner()))
    {
        return FJMHideResult::Failure(EJMHideFailureCode::InvalidSpot);
    }
    UJMHideParticipantDriverComponent* Driver = ResolveDriver();
    if (!Driver)
    {
        return FJMHideResult::Failure(EJMHideFailureCode::UnsupportedParticipant,
            NSLOCTEXT("JMHide", "NoParticipantDriver", "No participant driver supports this actor."));
    }
    if (!HideSpot->FindAnchor(EJMHideAnchorRole::Occupant) ||
        !HideSpot->FindAnchor(EJMHideAnchorRole::Camera) ||
        !HideSpot->FindAnchor(EJMHideAnchorRole::PrimaryExit))
    {
        return FJMHideResult::Failure(EJMHideFailureCode::MissingAnchor);
    }
    UJMHideMechanismComponent* Mechanism = HideSpot->FindMechanism();
    if (HideSpot->GetEffectiveArchetype() == EJMHideSpotArchetype::Enclosed && !Mechanism)
    {
        return FJMHideResult::Failure(EJMHideFailureCode::MissingMechanism);
    }

    ActiveSession = FJMHideSession();
    ActiveSession.SessionId = FGuid::NewGuid();
    ActiveSession.Interactor = this;
    ActiveSession.HideSpot = HideSpot;
    ActiveSession.ParticipantDriver = Driver;
    ActiveSession.MechanismProvider = Mechanism;
    ActiveSession.ResolvedConfig = HideSpot->ResolveConfig(Request);
    TransitionTo(EJMHidePhase::Reserving);

    const FJMHideResult ReserveResult = HideSpot->TryReserve(ActiveSession.SessionId, GetOwner());
    if (!ReserveResult.bSucceeded)
    {
        ActiveSession.CurrentPhase = EJMHidePhase::Failed;
        ActiveSession.bCleanupStarted = true;
        ActiveSession.bCleanupCompleted = true;
        return ReserveResult;
    }

    const FJMHideOperationContext Context = BuildOperationContext();
    if (ActiveSession.ResolvedConfig.bUseEntryAnchor && !HideSpot->FindAnchor(EJMHideAnchorRole::Entry))
    {
        RollbackEnter(EJMHideFailureCode::MissingAnchor);
        return FJMHideResult::Failure(EJMHideFailureCode::MissingAnchor);
    }

    FJMHideResult CaptureResult = Driver->CaptureState(ActiveSession.OriginalStateSnapshot);
    if (!CaptureResult.bSucceeded)
    {
        RollbackEnter(CaptureResult.Code);
        return CaptureResult;
    }
    TransitionTo(EJMHidePhase::PreparingEnter);
    FJMHideResult PrepareResult = Driver->PrepareForHide(
        ActiveSession.SessionId, Context, ActiveSession.OriginalStateSnapshot);
    if (!PrepareResult.bSucceeded)
    {
        RollbackEnter(PrepareResult.Code);
        return PrepareResult;
    }

    BindProviders();
    StartMechanism(EJMHideOperation::PrepareEnter, EJMHidePhase::Opening);
    return FJMHideResult::Success(NSLOCTEXT("JMHide", "EnterAccepted", "Hide enter command accepted."));
}

void UJMHideInteractorComponent::BindProviders()
{
    if (UJMHideParticipantDriverComponent* Driver = ActiveSession.ParticipantDriver.Get())
    {
        Driver->OnOperationCompleted.RemoveAll(this);
        Driver->OnOperationCompleted.AddUObject(this, &UJMHideInteractorComponent::HandleParticipantCompletion);
    }
    if (UJMHideMechanismComponent* Mechanism = ActiveSession.MechanismProvider.Get())
    {
        Mechanism->OnOperationCompleted.RemoveAll(this);
        Mechanism->OnOperationCompleted.AddUObject(this, &UJMHideInteractorComponent::HandleMechanismCompletion);
    }
}

void UJMHideInteractorComponent::UnbindProviders()
{
    if (UJMHideParticipantDriverComponent* Driver = ActiveSession.ParticipantDriver.Get())
    {
        Driver->OnOperationCompleted.RemoveAll(this);
    }
    if (UJMHideMechanismComponent* Mechanism = ActiveSession.MechanismProvider.Get())
    {
        Mechanism->OnOperationCompleted.RemoveAll(this);
    }
}

void UJMHideInteractorComponent::StartMechanism(EJMHideOperation Operation, EJMHidePhase Phase)
{
    ExpectedOperation = Operation;
    TransitionTo(Phase);
    UJMHideMechanismComponent* Mechanism = ActiveSession.MechanismProvider.Get();
    if (!Mechanism)
    {
        FJMHideOperationCompletion Completion;
        Completion.SessionId = ActiveSession.SessionId;
        Completion.Operation = Operation;
        Completion.bSucceeded = true;
        Completion.FailureCode = EJMHideFailureCode::None;
        HandleMechanismCompletion(Completion);
        return;
    }
    EJMHideFailureCode Failure = EJMHideFailureCode::None;
    const FJMHideOperationContext Context = BuildOperationContext();
    if (!Mechanism->CanStartOperation(Operation, Context, Failure) ||
        !Mechanism->StartOperation(ActiveSession.SessionId, Operation, Context))
    {
        Fail(Failure == EJMHideFailureCode::None ? EJMHideFailureCode::OperationRejected : Failure);
    }
}

void UJMHideInteractorComponent::StartParticipant(EJMHideOperation Operation, EJMHidePhase Phase)
{
    ExpectedOperation = Operation;
    TransitionTo(Phase);
    UJMHideParticipantDriverComponent* Driver = ActiveSession.ParticipantDriver.Get();
    if (!Driver || !Driver->StartOperation(ActiveSession.SessionId, Operation, BuildOperationContext()))
    {
        Fail(EJMHideFailureCode::OperationRejected);
    }
}

bool UJMHideInteractorComponent::IsExpectedCompletion(const FJMHideOperationCompletion& Completion,
    EJMHidePhase ExpectedPhase, EJMHideOperation InExpectedOperation) const
{
    return ActiveSession.IsActive() &&
        Completion.SessionId == ActiveSession.SessionId &&
        Completion.Operation == InExpectedOperation &&
        ExpectedOperation == InExpectedOperation &&
        ActiveSession.CurrentPhase == ExpectedPhase &&
        ActiveSession.Interactor.Get() == this &&
        ActiveSession.ParticipantDriver.IsValid() &&
        ActiveSession.HideSpot.IsValid();
}

void UJMHideInteractorComponent::HandleMechanismCompletion(const FJMHideOperationCompletion& Completion)
{
    if (Completion.Operation == EJMHideOperation::PrepareEnter &&
        IsExpectedCompletion(Completion, EJMHidePhase::Opening, EJMHideOperation::PrepareEnter))
    {
        if (!Completion.bSucceeded) { Fail(Completion.FailureCode); return; }
        StartParticipant(EJMHideOperation::Enter, EJMHidePhase::Entering);
    }
    else if (Completion.Operation == EJMHideOperation::CompleteEnter &&
        IsExpectedCompletion(Completion, EJMHidePhase::ClosingAfterEnter, EJMHideOperation::CompleteEnter))
    {
        if (!Completion.bSucceeded) { Fail(Completion.FailureCode); return; }
        FinishEnter();
    }
    else if (Completion.Operation == EJMHideOperation::PrepareExit &&
        IsExpectedCompletion(Completion, EJMHidePhase::OpeningForExit, EJMHideOperation::PrepareExit))
    {
        if (!Completion.bSucceeded) { Fail(Completion.FailureCode); return; }
        StartParticipant(EJMHideOperation::Exit, EJMHidePhase::Exiting);
    }
    else if (Completion.Operation == EJMHideOperation::CompleteExit &&
        IsExpectedCompletion(Completion, EJMHidePhase::ClosingAfterExit, EJMHideOperation::CompleteExit))
    {
        if (!Completion.bSucceeded) { Fail(Completion.FailureCode); return; }
        UJMHideSpotComponent* Spot = ActiveSession.HideSpot.Get();
        const FGuid SessionId = ActiveSession.SessionId;
        Cleanup(EJMHidePhase::Completed, true, true);
        OnHiddenExited.Broadcast(SessionId, Spot);
    }
}

void UJMHideInteractorComponent::HandleParticipantCompletion(const FJMHideOperationCompletion& Completion)
{
    if (Completion.Operation == EJMHideOperation::Enter &&
        IsExpectedCompletion(Completion, EJMHidePhase::Entering, EJMHideOperation::Enter))
    {
        if (!Completion.bSucceeded) { Fail(Completion.FailureCode); return; }
        StartMechanism(EJMHideOperation::CompleteEnter, EJMHidePhase::ClosingAfterEnter);
    }
    else if (Completion.Operation == EJMHideOperation::Exit &&
        IsExpectedCompletion(Completion, EJMHidePhase::Exiting, EJMHideOperation::Exit))
    {
        if (!Completion.bSucceeded) { Fail(Completion.FailureCode); return; }
        StartMechanism(EJMHideOperation::CompleteExit, EJMHidePhase::ClosingAfterExit);
    }
}

void UJMHideInteractorComponent::FinishEnter()
{
    UJMHideSpotComponent* Spot = ActiveSession.HideSpot.Get();
    UJMHideParticipantDriverComponent* Driver = ActiveSession.ParticipantDriver.Get();
    if (!Spot || !Driver)
    {
        RollbackEnter(EJMHideFailureCode::TargetDestroyed);
        return;
    }
    const FJMHideResult CommitResult = Spot->CommitOccupied(ActiveSession.SessionId, GetOwner());
    if (!CommitResult.bSucceeded)
    {
        RollbackEnter(CommitResult.Code);
        return;
    }
    Driver->ApplyHiddenState(ActiveSession.SessionId, BuildOperationContext());
    ExpectedOperation = EJMHideOperation::None;
    TransitionTo(EJMHidePhase::Hidden);
    OnExitPromptChanged.Broadcast(ActiveSession.ResolvedConfig.ExitPrompt);
    OnHiddenEntered.Broadcast(ActiveSession.SessionId, Spot);
}

FJMHideResult UJMHideInteractorComponent::TryExitCurrentHideSpot()
{
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
    UE_LOG(LogJMHideDebug, Log,
        TEXT("TryExitCurrentHideSpot called: Session=%s Interactor=%s State=%d Spot=%s"),
        *ActiveSession.SessionId.ToString(), *GetNameSafe(GetOwner()),
        static_cast<int32>(ActiveSession.CurrentPhase),
        *GetNameSafe(ActiveSession.HideSpot.Get()));
#endif
    if (ActiveSession.CurrentPhase != EJMHidePhase::Hidden)
    {
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
        UE_LOG(LogJMHideDebug, Warning, TEXT("Exit validation failed: FailureCode=%d (InvalidState)"),
            static_cast<int32>(EJMHideFailureCode::InvalidState));
#endif
        return FJMHideResult::Failure(EJMHideFailureCode::InvalidState);
    }
    FTransform Exit;
    if (!SelectExit(false, Exit))
    {
        // Normal interaction must not strand the player in a stable Hidden state.
        // When the spot explicitly allows a collision-ignoring force exit, use it
        // as a fallback after every authored exit has failed its fit test.
        if (ActiveSession.ResolvedConfig.bForceExitIgnoresCollision &&
            SelectExit(true, Exit))
        {
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
            UE_LOG(LogJMHideDebug, Warning,
                TEXT("All exits failed fit validation; using configured collision-ignoring fallback."));
#endif
            ActiveSession.SelectedExit = Exit;
            BeginExit(true, true);
            return FJMHideResult::Success(
                NSLOCTEXT("JMHide", "ForcedExitFallback", "Exit used the configured safety fallback."));
        }
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
        UE_LOG(LogJMHideDebug, Warning, TEXT("Exit validation failed: FailureCode=%d (ExitBlocked)"),
            static_cast<int32>(EJMHideFailureCode::ExitBlocked));
#endif
        return FJMHideResult::Failure(EJMHideFailureCode::ExitBlocked,
            NSLOCTEXT("JMHide", "AllExitsBlocked", "All hide exits are blocked."));
    }
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
    UE_LOG(LogJMHideDebug, Log, TEXT("Exit validation succeeded: Exit=%s"), *Exit.ToHumanReadableString());
#endif
    ActiveSession.SelectedExit = Exit;
    BeginExit(false, false);
    return FJMHideResult::Success();
}

FJMHideResult UJMHideInteractorComponent::ForceExit(bool bIgnoreCollisionPolicy)
{
    if (ActiveSession.CurrentPhase != EJMHidePhase::Hidden)
    {
        return FJMHideResult::Failure(EJMHideFailureCode::InvalidState);
    }
    FTransform Exit;
    const bool bEffectiveIgnoreCollision =
        bIgnoreCollisionPolicy && ActiveSession.ResolvedConfig.bForceExitIgnoresCollision;
    if (!SelectExit(bEffectiveIgnoreCollision, Exit))
    {
        return FJMHideResult::Failure(EJMHideFailureCode::ExitBlocked);
    }
    ActiveSession.SelectedExit = Exit;
    BeginExit(true, bEffectiveIgnoreCollision);
    return FJMHideResult::Success();
}

void UJMHideInteractorComponent::BeginExit(bool bForce, bool bIgnoreCollisionPolicy)
{
    bForceExitActive = bForce;
    OnExitPromptChanged.Broadcast(FText::GetEmpty());
    TransitionTo(EJMHidePhase::PreparingExit);
    StartMechanism(EJMHideOperation::PrepareExit, EJMHidePhase::OpeningForExit);
}

bool UJMHideInteractorComponent::SelectExit(bool bIgnoreCollisionPolicy, FTransform& OutExit) const
{
    const UJMHideSpotComponent* Spot = ActiveSession.HideSpot.Get();
    const UJMHideParticipantDriverComponent* Driver = ActiveSession.ParticipantDriver.Get();
    if (!Spot || !Driver)
    {
        return false;
    }
    TArray<UJMHideAnchorComponent*> Candidates;
    if (UJMHideAnchorComponent* Primary = Spot->FindAnchor(EJMHideAnchorRole::PrimaryExit))
    {
        Candidates.Add(Primary);
    }
    TArray<UJMHideAnchorComponent*> Alternatives;
    Spot->GetAlternativeExitAnchors(Alternatives);
    Candidates.Append(Alternatives);
    for (const UJMHideAnchorComponent* Candidate : Candidates)
    {
        const FTransform Transform = Candidate->GetComponentTransform();
        if (bIgnoreCollisionPolicy || Driver->CanOccupyTransform(Transform))
        {
            OutExit = Transform;
            return true;
        }
    }
    return false;
}

FJMHideOperationContext UJMHideInteractorComponent::BuildOperationContext() const
{
    FJMHideOperationContext Context;
    Context.Participant = GetOwner();
    Context.Config = ActiveSession.ResolvedConfig;
    Context.ExitTransform = ActiveSession.SelectedExit;
    if (const UJMHideSpotComponent* Spot = ActiveSession.HideSpot.Get())
    {
        if (const UJMHideAnchorComponent* Anchor = Spot->FindAnchor(EJMHideAnchorRole::Entry))
        {
            Context.EntryTransform = Anchor->GetComponentTransform();
        }
        if (const UJMHideAnchorComponent* Anchor = Spot->FindAnchor(EJMHideAnchorRole::Occupant))
        {
            Context.OccupantTransform = Anchor->GetComponentTransform();
        }
        if (const UJMHideAnchorComponent* Anchor = Spot->FindAnchor(EJMHideAnchorRole::Camera))
        {
            Context.CameraTransform = Anchor->GetComponentTransform();
        }
        if (Context.ExitTransform.Equals(FTransform::Identity))
        {
            if (const UJMHideAnchorComponent* Anchor = Spot->FindAnchor(EJMHideAnchorRole::PrimaryExit))
            {
                Context.ExitTransform = Anchor->GetComponentTransform();
            }
        }
    }
    return Context;
}

FJMHideResult UJMHideInteractorComponent::CancelCurrentTransition()
{
    if (!ActiveSession.IsActive())
    {
        return FJMHideResult::Failure(EJMHideFailureCode::InvalidState);
    }
    if (ActiveSession.CurrentPhase == EJMHidePhase::Hidden)
    {
        return FJMHideResult::Failure(EJMHideFailureCode::InvalidState,
            NSLOCTEXT("JMHide", "CancelHidden", "Hidden is a stable state; use Exit or ForceExit."));
    }
    const bool bWasExiting = ActiveSession.CurrentPhase == EJMHidePhase::PreparingExit ||
        ActiveSession.CurrentPhase == EJMHidePhase::OpeningForExit ||
        ActiveSession.CurrentPhase == EJMHidePhase::Exiting ||
        ActiveSession.CurrentPhase == EJMHidePhase::ClosingAfterExit;
    if (UJMHideMechanismComponent* Mechanism = ActiveSession.MechanismProvider.Get())
    {
        Mechanism->CancelOperation(ActiveSession.SessionId);
    }
    if (UJMHideParticipantDriverComponent* Driver = ActiveSession.ParticipantDriver.Get())
    {
        Driver->CancelOperation(ActiveSession.SessionId);
    }
    if (bWasExiting)
    {
        RollbackExitToHidden();
    }
    else
    {
        RollbackEnter(EJMHideFailureCode::Cancelled);
    }
    return FJMHideResult::Success();
}

void UJMHideInteractorComponent::RollbackEnter(EJMHideFailureCode Failure)
{
    if (UJMHideMechanismComponent* Mechanism = ActiveSession.MechanismProvider.Get())
    {
        Mechanism->CancelOperation(ActiveSession.SessionId);
        Mechanism->Restore(ActiveSession.SessionId);
    }
    Cleanup(Failure == EJMHideFailureCode::Cancelled ? EJMHidePhase::Cancelled : EJMHidePhase::Failed, true, true);
}

void UJMHideInteractorComponent::RollbackExitToHidden()
{
    if (UJMHideMechanismComponent* Mechanism = ActiveSession.MechanismProvider.Get())
    {
        Mechanism->Restore(ActiveSession.SessionId);
    }
    if (UJMHideParticipantDriverComponent* Driver = ActiveSession.ParticipantDriver.Get())
    {
        Driver->ApplyHiddenState(ActiveSession.SessionId, BuildOperationContext());
    }
    ExpectedOperation = EJMHideOperation::None;
    bForceExitActive = false;
    TransitionTo(EJMHidePhase::Hidden);
    OnExitPromptChanged.Broadcast(ActiveSession.ResolvedConfig.ExitPrompt);
}

void UJMHideInteractorComponent::Cleanup(EJMHidePhase FinalPhase, bool bReleaseSpot, bool bRestoreParticipant)
{
    if (ActiveSession.bCleanupCompleted)
    {
        return;
    }
    ActiveSession.bCleanupStarted = true;
    TransitionTo(EJMHidePhase::CleaningUp);
    UnbindProviders();
    if (bRestoreParticipant)
    {
        if (UJMHideParticipantDriverComponent* Driver = ActiveSession.ParticipantDriver.Get())
        {
            Driver->RestoreState(ActiveSession.SessionId, ActiveSession.OriginalStateSnapshot);
        }
    }
    if (bReleaseSpot)
    {
        if (UJMHideSpotComponent* Spot = ActiveSession.HideSpot.Get())
        {
            Spot->Release(ActiveSession.SessionId);
        }
    }
    ExpectedOperation = EJMHideOperation::None;
    ActiveSession.bCleanupCompleted = true;
    bForceExitActive = false;
    TransitionTo(FinalPhase);
    OnExitPromptChanged.Broadcast(FText::GetEmpty());
}

void UJMHideInteractorComponent::TransitionTo(EJMHidePhase NewPhase)
{
    if (ActiveSession.CurrentPhase == NewPhase)
    {
        return;
    }
    const EJMHidePhase OldPhase = ActiveSession.CurrentPhase;
    ActiveSession.CurrentPhase = NewPhase;
    OnPhaseChanged.Broadcast(ActiveSession.SessionId, OldPhase, NewPhase);
}

void UJMHideInteractorComponent::Fail(EJMHideFailureCode Failure)
{
    OnHideFailed.Broadcast(ActiveSession.SessionId, Failure);
    const bool bExitPhase = ActiveSession.CurrentPhase == EJMHidePhase::PreparingExit ||
        ActiveSession.CurrentPhase == EJMHidePhase::OpeningForExit ||
        ActiveSession.CurrentPhase == EJMHidePhase::Exiting ||
        ActiveSession.CurrentPhase == EJMHidePhase::ClosingAfterExit;
    if (bExitPhase && !bForceExitActive)
    {
        RollbackExitToHidden();
    }
    else
    {
        RollbackEnter(Failure);
    }
}
