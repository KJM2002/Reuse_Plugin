// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Types/JMGameplayEventTypes.h"

#ifdef JMGAMEPLAYEVENT_JMGameplayEventTypes_generated_h
#error "JMGameplayEventTypes.generated.h already included, missing '#pragma once' in JMGameplayEventTypes.h"
#endif
#define JMGAMEPLAYEVENT_JMGameplayEventTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FJMGameplayEventMessage;

// ********** Begin ScriptStruct FJMGameplayEventSubscriptionHandle ********************************
struct Z_Construct_UScriptStruct_FJMGameplayEventSubscriptionHandle_Statics;
#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Types_JMGameplayEventTypes_h_19_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMGameplayEventSubscriptionHandle_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMGameplayEventSubscriptionHandle;
// ********** End ScriptStruct FJMGameplayEventSubscriptionHandle **********************************

// ********** Begin ScriptStruct FJMGameplayEventMessage *******************************************
struct Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics;
#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Types_JMGameplayEventTypes_h_36_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMGameplayEventMessage;
// ********** End ScriptStruct FJMGameplayEventMessage *********************************************

// ********** Begin Delegate FJMGameplayEventDynamicDelegate ***************************************
#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Types_JMGameplayEventTypes_h_58_DELEGATE \
JMGAMEPLAYEVENT_API void FJMGameplayEventDynamicDelegate_DelegateWrapper(const FMulticastScriptDelegate& JMGameplayEventDynamicDelegate, FJMGameplayEventMessage const& Message);


// ********** End Delegate FJMGameplayEventDynamicDelegate *****************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Types_JMGameplayEventTypes_h

// ********** Begin Enum EJMGameplayEventMatchType *************************************************
#define FOREACH_ENUM_EJMGAMEPLAYEVENTMATCHTYPE(op) \
	op(EJMGameplayEventMatchType::Exact) \
	op(EJMGameplayEventMatchType::IncludeChildren) 

enum class EJMGameplayEventMatchType : uint8;
template<> struct TIsUEnumClass<EJMGameplayEventMatchType> { enum { Value = true }; };
template<> JMGAMEPLAYEVENT_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMGameplayEventMatchType>();
// ********** End Enum EJMGameplayEventMatchType ***************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
