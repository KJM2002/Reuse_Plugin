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
class UInventoryQuantityDialogWidgetBase;
class UInventoryTooltipWidgetBase;
class UFont;
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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Appearance")
	TSoftObjectPtr<UFont> RegularFont;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Appearance")
	TSoftObjectPtr<UFont> SemiBoldFont;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Appearance", meta = (ClampMin = "32.0"))
	float CompactGridSlotSize = 60.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Appearance", meta = (ClampMin = "0.0"))
	float CompactGridPadding = 2.0f;

	/** Sizes the two SizeBox panels from their slot row count. Disable to use Designer sizes unchanged. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Appearance")
	bool bAutoSizePanelsToContent = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Appearance", meta = (ClampMin = "200.0"))
	float CompactPanelWidth = 340.0f;

	/** Derives width from five fixed cells plus the panel's horizontal content padding. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Appearance")
	bool bFitPanelWidthToGrid = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Appearance", meta = (ClampMin = "0.0"))
	float CompactPanelHorizontalPadding = 10.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Appearance", meta = (ClampMin = "100.0"))
	float CompactPanelMinHeight = 170.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Appearance", meta = (ClampMin = "100.0"))
	float CompactPanelMaxHeight = 520.0f;

	/** Fixed header/padding area above the slot rows. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Appearance", meta = (ClampMin = "0.0"))
	float CompactPanelChromeHeight = 72.0f;

	/** Small containers remain at least this many rows tall. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Appearance", meta = (ClampMin = "1", ClampMax = "20"))
	int32 CompactPanelMinVisibleRows = 1;

	/** Larger containers stop growing here and use their ScrollBox. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Appearance", meta = (ClampMin = "1", ClampMax = "20"))
	int32 CompactPanelMaxVisibleRows = 6;

	/** Player keeps its Designer height so future capacity upgrades can fill the lower area. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Appearance")
	bool bAutoSizePlayerPanelHeight = false;

	/** Loot removes unused lower space and grows only by its MaxSlot row count. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Appearance")
	bool bAutoSizeContainerPanelHeight = true;

	/** Optional symmetrical layout. Disabled keeps Duckov-style content-sized panels. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|Appearance")
	bool bMatchPlayerAndContainerPanelHeight = false;

	/** Editable in WBP Class Defaults. {0}=container display name. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Text")
	FText ContainerHeaderTextFormat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Text")
	FText DefaultLootContainerText;

	/** Used only when C++ must create a missing Sort button at runtime. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Text")
	FText SortButtonText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Appearance|Player Header", meta = (ClampMin = "1", ClampMax = "96"))
	int32 PlayerHeaderFontSize = 18;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Appearance|Player Header")
	FVector2D PlayerHeaderPositionOffset = FVector2D::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Appearance|Player Header")
	FMargin PlayerHeaderPadding = FMargin(0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Appearance|Loot Header", meta = (ClampMin = "1", ClampMax = "96"))
	int32 LootHeaderFontSize = 18;

	/** Local X/Y adjustment applied after the panel's anchor and Canvas position. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Appearance|Loot Header")
	FVector2D LootHeaderPositionOffset = FVector2D::ZeroVector;

	/** Layout space around the Loot title inside its VerticalBox. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Appearance|Loot Header")
	FMargin LootHeaderPadding = FMargin(0.0f, 0.0f, 0.0f, 10.0f);

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

	UFUNCTION()
	void HandleDropQuantityConfirmed(int32 Quantity);

	UFUNCTION()
	void HandleDropQuantityCancelled();

	void BuildSortButtonIfNeeded();
	void BuildPanelBlurIfNeeded();
	void ApplyDuckovPanelStyle();
	void ApplySortButtonStyle();
	void ApplyDuckovTypography();
	void ApplyHeaderLayout();
	void ApplyReferencePanelSizing();
	void ResetAllSlotHoverStates();
	void UpdateBackpackHeader();
	void UpdateContainerHeader();
	bool EnsureTooltipWidget();
	bool EnsureContextMenuWidget();
	bool OpenDropQuantityDialog(UInventoryComponent* SourceInventory, int32 SlotIndex);
	void CloseDropQuantityDialog();
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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|UI")
	TSubclassOf<UInventoryQuantityDialogWidgetBase> QuantityDialogWidgetClass;

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

	UPROPERTY(Transient)
	TObjectPtr<UInventoryQuantityDialogWidgetBase> ActiveQuantityDialog = nullptr;

	TWeakObjectPtr<UInventoryDuckovSlotWidgetBase> HoveredTooltipSlot;
	TWeakObjectPtr<UInventoryComponent> ContextMenuSourceInventory;
	TWeakObjectPtr<UInventoryComponent> PendingDropInventory;
	FGuid PendingDropInstanceId;

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
