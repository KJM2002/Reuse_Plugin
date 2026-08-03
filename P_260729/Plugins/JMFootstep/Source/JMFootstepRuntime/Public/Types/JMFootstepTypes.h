#pragma once

#include "CoreMinimal.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "JMFootstepTypes.generated.h"

class AActor;
class UPhysicalMaterial;
class USoundBase;

UENUM(BlueprintType)
enum class EJMFootstepLocomotionState : uint8
{
    Idle,
    Walk,
    Run,
    CrouchWalk
};

UENUM(BlueprintType)
enum class EJMFootstepFoot : uint8
{
    Left,
    Right
};

UENUM(BlueprintType)
enum class EJMFootstepTriggerMode : uint8
{
    DistanceBased UMETA(DisplayName = "Distance Based"),
    ManualOnly UMETA(DisplayName = "Manual Only")
};

UENUM(BlueprintType)
enum class EJMFootstepFailureReason : uint8
{
    None,
    InvalidOwner,
    NotGrounded,
    NotMoving,
    TraceFailed,
    PhysicalMaterialMissing,
    SurfaceProfileMissing,
    SoundMissing,
    SettingsMissing
};

USTRUCT(BlueprintType)
struct JMFOOTSTEPRUNTIME_API FJMFootstepContext
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep")
    TObjectPtr<AActor> Instigator = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep|Trace")
    bool bOverrideTraceOrigin = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep|Trace", meta = (EditCondition = "bOverrideTraceOrigin"))
    FVector TraceOrigin = FVector::ZeroVector;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep|State")
    bool bOverrideLocomotionState = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep|State", meta = (EditCondition = "bOverrideLocomotionState"))
    EJMFootstepLocomotionState LocomotionState = EJMFootstepLocomotionState::Walk;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep|State")
    bool bOverrideLogicalFoot = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep|State", meta = (EditCondition = "bOverrideLogicalFoot"))
    EJMFootstepFoot LogicalFoot = EJMFootstepFoot::Left;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep|Audio", meta = (ClampMin = "0.0"))
    float VolumeMultiplier = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep|Audio", meta = (ClampMin = "0.01"))
    float PitchMultiplier = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Footstep")
    FName OptionalContextTag = NAME_None;
};

USTRUCT(BlueprintType)
struct JMFOOTSTEPRUNTIME_API FJMFootstepResult
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "Footstep")
    bool bSucceeded = false;

    UPROPERTY(BlueprintReadOnly, Category = "Footstep")
    EJMFootstepFailureReason FailureReason = EJMFootstepFailureReason::None;

    UPROPERTY(BlueprintReadOnly, Category = "Footstep")
    EJMFootstepLocomotionState LocomotionState = EJMFootstepLocomotionState::Idle;

    UPROPERTY(BlueprintReadOnly, Category = "Footstep")
    EJMFootstepLocomotionState SelectedVariantState = EJMFootstepLocomotionState::Idle;

    UPROPERTY(BlueprintReadOnly, Category = "Footstep")
    bool bUsedVariantFallback = false;

    UPROPERTY(BlueprintReadOnly, Category = "Footstep")
    bool bUsedLegacyVariant = false;

    UPROPERTY(BlueprintReadOnly, Category = "Footstep")
    EJMFootstepFoot LogicalFoot = EJMFootstepFoot::Left;

    UPROPERTY(BlueprintReadOnly, Category = "Footstep")
    TEnumAsByte<EPhysicalSurface> SurfaceType = SurfaceType_Default;

    UPROPERTY(BlueprintReadOnly, Category = "Footstep")
    TObjectPtr<UPhysicalMaterial> PhysicalMaterial = nullptr;

    UPROPERTY(BlueprintReadOnly, Category = "Footstep")
    TObjectPtr<USoundBase> SelectedSound = nullptr;

    UPROPERTY(BlueprintReadOnly, Category = "Footstep")
    FVector ImpactPoint = FVector::ZeroVector;

    UPROPERTY(BlueprintReadOnly, Category = "Footstep")
    FVector ImpactNormal = FVector::UpVector;

    UPROPERTY(BlueprintReadOnly, Category = "Footstep")
    float FinalVolume = 0.0f;

    UPROPERTY(BlueprintReadOnly, Category = "Footstep")
    float FinalPitch = 0.0f;

    static FJMFootstepResult Failure(EJMFootstepFailureReason Reason)
    {
        FJMFootstepResult Result;
        Result.FailureReason = Reason;
        return Result;
    }
};
