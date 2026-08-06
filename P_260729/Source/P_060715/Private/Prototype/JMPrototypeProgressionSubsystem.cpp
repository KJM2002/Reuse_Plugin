#include "Prototype/JMPrototypeProgressionSubsystem.h"

#include "Components/InventoryComponent.h"
#include "InventoryTypes.h"
#include "Items/InventoryItemDefinition.h"

#define LOCTEXT_NAMESPACE "JMPrototypeProgression"

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
	if (!IsValid(Inventory) || TravelInventory.IsEmpty())
	{
		return false;
	}
	bool bRestoredAll = true;
	for (const TPair<TObjectPtr<UInventoryItemDefinition>, int32>& Entry : TravelInventory)
	{
		UInventoryItemDefinition* Item = Entry.Key;
		if (!IsValid(Item) || Entry.Value <= 0)
		{
			continue;
		}
		const int32 ExistingQuantity = Inventory->GetItemQuantity(Item);
		if (ExistingQuantity > 0)
		{
			Inventory->RemoveItem(Item, ExistingQuantity);
		}
		bRestoredAll &= Inventory->AddItem(Item, Entry.Value);
	}
	TravelInventory.Reset();
	return bRestoredAll;
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
