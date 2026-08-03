#pragma once

#include "CoreMinimal.h"
#include "Door/JMDoorTypes.h"
#include "UObject/Interface.h"
#include "JMDoorSaveInterface.generated.h"

UINTERFACE(BlueprintType, Blueprintable)
class JMDOORRUNTIME_API UJMDoorSaveInterface : public UInterface
{
    GENERATED_BODY()
};

class JMDOORRUNTIME_API IJMDoorSaveInterface : public IInterface
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM Door|Save")
    FGuid GetDoorPersistentId() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM Door|Save")
    FJMDoorSaveData CaptureDoorSaveData() const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM Door|Save")
    bool RestoreDoorSaveData(const FJMDoorSaveData& SaveData);
};
