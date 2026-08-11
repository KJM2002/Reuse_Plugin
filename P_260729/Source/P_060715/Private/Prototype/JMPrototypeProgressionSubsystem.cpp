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
	ActiveQuestIndex = INDEX_NONE;
	SetRunState(EJMPrototypeRunState::AwaitingQuest);
	if (bResetPermanentProgress)
	{
		Currency = Config.InitialCurrency;
		CompletedQuestCount = 0;
		bInventoryUpgradePurchased = false;
		OnCurrencyChanged.Broadcast(Currency);
		OnInventoryUpgradeChanged.Broadcast(false);
	}
	return FJMPrototypeOperationResult::Success();
}

FJMPrototypeOperationResult UJMPrototypeProgressionSubsystem::AcceptQuest()
{
	if (!bConfigured || ActiveQuestIndex != INDEX_NONE)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidState,
			LOCTEXT("CannotAccept", "이미 진행 중인 의뢰가 있습니다."));
	}
	if (CompletedQuestCount >= 2)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidState,
			LOCTEXT("NoMoreQuests", "현재 받을 수 있는 추가 의뢰가 없습니다."));
	}
	ActiveQuestIndex = CompletedQuestCount;
	SetRunState(EJMPrototypeRunState::QuestAccepted);
	SaveTrackedBaseInventoryCheckpoint();
	return FJMPrototypeOperationResult::Success(FText::Format(
		LOCTEXT("QuestAcceptedMessage", "의뢰 {0}을(를) 수락했습니다."), FText::AsNumber(ActiveQuestIndex + 1)));
}

FJMPrototypeOperationResult UJMPrototypeProgressionSubsystem::EnterDungeon()
{
	if (!CanEnterDungeon())
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidState, LOCTEXT("CannotEnter", "The player is already exploring the dungeon."));
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

FJMPrototypeOperationResult UJMPrototypeProgressionSubsystem::SubmitQuest(UInventoryComponent* Inventory,
	UInventoryItemDefinition* QuestItem, int32 RequiredQuantity, int32 Reward, int32 QuestIndex)
{
	if (!bConfigured || ActiveQuestIndex == INDEX_NONE)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidState,
			LOCTEXT("CannotSubmit", "[아직 의뢰가 없습니다] 의뢰인에게서 의뢰를 먼저 받아 주세요."));
	}
	if (QuestIndex != ActiveQuestIndex)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidConfiguration,
			LOCTEXT("WrongQuestConfiguration", "제출대의 의뢰 정보가 현재 의뢰와 일치하지 않습니다."));
	}
	if (!IsValid(Inventory))
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::MissingInventory,
			LOCTEXT("MissingInventory", "플레이어 인벤토리를 찾을 수 없습니다."));
	}
	if (!IsValid(QuestItem) || RequiredQuantity <= 0)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::MissingItemDefinition,
			LOCTEXT("MissingQuestItem", "제출대에 의뢰 아이템이 설정되지 않았습니다."));
	}
	if (!Inventory->HasItem(QuestItem, RequiredQuantity))
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InsufficientItems,
			FText::Format(LOCTEXT("NotEnoughQuestItems", "의뢰 물품이 부족합니다. 필요 {0}개 / 보유 {1}개"),
				FText::AsNumber(RequiredQuantity), FText::AsNumber(Inventory->GetItemQuantity(QuestItem))));
	}
	if (!Inventory->RemoveItem(QuestItem, RequiredQuantity))
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InsufficientItems,
			LOCTEXT("RemoveQuestItemsFailed", "의뢰 물품 제출 처리에 실패했습니다. 인벤토리를 다시 확인해 주세요."));
	}

	const int32 GrantedReward = Reward >= 0 ? Reward : Config.QuestReward;
	AddCurrency(GrantedReward);
	++CompletedQuestCount;
	ActiveQuestIndex = INDEX_NONE;
	SetRunState(EJMPrototypeRunState::AwaitingQuest);
	SaveTrackedBaseInventoryCheckpoint();
	return FJMPrototypeOperationResult::Success(FText::Format(
		LOCTEXT("QuestSubmitted", "의뢰 물품 {0}개를 제출했습니다. 보상 +{1} 화폐\n[아직 의뢰가 없습니다]"),
		FText::AsNumber(RequiredQuantity), FText::AsNumber(GrantedReward)));
}

FJMPrototypeOperationResult UJMPrototypeProgressionSubsystem::CookAndSell(UInventoryComponent* Inventory, UInventoryItemDefinition* Ingredient, int32 RequiredQuantity)
{
	if (!bConfigured || RunState == EJMPrototypeRunState::Exploring)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidState, LOCTEXT("CannotCook", "요리는 기지에서만 사용할 수 있습니다."));
	}
	if (!IsValid(Inventory))
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::MissingInventory,
			LOCTEXT("MissingCookingInventory", "플레이어 인벤토리를 찾을 수 없습니다."));
	}
	if (!IsValid(Ingredient) || RequiredQuantity <= 0)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::MissingItemDefinition,
			LOCTEXT("MissingIngredient", "조리대에 요리 재료가 설정되지 않았습니다."));
	}
	if (!Inventory->HasItem(Ingredient, RequiredQuantity))
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InsufficientItems,
			FText::Format(LOCTEXT("NotEnoughIngredients", "점액 부산물이 부족합니다. 필요 {0}개 / 보유 {1}개"),
				FText::AsNumber(RequiredQuantity), FText::AsNumber(Inventory->GetItemQuantity(Ingredient))));
	}
	if (!Inventory->RemoveItem(Ingredient, RequiredQuantity))
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InsufficientItems,
			LOCTEXT("RemoveIngredientFailed", "요리 재료 소비 처리에 실패했습니다. 인벤토리를 다시 확인해 주세요."));
	}

	AddCurrency(Config.CookingReward);
	SaveTrackedBaseInventoryCheckpoint();
	return FJMPrototypeOperationResult::Success(FText::Format(
		LOCTEXT("CookingSold", "요리를 판매했습니다. 보상 +{0} 화폐"),
		FText::AsNumber(Config.CookingReward)));
}

FJMPrototypeOperationResult UJMPrototypeProgressionSubsystem::PurchaseInventoryUpgrade(UInventoryComponent* Inventory)
{
	if (!bConfigured || RunState == EJMPrototypeRunState::Exploring)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidState,
			LOCTEXT("CannotUpgrade", "인벤토리 업그레이드는 기지에서만 할 수 있습니다."));
	}
	if (bInventoryUpgradePurchased)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::AlreadyPurchased,
			LOCTEXT("AlreadyPurchased", "인벤토리 업그레이드를 이미 구매했습니다."));
	}
	if (!IsValid(Inventory))
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::MissingInventory,
			LOCTEXT("MissingUpgradeInventory", "플레이어 인벤토리를 찾을 수 없습니다."));
	}
	if (Currency < Config.InventoryUpgradeCost)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InsufficientCurrency,
			FText::Format(LOCTEXT("NotEnoughCurrency", "덕코인이 부족합니다. 비용 {0} / 보유 {1}"),
				FText::AsNumber(Config.InventoryUpgradeCost), FText::AsNumber(Currency)));
	}

	if (Inventory->SetMaxInventorySlots(Config.UpgradedInventorySlots) != EInventoryCapacityChangeResult::Success)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InventoryCapacityRejected,
			LOCTEXT("CapacityRejected", "가방에 든 아이템 때문에 슬롯 수를 변경할 수 없습니다."));
	}

	Currency -= Config.InventoryUpgradeCost;
	bInventoryUpgradePurchased = true;
	OnCurrencyChanged.Broadcast(Currency);
	OnInventoryUpgradeChanged.Broadcast(true);
	SaveTrackedBaseInventoryCheckpoint();
	return FJMPrototypeOperationResult::Success(FText::Format(
		LOCTEXT("InventoryUpgraded", "인벤토리를 {0}칸으로 업그레이드했습니다. 비용 -{1} 화폐"),
		FText::AsNumber(Config.UpgradedInventorySlots), FText::AsNumber(Config.InventoryUpgradeCost)));
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
		SetRunState(ActiveQuestIndex == INDEX_NONE
			? EJMPrototypeRunState::AwaitingQuest
			: EJMPrototypeRunState::QuestAccepted);
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
	SaveObject->SaveVersion = 2;
	SaveObject->Currency = Currency;
	SaveObject->bInventoryUpgradePurchased = bInventoryUpgradePurchased;
	SaveObject->RunState = RunState;
	SaveObject->ActiveQuestIndex = ActiveQuestIndex;
	SaveObject->CompletedQuestCount = CompletedQuestCount;
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
	if (SaveObject->SaveVersion >= 1)
	{
		Currency = FMath::Max(0, SaveObject->Currency);
		bInventoryUpgradePurchased = SaveObject->bInventoryUpgradePurchased;
		SetRunState(SaveObject->RunState);
		OnCurrencyChanged.Broadcast(Currency);
		OnInventoryUpgradeChanged.Broadcast(bInventoryUpgradePurchased);
	}
	if (SaveObject->SaveVersion >= 2)
	{
		ActiveQuestIndex = SaveObject->ActiveQuestIndex;
		CompletedQuestCount = FMath::Clamp(SaveObject->CompletedQuestCount, 0, 2);
	}
	else
	{
		// Legacy saves had one quest and no explicit active slot.
		ActiveQuestIndex = (SaveObject->RunState == EJMPrototypeRunState::QuestAccepted
			|| SaveObject->RunState == EJMPrototypeRunState::Exploring
			|| SaveObject->RunState == EJMPrototypeRunState::Returned) ? 0 : INDEX_NONE;
		CompletedQuestCount = SaveObject->RunState == EJMPrototypeRunState::QuestCompleted ? 1 : 0;
		if (SaveObject->RunState == EJMPrototypeRunState::QuestCompleted)
		{
			SetRunState(EJMPrototypeRunState::AwaitingQuest);
		}
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

void UJMPrototypeProgressionSubsystem::SaveTrackedBaseInventoryCheckpoint() const
{
	if (TrackedBaseInventory.IsValid())
	{
		SaveBaseInventoryCheckpoint(TrackedBaseInventory.Get());
	}
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
			// Level portals intentionally have no quest gate. Keep their state
			// transition on the same policy as every other dungeon entry path.
			EnterDungeon();
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
