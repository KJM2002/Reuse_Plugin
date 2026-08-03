// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueAssets.h"
#include "GameplayTagContainer.h"
#include "ReusableDialogueTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDialogueAssets() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USoundConcurrency_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueSequence();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueSequence_NoRegister();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueSpeakerProfile();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueSpeakerProfile_NoRegister();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueTextSoundSet();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueTextSoundSet_NoRegister();
REUSABLEDIALOGUESYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueLine();
UPackage* Z_Construct_UPackage__Script_ReusableDialogueSystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDialogueTextSoundSet ****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueTextSoundSet;
UClass* UDialogueTextSoundSet::GetPrivateStaticClass()
{
	using TClass = UDialogueTextSoundSet;
	if (!Z_Registration_Info_UClass_UDialogueTextSoundSet.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DialogueTextSoundSet"),
			Z_Registration_Info_UClass_UDialogueTextSoundSet.InnerSingleton,
			StaticRegisterNativesUDialogueTextSoundSet,
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
	return Z_Registration_Info_UClass_UDialogueTextSoundSet.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueTextSoundSet_NoRegister()
{
	return UDialogueTextSoundSet::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueTextSoundSet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "DialogueAssets.h" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Sounds_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VolumeMin_MetaData[] = {
		{ "Category", "Audio" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VolumeMax_MetaData[] = {
		{ "Category", "Audio" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PitchMin_MetaData[] = {
		{ "Category", "Audio" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PitchMax_MetaData[] = {
		{ "Category", "Audio" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumPlaybackInterval_MetaData[] = {
		{ "Category", "Audio" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SoundEveryNCharacters_MetaData[] = {
		{ "Category", "Audio" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSkipWhitespace_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSkipPunctuation_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bStopPreviousSound_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDisableWhileVoiceIsPlaying_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SoundConcurrency_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LineCompleteSound_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDialogueTextSoundSet constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Sounds_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Sounds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VolumeMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VolumeMax;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PitchMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PitchMax;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinimumPlaybackInterval;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SoundEveryNCharacters;
	static void NewProp_bSkipWhitespace_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSkipWhitespace;
	static void NewProp_bSkipPunctuation_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSkipPunctuation;
	static void NewProp_bStopPreviousSound_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStopPreviousSound;
	static void NewProp_bDisableWhileVoiceIsPlaying_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDisableWhileVoiceIsPlaying;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SoundConcurrency;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LineCompleteSound;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDialogueTextSoundSet constinit property declarations **********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueTextSoundSet>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDialogueTextSoundSet_Statics

// ********** Begin Class UDialogueTextSoundSet Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_Sounds_Inner = { "Sounds", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_Sounds = { "Sounds", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueTextSoundSet, Sounds), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Sounds_MetaData), NewProp_Sounds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_VolumeMin = { "VolumeMin", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueTextSoundSet, VolumeMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VolumeMin_MetaData), NewProp_VolumeMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_VolumeMax = { "VolumeMax", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueTextSoundSet, VolumeMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VolumeMax_MetaData), NewProp_VolumeMax_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_PitchMin = { "PitchMin", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueTextSoundSet, PitchMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PitchMin_MetaData), NewProp_PitchMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_PitchMax = { "PitchMax", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueTextSoundSet, PitchMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PitchMax_MetaData), NewProp_PitchMax_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_MinimumPlaybackInterval = { "MinimumPlaybackInterval", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueTextSoundSet, MinimumPlaybackInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumPlaybackInterval_MetaData), NewProp_MinimumPlaybackInterval_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_SoundEveryNCharacters = { "SoundEveryNCharacters", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueTextSoundSet, SoundEveryNCharacters), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SoundEveryNCharacters_MetaData), NewProp_SoundEveryNCharacters_MetaData) };
void Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_bSkipWhitespace_SetBit(void* Obj)
{
	((UDialogueTextSoundSet*)Obj)->bSkipWhitespace = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_bSkipWhitespace = { "bSkipWhitespace", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDialogueTextSoundSet), &Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_bSkipWhitespace_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSkipWhitespace_MetaData), NewProp_bSkipWhitespace_MetaData) };
void Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_bSkipPunctuation_SetBit(void* Obj)
{
	((UDialogueTextSoundSet*)Obj)->bSkipPunctuation = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_bSkipPunctuation = { "bSkipPunctuation", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDialogueTextSoundSet), &Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_bSkipPunctuation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSkipPunctuation_MetaData), NewProp_bSkipPunctuation_MetaData) };
void Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_bStopPreviousSound_SetBit(void* Obj)
{
	((UDialogueTextSoundSet*)Obj)->bStopPreviousSound = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_bStopPreviousSound = { "bStopPreviousSound", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDialogueTextSoundSet), &Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_bStopPreviousSound_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bStopPreviousSound_MetaData), NewProp_bStopPreviousSound_MetaData) };
void Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_bDisableWhileVoiceIsPlaying_SetBit(void* Obj)
{
	((UDialogueTextSoundSet*)Obj)->bDisableWhileVoiceIsPlaying = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_bDisableWhileVoiceIsPlaying = { "bDisableWhileVoiceIsPlaying", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDialogueTextSoundSet), &Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_bDisableWhileVoiceIsPlaying_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDisableWhileVoiceIsPlaying_MetaData), NewProp_bDisableWhileVoiceIsPlaying_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_SoundConcurrency = { "SoundConcurrency", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueTextSoundSet, SoundConcurrency), Z_Construct_UClass_USoundConcurrency_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SoundConcurrency_MetaData), NewProp_SoundConcurrency_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_LineCompleteSound = { "LineCompleteSound", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueTextSoundSet, LineCompleteSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LineCompleteSound_MetaData), NewProp_LineCompleteSound_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueTextSoundSet_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_Sounds_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_Sounds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_VolumeMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_VolumeMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_PitchMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_PitchMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_MinimumPlaybackInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_SoundEveryNCharacters,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_bSkipWhitespace,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_bSkipPunctuation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_bStopPreviousSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_bDisableWhileVoiceIsPlaying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_SoundConcurrency,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueTextSoundSet_Statics::NewProp_LineCompleteSound,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueTextSoundSet_Statics::PropPointers) < 2048);
// ********** End Class UDialogueTextSoundSet Property Definitions *********************************
UObject* (*const Z_Construct_UClass_UDialogueTextSoundSet_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_ReusableDialogueSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueTextSoundSet_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueTextSoundSet_Statics::ClassParams = {
	&UDialogueTextSoundSet::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDialogueTextSoundSet_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueTextSoundSet_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueTextSoundSet_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueTextSoundSet_Statics::Class_MetaDataParams)
};
void UDialogueTextSoundSet::StaticRegisterNativesUDialogueTextSoundSet()
{
}
UClass* Z_Construct_UClass_UDialogueTextSoundSet()
{
	if (!Z_Registration_Info_UClass_UDialogueTextSoundSet.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueTextSoundSet.OuterSingleton, Z_Construct_UClass_UDialogueTextSoundSet_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueTextSoundSet.OuterSingleton;
}
UDialogueTextSoundSet::UDialogueTextSoundSet(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDialogueTextSoundSet);
UDialogueTextSoundSet::~UDialogueTextSoundSet() {}
// ********** End Class UDialogueTextSoundSet ******************************************************

// ********** Begin Class UDialogueSpeakerProfile **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueSpeakerProfile;
UClass* UDialogueSpeakerProfile::GetPrivateStaticClass()
{
	using TClass = UDialogueSpeakerProfile;
	if (!Z_Registration_Info_UClass_UDialogueSpeakerProfile.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DialogueSpeakerProfile"),
			Z_Registration_Info_UClass_UDialogueSpeakerProfile.InnerSingleton,
			StaticRegisterNativesUDialogueSpeakerProfile,
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
	return Z_Registration_Info_UClass_UDialogueSpeakerProfile.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueSpeakerProfile_NoRegister()
{
	return UDialogueSpeakerProfile::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueSpeakerProfile_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "DialogueAssets.h" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeakerId_MetaData[] = {
		{ "Category", "Speaker" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[] = {
		{ "Category", "Speaker" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NameColor_MetaData[] = {
		{ "Category", "Speaker" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Portrait_MetaData[] = {
		{ "Category", "Speaker" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultVoiceSound_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextSoundSet_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableTextSound_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDialogueSpeakerProfile constinit property declarations ******************
	static const UECodeGen_Private::FNamePropertyParams NewProp_SpeakerId;
	static const UECodeGen_Private::FTextPropertyParams NewProp_DisplayName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NameColor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Portrait;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultVoiceSound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TextSoundSet;
	static void NewProp_bEnableTextSound_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableTextSound;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDialogueSpeakerProfile constinit property declarations ********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueSpeakerProfile>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDialogueSpeakerProfile_Statics

// ********** Begin Class UDialogueSpeakerProfile Property Definitions *****************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDialogueSpeakerProfile_Statics::NewProp_SpeakerId = { "SpeakerId", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSpeakerProfile, SpeakerId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeakerId_MetaData), NewProp_SpeakerId_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UDialogueSpeakerProfile_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSpeakerProfile, DisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayName_MetaData), NewProp_DisplayName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDialogueSpeakerProfile_Statics::NewProp_NameColor = { "NameColor", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSpeakerProfile, NameColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NameColor_MetaData), NewProp_NameColor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueSpeakerProfile_Statics::NewProp_Portrait = { "Portrait", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSpeakerProfile, Portrait), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Portrait_MetaData), NewProp_Portrait_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueSpeakerProfile_Statics::NewProp_DefaultVoiceSound = { "DefaultVoiceSound", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSpeakerProfile, DefaultVoiceSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultVoiceSound_MetaData), NewProp_DefaultVoiceSound_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueSpeakerProfile_Statics::NewProp_TextSoundSet = { "TextSoundSet", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSpeakerProfile, TextSoundSet), Z_Construct_UClass_UDialogueTextSoundSet_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextSoundSet_MetaData), NewProp_TextSoundSet_MetaData) };
void Z_Construct_UClass_UDialogueSpeakerProfile_Statics::NewProp_bEnableTextSound_SetBit(void* Obj)
{
	((UDialogueSpeakerProfile*)Obj)->bEnableTextSound = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDialogueSpeakerProfile_Statics::NewProp_bEnableTextSound = { "bEnableTextSound", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDialogueSpeakerProfile), &Z_Construct_UClass_UDialogueSpeakerProfile_Statics::NewProp_bEnableTextSound_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableTextSound_MetaData), NewProp_bEnableTextSound_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueSpeakerProfile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSpeakerProfile_Statics::NewProp_SpeakerId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSpeakerProfile_Statics::NewProp_DisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSpeakerProfile_Statics::NewProp_NameColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSpeakerProfile_Statics::NewProp_Portrait,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSpeakerProfile_Statics::NewProp_DefaultVoiceSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSpeakerProfile_Statics::NewProp_TextSoundSet,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSpeakerProfile_Statics::NewProp_bEnableTextSound,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueSpeakerProfile_Statics::PropPointers) < 2048);
// ********** End Class UDialogueSpeakerProfile Property Definitions *******************************
UObject* (*const Z_Construct_UClass_UDialogueSpeakerProfile_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_ReusableDialogueSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueSpeakerProfile_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueSpeakerProfile_Statics::ClassParams = {
	&UDialogueSpeakerProfile::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDialogueSpeakerProfile_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueSpeakerProfile_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueSpeakerProfile_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueSpeakerProfile_Statics::Class_MetaDataParams)
};
void UDialogueSpeakerProfile::StaticRegisterNativesUDialogueSpeakerProfile()
{
}
UClass* Z_Construct_UClass_UDialogueSpeakerProfile()
{
	if (!Z_Registration_Info_UClass_UDialogueSpeakerProfile.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueSpeakerProfile.OuterSingleton, Z_Construct_UClass_UDialogueSpeakerProfile_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueSpeakerProfile.OuterSingleton;
}
UDialogueSpeakerProfile::UDialogueSpeakerProfile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDialogueSpeakerProfile);
UDialogueSpeakerProfile::~UDialogueSpeakerProfile() {}
// ********** End Class UDialogueSpeakerProfile ****************************************************

// ********** Begin Class UDialogueSequence ********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueSequence;
UClass* UDialogueSequence::GetPrivateStaticClass()
{
	using TClass = UDialogueSequence;
	if (!Z_Registration_Info_UClass_UDialogueSequence.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DialogueSequence"),
			Z_Registration_Info_UClass_UDialogueSequence.InnerSingleton,
			StaticRegisterNativesUDialogueSequence,
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
	return Z_Registration_Info_UClass_UDialogueSequence.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueSequence_NoRegister()
{
	return UDialogueSequence::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueSequence_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "DialogueAssets.h" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SequenceId_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Lines_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SequenceTag_MetaData[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueAssets.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDialogueSequence constinit property declarations ************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_SequenceId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Lines_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Lines;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SequenceTag;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDialogueSequence constinit property declarations **************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueSequence>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDialogueSequence_Statics

// ********** Begin Class UDialogueSequence Property Definitions ***********************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDialogueSequence_Statics::NewProp_SequenceId = { "SequenceId", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSequence, SequenceId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SequenceId_MetaData), NewProp_SequenceId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDialogueSequence_Statics::NewProp_Lines_Inner = { "Lines", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDialogueLine, METADATA_PARAMS(0, nullptr) }; // 3166424386
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDialogueSequence_Statics::NewProp_Lines = { "Lines", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSequence, Lines), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Lines_MetaData), NewProp_Lines_MetaData) }; // 3166424386
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDialogueSequence_Statics::NewProp_SequenceTag = { "SequenceTag", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSequence, SequenceTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SequenceTag_MetaData), NewProp_SequenceTag_MetaData) }; // 517357616
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueSequence_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSequence_Statics::NewProp_SequenceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSequence_Statics::NewProp_Lines_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSequence_Statics::NewProp_Lines,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSequence_Statics::NewProp_SequenceTag,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueSequence_Statics::PropPointers) < 2048);
// ********** End Class UDialogueSequence Property Definitions *************************************
UObject* (*const Z_Construct_UClass_UDialogueSequence_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_ReusableDialogueSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueSequence_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueSequence_Statics::ClassParams = {
	&UDialogueSequence::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDialogueSequence_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueSequence_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueSequence_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueSequence_Statics::Class_MetaDataParams)
};
void UDialogueSequence::StaticRegisterNativesUDialogueSequence()
{
}
UClass* Z_Construct_UClass_UDialogueSequence()
{
	if (!Z_Registration_Info_UClass_UDialogueSequence.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueSequence.OuterSingleton, Z_Construct_UClass_UDialogueSequence_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueSequence.OuterSingleton;
}
UDialogueSequence::UDialogueSequence(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDialogueSequence);
UDialogueSequence::~UDialogueSequence() {}
// ********** End Class UDialogueSequence **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueAssets_h__Script_ReusableDialogueSystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueTextSoundSet, UDialogueTextSoundSet::StaticClass, TEXT("UDialogueTextSoundSet"), &Z_Registration_Info_UClass_UDialogueTextSoundSet, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueTextSoundSet), 3333510314U) },
		{ Z_Construct_UClass_UDialogueSpeakerProfile, UDialogueSpeakerProfile::StaticClass, TEXT("UDialogueSpeakerProfile"), &Z_Registration_Info_UClass_UDialogueSpeakerProfile, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueSpeakerProfile), 2000827339U) },
		{ Z_Construct_UClass_UDialogueSequence, UDialogueSequence::StaticClass, TEXT("UDialogueSequence"), &Z_Registration_Info_UClass_UDialogueSequence, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueSequence), 2485798507U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueAssets_h__Script_ReusableDialogueSystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueAssets_h__Script_ReusableDialogueSystem_76013625{
	TEXT("/Script/ReusableDialogueSystem"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueAssets_h__Script_ReusableDialogueSystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueAssets_h__Script_ReusableDialogueSystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
