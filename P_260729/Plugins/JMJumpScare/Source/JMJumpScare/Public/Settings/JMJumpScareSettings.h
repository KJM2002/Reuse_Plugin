#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Types/JMJumpScareTypes.h"
#include "JMJumpScareSettings.generated.h"

UCLASS(Config=JMJumpScare, DefaultConfig, meta=(DisplayName="JM JumpScare", ToolTip="Configure reusable JM JumpScare runtime defaults."))
class JMJUMPSCARE_API UJMJumpScareSettings : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    virtual FName GetCategoryName() const override { return TEXT("Plugins"); }
    virtual FName GetSectionName() const override { return TEXT("JM JumpScare"); }

    UPROPERTY(Config, EditAnywhere, Category="Debug")
    bool bEnableDebugLogging = false;

    UPROPERTY(Config, EditAnywhere, Category="Debug")
    bool bShowDebugSpawnTransform = false;

    UPROPERTY(Config, EditAnywhere, Category="Defaults")
    EJMJumpScareTriggerPolicy DefaultTriggerPolicy = EJMJumpScareTriggerPolicy::Once;

    UPROPERTY(Config, EditAnywhere, Category="Defaults")
    EJMJumpScareOverlapFilter DefaultOverlapActorFilter = EJMJumpScareOverlapFilter::PlayerControlledPawn;

    UPROPERTY(Config, EditAnywhere, Category="Defaults")
    EJMJumpScareConcurrentPolicy DefaultConcurrentPolicy = EJMJumpScareConcurrentPolicy::IgnoreNew;
};
