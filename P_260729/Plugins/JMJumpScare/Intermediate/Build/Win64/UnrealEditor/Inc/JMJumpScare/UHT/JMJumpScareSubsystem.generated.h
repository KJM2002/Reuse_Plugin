// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystems/JMJumpScareSubsystem.h"

#ifdef JMJUMPSCARE_JMJumpScareSubsystem_generated_h
#error "JMJumpScareSubsystem.generated.h already included, missing '#pragma once' in JMJumpScareSubsystem.h"
#endif
#define JMJUMPSCARE_JMJumpScareSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
enum class EJMJumpScarePhase : uint8;
enum class EJMJumpScareState : uint8;
struct FJMJumpScareActiveInfo;

// ********** Begin Delegate FJMJumpScareStateChanged **********************************************
#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Subsystems_JMJumpScareSubsystem_h_14_DELEGATE \
JMJUMPSCARE_API void FJMJumpScareStateChanged_DelegateWrapper(const FMulticastScriptDelegate& JMJumpScareStateChanged, EJMJumpScareState OldState, EJMJumpScareState NewState);


// ********** End Delegate FJMJumpScareStateChanged ************************************************

// ********** Begin Delegate FJMJumpScarePhaseChanged **********************************************
#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Subsystems_JMJumpScareSubsystem_h_15_DELEGATE \
JMJUMPSCARE_API void FJMJumpScarePhaseChanged_DelegateWrapper(const FMulticastScriptDelegate& JMJumpScarePhaseChanged, EJMJumpScarePhase OldPhase, EJMJumpScarePhase NewPhase);


// ********** End Delegate FJMJumpScarePhaseChanged ************************************************

// ********** Begin Class UJMJumpScareSubsystem ****************************************************
#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Subsystems_JMJumpScareSubsystem_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execResetOncePolicy); \
	DECLARE_FUNCTION(execGetActiveJumpScare); \
	DECLARE_FUNCTION(execGetPhase); \
	DECLARE_FUNCTION(execGetState); \
	DECLARE_FUNCTION(execIsJumpScarePlaying); \
	DECLARE_FUNCTION(execCancelJumpScare);


struct Z_Construct_UClass_UJMJumpScareSubsystem_Statics;
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareSubsystem_NoRegister();

#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Subsystems_JMJumpScareSubsystem_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMJumpScareSubsystem(); \
	friend struct ::Z_Construct_UClass_UJMJumpScareSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMJUMPSCARE_API UClass* ::Z_Construct_UClass_UJMJumpScareSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMJumpScareSubsystem, UWorldSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/JMJumpScare"), Z_Construct_UClass_UJMJumpScareSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UJMJumpScareSubsystem)


#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Subsystems_JMJumpScareSubsystem_h_21_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMJumpScareSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMJumpScareSubsystem(UJMJumpScareSubsystem&&) = delete; \
	UJMJumpScareSubsystem(const UJMJumpScareSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMJumpScareSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMJumpScareSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMJumpScareSubsystem) \
	NO_API virtual ~UJMJumpScareSubsystem();


#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Subsystems_JMJumpScareSubsystem_h_18_PROLOG
#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Subsystems_JMJumpScareSubsystem_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Subsystems_JMJumpScareSubsystem_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Subsystems_JMJumpScareSubsystem_h_21_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Subsystems_JMJumpScareSubsystem_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMJumpScareSubsystem;

// ********** End Class UJMJumpScareSubsystem ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Subsystems_JMJumpScareSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
