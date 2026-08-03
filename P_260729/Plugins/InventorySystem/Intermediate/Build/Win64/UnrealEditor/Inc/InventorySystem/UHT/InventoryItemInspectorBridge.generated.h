// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Interfaces/InventoryItemInspectorBridge.h"

#ifdef INVENTORYSYSTEM_InventoryItemInspectorBridge_generated_h
#error "InventoryItemInspectorBridge.generated.h already included, missing '#pragma once' in InventoryItemInspectorBridge.h"
#endif
#define INVENTORYSYSTEM_InventoryItemInspectorBridge_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APlayerController;
class UInventoryItemDefinition;

// ********** Begin Delegate FInventoryInspectorClosedSignature ************************************
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemInspectorBridge_h_9_DELEGATE \
INVENTORYSYSTEM_API void FInventoryInspectorClosedSignature_DelegateWrapper(const FMulticastScriptDelegate& InventoryInspectorClosedSignature);


// ********** End Delegate FInventoryInspectorClosedSignature **************************************

// ********** Begin Class UInventoryItemInspectorBridge ********************************************
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemInspectorBridge_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execNotifyInspectorClosed); \
	DECLARE_FUNCTION(execIsInspectorOpen); \
	DECLARE_FUNCTION(execCloseInspector); \
	DECLARE_FUNCTION(execOpenInspector);


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemInspectorBridge_h_14_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UInventoryItemInspectorBridge_Statics;
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemInspectorBridge_NoRegister();

#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemInspectorBridge_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInventoryItemInspectorBridge(); \
	friend struct ::Z_Construct_UClass_UInventoryItemInspectorBridge_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend INVENTORYSYSTEM_API UClass* ::Z_Construct_UClass_UInventoryItemInspectorBridge_NoRegister(); \
public: \
	DECLARE_CLASS2(UInventoryItemInspectorBridge, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/InventorySystem"), Z_Construct_UClass_UInventoryItemInspectorBridge_NoRegister) \
	DECLARE_SERIALIZER(UInventoryItemInspectorBridge)


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemInspectorBridge_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventoryItemInspectorBridge(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UInventoryItemInspectorBridge(UInventoryItemInspectorBridge&&) = delete; \
	UInventoryItemInspectorBridge(const UInventoryItemInspectorBridge&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryItemInspectorBridge); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryItemInspectorBridge); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryItemInspectorBridge) \
	NO_API virtual ~UInventoryItemInspectorBridge();


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemInspectorBridge_h_11_PROLOG
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemInspectorBridge_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemInspectorBridge_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemInspectorBridge_h_14_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemInspectorBridge_h_14_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemInspectorBridge_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UInventoryItemInspectorBridge;

// ********** End Class UInventoryItemInspectorBridge **********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemInspectorBridge_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
