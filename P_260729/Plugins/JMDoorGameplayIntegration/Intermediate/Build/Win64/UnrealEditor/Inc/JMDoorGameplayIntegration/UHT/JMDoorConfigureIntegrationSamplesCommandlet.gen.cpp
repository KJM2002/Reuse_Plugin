// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Commandlets/JMDoorConfigureIntegrationSamplesCommandlet.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMDoorConfigureIntegrationSamplesCommandlet() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UCommandlet();
JMDOORGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMDoorConfigureIntegrationSamplesCommandlet();
JMDOORGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMDoorConfigureIntegrationSamplesCommandlet_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMDoorGameplayIntegration();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMDoorConfigureIntegrationSamplesCommandlet *****************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMDoorConfigureIntegrationSamplesCommandlet;
UClass* UJMDoorConfigureIntegrationSamplesCommandlet::GetPrivateStaticClass()
{
	using TClass = UJMDoorConfigureIntegrationSamplesCommandlet;
	if (!Z_Registration_Info_UClass_UJMDoorConfigureIntegrationSamplesCommandlet.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMDoorConfigureIntegrationSamplesCommandlet"),
			Z_Registration_Info_UClass_UJMDoorConfigureIntegrationSamplesCommandlet.InnerSingleton,
			StaticRegisterNativesUJMDoorConfigureIntegrationSamplesCommandlet,
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
	return Z_Registration_Info_UClass_UJMDoorConfigureIntegrationSamplesCommandlet.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMDoorConfigureIntegrationSamplesCommandlet_NoRegister()
{
	return UJMDoorConfigureIntegrationSamplesCommandlet::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMDoorConfigureIntegrationSamplesCommandlet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Internal authoring commandlet used to keep the portable Old Key sample configured. */" },
#endif
		{ "IncludePath", "Commandlets/JMDoorConfigureIntegrationSamplesCommandlet.h" },
		{ "ModuleRelativePath", "Public/Commandlets/JMDoorConfigureIntegrationSamplesCommandlet.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Internal authoring commandlet used to keep the portable Old Key sample configured." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UJMDoorConfigureIntegrationSamplesCommandlet constinit property declarations 
// ********** End Class UJMDoorConfigureIntegrationSamplesCommandlet constinit property declarations 
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMDoorConfigureIntegrationSamplesCommandlet>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMDoorConfigureIntegrationSamplesCommandlet_Statics
UObject* (*const Z_Construct_UClass_UJMDoorConfigureIntegrationSamplesCommandlet_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCommandlet,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorGameplayIntegration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorConfigureIntegrationSamplesCommandlet_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMDoorConfigureIntegrationSamplesCommandlet_Statics::ClassParams = {
	&UJMDoorConfigureIntegrationSamplesCommandlet::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorConfigureIntegrationSamplesCommandlet_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMDoorConfigureIntegrationSamplesCommandlet_Statics::Class_MetaDataParams)
};
void UJMDoorConfigureIntegrationSamplesCommandlet::StaticRegisterNativesUJMDoorConfigureIntegrationSamplesCommandlet()
{
}
UClass* Z_Construct_UClass_UJMDoorConfigureIntegrationSamplesCommandlet()
{
	if (!Z_Registration_Info_UClass_UJMDoorConfigureIntegrationSamplesCommandlet.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMDoorConfigureIntegrationSamplesCommandlet.OuterSingleton, Z_Construct_UClass_UJMDoorConfigureIntegrationSamplesCommandlet_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMDoorConfigureIntegrationSamplesCommandlet.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMDoorConfigureIntegrationSamplesCommandlet);
UJMDoorConfigureIntegrationSamplesCommandlet::~UJMDoorConfigureIntegrationSamplesCommandlet() {}
// ********** End Class UJMDoorConfigureIntegrationSamplesCommandlet *******************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Commandlets_JMDoorConfigureIntegrationSamplesCommandlet_h__Script_JMDoorGameplayIntegration_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMDoorConfigureIntegrationSamplesCommandlet, UJMDoorConfigureIntegrationSamplesCommandlet::StaticClass, TEXT("UJMDoorConfigureIntegrationSamplesCommandlet"), &Z_Registration_Info_UClass_UJMDoorConfigureIntegrationSamplesCommandlet, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMDoorConfigureIntegrationSamplesCommandlet), 1879902158U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Commandlets_JMDoorConfigureIntegrationSamplesCommandlet_h__Script_JMDoorGameplayIntegration_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Commandlets_JMDoorConfigureIntegrationSamplesCommandlet_h__Script_JMDoorGameplayIntegration_3638931346{
	TEXT("/Script/JMDoorGameplayIntegration"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Commandlets_JMDoorConfigureIntegrationSamplesCommandlet_h__Script_JMDoorGameplayIntegration_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Commandlets_JMDoorConfigureIntegrationSamplesCommandlet_h__Script_JMDoorGameplayIntegration_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
