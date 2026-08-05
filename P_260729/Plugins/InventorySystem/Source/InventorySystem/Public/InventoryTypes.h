#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "InventoryTypes.generated.h"

class UInventoryItemDefinition;

UENUM(BlueprintType)
enum class EInventoryAddResult : uint8
{
	Success,
	PartialSuccess,
	InventoryFull,
	OverWeight,
	InvalidItem,
	InvalidQuantity
};

UENUM(BlueprintType)
enum class EInventoryOperationResult : uint8
{
	Success,
	PartialSuccess,
	InvalidSlot,
	InvalidItem,
	InvalidQuantity,
	InventoryFull,
	OverWeight,
	NotAllowed,
	CannotUse,
	EffectFailed,
	SpawnFailed
};

USTRUCT(BlueprintType)
struct INVENTORYSYSTEM_API FInventoryInitialItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TObjectPtr<UInventoryItemDefinition> ItemDefinition = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", meta = (ClampMin = "1"))
	int32 MinQuantity = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", meta = (ClampMin = "1"))
	int32 MaxQuantity = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float SpawnChance = 1.0f;
};

USTRUCT(BlueprintType)
struct INVENTORYSYSTEM_API FInventoryLootTableRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Loot")
	TObjectPtr<UInventoryItemDefinition> ItemDefinition = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Loot", meta = (ClampMin = "1"))
	int32 MinQuantity = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Loot", meta = (ClampMin = "1"))
	int32 MaxQuantity = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Loot", meta = (ClampMin = "0.0"))
	float Weight = 1.0f;
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
