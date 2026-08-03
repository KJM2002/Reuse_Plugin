#include "Interfaces/InventoryItemInspectorBridge.h"

bool UInventoryItemInspectorBridge::OpenInspector_Implementation(APlayerController* PlayerController, const UInventoryItemDefinition* ItemDefinition)
{
	return false;
}

void UInventoryItemInspectorBridge::CloseInspector_Implementation()
{
}

bool UInventoryItemInspectorBridge::IsInspectorOpen_Implementation() const
{
	return false;
}

void UInventoryItemInspectorBridge::NotifyInspectorClosed()
{
	OnInspectorClosed.Broadcast();
}
