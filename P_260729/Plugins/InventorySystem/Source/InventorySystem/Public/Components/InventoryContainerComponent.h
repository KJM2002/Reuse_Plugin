#pragma once

#include "CoreMinimal.h"
#include "Components/InventoryComponent.h"
#include "InventoryContainerComponent.generated.h"

class UDataTable;

/** Persistent inventory state shared by loot boxes, corpses, lockers, vehicles and storage actors. */
UCLASS(ClassGroup = (Inventory), BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class INVENTORYSYSTEM_API UInventoryContainerComponent : public UInventoryComponent
{
	GENERATED_BODY()

public:
	UInventoryContainerComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category = "Inventory|Container")
	FGuid ContainerID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Container")
	FText ContainerName;

	/** Optional designer-authored loot entries. They are rolled only once for this component instance. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory|Container|Loot")
	TArray<FInventoryInitialItem> InitialLoot;

	/** Optional weighted random loot source using FInventoryLootTableRow. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory|Container|Loot")
	TObjectPtr<UDataTable> LootTable = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory|Container|Loot", meta = (ClampMin = "0"))
	int32 LootTableRolls = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory|Container|Loot")
	bool bGenerateLootOnBeginPlay = true;

	UFUNCTION(BlueprintCallable, Category = "Inventory|Container|Loot")
	void GenerateInitialLoot();

	UFUNCTION(BlueprintCallable, Category = "Inventory|Container")
	void Sort() { SortItemsByQuantityDescending(); }

	UFUNCTION(BlueprintPure, Category = "Inventory|Container")
	int32 GetCapacity() const { return GetMaxInventorySlots(); }

private:
	bool bInitialLootGenerated = false;
};
