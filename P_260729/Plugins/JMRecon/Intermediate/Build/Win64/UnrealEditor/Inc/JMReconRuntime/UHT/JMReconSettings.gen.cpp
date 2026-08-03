// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Settings/JMReconSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMReconSettings() {}

// ********** Begin Cross Module References ********************************************************
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
JMRECONRUNTIME_API UClass* Z_Construct_UClass_UJMReconDefinition_NoRegister();
JMRECONRUNTIME_API UClass* Z_Construct_UClass_UJMReconSettings();
JMRECONRUNTIME_API UClass* Z_Construct_UClass_UJMReconSettings_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMReconRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMReconSettings *********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMReconSettings;
UClass* UJMReconSettings::GetPrivateStaticClass()
{
	using TClass = UJMReconSettings;
	if (!Z_Registration_Info_UClass_UJMReconSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMReconSettings"),
			Z_Registration_Info_UClass_UJMReconSettings.InnerSingleton,
			StaticRegisterNativesUJMReconSettings,
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
	return Z_Registration_Info_UClass_UJMReconSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMReconSettings_NoRegister()
{
	return UJMReconSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMReconSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "JM Recon" },
		{ "IncludePath", "Settings/JMReconSettings.h" },
		{ "ModuleRelativePath", "Public/Settings/JMReconSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultReconDefinition_MetaData[] = {
		{ "Category", "Defaults" },
		{ "ModuleRelativePath", "Public/Settings/JMReconSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultCameraBlendTime_MetaData[] = {
		{ "Category", "Defaults" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/JMReconSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDebugEnabled_MetaData[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/Settings/JMReconSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMReconSettings constinit property declarations *************************
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_DefaultReconDefinition;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultCameraBlendTime;
	static void NewProp_bDebugEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDebugEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMReconSettings constinit property declarations ***************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMReconSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMReconSettings_Statics

// ********** Begin Class UJMReconSettings Property Definitions ************************************
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UJMReconSettings_Statics::NewProp_DefaultReconDefinition = { "DefaultReconDefinition", nullptr, (EPropertyFlags)0x0014000000004001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconSettings, DefaultReconDefinition), Z_Construct_UClass_UJMReconDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultReconDefinition_MetaData), NewProp_DefaultReconDefinition_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMReconSettings_Statics::NewProp_DefaultCameraBlendTime = { "DefaultCameraBlendTime", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconSettings, DefaultCameraBlendTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultCameraBlendTime_MetaData), NewProp_DefaultCameraBlendTime_MetaData) };
void Z_Construct_UClass_UJMReconSettings_Statics::NewProp_bDebugEnabled_SetBit(void* Obj)
{
	((UJMReconSettings*)Obj)->bDebugEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMReconSettings_Statics::NewProp_bDebugEnabled = { "bDebugEnabled", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMReconSettings), &Z_Construct_UClass_UJMReconSettings_Statics::NewProp_bDebugEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDebugEnabled_MetaData), NewProp_bDebugEnabled_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMReconSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconSettings_Statics::NewProp_DefaultReconDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconSettings_Statics::NewProp_DefaultCameraBlendTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconSettings_Statics::NewProp_bDebugEnabled,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconSettings_Statics::PropPointers) < 2048);
// ********** End Class UJMReconSettings Property Definitions **************************************
UObject* (*const Z_Construct_UClass_UJMReconSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_JMReconRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMReconSettings_Statics::ClassParams = {
	&UJMReconSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMReconSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMReconSettings_Statics::Class_MetaDataParams)
};
void UJMReconSettings::StaticRegisterNativesUJMReconSettings()
{
}
UClass* Z_Construct_UClass_UJMReconSettings()
{
	if (!Z_Registration_Info_UClass_UJMReconSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMReconSettings.OuterSingleton, Z_Construct_UClass_UJMReconSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMReconSettings.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMReconSettings);
UJMReconSettings::~UJMReconSettings() {}
// ********** End Class UJMReconSettings ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Settings_JMReconSettings_h__Script_JMReconRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMReconSettings, UJMReconSettings::StaticClass, TEXT("UJMReconSettings"), &Z_Registration_Info_UClass_UJMReconSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMReconSettings), 3923325520U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Settings_JMReconSettings_h__Script_JMReconRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Settings_JMReconSettings_h__Script_JMReconRuntime_2492828458{
	TEXT("/Script/JMReconRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Settings_JMReconSettings_h__Script_JMReconRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Settings_JMReconSettings_h__Script_JMReconRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
