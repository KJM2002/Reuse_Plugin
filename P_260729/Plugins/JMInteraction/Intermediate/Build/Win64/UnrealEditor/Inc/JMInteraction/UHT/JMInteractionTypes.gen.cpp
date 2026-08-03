// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Types/JMInteractionTypes.h"
#include "GameplayTagContainer.h"
#include "Layout/Margin.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMInteractionTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
JMINTERACTION_API UEnum* Z_Construct_UEnum_JMInteraction_EJMInteractionDetectionMode();
JMINTERACTION_API UEnum* Z_Construct_UEnum_JMInteraction_EJMInteractionPromptHiddenMode();
JMINTERACTION_API UEnum* Z_Construct_UEnum_JMInteraction_EJMInteractionResultCode();
JMINTERACTION_API UEnum* Z_Construct_UEnum_JMInteraction_EJMInteractionState();
JMINTERACTION_API UEnum* Z_Construct_UEnum_JMInteraction_EJMInteractionTraceMode();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionContext();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionPrompt();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionPromptStyle();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionResult();
SLATE_API UEnum* Z_Construct_UEnum_Slate_ETextJustify();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FMargin();
UPackage* Z_Construct_UPackage__Script_JMInteraction();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EJMInteractionState *******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMInteractionState;
static UEnum* EJMInteractionState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMInteractionState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMInteractionState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMInteraction_EJMInteractionState, (UObject*)Z_Construct_UPackage__Script_JMInteraction(), TEXT("EJMInteractionState"));
	}
	return Z_Registration_Info_UEnum_EJMInteractionState.OuterSingleton;
}
template<> JMINTERACTION_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMInteractionState>()
{
	return EJMInteractionState_StaticEnum();
}
struct Z_Construct_UEnum_JMInteraction_EJMInteractionState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Disabled.Name", "EJMInteractionState::Disabled" },
		{ "Holding.Name", "EJMInteractionState::Holding" },
		{ "Idle.Name", "EJMInteractionState::Idle" },
		{ "Interacting.Name", "EJMInteractionState::Interacting" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
		{ "Targeting.Name", "EJMInteractionState::Targeting" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMInteractionState::Idle", (int64)EJMInteractionState::Idle },
		{ "EJMInteractionState::Targeting", (int64)EJMInteractionState::Targeting },
		{ "EJMInteractionState::Interacting", (int64)EJMInteractionState::Interacting },
		{ "EJMInteractionState::Holding", (int64)EJMInteractionState::Holding },
		{ "EJMInteractionState::Disabled", (int64)EJMInteractionState::Disabled },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMInteraction_EJMInteractionState_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMInteraction_EJMInteractionState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMInteraction,
	nullptr,
	"EJMInteractionState",
	"EJMInteractionState",
	Z_Construct_UEnum_JMInteraction_EJMInteractionState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMInteraction_EJMInteractionState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMInteraction_EJMInteractionState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMInteraction_EJMInteractionState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMInteraction_EJMInteractionState()
{
	if (!Z_Registration_Info_UEnum_EJMInteractionState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMInteractionState.InnerSingleton, Z_Construct_UEnum_JMInteraction_EJMInteractionState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMInteractionState.InnerSingleton;
}
// ********** End Enum EJMInteractionState *********************************************************

// ********** Begin Enum EJMInteractionResultCode **************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMInteractionResultCode;
static UEnum* EJMInteractionResultCode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMInteractionResultCode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMInteractionResultCode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMInteraction_EJMInteractionResultCode, (UObject*)Z_Construct_UPackage__Script_JMInteraction(), TEXT("EJMInteractionResultCode"));
	}
	return Z_Registration_Info_UEnum_EJMInteractionResultCode.OuterSingleton;
}
template<> JMINTERACTION_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMInteractionResultCode>()
{
	return EJMInteractionResultCode_StaticEnum();
}
struct Z_Construct_UEnum_JMInteraction_EJMInteractionResultCode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AlreadyInteracting.Name", "EJMInteractionResultCode::AlreadyInteracting" },
		{ "BlueprintType", "true" },
		{ "Disabled.Name", "EJMInteractionResultCode::Disabled" },
		{ "Failed.Name", "EJMInteractionResultCode::Failed" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
		{ "NotAllowed.Name", "EJMInteractionResultCode::NotAllowed" },
		{ "NoTarget.Name", "EJMInteractionResultCode::NoTarget" },
		{ "Succeeded.Name", "EJMInteractionResultCode::Succeeded" },
		{ "TargetInvalid.Name", "EJMInteractionResultCode::TargetInvalid" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMInteractionResultCode::Succeeded", (int64)EJMInteractionResultCode::Succeeded },
		{ "EJMInteractionResultCode::Failed", (int64)EJMInteractionResultCode::Failed },
		{ "EJMInteractionResultCode::Disabled", (int64)EJMInteractionResultCode::Disabled },
		{ "EJMInteractionResultCode::NoTarget", (int64)EJMInteractionResultCode::NoTarget },
		{ "EJMInteractionResultCode::TargetInvalid", (int64)EJMInteractionResultCode::TargetInvalid },
		{ "EJMInteractionResultCode::NotAllowed", (int64)EJMInteractionResultCode::NotAllowed },
		{ "EJMInteractionResultCode::AlreadyInteracting", (int64)EJMInteractionResultCode::AlreadyInteracting },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMInteraction_EJMInteractionResultCode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMInteraction_EJMInteractionResultCode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMInteraction,
	nullptr,
	"EJMInteractionResultCode",
	"EJMInteractionResultCode",
	Z_Construct_UEnum_JMInteraction_EJMInteractionResultCode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMInteraction_EJMInteractionResultCode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMInteraction_EJMInteractionResultCode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMInteraction_EJMInteractionResultCode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMInteraction_EJMInteractionResultCode()
{
	if (!Z_Registration_Info_UEnum_EJMInteractionResultCode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMInteractionResultCode.InnerSingleton, Z_Construct_UEnum_JMInteraction_EJMInteractionResultCode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMInteractionResultCode.InnerSingleton;
}
// ********** End Enum EJMInteractionResultCode ****************************************************

// ********** Begin Enum EJMInteractionDetectionMode ***********************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMInteractionDetectionMode;
static UEnum* EJMInteractionDetectionMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMInteractionDetectionMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMInteractionDetectionMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMInteraction_EJMInteractionDetectionMode, (UObject*)Z_Construct_UPackage__Script_JMInteraction(), TEXT("EJMInteractionDetectionMode"));
	}
	return Z_Registration_Info_UEnum_EJMInteractionDetectionMode.OuterSingleton;
}
template<> JMINTERACTION_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMInteractionDetectionMode>()
{
	return EJMInteractionDetectionMode_StaticEnum();
}
struct Z_Construct_UEnum_JMInteraction_EJMInteractionDetectionMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CenterScreenTrace.Name", "EJMInteractionDetectionMode::CenterScreenTrace" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
		{ "MouseCursorTrace.Name", "EJMInteractionDetectionMode::MouseCursorTrace" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMInteractionDetectionMode::CenterScreenTrace", (int64)EJMInteractionDetectionMode::CenterScreenTrace },
		{ "EJMInteractionDetectionMode::MouseCursorTrace", (int64)EJMInteractionDetectionMode::MouseCursorTrace },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMInteraction_EJMInteractionDetectionMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMInteraction_EJMInteractionDetectionMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMInteraction,
	nullptr,
	"EJMInteractionDetectionMode",
	"EJMInteractionDetectionMode",
	Z_Construct_UEnum_JMInteraction_EJMInteractionDetectionMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMInteraction_EJMInteractionDetectionMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMInteraction_EJMInteractionDetectionMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMInteraction_EJMInteractionDetectionMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMInteraction_EJMInteractionDetectionMode()
{
	if (!Z_Registration_Info_UEnum_EJMInteractionDetectionMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMInteractionDetectionMode.InnerSingleton, Z_Construct_UEnum_JMInteraction_EJMInteractionDetectionMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMInteractionDetectionMode.InnerSingleton;
}
// ********** End Enum EJMInteractionDetectionMode *************************************************

// ********** Begin Enum EJMInteractionTraceMode ***************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMInteractionTraceMode;
static UEnum* EJMInteractionTraceMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMInteractionTraceMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMInteractionTraceMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMInteraction_EJMInteractionTraceMode, (UObject*)Z_Construct_UPackage__Script_JMInteraction(), TEXT("EJMInteractionTraceMode"));
	}
	return Z_Registration_Info_UEnum_EJMInteractionTraceMode.OuterSingleton;
}
template<> JMINTERACTION_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMInteractionTraceMode>()
{
	return EJMInteractionTraceMode_StaticEnum();
}
struct Z_Construct_UEnum_JMInteraction_EJMInteractionTraceMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Manual.Name", "EJMInteractionTraceMode::Manual" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
		{ "OnInput.Name", "EJMInteractionTraceMode::OnInput" },
		{ "Tick.Name", "EJMInteractionTraceMode::Tick" },
		{ "Timer.Name", "EJMInteractionTraceMode::Timer" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMInteractionTraceMode::Manual", (int64)EJMInteractionTraceMode::Manual },
		{ "EJMInteractionTraceMode::OnInput", (int64)EJMInteractionTraceMode::OnInput },
		{ "EJMInteractionTraceMode::Timer", (int64)EJMInteractionTraceMode::Timer },
		{ "EJMInteractionTraceMode::Tick", (int64)EJMInteractionTraceMode::Tick },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMInteraction_EJMInteractionTraceMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMInteraction_EJMInteractionTraceMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMInteraction,
	nullptr,
	"EJMInteractionTraceMode",
	"EJMInteractionTraceMode",
	Z_Construct_UEnum_JMInteraction_EJMInteractionTraceMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMInteraction_EJMInteractionTraceMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMInteraction_EJMInteractionTraceMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMInteraction_EJMInteractionTraceMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMInteraction_EJMInteractionTraceMode()
{
	if (!Z_Registration_Info_UEnum_EJMInteractionTraceMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMInteractionTraceMode.InnerSingleton, Z_Construct_UEnum_JMInteraction_EJMInteractionTraceMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMInteractionTraceMode.InnerSingleton;
}
// ********** End Enum EJMInteractionTraceMode *****************************************************

// ********** Begin Enum EJMInteractionPromptHiddenMode ********************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMInteractionPromptHiddenMode;
static UEnum* EJMInteractionPromptHiddenMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMInteractionPromptHiddenMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMInteractionPromptHiddenMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMInteraction_EJMInteractionPromptHiddenMode, (UObject*)Z_Construct_UPackage__Script_JMInteraction(), TEXT("EJMInteractionPromptHiddenMode"));
	}
	return Z_Registration_Info_UEnum_EJMInteractionPromptHiddenMode.OuterSingleton;
}
template<> JMINTERACTION_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMInteractionPromptHiddenMode>()
{
	return EJMInteractionPromptHiddenMode_StaticEnum();
}
struct Z_Construct_UEnum_JMInteraction_EJMInteractionPromptHiddenMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Collapsed.Name", "EJMInteractionPromptHiddenMode::Collapsed" },
		{ "Hidden.Name", "EJMInteractionPromptHiddenMode::Hidden" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMInteractionPromptHiddenMode::Collapsed", (int64)EJMInteractionPromptHiddenMode::Collapsed },
		{ "EJMInteractionPromptHiddenMode::Hidden", (int64)EJMInteractionPromptHiddenMode::Hidden },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMInteraction_EJMInteractionPromptHiddenMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMInteraction_EJMInteractionPromptHiddenMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMInteraction,
	nullptr,
	"EJMInteractionPromptHiddenMode",
	"EJMInteractionPromptHiddenMode",
	Z_Construct_UEnum_JMInteraction_EJMInteractionPromptHiddenMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMInteraction_EJMInteractionPromptHiddenMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMInteraction_EJMInteractionPromptHiddenMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMInteraction_EJMInteractionPromptHiddenMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMInteraction_EJMInteractionPromptHiddenMode()
{
	if (!Z_Registration_Info_UEnum_EJMInteractionPromptHiddenMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMInteractionPromptHiddenMode.InnerSingleton, Z_Construct_UEnum_JMInteraction_EJMInteractionPromptHiddenMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMInteractionPromptHiddenMode.InnerSingleton;
}
// ********** End Enum EJMInteractionPromptHiddenMode **********************************************

// ********** Begin ScriptStruct FJMInteractionPromptStyle *****************************************
struct Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMInteractionPromptStyle); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMInteractionPromptStyle); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScreenOffset_MetaData[] = {
		{ "Category", "JM Interaction|Prompt UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Offset from the viewport center. Positive Y moves the prompt downward. */" },
#endif
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Offset from the viewport center. Positive Y moves the prompt downward." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FontSize_MetaData[] = {
		{ "Category", "JM Interaction|Prompt UI" },
		{ "ClampMax", "128" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderScale_MetaData[] = {
		{ "Category", "JM Interaction|Prompt UI" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Padding_MetaData[] = {
		{ "Category", "JM Interaction|Prompt UI" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextJustification_MetaData[] = {
		{ "Category", "JM Interaction|Prompt UI" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HiddenMode_MetaData[] = {
		{ "Category", "JM Interaction|Prompt UI" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMInteractionPromptStyle constinit property declarations *********
	static const UECodeGen_Private::FStructPropertyParams NewProp_ScreenOffset;
	static const UECodeGen_Private::FIntPropertyParams NewProp_FontSize;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RenderScale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Padding;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TextJustification;
	static const UECodeGen_Private::FBytePropertyParams NewProp_HiddenMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_HiddenMode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMInteractionPromptStyle constinit property declarations ***********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMInteractionPromptStyle>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMInteractionPromptStyle;
class UScriptStruct* FJMInteractionPromptStyle::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMInteractionPromptStyle.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMInteractionPromptStyle.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMInteractionPromptStyle, (UObject*)Z_Construct_UPackage__Script_JMInteraction(), TEXT("JMInteractionPromptStyle"));
	}
	return Z_Registration_Info_UScriptStruct_FJMInteractionPromptStyle.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMInteractionPromptStyle Property Definitions ********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics::NewProp_ScreenOffset = { "ScreenOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMInteractionPromptStyle, ScreenOffset), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScreenOffset_MetaData), NewProp_ScreenOffset_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics::NewProp_FontSize = { "FontSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMInteractionPromptStyle, FontSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FontSize_MetaData), NewProp_FontSize_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics::NewProp_RenderScale = { "RenderScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMInteractionPromptStyle, RenderScale), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderScale_MetaData), NewProp_RenderScale_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics::NewProp_Padding = { "Padding", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMInteractionPromptStyle, Padding), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Padding_MetaData), NewProp_Padding_MetaData) }; // 4099648758
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics::NewProp_TextJustification = { "TextJustification", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMInteractionPromptStyle, TextJustification), Z_Construct_UEnum_Slate_ETextJustify, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextJustification_MetaData), NewProp_TextJustification_MetaData) }; // 2449547307
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics::NewProp_HiddenMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics::NewProp_HiddenMode = { "HiddenMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMInteractionPromptStyle, HiddenMode), Z_Construct_UEnum_JMInteraction_EJMInteractionPromptHiddenMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HiddenMode_MetaData), NewProp_HiddenMode_MetaData) }; // 2694348291
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics::NewProp_ScreenOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics::NewProp_FontSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics::NewProp_RenderScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics::NewProp_Padding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics::NewProp_TextJustification,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics::NewProp_HiddenMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics::NewProp_HiddenMode,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMInteractionPromptStyle Property Definitions **********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMInteraction,
	nullptr,
	&NewStructOps,
	"JMInteractionPromptStyle",
	Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics::PropPointers),
	sizeof(FJMInteractionPromptStyle),
	alignof(FJMInteractionPromptStyle),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionPromptStyle()
{
	if (!Z_Registration_Info_UScriptStruct_FJMInteractionPromptStyle.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMInteractionPromptStyle.InnerSingleton, Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMInteractionPromptStyle.InnerSingleton);
}
// ********** End ScriptStruct FJMInteractionPromptStyle *******************************************

// ********** Begin ScriptStruct FJMInteractionResult **********************************************
struct Z_Construct_UScriptStruct_FJMInteractionResult_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMInteractionResult); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMInteractionResult); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSucceeded_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Code_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMInteractionResult constinit property declarations **************
	static void NewProp_bSucceeded_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSucceeded;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Code_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Code;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMInteractionResult constinit property declarations ****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMInteractionResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMInteractionResult_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMInteractionResult;
class UScriptStruct* FJMInteractionResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMInteractionResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMInteractionResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMInteractionResult, (UObject*)Z_Construct_UPackage__Script_JMInteraction(), TEXT("JMInteractionResult"));
	}
	return Z_Registration_Info_UScriptStruct_FJMInteractionResult.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMInteractionResult Property Definitions *************************
void Z_Construct_UScriptStruct_FJMInteractionResult_Statics::NewProp_bSucceeded_SetBit(void* Obj)
{
	((FJMInteractionResult*)Obj)->bSucceeded = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMInteractionResult_Statics::NewProp_bSucceeded = { "bSucceeded", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMInteractionResult), &Z_Construct_UScriptStruct_FJMInteractionResult_Statics::NewProp_bSucceeded_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSucceeded_MetaData), NewProp_bSucceeded_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMInteractionResult_Statics::NewProp_Code_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMInteractionResult_Statics::NewProp_Code = { "Code", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMInteractionResult, Code), Z_Construct_UEnum_JMInteraction_EJMInteractionResultCode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Code_MetaData), NewProp_Code_MetaData) }; // 308814958
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FJMInteractionResult_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMInteractionResult, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMInteractionResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMInteractionResult_Statics::NewProp_bSucceeded,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMInteractionResult_Statics::NewProp_Code_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMInteractionResult_Statics::NewProp_Code,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMInteractionResult_Statics::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMInteractionResult_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMInteractionResult Property Definitions ***************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMInteractionResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMInteraction,
	nullptr,
	&NewStructOps,
	"JMInteractionResult",
	Z_Construct_UScriptStruct_FJMInteractionResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMInteractionResult_Statics::PropPointers),
	sizeof(FJMInteractionResult),
	alignof(FJMInteractionResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMInteractionResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMInteractionResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionResult()
{
	if (!Z_Registration_Info_UScriptStruct_FJMInteractionResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMInteractionResult.InnerSingleton, Z_Construct_UScriptStruct_FJMInteractionResult_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMInteractionResult.InnerSingleton);
}
// ********** End ScriptStruct FJMInteractionResult ************************************************

// ********** Begin ScriptStruct FJMInteractionContext *********************************************
struct Z_Construct_UScriptStruct_FJMInteractionContext_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMInteractionContext); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMInteractionContext); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstigatorActor_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstigatorController_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetActor_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionLocation_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionDirection_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionTag_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstigatorTags_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMInteractionContext constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InstigatorActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InstigatorController;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InteractionLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InteractionDirection;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InteractionTag;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InstigatorTags;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMInteractionContext constinit property declarations ***************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMInteractionContext>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMInteractionContext_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMInteractionContext;
class UScriptStruct* FJMInteractionContext::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMInteractionContext.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMInteractionContext.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMInteractionContext, (UObject*)Z_Construct_UPackage__Script_JMInteraction(), TEXT("JMInteractionContext"));
	}
	return Z_Registration_Info_UScriptStruct_FJMInteractionContext.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMInteractionContext Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMInteractionContext_Statics::NewProp_InstigatorActor = { "InstigatorActor", nullptr, (EPropertyFlags)0x0114000000000004, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMInteractionContext, InstigatorActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstigatorActor_MetaData), NewProp_InstigatorActor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMInteractionContext_Statics::NewProp_InstigatorController = { "InstigatorController", nullptr, (EPropertyFlags)0x0114000000000004, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMInteractionContext, InstigatorController), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstigatorController_MetaData), NewProp_InstigatorController_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMInteractionContext_Statics::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0114000000000004, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMInteractionContext, TargetActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetActor_MetaData), NewProp_TargetActor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMInteractionContext_Statics::NewProp_InteractionLocation = { "InteractionLocation", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMInteractionContext, InteractionLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionLocation_MetaData), NewProp_InteractionLocation_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMInteractionContext_Statics::NewProp_InteractionDirection = { "InteractionDirection", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMInteractionContext, InteractionDirection), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionDirection_MetaData), NewProp_InteractionDirection_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMInteractionContext_Statics::NewProp_InteractionTag = { "InteractionTag", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMInteractionContext, InteractionTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionTag_MetaData), NewProp_InteractionTag_MetaData) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMInteractionContext_Statics::NewProp_InstigatorTags = { "InstigatorTags", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMInteractionContext, InstigatorTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstigatorTags_MetaData), NewProp_InstigatorTags_MetaData) }; // 3438578166
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMInteractionContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMInteractionContext_Statics::NewProp_InstigatorActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMInteractionContext_Statics::NewProp_InstigatorController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMInteractionContext_Statics::NewProp_TargetActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMInteractionContext_Statics::NewProp_InteractionLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMInteractionContext_Statics::NewProp_InteractionDirection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMInteractionContext_Statics::NewProp_InteractionTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMInteractionContext_Statics::NewProp_InstigatorTags,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMInteractionContext_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMInteractionContext Property Definitions **************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMInteractionContext_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMInteraction,
	nullptr,
	&NewStructOps,
	"JMInteractionContext",
	Z_Construct_UScriptStruct_FJMInteractionContext_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMInteractionContext_Statics::PropPointers),
	sizeof(FJMInteractionContext),
	alignof(FJMInteractionContext),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMInteractionContext_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMInteractionContext_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionContext()
{
	if (!Z_Registration_Info_UScriptStruct_FJMInteractionContext.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMInteractionContext.InnerSingleton, Z_Construct_UScriptStruct_FJMInteractionContext_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMInteractionContext.InnerSingleton);
}
// ********** End ScriptStruct FJMInteractionContext ***********************************************

// ********** Begin ScriptStruct FJMInteractionPrompt **********************************************
struct Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMInteractionPrompt); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMInteractionPrompt); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayText_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionTag_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HoldDuration_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Priority_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bVisible_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Types/JMInteractionTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMInteractionPrompt constinit property declarations **************
	static const UECodeGen_Private::FTextPropertyParams NewProp_DisplayText;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InteractionTag;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HoldDuration;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Priority;
	static void NewProp_bVisible_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bVisible;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMInteractionPrompt constinit property declarations ****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMInteractionPrompt>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMInteractionPrompt;
class UScriptStruct* FJMInteractionPrompt::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMInteractionPrompt.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMInteractionPrompt.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMInteractionPrompt, (UObject*)Z_Construct_UPackage__Script_JMInteraction(), TEXT("JMInteractionPrompt"));
	}
	return Z_Registration_Info_UScriptStruct_FJMInteractionPrompt.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMInteractionPrompt Property Definitions *************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics::NewProp_DisplayText = { "DisplayText", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMInteractionPrompt, DisplayText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayText_MetaData), NewProp_DisplayText_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics::NewProp_InteractionTag = { "InteractionTag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMInteractionPrompt, InteractionTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionTag_MetaData), NewProp_InteractionTag_MetaData) }; // 517357616
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics::NewProp_HoldDuration = { "HoldDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMInteractionPrompt, HoldDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HoldDuration_MetaData), NewProp_HoldDuration_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics::NewProp_Priority = { "Priority", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMInteractionPrompt, Priority), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Priority_MetaData), NewProp_Priority_MetaData) };
void Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics::NewProp_bVisible_SetBit(void* Obj)
{
	((FJMInteractionPrompt*)Obj)->bVisible = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics::NewProp_bVisible = { "bVisible", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMInteractionPrompt), &Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics::NewProp_bVisible_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bVisible_MetaData), NewProp_bVisible_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics::NewProp_DisplayText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics::NewProp_InteractionTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics::NewProp_HoldDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics::NewProp_Priority,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics::NewProp_bVisible,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMInteractionPrompt Property Definitions ***************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMInteraction,
	nullptr,
	&NewStructOps,
	"JMInteractionPrompt",
	Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics::PropPointers),
	sizeof(FJMInteractionPrompt),
	alignof(FJMInteractionPrompt),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionPrompt()
{
	if (!Z_Registration_Info_UScriptStruct_FJMInteractionPrompt.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMInteractionPrompt.InnerSingleton, Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMInteractionPrompt.InnerSingleton);
}
// ********** End ScriptStruct FJMInteractionPrompt ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Types_JMInteractionTypes_h__Script_JMInteraction_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EJMInteractionState_StaticEnum, TEXT("EJMInteractionState"), &Z_Registration_Info_UEnum_EJMInteractionState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2284070030U) },
		{ EJMInteractionResultCode_StaticEnum, TEXT("EJMInteractionResultCode"), &Z_Registration_Info_UEnum_EJMInteractionResultCode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 308814958U) },
		{ EJMInteractionDetectionMode_StaticEnum, TEXT("EJMInteractionDetectionMode"), &Z_Registration_Info_UEnum_EJMInteractionDetectionMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1585170584U) },
		{ EJMInteractionTraceMode_StaticEnum, TEXT("EJMInteractionTraceMode"), &Z_Registration_Info_UEnum_EJMInteractionTraceMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2566927994U) },
		{ EJMInteractionPromptHiddenMode_StaticEnum, TEXT("EJMInteractionPromptHiddenMode"), &Z_Registration_Info_UEnum_EJMInteractionPromptHiddenMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2694348291U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FJMInteractionPromptStyle::StaticStruct, Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics::NewStructOps, TEXT("JMInteractionPromptStyle"),&Z_Registration_Info_UScriptStruct_FJMInteractionPromptStyle, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMInteractionPromptStyle), 2420317743U) },
		{ FJMInteractionResult::StaticStruct, Z_Construct_UScriptStruct_FJMInteractionResult_Statics::NewStructOps, TEXT("JMInteractionResult"),&Z_Registration_Info_UScriptStruct_FJMInteractionResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMInteractionResult), 240276497U) },
		{ FJMInteractionContext::StaticStruct, Z_Construct_UScriptStruct_FJMInteractionContext_Statics::NewStructOps, TEXT("JMInteractionContext"),&Z_Registration_Info_UScriptStruct_FJMInteractionContext, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMInteractionContext), 3486038698U) },
		{ FJMInteractionPrompt::StaticStruct, Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics::NewStructOps, TEXT("JMInteractionPrompt"),&Z_Registration_Info_UScriptStruct_FJMInteractionPrompt, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMInteractionPrompt), 2592379790U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Types_JMInteractionTypes_h__Script_JMInteraction_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Types_JMInteractionTypes_h__Script_JMInteraction_3454721758{
	TEXT("/Script/JMInteraction"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Types_JMInteractionTypes_h__Script_JMInteraction_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Types_JMInteractionTypes_h__Script_JMInteraction_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Types_JMInteractionTypes_h__Script_JMInteraction_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Types_JMInteractionTypes_h__Script_JMInteraction_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
