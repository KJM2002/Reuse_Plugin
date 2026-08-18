#pragma once

#include "Locomotion/JMEnemyLocomotionComponent.h"
#include "JMEnemyLocomotion_SurfaceCrawler.generated.h"

/** Geometry-driven floor/wall/ceiling backend. Behavior remains in StateTree. */
UCLASS(ClassGroup=(JMEnemy), meta=(BlueprintSpawnableComponent))
class JMMONSTERFRAMEWORKRUNTIME_API UJMEnemyLocomotion_SurfaceCrawler : public UJMEnemyLocomotionComponent
{
    GENERATED_BODY()

public:
    UJMEnemyLocomotion_SurfaceCrawler();

    virtual EJMEnemyMoveRequestResult MoveToActor(AActor* TargetActor, FJMEnemyMoveOptions Options) override;
    virtual EJMEnemyMoveRequestResult MoveToLocation(FVector Destination, FJMEnemyMoveOptions Options) override;
    virtual EJMEnemyMoveRequestResult MoveAwayFromActor(
        AActor* ThreatActor, float EscapeDistance, FJMEnemyMoveOptions Options) override;
    virtual bool FindEscapeLocation(AActor* ThreatActor, float EscapeDistance, FVector& OutLocation) const override;
    virtual bool FindRandomReachableLocation(FVector Center, float Radius, FVector& OutLocation) const override;
    virtual void StopMovement() override;
    virtual bool FaceActor(AActor* TargetActor, EJMEnemyFacingMode Mode) override;
    virtual void ClearFacingFocus() override;
    virtual bool ApplyMovementProfile(const UJMEnemyMovementSet* MovementSet, FName ProfileName) override;

    UFUNCTION(BlueprintPure, Category="JM Enemy|Locomotion|Surface")
    FVector GetCurrentSurfaceNormal() const { return CurrentSurfaceNormal; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Locomotion|Surface")
    FVector GetAttachmentPoint() const { return AttachmentPoint; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Locomotion|Surface")
    FVector GetDesiredMoveDirection() const { return DesiredMoveDirection; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Locomotion|Surface")
    int32 GetSurfaceTransitionCount() const { return SurfaceTransitionCount; }

protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType,
        FActorComponentTickFunction* ThisTickFunction) override;
    virtual EJMEnemyMoveRequestResult SubmitMoveRequest(AActor* TargetActor, const FVector& Destination,
        const FJMEnemyMoveOptions& Options) override;

private:
    bool AcquireInitialSurface();
    bool TraceSurface(const FVector& Start, const FVector& Direction, float Distance, FHitResult& OutHit) const;
    bool ReacquireSurface(FHitResult& OutHit) const;
    void ApplySurfaceTransform(const FVector& NewLocation, const FVector& SurfaceNormal,
        const FVector& Forward, float DeltaTime, bool bSweep);
    FVector ResolveMoveGoal() const;
    void DrawSurfaceDebug(const FVector& TraceStart, const FVector& TraceEnd,
        const FHitResult* Hit, const FColor& Color) const;

    UPROPERTY(EditDefaultsOnly, Category="Surface Crawler", meta=(ClampMin="1.0"))
    float AttachmentOffset = 90.0f;

    UPROPERTY(EditDefaultsOnly, Category="Surface Crawler", meta=(ClampMin="1.0"))
    float AttachmentProbeDistance = 150.0f;

    UPROPERTY(EditDefaultsOnly, Category="Surface Crawler", meta=(ClampMin="1.0"))
    float ForwardTransitionProbe = 120.0f;

    UPROPERTY(EditDefaultsOnly, Category="Surface Crawler", meta=(ClampMin="0.0"))
    float SurfaceLossGraceTime = 0.2f;

    UPROPERTY(EditDefaultsOnly, Category="Surface Crawler", meta=(ClampMin="0.0"))
    float RotationInterpolationSpeed = 12.0f;

    UPROPERTY(EditDefaultsOnly, Category="Surface Crawler")
    TEnumAsByte<ECollisionChannel> SurfaceTraceChannel = ECC_Visibility;

    UPROPERTY(EditDefaultsOnly, Category="Surface Crawler|Debug")
    bool bDrawSurfaceDebug = false;

    FVector CurrentSurfaceNormal = FVector::UpVector;
    FVector AttachmentPoint = FVector::ZeroVector;
    FVector DesiredMoveDirection = FVector::ForwardVector;
    FVector DesiredFacingDirection = FVector::ForwardVector;
    float SurfaceSpeed = 300.0f;
    float ActiveAcceptanceRadius = 75.0f;
    float LostSurfaceTime = 0.0f;
    int32 SurfaceTransitionCount = 0;
};
