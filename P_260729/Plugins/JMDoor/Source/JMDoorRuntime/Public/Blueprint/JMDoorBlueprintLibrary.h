#pragma once

#include "CoreMinimal.h"
#include "Door/JMDoorTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "JMDoorBlueprintLibrary.generated.h"

UCLASS()
class JMDOORRUNTIME_API UJMDoorBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, Category="JM Door")
    static FJMDoorUseContext MakeDoorUseContext(AActor* InstigatorActor, FVector InteractionLocation, const FGameplayTagContainer& AccessTags, bool bIsAI = false, bool bQuiet = false, bool bFast = false, float RequestedOpenFraction = 1.0f);

    UFUNCTION(BlueprintCallable, Category="JM Door")
    static FJMDoorResult ExecuteDoorCommandOnObject(UObject* DoorObject, EJMDoorCommand Command, const FJMDoorUseContext& Context);
};
