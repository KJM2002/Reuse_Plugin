// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "InventoryTypes.h"

#ifdef INVENTORYSYSTEM_InventoryTypes_generated_h
#error "InventoryTypes.generated.h already included, missing '#pragma once' in InventoryTypes.h"
#endif
#define INVENTORYSYSTEM_InventoryTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FInventorySlot ****************************************************
struct Z_Construct_UScriptStruct_FInventorySlot_Statics;
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_InventoryTypes_h_34_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FInventorySlot_Statics; \
	static class UScriptStruct* StaticStruct();


struct FInventorySlot;
// ********** End ScriptStruct FInventorySlot ******************************************************

// ********** Begin ScriptStruct FInventoryAddOutcome **********************************************
struct Z_Construct_UScriptStruct_FInventoryAddOutcome_Statics;
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_InventoryTypes_h_51_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FInventoryAddOutcome_Statics; \
	static class UScriptStruct* StaticStruct();


struct FInventoryAddOutcome;
// ********** End ScriptStruct FInventoryAddOutcome ************************************************

// ********** Begin ScriptStruct FInventorySaveEntry ***********************************************
struct Z_Construct_UScriptStruct_FInventorySaveEntry_Statics;
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_InventoryTypes_h_71_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FInventorySaveEntry_Statics; \
	static class UScriptStruct* StaticStruct();


struct FInventorySaveEntry;
// ********** End ScriptStruct FInventorySaveEntry *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_InventoryTypes_h

// ********** Begin Enum EInventoryAddResult *******************************************************
#define FOREACH_ENUM_EINVENTORYADDRESULT(op) \
	op(EInventoryAddResult::Success) \
	op(EInventoryAddResult::PartialSuccess) \
	op(EInventoryAddResult::InventoryFull) \
	op(EInventoryAddResult::InvalidItem) \
	op(EInventoryAddResult::InvalidQuantity) 

enum class EInventoryAddResult : uint8;
template<> struct TIsUEnumClass<EInventoryAddResult> { enum { Value = true }; };
template<> INVENTORYSYSTEM_NON_ATTRIBUTED_API UEnum* StaticEnum<EInventoryAddResult>();
// ********** End Enum EInventoryAddResult *********************************************************

// ********** Begin Enum EInventoryOperationResult *************************************************
#define FOREACH_ENUM_EINVENTORYOPERATIONRESULT(op) \
	op(EInventoryOperationResult::Success) \
	op(EInventoryOperationResult::InvalidSlot) \
	op(EInventoryOperationResult::InvalidItem) \
	op(EInventoryOperationResult::InvalidQuantity) \
	op(EInventoryOperationResult::NotAllowed) \
	op(EInventoryOperationResult::CannotUse) \
	op(EInventoryOperationResult::EffectFailed) \
	op(EInventoryOperationResult::SpawnFailed) 

enum class EInventoryOperationResult : uint8;
template<> struct TIsUEnumClass<EInventoryOperationResult> { enum { Value = true }; };
template<> INVENTORYSYSTEM_NON_ATTRIBUTED_API UEnum* StaticEnum<EInventoryOperationResult>();
// ********** End Enum EInventoryOperationResult ***************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
