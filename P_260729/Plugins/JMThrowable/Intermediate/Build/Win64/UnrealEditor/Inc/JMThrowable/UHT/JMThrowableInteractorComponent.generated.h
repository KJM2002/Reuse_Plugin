// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "JMThrowableInteractorComponent.h"

#ifdef JMTHROWABLE_JMThrowableInteractorComponent_generated_h
#error "JMThrowableInteractorComponent.generated.h already included, missing '#pragma once' in JMThrowableInteractorComponent.h"
#endif
#define JMTHROWABLE_JMThrowableInteractorComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EJMThrowableUseState : uint8;
struct FGuid;
struct FJMThrowableUseContext;
struct FJMThrowResult;
struct FJMThrowSimulationResult;

// ********** Begin Class UJMThrowableInteractorComponent ******************************************
#define FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableInteractorComponent_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetPreviewResult); \
	DECLARE_FUNCTION(execGetSessionId); \
	DECLARE_FUNCTION(execGetUseState); \
	DECLARE_FUNCTION(execCancelItemUse); \
	DECLARE_FUNCTION(execTryCommitThrow); \
	DECLARE_FUNCTION(execEndAim); \
	DECLARE_FUNCTION(execBeginAim); \
	DECLARE_FUNCTION(execBeginItemUse);


struct Z_Construct_UClass_UJMThrowableInteractorComponent_Statics;
JMTHROWABLE_API UClass* Z_Construct_UClass_UJMThrowableInteractorComponent_NoRegister();

#define FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableInteractorComponent_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMThrowableInteractorComponent(); \
	friend struct ::Z_Construct_UClass_UJMThrowableInteractorComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMTHROWABLE_API UClass* ::Z_Construct_UClass_UJMThrowableInteractorComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMThrowableInteractorComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMThrowable"), Z_Construct_UClass_UJMThrowableInteractorComponent_NoRegister) \
	DECLARE_SERIALIZER(UJMThrowableInteractorComponent)


#define FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableInteractorComponent_h_23_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMThrowableInteractorComponent(UJMThrowableInteractorComponent&&) = delete; \
	UJMThrowableInteractorComponent(const UJMThrowableInteractorComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMThrowableInteractorComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMThrowableInteractorComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMThrowableInteractorComponent) \
	NO_API virtual ~UJMThrowableInteractorComponent();


#define FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableInteractorComponent_h_20_PROLOG
#define FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableInteractorComponent_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableInteractorComponent_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableInteractorComponent_h_23_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableInteractorComponent_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMThrowableInteractorComponent;

// ********** End Class UJMThrowableInteractorComponent ********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableInteractorComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
