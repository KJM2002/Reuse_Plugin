// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Types/JMJumpScareTypes.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMJumpScareTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
JMJUMPSCARE_API UClass* Z_Construct_UClass_AJMJumpScareAnchor_NoRegister();
JMJUMPSCARE_API UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScareCameraControlMode();
JMJUMPSCARE_API UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScareConcurrentPolicy();
JMJUMPSCARE_API UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScareOverlapFilter();
JMJUMPSCARE_API UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScarePhase();
JMJUMPSCARE_API UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScarePlayResult();
JMJUMPSCARE_API UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScarePresentationMode();
JMJUMPSCARE_API UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScareSpawnMode();
JMJUMPSCARE_API UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScareState();
JMJUMPSCARE_API UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScareTriggerPolicy();
JMJUMPSCARE_API UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScareVanishMode();
JMJUMPSCARE_API UScriptStruct* Z_Construct_UScriptStruct_FJMJumpScareActiveInfo();
JMJUMPSCARE_API UScriptStruct* Z_Construct_UScriptStruct_FJMJumpScareAudioEvent();
JMJUMPSCARE_API UScriptStruct* Z_Construct_UScriptStruct_FJMJumpScarePlayContext();
JMJUMPSCARE_API UScriptStruct* Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState();
UPackage* Z_Construct_UPackage__Script_JMJumpScare();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EJMJumpScareSpawnMode *****************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMJumpScareSpawnMode;
static UEnum* EJMJumpScareSpawnMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMJumpScareSpawnMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMJumpScareSpawnMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMJumpScare_EJMJumpScareSpawnMode, (UObject*)Z_Construct_UPackage__Script_JMJumpScare(), TEXT("EJMJumpScareSpawnMode"));
	}
	return Z_Registration_Info_UEnum_EJMJumpScareSpawnMode.OuterSingleton;
}
template<> JMJUMPSCARE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMJumpScareSpawnMode>()
{
	return EJMJumpScareSpawnMode_StaticEnum();
}
struct Z_Construct_UEnum_JMJumpScare_EJMJumpScareSpawnMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CameraRelative.Name", "EJMJumpScareSpawnMode::CameraRelative" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
		{ "WorldAnchor.Name", "EJMJumpScareSpawnMode::WorldAnchor" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMJumpScareSpawnMode::WorldAnchor", (int64)EJMJumpScareSpawnMode::WorldAnchor },
		{ "EJMJumpScareSpawnMode::CameraRelative", (int64)EJMJumpScareSpawnMode::CameraRelative },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMJumpScare_EJMJumpScareSpawnMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMJumpScare_EJMJumpScareSpawnMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMJumpScare,
	nullptr,
	"EJMJumpScareSpawnMode",
	"EJMJumpScareSpawnMode",
	Z_Construct_UEnum_JMJumpScare_EJMJumpScareSpawnMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMJumpScare_EJMJumpScareSpawnMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMJumpScare_EJMJumpScareSpawnMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMJumpScare_EJMJumpScareSpawnMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScareSpawnMode()
{
	if (!Z_Registration_Info_UEnum_EJMJumpScareSpawnMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMJumpScareSpawnMode.InnerSingleton, Z_Construct_UEnum_JMJumpScare_EJMJumpScareSpawnMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMJumpScareSpawnMode.InnerSingleton;
}
// ********** End Enum EJMJumpScareSpawnMode *******************************************************

// ********** Begin Enum EJMJumpScarePresentationMode **********************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMJumpScarePresentationMode;
static UEnum* EJMJumpScarePresentationMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMJumpScarePresentationMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMJumpScarePresentationMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMJumpScare_EJMJumpScarePresentationMode, (UObject*)Z_Construct_UPackage__Script_JMJumpScare(), TEXT("EJMJumpScarePresentationMode"));
	}
	return Z_Registration_Info_UEnum_EJMJumpScarePresentationMode.OuterSingleton;
}
template<> JMJUMPSCARE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMJumpScarePresentationMode>()
{
	return EJMJumpScarePresentationMode_StaticEnum();
}
struct Z_Construct_UEnum_JMJumpScare_EJMJumpScarePresentationMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CameraAttached.Name", "EJMJumpScarePresentationMode::CameraAttached" },
		{ "CameraRelative.Name", "EJMJumpScarePresentationMode::CameraRelative" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** UseLegacySpawnMode preserves every pre-1.1 Definition without asset migration. */" },
#endif
		{ "ForcedLookAt.Name", "EJMJumpScarePresentationMode::ForcedLookAt" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UseLegacySpawnMode preserves every pre-1.1 Definition without asset migration." },
#endif
		{ "UseLegacySpawnMode.Name", "EJMJumpScarePresentationMode::UseLegacySpawnMode" },
		{ "WorldActor.Name", "EJMJumpScarePresentationMode::WorldActor" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMJumpScarePresentationMode::UseLegacySpawnMode", (int64)EJMJumpScarePresentationMode::UseLegacySpawnMode },
		{ "EJMJumpScarePresentationMode::WorldActor", (int64)EJMJumpScarePresentationMode::WorldActor },
		{ "EJMJumpScarePresentationMode::CameraRelative", (int64)EJMJumpScarePresentationMode::CameraRelative },
		{ "EJMJumpScarePresentationMode::CameraAttached", (int64)EJMJumpScarePresentationMode::CameraAttached },
		{ "EJMJumpScarePresentationMode::ForcedLookAt", (int64)EJMJumpScarePresentationMode::ForcedLookAt },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMJumpScare_EJMJumpScarePresentationMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMJumpScare_EJMJumpScarePresentationMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMJumpScare,
	nullptr,
	"EJMJumpScarePresentationMode",
	"EJMJumpScarePresentationMode",
	Z_Construct_UEnum_JMJumpScare_EJMJumpScarePresentationMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMJumpScare_EJMJumpScarePresentationMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMJumpScare_EJMJumpScarePresentationMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMJumpScare_EJMJumpScarePresentationMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScarePresentationMode()
{
	if (!Z_Registration_Info_UEnum_EJMJumpScarePresentationMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMJumpScarePresentationMode.InnerSingleton, Z_Construct_UEnum_JMJumpScare_EJMJumpScarePresentationMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMJumpScarePresentationMode.InnerSingleton;
}
// ********** End Enum EJMJumpScarePresentationMode ************************************************

// ********** Begin Enum EJMJumpScarePhase *********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMJumpScarePhase;
static UEnum* EJMJumpScarePhase_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMJumpScarePhase.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMJumpScarePhase.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMJumpScare_EJMJumpScarePhase, (UObject*)Z_Construct_UPackage__Script_JMJumpScare(), TEXT("EJMJumpScarePhase"));
	}
	return Z_Registration_Info_UEnum_EJMJumpScarePhase.OuterSingleton;
}
template<> JMJUMPSCARE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMJumpScarePhase>()
{
	return EJMJumpScarePhase_StaticEnum();
}
struct Z_Construct_UEnum_JMJumpScare_EJMJumpScarePhase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Entering.Name", "EJMJumpScarePhase::Entering" },
		{ "Exiting.Name", "EJMJumpScarePhase::Exiting" },
		{ "Finishing.Name", "EJMJumpScarePhase::Finishing" },
		{ "Holding.Name", "EJMJumpScarePhase::Holding" },
		{ "Idle.Name", "EJMJumpScarePhase::Idle" },
		{ "Impact.Name", "EJMJumpScarePhase::Impact" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
		{ "Preparing.Name", "EJMJumpScarePhase::Preparing" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMJumpScarePhase::Idle", (int64)EJMJumpScarePhase::Idle },
		{ "EJMJumpScarePhase::Preparing", (int64)EJMJumpScarePhase::Preparing },
		{ "EJMJumpScarePhase::Entering", (int64)EJMJumpScarePhase::Entering },
		{ "EJMJumpScarePhase::Impact", (int64)EJMJumpScarePhase::Impact },
		{ "EJMJumpScarePhase::Holding", (int64)EJMJumpScarePhase::Holding },
		{ "EJMJumpScarePhase::Exiting", (int64)EJMJumpScarePhase::Exiting },
		{ "EJMJumpScarePhase::Finishing", (int64)EJMJumpScarePhase::Finishing },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMJumpScare_EJMJumpScarePhase_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMJumpScare_EJMJumpScarePhase_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMJumpScare,
	nullptr,
	"EJMJumpScarePhase",
	"EJMJumpScarePhase",
	Z_Construct_UEnum_JMJumpScare_EJMJumpScarePhase_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMJumpScare_EJMJumpScarePhase_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMJumpScare_EJMJumpScarePhase_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMJumpScare_EJMJumpScarePhase_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScarePhase()
{
	if (!Z_Registration_Info_UEnum_EJMJumpScarePhase.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMJumpScarePhase.InnerSingleton, Z_Construct_UEnum_JMJumpScare_EJMJumpScarePhase_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMJumpScarePhase.InnerSingleton;
}
// ********** End Enum EJMJumpScarePhase ***********************************************************

// ********** Begin Enum EJMJumpScareCameraControlMode *********************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMJumpScareCameraControlMode;
static UEnum* EJMJumpScareCameraControlMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMJumpScareCameraControlMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMJumpScareCameraControlMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMJumpScare_EJMJumpScareCameraControlMode, (UObject*)Z_Construct_UPackage__Script_JMJumpScare(), TEXT("EJMJumpScareCameraControlMode"));
	}
	return Z_Registration_Info_UEnum_EJMJumpScareCameraControlMode.OuterSingleton;
}
template<> JMJUMPSCARE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMJumpScareCameraControlMode>()
{
	return EJMJumpScareCameraControlMode_StaticEnum();
}
struct Z_Construct_UEnum_JMJumpScare_EJMJumpScareCameraControlMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "LockCurrentView.Name", "EJMJumpScareCameraControlMode::LockCurrentView" },
		{ "LookAtActor.Name", "EJMJumpScareCameraControlMode::LookAtActor" },
		{ "LookAtFocusPoint.Name", "EJMJumpScareCameraControlMode::LookAtFocusPoint" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
		{ "None.Name", "EJMJumpScareCameraControlMode::None" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMJumpScareCameraControlMode::None", (int64)EJMJumpScareCameraControlMode::None },
		{ "EJMJumpScareCameraControlMode::LockCurrentView", (int64)EJMJumpScareCameraControlMode::LockCurrentView },
		{ "EJMJumpScareCameraControlMode::LookAtActor", (int64)EJMJumpScareCameraControlMode::LookAtActor },
		{ "EJMJumpScareCameraControlMode::LookAtFocusPoint", (int64)EJMJumpScareCameraControlMode::LookAtFocusPoint },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMJumpScare_EJMJumpScareCameraControlMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMJumpScare_EJMJumpScareCameraControlMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMJumpScare,
	nullptr,
	"EJMJumpScareCameraControlMode",
	"EJMJumpScareCameraControlMode",
	Z_Construct_UEnum_JMJumpScare_EJMJumpScareCameraControlMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMJumpScare_EJMJumpScareCameraControlMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMJumpScare_EJMJumpScareCameraControlMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMJumpScare_EJMJumpScareCameraControlMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScareCameraControlMode()
{
	if (!Z_Registration_Info_UEnum_EJMJumpScareCameraControlMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMJumpScareCameraControlMode.InnerSingleton, Z_Construct_UEnum_JMJumpScare_EJMJumpScareCameraControlMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMJumpScareCameraControlMode.InnerSingleton;
}
// ********** End Enum EJMJumpScareCameraControlMode ***********************************************

// ********** Begin Enum EJMJumpScareVanishMode ****************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMJumpScareVanishMode;
static UEnum* EJMJumpScareVanishMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMJumpScareVanishMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMJumpScareVanishMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMJumpScare_EJMJumpScareVanishMode, (UObject*)Z_Construct_UPackage__Script_JMJumpScare(), TEXT("EJMJumpScareVanishMode"));
	}
	return Z_Registration_Info_UEnum_EJMJumpScareVanishMode.OuterSingleton;
}
template<> JMJUMPSCARE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMJumpScareVanishMode>()
{
	return EJMJumpScareVanishMode_StaticEnum();
}
struct Z_Construct_UEnum_JMJumpScare_EJMJumpScareVanishMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "InstantHide.Name", "EJMJumpScareVanishMode::InstantHide" },
		{ "InterfaceDriven.Name", "EJMJumpScareVanishMode::InterfaceDriven" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
		{ "None.Name", "EJMJumpScareVanishMode::None" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMJumpScareVanishMode::None", (int64)EJMJumpScareVanishMode::None },
		{ "EJMJumpScareVanishMode::InstantHide", (int64)EJMJumpScareVanishMode::InstantHide },
		{ "EJMJumpScareVanishMode::InterfaceDriven", (int64)EJMJumpScareVanishMode::InterfaceDriven },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMJumpScare_EJMJumpScareVanishMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMJumpScare_EJMJumpScareVanishMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMJumpScare,
	nullptr,
	"EJMJumpScareVanishMode",
	"EJMJumpScareVanishMode",
	Z_Construct_UEnum_JMJumpScare_EJMJumpScareVanishMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMJumpScare_EJMJumpScareVanishMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMJumpScare_EJMJumpScareVanishMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMJumpScare_EJMJumpScareVanishMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScareVanishMode()
{
	if (!Z_Registration_Info_UEnum_EJMJumpScareVanishMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMJumpScareVanishMode.InnerSingleton, Z_Construct_UEnum_JMJumpScare_EJMJumpScareVanishMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMJumpScareVanishMode.InnerSingleton;
}
// ********** End Enum EJMJumpScareVanishMode ******************************************************

// ********** Begin Enum EJMJumpScareTriggerPolicy *************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMJumpScareTriggerPolicy;
static UEnum* EJMJumpScareTriggerPolicy_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMJumpScareTriggerPolicy.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMJumpScareTriggerPolicy.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMJumpScare_EJMJumpScareTriggerPolicy, (UObject*)Z_Construct_UPackage__Script_JMJumpScare(), TEXT("EJMJumpScareTriggerPolicy"));
	}
	return Z_Registration_Info_UEnum_EJMJumpScareTriggerPolicy.OuterSingleton;
}
template<> JMJUMPSCARE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMJumpScareTriggerPolicy>()
{
	return EJMJumpScareTriggerPolicy_StaticEnum();
}
struct Z_Construct_UEnum_JMJumpScare_EJMJumpScareTriggerPolicy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
		{ "Once.Name", "EJMJumpScareTriggerPolicy::Once" },
		{ "Repeatable.Name", "EJMJumpScareTriggerPolicy::Repeatable" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMJumpScareTriggerPolicy::Once", (int64)EJMJumpScareTriggerPolicy::Once },
		{ "EJMJumpScareTriggerPolicy::Repeatable", (int64)EJMJumpScareTriggerPolicy::Repeatable },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMJumpScare_EJMJumpScareTriggerPolicy_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMJumpScare_EJMJumpScareTriggerPolicy_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMJumpScare,
	nullptr,
	"EJMJumpScareTriggerPolicy",
	"EJMJumpScareTriggerPolicy",
	Z_Construct_UEnum_JMJumpScare_EJMJumpScareTriggerPolicy_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMJumpScare_EJMJumpScareTriggerPolicy_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMJumpScare_EJMJumpScareTriggerPolicy_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMJumpScare_EJMJumpScareTriggerPolicy_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScareTriggerPolicy()
{
	if (!Z_Registration_Info_UEnum_EJMJumpScareTriggerPolicy.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMJumpScareTriggerPolicy.InnerSingleton, Z_Construct_UEnum_JMJumpScare_EJMJumpScareTriggerPolicy_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMJumpScareTriggerPolicy.InnerSingleton;
}
// ********** End Enum EJMJumpScareTriggerPolicy ***************************************************

// ********** Begin Enum EJMJumpScareConcurrentPolicy **********************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMJumpScareConcurrentPolicy;
static UEnum* EJMJumpScareConcurrentPolicy_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMJumpScareConcurrentPolicy.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMJumpScareConcurrentPolicy.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMJumpScare_EJMJumpScareConcurrentPolicy, (UObject*)Z_Construct_UPackage__Script_JMJumpScare(), TEXT("EJMJumpScareConcurrentPolicy"));
	}
	return Z_Registration_Info_UEnum_EJMJumpScareConcurrentPolicy.OuterSingleton;
}
template<> JMJUMPSCARE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMJumpScareConcurrentPolicy>()
{
	return EJMJumpScareConcurrentPolicy_StaticEnum();
}
struct Z_Construct_UEnum_JMJumpScare_EJMJumpScareConcurrentPolicy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IgnoreNew.Name", "EJMJumpScareConcurrentPolicy::IgnoreNew" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMJumpScareConcurrentPolicy::IgnoreNew", (int64)EJMJumpScareConcurrentPolicy::IgnoreNew },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMJumpScare_EJMJumpScareConcurrentPolicy_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMJumpScare_EJMJumpScareConcurrentPolicy_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMJumpScare,
	nullptr,
	"EJMJumpScareConcurrentPolicy",
	"EJMJumpScareConcurrentPolicy",
	Z_Construct_UEnum_JMJumpScare_EJMJumpScareConcurrentPolicy_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMJumpScare_EJMJumpScareConcurrentPolicy_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMJumpScare_EJMJumpScareConcurrentPolicy_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMJumpScare_EJMJumpScareConcurrentPolicy_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScareConcurrentPolicy()
{
	if (!Z_Registration_Info_UEnum_EJMJumpScareConcurrentPolicy.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMJumpScareConcurrentPolicy.InnerSingleton, Z_Construct_UEnum_JMJumpScare_EJMJumpScareConcurrentPolicy_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMJumpScareConcurrentPolicy.InnerSingleton;
}
// ********** End Enum EJMJumpScareConcurrentPolicy ************************************************

// ********** Begin Enum EJMJumpScareOverlapFilter *************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMJumpScareOverlapFilter;
static UEnum* EJMJumpScareOverlapFilter_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMJumpScareOverlapFilter.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMJumpScareOverlapFilter.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMJumpScare_EJMJumpScareOverlapFilter, (UObject*)Z_Construct_UPackage__Script_JMJumpScare(), TEXT("EJMJumpScareOverlapFilter"));
	}
	return Z_Registration_Info_UEnum_EJMJumpScareOverlapFilter.OuterSingleton;
}
template<> JMJUMPSCARE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMJumpScareOverlapFilter>()
{
	return EJMJumpScareOverlapFilter_StaticEnum();
}
struct Z_Construct_UEnum_JMJumpScare_EJMJumpScareOverlapFilter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AnyPawn.Name", "EJMJumpScareOverlapFilter::AnyPawn" },
		{ "BlueprintType", "true" },
		{ "GameplayTags.Name", "EJMJumpScareOverlapFilter::GameplayTags" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
		{ "PlayerControlledPawn.Name", "EJMJumpScareOverlapFilter::PlayerControlledPawn" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMJumpScareOverlapFilter::PlayerControlledPawn", (int64)EJMJumpScareOverlapFilter::PlayerControlledPawn },
		{ "EJMJumpScareOverlapFilter::AnyPawn", (int64)EJMJumpScareOverlapFilter::AnyPawn },
		{ "EJMJumpScareOverlapFilter::GameplayTags", (int64)EJMJumpScareOverlapFilter::GameplayTags },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMJumpScare_EJMJumpScareOverlapFilter_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMJumpScare_EJMJumpScareOverlapFilter_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMJumpScare,
	nullptr,
	"EJMJumpScareOverlapFilter",
	"EJMJumpScareOverlapFilter",
	Z_Construct_UEnum_JMJumpScare_EJMJumpScareOverlapFilter_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMJumpScare_EJMJumpScareOverlapFilter_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMJumpScare_EJMJumpScareOverlapFilter_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMJumpScare_EJMJumpScareOverlapFilter_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScareOverlapFilter()
{
	if (!Z_Registration_Info_UEnum_EJMJumpScareOverlapFilter.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMJumpScareOverlapFilter.InnerSingleton, Z_Construct_UEnum_JMJumpScare_EJMJumpScareOverlapFilter_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMJumpScareOverlapFilter.InnerSingleton;
}
// ********** End Enum EJMJumpScareOverlapFilter ***************************************************

// ********** Begin Enum EJMJumpScareState *********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMJumpScareState;
static UEnum* EJMJumpScareState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMJumpScareState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMJumpScareState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMJumpScare_EJMJumpScareState, (UObject*)Z_Construct_UPackage__Script_JMJumpScare(), TEXT("EJMJumpScareState"));
	}
	return Z_Registration_Info_UEnum_EJMJumpScareState.OuterSingleton;
}
template<> JMJUMPSCARE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMJumpScareState>()
{
	return EJMJumpScareState_StaticEnum();
}
struct Z_Construct_UEnum_JMJumpScare_EJMJumpScareState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Finishing.Name", "EJMJumpScareState::Finishing" },
		{ "Idle.Name", "EJMJumpScareState::Idle" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
		{ "Playing.Name", "EJMJumpScareState::Playing" },
		{ "Waiting.Name", "EJMJumpScareState::Waiting" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMJumpScareState::Idle", (int64)EJMJumpScareState::Idle },
		{ "EJMJumpScareState::Waiting", (int64)EJMJumpScareState::Waiting },
		{ "EJMJumpScareState::Playing", (int64)EJMJumpScareState::Playing },
		{ "EJMJumpScareState::Finishing", (int64)EJMJumpScareState::Finishing },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMJumpScare_EJMJumpScareState_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMJumpScare_EJMJumpScareState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMJumpScare,
	nullptr,
	"EJMJumpScareState",
	"EJMJumpScareState",
	Z_Construct_UEnum_JMJumpScare_EJMJumpScareState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMJumpScare_EJMJumpScareState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMJumpScare_EJMJumpScareState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMJumpScare_EJMJumpScareState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScareState()
{
	if (!Z_Registration_Info_UEnum_EJMJumpScareState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMJumpScareState.InnerSingleton, Z_Construct_UEnum_JMJumpScare_EJMJumpScareState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMJumpScareState.InnerSingleton;
}
// ********** End Enum EJMJumpScareState ***********************************************************

// ********** Begin Enum EJMJumpScarePlayResult ****************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMJumpScarePlayResult;
static UEnum* EJMJumpScarePlayResult_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMJumpScarePlayResult.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMJumpScarePlayResult.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMJumpScare_EJMJumpScarePlayResult, (UObject*)Z_Construct_UPackage__Script_JMJumpScare(), TEXT("EJMJumpScarePlayResult"));
	}
	return Z_Registration_Info_UEnum_EJMJumpScarePlayResult.OuterSingleton;
}
template<> JMJUMPSCARE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMJumpScarePlayResult>()
{
	return EJMJumpScarePlayResult_StaticEnum();
}
struct Z_Construct_UEnum_JMJumpScare_EJMJumpScarePlayResult_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AlreadyPlaying.Name", "EJMJumpScarePlayResult::AlreadyPlaying" },
		{ "AlreadyTriggered.Name", "EJMJumpScarePlayResult::AlreadyTriggered" },
		{ "BlueprintType", "true" },
		{ "InvalidActorClass.Name", "EJMJumpScarePlayResult::InvalidActorClass" },
		{ "InvalidDefinition.Name", "EJMJumpScarePlayResult::InvalidDefinition" },
		{ "InvalidWorld.Name", "EJMJumpScarePlayResult::InvalidWorld" },
		{ "MissingAnchor.Name", "EJMJumpScarePlayResult::MissingAnchor" },
		{ "MissingCamera.Name", "EJMJumpScarePlayResult::MissingCamera" },
		{ "MissingImage.Name", "EJMJumpScarePlayResult::MissingImage" },
		{ "MissingTargetPlayer.Name", "EJMJumpScarePlayResult::MissingTargetPlayer" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
		{ "SpawnFailed.Name", "EJMJumpScarePlayResult::SpawnFailed" },
		{ "Started.Name", "EJMJumpScarePlayResult::Started" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMJumpScarePlayResult::Started", (int64)EJMJumpScarePlayResult::Started },
		{ "EJMJumpScarePlayResult::AlreadyPlaying", (int64)EJMJumpScarePlayResult::AlreadyPlaying },
		{ "EJMJumpScarePlayResult::AlreadyTriggered", (int64)EJMJumpScarePlayResult::AlreadyTriggered },
		{ "EJMJumpScarePlayResult::InvalidWorld", (int64)EJMJumpScarePlayResult::InvalidWorld },
		{ "EJMJumpScarePlayResult::InvalidDefinition", (int64)EJMJumpScarePlayResult::InvalidDefinition },
		{ "EJMJumpScarePlayResult::MissingImage", (int64)EJMJumpScarePlayResult::MissingImage },
		{ "EJMJumpScarePlayResult::InvalidActorClass", (int64)EJMJumpScarePlayResult::InvalidActorClass },
		{ "EJMJumpScarePlayResult::MissingAnchor", (int64)EJMJumpScarePlayResult::MissingAnchor },
		{ "EJMJumpScarePlayResult::MissingTargetPlayer", (int64)EJMJumpScarePlayResult::MissingTargetPlayer },
		{ "EJMJumpScarePlayResult::MissingCamera", (int64)EJMJumpScarePlayResult::MissingCamera },
		{ "EJMJumpScarePlayResult::SpawnFailed", (int64)EJMJumpScarePlayResult::SpawnFailed },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMJumpScare_EJMJumpScarePlayResult_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMJumpScare_EJMJumpScarePlayResult_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMJumpScare,
	nullptr,
	"EJMJumpScarePlayResult",
	"EJMJumpScarePlayResult",
	Z_Construct_UEnum_JMJumpScare_EJMJumpScarePlayResult_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMJumpScare_EJMJumpScarePlayResult_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMJumpScare_EJMJumpScarePlayResult_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMJumpScare_EJMJumpScarePlayResult_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScarePlayResult()
{
	if (!Z_Registration_Info_UEnum_EJMJumpScarePlayResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMJumpScarePlayResult.InnerSingleton, Z_Construct_UEnum_JMJumpScare_EJMJumpScarePlayResult_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMJumpScarePlayResult.InnerSingleton;
}
// ********** End Enum EJMJumpScarePlayResult ******************************************************

// ********** Begin ScriptStruct FJMJumpScarePlayContext *******************************************
struct Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMJumpScarePlayContext); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMJumpScarePlayContext); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Runtime-only inputs. Persistent design data belongs to UJMJumpScareDefinition. */" },
#endif
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Runtime-only inputs. Persistent design data belongs to UJMJumpScareDefinition." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "Category", "JM JumpScare | Context" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
		{ "WorldContext", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Instigator_MetaData[] = {
		{ "Category", "JM JumpScare | Context" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetPlayer_MetaData[] = {
		{ "Category", "JM JumpScare | Context" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Anchor_MetaData[] = {
		{ "Category", "JM JumpScare | Context" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FocusTarget_MetaData[] = {
		{ "Category", "JM JumpScare | Context" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional existing world Actor used by ForcedLookAt. Its focus component is preferred when present. */" },
#endif
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional existing world Actor used by ForcedLookAt. Its focus component is preferred when present." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideSpawnTransform_MetaData[] = {
		{ "Category", "JM JumpScare | Context" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnTransformOverride_MetaData[] = {
		{ "Category", "JM JumpScare | Context" },
		{ "EditCondition", "bOverrideSpawnTransform" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Source_MetaData[] = {
		{ "Category", "JM JumpScare | Context" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContextTags_MetaData[] = {
		{ "Category", "JM JumpScare | Context" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideTriggerPolicy_MetaData[] = {
		{ "Category", "JM JumpScare | Context" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TriggerPolicyOverride_MetaData[] = {
		{ "Category", "JM JumpScare | Context" },
		{ "EditCondition", "bOverrideTriggerPolicy" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMJumpScarePlayContext constinit property declarations ***********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Instigator;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetPlayer;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Anchor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FocusTarget;
	static void NewProp_bOverrideSpawnTransform_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideSpawnTransform;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnTransformOverride;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Source;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ContextTags;
	static void NewProp_bOverrideTriggerPolicy_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideTriggerPolicy;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TriggerPolicyOverride_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TriggerPolicyOverride;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMJumpScarePlayContext constinit property declarations *************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMJumpScarePlayContext>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMJumpScarePlayContext;
class UScriptStruct* FJMJumpScarePlayContext::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMJumpScarePlayContext.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMJumpScarePlayContext.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMJumpScarePlayContext, (UObject*)Z_Construct_UPackage__Script_JMJumpScare(), TEXT("JMJumpScarePlayContext"));
	}
	return Z_Registration_Info_UScriptStruct_FJMJumpScarePlayContext.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMJumpScarePlayContext Property Definitions **********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMJumpScarePlayContext, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMJumpScarePlayContext, Instigator), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Instigator_MetaData), NewProp_Instigator_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_TargetPlayer = { "TargetPlayer", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMJumpScarePlayContext, TargetPlayer), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetPlayer_MetaData), NewProp_TargetPlayer_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_Anchor = { "Anchor", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMJumpScarePlayContext, Anchor), Z_Construct_UClass_AJMJumpScareAnchor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Anchor_MetaData), NewProp_Anchor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_FocusTarget = { "FocusTarget", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMJumpScarePlayContext, FocusTarget), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FocusTarget_MetaData), NewProp_FocusTarget_MetaData) };
void Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_bOverrideSpawnTransform_SetBit(void* Obj)
{
	((FJMJumpScarePlayContext*)Obj)->bOverrideSpawnTransform = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_bOverrideSpawnTransform = { "bOverrideSpawnTransform", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMJumpScarePlayContext), &Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_bOverrideSpawnTransform_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideSpawnTransform_MetaData), NewProp_bOverrideSpawnTransform_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_SpawnTransformOverride = { "SpawnTransformOverride", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMJumpScarePlayContext, SpawnTransformOverride), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnTransformOverride_MetaData), NewProp_SpawnTransformOverride_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_Source = { "Source", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMJumpScarePlayContext, Source), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Source_MetaData), NewProp_Source_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_ContextTags = { "ContextTags", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMJumpScarePlayContext, ContextTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContextTags_MetaData), NewProp_ContextTags_MetaData) }; // 3438578166
void Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_bOverrideTriggerPolicy_SetBit(void* Obj)
{
	((FJMJumpScarePlayContext*)Obj)->bOverrideTriggerPolicy = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_bOverrideTriggerPolicy = { "bOverrideTriggerPolicy", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMJumpScarePlayContext), &Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_bOverrideTriggerPolicy_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideTriggerPolicy_MetaData), NewProp_bOverrideTriggerPolicy_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_TriggerPolicyOverride_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_TriggerPolicyOverride = { "TriggerPolicyOverride", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMJumpScarePlayContext, TriggerPolicyOverride), Z_Construct_UEnum_JMJumpScare_EJMJumpScareTriggerPolicy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TriggerPolicyOverride_MetaData), NewProp_TriggerPolicyOverride_MetaData) }; // 453019027
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_Instigator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_TargetPlayer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_Anchor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_FocusTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_bOverrideSpawnTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_SpawnTransformOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_Source,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_ContextTags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_bOverrideTriggerPolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_TriggerPolicyOverride_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewProp_TriggerPolicyOverride,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMJumpScarePlayContext Property Definitions ************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMJumpScare,
	nullptr,
	&NewStructOps,
	"JMJumpScarePlayContext",
	Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::PropPointers),
	sizeof(FJMJumpScarePlayContext),
	alignof(FJMJumpScarePlayContext),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMJumpScarePlayContext()
{
	if (!Z_Registration_Info_UScriptStruct_FJMJumpScarePlayContext.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMJumpScarePlayContext.InnerSingleton, Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMJumpScarePlayContext.InnerSingleton);
}
// ********** End ScriptStruct FJMJumpScarePlayContext *********************************************

// ********** Begin ScriptStruct FJMJumpScareActiveInfo ********************************************
struct Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMJumpScareActiveInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMJumpScareActiveInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_State_MetaData[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Phase_MetaData[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpScareId_MetaData[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnedActor_MetaData[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Anchor_MetaData[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMJumpScareActiveInfo constinit property declarations ************
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Phase_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Phase;
	static const UECodeGen_Private::FStructPropertyParams NewProp_JumpScareId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawnedActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Anchor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMJumpScareActiveInfo constinit property declarations **************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMJumpScareActiveInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMJumpScareActiveInfo;
class UScriptStruct* FJMJumpScareActiveInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMJumpScareActiveInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMJumpScareActiveInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMJumpScareActiveInfo, (UObject*)Z_Construct_UPackage__Script_JMJumpScare(), TEXT("JMJumpScareActiveInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FJMJumpScareActiveInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMJumpScareActiveInfo Property Definitions ***********************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMJumpScareActiveInfo, State), Z_Construct_UEnum_JMJumpScare_EJMJumpScareState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_State_MetaData), NewProp_State_MetaData) }; // 595493008
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics::NewProp_Phase_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics::NewProp_Phase = { "Phase", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMJumpScareActiveInfo, Phase), Z_Construct_UEnum_JMJumpScare_EJMJumpScarePhase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Phase_MetaData), NewProp_Phase_MetaData) }; // 3098439532
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics::NewProp_JumpScareId = { "JumpScareId", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMJumpScareActiveInfo, JumpScareId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpScareId_MetaData), NewProp_JumpScareId_MetaData) }; // 517357616
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics::NewProp_SpawnedActor = { "SpawnedActor", nullptr, (EPropertyFlags)0x0114000000020015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMJumpScareActiveInfo, SpawnedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnedActor_MetaData), NewProp_SpawnedActor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics::NewProp_Anchor = { "Anchor", nullptr, (EPropertyFlags)0x0114000000020015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMJumpScareActiveInfo, Anchor), Z_Construct_UClass_AJMJumpScareAnchor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Anchor_MetaData), NewProp_Anchor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics::NewProp_State,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics::NewProp_Phase_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics::NewProp_Phase,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics::NewProp_JumpScareId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics::NewProp_SpawnedActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics::NewProp_Anchor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMJumpScareActiveInfo Property Definitions *************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMJumpScare,
	nullptr,
	&NewStructOps,
	"JMJumpScareActiveInfo",
	Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics::PropPointers),
	sizeof(FJMJumpScareActiveInfo),
	alignof(FJMJumpScareActiveInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMJumpScareActiveInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FJMJumpScareActiveInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMJumpScareActiveInfo.InnerSingleton, Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMJumpScareActiveInfo.InnerSingleton);
}
// ********** End ScriptStruct FJMJumpScareActiveInfo **********************************************

// ********** Begin ScriptStruct FJMJumpScareAudioEvent ********************************************
struct Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMJumpScareAudioEvent); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMJumpScareAudioEvent); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Sound_MetaData[] = {
		{ "Category", "JM JumpScare | Audio" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Phase_MetaData[] = {
		{ "Category", "JM JumpScare | Audio" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Delay_MetaData[] = {
		{ "Category", "JM JumpScare | Audio" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VolumeMultiplier_MetaData[] = {
		{ "Category", "JM JumpScare | Audio" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PitchMultiplier_MetaData[] = {
		{ "Category", "JM JumpScare | Audio" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMJumpScareAudioEvent constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Sound;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Phase_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Phase;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Delay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VolumeMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PitchMultiplier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMJumpScareAudioEvent constinit property declarations **************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMJumpScareAudioEvent>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMJumpScareAudioEvent;
class UScriptStruct* FJMJumpScareAudioEvent::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMJumpScareAudioEvent.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMJumpScareAudioEvent.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMJumpScareAudioEvent, (UObject*)Z_Construct_UPackage__Script_JMJumpScare(), TEXT("JMJumpScareAudioEvent"));
	}
	return Z_Registration_Info_UScriptStruct_FJMJumpScareAudioEvent.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMJumpScareAudioEvent Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics::NewProp_Sound = { "Sound", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMJumpScareAudioEvent, Sound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Sound_MetaData), NewProp_Sound_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics::NewProp_Phase_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics::NewProp_Phase = { "Phase", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMJumpScareAudioEvent, Phase), Z_Construct_UEnum_JMJumpScare_EJMJumpScarePhase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Phase_MetaData), NewProp_Phase_MetaData) }; // 3098439532
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics::NewProp_Delay = { "Delay", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMJumpScareAudioEvent, Delay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Delay_MetaData), NewProp_Delay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics::NewProp_VolumeMultiplier = { "VolumeMultiplier", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMJumpScareAudioEvent, VolumeMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VolumeMultiplier_MetaData), NewProp_VolumeMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics::NewProp_PitchMultiplier = { "PitchMultiplier", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMJumpScareAudioEvent, PitchMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PitchMultiplier_MetaData), NewProp_PitchMultiplier_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics::NewProp_Sound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics::NewProp_Phase_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics::NewProp_Phase,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics::NewProp_Delay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics::NewProp_VolumeMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics::NewProp_PitchMultiplier,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMJumpScareAudioEvent Property Definitions *************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMJumpScare,
	nullptr,
	&NewStructOps,
	"JMJumpScareAudioEvent",
	Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics::PropPointers),
	sizeof(FJMJumpScareAudioEvent),
	alignof(FJMJumpScareAudioEvent),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMJumpScareAudioEvent()
{
	if (!Z_Registration_Info_UScriptStruct_FJMJumpScareAudioEvent.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMJumpScareAudioEvent.InnerSingleton, Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMJumpScareAudioEvent.InnerSingleton);
}
// ********** End ScriptStruct FJMJumpScareAudioEvent **********************************************

// ********** Begin ScriptStruct FJMJumpScareTriggerSaveState **************************************
struct Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMJumpScareTriggerSaveState); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMJumpScareTriggerSaveState); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TriggerId_MetaData[] = {
		{ "Category", "JM JumpScare | Save" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasTriggered_MetaData[] = {
		{ "Category", "JM JumpScare | Save" },
		{ "ModuleRelativePath", "Public/Types/JMJumpScareTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMJumpScareTriggerSaveState constinit property declarations ******
	static const UECodeGen_Private::FStructPropertyParams NewProp_TriggerId;
	static void NewProp_bHasTriggered_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasTriggered;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMJumpScareTriggerSaveState constinit property declarations ********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMJumpScareTriggerSaveState>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMJumpScareTriggerSaveState;
class UScriptStruct* FJMJumpScareTriggerSaveState::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMJumpScareTriggerSaveState.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMJumpScareTriggerSaveState.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState, (UObject*)Z_Construct_UPackage__Script_JMJumpScare(), TEXT("JMJumpScareTriggerSaveState"));
	}
	return Z_Registration_Info_UScriptStruct_FJMJumpScareTriggerSaveState.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMJumpScareTriggerSaveState Property Definitions *****************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState_Statics::NewProp_TriggerId = { "TriggerId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMJumpScareTriggerSaveState, TriggerId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TriggerId_MetaData), NewProp_TriggerId_MetaData) }; // 517357616
void Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState_Statics::NewProp_bHasTriggered_SetBit(void* Obj)
{
	((FJMJumpScareTriggerSaveState*)Obj)->bHasTriggered = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState_Statics::NewProp_bHasTriggered = { "bHasTriggered", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMJumpScareTriggerSaveState), &Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState_Statics::NewProp_bHasTriggered_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasTriggered_MetaData), NewProp_bHasTriggered_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState_Statics::NewProp_TriggerId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState_Statics::NewProp_bHasTriggered,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMJumpScareTriggerSaveState Property Definitions *******************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMJumpScare,
	nullptr,
	&NewStructOps,
	"JMJumpScareTriggerSaveState",
	Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState_Statics::PropPointers),
	sizeof(FJMJumpScareTriggerSaveState),
	alignof(FJMJumpScareTriggerSaveState),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState()
{
	if (!Z_Registration_Info_UScriptStruct_FJMJumpScareTriggerSaveState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMJumpScareTriggerSaveState.InnerSingleton, Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMJumpScareTriggerSaveState.InnerSingleton);
}
// ********** End ScriptStruct FJMJumpScareTriggerSaveState ****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Types_JMJumpScareTypes_h__Script_JMJumpScare_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EJMJumpScareSpawnMode_StaticEnum, TEXT("EJMJumpScareSpawnMode"), &Z_Registration_Info_UEnum_EJMJumpScareSpawnMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 298533388U) },
		{ EJMJumpScarePresentationMode_StaticEnum, TEXT("EJMJumpScarePresentationMode"), &Z_Registration_Info_UEnum_EJMJumpScarePresentationMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 936040111U) },
		{ EJMJumpScarePhase_StaticEnum, TEXT("EJMJumpScarePhase"), &Z_Registration_Info_UEnum_EJMJumpScarePhase, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3098439532U) },
		{ EJMJumpScareCameraControlMode_StaticEnum, TEXT("EJMJumpScareCameraControlMode"), &Z_Registration_Info_UEnum_EJMJumpScareCameraControlMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1250972642U) },
		{ EJMJumpScareVanishMode_StaticEnum, TEXT("EJMJumpScareVanishMode"), &Z_Registration_Info_UEnum_EJMJumpScareVanishMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 386264693U) },
		{ EJMJumpScareTriggerPolicy_StaticEnum, TEXT("EJMJumpScareTriggerPolicy"), &Z_Registration_Info_UEnum_EJMJumpScareTriggerPolicy, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 453019027U) },
		{ EJMJumpScareConcurrentPolicy_StaticEnum, TEXT("EJMJumpScareConcurrentPolicy"), &Z_Registration_Info_UEnum_EJMJumpScareConcurrentPolicy, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1198158541U) },
		{ EJMJumpScareOverlapFilter_StaticEnum, TEXT("EJMJumpScareOverlapFilter"), &Z_Registration_Info_UEnum_EJMJumpScareOverlapFilter, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2064440234U) },
		{ EJMJumpScareState_StaticEnum, TEXT("EJMJumpScareState"), &Z_Registration_Info_UEnum_EJMJumpScareState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 595493008U) },
		{ EJMJumpScarePlayResult_StaticEnum, TEXT("EJMJumpScarePlayResult"), &Z_Registration_Info_UEnum_EJMJumpScarePlayResult, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 453831882U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FJMJumpScarePlayContext::StaticStruct, Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics::NewStructOps, TEXT("JMJumpScarePlayContext"),&Z_Registration_Info_UScriptStruct_FJMJumpScarePlayContext, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMJumpScarePlayContext), 1435639080U) },
		{ FJMJumpScareActiveInfo::StaticStruct, Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics::NewStructOps, TEXT("JMJumpScareActiveInfo"),&Z_Registration_Info_UScriptStruct_FJMJumpScareActiveInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMJumpScareActiveInfo), 3165102511U) },
		{ FJMJumpScareAudioEvent::StaticStruct, Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics::NewStructOps, TEXT("JMJumpScareAudioEvent"),&Z_Registration_Info_UScriptStruct_FJMJumpScareAudioEvent, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMJumpScareAudioEvent), 2484698117U) },
		{ FJMJumpScareTriggerSaveState::StaticStruct, Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState_Statics::NewStructOps, TEXT("JMJumpScareTriggerSaveState"),&Z_Registration_Info_UScriptStruct_FJMJumpScareTriggerSaveState, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMJumpScareTriggerSaveState), 804623082U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Types_JMJumpScareTypes_h__Script_JMJumpScare_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Types_JMJumpScareTypes_h__Script_JMJumpScare_172974360{
	TEXT("/Script/JMJumpScare"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Types_JMJumpScareTypes_h__Script_JMJumpScare_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Types_JMJumpScareTypes_h__Script_JMJumpScare_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Types_JMJumpScareTypes_h__Script_JMJumpScare_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Types_JMJumpScareTypes_h__Script_JMJumpScare_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
