// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Types/JMObjectiveTypes.h"

#ifdef JMOBJECTIVE_JMObjectiveTypes_generated_h
#error "JMObjectiveTypes.generated.h already included, missing '#pragma once' in JMObjectiveTypes.h"
#endif
#define JMOBJECTIVE_JMObjectiveTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGameplayTag;
struct FJMObjectiveRuntimeState;

// ********** Begin ScriptStruct FJMObjectiveRuntimeState ******************************************
struct Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics;
#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Types_JMObjectiveTypes_h_28_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMObjectiveRuntimeState_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMObjectiveRuntimeState;
// ********** End ScriptStruct FJMObjectiveRuntimeState ********************************************

// ********** Begin ScriptStruct FJMObjectiveSaveData **********************************************
struct Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics;
#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Types_JMObjectiveTypes_h_64_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMObjectiveSaveData_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMObjectiveSaveData;
// ********** End ScriptStruct FJMObjectiveSaveData ************************************************

// ********** Begin Delegate FJMObjectiveStateChangedSignature *************************************
#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Types_JMObjectiveTypes_h_85_DELEGATE \
JMOBJECTIVE_API void FJMObjectiveStateChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMObjectiveStateChangedSignature, FGameplayTag ObjectiveId, FJMObjectiveRuntimeState const& RuntimeState);


// ********** End Delegate FJMObjectiveStateChangedSignature ***************************************

// ********** Begin Delegate FJMObjectiveProgressedSignature ***************************************
#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Types_JMObjectiveTypes_h_86_DELEGATE \
JMOBJECTIVE_API void FJMObjectiveProgressedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMObjectiveProgressedSignature, FGameplayTag ObjectiveId, FJMObjectiveRuntimeState const& RuntimeState, int32 ProgressDelta);


// ********** End Delegate FJMObjectiveProgressedSignature *****************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Types_JMObjectiveTypes_h

// ********** Begin Enum EJMObjectiveState *********************************************************
#define FOREACH_ENUM_EJMOBJECTIVESTATE(op) \
	op(EJMObjectiveState::Inactive) \
	op(EJMObjectiveState::Active) \
	op(EJMObjectiveState::Completed) \
	op(EJMObjectiveState::Failed) 

enum class EJMObjectiveState : uint8;
template<> struct TIsUEnumClass<EJMObjectiveState> { enum { Value = true }; };
template<> JMOBJECTIVE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMObjectiveState>();
// ********** End Enum EJMObjectiveState ***********************************************************

// ********** Begin Enum EJMObjectiveProgressIncrementMode *****************************************
#define FOREACH_ENUM_EJMOBJECTIVEPROGRESSINCREMENTMODE(op) \
	op(EJMObjectiveProgressIncrementMode::FixedAmount) \
	op(EJMObjectiveProgressIncrementMode::PayloadAmount) 

enum class EJMObjectiveProgressIncrementMode : uint8;
template<> struct TIsUEnumClass<EJMObjectiveProgressIncrementMode> { enum { Value = true }; };
template<> JMOBJECTIVE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMObjectiveProgressIncrementMode>();
// ********** End Enum EJMObjectiveProgressIncrementMode *******************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
