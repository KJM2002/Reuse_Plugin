// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Settings/JMHideSettings.h"

#ifdef JMHIDERUNTIME_JMHideSettings_generated_h
#error "JMHideSettings.generated.h already included, missing '#pragma once' in JMHideSettings.h"
#endif
#define JMHIDERUNTIME_JMHideSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UJMHideSettings **********************************************************
struct Z_Construct_UClass_UJMHideSettings_Statics;
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideSettings_NoRegister();

#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Settings_JMHideSettings_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMHideSettings(); \
	friend struct ::Z_Construct_UClass_UJMHideSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMHIDERUNTIME_API UClass* ::Z_Construct_UClass_UJMHideSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMHideSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMHideRuntime"), Z_Construct_UClass_UJMHideSettings_NoRegister) \
	DECLARE_SERIALIZER(UJMHideSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Settings_JMHideSettings_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMHideSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMHideSettings(UJMHideSettings&&) = delete; \
	UJMHideSettings(const UJMHideSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMHideSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMHideSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMHideSettings) \
	NO_API virtual ~UJMHideSettings();


#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Settings_JMHideSettings_h_8_PROLOG
#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Settings_JMHideSettings_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Settings_JMHideSettings_h_11_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Settings_JMHideSettings_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMHideSettings;

// ********** End Class UJMHideSettings ************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Settings_JMHideSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
