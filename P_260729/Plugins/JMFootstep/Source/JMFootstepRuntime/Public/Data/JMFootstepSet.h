#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "JMFootstepSet.generated.h"

class UJMFootstepSurfaceProfile;

USTRUCT(BlueprintType)
struct JMFOOTSTEPRUNTIME_API FJMFootstepSurfaceEntry
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep")
    TEnumAsByte<EPhysicalSurface> SurfaceType = SurfaceType_Default;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep")
    TObjectPtr<UJMFootstepSurfaceProfile> Profile = nullptr;
};

UCLASS(BlueprintType)
class JMFOOTSTEPRUNTIME_API UJMFootstepSet : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep")
    TObjectPtr<UJMFootstepSurfaceProfile> DefaultProfile = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep")
    TArray<FJMFootstepSurfaceEntry> SurfaceProfiles;

    UFUNCTION(BlueprintPure, Category = "JM Footstep")
    UJMFootstepSurfaceProfile* FindProfile(EPhysicalSurface SurfaceType, bool& bUsedFallback) const;
};
