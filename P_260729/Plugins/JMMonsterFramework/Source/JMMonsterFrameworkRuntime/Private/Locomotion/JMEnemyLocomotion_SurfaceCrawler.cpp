#include "Locomotion/JMEnemyLocomotion_SurfaceCrawler.h"

#include "DrawDebugHelpers.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Locomotion/JMEnemyMovementSet.h"

UJMEnemyLocomotion_SurfaceCrawler::UJMEnemyLocomotion_SurfaceCrawler()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = false;
}

void UJMEnemyLocomotion_SurfaceCrawler::BeginPlay()
{
    Super::BeginPlay();
    if (ACharacter* Character = Cast<ACharacter>(GetOwner()))
    {
        Character->GetCharacterMovement()->StopMovementImmediately();
        Character->GetCharacterMovement()->SetMovementMode(MOVE_Flying);
        Character->GetCharacterMovement()->GravityScale = 0.0f;
    }
    AcquireInitialSurface();
}

void UJMEnemyLocomotion_SurfaceCrawler::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    SetComponentTickEnabled(false);
    Super::EndPlay(EndPlayReason);
}

EJMEnemyMoveRequestResult UJMEnemyLocomotion_SurfaceCrawler::MoveToActor(
    AActor* TargetActor, const FJMEnemyMoveOptions Options)
{
    if (!IsValid(TargetActor))
    {
        return Super::MoveToActor(TargetActor, Options);
    }
    return SubmitMoveRequest(TargetActor, TargetActor->GetActorLocation(), Options);
}

EJMEnemyMoveRequestResult UJMEnemyLocomotion_SurfaceCrawler::MoveToLocation(
    const FVector Destination, const FJMEnemyMoveOptions Options)
{
    return SubmitMoveRequest(nullptr, Destination, Options);
}

EJMEnemyMoveRequestResult UJMEnemyLocomotion_SurfaceCrawler::MoveAwayFromActor(
    AActor* ThreatActor, const float EscapeDistance, const FJMEnemyMoveOptions Options)
{
    FVector EscapeLocation;
    return FindEscapeLocation(ThreatActor, EscapeDistance, EscapeLocation)
        ? MoveToLocation(EscapeLocation, Options) : EJMEnemyMoveRequestResult::RequestFailed;
}

bool UJMEnemyLocomotion_SurfaceCrawler::FindEscapeLocation(
    AActor* ThreatActor, const float EscapeDistance, FVector& OutLocation) const
{
    const AActor* Owner = GetOwner();
    if (!Owner || !IsValid(ThreatActor) || EscapeDistance <= 0.0f) return false;
    FVector Away = FVector::VectorPlaneProject(
        Owner->GetActorLocation() - ThreatActor->GetActorLocation(), CurrentSurfaceNormal);
    if (!Away.Normalize())
    {
        Away = FVector::CrossProduct(CurrentSurfaceNormal, Owner->GetActorRightVector()).GetSafeNormal();
    }
    OutLocation = Owner->GetActorLocation() + Away * EscapeDistance;
    return !Away.IsNearlyZero();
}

bool UJMEnemyLocomotion_SurfaceCrawler::FindRandomReachableLocation(
    const FVector Center, const float Radius, FVector& OutLocation) const
{
    if (!GetOwner() || Radius <= 0.0f) return false;
    FVector BasisX = FVector::VectorPlaneProject(GetOwner()->GetActorForwardVector(), CurrentSurfaceNormal).GetSafeNormal();
    if (BasisX.IsNearlyZero()) BasisX = FVector::CrossProduct(CurrentSurfaceNormal, FVector::RightVector).GetSafeNormal();
    const FVector BasisY = FVector::CrossProduct(CurrentSurfaceNormal, BasisX).GetSafeNormal();
    const float Angle = FMath::FRandRange(0.0f, 2.0f * PI);
    const float Distance = FMath::FRandRange(Radius * 0.35f, Radius);
    OutLocation = Center + (BasisX * FMath::Cos(Angle) + BasisY * FMath::Sin(Angle)) * Distance;
    return true;
}

void UJMEnemyLocomotion_SurfaceCrawler::StopMovement()
{
    if (GetMoveStatus() == EJMEnemyMoveStatus::Moving)
    {
        FinishActiveMove(EJMEnemyMoveStatus::Aborted);
    }
    SetComponentTickEnabled(false);
    if (ACharacter* Character = Cast<ACharacter>(GetOwner()))
    {
        Character->GetCharacterMovement()->StopMovementImmediately();
    }
    Super::StopMovement();
}

bool UJMEnemyLocomotion_SurfaceCrawler::FaceActor(AActor* TargetActor, EJMEnemyFacingMode)
{
    if (!GetOwner() || !IsValid(TargetActor)) return false;
    DesiredFacingDirection = FVector::VectorPlaneProject(
        TargetActor->GetActorLocation() - GetOwner()->GetActorLocation(), CurrentSurfaceNormal).GetSafeNormal();
    return !DesiredFacingDirection.IsNearlyZero();
}

void UJMEnemyLocomotion_SurfaceCrawler::ClearFacingFocus()
{
    DesiredFacingDirection = DesiredMoveDirection;
}

bool UJMEnemyLocomotion_SurfaceCrawler::ApplyMovementProfile(
    const UJMEnemyMovementSet* MovementSet, const FName ProfileName)
{
    const FJMEnemyMovementProfile* Profile = MovementSet ? MovementSet->FindProfile(ProfileName) : nullptr;
    if (!Profile || !Super::ApplyMovementProfile(MovementSet, ProfileName)) return false;
    SurfaceSpeed = Profile->MaxSpeed;
    return true;
}

EJMEnemyMoveRequestResult UJMEnemyLocomotion_SurfaceCrawler::SubmitMoveRequest(
    AActor* TargetActor, const FVector& Destination, const FJMEnemyMoveOptions& Options)
{
    AActor* Owner = GetOwner();
    if (!Owner || (!TargetActor && Destination.ContainsNaN()) ||
        (TargetActor && !IsValid(TargetActor)) || (!AcquireInitialSurface() && AttachmentPoint.IsNearlyZero()))
    {
        FinishActiveMove(EJMEnemyMoveStatus::Failed);
        return EJMEnemyMoveRequestResult::RequestFailed;
    }
    ActiveAcceptanceRadius = ResolveAcceptanceRadius(Options);
    const FVector Goal = TargetActor ? TargetActor->GetActorLocation() : Destination;
    BeginBackendMove(TargetActor, Goal);
    if (FVector::Dist(Owner->GetActorLocation(), Goal) <= ActiveAcceptanceRadius)
    {
        FinishActiveMove(EJMEnemyMoveStatus::Succeeded);
        return EJMEnemyMoveRequestResult::AlreadyAtGoal;
    }
    LostSurfaceTime = 0.0f;
    SetComponentTickEnabled(true);
    return EJMEnemyMoveRequestResult::RequestStarted;
}

void UJMEnemyLocomotion_SurfaceCrawler::TickComponent(
    const float DeltaTime, const ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    AActor* Owner = GetOwner();
    if (!Owner || GetMoveStatus() != EJMEnemyMoveStatus::Moving) return;

    const FVector Goal = ResolveMoveGoal();
    UpdateBackendDestination(Goal);
    if (FVector::Dist(Owner->GetActorLocation(), Goal) <= ActiveAcceptanceRadius)
    {
        SetComponentTickEnabled(false);
        FinishActiveMove(EJMEnemyMoveStatus::Succeeded);
        return;
    }

    const FVector ToGoal = Goal - Owner->GetActorLocation();
    FVector TangentToGoal = FVector::VectorPlaneProject(ToGoal, CurrentSurfaceNormal);
    FVector Direction = TangentToGoal.GetSafeNormal();
    // If the goal lies mostly beyond the current plane, keep travelling toward the edge instead of
    // oscillating around its projection. Geometry traces will select the adjoining surface there.
    const float OffPlaneDistance = FMath::Abs(FVector::DotProduct(ToGoal, CurrentSurfaceNormal));
    if ((TangentToGoal.Size() <= ActiveAcceptanceRadius || OffPlaneDistance > ActiveAcceptanceRadius) &&
        ToGoal.Size() > ActiveAcceptanceRadius)
    {
        const FVector Continued = FVector::VectorPlaneProject(
            DesiredMoveDirection, CurrentSurfaceNormal).GetSafeNormal();
        if (!Continued.IsNearlyZero()) Direction = Continued;
    }
    if (Direction.IsNearlyZero())
    {
        SetComponentTickEnabled(false);
        FinishActiveMove(EJMEnemyMoveStatus::Failed);
        return;
    }
    DesiredMoveDirection = Direction;
    DesiredFacingDirection = Direction;
    const float Step = SurfaceSpeed * FMath::Min(DeltaTime, 0.05f);
    const FVector CurrentLocation = Owner->GetActorLocation();

    FHitResult ForwardHit;
    const FVector ForwardEnd = CurrentLocation + Direction * (Step + ForwardTransitionProbe);
    const bool bForwardHit = TraceSurface(CurrentLocation, Direction, Step + ForwardTransitionProbe, ForwardHit);
    DrawSurfaceDebug(CurrentLocation, ForwardEnd, bForwardHit ? &ForwardHit : nullptr, FColor::Yellow);
    if (bForwardHit && FVector::DotProduct(ForwardHit.ImpactNormal, CurrentSurfaceNormal) < 0.75f)
    {
        ++SurfaceTransitionCount;
        LostSurfaceTime = 0.0f;
        AttachmentPoint = ForwardHit.ImpactPoint;
        ApplySurfaceTransform(AttachmentPoint + ForwardHit.ImpactNormal * AttachmentOffset,
            ForwardHit.ImpactNormal, Direction, DeltaTime, false);
        return;
    }

    const FVector Candidate = CurrentLocation + Direction * Step;
    const FVector ProbeStart = Candidate + CurrentSurfaceNormal * 20.0f;
    FHitResult SupportHit;
    const bool bHasSupport = TraceSurface(ProbeStart, -CurrentSurfaceNormal,
        AttachmentProbeDistance + 20.0f, SupportHit);
    DrawSurfaceDebug(ProbeStart, ProbeStart - CurrentSurfaceNormal * (AttachmentProbeDistance + 20.0f),
        bHasSupport ? &SupportHit : nullptr, FColor::Green);
    if (bHasSupport)
    {
        LostSurfaceTime = 0.0f;
        AttachmentPoint = SupportHit.ImpactPoint;
        ApplySurfaceTransform(AttachmentPoint + SupportHit.ImpactNormal * AttachmentOffset,
            SupportHit.ImpactNormal, Direction, DeltaTime, true);
        return;
    }

    LostSurfaceTime += DeltaTime;
    if (LostSurfaceTime <= SurfaceLossGraceTime)
    {
        ApplySurfaceTransform(Candidate, CurrentSurfaceNormal, Direction, DeltaTime, true);
        return;
    }

    FHitResult Reacquired;
    if (ReacquireSurface(Reacquired))
    {
        LostSurfaceTime = 0.0f;
        AttachmentPoint = Reacquired.ImpactPoint;
        ApplySurfaceTransform(AttachmentPoint + Reacquired.ImpactNormal * AttachmentOffset,
            Reacquired.ImpactNormal, Direction, DeltaTime, false);
        return;
    }

    if (ACharacter* Character = Cast<ACharacter>(Owner))
    {
        Character->GetCharacterMovement()->GravityScale = 1.0f;
        Character->GetCharacterMovement()->SetMovementMode(MOVE_Falling);
    }
    SetComponentTickEnabled(false);
    FinishActiveMove(EJMEnemyMoveStatus::Failed);
}

bool UJMEnemyLocomotion_SurfaceCrawler::AcquireInitialSurface()
{
    if (!GetOwner()) return false;
    FHitResult Hit;
    if (!ReacquireSurface(Hit)) return false;
    AttachmentPoint = Hit.ImpactPoint;
    CurrentSurfaceNormal = Hit.ImpactNormal.GetSafeNormal();
    return true;
}

bool UJMEnemyLocomotion_SurfaceCrawler::TraceSurface(
    const FVector& Start, const FVector& Direction, const float Distance, FHitResult& OutHit) const
{
    const UWorld* World = GetWorld();
    if (!World || Direction.IsNearlyZero() || Distance <= 0.0f) return false;
    FCollisionQueryParams Params(SCENE_QUERY_STAT(JMSurfaceCrawler), false, GetOwner());
    return World->LineTraceSingleByChannel(OutHit, Start, Start + Direction.GetSafeNormal() * Distance,
        SurfaceTraceChannel, Params);
}

bool UJMEnemyLocomotion_SurfaceCrawler::ReacquireSurface(FHitResult& OutHit) const
{
    const AActor* Owner = GetOwner();
    if (!Owner) return false;
    const FVector Location = Owner->GetActorLocation();
    const FVector Directions[] = {-CurrentSurfaceNormal, FVector::DownVector, FVector::UpVector,
        FVector::ForwardVector, -FVector::ForwardVector, FVector::RightVector, -FVector::RightVector};
    float BestDistance = TNumericLimits<float>::Max();
    FHitResult BestHit;
    for (const FVector& Direction : Directions)
    {
        FHitResult Hit;
        if (TraceSurface(Location, Direction, AttachmentProbeDistance, Hit) && Hit.Distance < BestDistance)
        {
            BestDistance = Hit.Distance;
            BestHit = Hit;
        }
    }
    if (BestDistance == TNumericLimits<float>::Max()) return false;
    OutHit = BestHit;
    return true;
}

void UJMEnemyLocomotion_SurfaceCrawler::ApplySurfaceTransform(
    const FVector& NewLocation, const FVector& SurfaceNormal, const FVector& Forward,
    const float DeltaTime, const bool bSweep)
{
    AActor* Owner = GetOwner();
    if (!Owner || NewLocation.ContainsNaN() || SurfaceNormal.ContainsNaN()) return;
    const FVector SafeNormal = SurfaceNormal.GetSafeNormal();
    FVector SafeForward = FVector::VectorPlaneProject(Forward, SafeNormal).GetSafeNormal();
    if (SafeForward.IsNearlyZero())
    {
        SafeForward = FVector::VectorPlaneProject(Owner->GetActorForwardVector(), SafeNormal).GetSafeNormal();
    }
    const FRotator TargetRotation = FRotationMatrix::MakeFromXZ(SafeForward, SafeNormal).Rotator();
    const FRotator Rotation = FMath::RInterpTo(Owner->GetActorRotation(), TargetRotation,
        DeltaTime, RotationInterpolationSpeed);
    Owner->SetActorLocationAndRotation(NewLocation, Rotation, bSweep, nullptr, ETeleportType::None);
    CurrentSurfaceNormal = SafeNormal;
}

FVector UJMEnemyLocomotion_SurfaceCrawler::ResolveMoveGoal() const
{
    return IsValid(GetCurrentMoveTarget()) ? GetCurrentMoveTarget()->GetActorLocation() : GetCurrentDestination();
}

void UJMEnemyLocomotion_SurfaceCrawler::DrawSurfaceDebug(
    const FVector& TraceStart, const FVector& TraceEnd, const FHitResult* Hit, const FColor& Color) const
{
#if ENABLE_DRAW_DEBUG
    if (!bDrawSurfaceDebug || !GetWorld()) return;
    DrawDebugLine(GetWorld(), TraceStart, TraceEnd, Color, false, 0.0f, 0, 1.5f);
    if (Hit && Hit->bBlockingHit)
    {
        DrawDebugDirectionalArrow(GetWorld(), Hit->ImpactPoint,
            Hit->ImpactPoint + Hit->ImpactNormal * 80.0f, 20.0f, FColor::Cyan, false, 0.0f, 0, 2.0f);
    }
#endif
}
