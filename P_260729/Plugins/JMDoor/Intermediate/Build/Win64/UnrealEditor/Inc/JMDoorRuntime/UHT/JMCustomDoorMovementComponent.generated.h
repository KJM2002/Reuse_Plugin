// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Movement/JMCustomDoorMovementComponent.h"

#ifdef JMDOORRUNTIME_JMCustomDoorMovementComponent_generated_h
#error "JMCustomDoorMovementComponent.generated.h already included, missing '#pragma once' in JMCustomDoorMovementComponent.h"
#endif
#define JMDOORRUNTIME_JMCustomDoorMovementComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UJMCustomDoorMovementComponent *******************************************
struct Z_Construct_UClass_UJMCustomDoorMovementComponent_Statics;
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMCustomDoorMovementComponent_NoRegister();

#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMCustomDoorMovementComponent_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMCustomDoorMovementComponent(); \
	friend struct ::Z_Construct_UClass_UJMCustomDoorMovementComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMDOORRUNTIME_API UClass* ::Z_Construct_UClass_UJMCustomDoorMovementComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMCustomDoorMovementComponent, UJMDoorMovementComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMDoorRuntime"), Z_Construct_UClass_UJMCustomDoorMovementComponent_NoRegister) \
	DECLARE_SERIALIZER(UJMCustomDoorMovementComponent)


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMCustomDoorMovementComponent_h_10_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMCustomDoorMovementComponent(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMCustomDoorMovementComponent(UJMCustomDoorMovementComponent&&) = delete; \
	UJMCustomDoorMovementComponent(const UJMCustomDoorMovementComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMCustomDoorMovementComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMCustomDoorMovementComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMCustomDoorMovementComponent) \
	NO_API virtual ~UJMCustomDoorMovementComponent();


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMCustomDoorMovementComponent_h_7_PROLOG
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMCustomDoorMovementComponent_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMCustomDoorMovementComponent_h_10_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMCustomDoorMovementComponent_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMCustomDoorMovementComponent;

// ********** End Class UJMCustomDoorMovementComponent *********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMCustomDoorMovementComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
