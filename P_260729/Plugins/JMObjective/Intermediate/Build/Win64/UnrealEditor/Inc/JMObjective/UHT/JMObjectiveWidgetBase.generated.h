// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/JMObjectiveWidgetBase.h"

#ifdef JMOBJECTIVE_JMObjectiveWidgetBase_generated_h
#error "JMObjectiveWidgetBase.generated.h already included, missing '#pragma once' in JMObjectiveWidgetBase.h"
#endif
#define JMOBJECTIVE_JMObjectiveWidgetBase_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGameplayTag;
struct FJMObjectiveRuntimeState;

// ********** Begin Class UJMObjectiveWidgetBase ***************************************************
#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_UI_JMObjectiveWidgetBase_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetObjectiveState); \
	DECLARE_FUNCTION(execSetObjectiveState);


#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_UI_JMObjectiveWidgetBase_h_11_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UJMObjectiveWidgetBase_Statics;
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveWidgetBase_NoRegister();

#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_UI_JMObjectiveWidgetBase_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMObjectiveWidgetBase(); \
	friend struct ::Z_Construct_UClass_UJMObjectiveWidgetBase_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMOBJECTIVE_API UClass* ::Z_Construct_UClass_UJMObjectiveWidgetBase_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMObjectiveWidgetBase, UUserWidget, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/JMObjective"), Z_Construct_UClass_UJMObjectiveWidgetBase_NoRegister) \
	DECLARE_SERIALIZER(UJMObjectiveWidgetBase)


#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_UI_JMObjectiveWidgetBase_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMObjectiveWidgetBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMObjectiveWidgetBase(UJMObjectiveWidgetBase&&) = delete; \
	UJMObjectiveWidgetBase(const UJMObjectiveWidgetBase&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMObjectiveWidgetBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMObjectiveWidgetBase); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMObjectiveWidgetBase) \
	NO_API virtual ~UJMObjectiveWidgetBase();


#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_UI_JMObjectiveWidgetBase_h_8_PROLOG
#define FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_UI_JMObjectiveWidgetBase_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_UI_JMObjectiveWidgetBase_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_UI_JMObjectiveWidgetBase_h_11_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_UI_JMObjectiveWidgetBase_h_11_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_UI_JMObjectiveWidgetBase_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMObjectiveWidgetBase;

// ********** End Class UJMObjectiveWidgetBase *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_UI_JMObjectiveWidgetBase_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
