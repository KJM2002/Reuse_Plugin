// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Subsystems/JMObjectiveSubsystem.h"
#include "Engine/GameInstance.h"
#include "GameplayTagContainer.h"
#include "Types/JMObjectiveTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMObjectiveSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventSubsystem_NoRegister();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveDefinition_NoRegister();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveSubsystem();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveSubsystem_NoRegister();
JMOBJECTIVE_API UFunction* Z_Construct_UDelegateFunction_JMObjective_JMObjectiveProgressedSignature__DelegateSignature();
JMOBJECTIVE_API UFunction* Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature();
JMOBJECTIVE_API UScriptStruct* Z_Construct_UScriptStruct_FJMObjectiveRuntimeState();
JMOBJECTIVE_API UScriptStruct* Z_Construct_UScriptStruct_FJMObjectiveSaveData();
UPackage* Z_Construct_UPackage__Script_JMObjective();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMObjectiveSubsystem Function ActivateObjective *************************
struct Z_Construct_UFunction_UJMObjectiveSubsystem_ActivateObjective_Statics
{
	struct JMObjectiveSubsystem_eventActivateObjective_Parms
	{
		FGameplayTag ObjectiveId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ActivateObjective constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ActivateObjective constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ActivateObjective Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_ActivateObjective_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveSubsystem_eventActivateObjective_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UJMObjectiveSubsystem_ActivateObjective_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveSubsystem_eventActivateObjective_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_ActivateObjective_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveSubsystem_eventActivateObjective_Parms), &Z_Construct_UFunction_UJMObjectiveSubsystem_ActivateObjective_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveSubsystem_ActivateObjective_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_ActivateObjective_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_ActivateObjective_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_ActivateObjective_Statics::PropPointers) < 2048);
// ********** End Function ActivateObjective Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveSubsystem_ActivateObjective_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveSubsystem, nullptr, "ActivateObjective", 	Z_Construct_UFunction_UJMObjectiveSubsystem_ActivateObjective_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_ActivateObjective_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_ActivateObjective_Statics::JMObjectiveSubsystem_eventActivateObjective_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_ActivateObjective_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveSubsystem_ActivateObjective_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_ActivateObjective_Statics::JMObjectiveSubsystem_eventActivateObjective_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveSubsystem_ActivateObjective()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveSubsystem_ActivateObjective_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveSubsystem::execActivateObjective)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ActivateObjective(Z_Param_ObjectiveId);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveSubsystem Function ActivateObjective ***************************

// ********** Begin Class UJMObjectiveSubsystem Function AddObjectiveProgress **********************
struct Z_Construct_UFunction_UJMObjectiveSubsystem_AddObjectiveProgress_Statics
{
	struct JMObjectiveSubsystem_eventAddObjectiveProgress_Parms
	{
		FGameplayTag ObjectiveId;
		int32 Amount;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective" },
		{ "CPP_Default_Amount", "1" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddObjectiveProgress constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Amount;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddObjectiveProgress constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddObjectiveProgress Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_AddObjectiveProgress_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveSubsystem_eventAddObjectiveProgress_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_AddObjectiveProgress_Statics::NewProp_Amount = { "Amount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveSubsystem_eventAddObjectiveProgress_Parms, Amount), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UJMObjectiveSubsystem_AddObjectiveProgress_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveSubsystem_eventAddObjectiveProgress_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_AddObjectiveProgress_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveSubsystem_eventAddObjectiveProgress_Parms), &Z_Construct_UFunction_UJMObjectiveSubsystem_AddObjectiveProgress_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveSubsystem_AddObjectiveProgress_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_AddObjectiveProgress_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_AddObjectiveProgress_Statics::NewProp_Amount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_AddObjectiveProgress_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_AddObjectiveProgress_Statics::PropPointers) < 2048);
// ********** End Function AddObjectiveProgress Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveSubsystem_AddObjectiveProgress_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveSubsystem, nullptr, "AddObjectiveProgress", 	Z_Construct_UFunction_UJMObjectiveSubsystem_AddObjectiveProgress_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_AddObjectiveProgress_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_AddObjectiveProgress_Statics::JMObjectiveSubsystem_eventAddObjectiveProgress_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_AddObjectiveProgress_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveSubsystem_AddObjectiveProgress_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_AddObjectiveProgress_Statics::JMObjectiveSubsystem_eventAddObjectiveProgress_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveSubsystem_AddObjectiveProgress()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveSubsystem_AddObjectiveProgress_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveSubsystem::execAddObjectiveProgress)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_GET_PROPERTY(FIntProperty,Z_Param_Amount);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->AddObjectiveProgress(Z_Param_ObjectiveId,Z_Param_Amount);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveSubsystem Function AddObjectiveProgress ************************

// ********** Begin Class UJMObjectiveSubsystem Function CaptureObjectiveStates ********************
struct Z_Construct_UFunction_UJMObjectiveSubsystem_CaptureObjectiveStates_Statics
{
	struct JMObjectiveSubsystem_eventCaptureObjectiveStates_Parms
	{
		TArray<FJMObjectiveSaveData> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective|Save" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CaptureObjectiveStates constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CaptureObjectiveStates constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CaptureObjectiveStates Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_CaptureObjectiveStates_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FJMObjectiveSaveData, METADATA_PARAMS(0, nullptr) }; // 220837192
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_CaptureObjectiveStates_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveSubsystem_eventCaptureObjectiveStates_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 220837192
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveSubsystem_CaptureObjectiveStates_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_CaptureObjectiveStates_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_CaptureObjectiveStates_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_CaptureObjectiveStates_Statics::PropPointers) < 2048);
// ********** End Function CaptureObjectiveStates Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveSubsystem_CaptureObjectiveStates_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveSubsystem, nullptr, "CaptureObjectiveStates", 	Z_Construct_UFunction_UJMObjectiveSubsystem_CaptureObjectiveStates_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_CaptureObjectiveStates_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_CaptureObjectiveStates_Statics::JMObjectiveSubsystem_eventCaptureObjectiveStates_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_CaptureObjectiveStates_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveSubsystem_CaptureObjectiveStates_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_CaptureObjectiveStates_Statics::JMObjectiveSubsystem_eventCaptureObjectiveStates_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveSubsystem_CaptureObjectiveStates()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveSubsystem_CaptureObjectiveStates_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveSubsystem::execCaptureObjectiveStates)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FJMObjectiveSaveData>*)Z_Param__Result=P_THIS->CaptureObjectiveStates();
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveSubsystem Function CaptureObjectiveStates **********************

// ********** Begin Class UJMObjectiveSubsystem Function CompleteObjective *************************
struct Z_Construct_UFunction_UJMObjectiveSubsystem_CompleteObjective_Statics
{
	struct JMObjectiveSubsystem_eventCompleteObjective_Parms
	{
		FGameplayTag ObjectiveId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CompleteObjective constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CompleteObjective constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CompleteObjective Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_CompleteObjective_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveSubsystem_eventCompleteObjective_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UJMObjectiveSubsystem_CompleteObjective_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveSubsystem_eventCompleteObjective_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_CompleteObjective_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveSubsystem_eventCompleteObjective_Parms), &Z_Construct_UFunction_UJMObjectiveSubsystem_CompleteObjective_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveSubsystem_CompleteObjective_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_CompleteObjective_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_CompleteObjective_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_CompleteObjective_Statics::PropPointers) < 2048);
// ********** End Function CompleteObjective Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveSubsystem_CompleteObjective_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveSubsystem, nullptr, "CompleteObjective", 	Z_Construct_UFunction_UJMObjectiveSubsystem_CompleteObjective_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_CompleteObjective_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_CompleteObjective_Statics::JMObjectiveSubsystem_eventCompleteObjective_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_CompleteObjective_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveSubsystem_CompleteObjective_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_CompleteObjective_Statics::JMObjectiveSubsystem_eventCompleteObjective_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveSubsystem_CompleteObjective()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveSubsystem_CompleteObjective_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveSubsystem::execCompleteObjective)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CompleteObjective(Z_Param_ObjectiveId);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveSubsystem Function CompleteObjective ***************************

// ********** Begin Class UJMObjectiveSubsystem Function DeactivateObjective ***********************
struct Z_Construct_UFunction_UJMObjectiveSubsystem_DeactivateObjective_Statics
{
	struct JMObjectiveSubsystem_eventDeactivateObjective_Parms
	{
		FGameplayTag ObjectiveId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function DeactivateObjective constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DeactivateObjective constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DeactivateObjective Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_DeactivateObjective_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveSubsystem_eventDeactivateObjective_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UJMObjectiveSubsystem_DeactivateObjective_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveSubsystem_eventDeactivateObjective_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_DeactivateObjective_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveSubsystem_eventDeactivateObjective_Parms), &Z_Construct_UFunction_UJMObjectiveSubsystem_DeactivateObjective_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveSubsystem_DeactivateObjective_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_DeactivateObjective_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_DeactivateObjective_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_DeactivateObjective_Statics::PropPointers) < 2048);
// ********** End Function DeactivateObjective Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveSubsystem_DeactivateObjective_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveSubsystem, nullptr, "DeactivateObjective", 	Z_Construct_UFunction_UJMObjectiveSubsystem_DeactivateObjective_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_DeactivateObjective_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_DeactivateObjective_Statics::JMObjectiveSubsystem_eventDeactivateObjective_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_DeactivateObjective_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveSubsystem_DeactivateObjective_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_DeactivateObjective_Statics::JMObjectiveSubsystem_eventDeactivateObjective_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveSubsystem_DeactivateObjective()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveSubsystem_DeactivateObjective_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveSubsystem::execDeactivateObjective)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->DeactivateObjective(Z_Param_ObjectiveId);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveSubsystem Function DeactivateObjective *************************

// ********** Begin Class UJMObjectiveSubsystem Function FailObjective *****************************
struct Z_Construct_UFunction_UJMObjectiveSubsystem_FailObjective_Statics
{
	struct JMObjectiveSubsystem_eventFailObjective_Parms
	{
		FGameplayTag ObjectiveId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function FailObjective constinit property declarations *************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FailObjective constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FailObjective Property Definitions ************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_FailObjective_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveSubsystem_eventFailObjective_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UJMObjectiveSubsystem_FailObjective_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveSubsystem_eventFailObjective_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_FailObjective_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveSubsystem_eventFailObjective_Parms), &Z_Construct_UFunction_UJMObjectiveSubsystem_FailObjective_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveSubsystem_FailObjective_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_FailObjective_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_FailObjective_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_FailObjective_Statics::PropPointers) < 2048);
// ********** End Function FailObjective Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveSubsystem_FailObjective_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveSubsystem, nullptr, "FailObjective", 	Z_Construct_UFunction_UJMObjectiveSubsystem_FailObjective_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_FailObjective_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_FailObjective_Statics::JMObjectiveSubsystem_eventFailObjective_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_FailObjective_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveSubsystem_FailObjective_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_FailObjective_Statics::JMObjectiveSubsystem_eventFailObjective_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveSubsystem_FailObjective()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveSubsystem_FailObjective_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveSubsystem::execFailObjective)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->FailObjective(Z_Param_ObjectiveId);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveSubsystem Function FailObjective *******************************

// ********** Begin Class UJMObjectiveSubsystem Function GetActiveObjectives ***********************
struct Z_Construct_UFunction_UJMObjectiveSubsystem_GetActiveObjectives_Statics
{
	struct JMObjectiveSubsystem_eventGetActiveObjectives_Parms
	{
		TArray<FJMObjectiveRuntimeState> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetActiveObjectives constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetActiveObjectives constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetActiveObjectives Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_GetActiveObjectives_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, METADATA_PARAMS(0, nullptr) }; // 4088304728
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_GetActiveObjectives_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveSubsystem_eventGetActiveObjectives_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 4088304728
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveSubsystem_GetActiveObjectives_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_GetActiveObjectives_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_GetActiveObjectives_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_GetActiveObjectives_Statics::PropPointers) < 2048);
// ********** End Function GetActiveObjectives Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveSubsystem_GetActiveObjectives_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveSubsystem, nullptr, "GetActiveObjectives", 	Z_Construct_UFunction_UJMObjectiveSubsystem_GetActiveObjectives_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_GetActiveObjectives_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_GetActiveObjectives_Statics::JMObjectiveSubsystem_eventGetActiveObjectives_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_GetActiveObjectives_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveSubsystem_GetActiveObjectives_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_GetActiveObjectives_Statics::JMObjectiveSubsystem_eventGetActiveObjectives_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveSubsystem_GetActiveObjectives()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveSubsystem_GetActiveObjectives_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveSubsystem::execGetActiveObjectives)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FJMObjectiveRuntimeState>*)Z_Param__Result=P_THIS->GetActiveObjectives();
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveSubsystem Function GetActiveObjectives *************************

// ********** Begin Class UJMObjectiveSubsystem Function GetCompletedObjectives ********************
struct Z_Construct_UFunction_UJMObjectiveSubsystem_GetCompletedObjectives_Statics
{
	struct JMObjectiveSubsystem_eventGetCompletedObjectives_Parms
	{
		TArray<FJMObjectiveRuntimeState> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCompletedObjectives constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCompletedObjectives constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCompletedObjectives Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_GetCompletedObjectives_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, METADATA_PARAMS(0, nullptr) }; // 4088304728
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_GetCompletedObjectives_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveSubsystem_eventGetCompletedObjectives_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 4088304728
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveSubsystem_GetCompletedObjectives_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_GetCompletedObjectives_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_GetCompletedObjectives_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_GetCompletedObjectives_Statics::PropPointers) < 2048);
// ********** End Function GetCompletedObjectives Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveSubsystem_GetCompletedObjectives_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveSubsystem, nullptr, "GetCompletedObjectives", 	Z_Construct_UFunction_UJMObjectiveSubsystem_GetCompletedObjectives_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_GetCompletedObjectives_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_GetCompletedObjectives_Statics::JMObjectiveSubsystem_eventGetCompletedObjectives_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_GetCompletedObjectives_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveSubsystem_GetCompletedObjectives_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_GetCompletedObjectives_Statics::JMObjectiveSubsystem_eventGetCompletedObjectives_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveSubsystem_GetCompletedObjectives()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveSubsystem_GetCompletedObjectives_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveSubsystem::execGetCompletedObjectives)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FJMObjectiveRuntimeState>*)Z_Param__Result=P_THIS->GetCompletedObjectives();
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveSubsystem Function GetCompletedObjectives **********************

// ********** Begin Class UJMObjectiveSubsystem Function GetObjectiveProgress **********************
struct Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveProgress_Statics
{
	struct JMObjectiveSubsystem_eventGetObjectiveProgress_Parms
	{
		FGameplayTag ObjectiveId;
		int32 OutCurrentCount;
		int32 OutRequiredCount;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetObjectiveProgress constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OutCurrentCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OutRequiredCount;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetObjectiveProgress constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetObjectiveProgress Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveProgress_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveSubsystem_eventGetObjectiveProgress_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveProgress_Statics::NewProp_OutCurrentCount = { "OutCurrentCount", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveSubsystem_eventGetObjectiveProgress_Parms, OutCurrentCount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveProgress_Statics::NewProp_OutRequiredCount = { "OutRequiredCount", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveSubsystem_eventGetObjectiveProgress_Parms, OutRequiredCount), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveProgress_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveSubsystem_eventGetObjectiveProgress_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveProgress_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveSubsystem_eventGetObjectiveProgress_Parms), &Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveProgress_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveProgress_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveProgress_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveProgress_Statics::NewProp_OutCurrentCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveProgress_Statics::NewProp_OutRequiredCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveProgress_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveProgress_Statics::PropPointers) < 2048);
// ********** End Function GetObjectiveProgress Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveProgress_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveSubsystem, nullptr, "GetObjectiveProgress", 	Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveProgress_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveProgress_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveProgress_Statics::JMObjectiveSubsystem_eventGetObjectiveProgress_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveProgress_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveProgress_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveProgress_Statics::JMObjectiveSubsystem_eventGetObjectiveProgress_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveProgress()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveProgress_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveSubsystem::execGetObjectiveProgress)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_OutCurrentCount);
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_OutRequiredCount);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetObjectiveProgress(Z_Param_ObjectiveId,Z_Param_Out_OutCurrentCount,Z_Param_Out_OutRequiredCount);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveSubsystem Function GetObjectiveProgress ************************

// ********** Begin Class UJMObjectiveSubsystem Function GetObjectiveState *************************
struct Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveState_Statics
{
	struct JMObjectiveSubsystem_eventGetObjectiveState_Parms
	{
		FGameplayTag ObjectiveId;
		FJMObjectiveRuntimeState OutState;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetObjectiveState constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutState;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetObjectiveState constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetObjectiveState Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveState_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveSubsystem_eventGetObjectiveState_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveState_Statics::NewProp_OutState = { "OutState", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveSubsystem_eventGetObjectiveState_Parms, OutState), Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, METADATA_PARAMS(0, nullptr) }; // 4088304728
void Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveSubsystem_eventGetObjectiveState_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveSubsystem_eventGetObjectiveState_Parms), &Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveState_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveState_Statics::NewProp_OutState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveState_Statics::PropPointers) < 2048);
// ********** End Function GetObjectiveState Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveSubsystem, nullptr, "GetObjectiveState", 	Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveState_Statics::JMObjectiveSubsystem_eventGetObjectiveState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveState_Statics::JMObjectiveSubsystem_eventGetObjectiveState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveSubsystem::execGetObjectiveState)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_GET_STRUCT_REF(FJMObjectiveRuntimeState,Z_Param_Out_OutState);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetObjectiveState(Z_Param_ObjectiveId,Z_Param_Out_OutState);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveSubsystem Function GetObjectiveState ***************************

// ********** Begin Class UJMObjectiveSubsystem Function IsObjectiveActive *************************
struct Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveActive_Statics
{
	struct JMObjectiveSubsystem_eventIsObjectiveActive_Parms
	{
		FGameplayTag ObjectiveId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsObjectiveActive constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsObjectiveActive constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsObjectiveActive Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveActive_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveSubsystem_eventIsObjectiveActive_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveActive_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveSubsystem_eventIsObjectiveActive_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveActive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveSubsystem_eventIsObjectiveActive_Parms), &Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveActive_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveActive_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveActive_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveActive_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveActive_Statics::PropPointers) < 2048);
// ********** End Function IsObjectiveActive Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveActive_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveSubsystem, nullptr, "IsObjectiveActive", 	Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveActive_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveActive_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveActive_Statics::JMObjectiveSubsystem_eventIsObjectiveActive_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveActive_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveActive_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveActive_Statics::JMObjectiveSubsystem_eventIsObjectiveActive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveActive()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveActive_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveSubsystem::execIsObjectiveActive)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsObjectiveActive(Z_Param_ObjectiveId);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveSubsystem Function IsObjectiveActive ***************************

// ********** Begin Class UJMObjectiveSubsystem Function IsObjectiveCompleted **********************
struct Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveCompleted_Statics
{
	struct JMObjectiveSubsystem_eventIsObjectiveCompleted_Parms
	{
		FGameplayTag ObjectiveId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsObjectiveCompleted constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsObjectiveCompleted constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsObjectiveCompleted Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveCompleted_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveSubsystem_eventIsObjectiveCompleted_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveCompleted_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveSubsystem_eventIsObjectiveCompleted_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveCompleted_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveSubsystem_eventIsObjectiveCompleted_Parms), &Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveCompleted_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveCompleted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveCompleted_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveCompleted_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveCompleted_Statics::PropPointers) < 2048);
// ********** End Function IsObjectiveCompleted Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveCompleted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveSubsystem, nullptr, "IsObjectiveCompleted", 	Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveCompleted_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveCompleted_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveCompleted_Statics::JMObjectiveSubsystem_eventIsObjectiveCompleted_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveCompleted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveCompleted_Statics::JMObjectiveSubsystem_eventIsObjectiveCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveSubsystem::execIsObjectiveCompleted)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsObjectiveCompleted(Z_Param_ObjectiveId);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveSubsystem Function IsObjectiveCompleted ************************

// ********** Begin Class UJMObjectiveSubsystem Function RegisterObjective *************************
struct Z_Construct_UFunction_UJMObjectiveSubsystem_RegisterObjective_Statics
{
	struct JMObjectiveSubsystem_eventRegisterObjective_Parms
	{
		UJMObjectiveDefinition* Definition;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RegisterObjective constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Definition;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RegisterObjective constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RegisterObjective Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_RegisterObjective_Statics::NewProp_Definition = { "Definition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveSubsystem_eventRegisterObjective_Parms, Definition), Z_Construct_UClass_UJMObjectiveDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UJMObjectiveSubsystem_RegisterObjective_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveSubsystem_eventRegisterObjective_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_RegisterObjective_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveSubsystem_eventRegisterObjective_Parms), &Z_Construct_UFunction_UJMObjectiveSubsystem_RegisterObjective_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveSubsystem_RegisterObjective_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_RegisterObjective_Statics::NewProp_Definition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_RegisterObjective_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_RegisterObjective_Statics::PropPointers) < 2048);
// ********** End Function RegisterObjective Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveSubsystem_RegisterObjective_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveSubsystem, nullptr, "RegisterObjective", 	Z_Construct_UFunction_UJMObjectiveSubsystem_RegisterObjective_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_RegisterObjective_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_RegisterObjective_Statics::JMObjectiveSubsystem_eventRegisterObjective_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_RegisterObjective_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveSubsystem_RegisterObjective_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_RegisterObjective_Statics::JMObjectiveSubsystem_eventRegisterObjective_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveSubsystem_RegisterObjective()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveSubsystem_RegisterObjective_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveSubsystem::execRegisterObjective)
{
	P_GET_OBJECT(UJMObjectiveDefinition,Z_Param_Definition);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->RegisterObjective(Z_Param_Definition);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveSubsystem Function RegisterObjective ***************************

// ********** Begin Class UJMObjectiveSubsystem Function ResetObjective ****************************
struct Z_Construct_UFunction_UJMObjectiveSubsystem_ResetObjective_Statics
{
	struct JMObjectiveSubsystem_eventResetObjective_Parms
	{
		FGameplayTag ObjectiveId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResetObjective constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ResetObjective constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ResetObjective Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_ResetObjective_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveSubsystem_eventResetObjective_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UJMObjectiveSubsystem_ResetObjective_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveSubsystem_eventResetObjective_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_ResetObjective_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveSubsystem_eventResetObjective_Parms), &Z_Construct_UFunction_UJMObjectiveSubsystem_ResetObjective_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveSubsystem_ResetObjective_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_ResetObjective_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_ResetObjective_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_ResetObjective_Statics::PropPointers) < 2048);
// ********** End Function ResetObjective Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveSubsystem_ResetObjective_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveSubsystem, nullptr, "ResetObjective", 	Z_Construct_UFunction_UJMObjectiveSubsystem_ResetObjective_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_ResetObjective_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_ResetObjective_Statics::JMObjectiveSubsystem_eventResetObjective_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_ResetObjective_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveSubsystem_ResetObjective_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_ResetObjective_Statics::JMObjectiveSubsystem_eventResetObjective_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveSubsystem_ResetObjective()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveSubsystem_ResetObjective_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveSubsystem::execResetObjective)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ResetObjective(Z_Param_ObjectiveId);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveSubsystem Function ResetObjective ******************************

// ********** Begin Class UJMObjectiveSubsystem Function RestoreObjectiveStates ********************
struct Z_Construct_UFunction_UJMObjectiveSubsystem_RestoreObjectiveStates_Statics
{
	struct JMObjectiveSubsystem_eventRestoreObjectiveStates_Parms
	{
		TArray<FJMObjectiveSaveData> SavedStates;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective|Save" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedStates_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RestoreObjectiveStates constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SavedStates_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SavedStates;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RestoreObjectiveStates constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RestoreObjectiveStates Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_RestoreObjectiveStates_Statics::NewProp_SavedStates_Inner = { "SavedStates", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FJMObjectiveSaveData, METADATA_PARAMS(0, nullptr) }; // 220837192
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_RestoreObjectiveStates_Statics::NewProp_SavedStates = { "SavedStates", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveSubsystem_eventRestoreObjectiveStates_Parms, SavedStates), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedStates_MetaData), NewProp_SavedStates_MetaData) }; // 220837192
void Z_Construct_UFunction_UJMObjectiveSubsystem_RestoreObjectiveStates_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveSubsystem_eventRestoreObjectiveStates_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_RestoreObjectiveStates_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveSubsystem_eventRestoreObjectiveStates_Parms), &Z_Construct_UFunction_UJMObjectiveSubsystem_RestoreObjectiveStates_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveSubsystem_RestoreObjectiveStates_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_RestoreObjectiveStates_Statics::NewProp_SavedStates_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_RestoreObjectiveStates_Statics::NewProp_SavedStates,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_RestoreObjectiveStates_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_RestoreObjectiveStates_Statics::PropPointers) < 2048);
// ********** End Function RestoreObjectiveStates Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveSubsystem_RestoreObjectiveStates_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveSubsystem, nullptr, "RestoreObjectiveStates", 	Z_Construct_UFunction_UJMObjectiveSubsystem_RestoreObjectiveStates_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_RestoreObjectiveStates_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_RestoreObjectiveStates_Statics::JMObjectiveSubsystem_eventRestoreObjectiveStates_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_RestoreObjectiveStates_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveSubsystem_RestoreObjectiveStates_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_RestoreObjectiveStates_Statics::JMObjectiveSubsystem_eventRestoreObjectiveStates_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveSubsystem_RestoreObjectiveStates()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveSubsystem_RestoreObjectiveStates_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveSubsystem::execRestoreObjectiveStates)
{
	P_GET_TARRAY_REF(FJMObjectiveSaveData,Z_Param_Out_SavedStates);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->RestoreObjectiveStates(Z_Param_Out_SavedStates);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveSubsystem Function RestoreObjectiveStates **********************

// ********** Begin Class UJMObjectiveSubsystem Function UnregisterObjective ***********************
struct Z_Construct_UFunction_UJMObjectiveSubsystem_UnregisterObjective_Statics
{
	struct JMObjectiveSubsystem_eventUnregisterObjective_Parms
	{
		FGameplayTag ObjectiveId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function UnregisterObjective constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UnregisterObjective constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UnregisterObjective Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_UnregisterObjective_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveSubsystem_eventUnregisterObjective_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UJMObjectiveSubsystem_UnregisterObjective_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveSubsystem_eventUnregisterObjective_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveSubsystem_UnregisterObjective_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveSubsystem_eventUnregisterObjective_Parms), &Z_Construct_UFunction_UJMObjectiveSubsystem_UnregisterObjective_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveSubsystem_UnregisterObjective_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_UnregisterObjective_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveSubsystem_UnregisterObjective_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_UnregisterObjective_Statics::PropPointers) < 2048);
// ********** End Function UnregisterObjective Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveSubsystem_UnregisterObjective_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveSubsystem, nullptr, "UnregisterObjective", 	Z_Construct_UFunction_UJMObjectiveSubsystem_UnregisterObjective_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_UnregisterObjective_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_UnregisterObjective_Statics::JMObjectiveSubsystem_eventUnregisterObjective_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveSubsystem_UnregisterObjective_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveSubsystem_UnregisterObjective_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveSubsystem_UnregisterObjective_Statics::JMObjectiveSubsystem_eventUnregisterObjective_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveSubsystem_UnregisterObjective()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveSubsystem_UnregisterObjective_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveSubsystem::execUnregisterObjective)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_ObjectiveId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->UnregisterObjective(Z_Param_ObjectiveId);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveSubsystem Function UnregisterObjective *************************

// ********** Begin Class UJMObjectiveSubsystem ****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMObjectiveSubsystem;
UClass* UJMObjectiveSubsystem::GetPrivateStaticClass()
{
	using TClass = UJMObjectiveSubsystem;
	if (!Z_Registration_Info_UClass_UJMObjectiveSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMObjectiveSubsystem"),
			Z_Registration_Info_UClass_UJMObjectiveSubsystem.InnerSingleton,
			StaticRegisterNativesUJMObjectiveSubsystem,
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
	return Z_Registration_Info_UClass_UJMObjectiveSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMObjectiveSubsystem_NoRegister()
{
	return UJMObjectiveSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMObjectiveSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Subsystems/JMObjectiveSubsystem.h" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnObjectiveRegistered_MetaData[] = {
		{ "Category", "JM Objective|Events" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnObjectiveActivated_MetaData[] = {
		{ "Category", "JM Objective|Events" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnObjectiveProgressed_MetaData[] = {
		{ "Category", "JM Objective|Events" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnObjectiveCompleted_MetaData[] = {
		{ "Category", "JM Objective|Events" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnObjectiveFailed_MetaData[] = {
		{ "Category", "JM Objective|Events" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnObjectiveDeactivated_MetaData[] = {
		{ "Category", "JM Objective|Events" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnObjectiveReset_MetaData[] = {
		{ "Category", "JM Objective|Events" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnObjectiveRemoved_MetaData[] = {
		{ "Category", "JM Objective|Events" },
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectiveStates_MetaData[] = {
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedEventSubsystem_MetaData[] = {
		{ "ModuleRelativePath", "Public/Subsystems/JMObjectiveSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMObjectiveSubsystem constinit property declarations ********************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnObjectiveRegistered;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnObjectiveActivated;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnObjectiveProgressed;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnObjectiveCompleted;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnObjectiveFailed;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnObjectiveDeactivated;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnObjectiveReset;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnObjectiveRemoved;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveStates_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveStates_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ObjectiveStates;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CachedEventSubsystem;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMObjectiveSubsystem constinit property declarations **********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ActivateObjective"), .Pointer = &UJMObjectiveSubsystem::execActivateObjective },
		{ .NameUTF8 = UTF8TEXT("AddObjectiveProgress"), .Pointer = &UJMObjectiveSubsystem::execAddObjectiveProgress },
		{ .NameUTF8 = UTF8TEXT("CaptureObjectiveStates"), .Pointer = &UJMObjectiveSubsystem::execCaptureObjectiveStates },
		{ .NameUTF8 = UTF8TEXT("CompleteObjective"), .Pointer = &UJMObjectiveSubsystem::execCompleteObjective },
		{ .NameUTF8 = UTF8TEXT("DeactivateObjective"), .Pointer = &UJMObjectiveSubsystem::execDeactivateObjective },
		{ .NameUTF8 = UTF8TEXT("FailObjective"), .Pointer = &UJMObjectiveSubsystem::execFailObjective },
		{ .NameUTF8 = UTF8TEXT("GetActiveObjectives"), .Pointer = &UJMObjectiveSubsystem::execGetActiveObjectives },
		{ .NameUTF8 = UTF8TEXT("GetCompletedObjectives"), .Pointer = &UJMObjectiveSubsystem::execGetCompletedObjectives },
		{ .NameUTF8 = UTF8TEXT("GetObjectiveProgress"), .Pointer = &UJMObjectiveSubsystem::execGetObjectiveProgress },
		{ .NameUTF8 = UTF8TEXT("GetObjectiveState"), .Pointer = &UJMObjectiveSubsystem::execGetObjectiveState },
		{ .NameUTF8 = UTF8TEXT("IsObjectiveActive"), .Pointer = &UJMObjectiveSubsystem::execIsObjectiveActive },
		{ .NameUTF8 = UTF8TEXT("IsObjectiveCompleted"), .Pointer = &UJMObjectiveSubsystem::execIsObjectiveCompleted },
		{ .NameUTF8 = UTF8TEXT("RegisterObjective"), .Pointer = &UJMObjectiveSubsystem::execRegisterObjective },
		{ .NameUTF8 = UTF8TEXT("ResetObjective"), .Pointer = &UJMObjectiveSubsystem::execResetObjective },
		{ .NameUTF8 = UTF8TEXT("RestoreObjectiveStates"), .Pointer = &UJMObjectiveSubsystem::execRestoreObjectiveStates },
		{ .NameUTF8 = UTF8TEXT("UnregisterObjective"), .Pointer = &UJMObjectiveSubsystem::execUnregisterObjective },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMObjectiveSubsystem_ActivateObjective, "ActivateObjective" }, // 3730264382
		{ &Z_Construct_UFunction_UJMObjectiveSubsystem_AddObjectiveProgress, "AddObjectiveProgress" }, // 2774533161
		{ &Z_Construct_UFunction_UJMObjectiveSubsystem_CaptureObjectiveStates, "CaptureObjectiveStates" }, // 239220534
		{ &Z_Construct_UFunction_UJMObjectiveSubsystem_CompleteObjective, "CompleteObjective" }, // 4232422775
		{ &Z_Construct_UFunction_UJMObjectiveSubsystem_DeactivateObjective, "DeactivateObjective" }, // 250310283
		{ &Z_Construct_UFunction_UJMObjectiveSubsystem_FailObjective, "FailObjective" }, // 527585882
		{ &Z_Construct_UFunction_UJMObjectiveSubsystem_GetActiveObjectives, "GetActiveObjectives" }, // 3657254351
		{ &Z_Construct_UFunction_UJMObjectiveSubsystem_GetCompletedObjectives, "GetCompletedObjectives" }, // 958354195
		{ &Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveProgress, "GetObjectiveProgress" }, // 145154343
		{ &Z_Construct_UFunction_UJMObjectiveSubsystem_GetObjectiveState, "GetObjectiveState" }, // 3513394474
		{ &Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveActive, "IsObjectiveActive" }, // 2338459297
		{ &Z_Construct_UFunction_UJMObjectiveSubsystem_IsObjectiveCompleted, "IsObjectiveCompleted" }, // 2929540871
		{ &Z_Construct_UFunction_UJMObjectiveSubsystem_RegisterObjective, "RegisterObjective" }, // 2216069822
		{ &Z_Construct_UFunction_UJMObjectiveSubsystem_ResetObjective, "ResetObjective" }, // 1280822591
		{ &Z_Construct_UFunction_UJMObjectiveSubsystem_RestoreObjectiveStates, "RestoreObjectiveStates" }, // 1386990039
		{ &Z_Construct_UFunction_UJMObjectiveSubsystem_UnregisterObjective, "UnregisterObjective" }, // 2374211974
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMObjectiveSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMObjectiveSubsystem_Statics

// ********** Begin Class UJMObjectiveSubsystem Property Definitions *******************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_OnObjectiveRegistered = { "OnObjectiveRegistered", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveSubsystem, OnObjectiveRegistered), Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnObjectiveRegistered_MetaData), NewProp_OnObjectiveRegistered_MetaData) }; // 2668633666
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_OnObjectiveActivated = { "OnObjectiveActivated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveSubsystem, OnObjectiveActivated), Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnObjectiveActivated_MetaData), NewProp_OnObjectiveActivated_MetaData) }; // 2668633666
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_OnObjectiveProgressed = { "OnObjectiveProgressed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveSubsystem, OnObjectiveProgressed), Z_Construct_UDelegateFunction_JMObjective_JMObjectiveProgressedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnObjectiveProgressed_MetaData), NewProp_OnObjectiveProgressed_MetaData) }; // 1059743107
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_OnObjectiveCompleted = { "OnObjectiveCompleted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveSubsystem, OnObjectiveCompleted), Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnObjectiveCompleted_MetaData), NewProp_OnObjectiveCompleted_MetaData) }; // 2668633666
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_OnObjectiveFailed = { "OnObjectiveFailed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveSubsystem, OnObjectiveFailed), Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnObjectiveFailed_MetaData), NewProp_OnObjectiveFailed_MetaData) }; // 2668633666
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_OnObjectiveDeactivated = { "OnObjectiveDeactivated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveSubsystem, OnObjectiveDeactivated), Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnObjectiveDeactivated_MetaData), NewProp_OnObjectiveDeactivated_MetaData) }; // 2668633666
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_OnObjectiveReset = { "OnObjectiveReset", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveSubsystem, OnObjectiveReset), Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnObjectiveReset_MetaData), NewProp_OnObjectiveReset_MetaData) }; // 2668633666
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_OnObjectiveRemoved = { "OnObjectiveRemoved", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveSubsystem, OnObjectiveRemoved), Z_Construct_UDelegateFunction_JMObjective_JMObjectiveStateChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnObjectiveRemoved_MetaData), NewProp_OnObjectiveRemoved_MetaData) }; // 2668633666
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_ObjectiveStates_ValueProp = { "ObjectiveStates", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, METADATA_PARAMS(0, nullptr) }; // 4088304728
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_ObjectiveStates_Key_KeyProp = { "ObjectiveStates_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_ObjectiveStates = { "ObjectiveStates", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveSubsystem, ObjectiveStates), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectiveStates_MetaData), NewProp_ObjectiveStates_MetaData) }; // 517357616 4088304728
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_CachedEventSubsystem = { "CachedEventSubsystem", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveSubsystem, CachedEventSubsystem), Z_Construct_UClass_UJMGameplayEventSubsystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedEventSubsystem_MetaData), NewProp_CachedEventSubsystem_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMObjectiveSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_OnObjectiveRegistered,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_OnObjectiveActivated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_OnObjectiveProgressed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_OnObjectiveCompleted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_OnObjectiveFailed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_OnObjectiveDeactivated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_OnObjectiveReset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_OnObjectiveRemoved,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_ObjectiveStates_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_ObjectiveStates_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_ObjectiveStates,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveSubsystem_Statics::NewProp_CachedEventSubsystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveSubsystem_Statics::PropPointers) < 2048);
// ********** End Class UJMObjectiveSubsystem Property Definitions *********************************
UObject* (*const Z_Construct_UClass_UJMObjectiveSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_JMObjective,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMObjectiveSubsystem_Statics::ClassParams = {
	&UJMObjectiveSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMObjectiveSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveSubsystem_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMObjectiveSubsystem_Statics::Class_MetaDataParams)
};
void UJMObjectiveSubsystem::StaticRegisterNativesUJMObjectiveSubsystem()
{
	UClass* Class = UJMObjectiveSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMObjectiveSubsystem_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMObjectiveSubsystem()
{
	if (!Z_Registration_Info_UClass_UJMObjectiveSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMObjectiveSubsystem.OuterSingleton, Z_Construct_UClass_UJMObjectiveSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMObjectiveSubsystem.OuterSingleton;
}
UJMObjectiveSubsystem::UJMObjectiveSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMObjectiveSubsystem);
UJMObjectiveSubsystem::~UJMObjectiveSubsystem() {}
// ********** End Class UJMObjectiveSubsystem ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveSubsystem_h__Script_JMObjective_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMObjectiveSubsystem, UJMObjectiveSubsystem::StaticClass, TEXT("UJMObjectiveSubsystem"), &Z_Registration_Info_UClass_UJMObjectiveSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMObjectiveSubsystem), 196907221U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveSubsystem_h__Script_JMObjective_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveSubsystem_h__Script_JMObjective_2292165636{
	TEXT("/Script/JMObjective"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveSubsystem_h__Script_JMObjective_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveSubsystem_h__Script_JMObjective_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
