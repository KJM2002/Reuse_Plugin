#include "AI/SimpleEnemyAIController.h"
#include "Characters/SimpleEnemyCharacter.h"

#include "Engine/Engine.h"
#include "Engine/Blueprint.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Components/StateTreeAIComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Misc/AutomationTest.h"
#include "Perception/AIPerceptionSystem.h"
#include "Perception/AISense_Hearing.h"
#include "Perception/AISense_Sight.h"
#include "UObject/UnrealType.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMSimpleEnemyMemoryRuntimeTest,
    "JM.MonsterFramework.Phase8.RuntimeMemoryPath",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMSimpleEnemyMemoryRuntimeTest::RunTest(const FString& Parameters)
{
    AddExpectedErrorPlain(
        TEXT("No game viewport was found."),
        EAutomationExpectedErrorFlags::Contains,
        -1);
    AddExpectedErrorPlain(
        TEXT("Script Msg called by: BP_FirstPersonCharacter"),
        EAutomationExpectedErrorFlags::Contains,
        -1);
    AddExpectedErrorPlain(
        TEXT("OverrideParameter(User.PathPoints)"),
        EAutomationExpectedErrorFlags::Contains,
        -1);

    constexpr const TCHAR* BlueprintAssets[] =
    {
        TEXT("/JMMonsterFramework/AI/BP_SimpleEnemyAIController.BP_SimpleEnemyAIController"),
        TEXT("/JMMonsterFramework/AI/BP_SimpleEnemyAIController_LiveGrace.BP_SimpleEnemyAIController_LiveGrace"),
        TEXT("/JMMonsterFramework/Blueprints/BP_SimpleEnemy.BP_SimpleEnemy"),
        TEXT("/JMMonsterFramework/Blueprints/BP_SimpleEnemy_LiveGrace.BP_SimpleEnemy_LiveGrace")
    };
    for (const TCHAR* BlueprintPath : BlueprintAssets)
    {
        UBlueprint* Blueprint = LoadObject<UBlueprint>(nullptr, BlueprintPath);
        TestNotNull(FString::Printf(TEXT("Blueprint loads: %s"), BlueprintPath), Blueprint);
        if (Blueprint)
        {
            FKismetEditorUtilities::CompileBlueprint(Blueprint);
            TestEqual(
                FString::Printf(TEXT("Blueprint compiles without stale native property references: %s"), BlueprintPath),
                Blueprint->Status,
                BS_UpToDate);
        }
    }

    UClass* EnemyClass = LoadObject<UClass>(
        nullptr,
        TEXT("/JMMonsterFramework/Blueprints/BP_SimpleEnemy.BP_SimpleEnemy_C"));
    UClass* ControllerClass = LoadObject<UClass>(
        nullptr,
        TEXT("/JMMonsterFramework/AI/BP_SimpleEnemyAIController.BP_SimpleEnemyAIController_C"));
    UClass* PlayerClass = LoadObject<UClass>(
        nullptr,
        TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter.BP_FirstPersonCharacter_C"));

    TestNotNull(TEXT("Runtime enemy Blueprint class loads"), EnemyClass);
    TestNotNull(TEXT("Runtime controller Blueprint class loads"), ControllerClass);
    TestNotNull(TEXT("Runtime player Blueprint class loads"), PlayerClass);
    if (!EnemyClass || !ControllerClass || !PlayerClass)
    {
        return false;
    }

    TestNull(
        TEXT("Controller Blueprint no longer exposes legacy TargetActor property"),
        FindFProperty<FProperty>(ControllerClass, TEXT("TargetActor")));
    TestNull(
        TEXT("Controller Blueprint no longer exposes legacy bCanSeeTarget property"),
        FindFProperty<FProperty>(ControllerClass, TEXT("bCanSeeTarget")));
    TestNull(
        TEXT("Controller Blueprint no longer exposes legacy LastHeardLocation property"),
        FindFProperty<FProperty>(ControllerClass, TEXT("LastHeardLocation")));
    TestNotNull(
        TEXT("Controller Blueprint exposes the single EnemyMemory property"),
        FindFProperty<FProperty>(ControllerClass, TEXT("EnemyMemory")));

    UGameInstance* GameInstance = NewObject<UGameInstance>(GEngine);
    FWorldContext& WorldContext = GEngine->CreateNewWorldContext(EWorldType::Game);
    UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
    TestNotNull(TEXT("Runtime integration world is created"), World);
    if (!World)
    {
        GEngine->DestroyWorldContext(nullptr);
        return false;
    }
    WorldContext.OwningGameInstance = GameInstance;
    World->SetGameInstance(GameInstance);
    WorldContext.SetCurrentWorld(World);
    GameInstance->Init();
    TestNotNull(TEXT("Runtime integration world creates the real AI System"), World->CreateAISystem());
    TestTrue(TEXT("Runtime integration world creates its configured GameMode"), World->SetGameMode(FURL()));
    World->InitializeActorsForPlay(FURL());
    World->BeginPlay();

    const FVector EnemyLocation = FVector::ZeroVector;
    const FVector HearingPlayerLocation(-400.0, 0.0, 0.0);
    const FRotator SpawnRotation = FRotator::ZeroRotator;
    ASimpleEnemyCharacter* Enemy = Cast<ASimpleEnemyCharacter>(
        World->SpawnActor(EnemyClass, &EnemyLocation, &SpawnRotation));
    if (Enemy && !Enemy->GetController())
    {
        Enemy->SpawnDefaultController();
    }
    ASimpleEnemyAIController* Controller = Enemy
        ? Cast<ASimpleEnemyAIController>(Enemy->GetController())
        : nullptr;
    APlayerController* PlayerController = World->SpawnActor<APlayerController>();
    ACharacter* Player = Cast<ACharacter>(
        World->SpawnActor(PlayerClass, &HearingPlayerLocation, &SpawnRotation));

    TestNotNull(TEXT("Actual BP_SimpleEnemy spawns"), Enemy);
    TestNotNull(TEXT("Actual BP_SimpleEnemyAIController spawns"), Controller);
    TestNotNull(TEXT("Actual player Blueprint spawns"), Player);
    TestNotNull(TEXT("PlayerController spawns"), PlayerController);
    if (Enemy && Controller && Player && PlayerController)
    {
        PlayerController->Possess(Player);
        TestTrue(TEXT("Actual player Blueprint is player-controlled"), Player->IsPlayerControlled());
        TestTrue(
            TEXT("Actual player registers as an AI Sight stimulus source"),
            UAIPerceptionSystem::RegisterPerceptionStimuliSource(
                World,
                UAISense_Sight::StaticClass(),
                Player));

        UAISense_Hearing::ReportNoiseEvent(
            World,
            Player->GetActorLocation(),
            1.0f,
            Player,
            0.0f,
            TEXT("Phase8.RuntimeHearing"));
        for (int32 TickIndex = 0; TickIndex < 10; ++TickIndex)
        {
            World->Tick(LEVELTICK_All, 0.1f);
        }

        TestTrue(
            TEXT("Report Noise Event reaches EnemyMemory through actual AI Hearing"),
            Controller->EnemyMemory.bHasHeardSound);
        TestEqual(
            TEXT("Actual Hearing stores the reported runtime location"),
            Controller->EnemyMemory.LastHeardLocation,
            Player->GetActorLocation());

        Controller->ClearHeardSound();
        Player->SetActorLocation(FVector(400.0, 0.0, 0.0));
        for (int32 TickIndex = 0; TickIndex < 20; ++TickIndex)
        {
            World->Tick(LEVELTICK_All, 0.1f);
        }

        TestTrue(
            TEXT("Actual AI Sight updates EnemyMemory through perception callback"),
            Controller->EnemyMemory.bCanSeeTarget);
        TestEqual(
            TEXT("Actual AI Sight stores the player target in EnemyMemory"),
            Controller->EnemyMemory.TargetActor.Get(),
            static_cast<AActor*>(Player));
    }

    if (Controller && Controller->StateTreeComponent && Controller->StateTreeComponent->IsRunning())
    {
        Controller->StateTreeComponent->StopLogic(TEXT("Phase 8 runtime test teardown"));
    }
    World->BeginTearingDown();
    World->EndPlay(EEndPlayReason::Quit);
    GameInstance->Shutdown();
    GEngine->DestroyWorldContext(World);
    World->DestroyWorld(false);
    return !HasAnyErrors();
}

#endif
