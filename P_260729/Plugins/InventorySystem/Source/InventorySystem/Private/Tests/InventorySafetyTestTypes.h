#pragma once

#include "CoreMinimal.h"
#include "Components/InventoryComponent.h"
#include "Items/InventoryItemUseEffect.h"
#include "InventorySafetyTestTypes.generated.h"

UCLASS()
class UInventoryAlwaysSucceedsUseEffect : public UInventoryItemUseEffect
{
	GENERATED_BODY()

public:
	virtual bool CanUse_Implementation(AActor* User, const FInventorySlot& Slot) const override { return true; }
	virtual bool ExecuteUse_Implementation(AActor* User, UInventoryComponent* Inventory, const FInventorySlot& Slot) override { return true; }
};

UCLASS()
class UInventoryUseReentrancyReceiver : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UInventoryComponent> Inventory;

	int32 Action = 0;
	int32 AddedCallbackCount = 0;
	int32 MinimumObservedTotal = MAX_int32;

	UFUNCTION()
	void HandleItemAdded(UInventoryItemDefinition* ItemDefinition, int32 AddedQuantity, int32 SlotIndex)
	{
		++AddedCallbackCount;
		if (Inventory)
		{
			MinimumObservedTotal = FMath::Min(MinimumObservedTotal, Inventory->GetItemQuantity(ItemDefinition));
			Inventory->SortItemsByQuantityDescending();
		}
	}

	UFUNCTION()
	void HandleItemUsed(UInventoryItemDefinition* ItemDefinition, int32 OriginalSlotIndex)
	{
		if (!Inventory)
		{
			return;
		}
		if (Action == 1)
		{
			Inventory->SortItemsByQuantityDescending();
		}
		else if (Action == 2)
		{
			Inventory->MoveItemToEmptySlot(OriginalSlotIndex, 3);
		}
		else if (Action == 3)
		{
			Inventory->RemoveItemAtSlot(OriginalSlotIndex, 2);
		}
		else if (Action == 4)
		{
			Inventory->RemoveItemAtSlot(OriginalSlotIndex, 2);
			Inventory->MoveItemToEmptySlot(1, OriginalSlotIndex);
		}
	}
};
