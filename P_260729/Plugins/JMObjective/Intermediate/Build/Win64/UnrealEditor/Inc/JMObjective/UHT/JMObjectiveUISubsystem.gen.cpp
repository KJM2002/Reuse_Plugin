// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Subsystems/JMObjectiveUISubsystem.h"
#include "Engine/LocalPlayer.h"
#include "GameplayTagContainer.h"
#include "Types/JMObjectiveTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMObjectiveUISubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_ULocalPlayerSubsystem();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveSubsystem_NoRegister();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveUISubsystem();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveUISubsystem_NoRegister();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveWidgetBase_NoRegister();
JMOBJECTIVE_API UScriptStruct* Z_Construct_UScriptStruct_FJMObjectiveRuntimeState();
UPackage* Z_Construct_UPackage__Script_JMObjective();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMObjectiveUISubsystem Function GetObjectiveWidget **********************
struct Z_Construct_UFunction_UJMObjectiveUISubsystem_GetObjectiveWidget_Statics
{
	struct JMObjectiveUISubsystem_eventGetObjectiveWidget_Parms
	{
		UJMObjectiveWidgetBase* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective|UI" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveUISubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetObjectiveWidget constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetObjectiveWidget constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetObjectiveWidget Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveUISubsystem_GetObjectiveWidget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveUISubsystem_eventGetObjectiveWidget_Parms, ReturnValue), Z_Construct_UClass_UJMObjectiveWidgetBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveUISubsystem_GetObjectiveWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveUISubsystem_GetObjectiveWidget_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveUISubsystem_GetObjectiveWidget_Statics::PropPointers) < 2048);
// ********** End Function GetObjectiveWidget Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveUISubsystem_GetObjectiveWidget_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveUISubsystem, nullptr, "GetObjectiveWidget", 	Z_Construct_UFunction_UJMObjectiveUISubsystem_GetObjectiveWidget_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveUISubsystem_GetObjectiveWidget_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveUISubsystem_GetObjectiveWidget_Statics::JMObjectiveUISubsystem_eventGetObjectiveWidget_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveUISubsystem_GetObjectiveWidget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveUISubsystem_GetObjectiveWidget_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveUISubsystem_GetObjectiveWidget_Statics::JMObjectiveUISubsystem_eventGetObjectiveWidget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveUISubsystem_GetObjectiveWidget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveUISubsystem_GetObjectiveWidget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveUISubsystem::execGetObjectiveWidget)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UJMObjectiveWidgetBase**)Z_Param__Result=P_THIS->GetObjectiveWidget();
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveUISubsystem Function GetObjectiveWidget ************************

// ********** Begin Class UJMObjectiveUISubsystem Function HandleActivated *************************
struct Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleActivated_Statics
{
	struct JMObjectiveUISubsystem_eventHandleActivated_Parms
	{
		FGameplayTag ObjectiveId;
		FJMObjectiveRuntimeState RuntimeState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveUISubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RuntimeState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleActivated constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RuntimeState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleActivated constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleActivated Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleActivated_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveUISubsystem_eventHandleActivated_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleActivated_Statics::NewProp_RuntimeState = { "RuntimeState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveUISubsystem_eventHandleActivated_Parms, RuntimeState), Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RuntimeState_MetaData), NewProp_RuntimeState_MetaData) }; // 4088304728
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleActivated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleActivated_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleActivated_Statics::NewProp_RuntimeState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleActivated_Statics::PropPointers) < 2048);
// ********** End Function HandleActivated Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleActivated_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveUISubsystem, nullptr, "HandleActivated", 	Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleActivated_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleActivated_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleActivated_Statics::JMObjectiveUISubsystem_eventHandleActivated_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleActivated_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleActivated_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleActivated_Statics::JMObjectiveUISubsystem_eventHandleActivated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleActivated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleActivated_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveUISubsystem::execHandleActivated)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_GET_STRUCT_REF(FJMObjectiveRuntimeState,Z_Param_Out_RuntimeState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleActivated(Z_Param_ObjectiveId,Z_Param_Out_RuntimeState);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveUISubsystem Function HandleActivated ***************************

// ********** Begin Class UJMObjectiveUISubsystem Function HandleCompleted *************************
struct Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleCompleted_Statics
{
	struct JMObjectiveUISubsystem_eventHandleCompleted_Parms
	{
		FGameplayTag ObjectiveId;
		FJMObjectiveRuntimeState RuntimeState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveUISubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RuntimeState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleCompleted constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RuntimeState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleCompleted constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleCompleted Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleCompleted_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveUISubsystem_eventHandleCompleted_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleCompleted_Statics::NewProp_RuntimeState = { "RuntimeState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveUISubsystem_eventHandleCompleted_Parms, RuntimeState), Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RuntimeState_MetaData), NewProp_RuntimeState_MetaData) }; // 4088304728
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleCompleted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleCompleted_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleCompleted_Statics::NewProp_RuntimeState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleCompleted_Statics::PropPointers) < 2048);
// ********** End Function HandleCompleted Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleCompleted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveUISubsystem, nullptr, "HandleCompleted", 	Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleCompleted_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleCompleted_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleCompleted_Statics::JMObjectiveUISubsystem_eventHandleCompleted_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleCompleted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleCompleted_Statics::JMObjectiveUISubsystem_eventHandleCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveUISubsystem::execHandleCompleted)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_GET_STRUCT_REF(FJMObjectiveRuntimeState,Z_Param_Out_RuntimeState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCompleted(Z_Param_ObjectiveId,Z_Param_Out_RuntimeState);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveUISubsystem Function HandleCompleted ***************************

// ********** Begin Class UJMObjectiveUISubsystem Function HandleFailed ****************************
struct Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleFailed_Statics
{
	struct JMObjectiveUISubsystem_eventHandleFailed_Parms
	{
		FGameplayTag ObjectiveId;
		FJMObjectiveRuntimeState RuntimeState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveUISubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RuntimeState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleFailed constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RuntimeState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleFailed constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleFailed Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleFailed_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveUISubsystem_eventHandleFailed_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleFailed_Statics::NewProp_RuntimeState = { "RuntimeState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveUISubsystem_eventHandleFailed_Parms, RuntimeState), Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RuntimeState_MetaData), NewProp_RuntimeState_MetaData) }; // 4088304728
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleFailed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleFailed_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleFailed_Statics::NewProp_RuntimeState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleFailed_Statics::PropPointers) < 2048);
// ********** End Function HandleFailed Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleFailed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveUISubsystem, nullptr, "HandleFailed", 	Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleFailed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleFailed_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleFailed_Statics::JMObjectiveUISubsystem_eventHandleFailed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleFailed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleFailed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleFailed_Statics::JMObjectiveUISubsystem_eventHandleFailed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleFailed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleFailed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveUISubsystem::execHandleFailed)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_GET_STRUCT_REF(FJMObjectiveRuntimeState,Z_Param_Out_RuntimeState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleFailed(Z_Param_ObjectiveId,Z_Param_Out_RuntimeState);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveUISubsystem Function HandleFailed ******************************

// ********** Begin Class UJMObjectiveUISubsystem Function HandleProgressed ************************
struct Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleProgressed_Statics
{
	struct JMObjectiveUISubsystem_eventHandleProgressed_Parms
	{
		FGameplayTag ObjectiveId;
		FJMObjectiveRuntimeState RuntimeState;
		int32 ProgressDelta;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveUISubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RuntimeState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleProgressed constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RuntimeState;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ProgressDelta;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleProgressed constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleProgressed Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleProgressed_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveUISubsystem_eventHandleProgressed_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleProgressed_Statics::NewProp_RuntimeState = { "RuntimeState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveUISubsystem_eventHandleProgressed_Parms, RuntimeState), Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RuntimeState_MetaData), NewProp_RuntimeState_MetaData) }; // 4088304728
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleProgressed_Statics::NewProp_ProgressDelta = { "ProgressDelta", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveUISubsystem_eventHandleProgressed_Parms, ProgressDelta), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleProgressed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleProgressed_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleProgressed_Statics::NewProp_RuntimeState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleProgressed_Statics::NewProp_ProgressDelta,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleProgressed_Statics::PropPointers) < 2048);
// ********** End Function HandleProgressed Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleProgressed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveUISubsystem, nullptr, "HandleProgressed", 	Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleProgressed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleProgressed_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleProgressed_Statics::JMObjectiveUISubsystem_eventHandleProgressed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleProgressed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleProgressed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleProgressed_Statics::JMObjectiveUISubsystem_eventHandleProgressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleProgressed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleProgressed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveUISubsystem::execHandleProgressed)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_GET_STRUCT_REF(FJMObjectiveRuntimeState,Z_Param_Out_RuntimeState);
	P_GET_PROPERTY(FIntProperty,Z_Param_ProgressDelta);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleProgressed(Z_Param_ObjectiveId,Z_Param_Out_RuntimeState,Z_Param_ProgressDelta);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveUISubsystem Function HandleProgressed **************************

// ********** Begin Class UJMObjectiveUISubsystem Function HandleRegistered ************************
struct Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRegistered_Statics
{
	struct JMObjectiveUISubsystem_eventHandleRegistered_Parms
	{
		FGameplayTag ObjectiveId;
		FJMObjectiveRuntimeState RuntimeState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveUISubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RuntimeState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleRegistered constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RuntimeState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleRegistered constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleRegistered Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRegistered_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveUISubsystem_eventHandleRegistered_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRegistered_Statics::NewProp_RuntimeState = { "RuntimeState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveUISubsystem_eventHandleRegistered_Parms, RuntimeState), Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RuntimeState_MetaData), NewProp_RuntimeState_MetaData) }; // 4088304728
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRegistered_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRegistered_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRegistered_Statics::NewProp_RuntimeState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRegistered_Statics::PropPointers) < 2048);
// ********** End Function HandleRegistered Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRegistered_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveUISubsystem, nullptr, "HandleRegistered", 	Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRegistered_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRegistered_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRegistered_Statics::JMObjectiveUISubsystem_eventHandleRegistered_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRegistered_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRegistered_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRegistered_Statics::JMObjectiveUISubsystem_eventHandleRegistered_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRegistered()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRegistered_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveUISubsystem::execHandleRegistered)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_GET_STRUCT_REF(FJMObjectiveRuntimeState,Z_Param_Out_RuntimeState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleRegistered(Z_Param_ObjectiveId,Z_Param_Out_RuntimeState);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveUISubsystem Function HandleRegistered **************************

// ********** Begin Class UJMObjectiveUISubsystem Function HandleRemoved ***************************
struct Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRemoved_Statics
{
	struct JMObjectiveUISubsystem_eventHandleRemoved_Parms
	{
		FGameplayTag ObjectiveId;
		FJMObjectiveRuntimeState RuntimeState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveUISubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RuntimeState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleRemoved constinit property declarations *************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RuntimeState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleRemoved constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleRemoved Property Definitions ************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRemoved_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveUISubsystem_eventHandleRemoved_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRemoved_Statics::NewProp_RuntimeState = { "RuntimeState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveUISubsystem_eventHandleRemoved_Parms, RuntimeState), Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RuntimeState_MetaData), NewProp_RuntimeState_MetaData) }; // 4088304728
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRemoved_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRemoved_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRemoved_Statics::NewProp_RuntimeState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRemoved_Statics::PropPointers) < 2048);
// ********** End Function HandleRemoved Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRemoved_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveUISubsystem, nullptr, "HandleRemoved", 	Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRemoved_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRemoved_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRemoved_Statics::JMObjectiveUISubsystem_eventHandleRemoved_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRemoved_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRemoved_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRemoved_Statics::JMObjectiveUISubsystem_eventHandleRemoved_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRemoved()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRemoved_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveUISubsystem::execHandleRemoved)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_GET_STRUCT_REF(FJMObjectiveRuntimeState,Z_Param_Out_RuntimeState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleRemoved(Z_Param_ObjectiveId,Z_Param_Out_RuntimeState);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveUISubsystem Function HandleRemoved *****************************

// ********** Begin Class UJMObjectiveUISubsystem **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMObjectiveUISubsystem;
UClass* UJMObjectiveUISubsystem::GetPrivateStaticClass()
{
	using TClass = UJMObjectiveUISubsystem;
	if (!Z_Registration_Info_UClass_UJMObjectiveUISubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMObjectiveUISubsystem"),
			Z_Registration_Info_UClass_UJMObjectiveUISubsystem.InnerSingleton,
			StaticRegisterNativesUJMObjectiveUISubsystem,
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
	return Z_Registration_Info_UClass_UJMObjectiveUISubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMObjectiveUISubsystem_NoRegister()
{
	return UJMObjectiveUISubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMObjectiveUISubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Subsystems/JMObjectiveUISubsystem.h" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveUISubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectiveWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveUISubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectiveSubsystem_MetaData[] = {
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveUISubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMObjectiveUISubsystem constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ObjectiveWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ObjectiveSubsystem;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMObjectiveUISubsystem constinit property declarations ********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetObjectiveWidget"), .Pointer = &UJMObjectiveUISubsystem::execGetObjectiveWidget },
		{ .NameUTF8 = UTF8TEXT("HandleActivated"), .Pointer = &UJMObjectiveUISubsystem::execHandleActivated },
		{ .NameUTF8 = UTF8TEXT("HandleCompleted"), .Pointer = &UJMObjectiveUISubsystem::execHandleCompleted },
		{ .NameUTF8 = UTF8TEXT("HandleFailed"), .Pointer = &UJMObjectiveUISubsystem::execHandleFailed },
		{ .NameUTF8 = UTF8TEXT("HandleProgressed"), .Pointer = &UJMObjectiveUISubsystem::execHandleProgressed },
		{ .NameUTF8 = UTF8TEXT("HandleRegistered"), .Pointer = &UJMObjectiveUISubsystem::execHandleRegistered },
		{ .NameUTF8 = UTF8TEXT("HandleRemoved"), .Pointer = &UJMObjectiveUISubsystem::execHandleRemoved },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMObjectiveUISubsystem_GetObjectiveWidget, "GetObjectiveWidget" }, // 3202848039
		{ &Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleActivated, "HandleActivated" }, // 2332075925
		{ &Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleCompleted, "HandleCompleted" }, // 1652508559
		{ &Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleFailed, "HandleFailed" }, // 3522957176
		{ &Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleProgressed, "HandleProgressed" }, // 1948343074
		{ &Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRegistered, "HandleRegistered" }, // 3147695330
		{ &Z_Construct_UFunction_UJMObjectiveUISubsystem_HandleRemoved, "HandleRemoved" }, // 3382559459
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMObjectiveUISubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMObjectiveUISubsystem_Statics

// ********** Begin Class UJMObjectiveUISubsystem Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMObjectiveUISubsystem_Statics::NewProp_ObjectiveWidget = { "ObjectiveWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveUISubsystem, ObjectiveWidget), Z_Construct_UClass_UJMObjectiveWidgetBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectiveWidget_MetaData), NewProp_ObjectiveWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMObjectiveUISubsystem_Statics::NewProp_ObjectiveSubsystem = { "ObjectiveSubsystem", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveUISubsystem, ObjectiveSubsystem), Z_Construct_UClass_UJMObjectiveSubsystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectiveSubsystem_MetaData), NewProp_ObjectiveSubsystem_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMObjectiveUISubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveUISubsystem_Statics::NewProp_ObjectiveWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveUISubsystem_Statics::NewProp_ObjectiveSubsystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveUISubsystem_Statics::PropPointers) < 2048);
// ********** End Class UJMObjectiveUISubsystem Property Definitions *******************************
UObject* (*const Z_Construct_UClass_UJMObjectiveUISubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ULocalPlayerSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_JMObjective,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveUISubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMObjectiveUISubsystem_Statics::ClassParams = {
	&UJMObjectiveUISubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMObjectiveUISubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveUISubsystem_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveUISubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMObjectiveUISubsystem_Statics::Class_MetaDataParams)
};
void UJMObjectiveUISubsystem::StaticRegisterNativesUJMObjectiveUISubsystem()
{
	UClass* Class = UJMObjectiveUISubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMObjectiveUISubsystem_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMObjectiveUISubsystem()
{
	if (!Z_Registration_Info_UClass_UJMObjectiveUISubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMObjectiveUISubsystem.OuterSingleton, Z_Construct_UClass_UJMObjectiveUISubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMObjectiveUISubsystem.OuterSingleton;
}
UJMObjectiveUISubsystem::UJMObjectiveUISubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMObjectiveUISubsystem);
UJMObjectiveUISubsystem::~UJMObjectiveUISubsystem() {}
// ********** End Class UJMObjectiveUISubsystem ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveUISubsystem_h__Script_JMObjective_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMObjectiveUISubsystem, UJMObjectiveUISubsystem::StaticClass, TEXT("UJMObjectiveUISubsystem"), &Z_Registration_Info_UClass_UJMObjectiveUISubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMObjectiveUISubsystem), 3733733790U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveUISubsystem_h__Script_JMObjective_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveUISubsystem_h__Script_JMObjective_141685858{
	TEXT("/Script/JMObjective"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveUISubsystem_h__Script_JMObjective_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveUISubsystem_h__Script_JMObjective_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
