#include "Prototype/JMPrototypeLevelPortal.h"

#include "Components/InventoryComponent.h"
#include "Components/SphereComponent.h"
#include "Engine/GameInstance.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraComponent.h"
#include "Prototype/JMPrototypeInventoryResolver.h"
#include "Prototype/JMPrototypeProgressionSubsystem.h"

AJMPrototypeLevelPortal::AJMPrototypeLevelPortal()
{
	PrimaryActorTick.bCanEverTick = false;
	OverlapArea = CreateDefaultSubobject<USphereComponent>(TEXT("NSOverlapArea"));
	SetRootComponent(OverlapArea);
	OverlapArea->InitSphereRadius(190.0f);
	OverlapArea->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapArea->SetCollisionResponseToAllChannels(ECR_Ignore);
	OverlapArea->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	OverlapArea->SetGenerateOverlapEvents(true);

	PortalEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NS_Portal"));
	PortalEffect->SetupAttachment(OverlapArea);
	PortalEffect->SetAutoActivate(true);
}

void AJMPrototypeLevelPortal::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	APawn* Pawn = Cast<APawn>(OtherActor);
	if (bTravelStarted || DestinationLevel.IsNone() || !Pawn || !Pawn->IsPlayerControlled())
	{
		return;
	}

	UJMPrototypeProgressionSubsystem* Progression = GetGameInstance()
		? GetGameInstance()->GetSubsystem<UJMPrototypeProgressionSubsystem>() : nullptr;
	if (!Progression)
	{
		return;
	}
	const FJMPrototypeOperationResult StateResult = Direction == EJMPrototypePortalDirection::EnterDungeon
		? Progression->EnterDungeon()
		: Progression->ReturnToBase();
	if (!StateResult.bSucceeded)
	{
		return;
	}

	TArray<UInventoryItemDefinition*> RawTravelItems;
	RawTravelItems.Reserve(TravelItems.Num());
	for (UInventoryItemDefinition* Item : TravelItems)
	{
		RawTravelItems.Add(Item);
	}
	Progression->CaptureTravelInventory(JMPrototypeInventory::Resolve(Pawn), RawTravelItems);
	bTravelStarted = true;
	OverlapArea->SetGenerateOverlapEvents(false);
	UGameplayStatics::OpenLevel(this, DestinationLevel);
}
