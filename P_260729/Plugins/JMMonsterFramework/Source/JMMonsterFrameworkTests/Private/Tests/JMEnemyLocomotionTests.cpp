#include "Misc/AutomationTest.h"

#include "Core/JMEnemyDefinition.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Locomotion/JMEnemyLocomotionComponent.h"
#include "Locomotion/JMEnemyMovementSet.h"
#include "Tests/JMEnemyCoreTestTypes.h"
#include "Misc/DataValidation.h"
#include "UObject/StrongObjectPtr.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMEnemyMovementProfileTest,
    "JM.MonsterFramework.Locomotion.MovementProfiles",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyMovementProfileTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMEnemyMovementSet> Set(NewObject<UJMEnemyMovementSet>());
    FJMEnemyMovementProfile Normal;
    Normal.ProfileName = TEXT("Normal");
    Normal.MaxSpeed = 240.0f;
    Normal.MaxAcceleration = 900.0f;
    Normal.RotationRate = FRotator(0.0, 270.0, 0.0);
    Normal.AcceptanceRadius = 60.0f;
    Set->Profiles.Add(Normal);

    FJMEnemyMovementProfile Fast = Normal;
    Fast.ProfileName = TEXT("Fast");
    Fast.MaxSpeed = 600.0f;
    Set->Profiles.Add(Fast);

    FJMEnemyMovementProfile Found;
    TestTrue(TEXT("Named profile lookup succeeds"), Set->GetProfile(TEXT("Fast"), Found));
    TestEqual(TEXT("Lookup returns the requested profile"), Found.ProfileName, FName(TEXT("Fast")));
    TestEqual(TEXT("Profile values are retained"), Found.MaxSpeed, 600.0f);
    TestFalse(TEXT("Unknown profile lookup fails cleanly"), Set->GetProfile(TEXT("Missing"), Found));

    TStrongObjectPtr<UJMEnemyDefinition> Definition(NewObject<UJMEnemyDefinition>());
    Definition->MovementSet = Set.Get();
    Definition->DefaultMovementProfile = TEXT("Normal");
    FDataValidationContext ValidContext;
    TestEqual(TEXT("Configured default profile validates"),
        Definition->IsDataValid(ValidContext), EDataValidationResult::Valid);

    Definition->DefaultMovementProfile = TEXT("Missing");
    FDataValidationContext InvalidContext;
    TestEqual(TEXT("Missing default profile is rejected during authoring validation"),
        Definition->IsDataValid(InvalidContext), EDataValidationResult::Invalid);
    Definition->DefaultMovementProfile = TEXT("Normal");

    TStrongObjectPtr<AJMEnemyCoreTestEnemy> Enemy(NewObject<AJMEnemyCoreTestEnemy>());
    UJMEnemyLocomotionComponent* Locomotion = Enemy->GetEnemyLocomotionComponent();
    TestTrue(TEXT("A valid profile applies to CharacterMovement"),
        Locomotion->ApplyMovementProfile(Set.Get(), TEXT("Normal")));
    TestEqual(TEXT("Current profile is queryable"),
        Locomotion->GetCurrentMovementProfile(), FName(TEXT("Normal")));
    TestEqual(TEXT("Max speed is applied"), Enemy->GetCharacterMovement()->MaxWalkSpeed, 240.0f);
    TestEqual(TEXT("Acceleration is applied"), Enemy->GetCharacterMovement()->MaxAcceleration, 900.0f);
    TestFalse(TEXT("Invalid profile does not replace the active profile"),
        Locomotion->ApplyMovementProfile(Set.Get(), TEXT("Missing")));
    TestEqual(TEXT("Active profile remains unchanged after failure"),
        Locomotion->GetCurrentMovementProfile(), FName(TEXT("Normal")));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMEnemyLocomotionSafetyTest,
    "JM.MonsterFramework.Locomotion.SafeFailures",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyLocomotionSafetyTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMEnemyLocomotionComponent> Locomotion(NewObject<UJMEnemyLocomotionComponent>());
    TStrongObjectPtr<UJMEnemyLocomotionTestListener> Listener(NewObject<UJMEnemyLocomotionTestListener>());
    Locomotion->OnMoveFinished.AddDynamic(Listener.Get(), &UJMEnemyLocomotionTestListener::HandleMoveFinished);

    TestEqual(TEXT("Initial movement status is Idle"), Locomotion->GetMoveStatus(), EJMEnemyMoveStatus::Idle);
    TestFalse(TEXT("Initial request id is invalid"), Locomotion->GetCurrentRequestID().IsValid());
    TestEqual(TEXT("Missing owner/controller fails without navigation access"),
        Locomotion->MoveToLocation(FVector(100.0, 0.0, 0.0), FJMEnemyMoveOptions()),
        EJMEnemyMoveRequestResult::RequestFailed);
    TestEqual(TEXT("Failure status is normalized"), Locomotion->GetMoveStatus(), EJMEnemyMoveStatus::Failed);
    TestEqual(TEXT("Failed request emits one completion"), Listener->CallCount, 1);
    TestEqual(TEXT("Completion reports Failed"), Listener->LastResult, EJMEnemyMoveStatus::Failed);
    TestEqual(TEXT("Invalid target fails safely"),
        Locomotion->MoveToActor(nullptr, FJMEnemyMoveOptions()), EJMEnemyMoveRequestResult::RequestFailed);
    Locomotion->StopMovement();
    Locomotion->ClearFacingFocus();
    TestFalse(TEXT("Locomotion never ticks"), Locomotion->PrimaryComponentTick.bCanEverTick);
    return true;
}
