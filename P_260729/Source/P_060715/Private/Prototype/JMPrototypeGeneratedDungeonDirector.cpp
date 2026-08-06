#include "Prototype/JMPrototypeGeneratedDungeonDirector.h"

#include "Actors/JMGridMapGenerator.h"
#include "Actors/JMRoomModule.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/TargetPoint.h"
#include "Engine/World.h"
#include "Items/InventoryItemDefinition.h"
#include "Prototype/JMPrototypeMonster.h"
#include "Prototype/JMPrototypePickupSpawner.h"
#include "TimerManager.h"

AJMPrototypeGeneratedDungeonDirector::AJMPrototypeGeneratedDungeonDirector()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AJMPrototypeGeneratedDungeonDirector::BeginPlay()
{
	Super::BeginPlay();
	TryPopulate();
	if (!bPopulated)
	{
		GetWorldTimerManager().SetTimer(PopulateTimer, this, &AJMPrototypeGeneratedDungeonDirector::TryPopulate, 0.1f, true);
	}
}

void AJMPrototypeGeneratedDungeonDirector::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorldTimerManager().ClearTimer(PopulateTimer);
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
	if (!IsValid(MapGenerator) || MapGenerator->GeneratedRooms.Num() != 25 || !GetWorld())
	{
		return false;
	}

	TArray<AJMRoomModule*> CandidateRooms;
	for (const FJMGeneratedRoomRecord& Record : MapGenerator->GeneratedRooms)
	{
		const bool bEntranceOrExit = Record.Coordinate.X == 2 && (Record.Coordinate.Y == 0 || Record.Coordinate.Y == 4);
		if (IsValid(Record.RoomActor) && !bEntranceOrExit)
		{
			CandidateRooms.Add(Record.RoomActor);
		}
	}
	if (CandidateRooms.Num() < 12)
	{
		return false;
	}

	FRandomStream Stream(MapGenerator->RandomSeed ^ 0x51A7E);
	for (int32 Index = CandidateRooms.Num() - 1; Index > 0; --Index)
	{
		CandidateRooms.Swap(Index, Stream.RandRange(0, Index));
	}

	struct FPickupSpec
	{
		UInventoryItemDefinition* Item;
		UStaticMesh* Mesh;
		FVector Scale;
	};
	const TArray<FPickupSpec> Pickups = {
		{ SlimeSample, SampleMesh, FVector(0.35f) }, { SlimeSample, SampleMesh, FVector(0.35f) },
		{ SlimeSample, SampleMesh, FVector(0.35f) }, { SlimeSample, SampleMesh, FVector(0.35f) },
		{ SlimeSample, SampleMesh, FVector(0.35f) }, { SlimeSample, SampleMesh, FVector(0.35f) },
		{ SlimeSac, SacMesh, FVector(0.35f, 0.35f, 0.55f) }, { SlimeSac, SacMesh, FVector(0.35f, 0.35f, 0.55f) },
		{ Scrap, ScrapMesh, FVector(0.35f, 0.35f, 0.2f) }, { Scrap, ScrapMesh, FVector(0.35f, 0.35f, 0.2f) },
		{ EmergencyBattery, BatteryMesh, FVector(0.25f, 0.25f, 0.55f) }
	};

	for (int32 Index = 0; Index < Pickups.Num(); ++Index)
	{
		const FPickupSpec& Spec = Pickups[Index];
		if (!IsValid(Spec.Item))
		{
			continue;
		}
		USceneComponent* SpawnRoot = CandidateRooms[Index]->ItemSpawnRoot;
		const FVector Location = (SpawnRoot ? SpawnRoot->GetComponentLocation() : CandidateRooms[Index]->GetActorLocation()) + FVector(0.0f, 0.0f, 80.0f);
		AJMPrototypePickupSpawner* Spawner = GetWorld()->SpawnActor<AJMPrototypePickupSpawner>(Location, FRotator::ZeroRotator);
		if (Spawner)
		{
			Spawner->ItemDefinition = Spec.Item;
			Spawner->PickupMesh = Spec.Mesh;
			Spawner->PickupMeshScale = Spec.Scale;
			Spawner->PickupPrompt = FText::Format(NSLOCTEXT("JMPrototype", "PickupPrompt", "Pick up {0}"), Spec.Item->DisplayName);
			Spawner->ReplenishPickup();
		}
	}

	TArray<TObjectPtr<AActor>> PatrolPoints;
	for (int32 Index = 12; Index < 16; ++Index)
	{
		USceneComponent* SpawnRoot = CandidateRooms[Index]->AISpawnRoot;
		const FVector Location = (SpawnRoot ? SpawnRoot->GetComponentLocation() : CandidateRooms[Index]->GetActorLocation()) + FVector(0.0f, 0.0f, 100.0f);
		if (ATargetPoint* Point = GetWorld()->SpawnActor<ATargetPoint>(Location, FRotator::ZeroRotator))
		{
			PatrolPoints.Add(Point);
		}
	}
	if (!PatrolPoints.IsEmpty())
	{
		AJMPrototypeMonster* Monster = GetWorld()->SpawnActor<AJMPrototypeMonster>(PatrolPoints[0]->GetActorLocation(), FRotator::ZeroRotator);
		if (Monster)
		{
			Monster->PatrolPoints = PatrolPoints;
			Monster->PrototypeVisual->SetStaticMesh(MonsterMesh);
			Monster->PrototypeVisual->SetRelativeScale3D(FVector(1.2f));
		}
	}

	bPopulated = true;
	UE_LOG(LogTemp, Display, TEXT("PROTO_GENERATED_DUNGEON populated seed=%d rooms=%d pickups=%d patrol_points=%d"),
		MapGenerator->RandomSeed, MapGenerator->GeneratedRooms.Num(), Pickups.Num(), PatrolPoints.Num());
	return true;
}
