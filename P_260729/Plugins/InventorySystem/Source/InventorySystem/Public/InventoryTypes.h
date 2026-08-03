#pragma once

#include "CoreMinimal.h"
#include "InventoryTypes.generated.h"

class UInventoryItemDefinition;

UENUM(BlueprintType)
enum class EInventoryAddResult : uint8
{
	Success,
	PartialSuccess,
	InventoryFull,
	InvalidItem,
	InvalidQuantity
};

UENUM(BlueprintType)
enum class EInventoryOperationResult : uint8
{
	Success,
	InvalidSlot,
	InvalidItem,
	InvalidQuantity,
	NotAllowed,
	CannotUse,
	EffectFailed,
	SpawnFailed
};

USTRUCT(BlueprintType)
struct INVENTORYSYSTEM_API FInventorySlot
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TObjectPtr<UInventoryItemDefinition> ItemDefinition = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (ClampMin = "0"))
	int32 Quantity = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	FGuid InstanceId;

	bool IsValid() const { return ItemDefinition != nullptr && Quantity > 0; }
};

USTRUCT(BlueprintType)
struct INVENTORYSYSTEM_API FInventoryAddOutcome
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	EInventoryAddResult Result = EInventoryAddResult::InvalidItem;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	int32 RequestedQuantity = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	int32 AddedQuantity = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	int32 RemainingQuantity = 0;

	bool AddedAnything() const { return AddedQuantity > 0; }
};

USTRUCT(BlueprintType)
struct INVENTORYSYSTEM_API FInventorySaveEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "Inventory")
	FName ItemId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "Inventory")
	int32 Quantity = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "Inventory")
	FGuid InstanceId;
};
