#include "AI/Blackout/JMBlackoutLightZone.h"
#include "AI/Blackout/JMBlackoutMonster.h"
#include "AI/Common/JMMonsterBehaviorTreeNodes.h"
#include "AI/Hoarder/JMHoarderMonster.h"
#include "AI/Listener/JMListenerMonster.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "Components/StaticMeshComponent.h"
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
	TestTrue(TEXT("Patrol advance radius is larger than path acceptance radius"),
		Listener->PatrolPointAdvanceRadius > Listener->PatrolMoveAcceptanceRadius);
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
