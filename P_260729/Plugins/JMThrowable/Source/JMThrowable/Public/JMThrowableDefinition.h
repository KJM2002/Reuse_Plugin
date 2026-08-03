#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "JMThrowableTypes.h"
#include "JMThrowableDefinition.generated.h"

class AJMThrowableProjectile;
class UMaterialInterface;
class UNiagaraSystem;
class USoundBase;
class USoundAttenuation;
class UStaticMesh;

UCLASS(BlueprintType)
class JMTHROWABLE_API UJMThrowableDefinition : public UPrimaryDataAsset
{
    GENERATED_BODY()
public:
    UJMThrowableDefinition();
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Projectile") TSubclassOf<AJMThrowableProjectile> ProjectileClass;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Projectile", meta=(ClampMin="1")) float ThrowSpeed = 980.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Projectile", meta=(ClampMin="0", ToolTip="World-space upward speed added to the camera-forward throw velocity.")) float VerticalThrowBoost = 220.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Projectile") float GravityScale = 1.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Projectile", meta=(ClampMin="0.1")) float ProjectileRadius = 4.5f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Projectile|Visual") TSoftObjectPtr<UStaticMesh> ProjectileVisualMesh;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Projectile|Visual") TSoftObjectPtr<UMaterialInterface> ProjectileVisualMaterial;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Projectile|Visual", meta=(ClampMin="0.1", ToolTip="Centimeter dimensions used by the native box fallback and to normalize an optional visual mesh.")) FVector ProjectileVisualSize = FVector(8.5f, 5.5f, 2.2f);
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Projectile|Visual", meta=(ToolTip="Purely visual local rotation rate; collision remains the compatible sphere sweep.")) FRotator VisualSpinDegreesPerSecond = FRotator(110.f, 180.f, 75.f);
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Simulation", meta=(ClampMin="0.01")) float MaximumSimulationTime = 5.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Simulation", meta=(ClampMin="0.001")) float SimulationStep = 1.f / 60.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aim", meta=(ClampMin="100")) float AimTraceDistance = 10000.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collision") FName CollisionProfile = TEXT("BlockAll");
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collision", meta=(ClampMin="-1", ClampMax="1")) float FloorNormalThreshold = .7f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collision", meta=(ClampMin="0")) int32 MaxWallBounces = 1;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collision", meta=(ClampMin="0", ClampMax="1", ToolTip="Normal restitution for non-floor impacts.")) float BounceRestitution = .08f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collision", meta=(ClampMin="0", ClampMax="1", ToolTip="Tangential velocity retained after non-floor impacts.")) float TangentialDamping = .5f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collision|Floor Bounce", meta=(ClampMin="0")) int32 MaxFloorBounces = 3;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collision|Floor Bounce", meta=(ClampMin="0", ClampMax="1")) float FloorRestitution = .2f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collision|Floor Bounce", meta=(ClampMin="0", ClampMax="1")) float FloorTangentialDamping = .6f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collision|Floor Bounce", meta=(ClampMin="0", ClampMax="1", ToolTip="Restitution multiplier applied once per completed floor bounce.")) float FloorBounceDecay = .6f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collision|Floor Bounce", meta=(ClampMin="0", ToolTip="Minimum incoming normal speed required to perform another floor bounce.")) float FloorBounceStopSpeed = 80.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collision", meta=(ClampMin="0")) float SurfaceOffset = 1.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collision", meta=(ClampMin="0", ClampMax="1")) float FloorFriction = .18f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collision", meta=(ClampMin="0")) float FloorStopSpeed = 50.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collision", meta=(ClampMin="0")) float DynamicImpactImpulse = 80.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spawn") float SpawnForwardOffset = 60.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spawn") float SpawnRightOffset = 0.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spawn") float SpawnVerticalOffset = 0.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Preview", meta=(ClampMin="1")) float PreviewPointSpacing = 20.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Preview", meta=(ClampMin="0", ClampMax="200", ToolTip="Camera-forward distance to the centered visual preview origin. Runtime spawn offsets are not applied.")) float PreviewStartDistance = 40.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Preview", meta=(ClampMin="0.1", ClampMax="20")) float PreviewLineWidth = 10.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Preview", meta=(ClampMin="0.01", ClampMax="1")) float PreviewOpacity = .2f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Preview", meta=(ClampMin="2", ClampMax="40")) float PreviewEndMarkerSize = 5.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Preview|Flow", meta=(ClampMin="10", ClampMax="1000", ToolTip="World-space length of the bright highlight traveling along the trajectory.")) float PreviewFlowLength = 100.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Preview|Flow", meta=(ClampMin="0.1", ClampMax="1", ToolTip="Width of the bright highlight relative to the base ribbon.")) float PreviewFlowWidthMultiplier = .35f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Preview|Flow", meta=(ClampMin="0.01", ClampMax="1")) float PreviewFlowOpacity = .75f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Preview|Flow", meta=(ClampMin="0", ClampMax="500", ToolTip="Invisible travel distance after the end before the flow loops to the start.")) float PreviewFlowLoopGap = 35.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Preview|Flow", meta=(ClampMin="1", ClampMax="20", ToolTip="Diameter of the visible orb traveling with the flow highlight.")) float PreviewFlowOrbSize = 3.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Preview|Impact", meta=(ClampMin="0", ClampMax="10", ToolTip="Moves the first-impact marker away from the surface to prevent clipping.")) float PreviewMarkerSurfaceOffset = 1.5f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Preview|Niagara") EJMThrowablePreviewRendererMode PreviewRendererMode = EJMThrowablePreviewRendererMode::NiagaraPreferred;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Preview|Niagara", meta=(AllowedClasses="/Script/Niagara.NiagaraSystem", ToolTip="Plugin-owned trajectory system. A missing or invalid asset automatically uses the procedural fallback.")) TSoftObjectPtr<UNiagaraSystem> TrajectoryNiagaraSystem;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Preview|Niagara", meta=(ClampMin="2", ClampMax="256")) int32 NiagaraPathSampleCount = 64;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Preview") TSoftObjectPtr<UMaterialInterface> TrajectoryMaterial;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Preview", meta=(ClampMin="1")) float GlowMoveSpeed = 650.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Preview", meta=(ClampMin="0")) float GlowIntensity = 0.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Preview", meta=(ClampMin="1")) float GlowRadius = 35.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Activation", meta=(ClampMin="0")) float FuseDelay = 1.5f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Activation", meta=(ClampMin="1")) int32 BurstCount = 5;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Activation", meta=(ClampMin="0.01")) float BurstInterval = .22f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Activation") TSoftObjectPtr<UNiagaraSystem> BurstParticle;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Activation") TSoftObjectPtr<USoundBase> BurstSound;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Activation") TSoftObjectPtr<USoundAttenuation> SoundAttenuation;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Activation", meta=(ClampMin="0")) float LightIntensity = 8000.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Activation", meta=(ClampMin="0.01")) float LightDuration = .08f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI", meta=(ClampMin="0")) float NoiseLoudness = 4.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI", meta=(ClampMin="0")) float NoiseRadius = 2500.f;
};
