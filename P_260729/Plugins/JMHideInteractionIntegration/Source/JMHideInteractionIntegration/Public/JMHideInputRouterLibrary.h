#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Types/JMInteractionTypes.h"
#include "JMHideInputRouterLibrary.generated.h"

/**
 * Host-owned interaction input route.
 * Hidden participants exit directly; everyone else keeps the normal JMInteraction path.
 */
UCLASS()
class JMHIDEINTERACTIONINTEGRATION_API UJMHideInputRouterLibrary final
    : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category="JM Hide|Input", meta=(DefaultToSelf="Host"))
    static FJMInteractionResult RouteHostInteractInput(AActor* Host);
};
