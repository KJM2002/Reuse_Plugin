// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystems/JMObjectiveUISubsystem.h"

#ifdef JMOBJECTIVE_JMObjectiveUISubsystem_generated_h
#error "JMObjectiveUISubsystem.generated.h already included, missing '#pragma once' in JMObjectiveUISubsystem.h"
#endif
#define JMOBJECTIVE_JMObjectiveUISubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UJMObjectiveWidgetBase;
struct FGameplayTag;
struct FJMObjectiveRuntimeState;

// ********** Begin Class UJMObjectiveUISubsystem **************************************************
#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveUISubsystem_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleRemoved); \
	DECLARE_FUNCTION(execHandleFailed); \
	DECLARE_FUNCTION(execHandleCompleted); \
	DECLARE_FUNCTION(execHandleProgressed); \
	DECLARE_FUNCTION(execHandleActivated); \
	DECLARE_FUNCTION(execHandleRegistered); \
	DECLARE_FUNCTION(execGetObjectiveWidget);


struct Z_Construct_UClass_UJMObjectiveUISubsystem_Statics;
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveUISubsystem_NoRegister();

#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveUISubsystem_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMObjectiveUISubsystem(); \
	friend struct ::Z_Construct_UClass_UJMObjectiveUISubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMOBJECTIVE_API UClass* ::Z_Construct_UClass_UJMObjectiveUISubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMObjectiveUISubsystem, ULocalPlayerSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/JMObjective"), Z_Construct_UClass_UJMObjectiveUISubsystem_NoRegister) \
	DECLARE_SERIALIZER(UJMObjectiveUISubsystem)


#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveUISubsystem_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMObjectiveUISubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMObjectiveUISubsystem(UJMObjectiveUISubsystem&&) = delete; \
	UJMObjectiveUISubsystem(const UJMObjectiveUISubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMObjectiveUISubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMObjectiveUISubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMObjectiveUISubsystem) \
	NO_API virtual ~UJMObjectiveUISubsystem();


#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveUISubsystem_h_13_PROLOG
#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveUISubsystem_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveUISubsystem_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveUISubsystem_h_16_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveUISubsystem_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMObjectiveUISubsystem;

// ********** End Class UJMObjectiveUISubsystem ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Subsystems_JMObjectiveUISubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
