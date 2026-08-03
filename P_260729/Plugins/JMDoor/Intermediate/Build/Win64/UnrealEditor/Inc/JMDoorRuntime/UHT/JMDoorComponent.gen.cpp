// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Door/JMDoorComponent.h"
#include "Door/JMDoorTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMDoorComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorComponent();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorComponent_NoRegister();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorConfigData_NoRegister();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorMovementComponent_NoRegister();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorBlockBehavior();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorCommand();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorState();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel();
JMDOORRUNTIME_API UFunction* Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorAccessDeniedSignature__DelegateSignature();
JMDOORRUNTIME_API UFunction* Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorDurabilityChangedSignature__DelegateSignature();
JMDOORRUNTIME_API UFunction* Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorNoiseSignature__DelegateSignature();
JMDOORRUNTIME_API UFunction* Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorObstructedSignature__DelegateSignature();
JMDOORRUNTIME_API UFunction* Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorStateChangedSignature__DelegateSignature();
JMDOORRUNTIME_API UFunction* Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature();
JMDOORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMDoorNoiseEvent();
JMDOORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMDoorResult();
JMDOORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMDoorSaveData();
JMDOORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMDoorUseContext();
UPackage* Z_Construct_UPackage__Script_JMDoorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FJMDoorStateChangedSignature ******************************************
struct Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorStateChangedSignature__DelegateSignature_Statics
{
	struct _Script_JMDoorRuntime_eventJMDoorStateChangedSignature_Parms
	{
		EJMDoorState OldState;
		EJMDoorState NewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMDoorStateChangedSignature constinit property declarations **********
	static const UECodeGen_Private::FBytePropertyParams NewProp_OldState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OldState;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMDoorStateChangedSignature constinit property declarations ************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMDoorStateChangedSignature Property Definitions *********************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorStateChangedSignature__DelegateSignature_Statics::NewProp_OldState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorStateChangedSignature__DelegateSignature_Statics::NewProp_OldState = { "OldState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMDoorRuntime_eventJMDoorStateChangedSignature_Parms, OldState), Z_Construct_UEnum_JMDoorRuntime_EJMDoorState, METADATA_PARAMS(0, nullptr) }; // 2513049645
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorStateChangedSignature__DelegateSignature_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorStateChangedSignature__DelegateSignature_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMDoorRuntime_eventJMDoorStateChangedSignature_Parms, NewState), Z_Construct_UEnum_JMDoorRuntime_EJMDoorState, METADATA_PARAMS(0, nullptr) }; // 2513049645
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorStateChangedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorStateChangedSignature__DelegateSignature_Statics::NewProp_OldState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorStateChangedSignature__DelegateSignature_Statics::NewProp_OldState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorStateChangedSignature__DelegateSignature_Statics::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorStateChangedSignature__DelegateSignature_Statics::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorStateChangedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMDoorStateChangedSignature Property Definitions ***********************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorStateChangedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMDoorRuntime, nullptr, "JMDoorStateChangedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorStateChangedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorStateChangedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorStateChangedSignature__DelegateSignature_Statics::_Script_JMDoorRuntime_eventJMDoorStateChangedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorStateChangedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorStateChangedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorStateChangedSignature__DelegateSignature_Statics::_Script_JMDoorRuntime_eventJMDoorStateChangedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorStateChangedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorStateChangedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMDoorStateChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMDoorStateChangedSignature, EJMDoorState OldState, EJMDoorState NewState)
{
	struct _Script_JMDoorRuntime_eventJMDoorStateChangedSignature_Parms
	{
		EJMDoorState OldState;
		EJMDoorState NewState;
	};
	_Script_JMDoorRuntime_eventJMDoorStateChangedSignature_Parms Parms;
	Parms.OldState=OldState;
	Parms.NewState=NewState;
	JMDoorStateChangedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMDoorStateChangedSignature ********************************************

// ********** Begin Delegate FJMDoorAccessDeniedSignature ******************************************
struct Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorAccessDeniedSignature__DelegateSignature_Statics
{
	struct _Script_JMDoorRuntime_eventJMDoorAccessDeniedSignature_Parms
	{
		FJMDoorUseContext Context;
		FJMDoorResult Result;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMDoorAccessDeniedSignature constinit property declarations **********
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Result;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMDoorAccessDeniedSignature constinit property declarations ************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMDoorAccessDeniedSignature Property Definitions *********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorAccessDeniedSignature__DelegateSignature_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMDoorRuntime_eventJMDoorAccessDeniedSignature_Parms, Context), Z_Construct_UScriptStruct_FJMDoorUseContext, METADATA_PARAMS(0, nullptr) }; // 3552665729
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorAccessDeniedSignature__DelegateSignature_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMDoorRuntime_eventJMDoorAccessDeniedSignature_Parms, Result), Z_Construct_UScriptStruct_FJMDoorResult, METADATA_PARAMS(0, nullptr) }; // 1639184842
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorAccessDeniedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorAccessDeniedSignature__DelegateSignature_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorAccessDeniedSignature__DelegateSignature_Statics::NewProp_Result,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorAccessDeniedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMDoorAccessDeniedSignature Property Definitions ***********************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorAccessDeniedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMDoorRuntime, nullptr, "JMDoorAccessDeniedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorAccessDeniedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorAccessDeniedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorAccessDeniedSignature__DelegateSignature_Statics::_Script_JMDoorRuntime_eventJMDoorAccessDeniedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorAccessDeniedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorAccessDeniedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorAccessDeniedSignature__DelegateSignature_Statics::_Script_JMDoorRuntime_eventJMDoorAccessDeniedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorAccessDeniedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorAccessDeniedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMDoorAccessDeniedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMDoorAccessDeniedSignature, FJMDoorUseContext Context, FJMDoorResult Result)
{
	struct _Script_JMDoorRuntime_eventJMDoorAccessDeniedSignature_Parms
	{
		FJMDoorUseContext Context;
		FJMDoorResult Result;
	};
	_Script_JMDoorRuntime_eventJMDoorAccessDeniedSignature_Parms Parms;
	Parms.Context=Context;
	Parms.Result=Result;
	JMDoorAccessDeniedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMDoorAccessDeniedSignature ********************************************

// ********** Begin Delegate FJMDoorNoiseSignature *************************************************
struct Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorNoiseSignature__DelegateSignature_Statics
{
	struct _Script_JMDoorRuntime_eventJMDoorNoiseSignature_Parms
	{
		FJMDoorNoiseEvent NoiseEvent;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMDoorNoiseSignature constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_NoiseEvent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMDoorNoiseSignature constinit property declarations *******************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMDoorNoiseSignature Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorNoiseSignature__DelegateSignature_Statics::NewProp_NoiseEvent = { "NoiseEvent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMDoorRuntime_eventJMDoorNoiseSignature_Parms, NoiseEvent), Z_Construct_UScriptStruct_FJMDoorNoiseEvent, METADATA_PARAMS(0, nullptr) }; // 386806309
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorNoiseSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorNoiseSignature__DelegateSignature_Statics::NewProp_NoiseEvent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorNoiseSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMDoorNoiseSignature Property Definitions ******************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorNoiseSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMDoorRuntime, nullptr, "JMDoorNoiseSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorNoiseSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorNoiseSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorNoiseSignature__DelegateSignature_Statics::_Script_JMDoorRuntime_eventJMDoorNoiseSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorNoiseSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorNoiseSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorNoiseSignature__DelegateSignature_Statics::_Script_JMDoorRuntime_eventJMDoorNoiseSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorNoiseSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorNoiseSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMDoorNoiseSignature_DelegateWrapper(const FMulticastScriptDelegate& JMDoorNoiseSignature, FJMDoorNoiseEvent NoiseEvent)
{
	struct _Script_JMDoorRuntime_eventJMDoorNoiseSignature_Parms
	{
		FJMDoorNoiseEvent NoiseEvent;
	};
	_Script_JMDoorRuntime_eventJMDoorNoiseSignature_Parms Parms;
	Parms.NoiseEvent=NoiseEvent;
	JMDoorNoiseSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMDoorNoiseSignature ***************************************************

// ********** Begin Delegate FJMDoorObstructedSignature ********************************************
struct Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorObstructedSignature__DelegateSignature_Statics
{
	struct _Script_JMDoorRuntime_eventJMDoorObstructedSignature_Parms
	{
		AActor* BlockingActor;
		EJMDoorBlockBehavior Behavior;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMDoorObstructedSignature constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BlockingActor;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Behavior_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Behavior;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMDoorObstructedSignature constinit property declarations **************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMDoorObstructedSignature Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorObstructedSignature__DelegateSignature_Statics::NewProp_BlockingActor = { "BlockingActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMDoorRuntime_eventJMDoorObstructedSignature_Parms, BlockingActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorObstructedSignature__DelegateSignature_Statics::NewProp_Behavior_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorObstructedSignature__DelegateSignature_Statics::NewProp_Behavior = { "Behavior", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMDoorRuntime_eventJMDoorObstructedSignature_Parms, Behavior), Z_Construct_UEnum_JMDoorRuntime_EJMDoorBlockBehavior, METADATA_PARAMS(0, nullptr) }; // 1963034699
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorObstructedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorObstructedSignature__DelegateSignature_Statics::NewProp_BlockingActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorObstructedSignature__DelegateSignature_Statics::NewProp_Behavior_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorObstructedSignature__DelegateSignature_Statics::NewProp_Behavior,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorObstructedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMDoorObstructedSignature Property Definitions *************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorObstructedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMDoorRuntime, nullptr, "JMDoorObstructedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorObstructedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorObstructedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorObstructedSignature__DelegateSignature_Statics::_Script_JMDoorRuntime_eventJMDoorObstructedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorObstructedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorObstructedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorObstructedSignature__DelegateSignature_Statics::_Script_JMDoorRuntime_eventJMDoorObstructedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorObstructedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorObstructedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMDoorObstructedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMDoorObstructedSignature, AActor* BlockingActor, EJMDoorBlockBehavior Behavior)
{
	struct _Script_JMDoorRuntime_eventJMDoorObstructedSignature_Parms
	{
		AActor* BlockingActor;
		EJMDoorBlockBehavior Behavior;
	};
	_Script_JMDoorRuntime_eventJMDoorObstructedSignature_Parms Parms;
	Parms.BlockingActor=BlockingActor;
	Parms.Behavior=Behavior;
	JMDoorObstructedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMDoorObstructedSignature **********************************************

// ********** Begin Delegate FJMDoorDurabilityChangedSignature *************************************
struct Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorDurabilityChangedSignature__DelegateSignature_Statics
{
	struct _Script_JMDoorRuntime_eventJMDoorDurabilityChangedSignature_Parms
	{
		float DoorDurability;
		float LockDurability;
		bool bLockBroken;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMDoorDurabilityChangedSignature constinit property declarations *****
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DoorDurability;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LockDurability;
	static void NewProp_bLockBroken_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLockBroken;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMDoorDurabilityChangedSignature constinit property declarations *******
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMDoorDurabilityChangedSignature Property Definitions ****************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorDurabilityChangedSignature__DelegateSignature_Statics::NewProp_DoorDurability = { "DoorDurability", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMDoorRuntime_eventJMDoorDurabilityChangedSignature_Parms, DoorDurability), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorDurabilityChangedSignature__DelegateSignature_Statics::NewProp_LockDurability = { "LockDurability", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMDoorRuntime_eventJMDoorDurabilityChangedSignature_Parms, LockDurability), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorDurabilityChangedSignature__DelegateSignature_Statics::NewProp_bLockBroken_SetBit(void* Obj)
{
	((_Script_JMDoorRuntime_eventJMDoorDurabilityChangedSignature_Parms*)Obj)->bLockBroken = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorDurabilityChangedSignature__DelegateSignature_Statics::NewProp_bLockBroken = { "bLockBroken", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_JMDoorRuntime_eventJMDoorDurabilityChangedSignature_Parms), &Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorDurabilityChangedSignature__DelegateSignature_Statics::NewProp_bLockBroken_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorDurabilityChangedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorDurabilityChangedSignature__DelegateSignature_Statics::NewProp_DoorDurability,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorDurabilityChangedSignature__DelegateSignature_Statics::NewProp_LockDurability,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorDurabilityChangedSignature__DelegateSignature_Statics::NewProp_bLockBroken,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorDurabilityChangedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMDoorDurabilityChangedSignature Property Definitions ******************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorDurabilityChangedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMDoorRuntime, nullptr, "JMDoorDurabilityChangedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorDurabilityChangedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorDurabilityChangedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorDurabilityChangedSignature__DelegateSignature_Statics::_Script_JMDoorRuntime_eventJMDoorDurabilityChangedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorDurabilityChangedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorDurabilityChangedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorDurabilityChangedSignature__DelegateSignature_Statics::_Script_JMDoorRuntime_eventJMDoorDurabilityChangedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorDurabilityChangedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorDurabilityChangedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMDoorDurabilityChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMDoorDurabilityChangedSignature, float DoorDurability, float LockDurability, bool bLockBroken)
{
	struct _Script_JMDoorRuntime_eventJMDoorDurabilityChangedSignature_Parms
	{
		float DoorDurability;
		float LockDurability;
		bool bLockBroken;
	};
	_Script_JMDoorRuntime_eventJMDoorDurabilityChangedSignature_Parms Parms;
	Parms.DoorDurability=DoorDurability;
	Parms.LockDurability=LockDurability;
	Parms.bLockBroken=bLockBroken ? true : false;
	JMDoorDurabilityChangedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMDoorDurabilityChangedSignature ***************************************

// ********** Begin Delegate FJMSlideDoorPanelStateChangedSignature ********************************
struct Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature_Statics
{
	struct _Script_JMDoorRuntime_eventJMSlideDoorPanelStateChangedSignature_Parms
	{
		EJMSlideDoorPanel Panel;
		EJMDoorState OldState;
		EJMDoorState NewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMSlideDoorPanelStateChangedSignature constinit property declarations 
	static const UECodeGen_Private::FBytePropertyParams NewProp_Panel_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Panel;
	static const UECodeGen_Private::FBytePropertyParams NewProp_OldState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OldState;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMSlideDoorPanelStateChangedSignature constinit property declarations **
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMSlideDoorPanelStateChangedSignature Property Definitions ***********
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature_Statics::NewProp_Panel_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature_Statics::NewProp_Panel = { "Panel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMDoorRuntime_eventJMSlideDoorPanelStateChangedSignature_Parms, Panel), Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel, METADATA_PARAMS(0, nullptr) }; // 1478343840
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature_Statics::NewProp_OldState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature_Statics::NewProp_OldState = { "OldState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMDoorRuntime_eventJMSlideDoorPanelStateChangedSignature_Parms, OldState), Z_Construct_UEnum_JMDoorRuntime_EJMDoorState, METADATA_PARAMS(0, nullptr) }; // 2513049645
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMDoorRuntime_eventJMSlideDoorPanelStateChangedSignature_Parms, NewState), Z_Construct_UEnum_JMDoorRuntime_EJMDoorState, METADATA_PARAMS(0, nullptr) }; // 2513049645
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature_Statics::NewProp_Panel_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature_Statics::NewProp_Panel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature_Statics::NewProp_OldState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature_Statics::NewProp_OldState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature_Statics::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature_Statics::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMSlideDoorPanelStateChangedSignature Property Definitions *************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMDoorRuntime, nullptr, "JMSlideDoorPanelStateChangedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature_Statics::_Script_JMDoorRuntime_eventJMSlideDoorPanelStateChangedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature_Statics::_Script_JMDoorRuntime_eventJMSlideDoorPanelStateChangedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMSlideDoorPanelStateChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMSlideDoorPanelStateChangedSignature, EJMSlideDoorPanel Panel, EJMDoorState OldState, EJMDoorState NewState)
{
	struct _Script_JMDoorRuntime_eventJMSlideDoorPanelStateChangedSignature_Parms
	{
		EJMSlideDoorPanel Panel;
		EJMDoorState OldState;
		EJMDoorState NewState;
	};
	_Script_JMDoorRuntime_eventJMSlideDoorPanelStateChangedSignature_Parms Parms;
	Parms.Panel=Panel;
	Parms.OldState=OldState;
	Parms.NewState=NewState;
	JMSlideDoorPanelStateChangedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMSlideDoorPanelStateChangedSignature **********************************

// ********** Begin Class UJMDoorComponent Function ApplyDoorDamage ********************************
struct Z_Construct_UFunction_UJMDoorComponent_ApplyDoorDamage_Statics
{
	struct JMDoorComponent_eventApplyDoorDamage_Parms
	{
		float Damage;
		AActor* DamageInstigator;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Durability" },
		{ "CPP_Default_DamageInstigator", "None" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ApplyDoorDamage constinit property declarations ***********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Damage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DamageInstigator;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ApplyDoorDamage constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ApplyDoorDamage Property Definitions **********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMDoorComponent_ApplyDoorDamage_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventApplyDoorDamage_Parms, Damage), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMDoorComponent_ApplyDoorDamage_Statics::NewProp_DamageInstigator = { "DamageInstigator", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventApplyDoorDamage_Parms, DamageInstigator), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_ApplyDoorDamage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_ApplyDoorDamage_Statics::NewProp_Damage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_ApplyDoorDamage_Statics::NewProp_DamageInstigator,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_ApplyDoorDamage_Statics::PropPointers) < 2048);
// ********** End Function ApplyDoorDamage Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_ApplyDoorDamage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "ApplyDoorDamage", 	Z_Construct_UFunction_UJMDoorComponent_ApplyDoorDamage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_ApplyDoorDamage_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_ApplyDoorDamage_Statics::JMDoorComponent_eventApplyDoorDamage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_ApplyDoorDamage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_ApplyDoorDamage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_ApplyDoorDamage_Statics::JMDoorComponent_eventApplyDoorDamage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_ApplyDoorDamage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_ApplyDoorDamage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execApplyDoorDamage)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Damage);
	P_GET_OBJECT(AActor,Z_Param_DamageInstigator);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ApplyDoorDamage(Z_Param_Damage,Z_Param_DamageInstigator);
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function ApplyDoorDamage **********************************

// ********** Begin Class UJMDoorComponent Function ApplyLockDamage ********************************
struct Z_Construct_UFunction_UJMDoorComponent_ApplyLockDamage_Statics
{
	struct JMDoorComponent_eventApplyLockDamage_Parms
	{
		float Damage;
		AActor* DamageInstigator;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Durability" },
		{ "CPP_Default_DamageInstigator", "None" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ApplyLockDamage constinit property declarations ***********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Damage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DamageInstigator;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ApplyLockDamage constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ApplyLockDamage Property Definitions **********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMDoorComponent_ApplyLockDamage_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventApplyLockDamage_Parms, Damage), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMDoorComponent_ApplyLockDamage_Statics::NewProp_DamageInstigator = { "DamageInstigator", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventApplyLockDamage_Parms, DamageInstigator), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_ApplyLockDamage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_ApplyLockDamage_Statics::NewProp_Damage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_ApplyLockDamage_Statics::NewProp_DamageInstigator,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_ApplyLockDamage_Statics::PropPointers) < 2048);
// ********** End Function ApplyLockDamage Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_ApplyLockDamage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "ApplyLockDamage", 	Z_Construct_UFunction_UJMDoorComponent_ApplyLockDamage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_ApplyLockDamage_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_ApplyLockDamage_Statics::JMDoorComponent_eventApplyLockDamage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_ApplyLockDamage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_ApplyLockDamage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_ApplyLockDamage_Statics::JMDoorComponent_eventApplyLockDamage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_ApplyLockDamage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_ApplyLockDamage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execApplyLockDamage)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Damage);
	P_GET_OBJECT(AActor,Z_Param_DamageInstigator);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ApplyLockDamage(Z_Param_Damage,Z_Param_DamageInstigator);
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function ApplyLockDamage **********************************

// ********** Begin Class UJMDoorComponent Function CanExecuteCommand ******************************
struct Z_Construct_UFunction_UJMDoorComponent_CanExecuteCommand_Statics
{
	struct JMDoorComponent_eventCanExecuteCommand_Parms
	{
		EJMDoorCommand Command;
		FJMDoorUseContext Context;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CanExecuteCommand constinit property declarations *********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Command_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Command;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CanExecuteCommand constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CanExecuteCommand Property Definitions ********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMDoorComponent_CanExecuteCommand_Statics::NewProp_Command_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMDoorComponent_CanExecuteCommand_Statics::NewProp_Command = { "Command", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventCanExecuteCommand_Parms, Command), Z_Construct_UEnum_JMDoorRuntime_EJMDoorCommand, METADATA_PARAMS(0, nullptr) }; // 4018727221
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorComponent_CanExecuteCommand_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventCanExecuteCommand_Parms, Context), Z_Construct_UScriptStruct_FJMDoorUseContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3552665729
void Z_Construct_UFunction_UJMDoorComponent_CanExecuteCommand_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMDoorComponent_eventCanExecuteCommand_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMDoorComponent_CanExecuteCommand_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMDoorComponent_eventCanExecuteCommand_Parms), &Z_Construct_UFunction_UJMDoorComponent_CanExecuteCommand_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_CanExecuteCommand_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_CanExecuteCommand_Statics::NewProp_Command_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_CanExecuteCommand_Statics::NewProp_Command,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_CanExecuteCommand_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_CanExecuteCommand_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_CanExecuteCommand_Statics::PropPointers) < 2048);
// ********** End Function CanExecuteCommand Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_CanExecuteCommand_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "CanExecuteCommand", 	Z_Construct_UFunction_UJMDoorComponent_CanExecuteCommand_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_CanExecuteCommand_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_CanExecuteCommand_Statics::JMDoorComponent_eventCanExecuteCommand_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_CanExecuteCommand_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_CanExecuteCommand_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_CanExecuteCommand_Statics::JMDoorComponent_eventCanExecuteCommand_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_CanExecuteCommand()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_CanExecuteCommand_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execCanExecuteCommand)
{
	P_GET_ENUM(EJMDoorCommand,Z_Param_Command);
	P_GET_STRUCT_REF(FJMDoorUseContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanExecuteCommand(EJMDoorCommand(Z_Param_Command),Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function CanExecuteCommand ********************************

// ********** Begin Class UJMDoorComponent Function CaptureSaveData ********************************
struct Z_Construct_UFunction_UJMDoorComponent_CaptureSaveData_Statics
{
	struct JMDoorComponent_eventCaptureSaveData_Parms
	{
		FJMDoorSaveData ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Save" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CaptureSaveData constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CaptureSaveData constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CaptureSaveData Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorComponent_CaptureSaveData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventCaptureSaveData_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMDoorSaveData, METADATA_PARAMS(0, nullptr) }; // 362659228
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_CaptureSaveData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_CaptureSaveData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_CaptureSaveData_Statics::PropPointers) < 2048);
// ********** End Function CaptureSaveData Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_CaptureSaveData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "CaptureSaveData", 	Z_Construct_UFunction_UJMDoorComponent_CaptureSaveData_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_CaptureSaveData_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_CaptureSaveData_Statics::JMDoorComponent_eventCaptureSaveData_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_CaptureSaveData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_CaptureSaveData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_CaptureSaveData_Statics::JMDoorComponent_eventCaptureSaveData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_CaptureSaveData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_CaptureSaveData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execCaptureSaveData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMDoorSaveData*)Z_Param__Result=P_THIS->CaptureSaveData();
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function CaptureSaveData **********************************

// ********** Begin Class UJMDoorComponent Function CloseDoor **************************************
struct Z_Construct_UFunction_UJMDoorComponent_CloseDoor_Statics
{
	struct JMDoorComponent_eventCloseDoor_Parms
	{
		FJMDoorUseContext Context;
		FJMDoorResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CloseDoor constinit property declarations *****************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CloseDoor constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CloseDoor Property Definitions ****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorComponent_CloseDoor_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventCloseDoor_Parms, Context), Z_Construct_UScriptStruct_FJMDoorUseContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3552665729
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorComponent_CloseDoor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventCloseDoor_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMDoorResult, METADATA_PARAMS(0, nullptr) }; // 1639184842
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_CloseDoor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_CloseDoor_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_CloseDoor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_CloseDoor_Statics::PropPointers) < 2048);
// ********** End Function CloseDoor Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_CloseDoor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "CloseDoor", 	Z_Construct_UFunction_UJMDoorComponent_CloseDoor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_CloseDoor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_CloseDoor_Statics::JMDoorComponent_eventCloseDoor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_CloseDoor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_CloseDoor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_CloseDoor_Statics::JMDoorComponent_eventCloseDoor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_CloseDoor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_CloseDoor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execCloseDoor)
{
	P_GET_STRUCT_REF(FJMDoorUseContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMDoorResult*)Z_Param__Result=P_THIS->CloseDoor(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function CloseDoor ****************************************

// ********** Begin Class UJMDoorComponent Function CloseSlideDoor *********************************
struct Z_Construct_UFunction_UJMDoorComponent_CloseSlideDoor_Statics
{
	struct JMDoorComponent_eventCloseSlideDoor_Parms
	{
		EJMSlideDoorPanel Panel;
		FJMDoorUseContext Context;
		FJMDoorResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Slide Door" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CloseSlideDoor constinit property declarations ************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Panel_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Panel;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CloseSlideDoor constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CloseSlideDoor Property Definitions ***********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMDoorComponent_CloseSlideDoor_Statics::NewProp_Panel_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMDoorComponent_CloseSlideDoor_Statics::NewProp_Panel = { "Panel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventCloseSlideDoor_Parms, Panel), Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel, METADATA_PARAMS(0, nullptr) }; // 1478343840
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorComponent_CloseSlideDoor_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventCloseSlideDoor_Parms, Context), Z_Construct_UScriptStruct_FJMDoorUseContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3552665729
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorComponent_CloseSlideDoor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventCloseSlideDoor_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMDoorResult, METADATA_PARAMS(0, nullptr) }; // 1639184842
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_CloseSlideDoor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_CloseSlideDoor_Statics::NewProp_Panel_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_CloseSlideDoor_Statics::NewProp_Panel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_CloseSlideDoor_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_CloseSlideDoor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_CloseSlideDoor_Statics::PropPointers) < 2048);
// ********** End Function CloseSlideDoor Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_CloseSlideDoor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "CloseSlideDoor", 	Z_Construct_UFunction_UJMDoorComponent_CloseSlideDoor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_CloseSlideDoor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_CloseSlideDoor_Statics::JMDoorComponent_eventCloseSlideDoor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_CloseSlideDoor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_CloseSlideDoor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_CloseSlideDoor_Statics::JMDoorComponent_eventCloseSlideDoor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_CloseSlideDoor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_CloseSlideDoor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execCloseSlideDoor)
{
	P_GET_ENUM(EJMSlideDoorPanel,Z_Param_Panel);
	P_GET_STRUCT_REF(FJMDoorUseContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMDoorResult*)Z_Param__Result=P_THIS->CloseSlideDoor(EJMSlideDoorPanel(Z_Param_Panel),Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function CloseSlideDoor ***********************************

// ********** Begin Class UJMDoorComponent Function ExecuteCommand *********************************
struct Z_Construct_UFunction_UJMDoorComponent_ExecuteCommand_Statics
{
	struct JMDoorComponent_eventExecuteCommand_Parms
	{
		EJMDoorCommand Command;
		FJMDoorUseContext Context;
		FJMDoorResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ExecuteCommand constinit property declarations ************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Command_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Command;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ExecuteCommand constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ExecuteCommand Property Definitions ***********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMDoorComponent_ExecuteCommand_Statics::NewProp_Command_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMDoorComponent_ExecuteCommand_Statics::NewProp_Command = { "Command", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventExecuteCommand_Parms, Command), Z_Construct_UEnum_JMDoorRuntime_EJMDoorCommand, METADATA_PARAMS(0, nullptr) }; // 4018727221
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorComponent_ExecuteCommand_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventExecuteCommand_Parms, Context), Z_Construct_UScriptStruct_FJMDoorUseContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3552665729
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorComponent_ExecuteCommand_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventExecuteCommand_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMDoorResult, METADATA_PARAMS(0, nullptr) }; // 1639184842
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_ExecuteCommand_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_ExecuteCommand_Statics::NewProp_Command_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_ExecuteCommand_Statics::NewProp_Command,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_ExecuteCommand_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_ExecuteCommand_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_ExecuteCommand_Statics::PropPointers) < 2048);
// ********** End Function ExecuteCommand Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_ExecuteCommand_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "ExecuteCommand", 	Z_Construct_UFunction_UJMDoorComponent_ExecuteCommand_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_ExecuteCommand_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_ExecuteCommand_Statics::JMDoorComponent_eventExecuteCommand_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_ExecuteCommand_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_ExecuteCommand_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_ExecuteCommand_Statics::JMDoorComponent_eventExecuteCommand_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_ExecuteCommand()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_ExecuteCommand_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execExecuteCommand)
{
	P_GET_ENUM(EJMDoorCommand,Z_Param_Command);
	P_GET_STRUCT_REF(FJMDoorUseContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMDoorResult*)Z_Param__Result=P_THIS->ExecuteCommand(EJMDoorCommand(Z_Param_Command),Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function ExecuteCommand ***********************************

// ********** Begin Class UJMDoorComponent Function ForceOpenDoor **********************************
struct Z_Construct_UFunction_UJMDoorComponent_ForceOpenDoor_Statics
{
	struct JMDoorComponent_eventForceOpenDoor_Parms
	{
		float ForceDamage;
		FJMDoorUseContext Context;
		FJMDoorResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Durability" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ForceOpenDoor constinit property declarations *************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ForceDamage;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ForceOpenDoor constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ForceOpenDoor Property Definitions ************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMDoorComponent_ForceOpenDoor_Statics::NewProp_ForceDamage = { "ForceDamage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventForceOpenDoor_Parms, ForceDamage), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorComponent_ForceOpenDoor_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventForceOpenDoor_Parms, Context), Z_Construct_UScriptStruct_FJMDoorUseContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3552665729
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorComponent_ForceOpenDoor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventForceOpenDoor_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMDoorResult, METADATA_PARAMS(0, nullptr) }; // 1639184842
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_ForceOpenDoor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_ForceOpenDoor_Statics::NewProp_ForceDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_ForceOpenDoor_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_ForceOpenDoor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_ForceOpenDoor_Statics::PropPointers) < 2048);
// ********** End Function ForceOpenDoor Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_ForceOpenDoor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "ForceOpenDoor", 	Z_Construct_UFunction_UJMDoorComponent_ForceOpenDoor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_ForceOpenDoor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_ForceOpenDoor_Statics::JMDoorComponent_eventForceOpenDoor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_ForceOpenDoor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_ForceOpenDoor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_ForceOpenDoor_Statics::JMDoorComponent_eventForceOpenDoor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_ForceOpenDoor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_ForceOpenDoor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execForceOpenDoor)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_ForceDamage);
	P_GET_STRUCT_REF(FJMDoorUseContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMDoorResult*)Z_Param__Result=P_THIS->ForceOpenDoor(Z_Param_ForceDamage,Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function ForceOpenDoor ************************************

// ********** Begin Class UJMDoorComponent Function GetDoorDurability ******************************
struct Z_Construct_UFunction_UJMDoorComponent_GetDoorDurability_Statics
{
	struct JMDoorComponent_eventGetDoorDurability_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Durability" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDoorDurability constinit property declarations *********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDoorDurability constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDoorDurability Property Definitions ********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMDoorComponent_GetDoorDurability_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventGetDoorDurability_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_GetDoorDurability_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_GetDoorDurability_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_GetDoorDurability_Statics::PropPointers) < 2048);
// ********** End Function GetDoorDurability Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_GetDoorDurability_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "GetDoorDurability", 	Z_Construct_UFunction_UJMDoorComponent_GetDoorDurability_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_GetDoorDurability_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_GetDoorDurability_Statics::JMDoorComponent_eventGetDoorDurability_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_GetDoorDurability_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_GetDoorDurability_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_GetDoorDurability_Statics::JMDoorComponent_eventGetDoorDurability_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_GetDoorDurability()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_GetDoorDurability_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execGetDoorDurability)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetDoorDurability();
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function GetDoorDurability ********************************

// ********** Begin Class UJMDoorComponent Function GetLockDurability ******************************
struct Z_Construct_UFunction_UJMDoorComponent_GetLockDurability_Statics
{
	struct JMDoorComponent_eventGetLockDurability_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Durability" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetLockDurability constinit property declarations *********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetLockDurability constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetLockDurability Property Definitions ********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMDoorComponent_GetLockDurability_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventGetLockDurability_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_GetLockDurability_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_GetLockDurability_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_GetLockDurability_Statics::PropPointers) < 2048);
// ********** End Function GetLockDurability Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_GetLockDurability_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "GetLockDurability", 	Z_Construct_UFunction_UJMDoorComponent_GetLockDurability_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_GetLockDurability_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_GetLockDurability_Statics::JMDoorComponent_eventGetLockDurability_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_GetLockDurability_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_GetLockDurability_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_GetLockDurability_Statics::JMDoorComponent_eventGetLockDurability_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_GetLockDurability()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_GetLockDurability_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execGetLockDurability)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetLockDurability();
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function GetLockDurability ********************************

// ********** Begin Class UJMDoorComponent Function GetOpenFraction ********************************
struct Z_Construct_UFunction_UJMDoorComponent_GetOpenFraction_Statics
{
	struct JMDoorComponent_eventGetOpenFraction_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetOpenFraction constinit property declarations ***********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetOpenFraction constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetOpenFraction Property Definitions **********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMDoorComponent_GetOpenFraction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventGetOpenFraction_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_GetOpenFraction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_GetOpenFraction_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_GetOpenFraction_Statics::PropPointers) < 2048);
// ********** End Function GetOpenFraction Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_GetOpenFraction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "GetOpenFraction", 	Z_Construct_UFunction_UJMDoorComponent_GetOpenFraction_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_GetOpenFraction_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_GetOpenFraction_Statics::JMDoorComponent_eventGetOpenFraction_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_GetOpenFraction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_GetOpenFraction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_GetOpenFraction_Statics::JMDoorComponent_eventGetOpenFraction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_GetOpenFraction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_GetOpenFraction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execGetOpenFraction)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetOpenFraction();
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function GetOpenFraction **********************************

// ********** Begin Class UJMDoorComponent Function GetSlideDoorPanelOpenFraction ******************
struct Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelOpenFraction_Statics
{
	struct JMDoorComponent_eventGetSlideDoorPanelOpenFraction_Parms
	{
		EJMSlideDoorPanel Panel;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Slide Door" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSlideDoorPanelOpenFraction constinit property declarations *********
	static const UECodeGen_Private::FBytePropertyParams NewProp_Panel_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Panel;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSlideDoorPanelOpenFraction constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSlideDoorPanelOpenFraction Property Definitions ********************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelOpenFraction_Statics::NewProp_Panel_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelOpenFraction_Statics::NewProp_Panel = { "Panel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventGetSlideDoorPanelOpenFraction_Parms, Panel), Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel, METADATA_PARAMS(0, nullptr) }; // 1478343840
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelOpenFraction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventGetSlideDoorPanelOpenFraction_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelOpenFraction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelOpenFraction_Statics::NewProp_Panel_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelOpenFraction_Statics::NewProp_Panel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelOpenFraction_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelOpenFraction_Statics::PropPointers) < 2048);
// ********** End Function GetSlideDoorPanelOpenFraction Property Definitions **********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelOpenFraction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "GetSlideDoorPanelOpenFraction", 	Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelOpenFraction_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelOpenFraction_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelOpenFraction_Statics::JMDoorComponent_eventGetSlideDoorPanelOpenFraction_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelOpenFraction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelOpenFraction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelOpenFraction_Statics::JMDoorComponent_eventGetSlideDoorPanelOpenFraction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelOpenFraction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelOpenFraction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execGetSlideDoorPanelOpenFraction)
{
	P_GET_ENUM(EJMSlideDoorPanel,Z_Param_Panel);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetSlideDoorPanelOpenFraction(EJMSlideDoorPanel(Z_Param_Panel));
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function GetSlideDoorPanelOpenFraction ********************

// ********** Begin Class UJMDoorComponent Function GetSlideDoorPanelState *************************
struct Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelState_Statics
{
	struct JMDoorComponent_eventGetSlideDoorPanelState_Parms
	{
		EJMSlideDoorPanel Panel;
		EJMDoorState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Slide Door" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSlideDoorPanelState constinit property declarations ****************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Panel_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Panel;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSlideDoorPanelState constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSlideDoorPanelState Property Definitions ***************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelState_Statics::NewProp_Panel_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelState_Statics::NewProp_Panel = { "Panel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventGetSlideDoorPanelState_Parms, Panel), Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel, METADATA_PARAMS(0, nullptr) }; // 1478343840
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventGetSlideDoorPanelState_Parms, ReturnValue), Z_Construct_UEnum_JMDoorRuntime_EJMDoorState, METADATA_PARAMS(0, nullptr) }; // 2513049645
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelState_Statics::NewProp_Panel_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelState_Statics::NewProp_Panel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelState_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelState_Statics::PropPointers) < 2048);
// ********** End Function GetSlideDoorPanelState Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "GetSlideDoorPanelState", 	Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelState_Statics::JMDoorComponent_eventGetSlideDoorPanelState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelState_Statics::JMDoorComponent_eventGetSlideDoorPanelState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execGetSlideDoorPanelState)
{
	P_GET_ENUM(EJMSlideDoorPanel,Z_Param_Panel);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EJMDoorState*)Z_Param__Result=P_THIS->GetSlideDoorPanelState(EJMSlideDoorPanel(Z_Param_Panel));
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function GetSlideDoorPanelState ***************************

// ********** Begin Class UJMDoorComponent Function GetState ***************************************
struct Z_Construct_UFunction_UJMDoorComponent_GetState_Statics
{
	struct JMDoorComponent_eventGetState_Parms
	{
		EJMDoorState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetState constinit property declarations ******************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetState constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetState Property Definitions *****************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMDoorComponent_GetState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMDoorComponent_GetState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventGetState_Parms, ReturnValue), Z_Construct_UEnum_JMDoorRuntime_EJMDoorState, METADATA_PARAMS(0, nullptr) }; // 2513049645
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_GetState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_GetState_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_GetState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_GetState_Statics::PropPointers) < 2048);
// ********** End Function GetState Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_GetState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "GetState", 	Z_Construct_UFunction_UJMDoorComponent_GetState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_GetState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_GetState_Statics::JMDoorComponent_eventGetState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_GetState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_GetState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_GetState_Statics::JMDoorComponent_eventGetState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_GetState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_GetState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execGetState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EJMDoorState*)Z_Param__Result=P_THIS->GetState();
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function GetState *****************************************

// ********** Begin Class UJMDoorComponent Function IsLocked ***************************************
struct Z_Construct_UFunction_UJMDoorComponent_IsLocked_Statics
{
	struct JMDoorComponent_eventIsLocked_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsLocked constinit property declarations ******************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsLocked constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsLocked Property Definitions *****************************************
void Z_Construct_UFunction_UJMDoorComponent_IsLocked_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMDoorComponent_eventIsLocked_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMDoorComponent_IsLocked_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMDoorComponent_eventIsLocked_Parms), &Z_Construct_UFunction_UJMDoorComponent_IsLocked_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_IsLocked_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_IsLocked_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_IsLocked_Statics::PropPointers) < 2048);
// ********** End Function IsLocked Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_IsLocked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "IsLocked", 	Z_Construct_UFunction_UJMDoorComponent_IsLocked_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_IsLocked_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_IsLocked_Statics::JMDoorComponent_eventIsLocked_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_IsLocked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_IsLocked_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_IsLocked_Statics::JMDoorComponent_eventIsLocked_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_IsLocked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_IsLocked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execIsLocked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsLocked();
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function IsLocked *****************************************

// ********** Begin Class UJMDoorComponent Function LockDoor ***************************************
struct Z_Construct_UFunction_UJMDoorComponent_LockDoor_Statics
{
	struct JMDoorComponent_eventLockDoor_Parms
	{
		FJMDoorResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Access" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function LockDoor constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LockDoor constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LockDoor Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorComponent_LockDoor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventLockDoor_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMDoorResult, METADATA_PARAMS(0, nullptr) }; // 1639184842
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_LockDoor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_LockDoor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_LockDoor_Statics::PropPointers) < 2048);
// ********** End Function LockDoor Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_LockDoor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "LockDoor", 	Z_Construct_UFunction_UJMDoorComponent_LockDoor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_LockDoor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_LockDoor_Statics::JMDoorComponent_eventLockDoor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_LockDoor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_LockDoor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_LockDoor_Statics::JMDoorComponent_eventLockDoor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_LockDoor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_LockDoor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execLockDoor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMDoorResult*)Z_Param__Result=P_THIS->LockDoor();
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function LockDoor *****************************************

// ********** Begin Class UJMDoorComponent Function OpenDoor ***************************************
struct Z_Construct_UFunction_UJMDoorComponent_OpenDoor_Statics
{
	struct JMDoorComponent_eventOpenDoor_Parms
	{
		FJMDoorUseContext Context;
		FJMDoorResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OpenDoor constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OpenDoor constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OpenDoor Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorComponent_OpenDoor_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventOpenDoor_Parms, Context), Z_Construct_UScriptStruct_FJMDoorUseContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3552665729
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorComponent_OpenDoor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventOpenDoor_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMDoorResult, METADATA_PARAMS(0, nullptr) }; // 1639184842
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_OpenDoor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_OpenDoor_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_OpenDoor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_OpenDoor_Statics::PropPointers) < 2048);
// ********** End Function OpenDoor Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_OpenDoor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "OpenDoor", 	Z_Construct_UFunction_UJMDoorComponent_OpenDoor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_OpenDoor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_OpenDoor_Statics::JMDoorComponent_eventOpenDoor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_OpenDoor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_OpenDoor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_OpenDoor_Statics::JMDoorComponent_eventOpenDoor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_OpenDoor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_OpenDoor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execOpenDoor)
{
	P_GET_STRUCT_REF(FJMDoorUseContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMDoorResult*)Z_Param__Result=P_THIS->OpenDoor(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function OpenDoor *****************************************

// ********** Begin Class UJMDoorComponent Function OpenSlideDoor **********************************
struct Z_Construct_UFunction_UJMDoorComponent_OpenSlideDoor_Statics
{
	struct JMDoorComponent_eventOpenSlideDoor_Parms
	{
		EJMSlideDoorPanel Panel;
		FJMDoorUseContext Context;
		FJMDoorResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Slide Door" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Explicit panel control. Panel direction is fixed by the sliding movement component. */" },
#endif
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Explicit panel control. Panel direction is fixed by the sliding movement component." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OpenSlideDoor constinit property declarations *************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Panel_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Panel;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OpenSlideDoor constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OpenSlideDoor Property Definitions ************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMDoorComponent_OpenSlideDoor_Statics::NewProp_Panel_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMDoorComponent_OpenSlideDoor_Statics::NewProp_Panel = { "Panel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventOpenSlideDoor_Parms, Panel), Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel, METADATA_PARAMS(0, nullptr) }; // 1478343840
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorComponent_OpenSlideDoor_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventOpenSlideDoor_Parms, Context), Z_Construct_UScriptStruct_FJMDoorUseContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3552665729
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorComponent_OpenSlideDoor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventOpenSlideDoor_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMDoorResult, METADATA_PARAMS(0, nullptr) }; // 1639184842
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_OpenSlideDoor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_OpenSlideDoor_Statics::NewProp_Panel_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_OpenSlideDoor_Statics::NewProp_Panel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_OpenSlideDoor_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_OpenSlideDoor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_OpenSlideDoor_Statics::PropPointers) < 2048);
// ********** End Function OpenSlideDoor Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_OpenSlideDoor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "OpenSlideDoor", 	Z_Construct_UFunction_UJMDoorComponent_OpenSlideDoor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_OpenSlideDoor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_OpenSlideDoor_Statics::JMDoorComponent_eventOpenSlideDoor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_OpenSlideDoor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_OpenSlideDoor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_OpenSlideDoor_Statics::JMDoorComponent_eventOpenSlideDoor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_OpenSlideDoor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_OpenSlideDoor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execOpenSlideDoor)
{
	P_GET_ENUM(EJMSlideDoorPanel,Z_Param_Panel);
	P_GET_STRUCT_REF(FJMDoorUseContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMDoorResult*)Z_Param__Result=P_THIS->OpenSlideDoor(EJMSlideDoorPanel(Z_Param_Panel),Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function OpenSlideDoor ************************************

// ********** Begin Class UJMDoorComponent Function RestoreSaveData ********************************
struct Z_Construct_UFunction_UJMDoorComponent_RestoreSaveData_Statics
{
	struct JMDoorComponent_eventRestoreSaveData_Parms
	{
		FJMDoorSaveData SaveData;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Save" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SaveData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RestoreSaveData constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SaveData;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RestoreSaveData constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RestoreSaveData Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorComponent_RestoreSaveData_Statics::NewProp_SaveData = { "SaveData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventRestoreSaveData_Parms, SaveData), Z_Construct_UScriptStruct_FJMDoorSaveData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SaveData_MetaData), NewProp_SaveData_MetaData) }; // 362659228
void Z_Construct_UFunction_UJMDoorComponent_RestoreSaveData_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMDoorComponent_eventRestoreSaveData_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMDoorComponent_RestoreSaveData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMDoorComponent_eventRestoreSaveData_Parms), &Z_Construct_UFunction_UJMDoorComponent_RestoreSaveData_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_RestoreSaveData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_RestoreSaveData_Statics::NewProp_SaveData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_RestoreSaveData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_RestoreSaveData_Statics::PropPointers) < 2048);
// ********** End Function RestoreSaveData Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_RestoreSaveData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "RestoreSaveData", 	Z_Construct_UFunction_UJMDoorComponent_RestoreSaveData_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_RestoreSaveData_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_RestoreSaveData_Statics::JMDoorComponent_eventRestoreSaveData_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_RestoreSaveData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_RestoreSaveData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_RestoreSaveData_Statics::JMDoorComponent_eventRestoreSaveData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_RestoreSaveData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_RestoreSaveData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execRestoreSaveData)
{
	P_GET_STRUCT_REF(FJMDoorSaveData,Z_Param_Out_SaveData);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->RestoreSaveData(Z_Param_Out_SaveData);
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function RestoreSaveData **********************************

// ********** Begin Class UJMDoorComponent Function RetryBlockedMovement ***************************
struct Z_Construct_UFunction_UJMDoorComponent_RetryBlockedMovement_Statics
{
	struct JMDoorComponent_eventRetryBlockedMovement_Parms
	{
		FJMDoorResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Blocking" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RetryBlockedMovement constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RetryBlockedMovement constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RetryBlockedMovement Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorComponent_RetryBlockedMovement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventRetryBlockedMovement_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMDoorResult, METADATA_PARAMS(0, nullptr) }; // 1639184842
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_RetryBlockedMovement_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_RetryBlockedMovement_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_RetryBlockedMovement_Statics::PropPointers) < 2048);
// ********** End Function RetryBlockedMovement Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_RetryBlockedMovement_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "RetryBlockedMovement", 	Z_Construct_UFunction_UJMDoorComponent_RetryBlockedMovement_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_RetryBlockedMovement_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_RetryBlockedMovement_Statics::JMDoorComponent_eventRetryBlockedMovement_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_RetryBlockedMovement_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_RetryBlockedMovement_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_RetryBlockedMovement_Statics::JMDoorComponent_eventRetryBlockedMovement_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_RetryBlockedMovement()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_RetryBlockedMovement_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execRetryBlockedMovement)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMDoorResult*)Z_Param__Result=P_THIS->RetryBlockedMovement();
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function RetryBlockedMovement *****************************

// ********** Begin Class UJMDoorComponent Function SetMovementComponent ***************************
struct Z_Construct_UFunction_UJMDoorComponent_SetMovementComponent_Statics
{
	struct JMDoorComponent_eventSetMovementComponent_Parms
	{
		UJMDoorMovementComponent* InMovementComponent;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Movement" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InMovementComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetMovementComponent constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InMovementComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetMovementComponent constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetMovementComponent Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMDoorComponent_SetMovementComponent_Statics::NewProp_InMovementComponent = { "InMovementComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventSetMovementComponent_Parms, InMovementComponent), Z_Construct_UClass_UJMDoorMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InMovementComponent_MetaData), NewProp_InMovementComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_SetMovementComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_SetMovementComponent_Statics::NewProp_InMovementComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_SetMovementComponent_Statics::PropPointers) < 2048);
// ********** End Function SetMovementComponent Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_SetMovementComponent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "SetMovementComponent", 	Z_Construct_UFunction_UJMDoorComponent_SetMovementComponent_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_SetMovementComponent_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_SetMovementComponent_Statics::JMDoorComponent_eventSetMovementComponent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_SetMovementComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_SetMovementComponent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_SetMovementComponent_Statics::JMDoorComponent_eventSetMovementComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_SetMovementComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_SetMovementComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execSetMovementComponent)
{
	P_GET_OBJECT(UJMDoorMovementComponent,Z_Param_InMovementComponent);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMovementComponent(Z_Param_InMovementComponent);
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function SetMovementComponent *****************************

// ********** Begin Class UJMDoorComponent Function ToggleDoor *************************************
struct Z_Construct_UFunction_UJMDoorComponent_ToggleDoor_Statics
{
	struct JMDoorComponent_eventToggleDoor_Parms
	{
		FJMDoorUseContext Context;
		FJMDoorResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ToggleDoor constinit property declarations ****************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ToggleDoor constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ToggleDoor Property Definitions ***************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorComponent_ToggleDoor_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventToggleDoor_Parms, Context), Z_Construct_UScriptStruct_FJMDoorUseContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3552665729
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorComponent_ToggleDoor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventToggleDoor_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMDoorResult, METADATA_PARAMS(0, nullptr) }; // 1639184842
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_ToggleDoor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_ToggleDoor_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_ToggleDoor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_ToggleDoor_Statics::PropPointers) < 2048);
// ********** End Function ToggleDoor Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_ToggleDoor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "ToggleDoor", 	Z_Construct_UFunction_UJMDoorComponent_ToggleDoor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_ToggleDoor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_ToggleDoor_Statics::JMDoorComponent_eventToggleDoor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_ToggleDoor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_ToggleDoor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_ToggleDoor_Statics::JMDoorComponent_eventToggleDoor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_ToggleDoor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_ToggleDoor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execToggleDoor)
{
	P_GET_STRUCT_REF(FJMDoorUseContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMDoorResult*)Z_Param__Result=P_THIS->ToggleDoor(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function ToggleDoor ***************************************

// ********** Begin Class UJMDoorComponent Function UnlockDoor *************************************
struct Z_Construct_UFunction_UJMDoorComponent_UnlockDoor_Statics
{
	struct JMDoorComponent_eventUnlockDoor_Parms
	{
		FJMDoorUseContext Context;
		FJMDoorResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Access" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function UnlockDoor constinit property declarations ****************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UnlockDoor constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UnlockDoor Property Definitions ***************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorComponent_UnlockDoor_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventUnlockDoor_Parms, Context), Z_Construct_UScriptStruct_FJMDoorUseContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3552665729
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorComponent_UnlockDoor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventUnlockDoor_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMDoorResult, METADATA_PARAMS(0, nullptr) }; // 1639184842
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_UnlockDoor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_UnlockDoor_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_UnlockDoor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_UnlockDoor_Statics::PropPointers) < 2048);
// ********** End Function UnlockDoor Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_UnlockDoor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "UnlockDoor", 	Z_Construct_UFunction_UJMDoorComponent_UnlockDoor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_UnlockDoor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_UnlockDoor_Statics::JMDoorComponent_eventUnlockDoor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_UnlockDoor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_UnlockDoor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_UnlockDoor_Statics::JMDoorComponent_eventUnlockDoor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_UnlockDoor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_UnlockDoor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execUnlockDoor)
{
	P_GET_STRUCT_REF(FJMDoorUseContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMDoorResult*)Z_Param__Result=P_THIS->UnlockDoor(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function UnlockDoor ***************************************

// ********** Begin Class UJMDoorComponent Function ValidateConfiguration **************************
struct Z_Construct_UFunction_UJMDoorComponent_ValidateConfiguration_Statics
{
	struct JMDoorComponent_eventValidateConfiguration_Parms
	{
		TArray<FText> OutErrors;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Validation" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ValidateConfiguration constinit property declarations *****************
	static const UECodeGen_Private::FTextPropertyParams NewProp_OutErrors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutErrors;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ValidateConfiguration constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ValidateConfiguration Property Definitions ****************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UJMDoorComponent_ValidateConfiguration_Statics::NewProp_OutErrors_Inner = { "OutErrors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UJMDoorComponent_ValidateConfiguration_Statics::NewProp_OutErrors = { "OutErrors", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorComponent_eventValidateConfiguration_Parms, OutErrors), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UJMDoorComponent_ValidateConfiguration_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMDoorComponent_eventValidateConfiguration_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMDoorComponent_ValidateConfiguration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMDoorComponent_eventValidateConfiguration_Parms), &Z_Construct_UFunction_UJMDoorComponent_ValidateConfiguration_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorComponent_ValidateConfiguration_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_ValidateConfiguration_Statics::NewProp_OutErrors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_ValidateConfiguration_Statics::NewProp_OutErrors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorComponent_ValidateConfiguration_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_ValidateConfiguration_Statics::PropPointers) < 2048);
// ********** End Function ValidateConfiguration Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorComponent_ValidateConfiguration_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorComponent, nullptr, "ValidateConfiguration", 	Z_Construct_UFunction_UJMDoorComponent_ValidateConfiguration_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_ValidateConfiguration_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorComponent_ValidateConfiguration_Statics::JMDoorComponent_eventValidateConfiguration_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorComponent_ValidateConfiguration_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorComponent_ValidateConfiguration_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorComponent_ValidateConfiguration_Statics::JMDoorComponent_eventValidateConfiguration_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorComponent_ValidateConfiguration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorComponent_ValidateConfiguration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorComponent::execValidateConfiguration)
{
	P_GET_TARRAY_REF(FText,Z_Param_Out_OutErrors);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ValidateConfiguration(Z_Param_Out_OutErrors);
	P_NATIVE_END;
}
// ********** End Class UJMDoorComponent Function ValidateConfiguration ****************************

// ********** Begin Class UJMDoorComponent *********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMDoorComponent;
UClass* UJMDoorComponent::GetPrivateStaticClass()
{
	using TClass = UJMDoorComponent;
	if (!Z_Registration_Info_UClass_UJMDoorComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMDoorComponent"),
			Z_Registration_Info_UClass_UJMDoorComponent.InnerSingleton,
			StaticRegisterNativesUJMDoorComponent,
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
	return Z_Registration_Info_UClass_UJMDoorComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMDoorComponent_NoRegister()
{
	return UJMDoorComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMDoorComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JMGameplay" },
		{ "IncludePath", "Door/JMDoorComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Config_MetaData[] = {
		{ "Category", "JM Door|Config" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MovementComponent_MetaData[] = {
		{ "Category", "JM Door|Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Runtime wiring only. Exposing an ActorComponent pointer as EditAnywhere makes\n// the Details panel recursively expand sibling instanced components.\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Runtime wiring only. Exposing an ActorComponent pointer as EditAnywhere makes\nthe Details panel recursively expand sibling instanced components." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PersistentId_MetaData[] = {
		{ "Category", "JM Door|Save" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectiveTargetIdentifier_MetaData[] = {
		{ "Category", "JM Door|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Stable, designer-authored semantic identifier for event filtering (for example Door.Office.Main). */" },
#endif
		{ "DisplayName", "Objective Target Identifier" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stable, designer-authored semantic identifier for event filtering (for example Door.Office.Main)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDoorStateChanged_MetaData[] = {
		{ "Category", "JM Door|Events" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnAccessDenied_MetaData[] = {
		{ "Category", "JM Door|Events" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnNoiseEmitted_MetaData[] = {
		{ "Category", "JM Door|Events" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDoorObstructed_MetaData[] = {
		{ "Category", "JM Door|Events" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDurabilityChanged_MetaData[] = {
		{ "Category", "JM Door|Events" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSlideDoorPanelStateChanged_MetaData[] = {
		{ "Category", "JM Door|Slide Door|Events" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentState_MetaData[] = {
		{ "Category", "JM Door|Runtime" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentOpenFraction_MetaData[] = {
		{ "Category", "JM Door|Runtime" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetOpenFraction_MetaData[] = {
		{ "Category", "JM Door|Runtime" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLocked_MetaData[] = {
		{ "Category", "JM Door|Runtime" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLockBroken_MetaData[] = {
		{ "Category", "JM Door|Runtime" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DoorDurability_MetaData[] = {
		{ "Category", "JM Door|Runtime" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LockDurability_MetaData[] = {
		{ "Category", "JM Door|Runtime" },
		{ "ModuleRelativePath", "Public/Door/JMDoorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMDoorComponent constinit property declarations *************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Config;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MovementComponent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PersistentId;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ObjectiveTargetIdentifier;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDoorStateChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAccessDenied;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnNoiseEmitted;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDoorObstructed;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDurabilityChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSlideDoorPanelStateChanged;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentState;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentOpenFraction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TargetOpenFraction;
	static void NewProp_bLocked_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLocked;
	static void NewProp_bLockBroken_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLockBroken;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DoorDurability;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LockDurability;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMDoorComponent constinit property declarations ***************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ApplyDoorDamage"), .Pointer = &UJMDoorComponent::execApplyDoorDamage },
		{ .NameUTF8 = UTF8TEXT("ApplyLockDamage"), .Pointer = &UJMDoorComponent::execApplyLockDamage },
		{ .NameUTF8 = UTF8TEXT("CanExecuteCommand"), .Pointer = &UJMDoorComponent::execCanExecuteCommand },
		{ .NameUTF8 = UTF8TEXT("CaptureSaveData"), .Pointer = &UJMDoorComponent::execCaptureSaveData },
		{ .NameUTF8 = UTF8TEXT("CloseDoor"), .Pointer = &UJMDoorComponent::execCloseDoor },
		{ .NameUTF8 = UTF8TEXT("CloseSlideDoor"), .Pointer = &UJMDoorComponent::execCloseSlideDoor },
		{ .NameUTF8 = UTF8TEXT("ExecuteCommand"), .Pointer = &UJMDoorComponent::execExecuteCommand },
		{ .NameUTF8 = UTF8TEXT("ForceOpenDoor"), .Pointer = &UJMDoorComponent::execForceOpenDoor },
		{ .NameUTF8 = UTF8TEXT("GetDoorDurability"), .Pointer = &UJMDoorComponent::execGetDoorDurability },
		{ .NameUTF8 = UTF8TEXT("GetLockDurability"), .Pointer = &UJMDoorComponent::execGetLockDurability },
		{ .NameUTF8 = UTF8TEXT("GetOpenFraction"), .Pointer = &UJMDoorComponent::execGetOpenFraction },
		{ .NameUTF8 = UTF8TEXT("GetSlideDoorPanelOpenFraction"), .Pointer = &UJMDoorComponent::execGetSlideDoorPanelOpenFraction },
		{ .NameUTF8 = UTF8TEXT("GetSlideDoorPanelState"), .Pointer = &UJMDoorComponent::execGetSlideDoorPanelState },
		{ .NameUTF8 = UTF8TEXT("GetState"), .Pointer = &UJMDoorComponent::execGetState },
		{ .NameUTF8 = UTF8TEXT("IsLocked"), .Pointer = &UJMDoorComponent::execIsLocked },
		{ .NameUTF8 = UTF8TEXT("LockDoor"), .Pointer = &UJMDoorComponent::execLockDoor },
		{ .NameUTF8 = UTF8TEXT("OpenDoor"), .Pointer = &UJMDoorComponent::execOpenDoor },
		{ .NameUTF8 = UTF8TEXT("OpenSlideDoor"), .Pointer = &UJMDoorComponent::execOpenSlideDoor },
		{ .NameUTF8 = UTF8TEXT("RestoreSaveData"), .Pointer = &UJMDoorComponent::execRestoreSaveData },
		{ .NameUTF8 = UTF8TEXT("RetryBlockedMovement"), .Pointer = &UJMDoorComponent::execRetryBlockedMovement },
		{ .NameUTF8 = UTF8TEXT("SetMovementComponent"), .Pointer = &UJMDoorComponent::execSetMovementComponent },
		{ .NameUTF8 = UTF8TEXT("ToggleDoor"), .Pointer = &UJMDoorComponent::execToggleDoor },
		{ .NameUTF8 = UTF8TEXT("UnlockDoor"), .Pointer = &UJMDoorComponent::execUnlockDoor },
		{ .NameUTF8 = UTF8TEXT("ValidateConfiguration"), .Pointer = &UJMDoorComponent::execValidateConfiguration },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMDoorComponent_ApplyDoorDamage, "ApplyDoorDamage" }, // 3762464971
		{ &Z_Construct_UFunction_UJMDoorComponent_ApplyLockDamage, "ApplyLockDamage" }, // 3879177655
		{ &Z_Construct_UFunction_UJMDoorComponent_CanExecuteCommand, "CanExecuteCommand" }, // 2167671704
		{ &Z_Construct_UFunction_UJMDoorComponent_CaptureSaveData, "CaptureSaveData" }, // 4028824188
		{ &Z_Construct_UFunction_UJMDoorComponent_CloseDoor, "CloseDoor" }, // 2636009766
		{ &Z_Construct_UFunction_UJMDoorComponent_CloseSlideDoor, "CloseSlideDoor" }, // 43801222
		{ &Z_Construct_UFunction_UJMDoorComponent_ExecuteCommand, "ExecuteCommand" }, // 4144280442
		{ &Z_Construct_UFunction_UJMDoorComponent_ForceOpenDoor, "ForceOpenDoor" }, // 1605395019
		{ &Z_Construct_UFunction_UJMDoorComponent_GetDoorDurability, "GetDoorDurability" }, // 3343128478
		{ &Z_Construct_UFunction_UJMDoorComponent_GetLockDurability, "GetLockDurability" }, // 3666872565
		{ &Z_Construct_UFunction_UJMDoorComponent_GetOpenFraction, "GetOpenFraction" }, // 1352613823
		{ &Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelOpenFraction, "GetSlideDoorPanelOpenFraction" }, // 2729425409
		{ &Z_Construct_UFunction_UJMDoorComponent_GetSlideDoorPanelState, "GetSlideDoorPanelState" }, // 768821413
		{ &Z_Construct_UFunction_UJMDoorComponent_GetState, "GetState" }, // 90873716
		{ &Z_Construct_UFunction_UJMDoorComponent_IsLocked, "IsLocked" }, // 1664935503
		{ &Z_Construct_UFunction_UJMDoorComponent_LockDoor, "LockDoor" }, // 4078152852
		{ &Z_Construct_UFunction_UJMDoorComponent_OpenDoor, "OpenDoor" }, // 1047871331
		{ &Z_Construct_UFunction_UJMDoorComponent_OpenSlideDoor, "OpenSlideDoor" }, // 1532855260
		{ &Z_Construct_UFunction_UJMDoorComponent_RestoreSaveData, "RestoreSaveData" }, // 2027847784
		{ &Z_Construct_UFunction_UJMDoorComponent_RetryBlockedMovement, "RetryBlockedMovement" }, // 2555323892
		{ &Z_Construct_UFunction_UJMDoorComponent_SetMovementComponent, "SetMovementComponent" }, // 3199158061
		{ &Z_Construct_UFunction_UJMDoorComponent_ToggleDoor, "ToggleDoor" }, // 1265781429
		{ &Z_Construct_UFunction_UJMDoorComponent_UnlockDoor, "UnlockDoor" }, // 2822463824
		{ &Z_Construct_UFunction_UJMDoorComponent_ValidateConfiguration, "ValidateConfiguration" }, // 3974450319
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMDoorComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMDoorComponent_Statics

// ********** Begin Class UJMDoorComponent Property Definitions ************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_Config = { "Config", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorComponent, Config), Z_Construct_UClass_UJMDoorConfigData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Config_MetaData), NewProp_Config_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_MovementComponent = { "MovementComponent", nullptr, (EPropertyFlags)0x011400000008201c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorComponent, MovementComponent), Z_Construct_UClass_UJMDoorMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MovementComponent_MetaData), NewProp_MovementComponent_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_PersistentId = { "PersistentId", nullptr, (EPropertyFlags)0x0010000000000815, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorComponent, PersistentId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PersistentId_MetaData), NewProp_PersistentId_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_ObjectiveTargetIdentifier = { "ObjectiveTargetIdentifier", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorComponent, ObjectiveTargetIdentifier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectiveTargetIdentifier_MetaData), NewProp_ObjectiveTargetIdentifier_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_OnDoorStateChanged = { "OnDoorStateChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorComponent, OnDoorStateChanged), Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorStateChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDoorStateChanged_MetaData), NewProp_OnDoorStateChanged_MetaData) }; // 2012848532
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_OnAccessDenied = { "OnAccessDenied", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorComponent, OnAccessDenied), Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorAccessDeniedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnAccessDenied_MetaData), NewProp_OnAccessDenied_MetaData) }; // 800576528
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_OnNoiseEmitted = { "OnNoiseEmitted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorComponent, OnNoiseEmitted), Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorNoiseSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnNoiseEmitted_MetaData), NewProp_OnNoiseEmitted_MetaData) }; // 3772413326
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_OnDoorObstructed = { "OnDoorObstructed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorComponent, OnDoorObstructed), Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorObstructedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDoorObstructed_MetaData), NewProp_OnDoorObstructed_MetaData) }; // 2352402317
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_OnDurabilityChanged = { "OnDurabilityChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorComponent, OnDurabilityChanged), Z_Construct_UDelegateFunction_JMDoorRuntime_JMDoorDurabilityChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDurabilityChanged_MetaData), NewProp_OnDurabilityChanged_MetaData) }; // 3704831891
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_OnSlideDoorPanelStateChanged = { "OnSlideDoorPanelStateChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorComponent, OnSlideDoorPanelStateChanged), Z_Construct_UDelegateFunction_JMDoorRuntime_JMSlideDoorPanelStateChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSlideDoorPanelStateChanged_MetaData), NewProp_OnSlideDoorPanelStateChanged_MetaData) }; // 1834648128
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_CurrentState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_CurrentState = { "CurrentState", nullptr, (EPropertyFlags)0x0020080000002014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorComponent, CurrentState), Z_Construct_UEnum_JMDoorRuntime_EJMDoorState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentState_MetaData), NewProp_CurrentState_MetaData) }; // 2513049645
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_CurrentOpenFraction = { "CurrentOpenFraction", nullptr, (EPropertyFlags)0x0020080000002014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorComponent, CurrentOpenFraction), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentOpenFraction_MetaData), NewProp_CurrentOpenFraction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_TargetOpenFraction = { "TargetOpenFraction", nullptr, (EPropertyFlags)0x0020080000002014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorComponent, TargetOpenFraction), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetOpenFraction_MetaData), NewProp_TargetOpenFraction_MetaData) };
void Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_bLocked_SetBit(void* Obj)
{
	((UJMDoorComponent*)Obj)->bLocked = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_bLocked = { "bLocked", nullptr, (EPropertyFlags)0x0020080000002014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMDoorComponent), &Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_bLocked_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLocked_MetaData), NewProp_bLocked_MetaData) };
void Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_bLockBroken_SetBit(void* Obj)
{
	((UJMDoorComponent*)Obj)->bLockBroken = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_bLockBroken = { "bLockBroken", nullptr, (EPropertyFlags)0x0020080000002014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMDoorComponent), &Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_bLockBroken_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLockBroken_MetaData), NewProp_bLockBroken_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_DoorDurability = { "DoorDurability", nullptr, (EPropertyFlags)0x0020080000002014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorComponent, DoorDurability), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DoorDurability_MetaData), NewProp_DoorDurability_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_LockDurability = { "LockDurability", nullptr, (EPropertyFlags)0x0020080000002014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorComponent, LockDurability), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LockDurability_MetaData), NewProp_LockDurability_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMDoorComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_Config,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_MovementComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_PersistentId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_ObjectiveTargetIdentifier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_OnDoorStateChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_OnAccessDenied,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_OnNoiseEmitted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_OnDoorObstructed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_OnDurabilityChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_OnSlideDoorPanelStateChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_CurrentState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_CurrentState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_CurrentOpenFraction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_TargetOpenFraction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_bLocked,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_bLockBroken,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_DoorDurability,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorComponent_Statics::NewProp_LockDurability,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorComponent_Statics::PropPointers) < 2048);
// ********** End Class UJMDoorComponent Property Definitions **************************************
UObject* (*const Z_Construct_UClass_UJMDoorComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMDoorComponent_Statics::ClassParams = {
	&UJMDoorComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMDoorComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMDoorComponent_Statics::Class_MetaDataParams)
};
void UJMDoorComponent::StaticRegisterNativesUJMDoorComponent()
{
	UClass* Class = UJMDoorComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMDoorComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMDoorComponent()
{
	if (!Z_Registration_Info_UClass_UJMDoorComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMDoorComponent.OuterSingleton, Z_Construct_UClass_UJMDoorComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMDoorComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMDoorComponent);
UJMDoorComponent::~UJMDoorComponent() {}
// ********** End Class UJMDoorComponent ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorComponent_h__Script_JMDoorRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMDoorComponent, UJMDoorComponent::StaticClass, TEXT("UJMDoorComponent"), &Z_Registration_Info_UClass_UJMDoorComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMDoorComponent), 1806732184U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorComponent_h__Script_JMDoorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorComponent_h__Script_JMDoorRuntime_1163127546{
	TEXT("/Script/JMDoorRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorComponent_h__Script_JMDoorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorComponent_h__Script_JMDoorRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
