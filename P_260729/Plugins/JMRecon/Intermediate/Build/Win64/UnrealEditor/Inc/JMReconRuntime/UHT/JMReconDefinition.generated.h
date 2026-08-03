// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Data/JMReconDefinition.h"

#ifdef JMRECONRUNTIME_JMReconDefinition_generated_h
#error "JMReconDefinition.generated.h already included, missing '#pragma once' in JMReconDefinition.h"
#endif
#define JMRECONRUNTIME_JMReconDefinition_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UJMReconDefinition *******************************************************
struct Z_Construct_UClass_UJMReconDefinition_Statics;
JMRECONRUNTIME_API UClass* Z_Construct_UClass_UJMReconDefinition_NoRegister();

#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Data_JMReconDefinition_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMReconDefinition(); \
	friend struct ::Z_Construct_UClass_UJMReconDefinition_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMRECONRUNTIME_API UClass* ::Z_Construct_UClass_UJMReconDefinition_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMReconDefinition, UPrimaryDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/JMReconRuntime"), Z_Construct_UClass_UJMReconDefinition_NoRegister) \
	DECLARE_SERIALIZER(UJMReconDefinition)


#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Data_JMReconDefinition_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMReconDefinition(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMReconDefinition(UJMReconDefinition&&) = delete; \
	UJMReconDefinition(const UJMReconDefinition&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMReconDefinition); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMReconDefinition); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMReconDefinition) \
	NO_API virtual ~UJMReconDefinition();


#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Data_JMReconDefinition_h_10_PROLOG
#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Data_JMReconDefinition_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Data_JMReconDefinition_h_13_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Data_JMReconDefinition_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMReconDefinition;

// ********** End Class UJMReconDefinition *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Data_JMReconDefinition_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
