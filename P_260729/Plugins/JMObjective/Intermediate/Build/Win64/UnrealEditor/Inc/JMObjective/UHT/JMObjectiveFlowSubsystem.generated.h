// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystems/JMObjectiveFlowSubsystem.h"

#ifdef JMOBJECTIVE_JMObjectiveFlowSubsystem_generated_h
#error "JMObjectiveFlowSubsystem.generated.h already included, missing '#pragma once' in JMObjectiveFlowSubsystem.h"
#endif
#define JMOBJECTIVE_JMObjectiveFlowSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UJMObjectiveFlowDefinition;
struct FGameplayTag;
struct FJMObjectiveFlowRuntimeState;
struct FJMObjectiveFlowSaveData;
struct FJMObjectiveRuntimeState;

// ********** Begin Class UJMObjectiveFlowSubsystem ************************************************
#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveFlowSubsystem_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleObjectiveFailed); \
	DECLARE_FUNCTION(execHandleObjectiveCompleted); \
	DECLARE_FUNCTION(execRestoreObjectiveFlowStates); \
	DECLARE_FUNCTION(execCaptureObjectiveFlowStates); \
	DECLARE_FUNCTION(execIsObjectiveFlowCompleted); \
	DECLARE_FUNCTION(execIsObjectiveFlowActive); \
	DECLARE_FUNCTION(execGetActiveObjectiveFlows); \
	DECLARE_FUNCTION(execGetObjectiveFlowState); \
	DECLARE_FUNCTION(execRestartObjectiveFlow); \
	DECLARE_FUNCTION(execResetObjectiveFlow); \
	DECLARE_FUNCTION(execStopObjectiveFlow); \
	DECLARE_FUNCTION(execStartObjectiveFlow);


struct Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics;
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveFlowSubsystem_NoRegister();

#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveFlowSubsystem_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMObjectiveFlowSubsystem(); \
	friend struct ::Z_Construct_UClass_UJMObjectiveFlowSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMOBJECTIVE_API UClass* ::Z_Construct_UClass_UJMObjectiveFlowSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMObjectiveFlowSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/JMObjective"), Z_Construct_UClass_UJMObjectiveFlowSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UJMObjectiveFlowSubsystem)


#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveFlowSubsystem_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMObjectiveFlowSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMObjectiveFlowSubsystem(UJMObjectiveFlowSubsystem&&) = delete; \
	UJMObjectiveFlowSubsystem(const UJMObjectiveFlowSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMObjectiveFlowSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMObjectiveFlowSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMObjectiveFlowSubsystem) \
	NO_API virtual ~UJMObjectiveFlowSubsystem();


#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveFlowSubsystem_h_13_PROLOG
#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveFlowSubsystem_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveFlowSubsystem_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveFlowSubsystem_h_16_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveFlowSubsystem_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMObjectiveFlowSubsystem;

// ********** End Class UJMObjectiveFlowSubsystem **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveFlowSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
