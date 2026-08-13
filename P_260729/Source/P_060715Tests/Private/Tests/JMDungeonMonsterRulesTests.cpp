#include "AI/Blackout/JMBlackoutLightZone.h"
#include "AI/Blackout/JMBlackoutMonster.h"
#include "AI/Common/JMMonsterBehaviorTreeNodes.h"
#include "AI/Hoarder/JMHoarderMonster.h"
#include "AI/Listener/JMListenerMonster.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerState.h"
#include "Engine/World.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationEditorCommon.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMDungeonMonsterBlockoutDefaultsTest,
	"JM.AI.DungeonMonster.BlockoutAndFairnessDefaults",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMDungeonMonsterBlockoutDefaultsTest::RunTest(const FString&)
{
	const AJMListenerMonster* Listener = GetDefault<AJMListenerMonster>();
	const AJMHoarderMonster* Hoarder = GetDefault<AJMHoarderMonster>();
	const AJMBlackoutMonster* Blackout = GetDefault<AJMBlackoutMonster>();

	TestNotNull(TEXT("Listener has a torso blockout mesh"), Listener->Torso.Get());
	TestNotNull(TEXT("Every monster owns a physical contact sensor"), Listener->ContactSensor.Get());
	TestNotNull(TEXT("Listener has readable ear silhouettes"), Listener->LeftEar.Get());
	TestNotNull(TEXT("Hoarder has a heavy body blockout mesh"), Hoarder->Body.Get());
	TestNotNull(TEXT("Blackout has a tall upper body blockout mesh"), Blackout->UpperBody.Get());
	TestTrue(TEXT("Listener catch has a warning window"), Listener->AttackWarningDuration >= 1.0f);
	TestTrue(TEXT("Hoarder has a slower warning before aggression"), Hoarder->AlertDelay >= 1.0f);
	TestTrue(TEXT("Blackout is delayed by default"), !Blackout->bStartsActive && Blackout->AutomaticActivationDelay >= 30.0f);
	TestEqual(TEXT("Listener continuously loops its authored patrol route by default"),
		Listener->PatrolMode, EJMDungeonPatrolMode::ContinuousLoop);
	TestEqual(TEXT("Hoarder continuously loops its authored patrol route by default"),
		Hoarder->PatrolMode, EJMDungeonPatrolMode::ContinuousLoop);
	TestEqual(TEXT("Blackout continuously loops its authored patrol route after activation"),
		Blackout->PatrolMode, EJMDungeonPatrolMode::ContinuousLoop);
	TestEqual(TEXT("Listener patrols faster than the player's 300 walk speed"), Listener->PatrolSpeed, 350.0f);
	TestEqual(TEXT("Hoarder patrols faster than the player's 300 walk speed"), Hoarder->PatrolSpeed, 315.0f);
	TestEqual(TEXT("Blackout patrols faster than the player's 300 walk speed"), Blackout->PatrolSpeed, 335.0f);
	TestEqual(TEXT("Listener chases slightly faster than the player's 600 run speed"), Listener->ChaseSpeed, 650.0f);
	TestEqual(TEXT("Hoarder chases slightly faster than the player's 600 run speed"), Hoarder->ChaseSpeed, 620.0f);
	TestEqual(TEXT("Blackout chases slightly faster than the player's 600 run speed"), Blackout->ChaseSpeed, 640.0f);
	TestTrue(TEXT("Hoarder hears nearby walking instead of only sprinting"), Hoarder->MinimumNoiseLoudness <= 0.32f);
	TestTrue(TEXT("Blackout hears nearby walking instead of only sprinting"), Blackout->MinimumNoiseLoudness <= 0.32f);
	TestTrue(TEXT("Hoarder defends itself outside a misplaced territory center"), Hoarder->PersonalDefenseRadius > 0.0f);
	TestTrue(TEXT("Hoarder has long-room sight range"), Hoarder->DirectSightRange >= 2400.0f);
	TestTrue(TEXT("Hoarder keeps chasing after a brief line-of-sight break"), Hoarder->LoseTargetDelay >= 5.0f);
	TestTrue(TEXT("Hoarder searches the last known area after losing sight"), Hoarder->SearchDuration >= 8.0f);
	TestTrue(TEXT("Hoarder territory leash does not truncate its sight range"),
		Hoarder->WarningRadius + Hoarder->LeashExtraDistance >= Hoarder->DirectSightRange);
	TestTrue(TEXT("Patrol advance radius is larger than path acceptance radius"),
		Listener->PatrolPointAdvanceRadius > Listener->PatrolMoveAcceptanceRadius);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMDungeonMonsterContactRangeTest,
	"JM.AI.DungeonMonster.EffectiveAttackRangeIncludesCapsules",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMDungeonMonsterContactRangeTest::RunTest(const FString&)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
	AJMHoarderMonster* Hoarder = World
		? World->SpawnActor<AJMHoarderMonster>(FVector::ZeroVector, FRotator::ZeroRotator) : nullptr;
	ACharacter* Player = World
		? World->SpawnActor<ACharacter>(FVector(105.0f, 0.0f, 0.0f), FRotator::ZeroRotator) : nullptr;
	TestNotNull(TEXT("Hoarder spawns for contact check"), Hoarder);
	TestNotNull(TEXT("Player capsule spawns for contact check"), Player);
	if (Hoarder && Player)
	{
		TestTrue(TEXT("Touching character capsules are inside the effective attack range"),
			Hoarder->IsTargetWithinAttackRange(Player));
		TestTrue(TEXT("Effective attack range includes both capsule radii"),
			Hoarder->GetAttackTriggerDistance(Player) >= 105.0f);
	}
	if (World)
	{
		World->DestroyWorld(false);
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMDungeonMonsterMovingContactCatchTest,
	"JM.AI.DungeonMonster.PhysicalContactCatchesWithoutSustainedOverlap",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMDungeonMonsterMovingContactCatchTest::RunTest(const FString&)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
	AJMHoarderMonster* Hoarder = World
		? World->SpawnActor<AJMHoarderMonster>(FVector::ZeroVector, FRotator::ZeroRotator) : nullptr;
	ACharacter* Player = World
		? World->SpawnActor<ACharacter>(FVector(400.0f, 0.0f, 0.0f), FRotator::ZeroRotator) : nullptr;
	APlayerState* PlayerState = World ? World->SpawnActor<APlayerState>() : nullptr;
	AJMDungeonMonsterAIController* MonsterController = World
		? World->SpawnActor<AJMDungeonMonsterAIController>() : nullptr;
	TestNotNull(TEXT("Hoarder spawns for moving contact check"), Hoarder);
	TestNotNull(TEXT("Player spawns for moving contact check"), Player);
	if (Hoarder && Player && PlayerState && MonsterController)
	{
		Player->SetPlayerState(PlayerState);
		MonsterController->Possess(Hoarder);
		Hoarder->SetTerritoryCenter(Hoarder->GetActorLocation());
		Hoarder->AlertDelay = 0.0f;
		Hoarder->HandleSightStimulus(Player, true, Player->GetActorLocation());
		Hoarder->TickBehaviorTreeDecision(EJMDungeonMonsterState::Suspicious);
		TestEqual(TEXT("Precondition enters chase"), Hoarder->GetMonsterState(), EJMDungeonMonsterState::Chase);
		Player->SetActorEnableCollision(false);
		Player->SetActorLocation(FVector(75.0f, 0.0f, 0.0f), false, nullptr, ETeleportType::TeleportPhysics);
		TestTrue(TEXT("Single capsule contact is detected"), Hoarder->IsTargetInPhysicalContact(Player));
		Hoarder->TickBehaviorTreeDecision(EJMDungeonMonsterState::Chase);
		TestEqual(TEXT("One contact catches immediately and resets without sustained overlap"),
			Hoarder->GetMonsterState(), EJMDungeonMonsterState::Patrol);
	}
	if (World)
	{
		World->DestroyWorld(false);
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMDungeonMonsterSightChaseAttackTest,
	"JM.AI.DungeonMonster.SightCommitsToChaseAndContactAttack",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMDungeonMonsterSightChaseAttackTest::RunTest(const FString&)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
	AJMHoarderMonster* Hoarder = World
		? World->SpawnActor<AJMHoarderMonster>(FVector::ZeroVector, FRotator::ZeroRotator) : nullptr;
	ACharacter* Player = World
		? World->SpawnActor<ACharacter>(FVector(400.0f, 0.0f, 0.0f), FRotator::ZeroRotator) : nullptr;
	APlayerState* PlayerState = World ? World->SpawnActor<APlayerState>() : nullptr;
	AJMDungeonMonsterAIController* MonsterController = World
		? World->SpawnActor<AJMDungeonMonsterAIController>() : nullptr;
	TestNotNull(TEXT("Hoarder spawns for sight transition check"), Hoarder);
	TestNotNull(TEXT("Player spawns for sight transition check"), Player);
	TestNotNull(TEXT("Player state spawns for sight transition check"), PlayerState);
	TestNotNull(TEXT("Monster controller spawns for sight transition check"), MonsterController);

	if (Hoarder && Player && PlayerState && MonsterController)
	{
		Player->SetPlayerState(PlayerState);
		MonsterController->Possess(Hoarder);
		Hoarder->SetTerritoryCenter(Hoarder->GetActorLocation());
		Hoarder->AlertDelay = 0.0f;
		Hoarder->AttackWarningDuration = 0.0f;

		Hoarder->HandleSightStimulus(Player, true, Player->GetActorLocation());
		TestEqual(TEXT("Seeing a player enters the readable suspicious state"),
			Hoarder->GetMonsterState(), EJMDungeonMonsterState::Suspicious);
		Hoarder->TickBehaviorTreeDecision(EJMDungeonMonsterState::Suspicious);
		TestEqual(TEXT("Visible player becomes a committed chase target after the alert"),
			Hoarder->GetMonsterState(), EJMDungeonMonsterState::Chase);

		Player->SetActorLocation(FVector(105.0f, 0.0f, 0.0f), false, nullptr, ETeleportType::TeleportPhysics);
		Hoarder->HandleSightStimulus(Player, true, Player->GetActorLocation());
		Hoarder->TickBehaviorTreeDecision(EJMDungeonMonsterState::Chase);
		TestEqual(TEXT("Capsule contact enters attack warning instead of a harmless movement stop"),
			Hoarder->GetMonsterState(), EJMDungeonMonsterState::AttackWarning);
		Hoarder->TickBehaviorTreeDecision(EJMDungeonMonsterState::AttackWarning);
		TestEqual(TEXT("Standing inside contact range through the warning catches and resets the monster"),
			Hoarder->GetMonsterState(), EJMDungeonMonsterState::Patrol);
	}

	if (World)
	{
		World->DestroyWorld(false);
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMDungeonMonsterBehaviorTreeAssetsTest,
	"JM.AI.DungeonMonster.BehaviorTreeAssets",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMDungeonMonsterBehaviorTreeAssetsTest::RunTest(const FString&)
{
	struct FExpectedTree
	{
		const TCHAR* MonsterName;
		const TCHAR* TreePath;
	};
	const FExpectedTree ExpectedTrees[] = {
		{TEXT("Listener"), TEXT("/Game/AI/Listener/BT_Listener.BT_Listener")},
		{TEXT("Hoarder"), TEXT("/Game/AI/Hoarder/BT_Hoarder.BT_Hoarder")},
		{TEXT("Blackout"), TEXT("/Game/AI/Blackout/BT_Blackout.BT_Blackout")},
	};
	const FName BlackboardKeys[] = {
		TEXT("MonsterActor"), TEXT("TargetActor"), TEXT("State"), TEXT("StateName"),
		TEXT("LastKnownLocation"), TEXT("PatrolIndex"), TEXT("PatrolPointCount"),
		TEXT("CompletedPatrolLegs"), TEXT("PatrolMode"), TEXT("IsEnabled"),
	};
	const EJMDungeonMonsterState ExpectedStates[] = {
		EJMDungeonMonsterState::Dormant, EJMDungeonMonsterState::Patrol,
		EJMDungeonMonsterState::Suspicious, EJMDungeonMonsterState::Investigate,
		EJMDungeonMonsterState::Chase, EJMDungeonMonsterState::AttackWarning,
		EJMDungeonMonsterState::Search, EJMDungeonMonsterState::Return,
	};

	for (const FExpectedTree& Expected : ExpectedTrees)
	{
		UBehaviorTree* Tree = LoadObject<UBehaviorTree>(nullptr, Expected.TreePath);
		TestNotNull(FString::Printf(TEXT("%s Behavior Tree loads"), Expected.MonsterName), Tree);
		if (!Tree)
		{
			continue;
		}
		TestNotNull(FString::Printf(TEXT("%s Blackboard is assigned"), Expected.MonsterName),
			Tree->BlackboardAsset.Get());
		TestNotNull(FString::Printf(TEXT("%s runtime root is compiled"), Expected.MonsterName),
			Tree->RootNode.Get());
		if (Tree->RootNode)
		{
			TestEqual(FString::Printf(TEXT("%s exposes all eight state tasks"), Expected.MonsterName),
				Tree->RootNode->GetChildrenNum(), 8);
			for (int32 ChildIndex = 0; ChildIndex < Tree->RootNode->GetChildrenNum(); ++ChildIndex)
			{
				const UBTTask_JMMonsterState* StateTask =
					Cast<UBTTask_JMMonsterState>(Tree->RootNode->GetChildNode(ChildIndex));
				TestTrue(FString::Printf(TEXT("%s state branch %d uses the shared executable task"),
					Expected.MonsterName, ChildIndex),
					StateTask != nullptr);
				if (StateTask && ensure(ChildIndex < UE_ARRAY_COUNT(ExpectedStates)))
				{
					TestEqual(FString::Printf(TEXT("%s state branch %d keeps its authored state"),
						Expected.MonsterName, ChildIndex), StateTask->StateToRun, ExpectedStates[ChildIndex]);
				}
			}
		}
		if (Tree->BlackboardAsset)
		{
			for (const FName Key : BlackboardKeys)
			{
				TestTrue(FString::Printf(TEXT("%s Blackboard contains %s"), Expected.MonsterName, *Key.ToString()),
					Tree->BlackboardAsset->GetKeyID(Key) != FBlackboard::InvalidKey);
			}
		}
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMDungeonMonsterNoiseRuleTest,
	"JM.AI.DungeonMonster.ListenerInvestigatesNoise",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMDungeonMonsterNoiseRuleTest::RunTest(const FString&)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
	AJMListenerMonster* Listener = World ? World->SpawnActor<AJMListenerMonster>(FVector::ZeroVector, FRotator::ZeroRotator) : nullptr;
	TestNotNull(TEXT("Listener spawns"), Listener);
	if (!Listener)
	{
		if (World)
		{
			World->DestroyWorld(false);
		}
		return false;
	}
	Listener->HandleHearingStimulus(nullptr, FVector(500, 0, 0), 0.8f);
	TestEqual(TEXT("A loud noise enters investigate instead of instant chase"),
		Listener->GetMonsterState(), EJMDungeonMonsterState::Investigate);
	TestEqual(TEXT("Listener remembers the evidence location"), Listener->GetLastKnownLocation(), FVector(500, 0, 0));
	TestTrue(TEXT("Repeated player noise has an authored escalation window"), Listener->RepeatNoiseEscalationWindow > 0.0f);
	World->DestroyWorld(false);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMBlackoutSafeLightRuleTest,
	"JM.AI.DungeonMonster.BlackoutRespectsSafeLight",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMBlackoutSafeLightRuleTest::RunTest(const FString&)
{
	UWorld* World = FAutomationEditorCommonUtils::CreateNewMap();
	AJMBlackoutLightZone* Zone = World ? World->SpawnActor<AJMBlackoutLightZone>(FVector::ZeroVector, FRotator::ZeroRotator) : nullptr;
	TestNotNull(TEXT("Safe light zone spawns"), Zone);
	if (!Zone)
	{
		return false;
	}
	TestTrue(TEXT("Center is protected"), AJMBlackoutLightZone::IsLocationProtected(World, FVector::ZeroVector));
	TestFalse(TEXT("Distant darkness is not protected"), AJMBlackoutLightZone::IsLocationProtected(World, FVector(2000, 0, 0)));
	return true;
}

#endif
