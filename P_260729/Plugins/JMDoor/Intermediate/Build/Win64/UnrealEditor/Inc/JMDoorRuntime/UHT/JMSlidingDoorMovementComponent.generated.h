// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Movement/JMSlidingDoorMovementComponent.h"

#ifdef JMDOORRUNTIME_JMSlidingDoorMovementComponent_generated_h
#error "JMSlidingDoorMovementComponent.generated.h already included, missing '#pragma once' in JMSlidingDoorMovementComponent.h"
#endif
#define JMDOORRUNTIME_JMSlidingDoorMovementComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class USceneComponent;
enum class EJMSlideDoorPanel : uint8;

// ********** Begin Class UJMSlidingDoorMovementComponent ******************************************
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMSlidingDoorMovementComponent_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execIsLegacySinglePanelAsset); \
	DECLARE_FUNCTION(execHasPanel); \
	DECLARE_FUNCTION(execGetPanelCollisionComponent); \
	DECLARE_FUNCTION(execGetPanelCollisionWorldTransformAtFraction); \
	DECLARE_FUNCTION(execGetPanelWorldTransformAtFraction); \
	DECLARE_FUNCTION(execSetPanelOpenFraction); \
	DECLARE_FUNCTION(execInitializeDoorBComponent);


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMSlidingDoorMovementComponent_h_11_ARCHIVESERIALIZER \
	DECLARE_FSTRUCTUREDARCHIVE_SERIALIZER(UJMSlidingDoorMovementComponent, NO_API)


struct Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics;
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMSlidingDoorMovementComponent_NoRegister();

#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMSlidingDoorMovementComponent_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMSlidingDoorMovementComponent(); \
	friend struct ::Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMDOORRUNTIME_API UClass* ::Z_Construct_UClass_UJMSlidingDoorMovementComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMSlidingDoorMovementComponent, UJMDoorMovementComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMDoorRuntime"), Z_Construct_UClass_UJMSlidingDoorMovementComponent_NoRegister) \
	DECLARE_SERIALIZER(UJMSlidingDoorMovementComponent) \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMSlidingDoorMovementComponent_h_11_ARCHIVESERIALIZER


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMSlidingDoorMovementComponent_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMSlidingDoorMovementComponent(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMSlidingDoorMovementComponent(UJMSlidingDoorMovementComponent&&) = delete; \
	UJMSlidingDoorMovementComponent(const UJMSlidingDoorMovementComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMSlidingDoorMovementComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMSlidingDoorMovementComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMSlidingDoorMovementComponent) \
	NO_API virtual ~UJMSlidingDoorMovementComponent();


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMSlidingDoorMovementComponent_h_8_PROLOG
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMSlidingDoorMovementComponent_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMSlidingDoorMovementComponent_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMSlidingDoorMovementComponent_h_11_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMSlidingDoorMovementComponent_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMSlidingDoorMovementComponent;

// ********** End Class UJMSlidingDoorMovementComponent ********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMSlidingDoorMovementComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
