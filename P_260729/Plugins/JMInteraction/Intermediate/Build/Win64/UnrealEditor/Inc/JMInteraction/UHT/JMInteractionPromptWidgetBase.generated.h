// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/JMInteractionPromptWidgetBase.h"

#ifdef JMINTERACTION_JMInteractionPromptWidgetBase_generated_h
#error "JMInteractionPromptWidgetBase.generated.h already included, missing '#pragma once' in JMInteractionPromptWidgetBase.h"
#endif
#define JMINTERACTION_JMInteractionPromptWidgetBase_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FJMInteractionPrompt;
struct FJMInteractionPromptStyle;

// ********** Begin Delegate FJMPromptTextEvent ****************************************************
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_UI_JMInteractionPromptWidgetBase_h_13_DELEGATE \
JMINTERACTION_API void FJMPromptTextEvent_DelegateWrapper(const FMulticastScriptDelegate& JMPromptTextEvent, const FText& PromptText);


// ********** End Delegate FJMPromptTextEvent ******************************************************

// ********** Begin Delegate FJMPromptVisibilityEvent **********************************************
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_UI_JMInteractionPromptWidgetBase_h_14_DELEGATE \
JMINTERACTION_API void FJMPromptVisibilityEvent_DelegateWrapper(const FMulticastScriptDelegate& JMPromptVisibilityEvent);


// ********** End Delegate FJMPromptVisibilityEvent ************************************************

// ********** Begin Delegate FJMPromptStyleEvent ***************************************************
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_UI_JMInteractionPromptWidgetBase_h_15_DELEGATE \
JMINTERACTION_API void FJMPromptStyleEvent_DelegateWrapper(const FMulticastScriptDelegate& JMPromptStyleEvent, FJMInteractionPromptStyle PromptStyle);


// ********** End Delegate FJMPromptStyleEvent *****************************************************

// ********** Begin Class UJMInteractionPromptWidgetBase *******************************************
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_UI_JMInteractionPromptWidgetBase_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetAppliedPromptStyle); \
	DECLARE_FUNCTION(execIsPromptVisible); \
	DECLARE_FUNCTION(execGetDisplayedPromptText); \
	DECLARE_FUNCTION(execApplyPromptStyle); \
	DECLARE_FUNCTION(execSetPromptVisible); \
	DECLARE_FUNCTION(execSetPromptText); \
	DECLARE_FUNCTION(execClearInteractionPrompt); \
	DECLARE_FUNCTION(execSetInteractionPrompt);


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_UI_JMInteractionPromptWidgetBase_h_20_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics;
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractionPromptWidgetBase_NoRegister();

#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_UI_JMInteractionPromptWidgetBase_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMInteractionPromptWidgetBase(); \
	friend struct ::Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMINTERACTION_API UClass* ::Z_Construct_UClass_UJMInteractionPromptWidgetBase_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMInteractionPromptWidgetBase, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/JMInteraction"), Z_Construct_UClass_UJMInteractionPromptWidgetBase_NoRegister) \
	DECLARE_SERIALIZER(UJMInteractionPromptWidgetBase)


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_UI_JMInteractionPromptWidgetBase_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMInteractionPromptWidgetBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMInteractionPromptWidgetBase(UJMInteractionPromptWidgetBase&&) = delete; \
	UJMInteractionPromptWidgetBase(const UJMInteractionPromptWidgetBase&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMInteractionPromptWidgetBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMInteractionPromptWidgetBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMInteractionPromptWidgetBase) \
	NO_API virtual ~UJMInteractionPromptWidgetBase();


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_UI_JMInteractionPromptWidgetBase_h_17_PROLOG
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_UI_JMInteractionPromptWidgetBase_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_UI_JMInteractionPromptWidgetBase_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_UI_JMInteractionPromptWidgetBase_h_20_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_UI_JMInteractionPromptWidgetBase_h_20_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_UI_JMInteractionPromptWidgetBase_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMInteractionPromptWidgetBase;

// ********** End Class UJMInteractionPromptWidgetBase *********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_UI_JMInteractionPromptWidgetBase_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
