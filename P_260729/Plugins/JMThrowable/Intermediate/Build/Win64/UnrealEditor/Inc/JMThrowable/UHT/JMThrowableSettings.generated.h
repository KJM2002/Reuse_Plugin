// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "JMThrowableSettings.h"

#ifdef JMTHROWABLE_JMThrowableSettings_generated_h
#error "JMThrowableSettings.generated.h already included, missing '#pragma once' in JMThrowableSettings.h"
#endif
#define JMTHROWABLE_JMThrowableSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UJMThrowableSettings *****************************************************
struct Z_Construct_UClass_UJMThrowableSettings_Statics;
JMTHROWABLE_API UClass* Z_Construct_UClass_UJMThrowableSettings_NoRegister();

#define FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableSettings_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMThrowableSettings(); \
	friend struct ::Z_Construct_UClass_UJMThrowableSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMTHROWABLE_API UClass* ::Z_Construct_UClass_UJMThrowableSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMThrowableSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMThrowable"), Z_Construct_UClass_UJMThrowableSettings_NoRegister) \
	DECLARE_SERIALIZER(UJMThrowableSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableSettings_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMThrowableSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMThrowableSettings(UJMThrowableSettings&&) = delete; \
	UJMThrowableSettings(const UJMThrowableSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMThrowableSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMThrowableSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMThrowableSettings) \
	NO_API virtual ~UJMThrowableSettings();


#define FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableSettings_h_8_PROLOG
#define FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableSettings_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableSettings_h_11_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableSettings_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMThrowableSettings;

// ********** End Class UJMThrowableSettings *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
