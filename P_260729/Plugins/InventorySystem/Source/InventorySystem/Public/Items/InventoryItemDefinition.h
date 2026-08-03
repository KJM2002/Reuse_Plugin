#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "UObject/SoftObjectPtr.h"
#include "InventoryItemDefinition.generated.h"

class AInventoryWorldItemPickup;
class UInventoryItemUseEffect;
class UPrimaryDataAsset;
class UStaticMesh;
class UTexture2D;

UCLASS(BlueprintType)
class INVENTORYSYSTEM_API UInventoryItemDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Identity")
	FName ItemId;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Text")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Text", meta = (MultiLine = true))
	FText Description;

	/** Optional short presentation label such as "중요 아이템" or "소모품". */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Text")
	FText CategoryText;

	/** Optional secondary lore text. Kept separate so the detail hierarchy stays readable. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Text", meta = (MultiLine = true))
	FText FlavorText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Presentation")
	TSoftObjectPtr<UTexture2D> Icon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Presentation")
	TSoftObjectPtr<UStaticMesh> InspectMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Presentation")
	TSoftClassPtr<AInventoryWorldItemPickup> WorldItemClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Presentation", meta = (AllowedClasses = "/Script/Engine.PrimaryDataAsset"))
	TSoftObjectPtr<UPrimaryDataAsset> InspectorData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Rules")
	bool bCanUse = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Rules")
	bool bCanDrop = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Rules")
	bool bCanInspect = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Rules")
	bool bStackable = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Rules", meta = (ClampMin = "1", EditCondition = "bStackable"))
	int32 MaxStackSize = 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Rules", meta = (ClampMin = "0.0"))
	float Weight = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Rules")
	FGameplayTagContainer ItemTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Text")
	FText UseButtonText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Text")
	FText CannotUseReason;

	UPROPERTY(EditDefaultsOnly, Instanced, BlueprintReadOnly, Category = "Use", meta = (EditCondition = "bCanUse"))
	TObjectPtr<UInventoryItemUseEffect> UseEffect = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Use", meta = (EditCondition = "bCanUse"))
	bool bConsumeOnUse = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Use", meta = (ClampMin = "1", EditCondition = "bCanUse && bConsumeOnUse"))
	int32 ConsumeQuantity = 1;

	UFUNCTION(BlueprintPure, Category = "Inventory")
	int32 GetEffectiveMaxStackSize() const;
};
