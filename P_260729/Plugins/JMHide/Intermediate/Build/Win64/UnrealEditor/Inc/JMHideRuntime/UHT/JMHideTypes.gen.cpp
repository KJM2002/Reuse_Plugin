// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Types/JMHideTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMHideTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
JMHIDERUNTIME_API UEnum* Z_Construct_UEnum_JMHideRuntime_EJMHideAnchorRole();
JMHIDERUNTIME_API UEnum* Z_Construct_UEnum_JMHideRuntime_EJMHideFailureCode();
JMHIDERUNTIME_API UEnum* Z_Construct_UEnum_JMHideRuntime_EJMHideOperation();
JMHIDERUNTIME_API UEnum* Z_Construct_UEnum_JMHideRuntime_EJMHidePhase();
JMHIDERUNTIME_API UEnum* Z_Construct_UEnum_JMHideRuntime_EJMHideSpotArchetype();
JMHIDERUNTIME_API UEnum* Z_Construct_UEnum_JMHideRuntime_EJMHideSpotState();
JMHIDERUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMHideConfigOverride();
JMHIDERUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMHideConfigValues();
JMHIDERUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMHideOperationCompletion();
JMHIDERUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMHideOperationContext();
JMHIDERUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMHideParticipantSnapshot();
JMHIDERUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMHideRequest();
JMHIDERUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMHideResult();
JMHIDERUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMHideSession();
JMHIDERUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMResolvedHideConfig();
UPackage* Z_Construct_UPackage__Script_JMHideRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EJMHidePhase **************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMHidePhase;
static UEnum* EJMHidePhase_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMHidePhase.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMHidePhase.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMHideRuntime_EJMHidePhase, (UObject*)Z_Construct_UPackage__Script_JMHideRuntime(), TEXT("EJMHidePhase"));
	}
	return Z_Registration_Info_UEnum_EJMHidePhase.OuterSingleton;
}
template<> JMHIDERUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMHidePhase>()
{
	return EJMHidePhase_StaticEnum();
}
struct Z_Construct_UEnum_JMHideRuntime_EJMHidePhase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Cancelled.Name", "EJMHidePhase::Cancelled" },
		{ "CleaningUp.Name", "EJMHidePhase::CleaningUp" },
		{ "ClosingAfterEnter.Name", "EJMHidePhase::ClosingAfterEnter" },
		{ "ClosingAfterExit.Name", "EJMHidePhase::ClosingAfterExit" },
		{ "Completed.Name", "EJMHidePhase::Completed" },
		{ "Entering.Name", "EJMHidePhase::Entering" },
		{ "Exiting.Name", "EJMHidePhase::Exiting" },
		{ "Failed.Name", "EJMHidePhase::Failed" },
		{ "Hidden.Name", "EJMHidePhase::Hidden" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
		{ "None.Name", "EJMHidePhase::None" },
		{ "Opening.Name", "EJMHidePhase::Opening" },
		{ "OpeningForExit.Name", "EJMHidePhase::OpeningForExit" },
		{ "PreparingEnter.Name", "EJMHidePhase::PreparingEnter" },
		{ "PreparingExit.Name", "EJMHidePhase::PreparingExit" },
		{ "Reserving.Name", "EJMHidePhase::Reserving" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMHidePhase::None", (int64)EJMHidePhase::None },
		{ "EJMHidePhase::Reserving", (int64)EJMHidePhase::Reserving },
		{ "EJMHidePhase::PreparingEnter", (int64)EJMHidePhase::PreparingEnter },
		{ "EJMHidePhase::Opening", (int64)EJMHidePhase::Opening },
		{ "EJMHidePhase::Entering", (int64)EJMHidePhase::Entering },
		{ "EJMHidePhase::ClosingAfterEnter", (int64)EJMHidePhase::ClosingAfterEnter },
		{ "EJMHidePhase::Hidden", (int64)EJMHidePhase::Hidden },
		{ "EJMHidePhase::PreparingExit", (int64)EJMHidePhase::PreparingExit },
		{ "EJMHidePhase::OpeningForExit", (int64)EJMHidePhase::OpeningForExit },
		{ "EJMHidePhase::Exiting", (int64)EJMHidePhase::Exiting },
		{ "EJMHidePhase::ClosingAfterExit", (int64)EJMHidePhase::ClosingAfterExit },
		{ "EJMHidePhase::CleaningUp", (int64)EJMHidePhase::CleaningUp },
		{ "EJMHidePhase::Completed", (int64)EJMHidePhase::Completed },
		{ "EJMHidePhase::Cancelled", (int64)EJMHidePhase::Cancelled },
		{ "EJMHidePhase::Failed", (int64)EJMHidePhase::Failed },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMHideRuntime_EJMHidePhase_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMHideRuntime_EJMHidePhase_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMHideRuntime,
	nullptr,
	"EJMHidePhase",
	"EJMHidePhase",
	Z_Construct_UEnum_JMHideRuntime_EJMHidePhase_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMHideRuntime_EJMHidePhase_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMHideRuntime_EJMHidePhase_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMHideRuntime_EJMHidePhase_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMHideRuntime_EJMHidePhase()
{
	if (!Z_Registration_Info_UEnum_EJMHidePhase.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMHidePhase.InnerSingleton, Z_Construct_UEnum_JMHideRuntime_EJMHidePhase_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMHidePhase.InnerSingleton;
}
// ********** End Enum EJMHidePhase ****************************************************************

// ********** Begin Enum EJMHideSpotState **********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMHideSpotState;
static UEnum* EJMHideSpotState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMHideSpotState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMHideSpotState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMHideRuntime_EJMHideSpotState, (UObject*)Z_Construct_UPackage__Script_JMHideRuntime(), TEXT("EJMHideSpotState"));
	}
	return Z_Registration_Info_UEnum_EJMHideSpotState.OuterSingleton;
}
template<> JMHIDERUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMHideSpotState>()
{
	return EJMHideSpotState_StaticEnum();
}
struct Z_Construct_UEnum_JMHideRuntime_EJMHideSpotState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Available.Name", "EJMHideSpotState::Available" },
		{ "BlueprintType", "true" },
		{ "Disabled.Name", "EJMHideSpotState::Disabled" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
		{ "Occupied.Name", "EJMHideSpotState::Occupied" },
		{ "Reserved.Name", "EJMHideSpotState::Reserved" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMHideSpotState::Disabled", (int64)EJMHideSpotState::Disabled },
		{ "EJMHideSpotState::Available", (int64)EJMHideSpotState::Available },
		{ "EJMHideSpotState::Reserved", (int64)EJMHideSpotState::Reserved },
		{ "EJMHideSpotState::Occupied", (int64)EJMHideSpotState::Occupied },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMHideRuntime_EJMHideSpotState_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMHideRuntime_EJMHideSpotState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMHideRuntime,
	nullptr,
	"EJMHideSpotState",
	"EJMHideSpotState",
	Z_Construct_UEnum_JMHideRuntime_EJMHideSpotState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMHideRuntime_EJMHideSpotState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMHideRuntime_EJMHideSpotState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMHideRuntime_EJMHideSpotState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMHideRuntime_EJMHideSpotState()
{
	if (!Z_Registration_Info_UEnum_EJMHideSpotState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMHideSpotState.InnerSingleton, Z_Construct_UEnum_JMHideRuntime_EJMHideSpotState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMHideSpotState.InnerSingleton;
}
// ********** End Enum EJMHideSpotState ************************************************************

// ********** Begin Enum EJMHideSpotArchetype ******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMHideSpotArchetype;
static UEnum* EJMHideSpotArchetype_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMHideSpotArchetype.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMHideSpotArchetype.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMHideRuntime_EJMHideSpotArchetype, (UObject*)Z_Construct_UPackage__Script_JMHideRuntime(), TEXT("EJMHideSpotArchetype"));
	}
	return Z_Registration_Info_UEnum_EJMHideSpotArchetype.OuterSingleton;
}
template<> JMHIDERUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMHideSpotArchetype>()
{
	return EJMHideSpotArchetype_StaticEnum();
}
struct Z_Construct_UEnum_JMHideRuntime_EJMHideSpotArchetype_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Custom.Name", "EJMHideSpotArchetype::Custom" },
		{ "Enclosed.Name", "EJMHideSpotArchetype::Enclosed" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
		{ "OpenSpace.Name", "EJMHideSpotArchetype::OpenSpace" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMHideSpotArchetype::OpenSpace", (int64)EJMHideSpotArchetype::OpenSpace },
		{ "EJMHideSpotArchetype::Enclosed", (int64)EJMHideSpotArchetype::Enclosed },
		{ "EJMHideSpotArchetype::Custom", (int64)EJMHideSpotArchetype::Custom },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMHideRuntime_EJMHideSpotArchetype_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMHideRuntime_EJMHideSpotArchetype_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMHideRuntime,
	nullptr,
	"EJMHideSpotArchetype",
	"EJMHideSpotArchetype",
	Z_Construct_UEnum_JMHideRuntime_EJMHideSpotArchetype_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMHideRuntime_EJMHideSpotArchetype_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMHideRuntime_EJMHideSpotArchetype_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMHideRuntime_EJMHideSpotArchetype_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMHideRuntime_EJMHideSpotArchetype()
{
	if (!Z_Registration_Info_UEnum_EJMHideSpotArchetype.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMHideSpotArchetype.InnerSingleton, Z_Construct_UEnum_JMHideRuntime_EJMHideSpotArchetype_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMHideSpotArchetype.InnerSingleton;
}
// ********** End Enum EJMHideSpotArchetype ********************************************************

// ********** Begin Enum EJMHideAnchorRole *********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMHideAnchorRole;
static UEnum* EJMHideAnchorRole_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMHideAnchorRole.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMHideAnchorRole.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMHideRuntime_EJMHideAnchorRole, (UObject*)Z_Construct_UPackage__Script_JMHideRuntime(), TEXT("EJMHideAnchorRole"));
	}
	return Z_Registration_Info_UEnum_EJMHideAnchorRole.OuterSingleton;
}
template<> JMHIDERUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMHideAnchorRole>()
{
	return EJMHideAnchorRole_StaticEnum();
}
struct Z_Construct_UEnum_JMHideRuntime_EJMHideAnchorRole_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AlternativeExit.Name", "EJMHideAnchorRole::AlternativeExit" },
		{ "BlueprintType", "true" },
		{ "Camera.Name", "EJMHideAnchorRole::Camera" },
		{ "Entry.Name", "EJMHideAnchorRole::Entry" },
		{ "Investigation.Name", "EJMHideAnchorRole::Investigation" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
		{ "Occupant.Name", "EJMHideAnchorRole::Occupant" },
		{ "PrimaryExit.Name", "EJMHideAnchorRole::PrimaryExit" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMHideAnchorRole::Entry", (int64)EJMHideAnchorRole::Entry },
		{ "EJMHideAnchorRole::Occupant", (int64)EJMHideAnchorRole::Occupant },
		{ "EJMHideAnchorRole::Camera", (int64)EJMHideAnchorRole::Camera },
		{ "EJMHideAnchorRole::PrimaryExit", (int64)EJMHideAnchorRole::PrimaryExit },
		{ "EJMHideAnchorRole::AlternativeExit", (int64)EJMHideAnchorRole::AlternativeExit },
		{ "EJMHideAnchorRole::Investigation", (int64)EJMHideAnchorRole::Investigation },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMHideRuntime_EJMHideAnchorRole_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMHideRuntime_EJMHideAnchorRole_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMHideRuntime,
	nullptr,
	"EJMHideAnchorRole",
	"EJMHideAnchorRole",
	Z_Construct_UEnum_JMHideRuntime_EJMHideAnchorRole_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMHideRuntime_EJMHideAnchorRole_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMHideRuntime_EJMHideAnchorRole_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMHideRuntime_EJMHideAnchorRole_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMHideRuntime_EJMHideAnchorRole()
{
	if (!Z_Registration_Info_UEnum_EJMHideAnchorRole.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMHideAnchorRole.InnerSingleton, Z_Construct_UEnum_JMHideRuntime_EJMHideAnchorRole_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMHideAnchorRole.InnerSingleton;
}
// ********** End Enum EJMHideAnchorRole ***********************************************************

// ********** Begin Enum EJMHideOperation **********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMHideOperation;
static UEnum* EJMHideOperation_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMHideOperation.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMHideOperation.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMHideRuntime_EJMHideOperation, (UObject*)Z_Construct_UPackage__Script_JMHideRuntime(), TEXT("EJMHideOperation"));
	}
	return Z_Registration_Info_UEnum_EJMHideOperation.OuterSingleton;
}
template<> JMHIDERUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMHideOperation>()
{
	return EJMHideOperation_StaticEnum();
}
struct Z_Construct_UEnum_JMHideRuntime_EJMHideOperation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CompleteEnter.Name", "EJMHideOperation::CompleteEnter" },
		{ "CompleteExit.Name", "EJMHideOperation::CompleteExit" },
		{ "Enter.Name", "EJMHideOperation::Enter" },
		{ "Exit.Name", "EJMHideOperation::Exit" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
		{ "None.Name", "EJMHideOperation::None" },
		{ "PrepareEnter.Name", "EJMHideOperation::PrepareEnter" },
		{ "PrepareExit.Name", "EJMHideOperation::PrepareExit" },
		{ "Restore.Name", "EJMHideOperation::Restore" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMHideOperation::None", (int64)EJMHideOperation::None },
		{ "EJMHideOperation::PrepareEnter", (int64)EJMHideOperation::PrepareEnter },
		{ "EJMHideOperation::Enter", (int64)EJMHideOperation::Enter },
		{ "EJMHideOperation::CompleteEnter", (int64)EJMHideOperation::CompleteEnter },
		{ "EJMHideOperation::PrepareExit", (int64)EJMHideOperation::PrepareExit },
		{ "EJMHideOperation::Exit", (int64)EJMHideOperation::Exit },
		{ "EJMHideOperation::CompleteExit", (int64)EJMHideOperation::CompleteExit },
		{ "EJMHideOperation::Restore", (int64)EJMHideOperation::Restore },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMHideRuntime_EJMHideOperation_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMHideRuntime_EJMHideOperation_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMHideRuntime,
	nullptr,
	"EJMHideOperation",
	"EJMHideOperation",
	Z_Construct_UEnum_JMHideRuntime_EJMHideOperation_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMHideRuntime_EJMHideOperation_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMHideRuntime_EJMHideOperation_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMHideRuntime_EJMHideOperation_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMHideRuntime_EJMHideOperation()
{
	if (!Z_Registration_Info_UEnum_EJMHideOperation.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMHideOperation.InnerSingleton, Z_Construct_UEnum_JMHideRuntime_EJMHideOperation_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMHideOperation.InnerSingleton;
}
// ********** End Enum EJMHideOperation ************************************************************

// ********** Begin Enum EJMHideFailureCode ********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMHideFailureCode;
static UEnum* EJMHideFailureCode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMHideFailureCode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMHideFailureCode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMHideRuntime_EJMHideFailureCode, (UObject*)Z_Construct_UPackage__Script_JMHideRuntime(), TEXT("EJMHideFailureCode"));
	}
	return Z_Registration_Info_UEnum_EJMHideFailureCode.OuterSingleton;
}
template<> JMHIDERUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMHideFailureCode>()
{
	return EJMHideFailureCode_StaticEnum();
}
struct Z_Construct_UEnum_JMHideRuntime_EJMHideFailureCode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AlreadyActive.Name", "EJMHideFailureCode::AlreadyActive" },
		{ "BlueprintType", "true" },
		{ "Cancelled.Name", "EJMHideFailureCode::Cancelled" },
		{ "ExitBlocked.Name", "EJMHideFailureCode::ExitBlocked" },
		{ "InvalidMechanism.Name", "EJMHideFailureCode::InvalidMechanism" },
		{ "InvalidParticipant.Name", "EJMHideFailureCode::InvalidParticipant" },
		{ "InvalidSpot.Name", "EJMHideFailureCode::InvalidSpot" },
		{ "InvalidState.Name", "EJMHideFailureCode::InvalidState" },
		{ "MissingAnchor.Name", "EJMHideFailureCode::MissingAnchor" },
		{ "MissingMechanism.Name", "EJMHideFailureCode::MissingMechanism" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
		{ "None.Name", "EJMHideFailureCode::None" },
		{ "OperationFailed.Name", "EJMHideFailureCode::OperationFailed" },
		{ "OperationRejected.Name", "EJMHideFailureCode::OperationRejected" },
		{ "SpotDisabled.Name", "EJMHideFailureCode::SpotDisabled" },
		{ "SpotUnavailable.Name", "EJMHideFailureCode::SpotUnavailable" },
		{ "TargetDestroyed.Name", "EJMHideFailureCode::TargetDestroyed" },
		{ "UnsupportedParticipant.Name", "EJMHideFailureCode::UnsupportedParticipant" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMHideFailureCode::None", (int64)EJMHideFailureCode::None },
		{ "EJMHideFailureCode::AlreadyActive", (int64)EJMHideFailureCode::AlreadyActive },
		{ "EJMHideFailureCode::InvalidState", (int64)EJMHideFailureCode::InvalidState },
		{ "EJMHideFailureCode::InvalidParticipant", (int64)EJMHideFailureCode::InvalidParticipant },
		{ "EJMHideFailureCode::UnsupportedParticipant", (int64)EJMHideFailureCode::UnsupportedParticipant },
		{ "EJMHideFailureCode::InvalidSpot", (int64)EJMHideFailureCode::InvalidSpot },
		{ "EJMHideFailureCode::SpotDisabled", (int64)EJMHideFailureCode::SpotDisabled },
		{ "EJMHideFailureCode::SpotUnavailable", (int64)EJMHideFailureCode::SpotUnavailable },
		{ "EJMHideFailureCode::MissingAnchor", (int64)EJMHideFailureCode::MissingAnchor },
		{ "EJMHideFailureCode::MissingMechanism", (int64)EJMHideFailureCode::MissingMechanism },
		{ "EJMHideFailureCode::InvalidMechanism", (int64)EJMHideFailureCode::InvalidMechanism },
		{ "EJMHideFailureCode::OperationRejected", (int64)EJMHideFailureCode::OperationRejected },
		{ "EJMHideFailureCode::OperationFailed", (int64)EJMHideFailureCode::OperationFailed },
		{ "EJMHideFailureCode::ExitBlocked", (int64)EJMHideFailureCode::ExitBlocked },
		{ "EJMHideFailureCode::Cancelled", (int64)EJMHideFailureCode::Cancelled },
		{ "EJMHideFailureCode::TargetDestroyed", (int64)EJMHideFailureCode::TargetDestroyed },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMHideRuntime_EJMHideFailureCode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMHideRuntime_EJMHideFailureCode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMHideRuntime,
	nullptr,
	"EJMHideFailureCode",
	"EJMHideFailureCode",
	Z_Construct_UEnum_JMHideRuntime_EJMHideFailureCode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMHideRuntime_EJMHideFailureCode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMHideRuntime_EJMHideFailureCode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMHideRuntime_EJMHideFailureCode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMHideRuntime_EJMHideFailureCode()
{
	if (!Z_Registration_Info_UEnum_EJMHideFailureCode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMHideFailureCode.InnerSingleton, Z_Construct_UEnum_JMHideRuntime_EJMHideFailureCode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMHideFailureCode.InnerSingleton;
}
// ********** End Enum EJMHideFailureCode **********************************************************

// ********** Begin ScriptStruct FJMHideResult *****************************************************
struct Z_Construct_UScriptStruct_FJMHideResult_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMHideResult); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMHideResult); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSucceeded_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Code_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMHideResult constinit property declarations *********************
	static void NewProp_bSucceeded_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSucceeded;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Code_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Code;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMHideResult constinit property declarations ***********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMHideResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMHideResult_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMHideResult;
class UScriptStruct* FJMHideResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMHideResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMHideResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMHideResult, (UObject*)Z_Construct_UPackage__Script_JMHideRuntime(), TEXT("JMHideResult"));
	}
	return Z_Registration_Info_UScriptStruct_FJMHideResult.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMHideResult Property Definitions ********************************
void Z_Construct_UScriptStruct_FJMHideResult_Statics::NewProp_bSucceeded_SetBit(void* Obj)
{
	((FJMHideResult*)Obj)->bSucceeded = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMHideResult_Statics::NewProp_bSucceeded = { "bSucceeded", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMHideResult), &Z_Construct_UScriptStruct_FJMHideResult_Statics::NewProp_bSucceeded_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSucceeded_MetaData), NewProp_bSucceeded_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMHideResult_Statics::NewProp_Code_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMHideResult_Statics::NewProp_Code = { "Code", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideResult, Code), Z_Construct_UEnum_JMHideRuntime_EJMHideFailureCode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Code_MetaData), NewProp_Code_MetaData) }; // 71457987
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FJMHideResult_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideResult, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMHideResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideResult_Statics::NewProp_bSucceeded,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideResult_Statics::NewProp_Code_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideResult_Statics::NewProp_Code,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideResult_Statics::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideResult_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMHideResult Property Definitions **********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMHideResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideRuntime,
	nullptr,
	&NewStructOps,
	"JMHideResult",
	Z_Construct_UScriptStruct_FJMHideResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideResult_Statics::PropPointers),
	sizeof(FJMHideResult),
	alignof(FJMHideResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMHideResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMHideResult()
{
	if (!Z_Registration_Info_UScriptStruct_FJMHideResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMHideResult.InnerSingleton, Z_Construct_UScriptStruct_FJMHideResult_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMHideResult.InnerSingleton);
}
// ********** End ScriptStruct FJMHideResult *******************************************************

// ********** Begin ScriptStruct FJMHideConfigValues ***********************************************
struct Z_Construct_UScriptStruct_FJMHideConfigValues_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMHideConfigValues); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMHideConfigValues); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnterDuration_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExitDuration_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraBlendDuration_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseCameraFadeTransition_MetaData[] = {
		{ "Category", "JM Hide|Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Use a short fade instead of spatially blending the camera through solid geometry. */" },
#endif
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Use a short fade instead of spatially blending the camera through solid geometry." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseEntryAnchor_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHideParticipant_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDisableCollision_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bForceExitIgnoresCollision_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowLimitedLook_MetaData[] = {
		{ "Category", "JM Hide|Look" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookYawLimit_MetaData[] = {
		{ "Category", "JM Hide|Look" },
		{ "ClampMax", "180.0" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bAllowLimitedLook" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
		{ "Units", "deg" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookPitchLimit_MetaData[] = {
		{ "Category", "JM Hide|Look" },
		{ "ClampMax", "89.0" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bAllowLimitedLook" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
		{ "Units", "deg" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExitPrompt_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMHideConfigValues constinit property declarations ***************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EnterDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ExitDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraBlendDuration;
	static void NewProp_bUseCameraFadeTransition_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseCameraFadeTransition;
	static void NewProp_bUseEntryAnchor_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseEntryAnchor;
	static void NewProp_bHideParticipant_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHideParticipant;
	static void NewProp_bDisableCollision_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDisableCollision;
	static void NewProp_bForceExitIgnoresCollision_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bForceExitIgnoresCollision;
	static void NewProp_bAllowLimitedLook_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowLimitedLook;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LookYawLimit;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LookPitchLimit;
	static const UECodeGen_Private::FTextPropertyParams NewProp_ExitPrompt;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMHideConfigValues constinit property declarations *****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMHideConfigValues>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMHideConfigValues_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMHideConfigValues;
class UScriptStruct* FJMHideConfigValues::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMHideConfigValues.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMHideConfigValues.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMHideConfigValues, (UObject*)Z_Construct_UPackage__Script_JMHideRuntime(), TEXT("JMHideConfigValues"));
	}
	return Z_Registration_Info_UScriptStruct_FJMHideConfigValues.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMHideConfigValues Property Definitions **************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_EnterDuration = { "EnterDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideConfigValues, EnterDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnterDuration_MetaData), NewProp_EnterDuration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_ExitDuration = { "ExitDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideConfigValues, ExitDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExitDuration_MetaData), NewProp_ExitDuration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_CameraBlendDuration = { "CameraBlendDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideConfigValues, CameraBlendDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraBlendDuration_MetaData), NewProp_CameraBlendDuration_MetaData) };
void Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bUseCameraFadeTransition_SetBit(void* Obj)
{
	((FJMHideConfigValues*)Obj)->bUseCameraFadeTransition = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bUseCameraFadeTransition = { "bUseCameraFadeTransition", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMHideConfigValues), &Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bUseCameraFadeTransition_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseCameraFadeTransition_MetaData), NewProp_bUseCameraFadeTransition_MetaData) };
void Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bUseEntryAnchor_SetBit(void* Obj)
{
	((FJMHideConfigValues*)Obj)->bUseEntryAnchor = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bUseEntryAnchor = { "bUseEntryAnchor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMHideConfigValues), &Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bUseEntryAnchor_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseEntryAnchor_MetaData), NewProp_bUseEntryAnchor_MetaData) };
void Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bHideParticipant_SetBit(void* Obj)
{
	((FJMHideConfigValues*)Obj)->bHideParticipant = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bHideParticipant = { "bHideParticipant", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMHideConfigValues), &Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bHideParticipant_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHideParticipant_MetaData), NewProp_bHideParticipant_MetaData) };
void Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bDisableCollision_SetBit(void* Obj)
{
	((FJMHideConfigValues*)Obj)->bDisableCollision = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bDisableCollision = { "bDisableCollision", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMHideConfigValues), &Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bDisableCollision_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDisableCollision_MetaData), NewProp_bDisableCollision_MetaData) };
void Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bForceExitIgnoresCollision_SetBit(void* Obj)
{
	((FJMHideConfigValues*)Obj)->bForceExitIgnoresCollision = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bForceExitIgnoresCollision = { "bForceExitIgnoresCollision", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMHideConfigValues), &Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bForceExitIgnoresCollision_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bForceExitIgnoresCollision_MetaData), NewProp_bForceExitIgnoresCollision_MetaData) };
void Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bAllowLimitedLook_SetBit(void* Obj)
{
	((FJMHideConfigValues*)Obj)->bAllowLimitedLook = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bAllowLimitedLook = { "bAllowLimitedLook", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMHideConfigValues), &Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bAllowLimitedLook_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowLimitedLook_MetaData), NewProp_bAllowLimitedLook_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_LookYawLimit = { "LookYawLimit", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideConfigValues, LookYawLimit), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookYawLimit_MetaData), NewProp_LookYawLimit_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_LookPitchLimit = { "LookPitchLimit", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideConfigValues, LookPitchLimit), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookPitchLimit_MetaData), NewProp_LookPitchLimit_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_ExitPrompt = { "ExitPrompt", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideConfigValues, ExitPrompt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExitPrompt_MetaData), NewProp_ExitPrompt_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_EnterDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_ExitDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_CameraBlendDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bUseCameraFadeTransition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bUseEntryAnchor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bHideParticipant,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bDisableCollision,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bForceExitIgnoresCollision,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_bAllowLimitedLook,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_LookYawLimit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_LookPitchLimit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewProp_ExitPrompt,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMHideConfigValues Property Definitions ****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideRuntime,
	nullptr,
	&NewStructOps,
	"JMHideConfigValues",
	Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::PropPointers),
	sizeof(FJMHideConfigValues),
	alignof(FJMHideConfigValues),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMHideConfigValues()
{
	if (!Z_Registration_Info_UScriptStruct_FJMHideConfigValues.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMHideConfigValues.InnerSingleton, Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMHideConfigValues.InnerSingleton);
}
// ********** End ScriptStruct FJMHideConfigValues *************************************************

// ********** Begin ScriptStruct FJMHideConfigOverride *********************************************
struct Z_Construct_UScriptStruct_FJMHideConfigOverride_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMHideConfigOverride); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMHideConfigOverride); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverride_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Values_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "EditCondition", "bOverride" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMHideConfigOverride constinit property declarations *************
	static void NewProp_bOverride_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverride;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Values;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMHideConfigOverride constinit property declarations ***************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMHideConfigOverride>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMHideConfigOverride_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMHideConfigOverride;
class UScriptStruct* FJMHideConfigOverride::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMHideConfigOverride.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMHideConfigOverride.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMHideConfigOverride, (UObject*)Z_Construct_UPackage__Script_JMHideRuntime(), TEXT("JMHideConfigOverride"));
	}
	return Z_Registration_Info_UScriptStruct_FJMHideConfigOverride.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMHideConfigOverride Property Definitions ************************
void Z_Construct_UScriptStruct_FJMHideConfigOverride_Statics::NewProp_bOverride_SetBit(void* Obj)
{
	((FJMHideConfigOverride*)Obj)->bOverride = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMHideConfigOverride_Statics::NewProp_bOverride = { "bOverride", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMHideConfigOverride), &Z_Construct_UScriptStruct_FJMHideConfigOverride_Statics::NewProp_bOverride_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverride_MetaData), NewProp_bOverride_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMHideConfigOverride_Statics::NewProp_Values = { "Values", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideConfigOverride, Values), Z_Construct_UScriptStruct_FJMHideConfigValues, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Values_MetaData), NewProp_Values_MetaData) }; // 3280257492
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMHideConfigOverride_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideConfigOverride_Statics::NewProp_bOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideConfigOverride_Statics::NewProp_Values,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideConfigOverride_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMHideConfigOverride Property Definitions **************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMHideConfigOverride_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideRuntime,
	nullptr,
	&NewStructOps,
	"JMHideConfigOverride",
	Z_Construct_UScriptStruct_FJMHideConfigOverride_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideConfigOverride_Statics::PropPointers),
	sizeof(FJMHideConfigOverride),
	alignof(FJMHideConfigOverride),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideConfigOverride_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMHideConfigOverride_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMHideConfigOverride()
{
	if (!Z_Registration_Info_UScriptStruct_FJMHideConfigOverride.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMHideConfigOverride.InnerSingleton, Z_Construct_UScriptStruct_FJMHideConfigOverride_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMHideConfigOverride.InnerSingleton);
}
// ********** End ScriptStruct FJMHideConfigOverride ***********************************************

// ********** Begin ScriptStruct FJMResolvedHideConfig *********************************************
struct Z_Construct_UScriptStruct_FJMResolvedHideConfig_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMResolvedHideConfig); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMResolvedHideConfig); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMResolvedHideConfig constinit property declarations *************
// ********** End ScriptStruct FJMResolvedHideConfig constinit property declarations ***************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMResolvedHideConfig>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMResolvedHideConfig_Statics
static_assert(std::is_polymorphic<FJMResolvedHideConfig>() == std::is_polymorphic<FJMHideConfigValues>(), "USTRUCT FJMResolvedHideConfig cannot be polymorphic unless super FJMHideConfigValues is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMResolvedHideConfig;
class UScriptStruct* FJMResolvedHideConfig::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMResolvedHideConfig.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMResolvedHideConfig.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMResolvedHideConfig, (UObject*)Z_Construct_UPackage__Script_JMHideRuntime(), TEXT("JMResolvedHideConfig"));
	}
	return Z_Registration_Info_UScriptStruct_FJMResolvedHideConfig.OuterSingleton;
	}
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMResolvedHideConfig_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideRuntime,
	Z_Construct_UScriptStruct_FJMHideConfigValues,
	&NewStructOps,
	"JMResolvedHideConfig",
	nullptr,
	0,
	sizeof(FJMResolvedHideConfig),
	alignof(FJMResolvedHideConfig),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMResolvedHideConfig_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMResolvedHideConfig_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMResolvedHideConfig()
{
	if (!Z_Registration_Info_UScriptStruct_FJMResolvedHideConfig.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMResolvedHideConfig.InnerSingleton, Z_Construct_UScriptStruct_FJMResolvedHideConfig_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMResolvedHideConfig.InnerSingleton);
}
// ********** End ScriptStruct FJMResolvedHideConfig ***********************************************

// ********** Begin ScriptStruct FJMHideRequest ****************************************************
struct Z_Construct_UScriptStruct_FJMHideRequest_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMHideRequest); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMHideRequest); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConfigOverride_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMHideRequest constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ConfigOverride;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMHideRequest constinit property declarations **********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMHideRequest>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMHideRequest_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMHideRequest;
class UScriptStruct* FJMHideRequest::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMHideRequest.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMHideRequest.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMHideRequest, (UObject*)Z_Construct_UPackage__Script_JMHideRuntime(), TEXT("JMHideRequest"));
	}
	return Z_Registration_Info_UScriptStruct_FJMHideRequest.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMHideRequest Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMHideRequest_Statics::NewProp_ConfigOverride = { "ConfigOverride", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideRequest, ConfigOverride), Z_Construct_UScriptStruct_FJMHideConfigOverride, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConfigOverride_MetaData), NewProp_ConfigOverride_MetaData) }; // 2145498035
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMHideRequest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideRequest_Statics::NewProp_ConfigOverride,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideRequest_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMHideRequest Property Definitions *********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMHideRequest_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideRuntime,
	nullptr,
	&NewStructOps,
	"JMHideRequest",
	Z_Construct_UScriptStruct_FJMHideRequest_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideRequest_Statics::PropPointers),
	sizeof(FJMHideRequest),
	alignof(FJMHideRequest),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideRequest_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMHideRequest_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMHideRequest()
{
	if (!Z_Registration_Info_UScriptStruct_FJMHideRequest.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMHideRequest.InnerSingleton, Z_Construct_UScriptStruct_FJMHideRequest_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMHideRequest.InnerSingleton);
}
// ********** End ScriptStruct FJMHideRequest ******************************************************

// ********** Begin ScriptStruct FJMHideOperationContext *******************************************
struct Z_Construct_UScriptStruct_FJMHideOperationContext_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMHideOperationContext); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMHideOperationContext); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Participant_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntryTransform_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OccupantTransform_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraTransform_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExitTransform_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Config_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMHideOperationContext constinit property declarations ***********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Participant;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EntryTransform;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OccupantTransform;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CameraTransform;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ExitTransform;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Config;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMHideOperationContext constinit property declarations *************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMHideOperationContext>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMHideOperationContext_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMHideOperationContext;
class UScriptStruct* FJMHideOperationContext::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMHideOperationContext.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMHideOperationContext.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMHideOperationContext, (UObject*)Z_Construct_UPackage__Script_JMHideRuntime(), TEXT("JMHideOperationContext"));
	}
	return Z_Registration_Info_UScriptStruct_FJMHideOperationContext.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMHideOperationContext Property Definitions **********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMHideOperationContext_Statics::NewProp_Participant = { "Participant", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideOperationContext, Participant), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Participant_MetaData), NewProp_Participant_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMHideOperationContext_Statics::NewProp_EntryTransform = { "EntryTransform", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideOperationContext, EntryTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntryTransform_MetaData), NewProp_EntryTransform_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMHideOperationContext_Statics::NewProp_OccupantTransform = { "OccupantTransform", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideOperationContext, OccupantTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OccupantTransform_MetaData), NewProp_OccupantTransform_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMHideOperationContext_Statics::NewProp_CameraTransform = { "CameraTransform", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideOperationContext, CameraTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraTransform_MetaData), NewProp_CameraTransform_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMHideOperationContext_Statics::NewProp_ExitTransform = { "ExitTransform", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideOperationContext, ExitTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExitTransform_MetaData), NewProp_ExitTransform_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMHideOperationContext_Statics::NewProp_Config = { "Config", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideOperationContext, Config), Z_Construct_UScriptStruct_FJMResolvedHideConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Config_MetaData), NewProp_Config_MetaData) }; // 3456338744
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMHideOperationContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideOperationContext_Statics::NewProp_Participant,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideOperationContext_Statics::NewProp_EntryTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideOperationContext_Statics::NewProp_OccupantTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideOperationContext_Statics::NewProp_CameraTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideOperationContext_Statics::NewProp_ExitTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideOperationContext_Statics::NewProp_Config,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideOperationContext_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMHideOperationContext Property Definitions ************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMHideOperationContext_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideRuntime,
	nullptr,
	&NewStructOps,
	"JMHideOperationContext",
	Z_Construct_UScriptStruct_FJMHideOperationContext_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideOperationContext_Statics::PropPointers),
	sizeof(FJMHideOperationContext),
	alignof(FJMHideOperationContext),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideOperationContext_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMHideOperationContext_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMHideOperationContext()
{
	if (!Z_Registration_Info_UScriptStruct_FJMHideOperationContext.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMHideOperationContext.InnerSingleton, Z_Construct_UScriptStruct_FJMHideOperationContext_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMHideOperationContext.InnerSingleton);
}
// ********** End ScriptStruct FJMHideOperationContext *********************************************

// ********** Begin ScriptStruct FJMHideOperationCompletion ****************************************
struct Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMHideOperationCompletion); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMHideOperationCompletion); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SessionId_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Operation_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSucceeded_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FailureCode_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMHideOperationCompletion constinit property declarations ********
	static const UECodeGen_Private::FStructPropertyParams NewProp_SessionId;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Operation_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Operation;
	static void NewProp_bSucceeded_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSucceeded;
	static const UECodeGen_Private::FBytePropertyParams NewProp_FailureCode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_FailureCode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMHideOperationCompletion constinit property declarations **********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMHideOperationCompletion>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMHideOperationCompletion;
class UScriptStruct* FJMHideOperationCompletion::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMHideOperationCompletion.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMHideOperationCompletion.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMHideOperationCompletion, (UObject*)Z_Construct_UPackage__Script_JMHideRuntime(), TEXT("JMHideOperationCompletion"));
	}
	return Z_Registration_Info_UScriptStruct_FJMHideOperationCompletion.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMHideOperationCompletion Property Definitions *******************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideOperationCompletion, SessionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SessionId_MetaData), NewProp_SessionId_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics::NewProp_Operation_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics::NewProp_Operation = { "Operation", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideOperationCompletion, Operation), Z_Construct_UEnum_JMHideRuntime_EJMHideOperation, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Operation_MetaData), NewProp_Operation_MetaData) }; // 2615368747
void Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics::NewProp_bSucceeded_SetBit(void* Obj)
{
	((FJMHideOperationCompletion*)Obj)->bSucceeded = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics::NewProp_bSucceeded = { "bSucceeded", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMHideOperationCompletion), &Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics::NewProp_bSucceeded_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSucceeded_MetaData), NewProp_bSucceeded_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics::NewProp_FailureCode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics::NewProp_FailureCode = { "FailureCode", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideOperationCompletion, FailureCode), Z_Construct_UEnum_JMHideRuntime_EJMHideFailureCode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FailureCode_MetaData), NewProp_FailureCode_MetaData) }; // 71457987
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics::NewProp_SessionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics::NewProp_Operation_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics::NewProp_Operation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics::NewProp_bSucceeded,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics::NewProp_FailureCode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics::NewProp_FailureCode,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMHideOperationCompletion Property Definitions *********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideRuntime,
	nullptr,
	&NewStructOps,
	"JMHideOperationCompletion",
	Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics::PropPointers),
	sizeof(FJMHideOperationCompletion),
	alignof(FJMHideOperationCompletion),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMHideOperationCompletion()
{
	if (!Z_Registration_Info_UScriptStruct_FJMHideOperationCompletion.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMHideOperationCompletion.InnerSingleton, Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMHideOperationCompletion.InnerSingleton);
}
// ********** End ScriptStruct FJMHideOperationCompletion ******************************************

// ********** Begin ScriptStruct FJMHideParticipantSnapshot ****************************************
struct Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMHideParticipantSnapshot); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMHideParticipantSnapshot); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCaptured_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bChangedMovement_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bChangedTransform_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bChangedCollision_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bChangedVisibility_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bChangedViewTarget_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bChangedLookConstraint_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMHideParticipantSnapshot constinit property declarations ********
	static void NewProp_bCaptured_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCaptured;
	static void NewProp_bChangedMovement_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bChangedMovement;
	static void NewProp_bChangedTransform_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bChangedTransform;
	static void NewProp_bChangedCollision_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bChangedCollision;
	static void NewProp_bChangedVisibility_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bChangedVisibility;
	static void NewProp_bChangedViewTarget_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bChangedViewTarget;
	static void NewProp_bChangedLookConstraint_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bChangedLookConstraint;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMHideParticipantSnapshot constinit property declarations **********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMHideParticipantSnapshot>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMHideParticipantSnapshot;
class UScriptStruct* FJMHideParticipantSnapshot::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMHideParticipantSnapshot.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMHideParticipantSnapshot.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMHideParticipantSnapshot, (UObject*)Z_Construct_UPackage__Script_JMHideRuntime(), TEXT("JMHideParticipantSnapshot"));
	}
	return Z_Registration_Info_UScriptStruct_FJMHideParticipantSnapshot.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMHideParticipantSnapshot Property Definitions *******************
void Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bCaptured_SetBit(void* Obj)
{
	((FJMHideParticipantSnapshot*)Obj)->bCaptured = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bCaptured = { "bCaptured", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMHideParticipantSnapshot), &Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bCaptured_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCaptured_MetaData), NewProp_bCaptured_MetaData) };
void Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedMovement_SetBit(void* Obj)
{
	((FJMHideParticipantSnapshot*)Obj)->bChangedMovement = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedMovement = { "bChangedMovement", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMHideParticipantSnapshot), &Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedMovement_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bChangedMovement_MetaData), NewProp_bChangedMovement_MetaData) };
void Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedTransform_SetBit(void* Obj)
{
	((FJMHideParticipantSnapshot*)Obj)->bChangedTransform = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedTransform = { "bChangedTransform", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMHideParticipantSnapshot), &Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedTransform_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bChangedTransform_MetaData), NewProp_bChangedTransform_MetaData) };
void Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedCollision_SetBit(void* Obj)
{
	((FJMHideParticipantSnapshot*)Obj)->bChangedCollision = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedCollision = { "bChangedCollision", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMHideParticipantSnapshot), &Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedCollision_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bChangedCollision_MetaData), NewProp_bChangedCollision_MetaData) };
void Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedVisibility_SetBit(void* Obj)
{
	((FJMHideParticipantSnapshot*)Obj)->bChangedVisibility = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedVisibility = { "bChangedVisibility", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMHideParticipantSnapshot), &Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedVisibility_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bChangedVisibility_MetaData), NewProp_bChangedVisibility_MetaData) };
void Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedViewTarget_SetBit(void* Obj)
{
	((FJMHideParticipantSnapshot*)Obj)->bChangedViewTarget = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedViewTarget = { "bChangedViewTarget", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMHideParticipantSnapshot), &Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedViewTarget_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bChangedViewTarget_MetaData), NewProp_bChangedViewTarget_MetaData) };
void Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedLookConstraint_SetBit(void* Obj)
{
	((FJMHideParticipantSnapshot*)Obj)->bChangedLookConstraint = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedLookConstraint = { "bChangedLookConstraint", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMHideParticipantSnapshot), &Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedLookConstraint_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bChangedLookConstraint_MetaData), NewProp_bChangedLookConstraint_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bCaptured,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedMovement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedCollision,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedVisibility,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedViewTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewProp_bChangedLookConstraint,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMHideParticipantSnapshot Property Definitions *********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideRuntime,
	nullptr,
	&NewStructOps,
	"JMHideParticipantSnapshot",
	Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::PropPointers),
	sizeof(FJMHideParticipantSnapshot),
	alignof(FJMHideParticipantSnapshot),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMHideParticipantSnapshot()
{
	if (!Z_Registration_Info_UScriptStruct_FJMHideParticipantSnapshot.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMHideParticipantSnapshot.InnerSingleton, Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMHideParticipantSnapshot.InnerSingleton);
}
// ********** End ScriptStruct FJMHideParticipantSnapshot ******************************************

// ********** Begin ScriptStruct FJMHideSession ****************************************************
struct Z_Construct_UScriptStruct_FJMHideSession_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMHideSession); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMHideSession); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SessionId_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentPhase_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ResolvedConfig_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedExit_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OriginalStateSnapshot_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCleanupStarted_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCleanupCompleted_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Types/JMHideTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMHideSession constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SessionId;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentPhase_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentPhase;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ResolvedConfig;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SelectedExit;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OriginalStateSnapshot;
	static void NewProp_bCleanupStarted_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCleanupStarted;
	static void NewProp_bCleanupCompleted_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCleanupCompleted;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMHideSession constinit property declarations **********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMHideSession>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMHideSession_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMHideSession;
class UScriptStruct* FJMHideSession::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMHideSession.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMHideSession.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMHideSession, (UObject*)Z_Construct_UPackage__Script_JMHideRuntime(), TEXT("JMHideSession"));
	}
	return Z_Registration_Info_UScriptStruct_FJMHideSession.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMHideSession Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMHideSession_Statics::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideSession, SessionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SessionId_MetaData), NewProp_SessionId_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMHideSession_Statics::NewProp_CurrentPhase_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMHideSession_Statics::NewProp_CurrentPhase = { "CurrentPhase", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideSession, CurrentPhase), Z_Construct_UEnum_JMHideRuntime_EJMHidePhase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentPhase_MetaData), NewProp_CurrentPhase_MetaData) }; // 1560254620
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMHideSession_Statics::NewProp_ResolvedConfig = { "ResolvedConfig", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideSession, ResolvedConfig), Z_Construct_UScriptStruct_FJMResolvedHideConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ResolvedConfig_MetaData), NewProp_ResolvedConfig_MetaData) }; // 3456338744
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMHideSession_Statics::NewProp_SelectedExit = { "SelectedExit", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideSession, SelectedExit), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedExit_MetaData), NewProp_SelectedExit_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMHideSession_Statics::NewProp_OriginalStateSnapshot = { "OriginalStateSnapshot", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHideSession, OriginalStateSnapshot), Z_Construct_UScriptStruct_FJMHideParticipantSnapshot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OriginalStateSnapshot_MetaData), NewProp_OriginalStateSnapshot_MetaData) }; // 3080392559
void Z_Construct_UScriptStruct_FJMHideSession_Statics::NewProp_bCleanupStarted_SetBit(void* Obj)
{
	((FJMHideSession*)Obj)->bCleanupStarted = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMHideSession_Statics::NewProp_bCleanupStarted = { "bCleanupStarted", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMHideSession), &Z_Construct_UScriptStruct_FJMHideSession_Statics::NewProp_bCleanupStarted_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCleanupStarted_MetaData), NewProp_bCleanupStarted_MetaData) };
void Z_Construct_UScriptStruct_FJMHideSession_Statics::NewProp_bCleanupCompleted_SetBit(void* Obj)
{
	((FJMHideSession*)Obj)->bCleanupCompleted = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMHideSession_Statics::NewProp_bCleanupCompleted = { "bCleanupCompleted", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMHideSession), &Z_Construct_UScriptStruct_FJMHideSession_Statics::NewProp_bCleanupCompleted_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCleanupCompleted_MetaData), NewProp_bCleanupCompleted_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMHideSession_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideSession_Statics::NewProp_SessionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideSession_Statics::NewProp_CurrentPhase_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideSession_Statics::NewProp_CurrentPhase,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideSession_Statics::NewProp_ResolvedConfig,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideSession_Statics::NewProp_SelectedExit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideSession_Statics::NewProp_OriginalStateSnapshot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideSession_Statics::NewProp_bCleanupStarted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHideSession_Statics::NewProp_bCleanupCompleted,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideSession_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMHideSession Property Definitions *********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMHideSession_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideRuntime,
	nullptr,
	&NewStructOps,
	"JMHideSession",
	Z_Construct_UScriptStruct_FJMHideSession_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideSession_Statics::PropPointers),
	sizeof(FJMHideSession),
	alignof(FJMHideSession),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHideSession_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMHideSession_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMHideSession()
{
	if (!Z_Registration_Info_UScriptStruct_FJMHideSession.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMHideSession.InnerSingleton, Z_Construct_UScriptStruct_FJMHideSession_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMHideSession.InnerSingleton);
}
// ********** End ScriptStruct FJMHideSession ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Types_JMHideTypes_h__Script_JMHideRuntime_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EJMHidePhase_StaticEnum, TEXT("EJMHidePhase"), &Z_Registration_Info_UEnum_EJMHidePhase, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1560254620U) },
		{ EJMHideSpotState_StaticEnum, TEXT("EJMHideSpotState"), &Z_Registration_Info_UEnum_EJMHideSpotState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3285289581U) },
		{ EJMHideSpotArchetype_StaticEnum, TEXT("EJMHideSpotArchetype"), &Z_Registration_Info_UEnum_EJMHideSpotArchetype, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3499806852U) },
		{ EJMHideAnchorRole_StaticEnum, TEXT("EJMHideAnchorRole"), &Z_Registration_Info_UEnum_EJMHideAnchorRole, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3406772772U) },
		{ EJMHideOperation_StaticEnum, TEXT("EJMHideOperation"), &Z_Registration_Info_UEnum_EJMHideOperation, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2615368747U) },
		{ EJMHideFailureCode_StaticEnum, TEXT("EJMHideFailureCode"), &Z_Registration_Info_UEnum_EJMHideFailureCode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 71457987U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FJMHideResult::StaticStruct, Z_Construct_UScriptStruct_FJMHideResult_Statics::NewStructOps, TEXT("JMHideResult"),&Z_Registration_Info_UScriptStruct_FJMHideResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMHideResult), 1459112883U) },
		{ FJMHideConfigValues::StaticStruct, Z_Construct_UScriptStruct_FJMHideConfigValues_Statics::NewStructOps, TEXT("JMHideConfigValues"),&Z_Registration_Info_UScriptStruct_FJMHideConfigValues, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMHideConfigValues), 3280257492U) },
		{ FJMHideConfigOverride::StaticStruct, Z_Construct_UScriptStruct_FJMHideConfigOverride_Statics::NewStructOps, TEXT("JMHideConfigOverride"),&Z_Registration_Info_UScriptStruct_FJMHideConfigOverride, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMHideConfigOverride), 2145498035U) },
		{ FJMResolvedHideConfig::StaticStruct, Z_Construct_UScriptStruct_FJMResolvedHideConfig_Statics::NewStructOps, TEXT("JMResolvedHideConfig"),&Z_Registration_Info_UScriptStruct_FJMResolvedHideConfig, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMResolvedHideConfig), 3456338744U) },
		{ FJMHideRequest::StaticStruct, Z_Construct_UScriptStruct_FJMHideRequest_Statics::NewStructOps, TEXT("JMHideRequest"),&Z_Registration_Info_UScriptStruct_FJMHideRequest, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMHideRequest), 3732391629U) },
		{ FJMHideOperationContext::StaticStruct, Z_Construct_UScriptStruct_FJMHideOperationContext_Statics::NewStructOps, TEXT("JMHideOperationContext"),&Z_Registration_Info_UScriptStruct_FJMHideOperationContext, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMHideOperationContext), 746434956U) },
		{ FJMHideOperationCompletion::StaticStruct, Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics::NewStructOps, TEXT("JMHideOperationCompletion"),&Z_Registration_Info_UScriptStruct_FJMHideOperationCompletion, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMHideOperationCompletion), 3975656947U) },
		{ FJMHideParticipantSnapshot::StaticStruct, Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics::NewStructOps, TEXT("JMHideParticipantSnapshot"),&Z_Registration_Info_UScriptStruct_FJMHideParticipantSnapshot, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMHideParticipantSnapshot), 3080392559U) },
		{ FJMHideSession::StaticStruct, Z_Construct_UScriptStruct_FJMHideSession_Statics::NewStructOps, TEXT("JMHideSession"),&Z_Registration_Info_UScriptStruct_FJMHideSession, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMHideSession), 3326174497U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Types_JMHideTypes_h__Script_JMHideRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Types_JMHideTypes_h__Script_JMHideRuntime_620371743{
	TEXT("/Script/JMHideRuntime"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Types_JMHideTypes_h__Script_JMHideRuntime_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Types_JMHideTypes_h__Script_JMHideRuntime_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Types_JMHideTypes_h__Script_JMHideRuntime_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Types_JMHideTypes_h__Script_JMHideRuntime_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
