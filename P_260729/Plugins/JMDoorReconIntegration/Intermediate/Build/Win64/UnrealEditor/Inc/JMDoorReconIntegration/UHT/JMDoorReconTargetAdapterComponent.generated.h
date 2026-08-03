// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/JMDoorReconTargetAdapterComponent.h"

#ifdef JMDOORRECONINTEGRATION_JMDoorReconTargetAdapterComponent_generated_h
#error "JMDoorReconTargetAdapterComponent.generated.h already included, missing '#pragma once' in JMDoorReconTargetAdapterComponent.h"
#endif
#define JMDOORRECONINTEGRATION_JMDoorReconTargetAdapterComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EJMDoorState : uint8;

// ********** Begin Class UJMDoorReconTargetAdapterComponent ***************************************
#define FID_P_260729_Plugins_JMDoorReconIntegration_Source_JMDoorReconIntegration_Public_Components_JMDoorReconTargetAdapterComponent_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleDoorStateChanged); \
	DECLARE_FUNCTION(execIsTemporaryPoseActive);


struct Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_Statics;
JMDOORRECONINTEGRATION_API UClass* Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_NoRegister();

#define FID_P_260729_Plugins_JMDoorReconIntegration_Source_JMDoorReconIntegration_Public_Components_JMDoorReconTargetAdapterComponent_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMDoorReconTargetAdapterComponent(); \
	friend struct ::Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMDOORRECONINTEGRATION_API UClass* ::Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMDoorReconTargetAdapterComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMDoorReconIntegration"), Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_NoRegister) \
	DECLARE_SERIALIZER(UJMDoorReconTargetAdapterComponent) \
	virtual UObject* _getUObject() const override { return const_cast<UJMDoorReconTargetAdapterComponent*>(this); }


#define FID_P_260729_Plugins_JMDoorReconIntegration_Source_JMDoorReconIntegration_Public_Components_JMDoorReconTargetAdapterComponent_h_20_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMDoorReconTargetAdapterComponent(UJMDoorReconTargetAdapterComponent&&) = delete; \
	UJMDoorReconTargetAdapterComponent(const UJMDoorReconTargetAdapterComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMDoorReconTargetAdapterComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMDoorReconTargetAdapterComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMDoorReconTargetAdapterComponent) \
	NO_API virtual ~UJMDoorReconTargetAdapterComponent();


#define FID_P_260729_Plugins_JMDoorReconIntegration_Source_JMDoorReconIntegration_Public_Components_JMDoorReconTargetAdapterComponent_h_15_PROLOG
#define FID_P_260729_Plugins_JMDoorReconIntegration_Source_JMDoorReconIntegration_Public_Components_JMDoorReconTargetAdapterComponent_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMDoorReconIntegration_Source_JMDoorReconIntegration_Public_Components_JMDoorReconTargetAdapterComponent_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoorReconIntegration_Source_JMDoorReconIntegration_Public_Components_JMDoorReconTargetAdapterComponent_h_20_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoorReconIntegration_Source_JMDoorReconIntegration_Public_Components_JMDoorReconTargetAdapterComponent_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMDoorReconTargetAdapterComponent;

// ********** End Class UJMDoorReconTargetAdapterComponent *****************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMDoorReconIntegration_Source_JMDoorReconIntegration_Public_Components_JMDoorReconTargetAdapterComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
