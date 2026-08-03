#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "JMReconSettings.generated.h"

class UJMReconDefinition;

UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="JM Recon"))
class JMRECONRUNTIME_API UJMReconSettings : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    UJMReconSettings();

    UPROPERTY(Config, EditAnywhere, Category="Defaults")
    TSoftObjectPtr<UJMReconDefinition> DefaultReconDefinition;

    UPROPERTY(Config, EditAnywhere, Category="Defaults", meta=(ClampMin="0.0"))
    float DefaultCameraBlendTime = 0.2f;

    UPROPERTY(Config, EditAnywhere, Category="Debug")
    bool bDebugEnabled = false;

    virtual FName GetCategoryName() const override { return TEXT("Plugins"); }
};
