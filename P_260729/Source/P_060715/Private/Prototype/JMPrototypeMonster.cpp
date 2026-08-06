#include "Prototype/JMPrototypeMonster.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Prototype/JMPrototypeRunResetComponent.h"
#include "TimerManager.h"

AJMPrototypeMonsterAIController::AJMPrototypeMonsterAIController()
{
	MonsterPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("MonsterPerception"));
	SetPerceptionComponent(*MonsterPerception);
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	SightConfig->SightRadius = 1400.0f;
	SightConfig->LoseSightRadius = 1600.0f;
	SightConfig->PeripheralVisionAngleDegrees = 55.0f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	MonsterPerception->ConfigureSense(*SightConfig);
	MonsterPerception->SetDominantSense(SightConfig->GetSenseImplementation());
}

void AJMPrototypeMonsterAIController::BeginPlay()
{
	Super::BeginPlay();
	MonsterPerception->OnTargetPerceptionUpdated.AddUniqueDynamic(this, &AJMPrototypeMonsterAIController::HandleTargetPerceptionUpdated);
}

void AJMPrototypeMonsterAIController::HandleTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	APawn* SeenPawn = Cast<APawn>(Actor);
	if (!Stimulus.WasSuccessfullySensed() || !SeenPawn || !SeenPawn->IsPlayerControlled())
	{
		return;
	}
	if (AJMPrototypeMonster* Monster = Cast<AJMPrototypeMonster>(GetPawn()))
	{
		Monster->NotifyPlayerSeen(SeenPawn);
	}
}

bool AJMPrototypeMonsterAIController::IsTargetCurrentlySensed(AActor* Target) const
{
	if (!IsValid(Target) || !MonsterPerception)
	{
		return false;
	}
	FActorPerceptionBlueprintInfo PerceptionInfo;
	if (!MonsterPerception->GetActorsPerception(Target, PerceptionInfo))
	{
		return false;
	}
	for (const FAIStimulus& Stimulus : PerceptionInfo.LastSensedStimuli)
	{
		if (Stimulus.WasSuccessfullySensed())
		{
			return true;
		}
	}
	return false;
}

AJMPrototypeMonster::AJMPrototypeMonster()
{
	PrimaryActorTick.bCanEverTick = false;
	AIControllerClass = AJMPrototypeMonsterAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	PrototypeVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PrototypeVisual"));
	PrototypeVisual->SetupAttachment(GetRootComponent());
	PrototypeVisual->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AJMPrototypeMonster::BeginPlay()
{
	Super::BeginPlay();
	SpawnLocation = GetActorLocation();
	SpawnRotation = GetActorRotation();
	GetWorldTimerManager().SetTimer(MovementTimer, this, &AJMPrototypeMonster::UpdateMovement, 0.2f, true);
}

void AJMPrototypeMonster::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorldTimerManager().ClearTimer(MovementTimer);
	Super::EndPlay(EndPlayReason);
}

void AJMPrototypeMonster::NotifyPlayerSeen(APawn* SeenPawn)
{
	if (!IsValid(SeenPawn) || !SeenPawn->IsPlayerControlled())
	{
		return;
	}
	ChaseTarget = SeenPawn;
	LastSeenTime = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0;
	GetCharacterMovement()->MaxWalkSpeed = ChaseSpeed;
}

void AJMPrototypeMonster::UpdateMovement()
{
	AJMPrototypeMonsterAIController* MonsterController = Cast<AJMPrototypeMonsterAIController>(GetController());
	if (!MonsterController)
	{
		return;
	}

	if (APawn* Target = ChaseTarget.Get())
	{
		if (MonsterController->IsTargetCurrentlySensed(Target))
		{
			LastSeenTime = GetWorld() ? GetWorld()->GetTimeSeconds() : LastSeenTime;
		}
		if (FVector::DistSquared(GetActorLocation(), Target->GetActorLocation()) <= FMath::Square(CatchDistance))
		{
			OnPlayerCaught.Broadcast(Target);
			if (UJMPrototypeRunResetComponent* Reset = Target->FindComponentByClass<UJMPrototypeRunResetComponent>())
			{
				Reset->FailCurrentRun();
			}
			ResetMonster();
			return;
		}

		const double CurrentTime = GetWorld() ? GetWorld()->GetTimeSeconds() : LastSeenTime;
		if (CurrentTime - LastSeenTime > LoseSightDelay)
		{
			ClearChase();
		}
		else
		{
			MonsterController->MoveToActor(Target, CatchDistance * 0.8f, true, true, true, nullptr, true);
			return;
		}
	}

	GetCharacterMovement()->MaxWalkSpeed = PatrolSpeed;
	if (PatrolPoints.IsEmpty())
	{
		MonsterController->StopMovement();
		return;
	}

	if (!PatrolPoints.IsValidIndex(PatrolIndex) || !IsValid(PatrolPoints[PatrolIndex])
		|| FVector::DistSquared(GetActorLocation(), PatrolPoints[PatrolIndex]->GetActorLocation()) < FMath::Square(100.0f))
	{
		for (int32 Attempts = 0; Attempts < PatrolPoints.Num(); ++Attempts)
		{
			PatrolIndex = (PatrolIndex + 1) % PatrolPoints.Num();
			if (IsValid(PatrolPoints[PatrolIndex]))
			{
				break;
			}
		}
	}
	if (PatrolPoints.IsValidIndex(PatrolIndex) && IsValid(PatrolPoints[PatrolIndex]))
	{
		MonsterController->MoveToActor(PatrolPoints[PatrolIndex], 75.0f, true, true, true, nullptr, true);
	}
}

void AJMPrototypeMonster::ClearChase()
{
	ChaseTarget.Reset();
	LastSeenTime = -1.0;
}

void AJMPrototypeMonster::ResetMonster()
{
	ClearChase();
	PatrolIndex = INDEX_NONE;
	if (AAIController* MonsterController = Cast<AAIController>(GetController()))
	{
		MonsterController->StopMovement();
	}
	TeleportTo(SpawnLocation, SpawnRotation, false, true);
}
