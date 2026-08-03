// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Data/JMDoorConfigData.h"
#include "Door/JMDoorTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMDoorConfigData() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorConfigData();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorConfigData_NoRegister();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorBlockBehavior();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorOpenDirectionMode();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorOpenMode();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanelSelectionMode();
JMDOORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMDoorAccessRequirement();
UPackage* Z_Construct_UPackage__Script_JMDoorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMDoorConfigData ********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMDoorConfigData;
UClass* UJMDoorConfigData::GetPrivateStaticClass()
{
	using TClass = UJMDoorConfigData;
	if (!Z_Registration_Info_UClass_UJMDoorConfigData.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMDoorConfigData"),
			Z_Registration_Info_UClass_UJMDoorConfigData.InnerSingleton,
			StaticRegisterNativesUJMDoorConfigData,
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
	return Z_Registration_Info_UClass_UJMDoorConfigData.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMDoorConfigData_NoRegister()
{
	return UJMDoorConfigData::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMDoorConfigData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Data/JMDoorConfigData.h" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpenDuration_MetaData[] = {
		{ "Category", "Movement" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CloseDuration_MetaData[] = {
		{ "Category", "Movement" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FastSpeedMultiplier_MetaData[] = {
		{ "Category", "Movement" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QuietSpeedMultiplier_MetaData[] = {
		{ "Category", "Movement" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpenDirectionMode_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MovementCurve_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlideDoorOpenMode_MetaData[] = {
		{ "Category", "Slide Door|Opening Behavior" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlideDoorPanelSelectionMode_MetaData[] = {
		{ "Category", "Slide Door|Opening Behavior" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoClose_MetaData[] = {
		{ "Category", "Automatic" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AutoCloseDelay_MetaData[] = {
		{ "Category", "Automatic" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bAutoClose" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bInitiallyLocked_MetaData[] = {
		{ "Category", "Access" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AccessRequirement_MetaData[] = {
		{ "Category", "Access" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AcceptedAccessObjects_MetaData[] = {
		{ "Category", "Access" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Direct asset links accepted by this lock, such as Inventory Item Definitions.\n     * Use this for Blueprint-friendly key setup without Gameplay Tags.\n     */" },
#endif
		{ "DisplayName", "Accepted Access Items" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Direct asset links accepted by this lock, such as Inventory Item Definitions.\nUse this for Blueprint-friendly key setup without Gameplay Tags." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bBreakable_MetaData[] = {
		{ "Category", "Durability" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxDoorDurability_MetaData[] = {
		{ "Category", "Durability" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLockBreakable_MetaData[] = {
		{ "Category", "Durability" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxLockDurability_MetaData[] = {
		{ "Category", "Durability" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDetectObstructions_MetaData[] = {
		{ "Category", "Blocking" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlockBehavior_MetaData[] = {
		{ "Category", "Blocking" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPushCharacters_MetaData[] = {
		{ "Category", "Blocking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Moves characters out of the leaf's next pose before the door is advanced.\n     * This keeps the character capsule, rather than the camera, as the primary\n     * point of contact with an automatically closing door.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Moves characters out of the leaf's next pose before the door is advanced.\nThis keeps the character capsule, rather than the camera, as the primary\npoint of contact with an automatically closing door." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterPushPadding_MetaData[] = {
		{ "Category", "Blocking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Deprecated. Continuous pushes now use the exact swept leaf displacement without per-frame padding. */" },
#endif
		{ "DeprecatedProperty", "" },
		{ "DeprecationMessage", "Continuous character push no longer adds per-frame padding." },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Deprecated. Continuous pushes now use the exact swept leaf displacement without per-frame padding." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxCharacterPushDistancePerTick_MetaData[] = {
		{ "Category", "Blocking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Deprecated. Large leaf deltas are divided into swept substeps instead of clamped. */" },
#endif
		{ "DeprecatedProperty", "" },
		{ "DeprecationMessage", "Use Character Push Max Substep Distance instead." },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Deprecated. Large leaf deltas are divided into swept substeps instead of clamped." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterPushMaxSubstepDistance_MetaData[] = {
		{ "Category", "Blocking" },
		{ "ClampMin", "0.1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum translation covered by one predictive leaf sweep. The full frame delta is always applied. */" },
#endif
		{ "EditCondition", "bPushCharacters" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum translation covered by one predictive leaf sweep. The full frame delta is always applied." },
#endif
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterPushMaxSubstepAngle_MetaData[] = {
		{ "Category", "Blocking" },
		{ "ClampMax", "45.0" },
		{ "ClampMin", "0.1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum rotation covered by one predictive leaf sweep. */" },
#endif
		{ "EditCondition", "bPushCharacters" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum rotation covered by one predictive leaf sweep." },
#endif
		{ "Units", "deg" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterPushMaxSubsteps_MetaData[] = {
		{ "Category", "Blocking" },
		{ "ClampMax", "128" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Upper bound for predictive push work during an unusually long frame. */" },
#endif
		{ "EditCondition", "bPushCharacters" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Upper bound for predictive push work during an unusually long frame." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RetryDelay_MetaData[] = {
		{ "Category", "Blocking" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxRetryCount_MetaData[] = {
		{ "Category", "Blocking" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpenNoiseLoudness_MetaData[] = {
		{ "Category", "Noise" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpenNoiseRange_MetaData[] = {
		{ "Category", "Noise" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CloseNoiseLoudness_MetaData[] = {
		{ "Category", "Noise" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CloseNoiseRange_MetaData[] = {
		{ "Category", "Noise" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BreakNoiseLoudness_MetaData[] = {
		{ "Category", "Noise" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BreakNoiseRange_MetaData[] = {
		{ "Category", "Noise" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpenSound_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CloseSound_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LockedSound_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BreakSound_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/Data/JMDoorConfigData.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMDoorConfigData constinit property declarations ************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OpenDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CloseDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FastSpeedMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_QuietSpeedMultiplier;
	static const UECodeGen_Private::FBytePropertyParams NewProp_OpenDirectionMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OpenDirectionMode;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MovementCurve;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlideDoorOpenMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlideDoorOpenMode;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlideDoorPanelSelectionMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlideDoorPanelSelectionMode;
	static void NewProp_bAutoClose_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoClose;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AutoCloseDelay;
	static void NewProp_bInitiallyLocked_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInitiallyLocked;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AccessRequirement;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_AcceptedAccessObjects_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AcceptedAccessObjects;
	static void NewProp_bBreakable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bBreakable;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxDoorDurability;
	static void NewProp_bLockBreakable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLockBreakable;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxLockDurability;
	static void NewProp_bDetectObstructions_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDetectObstructions;
	static const UECodeGen_Private::FBytePropertyParams NewProp_BlockBehavior_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_BlockBehavior;
	static void NewProp_bPushCharacters_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPushCharacters;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CharacterPushPadding;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxCharacterPushDistancePerTick;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CharacterPushMaxSubstepDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CharacterPushMaxSubstepAngle;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CharacterPushMaxSubsteps;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RetryDelay;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxRetryCount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OpenNoiseLoudness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OpenNoiseRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CloseNoiseLoudness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CloseNoiseRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BreakNoiseLoudness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BreakNoiseRange;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_OpenSound;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_CloseSound;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_LockedSound;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_BreakSound;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMDoorConfigData constinit property declarations **************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMDoorConfigData>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMDoorConfigData_Statics

// ********** Begin Class UJMDoorConfigData Property Definitions ***********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_OpenDuration = { "OpenDuration", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, OpenDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpenDuration_MetaData), NewProp_OpenDuration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_CloseDuration = { "CloseDuration", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, CloseDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CloseDuration_MetaData), NewProp_CloseDuration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_FastSpeedMultiplier = { "FastSpeedMultiplier", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, FastSpeedMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FastSpeedMultiplier_MetaData), NewProp_FastSpeedMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_QuietSpeedMultiplier = { "QuietSpeedMultiplier", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, QuietSpeedMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QuietSpeedMultiplier_MetaData), NewProp_QuietSpeedMultiplier_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_OpenDirectionMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_OpenDirectionMode = { "OpenDirectionMode", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, OpenDirectionMode), Z_Construct_UEnum_JMDoorRuntime_EJMDoorOpenDirectionMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpenDirectionMode_MetaData), NewProp_OpenDirectionMode_MetaData) }; // 1573158568
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_MovementCurve = { "MovementCurve", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, MovementCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MovementCurve_MetaData), NewProp_MovementCurve_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_SlideDoorOpenMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_SlideDoorOpenMode = { "SlideDoorOpenMode", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, SlideDoorOpenMode), Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorOpenMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlideDoorOpenMode_MetaData), NewProp_SlideDoorOpenMode_MetaData) }; // 342004029
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_SlideDoorPanelSelectionMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_SlideDoorPanelSelectionMode = { "SlideDoorPanelSelectionMode", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, SlideDoorPanelSelectionMode), Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanelSelectionMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlideDoorPanelSelectionMode_MetaData), NewProp_SlideDoorPanelSelectionMode_MetaData) }; // 1922337433
void Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bAutoClose_SetBit(void* Obj)
{
	((UJMDoorConfigData*)Obj)->bAutoClose = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bAutoClose = { "bAutoClose", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMDoorConfigData), &Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bAutoClose_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoClose_MetaData), NewProp_bAutoClose_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_AutoCloseDelay = { "AutoCloseDelay", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, AutoCloseDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AutoCloseDelay_MetaData), NewProp_AutoCloseDelay_MetaData) };
void Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bInitiallyLocked_SetBit(void* Obj)
{
	((UJMDoorConfigData*)Obj)->bInitiallyLocked = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bInitiallyLocked = { "bInitiallyLocked", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMDoorConfigData), &Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bInitiallyLocked_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bInitiallyLocked_MetaData), NewProp_bInitiallyLocked_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_AccessRequirement = { "AccessRequirement", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, AccessRequirement), Z_Construct_UScriptStruct_FJMDoorAccessRequirement, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AccessRequirement_MetaData), NewProp_AccessRequirement_MetaData) }; // 3499309010
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_AcceptedAccessObjects_Inner = { "AcceptedAccessObjects", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_AcceptedAccessObjects = { "AcceptedAccessObjects", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, AcceptedAccessObjects), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AcceptedAccessObjects_MetaData), NewProp_AcceptedAccessObjects_MetaData) };
void Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bBreakable_SetBit(void* Obj)
{
	((UJMDoorConfigData*)Obj)->bBreakable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bBreakable = { "bBreakable", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMDoorConfigData), &Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bBreakable_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bBreakable_MetaData), NewProp_bBreakable_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_MaxDoorDurability = { "MaxDoorDurability", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, MaxDoorDurability), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxDoorDurability_MetaData), NewProp_MaxDoorDurability_MetaData) };
void Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bLockBreakable_SetBit(void* Obj)
{
	((UJMDoorConfigData*)Obj)->bLockBreakable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bLockBreakable = { "bLockBreakable", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMDoorConfigData), &Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bLockBreakable_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLockBreakable_MetaData), NewProp_bLockBreakable_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_MaxLockDurability = { "MaxLockDurability", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, MaxLockDurability), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxLockDurability_MetaData), NewProp_MaxLockDurability_MetaData) };
void Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bDetectObstructions_SetBit(void* Obj)
{
	((UJMDoorConfigData*)Obj)->bDetectObstructions = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bDetectObstructions = { "bDetectObstructions", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMDoorConfigData), &Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bDetectObstructions_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDetectObstructions_MetaData), NewProp_bDetectObstructions_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_BlockBehavior_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_BlockBehavior = { "BlockBehavior", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, BlockBehavior), Z_Construct_UEnum_JMDoorRuntime_EJMDoorBlockBehavior, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlockBehavior_MetaData), NewProp_BlockBehavior_MetaData) }; // 1963034699
void Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bPushCharacters_SetBit(void* Obj)
{
	((UJMDoorConfigData*)Obj)->bPushCharacters = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bPushCharacters = { "bPushCharacters", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMDoorConfigData), &Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bPushCharacters_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPushCharacters_MetaData), NewProp_bPushCharacters_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_CharacterPushPadding = { "CharacterPushPadding", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, CharacterPushPadding), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterPushPadding_MetaData), NewProp_CharacterPushPadding_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_MaxCharacterPushDistancePerTick = { "MaxCharacterPushDistancePerTick", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, MaxCharacterPushDistancePerTick), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxCharacterPushDistancePerTick_MetaData), NewProp_MaxCharacterPushDistancePerTick_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_CharacterPushMaxSubstepDistance = { "CharacterPushMaxSubstepDistance", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, CharacterPushMaxSubstepDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterPushMaxSubstepDistance_MetaData), NewProp_CharacterPushMaxSubstepDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_CharacterPushMaxSubstepAngle = { "CharacterPushMaxSubstepAngle", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, CharacterPushMaxSubstepAngle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterPushMaxSubstepAngle_MetaData), NewProp_CharacterPushMaxSubstepAngle_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_CharacterPushMaxSubsteps = { "CharacterPushMaxSubsteps", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, CharacterPushMaxSubsteps), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterPushMaxSubsteps_MetaData), NewProp_CharacterPushMaxSubsteps_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_RetryDelay = { "RetryDelay", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, RetryDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RetryDelay_MetaData), NewProp_RetryDelay_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_MaxRetryCount = { "MaxRetryCount", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, MaxRetryCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxRetryCount_MetaData), NewProp_MaxRetryCount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_OpenNoiseLoudness = { "OpenNoiseLoudness", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, OpenNoiseLoudness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpenNoiseLoudness_MetaData), NewProp_OpenNoiseLoudness_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_OpenNoiseRange = { "OpenNoiseRange", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, OpenNoiseRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpenNoiseRange_MetaData), NewProp_OpenNoiseRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_CloseNoiseLoudness = { "CloseNoiseLoudness", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, CloseNoiseLoudness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CloseNoiseLoudness_MetaData), NewProp_CloseNoiseLoudness_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_CloseNoiseRange = { "CloseNoiseRange", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, CloseNoiseRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CloseNoiseRange_MetaData), NewProp_CloseNoiseRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_BreakNoiseLoudness = { "BreakNoiseLoudness", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, BreakNoiseLoudness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BreakNoiseLoudness_MetaData), NewProp_BreakNoiseLoudness_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_BreakNoiseRange = { "BreakNoiseRange", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, BreakNoiseRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BreakNoiseRange_MetaData), NewProp_BreakNoiseRange_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_OpenSound = { "OpenSound", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, OpenSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpenSound_MetaData), NewProp_OpenSound_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_CloseSound = { "CloseSound", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, CloseSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CloseSound_MetaData), NewProp_CloseSound_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_LockedSound = { "LockedSound", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, LockedSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LockedSound_MetaData), NewProp_LockedSound_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_BreakSound = { "BreakSound", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorConfigData, BreakSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BreakSound_MetaData), NewProp_BreakSound_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMDoorConfigData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_OpenDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_CloseDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_FastSpeedMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_QuietSpeedMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_OpenDirectionMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_OpenDirectionMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_MovementCurve,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_SlideDoorOpenMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_SlideDoorOpenMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_SlideDoorPanelSelectionMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_SlideDoorPanelSelectionMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bAutoClose,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_AutoCloseDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bInitiallyLocked,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_AccessRequirement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_AcceptedAccessObjects_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_AcceptedAccessObjects,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bBreakable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_MaxDoorDurability,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bLockBreakable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_MaxLockDurability,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bDetectObstructions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_BlockBehavior_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_BlockBehavior,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_bPushCharacters,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_CharacterPushPadding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_MaxCharacterPushDistancePerTick,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_CharacterPushMaxSubstepDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_CharacterPushMaxSubstepAngle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_CharacterPushMaxSubsteps,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_RetryDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_MaxRetryCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_OpenNoiseLoudness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_OpenNoiseRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_CloseNoiseLoudness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_CloseNoiseRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_BreakNoiseLoudness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_BreakNoiseRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_OpenSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_CloseSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_LockedSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorConfigData_Statics::NewProp_BreakSound,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorConfigData_Statics::PropPointers) < 2048);
// ********** End Class UJMDoorConfigData Property Definitions *************************************
UObject* (*const Z_Construct_UClass_UJMDoorConfigData_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorConfigData_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMDoorConfigData_Statics::ClassParams = {
	&UJMDoorConfigData::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMDoorConfigData_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorConfigData_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorConfigData_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMDoorConfigData_Statics::Class_MetaDataParams)
};
void UJMDoorConfigData::StaticRegisterNativesUJMDoorConfigData()
{
}
UClass* Z_Construct_UClass_UJMDoorConfigData()
{
	if (!Z_Registration_Info_UClass_UJMDoorConfigData.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMDoorConfigData.OuterSingleton, Z_Construct_UClass_UJMDoorConfigData_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMDoorConfigData.OuterSingleton;
}
UJMDoorConfigData::UJMDoorConfigData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMDoorConfigData);
UJMDoorConfigData::~UJMDoorConfigData() {}
// ********** End Class UJMDoorConfigData **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Data_JMDoorConfigData_h__Script_JMDoorRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMDoorConfigData, UJMDoorConfigData::StaticClass, TEXT("UJMDoorConfigData"), &Z_Registration_Info_UClass_UJMDoorConfigData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMDoorConfigData), 4294027594U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Data_JMDoorConfigData_h__Script_JMDoorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Data_JMDoorConfigData_h__Script_JMDoorRuntime_2480053988{
	TEXT("/Script/JMDoorRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Data_JMDoorConfigData_h__Script_JMDoorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Data_JMDoorConfigData_h__Script_JMDoorRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
