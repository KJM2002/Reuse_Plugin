#include "AI/ListenerEnemyAIController.h"
#include "Characters/SimpleEnemyCharacter.h"
#include "StateTree/SimpleEnemyStateTreeNodes.h"

#include "AssetRegistry/AssetRegistryModule.h"
#include "Components/StateTreeAIComponentSchema.h"
#include "Engine/Blueprint.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Misc/AutomationTest.h"
#include "Misc/PackageName.h"
#include "Perception/AISenseConfig.h"
#include "Perception/AISenseConfig_Hearing.h"
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
    bool SaveListenerAsset(UObject& Asset, const TCHAR* PackagePath)
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

    UBlueprint* FindOrCreateListenerBlueprint(
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
                TEXT("JMMonsterFrameworkPhase9"));
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
    FJMListenerEnemyAssetsTest,
    "JM.MonsterFramework.Phase9.BuildAndValidateListenerAssets",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMListenerEnemyAssetsTest::RunTest(const FString& Parameters)
{
    constexpr TCHAR StateTreePackagePath[] = TEXT("/JMMonsterFramework/AI/ST_ListenerEnemy");
    constexpr TCHAR StateTreeAssetName[] = TEXT("ST_ListenerEnemy");
    constexpr TCHAR ControllerPackagePath[] = TEXT("/JMMonsterFramework/AI/BP_ListenerEnemyAIController");
    constexpr TCHAR ControllerAssetName[] = TEXT("BP_ListenerEnemyAIController");
    constexpr TCHAR CharacterPackagePath[] = TEXT("/JMMonsterFramework/Blueprints/BP_ListenerEnemy");
    constexpr TCHAR CharacterAssetName[] = TEXT("BP_ListenerEnemy");

    const AListenerEnemyAIController* NativeDefaults = GetDefault<AListenerEnemyAIController>();
    TestEqual(
        TEXT("Listener native controller selects only its StateTree"),
        NativeDefaults->StateTreeAsset.ToSoftObjectPath().ToString(),
        FString(TEXT("/JMMonsterFramework/AI/ST_ListenerEnemy.ST_ListenerEnemy")));
    TestNotNull(TEXT("Listener inherits the verified Hearing config"), NativeDefaults->HearingConfig.Get());
    if (NativeDefaults->HearingConfig)
    {
        TestEqual(
            TEXT("Listener uses its hearing-focused 2500uu range"),
            NativeDefaults->HearingConfig->HearingRange,
            2500.0f);
    }

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
    TestNotNull(TEXT("Listener StateTree exists"), StateTree);
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
    UStateTreeState& InvestigateSound = Root.AddChildState(TEXT("InvestigateSound"));
    UStateTreeState& Patrol = Root.AddChildState(TEXT("Patrol"));
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
    Attack.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Search)
        .AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = false;

    Chase.AddEnterCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = true;
    Chase.AddEnterCondition<FJMSimpleEnemyTargetInAttackRangeCondition>().GetNode().bExpectedValue = false;
    Chase.AddTask<FJMSimpleEnemyMoveToTargetTask>();
    Chase.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Attack)
        .AddCondition<FJMSimpleEnemyTargetInAttackRangeCondition>().GetNode().bExpectedValue = true;
    Chase.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &Search)
        .AddCondition<FJMSimpleEnemyCanSeeTargetCondition>().GetNode().bExpectedValue = false;

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

    Patrol.AddTask<FJMSimpleEnemyPatrolTask>();
    Patrol.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &InvestigateSound)
        .AddCondition<FJMSimpleEnemyHasHeardSoundCondition>();

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
    Search.AddTransition(EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &InvestigateSound)
        .AddCondition<FJMSimpleEnemyHasHeardSoundCondition>();
    Search.AddTransition(EStateTreeTransitionTrigger::OnStateCompleted, EStateTreeTransitionType::GotoState, &Patrol);

    FStateTreeCompilerLog CompilerLog;
    FStateTreeCompiler Compiler(CompilerLog);
    const bool bCompiled = Compiler.Compile(*StateTree);
    if (!bCompiled)
    {
        CompilerLog.DumpToLog(LogTemp);
    }
    TestTrue(TEXT("Listener StateTree compiles"), bCompiled);
    TestTrue(TEXT("Listener StateTree is ready to run"), StateTree->IsReadyToRun());
    TestEqual(TEXT("Listener has only the five required states"), Root.Children.Num(), 5);
    TestEqual(TEXT("Listener Patrol has only the Hearing trigger"), Patrol.Transitions.Num(), 1);
    TestEqual(TEXT("Listener sound investigation returns to Patrol when unresolved"), InvestigateSound.Transitions.Num(), 3);
    TestEqual(TEXT("Listener Search can react to a new sound or return to Patrol"), Search.Transitions.Num(), 4);
    if (HasAnyErrors())
    {
        return false;
    }
    if (bCreatedStateTree)
    {
        FAssetRegistryModule::AssetCreated(StateTree);
    }
    TestTrue(TEXT("Listener StateTree saves"), SaveListenerAsset(*StateTree, StateTreePackagePath));

    UBlueprint* ControllerBlueprint = FindOrCreateListenerBlueprint(
        ControllerPackagePath,
        ControllerAssetName,
        *AListenerEnemyAIController::StaticClass());
    TestNotNull(TEXT("Listener controller Blueprint exists"), ControllerBlueprint);
    AListenerEnemyAIController* ControllerDefaults = ControllerBlueprint
        ? Cast<AListenerEnemyAIController>(ControllerBlueprint->GeneratedClass->GetDefaultObject())
        : nullptr;
    TestNotNull(TEXT("Listener controller Blueprint has native Listener defaults"), ControllerDefaults);
    if (ControllerDefaults)
    {
        ControllerDefaults->Modify();
        ControllerDefaults->StateTreeAsset = StateTree;
        ControllerDefaults->HearingConfig->HearingRange = 2500.0f;
        ControllerBlueprint->MarkPackageDirty();
        TestEqual(
            TEXT("Listener Blueprint selects the Listener StateTree"),
            ControllerDefaults->StateTreeAsset.ToSoftObjectPath().ToString(),
            FString(TEXT("/JMMonsterFramework/AI/ST_ListenerEnemy.ST_ListenerEnemy")));
        TestEqual(
            TEXT("Listener Blueprint preserves native Hearing range"),
            ControllerDefaults->HearingConfig->HearingRange,
            2500.0f);
        TestTrue(TEXT("Listener controller Blueprint saves"), SaveListenerAsset(*ControllerBlueprint, ControllerPackagePath));
    }

    UBlueprint* BaseEnemyBlueprint = LoadObject<UBlueprint>(
        nullptr,
        TEXT("/JMMonsterFramework/Blueprints/BP_SimpleEnemy.BP_SimpleEnemy"));
    UClass* CharacterParentClass = IsValid(BaseEnemyBlueprint) && IsValid(BaseEnemyBlueprint->GeneratedClass)
        ? BaseEnemyBlueprint->GeneratedClass.Get()
        : ASimpleEnemyCharacter::StaticClass();
    UBlueprint* CharacterBlueprint = FindOrCreateListenerBlueprint(
        CharacterPackagePath,
        CharacterAssetName,
        *CharacterParentClass);
    TestNotNull(TEXT("Listener enemy Blueprint exists"), CharacterBlueprint);
    ASimpleEnemyCharacter* CharacterDefaults = CharacterBlueprint
        ? Cast<ASimpleEnemyCharacter>(CharacterBlueprint->GeneratedClass->GetDefaultObject())
        : nullptr;
    TestNotNull(TEXT("Listener enemy Blueprint has compatible character defaults"), CharacterDefaults);
    if (CharacterDefaults && ControllerBlueprint)
    {
        CharacterDefaults->Modify();
        CharacterDefaults->AIControllerClass = ControllerBlueprint->GeneratedClass;
        CharacterDefaults->AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
        CharacterBlueprint->MarkPackageDirty();
        TestTrue(
            TEXT("Listener enemy selects the actual Listener controller Blueprint"),
            CharacterDefaults->AIControllerClass.Get() == ControllerBlueprint->GeneratedClass.Get());
        TestEqual(
            TEXT("Listener enemy possesses when placed or spawned"),
            CharacterDefaults->AutoPossessAI,
            EAutoPossessAI::PlacedInWorldOrSpawned);
        TestTrue(TEXT("Listener enemy Blueprint saves"), SaveListenerAsset(*CharacterBlueprint, CharacterPackagePath));
    }

    return !HasAnyErrors();
}

#endif
