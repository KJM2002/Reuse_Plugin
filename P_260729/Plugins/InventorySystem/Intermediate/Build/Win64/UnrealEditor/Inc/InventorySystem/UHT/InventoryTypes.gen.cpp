// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "InventoryTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeInventoryTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemDefinition_NoRegister();
INVENTORYSYSTEM_API UEnum* Z_Construct_UEnum_InventorySystem_EInventoryAddResult();
INVENTORYSYSTEM_API UEnum* Z_Construct_UEnum_InventorySystem_EInventoryOperationResult();
INVENTORYSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FInventoryAddOutcome();
INVENTORYSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FInventorySaveEntry();
INVENTORYSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FInventorySlot();
UPackage* Z_Construct_UPackage__Script_InventorySystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EInventoryAddResult *******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EInventoryAddResult;
static UEnum* EInventoryAddResult_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EInventoryAddResult.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EInventoryAddResult.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_InventorySystem_EInventoryAddResult, (UObject*)Z_Construct_UPackage__Script_InventorySystem(), TEXT("EInventoryAddResult"));
	}
	return Z_Registration_Info_UEnum_EInventoryAddResult.OuterSingleton;
}
template<> INVENTORYSYSTEM_NON_ATTRIBUTED_API UEnum* StaticEnum<EInventoryAddResult>()
{
	return EInventoryAddResult_StaticEnum();
}
struct Z_Construct_UEnum_InventorySystem_EInventoryAddResult_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "InvalidItem.Name", "EInventoryAddResult::InvalidItem" },
		{ "InvalidQuantity.Name", "EInventoryAddResult::InvalidQuantity" },
		{ "InventoryFull.Name", "EInventoryAddResult::InventoryFull" },
		{ "ModuleRelativePath", "Public/InventoryTypes.h" },
		{ "PartialSuccess.Name", "EInventoryAddResult::PartialSuccess" },
		{ "Success.Name", "EInventoryAddResult::Success" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EInventoryAddResult::Success", (int64)EInventoryAddResult::Success },
		{ "EInventoryAddResult::PartialSuccess", (int64)EInventoryAddResult::PartialSuccess },
		{ "EInventoryAddResult::InventoryFull", (int64)EInventoryAddResult::InventoryFull },
		{ "EInventoryAddResult::InvalidItem", (int64)EInventoryAddResult::InvalidItem },
		{ "EInventoryAddResult::InvalidQuantity", (int64)EInventoryAddResult::InvalidQuantity },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_InventorySystem_EInventoryAddResult_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_InventorySystem_EInventoryAddResult_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_InventorySystem,
	nullptr,
	"EInventoryAddResult",
	"EInventoryAddResult",
	Z_Construct_UEnum_InventorySystem_EInventoryAddResult_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_InventorySystem_EInventoryAddResult_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_InventorySystem_EInventoryAddResult_Statics::Enum_MetaDataParams), Z_Construct_UEnum_InventorySystem_EInventoryAddResult_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_InventorySystem_EInventoryAddResult()
{
	if (!Z_Registration_Info_UEnum_EInventoryAddResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EInventoryAddResult.InnerSingleton, Z_Construct_UEnum_InventorySystem_EInventoryAddResult_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EInventoryAddResult.InnerSingleton;
}
// ********** End Enum EInventoryAddResult *********************************************************

// ********** Begin Enum EInventoryOperationResult *************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EInventoryOperationResult;
static UEnum* EInventoryOperationResult_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EInventoryOperationResult.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EInventoryOperationResult.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_InventorySystem_EInventoryOperationResult, (UObject*)Z_Construct_UPackage__Script_InventorySystem(), TEXT("EInventoryOperationResult"));
	}
	return Z_Registration_Info_UEnum_EInventoryOperationResult.OuterSingleton;
}
template<> INVENTORYSYSTEM_NON_ATTRIBUTED_API UEnum* StaticEnum<EInventoryOperationResult>()
{
	return EInventoryOperationResult_StaticEnum();
}
struct Z_Construct_UEnum_InventorySystem_EInventoryOperationResult_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CannotUse.Name", "EInventoryOperationResult::CannotUse" },
		{ "EffectFailed.Name", "EInventoryOperationResult::EffectFailed" },
		{ "InvalidItem.Name", "EInventoryOperationResult::InvalidItem" },
		{ "InvalidQuantity.Name", "EInventoryOperationResult::InvalidQuantity" },
		{ "InvalidSlot.Name", "EInventoryOperationResult::InvalidSlot" },
		{ "ModuleRelativePath", "Public/InventoryTypes.h" },
		{ "NotAllowed.Name", "EInventoryOperationResult::NotAllowed" },
		{ "SpawnFailed.Name", "EInventoryOperationResult::SpawnFailed" },
		{ "Success.Name", "EInventoryOperationResult::Success" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EInventoryOperationResult::Success", (int64)EInventoryOperationResult::Success },
		{ "EInventoryOperationResult::InvalidSlot", (int64)EInventoryOperationResult::InvalidSlot },
		{ "EInventoryOperationResult::InvalidItem", (int64)EInventoryOperationResult::InvalidItem },
		{ "EInventoryOperationResult::InvalidQuantity", (int64)EInventoryOperationResult::InvalidQuantity },
		{ "EInventoryOperationResult::NotAllowed", (int64)EInventoryOperationResult::NotAllowed },
		{ "EInventoryOperationResult::CannotUse", (int64)EInventoryOperationResult::CannotUse },
		{ "EInventoryOperationResult::EffectFailed", (int64)EInventoryOperationResult::EffectFailed },
		{ "EInventoryOperationResult::SpawnFailed", (int64)EInventoryOperationResult::SpawnFailed },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_InventorySystem_EInventoryOperationResult_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_InventorySystem_EInventoryOperationResult_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_InventorySystem,
	nullptr,
	"EInventoryOperationResult",
	"EInventoryOperationResult",
	Z_Construct_UEnum_InventorySystem_EInventoryOperationResult_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_InventorySystem_EInventoryOperationResult_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_InventorySystem_EInventoryOperationResult_Statics::Enum_MetaDataParams), Z_Construct_UEnum_InventorySystem_EInventoryOperationResult_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_InventorySystem_EInventoryOperationResult()
{
	if (!Z_Registration_Info_UEnum_EInventoryOperationResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EInventoryOperationResult.InnerSingleton, Z_Construct_UEnum_InventorySystem_EInventoryOperationResult_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EInventoryOperationResult.InnerSingleton;
}
// ********** End Enum EInventoryOperationResult ***************************************************

// ********** Begin ScriptStruct FInventorySlot ****************************************************
struct Z_Construct_UScriptStruct_FInventorySlot_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FInventorySlot); }
	static inline consteval int16 GetStructAlignment() { return alignof(FInventorySlot); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/InventoryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemDefinition_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/InventoryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quantity_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/InventoryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstanceId_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/InventoryTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FInventorySlot constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemDefinition;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InstanceId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FInventorySlot constinit property declarations **********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FInventorySlot>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FInventorySlot_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FInventorySlot;
class UScriptStruct* FInventorySlot::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FInventorySlot.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FInventorySlot.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FInventorySlot, (UObject*)Z_Construct_UPackage__Script_InventorySystem(), TEXT("InventorySlot"));
	}
	return Z_Registration_Info_UScriptStruct_FInventorySlot.OuterSingleton;
	}

// ********** Begin ScriptStruct FInventorySlot Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_ItemDefinition = { "ItemDefinition", nullptr, (EPropertyFlags)0x0114000000020015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventorySlot, ItemDefinition), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemDefinition_MetaData), NewProp_ItemDefinition_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventorySlot, Quantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quantity_MetaData), NewProp_Quantity_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_InstanceId = { "InstanceId", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventorySlot, InstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstanceId_MetaData), NewProp_InstanceId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FInventorySlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_ItemDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_InstanceId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventorySlot_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FInventorySlot Property Definitions *********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FInventorySlot_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_InventorySystem,
	nullptr,
	&NewStructOps,
	"InventorySlot",
	Z_Construct_UScriptStruct_FInventorySlot_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventorySlot_Statics::PropPointers),
	sizeof(FInventorySlot),
	alignof(FInventorySlot),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventorySlot_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FInventorySlot_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FInventorySlot()
{
	if (!Z_Registration_Info_UScriptStruct_FInventorySlot.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FInventorySlot.InnerSingleton, Z_Construct_UScriptStruct_FInventorySlot_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FInventorySlot.InnerSingleton);
}
// ********** End ScriptStruct FInventorySlot ******************************************************

// ********** Begin ScriptStruct FInventoryAddOutcome **********************************************
struct Z_Construct_UScriptStruct_FInventoryAddOutcome_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FInventoryAddOutcome); }
	static inline consteval int16 GetStructAlignment() { return alignof(FInventoryAddOutcome); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/InventoryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Result_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/InventoryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequestedQuantity_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/InventoryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AddedQuantity_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/InventoryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RemainingQuantity_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/InventoryTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FInventoryAddOutcome constinit property declarations **************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Result;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RequestedQuantity;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AddedQuantity;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RemainingQuantity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FInventoryAddOutcome constinit property declarations ****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FInventoryAddOutcome>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FInventoryAddOutcome_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FInventoryAddOutcome;
class UScriptStruct* FInventoryAddOutcome::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FInventoryAddOutcome.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FInventoryAddOutcome.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FInventoryAddOutcome, (UObject*)Z_Construct_UPackage__Script_InventorySystem(), TEXT("InventoryAddOutcome"));
	}
	return Z_Registration_Info_UScriptStruct_FInventoryAddOutcome.OuterSingleton;
	}

// ********** Begin ScriptStruct FInventoryAddOutcome Property Definitions *************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FInventoryAddOutcome_Statics::NewProp_Result_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FInventoryAddOutcome_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryAddOutcome, Result), Z_Construct_UEnum_InventorySystem_EInventoryAddResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Result_MetaData), NewProp_Result_MetaData) }; // 3264627793
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FInventoryAddOutcome_Statics::NewProp_RequestedQuantity = { "RequestedQuantity", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryAddOutcome, RequestedQuantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequestedQuantity_MetaData), NewProp_RequestedQuantity_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FInventoryAddOutcome_Statics::NewProp_AddedQuantity = { "AddedQuantity", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryAddOutcome, AddedQuantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AddedQuantity_MetaData), NewProp_AddedQuantity_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FInventoryAddOutcome_Statics::NewProp_RemainingQuantity = { "RemainingQuantity", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventoryAddOutcome, RemainingQuantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RemainingQuantity_MetaData), NewProp_RemainingQuantity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FInventoryAddOutcome_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddOutcome_Statics::NewProp_Result_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddOutcome_Statics::NewProp_Result,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddOutcome_Statics::NewProp_RequestedQuantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddOutcome_Statics::NewProp_AddedQuantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventoryAddOutcome_Statics::NewProp_RemainingQuantity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryAddOutcome_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FInventoryAddOutcome Property Definitions ***************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FInventoryAddOutcome_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_InventorySystem,
	nullptr,
	&NewStructOps,
	"InventoryAddOutcome",
	Z_Construct_UScriptStruct_FInventoryAddOutcome_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryAddOutcome_Statics::PropPointers),
	sizeof(FInventoryAddOutcome),
	alignof(FInventoryAddOutcome),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventoryAddOutcome_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FInventoryAddOutcome_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FInventoryAddOutcome()
{
	if (!Z_Registration_Info_UScriptStruct_FInventoryAddOutcome.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FInventoryAddOutcome.InnerSingleton, Z_Construct_UScriptStruct_FInventoryAddOutcome_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FInventoryAddOutcome.InnerSingleton);
}
// ********** End ScriptStruct FInventoryAddOutcome ************************************************

// ********** Begin ScriptStruct FInventorySaveEntry ***********************************************
struct Z_Construct_UScriptStruct_FInventorySaveEntry_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FInventorySaveEntry); }
	static inline consteval int16 GetStructAlignment() { return alignof(FInventorySaveEntry); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/InventoryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemId_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/InventoryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quantity_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/InventoryTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstanceId_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/InventoryTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FInventorySaveEntry constinit property declarations ***************
	static const UECodeGen_Private::FNamePropertyParams NewProp_ItemId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InstanceId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FInventorySaveEntry constinit property declarations *****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FInventorySaveEntry>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FInventorySaveEntry_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FInventorySaveEntry;
class UScriptStruct* FInventorySaveEntry::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FInventorySaveEntry.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FInventorySaveEntry.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FInventorySaveEntry, (UObject*)Z_Construct_UPackage__Script_InventorySystem(), TEXT("InventorySaveEntry"));
	}
	return Z_Registration_Info_UScriptStruct_FInventorySaveEntry.OuterSingleton;
	}

// ********** Begin ScriptStruct FInventorySaveEntry Property Definitions **************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FInventorySaveEntry_Statics::NewProp_ItemId = { "ItemId", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventorySaveEntry, ItemId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemId_MetaData), NewProp_ItemId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FInventorySaveEntry_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventorySaveEntry, Quantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quantity_MetaData), NewProp_Quantity_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FInventorySaveEntry_Statics::NewProp_InstanceId = { "InstanceId", nullptr, (EPropertyFlags)0x0010000001000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FInventorySaveEntry, InstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstanceId_MetaData), NewProp_InstanceId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FInventorySaveEntry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventorySaveEntry_Statics::NewProp_ItemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventorySaveEntry_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventorySaveEntry_Statics::NewProp_InstanceId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventorySaveEntry_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FInventorySaveEntry Property Definitions ****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FInventorySaveEntry_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_InventorySystem,
	nullptr,
	&NewStructOps,
	"InventorySaveEntry",
	Z_Construct_UScriptStruct_FInventorySaveEntry_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventorySaveEntry_Statics::PropPointers),
	sizeof(FInventorySaveEntry),
	alignof(FInventorySaveEntry),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventorySaveEntry_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FInventorySaveEntry_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FInventorySaveEntry()
{
	if (!Z_Registration_Info_UScriptStruct_FInventorySaveEntry.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FInventorySaveEntry.InnerSingleton, Z_Construct_UScriptStruct_FInventorySaveEntry_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FInventorySaveEntry.InnerSingleton);
}
// ********** End ScriptStruct FInventorySaveEntry *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_InventoryTypes_h__Script_InventorySystem_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EInventoryAddResult_StaticEnum, TEXT("EInventoryAddResult"), &Z_Registration_Info_UEnum_EInventoryAddResult, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3264627793U) },
		{ EInventoryOperationResult_StaticEnum, TEXT("EInventoryOperationResult"), &Z_Registration_Info_UEnum_EInventoryOperationResult, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 935842388U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FInventorySlot::StaticStruct, Z_Construct_UScriptStruct_FInventorySlot_Statics::NewStructOps, TEXT("InventorySlot"),&Z_Registration_Info_UScriptStruct_FInventorySlot, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FInventorySlot), 3353780059U) },
		{ FInventoryAddOutcome::StaticStruct, Z_Construct_UScriptStruct_FInventoryAddOutcome_Statics::NewStructOps, TEXT("InventoryAddOutcome"),&Z_Registration_Info_UScriptStruct_FInventoryAddOutcome, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FInventoryAddOutcome), 1841536829U) },
		{ FInventorySaveEntry::StaticStruct, Z_Construct_UScriptStruct_FInventorySaveEntry_Statics::NewStructOps, TEXT("InventorySaveEntry"),&Z_Registration_Info_UScriptStruct_FInventorySaveEntry, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FInventorySaveEntry), 4175675149U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_InventoryTypes_h__Script_InventorySystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_InventoryTypes_h__Script_InventorySystem_361904757{
	TEXT("/Script/InventorySystem"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_InventoryTypes_h__Script_InventorySystem_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_InventoryTypes_h__Script_InventorySystem_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_InventoryTypes_h__Script_InventorySystem_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_InventoryTypes_h__Script_InventorySystem_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
