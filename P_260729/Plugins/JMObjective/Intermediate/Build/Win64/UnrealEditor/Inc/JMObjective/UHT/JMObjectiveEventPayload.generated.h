// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Runtime/JMObjectiveEventPayload.h"

#ifdef JMOBJECTIVE_JMObjectiveEventPayload_generated_h
#error "JMObjectiveEventPayload.generated.h already included, missing '#pragma once' in JMObjectiveEventPayload.h"
#endif
#define JMOBJECTIVE_JMObjectiveEventPayload_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UJMObjectiveEventPayload *************************************************
struct Z_Construct_UClass_UJMObjectiveEventPayload_Statics;
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveEventPayload_NoRegister();

#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveEventPayload_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMObjectiveEventPayload(); \
	friend struct ::Z_Construct_UClass_UJMObjectiveEventPayload_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMOBJECTIVE_API UClass* ::Z_Construct_UClass_UJMObjectiveEventPayload_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMObjectiveEventPayload, UJMGameplayEventPayloadBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/JMObjective"), Z_Construct_UClass_UJMObjectiveEventPayload_NoRegister) \
	DECLARE_SERIALIZER(UJMObjectiveEventPayload)


#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveEventPayload_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMObjectiveEventPayload(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMObjectiveEventPayload(UJMObjectiveEventPayload&&) = delete; \
	UJMObjectiveEventPayload(const UJMObjectiveEventPayload&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMObjectiveEventPayload); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMObjectiveEventPayload); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMObjectiveEventPayload) \
	NO_API virtual ~UJMObjectiveEventPayload();


#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveEventPayload_h_8_PROLOG
#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveEventPayload_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveEventPayload_h_11_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveEventPayload_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMObjectiveEventPayload;

// ********** End Class UJMObjectiveEventPayload ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveEventPayload_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
