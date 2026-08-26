#include "AI/SimpleEnemyAIController.h"
#include "Characters/SimpleEnemyCharacter.h"

#include "AITypes.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Misc/AutomationTest.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Hearing.h"
#include "UObject/StrongObjectPtr.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMSimpleEnemyHearingStateTest,
    "JM.MonsterFramework.Phase7.HearingState",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMSimpleEnemyHearingStateTest::RunTest(const FString& Parameters)
{
    UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
    UClass* BlueprintControllerClass = LoadObject<UClass>(
        nullptr,
        TEXT("/JMMonsterFramework/AI/BP_SimpleEnemyAIController.BP_SimpleEnemyAIController_C"));
    ASimpleEnemyCharacter* BlueprintEnemy = World
        ? World->SpawnActor<ASimpleEnemyCharacter>()
        : nullptr;
    ASimpleEnemyAIController* BlueprintController = World && BlueprintControllerClass
        ? World->SpawnActor<ASimpleEnemyAIController>(BlueprintControllerClass)
        : nullptr;

    TestNotNull(TEXT("Predictive Blueprint controller class loads"), BlueprintControllerClass);
    TestNotNull(TEXT("Runtime Blueprint enemy spawns"), BlueprintEnemy);
    TestNotNull(TEXT("Runtime Blueprint controller spawns"), BlueprintController);
    if (BlueprintEnemy && BlueprintController)
    {
        BlueprintController->Possess(BlueprintEnemy);
        const UAIPerceptionComponent* BlueprintPerception = BlueprintController->GetPerceptionComponent();
        TestNotNull(TEXT("Blueprint controller owns AI Perception"), BlueprintPerception);
        TestNotNull(
            TEXT("Possess restores Hearing removed by stale Blueprint SensesConfig"),
            BlueprintPerception
                ? BlueprintPerception->GetSenseConfig(UAISense::GetSenseID<UAISense_Hearing>())
                : nullptr);
    }

    if (World)
    {
        World->DestroyWorld(false);
    }

    TStrongObjectPtr<ASimpleEnemyAIController> Controller(NewObject<ASimpleEnemyAIController>());
    TStrongObjectPtr<AActor> SoundSource(NewObject<AActor>());
    TStrongObjectPtr<AActor> VisibleTarget(NewObject<AActor>());

    const FVector HeardLocation(400.0f, 250.0f, 0.0f);
    const FVector IgnoredLocation(900.0f, 900.0f, 0.0f);

    const UAIPerceptionComponent* Perception = Controller->GetPerceptionComponent();
    TestNotNull(TEXT("Controller owns an AI Perception component"), Perception);
    TestNotNull(
        TEXT("Runtime Perception listener contains Hearing configuration"),
        Perception ? Perception->GetSenseConfig(UAISense::GetSenseID<UAISense_Hearing>()) : nullptr);

    TestFalse(TEXT("Hearing memory starts empty"), Controller->EnemyMemory.bHasHeardSound);
    Controller->ApplyHearingState(SoundSource.Get(), false, HeardLocation);
    TestFalse(TEXT("Unsuccessful Hearing stimulus is ignored"), Controller->EnemyMemory.bHasHeardSound);

    Controller->ApplyHearingState(SoundSource.Get(), true, FAISystem::InvalidLocation);
    TestFalse(TEXT("Invalid Hearing location is ignored"), Controller->EnemyMemory.bHasHeardSound);

    Controller->ApplyHearingState(SoundSource.Get(), true, HeardLocation);
    TestTrue(TEXT("Valid Hearing stimulus creates one pending sound"), Controller->EnemyMemory.bHasHeardSound);
    TestEqual(TEXT("Valid Hearing stimulus stores its location"), Controller->EnemyMemory.LastHeardLocation, HeardLocation);
    TestFalse(TEXT("Hearing alone never enables Sight"), Controller->EnemyMemory.bCanSeeTarget);
    TestNull(TEXT("Hearing alone never assigns the Sight target"), Controller->EnemyMemory.TargetActor.Get());

    Controller->EnemyMemory.bCanSeeTarget = true;
    Controller->ApplyHearingState(SoundSource.Get(), true, IgnoredLocation);
    TestEqual(TEXT("Sight priority prevents Hearing memory replacement"), Controller->EnemyMemory.LastHeardLocation, HeardLocation);

    Controller->EnemyMemory.bCanSeeTarget = false;
    Controller->ApplySightState(VisibleTarget.Get(), true, FVector::ZeroVector, FVector::ZeroVector);
    TestFalse(TEXT("Sight acquisition consumes pending Hearing memory"), Controller->EnemyMemory.bHasHeardSound);
    TestTrue(TEXT("Sight acquisition remains active"), Controller->EnemyMemory.bCanSeeTarget);
    TestEqual(TEXT("Sight acquisition owns TargetActor"), Controller->EnemyMemory.TargetActor.Get(), VisibleTarget.Get());

    return true;
}

#endif
