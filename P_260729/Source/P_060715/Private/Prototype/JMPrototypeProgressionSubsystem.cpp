#include "Prototype/JMPrototypeProgressionSubsystem.h"

#include "Components/InventoryComponent.h"
#include "Engine/GameInstance.h"
#include "GameFramework/Pawn.h"
#include "InventoryTypes.h"
#include "Items/InventoryItemDefinition.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/PackageName.h"
#include "Prototype/JMPrototypeInventoryResolver.h"
#include "Prototype/JMPrototypeInventorySaveGame.h"
#include "UObject/UObjectGlobals.h"

#define LOCTEXT_NAMESPACE "JMPrototypeProgression"

DEFINE_LOG_CATEGORY_STATIC(LogJMPrototypeInventoryTravel, Log, All);

const FString UJMPrototypeProgressionSubsystem::InventoryCheckpointSlot = TEXT("BaseUpgrade_PrototypeInventoryCheckpoint");

void UJMPrototypeProgressionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UJMPrototypeProgressionSubsystem::HandlePreLoadMap);
}

void UJMPrototypeProgressionSubsystem::Deinitialize()
{
	if (TrackedBaseInventory.IsValid())
	{
		TrackedBaseInventory->OnInventoryChanged.RemoveDynamic(this, &ThisClass::HandleTrackedBaseInventoryChanged);
	}
	TrackedBaseInventory.Reset();
	FCoreUObjectDelegates::PreLoadMap.RemoveAll(this);
	Super::Deinitialize();
}

FJMPrototypeOperationResult UJMPrototypeProgressionSubsystem::ConfigurePrototype(const FJMPrototypeConfig& InConfig, bool bResetPermanentProgress)
{
	if (!InConfig.IsValid())
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidConfiguration, LOCTEXT("InvalidConfig", "Prototype configuration is invalid."));
	}

	Config = InConfig;
	bConfigured = true;
	bLevelTravelPending = false;
	TravelInventory.Reset();
	bHasTravelInventorySnapshot = false;
	bDungeonRunStartedThisSession = false;
	bCommitInventoryCheckpointOnBaseArrival = false;
	SetRunState(EJMPrototypeRunState::AwaitingQuest);
	if (bResetPermanentProgress)
	{
		Currency = Config.InitialCurrency;
		bInventoryUpgradePurchased = false;
		OnCurrencyChanged.Broadcast(Currency);
		OnInventoryUpgradeChanged.Broadcast(false);
	}
	return FJMPrototypeOperationResult::Success();
}

FJMPrototypeOperationResult UJMPrototypeProgressionSubsystem::AcceptQuest()
{
	if (!bConfigured || (RunState != EJMPrototypeRunState::AwaitingQuest && RunState != EJMPrototypeRunState::QuestCompleted))
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidState, LOCTEXT("CannotAccept", "A quest cannot be accepted in the current state."));
	}
	SetRunState(EJMPrototypeRunState::QuestAccepted);
	return FJMPrototypeOperationResult::Success();
}

FJMPrototypeOperationResult UJMPrototypeProgressionSubsystem::EnterDungeon()
{
	if (!CanEnterDungeon())
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidState, LOCTEXT("CannotEnter", "Accept the quest before entering the dungeon."));
	}
	SetRunState(EJMPrototypeRunState::Exploring);
	return FJMPrototypeOperationResult::Success();
}

FJMPrototypeOperationResult UJMPrototypeProgressionSubsystem::ReturnToBase()
{
	if (!CanReturnToBase())
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidState, LOCTEXT("CannotReturn", "The player is not currently exploring."));
	}
	SetRunState(EJMPrototypeRunState::Returned);
	return FJMPrototypeOperationResult::Success();
}

FJMPrototypeOperationResult UJMPrototypeProgressionSubsystem::SubmitQuest(UInventoryComponent* Inventory, UInventoryItemDefinition* QuestItem, int32 RequiredQuantity)
{
	if (!bConfigured || RunState != EJMPrototypeRunState::Returned)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidState, LOCTEXT("CannotSubmit", "Return from the dungeon before submitting the quest."));
	}
	if (!IsValid(Inventory))
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::MissingInventory, LOCTEXT("MissingInventory", "No inventory was found."));
	}
	if (!IsValid(QuestItem) || RequiredQuantity <= 0)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::MissingItemDefinition, LOCTEXT("MissingQuestItem", "Quest item setup is invalid."));
	}
	if (!Inventory->HasItem(QuestItem, RequiredQuantity))
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InsufficientItems, LOCTEXT("NotEnoughQuestItems", "The required quest items are missing."));
	}
	if (!Inventory->RemoveItem(QuestItem, RequiredQuantity))
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InsufficientItems, LOCTEXT("RemoveQuestItemsFailed", "Quest items could not be removed."));
	}

	AddCurrency(Config.QuestReward);
	SetRunState(EJMPrototypeRunState::QuestCompleted);
	return FJMPrototypeOperationResult::Success();
}

FJMPrototypeOperationResult UJMPrototypeProgressionSubsystem::CookAndSell(UInventoryComponent* Inventory, UInventoryItemDefinition* Ingredient, int32 RequiredQuantity)
{
	if (!bConfigured || RunState == EJMPrototypeRunState::Exploring || RunState == EJMPrototypeRunState::AwaitingQuest)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidState, LOCTEXT("CannotCook", "Cooking is only available at the base during an active or completed run."));
	}
	if (!IsValid(Inventory))
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::MissingInventory, LOCTEXT("MissingCookingInventory", "No inventory was found."));
	}
	if (!IsValid(Ingredient) || RequiredQuantity <= 0)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::MissingItemDefinition, LOCTEXT("MissingIngredient", "Cooking ingredient setup is invalid."));
	}
	if (!Inventory->HasItem(Ingredient, RequiredQuantity) || !Inventory->RemoveItem(Ingredient, RequiredQuantity))
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InsufficientItems, LOCTEXT("NotEnoughIngredients", "The required cooking ingredient is missing."));
	}

	AddCurrency(Config.CookingReward);
	return FJMPrototypeOperationResult::Success();
}

FJMPrototypeOperationResult UJMPrototypeProgressionSubsystem::PurchaseInventoryUpgrade(UInventoryComponent* Inventory)
{
	if (!bConfigured || RunState == EJMPrototypeRunState::Exploring)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidState, LOCTEXT("CannotUpgrade", "Inventory upgrades are only available at the base."));
	}
	if (bInventoryUpgradePurchased)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::AlreadyPurchased, LOCTEXT("AlreadyPurchased", "The inventory upgrade is already owned."));
	}
	if (!IsValid(Inventory))
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::MissingInventory, LOCTEXT("MissingUpgradeInventory", "No inventory was found."));
	}
	if (Currency < Config.InventoryUpgradeCost)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InsufficientCurrency, LOCTEXT("NotEnoughCurrency", "There is not enough currency for this upgrade."));
	}

	if (Inventory->SetMaxInventorySlots(Config.UpgradedInventorySlots) != EInventoryCapacityChangeResult::Success)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InventoryCapacityRejected, LOCTEXT("CapacityRejected", "The inventory capacity could not be changed."));
	}

	Currency -= Config.InventoryUpgradeCost;
	bInventoryUpgradePurchased = true;
	OnCurrencyChanged.Broadcast(Currency);
	OnInventoryUpgradeChanged.Broadcast(true);
	return FJMPrototypeOperationResult::Success();
}

FJMPrototypeOperationResult UJMPrototypeProgressionSubsystem::ApplyOwnedInventoryCapacity(UInventoryComponent* Inventory) const
{
	if (!bConfigured)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidConfiguration, LOCTEXT("NotConfigured", "The prototype has not been configured."));
	}
	if (!IsValid(Inventory))
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::MissingInventory, LOCTEXT("MissingApplyInventory", "No inventory was found."));
	}

	const int32 DesiredCapacity = bInventoryUpgradePurchased ? Config.UpgradedInventorySlots : Config.BaseInventorySlots;
	if (Inventory->SetMaxInventorySlots(DesiredCapacity) != EInventoryCapacityChangeResult::Success)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InventoryCapacityRejected, LOCTEXT("ApplyCapacityRejected", "The owned inventory capacity could not be applied."));
	}
	return FJMPrototypeOperationResult::Success();
}

void UJMPrototypeProgressionSubsystem::ResetCurrentRun()
{
	if (bConfigured)
	{
		SetRunState(EJMPrototypeRunState::AwaitingQuest);
	}
}

void UJMPrototypeProgressionSubsystem::CaptureTravelInventory(UInventoryComponent* Inventory, const TArray<UInventoryItemDefinition*>& ItemDefinitions)
{
	TravelInventory.Reset();
	bHasTravelInventorySnapshot = IsValid(Inventory);
	if (!IsValid(Inventory))
	{
		return;
	}
	for (UInventoryItemDefinition* Item : ItemDefinitions)
	{
		if (IsValid(Item))
		{
			const int32 Quantity = Inventory->GetItemQuantity(Item);
			if (Quantity > 0)
			{
				TravelInventory.Add(Item, Quantity);
			}
		}
	}
}

bool UJMPrototypeProgressionSubsystem::RestoreTravelInventory(UInventoryComponent* Inventory)
{
	if (!IsValid(Inventory) || !bHasTravelInventorySnapshot)
	{
		return false;
	}
	ClearInventoryContents(Inventory);
	bool bRestoredAll = true;
	for (const TPair<TObjectPtr<UInventoryItemDefinition>, int32>& Entry : TravelInventory)
	{
		UInventoryItemDefinition* Item = Entry.Key;
		if (!IsValid(Item) || Entry.Value <= 0)
		{
			continue;
		}
		bRestoredAll &= Inventory->AddItem(Item, Entry.Value);
	}
	TravelInventory.Reset();
	bHasTravelInventorySnapshot = false;
	UE_LOG(LogJMPrototypeInventoryTravel, Display, TEXT("Restored inventory after map travel. Success=%s"), bRestoredAll ? TEXT("true") : TEXT("false"));
	return bRestoredAll;
}

void UJMPrototypeProgressionSubsystem::CaptureEntireTravelInventory(UInventoryComponent* Inventory)
{
	TravelInventory.Reset();
	bHasTravelInventorySnapshot = IsValid(Inventory);
	if (!IsValid(Inventory))
	{
		return;
	}
	int32 TotalQuantity = 0;
	for (const FInventorySlot& Slot : Inventory->GetSlotsNative())
	{
		if (!Slot.IsValid())
		{
			continue;
		}
		TravelInventory.FindOrAdd(Slot.ItemDefinition) += Slot.Quantity;
		TotalQuantity += Slot.Quantity;
	}
	UE_LOG(LogJMPrototypeInventoryTravel, Display,
		TEXT("Captured inventory before map travel. ItemTypes=%d TotalQuantity=%d"),
		TravelInventory.Num(), TotalQuantity);
}

void UJMPrototypeProgressionSubsystem::ClearInventoryContents(UInventoryComponent* Inventory)
{
	if (!IsValid(Inventory))
	{
		return;
	}
	const TArray<FInventorySlot> ExistingSlots = Inventory->GetInventorySlots();
	for (int32 SlotIndex = ExistingSlots.Num() - 1; SlotIndex >= 0; --SlotIndex)
	{
		if (ExistingSlots[SlotIndex].IsValid())
		{
			Inventory->RemoveItemAtSlot(SlotIndex, ExistingSlots[SlotIndex].Quantity);
		}
	}
}

bool UJMPrototypeProgressionSubsystem::IsExactLevelName(const FString& MapName, const TCHAR* ExpectedShortName)
{
	FString CleanName = MapName;
	int32 OptionsIndex = INDEX_NONE;
	if (CleanName.FindChar(TEXT('?'), OptionsIndex))
	{
		CleanName.LeftInline(OptionsIndex);
	}
	FString ShortName = FPackageName::GetShortName(CleanName);
	if (ShortName.StartsWith(TEXT("UEDPIE_")))
	{
		const int32 InstanceSeparator = ShortName.Find(TEXT("_"), ESearchCase::CaseSensitive, ESearchDir::FromStart, 7);
		if (InstanceSeparator != INDEX_NONE)
		{
			ShortName.RightChopInline(InstanceSeparator + 1);
		}
	}
	return ShortName.Equals(ExpectedShortName, ESearchCase::CaseSensitive);
}

bool UJMPrototypeProgressionSubsystem::IsBaseReturnCheckpointTransition(
	const FString& SourceMap, const FString& DestinationMap)
{
	return IsExactLevelName(SourceMap, TEXT("Level_Mapgenerate"))
		&& IsExactLevelName(DestinationMap, TEXT("Level_Prototype"));
}

bool UJMPrototypeProgressionSubsystem::SaveBaseInventoryCheckpoint(UInventoryComponent* Inventory) const
{
	if (!IsValid(Inventory))
	{
		return false;
	}
	UJMPrototypeInventorySaveGame* SaveObject = Cast<UJMPrototypeInventorySaveGame>(
		UGameplayStatics::CreateSaveGameObject(UJMPrototypeInventorySaveGame::StaticClass()));
	if (!SaveObject)
	{
		return false;
	}
	SaveObject->InventoryCapacity = Inventory->GetMaxInventorySlots();
	for (const FInventorySlot& Slot : Inventory->GetSlotsNative())
	{
		if (!Slot.IsValid())
		{
			continue;
		}
		FJMPrototypeSavedInventoryEntry& Entry = SaveObject->Items.AddDefaulted_GetRef();
		Entry.ItemDefinition = Slot.ItemDefinition;
		Entry.Quantity = Slot.Quantity;
	}
	const bool bSaved = UGameplayStatics::SaveGameToSlot(SaveObject, InventoryCheckpointSlot, 0);
	UE_LOG(LogJMPrototypeInventoryTravel, Display,
		TEXT("Base return inventory checkpoint saved. Success=%s Entries=%d"),
		bSaved ? TEXT("true") : TEXT("false"), SaveObject->Items.Num());
	return bSaved;
}

bool UJMPrototypeProgressionSubsystem::RestoreBaseInventoryCheckpoint(UInventoryComponent* Inventory)
{
	UGameInstance* GameInstance = GetGameInstance();
	UWorld* World = GameInstance ? GameInstance->GetWorld() : nullptr;
	if (!IsValid(Inventory) || !World
		|| !IsExactLevelName(World->GetOutermost()->GetName(), TEXT("Level_Prototype"))
		|| !UGameplayStatics::DoesSaveGameExist(InventoryCheckpointSlot, 0))
	{
		return false;
	}
	UJMPrototypeInventorySaveGame* SaveObject = Cast<UJMPrototypeInventorySaveGame>(
		UGameplayStatics::LoadGameFromSlot(InventoryCheckpointSlot, 0));
	if (!SaveObject)
	{
		return false;
	}
	if (SaveObject->InventoryCapacity > 0)
	{
		Inventory->SetMaxInventorySlots(SaveObject->InventoryCapacity);
	}
	ClearInventoryContents(Inventory);
	bool bRestoredAll = true;
	for (const FJMPrototypeSavedInventoryEntry& Entry : SaveObject->Items)
	{
		UInventoryItemDefinition* Item = Entry.ItemDefinition.LoadSynchronous();
		if (IsValid(Item) && Entry.Quantity > 0)
		{
			bRestoredAll &= Inventory->AddItem(Item, Entry.Quantity);
		}
	}
	UE_LOG(LogJMPrototypeInventoryTravel, Display,
		TEXT("Base inventory checkpoint restored. Success=%s Entries=%d"),
		bRestoredAll ? TEXT("true") : TEXT("false"), SaveObject->Items.Num());
	return bRestoredAll;
}

bool UJMPrototypeProgressionSubsystem::CommitBaseInventoryCheckpointIfPending(UInventoryComponent* Inventory)
{
	if (!bCommitInventoryCheckpointOnBaseArrival || !IsValid(Inventory))
	{
		return false;
	}
	UGameInstance* GameInstance = GetGameInstance();
	UWorld* World = GameInstance ? GameInstance->GetWorld() : nullptr;
	if (!World || !IsExactLevelName(World->GetOutermost()->GetName(), TEXT("Level_Prototype")))
	{
		return false;
	}
	bCommitInventoryCheckpointOnBaseArrival = false;
	return SaveBaseInventoryCheckpoint(Inventory);
}

void UJMPrototypeProgressionSubsystem::BeginBaseInventoryCheckpointTracking(
	UInventoryComponent* Inventory, const bool bTrustedBaseInventory)
{
	if (TrackedBaseInventory.IsValid())
	{
		TrackedBaseInventory->OnInventoryChanged.RemoveDynamic(this, &ThisClass::HandleTrackedBaseInventoryChanged);
	}
	TrackedBaseInventory.Reset();

	UGameInstance* GameInstance = GetGameInstance();
	UWorld* World = GameInstance ? GameInstance->GetWorld() : nullptr;
	if (!bTrustedBaseInventory || !IsValid(Inventory) || !World
		|| !IsExactLevelName(World->GetOutermost()->GetName(), TEXT("Level_Prototype")))
	{
		return;
	}
	TrackedBaseInventory = Inventory;
	Inventory->OnInventoryChanged.AddUniqueDynamic(this, &ThisClass::HandleTrackedBaseInventoryChanged);
	// This also creates the initial clean-base checkpoint on a new game.
	SaveBaseInventoryCheckpoint(Inventory);
}

void UJMPrototypeProgressionSubsystem::HandleTrackedBaseInventoryChanged()
{
	if (bWritingInventoryCheckpoint || !TrackedBaseInventory.IsValid())
	{
		return;
	}
	bWritingInventoryCheckpoint = true;
	SaveBaseInventoryCheckpoint(TrackedBaseInventory.Get());
	bWritingInventoryCheckpoint = false;
}

void UJMPrototypeProgressionSubsystem::HandlePreLoadMap(const FString& MapName)
{
	UGameInstance* GameInstance = GetGameInstance();
	UWorld* World = GameInstance ? GameInstance->GetWorld() : nullptr;
	APawn* PlayerPawn = World ? UGameplayStatics::GetPlayerPawn(World, 0) : nullptr;
	if (PlayerPawn)
	{
		UInventoryComponent* Inventory = JMPrototypeInventory::Resolve(PlayerPawn);
		CaptureEntireTravelInventory(Inventory);
		const FString SourceMap = World->GetOutermost()->GetName();
		const bool bEnteringDungeon = IsExactLevelName(SourceMap, TEXT("Level_Prototype"))
			&& IsExactLevelName(MapName, TEXT("Level_Mapgenerate"));
		const bool bReturningToBase = IsBaseReturnCheckpointTransition(SourceMap, MapName);
		if (bEnteringDungeon)
		{
			// Portals intentionally have no quest gate, but an accepted quest still
			// needs its lifecycle advanced when the level transition succeeds.
			if (bConfigured && RunState == EJMPrototypeRunState::QuestAccepted)
			{
				SetRunState(EJMPrototypeRunState::Exploring);
			}
			bDungeonRunStartedThisSession = true;
			bCommitInventoryCheckpointOnBaseArrival = false;
		}
		else if (bReturningToBase)
		{
			if (bConfigured && (RunState == EJMPrototypeRunState::Exploring
				|| RunState == EJMPrototypeRunState::QuestAccepted))
			{
				SetRunState(EJMPrototypeRunState::Returned);
			}
			bCommitInventoryCheckpointOnBaseArrival = bDungeonRunStartedThisSession;
			bDungeonRunStartedThisSession = false;
		}
		else
		{
			bDungeonRunStartedThisSession = false;
			bCommitInventoryCheckpointOnBaseArrival = false;
		}
	}
}

void UJMPrototypeProgressionSubsystem::MarkLevelTravelPending()
{
	bLevelTravelPending = true;
}

bool UJMPrototypeProgressionSubsystem::ConsumeLevelTravelPending()
{
	const bool bWasPending = bLevelTravelPending;
	bLevelTravelPending = false;
	return bWasPending;
}

bool UJMPrototypeProgressionSubsystem::CancelPendingLevelTravel(EJMPrototypeRunState StateBeforeTravel)
{
	if (!bLevelTravelPending)
	{
		return false;
	}
	bLevelTravelPending = false;
	TravelInventory.Reset();
	SetRunState(StateBeforeTravel);
	return true;
}

void UJMPrototypeProgressionSubsystem::SetRunState(EJMPrototypeRunState NewState)
{
	if (RunState == NewState)
	{
		return;
	}
	const EJMPrototypeRunState PreviousState = RunState;
	RunState = NewState;
	OnRunStateChanged.Broadcast(PreviousState, RunState);
}

void UJMPrototypeProgressionSubsystem::AddCurrency(int32 Amount)
{
	if (Amount <= 0)
	{
		return;
	}
	Currency = static_cast<int32>(FMath::Min<int64>(MAX_int32, static_cast<int64>(Currency) + Amount));
	OnCurrencyChanged.Broadcast(Currency);
}

#undef LOCTEXT_NAMESPACE
