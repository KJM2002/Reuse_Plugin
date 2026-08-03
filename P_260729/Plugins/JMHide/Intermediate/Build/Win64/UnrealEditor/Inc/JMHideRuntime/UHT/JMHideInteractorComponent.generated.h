// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/JMHideInteractorComponent.h"

#ifdef JMHIDERUNTIME_JMHideInteractorComponent_generated_h
#error "JMHideInteractorComponent.generated.h already included, missing '#pragma once' in JMHideInteractorComponent.h"
#endif
#define JMHIDERUNTIME_JMHideInteractorComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UJMHideSpotComponent;
enum class EJMHideFailureCode : uint8;
enum class EJMHidePhase : uint8;
struct FGuid;
struct FJMHideRequest;
struct FJMHideResult;

// ********** Begin Delegate FJMHidePhaseChangedSignature ******************************************
#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideInteractorComponent_h_12_DELEGATE \
JMHIDERUNTIME_API void FJMHidePhaseChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMHidePhaseChangedSignature, FGuid SessionId, EJMHidePhase OldPhase, EJMHidePhase NewPhase);


// ********** End Delegate FJMHidePhaseChangedSignature ********************************************

// ********** Begin Delegate FJMHideSessionEventSignature ******************************************
#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideInteractorComponent_h_13_DELEGATE \
JMHIDERUNTIME_API void FJMHideSessionEventSignature_DelegateWrapper(const FMulticastScriptDelegate& JMHideSessionEventSignature, FGuid SessionId, UJMHideSpotComponent* HideSpot);


// ********** End Delegate FJMHideSessionEventSignature ********************************************

// ********** Begin Delegate FJMHideExitPromptChangedSignature *************************************
#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideInteractorComponent_h_14_DELEGATE \
JMHIDERUNTIME_API void FJMHideExitPromptChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMHideExitPromptChangedSignature, const FText& Prompt);


// ********** End Delegate FJMHideExitPromptChangedSignature ***************************************

// ********** Begin Delegate FJMHideFailedSignature ************************************************
#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideInteractorComponent_h_15_DELEGATE \
JMHIDERUNTIME_API void FJMHideFailedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMHideFailedSignature, FGuid SessionId, EJMHideFailureCode Failure);


// ********** End Delegate FJMHideFailedSignature **************************************************

// ********** Begin Class UJMHideInteractorComponent ***********************************************
#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideInteractorComponent_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetCurrentHideSpot); \
	DECLARE_FUNCTION(execGetCurrentSessionId); \
	DECLARE_FUNCTION(execGetCurrentPhase); \
	DECLARE_FUNCTION(execHasActiveSession); \
	DECLARE_FUNCTION(execIsHidden); \
	DECLARE_FUNCTION(execForceExit); \
	DECLARE_FUNCTION(execCancelCurrentTransition); \
	DECLARE_FUNCTION(execTryExitCurrentHideSpot); \
	DECLARE_FUNCTION(execTryEnterHideSpotWithRequest); \
	DECLARE_FUNCTION(execTryEnterHideSpot);


struct Z_Construct_UClass_UJMHideInteractorComponent_Statics;
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideInteractorComponent_NoRegister();

#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideInteractorComponent_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMHideInteractorComponent(); \
	friend struct ::Z_Construct_UClass_UJMHideInteractorComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMHIDERUNTIME_API UClass* ::Z_Construct_UClass_UJMHideInteractorComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMHideInteractorComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMHideRuntime"), Z_Construct_UClass_UJMHideInteractorComponent_NoRegister) \
	DECLARE_SERIALIZER(UJMHideInteractorComponent)


#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideInteractorComponent_h_20_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMHideInteractorComponent(UJMHideInteractorComponent&&) = delete; \
	UJMHideInteractorComponent(const UJMHideInteractorComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMHideInteractorComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMHideInteractorComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMHideInteractorComponent) \
	NO_API virtual ~UJMHideInteractorComponent();


#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideInteractorComponent_h_17_PROLOG
#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideInteractorComponent_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideInteractorComponent_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideInteractorComponent_h_20_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideInteractorComponent_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMHideInteractorComponent;

// ********** End Class UJMHideInteractorComponent *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideInteractorComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
