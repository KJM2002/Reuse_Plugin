#pragma once

#include "Components/ActorComponent.h"
#include "InputCoreTypes.h"
#include "JMHarpoonGunComponent.generated.h"

class AJMHarpoonProjectile;
class AJMHarpoonGunVisualActor;
class APlayerController;
class UCableComponent;
class UCameraComponent;
class UPrimitiveComponent;
class USceneComponent;

UENUM(BlueprintType)
enum class EJMHarpoonGunState : uint8
{
    Ready,
    Flying,
    Embedded,
    Retracting
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJMHarpoonStateEvent, AJMHarpoonProjectile*, Projectile);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FJMHarpoonImpactEvent, AJMHarpoonProjectile*, Projectile, const FHitResult&, Hit);

/**
 * Fast first-person harpoon gun. It embeds in every blocking primitive and always supports recall.
 * Physics targets are pulled with a mass-independent force budget; static targets release the harpoon.
 */
UCLASS(ClassGroup=(JM), BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class JMPHYSICALGRABBER_API UJMHarpoonGunComponent final : public UActorComponent
{
    GENERATED_BODY()

public:
    UJMHarpoonGunComponent();

    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UFUNCTION(BlueprintCallable, Category="JM|Harpoon Gun")
    bool FireHarpoon();

    UFUNCTION(BlueprintCallable, Category="JM|Harpoon Gun")
    bool RecallHarpoon();

    UFUNCTION(BlueprintCallable, Category="JM|Harpoon Gun")
    void ResetHarpoon();

    UFUNCTION(BlueprintPure, Category="JM|Harpoon Gun")
    EJMHarpoonGunState GetHarpoonState() const { return State; }

    UFUNCTION(BlueprintPure, Category="JM|Harpoon Gun")
    AJMHarpoonProjectile* GetActiveHarpoon() const { return ActiveProjectile; }

    void NotifyProjectileImpact(AJMHarpoonProjectile* Projectile, const FHitResult& Hit, const FVector& ImpactVelocity);

    UPROPERTY(BlueprintAssignable, Category="JM|Harpoon Gun")
    FJMHarpoonStateEvent OnHarpoonFired;

    UPROPERTY(BlueprintAssignable, Category="JM|Harpoon Gun")
    FJMHarpoonImpactEvent OnHarpoonEmbedded;

    UPROPERTY(BlueprintAssignable, Category="JM|Harpoon Gun")
    FJMHarpoonStateEvent OnHarpoonRecallStarted;

    UPROPERTY(BlueprintAssignable, Category="JM|Harpoon Gun")
    FJMHarpoonStateEvent OnHarpoonReturned;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Input")
    FKey FireKey = EKeys::LeftMouseButton;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Fire", meta=(ClampMin="100.0", Units="cm/s"))
    float FireSpeed = 6500.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Fire", meta=(ClampMin="100.0", Units="cm"))
    float MaxRange = 2500.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Fire", meta=(ClampMin="0.0", Units="cm"))
    float EmbedDepth = 8.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Fire", meta=(ClampMin="0.0"))
    float ImpactImpulse = 30000.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Fire", meta=(ClampMin="0.0", Units="s"))
    float FireCooldown = 0.15f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall", meta=(ClampMin="100.0", Units="cm/s"))
    float ReelSpeed = 1800.0f;

    /** Procedural gravity used while a free harpoon searches for the floor. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Arc", meta=(ClampMin="0.0", Units="cm/s^2"))
    float ReturnGravity = 1800.0f;

    /** Time used to blend from floor/drop velocity into the final muzzle lift. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Arc", meta=(ClampMin="0.01", Units="s"))
    float ReturnGravityFadeTime = 0.35f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Arc", meta=(ClampMin="0.0", Units="cm/s"))
    float ReturnInitialDropSpeed = 280.0f;

    /** Retains a little forward motion only when recalling a still-flying harpoon. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Arc", meta=(ClampMin="0.0", Units="cm/s"))
    float ReturnForwardCarrySpeed = 300.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Arc", meta=(ClampMin="0.1"))
    float ReturnHomingResponsiveness = 5.0f;

    /** Speed used while the free harpoon is scraping along the floor. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Ground", meta=(ClampMin="100.0", Units="cm/s"))
    float ReturnGroundDragSpeed = 1100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Ground", meta=(ClampMin="0.1"))
    float ReturnGroundDragResponsiveness = 8.0f;

    /** Smooths vertical floor following so steps and uneven normals do not make the spear pop. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Ground", meta=(ClampMin="0.1"))
    float ReturnGroundHeightResponsiveness = 24.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Ground", meta=(ClampMin="0.1"))
    float ReturnGroundNormalResponsiveness = 10.0f;

    /** Keeps the kinematic harpoon slightly above the detected surface. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Ground", meta=(ClampMin="1.0", Units="cm"))
    float ReturnGroundClearance = 7.0f;

    /** Downward distance used to keep following slopes and small drops. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Ground", meta=(ClampMin="10.0", Units="cm"))
    float ReturnGroundProbeDistance = 120.0f;

    /** Height from which the floor-follow trace starts, allowing small steps and slopes. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Ground", meta=(ClampMin="0.0", Units="cm"))
    float ReturnGroundStepHeight = 35.0f;

    /** Near the player, the harpoon leaves the floor and lifts into the muzzle. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Ground", meta=(ClampMin="10.0", Units="cm"))
    float ReturnGroundLiftDistance = 240.0f;

    /** Safety fallback: begin final homing if no usable floor is found in time. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Ground", meta=(ClampMin="0.1", Units="s"))
    float ReturnGroundSearchTimeout = 1.5f;

    /** Minimum surface normal Z accepted as a floor. 0.5 is approximately a 60 degree slope. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Ground", meta=(ClampMin="0.0", ClampMax="1.0"))
    float ReturnMinimumGroundNormalZ = 0.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall", meta=(ClampMin="0.0"))
    float MaxPullForce = 200000.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall", meta=(ClampMin="0.0"))
    float PullStrength = 3000.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall", meta=(ClampMin="0.0"))
    float PullDamping = 700.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall", meta=(ClampMin="1.0", Units="cm"))
    float CatchDistance = 100.0f;

    /** Physics targets are released at this radius instead of being pulled through the player. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall", meta=(ClampMin="1.0", Units="cm"))
    float PhysicsReleaseDistance = 220.0f;

    /** Fraction of velocity toward the player removed when a physics target reaches the release radius. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall", meta=(ClampMin="0.0", ClampMax="1.0"))
    float ReleaseBraking = 0.85f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall", meta=(ClampMin="0.0", Units="s"))
    float HeavyTargetTimeout = 1.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall", meta=(ClampMin="0.0", Units="cm"))
    float MinimumRecallProgress = 100.0f;

    /** Pulls an embedded spear just outside the hit surface before kinematic recall begins. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall", meta=(ClampMin="0.0", Units="cm"))
    float ReturnSeparationDistance = 20.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation")
    FVector MuzzleOffset = FVector(80.0f, 18.0f, -14.0f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation")
    FVector GunVisualOffset = FVector(38.0f, 18.0f, -20.0f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation", meta=(ClampMin="0.0", Units="cm"))
    float RecoilDistance = 12.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation")
    bool bCreatePrototypeVisuals = true;

    /** Blueprint-editable visual actor spawned and attached to the first-person camera. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation")
    TSubclassOf<AJMHarpoonGunVisualActor> VisualActorClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable", meta=(ClampMin="1", ClampMax="64"))
    int32 CableNumSegments = 12;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable", meta=(ClampMin="1", ClampMax="32"))
    int32 CableSolverIterations = 8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable", meta=(ClampMin="0.1", Units="cm"))
    float CableWidth = 1.8f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable", meta=(ClampMin="0.0"))
    float CableGravityScale = 0.25f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable", meta=(ClampMin="0.005", Units="s"))
    float CableSubstepTime = 0.01f;

    /** Smooths changing cable length to prevent slack from being injected in one frame. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable", meta=(ClampMin="0.1"))
    float CableLengthInterpSpeed = 24.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable", meta=(ClampMin="1.0", ClampMax="1.2"))
    float CableSlackMultiplier = 1.01f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Debug")
    bool bDrawDebug = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Projectile")
    TSubclassOf<AJMHarpoonProjectile> ProjectileClass;

private:
    APlayerController* GetOwningPlayerController() const;
    bool GetView(FVector& OutLocation, FVector& OutDirection) const;
    FVector GetMuzzleLocation() const;
    void EnsurePresentation();
    void DestroyPresentation();
    void ShowCable(bool bShow);
    void SmoothCableLength(float TargetLength, float DeltaTime);
    void UpdateFlying(float DeltaTime);
    void UpdateEmbedded(float DeltaTime);
    void UpdateRetracting(float DeltaTime);
    void DetachForFreeReturn(bool bPreserveForwardCarry = false);
    void BeginFinalReturnLift();
    bool SweepFreeReturnForGround(const FVector& Start, const FVector& End, FHitResult& OutHit) const;
    bool FindFreeReturnGroundBelow(const FVector& Location, FHitResult& OutHit) const;
    float GetPhysicsTargetSurfaceDistance(const FVector& FromLocation, const FVector& GrabPoint) const;
    void ApplyPhysicsReleaseBraking(const FVector& GrabPoint, const FVector& PullDirection) const;
    void CompleteReturn();
    void UpdatePresentation(float DeltaTime);
    UPROPERTY(Transient)
    TObjectPtr<AJMHarpoonProjectile> ActiveProjectile;

    UPROPERTY(Transient)
    TObjectPtr<AJMHarpoonGunVisualActor> GunVisualActor;

    UPROPERTY(Transient)
    TObjectPtr<UCableComponent> Cable;

    UPROPERTY(Transient)
    TObjectPtr<UPrimitiveComponent> EmbeddedComponent;

    FName EmbeddedBone = NAME_None;
    FVector EmbeddedLocalPoint = FVector::ZeroVector;
    FVector LastImpactVelocity = FVector::ZeroVector;
    EJMHarpoonGunState State = EJMHarpoonGunState::Ready;
    float CooldownRemaining = 0.0f;
    float RecallElapsed = 0.0f;
    float RecallStartDistance = 0.0f;
    float FreeReturnElapsed = 0.0f;
    float FreeReturnPhaseElapsed = 0.0f;
    FVector FreeReturnVelocity = FVector::ZeroVector;
    FVector FreeReturnGroundNormal = FVector::UpVector;
    float RecoilAlpha = 0.0f;
    float WinchAngle = 0.0f;
    bool bPullingPhysicsTarget = false;
    bool bFreeReturnGrounded = false;
    bool bFreeReturnFinalLift = false;
};
