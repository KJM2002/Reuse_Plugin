// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/JMDoorInventoryAgentComponent.h"

#ifdef JMDOORGAMEPLAYINTEGRATION_JMDoorInventoryAgentComponent_generated_h
#error "JMDoorInventoryAgentComponent.generated.h already included, missing '#pragma once' in JMDoorInventoryAgentComponent.h"
#endif
#define JMDOORGAMEPLAYINTEGRATION_JMDoorInventoryAgentComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class AJMDoorActor;
class UInventoryItemDefinition;
struct FJMInteractionContext;

// ********** Begin Delegate FJMPendingDoorChangedSignature ****************************************
#define FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Components_JMDoorInventoryAgentComponent_h_14_DELEGATE \
JMDOORGAMEPLAYINTEGRATION_API void FJMPendingDoorChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMPendingDoorChangedSignature, AJMDoorActor* PendingDoor);


// ********** End Delegate FJMPendingDoorChangedSignature ******************************************

// ********** Begin Class UJMDoorInventoryAgentComponent *******************************************
#define FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Components_JMDoorInventoryAgentComponent_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execUseItemOnPendingDoor); \
	DECLARE_FUNCTION(execGetPendingDoor); \
	DECLARE_FUNCTION(execClearPendingDoor); \
	DECLARE_FUNCTION(execSetPendingDoorForItemUse); \
	DECLARE_FUNCTION(execBeginLockedDoorItemSelection);


struct Z_Construct_UClass_UJMDoorInventoryAgentComponent_Statics;
JMDOORGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMDoorInventoryAgentComponent_NoRegister();

#define FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Components_JMDoorInventoryAgentComponent_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMDoorInventoryAgentComponent(); \
	friend struct ::Z_Construct_UClass_UJMDoorInventoryAgentComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMDOORGAMEPLAYINTEGRATION_API UClass* ::Z_Construct_UClass_UJMDoorInventoryAgentComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMDoorInventoryAgentComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMDoorGameplayIntegration"), Z_Construct_UClass_UJMDoorInventoryAgentComponent_NoRegister) \
	DECLARE_SERIALIZER(UJMDoorInventoryAgentComponent) \
	virtual UObject* _getUObject() const override { return const_cast<UJMDoorInventoryAgentComponent*>(this); }


#define FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Components_JMDoorInventoryAgentComponent_h_22_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMDoorInventoryAgentComponent(UJMDoorInventoryAgentComponent&&) = delete; \
	UJMDoorInventoryAgentComponent(const UJMDoorInventoryAgentComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMDoorInventoryAgentComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMDoorInventoryAgentComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMDoorInventoryAgentComponent) \
	NO_API virtual ~UJMDoorInventoryAgentComponent();


#define FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Components_JMDoorInventoryAgentComponent_h_17_PROLOG
#define FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Components_JMDoorInventoryAgentComponent_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Components_JMDoorInventoryAgentComponent_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Components_JMDoorInventoryAgentComponent_h_22_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Components_JMDoorInventoryAgentComponent_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMDoorInventoryAgentComponent;

// ********** End Class UJMDoorInventoryAgentComponent *********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Components_JMDoorInventoryAgentComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
