// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Subsystems/JMDoorInteractionWorldSubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMDoorInteractionWorldSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
JMDOORGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMDoorInteractionWorldSubsystem();
JMDOORGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMDoorInteractionWorldSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMDoorGameplayIntegration();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMDoorInteractionWorldSubsystem *****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMDoorInteractionWorldSubsystem;
UClass* UJMDoorInteractionWorldSubsystem::GetPrivateStaticClass()
{
	using TClass = UJMDoorInteractionWorldSubsystem;
	if (!Z_Registration_Info_UClass_UJMDoorInteractionWorldSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMDoorInteractionWorldSubsystem"),
			Z_Registration_Info_UClass_UJMDoorInteractionWorldSubsystem.InnerSingleton,
			StaticRegisterNativesUJMDoorInteractionWorldSubsystem,
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
	return Z_Registration_Info_UClass_UJMDoorInteractionWorldSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMDoorInteractionWorldSubsystem_NoRegister()
{
	return UJMDoorInteractionWorldSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMDoorInteractionWorldSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Automatically equips every JMDoor actor with the JM interaction adapter. */" },
#endif
		{ "IncludePath", "Subsystems/JMDoorInteractionWorldSubsystem.h" },
		{ "ModuleRelativePath", "Public/Subsystems/JMDoorInteractionWorldSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Automatically equips every JMDoor actor with the JM interaction adapter." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UJMDoorInteractionWorldSubsystem constinit property declarations *********
// ********** End Class UJMDoorInteractionWorldSubsystem constinit property declarations ***********
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMDoorInteractionWorldSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMDoorInteractionWorldSubsystem_Statics
UObject* (*const Z_Construct_UClass_UJMDoorInteractionWorldSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorGameplayIntegration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorInteractionWorldSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMDoorInteractionWorldSubsystem_Statics::ClassParams = {
	&UJMDoorInteractionWorldSubsystem::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorInteractionWorldSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMDoorInteractionWorldSubsystem_Statics::Class_MetaDataParams)
};
void UJMDoorInteractionWorldSubsystem::StaticRegisterNativesUJMDoorInteractionWorldSubsystem()
{
}
UClass* Z_Construct_UClass_UJMDoorInteractionWorldSubsystem()
{
	if (!Z_Registration_Info_UClass_UJMDoorInteractionWorldSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMDoorInteractionWorldSubsystem.OuterSingleton, Z_Construct_UClass_UJMDoorInteractionWorldSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMDoorInteractionWorldSubsystem.OuterSingleton;
}
UJMDoorInteractionWorldSubsystem::UJMDoorInteractionWorldSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMDoorInteractionWorldSubsystem);
UJMDoorInteractionWorldSubsystem::~UJMDoorInteractionWorldSubsystem() {}
// ********** End Class UJMDoorInteractionWorldSubsystem *******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Subsystems_JMDoorInteractionWorldSubsystem_h__Script_JMDoorGameplayIntegration_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMDoorInteractionWorldSubsystem, UJMDoorInteractionWorldSubsystem::StaticClass, TEXT("UJMDoorInteractionWorldSubsystem"), &Z_Registration_Info_UClass_UJMDoorInteractionWorldSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMDoorInteractionWorldSubsystem), 135047511U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Subsystems_JMDoorInteractionWorldSubsystem_h__Script_JMDoorGameplayIntegration_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Subsystems_JMDoorInteractionWorldSubsystem_h__Script_JMDoorGameplayIntegration_362028927{
	TEXT("/Script/JMDoorGameplayIntegration"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Subsystems_JMDoorInteractionWorldSubsystem_h__Script_JMDoorGameplayIntegration_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Subsystems_JMDoorInteractionWorldSubsystem_h__Script_JMDoorGameplayIntegration_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
