#include "Components/JMHarpoonGunComponent.h"

#include "Actors/JMHarpoonGunVisualActor.h"
#include "Actors/JMHarpoonProjectile.h"
#include "CableComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Components/SceneComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/WorldSettings.h"
#include "Misc/CommandLine.h"
#include "Misc/Parse.h"

UJMHarpoonGunComponent::UJMHarpoonGunComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.TickGroup = TG_PrePhysics;

    ProjectileClass = AJMHarpoonProjectile::StaticClass();
    VisualActorClass = AJMHarpoonGunVisualActor::StaticClass();
}

void UJMHarpoonGunComponent::BeginPlay()
{
    Super::BeginPlay();
    PlayerGrappleState = bEnablePlayerGrapple
        ? EJMPlayerGrappleState::Idle
        : EJMPlayerGrappleState::Disabled;
    EnsurePresentation();
}

void UJMHarpoonGunComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    EndPlayerGrapple(EJMPlayerGrappleEndReason::InvalidAnchor);
    if (bPlayerGrappleFOVActive && GrappleCamera.IsValid())
    {
        GrappleCamera->SetFieldOfView(GrappleBaseFOV);
    }
    ResetHarpoon();
    DestroyPresentation();
    Super::EndPlay(EndPlayReason);
}

void UJMHarpoonGunComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    APlayerController* Controller = GetOwningPlayerController();
    if (!Controller || !Controller->IsLocalController())
    {
        return;
    }

    EnsurePresentation();
    CooldownRemaining = FMath::Max(0.0f, CooldownRemaining - DeltaTime);

    if (Controller->WasInputKeyJustPressed(FireKey))
    {
        if (State == EJMHarpoonGunState::Ready)
        {
            FireHarpoon();
        }
        else if (State == EJMHarpoonGunState::Flying || State == EJMHarpoonGunState::Embedded)
        {
            RecallHarpoon();
        }
    }

    UpdatePlayerGrappleInput(Controller);

#if !UE_BUILD_SHIPPING
    UpdateFailSafeSmoke();
    UpdatePlayerGrappleSmoke(DeltaTime);
#endif

    if (State != EJMHarpoonGunState::Ready && HasHarpoonSafetyViolation())
    {
        BeginEmergencyReturn();
    }

    switch (State)
    {
    case EJMHarpoonGunState::Flying:
        UpdateFlying(DeltaTime);
        break;
    case EJMHarpoonGunState::Embedded:
        UpdateEmbedded(DeltaTime);
        break;
    case EJMHarpoonGunState::Retracting:
        UpdateRetracting(DeltaTime);
        break;
    default:
        break;
    }

    UpdatePlayerGrapple(DeltaTime);
    UpdatePlayerGrappleFOV(DeltaTime);

    UpdatePresentation(DeltaTime);
}

void UJMHarpoonGunComponent::SetPlayerGrappleEnabled(bool bEnabled)
{
    if (!bEnabled)
    {
        bEnablePlayerGrapple = false;
        EndPlayerGrapple(EJMPlayerGrappleEndReason::FeatureDisabled);
        PlayerGrappleState = EJMPlayerGrappleState::Disabled;
        return;
    }

    bEnablePlayerGrapple = true;
    if (PlayerGrappleState == EJMPlayerGrappleState::Disabled)
    {
        PlayerGrappleState = EJMPlayerGrappleState::Idle;
    }
}

bool UJMHarpoonGunComponent::StartPlayerGrapple()
{
    if (!bEnablePlayerGrapple
        || State != EJMHarpoonGunState::Embedded
        || !IsValid(ActiveProjectile)
        || !IsValid(EmbeddedComponent))
    {
        return false;
    }

    if (!bAllowDynamicPlayerGrappleAnchors
        && EmbeddedComponent->IsSimulatingPhysics(EmbeddedBone))
    {
        PlayerGrappleState = EJMPlayerGrappleState::Idle;
        return false;
    }

    ACharacter* Character = Cast<ACharacter>(GetOwner());
    UCharacterMovementComponent* Movement = Character ? Character->GetCharacterMovement() : nullptr;
    if (!Character || !Movement)
    {
        PlayerGrappleState = EJMPlayerGrappleState::Idle;
        return false;
    }

    const float Distance = FVector::Distance(Character->GetActorLocation(), ActiveProjectile->GetActorLocation());
    if (!FMath::IsFinite(Distance) || Distance <= PlayerGrappleStopDistance)
    {
        PlayerGrappleState = EJMPlayerGrappleState::Idle;
        return false;
    }

    if (PlayerGrappleState == EJMPlayerGrappleState::Pulling)
    {
        return true;
    }

    GrappleCharacter = Character;
    GrappleMovement = Movement;
    GrappleOriginalGravityScale = Movement->GravityScale;
    GrappleOriginalMaxWalkSpeed = Movement->MaxWalkSpeed;
    GrappleOriginalGroundFriction = Movement->GroundFriction;
    GrappleOriginalBrakingFrictionFactor = Movement->BrakingFrictionFactor;
    bPlayerGrappleMovementOverridden = true;

    Movement->GravityScale = PlayerGrappleGravityScale;
    Movement->MaxWalkSpeed = FMath::Max(Movement->MaxWalkSpeed, PlayerGrappleMaxSpeed);
    Movement->GroundFriction = FMath::Min(Movement->GroundFriction, 0.5f);
    Movement->BrakingFrictionFactor = 0.0f;

    if (!bPlayerGrappleFOVActive)
    {
        GrappleCamera = GetOwner()->FindComponentByClass<UCameraComponent>();
        if (GrappleCamera.IsValid())
        {
            GrappleBaseFOV = GrappleCamera->FieldOfView;
            bPlayerGrappleFOVActive = true;
        }
    }

    PlayerGrappleElapsed = 0.0f;
    PlayerGrappleBlockedElapsed = 0.0f;
    PlayerGrappleProgressStartDistance = Distance;
    PlayerGrappleState = EJMPlayerGrappleState::Pulling;
    OnPlayerGrappleStarted.Broadcast(ActiveProjectile);
    return true;
}

void UJMHarpoonGunComponent::StopPlayerGrapple()
{
    EndPlayerGrapple(EJMPlayerGrappleEndReason::Released);
}

void UJMHarpoonGunComponent::UpdatePlayerGrappleInput(APlayerController* Controller)
{
    if (!bEnablePlayerGrapple)
    {
        if (PlayerGrappleState != EJMPlayerGrappleState::Disabled)
        {
            EndPlayerGrapple(EJMPlayerGrappleEndReason::FeatureDisabled);
            PlayerGrappleState = EJMPlayerGrappleState::Disabled;
        }
        return;
    }

    if (PlayerGrappleState == EJMPlayerGrappleState::Disabled)
    {
        PlayerGrappleState = EJMPlayerGrappleState::Idle;
    }

    if (Controller->WasInputKeyJustPressed(PlayerGrappleKey))
    {
        if (State == EJMHarpoonGunState::Flying)
        {
            PlayerGrappleState = EJMPlayerGrappleState::Armed;
        }
        else if (State == EJMHarpoonGunState::Embedded)
        {
            StartPlayerGrapple();
        }
    }

    if (Controller->WasInputKeyJustReleased(PlayerGrappleKey))
    {
        if (PlayerGrappleState == EJMPlayerGrappleState::Pulling)
        {
            EndPlayerGrapple(EJMPlayerGrappleEndReason::Released);
        }
        else if (PlayerGrappleState == EJMPlayerGrappleState::Armed)
        {
            PlayerGrappleState = EJMPlayerGrappleState::Idle;
        }
    }
}

void UJMHarpoonGunComponent::UpdatePlayerGrapple(float DeltaTime)
{
    if (PlayerGrappleState != EJMPlayerGrappleState::Pulling)
    {
        return;
    }

    if (!bEnablePlayerGrapple)
    {
        EndPlayerGrapple(EJMPlayerGrappleEndReason::FeatureDisabled);
        return;
    }

    if (State != EJMHarpoonGunState::Embedded
        || !IsValid(ActiveProjectile)
        || !IsValid(EmbeddedComponent)
        || !GrappleCharacter.IsValid()
        || !GrappleMovement.IsValid())
    {
        const EJMPlayerGrappleEndReason Reason = State == EJMHarpoonGunState::Retracting
            ? EJMPlayerGrappleEndReason::HarpoonRecall
            : EJMPlayerGrappleEndReason::InvalidAnchor;
        EndPlayerGrapple(Reason);
        return;
    }

    if (!bAllowDynamicPlayerGrappleAnchors
        && EmbeddedComponent->IsSimulatingPhysics(EmbeddedBone))
    {
        EndPlayerGrapple(EJMPlayerGrappleEndReason::InvalidAnchor);
        return;
    }

    ACharacter* Character = GrappleCharacter.Get();
    UCharacterMovementComponent* Movement = GrappleMovement.Get();
    const FVector AnchorLocation = ActiveProjectile->GetActorLocation();
    const FVector CharacterLocation = Character->GetActorLocation();
    const FVector ToAnchor = AnchorLocation - CharacterLocation;
    const float Distance = ToAnchor.Size();
    if (!FMath::IsFinite(Distance) || AnchorLocation.ContainsNaN())
    {
        EndPlayerGrapple(EJMPlayerGrappleEndReason::InvalidAnchor);
        return;
    }

    PlayerGrappleElapsed += DeltaTime;
    if (PlayerGrappleElapsed >= PlayerGrappleMaxDuration)
    {
        EndPlayerGrapple(EJMPlayerGrappleEndReason::Timeout);
        return;
    }

    const FVector PullDirection = ToAnchor.GetSafeNormal();
    if (Distance <= PlayerGrappleStopDistance || PullDirection.IsNearlyZero())
    {
        const float InwardSpeed = FVector::DotProduct(Movement->Velocity, PullDirection);
        if (InwardSpeed > 0.0f)
        {
            Movement->Velocity -= PullDirection * InwardSpeed * PlayerGrappleArrivalBraking;
        }
        EndPlayerGrapple(EJMPlayerGrappleEndReason::ReachedAnchor);
        return;
    }

    if (Distance <= PlayerGrappleProgressStartDistance - PlayerGrappleMinimumProgress)
    {
        PlayerGrappleProgressStartDistance = Distance;
        PlayerGrappleBlockedElapsed = 0.0f;
    }
    else
    {
        PlayerGrappleBlockedElapsed += DeltaTime;
        if (PlayerGrappleBlockedElapsed >= PlayerGrappleBlockedTimeout)
        {
            EndPlayerGrapple(EJMPlayerGrappleEndReason::Blocked);
            return;
        }
    }

    const float SafeSlowDistance = FMath::Max(
        PlayerGrappleApproachSlowDistance,
        PlayerGrappleStopDistance + 1.0f);
    const float SpeedAlpha = FMath::Clamp(
        (Distance - PlayerGrappleStopDistance) / (SafeSlowDistance - PlayerGrappleStopDistance),
        0.0f,
        1.0f);
    const float MinimumApproachSpeed = FMath::Min(600.0f, PlayerGrappleMaxSpeed);
    const float TargetInwardSpeed = FMath::Lerp(
        MinimumApproachSpeed,
        PlayerGrappleMaxSpeed,
        SpeedAlpha);

    const FVector CurrentVelocity = Movement->Velocity;
    const FVector TangentialVelocity = CurrentVelocity
        - PullDirection * FVector::DotProduct(CurrentVelocity, PullDirection);
    const FVector DesiredVelocity = PullDirection * TargetInwardSpeed
        + TangentialVelocity * PlayerGrappleTangentialRetention;
    const FVector VelocityDelta = (DesiredVelocity - CurrentVelocity).GetClampedToMaxSize(
        PlayerGrappleAcceleration * DeltaTime);
    FVector NewVelocity = (CurrentVelocity + VelocityDelta).GetClampedToMaxSize(PlayerGrappleMaxSpeed);
    if (PullDirection.Z < -0.1f)
    {
        NewVelocity.Z = FMath::Max(NewVelocity.Z, -PlayerGrappleMaxDownwardSpeed);
    }

    const FVector CameraLocation = GrappleCamera.IsValid()
        ? GrappleCamera->GetComponentLocation()
        : Character->GetPawnViewLocation();
    FVector ClosestAnchorPoint = FVector::ZeroVector;
    const float CameraToAnchorSurface = EmbeddedComponent->GetOwner() != GetOwner()
        ? EmbeddedComponent->GetClosestPointOnCollision(
            CameraLocation,
            ClosestAnchorPoint,
            EmbeddedBone)
        : -1.0f;
    const float SafeCameraClearance = FMath::Max(0.0f, PlayerGrappleCameraClearance);
    if (CameraToAnchorSurface >= 0.0f
        && CameraToAnchorSurface <= SafeCameraClearance + PlayerGrappleCameraProbeRadius)
    {
        FVector SurfaceDirection = (ClosestAnchorPoint - CameraLocation).GetSafeNormal();
        if (SurfaceDirection.IsNearlyZero())
        {
            SurfaceDirection = PullDirection;
        }
        const bool bSurfaceIsAhead = FVector::DotProduct(SurfaceDirection, PullDirection) > 0.35f;
        const float SurfaceSpeed = FVector::DotProduct(NewVelocity, SurfaceDirection);
        if (bSurfaceIsAhead && SurfaceSpeed > 0.0f)
        {
            NewVelocity -= SurfaceDirection * SurfaceSpeed;
            Movement->Velocity = NewVelocity;
            EndPlayerGrapple(EJMPlayerGrappleEndReason::ReachedAnchor);
            return;
        }
    }

    FHitResult CameraHit;
    if (SweepPlayerGrappleCamera(
        CameraLocation,
        PullDirection,
        NewVelocity,
        DeltaTime,
        CameraHit))
    {
        FVector HitNormal = CameraHit.Normal.GetSafeNormal();
        if (HitNormal.IsNearlyZero())
        {
            HitNormal = -PullDirection;
        }
        const float IntoSurfaceSpeed = FVector::DotProduct(NewVelocity, HitNormal);
        if (IntoSurfaceSpeed < 0.0f)
        {
            NewVelocity -= HitNormal * IntoSurfaceSpeed;
        }

        const bool bReachedAnchor = CameraHit.GetComponent() == EmbeddedComponent;
        Movement->Velocity = NewVelocity;
        EndPlayerGrapple(bReachedAnchor
            ? EJMPlayerGrappleEndReason::ReachedAnchor
            : EJMPlayerGrappleEndReason::Blocked);
        return;
    }

    Movement->GravityScale = PlayerGrappleGravityScale;
    Movement->Velocity = NewVelocity;
    if (Movement->IsMovingOnGround() && PullDirection.Z > 0.15f)
    {
        Movement->SetMovementMode(MOVE_Falling);
    }
}

bool UJMHarpoonGunComponent::SweepPlayerGrappleCamera(
    const FVector& CameraLocation,
    const FVector& PullDirection,
    const FVector& CandidateVelocity,
    float DeltaTime,
    FHitResult& OutHit) const
{
    UWorld* World = GetWorld();
    if (!World || PlayerGrappleCameraProbeRadius <= 0.0f)
    {
        return false;
    }

    const float SafeDeltaTime = FMath::Clamp(DeltaTime, 0.0f, 0.1f);
    const FVector PredictedCameraLocation = CameraLocation + CandidateVelocity * SafeDeltaTime;
    const FVector ProbeEnd = PredictedCameraLocation
        + PullDirection * FMath::Max(0.0f, PlayerGrappleCameraClearance);

    FCollisionObjectQueryParams ObjectQuery;
    ObjectQuery.AddObjectTypesToQuery(ECC_WorldStatic);
    ObjectQuery.AddObjectTypesToQuery(ECC_WorldDynamic);
    ObjectQuery.AddObjectTypesToQuery(ECC_PhysicsBody);

    FCollisionQueryParams QueryParams(SCENE_QUERY_STAT(JMPlayerGrappleCameraSafety), false, GetOwner());
    if (IsValid(ActiveProjectile))
    {
        QueryParams.AddIgnoredActor(ActiveProjectile);
    }
    if (IsValid(GunVisualActor))
    {
        QueryParams.AddIgnoredActor(GunVisualActor);
    }

    const bool bBlocked = World->SweepSingleByObjectType(
        OutHit,
        CameraLocation,
        ProbeEnd,
        FQuat::Identity,
        ObjectQuery,
        FCollisionShape::MakeSphere(PlayerGrappleCameraProbeRadius),
        QueryParams);

    if (bDrawDebug)
    {
        const FColor ProbeColor = bBlocked ? FColor::Red : FColor::Green;
        DrawDebugLine(World, CameraLocation, ProbeEnd, ProbeColor, false, 0.1f, 0, 1.0f);
        DrawDebugSphere(
            World,
            bBlocked ? OutHit.Location : ProbeEnd,
            PlayerGrappleCameraProbeRadius,
            12,
            ProbeColor,
            false,
            0.1f,
            0,
            1.0f);
    }

    return bBlocked;
}

void UJMHarpoonGunComponent::RestorePlayerGrappleMovement()
{
    if (bPlayerGrappleMovementOverridden && GrappleMovement.IsValid())
    {
        UCharacterMovementComponent* Movement = GrappleMovement.Get();
        Movement->GravityScale = GrappleOriginalGravityScale;
        Movement->MaxWalkSpeed = GrappleOriginalMaxWalkSpeed;
        Movement->GroundFriction = GrappleOriginalGroundFriction;
        Movement->BrakingFrictionFactor = GrappleOriginalBrakingFrictionFactor;
    }

    bPlayerGrappleMovementOverridden = false;
    GrappleCharacter.Reset();
    GrappleMovement.Reset();
}

void UJMHarpoonGunComponent::EndPlayerGrapple(EJMPlayerGrappleEndReason Reason)
{
    const bool bWasPulling = PlayerGrappleState == EJMPlayerGrappleState::Pulling;
    AJMHarpoonProjectile* GrappledProjectile = ActiveProjectile;
    RestorePlayerGrappleMovement();

    PlayerGrappleElapsed = 0.0f;
    PlayerGrappleBlockedElapsed = 0.0f;
    PlayerGrappleProgressStartDistance = 0.0f;
    PlayerGrappleState = bEnablePlayerGrapple
        ? EJMPlayerGrappleState::Idle
        : EJMPlayerGrappleState::Disabled;

    if (bWasPulling)
    {
        OnPlayerGrappleEnded.Broadcast(GrappledProjectile, Reason);
    }
}

void UJMHarpoonGunComponent::UpdatePlayerGrappleFOV(float DeltaTime)
{
    if (!bPlayerGrappleFOVActive)
    {
        return;
    }

    if (!GrappleCamera.IsValid())
    {
        bPlayerGrappleFOVActive = false;
        return;
    }

    const float TargetFOV = PlayerGrappleState == EJMPlayerGrappleState::Pulling
        ? GrappleBaseFOV + PlayerGrappleFOVBoost
        : GrappleBaseFOV;
    const float NewFOV = FMath::FInterpTo(
        GrappleCamera->FieldOfView,
        TargetFOV,
        DeltaTime,
        PlayerGrappleFOVInterpSpeed);
    GrappleCamera->SetFieldOfView(NewFOV);

    if (PlayerGrappleState != EJMPlayerGrappleState::Pulling
        && FMath::IsNearlyEqual(NewFOV, GrappleBaseFOV, 0.05f))
    {
        GrappleCamera->SetFieldOfView(GrappleBaseFOV);
        bPlayerGrappleFOVActive = false;
        GrappleCamera.Reset();
    }
}

bool UJMHarpoonGunComponent::FireHarpoon()
{
    if (State != EJMHarpoonGunState::Ready || CooldownRemaining > 0.0f || !ProjectileClass || !GetWorld())
    {
        return false;
    }

    FVector ViewLocation;
    FVector ViewDirection;
    if (!GetView(ViewLocation, ViewDirection))
    {
        return false;
    }

    const FVector MuzzleLocation = GetMuzzleLocation();
    const FVector AimPoint = ViewLocation + ViewDirection * MaxRange;
    const FVector ShotDirection = (AimPoint - MuzzleLocation).GetSafeNormal(SMALL_NUMBER, ViewDirection);

    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = GetOwner();
    SpawnParams.Instigator = Cast<APawn>(GetOwner());
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    ActiveProjectile = GetWorld()->SpawnActor<AJMHarpoonProjectile>(
        ProjectileClass,
        MuzzleLocation,
        ShotDirection.Rotation(),
        SpawnParams);

    if (!ActiveProjectile)
    {
        return false;
    }

    // MuzzleAssembly is the shared authoring transform for the visible muzzle
    // and loaded preview. Carry its world scale into the fired actor so the
    // loaded and flying states stay visually identical after viewport edits.
    if (GunVisualActor && GunVisualActor->GetMuzzlePoint())
    {
        ActiveProjectile->SetActorScale3D(GunVisualActor->GetMuzzlePoint()->GetComponentScale());
    }

    ActiveProjectile->InitializeHarpoon(this, ShotDirection, FireSpeed);
    State = EJMHarpoonGunState::Flying;
    RecoilAlpha = 1.0f;
    ShowCable(true);
    AttachCableToActiveProjectile(100.0f);

    if (APlayerController* Controller = GetOwningPlayerController())
    {
        Controller->AddPitchInput(-0.65f);
    }

    if (bDrawDebug)
    {
        DrawDebugLine(GetWorld(), MuzzleLocation, AimPoint, FColor::Orange, false, 1.0f, 0, 1.5f);
    }

    OnHarpoonFired.Broadcast(ActiveProjectile);
    return true;
}

bool UJMHarpoonGunComponent::RecallHarpoon()
{
    if (!ActiveProjectile || (State != EJMHarpoonGunState::Flying && State != EJMHarpoonGunState::Embedded))
    {
        return false;
    }

    EndPlayerGrapple(EJMPlayerGrappleEndReason::HarpoonRecall);

    const bool bWasFlying = State == EJMHarpoonGunState::Flying;
    RecallElapsed = 0.0f;
    bDeadlineRecoveryTriggered = false;
    RecallStartDistance = FVector::Distance(GetMuzzleLocation(), ActiveProjectile->GetActorLocation());
    bPullingPhysicsTarget = State == EJMHarpoonGunState::Embedded
        && IsValid(EmbeddedComponent)
        && EmbeddedComponent->IsSimulatingPhysics(EmbeddedBone);

    State = EJMHarpoonGunState::Retracting;
    if (bPullingPhysicsTarget)
    {
        const FVector MuzzleLocation = GetMuzzleLocation();
        const FVector GrabPoint = EmbeddedComponent->GetComponentTransform().TransformPosition(EmbeddedLocalPoint);
        const FVector PullDirection = (MuzzleLocation - GrabPoint).GetSafeNormal();
        if (GetPhysicsTargetSurfaceDistance(MuzzleLocation, GrabPoint) <= PhysicsReleaseDistance)
        {
            // A close or already-overlapping target should never enter the
            // pendulum-like force pull. Release the body and return only the spear.
            ApplyPhysicsReleaseBraking(GrabPoint, PullDirection);
            DetachForFreeReturn();
            BeginFinalReturnLift();
        }
    }
    else
    {
        DetachForFreeReturn(bWasFlying);
    }

    OnHarpoonRecallStarted.Broadcast(ActiveProjectile);
    return true;
}

void UJMHarpoonGunComponent::ResetHarpoon()
{
    EndPlayerGrapple(EJMPlayerGrappleEndReason::InvalidAnchor);

    if (ActiveProjectile)
    {
        ActiveProjectile->Destroy();
        ActiveProjectile = nullptr;
    }

    EmbeddedComponent = nullptr;
    EmbeddedBone = NAME_None;
    EmbeddedLocalPoint = FVector::ZeroVector;
    bPullingPhysicsTarget = false;
    RecallElapsed = 0.0f;
    RecallStartDistance = 0.0f;
    FreeReturnElapsed = 0.0f;
    FreeReturnPhaseElapsed = 0.0f;
    FreeReturnVelocity = FVector::ZeroVector;
    FreeReturnGroundNormal = FVector::UpVector;
    bFreeReturnGrounded = false;
    bFreeReturnFinalLift = false;
    bDeadlineRecoveryTriggered = false;
    State = EJMHarpoonGunState::Ready;
    ShowCable(false);
}

void UJMHarpoonGunComponent::NotifyProjectileImpact(
    AJMHarpoonProjectile* Projectile,
    const FHitResult& Hit,
    const FVector& ImpactVelocity)
{
    if (State != EJMHarpoonGunState::Flying || Projectile != ActiveProjectile || !Hit.GetComponent())
    {
        return;
    }

    EmbeddedComponent = Hit.GetComponent();
    EmbeddedBone = Hit.BoneName;
    EmbeddedLocalPoint = EmbeddedComponent->GetComponentTransform().InverseTransformPosition(Hit.ImpactPoint);
    LastImpactVelocity = ImpactVelocity;

    ActiveProjectile->EmbedAtHit(Hit, EmbedDepth);
    if (EmbeddedComponent->IsSimulatingPhysics(EmbeddedBone))
    {
        EmbeddedComponent->AddImpulseAtLocation(
            ImpactVelocity.GetSafeNormal() * ImpactImpulse,
            Hit.ImpactPoint,
            EmbeddedBone);
    }

    State = EJMHarpoonGunState::Embedded;
    RecoilAlpha = FMath::Max(RecoilAlpha, 0.45f);

    if (PlayerGrappleState == EJMPlayerGrappleState::Armed)
    {
        StartPlayerGrapple();
    }

    if (APlayerController* Controller = GetOwningPlayerController())
    {
        Controller->AddPitchInput(0.18f);
    }

    if (bDrawDebug)
    {
        DrawDebugSphere(GetWorld(), Hit.ImpactPoint, 14.0f, 16, FColor::Red, false, 2.0f, 0, 2.0f);
        DrawDebugDirectionalArrow(GetWorld(), Hit.ImpactPoint, Hit.ImpactPoint + Hit.ImpactNormal * 60.0f, 15.0f, FColor::Yellow, false, 2.0f);
    }

    OnHarpoonEmbedded.Broadcast(ActiveProjectile, Hit);
}

APlayerController* UJMHarpoonGunComponent::GetOwningPlayerController() const
{
    const APawn* Pawn = Cast<APawn>(GetOwner());
    return Pawn ? Cast<APlayerController>(Pawn->GetController()) : nullptr;
}

bool UJMHarpoonGunComponent::GetView(FVector& OutLocation, FVector& OutDirection) const
{
    const APlayerController* Controller = GetOwningPlayerController();
    if (!Controller)
    {
        return false;
    }

    FRotator Rotation;
    Controller->GetPlayerViewPoint(OutLocation, Rotation);
    OutDirection = Rotation.Vector();
    return true;
}

FVector UJMHarpoonGunComponent::GetMuzzleLocation() const
{
    if (IsValid(GunVisualActor) && GunVisualActor->GetMuzzlePoint())
    {
        return GunVisualActor->GetMuzzlePoint()->GetComponentLocation();
    }

    if (const UCameraComponent* Camera = GetOwner() ? GetOwner()->FindComponentByClass<UCameraComponent>() : nullptr)
    {
        return Camera->GetComponentTransform().TransformPosition(MuzzleOffset);
    }

    FVector ViewLocation;
    FVector ViewDirection;
    return GetView(ViewLocation, ViewDirection) ? ViewLocation + ViewDirection * MuzzleOffset.X : GetOwner()->GetActorLocation();
}

void UJMHarpoonGunComponent::EnsurePresentation()
{
    if (!GetOwner())
    {
        return;
    }

    UCameraComponent* Camera = GetOwner()->FindComponentByClass<UCameraComponent>();
    USceneComponent* Parent = Camera ? static_cast<USceneComponent*>(Camera) : GetOwner()->GetRootComponent();
    if (!Parent)
    {
        return;
    }

    if (!GunVisualActor && bCreatePrototypeVisuals && VisualActorClass)
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = GetOwner();
        SpawnParams.Instigator = Cast<APawn>(GetOwner());
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
        SpawnParams.ObjectFlags |= RF_Transient;

        GunVisualActor = GetWorld()->SpawnActor<AJMHarpoonGunVisualActor>(
            VisualActorClass,
            FTransform::Identity,
            SpawnParams);
        if (GunVisualActor)
        {
            GunVisualActor->AttachToComponent(Parent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
            GunVisualActor->SetActorRelativeLocation(GunVisualOffset);
            GunVisualActor->SetLoadedHarpoonClass(ProjectileClass);
        }
    }

    if (Cable)
    {
        return;
    }

    Cable = NewObject<UCableComponent>(GetOwner(), TEXT("JMHarpoonCable"));
    GetOwner()->AddInstanceComponent(Cable);
    if (GunVisualActor && GunVisualActor->GetMuzzlePoint())
    {
        Cable->SetupAttachment(GunVisualActor->GetMuzzlePoint());
    }
    else
    {
        Cable->SetupAttachment(Parent);
    }
    Cable->CableLength = 100.0f;
    Cable->NumSegments = FMath::Clamp(CableNumSegments, 1, 64);
    Cable->SolverIterations = FMath::Clamp(CableSolverIterations, 1, 32);
    Cable->CableWidth = CableWidth;
    Cable->CableGravityScale = CableGravityScale;
    Cable->SubstepTime = FMath::Max(CableSubstepTime, 0.005f);
    Cable->bUseSubstepping = true;
    Cable->bEnableStiffness = true;
    Cable->bEnableCollision = false;
    Cable->bAttachStart = true;
    Cable->bAttachEnd = true;
    Cable->EndLocation = FVector::ZeroVector;
    Cable->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    Cable->SetVisibility(false);
    // Cable allocates NumSegments + 1 simulation particles when it registers.
    // Changing NumSegments after RegisterComponent leaves the particle array at
    // the old size and causes an out-of-bounds access in UCableComponent::TickComponent.
    Cable->RegisterComponent();
    Cable->SetRelativeLocation(GunVisualActor ? FVector::ZeroVector : MuzzleOffset);
}

void UJMHarpoonGunComponent::DestroyPresentation()
{
    if (Cable)
    {
        Cable->DestroyComponent();
        Cable = nullptr;
    }

    if (GunVisualActor)
    {
        GunVisualActor->Destroy();
        GunVisualActor = nullptr;
    }
}

void UJMHarpoonGunComponent::ShowCable(bool bShow)
{
    if (Cable)
    {
        Cable->SetVisibility(bShow, true);
    }
}

void UJMHarpoonGunComponent::AttachCableToActiveProjectile(float InitialLength)
{
    if (!Cable || !IsValid(ActiveProjectile))
    {
        return;
    }

    USceneComponent* CableEnd = ActiveProjectile->GetCableAnchor();
    Cable->EndLocation = FVector::ZeroVector;
    Cable->SetAttachEndToComponent(CableEnd ? CableEnd : ActiveProjectile->GetRootComponent());
    Cable->CableLength = FMath::Max(100.0f, InitialLength);
}

bool UJMHarpoonGunComponent::HasHarpoonSafetyViolation() const
{
    if (!IsValid(ActiveProjectile))
    {
        return true;
    }

    const FVector ProjectileLocation = ActiveProjectile->GetActorLocation();
    const FVector MuzzleLocation = GetMuzzleLocation();
    if (ProjectileLocation.ContainsNaN() || MuzzleLocation.ContainsNaN())
    {
        return true;
    }

    const float SafeMaxDistance = FMath::Max(FailSafeMaxDistance, MaxRange * 1.5f);
    if (FVector::DistSquared(ProjectileLocation, MuzzleLocation) > FMath::Square(SafeMaxDistance))
    {
        return true;
    }

    if (ProjectileLocation.Z < MuzzleLocation.Z - FailSafeMaxVerticalDrop)
    {
        return true;
    }

    if (const AWorldSettings* WorldSettings = GetWorld() ? GetWorld()->GetWorldSettings() : nullptr)
    {
        if (ProjectileLocation.Z <= WorldSettings->KillZ + FailSafeKillZMargin)
        {
            return true;
        }
    }

    return false;
}

void UJMHarpoonGunComponent::BeginEmergencyReturn()
{
    EndPlayerGrapple(EJMPlayerGrappleEndReason::InvalidAnchor);

    if (!GetWorld() || !GetOwner() || !ProjectileClass)
    {
        ResetHarpoon();
        return;
    }

    const bool bRecallAlreadyStarted = State == EJMHarpoonGunState::Retracting;
    const float PreservedRecallElapsed = RecallElapsed;
    AJMHarpoonProjectile* LostProjectile = ActiveProjectile;
    ActiveProjectile = nullptr;
    if (IsValid(LostProjectile))
    {
        LostProjectile->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
        LostProjectile->Destroy();
    }

    EmbeddedComponent = nullptr;
    EmbeddedBone = NAME_None;
    EmbeddedLocalPoint = FVector::ZeroVector;
    bPullingPhysicsTarget = false;

    const FVector MuzzleLocation = GetMuzzleLocation();
    FVector ViewLocation;
    FVector ViewDirection;
    if (!GetView(ViewLocation, ViewDirection) || ViewDirection.ContainsNaN())
    {
        ViewDirection = GetOwner()->GetActorForwardVector();
    }
    ViewDirection = ViewDirection.GetSafeNormal(SMALL_NUMBER, FVector::ForwardVector);
    const FVector RecoveryLocation = MuzzleLocation
        + ViewDirection * FailSafeRecoveryDistance
        + FVector::DownVector * FMath::Min(75.0f, FailSafeRecoveryDistance * 0.15f);
    const FRotator RecoveryRotation = (MuzzleLocation - RecoveryLocation).Rotation();

    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = GetOwner();
    SpawnParams.Instigator = Cast<APawn>(GetOwner());
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    ActiveProjectile = GetWorld()->SpawnActor<AJMHarpoonProjectile>(
        ProjectileClass,
        RecoveryLocation,
        RecoveryRotation,
        SpawnParams);

    if (!ActiveProjectile)
    {
        // The visible loaded preview is the final fallback if actor spawning is
        // unavailable during world shutdown or level transition.
        ResetHarpoon();
        return;
    }

    if (GunVisualActor && GunVisualActor->GetMuzzlePoint())
    {
        ActiveProjectile->SetActorScale3D(GunVisualActor->GetMuzzlePoint()->GetComponentScale());
    }
    ActiveProjectile->BeginFreeReturn();

    RecallElapsed = bRecallAlreadyStarted ? PreservedRecallElapsed : 0.0f;
    RecallStartDistance = FVector::Distance(MuzzleLocation, RecoveryLocation);
    FreeReturnElapsed = 0.0f;
    FreeReturnPhaseElapsed = 0.0f;
    FreeReturnVelocity = FVector::ZeroVector;
    FreeReturnGroundNormal = FVector::UpVector;
    bFreeReturnGrounded = false;
    bFreeReturnFinalLift = true;
    bDeadlineRecoveryTriggered = true;
    State = EJMHarpoonGunState::Retracting;

    ShowCable(true);
    AttachCableToActiveProjectile(RecallStartDistance);
    if (!bRecallAlreadyStarted)
    {
        OnHarpoonRecallStarted.Broadcast(ActiveProjectile);
    }
}

void UJMHarpoonGunComponent::ForceCompleteReturnAtDeadline()
{
    EmbeddedComponent = nullptr;
    EmbeddedBone = NAME_None;
    EmbeddedLocalPoint = FVector::ZeroVector;
    bPullingPhysicsTarget = false;

    if (IsValid(ActiveProjectile))
    {
        ActiveProjectile->BeginFreeReturn();
        ActiveProjectile->SetActorLocationAndRotation(
            GetMuzzleLocation(),
            GetOwner() ? GetOwner()->GetActorForwardVector().Rotation() : FRotator::ZeroRotator,
            false,
            nullptr,
            ETeleportType::TeleportPhysics);
    }

    CompleteReturn();
}

void UJMHarpoonGunComponent::UpdateFailSafeSmoke()
{
#if UE_BUILD_SHIPPING
    return;
#else
    const bool bRunLostProjectileSmoke = FParse::Param(
        FCommandLine::Get(),
        TEXT("JMHarpoonFailSafeSmoke"));
    const bool bRunDeadlineSmoke = FParse::Param(
        FCommandLine::Get(),
        TEXT("JMHarpoonDeadlineSmoke"));
    if ((!bRunLostProjectileSmoke && !bRunDeadlineSmoke) || bFailSafeSmokeCompleted)
    {
        return;
    }

    if (!bFailSafeSmokeStarted && State == EJMHarpoonGunState::Ready)
    {
        if (FireHarpoon() && IsValid(ActiveProjectile))
        {
            if (bRunDeadlineSmoke)
            {
                // Make ordinary return impossible within the test deadline.
                // The hard deadline must perform the final state recovery.
                MaxRecallDuration = 0.75f;
                RecallDeadlineLeadTime = 0.25f;
                ReelSpeed = 100.0f;
                const FVector FarLocation = GetMuzzleLocation()
                    + GetOwner()->GetActorForwardVector().GetSafeNormal() * 3000.0f;
                ActiveProjectile->SetActorLocation(FarLocation, false, nullptr, ETeleportType::TeleportPhysics);
                RecallHarpoon();
                UE_LOG(LogTemp, Display, TEXT("JM_HARPOON_DEADLINE_SMOKE: slow return started 3000 cm away"));
            }
            else
            {
                // Simulate the strongest failure mode: the world deleted the
                // projectile before the gun component could detach it.
                ActiveProjectile->Destroy();
                UE_LOG(LogTemp, Display, TEXT("JM_HARPOON_FAILSAFE_SMOKE: original projectile destroyed"));
            }
            bFailSafeSmokeStarted = true;
        }
        return;
    }

    if (bFailSafeSmokeStarted && State == EJMHarpoonGunState::Ready)
    {
        bFailSafeSmokeCompleted = true;
        if (bRunDeadlineSmoke)
        {
            UE_LOG(LogTemp, Display, TEXT("JM_HARPOON_DEADLINE_SMOKE_SUCCESS: Ready state forced before deadline"));
        }
        else
        {
            UE_LOG(LogTemp, Display, TEXT("JM_HARPOON_FAILSAFE_SMOKE_SUCCESS: replacement harpoon returned"));
        }
    }
#endif
}

void UJMHarpoonGunComponent::UpdatePlayerGrappleSmoke(float DeltaTime)
{
#if UE_BUILD_SHIPPING
    return;
#else
    if (!FParse::Param(FCommandLine::Get(), TEXT("JMHarpoonPlayerGrappleSmoke"))
        || bPlayerGrappleSmokeCompleted)
    {
        return;
    }

    if (!bPlayerGrappleSmokeStarted && State == EJMHarpoonGunState::Ready)
    {
        SetPlayerGrappleEnabled(true);
        if (!FireHarpoon() || !IsValid(ActiveProjectile))
        {
            return;
        }

        const FVector AnchorLocation = GetOwner()->GetActorLocation()
            + GetOwner()->GetActorForwardVector().GetSafeNormal() * 1000.0f
            + FVector::UpVector * 500.0f;
        ActiveProjectile->BeginFreeReturn();
        ActiveProjectile->SetActorLocation(AnchorLocation, false, nullptr, ETeleportType::TeleportPhysics);
        EmbeddedComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
        EmbeddedBone = NAME_None;
        State = EJMHarpoonGunState::Embedded;

        PlayerGrappleSmokeStartDistance = FVector::Distance(
            GetOwner()->GetActorLocation(),
            AnchorLocation);
        if (!StartPlayerGrapple())
        {
            UE_LOG(LogTemp, Error, TEXT("JM_HARPOON_PLAYER_GRAPPLE_SMOKE_FAILED: grapple did not start"));
            bPlayerGrappleSmokeCompleted = true;
            ResetHarpoon();
            return;
        }

        bPlayerGrappleSmokeStarted = true;
        PlayerGrappleSmokeElapsed = 0.0f;
        UE_LOG(
            LogTemp,
            Display,
            TEXT("JM_HARPOON_PLAYER_GRAPPLE_SMOKE: pull started at %.1f cm"),
            PlayerGrappleSmokeStartDistance);
        return;
    }

    if (!bPlayerGrappleSmokeStarted)
    {
        return;
    }

    PlayerGrappleSmokeElapsed += DeltaTime;
    const float CurrentDistance = IsValid(ActiveProjectile)
        ? FVector::Distance(GetOwner()->GetActorLocation(), ActiveProjectile->GetActorLocation())
        : BIG_NUMBER;
    if (CurrentDistance <= PlayerGrappleSmokeStartDistance - 200.0f)
    {
        UCharacterMovementComponent* TestMovement = Cast<ACharacter>(GetOwner())
            ? Cast<ACharacter>(GetOwner())->GetCharacterMovement()
            : nullptr;
        SetPlayerGrappleEnabled(false);
        const bool bMovementRestored = TestMovement
            && PlayerGrappleState == EJMPlayerGrappleState::Disabled
            && FMath::IsNearlyEqual(TestMovement->GravityScale, GrappleOriginalGravityScale)
            && FMath::IsNearlyEqual(TestMovement->MaxWalkSpeed, GrappleOriginalMaxWalkSpeed)
            && FMath::IsNearlyEqual(TestMovement->GroundFriction, GrappleOriginalGroundFriction)
            && FMath::IsNearlyEqual(
                TestMovement->BrakingFrictionFactor,
                GrappleOriginalBrakingFrictionFactor);
        if (bMovementRestored)
        {
            UE_LOG(
                LogTemp,
                Display,
                TEXT("JM_HARPOON_PLAYER_GRAPPLE_SMOKE_SUCCESS: distance %.1f -> %.1f cm, OnOff restore passed"),
                PlayerGrappleSmokeStartDistance,
                CurrentDistance);
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("JM_HARPOON_PLAYER_GRAPPLE_SMOKE_FAILED: OnOff movement restore failed"));
        }
        bPlayerGrappleSmokeCompleted = true;
        ResetHarpoon();
        return;
    }

    if (PlayerGrappleSmokeElapsed >= 2.0f
        || PlayerGrappleState != EJMPlayerGrappleState::Pulling)
    {
        UE_LOG(
            LogTemp,
            Error,
            TEXT("JM_HARPOON_PLAYER_GRAPPLE_SMOKE_FAILED: state=%d distance=%.1f cm"),
            static_cast<int32>(PlayerGrappleState),
            CurrentDistance);
        bPlayerGrappleSmokeCompleted = true;
        EndPlayerGrapple(EJMPlayerGrappleEndReason::Timeout);
        ResetHarpoon();
    }
#endif
}

void UJMHarpoonGunComponent::SmoothCableLength(float TargetLength, float DeltaTime)
{
    if (!Cable)
    {
        return;
    }

    const float SafeTargetLength = FMath::Max(100.0f, TargetLength * CableSlackMultiplier);
    Cable->CableLength = FMath::FInterpTo(
        Cable->CableLength,
        SafeTargetLength,
        DeltaTime,
        CableLengthInterpSpeed);
}

void UJMHarpoonGunComponent::UpdateFlying(float DeltaTime)
{
    if (!IsValid(ActiveProjectile))
    {
        ResetHarpoon();
        return;
    }

    const float Distance = FVector::Distance(GetMuzzleLocation(), ActiveProjectile->GetActorLocation());
    SmoothCableLength(Distance, DeltaTime);
    if (Distance >= MaxRange)
    {
        RecallHarpoon();
    }
}

void UJMHarpoonGunComponent::UpdateEmbedded(float DeltaTime)
{
    if (!IsValid(ActiveProjectile) || !IsValid(EmbeddedComponent))
    {
        if (IsValid(ActiveProjectile))
        {
            RecallHarpoon();
        }
        else
        {
            ResetHarpoon();
        }
        return;
    }

    const float Distance = FVector::Distance(GetMuzzleLocation(), ActiveProjectile->GetActorLocation());
    SmoothCableLength(Distance, DeltaTime);
    if (Distance > MaxRange * 1.25f)
    {
        RecallHarpoon();
    }
}

void UJMHarpoonGunComponent::UpdateRetracting(float DeltaTime)
{
    if (!IsValid(ActiveProjectile))
    {
        ResetHarpoon();
        return;
    }

    RecallElapsed += DeltaTime;
    const float SafeMaxRecallDuration = FMath::Max(MaxRecallDuration, 0.5f);
    if (RecallElapsed >= SafeMaxRecallDuration)
    {
        ForceCompleteReturnAtDeadline();
        return;
    }

    const float SafeDeadlineLeadTime = FMath::Clamp(
        RecallDeadlineLeadTime,
        0.1f,
        SafeMaxRecallDuration);
    if (!bDeadlineRecoveryTriggered
        && RecallElapsed >= SafeMaxRecallDuration - SafeDeadlineLeadTime)
    {
        BeginEmergencyReturn();
        return;
    }

    const FVector MuzzleLocation = GetMuzzleLocation();

    if (bPullingPhysicsTarget && IsValid(EmbeddedComponent) && EmbeddedComponent->IsSimulatingPhysics(EmbeddedBone))
    {
        const FVector GrabPoint = EmbeddedComponent->GetComponentTransform().TransformPosition(EmbeddedLocalPoint);
        const FVector Error = MuzzleLocation - GrabPoint;
        const float Distance = Error.Size();
        const FVector PullDirection = Error.GetSafeNormal();
        const FVector PointVelocity = EmbeddedComponent->GetPhysicsLinearVelocityAtPoint(GrabPoint, EmbeddedBone);
        const float TargetSurfaceDistance = GetPhysicsTargetSurfaceDistance(MuzzleLocation, GrabPoint);

        if (TargetSurfaceDistance <= PhysicsReleaseDistance)
        {
            ApplyPhysicsReleaseBraking(GrabPoint, PullDirection);
            DetachForFreeReturn();
            BeginFinalReturnLift();
            return;
        }

        // Pull toward a safe sphere in front of the player, not all the way to
        // the muzzle. The spring error approaches zero near the release radius,
        // which creates a natural soft-catch zone instead of an overshoot.
        const FVector SoftCatchError = PullDirection * (Distance - PhysicsReleaseDistance);
        const FVector RequestedForce = SoftCatchError * PullStrength - PointVelocity * PullDamping;
        EmbeddedComponent->AddForceAtLocation(RequestedForce.GetClampedToMaxSize(MaxPullForce), GrabPoint, EmbeddedBone);
        SmoothCableLength(Distance, DeltaTime);

        if (RecallElapsed >= HeavyTargetTimeout && RecallStartDistance - Distance < MinimumRecallProgress)
        {
            DetachForFreeReturn();
        }
        return;
    }

    if (bPullingPhysicsTarget)
    {
        DetachForFreeReturn();
    }

    const FVector CurrentLocation = ActiveProjectile->GetActorLocation();
    const FVector ToMuzzle = MuzzleLocation - CurrentLocation;
    const float Distance = ToMuzzle.Size();
    FreeReturnElapsed += DeltaTime;

    if (!bFreeReturnFinalLift && Distance <= ReturnGroundLiftDistance)
    {
        BeginFinalReturnLift();
    }

    if (bFreeReturnFinalLift)
    {
        FreeReturnPhaseElapsed += DeltaTime;
        const FVector DesiredReturnVelocity = ToMuzzle.GetSafeNormal() * ReelSpeed;
        const float SafeBlendTime = FMath::Max(ReturnGravityFadeTime, KINDA_SMALL_NUMBER);
        const float LiftAlpha = FMath::Clamp(FreeReturnPhaseElapsed / SafeBlendTime, 0.0f, 1.0f);
        const float LiftResponsiveness = ReturnHomingResponsiveness * FMath::Lerp(0.35f, 1.0f, LiftAlpha);
        FreeReturnVelocity = FMath::VInterpTo(
            FreeReturnVelocity,
            DesiredReturnVelocity,
            DeltaTime,
            LiftResponsiveness).GetClampedToMaxSize(ReelSpeed);

        const FVector NewLocation = CurrentLocation + FreeReturnVelocity * DeltaTime;
        const FRotator ReturnRotation = FreeReturnVelocity.GetSafeNormal(SMALL_NUMBER, ToMuzzle.GetSafeNormal()).Rotation();
        ActiveProjectile->SetActorLocationAndRotation(NewLocation, ReturnRotation);
        SmoothCableLength(Distance, DeltaTime);

        if (FMath::PointDistToSegment(MuzzleLocation, CurrentLocation, NewLocation) <= CatchDistance)
        {
            ActiveProjectile->SetActorLocation(MuzzleLocation);
            CompleteReturn();
        }
        return;
    }

    if (bFreeReturnGrounded)
    {
        if (Distance <= ReturnGroundLiftDistance)
        {
            BeginFinalReturnLift();
            return;
        }

        const FVector SafeGroundNormal = FreeReturnGroundNormal.GetSafeNormal(SMALL_NUMBER, FVector::UpVector);
        const FVector GroundDirection = FVector::VectorPlaneProject(ToMuzzle, SafeGroundNormal).GetSafeNormal();
        if (GroundDirection.IsNearlyZero())
        {
            BeginFinalReturnLift();
            return;
        }

        const FVector GroundVelocity = FVector::VectorPlaneProject(FreeReturnVelocity, SafeGroundNormal);
        const FVector DesiredGroundVelocity = GroundDirection * ReturnGroundDragSpeed;
        FreeReturnVelocity = FMath::VInterpTo(
            GroundVelocity,
            DesiredGroundVelocity,
            DeltaTime,
            ReturnGroundDragResponsiveness).GetClampedToMaxSize(ReturnGroundDragSpeed);

        const FVector CandidateLocation = CurrentLocation + FreeReturnVelocity * DeltaTime;
        FHitResult GroundHit;
        if (FindFreeReturnGroundBelow(CandidateLocation, GroundHit))
        {
            FreeReturnGroundNormal = FMath::VInterpTo(
                SafeGroundNormal,
                GroundHit.ImpactNormal,
                DeltaTime,
                ReturnGroundNormalResponsiveness).GetSafeNormal(SMALL_NUMBER, GroundHit.ImpactNormal);
            const FVector TargetGroundLocation = GroundHit.ImpactPoint + FreeReturnGroundNormal * ReturnGroundClearance;
            FVector NewLocation = TargetGroundLocation;
            NewLocation.Z = FMath::FInterpTo(
                CurrentLocation.Z,
                TargetGroundLocation.Z,
                DeltaTime,
                ReturnGroundHeightResponsiveness);
            const FVector SurfaceDirection = FVector::VectorPlaneProject(
                MuzzleLocation - NewLocation,
                FreeReturnGroundNormal).GetSafeNormal(SMALL_NUMBER, GroundDirection);
            const FRotator GroundRotation = FRotationMatrix::MakeFromXZ(
                SurfaceDirection,
                FreeReturnGroundNormal).Rotator();
            ActiveProjectile->SetActorLocationAndRotation(NewLocation, GroundRotation);
        }
        else
        {
            // The floor ended. Carry the horizontal drag velocity over the edge
            // and resume falling until another usable surface is found.
            bFreeReturnGrounded = false;
            FreeReturnPhaseElapsed = 0.0f;
            FreeReturnGroundNormal = FVector::UpVector;
            FreeReturnVelocity.Z = -ReturnInitialDropSpeed;
            ActiveProjectile->SetActorLocationAndRotation(
                CandidateLocation,
                FreeReturnVelocity.GetSafeNormal(SMALL_NUMBER, GroundDirection).Rotation());
        }

        SmoothCableLength(Distance, DeltaTime);
        return;
    }

    // Kinematic ground search: the spear falls under procedural gravity while
    // retaining a modest horizontal pull. A sphere sweep detects the floor,
    // avoiding full rigid-body simulation and return-path collision overhead.
    FreeReturnPhaseElapsed += DeltaTime;
    FVector HorizontalVelocity(FreeReturnVelocity.X, FreeReturnVelocity.Y, 0.0f);
    const FVector FlatToMuzzle(ToMuzzle.X, ToMuzzle.Y, 0.0f);
    const FVector DesiredHorizontalVelocity = FlatToMuzzle.GetSafeNormal() * ReturnGroundDragSpeed;
    HorizontalVelocity = FMath::VInterpTo(
        HorizontalVelocity,
        DesiredHorizontalVelocity,
        DeltaTime,
        ReturnGroundDragResponsiveness * 0.35f);
    FreeReturnVelocity.X = HorizontalVelocity.X;
    FreeReturnVelocity.Y = HorizontalVelocity.Y;
    FreeReturnVelocity.Z -= ReturnGravity * DeltaTime;
    FreeReturnVelocity = FreeReturnVelocity.GetClampedToMaxSize(ReelSpeed);

    const FVector CandidateLocation = CurrentLocation + FreeReturnVelocity * DeltaTime;
    FHitResult GroundHit;
    if (SweepFreeReturnForGround(CurrentLocation, CandidateLocation, GroundHit))
    {
        bFreeReturnGrounded = true;
        FreeReturnPhaseElapsed = 0.0f;
        FreeReturnGroundNormal = GroundHit.ImpactNormal.GetSafeNormal(SMALL_NUMBER, FVector::UpVector);
        FreeReturnVelocity = FVector::VectorPlaneProject(FreeReturnVelocity, FreeReturnGroundNormal);
        const FVector GroundedLocation = GroundHit.ImpactPoint + FreeReturnGroundNormal * ReturnGroundClearance;
        const FVector GroundDirection = FVector::VectorPlaneProject(
            MuzzleLocation - GroundedLocation,
            FreeReturnGroundNormal).GetSafeNormal(SMALL_NUMBER, GetOwner()->GetActorForwardVector());
        const FRotator GroundRotation = FRotationMatrix::MakeFromXZ(
            GroundDirection,
            FreeReturnGroundNormal).Rotator();
        ActiveProjectile->SetActorLocationAndRotation(GroundedLocation, GroundRotation);
    }
    else
    {
        const FRotator FallRotation = FreeReturnVelocity.GetSafeNormal(
            SMALL_NUMBER,
            FVector::DownVector).Rotation();
        ActiveProjectile->SetActorLocationAndRotation(CandidateLocation, FallRotation);
    }

    SmoothCableLength(Distance, DeltaTime);

    if (!bFreeReturnGrounded && FreeReturnPhaseElapsed >= ReturnGroundSearchTimeout)
    {
        BeginFinalReturnLift();
    }
}

void UJMHarpoonGunComponent::DetachForFreeReturn(bool bPreserveForwardCarry)
{
    const bool bWasEmbedded = IsValid(EmbeddedComponent);
    const FVector SeparationDirection = ActiveProjectile
        ? -ActiveProjectile->GetTravelDirection()
        : FVector::ZeroVector;
    bPullingPhysicsTarget = false;
    EmbeddedComponent = nullptr;
    EmbeddedBone = NAME_None;
    FreeReturnElapsed = 0.0f;
    FreeReturnPhaseElapsed = 0.0f;
    bFreeReturnGrounded = false;
    bFreeReturnFinalLift = false;
    FreeReturnGroundNormal = FVector::UpVector;
    if (ActiveProjectile)
    {
        const FVector ForwardCarry = bPreserveForwardCarry
            ? ActiveProjectile->GetTravelDirection() * ReturnForwardCarrySpeed
            : FVector::ZeroVector;
        FreeReturnVelocity = ForwardCarry + FVector::DownVector * ReturnInitialDropSpeed;
        ActiveProjectile->BeginFreeReturn();
        if (bWasEmbedded && ReturnSeparationDistance > 0.0f)
        {
            ActiveProjectile->AddActorWorldOffset(
                SeparationDirection.GetSafeNormal() * ReturnSeparationDistance,
                false,
                nullptr,
                ETeleportType::TeleportPhysics);
        }
    }
}

void UJMHarpoonGunComponent::BeginFinalReturnLift()
{
    bFreeReturnGrounded = false;
    bFreeReturnFinalLift = true;
    FreeReturnPhaseElapsed = 0.0f;
}

bool UJMHarpoonGunComponent::SweepFreeReturnForGround(
    const FVector& Start,
    const FVector& End,
    FHitResult& OutHit) const
{
    if (!GetWorld() || !ActiveProjectile)
    {
        return false;
    }

    FCollisionQueryParams QueryParams(SCENE_QUERY_STAT(JMHarpoonReturnGroundSweep), false, ActiveProjectile);
    QueryParams.AddIgnoredActor(GetOwner());
    FCollisionObjectQueryParams ObjectParams;
    ObjectParams.AddObjectTypesToQuery(ECC_WorldStatic);
    ObjectParams.AddObjectTypesToQuery(ECC_WorldDynamic);
    ObjectParams.AddObjectTypesToQuery(ECC_PhysicsBody);
    const FCollisionShape GroundShape = FCollisionShape::MakeSphere(ReturnGroundClearance);
    if (!GetWorld()->SweepSingleByObjectType(
        OutHit,
        Start,
        End,
        FQuat::Identity,
        ObjectParams,
        GroundShape,
        QueryParams))
    {
        return false;
    }

    if (OutHit.bStartPenetrating && OutHit.ImpactNormal.Z >= ReturnMinimumGroundNormalZ)
    {
        FHitResult RecoveredFloorHit;
        if (FindFreeReturnGroundBelow(Start, RecoveredFloorHit))
        {
            OutHit = RecoveredFloorHit;
        }
    }

    return OutHit.ImpactNormal.Z >= ReturnMinimumGroundNormalZ;
}

bool UJMHarpoonGunComponent::FindFreeReturnGroundBelow(
    const FVector& Location,
    FHitResult& OutHit) const
{
    if (!GetWorld() || !ActiveProjectile)
    {
        return false;
    }

    const FVector TraceStart = Location + FVector::UpVector * ReturnGroundStepHeight;
    const FVector TraceEnd = Location - FVector::UpVector * ReturnGroundProbeDistance;
    FCollisionQueryParams QueryParams(SCENE_QUERY_STAT(JMHarpoonReturnGroundFollow), false, ActiveProjectile);
    QueryParams.AddIgnoredActor(GetOwner());
    FCollisionObjectQueryParams ObjectParams;
    ObjectParams.AddObjectTypesToQuery(ECC_WorldStatic);
    ObjectParams.AddObjectTypesToQuery(ECC_WorldDynamic);
    ObjectParams.AddObjectTypesToQuery(ECC_PhysicsBody);
    if (!GetWorld()->LineTraceSingleByObjectType(
        OutHit,
        TraceStart,
        TraceEnd,
        ObjectParams,
        QueryParams))
    {
        return false;
    }

    return OutHit.ImpactNormal.Z >= ReturnMinimumGroundNormalZ;
}

float UJMHarpoonGunComponent::GetPhysicsTargetSurfaceDistance(
    const FVector& FromLocation,
    const FVector& GrabPoint) const
{
    float Result = FVector::Distance(FromLocation, GrabPoint);
    if (!IsValid(EmbeddedComponent))
    {
        return Result;
    }

    FVector ClosestPoint;
    const float ClosestDistance = EmbeddedComponent->GetClosestPointOnCollision(
        FromLocation,
        ClosestPoint,
        EmbeddedBone);
    if (ClosestDistance >= 0.0f)
    {
        Result = FMath::Min(Result, ClosestDistance);
    }
    return Result;
}

void UJMHarpoonGunComponent::ApplyPhysicsReleaseBraking(
    const FVector& GrabPoint,
    const FVector& PullDirection) const
{
    if (!IsValid(EmbeddedComponent) || ReleaseBraking <= 0.0f)
    {
        return;
    }

    const FVector PointVelocity = EmbeddedComponent->GetPhysicsLinearVelocityAtPoint(GrabPoint, EmbeddedBone);
    const float InwardSpeed = FVector::DotProduct(PointVelocity, PullDirection);
    if (InwardSpeed <= 0.0f)
    {
        return;
    }

    const float TargetMass = EmbeddedComponent->GetMass();
    const FVector BrakingImpulse = -PullDirection * InwardSpeed * TargetMass * ReleaseBraking;
    EmbeddedComponent->AddImpulseAtLocation(BrakingImpulse, GrabPoint, EmbeddedBone);
}

void UJMHarpoonGunComponent::CompleteReturn()
{
    AJMHarpoonProjectile* ReturnedProjectile = ActiveProjectile;
    OnHarpoonReturned.Broadcast(ReturnedProjectile);
    if (ReturnedProjectile)
    {
        ReturnedProjectile->Destroy();
    }

    ActiveProjectile = nullptr;
    EmbeddedComponent = nullptr;
    EmbeddedBone = NAME_None;
    EmbeddedLocalPoint = FVector::ZeroVector;
    FreeReturnElapsed = 0.0f;
    FreeReturnPhaseElapsed = 0.0f;
    FreeReturnVelocity = FVector::ZeroVector;
    FreeReturnGroundNormal = FVector::UpVector;
    bPullingPhysicsTarget = false;
    bFreeReturnGrounded = false;
    bFreeReturnFinalLift = false;
    bDeadlineRecoveryTriggered = false;
    State = EJMHarpoonGunState::Ready;
    CooldownRemaining = FireCooldown;
    RecoilAlpha = 0.35f;
    ShowCable(false);
}

void UJMHarpoonGunComponent::UpdatePresentation(float DeltaTime)
{
    RecoilAlpha = FMath::FInterpTo(RecoilAlpha, 0.0f, DeltaTime, 14.0f);
    if (GunVisualActor)
    {
        GunVisualActor->SetActorRelativeLocation(GunVisualOffset + FVector(-RecoilDistance * RecoilAlpha, 0.0f, 0.0f));
    }

    const bool bShowLoadedHarpoon = State == EJMHarpoonGunState::Ready;
    if (GunVisualActor)
    {
        GunVisualActor->SetLoadedHarpoonVisible(bShowLoadedHarpoon);
    }

    const bool bShouldRotateWinch = State == EJMHarpoonGunState::Flying
        || State == EJMHarpoonGunState::Retracting;
    if (GunVisualActor && bShouldRotateWinch)
    {
        const float Direction = State == EJMHarpoonGunState::Retracting ? -1.0f : 1.0f;
        WinchAngle = FMath::Fmod(WinchAngle + Direction * DeltaTime * 720.0f, 360.0f);
        GunVisualActor->SetWinchAngle(WinchAngle);
    }
}
