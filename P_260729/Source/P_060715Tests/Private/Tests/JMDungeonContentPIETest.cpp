#include "Misc/AutomationTest.h"

#include "AI/Blackout/JMBlackoutMonster.h"
#include "AI/Common/JMDungeonMonster.h"
#include "AI/Listener/JMListenerMonster.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EngineUtils.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Items/InventoryItemDefinition.h"
#include "Perception/AIPerceptionComponent.h"
#include "Prototype/JMPrototypeGeneratedDungeonDirector.h"
#include "Prototype/JMPrototypePickupSpawner.h"
#include "Tests/AutomationEditorCommon.h"

#if WITH_DEV_AUTOMATION_TESTS

namespace
{
	UWorld* FindDungeonPIEWorld()
	{
		if (!GEngine)
		{
			return nullptr;
		}
		for (const FWorldContext& Context : GEngine->GetWorldContexts())
		{
			if (Context.WorldType == EWorldType::PIE)
			{
				return Context.World();
			}
		}
		return nullptr;
	}
}

class FJMVerifyDungeonContentPIECommand final : public IAutomationLatentCommand
{
public:
	explicit FJMVerifyDungeonContentPIECommand(FAutomationTestBase* InTest)
		: Test(InTest), StartedAt(FPlatformTime::Seconds())
	{
	}

	virtual bool Update() override
	{
		UWorld* World = FindDungeonPIEWorld();
		if (!World)
		{
			if (FPlatformTime::Seconds() - StartedAt <= 15.0)
			{
				return false;
			}
			Test->AddError(TEXT("Level_Mapgenerate PIE world did not start"));
			return true;
		}

		AJMPrototypeGeneratedDungeonDirector* Director = nullptr;
		for (TActorIterator<AJMPrototypeGeneratedDungeonDirector> It(World); It; ++It)
		{
			Director = *It;
			break;
		}
		if (!Director || !Director->IsDungeonPopulated())
		{
			if (FPlatformTime::Seconds() - StartedAt <= 15.0)
			{
				return false;
			}
			Test->AddError(FString::Printf(TEXT("Dungeon director did not populate: director=%d"), IsValid(Director)));
			return true;
		}
		if (World->GetTimeSeconds() < 4.0)
		{
			return false;
		}

		int32 MonsterCount = 0;
		int32 BlackoutCount = 0;
		int32 ActiveVisibleMonsterCount = 0;
		for (TActorIterator<AJMDungeonMonster> It(World); It; ++It)
		{
			++MonsterCount;
			const AAIController* Controller = Cast<AAIController>(It->GetController());
			const UBehaviorTreeComponent* BehaviorTree = Controller
				? Cast<UBehaviorTreeComponent>(Controller->GetBrainComponent()) : nullptr;
			Test->TestNotNull(FString::Printf(TEXT("%s owns a Behavior Tree component"), *It->GetName()),
				BehaviorTree);
			if (BehaviorTree)
			{
				Test->TestTrue(FString::Printf(TEXT("%s Behavior Tree is running"), *It->GetName()),
					BehaviorTree->IsRunning());
				const UBlackboardComponent* Blackboard = BehaviorTree->GetBlackboardComponent();
				Test->TestNotNull(FString::Printf(TEXT("%s owns its Blackboard"), *It->GetName()), Blackboard);
				if (Blackboard)
				{
					Test->TestEqual(FString::Printf(TEXT("%s Blackboard points to its monster"), *It->GetName()),
						Blackboard->GetValueAsObject(TEXT("MonsterActor")), static_cast<UObject*>(*It));
					Test->TestEqual(FString::Printf(TEXT("%s Blackboard reports three patrol POIs"), *It->GetName()),
						Blackboard->GetValueAsInt(TEXT("PatrolPointCount")), 3);
				}
			}
			Test->TestEqual(TEXT("Every spawned monster receives three room-authored patrol points"),
				It->GetAuthoredPatrolPointCount(), 3);
			if (const AJMBlackoutMonster* Blackout = Cast<AJMBlackoutMonster>(*It))
			{
				++BlackoutCount;
				Test->TestEqual(TEXT("Blackout remains dormant during its telegraph delay"),
					Blackout->GetMonsterState(), EJMDungeonMonsterState::Dormant);
			}
			else if (It->GetMonsterState() != EJMDungeonMonsterState::Dormant && !It->IsHidden())
			{
				++ActiveVisibleMonsterCount;
			}
		}

		const UInventoryItemDefinition* BatteryDefinition = LoadObject<UInventoryItemDefinition>(nullptr,
			TEXT("/Game/Prototype/Data/Items/DA_Item_EmergencyBattery.DA_Item_EmergencyBattery"));
		int32 PickupSpawnerCount = 0;
		int32 BatterySpawnerCount = 0;
		for (TActorIterator<AJMPrototypePickupSpawner> It(World); It; ++It)
		{
			++PickupSpawnerCount;
			if (It->ItemDefinition == BatteryDefinition)
			{
				++BatterySpawnerCount;
			}
		}

		Test->TestEqual(TEXT("Roster creates the three planned monster types"), MonsterCount, 3);
		Test->TestEqual(TEXT("Roster creates one delayed Blackout monster"), BlackoutCount, 1);
		Test->TestEqual(TEXT("Listener and Hoarder activate visibly after runtime navigation is ready"),
			ActiveVisibleMonsterCount, 2);
		Test->TestTrue(TEXT("At least the guaranteed authored item slot spawns"), PickupSpawnerCount >= 1);
		Test->TestEqual(TEXT("EmergencyBattery unique group resolves to exactly one room marker"), BatterySpawnerCount, 1);
		return true;
	}

private:
	FAutomationTestBase* Test = nullptr;
	double StartedAt = 0.0;
};

class FJMVerifyContinuousPatrolPIECommand final : public IAutomationLatentCommand
{
public:
	explicit FJMVerifyContinuousPatrolPIECommand(FAutomationTestBase* InTest)
		: Test(InTest)
	{
	}

	virtual bool Update() override
	{
		UWorld* World = FindDungeonPIEWorld();
		if (!World)
		{
			Test->AddError(TEXT("PIE world ended before the continuous patrol check"));
			return true;
		}

		if (!bStarted)
		{
			for (TActorIterator<AJMListenerMonster> It(World); It; ++It)
			{
				Listener = *It;
				break;
			}
			if (!Listener.IsValid())
			{
				Test->AddError(TEXT("Continuous patrol check could not find Listener"));
				return true;
			}
			if (AAIController* Controller = Cast<AAIController>(Listener->GetController()))
			{
				if (UAIPerceptionComponent* Perception = Controller->GetPerceptionComponent())
				{
					Perception->Deactivate();
				}
			}
			Listener->PatrolSpeed = 12000.0f;
			Listener->GetCharacterMovement()->MaxAcceleration = 100000.0f;
			Listener->ResetMonster();
			InitialCompletedLegs = Listener->GetCompletedPatrolLegCount();
			ObservationStartedAt = FPlatformTime::Seconds();
			bStarted = true;
			return false;
		}

		if (FPlatformTime::Seconds() - ObservationStartedAt < 8.0)
		{
			return false;
		}

		const int32 CompletedDuringObservation = Listener.IsValid()
			? Listener->GetCompletedPatrolLegCount() - InitialCompletedLegs : 0;
		Test->TestTrue(TEXT("Listener keeps patrolling after completing and wrapping its three-point route"),
			CompletedDuringObservation >= 4);
		return true;
	}

private:
	FAutomationTestBase* Test = nullptr;
	TWeakObjectPtr<AJMListenerMonster> Listener;
	double ObservationStartedAt = 0.0;
	int32 InitialCompletedLegs = 0;
	bool bStarted = false;
};

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMDungeonContentPIETest,
	"JM.Dungeon.Content.LevelMapgeneratePIE",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMDungeonContentPIETest::RunTest(const FString&)
{
	FAutomationEditorCommonUtils::LoadMap(TEXT("/Game/Level/Level_Mapgenerate"));
	ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(false));
	ADD_LATENT_AUTOMATION_COMMAND(FJMVerifyDungeonContentPIECommand(this));
	ADD_LATENT_AUTOMATION_COMMAND(FJMVerifyContinuousPatrolPIECommand(this));
	ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand());
	return true;
}

#endif
