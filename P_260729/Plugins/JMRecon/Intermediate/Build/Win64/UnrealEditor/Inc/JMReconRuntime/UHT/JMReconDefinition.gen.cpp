// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Data/JMReconDefinition.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMReconDefinition() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
ENGINE_API UClass* Z_Construct_UClass_USoundMix_NoRegister();
JMRECONRUNTIME_API UClass* Z_Construct_UClass_UJMReconDefinition();
JMRECONRUNTIME_API UClass* Z_Construct_UClass_UJMReconDefinition_NoRegister();
JMRECONRUNTIME_API UEnum* Z_Construct_UEnum_JMReconRuntime_EJMReconInitialObservationMode();
UPackage* Z_Construct_UPackage__Script_JMReconRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMReconDefinition *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMReconDefinition;
UClass* UJMReconDefinition::GetPrivateStaticClass()
{
	using TClass = UJMReconDefinition;
	if (!Z_Registration_Info_UClass_UJMReconDefinition.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMReconDefinition"),
			Z_Registration_Info_UClass_UJMReconDefinition.InnerSingleton,
			StaticRegisterNativesUJMReconDefinition,
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
	return Z_Registration_Info_UClass_UJMReconDefinition.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMReconDefinition_NoRegister()
{
	return UJMReconDefinition::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMReconDefinition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Data/JMReconDefinition.h" },
		{ "ModuleRelativePath", "Public/Data/JMReconDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InitialObservationMode_MetaData[] = {
		{ "Category", "General" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Listen preserves legacy behavior. Projects can select Peek for one-action observation. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/JMReconDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Listen preserves legacy behavior. Projects can select Peek for one-action observation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnteringDuration_MetaData[] = {
		{ "Category", "General" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMReconDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExitingDuration_MetaData[] = {
		{ "Category", "General" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMReconDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowListen_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/Data/JMReconDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowPeek_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/Data/JMReconDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowIlluminate_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/Data/JMReconDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumListenTime_MetaData[] = {
		{ "Category", "Listen" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMReconDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ListenAudioMix_MetaData[] = {
		{ "Category", "Listen" },
		{ "ModuleRelativePath", "Public/Data/JMReconDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ListenFadeDuration_MetaData[] = {
		{ "Category", "Listen" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMReconDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PeekOpenFraction_MetaData[] = {
		{ "Category", "Peek" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMReconDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraYawLimit_MetaData[] = {
		{ "Category", "Peek" },
		{ "ClampMax", "180.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMReconDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraPitchLimit_MetaData[] = {
		{ "Category", "Peek" },
		{ "ClampMax", "89.9" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMReconDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PeekBlendTime_MetaData[] = {
		{ "Category", "Peek" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMReconDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ListenNoise_MetaData[] = {
		{ "Category", "Risk" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMReconDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PeekNoise_MetaData[] = {
		{ "Category", "Risk" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMReconDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IlluminateEvent_MetaData[] = {
		{ "Category", "Risk" },
		{ "ModuleRelativePath", "Public/Data/JMReconDefinition.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMReconDefinition constinit property declarations ***********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InitialObservationMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InitialObservationMode;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EnteringDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ExitingDuration;
	static void NewProp_bAllowListen_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowListen;
	static void NewProp_bAllowPeek_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowPeek;
	static void NewProp_bAllowIlluminate_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowIlluminate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinimumListenTime;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_ListenAudioMix;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ListenFadeDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PeekOpenFraction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraYawLimit;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraPitchLimit;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PeekBlendTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ListenNoise;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PeekNoise;
	static const UECodeGen_Private::FNamePropertyParams NewProp_IlluminateEvent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMReconDefinition constinit property declarations *************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMReconDefinition>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMReconDefinition_Statics

// ********** Begin Class UJMReconDefinition Property Definitions **********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_InitialObservationMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_InitialObservationMode = { "InitialObservationMode", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconDefinition, InitialObservationMode), Z_Construct_UEnum_JMReconRuntime_EJMReconInitialObservationMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InitialObservationMode_MetaData), NewProp_InitialObservationMode_MetaData) }; // 1223066713
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_EnteringDuration = { "EnteringDuration", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconDefinition, EnteringDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnteringDuration_MetaData), NewProp_EnteringDuration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_ExitingDuration = { "ExitingDuration", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconDefinition, ExitingDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExitingDuration_MetaData), NewProp_ExitingDuration_MetaData) };
void Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_bAllowListen_SetBit(void* Obj)
{
	((UJMReconDefinition*)Obj)->bAllowListen = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_bAllowListen = { "bAllowListen", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMReconDefinition), &Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_bAllowListen_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowListen_MetaData), NewProp_bAllowListen_MetaData) };
void Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_bAllowPeek_SetBit(void* Obj)
{
	((UJMReconDefinition*)Obj)->bAllowPeek = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_bAllowPeek = { "bAllowPeek", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMReconDefinition), &Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_bAllowPeek_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowPeek_MetaData), NewProp_bAllowPeek_MetaData) };
void Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_bAllowIlluminate_SetBit(void* Obj)
{
	((UJMReconDefinition*)Obj)->bAllowIlluminate = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_bAllowIlluminate = { "bAllowIlluminate", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMReconDefinition), &Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_bAllowIlluminate_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowIlluminate_MetaData), NewProp_bAllowIlluminate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_MinimumListenTime = { "MinimumListenTime", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconDefinition, MinimumListenTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumListenTime_MetaData), NewProp_MinimumListenTime_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_ListenAudioMix = { "ListenAudioMix", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconDefinition, ListenAudioMix), Z_Construct_UClass_USoundMix_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ListenAudioMix_MetaData), NewProp_ListenAudioMix_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_ListenFadeDuration = { "ListenFadeDuration", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconDefinition, ListenFadeDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ListenFadeDuration_MetaData), NewProp_ListenFadeDuration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_PeekOpenFraction = { "PeekOpenFraction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconDefinition, PeekOpenFraction), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PeekOpenFraction_MetaData), NewProp_PeekOpenFraction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_CameraYawLimit = { "CameraYawLimit", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconDefinition, CameraYawLimit), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraYawLimit_MetaData), NewProp_CameraYawLimit_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_CameraPitchLimit = { "CameraPitchLimit", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconDefinition, CameraPitchLimit), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraPitchLimit_MetaData), NewProp_CameraPitchLimit_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_PeekBlendTime = { "PeekBlendTime", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconDefinition, PeekBlendTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PeekBlendTime_MetaData), NewProp_PeekBlendTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_ListenNoise = { "ListenNoise", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconDefinition, ListenNoise), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ListenNoise_MetaData), NewProp_ListenNoise_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_PeekNoise = { "PeekNoise", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconDefinition, PeekNoise), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PeekNoise_MetaData), NewProp_PeekNoise_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_IlluminateEvent = { "IlluminateEvent", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconDefinition, IlluminateEvent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IlluminateEvent_MetaData), NewProp_IlluminateEvent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMReconDefinition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_InitialObservationMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_InitialObservationMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_EnteringDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_ExitingDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_bAllowListen,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_bAllowPeek,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_bAllowIlluminate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_MinimumListenTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_ListenAudioMix,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_ListenFadeDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_PeekOpenFraction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_CameraYawLimit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_CameraPitchLimit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_PeekBlendTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_ListenNoise,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_PeekNoise,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconDefinition_Statics::NewProp_IlluminateEvent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconDefinition_Statics::PropPointers) < 2048);
// ********** End Class UJMReconDefinition Property Definitions ************************************
UObject* (*const Z_Construct_UClass_UJMReconDefinition_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_JMReconRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconDefinition_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMReconDefinition_Statics::ClassParams = {
	&UJMReconDefinition::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMReconDefinition_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconDefinition_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconDefinition_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMReconDefinition_Statics::Class_MetaDataParams)
};
void UJMReconDefinition::StaticRegisterNativesUJMReconDefinition()
{
}
UClass* Z_Construct_UClass_UJMReconDefinition()
{
	if (!Z_Registration_Info_UClass_UJMReconDefinition.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMReconDefinition.OuterSingleton, Z_Construct_UClass_UJMReconDefinition_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMReconDefinition.OuterSingleton;
}
UJMReconDefinition::UJMReconDefinition(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMReconDefinition);
UJMReconDefinition::~UJMReconDefinition() {}
// ********** End Class UJMReconDefinition *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Data_JMReconDefinition_h__Script_JMReconRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMReconDefinition, UJMReconDefinition::StaticClass, TEXT("UJMReconDefinition"), &Z_Registration_Info_UClass_UJMReconDefinition, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMReconDefinition), 2057061970U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Data_JMReconDefinition_h__Script_JMReconRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Data_JMReconDefinition_h__Script_JMReconRuntime_2240921561{
	TEXT("/Script/JMReconRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Data_JMReconDefinition_h__Script_JMReconRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Data_JMReconDefinition_h__Script_JMReconRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
