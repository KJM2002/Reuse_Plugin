#include "AI/StalkerEnemyAIController.h"
#include "Characters/SimpleEnemyCharacter.h"
#include "StateTree/SimpleEnemyStateTreeNodes.h"
#include "StateTree/StalkerEnemyStateTreeNodes.h"

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
    bool SaveStalkerAsset(UObject& Asset, const TCHAR* PackagePath)
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

    UBlueprint* FindOrCreateStalkerBlueprint(
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
                TEXT("JMMonsterFrameworkStalker"));
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

    void AddDistanceTransitions(
        UStateTreeState& Source,
        UStateTreeState& Retreat,
        UStateTreeState& HoldDistance,
        UStateTreeState& Approach)
    {
        Source.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Retreat)
            .AddCondition<FJMStalkerDistanceBandCondition>().GetNode().ExpectedBand = EJMStalkerDistanceBand::TooClose;
        Source.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &HoldDistance)
            .AddCondition<FJMStalkerDistanceBandCondition>().GetNode().ExpectedBand = EJMStalkerDistanceBand::Preferred;
        Source.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Approach)
            .AddCondition<FJMStalkerDistanceBandCondition>().GetNode().ExpectedBand = EJMStalkerDistanceBand::TooFar;
    }
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMStalkerEnemyAssetsTest,
    "JM.MonsterFramework.Stalker.BuildAndValidateAssets",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMStalkerEnemyAssetsTest::RunTest(const FString& Parameters)
{
    constexpr TCHAR StateTreePackagePath[] = TEXT("/JMMonsterFramework/AI/ST_StalkerEnemy");
    constexpr TCHAR StateTreeAssetName[] = TEXT("ST_StalkerEnemy");
    constexpr TCHAR ControllerPackagePath[] = TEXT("/JMMonsterFramework/AI/BP_StalkerEnemyAIController");
    constexpr TCHAR ControllerAssetName[] = TEXT("BP_StalkerEnemyAIController");
    constexpr TCHAR CharacterPackagePath[] = TEXT("/JMMonsterFramework/Blueprints/BP_StalkerEnemy");
    constexpr TCHAR CharacterAssetName[] = TEXT("BP_StalkerEnemy");

    const AStalkerEnemyAIController* NativeDefaults = GetDefault<AStalkerEnemyAIController>();
    TestEqual(
        TEXT("Stalker native controller selects its StateTree"),
        NativeDefaults->StateTreeAsset.ToSoftObjectPath().ToString(),
        FString(TEXT("/JMMonsterFramework/AI/ST_StalkerEnemy.ST_StalkerEnemy")));
    TestTrue(TEXT("Stalker minimum distance is positive"), NativeDefaults->MinimumFollowDistance > 0.0f);
    TestTrue(
        TEXT("Stalker maximum distance exceeds minimum"),
        NativeDefaults->MaximumFollowDistance > NativeDefaults->MinimumFollowDistance);
    TestTrue(TEXT("Stalker hysteresis is positive"), NativeDefaults->DistanceHysteresis > 0.0f);

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
    TestNotNull(TEXT("Stalker StateTree exists"), StateTree);
    if (!StateTree)
    {
        return false;
    }

    UStateTreeEditorData* EditorData = NewObject<UStateTreeEditorData>(StateTree, NAME_None, RF_Transactional);
    EditorData->Schema = NewObject<UStateTreeAIComponentSchema>(EditorData, NAME_None, RF_Transactional);
    StateTree->EditorData = EditorData;

    UStateTreeState& Root = EditorData->AddRootState();
    UStateTreeState& Retreat = Root.AddChildState(TEXT("Retreat"));
    UStateTreeState& HoldDistance = Root.AddChildState(TEXT("HoldDistance"));
    UStateTreeState& Approach = Root.AddChildState(TEXT("Approach"));
    UStateTreeState& RecentTracking = Root.AddChildState(TEXT("RecentTracking"));
    UStateTreeState& Investigate = Root.AddChildState(TEXT("InvestigateLastLocation"));
    UStateTreeState& Search = Root.AddChildState(TEXT("Search"));
    UStateTreeState& Patrol = Root.AddChildState(TEXT("Patrol"));

    Retreat.AddEnterCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;
    Retreat.AddEnterCondition<FJMStalkerDistanceBandCondition>().GetNode().ExpectedBand = EJMStalkerDistanceBand::TooClose;
    Retreat.AddTask<FJMStalkerRetreatTask>();
    Retreat.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &HoldDistance)
        .AddCondition<FJMStalkerDistanceBandCondition>().GetNode().ExpectedBand = EJMStalkerDistanceBand::Preferred;
    Retreat.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &RecentTracking)
        .AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = false;

    HoldDistance.AddEnterCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;
    HoldDistance.AddEnterCondition<FJMStalkerDistanceBandCondition>().GetNode().ExpectedBand = EJMStalkerDistanceBand::Preferred;
    HoldDistance.AddTask<FJMStalkerHoldDistanceTask>();
    HoldDistance.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Retreat)
        .AddCondition<FJMStalkerDistanceBandCondition>().GetNode().ExpectedBand = EJMStalkerDistanceBand::TooClose;
    HoldDistance.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Approach)
        .AddCondition<FJMStalkerDistanceBandCondition>().GetNode().ExpectedBand = EJMStalkerDistanceBand::TooFar;
    HoldDistance.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &RecentTracking)
        .AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = false;

    Approach.AddEnterCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;
    Approach.AddEnterCondition<FJMStalkerDistanceBandCondition>().GetNode().ExpectedBand = EJMStalkerDistanceBand::TooFar;
    Approach.AddTask<FJMStalkerApproachTask>();
    Approach.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &HoldDistance)
        .AddCondition<FJMStalkerDistanceBandCondition>().GetNode().ExpectedBand = EJMStalkerDistanceBand::Preferred;
    Approach.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &RecentTracking)
        .AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = false;

    RecentTracking.AddEnterCondition<FJMSimpleEnemyHasRecentTrackingMemoryCondition>();
    RecentTracking.AddTask<FJMSimpleEnemyRecentTrackingTask>();
    AddDistanceTransitions(RecentTracking, Retreat, HoldDistance, Approach);
    RecentTracking.AddTransition(
        EStateTreeTransitionTrigger::OnStateCompleted,
        EStateTreeTransitionType::GotoState,
        &Investigate);

    Investigate.AddTask<FJMSimpleEnemyMoveToLastSeenLocationTask>();
    AddDistanceTransitions(Investigate, Retreat, HoldDistance, Approach);
    Investigate.AddTransition(EStateTreeTransitionTrigger::OnStateCompleted, EStateTreeTransitionType::GotoState, &Search);

    FJMSimpleEnemySearchTask& SearchTask = Search.AddTask<FJMSimpleEnemySearchTask>().GetNode();
    SearchTask.SearchDuration = 4.0f;
    SearchTask.RotationSpeedDegrees = 90.0f;
    AddDistanceTransitions(Search, Retreat, HoldDistance, Approach);
    Search.AddTransition(EStateTreeTransitionTrigger::OnStateCompleted, EStateTreeTransitionType::GotoState, &Patrol);

    Patrol.AddTask<FJMSimpleEnemyPatrolTask>();
    AddDistanceTransitions(Patrol, Retreat, HoldDistance, Approach);

    FStateTreeCompilerLog CompilerLog;
    FStateTreeCompiler Compiler(CompilerLog);
    const bool bCompiled = Compiler.Compile(*StateTree);
    if (!bCompiled)
    {
        CompilerLog.DumpToLog(LogTemp);
    }
    TestTrue(TEXT("Stalker StateTree compiles"), bCompiled);
    TestTrue(TEXT("Stalker StateTree is ready to run"), StateTree->IsReadyToRun());
    TestEqual(TEXT("Stalker contains only seven required states"), Root.Children.Num(), 7);
    TestEqual(TEXT("Retreat has one movement task"), Retreat.Tasks.Num(), 1);
    TestEqual(TEXT("HoldDistance has one stop task"), HoldDistance.Tasks.Num(), 1);
    TestEqual(TEXT("Approach has one movement task"), Approach.Tasks.Num(), 1);
    TestEqual(TEXT("Retreat can hold or use Sight Lost tracking"), Retreat.Transitions.Num(), 2);
    TestEqual(TEXT("Hold can retreat, approach, or use Sight Lost tracking"), HoldDistance.Transitions.Num(), 3);
    TestEqual(TEXT("Approach can hold or use Sight Lost tracking"), Approach.Transitions.Num(), 2);
    TestEqual(TEXT("Predictive tracking can reacquire all bands or investigate"), RecentTracking.Transitions.Num(), 4);
    TestEqual(TEXT("Investigate can reacquire all bands or search"), Investigate.Transitions.Num(), 4);
    TestEqual(TEXT("Search can reacquire all bands or patrol"), Search.Transitions.Num(), 4);
    TestEqual(TEXT("Patrol can enter all three distance bands"), Patrol.Transitions.Num(), 3);
    if (HasAnyErrors())
    {
        return false;
    }
    if (bCreatedStateTree)
    {
        FAssetRegistryModule::AssetCreated(StateTree);
    }
    TestTrue(TEXT("Stalker StateTree saves"), SaveStalkerAsset(*StateTree, StateTreePackagePath));

    UBlueprint* ControllerBlueprint = FindOrCreateStalkerBlueprint(
        ControllerPackagePath,
        ControllerAssetName,
        *AStalkerEnemyAIController::StaticClass());
    TestNotNull(TEXT("Stalker controller Blueprint exists"), ControllerBlueprint);
    AStalkerEnemyAIController* ControllerDefaults = ControllerBlueprint
        ? Cast<AStalkerEnemyAIController>(ControllerBlueprint->GeneratedClass->GetDefaultObject())
        : nullptr;
    TestNotNull(TEXT("Stalker controller Blueprint has native defaults"), ControllerDefaults);
    if (ControllerDefaults)
    {
        ControllerDefaults->Modify();
        ControllerDefaults->StateTreeAsset = StateTree;
        ControllerDefaults->MinimumFollowDistance = 450.0f;
        ControllerDefaults->MaximumFollowDistance = 750.0f;
        ControllerDefaults->DistanceHysteresis = 75.0f;
        ControllerBlueprint->MarkPackageDirty();
        TestEqual(
            TEXT("Stalker Blueprint selects the Stalker StateTree"),
            ControllerDefaults->StateTreeAsset.ToSoftObjectPath().ToString(),
            FString(TEXT("/JMMonsterFramework/AI/ST_StalkerEnemy.ST_StalkerEnemy")));
        TestTrue(TEXT("Stalker controller Blueprint saves"), SaveStalkerAsset(*ControllerBlueprint, ControllerPackagePath));
    }

    UBlueprint* BaseEnemyBlueprint = LoadObject<UBlueprint>(
        nullptr,
        TEXT("/JMMonsterFramework/Blueprints/BP_SimpleEnemy.BP_SimpleEnemy"));
    UClass* CharacterParentClass = IsValid(BaseEnemyBlueprint) && IsValid(BaseEnemyBlueprint->GeneratedClass)
        ? BaseEnemyBlueprint->GeneratedClass.Get()
        : ASimpleEnemyCharacter::StaticClass();
    UBlueprint* CharacterBlueprint = FindOrCreateStalkerBlueprint(
        CharacterPackagePath,
        CharacterAssetName,
        *CharacterParentClass);
    TestNotNull(TEXT("Stalker enemy Blueprint exists"), CharacterBlueprint);
    ASimpleEnemyCharacter* CharacterDefaults = CharacterBlueprint
        ? Cast<ASimpleEnemyCharacter>(CharacterBlueprint->GeneratedClass->GetDefaultObject())
        : nullptr;
    TestNotNull(TEXT("Stalker enemy Blueprint has compatible character defaults"), CharacterDefaults);
    if (CharacterDefaults && ControllerBlueprint)
    {
        CharacterDefaults->Modify();
        CharacterDefaults->AIControllerClass = ControllerBlueprint->GeneratedClass;
        CharacterDefaults->AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
        CharacterBlueprint->MarkPackageDirty();
        TestTrue(
            TEXT("Stalker enemy selects the actual Stalker controller Blueprint"),
            CharacterDefaults->AIControllerClass.Get() == ControllerBlueprint->GeneratedClass.Get());
        TestEqual(
            TEXT("Stalker enemy possesses when placed or spawned"),
            CharacterDefaults->AutoPossessAI,
            EAutoPossessAI::PlacedInWorldOrSpawned);
        TestTrue(TEXT("Stalker enemy Blueprint saves"), SaveStalkerAsset(*CharacterBlueprint, CharacterPackagePath));
    }

    return !HasAnyErrors();
}

#endif
