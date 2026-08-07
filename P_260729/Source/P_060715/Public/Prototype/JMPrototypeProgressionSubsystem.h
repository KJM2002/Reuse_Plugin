#pragma once

#include "CoreMinimal.h"
#include "Prototype/JMPrototypeTypes.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "JMPrototypeProgressionSubsystem.generated.h"

class UInventoryComponent;
class UInventoryItemDefinition;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FJMPrototypeRunStateChangedSignature, EJMPrototypeRunState, PreviousState, EJMPrototypeRunState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJMPrototypeCurrencyChangedSignature, int32, NewCurrency);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJMPrototypeInventoryUpgradeChangedSignature, bool, bPurchased);

/** Session-scoped, single-player prototype state that survives map travel. */
UCLASS()
class P_060715_API UJMPrototypeProgressionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintAssignable, Category = "Base Upgrade Prototype|Events")
	FJMPrototypeRunStateChangedSignature OnRunStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "Base Upgrade Prototype|Events")
	FJMPrototypeCurrencyChangedSignature OnCurrencyChanged;

	UPROPERTY(BlueprintAssignable, Category = "Base Upgrade Prototype|Events")
	FJMPrototypeInventoryUpgradeChangedSignature OnInventoryUpgradeChanged;

	UFUNCTION(BlueprintCallable, Category = "Base Upgrade Prototype")
	FJMPrototypeOperationResult ConfigurePrototype(const FJMPrototypeConfig& InConfig, bool bResetPermanentProgress = true);

	UFUNCTION(BlueprintCallable, Category = "Base Upgrade Prototype")
	FJMPrototypeOperationResult AcceptQuest();

	UFUNCTION(BlueprintCallable, Category = "Base Upgrade Prototype")
	FJMPrototypeOperationResult EnterDungeon();

	UFUNCTION(BlueprintCallable, Category = "Base Upgrade Prototype")
	FJMPrototypeOperationResult ReturnToBase();

	UFUNCTION(BlueprintCallable, Category = "Base Upgrade Prototype")
	FJMPrototypeOperationResult SubmitQuest(UInventoryComponent* Inventory, UInventoryItemDefinition* QuestItem, int32 RequiredQuantity = 3);

	UFUNCTION(BlueprintCallable, Category = "Base Upgrade Prototype")
	FJMPrototypeOperationResult CookAndSell(UInventoryComponent* Inventory, UInventoryItemDefinition* Ingredient, int32 RequiredQuantity = 1);

	UFUNCTION(BlueprintCallable, Category = "Base Upgrade Prototype")
	FJMPrototypeOperationResult PurchaseInventoryUpgrade(UInventoryComponent* Inventory);

	UFUNCTION(BlueprintCallable, Category = "Base Upgrade Prototype")
	FJMPrototypeOperationResult ApplyOwnedInventoryCapacity(UInventoryComponent* Inventory) const;

	UFUNCTION(BlueprintCallable, Category = "Base Upgrade Prototype")
	void ResetCurrentRun();

	UFUNCTION(BlueprintCallable, Category = "Base Upgrade Prototype|Travel")
	void CaptureTravelInventory(UInventoryComponent* Inventory, const TArray<UInventoryItemDefinition*>& ItemDefinitions);

	UFUNCTION(BlueprintCallable, Category = "Base Upgrade Prototype|Travel")
	bool RestoreTravelInventory(UInventoryComponent* Inventory);

	/** Snapshots every occupied inventory slot before map travel. */
	UFUNCTION(BlueprintCallable, Category = "Base Upgrade Prototype|Travel")
	void CaptureEntireTravelInventory(UInventoryComponent* Inventory);

	/** Restores the last disk checkpoint, but only while the player is in the base level. */
	UFUNCTION(BlueprintCallable, Category = "Base Upgrade Prototype|Save")
	bool RestoreBaseInventoryCheckpoint(UInventoryComponent* Inventory);

	/** Writes a staged dungeon-return checkpoint after the base inventory has actually been restored. */
	bool CommitBaseInventoryCheckpointIfPending(UInventoryComponent* Inventory);

	/** Starts checkpoint updates for trusted base inventory changes (quest turn-in, cooking, sorting, etc.). */
	void BeginBaseInventoryCheckpointTracking(UInventoryComponent* Inventory, bool bTrustedBaseInventory);

	/** Exact transition predicate kept public so the anti-exploit boundary can be automation-tested. */
	static bool IsBaseReturnCheckpointTransition(const FString& SourceMap, const FString& DestinationMap);

	/** Marks an intentional OpenLevel so the next map keeps the current run. */
	void MarkLevelTravelPending();

	/** Consumes the one-shot travel marker on arrival. */
	bool ConsumeLevelTravelPending();

	/** Restores the source state when OpenLevel did not leave the source world. */
	bool CancelPendingLevelTravel(EJMPrototypeRunState StateBeforeTravel);

	UFUNCTION(BlueprintPure, Category = "Base Upgrade Prototype")
	bool IsConfigured() const { return bConfigured; }

	UFUNCTION(BlueprintPure, Category = "Base Upgrade Prototype")
	EJMPrototypeRunState GetRunState() const { return RunState; }

	UFUNCTION(BlueprintPure, Category = "Base Upgrade Prototype")
	int32 GetCurrency() const { return Currency; }

	UFUNCTION(BlueprintPure, Category = "Base Upgrade Prototype")
	bool HasInventoryUpgrade() const { return bInventoryUpgradePurchased; }

	UFUNCTION(BlueprintPure, Category = "Base Upgrade Prototype")
	FJMPrototypeConfig GetPrototypeConfig() const { return Config; }

	UFUNCTION(BlueprintPure, Category = "Base Upgrade Prototype")
	bool CanEnterDungeon() const { return bConfigured && RunState == EJMPrototypeRunState::QuestAccepted; }

	UFUNCTION(BlueprintPure, Category = "Base Upgrade Prototype")
	bool CanReturnToBase() const { return bConfigured && RunState == EJMPrototypeRunState::Exploring; }

private:
	UFUNCTION()
	void HandleTrackedBaseInventoryChanged();

	void HandlePreLoadMap(const FString& MapName);
	bool SaveBaseInventoryCheckpoint(UInventoryComponent* Inventory) const;
	void SaveTrackedBaseInventoryCheckpoint() const;
	static void ClearInventoryContents(UInventoryComponent* Inventory);
	static bool IsExactLevelName(const FString& MapName, const TCHAR* ExpectedShortName);
	void SetRunState(EJMPrototypeRunState NewState);
	void AddCurrency(int32 Amount);

	UPROPERTY(Transient)
	FJMPrototypeConfig Config;

	UPROPERTY(Transient)
	EJMPrototypeRunState RunState = EJMPrototypeRunState::AwaitingQuest;

	UPROPERTY(Transient)
	int32 Currency = 0;

	UPROPERTY(Transient)
	bool bInventoryUpgradePurchased = false;

	UPROPERTY(Transient)
	bool bConfigured = false;

	UPROPERTY(Transient)
	TMap<TObjectPtr<UInventoryItemDefinition>, int32> TravelInventory;

	bool bHasTravelInventorySnapshot = false;
	bool bDungeonRunStartedThisSession = false;
	bool bCommitInventoryCheckpointOnBaseArrival = false;
	bool bWritingInventoryCheckpoint = false;

	TWeakObjectPtr<UInventoryComponent> TrackedBaseInventory;

	bool bLevelTravelPending = false;

	static const FString InventoryCheckpointSlot;
};
