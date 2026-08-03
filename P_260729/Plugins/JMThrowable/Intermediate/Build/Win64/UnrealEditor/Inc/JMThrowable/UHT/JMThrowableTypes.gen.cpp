// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JMThrowableTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMThrowableTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
JMTHROWABLE_API UClass* Z_Construct_UClass_AJMThrowableProjectile_NoRegister();
JMTHROWABLE_API UClass* Z_Construct_UClass_UJMThrowableDefinition_NoRegister();
JMTHROWABLE_API UEnum* Z_Construct_UEnum_JMThrowable_EJMThrowablePreviewRendererMode();
JMTHROWABLE_API UEnum* Z_Construct_UEnum_JMThrowable_EJMThrowableProjectileState();
JMTHROWABLE_API UEnum* Z_Construct_UEnum_JMThrowable_EJMThrowableSurfaceType();
JMTHROWABLE_API UEnum* Z_Construct_UEnum_JMThrowable_EJMThrowableUseState();
JMTHROWABLE_API UEnum* Z_Construct_UEnum_JMThrowable_EJMThrowResultCode();
JMTHROWABLE_API UFunction* Z_Construct_UDelegateFunction_JMThrowable_JMThrowableStateChanged__DelegateSignature();
JMTHROWABLE_API UFunction* Z_Construct_UDelegateFunction_JMThrowable_JMThrowableThrowCompleted__DelegateSignature();
JMTHROWABLE_API UScriptStruct* Z_Construct_UScriptStruct_FJMThrowableUseContext();
JMTHROWABLE_API UScriptStruct* Z_Construct_UScriptStruct_FJMThrowParameters();
JMTHROWABLE_API UScriptStruct* Z_Construct_UScriptStruct_FJMThrowResult();
JMTHROWABLE_API UScriptStruct* Z_Construct_UScriptStruct_FJMThrowSimulationResult();
JMTHROWABLE_API UScriptStruct* Z_Construct_UScriptStruct_FJMThrowSimulationState();
UPackage* Z_Construct_UPackage__Script_JMThrowable();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EJMThrowableUseState ******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMThrowableUseState;
static UEnum* EJMThrowableUseState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMThrowableUseState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMThrowableUseState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMThrowable_EJMThrowableUseState, (UObject*)Z_Construct_UPackage__Script_JMThrowable(), TEXT("EJMThrowableUseState"));
	}
	return Z_Registration_Info_UEnum_EJMThrowableUseState.OuterSingleton;
}
template<> JMTHROWABLE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMThrowableUseState>()
{
	return EJMThrowableUseState_StaticEnum();
}
struct Z_Construct_UEnum_JMThrowable_EJMThrowableUseState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Aiming.Name", "EJMThrowableUseState::Aiming" },
		{ "BlueprintType", "true" },
		{ "CommittingThrow.Name", "EJMThrowableUseState::CommittingThrow" },
		{ "Idle.Name", "EJMThrowableUseState::Idle" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
		{ "Ready.Name", "EJMThrowableUseState::Ready" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMThrowableUseState::Idle", (int64)EJMThrowableUseState::Idle },
		{ "EJMThrowableUseState::Ready", (int64)EJMThrowableUseState::Ready },
		{ "EJMThrowableUseState::Aiming", (int64)EJMThrowableUseState::Aiming },
		{ "EJMThrowableUseState::CommittingThrow", (int64)EJMThrowableUseState::CommittingThrow },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMThrowable_EJMThrowableUseState_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMThrowable_EJMThrowableUseState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMThrowable,
	nullptr,
	"EJMThrowableUseState",
	"EJMThrowableUseState",
	Z_Construct_UEnum_JMThrowable_EJMThrowableUseState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMThrowable_EJMThrowableUseState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMThrowable_EJMThrowableUseState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMThrowable_EJMThrowableUseState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMThrowable_EJMThrowableUseState()
{
	if (!Z_Registration_Info_UEnum_EJMThrowableUseState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMThrowableUseState.InnerSingleton, Z_Construct_UEnum_JMThrowable_EJMThrowableUseState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMThrowableUseState.InnerSingleton;
}
// ********** End Enum EJMThrowableUseState ********************************************************

// ********** Begin Enum EJMThrowablePreviewRendererMode *******************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMThrowablePreviewRendererMode;
static UEnum* EJMThrowablePreviewRendererMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMThrowablePreviewRendererMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMThrowablePreviewRendererMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMThrowable_EJMThrowablePreviewRendererMode, (UObject*)Z_Construct_UPackage__Script_JMThrowable(), TEXT("EJMThrowablePreviewRendererMode"));
	}
	return Z_Registration_Info_UEnum_EJMThrowablePreviewRendererMode.OuterSingleton;
}
template<> JMTHROWABLE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMThrowablePreviewRendererMode>()
{
	return EJMThrowablePreviewRendererMode_StaticEnum();
}
struct Z_Construct_UEnum_JMThrowable_EJMThrowablePreviewRendererMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
		{ "NiagaraPreferred.Name", "EJMThrowablePreviewRendererMode::NiagaraPreferred" },
		{ "ProceduralOnly.Name", "EJMThrowablePreviewRendererMode::ProceduralOnly" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMThrowablePreviewRendererMode::NiagaraPreferred", (int64)EJMThrowablePreviewRendererMode::NiagaraPreferred },
		{ "EJMThrowablePreviewRendererMode::ProceduralOnly", (int64)EJMThrowablePreviewRendererMode::ProceduralOnly },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMThrowable_EJMThrowablePreviewRendererMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMThrowable_EJMThrowablePreviewRendererMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMThrowable,
	nullptr,
	"EJMThrowablePreviewRendererMode",
	"EJMThrowablePreviewRendererMode",
	Z_Construct_UEnum_JMThrowable_EJMThrowablePreviewRendererMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMThrowable_EJMThrowablePreviewRendererMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMThrowable_EJMThrowablePreviewRendererMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMThrowable_EJMThrowablePreviewRendererMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMThrowable_EJMThrowablePreviewRendererMode()
{
	if (!Z_Registration_Info_UEnum_EJMThrowablePreviewRendererMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMThrowablePreviewRendererMode.InnerSingleton, Z_Construct_UEnum_JMThrowable_EJMThrowablePreviewRendererMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMThrowablePreviewRendererMode.InnerSingleton;
}
// ********** End Enum EJMThrowablePreviewRendererMode *********************************************

// ********** Begin Enum EJMThrowableProjectileState ***********************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMThrowableProjectileState;
static UEnum* EJMThrowableProjectileState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMThrowableProjectileState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMThrowableProjectileState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMThrowable_EJMThrowableProjectileState, (UObject*)Z_Construct_UPackage__Script_JMThrowable(), TEXT("EJMThrowableProjectileState"));
	}
	return Z_Registration_Info_UEnum_EJMThrowableProjectileState.OuterSingleton;
}
template<> JMTHROWABLE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMThrowableProjectileState>()
{
	return EJMThrowableProjectileState_StaticEnum();
}
struct Z_Construct_UEnum_JMThrowable_EJMThrowableProjectileState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Activated.Name", "EJMThrowableProjectileState::Activated" },
		{ "BlueprintType", "true" },
		{ "Finished.Name", "EJMThrowableProjectileState::Finished" },
		{ "Flying.Name", "EJMThrowableProjectileState::Flying" },
		{ "Fuse.Name", "EJMThrowableProjectileState::Fuse" },
		{ "Inactive.Name", "EJMThrowableProjectileState::Inactive" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
		{ "Resting.Name", "EJMThrowableProjectileState::Resting" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMThrowableProjectileState::Inactive", (int64)EJMThrowableProjectileState::Inactive },
		{ "EJMThrowableProjectileState::Flying", (int64)EJMThrowableProjectileState::Flying },
		{ "EJMThrowableProjectileState::Resting", (int64)EJMThrowableProjectileState::Resting },
		{ "EJMThrowableProjectileState::Fuse", (int64)EJMThrowableProjectileState::Fuse },
		{ "EJMThrowableProjectileState::Activated", (int64)EJMThrowableProjectileState::Activated },
		{ "EJMThrowableProjectileState::Finished", (int64)EJMThrowableProjectileState::Finished },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMThrowable_EJMThrowableProjectileState_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMThrowable_EJMThrowableProjectileState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMThrowable,
	nullptr,
	"EJMThrowableProjectileState",
	"EJMThrowableProjectileState",
	Z_Construct_UEnum_JMThrowable_EJMThrowableProjectileState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMThrowable_EJMThrowableProjectileState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMThrowable_EJMThrowableProjectileState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMThrowable_EJMThrowableProjectileState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMThrowable_EJMThrowableProjectileState()
{
	if (!Z_Registration_Info_UEnum_EJMThrowableProjectileState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMThrowableProjectileState.InnerSingleton, Z_Construct_UEnum_JMThrowable_EJMThrowableProjectileState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMThrowableProjectileState.InnerSingleton;
}
// ********** End Enum EJMThrowableProjectileState *************************************************

// ********** Begin Enum EJMThrowableSurfaceType ***************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMThrowableSurfaceType;
static UEnum* EJMThrowableSurfaceType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMThrowableSurfaceType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMThrowableSurfaceType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMThrowable_EJMThrowableSurfaceType, (UObject*)Z_Construct_UPackage__Script_JMThrowable(), TEXT("EJMThrowableSurfaceType"));
	}
	return Z_Registration_Info_UEnum_EJMThrowableSurfaceType.OuterSingleton;
}
template<> JMTHROWABLE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMThrowableSurfaceType>()
{
	return EJMThrowableSurfaceType_StaticEnum();
}
struct Z_Construct_UEnum_JMThrowable_EJMThrowableSurfaceType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Ceiling.Name", "EJMThrowableSurfaceType::Ceiling" },
		{ "Floor.Name", "EJMThrowableSurfaceType::Floor" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
		{ "Slope.Name", "EJMThrowableSurfaceType::Slope" },
		{ "Wall.Name", "EJMThrowableSurfaceType::Wall" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMThrowableSurfaceType::Floor", (int64)EJMThrowableSurfaceType::Floor },
		{ "EJMThrowableSurfaceType::Wall", (int64)EJMThrowableSurfaceType::Wall },
		{ "EJMThrowableSurfaceType::Slope", (int64)EJMThrowableSurfaceType::Slope },
		{ "EJMThrowableSurfaceType::Ceiling", (int64)EJMThrowableSurfaceType::Ceiling },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMThrowable_EJMThrowableSurfaceType_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMThrowable_EJMThrowableSurfaceType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMThrowable,
	nullptr,
	"EJMThrowableSurfaceType",
	"EJMThrowableSurfaceType",
	Z_Construct_UEnum_JMThrowable_EJMThrowableSurfaceType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMThrowable_EJMThrowableSurfaceType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMThrowable_EJMThrowableSurfaceType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMThrowable_EJMThrowableSurfaceType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMThrowable_EJMThrowableSurfaceType()
{
	if (!Z_Registration_Info_UEnum_EJMThrowableSurfaceType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMThrowableSurfaceType.InnerSingleton, Z_Construct_UEnum_JMThrowable_EJMThrowableSurfaceType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMThrowableSurfaceType.InnerSingleton;
}
// ********** End Enum EJMThrowableSurfaceType *****************************************************

// ********** Begin Enum EJMThrowResultCode ********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMThrowResultCode;
static UEnum* EJMThrowResultCode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMThrowResultCode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMThrowResultCode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMThrowable_EJMThrowResultCode, (UObject*)Z_Construct_UPackage__Script_JMThrowable(), TEXT("EJMThrowResultCode"));
	}
	return Z_Registration_Info_UEnum_EJMThrowResultCode.OuterSingleton;
}
template<> JMTHROWABLE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMThrowResultCode>()
{
	return EJMThrowResultCode_StaticEnum();
}
struct Z_Construct_UEnum_JMThrowable_EJMThrowResultCode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlockedSpawn.Name", "EJMThrowResultCode::BlockedSpawn" },
		{ "BlueprintType", "true" },
		{ "DuplicateCommit.Name", "EJMThrowResultCode::DuplicateCommit" },
		{ "InvalidDefinition.Name", "EJMThrowResultCode::InvalidDefinition" },
		{ "InvalidState.Name", "EJMThrowResultCode::InvalidState" },
		{ "InvalidThrowOrigin.Name", "EJMThrowResultCode::InvalidThrowOrigin" },
		{ "InventoryConsumeFailed.Name", "EJMThrowResultCode::InventoryConsumeFailed" },
		{ "ItemNoLongerExists.Name", "EJMThrowResultCode::ItemNoLongerExists" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
		{ "NoActiveItem.Name", "EJMThrowResultCode::NoActiveItem" },
		{ "NoLocalView.Name", "EJMThrowResultCode::NoLocalView" },
		{ "ProjectileSpawnFailed.Name", "EJMThrowResultCode::ProjectileSpawnFailed" },
		{ "Success.Name", "EJMThrowResultCode::Success" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMThrowResultCode::Success", (int64)EJMThrowResultCode::Success },
		{ "EJMThrowResultCode::InvalidState", (int64)EJMThrowResultCode::InvalidState },
		{ "EJMThrowResultCode::NoActiveItem", (int64)EJMThrowResultCode::NoActiveItem },
		{ "EJMThrowResultCode::ItemNoLongerExists", (int64)EJMThrowResultCode::ItemNoLongerExists },
		{ "EJMThrowResultCode::InvalidDefinition", (int64)EJMThrowResultCode::InvalidDefinition },
		{ "EJMThrowResultCode::NoLocalView", (int64)EJMThrowResultCode::NoLocalView },
		{ "EJMThrowResultCode::InvalidThrowOrigin", (int64)EJMThrowResultCode::InvalidThrowOrigin },
		{ "EJMThrowResultCode::BlockedSpawn", (int64)EJMThrowResultCode::BlockedSpawn },
		{ "EJMThrowResultCode::ProjectileSpawnFailed", (int64)EJMThrowResultCode::ProjectileSpawnFailed },
		{ "EJMThrowResultCode::InventoryConsumeFailed", (int64)EJMThrowResultCode::InventoryConsumeFailed },
		{ "EJMThrowResultCode::DuplicateCommit", (int64)EJMThrowResultCode::DuplicateCommit },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMThrowable_EJMThrowResultCode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMThrowable_EJMThrowResultCode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMThrowable,
	nullptr,
	"EJMThrowResultCode",
	"EJMThrowResultCode",
	Z_Construct_UEnum_JMThrowable_EJMThrowResultCode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMThrowable_EJMThrowResultCode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMThrowable_EJMThrowResultCode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMThrowable_EJMThrowResultCode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMThrowable_EJMThrowResultCode()
{
	if (!Z_Registration_Info_UEnum_EJMThrowResultCode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMThrowResultCode.InnerSingleton, Z_Construct_UEnum_JMThrowable_EJMThrowResultCode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMThrowResultCode.InnerSingleton;
}
// ********** End Enum EJMThrowResultCode **********************************************************

// ********** Begin ScriptStruct FJMThrowParameters ************************************************
struct Z_Construct_UScriptStruct_FJMThrowParameters_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMThrowParameters); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMThrowParameters); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartPosition_MetaData[] = {
		{ "Category", "JMThrowParameters" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InitialVelocity_MetaData[] = {
		{ "Category", "JMThrowParameters" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Gravity_MetaData[] = {
		{ "Category", "JMThrowParameters" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileRadius_MetaData[] = {
		{ "Category", "JMThrowParameters" },
		{ "ClampMin", "0.1" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SimulationStep_MetaData[] = {
		{ "Category", "JMThrowParameters" },
		{ "ClampMin", "0.001" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumSimulationTime_MetaData[] = {
		{ "Category", "JMThrowParameters" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollisionProfile_MetaData[] = {
		{ "Category", "JMThrowParameters" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloorNormalThreshold_MetaData[] = {
		{ "Category", "JMThrowParameters" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "-1.0" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxWallBounces_MetaData[] = {
		{ "Category", "JMThrowParameters" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BounceRestitution_MetaData[] = {
		{ "Category", "JMThrowParameters" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TangentialDamping_MetaData[] = {
		{ "Category", "JMThrowParameters" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxFloorBounces_MetaData[] = {
		{ "Category", "JMThrowParameters" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloorRestitution_MetaData[] = {
		{ "Category", "JMThrowParameters" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloorTangentialDamping_MetaData[] = {
		{ "Category", "JMThrowParameters" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloorBounceDecay_MetaData[] = {
		{ "Category", "JMThrowParameters" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloorBounceStopSpeed_MetaData[] = {
		{ "Category", "JMThrowParameters" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SurfaceOffset_MetaData[] = {
		{ "Category", "JMThrowParameters" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloorFriction_MetaData[] = {
		{ "Category", "JMThrowParameters" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloorStopSpeed_MetaData[] = {
		{ "Category", "JMThrowParameters" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DynamicImpactImpulse_MetaData[] = {
		{ "Category", "JMThrowParameters" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VisualSpinDegreesPerSecond_MetaData[] = {
		{ "Category", "JMThrowParameters" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IgnoredActors_MetaData[] = {
		{ "Category", "JMThrowParameters" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDebugDraw_MetaData[] = {
		{ "Category", "JMThrowParameters" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMThrowParameters constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_StartPosition;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InitialVelocity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Gravity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ProjectileRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SimulationStep;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaximumSimulationTime;
	static const UECodeGen_Private::FNamePropertyParams NewProp_CollisionProfile;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FloorNormalThreshold;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxWallBounces;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BounceRestitution;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TangentialDamping;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxFloorBounces;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FloorRestitution;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FloorTangentialDamping;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FloorBounceDecay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FloorBounceStopSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SurfaceOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FloorFriction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FloorStopSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DynamicImpactImpulse;
	static const UECodeGen_Private::FStructPropertyParams NewProp_VisualSpinDegreesPerSecond;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IgnoredActors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_IgnoredActors;
	static void NewProp_bDebugDraw_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDebugDraw;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMThrowParameters constinit property declarations ******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMThrowParameters>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMThrowParameters_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMThrowParameters;
class UScriptStruct* FJMThrowParameters::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMThrowParameters.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMThrowParameters.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMThrowParameters, (UObject*)Z_Construct_UPackage__Script_JMThrowable(), TEXT("JMThrowParameters"));
	}
	return Z_Registration_Info_UScriptStruct_FJMThrowParameters.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMThrowParameters Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_StartPosition = { "StartPosition", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowParameters, StartPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartPosition_MetaData), NewProp_StartPosition_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_InitialVelocity = { "InitialVelocity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowParameters, InitialVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InitialVelocity_MetaData), NewProp_InitialVelocity_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_Gravity = { "Gravity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowParameters, Gravity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Gravity_MetaData), NewProp_Gravity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_ProjectileRadius = { "ProjectileRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowParameters, ProjectileRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileRadius_MetaData), NewProp_ProjectileRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_SimulationStep = { "SimulationStep", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowParameters, SimulationStep), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SimulationStep_MetaData), NewProp_SimulationStep_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_MaximumSimulationTime = { "MaximumSimulationTime", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowParameters, MaximumSimulationTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumSimulationTime_MetaData), NewProp_MaximumSimulationTime_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_CollisionProfile = { "CollisionProfile", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowParameters, CollisionProfile), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollisionProfile_MetaData), NewProp_CollisionProfile_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_FloorNormalThreshold = { "FloorNormalThreshold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowParameters, FloorNormalThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorNormalThreshold_MetaData), NewProp_FloorNormalThreshold_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_MaxWallBounces = { "MaxWallBounces", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowParameters, MaxWallBounces), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxWallBounces_MetaData), NewProp_MaxWallBounces_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_BounceRestitution = { "BounceRestitution", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowParameters, BounceRestitution), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BounceRestitution_MetaData), NewProp_BounceRestitution_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_TangentialDamping = { "TangentialDamping", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowParameters, TangentialDamping), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TangentialDamping_MetaData), NewProp_TangentialDamping_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_MaxFloorBounces = { "MaxFloorBounces", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowParameters, MaxFloorBounces), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxFloorBounces_MetaData), NewProp_MaxFloorBounces_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_FloorRestitution = { "FloorRestitution", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowParameters, FloorRestitution), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorRestitution_MetaData), NewProp_FloorRestitution_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_FloorTangentialDamping = { "FloorTangentialDamping", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowParameters, FloorTangentialDamping), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorTangentialDamping_MetaData), NewProp_FloorTangentialDamping_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_FloorBounceDecay = { "FloorBounceDecay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowParameters, FloorBounceDecay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorBounceDecay_MetaData), NewProp_FloorBounceDecay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_FloorBounceStopSpeed = { "FloorBounceStopSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowParameters, FloorBounceStopSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorBounceStopSpeed_MetaData), NewProp_FloorBounceStopSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_SurfaceOffset = { "SurfaceOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowParameters, SurfaceOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SurfaceOffset_MetaData), NewProp_SurfaceOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_FloorFriction = { "FloorFriction", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowParameters, FloorFriction), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorFriction_MetaData), NewProp_FloorFriction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_FloorStopSpeed = { "FloorStopSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowParameters, FloorStopSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorStopSpeed_MetaData), NewProp_FloorStopSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_DynamicImpactImpulse = { "DynamicImpactImpulse", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowParameters, DynamicImpactImpulse), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DynamicImpactImpulse_MetaData), NewProp_DynamicImpactImpulse_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_VisualSpinDegreesPerSecond = { "VisualSpinDegreesPerSecond", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowParameters, VisualSpinDegreesPerSecond), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VisualSpinDegreesPerSecond_MetaData), NewProp_VisualSpinDegreesPerSecond_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_IgnoredActors_Inner = { "IgnoredActors", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_IgnoredActors = { "IgnoredActors", nullptr, (EPropertyFlags)0x0114000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowParameters, IgnoredActors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IgnoredActors_MetaData), NewProp_IgnoredActors_MetaData) };
void Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_bDebugDraw_SetBit(void* Obj)
{
	((FJMThrowParameters*)Obj)->bDebugDraw = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_bDebugDraw = { "bDebugDraw", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMThrowParameters), &Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_bDebugDraw_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDebugDraw_MetaData), NewProp_bDebugDraw_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMThrowParameters_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_StartPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_InitialVelocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_Gravity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_ProjectileRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_SimulationStep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_MaximumSimulationTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_CollisionProfile,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_FloorNormalThreshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_MaxWallBounces,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_BounceRestitution,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_TangentialDamping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_MaxFloorBounces,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_FloorRestitution,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_FloorTangentialDamping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_FloorBounceDecay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_FloorBounceStopSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_SurfaceOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_FloorFriction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_FloorStopSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_DynamicImpactImpulse,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_VisualSpinDegreesPerSecond,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_IgnoredActors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_IgnoredActors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewProp_bDebugDraw,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMThrowParameters_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMThrowParameters Property Definitions *****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMThrowParameters_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMThrowable,
	nullptr,
	&NewStructOps,
	"JMThrowParameters",
	Z_Construct_UScriptStruct_FJMThrowParameters_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMThrowParameters_Statics::PropPointers),
	sizeof(FJMThrowParameters),
	alignof(FJMThrowParameters),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMThrowParameters_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMThrowParameters_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMThrowParameters()
{
	if (!Z_Registration_Info_UScriptStruct_FJMThrowParameters.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMThrowParameters.InnerSingleton, Z_Construct_UScriptStruct_FJMThrowParameters_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMThrowParameters.InnerSingleton);
}
// ********** End ScriptStruct FJMThrowParameters **************************************************

// ********** Begin ScriptStruct FJMThrowSimulationState *******************************************
struct Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMThrowSimulationState); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMThrowSimulationState); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[] = {
		{ "Category", "JMThrowSimulationState" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Velocity_MetaData[] = {
		{ "Category", "JMThrowSimulationState" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ElapsedTime_MetaData[] = {
		{ "Category", "JMThrowSimulationState" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WallBounceCount_MetaData[] = {
		{ "Category", "JMThrowSimulationState" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloorBounceCount_MetaData[] = {
		{ "Category", "JMThrowSimulationState" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bResting_MetaData[] = {
		{ "Category", "JMThrowSimulationState" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMThrowSimulationState constinit property declarations ***********
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Velocity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ElapsedTime;
	static const UECodeGen_Private::FIntPropertyParams NewProp_WallBounceCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_FloorBounceCount;
	static void NewProp_bResting_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bResting;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMThrowSimulationState constinit property declarations *************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMThrowSimulationState>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMThrowSimulationState;
class UScriptStruct* FJMThrowSimulationState::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMThrowSimulationState.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMThrowSimulationState.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMThrowSimulationState, (UObject*)Z_Construct_UPackage__Script_JMThrowable(), TEXT("JMThrowSimulationState"));
	}
	return Z_Registration_Info_UScriptStruct_FJMThrowSimulationState.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMThrowSimulationState Property Definitions **********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowSimulationState, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Position_MetaData), NewProp_Position_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics::NewProp_Velocity = { "Velocity", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowSimulationState, Velocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Velocity_MetaData), NewProp_Velocity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics::NewProp_ElapsedTime = { "ElapsedTime", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowSimulationState, ElapsedTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ElapsedTime_MetaData), NewProp_ElapsedTime_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics::NewProp_WallBounceCount = { "WallBounceCount", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowSimulationState, WallBounceCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WallBounceCount_MetaData), NewProp_WallBounceCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics::NewProp_FloorBounceCount = { "FloorBounceCount", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowSimulationState, FloorBounceCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorBounceCount_MetaData), NewProp_FloorBounceCount_MetaData) };
void Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics::NewProp_bResting_SetBit(void* Obj)
{
	((FJMThrowSimulationState*)Obj)->bResting = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics::NewProp_bResting = { "bResting", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMThrowSimulationState), &Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics::NewProp_bResting_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bResting_MetaData), NewProp_bResting_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics::NewProp_Velocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics::NewProp_ElapsedTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics::NewProp_WallBounceCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics::NewProp_FloorBounceCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics::NewProp_bResting,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMThrowSimulationState Property Definitions ************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMThrowable,
	nullptr,
	&NewStructOps,
	"JMThrowSimulationState",
	Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics::PropPointers),
	sizeof(FJMThrowSimulationState),
	alignof(FJMThrowSimulationState),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMThrowSimulationState()
{
	if (!Z_Registration_Info_UScriptStruct_FJMThrowSimulationState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMThrowSimulationState.InnerSingleton, Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMThrowSimulationState.InnerSingleton);
}
// ********** End ScriptStruct FJMThrowSimulationState *********************************************

// ********** Begin ScriptStruct FJMThrowSimulationResult ******************************************
struct Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMThrowSimulationResult); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMThrowSimulationResult); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Points_MetaData[] = {
		{ "Category", "JMThrowSimulationResult" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ImpactPoints_MetaData[] = {
		{ "Category", "JMThrowSimulationResult" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ImpactNormals_MetaData[] = {
		{ "Category", "JMThrowSimulationResult" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FinalRestPoint_MetaData[] = {
		{ "Category", "JMThrowSimulationResult" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bReachedRest_MetaData[] = {
		{ "Category", "JMThrowSimulationResult" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WallBounceCount_MetaData[] = {
		{ "Category", "JMThrowSimulationResult" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloorBounceCount_MetaData[] = {
		{ "Category", "JMThrowSimulationResult" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMThrowSimulationResult constinit property declarations **********
	static const UECodeGen_Private::FStructPropertyParams NewProp_Points_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Points;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ImpactPoints_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ImpactPoints;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ImpactNormals_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ImpactNormals;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FinalRestPoint;
	static void NewProp_bReachedRest_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bReachedRest;
	static const UECodeGen_Private::FIntPropertyParams NewProp_WallBounceCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_FloorBounceCount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMThrowSimulationResult constinit property declarations ************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMThrowSimulationResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMThrowSimulationResult;
class UScriptStruct* FJMThrowSimulationResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMThrowSimulationResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMThrowSimulationResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMThrowSimulationResult, (UObject*)Z_Construct_UPackage__Script_JMThrowable(), TEXT("JMThrowSimulationResult"));
	}
	return Z_Registration_Info_UScriptStruct_FJMThrowSimulationResult.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMThrowSimulationResult Property Definitions *********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::NewProp_Points_Inner = { "Points", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::NewProp_Points = { "Points", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowSimulationResult, Points), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Points_MetaData), NewProp_Points_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::NewProp_ImpactPoints_Inner = { "ImpactPoints", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::NewProp_ImpactPoints = { "ImpactPoints", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowSimulationResult, ImpactPoints), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ImpactPoints_MetaData), NewProp_ImpactPoints_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::NewProp_ImpactNormals_Inner = { "ImpactNormals", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::NewProp_ImpactNormals = { "ImpactNormals", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowSimulationResult, ImpactNormals), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ImpactNormals_MetaData), NewProp_ImpactNormals_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::NewProp_FinalRestPoint = { "FinalRestPoint", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowSimulationResult, FinalRestPoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FinalRestPoint_MetaData), NewProp_FinalRestPoint_MetaData) };
void Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::NewProp_bReachedRest_SetBit(void* Obj)
{
	((FJMThrowSimulationResult*)Obj)->bReachedRest = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::NewProp_bReachedRest = { "bReachedRest", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMThrowSimulationResult), &Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::NewProp_bReachedRest_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bReachedRest_MetaData), NewProp_bReachedRest_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::NewProp_WallBounceCount = { "WallBounceCount", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowSimulationResult, WallBounceCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WallBounceCount_MetaData), NewProp_WallBounceCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::NewProp_FloorBounceCount = { "FloorBounceCount", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowSimulationResult, FloorBounceCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorBounceCount_MetaData), NewProp_FloorBounceCount_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::NewProp_Points_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::NewProp_Points,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::NewProp_ImpactPoints_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::NewProp_ImpactPoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::NewProp_ImpactNormals_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::NewProp_ImpactNormals,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::NewProp_FinalRestPoint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::NewProp_bReachedRest,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::NewProp_WallBounceCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::NewProp_FloorBounceCount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMThrowSimulationResult Property Definitions ***********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMThrowable,
	nullptr,
	&NewStructOps,
	"JMThrowSimulationResult",
	Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::PropPointers),
	sizeof(FJMThrowSimulationResult),
	alignof(FJMThrowSimulationResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMThrowSimulationResult()
{
	if (!Z_Registration_Info_UScriptStruct_FJMThrowSimulationResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMThrowSimulationResult.InnerSingleton, Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMThrowSimulationResult.InnerSingleton);
}
// ********** End ScriptStruct FJMThrowSimulationResult ********************************************

// ********** Begin ScriptStruct FJMThrowableUseContext ********************************************
struct Z_Construct_UScriptStruct_FJMThrowableUseContext_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMThrowableUseContext); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMThrowableUseContext); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_User_MetaData[] = {
		{ "Category", "JMThrowableUseContext" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Definition_MetaData[] = {
		{ "Category", "JMThrowableUseContext" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExplicitThrowOrigin_MetaData[] = {
		{ "Category", "JMThrowableUseContext" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SessionId_MetaData[] = {
		{ "Category", "JMThrowableUseContext" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMThrowableUseContext constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_User;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Definition;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ExplicitThrowOrigin;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SessionId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMThrowableUseContext constinit property declarations **************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMThrowableUseContext>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMThrowableUseContext_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMThrowableUseContext;
class UScriptStruct* FJMThrowableUseContext::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMThrowableUseContext.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMThrowableUseContext.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMThrowableUseContext, (UObject*)Z_Construct_UPackage__Script_JMThrowable(), TEXT("JMThrowableUseContext"));
	}
	return Z_Registration_Info_UScriptStruct_FJMThrowableUseContext.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMThrowableUseContext Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMThrowableUseContext_Statics::NewProp_User = { "User", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowableUseContext, User), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_User_MetaData), NewProp_User_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMThrowableUseContext_Statics::NewProp_Definition = { "Definition", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowableUseContext, Definition), Z_Construct_UClass_UJMThrowableDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Definition_MetaData), NewProp_Definition_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMThrowableUseContext_Statics::NewProp_ExplicitThrowOrigin = { "ExplicitThrowOrigin", nullptr, (EPropertyFlags)0x011400000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowableUseContext, ExplicitThrowOrigin), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExplicitThrowOrigin_MetaData), NewProp_ExplicitThrowOrigin_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMThrowableUseContext_Statics::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowableUseContext, SessionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SessionId_MetaData), NewProp_SessionId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMThrowableUseContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowableUseContext_Statics::NewProp_User,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowableUseContext_Statics::NewProp_Definition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowableUseContext_Statics::NewProp_ExplicitThrowOrigin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowableUseContext_Statics::NewProp_SessionId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMThrowableUseContext_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMThrowableUseContext Property Definitions *************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMThrowableUseContext_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMThrowable,
	nullptr,
	&NewStructOps,
	"JMThrowableUseContext",
	Z_Construct_UScriptStruct_FJMThrowableUseContext_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMThrowableUseContext_Statics::PropPointers),
	sizeof(FJMThrowableUseContext),
	alignof(FJMThrowableUseContext),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000205),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMThrowableUseContext_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMThrowableUseContext_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMThrowableUseContext()
{
	if (!Z_Registration_Info_UScriptStruct_FJMThrowableUseContext.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMThrowableUseContext.InnerSingleton, Z_Construct_UScriptStruct_FJMThrowableUseContext_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMThrowableUseContext.InnerSingleton);
}
// ********** End ScriptStruct FJMThrowableUseContext **********************************************

// ********** Begin ScriptStruct FJMThrowResult ****************************************************
struct Z_Construct_UScriptStruct_FJMThrowResult_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMThrowResult); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMThrowResult); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSucceeded_MetaData[] = {
		{ "Category", "JMThrowResult" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ResultCode_MetaData[] = {
		{ "Category", "JMThrowResult" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FailureReason_MetaData[] = {
		{ "Category", "JMThrowResult" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Projectile_MetaData[] = {
		{ "Category", "JMThrowResult" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SessionId_MetaData[] = {
		{ "Category", "JMThrowResult" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConsumedQuantity_MetaData[] = {
		{ "Category", "JMThrowResult" },
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMThrowResult constinit property declarations ********************
	static void NewProp_bSucceeded_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSucceeded;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ResultCode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ResultCode;
	static const UECodeGen_Private::FTextPropertyParams NewProp_FailureReason;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Projectile;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SessionId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ConsumedQuantity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMThrowResult constinit property declarations **********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMThrowResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMThrowResult_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMThrowResult;
class UScriptStruct* FJMThrowResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMThrowResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMThrowResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMThrowResult, (UObject*)Z_Construct_UPackage__Script_JMThrowable(), TEXT("JMThrowResult"));
	}
	return Z_Registration_Info_UScriptStruct_FJMThrowResult.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMThrowResult Property Definitions *******************************
void Z_Construct_UScriptStruct_FJMThrowResult_Statics::NewProp_bSucceeded_SetBit(void* Obj)
{
	((FJMThrowResult*)Obj)->bSucceeded = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMThrowResult_Statics::NewProp_bSucceeded = { "bSucceeded", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMThrowResult), &Z_Construct_UScriptStruct_FJMThrowResult_Statics::NewProp_bSucceeded_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSucceeded_MetaData), NewProp_bSucceeded_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMThrowResult_Statics::NewProp_ResultCode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMThrowResult_Statics::NewProp_ResultCode = { "ResultCode", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowResult, ResultCode), Z_Construct_UEnum_JMThrowable_EJMThrowResultCode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ResultCode_MetaData), NewProp_ResultCode_MetaData) }; // 1477276836
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FJMThrowResult_Statics::NewProp_FailureReason = { "FailureReason", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowResult, FailureReason), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FailureReason_MetaData), NewProp_FailureReason_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMThrowResult_Statics::NewProp_Projectile = { "Projectile", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowResult, Projectile), Z_Construct_UClass_AJMThrowableProjectile_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Projectile_MetaData), NewProp_Projectile_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMThrowResult_Statics::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowResult, SessionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SessionId_MetaData), NewProp_SessionId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FJMThrowResult_Statics::NewProp_ConsumedQuantity = { "ConsumedQuantity", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowResult, ConsumedQuantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConsumedQuantity_MetaData), NewProp_ConsumedQuantity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMThrowResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowResult_Statics::NewProp_bSucceeded,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowResult_Statics::NewProp_ResultCode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowResult_Statics::NewProp_ResultCode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowResult_Statics::NewProp_FailureReason,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowResult_Statics::NewProp_Projectile,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowResult_Statics::NewProp_SessionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowResult_Statics::NewProp_ConsumedQuantity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMThrowResult_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMThrowResult Property Definitions *********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMThrowResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMThrowable,
	nullptr,
	&NewStructOps,
	"JMThrowResult",
	Z_Construct_UScriptStruct_FJMThrowResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMThrowResult_Statics::PropPointers),
	sizeof(FJMThrowResult),
	alignof(FJMThrowResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMThrowResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMThrowResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMThrowResult()
{
	if (!Z_Registration_Info_UScriptStruct_FJMThrowResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMThrowResult.InnerSingleton, Z_Construct_UScriptStruct_FJMThrowResult_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMThrowResult.InnerSingleton);
}
// ********** End ScriptStruct FJMThrowResult ******************************************************

// ********** Begin Delegate FJMThrowableStateChanged **********************************************
struct Z_Construct_UDelegateFunction_JMThrowable_JMThrowableStateChanged__DelegateSignature_Statics
{
	struct _Script_JMThrowable_eventJMThrowableStateChanged_Parms
	{
		EJMThrowableUseState NewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMThrowableStateChanged constinit property declarations **************
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMThrowableStateChanged constinit property declarations ****************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMThrowableStateChanged Property Definitions *************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_JMThrowable_JMThrowableStateChanged__DelegateSignature_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_JMThrowable_JMThrowableStateChanged__DelegateSignature_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMThrowable_eventJMThrowableStateChanged_Parms, NewState), Z_Construct_UEnum_JMThrowable_EJMThrowableUseState, METADATA_PARAMS(0, nullptr) }; // 755976728
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMThrowable_JMThrowableStateChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMThrowable_JMThrowableStateChanged__DelegateSignature_Statics::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMThrowable_JMThrowableStateChanged__DelegateSignature_Statics::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMThrowable_JMThrowableStateChanged__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMThrowableStateChanged Property Definitions ***************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMThrowable_JMThrowableStateChanged__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMThrowable, nullptr, "JMThrowableStateChanged__DelegateSignature", 	Z_Construct_UDelegateFunction_JMThrowable_JMThrowableStateChanged__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMThrowable_JMThrowableStateChanged__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMThrowable_JMThrowableStateChanged__DelegateSignature_Statics::_Script_JMThrowable_eventJMThrowableStateChanged_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMThrowable_JMThrowableStateChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMThrowable_JMThrowableStateChanged__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMThrowable_JMThrowableStateChanged__DelegateSignature_Statics::_Script_JMThrowable_eventJMThrowableStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMThrowable_JMThrowableStateChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMThrowable_JMThrowableStateChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMThrowableStateChanged_DelegateWrapper(const FMulticastScriptDelegate& JMThrowableStateChanged, EJMThrowableUseState NewState)
{
	struct _Script_JMThrowable_eventJMThrowableStateChanged_Parms
	{
		EJMThrowableUseState NewState;
	};
	_Script_JMThrowable_eventJMThrowableStateChanged_Parms Parms;
	Parms.NewState=NewState;
	JMThrowableStateChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMThrowableStateChanged ************************************************

// ********** Begin Delegate FJMThrowableThrowCompleted ********************************************
struct Z_Construct_UDelegateFunction_JMThrowable_JMThrowableThrowCompleted__DelegateSignature_Statics
{
	struct _Script_JMThrowable_eventJMThrowableThrowCompleted_Parms
	{
		FJMThrowResult Result;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/JMThrowableTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Result_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMThrowableThrowCompleted constinit property declarations ************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Result;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMThrowableThrowCompleted constinit property declarations **************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMThrowableThrowCompleted Property Definitions ***********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_JMThrowable_JMThrowableThrowCompleted__DelegateSignature_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMThrowable_eventJMThrowableThrowCompleted_Parms, Result), Z_Construct_UScriptStruct_FJMThrowResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Result_MetaData), NewProp_Result_MetaData) }; // 1994527197
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMThrowable_JMThrowableThrowCompleted__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMThrowable_JMThrowableThrowCompleted__DelegateSignature_Statics::NewProp_Result,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMThrowable_JMThrowableThrowCompleted__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMThrowableThrowCompleted Property Definitions *************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMThrowable_JMThrowableThrowCompleted__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMThrowable, nullptr, "JMThrowableThrowCompleted__DelegateSignature", 	Z_Construct_UDelegateFunction_JMThrowable_JMThrowableThrowCompleted__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMThrowable_JMThrowableThrowCompleted__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMThrowable_JMThrowableThrowCompleted__DelegateSignature_Statics::_Script_JMThrowable_eventJMThrowableThrowCompleted_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMThrowable_JMThrowableThrowCompleted__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMThrowable_JMThrowableThrowCompleted__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMThrowable_JMThrowableThrowCompleted__DelegateSignature_Statics::_Script_JMThrowable_eventJMThrowableThrowCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMThrowable_JMThrowableThrowCompleted__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMThrowable_JMThrowableThrowCompleted__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMThrowableThrowCompleted_DelegateWrapper(const FMulticastScriptDelegate& JMThrowableThrowCompleted, FJMThrowResult const& Result)
{
	struct _Script_JMThrowable_eventJMThrowableThrowCompleted_Parms
	{
		FJMThrowResult Result;
	};
	_Script_JMThrowable_eventJMThrowableThrowCompleted_Parms Parms;
	Parms.Result=Result;
	JMThrowableThrowCompleted.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMThrowableThrowCompleted **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableTypes_h__Script_JMThrowable_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EJMThrowableUseState_StaticEnum, TEXT("EJMThrowableUseState"), &Z_Registration_Info_UEnum_EJMThrowableUseState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 755976728U) },
		{ EJMThrowablePreviewRendererMode_StaticEnum, TEXT("EJMThrowablePreviewRendererMode"), &Z_Registration_Info_UEnum_EJMThrowablePreviewRendererMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2601393171U) },
		{ EJMThrowableProjectileState_StaticEnum, TEXT("EJMThrowableProjectileState"), &Z_Registration_Info_UEnum_EJMThrowableProjectileState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3369480408U) },
		{ EJMThrowableSurfaceType_StaticEnum, TEXT("EJMThrowableSurfaceType"), &Z_Registration_Info_UEnum_EJMThrowableSurfaceType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4286626248U) },
		{ EJMThrowResultCode_StaticEnum, TEXT("EJMThrowResultCode"), &Z_Registration_Info_UEnum_EJMThrowResultCode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1477276836U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FJMThrowParameters::StaticStruct, Z_Construct_UScriptStruct_FJMThrowParameters_Statics::NewStructOps, TEXT("JMThrowParameters"),&Z_Registration_Info_UScriptStruct_FJMThrowParameters, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMThrowParameters), 1204343964U) },
		{ FJMThrowSimulationState::StaticStruct, Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics::NewStructOps, TEXT("JMThrowSimulationState"),&Z_Registration_Info_UScriptStruct_FJMThrowSimulationState, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMThrowSimulationState), 2951013568U) },
		{ FJMThrowSimulationResult::StaticStruct, Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics::NewStructOps, TEXT("JMThrowSimulationResult"),&Z_Registration_Info_UScriptStruct_FJMThrowSimulationResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMThrowSimulationResult), 727515007U) },
		{ FJMThrowableUseContext::StaticStruct, Z_Construct_UScriptStruct_FJMThrowableUseContext_Statics::NewStructOps, TEXT("JMThrowableUseContext"),&Z_Registration_Info_UScriptStruct_FJMThrowableUseContext, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMThrowableUseContext), 2710774979U) },
		{ FJMThrowResult::StaticStruct, Z_Construct_UScriptStruct_FJMThrowResult_Statics::NewStructOps, TEXT("JMThrowResult"),&Z_Registration_Info_UScriptStruct_FJMThrowResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMThrowResult), 1994527197U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableTypes_h__Script_JMThrowable_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableTypes_h__Script_JMThrowable_2668469490{
	TEXT("/Script/JMThrowable"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableTypes_h__Script_JMThrowable_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableTypes_h__Script_JMThrowable_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableTypes_h__Script_JMThrowable_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableTypes_h__Script_JMThrowable_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
