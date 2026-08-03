// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actors/JMJumpScareTrigger.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "Types/JMJumpScareTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMJumpScareTrigger() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
JMJUMPSCARE_API UClass* Z_Construct_UClass_AJMJumpScareAnchor_NoRegister();
JMJUMPSCARE_API UClass* Z_Construct_UClass_AJMJumpScareTrigger();
JMJUMPSCARE_API UClass* Z_Construct_UClass_AJMJumpScareTrigger_NoRegister();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareDefinition_NoRegister();
JMJUMPSCARE_API UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScareOverlapFilter();
JMJUMPSCARE_API UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScareTriggerPolicy();
JMJUMPSCARE_API UScriptStruct* Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState();
UPackage* Z_Construct_UPackage__Script_JMJumpScare();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AJMJumpScareTrigger Function CaptureSaveState ****************************
struct Z_Construct_UFunction_AJMJumpScareTrigger_CaptureSaveState_Statics
{
	struct JMJumpScareTrigger_eventCaptureSaveState_Parms
	{
		FJMJumpScareTriggerSaveState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM JumpScare | Save" },
		{ "ModuleRelativePath", "Public/Actors/JMJumpScareTrigger.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CaptureSaveState constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CaptureSaveState constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CaptureSaveState Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AJMJumpScareTrigger_CaptureSaveState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMJumpScareTrigger_eventCaptureSaveState_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState, METADATA_PARAMS(0, nullptr) }; // 804623082
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AJMJumpScareTrigger_CaptureSaveState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AJMJumpScareTrigger_CaptureSaveState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AJMJumpScareTrigger_CaptureSaveState_Statics::PropPointers) < 2048);
// ********** End Function CaptureSaveState Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AJMJumpScareTrigger_CaptureSaveState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AJMJumpScareTrigger, nullptr, "CaptureSaveState", 	Z_Construct_UFunction_AJMJumpScareTrigger_CaptureSaveState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AJMJumpScareTrigger_CaptureSaveState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AJMJumpScareTrigger_CaptureSaveState_Statics::JMJumpScareTrigger_eventCaptureSaveState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AJMJumpScareTrigger_CaptureSaveState_Statics::Function_MetaDataParams), Z_Construct_UFunction_AJMJumpScareTrigger_CaptureSaveState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AJMJumpScareTrigger_CaptureSaveState_Statics::JMJumpScareTrigger_eventCaptureSaveState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AJMJumpScareTrigger_CaptureSaveState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AJMJumpScareTrigger_CaptureSaveState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AJMJumpScareTrigger::execCaptureSaveState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMJumpScareTriggerSaveState*)Z_Param__Result=P_THIS->CaptureSaveState();
	P_NATIVE_END;
}
// ********** End Class AJMJumpScareTrigger Function CaptureSaveState ******************************

// ********** Begin Class AJMJumpScareTrigger Function HandleBeginOverlap **************************
struct Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics
{
	struct JMJumpScareTrigger_eventHandleBeginOverlap_Parms
	{
		UPrimitiveComponent* OverlappedComponent;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComponent;
		int32 OtherBodyIndex;
		bool bFromSweep;
		FHitResult SweepResult;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Actors/JMJumpScareTrigger.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleBeginOverlap constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComponent;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
	static void NewProp_bFromSweep_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SweepResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleBeginOverlap constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleBeginOverlap Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMJumpScareTrigger_eventHandleBeginOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlappedComponent_MetaData), NewProp_OverlappedComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMJumpScareTrigger_eventHandleBeginOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::NewProp_OtherComponent = { "OtherComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMJumpScareTrigger_eventHandleBeginOverlap_Parms, OtherComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComponent_MetaData), NewProp_OtherComponent_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMJumpScareTrigger_eventHandleBeginOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::NewProp_bFromSweep_SetBit(void* Obj)
{
	((JMJumpScareTrigger_eventHandleBeginOverlap_Parms*)Obj)->bFromSweep = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMJumpScareTrigger_eventHandleBeginOverlap_Parms), &Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMJumpScareTrigger_eventHandleBeginOverlap_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SweepResult_MetaData), NewProp_SweepResult_MetaData) }; // 222120718
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::NewProp_OverlappedComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::NewProp_OtherComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::NewProp_OtherBodyIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::NewProp_bFromSweep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::NewProp_SweepResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::PropPointers) < 2048);
// ********** End Function HandleBeginOverlap Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AJMJumpScareTrigger, nullptr, "HandleBeginOverlap", 	Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::JMJumpScareTrigger_eventHandleBeginOverlap_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::Function_MetaDataParams), Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::JMJumpScareTrigger_eventHandleBeginOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AJMJumpScareTrigger::execHandleBeginOverlap)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComponent);
	P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
	P_GET_UBOOL(Z_Param_bFromSweep);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleBeginOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComponent,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
	P_NATIVE_END;
}
// ********** End Class AJMJumpScareTrigger Function HandleBeginOverlap ****************************

// ********** Begin Class AJMJumpScareTrigger Function ResetTrigger ********************************
struct Z_Construct_UFunction_AJMJumpScareTrigger_ResetTrigger_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Actors/JMJumpScareTrigger.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResetTrigger constinit property declarations **************************
// ********** End Function ResetTrigger constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AJMJumpScareTrigger_ResetTrigger_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AJMJumpScareTrigger, nullptr, "ResetTrigger", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AJMJumpScareTrigger_ResetTrigger_Statics::Function_MetaDataParams), Z_Construct_UFunction_AJMJumpScareTrigger_ResetTrigger_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AJMJumpScareTrigger_ResetTrigger()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AJMJumpScareTrigger_ResetTrigger_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AJMJumpScareTrigger::execResetTrigger)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetTrigger();
	P_NATIVE_END;
}
// ********** End Class AJMJumpScareTrigger Function ResetTrigger **********************************

// ********** Begin Class AJMJumpScareTrigger Function RestoreSaveState ****************************
struct Z_Construct_UFunction_AJMJumpScareTrigger_RestoreSaveState_Statics
{
	struct JMJumpScareTrigger_eventRestoreSaveState_Parms
	{
		FJMJumpScareTriggerSaveState SaveState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM JumpScare | Save" },
		{ "ModuleRelativePath", "Public/Actors/JMJumpScareTrigger.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SaveState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RestoreSaveState constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SaveState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RestoreSaveState constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RestoreSaveState Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AJMJumpScareTrigger_RestoreSaveState_Statics::NewProp_SaveState = { "SaveState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMJumpScareTrigger_eventRestoreSaveState_Parms, SaveState), Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SaveState_MetaData), NewProp_SaveState_MetaData) }; // 804623082
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AJMJumpScareTrigger_RestoreSaveState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AJMJumpScareTrigger_RestoreSaveState_Statics::NewProp_SaveState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AJMJumpScareTrigger_RestoreSaveState_Statics::PropPointers) < 2048);
// ********** End Function RestoreSaveState Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AJMJumpScareTrigger_RestoreSaveState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AJMJumpScareTrigger, nullptr, "RestoreSaveState", 	Z_Construct_UFunction_AJMJumpScareTrigger_RestoreSaveState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AJMJumpScareTrigger_RestoreSaveState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AJMJumpScareTrigger_RestoreSaveState_Statics::JMJumpScareTrigger_eventRestoreSaveState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AJMJumpScareTrigger_RestoreSaveState_Statics::Function_MetaDataParams), Z_Construct_UFunction_AJMJumpScareTrigger_RestoreSaveState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AJMJumpScareTrigger_RestoreSaveState_Statics::JMJumpScareTrigger_eventRestoreSaveState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AJMJumpScareTrigger_RestoreSaveState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AJMJumpScareTrigger_RestoreSaveState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AJMJumpScareTrigger::execRestoreSaveState)
{
	P_GET_STRUCT_REF(FJMJumpScareTriggerSaveState,Z_Param_Out_SaveState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RestoreSaveState(Z_Param_Out_SaveState);
	P_NATIVE_END;
}
// ********** End Class AJMJumpScareTrigger Function RestoreSaveState ******************************

// ********** Begin Class AJMJumpScareTrigger ******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AJMJumpScareTrigger;
UClass* AJMJumpScareTrigger::GetPrivateStaticClass()
{
	using TClass = AJMJumpScareTrigger;
	if (!Z_Registration_Info_UClass_AJMJumpScareTrigger.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMJumpScareTrigger"),
			Z_Registration_Info_UClass_AJMJumpScareTrigger.InnerSingleton,
			StaticRegisterNativesAJMJumpScareTrigger,
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
	return Z_Registration_Info_UClass_AJMJumpScareTrigger.InnerSingleton;
}
UClass* Z_Construct_UClass_AJMJumpScareTrigger_NoRegister()
{
	return AJMJumpScareTrigger::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AJMJumpScareTrigger_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DisplayName", "JM JumpScare Trigger" },
		{ "IncludePath", "Actors/JMJumpScareTrigger.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Actors/JMJumpScareTrigger.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TriggerVolume_MetaData[] = {
		{ "Category", "JM JumpScare | Trigger" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/JMJumpScareTrigger.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpScareDefinition_MetaData[] = {
		{ "Category", "JM JumpScare | Trigger" },
		{ "ModuleRelativePath", "Public/Actors/JMJumpScareTrigger.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpScareAnchor_MetaData[] = {
		{ "Category", "JM JumpScare | Trigger" },
		{ "ModuleRelativePath", "Public/Actors/JMJumpScareTrigger.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TriggerPolicy_MetaData[] = {
		{ "Category", "JM JumpScare | Trigger" },
		{ "ModuleRelativePath", "Public/Actors/JMJumpScareTrigger.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetActorFilter_MetaData[] = {
		{ "Category", "JM JumpScare | Trigger" },
		{ "ModuleRelativePath", "Public/Actors/JMJumpScareTrigger.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequiredActorTags_MetaData[] = {
		{ "Category", "JM JumpScare | Trigger" },
		{ "EditCondition", "TargetActorFilter==EJMJumpScareOverlapFilter::GameplayTags" },
		{ "ModuleRelativePath", "Public/Actors/JMJumpScareTrigger.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[] = {
		{ "Category", "JM JumpScare | Trigger" },
		{ "ModuleRelativePath", "Public/Actors/JMJumpScareTrigger.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TriggerId_MetaData[] = {
		{ "Categories", "JumpScare.Trigger" },
		{ "Category", "JM JumpScare | Save" },
		{ "ModuleRelativePath", "Public/Actors/JMJumpScareTrigger.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasTriggered_MetaData[] = {
		{ "Category", "JM JumpScare | Trigger" },
		{ "ModuleRelativePath", "Public/Actors/JMJumpScareTrigger.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AJMJumpScareTrigger constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TriggerVolume;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpScareDefinition;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpScareAnchor;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TriggerPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TriggerPolicy;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TargetActorFilter_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TargetActorFilter;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RequiredActorTags;
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TriggerId;
	static void NewProp_bHasTriggered_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasTriggered;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AJMJumpScareTrigger constinit property declarations ************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CaptureSaveState"), .Pointer = &AJMJumpScareTrigger::execCaptureSaveState },
		{ .NameUTF8 = UTF8TEXT("HandleBeginOverlap"), .Pointer = &AJMJumpScareTrigger::execHandleBeginOverlap },
		{ .NameUTF8 = UTF8TEXT("ResetTrigger"), .Pointer = &AJMJumpScareTrigger::execResetTrigger },
		{ .NameUTF8 = UTF8TEXT("RestoreSaveState"), .Pointer = &AJMJumpScareTrigger::execRestoreSaveState },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AJMJumpScareTrigger_CaptureSaveState, "CaptureSaveState" }, // 728329371
		{ &Z_Construct_UFunction_AJMJumpScareTrigger_HandleBeginOverlap, "HandleBeginOverlap" }, // 280397125
		{ &Z_Construct_UFunction_AJMJumpScareTrigger_ResetTrigger, "ResetTrigger" }, // 39349719
		{ &Z_Construct_UFunction_AJMJumpScareTrigger_RestoreSaveState, "RestoreSaveState" }, // 2773658615
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AJMJumpScareTrigger>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AJMJumpScareTrigger_Statics

// ********** Begin Class AJMJumpScareTrigger Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_TriggerVolume = { "TriggerVolume", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMJumpScareTrigger, TriggerVolume), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TriggerVolume_MetaData), NewProp_TriggerVolume_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_JumpScareDefinition = { "JumpScareDefinition", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMJumpScareTrigger, JumpScareDefinition), Z_Construct_UClass_UJMJumpScareDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpScareDefinition_MetaData), NewProp_JumpScareDefinition_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_JumpScareAnchor = { "JumpScareAnchor", nullptr, (EPropertyFlags)0x0114000000000815, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMJumpScareTrigger, JumpScareAnchor), Z_Construct_UClass_AJMJumpScareAnchor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpScareAnchor_MetaData), NewProp_JumpScareAnchor_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_TriggerPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_TriggerPolicy = { "TriggerPolicy", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMJumpScareTrigger, TriggerPolicy), Z_Construct_UEnum_JMJumpScare_EJMJumpScareTriggerPolicy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TriggerPolicy_MetaData), NewProp_TriggerPolicy_MetaData) }; // 453019027
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_TargetActorFilter_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_TargetActorFilter = { "TargetActorFilter", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMJumpScareTrigger, TargetActorFilter), Z_Construct_UEnum_JMJumpScare_EJMJumpScareOverlapFilter, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetActorFilter_MetaData), NewProp_TargetActorFilter_MetaData) }; // 2064440234
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_RequiredActorTags = { "RequiredActorTags", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMJumpScareTrigger, RequiredActorTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequiredActorTags_MetaData), NewProp_RequiredActorTags_MetaData) }; // 3438578166
void Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((AJMJumpScareTrigger*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AJMJumpScareTrigger), &Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_TriggerId = { "TriggerId", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMJumpScareTrigger, TriggerId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TriggerId_MetaData), NewProp_TriggerId_MetaData) }; // 517357616
void Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_bHasTriggered_SetBit(void* Obj)
{
	((AJMJumpScareTrigger*)Obj)->bHasTriggered = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_bHasTriggered = { "bHasTriggered", nullptr, (EPropertyFlags)0x0010000000022815, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AJMJumpScareTrigger), &Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_bHasTriggered_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasTriggered_MetaData), NewProp_bHasTriggered_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AJMJumpScareTrigger_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_TriggerVolume,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_JumpScareDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_JumpScareAnchor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_TriggerPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_TriggerPolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_TargetActorFilter_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_TargetActorFilter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_RequiredActorTags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_bEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_TriggerId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMJumpScareTrigger_Statics::NewProp_bHasTriggered,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AJMJumpScareTrigger_Statics::PropPointers) < 2048);
// ********** End Class AJMJumpScareTrigger Property Definitions ***********************************
UObject* (*const Z_Construct_UClass_AJMJumpScareTrigger_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_JMJumpScare,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AJMJumpScareTrigger_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AJMJumpScareTrigger_Statics::ClassParams = {
	&AJMJumpScareTrigger::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AJMJumpScareTrigger_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AJMJumpScareTrigger_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AJMJumpScareTrigger_Statics::Class_MetaDataParams), Z_Construct_UClass_AJMJumpScareTrigger_Statics::Class_MetaDataParams)
};
void AJMJumpScareTrigger::StaticRegisterNativesAJMJumpScareTrigger()
{
	UClass* Class = AJMJumpScareTrigger::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AJMJumpScareTrigger_Statics::Funcs));
}
UClass* Z_Construct_UClass_AJMJumpScareTrigger()
{
	if (!Z_Registration_Info_UClass_AJMJumpScareTrigger.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AJMJumpScareTrigger.OuterSingleton, Z_Construct_UClass_AJMJumpScareTrigger_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AJMJumpScareTrigger.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AJMJumpScareTrigger);
AJMJumpScareTrigger::~AJMJumpScareTrigger() {}
// ********** End Class AJMJumpScareTrigger ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Actors_JMJumpScareTrigger_h__Script_JMJumpScare_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AJMJumpScareTrigger, AJMJumpScareTrigger::StaticClass, TEXT("AJMJumpScareTrigger"), &Z_Registration_Info_UClass_AJMJumpScareTrigger, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AJMJumpScareTrigger), 1943004043U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Actors_JMJumpScareTrigger_h__Script_JMJumpScare_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Actors_JMJumpScareTrigger_h__Script_JMJumpScare_2845570009{
	TEXT("/Script/JMJumpScare"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Actors_JMJumpScareTrigger_h__Script_JMJumpScare_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Actors_JMJumpScareTrigger_h__Script_JMJumpScare_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
