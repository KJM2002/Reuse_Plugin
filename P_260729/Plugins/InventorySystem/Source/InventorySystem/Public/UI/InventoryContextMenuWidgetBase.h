#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/InventoryUIPresentationTypes.h"
#include "InventoryContextMenuWidgetBase.generated.h"

class UInventoryContextActionWidgetBase;
class UBorder;
class UTextBlock;
class UVerticalBox;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
	FInventoryContextMenuActionRequestedSignature,
	EInventoryContextActionId, ActionId,
	FGuid, InstanceId);

UCLASS(BlueprintType, Blueprintable)
class INVENTORYSYSTEM_API UInventoryContextMenuWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "Inventory|UI")
	FInventoryContextMenuActionRequestedSignature OnActionRequested;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|UI")
	TSubclassOf<UInventoryContextActionWidgetBase> ActionWidgetClass;

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	bool SetMenuData(const FInventorySlotViewData& InSlotData, const TArray<FInventoryContextAction>& InActions);

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void ClearMenu();

	UFUNCTION(BlueprintPure, Category = "Inventory|UI")
	FGuid GetTargetInstanceId() const { return TargetInstanceId; }

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeDestruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UBorder> Border_ContextMenu = nullptr;

	UFUNCTION()
	void HandleActionRequested(EInventoryContextActionId ActionId);

	void ClearActionWidgets();

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UVerticalBox> VerticalBox_Actions = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UTextBlock> Text_ContextMenuTitle = nullptr;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UInventoryContextActionWidgetBase>> ActionWidgets;

	FGuid TargetInstanceId;
};
