#pragma once

#include "CoreMinimal.h"
#include "UI/InventorySlotWidgetBase.h"
#include "InventoryDuckovSlotWidgetBase.generated.h"

class UBorder;
class UFont;
class UTextBlock;
class UTexture2D;

UCLASS(BlueprintType, Blueprintable)
class INVENTORYSYSTEM_API UInventoryDuckovSlotWidgetBase : public UInventorySlotWidgetBase
{
	GENERATED_BODY()

public:
	virtual void RefreshSlot() override;
	virtual void SetSelected(bool bInSelected) override;
	void ResetHoverState();

	/** Optional designer frame used for normal, hover and selected glow layers. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Appearance")
	TSoftObjectPtr<UTexture2D> SlotFrameTexture;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Appearance")
	TSoftObjectPtr<UFont> RegularFont;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Appearance")
	TSoftObjectPtr<UFont> SemiBoldFont;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Appearance")
	FLinearColor SlotGlowColor = FLinearColor(0.08f, 0.82f, 0.94f, 1.0f);

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnPreviewMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnDragDetected(
		const FGeometry& InGeometry,
		const FPointerEvent& InMouseEvent,
		UDragDropOperation*& OutOperation) override;
	virtual void NativeOnDragEnter(
		const FGeometry& InGeometry,
		const FDragDropEvent& InDragDropEvent,
		UDragDropOperation* InOperation) override;
	virtual void NativeOnDragLeave(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	virtual bool NativeOnDrop(
		const FGeometry& InGeometry,
		const FDragDropEvent& InDragDropEvent,
		UDragDropOperation* InOperation) override;
	virtual void NativeOnDragCancelled(
		const FDragDropEvent& InDragDropEvent,
		UDragDropOperation* InOperation) override;

	void ApplyDuckovVisualState();
	void ApplyDuckovTypography();

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UTextBlock> Text_ItemName = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UBorder> Border_Hover = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UBorder> Border_NameGradient = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UBorder> Border_QuantityBadge = nullptr;

	bool bDragHovered = false;
	bool bPendingQuickTransfer = false;
};
