#include "Prototype/JMPrototypeLevelPortal.h"

#include "Components/SphereComponent.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraComponent.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogJMPrototypePortal, Log, All);

AJMPrototypeLevelPortal::AJMPrototypeLevelPortal()
{
	PrimaryActorTick.bCanEverTick = false;

	OverlapArea = CreateDefaultSubobject<USphereComponent>(TEXT("NSOverlapArea"));
	SetRootComponent(OverlapArea);
	OverlapArea->InitSphereRadius(240.0f);
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
	GetWorldTimerManager().SetTimer(RecheckTimerHandle, this,
		&AJMPrototypeLevelPortal::RecheckPlayerInsidePortal, 0.1f, true);
}

void AJMPrototypeLevelPortal::HandleOverlapBegin(UPrimitiveComponent*, AActor* OtherActor,
	UPrimitiveComponent*, int32, bool, const FHitResult&)
{
	if (bTravelStarted || !Cast<APawn>(OtherActor))
	{
		return;
	}
	if (DestinationWorld.IsNull())
	{
		UE_LOG(LogJMPrototypePortal, Error, TEXT("Portal %s has no DestinationWorld."), *GetName());
		return;
	}

	bTravelStarted = true;
	OverlapArea->SetGenerateOverlapEvents(false);
	UE_LOG(LogJMPrototypePortal, Display, TEXT("Portal %s opening %s."),
		*GetName(), *DestinationWorld.ToSoftObjectPath().GetLongPackageName());
	UGameplayStatics::OpenLevelBySoftObjectPtr(this, DestinationWorld);
}

void AJMPrototypeLevelPortal::RecheckPlayerInsidePortal()
{
	if (bTravelStarted)
	{
		return;
	}
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	if (!PlayerPawn)
	{
		return;
	}
	const float Radius = OverlapArea->GetScaledSphereRadius();
	if (FVector::DistSquared(PlayerPawn->GetActorLocation(), OverlapArea->GetComponentLocation()) <= FMath::Square(Radius))
	{
		HandleOverlapBegin(OverlapArea, PlayerPawn, nullptr, 0, false, FHitResult());
	}
}
