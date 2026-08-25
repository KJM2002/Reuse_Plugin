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

    return true;
}

#endif
