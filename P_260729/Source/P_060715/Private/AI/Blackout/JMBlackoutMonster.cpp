#include "AI/Blackout/JMBlackoutMonster.h"

#include "AI/Blackout/JMBlackoutLightZone.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"

AJMBlackoutMonster::AJMBlackoutMonster()
{
	BehaviorTreeAsset = TSoftObjectPtr<UBehaviorTree>(FSoftObjectPath(TEXT("/Game/AI/Blackout/BT_Blackout.BT_Blackout")));
	PatrolSpeed = 335.0f;
	InvestigateSpeed = 430.0f;
	ChaseSpeed = 640.0f;
	AlertDelay = 1.4f;
	AttackWarningDuration = 1.5f;
	LoseTargetDelay = 1.8f;
	SearchDuration = 6.0f;
	MinimumNoiseLoudness = 0.30f;
	AlertSoundPitch = 0.35f;

	Core = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Core"));
	AddBlockoutPart(Core, TEXT("/Engine/BasicShapes/Sphere.Sphere"), FVector(0, 0, 70),
		FRotator::ZeroRotator, FVector(0.42f, 0.42f, 0.65f));
	UpperBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UpperBody"));
	AddBlockoutPart(UpperBody, TEXT("/Engine/BasicShapes/Cone.Cone"), FVector(0, 0, 110),
		FRotator(180, 0, 0), FVector(0.7f, 0.7f, 1.2f));
	LeftArm = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftArm"));
	AddBlockoutPart(LeftArm, TEXT("/Engine/BasicShapes/Cube.Cube"), FVector(0, -65, 60),
		FRotator(0, 0, -20), FVector(0.18f, 0.18f, 1.05f));
	RightArm = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightArm"));
	AddBlockoutPart(RightArm, TEXT("/Engine/BasicShapes/Cube.Cube"), FVector(0, 65, 60),
		FRotator(0, 0, 20), FVector(0.18f, 0.18f, 1.05f));
}

void AJMBlackoutMonster::BeginPlay()
{
	SetMonsterEnabled(bStartsActive);
	Super::BeginPlay();
	if (!bStartsActive && AutomaticActivationDelay > 0.0f)
	{
		GetWorldTimerManager().SetTimer(ActivationTimer, this, &ThisClass::ActivateAfterDelay,
			AutomaticActivationDelay, false);
	}
}

void AJMBlackoutMonster::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorldTimerManager().ClearTimer(ActivationTimer);
	Super::EndPlay(EndPlayReason);
}

void AJMBlackoutMonster::SetBlackoutActive(bool bActive)
{
	bStartsActive = bActive;
	SetMonsterEnabled(bActive);
	if (bActive)
	{
		GetWorldTimerManager().ClearTimer(ActivationTimer);
	}
}

void AJMBlackoutMonster::ActivateAfterDelay()
{
	SetBlackoutActive(true);
}

void AJMBlackoutMonster::UpdateSpecialRules()
{
	if (APawn* Target = TargetPawn.Get(); Target && AJMBlackoutLightZone::IsLocationProtected(GetWorld(), Target->GetActorLocation()))
	{
		ClearTargetAndReturn();
	}
}

bool AJMBlackoutMonster::CanPursueTarget(const APawn* Target) const
{
	return Super::CanPursueTarget(Target) && !AJMBlackoutLightZone::IsLocationProtected(GetWorld(), Target->GetActorLocation());
}

bool AJMBlackoutMonster::CanCatchTarget(const APawn* Target) const
{
	return Super::CanCatchTarget(Target) && !AJMBlackoutLightZone::IsLocationProtected(GetWorld(), Target->GetActorLocation());
}
