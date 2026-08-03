// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Settings/JMJumpScareSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMJumpScareSettings() {}

// ********** Begin Cross Module References ********************************************************
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareSettings();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareSettings_NoRegister();
JMJUMPSCARE_API UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScareConcurrentPolicy();
JMJUMPSCARE_API UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScareOverlapFilter();
JMJUMPSCARE_API UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScareTriggerPolicy();
UPackage* Z_Construct_UPackage__Script_JMJumpScare();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMJumpScareSettings *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMJumpScareSettings;
UClass* UJMJumpScareSettings::GetPrivateStaticClass()
{
	using TClass = UJMJumpScareSettings;
	if (!Z_Registration_Info_UClass_UJMJumpScareSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMJumpScareSettings"),
			Z_Registration_Info_UClass_UJMJumpScareSettings.InnerSingleton,
			StaticRegisterNativesUJMJumpScareSettings,
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
	return Z_Registration_Info_UClass_UJMJumpScareSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMJumpScareSettings_NoRegister()
{
	return UJMJumpScareSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMJumpScareSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "JM JumpScare" },
		{ "IncludePath", "Settings/JMJumpScareSettings.h" },
		{ "ModuleRelativePath", "Public/Settings/JMJumpScareSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Configure reusable JM JumpScare runtime defaults." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDebugLogging_MetaData[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/Settings/JMJumpScareSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowDebugSpawnTransform_MetaData[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/Settings/JMJumpScareSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultTriggerPolicy_MetaData[] = {
		{ "Category", "Defaults" },
		{ "ModuleRelativePath", "Public/Settings/JMJumpScareSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultOverlapActorFilter_MetaData[] = {
		{ "Category", "Defaults" },
		{ "ModuleRelativePath", "Public/Settings/JMJumpScareSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultConcurrentPolicy_MetaData[] = {
		{ "Category", "Defaults" },
		{ "ModuleRelativePath", "Public/Settings/JMJumpScareSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMJumpScareSettings constinit property declarations *********************
	static void NewProp_bEnableDebugLogging_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDebugLogging;
	static void NewProp_bShowDebugSpawnTransform_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowDebugSpawnTransform;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DefaultTriggerPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DefaultTriggerPolicy;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DefaultOverlapActorFilter_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DefaultOverlapActorFilter;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DefaultConcurrentPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DefaultConcurrentPolicy;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMJumpScareSettings constinit property declarations ***********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMJumpScareSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMJumpScareSettings_Statics

// ********** Begin Class UJMJumpScareSettings Property Definitions ********************************
void Z_Construct_UClass_UJMJumpScareSettings_Statics::NewProp_bEnableDebugLogging_SetBit(void* Obj)
{
	((UJMJumpScareSettings*)Obj)->bEnableDebugLogging = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMJumpScareSettings_Statics::NewProp_bEnableDebugLogging = { "bEnableDebugLogging", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMJumpScareSettings), &Z_Construct_UClass_UJMJumpScareSettings_Statics::NewProp_bEnableDebugLogging_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDebugLogging_MetaData), NewProp_bEnableDebugLogging_MetaData) };
void Z_Construct_UClass_UJMJumpScareSettings_Statics::NewProp_bShowDebugSpawnTransform_SetBit(void* Obj)
{
	((UJMJumpScareSettings*)Obj)->bShowDebugSpawnTransform = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMJumpScareSettings_Statics::NewProp_bShowDebugSpawnTransform = { "bShowDebugSpawnTransform", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMJumpScareSettings), &Z_Construct_UClass_UJMJumpScareSettings_Statics::NewProp_bShowDebugSpawnTransform_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowDebugSpawnTransform_MetaData), NewProp_bShowDebugSpawnTransform_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMJumpScareSettings_Statics::NewProp_DefaultTriggerPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMJumpScareSettings_Statics::NewProp_DefaultTriggerPolicy = { "DefaultTriggerPolicy", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareSettings, DefaultTriggerPolicy), Z_Construct_UEnum_JMJumpScare_EJMJumpScareTriggerPolicy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultTriggerPolicy_MetaData), NewProp_DefaultTriggerPolicy_MetaData) }; // 453019027
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMJumpScareSettings_Statics::NewProp_DefaultOverlapActorFilter_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMJumpScareSettings_Statics::NewProp_DefaultOverlapActorFilter = { "DefaultOverlapActorFilter", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareSettings, DefaultOverlapActorFilter), Z_Construct_UEnum_JMJumpScare_EJMJumpScareOverlapFilter, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultOverlapActorFilter_MetaData), NewProp_DefaultOverlapActorFilter_MetaData) }; // 2064440234
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMJumpScareSettings_Statics::NewProp_DefaultConcurrentPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMJumpScareSettings_Statics::NewProp_DefaultConcurrentPolicy = { "DefaultConcurrentPolicy", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareSettings, DefaultConcurrentPolicy), Z_Construct_UEnum_JMJumpScare_EJMJumpScareConcurrentPolicy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultConcurrentPolicy_MetaData), NewProp_DefaultConcurrentPolicy_MetaData) }; // 1198158541
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMJumpScareSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareSettings_Statics::NewProp_bEnableDebugLogging,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareSettings_Statics::NewProp_bShowDebugSpawnTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareSettings_Statics::NewProp_DefaultTriggerPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareSettings_Statics::NewProp_DefaultTriggerPolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareSettings_Statics::NewProp_DefaultOverlapActorFilter_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareSettings_Statics::NewProp_DefaultOverlapActorFilter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareSettings_Statics::NewProp_DefaultConcurrentPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareSettings_Statics::NewProp_DefaultConcurrentPolicy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareSettings_Statics::PropPointers) < 2048);
// ********** End Class UJMJumpScareSettings Property Definitions **********************************
UObject* (*const Z_Construct_UClass_UJMJumpScareSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_JMJumpScare,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMJumpScareSettings_Statics::ClassParams = {
	&UJMJumpScareSettings::StaticClass,
	"JMJumpScare",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMJumpScareSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMJumpScareSettings_Statics::Class_MetaDataParams)
};
void UJMJumpScareSettings::StaticRegisterNativesUJMJumpScareSettings()
{
}
UClass* Z_Construct_UClass_UJMJumpScareSettings()
{
	if (!Z_Registration_Info_UClass_UJMJumpScareSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMJumpScareSettings.OuterSingleton, Z_Construct_UClass_UJMJumpScareSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMJumpScareSettings.OuterSingleton;
}
UJMJumpScareSettings::UJMJumpScareSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMJumpScareSettings);
UJMJumpScareSettings::~UJMJumpScareSettings() {}
// ********** End Class UJMJumpScareSettings *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Settings_JMJumpScareSettings_h__Script_JMJumpScare_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMJumpScareSettings, UJMJumpScareSettings::StaticClass, TEXT("UJMJumpScareSettings"), &Z_Registration_Info_UClass_UJMJumpScareSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMJumpScareSettings), 623696085U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Settings_JMJumpScareSettings_h__Script_JMJumpScare_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Settings_JMJumpScareSettings_h__Script_JMJumpScare_1000669040{
	TEXT("/Script/JMJumpScare"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Settings_JMJumpScareSettings_h__Script_JMJumpScare_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Settings_JMJumpScareSettings_h__Script_JMJumpScare_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
