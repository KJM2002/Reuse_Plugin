// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Settings/JMHideSettings.h"
#include "Types/JMHideTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMHideSettings() {}

// ********** Begin Cross Module References ********************************************************
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideSettings();
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideSettings_NoRegister();
JMHIDERUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMHideConfigValues();
UPackage* Z_Construct_UPackage__Script_JMHideRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMHideSettings **********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMHideSettings;
UClass* UJMHideSettings::GetPrivateStaticClass()
{
	using TClass = UJMHideSettings;
	if (!Z_Registration_Info_UClass_UJMHideSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMHideSettings"),
			Z_Registration_Info_UClass_UJMHideSettings.InnerSingleton,
			StaticRegisterNativesUJMHideSettings,
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
	return Z_Registration_Info_UClass_UJMHideSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMHideSettings_NoRegister()
{
	return UJMHideSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMHideSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "JM Hide" },
		{ "IncludePath", "Settings/JMHideSettings.h" },
		{ "ModuleRelativePath", "Public/Settings/JMHideSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Defaults_MetaData[] = {
		{ "Category", "Defaults" },
		{ "ModuleRelativePath", "Public/Settings/JMHideSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMHideSettings constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Defaults;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMHideSettings constinit property declarations ****************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMHideSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMHideSettings_Statics

// ********** Begin Class UJMHideSettings Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMHideSettings_Statics::NewProp_Defaults = { "Defaults", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMHideSettings, Defaults), Z_Construct_UScriptStruct_FJMHideConfigValues, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Defaults_MetaData), NewProp_Defaults_MetaData) }; // 3280257492
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMHideSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideSettings_Statics::NewProp_Defaults,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideSettings_Statics::PropPointers) < 2048);
// ********** End Class UJMHideSettings Property Definitions ***************************************
UObject* (*const Z_Construct_UClass_UJMHideSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMHideSettings_Statics::ClassParams = {
	&UJMHideSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMHideSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMHideSettings_Statics::Class_MetaDataParams)
};
void UJMHideSettings::StaticRegisterNativesUJMHideSettings()
{
}
UClass* Z_Construct_UClass_UJMHideSettings()
{
	if (!Z_Registration_Info_UClass_UJMHideSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMHideSettings.OuterSingleton, Z_Construct_UClass_UJMHideSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMHideSettings.OuterSingleton;
}
UJMHideSettings::UJMHideSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMHideSettings);
UJMHideSettings::~UJMHideSettings() {}
// ********** End Class UJMHideSettings ************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Settings_JMHideSettings_h__Script_JMHideRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMHideSettings, UJMHideSettings::StaticClass, TEXT("UJMHideSettings"), &Z_Registration_Info_UClass_UJMHideSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMHideSettings), 2856838784U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Settings_JMHideSettings_h__Script_JMHideRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Settings_JMHideSettings_h__Script_JMHideRuntime_3892939932{
	TEXT("/Script/JMHideRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Settings_JMHideSettings_h__Script_JMHideRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Settings_JMHideSettings_h__Script_JMHideRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
