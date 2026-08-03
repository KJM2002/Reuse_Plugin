// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Types/JMHideTypes.h"

#ifdef JMHIDERUNTIME_JMHideTypes_generated_h
#error "JMHideTypes.generated.h already included, missing '#pragma once' in JMHideTypes.h"
#endif
#define JMHIDERUNTIME_JMHideTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FJMHideResult *****************************************************
struct Z_Construct_UScriptStruct_FJMHideResult_Statics;
#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Types_JMHideTypes_h_98_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMHideResult_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMHideResult;
// ********** End ScriptStruct FJMHideResult *******************************************************

// ********** Begin ScriptStruct FJMHideConfigValues ***********************************************
struct Z_Construct_UScriptStruct_FJMHideConfigValues_Statics;
#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Types_JMHideTypes_h_116_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMHideConfigValues_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMHideConfigValues;
// ********** End ScriptStruct FJMHideConfigValues *************************************************

// ********** Begin ScriptStruct FJMHideConfigOverride *********************************************
struct Z_Construct_UScriptStruct_FJMHideConfigOverride_Statics;
#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Types_JMHideTypes_h_161_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMHideConfigOverride_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMHideConfigOverride;
// ********** End ScriptStruct FJMHideConfigOverride ***********************************************

// ********** Begin ScriptStruct FJMResolvedHideConfig *********************************************
struct Z_Construct_UScriptStruct_FJMResolvedHideConfig_Statics;
#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Types_JMHideTypes_h_173_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMResolvedHideConfig_Statics; \
	static class UScriptStruct* StaticStruct(); \
	typedef FJMHideConfigValues Super;


struct FJMResolvedHideConfig;
// ********** End ScriptStruct FJMResolvedHideConfig ***********************************************

// ********** Begin ScriptStruct FJMHideRequest ****************************************************
struct Z_Construct_UScriptStruct_FJMHideRequest_Statics;
#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Types_JMHideTypes_h_179_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMHideRequest_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMHideRequest;
// ********** End ScriptStruct FJMHideRequest ******************************************************

// ********** Begin ScriptStruct FJMHideOperationContext *******************************************
struct Z_Construct_UScriptStruct_FJMHideOperationContext_Statics;
#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Types_JMHideTypes_h_188_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMHideOperationContext_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMHideOperationContext;
// ********** End ScriptStruct FJMHideOperationContext *********************************************

// ********** Begin ScriptStruct FJMHideOperationCompletion ****************************************
struct Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics;
#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Types_JMHideTypes_h_212_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMHideOperationCompletion_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMHideOperationCompletion;
// ********** End ScriptStruct FJMHideOperationCompletion ******************************************

// ********** Begin ScriptStruct FJMHideParticipantSnapshot ****************************************
struct Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics;
#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Types_JMHideTypes_h_230_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMHideParticipantSnapshot_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMHideParticipantSnapshot;
// ********** End ScriptStruct FJMHideParticipantSnapshot ******************************************

// ********** Begin ScriptStruct FJMHideSession ****************************************************
struct Z_Construct_UScriptStruct_FJMHideSession_Statics;
#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Types_JMHideTypes_h_257_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMHideSession_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMHideSession;
// ********** End ScriptStruct FJMHideSession ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Types_JMHideTypes_h

// ********** Begin Enum EJMHidePhase **************************************************************
#define FOREACH_ENUM_EJMHIDEPHASE(op) \
	op(EJMHidePhase::None) \
	op(EJMHidePhase::Reserving) \
	op(EJMHidePhase::PreparingEnter) \
	op(EJMHidePhase::Opening) \
	op(EJMHidePhase::Entering) \
	op(EJMHidePhase::ClosingAfterEnter) \
	op(EJMHidePhase::Hidden) \
	op(EJMHidePhase::PreparingExit) \
	op(EJMHidePhase::OpeningForExit) \
	op(EJMHidePhase::Exiting) \
	op(EJMHidePhase::ClosingAfterExit) \
	op(EJMHidePhase::CleaningUp) \
	op(EJMHidePhase::Completed) \
	op(EJMHidePhase::Cancelled) \
	op(EJMHidePhase::Failed) 

enum class EJMHidePhase : uint8;
template<> struct TIsUEnumClass<EJMHidePhase> { enum { Value = true }; };
template<> JMHIDERUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMHidePhase>();
// ********** End Enum EJMHidePhase ****************************************************************

// ********** Begin Enum EJMHideSpotState **********************************************************
#define FOREACH_ENUM_EJMHIDESPOTSTATE(op) \
	op(EJMHideSpotState::Disabled) \
	op(EJMHideSpotState::Available) \
	op(EJMHideSpotState::Reserved) \
	op(EJMHideSpotState::Occupied) 

enum class EJMHideSpotState : uint8;
template<> struct TIsUEnumClass<EJMHideSpotState> { enum { Value = true }; };
template<> JMHIDERUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMHideSpotState>();
// ********** End Enum EJMHideSpotState ************************************************************

// ********** Begin Enum EJMHideSpotArchetype ******************************************************
#define FOREACH_ENUM_EJMHIDESPOTARCHETYPE(op) \
	op(EJMHideSpotArchetype::OpenSpace) \
	op(EJMHideSpotArchetype::Enclosed) \
	op(EJMHideSpotArchetype::Custom) 

enum class EJMHideSpotArchetype : uint8;
template<> struct TIsUEnumClass<EJMHideSpotArchetype> { enum { Value = true }; };
template<> JMHIDERUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMHideSpotArchetype>();
// ********** End Enum EJMHideSpotArchetype ********************************************************

// ********** Begin Enum EJMHideAnchorRole *********************************************************
#define FOREACH_ENUM_EJMHIDEANCHORROLE(op) \
	op(EJMHideAnchorRole::Entry) \
	op(EJMHideAnchorRole::Occupant) \
	op(EJMHideAnchorRole::Camera) \
	op(EJMHideAnchorRole::PrimaryExit) \
	op(EJMHideAnchorRole::AlternativeExit) \
	op(EJMHideAnchorRole::Investigation) 

enum class EJMHideAnchorRole : uint8;
template<> struct TIsUEnumClass<EJMHideAnchorRole> { enum { Value = true }; };
template<> JMHIDERUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMHideAnchorRole>();
// ********** End Enum EJMHideAnchorRole ***********************************************************

// ********** Begin Enum EJMHideOperation **********************************************************
#define FOREACH_ENUM_EJMHIDEOPERATION(op) \
	op(EJMHideOperation::None) \
	op(EJMHideOperation::PrepareEnter) \
	op(EJMHideOperation::Enter) \
	op(EJMHideOperation::CompleteEnter) \
	op(EJMHideOperation::PrepareExit) \
	op(EJMHideOperation::Exit) \
	op(EJMHideOperation::CompleteExit) \
	op(EJMHideOperation::Restore) 

enum class EJMHideOperation : uint8;
template<> struct TIsUEnumClass<EJMHideOperation> { enum { Value = true }; };
template<> JMHIDERUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMHideOperation>();
// ********** End Enum EJMHideOperation ************************************************************

// ********** Begin Enum EJMHideFailureCode ********************************************************
#define FOREACH_ENUM_EJMHIDEFAILURECODE(op) \
	op(EJMHideFailureCode::None) \
	op(EJMHideFailureCode::AlreadyActive) \
	op(EJMHideFailureCode::InvalidState) \
	op(EJMHideFailureCode::InvalidParticipant) \
	op(EJMHideFailureCode::UnsupportedParticipant) \
	op(EJMHideFailureCode::InvalidSpot) \
	op(EJMHideFailureCode::SpotDisabled) \
	op(EJMHideFailureCode::SpotUnavailable) \
	op(EJMHideFailureCode::MissingAnchor) \
	op(EJMHideFailureCode::MissingMechanism) \
	op(EJMHideFailureCode::InvalidMechanism) \
	op(EJMHideFailureCode::OperationRejected) \
	op(EJMHideFailureCode::OperationFailed) \
	op(EJMHideFailureCode::ExitBlocked) \
	op(EJMHideFailureCode::Cancelled) \
	op(EJMHideFailureCode::TargetDestroyed) 

enum class EJMHideFailureCode : uint8;
template<> struct TIsUEnumClass<EJMHideFailureCode> { enum { Value = true }; };
template<> JMHIDERUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMHideFailureCode>();
// ********** End Enum EJMHideFailureCode **********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
