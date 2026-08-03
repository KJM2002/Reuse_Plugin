#include "Items/InventoryUseOnActorComponentsEffect.h"

#include "Components/ActorComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Pawn.h"
#include "Interfaces/InventoryItemUseReceiverInterface.h"

namespace
{
    void GatherReceiversOnActor(AActor* Actor, TArray<UObject*>& OutReceivers)
    {
        if (!IsValid(Actor))
        {
            return;
        }

        if (Actor->GetClass()->ImplementsInterface(UInventoryItemUseReceiverInterface::StaticClass()))
        {
            OutReceivers.AddUnique(Actor);
        }
        for (UActorComponent* Component : Actor->GetComponents())
        {
            if (IsValid(Component) && Component->GetClass()->ImplementsInterface(UInventoryItemUseReceiverInterface::StaticClass()))
            {
                OutReceivers.AddUnique(Component);
            }
        }
    }

    void GatherUseReceivers(AActor* User, TArray<UObject*>& OutReceivers)
    {
        GatherReceiversOnActor(User, OutReceivers);
        if (APawn* Pawn = Cast<APawn>(User))
        {
            GatherReceiversOnActor(Pawn->GetController(), OutReceivers);
        }
        else if (AController* Controller = Cast<AController>(User))
        {
            GatherReceiversOnActor(Controller->GetPawn(), OutReceivers);
        }
    }
}

bool UInventoryUseOnActorComponentsEffect::CanUse_Implementation(AActor* User, const FInventorySlot& Slot) const
{
    TArray<UObject*> Receivers;
    GatherUseReceivers(User, Receivers);
    for (UObject* Receiver : Receivers)
    {
        if (IInventoryItemUseReceiverInterface::Execute_CanReceiveInventoryItemUse(Receiver, User, nullptr, Slot))
        {
            return true;
        }
    }
    return false;
}

bool UInventoryUseOnActorComponentsEffect::ExecuteUse_Implementation(AActor* User, UInventoryComponent* Inventory, const FInventorySlot& Slot)
{
    TArray<UObject*> Receivers;
    GatherUseReceivers(User, Receivers);
    for (UObject* Receiver : Receivers)
    {
        if (IInventoryItemUseReceiverInterface::Execute_CanReceiveInventoryItemUse(Receiver, User, Inventory, Slot) &&
            IInventoryItemUseReceiverInterface::Execute_ReceiveInventoryItemUse(Receiver, User, Inventory, Slot))
        {
            return true;
        }
    }
    return false;
}
