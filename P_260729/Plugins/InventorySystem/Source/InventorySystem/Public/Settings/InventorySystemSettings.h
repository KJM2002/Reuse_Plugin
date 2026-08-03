#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "UObject/SoftObjectPtr.h"
#include "InventorySystemSettings.generated.h"

class UInputAction;
class UInputMappingContext;
class UInventoryWidgetBase;
class USoundBase;
class AInventoryWorldItemPickup;

UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Inventory", ToolTip = "Configure the reusable JM inventory system."))
class INVENTORYSYSTEM_API UInventorySystemSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UInventorySystemSettings();

	virtual FName GetCategoryName() const override { return TEXT("JM Plugins"); }

	UPROPERTY(EditAnywhere, Config, Category = "UI")
	TSoftClassPtr<UInventoryWidgetBase> DefaultInventoryWidgetClass;

	/** Replaces only the plugin's legacy WBP_Inventory with the native 0.5 presentation. Custom WBP classes are preserved. */
	UPROPERTY(EditAnywhere, Config, Category = "UI")
	bool bUpgradeLegacyDefaultWidgetToNative = true;

	/** Optional restrained UI feedback sounds. Empty references fail silently. */
	UPROPERTY(EditAnywhere, Config, Category = "UI|Sound")
	TSoftObjectPtr<USoundBase> InventoryOpenSound;

	UPROPERTY(EditAnywhere, Config, Category = "UI|Sound")
	TSoftObjectPtr<USoundBase> InventoryCloseSound;

	UPROPERTY(EditAnywhere, Config, Category = "UI|Sound")
	TSoftObjectPtr<USoundBase> SlotHoverSound;

	UPROPERTY(EditAnywhere, Config, Category = "UI|Sound")
	TSoftObjectPtr<USoundBase> SlotSelectSound;

	UPROPERTY(EditAnywhere, Config, Category = "UI|Sound")
	TSoftObjectPtr<USoundBase> ConfirmSound;

	UPROPERTY(EditAnywhere, Config, Category = "Input")
	TSoftObjectPtr<UInputAction> DefaultToggleInventoryAction;

	UPROPERTY(EditAnywhere, Config, Category = "Input")
	TSoftObjectPtr<UInputMappingContext> DefaultToggleInventoryMappingContext;

	UPROPERTY(EditAnywhere, Config, Category = "Inventory", meta = (ClampMin = "1"))
	int32 DefaultMaxInventorySlots = 20;

	UPROPERTY(EditAnywhere, Config, Category = "Drop", meta = (ClampMin = "0.0", Units = "cm"))
	float DefaultDropForwardDistance = 125.0f;

	UPROPERTY(EditAnywhere, Config, Category = "Drop", meta = (ClampMin = "0.0", Units = "cm"))
	float DefaultDropTraceHeight = 100.0f;

	UPROPERTY(EditAnywhere, Config, Category = "Drop", meta = (ClampMin = "0.0", Units = "cm"))
	float DefaultDropTraceDepth = 300.0f;

	/** Item Definition에 WorldItemClass가 없을 때 사용할 기본 Pickup 클래스다. */
	UPROPERTY(EditAnywhere, Config, Category = "Drop")
	TSoftClassPtr<AInventoryWorldItemPickup> DefaultWorldItemClass;
};
