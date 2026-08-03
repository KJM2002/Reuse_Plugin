// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Runtime/JMObjectiveFlowEventPayload.h"

#ifdef JMOBJECTIVE_JMObjectiveFlowEventPayload_generated_h
#error "JMObjectiveFlowEventPayload.generated.h already included, missing '#pragma once' in JMObjectiveFlowEventPayload.h"
#endif
#define JMOBJECTIVE_JMObjectiveFlowEventPayload_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UJMObjectiveFlowEventPayload *********************************************
struct Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics;
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveFlowEventPayload_NoRegister();

#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveFlowEventPayload_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMObjectiveFlowEventPayload(); \
	friend struct ::Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMOBJECTIVE_API UClass* ::Z_Construct_UClass_UJMObjectiveFlowEventPayload_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMObjectiveFlowEventPayload, UJMGameplayEventPayloadBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/JMObjective"), Z_Construct_UClass_UJMObjectiveFlowEventPayload_NoRegister) \
	DECLARE_SERIALIZER(UJMObjectiveFlowEventPayload)


#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveFlowEventPayload_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMObjectiveFlowEventPayload(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMObjectiveFlowEventPayload(UJMObjectiveFlowEventPayload&&) = delete; \
	UJMObjectiveFlowEventPayload(const UJMObjectiveFlowEventPayload&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMObjectiveFlowEventPayload); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMObjectiveFlowEventPayload); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMObjectiveFlowEventPayload) \
	NO_API virtual ~UJMObjectiveFlowEventPayload();


#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveFlowEventPayload_h_8_PROLOG
#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveFlowEventPayload_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveFlowEventPayload_h_11_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveFlowEventPayload_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMObjectiveFlowEventPayload;

// ********** End Class UJMObjectiveFlowEventPayload ***********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveFlowEventPayload_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
