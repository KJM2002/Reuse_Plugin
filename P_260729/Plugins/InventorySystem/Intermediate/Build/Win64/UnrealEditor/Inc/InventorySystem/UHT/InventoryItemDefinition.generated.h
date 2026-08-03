// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Items/InventoryItemDefinition.h"

#ifdef INVENTORYSYSTEM_InventoryItemDefinition_generated_h
#error "InventoryItemDefinition.generated.h already included, missing '#pragma once' in InventoryItemDefinition.h"
#endif
#define INVENTORYSYSTEM_InventoryItemDefinition_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UInventoryItemDefinition *************************************************
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemDefinition_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetEffectiveMaxStackSize);


struct Z_Construct_UClass_UInventoryItemDefinition_Statics;
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemDefinition_NoRegister();

#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemDefinition_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInventoryItemDefinition(); \
	friend struct ::Z_Construct_UClass_UInventoryItemDefinition_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend INVENTORYSYSTEM_API UClass* ::Z_Construct_UClass_UInventoryItemDefinition_NoRegister(); \
public: \
	DECLARE_CLASS2(UInventoryItemDefinition, UPrimaryDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/InventorySystem"), Z_Construct_UClass_UInventoryItemDefinition_NoRegister) \
	DECLARE_SERIALIZER(UInventoryItemDefinition)


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemDefinition_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventoryItemDefinition(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UInventoryItemDefinition(UInventoryItemDefinition&&) = delete; \
	UInventoryItemDefinition(const UInventoryItemDefinition&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryItemDefinition); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryItemDefinition); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryItemDefinition) \
	NO_API virtual ~UInventoryItemDefinition();


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemDefinition_h_15_PROLOG
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemDefinition_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemDefinition_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemDefinition_h_18_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemDefinition_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UInventoryItemDefinition;

// ********** End Class UInventoryItemDefinition ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemDefinition_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
