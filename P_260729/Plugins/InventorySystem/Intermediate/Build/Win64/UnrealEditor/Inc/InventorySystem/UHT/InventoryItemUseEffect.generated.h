// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Items/InventoryItemUseEffect.h"

#ifdef INVENTORYSYSTEM_InventoryItemUseEffect_generated_h
#error "InventoryItemUseEffect.generated.h already included, missing '#pragma once' in InventoryItemUseEffect.h"
#endif
#define INVENTORYSYSTEM_InventoryItemUseEffect_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UInventoryComponent;
struct FInventorySlot;

// ********** Begin Class UInventoryItemUseEffect **************************************************
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemUseEffect_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execExecuteUse); \
	DECLARE_FUNCTION(execCanUse);


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemUseEffect_h_13_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UInventoryItemUseEffect_Statics;
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemUseEffect_NoRegister();

#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemUseEffect_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInventoryItemUseEffect(); \
	friend struct ::Z_Construct_UClass_UInventoryItemUseEffect_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend INVENTORYSYSTEM_API UClass* ::Z_Construct_UClass_UInventoryItemUseEffect_NoRegister(); \
public: \
	DECLARE_CLASS2(UInventoryItemUseEffect, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/InventorySystem"), Z_Construct_UClass_UInventoryItemUseEffect_NoRegister) \
	DECLARE_SERIALIZER(UInventoryItemUseEffect)


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemUseEffect_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventoryItemUseEffect(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UInventoryItemUseEffect(UInventoryItemUseEffect&&) = delete; \
	UInventoryItemUseEffect(const UInventoryItemUseEffect&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryItemUseEffect); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryItemUseEffect); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryItemUseEffect) \
	NO_API virtual ~UInventoryItemUseEffect();


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemUseEffect_h_10_PROLOG
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemUseEffect_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemUseEffect_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemUseEffect_h_13_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemUseEffect_h_13_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemUseEffect_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UInventoryItemUseEffect;

// ********** End Class UInventoryItemUseEffect ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemUseEffect_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
