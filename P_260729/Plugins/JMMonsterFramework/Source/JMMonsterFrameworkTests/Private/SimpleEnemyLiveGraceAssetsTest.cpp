#include "AI/SimpleEnemyAIController.h"
#include "Characters/SimpleEnemyCharacter.h"
#include "StateTree/SimpleEnemyStateTreeNodes.h"

#include "AssetRegistry/AssetRegistryModule.h"
#include "Components/StateTreeAIComponentSchema.h"
#include "Engine/Blueprint.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Misc/AutomationTest.h"
#include "Misc/PackageName.h"
#include "StateTree.h"
#include "StateTreeCompiler.h"
#include "StateTreeCompilerLog.h"
#include "StateTreeEditorData.h"
#include "StateTreeState.h"
#include "UObject/Package.h"
#include "UObject/SavePackage.h"

#if WITH_DEV_AUTOMATION_TESTS

namespace
{
    bool SavePluginAsset(UObject& Asset, const TCHAR* PackagePath)
    {
        UPackage* Package = Asset.GetOutermost();
        Package->MarkPackageDirty();

        const FString Filename = FPackageName::LongPackageNameToFilename(
            PackagePath,
            FPackageName::GetAssetPackageExtension());
        FSavePackageArgs SaveArgs;
        SaveArgs.TopLevelFlags = RF_Public | RF_Standalone;
        SaveArgs.SaveFlags = SAVE_NoError;
        return UPackage::SavePackage(Package, &Asset, *Filename, SaveArgs);
    }

    UBlueprint* FindOrCreateBlueprint(
        const TCHAR* PackagePath,
        const TCHAR* AssetName,
        UClass& ParentClass)
    {
        UPackage* Package = FPackageName::DoesPackageExist(PackagePath)
            ? LoadPackage(nullptr, PackagePath, LOAD_None)
            : nullptr;
        UBlueprint* Blueprint = Package ? FindObject<UBlueprint>(Package, AssetName) : nullptr;
        if (!Blueprint)
        {
            Package = Package ? Package : CreatePackage(PackagePath);
            Blueprint = FKismetEditorUtilities::CreateBlueprint(
                &ParentClass,
                Package,
                AssetName,
                BPTYPE_Normal,
                UBlueprint::StaticClass(),
                UBlueprintGeneratedClass::StaticClass(),
                TEXT("JMMonsterFrameworkPhase4_6"));
            if (Blueprint)
            {
                FAssetRegistryModule::AssetCreated(Blueprint);
            }
        }
        if (Blueprint)
        {
            FKismetEditorUtilities::CompileBlueprint(Blueprint);
        }
        return Blueprint;
    }
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMSimpleEnemyLiveGraceAssetsTest,
    "JM.MonsterFramework.Phase7.BuildAndValidateLiveGraceAssets",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMSimpleEnemyLiveGraceAssetsTest::RunTest(const FString& Parameters)
{
    constexpr TCHAR StateTreePackagePath[] = TEXT("/JMMonsterFramework/AI/ST_SimpleEnemy_LiveGrace");
    constexpr TCHAR StateTreeAssetName[] = TEXT("ST_SimpleEnemy_LiveGrace");
    constexpr TCHAR ControllerPackagePath[] = TEXT("/JMMonsterFramework/AI/BP_SimpleEnemyAIController_LiveGrace");
    constexpr TCHAR ControllerAssetName[] = TEXT("BP_SimpleEnemyAIController_LiveGrace");
    constexpr TCHAR CharacterPackagePath[] = TEXT("/JMMonsterFramework/Blueprints/BP_SimpleEnemy_LiveGrace");
    constexpr TCHAR CharacterAssetName[] = TEXT("BP_SimpleEnemy_LiveGrace");

    const ASimpleEnemyAIController* NativeDefaults = GetDefault<ASimpleEnemyAIController>();
    TestEqual(
        TEXT("The native/predictive selection remains unchanged"),
        NativeDefaults->StateTreeAsset.ToSoftObjectPath().ToString(),
        FString(TEXT("/JMMonsterFramework/AI/ST_SimpleEnemy.ST_SimpleEnemy")));

    UPackage* StateTreePackage = FPackageName::DoesPackageExist(StateTreePackagePath)
        ? LoadPackage(nullptr, StateTreePackagePath, LOAD_None)
        : nullptr;
    if (!StateTreePackage)
    {
        StateTreePackage = CreatePackage(StateTreePackagePath);
    }
    UStateTree* StateTree = FindObject<UStateTree>(StateTreePackage, StateTreeAssetName);
    const bool bCreatedStateTree = !IsValid(StateTree);
    if (!StateTree)
    {
        StateTree = NewObject<UStateTree>(
            StateTreePackage,
            StateTreeAssetName,
            RF_Public | RF_Standalone | RF_Transactional);
    }
    TestNotNull(TEXT("Live Grace StateTree exists"), StateTree);
    if (!StateTree)
    {
        return false;
    }

    UStateTreeEditorData* EditorData = NewObject<UStateTreeEditorData>(StateTree, NAME_None, RF_Transactional);
    EditorData->Schema = NewObject<UStateTreeAIComponentSchema>(EditorData, NAME_None, RF_Transactional);
    StateTree->EditorData = EditorData;

    UStateTreeState& Root = EditorData->AddRootState();
    UStateTreeState& Attack = Root.AddChildState(TEXT("Attack"));
    UStateTreeState& Chase = Root.AddChildState(TEXT("Chase"));
    UStateTreeState& LiveGrace = Root.AddChildState(TEXT("LiveGraceTracking"));
    UStateTreeState& InvestigateSound = Root.AddChildState(TEXT("InvestigateSound"));
    UStateTreeState& Patrol = Root.AddChildState(TEXT("Patrol"));
    UStateTreeState& Investigate = Root.AddChildState(TEXT("InvestigateLastLocation"));
    UStateTreeState& Search = Root.AddChildState(TEXT("Search"));

    Attack.AddEnterCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;
    Attack.AddEnterCondition<FJMSimpleEnemyTargetInAttackRangeCondition>().GetNode().bExpectedValue = true;
    Attack.AddTask<FJMSimpleEnemyBasicAttackTask>();
    auto& AttackToChase = Attack.AddTransition(
        EStateTreeTransitionTrigger::OnTick,
        EStateTreeTransitionType::GotoState,
        &Chase);
    AttackToChase.AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;
    AttackToChase.AddCondition<FJMSimpleEnemyTargetInAttackRangeCondition>().GetNode().bExpectedValue = false;
    Attack.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &LiveGrace)
        .AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = false;

    Chase.AddEnterCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;
    Chase.AddEnterCondition<FJMSimpleEnemyTargetInAttackRangeCondition>().GetNode().bExpectedValue = false;
    Chase.AddTask<FJMSimpleEnemyMoveToTargetTask>();
    Chase.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Attack)
        .AddCondition<FJMSimpleEnemyTargetInAttackRangeCondition>().GetNode().bExpectedValue = true;
    Chase.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &LiveGrace)
        .AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = false;

    LiveGrace.AddEnterCondition<FJMSimpleEnemyHasLiveGraceTrackingCondition>();
    LiveGrace.AddTask<FJMSimpleEnemyLiveGraceTrackingTask>();
    LiveGrace.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Attack)
        .AddCondition<FJMSimpleEnemyTargetInAttackRangeCondition>().GetNode().bExpectedValue = true;
    auto& LiveGraceToChase = LiveGrace.AddTransition(
        EStateTreeTransitionTrigger::OnTick,
        EStateTreeTransitionType::GotoState,
        &Chase);
    LiveGraceToChase.AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;
    LiveGraceToChase.AddCondition<FJMSimpleEnemyTargetInAttackRangeCondition>().GetNode().bExpectedValue = false;
    LiveGrace.AddTransition(
        EStateTreeTransitionTrigger::OnStateCompleted,
        EStateTreeTransitionType::GotoState,
        &Investigate);

    FJMSimpleEnemyPatrolTask& PatrolTask = Patrol.AddTask<FJMSimpleEnemyPatrolTask>().GetNode();
    Patrol.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Attack)
        .AddCondition<FJMSimpleEnemyTargetInAttackRangeCondition>().GetNode().bExpectedValue = true;
    auto& PatrolToChase = Patrol.AddTransition(
        EStateTreeTransitionTrigger::OnTick,
        EStateTreeTransitionType::GotoState,
        &Chase);
    PatrolToChase.AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;
    PatrolToChase.AddCondition<FJMSimpleEnemyTargetInAttackRangeCondition>().GetNode().bExpectedValue = false;
    Patrol.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &InvestigateSound)
        .AddCondition<FJMSimpleEnemyHasHeardSoundCondition>();

    InvestigateSound.AddEnterCondition<FJMSimpleEnemyHasHeardSoundCondition>();
    InvestigateSound.AddTask<FJMSimpleEnemyInvestigateSoundTask>();
    InvestigateSound.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Attack)
        .AddCondition<FJMSimpleEnemyTargetInAttackRangeCondition>().GetNode().bExpectedValue = true;
    auto& SoundToChase = InvestigateSound.AddTransition(
        EStateTreeTransitionTrigger::OnTick,
        EStateTreeTransitionType::GotoState,
        &Chase);
    SoundToChase.AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;
    SoundToChase.AddCondition<FJMSimpleEnemyTargetInAttackRangeCondition>().GetNode().bExpectedValue = false;
    InvestigateSound.AddTransition(
        EStateTreeTransitionTrigger::OnStateCompleted,
        EStateTreeTransitionType::GotoState,
        &Patrol);

    Investigate.AddTask<FJMSimpleEnemyMoveToLastSeenLocationTask>();
    Investigate.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Attack)
        .AddCondition<FJMSimpleEnemyTargetInAttackRangeCondition>().GetNode().bExpectedValue = true;
    auto& InvestigateToChase = Investigate.AddTransition(
        EStateTreeTransitionTrigger::OnTick,
        EStateTreeTransitionType::GotoState,
        &Chase);
    InvestigateToChase.AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;
    InvestigateToChase.AddCondition<FJMSimpleEnemyTargetInAttackRangeCondition>().GetNode().bExpectedValue = false;
    Investigate.AddTransition(EStateTreeTransitionTrigger::OnStateCompleted, EStateTreeTransitionType::GotoState, &Search);

    FJMSimpleEnemySearchTask& SearchTask = Search.AddTask<FJMSimpleEnemySearchTask>().GetNode();
    SearchTask.SearchDuration = 4.0f;
    SearchTask.RotationSpeedDegrees = 90.0f;
    Search.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Attack)
        .AddCondition<FJMSimpleEnemyTargetInAttackRangeCondition>().GetNode().bExpectedValue = true;
    auto& SearchToChase = Search.AddTransition(
        EStateTreeTransitionTrigger::OnTick,
        EStateTreeTransitionType::GotoState,
        &Chase);
    SearchToChase.AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;
    SearchToChase.AddCondition<FJMSimpleEnemyTargetInAttackRangeCondition>().GetNode().bExpectedValue = false;
    Search.AddTransition(EStateTreeTransitionTrigger::OnStateCompleted, EStateTreeTransitionType::GotoState, &Patrol);

    FStateTreeCompilerLog CompilerLog;
    FStateTreeCompiler Compiler(CompilerLog);
    const bool bCompiled = Compiler.Compile(*StateTree);
    if (!bCompiled)
    {
        CompilerLog.DumpToLog(LogTemp);
    }
    TestTrue(TEXT("Live Grace StateTree compiles"), bCompiled);
    TestTrue(TEXT("Live Grace StateTree is ready to run"), StateTree->IsReadyToRun());
    TestEqual(TEXT("Live Grace tree contains seven Phase 7 states"), Root.Children.Num(), 7);
    TestEqual(TEXT("Live Grace tree Attack requires sight and range"), Attack.EnterConditions.Num(), 2);
    TestEqual(TEXT("Live Grace tree Attack has one task"), Attack.Tasks.Num(), 1);
    TestEqual(TEXT("Attack can chase or use Live Grace loss tracking"), Attack.Transitions.Num(), 2);
    TestEqual(TEXT("Live Grace state has one validity condition"), LiveGrace.EnterConditions.Num(), 1);
    TestEqual(TEXT("Live Grace state has one live tracking task"), LiveGrace.Tasks.Num(), 1);
    TestEqual(TEXT("Live Grace can attack, chase, or investigate"), LiveGrace.Transitions.Num(), 3);
    TestEqual(TEXT("Live Grace tree Patrol has one NavMesh task"), Patrol.Tasks.Num(), 1);
    TestEqual(TEXT("Live Grace tree Patrol can enter Attack, Chase, or sound investigation"), Patrol.Transitions.Num(), 3);
    TestTrue(TEXT("Live Grace tree Patrol radius is positive"), PatrolTask.PatrolRadius > 0.0f);
    TestTrue(TEXT("Live Grace tree Patrol wait is finite"), PatrolTask.WaitDuration > 0.0f);
    TestEqual(TEXT("Live Grace sound investigation requires pending sound"), InvestigateSound.EnterConditions.Num(), 1);
    TestEqual(TEXT("Live Grace sound investigation has one task"), InvestigateSound.Tasks.Num(), 1);
    TestEqual(TEXT("Live Grace sound investigation can attack, chase, or Patrol"), InvestigateSound.Transitions.Num(), 3);
    TestTrue(TEXT("Search remains finite"), SearchTask.SearchDuration > 0.0f);

    if (bCreatedStateTree)
    {
        FAssetRegistryModule::AssetCreated(StateTree);
    }
    TestTrue(TEXT("Live Grace StateTree saves"), SavePluginAsset(*StateTree, StateTreePackagePath));

    UBlueprint* PredictiveControllerBlueprint = LoadObject<UBlueprint>(
        nullptr,
        TEXT("/JMMonsterFramework/AI/BP_SimpleEnemyAIController.BP_SimpleEnemyAIController"));
    UClass* ControllerParentClass = ASimpleEnemyAIController::StaticClass();
    if (IsValid(PredictiveControllerBlueprint)
        && IsValid(PredictiveControllerBlueprint->GeneratedClass))
    {
        ControllerParentClass = PredictiveControllerBlueprint->GeneratedClass.Get();
    }
    UBlueprint* LiveControllerBlueprint = FindOrCreateBlueprint(
        ControllerPackagePath,
        ControllerAssetName,
        *ControllerParentClass);
    TestNotNull(TEXT("Live Grace controller preset exists"), LiveControllerBlueprint);
    ASimpleEnemyAIController* LiveControllerDefaults = LiveControllerBlueprint
        ? Cast<ASimpleEnemyAIController>(LiveControllerBlueprint->GeneratedClass->GetDefaultObject())
        : nullptr;
    TestNotNull(TEXT("Live Grace controller preset has compatible defaults"), LiveControllerDefaults);
    if (LiveControllerDefaults)
    {
        LiveControllerDefaults->Modify();
        LiveControllerDefaults->StateTreeAsset = StateTree;
        LiveControllerDefaults->LiveGraceDuration = 1.5f;
        LiveControllerBlueprint->MarkPackageDirty();
        TestEqual(
            TEXT("Live Grace controller selects only the new StateTree"),
            LiveControllerDefaults->StateTreeAsset.ToSoftObjectPath().ToString(),
            FString(TEXT("/JMMonsterFramework/AI/ST_SimpleEnemy_LiveGrace.ST_SimpleEnemy_LiveGrace")));
        TestTrue(TEXT("Live Grace controller preset saves"), SavePluginAsset(*LiveControllerBlueprint, ControllerPackagePath));
    }

    UBlueprint* PredictiveCharacterBlueprint = LoadObject<UBlueprint>(
        nullptr,
        TEXT("/JMMonsterFramework/Blueprints/BP_SimpleEnemy.BP_SimpleEnemy"));
    UClass* CharacterParentClass = ASimpleEnemyCharacter::StaticClass();
    if (IsValid(PredictiveCharacterBlueprint)
        && IsValid(PredictiveCharacterBlueprint->GeneratedClass))
    {
        CharacterParentClass = PredictiveCharacterBlueprint->GeneratedClass.Get();
    }
    UBlueprint* LiveCharacterBlueprint = FindOrCreateBlueprint(
        CharacterPackagePath,
        CharacterAssetName,
        *CharacterParentClass);
    TestNotNull(TEXT("Live Grace enemy preset exists"), LiveCharacterBlueprint);
    ASimpleEnemyCharacter* LiveCharacterDefaults = LiveCharacterBlueprint
        ? Cast<ASimpleEnemyCharacter>(LiveCharacterBlueprint->GeneratedClass->GetDefaultObject())
        : nullptr;
    TestNotNull(TEXT("Live Grace enemy preset has compatible defaults"), LiveCharacterDefaults);
    if (LiveCharacterDefaults && LiveControllerBlueprint)
    {
        LiveCharacterDefaults->Modify();
        LiveCharacterDefaults->AIControllerClass = LiveControllerBlueprint->GeneratedClass;
        LiveCharacterBlueprint->MarkPackageDirty();
        TestTrue(
            TEXT("Live Grace enemy selects the Live Grace controller preset"),
            LiveCharacterDefaults->AIControllerClass.Get()
                == LiveControllerBlueprint->GeneratedClass.Get());
        TestTrue(TEXT("Live Grace enemy preset saves"), SavePluginAsset(*LiveCharacterBlueprint, CharacterPackagePath));
    }

    return !HasAnyErrors();
}

#endif
