// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Settings/JMObjectiveSettings.h"

#ifdef JMOBJECTIVE_JMObjectiveSettings_generated_h
#error "JMObjectiveSettings.generated.h already included, missing '#pragma once' in JMObjectiveSettings.h"
#endif
#define JMOBJECTIVE_JMObjectiveSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UJMObjectiveSettings *****************************************************
struct Z_Construct_UClass_UJMObjectiveSettings_Statics;
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveSettings_NoRegister();

#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Settings_JMObjectiveSettings_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMObjectiveSettings(); \
	friend struct ::Z_Construct_UClass_UJMObjectiveSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMOBJECTIVE_API UClass* ::Z_Construct_UClass_UJMObjectiveSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMObjectiveSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMObjective"), Z_Construct_UClass_UJMObjectiveSettings_NoRegister) \
	DECLARE_SERIALIZER(UJMObjectiveSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Settings_JMObjectiveSettings_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMObjectiveSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMObjectiveSettings(UJMObjectiveSettings&&) = delete; \
	UJMObjectiveSettings(const UJMObjectiveSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMObjectiveSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMObjectiveSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMObjectiveSettings) \
	NO_API virtual ~UJMObjectiveSettings();


#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Settings_JMObjectiveSettings_h_9_PROLOG
#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Settings_JMObjectiveSettings_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Settings_JMObjectiveSettings_h_12_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Settings_JMObjectiveSettings_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMObjectiveSettings;

// ********** End Class UJMObjectiveSettings *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Settings_JMObjectiveSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
