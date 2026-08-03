// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "World/InventoryWorldItemPickup.h"

#ifdef INVENTORYSYSTEM_InventoryWorldItemPickup_generated_h
#error "InventoryWorldItemPickup.generated.h already included, missing '#pragma once' in InventoryWorldItemPickup.h"
#endif
#define INVENTORYSYSTEM_InventoryWorldItemPickup_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UInventoryItemDefinition;

// ********** Begin Class AInventoryWorldItemPickup ************************************************
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_World_InventoryWorldItemPickup_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnPickupStateChanged); \
	DECLARE_FUNCTION(execTryPickup); \
	DECLARE_FUNCTION(execSnapToGround); \
	DECLARE_FUNCTION(execInitializePickup);


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_World_InventoryWorldItemPickup_h_16_CALLBACK_WRAPPERS
struct Z_Construct_UClass_AInventoryWorldItemPickup_Statics;
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_AInventoryWorldItemPickup_NoRegister();

#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_World_InventoryWorldItemPickup_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAInventoryWorldItemPickup(); \
	friend struct ::Z_Construct_UClass_AInventoryWorldItemPickup_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend INVENTORYSYSTEM_API UClass* ::Z_Construct_UClass_AInventoryWorldItemPickup_NoRegister(); \
public: \
	DECLARE_CLASS2(AInventoryWorldItemPickup, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/InventorySystem"), Z_Construct_UClass_AInventoryWorldItemPickup_NoRegister) \
	DECLARE_SERIALIZER(AInventoryWorldItemPickup) \
	virtual UObject* _getUObject() const override { return const_cast<AInventoryWorldItemPickup*>(this); }


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_World_InventoryWorldItemPickup_h_16_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AInventoryWorldItemPickup(AInventoryWorldItemPickup&&) = delete; \
	AInventoryWorldItemPickup(const AInventoryWorldItemPickup&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AInventoryWorldItemPickup); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AInventoryWorldItemPickup); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AInventoryWorldItemPickup) \
	NO_API virtual ~AInventoryWorldItemPickup();


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_World_InventoryWorldItemPickup_h_13_PROLOG
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_World_InventoryWorldItemPickup_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_World_InventoryWorldItemPickup_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_World_InventoryWorldItemPickup_h_16_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_World_InventoryWorldItemPickup_h_16_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_World_InventoryWorldItemPickup_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AInventoryWorldItemPickup;

// ********** End Class AInventoryWorldItemPickup **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_World_InventoryWorldItemPickup_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
