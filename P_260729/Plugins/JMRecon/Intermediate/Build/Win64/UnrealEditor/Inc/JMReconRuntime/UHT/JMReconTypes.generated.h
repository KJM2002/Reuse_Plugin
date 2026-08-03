// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Types/JMReconTypes.h"

#ifdef JMRECONRUNTIME_JMReconTypes_generated_h
#error "JMReconTypes.generated.h already included, missing '#pragma once' in JMReconTypes.h"
#endif
#define JMRECONRUNTIME_JMReconTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FJMReconRequestResult *********************************************
struct Z_Construct_UScriptStruct_FJMReconRequestResult_Statics;
#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Types_JMReconTypes_h_70_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMReconRequestResult_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMReconRequestResult;
// ********** End ScriptStruct FJMReconRequestResult ***********************************************

// ********** Begin ScriptStruct FJMReconSession ***************************************************
struct Z_Construct_UScriptStruct_FJMReconSession_Statics;
#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Types_JMReconTypes_h_96_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMReconSession_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMReconSession;
// ********** End ScriptStruct FJMReconSession *****************************************************

// ********** Begin ScriptStruct FJMReconNoiseEvent ************************************************
struct Z_Construct_UScriptStruct_FJMReconNoiseEvent_Statics;
#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Types_JMReconTypes_h_121_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMReconNoiseEvent_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMReconNoiseEvent;
// ********** End ScriptStruct FJMReconNoiseEvent **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Types_JMReconTypes_h

// ********** Begin Enum EJMReconState *************************************************************
#define FOREACH_ENUM_EJMRECONSTATE(op) \
	op(EJMReconState::Idle) \
	op(EJMReconState::Entering) \
	op(EJMReconState::Listening) \
	op(EJMReconState::Peeking) \
	op(EJMReconState::Exiting) 

enum class EJMReconState : uint8;
template<> struct TIsUEnumClass<EJMReconState> { enum { Value = true }; };
template<> JMRECONRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMReconState>();
// ********** End Enum EJMReconState ***************************************************************

// ********** Begin Enum EJMReconInitialObservationMode ********************************************
#define FOREACH_ENUM_EJMRECONINITIALOBSERVATIONMODE(op) \
	op(EJMReconInitialObservationMode::Listen) \
	op(EJMReconInitialObservationMode::Peek) 

enum class EJMReconInitialObservationMode : uint8;
template<> struct TIsUEnumClass<EJMReconInitialObservationMode> { enum { Value = true }; };
template<> JMRECONRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMReconInitialObservationMode>();
// ********** End Enum EJMReconInitialObservationMode **********************************************

// ********** Begin Enum EJMReconMode **************************************************************
#define FOREACH_ENUM_EJMRECONMODE(op) \
	op(EJMReconMode::None) \
	op(EJMReconMode::Listen) \
	op(EJMReconMode::Peek) \
	op(EJMReconMode::Illuminate) 

enum class EJMReconMode : uint8;
template<> struct TIsUEnumClass<EJMReconMode> { enum { Value = true }; };
template<> JMRECONRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMReconMode>();
// ********** End Enum EJMReconMode ****************************************************************

// ********** Begin Enum EJMReconFailureReason *****************************************************
#define FOREACH_ENUM_EJMRECONFAILUREREASON(op) \
	op(EJMReconFailureReason::None) \
	op(EJMReconFailureReason::AlreadyActive) \
	op(EJMReconFailureReason::AlreadyInUse) \
	op(EJMReconFailureReason::InvalidInteractor) \
	op(EJMReconFailureReason::InvalidTarget) \
	op(EJMReconFailureReason::TargetDestroyed) \
	op(EJMReconFailureReason::Disabled) \
	op(EJMReconFailureReason::OutOfRange) \
	op(EJMReconFailureReason::DoorOpen) \
	op(EJMReconFailureReason::DoorMoving) \
	op(EJMReconFailureReason::Blocked) \
	op(EJMReconFailureReason::NotSupported) \
	op(EJMReconFailureReason::InvalidState) \
	op(EJMReconFailureReason::DefinitionInvalid) 

enum class EJMReconFailureReason : uint8;
template<> struct TIsUEnumClass<EJMReconFailureReason> { enum { Value = true }; };
template<> JMRECONRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMReconFailureReason>();
// ********** End Enum EJMReconFailureReason *******************************************************

// ********** Begin Enum EJMReconEndReason *********************************************************
#define FOREACH_ENUM_EJMRECONENDREASON(op) \
	op(EJMReconEndReason::Completed) \
	op(EJMReconEndReason::Cancelled) \
	op(EJMReconEndReason::TargetDestroyed) \
	op(EJMReconEndReason::InteractorDestroyed) \
	op(EJMReconEndReason::TargetInvalidated) \
	op(EJMReconEndReason::EndPlay) 

enum class EJMReconEndReason : uint8;
template<> struct TIsUEnumClass<EJMReconEndReason> { enum { Value = true }; };
template<> JMRECONRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMReconEndReason>();
// ********** End Enum EJMReconEndReason ***********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
