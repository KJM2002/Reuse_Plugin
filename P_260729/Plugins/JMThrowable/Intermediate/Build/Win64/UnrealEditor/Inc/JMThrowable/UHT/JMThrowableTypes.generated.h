// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "JMThrowableTypes.h"

#ifdef JMTHROWABLE_JMThrowableTypes_generated_h
#error "JMThrowableTypes.generated.h already included, missing '#pragma once' in JMThrowableTypes.h"
#endif
#define JMTHROWABLE_JMThrowableTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EJMThrowableUseState : uint8;
struct FJMThrowResult;

// ********** Begin ScriptStruct FJMThrowParameters ************************************************
struct Z_Construct_UScriptStruct_FJMThrowParameters_Statics;
#define FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableTypes_h_54_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMThrowParameters_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMThrowParameters;
// ********** End ScriptStruct FJMThrowParameters **************************************************

// ********** Begin ScriptStruct FJMThrowSimulationState *******************************************
struct Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics;
#define FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableTypes_h_84_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMThrowSimulationState_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMThrowSimulationState;
// ********** End ScriptStruct FJMThrowSimulationState *********************************************

// ********** Begin ScriptStruct FJMThrowSimulationResult ******************************************
struct Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics;
#define FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableTypes_h_96_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMThrowSimulationResult_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMThrowSimulationResult;
// ********** End ScriptStruct FJMThrowSimulationResult ********************************************

// ********** Begin ScriptStruct FJMThrowableUseContext ********************************************
struct Z_Construct_UScriptStruct_FJMThrowableUseContext_Statics;
#define FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableTypes_h_109_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMThrowableUseContext_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMThrowableUseContext;
// ********** End ScriptStruct FJMThrowableUseContext **********************************************

// ********** Begin ScriptStruct FJMThrowResult ****************************************************
struct Z_Construct_UScriptStruct_FJMThrowResult_Statics;
#define FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableTypes_h_119_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMThrowResult_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMThrowResult;
// ********** End ScriptStruct FJMThrowResult ******************************************************

// ********** Begin Delegate FJMThrowableStateChanged **********************************************
#define FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableTypes_h_128_DELEGATE \
JMTHROWABLE_API void FJMThrowableStateChanged_DelegateWrapper(const FMulticastScriptDelegate& JMThrowableStateChanged, EJMThrowableUseState NewState);


// ********** End Delegate FJMThrowableStateChanged ************************************************

// ********** Begin Delegate FJMThrowableThrowCompleted ********************************************
#define FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableTypes_h_129_DELEGATE \
JMTHROWABLE_API void FJMThrowableThrowCompleted_DelegateWrapper(const FMulticastScriptDelegate& JMThrowableThrowCompleted, FJMThrowResult const& Result);


// ********** End Delegate FJMThrowableThrowCompleted **********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableTypes_h

// ********** Begin Enum EJMThrowableUseState ******************************************************
#define FOREACH_ENUM_EJMTHROWABLEUSESTATE(op) \
	op(EJMThrowableUseState::Idle) \
	op(EJMThrowableUseState::Ready) \
	op(EJMThrowableUseState::Aiming) \
	op(EJMThrowableUseState::CommittingThrow) 

enum class EJMThrowableUseState : uint8;
template<> struct TIsUEnumClass<EJMThrowableUseState> { enum { Value = true }; };
template<> JMTHROWABLE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMThrowableUseState>();
// ********** End Enum EJMThrowableUseState ********************************************************

// ********** Begin Enum EJMThrowablePreviewRendererMode *******************************************
#define FOREACH_ENUM_EJMTHROWABLEPREVIEWRENDERERMODE(op) \
	op(EJMThrowablePreviewRendererMode::NiagaraPreferred) \
	op(EJMThrowablePreviewRendererMode::ProceduralOnly) 

enum class EJMThrowablePreviewRendererMode : uint8;
template<> struct TIsUEnumClass<EJMThrowablePreviewRendererMode> { enum { Value = true }; };
template<> JMTHROWABLE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMThrowablePreviewRendererMode>();
// ********** End Enum EJMThrowablePreviewRendererMode *********************************************

// ********** Begin Enum EJMThrowableProjectileState ***********************************************
#define FOREACH_ENUM_EJMTHROWABLEPROJECTILESTATE(op) \
	op(EJMThrowableProjectileState::Inactive) \
	op(EJMThrowableProjectileState::Flying) \
	op(EJMThrowableProjectileState::Resting) \
	op(EJMThrowableProjectileState::Fuse) \
	op(EJMThrowableProjectileState::Activated) \
	op(EJMThrowableProjectileState::Finished) 

enum class EJMThrowableProjectileState : uint8;
template<> struct TIsUEnumClass<EJMThrowableProjectileState> { enum { Value = true }; };
template<> JMTHROWABLE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMThrowableProjectileState>();
// ********** End Enum EJMThrowableProjectileState *************************************************

// ********** Begin Enum EJMThrowableSurfaceType ***************************************************
#define FOREACH_ENUM_EJMTHROWABLESURFACETYPE(op) \
	op(EJMThrowableSurfaceType::Floor) \
	op(EJMThrowableSurfaceType::Wall) \
	op(EJMThrowableSurfaceType::Slope) \
	op(EJMThrowableSurfaceType::Ceiling) 

enum class EJMThrowableSurfaceType : uint8;
template<> struct TIsUEnumClass<EJMThrowableSurfaceType> { enum { Value = true }; };
template<> JMTHROWABLE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMThrowableSurfaceType>();
// ********** End Enum EJMThrowableSurfaceType *****************************************************

// ********** Begin Enum EJMThrowResultCode ********************************************************
#define FOREACH_ENUM_EJMTHROWRESULTCODE(op) \
	op(EJMThrowResultCode::Success) \
	op(EJMThrowResultCode::InvalidState) \
	op(EJMThrowResultCode::NoActiveItem) \
	op(EJMThrowResultCode::ItemNoLongerExists) \
	op(EJMThrowResultCode::InvalidDefinition) \
	op(EJMThrowResultCode::NoLocalView) \
	op(EJMThrowResultCode::InvalidThrowOrigin) \
	op(EJMThrowResultCode::BlockedSpawn) \
	op(EJMThrowResultCode::ProjectileSpawnFailed) \
	op(EJMThrowResultCode::InventoryConsumeFailed) \
	op(EJMThrowResultCode::DuplicateCommit) 

enum class EJMThrowResultCode : uint8;
template<> struct TIsUEnumClass<EJMThrowResultCode> { enum { Value = true }; };
template<> JMTHROWABLE_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMThrowResultCode>();
// ********** End Enum EJMThrowResultCode **********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
