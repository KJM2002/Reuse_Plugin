// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Data/JMFootstepSet.h"

#ifdef JMFOOTSTEPRUNTIME_JMFootstepSet_generated_h
#error "JMFootstepSet.generated.h already included, missing '#pragma once' in JMFootstepSet.h"
#endif
#define JMFOOTSTEPRUNTIME_JMFootstepSet_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UJMFootstepSurfaceProfile;

// ********** Begin ScriptStruct FJMFootstepSurfaceEntry *******************************************
struct Z_Construct_UScriptStruct_FJMFootstepSurfaceEntry_Statics;
#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSet_h_13_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMFootstepSurfaceEntry_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMFootstepSurfaceEntry;
// ********** End ScriptStruct FJMFootstepSurfaceEntry *********************************************

// ********** Begin Class UJMFootstepSet ***********************************************************
#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSet_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execFindProfile);


struct Z_Construct_UClass_UJMFootstepSet_Statics;
JMFOOTSTEPRUNTIME_API UClass* Z_Construct_UClass_UJMFootstepSet_NoRegister();

#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSet_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMFootstepSet(); \
	friend struct ::Z_Construct_UClass_UJMFootstepSet_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMFOOTSTEPRUNTIME_API UClass* ::Z_Construct_UClass_UJMFootstepSet_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMFootstepSet, UPrimaryDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/JMFootstepRuntime"), Z_Construct_UClass_UJMFootstepSet_NoRegister) \
	DECLARE_SERIALIZER(UJMFootstepSet)


#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSet_h_25_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMFootstepSet(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMFootstepSet(UJMFootstepSet&&) = delete; \
	UJMFootstepSet(const UJMFootstepSet&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMFootstepSet); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMFootstepSet); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMFootstepSet) \
	NO_API virtual ~UJMFootstepSet();


#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSet_h_22_PROLOG
#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSet_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSet_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSet_h_25_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSet_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMFootstepSet;

// ********** End Class UJMFootstepSet *************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSet_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
