// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystems/JMObjectiveSubsystem.h"

#ifdef JMOBJECTIVE_JMObjectiveSubsystem_generated_h
#error "JMObjectiveSubsystem.generated.h already included, missing '#pragma once' in JMObjectiveSubsystem.h"
#endif
#define JMOBJECTIVE_JMObjectiveSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UJMObjectiveDefinition;
struct FGameplayTag;
struct FJMObjectiveRuntimeState;
struct FJMObjectiveSaveData;

// ********** Begin Class UJMObjectiveSubsystem ****************************************************
#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveSubsystem_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRestoreObjectiveStates); \
	DECLARE_FUNCTION(execCaptureObjectiveStates); \
	DECLARE_FUNCTION(execIsObjectiveCompleted); \
	DECLARE_FUNCTION(execIsObjectiveActive); \
	DECLARE_FUNCTION(execGetCompletedObjectives); \
	DECLARE_FUNCTION(execGetActiveObjectives); \
	DECLARE_FUNCTION(execGetObjectiveProgress); \
	DECLARE_FUNCTION(execGetObjectiveState); \
	DECLARE_FUNCTION(execAddObjectiveProgress); \
	DECLARE_FUNCTION(execResetObjective); \
	DECLARE_FUNCTION(execFailObjective); \
	DECLARE_FUNCTION(execCompleteObjective); \
	DECLARE_FUNCTION(execDeactivateObjective); \
	DECLARE_FUNCTION(execActivateObjective); \
	DECLARE_FUNCTION(execUnregisterObjective); \
	DECLARE_FUNCTION(execRegisterObjective);


struct Z_Construct_UClass_UJMObjectiveSubsystem_Statics;
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveSubsystem_NoRegister();

#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveSubsystem_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMObjectiveSubsystem(); \
	friend struct ::Z_Construct_UClass_UJMObjectiveSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMOBJECTIVE_API UClass* ::Z_Construct_UClass_UJMObjectiveSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMObjectiveSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/JMObjective"), Z_Construct_UClass_UJMObjectiveSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UJMObjectiveSubsystem)


#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveSubsystem_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMObjectiveSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMObjectiveSubsystem(UJMObjectiveSubsystem&&) = delete; \
	UJMObjectiveSubsystem(const UJMObjectiveSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMObjectiveSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMObjectiveSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMObjectiveSubsystem) \
	NO_API virtual ~UJMObjectiveSubsystem();


#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveSubsystem_h_12_PROLOG
#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveSubsystem_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveSubsystem_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveSubsystem_h_15_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveSubsystem_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMObjectiveSubsystem;

// ********** End Class UJMObjectiveSubsystem ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
