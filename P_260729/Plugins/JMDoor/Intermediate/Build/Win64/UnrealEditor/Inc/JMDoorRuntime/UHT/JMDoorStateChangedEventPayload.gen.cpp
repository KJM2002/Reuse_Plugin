// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Payloads/JMDoorStateChangedEventPayload.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMDoorStateChangedEventPayload() {}

// ********** Begin Cross Module References ********************************************************
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorStateChangedEventPayload();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorStateChangedEventPayload_NoRegister();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorState();
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventPayloadBase();
UPackage* Z_Construct_UPackage__Script_JMDoorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMDoorStateChangedEventPayload ******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMDoorStateChangedEventPayload;
UClass* UJMDoorStateChangedEventPayload::GetPrivateStaticClass()
{
	using TClass = UJMDoorStateChangedEventPayload;
	if (!Z_Registration_Info_UClass_UJMDoorStateChangedEventPayload.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMDoorStateChangedEventPayload"),
			Z_Registration_Info_UClass_UJMDoorStateChangedEventPayload.InnerSingleton,
			StaticRegisterNativesUJMDoorStateChangedEventPayload,
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
	return Z_Registration_Info_UClass_UJMDoorStateChangedEventPayload.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMDoorStateChangedEventPayload_NoRegister()
{
	return UJMDoorStateChangedEventPayload::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Payloads/JMDoorStateChangedEventPayload.h" },
		{ "ModuleRelativePath", "Public/Payloads/JMDoorStateChangedEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OldState_MetaData[] = {
		{ "Category", "JM Door|Events" },
		{ "ModuleRelativePath", "Public/Payloads/JMDoorStateChangedEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewState_MetaData[] = {
		{ "Category", "JM Door|Events" },
		{ "ModuleRelativePath", "Public/Payloads/JMDoorStateChangedEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpenFraction_MetaData[] = {
		{ "Category", "JM Door|Events" },
		{ "ModuleRelativePath", "Public/Payloads/JMDoorStateChangedEventPayload.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMDoorStateChangedEventPayload constinit property declarations **********
	static const UECodeGen_Private::FBytePropertyParams NewProp_OldState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OldState;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OpenFraction;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMDoorStateChangedEventPayload constinit property declarations ************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMDoorStateChangedEventPayload>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics

// ********** Begin Class UJMDoorStateChangedEventPayload Property Definitions *********************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics::NewProp_OldState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics::NewProp_OldState = { "OldState", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorStateChangedEventPayload, OldState), Z_Construct_UEnum_JMDoorRuntime_EJMDoorState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OldState_MetaData), NewProp_OldState_MetaData) }; // 2513049645
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorStateChangedEventPayload, NewState), Z_Construct_UEnum_JMDoorRuntime_EJMDoorState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewState_MetaData), NewProp_NewState_MetaData) }; // 2513049645
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics::NewProp_OpenFraction = { "OpenFraction", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorStateChangedEventPayload, OpenFraction), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpenFraction_MetaData), NewProp_OpenFraction_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics::NewProp_OldState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics::NewProp_OldState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics::NewProp_NewState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics::NewProp_OpenFraction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics::PropPointers) < 2048);
// ********** End Class UJMDoorStateChangedEventPayload Property Definitions ***********************
UObject* (*const Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UJMGameplayEventPayloadBase,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics::ClassParams = {
	&UJMDoorStateChangedEventPayload::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics::PropPointers),
	0,
	0x003010A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics::Class_MetaDataParams)
};
void UJMDoorStateChangedEventPayload::StaticRegisterNativesUJMDoorStateChangedEventPayload()
{
}
UClass* Z_Construct_UClass_UJMDoorStateChangedEventPayload()
{
	if (!Z_Registration_Info_UClass_UJMDoorStateChangedEventPayload.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMDoorStateChangedEventPayload.OuterSingleton, Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMDoorStateChangedEventPayload.OuterSingleton;
}
UJMDoorStateChangedEventPayload::UJMDoorStateChangedEventPayload(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMDoorStateChangedEventPayload);
UJMDoorStateChangedEventPayload::~UJMDoorStateChangedEventPayload() {}
// ********** End Class UJMDoorStateChangedEventPayload ********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Payloads_JMDoorStateChangedEventPayload_h__Script_JMDoorRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMDoorStateChangedEventPayload, UJMDoorStateChangedEventPayload::StaticClass, TEXT("UJMDoorStateChangedEventPayload"), &Z_Registration_Info_UClass_UJMDoorStateChangedEventPayload, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMDoorStateChangedEventPayload), 3363048197U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Payloads_JMDoorStateChangedEventPayload_h__Script_JMDoorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Payloads_JMDoorStateChangedEventPayload_h__Script_JMDoorRuntime_1192502505{
	TEXT("/Script/JMDoorRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Payloads_JMDoorStateChangedEventPayload_h__Script_JMDoorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Payloads_JMDoorStateChangedEventPayload_h__Script_JMDoorRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
