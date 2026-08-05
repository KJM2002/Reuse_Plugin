#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryTypes.h"
#include "InventoryComponent.generated.h"

class UInventoryItemDefinition;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInventoryChangedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FInventoryItemChangedSignature, UInventoryItemDefinition*, ItemDefinition, int32, Quantity, int32, SlotIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInventoryItemsReceivedSignature, UInventoryItemDefinition*, ItemDefinition, int32, Quantity);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInventoryItemUsedSignature, UInventoryItemDefinition*, ItemDefinition, int32, SlotIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInventoryFullSignature, UInventoryItemDefinition*, ItemDefinition, int32, RejectedQuantity);

UCLASS(ClassGroup = (Inventory), BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class INVENTORYSYSTEM_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryComponent();

	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Inventory|Events")
	FInventoryChangedSignature OnInventoryChanged;

	UPROPERTY(BlueprintAssignable, Category = "Inventory|Events")
	FInventoryItemChangedSignature OnItemAdded;

	/** 한 번의 Add 작업으로 실제 획득한 총수량을 한 번만 전달한다. */
	UPROPERTY(BlueprintAssignable, Category = "Inventory|Events")
	FInventoryItemsReceivedSignature OnItemsReceived;

	UPROPERTY(BlueprintAssignable, Category = "Inventory|Events")
	FInventoryItemChangedSignature OnItemRemoved;

	UPROPERTY(BlueprintAssignable, Category = "Inventory|Events")
	FInventoryItemUsedSignature OnItemUsed;

	UPROPERTY(BlueprintAssignable, Category = "Inventory|Events")
	FInventoryItemChangedSignature OnItemDropped;

	UPROPERTY(BlueprintAssignable, Category = "Inventory|Events")
	FInventoryFullSignature OnInventoryFull;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (ClampMin = "1"))
	int32 MaxInventorySlots = 20;

	/** Zero means unlimited. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (ClampMin = "0.0", Units = "kg"))
	float MaxInventoryWeight = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FInventoryAddOutcome AddItemDetailed(UInventoryItemDefinition* ItemDefinition, int32 Quantity = 1);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddItem(UInventoryItemDefinition* ItemDefinition, int32 Quantity = 1);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool RemoveItem(UInventoryItemDefinition* ItemDefinition, int32 Quantity = 1);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	EInventoryOperationResult RemoveItemAtSlot(int32 SlotIndex, int32 Quantity = 1);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	EInventoryOperationResult UseItemAtSlot(int32 SlotIndex, AActor* User = nullptr);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	EInventoryOperationResult DropItemAtSlot(int32 SlotIndex, int32 Quantity = 1, AActor* Dropper = nullptr);

	/** Moves one complete stack into an empty slot without changing item data. */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Layout")
	EInventoryOperationResult MoveItemToEmptySlot(int32 SourceSlotIndex, int32 DestinationSlotIndex);

	/** Atomically transfers quantity to another inventory. DestinationSlotIndex may be INDEX_NONE for auto placement. */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Transfer")
	EInventoryOperationResult MoveItem(UInventoryComponent* Destination, int32 SourceSlotIndex, int32 DestinationSlotIndex = -1, int32 Quantity = -1);

	UFUNCTION(BlueprintCallable, Category = "Inventory|Transfer")
	EInventoryOperationResult MoveStack(UInventoryComponent* Destination, int32 SourceSlotIndex, int32 DestinationSlotIndex = -1);

	UFUNCTION(BlueprintCallable, Category = "Inventory|Transfer")
	EInventoryOperationResult SplitStack(UInventoryComponent* Destination, int32 SourceSlotIndex, int32 Quantity, int32 DestinationSlotIndex = -1);

	UFUNCTION(BlueprintCallable, Category = "Inventory|Transfer")
	EInventoryOperationResult SwapItem(UInventoryComponent* OtherInventory, int32 ThisSlotIndex, int32 OtherSlotIndex);

	UFUNCTION(BlueprintPure, Category = "Inventory|Transfer")
	bool CanMove(UInventoryComponent* Destination, int32 SourceSlotIndex, int32 Quantity = -1, int32 DestinationSlotIndex = -1) const;

	/** Places occupied slots first, ordered by stack quantity from high to low. */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Layout")
	void SortItemsByQuantityDescending();

	UFUNCTION(BlueprintPure, Category = "Inventory")
	bool HasItem(UInventoryItemDefinition* ItemDefinition, int32 Quantity = 1) const;

	UFUNCTION(BlueprintPure, Category = "Inventory")
	int32 GetItemQuantity(UInventoryItemDefinition* ItemDefinition) const;

	UFUNCTION(BlueprintPure, Category = "Inventory")
	TArray<FInventorySlot> GetInventorySlots() const { return Slots; }

	UFUNCTION(BlueprintPure, Category = "Inventory")
	bool GetSlot(int32 SlotIndex, FInventorySlot& OutSlot) const;

	UFUNCTION(BlueprintPure, Category = "Inventory")
	int32 GetOccupiedSlotCount() const;

	UFUNCTION(BlueprintPure, Category = "Inventory")
	int32 GetMaxInventorySlots() const { return MaxInventorySlots; }

	UFUNCTION(BlueprintPure, Category = "Inventory")
	float GetCurrentWeight() const;

	UFUNCTION(BlueprintPure, Category = "Inventory")
	bool CanAccept(UInventoryItemDefinition* ItemDefinition, int32 Quantity = 1) const;

	UFUNCTION(BlueprintCallable, Category = "Inventory|Save")
	TArray<FInventorySaveEntry> MakeSaveEntries() const;

	const TArray<FInventorySlot>& GetSlotsNative() const { return Slots; }

protected:
	void EnsureSlotCapacity();
	bool IsValidSlotIndex(int32 SlotIndex) const;
	int32 GetAcceptableQuantity(UInventoryItemDefinition* ItemDefinition, int32 Quantity) const;
	void NotifyTransferMutation(UInventoryItemDefinition* ItemDefinition, int32 Quantity, int32 SlotIndex, bool bAdded);
	FVector FindDropLocation(AActor* Dropper) const;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	TArray<FInventorySlot> Slots;
};
