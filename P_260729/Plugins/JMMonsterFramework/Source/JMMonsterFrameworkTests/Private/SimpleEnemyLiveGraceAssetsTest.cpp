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
    "JM.MonsterFramework.Phase4_6.BuildAndValidateAssets",
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
    UStateTreeState& Chase = Root.AddChildState(TEXT("Chase"));
    UStateTreeState& LiveGrace = Root.AddChildState(TEXT("LiveGraceTracking"));
    UStateTreeState& Idle = Root.AddChildState(TEXT("Idle"));
    UStateTreeState& Investigate = Root.AddChildState(TEXT("InvestigateLastLocation"));
    UStateTreeState& Search = Root.AddChildState(TEXT("Search"));

    Chase.AddEnterCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;
    Chase.AddTask<FJMSimpleEnemyMoveToTargetTask>();
    Chase.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &LiveGrace)
        .AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = false;

    LiveGrace.AddEnterCondition<FJMSimpleEnemyHasLiveGraceTrackingCondition>();
    LiveGrace.AddTask<FJMSimpleEnemyLiveGraceTrackingTask>();
    LiveGrace.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Chase)
        .AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;
    LiveGrace.AddTransition(
        EStateTreeTransitionTrigger::OnStateCompleted,
        EStateTreeTransitionType::GotoState,
        &Investigate);

    Idle.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Chase)
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
    Search.AddTransition(EStateTreeTransitionTrigger::OnStateCompleted, EStateTreeTransitionType::GotoState, &Idle);

    FStateTreeCompilerLog CompilerLog;
    FStateTreeCompiler Compiler(CompilerLog);
    const bool bCompiled = Compiler.Compile(*StateTree);
    if (!bCompiled)
    {
        CompilerLog.DumpToLog(LogTemp);
    }
    TestTrue(TEXT("Live Grace StateTree compiles"), bCompiled);
    TestTrue(TEXT("Live Grace StateTree is ready to run"), StateTree->IsReadyToRun());
    TestEqual(TEXT("Live Grace tree contains five independent states"), Root.Children.Num(), 5);
    TestEqual(TEXT("Live Grace state has one validity condition"), LiveGrace.EnterConditions.Num(), 1);
    TestEqual(TEXT("Live Grace state has one live tracking task"), LiveGrace.Tasks.Num(), 1);
    TestEqual(TEXT("Live Grace can reacquire or investigate"), LiveGrace.Transitions.Num(), 2);
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
