// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Settings/JMReconSettings.h"

#ifdef JMRECONRUNTIME_JMReconSettings_generated_h
#error "JMReconSettings.generated.h already included, missing '#pragma once' in JMReconSettings.h"
#endif
#define JMRECONRUNTIME_JMReconSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UJMReconSettings *********************************************************
struct Z_Construct_UClass_UJMReconSettings_Statics;
JMRECONRUNTIME_API UClass* Z_Construct_UClass_UJMReconSettings_NoRegister();

#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Settings_JMReconSettings_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMReconSettings(); \
	friend struct ::Z_Construct_UClass_UJMReconSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMRECONRUNTIME_API UClass* ::Z_Construct_UClass_UJMReconSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMReconSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMReconRuntime"), Z_Construct_UClass_UJMReconSettings_NoRegister) \
	DECLARE_SERIALIZER(UJMReconSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Settings_JMReconSettings_h_12_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMReconSettings(UJMReconSettings&&) = delete; \
	UJMReconSettings(const UJMReconSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMReconSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMReconSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMReconSettings) \
	NO_API virtual ~UJMReconSettings();


#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Settings_JMReconSettings_h_9_PROLOG
#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Settings_JMReconSettings_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Settings_JMReconSettings_h_12_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Settings_JMReconSettings_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMReconSettings;

// ********** End Class UJMReconSettings ***********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Settings_JMReconSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
