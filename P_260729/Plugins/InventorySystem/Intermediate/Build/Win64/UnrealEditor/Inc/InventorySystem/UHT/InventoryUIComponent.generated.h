// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/InventoryUIComponent.h"

#ifdef INVENTORYSYSTEM_InventoryUIComponent_generated_h
#error "InventoryUIComponent.generated.h already included, missing '#pragma once' in InventoryUIComponent.h"
#endif
#define INVENTORYSYSTEM_InventoryUIComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UEnhancedInputComponent;
class UInventoryItemDefinition;
class UInventoryWidgetBase;
struct FKey;

// ********** Begin Delegate FInventoryUIStateSignature ********************************************
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryUIComponent_h_18_DELEGATE \
INVENTORYSYSTEM_API void FInventoryUIStateSignature_DelegateWrapper(const FMulticastScriptDelegate& InventoryUIStateSignature);


// ********** End Delegate FInventoryUIStateSignature **********************************************

// ********** Begin Delegate FInventoryUIPresentationSignature *************************************
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryUIComponent_h_19_DELEGATE \
INVENTORYSYSTEM_API void FInventoryUIPresentationSignature_DelegateWrapper(const FMulticastScriptDelegate& InventoryUIPresentationSignature, bool bInventoryVisible);


// ********** End Delegate FInventoryUIPresentationSignature ***************************************

// ********** Begin Class UInventoryUIComponent ****************************************************
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryUIComponent_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleItemsReceived); \
	DECLARE_FUNCTION(execHandleInspectorClosed); \
	DECLARE_FUNCTION(execHandleWidgetInspectTransitionFinished); \
	DECLARE_FUNCTION(execHandleWidgetCloseTransitionFinished); \
	DECLARE_FUNCTION(execHandleWidgetCloseRequested); \
	DECLARE_FUNCTION(execHandleToggleInput); \
	DECLARE_FUNCTION(execIsToggleInventoryKey); \
	DECLARE_FUNCTION(execGetInventoryWidget); \
	DECLARE_FUNCTION(execInspectItem); \
	DECLARE_FUNCTION(execIsInventoryOpen); \
	DECLARE_FUNCTION(execToggleInventory); \
	DECLARE_FUNCTION(execCloseInventory); \
	DECLARE_FUNCTION(execOpenInventory); \
	DECLARE_FUNCTION(execBindEnhancedInput);


struct Z_Construct_UClass_UInventoryUIComponent_Statics;
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryUIComponent_NoRegister();

#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryUIComponent_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInventoryUIComponent(); \
	friend struct ::Z_Construct_UClass_UInventoryUIComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend INVENTORYSYSTEM_API UClass* ::Z_Construct_UClass_UInventoryUIComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UInventoryUIComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/InventorySystem"), Z_Construct_UClass_UInventoryUIComponent_NoRegister) \
	DECLARE_SERIALIZER(UInventoryUIComponent)


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryUIComponent_h_24_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UInventoryUIComponent(UInventoryUIComponent&&) = delete; \
	UInventoryUIComponent(const UInventoryUIComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryUIComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryUIComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UInventoryUIComponent) \
	NO_API virtual ~UInventoryUIComponent();


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryUIComponent_h_21_PROLOG
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryUIComponent_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryUIComponent_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryUIComponent_h_24_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryUIComponent_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UInventoryUIComponent;

// ********** End Class UInventoryUIComponent ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryUIComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
