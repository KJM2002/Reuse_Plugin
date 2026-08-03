// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Settings/JMReconGameplayIntegrationSettings.h"
#include "InputCoreTypes.h"
#include "Types/JMInteractionTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMReconGameplayIntegrationSettings() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionPromptStyle();
JMRECONGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMReconGameplayIntegrationSettings();
JMRECONGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMReconGameplayIntegrationSettings_NoRegister();
JMRECONGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMReconPromptWidgetBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMReconGameplayIntegration();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMReconGameplayIntegrationSettings **************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMReconGameplayIntegrationSettings;
UClass* UJMReconGameplayIntegrationSettings::GetPrivateStaticClass()
{
	using TClass = UJMReconGameplayIntegrationSettings;
	if (!Z_Registration_Info_UClass_UJMReconGameplayIntegrationSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMReconGameplayIntegrationSettings"),
			Z_Registration_Info_UClass_UJMReconGameplayIntegrationSettings.InnerSingleton,
			StaticRegisterNativesUJMReconGameplayIntegrationSettings,
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
	return Z_Registration_Info_UClass_UJMReconGameplayIntegrationSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMReconGameplayIntegrationSettings_NoRegister()
{
	return UJMReconGameplayIntegrationSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "JM Recon Gameplay Integration" },
		{ "IncludePath", "Settings/JMReconGameplayIntegrationSettings.h" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoAddPlayerBridge_MetaData[] = {
		{ "Category", "Automatic Setup" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoBindInput_MetaData[] = {
		{ "Category", "Automatic Setup" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoManageCamera_MetaData[] = {
		{ "Category", "Automatic Setup" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoManageIlluminate_MetaData[] = {
		{ "Category", "Automatic Setup" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAlignPlayerToTarget_MetaData[] = {
		{ "Category", "Automatic Setup" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLockMovementDuringRecon_MetaData[] = {
		{ "Category", "Automatic Setup" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartOrFinishKey_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionDisplayKey_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Display-only key used beside the existing host interaction prompt. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Display-only key used beside the existing host interaction prompt." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PeekKey_MetaData[] = {
		{ "Category", "Input" },
		{ "DeprecatedProperty", "" },
		{ "DeprecationMessage", "Peek is entered automatically." },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IlluminateKey_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CancelKey_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExitKey_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RestoreBlendTime_MetaData[] = {
		{ "Category", "Camera" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraLookInterpSpeed_MetaData[] = {
		{ "Category", "Camera" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReconFieldOfView_MetaData[] = {
		{ "Category", "Camera" },
		{ "ClampMax", "170.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
		{ "Units", "deg" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bValidateCameraPlacement_MetaData[] = {
		{ "Category", "Camera|Validation" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraCollisionRadius_MetaData[] = {
		{ "Category", "Camera|Validation" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IlluminateIntensity_MetaData[] = {
		{ "Category", "Illuminate" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IlluminateAttenuationRadius_MetaData[] = {
		{ "Category", "Illuminate" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IlluminateOuterConeAngle_MetaData[] = {
		{ "Category", "Illuminate" },
		{ "ClampMax", "89.0" },
		{ "ClampMin", "1.0" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
		{ "Units", "deg" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IlluminateInnerConeAngle_MetaData[] = {
		{ "Category", "Illuminate" },
		{ "ClampMax", "89.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
		{ "Units", "deg" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IlluminateColor_MetaData[] = {
		{ "Category", "Illuminate" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IlluminateFadeDuration_MetaData[] = {
		{ "Category", "Illuminate" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlashlightOnSound_MetaData[] = {
		{ "Category", "Illuminate" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlashlightOffSound_MetaData[] = {
		{ "Category", "Illuminate" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCreateReconPromptWidget_MetaData[] = {
		{ "Category", "Prompt UI" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReconPromptWidgetClass_MetaData[] = {
		{ "Category", "Prompt UI" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReconPromptStyle_MetaData[] = {
		{ "Category", "Prompt UI" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FocusedTargetPromptFormat_MetaData[] = {
		{ "Category", "Prompt Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Supports {0}=interaction key and {1}=recon/start key. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Supports {0}=interaction key and {1}=recon/start key." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnteringPrompt_MetaData[] = {
		{ "Category", "Prompt Text" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlashlightActivePromptFormat_MetaData[] = {
		{ "Category", "Prompt Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Supports {0}=flashlight key and {1}=recon/start key. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Supports {0}=flashlight key and {1}=recon/start key." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObservingPromptFormat_MetaData[] = {
		{ "Category", "Prompt Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Supports {0}=flashlight key and {1}=recon/start key. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Supports {0}=flashlight key and {1}=recon/start key." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DoorMovingFailurePrompt_MetaData[] = {
		{ "Category", "Prompt Text|Failure" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DoorOpenFailurePrompt_MetaData[] = {
		{ "Category", "Prompt Text|Failure" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlockedFailurePrompt_MetaData[] = {
		{ "Category", "Prompt Text|Failure" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutOfRangeFailurePrompt_MetaData[] = {
		{ "Category", "Prompt Text|Failure" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GenericFailurePrompt_MetaData[] = {
		{ "Category", "Prompt Text|Failure" },
		{ "ModuleRelativePath", "Public/Settings/JMReconGameplayIntegrationSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMReconGameplayIntegrationSettings constinit property declarations ******
	static void NewProp_bAutoAddPlayerBridge_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoAddPlayerBridge;
	static void NewProp_bAutoBindInput_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoBindInput;
	static void NewProp_bAutoManageCamera_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoManageCamera;
	static void NewProp_bAutoManageIlluminate_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoManageIlluminate;
	static void NewProp_bAlignPlayerToTarget_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAlignPlayerToTarget;
	static void NewProp_bLockMovementDuringRecon_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLockMovementDuringRecon;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StartOrFinishKey;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InteractionDisplayKey;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PeekKey;
	static const UECodeGen_Private::FStructPropertyParams NewProp_IlluminateKey;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CancelKey;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ExitKey;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RestoreBlendTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraLookInterpSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReconFieldOfView;
	static void NewProp_bValidateCameraPlacement_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bValidateCameraPlacement;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraCollisionRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_IlluminateIntensity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_IlluminateAttenuationRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_IlluminateOuterConeAngle;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_IlluminateInnerConeAngle;
	static const UECodeGen_Private::FStructPropertyParams NewProp_IlluminateColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_IlluminateFadeDuration;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_FlashlightOnSound;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_FlashlightOffSound;
	static void NewProp_bCreateReconPromptWidget_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateReconPromptWidget;
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_ReconPromptWidgetClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReconPromptStyle;
	static const UECodeGen_Private::FTextPropertyParams NewProp_FocusedTargetPromptFormat;
	static const UECodeGen_Private::FTextPropertyParams NewProp_EnteringPrompt;
	static const UECodeGen_Private::FTextPropertyParams NewProp_FlashlightActivePromptFormat;
	static const UECodeGen_Private::FTextPropertyParams NewProp_ObservingPromptFormat;
	static const UECodeGen_Private::FTextPropertyParams NewProp_DoorMovingFailurePrompt;
	static const UECodeGen_Private::FTextPropertyParams NewProp_DoorOpenFailurePrompt;
	static const UECodeGen_Private::FTextPropertyParams NewProp_BlockedFailurePrompt;
	static const UECodeGen_Private::FTextPropertyParams NewProp_OutOfRangeFailurePrompt;
	static const UECodeGen_Private::FTextPropertyParams NewProp_GenericFailurePrompt;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMReconGameplayIntegrationSettings constinit property declarations ********
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMReconGameplayIntegrationSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics

// ********** Begin Class UJMReconGameplayIntegrationSettings Property Definitions *****************
void Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bAutoAddPlayerBridge_SetBit(void* Obj)
{
	((UJMReconGameplayIntegrationSettings*)Obj)->bAutoAddPlayerBridge = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bAutoAddPlayerBridge = { "bAutoAddPlayerBridge", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMReconGameplayIntegrationSettings), &Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bAutoAddPlayerBridge_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoAddPlayerBridge_MetaData), NewProp_bAutoAddPlayerBridge_MetaData) };
void Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bAutoBindInput_SetBit(void* Obj)
{
	((UJMReconGameplayIntegrationSettings*)Obj)->bAutoBindInput = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bAutoBindInput = { "bAutoBindInput", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMReconGameplayIntegrationSettings), &Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bAutoBindInput_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoBindInput_MetaData), NewProp_bAutoBindInput_MetaData) };
void Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bAutoManageCamera_SetBit(void* Obj)
{
	((UJMReconGameplayIntegrationSettings*)Obj)->bAutoManageCamera = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bAutoManageCamera = { "bAutoManageCamera", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMReconGameplayIntegrationSettings), &Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bAutoManageCamera_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoManageCamera_MetaData), NewProp_bAutoManageCamera_MetaData) };
void Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bAutoManageIlluminate_SetBit(void* Obj)
{
	((UJMReconGameplayIntegrationSettings*)Obj)->bAutoManageIlluminate = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bAutoManageIlluminate = { "bAutoManageIlluminate", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMReconGameplayIntegrationSettings), &Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bAutoManageIlluminate_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoManageIlluminate_MetaData), NewProp_bAutoManageIlluminate_MetaData) };
void Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bAlignPlayerToTarget_SetBit(void* Obj)
{
	((UJMReconGameplayIntegrationSettings*)Obj)->bAlignPlayerToTarget = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bAlignPlayerToTarget = { "bAlignPlayerToTarget", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMReconGameplayIntegrationSettings), &Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bAlignPlayerToTarget_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAlignPlayerToTarget_MetaData), NewProp_bAlignPlayerToTarget_MetaData) };
void Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bLockMovementDuringRecon_SetBit(void* Obj)
{
	((UJMReconGameplayIntegrationSettings*)Obj)->bLockMovementDuringRecon = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bLockMovementDuringRecon = { "bLockMovementDuringRecon", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMReconGameplayIntegrationSettings), &Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bLockMovementDuringRecon_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLockMovementDuringRecon_MetaData), NewProp_bLockMovementDuringRecon_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_StartOrFinishKey = { "StartOrFinishKey", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, StartOrFinishKey), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartOrFinishKey_MetaData), NewProp_StartOrFinishKey_MetaData) }; // 2693575693
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_InteractionDisplayKey = { "InteractionDisplayKey", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, InteractionDisplayKey), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionDisplayKey_MetaData), NewProp_InteractionDisplayKey_MetaData) }; // 2693575693
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_PeekKey = { "PeekKey", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, PeekKey), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PeekKey_MetaData), NewProp_PeekKey_MetaData) }; // 2693575693
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_IlluminateKey = { "IlluminateKey", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, IlluminateKey), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IlluminateKey_MetaData), NewProp_IlluminateKey_MetaData) }; // 2693575693
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_CancelKey = { "CancelKey", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, CancelKey), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CancelKey_MetaData), NewProp_CancelKey_MetaData) }; // 2693575693
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_ExitKey = { "ExitKey", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, ExitKey), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExitKey_MetaData), NewProp_ExitKey_MetaData) }; // 2693575693
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_RestoreBlendTime = { "RestoreBlendTime", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, RestoreBlendTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RestoreBlendTime_MetaData), NewProp_RestoreBlendTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_CameraLookInterpSpeed = { "CameraLookInterpSpeed", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, CameraLookInterpSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraLookInterpSpeed_MetaData), NewProp_CameraLookInterpSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_ReconFieldOfView = { "ReconFieldOfView", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, ReconFieldOfView), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReconFieldOfView_MetaData), NewProp_ReconFieldOfView_MetaData) };
void Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bValidateCameraPlacement_SetBit(void* Obj)
{
	((UJMReconGameplayIntegrationSettings*)Obj)->bValidateCameraPlacement = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bValidateCameraPlacement = { "bValidateCameraPlacement", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMReconGameplayIntegrationSettings), &Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bValidateCameraPlacement_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bValidateCameraPlacement_MetaData), NewProp_bValidateCameraPlacement_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_CameraCollisionRadius = { "CameraCollisionRadius", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, CameraCollisionRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraCollisionRadius_MetaData), NewProp_CameraCollisionRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_IlluminateIntensity = { "IlluminateIntensity", nullptr, (EPropertyFlags)0x0010040000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, IlluminateIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IlluminateIntensity_MetaData), NewProp_IlluminateIntensity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_IlluminateAttenuationRadius = { "IlluminateAttenuationRadius", nullptr, (EPropertyFlags)0x0010040000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, IlluminateAttenuationRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IlluminateAttenuationRadius_MetaData), NewProp_IlluminateAttenuationRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_IlluminateOuterConeAngle = { "IlluminateOuterConeAngle", nullptr, (EPropertyFlags)0x0010040000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, IlluminateOuterConeAngle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IlluminateOuterConeAngle_MetaData), NewProp_IlluminateOuterConeAngle_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_IlluminateInnerConeAngle = { "IlluminateInnerConeAngle", nullptr, (EPropertyFlags)0x0010040000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, IlluminateInnerConeAngle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IlluminateInnerConeAngle_MetaData), NewProp_IlluminateInnerConeAngle_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_IlluminateColor = { "IlluminateColor", nullptr, (EPropertyFlags)0x0010040000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, IlluminateColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IlluminateColor_MetaData), NewProp_IlluminateColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_IlluminateFadeDuration = { "IlluminateFadeDuration", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, IlluminateFadeDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IlluminateFadeDuration_MetaData), NewProp_IlluminateFadeDuration_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_FlashlightOnSound = { "FlashlightOnSound", nullptr, (EPropertyFlags)0x0014040000004001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, FlashlightOnSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlashlightOnSound_MetaData), NewProp_FlashlightOnSound_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_FlashlightOffSound = { "FlashlightOffSound", nullptr, (EPropertyFlags)0x0014040000004001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, FlashlightOffSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlashlightOffSound_MetaData), NewProp_FlashlightOffSound_MetaData) };
void Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bCreateReconPromptWidget_SetBit(void* Obj)
{
	((UJMReconGameplayIntegrationSettings*)Obj)->bCreateReconPromptWidget = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bCreateReconPromptWidget = { "bCreateReconPromptWidget", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMReconGameplayIntegrationSettings), &Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bCreateReconPromptWidget_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCreateReconPromptWidget_MetaData), NewProp_bCreateReconPromptWidget_MetaData) };
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_ReconPromptWidgetClass = { "ReconPromptWidgetClass", nullptr, (EPropertyFlags)0x0014000000004001, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, ReconPromptWidgetClass), Z_Construct_UClass_UJMReconPromptWidgetBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReconPromptWidgetClass_MetaData), NewProp_ReconPromptWidgetClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_ReconPromptStyle = { "ReconPromptStyle", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, ReconPromptStyle), Z_Construct_UScriptStruct_FJMInteractionPromptStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReconPromptStyle_MetaData), NewProp_ReconPromptStyle_MetaData) }; // 2420317743
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_FocusedTargetPromptFormat = { "FocusedTargetPromptFormat", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, FocusedTargetPromptFormat), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FocusedTargetPromptFormat_MetaData), NewProp_FocusedTargetPromptFormat_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_EnteringPrompt = { "EnteringPrompt", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, EnteringPrompt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnteringPrompt_MetaData), NewProp_EnteringPrompt_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_FlashlightActivePromptFormat = { "FlashlightActivePromptFormat", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, FlashlightActivePromptFormat), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlashlightActivePromptFormat_MetaData), NewProp_FlashlightActivePromptFormat_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_ObservingPromptFormat = { "ObservingPromptFormat", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, ObservingPromptFormat), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObservingPromptFormat_MetaData), NewProp_ObservingPromptFormat_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_DoorMovingFailurePrompt = { "DoorMovingFailurePrompt", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, DoorMovingFailurePrompt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DoorMovingFailurePrompt_MetaData), NewProp_DoorMovingFailurePrompt_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_DoorOpenFailurePrompt = { "DoorOpenFailurePrompt", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, DoorOpenFailurePrompt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DoorOpenFailurePrompt_MetaData), NewProp_DoorOpenFailurePrompt_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_BlockedFailurePrompt = { "BlockedFailurePrompt", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, BlockedFailurePrompt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlockedFailurePrompt_MetaData), NewProp_BlockedFailurePrompt_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_OutOfRangeFailurePrompt = { "OutOfRangeFailurePrompt", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, OutOfRangeFailurePrompt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutOfRangeFailurePrompt_MetaData), NewProp_OutOfRangeFailurePrompt_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_GenericFailurePrompt = { "GenericFailurePrompt", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconGameplayIntegrationSettings, GenericFailurePrompt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GenericFailurePrompt_MetaData), NewProp_GenericFailurePrompt_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bAutoAddPlayerBridge,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bAutoBindInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bAutoManageCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bAutoManageIlluminate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bAlignPlayerToTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bLockMovementDuringRecon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_StartOrFinishKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_InteractionDisplayKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_PeekKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_IlluminateKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_CancelKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_ExitKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_RestoreBlendTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_CameraLookInterpSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_ReconFieldOfView,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bValidateCameraPlacement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_CameraCollisionRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_IlluminateIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_IlluminateAttenuationRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_IlluminateOuterConeAngle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_IlluminateInnerConeAngle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_IlluminateColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_IlluminateFadeDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_FlashlightOnSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_FlashlightOffSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_bCreateReconPromptWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_ReconPromptWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_ReconPromptStyle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_FocusedTargetPromptFormat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_EnteringPrompt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_FlashlightActivePromptFormat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_ObservingPromptFormat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_DoorMovingFailurePrompt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_DoorOpenFailurePrompt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_BlockedFailurePrompt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_OutOfRangeFailurePrompt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::NewProp_GenericFailurePrompt,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::PropPointers) < 2048);
// ********** End Class UJMReconGameplayIntegrationSettings Property Definitions *******************
UObject* (*const Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_JMReconGameplayIntegration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::ClassParams = {
	&UJMReconGameplayIntegrationSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::Class_MetaDataParams)
};
void UJMReconGameplayIntegrationSettings::StaticRegisterNativesUJMReconGameplayIntegrationSettings()
{
}
UClass* Z_Construct_UClass_UJMReconGameplayIntegrationSettings()
{
	if (!Z_Registration_Info_UClass_UJMReconGameplayIntegrationSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMReconGameplayIntegrationSettings.OuterSingleton, Z_Construct_UClass_UJMReconGameplayIntegrationSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMReconGameplayIntegrationSettings.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMReconGameplayIntegrationSettings);
UJMReconGameplayIntegrationSettings::~UJMReconGameplayIntegrationSettings() {}
// ********** End Class UJMReconGameplayIntegrationSettings ****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Settings_JMReconGameplayIntegrationSettings_h__Script_JMReconGameplayIntegration_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMReconGameplayIntegrationSettings, UJMReconGameplayIntegrationSettings::StaticClass, TEXT("UJMReconGameplayIntegrationSettings"), &Z_Registration_Info_UClass_UJMReconGameplayIntegrationSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMReconGameplayIntegrationSettings), 3139622619U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Settings_JMReconGameplayIntegrationSettings_h__Script_JMReconGameplayIntegration_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Settings_JMReconGameplayIntegrationSettings_h__Script_JMReconGameplayIntegration_1140661157{
	TEXT("/Script/JMReconGameplayIntegration"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Settings_JMReconGameplayIntegrationSettings_h__Script_JMReconGameplayIntegration_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Settings_JMReconGameplayIntegrationSettings_h__Script_JMReconGameplayIntegration_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
