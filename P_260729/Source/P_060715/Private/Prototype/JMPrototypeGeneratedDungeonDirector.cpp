#include "Prototype/JMPrototypeGeneratedDungeonDirector.h"

#include "AI/Blackout/JMBlackoutMonster.h"
#include "AI/Common/JMDungeonMonster.h"
#include "AI/Hoarder/JMHoarderMonster.h"
#include "AI/Listener/JMListenerMonster.h"
#include "Actors/JMGridMapGenerator.h"
#include "Actors/JMCustomGridMapGenerator.h"
#include "Actors/JMRoomModule.h"
#include "Dungeon/Content/JMDungeonContentSpawnPoints.h"
#include "Engine/World.h"
#include "Items/InventoryItemDefinition.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "Prototype/JMPrototypePickupSpawner.h"
#include "TimerManager.h"

namespace
{
	struct FItemMarkerCandidate
	{
		TObjectPtr<AJMRoomModule> Room = nullptr;
		TObjectPtr<UJMDungeonItemSpawnPointComponent> Marker = nullptr;
	};

	struct FAIEntryCandidate
	{
		TObjectPtr<AJMRoomModule> Room = nullptr;
		TObjectPtr<UJMDungeonAIEntryPointComponent> Entry = nullptr;
	};

	template <typename CandidateType, typename WeightFunction>
	int32 PickWeightedIndex(const TArray<CandidateType>& Candidates, FRandomStream& Stream, WeightFunction GetWeight)
	{
		int32 TotalWeight = 0;
		for (const CandidateType& Candidate : Candidates)
		{
			TotalWeight += FMath::Max(1, GetWeight(Candidate));
		}
		if (TotalWeight <= 0)
		{
			return INDEX_NONE;
		}
		int32 Roll = Stream.RandRange(1, TotalWeight);
		for (int32 Index = 0; Index < Candidates.Num(); ++Index)
		{
			Roll -= FMath::Max(1, GetWeight(Candidates[Index]));
			if (Roll <= 0)
			{
				return Index;
			}
		}
		return Candidates.Num() - 1;
	}

	const FJMDungeonItemSpawnOption* PickItemOption(const UJMDungeonItemSpawnPointComponent& Marker, FRandomStream& Stream)
	{
		TArray<const FJMDungeonItemSpawnOption*> ValidOptions;
		int32 TotalWeight = 0;
		for (const FJMDungeonItemSpawnOption& Option : Marker.ItemOptions)
		{
			if (IsValid(Option.ItemDefinition) && Option.Weight > 0)
			{
				ValidOptions.Add(&Option);
				TotalWeight += Option.Weight;
			}
		}
		if (ValidOptions.IsEmpty() || TotalWeight <= 0)
		{
			return nullptr;
		}
		int32 Roll = Stream.RandRange(1, TotalWeight);
		for (const FJMDungeonItemSpawnOption* Option : ValidOptions)
		{
			Roll -= Option->Weight;
			if (Roll <= 0)
			{
				return Option;
			}
		}
		return ValidOptions.Last();
	}

	bool SpawnItemAtMarker(UWorld& World, AActor& Owner, UJMDungeonItemSpawnPointComponent& Marker, FRandomStream& Stream)
	{
		const FJMDungeonItemSpawnOption* Option = PickItemOption(Marker, Stream);
		if (!Option)
		{
			return false;
		}
		const FTransform SpawnTransform = Marker.GetComponentTransform();
		AJMPrototypePickupSpawner* Spawner = World.SpawnActorDeferred<AJMPrototypePickupSpawner>(
			AJMPrototypePickupSpawner::StaticClass(), SpawnTransform, &Owner, nullptr,
			ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
		if (!Spawner)
		{
			return false;
		}
		Spawner->ItemDefinition = Option->ItemDefinition;
		Spawner->Quantity = Stream.RandRange(FMath::Max(1, Option->MinQuantity), FMath::Max(Option->MinQuantity, Option->MaxQuantity));
		Spawner->PickupMesh = Option->PickupMesh;
		Spawner->PickupMeshScale = Option->PickupMeshScale;
		Spawner->PickupPrompt = Option->PickupPromptOverride.IsEmpty()
			? FText::Format(NSLOCTEXT("JMDungeonContent", "PickupPrompt", "Pick up {0}"), Option->ItemDefinition->DisplayName)
			: Option->PickupPromptOverride;
		UGameplayStatics::FinishSpawningActor(Spawner, SpawnTransform);
		return true;
	}
}

AJMPrototypeGeneratedDungeonDirector::AJMPrototypeGeneratedDungeonDirector()
{
	PrimaryActorTick.bCanEverTick = false;

	FJMDungeonMonsterSpawnRequest Listener;
	Listener.MonsterClass = AJMListenerMonster::StaticClass();
	Listener.ActivationDelay = 1.5f;
	MonsterRoster.Add(Listener);

	FJMDungeonMonsterSpawnRequest Hoarder;
	Hoarder.MonsterClass = AJMHoarderMonster::StaticClass();
	Hoarder.ActivationDelay = 2.0f;
	MonsterRoster.Add(Hoarder);

	FJMDungeonMonsterSpawnRequest Blackout;
	Blackout.MonsterClass = AJMBlackoutMonster::StaticClass();
	Blackout.ActivationDelay = 45.0f;
	MonsterRoster.Add(Blackout);
}

void AJMPrototypeGeneratedDungeonDirector::BeginPlay()
{
	Super::BeginPlay();
	TryPopulate();
	if (!bPopulated)
	{
		GetWorldTimerManager().SetTimer(PopulateTimer, this, &ThisClass::TryPopulate, 0.1f, true);
	}
}

void AJMPrototypeGeneratedDungeonDirector::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorldTimerManager().ClearTimer(PopulateTimer);
	GetWorldTimerManager().ClearTimer(ActivationTimer);
	PendingMonsterActivations.Reset();
	Super::EndPlay(EndPlayReason);
}

void AJMPrototypeGeneratedDungeonDirector::TryPopulate()
{
	if (PopulateGeneratedDungeon())
	{
		GetWorldTimerManager().ClearTimer(PopulateTimer);
	}
}

bool AJMPrototypeGeneratedDungeonDirector::PopulateGeneratedDungeon()
{
	if (bPopulated)
	{
		return true;
	}
	if (!GetWorld())
	{
		return false;
	}
	TArray<AJMRoomModule*> Rooms;
	int32 DungeonSeed = 0;
	if (!CollectValidatedRooms(Rooms, DungeonSeed))
	{
		return false;
	}

	FRandomStream ItemStream(DungeonSeed ^ 0x51A7E);
	FRandomStream AIStream(DungeonSeed ^ 0xA173D);
	const int32 ItemCount = PopulateItems(ItemStream, Rooms);
	if (UNavigationSystemV1* Navigation = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld()))
	{
		// Room modules are authored assets, but their instances are created during BeginPlay.
		// Force one complete build after all room collision has registered so authored AI
		// entry points can be projected on the generated dungeon instead of the editor floor.
		Navigation->Build();
		int32 ProjectedRoomCenters = 0;
		int32 ProjectedEntriesSmall = 0;
		int32 EntryCount = 0;
		for (const AJMRoomModule* Room : Rooms)
		{
			FNavLocation ProjectedLocation;
			ProjectedRoomCenters += Navigation->ProjectPointToNavigation(
				Room->GetActorLocation(), ProjectedLocation, FVector(500.0f, 500.0f, 500.0f)) ? 1 : 0;
			TArray<UJMDungeonAIEntryPointComponent*> Entries;
			Room->GetComponents(Entries);
			for (const UJMDungeonAIEntryPointComponent* Entry : Entries)
			{
				++EntryCount;
				ProjectedEntriesSmall += Navigation->ProjectPointToNavigation(
					Entry->GetComponentLocation(), ProjectedLocation, FVector(250.0f, 250.0f, 350.0f)) ? 1 : 0;
			}
		}
		UE_LOG(LogTemp, Display,
			TEXT("DUNGEON_CONTENT navigation rebuilt after runtime room generation nav_data=%s projected_room_centers=%d/%d projected_entries=%d/%d"),
			*GetNameSafe(Navigation->GetDefaultNavDataInstance(FNavigationSystem::DontCreate)),
			ProjectedRoomCenters, Rooms.Num(), ProjectedEntriesSmall, EntryCount);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("DUNGEON_CONTENT could not rebuild navigation: no navigation system"));
	}
	const int32 MonsterCount = PopulateMonsters(AIStream, Rooms);
	bPopulated = true;
	UE_LOG(LogTemp, Display, TEXT("DUNGEON_CONTENT populated seed=%d rooms=%d items=%d monsters=%d"),
		DungeonSeed, Rooms.Num(), ItemCount, MonsterCount);
	return true;
}

bool AJMPrototypeGeneratedDungeonDirector::CollectValidatedRooms(TArray<AJMRoomModule*>& OutRooms, int32& OutSeed) const
{
	const TArray<FJMGeneratedRoomRecord>* Records = nullptr;
	if (IsValid(MapGenerator))
	{
		if (MapGenerator->GeneratedRooms.Num() != 25 || !MapGenerator->ValidateGeneratedMap().bIsValid)
		{
			return false;
		}
		Records = &MapGenerator->GeneratedRooms;
		OutSeed = MapGenerator->RandomSeed;
	}
	else if (IsValid(CustomMapGenerator))
	{
		if (CustomMapGenerator->GeneratedRooms.IsEmpty() || !CustomMapGenerator->ValidateGeneratedMap().bIsValid)
		{
			return false;
		}
		Records = &CustomMapGenerator->GeneratedRooms;
		OutSeed = CustomMapGenerator->RandomSeed;
	}
	else
	{
		return false;
	}

	OutRooms.Reserve(Records->Num());
	for (const FJMGeneratedRoomRecord& Record : *Records)
	{
		if (IsValid(Record.RoomActor))
		{
			OutRooms.Add(Record.RoomActor);
		}
	}
	return OutRooms.Num() == Records->Num();
}

int32 AJMPrototypeGeneratedDungeonDirector::PopulateItems(FRandomStream& Stream, const TArray<AJMRoomModule*>& Rooms)
{
	TArray<FItemMarkerCandidate> DirectCandidates;
	TMap<FName, TArray<FItemMarkerCandidate>> UniqueGroups;
	for (AJMRoomModule* Room : Rooms)
	{
		TArray<UJMDungeonItemSpawnPointComponent*> Markers;
		Room->GetComponents(Markers);
		Markers.Sort([](const UJMDungeonItemSpawnPointComponent& A, const UJMDungeonItemSpawnPointComponent& B)
		{
			return A.SlotId.LexicalLess(B.SlotId);
		});
		for (UJMDungeonItemSpawnPointComponent* Marker : Markers)
		{
			if (!IsValid(Marker) || Marker->ItemOptions.IsEmpty())
			{
				continue;
			}
			FItemMarkerCandidate Candidate{Room, Marker};
			if (Marker->SelectionPolicy == EJMDungeonItemSelectionPolicy::UniqueGroup && !Marker->SelectionGroup.IsNone())
			{
				UniqueGroups.FindOrAdd(Marker->SelectionGroup).Add(Candidate);
			}
			else
			{
				DirectCandidates.Add(Candidate);
			}
		}
	}

	int32 SpawnedCount = 0;
	for (const FItemMarkerCandidate& Candidate : DirectCandidates)
	{
		const bool bShouldSpawn = Candidate.Marker->SelectionPolicy == EJMDungeonItemSelectionPolicy::Guaranteed ||
			Stream.FRand() <= Candidate.Marker->SpawnChance;
		if (bShouldSpawn && SpawnItemAtMarker(*GetWorld(), *this, *Candidate.Marker, Stream))
		{
			++SpawnedCount;
		}
	}

	TArray<FName> GroupNames;
	UniqueGroups.GetKeys(GroupNames);
	GroupNames.Sort(FNameLexicalLess());
	for (const FName GroupName : GroupNames)
	{
		TArray<FItemMarkerCandidate>& Candidates = UniqueGroups.FindChecked(GroupName);
		const int32 PickedIndex = PickWeightedIndex(Candidates, Stream,
			[](const FItemMarkerCandidate& Candidate) { return Candidate.Marker->MarkerWeight; });
		if (Candidates.IsValidIndex(PickedIndex) &&
			SpawnItemAtMarker(*GetWorld(), *this, *Candidates[PickedIndex].Marker, Stream))
		{
			++SpawnedCount;
		}
	}
	return SpawnedCount;
}

int32 AJMPrototypeGeneratedDungeonDirector::PopulateMonsters(FRandomStream& Stream, const TArray<AJMRoomModule*>& Rooms)
{
	TArray<FAIEntryCandidate> AllEntries;
	for (AJMRoomModule* Room : Rooms)
	{
		TArray<UJMDungeonAIEntryPointComponent*> Entries;
		Room->GetComponents(Entries);
		Entries.Sort([](const UJMDungeonAIEntryPointComponent& A, const UJMDungeonAIEntryPointComponent& B)
		{
			return A.EntryId.LexicalLess(B.EntryId);
		});
		for (UJMDungeonAIEntryPointComponent* Entry : Entries)
		{
			if (IsValid(Entry))
			{
				AllEntries.Add({Room, Entry});
			}
		}
	}

	TSet<TObjectPtr<AJMRoomModule>> UsedRooms;
	int32 SpawnedCount = 0;
	const double Now = GetWorld()->GetTimeSeconds();
	for (const FJMDungeonMonsterSpawnRequest& Request : MonsterRoster)
	{
		if (!Request.MonsterClass)
		{
			continue;
		}
		for (int32 SpawnIndex = 0; SpawnIndex < Request.Count; ++SpawnIndex)
		{
			TArray<FAIEntryCandidate> EligibleEntries;
			for (const FAIEntryCandidate& Candidate : AllEntries)
			{
				const bool bGroupMatches = Request.RequiredEntryGroup.IsNone() ||
					Candidate.Entry->EntryGroup == Request.RequiredEntryGroup;
				if (bGroupMatches && Candidate.Entry->AllowsMonsterClass(Request.MonsterClass) &&
					(!Request.bPreferUnusedRoom || !UsedRooms.Contains(Candidate.Room)))
				{
					EligibleEntries.Add(Candidate);
				}
			}
			if (EligibleEntries.IsEmpty() && Request.bPreferUnusedRoom)
			{
				for (const FAIEntryCandidate& Candidate : AllEntries)
				{
					const bool bGroupMatches = Request.RequiredEntryGroup.IsNone() ||
						Candidate.Entry->EntryGroup == Request.RequiredEntryGroup;
					if (bGroupMatches && Candidate.Entry->AllowsMonsterClass(Request.MonsterClass))
					{
						EligibleEntries.Add(Candidate);
					}
				}
			}
			const int32 EntryIndex = PickWeightedIndex(EligibleEntries, Stream,
				[](const FAIEntryCandidate& Candidate) { return Candidate.Entry->EntryWeight; });
			if (!EligibleEntries.IsValidIndex(EntryIndex))
			{
				UE_LOG(LogTemp, Warning, TEXT("DUNGEON_CONTENT no compatible AI entry for %s"), *GetNameSafe(Request.MonsterClass));
				continue;
			}

			const FAIEntryCandidate& Selected = EligibleEntries[EntryIndex];
			TArray<UJMDungeonAIRoutePointComponent*> RouteMarkers;
			Selected.Room->GetComponents(RouteMarkers);
			RouteMarkers.RemoveAll([&Selected](const UJMDungeonAIRoutePointComponent* Marker)
			{
				return !IsValid(Marker) || Marker->RouteGroup != Selected.Entry->RouteGroup;
			});
			RouteMarkers.Sort([](const UJMDungeonAIRoutePointComponent& A, const UJMDungeonAIRoutePointComponent& B)
			{
				return A.Order < B.Order;
			});

			FVector HomeLocation = Selected.Entry->GetComponentLocation();
			TArray<USceneComponent*> PatrolRoute;
			for (UJMDungeonAIRoutePointComponent* RouteMarker : RouteMarkers)
			{
				if (RouteMarker->Role == EJMDungeonAIRoutePointRole::Home)
				{
					HomeLocation = RouteMarker->GetComponentLocation();
				}
				else if (RouteMarker->Role == EJMDungeonAIRoutePointRole::Patrol)
				{
					PatrolRoute.Add(RouteMarker);
				}
			}

			const FTransform SpawnTransform = Selected.Entry->GetComponentTransform();
			AJMDungeonMonster* Monster = GetWorld()->SpawnActorDeferred<AJMDungeonMonster>(
				Request.MonsterClass, SpawnTransform, this, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
			if (!Monster)
			{
				continue;
			}
			Monster->ConfigureAuthoredRoute(PatrolRoute, HomeLocation);
			Monster->SetMonsterEnabled(false);
			if (AJMHoarderMonster* Hoarder = Cast<AJMHoarderMonster>(Monster))
			{
				Hoarder->SetTerritoryCenter(HomeLocation);
			}
			if (AJMBlackoutMonster* Blackout = Cast<AJMBlackoutMonster>(Monster))
			{
				Blackout->bStartsActive = false;
				Blackout->AutomaticActivationDelay = 0.0f;
			}
			UGameplayStatics::FinishSpawningActor(Monster, SpawnTransform);
			const double EarliestActivation = Now + FMath::Max(0.0f, Request.ActivationDelay);
			PendingMonsterActivations.Add({Monster, EarliestActivation,
				EarliestActivation + NavigationReadyTimeout});
			UsedRooms.Add(Selected.Room);
			++SpawnedCount;
		}
	}

	if (!PendingMonsterActivations.IsEmpty() && !GetWorldTimerManager().IsTimerActive(ActivationTimer))
	{
		GetWorldTimerManager().SetTimer(ActivationTimer, this, &ThisClass::UpdatePendingMonsterActivations, 0.25f, true);
	}
	return SpawnedCount;
}

void AJMPrototypeGeneratedDungeonDirector::UpdatePendingMonsterActivations()
{
	UNavigationSystemV1* Navigation = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	const double Now = GetWorld()->GetTimeSeconds();
	for (int32 Index = PendingMonsterActivations.Num() - 1; Index >= 0; --Index)
	{
		FPendingMonsterActivation& Pending = PendingMonsterActivations[Index];
		AJMDungeonMonster* Monster = Pending.Monster.Get();
		if (!IsValid(Monster))
		{
			PendingMonsterActivations.RemoveAtSwap(Index);
			continue;
		}
		if (Now < Pending.EarliestTime)
		{
			continue;
		}
		FNavLocation ProjectedLocation;
		if (Navigation && Navigation->ProjectPointToNavigation(Monster->GetActorLocation(), ProjectedLocation,
			FVector(250.0f, 250.0f, 350.0f)))
		{
			Monster->SetMonsterEnabled(true);
			PendingMonsterActivations.RemoveAtSwap(Index);
		}
		else if (Now >= Pending.Deadline)
		{
			UE_LOG(LogTemp, Warning, TEXT("DUNGEON_CONTENT kept %s dormant: navmesh was not ready at authored entry"),
				*GetNameSafe(Monster));
			PendingMonsterActivations.RemoveAtSwap(Index);
		}
	}
	if (PendingMonsterActivations.IsEmpty())
	{
		GetWorldTimerManager().ClearTimer(ActivationTimer);
	}
}
