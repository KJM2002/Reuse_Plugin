// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Integration/ReuseInventoryInspectorBridge.h"

#ifdef INVENTORYSYSTEM_ReuseInventoryInspectorBridge_generated_h
#error "ReuseInventoryInspectorBridge.generated.h already included, missing '#pragma once' in ReuseInventoryInspectorBridge.h"
#endif
#define INVENTORYSYSTEM_ReuseInventoryInspectorBridge_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EJMItemInspectionCloseReason : uint8;

// ********** Begin Class UReuseInventoryInspectorBridge *******************************************
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Integration_ReuseInventoryInspectorBridge_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleInspectionClosed);


struct Z_Construct_UClass_UReuseInventoryInspectorBridge_Statics;
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UReuseInventoryInspectorBridge_NoRegister();

#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Integration_ReuseInventoryInspectorBridge_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUReuseInventoryInspectorBridge(); \
	friend struct ::Z_Construct_UClass_UReuseInventoryInspectorBridge_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend INVENTORYSYSTEM_API UClass* ::Z_Construct_UClass_UReuseInventoryInspectorBridge_NoRegister(); \
public: \
	DECLARE_CLASS2(UReuseInventoryInspectorBridge, UInventoryItemInspectorBridge, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/InventorySystem"), Z_Construct_UClass_UReuseInventoryInspectorBridge_NoRegister) \
	DECLARE_SERIALIZER(UReuseInventoryInspectorBridge)


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Integration_ReuseInventoryInspectorBridge_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UReuseInventoryInspectorBridge(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UReuseInventoryInspectorBridge(UReuseInventoryInspectorBridge&&) = delete; \
	UReuseInventoryInspectorBridge(const UReuseInventoryInspectorBridge&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UReuseInventoryInspectorBridge); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UReuseInventoryInspectorBridge); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UReuseInventoryInspectorBridge) \
	NO_API virtual ~UReuseInventoryInspectorBridge();


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Integration_ReuseInventoryInspectorBridge_h_14_PROLOG
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Integration_ReuseInventoryInspectorBridge_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Integration_ReuseInventoryInspectorBridge_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Integration_ReuseInventoryInspectorBridge_h_17_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Integration_ReuseInventoryInspectorBridge_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UReuseInventoryInspectorBridge;

// ********** End Class UReuseInventoryInspectorBridge *********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Integration_ReuseInventoryInspectorBridge_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
