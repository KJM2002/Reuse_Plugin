// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Settings/JMInteractionSettings.h"
#include "Types/JMInteractionTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMInteractionSettings() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractionPromptWidgetBase_NoRegister();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractionSettings();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractionSettings_NoRegister();
JMINTERACTION_API UEnum* Z_Construct_UEnum_JMInteraction_EJMInteractionDetectionMode();
JMINTERACTION_API UEnum* Z_Construct_UEnum_JMInteraction_EJMInteractionTraceMode();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionPromptStyle();
UPackage* Z_Construct_UPackage__Script_JMInteraction();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMInteractionSettings ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMInteractionSettings;
UClass* UJMInteractionSettings::GetPrivateStaticClass()
{
	using TClass = UJMInteractionSettings;
	if (!Z_Registration_Info_UClass_UJMInteractionSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMInteractionSettings"),
			Z_Registration_Info_UClass_UJMInteractionSettings.InnerSingleton,
			StaticRegisterNativesUJMInteractionSettings,
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
	return Z_Registration_Info_UClass_UJMInteractionSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMInteractionSettings_NoRegister()
{
	return UJMInteractionSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMInteractionSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "Interaction" },
		{ "IncludePath", "Settings/JMInteractionSettings.h" },
		{ "ModuleRelativePath", "Public/Settings/JMInteractionSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Configure the reusable JM interaction system." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultInteractionDistance_MetaData[] = {
		{ "Category", "Detection" },
		{ "ClampMin", "1.0" },
		{ "ModuleRelativePath", "Public/Settings/JMInteractionSettings.h" },
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultTraceRadius_MetaData[] = {
		{ "Category", "Detection" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/JMInteractionSettings.h" },
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultTraceChannel_MetaData[] = {
		{ "Category", "Detection" },
		{ "ModuleRelativePath", "Public/Settings/JMInteractionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultDetectionMode_MetaData[] = {
		{ "Category", "Detection" },
		{ "ModuleRelativePath", "Public/Settings/JMInteractionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultTraceMode_MetaData[] = {
		{ "Category", "Detection" },
		{ "ModuleRelativePath", "Public/Settings/JMInteractionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultTraceInterval_MetaData[] = {
		{ "Category", "Detection" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Settings/JMInteractionSettings.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDefaultDebugTrace_MetaData[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/Settings/JMInteractionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultPromptWidgetClass_MetaData[] = {
		{ "Category", "Prompt UI" },
		{ "ModuleRelativePath", "Public/Settings/JMInteractionSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultPromptStyle_MetaData[] = {
		{ "Category", "Prompt UI" },
		{ "ModuleRelativePath", "Public/Settings/JMInteractionSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMInteractionSettings constinit property declarations *******************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultInteractionDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultTraceRadius;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DefaultTraceChannel;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DefaultDetectionMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DefaultDetectionMode;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DefaultTraceMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DefaultTraceMode;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultTraceInterval;
	static void NewProp_bDefaultDebugTrace_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDefaultDebugTrace;
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_DefaultPromptWidgetClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultPromptStyle;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMInteractionSettings constinit property declarations *********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMInteractionSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMInteractionSettings_Statics

// ********** Begin Class UJMInteractionSettings Property Definitions ******************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_DefaultInteractionDistance = { "DefaultInteractionDistance", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionSettings, DefaultInteractionDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultInteractionDistance_MetaData), NewProp_DefaultInteractionDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_DefaultTraceRadius = { "DefaultTraceRadius", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionSettings, DefaultTraceRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultTraceRadius_MetaData), NewProp_DefaultTraceRadius_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_DefaultTraceChannel = { "DefaultTraceChannel", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionSettings, DefaultTraceChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultTraceChannel_MetaData), NewProp_DefaultTraceChannel_MetaData) }; // 838391399
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_DefaultDetectionMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_DefaultDetectionMode = { "DefaultDetectionMode", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionSettings, DefaultDetectionMode), Z_Construct_UEnum_JMInteraction_EJMInteractionDetectionMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultDetectionMode_MetaData), NewProp_DefaultDetectionMode_MetaData) }; // 1585170584
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_DefaultTraceMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_DefaultTraceMode = { "DefaultTraceMode", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionSettings, DefaultTraceMode), Z_Construct_UEnum_JMInteraction_EJMInteractionTraceMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultTraceMode_MetaData), NewProp_DefaultTraceMode_MetaData) }; // 2566927994
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_DefaultTraceInterval = { "DefaultTraceInterval", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionSettings, DefaultTraceInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultTraceInterval_MetaData), NewProp_DefaultTraceInterval_MetaData) };
void Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_bDefaultDebugTrace_SetBit(void* Obj)
{
	((UJMInteractionSettings*)Obj)->bDefaultDebugTrace = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_bDefaultDebugTrace = { "bDefaultDebugTrace", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMInteractionSettings), &Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_bDefaultDebugTrace_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDefaultDebugTrace_MetaData), NewProp_bDefaultDebugTrace_MetaData) };
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_DefaultPromptWidgetClass = { "DefaultPromptWidgetClass", nullptr, (EPropertyFlags)0x0014000000004001, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionSettings, DefaultPromptWidgetClass), Z_Construct_UClass_UJMInteractionPromptWidgetBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultPromptWidgetClass_MetaData), NewProp_DefaultPromptWidgetClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_DefaultPromptStyle = { "DefaultPromptStyle", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionSettings, DefaultPromptStyle), Z_Construct_UScriptStruct_FJMInteractionPromptStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultPromptStyle_MetaData), NewProp_DefaultPromptStyle_MetaData) }; // 2420317743
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMInteractionSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_DefaultInteractionDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_DefaultTraceRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_DefaultTraceChannel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_DefaultDetectionMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_DefaultDetectionMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_DefaultTraceMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_DefaultTraceMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_DefaultTraceInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_bDefaultDebugTrace,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_DefaultPromptWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionSettings_Statics::NewProp_DefaultPromptStyle,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractionSettings_Statics::PropPointers) < 2048);
// ********** End Class UJMInteractionSettings Property Definitions ********************************
UObject* (*const Z_Construct_UClass_UJMInteractionSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_JMInteraction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractionSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMInteractionSettings_Statics::ClassParams = {
	&UJMInteractionSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMInteractionSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractionSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractionSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMInteractionSettings_Statics::Class_MetaDataParams)
};
void UJMInteractionSettings::StaticRegisterNativesUJMInteractionSettings()
{
}
UClass* Z_Construct_UClass_UJMInteractionSettings()
{
	if (!Z_Registration_Info_UClass_UJMInteractionSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMInteractionSettings.OuterSingleton, Z_Construct_UClass_UJMInteractionSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMInteractionSettings.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMInteractionSettings);
UJMInteractionSettings::~UJMInteractionSettings() {}
// ********** End Class UJMInteractionSettings *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Settings_JMInteractionSettings_h__Script_JMInteraction_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMInteractionSettings, UJMInteractionSettings::StaticClass, TEXT("UJMInteractionSettings"), &Z_Registration_Info_UClass_UJMInteractionSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMInteractionSettings), 3998622616U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Settings_JMInteractionSettings_h__Script_JMInteraction_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Settings_JMInteractionSettings_h__Script_JMInteraction_844926091{
	TEXT("/Script/JMInteraction"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Settings_JMInteractionSettings_h__Script_JMInteraction_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Settings_JMInteractionSettings_h__Script_JMInteraction_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
