// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DialogueSettings.h"

#ifdef REUSABLEDIALOGUESYSTEM_DialogueSettings_generated_h
#error "DialogueSettings.generated.h already included, missing '#pragma once' in DialogueSettings.h"
#endif
#define REUSABLEDIALOGUESYSTEM_DialogueSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UDialogueSettings ********************************************************
struct Z_Construct_UClass_UDialogueSettings_Statics;
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueSettings_NoRegister();

#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSettings_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDialogueSettings(); \
	friend struct ::Z_Construct_UClass_UDialogueSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend REUSABLEDIALOGUESYSTEM_API UClass* ::Z_Construct_UClass_UDialogueSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UDialogueSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/ReusableDialogueSystem"), Z_Construct_UClass_UDialogueSettings_NoRegister) \
	DECLARE_SERIALIZER(UDialogueSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSettings_h_14_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDialogueSettings(UDialogueSettings&&) = delete; \
	UDialogueSettings(const UDialogueSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDialogueSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDialogueSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDialogueSettings) \
	NO_API virtual ~UDialogueSettings();


#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSettings_h_11_PROLOG
#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSettings_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSettings_h_14_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSettings_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDialogueSettings;

// ********** End Class UDialogueSettings **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
