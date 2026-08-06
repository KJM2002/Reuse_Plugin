#include "Prototype/JMPrototypePickupSpawner.h"

#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Items/InventoryItemDefinition.h"
#include "Prototype/JMPrototypeProgressionSubsystem.h"
#include "World/InventoryWorldItemPickup.h"

AJMPrototypePickupSpawner::AJMPrototypePickupSpawner()
{
	PrimaryActorTick.bCanEverTick = false;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
}

void AJMPrototypePickupSpawner::BeginPlay()
{
	Super::BeginPlay();
	if (UGameInstance* GameInstance = GetGameInstance())
	{
		if (UJMPrototypeProgressionSubsystem* Progression = GameInstance->GetSubsystem<UJMPrototypeProgressionSubsystem>())
		{
			Progression->OnRunStateChanged.AddUniqueDynamic(this, &AJMPrototypePickupSpawner::HandleRunStateChanged);
		}
	}
	ReplenishPickup();
}

void AJMPrototypePickupSpawner::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (UGameInstance* GameInstance = GetGameInstance())
	{
		if (UJMPrototypeProgressionSubsystem* Progression = GameInstance->GetSubsystem<UJMPrototypeProgressionSubsystem>())
		{
			Progression->OnRunStateChanged.RemoveDynamic(this, &AJMPrototypePickupSpawner::HandleRunStateChanged);
		}
	}
	SpawnedPickup = nullptr;
	Super::EndPlay(EndPlayReason);
}

void AJMPrototypePickupSpawner::HandleRunStateChanged(EJMPrototypeRunState, EJMPrototypeRunState NewState)
{
	if (NewState == EJMPrototypeRunState::QuestAccepted)
	{
		ReplenishPickup();
	}
}

AInventoryWorldItemPickup* AJMPrototypePickupSpawner::ReplenishPickup()
{
	if (IsValid(SpawnedPickup) || !IsValid(ItemDefinition) || Quantity <= 0 || !GetWorld())
	{
		return SpawnedPickup;
	}

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = this;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnedPickup = GetWorld()->SpawnActor<AInventoryWorldItemPickup>(AInventoryWorldItemPickup::StaticClass(), GetActorTransform(), SpawnParameters);
	if (!SpawnedPickup)
	{
		return nullptr;
	}

	SpawnedPickup->InitializePickup(ItemDefinition, Quantity);
	SpawnedPickup->PickupInteractionPrompt = PickupPrompt;
	if (SpawnedPickup->ItemMesh)
	{
		SpawnedPickup->ItemMesh->SetStaticMesh(PickupMesh);
		SpawnedPickup->ItemMesh->SetRelativeScale3D(PickupMeshScale);
	}
	return SpawnedPickup;
}
