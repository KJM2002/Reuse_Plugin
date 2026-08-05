#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/InventoryUIPresentationTypes.h"
#include "InventoryTooltipWidgetBase.generated.h"

class UImage;
class UBorder;
class UTextBlock;

UCLASS(BlueprintType, Blueprintable)
class INVENTORYSYSTEM_API UInventoryTooltipWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void SetTooltipData(const FInventorySlotViewData& InData);

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void ClearTooltipData();

	UFUNCTION(BlueprintPure, Category = "Inventory|UI")
	const FInventorySlotViewData& GetTooltipData() const { return TooltipData; }

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
