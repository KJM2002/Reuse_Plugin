#include "AI/Hoarder/JMHoarderMonster.h"

#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

AJMHoarderMonster::AJMHoarderMonster()
{
	BehaviorTreeAsset = TSoftObjectPtr<UBehaviorTree>(FSoftObjectPath(TEXT("/Game/AI/Hoarder/BT_Hoarder.BT_Hoarder")));
	PatrolSpeed = 315.0f;
	InvestigateSpeed = 380.0f;
	ChaseSpeed = 620.0f;
	MinimumNoiseLoudness = 0.55f;
	AlertDelay = 1.25f;
	AttackWarningDuration = 1.35f;
	LoseTargetDelay = 2.5f;
	SearchDuration = 4.5f;
	AlertSoundPitch = 0.5f;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	AddBlockoutPart(Body, TEXT("/Engine/BasicShapes/Cube.Cube"), FVector(0, 0, 5),
		FRotator::ZeroRotator, FVector(1.15f, 0.8f, 0.8f));
	Shell = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Shell"));
	AddBlockoutPart(Shell, TEXT("/Engine/BasicShapes/Sphere.Sphere"), FVector(-15, 0, 65),
		FRotator::ZeroRotator, FVector(0.9f, 0.75f, 0.45f));
	GuardBar = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GuardBar"));
	AddBlockoutPart(GuardBar, TEXT("/Engine/BasicShapes/Cube.Cube"), FVector(55, 0, 35),
		FRotator(0, 0, 35), FVector(0.75f, 0.16f, 0.16f));
}

void AJMHoarderMonster::BeginPlay()
{
	Super::BeginPlay();
	if (!bTerritoryInitialized)
	{
		TerritoryCenter = GetActorLocation();
		bTerritoryInitialized = true;
	}
}

void AJMHoarderMonster::SetTerritoryCenter(FVector NewCenter)
{
	TerritoryCenter = NewCenter;
	bTerritoryInitialized = true;
}

void AJMHoarderMonster::NotifyProtectedObjectDisturbed(AActor* InstigatorActor)
{
	APawn* Pawn = Cast<APawn>(InstigatorActor);
	if (Pawn && Pawn->IsPlayerControlled() && CanPursueTarget(Pawn))
	{
		BeginChase(Pawn, Pawn->GetActorLocation());
	}
}

void AJMHoarderMonster::UpdateSpecialRules()
{
	APlayerController* PC = GetWorld() ? GetWorld()->GetFirstPlayerController() : nullptr;
	APawn* Player = PC ? PC->GetPawn() : nullptr;
	if (!Player || IsTargetHidden(Player))
	{
		return;
	}
	const float Distance = FVector::Dist2D(Player->GetActorLocation(), TerritoryCenter);
	if ((GetMonsterState() == EJMDungeonMonsterState::Chase ||
		GetMonsterState() == EJMDungeonMonsterState::AttackWarning) && Distance > WarningRadius + LeashExtraDistance)
	{
		ClearTargetAndReturn();
		return;
	}
	if ((GetMonsterState() == EJMDungeonMonsterState::Patrol || GetMonsterState() == EJMDungeonMonsterState::Return) &&
		Distance <= AggressionRadius)
	{
		BeginSuspicion(Player, Player->GetActorLocation());
	}
}

bool AJMHoarderMonster::CanPursueTarget(const APawn* Target) const
{
	return Super::CanPursueTarget(Target) &&
		FVector::Dist2D(Target->GetActorLocation(), TerritoryCenter) <= WarningRadius + LeashExtraDistance;
}

FVector AJMHoarderMonster::GetReturnLocation() const
{
	return TerritoryCenter;
}
