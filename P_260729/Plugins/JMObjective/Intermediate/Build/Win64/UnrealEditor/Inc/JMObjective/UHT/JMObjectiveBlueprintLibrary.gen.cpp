// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Blueprint/JMObjectiveBlueprintLibrary.h"
#include "GameplayTagContainer.h"
#include "Types/JMObjectiveFlowTypes.h"
#include "Types/JMObjectiveTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMObjectiveBlueprintLibrary() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveBlueprintLibrary();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveBlueprintLibrary_NoRegister();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveDefinition_NoRegister();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveFlowDefinition_NoRegister();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveFlowSubsystem_NoRegister();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveSubsystem_NoRegister();
JMOBJECTIVE_API UScriptStruct* Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState();
JMOBJECTIVE_API UScriptStruct* Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData();
JMOBJECTIVE_API UScriptStruct* Z_Construct_UScriptStruct_FJMObjectiveRuntimeState();
UPackage* Z_Construct_UPackage__Script_JMObjective();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMObjectiveBlueprintLibrary Function ActivateObjective ******************
struct Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ActivateObjective_Statics
{
	struct JMObjectiveBlueprintLibrary_eventActivateObjective_Parms
	{
		const UObject* WorldContextObject;
		FGameplayTag ObjectiveId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Blueprint/JMObjectiveBlueprintLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ActivateObjective constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ActivateObjective constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ActivateObjective Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ActivateObjective_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventActivateObjective_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ActivateObjective_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventActivateObjective_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ActivateObjective_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveBlueprintLibrary_eventActivateObjective_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ActivateObjective_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveBlueprintLibrary_eventActivateObjective_Parms), &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ActivateObjective_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ActivateObjective_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ActivateObjective_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ActivateObjective_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ActivateObjective_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ActivateObjective_Statics::PropPointers) < 2048);
// ********** End Function ActivateObjective Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ActivateObjective_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveBlueprintLibrary, nullptr, "ActivateObjective", 	Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ActivateObjective_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ActivateObjective_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ActivateObjective_Statics::JMObjectiveBlueprintLibrary_eventActivateObjective_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ActivateObjective_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ActivateObjective_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ActivateObjective_Statics::JMObjectiveBlueprintLibrary_eventActivateObjective_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ActivateObjective()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ActivateObjective_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveBlueprintLibrary::execActivateObjective)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UJMObjectiveBlueprintLibrary::ActivateObjective(Z_Param_WorldContextObject,Z_Param_ObjectiveId);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveBlueprintLibrary Function ActivateObjective ********************

// ********** Begin Class UJMObjectiveBlueprintLibrary Function AddObjectiveProgress ***************
struct Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_AddObjectiveProgress_Statics
{
	struct JMObjectiveBlueprintLibrary_eventAddObjectiveProgress_Parms
	{
		const UObject* WorldContextObject;
		FGameplayTag ObjectiveId;
		int32 Amount;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective" },
		{ "CPP_Default_Amount", "1" },
		{ "ModuleRelativePath", "Public/Blueprint/JMObjectiveBlueprintLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddObjectiveProgress constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Amount;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddObjectiveProgress constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddObjectiveProgress Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_AddObjectiveProgress_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventAddObjectiveProgress_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_AddObjectiveProgress_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventAddObjectiveProgress_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_AddObjectiveProgress_Statics::NewProp_Amount = { "Amount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventAddObjectiveProgress_Parms, Amount), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_AddObjectiveProgress_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveBlueprintLibrary_eventAddObjectiveProgress_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_AddObjectiveProgress_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveBlueprintLibrary_eventAddObjectiveProgress_Parms), &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_AddObjectiveProgress_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_AddObjectiveProgress_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_AddObjectiveProgress_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_AddObjectiveProgress_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_AddObjectiveProgress_Statics::NewProp_Amount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_AddObjectiveProgress_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_AddObjectiveProgress_Statics::PropPointers) < 2048);
// ********** End Function AddObjectiveProgress Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_AddObjectiveProgress_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveBlueprintLibrary, nullptr, "AddObjectiveProgress", 	Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_AddObjectiveProgress_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_AddObjectiveProgress_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_AddObjectiveProgress_Statics::JMObjectiveBlueprintLibrary_eventAddObjectiveProgress_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_AddObjectiveProgress_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_AddObjectiveProgress_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_AddObjectiveProgress_Statics::JMObjectiveBlueprintLibrary_eventAddObjectiveProgress_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_AddObjectiveProgress()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_AddObjectiveProgress_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveBlueprintLibrary::execAddObjectiveProgress)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_GET_PROPERTY(FIntProperty,Z_Param_Amount);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UJMObjectiveBlueprintLibrary::AddObjectiveProgress(Z_Param_WorldContextObject,Z_Param_ObjectiveId,Z_Param_Amount);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveBlueprintLibrary Function AddObjectiveProgress *****************

// ********** Begin Class UJMObjectiveBlueprintLibrary Function CaptureObjectiveFlowStates *********
struct Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CaptureObjectiveFlowStates_Statics
{
	struct JMObjectiveBlueprintLibrary_eventCaptureObjectiveFlowStates_Parms
	{
		const UObject* WorldContextObject;
		TArray<FJMObjectiveFlowSaveData> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective Flow|Save" },
		{ "ModuleRelativePath", "Public/Blueprint/JMObjectiveBlueprintLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CaptureObjectiveFlowStates constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CaptureObjectiveFlowStates constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CaptureObjectiveFlowStates Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CaptureObjectiveFlowStates_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventCaptureObjectiveFlowStates_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CaptureObjectiveFlowStates_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData, METADATA_PARAMS(0, nullptr) }; // 2623431764
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CaptureObjectiveFlowStates_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventCaptureObjectiveFlowStates_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 2623431764
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CaptureObjectiveFlowStates_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CaptureObjectiveFlowStates_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CaptureObjectiveFlowStates_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CaptureObjectiveFlowStates_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CaptureObjectiveFlowStates_Statics::PropPointers) < 2048);
// ********** End Function CaptureObjectiveFlowStates Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CaptureObjectiveFlowStates_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveBlueprintLibrary, nullptr, "CaptureObjectiveFlowStates", 	Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CaptureObjectiveFlowStates_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CaptureObjectiveFlowStates_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CaptureObjectiveFlowStates_Statics::JMObjectiveBlueprintLibrary_eventCaptureObjectiveFlowStates_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CaptureObjectiveFlowStates_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CaptureObjectiveFlowStates_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CaptureObjectiveFlowStates_Statics::JMObjectiveBlueprintLibrary_eventCaptureObjectiveFlowStates_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CaptureObjectiveFlowStates()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CaptureObjectiveFlowStates_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveBlueprintLibrary::execCaptureObjectiveFlowStates)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FJMObjectiveFlowSaveData>*)Z_Param__Result=UJMObjectiveBlueprintLibrary::CaptureObjectiveFlowStates(Z_Param_WorldContextObject);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveBlueprintLibrary Function CaptureObjectiveFlowStates ***********

// ********** Begin Class UJMObjectiveBlueprintLibrary Function CompleteObjective ******************
struct Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CompleteObjective_Statics
{
	struct JMObjectiveBlueprintLibrary_eventCompleteObjective_Parms
	{
		const UObject* WorldContextObject;
		FGameplayTag ObjectiveId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Blueprint/JMObjectiveBlueprintLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CompleteObjective constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CompleteObjective constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CompleteObjective Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CompleteObjective_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventCompleteObjective_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CompleteObjective_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventCompleteObjective_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CompleteObjective_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveBlueprintLibrary_eventCompleteObjective_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CompleteObjective_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveBlueprintLibrary_eventCompleteObjective_Parms), &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CompleteObjective_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CompleteObjective_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CompleteObjective_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CompleteObjective_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CompleteObjective_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CompleteObjective_Statics::PropPointers) < 2048);
// ********** End Function CompleteObjective Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CompleteObjective_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveBlueprintLibrary, nullptr, "CompleteObjective", 	Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CompleteObjective_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CompleteObjective_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CompleteObjective_Statics::JMObjectiveBlueprintLibrary_eventCompleteObjective_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CompleteObjective_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CompleteObjective_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CompleteObjective_Statics::JMObjectiveBlueprintLibrary_eventCompleteObjective_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CompleteObjective()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CompleteObjective_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveBlueprintLibrary::execCompleteObjective)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UJMObjectiveBlueprintLibrary::CompleteObjective(Z_Param_WorldContextObject,Z_Param_ObjectiveId);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveBlueprintLibrary Function CompleteObjective ********************

// ********** Begin Class UJMObjectiveBlueprintLibrary Function FailObjective **********************
struct Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_FailObjective_Statics
{
	struct JMObjectiveBlueprintLibrary_eventFailObjective_Parms
	{
		const UObject* WorldContextObject;
		FGameplayTag ObjectiveId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Blueprint/JMObjectiveBlueprintLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function FailObjective constinit property declarations *************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FailObjective constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FailObjective Property Definitions ************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_FailObjective_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventFailObjective_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_FailObjective_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventFailObjective_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_FailObjective_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveBlueprintLibrary_eventFailObjective_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_FailObjective_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveBlueprintLibrary_eventFailObjective_Parms), &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_FailObjective_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_FailObjective_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_FailObjective_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_FailObjective_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_FailObjective_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_FailObjective_Statics::PropPointers) < 2048);
// ********** End Function FailObjective Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_FailObjective_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveBlueprintLibrary, nullptr, "FailObjective", 	Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_FailObjective_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_FailObjective_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_FailObjective_Statics::JMObjectiveBlueprintLibrary_eventFailObjective_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_FailObjective_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_FailObjective_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_FailObjective_Statics::JMObjectiveBlueprintLibrary_eventFailObjective_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_FailObjective()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_FailObjective_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveBlueprintLibrary::execFailObjective)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UJMObjectiveBlueprintLibrary::FailObjective(Z_Param_WorldContextObject,Z_Param_ObjectiveId);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveBlueprintLibrary Function FailObjective ************************

// ********** Begin Class UJMObjectiveBlueprintLibrary Function GetObjectiveFlowState **************
struct Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowState_Statics
{
	struct JMObjectiveBlueprintLibrary_eventGetObjectiveFlowState_Parms
	{
		const UObject* WorldContextObject;
		FGameplayTag FlowId;
		FJMObjectiveFlowRuntimeState OutState;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Blueprint/JMObjectiveBlueprintLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetObjectiveFlowState constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FlowId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutState;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetObjectiveFlowState constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetObjectiveFlowState Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowState_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventGetObjectiveFlowState_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowState_Statics::NewProp_FlowId = { "FlowId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventGetObjectiveFlowState_Parms, FlowId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowState_Statics::NewProp_OutState = { "OutState", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventGetObjectiveFlowState_Parms, OutState), Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState, METADATA_PARAMS(0, nullptr) }; // 853706147
void Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveBlueprintLibrary_eventGetObjectiveFlowState_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveBlueprintLibrary_eventGetObjectiveFlowState_Parms), &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowState_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowState_Statics::NewProp_FlowId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowState_Statics::NewProp_OutState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowState_Statics::PropPointers) < 2048);
// ********** End Function GetObjectiveFlowState Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveBlueprintLibrary, nullptr, "GetObjectiveFlowState", 	Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowState_Statics::JMObjectiveBlueprintLibrary_eventGetObjectiveFlowState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowState_Statics::JMObjectiveBlueprintLibrary_eventGetObjectiveFlowState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveBlueprintLibrary::execGetObjectiveFlowState)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_STRUCT(FGameplayTag,Z_Param_FlowId);
	P_GET_STRUCT_REF(FJMObjectiveFlowRuntimeState,Z_Param_Out_OutState);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UJMObjectiveBlueprintLibrary::GetObjectiveFlowState(Z_Param_WorldContextObject,Z_Param_FlowId,Z_Param_Out_OutState);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveBlueprintLibrary Function GetObjectiveFlowState ****************

// ********** Begin Class UJMObjectiveBlueprintLibrary Function GetObjectiveFlowSubsystem **********
struct Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowSubsystem_Statics
{
	struct JMObjectiveBlueprintLibrary_eventGetObjectiveFlowSubsystem_Parms
	{
		const UObject* WorldContextObject;
		UJMObjectiveFlowSubsystem* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Blueprint/JMObjectiveBlueprintLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetObjectiveFlowSubsystem constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetObjectiveFlowSubsystem constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetObjectiveFlowSubsystem Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowSubsystem_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventGetObjectiveFlowSubsystem_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowSubsystem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventGetObjectiveFlowSubsystem_Parms, ReturnValue), Z_Construct_UClass_UJMObjectiveFlowSubsystem_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowSubsystem_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowSubsystem_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowSubsystem_Statics::PropPointers) < 2048);
// ********** End Function GetObjectiveFlowSubsystem Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowSubsystem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveBlueprintLibrary, nullptr, "GetObjectiveFlowSubsystem", 	Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowSubsystem_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowSubsystem_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowSubsystem_Statics::JMObjectiveBlueprintLibrary_eventGetObjectiveFlowSubsystem_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowSubsystem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowSubsystem_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowSubsystem_Statics::JMObjectiveBlueprintLibrary_eventGetObjectiveFlowSubsystem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowSubsystem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowSubsystem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveBlueprintLibrary::execGetObjectiveFlowSubsystem)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UJMObjectiveFlowSubsystem**)Z_Param__Result=UJMObjectiveBlueprintLibrary::GetObjectiveFlowSubsystem(Z_Param_WorldContextObject);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveBlueprintLibrary Function GetObjectiveFlowSubsystem ************

// ********** Begin Class UJMObjectiveBlueprintLibrary Function GetObjectiveState ******************
struct Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveState_Statics
{
	struct JMObjectiveBlueprintLibrary_eventGetObjectiveState_Parms
	{
		const UObject* WorldContextObject;
		FGameplayTag ObjectiveId;
		FJMObjectiveRuntimeState OutState;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Blueprint/JMObjectiveBlueprintLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetObjectiveState constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutState;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetObjectiveState constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetObjectiveState Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveState_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventGetObjectiveState_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveState_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventGetObjectiveState_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveState_Statics::NewProp_OutState = { "OutState", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventGetObjectiveState_Parms, OutState), Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, METADATA_PARAMS(0, nullptr) }; // 4088304728
void Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveBlueprintLibrary_eventGetObjectiveState_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveBlueprintLibrary_eventGetObjectiveState_Parms), &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveState_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveState_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveState_Statics::NewProp_OutState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveState_Statics::PropPointers) < 2048);
// ********** End Function GetObjectiveState Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveBlueprintLibrary, nullptr, "GetObjectiveState", 	Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveState_Statics::JMObjectiveBlueprintLibrary_eventGetObjectiveState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveState_Statics::JMObjectiveBlueprintLibrary_eventGetObjectiveState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveBlueprintLibrary::execGetObjectiveState)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_GET_STRUCT_REF(FJMObjectiveRuntimeState,Z_Param_Out_OutState);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UJMObjectiveBlueprintLibrary::GetObjectiveState(Z_Param_WorldContextObject,Z_Param_ObjectiveId,Z_Param_Out_OutState);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveBlueprintLibrary Function GetObjectiveState ********************

// ********** Begin Class UJMObjectiveBlueprintLibrary Function GetObjectiveSubsystem **************
struct Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveSubsystem_Statics
{
	struct JMObjectiveBlueprintLibrary_eventGetObjectiveSubsystem_Parms
	{
		const UObject* WorldContextObject;
		UJMObjectiveSubsystem* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Blueprint/JMObjectiveBlueprintLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetObjectiveSubsystem constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetObjectiveSubsystem constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetObjectiveSubsystem Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveSubsystem_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventGetObjectiveSubsystem_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveSubsystem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventGetObjectiveSubsystem_Parms, ReturnValue), Z_Construct_UClass_UJMObjectiveSubsystem_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveSubsystem_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveSubsystem_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveSubsystem_Statics::PropPointers) < 2048);
// ********** End Function GetObjectiveSubsystem Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveSubsystem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveBlueprintLibrary, nullptr, "GetObjectiveSubsystem", 	Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveSubsystem_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveSubsystem_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveSubsystem_Statics::JMObjectiveBlueprintLibrary_eventGetObjectiveSubsystem_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveSubsystem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveSubsystem_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveSubsystem_Statics::JMObjectiveBlueprintLibrary_eventGetObjectiveSubsystem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveSubsystem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveSubsystem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveBlueprintLibrary::execGetObjectiveSubsystem)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UJMObjectiveSubsystem**)Z_Param__Result=UJMObjectiveBlueprintLibrary::GetObjectiveSubsystem(Z_Param_WorldContextObject);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveBlueprintLibrary Function GetObjectiveSubsystem ****************

// ********** Begin Class UJMObjectiveBlueprintLibrary Function IsObjectiveCompleted ***************
struct Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_IsObjectiveCompleted_Statics
{
	struct JMObjectiveBlueprintLibrary_eventIsObjectiveCompleted_Parms
	{
		const UObject* WorldContextObject;
		FGameplayTag ObjectiveId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Blueprint/JMObjectiveBlueprintLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsObjectiveCompleted constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsObjectiveCompleted constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsObjectiveCompleted Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_IsObjectiveCompleted_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventIsObjectiveCompleted_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_IsObjectiveCompleted_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventIsObjectiveCompleted_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_IsObjectiveCompleted_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveBlueprintLibrary_eventIsObjectiveCompleted_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_IsObjectiveCompleted_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveBlueprintLibrary_eventIsObjectiveCompleted_Parms), &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_IsObjectiveCompleted_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_IsObjectiveCompleted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_IsObjectiveCompleted_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_IsObjectiveCompleted_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_IsObjectiveCompleted_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_IsObjectiveCompleted_Statics::PropPointers) < 2048);
// ********** End Function IsObjectiveCompleted Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_IsObjectiveCompleted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveBlueprintLibrary, nullptr, "IsObjectiveCompleted", 	Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_IsObjectiveCompleted_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_IsObjectiveCompleted_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_IsObjectiveCompleted_Statics::JMObjectiveBlueprintLibrary_eventIsObjectiveCompleted_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_IsObjectiveCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_IsObjectiveCompleted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_IsObjectiveCompleted_Statics::JMObjectiveBlueprintLibrary_eventIsObjectiveCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_IsObjectiveCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_IsObjectiveCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveBlueprintLibrary::execIsObjectiveCompleted)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UJMObjectiveBlueprintLibrary::IsObjectiveCompleted(Z_Param_WorldContextObject,Z_Param_ObjectiveId);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveBlueprintLibrary Function IsObjectiveCompleted *****************

// ********** Begin Class UJMObjectiveBlueprintLibrary Function RegisterObjective ******************
struct Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RegisterObjective_Statics
{
	struct JMObjectiveBlueprintLibrary_eventRegisterObjective_Parms
	{
		const UObject* WorldContextObject;
		UJMObjectiveDefinition* Definition;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Blueprint/JMObjectiveBlueprintLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RegisterObjective constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Definition;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RegisterObjective constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RegisterObjective Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RegisterObjective_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventRegisterObjective_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RegisterObjective_Statics::NewProp_Definition = { "Definition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventRegisterObjective_Parms, Definition), Z_Construct_UClass_UJMObjectiveDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RegisterObjective_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveBlueprintLibrary_eventRegisterObjective_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RegisterObjective_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveBlueprintLibrary_eventRegisterObjective_Parms), &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RegisterObjective_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RegisterObjective_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RegisterObjective_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RegisterObjective_Statics::NewProp_Definition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RegisterObjective_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RegisterObjective_Statics::PropPointers) < 2048);
// ********** End Function RegisterObjective Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RegisterObjective_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveBlueprintLibrary, nullptr, "RegisterObjective", 	Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RegisterObjective_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RegisterObjective_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RegisterObjective_Statics::JMObjectiveBlueprintLibrary_eventRegisterObjective_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RegisterObjective_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RegisterObjective_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RegisterObjective_Statics::JMObjectiveBlueprintLibrary_eventRegisterObjective_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RegisterObjective()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RegisterObjective_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveBlueprintLibrary::execRegisterObjective)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(UJMObjectiveDefinition,Z_Param_Definition);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UJMObjectiveBlueprintLibrary::RegisterObjective(Z_Param_WorldContextObject,Z_Param_Definition);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveBlueprintLibrary Function RegisterObjective ********************

// ********** Begin Class UJMObjectiveBlueprintLibrary Function ResetObjective *********************
struct Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjective_Statics
{
	struct JMObjectiveBlueprintLibrary_eventResetObjective_Parms
	{
		const UObject* WorldContextObject;
		FGameplayTag ObjectiveId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Blueprint/JMObjectiveBlueprintLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResetObjective constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ResetObjective constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ResetObjective Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjective_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventResetObjective_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjective_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventResetObjective_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjective_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveBlueprintLibrary_eventResetObjective_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjective_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveBlueprintLibrary_eventResetObjective_Parms), &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjective_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjective_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjective_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjective_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjective_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjective_Statics::PropPointers) < 2048);
// ********** End Function ResetObjective Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjective_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveBlueprintLibrary, nullptr, "ResetObjective", 	Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjective_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjective_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjective_Statics::JMObjectiveBlueprintLibrary_eventResetObjective_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjective_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjective_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjective_Statics::JMObjectiveBlueprintLibrary_eventResetObjective_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjective()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjective_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveBlueprintLibrary::execResetObjective)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UJMObjectiveBlueprintLibrary::ResetObjective(Z_Param_WorldContextObject,Z_Param_ObjectiveId);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveBlueprintLibrary Function ResetObjective ***********************

// ********** Begin Class UJMObjectiveBlueprintLibrary Function ResetObjectiveFlow *****************
struct Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjectiveFlow_Statics
{
	struct JMObjectiveBlueprintLibrary_eventResetObjectiveFlow_Parms
	{
		const UObject* WorldContextObject;
		FGameplayTag FlowId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Blueprint/JMObjectiveBlueprintLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResetObjectiveFlow constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FlowId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ResetObjectiveFlow constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ResetObjectiveFlow Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjectiveFlow_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventResetObjectiveFlow_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjectiveFlow_Statics::NewProp_FlowId = { "FlowId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventResetObjectiveFlow_Parms, FlowId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjectiveFlow_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveBlueprintLibrary_eventResetObjectiveFlow_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjectiveFlow_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveBlueprintLibrary_eventResetObjectiveFlow_Parms), &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjectiveFlow_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjectiveFlow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjectiveFlow_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjectiveFlow_Statics::NewProp_FlowId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjectiveFlow_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjectiveFlow_Statics::PropPointers) < 2048);
// ********** End Function ResetObjectiveFlow Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjectiveFlow_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveBlueprintLibrary, nullptr, "ResetObjectiveFlow", 	Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjectiveFlow_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjectiveFlow_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjectiveFlow_Statics::JMObjectiveBlueprintLibrary_eventResetObjectiveFlow_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjectiveFlow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjectiveFlow_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjectiveFlow_Statics::JMObjectiveBlueprintLibrary_eventResetObjectiveFlow_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjectiveFlow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjectiveFlow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveBlueprintLibrary::execResetObjectiveFlow)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_STRUCT(FGameplayTag,Z_Param_FlowId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UJMObjectiveBlueprintLibrary::ResetObjectiveFlow(Z_Param_WorldContextObject,Z_Param_FlowId);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveBlueprintLibrary Function ResetObjectiveFlow *******************

// ********** Begin Class UJMObjectiveBlueprintLibrary Function RestartObjectiveFlow ***************
struct Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestartObjectiveFlow_Statics
{
	struct JMObjectiveBlueprintLibrary_eventRestartObjectiveFlow_Parms
	{
		const UObject* WorldContextObject;
		FGameplayTag FlowId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Blueprint/JMObjectiveBlueprintLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RestartObjectiveFlow constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FlowId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RestartObjectiveFlow constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RestartObjectiveFlow Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestartObjectiveFlow_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventRestartObjectiveFlow_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestartObjectiveFlow_Statics::NewProp_FlowId = { "FlowId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventRestartObjectiveFlow_Parms, FlowId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestartObjectiveFlow_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveBlueprintLibrary_eventRestartObjectiveFlow_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestartObjectiveFlow_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveBlueprintLibrary_eventRestartObjectiveFlow_Parms), &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestartObjectiveFlow_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestartObjectiveFlow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestartObjectiveFlow_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestartObjectiveFlow_Statics::NewProp_FlowId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestartObjectiveFlow_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestartObjectiveFlow_Statics::PropPointers) < 2048);
// ********** End Function RestartObjectiveFlow Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestartObjectiveFlow_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveBlueprintLibrary, nullptr, "RestartObjectiveFlow", 	Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestartObjectiveFlow_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestartObjectiveFlow_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestartObjectiveFlow_Statics::JMObjectiveBlueprintLibrary_eventRestartObjectiveFlow_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestartObjectiveFlow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestartObjectiveFlow_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestartObjectiveFlow_Statics::JMObjectiveBlueprintLibrary_eventRestartObjectiveFlow_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestartObjectiveFlow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestartObjectiveFlow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveBlueprintLibrary::execRestartObjectiveFlow)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_STRUCT(FGameplayTag,Z_Param_FlowId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UJMObjectiveBlueprintLibrary::RestartObjectiveFlow(Z_Param_WorldContextObject,Z_Param_FlowId);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveBlueprintLibrary Function RestartObjectiveFlow *****************

// ********** Begin Class UJMObjectiveBlueprintLibrary Function RestoreObjectiveFlowStates *********
struct Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestoreObjectiveFlowStates_Statics
{
	struct JMObjectiveBlueprintLibrary_eventRestoreObjectiveFlowStates_Parms
	{
		const UObject* WorldContextObject;
		TArray<FJMObjectiveFlowSaveData> SavedStates;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective Flow|Save" },
		{ "ModuleRelativePath", "Public/Blueprint/JMObjectiveBlueprintLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedStates_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RestoreObjectiveFlowStates constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SavedStates_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SavedStates;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RestoreObjectiveFlowStates constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RestoreObjectiveFlowStates Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestoreObjectiveFlowStates_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventRestoreObjectiveFlowStates_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestoreObjectiveFlowStates_Statics::NewProp_SavedStates_Inner = { "SavedStates", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData, METADATA_PARAMS(0, nullptr) }; // 2623431764
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestoreObjectiveFlowStates_Statics::NewProp_SavedStates = { "SavedStates", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventRestoreObjectiveFlowStates_Parms, SavedStates), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedStates_MetaData), NewProp_SavedStates_MetaData) }; // 2623431764
void Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestoreObjectiveFlowStates_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveBlueprintLibrary_eventRestoreObjectiveFlowStates_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestoreObjectiveFlowStates_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveBlueprintLibrary_eventRestoreObjectiveFlowStates_Parms), &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestoreObjectiveFlowStates_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestoreObjectiveFlowStates_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestoreObjectiveFlowStates_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestoreObjectiveFlowStates_Statics::NewProp_SavedStates_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestoreObjectiveFlowStates_Statics::NewProp_SavedStates,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestoreObjectiveFlowStates_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestoreObjectiveFlowStates_Statics::PropPointers) < 2048);
// ********** End Function RestoreObjectiveFlowStates Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestoreObjectiveFlowStates_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveBlueprintLibrary, nullptr, "RestoreObjectiveFlowStates", 	Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestoreObjectiveFlowStates_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestoreObjectiveFlowStates_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestoreObjectiveFlowStates_Statics::JMObjectiveBlueprintLibrary_eventRestoreObjectiveFlowStates_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestoreObjectiveFlowStates_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestoreObjectiveFlowStates_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestoreObjectiveFlowStates_Statics::JMObjectiveBlueprintLibrary_eventRestoreObjectiveFlowStates_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestoreObjectiveFlowStates()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestoreObjectiveFlowStates_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveBlueprintLibrary::execRestoreObjectiveFlowStates)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_TARRAY_REF(FJMObjectiveFlowSaveData,Z_Param_Out_SavedStates);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UJMObjectiveBlueprintLibrary::RestoreObjectiveFlowStates(Z_Param_WorldContextObject,Z_Param_Out_SavedStates);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveBlueprintLibrary Function RestoreObjectiveFlowStates ***********

// ********** Begin Class UJMObjectiveBlueprintLibrary Function StartObjectiveFlow *****************
struct Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StartObjectiveFlow_Statics
{
	struct JMObjectiveBlueprintLibrary_eventStartObjectiveFlow_Parms
	{
		const UObject* WorldContextObject;
		UJMObjectiveFlowDefinition* FlowDefinition;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective Flow" },
		{ "DisplayName", "Start Objective Flow" },
		{ "ModuleRelativePath", "Public/Blueprint/JMObjectiveBlueprintLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function StartObjectiveFlow constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FlowDefinition;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function StartObjectiveFlow constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function StartObjectiveFlow Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StartObjectiveFlow_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventStartObjectiveFlow_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StartObjectiveFlow_Statics::NewProp_FlowDefinition = { "FlowDefinition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventStartObjectiveFlow_Parms, FlowDefinition), Z_Construct_UClass_UJMObjectiveFlowDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StartObjectiveFlow_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveBlueprintLibrary_eventStartObjectiveFlow_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StartObjectiveFlow_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveBlueprintLibrary_eventStartObjectiveFlow_Parms), &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StartObjectiveFlow_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StartObjectiveFlow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StartObjectiveFlow_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StartObjectiveFlow_Statics::NewProp_FlowDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StartObjectiveFlow_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StartObjectiveFlow_Statics::PropPointers) < 2048);
// ********** End Function StartObjectiveFlow Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StartObjectiveFlow_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveBlueprintLibrary, nullptr, "StartObjectiveFlow", 	Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StartObjectiveFlow_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StartObjectiveFlow_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StartObjectiveFlow_Statics::JMObjectiveBlueprintLibrary_eventStartObjectiveFlow_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StartObjectiveFlow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StartObjectiveFlow_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StartObjectiveFlow_Statics::JMObjectiveBlueprintLibrary_eventStartObjectiveFlow_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StartObjectiveFlow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StartObjectiveFlow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveBlueprintLibrary::execStartObjectiveFlow)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(UJMObjectiveFlowDefinition,Z_Param_FlowDefinition);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UJMObjectiveBlueprintLibrary::StartObjectiveFlow(Z_Param_WorldContextObject,Z_Param_FlowDefinition);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveBlueprintLibrary Function StartObjectiveFlow *******************

// ********** Begin Class UJMObjectiveBlueprintLibrary Function StopObjectiveFlow ******************
struct Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StopObjectiveFlow_Statics
{
	struct JMObjectiveBlueprintLibrary_eventStopObjectiveFlow_Parms
	{
		const UObject* WorldContextObject;
		FGameplayTag FlowId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Blueprint/JMObjectiveBlueprintLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function StopObjectiveFlow constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FlowId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function StopObjectiveFlow constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function StopObjectiveFlow Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StopObjectiveFlow_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventStopObjectiveFlow_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StopObjectiveFlow_Statics::NewProp_FlowId = { "FlowId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveBlueprintLibrary_eventStopObjectiveFlow_Parms, FlowId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StopObjectiveFlow_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveBlueprintLibrary_eventStopObjectiveFlow_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StopObjectiveFlow_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveBlueprintLibrary_eventStopObjectiveFlow_Parms), &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StopObjectiveFlow_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StopObjectiveFlow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StopObjectiveFlow_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StopObjectiveFlow_Statics::NewProp_FlowId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StopObjectiveFlow_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StopObjectiveFlow_Statics::PropPointers) < 2048);
// ********** End Function StopObjectiveFlow Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StopObjectiveFlow_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveBlueprintLibrary, nullptr, "StopObjectiveFlow", 	Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StopObjectiveFlow_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StopObjectiveFlow_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StopObjectiveFlow_Statics::JMObjectiveBlueprintLibrary_eventStopObjectiveFlow_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StopObjectiveFlow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StopObjectiveFlow_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StopObjectiveFlow_Statics::JMObjectiveBlueprintLibrary_eventStopObjectiveFlow_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StopObjectiveFlow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StopObjectiveFlow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveBlueprintLibrary::execStopObjectiveFlow)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_STRUCT(FGameplayTag,Z_Param_FlowId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UJMObjectiveBlueprintLibrary::StopObjectiveFlow(Z_Param_WorldContextObject,Z_Param_FlowId);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveBlueprintLibrary Function StopObjectiveFlow ********************

// ********** Begin Class UJMObjectiveBlueprintLibrary *********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMObjectiveBlueprintLibrary;
UClass* UJMObjectiveBlueprintLibrary::GetPrivateStaticClass()
{
	using TClass = UJMObjectiveBlueprintLibrary;
	if (!Z_Registration_Info_UClass_UJMObjectiveBlueprintLibrary.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMObjectiveBlueprintLibrary"),
			Z_Registration_Info_UClass_UJMObjectiveBlueprintLibrary.InnerSingleton,
			StaticRegisterNativesUJMObjectiveBlueprintLibrary,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UJMObjectiveBlueprintLibrary.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMObjectiveBlueprintLibrary_NoRegister()
{
	return UJMObjectiveBlueprintLibrary::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMObjectiveBlueprintLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Blueprint/JMObjectiveBlueprintLibrary.h" },
		{ "ModuleRelativePath", "Public/Blueprint/JMObjectiveBlueprintLibrary.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMObjectiveBlueprintLibrary constinit property declarations *************
// ********** End Class UJMObjectiveBlueprintLibrary constinit property declarations ***************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ActivateObjective"), .Pointer = &UJMObjectiveBlueprintLibrary::execActivateObjective },
		{ .NameUTF8 = UTF8TEXT("AddObjectiveProgress"), .Pointer = &UJMObjectiveBlueprintLibrary::execAddObjectiveProgress },
		{ .NameUTF8 = UTF8TEXT("CaptureObjectiveFlowStates"), .Pointer = &UJMObjectiveBlueprintLibrary::execCaptureObjectiveFlowStates },
		{ .NameUTF8 = UTF8TEXT("CompleteObjective"), .Pointer = &UJMObjectiveBlueprintLibrary::execCompleteObjective },
		{ .NameUTF8 = UTF8TEXT("FailObjective"), .Pointer = &UJMObjectiveBlueprintLibrary::execFailObjective },
		{ .NameUTF8 = UTF8TEXT("GetObjectiveFlowState"), .Pointer = &UJMObjectiveBlueprintLibrary::execGetObjectiveFlowState },
		{ .NameUTF8 = UTF8TEXT("GetObjectiveFlowSubsystem"), .Pointer = &UJMObjectiveBlueprintLibrary::execGetObjectiveFlowSubsystem },
		{ .NameUTF8 = UTF8TEXT("GetObjectiveState"), .Pointer = &UJMObjectiveBlueprintLibrary::execGetObjectiveState },
		{ .NameUTF8 = UTF8TEXT("GetObjectiveSubsystem"), .Pointer = &UJMObjectiveBlueprintLibrary::execGetObjectiveSubsystem },
		{ .NameUTF8 = UTF8TEXT("IsObjectiveCompleted"), .Pointer = &UJMObjectiveBlueprintLibrary::execIsObjectiveCompleted },
		{ .NameUTF8 = UTF8TEXT("RegisterObjective"), .Pointer = &UJMObjectiveBlueprintLibrary::execRegisterObjective },
		{ .NameUTF8 = UTF8TEXT("ResetObjective"), .Pointer = &UJMObjectiveBlueprintLibrary::execResetObjective },
		{ .NameUTF8 = UTF8TEXT("ResetObjectiveFlow"), .Pointer = &UJMObjectiveBlueprintLibrary::execResetObjectiveFlow },
		{ .NameUTF8 = UTF8TEXT("RestartObjectiveFlow"), .Pointer = &UJMObjectiveBlueprintLibrary::execRestartObjectiveFlow },
		{ .NameUTF8 = UTF8TEXT("RestoreObjectiveFlowStates"), .Pointer = &UJMObjectiveBlueprintLibrary::execRestoreObjectiveFlowStates },
		{ .NameUTF8 = UTF8TEXT("StartObjectiveFlow"), .Pointer = &UJMObjectiveBlueprintLibrary::execStartObjectiveFlow },
		{ .NameUTF8 = UTF8TEXT("StopObjectiveFlow"), .Pointer = &UJMObjectiveBlueprintLibrary::execStopObjectiveFlow },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ActivateObjective, "ActivateObjective" }, // 3532695998
		{ &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_AddObjectiveProgress, "AddObjectiveProgress" }, // 116028755
		{ &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CaptureObjectiveFlowStates, "CaptureObjectiveFlowStates" }, // 923216328
		{ &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_CompleteObjective, "CompleteObjective" }, // 1986366576
		{ &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_FailObjective, "FailObjective" }, // 625132239
		{ &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowState, "GetObjectiveFlowState" }, // 2343200525
		{ &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveFlowSubsystem, "GetObjectiveFlowSubsystem" }, // 299118706
		{ &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveState, "GetObjectiveState" }, // 28189325
		{ &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_GetObjectiveSubsystem, "GetObjectiveSubsystem" }, // 2490127003
		{ &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_IsObjectiveCompleted, "IsObjectiveCompleted" }, // 826209316
		{ &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RegisterObjective, "RegisterObjective" }, // 1996353361
		{ &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjective, "ResetObjective" }, // 2459302181
		{ &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_ResetObjectiveFlow, "ResetObjectiveFlow" }, // 1086066335
		{ &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestartObjectiveFlow, "RestartObjectiveFlow" }, // 175764191
		{ &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_RestoreObjectiveFlowStates, "RestoreObjectiveFlowStates" }, // 380240736
		{ &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StartObjectiveFlow, "StartObjectiveFlow" }, // 3328766830
		{ &Z_Construct_UFunction_UJMObjectiveBlueprintLibrary_StopObjectiveFlow, "StopObjectiveFlow" }, // 3529089313
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMObjectiveBlueprintLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMObjectiveBlueprintLibrary_Statics
UObject* (*const Z_Construct_UClass_UJMObjectiveBlueprintLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_JMObjective,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveBlueprintLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMObjectiveBlueprintLibrary_Statics::ClassParams = {
	&UJMObjectiveBlueprintLibrary::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveBlueprintLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMObjectiveBlueprintLibrary_Statics::Class_MetaDataParams)
};
void UJMObjectiveBlueprintLibrary::StaticRegisterNativesUJMObjectiveBlueprintLibrary()
{
	UClass* Class = UJMObjectiveBlueprintLibrary::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMObjectiveBlueprintLibrary_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMObjectiveBlueprintLibrary()
{
	if (!Z_Registration_Info_UClass_UJMObjectiveBlueprintLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMObjectiveBlueprintLibrary.OuterSingleton, Z_Construct_UClass_UJMObjectiveBlueprintLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMObjectiveBlueprintLibrary.OuterSingleton;
}
UJMObjectiveBlueprintLibrary::UJMObjectiveBlueprintLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMObjectiveBlueprintLibrary);
UJMObjectiveBlueprintLibrary::~UJMObjectiveBlueprintLibrary() {}
// ********** End Class UJMObjectiveBlueprintLibrary ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Blueprint_JMObjectiveBlueprintLibrary_h__Script_JMObjective_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMObjectiveBlueprintLibrary, UJMObjectiveBlueprintLibrary::StaticClass, TEXT("UJMObjectiveBlueprintLibrary"), &Z_Registration_Info_UClass_UJMObjectiveBlueprintLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMObjectiveBlueprintLibrary), 1035929405U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Blueprint_JMObjectiveBlueprintLibrary_h__Script_JMObjective_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Blueprint_JMObjectiveBlueprintLibrary_h__Script_JMObjective_588173959{
	TEXT("/Script/JMObjective"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Blueprint_JMObjectiveBlueprintLibrary_h__Script_JMObjective_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Blueprint_JMObjectiveBlueprintLibrary_h__Script_JMObjective_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
