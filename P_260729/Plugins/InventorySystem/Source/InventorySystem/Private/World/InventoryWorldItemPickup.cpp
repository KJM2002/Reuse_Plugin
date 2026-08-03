#include "World/InventoryWorldItemPickup.h"

#include "Components/InventoryComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "Interfaces/InventoryProviderInterface.h"
#include "Items/InventoryItemDefinition.h"

AInventoryWorldItemPickup::AInventoryWorldItemPickup()
{
	PrimaryActorTick.bCanEverTick = false;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	ItemMesh->SetupAttachment(SceneRoot);
	ItemMesh->SetCollisionProfileName(TEXT("BlockAllDynamic"));
	PickupInteractionPrompt = NSLOCTEXT("JMInventory", "PickupPrompt", "E키를 눌러 획득");
}

void AInventoryWorldItemPickup::BeginPlay()
{
	Super::BeginPlay();
	RefreshMesh();
}

void AInventoryWorldItemPickup::InitializePickup(UInventoryItemDefinition* InItemDefinition, int32 InQuantity)
{
	ItemDefinition = InItemDefinition;
	Quantity = FMath::Max(1, InQuantity);
	RefreshMesh();
	if (bSnapToGroundWhenDropped)
	{
		SnapToGround();
	}
	OnPickupStateChanged();
}

bool AInventoryWorldItemPickup::SnapToGround()
{
	UWorld* World = GetWorld();
	if (!World || !ItemMesh)
	{
		return false;
	}

	const FVector ActorLocation = GetActorLocation();
	const FVector TraceStart = ActorLocation + FVector::UpVector * 150.0f;
	const FVector TraceEnd = ActorLocation - FVector::UpVector * 600.0f;
	FCollisionQueryParams Params(SCENE_QUERY_STAT(InventoryPickupGroundSnap), false, this);
	Params.AddIgnoredActor(this);
	if (AActor* PickupOwner = GetOwner())
	{
		Params.AddIgnoredActor(PickupOwner);
	}

	FHitResult Hit;
	if (!World->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, ECC_Visibility, Params))
	{
		return false;
	}

	ItemMesh->UpdateBounds();
	const float MeshBottomZ = ItemMesh->Bounds.Origin.Z - ItemMesh->Bounds.BoxExtent.Z;
	FVector SnappedLocation = ActorLocation;
	SnappedLocation.Z += Hit.ImpactPoint.Z + FMath::Max(0.0f, GroundClearance) - MeshBottomZ;
	SetActorLocation(SnappedLocation, false, nullptr, ETeleportType::TeleportPhysics);
	return true;
}

bool AInventoryWorldItemPickup::CanInteract_Implementation(const FJMInteractionContext& Context) const
{
	return IsValid(ItemDefinition) && Quantity > 0 && IsValid(ResolveInventory(Context.InstigatorActor));
}

FJMInteractionResult AInventoryWorldItemPickup::BeginInteract_Implementation(const FJMInteractionContext& Context)
{
	return CanInteract_Implementation(Context)
		? FJMInteractionResult::Success()
		: FJMInteractionResult::Failure(EJMInteractionResultCode::NotAllowed, NSLOCTEXT("JMInventory", "PickupUnavailable", "이 아이템을 획득할 수 없습니다."));
}

FJMInteractionResult AInventoryWorldItemPickup::CompleteInteract_Implementation(const FJMInteractionContext& Context)
{
	return TryPickup(Context.InstigatorActor)
		? FJMInteractionResult::Success(NSLOCTEXT("JMInventory", "PickupSucceeded", "아이템을 획득했습니다."))
		: FJMInteractionResult::Failure(EJMInteractionResultCode::Failed, NSLOCTEXT("JMInventory", "PickupFailed", "인벤토리에 아이템을 추가하지 못했습니다."));
}

void AInventoryWorldItemPickup::CancelInteract_Implementation(const FJMInteractionContext& Context)
{
}

FJMInteractionPrompt AInventoryWorldItemPickup::GetInteractionPrompt_Implementation(const FJMInteractionContext& Context) const
{
	FJMInteractionPrompt Prompt;
	Prompt.DisplayText = PickupInteractionPrompt;
	Prompt.Priority = PickupInteractionPriority;
	Prompt.bVisible = CanInteract_Implementation(Context);
	return Prompt;
}

float AInventoryWorldItemPickup::GetInteractionDuration_Implementation(const FJMInteractionContext& Context) const
{
	return 0.0f;
}

int32 AInventoryWorldItemPickup::GetInteractionPriority_Implementation(const FJMInteractionContext& Context) const
{
	return PickupInteractionPriority;
}

bool AInventoryWorldItemPickup::TryPickup(AActor* InteractingActor)
{
	if (!IsValid(ItemDefinition) || Quantity <= 0)
	{
		return false;
	}

	UInventoryComponent* Inventory = ResolveInventory(InteractingActor);
	if (!IsValid(Inventory))
	{
		return false;
	}

	const FInventoryAddOutcome Outcome = Inventory->AddItemDetailed(ItemDefinition, Quantity);
	if (!Outcome.AddedAnything())
	{
		return false;
	}

	Quantity -= Outcome.AddedQuantity;
	if (Quantity <= 0)
	{
		Destroy();
	}
	else
	{
		OnPickupStateChanged();
	}
	return true;
}

void AInventoryWorldItemPickup::OnPickupStateChanged_Implementation()
{
}

UInventoryComponent* AInventoryWorldItemPickup::ResolveInventory(AActor* InteractingActor) const
{
	for (AActor* Candidate = InteractingActor; IsValid(Candidate); Candidate = Candidate->GetOwner())
	{
		if (Candidate->GetClass()->ImplementsInterface(UInventoryProviderInterface::StaticClass()))
		{
			if (UInventoryComponent* Provided = IInventoryProviderInterface::Execute_GetInventoryComponent(Candidate))
			{
				return Provided;
			}
		}
		if (UInventoryComponent* Found = Candidate->FindComponentByClass<UInventoryComponent>())
		{
			return Found;
		}
	}
	return nullptr;
}

void AInventoryWorldItemPickup::RefreshMesh()
{
	if (!ItemMesh || !IsValid(ItemDefinition) || ItemDefinition->InspectMesh.IsNull())
	{
		return;
	}
	if (UStaticMesh* Mesh = ItemDefinition->InspectMesh.LoadSynchronous())
	{
		ItemMesh->SetStaticMesh(Mesh);
	}
}
