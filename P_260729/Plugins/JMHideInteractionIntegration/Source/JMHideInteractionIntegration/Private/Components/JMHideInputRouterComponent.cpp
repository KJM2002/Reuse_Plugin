#include "Components/JMHideInputRouterComponent.h"

#include "Components/JMHideInteractorComponent.h"
#include "JMHideInputRouterLibrary.h"

UJMHideInputRouterComponent::UJMHideInputRouterComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

FJMInteractionResult UJMHideInputRouterComponent::RouteHostInteractInput()
{
    return UJMHideInputRouterLibrary::RouteHostInteractInput(GetOwner());
}

bool UJMHideInputRouterComponent::TryHandleInteractionInput_Implementation(
    FJMInteractionResult& OutResult)
{
    UJMHideInteractorComponent* Hide =
        GetOwner() ? GetOwner()->FindComponentByClass<UJMHideInteractorComponent>() : nullptr;
    if (!Hide || !Hide->IsHidden())
    {
        return false;
    }
    OutResult = UJMHideInputRouterLibrary::RouteHostInteractInput(GetOwner());
    return true;
}
