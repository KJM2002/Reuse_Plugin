// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/JMHideInteractorComponent.h"
#include "Types/JMHideTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMHideInteractorComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideInteractorComponent();
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideInteractorComponent_NoRegister();
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideSpotComponent_NoRegister();
JMHIDERUNTIME_API UEnum* Z_Construct_UEnum_JMHideRuntime_EJMHideFailureCode();
JMHIDERUNTIME_API UEnum* Z_Construct_UEnum_JMHideRuntime_EJMHidePhase();
JMHIDERUNTIME_API UFunction* Z_Construct_UDelegateFunction_JMHideRuntime_JMHideExitPromptChangedSignature__DelegateSignature();
JMHIDERUNTIME_API UFunction* Z_Construct_UDelegateFunction_JMHideRuntime_JMHideFailedSignature__DelegateSignature();
JMHIDERUNTIME_API UFunction* Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature();
JMHIDERUNTIME_API UFunction* Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSessionEventSignature__DelegateSignature();
JMHIDERUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMHideRequest();
JMHIDERUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMHideResult();
UPackage* Z_Construct_UPackage__Script_JMHideRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FJMHidePhaseChangedSignature ******************************************
struct Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature_Statics
{
	struct _Script_JMHideRuntime_eventJMHidePhaseChangedSignature_Parms
	{
		FGuid SessionId;
		EJMHidePhase OldPhase;
		EJMHidePhase NewPhase;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/JMHideInteractorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMHidePhaseChangedSignature constinit property declarations **********
	static const UECodeGen_Private::FStructPropertyParams NewProp_SessionId;
	static const UECodeGen_Private::FBytePropertyParams NewProp_OldPhase_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OldPhase;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewPhase_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewPhase;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMHidePhaseChangedSignature constinit property declarations ************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMHidePhaseChangedSignature Property Definitions *********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature_Statics::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMHideRuntime_eventJMHidePhaseChangedSignature_Parms, SessionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature_Statics::NewProp_OldPhase_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature_Statics::NewProp_OldPhase = { "OldPhase", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMHideRuntime_eventJMHidePhaseChangedSignature_Parms, OldPhase), Z_Construct_UEnum_JMHideRuntime_EJMHidePhase, METADATA_PARAMS(0, nullptr) }; // 1560254620
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature_Statics::NewProp_NewPhase_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature_Statics::NewProp_NewPhase = { "NewPhase", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMHideRuntime_eventJMHidePhaseChangedSignature_Parms, NewPhase), Z_Construct_UEnum_JMHideRuntime_EJMHidePhase, METADATA_PARAMS(0, nullptr) }; // 1560254620
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature_Statics::NewProp_SessionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature_Statics::NewProp_OldPhase_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature_Statics::NewProp_OldPhase,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature_Statics::NewProp_NewPhase_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature_Statics::NewProp_NewPhase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMHidePhaseChangedSignature Property Definitions ***********************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMHideRuntime, nullptr, "JMHidePhaseChangedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature_Statics::_Script_JMHideRuntime_eventJMHidePhaseChangedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature_Statics::_Script_JMHideRuntime_eventJMHidePhaseChangedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMHidePhaseChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMHidePhaseChangedSignature, FGuid SessionId, EJMHidePhase OldPhase, EJMHidePhase NewPhase)
{
	struct _Script_JMHideRuntime_eventJMHidePhaseChangedSignature_Parms
	{
		FGuid SessionId;
		EJMHidePhase OldPhase;
		EJMHidePhase NewPhase;
	};
	_Script_JMHideRuntime_eventJMHidePhaseChangedSignature_Parms Parms;
	Parms.SessionId=SessionId;
	Parms.OldPhase=OldPhase;
	Parms.NewPhase=NewPhase;
	JMHidePhaseChangedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMHidePhaseChangedSignature ********************************************

// ********** Begin Delegate FJMHideSessionEventSignature ******************************************
struct Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSessionEventSignature__DelegateSignature_Statics
{
	struct _Script_JMHideRuntime_eventJMHideSessionEventSignature_Parms
	{
		FGuid SessionId;
		UJMHideSpotComponent* HideSpot;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/JMHideInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HideSpot_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMHideSessionEventSignature constinit property declarations **********
	static const UECodeGen_Private::FStructPropertyParams NewProp_SessionId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HideSpot;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMHideSessionEventSignature constinit property declarations ************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMHideSessionEventSignature Property Definitions *********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSessionEventSignature__DelegateSignature_Statics::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMHideRuntime_eventJMHideSessionEventSignature_Parms, SessionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSessionEventSignature__DelegateSignature_Statics::NewProp_HideSpot = { "HideSpot", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMHideRuntime_eventJMHideSessionEventSignature_Parms, HideSpot), Z_Construct_UClass_UJMHideSpotComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HideSpot_MetaData), NewProp_HideSpot_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSessionEventSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSessionEventSignature__DelegateSignature_Statics::NewProp_SessionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSessionEventSignature__DelegateSignature_Statics::NewProp_HideSpot,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSessionEventSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMHideSessionEventSignature Property Definitions ***********************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSessionEventSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMHideRuntime, nullptr, "JMHideSessionEventSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSessionEventSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSessionEventSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSessionEventSignature__DelegateSignature_Statics::_Script_JMHideRuntime_eventJMHideSessionEventSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSessionEventSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSessionEventSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSessionEventSignature__DelegateSignature_Statics::_Script_JMHideRuntime_eventJMHideSessionEventSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSessionEventSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSessionEventSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMHideSessionEventSignature_DelegateWrapper(const FMulticastScriptDelegate& JMHideSessionEventSignature, FGuid SessionId, UJMHideSpotComponent* HideSpot)
{
	struct _Script_JMHideRuntime_eventJMHideSessionEventSignature_Parms
	{
		FGuid SessionId;
		UJMHideSpotComponent* HideSpot;
	};
	_Script_JMHideRuntime_eventJMHideSessionEventSignature_Parms Parms;
	Parms.SessionId=SessionId;
	Parms.HideSpot=HideSpot;
	JMHideSessionEventSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMHideSessionEventSignature ********************************************

// ********** Begin Delegate FJMHideExitPromptChangedSignature *************************************
struct Z_Construct_UDelegateFunction_JMHideRuntime_JMHideExitPromptChangedSignature__DelegateSignature_Statics
{
	struct _Script_JMHideRuntime_eventJMHideExitPromptChangedSignature_Parms
	{
		FText Prompt;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/JMHideInteractorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMHideExitPromptChangedSignature constinit property declarations *****
	static const UECodeGen_Private::FTextPropertyParams NewProp_Prompt;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMHideExitPromptChangedSignature constinit property declarations *******
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMHideExitPromptChangedSignature Property Definitions ****************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UDelegateFunction_JMHideRuntime_JMHideExitPromptChangedSignature__DelegateSignature_Statics::NewProp_Prompt = { "Prompt", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMHideRuntime_eventJMHideExitPromptChangedSignature_Parms, Prompt), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMHideRuntime_JMHideExitPromptChangedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMHideRuntime_JMHideExitPromptChangedSignature__DelegateSignature_Statics::NewProp_Prompt,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMHideRuntime_JMHideExitPromptChangedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMHideExitPromptChangedSignature Property Definitions ******************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMHideRuntime_JMHideExitPromptChangedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMHideRuntime, nullptr, "JMHideExitPromptChangedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_JMHideRuntime_JMHideExitPromptChangedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMHideRuntime_JMHideExitPromptChangedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMHideRuntime_JMHideExitPromptChangedSignature__DelegateSignature_Statics::_Script_JMHideRuntime_eventJMHideExitPromptChangedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMHideRuntime_JMHideExitPromptChangedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMHideRuntime_JMHideExitPromptChangedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMHideRuntime_JMHideExitPromptChangedSignature__DelegateSignature_Statics::_Script_JMHideRuntime_eventJMHideExitPromptChangedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMHideRuntime_JMHideExitPromptChangedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMHideRuntime_JMHideExitPromptChangedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMHideExitPromptChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMHideExitPromptChangedSignature, const FText& Prompt)
{
	struct _Script_JMHideRuntime_eventJMHideExitPromptChangedSignature_Parms
	{
		FText Prompt;
	};
	_Script_JMHideRuntime_eventJMHideExitPromptChangedSignature_Parms Parms;
	Parms.Prompt=Prompt;
	JMHideExitPromptChangedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMHideExitPromptChangedSignature ***************************************

// ********** Begin Delegate FJMHideFailedSignature ************************************************
struct Z_Construct_UDelegateFunction_JMHideRuntime_JMHideFailedSignature__DelegateSignature_Statics
{
	struct _Script_JMHideRuntime_eventJMHideFailedSignature_Parms
	{
		FGuid SessionId;
		EJMHideFailureCode Failure;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/JMHideInteractorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMHideFailedSignature constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SessionId;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Failure_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Failure;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMHideFailedSignature constinit property declarations ******************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMHideFailedSignature Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_JMHideRuntime_JMHideFailedSignature__DelegateSignature_Statics::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMHideRuntime_eventJMHideFailedSignature_Parms, SessionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_JMHideRuntime_JMHideFailedSignature__DelegateSignature_Statics::NewProp_Failure_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_JMHideRuntime_JMHideFailedSignature__DelegateSignature_Statics::NewProp_Failure = { "Failure", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMHideRuntime_eventJMHideFailedSignature_Parms, Failure), Z_Construct_UEnum_JMHideRuntime_EJMHideFailureCode, METADATA_PARAMS(0, nullptr) }; // 71457987
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMHideRuntime_JMHideFailedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMHideRuntime_JMHideFailedSignature__DelegateSignature_Statics::NewProp_SessionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMHideRuntime_JMHideFailedSignature__DelegateSignature_Statics::NewProp_Failure_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMHideRuntime_JMHideFailedSignature__DelegateSignature_Statics::NewProp_Failure,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMHideRuntime_JMHideFailedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMHideFailedSignature Property Definitions *****************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMHideRuntime_JMHideFailedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMHideRuntime, nullptr, "JMHideFailedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_JMHideRuntime_JMHideFailedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMHideRuntime_JMHideFailedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMHideRuntime_JMHideFailedSignature__DelegateSignature_Statics::_Script_JMHideRuntime_eventJMHideFailedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMHideRuntime_JMHideFailedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMHideRuntime_JMHideFailedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMHideRuntime_JMHideFailedSignature__DelegateSignature_Statics::_Script_JMHideRuntime_eventJMHideFailedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMHideRuntime_JMHideFailedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMHideRuntime_JMHideFailedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMHideFailedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMHideFailedSignature, FGuid SessionId, EJMHideFailureCode Failure)
{
	struct _Script_JMHideRuntime_eventJMHideFailedSignature_Parms
	{
		FGuid SessionId;
		EJMHideFailureCode Failure;
	};
	_Script_JMHideRuntime_eventJMHideFailedSignature_Parms Parms;
	Parms.SessionId=SessionId;
	Parms.Failure=Failure;
	JMHideFailedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMHideFailedSignature **************************************************

// ********** Begin Class UJMHideInteractorComponent Function CancelCurrentTransition **************
struct Z_Construct_UFunction_UJMHideInteractorComponent_CancelCurrentTransition_Statics
{
	struct JMHideInteractorComponent_eventCancelCurrentTransition_Parms
	{
		FJMHideResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Components/JMHideInteractorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CancelCurrentTransition constinit property declarations ***************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CancelCurrentTransition constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CancelCurrentTransition Property Definitions **************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMHideInteractorComponent_CancelCurrentTransition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMHideInteractorComponent_eventCancelCurrentTransition_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMHideResult, METADATA_PARAMS(0, nullptr) }; // 1459112883
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMHideInteractorComponent_CancelCurrentTransition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideInteractorComponent_CancelCurrentTransition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_CancelCurrentTransition_Statics::PropPointers) < 2048);
// ********** End Function CancelCurrentTransition Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMHideInteractorComponent_CancelCurrentTransition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMHideInteractorComponent, nullptr, "CancelCurrentTransition", 	Z_Construct_UFunction_UJMHideInteractorComponent_CancelCurrentTransition_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_CancelCurrentTransition_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMHideInteractorComponent_CancelCurrentTransition_Statics::JMHideInteractorComponent_eventCancelCurrentTransition_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_CancelCurrentTransition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMHideInteractorComponent_CancelCurrentTransition_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMHideInteractorComponent_CancelCurrentTransition_Statics::JMHideInteractorComponent_eventCancelCurrentTransition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMHideInteractorComponent_CancelCurrentTransition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMHideInteractorComponent_CancelCurrentTransition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMHideInteractorComponent::execCancelCurrentTransition)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMHideResult*)Z_Param__Result=P_THIS->CancelCurrentTransition();
	P_NATIVE_END;
}
// ********** End Class UJMHideInteractorComponent Function CancelCurrentTransition ****************

// ********** Begin Class UJMHideInteractorComponent Function ForceExit ****************************
struct Z_Construct_UFunction_UJMHideInteractorComponent_ForceExit_Statics
{
	struct JMHideInteractorComponent_eventForceExit_Parms
	{
		bool bIgnoreCollisionPolicy;
		FJMHideResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Hide" },
		{ "CPP_Default_bIgnoreCollisionPolicy", "true" },
		{ "ModuleRelativePath", "Public/Components/JMHideInteractorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ForceExit constinit property declarations *****************************
	static void NewProp_bIgnoreCollisionPolicy_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIgnoreCollisionPolicy;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ForceExit constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ForceExit Property Definitions ****************************************
void Z_Construct_UFunction_UJMHideInteractorComponent_ForceExit_Statics::NewProp_bIgnoreCollisionPolicy_SetBit(void* Obj)
{
	((JMHideInteractorComponent_eventForceExit_Parms*)Obj)->bIgnoreCollisionPolicy = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMHideInteractorComponent_ForceExit_Statics::NewProp_bIgnoreCollisionPolicy = { "bIgnoreCollisionPolicy", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMHideInteractorComponent_eventForceExit_Parms), &Z_Construct_UFunction_UJMHideInteractorComponent_ForceExit_Statics::NewProp_bIgnoreCollisionPolicy_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMHideInteractorComponent_ForceExit_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMHideInteractorComponent_eventForceExit_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMHideResult, METADATA_PARAMS(0, nullptr) }; // 1459112883
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMHideInteractorComponent_ForceExit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideInteractorComponent_ForceExit_Statics::NewProp_bIgnoreCollisionPolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideInteractorComponent_ForceExit_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_ForceExit_Statics::PropPointers) < 2048);
// ********** End Function ForceExit Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMHideInteractorComponent_ForceExit_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMHideInteractorComponent, nullptr, "ForceExit", 	Z_Construct_UFunction_UJMHideInteractorComponent_ForceExit_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_ForceExit_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMHideInteractorComponent_ForceExit_Statics::JMHideInteractorComponent_eventForceExit_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_ForceExit_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMHideInteractorComponent_ForceExit_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMHideInteractorComponent_ForceExit_Statics::JMHideInteractorComponent_eventForceExit_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMHideInteractorComponent_ForceExit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMHideInteractorComponent_ForceExit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMHideInteractorComponent::execForceExit)
{
	P_GET_UBOOL(Z_Param_bIgnoreCollisionPolicy);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMHideResult*)Z_Param__Result=P_THIS->ForceExit(Z_Param_bIgnoreCollisionPolicy);
	P_NATIVE_END;
}
// ********** End Class UJMHideInteractorComponent Function ForceExit ******************************

// ********** Begin Class UJMHideInteractorComponent Function GetCurrentHideSpot *******************
struct Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentHideSpot_Statics
{
	struct JMHideInteractorComponent_eventGetCurrentHideSpot_Parms
	{
		UJMHideSpotComponent* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Components/JMHideInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentHideSpot constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentHideSpot constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentHideSpot Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentHideSpot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMHideInteractorComponent_eventGetCurrentHideSpot_Parms, ReturnValue), Z_Construct_UClass_UJMHideSpotComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentHideSpot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentHideSpot_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentHideSpot_Statics::PropPointers) < 2048);
// ********** End Function GetCurrentHideSpot Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentHideSpot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMHideInteractorComponent, nullptr, "GetCurrentHideSpot", 	Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentHideSpot_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentHideSpot_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentHideSpot_Statics::JMHideInteractorComponent_eventGetCurrentHideSpot_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentHideSpot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentHideSpot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentHideSpot_Statics::JMHideInteractorComponent_eventGetCurrentHideSpot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentHideSpot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentHideSpot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMHideInteractorComponent::execGetCurrentHideSpot)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UJMHideSpotComponent**)Z_Param__Result=P_THIS->GetCurrentHideSpot();
	P_NATIVE_END;
}
// ********** End Class UJMHideInteractorComponent Function GetCurrentHideSpot *********************

// ********** Begin Class UJMHideInteractorComponent Function GetCurrentPhase **********************
struct Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentPhase_Statics
{
	struct JMHideInteractorComponent_eventGetCurrentPhase_Parms
	{
		EJMHidePhase ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Components/JMHideInteractorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentPhase constinit property declarations ***********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentPhase constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentPhase Property Definitions **********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentPhase_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentPhase_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMHideInteractorComponent_eventGetCurrentPhase_Parms, ReturnValue), Z_Construct_UEnum_JMHideRuntime_EJMHidePhase, METADATA_PARAMS(0, nullptr) }; // 1560254620
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentPhase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentPhase_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentPhase_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentPhase_Statics::PropPointers) < 2048);
// ********** End Function GetCurrentPhase Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentPhase_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMHideInteractorComponent, nullptr, "GetCurrentPhase", 	Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentPhase_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentPhase_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentPhase_Statics::JMHideInteractorComponent_eventGetCurrentPhase_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentPhase_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentPhase_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentPhase_Statics::JMHideInteractorComponent_eventGetCurrentPhase_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentPhase()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentPhase_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMHideInteractorComponent::execGetCurrentPhase)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EJMHidePhase*)Z_Param__Result=P_THIS->GetCurrentPhase();
	P_NATIVE_END;
}
// ********** End Class UJMHideInteractorComponent Function GetCurrentPhase ************************

// ********** Begin Class UJMHideInteractorComponent Function GetCurrentSessionId ******************
struct Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentSessionId_Statics
{
	struct JMHideInteractorComponent_eventGetCurrentSessionId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Components/JMHideInteractorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentSessionId constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentSessionId constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentSessionId Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentSessionId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMHideInteractorComponent_eventGetCurrentSessionId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentSessionId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentSessionId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentSessionId_Statics::PropPointers) < 2048);
// ********** End Function GetCurrentSessionId Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentSessionId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMHideInteractorComponent, nullptr, "GetCurrentSessionId", 	Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentSessionId_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentSessionId_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentSessionId_Statics::JMHideInteractorComponent_eventGetCurrentSessionId_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentSessionId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentSessionId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentSessionId_Statics::JMHideInteractorComponent_eventGetCurrentSessionId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentSessionId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentSessionId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMHideInteractorComponent::execGetCurrentSessionId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetCurrentSessionId();
	P_NATIVE_END;
}
// ********** End Class UJMHideInteractorComponent Function GetCurrentSessionId ********************

// ********** Begin Class UJMHideInteractorComponent Function HasActiveSession *********************
struct Z_Construct_UFunction_UJMHideInteractorComponent_HasActiveSession_Statics
{
	struct JMHideInteractorComponent_eventHasActiveSession_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Components/JMHideInteractorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HasActiveSession constinit property declarations **********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasActiveSession constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasActiveSession Property Definitions *********************************
void Z_Construct_UFunction_UJMHideInteractorComponent_HasActiveSession_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMHideInteractorComponent_eventHasActiveSession_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMHideInteractorComponent_HasActiveSession_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMHideInteractorComponent_eventHasActiveSession_Parms), &Z_Construct_UFunction_UJMHideInteractorComponent_HasActiveSession_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMHideInteractorComponent_HasActiveSession_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideInteractorComponent_HasActiveSession_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_HasActiveSession_Statics::PropPointers) < 2048);
// ********** End Function HasActiveSession Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMHideInteractorComponent_HasActiveSession_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMHideInteractorComponent, nullptr, "HasActiveSession", 	Z_Construct_UFunction_UJMHideInteractorComponent_HasActiveSession_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_HasActiveSession_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMHideInteractorComponent_HasActiveSession_Statics::JMHideInteractorComponent_eventHasActiveSession_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_HasActiveSession_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMHideInteractorComponent_HasActiveSession_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMHideInteractorComponent_HasActiveSession_Statics::JMHideInteractorComponent_eventHasActiveSession_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMHideInteractorComponent_HasActiveSession()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMHideInteractorComponent_HasActiveSession_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMHideInteractorComponent::execHasActiveSession)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->HasActiveSession();
	P_NATIVE_END;
}
// ********** End Class UJMHideInteractorComponent Function HasActiveSession ***********************

// ********** Begin Class UJMHideInteractorComponent Function IsHidden *****************************
struct Z_Construct_UFunction_UJMHideInteractorComponent_IsHidden_Statics
{
	struct JMHideInteractorComponent_eventIsHidden_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Components/JMHideInteractorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsHidden constinit property declarations ******************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsHidden constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsHidden Property Definitions *****************************************
void Z_Construct_UFunction_UJMHideInteractorComponent_IsHidden_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMHideInteractorComponent_eventIsHidden_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMHideInteractorComponent_IsHidden_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMHideInteractorComponent_eventIsHidden_Parms), &Z_Construct_UFunction_UJMHideInteractorComponent_IsHidden_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMHideInteractorComponent_IsHidden_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideInteractorComponent_IsHidden_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_IsHidden_Statics::PropPointers) < 2048);
// ********** End Function IsHidden Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMHideInteractorComponent_IsHidden_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMHideInteractorComponent, nullptr, "IsHidden", 	Z_Construct_UFunction_UJMHideInteractorComponent_IsHidden_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_IsHidden_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMHideInteractorComponent_IsHidden_Statics::JMHideInteractorComponent_eventIsHidden_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_IsHidden_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMHideInteractorComponent_IsHidden_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMHideInteractorComponent_IsHidden_Statics::JMHideInteractorComponent_eventIsHidden_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMHideInteractorComponent_IsHidden()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMHideInteractorComponent_IsHidden_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMHideInteractorComponent::execIsHidden)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsHidden();
	P_NATIVE_END;
}
// ********** End Class UJMHideInteractorComponent Function IsHidden *******************************

// ********** Begin Class UJMHideInteractorComponent Function TryEnterHideSpot *********************
struct Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpot_Statics
{
	struct JMHideInteractorComponent_eventTryEnterHideSpot_Parms
	{
		UJMHideSpotComponent* HideSpot;
		FJMHideResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Components/JMHideInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HideSpot_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function TryEnterHideSpot constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HideSpot;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TryEnterHideSpot constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TryEnterHideSpot Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpot_Statics::NewProp_HideSpot = { "HideSpot", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMHideInteractorComponent_eventTryEnterHideSpot_Parms, HideSpot), Z_Construct_UClass_UJMHideSpotComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HideSpot_MetaData), NewProp_HideSpot_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMHideInteractorComponent_eventTryEnterHideSpot_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMHideResult, METADATA_PARAMS(0, nullptr) }; // 1459112883
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpot_Statics::NewProp_HideSpot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpot_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpot_Statics::PropPointers) < 2048);
// ********** End Function TryEnterHideSpot Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMHideInteractorComponent, nullptr, "TryEnterHideSpot", 	Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpot_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpot_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpot_Statics::JMHideInteractorComponent_eventTryEnterHideSpot_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpot_Statics::JMHideInteractorComponent_eventTryEnterHideSpot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMHideInteractorComponent::execTryEnterHideSpot)
{
	P_GET_OBJECT(UJMHideSpotComponent,Z_Param_HideSpot);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMHideResult*)Z_Param__Result=P_THIS->TryEnterHideSpot(Z_Param_HideSpot);
	P_NATIVE_END;
}
// ********** End Class UJMHideInteractorComponent Function TryEnterHideSpot ***********************

// ********** Begin Class UJMHideInteractorComponent Function TryEnterHideSpotWithRequest **********
struct Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpotWithRequest_Statics
{
	struct JMHideInteractorComponent_eventTryEnterHideSpotWithRequest_Parms
	{
		UJMHideSpotComponent* HideSpot;
		FJMHideRequest Request;
		FJMHideResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Components/JMHideInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HideSpot_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Request_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function TryEnterHideSpotWithRequest constinit property declarations ***********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HideSpot;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Request;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TryEnterHideSpotWithRequest constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TryEnterHideSpotWithRequest Property Definitions **********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpotWithRequest_Statics::NewProp_HideSpot = { "HideSpot", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMHideInteractorComponent_eventTryEnterHideSpotWithRequest_Parms, HideSpot), Z_Construct_UClass_UJMHideSpotComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HideSpot_MetaData), NewProp_HideSpot_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpotWithRequest_Statics::NewProp_Request = { "Request", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMHideInteractorComponent_eventTryEnterHideSpotWithRequest_Parms, Request), Z_Construct_UScriptStruct_FJMHideRequest, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Request_MetaData), NewProp_Request_MetaData) }; // 3732391629
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpotWithRequest_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMHideInteractorComponent_eventTryEnterHideSpotWithRequest_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMHideResult, METADATA_PARAMS(0, nullptr) }; // 1459112883
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpotWithRequest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpotWithRequest_Statics::NewProp_HideSpot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpotWithRequest_Statics::NewProp_Request,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpotWithRequest_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpotWithRequest_Statics::PropPointers) < 2048);
// ********** End Function TryEnterHideSpotWithRequest Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpotWithRequest_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMHideInteractorComponent, nullptr, "TryEnterHideSpotWithRequest", 	Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpotWithRequest_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpotWithRequest_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpotWithRequest_Statics::JMHideInteractorComponent_eventTryEnterHideSpotWithRequest_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpotWithRequest_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpotWithRequest_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpotWithRequest_Statics::JMHideInteractorComponent_eventTryEnterHideSpotWithRequest_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpotWithRequest()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpotWithRequest_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMHideInteractorComponent::execTryEnterHideSpotWithRequest)
{
	P_GET_OBJECT(UJMHideSpotComponent,Z_Param_HideSpot);
	P_GET_STRUCT_REF(FJMHideRequest,Z_Param_Out_Request);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMHideResult*)Z_Param__Result=P_THIS->TryEnterHideSpotWithRequest(Z_Param_HideSpot,Z_Param_Out_Request);
	P_NATIVE_END;
}
// ********** End Class UJMHideInteractorComponent Function TryEnterHideSpotWithRequest ************

// ********** Begin Class UJMHideInteractorComponent Function TryExitCurrentHideSpot ***************
struct Z_Construct_UFunction_UJMHideInteractorComponent_TryExitCurrentHideSpot_Statics
{
	struct JMHideInteractorComponent_eventTryExitCurrentHideSpot_Parms
	{
		FJMHideResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Components/JMHideInteractorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function TryExitCurrentHideSpot constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TryExitCurrentHideSpot constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TryExitCurrentHideSpot Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMHideInteractorComponent_TryExitCurrentHideSpot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMHideInteractorComponent_eventTryExitCurrentHideSpot_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMHideResult, METADATA_PARAMS(0, nullptr) }; // 1459112883
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMHideInteractorComponent_TryExitCurrentHideSpot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideInteractorComponent_TryExitCurrentHideSpot_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_TryExitCurrentHideSpot_Statics::PropPointers) < 2048);
// ********** End Function TryExitCurrentHideSpot Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMHideInteractorComponent_TryExitCurrentHideSpot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMHideInteractorComponent, nullptr, "TryExitCurrentHideSpot", 	Z_Construct_UFunction_UJMHideInteractorComponent_TryExitCurrentHideSpot_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_TryExitCurrentHideSpot_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMHideInteractorComponent_TryExitCurrentHideSpot_Statics::JMHideInteractorComponent_eventTryExitCurrentHideSpot_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInteractorComponent_TryExitCurrentHideSpot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMHideInteractorComponent_TryExitCurrentHideSpot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMHideInteractorComponent_TryExitCurrentHideSpot_Statics::JMHideInteractorComponent_eventTryExitCurrentHideSpot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMHideInteractorComponent_TryExitCurrentHideSpot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMHideInteractorComponent_TryExitCurrentHideSpot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMHideInteractorComponent::execTryExitCurrentHideSpot)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMHideResult*)Z_Param__Result=P_THIS->TryExitCurrentHideSpot();
	P_NATIVE_END;
}
// ********** End Class UJMHideInteractorComponent Function TryExitCurrentHideSpot *****************

// ********** Begin Class UJMHideInteractorComponent ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMHideInteractorComponent;
UClass* UJMHideInteractorComponent::GetPrivateStaticClass()
{
	using TClass = UJMHideInteractorComponent;
	if (!Z_Registration_Info_UClass_UJMHideInteractorComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMHideInteractorComponent"),
			Z_Registration_Info_UClass_UJMHideInteractorComponent.InnerSingleton,
			StaticRegisterNativesUJMHideInteractorComponent,
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
	return Z_Registration_Info_UClass_UJMHideInteractorComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMHideInteractorComponent_NoRegister()
{
	return UJMHideInteractorComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMHideInteractorComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JMHide" },
		{ "IncludePath", "Components/JMHideInteractorComponent.h" },
		{ "ModuleRelativePath", "Public/Components/JMHideInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnPhaseChanged_MetaData[] = {
		{ "Category", "JM Hide|Events" },
		{ "ModuleRelativePath", "Public/Components/JMHideInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnHiddenEntered_MetaData[] = {
		{ "Category", "JM Hide|Events" },
		{ "ModuleRelativePath", "Public/Components/JMHideInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnHiddenExited_MetaData[] = {
		{ "Category", "JM Hide|Events" },
		{ "ModuleRelativePath", "Public/Components/JMHideInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnExitPromptChanged_MetaData[] = {
		{ "Category", "JM Hide|Events" },
		{ "ModuleRelativePath", "Public/Components/JMHideInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnHideFailed_MetaData[] = {
		{ "Category", "JM Hide|Events" },
		{ "ModuleRelativePath", "Public/Components/JMHideInteractorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMHideInteractorComponent constinit property declarations ***************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPhaseChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnHiddenEntered;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnHiddenExited;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnExitPromptChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnHideFailed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMHideInteractorComponent constinit property declarations *****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CancelCurrentTransition"), .Pointer = &UJMHideInteractorComponent::execCancelCurrentTransition },
		{ .NameUTF8 = UTF8TEXT("ForceExit"), .Pointer = &UJMHideInteractorComponent::execForceExit },
		{ .NameUTF8 = UTF8TEXT("GetCurrentHideSpot"), .Pointer = &UJMHideInteractorComponent::execGetCurrentHideSpot },
		{ .NameUTF8 = UTF8TEXT("GetCurrentPhase"), .Pointer = &UJMHideInteractorComponent::execGetCurrentPhase },
		{ .NameUTF8 = UTF8TEXT("GetCurrentSessionId"), .Pointer = &UJMHideInteractorComponent::execGetCurrentSessionId },
		{ .NameUTF8 = UTF8TEXT("HasActiveSession"), .Pointer = &UJMHideInteractorComponent::execHasActiveSession },
		{ .NameUTF8 = UTF8TEXT("IsHidden"), .Pointer = &UJMHideInteractorComponent::execIsHidden },
		{ .NameUTF8 = UTF8TEXT("TryEnterHideSpot"), .Pointer = &UJMHideInteractorComponent::execTryEnterHideSpot },
		{ .NameUTF8 = UTF8TEXT("TryEnterHideSpotWithRequest"), .Pointer = &UJMHideInteractorComponent::execTryEnterHideSpotWithRequest },
		{ .NameUTF8 = UTF8TEXT("TryExitCurrentHideSpot"), .Pointer = &UJMHideInteractorComponent::execTryExitCurrentHideSpot },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMHideInteractorComponent_CancelCurrentTransition, "CancelCurrentTransition" }, // 1602668297
		{ &Z_Construct_UFunction_UJMHideInteractorComponent_ForceExit, "ForceExit" }, // 1756500499
		{ &Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentHideSpot, "GetCurrentHideSpot" }, // 2337926549
		{ &Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentPhase, "GetCurrentPhase" }, // 3799364215
		{ &Z_Construct_UFunction_UJMHideInteractorComponent_GetCurrentSessionId, "GetCurrentSessionId" }, // 2819020781
		{ &Z_Construct_UFunction_UJMHideInteractorComponent_HasActiveSession, "HasActiveSession" }, // 897268658
		{ &Z_Construct_UFunction_UJMHideInteractorComponent_IsHidden, "IsHidden" }, // 137219825
		{ &Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpot, "TryEnterHideSpot" }, // 4266371793
		{ &Z_Construct_UFunction_UJMHideInteractorComponent_TryEnterHideSpotWithRequest, "TryEnterHideSpotWithRequest" }, // 4235484908
		{ &Z_Construct_UFunction_UJMHideInteractorComponent_TryExitCurrentHideSpot, "TryExitCurrentHideSpot" }, // 2755555754
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMHideInteractorComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMHideInteractorComponent_Statics

// ********** Begin Class UJMHideInteractorComponent Property Definitions **************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMHideInteractorComponent_Statics::NewProp_OnPhaseChanged = { "OnPhaseChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMHideInteractorComponent, OnPhaseChanged), Z_Construct_UDelegateFunction_JMHideRuntime_JMHidePhaseChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnPhaseChanged_MetaData), NewProp_OnPhaseChanged_MetaData) }; // 2311709196
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMHideInteractorComponent_Statics::NewProp_OnHiddenEntered = { "OnHiddenEntered", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMHideInteractorComponent, OnHiddenEntered), Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSessionEventSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnHiddenEntered_MetaData), NewProp_OnHiddenEntered_MetaData) }; // 230854124
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMHideInteractorComponent_Statics::NewProp_OnHiddenExited = { "OnHiddenExited", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMHideInteractorComponent, OnHiddenExited), Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSessionEventSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnHiddenExited_MetaData), NewProp_OnHiddenExited_MetaData) }; // 230854124
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMHideInteractorComponent_Statics::NewProp_OnExitPromptChanged = { "OnExitPromptChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMHideInteractorComponent, OnExitPromptChanged), Z_Construct_UDelegateFunction_JMHideRuntime_JMHideExitPromptChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnExitPromptChanged_MetaData), NewProp_OnExitPromptChanged_MetaData) }; // 3556893210
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMHideInteractorComponent_Statics::NewProp_OnHideFailed = { "OnHideFailed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMHideInteractorComponent, OnHideFailed), Z_Construct_UDelegateFunction_JMHideRuntime_JMHideFailedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnHideFailed_MetaData), NewProp_OnHideFailed_MetaData) }; // 4245910853
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMHideInteractorComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideInteractorComponent_Statics::NewProp_OnPhaseChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideInteractorComponent_Statics::NewProp_OnHiddenEntered,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideInteractorComponent_Statics::NewProp_OnHiddenExited,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideInteractorComponent_Statics::NewProp_OnExitPromptChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideInteractorComponent_Statics::NewProp_OnHideFailed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideInteractorComponent_Statics::PropPointers) < 2048);
// ********** End Class UJMHideInteractorComponent Property Definitions ****************************
UObject* (*const Z_Construct_UClass_UJMHideInteractorComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideInteractorComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMHideInteractorComponent_Statics::ClassParams = {
	&UJMHideInteractorComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMHideInteractorComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideInteractorComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideInteractorComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMHideInteractorComponent_Statics::Class_MetaDataParams)
};
void UJMHideInteractorComponent::StaticRegisterNativesUJMHideInteractorComponent()
{
	UClass* Class = UJMHideInteractorComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMHideInteractorComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMHideInteractorComponent()
{
	if (!Z_Registration_Info_UClass_UJMHideInteractorComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMHideInteractorComponent.OuterSingleton, Z_Construct_UClass_UJMHideInteractorComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMHideInteractorComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMHideInteractorComponent);
UJMHideInteractorComponent::~UJMHideInteractorComponent() {}
// ********** End Class UJMHideInteractorComponent *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideInteractorComponent_h__Script_JMHideRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMHideInteractorComponent, UJMHideInteractorComponent::StaticClass, TEXT("UJMHideInteractorComponent"), &Z_Registration_Info_UClass_UJMHideInteractorComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMHideInteractorComponent), 649207693U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideInteractorComponent_h__Script_JMHideRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideInteractorComponent_h__Script_JMHideRuntime_890860919{
	TEXT("/Script/JMHideRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideInteractorComponent_h__Script_JMHideRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideInteractorComponent_h__Script_JMHideRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
