#include "Items/InventoryItemDefinition.h"

FPrimaryAssetId UInventoryItemDefinition::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(TEXT("InventoryItem"), ItemId.IsNone() ? GetFName() : ItemId);
}

int32 UInventoryItemDefinition::GetEffectiveMaxStackSize() const
{
	return bStackable ? FMath::Max(1, MaxStackSize) : 1;
}
