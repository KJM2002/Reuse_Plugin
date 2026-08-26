#include "AI/ListenerEnemyAIController.h"
#include "Characters/SimpleEnemyCharacter.h"

#include "Components/StateTreeAIComponent.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"
#include "Misc/AutomationTest.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AIPerceptionSystem.h"
#include "Perception/AISense.h"
#include "Perception/AISense_Hearing.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Perception/AISenseConfig_Sight.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMListenerEnemyRuntimeTest,
    "JM.MonsterFramework.Phase9.ListenerRuntimePath",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

namespace
{
    bool HasActiveListenerState(const UStateTreeAIComponent* StateTreeComponent, const FName StateName)
    {
        return IsValid(StateTreeComponent)
            && StateTreeComponent->GetActiveStateNames().Contains(StateName);
    }
}

bool FJMListenerEnemyRuntimeTest::RunTest(const FString& Parameters)
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

    UClass* ListenerClass = LoadObject<UClass>(
        nullptr,
        TEXT("/JMMonsterFramework/Blueprints/BP_ListenerEnemy.BP_ListenerEnemy_C"));
    UClass* ListenerControllerClass = LoadObject<UClass>(
        nullptr,
        TEXT("/JMMonsterFramework/AI/BP_ListenerEnemyAIController.BP_ListenerEnemyAIController_C"));
    UClass* PlayerClass = LoadObject<UClass>(
        nullptr,
        TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter.BP_FirstPersonCharacter_C"));
    TestNotNull(TEXT("Actual Listener enemy Blueprint loads"), ListenerClass);
    TestNotNull(TEXT("Actual Listener controller Blueprint loads"), ListenerControllerClass);
    TestNotNull(TEXT("Actual player Blueprint loads"), PlayerClass);
    if (!ListenerClass || !ListenerControllerClass || !PlayerClass)
    {
        return false;
    }

    UGameInstance* GameInstance = NewObject<UGameInstance>(GEngine);
    FWorldContext& WorldContext = GEngine->CreateNewWorldContext(EWorldType::Game);
    UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
    TestNotNull(TEXT("Listener integration world is created"), World);
    if (!World)
    {
        GEngine->DestroyWorldContext(nullptr);
        return false;
    }
    WorldContext.OwningGameInstance = GameInstance;
    World->SetGameInstance(GameInstance);
    WorldContext.SetCurrentWorld(World);
    GameInstance->Init();
    TestNotNull(TEXT("Listener integration world creates the real AI System"), World->CreateAISystem());
    TestTrue(TEXT("Listener integration world creates GameMode"), World->SetGameMode(FURL()));
    World->InitializeActorsForPlay(FURL());
    World->BeginPlay();
    const uint64 InitialFrameCounter = GFrameCounter;
    const auto TickRuntimeWorld = [World]()
    {
        World->Tick(LEVELTICK_All, 0.1f);
        ++GFrameCounter;
    };

    const FVector ListenerLocation = FVector::ZeroVector;
    const FVector VisiblePlayerLocation(600.0, 0.0, 0.0);
    const FRotator SpawnRotation = FRotator::ZeroRotator;
    ASimpleEnemyCharacter* Listener = Cast<ASimpleEnemyCharacter>(
        World->SpawnActor(ListenerClass, &ListenerLocation, &SpawnRotation));
    if (Listener && !Listener->GetController())
    {
        Listener->SpawnDefaultController();
    }
    AListenerEnemyAIController* Controller = Listener
        ? Cast<AListenerEnemyAIController>(Listener->GetController())
        : nullptr;
    APlayerController* PlayerController = World->SpawnActor<APlayerController>();
    ACharacter* Player = Cast<ACharacter>(
        World->SpawnActor(PlayerClass, &VisiblePlayerLocation, &SpawnRotation));

    TestNotNull(TEXT("Actual BP_ListenerEnemy spawns"), Listener);
    TestNotNull(TEXT("Listener is possessed by its actual Listener controller"), Controller);
    TestNotNull(TEXT("Actual player Blueprint spawns"), Player);
    TestNotNull(TEXT("PlayerController spawns"), PlayerController);
    if (Listener && Controller && Player && PlayerController)
    {
        TestTrue(
            TEXT("Possessed controller is the configured Listener Blueprint class"),
            Controller->IsA(ListenerControllerClass));
        UAIPerceptionComponent* Perception = Controller->GetPerceptionComponent();
        TestNotNull(TEXT("Listener owns the actual Perception Component"), Perception);
        TestTrue(
            TEXT("Listener Hearing is enabled after Blueprint possession"),
            Perception && Perception->IsSenseEnabled(UAISense_Hearing::StaticClass()));
        const UAISenseConfig_Hearing* HearingConfig = Perception
            ? Cast<UAISenseConfig_Hearing>(
                Perception->GetSenseConfig(UAISense::GetSenseID<UAISense_Hearing>()))
            : nullptr;
        TestNotNull(TEXT("Listener runtime Perception contains Hearing config"), HearingConfig);
        if (HearingConfig)
        {
            TestEqual(TEXT("Listener runtime Hearing range remains 2500uu"), HearingConfig->HearingRange, 2500.0f);
        }
        const UAISenseConfig_Sight* SightConfig = Perception
            ? Cast<UAISenseConfig_Sight>(
                Perception->GetSenseConfig(UAISense::GetSenseID<UAISense_Sight>()))
            : nullptr;
        TestNotNull(TEXT("Listener runtime Perception preserves Sight config"), SightConfig);
        TestFalse(
            TEXT("Listener Sight is disabled during normal Patrol"),
            Perception && Perception->IsSenseEnabled(UAISense_Sight::StaticClass()));

        UStateTreeAIComponent* StateTreeComponent = Controller->FindComponentByClass<UStateTreeAIComponent>();
        TestNotNull(TEXT("Listener runs an actual StateTree component"), StateTreeComponent);
        TestTrue(TEXT("Listener StateTree logic is running"), StateTreeComponent && StateTreeComponent->IsRunning());

        PlayerController->Possess(Player);
        TestTrue(TEXT("Actual player is player-controlled"), Player->IsPlayerControlled());
        TestTrue(
            TEXT("Actual player registers as a Sight source"),
            UAIPerceptionSystem::RegisterPerceptionStimuliSource(
                World,
                UAISense_Sight::StaticClass(),
                Player));

        for (int32 TickIndex = 0; TickIndex < 5; ++TickIndex)
        {
            TickRuntimeWorld();
        }
        TestFalse(TEXT("No Noise creates no Hearing memory"), Controller->EnemyMemory.bHasHeardSound);
        TestFalse(TEXT("Visible player creates no Sight memory before Noise"), Controller->EnemyMemory.bCanSeeTarget);
        TestNull(TEXT("Listener does not know the visible player's Actor before Noise"), Controller->EnemyMemory.TargetActor.Get());

        const FVector NoiseA(-500.0, 100.0, 0.0);
        const FVector NoiseB(-300.0, -200.0, 0.0);
        UAISense_Hearing::ReportNoiseEvent(
            World,
            NoiseA,
            0.5f,
            Player,
            0.0f,
            TEXT("Phase9.Listener.NoiseA"));
        TickRuntimeWorld();
        TickRuntimeWorld();
        TestTrue(TEXT("Actual Noise A reaches Listener Hearing memory"), Controller->EnemyMemory.bHasHeardSound);
        TestEqual(TEXT("Noise A location is stored"), Controller->EnemyMemory.LastHeardLocation, NoiseA);

        UAISense_Hearing::ReportNoiseEvent(
            World,
            NoiseB,
            1.0f,
            Player,
            0.0f,
            TEXT("Phase9.Listener.NoiseB"));
        bool bObservedPatrolAfterInvestigation = false;
        for (int32 TickIndex = 0; TickIndex < 8; ++TickIndex)
        {
            TickRuntimeWorld();
            bObservedPatrolAfterInvestigation |= HasActiveListenerState(StateTreeComponent, TEXT("Patrol"));
        }
        TestEqual(
            TEXT("Repeated actual Noise uses the newest accepted location"),
            Controller->EnemyMemory.LastHeardLocation,
            NoiseB);
        TestTrue(
            TEXT("Unresolved runtime sound investigation exits to Patrol"),
            bObservedPatrolAfterInvestigation);
        TestFalse(
            TEXT("Listener Sight is disabled again after returning to Patrol"),
            Perception && Perception->IsSenseEnabled(UAISense_Sight::StaticClass()));

        if (StateTreeComponent && StateTreeComponent->IsRunning())
        {
            StateTreeComponent->StopLogic(TEXT("Phase 9 Listener runtime test teardown"));
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
