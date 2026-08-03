// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Core/ItemInspectorSettings.h"
#include "ItemInspection/JMItemInspectionTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeItemInspectorSettings() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UItemInspectorSettings();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UItemInspectorSettings_NoRegister();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMItemInspectionWidgetBase_NoRegister();
ITEMINSPECTORRUNTIME_API UEnum* Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionDuplicatePolicy();
ITEMINSPECTORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings();
UPackage* Z_Construct_UPackage__Script_ItemInspectorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EJMItemInspectionDuplicatePolicy ******************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMItemInspectionDuplicatePolicy;
static UEnum* EJMItemInspectionDuplicatePolicy_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMItemInspectionDuplicatePolicy.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMItemInspectionDuplicatePolicy.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionDuplicatePolicy, (UObject*)Z_Construct_UPackage__Script_ItemInspectorRuntime(), TEXT("EJMItemInspectionDuplicatePolicy"));
	}
	return Z_Registration_Info_UEnum_EJMItemInspectionDuplicatePolicy.OuterSingleton;
}
template<> ITEMINSPECTORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMItemInspectionDuplicatePolicy>()
{
	return EJMItemInspectionDuplicatePolicy_StaticEnum();
}
struct Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionDuplicatePolicy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Core/ItemInspectorSettings.h" },
		{ "RejectNewRequest.Name", "EJMItemInspectionDuplicatePolicy::RejectNewRequest" },
		{ "ReplaceCurrent.Name", "EJMItemInspectionDuplicatePolicy::ReplaceCurrent" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMItemInspectionDuplicatePolicy::RejectNewRequest", (int64)EJMItemInspectionDuplicatePolicy::RejectNewRequest },
		{ "EJMItemInspectionDuplicatePolicy::ReplaceCurrent", (int64)EJMItemInspectionDuplicatePolicy::ReplaceCurrent },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionDuplicatePolicy_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionDuplicatePolicy_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ItemInspectorRuntime,
	nullptr,
	"EJMItemInspectionDuplicatePolicy",
	"EJMItemInspectionDuplicatePolicy",
	Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionDuplicatePolicy_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionDuplicatePolicy_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionDuplicatePolicy_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionDuplicatePolicy_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionDuplicatePolicy()
{
	if (!Z_Registration_Info_UEnum_EJMItemInspectionDuplicatePolicy.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMItemInspectionDuplicatePolicy.InnerSingleton, Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionDuplicatePolicy_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMItemInspectionDuplicatePolicy.InnerSingleton;
}
// ********** End Enum EJMItemInspectionDuplicatePolicy ********************************************

// ********** Begin Class UItemInspectorSettings ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UItemInspectorSettings;
UClass* UItemInspectorSettings::GetPrivateStaticClass()
{
	using TClass = UItemInspectorSettings;
	if (!Z_Registration_Info_UClass_UItemInspectorSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ItemInspectorSettings"),
			Z_Registration_Info_UClass_UItemInspectorSettings.InnerSingleton,
			StaticRegisterNativesUItemInspectorSettings,
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
	return Z_Registration_Info_UClass_UItemInspectorSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UItemInspectorSettings_NoRegister()
{
	return UItemInspectorSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UItemInspectorSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "Item Inspector" },
		{ "IncludePath", "Core/ItemInspectorSettings.h" },
		{ "ModuleRelativePath", "Public/Core/ItemInspectorSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Configure the reusable JM item inspection system." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultInspectorWidgetClass_MetaData[] = {
		{ "Category", "Item Inspection" },
		{ "ModuleRelativePath", "Public/Core/ItemInspectorSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultRenderTargetSize_MetaData[] = {
		{ "Category", "Item Inspection" },
		{ "ModuleRelativePath", "Public/Core/ItemInspectorSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultRotationSensitivity_MetaData[] = {
		{ "Category", "Item Inspection" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Core/ItemInspectorSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultZoomSpeed_MetaData[] = {
		{ "Category", "Item Inspection" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Core/ItemInspectorSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultPreviewFOV_MetaData[] = {
		{ "Category", "Item Inspection" },
		{ "ClampMax", "170.0" },
		{ "ClampMin", "5.0" },
		{ "ModuleRelativePath", "Public/Core/ItemInspectorSettings.h" },
		{ "Units", "deg" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultBackgroundColor_MetaData[] = {
		{ "Category", "Item Inspection" },
		{ "ModuleRelativePath", "Public/Core/ItemInspectorSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDefaultBlockPlayerInput_MetaData[] = {
		{ "Category", "Item Inspection" },
		{ "ModuleRelativePath", "Public/Core/ItemInspectorSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDefaultPauseGame_MetaData[] = {
		{ "Category", "Item Inspection" },
		{ "ModuleRelativePath", "Public/Core/ItemInspectorSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DuplicatePolicy_MetaData[] = {
		{ "Category", "Item Inspection" },
		{ "ModuleRelativePath", "Public/Core/ItemInspectorSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDebugItemInspection_MetaData[] = {
		{ "Category", "Item Inspection" },
		{ "ModuleRelativePath", "Public/Core/ItemInspectorSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultTransitionSettings_MetaData[] = {
		{ "Category", "Item Inspection|Transition" },
		{ "ModuleRelativePath", "Public/Core/ItemInspectorSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UItemInspectorSettings constinit property declarations *******************
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_DefaultInspectorWidgetClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultRenderTargetSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultRotationSensitivity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultZoomSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultPreviewFOV;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultBackgroundColor;
	static void NewProp_bDefaultBlockPlayerInput_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDefaultBlockPlayerInput;
	static void NewProp_bDefaultPauseGame_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDefaultPauseGame;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DuplicatePolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DuplicatePolicy;
	static void NewProp_bDebugItemInspection_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDebugItemInspection;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefaultTransitionSettings;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UItemInspectorSettings constinit property declarations *********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UItemInspectorSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UItemInspectorSettings_Statics

// ********** Begin Class UItemInspectorSettings Property Definitions ******************************
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_DefaultInspectorWidgetClass = { "DefaultInspectorWidgetClass", nullptr, (EPropertyFlags)0x0014000000004001, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemInspectorSettings, DefaultInspectorWidgetClass), Z_Construct_UClass_UJMItemInspectionWidgetBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultInspectorWidgetClass_MetaData), NewProp_DefaultInspectorWidgetClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_DefaultRenderTargetSize = { "DefaultRenderTargetSize", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemInspectorSettings, DefaultRenderTargetSize), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultRenderTargetSize_MetaData), NewProp_DefaultRenderTargetSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_DefaultRotationSensitivity = { "DefaultRotationSensitivity", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemInspectorSettings, DefaultRotationSensitivity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultRotationSensitivity_MetaData), NewProp_DefaultRotationSensitivity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_DefaultZoomSpeed = { "DefaultZoomSpeed", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemInspectorSettings, DefaultZoomSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultZoomSpeed_MetaData), NewProp_DefaultZoomSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_DefaultPreviewFOV = { "DefaultPreviewFOV", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemInspectorSettings, DefaultPreviewFOV), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultPreviewFOV_MetaData), NewProp_DefaultPreviewFOV_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_DefaultBackgroundColor = { "DefaultBackgroundColor", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemInspectorSettings, DefaultBackgroundColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultBackgroundColor_MetaData), NewProp_DefaultBackgroundColor_MetaData) };
void Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_bDefaultBlockPlayerInput_SetBit(void* Obj)
{
	((UItemInspectorSettings*)Obj)->bDefaultBlockPlayerInput = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_bDefaultBlockPlayerInput = { "bDefaultBlockPlayerInput", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UItemInspectorSettings), &Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_bDefaultBlockPlayerInput_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDefaultBlockPlayerInput_MetaData), NewProp_bDefaultBlockPlayerInput_MetaData) };
void Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_bDefaultPauseGame_SetBit(void* Obj)
{
	((UItemInspectorSettings*)Obj)->bDefaultPauseGame = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_bDefaultPauseGame = { "bDefaultPauseGame", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UItemInspectorSettings), &Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_bDefaultPauseGame_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDefaultPauseGame_MetaData), NewProp_bDefaultPauseGame_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_DuplicatePolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_DuplicatePolicy = { "DuplicatePolicy", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemInspectorSettings, DuplicatePolicy), Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionDuplicatePolicy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DuplicatePolicy_MetaData), NewProp_DuplicatePolicy_MetaData) }; // 552245085
void Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_bDebugItemInspection_SetBit(void* Obj)
{
	((UItemInspectorSettings*)Obj)->bDebugItemInspection = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_bDebugItemInspection = { "bDebugItemInspection", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UItemInspectorSettings), &Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_bDebugItemInspection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDebugItemInspection_MetaData), NewProp_bDebugItemInspection_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_DefaultTransitionSettings = { "DefaultTransitionSettings", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UItemInspectorSettings, DefaultTransitionSettings), Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultTransitionSettings_MetaData), NewProp_DefaultTransitionSettings_MetaData) }; // 1121746411
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UItemInspectorSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_DefaultInspectorWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_DefaultRenderTargetSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_DefaultRotationSensitivity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_DefaultZoomSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_DefaultPreviewFOV,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_DefaultBackgroundColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_bDefaultBlockPlayerInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_bDefaultPauseGame,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_DuplicatePolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_DuplicatePolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_bDebugItemInspection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemInspectorSettings_Statics::NewProp_DefaultTransitionSettings,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UItemInspectorSettings_Statics::PropPointers) < 2048);
// ********** End Class UItemInspectorSettings Property Definitions ********************************
UObject* (*const Z_Construct_UClass_UItemInspectorSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_ItemInspectorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UItemInspectorSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UItemInspectorSettings_Statics::ClassParams = {
	&UItemInspectorSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UItemInspectorSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UItemInspectorSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UItemInspectorSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UItemInspectorSettings_Statics::Class_MetaDataParams)
};
void UItemInspectorSettings::StaticRegisterNativesUItemInspectorSettings()
{
}
UClass* Z_Construct_UClass_UItemInspectorSettings()
{
	if (!Z_Registration_Info_UClass_UItemInspectorSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UItemInspectorSettings.OuterSingleton, Z_Construct_UClass_UItemInspectorSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UItemInspectorSettings.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UItemInspectorSettings);
UItemInspectorSettings::~UItemInspectorSettings() {}
// ********** End Class UItemInspectorSettings *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_Core_ItemInspectorSettings_h__Script_ItemInspectorRuntime_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EJMItemInspectionDuplicatePolicy_StaticEnum, TEXT("EJMItemInspectionDuplicatePolicy"), &Z_Registration_Info_UEnum_EJMItemInspectionDuplicatePolicy, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 552245085U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UItemInspectorSettings, UItemInspectorSettings::StaticClass, TEXT("UItemInspectorSettings"), &Z_Registration_Info_UClass_UItemInspectorSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UItemInspectorSettings), 3151815128U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_Core_ItemInspectorSettings_h__Script_ItemInspectorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_Core_ItemInspectorSettings_h__Script_ItemInspectorRuntime_3840831904{
	TEXT("/Script/ItemInspectorRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_Core_ItemInspectorSettings_h__Script_ItemInspectorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_Core_ItemInspectorSettings_h__Script_ItemInspectorRuntime_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_Core_ItemInspectorSettings_h__Script_ItemInspectorRuntime_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_Core_ItemInspectorSettings_h__Script_ItemInspectorRuntime_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
