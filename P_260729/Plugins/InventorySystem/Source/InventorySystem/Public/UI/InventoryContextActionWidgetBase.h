#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/InventoryUIPresentationTypes.h"
#include "InventoryContextActionWidgetBase.generated.h"

class UButton;
class UTextBlock;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryContextActionRequestedSignature, EInventoryContextActionId, ActionId);

UCLASS(BlueprintType, Blueprintable)
class INVENTORYSYSTEM_API UInventoryContextActionWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "Inventory|UI")
	FInventoryContextActionRequestedSignature OnActionRequested;

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void SetActionData(const FInventoryContextAction& InAction);

	UFUNCTION(BlueprintPure, Category = "Inventory|UI")
	const FInventoryContextAction& GetActionData() const { return ActionData; }

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	UFUNCTION()
	void HandleActionClicked();

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UButton> Button_Action = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UTextBlock> Text_ActionLabel = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UTextBlock> Text_DisabledReason = nullptr;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Inventory|UI")
	FInventoryContextAction ActionData;
};
