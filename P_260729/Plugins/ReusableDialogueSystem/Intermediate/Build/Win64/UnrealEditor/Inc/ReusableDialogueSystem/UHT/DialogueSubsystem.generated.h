// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DialogueSubsystem.h"

#ifdef REUSABLEDIALOGUESYSTEM_DialogueSubsystem_generated_h
#error "DialogueSubsystem.generated.h already included, missing '#pragma once' in DialogueSubsystem.h"
#endif
#define REUSABLEDIALOGUESYSTEM_DialogueSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APlayerController;
class UDialogueSequence;
enum class EDialogueEndReason : uint8;
enum class EDialogueInteractionMode : uint8;
enum class EDialogueState : uint8;
enum class EExistingDialoguePolicy : uint8;
struct FDialogueHistoryEntry;
struct FDialogueLine;

// ********** Begin Delegate FDialogueStartedSignature *********************************************
#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSubsystem_h_14_DELEGATE \
REUSABLEDIALOGUESYSTEM_API void FDialogueStartedSignature_DelegateWrapper(const FMulticastScriptDelegate& DialogueStartedSignature, UDialogueSequence* Sequence);


// ********** End Delegate FDialogueStartedSignature ***********************************************

// ********** Begin Delegate FDialogueStateChangedSignature ****************************************
#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSubsystem_h_15_DELEGATE \
REUSABLEDIALOGUESYSTEM_API void FDialogueStateChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& DialogueStateChangedSignature, EDialogueState PreviousState, EDialogueState NewState);


// ********** End Delegate FDialogueStateChangedSignature ******************************************

// ********** Begin Delegate FDialogueLineSignature ************************************************
#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSubsystem_h_16_DELEGATE \
REUSABLEDIALOGUESYSTEM_API void FDialogueLineSignature_DelegateWrapper(const FMulticastScriptDelegate& DialogueLineSignature, UDialogueSequence* Sequence, FName LineId, int32 LineIndex);


// ********** End Delegate FDialogueLineSignature **************************************************

// ********** Begin Delegate FDialogueEndedSignature ***********************************************
#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSubsystem_h_17_DELEGATE \
REUSABLEDIALOGUESYSTEM_API void FDialogueEndedSignature_DelegateWrapper(const FMulticastScriptDelegate& DialogueEndedSignature, UDialogueSequence* Sequence, EDialogueEndReason Reason);


// ********** End Delegate FDialogueEndedSignature *************************************************

// ********** Begin Class UDialogueSubsystem *******************************************************
#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSubsystem_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execClearDialogueHistory); \
	DECLARE_FUNCTION(execGetDialogueHistory); \
	DECLARE_FUNCTION(execGetCurrentLine); \
	DECLARE_FUNCTION(execGetCurrentLineIndex); \
	DECLARE_FUNCTION(execGetCurrentSequence); \
	DECLARE_FUNCTION(execGetDialogueState); \
	DECLARE_FUNCTION(execIsLineRevealing); \
	DECLARE_FUNCTION(execIsDialogueActive); \
	DECLARE_FUNCTION(execResumeDialogue); \
	DECLARE_FUNCTION(execPauseDialogue); \
	DECLARE_FUNCTION(execStopDialogue); \
	DECLARE_FUNCTION(execCompleteCurrentLine); \
	DECLARE_FUNCTION(execAdvanceDialogue); \
	DECLARE_FUNCTION(execStartDialogue);


struct Z_Construct_UClass_UDialogueSubsystem_Statics;
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueSubsystem_NoRegister();

#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSubsystem_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDialogueSubsystem(); \
	friend struct ::Z_Construct_UClass_UDialogueSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend REUSABLEDIALOGUESYSTEM_API UClass* ::Z_Construct_UClass_UDialogueSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UDialogueSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ReusableDialogueSystem"), Z_Construct_UClass_UDialogueSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UDialogueSubsystem)


#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSubsystem_h_22_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDialogueSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDialogueSubsystem(UDialogueSubsystem&&) = delete; \
	UDialogueSubsystem(const UDialogueSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDialogueSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDialogueSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDialogueSubsystem) \
	NO_API virtual ~UDialogueSubsystem();


#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSubsystem_h_19_PROLOG
#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSubsystem_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSubsystem_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSubsystem_h_22_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSubsystem_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDialogueSubsystem;

// ********** End Class UDialogueSubsystem *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
