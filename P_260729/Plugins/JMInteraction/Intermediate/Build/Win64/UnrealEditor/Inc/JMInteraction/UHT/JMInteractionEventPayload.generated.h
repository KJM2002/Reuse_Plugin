// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Payloads/JMInteractionEventPayload.h"

#ifdef JMINTERACTION_JMInteractionEventPayload_generated_h
#error "JMInteractionEventPayload.generated.h already included, missing '#pragma once' in JMInteractionEventPayload.h"
#endif
#define JMINTERACTION_JMInteractionEventPayload_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UJMInteractionEventPayload ***********************************************
struct Z_Construct_UClass_UJMInteractionEventPayload_Statics;
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractionEventPayload_NoRegister();

#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Payloads_JMInteractionEventPayload_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMInteractionEventPayload(); \
	friend struct ::Z_Construct_UClass_UJMInteractionEventPayload_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMINTERACTION_API UClass* ::Z_Construct_UClass_UJMInteractionEventPayload_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMInteractionEventPayload, UJMGameplayEventPayloadBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/JMInteraction"), Z_Construct_UClass_UJMInteractionEventPayload_NoRegister) \
	DECLARE_SERIALIZER(UJMInteractionEventPayload)


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Payloads_JMInteractionEventPayload_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMInteractionEventPayload(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMInteractionEventPayload(UJMInteractionEventPayload&&) = delete; \
	UJMInteractionEventPayload(const UJMInteractionEventPayload&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMInteractionEventPayload); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMInteractionEventPayload); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMInteractionEventPayload) \
	NO_API virtual ~UJMInteractionEventPayload();


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Payloads_JMInteractionEventPayload_h_8_PROLOG
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Payloads_JMInteractionEventPayload_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Payloads_JMInteractionEventPayload_h_11_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Payloads_JMInteractionEventPayload_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMInteractionEventPayload;

// ********** End Class UJMInteractionEventPayload *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Payloads_JMInteractionEventPayload_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
