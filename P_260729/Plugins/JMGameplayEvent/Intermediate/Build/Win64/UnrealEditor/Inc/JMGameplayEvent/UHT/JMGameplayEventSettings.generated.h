// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Settings/JMGameplayEventSettings.h"

#ifdef JMGAMEPLAYEVENT_JMGameplayEventSettings_generated_h
#error "JMGameplayEventSettings.generated.h already included, missing '#pragma once' in JMGameplayEventSettings.h"
#endif
#define JMGAMEPLAYEVENT_JMGameplayEventSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UJMGameplayEventSettings *************************************************
struct Z_Construct_UClass_UJMGameplayEventSettings_Statics;
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventSettings_NoRegister();

#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Settings_JMGameplayEventSettings_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMGameplayEventSettings(); \
	friend struct ::Z_Construct_UClass_UJMGameplayEventSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMGAMEPLAYEVENT_API UClass* ::Z_Construct_UClass_UJMGameplayEventSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMGameplayEventSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMGameplayEvent"), Z_Construct_UClass_UJMGameplayEventSettings_NoRegister) \
	DECLARE_SERIALIZER(UJMGameplayEventSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("JMGameplayEvent");} \



#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Settings_JMGameplayEventSettings_h_10_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMGameplayEventSettings(UJMGameplayEventSettings&&) = delete; \
	UJMGameplayEventSettings(const UJMGameplayEventSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMGameplayEventSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMGameplayEventSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMGameplayEventSettings) \
	NO_API virtual ~UJMGameplayEventSettings();


#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Settings_JMGameplayEventSettings_h_7_PROLOG
#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Settings_JMGameplayEventSettings_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Settings_JMGameplayEventSettings_h_10_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Settings_JMGameplayEventSettings_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMGameplayEventSettings;

// ********** End Class UJMGameplayEventSettings ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Settings_JMGameplayEventSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
