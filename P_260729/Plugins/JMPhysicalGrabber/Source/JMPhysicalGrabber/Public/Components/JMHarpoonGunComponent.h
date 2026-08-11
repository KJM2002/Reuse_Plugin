#pragma once

#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "InputCoreTypes.h"
#include "Components/JMHarpoonWireRouteComponent.h"
#include "Types/JMHarpoonCableLengthModel.h"
#include "Types/JMHarpoonInteractionTypes.h"
#include "JMHarpoonGunComponent.generated.h"

class AJMHarpoonProjectile;
class AJMHarpoonGunVisualActor;
class ACharacter;
class APlayerController;
class UCableComponent;
class UCameraComponent;
class UCharacterMovementComponent;
class UMaterialInterface;
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

UENUM(BlueprintType)
enum class EJMPlayerGrappleState : uint8
{
    Disabled,
    Idle,
    Armed,
    Pulling
};

UENUM(BlueprintType)
enum class EJMPlayerGrappleEndReason : uint8
{
    Released,
    ReachedAnchor,
    HarpoonRecall,
    InvalidAnchor,
    Timeout,
    Blocked,
    FeatureDisabled
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJMHarpoonStateEvent, AJMHarpoonProjectile*, Projectile);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FJMHarpoonImpactEvent, AJMHarpoonProjectile*, Projectile, const FHitResult&, Hit);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJMPlayerGrappleStartedEvent, AJMHarpoonProjectile*, Projectile);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FJMPlayerGrappleEndedEvent,
    AJMHarpoonProjectile*, Projectile,
    EJMPlayerGrappleEndReason, Reason);

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

    UFUNCTION(BlueprintPure, Category="JM|Harpoon Gun|Interaction")
    bool HasCustomInteractionTarget() const { return IsValid(InteractionTargetObject); }

    UFUNCTION(BlueprintPure, Category="JM|Harpoon Gun|Interaction")
    FJMHarpoonInteractionProfile GetActiveInteractionProfile() const { return ActiveInteractionProfile; }

    UFUNCTION(BlueprintCallable, Category="JM|Harpoon Gun|Player Grapple")
    void SetPlayerGrappleEnabled(bool bEnabled);

    UFUNCTION(BlueprintPure, Category="JM|Harpoon Gun|Player Grapple")
    bool IsPlayerGrappleEnabled() const { return bEnablePlayerGrapple; }

    UFUNCTION(BlueprintCallable, Category="JM|Harpoon Gun|Player Grapple")
    bool StartPlayerGrapple();

    UFUNCTION(BlueprintCallable, Category="JM|Harpoon Gun|Player Grapple")
    void StopPlayerGrapple();

    UFUNCTION(BlueprintPure, Category="JM|Harpoon Gun|Player Grapple")
    EJMPlayerGrappleState GetPlayerGrappleState() const { return PlayerGrappleState; }

    void NotifyProjectileImpact(AJMHarpoonProjectile* Projectile, const FHitResult& Hit, const FVector& ImpactVelocity);

    UPROPERTY(BlueprintAssignable, Category="JM|Harpoon Gun")
    FJMHarpoonStateEvent OnHarpoonFired;

    UPROPERTY(BlueprintAssignable, Category="JM|Harpoon Gun")
    FJMHarpoonImpactEvent OnHarpoonEmbedded;

    UPROPERTY(BlueprintAssignable, Category="JM|Harpoon Gun")
    FJMHarpoonStateEvent OnHarpoonRecallStarted;

    UPROPERTY(BlueprintAssignable, Category="JM|Harpoon Gun")
    FJMHarpoonStateEvent OnHarpoonReturned;

    UPROPERTY(BlueprintAssignable, Category="JM|Harpoon Gun|Player Grapple")
    FJMPlayerGrappleStartedEvent OnPlayerGrappleStarted;

    UPROPERTY(BlueprintAssignable, Category="JM|Harpoon Gun|Player Grapple")
    FJMPlayerGrappleEndedEvent OnPlayerGrappleEnded;

    /** Compatibility only. Prefer project-owned Enhanced Input actions calling the public API. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Input")
    bool bUseLegacyKeyPolling = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Input", meta=(EditCondition="bUseLegacyKeyPolling"))
    FKey FireKey = EKeys::LeftMouseButton;

    /** Master switch. Turning it off during a pull immediately restores normal movement. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Player Grapple|Input")
    bool bEnablePlayerGrapple = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Player Grapple|Input", meta=(EditCondition="bUseLegacyKeyPolling"))
    FKey PlayerGrappleKey = EKeys::RightMouseButton;

    /** Allows the player to follow a projectile embedded in a moving physics body. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Player Grapple|Input")
    bool bAllowDynamicPlayerGrappleAnchors = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Player Grapple|Movement", meta=(ClampMin="100.0", Units="cm/s^2"))
    float PlayerGrappleAcceleration = 6500.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Player Grapple|Movement", meta=(ClampMin="100.0", Units="cm/s"))
    float PlayerGrappleMaxSpeed = 2500.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Player Grapple|Movement", meta=(ClampMin="10.0", Units="cm"))
    float PlayerGrappleStopDistance = 140.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Player Grapple|Movement", meta=(ClampMin="10.0", Units="cm"))
    float PlayerGrappleApproachSlowDistance = 550.0f;

    /** Fraction of sideways velocity retained while the cable pulls inward. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Player Grapple|Movement", meta=(ClampMin="0.0", ClampMax="1.0"))
    float PlayerGrappleTangentialRetention = 0.9f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Player Grapple|Movement", meta=(ClampMin="0.0", ClampMax="2.0"))
    float PlayerGrappleGravityScale = 0.35f;

    /** Removes this fraction of inward velocity when the player reaches the anchor. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Player Grapple|Movement", meta=(ClampMin="0.0", ClampMax="1.0"))
    float PlayerGrappleArrivalBraking = 0.8f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Player Grapple|Safety", meta=(ClampMin="0.1", Units="s"))
    float PlayerGrappleMaxDuration = 3.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Player Grapple|Safety", meta=(ClampMin="0.1", Units="s"))
    float PlayerGrappleBlockedTimeout = 0.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Player Grapple|Safety", meta=(ClampMin="0.0", Units="cm"))
    float PlayerGrappleMinimumProgress = 10.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Player Grapple|Safety", meta=(ClampMin="100.0", Units="cm/s"))
    float PlayerGrappleMaxDownwardSpeed = 1200.0f;

    /** Keeps the first-person camera this far from blocking geometry while grappling. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Player Grapple|Safety", meta=(ClampMin="0.0", Units="cm"))
    float PlayerGrappleCameraClearance = 55.0f;

    /** Radius of the predictive camera sweep. Increase it if narrow corners still clip. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Player Grapple|Safety", meta=(ClampMin="0.0", Units="cm"))
    float PlayerGrappleCameraProbeRadius = 14.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Player Grapple|Presentation", meta=(ClampMin="0.0", ClampMax="30.0", Units="deg"))
    float PlayerGrappleFOVBoost = 6.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Player Grapple|Presentation", meta=(ClampMin="0.1"))
    float PlayerGrappleFOVInterpSpeed = 10.0f;

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

    /** Traces from the crosshair before deriving the muzzle shot direction. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Fire|Aim")
    bool bUseCrosshairAimTrace = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Fire|Aim", meta=(EditCondition="bUseCrosshairAimTrace"))
    TEnumAsByte<ECollisionChannel> CrosshairTraceChannel = ECC_Visibility;

    /** Radius used to detect a blocking surface immediately outside the muzzle. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Fire|Muzzle Safety", meta=(ClampMin="0.1", Units="cm"))
    float MuzzleObstructionProbeRadius = 6.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Fire|Muzzle Safety", meta=(ClampMin="0.0", Units="cm"))
    float MuzzleObstructionProbeDistance = 30.0f;

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

    /** Targets strictly below this mass use the stable center-of-mass pull path. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Light", meta=(ClampMin="0.0", Units="kg"))
    float LightObjectMassThreshold = 5.0f;

    /** Small mass-independent velocity kick used instead of an off-center impact impulse. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Light", meta=(ClampMin="0.0", Units="cm/s"))
    float LightImpactVelocityKick = 80.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Light", meta=(ClampMin="0.0", Units="cm/s"))
    float LightMinPullSpeed = 220.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Light", meta=(ClampMin="0.0", Units="cm/s"))
    float LightMaxPullSpeed = 1100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Light", meta=(ClampMin="1.0", Units="cm"))
    float LightApproachSlowDistance = 650.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Light", meta=(ClampMin="0.0"))
    float LightVelocityGain = 8.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Light", meta=(ClampMin="0.0", Units="cm/s^2"))
    float LightMaxPullAcceleration = 2500.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Light", meta=(ClampMin="0.0", ClampMax="1.0"))
    float LightTangentialRetention = 0.15f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Light", meta=(ClampMin="0.0"))
    float LightAngularDamping = 9.0f;

    /** Maximum angular acceleration change in radians per second squared. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Light", meta=(ClampMin="0.0"))
    float LightMaxAngularDeceleration = 80.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Light", meta=(ClampMin="0.0", Units="s"))
    float LightPullRampTime = 0.10f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall", meta=(ClampMin="0.0", Units="s"))
    float HeavyTargetTimeout = 1.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall", meta=(ClampMin="0.0", Units="cm"))
    float MinimumRecallProgress = 100.0f;

    /** Pulls an embedded spear just outside the hit surface before kinematic recall begins. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall", meta=(ClampMin="0.0", Units="cm"))
    float ReturnSeparationDistance = 20.0f;

    /** Emergency recovery begins if the projectile exceeds this player distance. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Safety", meta=(ClampMin="1000.0", Units="cm"))
    float FailSafeMaxDistance = 6000.0f;

    /** Emergency recovery begins this far below the player, even when the map KillZ is much lower. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Safety", meta=(ClampMin="500.0", Units="cm"))
    float FailSafeMaxVerticalDrop = 5000.0f;

    /** Recovery starts above the world's KillZ so the engine cannot delete the harpoon first. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Safety", meta=(ClampMin="0.0", Units="cm"))
    float FailSafeKillZMargin = 1000.0f;

    /** Distance in front of the player where a lost or invalid harpoon is recreated for final return. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Safety", meta=(ClampMin="100.0", Units="cm"))
    float FailSafeRecoveryDistance = 450.0f;

    /** Absolute deadline from recall start to the Ready state. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Safety", meta=(ClampMin="0.5", Units="s"))
    float MaxRecallDuration = 4.0f;

    /** Before the deadline, abandon the target and recreate the spear nearby for a visible final return. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Recall|Safety", meta=(ClampMin="0.1", Units="s"))
    float RecallDeadlineLeadTime = 0.75f;

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

    /** Segment count is fixed before registration; 16 is the first-person quality/performance default. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable", meta=(ClampMin="1", ClampMax="32"))
    int32 CableNumSegments = 16;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable", meta=(ClampMin="1", ClampMax="16"))
    int32 CableSolverIterations = 12;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable", meta=(ClampMin="0.1", Units="cm"))
    float CableWidth = 1.2f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable", meta=(ClampMin="3", ClampMax="12"))
    int32 CableNumSides = 6;

    /** Optional project material. A tiled opaque braided-wire material is recommended. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable")
    TObjectPtr<UMaterialInterface> CableMaterial;

    /** World-space length represented by one material repeat. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable", meta=(ClampMin="1.0", Units="cm"))
    float CableMaterialTileLength = 75.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable", meta=(ClampMin="0.0"))
    float CableGravityScale = 0.12f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable", meta=(ClampMin="0.005", Units="s"))
    float CableSubstepTime = 0.008333f;

    /** Smooths changing cable length to prevent slack from being injected in one frame. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable", meta=(ClampMin="0.1"))
    float CableLengthInterpSpeed = 24.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable", meta=(ClampMin="1.0", ClampMax="1.2"))
    float CableSlackMultiplier = 1.01f;

    /** Short loaded/firing rest length. Keeping this small prevents a one-meter loop from being released at the muzzle. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable|Stability", meta=(ClampMin="1.0", Units="cm"))
    float CableMinimumLength = 10.0f;

    /** Lower/upper bounds keep percentage slack useful without creating a long loose rope at maximum range. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable", meta=(ClampMin="0.0", Units="cm"))
    float CableMinimumSlack = 2.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable", meta=(ClampMin="0.0", Units="cm"))
    float CableMaximumSlack = 8.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable|Stability", meta=(ClampMin="0.0", Units="cm"))
    float CableLengthDeadZone = 1.0f;

    /** Ignores sub-centimeter camera/muzzle jitter before it enters the cable simulation. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable|Stability", meta=(ClampMin="0.0", Units="cm"))
    float CableStartJitterDeadZone = 0.2f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable|Stability", meta=(ClampMin="0.1"))
    float CableStartStabilizationSpeed = 55.0f;

    /** Keeps the visual line attached during fast camera turns while still filtering micro jitter. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable|Stability", meta=(ClampMin="0.0", Units="cm"))
    float CableStartMaximumLag = 1.5f;

    /** Fast endpoint motion resets stale Verlet velocity into a straight, taut cable. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable|Stability", meta=(ClampMin="0.0", Units="cm"))
    float CableParticleResetDistance = 25.0f;

    /** Experimental CableComponent collision is enabled only during the short recall window. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable|Ground Collision")
    bool bEnableGroundCableCollision = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable|Ground Collision", meta=(ClampMin="0.0", ClampMax="1.0"))
    float CableCollisionFriction = 0.55f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Cable|Ground Collision")
    bool bCableCollideWithWorldDynamic = false;

    /** Uses bounded sphere-sweep contacts and spline meshes instead of particle cable collision. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Wire Route")
    bool bUseSplineWire = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Presentation|Wire Route", meta=(EditCondition="bUseSplineWire"))
    FJMHarpoonWireRouteSettings WireRouteSettings;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Debug")
    bool bDrawDebug = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Gun|Projectile")
    TSubclassOf<AJMHarpoonProjectile> ProjectileClass;

private:
    APlayerController* GetOwningPlayerController() const;
    bool GetView(FVector& OutLocation, FVector& OutDirection) const;
    FVector ResolveAimPoint(const FVector& ViewLocation, const FVector& ViewDirection) const;
    bool SweepMuzzleObstruction(
        const FVector& MuzzleLocation,
        const FVector& ShotDirection,
        FHitResult& OutHit) const;
    FVector GetMuzzleLocation() const;
    void EnsurePresentation();
    void DestroyPresentation();
    void ShowCable(bool bShow);
    void AttachCableToActiveProjectile(float InitialLength);
    void SmoothCableLength(float TargetLength, float DeltaTime);
    void UpdateCableStartProxy(float DeltaTime);
    void UpdateCableCollisionMode();
    void UpdateSplineWire(float DeltaTime);
    void ResetCablePresentationState();
    void UpdatePlayerGrappleInput(APlayerController* Controller);
    void UpdatePlayerGrapple(float DeltaTime);
    bool SweepPlayerGrappleCamera(
        const FVector& CameraLocation,
        const FVector& PullDirection,
        const FVector& CandidateVelocity,
        float DeltaTime,
        FHitResult& OutHit) const;
    void UpdatePlayerGrappleFOV(float DeltaTime);
    void EndPlayerGrapple(EJMPlayerGrappleEndReason Reason);
    void RestorePlayerGrappleMovement();
    bool HasHarpoonSafetyViolation() const;
    void BeginEmergencyReturn();
    void ForceCompleteReturnAtDeadline();
    void UpdateFailSafeSmoke();
    void UpdatePlayerGrappleSmoke(float DeltaTime);
    void UpdateFlying(float DeltaTime);
    void UpdateEmbedded(float DeltaTime);
    void UpdateRetracting(float DeltaTime);
    void DetachForFreeReturn(bool bPreserveForwardCarry = false);
    void BeginFinalReturnLift();
    bool SweepFreeReturnForGround(const FVector& Start, const FVector& End, FHitResult& OutHit) const;
    bool FindFreeReturnGroundBelow(const FVector& Location, FHitResult& OutHit) const;
    float GetPhysicsTargetSurfaceDistance(const FVector& FromLocation, const FVector& GrabPoint) const;
    float GetEmbeddedTargetMass() const;
    bool IsLightPhysicsTarget() const;
    FVector UpdateLightPhysicsPull(
        float DeltaTime,
        const FVector& MuzzleLocation,
        const FVector& CenterOfMass,
        float DistanceToRelease);
    FVector UpdateStandardPhysicsPull(
        const FVector& GrabPoint,
        const FVector& SoftCatchError,
        const FVector& PointVelocity);
    void ApplyLightAngularStabilization(float DeltaTime);
    void ApplyPhysicsReleaseBraking(const FVector& GrabPoint, const FVector& PullDirection) const;
    UObject* ResolveInteractionTarget(const FHitResult& Hit) const;
    void EndActiveInteraction(EJMHarpoonInteractionEndReason Reason);
    void CompleteReturn();
    void UpdatePresentation(float DeltaTime);
    UPROPERTY(Transient)
    TObjectPtr<AJMHarpoonProjectile> ActiveProjectile;

    UPROPERTY(Transient)
    TObjectPtr<AJMHarpoonGunVisualActor> GunVisualActor;

    UPROPERTY(Transient)
    TObjectPtr<UCableComponent> Cable;

    UPROPERTY(Transient)
    TObjectPtr<UJMHarpoonWireRouteComponent> WireRoute;

    UPROPERTY(Transient)
    TObjectPtr<USceneComponent> CableStartProxy;

    UPROPERTY(Transient)
    TObjectPtr<UPrimitiveComponent> EmbeddedComponent;

    UPROPERTY(Transient)
    TObjectPtr<UObject> InteractionTargetObject;

    FJMHarpoonInteractionContext ActiveInteractionContext;
    FJMHarpoonInteractionProfile ActiveInteractionProfile;

    FName EmbeddedBone = NAME_None;
    FVector EmbeddedLocalPoint = FVector::ZeroVector;
    FVector LastImpactVelocity = FVector::ZeroVector;
    EJMHarpoonGunState State = EJMHarpoonGunState::Ready;
    EJMPlayerGrappleState PlayerGrappleState = EJMPlayerGrappleState::Disabled;
    float CooldownRemaining = 0.0f;
    float RecallElapsed = 0.0f;
    float RecallStartDistance = 0.0f;
    float FreeReturnElapsed = 0.0f;
    float FreeReturnPhaseElapsed = 0.0f;
    FVector FreeReturnVelocity = FVector::ZeroVector;
    FVector FreeReturnGroundNormal = FVector::UpVector;
    float RecoilAlpha = 0.0f;
    float WinchAngle = 0.0f;
    FJMHarpoonCableLengthModel CableLengthModel;
    bool bCableStartInitialized = false;
    bool bGroundCableCollisionActive = false;
    bool bPullingPhysicsTarget = false;
    bool bFreeReturnGrounded = false;
    bool bFreeReturnFinalLift = false;
    bool bDeadlineRecoveryTriggered = false;
    TWeakObjectPtr<ACharacter> GrappleCharacter;
    TWeakObjectPtr<UCharacterMovementComponent> GrappleMovement;
    TWeakObjectPtr<UCameraComponent> GrappleCamera;
    float GrappleOriginalGravityScale = 1.0f;
    float GrappleOriginalMaxWalkSpeed = 600.0f;
    float GrappleOriginalGroundFriction = 8.0f;
    float GrappleOriginalBrakingFrictionFactor = 2.0f;
    float GrappleBaseFOV = 90.0f;
    float PlayerGrappleElapsed = 0.0f;
    float PlayerGrappleBlockedElapsed = 0.0f;
    float PlayerGrappleProgressStartDistance = 0.0f;
    bool bPlayerGrappleMovementOverridden = false;
    bool bPlayerGrappleFOVActive = false;
    bool bFailSafeSmokeStarted = false;
    bool bFailSafeSmokeCompleted = false;
    bool bPlayerGrappleSmokeStarted = false;
    bool bPlayerGrappleSmokeCompleted = false;
    float PlayerGrappleSmokeElapsed = 0.0f;
    float PlayerGrappleSmokeStartDistance = 0.0f;
};
