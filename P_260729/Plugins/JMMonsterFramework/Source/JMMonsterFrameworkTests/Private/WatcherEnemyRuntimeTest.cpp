#include "AI/WatcherEnemyAIController.h"
#include "Characters/SimpleEnemyCharacter.h"

#include "Components/BoxComponent.h"
#include "Components/StateTreeAIComponent.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "Misc/AutomationTest.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Hearing.h"
#include "Perception/AISense_Sight.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMWatcherEnemyRuntimeTest,
    "JM.MonsterFramework.Phase10.WatcherRuntimeGazePath",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

namespace
{
    bool HasActiveWatcherState(const UStateTreeAIComponent* StateTreeComponent, const FName StateName)
    {
        return IsValid(StateTreeComponent)
            && StateTreeComponent->GetActiveStateNames().Contains(StateName);
    }
}

bool FJMWatcherEnemyRuntimeTest::RunTest(const FString& Parameters)
{
    AddExpectedErrorPlain(TEXT("No game viewport was found."), EAutomationExpectedErrorFlags::Contains, -1);
    AddExpectedErrorPlain(
        TEXT("Script Msg called by: BP_FirstPersonCharacter"),
        EAutomationExpectedErrorFlags::Contains,
        -1);
    AddExpectedErrorPlain(TEXT("OverrideParameter(User.PathPoints)"), EAutomationExpectedErrorFlags::Contains, -1);

    UClass* WatcherClass = LoadObject<UClass>(
        nullptr,
        TEXT("/JMMonsterFramework/Blueprints/BP_WatcherEnemy.BP_WatcherEnemy_C"));
    UClass* WatcherControllerClass = LoadObject<UClass>(
        nullptr,
        TEXT("/JMMonsterFramework/AI/BP_WatcherEnemyAIController.BP_WatcherEnemyAIController_C"));
    UClass* PlayerClass = LoadObject<UClass>(
        nullptr,
        TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter.BP_FirstPersonCharacter_C"));
    TestNotNull(TEXT("Actual Watcher enemy Blueprint loads"), WatcherClass);
    TestNotNull(TEXT("Actual Watcher controller Blueprint loads"), WatcherControllerClass);
    TestNotNull(TEXT("Actual player Blueprint loads"), PlayerClass);
    if (!WatcherClass || !WatcherControllerClass || !PlayerClass)
    {
        return false;
    }

    UGameInstance* GameInstance = NewObject<UGameInstance>(GEngine);
    FWorldContext& WorldContext = GEngine->CreateNewWorldContext(EWorldType::Game);
    UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
    TestNotNull(TEXT("Watcher integration world is created"), World);
    if (!World)
    {
        GEngine->DestroyWorldContext(nullptr);
        return false;
    }
    WorldContext.OwningGameInstance = GameInstance;
    World->SetGameInstance(GameInstance);
    WorldContext.SetCurrentWorld(World);
    GameInstance->Init();
    TestNotNull(TEXT("Watcher integration world creates the real AI System"), World->CreateAISystem());
    TestTrue(TEXT("Watcher integration world creates GameMode"), World->SetGameMode(FURL()));
    World->InitializeActorsForPlay(FURL());
    World->BeginPlay();
    const uint64 InitialFrameCounter = GFrameCounter;
    const auto TickRuntimeWorld = [World]()
    {
        World->Tick(LEVELTICK_All, 0.05f);
        ++GFrameCounter;
    };
    const auto SettleCameraAndStateTree = [&TickRuntimeWorld]()
    {
        for (int32 TickIndex = 0; TickIndex < 4; ++TickIndex)
        {
            TickRuntimeWorld();
        }
    };

    const FVector WatcherLocation = FVector::ZeroVector;
    const FVector PlayerLocation(-600.0, 0.0, 0.0);
    const FRotator SpawnRotation = FRotator::ZeroRotator;
    ASimpleEnemyCharacter* Watcher = Cast<ASimpleEnemyCharacter>(
        World->SpawnActor(WatcherClass, &WatcherLocation, &SpawnRotation));
    if (Watcher && !Watcher->GetController())
    {
        Watcher->SpawnDefaultController();
    }
    AWatcherEnemyAIController* Controller = Watcher
        ? Cast<AWatcherEnemyAIController>(Watcher->GetController())
        : nullptr;
    APlayerController* PlayerController = World->SpawnActor<APlayerController>();
    ACharacter* Player = Cast<ACharacter>(World->SpawnActor(PlayerClass, &PlayerLocation, &SpawnRotation));

    TestNotNull(TEXT("Actual BP_WatcherEnemy spawns"), Watcher);
    TestNotNull(TEXT("Watcher is possessed by its actual Watcher controller"), Controller);
    TestNotNull(TEXT("Actual player Blueprint spawns"), Player);
    TestNotNull(TEXT("PlayerController spawns"), PlayerController);
    if (Watcher && Controller && Player && PlayerController)
    {
        Watcher->GetCharacterMovement()->GravityScale = 0.0f;
        Player->GetCharacterMovement()->GravityScale = 0.0f;
        PlayerController->Possess(Player);
        const auto SetActualPlayerViewYaw = [PlayerController, Player](const float Yaw)
        {
            const FRotator ViewRotation(0.0, Yaw, 0.0);
            PlayerController->SetControlRotation(ViewRotation);
            Player->SetActorRotation(ViewRotation);
        };
        SetActualPlayerViewYaw(0.0f);
        TestTrue(TEXT("Actual player is player-controlled"), Player->IsPlayerControlled());
        TestTrue(
            TEXT("Possessed controller is the configured Watcher Blueprint class"),
            Controller->IsA(WatcherControllerClass));

        UAIPerceptionComponent* Perception = Controller->GetPerceptionComponent();
        TestNotNull(TEXT("Watcher reuses the actual Perception Component"), Perception);
        TestFalse(
            TEXT("Watcher does not use Enemy-to-Player Sight as its trigger"),
            Perception && Perception->IsSenseEnabled(UAISense_Sight::StaticClass()));
        TestFalse(
            TEXT("Watcher does not use Hearing as its trigger"),
            Perception && Perception->IsSenseEnabled(UAISense_Hearing::StaticClass()));

        UStateTreeAIComponent* StateTreeComponent = Controller->FindComponentByClass<UStateTreeAIComponent>();
        TestNotNull(TEXT("Watcher runs an actual StateTree component"), StateTreeComponent);
        TestTrue(TEXT("Watcher StateTree logic is running"), StateTreeComponent && StateTreeComponent->IsRunning());

        SettleCameraAndStateTree();
        TestTrue(TEXT("Camera centered on visible Watcher produces Watched"), Controller->bPlayerIsWatchingWatcher);
        TestTrue(TEXT("Watched result reaches WatchedStop StateTree state"), HasActiveWatcherState(StateTreeComponent, TEXT("WatchedStop")));

        SetActualPlayerViewYaw(8.0f);
        SettleCameraAndStateTree();
        TestTrue(TEXT("Watcher inside the configured center angle remains Watched"), Controller->bPlayerIsWatchingWatcher);

        SetActualPlayerViewYaw(20.0f);
        SettleCameraAndStateTree();
        TestTrue(TEXT("Slightly off-center Watcher remains inside the camera view"), Controller->bPlayerIsWatchingWatcher);

        SetActualPlayerViewYaw(50.0f);
        TickRuntimeWorld();
        TestTrue(TEXT("One unstable frame does not release a watched Watcher"), Controller->bPlayerIsWatchingWatcher);
        SettleCameraAndStateTree();
        TestFalse(TEXT("Watcher outside the camera view becomes Unwatched"), Controller->bPlayerIsWatchingWatcher);
        TestTrue(TEXT("Unwatched result reaches UnwatchedMove StateTree state"), HasActiveWatcherState(StateTreeComponent, TEXT("UnwatchedMove")));

        Watcher->SetActorLocation(FVector(5000.0, 0.0, 0.0));
        SetActualPlayerViewYaw(0.0f);
        SettleCameraAndStateTree();
        TestTrue(TEXT("Distant Watcher still stops when it remains in camera view"), Controller->bPlayerIsWatchingWatcher);
        Watcher->SetActorLocation(WatcherLocation);
        SettleCameraAndStateTree();

        AActor* Wall = World->SpawnActor<AActor>();
        UBoxComponent* WallBox = Wall ? NewObject<UBoxComponent>(Wall, TEXT("WatcherVisibilityWall")) : nullptr;
        TestNotNull(TEXT("Visibility test wall spawns"), Wall);
        TestNotNull(TEXT("Visibility test wall owns a real collision component"), WallBox);
        if (Wall && WallBox)
        {
            Wall->SetRootComponent(WallBox);
            WallBox->SetBoxExtent(FVector(30.0, 150.0, 150.0));
            WallBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
            WallBox->SetCollisionResponseToAllChannels(ECR_Ignore);
            WallBox->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
            WallBox->RegisterComponent();
            Wall->SetActorLocation(FVector(-300.0, 0.0, 64.0));

            SetActualPlayerViewYaw(0.0f);
            SettleCameraAndStateTree();
            TestFalse(
                TEXT("Visibility wall rejects Watched even when camera direction matches"),
                Controller->bPlayerIsWatchingWatcher);

            WallBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
            Wall->Destroy();
            SettleCameraAndStateTree();
            TestTrue(TEXT("Removing the wall restores Watched"), Controller->bPlayerIsWatchingWatcher);
        }

        for (int32 Cycle = 0; Cycle < 20; ++Cycle)
        {
            SetActualPlayerViewYaw(90.0f);
            SettleCameraAndStateTree();
            TestFalse(FString::Printf(TEXT("Rapid cycle %d look away permits movement"), Cycle), Controller->bPlayerIsWatchingWatcher);

            SetActualPlayerViewYaw(0.0f);
            SettleCameraAndStateTree();
            TestTrue(FString::Printf(TEXT("Rapid cycle %d look back stops Watcher"), Cycle), Controller->bPlayerIsWatchingWatcher);
        }
        TestTrue(TEXT("Rapid final look reaches WatchedStop"), HasActiveWatcherState(StateTreeComponent, TEXT("WatchedStop")));

        if (StateTreeComponent && StateTreeComponent->IsRunning())
        {
            StateTreeComponent->StopLogic(TEXT("Phase 10 Watcher runtime test teardown"));
        }
    }

    World->BeginTearingDown();
    World->EndPlay(EEndPlayReason::Quit);
    GFrameCounter = InitialFrameCounter;
    GameInstance->Shutdown();
    GEngine->DestroyWorldContext(World);
    World->DestroyWorld(false);
    return !HasAnyErrors();
}

#endif
