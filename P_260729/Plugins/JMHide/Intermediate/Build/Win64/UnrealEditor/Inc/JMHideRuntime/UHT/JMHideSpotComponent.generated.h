// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/JMHideSpotComponent.h"

#ifdef JMHIDERUNTIME_JMHideSpotComponent_generated_h
#error "JMHideSpotComponent.generated.h already included, missing '#pragma once' in JMHideSpotComponent.h"
#endif
#define JMHIDERUNTIME_JMHideSpotComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EJMHideSpotState : uint8;

// ********** Begin Delegate FJMHideSpotStateChangedSignature **************************************
#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSpotComponent_h_13_DELEGATE \
JMHIDERUNTIME_API void FJMHideSpotStateChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMHideSpotStateChangedSignature, EJMHideSpotState OldState, EJMHideSpotState NewState);


// ********** End Delegate FJMHideSpotStateChangedSignature ****************************************

// ********** Begin Class UJMHideSpotComponent *****************************************************
#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSpotComponent_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execValidateConfiguration); \
	DECLARE_FUNCTION(execIsAvailable); \
	DECLARE_FUNCTION(execGetSpotState);


struct Z_Construct_UClass_UJMHideSpotComponent_Statics;
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideSpotComponent_NoRegister();

#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSpotComponent_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMHideSpotComponent(); \
	friend struct ::Z_Construct_UClass_UJMHideSpotComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMHIDERUNTIME_API UClass* ::Z_Construct_UClass_UJMHideSpotComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMHideSpotComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMHideRuntime"), Z_Construct_UClass_UJMHideSpotComponent_NoRegister) \
	DECLARE_SERIALIZER(UJMHideSpotComponent)


#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSpotComponent_h_18_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMHideSpotComponent(UJMHideSpotComponent&&) = delete; \
	UJMHideSpotComponent(const UJMHideSpotComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMHideSpotComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMHideSpotComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMHideSpotComponent) \
	NO_API virtual ~UJMHideSpotComponent();


#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSpotComponent_h_15_PROLOG
#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSpotComponent_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSpotComponent_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSpotComponent_h_18_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSpotComponent_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMHideSpotComponent;

// ********** End Class UJMHideSpotComponent *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSpotComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
