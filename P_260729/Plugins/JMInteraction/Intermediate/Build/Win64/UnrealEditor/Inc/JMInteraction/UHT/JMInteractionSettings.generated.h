// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Settings/JMInteractionSettings.h"

#ifdef JMINTERACTION_JMInteractionSettings_generated_h
#error "JMInteractionSettings.generated.h already included, missing '#pragma once' in JMInteractionSettings.h"
#endif
#define JMINTERACTION_JMInteractionSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UJMInteractionSettings ***************************************************
struct Z_Construct_UClass_UJMInteractionSettings_Statics;
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractionSettings_NoRegister();

#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Settings_JMInteractionSettings_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMInteractionSettings(); \
	friend struct ::Z_Construct_UClass_UJMInteractionSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMINTERACTION_API UClass* ::Z_Construct_UClass_UJMInteractionSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMInteractionSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMInteraction"), Z_Construct_UClass_UJMInteractionSettings_NoRegister) \
	DECLARE_SERIALIZER(UJMInteractionSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Settings_JMInteractionSettings_h_15_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMInteractionSettings(UJMInteractionSettings&&) = delete; \
	UJMInteractionSettings(const UJMInteractionSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMInteractionSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMInteractionSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMInteractionSettings) \
	NO_API virtual ~UJMInteractionSettings();


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Settings_JMInteractionSettings_h_12_PROLOG
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Settings_JMInteractionSettings_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Settings_JMInteractionSettings_h_15_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Settings_JMInteractionSettings_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMInteractionSettings;

// ********** End Class UJMInteractionSettings *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Settings_JMInteractionSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
