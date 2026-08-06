#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryTypes.h"
#include "InventoryWidgetBase.generated.h"

class UButton;
class UBorder;
class UHorizontalBox;
class UImage;
class UInventoryComponent;
class UInventorySlotWidgetBase;
class UInventoryUIComponent;
class UOverlay;
class USizeBox;
class UTextBlock;
class UUniformGridPanel;
class UVerticalBox;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInventoryWidgetCloseRequestedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInventoryWidgetTransitionFinishedSignature);

/**
 * 전체 인벤토리 UI의 공통 동작을 담당한다.
 * 파생 Widget Blueprint는 BindWidget 이름에 맞춰 UI를 배치하고 디자인만 한다.
 */
UCLASS(BlueprintType, Blueprintable)
class INVENTORYSYSTEM_API UInventoryWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UInventoryWidgetBase(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintAssignable, Category = "Inventory|UI")
	FInventoryWidgetCloseRequestedSignature OnCloseRequested;

	UPROPERTY(BlueprintAssignable, Category = "Inventory|UI")
	FInventoryWidgetTransitionFinishedSignature OnCloseTransitionFinished;

	UPROPERTY(BlueprintAssignable, Category = "Inventory|UI")
	FInventoryWidgetTransitionFinishedSignature OnInspectTransitionFinished;

	/** WBP_InventorySlot처럼 UInventorySlotWidgetBase에서 파생된 Widget Blueprint를 지정한다. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|UI")
	TSubclassOf<UInventorySlotWidgetBase> SlotWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|UI", meta = (ClampMin = "1"))
	int32 GridColumnCount = 5;

	/** true이면 인벤토리 최대 용량만큼 빈 슬롯까지 표시해 고정 Grid를 만든다. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|UI")
	bool bShowEmptySlots = true;

	/** The following labels/formats are editable from Widget Blueprint Class Defaults. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Text")
	FText InventoryTitleText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Text")
	FText CapacityTextFormat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Text")
	FText SelectedQuantityTextFormat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Text")
	FText EmptyInventoryHintText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Text")
	FText SelectItemHintText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Text")
	FText UseButtonText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Text")
	FText DropButtonText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Text")
	FText InspectButtonText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Text")
	FText CloseButtonText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Text")
	FText InputHintText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Text")
	FText CloseHintText;

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void InitializeInventory(UInventoryComponent* InInventory, UInventoryUIComponent* InCoordinator);

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	bool SelectSlot(int32 SlotIndex);

	UFUNCTION(BlueprintPure, Category = "Inventory|UI")
	bool GetSelectedSlot(FInventorySlot& OutSlot) const;

	UFUNCTION(BlueprintPure, Category = "Inventory|UI")
	int32 GetSelectedSlotIndex() const { return SelectedSlotIndex; }

	UFUNCTION(BlueprintPure, Category = "Inventory|UI")
	UInventoryComponent* GetInventoryComponent() const { return InventoryComponent; }

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	EInventoryOperationResult UseSelectedItem();

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	EInventoryOperationResult DropSelectedItem(int32 Quantity = 1);

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	bool InspectSelectedItem();

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void RequestClose();

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	virtual void RefreshInventory();

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void BeginOpenTransition();

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	virtual void BeginCloseTransition();

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	virtual void BeginInspectTransition();

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void BeginInspectorReturnTransition();

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void FocusSelectedSlot();

	UFUNCTION(BlueprintPure, Category = "Inventory|UI")
	bool IsClosing() const { return bClosing; }

	void NotifySlotHovered();
	void NotifySlotSelected();

	void RegisterSlotWidget(UInventorySlotWidgetBase* SlotWidget);
	void UnregisterSlotWidget(UInventorySlotWidgetBase* SlotWidget);

	/** C++ 기본 갱신 이후 게임별 연출이 더 필요할 때만 구현한다. */
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory|UI")
	void OnInventoryRefreshed(const TArray<FInventorySlot>& CurrentSlots);

	/** C++ 기본 상세 정보 갱신 이후 게임별 연출이 더 필요할 때만 구현한다. */
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory|UI")
	void OnSelectionChanged(int32 NewSlotIndex, const FInventorySlot& SelectedSlot);

	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory|UI")
	void OnInventoryOperationFailed(EInventoryOperationResult Result);

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeOnInitialized() override;
	virtual void NativeDestruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual FReply NativeOnPreviewKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

	UFUNCTION()
	void HandleInventoryChanged();

	UFUNCTION()
	void HandleUseClicked();

	UFUNCTION()
	void HandleDropClicked();

	UFUNCTION()
	void HandleInspectClicked();

	UFUNCTION()
	void HandleCloseClicked();

	void RebuildSlotGrid();
	/** Applies subclass-specific grid invariants before the first build and every refresh. */
	virtual void PrepareInventoryLayout();
	void RefreshSelectedItemDetails();
	void ClearSelectedItemDetails();
	void UpdateRegisteredSlotSelection();
	void BuildDefaultWidgetTreeIfNeeded();
	void UpdateCapacityText();
	void ApplyTransitionVisual(float Alpha);
	void PlayConfiguredSound(const TSoftObjectPtr<class USoundBase>& Sound) const;

	/** 반드시 WBP_Inventory에 같은 이름의 Uniform Grid Panel이 있어야 한다. */
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UUniformGridPanel> UniformGridPanel_Items = nullptr;

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UTextBlock> Text_Capacity = nullptr;

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UImage> Image_SelectedIcon = nullptr;

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UTextBlock> Text_SelectedName = nullptr;

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UTextBlock> Text_SelectedQuantity = nullptr;

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UTextBlock> Text_SelectedDescription = nullptr;

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UTextBlock> Text_SelectedCategory = nullptr;

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UTextBlock> Text_SelectedFlavor = nullptr;

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UTextBlock> Text_EmptyHint = nullptr;

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UHorizontalBox> HorizontalBox_Actions = nullptr;

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UOverlay> Overlay_Root = nullptr;

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UBorder> Border_BackgroundDim = nullptr;

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UBorder> Border_InventoryWindow = nullptr;

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UTextBlock> Text_DisabledReason = nullptr;

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UButton> Button_Use = nullptr;

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UButton> Button_Drop = nullptr;

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UButton> Button_Inspect = nullptr;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Button_Close = nullptr;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Inventory|UI")
	TObjectPtr<UInventoryComponent> InventoryComponent = nullptr;

	UPROPERTY(Transient)
	TObjectPtr<UInventoryUIComponent> Coordinator = nullptr;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Inventory|UI")
	int32 SelectedSlotIndex = INDEX_NONE;

	FGuid SelectedItemInstanceId;

	TArray<TWeakObjectPtr<UInventorySlotWidgetBase>> RegisteredSlotWidgets;

	float TransitionElapsed = 0.0f;
	float TransitionStartAlpha = 0.0f;
	float TransitionTargetAlpha = 1.0f;
	bool bTransitionActive = false;
	bool bClosing = false;
	bool bInspectTransition = false;
	bool bPreserveBackdropDuringTransition = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|UI|Animation", meta = (ClampMin = "0.01", Units = "s"))
	float OpenTransitionDuration = 0.22f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|UI|Animation", meta = (ClampMin = "0.01", Units = "s"))
	float CloseTransitionDuration = 0.15f;
};
