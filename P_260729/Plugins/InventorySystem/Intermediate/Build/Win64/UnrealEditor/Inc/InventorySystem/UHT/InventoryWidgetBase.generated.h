// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/InventoryWidgetBase.h"

#ifdef INVENTORYSYSTEM_InventoryWidgetBase_generated_h
#error "InventoryWidgetBase.generated.h already included, missing '#pragma once' in InventoryWidgetBase.h"
#endif
#define INVENTORYSYSTEM_InventoryWidgetBase_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UInventoryComponent;
class UInventoryUIComponent;
enum class EInventoryOperationResult : uint8;
struct FInventorySlot;

// ********** Begin Delegate FInventoryWidgetCloseRequestedSignature *******************************
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryWidgetBase_h_21_DELEGATE \
INVENTORYSYSTEM_API void FInventoryWidgetCloseRequestedSignature_DelegateWrapper(const FMulticastScriptDelegate& InventoryWidgetCloseRequestedSignature);


// ********** End Delegate FInventoryWidgetCloseRequestedSignature *********************************

// ********** Begin Delegate FInventoryWidgetTransitionFinishedSignature ***************************
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryWidgetBase_h_22_DELEGATE \
INVENTORYSYSTEM_API void FInventoryWidgetTransitionFinishedSignature_DelegateWrapper(const FMulticastScriptDelegate& InventoryWidgetTransitionFinishedSignature);


// ********** End Delegate FInventoryWidgetTransitionFinishedSignature *****************************

// ********** Begin Class UInventoryWidgetBase *****************************************************
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryWidgetBase_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleCloseClicked); \
	DECLARE_FUNCTION(execHandleInspectClicked); \
	DECLARE_FUNCTION(execHandleDropClicked); \
	DECLARE_FUNCTION(execHandleUseClicked); \
	DECLARE_FUNCTION(execHandleInventoryChanged); \
	DECLARE_FUNCTION(execIsClosing); \
	DECLARE_FUNCTION(execFocusSelectedSlot); \
	DECLARE_FUNCTION(execBeginInspectorReturnTransition); \
	DECLARE_FUNCTION(execBeginInspectTransition); \
	DECLARE_FUNCTION(execBeginCloseTransition); \
	DECLARE_FUNCTION(execBeginOpenTransition); \
	DECLARE_FUNCTION(execRefreshInventory); \
	DECLARE_FUNCTION(execRequestClose); \
	DECLARE_FUNCTION(execInspectSelectedItem); \
	DECLARE_FUNCTION(execDropSelectedItem); \
	DECLARE_FUNCTION(execUseSelectedItem); \
	DECLARE_FUNCTION(execGetInventoryComponent); \
	DECLARE_FUNCTION(execGetSelectedSlotIndex); \
	DECLARE_FUNCTION(execGetSelectedSlot); \
	DECLARE_FUNCTION(execSelectSlot); \
	DECLARE_FUNCTION(execInitializeInventory);


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryWidgetBase_h_31_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UInventoryWidgetBase_Statics;
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryWidgetBase_NoRegister();

#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryWidgetBase_h_31_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInventoryWidgetBase(); \
	friend struct ::Z_Construct_UClass_UInventoryWidgetBase_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend INVENTORYSYSTEM_API UClass* ::Z_Construct_UClass_UInventoryWidgetBase_NoRegister(); \
public: \
	DECLARE_CLASS2(UInventoryWidgetBase, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/InventorySystem"), Z_Construct_UClass_UInventoryWidgetBase_NoRegister) \
	DECLARE_SERIALIZER(UInventoryWidgetBase)


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryWidgetBase_h_31_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UInventoryWidgetBase(UInventoryWidgetBase&&) = delete; \
	UInventoryWidgetBase(const UInventoryWidgetBase&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryWidgetBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryWidgetBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryWidgetBase) \
	NO_API virtual ~UInventoryWidgetBase();


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryWidgetBase_h_28_PROLOG
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryWidgetBase_h_31_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryWidgetBase_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryWidgetBase_h_31_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryWidgetBase_h_31_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryWidgetBase_h_31_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UInventoryWidgetBase;

// ********** End Class UInventoryWidgetBase *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryWidgetBase_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
