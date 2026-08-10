#include "Components/JMHarpoonGunComponent.h"

#include "Actors/JMHarpoonGunVisualActor.h"
#include "Actors/JMHarpoonProjectile.h"
#include "CableComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Components/SceneComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"

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
    EnsurePresentation();
}

void UJMHarpoonGunComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
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

    UpdatePresentation(DeltaTime);
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
    if (Cable)
    {
        USceneComponent* CableEnd = ActiveProjectile->GetCableAnchor();
        Cable->EndLocation = FVector::ZeroVector;
        Cable->SetAttachEndToComponent(CableEnd ? CableEnd : ActiveProjectile->GetRootComponent());
        Cable->CableLength = 100.0f;
    }

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

    const bool bWasFlying = State == EJMHarpoonGunState::Flying;
    RecallElapsed = 0.0f;
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
