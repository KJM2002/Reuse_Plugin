#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventorySlotWidgetBase.generated.h"

class UBorder;
class UButton;
class UImage;
class UInventoryItemDefinition;
class UInventoryComponent;
class UInventoryWidgetBase;
class UOverlay;
class UScaleBox;
class USizeBox;
class UTextBlock;
class UTexture2D;

/**
 * 아이템 슬롯의 공통 동작을 담당한다.
 * 파생 Widget Blueprint는 BindWidget 이름에 맞춰 UI를 배치하고 디자인만 한다.
 */
UCLASS(BlueprintType, Blueprintable)
class INVENTORYSYSTEM_API UInventorySlotWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UInventorySlotWidgetBase(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void InitializeSlot(UInventoryWidgetBase* InOwnerInventoryWidget, int32 InSlotIndex, UInventoryItemDefinition* InItemDefinition, int32 InQuantity);

	void InitializeSlotForInventory(UInventoryWidgetBase* InOwnerInventoryWidget, UInventoryComponent* InSourceInventory, int32 InSlotIndex, UInventoryItemDefinition* InItemDefinition, int32 InQuantity, const FGuid& InInstanceId = FGuid());

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	virtual void RefreshSlot();

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	virtual void SetSelected(bool bInSelected);

	UFUNCTION(BlueprintPure, Category = "Inventory|UI")
	int32 GetSlotIndex() const { return SlotIndex; }

	UFUNCTION(BlueprintPure, Category = "Inventory|UI")
	UInventoryItemDefinition* GetItemDefinition() const { return ItemDefinition; }

	UFUNCTION(BlueprintPure, Category = "Inventory|UI")
	int32 GetQuantity() const { return Quantity; }

	UInventoryComponent* GetSourceInventory() const { return SourceInventory; }
	const FGuid& GetDisplayedInstanceId() const { return DisplayedInstanceId; }

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void FocusSlot();

	UFUNCTION(BlueprintNativeEvent, Category = "Inventory|UI")
	bool ShouldShowUnavailable() const;
	virtual bool ShouldShowUnavailable_Implementation() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory|UI")
	void OnSlotRefreshed();

	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory|UI")
	void OnSelectionVisualChanged(bool bIsSelected);

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeOnInitialized() override;
	virtual void NativeDestruct() override;
	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;

	UFUNCTION()
	void HandleSelectClicked();

	void BuildDefaultWidgetTreeIfNeeded();
	void ApplyVisualState();

	/** 반드시 WBP_InventorySlot에 같은 이름의 Button이 있어야 한다. */
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Button_Select = nullptr;

	/** 아이콘의 크기 제한과 그리기 순서를 C++가 보장하기 위해 사용한다. */
	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UOverlay> Overlay_Slot = nullptr;

	/** 각 빈 슬롯과 아이템 슬롯에 공통으로 사용하는 Grid 프레임이다. */
	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UBorder> Border_Background = nullptr;

	/** 비워 두면 해상도 독립적인 Rounded Box를 사용한다. 필요한 경우에만 커스텀 Texture를 지정한다. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|UI")
	TSoftObjectPtr<UTexture2D> SlotBackgroundTexture;

	/** 있으면 C++가 선택 상태와 관계없이 전체 슬롯을 정사각형으로 고정한다. */
	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<USizeBox> SizeBox_Slot = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|UI", meta = (ClampMin = "1.0"))
	float SlotDisplaySize = 96.0f;

	/** 반드시 WBP_InventorySlot에 같은 이름의 Image가 있어야 한다. */
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> Image_ItemIcon = nullptr;

	/** 있으면 C++가 슬롯 아이콘 표시 영역을 정사각형으로 고정한다. */
	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<USizeBox> SizeBox_Icon = nullptr;

	/** 있으면 C++가 원본 비율을 보존하는 Scale To Fit을 강제한다. */
	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UScaleBox> ScaleBox_Icon = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|UI", meta = (ClampMin = "1.0"))
	float IconDisplaySize = 72.0f;

	/** 반드시 WBP_InventorySlot에 같은 이름의 Text Block이 있어야 한다. */
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Text_Quantity = nullptr;

	/** 수량 Text를 슬롯 우측 하단에서 안쪽으로 띄우는 여백이다. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory|UI")
	FMargin QuantityPadding = FMargin(0.0f, 0.0f, 8.0f, 6.0f);

	/** Editable in the slot Widget Blueprint Class Defaults. {0}=stack quantity. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Text")
	FText QuantityTextFormat;

	/** 선택 표시가 필요할 때 같은 이름의 Image를 선택적으로 배치한다. */
	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UImage> Image_Selection = nullptr;

	/** 사용 불가 음영이 필요할 때 같은 이름의 Border를 선택적으로 배치한다. */
	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UBorder> Border_Unavailable = nullptr;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Inventory|UI")
	TObjectPtr<UInventoryWidgetBase> OwnerInventoryWidget = nullptr;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Inventory|UI")
	TObjectPtr<UInventoryComponent> SourceInventory = nullptr;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Inventory|UI")
	TObjectPtr<UInventoryItemDefinition> ItemDefinition = nullptr;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Inventory|UI")
	int32 SlotIndex = INDEX_NONE;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Inventory|UI")
	int32 Quantity = 0;

	/** 화면에 그려진 스택의 식별자. 배열 갱신 뒤 도착한 지연 Hover 이벤트를 검증한다. */
	UPROPERTY(Transient, BlueprintReadOnly, Category = "Inventory|UI")
	FGuid DisplayedInstanceId;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Inventory|UI")
	bool bSelected = false;

	bool bHovered = false;
};
