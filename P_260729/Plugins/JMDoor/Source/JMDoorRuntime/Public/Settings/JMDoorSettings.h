#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/DeveloperSettings.h"
#include "JMDoorSettings.generated.h"

UCLASS(Config=JMDoor, DefaultConfig, meta=(DisplayName="Door", ToolTip="Configure the reusable JM door system."))
class JMDOORRUNTIME_API UJMDoorSettings : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    virtual FName GetCategoryName() const override { return TEXT("JM Plugins"); }
    virtual FName GetSectionName() const override { return TEXT("Door"); }

    UPROPERTY(Config, EditAnywhere, Category="Blocking")
    TEnumAsByte<ECollisionChannel> DefaultBlockingChannel = ECC_Visibility;

    UPROPERTY(Config, EditAnywhere, Category="Debug")
    bool bDrawObstructionDebug = false;

    /** Draw leaf motion, contact point, requested push, actual movement and blocking normals. */
    UPROPERTY(Config, EditAnywhere, Category="Debug")
    bool bDrawCharacterPushDebug = false;

    /** Log leaf delta, requested push, actual movement and sweep result for each contacted character. */
    UPROPERTY(Config, EditAnywhere, Category="Debug")
    bool bLogCharacterPushDebug = false;

    UPROPERTY(Config, EditAnywhere, Category="Debug", meta=(ClampMin="0.0", Units="s"))
    float CharacterPushDebugDuration = 0.1f;

    UPROPERTY(Config, EditAnywhere, Category="Validation")
    bool bWarnOnMissingMovementComponent = true;
};
