// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Door/JMDoorTypes.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMDoorTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorAccessMatchMode();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorBlockBehavior();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorCommand();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorOpenDirectionMode();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorResultCode();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorState();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorOpenMode();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanelSelectionMode();
JMDOORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMDoorAccessRequirement();
JMDOORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMDoorNoiseEvent();
JMDOORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMDoorResult();
JMDOORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMDoorSaveData();
JMDOORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMDoorUseContext();
UPackage* Z_Construct_UPackage__Script_JMDoorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EJMDoorState **************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMDoorState;
static UEnum* EJMDoorState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMDoorState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMDoorState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMDoorRuntime_EJMDoorState, (UObject*)Z_Construct_UPackage__Script_JMDoorRuntime(), TEXT("EJMDoorState"));
	}
	return Z_Registration_Info_UEnum_EJMDoorState.OuterSingleton;
}
template<> JMDOORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMDoorState>()
{
	return EJMDoorState_StaticEnum();
}
struct Z_Construct_UEnum_JMDoorRuntime_EJMDoorState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Blocked.Name", "EJMDoorState::Blocked" },
		{ "BlueprintType", "true" },
		{ "Broken.Name", "EJMDoorState::Broken" },
		{ "Closed.Name", "EJMDoorState::Closed" },
		{ "Closing.Name", "EJMDoorState::Closing" },
		{ "Jammed.Name", "EJMDoorState::Jammed" },
		{ "Locked.Name", "EJMDoorState::Locked" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
		{ "Open.Name", "EJMDoorState::Open" },
		{ "Opening.Name", "EJMDoorState::Opening" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMDoorState::Closed", (int64)EJMDoorState::Closed },
		{ "EJMDoorState::Opening", (int64)EJMDoorState::Opening },
		{ "EJMDoorState::Open", (int64)EJMDoorState::Open },
		{ "EJMDoorState::Closing", (int64)EJMDoorState::Closing },
		{ "EJMDoorState::Locked", (int64)EJMDoorState::Locked },
		{ "EJMDoorState::Blocked", (int64)EJMDoorState::Blocked },
		{ "EJMDoorState::Jammed", (int64)EJMDoorState::Jammed },
		{ "EJMDoorState::Broken", (int64)EJMDoorState::Broken },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMDoorRuntime_EJMDoorState_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMDoorRuntime_EJMDoorState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMDoorRuntime,
	nullptr,
	"EJMDoorState",
	"EJMDoorState",
	Z_Construct_UEnum_JMDoorRuntime_EJMDoorState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMDoorRuntime_EJMDoorState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMDoorRuntime_EJMDoorState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMDoorRuntime_EJMDoorState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorState()
{
	if (!Z_Registration_Info_UEnum_EJMDoorState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMDoorState.InnerSingleton, Z_Construct_UEnum_JMDoorRuntime_EJMDoorState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMDoorState.InnerSingleton;
}
// ********** End Enum EJMDoorState ****************************************************************

// ********** Begin Enum EJMDoorCommand ************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMDoorCommand;
static UEnum* EJMDoorCommand_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMDoorCommand.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMDoorCommand.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMDoorRuntime_EJMDoorCommand, (UObject*)Z_Construct_UPackage__Script_JMDoorRuntime(), TEXT("EJMDoorCommand"));
	}
	return Z_Registration_Info_UEnum_EJMDoorCommand.OuterSingleton;
}
template<> JMDOORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMDoorCommand>()
{
	return EJMDoorCommand_StaticEnum();
}
struct Z_Construct_UEnum_JMDoorRuntime_EJMDoorCommand_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Close.Name", "EJMDoorCommand::Close" },
		{ "ForceOpen.Name", "EJMDoorCommand::ForceOpen" },
		{ "Lock.Name", "EJMDoorCommand::Lock" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
		{ "Open.Name", "EJMDoorCommand::Open" },
		{ "Toggle.Name", "EJMDoorCommand::Toggle" },
		{ "Unlock.Name", "EJMDoorCommand::Unlock" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMDoorCommand::Open", (int64)EJMDoorCommand::Open },
		{ "EJMDoorCommand::Close", (int64)EJMDoorCommand::Close },
		{ "EJMDoorCommand::Toggle", (int64)EJMDoorCommand::Toggle },
		{ "EJMDoorCommand::Unlock", (int64)EJMDoorCommand::Unlock },
		{ "EJMDoorCommand::Lock", (int64)EJMDoorCommand::Lock },
		{ "EJMDoorCommand::ForceOpen", (int64)EJMDoorCommand::ForceOpen },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMDoorRuntime_EJMDoorCommand_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMDoorRuntime_EJMDoorCommand_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMDoorRuntime,
	nullptr,
	"EJMDoorCommand",
	"EJMDoorCommand",
	Z_Construct_UEnum_JMDoorRuntime_EJMDoorCommand_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMDoorRuntime_EJMDoorCommand_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMDoorRuntime_EJMDoorCommand_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMDoorRuntime_EJMDoorCommand_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorCommand()
{
	if (!Z_Registration_Info_UEnum_EJMDoorCommand.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMDoorCommand.InnerSingleton, Z_Construct_UEnum_JMDoorRuntime_EJMDoorCommand_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMDoorCommand.InnerSingleton;
}
// ********** End Enum EJMDoorCommand **************************************************************

// ********** Begin Enum EJMDoorResultCode *********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMDoorResultCode;
static UEnum* EJMDoorResultCode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMDoorResultCode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMDoorResultCode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMDoorRuntime_EJMDoorResultCode, (UObject*)Z_Construct_UPackage__Script_JMDoorRuntime(), TEXT("EJMDoorResultCode"));
	}
	return Z_Registration_Info_UEnum_EJMDoorResultCode.OuterSingleton;
}
template<> JMDOORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMDoorResultCode>()
{
	return EJMDoorResultCode_StaticEnum();
}
struct Z_Construct_UEnum_JMDoorRuntime_EJMDoorResultCode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AccessDenied.Name", "EJMDoorResultCode::AccessDenied" },
		{ "AlreadyAtTarget.Name", "EJMDoorResultCode::AlreadyAtTarget" },
		{ "Blocked.Name", "EJMDoorResultCode::Blocked" },
		{ "BlueprintType", "true" },
		{ "Broken.Name", "EJMDoorResultCode::Broken" },
		{ "Disabled.Name", "EJMDoorResultCode::Disabled" },
		{ "InvalidRequest.Name", "EJMDoorResultCode::InvalidRequest" },
		{ "Jammed.Name", "EJMDoorResultCode::Jammed" },
		{ "Locked.Name", "EJMDoorResultCode::Locked" },
		{ "MissingMovementComponent.Name", "EJMDoorResultCode::MissingMovementComponent" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
		{ "Moving.Name", "EJMDoorResultCode::Moving" },
		{ "Succeeded.Name", "EJMDoorResultCode::Succeeded" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMDoorResultCode::Succeeded", (int64)EJMDoorResultCode::Succeeded },
		{ "EJMDoorResultCode::InvalidRequest", (int64)EJMDoorResultCode::InvalidRequest },
		{ "EJMDoorResultCode::Disabled", (int64)EJMDoorResultCode::Disabled },
		{ "EJMDoorResultCode::AccessDenied", (int64)EJMDoorResultCode::AccessDenied },
		{ "EJMDoorResultCode::Locked", (int64)EJMDoorResultCode::Locked },
		{ "EJMDoorResultCode::AlreadyAtTarget", (int64)EJMDoorResultCode::AlreadyAtTarget },
		{ "EJMDoorResultCode::Moving", (int64)EJMDoorResultCode::Moving },
		{ "EJMDoorResultCode::Blocked", (int64)EJMDoorResultCode::Blocked },
		{ "EJMDoorResultCode::Jammed", (int64)EJMDoorResultCode::Jammed },
		{ "EJMDoorResultCode::Broken", (int64)EJMDoorResultCode::Broken },
		{ "EJMDoorResultCode::MissingMovementComponent", (int64)EJMDoorResultCode::MissingMovementComponent },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMDoorRuntime_EJMDoorResultCode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMDoorRuntime_EJMDoorResultCode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMDoorRuntime,
	nullptr,
	"EJMDoorResultCode",
	"EJMDoorResultCode",
	Z_Construct_UEnum_JMDoorRuntime_EJMDoorResultCode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMDoorRuntime_EJMDoorResultCode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMDoorRuntime_EJMDoorResultCode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMDoorRuntime_EJMDoorResultCode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorResultCode()
{
	if (!Z_Registration_Info_UEnum_EJMDoorResultCode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMDoorResultCode.InnerSingleton, Z_Construct_UEnum_JMDoorRuntime_EJMDoorResultCode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMDoorResultCode.InnerSingleton;
}
// ********** End Enum EJMDoorResultCode ***********************************************************

// ********** Begin Enum EJMDoorOpenDirectionMode **************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMDoorOpenDirectionMode;
static UEnum* EJMDoorOpenDirectionMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMDoorOpenDirectionMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMDoorOpenDirectionMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMDoorRuntime_EJMDoorOpenDirectionMode, (UObject*)Z_Construct_UPackage__Script_JMDoorRuntime(), TEXT("EJMDoorOpenDirectionMode"));
	}
	return Z_Registration_Info_UEnum_EJMDoorOpenDirectionMode.OuterSingleton;
}
template<> JMDOORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMDoorOpenDirectionMode>()
{
	return EJMDoorOpenDirectionMode_StaticEnum();
}
struct Z_Construct_UEnum_JMDoorRuntime_EJMDoorOpenDirectionMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AwayFromInteractor.Name", "EJMDoorOpenDirectionMode::AwayFromInteractor" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
		{ "Negative.Name", "EJMDoorOpenDirectionMode::Negative" },
		{ "Positive.Name", "EJMDoorOpenDirectionMode::Positive" },
		{ "TowardInteractor.Name", "EJMDoorOpenDirectionMode::TowardInteractor" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMDoorOpenDirectionMode::Positive", (int64)EJMDoorOpenDirectionMode::Positive },
		{ "EJMDoorOpenDirectionMode::Negative", (int64)EJMDoorOpenDirectionMode::Negative },
		{ "EJMDoorOpenDirectionMode::AwayFromInteractor", (int64)EJMDoorOpenDirectionMode::AwayFromInteractor },
		{ "EJMDoorOpenDirectionMode::TowardInteractor", (int64)EJMDoorOpenDirectionMode::TowardInteractor },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMDoorRuntime_EJMDoorOpenDirectionMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMDoorRuntime_EJMDoorOpenDirectionMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMDoorRuntime,
	nullptr,
	"EJMDoorOpenDirectionMode",
	"EJMDoorOpenDirectionMode",
	Z_Construct_UEnum_JMDoorRuntime_EJMDoorOpenDirectionMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMDoorRuntime_EJMDoorOpenDirectionMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMDoorRuntime_EJMDoorOpenDirectionMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMDoorRuntime_EJMDoorOpenDirectionMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorOpenDirectionMode()
{
	if (!Z_Registration_Info_UEnum_EJMDoorOpenDirectionMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMDoorOpenDirectionMode.InnerSingleton, Z_Construct_UEnum_JMDoorRuntime_EJMDoorOpenDirectionMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMDoorOpenDirectionMode.InnerSingleton;
}
// ********** End Enum EJMDoorOpenDirectionMode ****************************************************

// ********** Begin Enum EJMSlideDoorPanel *********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMSlideDoorPanel;
static UEnum* EJMSlideDoorPanel_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMSlideDoorPanel.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMSlideDoorPanel.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel, (UObject*)Z_Construct_UPackage__Script_JMDoorRuntime(), TEXT("EJMSlideDoorPanel"));
	}
	return Z_Registration_Info_UEnum_EJMSlideDoorPanel.OuterSingleton;
}
template<> JMDOORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMSlideDoorPanel>()
{
	return EJMSlideDoorPanel_StaticEnum();
}
struct Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Both.Name", "EJMSlideDoorPanel::Both" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Explicit panel selection for a two-panel sliding door. */" },
#endif
		{ "DoorA.Name", "EJMSlideDoorPanel::DoorA" },
		{ "DoorB.Name", "EJMSlideDoorPanel::DoorB" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Explicit panel selection for a two-panel sliding door." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMSlideDoorPanel::DoorA", (int64)EJMSlideDoorPanel::DoorA },
		{ "EJMSlideDoorPanel::DoorB", (int64)EJMSlideDoorPanel::DoorB },
		{ "EJMSlideDoorPanel::Both", (int64)EJMSlideDoorPanel::Both },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMDoorRuntime,
	nullptr,
	"EJMSlideDoorPanel",
	"EJMSlideDoorPanel",
	Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel()
{
	if (!Z_Registration_Info_UEnum_EJMSlideDoorPanel.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMSlideDoorPanel.InnerSingleton, Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMSlideDoorPanel.InnerSingleton;
}
// ********** End Enum EJMSlideDoorPanel ***********************************************************

// ********** Begin Enum EJMSlideDoorOpenMode ******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMSlideDoorOpenMode;
static UEnum* EJMSlideDoorOpenMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMSlideDoorOpenMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMSlideDoorOpenMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorOpenMode, (UObject*)Z_Construct_UPackage__Script_JMDoorRuntime(), TEXT("EJMSlideDoorOpenMode"));
	}
	return Z_Registration_Info_UEnum_EJMSlideDoorOpenMode.OuterSingleton;
}
template<> JMDOORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMSlideDoorOpenMode>()
{
	return EJMSlideDoorOpenMode_StaticEnum();
}
struct Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorOpenMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Panel(s) opened by the general OpenDoor command. */" },
#endif
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
		{ "OpenBoth.Name", "EJMSlideDoorOpenMode::OpenBoth" },
		{ "OpenDoorA.Name", "EJMSlideDoorOpenMode::OpenDoorA" },
		{ "OpenDoorB.Name", "EJMSlideDoorOpenMode::OpenDoorB" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Panel(s) opened by the general OpenDoor command." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMSlideDoorOpenMode::OpenDoorA", (int64)EJMSlideDoorOpenMode::OpenDoorA },
		{ "EJMSlideDoorOpenMode::OpenDoorB", (int64)EJMSlideDoorOpenMode::OpenDoorB },
		{ "EJMSlideDoorOpenMode::OpenBoth", (int64)EJMSlideDoorOpenMode::OpenBoth },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorOpenMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorOpenMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMDoorRuntime,
	nullptr,
	"EJMSlideDoorOpenMode",
	"EJMSlideDoorOpenMode",
	Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorOpenMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorOpenMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorOpenMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorOpenMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorOpenMode()
{
	if (!Z_Registration_Info_UEnum_EJMSlideDoorOpenMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMSlideDoorOpenMode.InnerSingleton, Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorOpenMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMSlideDoorOpenMode.InnerSingleton;
}
// ********** End Enum EJMSlideDoorOpenMode ********************************************************

// ********** Begin Enum EJMSlideDoorPanelSelectionMode ********************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMSlideDoorPanelSelectionMode;
static UEnum* EJMSlideDoorPanelSelectionMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMSlideDoorPanelSelectionMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMSlideDoorPanelSelectionMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanelSelectionMode, (UObject*)Z_Construct_UPackage__Script_JMDoorRuntime(), TEXT("EJMSlideDoorPanelSelectionMode"));
	}
	return Z_Registration_Info_UEnum_EJMSlideDoorPanelSelectionMode.OuterSingleton;
}
template<> JMDOORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMSlideDoorPanelSelectionMode>()
{
	return EJMSlideDoorPanelSelectionMode_StaticEnum();
}
struct Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanelSelectionMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** How the general OpenDoor command chooses a panel. Movement direction is never changed. */" },
#endif
		{ "ConfiguredPanel.Name", "EJMSlideDoorPanelSelectionMode::ConfiguredPanel" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
		{ "NearestPanel.Name", "EJMSlideDoorPanelSelectionMode::NearestPanel" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How the general OpenDoor command chooses a panel. Movement direction is never changed." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMSlideDoorPanelSelectionMode::ConfiguredPanel", (int64)EJMSlideDoorPanelSelectionMode::ConfiguredPanel },
		{ "EJMSlideDoorPanelSelectionMode::NearestPanel", (int64)EJMSlideDoorPanelSelectionMode::NearestPanel },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanelSelectionMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanelSelectionMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMDoorRuntime,
	nullptr,
	"EJMSlideDoorPanelSelectionMode",
	"EJMSlideDoorPanelSelectionMode",
	Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanelSelectionMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanelSelectionMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanelSelectionMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanelSelectionMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanelSelectionMode()
{
	if (!Z_Registration_Info_UEnum_EJMSlideDoorPanelSelectionMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMSlideDoorPanelSelectionMode.InnerSingleton, Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanelSelectionMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMSlideDoorPanelSelectionMode.InnerSingleton;
}
// ********** End Enum EJMSlideDoorPanelSelectionMode **********************************************

// ********** Begin Enum EJMDoorBlockBehavior ******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMDoorBlockBehavior;
static UEnum* EJMDoorBlockBehavior_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMDoorBlockBehavior.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMDoorBlockBehavior.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMDoorRuntime_EJMDoorBlockBehavior, (UObject*)Z_Construct_UPackage__Script_JMDoorRuntime(), TEXT("EJMDoorBlockBehavior"));
	}
	return Z_Registration_Info_UEnum_EJMDoorBlockBehavior.OuterSingleton;
}
template<> JMDOORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMDoorBlockBehavior>()
{
	return EJMDoorBlockBehavior_StaticEnum();
}
struct Z_Construct_UEnum_JMDoorRuntime_EJMDoorBlockBehavior_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Ignore.Name", "EJMDoorBlockBehavior::Ignore" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
		{ "Retry.Name", "EJMDoorBlockBehavior::Retry" },
		{ "Reverse.Name", "EJMDoorBlockBehavior::Reverse" },
		{ "Stop.Name", "EJMDoorBlockBehavior::Stop" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMDoorBlockBehavior::Stop", (int64)EJMDoorBlockBehavior::Stop },
		{ "EJMDoorBlockBehavior::Reverse", (int64)EJMDoorBlockBehavior::Reverse },
		{ "EJMDoorBlockBehavior::Retry", (int64)EJMDoorBlockBehavior::Retry },
		{ "EJMDoorBlockBehavior::Ignore", (int64)EJMDoorBlockBehavior::Ignore },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMDoorRuntime_EJMDoorBlockBehavior_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMDoorRuntime_EJMDoorBlockBehavior_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMDoorRuntime,
	nullptr,
	"EJMDoorBlockBehavior",
	"EJMDoorBlockBehavior",
	Z_Construct_UEnum_JMDoorRuntime_EJMDoorBlockBehavior_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMDoorRuntime_EJMDoorBlockBehavior_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMDoorRuntime_EJMDoorBlockBehavior_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMDoorRuntime_EJMDoorBlockBehavior_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorBlockBehavior()
{
	if (!Z_Registration_Info_UEnum_EJMDoorBlockBehavior.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMDoorBlockBehavior.InnerSingleton, Z_Construct_UEnum_JMDoorRuntime_EJMDoorBlockBehavior_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMDoorBlockBehavior.InnerSingleton;
}
// ********** End Enum EJMDoorBlockBehavior ********************************************************

// ********** Begin Enum EJMDoorAccessMatchMode ****************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMDoorAccessMatchMode;
static UEnum* EJMDoorAccessMatchMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMDoorAccessMatchMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMDoorAccessMatchMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMDoorRuntime_EJMDoorAccessMatchMode, (UObject*)Z_Construct_UPackage__Script_JMDoorRuntime(), TEXT("EJMDoorAccessMatchMode"));
	}
	return Z_Registration_Info_UEnum_EJMDoorAccessMatchMode.OuterSingleton;
}
template<> JMDOORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMDoorAccessMatchMode>()
{
	return EJMDoorAccessMatchMode_StaticEnum();
}
struct Z_Construct_UEnum_JMDoorRuntime_EJMDoorAccessMatchMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AllRequired.Name", "EJMDoorAccessMatchMode::AllRequired" },
		{ "AnyRequired.Name", "EJMDoorAccessMatchMode::AnyRequired" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMDoorAccessMatchMode::AllRequired", (int64)EJMDoorAccessMatchMode::AllRequired },
		{ "EJMDoorAccessMatchMode::AnyRequired", (int64)EJMDoorAccessMatchMode::AnyRequired },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMDoorRuntime_EJMDoorAccessMatchMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMDoorRuntime_EJMDoorAccessMatchMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMDoorRuntime,
	nullptr,
	"EJMDoorAccessMatchMode",
	"EJMDoorAccessMatchMode",
	Z_Construct_UEnum_JMDoorRuntime_EJMDoorAccessMatchMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMDoorRuntime_EJMDoorAccessMatchMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMDoorRuntime_EJMDoorAccessMatchMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMDoorRuntime_EJMDoorAccessMatchMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorAccessMatchMode()
{
	if (!Z_Registration_Info_UEnum_EJMDoorAccessMatchMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMDoorAccessMatchMode.InnerSingleton, Z_Construct_UEnum_JMDoorRuntime_EJMDoorAccessMatchMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMDoorAccessMatchMode.InnerSingleton;
}
// ********** End Enum EJMDoorAccessMatchMode ******************************************************

// ********** Begin ScriptStruct FJMDoorAccessRequirement ******************************************
struct Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMDoorAccessRequirement); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMDoorAccessRequirement); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequiredTags_MetaData[] = {
		{ "Category", "JM Door|Access" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MasterAccessTags_MetaData[] = {
		{ "Category", "JM Door|Access" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MatchMode_MetaData[] = {
		{ "Category", "JM Door|Access" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bConsumeAccess_MetaData[] = {
		{ "Category", "JM Door|Access" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMDoorAccessRequirement constinit property declarations **********
	static const UECodeGen_Private::FStructPropertyParams NewProp_RequiredTags;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MasterAccessTags;
	static const UECodeGen_Private::FBytePropertyParams NewProp_MatchMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_MatchMode;
	static void NewProp_bConsumeAccess_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bConsumeAccess;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMDoorAccessRequirement constinit property declarations ************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMDoorAccessRequirement>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMDoorAccessRequirement;
class UScriptStruct* FJMDoorAccessRequirement::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMDoorAccessRequirement.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMDoorAccessRequirement.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMDoorAccessRequirement, (UObject*)Z_Construct_UPackage__Script_JMDoorRuntime(), TEXT("JMDoorAccessRequirement"));
	}
	return Z_Registration_Info_UScriptStruct_FJMDoorAccessRequirement.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMDoorAccessRequirement Property Definitions *********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics::NewProp_RequiredTags = { "RequiredTags", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorAccessRequirement, RequiredTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequiredTags_MetaData), NewProp_RequiredTags_MetaData) }; // 3438578166
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics::NewProp_MasterAccessTags = { "MasterAccessTags", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorAccessRequirement, MasterAccessTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MasterAccessTags_MetaData), NewProp_MasterAccessTags_MetaData) }; // 3438578166
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics::NewProp_MatchMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics::NewProp_MatchMode = { "MatchMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorAccessRequirement, MatchMode), Z_Construct_UEnum_JMDoorRuntime_EJMDoorAccessMatchMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MatchMode_MetaData), NewProp_MatchMode_MetaData) }; // 1727283388
void Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics::NewProp_bConsumeAccess_SetBit(void* Obj)
{
	((FJMDoorAccessRequirement*)Obj)->bConsumeAccess = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics::NewProp_bConsumeAccess = { "bConsumeAccess", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMDoorAccessRequirement), &Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics::NewProp_bConsumeAccess_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bConsumeAccess_MetaData), NewProp_bConsumeAccess_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics::NewProp_RequiredTags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics::NewProp_MasterAccessTags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics::NewProp_MatchMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics::NewProp_MatchMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics::NewProp_bConsumeAccess,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMDoorAccessRequirement Property Definitions ***********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorRuntime,
	nullptr,
	&NewStructOps,
	"JMDoorAccessRequirement",
	Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics::PropPointers),
	sizeof(FJMDoorAccessRequirement),
	alignof(FJMDoorAccessRequirement),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMDoorAccessRequirement()
{
	if (!Z_Registration_Info_UScriptStruct_FJMDoorAccessRequirement.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMDoorAccessRequirement.InnerSingleton, Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMDoorAccessRequirement.InnerSingleton);
}
// ********** End ScriptStruct FJMDoorAccessRequirement ********************************************

// ********** Begin ScriptStruct FJMDoorUseContext *************************************************
struct Z_Construct_UScriptStruct_FJMDoorUseContext_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMDoorUseContext); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMDoorUseContext); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstigatorActor_MetaData[] = {
		{ "Category", "JM Door" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstigatorController_MetaData[] = {
		{ "Category", "JM Door" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionLocation_MetaData[] = {
		{ "Category", "JM Door" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionDirection_MetaData[] = {
		{ "Category", "JM Door" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Direction in which the interactor is looking/using. Used to swing away from the interaction. */" },
#endif
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Direction in which the interactor is looking/using. Used to swing away from the interaction." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AccessTags_MetaData[] = {
		{ "Category", "JM Door" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AccessObject_MetaData[] = {
		{ "Category", "JM Door" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional directly linked key/card/item object. No Gameplay Tags are required. */" },
#endif
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional directly linked key/card/item object. No Gameplay Tags are required." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsAI_MetaData[] = {
		{ "Category", "JM Door" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bQuiet_MetaData[] = {
		{ "Category", "JM Door" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bFast_MetaData[] = {
		{ "Category", "JM Door" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequestedOpenFraction_MetaData[] = {
		{ "Category", "JM Door" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMDoorUseContext constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InstigatorActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InstigatorController;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InteractionLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InteractionDirection;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AccessTags;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AccessObject;
	static void NewProp_bIsAI_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsAI;
	static void NewProp_bQuiet_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bQuiet;
	static void NewProp_bFast_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFast;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RequestedOpenFraction;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMDoorUseContext constinit property declarations *******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMDoorUseContext>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMDoorUseContext_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMDoorUseContext;
class UScriptStruct* FJMDoorUseContext::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMDoorUseContext.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMDoorUseContext.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMDoorUseContext, (UObject*)Z_Construct_UPackage__Script_JMDoorRuntime(), TEXT("JMDoorUseContext"));
	}
	return Z_Registration_Info_UScriptStruct_FJMDoorUseContext.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMDoorUseContext Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_InstigatorActor = { "InstigatorActor", nullptr, (EPropertyFlags)0x0114000000000004, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorUseContext, InstigatorActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstigatorActor_MetaData), NewProp_InstigatorActor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_InstigatorController = { "InstigatorController", nullptr, (EPropertyFlags)0x0114000000000004, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorUseContext, InstigatorController), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstigatorController_MetaData), NewProp_InstigatorController_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_InteractionLocation = { "InteractionLocation", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorUseContext, InteractionLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionLocation_MetaData), NewProp_InteractionLocation_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_InteractionDirection = { "InteractionDirection", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorUseContext, InteractionDirection), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionDirection_MetaData), NewProp_InteractionDirection_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_AccessTags = { "AccessTags", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorUseContext, AccessTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AccessTags_MetaData), NewProp_AccessTags_MetaData) }; // 3438578166
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_AccessObject = { "AccessObject", nullptr, (EPropertyFlags)0x0114000000000004, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorUseContext, AccessObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AccessObject_MetaData), NewProp_AccessObject_MetaData) };
void Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_bIsAI_SetBit(void* Obj)
{
	((FJMDoorUseContext*)Obj)->bIsAI = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_bIsAI = { "bIsAI", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMDoorUseContext), &Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_bIsAI_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsAI_MetaData), NewProp_bIsAI_MetaData) };
void Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_bQuiet_SetBit(void* Obj)
{
	((FJMDoorUseContext*)Obj)->bQuiet = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_bQuiet = { "bQuiet", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMDoorUseContext), &Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_bQuiet_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bQuiet_MetaData), NewProp_bQuiet_MetaData) };
void Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_bFast_SetBit(void* Obj)
{
	((FJMDoorUseContext*)Obj)->bFast = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_bFast = { "bFast", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMDoorUseContext), &Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_bFast_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bFast_MetaData), NewProp_bFast_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_RequestedOpenFraction = { "RequestedOpenFraction", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorUseContext, RequestedOpenFraction), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequestedOpenFraction_MetaData), NewProp_RequestedOpenFraction_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_InstigatorActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_InstigatorController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_InteractionLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_InteractionDirection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_AccessTags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_AccessObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_bIsAI,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_bQuiet,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_bFast,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewProp_RequestedOpenFraction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMDoorUseContext Property Definitions ******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorRuntime,
	nullptr,
	&NewStructOps,
	"JMDoorUseContext",
	Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::PropPointers),
	sizeof(FJMDoorUseContext),
	alignof(FJMDoorUseContext),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMDoorUseContext()
{
	if (!Z_Registration_Info_UScriptStruct_FJMDoorUseContext.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMDoorUseContext.InnerSingleton, Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMDoorUseContext.InnerSingleton);
}
// ********** End ScriptStruct FJMDoorUseContext ***************************************************

// ********** Begin ScriptStruct FJMDoorResult *****************************************************
struct Z_Construct_UScriptStruct_FJMDoorResult_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMDoorResult); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMDoorResult); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSucceeded_MetaData[] = {
		{ "Category", "JM Door" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Code_MetaData[] = {
		{ "Category", "JM Door" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "Category", "JM Door" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMDoorResult constinit property declarations *********************
	static void NewProp_bSucceeded_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSucceeded;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Code_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Code;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMDoorResult constinit property declarations ***********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMDoorResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMDoorResult_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMDoorResult;
class UScriptStruct* FJMDoorResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMDoorResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMDoorResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMDoorResult, (UObject*)Z_Construct_UPackage__Script_JMDoorRuntime(), TEXT("JMDoorResult"));
	}
	return Z_Registration_Info_UScriptStruct_FJMDoorResult.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMDoorResult Property Definitions ********************************
void Z_Construct_UScriptStruct_FJMDoorResult_Statics::NewProp_bSucceeded_SetBit(void* Obj)
{
	((FJMDoorResult*)Obj)->bSucceeded = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMDoorResult_Statics::NewProp_bSucceeded = { "bSucceeded", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMDoorResult), &Z_Construct_UScriptStruct_FJMDoorResult_Statics::NewProp_bSucceeded_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSucceeded_MetaData), NewProp_bSucceeded_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMDoorResult_Statics::NewProp_Code_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMDoorResult_Statics::NewProp_Code = { "Code", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorResult, Code), Z_Construct_UEnum_JMDoorRuntime_EJMDoorResultCode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Code_MetaData), NewProp_Code_MetaData) }; // 1335454960
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FJMDoorResult_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorResult, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMDoorResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorResult_Statics::NewProp_bSucceeded,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorResult_Statics::NewProp_Code_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorResult_Statics::NewProp_Code,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorResult_Statics::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMDoorResult_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMDoorResult Property Definitions **********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMDoorResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorRuntime,
	nullptr,
	&NewStructOps,
	"JMDoorResult",
	Z_Construct_UScriptStruct_FJMDoorResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMDoorResult_Statics::PropPointers),
	sizeof(FJMDoorResult),
	alignof(FJMDoorResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMDoorResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMDoorResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMDoorResult()
{
	if (!Z_Registration_Info_UScriptStruct_FJMDoorResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMDoorResult.InnerSingleton, Z_Construct_UScriptStruct_FJMDoorResult_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMDoorResult.InnerSingleton);
}
// ********** End ScriptStruct FJMDoorResult *******************************************************

// ********** Begin ScriptStruct FJMDoorNoiseEvent *************************************************
struct Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMDoorNoiseEvent); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMDoorNoiseEvent); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "Category", "JM Door|Noise" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Loudness_MetaData[] = {
		{ "Category", "JM Door|Noise" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxRange_MetaData[] = {
		{ "Category", "JM Door|Noise" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NoiseTag_MetaData[] = {
		{ "Category", "JM Door|Noise" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceActor_MetaData[] = {
		{ "Category", "JM Door|Noise" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstigatorActor_MetaData[] = {
		{ "Category", "JM Door|Noise" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMDoorNoiseEvent constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Loudness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxRange;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NoiseTag;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SourceActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InstigatorActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMDoorNoiseEvent constinit property declarations *******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMDoorNoiseEvent>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMDoorNoiseEvent;
class UScriptStruct* FJMDoorNoiseEvent::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMDoorNoiseEvent.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMDoorNoiseEvent.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMDoorNoiseEvent, (UObject*)Z_Construct_UPackage__Script_JMDoorRuntime(), TEXT("JMDoorNoiseEvent"));
	}
	return Z_Registration_Info_UScriptStruct_FJMDoorNoiseEvent.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMDoorNoiseEvent Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorNoiseEvent, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics::NewProp_Loudness = { "Loudness", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorNoiseEvent, Loudness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Loudness_MetaData), NewProp_Loudness_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics::NewProp_MaxRange = { "MaxRange", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorNoiseEvent, MaxRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxRange_MetaData), NewProp_MaxRange_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics::NewProp_NoiseTag = { "NoiseTag", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorNoiseEvent, NoiseTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NoiseTag_MetaData), NewProp_NoiseTag_MetaData) }; // 517357616
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics::NewProp_SourceActor = { "SourceActor", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorNoiseEvent, SourceActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceActor_MetaData), NewProp_SourceActor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics::NewProp_InstigatorActor = { "InstigatorActor", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorNoiseEvent, InstigatorActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstigatorActor_MetaData), NewProp_InstigatorActor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics::NewProp_Loudness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics::NewProp_MaxRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics::NewProp_NoiseTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics::NewProp_SourceActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics::NewProp_InstigatorActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMDoorNoiseEvent Property Definitions ******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorRuntime,
	nullptr,
	&NewStructOps,
	"JMDoorNoiseEvent",
	Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics::PropPointers),
	sizeof(FJMDoorNoiseEvent),
	alignof(FJMDoorNoiseEvent),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMDoorNoiseEvent()
{
	if (!Z_Registration_Info_UScriptStruct_FJMDoorNoiseEvent.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMDoorNoiseEvent.InnerSingleton, Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMDoorNoiseEvent.InnerSingleton);
}
// ********** End ScriptStruct FJMDoorNoiseEvent ***************************************************

// ********** Begin ScriptStruct FJMDoorSaveData ***************************************************
struct Z_Construct_UScriptStruct_FJMDoorSaveData_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMDoorSaveData); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMDoorSaveData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Version_MetaData[] = {
		{ "Category", "JM Door|Save" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PersistentId_MetaData[] = {
		{ "Category", "JM Door|Save" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_State_MetaData[] = {
		{ "Category", "JM Door|Save" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLocked_MetaData[] = {
		{ "Category", "JM Door|Save" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLockBroken_MetaData[] = {
		{ "Category", "JM Door|Save" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpenFraction_MetaData[] = {
		{ "Category", "JM Door|Save" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DoorDurability_MetaData[] = {
		{ "Category", "JM Door|Save" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LockDurability_MetaData[] = {
		{ "Category", "JM Door|Save" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlideDoorAOpenFraction_MetaData[] = {
		{ "Category", "JM Door|Save" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Independent sliding panel progress. Version 1 data migrates OpenFraction to panel A. */" },
#endif
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Independent sliding panel progress. Version 1 data migrates OpenFraction to panel A." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlideDoorBOpenFraction_MetaData[] = {
		{ "Category", "JM Door|Save" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlideDoorAState_MetaData[] = {
		{ "Category", "JM Door|Save" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlideDoorBState_MetaData[] = {
		{ "Category", "JM Door|Save" },
		{ "ModuleRelativePath", "Public/Door/JMDoorTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMDoorSaveData constinit property declarations *******************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Version;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PersistentId;
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static void NewProp_bLocked_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLocked;
	static void NewProp_bLockBroken_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLockBroken;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OpenFraction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DoorDurability;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LockDurability;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SlideDoorAOpenFraction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SlideDoorBOpenFraction;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlideDoorAState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlideDoorAState;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlideDoorBState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlideDoorBState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMDoorSaveData constinit property declarations *********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMDoorSaveData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMDoorSaveData_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMDoorSaveData;
class UScriptStruct* FJMDoorSaveData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMDoorSaveData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMDoorSaveData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMDoorSaveData, (UObject*)Z_Construct_UPackage__Script_JMDoorRuntime(), TEXT("JMDoorSaveData"));
	}
	return Z_Registration_Info_UScriptStruct_FJMDoorSaveData.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMDoorSaveData Property Definitions ******************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_Version = { "Version", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorSaveData, Version), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Version_MetaData), NewProp_Version_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_PersistentId = { "PersistentId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorSaveData, PersistentId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PersistentId_MetaData), NewProp_PersistentId_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorSaveData, State), Z_Construct_UEnum_JMDoorRuntime_EJMDoorState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_State_MetaData), NewProp_State_MetaData) }; // 2513049645
void Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_bLocked_SetBit(void* Obj)
{
	((FJMDoorSaveData*)Obj)->bLocked = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_bLocked = { "bLocked", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMDoorSaveData), &Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_bLocked_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLocked_MetaData), NewProp_bLocked_MetaData) };
void Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_bLockBroken_SetBit(void* Obj)
{
	((FJMDoorSaveData*)Obj)->bLockBroken = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_bLockBroken = { "bLockBroken", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMDoorSaveData), &Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_bLockBroken_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLockBroken_MetaData), NewProp_bLockBroken_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_OpenFraction = { "OpenFraction", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorSaveData, OpenFraction), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpenFraction_MetaData), NewProp_OpenFraction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_DoorDurability = { "DoorDurability", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorSaveData, DoorDurability), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DoorDurability_MetaData), NewProp_DoorDurability_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_LockDurability = { "LockDurability", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorSaveData, LockDurability), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LockDurability_MetaData), NewProp_LockDurability_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_SlideDoorAOpenFraction = { "SlideDoorAOpenFraction", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorSaveData, SlideDoorAOpenFraction), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlideDoorAOpenFraction_MetaData), NewProp_SlideDoorAOpenFraction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_SlideDoorBOpenFraction = { "SlideDoorBOpenFraction", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorSaveData, SlideDoorBOpenFraction), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlideDoorBOpenFraction_MetaData), NewProp_SlideDoorBOpenFraction_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_SlideDoorAState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_SlideDoorAState = { "SlideDoorAState", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorSaveData, SlideDoorAState), Z_Construct_UEnum_JMDoorRuntime_EJMDoorState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlideDoorAState_MetaData), NewProp_SlideDoorAState_MetaData) }; // 2513049645
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_SlideDoorBState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_SlideDoorBState = { "SlideDoorBState", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMDoorSaveData, SlideDoorBState), Z_Construct_UEnum_JMDoorRuntime_EJMDoorState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlideDoorBState_MetaData), NewProp_SlideDoorBState_MetaData) }; // 2513049645
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_Version,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_PersistentId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_State,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_bLocked,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_bLockBroken,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_OpenFraction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_DoorDurability,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_LockDurability,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_SlideDoorAOpenFraction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_SlideDoorBOpenFraction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_SlideDoorAState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_SlideDoorAState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_SlideDoorBState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewProp_SlideDoorBState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMDoorSaveData Property Definitions ********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorRuntime,
	nullptr,
	&NewStructOps,
	"JMDoorSaveData",
	Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::PropPointers),
	sizeof(FJMDoorSaveData),
	alignof(FJMDoorSaveData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMDoorSaveData()
{
	if (!Z_Registration_Info_UScriptStruct_FJMDoorSaveData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMDoorSaveData.InnerSingleton, Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMDoorSaveData.InnerSingleton);
}
// ********** End ScriptStruct FJMDoorSaveData *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorTypes_h__Script_JMDoorRuntime_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EJMDoorState_StaticEnum, TEXT("EJMDoorState"), &Z_Registration_Info_UEnum_EJMDoorState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2513049645U) },
		{ EJMDoorCommand_StaticEnum, TEXT("EJMDoorCommand"), &Z_Registration_Info_UEnum_EJMDoorCommand, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4018727221U) },
		{ EJMDoorResultCode_StaticEnum, TEXT("EJMDoorResultCode"), &Z_Registration_Info_UEnum_EJMDoorResultCode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1335454960U) },
		{ EJMDoorOpenDirectionMode_StaticEnum, TEXT("EJMDoorOpenDirectionMode"), &Z_Registration_Info_UEnum_EJMDoorOpenDirectionMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1573158568U) },
		{ EJMSlideDoorPanel_StaticEnum, TEXT("EJMSlideDoorPanel"), &Z_Registration_Info_UEnum_EJMSlideDoorPanel, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1478343840U) },
		{ EJMSlideDoorOpenMode_StaticEnum, TEXT("EJMSlideDoorOpenMode"), &Z_Registration_Info_UEnum_EJMSlideDoorOpenMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 342004029U) },
		{ EJMSlideDoorPanelSelectionMode_StaticEnum, TEXT("EJMSlideDoorPanelSelectionMode"), &Z_Registration_Info_UEnum_EJMSlideDoorPanelSelectionMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1922337433U) },
		{ EJMDoorBlockBehavior_StaticEnum, TEXT("EJMDoorBlockBehavior"), &Z_Registration_Info_UEnum_EJMDoorBlockBehavior, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1963034699U) },
		{ EJMDoorAccessMatchMode_StaticEnum, TEXT("EJMDoorAccessMatchMode"), &Z_Registration_Info_UEnum_EJMDoorAccessMatchMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1727283388U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FJMDoorAccessRequirement::StaticStruct, Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics::NewStructOps, TEXT("JMDoorAccessRequirement"),&Z_Registration_Info_UScriptStruct_FJMDoorAccessRequirement, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMDoorAccessRequirement), 3499309010U) },
		{ FJMDoorUseContext::StaticStruct, Z_Construct_UScriptStruct_FJMDoorUseContext_Statics::NewStructOps, TEXT("JMDoorUseContext"),&Z_Registration_Info_UScriptStruct_FJMDoorUseContext, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMDoorUseContext), 3552665729U) },
		{ FJMDoorResult::StaticStruct, Z_Construct_UScriptStruct_FJMDoorResult_Statics::NewStructOps, TEXT("JMDoorResult"),&Z_Registration_Info_UScriptStruct_FJMDoorResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMDoorResult), 1639184842U) },
		{ FJMDoorNoiseEvent::StaticStruct, Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics::NewStructOps, TEXT("JMDoorNoiseEvent"),&Z_Registration_Info_UScriptStruct_FJMDoorNoiseEvent, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMDoorNoiseEvent), 386806309U) },
		{ FJMDoorSaveData::StaticStruct, Z_Construct_UScriptStruct_FJMDoorSaveData_Statics::NewStructOps, TEXT("JMDoorSaveData"),&Z_Registration_Info_UScriptStruct_FJMDoorSaveData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMDoorSaveData), 362659228U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorTypes_h__Script_JMDoorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorTypes_h__Script_JMDoorRuntime_3992853588{
	TEXT("/Script/JMDoorRuntime"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorTypes_h__Script_JMDoorRuntime_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorTypes_h__Script_JMDoorRuntime_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorTypes_h__Script_JMDoorRuntime_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorTypes_h__Script_JMDoorRuntime_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
