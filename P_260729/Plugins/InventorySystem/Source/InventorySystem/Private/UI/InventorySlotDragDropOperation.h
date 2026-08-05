#pragma once

#include "CoreMinimal.h"
#include "Blueprint/DragDropOperation.h"
#include "InventorySlotDragDropOperation.generated.h"

class UInventoryWidgetBase;
class UInventoryComponent;

/** Runtime-only payload for moving an inventory stack between visible slots. */
UCLASS()
class UInventorySlotDragDropOperation final : public UDragDropOperation
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UInventoryWidgetBase> SourceInventoryWidget = nullptr;

	UPROPERTY(Transient)
	TObjectPtr<UInventoryComponent> SourceInventory = nullptr;

	UPROPERTY(Transient)
	int32 SourceSlotIndex = INDEX_NONE;
};
