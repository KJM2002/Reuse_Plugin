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
    "JM.MonsterFramework.Phase5.BuildAndValidatePredictiveStateTree",
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
    UStateTreeState& Chase = Root.AddChildState(TEXT("Chase"));
    UStateTreeState& RecentTracking = Root.AddChildState(TEXT("RecentTracking"));
    UStateTreeState& Patrol = Root.AddChildState(TEXT("Patrol"));
    UStateTreeState& Investigate = Root.AddChildState(TEXT("InvestigateLastLocation"));
    UStateTreeState& Search = Root.AddChildState(TEXT("Search"));

    Chase.AddEnterCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;
    Chase.AddTask<FJMSimpleEnemyMoveToTargetTask>();
    Chase.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &RecentTracking)
        .AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = false;

    RecentTracking.AddEnterCondition<FJMSimpleEnemyHasRecentTrackingMemoryCondition>();
    RecentTracking.AddTask<FJMSimpleEnemyRecentTrackingTask>();
    RecentTracking.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Chase)
        .AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;
    RecentTracking.AddTransition(
        EStateTreeTransitionTrigger::OnStateCompleted,
        EStateTreeTransitionType::GotoState,
        &Investigate);

    FJMSimpleEnemyPatrolTask& PatrolTask = Patrol.AddTask<FJMSimpleEnemyPatrolTask>().GetNode();
    Patrol.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Chase)
        .AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;

    Investigate.AddTask<FJMSimpleEnemyMoveToLastSeenLocationTask>();
    Investigate.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Chase)
        .AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;
    Investigate.AddTransition(EStateTreeTransitionTrigger::OnStateCompleted, EStateTreeTransitionType::GotoState, &Search);

    FJMSimpleEnemySearchTask& SearchTask = Search.AddTask<FJMSimpleEnemySearchTask>().GetNode();
    SearchTask.SearchDuration = 4.0f;
    SearchTask.RotationSpeedDegrees = 90.0f;
    Search.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Chase)
        .AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;
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
    TestEqual(TEXT("Predictive tree contains the five Phase 5 states"), Root.Children.Num(), 5);
    TestEqual(TEXT("Chase has one condition"), Chase.EnterConditions.Num(), 1);
    TestEqual(TEXT("Chase has one movement task"), Chase.Tasks.Num(), 1);
    TestEqual(TEXT("RecentTracking requires valid cached memory"), RecentTracking.EnterConditions.Num(), 1);
    TestEqual(TEXT("RecentTracking has one cached prediction task"), RecentTracking.Tasks.Num(), 1);
    TestEqual(TEXT("RecentTracking can reacquire or enter Investigate"), RecentTracking.Transitions.Num(), 2);
    TestEqual(TEXT("Patrol has one NavMesh movement task"), Patrol.Tasks.Num(), 1);
    TestEqual(TEXT("Patrol can immediately enter Chase"), Patrol.Transitions.Num(), 1);
    TestTrue(TEXT("Patrol radius is positive"), PatrolTask.PatrolRadius > 0.0f);
    TestTrue(TEXT("Patrol wait is finite and positive"), PatrolTask.WaitDuration > 0.0f);
    TestEqual(TEXT("Investigate has one location movement task"), Investigate.Tasks.Num(), 1);
    TestEqual(TEXT("Investigate can reacquire or enter Search"), Investigate.Transitions.Num(), 2);
    TestEqual(TEXT("Search has one finite rotation task"), Search.Tasks.Num(), 1);
    TestEqual(TEXT("Search can reacquire or return to Patrol"), Search.Transitions.Num(), 2);
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
