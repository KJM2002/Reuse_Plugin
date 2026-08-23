#include "Reference/JMMonsterFrameworkBuildReferenceAssetsCommandlet.h"

#include "Action/JMEnemyActionDefinition.h"
#include "Audio/JMEnemyAudioSet.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Components/StateTreeAIComponentSchema.h"
#include "Components/StaticMeshComponent.h"
#include "Core/JMEnemyBase.h"
#include "Core/JMEnemyDefinition.h"
#include "Core/JMSurfaceCrawlerEnemyBase.h"
#include "Engine/Blueprint.h"
#include "Engine/SimpleConstructionScript.h"
#include "Engine/SCS_Node.h"
#include "Engine/StaticMesh.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Locomotion/JMEnemyMovementSet.h"
#include "StateTree.h"
#include "StateTreeCompilerLog.h"
#include "StateTreeEditingSubsystem.h"
#include "StateTreeEditorData.h"
#include "StateTreeFactory.h"
#include "StateTree/JMEnemyStateTreeConditions.h"
#include "StateTree/JMEnemyStateTreeTasks.h"
#include "Types/JMEnemyTags.h"
#include "UObject/SavePackage.h"

namespace JMListenerAssets
{
    constexpr TCHAR RootPath[] = TEXT("/JMMonsterFramework/Reference/Listener");

    template<typename T>
    T* CreateAsset(const TCHAR* Name)
    {
        const FString PackageName = FString::Printf(TEXT("%s/%s"), RootPath, Name);
        const FString ObjectPath = FString::Printf(TEXT("%s.%s"), *PackageName, Name);
        if (T* Existing = LoadObject<T>(nullptr, *ObjectPath))
        {
            return Existing;
        }
        UPackage* Package = CreatePackage(*PackageName);
        if (T* Existing = FindObject<T>(Package, Name))
        {
            return Existing;
        }
        T* Asset = NewObject<T>(Package, T::StaticClass(), Name, RF_Public | RF_Standalone | RF_Transactional);
        FAssetRegistryModule::AssetCreated(Asset);
        return Asset;
    }

    bool SaveAsset(UObject* Asset)
    {
        if (!Asset) return false;
        UPackage* Package = Asset->GetOutermost();
        Package->MarkPackageDirty();
        const FString Filename = FPackageName::LongPackageNameToFilename(
            Package->GetName(), FPackageName::GetAssetPackageExtension());
        FSavePackageArgs Args;
        Args.TopLevelFlags = RF_Public | RF_Standalone;
        Args.SaveFlags = SAVE_NoError;
        return UPackage::SavePackage(Package, Asset, *Filename, Args);
    }

    template<typename T>
    void SetStateTask(UStateTreeState& State, const FGameplayTag Tag)
    {
        auto& Node = State.AddTask<T>();
        Node.GetInstanceData().State = Tag;
    }

    void SetProfileTask(UStateTreeState& State, const FName Profile)
    {
        auto& Node = State.AddTask<FJMStateTreeMovementProfileTask>();
        Node.GetInstanceData().ProfileName = Profile;
    }

    FStateTreeTransition& TickTo(UStateTreeState& From, UStateTreeState& To,
        const EStateTreeTransitionPriority Priority = EStateTreeTransitionPriority::Normal)
    {
        FStateTreeTransition& Transition = From.AddTransition(
            EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &To);
        Transition.Priority = Priority;
        return Transition;
    }

    FStateTreeTransition& StimulusTo(UStateTreeState& From, UStateTreeState& To,
        const EStateTreeTransitionPriority Priority = EStateTreeTransitionPriority::Normal)
    {
        FStateTreeTransition& Transition = From.AddTransition(
            EStateTreeTransitionTrigger::OnEvent, JMEnemyTags::Event_Stimulus,
            EStateTreeTransitionType::GotoState, &To);
        Transition.Priority = Priority;
        return Transition;
    }

    FStateTreeTransition& CompletedTo(UStateTreeState& From, UStateTreeState& To,
        const EStateTreeTransitionTrigger Trigger = EStateTreeTransitionTrigger::OnStateSucceeded)
    {
        return From.AddTransition(Trigger, EStateTreeTransitionType::GotoState, &To);
    }

    UStateTree* BuildStateTree()
    {
        const FName AssetName(TEXT("ST_Listener"));
        const FString PackageName = FString::Printf(TEXT("%s/%s"), RootPath, *AssetName.ToString());
        const FString ObjectPath = FString::Printf(TEXT("%s.%s"), *PackageName, *AssetName.ToString());
        UStateTree* Tree = LoadObject<UStateTree>(nullptr, *ObjectPath);
        UPackage* Package = Tree ? Tree->GetOutermost() : CreatePackage(*PackageName);
        if (!Tree)
        {
            UStateTreeFactory* Factory = NewObject<UStateTreeFactory>();
            Factory->SetSchemaClass(UStateTreeAIComponentSchema::StaticClass());
            Tree = Cast<UStateTree>(Factory->FactoryCreateNew(
                UStateTree::StaticClass(), Package, AssetName, RF_Public | RF_Standalone | RF_Transactional,
                nullptr, GWarn));
            if (!Tree) return nullptr;
            FAssetRegistryModule::AssetCreated(Tree);
        }

        UStateTreeEditorData* EditorData = CastChecked<UStateTreeEditorData>(Tree->EditorData);
        UStateTreeState& Root = *EditorData->SubTrees[0];
        EditorData->Evaluators.Reset();
        EditorData->GlobalTasks.Reset();
        Root.EnterConditions.Reset();
        Root.Tasks.Reset();
        Root.Transitions.Reset();
        Root.Children.Reset();
        Root.Name = TEXT("Root");
        Root.SelectionBehavior = EStateTreeStateSelectionBehavior::TrySelectChildrenInOrder;
        auto& Context = EditorData->AddEvaluator<FJMStateTreeContextEvaluator>();

        UStateTreeState& Patrol = Root.AddChildState(TEXT("Patrol"));
        UStateTreeState& Investigate = Root.AddChildState(TEXT("Investigate"));
        UStateTreeState& Confirm = Root.AddChildState(TEXT("ConfirmTarget"));
        UStateTreeState& Chase = Root.AddChildState(TEXT("Chase"));
        UStateTreeState& Attack = Root.AddChildState(TEXT("Attack"));
        UStateTreeState& Search = Root.AddChildState(TEXT("Search"));
        UStateTreeState& SearchAround = Root.AddChildState(TEXT("SearchAround"));
        for (UStateTreeState* State : {&Patrol, &Investigate, &Confirm, &Chase, &Attack, &Search, &SearchAround})
        {
            State->TasksCompletion = EStateTreeTaskCompletionType::All;
        }

        SetStateTask<FJMStateTreeSetStateTask>(Patrol, JMEnemyTags::State_Patrol);
        SetProfileTask(Patrol, TEXT("Patrol"));
        Patrol.AddTask<FJMStateTreeClearTargetTask>();
        auto& PatrolMove = Patrol.AddTask<FJMStateTreeMoveRandomTask>();
        PatrolMove.GetInstanceData().Radius = 900.0f;
        PatrolMove.GetInstanceData().bUseHomeAsCenter = true;
        PatrolMove.GetInstanceData().MinWaitTime = 0.75f;
        PatrolMove.GetInstanceData().MaxWaitTime = 1.75f;
        PatrolMove.GetInstanceData().RetryBackoff = 0.25f;
        PatrolMove.GetInstanceData().MaxRetries = 3;
        auto& PatrolHearing = TickTo(Patrol, Investigate, EStateTreeTransitionPriority::High)
            .AddCondition<FJMStateTreeRecentHearingCondition>();
        PatrolHearing.GetInstanceData().MaximumAge = 1.5f;
        CompletedTo(Patrol, Patrol);
        CompletedTo(Patrol, Patrol, EStateTreeTransitionTrigger::OnStateFailed);

        SetStateTask<FJMStateTreeSetStateTask>(Investigate, JMEnemyTags::State_Investigate);
        SetProfileTask(Investigate, TEXT("Investigate"));
        auto& InvestigateMove = Investigate.AddTask<FJMStateTreeMoveToLocationTask>();
        EditorData->AddPropertyBinding(Context, TEXT("LastHeardLocation"), InvestigateMove, TEXT("Location"));
        FStateTreeTransition& ConfirmTransition = StimulusTo(Investigate, Confirm, EStateTreeTransitionPriority::High);
        auto& ConfirmRecent = ConfirmTransition.AddCondition<FJMStateTreeRecentHearingCondition>();
        ConfirmRecent.GetInstanceData().MaximumAge = 2.0f;
        auto& CombatTarget = ConfirmTransition.AddCondition<FJMStateTreeCombatTargetCondition>();
        EditorData->AddPropertyBinding(Context, TEXT("LastHeardSource"), CombatTarget, TEXT("Actor"));
        auto& ConfirmDistance = ConfirmTransition.AddCondition<FJMStateTreeDistanceCondition>();
        ConfirmDistance.GetInstanceData().Distance = 900.0f;
        ConfirmDistance.GetInstanceData().Comparison = EJMStateTreeCompare::LessOrEqual;
        EditorData->AddPropertyBinding(Context, TEXT("LastHeardSource"), ConfirmDistance, TEXT("TargetActor"));
        auto& Reinvestigate = CompletedTo(Investigate, Investigate)
            .AddCondition<FJMStateTreeRecentHearingCondition>();
        Reinvestigate.GetInstanceData().MaximumAge = 1.5f;
        CompletedTo(Investigate, Patrol, EStateTreeTransitionTrigger::OnStateCompleted);

        auto& SetTarget = Confirm.AddTask<FJMStateTreeSetTargetTask>();
        EditorData->AddPropertyBinding(Context, TEXT("LastHeardSource"), SetTarget, TEXT("TargetActor"));
        CompletedTo(Confirm, Chase);
        CompletedTo(Confirm, Investigate, EStateTreeTransitionTrigger::OnStateFailed);

        SetStateTask<FJMStateTreeSetStateTask>(Chase, JMEnemyTags::State_Chase);
        SetProfileTask(Chase, TEXT("Chase"));
        auto& ChaseMove = Chase.AddTask<FJMStateTreeMoveToActorTask>();
        EditorData->AddPropertyBinding(Context, TEXT("CurrentTarget"), ChaseMove, TEXT("TargetActor"));
        FStateTreeTransition& AttackTransition = TickTo(Chase, Attack, EStateTreeTransitionPriority::Critical);
        auto& AttackReady = AttackTransition.AddCondition<FJMStateTreeActionReadyCondition>();
        AttackReady.GetInstanceData().ActionId = JMEnemyTags::Action_Melee;
        EditorData->AddPropertyBinding(Context, TEXT("CurrentTarget"), AttackReady, TEXT("TargetActor"));
        auto& LostTarget = TickTo(Chase, Search, EStateTreeTransitionPriority::High)
            .AddCondition<FJMStateTreeTargetHearingCondition>();
        LostTarget.GetInstanceData().MaximumAge = 4.0f;
        LostTarget.GetInstanceData().bInvert = true;
        CompletedTo(Chase, Search, EStateTreeTransitionTrigger::OnStateFailed);
        auto& CompletedAttack = CompletedTo(Chase, Attack)
            .AddCondition<FJMStateTreeActionReadyCondition>();
        CompletedAttack.GetInstanceData().ActionId = JMEnemyTags::Action_Melee;
        EditorData->AddPropertyBinding(Context, TEXT("CurrentTarget"), CompletedAttack, TEXT("TargetActor"));
        CompletedTo(Chase, Chase);

        SetStateTask<FJMStateTreeSetStateTask>(Attack, JMEnemyTags::State_Attack);
        Attack.AddTask<FJMStateTreeStopMovementTask>();
        auto& Face = Attack.AddTask<FJMStateTreeFaceActorTask>();
        EditorData->AddPropertyBinding(Context, TEXT("CurrentTarget"), Face, TEXT("TargetActor"));
        auto& Execute = Attack.AddTask<FJMStateTreeExecuteActionTask>();
        Execute.GetInstanceData().ActionId = JMEnemyTags::Action_Melee;
        EditorData->AddPropertyBinding(Context, TEXT("CurrentTarget"), Execute, TEXT("TargetActor"));
        CompletedTo(Attack, Chase, EStateTreeTransitionTrigger::OnStateCompleted);

        SetStateTask<FJMStateTreeSetStateTask>(Search, JMEnemyTags::State_Search);
        SetProfileTask(Search, TEXT("Investigate"));
        auto& SearchMove = Search.AddTask<FJMStateTreeMoveToLocationTask>();
        EditorData->AddPropertyBinding(Context, TEXT("LastKnownLocation"), SearchMove, TEXT("Location"));
        CompletedTo(Search, SearchAround, EStateTreeTransitionTrigger::OnStateCompleted);

        SetStateTask<FJMStateTreeSetStateTask>(SearchAround, JMEnemyTags::State_Search);
        SetProfileTask(SearchAround, TEXT("Investigate"));
        auto& RandomSearch = SearchAround.AddTask<FJMStateTreeMoveRandomTask>();
        RandomSearch.GetInstanceData().bUseHomeAsCenter = false;
        RandomSearch.GetInstanceData().bUseOwnerAsCenter = false;
        RandomSearch.GetInstanceData().Radius = 650.0f;
        EditorData->AddPropertyBinding(Context, TEXT("LastKnownLocation"), RandomSearch, TEXT("Center"));
        auto& SearchTargetSound = TickTo(SearchAround, Chase, EStateTreeTransitionPriority::Critical)
            .AddCondition<FJMStateTreeTargetHearingCondition>();
        SearchTargetSound.GetInstanceData().MaximumAge = 1.5f;
        auto& SearchAnySound = TickTo(SearchAround, Investigate, EStateTreeTransitionPriority::High)
            .AddCondition<FJMStateTreeRecentHearingCondition>();
        SearchAnySound.GetInstanceData().MaximumAge = 1.5f;
        auto& SearchTimeout = TickTo(SearchAround, Patrol, EStateTreeTransitionPriority::Normal)
            .AddCondition<FJMStateTreeTargetHearingCondition>();
        SearchTimeout.GetInstanceData().MaximumAge = 12.0f;
        SearchTimeout.GetInstanceData().bInvert = true;
        CompletedTo(SearchAround, SearchAround);
        CompletedTo(SearchAround, SearchAround, EStateTreeTransitionTrigger::OnStateFailed);

        FStateTreeCompilerLog Log;
        if (!UStateTreeEditingSubsystem::CompileStateTree(Tree, Log))
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to compile ST_Listener"));
            return nullptr;
        }
        return Tree;
    }

    UBlueprint* BuildBlueprint(UJMEnemyDefinition* Definition)
    {
        const FName AssetName(TEXT("BP_Enemy_Listener"));
        const FString PackageName = FString::Printf(TEXT("%s/%s"), RootPath, *AssetName.ToString());
        const FString ObjectPath = FString::Printf(TEXT("%s.%s"), *PackageName, *AssetName.ToString());
        UPackage* Package = CreatePackage(*PackageName);
        UBlueprint* Blueprint = LoadObject<UBlueprint>(nullptr, *ObjectPath);
        if (!Blueprint)
        {
            Blueprint = FindObject<UBlueprint>(Package, AssetName.ToString());
        }
        if (!Blueprint)
        {
            Blueprint = FKismetEditorUtilities::CreateBlueprint(AJMEnemyBase::StaticClass(), Package,
                AssetName, BPTYPE_Normal, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass(),
                FName(TEXT("JMListenerReferenceBuilder")));
            FAssetRegistryModule::AssetCreated(Blueprint);
        }
        if (!Blueprint || !Blueprint->GeneratedClass) return nullptr;
        if (Blueprint->SimpleConstructionScript && Blueprint->SimpleConstructionScript->GetAllNodes().IsEmpty())
        {
            USCS_Node* Node = Blueprint->SimpleConstructionScript->CreateNode(
                UStaticMeshComponent::StaticClass(), TEXT("ListenerPlaceholder"));
            if (UStaticMeshComponent* Mesh = Cast<UStaticMeshComponent>(Node->ComponentTemplate))
            {
                Mesh->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cylinder.Cylinder")));
                Mesh->SetRelativeScale3D(FVector(0.65f, 0.65f, 1.6f));
                Mesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
            }
            Blueprint->SimpleConstructionScript->AddNode(Node);
        }
        FKismetEditorUtilities::CompileBlueprint(Blueprint);
        AJMEnemyBase* CDO = Cast<AJMEnemyBase>(Blueprint->GeneratedClass->GetDefaultObject());
        FObjectProperty* DefinitionProperty = FindFProperty<FObjectProperty>(
            AJMEnemyBase::StaticClass(), TEXT("EnemyDefinition"));
        if (CDO && DefinitionProperty)
        {
            Blueprint->Modify();
            CDO->Modify();
            DefinitionProperty->SetObjectPropertyValue_InContainer(CDO, Definition);
        }
        return Blueprint;
    }
}

namespace JMWatcherAssets
{
    constexpr TCHAR RootPath[] = TEXT("/JMMonsterFramework/Reference/Watcher");

    template<typename T>
    T* CreateAsset(const TCHAR* Name)
    {
        const FString PackageName = FString::Printf(TEXT("%s/%s"), RootPath, Name);
        const FString ObjectPath = FString::Printf(TEXT("%s.%s"), *PackageName, Name);
        if (T* Existing = LoadObject<T>(nullptr, *ObjectPath)) return Existing;
        UPackage* Package = CreatePackage(*PackageName);
        if (T* Existing = FindObject<T>(Package, Name)) return Existing;
        T* Asset = NewObject<T>(Package, T::StaticClass(), Name, RF_Public | RF_Standalone | RF_Transactional);
        FAssetRegistryModule::AssetCreated(Asset);
        return Asset;
    }

    bool SaveAsset(UObject* Asset)
    {
        if (!Asset) return false;
        UPackage* Package = Asset->GetOutermost();
        Package->MarkPackageDirty();
        const FString Filename = FPackageName::LongPackageNameToFilename(
            Package->GetName(), FPackageName::GetAssetPackageExtension());
        FSavePackageArgs Args;
        Args.TopLevelFlags = RF_Public | RF_Standalone;
        Args.SaveFlags = SAVE_NoError;
        return UPackage::SavePackage(Package, Asset, *Filename, Args);
    }

    template<typename T>
    void SetStateTask(UStateTreeState& State, const FGameplayTag Tag)
    {
        State.AddTask<T>().GetInstanceData().State = Tag;
    }

    void SetProfileTask(UStateTreeState& State, const FName Profile)
    {
        State.AddTask<FJMStateTreeMovementProfileTask>().GetInstanceData().ProfileName = Profile;
    }

    FStateTreeTransition& TickTo(UStateTreeState& From, UStateTreeState& To,
        const EStateTreeTransitionPriority Priority = EStateTreeTransitionPriority::Normal)
    {
        FStateTreeTransition& Transition = From.AddTransition(
            EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &To);
        Transition.Priority = Priority;
        return Transition;
    }

    FStateTreeTransition& StimulusTo(UStateTreeState& From, UStateTreeState& To,
        const EStateTreeTransitionPriority Priority = EStateTreeTransitionPriority::Normal)
    {
        FStateTreeTransition& Transition = From.AddTransition(
            EStateTreeTransitionTrigger::OnEvent, JMEnemyTags::Event_Stimulus,
            EStateTreeTransitionType::GotoState, &To);
        Transition.Priority = Priority;
        return Transition;
    }

    FStateTreeTransition& CompletedTo(UStateTreeState& From, UStateTreeState& To,
        const EStateTreeTransitionTrigger Trigger = EStateTreeTransitionTrigger::OnStateSucceeded)
    {
        return From.AddTransition(Trigger, EStateTreeTransitionType::GotoState, &To);
    }

    void ConfigureGaze(FJMStateTreeGazeInstanceData& Data, const bool bInvert = false)
    {
        Data.MinimumStrength = 0.90f;
        Data.MinimumDuration = 0.05f;
        Data.bInvert = bInvert;
    }

    UStateTree* BuildStateTree()
    {
        const FName AssetName(TEXT("ST_Watcher"));
        const FString PackageName = FString::Printf(TEXT("%s/%s"), RootPath, *AssetName.ToString());
        const FString ObjectPath = FString::Printf(TEXT("%s.%s"), *PackageName, *AssetName.ToString());
        UStateTree* Tree = LoadObject<UStateTree>(nullptr, *ObjectPath);
        UPackage* Package = Tree ? Tree->GetOutermost() : CreatePackage(*PackageName);
        if (!Tree)
        {
            UStateTreeFactory* Factory = NewObject<UStateTreeFactory>();
            Factory->SetSchemaClass(UStateTreeAIComponentSchema::StaticClass());
            Tree = Cast<UStateTree>(Factory->FactoryCreateNew(UStateTree::StaticClass(), Package, AssetName,
                RF_Public | RF_Standalone | RF_Transactional, nullptr, GWarn));
            if (!Tree) return nullptr;
            FAssetRegistryModule::AssetCreated(Tree);
        }

        UStateTreeEditorData* EditorData = CastChecked<UStateTreeEditorData>(Tree->EditorData);
        UStateTreeState& Root = *EditorData->SubTrees[0];
        EditorData->Evaluators.Reset();
        EditorData->GlobalTasks.Reset();
        Root.EnterConditions.Reset();
        Root.Tasks.Reset();
        Root.Transitions.Reset();
        Root.Children.Reset();
        Root.Name = TEXT("Root");
        Root.SelectionBehavior = EStateTreeStateSelectionBehavior::TrySelectChildrenInOrder;
        auto& Context = EditorData->AddEvaluator<FJMStateTreeContextEvaluator>();

        UStateTreeState& Patrol = Root.AddChildState(TEXT("Patrol"));
        UStateTreeState& Acquire = Root.AddChildState(TEXT("AcquireTarget"));
        UStateTreeState& Chase = Root.AddChildState(TEXT("Chase"));
        UStateTreeState& Frozen = Root.AddChildState(TEXT("Frozen"));
        UStateTreeState& Attack = Root.AddChildState(TEXT("Attack"));
        for (UStateTreeState* State : {&Patrol, &Acquire, &Chase, &Frozen, &Attack})
        {
            State->TasksCompletion = EStateTreeTaskCompletionType::All;
        }

        SetStateTask<FJMStateTreeSetStateTask>(Patrol, JMEnemyTags::State_Patrol);
        SetProfileTask(Patrol, TEXT("Patrol"));
        Patrol.AddTask<FJMStateTreeClearTargetTask>();
        auto& PatrolMove = Patrol.AddTask<FJMStateTreeMoveRandomTask>();
        PatrolMove.GetInstanceData().Radius = 900.0f;
        PatrolMove.GetInstanceData().bUseHomeAsCenter = true;
        PatrolMove.GetInstanceData().MinWaitTime = 0.5f;
        PatrolMove.GetInstanceData().MaxWaitTime = 1.25f;
        PatrolMove.GetInstanceData().RetryBackoff = 0.25f;
        PatrolMove.GetInstanceData().MaxRetries = 3;
        FStateTreeTransition& AcquireTransition = TickTo(Patrol, Acquire, EStateTreeTransitionPriority::Critical);
        auto& VisibleCandidate = AcquireTransition.AddCondition<FJMStateTreeActorVisionCondition>();
        VisibleCandidate.GetInstanceData().bUseLastSeenSource = true;
        EditorData->AddPropertyBinding(Context, TEXT("LastSeenSource"), VisibleCandidate, TEXT("Actor"));
        auto& CombatCandidate = AcquireTransition.AddCondition<FJMStateTreeCombatTargetCondition>();
        CombatCandidate.GetInstanceData().bUseLastSeenSource = true;
        EditorData->AddPropertyBinding(Context, TEXT("LastSeenSource"), CombatCandidate, TEXT("Actor"));
        CompletedTo(Patrol, Patrol);
        CompletedTo(Patrol, Patrol, EStateTreeTransitionTrigger::OnStateFailed);

        auto& SetTarget = Acquire.AddTask<FJMStateTreeSetTargetTask>();
        SetTarget.GetInstanceData().bUseLastSeenSource = true;
        EditorData->AddPropertyBinding(Context, TEXT("LastSeenSource"), SetTarget, TEXT("TargetActor"));
        CompletedTo(Acquire, Chase);
        CompletedTo(Acquire, Patrol, EStateTreeTransitionTrigger::OnStateFailed);

        SetStateTask<FJMStateTreeSetStateTask>(Chase, JMEnemyTags::State_Chase);
        SetProfileTask(Chase, TEXT("Chase"));
        auto& ChaseMove = Chase.AddTask<FJMStateTreeMoveToActorTask>();
        EditorData->AddPropertyBinding(Context, TEXT("CurrentTarget"), ChaseMove, TEXT("TargetActor"));
        auto& FreezeFromChase = TickTo(Chase, Frozen, EStateTreeTransitionPriority::Critical)
            .AddCondition<FJMStateTreeGazeCondition>();
        ConfigureGaze(FreezeFromChase.GetInstanceData());
        auto& AttackReady = TickTo(Chase, Attack, EStateTreeTransitionPriority::High)
            .AddCondition<FJMStateTreeActionReadyCondition>();
        AttackReady.GetInstanceData().ActionId = JMEnemyTags::Action_Melee;
        EditorData->AddPropertyBinding(Context, TEXT("CurrentTarget"), AttackReady, TEXT("TargetActor"));
        auto& ChaseLost = TickTo(Chase, Patrol, EStateTreeTransitionPriority::Normal)
            .AddCondition<FJMStateTreeRecentVisionCondition>();
        ChaseLost.GetInstanceData().MaximumAge = 1.5f;
        ChaseLost.GetInstanceData().bInvert = true;
        CompletedTo(Chase, Chase);
        CompletedTo(Chase, Patrol, EStateTreeTransitionTrigger::OnStateFailed);

        SetStateTask<FJMStateTreeSetStateTask>(Frozen, JMEnemyTags::State_Watcher_Frozen);
        Frozen.AddTask<FJMStateTreeStopMovementTask>();
        auto& FrozenFace = Frozen.AddTask<FJMStateTreeFaceActorTask>();
        EditorData->AddPropertyBinding(Context, TEXT("CurrentTarget"), FrozenFace, TEXT("TargetActor"));
        Frozen.AddTask<FJMStateTreeWaitForTransitionTask>();
        auto& FrozenLost = TickTo(Frozen, Patrol, EStateTreeTransitionPriority::Critical)
            .AddCondition<FJMStateTreeRecentVisionCondition>();
        FrozenLost.GetInstanceData().MaximumAge = 1.5f;
        FrozenLost.GetInstanceData().bInvert = true;
        auto& GazeReleased = TickTo(Frozen, Chase, EStateTreeTransitionPriority::High)
            .AddCondition<FJMStateTreeGazeCondition>();
        ConfigureGaze(GazeReleased.GetInstanceData(), true);

        SetStateTask<FJMStateTreeSetStateTask>(Attack, JMEnemyTags::State_Attack);
        Attack.AddTask<FJMStateTreeStopMovementTask>();
        auto& AttackFace = Attack.AddTask<FJMStateTreeFaceActorTask>();
        EditorData->AddPropertyBinding(Context, TEXT("CurrentTarget"), AttackFace, TEXT("TargetActor"));
        auto& Execute = Attack.AddTask<FJMStateTreeExecuteActionTask>();
        Execute.GetInstanceData().ActionId = JMEnemyTags::Action_Melee;
        EditorData->AddPropertyBinding(Context, TEXT("CurrentTarget"), Execute, TEXT("TargetActor"));
        auto& FreezeAttack = TickTo(Attack, Frozen, EStateTreeTransitionPriority::Critical)
            .AddCondition<FJMStateTreeGazeCondition>();
        ConfigureGaze(FreezeAttack.GetInstanceData());
        auto& AttackLost = TickTo(Attack, Patrol, EStateTreeTransitionPriority::High)
            .AddCondition<FJMStateTreeRecentVisionCondition>();
        AttackLost.GetInstanceData().MaximumAge = 1.5f;
        AttackLost.GetInstanceData().bInvert = true;
        auto& FrozenAfterAttack = CompletedTo(Attack, Frozen, EStateTreeTransitionTrigger::OnStateCompleted)
            .AddCondition<FJMStateTreeGazeCondition>();
        ConfigureGaze(FrozenAfterAttack.GetInstanceData());
        CompletedTo(Attack, Chase, EStateTreeTransitionTrigger::OnStateCompleted);
        CompletedTo(Attack, Chase, EStateTreeTransitionTrigger::OnStateFailed);

        FStateTreeCompilerLog Log;
        if (!UStateTreeEditingSubsystem::CompileStateTree(Tree, Log))
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to compile ST_Watcher"));
            return nullptr;
        }
        return Tree;
    }

    UBlueprint* BuildBlueprint(UJMEnemyDefinition* Definition)
    {
        const FName AssetName(TEXT("BP_Enemy_Watcher"));
        const FString PackageName = FString::Printf(TEXT("%s/%s"), RootPath, *AssetName.ToString());
        const FString ObjectPath = FString::Printf(TEXT("%s.%s"), *PackageName, *AssetName.ToString());
        UPackage* Package = CreatePackage(*PackageName);
        UBlueprint* Blueprint = LoadObject<UBlueprint>(nullptr, *ObjectPath);
        if (!Blueprint) Blueprint = FindObject<UBlueprint>(Package, AssetName.ToString());
        if (!Blueprint)
        {
            Blueprint = FKismetEditorUtilities::CreateBlueprint(AJMEnemyBase::StaticClass(), Package, AssetName,
                BPTYPE_Normal, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass(),
                FName(TEXT("JMWatcherReferenceBuilder")));
            FAssetRegistryModule::AssetCreated(Blueprint);
        }
        if (!Blueprint || !Blueprint->GeneratedClass) return nullptr;
        if (Blueprint->SimpleConstructionScript && Blueprint->SimpleConstructionScript->GetAllNodes().IsEmpty())
        {
            USCS_Node* Node = Blueprint->SimpleConstructionScript->CreateNode(
                UStaticMeshComponent::StaticClass(), TEXT("WatcherPlaceholder"));
            if (UStaticMeshComponent* Mesh = Cast<UStaticMeshComponent>(Node->ComponentTemplate))
            {
                Mesh->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cone.Cone")));
                Mesh->SetRelativeScale3D(FVector(0.8f, 0.8f, 1.8f));
            }
            Blueprint->SimpleConstructionScript->AddNode(Node);
        }
        FObjectProperty* DefinitionProperty = FindFProperty<FObjectProperty>(AJMEnemyBase::StaticClass(), TEXT("EnemyDefinition"));
        AJMEnemyBase* CDO = Cast<AJMEnemyBase>(Blueprint->GeneratedClass->GetDefaultObject());
        if (CDO && DefinitionProperty)
        {
            Blueprint->Modify();
            CDO->Modify();
            DefinitionProperty->SetObjectPropertyValue_InContainer(CDO, Definition);
        }
        FKismetEditorUtilities::CompileBlueprint(Blueprint);
        CDO = Blueprint->GeneratedClass
            ? Cast<AJMEnemyBase>(Blueprint->GeneratedClass->GetDefaultObject()) : nullptr;
        if (CDO && DefinitionProperty)
        {
            CDO->Modify();
            DefinitionProperty->SetObjectPropertyValue_InContainer(CDO, Definition);
        }
        return Blueprint;
    }

    bool BuildAndSave()
    {
        UJMEnemyMovementSet* Movement = CreateAsset<UJMEnemyMovementSet>(TEXT("DA_Watcher_Movement"));
        Movement->Profiles.Reset();
        auto AddProfile = [Movement](const FName Name, const float Speed)
        {
            FJMEnemyMovementProfile Profile;
            Profile.ProfileName = Name;
            Profile.MaxSpeed = Speed;
            Profile.MaxAcceleration = 2200.0f;
            Profile.AcceptanceRadius = 70.0f;
            Movement->Profiles.Add(Profile);
        };
        AddProfile(TEXT("Patrol"), 250.0f);
        AddProfile(TEXT("Chase"), 750.0f);

        UJMEnemyActionDefinition_Melee* Melee = CreateAsset<UJMEnemyActionDefinition_Melee>(TEXT("DA_Watcher_Melee"));
        Melee->Damage = 25.0f;
        Melee->AttackRange = 170.0f;
        Melee->WindupDuration = 0.3f;
        Melee->ActiveDuration = 0.1f;
        Melee->RecoveryDuration = 0.35f;
        Melee->Cooldown = 0.6f;

        UStateTree* StateTree = BuildStateTree();
        UJMEnemyAudioSet* Audio = CreateAsset<UJMEnemyAudioSet>(TEXT("DA_Watcher_Audio"));
        Audio->Events.Reset();
        for (const EJMEnemyAudioEvent Event : {EJMEnemyAudioEvent::Chase, EJMEnemyAudioEvent::Frozen,
            EJMEnemyAudioEvent::AttackWindup, EJMEnemyAudioEvent::Attack})
        {
            FJMEnemyAudioEventEntry& Entry = Audio->Events.AddDefaulted_GetRef();
            Entry.Event = Event;
        }
        UJMEnemyDefinition* Definition = CreateAsset<UJMEnemyDefinition>(TEXT("DA_Enemy_Watcher"));
        Definition->EnemyId = TEXT("Watcher.Reference");
        Definition->DisplayName = FText::FromString(TEXT("Watcher Reference Enemy"));
        Definition->MaxHealth = 100.0f;
        Definition->BaseDamage = 25.0f;
        Definition->InitialState = JMEnemyTags::State_Patrol;
        Definition->Perception.Vision.bEnabled = true;
        Definition->Perception.Vision.SightRadius = 2200.0f;
        Definition->Perception.Vision.LoseSightRadius = 2500.0f;
        Definition->Perception.Vision.PeripheralVisionAngle = 75.0f;
        Definition->Perception.Hearing.bEnabled = false;
        Definition->Perception.PlayerGaze.bEnabled = true;
        Definition->Perception.PlayerGaze.UpdateInterval = 0.05f;
        Definition->Perception.PlayerGaze.MaximumDistance = 2500.0f;
        Definition->Perception.PlayerGaze.DotThreshold = 0.90f;
        Definition->Perception.PlayerGaze.bRequireLineOfSight = true;
        Definition->MovementSet = Movement;
        Definition->DefaultMovementProfile = TEXT("Patrol");
        Definition->Actions = {Melee};
        Definition->StateTree = StateTree;
        Definition->AudioSet = Audio;
        UBlueprint* Blueprint = BuildBlueprint(Definition);

        const bool bSaved = SaveAsset(Movement) && SaveAsset(Melee) && SaveAsset(Audio) && SaveAsset(StateTree) &&
            SaveAsset(Definition) && SaveAsset(Blueprint);
        UE_LOG(LogTemp, Display, TEXT("JM_WATCHER_REFERENCE_ASSETS=%s"), bSaved ? TEXT("SUCCESS") : TEXT("FAILED"));
        return bSaved;
    }
}

namespace JMCrawlerAssets
{
    constexpr TCHAR RootPath[] = TEXT("/JMMonsterFramework/Reference/Crawler");

    template<typename T>
    T* CreateAsset(const TCHAR* Name)
    {
        const FString PackageName = FString::Printf(TEXT("%s/%s"), RootPath, Name);
        const FString ObjectPath = FString::Printf(TEXT("%s.%s"), *PackageName, Name);
        if (T* Existing = LoadObject<T>(nullptr, *ObjectPath)) return Existing;
        UPackage* Package = CreatePackage(*PackageName);
        if (T* Existing = FindObject<T>(Package, Name)) return Existing;
        T* Asset = NewObject<T>(Package, T::StaticClass(), Name, RF_Public | RF_Standalone | RF_Transactional);
        FAssetRegistryModule::AssetCreated(Asset);
        return Asset;
    }

    bool SaveAsset(UObject* Asset)
    {
        if (!Asset) return false;
        UPackage* Package = Asset->GetOutermost();
        Package->MarkPackageDirty();
        const FString Filename = FPackageName::LongPackageNameToFilename(
            Package->GetName(), FPackageName::GetAssetPackageExtension());
        FSavePackageArgs Args;
        Args.TopLevelFlags = RF_Public | RF_Standalone;
        Args.SaveFlags = SAVE_NoError;
        return UPackage::SavePackage(Package, Asset, *Filename, Args);
    }

    template<typename T>
    void SetState(UStateTreeState& State, const FGameplayTag Tag)
    {
        State.AddTask<T>().GetInstanceData().State = Tag;
    }

    void SetProfile(UStateTreeState& State, const FName Profile)
    {
        State.AddTask<FJMStateTreeMovementProfileTask>().GetInstanceData().ProfileName = Profile;
    }

    FStateTreeTransition& TickTo(UStateTreeState& From, UStateTreeState& To,
        const EStateTreeTransitionPriority Priority = EStateTreeTransitionPriority::Normal)
    {
        FStateTreeTransition& Transition = From.AddTransition(
            EStateTreeTransitionTrigger::OnTick, EStateTreeTransitionType::GotoState, &To);
        Transition.Priority = Priority;
        return Transition;
    }

    FStateTreeTransition& StimulusTo(UStateTreeState& From, UStateTreeState& To,
        const EStateTreeTransitionPriority Priority = EStateTreeTransitionPriority::Normal)
    {
        FStateTreeTransition& Transition = From.AddTransition(
            EStateTreeTransitionTrigger::OnEvent, JMEnemyTags::Event_Stimulus,
            EStateTreeTransitionType::GotoState, &To);
        Transition.Priority = Priority;
        return Transition;
    }

    FStateTreeTransition& CompletedTo(UStateTreeState& From, UStateTreeState& To,
        const EStateTreeTransitionTrigger Trigger = EStateTreeTransitionTrigger::OnStateSucceeded)
    {
        return From.AddTransition(Trigger, EStateTreeTransitionType::GotoState, &To);
    }

    void ConfigureGaze(FJMStateTreeGazeInstanceData& Data)
    {
        Data.MinimumStrength = 0.85f;
        Data.MinimumDuration = 0.05f;
    }

    void AddTargetLost(UStateTreeState& From, UStateTreeState& Roam,
        const EStateTreeTransitionPriority Priority = EStateTreeTransitionPriority::Normal)
    {
        auto& Lost = TickTo(From, Roam, Priority).AddCondition<FJMStateTreeRecentVisionCondition>();
        Lost.GetInstanceData().MaximumAge = 2.0f;
        Lost.GetInstanceData().bInvert = true;
    }

    void AddEncounterGaze(UStateTreeEditorData& EditorData, UStateTreeState& From,
        UStateTreeState& Destination, const EJMStateTreeCompare Comparison, const int32 Threshold,
        const EStateTreeTransitionPriority Priority)
    {
        FStateTreeTransition& Transition = TickTo(From, Destination, Priority);
        auto& Gaze = Transition.AddCondition<FJMStateTreeGazeCondition>();
        ConfigureGaze(Gaze.GetInstanceData());
        auto& Encounter = Transition.AddCondition<FJMStateTreeEncounterCondition>();
        Encounter.GetInstanceData().Comparison = Comparison;
        Encounter.GetInstanceData().Threshold = Threshold;
    }

    UStateTree* BuildStateTree()
    {
        const FName AssetName(TEXT("ST_Crawler"));
        const FString PackageName = FString::Printf(TEXT("%s/%s"), RootPath, *AssetName.ToString());
        const FString ObjectPath = FString::Printf(TEXT("%s.%s"), *PackageName, *AssetName.ToString());
        UStateTree* Tree = LoadObject<UStateTree>(nullptr, *ObjectPath);
        UPackage* Package = Tree ? Tree->GetOutermost() : CreatePackage(*PackageName);
        if (!Tree)
        {
            UStateTreeFactory* Factory = NewObject<UStateTreeFactory>();
            Factory->SetSchemaClass(UStateTreeAIComponentSchema::StaticClass());
            Tree = Cast<UStateTree>(Factory->FactoryCreateNew(UStateTree::StaticClass(), Package, AssetName,
                RF_Public | RF_Standalone | RF_Transactional, nullptr, GWarn));
            if (!Tree) return nullptr;
            FAssetRegistryModule::AssetCreated(Tree);
        }

        UStateTreeEditorData* EditorData = CastChecked<UStateTreeEditorData>(Tree->EditorData);
        UStateTreeState& Root = *EditorData->SubTrees[0];
        EditorData->Evaluators.Reset();
        EditorData->GlobalTasks.Reset();
        Root.EnterConditions.Reset();
        Root.Tasks.Reset();
        Root.Transitions.Reset();
        Root.Children.Reset();
        Root.Name = TEXT("Root");
        Root.SelectionBehavior = EStateTreeStateSelectionBehavior::TrySelectChildrenInOrder;
        auto& Context = EditorData->AddEvaluator<FJMStateTreeContextEvaluator>();

        UStateTreeState& Roam = Root.AddChildState(TEXT("Roam"));
        UStateTreeState& Acquire = Root.AddChildState(TEXT("AcquireTarget"));
        UStateTreeState& Stalk = Root.AddChildState(TEXT("Stalk"));
        UStateTreeState& Flee = Root.AddChildState(TEXT("Flee"));
        UStateTreeState& Hide = Root.AddChildState(TEXT("Hide"));
        UStateTreeState& ReApproach = Root.AddChildState(TEXT("ReApproach"));
        UStateTreeState& Enrage = Root.AddChildState(TEXT("Enrage"));
        UStateTreeState& Frenzy = Root.AddChildState(TEXT("FrenzyChase"));
        UStateTreeState& Attack = Root.AddChildState(TEXT("Attack"));
        for (UStateTreeState* State : {&Roam, &Acquire, &Stalk, &Flee, &Hide,
            &ReApproach, &Enrage, &Frenzy, &Attack})
        {
            State->TasksCompletion = EStateTreeTaskCompletionType::All;
        }

        SetState<FJMStateTreeSetStateTask>(Roam, JMEnemyTags::State_Patrol);
        SetProfile(Roam, TEXT("Roam"));
        Roam.AddTask<FJMStateTreeClearTargetTask>();
        auto& RoamMove = Roam.AddTask<FJMStateTreeMoveRandomTask>();
        RoamMove.GetInstanceData().Radius = 700.0f;
        RoamMove.GetInstanceData().bUseHomeAsCenter = true;
        RoamMove.GetInstanceData().MinWaitTime = 0.25f;
        RoamMove.GetInstanceData().MaxWaitTime = 0.75f;
        RoamMove.GetInstanceData().RetryBackoff = 0.25f;
        RoamMove.GetInstanceData().MaxRetries = 3;
        FStateTreeTransition& AcquireTransition = TickTo(Roam, Acquire, EStateTreeTransitionPriority::Critical);
        auto& Visible = AcquireTransition.AddCondition<FJMStateTreeActorVisionCondition>();
        Visible.GetInstanceData().bUseLastSeenSource = true;
        EditorData->AddPropertyBinding(Context, TEXT("LastSeenSource"), Visible, TEXT("Actor"));
        auto& Combat = AcquireTransition.AddCondition<FJMStateTreeCombatTargetCondition>();
        Combat.GetInstanceData().bUseLastSeenSource = true;
        EditorData->AddPropertyBinding(Context, TEXT("LastSeenSource"), Combat, TEXT("Actor"));
        CompletedTo(Roam, Roam);
        CompletedTo(Roam, Roam, EStateTreeTransitionTrigger::OnStateFailed);

        auto& SetTarget = Acquire.AddTask<FJMStateTreeSetTargetTask>();
        SetTarget.GetInstanceData().bUseLastSeenSource = true;
        EditorData->AddPropertyBinding(Context, TEXT("LastSeenSource"), SetTarget, TEXT("TargetActor"));
        CompletedTo(Acquire, Stalk);
        CompletedTo(Acquire, Roam, EStateTreeTransitionTrigger::OnStateFailed);

        SetState<FJMStateTreeSetStateTask>(Stalk, JMEnemyTags::State_Crawler_Stalk);
        SetProfile(Stalk, TEXT("Stalk"));
        auto& StalkMove = Stalk.AddTask<FJMStateTreeMoveToActorTask>();
        StalkMove.GetInstanceData().Options.AcceptanceRadius = 900.0f;
        EditorData->AddPropertyBinding(Context, TEXT("CurrentTarget"), StalkMove, TEXT("TargetActor"));
        AddEncounterGaze(*EditorData, Stalk, Enrage, EJMStateTreeCompare::GreaterOrEqual, 1,
            EStateTreeTransitionPriority::Critical);
        AddEncounterGaze(*EditorData, Stalk, Flee, EJMStateTreeCompare::Equal, 0,
            EStateTreeTransitionPriority::High);
        AddTargetLost(Stalk, Roam);
        CompletedTo(Stalk, Stalk);
        CompletedTo(Stalk, Roam, EStateTreeTransitionTrigger::OnStateFailed);

        SetState<FJMStateTreeSetStateTask>(Flee, JMEnemyTags::State_Flee);
        SetProfile(Flee, TEXT("Flee"));
        auto& Escape = Flee.AddTask<FJMStateTreeFindEscapeTask>();
        Escape.GetInstanceData().EscapeDistance = 1200.0f;
        EditorData->AddPropertyBinding(Context, TEXT("CurrentTarget"), Escape, TEXT("ThreatActor"));
        auto& EscapeMove = Flee.AddTask<FJMStateTreeMoveToLocationTask>();
        EditorData->AddPropertyBinding(Escape, TEXT("EscapeLocation"), EscapeMove, TEXT("Location"));
        CompletedTo(Flee, Hide, EStateTreeTransitionTrigger::OnStateCompleted);
        CompletedTo(Flee, Hide, EStateTreeTransitionTrigger::OnStateFailed);

        SetState<FJMStateTreeSetStateTask>(Hide, JMEnemyTags::State_Hide);
        Hide.AddTask<FJMStateTreeStopMovementTask>();
        Hide.AddTask<FJMStateTreeIncrementEncounterTask>();
        auto& HideWait = Hide.AddTask<FJMStateTreeWaitTask>();
        HideWait.GetInstanceData().Duration = 3.0f;
        CompletedTo(Hide, ReApproach, EStateTreeTransitionTrigger::OnStateCompleted);

        SetState<FJMStateTreeSetStateTask>(ReApproach, JMEnemyTags::State_Crawler_ReApproach);
        SetProfile(ReApproach, TEXT("ReApproach"));
        auto& ReturnMove = ReApproach.AddTask<FJMStateTreeMoveToActorTask>();
        ReturnMove.GetInstanceData().Options.AcceptanceRadius = 900.0f;
        EditorData->AddPropertyBinding(Context, TEXT("CurrentTarget"), ReturnMove, TEXT("TargetActor"));
        AddEncounterGaze(*EditorData, ReApproach, Enrage, EJMStateTreeCompare::GreaterOrEqual, 1,
            EStateTreeTransitionPriority::Critical);
        AddTargetLost(ReApproach, Roam);
        CompletedTo(ReApproach, ReApproach);
        CompletedTo(ReApproach, Roam, EStateTreeTransitionTrigger::OnStateFailed);

        SetState<FJMStateTreeSetStateTask>(Enrage, JMEnemyTags::State_Enraged);
        Enrage.AddTask<FJMStateTreeStopMovementTask>();
        SetProfile(Enrage, TEXT("Frenzy"));
        auto& Scream = Enrage.AddTask<FJMStateTreeExecuteActionTask>();
        Scream.GetInstanceData().ActionId = JMEnemyTags::Action_Scream;
        EditorData->AddPropertyBinding(Context, TEXT("CurrentTarget"), Scream, TEXT("TargetActor"));
        CompletedTo(Enrage, Frenzy, EStateTreeTransitionTrigger::OnStateCompleted);
        CompletedTo(Enrage, Frenzy, EStateTreeTransitionTrigger::OnStateFailed);

        SetState<FJMStateTreeSetStateTask>(Frenzy, JMEnemyTags::State_Crawler_FrenzyChase);
        SetProfile(Frenzy, TEXT("Frenzy"));
        auto& FrenzyMove = Frenzy.AddTask<FJMStateTreeMoveToActorTask>();
        EditorData->AddPropertyBinding(Context, TEXT("CurrentTarget"), FrenzyMove, TEXT("TargetActor"));
        auto& AttackReady = TickTo(Frenzy, Attack, EStateTreeTransitionPriority::Critical)
            .AddCondition<FJMStateTreeActionReadyCondition>();
        AttackReady.GetInstanceData().ActionId = JMEnemyTags::Action_Melee;
        EditorData->AddPropertyBinding(Context, TEXT("CurrentTarget"), AttackReady, TEXT("TargetActor"));
        AddTargetLost(Frenzy, Roam, EStateTreeTransitionPriority::High);
        CompletedTo(Frenzy, Frenzy);
        CompletedTo(Frenzy, Roam, EStateTreeTransitionTrigger::OnStateFailed);

        SetState<FJMStateTreeSetStateTask>(Attack, JMEnemyTags::State_Attack);
        Attack.AddTask<FJMStateTreeStopMovementTask>();
        auto& Face = Attack.AddTask<FJMStateTreeFaceActorTask>();
        EditorData->AddPropertyBinding(Context, TEXT("CurrentTarget"), Face, TEXT("TargetActor"));
        auto& Melee = Attack.AddTask<FJMStateTreeExecuteActionTask>();
        Melee.GetInstanceData().ActionId = JMEnemyTags::Action_Melee;
        EditorData->AddPropertyBinding(Context, TEXT("CurrentTarget"), Melee, TEXT("TargetActor"));
        AddTargetLost(Attack, Roam, EStateTreeTransitionPriority::Critical);
        CompletedTo(Attack, Frenzy, EStateTreeTransitionTrigger::OnStateCompleted);
        CompletedTo(Attack, Frenzy, EStateTreeTransitionTrigger::OnStateFailed);

        FStateTreeCompilerLog Log;
        if (!UStateTreeEditingSubsystem::CompileStateTree(Tree, Log))
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to compile ST_Crawler"));
            return nullptr;
        }
        return Tree;
    }

    UBlueprint* BuildBlueprint(UJMEnemyDefinition* Definition)
    {
        const FName AssetName(TEXT("BP_Enemy_Crawler"));
        const FString PackageName = FString::Printf(TEXT("%s/%s"), RootPath, *AssetName.ToString());
        const FString ObjectPath = FString::Printf(TEXT("%s.%s"), *PackageName, *AssetName.ToString());
        UPackage* Package = CreatePackage(*PackageName);
        UBlueprint* Blueprint = LoadObject<UBlueprint>(nullptr, *ObjectPath);
        if (!Blueprint) Blueprint = FindObject<UBlueprint>(Package, AssetName.ToString());
        if (!Blueprint)
        {
            Blueprint = FKismetEditorUtilities::CreateBlueprint(AJMSurfaceCrawlerEnemyBase::StaticClass(), Package,
                AssetName, BPTYPE_Normal, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass(),
                FName(TEXT("JMCrawlerReferenceBuilder")));
            FAssetRegistryModule::AssetCreated(Blueprint);
        }
        if (!Blueprint || !Blueprint->GeneratedClass) return nullptr;
        if (Blueprint->SimpleConstructionScript && Blueprint->SimpleConstructionScript->GetAllNodes().IsEmpty())
        {
            USCS_Node* Node = Blueprint->SimpleConstructionScript->CreateNode(
                UStaticMeshComponent::StaticClass(), TEXT("CrawlerPlaceholder"));
            if (UStaticMeshComponent* Mesh = Cast<UStaticMeshComponent>(Node->ComponentTemplate))
            {
                Mesh->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Sphere.Sphere")));
                Mesh->SetRelativeScale3D(FVector(1.1f, 0.55f, 0.35f));
            }
            Blueprint->SimpleConstructionScript->AddNode(Node);
        }
        FObjectProperty* DefinitionProperty = FindFProperty<FObjectProperty>(AJMEnemyBase::StaticClass(), TEXT("EnemyDefinition"));
        AJMEnemyBase* CDO = Cast<AJMEnemyBase>(Blueprint->GeneratedClass->GetDefaultObject());
        if (CDO && DefinitionProperty)
        {
            Blueprint->Modify();
            CDO->Modify();
            DefinitionProperty->SetObjectPropertyValue_InContainer(CDO, Definition);
        }
        FKismetEditorUtilities::CompileBlueprint(Blueprint);
        CDO = Blueprint->GeneratedClass ? Cast<AJMEnemyBase>(Blueprint->GeneratedClass->GetDefaultObject()) : nullptr;
        if (CDO && DefinitionProperty) DefinitionProperty->SetObjectPropertyValue_InContainer(CDO, Definition);
        return Blueprint;
    }

    bool BuildAndSave()
    {
        UJMEnemyMovementSet* Movement = CreateAsset<UJMEnemyMovementSet>(TEXT("DA_Crawler_Movement"));
        Movement->Profiles.Reset();
        auto AddProfile = [Movement](const FName Name, const float Speed)
        {
            FJMEnemyMovementProfile Profile;
            Profile.ProfileName = Name;
            Profile.MaxSpeed = Speed;
            Profile.MaxAcceleration = 2400.0f;
            Profile.AcceptanceRadius = 75.0f;
            Movement->Profiles.Add(Profile);
        };
        AddProfile(TEXT("Roam"), 220.0f);
        AddProfile(TEXT("Stalk"), 300.0f);
        AddProfile(TEXT("Flee"), 650.0f);
        AddProfile(TEXT("ReApproach"), 350.0f);
        AddProfile(TEXT("Frenzy"), 1000.0f);

        UJMEnemyActionDefinition_Melee* Melee = CreateAsset<UJMEnemyActionDefinition_Melee>(TEXT("DA_Crawler_Melee"));
        Melee->Damage = 30.0f;
        Melee->AttackRange = 175.0f;
        Melee->WindupDuration = 0.25f;
        Melee->ActiveDuration = 0.1f;
        Melee->RecoveryDuration = 0.3f;
        Melee->Cooldown = 0.5f;
        UJMEnemyActionDefinition_Scream* Scream = CreateAsset<UJMEnemyActionDefinition_Scream>(TEXT("DA_Crawler_Scream"));
        Scream->WindupDuration = 0.2f;
        Scream->ActiveDuration = 0.5f;
        Scream->RecoveryDuration = 0.3f;
        Scream->Cooldown = 1.0f;

        UStateTree* StateTree = BuildStateTree();
        UJMEnemyAudioSet* Audio = CreateAsset<UJMEnemyAudioSet>(TEXT("DA_Crawler_Audio"));
        Audio->Events.Reset();
        for (const EJMEnemyAudioEvent Event : {EJMEnemyAudioEvent::Flee, EJMEnemyAudioEvent::Enrage,
            EJMEnemyAudioEvent::Frenzy, EJMEnemyAudioEvent::AttackWindup,
            EJMEnemyAudioEvent::Attack, EJMEnemyAudioEvent::Scream})
        {
            FJMEnemyAudioEventEntry& Entry = Audio->Events.AddDefaulted_GetRef();
            Entry.Event = Event;
        }
        UJMEnemyDefinition* Definition = CreateAsset<UJMEnemyDefinition>(TEXT("DA_Enemy_Crawler"));
        Definition->EnemyId = TEXT("Crawler.Reference");
        Definition->DisplayName = FText::FromString(TEXT("Crawler Reference Enemy"));
        Definition->MaxHealth = 90.0f;
        Definition->BaseDamage = 30.0f;
        Definition->InitialState = JMEnemyTags::State_Patrol;
        Definition->Perception.Vision.bEnabled = true;
        Definition->Perception.Vision.SightRadius = 2400.0f;
        Definition->Perception.Vision.LoseSightRadius = 2800.0f;
        Definition->Perception.Hearing.bEnabled = false;
        Definition->Perception.PlayerGaze.bEnabled = true;
        Definition->Perception.PlayerGaze.UpdateInterval = 0.05f;
        Definition->Perception.PlayerGaze.MaximumDistance = 2800.0f;
        Definition->Perception.PlayerGaze.DotThreshold = 0.85f;
        Definition->MovementSet = Movement;
        Definition->DefaultMovementProfile = TEXT("Roam");
        Definition->Actions = {Melee, Scream};
        Definition->StateTree = StateTree;
        Definition->AudioSet = Audio;
        UBlueprint* Blueprint = BuildBlueprint(Definition);

        const bool bSaved = SaveAsset(Movement) && SaveAsset(Melee) && SaveAsset(Scream) && SaveAsset(Audio) &&
            SaveAsset(StateTree) && SaveAsset(Definition) && SaveAsset(Blueprint);
        UE_LOG(LogTemp, Display, TEXT("JM_CRAWLER_REFERENCE_ASSETS=%s"), bSaved ? TEXT("SUCCESS") : TEXT("FAILED"));
        return bSaved;
    }
}

UJMMonsterFrameworkBuildReferenceAssetsCommandlet::UJMMonsterFrameworkBuildReferenceAssetsCommandlet()
{
    IsClient = false;
    IsEditor = true;
    IsServer = false;
    LogToConsole = true;
}

int32 UJMMonsterFrameworkBuildReferenceAssetsCommandlet::Main(const FString& Params)
{
    using namespace JMListenerAssets;
    UJMEnemyMovementSet* Movement = CreateAsset<UJMEnemyMovementSet>(TEXT("DA_Listener_Movement"));
    Movement->Profiles.Reset();
    auto AddProfile = [Movement](const FName Name, const float Speed)
    {
        FJMEnemyMovementProfile Profile;
        Profile.ProfileName = Name;
        Profile.MaxSpeed = Speed;
        Profile.MaxAcceleration = 1600.0f;
        Profile.AcceptanceRadius = 75.0f;
        Movement->Profiles.Add(Profile);
    };
    AddProfile(TEXT("Patrol"), 350.0f);
    AddProfile(TEXT("Investigate"), 450.0f);
    AddProfile(TEXT("Chase"), 650.0f);

    UJMEnemyActionDefinition_Melee* Melee = CreateAsset<UJMEnemyActionDefinition_Melee>(TEXT("DA_Listener_Melee"));
    Melee->Damage = 25.0f;
    Melee->AttackRange = 165.0f;
    Melee->WindupDuration = 0.35f;
    Melee->ActiveDuration = 0.1f;
    Melee->RecoveryDuration = 0.4f;
    Melee->Cooldown = 0.6f;

    UStateTree* StateTree = BuildStateTree();
    UJMEnemyAudioSet* Audio = CreateAsset<UJMEnemyAudioSet>(TEXT("DA_Listener_Audio"));
    Audio->Events.Reset();
    for (const EJMEnemyAudioEvent Event : {EJMEnemyAudioEvent::Investigate, EJMEnemyAudioEvent::Chase,
        EJMEnemyAudioEvent::AttackWindup, EJMEnemyAudioEvent::Attack})
    {
        FJMEnemyAudioEventEntry& Entry = Audio->Events.AddDefaulted_GetRef();
        Entry.Event = Event;
    }
    UJMEnemyDefinition* Definition = CreateAsset<UJMEnemyDefinition>(TEXT("DA_Enemy_Listener"));
    Definition->EnemyId = TEXT("Listener.Reference");
    Definition->DisplayName = FText::FromString(TEXT("Listener Reference Enemy"));
    Definition->MaxHealth = 100.0f;
    Definition->BaseDamage = 25.0f;
    Definition->InitialState = JMEnemyTags::State_Patrol;
    Definition->Perception.Vision.bEnabled = false;
    Definition->Perception.Hearing.bEnabled = true;
    Definition->Perception.Hearing.HearingRange = 2200.0f;
    Definition->Perception.Hearing.StimulusMaxAge = 8.0f;
    Definition->Perception.Hearing.MinimumStrength = 0.2f;
    Definition->Perception.PlayerGaze.bEnabled = false;
    Definition->MovementSet = Movement;
    Definition->DefaultMovementProfile = TEXT("Patrol");
    Definition->Actions = {Melee};
    Definition->StateTree = StateTree;
    Definition->AudioSet = Audio;
    UBlueprint* Blueprint = BuildBlueprint(Definition);

    const bool bMovementSaved = SaveAsset(Movement);
    const bool bMeleeSaved = SaveAsset(Melee);
    const bool bTreeSaved = SaveAsset(StateTree);
    const bool bAudioSaved = SaveAsset(Audio);
    const bool bDefinitionSaved = SaveAsset(Definition);
    const bool bBlueprintSaved = SaveAsset(Blueprint);
    UE_LOG(LogTemp, Display, TEXT("JM_LISTENER_SAVE Movement=%d Melee=%d Tree=%d Definition=%d Blueprint=%d"),
        bMovementSaved, bMeleeSaved, bTreeSaved, bDefinitionSaved, bBlueprintSaved);
    const bool bSaved = bMovementSaved && bMeleeSaved && bAudioSaved && bTreeSaved && bDefinitionSaved && bBlueprintSaved;
    UE_LOG(LogTemp, Display, TEXT("JM_LISTENER_REFERENCE_ASSETS=%s"), bSaved ? TEXT("SUCCESS") : TEXT("FAILED"));
    const bool bWatcherSaved = JMWatcherAssets::BuildAndSave();
    const bool bCrawlerSaved = JMCrawlerAssets::BuildAndSave();
    return bSaved && bWatcherSaved && bCrawlerSaved ? 0 : 1;
}
