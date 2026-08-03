// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Types/JMObjectiveTypes.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMObjectiveTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveDefinition_NoRegister();
JMOBJECTIVE_API UEnum* Z_Construct_UEnum_JMObjective_EJMObjectiveProgressIncrementMode();
JMOBJECTIVE_API UEnum* Z_Construct_UEnum_JMObjective_EJMObjectiveState();
JMOBJECTIVE_API UFunction* Z_Construct_UDelegateFunction_JMObjective_JMObjectiveProgressedSignature__DelegateSignature();
JMOBJECTIVE_API UFunction* Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature();
JMOBJECTIVE_API UScriptStruct* Z_Construct_UScriptStruct_FJMObjectiveRuntimeState();
JMOBJECTIVE_API UScriptStruct* Z_Construct_UScriptStruct_FJMObjectiveSaveData();
UPackage* Z_Construct_UPackage__Script_JMObjective();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EJMObjectiveState *********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMObjectiveState;
static UEnum* EJMObjectiveState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMObjectiveState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMObjectiveState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMObjective_EJMObjectiveState, (UObject*)Z_Construct_UPackage__Script_JMObjective(), TEXT("EJMObjectiveState"));
	}
	return Z_Registration_Info_UEnum_EJMObjectiveState.OuterSingleton;
}
template<> JMOBJECTIVE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMObjectiveState>()
{
	return EJMObjectiveState_StaticEnum();
}
struct Z_Construct_UEnum_JMObjective_EJMObjectiveState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Active.Name", "EJMObjectiveState::Active" },
		{ "BlueprintType", "true" },
		{ "Completed.Name", "EJMObjectiveState::Completed" },
		{ "Failed.Name", "EJMObjectiveState::Failed" },
		{ "Inactive.Name", "EJMObjectiveState::Inactive" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveTypes.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMObjectiveState::Inactive", (int64)EJMObjectiveState::Inactive },
		{ "EJMObjectiveState::Active", (int64)EJMObjectiveState::Active },
		{ "EJMObjectiveState::Completed", (int64)EJMObjectiveState::Completed },
		{ "EJMObjectiveState::Failed", (int64)EJMObjectiveState::Failed },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMObjective_EJMObjectiveState_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMObjective_EJMObjectiveState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMObjective,
	nullptr,
	"EJMObjectiveState",
	"EJMObjectiveState",
	Z_Construct_UEnum_JMObjective_EJMObjectiveState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMObjective_EJMObjectiveState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMObjective_EJMObjectiveState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMObjective_EJMObjectiveState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMObjective_EJMObjectiveState()
{
	if (!Z_Registration_Info_UEnum_EJMObjectiveState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMObjectiveState.InnerSingleton, Z_Construct_UEnum_JMObjective_EJMObjectiveState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMObjectiveState.InnerSingleton;
}
// ********** End Enum EJMObjectiveState ***********************************************************

// ********** Begin Enum EJMObjectiveProgressIncrementMode *****************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMObjectiveProgressIncrementMode;
static UEnum* EJMObjectiveProgressIncrementMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMObjectiveProgressIncrementMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMObjectiveProgressIncrementMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMObjective_EJMObjectiveProgressIncrementMode, (UObject*)Z_Construct_UPackage__Script_JMObjective(), TEXT("EJMObjectiveProgressIncrementMode"));
	}
	return Z_Registration_Info_UEnum_EJMObjectiveProgressIncrementMode.OuterSingleton;
}
template<> JMOBJECTIVE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMObjectiveProgressIncrementMode>()
{
	return EJMObjectiveProgressIncrementMode_StaticEnum();
}
struct Z_Construct_UEnum_JMObjective_EJMObjectiveProgressIncrementMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "FixedAmount.Name", "EJMObjectiveProgressIncrementMode::FixedAmount" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveTypes.h" },
		{ "PayloadAmount.Name", "EJMObjectiveProgressIncrementMode::PayloadAmount" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMObjectiveProgressIncrementMode::FixedAmount", (int64)EJMObjectiveProgressIncrementMode::FixedAmount },
		{ "EJMObjectiveProgressIncrementMode::PayloadAmount", (int64)EJMObjectiveProgressIncrementMode::PayloadAmount },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMObjective_EJMObjectiveProgressIncrementMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMObjective_EJMObjectiveProgressIncrementMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMObjective,
	nullptr,
	"EJMObjectiveProgressIncrementMode",
	"EJMObjectiveProgressIncrementMode",
	Z_Construct_UEnum_JMObjective_EJMObjectiveProgressIncrementMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMObjective_EJMObjectiveProgressIncrementMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMObjective_EJMObjectiveProgressIncrementMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMObjective_EJMObjectiveProgressIncrementMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMObjective_EJMObjectiveProgressIncrementMode()
{
	if (!Z_Registration_Info_UEnum_EJMObjectiveProgressIncrementMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMObjectiveProgressIncrementMode.InnerSingleton, Z_Construct_UEnum_JMObjective_EJMObjectiveProgressIncrementMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMObjectiveProgressIncrementMode.InnerSingleton;
}
// ********** End Enum EJMObjectiveProgressIncrementMode *******************************************

// ********** Begin ScriptStruct FJMObjectiveRuntimeState ******************************************
struct Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMObjectiveRuntimeState); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMObjectiveRuntimeState); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectiveId_MetaData[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Definition_MetaData[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_State_MetaData[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentCount_MetaData[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequiredCount_MetaData[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivationTime_MetaData[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CompletionTime_MetaData[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FailureTime_MetaData[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastEventTag_MetaData[] = {
		{ "Category", "JM Objective|Debug" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastTargetIdentifier_MetaData[] = {
		{ "Category", "JM Objective|Debug" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMObjectiveRuntimeState constinit property declarations **********
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Definition;
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RequiredCount;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActivationTime;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CompletionTime;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FailureTime;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LastEventTag;
	static const UECodeGen_Private::FNamePropertyParams NewProp_LastTargetIdentifier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMObjectiveRuntimeState constinit property declarations ************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMObjectiveRuntimeState>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMObjectiveRuntimeState;
class UScriptStruct* FJMObjectiveRuntimeState::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMObjectiveRuntimeState.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMObjectiveRuntimeState.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, (UObject*)Z_Construct_UPackage__Script_JMObjective(), TEXT("JMObjectiveRuntimeState"));
	}
	return Z_Registration_Info_UScriptStruct_FJMObjectiveRuntimeState.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMObjectiveRuntimeState Property Definitions *********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveRuntimeState, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectiveId_MetaData), NewProp_ObjectiveId_MetaData) }; // 517357616
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::NewProp_Definition = { "Definition", nullptr, (EPropertyFlags)0x0114000000020015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveRuntimeState, Definition), Z_Construct_UClass_UJMObjectiveDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Definition_MetaData), NewProp_Definition_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveRuntimeState, State), Z_Construct_UEnum_JMObjective_EJMObjectiveState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_State_MetaData), NewProp_State_MetaData) }; // 3203899945
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::NewProp_CurrentCount = { "CurrentCount", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveRuntimeState, CurrentCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentCount_MetaData), NewProp_CurrentCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::NewProp_RequiredCount = { "RequiredCount", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveRuntimeState, RequiredCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequiredCount_MetaData), NewProp_RequiredCount_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::NewProp_ActivationTime = { "ActivationTime", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveRuntimeState, ActivationTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivationTime_MetaData), NewProp_ActivationTime_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::NewProp_CompletionTime = { "CompletionTime", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveRuntimeState, CompletionTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CompletionTime_MetaData), NewProp_CompletionTime_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::NewProp_FailureTime = { "FailureTime", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveRuntimeState, FailureTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FailureTime_MetaData), NewProp_FailureTime_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::NewProp_LastEventTag = { "LastEventTag", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveRuntimeState, LastEventTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastEventTag_MetaData), NewProp_LastEventTag_MetaData) }; // 517357616
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::NewProp_LastTargetIdentifier = { "LastTargetIdentifier", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveRuntimeState, LastTargetIdentifier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastTargetIdentifier_MetaData), NewProp_LastTargetIdentifier_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::NewProp_Definition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::NewProp_State,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::NewProp_CurrentCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::NewProp_RequiredCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::NewProp_ActivationTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::NewProp_CompletionTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::NewProp_FailureTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::NewProp_LastEventTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::NewProp_LastTargetIdentifier,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMObjectiveRuntimeState Property Definitions ***********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMObjective,
	nullptr,
	&NewStructOps,
	"JMObjectiveRuntimeState",
	Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::PropPointers),
	sizeof(FJMObjectiveRuntimeState),
	alignof(FJMObjectiveRuntimeState),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMObjectiveRuntimeState()
{
	if (!Z_Registration_Info_UScriptStruct_FJMObjectiveRuntimeState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMObjectiveRuntimeState.InnerSingleton, Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMObjectiveRuntimeState.InnerSingleton);
}
// ********** End ScriptStruct FJMObjectiveRuntimeState ********************************************

// ********** Begin ScriptStruct FJMObjectiveSaveData **********************************************
struct Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMObjectiveSaveData); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMObjectiveSaveData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectiveId_MetaData[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_State_MetaData[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentCount_MetaData[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivationTime_MetaData[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CompletionTime_MetaData[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FailureTime_MetaData[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Types/JMObjectiveTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMObjectiveSaveData constinit property declarations **************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentCount;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActivationTime;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CompletionTime;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FailureTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMObjectiveSaveData constinit property declarations ****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMObjectiveSaveData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMObjectiveSaveData;
class UScriptStruct* FJMObjectiveSaveData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMObjectiveSaveData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMObjectiveSaveData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMObjectiveSaveData, (UObject*)Z_Construct_UPackage__Script_JMObjective(), TEXT("JMObjectiveSaveData"));
	}
	return Z_Registration_Info_UScriptStruct_FJMObjectiveSaveData.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMObjectiveSaveData Property Definitions *************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveSaveData, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectiveId_MetaData), NewProp_ObjectiveId_MetaData) }; // 517357616
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveSaveData, State), Z_Construct_UEnum_JMObjective_EJMObjectiveState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_State_MetaData), NewProp_State_MetaData) }; // 3203899945
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics::NewProp_CurrentCount = { "CurrentCount", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveSaveData, CurrentCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentCount_MetaData), NewProp_CurrentCount_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics::NewProp_ActivationTime = { "ActivationTime", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveSaveData, ActivationTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivationTime_MetaData), NewProp_ActivationTime_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics::NewProp_CompletionTime = { "CompletionTime", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveSaveData, CompletionTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CompletionTime_MetaData), NewProp_CompletionTime_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics::NewProp_FailureTime = { "FailureTime", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMObjectiveSaveData, FailureTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FailureTime_MetaData), NewProp_FailureTime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics::NewProp_State,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics::NewProp_CurrentCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics::NewProp_ActivationTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics::NewProp_CompletionTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics::NewProp_FailureTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMObjectiveSaveData Property Definitions ***************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMObjective,
	nullptr,
	&NewStructOps,
	"JMObjectiveSaveData",
	Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics::PropPointers),
	sizeof(FJMObjectiveSaveData),
	alignof(FJMObjectiveSaveData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMObjectiveSaveData()
{
	if (!Z_Registration_Info_UScriptStruct_FJMObjectiveSaveData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMObjectiveSaveData.InnerSingleton, Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMObjectiveSaveData.InnerSingleton);
}
// ********** End ScriptStruct FJMObjectiveSaveData ************************************************

// ********** Begin Delegate FJMObjectiveStateChangedSignature *************************************
struct Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature_Statics
{
	struct _Script_JMObjective_eventJMObjectiveStateChangedSignature_Parms
	{
		FGameplayTag ObjectiveId;
		FJMObjectiveRuntimeState RuntimeState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Types/JMObjectiveTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RuntimeState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMObjectiveStateChangedSignature constinit property declarations *****
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RuntimeState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMObjectiveStateChangedSignature constinit property declarations *******
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMObjectiveStateChangedSignature Property Definitions ****************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMObjective_eventJMObjectiveStateChangedSignature_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature_Statics::NewProp_RuntimeState = { "RuntimeState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMObjective_eventJMObjectiveStateChangedSignature_Parms, RuntimeState), Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RuntimeState_MetaData), NewProp_RuntimeState_MetaData) }; // 4088304728
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature_Statics::NewProp_RuntimeState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMObjectiveStateChangedSignature Property Definitions ******************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMObjective, nullptr, "JMObjectiveStateChangedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature_Statics::_Script_JMObjective_eventJMObjectiveStateChangedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature_Statics::_Script_JMObjective_eventJMObjectiveStateChangedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMObjectiveStateChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMObjectiveStateChangedSignature, FGameplayTag ObjectiveId, FJMObjectiveRuntimeState const& RuntimeState)
{
	struct _Script_JMObjective_eventJMObjectiveStateChangedSignature_Parms
	{
		FGameplayTag ObjectiveId;
		FJMObjectiveRuntimeState RuntimeState;
	};
	_Script_JMObjective_eventJMObjectiveStateChangedSignature_Parms Parms;
	Parms.ObjectiveId=ObjectiveId;
	Parms.RuntimeState=RuntimeState;
	JMObjectiveStateChangedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMObjectiveStateChangedSignature ***************************************

// ********** Begin Delegate FJMObjectiveProgressedSignature ***************************************
struct Z_Construct_UDelegateFunction_JMObjective_JMObjectiveProgressedSignature__DelegateSignature_Statics
{
	struct _Script_JMObjective_eventJMObjectiveProgressedSignature_Parms
	{
		FGameplayTag ObjectiveId;
		FJMObjectiveRuntimeState RuntimeState;
		int32 ProgressDelta;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Types/JMObjectiveTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RuntimeState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMObjectiveProgressedSignature constinit property declarations *******
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RuntimeState;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ProgressDelta;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMObjectiveProgressedSignature constinit property declarations *********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMObjectiveProgressedSignature Property Definitions ******************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_JMObjective_JMObjectiveProgressedSignature__DelegateSignature_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMObjective_eventJMObjectiveProgressedSignature_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_JMObjective_JMObjectiveProgressedSignature__DelegateSignature_Statics::NewProp_RuntimeState = { "RuntimeState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMObjective_eventJMObjectiveProgressedSignature_Parms, RuntimeState), Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RuntimeState_MetaData), NewProp_RuntimeState_MetaData) }; // 4088304728
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_JMObjective_JMObjectiveProgressedSignature__DelegateSignature_Statics::NewProp_ProgressDelta = { "ProgressDelta", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMObjective_eventJMObjectiveProgressedSignature_Parms, ProgressDelta), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMObjective_JMObjectiveProgressedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMObjective_JMObjectiveProgressedSignature__DelegateSignature_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMObjective_JMObjectiveProgressedSignature__DelegateSignature_Statics::NewProp_RuntimeState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMObjective_JMObjectiveProgressedSignature__DelegateSignature_Statics::NewProp_ProgressDelta,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMObjective_JMObjectiveProgressedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMObjectiveProgressedSignature Property Definitions ********************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMObjective_JMObjectiveProgressedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMObjective, nullptr, "JMObjectiveProgressedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_JMObjective_JMObjectiveProgressedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMObjective_JMObjectiveProgressedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMObjective_JMObjectiveProgressedSignature__DelegateSignature_Statics::_Script_JMObjective_eventJMObjectiveProgressedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMObjective_JMObjectiveProgressedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMObjective_JMObjectiveProgressedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMObjective_JMObjectiveProgressedSignature__DelegateSignature_Statics::_Script_JMObjective_eventJMObjectiveProgressedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMObjective_JMObjectiveProgressedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMObjective_JMObjectiveProgressedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMObjectiveProgressedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMObjectiveProgressedSignature, FGameplayTag ObjectiveId, FJMObjectiveRuntimeState const& RuntimeState, int32 ProgressDelta)
{
	struct _Script_JMObjective_eventJMObjectiveProgressedSignature_Parms
	{
		FGameplayTag ObjectiveId;
		FJMObjectiveRuntimeState RuntimeState;
		int32 ProgressDelta;
	};
	_Script_JMObjective_eventJMObjectiveProgressedSignature_Parms Parms;
	Parms.ObjectiveId=ObjectiveId;
	Parms.RuntimeState=RuntimeState;
	Parms.ProgressDelta=ProgressDelta;
	JMObjectiveProgressedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMObjectiveProgressedSignature *****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Types_JMObjectiveTypes_h__Script_JMObjective_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EJMObjectiveState_StaticEnum, TEXT("EJMObjectiveState"), &Z_Registration_Info_UEnum_EJMObjectiveState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3203899945U) },
		{ EJMObjectiveProgressIncrementMode_StaticEnum, TEXT("EJMObjectiveProgressIncrementMode"), &Z_Registration_Info_UEnum_EJMObjectiveProgressIncrementMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3082881662U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FJMObjectiveRuntimeState::StaticStruct, Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics::NewStructOps, TEXT("JMObjectiveRuntimeState"),&Z_Registration_Info_UScriptStruct_FJMObjectiveRuntimeState, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMObjectiveRuntimeState), 4088304728U) },
		{ FJMObjectiveSaveData::StaticStruct, Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics::NewStructOps, TEXT("JMObjectiveSaveData"),&Z_Registration_Info_UScriptStruct_FJMObjectiveSaveData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMObjectiveSaveData), 220837192U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Types_JMObjectiveTypes_h__Script_JMObjective_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Types_JMObjectiveTypes_h__Script_JMObjective_2226385297{
	TEXT("/Script/JMObjective"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Types_JMObjectiveTypes_h__Script_JMObjective_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Types_JMObjectiveTypes_h__Script_JMObjective_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Types_JMObjectiveTypes_h__Script_JMObjective_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Types_JMObjectiveTypes_h__Script_JMObjective_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
