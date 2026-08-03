// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/JMReconInteractorComponent.h"

#ifdef JMRECONRUNTIME_JMReconInteractorComponent_generated_h
#error "JMReconInteractorComponent.generated.h already included, missing '#pragma once' in JMReconInteractorComponent.h"
#endif
#define JMRECONRUNTIME_JMReconInteractorComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UJMReconTargetComponent;
enum class EJMReconEndReason : uint8;
enum class EJMReconFailureReason : uint8;
enum class EJMReconState : uint8;
struct FGuid;
struct FJMReconNoiseEvent;
struct FJMReconRequestResult;

// ********** Begin Delegate FJMReconStateChangedSignature *****************************************
#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconInteractorComponent_h_12_DELEGATE \
JMRECONRUNTIME_API void FJMReconStateChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMReconStateChangedSignature, EJMReconState OldState, EJMReconState NewState);


// ********** End Delegate FJMReconStateChangedSignature *******************************************

// ********** Begin Delegate FJMReconSessionStartedSignature ***************************************
#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconInteractorComponent_h_13_DELEGATE \
JMRECONRUNTIME_API void FJMReconSessionStartedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMReconSessionStartedSignature, FGuid SessionId, UJMReconTargetComponent* Target);


// ********** End Delegate FJMReconSessionStartedSignature *****************************************

// ********** Begin Delegate FJMReconSessionEndedSignature *****************************************
#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconInteractorComponent_h_14_DELEGATE \
JMRECONRUNTIME_API void FJMReconSessionEndedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMReconSessionEndedSignature, FGuid SessionId, EJMReconEndReason Reason);


// ********** End Delegate FJMReconSessionEndedSignature *******************************************

// ********** Begin Delegate FJMReconIlluminateRequestedSignature **********************************
#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconInteractorComponent_h_15_DELEGATE \
JMRECONRUNTIME_API void FJMReconIlluminateRequestedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMReconIlluminateRequestedSignature, bool bEnabled);


// ********** End Delegate FJMReconIlluminateRequestedSignature ************************************

// ********** Begin Delegate FJMReconNoiseGeneratedSignature ***************************************
#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconInteractorComponent_h_16_DELEGATE \
JMRECONRUNTIME_API void FJMReconNoiseGeneratedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMReconNoiseGeneratedSignature, FJMReconNoiseEvent const& Noise);


// ********** End Delegate FJMReconNoiseGeneratedSignature *****************************************

// ********** Begin Delegate FJMReconCameraRequestedSignature **************************************
#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconInteractorComponent_h_17_DELEGATE \
JMRECONRUNTIME_API void FJMReconCameraRequestedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMReconCameraRequestedSignature, FTransform const& WorldTransform, EJMReconState State, float BlendTime);


// ********** End Delegate FJMReconCameraRequestedSignature ****************************************

// ********** Begin Delegate FJMReconCameraRestoreRequestedSignature *******************************
#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconInteractorComponent_h_18_DELEGATE \
JMRECONRUNTIME_API void FJMReconCameraRestoreRequestedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMReconCameraRestoreRequestedSignature);


// ********** End Delegate FJMReconCameraRestoreRequestedSignature *********************************

// ********** Begin Class UJMReconInteractorComponent **********************************************
#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconInteractorComponent_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleTargetDestroyed); \
	DECLARE_FUNCTION(execGetDebugStatus); \
	DECLARE_FUNCTION(execGetLastFailureReason); \
	DECLARE_FUNCTION(execGetCurrentTarget); \
	DECLARE_FUNCTION(execIsIlluminating); \
	DECLARE_FUNCTION(execIsReconActive); \
	DECLARE_FUNCTION(execGetSessionId); \
	DECLARE_FUNCTION(execGetCurrentState); \
	DECLARE_FUNCTION(execFinishRecon); \
	DECLARE_FUNCTION(execCancelRecon); \
	DECLARE_FUNCTION(execSetIlluminate); \
	DECLARE_FUNCTION(execStopPeek); \
	DECLARE_FUNCTION(execStartPeek); \
	DECLARE_FUNCTION(execStopListen); \
	DECLARE_FUNCTION(execStartListen); \
	DECLARE_FUNCTION(execTryStartRecon);


struct Z_Construct_UClass_UJMReconInteractorComponent_Statics;
JMRECONRUNTIME_API UClass* Z_Construct_UClass_UJMReconInteractorComponent_NoRegister();

#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconInteractorComponent_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMReconInteractorComponent(); \
	friend struct ::Z_Construct_UClass_UJMReconInteractorComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMRECONRUNTIME_API UClass* ::Z_Construct_UClass_UJMReconInteractorComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMReconInteractorComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMReconRuntime"), Z_Construct_UClass_UJMReconInteractorComponent_NoRegister) \
	DECLARE_SERIALIZER(UJMReconInteractorComponent)


#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconInteractorComponent_h_23_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMReconInteractorComponent(UJMReconInteractorComponent&&) = delete; \
	UJMReconInteractorComponent(const UJMReconInteractorComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMReconInteractorComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMReconInteractorComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMReconInteractorComponent) \
	NO_API virtual ~UJMReconInteractorComponent();


#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconInteractorComponent_h_20_PROLOG
#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconInteractorComponent_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconInteractorComponent_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconInteractorComponent_h_23_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconInteractorComponent_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMReconInteractorComponent;

// ********** End Class UJMReconInteractorComponent ************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconInteractorComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
