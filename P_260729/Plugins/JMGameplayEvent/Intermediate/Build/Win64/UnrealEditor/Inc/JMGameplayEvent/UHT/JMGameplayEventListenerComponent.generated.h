// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/JMGameplayEventListenerComponent.h"

#ifdef JMGAMEPLAYEVENT_JMGameplayEventListenerComponent_generated_h
#error "JMGameplayEventListenerComponent.generated.h already included, missing '#pragma once' in JMGameplayEventListenerComponent.h"
#endif
#define JMGAMEPLAYEVENT_JMGameplayEventListenerComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGameplayTag;

// ********** Begin Class UJMGameplayEventListenerComponent ****************************************
#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Components_JMGameplayEventListenerComponent_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execUnsubscribeAll); \
	DECLARE_FUNCTION(execRefreshSubscriptions); \
	DECLARE_FUNCTION(execRemoveEventTag); \
	DECLARE_FUNCTION(execAddEventTag);


struct Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics;
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventListenerComponent_NoRegister();

#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Components_JMGameplayEventListenerComponent_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMGameplayEventListenerComponent(); \
	friend struct ::Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMGAMEPLAYEVENT_API UClass* ::Z_Construct_UClass_UJMGameplayEventListenerComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMGameplayEventListenerComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMGameplayEvent"), Z_Construct_UClass_UJMGameplayEventListenerComponent_NoRegister) \
	DECLARE_SERIALIZER(UJMGameplayEventListenerComponent)


#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Components_JMGameplayEventListenerComponent_h_11_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMGameplayEventListenerComponent(UJMGameplayEventListenerComponent&&) = delete; \
	UJMGameplayEventListenerComponent(const UJMGameplayEventListenerComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMGameplayEventListenerComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMGameplayEventListenerComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMGameplayEventListenerComponent) \
	NO_API virtual ~UJMGameplayEventListenerComponent();


#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Components_JMGameplayEventListenerComponent_h_8_PROLOG
#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Components_JMGameplayEventListenerComponent_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Components_JMGameplayEventListenerComponent_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Components_JMGameplayEventListenerComponent_h_11_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Components_JMGameplayEventListenerComponent_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMGameplayEventListenerComponent;

// ********** End Class UJMGameplayEventListenerComponent ******************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Components_JMGameplayEventListenerComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
