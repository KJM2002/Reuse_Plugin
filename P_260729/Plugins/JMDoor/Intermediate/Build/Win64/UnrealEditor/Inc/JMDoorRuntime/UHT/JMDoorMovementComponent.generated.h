// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Movement/JMDoorMovementComponent.h"

#ifdef JMDOORRUNTIME_JMDoorMovementComponent_generated_h
#error "JMDoorMovementComponent.generated.h already included, missing '#pragma once' in JMDoorMovementComponent.h"
#endif
#define JMDOORRUNTIME_JMDoorMovementComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class USceneComponent;

// ********** Begin Class UJMDoorMovementComponent *************************************************
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMDoorMovementComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execCalculateRelativeTransform); \
	DECLARE_FUNCTION(execGetCollisionComponent); \
	DECLARE_FUNCTION(execGetMovingComponent); \
	DECLARE_FUNCTION(execGetDirectionProbeWorldLocationAtFraction); \
	DECLARE_FUNCTION(execGetCollisionWorldTransformAtFraction); \
	DECLARE_FUNCTION(execGetWorldTransformAtFraction); \
	DECLARE_FUNCTION(execGetRelativeTransformAtFraction); \
	DECLARE_FUNCTION(execSetOpenFraction); \
	DECLARE_FUNCTION(execSetDirectionProbeComponent); \
	DECLARE_FUNCTION(execSetCollisionComponent); \
	DECLARE_FUNCTION(execInitializeMovingComponent);


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMDoorMovementComponent_h_13_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UJMDoorMovementComponent_Statics;
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorMovementComponent_NoRegister();

#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMDoorMovementComponent_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMDoorMovementComponent(); \
	friend struct ::Z_Construct_UClass_UJMDoorMovementComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMDOORRUNTIME_API UClass* ::Z_Construct_UClass_UJMDoorMovementComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMDoorMovementComponent, UActorComponent, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMDoorRuntime"), Z_Construct_UClass_UJMDoorMovementComponent_NoRegister) \
	DECLARE_SERIALIZER(UJMDoorMovementComponent)


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMDoorMovementComponent_h_13_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMDoorMovementComponent(UJMDoorMovementComponent&&) = delete; \
	UJMDoorMovementComponent(const UJMDoorMovementComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMDoorMovementComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMDoorMovementComponent); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(UJMDoorMovementComponent) \
	NO_API virtual ~UJMDoorMovementComponent();


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMDoorMovementComponent_h_10_PROLOG
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMDoorMovementComponent_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMDoorMovementComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMDoorMovementComponent_h_13_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMDoorMovementComponent_h_13_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMDoorMovementComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMDoorMovementComponent;

// ********** End Class UJMDoorMovementComponent ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMDoorMovementComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
