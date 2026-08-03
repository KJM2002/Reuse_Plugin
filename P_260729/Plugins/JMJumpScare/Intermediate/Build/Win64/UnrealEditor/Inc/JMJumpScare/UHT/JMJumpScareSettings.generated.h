// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Settings/JMJumpScareSettings.h"

#ifdef JMJUMPSCARE_JMJumpScareSettings_generated_h
#error "JMJumpScareSettings.generated.h already included, missing '#pragma once' in JMJumpScareSettings.h"
#endif
#define JMJUMPSCARE_JMJumpScareSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UJMJumpScareSettings *****************************************************
struct Z_Construct_UClass_UJMJumpScareSettings_Statics;
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareSettings_NoRegister();

#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Settings_JMJumpScareSettings_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMJumpScareSettings(); \
	friend struct ::Z_Construct_UClass_UJMJumpScareSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMJUMPSCARE_API UClass* ::Z_Construct_UClass_UJMJumpScareSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMJumpScareSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMJumpScare"), Z_Construct_UClass_UJMJumpScareSettings_NoRegister) \
	DECLARE_SERIALIZER(UJMJumpScareSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("JMJumpScare");} \



#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Settings_JMJumpScareSettings_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMJumpScareSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMJumpScareSettings(UJMJumpScareSettings&&) = delete; \
	UJMJumpScareSettings(const UJMJumpScareSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMJumpScareSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMJumpScareSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMJumpScareSettings) \
	NO_API virtual ~UJMJumpScareSettings();


#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Settings_JMJumpScareSettings_h_8_PROLOG
#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Settings_JMJumpScareSettings_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Settings_JMJumpScareSettings_h_11_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Settings_JMJumpScareSettings_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMJumpScareSettings;

// ********** End Class UJMJumpScareSettings *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Settings_JMJumpScareSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
