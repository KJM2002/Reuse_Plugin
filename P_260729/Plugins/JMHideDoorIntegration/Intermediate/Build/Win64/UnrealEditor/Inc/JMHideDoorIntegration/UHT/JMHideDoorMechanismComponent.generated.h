// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/JMHideDoorMechanismComponent.h"

#ifdef JMHIDEDOORINTEGRATION_JMHideDoorMechanismComponent_generated_h
#error "JMHideDoorMechanismComponent.generated.h already included, missing '#pragma once' in JMHideDoorMechanismComponent.h"
#endif
#define JMHIDEDOORINTEGRATION_JMHideDoorMechanismComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EJMDoorState : uint8;

// ********** Begin Class UJMHideDoorMechanismComponent ********************************************
#define FID_P_260729_Plugins_JMHideDoorIntegration_Source_JMHideDoorIntegration_Public_Components_JMHideDoorMechanismComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleDoorStateChanged);


struct Z_Construct_UClass_UJMHideDoorMechanismComponent_Statics;
JMHIDEDOORINTEGRATION_API UClass* Z_Construct_UClass_UJMHideDoorMechanismComponent_NoRegister();

#define FID_P_260729_Plugins_JMHideDoorIntegration_Source_JMHideDoorIntegration_Public_Components_JMHideDoorMechanismComponent_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMHideDoorMechanismComponent(); \
	friend struct ::Z_Construct_UClass_UJMHideDoorMechanismComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMHIDEDOORINTEGRATION_API UClass* ::Z_Construct_UClass_UJMHideDoorMechanismComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMHideDoorMechanismComponent, UJMHideMechanismComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMHideDoorIntegration"), Z_Construct_UClass_UJMHideDoorMechanismComponent_NoRegister) \
	DECLARE_SERIALIZER(UJMHideDoorMechanismComponent)


#define FID_P_260729_Plugins_JMHideDoorIntegration_Source_JMHideDoorIntegration_Public_Components_JMHideDoorMechanismComponent_h_13_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMHideDoorMechanismComponent(UJMHideDoorMechanismComponent&&) = delete; \
	UJMHideDoorMechanismComponent(const UJMHideDoorMechanismComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMHideDoorMechanismComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMHideDoorMechanismComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMHideDoorMechanismComponent) \
	NO_API virtual ~UJMHideDoorMechanismComponent();


#define FID_P_260729_Plugins_JMHideDoorIntegration_Source_JMHideDoorIntegration_Public_Components_JMHideDoorMechanismComponent_h_10_PROLOG
#define FID_P_260729_Plugins_JMHideDoorIntegration_Source_JMHideDoorIntegration_Public_Components_JMHideDoorMechanismComponent_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMHideDoorIntegration_Source_JMHideDoorIntegration_Public_Components_JMHideDoorMechanismComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMHideDoorIntegration_Source_JMHideDoorIntegration_Public_Components_JMHideDoorMechanismComponent_h_13_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMHideDoorIntegration_Source_JMHideDoorIntegration_Public_Components_JMHideDoorMechanismComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMHideDoorMechanismComponent;

// ********** End Class UJMHideDoorMechanismComponent **********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMHideDoorIntegration_Source_JMHideDoorIntegration_Public_Components_JMHideDoorMechanismComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
