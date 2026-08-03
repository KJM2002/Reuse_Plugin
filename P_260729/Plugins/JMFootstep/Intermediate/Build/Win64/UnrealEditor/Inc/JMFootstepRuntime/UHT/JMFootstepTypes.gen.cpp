// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Types/JMFootstepTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMFootstepTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
JMFOOTSTEPRUNTIME_API UEnum* Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFailureReason();
JMFOOTSTEPRUNTIME_API UEnum* Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFoot();
JMFOOTSTEPRUNTIME_API UEnum* Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepLocomotionState();
JMFOOTSTEPRUNTIME_API UEnum* Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepTriggerMode();
JMFOOTSTEPRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMFootstepContext();
JMFOOTSTEPRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMFootstepResult();
PHYSICSCORE_API UClass* Z_Construct_UClass_UPhysicalMaterial_NoRegister();
PHYSICSCORE_API UEnum* Z_Construct_UEnum_PhysicsCore_EPhysicalSurface();
UPackage* Z_Construct_UPackage__Script_JMFootstepRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EJMFootstepLocomotionState ************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMFootstepLocomotionState;
static UEnum* EJMFootstepLocomotionState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMFootstepLocomotionState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMFootstepLocomotionState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepLocomotionState, (UObject*)Z_Construct_UPackage__Script_JMFootstepRuntime(), TEXT("EJMFootstepLocomotionState"));
	}
	return Z_Registration_Info_UEnum_EJMFootstepLocomotionState.OuterSingleton;
}
template<> JMFOOTSTEPRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMFootstepLocomotionState>()
{
	return EJMFootstepLocomotionState_StaticEnum();
}
struct Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepLocomotionState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CrouchWalk.Name", "EJMFootstepLocomotionState::CrouchWalk" },
		{ "Idle.Name", "EJMFootstepLocomotionState::Idle" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
		{ "Run.Name", "EJMFootstepLocomotionState::Run" },
		{ "Walk.Name", "EJMFootstepLocomotionState::Walk" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMFootstepLocomotionState::Idle", (int64)EJMFootstepLocomotionState::Idle },
		{ "EJMFootstepLocomotionState::Walk", (int64)EJMFootstepLocomotionState::Walk },
		{ "EJMFootstepLocomotionState::Run", (int64)EJMFootstepLocomotionState::Run },
		{ "EJMFootstepLocomotionState::CrouchWalk", (int64)EJMFootstepLocomotionState::CrouchWalk },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepLocomotionState_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepLocomotionState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMFootstepRuntime,
	nullptr,
	"EJMFootstepLocomotionState",
	"EJMFootstepLocomotionState",
	Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepLocomotionState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepLocomotionState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepLocomotionState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepLocomotionState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepLocomotionState()
{
	if (!Z_Registration_Info_UEnum_EJMFootstepLocomotionState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMFootstepLocomotionState.InnerSingleton, Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepLocomotionState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMFootstepLocomotionState.InnerSingleton;
}
// ********** End Enum EJMFootstepLocomotionState **************************************************

// ********** Begin Enum EJMFootstepFoot ***********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMFootstepFoot;
static UEnum* EJMFootstepFoot_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMFootstepFoot.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMFootstepFoot.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFoot, (UObject*)Z_Construct_UPackage__Script_JMFootstepRuntime(), TEXT("EJMFootstepFoot"));
	}
	return Z_Registration_Info_UEnum_EJMFootstepFoot.OuterSingleton;
}
template<> JMFOOTSTEPRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMFootstepFoot>()
{
	return EJMFootstepFoot_StaticEnum();
}
struct Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFoot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Left.Name", "EJMFootstepFoot::Left" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
		{ "Right.Name", "EJMFootstepFoot::Right" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMFootstepFoot::Left", (int64)EJMFootstepFoot::Left },
		{ "EJMFootstepFoot::Right", (int64)EJMFootstepFoot::Right },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFoot_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFoot_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMFootstepRuntime,
	nullptr,
	"EJMFootstepFoot",
	"EJMFootstepFoot",
	Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFoot_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFoot_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFoot_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFoot_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFoot()
{
	if (!Z_Registration_Info_UEnum_EJMFootstepFoot.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMFootstepFoot.InnerSingleton, Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFoot_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMFootstepFoot.InnerSingleton;
}
// ********** End Enum EJMFootstepFoot *************************************************************

// ********** Begin Enum EJMFootstepTriggerMode ****************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMFootstepTriggerMode;
static UEnum* EJMFootstepTriggerMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMFootstepTriggerMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMFootstepTriggerMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepTriggerMode, (UObject*)Z_Construct_UPackage__Script_JMFootstepRuntime(), TEXT("EJMFootstepTriggerMode"));
	}
	return Z_Registration_Info_UEnum_EJMFootstepTriggerMode.OuterSingleton;
}
template<> JMFOOTSTEPRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMFootstepTriggerMode>()
{
	return EJMFootstepTriggerMode_StaticEnum();
}
struct Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepTriggerMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DistanceBased.DisplayName", "Distance Based" },
		{ "DistanceBased.Name", "EJMFootstepTriggerMode::DistanceBased" },
		{ "ManualOnly.DisplayName", "Manual Only" },
		{ "ManualOnly.Name", "EJMFootstepTriggerMode::ManualOnly" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMFootstepTriggerMode::DistanceBased", (int64)EJMFootstepTriggerMode::DistanceBased },
		{ "EJMFootstepTriggerMode::ManualOnly", (int64)EJMFootstepTriggerMode::ManualOnly },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepTriggerMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepTriggerMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMFootstepRuntime,
	nullptr,
	"EJMFootstepTriggerMode",
	"EJMFootstepTriggerMode",
	Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepTriggerMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepTriggerMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepTriggerMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepTriggerMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepTriggerMode()
{
	if (!Z_Registration_Info_UEnum_EJMFootstepTriggerMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMFootstepTriggerMode.InnerSingleton, Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepTriggerMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMFootstepTriggerMode.InnerSingleton;
}
// ********** End Enum EJMFootstepTriggerMode ******************************************************

// ********** Begin Enum EJMFootstepFailureReason **************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMFootstepFailureReason;
static UEnum* EJMFootstepFailureReason_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMFootstepFailureReason.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMFootstepFailureReason.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFailureReason, (UObject*)Z_Construct_UPackage__Script_JMFootstepRuntime(), TEXT("EJMFootstepFailureReason"));
	}
	return Z_Registration_Info_UEnum_EJMFootstepFailureReason.OuterSingleton;
}
template<> JMFOOTSTEPRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMFootstepFailureReason>()
{
	return EJMFootstepFailureReason_StaticEnum();
}
struct Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFailureReason_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "InvalidOwner.Name", "EJMFootstepFailureReason::InvalidOwner" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
		{ "None.Name", "EJMFootstepFailureReason::None" },
		{ "NotGrounded.Name", "EJMFootstepFailureReason::NotGrounded" },
		{ "NotMoving.Name", "EJMFootstepFailureReason::NotMoving" },
		{ "PhysicalMaterialMissing.Name", "EJMFootstepFailureReason::PhysicalMaterialMissing" },
		{ "SettingsMissing.Name", "EJMFootstepFailureReason::SettingsMissing" },
		{ "SoundMissing.Name", "EJMFootstepFailureReason::SoundMissing" },
		{ "SurfaceProfileMissing.Name", "EJMFootstepFailureReason::SurfaceProfileMissing" },
		{ "TraceFailed.Name", "EJMFootstepFailureReason::TraceFailed" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMFootstepFailureReason::None", (int64)EJMFootstepFailureReason::None },
		{ "EJMFootstepFailureReason::InvalidOwner", (int64)EJMFootstepFailureReason::InvalidOwner },
		{ "EJMFootstepFailureReason::NotGrounded", (int64)EJMFootstepFailureReason::NotGrounded },
		{ "EJMFootstepFailureReason::NotMoving", (int64)EJMFootstepFailureReason::NotMoving },
		{ "EJMFootstepFailureReason::TraceFailed", (int64)EJMFootstepFailureReason::TraceFailed },
		{ "EJMFootstepFailureReason::PhysicalMaterialMissing", (int64)EJMFootstepFailureReason::PhysicalMaterialMissing },
		{ "EJMFootstepFailureReason::SurfaceProfileMissing", (int64)EJMFootstepFailureReason::SurfaceProfileMissing },
		{ "EJMFootstepFailureReason::SoundMissing", (int64)EJMFootstepFailureReason::SoundMissing },
		{ "EJMFootstepFailureReason::SettingsMissing", (int64)EJMFootstepFailureReason::SettingsMissing },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFailureReason_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFailureReason_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMFootstepRuntime,
	nullptr,
	"EJMFootstepFailureReason",
	"EJMFootstepFailureReason",
	Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFailureReason_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFailureReason_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFailureReason_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFailureReason_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFailureReason()
{
	if (!Z_Registration_Info_UEnum_EJMFootstepFailureReason.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMFootstepFailureReason.InnerSingleton, Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFailureReason_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMFootstepFailureReason.InnerSingleton;
}
// ********** End Enum EJMFootstepFailureReason ****************************************************

// ********** Begin ScriptStruct FJMFootstepContext ************************************************
struct Z_Construct_UScriptStruct_FJMFootstepContext_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMFootstepContext); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMFootstepContext); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Instigator_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideTraceOrigin_MetaData[] = {
		{ "Category", "Footstep|Trace" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TraceOrigin_MetaData[] = {
		{ "Category", "Footstep|Trace" },
		{ "EditCondition", "bOverrideTraceOrigin" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideLocomotionState_MetaData[] = {
		{ "Category", "Footstep|State" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LocomotionState_MetaData[] = {
		{ "Category", "Footstep|State" },
		{ "EditCondition", "bOverrideLocomotionState" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideLogicalFoot_MetaData[] = {
		{ "Category", "Footstep|State" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LogicalFoot_MetaData[] = {
		{ "Category", "Footstep|State" },
		{ "EditCondition", "bOverrideLogicalFoot" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VolumeMultiplier_MetaData[] = {
		{ "Category", "Footstep|Audio" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PitchMultiplier_MetaData[] = {
		{ "Category", "Footstep|Audio" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OptionalContextTag_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMFootstepContext constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Instigator;
	static void NewProp_bOverrideTraceOrigin_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideTraceOrigin;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TraceOrigin;
	static void NewProp_bOverrideLocomotionState_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideLocomotionState;
	static const UECodeGen_Private::FBytePropertyParams NewProp_LocomotionState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_LocomotionState;
	static void NewProp_bOverrideLogicalFoot_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideLogicalFoot;
	static const UECodeGen_Private::FBytePropertyParams NewProp_LogicalFoot_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_LogicalFoot;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VolumeMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PitchMultiplier;
	static const UECodeGen_Private::FNamePropertyParams NewProp_OptionalContextTag;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMFootstepContext constinit property declarations ******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMFootstepContext>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMFootstepContext_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMFootstepContext;
class UScriptStruct* FJMFootstepContext::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMFootstepContext.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMFootstepContext.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMFootstepContext, (UObject*)Z_Construct_UPackage__Script_JMFootstepRuntime(), TEXT("JMFootstepContext"));
	}
	return Z_Registration_Info_UScriptStruct_FJMFootstepContext.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMFootstepContext Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepContext, Instigator), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Instigator_MetaData), NewProp_Instigator_MetaData) };
void Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_bOverrideTraceOrigin_SetBit(void* Obj)
{
	((FJMFootstepContext*)Obj)->bOverrideTraceOrigin = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_bOverrideTraceOrigin = { "bOverrideTraceOrigin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMFootstepContext), &Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_bOverrideTraceOrigin_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideTraceOrigin_MetaData), NewProp_bOverrideTraceOrigin_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_TraceOrigin = { "TraceOrigin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepContext, TraceOrigin), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TraceOrigin_MetaData), NewProp_TraceOrigin_MetaData) };
void Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_bOverrideLocomotionState_SetBit(void* Obj)
{
	((FJMFootstepContext*)Obj)->bOverrideLocomotionState = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_bOverrideLocomotionState = { "bOverrideLocomotionState", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMFootstepContext), &Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_bOverrideLocomotionState_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideLocomotionState_MetaData), NewProp_bOverrideLocomotionState_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_LocomotionState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_LocomotionState = { "LocomotionState", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepContext, LocomotionState), Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepLocomotionState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LocomotionState_MetaData), NewProp_LocomotionState_MetaData) }; // 2109635988
void Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_bOverrideLogicalFoot_SetBit(void* Obj)
{
	((FJMFootstepContext*)Obj)->bOverrideLogicalFoot = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_bOverrideLogicalFoot = { "bOverrideLogicalFoot", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMFootstepContext), &Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_bOverrideLogicalFoot_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideLogicalFoot_MetaData), NewProp_bOverrideLogicalFoot_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_LogicalFoot_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_LogicalFoot = { "LogicalFoot", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepContext, LogicalFoot), Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFoot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LogicalFoot_MetaData), NewProp_LogicalFoot_MetaData) }; // 1969087940
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_VolumeMultiplier = { "VolumeMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepContext, VolumeMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VolumeMultiplier_MetaData), NewProp_VolumeMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_PitchMultiplier = { "PitchMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepContext, PitchMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PitchMultiplier_MetaData), NewProp_PitchMultiplier_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_OptionalContextTag = { "OptionalContextTag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepContext, OptionalContextTag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OptionalContextTag_MetaData), NewProp_OptionalContextTag_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMFootstepContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_Instigator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_bOverrideTraceOrigin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_TraceOrigin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_bOverrideLocomotionState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_LocomotionState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_LocomotionState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_bOverrideLogicalFoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_LogicalFoot_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_LogicalFoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_VolumeMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_PitchMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewProp_OptionalContextTag,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMFootstepContext_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMFootstepContext Property Definitions *****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMFootstepContext_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMFootstepRuntime,
	nullptr,
	&NewStructOps,
	"JMFootstepContext",
	Z_Construct_UScriptStruct_FJMFootstepContext_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMFootstepContext_Statics::PropPointers),
	sizeof(FJMFootstepContext),
	alignof(FJMFootstepContext),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMFootstepContext_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMFootstepContext_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMFootstepContext()
{
	if (!Z_Registration_Info_UScriptStruct_FJMFootstepContext.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMFootstepContext.InnerSingleton, Z_Construct_UScriptStruct_FJMFootstepContext_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMFootstepContext.InnerSingleton);
}
// ********** End ScriptStruct FJMFootstepContext **************************************************

// ********** Begin ScriptStruct FJMFootstepResult *************************************************
struct Z_Construct_UScriptStruct_FJMFootstepResult_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMFootstepResult); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMFootstepResult); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSucceeded_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FailureReason_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LocomotionState_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedVariantState_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUsedVariantFallback_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUsedLegacyVariant_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LogicalFoot_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SurfaceType_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PhysicalMaterial_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedSound_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ImpactPoint_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ImpactNormal_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FinalVolume_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FinalPitch_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ModuleRelativePath", "Public/Types/JMFootstepTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMFootstepResult constinit property declarations *****************
	static void NewProp_bSucceeded_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSucceeded;
	static const UECodeGen_Private::FBytePropertyParams NewProp_FailureReason_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_FailureReason;
	static const UECodeGen_Private::FBytePropertyParams NewProp_LocomotionState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_LocomotionState;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SelectedVariantState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SelectedVariantState;
	static void NewProp_bUsedVariantFallback_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUsedVariantFallback;
	static void NewProp_bUsedLegacyVariant_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUsedLegacyVariant;
	static const UECodeGen_Private::FBytePropertyParams NewProp_LogicalFoot_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_LogicalFoot;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SurfaceType;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PhysicalMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedSound;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ImpactPoint;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ImpactNormal;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FinalVolume;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FinalPitch;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMFootstepResult constinit property declarations *******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMFootstepResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMFootstepResult_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMFootstepResult;
class UScriptStruct* FJMFootstepResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMFootstepResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMFootstepResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMFootstepResult, (UObject*)Z_Construct_UPackage__Script_JMFootstepRuntime(), TEXT("JMFootstepResult"));
	}
	return Z_Registration_Info_UScriptStruct_FJMFootstepResult.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMFootstepResult Property Definitions ****************************
void Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_bSucceeded_SetBit(void* Obj)
{
	((FJMFootstepResult*)Obj)->bSucceeded = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_bSucceeded = { "bSucceeded", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMFootstepResult), &Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_bSucceeded_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSucceeded_MetaData), NewProp_bSucceeded_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_FailureReason_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_FailureReason = { "FailureReason", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepResult, FailureReason), Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFailureReason, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FailureReason_MetaData), NewProp_FailureReason_MetaData) }; // 1742016081
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_LocomotionState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_LocomotionState = { "LocomotionState", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepResult, LocomotionState), Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepLocomotionState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LocomotionState_MetaData), NewProp_LocomotionState_MetaData) }; // 2109635988
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_SelectedVariantState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_SelectedVariantState = { "SelectedVariantState", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepResult, SelectedVariantState), Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepLocomotionState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedVariantState_MetaData), NewProp_SelectedVariantState_MetaData) }; // 2109635988
void Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_bUsedVariantFallback_SetBit(void* Obj)
{
	((FJMFootstepResult*)Obj)->bUsedVariantFallback = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_bUsedVariantFallback = { "bUsedVariantFallback", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMFootstepResult), &Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_bUsedVariantFallback_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUsedVariantFallback_MetaData), NewProp_bUsedVariantFallback_MetaData) };
void Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_bUsedLegacyVariant_SetBit(void* Obj)
{
	((FJMFootstepResult*)Obj)->bUsedLegacyVariant = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_bUsedLegacyVariant = { "bUsedLegacyVariant", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMFootstepResult), &Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_bUsedLegacyVariant_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUsedLegacyVariant_MetaData), NewProp_bUsedLegacyVariant_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_LogicalFoot_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_LogicalFoot = { "LogicalFoot", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepResult, LogicalFoot), Z_Construct_UEnum_JMFootstepRuntime_EJMFootstepFoot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LogicalFoot_MetaData), NewProp_LogicalFoot_MetaData) }; // 1969087940
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_SurfaceType = { "SurfaceType", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepResult, SurfaceType), Z_Construct_UEnum_PhysicsCore_EPhysicalSurface, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SurfaceType_MetaData), NewProp_SurfaceType_MetaData) }; // 2774282401
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_PhysicalMaterial = { "PhysicalMaterial", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepResult, PhysicalMaterial), Z_Construct_UClass_UPhysicalMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PhysicalMaterial_MetaData), NewProp_PhysicalMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_SelectedSound = { "SelectedSound", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepResult, SelectedSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedSound_MetaData), NewProp_SelectedSound_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_ImpactPoint = { "ImpactPoint", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepResult, ImpactPoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ImpactPoint_MetaData), NewProp_ImpactPoint_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_ImpactNormal = { "ImpactNormal", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepResult, ImpactNormal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ImpactNormal_MetaData), NewProp_ImpactNormal_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_FinalVolume = { "FinalVolume", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepResult, FinalVolume), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FinalVolume_MetaData), NewProp_FinalVolume_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_FinalPitch = { "FinalPitch", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepResult, FinalPitch), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FinalPitch_MetaData), NewProp_FinalPitch_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMFootstepResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_bSucceeded,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_FailureReason_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_FailureReason,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_LocomotionState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_LocomotionState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_SelectedVariantState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_SelectedVariantState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_bUsedVariantFallback,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_bUsedLegacyVariant,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_LogicalFoot_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_LogicalFoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_SurfaceType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_PhysicalMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_SelectedSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_ImpactPoint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_ImpactNormal,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_FinalVolume,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewProp_FinalPitch,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMFootstepResult_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMFootstepResult Property Definitions ******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMFootstepResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMFootstepRuntime,
	nullptr,
	&NewStructOps,
	"JMFootstepResult",
	Z_Construct_UScriptStruct_FJMFootstepResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMFootstepResult_Statics::PropPointers),
	sizeof(FJMFootstepResult),
	alignof(FJMFootstepResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMFootstepResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMFootstepResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMFootstepResult()
{
	if (!Z_Registration_Info_UScriptStruct_FJMFootstepResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMFootstepResult.InnerSingleton, Z_Construct_UScriptStruct_FJMFootstepResult_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMFootstepResult.InnerSingleton);
}
// ********** End ScriptStruct FJMFootstepResult ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Types_JMFootstepTypes_h__Script_JMFootstepRuntime_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EJMFootstepLocomotionState_StaticEnum, TEXT("EJMFootstepLocomotionState"), &Z_Registration_Info_UEnum_EJMFootstepLocomotionState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2109635988U) },
		{ EJMFootstepFoot_StaticEnum, TEXT("EJMFootstepFoot"), &Z_Registration_Info_UEnum_EJMFootstepFoot, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1969087940U) },
		{ EJMFootstepTriggerMode_StaticEnum, TEXT("EJMFootstepTriggerMode"), &Z_Registration_Info_UEnum_EJMFootstepTriggerMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 236246170U) },
		{ EJMFootstepFailureReason_StaticEnum, TEXT("EJMFootstepFailureReason"), &Z_Registration_Info_UEnum_EJMFootstepFailureReason, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1742016081U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FJMFootstepContext::StaticStruct, Z_Construct_UScriptStruct_FJMFootstepContext_Statics::NewStructOps, TEXT("JMFootstepContext"),&Z_Registration_Info_UScriptStruct_FJMFootstepContext, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMFootstepContext), 163523017U) },
		{ FJMFootstepResult::StaticStruct, Z_Construct_UScriptStruct_FJMFootstepResult_Statics::NewStructOps, TEXT("JMFootstepResult"),&Z_Registration_Info_UScriptStruct_FJMFootstepResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMFootstepResult), 3779851243U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Types_JMFootstepTypes_h__Script_JMFootstepRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Types_JMFootstepTypes_h__Script_JMFootstepRuntime_872747527{
	TEXT("/Script/JMFootstepRuntime"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Types_JMFootstepTypes_h__Script_JMFootstepRuntime_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Types_JMFootstepTypes_h__Script_JMFootstepRuntime_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Types_JMFootstepTypes_h__Script_JMFootstepRuntime_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Types_JMFootstepTypes_h__Script_JMFootstepRuntime_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
