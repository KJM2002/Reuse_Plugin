#include "AI/JMAIBehaviorTreeAuthoringLibrary.h"

#include "AI/Common/JMDungeonMonster.h"
#include "AI/Common/JMMonsterBehaviorTreeNodes.h"
#include "AIGraphSchema.h"
#include "AIGraphTypes.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Enum.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Int.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Name.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/Composites/BTComposite_Selector.h"
#include "BehaviorTreeGraph.h"
#include "BehaviorTreeGraphNode_Composite.h"
#include "BehaviorTreeGraphNode_Decorator.h"
#include "BehaviorTreeGraphNode_Root.h"
#include "BehaviorTreeGraphNode_Task.h"
#include "EdGraph/EdGraph.h"
#include "EdGraph/EdGraphSchema.h"
#include "EdGraphSchema_BehaviorTree.h"
#include "Engine/Blueprint.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Misc/PackageName.h"
#include "UObject/SavePackage.h"

namespace
{
	struct FMonsterBTSpec
	{
		const TCHAR* TypeName;
		const TCHAR* Folder;
	};

	const TArray<TPair<EJMDungeonMonsterState, const TCHAR*>> StateSpecs = {
		{EJMDungeonMonsterState::Dormant, TEXT("Dormant")},
		{EJMDungeonMonsterState::Patrol, TEXT("Patrol")},
		{EJMDungeonMonsterState::Suspicious, TEXT("Suspicious")},
		{EJMDungeonMonsterState::Investigate, TEXT("Investigate")},
		{EJMDungeonMonsterState::Chase, TEXT("Chase")},
		{EJMDungeonMonsterState::AttackWarning, TEXT("AttackWarning")},
		{EJMDungeonMonsterState::Search, TEXT("Search")},
		{EJMDungeonMonsterState::Return, TEXT("Return")},
	};

	bool SaveAsset(UObject* Asset)
	{
		if (!Asset)
		{
			return false;
		}
		UPackage* Package = Asset->GetOutermost();
		const FString Filename = FPackageName::LongPackageNameToFilename(
			Package->GetName(), FPackageName::GetAssetPackageExtension());
		FSavePackageArgs Args;
		Args.TopLevelFlags = RF_Public | RF_Standalone;
		Args.SaveFlags = SAVE_NoError;
		return UPackage::SavePackage(Package, Asset, *Filename, Args);
	}

	template <typename AssetType>
	AssetType* FindOrCreateAsset(const FString& PackageName, const FString& AssetName)
	{
		if (AssetType* Existing = LoadObject<AssetType>(nullptr, *FString::Printf(TEXT("%s.%s"), *PackageName, *AssetName)))
		{
			return Existing;
		}
		UPackage* Package = CreatePackage(*PackageName);
		AssetType* Asset = NewObject<AssetType>(Package, *AssetName,
			RF_Public | RF_Standalone | RF_Transactional);
		FAssetRegistryModule::AssetCreated(Asset);
		Asset->MarkPackageDirty();
		return Asset;
	}

	template <typename KeyType>
	KeyType* AddKey(UBlackboardData& Blackboard, const FName Name, const TCHAR* Description,
		const FName Category = TEXT("Runtime"))
	{
		FBlackboardEntry& Entry = Blackboard.Keys.AddDefaulted_GetRef();
		Entry.EntryName = Name;
		Entry.EntryDescription = Description;
		Entry.EntryCategory = Category;
		KeyType* Type = NewObject<KeyType>(&Blackboard);
		Entry.KeyType = Type;
		return Type;
	}

	void ConfigureBlackboard(UBlackboardData& Blackboard)
	{
		Blackboard.Modify();
		Blackboard.Keys.Reset();
		UBlackboardKeyType_Enum* State = AddKey<UBlackboardKeyType_Enum>(Blackboard, TEXT("State"),
			TEXT("Authoritative EJMDungeonMonsterState used by the visible BT branches."), TEXT("State"));
		State->EnumType = StaticEnum<EJMDungeonMonsterState>();
		AddKey<UBlackboardKeyType_Name>(Blackboard, TEXT("StateName"),
			TEXT("Readable state name for live debugging."), TEXT("State"));
		UBlackboardKeyType_Enum* PatrolMode = AddKey<UBlackboardKeyType_Enum>(Blackboard, TEXT("PatrolMode"),
			TEXT("ContinuousLoop or Stationary."), TEXT("Patrol"));
		PatrolMode->EnumType = StaticEnum<EJMDungeonPatrolMode>();
		UBlackboardKeyType_Object* Monster = AddKey<UBlackboardKeyType_Object>(Blackboard, TEXT("MonsterActor"),
			TEXT("The controlled dungeon monster."), TEXT("Actors"));
		Monster->BaseClass = AActor::StaticClass();
		UBlackboardKeyType_Object* Target = AddKey<UBlackboardKeyType_Object>(Blackboard, TEXT("TargetActor"),
			TEXT("Current player target, empty while idle."), TEXT("Actors"));
		Target->BaseClass = AActor::StaticClass();
		AddKey<UBlackboardKeyType_Vector>(Blackboard, TEXT("LastKnownLocation"),
			TEXT("Last sight or noise evidence position."), TEXT("Evidence"));
		AddKey<UBlackboardKeyType_Int>(Blackboard, TEXT("PatrolIndex"),
			TEXT("Current authored patrol POI index."), TEXT("Patrol"));
		AddKey<UBlackboardKeyType_Int>(Blackboard, TEXT("PatrolPointCount"),
			TEXT("Number of authored patrol POIs."), TEXT("Patrol"));
		AddKey<UBlackboardKeyType_Int>(Blackboard, TEXT("CompletedPatrolLegs"),
			TEXT("Monotonic counter useful for verifying continuous looping."), TEXT("Patrol"));
		AddKey<UBlackboardKeyType_Bool>(Blackboard, TEXT("IsEnabled"),
			TEXT("False during authored activation delay or explicit dormancy."), TEXT("State"));
		Blackboard.UpdateKeyIDs();
		Blackboard.UpdateIfHasSynchronizedKeys();
		Blackboard.MarkPackageDirty();
	}

	UBlueprint* FindOrCreateTaskBlueprint(const FMonsterBTSpec& MonsterSpec,
		EJMDungeonMonsterState State, const TCHAR* StateName)
	{
		const FString AssetName = FString::Printf(TEXT("BTT_%s_%s"), MonsterSpec.TypeName, StateName);
		const FString PackageName = FString::Printf(TEXT("%s/%s"), MonsterSpec.Folder, *AssetName);
		UBlueprint* Blueprint = LoadObject<UBlueprint>(nullptr,
			*FString::Printf(TEXT("%s.%s"), *PackageName, *AssetName));
		if (!Blueprint)
		{
			UPackage* Package = CreatePackage(*PackageName);
			Blueprint = FKismetEditorUtilities::CreateBlueprint(UBTTask_JMMonsterState::StaticClass(), Package,
				*AssetName, BPTYPE_Normal, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass(),
				TEXT("JMMonsterBehaviorTreeAuthoring"));
			FAssetRegistryModule::AssetCreated(Blueprint);
		}
		FKismetEditorUtilities::CompileBlueprint(Blueprint);
		if (UClass* GeneratedClass = Blueprint ? Blueprint->GeneratedClass : nullptr)
		{
			if (UBTTask_JMMonsterState* Defaults = Cast<UBTTask_JMMonsterState>(GeneratedClass->GetDefaultObject()))
			{
				Defaults->ConfigureTask(State,
					FString::Printf(TEXT("%s: %s"), MonsterSpec.TypeName, StateName));
			}
		}
		Blueprint->BlueprintDescription = FString::Printf(
			TEXT("Actual %s %s state task. Runtime behavior is implemented by UBTTask_JMMonsterState."),
			MonsterSpec.TypeName, StateName);
		Blueprint->MarkPackageDirty();
		SaveAsset(Blueprint);
		return Blueprint;
	}

	UBehaviorTreeGraphNode* SpawnGraphNode(UBehaviorTreeGraph& Graph, UClass* GraphNodeClass,
		UClass* RuntimeNodeClass, UEdGraphPin* FromPin, const FVector2f Position)
	{
		UBehaviorTreeGraphNode* Template = NewObject<UBehaviorTreeGraphNode>(&Graph, GraphNodeClass);
		Template->ClassData = FGraphNodeClassData(RuntimeNodeClass, FString());
		FAISchemaAction_NewNode Action;
		Action.NodeTemplate = Template;
		return Cast<UBehaviorTreeGraphNode>(Action.PerformAction(&Graph, FromPin, Position, false));
	}

	bool BuildTreeForMonster(const FMonsterBTSpec& MonsterSpec)
	{
		const FString BlackboardName = FString::Printf(TEXT("BB_%s"), MonsterSpec.TypeName);
		const FString BlackboardPackage = FString::Printf(TEXT("%s/%s"), MonsterSpec.Folder, *BlackboardName);
		UBlackboardData* Blackboard = FindOrCreateAsset<UBlackboardData>(BlackboardPackage, BlackboardName);
		ConfigureBlackboard(*Blackboard);
		SaveAsset(Blackboard);

		TArray<UBlueprint*> Tasks;
		for (const TPair<EJMDungeonMonsterState, const TCHAR*>& StateSpec : StateSpecs)
		{
			Tasks.Add(FindOrCreateTaskBlueprint(MonsterSpec, StateSpec.Key, StateSpec.Value));
		}

		const FString TreeName = FString::Printf(TEXT("BT_%s"), MonsterSpec.TypeName);
		const FString TreePackage = FString::Printf(TEXT("%s/%s"), MonsterSpec.Folder, *TreeName);
		UBehaviorTree* Tree = FindOrCreateAsset<UBehaviorTree>(TreePackage, TreeName);
		if (Tree->BTGraph)
		{
			// Existing authored graph is preserved so rerunning this utility never destroys manual edits.
			Tree->BlackboardAsset = Blackboard;
			Tree->MarkPackageDirty();
			return SaveAsset(Tree);
		}

		Tree->BlackboardAsset = Blackboard;
		Tree->BTGraph = FBlueprintEditorUtils::CreateNewGraph(Tree, TEXT("BehaviorTree"),
			UBehaviorTreeGraph::StaticClass(), UEdGraphSchema_BehaviorTree::StaticClass());
		UBehaviorTreeGraph* Graph = CastChecked<UBehaviorTreeGraph>(Tree->BTGraph);
		Graph->GetSchema()->CreateDefaultNodesForGraph(*Graph);
		Graph->OnCreated();
		Graph->Initialize();

		UBehaviorTreeGraphNode_Root* Root = nullptr;
		for (UEdGraphNode* Node : Graph->Nodes)
		{
			if ((Root = Cast<UBehaviorTreeGraphNode_Root>(Node)))
			{
				break;
			}
		}
		if (!Root)
		{
			return false;
		}
		Root->BlackboardAsset = Blackboard;
		Root->UpdateBlackboard();

		UBehaviorTreeGraphNode* Selector = SpawnGraphNode(*Graph,
			UBehaviorTreeGraphNode_Composite::StaticClass(), UBTComposite_Selector::StaticClass(),
			Root->GetOutputPin(), FVector2f(0.0f, 180.0f));
		if (!Selector)
		{
			return false;
		}

		for (int32 Index = 0; Index < StateSpecs.Num(); ++Index)
		{
			UClass* TaskClass = Tasks[Index] ? Tasks[Index]->GeneratedClass : nullptr;
			UBehaviorTreeGraphNode* TaskNode = SpawnGraphNode(*Graph,
				UBehaviorTreeGraphNode_Task::StaticClass(), TaskClass, Selector->GetOutputPin(),
				FVector2f(-1050.0f + Index * 300.0f, 430.0f));
			if (!TaskNode)
			{
				return false;
			}
			if (UBTTask_JMMonsterState* TaskInstance = Cast<UBTTask_JMMonsterState>(TaskNode->NodeInstance))
			{
				TaskInstance->ConfigureTask(StateSpecs[Index].Key,
					FString::Printf(TEXT("%s: %s"), MonsterSpec.TypeName, StateSpecs[Index].Value));
			}

			UBehaviorTreeGraphNode_Decorator* DecoratorTemplate =
				NewObject<UBehaviorTreeGraphNode_Decorator>(Graph);
			DecoratorTemplate->ClassData = FGraphNodeClassData(UBTDecorator_JMMonsterState::StaticClass(), FString());
			FAISchemaAction_NewSubNode DecoratorAction;
			DecoratorAction.ParentNode = TaskNode;
			DecoratorAction.NodeTemplate = DecoratorTemplate;
			DecoratorAction.PerformAction(Graph, nullptr, FVector2f::ZeroVector, false);
			if (UBTDecorator_JMMonsterState* Decorator =
				Cast<UBTDecorator_JMMonsterState>(DecoratorTemplate->NodeInstance))
			{
				Decorator->ExpectedState = StateSpecs[Index].Key;
			}
		}

		Graph->UpdateAsset();
		Graph->OnSave();
		Tree->MarkPackageDirty();
		return SaveAsset(Tree);
	}
}

bool UJMAIBehaviorTreeAuthoringLibrary::BuildMonsterBehaviorTreeAssets()
{
	const TArray<FMonsterBTSpec> MonsterSpecs = {
		{TEXT("Listener"), TEXT("/Game/AI/Listener")},
		{TEXT("Hoarder"), TEXT("/Game/AI/Hoarder")},
		{TEXT("Blackout"), TEXT("/Game/AI/Blackout")},
	};
	bool bSuccess = true;
	for (const FMonsterBTSpec& Spec : MonsterSpecs)
	{
		bSuccess &= BuildTreeForMonster(Spec);
	}
	UE_LOG(LogTemp, Display, TEXT("JM_AI_BT_AUTHORING result=%s monsters=%d tasks_per_monster=%d"),
		bSuccess ? TEXT("success") : TEXT("failure"), MonsterSpecs.Num(), StateSpecs.Num());
	return bSuccess;
}
