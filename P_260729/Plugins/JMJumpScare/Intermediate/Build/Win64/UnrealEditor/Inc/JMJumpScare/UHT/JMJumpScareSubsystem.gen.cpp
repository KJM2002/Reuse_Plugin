// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Subsystems/JMJumpScareSubsystem.h"
#include "Types/JMJumpScareTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMJumpScareSubsystem() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAudioComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareDefinition_NoRegister();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareOverlayWidget_NoRegister();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareSubsystem();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareSubsystem_NoRegister();
JMJUMPSCARE_API UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScarePhase();
JMJUMPSCARE_API UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScareState();
JMJUMPSCARE_API UFunction* Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature();
JMJUMPSCARE_API UFunction* Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature();
JMJUMPSCARE_API UScriptStruct* Z_Construct_UScriptStruct_FJMJumpScareActiveInfo();
JMJUMPSCARE_API UScriptStruct* Z_Construct_UScriptStruct_FJMJumpScarePlayContext();
UPackage* Z_Construct_UPackage__Script_JMJumpScare();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FJMJumpScareStateChanged **********************************************
struct Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature_Statics
{
	struct _Script_JMJumpScare_eventJMJumpScareStateChanged_Parms
	{
		EJMJumpScareState OldState;
		EJMJumpScareState NewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Subsystems/JMJumpScareSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMJumpScareStateChanged constinit property declarations **************
	static const UECodeGen_Private::FBytePropertyParams NewProp_OldState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OldState;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMJumpScareStateChanged constinit property declarations ****************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMJumpScareStateChanged Property Definitions *************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature_Statics::NewProp_OldState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature_Statics::NewProp_OldState = { "OldState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMJumpScare_eventJMJumpScareStateChanged_Parms, OldState), Z_Construct_UEnum_JMJumpScare_EJMJumpScareState, METADATA_PARAMS(0, nullptr) }; // 595493008
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMJumpScare_eventJMJumpScareStateChanged_Parms, NewState), Z_Construct_UEnum_JMJumpScare_EJMJumpScareState, METADATA_PARAMS(0, nullptr) }; // 595493008
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature_Statics::NewProp_OldState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature_Statics::NewProp_OldState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature_Statics::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature_Statics::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMJumpScareStateChanged Property Definitions ***************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMJumpScare, nullptr, "JMJumpScareStateChanged__DelegateSignature", 	Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature_Statics::_Script_JMJumpScare_eventJMJumpScareStateChanged_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature_Statics::_Script_JMJumpScare_eventJMJumpScareStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMJumpScareStateChanged_DelegateWrapper(const FMulticastScriptDelegate& JMJumpScareStateChanged, EJMJumpScareState OldState, EJMJumpScareState NewState)
{
	struct _Script_JMJumpScare_eventJMJumpScareStateChanged_Parms
	{
		EJMJumpScareState OldState;
		EJMJumpScareState NewState;
	};
	_Script_JMJumpScare_eventJMJumpScareStateChanged_Parms Parms;
	Parms.OldState=OldState;
	Parms.NewState=NewState;
	JMJumpScareStateChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMJumpScareStateChanged ************************************************

// ********** Begin Delegate FJMJumpScarePhaseChanged **********************************************
struct Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature_Statics
{
	struct _Script_JMJumpScare_eventJMJumpScarePhaseChanged_Parms
	{
		EJMJumpScarePhase OldPhase;
		EJMJumpScarePhase NewPhase;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Subsystems/JMJumpScareSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMJumpScarePhaseChanged constinit property declarations **************
	static const UECodeGen_Private::FBytePropertyParams NewProp_OldPhase_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OldPhase;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewPhase_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewPhase;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMJumpScarePhaseChanged constinit property declarations ****************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMJumpScarePhaseChanged Property Definitions *************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature_Statics::NewProp_OldPhase_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature_Statics::NewProp_OldPhase = { "OldPhase", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMJumpScare_eventJMJumpScarePhaseChanged_Parms, OldPhase), Z_Construct_UEnum_JMJumpScare_EJMJumpScarePhase, METADATA_PARAMS(0, nullptr) }; // 3098439532
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature_Statics::NewProp_NewPhase_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature_Statics::NewProp_NewPhase = { "NewPhase", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMJumpScare_eventJMJumpScarePhaseChanged_Parms, NewPhase), Z_Construct_UEnum_JMJumpScare_EJMJumpScarePhase, METADATA_PARAMS(0, nullptr) }; // 3098439532
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature_Statics::NewProp_OldPhase_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature_Statics::NewProp_OldPhase,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature_Statics::NewProp_NewPhase_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature_Statics::NewProp_NewPhase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMJumpScarePhaseChanged Property Definitions ***************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMJumpScare, nullptr, "JMJumpScarePhaseChanged__DelegateSignature", 	Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature_Statics::_Script_JMJumpScare_eventJMJumpScarePhaseChanged_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature_Statics::_Script_JMJumpScare_eventJMJumpScarePhaseChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMJumpScarePhaseChanged_DelegateWrapper(const FMulticastScriptDelegate& JMJumpScarePhaseChanged, EJMJumpScarePhase OldPhase, EJMJumpScarePhase NewPhase)
{
	struct _Script_JMJumpScare_eventJMJumpScarePhaseChanged_Parms
	{
		EJMJumpScarePhase OldPhase;
		EJMJumpScarePhase NewPhase;
	};
	_Script_JMJumpScare_eventJMJumpScarePhaseChanged_Parms Parms;
	Parms.OldPhase=OldPhase;
	Parms.NewPhase=NewPhase;
	JMJumpScarePhaseChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMJumpScarePhaseChanged ************************************************

// ********** Begin Class UJMJumpScareSubsystem Function CancelJumpScare ***************************
struct Z_Construct_UFunction_UJMJumpScareSubsystem_CancelJumpScare_Statics
{
	struct JMJumpScareSubsystem_eventCancelJumpScare_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Subsystems/JMJumpScareSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CancelJumpScare constinit property declarations ***********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CancelJumpScare constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CancelJumpScare Property Definitions **********************************
void Z_Construct_UFunction_UJMJumpScareSubsystem_CancelJumpScare_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMJumpScareSubsystem_eventCancelJumpScare_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMJumpScareSubsystem_CancelJumpScare_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMJumpScareSubsystem_eventCancelJumpScare_Parms), &Z_Construct_UFunction_UJMJumpScareSubsystem_CancelJumpScare_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMJumpScareSubsystem_CancelJumpScare_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMJumpScareSubsystem_CancelJumpScare_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareSubsystem_CancelJumpScare_Statics::PropPointers) < 2048);
// ********** End Function CancelJumpScare Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMJumpScareSubsystem_CancelJumpScare_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMJumpScareSubsystem, nullptr, "CancelJumpScare", 	Z_Construct_UFunction_UJMJumpScareSubsystem_CancelJumpScare_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareSubsystem_CancelJumpScare_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMJumpScareSubsystem_CancelJumpScare_Statics::JMJumpScareSubsystem_eventCancelJumpScare_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareSubsystem_CancelJumpScare_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMJumpScareSubsystem_CancelJumpScare_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMJumpScareSubsystem_CancelJumpScare_Statics::JMJumpScareSubsystem_eventCancelJumpScare_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMJumpScareSubsystem_CancelJumpScare()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMJumpScareSubsystem_CancelJumpScare_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMJumpScareSubsystem::execCancelJumpScare)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CancelJumpScare();
	P_NATIVE_END;
}
// ********** End Class UJMJumpScareSubsystem Function CancelJumpScare *****************************

// ********** Begin Class UJMJumpScareSubsystem Function GetActiveJumpScare ************************
struct Z_Construct_UFunction_UJMJumpScareSubsystem_GetActiveJumpScare_Statics
{
	struct JMJumpScareSubsystem_eventGetActiveJumpScare_Parms
	{
		FJMJumpScareActiveInfo ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Subsystems/JMJumpScareSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetActiveJumpScare constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetActiveJumpScare constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetActiveJumpScare Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMJumpScareSubsystem_GetActiveJumpScare_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMJumpScareSubsystem_eventGetActiveJumpScare_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMJumpScareActiveInfo, METADATA_PARAMS(0, nullptr) }; // 3165102511
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMJumpScareSubsystem_GetActiveJumpScare_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMJumpScareSubsystem_GetActiveJumpScare_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareSubsystem_GetActiveJumpScare_Statics::PropPointers) < 2048);
// ********** End Function GetActiveJumpScare Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMJumpScareSubsystem_GetActiveJumpScare_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMJumpScareSubsystem, nullptr, "GetActiveJumpScare", 	Z_Construct_UFunction_UJMJumpScareSubsystem_GetActiveJumpScare_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareSubsystem_GetActiveJumpScare_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMJumpScareSubsystem_GetActiveJumpScare_Statics::JMJumpScareSubsystem_eventGetActiveJumpScare_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareSubsystem_GetActiveJumpScare_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMJumpScareSubsystem_GetActiveJumpScare_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMJumpScareSubsystem_GetActiveJumpScare_Statics::JMJumpScareSubsystem_eventGetActiveJumpScare_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMJumpScareSubsystem_GetActiveJumpScare()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMJumpScareSubsystem_GetActiveJumpScare_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMJumpScareSubsystem::execGetActiveJumpScare)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMJumpScareActiveInfo*)Z_Param__Result=P_THIS->GetActiveJumpScare();
	P_NATIVE_END;
}
// ********** End Class UJMJumpScareSubsystem Function GetActiveJumpScare **************************

// ********** Begin Class UJMJumpScareSubsystem Function GetPhase **********************************
struct Z_Construct_UFunction_UJMJumpScareSubsystem_GetPhase_Statics
{
	struct JMJumpScareSubsystem_eventGetPhase_Parms
	{
		EJMJumpScarePhase ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Subsystems/JMJumpScareSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPhase constinit property declarations ******************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPhase constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPhase Property Definitions *****************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMJumpScareSubsystem_GetPhase_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMJumpScareSubsystem_GetPhase_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMJumpScareSubsystem_eventGetPhase_Parms, ReturnValue), Z_Construct_UEnum_JMJumpScare_EJMJumpScarePhase, METADATA_PARAMS(0, nullptr) }; // 3098439532
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMJumpScareSubsystem_GetPhase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMJumpScareSubsystem_GetPhase_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMJumpScareSubsystem_GetPhase_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareSubsystem_GetPhase_Statics::PropPointers) < 2048);
// ********** End Function GetPhase Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMJumpScareSubsystem_GetPhase_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMJumpScareSubsystem, nullptr, "GetPhase", 	Z_Construct_UFunction_UJMJumpScareSubsystem_GetPhase_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareSubsystem_GetPhase_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMJumpScareSubsystem_GetPhase_Statics::JMJumpScareSubsystem_eventGetPhase_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareSubsystem_GetPhase_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMJumpScareSubsystem_GetPhase_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMJumpScareSubsystem_GetPhase_Statics::JMJumpScareSubsystem_eventGetPhase_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMJumpScareSubsystem_GetPhase()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMJumpScareSubsystem_GetPhase_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMJumpScareSubsystem::execGetPhase)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EJMJumpScarePhase*)Z_Param__Result=P_THIS->GetPhase();
	P_NATIVE_END;
}
// ********** End Class UJMJumpScareSubsystem Function GetPhase ************************************

// ********** Begin Class UJMJumpScareSubsystem Function GetState **********************************
struct Z_Construct_UFunction_UJMJumpScareSubsystem_GetState_Statics
{
	struct JMJumpScareSubsystem_eventGetState_Parms
	{
		EJMJumpScareState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Subsystems/JMJumpScareSubsystem.h" },
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
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMJumpScareSubsystem_GetState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMJumpScareSubsystem_GetState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMJumpScareSubsystem_eventGetState_Parms, ReturnValue), Z_Construct_UEnum_JMJumpScare_EJMJumpScareState, METADATA_PARAMS(0, nullptr) }; // 595493008
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMJumpScareSubsystem_GetState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMJumpScareSubsystem_GetState_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMJumpScareSubsystem_GetState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareSubsystem_GetState_Statics::PropPointers) < 2048);
// ********** End Function GetState Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMJumpScareSubsystem_GetState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMJumpScareSubsystem, nullptr, "GetState", 	Z_Construct_UFunction_UJMJumpScareSubsystem_GetState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareSubsystem_GetState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMJumpScareSubsystem_GetState_Statics::JMJumpScareSubsystem_eventGetState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareSubsystem_GetState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMJumpScareSubsystem_GetState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMJumpScareSubsystem_GetState_Statics::JMJumpScareSubsystem_eventGetState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMJumpScareSubsystem_GetState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMJumpScareSubsystem_GetState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMJumpScareSubsystem::execGetState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EJMJumpScareState*)Z_Param__Result=P_THIS->GetState();
	P_NATIVE_END;
}
// ********** End Class UJMJumpScareSubsystem Function GetState ************************************

// ********** Begin Class UJMJumpScareSubsystem Function IsJumpScarePlaying ************************
struct Z_Construct_UFunction_UJMJumpScareSubsystem_IsJumpScarePlaying_Statics
{
	struct JMJumpScareSubsystem_eventIsJumpScarePlaying_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Subsystems/JMJumpScareSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsJumpScarePlaying constinit property declarations ********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsJumpScarePlaying constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsJumpScarePlaying Property Definitions *******************************
void Z_Construct_UFunction_UJMJumpScareSubsystem_IsJumpScarePlaying_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMJumpScareSubsystem_eventIsJumpScarePlaying_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMJumpScareSubsystem_IsJumpScarePlaying_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMJumpScareSubsystem_eventIsJumpScarePlaying_Parms), &Z_Construct_UFunction_UJMJumpScareSubsystem_IsJumpScarePlaying_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMJumpScareSubsystem_IsJumpScarePlaying_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMJumpScareSubsystem_IsJumpScarePlaying_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareSubsystem_IsJumpScarePlaying_Statics::PropPointers) < 2048);
// ********** End Function IsJumpScarePlaying Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMJumpScareSubsystem_IsJumpScarePlaying_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMJumpScareSubsystem, nullptr, "IsJumpScarePlaying", 	Z_Construct_UFunction_UJMJumpScareSubsystem_IsJumpScarePlaying_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareSubsystem_IsJumpScarePlaying_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMJumpScareSubsystem_IsJumpScarePlaying_Statics::JMJumpScareSubsystem_eventIsJumpScarePlaying_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareSubsystem_IsJumpScarePlaying_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMJumpScareSubsystem_IsJumpScarePlaying_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMJumpScareSubsystem_IsJumpScarePlaying_Statics::JMJumpScareSubsystem_eventIsJumpScarePlaying_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMJumpScareSubsystem_IsJumpScarePlaying()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMJumpScareSubsystem_IsJumpScarePlaying_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMJumpScareSubsystem::execIsJumpScarePlaying)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsJumpScarePlaying();
	P_NATIVE_END;
}
// ********** End Class UJMJumpScareSubsystem Function IsJumpScarePlaying **************************

// ********** Begin Class UJMJumpScareSubsystem Function ResetOncePolicy ***************************
struct Z_Construct_UFunction_UJMJumpScareSubsystem_ResetOncePolicy_Statics
{
	struct JMJumpScareSubsystem_eventResetOncePolicy_Parms
	{
		UObject* SourceOrDefinition;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Subsystems/JMJumpScareSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResetOncePolicy constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SourceOrDefinition;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ResetOncePolicy constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ResetOncePolicy Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMJumpScareSubsystem_ResetOncePolicy_Statics::NewProp_SourceOrDefinition = { "SourceOrDefinition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMJumpScareSubsystem_eventResetOncePolicy_Parms, SourceOrDefinition), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMJumpScareSubsystem_ResetOncePolicy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMJumpScareSubsystem_ResetOncePolicy_Statics::NewProp_SourceOrDefinition,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareSubsystem_ResetOncePolicy_Statics::PropPointers) < 2048);
// ********** End Function ResetOncePolicy Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMJumpScareSubsystem_ResetOncePolicy_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMJumpScareSubsystem, nullptr, "ResetOncePolicy", 	Z_Construct_UFunction_UJMJumpScareSubsystem_ResetOncePolicy_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareSubsystem_ResetOncePolicy_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMJumpScareSubsystem_ResetOncePolicy_Statics::JMJumpScareSubsystem_eventResetOncePolicy_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareSubsystem_ResetOncePolicy_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMJumpScareSubsystem_ResetOncePolicy_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMJumpScareSubsystem_ResetOncePolicy_Statics::JMJumpScareSubsystem_eventResetOncePolicy_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMJumpScareSubsystem_ResetOncePolicy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMJumpScareSubsystem_ResetOncePolicy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMJumpScareSubsystem::execResetOncePolicy)
{
	P_GET_OBJECT(UObject,Z_Param_SourceOrDefinition);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetOncePolicy(Z_Param_SourceOrDefinition);
	P_NATIVE_END;
}
// ********** End Class UJMJumpScareSubsystem Function ResetOncePolicy *****************************

// ********** Begin Class UJMJumpScareSubsystem ****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMJumpScareSubsystem;
UClass* UJMJumpScareSubsystem::GetPrivateStaticClass()
{
	using TClass = UJMJumpScareSubsystem;
	if (!Z_Registration_Info_UClass_UJMJumpScareSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMJumpScareSubsystem"),
			Z_Registration_Info_UClass_UJMJumpScareSubsystem.InnerSingleton,
			StaticRegisterNativesUJMJumpScareSubsystem,
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
	return Z_Registration_Info_UClass_UJMJumpScareSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMJumpScareSubsystem_NoRegister()
{
	return UJMJumpScareSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMJumpScareSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** World-owned service that presents one full-screen 2D JumpScare at a time. */" },
#endif
		{ "IncludePath", "Subsystems/JMJumpScareSubsystem.h" },
		{ "ModuleRelativePath", "Public/Subsystems/JMJumpScareSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "World-owned service that presents one full-screen 2D JumpScare at a time." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnStateChanged_MetaData[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Subsystems/JMJumpScareSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnPhaseChanged_MetaData[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Subsystems/JMJumpScareSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveDefinition_MetaData[] = {
		{ "ModuleRelativePath", "Public/Subsystems/JMJumpScareSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveContext_MetaData[] = {
		{ "ModuleRelativePath", "Public/Subsystems/JMJumpScareSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlayWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Subsystems/JMJumpScareSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnedAudio_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Subsystems/JMJumpScareSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GlitchAudio_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Subsystems/JMJumpScareSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveGlitchMaterial_MetaData[] = {
		{ "ModuleRelativePath", "Public/Subsystems/JMJumpScareSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_State_MetaData[] = {
		{ "ModuleRelativePath", "Public/Subsystems/JMJumpScareSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Phase_MetaData[] = {
		{ "ModuleRelativePath", "Public/Subsystems/JMJumpScareSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMJumpScareSubsystem constinit property declarations ********************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStateChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPhaseChanged;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveDefinition;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActiveContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlayWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawnedAudio;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GlitchAudio;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveGlitchMaterial;
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Phase_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Phase;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMJumpScareSubsystem constinit property declarations **********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CancelJumpScare"), .Pointer = &UJMJumpScareSubsystem::execCancelJumpScare },
		{ .NameUTF8 = UTF8TEXT("GetActiveJumpScare"), .Pointer = &UJMJumpScareSubsystem::execGetActiveJumpScare },
		{ .NameUTF8 = UTF8TEXT("GetPhase"), .Pointer = &UJMJumpScareSubsystem::execGetPhase },
		{ .NameUTF8 = UTF8TEXT("GetState"), .Pointer = &UJMJumpScareSubsystem::execGetState },
		{ .NameUTF8 = UTF8TEXT("IsJumpScarePlaying"), .Pointer = &UJMJumpScareSubsystem::execIsJumpScarePlaying },
		{ .NameUTF8 = UTF8TEXT("ResetOncePolicy"), .Pointer = &UJMJumpScareSubsystem::execResetOncePolicy },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMJumpScareSubsystem_CancelJumpScare, "CancelJumpScare" }, // 2274047033
		{ &Z_Construct_UFunction_UJMJumpScareSubsystem_GetActiveJumpScare, "GetActiveJumpScare" }, // 1155258166
		{ &Z_Construct_UFunction_UJMJumpScareSubsystem_GetPhase, "GetPhase" }, // 1630978933
		{ &Z_Construct_UFunction_UJMJumpScareSubsystem_GetState, "GetState" }, // 1692836372
		{ &Z_Construct_UFunction_UJMJumpScareSubsystem_IsJumpScarePlaying, "IsJumpScarePlaying" }, // 2021790788
		{ &Z_Construct_UFunction_UJMJumpScareSubsystem_ResetOncePolicy, "ResetOncePolicy" }, // 374744715
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMJumpScareSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMJumpScareSubsystem_Statics

// ********** Begin Class UJMJumpScareSubsystem Property Definitions *******************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_OnStateChanged = { "OnStateChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareSubsystem, OnStateChanged), Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnStateChanged_MetaData), NewProp_OnStateChanged_MetaData) }; // 4243719521
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_OnPhaseChanged = { "OnPhaseChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareSubsystem, OnPhaseChanged), Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnPhaseChanged_MetaData), NewProp_OnPhaseChanged_MetaData) }; // 2105654216
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_ActiveDefinition = { "ActiveDefinition", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareSubsystem, ActiveDefinition), Z_Construct_UClass_UJMJumpScareDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveDefinition_MetaData), NewProp_ActiveDefinition_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_ActiveContext = { "ActiveContext", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareSubsystem, ActiveContext), Z_Construct_UScriptStruct_FJMJumpScarePlayContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveContext_MetaData), NewProp_ActiveContext_MetaData) }; // 1435639080
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_OverlayWidget = { "OverlayWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareSubsystem, OverlayWidget), Z_Construct_UClass_UJMJumpScareOverlayWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlayWidget_MetaData), NewProp_OverlayWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_SpawnedAudio = { "SpawnedAudio", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareSubsystem, SpawnedAudio), Z_Construct_UClass_UAudioComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnedAudio_MetaData), NewProp_SpawnedAudio_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_GlitchAudio = { "GlitchAudio", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareSubsystem, GlitchAudio), Z_Construct_UClass_UAudioComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GlitchAudio_MetaData), NewProp_GlitchAudio_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_ActiveGlitchMaterial = { "ActiveGlitchMaterial", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareSubsystem, ActiveGlitchMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveGlitchMaterial_MetaData), NewProp_ActiveGlitchMaterial_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareSubsystem, State), Z_Construct_UEnum_JMJumpScare_EJMJumpScareState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_State_MetaData), NewProp_State_MetaData) }; // 595493008
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_Phase_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_Phase = { "Phase", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareSubsystem, Phase), Z_Construct_UEnum_JMJumpScare_EJMJumpScarePhase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Phase_MetaData), NewProp_Phase_MetaData) }; // 3098439532
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMJumpScareSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_OnStateChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_OnPhaseChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_ActiveDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_ActiveContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_OverlayWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_SpawnedAudio,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_GlitchAudio,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_ActiveGlitchMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_State,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_Phase_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareSubsystem_Statics::NewProp_Phase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareSubsystem_Statics::PropPointers) < 2048);
// ********** End Class UJMJumpScareSubsystem Property Definitions *********************************
UObject* (*const Z_Construct_UClass_UJMJumpScareSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_JMJumpScare,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMJumpScareSubsystem_Statics::ClassParams = {
	&UJMJumpScareSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMJumpScareSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareSubsystem_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMJumpScareSubsystem_Statics::Class_MetaDataParams)
};
void UJMJumpScareSubsystem::StaticRegisterNativesUJMJumpScareSubsystem()
{
	UClass* Class = UJMJumpScareSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMJumpScareSubsystem_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMJumpScareSubsystem()
{
	if (!Z_Registration_Info_UClass_UJMJumpScareSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMJumpScareSubsystem.OuterSingleton, Z_Construct_UClass_UJMJumpScareSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMJumpScareSubsystem.OuterSingleton;
}
UJMJumpScareSubsystem::UJMJumpScareSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMJumpScareSubsystem);
UJMJumpScareSubsystem::~UJMJumpScareSubsystem() {}
// ********** End Class UJMJumpScareSubsystem ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Subsystems_JMJumpScareSubsystem_h__Script_JMJumpScare_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMJumpScareSubsystem, UJMJumpScareSubsystem::StaticClass, TEXT("UJMJumpScareSubsystem"), &Z_Registration_Info_UClass_UJMJumpScareSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMJumpScareSubsystem), 2908291039U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Subsystems_JMJumpScareSubsystem_h__Script_JMJumpScare_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Subsystems_JMJumpScareSubsystem_h__Script_JMJumpScare_3299509203{
	TEXT("/Script/JMJumpScare"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Subsystems_JMJumpScareSubsystem_h__Script_JMJumpScare_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Subsystems_JMJumpScareSubsystem_h__Script_JMJumpScare_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
