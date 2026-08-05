#include "Components/InventoryContainerComponent.h"

#include "Items/InventoryItemDefinition.h"
#include "Engine/DataTable.h"

UInventoryContainerComponent::UInventoryContainerComponent()
{
	ContainerName = NSLOCTEXT("JMInventory", "DefaultContainerName", "Container");
	MaxInventorySlots = 12;
}

void UInventoryContainerComponent::BeginPlay()
{
	Super::BeginPlay();
	if (!ContainerID.IsValid())
	{
		ContainerID = FGuid::NewGuid();
	}
	if (bGenerateLootOnBeginPlay)
	{
		GenerateInitialLoot();
	}
}

void UInventoryContainerComponent::GenerateInitialLoot()
{
	if (bInitialLootGenerated)
	{
		return;
	}
	bInitialLootGenerated = true;
	for (const FInventoryInitialItem& Entry : InitialLoot)
	{
		if (!IsValid(Entry.ItemDefinition) || FMath::FRand() > FMath::Clamp(Entry.SpawnChance, 0.0f, 1.0f))
		{
			continue;
		}
		const int32 MinQuantity = FMath::Max(1, Entry.MinQuantity);
		const int32 MaxQuantity = FMath::Max(MinQuantity, Entry.MaxQuantity);
		AddItemDetailed(Entry.ItemDefinition, FMath::RandRange(MinQuantity, MaxQuantity));
	}

	if (LootTable && LootTableRolls > 0)
	{
		TArray<FInventoryLootTableRow*> Rows;
		LootTable->GetAllRows(TEXT("InventoryContainerLoot"), Rows);
		for (int32 Roll = 0; Roll < LootTableRolls; ++Roll)
		{
			float TotalWeight = 0.0f;
			for (const FInventoryLootTableRow* Row : Rows)
			{
				if (Row && IsValid(Row->ItemDefinition))
				{
					TotalWeight += FMath::Max(0.0f, Row->Weight);
				}
			}
			if (TotalWeight <= 0.0f)
			{
				break;
			}
			float Choice = FMath::FRandRange(0.0f, TotalWeight);
			for (const FInventoryLootTableRow* Row : Rows)
			{
				if (!Row || !IsValid(Row->ItemDefinition))
				{
					continue;
				}
				Choice -= FMath::Max(0.0f, Row->Weight);
				if (Choice <= 0.0f)
				{
					const int32 MinQuantity = FMath::Max(1, Row->MinQuantity);
					AddItemDetailed(Row->ItemDefinition, FMath::RandRange(MinQuantity, FMath::Max(MinQuantity, Row->MaxQuantity)));
					break;
				}
			}
		}
	}
}
