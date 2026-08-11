#pragma once

#include "CoreMinimal.h"
#include "JMHarpoonInteractionTypes.generated.h"

class AJMHarpoonProjectile;
class UJMHarpoonGunComponent;
class UPrimitiveComponent;

UENUM(BlueprintType)
enum class EJMHarpoonReaction : uint8
{
    None,
    Pull,
    Break,
    Extract,
    Activate,
    CreaturePart,
    Anchor
};

UENUM(BlueprintType)
enum class EJMHarpoonInteractionEndReason : uint8
{
    Released,
    Completed,
    TargetInvalid,
    Reset,
    RecallTimeout
};

UENUM(BlueprintType)
enum class EJMHarpoonReactionDirective : uint8
{
    Continue,
    ReleaseHarpoon
};

/** Data owned by the hit target. Values are deliberately independent of any game-specific actor class. */
USTRUCT(BlueprintType)
struct JMPHYSICALGRABBER_API FJMHarpoonInteractionProfile
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Harpoon")
    bool bCanEmbed = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Harpoon")
    bool bCanPull = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Harpoon")
    bool bCanBreak = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Harpoon")
    bool bCanExtract = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Harpoon")
    bool bCanActivate = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Harpoon")
    bool bCanAffectCreature = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Harpoon")
    EJMHarpoonReaction Reaction = EJMHarpoonReaction::Pull;

    /** Multiplies the gun's force budget. Use resistance rather than actor-class branches. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Harpoon", meta=(ClampMin="0.0"))
    float PullResistance = 1.0f;

    /** Sustained cable force required by Break, Extract, Activate, or CreaturePart reactions. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Harpoon", meta=(ClampMin="0.0"))
    float ReactionForce = 75000.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Harpoon", meta=(ClampMin="0.0", Units="s"))
    float ReactionHoldTime = 0.35f;

    /** Force above which fragile cargo loses condition. Zero disables fragile handling. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Harpoon", meta=(ClampMin="0.0"))
    float FragileSafeForce = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Harpoon", meta=(ClampMin="0.0"))
    float FragileDamagePerSecond = 0.35f;

    /** Generic signal for an AI/noise bridge. The core plugin does not depend on an AI system. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Harpoon", meta=(ClampMin="0.0"))
    float ImpactNoiseLoudness = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Harpoon", meta=(ClampMin="0.0"))
    float PullNoiseLoudness = 0.0f;
};

USTRUCT(BlueprintType)
struct JMPHYSICALGRABBER_API FJMHarpoonInteractionContext
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="Harpoon")
    TObjectPtr<UJMHarpoonGunComponent> Gun = nullptr;

    UPROPERTY(BlueprintReadOnly, Category="Harpoon")
    TObjectPtr<AJMHarpoonProjectile> Projectile = nullptr;

    UPROPERTY(BlueprintReadOnly, Category="Harpoon")
    TObjectPtr<UPrimitiveComponent> HitComponent = nullptr;

    UPROPERTY(BlueprintReadOnly, Category="Harpoon")
    FVector ImpactPoint = FVector::ZeroVector;

    UPROPERTY(BlueprintReadOnly, Category="Harpoon")
    FVector ImpactNormal = FVector::UpVector;

    UPROPERTY(BlueprintReadOnly, Category="Harpoon")
    FVector ImpactVelocity = FVector::ZeroVector;

    UPROPERTY(BlueprintReadOnly, Category="Harpoon")
    FName BoneName = NAME_None;
};

USTRUCT(BlueprintType)
struct JMPHYSICALGRABBER_API FJMHarpoonPullUpdate
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="Harpoon")
    float DeltaTime = 0.0f;

    UPROPERTY(BlueprintReadOnly, Category="Harpoon")
    float PullElapsed = 0.0f;

    UPROPERTY(BlueprintReadOnly, Category="Harpoon")
    float Distance = 0.0f;

    UPROPERTY(BlueprintReadOnly, Category="Harpoon")
    float AppliedForce = 0.0f;

    UPROPERTY(BlueprintReadOnly, Category="Harpoon")
    float ReactionProgress = 0.0f;
};
