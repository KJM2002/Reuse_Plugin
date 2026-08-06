#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/InventoryUIPresentationTypes.h"
#include "InventoryTooltipWidgetBase.generated.h"

class UImage;
class UBorder;
class UFont;
class UTextBlock;

UCLASS(BlueprintType, Blueprintable)
class INVENTORYSYSTEM_API UInventoryTooltipWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UInventoryTooltipWidgetBase(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void SetTooltipData(const FInventorySlotViewData& InData);

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void ClearTooltipData();

	UFUNCTION(BlueprintPure, Category = "Inventory|UI")
	const FInventorySlotViewData& GetTooltipData() const { return TooltipData; }

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Appearance")
	TSoftObjectPtr<UFont> RegularFont;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Appearance")
	TSoftObjectPtr<UFont> SemiBoldFont;

	/** Editable in the tooltip Widget Blueprint Class Defaults. {0}=stack quantity. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Text")
	FText QuantityTextFormat;

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeDestruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UBorder> Border_Tooltip = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UImage> Image_TooltipIcon = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UTextBlock> Text_TooltipName = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UTextBlock> Text_TooltipQuantity = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UTextBlock> Text_TooltipDescription = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UTextBlock> Text_TooltipCategory = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UTextBlock> Text_TooltipFlavor = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UTextBlock> Text_TooltipDisabledReason = nullptr;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Inventory|UI")
	FInventorySlotViewData TooltipData;
};
