#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "JMObjectiveSettings.generated.h"

class UJMObjectiveWidgetBase;

UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "JM Objective"))
class JMOBJECTIVE_API UJMObjectiveSettings : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    virtual FName GetCategoryName() const override { return TEXT("JM Plugins"); }

    UPROPERTY(Config, EditAnywhere, Category = "Debug")
    bool bEnableDebugLogging = false;

    UPROPERTY(Config, EditAnywhere, Category = "Debug", meta = (EditCondition = "bEnableDebugLogging"))
    bool bLogObjectiveRegistration = false;

    UPROPERTY(Config, EditAnywhere, Category = "Debug", meta = (EditCondition = "bEnableDebugLogging"))
    bool bLogEventFiltering = false;

    UPROPERTY(Config, EditAnywhere, Category = "Debug", meta = (EditCondition = "bEnableDebugLogging"))
    bool bLogProgressChanges = false;

    UPROPERTY(Config, EditAnywhere, Category = "Debug", meta = (EditCondition = "bEnableDebugLogging"))
    bool bLogStateChanges = false;

    UPROPERTY(Config, EditAnywhere, Category = "Validation")
    bool bWarnDuplicateObjectiveId = true;

    UPROPERTY(Config, EditAnywhere, Category = "UI")
    TSoftClassPtr<UJMObjectiveWidgetBase> DefaultObjectiveWidgetClass;

    UPROPERTY(Config, EditAnywhere, Category = "UI")
    bool bAutomaticallyCreateObjectiveUI = true;

    UPROPERTY(Config, EditAnywhere, Category = "UI")
    int32 ObjectiveWidgetZOrder = 10;

    UPROPERTY(Config, EditAnywhere, Category = "UI")
    bool bHideWidgetWhenNoActiveObjective = true;

    UPROPERTY(Config, EditAnywhere, Category = "UI", meta = (ClampMin = "0.0", UIMin = "0.0"))
    float CompletedDisplayDuration = 1.5f;
};
