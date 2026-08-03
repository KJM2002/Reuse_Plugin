// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/JMReconPlayerBridgeComponent.h"

#ifdef JMRECONGAMEPLAYINTEGRATION_JMReconPlayerBridgeComponent_generated_h
#error "JMReconPlayerBridgeComponent.generated.h already included, missing '#pragma once' in JMReconPlayerBridgeComponent.h"
#endif
#define JMRECONGAMEPLAYINTEGRATION_JMReconPlayerBridgeComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UJMReconTargetComponent;
class UObject;
enum class EJMReconEndReason : uint8;
enum class EJMReconState : uint8;
struct FGuid;
struct FJMReconRequestResult;

// ********** Begin Delegate FJMReconFlashlightStateChangedSignature *******************************
#define FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Components_JMReconPlayerBridgeComponent_h_18_DELEGATE \
JMRECONGAMEPLAYINTEGRATION_API void FJMReconFlashlightStateChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMReconFlashlightStateChangedSignature, bool bEnabled);


// ********** End Delegate FJMReconFlashlightStateChangedSignature *********************************

// ********** Begin Class UJMReconPlayerBridgeComponent ********************************************
#define FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Components_JMReconPlayerBridgeComponent_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleIlluminateRequested); \
	DECLARE_FUNCTION(execHandleCameraRestoreRequested); \
	DECLARE_FUNCTION(execHandleCameraTransformRequested); \
	DECLARE_FUNCTION(execHandleSessionEnded); \
	DECLARE_FUNCTION(execHandleSessionStarted); \
	DECLARE_FUNCTION(execHandleStateChanged); \
	DECLARE_FUNCTION(execHandleFocusedInteractableChanged); \
	DECLARE_FUNCTION(execFindFocusedReconTarget); \
	DECLARE_FUNCTION(execTryStartReconWithTarget); \
	DECLARE_FUNCTION(execTryStartReconFromFocusedTarget);


struct Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics;
JMRECONGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMReconPlayerBridgeComponent_NoRegister();

#define FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Components_JMReconPlayerBridgeComponent_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMReconPlayerBridgeComponent(); \
	friend struct ::Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMRECONGAMEPLAYINTEGRATION_API UClass* ::Z_Construct_UClass_UJMReconPlayerBridgeComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMReconPlayerBridgeComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMReconGameplayIntegration"), Z_Construct_UClass_UJMReconPlayerBridgeComponent_NoRegister) \
	DECLARE_SERIALIZER(UJMReconPlayerBridgeComponent)


#define FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Components_JMReconPlayerBridgeComponent_h_27_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMReconPlayerBridgeComponent(UJMReconPlayerBridgeComponent&&) = delete; \
	UJMReconPlayerBridgeComponent(const UJMReconPlayerBridgeComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMReconPlayerBridgeComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMReconPlayerBridgeComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMReconPlayerBridgeComponent) \
	NO_API virtual ~UJMReconPlayerBridgeComponent();


#define FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Components_JMReconPlayerBridgeComponent_h_24_PROLOG
#define FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Components_JMReconPlayerBridgeComponent_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Components_JMReconPlayerBridgeComponent_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Components_JMReconPlayerBridgeComponent_h_27_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Components_JMReconPlayerBridgeComponent_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMReconPlayerBridgeComponent;

// ********** End Class UJMReconPlayerBridgeComponent **********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Components_JMReconPlayerBridgeComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
