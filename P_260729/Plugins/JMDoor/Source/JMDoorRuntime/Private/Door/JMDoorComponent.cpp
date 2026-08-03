#include "Door/JMDoorComponent.h"
#include "Door/JMDoorEventTags.h"
#include "Door/JMDoorTags.h"

#include "Components/PrimitiveComponent.h"
#include "Curves/CurveFloat.h"
#include "Data/JMDoorConfigData.h"
#include "DrawDebugHelpers.h"
#include "Engine/OverlapResult.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Interfaces/JMDoorAccessProviderInterface.h"
#include "Interfaces/JMDoorInterfaceDispatch.h"
#include "JMDoorLog.h"
#include "Kismet/GameplayStatics.h"
#include "Movement/JMDoorMovementComponent.h"
#include "Movement/JMSlidingDoorMovementComponent.h"
#include "Payloads/JMDoorStateChangedEventPayload.h"
#include "Settings/JMDoorSettings.h"
#include "Subsystems/JMGameplayEventSubsystem.h"
#include "Sound/SoundBase.h"
#include "TimerManager.h"

namespace
{
    const UJMDoorConfigData* JMGetFallbackDoorConfig()
    {
        return GetDefault<UJMDoorConfigData>();
    }
}

UJMDoorComponent::UJMDoorComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = false;
}

void UJMDoorComponent::BeginPlay()
{
    Super::BeginPlay();

    if (!PersistentId.IsValid())
    {
        PersistentId = FGuid::NewGuid();
        UE_LOG(LogJMDoor, Verbose, TEXT("Door '%s' received a runtime-only persistent ID."), *GetNameSafe(GetOwner()));
    }

    if (!MovementComponent && GetOwner())
    {
        MovementComponent = GetOwner()->FindComponentByClass<UJMDoorMovementComponent>();
    }

    const UJMDoorConfigData* EffectiveConfig = GetEffectiveConfig();
    bLocked = EffectiveConfig->bInitiallyLocked;
    DoorDurability = EffectiveConfig->MaxDoorDurability;
    LockDurability = EffectiveConfig->MaxLockDurability;
    CurrentState = bLocked ? EJMDoorState::Locked : EJMDoorState::Closed;

    if (MovementComponent)
    {
        // Actor components do not have a guaranteed BeginPlay order. Capture the
        // Blueprint-authored closed transform before applying the initial state,
        // otherwise an identity transform can flatten/reposition the door leaf.
        MovementComponent->InitializeMovingComponent(MovementComponent->GetMovingComponent());
        if (UJMSlidingDoorMovementComponent* Sliding = Cast<UJMSlidingDoorMovementComponent>(MovementComponent); Sliding && !Sliding->IsLegacySinglePanelAsset())
        {
            Sliding->SetPanelOpenFraction(EJMSlideDoorPanel::Both, 0.0f);
            SlideDoorA = FSlidePanelRuntimeState();
            SlideDoorB = FSlidePanelRuntimeState();
        }
        else
        {
            MovementComponent->SetOpenFraction(0.0f, OpenDirectionSign);
        }
    }
    else if (GetDefault<UJMDoorSettings>()->bWarnOnMissingMovementComponent)
    {
        UE_LOG(LogJMDoor, Warning, TEXT("Door '%s' has no movement component."), *GetNameSafe(GetOwner()));
    }
}

void UJMDoorComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(RetryTimerHandle);
        World->GetTimerManager().ClearTimer(AutoCloseTimerHandle);
        World->GetTimerManager().ClearTimer(SlideDoorAAutoCloseTimerHandle);
        World->GetTimerManager().ClearTimer(SlideDoorBAutoCloseTimerHandle);
        World->GetTimerManager().ClearTimer(SlideDoorARetryTimerHandle);
        World->GetTimerManager().ClearTimer(SlideDoorBRetryTimerHandle);
    }
    SetComponentTickEnabled(false);
    Super::EndPlay(EndPlayReason);
}

void UJMDoorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (IsDualPanelSlidingDoor())
    {
        TickSlideDoorPanels(DeltaTime);
        return;
    }

    if (CurrentState != EJMDoorState::Opening && CurrentState != EJMDoorState::Closing)
    {
        SetComponentTickEnabled(false);
        return;
    }

    const float Direction = TargetOpenFraction >= CurrentOpenFraction ? 1.0f : -1.0f;
    const float ProposedFraction = FMath::Clamp(CurrentOpenFraction + Direction * DeltaTime / FMath::Max(ActiveMoveDuration, 0.01f), 0.0f, 1.0f);
    const float CurrentEasedFraction = GetEffectiveConfig()->MovementCurve
        ? GetEffectiveConfig()->MovementCurve->GetFloatValue(CurrentOpenFraction)
        : CurrentOpenFraction;
    const float ProposedEasedFraction = GetEffectiveConfig()->MovementCurve
        ? GetEffectiveConfig()->MovementCurve->GetFloatValue(ProposedFraction)
        : ProposedFraction;

    PushCharactersAlongSweptPath(CurrentEasedFraction, ProposedEasedFraction);

    AActor* BlockingActor = nullptr;
    if (!bReversingFromObstruction && GetEffectiveConfig()->bDetectObstructions && GetEffectiveConfig()->BlockBehavior != EJMDoorBlockBehavior::Ignore && IsObstructed(ProposedFraction, BlockingActor))
    {
        HandleObstruction(BlockingActor);
        return;
    }

    CurrentOpenFraction = ProposedFraction;
    MovementComponent->SetOpenFraction(ProposedEasedFraction, OpenDirectionSign);

    if (FMath::IsNearlyEqual(CurrentOpenFraction, TargetOpenFraction, KINDA_SMALL_NUMBER))
    {
        CurrentOpenFraction = TargetOpenFraction;
        FinishMovement();
    }
}

FJMDoorResult UJMDoorComponent::ExecuteCommand(EJMDoorCommand Command, const FJMDoorUseContext& Context)
{
    switch (Command)
    {
    case EJMDoorCommand::Open: return OpenDoor(Context);
    case EJMDoorCommand::Close: return CloseDoor(Context);
    case EJMDoorCommand::Toggle: return ToggleDoor(Context);
    case EJMDoorCommand::Unlock: return UnlockDoor(Context);
    case EJMDoorCommand::Lock: return LockDoor();
    case EJMDoorCommand::ForceOpen: return ForceOpenDoor(1.0f, Context);
    default: return FJMDoorResult::Failure(EJMDoorResultCode::InvalidRequest, NSLOCTEXT("JMDoor", "InvalidCommand", "Invalid door command."));
    }
}

bool UJMDoorComponent::CanExecuteCommand(EJMDoorCommand Command, const FJMDoorUseContext& Context) const
{
    if (CurrentState == EJMDoorState::Broken || !MovementComponent)
    {
        return false;
    }
    if (Command == EJMDoorCommand::Close && CurrentOpenFraction <= KINDA_SMALL_NUMBER)
    {
        return false;
    }
    if ((Command == EJMDoorCommand::Open || Command == EJMDoorCommand::Toggle) && bLocked)
    {
        FJMDoorResult Ignored;
        return ResolveAccess(Context, false, Ignored);
    }
    return true;
}

FJMDoorResult UJMDoorComponent::OpenDoor(const FJMDoorUseContext& Context)
{
    if (IsDualPanelSlidingDoor())
    {
        return OpenSlideDoor(ResolveSlideDoorPanel(Context), Context);
    }

    if (bLocked)
    {
        FJMDoorResult AccessResult;
        if (!ResolveAccess(Context, true, AccessResult))
        {
            PlayConfiguredSound(GetEffectiveConfig()->LockedSound);
            OnAccessDenied.Broadcast(Context, AccessResult);
            return AccessResult;
        }
        bLocked = false;
    }

    OpenDirectionSign = ResolveOpenDirection(Context);
    bReversingFromObstruction = false;
    return BeginMovement(FMath::Clamp(Context.RequestedOpenFraction, 0.01f, 1.0f), Context);
}

FJMDoorResult UJMDoorComponent::CloseDoor(const FJMDoorUseContext& Context)
{
    if (IsDualPanelSlidingDoor())
    {
        return CloseSlideDoor(EJMSlideDoorPanel::Both, Context);
    }

    bReversingFromObstruction = false;
    return BeginMovement(0.0f, Context);
}

FJMDoorResult UJMDoorComponent::ToggleDoor(const FJMDoorUseContext& Context)
{
    if (IsDualPanelSlidingDoor())
    {
        const bool bAnyOpenOrOpening = SlideDoorA.OpenFraction > KINDA_SMALL_NUMBER || SlideDoorB.OpenFraction > KINDA_SMALL_NUMBER ||
            SlideDoorA.State == EJMDoorState::Opening || SlideDoorB.State == EJMDoorState::Opening;
        return bAnyOpenOrOpening ? CloseSlideDoor(EJMSlideDoorPanel::Both, Context) : OpenSlideDoor(ResolveSlideDoorPanel(Context), Context);
    }
    return (CurrentOpenFraction > 0.5f || CurrentState == EJMDoorState::Opening) ? CloseDoor(Context) : OpenDoor(Context);
}

FJMDoorResult UJMDoorComponent::OpenSlideDoor(EJMSlideDoorPanel Panel, const FJMDoorUseContext& Context)
{
    if (!IsDualPanelSlidingDoor())
    {
        if (Panel == EJMSlideDoorPanel::DoorB)
        {
            return FJMDoorResult::Failure(EJMDoorResultCode::MissingMovementComponent, NSLOCTEXT("JMDoor", "LegacySlideHasNoPanelB", "This legacy sliding door has no panel B."));
        }
        return OpenDoor(Context);
    }

    if (bLocked)
    {
        FJMDoorResult AccessResult;
        if (!ResolveAccess(Context, true, AccessResult))
        {
            PlayConfiguredSound(GetEffectiveConfig()->LockedSound);
            OnAccessDenied.Broadcast(Context, AccessResult);
            return AccessResult;
        }
        bLocked = false;
    }

    return BeginSlidePanelMovement(Panel, 1.0f, Context);
}

FJMDoorResult UJMDoorComponent::CloseSlideDoor(EJMSlideDoorPanel Panel, const FJMDoorUseContext& Context)
{
    if (!IsDualPanelSlidingDoor())
    {
        if (Panel == EJMSlideDoorPanel::DoorB)
        {
            return FJMDoorResult::Failure(EJMDoorResultCode::MissingMovementComponent, NSLOCTEXT("JMDoor", "LegacySlideHasNoPanelB", "This legacy sliding door has no panel B."));
        }
        return CloseDoor(Context);
    }
    return BeginSlidePanelMovement(Panel, 0.0f, Context);
}

EJMDoorState UJMDoorComponent::GetSlideDoorPanelState(EJMSlideDoorPanel Panel) const
{
    if (Panel == EJMSlideDoorPanel::DoorA) return SlideDoorA.State;
    if (Panel == EJMSlideDoorPanel::DoorB) return SlideDoorB.State;
    return CurrentState;
}

float UJMDoorComponent::GetSlideDoorPanelOpenFraction(EJMSlideDoorPanel Panel) const
{
    if (Panel == EJMSlideDoorPanel::DoorA) return SlideDoorA.OpenFraction;
    if (Panel == EJMSlideDoorPanel::DoorB) return SlideDoorB.OpenFraction;
    return FMath::Max(SlideDoorA.OpenFraction, SlideDoorB.OpenFraction);
}

FJMDoorResult UJMDoorComponent::LockDoor()
{
    if (bLockBroken || CurrentState == EJMDoorState::Broken)
    {
        return FJMDoorResult::Failure(EJMDoorResultCode::Broken, NSLOCTEXT("JMDoor", "LockBroken", "The lock is broken."));
    }
    if (CurrentOpenFraction > KINDA_SMALL_NUMBER)
    {
        return FJMDoorResult::Failure(EJMDoorResultCode::InvalidRequest, NSLOCTEXT("JMDoor", "CloseBeforeLock", "Close the door before locking it."));
    }
    bLocked = true;
    SetState(EJMDoorState::Locked);
    return FJMDoorResult::Success();
}

FJMDoorResult UJMDoorComponent::UnlockDoor(const FJMDoorUseContext& Context)
{
    if (!bLocked)
    {
        return FJMDoorResult::Success();
    }
    FJMDoorResult AccessResult;
    if (!ResolveAccess(Context, true, AccessResult))
    {
        OnAccessDenied.Broadcast(Context, AccessResult);
        return AccessResult;
    }
    bLocked = false;
    SetState(EJMDoorState::Closed, Context.InstigatorActor);
    return FJMDoorResult::Success();
}

FJMDoorResult UJMDoorComponent::ForceOpenDoor(float ForceDamage, const FJMDoorUseContext& Context)
{
    if (CurrentState == EJMDoorState::Broken)
    {
        return FJMDoorResult::Failure(EJMDoorResultCode::Broken, NSLOCTEXT("JMDoor", "DoorAlreadyBroken", "The door is already broken."));
    }

    if (bLocked && !bLockBroken)
    {
        ApplyLockDamage(ForceDamage, Context.InstigatorActor);
        if (bLocked)
        {
            return FJMDoorResult::Failure(EJMDoorResultCode::Locked, NSLOCTEXT("JMDoor", "ForceInsufficient", "The lock resisted the force."));
        }
    }
    return OpenDoor(Context);
}

void UJMDoorComponent::ApplyDoorDamage(float Damage, AActor* DamageInstigator)
{
    if (!GetEffectiveConfig()->bBreakable || Damage <= 0.0f || CurrentState == EJMDoorState::Broken)
    {
        return;
    }
    DoorDurability = FMath::Max(0.0f, DoorDurability - Damage);
    OnDurabilityChanged.Broadcast(DoorDurability, LockDurability, bLockBroken);
    if (DoorDurability <= KINDA_SMALL_NUMBER)
    {
        BreakDoor(DamageInstigator);
    }
}

void UJMDoorComponent::ApplyLockDamage(float Damage, AActor* DamageInstigator)
{
    if (!GetEffectiveConfig()->bLockBreakable || Damage <= 0.0f || bLockBroken)
    {
        return;
    }
    LockDurability = FMath::Max(0.0f, LockDurability - Damage);
    if (LockDurability <= KINDA_SMALL_NUMBER)
    {
        bLockBroken = true;
        bLocked = false;
        SetState(CurrentOpenFraction <= KINDA_SMALL_NUMBER ? EJMDoorState::Closed : EJMDoorState::Open, DamageInstigator);
    }
    OnDurabilityChanged.Broadcast(DoorDurability, LockDurability, bLockBroken);
}

FJMDoorResult UJMDoorComponent::RetryBlockedMovement()
{
    if (IsDualPanelSlidingDoor())
    {
        bool bRetried = false;
        if (SlideDoorA.State == EJMDoorState::Blocked)
        {
            bRetried |= BeginSingleSlidePanelMovement(EJMSlideDoorPanel::DoorA, SlideDoorA.TargetFraction, SlideDoorA.Context).bSucceeded;
        }
        if (SlideDoorB.State == EJMDoorState::Blocked)
        {
            bRetried |= BeginSingleSlidePanelMovement(EJMSlideDoorPanel::DoorB, SlideDoorB.TargetFraction, SlideDoorB.Context).bSucceeded;
        }
        if (bRetried)
        {
            UpdateSlideDoorAggregateState();
            SetComponentTickEnabled(true);
            return FJMDoorResult::Success();
        }
    }
    if (CurrentState != EJMDoorState::Blocked)
    {
        return FJMDoorResult::Failure(EJMDoorResultCode::InvalidRequest, NSLOCTEXT("JMDoor", "NotBlocked", "The door is not blocked."));
    }
    bReversingFromObstruction = false;
    return BeginMovement(TargetOpenFraction, ActiveContext);
}

void UJMDoorComponent::SetMovementComponent(UJMDoorMovementComponent* InMovementComponent)
{
    MovementComponent = InMovementComponent;
}

FJMDoorSaveData UJMDoorComponent::CaptureSaveData() const
{
    FJMDoorSaveData Data;
    Data.PersistentId = PersistentId;
    Data.State = CurrentState;
    Data.bLocked = bLocked;
    Data.bLockBroken = bLockBroken;
    Data.OpenFraction = CurrentOpenFraction;
    Data.DoorDurability = DoorDurability;
    Data.LockDurability = LockDurability;
    if (IsDualPanelSlidingDoor())
    {
        Data.SlideDoorAOpenFraction = SlideDoorA.OpenFraction;
        Data.SlideDoorBOpenFraction = SlideDoorB.OpenFraction;
        Data.SlideDoorAState = SlideDoorA.State;
        Data.SlideDoorBState = SlideDoorB.State;
    }
    return Data;
}

bool UJMDoorComponent::RestoreSaveData(const FJMDoorSaveData& SaveData)
{
    if ((SaveData.Version != 1 && SaveData.Version != 2) || (SaveData.PersistentId.IsValid() && SaveData.PersistentId != PersistentId))
    {
        UE_LOG(LogJMDoor, Warning, TEXT("Rejected incompatible save data for '%s'."), *GetNameSafe(GetOwner()));
        return false;
    }

    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(RetryTimerHandle);
        World->GetTimerManager().ClearTimer(AutoCloseTimerHandle);
        World->GetTimerManager().ClearTimer(SlideDoorAAutoCloseTimerHandle);
        World->GetTimerManager().ClearTimer(SlideDoorBAutoCloseTimerHandle);
        World->GetTimerManager().ClearTimer(SlideDoorARetryTimerHandle);
        World->GetTimerManager().ClearTimer(SlideDoorBRetryTimerHandle);
    }
    SetComponentTickEnabled(false);
    bLocked = SaveData.bLocked;
    bLockBroken = SaveData.bLockBroken;
    DoorDurability = FMath::Max(0.0f, SaveData.DoorDurability);
    LockDurability = FMath::Max(0.0f, SaveData.LockDurability);
    CurrentOpenFraction = FMath::Clamp(SaveData.OpenFraction, 0.0f, 1.0f);
    TargetOpenFraction = CurrentOpenFraction;
    CurrentState = SaveData.State;
    if (UJMSlidingDoorMovementComponent* Sliding = Cast<UJMSlidingDoorMovementComponent>(MovementComponent); Sliding && IsDualPanelSlidingDoor())
    {
        SlideDoorA.OpenFraction = FMath::Clamp(SaveData.Version >= 2 ? SaveData.SlideDoorAOpenFraction : SaveData.OpenFraction, 0.0f, 1.0f);
        SlideDoorB.OpenFraction = FMath::Clamp(SaveData.Version >= 2 ? SaveData.SlideDoorBOpenFraction : 0.0f, 0.0f, 1.0f);
        SlideDoorA.TargetFraction = SlideDoorA.OpenFraction;
        SlideDoorB.TargetFraction = SlideDoorB.OpenFraction;
        SlideDoorA.State = SlideDoorA.OpenFraction > KINDA_SMALL_NUMBER ? EJMDoorState::Open : EJMDoorState::Closed;
        SlideDoorB.State = SlideDoorB.OpenFraction > KINDA_SMALL_NUMBER ? EJMDoorState::Open : EJMDoorState::Closed;
        const float EasedA = GetEffectiveConfig()->MovementCurve ? GetEffectiveConfig()->MovementCurve->GetFloatValue(SlideDoorA.OpenFraction) : SlideDoorA.OpenFraction;
        const float EasedB = GetEffectiveConfig()->MovementCurve ? GetEffectiveConfig()->MovementCurve->GetFloatValue(SlideDoorB.OpenFraction) : SlideDoorB.OpenFraction;
        Sliding->SetPanelOpenFraction(EJMSlideDoorPanel::DoorA, EasedA);
        Sliding->SetPanelOpenFraction(EJMSlideDoorPanel::DoorB, EasedB);
        UpdateSlideDoorAggregateState();
    }
    else if (MovementComponent)
    {
        MovementComponent->SetOpenFraction(CurrentOpenFraction, OpenDirectionSign);
    }
    OnDurabilityChanged.Broadcast(DoorDurability, LockDurability, bLockBroken);
    return true;
}

bool UJMDoorComponent::ValidateConfiguration(TArray<FText>& OutErrors) const
{
    OutErrors.Reset();
    if (!MovementComponent)
    {
        OutErrors.Add(NSLOCTEXT("JMDoor", "ValidationMovement", "A door movement component is required."));
    }
    if (const UJMDoorConfigData* Effective = GetEffectiveConfig())
    {
        if (Effective->OpenDuration <= 0.0f || Effective->CloseDuration <= 0.0f)
        {
            OutErrors.Add(NSLOCTEXT("JMDoor", "ValidationDuration", "Open and close durations must be greater than zero."));
        }
        if (Effective->MaxDoorDurability < 0.0f || Effective->MaxLockDurability < 0.0f)
        {
            OutErrors.Add(NSLOCTEXT("JMDoor", "ValidationDurability", "Durability cannot be negative."));
        }
    }
    return OutErrors.IsEmpty();
}

FJMDoorResult UJMDoorComponent::BeginMovement(float TargetFraction, const FJMDoorUseContext& Context)
{
    if (CurrentState == EJMDoorState::Broken)
    {
        return FJMDoorResult::Failure(EJMDoorResultCode::Broken, NSLOCTEXT("JMDoor", "CannotMoveBroken", "A broken door cannot move."));
    }
    if (CurrentState == EJMDoorState::Jammed)
    {
        return FJMDoorResult::Failure(EJMDoorResultCode::Jammed, NSLOCTEXT("JMDoor", "CannotMoveJammed", "The door is jammed."));
    }
    if (!MovementComponent || !MovementComponent->GetMovingComponent())
    {
        return FJMDoorResult::Failure(EJMDoorResultCode::MissingMovementComponent, NSLOCTEXT("JMDoor", "MissingMovement", "The door has no configured moving component."));
    }

    TargetFraction = FMath::Clamp(TargetFraction, 0.0f, 1.0f);
    if (FMath::IsNearlyEqual(TargetFraction, CurrentOpenFraction, KINDA_SMALL_NUMBER))
    {
        return FJMDoorResult::Failure(EJMDoorResultCode::AlreadyAtTarget, NSLOCTEXT("JMDoor", "AlreadyAtTarget", "The door is already at the requested position."));
    }

    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(RetryTimerHandle);
        World->GetTimerManager().ClearTimer(AutoCloseTimerHandle);
    }

    // A Retry resumes the same interrupted motion and must not replay its cue.
    // An obstruction Reverse starts a real motion in the opposite direction and
    // should play the corresponding cue immediately.
    const bool bResumingAfterRetry = CurrentState == EJMDoorState::Blocked && !bReversingFromObstruction;

    TargetOpenFraction = TargetFraction;
    ActiveContext = Context;
    bActiveQuiet = Context.bQuiet;
    const bool bOpening = TargetOpenFraction > CurrentOpenFraction;
    float SpeedMultiplier = Context.bFast ? GetEffectiveConfig()->FastSpeedMultiplier : 1.0f;
    if (Context.bQuiet)
    {
        SpeedMultiplier *= GetEffectiveConfig()->QuietSpeedMultiplier;
    }
    ActiveMoveDuration = (bOpening ? GetEffectiveConfig()->OpenDuration : GetEffectiveConfig()->CloseDuration) / FMath::Max(SpeedMultiplier, 0.01f);
    SetState(bOpening ? EJMDoorState::Opening : EJMDoorState::Closing);
    if (!bResumingAfterRetry)
    {
        if (bOpening)
        {
            PlayConfiguredSound(GetEffectiveConfig()->OpenSound);
            EmitNoise(GetEffectiveConfig()->OpenNoiseLoudness, GetEffectiveConfig()->OpenNoiseRange, TAG_JMDoor_Noise_Open.GetTag(), ActiveContext);
        }
        else
        {
            PlayConfiguredSound(GetEffectiveConfig()->CloseSound);
            EmitNoise(GetEffectiveConfig()->CloseNoiseLoudness, GetEffectiveConfig()->CloseNoiseRange, TAG_JMDoor_Noise_Close.GetTag(), ActiveContext);
        }
    }
    SetComponentTickEnabled(true);
    return FJMDoorResult::Success();
}

bool UJMDoorComponent::ResolveAccess(const FJMDoorUseContext& Context, bool bConsume, FJMDoorResult& OutResult) const
{
    const UJMDoorConfigData* EffectiveConfig = GetEffectiveConfig();
    const FJMDoorAccessRequirement& Requirement = EffectiveConfig->AccessRequirement;
    if (Requirement.IsEmpty() && EffectiveConfig->AcceptedAccessObjects.IsEmpty())
    {
        OutResult = FJMDoorResult::Failure(EJMDoorResultCode::Locked, NSLOCTEXT("JMDoor", "LockedNoRequirement", "The door is locked and has no configured access requirement."));
        return false;
    }

    AActor* Provider = Context.InstigatorActor;
    bool bHasAccess = false;
    if (IsValid(Context.AccessObject))
    {
        const FSoftObjectPath AccessObjectPath(Context.AccessObject);
        bHasAccess = EffectiveConfig->AcceptedAccessObjects.ContainsByPredicate([&AccessObjectPath](const TSoftObjectPtr<UObject>& AcceptedObject)
        {
            return !AcceptedObject.IsNull() && AcceptedObject.ToSoftObjectPath() == AccessObjectPath;
        });
    }
    if (!bHasAccess && !Requirement.IsEmpty())
    {
        bHasAccess = Requirement.IsSatisfiedBy(Context.AccessTags);
    }
    if (!bHasAccess && IsValid(Provider) && Provider->GetClass()->ImplementsInterface(UJMDoorAccessProviderInterface::StaticClass()))
    {
        const FGameplayTagContainer ProviderTags = JMDoorInterfaceDispatch::GetAccessTags(Provider);
        bHasAccess = Requirement.IsSatisfiedBy(ProviderTags) || JMDoorInterfaceDispatch::CanProvideAccess(Provider, Requirement);
    }
    if (!bHasAccess)
    {
        OutResult = FJMDoorResult::Failure(EJMDoorResultCode::AccessDenied, NSLOCTEXT("JMDoor", "AccessDenied", "Access was denied."));
        return false;
    }

    if (bConsume && Requirement.bConsumeAccess)
    {
        if (!IsValid(Provider) || !Provider->GetClass()->ImplementsInterface(UJMDoorAccessProviderInterface::StaticClass()) ||
            !JMDoorInterfaceDispatch::ConsumeAccess(Provider, Requirement))
        {
            OutResult = FJMDoorResult::Failure(EJMDoorResultCode::AccessDenied, NSLOCTEXT("JMDoor", "ConsumeFailed", "The required access item could not be consumed."));
            return false;
        }
    }

    OutResult = FJMDoorResult::Success();
    return true;
}

int32 UJMDoorComponent::ResolveOpenDirection(const FJMDoorUseContext& Context) const
{
    const EJMDoorOpenDirectionMode Mode = GetEffectiveConfig()->OpenDirectionMode;
    if (Mode == EJMDoorOpenDirectionMode::Positive) return 1;
    if (Mode == EJMDoorOpenDirectionMode::Negative) return -1;

    if (!MovementComponent) return 1;

    FVector InteractorLocation = Context.InteractionLocation;
    if (InteractorLocation.IsNearlyZero() && IsValid(Context.InstigatorActor))
    {
        InteractorLocation = Context.InstigatorActor->GetActorLocation();
    }
    const FVector ClosedProbe = MovementComponent->GetDirectionProbeWorldLocationAtFraction(0.0f, 1);
    const FVector PositiveProbe = MovementComponent->GetDirectionProbeWorldLocationAtFraction(1.0f, 1);
    const FVector NegativeProbe = MovementComponent->GetDirectionProbeWorldLocationAtFraction(1.0f, -1);
    const FVector DoorSideAxis = (PositiveProbe - NegativeProbe).GetSafeNormal();
    const double PlayerSide = FVector::DotProduct(InteractorLocation - ClosedProbe, DoorSideAxis);
    const double PositiveDistanceSq = FVector::DistSquared(PositiveProbe, InteractorLocation);
    const double NegativeDistanceSq = FVector::DistSquared(NegativeProbe, InteractorLocation);

    int32 AwaySign = 1;
    if (!DoorSideAxis.IsNearlyZero() && !FMath::IsNearlyZero(PlayerSide, 0.1))
    {
        // PositiveProbe defines the positive half-space of the closed door plane.
        // Always select the candidate in the half-space opposite the player.
        AwaySign = PlayerSide > 0.0 ? -1 : 1;
    }
    else if (!FMath::IsNearlyEqual(PositiveDistanceSq, NegativeDistanceSq, 1.0))
    {
        AwaySign = PositiveDistanceSq > NegativeDistanceSq ? 1 : -1;
    }
    UE_LOG(LogJMDoor, Verbose, TEXT("Open direction resolved: door=%s mode=%d sign=%d player=%s closed=%s playerSide=%.3f"), *GetNameSafe(GetOwner()), static_cast<int32>(Mode), AwaySign, *InteractorLocation.ToCompactString(), *ClosedProbe.ToCompactString(), PlayerSide);
    return Mode == EJMDoorOpenDirectionMode::AwayFromInteractor ? AwaySign : -AwaySign;
}

bool UJMDoorComponent::IsObstructed(float ProposedFraction, AActor*& OutBlockingActor) const
{
    OutBlockingActor = nullptr;
    if (!MovementComponent || !MovementComponent->GetMovingComponent() || !GetWorld())
    {
        return false;
    }

    UPrimitiveComponent* Primitive = MovementComponent->GetCollisionComponent();
    if (!Primitive || Primitive->GetCollisionEnabled() == ECollisionEnabled::NoCollision)
    {
        return false;
    }

    const float EasedFraction = GetEffectiveConfig()->MovementCurve
        ? GetEffectiveConfig()->MovementCurve->GetFloatValue(ProposedFraction)
        : ProposedFraction;
    const FTransform ProposedTransform = MovementComponent->GetCollisionWorldTransformAtFraction(EasedFraction, OpenDirectionSign);
    return IsGeometryObstructed(Primitive, ProposedTransform, OutBlockingActor);
}

bool UJMDoorComponent::IsGeometryObstructed(UPrimitiveComponent* Primitive, const FTransform& ProposedTransform, AActor*& OutBlockingActor) const
{
    OutBlockingActor = nullptr;
    if (!Primitive || Primitive->GetCollisionEnabled() == ECollisionEnabled::NoCollision || !GetWorld())
    {
        return false;
    }

    const FVector Extent = Primitive->Bounds.BoxExtent.ComponentMax(FVector(2.0f));
    FComponentQueryParams Params(SCENE_QUERY_STAT(JMDoorObstruction), GetOwner());
    TArray<FOverlapResult> Overlaps;
    const bool bOverlap = GetWorld()->ComponentOverlapMulti(
        Overlaps,
        Primitive,
        ProposedTransform.GetLocation(),
        ProposedTransform.GetRotation(),
        Params);

    if (GetDefault<UJMDoorSettings>()->bDrawObstructionDebug)
    {
        DrawDebugBox(GetWorld(), ProposedTransform.GetLocation(), Extent * 0.9f, ProposedTransform.GetRotation(), bOverlap ? FColor::Red : FColor::Green, false, 0.1f);
    }

    for (const FOverlapResult& Overlap : Overlaps)
    {
        if (AActor* Actor = Overlap.GetActor())
        {
            if (Actor != GetOwner() && Overlap.bBlockingHit)
            {
                if (ACharacter* Character = Cast<ACharacter>(Actor))
                {
                    if (CharactersClearedForProposedPose.Contains(TWeakObjectPtr<ACharacter>(Character)))
                    {
                        continue;
                    }
                }
                OutBlockingActor = Actor;
                return true;
            }
        }
    }
    return false;
}

void UJMDoorComponent::PushCharactersAlongSweptPath(float CurrentEasedFraction, float ProposedEasedFraction)
{
    CharactersClearedForProposedPose.Reset();

    const UJMDoorConfigData* EffectiveConfig = GetEffectiveConfig();
    UWorld* World = GetWorld();
    if (!EffectiveConfig->bPushCharacters || !MovementComponent || !World)
    {
        return;
    }

    UPrimitiveComponent* Primitive = MovementComponent->GetCollisionComponent();
    if (!Primitive || Primitive->GetCollisionEnabled() == ECollisionEnabled::NoCollision)
    {
        return;
    }

    const FTransform FrameStart = MovementComponent->GetCollisionWorldTransformAtFraction(CurrentEasedFraction, OpenDirectionSign);
    const FTransform FrameEnd = MovementComponent->GetCollisionWorldTransformAtFraction(ProposedEasedFraction, OpenDirectionSign);
    PushCharactersAlongSweptGeometry(Primitive, FrameStart, FrameEnd);
}

void UJMDoorComponent::PushCharactersAlongSweptGeometry(UPrimitiveComponent* Primitive, const FTransform& FrameStart, const FTransform& FrameEnd)
{
    CharactersClearedForProposedPose.Reset();

    const UJMDoorConfigData* EffectiveConfig = GetEffectiveConfig();
    UWorld* World = GetWorld();
    if (!EffectiveConfig->bPushCharacters || !Primitive || Primitive->GetCollisionEnabled() == ECollisionEnabled::NoCollision || !World)
    {
        return;
    }

    const float FrameTranslation = FVector::Distance(FrameStart.GetLocation(), FrameEnd.GetLocation());
    const float FrameAngleDegrees = FMath::RadiansToDegrees(FrameStart.GetRotation().AngularDistance(FrameEnd.GetRotation()));
    const int32 TranslationSteps = FMath::CeilToInt(FrameTranslation / FMath::Max(EffectiveConfig->CharacterPushMaxSubstepDistance, 0.1f));
    const int32 RotationSteps = FMath::CeilToInt(FrameAngleDegrees / FMath::Max(EffectiveConfig->CharacterPushMaxSubstepAngle, 0.1f));
    const int32 SubstepCount = FMath::Clamp(
        FMath::Max3(1, TranslationSteps, RotationSteps),
        1,
        FMath::Max(1, EffectiveConfig->CharacterPushMaxSubsteps));
    const UJMDoorSettings* Settings = GetDefault<UJMDoorSettings>();

    if (Settings->bLogCharacterPushDebug)
    {
        UE_LOG(LogJMDoor, Log,
            TEXT("KinematicPush frame=%llu door=%s leafDelta=%s angle=%.3f substeps=%d"),
            GFrameCounter,
            *GetNameSafe(GetOwner()),
            *(FrameEnd.GetLocation() - FrameStart.GetLocation()).ToCompactString(),
            FrameAngleDegrees,
            SubstepCount);
    }
    if (Settings->bDrawCharacterPushDebug)
    {
        DrawDebugDirectionalArrow(World, FrameStart.GetLocation(), FrameEnd.GetLocation(), 12.0f, FColor::Yellow, false, Settings->CharacterPushDebugDuration, 0, 1.5f);
    }

    auto InterpolatePose = [](const FTransform& Start, const FTransform& End, float Alpha)
    {
        FTransform Result;
        Result.SetLocation(FMath::Lerp(Start.GetLocation(), End.GetLocation(), Alpha));
        Result.SetRotation(FQuat::Slerp(Start.GetRotation(), End.GetRotation(), Alpha).GetNormalized());
        Result.SetScale3D(FMath::Lerp(Start.GetScale3D(), End.GetScale3D(), Alpha));
        return Result;
    };

    FComponentQueryParams QueryParams(SCENE_QUERY_STAT(JMDoorCharacterPush), GetOwner());
    for (int32 StepIndex = 0; StepIndex < SubstepCount; ++StepIndex)
    {
        const float StartAlpha = static_cast<float>(StepIndex) / static_cast<float>(SubstepCount);
        const float EndAlpha = static_cast<float>(StepIndex + 1) / static_cast<float>(SubstepCount);
        const FTransform StepStart = InterpolatePose(FrameStart, FrameEnd, StartAlpha);
        const FTransform StepEnd = InterpolatePose(FrameStart, FrameEnd, EndAlpha);

        // ComponentSweep uses the real leaf collision geometry. Rotation is
        // approximated by short angular substeps, while translation is swept
        // continuously across each substep. Characters are moved before the
        // leaf transform is committed, so this is predictive rather than a
        // post-penetration correction.
        TArray<FHitResult> ContactHits;
        World->ComponentSweepMulti(
            ContactHits,
            Primitive,
            StepStart.GetLocation(),
            StepEnd.GetLocation(),
            StepEnd.GetRotation(),
            QueryParams);

        TMap<ACharacter*, FHitResult> EarliestCharacterHits;
        for (const FHitResult& ContactHit : ContactHits)
        {
            ACharacter* Character = Cast<ACharacter>(ContactHit.GetActor());
            if (!IsValid(Character) || !ContactHit.bBlockingHit)
            {
                continue;
            }

            FHitResult* ExistingHit = EarliestCharacterHits.Find(Character);
            if (!ExistingHit || ContactHit.Time < ExistingHit->Time)
            {
                EarliestCharacterHits.Add(Character, ContactHit);
            }
        }

        for (const TPair<ACharacter*, FHitResult>& Pair : EarliestCharacterHits)
        {
            ACharacter* Character = Pair.Key;
            const FHitResult& ContactHit = Pair.Value;
            UCharacterMovementComponent* CharacterMovement = Character->GetCharacterMovement();
            UPrimitiveComponent* UpdatedPrimitive = CharacterMovement
                ? Cast<UPrimitiveComponent>(CharacterMovement->UpdatedComponent)
                : nullptr;
            if (!CharacterMovement || !UpdatedPrimitive)
            {
                continue;
            }

            const float ContactAlpha = FMath::Clamp(ContactHit.Time, 0.0f, 1.0f);
            const FTransform ContactPose = InterpolatePose(StepStart, StepEnd, ContactAlpha);
            FVector ContactPoint = ContactHit.ImpactPoint;
            if (ContactHit.bStartPenetrating || ContactPoint.ContainsNaN())
            {
                ContactPoint = Character->GetActorLocation();
            }

            // Transforming the contact point from the contact pose into the
            // substep end pose yields the rigid-body surface displacement.
            // For a hinge this is tangent motion with |delta| ~= angle*radius;
            // for a sliding leaf it is exactly the leaf translation delta.
            const FVector LocalContact = ContactPose.InverseTransformPosition(ContactPoint);
            FVector PushDelta = StepEnd.TransformPosition(LocalContact) - ContactPoint;
            if (PushDelta.IsNearlyZero())
            {
                PushDelta = (StepEnd.GetLocation() - StepStart.GetLocation()) * (1.0f - ContactAlpha);
            }
            if (PushDelta.IsNearlyZero())
            {
                continue;
            }

            AActor* DoorOwner = GetOwner();
            const bool bAlreadyIgnoringDoor = DoorOwner && UpdatedPrimitive->GetMoveIgnoreActors().Contains(DoorOwner);
            if (DoorOwner && !bAlreadyIgnoringDoor)
            {
                UpdatedPrimitive->IgnoreActorWhenMoving(DoorOwner, true);
            }

            const FVector CharacterStart = UpdatedPrimitive->GetComponentLocation();
            FHitResult MovementHit;
            CharacterMovement->SafeMoveUpdatedComponent(
                PushDelta,
                UpdatedPrimitive->GetComponentQuat(),
                true,
                MovementHit,
                ETeleportType::None);
            if (MovementHit.IsValidBlockingHit() && MovementHit.Time < 1.0f)
            {
                static_cast<UMovementComponent*>(CharacterMovement)->SlideAlongSurface(
                    PushDelta,
                    1.0f - MovementHit.Time,
                    MovementHit.Normal,
                    MovementHit,
                    true);
            }
            const FVector ActualMovement = UpdatedPrimitive->GetComponentLocation() - CharacterStart;

            if (DoorOwner && !bAlreadyIgnoringDoor)
            {
                UpdatedPrimitive->IgnoreActorWhenMoving(DoorOwner, false);
            }

            const float RequestedProgress = PushDelta.Size();
            const float ActualProgress = FVector::DotProduct(ActualMovement, PushDelta.GetSafeNormal());
            const TWeakObjectPtr<ACharacter> CharacterKey(Character);
            if (ActualProgress + 0.1f >= RequestedProgress)
            {
                CharactersClearedForProposedPose.Add(CharacterKey);
            }
            else
            {
                CharactersClearedForProposedPose.Remove(CharacterKey);
            }

            if (Settings->bLogCharacterPushDebug)
            {
                UE_LOG(LogJMDoor, Log,
                    TEXT("KinematicPush frame=%llu door=%s character=%s step=%d/%d contactTime=%.3f leafDelta=%s push=%s actual=%s moveHit=%s hitActor=%s hitNormal=%s"),
                    GFrameCounter,
                    *GetNameSafe(GetOwner()),
                    *GetNameSafe(Character),
                    StepIndex + 1,
                    SubstepCount,
                    ContactAlpha,
                    *(StepEnd.GetLocation() - StepStart.GetLocation()).ToCompactString(),
                    *PushDelta.ToCompactString(),
                    *ActualMovement.ToCompactString(),
                    MovementHit.IsValidBlockingHit() ? TEXT("true") : TEXT("false"),
                    *GetNameSafe(MovementHit.GetActor()),
                    *MovementHit.Normal.ToCompactString());
            }
            if (Settings->bDrawCharacterPushDebug)
            {
                DrawDebugSphere(World, ContactPoint, 4.0f, 8, FColor::Orange, false, Settings->CharacterPushDebugDuration);
                DrawDebugDirectionalArrow(World, CharacterStart, CharacterStart + PushDelta, 8.0f, FColor::Cyan, false, Settings->CharacterPushDebugDuration, 0, 2.0f);
                DrawDebugDirectionalArrow(World, CharacterStart, CharacterStart + ActualMovement, 8.0f, FColor::Green, false, Settings->CharacterPushDebugDuration, 0, 2.0f);
                if (MovementHit.IsValidBlockingHit())
                {
                    DrawDebugDirectionalArrow(World, MovementHit.ImpactPoint, MovementHit.ImpactPoint + MovementHit.Normal * 30.0f, 8.0f, FColor::Red, false, Settings->CharacterPushDebugDuration, 0, 2.0f);
                }
            }
        }
    }
}

bool UJMDoorComponent::IsDualPanelSlidingDoor() const
{
    const UJMSlidingDoorMovementComponent* Sliding = Cast<UJMSlidingDoorMovementComponent>(MovementComponent);
    return Sliding && !Sliding->IsLegacySinglePanelAsset() &&
        Sliding->HasPanel(EJMSlideDoorPanel::DoorA) && Sliding->HasPanel(EJMSlideDoorPanel::DoorB);
}

EJMSlideDoorPanel UJMDoorComponent::ResolveSlideDoorPanel(const FJMDoorUseContext& Context) const
{
    const UJMDoorConfigData* EffectiveConfig = GetEffectiveConfig();
    if (EffectiveConfig->SlideDoorPanelSelectionMode == EJMSlideDoorPanelSelectionMode::ConfiguredPanel)
    {
        switch (EffectiveConfig->SlideDoorOpenMode)
        {
        case EJMSlideDoorOpenMode::OpenDoorB: return EJMSlideDoorPanel::DoorB;
        case EJMSlideDoorOpenMode::OpenBoth: return EJMSlideDoorPanel::Both;
        default: return EJMSlideDoorPanel::DoorA;
        }
    }

    const UJMSlidingDoorMovementComponent* Sliding = Cast<UJMSlidingDoorMovementComponent>(MovementComponent);
    if (!Sliding || !Sliding->HasPanel(EJMSlideDoorPanel::DoorB))
    {
        return EJMSlideDoorPanel::DoorA;
    }

    FVector InteractionLocation = Context.InteractionLocation;
    if (InteractionLocation.IsNearlyZero() && IsValid(Context.InstigatorActor))
    {
        InteractionLocation = Context.InstigatorActor->GetActorLocation();
    }
    const FVector PanelALocation = Sliding->GetPanelWorldTransformAtFraction(EJMSlideDoorPanel::DoorA, SlideDoorA.OpenFraction).GetLocation();
    const FVector PanelBLocation = Sliding->GetPanelWorldTransformAtFraction(EJMSlideDoorPanel::DoorB, SlideDoorB.OpenFraction).GetLocation();
    return FVector::DistSquared(InteractionLocation, PanelALocation) <= FVector::DistSquared(InteractionLocation, PanelBLocation)
        ? EJMSlideDoorPanel::DoorA
        : EJMSlideDoorPanel::DoorB;
}

FJMDoorResult UJMDoorComponent::BeginSlidePanelMovement(EJMSlideDoorPanel Panel, float TargetFraction, const FJMDoorUseContext& Context)
{
    if (CurrentState == EJMDoorState::Broken)
    {
        return FJMDoorResult::Failure(EJMDoorResultCode::Broken, NSLOCTEXT("JMDoor", "CannotMoveBrokenSlideDoor", "A broken sliding door cannot move."));
    }

    FJMDoorResult ResultA = FJMDoorResult::Failure(EJMDoorResultCode::AlreadyAtTarget, FText::GetEmpty());
    FJMDoorResult ResultB = ResultA;
    if (Panel == EJMSlideDoorPanel::DoorA || Panel == EJMSlideDoorPanel::Both)
    {
        ResultA = BeginSingleSlidePanelMovement(EJMSlideDoorPanel::DoorA, TargetFraction, Context);
    }
    if (Panel == EJMSlideDoorPanel::DoorB || Panel == EJMSlideDoorPanel::Both)
    {
        ResultB = BeginSingleSlidePanelMovement(EJMSlideDoorPanel::DoorB, TargetFraction, Context);
    }

    const bool bAnyStarted = ResultA.bSucceeded || ResultB.bSucceeded;
    if (!bAnyStarted)
    {
        return Panel == EJMSlideDoorPanel::DoorB ? ResultB : ResultA;
    }

    ActiveContext = Context;
    bActiveQuiet = Context.bQuiet;
    if (TargetFraction > 0.5f)
    {
        PlayConfiguredSound(GetEffectiveConfig()->OpenSound);
        EmitNoise(GetEffectiveConfig()->OpenNoiseLoudness, GetEffectiveConfig()->OpenNoiseRange, TAG_JMDoor_Noise_Open.GetTag(), Context);
    }
    else
    {
        PlayConfiguredSound(GetEffectiveConfig()->CloseSound);
        EmitNoise(GetEffectiveConfig()->CloseNoiseLoudness, GetEffectiveConfig()->CloseNoiseRange, TAG_JMDoor_Noise_Close.GetTag(), Context);
    }
    UpdateSlideDoorAggregateState();
    SetComponentTickEnabled(true);
    return FJMDoorResult::Success();
}

FJMDoorResult UJMDoorComponent::BeginSingleSlidePanelMovement(EJMSlideDoorPanel Panel, float TargetFraction, const FJMDoorUseContext& Context)
{
    UJMSlidingDoorMovementComponent* Sliding = Cast<UJMSlidingDoorMovementComponent>(MovementComponent);
    if (!Sliding || !Sliding->HasPanel(Panel))
    {
        return FJMDoorResult::Failure(EJMDoorResultCode::MissingMovementComponent, NSLOCTEXT("JMDoor", "MissingSlidePanel", "The requested sliding door panel is not configured."));
    }

    FSlidePanelRuntimeState& Runtime = Panel == EJMSlideDoorPanel::DoorB ? SlideDoorB : SlideDoorA;
    TargetFraction = FMath::Clamp(TargetFraction, 0.0f, 1.0f);
    if (FMath::IsNearlyEqual(Runtime.OpenFraction, TargetFraction, KINDA_SMALL_NUMBER) &&
        Runtime.State != EJMDoorState::Opening && Runtime.State != EJMDoorState::Closing)
    {
        return FJMDoorResult::Failure(EJMDoorResultCode::AlreadyAtTarget, NSLOCTEXT("JMDoor", "SlidePanelAlreadyAtTarget", "The requested sliding door panel is already at the target."));
    }

    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(Panel == EJMSlideDoorPanel::DoorB ? SlideDoorBRetryTimerHandle : SlideDoorARetryTimerHandle);
        World->GetTimerManager().ClearTimer(Panel == EJMSlideDoorPanel::DoorB ? SlideDoorBAutoCloseTimerHandle : SlideDoorAAutoCloseTimerHandle);
    }

    Runtime.TargetFraction = TargetFraction;
    Runtime.Context = Context;
    Runtime.bReversingFromObstruction = false;
    float SpeedMultiplier = Context.bFast ? GetEffectiveConfig()->FastSpeedMultiplier : 1.0f;
    if (Context.bQuiet)
    {
        SpeedMultiplier *= GetEffectiveConfig()->QuietSpeedMultiplier;
    }
    const bool bOpening = TargetFraction > Runtime.OpenFraction;
    Runtime.MoveDuration = (bOpening ? GetEffectiveConfig()->OpenDuration : GetEffectiveConfig()->CloseDuration) / FMath::Max(SpeedMultiplier, 0.01f);
    SetSlidePanelState(Panel, bOpening ? EJMDoorState::Opening : EJMDoorState::Closing);
    return FJMDoorResult::Success();
}

void UJMDoorComponent::TickSlideDoorPanels(float DeltaTime)
{
    UJMSlidingDoorMovementComponent* Sliding = Cast<UJMSlidingDoorMovementComponent>(MovementComponent);
    if (!Sliding)
    {
        SetComponentTickEnabled(false);
        return;
    }

    auto TickPanel = [this, Sliding, DeltaTime](EJMSlideDoorPanel Panel, FSlidePanelRuntimeState& Runtime)
    {
        if (Runtime.State != EJMDoorState::Opening && Runtime.State != EJMDoorState::Closing)
        {
            return;
        }

        const float Direction = Runtime.TargetFraction >= Runtime.OpenFraction ? 1.0f : -1.0f;
        const float ProposedFraction = FMath::Clamp(Runtime.OpenFraction + Direction * DeltaTime / FMath::Max(Runtime.MoveDuration, 0.01f), 0.0f, 1.0f);
        const float CurrentEased = GetEffectiveConfig()->MovementCurve
            ? GetEffectiveConfig()->MovementCurve->GetFloatValue(Runtime.OpenFraction)
            : Runtime.OpenFraction;
        const float ProposedEased = GetEffectiveConfig()->MovementCurve
            ? GetEffectiveConfig()->MovementCurve->GetFloatValue(ProposedFraction)
            : ProposedFraction;
        UPrimitiveComponent* Primitive = Sliding->GetPanelCollisionComponent(Panel);
        const FTransform FrameStart = Sliding->GetPanelCollisionWorldTransformAtFraction(Panel, CurrentEased);
        const FTransform FrameEnd = Sliding->GetPanelCollisionWorldTransformAtFraction(Panel, ProposedEased);
        PushCharactersAlongSweptGeometry(Primitive, FrameStart, FrameEnd);

        AActor* BlockingActor = nullptr;
        if (!Runtime.bReversingFromObstruction && GetEffectiveConfig()->bDetectObstructions &&
            GetEffectiveConfig()->BlockBehavior != EJMDoorBlockBehavior::Ignore &&
            IsGeometryObstructed(Primitive, FrameEnd, BlockingActor))
        {
            HandleSlidePanelObstruction(Panel, BlockingActor);
            return;
        }

        Runtime.OpenFraction = ProposedFraction;
        Sliding->SetPanelOpenFraction(Panel, ProposedEased);
        if (FMath::IsNearlyEqual(Runtime.OpenFraction, Runtime.TargetFraction, KINDA_SMALL_NUMBER))
        {
            Runtime.OpenFraction = Runtime.TargetFraction;
            FinishSlidePanelMovement(Panel);
        }
    };

    TickPanel(EJMSlideDoorPanel::DoorA, SlideDoorA);
    TickPanel(EJMSlideDoorPanel::DoorB, SlideDoorB);
    UpdateSlideDoorAggregateState();

    const bool bAnyMoving = SlideDoorA.State == EJMDoorState::Opening || SlideDoorA.State == EJMDoorState::Closing ||
        SlideDoorB.State == EJMDoorState::Opening || SlideDoorB.State == EJMDoorState::Closing;
    SetComponentTickEnabled(bAnyMoving);
}

void UJMDoorComponent::FinishSlidePanelMovement(EJMSlideDoorPanel Panel)
{
    FSlidePanelRuntimeState& Runtime = Panel == EJMSlideDoorPanel::DoorB ? SlideDoorB : SlideDoorA;
    Runtime.RetryCount = 0;
    Runtime.bReversingFromObstruction = false;
    SetSlidePanelState(Panel, Runtime.TargetFraction <= KINDA_SMALL_NUMBER ? EJMDoorState::Closed : EJMDoorState::Open);

    if (Runtime.State == EJMDoorState::Open && GetEffectiveConfig()->bAutoClose && GetWorld())
    {
        FTimerHandle& Timer = Panel == EJMSlideDoorPanel::DoorB ? SlideDoorBAutoCloseTimerHandle : SlideDoorAAutoCloseTimerHandle;
        FTimerDelegate Delegate = Panel == EJMSlideDoorPanel::DoorB
            ? FTimerDelegate::CreateUObject(this, &UJMDoorComponent::HandleSlideDoorBAutoCloseTimer)
            : FTimerDelegate::CreateUObject(this, &UJMDoorComponent::HandleSlideDoorAAutoCloseTimer);
        GetWorld()->GetTimerManager().SetTimer(Timer, Delegate, GetEffectiveConfig()->AutoCloseDelay, false);
    }
}

void UJMDoorComponent::HandleSlidePanelObstruction(EJMSlideDoorPanel Panel, AActor* BlockingActor)
{
    FSlidePanelRuntimeState& Runtime = Panel == EJMSlideDoorPanel::DoorB ? SlideDoorB : SlideDoorA;
    const EJMDoorBlockBehavior Behavior = GetEffectiveConfig()->BlockBehavior;
    OnDoorObstructed.Broadcast(BlockingActor, Behavior);
    SetSlidePanelState(Panel, EJMDoorState::Blocked);

    if (Behavior == EJMDoorBlockBehavior::Reverse)
    {
        const float ReverseTarget = Runtime.TargetFraction > Runtime.OpenFraction ? 0.0f : 1.0f;
        BeginSingleSlidePanelMovement(Panel, ReverseTarget, Runtime.Context);
        Runtime.bReversingFromObstruction = true;
    }
    else if (Behavior == EJMDoorBlockBehavior::Retry && Runtime.RetryCount < GetEffectiveConfig()->MaxRetryCount)
    {
        ++Runtime.RetryCount;
        if (UWorld* World = GetWorld())
        {
            FTimerHandle& Timer = Panel == EJMSlideDoorPanel::DoorB ? SlideDoorBRetryTimerHandle : SlideDoorARetryTimerHandle;
            FTimerDelegate Delegate = Panel == EJMSlideDoorPanel::DoorB
                ? FTimerDelegate::CreateUObject(this, &UJMDoorComponent::HandleSlideDoorBRetryTimer)
                : FTimerDelegate::CreateUObject(this, &UJMDoorComponent::HandleSlideDoorARetryTimer);
            World->GetTimerManager().SetTimer(Timer, Delegate, GetEffectiveConfig()->RetryDelay, false);
        }
    }
    else if (Behavior == EJMDoorBlockBehavior::Retry)
    {
        SetSlidePanelState(Panel, EJMDoorState::Jammed);
    }
}

void UJMDoorComponent::UpdateSlideDoorAggregateState()
{
    CurrentOpenFraction = FMath::Max(SlideDoorA.OpenFraction, SlideDoorB.OpenFraction);
    TargetOpenFraction = FMath::Max(SlideDoorA.TargetFraction, SlideDoorB.TargetFraction);

    EJMDoorState AggregateState = bLocked && CurrentOpenFraction <= KINDA_SMALL_NUMBER ? EJMDoorState::Locked : EJMDoorState::Closed;
    if (SlideDoorA.State == EJMDoorState::Opening || SlideDoorB.State == EJMDoorState::Opening) AggregateState = EJMDoorState::Opening;
    else if (SlideDoorA.State == EJMDoorState::Closing || SlideDoorB.State == EJMDoorState::Closing) AggregateState = EJMDoorState::Closing;
    else if (SlideDoorA.State == EJMDoorState::Jammed || SlideDoorB.State == EJMDoorState::Jammed) AggregateState = EJMDoorState::Jammed;
    else if (SlideDoorA.State == EJMDoorState::Blocked || SlideDoorB.State == EJMDoorState::Blocked) AggregateState = EJMDoorState::Blocked;
    else if (SlideDoorA.OpenFraction > KINDA_SMALL_NUMBER || SlideDoorB.OpenFraction > KINDA_SMALL_NUMBER) AggregateState = EJMDoorState::Open;
    SetState(AggregateState);
}

void UJMDoorComponent::SetSlidePanelState(EJMSlideDoorPanel Panel, EJMDoorState NewState)
{
    FSlidePanelRuntimeState& Runtime = Panel == EJMSlideDoorPanel::DoorB ? SlideDoorB : SlideDoorA;
    if (Runtime.State == NewState)
    {
        return;
    }
    const EJMDoorState OldState = Runtime.State;
    Runtime.State = NewState;
    OnSlideDoorPanelStateChanged.Broadcast(Panel, OldState, NewState);
}

void UJMDoorComponent::HandleSlideDoorAAutoCloseTimer()
{
    FJMDoorUseContext Context;
    CloseSlideDoor(EJMSlideDoorPanel::DoorA, Context);
}

void UJMDoorComponent::HandleSlideDoorBAutoCloseTimer()
{
    FJMDoorUseContext Context;
    CloseSlideDoor(EJMSlideDoorPanel::DoorB, Context);
}

void UJMDoorComponent::HandleSlideDoorARetryTimer()
{
    BeginSingleSlidePanelMovement(EJMSlideDoorPanel::DoorA, SlideDoorA.TargetFraction, SlideDoorA.Context);
    UpdateSlideDoorAggregateState();
    SetComponentTickEnabled(true);
}

void UJMDoorComponent::HandleSlideDoorBRetryTimer()
{
    BeginSingleSlidePanelMovement(EJMSlideDoorPanel::DoorB, SlideDoorB.TargetFraction, SlideDoorB.Context);
    UpdateSlideDoorAggregateState();
    SetComponentTickEnabled(true);
}

void UJMDoorComponent::HandleObstruction(AActor* BlockingActor)
{
    SetComponentTickEnabled(false);
    const EJMDoorBlockBehavior Behavior = GetEffectiveConfig()->BlockBehavior;
    OnDoorObstructed.Broadcast(BlockingActor, Behavior);
    SetState(EJMDoorState::Blocked);

    if (Behavior == EJMDoorBlockBehavior::Reverse)
    {
        const float ReverseTarget = TargetOpenFraction > CurrentOpenFraction ? 0.0f : 1.0f;
        bReversingFromObstruction = true;
        BeginMovement(ReverseTarget, ActiveContext);
    }
    else if (Behavior == EJMDoorBlockBehavior::Retry && RetryCount < GetEffectiveConfig()->MaxRetryCount)
    {
        ++RetryCount;
        if (UWorld* World = GetWorld())
        {
            World->GetTimerManager().SetTimer(RetryTimerHandle, this, &UJMDoorComponent::HandleRetryTimer, GetEffectiveConfig()->RetryDelay, false);
        }
    }
    else if (Behavior == EJMDoorBlockBehavior::Retry)
    {
        SetState(EJMDoorState::Jammed);
    }
}

void UJMDoorComponent::HandleRetryTimer()
{
    BeginMovement(TargetOpenFraction, ActiveContext);
}

void UJMDoorComponent::HandleAutoCloseTimer()
{
    FJMDoorUseContext AutoContext;
    CloseDoor(AutoContext);
}

void UJMDoorComponent::FinishMovement()
{
    SetComponentTickEnabled(false);
    RetryCount = 0;
    bReversingFromObstruction = false;
    if (TargetOpenFraction <= KINDA_SMALL_NUMBER)
    {
        SetState(bLocked ? EJMDoorState::Locked : EJMDoorState::Closed);
    }
    else
    {
        SetState(EJMDoorState::Open);
        if (GetEffectiveConfig()->bAutoClose && GetWorld())
        {
            GetWorld()->GetTimerManager().SetTimer(AutoCloseTimerHandle, this, &UJMDoorComponent::HandleAutoCloseTimer, GetEffectiveConfig()->AutoCloseDelay, false);
        }
    }
}

void UJMDoorComponent::BreakDoor(AActor* DamageInstigator)
{
    SetComponentTickEnabled(false);
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(SlideDoorAAutoCloseTimerHandle);
        World->GetTimerManager().ClearTimer(SlideDoorBAutoCloseTimerHandle);
        World->GetTimerManager().ClearTimer(SlideDoorARetryTimerHandle);
        World->GetTimerManager().ClearTimer(SlideDoorBRetryTimerHandle);
    }
    if (IsDualPanelSlidingDoor())
    {
        SetSlidePanelState(EJMSlideDoorPanel::DoorA, EJMDoorState::Broken);
        SetSlidePanelState(EJMSlideDoorPanel::DoorB, EJMDoorState::Broken);
    }
    bLocked = false;
    bLockBroken = true;
    SetState(EJMDoorState::Broken, DamageInstigator);
    FJMDoorUseContext Context;
    Context.InstigatorActor = DamageInstigator;
    PlayConfiguredSound(GetEffectiveConfig()->BreakSound);
    EmitNoise(GetEffectiveConfig()->BreakNoiseLoudness, GetEffectiveConfig()->BreakNoiseRange, TAG_JMDoor_Noise_Break.GetTag(), Context);
}

void UJMDoorComponent::SetState(EJMDoorState NewState, AActor* EventInstigator)
{
    if (CurrentState == NewState) return;
    const EJMDoorState OldState = CurrentState;
    CurrentState = NewState;
    OnDoorStateChanged.Broadcast(OldState, NewState);

    FGameplayTag EventTag;
    if (OldState == EJMDoorState::Locked && NewState != EJMDoorState::Locked)
    {
        EventTag = JMDoorEventTags::Unlocked;
    }
    else
    {
        switch (NewState)
        {
        case EJMDoorState::Open: EventTag = JMDoorEventTags::Opened; break;
        case EJMDoorState::Closed: EventTag = JMDoorEventTags::Closed; break;
        case EJMDoorState::Locked: EventTag = JMDoorEventTags::Locked; break;
        case EJMDoorState::Broken: EventTag = JMDoorEventTags::Broken; break;
        default: break;
        }
    }
    if (!EventTag.IsValid())
    {
        return;
    }

    UGameInstance* GameInstance = GetWorld() ? GetWorld()->GetGameInstance() : nullptr;
    UJMGameplayEventSubsystem* EventSubsystem = GameInstance ? GameInstance->GetSubsystem<UJMGameplayEventSubsystem>() : nullptr;
    if (!EventSubsystem)
    {
        return;
    }
    UJMDoorStateChangedEventPayload* Payload = NewObject<UJMDoorStateChangedEventPayload>(this);
    Payload->OldState = OldState;
    Payload->NewState = NewState;
    Payload->OpenFraction = CurrentOpenFraction;
    Payload->ObjectiveTargetIdentifier = ObjectiveTargetIdentifier;
    Payload->ObjectiveProgressAmount = 1;
    FJMGameplayEventMessage Message;
    Message.EventTag = EventTag;
    Message.Source = GetOwner();
    Message.Instigator = IsValid(EventInstigator) ? EventInstigator : ActiveContext.InstigatorActor.Get();
    Message.Target = GetOwner();
    Message.Payload = Payload;
    EventSubsystem->PublishEvent(Message);
}

void UJMDoorComponent::EmitNoise(float Loudness, float MaxRange, FGameplayTag NoiseTag, const FJMDoorUseContext& Context) const
{
    FJMDoorNoiseEvent Event;
    Event.Location = GetOwner() ? GetOwner()->GetActorLocation() : FVector::ZeroVector;
    Event.Loudness = bActiveQuiet ? Loudness * 0.2f : Loudness;
    Event.MaxRange = MaxRange;
    Event.NoiseTag = NoiseTag;
    Event.SourceActor = GetOwner();
    Event.InstigatorActor = Context.InstigatorActor;
    const_cast<UJMDoorComponent*>(this)->OnNoiseEmitted.Broadcast(Event);
}

void UJMDoorComponent::PlayConfiguredSound(const TSoftObjectPtr<USoundBase>& Sound) const
{
    if (USoundBase* LoadedSound = Sound.LoadSynchronous())
    {
        UGameplayStatics::PlaySoundAtLocation(this, LoadedSound, GetOwner() ? GetOwner()->GetActorLocation() : FVector::ZeroVector);
    }
}

const UJMDoorConfigData* UJMDoorComponent::GetEffectiveConfig() const
{
    return Config ? Config : JMGetFallbackDoorConfig();
}
