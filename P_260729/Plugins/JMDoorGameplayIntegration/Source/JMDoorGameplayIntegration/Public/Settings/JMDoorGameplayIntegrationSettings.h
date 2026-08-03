#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "JMDoorGameplayIntegrationSettings.generated.h"

/**
 * Project-wide defaults for the automatically-created door interaction adapter.
 * Add a JMDoorInteractableAdapterComponent to an individual door to override them.
 */
UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "JM Door Gameplay Integration"))
class JMDOORGAMEPLAYINTEGRATION_API UJMDoorGameplayIntegrationSettings : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    UJMDoorGameplayIntegrationSettings();

    UPROPERTY(Config, EditAnywhere, Category = "Interaction Prompt")
    FText OpenDoorPrompt;

    UPROPERTY(Config, EditAnywhere, Category = "Interaction Prompt")
    FText CloseDoorPrompt;

    UPROPERTY(Config, EditAnywhere, Category = "Interaction Prompt")
    FText LockedDoorPrompt;

    virtual FName GetCategoryName() const override { return TEXT("JM Plugins"); }
};
