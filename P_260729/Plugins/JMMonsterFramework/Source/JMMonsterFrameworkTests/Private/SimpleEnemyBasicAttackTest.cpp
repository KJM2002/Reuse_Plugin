#include "AI/SimpleEnemyAIController.h"
#include "Characters/SimpleEnemyCharacter.h"

#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMSimpleEnemyBasicAttackTest,
    "JM.MonsterFramework.Phase6.BasicAttackRangeAndCooldown",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMSimpleEnemyBasicAttackTest::RunTest(const FString& Parameters)
{
    UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
    ASimpleEnemyCharacter* Enemy = World
        ? World->SpawnActor<ASimpleEnemyCharacter>(FVector::ZeroVector, FRotator::ZeroRotator)
        : nullptr;
    ACharacter* Target = World
        ? World->SpawnActor<ACharacter>(FVector(300.0f, 0.0f, 0.0f), FRotator::ZeroRotator)
        : nullptr;
    ASimpleEnemyAIController* Controller = World
        ? World->SpawnActor<ASimpleEnemyAIController>()
        : nullptr;

    TestNotNull(TEXT("Attack test Enemy spawns"), Enemy);
    TestNotNull(TEXT("Attack test Target spawns"), Target);
    TestNotNull(TEXT("Attack test Controller spawns"), Controller);
    if (Enemy && Target && Controller)
    {
        Controller->Possess(Enemy);
        Controller->EnemyMemory.TargetActor = Target;
        Controller->EnemyMemory.bCanSeeTarget = true;

        TestFalse(TEXT("Target outside 150uu is not in attack range"), Controller->IsTargetInAttackRange());
        TestFalse(TEXT("Target outside range cannot be damaged"), Controller->PerformBasicAttack());
        TestEqual(TEXT("Rejected attack does not start cooldown"), Controller->LastBasicAttackTime, -1.0f);

        Target->SetActorLocation(FVector(100.0f, 0.0f, 0.0f));
        TestTrue(TEXT("Visible target inside 150uu is in attack range"), Controller->IsTargetInAttackRange());
        TestTrue(TEXT("First in-range attack succeeds"), Controller->PerformBasicAttack());
        const float FirstAttackTime = Controller->LastBasicAttackTime;
        TestTrue(TEXT("Successful attack records cooldown time"), FirstAttackTime >= 0.0f);
        TestFalse(TEXT("Immediate second attack is blocked by cooldown"), Controller->PerformBasicAttack());
        TestEqual(TEXT("Blocked attack cannot reset cooldown"), Controller->LastBasicAttackTime, FirstAttackTime);

        Target->SetActorLocation(FVector(300.0f, 0.0f, 0.0f));
        TestFalse(TEXT("Moving out of range disables Attack again"), Controller->IsTargetInAttackRange());
    }

    if (World)
    {
        World->DestroyWorld(false);
    }
    return !HasAnyErrors();
}

#endif
