#include "Blueprint/JMDoorBlueprintLibrary.h"

#include "GameFramework/Controller.h"
#include "GameFramework/Pawn.h"
#include "Interfaces/JMDoorUsableInterface.h"
#include "Interfaces/JMDoorInterfaceDispatch.h"

FJMDoorUseContext UJMDoorBlueprintLibrary::MakeDoorUseContext(AActor* InstigatorActor, FVector InteractionLocation, const FGameplayTagContainer& AccessTags, bool bIsAI, bool bQuiet, bool bFast, float RequestedOpenFraction)
{
    FJMDoorUseContext Context;
    Context.InstigatorActor = InstigatorActor;
    Context.InteractionLocation = InteractionLocation;
    Context.InteractionDirection = IsValid(InstigatorActor) ? InstigatorActor->GetActorForwardVector() : FVector::ZeroVector;
    Context.AccessTags = AccessTags;
    Context.bIsAI = bIsAI;
    Context.bQuiet = bQuiet;
    Context.bFast = bFast;
    Context.RequestedOpenFraction = FMath::Clamp(RequestedOpenFraction, 0.0f, 1.0f);
    if (const APawn* Pawn = Cast<APawn>(InstigatorActor))
    {
        Context.InstigatorController = Pawn->GetController();
    }
    else
    {
        Context.InstigatorController = Cast<AController>(InstigatorActor);
    }
    return Context;
}

FJMDoorResult UJMDoorBlueprintLibrary::ExecuteDoorCommandOnObject(UObject* DoorObject, EJMDoorCommand Command, const FJMDoorUseContext& Context)
{
    if (!IsValid(DoorObject) || !DoorObject->GetClass()->ImplementsInterface(UJMDoorUsableInterface::StaticClass()))
    {
        return FJMDoorResult::Failure(EJMDoorResultCode::InvalidRequest, NSLOCTEXT("JMDoor", "NotDoorUsable", "The object does not implement the JM Door Usable interface."));
    }
    return JMDoorInterfaceDispatch::ExecuteDoorCommand(DoorObject, Command, Context);
}
