// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Blueprint/JMJumpScareBlueprintLibrary.h"

#ifdef JMJUMPSCARE_JMJumpScareBlueprintLibrary_generated_h
#error "JMJumpScareBlueprintLibrary.generated.h already included, missing '#pragma once' in JMJumpScareBlueprintLibrary.h"
#endif
#define JMJUMPSCARE_JMJumpScareBlueprintLibrary_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APlayerController;
class UJMJumpScareDefinition;
class UObject;
enum class EJMJumpScarePlayResult : uint8;

// ********** Begin Class UJMJumpScareBlueprintLibrary *********************************************
#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Blueprint_JMJumpScareBlueprintLibrary_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execIsJumpScarePlaying); \
	DECLARE_FUNCTION(execCancelJumpScare); \
	DECLARE_FUNCTION(execPlayJumpScare);


struct Z_Construct_UClass_UJMJumpScareBlueprintLibrary_Statics;
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareBlueprintLibrary_NoRegister();

#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Blueprint_JMJumpScareBlueprintLibrary_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMJumpScareBlueprintLibrary(); \
	friend struct ::Z_Construct_UClass_UJMJumpScareBlueprintLibrary_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMJUMPSCARE_API UClass* ::Z_Construct_UClass_UJMJumpScareBlueprintLibrary_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMJumpScareBlueprintLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/JMJumpScare"), Z_Construct_UClass_UJMJumpScareBlueprintLibrary_NoRegister) \
	DECLARE_SERIALIZER(UJMJumpScareBlueprintLibrary)


#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Blueprint_JMJumpScareBlueprintLibrary_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMJumpScareBlueprintLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMJumpScareBlueprintLibrary(UJMJumpScareBlueprintLibrary&&) = delete; \
	UJMJumpScareBlueprintLibrary(const UJMJumpScareBlueprintLibrary&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMJumpScareBlueprintLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMJumpScareBlueprintLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMJumpScareBlueprintLibrary) \
	NO_API virtual ~UJMJumpScareBlueprintLibrary();


#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Blueprint_JMJumpScareBlueprintLibrary_h_11_PROLOG
#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Blueprint_JMJumpScareBlueprintLibrary_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Blueprint_JMJumpScareBlueprintLibrary_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Blueprint_JMJumpScareBlueprintLibrary_h_14_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Blueprint_JMJumpScareBlueprintLibrary_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMJumpScareBlueprintLibrary;

// ********** End Class UJMJumpScareBlueprintLibrary ***********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Blueprint_JMJumpScareBlueprintLibrary_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
