// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Door/JMDoorComponent.h"

#ifdef JMDOORRUNTIME_JMDoorComponent_generated_h
#error "JMDoorComponent.generated.h already included, missing '#pragma once' in JMDoorComponent.h"
#endif
#define JMDOORRUNTIME_JMDoorComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UJMDoorMovementComponent;
enum class EJMDoorBlockBehavior : uint8;
enum class EJMDoorCommand : uint8;
enum class EJMDoorState : uint8;
enum class EJMSlideDoorPanel : uint8;
struct FJMDoorNoiseEvent;
struct FJMDoorResult;
struct FJMDoorSaveData;
struct FJMDoorUseContext;

// ********** Begin Delegate FJMDoorStateChangedSignature ******************************************
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorComponent_h_14_DELEGATE \
JMDOORRUNTIME_API void FJMDoorStateChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMDoorStateChangedSignature, EJMDoorState OldState, EJMDoorState NewState);


// ********** End Delegate FJMDoorStateChangedSignature ********************************************

// ********** Begin Delegate FJMDoorAccessDeniedSignature ******************************************
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorComponent_h_15_DELEGATE \
JMDOORRUNTIME_API void FJMDoorAccessDeniedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMDoorAccessDeniedSignature, FJMDoorUseContext Context, FJMDoorResult Result);


// ********** End Delegate FJMDoorAccessDeniedSignature ********************************************

// ********** Begin Delegate FJMDoorNoiseSignature *************************************************
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorComponent_h_16_DELEGATE \
JMDOORRUNTIME_API void FJMDoorNoiseSignature_DelegateWrapper(const FMulticastScriptDelegate& JMDoorNoiseSignature, FJMDoorNoiseEvent NoiseEvent);


// ********** End Delegate FJMDoorNoiseSignature ***************************************************

// ********** Begin Delegate FJMDoorObstructedSignature ********************************************
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorComponent_h_17_DELEGATE \
JMDOORRUNTIME_API void FJMDoorObstructedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMDoorObstructedSignature, AActor* BlockingActor, EJMDoorBlockBehavior Behavior);


// ********** End Delegate FJMDoorObstructedSignature **********************************************

// ********** Begin Delegate FJMDoorDurabilityChangedSignature *************************************
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorComponent_h_18_DELEGATE \
JMDOORRUNTIME_API void FJMDoorDurabilityChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMDoorDurabilityChangedSignature, float DoorDurability, float LockDurability, bool bLockBroken);


// ********** End Delegate FJMDoorDurabilityChangedSignature ***************************************

// ********** Begin Delegate FJMSlideDoorPanelStateChangedSignature ********************************
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorComponent_h_19_DELEGATE \
JMDOORRUNTIME_API void FJMSlideDoorPanelStateChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMSlideDoorPanelStateChangedSignature, EJMSlideDoorPanel Panel, EJMDoorState OldState, EJMDoorState NewState);


// ********** End Delegate FJMSlideDoorPanelStateChangedSignature **********************************

// ********** Begin Class UJMDoorComponent *********************************************************
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorComponent_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execValidateConfiguration); \
	DECLARE_FUNCTION(execGetLockDurability); \
	DECLARE_FUNCTION(execGetDoorDurability); \
	DECLARE_FUNCTION(execGetOpenFraction); \
	DECLARE_FUNCTION(execIsLocked); \
	DECLARE_FUNCTION(execGetState); \
	DECLARE_FUNCTION(execRestoreSaveData); \
	DECLARE_FUNCTION(execCaptureSaveData); \
	DECLARE_FUNCTION(execSetMovementComponent); \
	DECLARE_FUNCTION(execRetryBlockedMovement); \
	DECLARE_FUNCTION(execApplyLockDamage); \
	DECLARE_FUNCTION(execApplyDoorDamage); \
	DECLARE_FUNCTION(execForceOpenDoor); \
	DECLARE_FUNCTION(execUnlockDoor); \
	DECLARE_FUNCTION(execLockDoor); \
	DECLARE_FUNCTION(execGetSlideDoorPanelOpenFraction); \
	DECLARE_FUNCTION(execGetSlideDoorPanelState); \
	DECLARE_FUNCTION(execCloseSlideDoor); \
	DECLARE_FUNCTION(execOpenSlideDoor); \
	DECLARE_FUNCTION(execToggleDoor); \
	DECLARE_FUNCTION(execCloseDoor); \
	DECLARE_FUNCTION(execOpenDoor); \
	DECLARE_FUNCTION(execCanExecuteCommand); \
	DECLARE_FUNCTION(execExecuteCommand);


struct Z_Construct_UClass_UJMDoorComponent_Statics;
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorComponent_NoRegister();

#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorComponent_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMDoorComponent(); \
	friend struct ::Z_Construct_UClass_UJMDoorComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMDOORRUNTIME_API UClass* ::Z_Construct_UClass_UJMDoorComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMDoorComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMDoorRuntime"), Z_Construct_UClass_UJMDoorComponent_NoRegister) \
	DECLARE_SERIALIZER(UJMDoorComponent)


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorComponent_h_24_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMDoorComponent(UJMDoorComponent&&) = delete; \
	UJMDoorComponent(const UJMDoorComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMDoorComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMDoorComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMDoorComponent) \
	NO_API virtual ~UJMDoorComponent();


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorComponent_h_21_PROLOG
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorComponent_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorComponent_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorComponent_h_24_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorComponent_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMDoorComponent;

// ********** End Class UJMDoorComponent ***********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Door_JMDoorComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
