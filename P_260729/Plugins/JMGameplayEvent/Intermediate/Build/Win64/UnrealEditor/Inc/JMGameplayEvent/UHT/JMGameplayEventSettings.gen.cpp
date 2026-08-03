// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Settings/JMGameplayEventSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMGameplayEventSettings() {}

// ********** Begin Cross Module References ********************************************************
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventSettings();
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventSettings_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMGameplayEvent();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMGameplayEventSettings *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMGameplayEventSettings;
UClass* UJMGameplayEventSettings::GetPrivateStaticClass()
{
	using TClass = UJMGameplayEventSettings;
	if (!Z_Registration_Info_UClass_UJMGameplayEventSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMGameplayEventSettings"),
			Z_Registration_Info_UClass_UJMGameplayEventSettings.InnerSingleton,
			StaticRegisterNativesUJMGameplayEventSettings,
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
	return Z_Registration_Info_UClass_UJMGameplayEventSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMGameplayEventSettings_NoRegister()
{
	return UJMGameplayEventSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMGameplayEventSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "JM Gameplay Event" },
		{ "IncludePath", "Settings/JMGameplayEventSettings.h" },
		{ "ModuleRelativePath", "Public/Settings/JMGameplayEventSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDebugLogging_MetaData[] = {
		{ "Category", "Logging" },
		{ "ModuleRelativePath", "Public/Settings/JMGameplayEventSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLogPublishedEvents_MetaData[] = {
		{ "Category", "Logging" },
		{ "EditCondition", "bEnableDebugLogging" },
		{ "ModuleRelativePath", "Public/Settings/JMGameplayEventSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLogUnhandledEvents_MetaData[] = {
		{ "Category", "Logging" },
		{ "EditCondition", "bEnableDebugLogging" },
		{ "ModuleRelativePath", "Public/Settings/JMGameplayEventSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bWarnDuplicateSubscription_MetaData[] = {
		{ "Category", "Safety" },
		{ "ModuleRelativePath", "Public/Settings/JMGameplayEventSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumNestedDispatchDepth_MetaData[] = {
		{ "Category", "Safety" },
		{ "ClampMax", "128" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/Settings/JMGameplayEventSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMGameplayEventSettings constinit property declarations *****************
	static void NewProp_bEnableDebugLogging_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDebugLogging;
	static void NewProp_bLogPublishedEvents_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLogPublishedEvents;
	static void NewProp_bLogUnhandledEvents_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLogUnhandledEvents;
	static void NewProp_bWarnDuplicateSubscription_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWarnDuplicateSubscription;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaximumNestedDispatchDepth;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMGameplayEventSettings constinit property declarations *******************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMGameplayEventSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMGameplayEventSettings_Statics

// ********** Begin Class UJMGameplayEventSettings Property Definitions ****************************
void Z_Construct_UClass_UJMGameplayEventSettings_Statics::NewProp_bEnableDebugLogging_SetBit(void* Obj)
{
	((UJMGameplayEventSettings*)Obj)->bEnableDebugLogging = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMGameplayEventSettings_Statics::NewProp_bEnableDebugLogging = { "bEnableDebugLogging", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMGameplayEventSettings), &Z_Construct_UClass_UJMGameplayEventSettings_Statics::NewProp_bEnableDebugLogging_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDebugLogging_MetaData), NewProp_bEnableDebugLogging_MetaData) };
void Z_Construct_UClass_UJMGameplayEventSettings_Statics::NewProp_bLogPublishedEvents_SetBit(void* Obj)
{
	((UJMGameplayEventSettings*)Obj)->bLogPublishedEvents = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMGameplayEventSettings_Statics::NewProp_bLogPublishedEvents = { "bLogPublishedEvents", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMGameplayEventSettings), &Z_Construct_UClass_UJMGameplayEventSettings_Statics::NewProp_bLogPublishedEvents_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLogPublishedEvents_MetaData), NewProp_bLogPublishedEvents_MetaData) };
void Z_Construct_UClass_UJMGameplayEventSettings_Statics::NewProp_bLogUnhandledEvents_SetBit(void* Obj)
{
	((UJMGameplayEventSettings*)Obj)->bLogUnhandledEvents = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMGameplayEventSettings_Statics::NewProp_bLogUnhandledEvents = { "bLogUnhandledEvents", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMGameplayEventSettings), &Z_Construct_UClass_UJMGameplayEventSettings_Statics::NewProp_bLogUnhandledEvents_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLogUnhandledEvents_MetaData), NewProp_bLogUnhandledEvents_MetaData) };
void Z_Construct_UClass_UJMGameplayEventSettings_Statics::NewProp_bWarnDuplicateSubscription_SetBit(void* Obj)
{
	((UJMGameplayEventSettings*)Obj)->bWarnDuplicateSubscription = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMGameplayEventSettings_Statics::NewProp_bWarnDuplicateSubscription = { "bWarnDuplicateSubscription", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMGameplayEventSettings), &Z_Construct_UClass_UJMGameplayEventSettings_Statics::NewProp_bWarnDuplicateSubscription_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bWarnDuplicateSubscription_MetaData), NewProp_bWarnDuplicateSubscription_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UJMGameplayEventSettings_Statics::NewProp_MaximumNestedDispatchDepth = { "MaximumNestedDispatchDepth", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMGameplayEventSettings, MaximumNestedDispatchDepth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumNestedDispatchDepth_MetaData), NewProp_MaximumNestedDispatchDepth_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMGameplayEventSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMGameplayEventSettings_Statics::NewProp_bEnableDebugLogging,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMGameplayEventSettings_Statics::NewProp_bLogPublishedEvents,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMGameplayEventSettings_Statics::NewProp_bLogUnhandledEvents,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMGameplayEventSettings_Statics::NewProp_bWarnDuplicateSubscription,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMGameplayEventSettings_Statics::NewProp_MaximumNestedDispatchDepth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMGameplayEventSettings_Statics::PropPointers) < 2048);
// ********** End Class UJMGameplayEventSettings Property Definitions ******************************
UObject* (*const Z_Construct_UClass_UJMGameplayEventSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_JMGameplayEvent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMGameplayEventSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMGameplayEventSettings_Statics::ClassParams = {
	&UJMGameplayEventSettings::StaticClass,
	"JMGameplayEvent",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMGameplayEventSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMGameplayEventSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMGameplayEventSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMGameplayEventSettings_Statics::Class_MetaDataParams)
};
void UJMGameplayEventSettings::StaticRegisterNativesUJMGameplayEventSettings()
{
}
UClass* Z_Construct_UClass_UJMGameplayEventSettings()
{
	if (!Z_Registration_Info_UClass_UJMGameplayEventSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMGameplayEventSettings.OuterSingleton, Z_Construct_UClass_UJMGameplayEventSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMGameplayEventSettings.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMGameplayEventSettings);
UJMGameplayEventSettings::~UJMGameplayEventSettings() {}
// ********** End Class UJMGameplayEventSettings ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Settings_JMGameplayEventSettings_h__Script_JMGameplayEvent_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMGameplayEventSettings, UJMGameplayEventSettings::StaticClass, TEXT("UJMGameplayEventSettings"), &Z_Registration_Info_UClass_UJMGameplayEventSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMGameplayEventSettings), 3917177080U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Settings_JMGameplayEventSettings_h__Script_JMGameplayEvent_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Settings_JMGameplayEventSettings_h__Script_JMGameplayEvent_782299115{
	TEXT("/Script/JMGameplayEvent"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Settings_JMGameplayEventSettings_h__Script_JMGameplayEvent_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Settings_JMGameplayEventSettings_h__Script_JMGameplayEvent_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
