// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Types/JMReconTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMReconTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
JMRECONRUNTIME_API UEnum* Z_Construct_UEnum_JMReconRuntime_EJMReconEndReason();
JMRECONRUNTIME_API UEnum* Z_Construct_UEnum_JMReconRuntime_EJMReconFailureReason();
JMRECONRUNTIME_API UEnum* Z_Construct_UEnum_JMReconRuntime_EJMReconInitialObservationMode();
JMRECONRUNTIME_API UEnum* Z_Construct_UEnum_JMReconRuntime_EJMReconMode();
JMRECONRUNTIME_API UEnum* Z_Construct_UEnum_JMReconRuntime_EJMReconState();
JMRECONRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMReconNoiseEvent();
JMRECONRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMReconRequestResult();
JMRECONRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMReconSession();
UPackage* Z_Construct_UPackage__Script_JMReconRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EJMReconState *************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMReconState;
static UEnum* EJMReconState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMReconState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMReconState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMReconRuntime_EJMReconState, (UObject*)Z_Construct_UPackage__Script_JMReconRuntime(), TEXT("EJMReconState"));
	}
	return Z_Registration_Info_UEnum_EJMReconState.OuterSingleton;
}
template<> JMRECONRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMReconState>()
{
	return EJMReconState_StaticEnum();
}
struct Z_Construct_UEnum_JMReconRuntime_EJMReconState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Entering.Name", "EJMReconState::Entering" },
		{ "Exiting.Name", "EJMReconState::Exiting" },
		{ "Idle.Name", "EJMReconState::Idle" },
		{ "Listening.Name", "EJMReconState::Listening" },
		{ "ModuleRelativePath", "Public/Types/JMReconTypes.h" },
		{ "Peeking.Name", "EJMReconState::Peeking" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMReconState::Idle", (int64)EJMReconState::Idle },
		{ "EJMReconState::Entering", (int64)EJMReconState::Entering },
		{ "EJMReconState::Listening", (int64)EJMReconState::Listening },
		{ "EJMReconState::Peeking", (int64)EJMReconState::Peeking },
		{ "EJMReconState::Exiting", (int64)EJMReconState::Exiting },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMReconRuntime_EJMReconState_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMReconRuntime_EJMReconState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMReconRuntime,
	nullptr,
	"EJMReconState",
	"EJMReconState",
	Z_Construct_UEnum_JMReconRuntime_EJMReconState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMReconRuntime_EJMReconState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMReconRuntime_EJMReconState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMReconRuntime_EJMReconState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMReconRuntime_EJMReconState()
{
	if (!Z_Registration_Info_UEnum_EJMReconState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMReconState.InnerSingleton, Z_Construct_UEnum_JMReconRuntime_EJMReconState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMReconState.InnerSingleton;
}
// ********** End Enum EJMReconState ***************************************************************

// ********** Begin Enum EJMReconInitialObservationMode ********************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMReconInitialObservationMode;
static UEnum* EJMReconInitialObservationMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMReconInitialObservationMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMReconInitialObservationMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMReconRuntime_EJMReconInitialObservationMode, (UObject*)Z_Construct_UPackage__Script_JMReconRuntime(), TEXT("EJMReconInitialObservationMode"));
	}
	return Z_Registration_Info_UEnum_EJMReconInitialObservationMode.OuterSingleton;
}
template<> JMRECONRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMReconInitialObservationMode>()
{
	return EJMReconInitialObservationMode_StaticEnum();
}
struct Z_Construct_UEnum_JMReconRuntime_EJMReconInitialObservationMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Listen.Name", "EJMReconInitialObservationMode::Listen" },
		{ "ModuleRelativePath", "Public/Types/JMReconTypes.h" },
		{ "Peek.Name", "EJMReconInitialObservationMode::Peek" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMReconInitialObservationMode::Listen", (int64)EJMReconInitialObservationMode::Listen },
		{ "EJMReconInitialObservationMode::Peek", (int64)EJMReconInitialObservationMode::Peek },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMReconRuntime_EJMReconInitialObservationMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMReconRuntime_EJMReconInitialObservationMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMReconRuntime,
	nullptr,
	"EJMReconInitialObservationMode",
	"EJMReconInitialObservationMode",
	Z_Construct_UEnum_JMReconRuntime_EJMReconInitialObservationMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMReconRuntime_EJMReconInitialObservationMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMReconRuntime_EJMReconInitialObservationMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMReconRuntime_EJMReconInitialObservationMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMReconRuntime_EJMReconInitialObservationMode()
{
	if (!Z_Registration_Info_UEnum_EJMReconInitialObservationMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMReconInitialObservationMode.InnerSingleton, Z_Construct_UEnum_JMReconRuntime_EJMReconInitialObservationMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMReconInitialObservationMode.InnerSingleton;
}
// ********** End Enum EJMReconInitialObservationMode **********************************************

// ********** Begin Enum EJMReconMode **************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMReconMode;
static UEnum* EJMReconMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMReconMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMReconMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMReconRuntime_EJMReconMode, (UObject*)Z_Construct_UPackage__Script_JMReconRuntime(), TEXT("EJMReconMode"));
	}
	return Z_Registration_Info_UEnum_EJMReconMode.OuterSingleton;
}
template<> JMRECONRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMReconMode>()
{
	return EJMReconMode_StaticEnum();
}
struct Z_Construct_UEnum_JMReconRuntime_EJMReconMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Bitflags", "" },
		{ "BlueprintType", "true" },
		{ "Illuminate.Name", "EJMReconMode::Illuminate" },
		{ "Listen.Name", "EJMReconMode::Listen" },
		{ "ModuleRelativePath", "Public/Types/JMReconTypes.h" },
		{ "None.Name", "EJMReconMode::None" },
		{ "Peek.Name", "EJMReconMode::Peek" },
		{ "UseEnumValuesAsMaskValuesInEditor", "true" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMReconMode::None", (int64)EJMReconMode::None },
		{ "EJMReconMode::Listen", (int64)EJMReconMode::Listen },
		{ "EJMReconMode::Peek", (int64)EJMReconMode::Peek },
		{ "EJMReconMode::Illuminate", (int64)EJMReconMode::Illuminate },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMReconRuntime_EJMReconMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMReconRuntime_EJMReconMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMReconRuntime,
	nullptr,
	"EJMReconMode",
	"EJMReconMode",
	Z_Construct_UEnum_JMReconRuntime_EJMReconMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMReconRuntime_EJMReconMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMReconRuntime_EJMReconMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMReconRuntime_EJMReconMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMReconRuntime_EJMReconMode()
{
	if (!Z_Registration_Info_UEnum_EJMReconMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMReconMode.InnerSingleton, Z_Construct_UEnum_JMReconRuntime_EJMReconMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMReconMode.InnerSingleton;
}
// ********** End Enum EJMReconMode ****************************************************************

// ********** Begin Enum EJMReconFailureReason *****************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMReconFailureReason;
static UEnum* EJMReconFailureReason_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMReconFailureReason.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMReconFailureReason.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMReconRuntime_EJMReconFailureReason, (UObject*)Z_Construct_UPackage__Script_JMReconRuntime(), TEXT("EJMReconFailureReason"));
	}
	return Z_Registration_Info_UEnum_EJMReconFailureReason.OuterSingleton;
}
template<> JMRECONRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMReconFailureReason>()
{
	return EJMReconFailureReason_StaticEnum();
}
struct Z_Construct_UEnum_JMReconRuntime_EJMReconFailureReason_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AlreadyActive.Name", "EJMReconFailureReason::AlreadyActive" },
		{ "AlreadyInUse.Name", "EJMReconFailureReason::AlreadyInUse" },
		{ "Blocked.Name", "EJMReconFailureReason::Blocked" },
		{ "BlueprintType", "true" },
		{ "DefinitionInvalid.Name", "EJMReconFailureReason::DefinitionInvalid" },
		{ "Disabled.Name", "EJMReconFailureReason::Disabled" },
		{ "DoorMoving.Name", "EJMReconFailureReason::DoorMoving" },
		{ "DoorOpen.Name", "EJMReconFailureReason::DoorOpen" },
		{ "InvalidInteractor.Name", "EJMReconFailureReason::InvalidInteractor" },
		{ "InvalidState.Name", "EJMReconFailureReason::InvalidState" },
		{ "InvalidTarget.Name", "EJMReconFailureReason::InvalidTarget" },
		{ "ModuleRelativePath", "Public/Types/JMReconTypes.h" },
		{ "None.Name", "EJMReconFailureReason::None" },
		{ "NotSupported.Name", "EJMReconFailureReason::NotSupported" },
		{ "OutOfRange.Name", "EJMReconFailureReason::OutOfRange" },
		{ "TargetDestroyed.Name", "EJMReconFailureReason::TargetDestroyed" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMReconFailureReason::None", (int64)EJMReconFailureReason::None },
		{ "EJMReconFailureReason::AlreadyActive", (int64)EJMReconFailureReason::AlreadyActive },
		{ "EJMReconFailureReason::AlreadyInUse", (int64)EJMReconFailureReason::AlreadyInUse },
		{ "EJMReconFailureReason::InvalidInteractor", (int64)EJMReconFailureReason::InvalidInteractor },
		{ "EJMReconFailureReason::InvalidTarget", (int64)EJMReconFailureReason::InvalidTarget },
		{ "EJMReconFailureReason::TargetDestroyed", (int64)EJMReconFailureReason::TargetDestroyed },
		{ "EJMReconFailureReason::Disabled", (int64)EJMReconFailureReason::Disabled },
		{ "EJMReconFailureReason::OutOfRange", (int64)EJMReconFailureReason::OutOfRange },
		{ "EJMReconFailureReason::DoorOpen", (int64)EJMReconFailureReason::DoorOpen },
		{ "EJMReconFailureReason::DoorMoving", (int64)EJMReconFailureReason::DoorMoving },
		{ "EJMReconFailureReason::Blocked", (int64)EJMReconFailureReason::Blocked },
		{ "EJMReconFailureReason::NotSupported", (int64)EJMReconFailureReason::NotSupported },
		{ "EJMReconFailureReason::InvalidState", (int64)EJMReconFailureReason::InvalidState },
		{ "EJMReconFailureReason::DefinitionInvalid", (int64)EJMReconFailureReason::DefinitionInvalid },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMReconRuntime_EJMReconFailureReason_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMReconRuntime_EJMReconFailureReason_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMReconRuntime,
	nullptr,
	"EJMReconFailureReason",
	"EJMReconFailureReason",
	Z_Construct_UEnum_JMReconRuntime_EJMReconFailureReason_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMReconRuntime_EJMReconFailureReason_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMReconRuntime_EJMReconFailureReason_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMReconRuntime_EJMReconFailureReason_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMReconRuntime_EJMReconFailureReason()
{
	if (!Z_Registration_Info_UEnum_EJMReconFailureReason.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMReconFailureReason.InnerSingleton, Z_Construct_UEnum_JMReconRuntime_EJMReconFailureReason_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMReconFailureReason.InnerSingleton;
}
// ********** End Enum EJMReconFailureReason *******************************************************

// ********** Begin Enum EJMReconEndReason *********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMReconEndReason;
static UEnum* EJMReconEndReason_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMReconEndReason.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMReconEndReason.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMReconRuntime_EJMReconEndReason, (UObject*)Z_Construct_UPackage__Script_JMReconRuntime(), TEXT("EJMReconEndReason"));
	}
	return Z_Registration_Info_UEnum_EJMReconEndReason.OuterSingleton;
}
template<> JMRECONRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMReconEndReason>()
{
	return EJMReconEndReason_StaticEnum();
}
struct Z_Construct_UEnum_JMReconRuntime_EJMReconEndReason_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Cancelled.Name", "EJMReconEndReason::Cancelled" },
		{ "Completed.Name", "EJMReconEndReason::Completed" },
		{ "EndPlay.Name", "EJMReconEndReason::EndPlay" },
		{ "InteractorDestroyed.Name", "EJMReconEndReason::InteractorDestroyed" },
		{ "ModuleRelativePath", "Public/Types/JMReconTypes.h" },
		{ "TargetDestroyed.Name", "EJMReconEndReason::TargetDestroyed" },
		{ "TargetInvalidated.Name", "EJMReconEndReason::TargetInvalidated" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMReconEndReason::Completed", (int64)EJMReconEndReason::Completed },
		{ "EJMReconEndReason::Cancelled", (int64)EJMReconEndReason::Cancelled },
		{ "EJMReconEndReason::TargetDestroyed", (int64)EJMReconEndReason::TargetDestroyed },
		{ "EJMReconEndReason::InteractorDestroyed", (int64)EJMReconEndReason::InteractorDestroyed },
		{ "EJMReconEndReason::TargetInvalidated", (int64)EJMReconEndReason::TargetInvalidated },
		{ "EJMReconEndReason::EndPlay", (int64)EJMReconEndReason::EndPlay },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMReconRuntime_EJMReconEndReason_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMReconRuntime_EJMReconEndReason_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMReconRuntime,
	nullptr,
	"EJMReconEndReason",
	"EJMReconEndReason",
	Z_Construct_UEnum_JMReconRuntime_EJMReconEndReason_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMReconRuntime_EJMReconEndReason_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMReconRuntime_EJMReconEndReason_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMReconRuntime_EJMReconEndReason_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMReconRuntime_EJMReconEndReason()
{
	if (!Z_Registration_Info_UEnum_EJMReconEndReason.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMReconEndReason.InnerSingleton, Z_Construct_UEnum_JMReconRuntime_EJMReconEndReason_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMReconEndReason.InnerSingleton;
}
// ********** End Enum EJMReconEndReason ***********************************************************

// ********** Begin ScriptStruct FJMReconRequestResult *********************************************
struct Z_Construct_UScriptStruct_FJMReconRequestResult_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMReconRequestResult); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMReconRequestResult); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMReconTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSucceeded_MetaData[] = {
		{ "Category", "Recon" },
		{ "ModuleRelativePath", "Public/Types/JMReconTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FailureReason_MetaData[] = {
		{ "Category", "Recon" },
		{ "ModuleRelativePath", "Public/Types/JMReconTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMReconRequestResult constinit property declarations *************
	static void NewProp_bSucceeded_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSucceeded;
	static const UECodeGen_Private::FBytePropertyParams NewProp_FailureReason_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_FailureReason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMReconRequestResult constinit property declarations ***************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMReconRequestResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMReconRequestResult_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMReconRequestResult;
class UScriptStruct* FJMReconRequestResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMReconRequestResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMReconRequestResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMReconRequestResult, (UObject*)Z_Construct_UPackage__Script_JMReconRuntime(), TEXT("JMReconRequestResult"));
	}
	return Z_Registration_Info_UScriptStruct_FJMReconRequestResult.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMReconRequestResult Property Definitions ************************
void Z_Construct_UScriptStruct_FJMReconRequestResult_Statics::NewProp_bSucceeded_SetBit(void* Obj)
{
	((FJMReconRequestResult*)Obj)->bSucceeded = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMReconRequestResult_Statics::NewProp_bSucceeded = { "bSucceeded", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMReconRequestResult), &Z_Construct_UScriptStruct_FJMReconRequestResult_Statics::NewProp_bSucceeded_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSucceeded_MetaData), NewProp_bSucceeded_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMReconRequestResult_Statics::NewProp_FailureReason_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMReconRequestResult_Statics::NewProp_FailureReason = { "FailureReason", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMReconRequestResult, FailureReason), Z_Construct_UEnum_JMReconRuntime_EJMReconFailureReason, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FailureReason_MetaData), NewProp_FailureReason_MetaData) }; // 2032304082
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMReconRequestResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMReconRequestResult_Statics::NewProp_bSucceeded,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMReconRequestResult_Statics::NewProp_FailureReason_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMReconRequestResult_Statics::NewProp_FailureReason,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMReconRequestResult_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMReconRequestResult Property Definitions **************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMReconRequestResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMReconRuntime,
	nullptr,
	&NewStructOps,
	"JMReconRequestResult",
	Z_Construct_UScriptStruct_FJMReconRequestResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMReconRequestResult_Statics::PropPointers),
	sizeof(FJMReconRequestResult),
	alignof(FJMReconRequestResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMReconRequestResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMReconRequestResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMReconRequestResult()
{
	if (!Z_Registration_Info_UScriptStruct_FJMReconRequestResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMReconRequestResult.InnerSingleton, Z_Construct_UScriptStruct_FJMReconRequestResult_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMReconRequestResult.InnerSingleton);
}
// ********** End ScriptStruct FJMReconRequestResult ***********************************************

// ********** Begin ScriptStruct FJMReconSession ***************************************************
struct Z_Construct_UScriptStruct_FJMReconSession_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMReconSession); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMReconSession); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMReconTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SessionId_MetaData[] = {
		{ "Category", "Recon" },
		{ "ModuleRelativePath", "Public/Types/JMReconTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentState_MetaData[] = {
		{ "Category", "Recon" },
		{ "ModuleRelativePath", "Public/Types/JMReconTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsIlluminating_MetaData[] = {
		{ "Category", "Recon" },
		{ "ModuleRelativePath", "Public/Types/JMReconTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMReconSession constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SessionId;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentState;
	static void NewProp_bIsIlluminating_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsIlluminating;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMReconSession constinit property declarations *********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMReconSession>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMReconSession_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMReconSession;
class UScriptStruct* FJMReconSession::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMReconSession.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMReconSession.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMReconSession, (UObject*)Z_Construct_UPackage__Script_JMReconRuntime(), TEXT("JMReconSession"));
	}
	return Z_Registration_Info_UScriptStruct_FJMReconSession.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMReconSession Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMReconSession_Statics::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMReconSession, SessionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SessionId_MetaData), NewProp_SessionId_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMReconSession_Statics::NewProp_CurrentState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMReconSession_Statics::NewProp_CurrentState = { "CurrentState", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMReconSession, CurrentState), Z_Construct_UEnum_JMReconRuntime_EJMReconState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentState_MetaData), NewProp_CurrentState_MetaData) }; // 3305027711
void Z_Construct_UScriptStruct_FJMReconSession_Statics::NewProp_bIsIlluminating_SetBit(void* Obj)
{
	((FJMReconSession*)Obj)->bIsIlluminating = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMReconSession_Statics::NewProp_bIsIlluminating = { "bIsIlluminating", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMReconSession), &Z_Construct_UScriptStruct_FJMReconSession_Statics::NewProp_bIsIlluminating_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsIlluminating_MetaData), NewProp_bIsIlluminating_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMReconSession_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMReconSession_Statics::NewProp_SessionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMReconSession_Statics::NewProp_CurrentState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMReconSession_Statics::NewProp_CurrentState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMReconSession_Statics::NewProp_bIsIlluminating,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMReconSession_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMReconSession Property Definitions ********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMReconSession_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMReconRuntime,
	nullptr,
	&NewStructOps,
	"JMReconSession",
	Z_Construct_UScriptStruct_FJMReconSession_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMReconSession_Statics::PropPointers),
	sizeof(FJMReconSession),
	alignof(FJMReconSession),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMReconSession_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMReconSession_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMReconSession()
{
	if (!Z_Registration_Info_UScriptStruct_FJMReconSession.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMReconSession.InnerSingleton, Z_Construct_UScriptStruct_FJMReconSession_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMReconSession.InnerSingleton);
}
// ********** End ScriptStruct FJMReconSession *****************************************************

// ********** Begin ScriptStruct FJMReconNoiseEvent ************************************************
struct Z_Construct_UScriptStruct_FJMReconNoiseEvent_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMReconNoiseEvent); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMReconNoiseEvent); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMReconTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "Category", "Recon" },
		{ "ModuleRelativePath", "Public/Types/JMReconTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Loudness_MetaData[] = {
		{ "Category", "Recon" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Types/JMReconTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NoiseType_MetaData[] = {
		{ "Category", "Recon" },
		{ "ModuleRelativePath", "Public/Types/JMReconTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Instigator_MetaData[] = {
		{ "Category", "Recon" },
		{ "ModuleRelativePath", "Public/Types/JMReconTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[] = {
		{ "Category", "Recon" },
		{ "ModuleRelativePath", "Public/Types/JMReconTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMReconNoiseEvent constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Loudness;
	static const UECodeGen_Private::FNamePropertyParams NewProp_NoiseType;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Instigator;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMReconNoiseEvent constinit property declarations ******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMReconNoiseEvent>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMReconNoiseEvent_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMReconNoiseEvent;
class UScriptStruct* FJMReconNoiseEvent::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMReconNoiseEvent.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMReconNoiseEvent.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMReconNoiseEvent, (UObject*)Z_Construct_UPackage__Script_JMReconRuntime(), TEXT("JMReconNoiseEvent"));
	}
	return Z_Registration_Info_UScriptStruct_FJMReconNoiseEvent.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMReconNoiseEvent Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMReconNoiseEvent_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMReconNoiseEvent, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMReconNoiseEvent_Statics::NewProp_Loudness = { "Loudness", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMReconNoiseEvent, Loudness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Loudness_MetaData), NewProp_Loudness_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FJMReconNoiseEvent_Statics::NewProp_NoiseType = { "NoiseType", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMReconNoiseEvent, NoiseType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NoiseType_MetaData), NewProp_NoiseType_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMReconNoiseEvent_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMReconNoiseEvent, Instigator), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Instigator_MetaData), NewProp_Instigator_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMReconNoiseEvent_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMReconNoiseEvent, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Target_MetaData), NewProp_Target_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMReconNoiseEvent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMReconNoiseEvent_Statics::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMReconNoiseEvent_Statics::NewProp_Loudness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMReconNoiseEvent_Statics::NewProp_NoiseType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMReconNoiseEvent_Statics::NewProp_Instigator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMReconNoiseEvent_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMReconNoiseEvent_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMReconNoiseEvent Property Definitions *****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMReconNoiseEvent_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMReconRuntime,
	nullptr,
	&NewStructOps,
	"JMReconNoiseEvent",
	Z_Construct_UScriptStruct_FJMReconNoiseEvent_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMReconNoiseEvent_Statics::PropPointers),
	sizeof(FJMReconNoiseEvent),
	alignof(FJMReconNoiseEvent),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMReconNoiseEvent_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMReconNoiseEvent_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMReconNoiseEvent()
{
	if (!Z_Registration_Info_UScriptStruct_FJMReconNoiseEvent.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMReconNoiseEvent.InnerSingleton, Z_Construct_UScriptStruct_FJMReconNoiseEvent_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMReconNoiseEvent.InnerSingleton);
}
// ********** End ScriptStruct FJMReconNoiseEvent **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Types_JMReconTypes_h__Script_JMReconRuntime_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EJMReconState_StaticEnum, TEXT("EJMReconState"), &Z_Registration_Info_UEnum_EJMReconState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3305027711U) },
		{ EJMReconInitialObservationMode_StaticEnum, TEXT("EJMReconInitialObservationMode"), &Z_Registration_Info_UEnum_EJMReconInitialObservationMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1223066713U) },
		{ EJMReconMode_StaticEnum, TEXT("EJMReconMode"), &Z_Registration_Info_UEnum_EJMReconMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1119645649U) },
		{ EJMReconFailureReason_StaticEnum, TEXT("EJMReconFailureReason"), &Z_Registration_Info_UEnum_EJMReconFailureReason, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2032304082U) },
		{ EJMReconEndReason_StaticEnum, TEXT("EJMReconEndReason"), &Z_Registration_Info_UEnum_EJMReconEndReason, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3838439290U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FJMReconRequestResult::StaticStruct, Z_Construct_UScriptStruct_FJMReconRequestResult_Statics::NewStructOps, TEXT("JMReconRequestResult"),&Z_Registration_Info_UScriptStruct_FJMReconRequestResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMReconRequestResult), 1431610246U) },
		{ FJMReconSession::StaticStruct, Z_Construct_UScriptStruct_FJMReconSession_Statics::NewStructOps, TEXT("JMReconSession"),&Z_Registration_Info_UScriptStruct_FJMReconSession, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMReconSession), 816966381U) },
		{ FJMReconNoiseEvent::StaticStruct, Z_Construct_UScriptStruct_FJMReconNoiseEvent_Statics::NewStructOps, TEXT("JMReconNoiseEvent"),&Z_Registration_Info_UScriptStruct_FJMReconNoiseEvent, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMReconNoiseEvent), 3767723695U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Types_JMReconTypes_h__Script_JMReconRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Types_JMReconTypes_h__Script_JMReconRuntime_2116035275{
	TEXT("/Script/JMReconRuntime"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Types_JMReconTypes_h__Script_JMReconRuntime_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Types_JMReconTypes_h__Script_JMReconRuntime_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Types_JMReconTypes_h__Script_JMReconRuntime_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Types_JMReconTypes_h__Script_JMReconRuntime_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
