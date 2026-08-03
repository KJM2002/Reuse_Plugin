#pragma once

#include "CoreMinimal.h"
#include "Door/JMDoorTypes.h"
#include "UObject/Object.h"
#include "JMDoorTestEventReceiver.generated.h"

UCLASS()
class UJMDoorTestEventReceiver final : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION()
    void HandleNoise(FJMDoorNoiseEvent NoiseEvent);

    int32 NoiseCount = 0;
    FGameplayTag LastNoiseTag;
};
