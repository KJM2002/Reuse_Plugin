// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Settings/JMDoorGameplayIntegrationSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMDoorGameplayIntegrationSettings() {}

// ********** Begin Cross Module References ********************************************************
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
JMDOORGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMDoorGameplayIntegrationSettings();
JMDOORGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMDoorGameplayIntegrationSettings_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMDoorGameplayIntegration();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMDoorGameplayIntegrationSettings ***************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMDoorGameplayIntegrationSettings;
UClass* UJMDoorGameplayIntegrationSettings::GetPrivateStaticClass()
{
	using TClass = UJMDoorGameplayIntegrationSettings;
	if (!Z_Registration_Info_UClass_UJMDoorGameplayIntegrationSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMDoorGameplayIntegrationSettings"),
			Z_Registration_Info_UClass_UJMDoorGameplayIntegrationSettings.InnerSingleton,
			StaticRegisterNativesUJMDoorGameplayIntegrationSettings,
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
	return Z_Registration_Info_UClass_UJMDoorGameplayIntegrationSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMDoorGameplayIntegrationSettings_NoRegister()
{
	return UJMDoorGameplayIntegrationSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMDoorGameplayIntegrationSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Project-wide defaults for the automatically-created door interaction adapter.\n * Add a JMDoorInteractableAdapterComponent to an individual door to override them.\n */" },
#endif
		{ "DisplayName", "JM Door Gameplay Integration" },
		{ "IncludePath", "Settings/JMDoorGameplayIntegrationSettings.h" },
		{ "ModuleRelativePath", "Public/Settings/JMDoorGameplayIntegrationSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Project-wide defaults for the automatically-created door interaction adapter.\nAdd a JMDoorInteractableAdapterComponent to an individual door to override them." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpenDoorPrompt_MetaData[] = {
		{ "Category", "Interaction Prompt" },
		{ "ModuleRelativePath", "Public/Settings/JMDoorGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CloseDoorPrompt_MetaData[] = {
		{ "Category", "Interaction Prompt" },
		{ "ModuleRelativePath", "Public/Settings/JMDoorGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LockedDoorPrompt_MetaData[] = {
		{ "Category", "Interaction Prompt" },
		{ "ModuleRelativePath", "Public/Settings/JMDoorGameplayIntegrationSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMDoorGameplayIntegrationSettings constinit property declarations *******
	static const UECodeGen_Private::FTextPropertyParams NewProp_OpenDoorPrompt;
	static const UECodeGen_Private::FTextPropertyParams NewProp_CloseDoorPrompt;
	static const UECodeGen_Private::FTextPropertyParams NewProp_LockedDoorPrompt;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMDoorGameplayIntegrationSettings constinit property declarations *********
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMDoorGameplayIntegrationSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMDoorGameplayIntegrationSettings_Statics

// ********** Begin Class UJMDoorGameplayIntegrationSettings Property Definitions ******************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMDoorGameplayIntegrationSettings_Statics::NewProp_OpenDoorPrompt = { "OpenDoorPrompt", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorGameplayIntegrationSettings, OpenDoorPrompt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpenDoorPrompt_MetaData), NewProp_OpenDoorPrompt_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMDoorGameplayIntegrationSettings_Statics::NewProp_CloseDoorPrompt = { "CloseDoorPrompt", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorGameplayIntegrationSettings, CloseDoorPrompt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CloseDoorPrompt_MetaData), NewProp_CloseDoorPrompt_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMDoorGameplayIntegrationSettings_Statics::NewProp_LockedDoorPrompt = { "LockedDoorPrompt", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorGameplayIntegrationSettings, LockedDoorPrompt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LockedDoorPrompt_MetaData), NewProp_LockedDoorPrompt_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMDoorGameplayIntegrationSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorGameplayIntegrationSettings_Statics::NewProp_OpenDoorPrompt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorGameplayIntegrationSettings_Statics::NewProp_CloseDoorPrompt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorGameplayIntegrationSettings_Statics::NewProp_LockedDoorPrompt,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorGameplayIntegrationSettings_Statics::PropPointers) < 2048);
// ********** End Class UJMDoorGameplayIntegrationSettings Property Definitions ********************
UObject* (*const Z_Construct_UClass_UJMDoorGameplayIntegrationSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorGameplayIntegration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorGameplayIntegrationSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMDoorGameplayIntegrationSettings_Statics::ClassParams = {
	&UJMDoorGameplayIntegrationSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMDoorGameplayIntegrationSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorGameplayIntegrationSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorGameplayIntegrationSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMDoorGameplayIntegrationSettings_Statics::Class_MetaDataParams)
};
void UJMDoorGameplayIntegrationSettings::StaticRegisterNativesUJMDoorGameplayIntegrationSettings()
{
}
UClass* Z_Construct_UClass_UJMDoorGameplayIntegrationSettings()
{
	if (!Z_Registration_Info_UClass_UJMDoorGameplayIntegrationSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMDoorGameplayIntegrationSettings.OuterSingleton, Z_Construct_UClass_UJMDoorGameplayIntegrationSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMDoorGameplayIntegrationSettings.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMDoorGameplayIntegrationSettings);
UJMDoorGameplayIntegrationSettings::~UJMDoorGameplayIntegrationSettings() {}
// ********** End Class UJMDoorGameplayIntegrationSettings *****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Settings_JMDoorGameplayIntegrationSettings_h__Script_JMDoorGameplayIntegration_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMDoorGameplayIntegrationSettings, UJMDoorGameplayIntegrationSettings::StaticClass, TEXT("UJMDoorGameplayIntegrationSettings"), &Z_Registration_Info_UClass_UJMDoorGameplayIntegrationSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMDoorGameplayIntegrationSettings), 166643021U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Settings_JMDoorGameplayIntegrationSettings_h__Script_JMDoorGameplayIntegration_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Settings_JMDoorGameplayIntegrationSettings_h__Script_JMDoorGameplayIntegration_2988657593{
	TEXT("/Script/JMDoorGameplayIntegration"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Settings_JMDoorGameplayIntegrationSettings_h__Script_JMDoorGameplayIntegration_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Settings_JMDoorGameplayIntegrationSettings_h__Script_JMDoorGameplayIntegration_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
