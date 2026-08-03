// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Types/JMInteractionTypes.h"

#ifdef JMINTERACTION_JMInteractionTypes_generated_h
#error "JMInteractionTypes.generated.h already included, missing '#pragma once' in JMInteractionTypes.h"
#endif
#define JMINTERACTION_JMInteractionTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FJMInteractionPromptStyle *****************************************
struct Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics;
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Types_JMInteractionTypes_h_59_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMInteractionPromptStyle_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMInteractionPromptStyle;
// ********** End ScriptStruct FJMInteractionPromptStyle *******************************************

// ********** Begin ScriptStruct FJMInteractionResult **********************************************
struct Z_Construct_UScriptStruct_FJMInteractionResult_Statics;
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Types_JMInteractionTypes_h_84_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMInteractionResult_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMInteractionResult;
// ********** End ScriptStruct FJMInteractionResult ************************************************

// ********** Begin ScriptStruct FJMInteractionContext *********************************************
struct Z_Construct_UScriptStruct_FJMInteractionContext_Statics;
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Types_JMInteractionTypes_h_102_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMInteractionContext_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMInteractionContext;
// ********** End ScriptStruct FJMInteractionContext ***********************************************

// ********** Begin ScriptStruct FJMInteractionPrompt **********************************************
struct Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics;
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Types_JMInteractionTypes_h_129_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMInteractionPrompt_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMInteractionPrompt;
// ********** End ScriptStruct FJMInteractionPrompt ************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Types_JMInteractionTypes_h

// ********** Begin Enum EJMInteractionState *******************************************************
#define FOREACH_ENUM_EJMINTERACTIONSTATE(op) \
	op(EJMInteractionState::Idle) \
	op(EJMInteractionState::Targeting) \
	op(EJMInteractionState::Interacting) \
	op(EJMInteractionState::Holding) \
	op(EJMInteractionState::Disabled) 

enum class EJMInteractionState : uint8;
template<> struct TIsUEnumClass<EJMInteractionState> { enum { Value = true }; };
template<> JMINTERACTION_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMInteractionState>();
// ********** End Enum EJMInteractionState *********************************************************

// ********** Begin Enum EJMInteractionResultCode **************************************************
#define FOREACH_ENUM_EJMINTERACTIONRESULTCODE(op) \
	op(EJMInteractionResultCode::Succeeded) \
	op(EJMInteractionResultCode::Failed) \
	op(EJMInteractionResultCode::Disabled) \
	op(EJMInteractionResultCode::NoTarget) \
	op(EJMInteractionResultCode::TargetInvalid) \
	op(EJMInteractionResultCode::NotAllowed) \
	op(EJMInteractionResultCode::AlreadyInteracting) 

enum class EJMInteractionResultCode : uint8;
template<> struct TIsUEnumClass<EJMInteractionResultCode> { enum { Value = true }; };
template<> JMINTERACTION_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMInteractionResultCode>();
// ********** End Enum EJMInteractionResultCode ****************************************************

// ********** Begin Enum EJMInteractionDetectionMode ***********************************************
#define FOREACH_ENUM_EJMINTERACTIONDETECTIONMODE(op) \
	op(EJMInteractionDetectionMode::CenterScreenTrace) \
	op(EJMInteractionDetectionMode::MouseCursorTrace) 

enum class EJMInteractionDetectionMode : uint8;
template<> struct TIsUEnumClass<EJMInteractionDetectionMode> { enum { Value = true }; };
template<> JMINTERACTION_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMInteractionDetectionMode>();
// ********** End Enum EJMInteractionDetectionMode *************************************************

// ********** Begin Enum EJMInteractionTraceMode ***************************************************
#define FOREACH_ENUM_EJMINTERACTIONTRACEMODE(op) \
	op(EJMInteractionTraceMode::Manual) \
	op(EJMInteractionTraceMode::OnInput) \
	op(EJMInteractionTraceMode::Timer) \
	op(EJMInteractionTraceMode::Tick) 

enum class EJMInteractionTraceMode : uint8;
template<> struct TIsUEnumClass<EJMInteractionTraceMode> { enum { Value = true }; };
template<> JMINTERACTION_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMInteractionTraceMode>();
// ********** End Enum EJMInteractionTraceMode *****************************************************

// ********** Begin Enum EJMInteractionPromptHiddenMode ********************************************
#define FOREACH_ENUM_EJMINTERACTIONPROMPTHIDDENMODE(op) \
	op(EJMInteractionPromptHiddenMode::Collapsed) \
	op(EJMInteractionPromptHiddenMode::Hidden) 

enum class EJMInteractionPromptHiddenMode : uint8;
template<> struct TIsUEnumClass<EJMInteractionPromptHiddenMode> { enum { Value = true }; };
template<> JMINTERACTION_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMInteractionPromptHiddenMode>();
// ********** End Enum EJMInteractionPromptHiddenMode **********************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
