#include "AI/WatcherEnemyAIController.h"
#include "Characters/SimpleEnemyCharacter.h"
#include "StateTree/WatcherEnemyStateTreeNodes.h"

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
    bool SaveWatcherAsset(UObject& Asset, const TCHAR* PackagePath)
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

    UBlueprint* FindOrCreateWatcherBlueprint(
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
                TEXT("JMMonsterFrameworkPhase10"));
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
    FJMWatcherEnemyAssetsTest,
    "JM.MonsterFramework.Phase10.BuildAndValidateWatcherAssets",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMWatcherEnemyAssetsTest::RunTest(const FString& Parameters)
{
    constexpr TCHAR StateTreePackagePath[] = TEXT("/JMMonsterFramework/AI/ST_WatcherEnemy");
    constexpr TCHAR StateTreeAssetName[] = TEXT("ST_WatcherEnemy");
    constexpr TCHAR ControllerPackagePath[] = TEXT("/JMMonsterFramework/AI/BP_WatcherEnemyAIController");
    constexpr TCHAR ControllerAssetName[] = TEXT("BP_WatcherEnemyAIController");
    constexpr TCHAR CharacterPackagePath[] = TEXT("/JMMonsterFramework/Blueprints/BP_WatcherEnemy");
    constexpr TCHAR CharacterAssetName[] = TEXT("BP_WatcherEnemy");

    const AWatcherEnemyAIController* NativeDefaults = GetDefault<AWatcherEnemyAIController>();
    TestEqual(
        TEXT("Watcher native controller selects only its StateTree"),
        NativeDefaults->StateTreeAsset.ToSoftObjectPath().ToString(),
        FString(TEXT("/JMMonsterFramework/AI/ST_WatcherEnemy.ST_WatcherEnemy")));
    TestEqual(TEXT("Watcher accepts most of the actual camera view"), NativeDefaults->GazeScreenEdgeFraction, 0.85f);
    TestEqual(TEXT("Watcher uses a short release grace"), NativeDefaults->GazeLostGraceDuration, 0.12f);

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
    TestNotNull(TEXT("Watcher StateTree exists"), StateTree);
    if (!StateTree)
    {
        return false;
    }

    UStateTreeEditorData* EditorData = NewObject<UStateTreeEditorData>(StateTree, NAME_None, RF_Transactional);
    EditorData->Schema = NewObject<UStateTreeAIComponentSchema>(EditorData, NAME_None, RF_Transactional);
    StateTree->EditorData = EditorData;

    UStateTreeState& Root = EditorData->AddRootState();
    UStateTreeState& WatchedStop = Root.AddChildState(TEXT("WatchedStop"));
    UStateTreeState& UnwatchedMove = Root.AddChildState(TEXT("UnwatchedMove"));

    WatchedStop.AddEnterCondition<FJMWatcherIsWatchedCondition>().GetNode().bExpectedValue = true;
    WatchedStop.AddTask<FJMWatcherStopTask>();
    WatchedStop.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &UnwatchedMove)
        .AddCondition<FJMWatcherIsWatchedCondition>().GetNode().bExpectedValue = false;

    UnwatchedMove.AddEnterCondition<FJMWatcherIsWatchedCondition>().GetNode().bExpectedValue = false;
    UnwatchedMove.AddTask<FJMWatcherMoveTask>();
    UnwatchedMove.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &WatchedStop)
        .AddCondition<FJMWatcherIsWatchedCondition>().GetNode().bExpectedValue = true;

    FStateTreeCompilerLog CompilerLog;
    FStateTreeCompiler Compiler(CompilerLog);
    const bool bCompiled = Compiler.Compile(*StateTree);
    if (!bCompiled)
    {
        CompilerLog.DumpToLog(LogTemp);
    }
    TestTrue(TEXT("Watcher StateTree compiles"), bCompiled);
    TestTrue(TEXT("Watcher StateTree is ready to run"), StateTree->IsReadyToRun());
    TestEqual(TEXT("Watcher has only the two Gaze states"), Root.Children.Num(), 2);
    TestEqual(TEXT("WatchedStop has one task and one exit"), WatchedStop.Tasks.Num(), 1);
    TestEqual(TEXT("WatchedStop has one transition"), WatchedStop.Transitions.Num(), 1);
    TestEqual(TEXT("UnwatchedMove has one task and one exit"), UnwatchedMove.Tasks.Num(), 1);
    TestEqual(TEXT("UnwatchedMove has one transition"), UnwatchedMove.Transitions.Num(), 1);
    if (HasAnyErrors())
    {
        return false;
    }
    if (bCreatedStateTree)
    {
        FAssetRegistryModule::AssetCreated(StateTree);
    }
    TestTrue(TEXT("Watcher StateTree saves"), SaveWatcherAsset(*StateTree, StateTreePackagePath));

    UBlueprint* ControllerBlueprint = FindOrCreateWatcherBlueprint(
        ControllerPackagePath,
        ControllerAssetName,
        *AWatcherEnemyAIController::StaticClass());
    TestNotNull(TEXT("Watcher controller Blueprint exists"), ControllerBlueprint);
    AWatcherEnemyAIController* ControllerDefaults = ControllerBlueprint
        ? Cast<AWatcherEnemyAIController>(ControllerBlueprint->GeneratedClass->GetDefaultObject())
        : nullptr;
    TestNotNull(TEXT("Watcher controller Blueprint has native Watcher defaults"), ControllerDefaults);
    if (ControllerDefaults)
    {
        ControllerDefaults->Modify();
        ControllerDefaults->StateTreeAsset = StateTree;
        ControllerDefaults->GazeScreenEdgeFraction = 0.85f;
        ControllerDefaults->GazeLostGraceDuration = 0.12f;
        ControllerBlueprint->MarkPackageDirty();
        TestEqual(
            TEXT("Watcher Blueprint selects the Watcher StateTree"),
            ControllerDefaults->StateTreeAsset.ToSoftObjectPath().ToString(),
            FString(TEXT("/JMMonsterFramework/AI/ST_WatcherEnemy.ST_WatcherEnemy")));
        TestEqual(
            TEXT("Watcher Blueprint preserves native screen fraction"),
            ControllerDefaults->GazeScreenEdgeFraction,
            0.85f);
        TestEqual(
            TEXT("Watcher Blueprint preserves native release grace"),
            ControllerDefaults->GazeLostGraceDuration,
            0.12f);
        TestTrue(TEXT("Watcher controller Blueprint saves"), SaveWatcherAsset(*ControllerBlueprint, ControllerPackagePath));
    }

    UBlueprint* BaseEnemyBlueprint = LoadObject<UBlueprint>(
        nullptr,
        TEXT("/JMMonsterFramework/Blueprints/BP_SimpleEnemy.BP_SimpleEnemy"));
    UClass* CharacterParentClass = IsValid(BaseEnemyBlueprint) && IsValid(BaseEnemyBlueprint->GeneratedClass)
        ? BaseEnemyBlueprint->GeneratedClass.Get()
        : ASimpleEnemyCharacter::StaticClass();
    UBlueprint* CharacterBlueprint = FindOrCreateWatcherBlueprint(
        CharacterPackagePath,
        CharacterAssetName,
        *CharacterParentClass);
    TestNotNull(TEXT("Watcher enemy Blueprint exists"), CharacterBlueprint);
    ASimpleEnemyCharacter* CharacterDefaults = CharacterBlueprint
        ? Cast<ASimpleEnemyCharacter>(CharacterBlueprint->GeneratedClass->GetDefaultObject())
        : nullptr;
    TestNotNull(TEXT("Watcher enemy Blueprint has compatible character defaults"), CharacterDefaults);
    if (CharacterDefaults && ControllerBlueprint)
    {
        CharacterDefaults->Modify();
        CharacterDefaults->AIControllerClass = ControllerBlueprint->GeneratedClass;
        CharacterDefaults->AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
        CharacterBlueprint->MarkPackageDirty();
        TestTrue(
            TEXT("Watcher enemy selects the actual Watcher controller Blueprint"),
            CharacterDefaults->AIControllerClass.Get() == ControllerBlueprint->GeneratedClass.Get());
        TestEqual(
            TEXT("Watcher enemy possesses when placed or spawned"),
            CharacterDefaults->AutoPossessAI,
            EAutoPossessAI::PlacedInWorldOrSpawned);
        TestTrue(TEXT("Watcher enemy Blueprint saves"), SaveWatcherAsset(*CharacterBlueprint, CharacterPackagePath));
    }

    return !HasAnyErrors();
}

#endif
