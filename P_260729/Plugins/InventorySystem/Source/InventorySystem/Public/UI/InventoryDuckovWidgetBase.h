#pragma once

#include "CoreMinimal.h"
#include "UI/InventoryWidgetBase.h"
#include "UI/InventoryUIPresentationTypes.h"
#include "InventoryDuckovWidgetBase.generated.h"

class UCanvasPanel;
class UBackgroundBlur;
class UBorder;
class UButton;
class UHorizontalBox;
class UInventoryContextActionWidgetBase;
class UInventoryComponent;
class UInventoryContainerComponent;
class UInventoryContextMenuWidgetBase;
class UInventoryDuckovSlotWidgetBase;
class UInventoryTooltipWidgetBase;
class UTextBlock;
class UUniformGridPanel;
class UWidget;

UCLASS(BlueprintType, Blueprintable)
class INVENTORYSYSTEM_API UInventoryDuckovWidgetBase : public UInventoryWidgetBase
{
	GENERATED_BODY()

public:
	UInventoryDuckovWidgetBase(const FObjectInitializer& ObjectInitializer);

	void HandleSlotHovered(UInventoryDuckovSlotWidgetBase* SlotWidget, const FVector2D& ScreenPosition);
	void HandleSlotUnhovered(UInventoryDuckovSlotWidgetBase* SlotWidget);
	bool HandleSlotContextRequested(UInventoryDuckovSlotWidgetBase* SlotWidget, const FVector2D& ScreenPosition);
	void HandleSlotDragStarted();
	void HandleSlotDragFinished();
	bool HandleSlotDrop(UInventoryComponent* SourceInventory, int32 SourceSlotIndex, UInventoryComponent* DestinationInventory, int32 DestinationSlotIndex, bool bSplitStack);
	bool TransferSlotToPairedInventory(UInventoryComponent* SourceInventory, int32 SourceSlotIndex, bool bSplitStack = false);

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void SetExternalContainer(UInventoryContainerComponent* InContainer);

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void CloseTransientWidgets();

	virtual void RefreshInventory() override;
	virtual void BeginCloseTransition() override;
	virtual void BeginInspectTransition() override;

protected:
	virtual void PrepareInventoryLayout() override;
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual FReply NativeOnPreviewKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

	UFUNCTION()
	void HandleContextActionRequested(EInventoryContextActionId ActionId, FGuid InstanceId);

	UFUNCTION()
	void HandleSortClicked();

	void BuildSortButtonIfNeeded();
	void BuildPanelBlurIfNeeded();
	void ApplyDuckovPanelStyle();
	void ApplySortButtonStyle();
	void ResetAllSlotHoverStates();
	void UpdateBackpackHeader();
	bool EnsureTooltipWidget();
	bool EnsureContextMenuWidget();
	void HideTooltip();
	void HideContextMenu();
	void PositionPopup(UWidget* Popup, UCanvasPanel* Layer, const FVector2D& ScreenPosition, const FVector2D& Offset);
	bool MakeSlotViewData(UInventoryComponent* SourceInventory, int32 SlotIndex, FInventorySlotViewData& OutData) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|UI")
	TSubclassOf<UInventoryTooltipWidgetBase> TooltipWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|UI")
	TSubclassOf<UInventoryContextMenuWidgetBase> ContextMenuWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|UI")
	TSubclassOf<UInventoryContextActionWidgetBase> ContextActionWidgetClass;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UWidget> Panel_PlayerInventory = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UBorder> Border_PlayerPanel = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UWidget> Panel_ExternalContainer = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UUniformGridPanel> UniformGridPanel_ContainerItems = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UTextBlock> Text_ContainerName = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UTextBlock> Text_PlayerContainerName = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UHorizontalBox> HorizontalBox_Header = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UButton> Button_Sort = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UCanvasPanel> CanvasPanel_TooltipLayer = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|UI")
	TObjectPtr<UCanvasPanel> CanvasPanel_ContextMenuLayer = nullptr;

	UPROPERTY(Transient)
	TObjectPtr<UInventoryTooltipWidgetBase> ActiveTooltipWidget = nullptr;

	UPROPERTY(Transient)
	TObjectPtr<UInventoryContextMenuWidgetBase> ContextMenuWidget = nullptr;

	TWeakObjectPtr<UInventoryDuckovSlotWidgetBase> HoveredTooltipSlot;
	TWeakObjectPtr<UInventoryComponent> ContextMenuSourceInventory;

	UPROPERTY(Transient)
	TObjectPtr<UBackgroundBlur> PlayerPanelBackgroundBlur = nullptr;

	UPROPERTY(Transient)
	TObjectPtr<UBorder> RuntimeExternalContainerBorder = nullptr;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Inventory|UI")
	TObjectPtr<UInventoryContainerComponent> ExternalContainer = nullptr;

	UFUNCTION()
	void HandleExternalContainerChanged();

	void RebuildExternalContainerGrid();
	void EnsureExternalContainerWidgets();
};
