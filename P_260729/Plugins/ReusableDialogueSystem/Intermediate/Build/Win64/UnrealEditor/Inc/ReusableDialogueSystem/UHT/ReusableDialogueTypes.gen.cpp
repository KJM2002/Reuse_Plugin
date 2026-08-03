// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ReusableDialogueTypes.h"
#include "GameplayTagContainer.h"
#include "UObject/PrimaryAssetId.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeReusableDialogueTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FPrimaryAssetId();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueSpeakerProfile_NoRegister();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueTextSoundSet_NoRegister();
REUSABLEDIALOGUESYSTEM_API UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EDialogueEndReason();
REUSABLEDIALOGUESYSTEM_API UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EDialogueInteractionMode();
REUSABLEDIALOGUESYSTEM_API UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EDialogueRevealMode();
REUSABLEDIALOGUESYSTEM_API UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EDialogueState();
REUSABLEDIALOGUESYSTEM_API UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EDialogueTextSoundTriggerMode();
REUSABLEDIALOGUESYSTEM_API UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EDialogueTokenType();
REUSABLEDIALOGUESYSTEM_API UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EExistingDialoguePolicy();
REUSABLEDIALOGUESYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueHistoryEntry();
REUSABLEDIALOGUESYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueLine();
UPackage* Z_Construct_UPackage__Script_ReusableDialogueSystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EDialogueState ************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDialogueState;
static UEnum* EDialogueState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EDialogueState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EDialogueState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ReusableDialogueSystem_EDialogueState, (UObject*)Z_Construct_UPackage__Script_ReusableDialogueSystem(), TEXT("EDialogueState"));
	}
	return Z_Registration_Info_UEnum_EDialogueState.OuterSingleton;
}
template<> REUSABLEDIALOGUESYSTEM_NON_ATTRIBUTED_API UEnum* StaticEnum<EDialogueState>()
{
	return EDialogueState_StaticEnum();
}
struct Z_Construct_UEnum_ReusableDialogueSystem_EDialogueState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Closing.Name", "EDialogueState::Closing" },
		{ "Inactive.Name", "EDialogueState::Inactive" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
		{ "Opening.Name", "EDialogueState::Opening" },
		{ "Paused.Name", "EDialogueState::Paused" },
		{ "Revealing.Name", "EDialogueState::Revealing" },
		{ "Transitioning.Name", "EDialogueState::Transitioning" },
		{ "WaitingForAdvance.Name", "EDialogueState::WaitingForAdvance" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDialogueState::Inactive", (int64)EDialogueState::Inactive },
		{ "EDialogueState::Opening", (int64)EDialogueState::Opening },
		{ "EDialogueState::Revealing", (int64)EDialogueState::Revealing },
		{ "EDialogueState::WaitingForAdvance", (int64)EDialogueState::WaitingForAdvance },
		{ "EDialogueState::Transitioning", (int64)EDialogueState::Transitioning },
		{ "EDialogueState::Paused", (int64)EDialogueState::Paused },
		{ "EDialogueState::Closing", (int64)EDialogueState::Closing },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_ReusableDialogueSystem_EDialogueState_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ReusableDialogueSystem_EDialogueState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ReusableDialogueSystem,
	nullptr,
	"EDialogueState",
	"EDialogueState",
	Z_Construct_UEnum_ReusableDialogueSystem_EDialogueState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ReusableDialogueSystem_EDialogueState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ReusableDialogueSystem_EDialogueState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ReusableDialogueSystem_EDialogueState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EDialogueState()
{
	if (!Z_Registration_Info_UEnum_EDialogueState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDialogueState.InnerSingleton, Z_Construct_UEnum_ReusableDialogueSystem_EDialogueState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EDialogueState.InnerSingleton;
}
// ********** End Enum EDialogueState **************************************************************

// ********** Begin Enum EDialogueRevealMode *******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDialogueRevealMode;
static UEnum* EDialogueRevealMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EDialogueRevealMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EDialogueRevealMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ReusableDialogueSystem_EDialogueRevealMode, (UObject*)Z_Construct_UPackage__Script_ReusableDialogueSystem(), TEXT("EDialogueRevealMode"));
	}
	return Z_Registration_Info_UEnum_EDialogueRevealMode.OuterSingleton;
}
template<> REUSABLEDIALOGUESYSTEM_NON_ATTRIBUTED_API UEnum* StaticEnum<EDialogueRevealMode>()
{
	return EDialogueRevealMode_StaticEnum();
}
struct Z_Construct_UEnum_ReusableDialogueSystem_EDialogueRevealMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Character.Name", "EDialogueRevealMode::Character" },
		{ "Instant.Name", "EDialogueRevealMode::Instant" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
		{ "Word.Name", "EDialogueRevealMode::Word" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDialogueRevealMode::Word", (int64)EDialogueRevealMode::Word },
		{ "EDialogueRevealMode::Character", (int64)EDialogueRevealMode::Character },
		{ "EDialogueRevealMode::Instant", (int64)EDialogueRevealMode::Instant },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_ReusableDialogueSystem_EDialogueRevealMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ReusableDialogueSystem_EDialogueRevealMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ReusableDialogueSystem,
	nullptr,
	"EDialogueRevealMode",
	"EDialogueRevealMode",
	Z_Construct_UEnum_ReusableDialogueSystem_EDialogueRevealMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ReusableDialogueSystem_EDialogueRevealMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ReusableDialogueSystem_EDialogueRevealMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ReusableDialogueSystem_EDialogueRevealMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EDialogueRevealMode()
{
	if (!Z_Registration_Info_UEnum_EDialogueRevealMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDialogueRevealMode.InnerSingleton, Z_Construct_UEnum_ReusableDialogueSystem_EDialogueRevealMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EDialogueRevealMode.InnerSingleton;
}
// ********** End Enum EDialogueRevealMode *********************************************************

// ********** Begin Enum EDialogueInteractionMode **************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDialogueInteractionMode;
static UEnum* EDialogueInteractionMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EDialogueInteractionMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EDialogueInteractionMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ReusableDialogueSystem_EDialogueInteractionMode, (UObject*)Z_Construct_UPackage__Script_ReusableDialogueSystem(), TEXT("EDialogueInteractionMode"));
	}
	return Z_Registration_Info_UEnum_EDialogueInteractionMode.OuterSingleton;
}
template<> REUSABLEDIALOGUESYSTEM_NON_ATTRIBUTED_API UEnum* StaticEnum<EDialogueInteractionMode>()
{
	return EDialogueInteractionMode_StaticEnum();
}
struct Z_Construct_UEnum_ReusableDialogueSystem_EDialogueInteractionMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Cinematic.Name", "EDialogueInteractionMode::Cinematic" },
		{ "Modal.Name", "EDialogueInteractionMode::Modal" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
		{ "Overlay.Name", "EDialogueInteractionMode::Overlay" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDialogueInteractionMode::Modal", (int64)EDialogueInteractionMode::Modal },
		{ "EDialogueInteractionMode::Overlay", (int64)EDialogueInteractionMode::Overlay },
		{ "EDialogueInteractionMode::Cinematic", (int64)EDialogueInteractionMode::Cinematic },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_ReusableDialogueSystem_EDialogueInteractionMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ReusableDialogueSystem_EDialogueInteractionMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ReusableDialogueSystem,
	nullptr,
	"EDialogueInteractionMode",
	"EDialogueInteractionMode",
	Z_Construct_UEnum_ReusableDialogueSystem_EDialogueInteractionMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ReusableDialogueSystem_EDialogueInteractionMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ReusableDialogueSystem_EDialogueInteractionMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ReusableDialogueSystem_EDialogueInteractionMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EDialogueInteractionMode()
{
	if (!Z_Registration_Info_UEnum_EDialogueInteractionMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDialogueInteractionMode.InnerSingleton, Z_Construct_UEnum_ReusableDialogueSystem_EDialogueInteractionMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EDialogueInteractionMode.InnerSingleton;
}
// ********** End Enum EDialogueInteractionMode ****************************************************

// ********** Begin Enum EExistingDialoguePolicy ***************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EExistingDialoguePolicy;
static UEnum* EExistingDialoguePolicy_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EExistingDialoguePolicy.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EExistingDialoguePolicy.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ReusableDialogueSystem_EExistingDialoguePolicy, (UObject*)Z_Construct_UPackage__Script_ReusableDialogueSystem(), TEXT("EExistingDialoguePolicy"));
	}
	return Z_Registration_Info_UEnum_EExistingDialoguePolicy.OuterSingleton;
}
template<> REUSABLEDIALOGUESYSTEM_NON_ATTRIBUTED_API UEnum* StaticEnum<EExistingDialoguePolicy>()
{
	return EExistingDialoguePolicy_StaticEnum();
}
struct Z_Construct_UEnum_ReusableDialogueSystem_EExistingDialoguePolicy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
		{ "Reject.Name", "EExistingDialoguePolicy::Reject" },
		{ "ReplaceCurrent.Name", "EExistingDialoguePolicy::ReplaceCurrent" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EExistingDialoguePolicy::Reject", (int64)EExistingDialoguePolicy::Reject },
		{ "EExistingDialoguePolicy::ReplaceCurrent", (int64)EExistingDialoguePolicy::ReplaceCurrent },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_ReusableDialogueSystem_EExistingDialoguePolicy_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ReusableDialogueSystem_EExistingDialoguePolicy_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ReusableDialogueSystem,
	nullptr,
	"EExistingDialoguePolicy",
	"EExistingDialoguePolicy",
	Z_Construct_UEnum_ReusableDialogueSystem_EExistingDialoguePolicy_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ReusableDialogueSystem_EExistingDialoguePolicy_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ReusableDialogueSystem_EExistingDialoguePolicy_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ReusableDialogueSystem_EExistingDialoguePolicy_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EExistingDialoguePolicy()
{
	if (!Z_Registration_Info_UEnum_EExistingDialoguePolicy.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EExistingDialoguePolicy.InnerSingleton, Z_Construct_UEnum_ReusableDialogueSystem_EExistingDialoguePolicy_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EExistingDialoguePolicy.InnerSingleton;
}
// ********** End Enum EExistingDialoguePolicy *****************************************************

// ********** Begin Enum EDialogueTextSoundTriggerMode *********************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDialogueTextSoundTriggerMode;
static UEnum* EDialogueTextSoundTriggerMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EDialogueTextSoundTriggerMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EDialogueTextSoundTriggerMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ReusableDialogueSystem_EDialogueTextSoundTriggerMode, (UObject*)Z_Construct_UPackage__Script_ReusableDialogueSystem(), TEXT("EDialogueTextSoundTriggerMode"));
	}
	return Z_Registration_Info_UEnum_EDialogueTextSoundTriggerMode.OuterSingleton;
}
template<> REUSABLEDIALOGUESYSTEM_NON_ATTRIBUTED_API UEnum* StaticEnum<EDialogueTextSoundTriggerMode>()
{
	return EDialogueTextSoundTriggerMode_StaticEnum();
}
struct Z_Construct_UEnum_ReusableDialogueSystem_EDialogueTextSoundTriggerMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "EveryNCharacters.Name", "EDialogueTextSoundTriggerMode::EveryNCharacters" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
		{ "None.Name", "EDialogueTextSoundTriggerMode::None" },
		{ "PerRevealToken.Name", "EDialogueTextSoundTriggerMode::PerRevealToken" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDialogueTextSoundTriggerMode::PerRevealToken", (int64)EDialogueTextSoundTriggerMode::PerRevealToken },
		{ "EDialogueTextSoundTriggerMode::EveryNCharacters", (int64)EDialogueTextSoundTriggerMode::EveryNCharacters },
		{ "EDialogueTextSoundTriggerMode::None", (int64)EDialogueTextSoundTriggerMode::None },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_ReusableDialogueSystem_EDialogueTextSoundTriggerMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ReusableDialogueSystem_EDialogueTextSoundTriggerMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ReusableDialogueSystem,
	nullptr,
	"EDialogueTextSoundTriggerMode",
	"EDialogueTextSoundTriggerMode",
	Z_Construct_UEnum_ReusableDialogueSystem_EDialogueTextSoundTriggerMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ReusableDialogueSystem_EDialogueTextSoundTriggerMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ReusableDialogueSystem_EDialogueTextSoundTriggerMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ReusableDialogueSystem_EDialogueTextSoundTriggerMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EDialogueTextSoundTriggerMode()
{
	if (!Z_Registration_Info_UEnum_EDialogueTextSoundTriggerMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDialogueTextSoundTriggerMode.InnerSingleton, Z_Construct_UEnum_ReusableDialogueSystem_EDialogueTextSoundTriggerMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EDialogueTextSoundTriggerMode.InnerSingleton;
}
// ********** End Enum EDialogueTextSoundTriggerMode ***********************************************

// ********** Begin Enum EDialogueEndReason ********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDialogueEndReason;
static UEnum* EDialogueEndReason_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EDialogueEndReason.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EDialogueEndReason.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ReusableDialogueSystem_EDialogueEndReason, (UObject*)Z_Construct_UPackage__Script_ReusableDialogueSystem(), TEXT("EDialogueEndReason"));
	}
	return Z_Registration_Info_UEnum_EDialogueEndReason.OuterSingleton;
}
template<> REUSABLEDIALOGUESYSTEM_NON_ATTRIBUTED_API UEnum* StaticEnum<EDialogueEndReason>()
{
	return EDialogueEndReason_StaticEnum();
}
struct Z_Construct_UEnum_ReusableDialogueSystem_EDialogueEndReason_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Cancelled.Name", "EDialogueEndReason::Cancelled" },
		{ "Completed.Name", "EDialogueEndReason::Completed" },
		{ "InvalidData.Name", "EDialogueEndReason::InvalidData" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
		{ "Replaced.Name", "EDialogueEndReason::Replaced" },
		{ "WidgetCreationFailed.Name", "EDialogueEndReason::WidgetCreationFailed" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDialogueEndReason::Completed", (int64)EDialogueEndReason::Completed },
		{ "EDialogueEndReason::Cancelled", (int64)EDialogueEndReason::Cancelled },
		{ "EDialogueEndReason::Replaced", (int64)EDialogueEndReason::Replaced },
		{ "EDialogueEndReason::InvalidData", (int64)EDialogueEndReason::InvalidData },
		{ "EDialogueEndReason::WidgetCreationFailed", (int64)EDialogueEndReason::WidgetCreationFailed },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_ReusableDialogueSystem_EDialogueEndReason_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ReusableDialogueSystem_EDialogueEndReason_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ReusableDialogueSystem,
	nullptr,
	"EDialogueEndReason",
	"EDialogueEndReason",
	Z_Construct_UEnum_ReusableDialogueSystem_EDialogueEndReason_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ReusableDialogueSystem_EDialogueEndReason_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ReusableDialogueSystem_EDialogueEndReason_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ReusableDialogueSystem_EDialogueEndReason_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EDialogueEndReason()
{
	if (!Z_Registration_Info_UEnum_EDialogueEndReason.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDialogueEndReason.InnerSingleton, Z_Construct_UEnum_ReusableDialogueSystem_EDialogueEndReason_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EDialogueEndReason.InnerSingleton;
}
// ********** End Enum EDialogueEndReason **********************************************************

// ********** Begin Enum EDialogueTokenType ********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDialogueTokenType;
static UEnum* EDialogueTokenType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EDialogueTokenType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EDialogueTokenType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ReusableDialogueSystem_EDialogueTokenType, (UObject*)Z_Construct_UPackage__Script_ReusableDialogueSystem(), TEXT("EDialogueTokenType"));
	}
	return Z_Registration_Info_UEnum_EDialogueTokenType.OuterSingleton;
}
template<> REUSABLEDIALOGUESYSTEM_NON_ATTRIBUTED_API UEnum* StaticEnum<EDialogueTokenType>()
{
	return EDialogueTokenType_StaticEnum();
}
struct Z_Construct_UEnum_ReusableDialogueSystem_EDialogueTokenType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Mixed.Name", "EDialogueTokenType::Mixed" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
		{ "Punctuation.Name", "EDialogueTokenType::Punctuation" },
		{ "Whitespace.Name", "EDialogueTokenType::Whitespace" },
		{ "Word.Name", "EDialogueTokenType::Word" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDialogueTokenType::Word", (int64)EDialogueTokenType::Word },
		{ "EDialogueTokenType::Whitespace", (int64)EDialogueTokenType::Whitespace },
		{ "EDialogueTokenType::Punctuation", (int64)EDialogueTokenType::Punctuation },
		{ "EDialogueTokenType::Mixed", (int64)EDialogueTokenType::Mixed },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_ReusableDialogueSystem_EDialogueTokenType_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ReusableDialogueSystem_EDialogueTokenType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ReusableDialogueSystem,
	nullptr,
	"EDialogueTokenType",
	"EDialogueTokenType",
	Z_Construct_UEnum_ReusableDialogueSystem_EDialogueTokenType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ReusableDialogueSystem_EDialogueTokenType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ReusableDialogueSystem_EDialogueTokenType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ReusableDialogueSystem_EDialogueTokenType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EDialogueTokenType()
{
	if (!Z_Registration_Info_UEnum_EDialogueTokenType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDialogueTokenType.InnerSingleton, Z_Construct_UEnum_ReusableDialogueSystem_EDialogueTokenType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EDialogueTokenType.InnerSingleton;
}
// ********** End Enum EDialogueTokenType **********************************************************

// ********** Begin ScriptStruct FDialogueLine *****************************************************
struct Z_Construct_UScriptStruct_FDialogueLine_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDialogueLine); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDialogueLine); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LineId_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Speaker_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeakerNameOverride_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogueText_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
		{ "MultiLine", "TRUE" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RevealMode_MetaData[] = {
		{ "Category", "Reveal" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WordIntervalOverride_MetaData[] = {
		{ "Category", "Reveal" },
		{ "ClampMin", "-1.0" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterIntervalOverride_MetaData[] = {
		{ "Category", "Reveal" },
		{ "ClampMin", "-1.0" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartDelay_MetaData[] = {
		{ "Category", "Timing" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EndDelay_MetaData[] = {
		{ "Category", "Timing" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bWaitForPlayerInput_MetaData[] = {
		{ "Category", "Flow" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanSkipReveal_MetaData[] = {
		{ "Category", "Flow" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoAdvance_MetaData[] = {
		{ "Category", "Flow" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AutoAdvanceDelay_MetaData[] = {
		{ "Category", "Flow" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VoiceSound_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextSoundSetOverride_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDisableTextSound_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextSoundTriggerMode_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SoundEveryNCharactersOverride_MetaData[] = {
		{ "Category", "Audio" },
		{ "ClampMin", "-1" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumTextSoundIntervalOverride_MetaData[] = {
		{ "Category", "Audio" },
		{ "ClampMin", "-1.0" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LineTags_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDialogueLine constinit property declarations *********************
	static const UECodeGen_Private::FNamePropertyParams NewProp_LineId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Speaker;
	static const UECodeGen_Private::FTextPropertyParams NewProp_SpeakerNameOverride;
	static const UECodeGen_Private::FTextPropertyParams NewProp_DialogueText;
	static const UECodeGen_Private::FBytePropertyParams NewProp_RevealMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_RevealMode;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WordIntervalOverride;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CharacterIntervalOverride;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StartDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EndDelay;
	static void NewProp_bWaitForPlayerInput_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWaitForPlayerInput;
	static void NewProp_bCanSkipReveal_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanSkipReveal;
	static void NewProp_bAutoAdvance_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoAdvance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AutoAdvanceDelay;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VoiceSound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TextSoundSetOverride;
	static void NewProp_bDisableTextSound_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDisableTextSound;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TextSoundTriggerMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TextSoundTriggerMode;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SoundEveryNCharactersOverride;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinimumTextSoundIntervalOverride;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LineTags;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDialogueLine constinit property declarations ***********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDialogueLine>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDialogueLine_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDialogueLine;
class UScriptStruct* FDialogueLine::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDialogueLine.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDialogueLine.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDialogueLine, (UObject*)Z_Construct_UPackage__Script_ReusableDialogueSystem(), TEXT("DialogueLine"));
	}
	return Z_Registration_Info_UScriptStruct_FDialogueLine.OuterSingleton;
	}

// ********** Begin ScriptStruct FDialogueLine Property Definitions ********************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_LineId = { "LineId", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueLine, LineId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LineId_MetaData), NewProp_LineId_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_Speaker = { "Speaker", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueLine, Speaker), Z_Construct_UClass_UDialogueSpeakerProfile_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Speaker_MetaData), NewProp_Speaker_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_SpeakerNameOverride = { "SpeakerNameOverride", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueLine, SpeakerNameOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeakerNameOverride_MetaData), NewProp_SpeakerNameOverride_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_DialogueText = { "DialogueText", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueLine, DialogueText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogueText_MetaData), NewProp_DialogueText_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_RevealMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_RevealMode = { "RevealMode", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueLine, RevealMode), Z_Construct_UEnum_ReusableDialogueSystem_EDialogueRevealMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RevealMode_MetaData), NewProp_RevealMode_MetaData) }; // 3637322456
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_WordIntervalOverride = { "WordIntervalOverride", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueLine, WordIntervalOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WordIntervalOverride_MetaData), NewProp_WordIntervalOverride_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_CharacterIntervalOverride = { "CharacterIntervalOverride", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueLine, CharacterIntervalOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterIntervalOverride_MetaData), NewProp_CharacterIntervalOverride_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_StartDelay = { "StartDelay", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueLine, StartDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartDelay_MetaData), NewProp_StartDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_EndDelay = { "EndDelay", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueLine, EndDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EndDelay_MetaData), NewProp_EndDelay_MetaData) };
void Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_bWaitForPlayerInput_SetBit(void* Obj)
{
	((FDialogueLine*)Obj)->bWaitForPlayerInput = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_bWaitForPlayerInput = { "bWaitForPlayerInput", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDialogueLine), &Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_bWaitForPlayerInput_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bWaitForPlayerInput_MetaData), NewProp_bWaitForPlayerInput_MetaData) };
void Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_bCanSkipReveal_SetBit(void* Obj)
{
	((FDialogueLine*)Obj)->bCanSkipReveal = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_bCanSkipReveal = { "bCanSkipReveal", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDialogueLine), &Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_bCanSkipReveal_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanSkipReveal_MetaData), NewProp_bCanSkipReveal_MetaData) };
void Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_bAutoAdvance_SetBit(void* Obj)
{
	((FDialogueLine*)Obj)->bAutoAdvance = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_bAutoAdvance = { "bAutoAdvance", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDialogueLine), &Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_bAutoAdvance_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoAdvance_MetaData), NewProp_bAutoAdvance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_AutoAdvanceDelay = { "AutoAdvanceDelay", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueLine, AutoAdvanceDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AutoAdvanceDelay_MetaData), NewProp_AutoAdvanceDelay_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_VoiceSound = { "VoiceSound", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueLine, VoiceSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VoiceSound_MetaData), NewProp_VoiceSound_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_TextSoundSetOverride = { "TextSoundSetOverride", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueLine, TextSoundSetOverride), Z_Construct_UClass_UDialogueTextSoundSet_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextSoundSetOverride_MetaData), NewProp_TextSoundSetOverride_MetaData) };
void Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_bDisableTextSound_SetBit(void* Obj)
{
	((FDialogueLine*)Obj)->bDisableTextSound = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_bDisableTextSound = { "bDisableTextSound", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDialogueLine), &Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_bDisableTextSound_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDisableTextSound_MetaData), NewProp_bDisableTextSound_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_TextSoundTriggerMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_TextSoundTriggerMode = { "TextSoundTriggerMode", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueLine, TextSoundTriggerMode), Z_Construct_UEnum_ReusableDialogueSystem_EDialogueTextSoundTriggerMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextSoundTriggerMode_MetaData), NewProp_TextSoundTriggerMode_MetaData) }; // 457344017
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_SoundEveryNCharactersOverride = { "SoundEveryNCharactersOverride", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueLine, SoundEveryNCharactersOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SoundEveryNCharactersOverride_MetaData), NewProp_SoundEveryNCharactersOverride_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_MinimumTextSoundIntervalOverride = { "MinimumTextSoundIntervalOverride", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueLine, MinimumTextSoundIntervalOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumTextSoundIntervalOverride_MetaData), NewProp_MinimumTextSoundIntervalOverride_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_LineTags = { "LineTags", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueLine, LineTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LineTags_MetaData), NewProp_LineTags_MetaData) }; // 3438578166
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDialogueLine_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_LineId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_Speaker,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_SpeakerNameOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_DialogueText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_RevealMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_RevealMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_WordIntervalOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_CharacterIntervalOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_StartDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_EndDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_bWaitForPlayerInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_bCanSkipReveal,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_bAutoAdvance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_AutoAdvanceDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_VoiceSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_TextSoundSetOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_bDisableTextSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_TextSoundTriggerMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_TextSoundTriggerMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_SoundEveryNCharactersOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_MinimumTextSoundIntervalOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueLine_Statics::NewProp_LineTags,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueLine_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDialogueLine Property Definitions **********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDialogueLine_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ReusableDialogueSystem,
	nullptr,
	&NewStructOps,
	"DialogueLine",
	Z_Construct_UScriptStruct_FDialogueLine_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueLine_Statics::PropPointers),
	sizeof(FDialogueLine),
	alignof(FDialogueLine),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueLine_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDialogueLine_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDialogueLine()
{
	if (!Z_Registration_Info_UScriptStruct_FDialogueLine.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDialogueLine.InnerSingleton, Z_Construct_UScriptStruct_FDialogueLine_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDialogueLine.InnerSingleton);
}
// ********** End ScriptStruct FDialogueLine *******************************************************

// ********** Begin ScriptStruct FDialogueHistoryEntry *********************************************
struct Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDialogueHistoryEntry); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDialogueHistoryEntry); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SequenceId_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LineId_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LineIndex_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeakerName_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogueText_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Timestamp_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VoiceSound_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/ReusableDialogueTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDialogueHistoryEntry constinit property declarations *************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SequenceId;
	static const UECodeGen_Private::FNamePropertyParams NewProp_LineId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LineIndex;
	static const UECodeGen_Private::FTextPropertyParams NewProp_SpeakerName;
	static const UECodeGen_Private::FTextPropertyParams NewProp_DialogueText;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Timestamp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VoiceSound;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDialogueHistoryEntry constinit property declarations ***************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDialogueHistoryEntry>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDialogueHistoryEntry;
class UScriptStruct* FDialogueHistoryEntry::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDialogueHistoryEntry.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDialogueHistoryEntry.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDialogueHistoryEntry, (UObject*)Z_Construct_UPackage__Script_ReusableDialogueSystem(), TEXT("DialogueHistoryEntry"));
	}
	return Z_Registration_Info_UScriptStruct_FDialogueHistoryEntry.OuterSingleton;
	}

// ********** Begin ScriptStruct FDialogueHistoryEntry Property Definitions ************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics::NewProp_SequenceId = { "SequenceId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueHistoryEntry, SequenceId), Z_Construct_UScriptStruct_FPrimaryAssetId, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SequenceId_MetaData), NewProp_SequenceId_MetaData) }; // 265326925
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics::NewProp_LineId = { "LineId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueHistoryEntry, LineId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LineId_MetaData), NewProp_LineId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics::NewProp_LineIndex = { "LineIndex", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueHistoryEntry, LineIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LineIndex_MetaData), NewProp_LineIndex_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics::NewProp_SpeakerName = { "SpeakerName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueHistoryEntry, SpeakerName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeakerName_MetaData), NewProp_SpeakerName_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics::NewProp_DialogueText = { "DialogueText", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueHistoryEntry, DialogueText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogueText_MetaData), NewProp_DialogueText_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics::NewProp_Timestamp = { "Timestamp", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueHistoryEntry, Timestamp), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Timestamp_MetaData), NewProp_Timestamp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics::NewProp_VoiceSound = { "VoiceSound", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDialogueHistoryEntry, VoiceSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VoiceSound_MetaData), NewProp_VoiceSound_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics::NewProp_SequenceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics::NewProp_LineId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics::NewProp_LineIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics::NewProp_SpeakerName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics::NewProp_DialogueText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics::NewProp_Timestamp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics::NewProp_VoiceSound,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDialogueHistoryEntry Property Definitions **************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ReusableDialogueSystem,
	nullptr,
	&NewStructOps,
	"DialogueHistoryEntry",
	Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics::PropPointers),
	sizeof(FDialogueHistoryEntry),
	alignof(FDialogueHistoryEntry),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDialogueHistoryEntry()
{
	if (!Z_Registration_Info_UScriptStruct_FDialogueHistoryEntry.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDialogueHistoryEntry.InnerSingleton, Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDialogueHistoryEntry.InnerSingleton);
}
// ********** End ScriptStruct FDialogueHistoryEntry ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_ReusableDialogueTypes_h__Script_ReusableDialogueSystem_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EDialogueState_StaticEnum, TEXT("EDialogueState"), &Z_Registration_Info_UEnum_EDialogueState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 657167223U) },
		{ EDialogueRevealMode_StaticEnum, TEXT("EDialogueRevealMode"), &Z_Registration_Info_UEnum_EDialogueRevealMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3637322456U) },
		{ EDialogueInteractionMode_StaticEnum, TEXT("EDialogueInteractionMode"), &Z_Registration_Info_UEnum_EDialogueInteractionMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3853692148U) },
		{ EExistingDialoguePolicy_StaticEnum, TEXT("EExistingDialoguePolicy"), &Z_Registration_Info_UEnum_EExistingDialoguePolicy, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3634757249U) },
		{ EDialogueTextSoundTriggerMode_StaticEnum, TEXT("EDialogueTextSoundTriggerMode"), &Z_Registration_Info_UEnum_EDialogueTextSoundTriggerMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 457344017U) },
		{ EDialogueEndReason_StaticEnum, TEXT("EDialogueEndReason"), &Z_Registration_Info_UEnum_EDialogueEndReason, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3091157201U) },
		{ EDialogueTokenType_StaticEnum, TEXT("EDialogueTokenType"), &Z_Registration_Info_UEnum_EDialogueTokenType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 651212348U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FDialogueLine::StaticStruct, Z_Construct_UScriptStruct_FDialogueLine_Statics::NewStructOps, TEXT("DialogueLine"),&Z_Registration_Info_UScriptStruct_FDialogueLine, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDialogueLine), 3166424386U) },
		{ FDialogueHistoryEntry::StaticStruct, Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics::NewStructOps, TEXT("DialogueHistoryEntry"),&Z_Registration_Info_UScriptStruct_FDialogueHistoryEntry, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDialogueHistoryEntry), 695882414U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_ReusableDialogueTypes_h__Script_ReusableDialogueSystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_ReusableDialogueTypes_h__Script_ReusableDialogueSystem_2698041520{
	TEXT("/Script/ReusableDialogueSystem"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_ReusableDialogueTypes_h__Script_ReusableDialogueSystem_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_ReusableDialogueTypes_h__Script_ReusableDialogueSystem_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_ReusableDialogueTypes_h__Script_ReusableDialogueSystem_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_ReusableDialogueTypes_h__Script_ReusableDialogueSystem_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
