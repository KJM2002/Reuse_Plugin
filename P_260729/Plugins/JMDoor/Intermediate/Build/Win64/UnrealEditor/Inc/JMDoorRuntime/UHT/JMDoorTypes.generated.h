// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Door/JMDoorTypes.h"

#ifdef JMDOORRUNTIME_JMDoorTypes_generated_h
#error "JMDoorTypes.generated.h already included, missing '#pragma once' in JMDoorTypes.h"
#endif
#define JMDOORRUNTIME_JMDoorTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FJMDoorAccessRequirement ******************************************
struct Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics;
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorTypes_h_104_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMDoorAccessRequirement_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMDoorAccessRequirement;
// ********** End ScriptStruct FJMDoorAccessRequirement ********************************************

// ********** Begin ScriptStruct FJMDoorUseContext *************************************************
struct Z_Construct_UScriptStruct_FJMDoorUseContext_Statics;
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorTypes_h_125_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMDoorUseContext_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMDoorUseContext;
// ********** End ScriptStruct FJMDoorUseContext ***************************************************

// ********** Begin ScriptStruct FJMDoorResult *****************************************************
struct Z_Construct_UScriptStruct_FJMDoorResult_Statics;
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorTypes_h_163_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMDoorResult_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMDoorResult;
// ********** End ScriptStruct FJMDoorResult *******************************************************

// ********** Begin ScriptStruct FJMDoorNoiseEvent *************************************************
struct Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics;
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorTypes_h_181_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMDoorNoiseEvent_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMDoorNoiseEvent;
// ********** End ScriptStruct FJMDoorNoiseEvent ***************************************************

// ********** Begin ScriptStruct FJMDoorSaveData ***************************************************
struct Z_Construct_UScriptStruct_FJMDoorSaveData_Statics;
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorTypes_h_205_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMDoorSaveData_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMDoorSaveData;
// ********** End ScriptStruct FJMDoorSaveData *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorTypes_h

// ********** Begin Enum EJMDoorState **************************************************************
#define FOREACH_ENUM_EJMDOORSTATE(op) \
	op(EJMDoorState::Closed) \
	op(EJMDoorState::Opening) \
	op(EJMDoorState::Open) \
	op(EJMDoorState::Closing) \
	op(EJMDoorState::Locked) \
	op(EJMDoorState::Blocked) \
	op(EJMDoorState::Jammed) \
	op(EJMDoorState::Broken) 

enum class EJMDoorState : uint8;
template<> struct TIsUEnumClass<EJMDoorState> { enum { Value = true }; };
template<> JMDOORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMDoorState>();
// ********** End Enum EJMDoorState ****************************************************************

// ********** Begin Enum EJMDoorCommand ************************************************************
#define FOREACH_ENUM_EJMDOORCOMMAND(op) \
	op(EJMDoorCommand::Open) \
	op(EJMDoorCommand::Close) \
	op(EJMDoorCommand::Toggle) \
	op(EJMDoorCommand::Unlock) \
	op(EJMDoorCommand::Lock) \
	op(EJMDoorCommand::ForceOpen) 

enum class EJMDoorCommand : uint8;
template<> struct TIsUEnumClass<EJMDoorCommand> { enum { Value = true }; };
template<> JMDOORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMDoorCommand>();
// ********** End Enum EJMDoorCommand **************************************************************

// ********** Begin Enum EJMDoorResultCode *********************************************************
#define FOREACH_ENUM_EJMDOORRESULTCODE(op) \
	op(EJMDoorResultCode::Succeeded) \
	op(EJMDoorResultCode::InvalidRequest) \
	op(EJMDoorResultCode::Disabled) \
	op(EJMDoorResultCode::AccessDenied) \
	op(EJMDoorResultCode::Locked) \
	op(EJMDoorResultCode::AlreadyAtTarget) \
	op(EJMDoorResultCode::Moving) \
	op(EJMDoorResultCode::Blocked) \
	op(EJMDoorResultCode::Jammed) \
	op(EJMDoorResultCode::Broken) \
	op(EJMDoorResultCode::MissingMovementComponent) 

enum class EJMDoorResultCode : uint8;
template<> struct TIsUEnumClass<EJMDoorResultCode> { enum { Value = true }; };
template<> JMDOORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMDoorResultCode>();
// ********** End Enum EJMDoorResultCode ***********************************************************

// ********** Begin Enum EJMDoorOpenDirectionMode **************************************************
#define FOREACH_ENUM_EJMDOOROPENDIRECTIONMODE(op) \
	op(EJMDoorOpenDirectionMode::Positive) \
	op(EJMDoorOpenDirectionMode::Negative) \
	op(EJMDoorOpenDirectionMode::AwayFromInteractor) \
	op(EJMDoorOpenDirectionMode::TowardInteractor) 

enum class EJMDoorOpenDirectionMode : uint8;
template<> struct TIsUEnumClass<EJMDoorOpenDirectionMode> { enum { Value = true }; };
template<> JMDOORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMDoorOpenDirectionMode>();
// ********** End Enum EJMDoorOpenDirectionMode ****************************************************

// ********** Begin Enum EJMSlideDoorPanel *********************************************************
#define FOREACH_ENUM_EJMSLIDEDOORPANEL(op) \
	op(EJMSlideDoorPanel::DoorA) \
	op(EJMSlideDoorPanel::DoorB) \
	op(EJMSlideDoorPanel::Both) 

enum class EJMSlideDoorPanel : uint8;
template<> struct TIsUEnumClass<EJMSlideDoorPanel> { enum { Value = true }; };
template<> JMDOORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMSlideDoorPanel>();
// ********** End Enum EJMSlideDoorPanel ***********************************************************

// ********** Begin Enum EJMSlideDoorOpenMode ******************************************************
#define FOREACH_ENUM_EJMSLIDEDOOROPENMODE(op) \
	op(EJMSlideDoorOpenMode::OpenDoorA) \
	op(EJMSlideDoorOpenMode::OpenDoorB) \
	op(EJMSlideDoorOpenMode::OpenBoth) 

enum class EJMSlideDoorOpenMode : uint8;
template<> struct TIsUEnumClass<EJMSlideDoorOpenMode> { enum { Value = true }; };
template<> JMDOORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMSlideDoorOpenMode>();
// ********** End Enum EJMSlideDoorOpenMode ********************************************************

// ********** Begin Enum EJMSlideDoorPanelSelectionMode ********************************************
#define FOREACH_ENUM_EJMSLIDEDOORPANELSELECTIONMODE(op) \
	op(EJMSlideDoorPanelSelectionMode::ConfiguredPanel) \
	op(EJMSlideDoorPanelSelectionMode::NearestPanel) 

enum class EJMSlideDoorPanelSelectionMode : uint8;
template<> struct TIsUEnumClass<EJMSlideDoorPanelSelectionMode> { enum { Value = true }; };
template<> JMDOORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMSlideDoorPanelSelectionMode>();
// ********** End Enum EJMSlideDoorPanelSelectionMode **********************************************

// ********** Begin Enum EJMDoorBlockBehavior ******************************************************
#define FOREACH_ENUM_EJMDOORBLOCKBEHAVIOR(op) \
	op(EJMDoorBlockBehavior::Stop) \
	op(EJMDoorBlockBehavior::Reverse) \
	op(EJMDoorBlockBehavior::Retry) \
	op(EJMDoorBlockBehavior::Ignore) 

enum class EJMDoorBlockBehavior : uint8;
template<> struct TIsUEnumClass<EJMDoorBlockBehavior> { enum { Value = true }; };
template<> JMDOORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMDoorBlockBehavior>();
// ********** End Enum EJMDoorBlockBehavior ********************************************************

// ********** Begin Enum EJMDoorAccessMatchMode ****************************************************
#define FOREACH_ENUM_EJMDOORACCESSMATCHMODE(op) \
	op(EJMDoorAccessMatchMode::AllRequired) \
	op(EJMDoorAccessMatchMode::AnyRequired) 

enum class EJMDoorAccessMatchMode : uint8;
template<> struct TIsUEnumClass<EJMDoorAccessMatchMode> { enum { Value = true }; };
template<> JMDOORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMDoorAccessMatchMode>();
// ********** End Enum EJMDoorAccessMatchMode ******************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
