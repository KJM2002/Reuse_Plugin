// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/JMInteractionComponent.h"

#ifdef JMINTERACTION_JMInteractionComponent_generated_h
#error "JMInteractionComponent.generated.h already included, missing '#pragma once' in JMInteractionComponent.h"
#endif
#define JMINTERACTION_JMInteractionComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UObject;
enum class EJMInteractionState : uint8;
struct FJMInteractionPrompt;
struct FJMInteractionResult;

// ********** Begin Delegate FJMInteractableChangedSignature ***************************************
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractionComponent_h_11_DELEGATE \
JMINTERACTION_API void FJMInteractableChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMInteractableChangedSignature, UObject* OldInteractable, UObject* NewInteractable);


// ********** End Delegate FJMInteractableChangedSignature *****************************************

// ********** Begin Delegate FJMInteractionPromptChangedSignature **********************************
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractionComponent_h_12_DELEGATE \
JMINTERACTION_API void FJMInteractionPromptChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMInteractionPromptChangedSignature, FJMInteractionPrompt Prompt);


// ********** End Delegate FJMInteractionPromptChangedSignature ************************************

// ********** Begin Delegate FJMInteractionFinishedSignature ***************************************
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractionComponent_h_13_DELEGATE \
JMINTERACTION_API void FJMInteractionFinishedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMInteractionFinishedSignature, UObject* Interactable, FJMInteractionResult Result);


// ********** End Delegate FJMInteractionFinishedSignature *****************************************

// ********** Begin Class UJMInteractionComponent **************************************************
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractionComponent_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetInteractionState); \
	DECLARE_FUNCTION(execGetCurrentPrompt); \
	DECLARE_FUNCTION(execGetCurrentInteractableActor); \
	DECLARE_FUNCTION(execGetCurrentInteractableObject); \
	DECLARE_FUNCTION(execIsPromptSuppressed); \
	DECLARE_FUNCTION(execSetPromptSuppressed); \
	DECLARE_FUNCTION(execSetInteractionEnabled); \
	DECLARE_FUNCTION(execCancelInteraction); \
	DECLARE_FUNCTION(execCompleteInteraction); \
	DECLARE_FUNCTION(execTryBeginInteraction); \
	DECLARE_FUNCTION(execTryInteract); \
	DECLARE_FUNCTION(execRefreshCurrentInteractableFromTrace); \
	DECLARE_FUNCTION(execRefreshCurrentInteractable);


struct Z_Construct_UClass_UJMInteractionComponent_Statics;
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractionComponent_NoRegister();

#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractionComponent_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMInteractionComponent(); \
	friend struct ::Z_Construct_UClass_UJMInteractionComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMINTERACTION_API UClass* ::Z_Construct_UClass_UJMInteractionComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMInteractionComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMInteraction"), Z_Construct_UClass_UJMInteractionComponent_NoRegister) \
	DECLARE_SERIALIZER(UJMInteractionComponent)


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractionComponent_h_18_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMInteractionComponent(UJMInteractionComponent&&) = delete; \
	UJMInteractionComponent(const UJMInteractionComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMInteractionComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMInteractionComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMInteractionComponent) \
	NO_API virtual ~UJMInteractionComponent();


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractionComponent_h_15_PROLOG
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractionComponent_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractionComponent_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractionComponent_h_18_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractionComponent_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMInteractionComponent;

// ********** End Class UJMInteractionComponent ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractionComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
