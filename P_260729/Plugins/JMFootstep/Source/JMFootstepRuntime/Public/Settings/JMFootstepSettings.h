#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Engine/EngineTypes.h"
#include "Types/JMFootstepTypes.h"
#include "UObject/SoftObjectPtr.h"
#include "JMFootstepSettings.generated.h"

class UJMFootstepSet;

UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Footstep", ToolTip = "Configure the reusable JM distance-driven footstep system."))
class JMFOOTSTEPRUNTIME_API UJMFootstepSettings : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    UJMFootstepSettings();

    static const UJMFootstepSettings* Get();
    virtual FName GetCategoryName() const override;

    UPROPERTY(EditAnywhere, Config, Category = "Data", meta = (DisplayName = "Default Footstep Set"))
    TSoftObjectPtr<UJMFootstepSet> DefaultFootstepSet;

    UPROPERTY(EditAnywhere, Config, Category = "Trigger")
    EJMFootstepTriggerMode TriggerMode = EJMFootstepTriggerMode::DistanceBased;

    UPROPERTY(EditAnywhere, Config, Category = "Movement", meta = (ClampMin = "0.0", Units = "cm/s"))
    float MinimumMovementSpeed = 10.0f;

    UPROPERTY(EditAnywhere, Config, Category = "Movement", meta = (ClampMin = "0.0", Units = "cm/s"))
    float RunSpeedThreshold = 325.0f;

    UPROPERTY(EditAnywhere, Config, Category = "Movement", meta = (ClampMin = "1.0", Units = "cm"))
    float WalkStepDistance = 110.0f;

    UPROPERTY(EditAnywhere, Config, Category = "Movement", meta = (ClampMin = "1.0", Units = "cm"))
    float RunStepDistance = 140.0f;

    UPROPERTY(EditAnywhere, Config, Category = "Movement", meta = (ClampMin = "1.0", Units = "cm"))
    float CrouchStepDistance = 80.0f;

    UPROPERTY(EditAnywhere, Config, Category = "Movement", meta = (ClampMin = "1.0", Units = "cm", ToolTip = "A single frame delta at or above this value is treated as teleportation."))
    float TeleportDistanceThreshold = 500.0f;

    UPROPERTY(EditAnywhere, Config, Category = "Movement", meta = (ClampMin = "1", ClampMax = "8"))
    int32 MaxStepsPerFrame = 2;

    UPROPERTY(EditAnywhere, Config, Category = "Trace", meta = (ClampMin = "1.0", Units = "cm"))
    float TraceDistance = 70.0f;

    UPROPERTY(EditAnywhere, Config, Category = "Trace", meta = (ClampMin = "0.0", Units = "cm"))
    float TraceStartOffset = 10.0f;

    UPROPERTY(EditAnywhere, Config, Category = "Trace")
    TEnumAsByte<ECollisionChannel> TraceChannel = ECC_Visibility;

    UPROPERTY(EditAnywhere, Config, Category = "Audio", meta = (ClampMin = "0.0"))
    float DefaultVolumeMultiplier = 1.0f;

    UPROPERTY(EditAnywhere, Config, Category = "Audio", meta = (ClampMin = "0.01"))
    float DefaultPitchMultiplier = 1.0f;

    UPROPERTY(EditAnywhere, Config, Category = "Audio", meta = (ClampMin = "0.0"))
    float WalkVolumeMultiplier = 0.75f;

    UPROPERTY(EditAnywhere, Config, Category = "Audio", meta = (ClampMin = "0.0"))
    float RunVolumeMultiplier = 1.0f;

    UPROPERTY(EditAnywhere, Config, Category = "Audio", meta = (ClampMin = "0.0"))
    float CrouchVolumeMultiplier = 0.35f;

    UPROPERTY(EditAnywhere, Config, Category = "Debug")
    bool bEnableDebug = false;
};
