// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/JMFootstepComponent.h"

#ifdef JMFOOTSTEPRUNTIME_JMFootstepComponent_generated_h
#error "JMFootstepComponent.generated.h already included, missing '#pragma once' in JMFootstepComponent.h"
#endif
#define JMFOOTSTEPRUNTIME_JMFootstepComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EJMFootstepLocomotionState : uint8;
struct FJMFootstepContext;
struct FJMFootstepResult;

// ********** Begin Delegate FJMFootstepPlayedSignature ********************************************
#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Components_JMFootstepComponent_h_18_DELEGATE \
JMFOOTSTEPRUNTIME_API void FJMFootstepPlayedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMFootstepPlayedSignature, FJMFootstepResult const& Result);


// ********** End Delegate FJMFootstepPlayedSignature **********************************************

// ********** Begin ScriptStruct FJMFootstepVariantSoundHistory ************************************
struct Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory_Statics;
#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Components_JMFootstepComponent_h_23_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMFootstepVariantSoundHistory_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMFootstepVariantSoundHistory;
// ********** End ScriptStruct FJMFootstepVariantSoundHistory **************************************

// ********** Begin Class UJMFootstepComponent *****************************************************
#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Components_JMFootstepComponent_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execResetFootstepState); \
	DECLARE_FUNCTION(execGetAccumulatedDistance); \
	DECLARE_FUNCTION(execGetCurrentLocomotionState); \
	DECLARE_FUNCTION(execHasLocomotionStateOverride); \
	DECLARE_FUNCTION(execClearLocomotionStateOverride); \
	DECLARE_FUNCTION(execSetLocomotionStateOverride); \
	DECLARE_FUNCTION(execRequestFootstep); \
	DECLARE_FUNCTION(execTriggerFootstep);


struct Z_Construct_UClass_UJMFootstepComponent_Statics;
JMFOOTSTEPRUNTIME_API UClass* Z_Construct_UClass_UJMFootstepComponent_NoRegister();

#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Components_JMFootstepComponent_h_45_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMFootstepComponent(); \
	friend struct ::Z_Construct_UClass_UJMFootstepComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMFOOTSTEPRUNTIME_API UClass* ::Z_Construct_UClass_UJMFootstepComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMFootstepComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMFootstepRuntime"), Z_Construct_UClass_UJMFootstepComponent_NoRegister) \
	DECLARE_SERIALIZER(UJMFootstepComponent)


#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Components_JMFootstepComponent_h_45_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMFootstepComponent(UJMFootstepComponent&&) = delete; \
	UJMFootstepComponent(const UJMFootstepComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMFootstepComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMFootstepComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMFootstepComponent) \
	NO_API virtual ~UJMFootstepComponent();


#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Components_JMFootstepComponent_h_42_PROLOG
#define FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Components_JMFootstepComponent_h_45_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Components_JMFootstepComponent_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Components_JMFootstepComponent_h_45_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Components_JMFootstepComponent_h_45_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMFootstepComponent;

// ********** End Class UJMFootstepComponent *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Components_JMFootstepComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
