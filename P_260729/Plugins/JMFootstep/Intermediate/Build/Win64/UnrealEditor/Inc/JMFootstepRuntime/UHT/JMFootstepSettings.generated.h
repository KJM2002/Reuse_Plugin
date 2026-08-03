// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Settings/JMFootstepSettings.h"

#ifdef JMFOOTSTEPRUNTIME_JMFootstepSettings_generated_h
#error "JMFootstepSettings.generated.h already included, missing '#pragma once' in JMFootstepSettings.h"
#endif
#define JMFOOTSTEPRUNTIME_JMFootstepSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UJMFootstepSettings ******************************************************
struct Z_Construct_UClass_UJMFootstepSettings_Statics;
JMFOOTSTEPRUNTIME_API UClass* Z_Construct_UClass_UJMFootstepSettings_NoRegister();

#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Settings_JMFootstepSettings_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMFootstepSettings(); \
	friend struct ::Z_Construct_UClass_UJMFootstepSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMFOOTSTEPRUNTIME_API UClass* ::Z_Construct_UClass_UJMFootstepSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMFootstepSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMFootstepRuntime"), Z_Construct_UClass_UJMFootstepSettings_NoRegister) \
	DECLARE_SERIALIZER(UJMFootstepSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Settings_JMFootstepSettings_h_15_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMFootstepSettings(UJMFootstepSettings&&) = delete; \
	UJMFootstepSettings(const UJMFootstepSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMFootstepSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMFootstepSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMFootstepSettings) \
	NO_API virtual ~UJMFootstepSettings();


#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Settings_JMFootstepSettings_h_12_PROLOG
#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Settings_JMFootstepSettings_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Settings_JMFootstepSettings_h_15_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Settings_JMFootstepSettings_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMFootstepSettings;

// ********** End Class UJMFootstepSettings ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Settings_JMFootstepSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
