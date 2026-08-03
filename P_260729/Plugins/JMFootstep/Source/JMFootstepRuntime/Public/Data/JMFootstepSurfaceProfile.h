#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Types/JMFootstepTypes.h"
#include "JMFootstepSurfaceProfile.generated.h"

class USoundAttenuation;
class USoundBase;

USTRUCT(BlueprintType)
struct JMFOOTSTEPRUNTIME_API FJMFootstepSoundVariant
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep", meta = (ToolTip = "Sounds randomly selected for this locomotion state. Null entries are ignored."))
    TArray<TObjectPtr<USoundBase>> Sounds;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep", meta = (ClampMin = "0.0", ToolTip = "Minimum natural volume variation before state and request multipliers."))
    float VolumeMin = 0.9f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep", meta = (ClampMin = "0.0", ToolTip = "Maximum natural volume variation before state and request multipliers."))
    float VolumeMax = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep", meta = (ClampMin = "0.01", ToolTip = "Minimum natural pitch variation."))
    float PitchMin = 0.95f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep", meta = (ClampMin = "0.01", ToolTip = "Maximum natural pitch variation."))
    float PitchMax = 1.05f;

    bool HasValidSound() const;
    int32 GetValidSoundCount() const;
};

UCLASS(BlueprintType)
class JMFOOTSTEPRUNTIME_API UJMFootstepSurfaceProfile : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Walk", meta = (DisplayName = "Walk Variant"))
    FJMFootstepSoundVariant WalkVariant;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Run", meta = (DisplayName = "Run Variant"))
    FJMFootstepSoundVariant RunVariant;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Crouch Walk", meta = (DisplayName = "Crouch Walk Variant"))
    FJMFootstepSoundVariant CrouchWalkVariant;

    /**
     * v1.0 compatibility fallback. Kept with the original property name and type
     * so existing UJMFootstepSurfaceProfile assets continue to deserialize.
     */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Legacy Compatibility", meta = (DisplayName = "Legacy Sounds (v1.0 Fallback)", ToolTip = "Used only when the requested locomotion variant and its Walk fallback contain no valid sounds."))
    TArray<TObjectPtr<USoundBase>> Sounds;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Legacy Compatibility", meta = (DisplayName = "Legacy Volume Min", ClampMin = "0.0"))
    float VolumeMin = 0.9f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Legacy Compatibility", meta = (DisplayName = "Legacy Volume Max", ClampMin = "0.0"))
    float VolumeMax = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Legacy Compatibility", meta = (DisplayName = "Legacy Pitch Min", ClampMin = "0.01"))
    float PitchMin = 0.95f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Legacy Compatibility", meta = (DisplayName = "Legacy Pitch Max", ClampMin = "0.01"))
    float PitchMax = 1.05f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Spatial Audio")
    TObjectPtr<USoundAttenuation> AttenuationSettings = nullptr;

    /**
     * Resolves a copy of the data used for the requested gait.
     * Run/CrouchWalk may fall back to Walk; every gait may fall back to v1.0 fields.
     * Idle is invalid and returns false.
     */
    UFUNCTION(BlueprintPure, Category = "JM Footstep")
    bool ResolveVariant(
        EJMFootstepLocomotionState RequestedState,
        FJMFootstepSoundVariant& OutVariant,
        EJMFootstepLocomotionState& OutSelectedVariantState,
        bool& bOutUsedFallback,
        bool& bOutUsedLegacyVariant) const;

    bool HasValidLegacySound() const;
};
