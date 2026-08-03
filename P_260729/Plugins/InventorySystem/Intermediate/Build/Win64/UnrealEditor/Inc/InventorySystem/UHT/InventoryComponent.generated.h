// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/InventoryComponent.h"

#ifdef INVENTORYSYSTEM_InventoryComponent_generated_h
#error "InventoryComponent.generated.h already included, missing '#pragma once' in InventoryComponent.h"
#endif
#define INVENTORYSYSTEM_InventoryComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UInventoryItemDefinition;
enum class EInventoryOperationResult : uint8;
struct FInventoryAddOutcome;
struct FInventorySaveEntry;
struct FInventorySlot;

// ********** Begin Delegate FInventoryChangedSignature ********************************************
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryComponent_h_10_DELEGATE \
INVENTORYSYSTEM_API void FInventoryChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& InventoryChangedSignature);


// ********** End Delegate FInventoryChangedSignature **********************************************

// ********** Begin Delegate FInventoryItemChangedSignature ****************************************
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryComponent_h_11_DELEGATE \
INVENTORYSYSTEM_API void FInventoryItemChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& InventoryItemChangedSignature, UInventoryItemDefinition* ItemDefinition, int32 Quantity, int32 SlotIndex);


// ********** End Delegate FInventoryItemChangedSignature ******************************************

// ********** Begin Delegate FInventoryItemsReceivedSignature **************************************
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryComponent_h_12_DELEGATE \
INVENTORYSYSTEM_API void FInventoryItemsReceivedSignature_DelegateWrapper(const FMulticastScriptDelegate& InventoryItemsReceivedSignature, UInventoryItemDefinition* ItemDefinition, int32 Quantity);


// ********** End Delegate FInventoryItemsReceivedSignature ****************************************

// ********** Begin Delegate FInventoryItemUsedSignature *******************************************
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryComponent_h_13_DELEGATE \
INVENTORYSYSTEM_API void FInventoryItemUsedSignature_DelegateWrapper(const FMulticastScriptDelegate& InventoryItemUsedSignature, UInventoryItemDefinition* ItemDefinition, int32 SlotIndex);


// ********** End Delegate FInventoryItemUsedSignature *********************************************

// ********** Begin Delegate FInventoryFullSignature ***********************************************
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryComponent_h_14_DELEGATE \
INVENTORYSYSTEM_API void FInventoryFullSignature_DelegateWrapper(const FMulticastScriptDelegate& InventoryFullSignature, UInventoryItemDefinition* ItemDefinition, int32 RejectedQuantity);


// ********** End Delegate FInventoryFullSignature *************************************************

// ********** Begin Class UInventoryComponent ******************************************************
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryComponent_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execMakeSaveEntries); \
	DECLARE_FUNCTION(execGetMaxInventorySlots); \
	DECLARE_FUNCTION(execGetOccupiedSlotCount); \
	DECLARE_FUNCTION(execGetSlot); \
	DECLARE_FUNCTION(execGetInventorySlots); \
	DECLARE_FUNCTION(execGetItemQuantity); \
	DECLARE_FUNCTION(execHasItem); \
	DECLARE_FUNCTION(execDropItemAtSlot); \
	DECLARE_FUNCTION(execUseItemAtSlot); \
	DECLARE_FUNCTION(execRemoveItemAtSlot); \
	DECLARE_FUNCTION(execRemoveItem); \
	DECLARE_FUNCTION(execAddItem); \
	DECLARE_FUNCTION(execAddItemDetailed);


struct Z_Construct_UClass_UInventoryComponent_Statics;
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryComponent_NoRegister();

#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryComponent_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInventoryComponent(); \
	friend struct ::Z_Construct_UClass_UInventoryComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend INVENTORYSYSTEM_API UClass* ::Z_Construct_UClass_UInventoryComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UInventoryComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/InventorySystem"), Z_Construct_UClass_UInventoryComponent_NoRegister) \
	DECLARE_SERIALIZER(UInventoryComponent)


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryComponent_h_19_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UInventoryComponent(UInventoryComponent&&) = delete; \
	UInventoryComponent(const UInventoryComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UInventoryComponent) \
	NO_API virtual ~UInventoryComponent();


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryComponent_h_16_PROLOG
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryComponent_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryComponent_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryComponent_h_19_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryComponent_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UInventoryComponent;

// ********** End Class UInventoryComponent ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
