// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Payloads/JMGameplayEventPayloadBase.h"

#ifdef JMGAMEPLAYEVENT_JMGameplayEventPayloadBase_generated_h
#error "JMGameplayEventPayloadBase.generated.h already included, missing '#pragma once' in JMGameplayEventPayloadBase.h"
#endif
#define JMGAMEPLAYEVENT_JMGameplayEventPayloadBase_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UJMGameplayEventPayloadBase **********************************************
struct Z_Construct_UClass_UJMGameplayEventPayloadBase_Statics;
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventPayloadBase_NoRegister();

#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Payloads_JMGameplayEventPayloadBase_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMGameplayEventPayloadBase(); \
	friend struct ::Z_Construct_UClass_UJMGameplayEventPayloadBase_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMGAMEPLAYEVENT_API UClass* ::Z_Construct_UClass_UJMGameplayEventPayloadBase_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMGameplayEventPayloadBase, UObject, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Transient), CASTCLASS_None, TEXT("/Script/JMGameplayEvent"), Z_Construct_UClass_UJMGameplayEventPayloadBase_NoRegister) \
	DECLARE_SERIALIZER(UJMGameplayEventPayloadBase)


#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Payloads_JMGameplayEventPayloadBase_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMGameplayEventPayloadBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMGameplayEventPayloadBase(UJMGameplayEventPayloadBase&&) = delete; \
	UJMGameplayEventPayloadBase(const UJMGameplayEventPayloadBase&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMGameplayEventPayloadBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMGameplayEventPayloadBase); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMGameplayEventPayloadBase) \
	NO_API virtual ~UJMGameplayEventPayloadBase();


#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Payloads_JMGameplayEventPayloadBase_h_9_PROLOG
#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Payloads_JMGameplayEventPayloadBase_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Payloads_JMGameplayEventPayloadBase_h_12_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Payloads_JMGameplayEventPayloadBase_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMGameplayEventPayloadBase;

// ********** End Class UJMGameplayEventPayloadBase ************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Payloads_JMGameplayEventPayloadBase_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
