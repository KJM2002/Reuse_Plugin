#include "AI/SimpleEnemyAIController.h"
#include "Characters/SimpleEnemyCharacter.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMSimpleEnemyDefaultsTest,
    "JM.MonsterFramework.Phase0.SimpleEnemyDefaults",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMSimpleEnemyDefaultsTest::RunTest(const FString& Parameters)
{
    const ASimpleEnemyCharacter* Enemy = GetDefault<ASimpleEnemyCharacter>();

    TestNotNull(TEXT("Simple enemy has an inherited capsule"), Enemy->GetCapsuleComponent());
    TestNotNull(TEXT("Simple enemy has an inherited mesh"), Enemy->GetMesh());
    TestNotNull(TEXT("Simple enemy has an inherited character movement component"), Enemy->GetCharacterMovement());
    TestEqual(
        TEXT("Simple enemy uses the Phase 0 AI controller"),
        Enemy->AIControllerClass.Get(),
        ASimpleEnemyAIController::StaticClass());
    TestEqual(
        TEXT("Placed and runtime-spawned enemies request AI possession"),
        Enemy->AutoPossessAI,
        EAutoPossessAI::PlacedInWorldOrSpawned);
    TestEqual(
        TEXT("The default land movement mode is walking"),
        Enemy->GetCharacterMovement()->DefaultLandMovementMode,
        MOVE_Walking);

    const ASimpleEnemyAIController* Controller = GetDefault<ASimpleEnemyAIController>();
    TestEqual(TEXT("Recent tracking lasts 1.5 seconds"), Controller->TrackingMemoryDuration, 1.5f);
    TestEqual(TEXT("Recent tracking prediction is capped at 700uu"), Controller->MaximumPredictionDistance, 700.0f);
    TestEqual(TEXT("Live Grace tracking lasts 1.5 seconds"), Controller->LiveGraceDuration, 1.5f);
    TestEqual(TEXT("Basic attack range is 150uu"), Controller->AttackRange, 150.0f);
    TestEqual(TEXT("Basic attack cooldown is one second"), Controller->AttackCooldown, 1.0f);
    TestEqual(TEXT("Basic attack damage is ten"), Controller->Damage, 10.0f);

    return true;
}

#endif
