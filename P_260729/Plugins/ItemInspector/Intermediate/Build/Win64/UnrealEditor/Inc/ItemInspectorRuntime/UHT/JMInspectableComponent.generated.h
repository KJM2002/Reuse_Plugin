// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ItemInspection/JMInspectableComponent.h"

#ifdef ITEMINSPECTORRUNTIME_JMInspectableComponent_generated_h
#error "JMInspectableComponent.generated.h already included, missing '#pragma once' in JMInspectableComponent.h"
#endif
#define ITEMINSPECTORRUNTIME_JMInspectableComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UJMItemInspectionData;
struct FJMInteractionContext;
struct FJMInteractionResult;

// ********** Begin Delegate FJMInspectableInspectionEvent *****************************************
#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMInspectableComponent_h_12_DELEGATE \
ITEMINSPECTORRUNTIME_API void FJMInspectableInspectionEvent_DelegateWrapper(const FMulticastScriptDelegate& JMInspectableInspectionEvent, UJMItemInspectionData* InspectionData);


// ********** End Delegate FJMInspectableInspectionEvent *******************************************

// ********** Begin Class UJMInspectableComponent **************************************************
#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMInspectableComponent_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool CanInspect_Implementation(FJMInteractionContext const& Context) const; \
	DECLARE_FUNCTION(execCanInspect); \
	DECLARE_FUNCTION(execTryOpenInspection);


#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMInspectableComponent_h_17_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UJMInspectableComponent_Statics;
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMInspectableComponent_NoRegister();

#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMInspectableComponent_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMInspectableComponent(); \
	friend struct ::Z_Construct_UClass_UJMInspectableComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ITEMINSPECTORRUNTIME_API UClass* ::Z_Construct_UClass_UJMInspectableComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMInspectableComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ItemInspectorRuntime"), Z_Construct_UClass_UJMInspectableComponent_NoRegister) \
	DECLARE_SERIALIZER(UJMInspectableComponent) \
	virtual UObject* _getUObject() const override { return const_cast<UJMInspectableComponent*>(this); }


#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMInspectableComponent_h_17_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMInspectableComponent(UJMInspectableComponent&&) = delete; \
	UJMInspectableComponent(const UJMInspectableComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMInspectableComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMInspectableComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMInspectableComponent) \
	NO_API virtual ~UJMInspectableComponent();


#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMInspectableComponent_h_14_PROLOG
#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMInspectableComponent_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMInspectableComponent_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMInspectableComponent_h_17_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMInspectableComponent_h_17_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMInspectableComponent_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMInspectableComponent;

// ********** End Class UJMInspectableComponent ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMInspectableComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
