// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Blueprint/JMGameplayEventBlueprintLibrary.h"

#ifdef JMGAMEPLAYEVENT_JMGameplayEventBlueprintLibrary_generated_h
#error "JMGameplayEventBlueprintLibrary.generated.h already included, missing '#pragma once' in JMGameplayEventBlueprintLibrary.h"
#endif
#define JMGAMEPLAYEVENT_JMGameplayEventBlueprintLibrary_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UJMGameplayEventSubsystem;
class UObject;
struct FGameplayTag;
struct FGameplayTagContainer;

// ********** Begin Class UJMGameplayEventBlueprintLibrary *****************************************
#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Blueprint_JMGameplayEventBlueprintLibrary_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetGameplayEventSubsystem); \
	DECLARE_FUNCTION(execPublishGameplayEvent);


struct Z_Construct_UClass_UJMGameplayEventBlueprintLibrary_Statics;
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventBlueprintLibrary_NoRegister();

#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Blueprint_JMGameplayEventBlueprintLibrary_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMGameplayEventBlueprintLibrary(); \
	friend struct ::Z_Construct_UClass_UJMGameplayEventBlueprintLibrary_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMGAMEPLAYEVENT_API UClass* ::Z_Construct_UClass_UJMGameplayEventBlueprintLibrary_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMGameplayEventBlueprintLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/JMGameplayEvent"), Z_Construct_UClass_UJMGameplayEventBlueprintLibrary_NoRegister) \
	DECLARE_SERIALIZER(UJMGameplayEventBlueprintLibrary)


#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Blueprint_JMGameplayEventBlueprintLibrary_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMGameplayEventBlueprintLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMGameplayEventBlueprintLibrary(UJMGameplayEventBlueprintLibrary&&) = delete; \
	UJMGameplayEventBlueprintLibrary(const UJMGameplayEventBlueprintLibrary&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMGameplayEventBlueprintLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMGameplayEventBlueprintLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMGameplayEventBlueprintLibrary) \
	NO_API virtual ~UJMGameplayEventBlueprintLibrary();


#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Blueprint_JMGameplayEventBlueprintLibrary_h_10_PROLOG
#define FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Blueprint_JMGameplayEventBlueprintLibrary_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Blueprint_JMGameplayEventBlueprintLibrary_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Blueprint_JMGameplayEventBlueprintLibrary_h_13_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Blueprint_JMGameplayEventBlueprintLibrary_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMGameplayEventBlueprintLibrary;

// ********** End Class UJMGameplayEventBlueprintLibrary *******************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Blueprint_JMGameplayEventBlueprintLibrary_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
