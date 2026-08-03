// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystems/JMGameplayEventSubsystem.h"

#ifdef JMGAMEPLAYEVENT_JMGameplayEventSubsystem_generated_h
#error "JMGameplayEventSubsystem.generated.h already included, missing '#pragma once' in JMGameplayEventSubsystem.h"
#endif
#define JMGAMEPLAYEVENT_JMGameplayEventSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
struct FJMGameplayEventMessage;
struct FJMGameplayEventSubscriptionHandle;

// ********** Begin Class UJMGameplayEventSubsystem ************************************************
#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Subsystems_JMGameplayEventSubsystem_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execUnsubscribeAll); \
	DECLARE_FUNCTION(execUnsubscribeEvent); \
	DECLARE_FUNCTION(execPublishEvent);


struct Z_Construct_UClass_UJMGameplayEventSubsystem_Statics;
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventSubsystem_NoRegister();

#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Subsystems_JMGameplayEventSubsystem_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMGameplayEventSubsystem(); \
	friend struct ::Z_Construct_UClass_UJMGameplayEventSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMGAMEPLAYEVENT_API UClass* ::Z_Construct_UClass_UJMGameplayEventSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMGameplayEventSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/JMGameplayEvent"), Z_Construct_UClass_UJMGameplayEventSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UJMGameplayEventSubsystem)


#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Subsystems_JMGameplayEventSubsystem_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMGameplayEventSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMGameplayEventSubsystem(UJMGameplayEventSubsystem&&) = delete; \
	UJMGameplayEventSubsystem(const UJMGameplayEventSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMGameplayEventSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMGameplayEventSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMGameplayEventSubsystem) \
	NO_API virtual ~UJMGameplayEventSubsystem();


#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Subsystems_JMGameplayEventSubsystem_h_12_PROLOG
#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Subsystems_JMGameplayEventSubsystem_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Subsystems_JMGameplayEventSubsystem_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Subsystems_JMGameplayEventSubsystem_h_15_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Subsystems_JMGameplayEventSubsystem_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMGameplayEventSubsystem;

// ********** End Class UJMGameplayEventSubsystem **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Subsystems_JMGameplayEventSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
