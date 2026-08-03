// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JMThrowableSettings.h"
#include "InputCoreTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMThrowableSettings() {}

// ********** Begin Cross Module References ********************************************************
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey();
JMTHROWABLE_API UClass* Z_Construct_UClass_UJMThrowableSettings();
JMTHROWABLE_API UClass* Z_Construct_UClass_UJMThrowableSettings_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMThrowable();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMThrowableSettings *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMThrowableSettings;
UClass* UJMThrowableSettings::GetPrivateStaticClass()
{
	using TClass = UJMThrowableSettings;
	if (!Z_Registration_Info_UClass_UJMThrowableSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMThrowableSettings"),
			Z_Registration_Info_UClass_UJMThrowableSettings.InnerSingleton,
			StaticRegisterNativesUJMThrowableSettings,
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
	return Z_Registration_Info_UClass_UJMThrowableSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMThrowableSettings_NoRegister()
{
	return UJMThrowableSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMThrowableSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "Throwable" },
		{ "IncludePath", "JMThrowableSettings.h" },
		{ "ModuleRelativePath", "Public/JMThrowableSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultAimKey_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/JMThrowableSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultThrowKey_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/JMThrowableSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultCancelKey_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/JMThrowableSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputPriority_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/JMThrowableSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewUpdateHz_MetaData[] = {
		{ "Category", "Aim" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/JMThrowableSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRestrictMovementWhileAiming_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Public/JMThrowableSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCancelSprintOnAim_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Public/JMThrowableSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimMovementSpeedMultiplier_MetaData[] = {
		{ "Category", "Movement" },
		{ "ClampMax", "1" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDebugThrowableTrajectory_MetaData[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/JMThrowableSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMThrowableSettings constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultAimKey;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultThrowKey;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultCancelKey;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InputPriority;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PreviewUpdateHz;
	static void NewProp_bRestrictMovementWhileAiming_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRestrictMovementWhileAiming;
	static void NewProp_bCancelSprintOnAim_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCancelSprintOnAim;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AimMovementSpeedMultiplier;
	static void NewProp_bDebugThrowableTrajectory_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDebugThrowableTrajectory;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMThrowableSettings constinit property declarations ***********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMThrowableSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMThrowableSettings_Statics

// ********** Begin Class UJMThrowableSettings Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_DefaultAimKey = { "DefaultAimKey", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableSettings, DefaultAimKey), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultAimKey_MetaData), NewProp_DefaultAimKey_MetaData) }; // 2693575693
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_DefaultThrowKey = { "DefaultThrowKey", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableSettings, DefaultThrowKey), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultThrowKey_MetaData), NewProp_DefaultThrowKey_MetaData) }; // 2693575693
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_DefaultCancelKey = { "DefaultCancelKey", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableSettings, DefaultCancelKey), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultCancelKey_MetaData), NewProp_DefaultCancelKey_MetaData) }; // 2693575693
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_InputPriority = { "InputPriority", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableSettings, InputPriority), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputPriority_MetaData), NewProp_InputPriority_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_PreviewUpdateHz = { "PreviewUpdateHz", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableSettings, PreviewUpdateHz), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewUpdateHz_MetaData), NewProp_PreviewUpdateHz_MetaData) };
void Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_bRestrictMovementWhileAiming_SetBit(void* Obj)
{
	((UJMThrowableSettings*)Obj)->bRestrictMovementWhileAiming = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_bRestrictMovementWhileAiming = { "bRestrictMovementWhileAiming", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMThrowableSettings), &Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_bRestrictMovementWhileAiming_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRestrictMovementWhileAiming_MetaData), NewProp_bRestrictMovementWhileAiming_MetaData) };
void Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_bCancelSprintOnAim_SetBit(void* Obj)
{
	((UJMThrowableSettings*)Obj)->bCancelSprintOnAim = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_bCancelSprintOnAim = { "bCancelSprintOnAim", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMThrowableSettings), &Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_bCancelSprintOnAim_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCancelSprintOnAim_MetaData), NewProp_bCancelSprintOnAim_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_AimMovementSpeedMultiplier = { "AimMovementSpeedMultiplier", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableSettings, AimMovementSpeedMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimMovementSpeedMultiplier_MetaData), NewProp_AimMovementSpeedMultiplier_MetaData) };
void Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_bDebugThrowableTrajectory_SetBit(void* Obj)
{
	((UJMThrowableSettings*)Obj)->bDebugThrowableTrajectory = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_bDebugThrowableTrajectory = { "bDebugThrowableTrajectory", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMThrowableSettings), &Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_bDebugThrowableTrajectory_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDebugThrowableTrajectory_MetaData), NewProp_bDebugThrowableTrajectory_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMThrowableSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_DefaultAimKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_DefaultThrowKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_DefaultCancelKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_InputPriority,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_PreviewUpdateHz,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_bRestrictMovementWhileAiming,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_bCancelSprintOnAim,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_AimMovementSpeedMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableSettings_Statics::NewProp_bDebugThrowableTrajectory,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableSettings_Statics::PropPointers) < 2048);
// ********** End Class UJMThrowableSettings Property Definitions **********************************
UObject* (*const Z_Construct_UClass_UJMThrowableSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_JMThrowable,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMThrowableSettings_Statics::ClassParams = {
	&UJMThrowableSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMThrowableSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMThrowableSettings_Statics::Class_MetaDataParams)
};
void UJMThrowableSettings::StaticRegisterNativesUJMThrowableSettings()
{
}
UClass* Z_Construct_UClass_UJMThrowableSettings()
{
	if (!Z_Registration_Info_UClass_UJMThrowableSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMThrowableSettings.OuterSingleton, Z_Construct_UClass_UJMThrowableSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMThrowableSettings.OuterSingleton;
}
UJMThrowableSettings::UJMThrowableSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMThrowableSettings);
UJMThrowableSettings::~UJMThrowableSettings() {}
// ********** End Class UJMThrowableSettings *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableSettings_h__Script_JMThrowable_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMThrowableSettings, UJMThrowableSettings::StaticClass, TEXT("UJMThrowableSettings"), &Z_Registration_Info_UClass_UJMThrowableSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMThrowableSettings), 828447923U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableSettings_h__Script_JMThrowable_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableSettings_h__Script_JMThrowable_1896094975{
	TEXT("/Script/JMThrowable"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableSettings_h__Script_JMThrowable_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableSettings_h__Script_JMThrowable_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
