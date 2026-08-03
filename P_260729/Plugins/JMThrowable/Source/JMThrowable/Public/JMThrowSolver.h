#pragma once

#include "CoreMinimal.h"
#include "JMThrowableTypes.h"

class JMTHROWABLE_API FJMThrowSolver
{
public:
    static FJMThrowSimulationResult Simulate(UWorld* World, const FJMThrowParameters& Parameters);
    /** Uses the shared fixed-step solver but stops visual prediction at the first blocking hit. */
    static FJMThrowSimulationResult SimulatePreview(UWorld* World, const FJMThrowParameters& Parameters);
    static FVector CalculatePreviewVisualOrigin(const FVector& ViewLocation, const FVector& ViewForward, float PreviewStartDistance);
    static FVector CalculateLaunchVelocity(const FVector& ViewForward, float ThrowSpeed, float VerticalThrowBoost);
    static float CalculateFlowWidth(float BaseWidth, float FlowWidthMultiplier);
    /** Returns a fixed-size, distance-uniform path while preserving both endpoints exactly. */
    static TArray<FVector> ResamplePathByDistance(const TArray<FVector>& Points, int32 SampleCount);
    static bool Step(UWorld* World, const FJMThrowParameters& Parameters, FJMThrowSimulationState& State, FHitResult* OutHit = nullptr);
    static FVector ResolveWallBounce(const FVector& Velocity, const FVector& Normal, float Restitution, float TangentialDamping);
    static FVector ResolveFloorBounce(const FVector& Velocity, const FVector& Normal, float Restitution, float TangentialDamping, float BounceDecay, int32 CompletedFloorBounces);
    static bool ShouldFloorBounce(float IncomingNormalSpeed, int32 BounceCount, int32 MaxBounceCount, float StopSpeed);
    static EJMThrowableSurfaceType ClassifySurface(const FVector& Normal, float FloorNormalThreshold);
    static bool ShouldBounce(EJMThrowableSurfaceType Surface, int32 BounceCount, int32 MaxBounceCount);
};
