// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Settings/JMDoorSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMDoorSettings() {}

// ********** Begin Cross Module References ********************************************************
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorSettings();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorSettings_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMDoorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMDoorSettings **********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMDoorSettings;
UClass* UJMDoorSettings::GetPrivateStaticClass()
{
	using TClass = UJMDoorSettings;
	if (!Z_Registration_Info_UClass_UJMDoorSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMDoorSettings"),
			Z_Registration_Info_UClass_UJMDoorSettings.InnerSingleton,
			StaticRegisterNativesUJMDoorSettings,
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
	return Z_Registration_Info_UClass_UJMDoorSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMDoorSettings_NoRegister()
{
	return UJMDoorSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMDoorSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "Door" },
		{ "IncludePath", "Settings/JMDoorSettings.h" },
		{ "ModuleRelativePath", "Public/Settings/JMDoorSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Configure the reusable JM door system." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultBlockingChannel_MetaData[] = {
		{ "Category", "Blocking" },
		{ "ModuleRelativePath", "Public/Settings/JMDoorSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDrawObstructionDebug_MetaData[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/Settings/JMDoorSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDrawCharacterPushDebug_MetaData[] = {
		{ "Category", "Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Draw leaf motion, contact point, requested push, actual movement and blocking normals. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/JMDoorSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Draw leaf motion, contact point, requested push, actual movement and blocking normals." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLogCharacterPushDebug_MetaData[] = {
		{ "Category", "Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Log leaf delta, requested push, actual movement and sweep result for each contacted character. */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/JMDoorSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Log leaf delta, requested push, actual movement and sweep result for each contacted character." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterPushDebugDuration_MetaData[] = {
		{ "Category", "Debug" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Settings/JMDoorSettings.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bWarnOnMissingMovementComponent_MetaData[] = {
		{ "Category", "Validation" },
		{ "ModuleRelativePath", "Public/Settings/JMDoorSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMDoorSettings constinit property declarations **************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_DefaultBlockingChannel;
	static void NewProp_bDrawObstructionDebug_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawObstructionDebug;
	static void NewProp_bDrawCharacterPushDebug_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawCharacterPushDebug;
	static void NewProp_bLogCharacterPushDebug_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLogCharacterPushDebug;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CharacterPushDebugDuration;
	static void NewProp_bWarnOnMissingMovementComponent_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWarnOnMissingMovementComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMDoorSettings constinit property declarations ****************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMDoorSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMDoorSettings_Statics

// ********** Begin Class UJMDoorSettings Property Definitions *************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMDoorSettings_Statics::NewProp_DefaultBlockingChannel = { "DefaultBlockingChannel", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorSettings, DefaultBlockingChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultBlockingChannel_MetaData), NewProp_DefaultBlockingChannel_MetaData) }; // 838391399
void Z_Construct_UClass_UJMDoorSettings_Statics::NewProp_bDrawObstructionDebug_SetBit(void* Obj)
{
	((UJMDoorSettings*)Obj)->bDrawObstructionDebug = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMDoorSettings_Statics::NewProp_bDrawObstructionDebug = { "bDrawObstructionDebug", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMDoorSettings), &Z_Construct_UClass_UJMDoorSettings_Statics::NewProp_bDrawObstructionDebug_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDrawObstructionDebug_MetaData), NewProp_bDrawObstructionDebug_MetaData) };
void Z_Construct_UClass_UJMDoorSettings_Statics::NewProp_bDrawCharacterPushDebug_SetBit(void* Obj)
{
	((UJMDoorSettings*)Obj)->bDrawCharacterPushDebug = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMDoorSettings_Statics::NewProp_bDrawCharacterPushDebug = { "bDrawCharacterPushDebug", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMDoorSettings), &Z_Construct_UClass_UJMDoorSettings_Statics::NewProp_bDrawCharacterPushDebug_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDrawCharacterPushDebug_MetaData), NewProp_bDrawCharacterPushDebug_MetaData) };
void Z_Construct_UClass_UJMDoorSettings_Statics::NewProp_bLogCharacterPushDebug_SetBit(void* Obj)
{
	((UJMDoorSettings*)Obj)->bLogCharacterPushDebug = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMDoorSettings_Statics::NewProp_bLogCharacterPushDebug = { "bLogCharacterPushDebug", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMDoorSettings), &Z_Construct_UClass_UJMDoorSettings_Statics::NewProp_bLogCharacterPushDebug_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLogCharacterPushDebug_MetaData), NewProp_bLogCharacterPushDebug_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMDoorSettings_Statics::NewProp_CharacterPushDebugDuration = { "CharacterPushDebugDuration", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorSettings, CharacterPushDebugDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterPushDebugDuration_MetaData), NewProp_CharacterPushDebugDuration_MetaData) };
void Z_Construct_UClass_UJMDoorSettings_Statics::NewProp_bWarnOnMissingMovementComponent_SetBit(void* Obj)
{
	((UJMDoorSettings*)Obj)->bWarnOnMissingMovementComponent = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMDoorSettings_Statics::NewProp_bWarnOnMissingMovementComponent = { "bWarnOnMissingMovementComponent", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMDoorSettings), &Z_Construct_UClass_UJMDoorSettings_Statics::NewProp_bWarnOnMissingMovementComponent_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bWarnOnMissingMovementComponent_MetaData), NewProp_bWarnOnMissingMovementComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMDoorSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorSettings_Statics::NewProp_DefaultBlockingChannel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorSettings_Statics::NewProp_bDrawObstructionDebug,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorSettings_Statics::NewProp_bDrawCharacterPushDebug,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorSettings_Statics::NewProp_bLogCharacterPushDebug,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorSettings_Statics::NewProp_CharacterPushDebugDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorSettings_Statics::NewProp_bWarnOnMissingMovementComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorSettings_Statics::PropPointers) < 2048);
// ********** End Class UJMDoorSettings Property Definitions ***************************************
UObject* (*const Z_Construct_UClass_UJMDoorSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMDoorSettings_Statics::ClassParams = {
	&UJMDoorSettings::StaticClass,
	"JMDoor",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMDoorSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMDoorSettings_Statics::Class_MetaDataParams)
};
void UJMDoorSettings::StaticRegisterNativesUJMDoorSettings()
{
}
UClass* Z_Construct_UClass_UJMDoorSettings()
{
	if (!Z_Registration_Info_UClass_UJMDoorSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMDoorSettings.OuterSingleton, Z_Construct_UClass_UJMDoorSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMDoorSettings.OuterSingleton;
}
UJMDoorSettings::UJMDoorSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMDoorSettings);
UJMDoorSettings::~UJMDoorSettings() {}
// ********** End Class UJMDoorSettings ************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Settings_JMDoorSettings_h__Script_JMDoorRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMDoorSettings, UJMDoorSettings::StaticClass, TEXT("UJMDoorSettings"), &Z_Registration_Info_UClass_UJMDoorSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMDoorSettings), 4028062854U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Settings_JMDoorSettings_h__Script_JMDoorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Settings_JMDoorSettings_h__Script_JMDoorRuntime_3412078364{
	TEXT("/Script/JMDoorRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Settings_JMDoorSettings_h__Script_JMDoorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Settings_JMDoorSettings_h__Script_JMDoorRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
