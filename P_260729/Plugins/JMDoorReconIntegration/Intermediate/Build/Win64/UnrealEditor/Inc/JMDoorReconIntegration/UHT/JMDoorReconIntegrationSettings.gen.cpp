// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Settings/JMDoorReconIntegrationSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMDoorReconIntegrationSettings() {}

// ********** Begin Cross Module References ********************************************************
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
JMDOORRECONINTEGRATION_API UClass* Z_Construct_UClass_UJMDoorReconIntegrationSettings();
JMDOORRECONINTEGRATION_API UClass* Z_Construct_UClass_UJMDoorReconIntegrationSettings_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMDoorReconIntegration();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMDoorReconIntegrationSettings ******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMDoorReconIntegrationSettings;
UClass* UJMDoorReconIntegrationSettings::GetPrivateStaticClass()
{
	using TClass = UJMDoorReconIntegrationSettings;
	if (!Z_Registration_Info_UClass_UJMDoorReconIntegrationSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMDoorReconIntegrationSettings"),
			Z_Registration_Info_UClass_UJMDoorReconIntegrationSettings.InnerSingleton,
			StaticRegisterNativesUJMDoorReconIntegrationSettings,
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
	return Z_Registration_Info_UClass_UJMDoorReconIntegrationSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMDoorReconIntegrationSettings_NoRegister()
{
	return UJMDoorReconIntegrationSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMDoorReconIntegrationSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "JM Door Recon Integration" },
		{ "IncludePath", "Settings/JMDoorReconIntegrationSettings.h" },
		{ "ModuleRelativePath", "Public/Settings/JMDoorReconIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoAddDoorAdapter_MetaData[] = {
		{ "Category", "Automatic Setup" },
		{ "ModuleRelativePath", "Public/Settings/JMDoorReconIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpenBlendDuration_MetaData[] = {
		{ "Category", "Door Pose" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/JMDoorReconIntegrationSettings.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RestoreBlendDuration_MetaData[] = {
		{ "Category", "Door Pose" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/JMDoorReconIntegrationSettings.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumExistingOpenFraction_MetaData[] = {
		{ "Category", "Door Pose" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/JMDoorReconIntegrationSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMDoorReconIntegrationSettings constinit property declarations **********
	static void NewProp_bAutoAddDoorAdapter_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoAddDoorAdapter;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OpenBlendDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RestoreBlendDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaximumExistingOpenFraction;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMDoorReconIntegrationSettings constinit property declarations ************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMDoorReconIntegrationSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMDoorReconIntegrationSettings_Statics

// ********** Begin Class UJMDoorReconIntegrationSettings Property Definitions *********************
void Z_Construct_UClass_UJMDoorReconIntegrationSettings_Statics::NewProp_bAutoAddDoorAdapter_SetBit(void* Obj)
{
	((UJMDoorReconIntegrationSettings*)Obj)->bAutoAddDoorAdapter = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMDoorReconIntegrationSettings_Statics::NewProp_bAutoAddDoorAdapter = { "bAutoAddDoorAdapter", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMDoorReconIntegrationSettings), &Z_Construct_UClass_UJMDoorReconIntegrationSettings_Statics::NewProp_bAutoAddDoorAdapter_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoAddDoorAdapter_MetaData), NewProp_bAutoAddDoorAdapter_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorReconIntegrationSettings_Statics::NewProp_OpenBlendDuration = { "OpenBlendDuration", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorReconIntegrationSettings, OpenBlendDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpenBlendDuration_MetaData), NewProp_OpenBlendDuration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorReconIntegrationSettings_Statics::NewProp_RestoreBlendDuration = { "RestoreBlendDuration", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorReconIntegrationSettings, RestoreBlendDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RestoreBlendDuration_MetaData), NewProp_RestoreBlendDuration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorReconIntegrationSettings_Statics::NewProp_MaximumExistingOpenFraction = { "MaximumExistingOpenFraction", nullptr, (EPropertyFlags)0x0010040000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorReconIntegrationSettings, MaximumExistingOpenFraction), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumExistingOpenFraction_MetaData), NewProp_MaximumExistingOpenFraction_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMDoorReconIntegrationSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorReconIntegrationSettings_Statics::NewProp_bAutoAddDoorAdapter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorReconIntegrationSettings_Statics::NewProp_OpenBlendDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorReconIntegrationSettings_Statics::NewProp_RestoreBlendDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorReconIntegrationSettings_Statics::NewProp_MaximumExistingOpenFraction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorReconIntegrationSettings_Statics::PropPointers) < 2048);
// ********** End Class UJMDoorReconIntegrationSettings Property Definitions ***********************
UObject* (*const Z_Construct_UClass_UJMDoorReconIntegrationSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorReconIntegration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorReconIntegrationSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMDoorReconIntegrationSettings_Statics::ClassParams = {
	&UJMDoorReconIntegrationSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMDoorReconIntegrationSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorReconIntegrationSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorReconIntegrationSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMDoorReconIntegrationSettings_Statics::Class_MetaDataParams)
};
void UJMDoorReconIntegrationSettings::StaticRegisterNativesUJMDoorReconIntegrationSettings()
{
}
UClass* Z_Construct_UClass_UJMDoorReconIntegrationSettings()
{
	if (!Z_Registration_Info_UClass_UJMDoorReconIntegrationSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMDoorReconIntegrationSettings.OuterSingleton, Z_Construct_UClass_UJMDoorReconIntegrationSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMDoorReconIntegrationSettings.OuterSingleton;
}
UJMDoorReconIntegrationSettings::UJMDoorReconIntegrationSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMDoorReconIntegrationSettings);
UJMDoorReconIntegrationSettings::~UJMDoorReconIntegrationSettings() {}
// ********** End Class UJMDoorReconIntegrationSettings ********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorReconIntegration_Source_JMDoorReconIntegration_Public_Settings_JMDoorReconIntegrationSettings_h__Script_JMDoorReconIntegration_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMDoorReconIntegrationSettings, UJMDoorReconIntegrationSettings::StaticClass, TEXT("UJMDoorReconIntegrationSettings"), &Z_Registration_Info_UClass_UJMDoorReconIntegrationSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMDoorReconIntegrationSettings), 1970208312U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorReconIntegration_Source_JMDoorReconIntegration_Public_Settings_JMDoorReconIntegrationSettings_h__Script_JMDoorReconIntegration_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorReconIntegration_Source_JMDoorReconIntegration_Public_Settings_JMDoorReconIntegrationSettings_h__Script_JMDoorReconIntegration_1730390485{
	TEXT("/Script/JMDoorReconIntegration"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorReconIntegration_Source_JMDoorReconIntegration_Public_Settings_JMDoorReconIntegrationSettings_h__Script_JMDoorReconIntegration_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorReconIntegration_Source_JMDoorReconIntegration_Public_Settings_JMDoorReconIntegrationSettings_h__Script_JMDoorReconIntegration_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
