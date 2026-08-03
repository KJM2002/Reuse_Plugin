// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDialogueSettings() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueSettings();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueSettings_NoRegister();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueTextSoundSet_NoRegister();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueWidgetBase_NoRegister();
REUSABLEDIALOGUESYSTEM_API UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EDialogueInteractionMode();
REUSABLEDIALOGUESYSTEM_API UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EDialogueRevealMode();
REUSABLEDIALOGUESYSTEM_API UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EExistingDialoguePolicy();
UPackage* Z_Construct_UPackage__Script_ReusableDialogueSystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDialogueSettings ********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueSettings;
UClass* UDialogueSettings::GetPrivateStaticClass()
{
	using TClass = UDialogueSettings;
	if (!Z_Registration_Info_UClass_UDialogueSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DialogueSettings"),
			Z_Registration_Info_UClass_UDialogueSettings.InnerSingleton,
			StaticRegisterNativesUDialogueSettings,
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
	return Z_Registration_Info_UClass_UDialogueSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueSettings_NoRegister()
{
	return UDialogueSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "Dialogue" },
		{ "IncludePath", "DialogueSettings.h" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Configure the reusable JM dialogue system." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultDialogueWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultRevealMode_MetaData[] = {
		{ "Category", "Reveal" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bForceCharacterReveal_MetaData[] = {
		{ "Category", "Reveal" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Keeps previously-authored Word lines on character reveal. Instant lines remain instant. */" },
#endif
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Keeps previously-authored Word lines on character reveal. Instant lines remain instant." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultWordInterval_MetaData[] = {
		{ "Category", "Reveal" },
		{ "ClampMin", "0.001" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultCharacterInterval_MetaData[] = {
		{ "Category", "Reveal" },
		{ "ClampMin", "0.001" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSmoothCharacterReveal_MetaData[] = {
		{ "Category", "Reveal|Smoothing" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterRevealBlendDuration_MetaData[] = {
		{ "Category", "Reveal|Smoothing" },
		{ "ClampMax", "0.25" },
		{ "ClampMin", "0.001" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterRevealStartOpacity_MetaData[] = {
		{ "Category", "Reveal|Smoothing" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CommaDelay_MetaData[] = {
		{ "Category", "Reveal" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SentenceEndDelay_MetaData[] = {
		{ "Category", "Reveal" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EllipsisDelay_MetaData[] = {
		{ "Category", "Reveal" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewLineDelay_MetaData[] = {
		{ "Category", "Reveal" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultInteractionMode_MetaData[] = {
		{ "Category", "Flow" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultExistingDialoguePolicy_MetaData[] = {
		{ "Category", "Flow" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowMouseAdvance_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowKeyboardAdvance_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowGamepadAdvance_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputDebounceTime_MetaData[] = {
		{ "Category", "Input" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultTextSoundSet_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultTextSoundVolume_MetaData[] = {
		{ "Category", "Audio" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultTextSoundPitchMin_MetaData[] = {
		{ "Category", "Audio" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultTextSoundPitchMax_MetaData[] = {
		{ "Category", "Audio" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMinimumTextSoundInterval_MetaData[] = {
		{ "Category", "Audio" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultSoundEveryNCharacters_MetaData[] = {
		{ "Category", "Audio" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultTextScale_MetaData[] = {
		{ "Category", "UI" },
		{ "ClampMin", "0.1" },
		{ "ModuleRelativePath", "Public/DialogueSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDialogueSettings constinit property declarations ************************
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_DefaultDialogueWidgetClass;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DefaultRevealMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DefaultRevealMode;
	static void NewProp_bForceCharacterReveal_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bForceCharacterReveal;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultWordInterval;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultCharacterInterval;
	static void NewProp_bSmoothCharacterReveal_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSmoothCharacterReveal;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CharacterRevealBlendDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CharacterRevealStartOpacity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CommaDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SentenceEndDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EllipsisDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NewLineDelay;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DefaultInteractionMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DefaultInteractionMode;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DefaultExistingDialoguePolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DefaultExistingDialoguePolicy;
	static void NewProp_bAllowMouseAdvance_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowMouseAdvance;
	static void NewProp_bAllowKeyboardAdvance_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowKeyboardAdvance;
	static void NewProp_bAllowGamepadAdvance_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowGamepadAdvance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InputDebounceTime;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_DefaultTextSoundSet;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultTextSoundVolume;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultTextSoundPitchMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultTextSoundPitchMax;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultMinimumTextSoundInterval;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DefaultSoundEveryNCharacters;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultTextScale;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDialogueSettings constinit property declarations **************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDialogueSettings_Statics

// ********** Begin Class UDialogueSettings Property Definitions ***********************************
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultDialogueWidgetClass = { "DefaultDialogueWidgetClass", nullptr, (EPropertyFlags)0x0014000000004001, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSettings, DefaultDialogueWidgetClass), Z_Construct_UClass_UDialogueWidgetBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultDialogueWidgetClass_MetaData), NewProp_DefaultDialogueWidgetClass_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultRevealMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultRevealMode = { "DefaultRevealMode", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSettings, DefaultRevealMode), Z_Construct_UEnum_ReusableDialogueSystem_EDialogueRevealMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultRevealMode_MetaData), NewProp_DefaultRevealMode_MetaData) }; // 3637322456
void Z_Construct_UClass_UDialogueSettings_Statics::NewProp_bForceCharacterReveal_SetBit(void* Obj)
{
	((UDialogueSettings*)Obj)->bForceCharacterReveal = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_bForceCharacterReveal = { "bForceCharacterReveal", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDialogueSettings), &Z_Construct_UClass_UDialogueSettings_Statics::NewProp_bForceCharacterReveal_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bForceCharacterReveal_MetaData), NewProp_bForceCharacterReveal_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultWordInterval = { "DefaultWordInterval", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSettings, DefaultWordInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultWordInterval_MetaData), NewProp_DefaultWordInterval_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultCharacterInterval = { "DefaultCharacterInterval", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSettings, DefaultCharacterInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultCharacterInterval_MetaData), NewProp_DefaultCharacterInterval_MetaData) };
void Z_Construct_UClass_UDialogueSettings_Statics::NewProp_bSmoothCharacterReveal_SetBit(void* Obj)
{
	((UDialogueSettings*)Obj)->bSmoothCharacterReveal = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_bSmoothCharacterReveal = { "bSmoothCharacterReveal", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDialogueSettings), &Z_Construct_UClass_UDialogueSettings_Statics::NewProp_bSmoothCharacterReveal_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSmoothCharacterReveal_MetaData), NewProp_bSmoothCharacterReveal_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_CharacterRevealBlendDuration = { "CharacterRevealBlendDuration", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSettings, CharacterRevealBlendDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterRevealBlendDuration_MetaData), NewProp_CharacterRevealBlendDuration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_CharacterRevealStartOpacity = { "CharacterRevealStartOpacity", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSettings, CharacterRevealStartOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterRevealStartOpacity_MetaData), NewProp_CharacterRevealStartOpacity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_CommaDelay = { "CommaDelay", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSettings, CommaDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CommaDelay_MetaData), NewProp_CommaDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_SentenceEndDelay = { "SentenceEndDelay", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSettings, SentenceEndDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SentenceEndDelay_MetaData), NewProp_SentenceEndDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_EllipsisDelay = { "EllipsisDelay", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSettings, EllipsisDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EllipsisDelay_MetaData), NewProp_EllipsisDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_NewLineDelay = { "NewLineDelay", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSettings, NewLineDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewLineDelay_MetaData), NewProp_NewLineDelay_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultInteractionMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultInteractionMode = { "DefaultInteractionMode", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSettings, DefaultInteractionMode), Z_Construct_UEnum_ReusableDialogueSystem_EDialogueInteractionMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultInteractionMode_MetaData), NewProp_DefaultInteractionMode_MetaData) }; // 3853692148
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultExistingDialoguePolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultExistingDialoguePolicy = { "DefaultExistingDialoguePolicy", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSettings, DefaultExistingDialoguePolicy), Z_Construct_UEnum_ReusableDialogueSystem_EExistingDialoguePolicy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultExistingDialoguePolicy_MetaData), NewProp_DefaultExistingDialoguePolicy_MetaData) }; // 3634757249
void Z_Construct_UClass_UDialogueSettings_Statics::NewProp_bAllowMouseAdvance_SetBit(void* Obj)
{
	((UDialogueSettings*)Obj)->bAllowMouseAdvance = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_bAllowMouseAdvance = { "bAllowMouseAdvance", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDialogueSettings), &Z_Construct_UClass_UDialogueSettings_Statics::NewProp_bAllowMouseAdvance_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowMouseAdvance_MetaData), NewProp_bAllowMouseAdvance_MetaData) };
void Z_Construct_UClass_UDialogueSettings_Statics::NewProp_bAllowKeyboardAdvance_SetBit(void* Obj)
{
	((UDialogueSettings*)Obj)->bAllowKeyboardAdvance = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_bAllowKeyboardAdvance = { "bAllowKeyboardAdvance", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDialogueSettings), &Z_Construct_UClass_UDialogueSettings_Statics::NewProp_bAllowKeyboardAdvance_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowKeyboardAdvance_MetaData), NewProp_bAllowKeyboardAdvance_MetaData) };
void Z_Construct_UClass_UDialogueSettings_Statics::NewProp_bAllowGamepadAdvance_SetBit(void* Obj)
{
	((UDialogueSettings*)Obj)->bAllowGamepadAdvance = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_bAllowGamepadAdvance = { "bAllowGamepadAdvance", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDialogueSettings), &Z_Construct_UClass_UDialogueSettings_Statics::NewProp_bAllowGamepadAdvance_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowGamepadAdvance_MetaData), NewProp_bAllowGamepadAdvance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_InputDebounceTime = { "InputDebounceTime", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSettings, InputDebounceTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputDebounceTime_MetaData), NewProp_InputDebounceTime_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultTextSoundSet = { "DefaultTextSoundSet", nullptr, (EPropertyFlags)0x0014000000004001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSettings, DefaultTextSoundSet), Z_Construct_UClass_UDialogueTextSoundSet_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultTextSoundSet_MetaData), NewProp_DefaultTextSoundSet_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultTextSoundVolume = { "DefaultTextSoundVolume", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSettings, DefaultTextSoundVolume), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultTextSoundVolume_MetaData), NewProp_DefaultTextSoundVolume_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultTextSoundPitchMin = { "DefaultTextSoundPitchMin", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSettings, DefaultTextSoundPitchMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultTextSoundPitchMin_MetaData), NewProp_DefaultTextSoundPitchMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultTextSoundPitchMax = { "DefaultTextSoundPitchMax", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSettings, DefaultTextSoundPitchMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultTextSoundPitchMax_MetaData), NewProp_DefaultTextSoundPitchMax_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultMinimumTextSoundInterval = { "DefaultMinimumTextSoundInterval", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSettings, DefaultMinimumTextSoundInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultMinimumTextSoundInterval_MetaData), NewProp_DefaultMinimumTextSoundInterval_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultSoundEveryNCharacters = { "DefaultSoundEveryNCharacters", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSettings, DefaultSoundEveryNCharacters), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultSoundEveryNCharacters_MetaData), NewProp_DefaultSoundEveryNCharacters_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultTextScale = { "DefaultTextScale", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSettings, DefaultTextScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultTextScale_MetaData), NewProp_DefaultTextScale_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultDialogueWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultRevealMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultRevealMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_bForceCharacterReveal,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultWordInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultCharacterInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_bSmoothCharacterReveal,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_CharacterRevealBlendDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_CharacterRevealStartOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_CommaDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_SentenceEndDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_EllipsisDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_NewLineDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultInteractionMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultInteractionMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultExistingDialoguePolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultExistingDialoguePolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_bAllowMouseAdvance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_bAllowKeyboardAdvance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_bAllowGamepadAdvance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_InputDebounceTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultTextSoundSet,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultTextSoundVolume,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultTextSoundPitchMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultTextSoundPitchMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultMinimumTextSoundInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultSoundEveryNCharacters,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSettings_Statics::NewProp_DefaultTextScale,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueSettings_Statics::PropPointers) < 2048);
// ********** End Class UDialogueSettings Property Definitions *************************************
UObject* (*const Z_Construct_UClass_UDialogueSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_ReusableDialogueSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueSettings_Statics::ClassParams = {
	&UDialogueSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDialogueSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueSettings_Statics::Class_MetaDataParams)
};
void UDialogueSettings::StaticRegisterNativesUDialogueSettings()
{
}
UClass* Z_Construct_UClass_UDialogueSettings()
{
	if (!Z_Registration_Info_UClass_UDialogueSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueSettings.OuterSingleton, Z_Construct_UClass_UDialogueSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueSettings.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDialogueSettings);
UDialogueSettings::~UDialogueSettings() {}
// ********** End Class UDialogueSettings **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSettings_h__Script_ReusableDialogueSystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueSettings, UDialogueSettings::StaticClass, TEXT("UDialogueSettings"), &Z_Registration_Info_UClass_UDialogueSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueSettings), 220706400U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSettings_h__Script_ReusableDialogueSystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSettings_h__Script_ReusableDialogueSystem_2760883301{
	TEXT("/Script/ReusableDialogueSystem"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSettings_h__Script_ReusableDialogueSystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSettings_h__Script_ReusableDialogueSystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
