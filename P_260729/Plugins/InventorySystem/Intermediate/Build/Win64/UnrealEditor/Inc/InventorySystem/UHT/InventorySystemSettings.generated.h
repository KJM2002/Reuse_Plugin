// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Settings/InventorySystemSettings.h"

#ifdef INVENTORYSYSTEM_InventorySystemSettings_generated_h
#error "InventorySystemSettings.generated.h already included, missing '#pragma once' in InventorySystemSettings.h"
#endif
#define INVENTORYSYSTEM_InventorySystemSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UInventorySystemSettings *************************************************
struct Z_Construct_UClass_UInventorySystemSettings_Statics;
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventorySystemSettings_NoRegister();

#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Settings_InventorySystemSettings_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInventorySystemSettings(); \
	friend struct ::Z_Construct_UClass_UInventorySystemSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend INVENTORYSYSTEM_API UClass* ::Z_Construct_UClass_UInventorySystemSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UInventorySystemSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/InventorySystem"), Z_Construct_UClass_UInventorySystemSettings_NoRegister) \
	DECLARE_SERIALIZER(UInventorySystemSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Settings_InventorySystemSettings_h_17_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UInventorySystemSettings(UInventorySystemSettings&&) = delete; \
	UInventorySystemSettings(const UInventorySystemSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventorySystemSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventorySystemSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UInventorySystemSettings) \
	NO_API virtual ~UInventorySystemSettings();


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Settings_InventorySystemSettings_h_14_PROLOG
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Settings_InventorySystemSettings_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Settings_InventorySystemSettings_h_17_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Settings_InventorySystemSettings_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UInventorySystemSettings;

// ********** End Class UInventorySystemSettings ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Settings_InventorySystemSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
