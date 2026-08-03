#include "JMThrowSolver.h"
#include "Engine/World.h"

FVector FJMThrowSolver::CalculatePreviewVisualOrigin(
    const FVector& ViewLocation,
    const FVector& ViewForward,
    float PreviewStartDistance)
{
    return ViewLocation + ViewForward.GetSafeNormal() * FMath::Max(0.f, PreviewStartDistance);
}

FVector FJMThrowSolver::CalculateLaunchVelocity(
    const FVector& ViewForward,
    float ThrowSpeed,
    float VerticalThrowBoost)
{
    return ViewForward.GetSafeNormal() * FMath::Max(0.f, ThrowSpeed)
        + FVector::UpVector * FMath::Max(0.f, VerticalThrowBoost);
}

float FJMThrowSolver::CalculateFlowWidth(float BaseWidth, float FlowWidthMultiplier)
{
    return FMath::Max(0.f, BaseWidth) * FMath::Clamp(FlowWidthMultiplier, 0.f, 1.f);
}

TArray<FVector> FJMThrowSolver::ResamplePathByDistance(
    const TArray<FVector>& Points,
    int32 SampleCount)
{
    TArray<FVector> Result;
    if (Points.IsEmpty() || SampleCount <= 0)
    {
        return Result;
    }

    SampleCount = FMath::Max(2, SampleCount);
    Result.Reserve(SampleCount);
    if (Points.Num() == 1)
    {
        Result.Init(Points[0], SampleCount);
        return Result;
    }

    TArray<float> CumulativeDistances;
    CumulativeDistances.Reserve(Points.Num());
    CumulativeDistances.Add(0.f);
    for (int32 Index = 1; Index < Points.Num(); ++Index)
    {
        CumulativeDistances.Add(
            CumulativeDistances.Last() + FVector::Distance(Points[Index - 1], Points[Index]));
    }

    const float TotalDistance = CumulativeDistances.Last();
    if (TotalDistance <= KINDA_SMALL_NUMBER)
    {
        Result.Init(Points[0], SampleCount);
        Result.Last() = Points.Last();
        return Result;
    }

    int32 SegmentIndex = 1;
    for (int32 SampleIndex = 0; SampleIndex < SampleCount; ++SampleIndex)
    {
        if (SampleIndex == 0)
        {
            Result.Add(Points[0]);
            continue;
        }
        if (SampleIndex == SampleCount - 1)
        {
            Result.Add(Points.Last());
            continue;
        }

        const float TargetDistance =
            TotalDistance * static_cast<float>(SampleIndex) / static_cast<float>(SampleCount - 1);
        while (SegmentIndex + 1 < CumulativeDistances.Num()
            && CumulativeDistances[SegmentIndex] < TargetDistance)
        {
            ++SegmentIndex;
        }
        const float SegmentStartDistance = CumulativeDistances[SegmentIndex - 1];
        const float SegmentLength =
            CumulativeDistances[SegmentIndex] - SegmentStartDistance;
        const float Alpha = SegmentLength > KINDA_SMALL_NUMBER
            ? (TargetDistance - SegmentStartDistance) / SegmentLength
            : 0.f;
        Result.Add(FMath::Lerp(Points[SegmentIndex - 1], Points[SegmentIndex], Alpha));
    }
    return Result;
}

FVector FJMThrowSolver::ResolveWallBounce(const FVector& Velocity, const FVector& Normal, float Restitution, float TangentialDamping)
{
    const FVector N = Normal.GetSafeNormal();
    const FVector NormalVelocity = FVector::DotProduct(Velocity, N) * N;
    const FVector TangentialVelocity = Velocity - NormalVelocity;
    return (-NormalVelocity * FMath::Clamp(Restitution, 0.f, 1.f))
        + (TangentialVelocity * FMath::Clamp(TangentialDamping, 0.f, 1.f));
}

FVector FJMThrowSolver::ResolveFloorBounce(
    const FVector& Velocity,
    const FVector& Normal,
    float Restitution,
    float TangentialDamping,
    float BounceDecay,
    int32 CompletedFloorBounces)
{
    const float Decay = FMath::Pow(
        FMath::Clamp(BounceDecay, 0.f, 1.f),
        FMath::Max(0, CompletedFloorBounces));
    return ResolveWallBounce(
        Velocity,
        Normal,
        FMath::Clamp(Restitution, 0.f, 1.f) * Decay,
        TangentialDamping);
}

bool FJMThrowSolver::ShouldFloorBounce(
    float IncomingNormalSpeed,
    int32 BounceCount,
    int32 MaxBounceCount,
    float StopSpeed)
{
    return BounceCount < MaxBounceCount
        && IncomingNormalSpeed >= FMath::Max(0.f, StopSpeed);
}

EJMThrowableSurfaceType FJMThrowSolver::ClassifySurface(const FVector& Normal, float FloorNormalThreshold)
{
    const float UpDot = FVector::DotProduct(Normal.GetSafeNormal(), FVector::UpVector);
    if (UpDot >= FloorNormalThreshold) return EJMThrowableSurfaceType::Floor;
    if (UpDot <= -FloorNormalThreshold) return EJMThrowableSurfaceType::Ceiling;
    if (FMath::Abs(UpDot) <= .25f) return EJMThrowableSurfaceType::Wall;
    return EJMThrowableSurfaceType::Slope;
}

bool FJMThrowSolver::ShouldBounce(EJMThrowableSurfaceType Surface, int32 BounceCount, int32 MaxBounceCount)
{
    return Surface != EJMThrowableSurfaceType::Floor && BounceCount < MaxBounceCount;
}

bool FJMThrowSolver::Step(UWorld* World, const FJMThrowParameters& P, FJMThrowSimulationState& State, FHitResult* OutHit)
{
    if (!World || State.bResting) return false;
    const float Dt = FMath::Max(P.SimulationStep, KINDA_SMALL_NUMBER);
    const FVector NewVelocity = State.Velocity + P.Gravity * Dt;
    const FVector End = State.Position + (State.Velocity + NewVelocity) * (.5f * Dt);
    FCollisionQueryParams Query(SCENE_QUERY_STAT(JMThrowableSolver), false);
    for (AActor* Ignored : P.IgnoredActors) if (IsValid(Ignored)) Query.AddIgnoredActor(Ignored);
    FCollisionShape Shape = FCollisionShape::MakeSphere(FMath::Max(.1f, P.ProjectileRadius));
    FHitResult Hit;
    const bool bHit = World->SweepSingleByProfile(Hit, State.Position, End, FQuat::Identity, P.CollisionProfile, Shape, Query);
    State.ElapsedTime += Dt;
    if (!bHit)
    {
        State.Position = End;
        State.Velocity = NewVelocity;
        return true;
    }
    State.Position = Hit.ImpactPoint + Hit.ImpactNormal.GetSafeNormal() * (P.ProjectileRadius + P.SurfaceOffset);
    if (OutHit) *OutHit = Hit;
    const EJMThrowableSurfaceType Surface = ClassifySurface(Hit.ImpactNormal, P.FloorNormalThreshold);
    if (Surface == EJMThrowableSurfaceType::Floor)
    {
        const FVector SurfaceNormal = Hit.ImpactNormal.GetSafeNormal();
        const float IncomingNormalSpeed = FMath::Max(
            0.f,
            -FVector::DotProduct(NewVelocity, SurfaceNormal));
        if (ShouldFloorBounce(
            IncomingNormalSpeed,
            State.FloorBounceCount,
            P.MaxFloorBounces,
            P.FloorBounceStopSpeed))
        {
            State.Velocity = ResolveFloorBounce(
                NewVelocity,
                SurfaceNormal,
                P.FloorRestitution,
                P.FloorTangentialDamping,
                P.FloorBounceDecay,
                State.FloorBounceCount);
            ++State.FloorBounceCount;
            return true;
        }

        const FVector FloorVelocity = FVector::VectorPlaneProject(NewVelocity, Hit.ImpactNormal) * P.FloorFriction;
        if (FloorVelocity.Size() > P.FloorStopSpeed)
        {
            State.Velocity = FloorVelocity;
            return true;
        }
        State.Velocity = FVector::ZeroVector;
        State.bResting = true;
        return false;
    }
    if (!ShouldBounce(Surface, State.WallBounceCount, P.MaxWallBounces))
    {
        State.Velocity = FVector::ZeroVector;
        State.bResting = true;
        return false;
    }
    State.Velocity = ResolveWallBounce(NewVelocity, Hit.ImpactNormal, P.BounceRestitution, P.TangentialDamping);
    ++State.WallBounceCount;
    return true;
}

FJMThrowSimulationResult FJMThrowSolver::Simulate(UWorld* World, const FJMThrowParameters& P)
{
    FJMThrowSimulationResult Result;
    FJMThrowSimulationState State;
    State.Position = P.StartPosition;
    State.Velocity = P.InitialVelocity;
    Result.Points.Add(State.Position);
    while (State.ElapsedTime < P.MaximumSimulationTime && !State.bResting)
    {
        FHitResult Hit;
        const FVector Before = State.Position;
        Step(World, P, State, &Hit);
        Result.Points.Add(State.Position);
        if (Hit.bBlockingHit)
        {
            Result.ImpactPoints.Add(Hit.ImpactPoint);
            Result.ImpactNormals.Add(Hit.ImpactNormal);
        }
        if (Before.Equals(State.Position) && !Hit.bBlockingHit) break;
    }
    Result.FinalRestPoint = State.Position;
    Result.bReachedRest = State.bResting;
    Result.WallBounceCount = State.WallBounceCount;
    Result.FloorBounceCount = State.FloorBounceCount;
    return Result;
}

FJMThrowSimulationResult FJMThrowSolver::SimulatePreview(UWorld* World, const FJMThrowParameters& P)
{
    FJMThrowSimulationResult Result;
    FJMThrowSimulationState State;
    State.Position = P.StartPosition;
    State.Velocity = P.InitialVelocity;
    Result.Points.Add(State.Position);

    while (State.ElapsedTime < P.MaximumSimulationTime && !State.bResting)
    {
        FHitResult Hit;
        const FVector Before = State.Position;
        Step(World, P, State, &Hit);
        if (Hit.bBlockingHit)
        {
            // A preview represents the contact point, not the post-sweep projectile-center
            // offset that runtime movement needs to resolve penetration.
            Result.Points.Add(Hit.ImpactPoint);
            Result.ImpactPoints.Add(Hit.ImpactPoint);
            Result.ImpactNormals.Add(Hit.ImpactNormal);
            break;
        }

        Result.Points.Add(State.Position);
        if (Before.Equals(State.Position))
        {
            break;
        }
    }

    Result.FinalRestPoint = State.Position;
    Result.bReachedRest = State.bResting;
    Result.WallBounceCount = State.WallBounceCount;
    Result.FloorBounceCount = State.FloorBounceCount;
    return Result;
}
