// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Integration/ReuseInspectableInventoryPickup.h"

#ifdef INVENTORYSYSTEM_ReuseInspectableInventoryPickup_generated_h
#error "ReuseInspectableInventoryPickup.generated.h already included, missing '#pragma once' in ReuseInspectableInventoryPickup.h"
#endif
#define INVENTORYSYSTEM_ReuseInspectableInventoryPickup_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EJMItemInspectionCloseReason : uint8;

// ********** Begin Class AReuseInspectableInventoryPickup *****************************************
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Integration_ReuseInspectableInventoryPickup_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleInspectionClosed);


struct Z_Construct_UClass_AReuseInspectableInventoryPickup_Statics;
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_AReuseInspectableInventoryPickup_NoRegister();

#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Integration_ReuseInspectableInventoryPickup_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAReuseInspectableInventoryPickup(); \
	friend struct ::Z_Construct_UClass_AReuseInspectableInventoryPickup_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend INVENTORYSYSTEM_API UClass* ::Z_Construct_UClass_AReuseInspectableInventoryPickup_NoRegister(); \
public: \
	DECLARE_CLASS2(AReuseInspectableInventoryPickup, AInventoryWorldItemPickup, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/InventorySystem"), Z_Construct_UClass_AReuseInspectableInventoryPickup_NoRegister) \
	DECLARE_SERIALIZER(AReuseInspectableInventoryPickup)


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Integration_ReuseInspectableInventoryPickup_h_19_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AReuseInspectableInventoryPickup(AReuseInspectableInventoryPickup&&) = delete; \
	AReuseInspectableInventoryPickup(const AReuseInspectableInventoryPickup&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AReuseInspectableInventoryPickup); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AReuseInspectableInventoryPickup); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AReuseInspectableInventoryPickup) \
	NO_API virtual ~AReuseInspectableInventoryPickup();


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Integration_ReuseInspectableInventoryPickup_h_16_PROLOG
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Integration_ReuseInspectableInventoryPickup_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Integration_ReuseInspectableInventoryPickup_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Integration_ReuseInspectableInventoryPickup_h_19_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Integration_ReuseInspectableInventoryPickup_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AReuseInspectableInventoryPickup;

// ********** End Class AReuseInspectableInventoryPickup *******************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Integration_ReuseInspectableInventoryPickup_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
