#include "Misc/AutomationTest.h"

#include "Action/JMEnemyActionComponent.h"
#include "Action/JMEnemyActionDefinition.h"
#include "Components/CapsuleComponent.h"
#include "Core/JMEnemyAIController.h"
#include "Core/JMEnemyBase.h"
#include "Core/JMEnemyDefinition.h"
#include "Core/JMSurfaceCrawlerEnemyBase.h"
#include "Engine/Blueprint.h"
#include "Engine/Engine.h"
#include "Engine/StaticMesh.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/World.h"
#include "Engine/WorldInitializationValues.h"
#include "GameFramework/PlayerController.h"
#include "Locomotion/JMEnemyLocomotion_SurfaceCrawler.h"
#include "Locomotion/JMEnemyMovementSet.h"
#include "Memory/JMEnemyMemoryComponent.h"
#include "Perception/JMEnemyPerceptionComponent.h"
#include "State/JMEnemyStateComponent.h"
#include "StateTree.h"
#include "StateTreeEditorData.h"
#include "StateTree/JMEnemyStateTreeComponent.h"
#include "Tests/JMEnemyCoreTestTypes.h"
#include "TimerManager.h"
#include "Types/JMEnemyTags.h"

namespace JMCrawlerReferenceTests
{
    constexpr TCHAR DefinitionPath[] =
        TEXT("/JMMonsterFramework/Reference/Crawler/DA_Enemy_Crawler.DA_Enemy_Crawler");
    constexpr TCHAR BlueprintPath[] =
        TEXT("/JMMonsterFramework/Reference/Crawler/BP_Enemy_Crawler.BP_Enemy_Crawler");

    UWorld* CreateWorld(const TCHAR* Name)
    {
        UWorld::InitializationValues Init;
        Init.AllowAudioPlayback(false).RequiresHitProxies(false).CreateNavigation(false)
            .CreateAISystem(true).ShouldSimulatePhysics(false).SetTransactional(false).CreateFXSystem(false);
        UWorld* World = UWorld::CreateWorld(EWorldType::Game, true, Name,
            GetTransientPackage(), true, ERHIFeatureLevel::Num, &Init);
        if (World)
        {
            FWorldContext& Context = GEngine->CreateNewWorldContext(EWorldType::Game);
            Context.SetCurrentWorld(World);
        }
        return World;
    }

    void DestroyWorld(UWorld* World)
    {
        if (!World) return;
        GEngine->DestroyWorldContext(World);
        World->DestroyWorld(false);
    }

    AStaticMeshActor* AddCube(UWorld& World, const FVector Location, const FVector Scale)
    {
        AStaticMeshActor* Actor = World.SpawnActor<AStaticMeshActor>(Location, FRotator::ZeroRotator);
        Actor->GetStaticMeshComponent()->SetStaticMesh(
            LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube")));
        Actor->SetActorScale3D(Scale);
        Actor->GetStaticMeshComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
        Actor->ReregisterAllComponents();
        return Actor;
    }

    void TickWorld(UWorld& World, const float Seconds)
    {
        constexpr float Step = 0.02f;
        for (int32 Index = 0; Index < FMath::CeilToInt(Seconds / Step); ++Index)
        {
            World.Tick(LEVELTICK_All, Step);
            World.GetTimerManager().Tick(Step);
        }
    }

    bool SubmitVision(AJMEnemyBase& Crawler, AActor& Source, const bool bSensed)
    {
        FJMStimulus Stimulus;
        Stimulus.Type = EJMStimulusType::Vision;
        Stimulus.SourceActor = &Source;
        Stimulus.WorldLocation = Source.GetActorLocation();
        Stimulus.Strength = bSensed ? 1.0f : 0.0f;
        Stimulus.Confidence = 1.0f;
        Stimulus.Timestamp = Crawler.GetWorld()->GetTimeSeconds();
        Stimulus.bSuccessfullySensed = bSensed;
        return Crawler.GetEnemyPerceptionComponent()->SubmitStimulus(Stimulus);
    }

    void StopStateTree(AJMEnemyBase& Enemy)
    {
        if (AJMEnemyAIController* Controller = Cast<AJMEnemyAIController>(Enemy.GetController()))
        {
            Controller->GetEnemyStateTreeComponent()->StopFrameworkTree(
                TEXT("Manual Crawler vertical-slice building-block verification"));
        }
    }
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMEnemyCrawlerAssetCompositionTest,
    "JM.MonsterFramework.Crawler.AssetComposition",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyCrawlerAssetCompositionTest::RunTest(const FString& Parameters)
{
    UJMEnemyDefinition* Definition = LoadObject<UJMEnemyDefinition>(nullptr,
        JMCrawlerReferenceTests::DefinitionPath);
    UBlueprint* Blueprint = LoadObject<UBlueprint>(nullptr, JMCrawlerReferenceTests::BlueprintPath);
    TestNotNull(TEXT("Crawler Definition loads"), Definition);
    TestNotNull(TEXT("Crawler Blueprint loads"), Blueprint);
    if (!Definition || !Blueprint) return false;

    TestTrue(TEXT("Crawler Vision is enabled"), Definition->Perception.Vision.bEnabled);
    TestTrue(TEXT("Crawler Gaze is enabled"), Definition->Perception.PlayerGaze.bEnabled);
    TestFalse(TEXT("Crawler Hearing is disabled"), Definition->Perception.Hearing.bEnabled);
    TestNotNull(TEXT("Crawler MovementSet is assigned"), Definition->MovementSet.Get());
    TestEqual(TEXT("Crawler has five behavior profiles"), Definition->MovementSet->Profiles.Num(), 5);
    TestEqual(TEXT("Crawler has Melee and Scream"), Definition->Actions.Num(), 2);
    TestTrue(TEXT("Crawler first action is Melee"), Definition->Actions[0] &&
        Definition->Actions[0]->ActionId == JMEnemyTags::Action_Melee);
    TestTrue(TEXT("Crawler second action is Scream"), Definition->Actions[1] &&
        Definition->Actions[1]->ActionId == JMEnemyTags::Action_Scream);
    TestTrue(TEXT("Crawler StateTree is compile-ready"),
        Definition->StateTree && Definition->StateTree->IsReadyToRun());
    TestTrue(TEXT("Crawler Blueprint uses only the locomotion shell"),
        Blueprint->GeneratedClass && Blueprint->GeneratedClass->GetSuperClass() ==
            AJMSurfaceCrawlerEnemyBase::StaticClass());
    const AJMEnemyBase* CDO = Blueprint->GeneratedClass
        ? Cast<AJMEnemyBase>(Blueprint->GeneratedClass->GetDefaultObject()) : nullptr;
    TestTrue(TEXT("Crawler shell supplies SurfaceCrawler locomotion"), CDO &&
        CDO->GetEnemyLocomotionComponent()->IsA<UJMEnemyLocomotion_SurfaceCrawler>());
    TestEqual(TEXT("Crawler CDO is wired to Definition"),
        CDO ? CDO->GetEnemyDefinition() : nullptr, Definition);

    const UStateTreeEditorData* EditorData = Definition->StateTree
        ? Cast<UStateTreeEditorData>(Definition->StateTree->EditorData) : nullptr;
    TestNotNull(TEXT("Crawler StateTree retains editor data"), EditorData);
    if (EditorData && !EditorData->SubTrees.IsEmpty())
    {
        TSet<FName> Names;
        for (const UStateTreeState* State : EditorData->SubTrees[0]->Children)
        {
            if (State) Names.Add(State->Name);
        }
        for (const FName Required : {FName(TEXT("Roam")), FName(TEXT("AcquireTarget")),
            FName(TEXT("Stalk")), FName(TEXT("Flee")), FName(TEXT("Hide")),
            FName(TEXT("ReApproach")), FName(TEXT("Enrage")),
            FName(TEXT("FrenzyChase")), FName(TEXT("Attack"))})
        {
            TestTrue(FString::Printf(TEXT("StateTree contains %s"), *Required.ToString()),
                Names.Contains(Required));
        }
    }
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMEnemySurfaceCrawlerLocomotionTest,
    "JM.MonsterFramework.Locomotion.SurfaceCrawler",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemySurfaceCrawlerLocomotionTest::RunTest(const FString& Parameters)
{
    UBlueprint* Blueprint = LoadObject<UBlueprint>(nullptr, JMCrawlerReferenceTests::BlueprintPath);
    if (!TestNotNull(TEXT("Crawler Blueprint loads for surface test"), Blueprint) || !Blueprint->GeneratedClass)
        return false;
    UWorld* World = JMCrawlerReferenceTests::CreateWorld(TEXT("JMSurfaceCrawlerFixture"));
    if (!TestNotNull(TEXT("Surface fixture world is created"), World)) return false;

    JMCrawlerReferenceTests::AddCube(*World, FVector(0.0, 0.0, -25.0), FVector(10.0f, 5.0f, 0.25f));
    JMCrawlerReferenceTests::AddCube(*World, FVector(500.0, 0.0, 250.0), FVector(0.25f, 5.0f, 5.0f));
    JMCrawlerReferenceTests::AddCube(*World, FVector(0.0, 0.0, 525.0), FVector(10.0f, 5.0f, 0.25f));
    World->InitializeActorsForPlay(FURL());
    World->BeginPlay();

    AJMEnemyBase* Crawler = World->SpawnActor<AJMEnemyBase>(Blueprint->GeneratedClass,
        FVector(0.0, 0.0, 90.0), FRotator::ZeroRotator);
    if (Crawler && !Crawler->GetController()) Crawler->SpawnDefaultController();
    if (!TestNotNull(TEXT("Crawler spawns in fixture"), Crawler))
    {
        JMCrawlerReferenceTests::DestroyWorld(World);
        return false;
    }
    JMCrawlerReferenceTests::StopStateTree(*Crawler);
    Crawler->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    UJMEnemyLocomotion_SurfaceCrawler* Surface = Cast<UJMEnemyLocomotion_SurfaceCrawler>(
        Crawler->GetEnemyLocomotionComponent());
    TestNotNull(TEXT("Surface backend is active"), Surface);
    if (!Surface)
    {
        JMCrawlerReferenceTests::DestroyWorld(World);
        return false;
    }
    Surface->ApplyMovementProfile(Crawler->GetEnemyDefinition()->MovementSet.Get(), TEXT("Flee"));
    TestTrue(TEXT("Initial attachment is floor"), Surface->GetCurrentSurfaceNormal().Z > 0.8f);
    TestEqual(TEXT("Surface move starts through common API"),
        Surface->MoveToLocation(FVector(250.0, 0.0, 410.0), FJMEnemyMoveOptions()),
        EJMEnemyMoveRequestResult::RequestStarted);

    bool bSawWall = false;
    bool bSawCeiling = false;
    for (int32 Index = 0; Index < 400 && Surface->GetMoveStatus() == EJMEnemyMoveStatus::Moving; ++Index)
    {
        static_cast<UActorComponent*>(Surface)->TickComponent(0.02f, LEVELTICK_All, nullptr);
        const FVector Normal = Surface->GetCurrentSurfaceNormal();
        bSawWall |= FMath::Abs(Normal.X) > 0.8f;
        bSawCeiling |= Normal.Z < -0.8f;
    }
    AddInfo(FString::Printf(TEXT("Surface final Location=%s Normal=%s Status=%d Transitions=%d"),
        *Crawler->GetActorLocation().ToCompactString(),
        *Surface->GetCurrentSurfaceNormal().ToCompactString(),
        static_cast<int32>(Surface->GetMoveStatus()), Surface->GetSurfaceTransitionCount()));
    TestTrue(TEXT("Crawler transitions Floor to Wall"), bSawWall);
    TestTrue(TEXT("Crawler transitions Wall to Ceiling"), bSawCeiling);
    TestTrue(TEXT("At least two geometry-driven transitions are recorded"),
        Surface->GetSurfaceTransitionCount() >= 2);
    TestEqual(TEXT("Surface request completes through common lifecycle"),
        Surface->GetMoveStatus(), EJMEnemyMoveStatus::Succeeded);
    TestTrue(TEXT("Final orientation up follows ceiling normal"),
        FVector::DotProduct(Crawler->GetActorUpVector(), FVector::DownVector) > 0.75f);
    TestFalse(TEXT("Surface traversal never creates NaN position"), Crawler->GetActorLocation().ContainsNaN());

    const FVector RestartGoal = Crawler->GetActorLocation() + Crawler->GetActorForwardVector() * 350.0f;
    TestEqual(TEXT("A new surface request starts after completion"),
        Surface->MoveToLocation(RestartGoal, FJMEnemyMoveOptions()), EJMEnemyMoveRequestResult::RequestStarted);
    const FAIRequestID CancelledID = Surface->GetCurrentRequestID();
    Surface->StopMovement();
    TestEqual(TEXT("Stopping surface movement reports Aborted"),
        Surface->GetMoveStatus(), EJMEnemyMoveStatus::Aborted);
    TestEqual(TEXT("Another request can start after abort"),
        Surface->MoveToLocation(RestartGoal, FJMEnemyMoveOptions()), EJMEnemyMoveRequestResult::RequestStarted);
    TestTrue(TEXT("Restart owns a new request identity"),
        Surface->GetCurrentRequestID().IsValid() &&
        !Surface->GetCurrentRequestID().IsEquivalent(CancelledID));
    Surface->StopMovement();

    JMCrawlerReferenceTests::DestroyWorld(World);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMEnemyCrawlerWorldVerticalSliceTest,
    "JM.MonsterFramework.Crawler.WorldVerticalSlice",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyCrawlerWorldVerticalSliceTest::RunTest(const FString& Parameters)
{
    UBlueprint* Blueprint = LoadObject<UBlueprint>(nullptr, JMCrawlerReferenceTests::BlueprintPath);
    if (!TestNotNull(TEXT("Crawler Blueprint loads for vertical slice"), Blueprint) || !Blueprint->GeneratedClass)
        return false;
    UWorld* World = JMCrawlerReferenceTests::CreateWorld(TEXT("JMCrawlerVerticalSlice"));
    if (!TestNotNull(TEXT("Crawler vertical world is created"), World)) return false;
    JMCrawlerReferenceTests::AddCube(*World, FVector::ZeroVector - FVector(0.0, 0.0, 25.0),
        FVector(20.0f, 20.0f, 0.25f));
    World->InitializeActorsForPlay(FURL());
    World->BeginPlay();

    AJMEnemyBase* Crawler = World->SpawnActor<AJMEnemyBase>(Blueprint->GeneratedClass,
        FVector(0.0, 0.0, 90.0), FRotator::ZeroRotator);
    if (Crawler && !Crawler->GetController()) Crawler->SpawnDefaultController();
    AJMEnemyPlayerDamageTarget* Player = World->SpawnActor<AJMEnemyPlayerDamageTarget>(
        FVector(700.0, 0.0, 90.0), FRotator::ZeroRotator);
    APlayerController* PlayerController = World->SpawnActor<APlayerController>();
    PlayerController->Possess(Player);
    if (!TestNotNull(TEXT("Crawler spawns"), Crawler) || !TestNotNull(TEXT("Player spawns"), Player))
    {
        JMCrawlerReferenceTests::DestroyWorld(World);
        return false;
    }
    JMCrawlerReferenceTests::StopStateTree(*Crawler);
    FJMEnemyPerceptionConfig TestPerception = Crawler->GetEnemyPerceptionComponent()->GetConfig();
    TestPerception.PlayerGaze.UpdateInterval = 10.0f;
    Crawler->GetEnemyPerceptionComponent()->ApplyConfig(TestPerception);

    TestTrue(TEXT("Vision enters normalized boundary"),
        JMCrawlerReferenceTests::SubmitVision(*Crawler, *Player, true));
    TestTrue(TEXT("Vision exposes generic combat candidate"),
        Crawler->GetEnemyMemoryComponent()->CanCurrentlySeeActor(Player));
    Crawler->GetEnemyMemoryComponent()->SetCurrentTarget(Player);
    Crawler->GetEnemyStateComponent()->SetState(JMEnemyTags::State_Crawler_Stalk);
    TestTrue(TEXT("Acquire enters Stalk with explicit target"),
        Crawler->GetEnemyMemoryComponent()->GetCurrentTarget() == Player &&
        Crawler->GetEnemyStateComponent()->IsInState(JMEnemyTags::State_Crawler_Stalk));

    Crawler->GetEnemyPerceptionComponent()->SubmitPlayerGazeObservation(true, 1.0f, Player);
    JMCrawlerReferenceTests::TickWorld(*World, 0.06f);
    Crawler->GetEnemyPerceptionComponent()->SubmitPlayerGazeObservation(true, 1.0f, Player);
    TestEqual(TEXT("First encounter starts at zero"), Crawler->GetEnemyMemoryComponent()->GetEncounterCount(), 0);
    Crawler->GetEnemyStateComponent()->SetState(JMEnemyTags::State_Flee);
    FVector Escape;
    TestTrue(TEXT("Surface backend supplies escape location"),
        Crawler->GetEnemyLocomotionComponent()->FindEscapeLocation(Player, 800.0f, Escape));
    TestTrue(TEXT("First gaze selects Flee behavior"),
        Crawler->GetEnemyStateComponent()->IsInState(JMEnemyTags::State_Flee));

    Crawler->GetEnemyLocomotionComponent()->StopMovement();
    Crawler->GetEnemyStateComponent()->SetState(JMEnemyTags::State_Hide);
    Crawler->GetEnemyMemoryComponent()->IncrementEncounterCount();
    TestEqual(TEXT("Hide records first encounter"), Crawler->GetEnemyMemoryComponent()->GetEncounterCount(), 1);
    Crawler->GetEnemyStateComponent()->SetState(JMEnemyTags::State_Crawler_ReApproach);
    TestTrue(TEXT("Hide completion enters ReApproach"),
        Crawler->GetEnemyStateComponent()->IsInState(JMEnemyTags::State_Crawler_ReApproach));

    Crawler->GetEnemyStateComponent()->SetState(JMEnemyTags::State_Enraged);
    TestTrue(TEXT("Second encounter gaze selects Enrage"),
        Crawler->GetEnemyPerceptionComponent()->IsPlayerLookingAtMe() &&
        Crawler->GetEnemyMemoryComponent()->GetEncounterCount() >= 1 &&
        Crawler->GetEnemyStateComponent()->IsInState(JMEnemyTags::State_Enraged));
    UJMEnemyActionDefinition_Scream* Scream = Cast<UJMEnemyActionDefinition_Scream>(
        Crawler->GetEnemyDefinition()->Actions[1]);
    if (Scream)
    {
        Scream->WindupDuration = Scream->ActiveDuration = Scream->RecoveryDuration = Scream->Cooldown = 0.0f;
    }
    FJMEnemyActionContext ScreamContext;
    ScreamContext.TargetActor = Player;
    TestEqual(TEXT("Enrage reuses Scream action"),
        Crawler->GetEnemyActionComponent()->ExecuteAction(JMEnemyTags::Action_Scream, ScreamContext),
        EJMEnemyActionExecuteResult::Started);
    Crawler->GetEnemyStateComponent()->SetState(JMEnemyTags::State_Crawler_FrenzyChase);
    TestTrue(TEXT("Frenzy ignores persistent gaze"),
        Crawler->GetEnemyPerceptionComponent()->IsPlayerLookingAtMe() &&
        Crawler->GetEnemyStateComponent()->IsInState(JMEnemyTags::State_Crawler_FrenzyChase));

    Crawler->GetEnemyPerceptionComponent()->SubmitPlayerGazeObservation(false, 0.0f, nullptr);
    Player->SetActorLocation(Crawler->GetActorLocation() + FVector(20.0, 0.0, 0.0));
    UJMEnemyActionDefinition_Melee* Melee = Cast<UJMEnemyActionDefinition_Melee>(
        Crawler->GetEnemyDefinition()->Actions[0]);
    if (Melee)
    {
        Melee->WindupDuration = Melee->ActiveDuration = Melee->RecoveryDuration = Melee->Cooldown = 0.0f;
    }
    Crawler->GetEnemyStateComponent()->SetState(JMEnemyTags::State_Attack);
    FJMEnemyActionContext MeleeContext;
    MeleeContext.TargetActor = Player;
    TestEqual(TEXT("Crawler starts reusable Melee"),
        Crawler->GetEnemyActionComponent()->ExecuteAction(JMEnemyTags::Action_Melee, MeleeContext),
        EJMEnemyActionExecuteResult::Started);
    TestTrue(TEXT("Crawler Melee damages target"), Player->DamageCallCount > 0);

    JMCrawlerReferenceTests::DestroyWorld(World);
    return true;
}
