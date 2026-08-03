// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "JMThrowableGameplayIntegrationComponent.h"

#ifdef JMTHROWABLEGAMEPLAYINTEGRATION_JMThrowableGameplayIntegrationComponent_generated_h
#error "JMThrowableGameplayIntegrationComponent.generated.h already included, missing '#pragma once' in JMThrowableGameplayIntegrationComponent.h"
#endif
#define JMTHROWABLEGAMEPLAYINTEGRATION_JMThrowableGameplayIntegrationComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EJMThrowableUseState : uint8;

// ********** Begin Class UJMThrowableGameplayIntegrationComponent *********************************
#define FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableGameplayIntegrationComponent_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleStateChanged); \
	DECLARE_FUNCTION(execHandleInventoryChanged); \
	DECLARE_FUNCTION(execRequestCancelSprint); \
	DECLARE_FUNCTION(execNotifyInventoryOpening);


#define FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableGameplayIntegrationComponent_h_21_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics;
JMTHROWABLEGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_NoRegister();

#define FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableGameplayIntegrationComponent_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMThrowableGameplayIntegrationComponent(); \
	friend struct ::Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMTHROWABLEGAMEPLAYINTEGRATION_API UClass* ::Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMThrowableGameplayIntegrationComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMThrowableGameplayIntegration"), Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_NoRegister) \
	DECLARE_SERIALIZER(UJMThrowableGameplayIntegrationComponent)


#define FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableGameplayIntegrationComponent_h_21_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMThrowableGameplayIntegrationComponent(UJMThrowableGameplayIntegrationComponent&&) = delete; \
	UJMThrowableGameplayIntegrationComponent(const UJMThrowableGameplayIntegrationComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMThrowableGameplayIntegrationComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMThrowableGameplayIntegrationComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMThrowableGameplayIntegrationComponent) \
	NO_API virtual ~UJMThrowableGameplayIntegrationComponent();


#define FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableGameplayIntegrationComponent_h_18_PROLOG
#define FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableGameplayIntegrationComponent_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableGameplayIntegrationComponent_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableGameplayIntegrationComponent_h_21_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableGameplayIntegrationComponent_h_21_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableGameplayIntegrationComponent_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMThrowableGameplayIntegrationComponent;

// ********** End Class UJMThrowableGameplayIntegrationComponent ***********************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableGameplayIntegrationComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
