#include "World/InventoryContainerActor.h"

#include "Components/InventoryContainerComponent.h"
#include "Components/InventoryUIComponent.h"
#include "Components/JMInteractableComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Pawn.h"

AInventoryContainerActor::AInventoryContainerActor()
{
	PrimaryActorTick.bCanEverTick = false;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(SceneRoot);
	Mesh->SetCollisionProfileName(TEXT("BlockAllDynamic"));
	Container = CreateDefaultSubobject<UInventoryContainerComponent>(TEXT("InventoryContainer"));
	Interaction = CreateDefaultSubobject<UJMInteractableComponent>(TEXT("Interaction"));
	Interaction->InteractionPrompt = NSLOCTEXT("JMInventory", "OpenContainerPrompt", "Open");
	Interaction->OnInteracted.AddDynamic(this, &AInventoryContainerActor::HandleInteracted);
}

void AInventoryContainerActor::HandleInteracted(const FJMInteractionContext& Context)
{
	OpenFor(Context.InstigatorActor);
}

bool AInventoryContainerActor::OpenFor(AActor* InteractingActor)
{
	for (AActor* Candidate = InteractingActor; IsValid(Candidate); Candidate = Candidate->GetOwner())
	{
		if (UInventoryUIComponent* UI = Candidate->FindComponentByClass<UInventoryUIComponent>())
		{
			return UI->OpenContainer(Container);
		}
		if (const APawn* Pawn = Cast<APawn>(Candidate))
		{
			if (AController* Controller = Pawn->GetController())
			{
				if (UInventoryUIComponent* UI = Controller->FindComponentByClass<UInventoryUIComponent>())
				{
					return UI->OpenContainer(Container);
				}
			}
		}
	}
	return false;
}
