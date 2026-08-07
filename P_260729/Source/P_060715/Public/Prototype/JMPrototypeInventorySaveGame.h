#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
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
	UPROPERTY(SaveGame)
	TArray<FJMPrototypeSavedInventoryEntry> Items;

	UPROPERTY(SaveGame)
	int32 InventoryCapacity = 4;
};
