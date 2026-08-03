// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Settings/JMObjectiveSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMObjectiveSettings() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveSettings();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveSettings_NoRegister();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveWidgetBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMObjective();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMObjectiveSettings *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMObjectiveSettings;
UClass* UJMObjectiveSettings::GetPrivateStaticClass()
{
	using TClass = UJMObjectiveSettings;
	if (!Z_Registration_Info_UClass_UJMObjectiveSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMObjectiveSettings"),
			Z_Registration_Info_UClass_UJMObjectiveSettings.InnerSingleton,
			StaticRegisterNativesUJMObjectiveSettings,
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
	return Z_Registration_Info_UClass_UJMObjectiveSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMObjectiveSettings_NoRegister()
{
	return UJMObjectiveSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMObjectiveSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "JM Objective" },
		{ "IncludePath", "Settings/JMObjectiveSettings.h" },
		{ "ModuleRelativePath", "Public/Settings/JMObjectiveSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDebugLogging_MetaData[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/Settings/JMObjectiveSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLogObjectiveRegistration_MetaData[] = {
		{ "Category", "Debug" },
		{ "EditCondition", "bEnableDebugLogging" },
		{ "ModuleRelativePath", "Public/Settings/JMObjectiveSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLogEventFiltering_MetaData[] = {
		{ "Category", "Debug" },
		{ "EditCondition", "bEnableDebugLogging" },
		{ "ModuleRelativePath", "Public/Settings/JMObjectiveSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLogProgressChanges_MetaData[] = {
		{ "Category", "Debug" },
		{ "EditCondition", "bEnableDebugLogging" },
		{ "ModuleRelativePath", "Public/Settings/JMObjectiveSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLogStateChanges_MetaData[] = {
		{ "Category", "Debug" },
		{ "EditCondition", "bEnableDebugLogging" },
		{ "ModuleRelativePath", "Public/Settings/JMObjectiveSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bWarnDuplicateObjectiveId_MetaData[] = {
		{ "Category", "Validation" },
		{ "ModuleRelativePath", "Public/Settings/JMObjectiveSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultObjectiveWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/Settings/JMObjectiveSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutomaticallyCreateObjectiveUI_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/Settings/JMObjectiveSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectiveWidgetZOrder_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/Settings/JMObjectiveSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHideWidgetWhenNoActiveObjective_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/Settings/JMObjectiveSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CompletedDisplayDuration_MetaData[] = {
		{ "Category", "UI" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/JMObjectiveSettings.h" },
		{ "UIMin", "0.0" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMObjectiveSettings constinit property declarations *********************
	static void NewProp_bEnableDebugLogging_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDebugLogging;
	static void NewProp_bLogObjectiveRegistration_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLogObjectiveRegistration;
	static void NewProp_bLogEventFiltering_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLogEventFiltering;
	static void NewProp_bLogProgressChanges_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLogProgressChanges;
	static void NewProp_bLogStateChanges_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLogStateChanges;
	static void NewProp_bWarnDuplicateObjectiveId_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWarnDuplicateObjectiveId;
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_DefaultObjectiveWidgetClass;
	static void NewProp_bAutomaticallyCreateObjectiveUI_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutomaticallyCreateObjectiveUI;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ObjectiveWidgetZOrder;
	static void NewProp_bHideWidgetWhenNoActiveObjective_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHideWidgetWhenNoActiveObjective;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CompletedDisplayDuration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMObjectiveSettings constinit property declarations ***********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMObjectiveSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMObjectiveSettings_Statics

// ********** Begin Class UJMObjectiveSettings Property Definitions ********************************
void Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bEnableDebugLogging_SetBit(void* Obj)
{
	((UJMObjectiveSettings*)Obj)->bEnableDebugLogging = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bEnableDebugLogging = { "bEnableDebugLogging", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMObjectiveSettings), &Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bEnableDebugLogging_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDebugLogging_MetaData), NewProp_bEnableDebugLogging_MetaData) };
void Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bLogObjectiveRegistration_SetBit(void* Obj)
{
	((UJMObjectiveSettings*)Obj)->bLogObjectiveRegistration = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bLogObjectiveRegistration = { "bLogObjectiveRegistration", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMObjectiveSettings), &Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bLogObjectiveRegistration_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLogObjectiveRegistration_MetaData), NewProp_bLogObjectiveRegistration_MetaData) };
void Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bLogEventFiltering_SetBit(void* Obj)
{
	((UJMObjectiveSettings*)Obj)->bLogEventFiltering = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bLogEventFiltering = { "bLogEventFiltering", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMObjectiveSettings), &Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bLogEventFiltering_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLogEventFiltering_MetaData), NewProp_bLogEventFiltering_MetaData) };
void Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bLogProgressChanges_SetBit(void* Obj)
{
	((UJMObjectiveSettings*)Obj)->bLogProgressChanges = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bLogProgressChanges = { "bLogProgressChanges", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMObjectiveSettings), &Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bLogProgressChanges_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLogProgressChanges_MetaData), NewProp_bLogProgressChanges_MetaData) };
void Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bLogStateChanges_SetBit(void* Obj)
{
	((UJMObjectiveSettings*)Obj)->bLogStateChanges = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bLogStateChanges = { "bLogStateChanges", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMObjectiveSettings), &Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bLogStateChanges_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLogStateChanges_MetaData), NewProp_bLogStateChanges_MetaData) };
void Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bWarnDuplicateObjectiveId_SetBit(void* Obj)
{
	((UJMObjectiveSettings*)Obj)->bWarnDuplicateObjectiveId = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bWarnDuplicateObjectiveId = { "bWarnDuplicateObjectiveId", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMObjectiveSettings), &Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bWarnDuplicateObjectiveId_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bWarnDuplicateObjectiveId_MetaData), NewProp_bWarnDuplicateObjectiveId_MetaData) };
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_DefaultObjectiveWidgetClass = { "DefaultObjectiveWidgetClass", nullptr, (EPropertyFlags)0x0014000000004001, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveSettings, DefaultObjectiveWidgetClass), Z_Construct_UClass_UJMObjectiveWidgetBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultObjectiveWidgetClass_MetaData), NewProp_DefaultObjectiveWidgetClass_MetaData) };
void Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bAutomaticallyCreateObjectiveUI_SetBit(void* Obj)
{
	((UJMObjectiveSettings*)Obj)->bAutomaticallyCreateObjectiveUI = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bAutomaticallyCreateObjectiveUI = { "bAutomaticallyCreateObjectiveUI", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMObjectiveSettings), &Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bAutomaticallyCreateObjectiveUI_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutomaticallyCreateObjectiveUI_MetaData), NewProp_bAutomaticallyCreateObjectiveUI_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_ObjectiveWidgetZOrder = { "ObjectiveWidgetZOrder", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveSettings, ObjectiveWidgetZOrder), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectiveWidgetZOrder_MetaData), NewProp_ObjectiveWidgetZOrder_MetaData) };
void Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bHideWidgetWhenNoActiveObjective_SetBit(void* Obj)
{
	((UJMObjectiveSettings*)Obj)->bHideWidgetWhenNoActiveObjective = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bHideWidgetWhenNoActiveObjective = { "bHideWidgetWhenNoActiveObjective", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMObjectiveSettings), &Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bHideWidgetWhenNoActiveObjective_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHideWidgetWhenNoActiveObjective_MetaData), NewProp_bHideWidgetWhenNoActiveObjective_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_CompletedDisplayDuration = { "CompletedDisplayDuration", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveSettings, CompletedDisplayDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CompletedDisplayDuration_MetaData), NewProp_CompletedDisplayDuration_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMObjectiveSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bEnableDebugLogging,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bLogObjectiveRegistration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bLogEventFiltering,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bLogProgressChanges,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bLogStateChanges,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bWarnDuplicateObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_DefaultObjectiveWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bAutomaticallyCreateObjectiveUI,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_ObjectiveWidgetZOrder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_bHideWidgetWhenNoActiveObjective,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveSettings_Statics::NewProp_CompletedDisplayDuration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveSettings_Statics::PropPointers) < 2048);
// ********** End Class UJMObjectiveSettings Property Definitions **********************************
UObject* (*const Z_Construct_UClass_UJMObjectiveSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_JMObjective,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMObjectiveSettings_Statics::ClassParams = {
	&UJMObjectiveSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMObjectiveSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMObjectiveSettings_Statics::Class_MetaDataParams)
};
void UJMObjectiveSettings::StaticRegisterNativesUJMObjectiveSettings()
{
}
UClass* Z_Construct_UClass_UJMObjectiveSettings()
{
	if (!Z_Registration_Info_UClass_UJMObjectiveSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMObjectiveSettings.OuterSingleton, Z_Construct_UClass_UJMObjectiveSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMObjectiveSettings.OuterSingleton;
}
UJMObjectiveSettings::UJMObjectiveSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMObjectiveSettings);
UJMObjectiveSettings::~UJMObjectiveSettings() {}
// ********** End Class UJMObjectiveSettings *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Settings_JMObjectiveSettings_h__Script_JMObjective_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMObjectiveSettings, UJMObjectiveSettings::StaticClass, TEXT("UJMObjectiveSettings"), &Z_Registration_Info_UClass_UJMObjectiveSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMObjectiveSettings), 2488762711U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Settings_JMObjectiveSettings_h__Script_JMObjective_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Settings_JMObjectiveSettings_h__Script_JMObjective_3747708672{
	TEXT("/Script/JMObjective"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Settings_JMObjectiveSettings_h__Script_JMObjective_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Settings_JMObjectiveSettings_h__Script_JMObjective_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
