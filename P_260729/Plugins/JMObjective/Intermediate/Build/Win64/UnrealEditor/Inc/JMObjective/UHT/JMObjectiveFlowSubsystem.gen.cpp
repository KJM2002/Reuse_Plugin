// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Subsystems/JMObjectiveFlowSubsystem.h"
#include "Engine/GameInstance.h"
#include "GameplayTagContainer.h"
#include "Types/JMObjectiveFlowTypes.h"
#include "Types/JMObjectiveTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMObjectiveFlowSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventSubsystem_NoRegister();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveFlowDefinition_NoRegister();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveFlowSubsystem();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveFlowSubsystem_NoRegister();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveSubsystem_NoRegister();
JMOBJECTIVE_API UFunction* Z_Construct_UDelegateFunction_JMObjective_JMObjectiveFlowStateChangedSignature__DelegateSignature();
JMOBJECTIVE_API UScriptStruct* Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState();
JMOBJECTIVE_API UScriptStruct* Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData();
JMOBJECTIVE_API UScriptStruct* Z_Construct_UScriptStruct_FJMObjectiveRuntimeState();
UPackage* Z_Construct_UPackage__Script_JMObjective();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMObjectiveFlowSubsystem Function CaptureObjectiveFlowStates ************
struct Z_Construct_UFunction_UJMObjectiveFlowSubsystem_CaptureObjectiveFlowStates_Statics
{
	struct JMObjectiveFlowSubsystem_eventCaptureObjectiveFlowStates_Parms
	{
		TArray<FJMObjectiveFlowSaveData> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective Flow|Save" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveFlowSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CaptureObjectiveFlowStates constinit property declarations ************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CaptureObjectiveFlowStates constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CaptureObjectiveFlowStates Property Definitions ***********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_CaptureObjectiveFlowStates_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData, METADATA_PARAMS(0, nullptr) }; // 2623431764
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_CaptureObjectiveFlowStates_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveFlowSubsystem_eventCaptureObjectiveFlowStates_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 2623431764
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveFlowSubsystem_CaptureObjectiveFlowStates_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_CaptureObjectiveFlowStates_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_CaptureObjectiveFlowStates_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_CaptureObjectiveFlowStates_Statics::PropPointers) < 2048);
// ********** End Function CaptureObjectiveFlowStates Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_CaptureObjectiveFlowStates_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveFlowSubsystem, nullptr, "CaptureObjectiveFlowStates", 	Z_Construct_UFunction_UJMObjectiveFlowSubsystem_CaptureObjectiveFlowStates_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_CaptureObjectiveFlowStates_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_CaptureObjectiveFlowStates_Statics::JMObjectiveFlowSubsystem_eventCaptureObjectiveFlowStates_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_CaptureObjectiveFlowStates_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveFlowSubsystem_CaptureObjectiveFlowStates_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_CaptureObjectiveFlowStates_Statics::JMObjectiveFlowSubsystem_eventCaptureObjectiveFlowStates_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveFlowSubsystem_CaptureObjectiveFlowStates()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveFlowSubsystem_CaptureObjectiveFlowStates_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveFlowSubsystem::execCaptureObjectiveFlowStates)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FJMObjectiveFlowSaveData>*)Z_Param__Result=P_THIS->CaptureObjectiveFlowStates();
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveFlowSubsystem Function CaptureObjectiveFlowStates **************

// ********** Begin Class UJMObjectiveFlowSubsystem Function GetActiveObjectiveFlows ***************
struct Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetActiveObjectiveFlows_Statics
{
	struct JMObjectiveFlowSubsystem_eventGetActiveObjectiveFlows_Parms
	{
		TArray<FJMObjectiveFlowRuntimeState> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveFlowSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetActiveObjectiveFlows constinit property declarations ***************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetActiveObjectiveFlows constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetActiveObjectiveFlows Property Definitions **************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetActiveObjectiveFlows_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState, METADATA_PARAMS(0, nullptr) }; // 853706147
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetActiveObjectiveFlows_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveFlowSubsystem_eventGetActiveObjectiveFlows_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 853706147
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetActiveObjectiveFlows_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetActiveObjectiveFlows_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetActiveObjectiveFlows_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetActiveObjectiveFlows_Statics::PropPointers) < 2048);
// ********** End Function GetActiveObjectiveFlows Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetActiveObjectiveFlows_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveFlowSubsystem, nullptr, "GetActiveObjectiveFlows", 	Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetActiveObjectiveFlows_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetActiveObjectiveFlows_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetActiveObjectiveFlows_Statics::JMObjectiveFlowSubsystem_eventGetActiveObjectiveFlows_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetActiveObjectiveFlows_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetActiveObjectiveFlows_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetActiveObjectiveFlows_Statics::JMObjectiveFlowSubsystem_eventGetActiveObjectiveFlows_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetActiveObjectiveFlows()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetActiveObjectiveFlows_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveFlowSubsystem::execGetActiveObjectiveFlows)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FJMObjectiveFlowRuntimeState>*)Z_Param__Result=P_THIS->GetActiveObjectiveFlows();
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveFlowSubsystem Function GetActiveObjectiveFlows *****************

// ********** Begin Class UJMObjectiveFlowSubsystem Function GetObjectiveFlowState *****************
struct Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetObjectiveFlowState_Statics
{
	struct JMObjectiveFlowSubsystem_eventGetObjectiveFlowState_Parms
	{
		FGameplayTag FlowId;
		FJMObjectiveFlowRuntimeState OutState;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveFlowSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetObjectiveFlowState constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_FlowId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutState;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetObjectiveFlowState constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetObjectiveFlowState Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetObjectiveFlowState_Statics::NewProp_FlowId = { "FlowId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveFlowSubsystem_eventGetObjectiveFlowState_Parms, FlowId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetObjectiveFlowState_Statics::NewProp_OutState = { "OutState", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveFlowSubsystem_eventGetObjectiveFlowState_Parms, OutState), Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState, METADATA_PARAMS(0, nullptr) }; // 853706147
void Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetObjectiveFlowState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveFlowSubsystem_eventGetObjectiveFlowState_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetObjectiveFlowState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveFlowSubsystem_eventGetObjectiveFlowState_Parms), &Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetObjectiveFlowState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetObjectiveFlowState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetObjectiveFlowState_Statics::NewProp_FlowId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetObjectiveFlowState_Statics::NewProp_OutState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetObjectiveFlowState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetObjectiveFlowState_Statics::PropPointers) < 2048);
// ********** End Function GetObjectiveFlowState Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetObjectiveFlowState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveFlowSubsystem, nullptr, "GetObjectiveFlowState", 	Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetObjectiveFlowState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetObjectiveFlowState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetObjectiveFlowState_Statics::JMObjectiveFlowSubsystem_eventGetObjectiveFlowState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetObjectiveFlowState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetObjectiveFlowState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetObjectiveFlowState_Statics::JMObjectiveFlowSubsystem_eventGetObjectiveFlowState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetObjectiveFlowState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetObjectiveFlowState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveFlowSubsystem::execGetObjectiveFlowState)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_FlowId);
	P_GET_STRUCT_REF(FJMObjectiveFlowRuntimeState,Z_Param_Out_OutState);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetObjectiveFlowState(Z_Param_FlowId,Z_Param_Out_OutState);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveFlowSubsystem Function GetObjectiveFlowState *******************

// ********** Begin Class UJMObjectiveFlowSubsystem Function HandleObjectiveCompleted **************
struct Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveCompleted_Statics
{
	struct JMObjectiveFlowSubsystem_eventHandleObjectiveCompleted_Parms
	{
		FGameplayTag ObjectiveId;
		FJMObjectiveRuntimeState RuntimeState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveFlowSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RuntimeState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleObjectiveCompleted constinit property declarations **************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RuntimeState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleObjectiveCompleted constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleObjectiveCompleted Property Definitions *************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveCompleted_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveFlowSubsystem_eventHandleObjectiveCompleted_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveCompleted_Statics::NewProp_RuntimeState = { "RuntimeState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveFlowSubsystem_eventHandleObjectiveCompleted_Parms, RuntimeState), Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RuntimeState_MetaData), NewProp_RuntimeState_MetaData) }; // 4088304728
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveCompleted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveCompleted_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveCompleted_Statics::NewProp_RuntimeState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveCompleted_Statics::PropPointers) < 2048);
// ********** End Function HandleObjectiveCompleted Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveCompleted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveFlowSubsystem, nullptr, "HandleObjectiveCompleted", 	Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveCompleted_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveCompleted_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveCompleted_Statics::JMObjectiveFlowSubsystem_eventHandleObjectiveCompleted_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveCompleted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveCompleted_Statics::JMObjectiveFlowSubsystem_eventHandleObjectiveCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveFlowSubsystem::execHandleObjectiveCompleted)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_GET_STRUCT_REF(FJMObjectiveRuntimeState,Z_Param_Out_RuntimeState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleObjectiveCompleted(Z_Param_ObjectiveId,Z_Param_Out_RuntimeState);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveFlowSubsystem Function HandleObjectiveCompleted ****************

// ********** Begin Class UJMObjectiveFlowSubsystem Function HandleObjectiveFailed *****************
struct Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveFailed_Statics
{
	struct JMObjectiveFlowSubsystem_eventHandleObjectiveFailed_Parms
	{
		FGameplayTag ObjectiveId;
		FJMObjectiveRuntimeState RuntimeState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveFlowSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RuntimeState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleObjectiveFailed constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RuntimeState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleObjectiveFailed constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleObjectiveFailed Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveFailed_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveFlowSubsystem_eventHandleObjectiveFailed_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveFailed_Statics::NewProp_RuntimeState = { "RuntimeState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveFlowSubsystem_eventHandleObjectiveFailed_Parms, RuntimeState), Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RuntimeState_MetaData), NewProp_RuntimeState_MetaData) }; // 4088304728
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveFailed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveFailed_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveFailed_Statics::NewProp_RuntimeState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveFailed_Statics::PropPointers) < 2048);
// ********** End Function HandleObjectiveFailed Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveFailed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveFlowSubsystem, nullptr, "HandleObjectiveFailed", 	Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveFailed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveFailed_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveFailed_Statics::JMObjectiveFlowSubsystem_eventHandleObjectiveFailed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveFailed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveFailed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveFailed_Statics::JMObjectiveFlowSubsystem_eventHandleObjectiveFailed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveFailed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveFailed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveFlowSubsystem::execHandleObjectiveFailed)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_GET_STRUCT_REF(FJMObjectiveRuntimeState,Z_Param_Out_RuntimeState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleObjectiveFailed(Z_Param_ObjectiveId,Z_Param_Out_RuntimeState);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveFlowSubsystem Function HandleObjectiveFailed *******************

// ********** Begin Class UJMObjectiveFlowSubsystem Function IsObjectiveFlowActive *****************
struct Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowActive_Statics
{
	struct JMObjectiveFlowSubsystem_eventIsObjectiveFlowActive_Parms
	{
		FGameplayTag FlowId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveFlowSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsObjectiveFlowActive constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_FlowId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsObjectiveFlowActive constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsObjectiveFlowActive Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowActive_Statics::NewProp_FlowId = { "FlowId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveFlowSubsystem_eventIsObjectiveFlowActive_Parms, FlowId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowActive_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveFlowSubsystem_eventIsObjectiveFlowActive_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowActive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveFlowSubsystem_eventIsObjectiveFlowActive_Parms), &Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowActive_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowActive_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowActive_Statics::NewProp_FlowId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowActive_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowActive_Statics::PropPointers) < 2048);
// ********** End Function IsObjectiveFlowActive Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowActive_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveFlowSubsystem, nullptr, "IsObjectiveFlowActive", 	Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowActive_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowActive_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowActive_Statics::JMObjectiveFlowSubsystem_eventIsObjectiveFlowActive_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowActive_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowActive_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowActive_Statics::JMObjectiveFlowSubsystem_eventIsObjectiveFlowActive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowActive()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowActive_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveFlowSubsystem::execIsObjectiveFlowActive)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_FlowId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsObjectiveFlowActive(Z_Param_FlowId);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveFlowSubsystem Function IsObjectiveFlowActive *******************

// ********** Begin Class UJMObjectiveFlowSubsystem Function IsObjectiveFlowCompleted **************
struct Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowCompleted_Statics
{
	struct JMObjectiveFlowSubsystem_eventIsObjectiveFlowCompleted_Parms
	{
		FGameplayTag FlowId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveFlowSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsObjectiveFlowCompleted constinit property declarations **************
	static const UECodeGen_Private::FStructPropertyParams NewProp_FlowId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsObjectiveFlowCompleted constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsObjectiveFlowCompleted Property Definitions *************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowCompleted_Statics::NewProp_FlowId = { "FlowId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveFlowSubsystem_eventIsObjectiveFlowCompleted_Parms, FlowId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowCompleted_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveFlowSubsystem_eventIsObjectiveFlowCompleted_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowCompleted_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveFlowSubsystem_eventIsObjectiveFlowCompleted_Parms), &Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowCompleted_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowCompleted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowCompleted_Statics::NewProp_FlowId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowCompleted_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowCompleted_Statics::PropPointers) < 2048);
// ********** End Function IsObjectiveFlowCompleted Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowCompleted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveFlowSubsystem, nullptr, "IsObjectiveFlowCompleted", 	Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowCompleted_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowCompleted_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowCompleted_Statics::JMObjectiveFlowSubsystem_eventIsObjectiveFlowCompleted_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowCompleted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowCompleted_Statics::JMObjectiveFlowSubsystem_eventIsObjectiveFlowCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveFlowSubsystem::execIsObjectiveFlowCompleted)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_FlowId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsObjectiveFlowCompleted(Z_Param_FlowId);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveFlowSubsystem Function IsObjectiveFlowCompleted ****************

// ********** Begin Class UJMObjectiveFlowSubsystem Function ResetObjectiveFlow ********************
struct Z_Construct_UFunction_UJMObjectiveFlowSubsystem_ResetObjectiveFlow_Statics
{
	struct JMObjectiveFlowSubsystem_eventResetObjectiveFlow_Parms
	{
		FGameplayTag FlowId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveFlowSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResetObjectiveFlow constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_FlowId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ResetObjectiveFlow constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ResetObjectiveFlow Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_ResetObjectiveFlow_Statics::NewProp_FlowId = { "FlowId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveFlowSubsystem_eventResetObjectiveFlow_Parms, FlowId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UJMObjectiveFlowSubsystem_ResetObjectiveFlow_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveFlowSubsystem_eventResetObjectiveFlow_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_ResetObjectiveFlow_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveFlowSubsystem_eventResetObjectiveFlow_Parms), &Z_Construct_UFunction_UJMObjectiveFlowSubsystem_ResetObjectiveFlow_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveFlowSubsystem_ResetObjectiveFlow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_ResetObjectiveFlow_Statics::NewProp_FlowId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_ResetObjectiveFlow_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_ResetObjectiveFlow_Statics::PropPointers) < 2048);
// ********** End Function ResetObjectiveFlow Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_ResetObjectiveFlow_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveFlowSubsystem, nullptr, "ResetObjectiveFlow", 	Z_Construct_UFunction_UJMObjectiveFlowSubsystem_ResetObjectiveFlow_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_ResetObjectiveFlow_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_ResetObjectiveFlow_Statics::JMObjectiveFlowSubsystem_eventResetObjectiveFlow_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_ResetObjectiveFlow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveFlowSubsystem_ResetObjectiveFlow_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_ResetObjectiveFlow_Statics::JMObjectiveFlowSubsystem_eventResetObjectiveFlow_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveFlowSubsystem_ResetObjectiveFlow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveFlowSubsystem_ResetObjectiveFlow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveFlowSubsystem::execResetObjectiveFlow)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_FlowId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ResetObjectiveFlow(Z_Param_FlowId);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveFlowSubsystem Function ResetObjectiveFlow **********************

// ********** Begin Class UJMObjectiveFlowSubsystem Function RestartObjectiveFlow ******************
struct Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestartObjectiveFlow_Statics
{
	struct JMObjectiveFlowSubsystem_eventRestartObjectiveFlow_Parms
	{
		FGameplayTag FlowId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveFlowSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RestartObjectiveFlow constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_FlowId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RestartObjectiveFlow constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RestartObjectiveFlow Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestartObjectiveFlow_Statics::NewProp_FlowId = { "FlowId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveFlowSubsystem_eventRestartObjectiveFlow_Parms, FlowId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestartObjectiveFlow_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveFlowSubsystem_eventRestartObjectiveFlow_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestartObjectiveFlow_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveFlowSubsystem_eventRestartObjectiveFlow_Parms), &Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestartObjectiveFlow_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestartObjectiveFlow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestartObjectiveFlow_Statics::NewProp_FlowId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestartObjectiveFlow_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestartObjectiveFlow_Statics::PropPointers) < 2048);
// ********** End Function RestartObjectiveFlow Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestartObjectiveFlow_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveFlowSubsystem, nullptr, "RestartObjectiveFlow", 	Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestartObjectiveFlow_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestartObjectiveFlow_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestartObjectiveFlow_Statics::JMObjectiveFlowSubsystem_eventRestartObjectiveFlow_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestartObjectiveFlow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestartObjectiveFlow_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestartObjectiveFlow_Statics::JMObjectiveFlowSubsystem_eventRestartObjectiveFlow_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestartObjectiveFlow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestartObjectiveFlow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveFlowSubsystem::execRestartObjectiveFlow)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_FlowId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->RestartObjectiveFlow(Z_Param_FlowId);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveFlowSubsystem Function RestartObjectiveFlow ********************

// ********** Begin Class UJMObjectiveFlowSubsystem Function RestoreObjectiveFlowStates ************
struct Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestoreObjectiveFlowStates_Statics
{
	struct JMObjectiveFlowSubsystem_eventRestoreObjectiveFlowStates_Parms
	{
		TArray<FJMObjectiveFlowSaveData> SavedStates;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective Flow|Save" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveFlowSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedStates_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RestoreObjectiveFlowStates constinit property declarations ************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SavedStates_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SavedStates;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RestoreObjectiveFlowStates constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RestoreObjectiveFlowStates Property Definitions ***********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestoreObjectiveFlowStates_Statics::NewProp_SavedStates_Inner = { "SavedStates", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData, METADATA_PARAMS(0, nullptr) }; // 2623431764
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestoreObjectiveFlowStates_Statics::NewProp_SavedStates = { "SavedStates", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveFlowSubsystem_eventRestoreObjectiveFlowStates_Parms, SavedStates), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedStates_MetaData), NewProp_SavedStates_MetaData) }; // 2623431764
void Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestoreObjectiveFlowStates_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveFlowSubsystem_eventRestoreObjectiveFlowStates_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestoreObjectiveFlowStates_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveFlowSubsystem_eventRestoreObjectiveFlowStates_Parms), &Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestoreObjectiveFlowStates_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestoreObjectiveFlowStates_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestoreObjectiveFlowStates_Statics::NewProp_SavedStates_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestoreObjectiveFlowStates_Statics::NewProp_SavedStates,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestoreObjectiveFlowStates_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestoreObjectiveFlowStates_Statics::PropPointers) < 2048);
// ********** End Function RestoreObjectiveFlowStates Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestoreObjectiveFlowStates_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveFlowSubsystem, nullptr, "RestoreObjectiveFlowStates", 	Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestoreObjectiveFlowStates_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestoreObjectiveFlowStates_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestoreObjectiveFlowStates_Statics::JMObjectiveFlowSubsystem_eventRestoreObjectiveFlowStates_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestoreObjectiveFlowStates_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestoreObjectiveFlowStates_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestoreObjectiveFlowStates_Statics::JMObjectiveFlowSubsystem_eventRestoreObjectiveFlowStates_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestoreObjectiveFlowStates()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestoreObjectiveFlowStates_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveFlowSubsystem::execRestoreObjectiveFlowStates)
{
	P_GET_TARRAY_REF(FJMObjectiveFlowSaveData,Z_Param_Out_SavedStates);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->RestoreObjectiveFlowStates(Z_Param_Out_SavedStates);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveFlowSubsystem Function RestoreObjectiveFlowStates **************

// ********** Begin Class UJMObjectiveFlowSubsystem Function StartObjectiveFlow ********************
struct Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StartObjectiveFlow_Statics
{
	struct JMObjectiveFlowSubsystem_eventStartObjectiveFlow_Parms
	{
		UJMObjectiveFlowDefinition* Definition;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveFlowSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function StartObjectiveFlow constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Definition;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function StartObjectiveFlow constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function StartObjectiveFlow Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StartObjectiveFlow_Statics::NewProp_Definition = { "Definition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveFlowSubsystem_eventStartObjectiveFlow_Parms, Definition), Z_Construct_UClass_UJMObjectiveFlowDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StartObjectiveFlow_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveFlowSubsystem_eventStartObjectiveFlow_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StartObjectiveFlow_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveFlowSubsystem_eventStartObjectiveFlow_Parms), &Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StartObjectiveFlow_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StartObjectiveFlow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StartObjectiveFlow_Statics::NewProp_Definition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StartObjectiveFlow_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StartObjectiveFlow_Statics::PropPointers) < 2048);
// ********** End Function StartObjectiveFlow Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StartObjectiveFlow_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveFlowSubsystem, nullptr, "StartObjectiveFlow", 	Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StartObjectiveFlow_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StartObjectiveFlow_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StartObjectiveFlow_Statics::JMObjectiveFlowSubsystem_eventStartObjectiveFlow_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StartObjectiveFlow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StartObjectiveFlow_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StartObjectiveFlow_Statics::JMObjectiveFlowSubsystem_eventStartObjectiveFlow_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StartObjectiveFlow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StartObjectiveFlow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveFlowSubsystem::execStartObjectiveFlow)
{
	P_GET_OBJECT(UJMObjectiveFlowDefinition,Z_Param_Definition);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->StartObjectiveFlow(Z_Param_Definition);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveFlowSubsystem Function StartObjectiveFlow **********************

// ********** Begin Class UJMObjectiveFlowSubsystem Function StopObjectiveFlow *********************
struct Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StopObjectiveFlow_Statics
{
	struct JMObjectiveFlowSubsystem_eventStopObjectiveFlow_Parms
	{
		FGameplayTag FlowId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveFlowSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function StopObjectiveFlow constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_FlowId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function StopObjectiveFlow constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function StopObjectiveFlow Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StopObjectiveFlow_Statics::NewProp_FlowId = { "FlowId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveFlowSubsystem_eventStopObjectiveFlow_Parms, FlowId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StopObjectiveFlow_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveFlowSubsystem_eventStopObjectiveFlow_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StopObjectiveFlow_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveFlowSubsystem_eventStopObjectiveFlow_Parms), &Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StopObjectiveFlow_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StopObjectiveFlow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StopObjectiveFlow_Statics::NewProp_FlowId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StopObjectiveFlow_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StopObjectiveFlow_Statics::PropPointers) < 2048);
// ********** End Function StopObjectiveFlow Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StopObjectiveFlow_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveFlowSubsystem, nullptr, "StopObjectiveFlow", 	Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StopObjectiveFlow_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StopObjectiveFlow_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StopObjectiveFlow_Statics::JMObjectiveFlowSubsystem_eventStopObjectiveFlow_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StopObjectiveFlow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StopObjectiveFlow_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StopObjectiveFlow_Statics::JMObjectiveFlowSubsystem_eventStopObjectiveFlow_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StopObjectiveFlow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StopObjectiveFlow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveFlowSubsystem::execStopObjectiveFlow)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_FlowId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->StopObjectiveFlow(Z_Param_FlowId);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveFlowSubsystem Function StopObjectiveFlow ***********************

// ********** Begin Class UJMObjectiveFlowSubsystem ************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMObjectiveFlowSubsystem;
UClass* UJMObjectiveFlowSubsystem::GetPrivateStaticClass()
{
	using TClass = UJMObjectiveFlowSubsystem;
	if (!Z_Registration_Info_UClass_UJMObjectiveFlowSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMObjectiveFlowSubsystem"),
			Z_Registration_Info_UClass_UJMObjectiveFlowSubsystem.InnerSingleton,
			StaticRegisterNativesUJMObjectiveFlowSubsystem,
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
	return Z_Registration_Info_UClass_UJMObjectiveFlowSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMObjectiveFlowSubsystem_NoRegister()
{
	return UJMObjectiveFlowSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Subsystems/JMObjectiveFlowSubsystem.h" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveFlowSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnObjectiveFlowStarted_MetaData[] = {
		{ "Category", "JM Objective Flow|Events" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveFlowSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnObjectiveFlowStepChanged_MetaData[] = {
		{ "Category", "JM Objective Flow|Events" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveFlowSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnObjectiveFlowCompleted_MetaData[] = {
		{ "Category", "JM Objective Flow|Events" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveFlowSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnObjectiveFlowFailed_MetaData[] = {
		{ "Category", "JM Objective Flow|Events" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveFlowSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnObjectiveFlowStopped_MetaData[] = {
		{ "Category", "JM Objective Flow|Events" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveFlowSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlowStates_MetaData[] = {
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveFlowSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectiveSubsystem_MetaData[] = {
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveFlowSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EventSubsystem_MetaData[] = {
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveFlowSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMObjectiveFlowSubsystem constinit property declarations ****************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnObjectiveFlowStarted;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnObjectiveFlowStepChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnObjectiveFlowCompleted;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnObjectiveFlowFailed;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnObjectiveFlowStopped;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FlowStates_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FlowStates_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_FlowStates;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ObjectiveSubsystem;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EventSubsystem;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMObjectiveFlowSubsystem constinit property declarations ******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CaptureObjectiveFlowStates"), .Pointer = &UJMObjectiveFlowSubsystem::execCaptureObjectiveFlowStates },
		{ .NameUTF8 = UTF8TEXT("GetActiveObjectiveFlows"), .Pointer = &UJMObjectiveFlowSubsystem::execGetActiveObjectiveFlows },
		{ .NameUTF8 = UTF8TEXT("GetObjectiveFlowState"), .Pointer = &UJMObjectiveFlowSubsystem::execGetObjectiveFlowState },
		{ .NameUTF8 = UTF8TEXT("HandleObjectiveCompleted"), .Pointer = &UJMObjectiveFlowSubsystem::execHandleObjectiveCompleted },
		{ .NameUTF8 = UTF8TEXT("HandleObjectiveFailed"), .Pointer = &UJMObjectiveFlowSubsystem::execHandleObjectiveFailed },
		{ .NameUTF8 = UTF8TEXT("IsObjectiveFlowActive"), .Pointer = &UJMObjectiveFlowSubsystem::execIsObjectiveFlowActive },
		{ .NameUTF8 = UTF8TEXT("IsObjectiveFlowCompleted"), .Pointer = &UJMObjectiveFlowSubsystem::execIsObjectiveFlowCompleted },
		{ .NameUTF8 = UTF8TEXT("ResetObjectiveFlow"), .Pointer = &UJMObjectiveFlowSubsystem::execResetObjectiveFlow },
		{ .NameUTF8 = UTF8TEXT("RestartObjectiveFlow"), .Pointer = &UJMObjectiveFlowSubsystem::execRestartObjectiveFlow },
		{ .NameUTF8 = UTF8TEXT("RestoreObjectiveFlowStates"), .Pointer = &UJMObjectiveFlowSubsystem::execRestoreObjectiveFlowStates },
		{ .NameUTF8 = UTF8TEXT("StartObjectiveFlow"), .Pointer = &UJMObjectiveFlowSubsystem::execStartObjectiveFlow },
		{ .NameUTF8 = UTF8TEXT("StopObjectiveFlow"), .Pointer = &UJMObjectiveFlowSubsystem::execStopObjectiveFlow },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMObjectiveFlowSubsystem_CaptureObjectiveFlowStates, "CaptureObjectiveFlowStates" }, // 3034189205
		{ &Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetActiveObjectiveFlows, "GetActiveObjectiveFlows" }, // 1950711765
		{ &Z_Construct_UFunction_UJMObjectiveFlowSubsystem_GetObjectiveFlowState, "GetObjectiveFlowState" }, // 4034498641
		{ &Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveCompleted, "HandleObjectiveCompleted" }, // 3152941239
		{ &Z_Construct_UFunction_UJMObjectiveFlowSubsystem_HandleObjectiveFailed, "HandleObjectiveFailed" }, // 2332933799
		{ &Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowActive, "IsObjectiveFlowActive" }, // 1932427350
		{ &Z_Construct_UFunction_UJMObjectiveFlowSubsystem_IsObjectiveFlowCompleted, "IsObjectiveFlowCompleted" }, // 1786605827
		{ &Z_Construct_UFunction_UJMObjectiveFlowSubsystem_ResetObjectiveFlow, "ResetObjectiveFlow" }, // 2217167867
		{ &Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestartObjectiveFlow, "RestartObjectiveFlow" }, // 2917755315
		{ &Z_Construct_UFunction_UJMObjectiveFlowSubsystem_RestoreObjectiveFlowStates, "RestoreObjectiveFlowStates" }, // 1319987704
		{ &Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StartObjectiveFlow, "StartObjectiveFlow" }, // 1303790499
		{ &Z_Construct_UFunction_UJMObjectiveFlowSubsystem_StopObjectiveFlow, "StopObjectiveFlow" }, // 530837661
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMObjectiveFlowSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics

// ********** Begin Class UJMObjectiveFlowSubsystem Property Definitions ***************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::NewProp_OnObjectiveFlowStarted = { "OnObjectiveFlowStarted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveFlowSubsystem, OnObjectiveFlowStarted), Z_Construct_UDelegateFunction_JMObjective_JMObjectiveFlowStateChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnObjectiveFlowStarted_MetaData), NewProp_OnObjectiveFlowStarted_MetaData) }; // 842937058
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::NewProp_OnObjectiveFlowStepChanged = { "OnObjectiveFlowStepChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveFlowSubsystem, OnObjectiveFlowStepChanged), Z_Construct_UDelegateFunction_JMObjective_JMObjectiveFlowStateChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnObjectiveFlowStepChanged_MetaData), NewProp_OnObjectiveFlowStepChanged_MetaData) }; // 842937058
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::NewProp_OnObjectiveFlowCompleted = { "OnObjectiveFlowCompleted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveFlowSubsystem, OnObjectiveFlowCompleted), Z_Construct_UDelegateFunction_JMObjective_JMObjectiveFlowStateChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnObjectiveFlowCompleted_MetaData), NewProp_OnObjectiveFlowCompleted_MetaData) }; // 842937058
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::NewProp_OnObjectiveFlowFailed = { "OnObjectiveFlowFailed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveFlowSubsystem, OnObjectiveFlowFailed), Z_Construct_UDelegateFunction_JMObjective_JMObjectiveFlowStateChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnObjectiveFlowFailed_MetaData), NewProp_OnObjectiveFlowFailed_MetaData) }; // 842937058
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::NewProp_OnObjectiveFlowStopped = { "OnObjectiveFlowStopped", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveFlowSubsystem, OnObjectiveFlowStopped), Z_Construct_UDelegateFunction_JMObjective_JMObjectiveFlowStateChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnObjectiveFlowStopped_MetaData), NewProp_OnObjectiveFlowStopped_MetaData) }; // 842937058
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::NewProp_FlowStates_ValueProp = { "FlowStates", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState, METADATA_PARAMS(0, nullptr) }; // 853706147
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::NewProp_FlowStates_Key_KeyProp = { "FlowStates_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::NewProp_FlowStates = { "FlowStates", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveFlowSubsystem, FlowStates), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlowStates_MetaData), NewProp_FlowStates_MetaData) }; // 517357616 853706147
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::NewProp_ObjectiveSubsystem = { "ObjectiveSubsystem", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveFlowSubsystem, ObjectiveSubsystem), Z_Construct_UClass_UJMObjectiveSubsystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectiveSubsystem_MetaData), NewProp_ObjectiveSubsystem_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::NewProp_EventSubsystem = { "EventSubsystem", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveFlowSubsystem, EventSubsystem), Z_Construct_UClass_UJMGameplayEventSubsystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EventSubsystem_MetaData), NewProp_EventSubsystem_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::NewProp_OnObjectiveFlowStarted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::NewProp_OnObjectiveFlowStepChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::NewProp_OnObjectiveFlowCompleted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::NewProp_OnObjectiveFlowFailed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::NewProp_OnObjectiveFlowStopped,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::NewProp_FlowStates_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::NewProp_FlowStates_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::NewProp_FlowStates,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::NewProp_ObjectiveSubsystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::NewProp_EventSubsystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::PropPointers) < 2048);
// ********** End Class UJMObjectiveFlowSubsystem Property Definitions *****************************
UObject* (*const Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_JMObjective,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::ClassParams = {
	&UJMObjectiveFlowSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::Class_MetaDataParams)
};
void UJMObjectiveFlowSubsystem::StaticRegisterNativesUJMObjectiveFlowSubsystem()
{
	UClass* Class = UJMObjectiveFlowSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMObjectiveFlowSubsystem()
{
	if (!Z_Registration_Info_UClass_UJMObjectiveFlowSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMObjectiveFlowSubsystem.OuterSingleton, Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMObjectiveFlowSubsystem.OuterSingleton;
}
UJMObjectiveFlowSubsystem::UJMObjectiveFlowSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMObjectiveFlowSubsystem);
UJMObjectiveFlowSubsystem::~UJMObjectiveFlowSubsystem() {}
// ********** End Class UJMObjectiveFlowSubsystem **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveFlowSubsystem_h__Script_JMObjective_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMObjectiveFlowSubsystem, UJMObjectiveFlowSubsystem::StaticClass, TEXT("UJMObjectiveFlowSubsystem"), &Z_Registration_Info_UClass_UJMObjectiveFlowSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMObjectiveFlowSubsystem), 2196153897U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveFlowSubsystem_h__Script_JMObjective_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveFlowSubsystem_h__Script_JMObjective_2671690086{
	TEXT("/Script/JMObjective"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveFlowSubsystem_h__Script_JMObjective_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveFlowSubsystem_h__Script_JMObjective_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
