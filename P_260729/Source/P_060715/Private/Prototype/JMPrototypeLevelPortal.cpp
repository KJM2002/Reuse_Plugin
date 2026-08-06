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
	OverlapArea->OnComponentBeginOverlap.AddDynamic(this, &AJMPrototypeLevelPortal::HandleOverlapBegin);

	PortalEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NS_Portal"));
	PortalEffect->SetupAttachment(OverlapArea);
	PortalEffect->SetAutoActivate(true);
}

void AJMPrototypeLevelPortal::BeginPlay()
{
	Super::BeginPlay();
	bTravelStarted = false;
	OverlapArea->SetGenerateOverlapEvents(true);
	// An overlap can happen while a newly spawned pawn is not possessed yet.
	// Recheck spatial containment after possession so that early overlap is not
	// permanently lost merely because IsPlayerControlled() was initially false.
	GetWorldTimerManager().SetTimer(OverlapRecheckHandle, this,
		&AJMPrototypeLevelPortal::RecheckPlayerInsidePortal, 0.1f, true);
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

void AJMPrototypeLevelPortal::HandleOverlapBegin(UPrimitiveComponent*, AActor* OtherActor,
	UPrimitiveComponent*, int32, bool, const FHitResult&)
{
	TryTravel(OtherActor);
}

void AJMPrototypeLevelPortal::TryTravel(AActor* OtherActor)
{
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
	if (Progression)
	{
		StateBeforeTravel = Progression->GetRunState();
		const FJMPrototypeOperationResult StateResult = Direction == EJMPrototypePortalDirection::EnterDungeon
			? Progression->EnterDungeon()
			: Progression->ReturnToBase();
		if (!StateResult.bSucceeded)
		{
			// Prototype travel is intentionally unconditional. Progression state can
			// enrich an accepted quest, but it must never prevent map traversal.
			UE_LOG(LogJMPrototypePortal, Display, TEXT("Portal %s continues without a progression transition: %s"), *GetName(), *StateResult.Message.ToString());
		}

		TArray<UInventoryItemDefinition*> RawTravelItems;
		RawTravelItems.Reserve(TravelItems.Num());
		for (UInventoryItemDefinition* Item : TravelItems)
		{
			RawTravelItems.Add(Item);
		}
		Progression->CaptureTravelInventory(JMPrototypeInventory::Resolve(Pawn), RawTravelItems);
		Progression->MarkLevelTravelPending();
	}
	bTravelStarted = true;
	OverlapArea->SetGenerateOverlapEvents(false);
	UE_LOG(LogJMPrototypePortal, Display, TEXT("Portal %s opening validated level %s."), *GetName(), *DestinationPackage.ToString());
	UGameplayStatics::OpenLevel(this, DestinationPackage);
	// Successful OpenLevel destroys this source actor. If it is still alive after
	// the grace period, the browse failed and all one-shot state must be restored.
	GetWorldTimerManager().SetTimer(TravelWatchdogHandle, this, &AJMPrototypeLevelPortal::HandleTravelWatchdog, 2.0f, false);
}

void AJMPrototypeLevelPortal::RecheckPlayerInsidePortal()
{
	if (bTravelStarted)
	{
		return;
	}
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	if (!PlayerPawn || !PlayerPawn->IsPlayerControlled())
	{
		return;
	}
	const float Radius = OverlapArea->GetScaledSphereRadius();
	if (FVector::DistSquared(PlayerPawn->GetActorLocation(), OverlapArea->GetComponentLocation()) <= FMath::Square(Radius))
	{
		TryTravel(PlayerPawn);
	}
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
