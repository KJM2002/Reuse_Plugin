#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/SoftObjectPtr.h"
#include "InventoryUIComponent.generated.h"

class UEnhancedInputComponent;
class UInputAction;
class UInputMappingContext;
class UInventoryComponent;
class UInventoryContainerComponent;
class UInventoryItemDefinition;
class UInventoryItemInspectorBridge;
class UInventoryPickupNotificationWidget;
class UInventoryWidgetBase;
struct FKey;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInventoryUIStateSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryUIPresentationSignature, bool, bInventoryVisible);

UCLASS(ClassGroup = (Inventory), BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class INVENTORYSYSTEM_API UInventoryUIComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryUIComponent();

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(BlueprintAssignable, Category = "Inventory|UI")
	FInventoryUIStateSignature OnInventoryOpened;

	UPROPERTY(BlueprintAssignable, Category = "Inventory|UI")
	FInventoryUIStateSignature OnInventoryClosed;

	/** Generic modal-HUD hook. Gameplay HUD layers should fade out for true and restore for false. */
	UPROPERTY(BlueprintAssignable, Category = "Inventory|UI")
	FInventoryUIPresentationSignature OnInventoryPresentationChanged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|UI")
	TSoftClassPtr<UInventoryWidgetBase> InventoryWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Input")
	TSoftObjectPtr<UInputAction> ToggleInventoryAction;

	/** UI가 Action Key를 먼저 소비해도 같은 Key로 닫을 수 있도록 Action이 들어 있는 Mapping Context를 지정한다. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Input")
	TSoftObjectPtr<UInputMappingContext> ToggleInputMappingContext;

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite, Category = "Inventory|Inspector")
	TObjectPtr<UInventoryItemInspectorBridge> InspectorBridge = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TObjectPtr<UInventoryComponent> InventoryComponent = nullptr;

	/** 비워 두면 C++ 기본 획득 알림 Widget을 사용한다. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Notification")
	TSubclassOf<UInventoryPickupNotificationWidget> PickupNotificationWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Notification", meta = (ClampMin = "0.1"))
	float PickupNotificationDuration = 2.0f;

	UFUNCTION(BlueprintCallable, Category = "Inventory|Input")
	bool BindEnhancedInput(UEnhancedInputComponent* EnhancedInputComponent);

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	bool OpenInventory();

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	bool OpenContainer(UInventoryContainerComponent* Container);

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void SetCurrentContainer(UInventoryContainerComponent* Container);

	UFUNCTION(BlueprintPure, Category = "Inventory|UI")
	UInventoryContainerComponent* GetCurrentContainer() const { return CurrentContainer; }

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void CloseInventory();

	UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
	void ToggleInventory();

	UFUNCTION(BlueprintPure, Category = "Inventory|UI")
	bool IsInventoryOpen() const;

	UFUNCTION(BlueprintCallable, Category = "Inventory|Inspector")
	bool InspectItem(UInventoryItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintPure, Category = "Inventory|UI")
	UInventoryWidgetBase* GetInventoryWidget() const { return InventoryWidget; }

	/** 현재 활성 Enhanced Input Mapping에서 ToggleInventoryAction에 연결된 Key인지 확인한다. */
	UFUNCTION(BlueprintPure, Category = "Inventory|Input")
	bool IsToggleInventoryKey(FKey Key) const;

protected:
	UFUNCTION()
	void HandleToggleInput();

	UFUNCTION()
	void HandleWidgetCloseRequested();

	UFUNCTION()
	void HandleWidgetCloseTransitionFinished();

	UFUNCTION()
	void HandleWidgetInspectTransitionFinished();

	UFUNCTION()
	void HandleInspectorClosed();

	UFUNCTION()
	void HandleItemsReceived(UInventoryItemDefinition* ItemDefinition, int32 Quantity);

	void HandleInventoryResolveTimer();
	bool ResolveAndBindInventoryComponent();

	APlayerController* ResolvePlayerController() const;
	UInventoryComponent* ResolveInventoryComponent() const;
	void ApplyInputMode(APlayerController* PlayerController);
	void RestoreInputMode();
	void FinalizeCloseInventory();
	void PublishPresentationEvent(bool bInventoryVisible);
	void PlayConfiguredSound(const TSoftObjectPtr<class USoundBase>& Sound) const;
	void UnbindEnhancedInput();

	UPROPERTY(Transient)
	TObjectPtr<UInventoryWidgetBase> InventoryWidget = nullptr;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Inventory|UI", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInventoryContainerComponent> CurrentContainer = nullptr;

	UPROPERTY(Transient)
	TObjectPtr<UInventoryPickupNotificationWidget> PickupNotificationWidget = nullptr;

	UPROPERTY(Transient)
	TObjectPtr<UInventoryItemDefinition> PendingInspectorItem = nullptr;

	TWeakObjectPtr<UEnhancedInputComponent> BoundEnhancedInputComponent;
	TWeakObjectPtr<UInventoryComponent> BoundNotificationInventory;
	TWeakObjectPtr<APlayerController> InputModePlayerController;
	TWeakObjectPtr<APawn> InputBlockedPawn;
	FTimerHandle InventoryResolveTimerHandle;
	bool bPreviousMouseCursor = false;
	bool bAppliedMoveInputBlock = false;
	bool bAppliedLookInputBlock = false;
	bool bAppliedPawnInputBlock = false;
	bool bClosePending = false;
	uint32 ToggleInputBindingHandle = 0;
};
