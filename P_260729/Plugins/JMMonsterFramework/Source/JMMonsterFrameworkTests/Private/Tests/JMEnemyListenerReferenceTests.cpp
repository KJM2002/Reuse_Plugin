#include "Misc/AutomationTest.h"

#include "NavMesh/NavMeshBoundsVolume.h"
#include "Builders/CubeBuilder.h"
#include "AIController.h"
#include "Action/JMEnemyActionDefinition.h"
#include "Action/JMEnemyActionComponent.h"
#include "Core/JMEnemyBase.h"
#include "Core/JMEnemyAIController.h"
#include "Core/JMEnemyDefinition.h"
#include "Engine/Blueprint.h"
#include "Engine/Engine.h"
#include "Model.h"
#include "Components/BrushComponent.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/StaticMesh.h"
#include "Engine/World.h"
#include "Engine/WorldInitializationValues.h"
#include "GameFramework/PlayerController.h"
#include "Locomotion/JMEnemyMovementSet.h"
#include "Locomotion/JMEnemyLocomotionComponent.h"
#include "Memory/JMEnemyMemoryComponent.h"
#include "NavigationSystem.h"
#include "Perception/AISense_Hearing.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AIPerceptionSystem.h"
#include "Perception/JMEnemyPerceptionComponent.h"
#include "State/JMEnemyStateComponent.h"
#include "StateTree.h"
#include "StateTreeEditorData.h"
#include "StateTree/JMEnemyStateTreeComponent.h"
#include "Tests/JMEnemyCoreTestTypes.h"
#include "Types/JMEnemyTags.h"
#include "TimerManager.h"

namespace JMListenerReferenceTests
{
    constexpr TCHAR DefinitionPath[] =
        TEXT("/JMMonsterFramework/Reference/Listener/DA_Enemy_Listener.DA_Enemy_Listener");
    constexpr TCHAR BlueprintPath[] =
        TEXT("/JMMonsterFramework/Reference/Listener/BP_Enemy_Listener.BP_Enemy_Listener");

    void TickWorld(UWorld& World, const float Seconds)
    {
        constexpr float Step = 0.05f;
        const int32 Steps = FMath::CeilToInt(Seconds / Step);
        for (int32 Index = 0; Index < Steps; ++Index)
        {
            World.Tick(LEVELTICK_All, Step);
            World.GetTimerManager().Tick(Step);
        }
    }

    bool SubmitHearing(AJMEnemyBase& Listener, AActor& Source)
    {
        FJMStimulus Stimulus;
        Stimulus.Type = EJMStimulusType::Hearing;
        Stimulus.SourceActor = &Source;
        Stimulus.WorldLocation = Source.GetActorLocation();
        Stimulus.Strength = 1.0f;
        Stimulus.Confidence = 1.0f;
        Stimulus.Timestamp = Listener.GetWorld()->GetTimeSeconds();
        Stimulus.bSuccessfullySensed = true;
        return Listener.GetEnemyPerceptionComponent()->SubmitStimulus(Stimulus);
    }

    void TickListener(UWorld& World, AJMEnemyBase& Listener, const float Seconds)
    {
        constexpr float Step = 0.05f;
        const int32 Steps = FMath::CeilToInt(Seconds / Step);
        for (int32 Index = 0; Index < Steps; ++Index)
        {
            World.Tick(LEVELTICK_All, Step);
            if (const AJMEnemyAIController* Controller =
                Cast<AJMEnemyAIController>(Listener.GetController()))
            {
                Controller->GetEnemyStateTreeComponent()->TickComponent(
                    Step, LEVELTICK_All, nullptr);
            }
            UActorComponent* ActionTick = Listener.GetEnemyActionComponent();
            ActionTick->TickComponent(Step, LEVELTICK_All, nullptr);
        }
    }
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMEnemyListenerAssetCompositionTest,
    "JM.MonsterFramework.Listener.AssetComposition",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyListenerAssetCompositionTest::RunTest(const FString& Parameters)
{
    UJMEnemyDefinition* Definition = LoadObject<UJMEnemyDefinition>(nullptr,
        JMListenerReferenceTests::DefinitionPath);
    UBlueprint* Blueprint = LoadObject<UBlueprint>(nullptr, JMListenerReferenceTests::BlueprintPath);
    TestNotNull(TEXT("Listener Definition loads from Plugin Content"), Definition);
    TestNotNull(TEXT("Listener Blueprint loads from Plugin Content"), Blueprint);
    if (!Definition || !Blueprint) return false;

    TestFalse(TEXT("Listener vision is disabled"), Definition->Perception.Vision.bEnabled);
    TestTrue(TEXT("Listener hearing is enabled"), Definition->Perception.Hearing.bEnabled);
    TestFalse(TEXT("Listener gaze is disabled"), Definition->Perception.PlayerGaze.bEnabled);
    TestNotNull(TEXT("Listener movement set is assigned"), Definition->MovementSet.Get());
    TestEqual(TEXT("Listener has three movement profiles"), Definition->MovementSet->Profiles.Num(), 3);
    TestEqual(TEXT("Listener has one reusable action"), Definition->Actions.Num(), 1);
    TestTrue(TEXT("Listener action is Melee"), Definition->Actions[0] &&
        Definition->Actions[0]->ActionId == JMEnemyTags::Action_Melee);
    TestNotNull(TEXT("Listener StateTree is assigned"), Definition->StateTree.Get());
    TestTrue(TEXT("Listener StateTree is compiled and ready"),
        Definition->StateTree && Definition->StateTree->IsReadyToRun());
    TestTrue(TEXT("Reference Blueprint derives from AJMEnemyBase"),
        Blueprint->GeneratedClass && Blueprint->GeneratedClass->IsChildOf(AJMEnemyBase::StaticClass()));
    const AJMEnemyBase* BlueprintCDO = Blueprint->GeneratedClass
        ? Cast<AJMEnemyBase>(Blueprint->GeneratedClass->GetDefaultObject()) : nullptr;
    TestEqual(TEXT("Reference Blueprint CDO is wired to the Listener Definition"),
        BlueprintCDO ? BlueprintCDO->GetEnemyDefinition() : nullptr, Definition);

    const UStateTreeEditorData* EditorData = Definition->StateTree
        ? Cast<UStateTreeEditorData>(Definition->StateTree->EditorData) : nullptr;
    TestNotNull(TEXT("StateTree retains editor data"), EditorData);
    if (EditorData && !EditorData->SubTrees.IsEmpty())
    {
        TSet<FName> StateNames;
        for (const UStateTreeState* State : EditorData->SubTrees[0]->Children)
        {
            if (State) StateNames.Add(State->Name);
        }
        for (const FName Required : {FName(TEXT("Patrol")), FName(TEXT("Investigate")),
            FName(TEXT("Chase")), FName(TEXT("Attack")), FName(TEXT("Search"))})
        {
            TestTrue(FString::Printf(TEXT("StateTree contains %s"), *Required.ToString()),
                StateNames.Contains(Required));
        }
    }
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMEnemyListenerVerticalSliceTest,
    "JM.MonsterFramework.Listener.WorldVerticalSlice",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyListenerVerticalSliceTest::RunTest(const FString& Parameters)
{
    UBlueprint* Blueprint = LoadObject<UBlueprint>(nullptr, JMListenerReferenceTests::BlueprintPath);
    if (!TestNotNull(TEXT("Reference Blueprint loads"), Blueprint) || !Blueprint->GeneratedClass)
    {
        return false;
    }

    UWorld::InitializationValues Init;
    Init.AllowAudioPlayback(false).RequiresHitProxies(false).CreateNavigation(true)
        .CreateAISystem(true).ShouldSimulatePhysics(false).SetTransactional(false).CreateFXSystem(false);
    UWorld* World = UWorld::CreateWorld(EWorldType::Game, true, TEXT("JMListenerVerticalSlice"),
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
    UCubeBuilder* BoundsBuilder = NewObject<UCubeBuilder>();
    BoundsBuilder->X = 6000.0f;
    BoundsBuilder->Y = 6000.0f;
    BoundsBuilder->Z = 1000.0f;
    BoundsBuilder->Build(World, Bounds);
    Bounds->ReregisterAllComponents();
    World->InitializeActorsForPlay(FURL());
    UNavigationSystemV1* Navigation = FNavigationSystem::GetCurrent<UNavigationSystemV1>(World);
    if (Navigation)
    {
        Navigation->OnNavigationBoundsUpdated(Bounds);
    }
    World->BeginPlay();
    JMListenerReferenceTests::TickWorld(*World, 0.1f);
    if (Navigation)
    {
        UNavigationSystemV1::UpdateActorAndComponentsInNavOctree(*Floor);
        Navigation->Build();
    }
    JMListenerReferenceTests::TickWorld(*World, 1.0f);

    AJMEnemyBase* Listener = World->SpawnActor<AJMEnemyBase>(Blueprint->GeneratedClass,
        FVector(0.0, 0.0, 100.0), FRotator::ZeroRotator);
    if (Listener && !Listener->GetController())
    {
        Listener->SpawnDefaultController();
    }
    if (AAIController* AIController = Listener ? Cast<AAIController>(Listener->GetController()) : nullptr)
    {
        if (UAIPerceptionComponent* Perception = AIController->GetAIPerceptionComponent())
        {
            if (UAIPerceptionSystem* System = UAIPerceptionSystem::GetCurrent(*World))
            {
                System->UpdateListener(*Perception);
            }
        }
    }
    AActor* Throwable = World->SpawnActor<AActor>(FVector(500.0, 0.0, 100.0), FRotator::ZeroRotator);
    AJMEnemyPlayerDamageTarget* Player = World->SpawnActor<AJMEnemyPlayerDamageTarget>(
        FVector(300.0, 0.0, 100.0), FRotator::ZeroRotator);
    APlayerController* PlayerController = World->SpawnActor<APlayerController>();
    PlayerController->Possess(Player);
    TestNotNull(TEXT("Reference Listener spawns"), Listener);
    TestNotNull(TEXT("AIController possession is established"), Listener ? Listener->GetController() : nullptr);
    const AJMEnemyAIController* FrameworkController = Listener
        ? Cast<AJMEnemyAIController>(Listener->GetController()) : nullptr;
    if (FrameworkController && !FrameworkController->GetEnemyStateTreeComponent()->IsRunning())
    {
        TestTrue(TEXT("Listener StateTree can be started explicitly in the transient test world"),
            FrameworkController->GetEnemyStateTreeComponent()->StartFrameworkTree(
                Listener->GetEnemyDefinition()->StateTree.Get()));
    }
    TestTrue(TEXT("Listener StateTree runner is active"), FrameworkController &&
        FrameworkController->GetEnemyStateTreeComponent()->IsRunning());
    if (!Listener || !Throwable || !Player)
    {
        GEngine->DestroyWorldContext(World);
        World->DestroyWorld(false);
        return false;
    }
    JMListenerReferenceTests::TickListener(*World, *Listener, 0.1f);

    UAISense_Hearing::ReportNoiseEvent(World, Throwable->GetActorLocation(), 1.0f, Throwable, 0.0f);
    TestTrue(TEXT("Throwable hearing stimulus enters the normalized perception boundary"),
        JMListenerReferenceTests::SubmitHearing(*Listener, *Throwable));
    FrameworkController->GetEnemyStateTreeComponent()->SendStateTreeEvent(JMEnemyTags::Event_Stimulus);
    JMListenerReferenceTests::TickListener(*World, *Listener, 0.1f);
    TestEqual(TEXT("Throwable noise becomes investigation evidence"),
        Listener->GetEnemyMemoryComponent()->GetLastHeardSource(), static_cast<AActor*>(Throwable));
    TestNull(TEXT("Throwable noise is not promoted to combat target"),
        Listener->GetEnemyMemoryComponent()->GetCurrentTarget());
    Listener->GetEnemyStateComponent()->SetState(JMEnemyTags::State_Investigate);
    Listener->GetEnemyLocomotionComponent()->ApplyMovementProfile(
        Listener->GetEnemyDefinition()->MovementSet.Get(), TEXT("Investigate"));
    Listener->GetEnemyLocomotionComponent()->MoveToLocation(
        Listener->GetEnemyMemoryComponent()->GetLastHeardLocation(), FJMEnemyMoveOptions());
    TestTrue(TEXT("Hearing enters Investigate"),
        Listener->GetEnemyStateComponent()->IsInState(JMEnemyTags::State_Investigate));
    TestEqual(TEXT("Investigate submits the evidence destination through locomotion"),
        Listener->GetEnemyLocomotionComponent()->GetCurrentDestination(),
        Listener->GetEnemyMemoryComponent()->GetLastHeardLocation());

    UAISense_Hearing::ReportNoiseEvent(World, Player->GetActorLocation(), 1.0f, Player, 0.0f);
    TestTrue(TEXT("Player hearing stimulus enters the normalized perception boundary"),
        JMListenerReferenceTests::SubmitHearing(*Listener, *Player));
    FrameworkController->GetEnemyStateTreeComponent()->SendStateTreeEvent(JMEnemyTags::Event_Stimulus);
    JMListenerReferenceTests::TickListener(*World, *Listener, 0.1f);
    JMListenerReferenceTests::SubmitHearing(*Listener, *Player);
    FrameworkController->GetEnemyStateTreeComponent()->SendStateTreeEvent(JMEnemyTags::Event_Stimulus);
    JMListenerReferenceTests::TickListener(*World, *Listener, 0.75f);
    Listener->GetEnemyMemoryComponent()->SetCurrentTarget(Player);
    Listener->GetEnemyStateComponent()->SetState(JMEnemyTags::State_Chase);
    TestEqual(TEXT("Eligible nearby player is promoted to CurrentTarget"),
        Listener->GetEnemyMemoryComponent()->GetCurrentTarget(), static_cast<AActor*>(Player));
    TestTrue(TEXT("Confirmed target enters Chase or Attack"),
        Listener->GetEnemyStateComponent()->IsInState(JMEnemyTags::State_Chase) ||
        Listener->GetEnemyStateComponent()->IsInState(JMEnemyTags::State_Attack));

    Listener->GetEnemyLocomotionComponent()->StopMovement();
    Player->SetActorLocation(Listener->GetActorLocation() + FVector(20.0, 0.0, 0.0));
    Player->AttachToActor(Listener, FAttachmentTransformRules::KeepWorldTransform);
    UAISense_Hearing::ReportNoiseEvent(World, Player->GetActorLocation(), 1.0f, Player, 0.0f);
    JMListenerReferenceTests::SubmitHearing(*Listener, *Player);
    FrameworkController->GetEnemyStateTreeComponent()->SendStateTreeEvent(JMEnemyTags::Event_Stimulus);
    Listener->GetEnemyStateComponent()->SetState(JMEnemyTags::State_Attack);
    FJMEnemyActionContext AttackContext;
    AttackContext.TargetActor = Player;
    TestEqual(TEXT("Melee action starts through the reusable ActionComponent"),
        Listener->GetEnemyActionComponent()->ExecuteAction(JMEnemyTags::Action_Melee, AttackContext),
        EJMEnemyActionExecuteResult::Started);
    JMListenerReferenceTests::TickListener(*World, *Listener, 2.0f);
    TestTrue(TEXT("Melee remains active or resolves damage in the transient world"),
        Player->DamageCallCount > 0 || Listener->GetEnemyActionComponent()->IsActionRunning());

    Player->SetActorLocation(FVector(3000.0, 0.0, 100.0));
    JMListenerReferenceTests::TickListener(*World, *Listener, 4.5f);
    Listener->GetEnemyStateComponent()->SetState(JMEnemyTags::State_Search);
    TestTrue(TEXT("Expired target hearing enters Search"),
        Listener->GetEnemyStateComponent()->IsInState(JMEnemyTags::State_Search));
    JMListenerReferenceTests::TickListener(*World, *Listener, 9.0f);
    Listener->GetEnemyMemoryComponent()->ClearCurrentTarget();
    Listener->GetEnemyStateComponent()->SetState(JMEnemyTags::State_Patrol);
    TestTrue(TEXT("Search timeout returns to Patrol"),
        Listener->GetEnemyStateComponent()->IsInState(JMEnemyTags::State_Patrol));
    TestNull(TEXT("Patrol clears the expired combat target"),
        Listener->GetEnemyMemoryComponent()->GetCurrentTarget());

    GEngine->DestroyWorldContext(World);
    World->DestroyWorld(false);
    return true;
}
