// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Types/JMJumpScareTypes.h"

#ifdef JMJUMPSCARE_JMJumpScareTypes_generated_h
#error "JMJumpScareTypes.generated.h already included, missing '#pragma once' in JMJumpScareTypes.h"
#endif
#define JMJUMPSCARE_JMJumpScareTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FJMJumpScarePlayContext *******************************************
struct Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics;
#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Types_JMJumpScareTypes_h_109_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMJumpScarePlayContext_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMJumpScarePlayContext;
// ********** End ScriptStruct FJMJumpScarePlayContext *********************************************

// ********** Begin ScriptStruct FJMJumpScareActiveInfo ********************************************
struct Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics;
#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Types_JMJumpScareTypes_h_149_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMJumpScareActiveInfo_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMJumpScareActiveInfo;
// ********** End ScriptStruct FJMJumpScareActiveInfo **********************************************

// ********** Begin ScriptStruct FJMJumpScareAudioEvent ********************************************
struct Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics;
#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Types_JMJumpScareTypes_h_170_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMJumpScareAudioEvent_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMJumpScareAudioEvent;
// ********** End ScriptStruct FJMJumpScareAudioEvent **********************************************

// ********** Begin ScriptStruct FJMJumpScareTriggerSaveState **************************************
struct Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState_Statics;
#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Types_JMJumpScareTypes_h_191_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMJumpScareTriggerSaveState_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMJumpScareTriggerSaveState;
// ********** End ScriptStruct FJMJumpScareTriggerSaveState ****************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Types_JMJumpScareTypes_h

// ********** Begin Enum EJMJumpScareSpawnMode *****************************************************
#define FOREACH_ENUM_EJMJUMPSCARESPAWNMODE(op) \
	op(EJMJumpScareSpawnMode::WorldAnchor) \
	op(EJMJumpScareSpawnMode::CameraRelative) 

enum class EJMJumpScareSpawnMode : uint8;
template<> struct TIsUEnumClass<EJMJumpScareSpawnMode> { enum { Value = true }; };
template<> JMJUMPSCARE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMJumpScareSpawnMode>();
// ********** End Enum EJMJumpScareSpawnMode *******************************************************

// ********** Begin Enum EJMJumpScarePresentationMode **********************************************
#define FOREACH_ENUM_EJMJUMPSCAREPRESENTATIONMODE(op) \
	op(EJMJumpScarePresentationMode::UseLegacySpawnMode) \
	op(EJMJumpScarePresentationMode::WorldActor) \
	op(EJMJumpScarePresentationMode::CameraRelative) \
	op(EJMJumpScarePresentationMode::CameraAttached) \
	op(EJMJumpScarePresentationMode::ForcedLookAt) 

enum class EJMJumpScarePresentationMode : uint8;
template<> struct TIsUEnumClass<EJMJumpScarePresentationMode> { enum { Value = true }; };
template<> JMJUMPSCARE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMJumpScarePresentationMode>();
// ********** End Enum EJMJumpScarePresentationMode ************************************************

// ********** Begin Enum EJMJumpScarePhase *********************************************************
#define FOREACH_ENUM_EJMJUMPSCAREPHASE(op) \
	op(EJMJumpScarePhase::Idle) \
	op(EJMJumpScarePhase::Preparing) \
	op(EJMJumpScarePhase::Entering) \
	op(EJMJumpScarePhase::Impact) \
	op(EJMJumpScarePhase::Holding) \
	op(EJMJumpScarePhase::Exiting) \
	op(EJMJumpScarePhase::Finishing) 

enum class EJMJumpScarePhase : uint8;
template<> struct TIsUEnumClass<EJMJumpScarePhase> { enum { Value = true }; };
template<> JMJUMPSCARE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMJumpScarePhase>();
// ********** End Enum EJMJumpScarePhase ***********************************************************

// ********** Begin Enum EJMJumpScareCameraControlMode *********************************************
#define FOREACH_ENUM_EJMJUMPSCARECAMERACONTROLMODE(op) \
	op(EJMJumpScareCameraControlMode::None) \
	op(EJMJumpScareCameraControlMode::LockCurrentView) \
	op(EJMJumpScareCameraControlMode::LookAtActor) \
	op(EJMJumpScareCameraControlMode::LookAtFocusPoint) 

enum class EJMJumpScareCameraControlMode : uint8;
template<> struct TIsUEnumClass<EJMJumpScareCameraControlMode> { enum { Value = true }; };
template<> JMJUMPSCARE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMJumpScareCameraControlMode>();
// ********** End Enum EJMJumpScareCameraControlMode ***********************************************

// ********** Begin Enum EJMJumpScareVanishMode ****************************************************
#define FOREACH_ENUM_EJMJUMPSCAREVANISHMODE(op) \
	op(EJMJumpScareVanishMode::None) \
	op(EJMJumpScareVanishMode::InstantHide) \
	op(EJMJumpScareVanishMode::InterfaceDriven) 

enum class EJMJumpScareVanishMode : uint8;
template<> struct TIsUEnumClass<EJMJumpScareVanishMode> { enum { Value = true }; };
template<> JMJUMPSCARE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMJumpScareVanishMode>();
// ********** End Enum EJMJumpScareVanishMode ******************************************************

// ********** Begin Enum EJMJumpScareTriggerPolicy *************************************************
#define FOREACH_ENUM_EJMJUMPSCARETRIGGERPOLICY(op) \
	op(EJMJumpScareTriggerPolicy::Once) \
	op(EJMJumpScareTriggerPolicy::Repeatable) 

enum class EJMJumpScareTriggerPolicy : uint8;
template<> struct TIsUEnumClass<EJMJumpScareTriggerPolicy> { enum { Value = true }; };
template<> JMJUMPSCARE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMJumpScareTriggerPolicy>();
// ********** End Enum EJMJumpScareTriggerPolicy ***************************************************

// ********** Begin Enum EJMJumpScareConcurrentPolicy **********************************************
#define FOREACH_ENUM_EJMJUMPSCARECONCURRENTPOLICY(op) \
	op(EJMJumpScareConcurrentPolicy::IgnoreNew) 

enum class EJMJumpScareConcurrentPolicy : uint8;
template<> struct TIsUEnumClass<EJMJumpScareConcurrentPolicy> { enum { Value = true }; };
template<> JMJUMPSCARE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMJumpScareConcurrentPolicy>();
// ********** End Enum EJMJumpScareConcurrentPolicy ************************************************

// ********** Begin Enum EJMJumpScareOverlapFilter *************************************************
#define FOREACH_ENUM_EJMJUMPSCAREOVERLAPFILTER(op) \
	op(EJMJumpScareOverlapFilter::PlayerControlledPawn) \
	op(EJMJumpScareOverlapFilter::AnyPawn) \
	op(EJMJumpScareOverlapFilter::GameplayTags) 

enum class EJMJumpScareOverlapFilter : uint8;
template<> struct TIsUEnumClass<EJMJumpScareOverlapFilter> { enum { Value = true }; };
template<> JMJUMPSCARE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMJumpScareOverlapFilter>();
// ********** End Enum EJMJumpScareOverlapFilter ***************************************************

// ********** Begin Enum EJMJumpScareState *********************************************************
#define FOREACH_ENUM_EJMJUMPSCARESTATE(op) \
	op(EJMJumpScareState::Idle) \
	op(EJMJumpScareState::Waiting) \
	op(EJMJumpScareState::Playing) \
	op(EJMJumpScareState::Finishing) 

enum class EJMJumpScareState : uint8;
template<> struct TIsUEnumClass<EJMJumpScareState> { enum { Value = true }; };
template<> JMJUMPSCARE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMJumpScareState>();
// ********** End Enum EJMJumpScareState ***********************************************************

// ********** Begin Enum EJMJumpScarePlayResult ****************************************************
#define FOREACH_ENUM_EJMJUMPSCAREPLAYRESULT(op) \
	op(EJMJumpScarePlayResult::Started) \
	op(EJMJumpScarePlayResult::AlreadyPlaying) \
	op(EJMJumpScarePlayResult::AlreadyTriggered) \
	op(EJMJumpScarePlayResult::InvalidWorld) \
	op(EJMJumpScarePlayResult::InvalidDefinition) \
	op(EJMJumpScarePlayResult::MissingImage) \
	op(EJMJumpScarePlayResult::InvalidActorClass) \
	op(EJMJumpScarePlayResult::MissingAnchor) \
	op(EJMJumpScarePlayResult::MissingTargetPlayer) \
	op(EJMJumpScarePlayResult::MissingCamera) \
	op(EJMJumpScarePlayResult::SpawnFailed) 

enum class EJMJumpScarePlayResult : uint8;
template<> struct TIsUEnumClass<EJMJumpScarePlayResult> { enum { Value = true }; };
template<> JMJUMPSCARE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMJumpScarePlayResult>();
// ********** End Enum EJMJumpScarePlayResult ******************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
