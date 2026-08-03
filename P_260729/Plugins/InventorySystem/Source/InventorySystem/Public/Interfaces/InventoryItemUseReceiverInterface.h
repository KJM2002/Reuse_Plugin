#pragma once

#include "CoreMinimal.h"
#include "InventoryTypes.h"
#include "UObject/Interface.h"
#include "InventoryItemUseReceiverInterface.generated.h"

class UInventoryComponent;

/**
 * Optional receiver for context-sensitive inventory items.
 * The inventory remains unaware of doors, quests, equipment, or other consumers.
 */
UINTERFACE(BlueprintType)
class INVENTORYSYSTEM_API UInventoryItemUseReceiverInterface : public UInterface
{
    GENERATED_BODY()
};

class INVENTORYSYSTEM_API IInventoryItemUseReceiverInterface
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Inventory|Use Target")
    bool CanReceiveInventoryItemUse(AActor* User, UInventoryComponent* Inventory, const FInventorySlot& Slot) const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Inventory|Use Target")
    bool ReceiveInventoryItemUse(AActor* User, UInventoryComponent* Inventory, const FInventorySlot& Slot);
};
