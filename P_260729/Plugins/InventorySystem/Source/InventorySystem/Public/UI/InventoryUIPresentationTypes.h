#pragma once

#include "CoreMinimal.h"
#include "InventoryTypes.h"
#include "InventoryUIPresentationTypes.generated.h"

class UInventoryItemDefinition;

UENUM(BlueprintType)
enum class EInventoryContextActionId : uint8
{
	Use,
	Drop,
	Inspect
};

USTRUCT(BlueprintType)
struct INVENTORYSYSTEM_API FInventorySlotViewData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Inventory|UI")
	int32 SlotIndex = INDEX_NONE;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory|UI")
	FGuid InstanceId;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory|UI")
	TObjectPtr<UInventoryItemDefinition> ItemDefinition = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory|UI")
	int32 Quantity = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory|UI")
	FText DisplayName;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory|UI")
	FText Description;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory|UI")
	FText CategoryText;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory|UI")
	FText FlavorText;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory|UI")
	FText CannotUseReason;

	bool IsValid() const;
};

USTRUCT(BlueprintType)
struct INVENTORYSYSTEM_API FInventoryContextAction
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Inventory|UI")
	EInventoryContextActionId ActionId = EInventoryContextActionId::Use;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory|UI")
	FText DisplayText;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory|UI")
	bool bEnabled = true;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory|UI")
	FText DisabledReason;
};

struct INVENTORYSYSTEM_API FInventoryUIPresentationUtils
{
	static FInventorySlotViewData MakeSlotViewData(const FInventorySlot& Slot, int32 SlotIndex);
	static TArray<FInventoryContextAction> BuildContextActions(const FInventorySlotViewData& Data);
	static int32 FindSlotIndexByInstanceId(const TArray<FInventorySlot>& Slots, const FGuid& InstanceId);
	static int32 ResolveSlotIndexForPresentation(const TArray<FInventorySlot>& Slots, int32 PreferredSlotIndex, const FGuid& ExpectedInstanceId);
	static FText FormatCapacityText(int32 OccupiedSlots, int32 MaximumSlots);
	static FText FormatQuantityText(int32 Quantity);
	static bool ShouldShowQuantity(int32 Quantity);
	static bool CanPresentInspectAction(const UInventoryItemDefinition* ItemDefinition);
	static FVector2D ClampPopupPosition(
		const FVector2D& DesiredPosition,
		const FVector2D& PopupSize,
		const FVector2D& AvailableSize,
		float EdgePadding = 8.0f);
	static FVector2D CalculateGridPanelSize(
		int32 SlotCount,
		int32 ColumnCount,
		float SlotSize,
		float SlotPadding,
		float PanelWidth,
		float ChromeHeight,
		int32 MinimumVisibleRows,
		int32 MaximumVisibleRows,
		float MinimumPanelHeight,
		float MaximumPanelHeight);
};
