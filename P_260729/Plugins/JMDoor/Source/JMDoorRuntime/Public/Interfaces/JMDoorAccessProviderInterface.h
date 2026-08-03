#pragma once

#include "CoreMinimal.h"
#include "Door/JMDoorTypes.h"
#include "UObject/Interface.h"
#include "JMDoorAccessProviderInterface.generated.h"

UINTERFACE(BlueprintType, Blueprintable)
class JMDOORRUNTIME_API UJMDoorAccessProviderInterface : public UInterface
{
    GENERATED_BODY()
};

class JMDOORRUNTIME_API IJMDoorAccessProviderInterface : public IInterface
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM Door|Access")
    FGameplayTagContainer GetDoorAccessTags() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM Door|Access")
    bool CanProvideDoorAccess(const FJMDoorAccessRequirement& Requirement) const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM Door|Access")
    bool ConsumeDoorAccess(const FJMDoorAccessRequirement& Requirement);
};
