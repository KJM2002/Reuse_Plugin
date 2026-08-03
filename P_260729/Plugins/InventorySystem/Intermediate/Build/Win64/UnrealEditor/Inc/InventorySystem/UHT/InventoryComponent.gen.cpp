// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/InventoryComponent.h"
#include "InventoryTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeInventoryComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryComponent();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryComponent_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemDefinition_NoRegister();
INVENTORYSYSTEM_API UEnum* Z_Construct_UEnum_InventorySystem_EInventoryOperationResult();
INVENTORYSYSTEM_API UFunction* Z_Construct_UDelegateFunction_InventorySystem_InventoryChangedSignature__DelegateSignature();
INVENTORYSYSTEM_API UFunction* Z_Construct_UDelegateFunction_InventorySystem_InventoryFullSignature__DelegateSignature();
INVENTORYSYSTEM_API UFunction* Z_Construct_UDelegateFunction_InventorySystem_InventoryItemChangedSignature__DelegateSignature();
INVENTORYSYSTEM_API UFunction* Z_Construct_UDelegateFunction_InventorySystem_InventoryItemsReceivedSignature__DelegateSignature();
INVENTORYSYSTEM_API UFunction* Z_Construct_UDelegateFunction_InventorySystem_InventoryItemUsedSignature__DelegateSignature();
INVENTORYSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FInventoryAddOutcome();
INVENTORYSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FInventorySaveEntry();
INVENTORYSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FInventorySlot();
UPackage* Z_Construct_UPackage__Script_InventorySystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FInventoryChangedSignature ********************************************
struct Z_Construct_UDelegateFunction_InventorySystem_InventoryChangedSignature__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FInventoryChangedSignature constinit property declarations ************
// ********** End Delegate FInventoryChangedSignature constinit property declarations **************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_InventorySystem_InventoryChangedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_InventorySystem, nullptr, "InventoryChangedSignature__DelegateSignature", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_InventoryChangedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_InventorySystem_InventoryChangedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_InventorySystem_InventoryChangedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_InventorySystem_InventoryChangedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FInventoryChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& InventoryChangedSignature)
{
	InventoryChangedSignature.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FInventoryChangedSignature **********************************************

// ********** Begin Delegate FInventoryItemChangedSignature ****************************************
struct Z_Construct_UDelegateFunction_InventorySystem_InventoryItemChangedSignature__DelegateSignature_Statics
{
	struct _Script_InventorySystem_eventInventoryItemChangedSignature_Parms
	{
		UInventoryItemDefinition* ItemDefinition;
		int32 Quantity;
		int32 SlotIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FInventoryItemChangedSignature constinit property declarations ********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemDefinition;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FInventoryItemChangedSignature constinit property declarations **********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FInventoryItemChangedSignature Property Definitions *******************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_InventorySystem_InventoryItemChangedSignature__DelegateSignature_Statics::NewProp_ItemDefinition = { "ItemDefinition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_InventorySystem_eventInventoryItemChangedSignature_Parms, ItemDefinition), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_InventorySystem_InventoryItemChangedSignature__DelegateSignature_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_InventorySystem_eventInventoryItemChangedSignature_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_InventorySystem_InventoryItemChangedSignature__DelegateSignature_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_InventorySystem_eventInventoryItemChangedSignature_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_InventorySystem_InventoryItemChangedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_InventorySystem_InventoryItemChangedSignature__DelegateSignature_Statics::NewProp_ItemDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_InventorySystem_InventoryItemChangedSignature__DelegateSignature_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_InventorySystem_InventoryItemChangedSignature__DelegateSignature_Statics::NewProp_SlotIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_InventoryItemChangedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FInventoryItemChangedSignature Property Definitions *********************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_InventorySystem_InventoryItemChangedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_InventorySystem, nullptr, "InventoryItemChangedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_InventorySystem_InventoryItemChangedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_InventoryItemChangedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_InventorySystem_InventoryItemChangedSignature__DelegateSignature_Statics::_Script_InventorySystem_eventInventoryItemChangedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_InventoryItemChangedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_InventorySystem_InventoryItemChangedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_InventorySystem_InventoryItemChangedSignature__DelegateSignature_Statics::_Script_InventorySystem_eventInventoryItemChangedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_InventorySystem_InventoryItemChangedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_InventorySystem_InventoryItemChangedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FInventoryItemChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& InventoryItemChangedSignature, UInventoryItemDefinition* ItemDefinition, int32 Quantity, int32 SlotIndex)
{
	struct _Script_InventorySystem_eventInventoryItemChangedSignature_Parms
	{
		UInventoryItemDefinition* ItemDefinition;
		int32 Quantity;
		int32 SlotIndex;
	};
	_Script_InventorySystem_eventInventoryItemChangedSignature_Parms Parms;
	Parms.ItemDefinition=ItemDefinition;
	Parms.Quantity=Quantity;
	Parms.SlotIndex=SlotIndex;
	InventoryItemChangedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FInventoryItemChangedSignature ******************************************

// ********** Begin Delegate FInventoryItemsReceivedSignature **************************************
struct Z_Construct_UDelegateFunction_InventorySystem_InventoryItemsReceivedSignature__DelegateSignature_Statics
{
	struct _Script_InventorySystem_eventInventoryItemsReceivedSignature_Parms
	{
		UInventoryItemDefinition* ItemDefinition;
		int32 Quantity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FInventoryItemsReceivedSignature constinit property declarations ******
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemDefinition;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FInventoryItemsReceivedSignature constinit property declarations ********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FInventoryItemsReceivedSignature Property Definitions *****************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_InventorySystem_InventoryItemsReceivedSignature__DelegateSignature_Statics::NewProp_ItemDefinition = { "ItemDefinition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_InventorySystem_eventInventoryItemsReceivedSignature_Parms, ItemDefinition), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_InventorySystem_InventoryItemsReceivedSignature__DelegateSignature_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_InventorySystem_eventInventoryItemsReceivedSignature_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_InventorySystem_InventoryItemsReceivedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_InventorySystem_InventoryItemsReceivedSignature__DelegateSignature_Statics::NewProp_ItemDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_InventorySystem_InventoryItemsReceivedSignature__DelegateSignature_Statics::NewProp_Quantity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_InventoryItemsReceivedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FInventoryItemsReceivedSignature Property Definitions *******************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_InventorySystem_InventoryItemsReceivedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_InventorySystem, nullptr, "InventoryItemsReceivedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_InventorySystem_InventoryItemsReceivedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_InventoryItemsReceivedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_InventorySystem_InventoryItemsReceivedSignature__DelegateSignature_Statics::_Script_InventorySystem_eventInventoryItemsReceivedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_InventoryItemsReceivedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_InventorySystem_InventoryItemsReceivedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_InventorySystem_InventoryItemsReceivedSignature__DelegateSignature_Statics::_Script_InventorySystem_eventInventoryItemsReceivedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_InventorySystem_InventoryItemsReceivedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_InventorySystem_InventoryItemsReceivedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FInventoryItemsReceivedSignature_DelegateWrapper(const FMulticastScriptDelegate& InventoryItemsReceivedSignature, UInventoryItemDefinition* ItemDefinition, int32 Quantity)
{
	struct _Script_InventorySystem_eventInventoryItemsReceivedSignature_Parms
	{
		UInventoryItemDefinition* ItemDefinition;
		int32 Quantity;
	};
	_Script_InventorySystem_eventInventoryItemsReceivedSignature_Parms Parms;
	Parms.ItemDefinition=ItemDefinition;
	Parms.Quantity=Quantity;
	InventoryItemsReceivedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FInventoryItemsReceivedSignature ****************************************

// ********** Begin Delegate FInventoryItemUsedSignature *******************************************
struct Z_Construct_UDelegateFunction_InventorySystem_InventoryItemUsedSignature__DelegateSignature_Statics
{
	struct _Script_InventorySystem_eventInventoryItemUsedSignature_Parms
	{
		UInventoryItemDefinition* ItemDefinition;
		int32 SlotIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FInventoryItemUsedSignature constinit property declarations ***********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemDefinition;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FInventoryItemUsedSignature constinit property declarations *************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FInventoryItemUsedSignature Property Definitions **********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_InventorySystem_InventoryItemUsedSignature__DelegateSignature_Statics::NewProp_ItemDefinition = { "ItemDefinition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_InventorySystem_eventInventoryItemUsedSignature_Parms, ItemDefinition), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_InventorySystem_InventoryItemUsedSignature__DelegateSignature_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_InventorySystem_eventInventoryItemUsedSignature_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_InventorySystem_InventoryItemUsedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_InventorySystem_InventoryItemUsedSignature__DelegateSignature_Statics::NewProp_ItemDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_InventorySystem_InventoryItemUsedSignature__DelegateSignature_Statics::NewProp_SlotIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_InventoryItemUsedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FInventoryItemUsedSignature Property Definitions ************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_InventorySystem_InventoryItemUsedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_InventorySystem, nullptr, "InventoryItemUsedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_InventorySystem_InventoryItemUsedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_InventoryItemUsedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_InventorySystem_InventoryItemUsedSignature__DelegateSignature_Statics::_Script_InventorySystem_eventInventoryItemUsedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_InventoryItemUsedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_InventorySystem_InventoryItemUsedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_InventorySystem_InventoryItemUsedSignature__DelegateSignature_Statics::_Script_InventorySystem_eventInventoryItemUsedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_InventorySystem_InventoryItemUsedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_InventorySystem_InventoryItemUsedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FInventoryItemUsedSignature_DelegateWrapper(const FMulticastScriptDelegate& InventoryItemUsedSignature, UInventoryItemDefinition* ItemDefinition, int32 SlotIndex)
{
	struct _Script_InventorySystem_eventInventoryItemUsedSignature_Parms
	{
		UInventoryItemDefinition* ItemDefinition;
		int32 SlotIndex;
	};
	_Script_InventorySystem_eventInventoryItemUsedSignature_Parms Parms;
	Parms.ItemDefinition=ItemDefinition;
	Parms.SlotIndex=SlotIndex;
	InventoryItemUsedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FInventoryItemUsedSignature *********************************************

// ********** Begin Delegate FInventoryFullSignature ***********************************************
struct Z_Construct_UDelegateFunction_InventorySystem_InventoryFullSignature__DelegateSignature_Statics
{
	struct _Script_InventorySystem_eventInventoryFullSignature_Parms
	{
		UInventoryItemDefinition* ItemDefinition;
		int32 RejectedQuantity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FInventoryFullSignature constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemDefinition;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RejectedQuantity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FInventoryFullSignature constinit property declarations *****************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FInventoryFullSignature Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_InventorySystem_InventoryFullSignature__DelegateSignature_Statics::NewProp_ItemDefinition = { "ItemDefinition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_InventorySystem_eventInventoryFullSignature_Parms, ItemDefinition), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_InventorySystem_InventoryFullSignature__DelegateSignature_Statics::NewProp_RejectedQuantity = { "RejectedQuantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_InventorySystem_eventInventoryFullSignature_Parms, RejectedQuantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_InventorySystem_InventoryFullSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_InventorySystem_InventoryFullSignature__DelegateSignature_Statics::NewProp_ItemDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_InventorySystem_InventoryFullSignature__DelegateSignature_Statics::NewProp_RejectedQuantity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_InventoryFullSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FInventoryFullSignature Property Definitions ****************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_InventorySystem_InventoryFullSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_InventorySystem, nullptr, "InventoryFullSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_InventorySystem_InventoryFullSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_InventoryFullSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_InventorySystem_InventoryFullSignature__DelegateSignature_Statics::_Script_InventorySystem_eventInventoryFullSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_InventoryFullSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_InventorySystem_InventoryFullSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_InventorySystem_InventoryFullSignature__DelegateSignature_Statics::_Script_InventorySystem_eventInventoryFullSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_InventorySystem_InventoryFullSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_InventorySystem_InventoryFullSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FInventoryFullSignature_DelegateWrapper(const FMulticastScriptDelegate& InventoryFullSignature, UInventoryItemDefinition* ItemDefinition, int32 RejectedQuantity)
{
	struct _Script_InventorySystem_eventInventoryFullSignature_Parms
	{
		UInventoryItemDefinition* ItemDefinition;
		int32 RejectedQuantity;
	};
	_Script_InventorySystem_eventInventoryFullSignature_Parms Parms;
	Parms.ItemDefinition=ItemDefinition;
	Parms.RejectedQuantity=RejectedQuantity;
	InventoryFullSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FInventoryFullSignature *************************************************

// ********** Begin Class UInventoryComponent Function AddItem *************************************
struct Z_Construct_UFunction_UInventoryComponent_AddItem_Statics
{
	struct InventoryComponent_eventAddItem_Parms
	{
		UInventoryItemDefinition* ItemDefinition;
		int32 Quantity;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "CPP_Default_Quantity", "1" },
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddItem constinit property declarations *******************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemDefinition;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddItem constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddItem Property Definitions ******************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryComponent_AddItem_Statics::NewProp_ItemDefinition = { "ItemDefinition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventAddItem_Parms, ItemDefinition), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_AddItem_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventAddItem_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UInventoryComponent_AddItem_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventoryComponent_eventAddItem_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryComponent_AddItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventoryComponent_eventAddItem_Parms), &Z_Construct_UFunction_UInventoryComponent_AddItem_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_AddItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_AddItem_Statics::NewProp_ItemDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_AddItem_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_AddItem_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_AddItem_Statics::PropPointers) < 2048);
// ********** End Function AddItem Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_AddItem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "AddItem", 	Z_Construct_UFunction_UInventoryComponent_AddItem_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_AddItem_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryComponent_AddItem_Statics::InventoryComponent_eventAddItem_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_AddItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryComponent_AddItem_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryComponent_AddItem_Statics::InventoryComponent_eventAddItem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryComponent_AddItem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_AddItem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryComponent::execAddItem)
{
	P_GET_OBJECT(UInventoryItemDefinition,Z_Param_ItemDefinition);
	P_GET_PROPERTY(FIntProperty,Z_Param_Quantity);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->AddItem(Z_Param_ItemDefinition,Z_Param_Quantity);
	P_NATIVE_END;
}
// ********** End Class UInventoryComponent Function AddItem ***************************************

// ********** Begin Class UInventoryComponent Function AddItemDetailed *****************************
struct Z_Construct_UFunction_UInventoryComponent_AddItemDetailed_Statics
{
	struct InventoryComponent_eventAddItemDetailed_Parms
	{
		UInventoryItemDefinition* ItemDefinition;
		int32 Quantity;
		FInventoryAddOutcome ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "CPP_Default_Quantity", "1" },
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddItemDetailed constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemDefinition;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddItemDetailed constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddItemDetailed Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryComponent_AddItemDetailed_Statics::NewProp_ItemDefinition = { "ItemDefinition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventAddItemDetailed_Parms, ItemDefinition), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_AddItemDetailed_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventAddItemDetailed_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryComponent_AddItemDetailed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventAddItemDetailed_Parms, ReturnValue), Z_Construct_UScriptStruct_FInventoryAddOutcome, METADATA_PARAMS(0, nullptr) }; // 1841536829
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_AddItemDetailed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_AddItemDetailed_Statics::NewProp_ItemDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_AddItemDetailed_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_AddItemDetailed_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_AddItemDetailed_Statics::PropPointers) < 2048);
// ********** End Function AddItemDetailed Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_AddItemDetailed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "AddItemDetailed", 	Z_Construct_UFunction_UInventoryComponent_AddItemDetailed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_AddItemDetailed_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryComponent_AddItemDetailed_Statics::InventoryComponent_eventAddItemDetailed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_AddItemDetailed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryComponent_AddItemDetailed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryComponent_AddItemDetailed_Statics::InventoryComponent_eventAddItemDetailed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryComponent_AddItemDetailed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_AddItemDetailed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryComponent::execAddItemDetailed)
{
	P_GET_OBJECT(UInventoryItemDefinition,Z_Param_ItemDefinition);
	P_GET_PROPERTY(FIntProperty,Z_Param_Quantity);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FInventoryAddOutcome*)Z_Param__Result=P_THIS->AddItemDetailed(Z_Param_ItemDefinition,Z_Param_Quantity);
	P_NATIVE_END;
}
// ********** End Class UInventoryComponent Function AddItemDetailed *******************************

// ********** Begin Class UInventoryComponent Function DropItemAtSlot ******************************
struct Z_Construct_UFunction_UInventoryComponent_DropItemAtSlot_Statics
{
	struct InventoryComponent_eventDropItemAtSlot_Parms
	{
		int32 SlotIndex;
		int32 Quantity;
		AActor* Dropper;
		EInventoryOperationResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "CPP_Default_Dropper", "None" },
		{ "CPP_Default_Quantity", "1" },
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function DropItemAtSlot constinit property declarations ************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Dropper;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DropItemAtSlot constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DropItemAtSlot Property Definitions ***********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_DropItemAtSlot_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventDropItemAtSlot_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_DropItemAtSlot_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventDropItemAtSlot_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryComponent_DropItemAtSlot_Statics::NewProp_Dropper = { "Dropper", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventDropItemAtSlot_Parms, Dropper), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UInventoryComponent_DropItemAtSlot_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UInventoryComponent_DropItemAtSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventDropItemAtSlot_Parms, ReturnValue), Z_Construct_UEnum_InventorySystem_EInventoryOperationResult, METADATA_PARAMS(0, nullptr) }; // 935842388
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_DropItemAtSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_DropItemAtSlot_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_DropItemAtSlot_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_DropItemAtSlot_Statics::NewProp_Dropper,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_DropItemAtSlot_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_DropItemAtSlot_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_DropItemAtSlot_Statics::PropPointers) < 2048);
// ********** End Function DropItemAtSlot Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_DropItemAtSlot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "DropItemAtSlot", 	Z_Construct_UFunction_UInventoryComponent_DropItemAtSlot_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_DropItemAtSlot_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryComponent_DropItemAtSlot_Statics::InventoryComponent_eventDropItemAtSlot_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_DropItemAtSlot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryComponent_DropItemAtSlot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryComponent_DropItemAtSlot_Statics::InventoryComponent_eventDropItemAtSlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryComponent_DropItemAtSlot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_DropItemAtSlot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryComponent::execDropItemAtSlot)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_GET_PROPERTY(FIntProperty,Z_Param_Quantity);
	P_GET_OBJECT(AActor,Z_Param_Dropper);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EInventoryOperationResult*)Z_Param__Result=P_THIS->DropItemAtSlot(Z_Param_SlotIndex,Z_Param_Quantity,Z_Param_Dropper);
	P_NATIVE_END;
}
// ********** End Class UInventoryComponent Function DropItemAtSlot ********************************

// ********** Begin Class UInventoryComponent Function GetInventorySlots ***************************
struct Z_Construct_UFunction_UInventoryComponent_GetInventorySlots_Statics
{
	struct InventoryComponent_eventGetInventorySlots_Parms
	{
		TArray<FInventorySlot> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetInventorySlots constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetInventorySlots constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetInventorySlots Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryComponent_GetInventorySlots_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FInventorySlot, METADATA_PARAMS(0, nullptr) }; // 3353780059
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UInventoryComponent_GetInventorySlots_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventGetInventorySlots_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 3353780059
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_GetInventorySlots_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_GetInventorySlots_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_GetInventorySlots_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_GetInventorySlots_Statics::PropPointers) < 2048);
// ********** End Function GetInventorySlots Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_GetInventorySlots_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "GetInventorySlots", 	Z_Construct_UFunction_UInventoryComponent_GetInventorySlots_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_GetInventorySlots_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryComponent_GetInventorySlots_Statics::InventoryComponent_eventGetInventorySlots_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_GetInventorySlots_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryComponent_GetInventorySlots_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryComponent_GetInventorySlots_Statics::InventoryComponent_eventGetInventorySlots_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryComponent_GetInventorySlots()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_GetInventorySlots_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryComponent::execGetInventorySlots)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FInventorySlot>*)Z_Param__Result=P_THIS->GetInventorySlots();
	P_NATIVE_END;
}
// ********** End Class UInventoryComponent Function GetInventorySlots *****************************

// ********** Begin Class UInventoryComponent Function GetItemQuantity *****************************
struct Z_Construct_UFunction_UInventoryComponent_GetItemQuantity_Statics
{
	struct InventoryComponent_eventGetItemQuantity_Parms
	{
		UInventoryItemDefinition* ItemDefinition;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetItemQuantity constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemDefinition;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetItemQuantity constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetItemQuantity Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryComponent_GetItemQuantity_Statics::NewProp_ItemDefinition = { "ItemDefinition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventGetItemQuantity_Parms, ItemDefinition), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_GetItemQuantity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventGetItemQuantity_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_GetItemQuantity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_GetItemQuantity_Statics::NewProp_ItemDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_GetItemQuantity_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_GetItemQuantity_Statics::PropPointers) < 2048);
// ********** End Function GetItemQuantity Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_GetItemQuantity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "GetItemQuantity", 	Z_Construct_UFunction_UInventoryComponent_GetItemQuantity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_GetItemQuantity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryComponent_GetItemQuantity_Statics::InventoryComponent_eventGetItemQuantity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_GetItemQuantity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryComponent_GetItemQuantity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryComponent_GetItemQuantity_Statics::InventoryComponent_eventGetItemQuantity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryComponent_GetItemQuantity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_GetItemQuantity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryComponent::execGetItemQuantity)
{
	P_GET_OBJECT(UInventoryItemDefinition,Z_Param_ItemDefinition);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetItemQuantity(Z_Param_ItemDefinition);
	P_NATIVE_END;
}
// ********** End Class UInventoryComponent Function GetItemQuantity *******************************

// ********** Begin Class UInventoryComponent Function GetMaxInventorySlots ************************
struct Z_Construct_UFunction_UInventoryComponent_GetMaxInventorySlots_Statics
{
	struct InventoryComponent_eventGetMaxInventorySlots_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetMaxInventorySlots constinit property declarations ******************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetMaxInventorySlots constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetMaxInventorySlots Property Definitions *****************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_GetMaxInventorySlots_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventGetMaxInventorySlots_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_GetMaxInventorySlots_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_GetMaxInventorySlots_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_GetMaxInventorySlots_Statics::PropPointers) < 2048);
// ********** End Function GetMaxInventorySlots Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_GetMaxInventorySlots_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "GetMaxInventorySlots", 	Z_Construct_UFunction_UInventoryComponent_GetMaxInventorySlots_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_GetMaxInventorySlots_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryComponent_GetMaxInventorySlots_Statics::InventoryComponent_eventGetMaxInventorySlots_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_GetMaxInventorySlots_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryComponent_GetMaxInventorySlots_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryComponent_GetMaxInventorySlots_Statics::InventoryComponent_eventGetMaxInventorySlots_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryComponent_GetMaxInventorySlots()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_GetMaxInventorySlots_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryComponent::execGetMaxInventorySlots)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetMaxInventorySlots();
	P_NATIVE_END;
}
// ********** End Class UInventoryComponent Function GetMaxInventorySlots **************************

// ********** Begin Class UInventoryComponent Function GetOccupiedSlotCount ************************
struct Z_Construct_UFunction_UInventoryComponent_GetOccupiedSlotCount_Statics
{
	struct InventoryComponent_eventGetOccupiedSlotCount_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetOccupiedSlotCount constinit property declarations ******************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetOccupiedSlotCount constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetOccupiedSlotCount Property Definitions *****************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_GetOccupiedSlotCount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventGetOccupiedSlotCount_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_GetOccupiedSlotCount_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_GetOccupiedSlotCount_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_GetOccupiedSlotCount_Statics::PropPointers) < 2048);
// ********** End Function GetOccupiedSlotCount Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_GetOccupiedSlotCount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "GetOccupiedSlotCount", 	Z_Construct_UFunction_UInventoryComponent_GetOccupiedSlotCount_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_GetOccupiedSlotCount_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryComponent_GetOccupiedSlotCount_Statics::InventoryComponent_eventGetOccupiedSlotCount_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_GetOccupiedSlotCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryComponent_GetOccupiedSlotCount_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryComponent_GetOccupiedSlotCount_Statics::InventoryComponent_eventGetOccupiedSlotCount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryComponent_GetOccupiedSlotCount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_GetOccupiedSlotCount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryComponent::execGetOccupiedSlotCount)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetOccupiedSlotCount();
	P_NATIVE_END;
}
// ********** End Class UInventoryComponent Function GetOccupiedSlotCount **************************

// ********** Begin Class UInventoryComponent Function GetSlot *************************************
struct Z_Construct_UFunction_UInventoryComponent_GetSlot_Statics
{
	struct InventoryComponent_eventGetSlot_Parms
	{
		int32 SlotIndex;
		FInventorySlot OutSlot;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSlot constinit property declarations *******************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutSlot;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSlot constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSlot Property Definitions ******************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_GetSlot_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventGetSlot_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryComponent_GetSlot_Statics::NewProp_OutSlot = { "OutSlot", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventGetSlot_Parms, OutSlot), Z_Construct_UScriptStruct_FInventorySlot, METADATA_PARAMS(0, nullptr) }; // 3353780059
void Z_Construct_UFunction_UInventoryComponent_GetSlot_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventoryComponent_eventGetSlot_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryComponent_GetSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventoryComponent_eventGetSlot_Parms), &Z_Construct_UFunction_UInventoryComponent_GetSlot_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_GetSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_GetSlot_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_GetSlot_Statics::NewProp_OutSlot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_GetSlot_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_GetSlot_Statics::PropPointers) < 2048);
// ********** End Function GetSlot Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_GetSlot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "GetSlot", 	Z_Construct_UFunction_UInventoryComponent_GetSlot_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_GetSlot_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryComponent_GetSlot_Statics::InventoryComponent_eventGetSlot_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_GetSlot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryComponent_GetSlot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryComponent_GetSlot_Statics::InventoryComponent_eventGetSlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryComponent_GetSlot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_GetSlot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryComponent::execGetSlot)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_GET_STRUCT_REF(FInventorySlot,Z_Param_Out_OutSlot);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetSlot(Z_Param_SlotIndex,Z_Param_Out_OutSlot);
	P_NATIVE_END;
}
// ********** End Class UInventoryComponent Function GetSlot ***************************************

// ********** Begin Class UInventoryComponent Function HasItem *************************************
struct Z_Construct_UFunction_UInventoryComponent_HasItem_Statics
{
	struct InventoryComponent_eventHasItem_Parms
	{
		UInventoryItemDefinition* ItemDefinition;
		int32 Quantity;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "CPP_Default_Quantity", "1" },
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HasItem constinit property declarations *******************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemDefinition;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasItem constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasItem Property Definitions ******************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryComponent_HasItem_Statics::NewProp_ItemDefinition = { "ItemDefinition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventHasItem_Parms, ItemDefinition), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_HasItem_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventHasItem_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UInventoryComponent_HasItem_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventoryComponent_eventHasItem_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryComponent_HasItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventoryComponent_eventHasItem_Parms), &Z_Construct_UFunction_UInventoryComponent_HasItem_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_HasItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_HasItem_Statics::NewProp_ItemDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_HasItem_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_HasItem_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_HasItem_Statics::PropPointers) < 2048);
// ********** End Function HasItem Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_HasItem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "HasItem", 	Z_Construct_UFunction_UInventoryComponent_HasItem_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_HasItem_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryComponent_HasItem_Statics::InventoryComponent_eventHasItem_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_HasItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryComponent_HasItem_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryComponent_HasItem_Statics::InventoryComponent_eventHasItem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryComponent_HasItem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_HasItem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryComponent::execHasItem)
{
	P_GET_OBJECT(UInventoryItemDefinition,Z_Param_ItemDefinition);
	P_GET_PROPERTY(FIntProperty,Z_Param_Quantity);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->HasItem(Z_Param_ItemDefinition,Z_Param_Quantity);
	P_NATIVE_END;
}
// ********** End Class UInventoryComponent Function HasItem ***************************************

// ********** Begin Class UInventoryComponent Function MakeSaveEntries *****************************
struct Z_Construct_UFunction_UInventoryComponent_MakeSaveEntries_Statics
{
	struct InventoryComponent_eventMakeSaveEntries_Parms
	{
		TArray<FInventorySaveEntry> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Save" },
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function MakeSaveEntries constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MakeSaveEntries constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MakeSaveEntries Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryComponent_MakeSaveEntries_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FInventorySaveEntry, METADATA_PARAMS(0, nullptr) }; // 4175675149
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UInventoryComponent_MakeSaveEntries_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventMakeSaveEntries_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 4175675149
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_MakeSaveEntries_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_MakeSaveEntries_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_MakeSaveEntries_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_MakeSaveEntries_Statics::PropPointers) < 2048);
// ********** End Function MakeSaveEntries Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_MakeSaveEntries_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "MakeSaveEntries", 	Z_Construct_UFunction_UInventoryComponent_MakeSaveEntries_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_MakeSaveEntries_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryComponent_MakeSaveEntries_Statics::InventoryComponent_eventMakeSaveEntries_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_MakeSaveEntries_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryComponent_MakeSaveEntries_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryComponent_MakeSaveEntries_Statics::InventoryComponent_eventMakeSaveEntries_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryComponent_MakeSaveEntries()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_MakeSaveEntries_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryComponent::execMakeSaveEntries)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FInventorySaveEntry>*)Z_Param__Result=P_THIS->MakeSaveEntries();
	P_NATIVE_END;
}
// ********** End Class UInventoryComponent Function MakeSaveEntries *******************************

// ********** Begin Class UInventoryComponent Function RemoveItem **********************************
struct Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics
{
	struct InventoryComponent_eventRemoveItem_Parms
	{
		UInventoryItemDefinition* ItemDefinition;
		int32 Quantity;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "CPP_Default_Quantity", "1" },
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveItem constinit property declarations ****************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemDefinition;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemoveItem constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemoveItem Property Definitions ***************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::NewProp_ItemDefinition = { "ItemDefinition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventRemoveItem_Parms, ItemDefinition), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventRemoveItem_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventoryComponent_eventRemoveItem_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventoryComponent_eventRemoveItem_Parms), &Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::NewProp_ItemDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::PropPointers) < 2048);
// ********** End Function RemoveItem Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "RemoveItem", 	Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::InventoryComponent_eventRemoveItem_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::InventoryComponent_eventRemoveItem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryComponent_RemoveItem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryComponent::execRemoveItem)
{
	P_GET_OBJECT(UInventoryItemDefinition,Z_Param_ItemDefinition);
	P_GET_PROPERTY(FIntProperty,Z_Param_Quantity);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->RemoveItem(Z_Param_ItemDefinition,Z_Param_Quantity);
	P_NATIVE_END;
}
// ********** End Class UInventoryComponent Function RemoveItem ************************************

// ********** Begin Class UInventoryComponent Function RemoveItemAtSlot ****************************
struct Z_Construct_UFunction_UInventoryComponent_RemoveItemAtSlot_Statics
{
	struct InventoryComponent_eventRemoveItemAtSlot_Parms
	{
		int32 SlotIndex;
		int32 Quantity;
		EInventoryOperationResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "CPP_Default_Quantity", "1" },
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveItemAtSlot constinit property declarations **********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemoveItemAtSlot constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemoveItemAtSlot Property Definitions *********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_RemoveItemAtSlot_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventRemoveItemAtSlot_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_RemoveItemAtSlot_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventRemoveItemAtSlot_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UInventoryComponent_RemoveItemAtSlot_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UInventoryComponent_RemoveItemAtSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventRemoveItemAtSlot_Parms, ReturnValue), Z_Construct_UEnum_InventorySystem_EInventoryOperationResult, METADATA_PARAMS(0, nullptr) }; // 935842388
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_RemoveItemAtSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_RemoveItemAtSlot_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_RemoveItemAtSlot_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_RemoveItemAtSlot_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_RemoveItemAtSlot_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_RemoveItemAtSlot_Statics::PropPointers) < 2048);
// ********** End Function RemoveItemAtSlot Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_RemoveItemAtSlot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "RemoveItemAtSlot", 	Z_Construct_UFunction_UInventoryComponent_RemoveItemAtSlot_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_RemoveItemAtSlot_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryComponent_RemoveItemAtSlot_Statics::InventoryComponent_eventRemoveItemAtSlot_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_RemoveItemAtSlot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryComponent_RemoveItemAtSlot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryComponent_RemoveItemAtSlot_Statics::InventoryComponent_eventRemoveItemAtSlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryComponent_RemoveItemAtSlot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_RemoveItemAtSlot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryComponent::execRemoveItemAtSlot)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_GET_PROPERTY(FIntProperty,Z_Param_Quantity);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EInventoryOperationResult*)Z_Param__Result=P_THIS->RemoveItemAtSlot(Z_Param_SlotIndex,Z_Param_Quantity);
	P_NATIVE_END;
}
// ********** End Class UInventoryComponent Function RemoveItemAtSlot ******************************

// ********** Begin Class UInventoryComponent Function UseItemAtSlot *******************************
struct Z_Construct_UFunction_UInventoryComponent_UseItemAtSlot_Statics
{
	struct InventoryComponent_eventUseItemAtSlot_Parms
	{
		int32 SlotIndex;
		AActor* User;
		EInventoryOperationResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "CPP_Default_User", "None" },
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function UseItemAtSlot constinit property declarations *************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_User;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UseItemAtSlot constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UseItemAtSlot Property Definitions ************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_UseItemAtSlot_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventUseItemAtSlot_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryComponent_UseItemAtSlot_Statics::NewProp_User = { "User", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventUseItemAtSlot_Parms, User), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UInventoryComponent_UseItemAtSlot_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UInventoryComponent_UseItemAtSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryComponent_eventUseItemAtSlot_Parms, ReturnValue), Z_Construct_UEnum_InventorySystem_EInventoryOperationResult, METADATA_PARAMS(0, nullptr) }; // 935842388
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_UseItemAtSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_UseItemAtSlot_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_UseItemAtSlot_Statics::NewProp_User,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_UseItemAtSlot_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_UseItemAtSlot_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_UseItemAtSlot_Statics::PropPointers) < 2048);
// ********** End Function UseItemAtSlot Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_UseItemAtSlot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "UseItemAtSlot", 	Z_Construct_UFunction_UInventoryComponent_UseItemAtSlot_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_UseItemAtSlot_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryComponent_UseItemAtSlot_Statics::InventoryComponent_eventUseItemAtSlot_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_UseItemAtSlot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryComponent_UseItemAtSlot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryComponent_UseItemAtSlot_Statics::InventoryComponent_eventUseItemAtSlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryComponent_UseItemAtSlot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_UseItemAtSlot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryComponent::execUseItemAtSlot)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_GET_OBJECT(AActor,Z_Param_User);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EInventoryOperationResult*)Z_Param__Result=P_THIS->UseItemAtSlot(Z_Param_SlotIndex,Z_Param_User);
	P_NATIVE_END;
}
// ********** End Class UInventoryComponent Function UseItemAtSlot *********************************

// ********** Begin Class UInventoryComponent ******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UInventoryComponent;
UClass* UInventoryComponent::GetPrivateStaticClass()
{
	using TClass = UInventoryComponent;
	if (!Z_Registration_Info_UClass_UInventoryComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("InventoryComponent"),
			Z_Registration_Info_UClass_UInventoryComponent.InnerSingleton,
			StaticRegisterNativesUInventoryComponent,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UInventoryComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UInventoryComponent_NoRegister()
{
	return UInventoryComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UInventoryComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Inventory" },
		{ "IncludePath", "Components/InventoryComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnInventoryChanged_MetaData[] = {
		{ "Category", "Inventory|Events" },
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnItemAdded_MetaData[] = {
		{ "Category", "Inventory|Events" },
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnItemsReceived_MetaData[] = {
		{ "Category", "Inventory|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xed\x95\x9c \xeb\xb2\x88\xec\x9d\x98 Add \xec\x9e\x91\xec\x97\x85\xec\x9c\xbc\xeb\xa1\x9c \xec\x8b\xa4\xec\xa0\x9c \xed\x9a\x8d\xeb\x93\x9d\xed\x95\x9c \xec\xb4\x9d\xec\x88\x98\xeb\x9f\x89\xec\x9d\x84 \xed\x95\x9c \xeb\xb2\x88\xeb\xa7\x8c \xec\xa0\x84\xeb\x8b\xac\xed\x95\x9c\xeb\x8b\xa4. */" },
#endif
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x95\x9c \xeb\xb2\x88\xec\x9d\x98 Add \xec\x9e\x91\xec\x97\x85\xec\x9c\xbc\xeb\xa1\x9c \xec\x8b\xa4\xec\xa0\x9c \xed\x9a\x8d\xeb\x93\x9d\xed\x95\x9c \xec\xb4\x9d\xec\x88\x98\xeb\x9f\x89\xec\x9d\x84 \xed\x95\x9c \xeb\xb2\x88\xeb\xa7\x8c \xec\xa0\x84\xeb\x8b\xac\xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnItemRemoved_MetaData[] = {
		{ "Category", "Inventory|Events" },
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnItemUsed_MetaData[] = {
		{ "Category", "Inventory|Events" },
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnItemDropped_MetaData[] = {
		{ "Category", "Inventory|Events" },
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnInventoryFull_MetaData[] = {
		{ "Category", "Inventory|Events" },
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxInventorySlots_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Slots_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/Components/InventoryComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UInventoryComponent constinit property declarations **********************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInventoryChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnItemAdded;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnItemsReceived;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnItemRemoved;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnItemUsed;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnItemDropped;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInventoryFull;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxInventorySlots;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Slots_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Slots;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UInventoryComponent constinit property declarations ************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddItem"), .Pointer = &UInventoryComponent::execAddItem },
		{ .NameUTF8 = UTF8TEXT("AddItemDetailed"), .Pointer = &UInventoryComponent::execAddItemDetailed },
		{ .NameUTF8 = UTF8TEXT("DropItemAtSlot"), .Pointer = &UInventoryComponent::execDropItemAtSlot },
		{ .NameUTF8 = UTF8TEXT("GetInventorySlots"), .Pointer = &UInventoryComponent::execGetInventorySlots },
		{ .NameUTF8 = UTF8TEXT("GetItemQuantity"), .Pointer = &UInventoryComponent::execGetItemQuantity },
		{ .NameUTF8 = UTF8TEXT("GetMaxInventorySlots"), .Pointer = &UInventoryComponent::execGetMaxInventorySlots },
		{ .NameUTF8 = UTF8TEXT("GetOccupiedSlotCount"), .Pointer = &UInventoryComponent::execGetOccupiedSlotCount },
		{ .NameUTF8 = UTF8TEXT("GetSlot"), .Pointer = &UInventoryComponent::execGetSlot },
		{ .NameUTF8 = UTF8TEXT("HasItem"), .Pointer = &UInventoryComponent::execHasItem },
		{ .NameUTF8 = UTF8TEXT("MakeSaveEntries"), .Pointer = &UInventoryComponent::execMakeSaveEntries },
		{ .NameUTF8 = UTF8TEXT("RemoveItem"), .Pointer = &UInventoryComponent::execRemoveItem },
		{ .NameUTF8 = UTF8TEXT("RemoveItemAtSlot"), .Pointer = &UInventoryComponent::execRemoveItemAtSlot },
		{ .NameUTF8 = UTF8TEXT("UseItemAtSlot"), .Pointer = &UInventoryComponent::execUseItemAtSlot },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventoryComponent_AddItem, "AddItem" }, // 4207663566
		{ &Z_Construct_UFunction_UInventoryComponent_AddItemDetailed, "AddItemDetailed" }, // 1759061137
		{ &Z_Construct_UFunction_UInventoryComponent_DropItemAtSlot, "DropItemAtSlot" }, // 2972917649
		{ &Z_Construct_UFunction_UInventoryComponent_GetInventorySlots, "GetInventorySlots" }, // 2222641969
		{ &Z_Construct_UFunction_UInventoryComponent_GetItemQuantity, "GetItemQuantity" }, // 3745672697
		{ &Z_Construct_UFunction_UInventoryComponent_GetMaxInventorySlots, "GetMaxInventorySlots" }, // 1099165485
		{ &Z_Construct_UFunction_UInventoryComponent_GetOccupiedSlotCount, "GetOccupiedSlotCount" }, // 2454046769
		{ &Z_Construct_UFunction_UInventoryComponent_GetSlot, "GetSlot" }, // 3407506312
		{ &Z_Construct_UFunction_UInventoryComponent_HasItem, "HasItem" }, // 432479783
		{ &Z_Construct_UFunction_UInventoryComponent_MakeSaveEntries, "MakeSaveEntries" }, // 851033004
		{ &Z_Construct_UFunction_UInventoryComponent_RemoveItem, "RemoveItem" }, // 1470483023
		{ &Z_Construct_UFunction_UInventoryComponent_RemoveItemAtSlot, "RemoveItemAtSlot" }, // 3116349923
		{ &Z_Construct_UFunction_UInventoryComponent_UseItemAtSlot, "UseItemAtSlot" }, // 2430783399
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UInventoryComponent_Statics

// ********** Begin Class UInventoryComponent Property Definitions *********************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnInventoryChanged = { "OnInventoryChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryComponent, OnInventoryChanged), Z_Construct_UDelegateFunction_InventorySystem_InventoryChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnInventoryChanged_MetaData), NewProp_OnInventoryChanged_MetaData) }; // 2541830174
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnItemAdded = { "OnItemAdded", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryComponent, OnItemAdded), Z_Construct_UDelegateFunction_InventorySystem_InventoryItemChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnItemAdded_MetaData), NewProp_OnItemAdded_MetaData) }; // 279436811
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnItemsReceived = { "OnItemsReceived", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryComponent, OnItemsReceived), Z_Construct_UDelegateFunction_InventorySystem_InventoryItemsReceivedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnItemsReceived_MetaData), NewProp_OnItemsReceived_MetaData) }; // 4059637908
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnItemRemoved = { "OnItemRemoved", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryComponent, OnItemRemoved), Z_Construct_UDelegateFunction_InventorySystem_InventoryItemChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnItemRemoved_MetaData), NewProp_OnItemRemoved_MetaData) }; // 279436811
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnItemUsed = { "OnItemUsed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryComponent, OnItemUsed), Z_Construct_UDelegateFunction_InventorySystem_InventoryItemUsedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnItemUsed_MetaData), NewProp_OnItemUsed_MetaData) }; // 2678427005
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnItemDropped = { "OnItemDropped", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryComponent, OnItemDropped), Z_Construct_UDelegateFunction_InventorySystem_InventoryItemChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnItemDropped_MetaData), NewProp_OnItemDropped_MetaData) }; // 279436811
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnInventoryFull = { "OnInventoryFull", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryComponent, OnInventoryFull), Z_Construct_UDelegateFunction_InventorySystem_InventoryFullSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnInventoryFull_MetaData), NewProp_OnInventoryFull_MetaData) }; // 1932690645
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UInventoryComponent_Statics::NewProp_MaxInventorySlots = { "MaxInventorySlots", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryComponent, MaxInventorySlots), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxInventorySlots_MetaData), NewProp_MaxInventorySlots_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UInventoryComponent_Statics::NewProp_Slots_Inner = { "Slots", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FInventorySlot, METADATA_PARAMS(0, nullptr) }; // 3353780059
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UInventoryComponent_Statics::NewProp_Slots = { "Slots", nullptr, (EPropertyFlags)0x0020080000020815, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryComponent, Slots), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Slots_MetaData), NewProp_Slots_MetaData) }; // 3353780059
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventoryComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnInventoryChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnItemAdded,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnItemsReceived,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnItemRemoved,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnItemUsed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnItemDropped,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnInventoryFull,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryComponent_Statics::NewProp_MaxInventorySlots,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryComponent_Statics::NewProp_Slots_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryComponent_Statics::NewProp_Slots,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryComponent_Statics::PropPointers) < 2048);
// ********** End Class UInventoryComponent Property Definitions ***********************************
UObject* (*const Z_Construct_UClass_UInventoryComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_InventorySystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventoryComponent_Statics::ClassParams = {
	&UInventoryComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UInventoryComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UInventoryComponent_Statics::Class_MetaDataParams)
};
void UInventoryComponent::StaticRegisterNativesUInventoryComponent()
{
	UClass* Class = UInventoryComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UInventoryComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UInventoryComponent()
{
	if (!Z_Registration_Info_UClass_UInventoryComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventoryComponent.OuterSingleton, Z_Construct_UClass_UInventoryComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInventoryComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UInventoryComponent);
UInventoryComponent::~UInventoryComponent() {}
// ********** End Class UInventoryComponent ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryComponent_h__Script_InventorySystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInventoryComponent, UInventoryComponent::StaticClass, TEXT("UInventoryComponent"), &Z_Registration_Info_UClass_UInventoryComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventoryComponent), 2608766128U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryComponent_h__Script_InventorySystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryComponent_h__Script_InventorySystem_3943738028{
	TEXT("/Script/InventorySystem"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryComponent_h__Script_InventorySystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryComponent_h__Script_InventorySystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
