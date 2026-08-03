#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "JMDoorReconIntegrationSettings.generated.h"

UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="JM Door Recon Integration"))
class JMDOORRECONINTEGRATION_API UJMDoorReconIntegrationSettings : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    UPROPERTY(Config, EditAnywhere, Category="Automatic Setup")
    bool bAutoAddDoorAdapter = true;

    UPROPERTY(Config, EditAnywhere, Category="Door Pose", meta=(ClampMin="0.0", Units="s"))
    float OpenBlendDuration = 0.25f;

    UPROPERTY(Config, EditAnywhere, Category="Door Pose", meta=(ClampMin="0.0", Units="s"))
    float RestoreBlendDuration = 0.2f;

    UPROPERTY(Config, EditAnywhere, Category="Door Pose", AdvancedDisplay, meta=(ClampMin="0.0", ClampMax="1.0"))
    float MaximumExistingOpenFraction = 0.95f;

    virtual FName GetCategoryName() const override { return TEXT("Plugins"); }
};
