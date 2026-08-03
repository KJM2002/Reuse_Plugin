#pragma once

#include "CoreMinimal.h"
#include "Door/JMDoorTypes.h"
#include "UObject/Interface.h"
#include "JMDoorUsableInterface.generated.h"

UINTERFACE(BlueprintType, Blueprintable)
class JMDOORRUNTIME_API UJMDoorUsableInterface : public UInterface
{
    GENERATED_BODY()
};

class JMDOORRUNTIME_API IJMDoorUsableInterface : public IInterface
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM Door")
    FJMDoorResult ExecuteDoorCommand(EJMDoorCommand Command, const FJMDoorUseContext& Context);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM Door")
    bool CanExecuteDoorCommand(EJMDoorCommand Command, const FJMDoorUseContext& Context) const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM Door")
    EJMDoorState GetDoorState() const;
};
