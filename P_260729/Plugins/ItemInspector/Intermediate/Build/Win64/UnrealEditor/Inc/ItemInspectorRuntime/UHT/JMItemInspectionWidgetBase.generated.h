// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ItemInspection/JMItemInspectionWidgetBase.h"

#ifdef ITEMINSPECTORRUNTIME_JMItemInspectionWidgetBase_generated_h
#error "JMItemInspectionWidgetBase.generated.h already included, missing '#pragma once' in JMItemInspectionWidgetBase.h"
#endif
#define ITEMINSPECTORRUNTIME_JMItemInspectionWidgetBase_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UJMItemInspectionData;
class UTexture;
enum class EJMItemInspectionCloseReason : uint8;

// ********** Begin Delegate FJMItemInspectionCloseRequestedSignature ******************************
#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionWidgetBase_h_18_DELEGATE \
ITEMINSPECTORRUNTIME_API void FJMItemInspectionCloseRequestedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMItemInspectionCloseRequestedSignature, EJMItemInspectionCloseReason Reason);


// ********** End Delegate FJMItemInspectionCloseRequestedSignature ********************************

// ********** Begin Delegate FJMItemInspectionPreviewDraggedSignature ******************************
#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionWidgetBase_h_19_DELEGATE \
ITEMINSPECTORRUNTIME_API void FJMItemInspectionPreviewDraggedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMItemInspectionPreviewDraggedSignature, float ScreenDeltaX, float ScreenDeltaY);


// ********** End Delegate FJMItemInspectionPreviewDraggedSignature ********************************

// ********** Begin Delegate FJMItemInspectionPreviewZoomedSignature *******************************
#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionWidgetBase_h_20_DELEGATE \
ITEMINSPECTORRUNTIME_API void FJMItemInspectionPreviewZoomedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMItemInspectionPreviewZoomedSignature, float WheelDelta);


// ********** End Delegate FJMItemInspectionPreviewZoomedSignature *********************************

// ********** Begin Class UJMItemInspectionWidgetBase **********************************************
#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionWidgetBase_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleCloseButtonClicked); \
	DECLARE_FUNCTION(execRequestClose); \
	DECLARE_FUNCTION(execSetPreviewStatusText); \
	DECLARE_FUNCTION(execSetPreviewTexture); \
	DECLARE_FUNCTION(execSetAdditionalInfo); \
	DECLARE_FUNCTION(execSetDescription); \
	DECLARE_FUNCTION(execSetCategoryText); \
	DECLARE_FUNCTION(execSetItemName); \
	DECLARE_FUNCTION(execSetInspectionData);


#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionWidgetBase_h_25_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics;
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMItemInspectionWidgetBase_NoRegister();

#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionWidgetBase_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMItemInspectionWidgetBase(); \
	friend struct ::Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ITEMINSPECTORRUNTIME_API UClass* ::Z_Construct_UClass_UJMItemInspectionWidgetBase_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMItemInspectionWidgetBase, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ItemInspectorRuntime"), Z_Construct_UClass_UJMItemInspectionWidgetBase_NoRegister) \
	DECLARE_SERIALIZER(UJMItemInspectionWidgetBase)


#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionWidgetBase_h_25_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMItemInspectionWidgetBase(UJMItemInspectionWidgetBase&&) = delete; \
	UJMItemInspectionWidgetBase(const UJMItemInspectionWidgetBase&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMItemInspectionWidgetBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMItemInspectionWidgetBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMItemInspectionWidgetBase) \
	NO_API virtual ~UJMItemInspectionWidgetBase();


#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionWidgetBase_h_22_PROLOG
#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionWidgetBase_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionWidgetBase_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionWidgetBase_h_25_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionWidgetBase_h_25_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionWidgetBase_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMItemInspectionWidgetBase;

// ********** End Class UJMItemInspectionWidgetBase ************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionWidgetBase_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
