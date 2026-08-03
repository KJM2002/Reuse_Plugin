// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Tests/JMDoorTestEventReceiver.h"

#ifdef JMDOORTESTS_JMDoorTestEventReceiver_generated_h
#error "JMDoorTestEventReceiver.generated.h already included, missing '#pragma once' in JMDoorTestEventReceiver.h"
#endif
#define JMDOORTESTS_JMDoorTestEventReceiver_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FJMDoorNoiseEvent;

// ********** Begin Class UJMDoorTestEventReceiver *************************************************
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Private_Tests_JMDoorTestEventReceiver_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleNoise);


struct Z_Construct_UClass_UJMDoorTestEventReceiver_Statics;
JMDOORTESTS_API UClass* Z_Construct_UClass_UJMDoorTestEventReceiver_NoRegister();

#define FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Private_Tests_JMDoorTestEventReceiver_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMDoorTestEventReceiver(); \
	friend struct ::Z_Construct_UClass_UJMDoorTestEventReceiver_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMDOORTESTS_API UClass* ::Z_Construct_UClass_UJMDoorTestEventReceiver_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMDoorTestEventReceiver, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/JMDoorTests"), Z_Construct_UClass_UJMDoorTestEventReceiver_NoRegister) \
	DECLARE_SERIALIZER(UJMDoorTestEventReceiver)


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Private_Tests_JMDoorTestEventReceiver_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMDoorTestEventReceiver(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMDoorTestEventReceiver(UJMDoorTestEventReceiver&&) = delete; \
	UJMDoorTestEventReceiver(const UJMDoorTestEventReceiver&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMDoorTestEventReceiver); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMDoorTestEventReceiver); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMDoorTestEventReceiver) \
	NO_API virtual ~UJMDoorTestEventReceiver();


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Private_Tests_JMDoorTestEventReceiver_h_8_PROLOG
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Private_Tests_JMDoorTestEventReceiver_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Private_Tests_JMDoorTestEventReceiver_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Private_Tests_JMDoorTestEventReceiver_h_11_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Private_Tests_JMDoorTestEventReceiver_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMDoorTestEventReceiver;

// ********** End Class UJMDoorTestEventReceiver ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Private_Tests_JMDoorTestEventReceiver_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
