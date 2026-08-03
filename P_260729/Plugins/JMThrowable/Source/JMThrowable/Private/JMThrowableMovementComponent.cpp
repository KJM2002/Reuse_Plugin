#include "JMThrowableMovementComponent.h"
#include "JMThrowSolver.h"
#include "JMThrowableProjectile.h"
#include "DrawDebugHelpers.h"

UJMThrowableMovementComponent::UJMThrowableMovementComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = false;
}

void UJMThrowableMovementComponent::Launch(const FJMThrowParameters& InParameters)
{
    Parameters = InParameters;
    // The manual sphere sweep must ignore the projectile's own collision shape.
    // Without this, the first fixed step can immediately hit the owning actor and rest.
    Parameters.IgnoredActors.AddUnique(GetOwner());
    SimulationState = FJMThrowSimulationState();
    SimulationState.Position = GetOwner()->GetActorLocation();
    SimulationState.Velocity = Parameters.InitialVelocity;
    Velocity = Parameters.InitialVelocity;
    Accumulator = 0.f;
    State = EJMThrowableProjectileState::Flying;
    SetComponentTickEnabled(true);
}

void UJMThrowableMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* Tick)
{
    Super::TickComponent(DeltaTime, TickType, Tick);
    if (State != EJMThrowableProjectileState::Flying || !GetWorld()) return;
    Accumulator += DeltaTime;
    const float StepSize = FMath::Max(Parameters.SimulationStep, KINDA_SMALL_NUMBER);
    while (Accumulator >= StepSize && State == EJMThrowableProjectileState::Flying)
    {
        FHitResult Hit;
        const int32 PreviousBounces = SimulationState.WallBounceCount;
        const int32 PreviousFloorBounces = SimulationState.FloorBounceCount;
        FJMThrowSolver::Step(GetWorld(), Parameters, SimulationState, &Hit);
#if !UE_BUILD_SHIPPING
        if (Parameters.bDebugDraw)
        {
            DrawDebugLine(GetWorld(), GetOwner()->GetActorLocation(), SimulationState.Position, FColor::Cyan, false, 1.f, 0, 1.f);
            if (Hit.bBlockingHit)
            {
                DrawDebugDirectionalArrow(GetWorld(), Hit.ImpactPoint,
                    Hit.ImpactPoint + Hit.ImpactNormal * 50.f, 12.f, FColor::Yellow, false, 2.f, 0, 2.f);
                UE_LOG(LogTemp, Log, TEXT("JMThrowable impact: Surface=%d Bounce=%d Velocity=%s"),
                    static_cast<int32>(FJMThrowSolver::ClassifySurface(Hit.ImpactNormal, Parameters.FloorNormalThreshold)),
                    SimulationState.WallBounceCount, *SimulationState.Velocity.ToCompactString());
            }
        }
#endif
        GetOwner()->SetActorLocation(SimulationState.Position);
        GetOwner()->AddActorLocalRotation(Parameters.VisualSpinDegreesPerSecond * StepSize);
        Velocity = SimulationState.Velocity;
        if (Hit.bBlockingHit && SimulationState.bResting) Rest(Hit);
        else if (Hit.bBlockingHit
            && (SimulationState.WallBounceCount > PreviousBounces
                || SimulationState.FloorBounceCount > PreviousFloorBounces))
            if (AJMThrowableProjectile* P = Cast<AJMThrowableProjectile>(GetOwner())) P->NotifyMovementBounced(Hit);
        if (SimulationState.ElapsedTime >= Parameters.MaximumSimulationTime && State == EJMThrowableProjectileState::Flying)
            Rest(Hit);
        Accumulator -= StepSize;
    }
}

void UJMThrowableMovementComponent::Rest(const FHitResult& Hit)
{
    State = EJMThrowableProjectileState::Resting;
    Velocity = FVector::ZeroVector;
    SetComponentTickEnabled(false);
    if (AJMThrowableProjectile* P = Cast<AJMThrowableProjectile>(GetOwner())) P->NotifyMovementRested(Hit);
}
