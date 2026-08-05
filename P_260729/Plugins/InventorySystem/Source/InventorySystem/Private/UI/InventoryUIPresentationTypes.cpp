#include "UI/InventoryUIPresentationTypes.h"

#include "Items/InventoryItemDefinition.h"

bool FInventorySlotViewData::IsValid() const
{
	return ::IsValid(ItemDefinition) && Quantity > 0 && InstanceId.IsValid();
}

FInventorySlotViewData FInventoryUIPresentationUtils::MakeSlotViewData(const FInventorySlot& Slot, int32 SlotIndex)
{
	FInventorySlotViewData Result;
	Result.SlotIndex = SlotIndex;
	Result.InstanceId = Slot.InstanceId;
	Result.ItemDefinition = Slot.ItemDefinition;
	Result.Quantity = FMath::Max(0, Slot.Quantity);

	if (IsValid(Slot.ItemDefinition))
	{
		Result.DisplayName = Slot.ItemDefinition->DisplayName.IsEmpty()
			? FText::FromName(Slot.ItemDefinition->ItemId)
			: Slot.ItemDefinition->DisplayName;
		Result.Description = Slot.ItemDefinition->Description;
		Result.CategoryText = Slot.ItemDefinition->CategoryText;
		Result.FlavorText = Slot.ItemDefinition->FlavorText;
		Result.CannotUseReason = Slot.ItemDefinition->bCanUse
			? FText::GetEmpty()
			: Slot.ItemDefinition->CannotUseReason;
	}

	return Result;
}

TArray<FInventoryContextAction> FInventoryUIPresentationUtils::BuildContextActions(const FInventorySlotViewData& Data)
{
	TArray<FInventoryContextAction> Actions;
	if (!Data.IsValid())
	{
		return Actions;
	}

	const UInventoryItemDefinition* ItemDefinition = Data.ItemDefinition;
	if (ItemDefinition->bCanUse)
	{
		FInventoryContextAction& Action = Actions.AddDefaulted_GetRef();
		Action.ActionId = EInventoryContextActionId::Use;
		Action.DisplayText = ItemDefinition->UseButtonText.IsEmpty()
			? NSLOCTEXT("InventorySystem", "ContextUse", "사용")
			: ItemDefinition->UseButtonText;
	}

	if (ItemDefinition->bCanDrop)
	{
		FInventoryContextAction& Action = Actions.AddDefaulted_GetRef();
		Action.ActionId = EInventoryContextActionId::Drop;
		Action.DisplayText = NSLOCTEXT("InventorySystem", "ContextDropOne", "하나 버리기");
	}

	if (CanPresentInspectAction(ItemDefinition))
	{
		FInventoryContextAction& Action = Actions.AddDefaulted_GetRef();
		Action.ActionId = EInventoryContextActionId::Inspect;
		Action.DisplayText = NSLOCTEXT("InventorySystem", "ContextInspect", "조사");
	}

	return Actions;
}

int32 FInventoryUIPresentationUtils::FindSlotIndexByInstanceId(const TArray<FInventorySlot>& Slots, const FGuid& InstanceId)
{
	if (!InstanceId.IsValid())
	{
		return INDEX_NONE;
	}

	for (int32 Index = 0; Index < Slots.Num(); ++Index)
	{
		if (Slots[Index].IsValid() && Slots[Index].InstanceId == InstanceId)
		{
			return Index;
		}
	}
	return INDEX_NONE;
}

FText FInventoryUIPresentationUtils::FormatCapacityText(int32 OccupiedSlots, int32 MaximumSlots)
{
	return FText::Format(
		NSLOCTEXT("InventorySystem", "DuckovCapacityFormat", "{0} / {1}"),
		FText::AsNumber(FMath::Max(0, OccupiedSlots)),
		FText::AsNumber(FMath::Max(0, MaximumSlots)));
}

FText FInventoryUIPresentationUtils::FormatQuantityText(int32 Quantity)
{
	return ShouldShowQuantity(Quantity)
		? FText::Format(NSLOCTEXT("InventorySystem", "DuckovQuantityFormat", "x{0}"), FText::AsNumber(Quantity))
		: FText::GetEmpty();
}

bool FInventoryUIPresentationUtils::ShouldShowQuantity(int32 Quantity)
{
	return Quantity > 1;
}

bool FInventoryUIPresentationUtils::CanPresentInspectAction(const UInventoryItemDefinition* ItemDefinition)
{
	return IsValid(ItemDefinition)
		&& ItemDefinition->bCanInspect
		&& !ItemDefinition->InspectMesh.IsNull()
		&& !ItemDefinition->InspectorData.IsNull();
}

FVector2D FInventoryUIPresentationUtils::ClampPopupPosition(
	const FVector2D& DesiredPosition,
	const FVector2D& PopupSize,
	const FVector2D& AvailableSize,
	float EdgePadding)
{
	const float SafePadding = FMath::Max(0.0f, EdgePadding);
	const FVector2D SafePopupSize(FMath::Max(0.0f, PopupSize.X), FMath::Max(0.0f, PopupSize.Y));
	const FVector2D SafeAvailableSize(FMath::Max(0.0f, AvailableSize.X), FMath::Max(0.0f, AvailableSize.Y));
	const float MaximumX = FMath::Max(SafePadding, SafeAvailableSize.X - SafePopupSize.X - SafePadding);
	const float MaximumY = FMath::Max(SafePadding, SafeAvailableSize.Y - SafePopupSize.Y - SafePadding);
	return FVector2D(
		FMath::Clamp(DesiredPosition.X, SafePadding, MaximumX),
		FMath::Clamp(DesiredPosition.Y, SafePadding, MaximumY));
}
