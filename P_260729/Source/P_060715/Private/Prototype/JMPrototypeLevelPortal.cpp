#include "Prototype/JMPrototypeLevelPortal.h"

#include "Components/InventoryComponent.h"
#include "Components/SphereComponent.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/PackageName.h"
#include "NiagaraComponent.h"
#include "Prototype/JMPrototypeInventoryResolver.h"
#include "Prototype/JMPrototypeProgressionSubsystem.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogJMPrototypePortal, Log, All);

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

void AJMPrototypeLevelPortal::BeginPlay()
{
	Super::BeginPlay();
	bTravelStarted = false;
	OverlapArea->SetGenerateOverlapEvents(true);
}

bool AJMPrototypeLevelPortal::ResolveDestinationPackage(FName& OutPackageName) const
{
	FString PackageName;
	if (!DestinationWorld.IsNull())
	{
		PackageName = DestinationWorld.ToSoftObjectPath().GetLongPackageName();
	}
	else if (!DestinationLevel.IsNone())
	{
		const FString LegacyName = DestinationLevel.ToString();
		if (FPackageName::IsValidLongPackageName(LegacyName))
		{
			PackageName = LegacyName;
		}
		else if (!FPackageName::SearchForPackageOnDisk(LegacyName, &PackageName))
		{
			return false;
		}
	}
	if (PackageName.IsEmpty() || !FPackageName::DoesPackageExist(PackageName))
	{
		return false;
	}
	OutPackageName = FName(*PackageName);
	return true;
}

void AJMPrototypeLevelPortal::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	APawn* Pawn = Cast<APawn>(OtherActor);
	if (bTravelStarted || !Pawn || !Pawn->IsPlayerControlled())
	{
		return;
	}
	FName DestinationPackage;
	if (!ResolveDestinationPackage(DestinationPackage))
	{
		UE_LOG(LogJMPrototypePortal, Error, TEXT("Portal %s has no valid destination world."), *GetName());
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
		UE_LOG(LogJMPrototypePortal, Warning, TEXT("Portal %s rejected travel: %s"), *GetName(), *StateResult.Message.ToString());
		return;
	}
	StateBeforeTravel = Direction == EJMPrototypePortalDirection::EnterDungeon
		? EJMPrototypeRunState::QuestAccepted
		: EJMPrototypeRunState::Exploring;

	TArray<UInventoryItemDefinition*> RawTravelItems;
	RawTravelItems.Reserve(TravelItems.Num());
	for (UInventoryItemDefinition* Item : TravelItems)
	{
		RawTravelItems.Add(Item);
	}
	Progression->CaptureTravelInventory(JMPrototypeInventory::Resolve(Pawn), RawTravelItems);
	Progression->MarkLevelTravelPending();
	bTravelStarted = true;
	OverlapArea->SetGenerateOverlapEvents(false);
	UE_LOG(LogJMPrototypePortal, Display, TEXT("Portal %s opening validated level %s."), *GetName(), *DestinationPackage.ToString());
	UGameplayStatics::OpenLevel(this, DestinationPackage);
	// Successful OpenLevel destroys this source actor. If it is still alive after
	// the grace period, the browse failed and all one-shot state must be restored.
	GetWorldTimerManager().SetTimer(TravelWatchdogHandle, this, &AJMPrototypeLevelPortal::HandleTravelWatchdog, 2.0f, false);
}

void AJMPrototypeLevelPortal::HandleTravelWatchdog()
{
	if (!bTravelStarted)
	{
		return;
	}
	if (UJMPrototypeProgressionSubsystem* Progression = GetGameInstance()
		? GetGameInstance()->GetSubsystem<UJMPrototypeProgressionSubsystem>() : nullptr)
	{
		Progression->CancelPendingLevelTravel(StateBeforeTravel);
	}
	bTravelStarted = false;
	OverlapArea->SetGenerateOverlapEvents(true);
	UE_LOG(LogJMPrototypePortal, Error, TEXT("Portal %s travel did not leave the source world; state and overlap were restored."), *GetName());
}
