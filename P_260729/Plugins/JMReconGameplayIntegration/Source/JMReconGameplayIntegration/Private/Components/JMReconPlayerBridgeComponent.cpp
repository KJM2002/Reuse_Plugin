#include "Components/JMReconPlayerBridgeComponent.h"

#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"
#include "CollisionShape.h"
#include "Components/InputComponent.h"
#include "Components/JMInteractionComponent.h"
#include "Components/JMReconInteractorComponent.h"
#include "Components/JMReconTargetComponent.h"
#include "Components/SpotLightComponent.h"
#include "Data/JMReconDefinition.h"
#include "Engine/World.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "JMReconGameplayIntegration.h"
#include "Kismet/GameplayStatics.h"
#include "Settings/JMReconGameplayIntegrationSettings.h"
#include "Sound/SoundBase.h"
#include "TimerManager.h"
#include "UI/JMReconPromptWidgetBase.h"

UJMReconPlayerBridgeComponent::UJMReconPlayerBridgeComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = false;
}

float UJMReconPlayerBridgeComponent::AccumulateClampedLookAngle(
    float CurrentOffset,
    float PreviousControlAngle,
    float CurrentControlAngle,
    float Limit)
{
    const float SafeLimit = FMath::Max(0.0f, Limit);
    const float InputDelta = FMath::FindDeltaAngleDegrees(
        PreviousControlAngle,
        CurrentControlAngle);
    return FMath::Clamp(CurrentOffset + InputDelta, -SafeLimit, SafeLimit);
}

void UJMReconPlayerBridgeComponent::BeginPlay()
{
    Super::BeginPlay();

    CacheComponents();
    if (!ReconInteractor)
    {
        UE_LOG(
            LogJMReconGameplayIntegration,
            Warning,
            TEXT("%s has a Recon player bridge but no JMReconInteractorComponent."),
            *GetNameSafe(GetOwner()));
        return;
    }

    ReconInteractor->OnSessionStarted.AddUniqueDynamic(
        this,
        &UJMReconPlayerBridgeComponent::HandleSessionStarted);
    ReconInteractor->OnSessionEnded.AddUniqueDynamic(
        this,
        &UJMReconPlayerBridgeComponent::HandleSessionEnded);
    ReconInteractor->OnCameraTransformRequested.AddUniqueDynamic(
        this,
        &UJMReconPlayerBridgeComponent::HandleCameraTransformRequested);
    ReconInteractor->OnCameraRestoreRequested.AddUniqueDynamic(
        this,
        &UJMReconPlayerBridgeComponent::HandleCameraRestoreRequested);
    ReconInteractor->OnIlluminateRequested.AddUniqueDynamic(
        this,
        &UJMReconPlayerBridgeComponent::HandleIlluminateRequested);
    ReconInteractor->OnStateChanged.AddUniqueDynamic(
        this,
        &UJMReconPlayerBridgeComponent::HandleStateChanged);
    if (InteractionComponent)
    {
        InteractionComponent->OnCurrentInteractableChanged.AddUniqueDynamic(
            this, &UJMReconPlayerBridgeComponent::HandleFocusedInteractableChanged);
    }

    CreatePromptWidget();
    UpdatePrompt();

    if (GetDefault<UJMReconGameplayIntegrationSettings>()->bAutoBindInput)
    {
        TryBindInput();
        if (!bInputBound && GetWorld())
        {
            GetWorld()->GetTimerManager().SetTimer(
                InputBindingRetryHandle,
                this,
                &UJMReconPlayerBridgeComponent::TryBindInput,
                0.1f,
                true);
        }
    }
}

void UJMReconPlayerBridgeComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (GetWorld())
    {
        GetWorld()->GetTimerManager().ClearTimer(InputBindingRetryHandle);
        GetWorld()->GetTimerManager().ClearTimer(PromptFailureTimerHandle);
    }
    RestorePlayerState();

    if (APlayerController* PlayerController = ResolvePlayerController();
        PlayerController && ReconInputComponent)
    {
        PlayerController->PopInputComponent(ReconInputComponent);
    }
    if (ReconInputComponent)
    {
        ReconInputComponent->DestroyComponent();
        ReconInputComponent = nullptr;
    }
    bInputBound = false;

    if (ReconInteractor)
    {
        ReconInteractor->OnSessionStarted.RemoveDynamic(
            this,
            &UJMReconPlayerBridgeComponent::HandleSessionStarted);
        ReconInteractor->OnSessionEnded.RemoveDynamic(
            this,
            &UJMReconPlayerBridgeComponent::HandleSessionEnded);
        ReconInteractor->OnCameraTransformRequested.RemoveDynamic(
            this,
            &UJMReconPlayerBridgeComponent::HandleCameraTransformRequested);
        ReconInteractor->OnCameraRestoreRequested.RemoveDynamic(
            this,
            &UJMReconPlayerBridgeComponent::HandleCameraRestoreRequested);
        ReconInteractor->OnIlluminateRequested.RemoveDynamic(
            this,
            &UJMReconPlayerBridgeComponent::HandleIlluminateRequested);
        ReconInteractor->OnStateChanged.RemoveDynamic(
            this,
            &UJMReconPlayerBridgeComponent::HandleStateChanged);
    }
    if (InteractionComponent)
    {
        InteractionComponent->OnCurrentInteractableChanged.RemoveDynamic(
            this, &UJMReconPlayerBridgeComponent::HandleFocusedInteractableChanged);
    }
    RestoreFocusPromptSuppression();
    if (ReconPromptWidget)
    {
        ReconPromptWidget->RemoveFromParent();
        ReconPromptWidget = nullptr;
    }
    if (ReconCameraActor)
    {
        ReconCameraActor->Destroy();
        ReconCameraActor = nullptr;
        ReconIlluminateLight = nullptr;
    }
    Super::EndPlay(EndPlayReason);
}

void UJMReconPlayerBridgeComponent::CacheComponents()
{
    AActor* Owner = GetOwner();
    InteractionComponent = Owner ? Owner->FindComponentByClass<UJMInteractionComponent>() : nullptr;
    ReconInteractor = Owner ? Owner->FindComponentByClass<UJMReconInteractorComponent>() : nullptr;
}

void UJMReconPlayerBridgeComponent::CreatePromptWidget()
{
    const UJMReconGameplayIntegrationSettings* Settings =
        GetDefault<UJMReconGameplayIntegrationSettings>();
    APlayerController* PlayerController = ResolvePlayerController();
    if (!Settings->bCreateReconPromptWidget || !PlayerController || ReconPromptWidget)
    {
        return;
    }

    UClass* WidgetClass = UJMReconPromptWidgetBase::StaticClass();
    if (!Settings->ReconPromptWidgetClass.IsNull())
    {
        if (UClass* LoadedClass = Settings->ReconPromptWidgetClass.LoadSynchronous())
        {
            WidgetClass = LoadedClass;
        }
    }
    ReconPromptWidget = CreateWidget<UJMReconPromptWidgetBase>(PlayerController, WidgetClass);
    if (ReconPromptWidget)
    {
        ReconPromptWidget->ApplyReconPromptStyle(Settings->ReconPromptStyle);
        ReconPromptWidget->AddToViewport(100);
    }
}

void UJMReconPlayerBridgeComponent::RestoreFocusPromptSuppression()
{
    if (InteractionComponent && bFocusPromptSuppressionApplied)
    {
        InteractionComponent->SetPromptSuppressed(bPromptSuppressedBeforeFocus);
    }
    bFocusPromptSuppressionApplied = false;
}

void UJMReconPlayerBridgeComponent::UpdatePrompt()
{
    if (!ReconPromptWidget || bFailurePromptActive)
    {
        return;
    }

    const UJMReconGameplayIntegrationSettings* Settings =
        GetDefault<UJMReconGameplayIntegrationSettings>();
    const EJMReconState State = ReconInteractor
        ? ReconInteractor->GetCurrentState()
        : EJMReconState::Idle;
    const FText StartKey = Settings->StartOrFinishKey.GetDisplayName();
    const FText InteractionKey = Settings->InteractionDisplayKey.GetDisplayName();
    const FText FlashlightKey = Settings->IlluminateKey.GetDisplayName();

    if (State == EJMReconState::Entering)
    {
        ReconPromptWidget->SetReconPrompt(Settings->EnteringPrompt, true);
        return;
    }
    if (State == EJMReconState::Peeking)
    {
        const FText Prompt = ReconInteractor->IsIlluminating()
            ? FText::Format(
                Settings->FlashlightActivePromptFormat,
                FlashlightKey, StartKey)
            : FText::Format(
                Settings->ObservingPromptFormat,
                FlashlightKey, StartKey);
        ReconPromptWidget->SetReconPrompt(Prompt, true);
        return;
    }
    if (State == EJMReconState::Exiting)
    {
        ReconPromptWidget->SetReconPrompt(FText::GetEmpty(), false);
        return;
    }

    UJMReconTargetComponent* FocusedTarget = FindFocusedReconTarget();
    if (FocusedTarget)
    {
        if (InteractionComponent && !bFocusPromptSuppressionApplied)
        {
            bPromptSuppressedBeforeFocus = InteractionComponent->IsPromptSuppressed();
            InteractionComponent->SetPromptSuppressed(true);
            bFocusPromptSuppressionApplied = true;
        }
        ReconPromptWidget->SetReconPrompt(
            FText::Format(
                Settings->FocusedTargetPromptFormat,
                InteractionKey,
                StartKey),
            true);
    }
    else
    {
        RestoreFocusPromptSuppression();
        ReconPromptWidget->SetReconPrompt(FText::GetEmpty(), false);
    }
}

void UJMReconPlayerBridgeComponent::ShowFailure(EJMReconFailureReason FailureReason)
{
    if (!ReconPromptWidget)
    {
        return;
    }

    FText Message;
    const UJMReconGameplayIntegrationSettings* Settings =
        GetDefault<UJMReconGameplayIntegrationSettings>();
    switch (FailureReason)
    {
    case EJMReconFailureReason::DoorMoving:
        Message = Settings->DoorMovingFailurePrompt;
        break;
    case EJMReconFailureReason::DoorOpen:
        Message = Settings->DoorOpenFailurePrompt;
        break;
    case EJMReconFailureReason::Blocked:
        Message = Settings->BlockedFailurePrompt;
        break;
    case EJMReconFailureReason::OutOfRange:
        Message = Settings->OutOfRangeFailurePrompt;
        break;
    default:
        Message = Settings->GenericFailurePrompt;
        break;
    }
    bFailurePromptActive = true;
    ReconPromptWidget->SetReconPrompt(Message, true);
    if (UWorld* World = GetWorld())
    {
        const TWeakObjectPtr<UJMReconPlayerBridgeComponent> WeakThis(this);
        FTimerDelegate Delegate;
        Delegate.BindLambda([WeakThis]()
        {
            if (WeakThis.IsValid())
            {
                WeakThis->bFailurePromptActive = false;
                WeakThis->UpdatePrompt();
            }
        });
        World->GetTimerManager().SetTimer(PromptFailureTimerHandle, Delegate, 1.5f, false);
    }
}

void UJMReconPlayerBridgeComponent::HandleFocusedInteractableChanged(
    UObject* OldInteractable, UObject* NewInteractable)
{
    UpdatePrompt();
}

void UJMReconPlayerBridgeComponent::HandleStateChanged(
    EJMReconState OldState, EJMReconState NewState)
{
    if (NewState == EJMReconState::Exiting)
    {
        BeginPlayerReturn();
        UJMReconTargetComponent* Target =
            ReconInteractor ? ReconInteractor->GetCurrentTarget() : nullptr;
        UJMReconDefinition* Definition =
            Target ? Target->GetEffectiveDefinition() : nullptr;
        BeginCameraReturn(
            Definition
                ? Definition->ExitingDuration
                : GetDefault<UJMReconGameplayIntegrationSettings>()->RestoreBlendTime);
    }
    UpdatePrompt();
}

void UJMReconPlayerBridgeComponent::TryBindInput()
{
    if (bInputBound)
    {
        if (GetWorld())
        {
            GetWorld()->GetTimerManager().ClearTimer(InputBindingRetryHandle);
        }
        return;
    }

    const APawn* Pawn = Cast<APawn>(GetOwner());
    APlayerController* PlayerController = ResolvePlayerController();
    if (!Pawn || !Pawn->InputComponent || !PlayerController)
    {
        return;
    }

    ReconInputComponent = NewObject<UInputComponent>(
        GetOwner(),
        TEXT("JMReconInputComponent"),
        RF_Transient);
    ReconInputComponent->Priority = 100;
    ReconInputComponent->bBlockInput = false;
    ReconInputComponent->RegisterComponent();

    UInputComponent* Input = ReconInputComponent;
    const UJMReconGameplayIntegrationSettings* Settings =
        GetDefault<UJMReconGameplayIntegrationSettings>();
    FInputKeyBinding& StartBinding = Input->BindKey(
        Settings->StartOrFinishKey,
        IE_Pressed,
        this,
        &UJMReconPlayerBridgeComponent::HandleStartOrFinishInput);
    StartBinding.bConsumeInput = false;
    FInputKeyBinding& IlluminatePressedBinding = Input->BindKey(
        Settings->IlluminateKey,
        IE_Pressed,
        this,
        &UJMReconPlayerBridgeComponent::HandleIlluminatePressed);
    IlluminatePressedBindingIndex = Input->KeyBindings.Num() - 1;
    IlluminatePressedBinding.bConsumeInput = false;
    FInputKeyBinding& IlluminateReleasedBinding = Input->BindKey(
        Settings->IlluminateKey,
        IE_Released,
        this,
        &UJMReconPlayerBridgeComponent::HandleIlluminateReleased);
    IlluminateReleasedBindingIndex = Input->KeyBindings.Num() - 1;
    IlluminateReleasedBinding.bConsumeInput = false;
    FInputKeyBinding& CancelBinding = Input->BindKey(
        Settings->CancelKey,
        IE_Pressed,
        this,
        &UJMReconPlayerBridgeComponent::HandleCancelInput);
    CancelBinding.bConsumeInput = false;
    FInputKeyBinding& ExitBinding = Input->BindKey(
        Settings->ExitKey,
        IE_Pressed,
        this,
        &UJMReconPlayerBridgeComponent::HandleExitInput);
    ExitBinding.bConsumeInput = false;

    PlayerController->PushInputComponent(ReconInputComponent);
    SetIlluminateInputCaptured(bIlluminateInputCaptured);
    bInputBound = true;
    if (GetWorld())
    {
        GetWorld()->GetTimerManager().ClearTimer(InputBindingRetryHandle);
    }
}

UJMReconTargetComponent* UJMReconPlayerBridgeComponent::FindReconTargetOnActor(AActor* Actor) const
{
    for (AActor* Candidate = Actor; Candidate; Candidate = Candidate->GetAttachParentActor())
    {
        if (UJMReconTargetComponent* Target =
            Candidate->FindComponentByClass<UJMReconTargetComponent>())
        {
            return Target;
        }
    }
    return nullptr;
}

UJMReconTargetComponent* UJMReconPlayerBridgeComponent::FindFocusedReconTarget() const
{
    if (!InteractionComponent)
    {
        return nullptr;
    }
    return FindReconTargetOnActor(InteractionComponent->GetCurrentInteractableActor());
}

bool UJMReconPlayerBridgeComponent::IsCameraPlacementValid(
    UJMReconTargetComponent* Target) const
{
    const UJMReconGameplayIntegrationSettings* Settings =
        GetDefault<UJMReconGameplayIntegrationSettings>();
    UWorld* World = GetWorld();
    if (!Settings->bValidateCameraPlacement || !Target || !World ||
        Settings->CameraCollisionRadius <= 0.0f)
    {
        return true;
    }

    FCollisionQueryParams QueryParams(SCENE_QUERY_STAT(JMReconCameraPlacement), false);
    QueryParams.AddIgnoredActor(GetOwner());
    QueryParams.AddIgnoredActor(Target->GetOwner());
    return !World->OverlapBlockingTestByChannel(
        Target->GetPeekCameraWorldTransform().GetLocation(),
        Target->GetPeekCameraWorldTransform().GetRotation(),
        ECC_Visibility,
        FCollisionShape::MakeSphere(Settings->CameraCollisionRadius),
        QueryParams);
}

FJMReconRequestResult UJMReconPlayerBridgeComponent::TryStartReconFromFocusedTarget()
{
    CacheComponents();
    if (!ReconInteractor || !InteractionComponent)
    {
        return FJMReconRequestResult::Failure(EJMReconFailureReason::InvalidInteractor);
    }

    InteractionComponent->RefreshCurrentInteractable();
    UJMReconTargetComponent* Target = FindFocusedReconTarget();
    const FJMReconRequestResult Result = TryStartReconWithTarget(Target);
    if (!Result.bSucceeded)
    {
        ShowFailure(Result.FailureReason);
    }
    return Result;
}

FJMReconRequestResult UJMReconPlayerBridgeComponent::TryStartReconWithTarget(
    UJMReconTargetComponent* Target)
{
    CacheComponents();
    if (!Target)
    {
        return FJMReconRequestResult::Failure(EJMReconFailureReason::InvalidTarget);
    }
    if (!IsCameraPlacementValid(Target))
    {
        return FJMReconRequestResult::Failure(EJMReconFailureReason::Blocked);
    }
    return ReconInteractor
        ? ReconInteractor->TryStartRecon(Target)
        : FJMReconRequestResult::Failure(EJMReconFailureReason::InvalidInteractor);
}

void UJMReconPlayerBridgeComponent::HandleStartOrFinishInput()
{
    if (!ReconInteractor)
    {
        CacheComponents();
    }
    if (ReconInteractor &&
        (ReconInteractor->GetCurrentState() == EJMReconState::Entering ||
         ReconInteractor->GetCurrentState() == EJMReconState::Exiting))
    {
        return;
    }
    if (ReconInteractor && ReconInteractor->IsReconActive())
    {
        ReconInteractor->FinishRecon();
        return;
    }
    TryStartReconFromFocusedTarget();
}

void UJMReconPlayerBridgeComponent::HandleIlluminatePressed()
{
    if (ReconInteractor && ReconInteractor->GetCurrentState() == EJMReconState::Peeking)
    {
        ReconInteractor->SetIlluminate(true);
    }
}

void UJMReconPlayerBridgeComponent::HandleExitInput()
{
    if (ReconInteractor && ReconInteractor->IsReconActive() &&
        ReconInteractor->GetCurrentState() != EJMReconState::Exiting)
    {
        ReconInteractor->FinishRecon();
    }
}

void UJMReconPlayerBridgeComponent::HandleIlluminateReleased()
{
    if (ReconInteractor && ReconInteractor->GetCurrentState() == EJMReconState::Peeking)
    {
        ReconInteractor->SetIlluminate(false);
    }
    if (bAwaitingIlluminateRelease)
    {
        bAwaitingIlluminateRelease = false;
        SetIlluminateInputCaptured(false);
    }
}

void UJMReconPlayerBridgeComponent::SetIlluminateInputCaptured(bool bCaptured)
{
    bIlluminateInputCaptured = bCaptured;
    if (!ReconInputComponent)
    {
        return;
    }

    if (ReconInputComponent->KeyBindings.IsValidIndex(IlluminatePressedBindingIndex))
    {
        ReconInputComponent->KeyBindings[IlluminatePressedBindingIndex].bConsumeInput =
            bCaptured;
    }
    if (ReconInputComponent->KeyBindings.IsValidIndex(IlluminateReleasedBindingIndex))
    {
        ReconInputComponent->KeyBindings[IlluminateReleasedBindingIndex].bConsumeInput =
            bCaptured;
    }
}

void UJMReconPlayerBridgeComponent::ReleaseIlluminateInputWhenSafe()
{
    const UJMReconGameplayIntegrationSettings* Settings =
        GetDefault<UJMReconGameplayIntegrationSettings>();
    const APlayerController* PlayerController = ResolvePlayerController();
    bAwaitingIlluminateRelease =
        PlayerController && PlayerController->IsInputKeyDown(Settings->IlluminateKey);
    if (!bAwaitingIlluminateRelease)
    {
        SetIlluminateInputCaptured(false);
    }
}

void UJMReconPlayerBridgeComponent::ForcePlayerFlashlightsOff()
{
    AActor* Owner = GetOwner();
    if (!Owner)
    {
        return;
    }

    TInlineComponentArray<USpotLightComponent*> PlayerSpotLights(Owner);
    for (USpotLightComponent* SpotLight : PlayerSpotLights)
    {
        if (IsValid(SpotLight))
        {
            SpotLight->SetVisibility(false, true);
        }
    }
}

void UJMReconPlayerBridgeComponent::HandleCancelInput()
{
    if (ReconInteractor && ReconInteractor->IsReconActive())
    {
        ReconInteractor->CancelRecon();
    }
}

APlayerController* UJMReconPlayerBridgeComponent::ResolvePlayerController() const
{
    const APawn* Pawn = Cast<APawn>(GetOwner());
    return Pawn ? Cast<APlayerController>(Pawn->GetController()) : nullptr;
}

void UJMReconPlayerBridgeComponent::HandleSessionStarted(
    FGuid SessionId,
    UJMReconTargetComponent* Target)
{
    const UJMReconGameplayIntegrationSettings* Settings =
        GetDefault<UJMReconGameplayIntegrationSettings>();
    APlayerController* PlayerController = ResolvePlayerController();
    APawn* Pawn = Cast<APawn>(GetOwner());
    bSessionStateCaptured = true;
    bAwaitingIlluminateRelease = false;
    SetIlluminateInputCaptured(true);
    ForcePlayerFlashlightsOff();

    if (PlayerController)
    {
        PreviousViewTarget = PlayerController->GetViewTarget();
        SavedControlRotation = PlayerController->GetControlRotation();
        if (Settings->bLockMovementDuringRecon)
        {
            PlayerController->SetIgnoreMoveInput(true);
            bMovementLockApplied = true;
        }
    }

    if (InteractionComponent)
    {
        bPreviousInteractionEnabled = InteractionComponent->bInteractionEnabled;
        // A focused Recon target temporarily suppresses the normal interaction
        // prompt in favor of the combined Recon prompt. Preserve the state from
        // before that focus suppression, not the temporary true value.
        bPreviousPromptSuppressed = bFocusPromptSuppressionApplied
            ? bPromptSuppressedBeforeFocus
            : InteractionComponent->IsPromptSuppressed();
        // The active session now owns suppression. Prevent the focus layer from
        // restoring over the session layer while focus is cleared on disable.
        bFocusPromptSuppressionApplied = false;
        InteractionComponent->SetInteractionEnabled(false);
        InteractionComponent->SetPromptSuppressed(true);
    }

    if (Settings->bAlignPlayerToTarget && Pawn && Target)
    {
        AlignmentStartTransform = Pawn->GetActorTransform();
        bPlayerTransformCaptured = true;
        AlignmentTargetTransform = Target->GetPlayerWorldTransform();
        UJMReconDefinition* Definition = Target->GetEffectiveDefinition();
        AlignmentDuration = Definition ? Definition->EnteringDuration : 0.0f;
        AlignmentElapsed = 0.0f;
        bAligningPlayer = AlignmentDuration > 0.0f;
        if (!bAligningPlayer)
        {
            Pawn->SetActorLocationAndRotation(
                AlignmentTargetTransform.GetLocation(),
                AlignmentTargetTransform.Rotator(),
                true);
        }
        SetComponentTickEnabled(bAligningPlayer);
    }
}

void UJMReconPlayerBridgeComponent::HandleSessionEnded(
    FGuid SessionId,
    EJMReconEndReason Reason)
{
    // StateChanged(Idle) can run immediately before this callback and may have
    // observed a transient focus. Discard that ownership, restore the genuine
    // pre-session state, then let the current focus acquire suppression again.
    bFocusPromptSuppressionApplied = false;
    RestorePlayerState();
    ReleaseIlluminateInputWhenSafe();
    UpdatePrompt();
}

void UJMReconPlayerBridgeComponent::BeginPlayerReturn()
{
    if (!bSessionStateCaptured || !bPlayerTransformCaptured)
    {
        return;
    }

    APawn* Pawn = Cast<APawn>(GetOwner());
    UJMReconTargetComponent* Target =
        ReconInteractor ? ReconInteractor->GetCurrentTarget() : nullptr;
    UJMReconDefinition* Definition =
        Target ? Target->GetEffectiveDefinition() : nullptr;
    if (!Pawn)
    {
        return;
    }

    bAligningPlayer = false;
    ReturnStartTransform = Pawn->GetActorTransform();
    ReturnElapsed = 0.0f;
    ReturnDuration = Definition
        ? FMath::Max(0.0f, Definition->ExitingDuration)
        : FMath::Max(
            0.0f,
            GetDefault<UJMReconGameplayIntegrationSettings>()->RestoreBlendTime);
    bReturningPlayer = ReturnDuration > 0.0f &&
        !ReturnStartTransform.Equals(AlignmentStartTransform);
    if (!bReturningPlayer)
    {
        Pawn->SetActorTransform(
            AlignmentStartTransform,
            false,
            nullptr,
            ETeleportType::TeleportPhysics);
    }
    SetComponentTickEnabled(
        bReturningPlayer ||
        !FMath::IsNearlyEqual(
            FlashlightCurrentIntensity,
            FlashlightTargetIntensity,
            1.0f));
}

void UJMReconPlayerBridgeComponent::BeginCameraReturn(float BlendTime)
{
    const UJMReconGameplayIntegrationSettings* Settings =
        GetDefault<UJMReconGameplayIntegrationSettings>();
    APlayerController* PlayerController = ResolvePlayerController();
    if (!Settings->bAutoManageCamera || !PlayerController || bCameraReturnStarted)
    {
        return;
    }

    AActor* RestoreTarget = PreviousViewTarget.Get();
    if (!RestoreTarget)
    {
        RestoreTarget = GetOwner();
    }

    // The Recon look intentionally changes ControlRotation while the outgoing
    // camera is active. Restore it before starting the blend so the incoming
    // player camera already has its final orientation instead of snapping when
    // the session cleanup runs.
    PlayerController->SetControlRotation(SavedControlRotation);
    if (!PlayerController->IsLookInputIgnored())
    {
        PlayerController->SetIgnoreLookInput(true);
        bReturnLookLockApplied = true;
    }
    PlayerController->SetViewTargetWithBlend(
        RestoreTarget,
        FMath::Max(0.0f, BlendTime),
        VTBlend_Cubic,
        2.0f,
        true);
    bCameraReturnStarted = true;
}

void UJMReconPlayerBridgeComponent::RestorePlayerState()
{
    if (!bSessionStateCaptured)
    {
        return;
    }

    APlayerController* PlayerController = ResolvePlayerController();
    if (PlayerController && bMovementLockApplied)
    {
        PlayerController->SetIgnoreMoveInput(false);
        bMovementLockApplied = false;
    }
    if (PlayerController && bReturnLookLockApplied)
    {
        PlayerController->SetIgnoreLookInput(false);
        bReturnLookLockApplied = false;
    }
    if (PlayerController)
    {
        PlayerController->SetControlRotation(SavedControlRotation);
    }
    if (InteractionComponent)
    {
        InteractionComponent->SetInteractionEnabled(bPreviousInteractionEnabled);
        InteractionComponent->SetPromptSuppressed(bPreviousPromptSuppressed);
    }
    if (bPlayerTransformCaptured)
    {
        if (APawn* Pawn = Cast<APawn>(GetOwner()))
        {
            Pawn->SetActorTransform(
                AlignmentStartTransform,
                false,
                nullptr,
                ETeleportType::TeleportPhysics);
        }
    }
    bAligningPlayer = false;
    bReturningPlayer = false;
    bPlayerTransformCaptured = false;
    bCameraReturnStarted = false;
    ReconLookYaw = 0.0f;
    ReconLookPitch = 0.0f;
    FlashlightTargetIntensity = 0.0f;
    FlashlightCurrentIntensity = 0.0f;
    if (ReconInteractor && ReconInteractor->IsIlluminating())
    {
        ReconInteractor->SetIlluminate(false);
    }
    if (ReconIlluminateLight)
    {
        ReconIlluminateLight->SetIntensity(0.0f);
        ReconIlluminateLight->SetVisibility(false);
    }
    bSessionStateCaptured = false;
    SetComponentTickEnabled(false);
}

void UJMReconPlayerBridgeComponent::HandleCameraTransformRequested(
    const FTransform& WorldTransform,
    EJMReconState State,
    float BlendTime)
{
    const UJMReconGameplayIntegrationSettings* Settings =
        GetDefault<UJMReconGameplayIntegrationSettings>();
    APlayerController* PlayerController = ResolvePlayerController();
    if (!Settings->bAutoManageCamera || !PlayerController || !GetWorld())
    {
        return;
    }

    if (!ReconCameraActor)
    {
        FActorSpawnParameters SpawnParameters;
        SpawnParameters.Owner = GetOwner();
        SpawnParameters.ObjectFlags |= RF_Transient;
        ReconCameraActor = GetWorld()->SpawnActor<ACameraActor>(
            ACameraActor::StaticClass(),
            WorldTransform,
            SpawnParameters);
    }
    if (!ReconCameraActor)
    {
        return;
    }
    if (!ReconIlluminateLight && ReconCameraActor->GetCameraComponent())
    {
        ReconIlluminateLight = NewObject<USpotLightComponent>(
            ReconCameraActor,
            TEXT("JMReconIlluminateLight"));
        ReconIlluminateLight->SetupAttachment(ReconCameraActor->GetCameraComponent());
        ReconIlluminateLight->SetIntensity(0.0f);
        ReconIlluminateLight->SetAttenuationRadius(Settings->IlluminateAttenuationRadius);
        ReconIlluminateLight->SetInnerConeAngle(Settings->IlluminateInnerConeAngle);
        ReconIlluminateLight->SetOuterConeAngle(Settings->IlluminateOuterConeAngle);
        ReconIlluminateLight->SetLightColor(Settings->IlluminateColor);
        ReconIlluminateLight->SetVisibility(false);
        ReconIlluminateLight->RegisterComponent();
    }

    ReconCameraActor->SetActorTransform(WorldTransform);
    if (PlayerController->PlayerCameraManager && ReconCameraActor->GetCameraComponent())
    {
        ReconCameraActor->GetCameraComponent()->SetFieldOfView(
            Settings->ReconFieldOfView > 0.0f
                ? Settings->ReconFieldOfView
                : PlayerController->PlayerCameraManager->GetFOVAngle());
    }
    PlayerController->SetViewTargetWithBlend(
        ReconCameraActor,
        FMath::Max(0.0f, BlendTime),
        VTBlend_Cubic,
        2.0f,
        true);

    PeekBaseTransform = WorldTransform;
    PeekControlRotationOrigin = PlayerController->GetControlRotation();
    LastObservedControlRotation = PeekControlRotationOrigin;
    ReconLookYaw = 0.0f;
    ReconLookPitch = 0.0f;
    SetComponentTickEnabled(
        State == EJMReconState::Peeking ||
        bAligningPlayer ||
        !FMath::IsNearlyEqual(FlashlightCurrentIntensity, FlashlightTargetIntensity));
}

void UJMReconPlayerBridgeComponent::HandleCameraRestoreRequested()
{
    const UJMReconGameplayIntegrationSettings* Settings =
        GetDefault<UJMReconGameplayIntegrationSettings>();
    APlayerController* PlayerController = ResolvePlayerController();
    if (!Settings->bAutoManageCamera || !PlayerController)
    {
        return;
    }

    if (bCameraReturnStarted)
    {
        PreviousViewTarget.Reset();
        bCameraReturnStarted = false;
        return;
    }

    AActor* RestoreTarget = PreviousViewTarget.Get();
    if (!RestoreTarget)
    {
        RestoreTarget = GetOwner();
    }
    PlayerController->SetViewTargetWithBlend(
        RestoreTarget,
        FMath::Max(0.0f, Settings->RestoreBlendTime),
        VTBlend_Cubic,
        2.0f,
        true);
    PreviousViewTarget.Reset();
    SetComponentTickEnabled(false);
}

void UJMReconPlayerBridgeComponent::HandleIlluminateRequested(bool bEnabled)
{
    const UJMReconGameplayIntegrationSettings* Settings =
        GetDefault<UJMReconGameplayIntegrationSettings>();
    if (Settings->bAutoManageIlluminate && ReconIlluminateLight)
    {
        FlashlightTargetIntensity = bEnabled ? Settings->IlluminateIntensity : 0.0f;
        ReconIlluminateLight->SetVisibility(true);
        if (USoundBase* Sound = bEnabled
            ? Settings->FlashlightOnSound.Get()
            : Settings->FlashlightOffSound.Get())
        {
            UGameplayStatics::PlaySound2D(this, Sound);
        }
        OnFlashlightStateChanged.Broadcast(bEnabled);
        SetComponentTickEnabled(true);
    }
    UpdatePrompt();
}

void UJMReconPlayerBridgeComponent::TickComponent(
    float DeltaTime,
    ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    bool bNeedsTick = false;
    const UJMReconGameplayIntegrationSettings* Settings =
        GetDefault<UJMReconGameplayIntegrationSettings>();

    if (bAligningPlayer)
    {
        AlignmentElapsed += DeltaTime;
        const float Alpha = AlignmentDuration > 0.0f
            ? FMath::Clamp(AlignmentElapsed / AlignmentDuration, 0.0f, 1.0f)
            : 1.0f;
        FTransform AlignedTransform;
        AlignedTransform.Blend(
            AlignmentStartTransform,
            AlignmentTargetTransform,
            FMath::InterpEaseInOut(0.0f, 1.0f, Alpha, 2.0f));
        if (APawn* Pawn = Cast<APawn>(GetOwner()))
        {
            Pawn->SetActorLocationAndRotation(
                AlignedTransform.GetLocation(),
                AlignedTransform.Rotator(),
                true);
        }
        bAligningPlayer = Alpha < 1.0f;
        bNeedsTick |= bAligningPlayer;
    }

    if (bReturningPlayer)
    {
        ReturnElapsed += DeltaTime;
        const float Alpha = ReturnDuration > 0.0f
            ? FMath::Clamp(ReturnElapsed / ReturnDuration, 0.0f, 1.0f)
            : 1.0f;
        FTransform ReturnedTransform;
        ReturnedTransform.Blend(
            ReturnStartTransform,
            AlignmentStartTransform,
            FMath::InterpEaseInOut(0.0f, 1.0f, Alpha, 2.0f));
        if (APawn* Pawn = Cast<APawn>(GetOwner()))
        {
            if (Alpha < 1.0f)
            {
                Pawn->SetActorLocationAndRotation(
                    ReturnedTransform.GetLocation(),
                    ReturnedTransform.Rotator(),
                    true);
            }
            else
            {
                Pawn->SetActorTransform(
                    AlignmentStartTransform,
                    false,
                    nullptr,
                    ETeleportType::TeleportPhysics);
            }
        }
        bReturningPlayer = Alpha < 1.0f;
        bNeedsTick |= bReturningPlayer;
    }

    if (ReconIlluminateLight &&
        !FMath::IsNearlyEqual(
            FlashlightCurrentIntensity,
            FlashlightTargetIntensity,
            1.0f))
    {
        const float FadeDuration = FMath::Max(Settings->IlluminateFadeDuration, KINDA_SMALL_NUMBER);
        const float Speed = FMath::Max(Settings->IlluminateIntensity, 1.0f) / FadeDuration;
        FlashlightCurrentIntensity = FMath::FInterpConstantTo(
            FlashlightCurrentIntensity,
            FlashlightTargetIntensity,
            DeltaTime,
            Speed);
        ReconIlluminateLight->SetIntensity(FlashlightCurrentIntensity);
        bNeedsTick = true;
    }
    else if (ReconIlluminateLight)
    {
        FlashlightCurrentIntensity = FlashlightTargetIntensity;
        ReconIlluminateLight->SetIntensity(FlashlightCurrentIntensity);
        if (FlashlightCurrentIntensity <= 1.0f)
        {
            ReconIlluminateLight->SetVisibility(false);
        }
    }

    if (ReconInteractor &&
        ReconInteractor->GetCurrentState() == EJMReconState::Peeking &&
        ReconCameraActor)
    {
        APlayerController* PlayerController = ResolvePlayerController();
        UJMReconTargetComponent* Target = ReconInteractor->GetCurrentTarget();
        UJMReconDefinition* Definition = Target ? Target->GetEffectiveDefinition() : nullptr;
        if (PlayerController && Definition)
        {
            const FRotator CurrentControlRotation = PlayerController->GetControlRotation();
            ReconLookYaw = AccumulateClampedLookAngle(
                ReconLookYaw,
                LastObservedControlRotation.Yaw,
                CurrentControlRotation.Yaw,
                Definition->CameraYawLimit);
            ReconLookPitch = AccumulateClampedLookAngle(
                ReconLookPitch,
                LastObservedControlRotation.Pitch,
                CurrentControlRotation.Pitch,
                Definition->CameraPitchLimit);
            LastObservedControlRotation = CurrentControlRotation;

            FRotator BaseRotation = PeekBaseTransform.Rotator();
            BaseRotation.Roll = 0.0f;
            const FQuat TargetRotation =
                BaseRotation.Quaternion() *
                FRotator(ReconLookPitch, ReconLookYaw, 0.0f).Quaternion();
            const FQuat SmoothedRotation = Settings->CameraLookInterpSpeed > 0.0f
                ? FMath::QInterpTo(
                    ReconCameraActor->GetActorQuat(),
                    TargetRotation,
                    DeltaTime,
                    Settings->CameraLookInterpSpeed)
                : TargetRotation;
            ReconCameraActor->SetActorLocationAndRotation(
                PeekBaseTransform.GetLocation(),
                SmoothedRotation);
            bNeedsTick = true;
        }
    }

    SetComponentTickEnabled(bNeedsTick);
}
