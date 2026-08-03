#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interfaces/JMInteractionInputInterceptorInterface.h"
#include "Types/JMInteractionTypes.h"
#include "JMHideInputRouterComponent.generated.h"

/** Called by host-owned input. This component never registers an Input Action. */
UCLASS(ClassGroup=(JMHide), meta=(BlueprintSpawnableComponent), BlueprintType)
class JMHIDEINTERACTIONINTEGRATION_API UJMHideInputRouterComponent final
    : public UActorComponent
    , public IJMInteractionInputInterceptorInterface
{
    GENERATED_BODY()

public:
    UJMHideInputRouterComponent();

    UFUNCTION(BlueprintCallable, Category="JM Hide|Input")
    FJMInteractionResult RouteHostInteractInput();

    virtual bool TryHandleInteractionInput_Implementation(
        FJMInteractionResult& OutResult) override;
};
