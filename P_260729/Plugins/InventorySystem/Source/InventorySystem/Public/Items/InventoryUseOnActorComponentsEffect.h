#pragma once

#include "CoreMinimal.h"
#include "Items/InventoryItemUseEffect.h"
#include "InventoryUseOnActorComponentsEffect.generated.h"

/** Routes an item's Use button to a compatible receiver component on the user. */
UCLASS(BlueprintType, EditInlineNew)
class INVENTORYSYSTEM_API UInventoryUseOnActorComponentsEffect : public UInventoryItemUseEffect
{
    GENERATED_BODY()

public:
    virtual bool CanUse_Implementation(AActor* User, const FInventorySlot& Slot) const override;
    virtual bool ExecuteUse_Implementation(AActor* User, UInventoryComponent* Inventory, const FInventorySlot& Slot) override;
};
