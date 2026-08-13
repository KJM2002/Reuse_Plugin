#include "AI/Common/JMDungeonMonster.h"

#include "AI/NavigationSystemBase.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/AudioComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/PointLightComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/JMHideInteractorComponent.h"
#include "Engine/World.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense.h"
#include "Perception/AISense_Hearing.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Prototype/JMPrototypeRunResetComponent.h"
#include "TimerManager.h"

AJMDungeonMonsterAIController::AJMDungeonMonsterAIController()
{
	MonsterPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("MonsterPerception"));
	SetPerceptionComponent(*MonsterPerception);

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	SightConfig->SightRadius = 1350.0f;
	SightConfig->LoseSightRadius = 1550.0f;
	SightConfig->PeripheralVisionAngleDegrees = 55.0f;
	SightConfig->SetMaxAge(4.0f);
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	MonsterPerception->ConfigureSense(*SightConfig);

	HearingConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("HearingConfig"));
	HearingConfig->HearingRange = 2200.0f;
	HearingConfig->SetMaxAge(5.0f);
	HearingConfig->DetectionByAffiliation.bDetectEnemies = true;
	HearingConfig->DetectionByAffiliation.bDetectFriendlies = true;
	HearingConfig->DetectionByAffiliation.bDetectNeutrals = true;
	MonsterPerception->ConfigureSense(*HearingConfig);
	MonsterPerception->SetDominantSense(SightConfig->GetSenseImplementation());
}

void AJMDungeonMonsterAIController::BeginPlay()
{
	Super::BeginPlay();
	MonsterPerception->OnTargetPerceptionUpdated.AddUniqueDynamic(this, &ThisClass::HandleTargetPerceptionUpdated);
}

void AJMDungeonMonsterAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	AJMDungeonMonster* Monster = Cast<AJMDungeonMonster>(InPawn);
	UBehaviorTree* Tree = Monster ? Monster->BehaviorTreeAsset.LoadSynchronous() : nullptr;
	if (Monster && Tree && RunBehaviorTree(Tree))
	{
		Monster->SetBehaviorTreeDriven(true);
		if (UBlackboardComponent* MonsterBlackboard = GetBlackboardComponent())
		{
			Monster->SyncBehaviorTreeBlackboard(*MonsterBlackboard);
		}
	}
}

void AJMDungeonMonsterAIController::HandleTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	AJMDungeonMonster* Monster = Cast<AJMDungeonMonster>(GetPawn());
	if (!Monster)
	{
		return;
	}

	if (Stimulus.Type == UAISense::GetSenseID<UAISense_Sight>())
	{
		if (APawn* SensedPawn = Cast<APawn>(Actor); SensedPawn && SensedPawn->IsPlayerControlled())
		{
			Monster->HandleSightStimulus(SensedPawn, Stimulus.WasSuccessfullySensed(), Stimulus.StimulusLocation);
		}
	}
	else if (Stimulus.Type == UAISense::GetSenseID<UAISense_Hearing>() && Stimulus.WasSuccessfullySensed())
	{
		Monster->HandleHearingStimulus(Actor, Stimulus.StimulusLocation, Stimulus.Strength);
	}
}

bool AJMDungeonMonsterAIController::IsTargetSeen(AActor* Target) const
{
	if (!IsValid(Target) || !MonsterPerception)
	{
		return false;
	}
	FActorPerceptionBlueprintInfo Info;
	if (!MonsterPerception->GetActorsPerception(Target, Info))
	{
		return false;
	}
	for (const FAIStimulus& Stimulus : Info.LastSensedStimuli)
	{
		if (Stimulus.Type == UAISense::GetSenseID<UAISense_Sight>() && Stimulus.WasSuccessfullySensed())
		{
			return true;
		}
	}
	return false;
}

AJMDungeonMonster::AJMDungeonMonster()
{
	PrimaryActorTick.bCanEverTick = false;
	AIControllerClass = AJMDungeonMonsterAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	BlockoutRoot = CreateDefaultSubobject<USceneComponent>(TEXT("BlockoutRoot"));
	BlockoutRoot->SetupAttachment(GetRootComponent());

	StateLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("StateLight"));
	StateLight->SetupAttachment(BlockoutRoot);
	StateLight->SetRelativeLocation(FVector(35.0f, 0.0f, 75.0f));
	StateLight->SetAttenuationRadius(220.0f);
	StateLight->SetIntensity(850.0f);
	StateLight->SetCastShadows(false);

	VoiceAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("VoiceAudio"));
	VoiceAudio->SetupAttachment(BlockoutRoot);
	VoiceAudio->bAutoActivate = false;

	ContactSensor = CreateDefaultSubobject<UCapsuleComponent>(TEXT("ContactSensor"));
	ContactSensor->SetupAttachment(GetCapsuleComponent());
	ContactSensor->InitCapsuleSize(GetCapsuleComponent()->GetUnscaledCapsuleRadius() + PhysicalContactTolerance,
		GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight() + PhysicalContactTolerance);
	ContactSensor->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	ContactSensor->SetCollisionResponseToAllChannels(ECR_Ignore);
	ContactSensor->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	ContactSensor->SetGenerateOverlapEvents(true);
	ContactSensor->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::HandleContactSensorOverlap);

	static ConstructorHelpers::FObjectFinder<USoundBase> DefaultAlert(
		TEXT("/Engine/EngineSounds/1kSineTonePing.1kSineTonePing"));
	if (DefaultAlert.Succeeded())
	{
		AlertSound = DefaultAlert.Object;
	}
}

void AJMDungeonMonster::BeginPlay()
{
	Super::BeginPlay();
	if (ContactSensor && GetCapsuleComponent())
	{
		ContactSensor->SetCapsuleSize(GetCapsuleComponent()->GetUnscaledCapsuleRadius() + PhysicalContactTolerance,
			GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight() + PhysicalContactTolerance);
	}
	SpawnLocation = GetActorLocation();
	SpawnRotation = GetActorRotation();
	LastKnownLocation = SpawnLocation;
	// Deferred spawning can initialize CharacterMovement after the director first
	// configures dormancy. Re-apply the full enabled state once every component is ready.
	SetMonsterEnabled(bMonsterEnabled);
	if (!bBehaviorTreeDriven)
	{
		GetWorldTimerManager().SetTimer(DecisionTimer, this, &ThisClass::UpdateDecision, 0.15f, true);
	}
}

void AJMDungeonMonster::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorldTimerManager().ClearTimer(DecisionTimer);
	Super::EndPlay(EndPlayReason);
}

void AJMDungeonMonster::SetMonsterEnabled(bool bEnabled)
{
	bMonsterEnabled = bEnabled;
	SetActorHiddenInGame(!bEnabled);
	SetActorEnableCollision(bEnabled);
	if (bEnabled)
	{
		if (UCharacterMovementComponent* Movement = GetCharacterMovement())
		{
			Movement->SetMovementMode(MOVE_Walking);
		}
		SetMonsterState(EJMDungeonMonsterState::Patrol);
	}
	else
	{
		if (UCharacterMovementComponent* Movement = GetCharacterMovement())
		{
			Movement->StopMovementImmediately();
			Movement->DisableMovement();
		}
		TargetPawn.Reset();
		SetMonsterState(EJMDungeonMonsterState::Dormant);
		if (AAIController* ActiveController = Cast<AAIController>(GetController()))
		{
			ActiveController->StopMovement();
		}
	}
}

void AJMDungeonMonster::ConfigureAuthoredRoute(const TArray<USceneComponent*>& InPatrolPoints, FVector InHomeLocation)
{
	AuthoredPatrolPoints.Reset(InPatrolPoints.Num());
	for (USceneComponent* Point : InPatrolPoints)
	{
		if (IsValid(Point))
		{
			AuthoredPatrolPoints.Add(Point);
		}
	}
	AuthoredHomeLocation = InHomeLocation;
	bHasAuthoredHome = true;
	PatrolIndex = INDEX_NONE;
}

void AJMDungeonMonster::SetBehaviorTreeDriven(bool bDriven)
{
	bBehaviorTreeDriven = bDriven;
	if (bBehaviorTreeDriven)
	{
		GetWorldTimerManager().ClearTimer(DecisionTimer);
	}
}

void AJMDungeonMonster::TickBehaviorTreeDecision(EJMDungeonMonsterState ExpectedState)
{
	if (MonsterState == ExpectedState)
	{
		UpdateDecision();
	}
}

void AJMDungeonMonster::SyncBehaviorTreeBlackboard(UBlackboardComponent& Blackboard) const
{
	const UEnum* StateEnum = StaticEnum<EJMDungeonMonsterState>();
	Blackboard.SetValueAsObject(TEXT("MonsterActor"), const_cast<AJMDungeonMonster*>(this));
	Blackboard.SetValueAsObject(TEXT("TargetActor"), TargetPawn.Get());
	Blackboard.SetValueAsEnum(TEXT("State"), static_cast<uint8>(MonsterState));
	Blackboard.SetValueAsName(TEXT("StateName"), StateEnum
		? FName(*StateEnum->GetNameStringByValue(static_cast<int64>(MonsterState))) : NAME_None);
	Blackboard.SetValueAsVector(TEXT("LastKnownLocation"), LastKnownLocation);
	Blackboard.SetValueAsInt(TEXT("PatrolIndex"), PatrolIndex);
	Blackboard.SetValueAsInt(TEXT("PatrolPointCount"), AuthoredPatrolPoints.Num());
	Blackboard.SetValueAsInt(TEXT("CompletedPatrolLegs"), CompletedPatrolLegCount);
	Blackboard.SetValueAsEnum(TEXT("PatrolMode"), static_cast<uint8>(PatrolMode));
	Blackboard.SetValueAsBool(TEXT("IsEnabled"), bMonsterEnabled);
}

void AJMDungeonMonster::HandleSightStimulus(APawn* SeenPawn, bool bSuccessfullySensed, const FVector& StimulusLocation)
{
	if (!bMonsterEnabled || !UsesSightStimulus() || !IsValid(SeenPawn) || !SeenPawn->IsPlayerControlled())
	{
		return;
	}
	if (bSuccessfullySensed && !IsTargetHidden(SeenPawn) && CanPursueTarget(SeenPawn))
	{
		LastKnownLocation = SeenPawn->GetActorLocation();
		LastEvidenceTime = GetWorld()->GetTimeSeconds();
		if (MonsterState == EJMDungeonMonsterState::Chase || MonsterState == EJMDungeonMonsterState::AttackWarning)
		{
			TargetPawn = SeenPawn;
		}
		else
		{
			BeginSuspicion(SeenPawn, LastKnownLocation);
		}
	}
	else if (!bSuccessfullySensed && TargetPawn.Get() == SeenPawn)
	{
		LastKnownLocation = StimulusLocation.IsNearlyZero() ? SeenPawn->GetActorLocation() : StimulusLocation;
	}
}

void AJMDungeonMonster::HandleHearingStimulus(AActor* SourceActor, const FVector& StimulusLocation, float Loudness)
{
	if (!bMonsterEnabled || !UsesHearingStimulus() || Loudness < MinimumNoiseLoudness)
	{
		return;
	}
	APawn* SourcePawn = Cast<APawn>(SourceActor);
	if (SourcePawn && (!SourcePawn->IsPlayerControlled() || IsTargetHidden(SourcePawn)))
	{
		return;
	}
	BeginInvestigation(StimulusLocation, SourceActor);
}

void AJMDungeonMonster::BeginSuspicion(APawn* Target, const FVector& EvidenceLocation)
{
	if (!CanPursueTarget(Target))
	{
		return;
	}
	TargetPawn = Target;
	LastKnownLocation = EvidenceLocation;
	LastEvidenceTime = GetWorld()->GetTimeSeconds();
	SetMonsterState(EJMDungeonMonsterState::Suspicious);
}

void AJMDungeonMonster::BeginInvestigation(const FVector& EvidenceLocation, AActor* SourceActor)
{
	APawn* SourcePawn = Cast<APawn>(SourceActor);
	if (SourcePawn && CanPursueTarget(SourcePawn))
	{
		TargetPawn = SourcePawn;
	}
	LastKnownLocation = EvidenceLocation;
	LastEvidenceTime = GetWorld()->GetTimeSeconds();
	if (MonsterState != EJMDungeonMonsterState::Chase && MonsterState != EJMDungeonMonsterState::AttackWarning)
	{
		SetMonsterState(EJMDungeonMonsterState::Investigate);
	}
}

void AJMDungeonMonster::BeginChase(APawn* Target, const FVector& EvidenceLocation)
{
	if (!CanPursueTarget(Target))
	{
		return;
	}
	TargetPawn = Target;
	LastKnownLocation = EvidenceLocation;
	LastEvidenceTime = GetWorld()->GetTimeSeconds();
	SetMonsterState(EJMDungeonMonsterState::Chase);
}

void AJMDungeonMonster::BeginSearch(const FVector& SearchOrigin)
{
	LastKnownLocation = SearchOrigin;
	TargetPawn.Reset();
	bHasSearchPoint = false;
	SetMonsterState(EJMDungeonMonsterState::Search);
}

void AJMDungeonMonster::ClearTargetAndReturn()
{
	TargetPawn.Reset();
	bHasSearchPoint = false;
	SetMonsterState(EJMDungeonMonsterState::Return);
}

void AJMDungeonMonster::SetMonsterState(EJMDungeonMonsterState NewState)
{
	if (MonsterState == NewState && StateStartTime > 0.0)
	{
		return;
	}
	const EJMDungeonMonsterState OldState = MonsterState;
	MonsterState = NewState;
	StateStartTime = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0;
	bHasSearchPoint = false;
	RefreshStateFeedback();
	if (NewState == EJMDungeonMonsterState::Suspicious || NewState == EJMDungeonMonsterState::AttackWarning)
	{
		PlayAlertCue();
	}
	OnStateChanged.Broadcast(OldState, NewState);
	if (AAIController* ActiveController = Cast<AAIController>(GetController()))
	{
		if (UBlackboardComponent* Blackboard = ActiveController->GetBlackboardComponent())
		{
			SyncBehaviorTreeBlackboard(*Blackboard);
		}
	}
}

void AJMDungeonMonster::UpdateDecision()
{
	if (!bMonsterEnabled || MonsterState == EJMDungeonMonsterState::Dormant)
	{
		return;
	}
	UpdateSpecialRules();
	AJMDungeonMonsterAIController* MonsterController = Cast<AJMDungeonMonsterAIController>(GetController());
	if (!MonsterController)
	{
		return;
	}
	RefreshDirectPlayerAwareness(MonsterController);
	const double Now = GetWorld()->GetTimeSeconds();
	if (MonsterState == EJMDungeonMonsterState::Suspicious)
	{
		MonsterController->StopMovement();
		if (Now - StateStartTime >= AlertDelay)
		{
			if (APawn* Target = TargetPawn.Get(); Target && CanPursueTarget(Target) && !IsTargetHidden(Target))
			{
				BeginChase(Target, LastKnownLocation);
			}
			else
			{
				SetMonsterState(EJMDungeonMonsterState::Investigate);
			}
		}
		return;
	}
	switch (MonsterState)
	{
	case EJMDungeonMonsterState::Patrol: UpdatePatrol(MonsterController); break;
	case EJMDungeonMonsterState::Investigate: UpdateInvestigation(MonsterController); break;
	case EJMDungeonMonsterState::Chase: UpdateChase(MonsterController); break;
	case EJMDungeonMonsterState::AttackWarning: UpdateAttackWarning(MonsterController); break;
	case EJMDungeonMonsterState::Search: UpdateSearch(MonsterController); break;
	case EJMDungeonMonsterState::Return: UpdateReturn(MonsterController); break;
	default: break;
	}
}

void AJMDungeonMonster::UpdatePatrol(AJMDungeonMonsterAIController* MonsterController)
{
	GetCharacterMovement()->MaxWalkSpeed = PatrolSpeed;
	if (PatrolMode == EJMDungeonPatrolMode::Stationary)
	{
		MonsterController->StopMovement();
		return;
	}
	const float AdvanceRadiusSquared = FMath::Square(FMath::Max(
		PatrolPointAdvanceRadius, PatrolMoveAcceptanceRadius + 1.0f));
	if (!AuthoredPatrolPoints.IsEmpty())
	{
		const bool bReachedCurrentPoint = AuthoredPatrolPoints.IsValidIndex(PatrolIndex) &&
			IsValid(AuthoredPatrolPoints[PatrolIndex]) &&
			FVector::DistSquared2D(GetActorLocation(), AuthoredPatrolPoints[PatrolIndex]->GetComponentLocation()) <= AdvanceRadiusSquared;
		if (!AuthoredPatrolPoints.IsValidIndex(PatrolIndex) || !IsValid(AuthoredPatrolPoints[PatrolIndex]) || bReachedCurrentPoint)
		{
			CompletedPatrolLegCount += bReachedCurrentPoint ? 1 : 0;
			for (int32 Attempt = 0; Attempt < AuthoredPatrolPoints.Num(); ++Attempt)
			{
				PatrolIndex = (PatrolIndex + 1) % AuthoredPatrolPoints.Num();
				if (IsValid(AuthoredPatrolPoints[PatrolIndex]))
				{
					break;
				}
			}
		}
		if (AuthoredPatrolPoints.IsValidIndex(PatrolIndex) && IsValid(AuthoredPatrolPoints[PatrolIndex]))
		{
			MoveToward(MonsterController, AuthoredPatrolPoints[PatrolIndex]->GetComponentLocation(),
				PatrolMoveAcceptanceRadius, false);
		}
		return;
	}
	if (PatrolPoints.IsEmpty())
	{
		MonsterController->StopMovement();
		return;
	}
	const bool bReachedCurrentPoint = PatrolPoints.IsValidIndex(PatrolIndex) && IsValid(PatrolPoints[PatrolIndex]) &&
		FVector::DistSquared2D(GetActorLocation(), PatrolPoints[PatrolIndex]->GetActorLocation()) <= AdvanceRadiusSquared;
	if (!PatrolPoints.IsValidIndex(PatrolIndex) || !IsValid(PatrolPoints[PatrolIndex]) || bReachedCurrentPoint)
	{
		CompletedPatrolLegCount += bReachedCurrentPoint ? 1 : 0;
		for (int32 Attempt = 0; Attempt < PatrolPoints.Num(); ++Attempt)
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
		MoveToward(MonsterController, PatrolPoints[PatrolIndex]->GetActorLocation(),
			PatrolMoveAcceptanceRadius, false);
	}
}

void AJMDungeonMonster::UpdateInvestigation(AJMDungeonMonsterAIController* MonsterController)
{
	GetCharacterMovement()->MaxWalkSpeed = InvestigateSpeed;
	MoveToward(MonsterController, LastKnownLocation, 90.0f);
	if (FVector::DistSquared(GetActorLocation(), LastKnownLocation) <= FMath::Square(130.0f))
	{
		BeginSearch(LastKnownLocation);
	}
}

void AJMDungeonMonster::UpdateChase(AJMDungeonMonsterAIController* MonsterController)
{
	APawn* Target = TargetPawn.Get();
	if (!Target || !CanPursueTarget(Target) || IsTargetHidden(Target))
	{
		BeginSearch(LastKnownLocation);
		return;
	}
	const double Now = GetWorld()->GetTimeSeconds();
	if (IsTargetInPhysicalContact(Target))
	{
		CatchPlayer(Target);
		return;
	}
	if (UsesSightStimulus() && MonsterController->IsTargetSeen(Target))
	{
		LastKnownLocation = Target->GetActorLocation();
		LastEvidenceTime = Now;
	}
	if (Now - LastEvidenceTime > LoseTargetDelay)
	{
		BeginSearch(LastKnownLocation);
		return;
	}
	if (IsTargetWithinAttackRange(Target))
	{
		SetMonsterState(EJMDungeonMonsterState::AttackWarning);
		MonsterController->StopMovement();
		return;
	}
	GetCharacterMovement()->MaxWalkSpeed = ChaseSpeed;
	// Do not include either agent's collision radius here. The explicit contact test above owns attack range.
	MoveToward(MonsterController, LastKnownLocation, 5.0f, false);
}

void AJMDungeonMonster::UpdateAttackWarning(AJMDungeonMonsterAIController* MonsterController)
{
	MonsterController->StopMovement();
	APawn* Target = TargetPawn.Get();
	if (Target && CanCatchTarget(Target) && IsTargetInPhysicalContact(Target))
	{
		CatchPlayer(Target);
		return;
	}
	const float EscapeDistance = GetAttackTriggerDistance(Target) * 1.35f;
	if (!Target || !CanCatchTarget(Target) ||
		FVector::DistSquared2D(GetActorLocation(), Target->GetActorLocation()) > FMath::Square(EscapeDistance))
	{
		SetMonsterState(EJMDungeonMonsterState::Chase);
		return;
	}
	const FVector Direction = Target->GetActorLocation() - GetActorLocation();
	if (!Direction.IsNearlyZero())
	{
		SetActorRotation(Direction.Rotation());
	}
	if (GetWorld()->GetTimeSeconds() - StateStartTime >= AttackWarningDuration)
	{
		CatchPlayer(Target);
	}
}

void AJMDungeonMonster::RefreshDirectPlayerAwareness(AJMDungeonMonsterAIController* MonsterController)
{
	APlayerController* PlayerController = GetWorld() ? GetWorld()->GetFirstPlayerController() : nullptr;
	APawn* Player = PlayerController ? PlayerController->GetPawn() : nullptr;
	if (!Player || IsTargetHidden(Player) || !CanPursueTarget(Player))
	{
		return;
	}

	const double Now = GetWorld()->GetTimeSeconds();
	if (IsTargetInPhysicalContact(Player))
	{
		TargetPawn = Player;
		LastKnownLocation = Player->GetActorLocation();
		LastEvidenceTime = Now;
		CatchPlayer(Player);
		return;
	}
	if (IsTargetWithinAttackRange(Player))
	{
		// Near-contact still keeps the authored warning/dodge window; confirmed body contact above is already lethal.
		TargetPawn = Player;
		LastKnownLocation = Player->GetActorLocation();
		LastEvidenceTime = Now;
		if (MonsterState != EJMDungeonMonsterState::AttackWarning)
		{
			SetMonsterState(EJMDungeonMonsterState::AttackWarning);
			MonsterController->StopMovement();
		}
		return;
	}

	if (!UsesSightStimulus() || !HasDirectSightTo(Player, MonsterController))
	{
		return;
	}

	TargetPawn = Player;
	LastKnownLocation = Player->GetActorLocation();
	LastEvidenceTime = Now;
	if (MonsterState != EJMDungeonMonsterState::Chase && MonsterState != EJMDungeonMonsterState::AttackWarning &&
		MonsterState != EJMDungeonMonsterState::Suspicious)
	{
		BeginSuspicion(Player, LastKnownLocation);
	}
}

bool AJMDungeonMonster::HasDirectSightTo(const APawn* Target,
	const AJMDungeonMonsterAIController* MonsterController) const
{
	if (!Target || !MonsterController)
	{
		return false;
	}
	const FVector ToTarget = Target->GetActorLocation() - GetActorLocation();
	const FVector ToTarget2D(ToTarget.X, ToTarget.Y, 0.0f);
	if (ToTarget2D.SizeSquared() > FMath::Square(DirectSightRange))
	{
		return false;
	}
	const FVector Forward2D = GetActorForwardVector().GetSafeNormal2D();
	if (!ToTarget2D.IsNearlyZero() && FVector::DotProduct(Forward2D, ToTarget2D.GetSafeNormal()) <
		FMath::Cos(FMath::DegreesToRadians(DirectSightHalfAngle)))
	{
		return false;
	}
	return MonsterController->LineOfSightTo(Target, FVector::ZeroVector, true);
}

void AJMDungeonMonster::UpdateSearch(AJMDungeonMonsterAIController* MonsterController)
{
	if (GetWorld()->GetTimeSeconds() - StateStartTime >= SearchDuration)
	{
		ClearTargetAndReturn();
		return;
	}
	GetCharacterMovement()->MaxWalkSpeed = InvestigateSpeed * 0.8f;
	if (!bHasSearchPoint || FVector::DistSquared(GetActorLocation(), CurrentSearchPoint) < FMath::Square(110.0f))
	{
		FNavLocation NavPoint;
		if (UNavigationSystemV1* Nav = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
			Nav && Nav->GetRandomReachablePointInRadius(LastKnownLocation, SearchRadius, NavPoint))
		{
			CurrentSearchPoint = NavPoint.Location;
			bHasSearchPoint = true;
		}
		else
		{
			CurrentSearchPoint = LastKnownLocation;
			bHasSearchPoint = true;
		}
	}
	MoveToward(MonsterController, CurrentSearchPoint, 75.0f);
}

void AJMDungeonMonster::UpdateReturn(AJMDungeonMonsterAIController* MonsterController)
{
	GetCharacterMovement()->MaxWalkSpeed = PatrolSpeed;
	const FVector ReturnLocation = GetReturnLocation();
	MoveToward(MonsterController, ReturnLocation, 100.0f);
	if (FVector::DistSquared(GetActorLocation(), ReturnLocation) <= FMath::Square(140.0f))
	{
		SetMonsterState(EJMDungeonMonsterState::Patrol);
	}
}

void AJMDungeonMonster::MoveToward(AJMDungeonMonsterAIController* MonsterController, const FVector& Destination,
	float AcceptanceRadius, bool bStopOnOverlap)
{
	MonsterController->MoveToLocation(Destination, AcceptanceRadius, bStopOnOverlap, true, true, false, nullptr, true);
}

void AJMDungeonMonster::CatchPlayer(APawn* Player)
{
	OnPlayerCaught.Broadcast(Player);
	if (UJMPrototypeRunResetComponent* Reset = Player->FindComponentByClass<UJMPrototypeRunResetComponent>())
	{
		Reset->FailCurrentRun();
	}
	ResetMonster();
}

bool AJMDungeonMonster::CanPursueTarget(const APawn* Target) const
{
	return bMonsterEnabled && IsValid(Target) && Target->IsPlayerControlled() && !IsTargetHidden(Target);
}

bool AJMDungeonMonster::CanCatchTarget(const APawn* Target) const
{
	return CanPursueTarget(Target) && GetWorld() && GetWorld()->GetTimeSeconds() - LastEvidenceTime <= LoseTargetDelay + AttackWarningDuration;
}

float AJMDungeonMonster::GetAttackTriggerDistance(const APawn* Target) const
{
	float ContactDistance = 0.0f;
	if (const UCapsuleComponent* MonsterCapsule = GetCapsuleComponent())
	{
		ContactDistance += MonsterCapsule->GetScaledCapsuleRadius();
	}
	if (const ACharacter* TargetCharacter = Cast<ACharacter>(Target))
	{
		if (const UCapsuleComponent* TargetCapsule = TargetCharacter->GetCapsuleComponent())
		{
			ContactDistance += TargetCapsule->GetScaledCapsuleRadius();
		}
	}
	return FMath::Max(CatchDistance, ContactDistance + ContactAttackPadding);
}

bool AJMDungeonMonster::IsTargetWithinAttackRange(const APawn* Target) const
{
	return IsValid(Target) && FVector::DistSquared2D(GetActorLocation(), Target->GetActorLocation()) <=
		FMath::Square(GetAttackTriggerDistance(Target));
}

bool AJMDungeonMonster::IsTargetInPhysicalContact(const APawn* Target) const
{
	if (!IsValid(Target))
	{
		return false;
	}
	const UCapsuleComponent* MonsterCapsule = GetCapsuleComponent();
	const ACharacter* TargetCharacter = Cast<ACharacter>(Target);
	const UCapsuleComponent* TargetCapsule = TargetCharacter ? TargetCharacter->GetCapsuleComponent() : nullptr;
	if (!MonsterCapsule || !TargetCapsule)
	{
		return false;
	}
	const float HorizontalContactDistance = MonsterCapsule->GetScaledCapsuleRadius() +
		TargetCapsule->GetScaledCapsuleRadius() + PhysicalContactTolerance;
	const float VerticalContactDistance = MonsterCapsule->GetScaledCapsuleHalfHeight() +
		TargetCapsule->GetScaledCapsuleHalfHeight() + PhysicalContactTolerance;
	return FVector::DistSquared2D(GetActorLocation(), Target->GetActorLocation()) <=
		FMath::Square(HorizontalContactDistance) &&
		FMath::Abs(GetActorLocation().Z - Target->GetActorLocation().Z) <= VerticalContactDistance;
}

void AJMDungeonMonster::HandleContactSensorOverlap(UPrimitiveComponent*, AActor* OtherActor,
	UPrimitiveComponent*, int32, bool, const FHitResult&)
{
	APawn* Player = Cast<APawn>(OtherActor);
	if (!bMonsterEnabled || Player == this || !Player || !Player->IsPlayerControlled() || !CanPursueTarget(Player))
	{
		return;
	}
	TargetPawn = Player;
	LastKnownLocation = Player->GetActorLocation();
	LastEvidenceTime = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0;
	CatchPlayer(Player);
}

bool AJMDungeonMonster::IsTargetHidden(const AActor* Target) const
{
	if (!IsValid(Target))
	{
		return false;
	}
	if (const UJMHideInteractorComponent* Hide = Target->FindComponentByClass<UJMHideInteractorComponent>())
	{
		return Hide->IsHidden();
	}
	return false;
}

FVector AJMDungeonMonster::GetReturnLocation() const
{
	return bHasAuthoredHome ? AuthoredHomeLocation : SpawnLocation;
}

void AJMDungeonMonster::UpdateSpecialRules()
{
}

void AJMDungeonMonster::ResetMonster()
{
	TargetPawn.Reset();
	PatrolIndex = INDEX_NONE;
	bHasSearchPoint = false;
	LastEvidenceTime = -1.0;
	if (AAIController* ActiveController = Cast<AAIController>(GetController()))
	{
		ActiveController->StopMovement();
	}
	TeleportTo(SpawnLocation, SpawnRotation, false, true);
	SetMonsterState(bMonsterEnabled ? EJMDungeonMonsterState::Patrol : EJMDungeonMonsterState::Dormant);
}

void AJMDungeonMonster::PlayAlertCue()
{
	if (AlertSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, AlertSound, GetActorLocation(), 0.18f, AlertSoundPitch);
	}
}

void AJMDungeonMonster::RefreshStateFeedback()
{
	if (!StateLight)
	{
		return;
	}
	FLinearColor Color = FLinearColor(0.08f, 0.25f, 1.0f);
	float Intensity = 650.0f;
	switch (MonsterState)
	{
	case EJMDungeonMonsterState::Dormant: Intensity = 0.0f; break;
	case EJMDungeonMonsterState::Patrol: Color = FLinearColor(0.05f, 0.25f, 1.0f); break;
	case EJMDungeonMonsterState::Suspicious: Color = FLinearColor::Yellow; Intensity = 1300.0f; break;
	case EJMDungeonMonsterState::Investigate: Color = FLinearColor(1.0f, 0.25f, 0.0f); Intensity = 1100.0f; break;
	case EJMDungeonMonsterState::Chase: Color = FLinearColor::Red; Intensity = 1800.0f; break;
	case EJMDungeonMonsterState::AttackWarning: Color = FLinearColor::White; Intensity = 2600.0f; break;
	case EJMDungeonMonsterState::Search: Color = FLinearColor(0.5f, 0.0f, 1.0f); Intensity = 1000.0f; break;
	case EJMDungeonMonsterState::Return: Color = FLinearColor(0.0f, 0.8f, 0.8f); break;
	}
	StateLight->SetLightColor(Color);
	StateLight->SetIntensity(Intensity);
}

void AJMDungeonMonster::AddBlockoutPart(UStaticMeshComponent* Part, const TCHAR* MeshPath,
	const FVector& RelativeLocation, const FRotator& RelativeRotation, const FVector& RelativeScale)
{
	if (!Part)
	{
		return;
	}
	Part->SetupAttachment(BlockoutRoot);
	if (UStaticMesh* LoadedMesh = LoadObject<UStaticMesh>(nullptr, MeshPath))
	{
		Part->SetStaticMesh(LoadedMesh);
	}
	Part->SetRelativeLocation(RelativeLocation);
	Part->SetRelativeRotation(RelativeRotation);
	Part->SetRelativeScale3D(RelativeScale);
	Part->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
