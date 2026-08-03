// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/JMReconTargetComponent.h"

#ifdef JMRECONRUNTIME_JMReconTargetComponent_generated_h
#error "JMReconTargetComponent.generated.h already included, missing '#pragma once' in JMReconTargetComponent.h"
#endif
#define JMRECONRUNTIME_JMReconTargetComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UJMReconDefinition;
enum class EJMReconMode : uint8;

// ********** Begin Class UJMReconTargetComponent **************************************************
#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconTargetComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSupportsMode); \
	DECLARE_FUNCTION(execGetPeekCameraWorldTransform); \
	DECLARE_FUNCTION(execGetListenCameraWorldTransform); \
	DECLARE_FUNCTION(execGetPlayerWorldTransform); \
	DECLARE_FUNCTION(execGetEffectiveDefinition);


struct Z_Construct_UClass_UJMReconTargetComponent_Statics;
JMRECONRUNTIME_API UClass* Z_Construct_UClass_UJMReconTargetComponent_NoRegister();

#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconTargetComponent_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMReconTargetComponent(); \
	friend struct ::Z_Construct_UClass_UJMReconTargetComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMRECONRUNTIME_API UClass* ::Z_Construct_UClass_UJMReconTargetComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMReconTargetComponent, USceneComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMReconRuntime"), Z_Construct_UClass_UJMReconTargetComponent_NoRegister) \
	DECLARE_SERIALIZER(UJMReconTargetComponent)


#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconTargetComponent_h_13_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMReconTargetComponent(UJMReconTargetComponent&&) = delete; \
	UJMReconTargetComponent(const UJMReconTargetComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMReconTargetComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMReconTargetComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMReconTargetComponent) \
	NO_API virtual ~UJMReconTargetComponent();


#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconTargetComponent_h_10_PROLOG
#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconTargetComponent_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconTargetComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconTargetComponent_h_13_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconTargetComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMReconTargetComponent;

// ********** End Class UJMReconTargetComponent ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconTargetComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
