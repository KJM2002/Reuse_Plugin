// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ItemInspection/JMItemInspectionSubsystem.h"

#ifdef ITEMINSPECTORRUNTIME_JMItemInspectionSubsystem_generated_h
#error "JMItemInspectionSubsystem.generated.h already included, missing '#pragma once' in JMItemInspectionSubsystem.h"
#endif
#define ITEMINSPECTORRUNTIME_JMItemInspectionSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UJMItemInspectionData;
enum class EJMItemInspectionCloseReason : uint8;
enum class EJMItemInspectionState : uint8;
struct FJMItemInspectionRequest;

// ********** Begin Delegate FJMItemInspectionOpenedSignature **************************************
#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionSubsystem_h_17_DELEGATE \
ITEMINSPECTORRUNTIME_API void FJMItemInspectionOpenedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMItemInspectionOpenedSignature, UJMItemInspectionData* InspectionData);


// ********** End Delegate FJMItemInspectionOpenedSignature ****************************************

// ********** Begin Delegate FJMItemInspectionClosedSignature **************************************
#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionSubsystem_h_18_DELEGATE \
ITEMINSPECTORRUNTIME_API void FJMItemInspectionClosedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMItemInspectionClosedSignature, EJMItemInspectionCloseReason Reason);


// ********** End Delegate FJMItemInspectionClosedSignature ****************************************

// ********** Begin Delegate FJMItemInspectionFailedSignature **************************************
#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionSubsystem_h_19_DELEGATE \
ITEMINSPECTORRUNTIME_API void FJMItemInspectionFailedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMItemInspectionFailedSignature, UJMItemInspectionData* InspectionData, const FText& Reason);


// ********** End Delegate FJMItemInspectionFailedSignature ****************************************

// ********** Begin Class UJMItemInspectionSubsystem ***********************************************
#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionSubsystem_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandlePreviewZoomed); \
	DECLARE_FUNCTION(execHandlePreviewDragged); \
	DECLARE_FUNCTION(execHandleWidgetCloseRequested); \
	DECLARE_FUNCTION(execResetPreviewRotation); \
	DECLARE_FUNCTION(execGetInspectionState); \
	DECLARE_FUNCTION(execGetCurrentInspectionData); \
	DECLARE_FUNCTION(execIsInspectionOpen); \
	DECLARE_FUNCTION(execCloseInspection); \
	DECLARE_FUNCTION(execOpenInspectionFromRequest); \
	DECLARE_FUNCTION(execOpenInspection);


struct Z_Construct_UClass_UJMItemInspectionSubsystem_Statics;
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMItemInspectionSubsystem_NoRegister();

#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionSubsystem_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMItemInspectionSubsystem(); \
	friend struct ::Z_Construct_UClass_UJMItemInspectionSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ITEMINSPECTORRUNTIME_API UClass* ::Z_Construct_UClass_UJMItemInspectionSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMItemInspectionSubsystem, ULocalPlayerSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ItemInspectorRuntime"), Z_Construct_UClass_UJMItemInspectionSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UJMItemInspectionSubsystem)


#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionSubsystem_h_24_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMItemInspectionSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMItemInspectionSubsystem(UJMItemInspectionSubsystem&&) = delete; \
	UJMItemInspectionSubsystem(const UJMItemInspectionSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMItemInspectionSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMItemInspectionSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMItemInspectionSubsystem) \
	NO_API virtual ~UJMItemInspectionSubsystem();


#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionSubsystem_h_21_PROLOG
#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionSubsystem_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionSubsystem_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionSubsystem_h_24_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionSubsystem_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMItemInspectionSubsystem;

// ********** End Class UJMItemInspectionSubsystem *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
