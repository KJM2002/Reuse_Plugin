// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Subsystems/JMReconGameplayIntegrationWorldSubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMReconGameplayIntegrationWorldSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
JMRECONGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMReconGameplayIntegrationWorldSubsystem();
JMRECONGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMReconGameplayIntegrationWorldSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMReconGameplayIntegration();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMReconGameplayIntegrationWorldSubsystem ********************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMReconGameplayIntegrationWorldSubsystem;
UClass* UJMReconGameplayIntegrationWorldSubsystem::GetPrivateStaticClass()
{
	using TClass = UJMReconGameplayIntegrationWorldSubsystem;
	if (!Z_Registration_Info_UClass_UJMReconGameplayIntegrationWorldSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMReconGameplayIntegrationWorldSubsystem"),
			Z_Registration_Info_UClass_UJMReconGameplayIntegrationWorldSubsystem.InnerSingleton,
			StaticRegisterNativesUJMReconGameplayIntegrationWorldSubsystem,
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
	return Z_Registration_Info_UClass_UJMReconGameplayIntegrationWorldSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMReconGameplayIntegrationWorldSubsystem_NoRegister()
{
	return UJMReconGameplayIntegrationWorldSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMReconGameplayIntegrationWorldSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Subsystems/JMReconGameplayIntegrationWorldSubsystem.h" },
		{ "ModuleRelativePath", "Public/Subsystems/JMReconGameplayIntegrationWorldSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMReconGameplayIntegrationWorldSubsystem constinit property declarations 
// ********** End Class UJMReconGameplayIntegrationWorldSubsystem constinit property declarations **
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMReconGameplayIntegrationWorldSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMReconGameplayIntegrationWorldSubsystem_Statics
UObject* (*const Z_Construct_UClass_UJMReconGameplayIntegrationWorldSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_JMReconGameplayIntegration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconGameplayIntegrationWorldSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMReconGameplayIntegrationWorldSubsystem_Statics::ClassParams = {
	&UJMReconGameplayIntegrationWorldSubsystem::StaticClass,
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
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconGameplayIntegrationWorldSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMReconGameplayIntegrationWorldSubsystem_Statics::Class_MetaDataParams)
};
void UJMReconGameplayIntegrationWorldSubsystem::StaticRegisterNativesUJMReconGameplayIntegrationWorldSubsystem()
{
}
UClass* Z_Construct_UClass_UJMReconGameplayIntegrationWorldSubsystem()
{
	if (!Z_Registration_Info_UClass_UJMReconGameplayIntegrationWorldSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMReconGameplayIntegrationWorldSubsystem.OuterSingleton, Z_Construct_UClass_UJMReconGameplayIntegrationWorldSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMReconGameplayIntegrationWorldSubsystem.OuterSingleton;
}
UJMReconGameplayIntegrationWorldSubsystem::UJMReconGameplayIntegrationWorldSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMReconGameplayIntegrationWorldSubsystem);
UJMReconGameplayIntegrationWorldSubsystem::~UJMReconGameplayIntegrationWorldSubsystem() {}
// ********** End Class UJMReconGameplayIntegrationWorldSubsystem **********************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Subsystems_JMReconGameplayIntegrationWorldSubsystem_h__Script_JMReconGameplayIntegration_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMReconGameplayIntegrationWorldSubsystem, UJMReconGameplayIntegrationWorldSubsystem::StaticClass, TEXT("UJMReconGameplayIntegrationWorldSubsystem"), &Z_Registration_Info_UClass_UJMReconGameplayIntegrationWorldSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMReconGameplayIntegrationWorldSubsystem), 732890962U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Subsystems_JMReconGameplayIntegrationWorldSubsystem_h__Script_JMReconGameplayIntegration_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Subsystems_JMReconGameplayIntegrationWorldSubsystem_h__Script_JMReconGameplayIntegration_897470861{
	TEXT("/Script/JMReconGameplayIntegration"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Subsystems_JMReconGameplayIntegrationWorldSubsystem_h__Script_JMReconGameplayIntegration_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Subsystems_JMReconGameplayIntegrationWorldSubsystem_h__Script_JMReconGameplayIntegration_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
