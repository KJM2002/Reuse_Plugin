// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Data/JMJumpScareDefinition.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMJumpScareDefinition() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareDefinition();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareDefinition_NoRegister();
JMJUMPSCARE_API UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScareTriggerPolicy();
UPackage* Z_Construct_UPackage__Script_JMJumpScare();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMJumpScareDefinition Function IsDefinitionValid ************************
struct Z_Construct_UFunction_UJMJumpScareDefinition_IsDefinitionValid_Statics
{
	struct JMJumpScareDefinition_eventIsDefinitionValid_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Data/JMJumpScareDefinition.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsDefinitionValid constinit property declarations *********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsDefinitionValid constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsDefinitionValid Property Definitions ********************************
void Z_Construct_UFunction_UJMJumpScareDefinition_IsDefinitionValid_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMJumpScareDefinition_eventIsDefinitionValid_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMJumpScareDefinition_IsDefinitionValid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMJumpScareDefinition_eventIsDefinitionValid_Parms), &Z_Construct_UFunction_UJMJumpScareDefinition_IsDefinitionValid_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMJumpScareDefinition_IsDefinitionValid_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMJumpScareDefinition_IsDefinitionValid_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareDefinition_IsDefinitionValid_Statics::PropPointers) < 2048);
// ********** End Function IsDefinitionValid Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMJumpScareDefinition_IsDefinitionValid_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMJumpScareDefinition, nullptr, "IsDefinitionValid", 	Z_Construct_UFunction_UJMJumpScareDefinition_IsDefinitionValid_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareDefinition_IsDefinitionValid_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMJumpScareDefinition_IsDefinitionValid_Statics::JMJumpScareDefinition_eventIsDefinitionValid_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareDefinition_IsDefinitionValid_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMJumpScareDefinition_IsDefinitionValid_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMJumpScareDefinition_IsDefinitionValid_Statics::JMJumpScareDefinition_eventIsDefinitionValid_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMJumpScareDefinition_IsDefinitionValid()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMJumpScareDefinition_IsDefinitionValid_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMJumpScareDefinition::execIsDefinitionValid)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsDefinitionValid();
	P_NATIVE_END;
}
// ********** End Class UJMJumpScareDefinition Function IsDefinitionValid **************************

// ********** Begin Class UJMJumpScareDefinition ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMJumpScareDefinition;
UClass* UJMJumpScareDefinition::GetPrivateStaticClass()
{
	using TClass = UJMJumpScareDefinition;
	if (!Z_Registration_Info_UClass_UJMJumpScareDefinition.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMJumpScareDefinition"),
			Z_Registration_Info_UClass_UJMJumpScareDefinition.InnerSingleton,
			StaticRegisterNativesUJMJumpScareDefinition,
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
	return Z_Registration_Info_UClass_UJMJumpScareDefinition.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMJumpScareDefinition_NoRegister()
{
	return UJMJumpScareDefinition::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMJumpScareDefinition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * A deliberately small JumpScare definition.\n * The runtime presents Image as a full-screen 2D overlay on the target player's view.\n */" },
#endif
		{ "DisplayName", "JM JumpScare Definition" },
		{ "IncludePath", "Data/JMJumpScareDefinition.h" },
		{ "ModuleRelativePath", "Public/Data/JMJumpScareDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A deliberately small JumpScare definition.\nThe runtime presents Image as a full-screen 2D overlay on the target player's view." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpScareId_MetaData[] = {
		{ "Categories", "JumpScare" },
		{ "Category", "JumpScare" },
		{ "ModuleRelativePath", "Public/Data/JMJumpScareDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Image_MetaData[] = {
		{ "Category", "JumpScare" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Image placed over the target player's camera view. Alpha is supported. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/JMJumpScareDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Image placed over the target player's camera view. Alpha is supported." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ImageTint_MetaData[] = {
		{ "Category", "JumpScare" },
		{ "ModuleRelativePath", "Public/Data/JMJumpScareDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ImageResolution_MetaData[] = {
		{ "Category", "JumpScare" },
		{ "ClampMin", "1.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** On-screen size in viewport pixels. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/JMJumpScareDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "On-screen size in viewport pixels." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RiseDuration_MetaData[] = {
		{ "Category", "JumpScare" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Time for the image to rise from below the screen to the center. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/JMJumpScareDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Time for the image to rise from below the screen to the center." },
#endif
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ZOrder_MetaData[] = {
		{ "Category", "JumpScare" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Draw order on the player's screen. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/JMJumpScareDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Draw order on the player's screen." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartDelay_MetaData[] = {
		{ "Category", "JumpScare" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMJumpScareDefinition.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Duration_MetaData[] = {
		{ "Category", "JumpScare" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMJumpScareDefinition.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpScareSound_MetaData[] = {
		{ "Category", "JumpScare" },
		{ "ModuleRelativePath", "Public/Data/JMJumpScareDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SoundDelay_MetaData[] = {
		{ "Category", "JumpScare" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMJumpScareDefinition.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VolumeMultiplier_MetaData[] = {
		{ "Category", "JumpScare" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMJumpScareDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PitchMultiplier_MetaData[] = {
		{ "Category", "JumpScare" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Data/JMJumpScareDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GlitchMaterial_MetaData[] = {
		{ "Category", "JumpScare | Glitch" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Post-process material played after the image disappears. Defaults to /Game/Jumpscare/M_Glitch. */" },
#endif
		{ "ModuleRelativePath", "Public/Data/JMJumpScareDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Post-process material played after the image disappears. Defaults to /Game/Jumpscare/M_Glitch." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GlitchDuration_MetaData[] = {
		{ "Category", "JumpScare | Glitch" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMJumpScareDefinition.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GlitchSound_MetaData[] = {
		{ "Category", "JumpScare | Glitch" },
		{ "ModuleRelativePath", "Public/Data/JMJumpScareDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GlitchVolumeMultiplier_MetaData[] = {
		{ "Category", "JumpScare | Glitch" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Data/JMJumpScareDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GlitchPitchMultiplier_MetaData[] = {
		{ "Category", "JumpScare | Glitch" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Data/JMJumpScareDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TriggerPolicy_MetaData[] = {
		{ "Category", "JumpScare" },
		{ "ModuleRelativePath", "Public/Data/JMJumpScareDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnteringDuration_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Retained only for source compatibility with JMRecon integration.\n     * The 2D overlay appears immediately after StartDelay.\n     */" },
#endif
		{ "DeprecatedProperty", "" },
		{ "DeprecationMessage", "2D JumpScares no longer use an entering phase." },
		{ "ModuleRelativePath", "Public/Data/JMJumpScareDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Retained only for source compatibility with JMRecon integration.\nThe 2D overlay appears immediately after StartDelay." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UJMJumpScareDefinition constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JumpScareId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Image;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ImageTint;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ImageResolution;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RiseDuration;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ZOrder;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StartDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpScareSound;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SoundDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VolumeMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PitchMultiplier;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_GlitchMaterial;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GlitchDuration;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GlitchSound;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GlitchVolumeMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GlitchPitchMultiplier;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TriggerPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TriggerPolicy;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EnteringDuration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMJumpScareDefinition constinit property declarations *********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("IsDefinitionValid"), .Pointer = &UJMJumpScareDefinition::execIsDefinitionValid },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMJumpScareDefinition_IsDefinitionValid, "IsDefinitionValid" }, // 905730528
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMJumpScareDefinition>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMJumpScareDefinition_Statics

// ********** Begin Class UJMJumpScareDefinition Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_JumpScareId = { "JumpScareId", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareDefinition, JumpScareId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpScareId_MetaData), NewProp_JumpScareId_MetaData) }; // 517357616
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_Image = { "Image", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareDefinition, Image), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Image_MetaData), NewProp_Image_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_ImageTint = { "ImageTint", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareDefinition, ImageTint), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ImageTint_MetaData), NewProp_ImageTint_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_ImageResolution = { "ImageResolution", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareDefinition, ImageResolution), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ImageResolution_MetaData), NewProp_ImageResolution_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_RiseDuration = { "RiseDuration", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareDefinition, RiseDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RiseDuration_MetaData), NewProp_RiseDuration_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_ZOrder = { "ZOrder", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareDefinition, ZOrder), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ZOrder_MetaData), NewProp_ZOrder_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_StartDelay = { "StartDelay", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareDefinition, StartDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartDelay_MetaData), NewProp_StartDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareDefinition, Duration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Duration_MetaData), NewProp_Duration_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_JumpScareSound = { "JumpScareSound", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareDefinition, JumpScareSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpScareSound_MetaData), NewProp_JumpScareSound_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_SoundDelay = { "SoundDelay", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareDefinition, SoundDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SoundDelay_MetaData), NewProp_SoundDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_VolumeMultiplier = { "VolumeMultiplier", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareDefinition, VolumeMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VolumeMultiplier_MetaData), NewProp_VolumeMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_PitchMultiplier = { "PitchMultiplier", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareDefinition, PitchMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PitchMultiplier_MetaData), NewProp_PitchMultiplier_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_GlitchMaterial = { "GlitchMaterial", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareDefinition, GlitchMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GlitchMaterial_MetaData), NewProp_GlitchMaterial_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_GlitchDuration = { "GlitchDuration", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareDefinition, GlitchDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GlitchDuration_MetaData), NewProp_GlitchDuration_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_GlitchSound = { "GlitchSound", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareDefinition, GlitchSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GlitchSound_MetaData), NewProp_GlitchSound_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_GlitchVolumeMultiplier = { "GlitchVolumeMultiplier", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareDefinition, GlitchVolumeMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GlitchVolumeMultiplier_MetaData), NewProp_GlitchVolumeMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_GlitchPitchMultiplier = { "GlitchPitchMultiplier", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareDefinition, GlitchPitchMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GlitchPitchMultiplier_MetaData), NewProp_GlitchPitchMultiplier_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_TriggerPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_TriggerPolicy = { "TriggerPolicy", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareDefinition, TriggerPolicy), Z_Construct_UEnum_JMJumpScare_EJMJumpScareTriggerPolicy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TriggerPolicy_MetaData), NewProp_TriggerPolicy_MetaData) }; // 453019027
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_EnteringDuration = { "EnteringDuration", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareDefinition, EnteringDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnteringDuration_MetaData), NewProp_EnteringDuration_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMJumpScareDefinition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_JumpScareId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_Image,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_ImageTint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_ImageResolution,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_RiseDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_ZOrder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_StartDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_Duration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_JumpScareSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_SoundDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_VolumeMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_PitchMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_GlitchMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_GlitchDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_GlitchSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_GlitchVolumeMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_GlitchPitchMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_TriggerPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_TriggerPolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareDefinition_Statics::NewProp_EnteringDuration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareDefinition_Statics::PropPointers) < 2048);
// ********** End Class UJMJumpScareDefinition Property Definitions ********************************
UObject* (*const Z_Construct_UClass_UJMJumpScareDefinition_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_JMJumpScare,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareDefinition_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMJumpScareDefinition_Statics::ClassParams = {
	&UJMJumpScareDefinition::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMJumpScareDefinition_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareDefinition_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareDefinition_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMJumpScareDefinition_Statics::Class_MetaDataParams)
};
void UJMJumpScareDefinition::StaticRegisterNativesUJMJumpScareDefinition()
{
	UClass* Class = UJMJumpScareDefinition::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMJumpScareDefinition_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMJumpScareDefinition()
{
	if (!Z_Registration_Info_UClass_UJMJumpScareDefinition.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMJumpScareDefinition.OuterSingleton, Z_Construct_UClass_UJMJumpScareDefinition_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMJumpScareDefinition.OuterSingleton;
}
UJMJumpScareDefinition::UJMJumpScareDefinition(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMJumpScareDefinition);
UJMJumpScareDefinition::~UJMJumpScareDefinition() {}
// ********** End Class UJMJumpScareDefinition *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Data_JMJumpScareDefinition_h__Script_JMJumpScare_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMJumpScareDefinition, UJMJumpScareDefinition::StaticClass, TEXT("UJMJumpScareDefinition"), &Z_Registration_Info_UClass_UJMJumpScareDefinition, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMJumpScareDefinition), 1118881152U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Data_JMJumpScareDefinition_h__Script_JMJumpScare_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Data_JMJumpScareDefinition_h__Script_JMJumpScare_1561909021{
	TEXT("/Script/JMJumpScare"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Data_JMJumpScareDefinition_h__Script_JMJumpScare_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Data_JMJumpScareDefinition_h__Script_JMJumpScare_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
