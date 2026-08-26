#include "AI/SimpleEnemyAIController.h"
#include "StateTree/SimpleEnemyStateTreeNodes.h"

#include "AssetRegistry/AssetRegistryModule.h"
#include "Components/StateTreeAIComponent.h"
#include "Components/StateTreeAIComponentSchema.h"
#include "Conditions/StateTreeCommonConditions.h"
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

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMSimpleEnemyStateTreeAssetTest,
    "JM.MonsterFramework.Phase7.BuildAndValidatePredictiveStateTree",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMSimpleEnemyStateTreeAssetTest::RunTest(const FString& Parameters)
{
    constexpr TCHAR PackagePath[] = TEXT("/JMMonsterFramework/AI/ST_SimpleEnemy");
    constexpr TCHAR AssetName[] = TEXT("ST_SimpleEnemy");

    UPackage* Package = LoadPackage(nullptr, PackagePath, LOAD_None);
    if (!Package)
    {
        Package = CreatePackage(PackagePath);
    }

    UStateTree* StateTree = FindObject<UStateTree>(Package, AssetName);
    const bool bCreatedAsset = !IsValid(StateTree);
    if (bCreatedAsset)
    {
        StateTree = NewObject<UStateTree>(Package, AssetName, RF_Public | RF_Standalone | RF_Transactional);
    }

    TestNotNull(TEXT("StateTree asset exists"), StateTree);
    if (!StateTree)
    {
        return false;
    }

    const ASimpleEnemyAIController* ControllerDefaults = GetDefault<ASimpleEnemyAIController>();
    TestNotNull(TEXT("Controller owns a StateTree AI component"), ControllerDefaults->StateTreeComponent.Get());
    TestEqual(
        TEXT("Controller points at the plugin StateTree"),
        ControllerDefaults->StateTreeAsset.ToSoftObjectPath().ToString(),
        FString(TEXT("/JMMonsterFramework/AI/ST_SimpleEnemy.ST_SimpleEnemy")));

    UStateTreeEditorData* EditorData = NewObject<UStateTreeEditorData>(StateTree, NAME_None, RF_Transactional);
    EditorData->Schema = NewObject<UStateTreeAIComponentSchema>(EditorData, NAME_None, RF_Transactional);
    StateTree->EditorData = EditorData;

    UStateTreeState& Root = EditorData->AddRootState();
    UStateTreeState& Attack = Root.AddChildState(TEXT("Attack"));
    UStateTreeState& Chase = Root.AddChildState(TEXT("Chase"));
    UStateTreeState& RecentTracking = Root.AddChildState(TEXT("RecentTracking"));
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
    Attack.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &RecentTracking)
        .AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = false;

    Chase.AddEnterCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;
    Chase.AddEnterCondition<FJMSimpleEnemyTargetInAttackRangeCondition>().GetNode().bExpectedValue = false;
    Chase.AddTask<FJMSimpleEnemyMoveToTargetTask>();
    Chase.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Attack)
        .AddCondition<FJMSimpleEnemyTargetInAttackRangeCondition>().GetNode().bExpectedValue = true;
    Chase.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &RecentTracking)
        .AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = false;

    RecentTracking.AddEnterCondition<FJMSimpleEnemyHasRecentTrackingMemoryCondition>();
    RecentTracking.AddTask<FJMSimpleEnemyRecentTrackingTask>();
    RecentTracking.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Attack)
        .AddCondition<FJMSimpleEnemyTargetInAttackRangeCondition>().GetNode().bExpectedValue = true;
    auto& RecentTrackingToChase = RecentTracking.AddTransition(
        EStateTreeTransitionTrigger::OnTick,
        EStateTreeTransitionType::GotoState,
        &Chase);
    RecentTrackingToChase.AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;
    RecentTrackingToChase.AddCondition<FJMSimpleEnemyTargetInAttackRangeCondition>().GetNode().bExpectedValue = false;
    RecentTracking.AddTransition(
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
    TestTrue(TEXT("StateTree compiles"), bCompiled);
    TestTrue(TEXT("StateTree is ready to run"), StateTree->IsReadyToRun());
    TestEqual(TEXT("Predictive tree contains the seven Phase 7 states"), Root.Children.Num(), 7);
    TestEqual(TEXT("Attack requires sight and range"), Attack.EnterConditions.Num(), 2);
    TestEqual(TEXT("Attack has one basic attack task"), Attack.Tasks.Num(), 1);
    TestEqual(TEXT("Attack can chase or use Predictive loss tracking"), Attack.Transitions.Num(), 2);
    TestEqual(TEXT("Chase requires sight and out-of-range"), Chase.EnterConditions.Num(), 2);
    TestEqual(TEXT("Chase has one movement task"), Chase.Tasks.Num(), 1);
    TestEqual(TEXT("RecentTracking requires valid cached memory"), RecentTracking.EnterConditions.Num(), 1);
    TestEqual(TEXT("RecentTracking has one cached prediction task"), RecentTracking.Tasks.Num(), 1);
    TestEqual(TEXT("RecentTracking can attack, chase, or enter Investigate"), RecentTracking.Transitions.Num(), 3);
    TestEqual(TEXT("Patrol has one NavMesh movement task"), Patrol.Tasks.Num(), 1);
    TestEqual(TEXT("Patrol can enter Attack, Chase, or sound investigation"), Patrol.Transitions.Num(), 3);
    TestTrue(TEXT("Patrol radius is positive"), PatrolTask.PatrolRadius > 0.0f);
    TestTrue(TEXT("Patrol wait is finite and positive"), PatrolTask.WaitDuration > 0.0f);
    TestEqual(TEXT("Sound investigation requires one pending sound"), InvestigateSound.EnterConditions.Num(), 1);
    TestEqual(TEXT("Sound investigation has one movement task"), InvestigateSound.Tasks.Num(), 1);
    TestEqual(TEXT("Sound investigation can attack, chase, or return to Patrol"), InvestigateSound.Transitions.Num(), 3);
    TestEqual(TEXT("Investigate has one location movement task"), Investigate.Tasks.Num(), 1);
    TestEqual(TEXT("Investigate can attack, chase, or enter Search"), Investigate.Transitions.Num(), 3);
    TestEqual(TEXT("Search has one finite rotation task"), Search.Tasks.Num(), 1);
    TestEqual(TEXT("Search can attack, chase, or return to Patrol"), Search.Transitions.Num(), 3);
    TestTrue(TEXT("Search duration is finite and positive"), SearchTask.SearchDuration > 0.0f);

    if (HasAnyErrors())
    {
        return false;
    }

    StateTree->MarkPackageDirty();
    if (bCreatedAsset)
    {
        FAssetRegistryModule::AssetCreated(StateTree);
    }

    const FString Filename = FPackageName::LongPackageNameToFilename(
        PackagePath,
        FPackageName::GetAssetPackageExtension());
    FSavePackageArgs SaveArgs;
    SaveArgs.TopLevelFlags = RF_Public | RF_Standalone;
    SaveArgs.SaveFlags = SAVE_NoError;
    TestTrue(TEXT("StateTree package saves"), UPackage::SavePackage(Package, StateTree, *Filename, SaveArgs));

    return !HasAnyErrors();
}

#endif
