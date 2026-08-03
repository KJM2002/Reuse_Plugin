// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Settings/JMDoorSettings.h"

#ifdef JMDOORRUNTIME_JMDoorSettings_generated_h
#error "JMDoorSettings.generated.h already included, missing '#pragma once' in JMDoorSettings.h"
#endif
#define JMDOORRUNTIME_JMDoorSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UJMDoorSettings **********************************************************
struct Z_Construct_UClass_UJMDoorSettings_Statics;
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorSettings_NoRegister();

#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Settings_JMDoorSettings_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMDoorSettings(); \
	friend struct ::Z_Construct_UClass_UJMDoorSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMDOORRUNTIME_API UClass* ::Z_Construct_UClass_UJMDoorSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMDoorSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMDoorRuntime"), Z_Construct_UClass_UJMDoorSettings_NoRegister) \
	DECLARE_SERIALIZER(UJMDoorSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("JMDoor");} \



#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Settings_JMDoorSettings_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMDoorSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMDoorSettings(UJMDoorSettings&&) = delete; \
	UJMDoorSettings(const UJMDoorSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMDoorSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMDoorSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMDoorSettings) \
	NO_API virtual ~UJMDoorSettings();


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Settings_JMDoorSettings_h_8_PROLOG
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Settings_JMDoorSettings_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Settings_JMDoorSettings_h_11_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Settings_JMDoorSettings_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMDoorSettings;

// ********** End Class UJMDoorSettings ************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Settings_JMDoorSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
