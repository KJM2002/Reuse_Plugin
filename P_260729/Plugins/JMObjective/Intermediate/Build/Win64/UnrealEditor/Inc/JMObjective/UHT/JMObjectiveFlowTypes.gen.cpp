// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Types/JMObjectiveFlowTypes.h"
#include "GameplayTagContainer.h"
#include "Types/JMObjectiveTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMObjectiveFlowTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveFlowDefinition_NoRegister();
JMOBJECTIVE_API UEnum* Z_Construct_UEnum_JMObjective_EJMObjectiveFlowState();
JMOBJECTIVE_API UFunction* Z_Construct_UDelegateFunction_JMObjective_JMObjectiveFlowStateChangedSignature__DelegateSignature();
JMOBJECTIVE_API UScriptStruct* Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState();
JMOBJECTIVE_API UScriptStruct* Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData();
JMOBJECTIVE_API UScriptStruct* Z_Construct_UScriptStruct_FJMObjectiveSaveData();
UPackage* Z_Construct_UPackage__Script_JMObjective();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EJMObjectiveFlowState *****************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMObjectiveFlowState;
static UEnum* EJMObjectiveFlowState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMObjectiveFlowState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMObjectiveFlowState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMObjective_EJMObjectiveFlowState, (UObject*)Z_Construct_UPackage__Script_JMObjective(), TEXT("EJMObjectiveFlowState"));
	}
	return Z_Registration_Info_UEnum_EJMObjectiveFlowState.OuterSingleton;
}
template<> JMOBJECTIVE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMObjectiveFlowState>()
{
	return EJMObjectiveFlowState_StaticEnum();
}
struct Z_Construct_UEnum_JMObjective_EJMObjectiveFlowState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Active.Name", "EJMObjectiveFlowState::Active" },
		{ "BlueprintType", "true" },
		{ "Completed.Name", "EJMObjectiveFlowState::Completed" },
		{ "Failed.Name", "EJMObjectiveFlowState::Failed" },
		{ "Inactive.Name", "EJMObjectiveFlowState::Inactive" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveFlowTypes.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMObjectiveFlowState::Inactive", (int64)EJMObjectiveFlowState::Inactive },
		{ "EJMObjectiveFlowState::Active", (int64)EJMObjectiveFlowState::Active },
		{ "EJMObjectiveFlowState::Completed", (int64)EJMObjectiveFlowState::Completed },
		{ "EJMObjectiveFlowState::Failed", (int64)EJMObjectiveFlowState::Failed },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMObjective_EJMObjectiveFlowState_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMObjective_EJMObjectiveFlowState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMObjective,
	nullptr,
	"EJMObjectiveFlowState",
	"EJMObjectiveFlowState",
	Z_Construct_UEnum_JMObjective_EJMObjectiveFlowState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMObjective_EJMObjectiveFlowState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMObjective_EJMObjectiveFlowState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMObjective_EJMObjectiveFlowState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMObjective_EJMObjectiveFlowState()
{
	if (!Z_Registration_Info_UEnum_EJMObjectiveFlowState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMObjectiveFlowState.InnerSingleton, Z_Construct_UEnum_JMObjective_EJMObjectiveFlowState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMObjectiveFlowState.InnerSingleton;
}
// ********** End Enum EJMObjectiveFlowState *******************************************************

// ********** Begin ScriptStruct FJMObjectiveFlowRuntimeState **************************************
struct Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMObjectiveFlowRuntimeState); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMObjectiveFlowRuntimeState); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveFlowTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlowId_MetaData[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveFlowTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Definition_MetaData[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveFlowTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_State_MetaData[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveFlowTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentStepIndex_MetaData[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveFlowTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentObjectiveId_MetaData[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveFlowTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartTime_MetaData[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveFlowTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CompletionTime_MetaData[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveFlowTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FailureTime_MetaData[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveFlowTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMObjectiveFlowRuntimeState constinit property declarations ******
	static const UECodeGen_Private::FStructPropertyParams NewProp_FlowId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Definition;
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentStepIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentObjectiveId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StartTime;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CompletionTime;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FailureTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMObjectiveFlowRuntimeState constinit property declarations ********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMObjectiveFlowRuntimeState>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMObjectiveFlowRuntimeState;
class UScriptStruct* FJMObjectiveFlowRuntimeState::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMObjectiveFlowRuntimeState.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMObjectiveFlowRuntimeState.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState, (UObject*)Z_Construct_UPackage__Script_JMObjective(), TEXT("JMObjectiveFlowRuntimeState"));
	}
	return Z_Registration_Info_UScriptStruct_FJMObjectiveFlowRuntimeState.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMObjectiveFlowRuntimeState Property Definitions *****************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::NewProp_FlowId = { "FlowId", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveFlowRuntimeState, FlowId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlowId_MetaData), NewProp_FlowId_MetaData) }; // 517357616
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::NewProp_Definition = { "Definition", nullptr, (EPropertyFlags)0x0114000000020015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveFlowRuntimeState, Definition), Z_Construct_UClass_UJMObjectiveFlowDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Definition_MetaData), NewProp_Definition_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveFlowRuntimeState, State), Z_Construct_UEnum_JMObjective_EJMObjectiveFlowState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_State_MetaData), NewProp_State_MetaData) }; // 1681952767
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::NewProp_CurrentStepIndex = { "CurrentStepIndex", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveFlowRuntimeState, CurrentStepIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentStepIndex_MetaData), NewProp_CurrentStepIndex_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::NewProp_CurrentObjectiveId = { "CurrentObjectiveId", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveFlowRuntimeState, CurrentObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentObjectiveId_MetaData), NewProp_CurrentObjectiveId_MetaData) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::NewProp_StartTime = { "StartTime", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveFlowRuntimeState, StartTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartTime_MetaData), NewProp_StartTime_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::NewProp_CompletionTime = { "CompletionTime", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveFlowRuntimeState, CompletionTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CompletionTime_MetaData), NewProp_CompletionTime_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::NewProp_FailureTime = { "FailureTime", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveFlowRuntimeState, FailureTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FailureTime_MetaData), NewProp_FailureTime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::NewProp_FlowId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::NewProp_Definition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::NewProp_State,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::NewProp_CurrentStepIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::NewProp_CurrentObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::NewProp_StartTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::NewProp_CompletionTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::NewProp_FailureTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMObjectiveFlowRuntimeState Property Definitions *******************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMObjective,
	nullptr,
	&NewStructOps,
	"JMObjectiveFlowRuntimeState",
	Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::PropPointers),
	sizeof(FJMObjectiveFlowRuntimeState),
	alignof(FJMObjectiveFlowRuntimeState),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState()
{
	if (!Z_Registration_Info_UScriptStruct_FJMObjectiveFlowRuntimeState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMObjectiveFlowRuntimeState.InnerSingleton, Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMObjectiveFlowRuntimeState.InnerSingleton);
}
// ********** End ScriptStruct FJMObjectiveFlowRuntimeState ****************************************

// ********** Begin ScriptStruct FJMObjectiveFlowSaveData ******************************************
struct Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMObjectiveFlowSaveData); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMObjectiveFlowSaveData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveFlowTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlowId_MetaData[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveFlowTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Definition_MetaData[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveFlowTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_State_MetaData[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveFlowTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentStepIndex_MetaData[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveFlowTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentObjectiveId_MetaData[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveFlowTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartTime_MetaData[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveFlowTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CompletionTime_MetaData[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveFlowTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FailureTime_MetaData[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveFlowTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectiveStates_MetaData[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveFlowTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMObjectiveFlowSaveData constinit property declarations **********
	static const UECodeGen_Private::FStructPropertyParams NewProp_FlowId;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Definition;
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentStepIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentObjectiveId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StartTime;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CompletionTime;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FailureTime;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveStates_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ObjectiveStates;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMObjectiveFlowSaveData constinit property declarations ************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMObjectiveFlowSaveData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMObjectiveFlowSaveData;
class UScriptStruct* FJMObjectiveFlowSaveData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMObjectiveFlowSaveData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMObjectiveFlowSaveData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData, (UObject*)Z_Construct_UPackage__Script_JMObjective(), TEXT("JMObjectiveFlowSaveData"));
	}
	return Z_Registration_Info_UScriptStruct_FJMObjectiveFlowSaveData.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMObjectiveFlowSaveData Property Definitions *********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::NewProp_FlowId = { "FlowId", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveFlowSaveData, FlowId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlowId_MetaData), NewProp_FlowId_MetaData) }; // 517357616
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::NewProp_Definition = { "Definition", nullptr, (EPropertyFlags)0x0014000001000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveFlowSaveData, Definition), Z_Construct_UClass_UJMObjectiveFlowDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Definition_MetaData), NewProp_Definition_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveFlowSaveData, State), Z_Construct_UEnum_JMObjective_EJMObjectiveFlowState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_State_MetaData), NewProp_State_MetaData) }; // 1681952767
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::NewProp_CurrentStepIndex = { "CurrentStepIndex", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveFlowSaveData, CurrentStepIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentStepIndex_MetaData), NewProp_CurrentStepIndex_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::NewProp_CurrentObjectiveId = { "CurrentObjectiveId", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveFlowSaveData, CurrentObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentObjectiveId_MetaData), NewProp_CurrentObjectiveId_MetaData) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::NewProp_StartTime = { "StartTime", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveFlowSaveData, StartTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartTime_MetaData), NewProp_StartTime_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::NewProp_CompletionTime = { "CompletionTime", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveFlowSaveData, CompletionTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CompletionTime_MetaData), NewProp_CompletionTime_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::NewProp_FailureTime = { "FailureTime", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveFlowSaveData, FailureTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FailureTime_MetaData), NewProp_FailureTime_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::NewProp_ObjectiveStates_Inner = { "ObjectiveStates", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FJMObjectiveSaveData, METADATA_PARAMS(0, nullptr) }; // 220837192
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::NewProp_ObjectiveStates = { "ObjectiveStates", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveFlowSaveData, ObjectiveStates), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectiveStates_MetaData), NewProp_ObjectiveStates_MetaData) }; // 220837192
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::NewProp_FlowId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::NewProp_Definition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::NewProp_State,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::NewProp_CurrentStepIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::NewProp_CurrentObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::NewProp_StartTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::NewProp_CompletionTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::NewProp_FailureTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::NewProp_ObjectiveStates_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::NewProp_ObjectiveStates,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMObjectiveFlowSaveData Property Definitions ***********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMObjective,
	nullptr,
	&NewStructOps,
	"JMObjectiveFlowSaveData",
	Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::PropPointers),
	sizeof(FJMObjectiveFlowSaveData),
	alignof(FJMObjectiveFlowSaveData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData()
{
	if (!Z_Registration_Info_UScriptStruct_FJMObjectiveFlowSaveData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMObjectiveFlowSaveData.InnerSingleton, Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMObjectiveFlowSaveData.InnerSingleton);
}
// ********** End ScriptStruct FJMObjectiveFlowSaveData ********************************************

// ********** Begin Delegate FJMObjectiveFlowStateChangedSignature *********************************
struct Z_Construct_UDelegateFunction_JMObjective_JMObjectiveFlowStateChangedSignature__DelegateSignature_Statics
{
	struct _Script_JMObjective_eventJMObjectiveFlowStateChangedSignature_Parms
	{
		FGameplayTag FlowId;
		FJMObjectiveFlowRuntimeState RuntimeState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Types/JMObjectiveFlowTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RuntimeState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMObjectiveFlowStateChangedSignature constinit property declarations *
	static const UECodeGen_Private::FStructPropertyParams NewProp_FlowId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RuntimeState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMObjectiveFlowStateChangedSignature constinit property declarations ***
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMObjectiveFlowStateChangedSignature Property Definitions ************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_JMObjective_JMObjectiveFlowStateChangedSignature__DelegateSignature_Statics::NewProp_FlowId = { "FlowId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMObjective_eventJMObjectiveFlowStateChangedSignature_Parms, FlowId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_JMObjective_JMObjectiveFlowStateChangedSignature__DelegateSignature_Statics::NewProp_RuntimeState = { "RuntimeState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMObjective_eventJMObjectiveFlowStateChangedSignature_Parms, RuntimeState), Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RuntimeState_MetaData), NewProp_RuntimeState_MetaData) }; // 853706147
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMObjective_JMObjectiveFlowStateChangedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMObjective_JMObjectiveFlowStateChangedSignature__DelegateSignature_Statics::NewProp_FlowId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMObjective_JMObjectiveFlowStateChangedSignature__DelegateSignature_Statics::NewProp_RuntimeState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMObjective_JMObjectiveFlowStateChangedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMObjectiveFlowStateChangedSignature Property Definitions **************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMObjective_JMObjectiveFlowStateChangedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMObjective, nullptr, "JMObjectiveFlowStateChangedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_JMObjective_JMObjectiveFlowStateChangedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMObjective_JMObjectiveFlowStateChangedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMObjective_JMObjectiveFlowStateChangedSignature__DelegateSignature_Statics::_Script_JMObjective_eventJMObjectiveFlowStateChangedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMObjective_JMObjectiveFlowStateChangedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMObjective_JMObjectiveFlowStateChangedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMObjective_JMObjectiveFlowStateChangedSignature__DelegateSignature_Statics::_Script_JMObjective_eventJMObjectiveFlowStateChangedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMObjective_JMObjectiveFlowStateChangedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMObjective_JMObjectiveFlowStateChangedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMObjectiveFlowStateChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMObjectiveFlowStateChangedSignature, FGameplayTag FlowId, FJMObjectiveFlowRuntimeState const& RuntimeState)
{
	struct _Script_JMObjective_eventJMObjectiveFlowStateChangedSignature_Parms
	{
		FGameplayTag FlowId;
		FJMObjectiveFlowRuntimeState RuntimeState;
	};
	_Script_JMObjective_eventJMObjectiveFlowStateChangedSignature_Parms Parms;
	Parms.FlowId=FlowId;
	Parms.RuntimeState=RuntimeState;
	JMObjectiveFlowStateChangedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMObjectiveFlowStateChangedSignature ***********************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Types_JMObjectiveFlowTypes_h__Script_JMObjective_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EJMObjectiveFlowState_StaticEnum, TEXT("EJMObjectiveFlowState"), &Z_Registration_Info_UEnum_EJMObjectiveFlowState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1681952767U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FJMObjectiveFlowRuntimeState::StaticStruct, Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics::NewStructOps, TEXT("JMObjectiveFlowRuntimeState"),&Z_Registration_Info_UScriptStruct_FJMObjectiveFlowRuntimeState, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMObjectiveFlowRuntimeState), 853706147U) },
		{ FJMObjectiveFlowSaveData::StaticStruct, Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics::NewStructOps, TEXT("JMObjectiveFlowSaveData"),&Z_Registration_Info_UScriptStruct_FJMObjectiveFlowSaveData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMObjectiveFlowSaveData), 2623431764U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Types_JMObjectiveFlowTypes_h__Script_JMObjective_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Types_JMObjectiveFlowTypes_h__Script_JMObjective_1090359026{
	TEXT("/Script/JMObjective"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Types_JMObjectiveFlowTypes_h__Script_JMObjective_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Types_JMObjectiveFlowTypes_h__Script_JMObjective_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Types_JMObjectiveFlowTypes_h__Script_JMObjective_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Types_JMObjectiveFlowTypes_h__Script_JMObjective_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
