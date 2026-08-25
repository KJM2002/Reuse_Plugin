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
    "JM.MonsterFramework.Phase3.BuildAndValidateStateTree",
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
    UStateTreeState& Idle = Root.AddChildState(TEXT("Idle"));
    UStateTreeState& Investigate = Root.AddChildState(TEXT("InvestigateLastLocation"));

    Chase.AddEnterCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;
    Chase.AddTask<FJMSimpleEnemyMoveToTargetTask>();
    Chase.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Investigate)
        .AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = false;

    Idle.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Chase)
        .AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;

    Investigate.AddTask<FJMSimpleEnemyMoveToLastSeenLocationTask>();
    Investigate.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Chase)
        .AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;
    Investigate.AddTransition(EStateTreeTransitionTrigger::OnStateCompleted, EStateTreeTransitionType::GotoState, &Idle);

    FStateTreeCompilerLog CompilerLog;
    FStateTreeCompiler Compiler(CompilerLog);
    const bool bCompiled = Compiler.Compile(*StateTree);
    if (!bCompiled)
    {
        CompilerLog.DumpToLog(LogTemp);
    }
    TestTrue(TEXT("StateTree compiles"), bCompiled);
    TestTrue(TEXT("StateTree is ready to run"), StateTree->IsReadyToRun());
    TestEqual(TEXT("Root contains Chase, Idle, and InvestigateLastLocation"), Root.Children.Num(), 3);
    TestEqual(TEXT("Chase has one condition"), Chase.EnterConditions.Num(), 1);
    TestEqual(TEXT("Chase has one movement task"), Chase.Tasks.Num(), 1);
    TestEqual(TEXT("Investigate has one location movement task"), Investigate.Tasks.Num(), 1);
    TestEqual(TEXT("Investigate can reacquire or finish at Idle"), Investigate.Transitions.Num(), 2);

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
