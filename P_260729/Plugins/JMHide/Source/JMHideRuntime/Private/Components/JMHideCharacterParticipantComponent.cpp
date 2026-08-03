#include "Components/JMHideCharacterParticipantComponent.h"

#include "Camera/CameraActor.h"
#include "Components/CapsuleComponent.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"
#include "Camera/PlayerCameraManager.h"
#include "TimerManager.h"

UJMHideCharacterParticipantComponent::UJMHideCharacterParticipantComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = false;
}

void UJMHideCharacterParticipantComponent::TickComponent(float DeltaTime, ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    UpdateLimitedLook();
}

void UJMHideCharacterParticipantComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    EndHideView();
    if (GetWorld())
    {
        GetWorld()->GetTimerManager().ClearTimer(OperationTimer);
        GetWorld()->GetTimerManager().ClearTimer(FadeMidpointTimer);
    }
    if (HideCameraActor.IsValid())
    {
        HideCameraActor->Destroy();
    }
    Super::EndPlay(EndPlayReason);
}

ACharacter* UJMHideCharacterParticipantComponent::GetCharacter() const
{
    return Cast<ACharacter>(GetOwner());
}

APlayerController* UJMHideCharacterParticipantComponent::GetPlayerController() const
{
    const ACharacter* Character = GetCharacter();
    return Character ? Cast<APlayerController>(Character->GetController()) : nullptr;
}

bool UJMHideCharacterParticipantComponent::SupportsParticipant(AActor* Participant) const
{
    const ACharacter* Character = Cast<ACharacter>(Participant);
    return Character && Character == GetOwner() && Character->GetCharacterMovement() && Character->GetCapsuleComponent();
}

FJMHideResult UJMHideCharacterParticipantComponent::CaptureState(FJMHideParticipantSnapshot& OutSnapshot)
{
    ACharacter* Character = GetCharacter();
    if (!SupportsParticipant(Character))
    {
        return FJMHideResult::Failure(EJMHideFailureCode::UnsupportedParticipant,
            NSLOCTEXT("JMHide", "CharacterDriverUnsupported", "The default driver requires an ACharacter owner."));
    }

    UCharacterMovementComponent* Movement = Character->GetCharacterMovement();
    UCapsuleComponent* Capsule = Character->GetCapsuleComponent();
    OriginalMovementMode = Movement->MovementMode;
    OriginalCustomMovementMode = Movement->CustomMovementMode;
    OriginalCollision = Capsule->GetCollisionEnabled();
    OriginalCollisionProfile = Capsule->GetCollisionProfileName();
    bOriginalHidden = Character->IsHidden();
    bVisibilityChangedOwned = false;
    OriginalActorTransform = Character->GetActorTransform();
    bRestoreActorTransform = true;
    if (APlayerController* PC = GetPlayerController())
    {
        OriginalViewTarget = PC->GetViewTarget();
        OriginalControlRotation = PC->GetControlRotation();
    }
    OutSnapshot = FJMHideParticipantSnapshot();
    OutSnapshot.bCaptured = true;
    return FJMHideResult::Success();
}

FJMHideResult UJMHideCharacterParticipantComponent::PrepareForHide(const FGuid& SessionId,
    const FJMHideOperationContext& Context, FJMHideParticipantSnapshot& InOutSnapshot)
{
    ACharacter* Character = GetCharacter();
    if (!InOutSnapshot.bCaptured || !SupportsParticipant(Character))
    {
        return FJMHideResult::Failure(EJMHideFailureCode::UnsupportedParticipant);
    }

    UCharacterMovementComponent* Movement = Character->GetCharacterMovement();
    if (Movement->MovementMode != MOVE_None)
    {
        Movement->DisableMovement();
        InOutSnapshot.bChangedMovement = true;
    }
    if (Context.Config.bDisableCollision && Character->GetCapsuleComponent()->GetCollisionEnabled() != ECollisionEnabled::NoCollision)
    {
        Character->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        InOutSnapshot.bChangedCollision = true;
    }
    if (Context.Config.bUseEntryAnchor && !Character->GetActorTransform().Equals(Context.EntryTransform))
    {
        Character->SetActorTransform(Context.EntryTransform, false, nullptr, ETeleportType::TeleportPhysics);
        InOutSnapshot.bChangedTransform = true;
    }
    InOutSnapshot.bChangedVisibility = Context.Config.bHideParticipant && !bOriginalHidden;
    bVisibilityChangedOwned = InOutSnapshot.bChangedVisibility;
    InOutSnapshot.bChangedViewTarget = GetPlayerController() != nullptr;
    InOutSnapshot.bChangedLookConstraint = GetPlayerController() != nullptr;
    return FJMHideResult::Success();
}

void UJMHideCharacterParticipantComponent::EnsureCameraActor(const FTransform& Transform)
{
    UWorld* World = GetWorld();
    if (!World)
    {
        return;
    }
    ACameraActor* Camera = HideCameraActor.Get();
    if (!Camera)
    {
        FActorSpawnParameters Params;
        Params.Owner = GetOwner();
        Params.ObjectFlags |= RF_Transient;
        Camera = World->SpawnActor<ACameraActor>(ACameraActor::StaticClass(), Transform, Params);
        HideCameraActor = Camera;
    }
    else
    {
        Camera->SetActorTransform(Transform);
    }
}

void UJMHideCharacterParticipantComponent::BeginHideView(
    const FJMHideOperationContext& Context)
{
    HideViewBaseRotation = Context.CameraTransform.Rotator().GetNormalized();
    HideViewYawLimit = FMath::Clamp(Context.Config.LookYawLimit, 0.0f, 180.0f);
    HideViewPitchLimit = FMath::Clamp(Context.Config.LookPitchLimit, 0.0f, 89.0f);
    bLimitedLookEnabled = Context.Config.bAllowLimitedLook;
    bHideViewActive = true;
    SetComponentTickEnabled(true);
    UpdateLimitedLook();
}

void UJMHideCharacterParticipantComponent::EndHideView()
{
    bHideViewActive = false;
    SetComponentTickEnabled(false);
}

void UJMHideCharacterParticipantComponent::UpdateLimitedLook()
{
    APlayerController* PC = GetPlayerController();
    ACameraActor* Camera = HideCameraActor.Get();
    if (!bHideViewActive || !PC || !Camera)
    {
        return;
    }

    FRotator DesiredRotation = PC->GetControlRotation().GetNormalized();
    if (bLimitedLookEnabled)
    {
        const float YawDelta = FMath::FindDeltaAngleDegrees(
            HideViewBaseRotation.Yaw, DesiredRotation.Yaw);
        const float PitchDelta = FMath::FindDeltaAngleDegrees(
            HideViewBaseRotation.Pitch, DesiredRotation.Pitch);
        DesiredRotation.Yaw = HideViewBaseRotation.Yaw +
            FMath::Clamp(YawDelta, -HideViewYawLimit, HideViewYawLimit);
        DesiredRotation.Pitch = HideViewBaseRotation.Pitch +
            FMath::Clamp(PitchDelta, -HideViewPitchLimit, HideViewPitchLimit);
    }
    else
    {
        DesiredRotation = HideViewBaseRotation;
    }
    DesiredRotation.Roll = HideViewBaseRotation.Roll;
    DesiredRotation.Normalize();
    PC->SetControlRotation(DesiredRotation);
    Camera->SetActorRotation(DesiredRotation);
}

void UJMHideCharacterParticipantComponent::StartFadeTransition(float Duration)
{
    APlayerController* PC = GetPlayerController();
    if (!GetWorld() || !PC || !PC->PlayerCameraManager ||
        Duration <= KINDA_SMALL_NUMBER)
    {
        HandleFadeMidpoint();
        return;
    }
    bFadeTransitionActive = true;
    const float HalfDuration = Duration * 0.5f;
    PC->PlayerCameraManager->StartCameraFade(
        0.0f, 1.0f, HalfDuration, FLinearColor::Black, false, true);
    GetWorld()->GetTimerManager().SetTimer(
        FadeMidpointTimer, this,
        &UJMHideCharacterParticipantComponent::HandleFadeMidpoint,
        HalfDuration, false);
}

void UJMHideCharacterParticipantComponent::HandleFadeMidpoint()
{
    ACharacter* Character = GetCharacter();
    APlayerController* PC = GetPlayerController();
    if (!ActiveSessionId.IsValid() || !Character)
    {
        return;
    }

    if (ActiveOperation == EJMHideOperation::Enter)
    {
        Character->SetActorTransform(
            ActiveContext.OccupantTransform, false, nullptr,
            ETeleportType::TeleportPhysics);
        if (PC && HideCameraActor.IsValid())
        {
            PC->SetControlRotation(ActiveContext.CameraTransform.Rotator());
            PC->SetViewTarget(HideCameraActor.Get());
            BeginHideView(ActiveContext);
        }
    }
    else if (ActiveOperation == EJMHideOperation::Exit)
    {
        if (bVisibilityChangedOwned && Character->IsHidden())
        {
            Character->SetActorHiddenInGame(false);
        }
        Character->SetActorTransform(
            ActiveContext.ExitTransform, false, nullptr,
            ETeleportType::TeleportPhysics);
        bRestoreActorTransform = false;
        if (PC && OriginalViewTarget.IsValid())
        {
            PC->SetControlRotation(OriginalControlRotation);
            PC->SetViewTarget(OriginalViewTarget.Get());
        }
    }

    if (bFadeTransitionActive && PC && PC->PlayerCameraManager)
    {
        const float OperationDuration =
            ActiveOperation == EJMHideOperation::Enter
            ? ActiveContext.Config.EnterDuration
            : ActiveContext.Config.ExitDuration;
        const float HalfDuration = FMath::Max(
            OperationDuration, ActiveContext.Config.CameraBlendDuration) * 0.5f;
        PC->PlayerCameraManager->StartCameraFade(
            1.0f, 0.0f, HalfDuration, FLinearColor::Black, false, false);
    }
}

void UJMHideCharacterParticipantComponent::StopFadeTransition()
{
    if (GetWorld())
    {
        GetWorld()->GetTimerManager().ClearTimer(FadeMidpointTimer);
    }
    if (APlayerController* PC = GetPlayerController();
        PC && PC->PlayerCameraManager && bFadeTransitionActive)
    {
        PC->PlayerCameraManager->StopCameraFade();
    }
    bFadeTransitionActive = false;
}

bool UJMHideCharacterParticipantComponent::StartOperation(const FGuid& SessionId, EJMHideOperation Operation,
    const FJMHideOperationContext& Context)
{
    ACharacter* Character = GetCharacter();
    if (!SessionId.IsValid() || !SupportsParticipant(Character) || ActiveSessionId.IsValid())
    {
        return false;
    }

    ActiveSessionId = SessionId;
    ActiveOperation = Operation;
    ActiveContext = Context;
    float Duration = 0.0f;
    if (Operation == EJMHideOperation::Enter)
    {
        LastHiddenTransform = Context.OccupantTransform;
        EnsureCameraActor(Context.CameraTransform);
        Duration = FMath::Max(Context.Config.EnterDuration, Context.Config.CameraBlendDuration);
        if (Context.Config.bUseCameraFadeTransition)
        {
            StartFadeTransition(Duration);
        }
        else
        {
            if (APlayerController* PC = GetPlayerController(); PC && HideCameraActor.IsValid())
            {
                // Lock the outgoing first-person POV before moving the character.
                // Otherwise the source camera snaps with the body before the blend.
                PC->SetViewTargetWithBlend(
                    HideCameraActor.Get(), Context.Config.CameraBlendDuration,
                    VTBlend_Cubic, 2.0f, true);
            }
            Character->SetActorTransform(
                Context.OccupantTransform, false, nullptr,
                ETeleportType::TeleportPhysics);
            if (Duration <= KINDA_SMALL_NUMBER)
            {
                if (APlayerController* PC = GetPlayerController();
                    PC && HideCameraActor.IsValid())
                {
                    PC->SetControlRotation(Context.CameraTransform.Rotator());
                    BeginHideView(Context);
                }
            }
        }
    }
    else if (Operation == EJMHideOperation::Exit)
    {
        EndHideView();
        Duration = FMath::Max(Context.Config.ExitDuration, Context.Config.CameraBlendDuration);
        if (Context.Config.bUseCameraFadeTransition)
        {
            StartFadeTransition(Duration);
        }
        else
        {
            if (bVisibilityChangedOwned && Character->IsHidden())
            {
                Character->SetActorHiddenInGame(false);
            }
            Character->SetActorTransform(
                Context.ExitTransform, false, nullptr,
                ETeleportType::TeleportPhysics);
            bRestoreActorTransform = false;
            if (APlayerController* PC = GetPlayerController(); PC && OriginalViewTarget.IsValid())
            {
                PC->SetControlRotation(OriginalControlRotation);
                PC->SetViewTargetWithBlend(
                    OriginalViewTarget.Get(), Context.Config.CameraBlendDuration,
                    VTBlend_Cubic, 2.0f, true);
            }
        }
    }
    else
    {
        ActiveSessionId.Invalidate();
        ActiveOperation = EJMHideOperation::None;
        CompleteOperation(SessionId, Operation, true);
        return true;
    }

    if (Duration <= KINDA_SMALL_NUMBER || !GetWorld())
    {
        FinishTimedOperation();
    }
    else
    {
        GetWorld()->GetTimerManager().SetTimer(OperationTimer, this,
            &UJMHideCharacterParticipantComponent::FinishTimedOperation, Duration, false);
    }
    return true;
}

void UJMHideCharacterParticipantComponent::FinishTimedOperation()
{
    const FGuid SessionId = ActiveSessionId;
    const EJMHideOperation Operation = ActiveOperation;
    if (Operation == EJMHideOperation::Enter && !bHideViewActive)
    {
        if (APlayerController* PC = GetPlayerController();
            PC && HideCameraActor.IsValid())
        {
            PC->SetControlRotation(ActiveContext.CameraTransform.Rotator());
            BeginHideView(ActiveContext);
        }
    }
    StopFadeTransition();
    ActiveSessionId.Invalidate();
    ActiveOperation = EJMHideOperation::None;
    CompleteOperation(SessionId, Operation, true);
}

void UJMHideCharacterParticipantComponent::CancelOperation(const FGuid& SessionId)
{
    if (SessionId == ActiveSessionId)
    {
        if (GetWorld())
        {
            GetWorld()->GetTimerManager().ClearTimer(OperationTimer);
        }
        StopFadeTransition();
        ActiveSessionId.Invalidate();
        ActiveOperation = EJMHideOperation::None;
    }
}

void UJMHideCharacterParticipantComponent::ApplyHiddenState(const FGuid& SessionId,
    const FJMHideOperationContext& Context)
{
    if (ACharacter* Character = GetCharacter())
    {
        LastHiddenTransform = Context.OccupantTransform;
        Character->SetActorTransform(Context.OccupantTransform, false, nullptr, ETeleportType::TeleportPhysics);
        if (Context.Config.bHideParticipant && !Character->IsHidden())
        {
            Character->SetActorHiddenInGame(true);
        }
        EnsureCameraActor(Context.CameraTransform);
        if (APlayerController* PC = GetPlayerController(); PC && HideCameraActor.IsValid())
        {
            PC->SetControlRotation(Context.CameraTransform.Rotator());
            PC->SetViewTarget(HideCameraActor.Get());
            BeginHideView(Context);
        }
    }
}

void UJMHideCharacterParticipantComponent::RestoreState(const FGuid& SessionId,
    const FJMHideParticipantSnapshot& Snapshot)
{
    EndHideView();
    ACharacter* Character = GetCharacter();
    if (!Character || !Snapshot.bCaptured)
    {
        return;
    }
    UCharacterMovementComponent* Movement = Character->GetCharacterMovement();
    UCapsuleComponent* Capsule = Character->GetCapsuleComponent();
    if (Snapshot.bChangedMovement && Movement->MovementMode == MOVE_None)
    {
        Movement->SetMovementMode(OriginalMovementMode, OriginalCustomMovementMode);
    }
    if (Snapshot.bChangedCollision && Capsule->GetCollisionEnabled() == ECollisionEnabled::NoCollision)
    {
        Capsule->SetCollisionProfileName(OriginalCollisionProfile);
        Capsule->SetCollisionEnabled(OriginalCollision);
    }
    if (Snapshot.bChangedVisibility && Character->IsHidden())
    {
        Character->SetActorHiddenInGame(bOriginalHidden);
    }
    if (Snapshot.bChangedTransform && bRestoreActorTransform)
    {
        Character->SetActorTransform(OriginalActorTransform, false, nullptr, ETeleportType::TeleportPhysics);
    }
    if (APlayerController* PC = GetPlayerController())
    {
        if (Snapshot.bChangedViewTarget && HideCameraActor.IsValid() && PC->GetViewTarget() == HideCameraActor.Get() && OriginalViewTarget.IsValid())
        {
            PC->SetViewTarget(OriginalViewTarget.Get());
        }
        if (Snapshot.bChangedLookConstraint && PC->GetControlRotation().Equals(ActiveContext.CameraTransform.Rotator(), 0.1f))
        {
            PC->SetControlRotation(OriginalControlRotation);
        }
    }
    if (HideCameraActor.IsValid())
    {
        HideCameraActor->Destroy();
        HideCameraActor.Reset();
    }
}

bool UJMHideCharacterParticipantComponent::CanOccupyTransform(const FTransform& Transform) const
{
    const ACharacter* Character = GetCharacter();
    const UCapsuleComponent* Capsule = Character ? Character->GetCapsuleComponent() : nullptr;
    UWorld* World = GetWorld();
    if (!Capsule || !World)
    {
        return false;
    }
    FCollisionQueryParams Params(SCENE_QUERY_STAT(JMHideExit), false, Character);
    const FCollisionShape Shape = FCollisionShape::MakeCapsule(
        Capsule->GetScaledCapsuleRadius(), Capsule->GetScaledCapsuleHalfHeight());
    const FName Profile = OriginalCollisionProfile.IsNone() ? FName(TEXT("Pawn")) : OriginalCollisionProfile;
    return !World->OverlapBlockingTestByProfile(Transform.GetLocation(), Transform.GetRotation(), Profile, Shape, Params);
}

FTransform UJMHideCharacterParticipantComponent::GetViewTransform() const
{
    if (const APlayerController* PC = GetPlayerController())
    {
        FVector Location;
        FRotator Rotation;
        PC->GetPlayerViewPoint(Location, Rotation);
        return FTransform(Rotation, Location);
    }
    return Super::GetViewTransform();
}
