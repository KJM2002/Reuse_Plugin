// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Data/JMFootstepSurfaceProfile.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMFootstepSurfaceProfile() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
ENGINE_API UClass* Z_Construct_UClass_USoundAttenuation_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
JMFOOTSTEPRUNTIME_API UClass* Z_Construct_UClass_UJMFootstepSurfaceProfile();
JMFOOTSTEPRUNTIME_API UClass* Z_Construct_UClass_UJMFootstepSurfaceProfile_NoRegister();
JMFOOTSTEPRUNTIME_API UEnum* Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepLocomotionState();
JMFOOTSTEPRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMFootstepSoundVariant();
UPackage* Z_Construct_UPackage__Script_JMFootstepRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FJMFootstepSoundVariant *******************************************
struct Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMFootstepSoundVariant); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMFootstepSoundVariant); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Data/JMFootstepSurfaceProfile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Sounds_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ModuleRelativePath", "Public/Data/JMFootstepSurfaceProfile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sounds randomly selected for this locomotion state. Null entries are ignored." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VolumeMin_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMFootstepSurfaceProfile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Minimum natural volume variation before state and request multipliers." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VolumeMax_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMFootstepSurfaceProfile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum natural volume variation before state and request multipliers." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PitchMin_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Data/JMFootstepSurfaceProfile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Minimum natural pitch variation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PitchMax_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Data/JMFootstepSurfaceProfile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum natural pitch variation." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMFootstepSoundVariant constinit property declarations ***********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Sounds_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Sounds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VolumeMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VolumeMax;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PitchMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PitchMax;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMFootstepSoundVariant constinit property declarations *************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMFootstepSoundVariant>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMFootstepSoundVariant;
class UScriptStruct* FJMFootstepSoundVariant::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMFootstepSoundVariant.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMFootstepSoundVariant.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMFootstepSoundVariant, (UObject*)Z_Construct_UPackage__Script_JMFootstepRuntime(), TEXT("JMFootstepSoundVariant"));
	}
	return Z_Registration_Info_UScriptStruct_FJMFootstepSoundVariant.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMFootstepSoundVariant Property Definitions **********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics::NewProp_Sounds_Inner = { "Sounds", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics::NewProp_Sounds = { "Sounds", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepSoundVariant, Sounds), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Sounds_MetaData), NewProp_Sounds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics::NewProp_VolumeMin = { "VolumeMin", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepSoundVariant, VolumeMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VolumeMin_MetaData), NewProp_VolumeMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics::NewProp_VolumeMax = { "VolumeMax", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepSoundVariant, VolumeMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VolumeMax_MetaData), NewProp_VolumeMax_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics::NewProp_PitchMin = { "PitchMin", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepSoundVariant, PitchMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PitchMin_MetaData), NewProp_PitchMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics::NewProp_PitchMax = { "PitchMax", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepSoundVariant, PitchMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PitchMax_MetaData), NewProp_PitchMax_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics::NewProp_Sounds_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics::NewProp_Sounds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics::NewProp_VolumeMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics::NewProp_VolumeMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics::NewProp_PitchMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics::NewProp_PitchMax,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMFootstepSoundVariant Property Definitions ************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMFootstepRuntime,
	nullptr,
	&NewStructOps,
	"JMFootstepSoundVariant",
	Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics::PropPointers),
	sizeof(FJMFootstepSoundVariant),
	alignof(FJMFootstepSoundVariant),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMFootstepSoundVariant()
{
	if (!Z_Registration_Info_UScriptStruct_FJMFootstepSoundVariant.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMFootstepSoundVariant.InnerSingleton, Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMFootstepSoundVariant.InnerSingleton);
}
// ********** End ScriptStruct FJMFootstepSoundVariant *********************************************

// ********** Begin Class UJMFootstepSurfaceProfile Function ResolveVariant ************************
struct Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics
{
	struct JMFootstepSurfaceProfile_eventResolveVariant_Parms
	{
		EJMFootstepLocomotionState RequestedState;
		FJMFootstepSoundVariant OutVariant;
		EJMFootstepLocomotionState OutSelectedVariantState;
		bool bOutUsedFallback;
		bool bOutUsedLegacyVariant;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Footstep" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Resolves a copy of the data used for the requested gait.\n     * Run/CrouchWalk may fall back to Walk; every gait may fall back to v1.0 fields.\n     * Idle is invalid and returns false.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Data/JMFootstepSurfaceProfile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Resolves a copy of the data used for the requested gait.\nRun/CrouchWalk may fall back to Walk; every gait may fall back to v1.0 fields.\nIdle is invalid and returns false." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ResolveVariant constinit property declarations ************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_RequestedState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_RequestedState;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutVariant;
	static const UECodeGen_Private::FBytePropertyParams NewProp_OutSelectedVariantState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OutSelectedVariantState;
	static void NewProp_bOutUsedFallback_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOutUsedFallback;
	static void NewProp_bOutUsedLegacyVariant_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOutUsedLegacyVariant;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ResolveVariant constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ResolveVariant Property Definitions ***********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::NewProp_RequestedState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::NewProp_RequestedState = { "RequestedState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMFootstepSurfaceProfile_eventResolveVariant_Parms, RequestedState), Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepLocomotionState, METADATA_PARAMS(0, nullptr) }; // 2109635988
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::NewProp_OutVariant = { "OutVariant", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMFootstepSurfaceProfile_eventResolveVariant_Parms, OutVariant), Z_Construct_UScriptStruct_FJMFootstepSoundVariant, METADATA_PARAMS(0, nullptr) }; // 3471552529
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::NewProp_OutSelectedVariantState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::NewProp_OutSelectedVariantState = { "OutSelectedVariantState", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMFootstepSurfaceProfile_eventResolveVariant_Parms, OutSelectedVariantState), Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepLocomotionState, METADATA_PARAMS(0, nullptr) }; // 2109635988
void Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::NewProp_bOutUsedFallback_SetBit(void* Obj)
{
	((JMFootstepSurfaceProfile_eventResolveVariant_Parms*)Obj)->bOutUsedFallback = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::NewProp_bOutUsedFallback = { "bOutUsedFallback", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMFootstepSurfaceProfile_eventResolveVariant_Parms), &Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::NewProp_bOutUsedFallback_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::NewProp_bOutUsedLegacyVariant_SetBit(void* Obj)
{
	((JMFootstepSurfaceProfile_eventResolveVariant_Parms*)Obj)->bOutUsedLegacyVariant = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::NewProp_bOutUsedLegacyVariant = { "bOutUsedLegacyVariant", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMFootstepSurfaceProfile_eventResolveVariant_Parms), &Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::NewProp_bOutUsedLegacyVariant_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMFootstepSurfaceProfile_eventResolveVariant_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMFootstepSurfaceProfile_eventResolveVariant_Parms), &Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::NewProp_RequestedState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::NewProp_RequestedState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::NewProp_OutVariant,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::NewProp_OutSelectedVariantState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::NewProp_OutSelectedVariantState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::NewProp_bOutUsedFallback,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::NewProp_bOutUsedLegacyVariant,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::PropPointers) < 2048);
// ********** End Function ResolveVariant Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMFootstepSurfaceProfile, nullptr, "ResolveVariant", 	Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::JMFootstepSurfaceProfile_eventResolveVariant_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::JMFootstepSurfaceProfile_eventResolveVariant_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMFootstepSurfaceProfile::execResolveVariant)
{
	P_GET_ENUM(EJMFootstepLocomotionState,Z_Param_RequestedState);
	P_GET_STRUCT_REF(FJMFootstepSoundVariant,Z_Param_Out_OutVariant);
	P_GET_ENUM_REF(EJMFootstepLocomotionState,Z_Param_Out_OutSelectedVariantState);
	P_GET_UBOOL_REF(Z_Param_Out_bOutUsedFallback);
	P_GET_UBOOL_REF(Z_Param_Out_bOutUsedLegacyVariant);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ResolveVariant(EJMFootstepLocomotionState(Z_Param_RequestedState),Z_Param_Out_OutVariant,(EJMFootstepLocomotionState&)(Z_Param_Out_OutSelectedVariantState),Z_Param_Out_bOutUsedFallback,Z_Param_Out_bOutUsedLegacyVariant);
	P_NATIVE_END;
}
// ********** End Class UJMFootstepSurfaceProfile Function ResolveVariant **************************

// ********** Begin Class UJMFootstepSurfaceProfile ************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMFootstepSurfaceProfile;
UClass* UJMFootstepSurfaceProfile::GetPrivateStaticClass()
{
	using TClass = UJMFootstepSurfaceProfile;
	if (!Z_Registration_Info_UClass_UJMFootstepSurfaceProfile.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMFootstepSurfaceProfile"),
			Z_Registration_Info_UClass_UJMFootstepSurfaceProfile.InnerSingleton,
			StaticRegisterNativesUJMFootstepSurfaceProfile,
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
	return Z_Registration_Info_UClass_UJMFootstepSurfaceProfile.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMFootstepSurfaceProfile_NoRegister()
{
	return UJMFootstepSurfaceProfile::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Data/JMFootstepSurfaceProfile.h" },
		{ "ModuleRelativePath", "Public/Data/JMFootstepSurfaceProfile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalkVariant_MetaData[] = {
		{ "Category", "Footstep|Walk" },
		{ "DisplayName", "Walk Variant" },
		{ "ModuleRelativePath", "Public/Data/JMFootstepSurfaceProfile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RunVariant_MetaData[] = {
		{ "Category", "Footstep|Run" },
		{ "DisplayName", "Run Variant" },
		{ "ModuleRelativePath", "Public/Data/JMFootstepSurfaceProfile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CrouchWalkVariant_MetaData[] = {
		{ "Category", "Footstep|Crouch Walk" },
		{ "DisplayName", "Crouch Walk Variant" },
		{ "ModuleRelativePath", "Public/Data/JMFootstepSurfaceProfile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Sounds_MetaData[] = {
		{ "Category", "Footstep|Legacy Compatibility" },
		{ "DisplayName", "Legacy Sounds (v1.0 Fallback)" },
		{ "ModuleRelativePath", "Public/Data/JMFootstepSurfaceProfile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Used only when the requested locomotion variant and its Walk fallback contain no valid sounds." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VolumeMin_MetaData[] = {
		{ "Category", "Footstep|Legacy Compatibility" },
		{ "ClampMin", "0.0" },
		{ "DisplayName", "Legacy Volume Min" },
		{ "ModuleRelativePath", "Public/Data/JMFootstepSurfaceProfile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VolumeMax_MetaData[] = {
		{ "Category", "Footstep|Legacy Compatibility" },
		{ "ClampMin", "0.0" },
		{ "DisplayName", "Legacy Volume Max" },
		{ "ModuleRelativePath", "Public/Data/JMFootstepSurfaceProfile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PitchMin_MetaData[] = {
		{ "Category", "Footstep|Legacy Compatibility" },
		{ "ClampMin", "0.01" },
		{ "DisplayName", "Legacy Pitch Min" },
		{ "ModuleRelativePath", "Public/Data/JMFootstepSurfaceProfile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PitchMax_MetaData[] = {
		{ "Category", "Footstep|Legacy Compatibility" },
		{ "ClampMin", "0.01" },
		{ "DisplayName", "Legacy Pitch Max" },
		{ "ModuleRelativePath", "Public/Data/JMFootstepSurfaceProfile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttenuationSettings_MetaData[] = {
		{ "Category", "Footstep|Spatial Audio" },
		{ "ModuleRelativePath", "Public/Data/JMFootstepSurfaceProfile.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMFootstepSurfaceProfile constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_WalkVariant;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RunVariant;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CrouchWalkVariant;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Sounds_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Sounds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VolumeMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VolumeMax;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PitchMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PitchMax;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttenuationSettings;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMFootstepSurfaceProfile constinit property declarations ******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ResolveVariant"), .Pointer = &UJMFootstepSurfaceProfile::execResolveVariant },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMFootstepSurfaceProfile_ResolveVariant, "ResolveVariant" }, // 3855999950
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMFootstepSurfaceProfile>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics

// ********** Begin Class UJMFootstepSurfaceProfile Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::NewProp_WalkVariant = { "WalkVariant", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSurfaceProfile, WalkVariant), Z_Construct_UScriptStruct_FJMFootstepSoundVariant, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalkVariant_MetaData), NewProp_WalkVariant_MetaData) }; // 3471552529
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::NewProp_RunVariant = { "RunVariant", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSurfaceProfile, RunVariant), Z_Construct_UScriptStruct_FJMFootstepSoundVariant, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RunVariant_MetaData), NewProp_RunVariant_MetaData) }; // 3471552529
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::NewProp_CrouchWalkVariant = { "CrouchWalkVariant", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSurfaceProfile, CrouchWalkVariant), Z_Construct_UScriptStruct_FJMFootstepSoundVariant, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CrouchWalkVariant_MetaData), NewProp_CrouchWalkVariant_MetaData) }; // 3471552529
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::NewProp_Sounds_Inner = { "Sounds", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::NewProp_Sounds = { "Sounds", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSurfaceProfile, Sounds), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Sounds_MetaData), NewProp_Sounds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::NewProp_VolumeMin = { "VolumeMin", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSurfaceProfile, VolumeMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VolumeMin_MetaData), NewProp_VolumeMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::NewProp_VolumeMax = { "VolumeMax", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSurfaceProfile, VolumeMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VolumeMax_MetaData), NewProp_VolumeMax_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::NewProp_PitchMin = { "PitchMin", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSurfaceProfile, PitchMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PitchMin_MetaData), NewProp_PitchMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::NewProp_PitchMax = { "PitchMax", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSurfaceProfile, PitchMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PitchMax_MetaData), NewProp_PitchMax_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::NewProp_AttenuationSettings = { "AttenuationSettings", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSurfaceProfile, AttenuationSettings), Z_Construct_UClass_USoundAttenuation_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttenuationSettings_MetaData), NewProp_AttenuationSettings_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::NewProp_WalkVariant,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::NewProp_RunVariant,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::NewProp_CrouchWalkVariant,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::NewProp_Sounds_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::NewProp_Sounds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::NewProp_VolumeMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::NewProp_VolumeMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::NewProp_PitchMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::NewProp_PitchMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::NewProp_AttenuationSettings,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::PropPointers) < 2048);
// ********** End Class UJMFootstepSurfaceProfile Property Definitions *****************************
UObject* (*const Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_JMFootstepRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::ClassParams = {
	&UJMFootstepSurfaceProfile::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::Class_MetaDataParams)
};
void UJMFootstepSurfaceProfile::StaticRegisterNativesUJMFootstepSurfaceProfile()
{
	UClass* Class = UJMFootstepSurfaceProfile::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMFootstepSurfaceProfile()
{
	if (!Z_Registration_Info_UClass_UJMFootstepSurfaceProfile.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMFootstepSurfaceProfile.OuterSingleton, Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMFootstepSurfaceProfile.OuterSingleton;
}
UJMFootstepSurfaceProfile::UJMFootstepSurfaceProfile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMFootstepSurfaceProfile);
UJMFootstepSurfaceProfile::~UJMFootstepSurfaceProfile() {}
// ********** End Class UJMFootstepSurfaceProfile **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSurfaceProfile_h__Script_JMFootstepRuntime_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FJMFootstepSoundVariant::StaticStruct, Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics::NewStructOps, TEXT("JMFootstepSoundVariant"),&Z_Registration_Info_UScriptStruct_FJMFootstepSoundVariant, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMFootstepSoundVariant), 3471552529U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMFootstepSurfaceProfile, UJMFootstepSurfaceProfile::StaticClass, TEXT("UJMFootstepSurfaceProfile"), &Z_Registration_Info_UClass_UJMFootstepSurfaceProfile, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMFootstepSurfaceProfile), 2111484112U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSurfaceProfile_h__Script_JMFootstepRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSurfaceProfile_h__Script_JMFootstepRuntime_1339740576{
	TEXT("/Script/JMFootstepRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSurfaceProfile_h__Script_JMFootstepRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSurfaceProfile_h__Script_JMFootstepRuntime_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSurfaceProfile_h__Script_JMFootstepRuntime_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSurfaceProfile_h__Script_JMFootstepRuntime_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
