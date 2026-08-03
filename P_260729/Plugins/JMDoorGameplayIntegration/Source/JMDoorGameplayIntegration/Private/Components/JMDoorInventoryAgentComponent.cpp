#include "Components/JMDoorInventoryAgentComponent.h"

#include "Actors/JMDoorActor.h"
#include "Components/InventoryUIComponent.h"
#include "Door/JMDoorComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Pawn.h"
#include "Items/InventoryItemDefinition.h"

DEFINE_LOG_CATEGORY_STATIC(LogJMDoorInventoryIntegration, Log, All);

namespace
{
void CloseInventoryUIsForActorGraph(AActor* Owner)
{
    if (!Owner)
    {
        return;
    }

    TArray<UInventoryUIComponent*> InventoryUIs;
    if (UInventoryUIComponent* OwnerUI = Owner->FindComponentByClass<UInventoryUIComponent>())
    {
        InventoryUIs.AddUnique(OwnerUI);
    }

    if (const APawn* Pawn = Cast<APawn>(Owner))
    {
        if (AController* Controller = Pawn->GetController())
        {
            if (UInventoryUIComponent* ControllerUI = Controller->FindComponentByClass<UInventoryUIComponent>())
            {
                InventoryUIs.AddUnique(ControllerUI);
            }
        }
    }
    else if (const AController* Controller = Cast<AController>(Owner))
    {
        if (APawn* ControlledPawn = Controller->GetPawn())
        {
            if (UInventoryUIComponent* PawnUI = ControlledPawn->FindComponentByClass<UInventoryUIComponent>())
            {
                InventoryUIs.AddUnique(PawnUI);
            }
        }
    }

    for (UInventoryUIComponent* InventoryUI : InventoryUIs)
    {
        InventoryUI->CloseInventory();
    }
}
}

UJMDoorInventoryAgentComponent::UJMDoorInventoryAgentComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

bool UJMDoorInventoryAgentComponent::BeginLockedDoorItemSelection(AJMDoorActor* Door, const FJMInteractionContext& InteractionContext)
{
    if (!SetPendingDoorForItemUse(Door, InteractionContext))
    {
        return false;
    }

    UInventoryUIComponent* InventoryUI = ResolveInventoryUI();
    if (!InventoryUI || !InventoryUI->OpenInventory())
    {
        UE_LOG(LogJMDoorInventoryIntegration, Warning, TEXT("Locked door target was set, but Inventory UI could not be opened for %s."), *GetNameSafe(GetOwner()));
        ClearPendingDoor();
        return false;
    }
    return true;
}

bool UJMDoorInventoryAgentComponent::SetPendingDoorForItemUse(AJMDoorActor* Door, const FJMInteractionContext& InteractionContext)
{
    if (!IsValid(Door) || !Door->DoorComponent || !Door->DoorComponent->IsLocked())
    {
        return false;
    }
    PendingDoor = Door;
    PendingInteractionContext = InteractionContext;
    OnPendingDoorChanged.Broadcast(Door);
    UE_LOG(LogJMDoorInventoryIntegration, Log, TEXT("Pending locked door set: user=%s, door=%s."), *GetNameSafe(GetOwner()), *GetNameSafe(Door));
    return true;
}

void UJMDoorInventoryAgentComponent::ClearPendingDoor()
{
    PendingDoor.Reset();
    PendingInteractionContext = FJMInteractionContext();
    OnPendingDoorChanged.Broadcast(nullptr);
}

bool UJMDoorInventoryAgentComponent::UseItemOnPendingDoor(UInventoryItemDefinition* ItemDefinition, AActor* User)
{
    if (!IsValid(ItemDefinition))
    {
        return false;
    }
    FInventorySlot Slot;
    Slot.ItemDefinition = ItemDefinition;
    Slot.Quantity = 1;
    return ReceiveInventoryItemUse_Implementation(IsValid(User) ? User : GetOwner(), nullptr, Slot);
}

bool UJMDoorInventoryAgentComponent::CanReceiveInventoryItemUse_Implementation(AActor* User, UInventoryComponent* Inventory, const FInventorySlot& Slot) const
{
    const AJMDoorActor* Door = PendingDoor.Get();
    if (!IsValid(Door) || !Door->DoorComponent || !Door->DoorComponent->IsLocked() || !IsValid(Slot.ItemDefinition))
    {
        UE_LOG(LogJMDoorInventoryIntegration, Warning, TEXT("Item use rejected because the pending door or item is invalid. user=%s, door=%s, item=%s."), *GetNameSafe(GetOwner()), *GetNameSafe(Door), *GetNameSafe(Slot.ItemDefinition));
        return false;
    }

    FJMDoorUseContext DoorContext;
    DoorContext.InstigatorActor = IsValid(User) ? User : GetOwner();
    DoorContext.InstigatorController = PendingInteractionContext.InstigatorController;
    DoorContext.InteractionLocation = PendingInteractionContext.InteractionLocation;
    DoorContext.InteractionDirection = PendingInteractionContext.InteractionDirection;
    DoorContext.AccessTags = Slot.ItemDefinition->ItemTags;
    DoorContext.AccessObject = Slot.ItemDefinition;
    const bool bCanOpen = Door->DoorComponent->CanExecuteCommand(EJMDoorCommand::Open, DoorContext);
    if (!bCanOpen)
    {
        UE_LOG(LogJMDoorInventoryIntegration, Warning, TEXT("Item %s does not satisfy access for door %s. Tags=%s"), *GetNameSafe(Slot.ItemDefinition), *GetNameSafe(Door), *Slot.ItemDefinition->ItemTags.ToStringSimple());
    }
    return bCanOpen;
}

bool UJMDoorInventoryAgentComponent::ReceiveInventoryItemUse_Implementation(AActor* User, UInventoryComponent* Inventory, const FInventorySlot& Slot)
{
    AJMDoorActor* Door = PendingDoor.Get();
    if (!CanReceiveInventoryItemUse_Implementation(User, Inventory, Slot) || !Door)
    {
        return false;
    }

    FJMDoorUseContext DoorContext;
    DoorContext.InstigatorActor = IsValid(User) ? User : GetOwner();
    DoorContext.InstigatorController = PendingInteractionContext.InstigatorController;
    DoorContext.InteractionLocation = PendingInteractionContext.InteractionLocation;
    DoorContext.InteractionDirection = PendingInteractionContext.InteractionDirection;
    DoorContext.AccessTags = Slot.ItemDefinition->ItemTags;
    DoorContext.AccessObject = Slot.ItemDefinition;
    DoorContext.RequestedOpenFraction = 1.0f;
    const FJMDoorResult Result = Door->DoorComponent->OpenDoor(DoorContext);
    if (!Result.bSucceeded)
    {
        UE_LOG(LogJMDoorInventoryIntegration, Warning, TEXT("Door open failed after item use: door=%s, code=%d, message=%s"), *GetNameSafe(Door), static_cast<int32>(Result.Code), *Result.Message.ToString());
        return false;
    }

    // Old project blueprints may still contain an InventoryUIComponent on both
    // the Pawn and PlayerController. Close every UI in that ownership graph so
    // a duplicate widget cannot remain on screen after the key succeeds.
    CloseInventoryUIsForActorGraph(GetOwner());
    ClearPendingDoor();
    UE_LOG(LogJMDoorInventoryIntegration, Log, TEXT("Door opened through inventory item use: door=%s, item=%s."), *GetNameSafe(Door), *GetNameSafe(Slot.ItemDefinition));
    return true;
}

UInventoryUIComponent* UJMDoorInventoryAgentComponent::ResolveInventoryUI() const
{
    AActor* Owner = GetOwner();
    if (!Owner)
    {
        return nullptr;
    }
    // PlayerController owns input mode and viewport UI. Prefer its component
    // even when a legacy Pawn blueprint also contains an InventoryUIComponent.
    if (const APawn* Pawn = Cast<APawn>(Owner))
    {
        if (AController* Controller = Pawn->GetController())
        {
            if (UInventoryUIComponent* ControllerUI = Controller->FindComponentByClass<UInventoryUIComponent>())
            {
                return ControllerUI;
            }
        }
    }
    if (UInventoryUIComponent* Component = Owner->FindComponentByClass<UInventoryUIComponent>())
    {
        return Component;
    }
    if (const AController* Controller = Cast<AController>(Owner))
    {
        if (APawn* Pawn = Controller->GetPawn())
        {
            return Pawn->FindComponentByClass<UInventoryUIComponent>();
        }
    }
    return nullptr;
}
