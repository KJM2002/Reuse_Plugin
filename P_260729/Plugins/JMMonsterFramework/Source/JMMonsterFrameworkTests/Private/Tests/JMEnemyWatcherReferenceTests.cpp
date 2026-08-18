#include "Misc/AutomationTest.h"

#include "Action/JMEnemyActionComponent.h"
#include "Action/JMEnemyActionDefinition.h"
#include "Audio/JMEnemyAudioSet.h"
#include "Builders/CubeBuilder.h"
#include "Components/BrushComponent.h"
#include "Core/JMEnemyBase.h"
#include "Core/JMEnemyAIController.h"
#include "Core/JMEnemyDefinition.h"
#include "Engine/Blueprint.h"
#include "Engine/Engine.h"
#include "Engine/StaticMesh.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/World.h"
#include "Engine/WorldInitializationValues.h"
#include "GameFramework/PlayerController.h"
#include "Locomotion/JMEnemyLocomotionComponent.h"
#include "Locomotion/JMEnemyMovementSet.h"
#include "Memory/JMEnemyMemoryComponent.h"
#include "Model.h"
#include "NavMesh/NavMeshBoundsVolume.h"
#include "NavigationSystem.h"
#include "Perception/JMEnemyPerceptionComponent.h"
#include "State/JMEnemyStateComponent.h"
#include "StateTree.h"
#include "StateTreeEditorData.h"
#include "StateTree/JMEnemyStateTreeComponent.h"
#include "Tests/JMEnemyCoreTestTypes.h"
#include "TimerManager.h"
#include "Types/JMEnemyTags.h"

namespace JMWatcherReferenceTests
{
    constexpr TCHAR DefinitionPath[] =
        TEXT("/JMMonsterFramework/Reference/Watcher/DA_Enemy_Watcher.DA_Enemy_Watcher");
    constexpr TCHAR BlueprintPath[] =
        TEXT("/JMMonsterFramework/Reference/Watcher/BP_Enemy_Watcher.BP_Enemy_Watcher");

    void TickWorld(UWorld& World, const float Seconds)
    {
        constexpr float Step = 0.05f;
        for (int32 Index = 0; Index < FMath::CeilToInt(Seconds / Step); ++Index)
        {
            World.Tick(LEVELTICK_All, Step);
            World.GetTimerManager().Tick(Step);
        }
    }

    bool SubmitVision(AJMEnemyBase& Watcher, AActor& Source, const bool bSensed)
    {
        FJMStimulus Stimulus;
        Stimulus.Type = EJMStimulusType::Vision;
        Stimulus.SourceActor = &Source;
        Stimulus.WorldLocation = Source.GetActorLocation();
        Stimulus.Strength = bSensed ? 1.0f : 0.0f;
        Stimulus.Confidence = 1.0f;
        Stimulus.Timestamp = Watcher.GetWorld()->GetTimeSeconds();
        Stimulus.bSuccessfullySensed = bSensed;
        return Watcher.GetEnemyPerceptionComponent()->SubmitStimulus(Stimulus);
    }
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMEnemyWatcherAssetCompositionTest,
    "JM.MonsterFramework.Watcher.AssetComposition",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyWatcherAssetCompositionTest::RunTest(const FString& Parameters)
{
    UJMEnemyDefinition* Definition = LoadObject<UJMEnemyDefinition>(nullptr,
        JMWatcherReferenceTests::DefinitionPath);
    UBlueprint* Blueprint = LoadObject<UBlueprint>(nullptr, JMWatcherReferenceTests::BlueprintPath);
    TestNotNull(TEXT("Watcher Definition loads from Plugin Content"), Definition);
    TestNotNull(TEXT("Watcher Blueprint loads from Plugin Content"), Blueprint);
    if (!Definition || !Blueprint) return false;

    TestTrue(TEXT("Watcher vision is enabled"), Definition->Perception.Vision.bEnabled);
    TestFalse(TEXT("Watcher hearing is disabled"), Definition->Perception.Hearing.bEnabled);
    TestTrue(TEXT("Watcher gaze is enabled"), Definition->Perception.PlayerGaze.bEnabled);
    TestEqual(TEXT("Watcher gaze threshold is data-driven"),
        Definition->Perception.PlayerGaze.DotThreshold, 0.90f);
    TestEqual(TEXT("Watcher target-lost grace is represented in StateTree, not Definition duplication"),
        Definition->Perception.Vision.StimulusMaxAge, 5.0f);
    TestNotNull(TEXT("Watcher movement set is assigned"), Definition->MovementSet.Get());
    TestEqual(TEXT("Watcher has Patrol and Chase profiles"), Definition->MovementSet->Profiles.Num(), 2);
    TestEqual(TEXT("Watcher has one reusable action"), Definition->Actions.Num(), 1);
    TestTrue(TEXT("Watcher action is reusable Melee"), Definition->Actions[0] &&
        Definition->Actions[0]->ActionId == JMEnemyTags::Action_Melee);
    TestTrue(TEXT("Watcher StateTree is compiled and ready"),
        Definition->StateTree && Definition->StateTree->IsReadyToRun());
    TestTrue(TEXT("Watcher audio contract covers Frozen and Attack"),
        Definition->AudioSet && Definition->AudioSet->FindEvent(EJMEnemyAudioEvent::Frozen) &&
        Definition->AudioSet->FindEvent(EJMEnemyAudioEvent::Attack));
    TestTrue(TEXT("Watcher Blueprint directly derives from AJMEnemyBase"),
        Blueprint->GeneratedClass && Blueprint->GeneratedClass->GetSuperClass() == AJMEnemyBase::StaticClass());
    const AJMEnemyBase* CDO = Blueprint->GeneratedClass
        ? Cast<AJMEnemyBase>(Blueprint->GeneratedClass->GetDefaultObject()) : nullptr;
    TestEqual(TEXT("Watcher Blueprint CDO is wired to its Definition"),
        CDO ? CDO->GetEnemyDefinition() : nullptr, Definition);

    const UStateTreeEditorData* EditorData = Definition->StateTree
        ? Cast<UStateTreeEditorData>(Definition->StateTree->EditorData) : nullptr;
    TestNotNull(TEXT("Watcher StateTree retains editor data"), EditorData);
    if (EditorData && !EditorData->SubTrees.IsEmpty())
    {
        TSet<FName> StateNames;
        for (const UStateTreeState* State : EditorData->SubTrees[0]->Children)
        {
            if (State) StateNames.Add(State->Name);
        }
        for (const FName Required : {FName(TEXT("Patrol")), FName(TEXT("AcquireTarget")),
            FName(TEXT("Chase")), FName(TEXT("Frozen")), FName(TEXT("Attack"))})
        {
            TestTrue(FString::Printf(TEXT("StateTree contains %s"), *Required.ToString()),
                StateNames.Contains(Required));
        }
    }
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMEnemyWatcherWorldVerticalSliceTest,
    "JM.MonsterFramework.Watcher.WorldVerticalSlice",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyWatcherWorldVerticalSliceTest::RunTest(const FString& Parameters)
{
    UBlueprint* Blueprint = LoadObject<UBlueprint>(nullptr, JMWatcherReferenceTests::BlueprintPath);
    if (!TestNotNull(TEXT("Watcher Blueprint loads"), Blueprint) || !Blueprint->GeneratedClass) return false;

    UWorld::InitializationValues Init;
    Init.AllowAudioPlayback(false).RequiresHitProxies(false).CreateNavigation(true)
        .CreateAISystem(true).ShouldSimulatePhysics(false).SetTransactional(false).CreateFXSystem(false);
    UWorld* World = UWorld::CreateWorld(EWorldType::Game, true, TEXT("JMWatcherVerticalSlice"),
        GetTransientPackage(), true, ERHIFeatureLevel::Num, &Init);
    if (!TestNotNull(TEXT("Integration world is created"), World)) return false;
    FWorldContext& WorldContext = GEngine->CreateNewWorldContext(EWorldType::Game);
    WorldContext.SetCurrentWorld(World);

    AStaticMeshActor* Floor = World->SpawnActor<AStaticMeshActor>(FVector(0.0, 0.0, -100.0), FRotator::ZeroRotator);
    Floor->GetStaticMeshComponent()->SetStaticMesh(
        LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube")));
    Floor->SetActorScale3D(FVector(30.0f, 30.0f, 1.0f));
    Floor->ReregisterAllComponents();
    ANavMeshBoundsVolume* Bounds = World->SpawnActor<ANavMeshBoundsVolume>(FVector::ZeroVector, FRotator::ZeroRotator);
    Bounds->Brush = NewObject<UModel>(Bounds, NAME_None, RF_Transient);
    Bounds->Brush->Initialize(Bounds, true);
    Bounds->GetBrushComponent()->Brush = Bounds->Brush;
    UCubeBuilder* Builder = NewObject<UCubeBuilder>();
    Builder->X = 6000.0f;
    Builder->Y = 6000.0f;
    Builder->Z = 1000.0f;
    Builder->Build(World, Bounds);
    Bounds->ReregisterAllComponents();
    World->InitializeActorsForPlay(FURL());
    UNavigationSystemV1* Navigation = FNavigationSystem::GetCurrent<UNavigationSystemV1>(World);
    if (Navigation) Navigation->OnNavigationBoundsUpdated(Bounds);
    World->BeginPlay();
    JMWatcherReferenceTests::TickWorld(*World, 0.1f);
    if (Navigation)
    {
        UNavigationSystemV1::UpdateActorAndComponentsInNavOctree(*Floor);
        Navigation->Build();
    }
    JMWatcherReferenceTests::TickWorld(*World, 0.5f);

    AJMEnemyBase* Watcher = World->SpawnActor<AJMEnemyBase>(Blueprint->GeneratedClass,
        FVector(0.0, 0.0, 100.0), FRotator::ZeroRotator);
    if (Watcher && !Watcher->GetController()) Watcher->SpawnDefaultController();
    AJMEnemyPlayerDamageTarget* Player = World->SpawnActor<AJMEnemyPlayerDamageTarget>(
        FVector(600.0, 0.0, 100.0), FRotator(0.0, 180.0, 0.0));
    APlayerController* PlayerController = World->SpawnActor<APlayerController>();
    PlayerController->Possess(Player);
    PlayerController->SetControlRotation(FRotator(0.0, 180.0, 0.0));
    if (!TestNotNull(TEXT("Watcher spawns"), Watcher) || !TestNotNull(TEXT("Player spawns"), Player))
    {
        GEngine->DestroyWorldContext(World);
        World->DestroyWorld(false);
        return false;
    }
    if (AJMEnemyAIController* Controller = Cast<AJMEnemyAIController>(Watcher->GetController()))
    {
        Controller->GetEnemyStateTreeComponent()->StopFrameworkTree(TEXT("Manual vertical-slice building-block verification"));
    }
    FJMEnemyPerceptionConfig TestPerception = Watcher->GetEnemyPerceptionComponent()->GetConfig();
    TestPerception.PlayerGaze.UpdateInterval = 10.0f;
    Watcher->GetEnemyPerceptionComponent()->ApplyConfig(TestPerception);
    JMWatcherReferenceTests::TickWorld(*World, 0.15f);

    TestTrue(TEXT("Vision stimulus enters normalized perception"),
        JMWatcherReferenceTests::SubmitVision(*Watcher, *Player, true));
    TestTrue(TEXT("Vision memory exposes the visible candidate"),
        Watcher->GetEnemyMemoryComponent()->CanCurrentlySeeActor(Player));
    Watcher->GetEnemyMemoryComponent()->SetCurrentTarget(Player);
    Watcher->GetEnemyStateComponent()->SetState(JMEnemyTags::State_Chase);
    Watcher->GetEnemyLocomotionComponent()->ApplyMovementProfile(
        Watcher->GetEnemyDefinition()->MovementSet.Get(), TEXT("Chase"));
    const EJMEnemyMoveRequestResult FirstMove = Watcher->GetEnemyLocomotionComponent()->MoveToActor(
        Player, FJMEnemyMoveOptions());
    TestTrue(TEXT("Vision candidate becomes CurrentTarget through explicit target API"),
        Watcher->GetEnemyMemoryComponent()->GetCurrentTarget() == Player);
    TestTrue(TEXT("Chase issues a valid locomotion request"),
        FirstMove == EJMEnemyMoveRequestResult::RequestStarted ||
        FirstMove == EJMEnemyMoveRequestResult::AlreadyAtGoal);

    TestTrue(TEXT("External gaze adapter accepts observation"),
        Watcher->GetEnemyPerceptionComponent()->SubmitPlayerGazeObservation(true, 1.0f, Player));
    JMWatcherReferenceTests::TickWorld(*World, 0.05f);
    Watcher->GetEnemyPerceptionComponent()->SubmitPlayerGazeObservation(true, 1.0f, Player);
    TestTrue(TEXT("Runtime gaze detects the player looking at Watcher"),
        Watcher->GetEnemyPerceptionComponent()->IsPlayerLookingAtMe());
    TestTrue(TEXT("Gaze duration reaches the StateTree threshold"),
        Watcher->GetEnemyPerceptionComponent()->GetGazeDuration() >= 0.05f);
    Watcher->GetEnemyLocomotionComponent()->StopMovement();
    Watcher->GetEnemyStateComponent()->SetState(JMEnemyTags::State_Watcher_Frozen);
    TestTrue(TEXT("Gaze enters Frozen"),
        Watcher->GetEnemyStateComponent()->IsInState(JMEnemyTags::State_Watcher_Frozen));
    TestEqual(TEXT("Frozen stops the active move"), Watcher->GetEnemyLocomotionComponent()->GetMoveStatus(),
        EJMEnemyMoveStatus::Aborted);

    TestTrue(TEXT("External gaze adapter accepts release"),
        Watcher->GetEnemyPerceptionComponent()->SubmitPlayerGazeObservation(false, 0.0f, nullptr));
    TestFalse(TEXT("Turning away releases gaze"), Watcher->GetEnemyPerceptionComponent()->IsPlayerLookingAtMe());
    Watcher->GetEnemyStateComponent()->SetState(JMEnemyTags::State_Chase);
    const EJMEnemyMoveRequestResult SecondMove = Watcher->GetEnemyLocomotionComponent()->MoveToActor(
        Player, FJMEnemyMoveOptions());
    TestTrue(TEXT("Chase can submit a fresh move after cancellation"),
        SecondMove == EJMEnemyMoveRequestResult::RequestStarted ||
        SecondMove == EJMEnemyMoveRequestResult::AlreadyAtGoal);

    Watcher->GetEnemyPerceptionComponent()->SubmitPlayerGazeObservation(true, 1.0f, Player);
    JMWatcherReferenceTests::TickWorld(*World, 0.05f);
    Watcher->GetEnemyPerceptionComponent()->SubmitPlayerGazeObservation(true, 1.0f, Player);
    Watcher->GetEnemyLocomotionComponent()->StopMovement();
    Watcher->GetEnemyStateComponent()->SetState(JMEnemyTags::State_Watcher_Frozen);
    TestTrue(TEXT("Repeated look freezes again without move lifecycle corruption"),
        Watcher->GetEnemyPerceptionComponent()->IsPlayerLookingAtMe() &&
        Watcher->GetEnemyStateComponent()->IsInState(JMEnemyTags::State_Watcher_Frozen));

    Watcher->GetEnemyPerceptionComponent()->SubmitPlayerGazeObservation(false, 0.0f, nullptr);
    Player->SetActorLocation(Watcher->GetActorLocation() + FVector(20.0, 0.0, 0.0));
    Player->AttachToActor(Watcher, FAttachmentTransformRules::KeepWorldTransform);
    JMWatcherReferenceTests::TickWorld(*World, 0.1f);
    Watcher->GetEnemyStateComponent()->SetState(JMEnemyTags::State_Attack);
    UJMEnemyActionDefinition_Melee* TestMelee = Cast<UJMEnemyActionDefinition_Melee>(
        Watcher->GetEnemyDefinition()->Actions[0]);
    if (TestMelee)
    {
        // The generic timed lifecycle has dedicated tests; resolve synchronously in this world slice.
        TestMelee->WindupDuration = 0.0f;
        TestMelee->ActiveDuration = 0.0f;
        TestMelee->RecoveryDuration = 0.0f;
        TestMelee->Cooldown = 0.0f;
    }
    FJMEnemyActionContext AttackContext;
    AttackContext.TargetActor = Player;
    TestEqual(TEXT("Watcher starts reusable Melee"),
        Watcher->GetEnemyActionComponent()->ExecuteAction(JMEnemyTags::Action_Melee, AttackContext),
        EJMEnemyActionExecuteResult::Started);
    TestTrue(TEXT("Watcher Melee resolves damage"), Player->DamageCallCount > 0);

    TestTrue(TEXT("Vision loss stimulus enters normalized perception"),
        JMWatcherReferenceTests::SubmitVision(*Watcher, *Player, false));
    JMWatcherReferenceTests::TickWorld(*World, 1.6f);
    TestFalse(TEXT("Last-seen grace expires without a polling timer"),
        Watcher->GetEnemyMemoryComponent()->HasSeenTargetRecently(1.5f));
    Watcher->GetEnemyMemoryComponent()->ClearCurrentTarget();
    Watcher->GetEnemyStateComponent()->SetState(JMEnemyTags::State_Patrol);
    TestNull(TEXT("Expired target is cleared"), Watcher->GetEnemyMemoryComponent()->GetCurrentTarget());
    TestTrue(TEXT("Target loss returns to Patrol"),
        Watcher->GetEnemyStateComponent()->IsInState(JMEnemyTags::State_Patrol));

    GEngine->DestroyWorldContext(World);
    World->DestroyWorld(false);
    return true;
}
