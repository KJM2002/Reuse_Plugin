// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Settings/InventorySystemSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeInventorySystemSettings() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_AInventoryWorldItemPickup_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventorySystemSettings();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventorySystemSettings_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryWidgetBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_InventorySystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UInventorySystemSettings *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UInventorySystemSettings;
UClass* UInventorySystemSettings::GetPrivateStaticClass()
{
	using TClass = UInventorySystemSettings;
	if (!Z_Registration_Info_UClass_UInventorySystemSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("InventorySystemSettings"),
			Z_Registration_Info_UClass_UInventorySystemSettings.InnerSingleton,
			StaticRegisterNativesUInventorySystemSettings,
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
	return Z_Registration_Info_UClass_UInventorySystemSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UInventorySystemSettings_NoRegister()
{
	return UInventorySystemSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UInventorySystemSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "Inventory" },
		{ "IncludePath", "Settings/InventorySystemSettings.h" },
		{ "ModuleRelativePath", "Public/Settings/InventorySystemSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Configure the reusable JM inventory system." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultInventoryWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/Settings/InventorySystemSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUpgradeLegacyDefaultWidgetToNative_MetaData[] = {
		{ "Category", "UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Replaces only the plugin's legacy WBP_Inventory with the native 0.5 presentation. Custom WBP classes are preserved. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/InventorySystemSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Replaces only the plugin's legacy WBP_Inventory with the native 0.5 presentation. Custom WBP classes are preserved." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventoryOpenSound_MetaData[] = {
		{ "Category", "UI|Sound" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional restrained UI feedback sounds. Empty references fail silently. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/InventorySystemSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional restrained UI feedback sounds. Empty references fail silently." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventoryCloseSound_MetaData[] = {
		{ "Category", "UI|Sound" },
		{ "ModuleRelativePath", "Public/Settings/InventorySystemSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotHoverSound_MetaData[] = {
		{ "Category", "UI|Sound" },
		{ "ModuleRelativePath", "Public/Settings/InventorySystemSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotSelectSound_MetaData[] = {
		{ "Category", "UI|Sound" },
		{ "ModuleRelativePath", "Public/Settings/InventorySystemSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConfirmSound_MetaData[] = {
		{ "Category", "UI|Sound" },
		{ "ModuleRelativePath", "Public/Settings/InventorySystemSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultToggleInventoryAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Settings/InventorySystemSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultToggleInventoryMappingContext_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Settings/InventorySystemSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMaxInventorySlots_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/Settings/InventorySystemSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultDropForwardDistance_MetaData[] = {
		{ "Category", "Drop" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/InventorySystemSettings.h" },
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultDropTraceHeight_MetaData[] = {
		{ "Category", "Drop" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/InventorySystemSettings.h" },
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultDropTraceDepth_MetaData[] = {
		{ "Category", "Drop" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/InventorySystemSettings.h" },
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultWorldItemClass_MetaData[] = {
		{ "Category", "Drop" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Item Definition\xec\x97\x90 WorldItemClass\xea\xb0\x80 \xec\x97\x86\xec\x9d\x84 \xeb\x95\x8c \xec\x82\xac\xec\x9a\xa9\xed\x95\xa0 \xea\xb8\xb0\xeb\xb3\xb8 Pickup \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\xeb\x8b\xa4. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/InventorySystemSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Item Definition\xec\x97\x90 WorldItemClass\xea\xb0\x80 \xec\x97\x86\xec\x9d\x84 \xeb\x95\x8c \xec\x82\xac\xec\x9a\xa9\xed\x95\xa0 \xea\xb8\xb0\xeb\xb3\xb8 Pickup \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\xeb\x8b\xa4." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UInventorySystemSettings constinit property declarations *****************
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_DefaultInventoryWidgetClass;
	static void NewProp_bUpgradeLegacyDefaultWidgetToNative_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUpgradeLegacyDefaultWidgetToNative;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_InventoryOpenSound;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_InventoryCloseSound;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_SlotHoverSound;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_SlotSelectSound;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_ConfirmSound;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_DefaultToggleInventoryAction;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_DefaultToggleInventoryMappingContext;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DefaultMaxInventorySlots;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultDropForwardDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultDropTraceHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultDropTraceDepth;
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_DefaultWorldItemClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UInventorySystemSettings constinit property declarations *******************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventorySystemSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UInventorySystemSettings_Statics

// ********** Begin Class UInventorySystemSettings Property Definitions ****************************
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_DefaultInventoryWidgetClass = { "DefaultInventoryWidgetClass", nullptr, (EPropertyFlags)0x0014000000004001, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySystemSettings, DefaultInventoryWidgetClass), Z_Construct_UClass_UInventoryWidgetBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultInventoryWidgetClass_MetaData), NewProp_DefaultInventoryWidgetClass_MetaData) };
void Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_bUpgradeLegacyDefaultWidgetToNative_SetBit(void* Obj)
{
	((UInventorySystemSettings*)Obj)->bUpgradeLegacyDefaultWidgetToNative = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_bUpgradeLegacyDefaultWidgetToNative = { "bUpgradeLegacyDefaultWidgetToNative", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UInventorySystemSettings), &Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_bUpgradeLegacyDefaultWidgetToNative_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUpgradeLegacyDefaultWidgetToNative_MetaData), NewProp_bUpgradeLegacyDefaultWidgetToNative_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_InventoryOpenSound = { "InventoryOpenSound", nullptr, (EPropertyFlags)0x0014000000004001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySystemSettings, InventoryOpenSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryOpenSound_MetaData), NewProp_InventoryOpenSound_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_InventoryCloseSound = { "InventoryCloseSound", nullptr, (EPropertyFlags)0x0014000000004001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySystemSettings, InventoryCloseSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryCloseSound_MetaData), NewProp_InventoryCloseSound_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_SlotHoverSound = { "SlotHoverSound", nullptr, (EPropertyFlags)0x0014000000004001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySystemSettings, SlotHoverSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotHoverSound_MetaData), NewProp_SlotHoverSound_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_SlotSelectSound = { "SlotSelectSound", nullptr, (EPropertyFlags)0x0014000000004001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySystemSettings, SlotSelectSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotSelectSound_MetaData), NewProp_SlotSelectSound_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_ConfirmSound = { "ConfirmSound", nullptr, (EPropertyFlags)0x0014000000004001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySystemSettings, ConfirmSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConfirmSound_MetaData), NewProp_ConfirmSound_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_DefaultToggleInventoryAction = { "DefaultToggleInventoryAction", nullptr, (EPropertyFlags)0x0014000000004001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySystemSettings, DefaultToggleInventoryAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultToggleInventoryAction_MetaData), NewProp_DefaultToggleInventoryAction_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_DefaultToggleInventoryMappingContext = { "DefaultToggleInventoryMappingContext", nullptr, (EPropertyFlags)0x0014000000004001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySystemSettings, DefaultToggleInventoryMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultToggleInventoryMappingContext_MetaData), NewProp_DefaultToggleInventoryMappingContext_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_DefaultMaxInventorySlots = { "DefaultMaxInventorySlots", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySystemSettings, DefaultMaxInventorySlots), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultMaxInventorySlots_MetaData), NewProp_DefaultMaxInventorySlots_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_DefaultDropForwardDistance = { "DefaultDropForwardDistance", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySystemSettings, DefaultDropForwardDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultDropForwardDistance_MetaData), NewProp_DefaultDropForwardDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_DefaultDropTraceHeight = { "DefaultDropTraceHeight", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySystemSettings, DefaultDropTraceHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultDropTraceHeight_MetaData), NewProp_DefaultDropTraceHeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_DefaultDropTraceDepth = { "DefaultDropTraceDepth", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySystemSettings, DefaultDropTraceDepth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultDropTraceDepth_MetaData), NewProp_DefaultDropTraceDepth_MetaData) };
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_DefaultWorldItemClass = { "DefaultWorldItemClass", nullptr, (EPropertyFlags)0x0014000000004001, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySystemSettings, DefaultWorldItemClass), Z_Construct_UClass_AInventoryWorldItemPickup_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultWorldItemClass_MetaData), NewProp_DefaultWorldItemClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventorySystemSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_DefaultInventoryWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_bUpgradeLegacyDefaultWidgetToNative,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_InventoryOpenSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_InventoryCloseSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_SlotHoverSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_SlotSelectSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_ConfirmSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_DefaultToggleInventoryAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_DefaultToggleInventoryMappingContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_DefaultMaxInventorySlots,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_DefaultDropForwardDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_DefaultDropTraceHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_DefaultDropTraceDepth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySystemSettings_Statics::NewProp_DefaultWorldItemClass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySystemSettings_Statics::PropPointers) < 2048);
// ********** End Class UInventorySystemSettings Property Definitions ******************************
UObject* (*const Z_Construct_UClass_UInventorySystemSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_InventorySystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySystemSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventorySystemSettings_Statics::ClassParams = {
	&UInventorySystemSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UInventorySystemSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySystemSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySystemSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UInventorySystemSettings_Statics::Class_MetaDataParams)
};
void UInventorySystemSettings::StaticRegisterNativesUInventorySystemSettings()
{
}
UClass* Z_Construct_UClass_UInventorySystemSettings()
{
	if (!Z_Registration_Info_UClass_UInventorySystemSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventorySystemSettings.OuterSingleton, Z_Construct_UClass_UInventorySystemSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInventorySystemSettings.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UInventorySystemSettings);
UInventorySystemSettings::~UInventorySystemSettings() {}
// ********** End Class UInventorySystemSettings ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Settings_InventorySystemSettings_h__Script_InventorySystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInventorySystemSettings, UInventorySystemSettings::StaticClass, TEXT("UInventorySystemSettings"), &Z_Registration_Info_UClass_UInventorySystemSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventorySystemSettings), 1196092119U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Settings_InventorySystemSettings_h__Script_InventorySystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Settings_InventorySystemSettings_h__Script_InventorySystem_745135165{
	TEXT("/Script/InventorySystem"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Settings_InventorySystemSettings_h__Script_InventorySystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Settings_InventorySystemSettings_h__Script_InventorySystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
