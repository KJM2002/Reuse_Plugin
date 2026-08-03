// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Types/JMFootstepTypes.h"

#ifdef JMFOOTSTEPRUNTIME_JMFootstepTypes_generated_h
#error "JMFootstepTypes.generated.h already included, missing '#pragma once' in JMFootstepTypes.h"
#endif
#define JMFOOTSTEPRUNTIME_JMFootstepTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FJMFootstepContext ************************************************
struct Z_Construct_UScriptStruct_FJMFootstepContext_Statics;
#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Types_JMFootstepTypes_h_51_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMFootstepContext_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMFootstepContext;
// ********** End ScriptStruct FJMFootstepContext **************************************************

// ********** Begin ScriptStruct FJMFootstepResult *************************************************
struct Z_Construct_UScriptStruct_FJMFootstepResult_Statics;
#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Types_JMFootstepTypes_h_87_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMFootstepResult_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMFootstepResult;
// ********** End ScriptStruct FJMFootstepResult ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Types_JMFootstepTypes_h

// ********** Begin Enum EJMFootstepLocomotionState ************************************************
#define FOREACH_ENUM_EJMFOOTSTEPLOCOMOTIONSTATE(op) \
	op(EJMFootstepLocomotionState::Idle) \
	op(EJMFootstepLocomotionState::Walk) \
	op(EJMFootstepLocomotionState::Run) \
	op(EJMFootstepLocomotionState::CrouchWalk) 

enum class EJMFootstepLocomotionState : uint8;
template<> struct TIsUEnumClass<EJMFootstepLocomotionState> { enum { Value = true }; };
template<> JMFOOTSTEPRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMFootstepLocomotionState>();
// ********** End Enum EJMFootstepLocomotionState **************************************************

// ********** Begin Enum EJMFootstepFoot ***********************************************************
#define FOREACH_ENUM_EJMFOOTSTEPFOOT(op) \
	op(EJMFootstepFoot::Left) \
	op(EJMFootstepFoot::Right) 

enum class EJMFootstepFoot : uint8;
template<> struct TIsUEnumClass<EJMFootstepFoot> { enum { Value = true }; };
template<> JMFOOTSTEPRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMFootstepFoot>();
// ********** End Enum EJMFootstepFoot *************************************************************

// ********** Begin Enum EJMFootstepTriggerMode ****************************************************
#define FOREACH_ENUM_EJMFOOTSTEPTRIGGERMODE(op) \
	op(EJMFootstepTriggerMode::DistanceBased) \
	op(EJMFootstepTriggerMode::ManualOnly) 

enum class EJMFootstepTriggerMode : uint8;
template<> struct TIsUEnumClass<EJMFootstepTriggerMode> { enum { Value = true }; };
template<> JMFOOTSTEPRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMFootstepTriggerMode>();
// ********** End Enum EJMFootstepTriggerMode ******************************************************

// ********** Begin Enum EJMFootstepFailureReason **************************************************
#define FOREACH_ENUM_EJMFOOTSTEPFAILUREREASON(op) \
	op(EJMFootstepFailureReason::None) \
	op(EJMFootstepFailureReason::InvalidOwner) \
	op(EJMFootstepFailureReason::NotGrounded) \
	op(EJMFootstepFailureReason::NotMoving) \
	op(EJMFootstepFailureReason::TraceFailed) \
	op(EJMFootstepFailureReason::PhysicalMaterialMissing) \
	op(EJMFootstepFailureReason::SurfaceProfileMissing) \
	op(EJMFootstepFailureReason::SoundMissing) \
	op(EJMFootstepFailureReason::SettingsMissing) 

enum class EJMFootstepFailureReason : uint8;
template<> struct TIsUEnumClass<EJMFootstepFailureReason> { enum { Value = true }; };
template<> JMFOOTSTEPRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMFootstepFailureReason>();
// ********** End Enum EJMFootstepFailureReason ****************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
