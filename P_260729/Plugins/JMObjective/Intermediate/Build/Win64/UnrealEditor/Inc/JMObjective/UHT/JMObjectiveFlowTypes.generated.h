// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Types/JMObjectiveFlowTypes.h"

#ifdef JMOBJECTIVE_JMObjectiveFlowTypes_generated_h
#error "JMObjectiveFlowTypes.generated.h already included, missing '#pragma once' in JMObjectiveFlowTypes.h"
#endif
#define JMOBJECTIVE_JMObjectiveFlowTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGameplayTag;
struct FJMObjectiveFlowRuntimeState;

// ********** Begin ScriptStruct FJMObjectiveFlowRuntimeState **************************************
struct Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics;
#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Types_JMObjectiveFlowTypes_h_22_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMObjectiveFlowRuntimeState_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMObjectiveFlowRuntimeState;
// ********** End ScriptStruct FJMObjectiveFlowRuntimeState ****************************************

// ********** Begin ScriptStruct FJMObjectiveFlowSaveData ******************************************
struct Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics;
#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Types_JMObjectiveFlowTypes_h_52_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMObjectiveFlowSaveData_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMObjectiveFlowSaveData;
// ********** End ScriptStruct FJMObjectiveFlowSaveData ********************************************

// ********** Begin Delegate FJMObjectiveFlowStateChangedSignature *********************************
#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Types_JMObjectiveFlowTypes_h_82_DELEGATE \
JMOBJECTIVE_API void FJMObjectiveFlowStateChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMObjectiveFlowStateChangedSignature, FGameplayTag FlowId, FJMObjectiveFlowRuntimeState const& RuntimeState);


// ********** End Delegate FJMObjectiveFlowStateChangedSignature ***********************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Types_JMObjectiveFlowTypes_h

// ********** Begin Enum EJMObjectiveFlowState *****************************************************
#define FOREACH_ENUM_EJMOBJECTIVEFLOWSTATE(op) \
	op(EJMObjectiveFlowState::Inactive) \
	op(EJMObjectiveFlowState::Active) \
	op(EJMObjectiveFlowState::Completed) \
	op(EJMObjectiveFlowState::Failed) 

enum class EJMObjectiveFlowState : uint8;
template<> struct TIsUEnumClass<EJMObjectiveFlowState> { enum { Value = true }; };
template<> JMOBJECTIVE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMObjectiveFlowState>();
// ********** End Enum EJMObjectiveFlowState *******************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
