#pragma once

#include "CoreMinimal.h"
#include "InventoryTypes.h"
#include "UObject/Object.h"
#include "InventoryItemUseEffect.generated.h"

class UInventoryComponent;

UCLASS(Abstract, Blueprintable, EditInlineNew, DefaultToInstanced)
class INVENTORYSYSTEM_API UInventoryItemUseEffect : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Inventory|Use")
	bool CanUse(AActor* User, const FInventorySlot& Slot) const;
	virtual bool CanUse_Implementation(AActor* User, const FInventorySlot& Slot) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Inventory|Use")
	bool ExecuteUse(AActor* User, UInventoryComponent* Inventory, const FInventorySlot& Slot);
	virtual bool ExecuteUse_Implementation(AActor* User, UInventoryComponent* Inventory, const FInventorySlot& Slot);
};
