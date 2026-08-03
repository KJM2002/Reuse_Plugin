// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/JMFootstepComponent.h"
#include "Types/JMFootstepTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMFootstepComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
JMFOOTSTEPRUNTIME_API UClass* Z_Construct_UClass_UJMFootstepComponent();
JMFOOTSTEPRUNTIME_API UClass* Z_Construct_UClass_UJMFootstepComponent_NoRegister();
JMFOOTSTEPRUNTIME_API UClass* Z_Construct_UClass_UJMFootstepSet_NoRegister();
JMFOOTSTEPRUNTIME_API UClass* Z_Construct_UClass_UJMFootstepSurfaceProfile_NoRegister();
JMFOOTSTEPRUNTIME_API UEnum* Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepLocomotionState();
JMFOOTSTEPRUNTIME_API UEnum* Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepTriggerMode();
JMFOOTSTEPRUNTIME_API UFunction* Z_Construct_UDelegateFunction_JMFootstepRuntime_JMFootstepPlayedSignature__DelegateSignature();
JMFOOTSTEPRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMFootstepContext();
JMFOOTSTEPRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMFootstepResult();
JMFOOTSTEPRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory();
UPackage* Z_Construct_UPackage__Script_JMFootstepRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FJMFootstepPlayedSignature ********************************************
struct Z_Construct_UDelegateFunction_JMFootstepRuntime_JMFootstepPlayedSignature__DelegateSignature_Statics
{
	struct _Script_JMFootstepRuntime_eventJMFootstepPlayedSignature_Parms
	{
		FJMFootstepResult Result;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Result_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMFootstepPlayedSignature constinit property declarations ************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Result;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMFootstepPlayedSignature constinit property declarations **************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMFootstepPlayedSignature Property Definitions ***********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_JMFootstepRuntime_JMFootstepPlayedSignature__DelegateSignature_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMFootstepRuntime_eventJMFootstepPlayedSignature_Parms, Result), Z_Construct_UScriptStruct_FJMFootstepResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Result_MetaData), NewProp_Result_MetaData) }; // 3779851243
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMFootstepRuntime_JMFootstepPlayedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMFootstepRuntime_JMFootstepPlayedSignature__DelegateSignature_Statics::NewProp_Result,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMFootstepRuntime_JMFootstepPlayedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMFootstepPlayedSignature Property Definitions *************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMFootstepRuntime_JMFootstepPlayedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMFootstepRuntime, nullptr, "JMFootstepPlayedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_JMFootstepRuntime_JMFootstepPlayedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMFootstepRuntime_JMFootstepPlayedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMFootstepRuntime_JMFootstepPlayedSignature__DelegateSignature_Statics::_Script_JMFootstepRuntime_eventJMFootstepPlayedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMFootstepRuntime_JMFootstepPlayedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMFootstepRuntime_JMFootstepPlayedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMFootstepRuntime_JMFootstepPlayedSignature__DelegateSignature_Statics::_Script_JMFootstepRuntime_eventJMFootstepPlayedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMFootstepRuntime_JMFootstepPlayedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMFootstepRuntime_JMFootstepPlayedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMFootstepPlayedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMFootstepPlayedSignature, FJMFootstepResult const& Result)
{
	struct _Script_JMFootstepRuntime_eventJMFootstepPlayedSignature_Parms
	{
		FJMFootstepResult Result;
	};
	_Script_JMFootstepRuntime_eventJMFootstepPlayedSignature_Parms Parms;
	Parms.Result=Result;
	JMFootstepPlayedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMFootstepPlayedSignature **********************************************

// ********** Begin ScriptStruct FJMFootstepVariantSoundHistory ************************************
struct Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMFootstepVariantSoundHistory); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMFootstepVariantSoundHistory); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalkIndex_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RunIndex_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CrouchWalkIndex_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LegacyIndex_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMFootstepVariantSoundHistory constinit property declarations ****
	static const UECodeGen_Private::FIntPropertyParams NewProp_WalkIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RunIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CrouchWalkIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LegacyIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMFootstepVariantSoundHistory constinit property declarations ******
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMFootstepVariantSoundHistory>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMFootstepVariantSoundHistory;
class UScriptStruct* FJMFootstepVariantSoundHistory::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMFootstepVariantSoundHistory.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMFootstepVariantSoundHistory.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory, (UObject*)Z_Construct_UPackage__Script_JMFootstepRuntime(), TEXT("JMFootstepVariantSoundHistory"));
	}
	return Z_Registration_Info_UScriptStruct_FJMFootstepVariantSoundHistory.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMFootstepVariantSoundHistory Property Definitions ***************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory_Statics::NewProp_WalkIndex = { "WalkIndex", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepVariantSoundHistory, WalkIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalkIndex_MetaData), NewProp_WalkIndex_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory_Statics::NewProp_RunIndex = { "RunIndex", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepVariantSoundHistory, RunIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RunIndex_MetaData), NewProp_RunIndex_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory_Statics::NewProp_CrouchWalkIndex = { "CrouchWalkIndex", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepVariantSoundHistory, CrouchWalkIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CrouchWalkIndex_MetaData), NewProp_CrouchWalkIndex_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory_Statics::NewProp_LegacyIndex = { "LegacyIndex", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepVariantSoundHistory, LegacyIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LegacyIndex_MetaData), NewProp_LegacyIndex_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory_Statics::NewProp_WalkIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory_Statics::NewProp_RunIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory_Statics::NewProp_CrouchWalkIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory_Statics::NewProp_LegacyIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMFootstepVariantSoundHistory Property Definitions *****************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMFootstepRuntime,
	nullptr,
	&NewStructOps,
	"JMFootstepVariantSoundHistory",
	Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory_Statics::PropPointers),
	sizeof(FJMFootstepVariantSoundHistory),
	alignof(FJMFootstepVariantSoundHistory),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory()
{
	if (!Z_Registration_Info_UScriptStruct_FJMFootstepVariantSoundHistory.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMFootstepVariantSoundHistory.InnerSingleton, Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMFootstepVariantSoundHistory.InnerSingleton);
}
// ********** End ScriptStruct FJMFootstepVariantSoundHistory **************************************

// ********** Begin Class UJMFootstepComponent Function ClearLocomotionStateOverride ***************
struct Z_Construct_UFunction_UJMFootstepComponent_ClearLocomotionStateOverride_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Footstep" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ClearLocomotionStateOverride constinit property declarations **********
// ********** End Function ClearLocomotionStateOverride constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMFootstepComponent_ClearLocomotionStateOverride_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMFootstepComponent, nullptr, "ClearLocomotionStateOverride", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepComponent_ClearLocomotionStateOverride_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMFootstepComponent_ClearLocomotionStateOverride_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UJMFootstepComponent_ClearLocomotionStateOverride()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMFootstepComponent_ClearLocomotionStateOverride_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMFootstepComponent::execClearLocomotionStateOverride)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearLocomotionStateOverride();
	P_NATIVE_END;
}
// ********** End Class UJMFootstepComponent Function ClearLocomotionStateOverride *****************

// ********** Begin Class UJMFootstepComponent Function GetAccumulatedDistance *********************
struct Z_Construct_UFunction_UJMFootstepComponent_GetAccumulatedDistance_Statics
{
	struct JMFootstepComponent_eventGetAccumulatedDistance_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Footstep" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAccumulatedDistance constinit property declarations ****************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAccumulatedDistance constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAccumulatedDistance Property Definitions ***************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMFootstepComponent_GetAccumulatedDistance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMFootstepComponent_eventGetAccumulatedDistance_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMFootstepComponent_GetAccumulatedDistance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMFootstepComponent_GetAccumulatedDistance_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepComponent_GetAccumulatedDistance_Statics::PropPointers) < 2048);
// ********** End Function GetAccumulatedDistance Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMFootstepComponent_GetAccumulatedDistance_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMFootstepComponent, nullptr, "GetAccumulatedDistance", 	Z_Construct_UFunction_UJMFootstepComponent_GetAccumulatedDistance_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepComponent_GetAccumulatedDistance_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMFootstepComponent_GetAccumulatedDistance_Statics::JMFootstepComponent_eventGetAccumulatedDistance_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepComponent_GetAccumulatedDistance_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMFootstepComponent_GetAccumulatedDistance_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMFootstepComponent_GetAccumulatedDistance_Statics::JMFootstepComponent_eventGetAccumulatedDistance_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMFootstepComponent_GetAccumulatedDistance()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMFootstepComponent_GetAccumulatedDistance_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMFootstepComponent::execGetAccumulatedDistance)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetAccumulatedDistance();
	P_NATIVE_END;
}
// ********** End Class UJMFootstepComponent Function GetAccumulatedDistance ***********************

// ********** Begin Class UJMFootstepComponent Function GetCurrentLocomotionState ******************
struct Z_Construct_UFunction_UJMFootstepComponent_GetCurrentLocomotionState_Statics
{
	struct JMFootstepComponent_eventGetCurrentLocomotionState_Parms
	{
		EJMFootstepLocomotionState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Footstep" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentLocomotionState constinit property declarations *************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentLocomotionState constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentLocomotionState Property Definitions ************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMFootstepComponent_GetCurrentLocomotionState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMFootstepComponent_GetCurrentLocomotionState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMFootstepComponent_eventGetCurrentLocomotionState_Parms, ReturnValue), Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepLocomotionState, METADATA_PARAMS(0, nullptr) }; // 2109635988
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMFootstepComponent_GetCurrentLocomotionState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMFootstepComponent_GetCurrentLocomotionState_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMFootstepComponent_GetCurrentLocomotionState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepComponent_GetCurrentLocomotionState_Statics::PropPointers) < 2048);
// ********** End Function GetCurrentLocomotionState Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMFootstepComponent_GetCurrentLocomotionState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMFootstepComponent, nullptr, "GetCurrentLocomotionState", 	Z_Construct_UFunction_UJMFootstepComponent_GetCurrentLocomotionState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepComponent_GetCurrentLocomotionState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMFootstepComponent_GetCurrentLocomotionState_Statics::JMFootstepComponent_eventGetCurrentLocomotionState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepComponent_GetCurrentLocomotionState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMFootstepComponent_GetCurrentLocomotionState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMFootstepComponent_GetCurrentLocomotionState_Statics::JMFootstepComponent_eventGetCurrentLocomotionState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMFootstepComponent_GetCurrentLocomotionState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMFootstepComponent_GetCurrentLocomotionState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMFootstepComponent::execGetCurrentLocomotionState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EJMFootstepLocomotionState*)Z_Param__Result=P_THIS->GetCurrentLocomotionState();
	P_NATIVE_END;
}
// ********** End Class UJMFootstepComponent Function GetCurrentLocomotionState ********************

// ********** Begin Class UJMFootstepComponent Function HasLocomotionStateOverride *****************
struct Z_Construct_UFunction_UJMFootstepComponent_HasLocomotionStateOverride_Statics
{
	struct JMFootstepComponent_eventHasLocomotionStateOverride_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Footstep" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HasLocomotionStateOverride constinit property declarations ************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasLocomotionStateOverride constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasLocomotionStateOverride Property Definitions ***********************
void Z_Construct_UFunction_UJMFootstepComponent_HasLocomotionStateOverride_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMFootstepComponent_eventHasLocomotionStateOverride_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMFootstepComponent_HasLocomotionStateOverride_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMFootstepComponent_eventHasLocomotionStateOverride_Parms), &Z_Construct_UFunction_UJMFootstepComponent_HasLocomotionStateOverride_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMFootstepComponent_HasLocomotionStateOverride_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMFootstepComponent_HasLocomotionStateOverride_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepComponent_HasLocomotionStateOverride_Statics::PropPointers) < 2048);
// ********** End Function HasLocomotionStateOverride Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMFootstepComponent_HasLocomotionStateOverride_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMFootstepComponent, nullptr, "HasLocomotionStateOverride", 	Z_Construct_UFunction_UJMFootstepComponent_HasLocomotionStateOverride_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepComponent_HasLocomotionStateOverride_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMFootstepComponent_HasLocomotionStateOverride_Statics::JMFootstepComponent_eventHasLocomotionStateOverride_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepComponent_HasLocomotionStateOverride_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMFootstepComponent_HasLocomotionStateOverride_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMFootstepComponent_HasLocomotionStateOverride_Statics::JMFootstepComponent_eventHasLocomotionStateOverride_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMFootstepComponent_HasLocomotionStateOverride()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMFootstepComponent_HasLocomotionStateOverride_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMFootstepComponent::execHasLocomotionStateOverride)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->HasLocomotionStateOverride();
	P_NATIVE_END;
}
// ********** End Class UJMFootstepComponent Function HasLocomotionStateOverride *******************

// ********** Begin Class UJMFootstepComponent Function RequestFootstep ****************************
struct Z_Construct_UFunction_UJMFootstepComponent_RequestFootstep_Statics
{
	struct JMFootstepComponent_eventRequestFootstep_Parms
	{
		FJMFootstepContext Context;
		FJMFootstepResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Footstep" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestFootstep constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestFootstep constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestFootstep Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMFootstepComponent_RequestFootstep_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMFootstepComponent_eventRequestFootstep_Parms, Context), Z_Construct_UScriptStruct_FJMFootstepContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 163523017
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMFootstepComponent_RequestFootstep_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMFootstepComponent_eventRequestFootstep_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMFootstepResult, METADATA_PARAMS(0, nullptr) }; // 3779851243
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMFootstepComponent_RequestFootstep_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMFootstepComponent_RequestFootstep_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMFootstepComponent_RequestFootstep_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepComponent_RequestFootstep_Statics::PropPointers) < 2048);
// ********** End Function RequestFootstep Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMFootstepComponent_RequestFootstep_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMFootstepComponent, nullptr, "RequestFootstep", 	Z_Construct_UFunction_UJMFootstepComponent_RequestFootstep_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepComponent_RequestFootstep_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMFootstepComponent_RequestFootstep_Statics::JMFootstepComponent_eventRequestFootstep_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepComponent_RequestFootstep_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMFootstepComponent_RequestFootstep_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMFootstepComponent_RequestFootstep_Statics::JMFootstepComponent_eventRequestFootstep_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMFootstepComponent_RequestFootstep()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMFootstepComponent_RequestFootstep_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMFootstepComponent::execRequestFootstep)
{
	P_GET_STRUCT_REF(FJMFootstepContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMFootstepResult*)Z_Param__Result=P_THIS->RequestFootstep(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Class UJMFootstepComponent Function RequestFootstep ******************************

// ********** Begin Class UJMFootstepComponent Function ResetFootstepState *************************
struct Z_Construct_UFunction_UJMFootstepComponent_ResetFootstepState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Footstep" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResetFootstepState constinit property declarations ********************
// ********** End Function ResetFootstepState constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMFootstepComponent_ResetFootstepState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMFootstepComponent, nullptr, "ResetFootstepState", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepComponent_ResetFootstepState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMFootstepComponent_ResetFootstepState_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UJMFootstepComponent_ResetFootstepState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMFootstepComponent_ResetFootstepState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMFootstepComponent::execResetFootstepState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetFootstepState();
	P_NATIVE_END;
}
// ********** End Class UJMFootstepComponent Function ResetFootstepState ***************************

// ********** Begin Class UJMFootstepComponent Function SetLocomotionStateOverride *****************
struct Z_Construct_UFunction_UJMFootstepComponent_SetLocomotionStateOverride_Statics
{
	struct JMFootstepComponent_eventSetLocomotionStateOverride_Parms
	{
		EJMFootstepLocomotionState NewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Footstep" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetLocomotionStateOverride constinit property declarations ************
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetLocomotionStateOverride constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetLocomotionStateOverride Property Definitions ***********************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMFootstepComponent_SetLocomotionStateOverride_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMFootstepComponent_SetLocomotionStateOverride_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMFootstepComponent_eventSetLocomotionStateOverride_Parms, NewState), Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepLocomotionState, METADATA_PARAMS(0, nullptr) }; // 2109635988
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMFootstepComponent_SetLocomotionStateOverride_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMFootstepComponent_SetLocomotionStateOverride_Statics::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMFootstepComponent_SetLocomotionStateOverride_Statics::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepComponent_SetLocomotionStateOverride_Statics::PropPointers) < 2048);
// ********** End Function SetLocomotionStateOverride Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMFootstepComponent_SetLocomotionStateOverride_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMFootstepComponent, nullptr, "SetLocomotionStateOverride", 	Z_Construct_UFunction_UJMFootstepComponent_SetLocomotionStateOverride_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepComponent_SetLocomotionStateOverride_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMFootstepComponent_SetLocomotionStateOverride_Statics::JMFootstepComponent_eventSetLocomotionStateOverride_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepComponent_SetLocomotionStateOverride_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMFootstepComponent_SetLocomotionStateOverride_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMFootstepComponent_SetLocomotionStateOverride_Statics::JMFootstepComponent_eventSetLocomotionStateOverride_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMFootstepComponent_SetLocomotionStateOverride()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMFootstepComponent_SetLocomotionStateOverride_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMFootstepComponent::execSetLocomotionStateOverride)
{
	P_GET_ENUM(EJMFootstepLocomotionState,Z_Param_NewState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetLocomotionStateOverride(EJMFootstepLocomotionState(Z_Param_NewState));
	P_NATIVE_END;
}
// ********** End Class UJMFootstepComponent Function SetLocomotionStateOverride *******************

// ********** Begin Class UJMFootstepComponent Function TriggerFootstep ****************************
struct Z_Construct_UFunction_UJMFootstepComponent_TriggerFootstep_Statics
{
	struct JMFootstepComponent_eventTriggerFootstep_Parms
	{
		FJMFootstepResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Footstep" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function TriggerFootstep constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TriggerFootstep constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TriggerFootstep Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMFootstepComponent_TriggerFootstep_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMFootstepComponent_eventTriggerFootstep_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMFootstepResult, METADATA_PARAMS(0, nullptr) }; // 3779851243
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMFootstepComponent_TriggerFootstep_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMFootstepComponent_TriggerFootstep_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepComponent_TriggerFootstep_Statics::PropPointers) < 2048);
// ********** End Function TriggerFootstep Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMFootstepComponent_TriggerFootstep_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMFootstepComponent, nullptr, "TriggerFootstep", 	Z_Construct_UFunction_UJMFootstepComponent_TriggerFootstep_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepComponent_TriggerFootstep_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMFootstepComponent_TriggerFootstep_Statics::JMFootstepComponent_eventTriggerFootstep_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepComponent_TriggerFootstep_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMFootstepComponent_TriggerFootstep_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMFootstepComponent_TriggerFootstep_Statics::JMFootstepComponent_eventTriggerFootstep_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMFootstepComponent_TriggerFootstep()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMFootstepComponent_TriggerFootstep_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMFootstepComponent::execTriggerFootstep)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMFootstepResult*)Z_Param__Result=P_THIS->TriggerFootstep();
	P_NATIVE_END;
}
// ********** End Class UJMFootstepComponent Function TriggerFootstep ******************************

// ********** Begin Class UJMFootstepComponent *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMFootstepComponent;
UClass* UJMFootstepComponent::GetPrivateStaticClass()
{
	using TClass = UJMFootstepComponent;
	if (!Z_Registration_Info_UClass_UJMFootstepComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMFootstepComponent"),
			Z_Registration_Info_UClass_UJMFootstepComponent.InnerSingleton,
			StaticRegisterNativesUJMFootstepComponent,
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
	return Z_Registration_Info_UClass_UJMFootstepComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMFootstepComponent_NoRegister()
{
	return UJMFootstepComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMFootstepComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JM" },
		{ "IncludePath", "Components/JMFootstepComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnFootstepPlayed_MetaData[] = {
		{ "Category", "JM Footstep" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FootstepSetOverride_MetaData[] = {
		{ "Category", "Footstep|Data" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideTriggerMode_MetaData[] = {
		{ "Category", "Footstep|Trigger" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TriggerModeOverride_MetaData[] = {
		{ "Category", "Footstep|Trigger" },
		{ "EditCondition", "bOverrideTriggerMode" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideMovementSettings_MetaData[] = {
		{ "Category", "Footstep|Overrides" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumMovementSpeedOverride_MetaData[] = {
		{ "Category", "Footstep|Overrides" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bOverrideMovementSettings" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
		{ "Units", "cm/s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RunSpeedThresholdOverride_MetaData[] = {
		{ "Category", "Footstep|Overrides" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bOverrideMovementSettings" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
		{ "Units", "cm/s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalkStepDistanceOverride_MetaData[] = {
		{ "Category", "Footstep|Overrides" },
		{ "ClampMin", "1.0" },
		{ "EditCondition", "bOverrideMovementSettings" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RunStepDistanceOverride_MetaData[] = {
		{ "Category", "Footstep|Overrides" },
		{ "ClampMin", "1.0" },
		{ "EditCondition", "bOverrideMovementSettings" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CrouchStepDistanceOverride_MetaData[] = {
		{ "Category", "Footstep|Overrides" },
		{ "ClampMin", "1.0" },
		{ "EditCondition", "bOverrideMovementSettings" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TeleportDistanceThresholdOverride_MetaData[] = {
		{ "Category", "Footstep|Overrides" },
		{ "ClampMin", "1.0" },
		{ "EditCondition", "bOverrideMovementSettings" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxStepsPerFrameOverride_MetaData[] = {
		{ "Category", "Footstep|Overrides" },
		{ "ClampMax", "8" },
		{ "ClampMin", "1" },
		{ "EditCondition", "bOverrideMovementSettings" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideTraceSettings_MetaData[] = {
		{ "Category", "Footstep|Overrides" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TraceDistanceOverride_MetaData[] = {
		{ "Category", "Footstep|Overrides" },
		{ "ClampMin", "1.0" },
		{ "EditCondition", "bOverrideTraceSettings" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TraceStartOffsetOverride_MetaData[] = {
		{ "Category", "Footstep|Overrides" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bOverrideTraceSettings" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TraceChannelOverride_MetaData[] = {
		{ "Category", "Footstep|Overrides" },
		{ "EditCondition", "bOverrideTraceSettings" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideAudioMultipliers_MetaData[] = {
		{ "Category", "Footstep|Overrides" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VolumeMultiplierOverride_MetaData[] = {
		{ "Category", "Footstep|Overrides" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bOverrideAudioMultipliers" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PitchMultiplierOverride_MetaData[] = {
		{ "Category", "Footstep|Overrides" },
		{ "ClampMin", "0.01" },
		{ "EditCondition", "bOverrideAudioMultipliers" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideDebug_MetaData[] = {
		{ "Category", "Footstep|Debug" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDebugOverride_MetaData[] = {
		{ "Category", "Footstep|Debug" },
		{ "EditCondition", "bOverrideDebug" },
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SoundHistoryByProfile_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/JMFootstepComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMFootstepComponent constinit property declarations *********************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnFootstepPlayed;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FootstepSetOverride;
	static void NewProp_bOverrideTriggerMode_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideTriggerMode;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TriggerModeOverride_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TriggerModeOverride;
	static void NewProp_bOverrideMovementSettings_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideMovementSettings;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinimumMovementSpeedOverride;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RunSpeedThresholdOverride;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WalkStepDistanceOverride;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RunStepDistanceOverride;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CrouchStepDistanceOverride;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TeleportDistanceThresholdOverride;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxStepsPerFrameOverride;
	static void NewProp_bOverrideTraceSettings_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideTraceSettings;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TraceDistanceOverride;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TraceStartOffsetOverride;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TraceChannelOverride;
	static void NewProp_bOverrideAudioMultipliers_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideAudioMultipliers;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VolumeMultiplierOverride;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PitchMultiplierOverride;
	static void NewProp_bOverrideDebug_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideDebug;
	static void NewProp_bEnableDebugOverride_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDebugOverride;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SoundHistoryByProfile_ValueProp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SoundHistoryByProfile_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_SoundHistoryByProfile;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMFootstepComponent constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ClearLocomotionStateOverride"), .Pointer = &UJMFootstepComponent::execClearLocomotionStateOverride },
		{ .NameUTF8 = UTF8TEXT("GetAccumulatedDistance"), .Pointer = &UJMFootstepComponent::execGetAccumulatedDistance },
		{ .NameUTF8 = UTF8TEXT("GetCurrentLocomotionState"), .Pointer = &UJMFootstepComponent::execGetCurrentLocomotionState },
		{ .NameUTF8 = UTF8TEXT("HasLocomotionStateOverride"), .Pointer = &UJMFootstepComponent::execHasLocomotionStateOverride },
		{ .NameUTF8 = UTF8TEXT("RequestFootstep"), .Pointer = &UJMFootstepComponent::execRequestFootstep },
		{ .NameUTF8 = UTF8TEXT("ResetFootstepState"), .Pointer = &UJMFootstepComponent::execResetFootstepState },
		{ .NameUTF8 = UTF8TEXT("SetLocomotionStateOverride"), .Pointer = &UJMFootstepComponent::execSetLocomotionStateOverride },
		{ .NameUTF8 = UTF8TEXT("TriggerFootstep"), .Pointer = &UJMFootstepComponent::execTriggerFootstep },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMFootstepComponent_ClearLocomotionStateOverride, "ClearLocomotionStateOverride" }, // 2556457993
		{ &Z_Construct_UFunction_UJMFootstepComponent_GetAccumulatedDistance, "GetAccumulatedDistance" }, // 1685228724
		{ &Z_Construct_UFunction_UJMFootstepComponent_GetCurrentLocomotionState, "GetCurrentLocomotionState" }, // 3656057040
		{ &Z_Construct_UFunction_UJMFootstepComponent_HasLocomotionStateOverride, "HasLocomotionStateOverride" }, // 1952620187
		{ &Z_Construct_UFunction_UJMFootstepComponent_RequestFootstep, "RequestFootstep" }, // 1467471027
		{ &Z_Construct_UFunction_UJMFootstepComponent_ResetFootstepState, "ResetFootstepState" }, // 3810265499
		{ &Z_Construct_UFunction_UJMFootstepComponent_SetLocomotionStateOverride, "SetLocomotionStateOverride" }, // 650859249
		{ &Z_Construct_UFunction_UJMFootstepComponent_TriggerFootstep, "TriggerFootstep" }, // 2792497958
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMFootstepComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMFootstepComponent_Statics

// ********** Begin Class UJMFootstepComponent Property Definitions ********************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_OnFootstepPlayed = { "OnFootstepPlayed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepComponent, OnFootstepPlayed), Z_Construct_UDelegateFunction_JMFootstepRuntime_JMFootstepPlayedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnFootstepPlayed_MetaData), NewProp_OnFootstepPlayed_MetaData) }; // 3682267987
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_FootstepSetOverride = { "FootstepSetOverride", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepComponent, FootstepSetOverride), Z_Construct_UClass_UJMFootstepSet_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FootstepSetOverride_MetaData), NewProp_FootstepSetOverride_MetaData) };
void Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bOverrideTriggerMode_SetBit(void* Obj)
{
	((UJMFootstepComponent*)Obj)->bOverrideTriggerMode = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bOverrideTriggerMode = { "bOverrideTriggerMode", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMFootstepComponent), &Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bOverrideTriggerMode_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideTriggerMode_MetaData), NewProp_bOverrideTriggerMode_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_TriggerModeOverride_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_TriggerModeOverride = { "TriggerModeOverride", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepComponent, TriggerModeOverride), Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepTriggerMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TriggerModeOverride_MetaData), NewProp_TriggerModeOverride_MetaData) }; // 236246170
void Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bOverrideMovementSettings_SetBit(void* Obj)
{
	((UJMFootstepComponent*)Obj)->bOverrideMovementSettings = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bOverrideMovementSettings = { "bOverrideMovementSettings", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMFootstepComponent), &Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bOverrideMovementSettings_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideMovementSettings_MetaData), NewProp_bOverrideMovementSettings_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_MinimumMovementSpeedOverride = { "MinimumMovementSpeedOverride", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepComponent, MinimumMovementSpeedOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumMovementSpeedOverride_MetaData), NewProp_MinimumMovementSpeedOverride_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_RunSpeedThresholdOverride = { "RunSpeedThresholdOverride", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepComponent, RunSpeedThresholdOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RunSpeedThresholdOverride_MetaData), NewProp_RunSpeedThresholdOverride_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_WalkStepDistanceOverride = { "WalkStepDistanceOverride", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepComponent, WalkStepDistanceOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalkStepDistanceOverride_MetaData), NewProp_WalkStepDistanceOverride_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_RunStepDistanceOverride = { "RunStepDistanceOverride", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepComponent, RunStepDistanceOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RunStepDistanceOverride_MetaData), NewProp_RunStepDistanceOverride_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_CrouchStepDistanceOverride = { "CrouchStepDistanceOverride", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepComponent, CrouchStepDistanceOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CrouchStepDistanceOverride_MetaData), NewProp_CrouchStepDistanceOverride_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_TeleportDistanceThresholdOverride = { "TeleportDistanceThresholdOverride", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepComponent, TeleportDistanceThresholdOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TeleportDistanceThresholdOverride_MetaData), NewProp_TeleportDistanceThresholdOverride_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_MaxStepsPerFrameOverride = { "MaxStepsPerFrameOverride", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepComponent, MaxStepsPerFrameOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxStepsPerFrameOverride_MetaData), NewProp_MaxStepsPerFrameOverride_MetaData) };
void Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bOverrideTraceSettings_SetBit(void* Obj)
{
	((UJMFootstepComponent*)Obj)->bOverrideTraceSettings = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bOverrideTraceSettings = { "bOverrideTraceSettings", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMFootstepComponent), &Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bOverrideTraceSettings_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideTraceSettings_MetaData), NewProp_bOverrideTraceSettings_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_TraceDistanceOverride = { "TraceDistanceOverride", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepComponent, TraceDistanceOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TraceDistanceOverride_MetaData), NewProp_TraceDistanceOverride_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_TraceStartOffsetOverride = { "TraceStartOffsetOverride", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepComponent, TraceStartOffsetOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TraceStartOffsetOverride_MetaData), NewProp_TraceStartOffsetOverride_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_TraceChannelOverride = { "TraceChannelOverride", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepComponent, TraceChannelOverride), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TraceChannelOverride_MetaData), NewProp_TraceChannelOverride_MetaData) }; // 838391399
void Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bOverrideAudioMultipliers_SetBit(void* Obj)
{
	((UJMFootstepComponent*)Obj)->bOverrideAudioMultipliers = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bOverrideAudioMultipliers = { "bOverrideAudioMultipliers", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMFootstepComponent), &Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bOverrideAudioMultipliers_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideAudioMultipliers_MetaData), NewProp_bOverrideAudioMultipliers_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_VolumeMultiplierOverride = { "VolumeMultiplierOverride", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepComponent, VolumeMultiplierOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VolumeMultiplierOverride_MetaData), NewProp_VolumeMultiplierOverride_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_PitchMultiplierOverride = { "PitchMultiplierOverride", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepComponent, PitchMultiplierOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PitchMultiplierOverride_MetaData), NewProp_PitchMultiplierOverride_MetaData) };
void Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bOverrideDebug_SetBit(void* Obj)
{
	((UJMFootstepComponent*)Obj)->bOverrideDebug = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bOverrideDebug = { "bOverrideDebug", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMFootstepComponent), &Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bOverrideDebug_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideDebug_MetaData), NewProp_bOverrideDebug_MetaData) };
void Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bEnableDebugOverride_SetBit(void* Obj)
{
	((UJMFootstepComponent*)Obj)->bEnableDebugOverride = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bEnableDebugOverride = { "bEnableDebugOverride", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMFootstepComponent), &Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bEnableDebugOverride_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDebugOverride_MetaData), NewProp_bEnableDebugOverride_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_SoundHistoryByProfile_ValueProp = { "SoundHistoryByProfile", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory, METADATA_PARAMS(0, nullptr) }; // 4005717197
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_SoundHistoryByProfile_Key_KeyProp = { "SoundHistoryByProfile_Key", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UJMFootstepSurfaceProfile_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_SoundHistoryByProfile = { "SoundHistoryByProfile", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepComponent, SoundHistoryByProfile), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SoundHistoryByProfile_MetaData), NewProp_SoundHistoryByProfile_MetaData) }; // 4005717197
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMFootstepComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_OnFootstepPlayed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_FootstepSetOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bOverrideTriggerMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_TriggerModeOverride_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_TriggerModeOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bOverrideMovementSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_MinimumMovementSpeedOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_RunSpeedThresholdOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_WalkStepDistanceOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_RunStepDistanceOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_CrouchStepDistanceOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_TeleportDistanceThresholdOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_MaxStepsPerFrameOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bOverrideTraceSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_TraceDistanceOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_TraceStartOffsetOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_TraceChannelOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bOverrideAudioMultipliers,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_VolumeMultiplierOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_PitchMultiplierOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bOverrideDebug,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_bEnableDebugOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_SoundHistoryByProfile_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_SoundHistoryByProfile_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepComponent_Statics::NewProp_SoundHistoryByProfile,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMFootstepComponent_Statics::PropPointers) < 2048);
// ********** End Class UJMFootstepComponent Property Definitions **********************************
UObject* (*const Z_Construct_UClass_UJMFootstepComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMFootstepRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMFootstepComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMFootstepComponent_Statics::ClassParams = {
	&UJMFootstepComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMFootstepComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMFootstepComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMFootstepComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMFootstepComponent_Statics::Class_MetaDataParams)
};
void UJMFootstepComponent::StaticRegisterNativesUJMFootstepComponent()
{
	UClass* Class = UJMFootstepComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMFootstepComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMFootstepComponent()
{
	if (!Z_Registration_Info_UClass_UJMFootstepComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMFootstepComponent.OuterSingleton, Z_Construct_UClass_UJMFootstepComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMFootstepComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMFootstepComponent);
UJMFootstepComponent::~UJMFootstepComponent() {}
// ********** End Class UJMFootstepComponent *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Components_JMFootstepComponent_h__Script_JMFootstepRuntime_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FJMFootstepVariantSoundHistory::StaticStruct, Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory_Statics::NewStructOps, TEXT("JMFootstepVariantSoundHistory"),&Z_Registration_Info_UScriptStruct_FJMFootstepVariantSoundHistory, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMFootstepVariantSoundHistory), 4005717197U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMFootstepComponent, UJMFootstepComponent::StaticClass, TEXT("UJMFootstepComponent"), &Z_Registration_Info_UClass_UJMFootstepComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMFootstepComponent), 2507485252U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Components_JMFootstepComponent_h__Script_JMFootstepRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Components_JMFootstepComponent_h__Script_JMFootstepRuntime_4204150821{
	TEXT("/Script/JMFootstepRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Components_JMFootstepComponent_h__Script_JMFootstepRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Components_JMFootstepComponent_h__Script_JMFootstepRuntime_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Components_JMFootstepComponent_h__Script_JMFootstepRuntime_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Components_JMFootstepComponent_h__Script_JMFootstepRuntime_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
