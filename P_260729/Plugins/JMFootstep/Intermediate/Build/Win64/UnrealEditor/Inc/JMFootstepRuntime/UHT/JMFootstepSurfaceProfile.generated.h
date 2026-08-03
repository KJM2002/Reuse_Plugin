// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Data/JMFootstepSurfaceProfile.h"

#ifdef JMFOOTSTEPRUNTIME_JMFootstepSurfaceProfile_generated_h
#error "JMFootstepSurfaceProfile.generated.h already included, missing '#pragma once' in JMFootstepSurfaceProfile.h"
#endif
#define JMFOOTSTEPRUNTIME_JMFootstepSurfaceProfile_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EJMFootstepLocomotionState : uint8;
struct FJMFootstepSoundVariant;

// ********** Begin ScriptStruct FJMFootstepSoundVariant *******************************************
struct Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics;
#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSurfaceProfile_h_14_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMFootstepSoundVariant_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMFootstepSoundVariant;
// ********** End ScriptStruct FJMFootstepSoundVariant *********************************************

// ********** Begin Class UJMFootstepSurfaceProfile ************************************************
#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSurfaceProfile_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execResolveVariant);


struct Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics;
JMFOOTSTEPRUNTIME_API UClass* Z_Construct_UClass_UJMFootstepSurfaceProfile_NoRegister();

#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSurfaceProfile_h_38_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMFootstepSurfaceProfile(); \
	friend struct ::Z_Construct_UClass_UJMFootstepSurfaceProfile_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMFOOTSTEPRUNTIME_API UClass* ::Z_Construct_UClass_UJMFootstepSurfaceProfile_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMFootstepSurfaceProfile, UPrimaryDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/JMFootstepRuntime"), Z_Construct_UClass_UJMFootstepSurfaceProfile_NoRegister) \
	DECLARE_SERIALIZER(UJMFootstepSurfaceProfile)


#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSurfaceProfile_h_38_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMFootstepSurfaceProfile(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMFootstepSurfaceProfile(UJMFootstepSurfaceProfile&&) = delete; \
	UJMFootstepSurfaceProfile(const UJMFootstepSurfaceProfile&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMFootstepSurfaceProfile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMFootstepSurfaceProfile); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMFootstepSurfaceProfile) \
	NO_API virtual ~UJMFootstepSurfaceProfile();


#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSurfaceProfile_h_35_PROLOG
#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSurfaceProfile_h_38_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSurfaceProfile_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSurfaceProfile_h_38_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSurfaceProfile_h_38_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMFootstepSurfaceProfile;

// ********** End Class UJMFootstepSurfaceProfile **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSurfaceProfile_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
