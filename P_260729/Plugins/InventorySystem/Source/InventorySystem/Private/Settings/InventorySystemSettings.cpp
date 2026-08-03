#include "Settings/InventorySystemSettings.h"

#include "InputAction.h"
#include "UI/InventoryWidgetBase.h"
#include "World/InventoryWorldItemPickup.h"

UInventorySystemSettings::UInventorySystemSettings()
{
	CategoryName = TEXT("JM Plugins");
	SectionName = TEXT("Inventory");
	// The native widget is a complete, portable fallback. Projects can still point
	// this setting at WBP_Inventory (or any derived presentation) without changing
	// inventory data or behavior.
	DefaultInventoryWidgetClass = UInventoryWidgetBase::StaticClass();
	DefaultToggleInventoryAction = TSoftObjectPtr<UInputAction>(FSoftObjectPath(TEXT("/InventorySystem/Input/IA_Inventory.IA_Inventory")));
	DefaultWorldItemClass = TSoftClassPtr<AInventoryWorldItemPickup>(FSoftObjectPath(TEXT("/Script/InventorySystem.ReuseInspectableInventoryPickup")));
}
