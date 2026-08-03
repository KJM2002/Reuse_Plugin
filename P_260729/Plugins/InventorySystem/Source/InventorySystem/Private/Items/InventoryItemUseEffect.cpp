#include "Items/InventoryItemUseEffect.h"

bool UInventoryItemUseEffect::CanUse_Implementation(AActor* User, const FInventorySlot& Slot) const
{
	return IsValid(User) && Slot.IsValid();
}

bool UInventoryItemUseEffect::ExecuteUse_Implementation(AActor* User, UInventoryComponent* Inventory, const FInventorySlot& Slot)
{
	return false;
}
