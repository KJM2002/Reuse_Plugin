#include "AI/Listener/JMListenerMonster.h"

#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"

AJMListenerMonster::AJMListenerMonster()
{
	BehaviorTreeAsset = TSoftObjectPtr<UBehaviorTree>(FSoftObjectPath(TEXT("/Game/AI/Listener/BT_Listener.BT_Listener")));
	PatrolSpeed = 350.0f;
	InvestigateSpeed = 450.0f;
	ChaseSpeed = 650.0f;
	MinimumNoiseLoudness = 0.2f;
	LoseTargetDelay = 1.35f;
	SearchDuration = 8.0f;
	SearchRadius = 650.0f;
	AlertDelay = 0.55f;
	AttackWarningDuration = 1.1f;
	AlertSoundPitch = 0.72f;

	Torso = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Torso"));
	AddBlockoutPart(Torso, TEXT("/Engine/BasicShapes/Cylinder.Cylinder"), FVector(0, 0, 15),
		FRotator::ZeroRotator, FVector(0.55f, 0.55f, 1.25f));
	Head = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Head"));
	AddBlockoutPart(Head, TEXT("/Engine/BasicShapes/Sphere.Sphere"), FVector(0, 0, 105),
		FRotator::ZeroRotator, FVector(0.48f, 0.48f, 0.38f));
	LeftEar = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftEar"));
	AddBlockoutPart(LeftEar, TEXT("/Engine/BasicShapes/Cone.Cone"), FVector(0, -55, 108),
		FRotator(0, 0, 90), FVector(0.28f, 0.28f, 0.55f));
	RightEar = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightEar"));
	AddBlockoutPart(RightEar, TEXT("/Engine/BasicShapes/Cone.Cone"), FVector(0, 55, 108),
		FRotator(0, 0, -90), FVector(0.28f, 0.28f, 0.55f));
}

void AJMListenerMonster::HandleHearingStimulus(AActor* SourceActor, const FVector& StimulusLocation, float Loudness)
{
	APawn* SourcePawn = Cast<APawn>(SourceActor);
	const double Now = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0;
	const bool bRepeatedNoise = LastEvidenceTime >= 0.0 && Now - LastEvidenceTime <= RepeatNoiseEscalationWindow;
	if (Loudness >= MinimumNoiseLoudness && SourcePawn && SourcePawn->IsPlayerControlled() && !IsTargetHidden(SourcePawn))
	{
		if (GetMonsterState() == EJMDungeonMonsterState::Chase || GetMonsterState() == EJMDungeonMonsterState::AttackWarning)
		{
			TargetPawn = SourcePawn;
			LastKnownLocation = StimulusLocation;
			LastEvidenceTime = Now;
			return;
		}
		if (bRepeatedNoise)
		{
			BeginChase(SourcePawn, StimulusLocation);
			return;
		}
	}
	Super::HandleHearingStimulus(SourceActor, StimulusLocation, Loudness);
}
