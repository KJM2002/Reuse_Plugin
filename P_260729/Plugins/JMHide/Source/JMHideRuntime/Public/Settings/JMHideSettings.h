#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Types/JMHideTypes.h"
#include "JMHideSettings.generated.h"

UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="JM Hide"))
class JMHIDERUNTIME_API UJMHideSettings final : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    UPROPERTY(Config, EditAnywhere, Category="Defaults")
    FJMHideConfigValues Defaults;

    virtual FName GetCategoryName() const override { return TEXT("Plugins"); }
};
