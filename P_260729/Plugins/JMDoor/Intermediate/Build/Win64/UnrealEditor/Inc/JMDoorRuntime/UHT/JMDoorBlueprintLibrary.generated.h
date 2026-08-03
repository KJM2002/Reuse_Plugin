// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Blueprint/JMDoorBlueprintLibrary.h"

#ifdef JMDOORRUNTIME_JMDoorBlueprintLibrary_generated_h
#error "JMDoorBlueprintLibrary.generated.h already included, missing '#pragma once' in JMDoorBlueprintLibrary.h"
#endif
#define JMDOORRUNTIME_JMDoorBlueprintLibrary_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UObject;
enum class EJMDoorCommand : uint8;
struct FGameplayTagContainer;
struct FJMDoorResult;
struct FJMDoorUseContext;

// ********** Begin Class UJMDoorBlueprintLibrary **************************************************
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Blueprint_JMDoorBlueprintLibrary_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execExecuteDoorCommandOnObject); \
	DECLARE_FUNCTION(execMakeDoorUseContext);


struct Z_Construct_UClass_UJMDoorBlueprintLibrary_Statics;
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorBlueprintLibrary_NoRegister();

#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Blueprint_JMDoorBlueprintLibrary_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMDoorBlueprintLibrary(); \
	friend struct ::Z_Construct_UClass_UJMDoorBlueprintLibrary_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMDOORRUNTIME_API UClass* ::Z_Construct_UClass_UJMDoorBlueprintLibrary_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMDoorBlueprintLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/JMDoorRuntime"), Z_Construct_UClass_UJMDoorBlueprintLibrary_NoRegister) \
	DECLARE_SERIALIZER(UJMDoorBlueprintLibrary)


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Blueprint_JMDoorBlueprintLibrary_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMDoorBlueprintLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMDoorBlueprintLibrary(UJMDoorBlueprintLibrary&&) = delete; \
	UJMDoorBlueprintLibrary(const UJMDoorBlueprintLibrary&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMDoorBlueprintLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMDoorBlueprintLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMDoorBlueprintLibrary) \
	NO_API virtual ~UJMDoorBlueprintLibrary();


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Blueprint_JMDoorBlueprintLibrary_h_8_PROLOG
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Blueprint_JMDoorBlueprintLibrary_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Blueprint_JMDoorBlueprintLibrary_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Blueprint_JMDoorBlueprintLibrary_h_11_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Blueprint_JMDoorBlueprintLibrary_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMDoorBlueprintLibrary;

// ********** End Class UJMDoorBlueprintLibrary ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Blueprint_JMDoorBlueprintLibrary_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
