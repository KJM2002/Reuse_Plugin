#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Prototype/JMPrototypeTypes.h"
#include "UObject/SoftObjectPtr.h"
#include "JMPrototypeInventorySaveGame.generated.h"

class UInventoryItemDefinition;

USTRUCT()
struct FJMPrototypeSavedInventoryEntry
{
	GENERATED_BODY()

	UPROPERTY(SaveGame)
	TSoftObjectPtr<UInventoryItemDefinition> ItemDefinition;

	UPROPERTY(SaveGame)
	int32 Quantity = 0;
};

/** Last inventory checkpoint created by a successful dungeon-to-base transition. */
UCLASS()
class P_060715_API UJMPrototypeInventorySaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	/** Zero identifies inventory-only checkpoints written before economy persistence was added. */
	UPROPERTY(SaveGame)
	int32 SaveVersion = 0;

	UPROPERTY(SaveGame)
	TArray<FJMPrototypeSavedInventoryEntry> Items;

	UPROPERTY(SaveGame)
	int32 InventoryCapacity = 4;

	UPROPERTY(SaveGame)
	int32 Currency = 0;

	UPROPERTY(SaveGame)
	bool bInventoryUpgradePurchased = false;

	UPROPERTY(SaveGame)
	EJMPrototypeRunState RunState = EJMPrototypeRunState::AwaitingQuest;

	UPROPERTY(SaveGame)
	int32 ActiveQuestIndex = INDEX_NONE;

	UPROPERTY(SaveGame)
	int32 CompletedQuestCount = 0;
};
