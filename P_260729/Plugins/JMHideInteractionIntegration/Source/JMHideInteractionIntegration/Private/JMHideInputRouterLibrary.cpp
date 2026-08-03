#include "JMHideInputRouterLibrary.h"

#include "Components/JMHideInteractorComponent.h"
#include "Components/JMInteractionComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogJMHideDebug, Log, All);

FJMInteractionResult UJMHideInputRouterLibrary::RouteHostInteractInput(AActor* Host)
{
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
    UE_LOG(LogJMHideDebug, Log, TEXT("Interact input received: Host=%s"), *GetNameSafe(Host));
#endif

    UJMHideInteractorComponent* Hide =
        Host ? Host->FindComponentByClass<UJMHideInteractorComponent>() : nullptr;
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
    UE_LOG(LogJMHideDebug, Log, TEXT("Interactor %s: Component=%s State=%d Spot=%s"),
        Hide ? TEXT("found") : TEXT("missing"),
        *GetNameSafe(Hide),
        Hide ? static_cast<int32>(Hide->GetCurrentPhase()) : -1,
        Hide ? *GetNameSafe(Hide->GetCurrentHideSpot()) : TEXT("None"));
#endif

    if (Hide && Hide->IsHidden())
    {
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
        UE_LOG(LogJMHideDebug, Log, TEXT("Routing input to TryExitCurrentHideSpot"));
#endif
        const FJMHideResult Result = Hide->TryExitCurrentHideSpot();
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
        UE_LOG(LogJMHideDebug, Log, TEXT("Exit command result: Success=%s FailureCode=%d Message=%s"),
            Result.bSucceeded ? TEXT("true") : TEXT("false"),
            static_cast<int32>(Result.Code),
            *Result.Message.ToString());
#endif
        return Result.bSucceeded
            ? FJMInteractionResult::Success()
            : FJMInteractionResult::Failure(EJMInteractionResultCode::NotAllowed, Result.Message);
    }

    UJMInteractionComponent* Interaction =
        Host ? Host->FindComponentByClass<UJMInteractionComponent>() : nullptr;
    return Interaction
        ? Interaction->TryBeginInteraction()
        : FJMInteractionResult::Failure(EJMInteractionResultCode::NoTarget,
            NSLOCTEXT("JMHideInteraction", "MissingInteraction", "JMInteractionComponent is missing."));
}
