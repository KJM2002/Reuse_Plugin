// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/InventorySlotWidgetBase.h"
#include "Layout/Margin.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeInventorySlotWidgetBase() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemDefinition_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventorySlotWidgetBase();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventorySlotWidgetBase_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryWidgetBase_NoRegister();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FMargin();
UMG_API UClass* Z_Construct_UClass_UBorder_NoRegister();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
UMG_API UClass* Z_Construct_UClass_UOverlay_NoRegister();
UMG_API UClass* Z_Construct_UClass_UScaleBox_NoRegister();
UMG_API UClass* Z_Construct_UClass_USizeBox_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_InventorySystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UInventorySlotWidgetBase Function FocusSlot ******************************
struct Z_Construct_UFunction_UInventorySlotWidgetBase_FocusSlot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function FocusSlot constinit property declarations *****************************
// ********** End Function FocusSlot constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySlotWidgetBase_FocusSlot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventorySlotWidgetBase, nullptr, "FocusSlot", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_FocusSlot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventorySlotWidgetBase_FocusSlot_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventorySlotWidgetBase_FocusSlot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventorySlotWidgetBase_FocusSlot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventorySlotWidgetBase::execFocusSlot)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FocusSlot();
	P_NATIVE_END;
}
// ********** End Class UInventorySlotWidgetBase Function FocusSlot ********************************

// ********** Begin Class UInventorySlotWidgetBase Function GetItemDefinition **********************
struct Z_Construct_UFunction_UInventorySlotWidgetBase_GetItemDefinition_Statics
{
	struct InventorySlotWidgetBase_eventGetItemDefinition_Parms
	{
		UInventoryItemDefinition* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetItemDefinition constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetItemDefinition constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetItemDefinition Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventorySlotWidgetBase_GetItemDefinition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventorySlotWidgetBase_eventGetItemDefinition_Parms, ReturnValue), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventorySlotWidgetBase_GetItemDefinition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventorySlotWidgetBase_GetItemDefinition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_GetItemDefinition_Statics::PropPointers) < 2048);
// ********** End Function GetItemDefinition Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySlotWidgetBase_GetItemDefinition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventorySlotWidgetBase, nullptr, "GetItemDefinition", 	Z_Construct_UFunction_UInventorySlotWidgetBase_GetItemDefinition_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_GetItemDefinition_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventorySlotWidgetBase_GetItemDefinition_Statics::InventorySlotWidgetBase_eventGetItemDefinition_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_GetItemDefinition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventorySlotWidgetBase_GetItemDefinition_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventorySlotWidgetBase_GetItemDefinition_Statics::InventorySlotWidgetBase_eventGetItemDefinition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventorySlotWidgetBase_GetItemDefinition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventorySlotWidgetBase_GetItemDefinition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventorySlotWidgetBase::execGetItemDefinition)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UInventoryItemDefinition**)Z_Param__Result=P_THIS->GetItemDefinition();
	P_NATIVE_END;
}
// ********** End Class UInventorySlotWidgetBase Function GetItemDefinition ************************

// ********** Begin Class UInventorySlotWidgetBase Function GetQuantity ****************************
struct Z_Construct_UFunction_UInventorySlotWidgetBase_GetQuantity_Statics
{
	struct InventorySlotWidgetBase_eventGetQuantity_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetQuantity constinit property declarations ***************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetQuantity constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetQuantity Property Definitions **************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventorySlotWidgetBase_GetQuantity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventorySlotWidgetBase_eventGetQuantity_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventorySlotWidgetBase_GetQuantity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventorySlotWidgetBase_GetQuantity_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_GetQuantity_Statics::PropPointers) < 2048);
// ********** End Function GetQuantity Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySlotWidgetBase_GetQuantity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventorySlotWidgetBase, nullptr, "GetQuantity", 	Z_Construct_UFunction_UInventorySlotWidgetBase_GetQuantity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_GetQuantity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventorySlotWidgetBase_GetQuantity_Statics::InventorySlotWidgetBase_eventGetQuantity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_GetQuantity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventorySlotWidgetBase_GetQuantity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventorySlotWidgetBase_GetQuantity_Statics::InventorySlotWidgetBase_eventGetQuantity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventorySlotWidgetBase_GetQuantity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventorySlotWidgetBase_GetQuantity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventorySlotWidgetBase::execGetQuantity)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetQuantity();
	P_NATIVE_END;
}
// ********** End Class UInventorySlotWidgetBase Function GetQuantity ******************************

// ********** Begin Class UInventorySlotWidgetBase Function GetSlotIndex ***************************
struct Z_Construct_UFunction_UInventorySlotWidgetBase_GetSlotIndex_Statics
{
	struct InventorySlotWidgetBase_eventGetSlotIndex_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSlotIndex constinit property declarations **************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSlotIndex constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSlotIndex Property Definitions *************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventorySlotWidgetBase_GetSlotIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventorySlotWidgetBase_eventGetSlotIndex_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventorySlotWidgetBase_GetSlotIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventorySlotWidgetBase_GetSlotIndex_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_GetSlotIndex_Statics::PropPointers) < 2048);
// ********** End Function GetSlotIndex Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySlotWidgetBase_GetSlotIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventorySlotWidgetBase, nullptr, "GetSlotIndex", 	Z_Construct_UFunction_UInventorySlotWidgetBase_GetSlotIndex_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_GetSlotIndex_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventorySlotWidgetBase_GetSlotIndex_Statics::InventorySlotWidgetBase_eventGetSlotIndex_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_GetSlotIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventorySlotWidgetBase_GetSlotIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventorySlotWidgetBase_GetSlotIndex_Statics::InventorySlotWidgetBase_eventGetSlotIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventorySlotWidgetBase_GetSlotIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventorySlotWidgetBase_GetSlotIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventorySlotWidgetBase::execGetSlotIndex)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetSlotIndex();
	P_NATIVE_END;
}
// ********** End Class UInventorySlotWidgetBase Function GetSlotIndex *****************************

// ********** Begin Class UInventorySlotWidgetBase Function HandleSelectClicked ********************
struct Z_Construct_UFunction_UInventorySlotWidgetBase_HandleSelectClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSelectClicked constinit property declarations *******************
// ********** End Function HandleSelectClicked constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySlotWidgetBase_HandleSelectClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventorySlotWidgetBase, nullptr, "HandleSelectClicked", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_HandleSelectClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventorySlotWidgetBase_HandleSelectClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventorySlotWidgetBase_HandleSelectClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventorySlotWidgetBase_HandleSelectClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventorySlotWidgetBase::execHandleSelectClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSelectClicked();
	P_NATIVE_END;
}
// ********** End Class UInventorySlotWidgetBase Function HandleSelectClicked **********************

// ********** Begin Class UInventorySlotWidgetBase Function InitializeSlot *************************
struct Z_Construct_UFunction_UInventorySlotWidgetBase_InitializeSlot_Statics
{
	struct InventorySlotWidgetBase_eventInitializeSlot_Parms
	{
		UInventoryWidgetBase* InOwnerInventoryWidget;
		int32 InSlotIndex;
		UInventoryItemDefinition* InItemDefinition;
		int32 InQuantity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InOwnerInventoryWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function InitializeSlot constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InOwnerInventoryWidget;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InSlotIndex;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InItemDefinition;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InQuantity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InitializeSlot constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InitializeSlot Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventorySlotWidgetBase_InitializeSlot_Statics::NewProp_InOwnerInventoryWidget = { "InOwnerInventoryWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventorySlotWidgetBase_eventInitializeSlot_Parms, InOwnerInventoryWidget), Z_Construct_UClass_UInventoryWidgetBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InOwnerInventoryWidget_MetaData), NewProp_InOwnerInventoryWidget_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventorySlotWidgetBase_InitializeSlot_Statics::NewProp_InSlotIndex = { "InSlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventorySlotWidgetBase_eventInitializeSlot_Parms, InSlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventorySlotWidgetBase_InitializeSlot_Statics::NewProp_InItemDefinition = { "InItemDefinition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventorySlotWidgetBase_eventInitializeSlot_Parms, InItemDefinition), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventorySlotWidgetBase_InitializeSlot_Statics::NewProp_InQuantity = { "InQuantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventorySlotWidgetBase_eventInitializeSlot_Parms, InQuantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventorySlotWidgetBase_InitializeSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventorySlotWidgetBase_InitializeSlot_Statics::NewProp_InOwnerInventoryWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventorySlotWidgetBase_InitializeSlot_Statics::NewProp_InSlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventorySlotWidgetBase_InitializeSlot_Statics::NewProp_InItemDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventorySlotWidgetBase_InitializeSlot_Statics::NewProp_InQuantity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_InitializeSlot_Statics::PropPointers) < 2048);
// ********** End Function InitializeSlot Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySlotWidgetBase_InitializeSlot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventorySlotWidgetBase, nullptr, "InitializeSlot", 	Z_Construct_UFunction_UInventorySlotWidgetBase_InitializeSlot_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_InitializeSlot_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventorySlotWidgetBase_InitializeSlot_Statics::InventorySlotWidgetBase_eventInitializeSlot_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_InitializeSlot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventorySlotWidgetBase_InitializeSlot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventorySlotWidgetBase_InitializeSlot_Statics::InventorySlotWidgetBase_eventInitializeSlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventorySlotWidgetBase_InitializeSlot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventorySlotWidgetBase_InitializeSlot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventorySlotWidgetBase::execInitializeSlot)
{
	P_GET_OBJECT(UInventoryWidgetBase,Z_Param_InOwnerInventoryWidget);
	P_GET_PROPERTY(FIntProperty,Z_Param_InSlotIndex);
	P_GET_OBJECT(UInventoryItemDefinition,Z_Param_InItemDefinition);
	P_GET_PROPERTY(FIntProperty,Z_Param_InQuantity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeSlot(Z_Param_InOwnerInventoryWidget,Z_Param_InSlotIndex,Z_Param_InItemDefinition,Z_Param_InQuantity);
	P_NATIVE_END;
}
// ********** End Class UInventorySlotWidgetBase Function InitializeSlot ***************************

// ********** Begin Class UInventorySlotWidgetBase Function OnSelectionVisualChanged ***************
struct InventorySlotWidgetBase_eventOnSelectionVisualChanged_Parms
{
	bool bIsSelected;
};
static FName NAME_UInventorySlotWidgetBase_OnSelectionVisualChanged = FName(TEXT("OnSelectionVisualChanged"));
void UInventorySlotWidgetBase::OnSelectionVisualChanged(bool bIsSelected)
{
	InventorySlotWidgetBase_eventOnSelectionVisualChanged_Parms Parms;
	Parms.bIsSelected=bIsSelected ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_UInventorySlotWidgetBase_OnSelectionVisualChanged);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UInventorySlotWidgetBase_OnSelectionVisualChanged_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnSelectionVisualChanged constinit property declarations **************
	static void NewProp_bIsSelected_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsSelected;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnSelectionVisualChanged constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnSelectionVisualChanged Property Definitions *************************
void Z_Construct_UFunction_UInventorySlotWidgetBase_OnSelectionVisualChanged_Statics::NewProp_bIsSelected_SetBit(void* Obj)
{
	((InventorySlotWidgetBase_eventOnSelectionVisualChanged_Parms*)Obj)->bIsSelected = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventorySlotWidgetBase_OnSelectionVisualChanged_Statics::NewProp_bIsSelected = { "bIsSelected", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventorySlotWidgetBase_eventOnSelectionVisualChanged_Parms), &Z_Construct_UFunction_UInventorySlotWidgetBase_OnSelectionVisualChanged_Statics::NewProp_bIsSelected_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventorySlotWidgetBase_OnSelectionVisualChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventorySlotWidgetBase_OnSelectionVisualChanged_Statics::NewProp_bIsSelected,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_OnSelectionVisualChanged_Statics::PropPointers) < 2048);
// ********** End Function OnSelectionVisualChanged Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySlotWidgetBase_OnSelectionVisualChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventorySlotWidgetBase, nullptr, "OnSelectionVisualChanged", 	Z_Construct_UFunction_UInventorySlotWidgetBase_OnSelectionVisualChanged_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_OnSelectionVisualChanged_Statics::PropPointers), 
sizeof(InventorySlotWidgetBase_eventOnSelectionVisualChanged_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_OnSelectionVisualChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventorySlotWidgetBase_OnSelectionVisualChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InventorySlotWidgetBase_eventOnSelectionVisualChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventorySlotWidgetBase_OnSelectionVisualChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventorySlotWidgetBase_OnSelectionVisualChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UInventorySlotWidgetBase Function OnSelectionVisualChanged *****************

// ********** Begin Class UInventorySlotWidgetBase Function OnSlotRefreshed ************************
static FName NAME_UInventorySlotWidgetBase_OnSlotRefreshed = FName(TEXT("OnSlotRefreshed"));
void UInventorySlotWidgetBase::OnSlotRefreshed()
{
	UFunction* Func = FindFunctionChecked(NAME_UInventorySlotWidgetBase_OnSlotRefreshed);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UInventorySlotWidgetBase_OnSlotRefreshed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnSlotRefreshed constinit property declarations ***********************
// ********** End Function OnSlotRefreshed constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySlotWidgetBase_OnSlotRefreshed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventorySlotWidgetBase, nullptr, "OnSlotRefreshed", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_OnSlotRefreshed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventorySlotWidgetBase_OnSlotRefreshed_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventorySlotWidgetBase_OnSlotRefreshed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventorySlotWidgetBase_OnSlotRefreshed_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UInventorySlotWidgetBase Function OnSlotRefreshed **************************

// ********** Begin Class UInventorySlotWidgetBase Function RefreshSlot ****************************
struct Z_Construct_UFunction_UInventorySlotWidgetBase_RefreshSlot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshSlot constinit property declarations ***************************
// ********** End Function RefreshSlot constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySlotWidgetBase_RefreshSlot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventorySlotWidgetBase, nullptr, "RefreshSlot", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_RefreshSlot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventorySlotWidgetBase_RefreshSlot_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventorySlotWidgetBase_RefreshSlot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventorySlotWidgetBase_RefreshSlot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventorySlotWidgetBase::execRefreshSlot)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshSlot();
	P_NATIVE_END;
}
// ********** End Class UInventorySlotWidgetBase Function RefreshSlot ******************************

// ********** Begin Class UInventorySlotWidgetBase Function SetSelected ****************************
struct Z_Construct_UFunction_UInventorySlotWidgetBase_SetSelected_Statics
{
	struct InventorySlotWidgetBase_eventSetSelected_Parms
	{
		bool bInSelected;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetSelected constinit property declarations ***************************
	static void NewProp_bInSelected_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInSelected;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSelected constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSelected Property Definitions **************************************
void Z_Construct_UFunction_UInventorySlotWidgetBase_SetSelected_Statics::NewProp_bInSelected_SetBit(void* Obj)
{
	((InventorySlotWidgetBase_eventSetSelected_Parms*)Obj)->bInSelected = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventorySlotWidgetBase_SetSelected_Statics::NewProp_bInSelected = { "bInSelected", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventorySlotWidgetBase_eventSetSelected_Parms), &Z_Construct_UFunction_UInventorySlotWidgetBase_SetSelected_Statics::NewProp_bInSelected_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventorySlotWidgetBase_SetSelected_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventorySlotWidgetBase_SetSelected_Statics::NewProp_bInSelected,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_SetSelected_Statics::PropPointers) < 2048);
// ********** End Function SetSelected Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySlotWidgetBase_SetSelected_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventorySlotWidgetBase, nullptr, "SetSelected", 	Z_Construct_UFunction_UInventorySlotWidgetBase_SetSelected_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_SetSelected_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventorySlotWidgetBase_SetSelected_Statics::InventorySlotWidgetBase_eventSetSelected_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_SetSelected_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventorySlotWidgetBase_SetSelected_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventorySlotWidgetBase_SetSelected_Statics::InventorySlotWidgetBase_eventSetSelected_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventorySlotWidgetBase_SetSelected()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventorySlotWidgetBase_SetSelected_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventorySlotWidgetBase::execSetSelected)
{
	P_GET_UBOOL(Z_Param_bInSelected);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSelected(Z_Param_bInSelected);
	P_NATIVE_END;
}
// ********** End Class UInventorySlotWidgetBase Function SetSelected ******************************

// ********** Begin Class UInventorySlotWidgetBase Function ShouldShowUnavailable ******************
struct InventorySlotWidgetBase_eventShouldShowUnavailable_Parms
{
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	InventorySlotWidgetBase_eventShouldShowUnavailable_Parms()
		: ReturnValue(false)
	{
	}
};
static FName NAME_UInventorySlotWidgetBase_ShouldShowUnavailable = FName(TEXT("ShouldShowUnavailable"));
bool UInventorySlotWidgetBase::ShouldShowUnavailable() const
{
	UFunction* Func = FindFunctionChecked(NAME_UInventorySlotWidgetBase_ShouldShowUnavailable);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		InventorySlotWidgetBase_eventShouldShowUnavailable_Parms Parms;
		const_cast<UInventorySlotWidgetBase*>(this)->ProcessEvent(Func,&Parms);
		return !!Parms.ReturnValue;
	}
	else
	{
		return const_cast<UInventorySlotWidgetBase*>(this)->ShouldShowUnavailable_Implementation();
	}
}
struct Z_Construct_UFunction_UInventorySlotWidgetBase_ShouldShowUnavailable_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ShouldShowUnavailable constinit property declarations *****************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ShouldShowUnavailable constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ShouldShowUnavailable Property Definitions ****************************
void Z_Construct_UFunction_UInventorySlotWidgetBase_ShouldShowUnavailable_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventorySlotWidgetBase_eventShouldShowUnavailable_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventorySlotWidgetBase_ShouldShowUnavailable_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventorySlotWidgetBase_eventShouldShowUnavailable_Parms), &Z_Construct_UFunction_UInventorySlotWidgetBase_ShouldShowUnavailable_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventorySlotWidgetBase_ShouldShowUnavailable_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventorySlotWidgetBase_ShouldShowUnavailable_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_ShouldShowUnavailable_Statics::PropPointers) < 2048);
// ********** End Function ShouldShowUnavailable Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventorySlotWidgetBase_ShouldShowUnavailable_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventorySlotWidgetBase, nullptr, "ShouldShowUnavailable", 	Z_Construct_UFunction_UInventorySlotWidgetBase_ShouldShowUnavailable_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_ShouldShowUnavailable_Statics::PropPointers), 
sizeof(InventorySlotWidgetBase_eventShouldShowUnavailable_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventorySlotWidgetBase_ShouldShowUnavailable_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventorySlotWidgetBase_ShouldShowUnavailable_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InventorySlotWidgetBase_eventShouldShowUnavailable_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventorySlotWidgetBase_ShouldShowUnavailable()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventorySlotWidgetBase_ShouldShowUnavailable_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventorySlotWidgetBase::execShouldShowUnavailable)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ShouldShowUnavailable_Implementation();
	P_NATIVE_END;
}
// ********** End Class UInventorySlotWidgetBase Function ShouldShowUnavailable ********************

// ********** Begin Class UInventorySlotWidgetBase *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UInventorySlotWidgetBase;
UClass* UInventorySlotWidgetBase::GetPrivateStaticClass()
{
	using TClass = UInventorySlotWidgetBase;
	if (!Z_Registration_Info_UClass_UInventorySlotWidgetBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("InventorySlotWidgetBase"),
			Z_Registration_Info_UClass_UInventorySlotWidgetBase.InnerSingleton,
			StaticRegisterNativesUInventorySlotWidgetBase,
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
	return Z_Registration_Info_UClass_UInventorySlotWidgetBase.InnerSingleton;
}
UClass* Z_Construct_UClass_UInventorySlotWidgetBase_NoRegister()
{
	return UInventorySlotWidgetBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UInventorySlotWidgetBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xec\x8a\xac\xeb\xa1\xaf\xec\x9d\x98 \xea\xb3\xb5\xed\x86\xb5 \xeb\x8f\x99\xec\x9e\x91\xec\x9d\x84 \xeb\x8b\xb4\xeb\x8b\xb9\xed\x95\x9c\xeb\x8b\xa4.\n * \xed\x8c\x8c\xec\x83\x9d Widget Blueprint\xeb\x8a\x94 BindWidget \xec\x9d\xb4\xeb\xa6\x84\xec\x97\x90 \xeb\xa7\x9e\xec\xb6\xb0 UI\xeb\xa5\xbc \xeb\xb0\xb0\xec\xb9\x98\xed\x95\x98\xea\xb3\xa0 \xeb\x94\x94\xec\x9e\x90\xec\x9d\xb8\xeb\xa7\x8c \xed\x95\x9c\xeb\x8b\xa4.\n */" },
#endif
		{ "IncludePath", "UI/InventorySlotWidgetBase.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xec\x8a\xac\xeb\xa1\xaf\xec\x9d\x98 \xea\xb3\xb5\xed\x86\xb5 \xeb\x8f\x99\xec\x9e\x91\xec\x9d\x84 \xeb\x8b\xb4\xeb\x8b\xb9\xed\x95\x9c\xeb\x8b\xa4.\n\xed\x8c\x8c\xec\x83\x9d Widget Blueprint\xeb\x8a\x94 BindWidget \xec\x9d\xb4\xeb\xa6\x84\xec\x97\x90 \xeb\xa7\x9e\xec\xb6\xb0 UI\xeb\xa5\xbc \xeb\xb0\xb0\xec\xb9\x98\xed\x95\x98\xea\xb3\xa0 \xeb\x94\x94\xec\x9e\x90\xec\x9d\xb8\xeb\xa7\x8c \xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Button_Select_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xeb\xb0\x98\xeb\x93\x9c\xec\x8b\x9c WBP_InventorySlot\xec\x97\x90 \xea\xb0\x99\xec\x9d\x80 \xec\x9d\xb4\xeb\xa6\x84\xec\x9d\x98 Button\xec\x9d\xb4 \xec\x9e\x88\xec\x96\xb4\xec\x95\xbc \xed\x95\x9c\xeb\x8b\xa4. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb0\x98\xeb\x93\x9c\xec\x8b\x9c WBP_InventorySlot\xec\x97\x90 \xea\xb0\x99\xec\x9d\x80 \xec\x9d\xb4\xeb\xa6\x84\xec\x9d\x98 Button\xec\x9d\xb4 \xec\x9e\x88\xec\x96\xb4\xec\x95\xbc \xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Overlay_Slot_MetaData[] = {
		{ "BindWidgetOptional", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xec\x95\x84\xec\x9d\xb4\xec\xbd\x98\xec\x9d\x98 \xed\x81\xac\xea\xb8\xb0 \xec\xa0\x9c\xed\x95\x9c\xea\xb3\xbc \xea\xb7\xb8\xeb\xa6\xac\xea\xb8\xb0 \xec\x88\x9c\xec\x84\x9c\xeb\xa5\xbc C++\xea\xb0\x80 \xeb\xb3\xb4\xec\x9e\xa5\xed\x95\x98\xea\xb8\xb0 \xec\x9c\x84\xed\x95\xb4 \xec\x82\xac\xec\x9a\xa9\xed\x95\x9c\xeb\x8b\xa4. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x95\x84\xec\x9d\xb4\xec\xbd\x98\xec\x9d\x98 \xed\x81\xac\xea\xb8\xb0 \xec\xa0\x9c\xed\x95\x9c\xea\xb3\xbc \xea\xb7\xb8\xeb\xa6\xac\xea\xb8\xb0 \xec\x88\x9c\xec\x84\x9c\xeb\xa5\xbc C++\xea\xb0\x80 \xeb\xb3\xb4\xec\x9e\xa5\xed\x95\x98\xea\xb8\xb0 \xec\x9c\x84\xed\x95\xb4 \xec\x82\xac\xec\x9a\xa9\xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Border_Background_MetaData[] = {
		{ "BindWidgetOptional", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xea\xb0\x81 \xeb\xb9\x88 \xec\x8a\xac\xeb\xa1\xaf\xea\xb3\xbc \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xec\x8a\xac\xeb\xa1\xaf\xec\x97\x90 \xea\xb3\xb5\xed\x86\xb5\xec\x9c\xbc\xeb\xa1\x9c \xec\x82\xac\xec\x9a\xa9\xed\x95\x98\xeb\x8a\x94 Grid \xed\x94\x84\xeb\xa0\x88\xec\x9e\x84\xec\x9d\xb4\xeb\x8b\xa4. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xea\xb0\x81 \xeb\xb9\x88 \xec\x8a\xac\xeb\xa1\xaf\xea\xb3\xbc \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xec\x8a\xac\xeb\xa1\xaf\xec\x97\x90 \xea\xb3\xb5\xed\x86\xb5\xec\x9c\xbc\xeb\xa1\x9c \xec\x82\xac\xec\x9a\xa9\xed\x95\x98\xeb\x8a\x94 Grid \xed\x94\x84\xeb\xa0\x88\xec\x9e\x84\xec\x9d\xb4\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotBackgroundTexture_MetaData[] = {
		{ "Category", "Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xeb\xb9\x84\xec\x9b\x8c \xeb\x91\x90\xeb\xa9\xb4 \xed\x95\xb4\xec\x83\x81\xeb\x8f\x84 \xeb\x8f\x85\xeb\xa6\xbd\xec\xa0\x81\xec\x9d\xb8 Rounded Box\xeb\xa5\xbc \xec\x82\xac\xec\x9a\xa9\xed\x95\x9c\xeb\x8b\xa4. \xed\x95\x84\xec\x9a\x94\xed\x95\x9c \xea\xb2\xbd\xec\x9a\xb0\xec\x97\x90\xeb\xa7\x8c \xec\xbb\xa4\xec\x8a\xa4\xed\x85\x80 Texture\xeb\xa5\xbc \xec\xa7\x80\xec\xa0\x95\xed\x95\x9c\xeb\x8b\xa4. */" },
#endif
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb9\x84\xec\x9b\x8c \xeb\x91\x90\xeb\xa9\xb4 \xed\x95\xb4\xec\x83\x81\xeb\x8f\x84 \xeb\x8f\x85\xeb\xa6\xbd\xec\xa0\x81\xec\x9d\xb8 Rounded Box\xeb\xa5\xbc \xec\x82\xac\xec\x9a\xa9\xed\x95\x9c\xeb\x8b\xa4. \xed\x95\x84\xec\x9a\x94\xed\x95\x9c \xea\xb2\xbd\xec\x9a\xb0\xec\x97\x90\xeb\xa7\x8c \xec\xbb\xa4\xec\x8a\xa4\xed\x85\x80 Texture\xeb\xa5\xbc \xec\xa7\x80\xec\xa0\x95\xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SizeBox_Slot_MetaData[] = {
		{ "BindWidgetOptional", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xec\x9e\x88\xec\x9c\xbc\xeb\xa9\xb4 C++\xea\xb0\x80 \xec\x84\xa0\xed\x83\x9d \xec\x83\x81\xed\x83\x9c\xec\x99\x80 \xea\xb4\x80\xea\xb3\x84\xec\x97\x86\xec\x9d\xb4 \xec\xa0\x84\xec\xb2\xb4 \xec\x8a\xac\xeb\xa1\xaf\xec\x9d\x84 \xec\xa0\x95\xec\x82\xac\xea\xb0\x81\xed\x98\x95\xec\x9c\xbc\xeb\xa1\x9c \xea\xb3\xa0\xec\xa0\x95\xed\x95\x9c\xeb\x8b\xa4. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9e\x88\xec\x9c\xbc\xeb\xa9\xb4 C++\xea\xb0\x80 \xec\x84\xa0\xed\x83\x9d \xec\x83\x81\xed\x83\x9c\xec\x99\x80 \xea\xb4\x80\xea\xb3\x84\xec\x97\x86\xec\x9d\xb4 \xec\xa0\x84\xec\xb2\xb4 \xec\x8a\xac\xeb\xa1\xaf\xec\x9d\x84 \xec\xa0\x95\xec\x82\xac\xea\xb0\x81\xed\x98\x95\xec\x9c\xbc\xeb\xa1\x9c \xea\xb3\xa0\xec\xa0\x95\xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotDisplaySize_MetaData[] = {
		{ "Category", "Inventory|UI" },
		{ "ClampMin", "1.0" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Image_ItemIcon_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xeb\xb0\x98\xeb\x93\x9c\xec\x8b\x9c WBP_InventorySlot\xec\x97\x90 \xea\xb0\x99\xec\x9d\x80 \xec\x9d\xb4\xeb\xa6\x84\xec\x9d\x98 Image\xea\xb0\x80 \xec\x9e\x88\xec\x96\xb4\xec\x95\xbc \xed\x95\x9c\xeb\x8b\xa4. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb0\x98\xeb\x93\x9c\xec\x8b\x9c WBP_InventorySlot\xec\x97\x90 \xea\xb0\x99\xec\x9d\x80 \xec\x9d\xb4\xeb\xa6\x84\xec\x9d\x98 Image\xea\xb0\x80 \xec\x9e\x88\xec\x96\xb4\xec\x95\xbc \xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SizeBox_Icon_MetaData[] = {
		{ "BindWidgetOptional", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xec\x9e\x88\xec\x9c\xbc\xeb\xa9\xb4 C++\xea\xb0\x80 \xec\x8a\xac\xeb\xa1\xaf \xec\x95\x84\xec\x9d\xb4\xec\xbd\x98 \xed\x91\x9c\xec\x8b\x9c \xec\x98\x81\xec\x97\xad\xec\x9d\x84 \xec\xa0\x95\xec\x82\xac\xea\xb0\x81\xed\x98\x95\xec\x9c\xbc\xeb\xa1\x9c \xea\xb3\xa0\xec\xa0\x95\xed\x95\x9c\xeb\x8b\xa4. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9e\x88\xec\x9c\xbc\xeb\xa9\xb4 C++\xea\xb0\x80 \xec\x8a\xac\xeb\xa1\xaf \xec\x95\x84\xec\x9d\xb4\xec\xbd\x98 \xed\x91\x9c\xec\x8b\x9c \xec\x98\x81\xec\x97\xad\xec\x9d\x84 \xec\xa0\x95\xec\x82\xac\xea\xb0\x81\xed\x98\x95\xec\x9c\xbc\xeb\xa1\x9c \xea\xb3\xa0\xec\xa0\x95\xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScaleBox_Icon_MetaData[] = {
		{ "BindWidgetOptional", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xec\x9e\x88\xec\x9c\xbc\xeb\xa9\xb4 C++\xea\xb0\x80 \xec\x9b\x90\xeb\xb3\xb8 \xeb\xb9\x84\xec\x9c\xa8\xec\x9d\x84 \xeb\xb3\xb4\xec\xa1\xb4\xed\x95\x98\xeb\x8a\x94 Scale To Fit\xec\x9d\x84 \xea\xb0\x95\xec\xa0\x9c\xed\x95\x9c\xeb\x8b\xa4. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9e\x88\xec\x9c\xbc\xeb\xa9\xb4 C++\xea\xb0\x80 \xec\x9b\x90\xeb\xb3\xb8 \xeb\xb9\x84\xec\x9c\xa8\xec\x9d\x84 \xeb\xb3\xb4\xec\xa1\xb4\xed\x95\x98\xeb\x8a\x94 Scale To Fit\xec\x9d\x84 \xea\xb0\x95\xec\xa0\x9c\xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IconDisplaySize_MetaData[] = {
		{ "Category", "Inventory|UI" },
		{ "ClampMin", "1.0" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_Quantity_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xeb\xb0\x98\xeb\x93\x9c\xec\x8b\x9c WBP_InventorySlot\xec\x97\x90 \xea\xb0\x99\xec\x9d\x80 \xec\x9d\xb4\xeb\xa6\x84\xec\x9d\x98 Text Block\xec\x9d\xb4 \xec\x9e\x88\xec\x96\xb4\xec\x95\xbc \xed\x95\x9c\xeb\x8b\xa4. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb0\x98\xeb\x93\x9c\xec\x8b\x9c WBP_InventorySlot\xec\x97\x90 \xea\xb0\x99\xec\x9d\x80 \xec\x9d\xb4\xeb\xa6\x84\xec\x9d\x98 Text Block\xec\x9d\xb4 \xec\x9e\x88\xec\x96\xb4\xec\x95\xbc \xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QuantityPadding_MetaData[] = {
		{ "Category", "Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xec\x88\x98\xeb\x9f\x89 Text\xeb\xa5\xbc \xec\x8a\xac\xeb\xa1\xaf \xec\x9a\xb0\xec\xb8\xa1 \xed\x95\x98\xeb\x8b\xa8\xec\x97\x90\xec\x84\x9c \xec\x95\x88\xec\xaa\xbd\xec\x9c\xbc\xeb\xa1\x9c \xeb\x9d\x84\xec\x9a\xb0\xeb\x8a\x94 \xec\x97\xac\xeb\xb0\xb1\xec\x9d\xb4\xeb\x8b\xa4. */" },
#endif
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x88\x98\xeb\x9f\x89 Text\xeb\xa5\xbc \xec\x8a\xac\xeb\xa1\xaf \xec\x9a\xb0\xec\xb8\xa1 \xed\x95\x98\xeb\x8b\xa8\xec\x97\x90\xec\x84\x9c \xec\x95\x88\xec\xaa\xbd\xec\x9c\xbc\xeb\xa1\x9c \xeb\x9d\x84\xec\x9a\xb0\xeb\x8a\x94 \xec\x97\xac\xeb\xb0\xb1\xec\x9d\xb4\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Image_Selection_MetaData[] = {
		{ "BindWidgetOptional", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xec\x84\xa0\xed\x83\x9d \xed\x91\x9c\xec\x8b\x9c\xea\xb0\x80 \xed\x95\x84\xec\x9a\x94\xed\x95\xa0 \xeb\x95\x8c \xea\xb0\x99\xec\x9d\x80 \xec\x9d\xb4\xeb\xa6\x84\xec\x9d\x98 Image\xeb\xa5\xbc \xec\x84\xa0\xed\x83\x9d\xec\xa0\x81\xec\x9c\xbc\xeb\xa1\x9c \xeb\xb0\xb0\xec\xb9\x98\xed\x95\x9c\xeb\x8b\xa4. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x84\xa0\xed\x83\x9d \xed\x91\x9c\xec\x8b\x9c\xea\xb0\x80 \xed\x95\x84\xec\x9a\x94\xed\x95\xa0 \xeb\x95\x8c \xea\xb0\x99\xec\x9d\x80 \xec\x9d\xb4\xeb\xa6\x84\xec\x9d\x98 Image\xeb\xa5\xbc \xec\x84\xa0\xed\x83\x9d\xec\xa0\x81\xec\x9c\xbc\xeb\xa1\x9c \xeb\xb0\xb0\xec\xb9\x98\xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Border_Unavailable_MetaData[] = {
		{ "BindWidgetOptional", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xec\x82\xac\xec\x9a\xa9 \xeb\xb6\x88\xea\xb0\x80 \xec\x9d\x8c\xec\x98\x81\xec\x9d\xb4 \xed\x95\x84\xec\x9a\x94\xed\x95\xa0 \xeb\x95\x8c \xea\xb0\x99\xec\x9d\x80 \xec\x9d\xb4\xeb\xa6\x84\xec\x9d\x98 Border\xeb\xa5\xbc \xec\x84\xa0\xed\x83\x9d\xec\xa0\x81\xec\x9c\xbc\xeb\xa1\x9c \xeb\xb0\xb0\xec\xb9\x98\xed\x95\x9c\xeb\x8b\xa4. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x82\xac\xec\x9a\xa9 \xeb\xb6\x88\xea\xb0\x80 \xec\x9d\x8c\xec\x98\x81\xec\x9d\xb4 \xed\x95\x84\xec\x9a\x94\xed\x95\xa0 \xeb\x95\x8c \xea\xb0\x99\xec\x9d\x80 \xec\x9d\xb4\xeb\xa6\x84\xec\x9d\x98 Border\xeb\xa5\xbc \xec\x84\xa0\xed\x83\x9d\xec\xa0\x81\xec\x9c\xbc\xeb\xa1\x9c \xeb\xb0\xb0\xec\xb9\x98\xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OwnerInventoryWidget_MetaData[] = {
		{ "Category", "Inventory|UI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemDefinition_MetaData[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotIndex_MetaData[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quantity_MetaData[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSelected_MetaData[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventorySlotWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UInventorySlotWidgetBase constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Button_Select;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Overlay_Slot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Border_Background;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_SlotBackgroundTexture;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SizeBox_Slot;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SlotDisplaySize;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Image_ItemIcon;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SizeBox_Icon;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ScaleBox_Icon;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_IconDisplaySize;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Text_Quantity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_QuantityPadding;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Image_Selection;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Border_Unavailable;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OwnerInventoryWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemDefinition;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static void NewProp_bSelected_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSelected;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UInventorySlotWidgetBase constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("FocusSlot"), .Pointer = &UInventorySlotWidgetBase::execFocusSlot },
		{ .NameUTF8 = UTF8TEXT("GetItemDefinition"), .Pointer = &UInventorySlotWidgetBase::execGetItemDefinition },
		{ .NameUTF8 = UTF8TEXT("GetQuantity"), .Pointer = &UInventorySlotWidgetBase::execGetQuantity },
		{ .NameUTF8 = UTF8TEXT("GetSlotIndex"), .Pointer = &UInventorySlotWidgetBase::execGetSlotIndex },
		{ .NameUTF8 = UTF8TEXT("HandleSelectClicked"), .Pointer = &UInventorySlotWidgetBase::execHandleSelectClicked },
		{ .NameUTF8 = UTF8TEXT("InitializeSlot"), .Pointer = &UInventorySlotWidgetBase::execInitializeSlot },
		{ .NameUTF8 = UTF8TEXT("RefreshSlot"), .Pointer = &UInventorySlotWidgetBase::execRefreshSlot },
		{ .NameUTF8 = UTF8TEXT("SetSelected"), .Pointer = &UInventorySlotWidgetBase::execSetSelected },
		{ .NameUTF8 = UTF8TEXT("ShouldShowUnavailable"), .Pointer = &UInventorySlotWidgetBase::execShouldShowUnavailable },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventorySlotWidgetBase_FocusSlot, "FocusSlot" }, // 2350599952
		{ &Z_Construct_UFunction_UInventorySlotWidgetBase_GetItemDefinition, "GetItemDefinition" }, // 2756767288
		{ &Z_Construct_UFunction_UInventorySlotWidgetBase_GetQuantity, "GetQuantity" }, // 3089204065
		{ &Z_Construct_UFunction_UInventorySlotWidgetBase_GetSlotIndex, "GetSlotIndex" }, // 2077975419
		{ &Z_Construct_UFunction_UInventorySlotWidgetBase_HandleSelectClicked, "HandleSelectClicked" }, // 2380931266
		{ &Z_Construct_UFunction_UInventorySlotWidgetBase_InitializeSlot, "InitializeSlot" }, // 2725505557
		{ &Z_Construct_UFunction_UInventorySlotWidgetBase_OnSelectionVisualChanged, "OnSelectionVisualChanged" }, // 665283658
		{ &Z_Construct_UFunction_UInventorySlotWidgetBase_OnSlotRefreshed, "OnSlotRefreshed" }, // 1638205186
		{ &Z_Construct_UFunction_UInventorySlotWidgetBase_RefreshSlot, "RefreshSlot" }, // 1438962192
		{ &Z_Construct_UFunction_UInventorySlotWidgetBase_SetSelected, "SetSelected" }, // 60859226
		{ &Z_Construct_UFunction_UInventorySlotWidgetBase_ShouldShowUnavailable, "ShouldShowUnavailable" }, // 4005271094
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventorySlotWidgetBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UInventorySlotWidgetBase_Statics

// ********** Begin Class UInventorySlotWidgetBase Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_Button_Select = { "Button_Select", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotWidgetBase, Button_Select), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Button_Select_MetaData), NewProp_Button_Select_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_Overlay_Slot = { "Overlay_Slot", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotWidgetBase, Overlay_Slot), Z_Construct_UClass_UOverlay_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Overlay_Slot_MetaData), NewProp_Overlay_Slot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_Border_Background = { "Border_Background", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotWidgetBase, Border_Background), Z_Construct_UClass_UBorder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Border_Background_MetaData), NewProp_Border_Background_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_SlotBackgroundTexture = { "SlotBackgroundTexture", nullptr, (EPropertyFlags)0x0024080000010015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotWidgetBase, SlotBackgroundTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotBackgroundTexture_MetaData), NewProp_SlotBackgroundTexture_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_SizeBox_Slot = { "SizeBox_Slot", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotWidgetBase, SizeBox_Slot), Z_Construct_UClass_USizeBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SizeBox_Slot_MetaData), NewProp_SizeBox_Slot_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_SlotDisplaySize = { "SlotDisplaySize", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotWidgetBase, SlotDisplaySize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotDisplaySize_MetaData), NewProp_SlotDisplaySize_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_Image_ItemIcon = { "Image_ItemIcon", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotWidgetBase, Image_ItemIcon), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Image_ItemIcon_MetaData), NewProp_Image_ItemIcon_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_SizeBox_Icon = { "SizeBox_Icon", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotWidgetBase, SizeBox_Icon), Z_Construct_UClass_USizeBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SizeBox_Icon_MetaData), NewProp_SizeBox_Icon_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_ScaleBox_Icon = { "ScaleBox_Icon", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotWidgetBase, ScaleBox_Icon), Z_Construct_UClass_UScaleBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScaleBox_Icon_MetaData), NewProp_ScaleBox_Icon_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_IconDisplaySize = { "IconDisplaySize", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotWidgetBase, IconDisplaySize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IconDisplaySize_MetaData), NewProp_IconDisplaySize_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_Text_Quantity = { "Text_Quantity", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotWidgetBase, Text_Quantity), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_Quantity_MetaData), NewProp_Text_Quantity_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_QuantityPadding = { "QuantityPadding", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotWidgetBase, QuantityPadding), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QuantityPadding_MetaData), NewProp_QuantityPadding_MetaData) }; // 4099648758
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_Image_Selection = { "Image_Selection", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotWidgetBase, Image_Selection), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Image_Selection_MetaData), NewProp_Image_Selection_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_Border_Unavailable = { "Border_Unavailable", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotWidgetBase, Border_Unavailable), Z_Construct_UClass_UBorder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Border_Unavailable_MetaData), NewProp_Border_Unavailable_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_OwnerInventoryWidget = { "OwnerInventoryWidget", nullptr, (EPropertyFlags)0x012408000008201c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotWidgetBase, OwnerInventoryWidget), Z_Construct_UClass_UInventoryWidgetBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwnerInventoryWidget_MetaData), NewProp_OwnerInventoryWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_ItemDefinition = { "ItemDefinition", nullptr, (EPropertyFlags)0x0124080000002014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotWidgetBase, ItemDefinition), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemDefinition_MetaData), NewProp_ItemDefinition_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0020080000002014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotWidgetBase, SlotIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotIndex_MetaData), NewProp_SlotIndex_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0020080000002014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventorySlotWidgetBase, Quantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quantity_MetaData), NewProp_Quantity_MetaData) };
void Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_bSelected_SetBit(void* Obj)
{
	((UInventorySlotWidgetBase*)Obj)->bSelected = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_bSelected = { "bSelected", nullptr, (EPropertyFlags)0x0020080000002014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UInventorySlotWidgetBase), &Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_bSelected_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSelected_MetaData), NewProp_bSelected_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventorySlotWidgetBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_Button_Select,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_Overlay_Slot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_Border_Background,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_SlotBackgroundTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_SizeBox_Slot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_SlotDisplaySize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_Image_ItemIcon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_SizeBox_Icon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_ScaleBox_Icon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_IconDisplaySize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_Text_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_QuantityPadding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_Image_Selection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_Border_Unavailable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_OwnerInventoryWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_ItemDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySlotWidgetBase_Statics::NewProp_bSelected,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidgetBase_Statics::PropPointers) < 2048);
// ********** End Class UInventorySlotWidgetBase Property Definitions ******************************
UObject* (*const Z_Construct_UClass_UInventorySlotWidgetBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_InventorySystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidgetBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventorySlotWidgetBase_Statics::ClassParams = {
	&UInventorySlotWidgetBase::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UInventorySlotWidgetBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidgetBase_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySlotWidgetBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UInventorySlotWidgetBase_Statics::Class_MetaDataParams)
};
void UInventorySlotWidgetBase::StaticRegisterNativesUInventorySlotWidgetBase()
{
	UClass* Class = UInventorySlotWidgetBase::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UInventorySlotWidgetBase_Statics::Funcs));
}
UClass* Z_Construct_UClass_UInventorySlotWidgetBase()
{
	if (!Z_Registration_Info_UClass_UInventorySlotWidgetBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventorySlotWidgetBase.OuterSingleton, Z_Construct_UClass_UInventorySlotWidgetBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInventorySlotWidgetBase.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UInventorySlotWidgetBase);
UInventorySlotWidgetBase::~UInventorySlotWidgetBase() {}
// ********** End Class UInventorySlotWidgetBase ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventorySlotWidgetBase_h__Script_InventorySystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInventorySlotWidgetBase, UInventorySlotWidgetBase::StaticClass, TEXT("UInventorySlotWidgetBase"), &Z_Registration_Info_UClass_UInventorySlotWidgetBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventorySlotWidgetBase), 777282390U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventorySlotWidgetBase_h__Script_InventorySystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventorySlotWidgetBase_h__Script_InventorySystem_2591171191{
	TEXT("/Script/InventorySystem"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventorySlotWidgetBase_h__Script_InventorySystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventorySlotWidgetBase_h__Script_InventorySystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
