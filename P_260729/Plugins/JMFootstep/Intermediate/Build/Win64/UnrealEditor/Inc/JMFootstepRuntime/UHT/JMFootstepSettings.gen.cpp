// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Settings/JMFootstepSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMFootstepSettings() {}

// ********** Begin Cross Module References ********************************************************
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
JMFOOTSTEPRUNTIME_API UClass* Z_Construct_UClass_UJMFootstepSet_NoRegister();
JMFOOTSTEPRUNTIME_API UClass* Z_Construct_UClass_UJMFootstepSettings();
JMFOOTSTEPRUNTIME_API UClass* Z_Construct_UClass_UJMFootstepSettings_NoRegister();
JMFOOTSTEPRUNTIME_API UEnum* Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepTriggerMode();
UPackage* Z_Construct_UPackage__Script_JMFootstepRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMFootstepSettings ******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMFootstepSettings;
UClass* UJMFootstepSettings::GetPrivateStaticClass()
{
	using TClass = UJMFootstepSettings;
	if (!Z_Registration_Info_UClass_UJMFootstepSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMFootstepSettings"),
			Z_Registration_Info_UClass_UJMFootstepSettings.InnerSingleton,
			StaticRegisterNativesUJMFootstepSettings,
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
	return Z_Registration_Info_UClass_UJMFootstepSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMFootstepSettings_NoRegister()
{
	return UJMFootstepSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMFootstepSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "Footstep" },
		{ "IncludePath", "Settings/JMFootstepSettings.h" },
		{ "ModuleRelativePath", "Public/Settings/JMFootstepSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Configure the reusable JM distance-driven footstep system." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultFootstepSet_MetaData[] = {
		{ "Category", "Data" },
		{ "DisplayName", "Default Footstep Set" },
		{ "ModuleRelativePath", "Public/Settings/JMFootstepSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TriggerMode_MetaData[] = {
		{ "Category", "Trigger" },
		{ "ModuleRelativePath", "Public/Settings/JMFootstepSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumMovementSpeed_MetaData[] = {
		{ "Category", "Movement" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/JMFootstepSettings.h" },
		{ "Units", "cm/s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RunSpeedThreshold_MetaData[] = {
		{ "Category", "Movement" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/JMFootstepSettings.h" },
		{ "Units", "cm/s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalkStepDistance_MetaData[] = {
		{ "Category", "Movement" },
		{ "ClampMin", "1.0" },
		{ "ModuleRelativePath", "Public/Settings/JMFootstepSettings.h" },
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RunStepDistance_MetaData[] = {
		{ "Category", "Movement" },
		{ "ClampMin", "1.0" },
		{ "ModuleRelativePath", "Public/Settings/JMFootstepSettings.h" },
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CrouchStepDistance_MetaData[] = {
		{ "Category", "Movement" },
		{ "ClampMin", "1.0" },
		{ "ModuleRelativePath", "Public/Settings/JMFootstepSettings.h" },
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TeleportDistanceThreshold_MetaData[] = {
		{ "Category", "Movement" },
		{ "ClampMin", "1.0" },
		{ "ModuleRelativePath", "Public/Settings/JMFootstepSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A single frame delta at or above this value is treated as teleportation." },
#endif
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxStepsPerFrame_MetaData[] = {
		{ "Category", "Movement" },
		{ "ClampMax", "8" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/Settings/JMFootstepSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TraceDistance_MetaData[] = {
		{ "Category", "Trace" },
		{ "ClampMin", "1.0" },
		{ "ModuleRelativePath", "Public/Settings/JMFootstepSettings.h" },
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TraceStartOffset_MetaData[] = {
		{ "Category", "Trace" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/JMFootstepSettings.h" },
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TraceChannel_MetaData[] = {
		{ "Category", "Trace" },
		{ "ModuleRelativePath", "Public/Settings/JMFootstepSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultVolumeMultiplier_MetaData[] = {
		{ "Category", "Audio" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/JMFootstepSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultPitchMultiplier_MetaData[] = {
		{ "Category", "Audio" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Settings/JMFootstepSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalkVolumeMultiplier_MetaData[] = {
		{ "Category", "Audio" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/JMFootstepSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RunVolumeMultiplier_MetaData[] = {
		{ "Category", "Audio" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/JMFootstepSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CrouchVolumeMultiplier_MetaData[] = {
		{ "Category", "Audio" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/JMFootstepSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDebug_MetaData[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/Settings/JMFootstepSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMFootstepSettings constinit property declarations **********************
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_DefaultFootstepSet;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TriggerMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TriggerMode;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinimumMovementSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RunSpeedThreshold;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WalkStepDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RunStepDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CrouchStepDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TeleportDistanceThreshold;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxStepsPerFrame;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TraceDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TraceStartOffset;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TraceChannel;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultVolumeMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultPitchMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WalkVolumeMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RunVolumeMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CrouchVolumeMultiplier;
	static void NewProp_bEnableDebug_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDebug;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMFootstepSettings constinit property declarations ************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMFootstepSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMFootstepSettings_Statics

// ********** Begin Class UJMFootstepSettings Property Definitions *********************************
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_DefaultFootstepSet = { "DefaultFootstepSet", nullptr, (EPropertyFlags)0x0014000000004001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSettings, DefaultFootstepSet), Z_Construct_UClass_UJMFootstepSet_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultFootstepSet_MetaData), NewProp_DefaultFootstepSet_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_TriggerMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_TriggerMode = { "TriggerMode", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSettings, TriggerMode), Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepTriggerMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TriggerMode_MetaData), NewProp_TriggerMode_MetaData) }; // 236246170
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_MinimumMovementSpeed = { "MinimumMovementSpeed", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSettings, MinimumMovementSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumMovementSpeed_MetaData), NewProp_MinimumMovementSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_RunSpeedThreshold = { "RunSpeedThreshold", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSettings, RunSpeedThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RunSpeedThreshold_MetaData), NewProp_RunSpeedThreshold_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_WalkStepDistance = { "WalkStepDistance", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSettings, WalkStepDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalkStepDistance_MetaData), NewProp_WalkStepDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_RunStepDistance = { "RunStepDistance", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSettings, RunStepDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RunStepDistance_MetaData), NewProp_RunStepDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_CrouchStepDistance = { "CrouchStepDistance", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSettings, CrouchStepDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CrouchStepDistance_MetaData), NewProp_CrouchStepDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_TeleportDistanceThreshold = { "TeleportDistanceThreshold", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSettings, TeleportDistanceThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TeleportDistanceThreshold_MetaData), NewProp_TeleportDistanceThreshold_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_MaxStepsPerFrame = { "MaxStepsPerFrame", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSettings, MaxStepsPerFrame), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxStepsPerFrame_MetaData), NewProp_MaxStepsPerFrame_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_TraceDistance = { "TraceDistance", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSettings, TraceDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TraceDistance_MetaData), NewProp_TraceDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_TraceStartOffset = { "TraceStartOffset", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSettings, TraceStartOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TraceStartOffset_MetaData), NewProp_TraceStartOffset_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_TraceChannel = { "TraceChannel", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSettings, TraceChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TraceChannel_MetaData), NewProp_TraceChannel_MetaData) }; // 838391399
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_DefaultVolumeMultiplier = { "DefaultVolumeMultiplier", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSettings, DefaultVolumeMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultVolumeMultiplier_MetaData), NewProp_DefaultVolumeMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_DefaultPitchMultiplier = { "DefaultPitchMultiplier", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSettings, DefaultPitchMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultPitchMultiplier_MetaData), NewProp_DefaultPitchMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_WalkVolumeMultiplier = { "WalkVolumeMultiplier", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSettings, WalkVolumeMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalkVolumeMultiplier_MetaData), NewProp_WalkVolumeMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_RunVolumeMultiplier = { "RunVolumeMultiplier", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSettings, RunVolumeMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RunVolumeMultiplier_MetaData), NewProp_RunVolumeMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_CrouchVolumeMultiplier = { "CrouchVolumeMultiplier", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSettings, CrouchVolumeMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CrouchVolumeMultiplier_MetaData), NewProp_CrouchVolumeMultiplier_MetaData) };
void Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_bEnableDebug_SetBit(void* Obj)
{
	((UJMFootstepSettings*)Obj)->bEnableDebug = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_bEnableDebug = { "bEnableDebug", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMFootstepSettings), &Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_bEnableDebug_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDebug_MetaData), NewProp_bEnableDebug_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMFootstepSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_DefaultFootstepSet,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_TriggerMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_TriggerMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_MinimumMovementSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_RunSpeedThreshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_WalkStepDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_RunStepDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_CrouchStepDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_TeleportDistanceThreshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_MaxStepsPerFrame,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_TraceDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_TraceStartOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_TraceChannel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_DefaultVolumeMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_DefaultPitchMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_WalkVolumeMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_RunVolumeMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_CrouchVolumeMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSettings_Statics::NewProp_bEnableDebug,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMFootstepSettings_Statics::PropPointers) < 2048);
// ********** End Class UJMFootstepSettings Property Definitions ***********************************
UObject* (*const Z_Construct_UClass_UJMFootstepSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_JMFootstepRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMFootstepSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMFootstepSettings_Statics::ClassParams = {
	&UJMFootstepSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMFootstepSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMFootstepSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMFootstepSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMFootstepSettings_Statics::Class_MetaDataParams)
};
void UJMFootstepSettings::StaticRegisterNativesUJMFootstepSettings()
{
}
UClass* Z_Construct_UClass_UJMFootstepSettings()
{
	if (!Z_Registration_Info_UClass_UJMFootstepSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMFootstepSettings.OuterSingleton, Z_Construct_UClass_UJMFootstepSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMFootstepSettings.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMFootstepSettings);
UJMFootstepSettings::~UJMFootstepSettings() {}
// ********** End Class UJMFootstepSettings ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Settings_JMFootstepSettings_h__Script_JMFootstepRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMFootstepSettings, UJMFootstepSettings::StaticClass, TEXT("UJMFootstepSettings"), &Z_Registration_Info_UClass_UJMFootstepSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMFootstepSettings), 409611154U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Settings_JMFootstepSettings_h__Script_JMFootstepRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Settings_JMFootstepSettings_h__Script_JMFootstepRuntime_2772750290{
	TEXT("/Script/JMFootstepRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Settings_JMFootstepSettings_h__Script_JMFootstepRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Settings_JMFootstepSettings_h__Script_JMFootstepRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
