// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Actors/JMDoorActor.h"

#ifdef JMDOORRUNTIME_JMDoorActor_generated_h
#error "JMDoorActor.generated.h already included, missing '#pragma once' in JMDoorActor.h"
#endif
#define JMDOORRUNTIME_JMDoorActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EJMDoorState : uint8;
enum class EJMSlideDoorPanel : uint8;
struct FJMDoorResult;
struct FJMDoorUseContext;

// ********** Begin Class AJMDoorActor *************************************************************
struct Z_Construct_UClass_AJMDoorActor_Statics;
JMDOORRUNTIME_API UClass* Z_Construct_UClass_AJMDoorActor_NoRegister();

#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAJMDoorActor(); \
	friend struct ::Z_Construct_UClass_AJMDoorActor_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMDOORRUNTIME_API UClass* ::Z_Construct_UClass_AJMDoorActor_NoRegister(); \
public: \
	DECLARE_CLASS2(AJMDoorActor, AActor, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMDoorRuntime"), Z_Construct_UClass_AJMDoorActor_NoRegister) \
	DECLARE_SERIALIZER(AJMDoorActor) \
	virtual UObject* _getUObject() const override { return const_cast<AJMDoorActor*>(this); }


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h_18_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AJMDoorActor(AJMDoorActor&&) = delete; \
	AJMDoorActor(const AJMDoorActor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AJMDoorActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AJMDoorActor); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AJMDoorActor) \
	NO_API virtual ~AJMDoorActor();


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h_15_PROLOG
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h_18_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AJMDoorActor;

// ********** End Class AJMDoorActor ***************************************************************

// ********** Begin Class AJMRotatingDoorActor *****************************************************
struct Z_Construct_UClass_AJMRotatingDoorActor_Statics;
JMDOORRUNTIME_API UClass* Z_Construct_UClass_AJMRotatingDoorActor_NoRegister();

#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h_58_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAJMRotatingDoorActor(); \
	friend struct ::Z_Construct_UClass_AJMRotatingDoorActor_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMDOORRUNTIME_API UClass* ::Z_Construct_UClass_AJMRotatingDoorActor_NoRegister(); \
public: \
	DECLARE_CLASS2(AJMRotatingDoorActor, AJMDoorActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMDoorRuntime"), Z_Construct_UClass_AJMRotatingDoorActor_NoRegister) \
	DECLARE_SERIALIZER(AJMRotatingDoorActor)


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h_58_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AJMRotatingDoorActor(AJMRotatingDoorActor&&) = delete; \
	AJMRotatingDoorActor(const AJMRotatingDoorActor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AJMRotatingDoorActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AJMRotatingDoorActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AJMRotatingDoorActor) \
	NO_API virtual ~AJMRotatingDoorActor();


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h_55_PROLOG
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h_58_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h_58_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h_58_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AJMRotatingDoorActor;

// ********** End Class AJMRotatingDoorActor *******************************************************

// ********** Begin Class AJMSlidingDoorActor ******************************************************
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h_70_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetSlideDoorPanelState); \
	DECLARE_FUNCTION(execCloseSlideDoor); \
	DECLARE_FUNCTION(execOpenSlideDoor);


struct Z_Construct_UClass_AJMSlidingDoorActor_Statics;
JMDOORRUNTIME_API UClass* Z_Construct_UClass_AJMSlidingDoorActor_NoRegister();

#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h_70_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAJMSlidingDoorActor(); \
	friend struct ::Z_Construct_UClass_AJMSlidingDoorActor_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMDOORRUNTIME_API UClass* ::Z_Construct_UClass_AJMSlidingDoorActor_NoRegister(); \
public: \
	DECLARE_CLASS2(AJMSlidingDoorActor, AJMDoorActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMDoorRuntime"), Z_Construct_UClass_AJMSlidingDoorActor_NoRegister) \
	DECLARE_SERIALIZER(AJMSlidingDoorActor)


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h_70_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AJMSlidingDoorActor(AJMSlidingDoorActor&&) = delete; \
	AJMSlidingDoorActor(const AJMSlidingDoorActor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AJMSlidingDoorActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AJMSlidingDoorActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AJMSlidingDoorActor) \
	NO_API virtual ~AJMSlidingDoorActor();


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h_67_PROLOG
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h_70_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h_70_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h_70_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h_70_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AJMSlidingDoorActor;

// ********** End Class AJMSlidingDoorActor ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
