#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "InputCoreTypes.h"
#include "JMThrowableSettings.generated.h"

UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="Throwable"))
class JMTHROWABLE_API UJMThrowableSettings : public UDeveloperSettings
{
    GENERATED_BODY()
public:
    virtual FName GetCategoryName() const override { return TEXT("JM Plugins"); }
    UPROPERTY(Config, EditAnywhere, Category="Input") FKey DefaultAimKey = EKeys::RightMouseButton;
    UPROPERTY(Config, EditAnywhere, Category="Input") FKey DefaultThrowKey = EKeys::LeftMouseButton;
    UPROPERTY(Config, EditAnywhere, Category="Input") FKey DefaultCancelKey = EKeys::Q;
    UPROPERTY(Config, EditAnywhere, Category="Input") int32 InputPriority = 50;
    UPROPERTY(Config, EditAnywhere, Category="Aim", meta=(ClampMin="1")) float PreviewUpdateHz = 30.f;
    UPROPERTY(Config, EditAnywhere, Category="Movement") bool bRestrictMovementWhileAiming = false;
    UPROPERTY(Config, EditAnywhere, Category="Movement") bool bCancelSprintOnAim = false;
    UPROPERTY(Config, EditAnywhere, Category="Movement", meta=(ClampMin="0", ClampMax="1")) float AimMovementSpeedMultiplier = .55f;
    UPROPERTY(Config, EditAnywhere, Category="Debug") bool bDebugThrowableTrajectory = false;
};
