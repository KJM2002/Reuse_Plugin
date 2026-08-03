#include "Components/JMFootstepComponent.h"

#include "Components/CapsuleComponent.h"
#include "Data/JMFootstepSet.h"
#include "Data/JMFootstepSurfaceProfile.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "JMFootstepRuntime.h"
#include "Kismet/GameplayStatics.h"
#include "Settings/JMFootstepSettings.h"
#include "Sound/SoundAttenuation.h"
#include "Sound/SoundBase.h"

int32 FJMFootstepVariantSoundHistory::GetLastIndex(
    const EJMFootstepLocomotionState VariantState,
    const bool bLegacyVariant) const
{
    if (bLegacyVariant)
    {
        return LegacyIndex;
    }

    switch (VariantState)
    {
    case EJMFootstepLocomotionState::Run:
        return RunIndex;
    case EJMFootstepLocomotionState::CrouchWalk:
        return CrouchWalkIndex;
    case EJMFootstepLocomotionState::Walk:
    default:
        return WalkIndex;
    }
}

void FJMFootstepVariantSoundHistory::SetLastIndex(
    const EJMFootstepLocomotionState VariantState,
    const bool bLegacyVariant,
    const int32 SoundIndex)
{
    if (bLegacyVariant)
    {
        LegacyIndex = SoundIndex;
        return;
    }

    switch (VariantState)
    {
    case EJMFootstepLocomotionState::Run:
        RunIndex = SoundIndex;
        break;
    case EJMFootstepLocomotionState::CrouchWalk:
        CrouchWalkIndex = SoundIndex;
        break;
    case EJMFootstepLocomotionState::Walk:
    default:
        WalkIndex = SoundIndex;
        break;
    }
}

UJMFootstepComponent::UJMFootstepComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = true;
    bAutoActivate = true;
}

void UJMFootstepComponent::BeginPlay()
{
    Super::BeginPlay();
    ResetFootstepState();

    if (!Cast<ACharacter>(GetOwner()))
    {
        UE_LOG(LogJMFootstep, Warning, TEXT("%s requires an ACharacter owner; automatic footstep updates were disabled."), *GetNameSafe(this));
        SetComponentTickEnabled(false);
    }
}

void UJMFootstepComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    ResetFootstepState();
    OnFootstepPlayed.Clear();
    Super::EndPlay(EndPlayReason);
}

void UJMFootstepComponent::Activate(const bool bReset)
{
    Super::Activate(bReset);
    ResetFootstepState();
    SetComponentTickEnabled(Cast<ACharacter>(GetOwner()) != nullptr);
}

void UJMFootstepComponent::Deactivate()
{
    SetComponentTickEnabled(false);
    ResetFootstepState();
    Super::Deactivate();
}

void UJMFootstepComponent::TickComponent(
    const float DeltaTime,
    const ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    ACharacter* Character = Cast<ACharacter>(GetOwner());
    if (!IsActive() || !IsValid(Character))
    {
        return;
    }

    const FVector CurrentLocation = Character->GetActorLocation();
    if (!bHasPreviousLocation)
    {
        PreviousLocation = CurrentLocation;
        bHasPreviousLocation = true;
        return;
    }

    const float Distance2D = FVector::Dist2D(CurrentLocation, PreviousLocation);
    PreviousLocation = CurrentLocation;
    LastActualSpeed2D = DeltaTime > UE_KINDA_SMALL_NUMBER ? Distance2D / DeltaTime : 0.0f;

    const UJMFootstepSettings* Settings = UJMFootstepSettings::Get();
    if (!Settings)
    {
        DistanceAccumulator.Reset();
        return;
    }

    const EJMFootstepTriggerMode TriggerMode = bOverrideTriggerMode
        ? TriggerModeOverride
        : Settings->TriggerMode;
    if (TriggerMode != EJMFootstepTriggerMode::DistanceBased)
    {
        return;
    }

    const bool bGrounded = IsOwnerGrounded(Character);
    CurrentLocomotionState = DetectLocomotionState(LastActualSpeed2D, bGrounded);

    if (!bGrounded)
    {
        DistanceAccumulator.Reset();
        return;
    }

    if (CurrentLocomotionState == EJMFootstepLocomotionState::Idle)
    {
        return;
    }

    const float RequiredDistance = GetStepDistance(CurrentLocomotionState);
    const float TeleportThreshold = bOverrideMovementSettings
        ? TeleportDistanceThresholdOverride
        : Settings->TeleportDistanceThreshold;
    const int32 MaxSteps = bOverrideMovementSettings
        ? MaxStepsPerFrameOverride
        : Settings->MaxStepsPerFrame;

    const int32 StepCount = DistanceAccumulator.AddMovement(
        Distance2D,
        true,
        RequiredDistance,
        TeleportThreshold,
        MaxSteps);

#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
    if (IsDebugEnabled(Settings))
    {
        UE_LOG(
            LogJMFootstep,
            Log,
            TEXT("%s State=%d Accumulated=%.2f Required=%.2f Delta=%.2f"),
            *GetNameSafe(Character),
            static_cast<int32>(CurrentLocomotionState),
            DistanceAccumulator.GetAccumulatedDistance(),
            RequiredDistance,
            Distance2D);
    }
#endif

    for (int32 StepIndex = 0; StepIndex < StepCount; ++StepIndex)
    {
        FJMFootstepContext Context;
        Context.Instigator = Character;
        Context.bOverrideLocomotionState = true;
        Context.LocomotionState = CurrentLocomotionState;
        RequestFootstep(Context);
    }
}

FJMFootstepResult UJMFootstepComponent::TriggerFootstep()
{
    FJMFootstepContext Context;
    Context.Instigator = GetOwner();
    return RequestFootstep(Context);
}

FJMFootstepResult UJMFootstepComponent::RequestFootstep(const FJMFootstepContext& Context)
{
    ACharacter* Character = Cast<ACharacter>(GetOwner());
    if (!IsValid(Character))
    {
        return MakeFailure(EJMFootstepFailureReason::InvalidOwner, EJMFootstepLocomotionState::Idle, NextLogicalFoot);
    }

    const UJMFootstepSettings* Settings = UJMFootstepSettings::Get();
    if (!Settings)
    {
        return MakeFailure(EJMFootstepFailureReason::SettingsMissing, CurrentLocomotionState, NextLogicalFoot);
    }

    const EJMFootstepLocomotionState State = FJMFootstepRuntimeLogic::ResolveRequestedLocomotionState(
        Context,
        DetectLocomotionState(Character->GetVelocity().Size2D(), IsOwnerGrounded(Character)));
    const EJMFootstepFoot Foot = Context.bOverrideLogicalFoot ? Context.LogicalFoot : NextLogicalFoot;

    if (!IsOwnerGrounded(Character))
    {
        return MakeFailure(EJMFootstepFailureReason::NotGrounded, State, Foot);
    }

    if (State == EJMFootstepLocomotionState::Idle)
    {
        return MakeFailure(EJMFootstepFailureReason::NotMoving, State, Foot);
    }

    UJMFootstepSet* FootstepSet = ResolveFootstepSet(Settings);
    if (!IsValid(FootstepSet))
    {
        return MakeFailure(EJMFootstepFailureReason::SettingsMissing, State, Foot);
    }

    UWorld* World = GetWorld();
    if (!IsValid(World))
    {
        return MakeFailure(EJMFootstepFailureReason::TraceFailed, State, Foot);
    }

    const float TraceDistance = bOverrideTraceSettings ? TraceDistanceOverride : Settings->TraceDistance;
    const ECollisionChannel TraceChannel = bOverrideTraceSettings
        ? TraceChannelOverride.GetValue()
        : Settings->TraceChannel.GetValue();
    const FVector TraceStart = Context.bOverrideTraceOrigin
        ? Context.TraceOrigin
        : GetDefaultTraceOrigin(Character);
    const FVector TraceEnd = TraceStart - FVector(0.0f, 0.0f, FMath::Max(1.0f, TraceDistance));

    FCollisionQueryParams QueryParams(SCENE_QUERY_STAT(JMFootstepTrace), false, Character);
    QueryParams.bReturnPhysicalMaterial = true;

    FHitResult Hit;
    const bool bHit = World->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, TraceChannel, QueryParams);

#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
    if (IsDebugEnabled(Settings))
    {
        DrawDebugLine(World, TraceStart, TraceEnd, bHit ? FColor::Green : FColor::Red, false, 1.5f, 0, 1.5f);
        if (bHit)
        {
            DrawDebugPoint(World, Hit.ImpactPoint, 12.0f, FColor::Yellow, false, 1.5f);
        }
    }
#endif

    if (!bHit)
    {
        return MakeFailure(EJMFootstepFailureReason::TraceFailed, State, Foot);
    }

    UPhysicalMaterial* PhysicalMaterial = Hit.PhysMaterial.Get();
    const EPhysicalSurface SurfaceType = PhysicalMaterial
        ? UPhysicalMaterial::DetermineSurfaceType(PhysicalMaterial)
        : SurfaceType_Default;

    bool bUsedFallback = false;
    UJMFootstepSurfaceProfile* Profile = FootstepSet->FindProfile(SurfaceType, bUsedFallback);
    if (!IsValid(Profile))
    {
        return MakeFailure(
            PhysicalMaterial
                ? EJMFootstepFailureReason::SurfaceProfileMissing
                : EJMFootstepFailureReason::PhysicalMaterialMissing,
            State,
            Foot);
    }

    FJMFootstepSoundVariant SelectedVariant;
    EJMFootstepLocomotionState SelectedVariantState = EJMFootstepLocomotionState::Idle;
    bool bUsedVariantFallback = false;
    bool bUsedLegacyVariant = false;
    if (!Profile->ResolveVariant(
            State,
            SelectedVariant,
            SelectedVariantState,
            bUsedVariantFallback,
            bUsedLegacyVariant))
    {
        return MakeFailure(EJMFootstepFailureReason::SoundMissing, State, Foot);
    }

    TArray<int32, TInlineAllocator<8>> ValidSoundIndices;
    for (int32 Index = 0; Index < SelectedVariant.Sounds.Num(); ++Index)
    {
        if (IsValid(SelectedVariant.Sounds[Index]))
        {
            ValidSoundIndices.Add(Index);
        }
    }

    if (ValidSoundIndices.IsEmpty())
    {
        return MakeFailure(EJMFootstepFailureReason::SoundMissing, State, Foot);
    }

    const FJMFootstepVariantSoundHistory* History = SoundHistoryByProfile.Find(Profile);
    const int32 LastSoundIndex = History
        ? History->GetLastIndex(SelectedVariantState, bUsedLegacyVariant)
        : INDEX_NONE;
    TArray<int32, TInlineAllocator<8>> CandidateIndices = ValidSoundIndices;
    if (CandidateIndices.Num() > 1)
    {
        CandidateIndices.RemoveSingle(LastSoundIndex);
    }
    const int32 SelectedArrayIndex = CandidateIndices[FMath::RandHelper(CandidateIndices.Num())];
    USoundBase* SelectedSound = SelectedVariant.Sounds[SelectedArrayIndex];

    const float ProfileVolume = FMath::FRandRange(
        FMath::Min(SelectedVariant.VolumeMin, SelectedVariant.VolumeMax),
        FMath::Max(SelectedVariant.VolumeMin, SelectedVariant.VolumeMax));
    const float ProfilePitch = FMath::FRandRange(
        FMath::Min(SelectedVariant.PitchMin, SelectedVariant.PitchMax),
        FMath::Max(SelectedVariant.PitchMin, SelectedVariant.PitchMax));
    const float BaseVolume = bOverrideAudioMultipliers
        ? VolumeMultiplierOverride
        : Settings->DefaultVolumeMultiplier;
    const float BasePitch = bOverrideAudioMultipliers
        ? PitchMultiplierOverride
        : Settings->DefaultPitchMultiplier;
    const float FinalVolume = FMath::Max(
        0.0f,
        ProfileVolume * BaseVolume * GetStateVolumeMultiplier(State) * FMath::Max(0.0f, Context.VolumeMultiplier));
    const float FinalPitch = FMath::Max(
        0.01f,
        ProfilePitch * BasePitch * FMath::Max(0.01f, Context.PitchMultiplier));

    UGameplayStatics::PlaySoundAtLocation(
        this,
        SelectedSound,
        Hit.ImpactPoint,
        FRotator::ZeroRotator,
        FinalVolume,
        FinalPitch,
        0.0f,
        Profile->AttenuationSettings,
        nullptr,
        Context.Instigator ? Context.Instigator.Get() : Character);

    FJMFootstepResult Result;
    Result.bSucceeded = true;
    Result.FailureReason = EJMFootstepFailureReason::None;
    Result.LocomotionState = State;
    Result.SelectedVariantState = SelectedVariantState;
    Result.bUsedVariantFallback = bUsedVariantFallback;
    Result.bUsedLegacyVariant = bUsedLegacyVariant;
    Result.LogicalFoot = Foot;
    Result.SurfaceType = SurfaceType;
    Result.PhysicalMaterial = PhysicalMaterial;
    Result.SelectedSound = SelectedSound;
    Result.ImpactPoint = Hit.ImpactPoint;
    Result.ImpactNormal = Hit.ImpactNormal;
    Result.FinalVolume = FinalVolume;
    Result.FinalPitch = FinalPitch;

    SoundHistoryByProfile.FindOrAdd(Profile).SetLastIndex(
        SelectedVariantState,
        bUsedLegacyVariant,
        SelectedArrayIndex);
    NextLogicalFoot = Foot == EJMFootstepFoot::Left
        ? EJMFootstepFoot::Right
        : EJMFootstepFoot::Left;

#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
    if (IsDebugEnabled(Settings))
    {
        UE_LOG(
            LogJMFootstep,
            Log,
            TEXT("%s played %s Surface=%d Profile=%s Foot=%d RequestedState=%d SelectedVariantState=%d Volume=%.2f Pitch=%.2f SurfaceFallback=%s VariantFallback=%s LegacyVariant=%s"),
            *GetNameSafe(Character),
            *GetNameSafe(SelectedSound),
            static_cast<int32>(SurfaceType),
            *GetNameSafe(Profile),
            static_cast<int32>(Foot),
            static_cast<int32>(State),
            static_cast<int32>(SelectedVariantState),
            FinalVolume,
            FinalPitch,
            bUsedFallback ? TEXT("true") : TEXT("false"),
            bUsedVariantFallback ? TEXT("true") : TEXT("false"),
            bUsedLegacyVariant ? TEXT("true") : TEXT("false"));
    }
#endif

    OnFootstepPlayed.Broadcast(Result);
    return Result;
}

void UJMFootstepComponent::SetLocomotionStateOverride(const EJMFootstepLocomotionState NewState)
{
    LocomotionOverride = NewState;
    bHasLocomotionOverride = true;
}

void UJMFootstepComponent::ClearLocomotionStateOverride()
{
    bHasLocomotionOverride = false;
}

void UJMFootstepComponent::ResetFootstepState()
{
    DistanceAccumulator.Reset();
    CurrentLocomotionState = EJMFootstepLocomotionState::Idle;
    LastActualSpeed2D = 0.0f;
    NextLogicalFoot = EJMFootstepFoot::Left;
    SoundHistoryByProfile.Reset();

    if (const AActor* Owner = GetOwner())
    {
        PreviousLocation = Owner->GetActorLocation();
        bHasPreviousLocation = true;
    }
    else
    {
        PreviousLocation = FVector::ZeroVector;
        bHasPreviousLocation = false;
    }
}

bool UJMFootstepComponent::IsOwnerGrounded(const ACharacter* Character) const
{
    if (!IsValid(Character))
    {
        return false;
    }

    const UCharacterMovementComponent* Movement = Character->GetCharacterMovement();
    if (!IsValid(Movement))
    {
        return false;
    }

    return Movement->MovementMode == MOVE_Walking || Movement->MovementMode == MOVE_NavWalking;
}

EJMFootstepLocomotionState UJMFootstepComponent::DetectLocomotionState(
    const float ActualSpeed2D,
    const bool bGrounded) const
{
    if (bHasLocomotionOverride)
    {
        return LocomotionOverride;
    }

    const UJMFootstepSettings* Settings = UJMFootstepSettings::Get();
    if (!Settings)
    {
        return EJMFootstepLocomotionState::Idle;
    }

    const float MinimumSpeed = bOverrideMovementSettings
        ? MinimumMovementSpeedOverride
        : Settings->MinimumMovementSpeed;
    const float RunThreshold = bOverrideMovementSettings
        ? RunSpeedThresholdOverride
        : Settings->RunSpeedThreshold;
    const ACharacter* Character = Cast<ACharacter>(GetOwner());

    return FJMFootstepRuntimeLogic::ResolveLocomotionState(
        ActualSpeed2D,
        IsValid(Character) && Character->bIsCrouched,
        bGrounded,
        MinimumSpeed,
        RunThreshold);
}

float UJMFootstepComponent::GetStepDistance(const EJMFootstepLocomotionState State) const
{
    const UJMFootstepSettings* Settings = UJMFootstepSettings::Get();
    if (!Settings)
    {
        return 110.0f;
    }

    return FJMFootstepRuntimeLogic::ResolveStepDistance(
        State,
        bOverrideMovementSettings ? WalkStepDistanceOverride : Settings->WalkStepDistance,
        bOverrideMovementSettings ? RunStepDistanceOverride : Settings->RunStepDistance,
        bOverrideMovementSettings ? CrouchStepDistanceOverride : Settings->CrouchStepDistance);
}

float UJMFootstepComponent::GetStateVolumeMultiplier(const EJMFootstepLocomotionState State) const
{
    const UJMFootstepSettings* Settings = UJMFootstepSettings::Get();
    if (!Settings)
    {
        return 1.0f;
    }

    return FJMFootstepRuntimeLogic::ResolveStateVolumeMultiplier(
        State,
        Settings->WalkVolumeMultiplier,
        Settings->RunVolumeMultiplier,
        Settings->CrouchVolumeMultiplier);
}

FVector UJMFootstepComponent::GetDefaultTraceOrigin(const ACharacter* Character) const
{
    const UJMFootstepSettings* Settings = UJMFootstepSettings::Get();
    const float StartOffset = bOverrideTraceSettings
        ? TraceStartOffsetOverride
        : (Settings ? Settings->TraceStartOffset : 10.0f);

    FVector Origin = Character ? Character->GetActorLocation() : FVector::ZeroVector;
    if (Character && Character->GetCapsuleComponent())
    {
        Origin.Z -= Character->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
    }
    Origin.Z += FMath::Max(0.0f, StartOffset);
    return Origin;
}

UJMFootstepSet* UJMFootstepComponent::ResolveFootstepSet(const UJMFootstepSettings* Settings) const
{
    if (IsValid(FootstepSetOverride))
    {
        return FootstepSetOverride;
    }

    return Settings ? Settings->DefaultFootstepSet.LoadSynchronous() : nullptr;
}

FJMFootstepResult UJMFootstepComponent::MakeFailure(
    const EJMFootstepFailureReason Reason,
    const EJMFootstepLocomotionState State,
    const EJMFootstepFoot Foot) const
{
    FJMFootstepResult Result = FJMFootstepResult::Failure(Reason);
    Result.LocomotionState = State;
    Result.LogicalFoot = Foot;
    return Result;
}

bool UJMFootstepComponent::IsDebugEnabled(const UJMFootstepSettings* Settings) const
{
    return bOverrideDebug ? bEnableDebugOverride : (Settings && Settings->bEnableDebug);
}
