// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Payloads/JMJumpScareEventPayload.h"

#ifdef JMJUMPSCARE_JMJumpScareEventPayload_generated_h
#error "JMJumpScareEventPayload.generated.h already included, missing '#pragma once' in JMJumpScareEventPayload.h"
#endif
#define JMJUMPSCARE_JMJumpScareEventPayload_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UJMJumpScareEventPayload *************************************************
struct Z_Construct_UClass_UJMJumpScareEventPayload_Statics;
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareEventPayload_NoRegister();

#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Payloads_JMJumpScareEventPayload_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMJumpScareEventPayload(); \
	friend struct ::Z_Construct_UClass_UJMJumpScareEventPayload_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMJUMPSCARE_API UClass* ::Z_Construct_UClass_UJMJumpScareEventPayload_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMJumpScareEventPayload, UJMGameplayEventPayloadBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/JMJumpScare"), Z_Construct_UClass_UJMJumpScareEventPayload_NoRegister) \
	DECLARE_SERIALIZER(UJMJumpScareEventPayload)


#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Payloads_JMJumpScareEventPayload_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMJumpScareEventPayload(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMJumpScareEventPayload(UJMJumpScareEventPayload&&) = delete; \
	UJMJumpScareEventPayload(const UJMJumpScareEventPayload&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMJumpScareEventPayload); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMJumpScareEventPayload); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMJumpScareEventPayload) \
	NO_API virtual ~UJMJumpScareEventPayload();


#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Payloads_JMJumpScareEventPayload_h_13_PROLOG
#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Payloads_JMJumpScareEventPayload_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Payloads_JMJumpScareEventPayload_h_16_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Payloads_JMJumpScareEventPayload_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMJumpScareEventPayload;

// ********** End Class UJMJumpScareEventPayload ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Payloads_JMJumpScareEventPayload_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
