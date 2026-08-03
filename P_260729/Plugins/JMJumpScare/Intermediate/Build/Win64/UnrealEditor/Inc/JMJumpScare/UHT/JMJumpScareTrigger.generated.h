// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Actors/JMJumpScareTrigger.h"

#ifdef JMJUMPSCARE_JMJumpScareTrigger_generated_h
#error "JMJumpScareTrigger.generated.h already included, missing '#pragma once' in JMJumpScareTrigger.h"
#endif
#define JMJUMPSCARE_JMJumpScareTrigger_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
struct FJMJumpScareTriggerSaveState;

// ********** Begin Class AJMJumpScareTrigger ******************************************************
#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Actors_JMJumpScareTrigger_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleBeginOverlap); \
	DECLARE_FUNCTION(execRestoreSaveState); \
	DECLARE_FUNCTION(execCaptureSaveState); \
	DECLARE_FUNCTION(execResetTrigger);


struct Z_Construct_UClass_AJMJumpScareTrigger_Statics;
JMJUMPSCARE_API UClass* Z_Construct_UClass_AJMJumpScareTrigger_NoRegister();

#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Actors_JMJumpScareTrigger_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAJMJumpScareTrigger(); \
	friend struct ::Z_Construct_UClass_AJMJumpScareTrigger_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMJUMPSCARE_API UClass* ::Z_Construct_UClass_AJMJumpScareTrigger_NoRegister(); \
public: \
	DECLARE_CLASS2(AJMJumpScareTrigger, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMJumpScare"), Z_Construct_UClass_AJMJumpScareTrigger_NoRegister) \
	DECLARE_SERIALIZER(AJMJumpScareTrigger)


#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Actors_JMJumpScareTrigger_h_16_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AJMJumpScareTrigger(AJMJumpScareTrigger&&) = delete; \
	AJMJumpScareTrigger(const AJMJumpScareTrigger&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AJMJumpScareTrigger); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AJMJumpScareTrigger); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AJMJumpScareTrigger) \
	NO_API virtual ~AJMJumpScareTrigger();


#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Actors_JMJumpScareTrigger_h_13_PROLOG
#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Actors_JMJumpScareTrigger_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Actors_JMJumpScareTrigger_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Actors_JMJumpScareTrigger_h_16_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Actors_JMJumpScareTrigger_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AJMJumpScareTrigger;

// ********** End Class AJMJumpScareTrigger ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Actors_JMJumpScareTrigger_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
