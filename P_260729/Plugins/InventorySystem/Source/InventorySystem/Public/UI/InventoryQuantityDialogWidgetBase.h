#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryQuantityDialogWidgetBase.generated.h"

class UBorder;
class UButton;
class UTextBlock;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryQuantityConfirmedSignature, int32, Quantity);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInventoryQuantityCancelledSignature);

/** Reusable quantity picker used by stack operations such as Drop. */
UCLASS(BlueprintType, Blueprintable)
class INVENTORYSYSTEM_API UInventoryQuantityDialogWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UInventoryQuantityDialogWidgetBase(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintAssignable, Category = "Inventory|Quantity")
	FInventoryQuantityConfirmedSignature OnConfirmed;

	UPROPERTY(BlueprintAssignable, Category = "Inventory|Quantity")
	FInventoryQuantityCancelledSignature OnCancelled;

	UFUNCTION(BlueprintCallable, Category = "Inventory|Quantity")
	void ShowQuantityPicker(int32 InMaximumQuantity, int32 InInitialQuantity = 1);

	UFUNCTION(BlueprintCallable, Category = "Inventory|Quantity")
	void SetQuantity(int32 InQuantity);

	UFUNCTION(BlueprintPure, Category = "Inventory|Quantity")
	int32 GetQuantity() const { return CurrentQuantity; }

	UFUNCTION(BlueprintPure, Category = "Inventory|Quantity")
	int32 GetMaximumQuantity() const { return MaximumQuantity; }

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeOnInitialized() override;
	virtual void NativeDestruct() override;
	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

	void BuildDefaultWidgetTreeIfNeeded();
	void RefreshQuantityText();

	UFUNCTION()
	void HandleDecreaseClicked();

	UFUNCTION()
	void HandleIncreaseClicked();

	UFUNCTION()
	void HandleAllClicked();

	UFUNCTION()
	void HandleConfirmClicked();

	UFUNCTION()
	void HandleCancelClicked();

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UBorder> Border_Dialog = nullptr;

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UTextBlock> Text_Quantity = nullptr;

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UButton> Button_Decrease = nullptr;

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UButton> Button_Increase = nullptr;

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UButton> Button_All = nullptr;

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UButton> Button_Confirm = nullptr;

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UButton> Button_Cancel = nullptr;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Inventory|Quantity")
	int32 CurrentQuantity = 1;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Inventory|Quantity")
	int32 MaximumQuantity = 1;
};
