// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ReusableDialogueTypes.h"

#ifdef REUSABLEDIALOGUESYSTEM_ReusableDialogueTypes_generated_h
#error "ReusableDialogueTypes.generated.h already included, missing '#pragma once' in ReusableDialogueTypes.h"
#endif
#define REUSABLEDIALOGUESYSTEM_ReusableDialogueTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FDialogueLine *****************************************************
struct Z_Construct_UScriptStruct_FDialogueLine_Statics;
#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_ReusableDialogueTypes_h_36_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FDialogueLine_Statics; \
	static class UScriptStruct* StaticStruct();


struct FDialogueLine;
// ********** End ScriptStruct FDialogueLine *******************************************************

// ********** Begin ScriptStruct FDialogueHistoryEntry *********************************************
struct Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics;
#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_ReusableDialogueTypes_h_63_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FDialogueHistoryEntry_Statics; \
	static class UScriptStruct* StaticStruct();


struct FDialogueHistoryEntry;
// ********** End ScriptStruct FDialogueHistoryEntry ***********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_ReusableDialogueTypes_h

// ********** Begin Enum EDialogueState ************************************************************
#define FOREACH_ENUM_EDIALOGUESTATE(op) \
	op(EDialogueState::Inactive) \
	op(EDialogueState::Opening) \
	op(EDialogueState::Revealing) \
	op(EDialogueState::WaitingForAdvance) \
	op(EDialogueState::Transitioning) \
	op(EDialogueState::Paused) \
	op(EDialogueState::Closing) 

enum class EDialogueState : uint8;
template<> struct TIsUEnumClass<EDialogueState> { enum { Value = true }; };
template<> REUSABLEDIALOGUESYSTEM_NON_ATTRIBUTED_API UEnum* StaticEnum<EDialogueState>();
// ********** End Enum EDialogueState **************************************************************

// ********** Begin Enum EDialogueRevealMode *******************************************************
#define FOREACH_ENUM_EDIALOGUEREVEALMODE(op) \
	op(EDialogueRevealMode::Word) \
	op(EDialogueRevealMode::Character) \
	op(EDialogueRevealMode::Instant) 

enum class EDialogueRevealMode : uint8;
template<> struct TIsUEnumClass<EDialogueRevealMode> { enum { Value = true }; };
template<> REUSABLEDIALOGUESYSTEM_NON_ATTRIBUTED_API UEnum* StaticEnum<EDialogueRevealMode>();
// ********** End Enum EDialogueRevealMode *********************************************************

// ********** Begin Enum EDialogueInteractionMode **************************************************
#define FOREACH_ENUM_EDIALOGUEINTERACTIONMODE(op) \
	op(EDialogueInteractionMode::Modal) \
	op(EDialogueInteractionMode::Overlay) \
	op(EDialogueInteractionMode::Cinematic) 

enum class EDialogueInteractionMode : uint8;
template<> struct TIsUEnumClass<EDialogueInteractionMode> { enum { Value = true }; };
template<> REUSABLEDIALOGUESYSTEM_NON_ATTRIBUTED_API UEnum* StaticEnum<EDialogueInteractionMode>();
// ********** End Enum EDialogueInteractionMode ****************************************************

// ********** Begin Enum EExistingDialoguePolicy ***************************************************
#define FOREACH_ENUM_EEXISTINGDIALOGUEPOLICY(op) \
	op(EExistingDialoguePolicy::Reject) \
	op(EExistingDialoguePolicy::ReplaceCurrent) 

enum class EExistingDialoguePolicy : uint8;
template<> struct TIsUEnumClass<EExistingDialoguePolicy> { enum { Value = true }; };
template<> REUSABLEDIALOGUESYSTEM_NON_ATTRIBUTED_API UEnum* StaticEnum<EExistingDialoguePolicy>();
// ********** End Enum EExistingDialoguePolicy *****************************************************

// ********** Begin Enum EDialogueTextSoundTriggerMode *********************************************
#define FOREACH_ENUM_EDIALOGUETEXTSOUNDTRIGGERMODE(op) \
	op(EDialogueTextSoundTriggerMode::PerRevealToken) \
	op(EDialogueTextSoundTriggerMode::EveryNCharacters) \
	op(EDialogueTextSoundTriggerMode::None) 

enum class EDialogueTextSoundTriggerMode : uint8;
template<> struct TIsUEnumClass<EDialogueTextSoundTriggerMode> { enum { Value = true }; };
template<> REUSABLEDIALOGUESYSTEM_NON_ATTRIBUTED_API UEnum* StaticEnum<EDialogueTextSoundTriggerMode>();
// ********** End Enum EDialogueTextSoundTriggerMode ***********************************************

// ********** Begin Enum EDialogueEndReason ********************************************************
#define FOREACH_ENUM_EDIALOGUEENDREASON(op) \
	op(EDialogueEndReason::Completed) \
	op(EDialogueEndReason::Cancelled) \
	op(EDialogueEndReason::Replaced) \
	op(EDialogueEndReason::InvalidData) \
	op(EDialogueEndReason::WidgetCreationFailed) 

enum class EDialogueEndReason : uint8;
template<> struct TIsUEnumClass<EDialogueEndReason> { enum { Value = true }; };
template<> REUSABLEDIALOGUESYSTEM_NON_ATTRIBUTED_API UEnum* StaticEnum<EDialogueEndReason>();
// ********** End Enum EDialogueEndReason **********************************************************

// ********** Begin Enum EDialogueTokenType ********************************************************
#define FOREACH_ENUM_EDIALOGUETOKENTYPE(op) \
	op(EDialogueTokenType::Word) \
	op(EDialogueTokenType::Whitespace) \
	op(EDialogueTokenType::Punctuation) \
	op(EDialogueTokenType::Mixed) 

enum class EDialogueTokenType : uint8;
template<> struct TIsUEnumClass<EDialogueTokenType> { enum { Value = true }; };
template<> REUSABLEDIALOGUESYSTEM_NON_ATTRIBUTED_API UEnum* StaticEnum<EDialogueTokenType>();
// ********** End Enum EDialogueTokenType **********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
