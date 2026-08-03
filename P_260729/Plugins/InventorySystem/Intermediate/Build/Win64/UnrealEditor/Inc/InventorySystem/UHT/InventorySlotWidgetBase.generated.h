// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/InventorySlotWidgetBase.h"

#ifdef INVENTORYSYSTEM_InventorySlotWidgetBase_generated_h
#error "InventorySlotWidgetBase.generated.h already included, missing '#pragma once' in InventorySlotWidgetBase.h"
#endif
#define INVENTORYSYSTEM_InventorySlotWidgetBase_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UInventoryItemDefinition;
class UInventoryWidgetBase;

// ********** Begin Class UInventorySlotWidgetBase *************************************************
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventorySlotWidgetBase_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleSelectClicked); \
	DECLARE_FUNCTION(execShouldShowUnavailable); \
	DECLARE_FUNCTION(execFocusSlot); \
	DECLARE_FUNCTION(execGetQuantity); \
	DECLARE_FUNCTION(execGetItemDefinition); \
	DECLARE_FUNCTION(execGetSlotIndex); \
	DECLARE_FUNCTION(execSetSelected); \
	DECLARE_FUNCTION(execRefreshSlot); \
	DECLARE_FUNCTION(execInitializeSlot);


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventorySlotWidgetBase_h_25_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UInventorySlotWidgetBase_Statics;
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventorySlotWidgetBase_NoRegister();

#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventorySlotWidgetBase_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInventorySlotWidgetBase(); \
	friend struct ::Z_Construct_UClass_UInventorySlotWidgetBase_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend INVENTORYSYSTEM_API UClass* ::Z_Construct_UClass_UInventorySlotWidgetBase_NoRegister(); \
public: \
	DECLARE_CLASS2(UInventorySlotWidgetBase, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/InventorySystem"), Z_Construct_UClass_UInventorySlotWidgetBase_NoRegister) \
	DECLARE_SERIALIZER(UInventorySlotWidgetBase)


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventorySlotWidgetBase_h_25_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UInventorySlotWidgetBase(UInventorySlotWidgetBase&&) = delete; \
	UInventorySlotWidgetBase(const UInventorySlotWidgetBase&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventorySlotWidgetBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventorySlotWidgetBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventorySlotWidgetBase) \
	NO_API virtual ~UInventorySlotWidgetBase();


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventorySlotWidgetBase_h_22_PROLOG
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventorySlotWidgetBase_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventorySlotWidgetBase_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventorySlotWidgetBase_h_25_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventorySlotWidgetBase_h_25_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventorySlotWidgetBase_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UInventorySlotWidgetBase;

// ********** End Class UInventorySlotWidgetBase ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventorySlotWidgetBase_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
