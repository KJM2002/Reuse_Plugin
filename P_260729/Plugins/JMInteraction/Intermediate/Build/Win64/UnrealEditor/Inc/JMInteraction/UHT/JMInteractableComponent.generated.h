// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/JMInteractableComponent.h"

#ifdef JMINTERACTION_JMInteractableComponent_generated_h
#error "JMInteractableComponent.generated.h already included, missing '#pragma once' in JMInteractableComponent.h"
#endif
#define JMINTERACTION_JMInteractableComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FJMInteractionContext;
struct FJMInteractionResult;

// ********** Begin Delegate FJMInteractableEvent **************************************************
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractableComponent_h_7_DELEGATE \
JMINTERACTION_API void FJMInteractableEvent_DelegateWrapper(const FMulticastScriptDelegate& JMInteractableEvent, FJMInteractionContext const& Context);


// ********** End Delegate FJMInteractableEvent ****************************************************

// ********** Begin Class UJMInteractableComponent *************************************************
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractableComponent_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual FJMInteractionResult HandleInteract_Implementation(FJMInteractionContext const& Context); \
	virtual bool EvaluateCanInteract_Implementation(FJMInteractionContext const& Context) const; \
	DECLARE_FUNCTION(execHandleInteract); \
	DECLARE_FUNCTION(execEvaluateCanInteract);


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractableComponent_h_12_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UJMInteractableComponent_Statics;
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractableComponent_NoRegister();

#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractableComponent_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMInteractableComponent(); \
	friend struct ::Z_Construct_UClass_UJMInteractableComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMINTERACTION_API UClass* ::Z_Construct_UClass_UJMInteractableComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMInteractableComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMInteraction"), Z_Construct_UClass_UJMInteractableComponent_NoRegister) \
	DECLARE_SERIALIZER(UJMInteractableComponent) \
	virtual UObject* _getUObject() const override { return const_cast<UJMInteractableComponent*>(this); }


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractableComponent_h_12_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMInteractableComponent(UJMInteractableComponent&&) = delete; \
	UJMInteractableComponent(const UJMInteractableComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMInteractableComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMInteractableComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMInteractableComponent) \
	NO_API virtual ~UJMInteractableComponent();


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractableComponent_h_9_PROLOG
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractableComponent_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractableComponent_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractableComponent_h_12_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractableComponent_h_12_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractableComponent_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMInteractableComponent;

// ********** End Class UJMInteractableComponent ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractableComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
