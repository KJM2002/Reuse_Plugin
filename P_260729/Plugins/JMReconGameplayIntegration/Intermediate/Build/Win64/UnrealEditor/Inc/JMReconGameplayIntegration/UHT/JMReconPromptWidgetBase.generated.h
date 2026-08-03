// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/JMReconPromptWidgetBase.h"

#ifdef JMRECONGAMEPLAYINTEGRATION_JMReconPromptWidgetBase_generated_h
#error "JMReconPromptWidgetBase.generated.h already included, missing '#pragma once' in JMReconPromptWidgetBase.h"
#endif
#define JMRECONGAMEPLAYINTEGRATION_JMReconPromptWidgetBase_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FJMInteractionPromptStyle;

// ********** Begin Class UJMReconPromptWidgetBase *************************************************
#define FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_UI_JMReconPromptWidgetBase_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetDisplayedPrompt); \
	DECLARE_FUNCTION(execApplyReconPromptStyle); \
	DECLARE_FUNCTION(execSetReconPrompt);


#define FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_UI_JMReconPromptWidgetBase_h_14_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UJMReconPromptWidgetBase_Statics;
JMRECONGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMReconPromptWidgetBase_NoRegister();

#define FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_UI_JMReconPromptWidgetBase_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMReconPromptWidgetBase(); \
	friend struct ::Z_Construct_UClass_UJMReconPromptWidgetBase_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMRECONGAMEPLAYINTEGRATION_API UClass* ::Z_Construct_UClass_UJMReconPromptWidgetBase_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMReconPromptWidgetBase, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/JMReconGameplayIntegration"), Z_Construct_UClass_UJMReconPromptWidgetBase_NoRegister) \
	DECLARE_SERIALIZER(UJMReconPromptWidgetBase)


#define FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_UI_JMReconPromptWidgetBase_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMReconPromptWidgetBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMReconPromptWidgetBase(UJMReconPromptWidgetBase&&) = delete; \
	UJMReconPromptWidgetBase(const UJMReconPromptWidgetBase&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMReconPromptWidgetBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMReconPromptWidgetBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMReconPromptWidgetBase) \
	NO_API virtual ~UJMReconPromptWidgetBase();


#define FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_UI_JMReconPromptWidgetBase_h_11_PROLOG
#define FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_UI_JMReconPromptWidgetBase_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_UI_JMReconPromptWidgetBase_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_UI_JMReconPromptWidgetBase_h_14_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_UI_JMReconPromptWidgetBase_h_14_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_UI_JMReconPromptWidgetBase_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMReconPromptWidgetBase;

// ********** End Class UJMReconPromptWidgetBase ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_UI_JMReconPromptWidgetBase_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
