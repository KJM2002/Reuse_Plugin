// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DialogueWidgetBase.h"

#ifdef REUSABLEDIALOGUESYSTEM_DialogueWidgetBase_generated_h
#error "DialogueWidgetBase.generated.h already included, missing '#pragma once' in DialogueWidgetBase.h"
#endif
#define REUSABLEDIALOGUESYSTEM_DialogueWidgetBase_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UTexture2D;
struct FLinearColor;

// ********** Begin Class UDialogueWidgetBase ******************************************************
#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueWidgetBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execResetDialogueWidget); \
	DECLARE_FUNCTION(execSetAdvanceIndicatorVisible); \
	DECLARE_FUNCTION(execSetPortrait); \
	DECLARE_FUNCTION(execSetDialogueTextSmoothed); \
	DECLARE_FUNCTION(execSetDialogueText); \
	DECLARE_FUNCTION(execSetSpeakerNameColor); \
	DECLARE_FUNCTION(execSetSpeakerName);


#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueWidgetBase_h_15_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UDialogueWidgetBase_Statics;
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueWidgetBase_NoRegister();

#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueWidgetBase_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDialogueWidgetBase(); \
	friend struct ::Z_Construct_UClass_UDialogueWidgetBase_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend REUSABLEDIALOGUESYSTEM_API UClass* ::Z_Construct_UClass_UDialogueWidgetBase_NoRegister(); \
public: \
	DECLARE_CLASS2(UDialogueWidgetBase, UUserWidget, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/ReusableDialogueSystem"), Z_Construct_UClass_UDialogueWidgetBase_NoRegister) \
	DECLARE_SERIALIZER(UDialogueWidgetBase)


#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueWidgetBase_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDialogueWidgetBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDialogueWidgetBase(UDialogueWidgetBase&&) = delete; \
	UDialogueWidgetBase(const UDialogueWidgetBase&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDialogueWidgetBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDialogueWidgetBase); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDialogueWidgetBase) \
	NO_API virtual ~UDialogueWidgetBase();


#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueWidgetBase_h_12_PROLOG
#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueWidgetBase_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueWidgetBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueWidgetBase_h_15_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueWidgetBase_h_15_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueWidgetBase_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDialogueWidgetBase;

// ********** End Class UDialogueWidgetBase ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueWidgetBase_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
