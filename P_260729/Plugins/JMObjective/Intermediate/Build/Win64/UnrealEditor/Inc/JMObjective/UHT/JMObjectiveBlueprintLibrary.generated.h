// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Blueprint/JMObjectiveBlueprintLibrary.h"

#ifdef JMOBJECTIVE_JMObjectiveBlueprintLibrary_generated_h
#error "JMObjectiveBlueprintLibrary.generated.h already included, missing '#pragma once' in JMObjectiveBlueprintLibrary.h"
#endif
#define JMOBJECTIVE_JMObjectiveBlueprintLibrary_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UJMObjectiveDefinition;
class UJMObjectiveFlowDefinition;
class UJMObjectiveFlowSubsystem;
class UJMObjectiveSubsystem;
class UObject;
struct FGameplayTag;
struct FJMObjectiveFlowRuntimeState;
struct FJMObjectiveFlowSaveData;
struct FJMObjectiveRuntimeState;

// ********** Begin Class UJMObjectiveBlueprintLibrary *********************************************
#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Blueprint_JMObjectiveBlueprintLibrary_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRestoreObjectiveFlowStates); \
	DECLARE_FUNCTION(execCaptureObjectiveFlowStates); \
	DECLARE_FUNCTION(execGetObjectiveFlowState); \
	DECLARE_FUNCTION(execRestartObjectiveFlow); \
	DECLARE_FUNCTION(execResetObjectiveFlow); \
	DECLARE_FUNCTION(execStopObjectiveFlow); \
	DECLARE_FUNCTION(execStartObjectiveFlow); \
	DECLARE_FUNCTION(execGetObjectiveFlowSubsystem); \
	DECLARE_FUNCTION(execIsObjectiveCompleted); \
	DECLARE_FUNCTION(execGetObjectiveState); \
	DECLARE_FUNCTION(execAddObjectiveProgress); \
	DECLARE_FUNCTION(execResetObjective); \
	DECLARE_FUNCTION(execFailObjective); \
	DECLARE_FUNCTION(execCompleteObjective); \
	DECLARE_FUNCTION(execActivateObjective); \
	DECLARE_FUNCTION(execRegisterObjective); \
	DECLARE_FUNCTION(execGetObjectiveSubsystem);


struct Z_Construct_UClass_UJMObjectiveBlueprintLibrary_Statics;
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveBlueprintLibrary_NoRegister();

#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Blueprint_JMObjectiveBlueprintLibrary_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMObjectiveBlueprintLibrary(); \
	friend struct ::Z_Construct_UClass_UJMObjectiveBlueprintLibrary_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMOBJECTIVE_API UClass* ::Z_Construct_UClass_UJMObjectiveBlueprintLibrary_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMObjectiveBlueprintLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/JMObjective"), Z_Construct_UClass_UJMObjectiveBlueprintLibrary_NoRegister) \
	DECLARE_SERIALIZER(UJMObjectiveBlueprintLibrary)


#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Blueprint_JMObjectiveBlueprintLibrary_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMObjectiveBlueprintLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMObjectiveBlueprintLibrary(UJMObjectiveBlueprintLibrary&&) = delete; \
	UJMObjectiveBlueprintLibrary(const UJMObjectiveBlueprintLibrary&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMObjectiveBlueprintLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMObjectiveBlueprintLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMObjectiveBlueprintLibrary) \
	NO_API virtual ~UJMObjectiveBlueprintLibrary();


#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Blueprint_JMObjectiveBlueprintLibrary_h_14_PROLOG
#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Blueprint_JMObjectiveBlueprintLibrary_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Blueprint_JMObjectiveBlueprintLibrary_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Blueprint_JMObjectiveBlueprintLibrary_h_17_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Blueprint_JMObjectiveBlueprintLibrary_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMObjectiveBlueprintLibrary;

// ********** End Class UJMObjectiveBlueprintLibrary ***********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Blueprint_JMObjectiveBlueprintLibrary_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
