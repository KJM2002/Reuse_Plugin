// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/InventoryWidgetBase.h"
#include "InventoryTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeInventoryWidgetBase() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryComponent_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventorySlotWidgetBase_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryUIComponent_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryWidgetBase();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryWidgetBase_NoRegister();
INVENTORYSYSTEM_API UEnum* Z_Construct_UEnum_InventorySystem_EInventoryOperationResult();
INVENTORYSYSTEM_API UFunction* Z_Construct_UDelegateFunction_InventorySystem_InventoryWidgetCloseRequestedSignature__DelegateSignature();
INVENTORYSYSTEM_API UFunction* Z_Construct_UDelegateFunction_InventorySystem_InventoryWidgetTransitionFinishedSignature__DelegateSignature();
INVENTORYSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FInventorySlot();
UMG_API UClass* Z_Construct_UClass_UBorder_NoRegister();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UHorizontalBox_NoRegister();
UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
UMG_API UClass* Z_Construct_UClass_UOverlay_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUniformGridPanel_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_InventorySystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FInventoryWidgetCloseRequestedSignature *******************************
struct Z_Construct_UDelegateFunction_InventorySystem_InventoryWidgetCloseRequestedSignature__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FInventoryWidgetCloseRequestedSignature constinit property declarations 
// ********** End Delegate FInventoryWidgetCloseRequestedSignature constinit property declarations *
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_InventorySystem_InventoryWidgetCloseRequestedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_InventorySystem, nullptr, "InventoryWidgetCloseRequestedSignature__DelegateSignature", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_InventoryWidgetCloseRequestedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_InventorySystem_InventoryWidgetCloseRequestedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_InventorySystem_InventoryWidgetCloseRequestedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_InventorySystem_InventoryWidgetCloseRequestedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FInventoryWidgetCloseRequestedSignature_DelegateWrapper(const FMulticastScriptDelegate& InventoryWidgetCloseRequestedSignature)
{
	InventoryWidgetCloseRequestedSignature.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FInventoryWidgetCloseRequestedSignature *********************************

// ********** Begin Delegate FInventoryWidgetTransitionFinishedSignature ***************************
struct Z_Construct_UDelegateFunction_InventorySystem_InventoryWidgetTransitionFinishedSignature__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FInventoryWidgetTransitionFinishedSignature constinit property declarations 
// ********** End Delegate FInventoryWidgetTransitionFinishedSignature constinit property declarations 
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_InventorySystem_InventoryWidgetTransitionFinishedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_InventorySystem, nullptr, "InventoryWidgetTransitionFinishedSignature__DelegateSignature", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_InventoryWidgetTransitionFinishedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_InventorySystem_InventoryWidgetTransitionFinishedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_InventorySystem_InventoryWidgetTransitionFinishedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_InventorySystem_InventoryWidgetTransitionFinishedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FInventoryWidgetTransitionFinishedSignature_DelegateWrapper(const FMulticastScriptDelegate& InventoryWidgetTransitionFinishedSignature)
{
	InventoryWidgetTransitionFinishedSignature.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FInventoryWidgetTransitionFinishedSignature *****************************

// ********** Begin Class UInventoryWidgetBase Function BeginCloseTransition ***********************
struct Z_Construct_UFunction_UInventoryWidgetBase_BeginCloseTransition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BeginCloseTransition constinit property declarations ******************
// ********** End Function BeginCloseTransition constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_BeginCloseTransition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "BeginCloseTransition", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_BeginCloseTransition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_BeginCloseTransition_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_BeginCloseTransition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_BeginCloseTransition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryWidgetBase::execBeginCloseTransition)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->BeginCloseTransition();
	P_NATIVE_END;
}
// ********** End Class UInventoryWidgetBase Function BeginCloseTransition *************************

// ********** Begin Class UInventoryWidgetBase Function BeginInspectorReturnTransition *************
struct Z_Construct_UFunction_UInventoryWidgetBase_BeginInspectorReturnTransition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BeginInspectorReturnTransition constinit property declarations ********
// ********** End Function BeginInspectorReturnTransition constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_BeginInspectorReturnTransition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "BeginInspectorReturnTransition", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_BeginInspectorReturnTransition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_BeginInspectorReturnTransition_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_BeginInspectorReturnTransition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_BeginInspectorReturnTransition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryWidgetBase::execBeginInspectorReturnTransition)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->BeginInspectorReturnTransition();
	P_NATIVE_END;
}
// ********** End Class UInventoryWidgetBase Function BeginInspectorReturnTransition ***************

// ********** Begin Class UInventoryWidgetBase Function BeginInspectTransition *********************
struct Z_Construct_UFunction_UInventoryWidgetBase_BeginInspectTransition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BeginInspectTransition constinit property declarations ****************
// ********** End Function BeginInspectTransition constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_BeginInspectTransition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "BeginInspectTransition", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_BeginInspectTransition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_BeginInspectTransition_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_BeginInspectTransition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_BeginInspectTransition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryWidgetBase::execBeginInspectTransition)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->BeginInspectTransition();
	P_NATIVE_END;
}
// ********** End Class UInventoryWidgetBase Function BeginInspectTransition ***********************

// ********** Begin Class UInventoryWidgetBase Function BeginOpenTransition ************************
struct Z_Construct_UFunction_UInventoryWidgetBase_BeginOpenTransition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BeginOpenTransition constinit property declarations *******************
// ********** End Function BeginOpenTransition constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_BeginOpenTransition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "BeginOpenTransition", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_BeginOpenTransition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_BeginOpenTransition_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_BeginOpenTransition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_BeginOpenTransition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryWidgetBase::execBeginOpenTransition)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->BeginOpenTransition();
	P_NATIVE_END;
}
// ********** End Class UInventoryWidgetBase Function BeginOpenTransition **************************

// ********** Begin Class UInventoryWidgetBase Function DropSelectedItem ***************************
struct Z_Construct_UFunction_UInventoryWidgetBase_DropSelectedItem_Statics
{
	struct InventoryWidgetBase_eventDropSelectedItem_Parms
	{
		int32 Quantity;
		EInventoryOperationResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "CPP_Default_Quantity", "1" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function DropSelectedItem constinit property declarations **********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DropSelectedItem constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DropSelectedItem Property Definitions *********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryWidgetBase_DropSelectedItem_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryWidgetBase_eventDropSelectedItem_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UInventoryWidgetBase_DropSelectedItem_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UInventoryWidgetBase_DropSelectedItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryWidgetBase_eventDropSelectedItem_Parms, ReturnValue), Z_Construct_UEnum_InventorySystem_EInventoryOperationResult, METADATA_PARAMS(0, nullptr) }; // 935842388
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryWidgetBase_DropSelectedItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryWidgetBase_DropSelectedItem_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryWidgetBase_DropSelectedItem_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryWidgetBase_DropSelectedItem_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_DropSelectedItem_Statics::PropPointers) < 2048);
// ********** End Function DropSelectedItem Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_DropSelectedItem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "DropSelectedItem", 	Z_Construct_UFunction_UInventoryWidgetBase_DropSelectedItem_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_DropSelectedItem_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryWidgetBase_DropSelectedItem_Statics::InventoryWidgetBase_eventDropSelectedItem_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_DropSelectedItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_DropSelectedItem_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryWidgetBase_DropSelectedItem_Statics::InventoryWidgetBase_eventDropSelectedItem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_DropSelectedItem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_DropSelectedItem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryWidgetBase::execDropSelectedItem)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Quantity);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EInventoryOperationResult*)Z_Param__Result=P_THIS->DropSelectedItem(Z_Param_Quantity);
	P_NATIVE_END;
}
// ********** End Class UInventoryWidgetBase Function DropSelectedItem *****************************

// ********** Begin Class UInventoryWidgetBase Function FocusSelectedSlot **************************
struct Z_Construct_UFunction_UInventoryWidgetBase_FocusSelectedSlot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function FocusSelectedSlot constinit property declarations *********************
// ********** End Function FocusSelectedSlot constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_FocusSelectedSlot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "FocusSelectedSlot", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_FocusSelectedSlot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_FocusSelectedSlot_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_FocusSelectedSlot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_FocusSelectedSlot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryWidgetBase::execFocusSelectedSlot)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FocusSelectedSlot();
	P_NATIVE_END;
}
// ********** End Class UInventoryWidgetBase Function FocusSelectedSlot ****************************

// ********** Begin Class UInventoryWidgetBase Function GetInventoryComponent **********************
struct Z_Construct_UFunction_UInventoryWidgetBase_GetInventoryComponent_Statics
{
	struct InventoryWidgetBase_eventGetInventoryComponent_Parms
	{
		UInventoryComponent* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetInventoryComponent constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetInventoryComponent constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetInventoryComponent Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryWidgetBase_GetInventoryComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryWidgetBase_eventGetInventoryComponent_Parms, ReturnValue), Z_Construct_UClass_UInventoryComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryWidgetBase_GetInventoryComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryWidgetBase_GetInventoryComponent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_GetInventoryComponent_Statics::PropPointers) < 2048);
// ********** End Function GetInventoryComponent Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_GetInventoryComponent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "GetInventoryComponent", 	Z_Construct_UFunction_UInventoryWidgetBase_GetInventoryComponent_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_GetInventoryComponent_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryWidgetBase_GetInventoryComponent_Statics::InventoryWidgetBase_eventGetInventoryComponent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_GetInventoryComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_GetInventoryComponent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryWidgetBase_GetInventoryComponent_Statics::InventoryWidgetBase_eventGetInventoryComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_GetInventoryComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_GetInventoryComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryWidgetBase::execGetInventoryComponent)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UInventoryComponent**)Z_Param__Result=P_THIS->GetInventoryComponent();
	P_NATIVE_END;
}
// ********** End Class UInventoryWidgetBase Function GetInventoryComponent ************************

// ********** Begin Class UInventoryWidgetBase Function GetSelectedSlot ****************************
struct Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlot_Statics
{
	struct InventoryWidgetBase_eventGetSelectedSlot_Parms
	{
		FInventorySlot OutSlot;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSelectedSlot constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutSlot;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSelectedSlot constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSelectedSlot Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlot_Statics::NewProp_OutSlot = { "OutSlot", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryWidgetBase_eventGetSelectedSlot_Parms, OutSlot), Z_Construct_UScriptStruct_FInventorySlot, METADATA_PARAMS(0, nullptr) }; // 3353780059
void Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlot_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventoryWidgetBase_eventGetSelectedSlot_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventoryWidgetBase_eventGetSelectedSlot_Parms), &Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlot_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlot_Statics::NewProp_OutSlot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlot_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlot_Statics::PropPointers) < 2048);
// ********** End Function GetSelectedSlot Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "GetSelectedSlot", 	Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlot_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlot_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlot_Statics::InventoryWidgetBase_eventGetSelectedSlot_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlot_Statics::InventoryWidgetBase_eventGetSelectedSlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryWidgetBase::execGetSelectedSlot)
{
	P_GET_STRUCT_REF(FInventorySlot,Z_Param_Out_OutSlot);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetSelectedSlot(Z_Param_Out_OutSlot);
	P_NATIVE_END;
}
// ********** End Class UInventoryWidgetBase Function GetSelectedSlot ******************************

// ********** Begin Class UInventoryWidgetBase Function GetSelectedSlotIndex ***********************
struct Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlotIndex_Statics
{
	struct InventoryWidgetBase_eventGetSelectedSlotIndex_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSelectedSlotIndex constinit property declarations ******************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSelectedSlotIndex constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSelectedSlotIndex Property Definitions *****************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlotIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryWidgetBase_eventGetSelectedSlotIndex_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlotIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlotIndex_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlotIndex_Statics::PropPointers) < 2048);
// ********** End Function GetSelectedSlotIndex Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlotIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "GetSelectedSlotIndex", 	Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlotIndex_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlotIndex_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlotIndex_Statics::InventoryWidgetBase_eventGetSelectedSlotIndex_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlotIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlotIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlotIndex_Statics::InventoryWidgetBase_eventGetSelectedSlotIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlotIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlotIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryWidgetBase::execGetSelectedSlotIndex)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetSelectedSlotIndex();
	P_NATIVE_END;
}
// ********** End Class UInventoryWidgetBase Function GetSelectedSlotIndex *************************

// ********** Begin Class UInventoryWidgetBase Function HandleCloseClicked *************************
struct Z_Construct_UFunction_UInventoryWidgetBase_HandleCloseClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleCloseClicked constinit property declarations ********************
// ********** End Function HandleCloseClicked constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_HandleCloseClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "HandleCloseClicked", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_HandleCloseClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_HandleCloseClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_HandleCloseClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_HandleCloseClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryWidgetBase::execHandleCloseClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCloseClicked();
	P_NATIVE_END;
}
// ********** End Class UInventoryWidgetBase Function HandleCloseClicked ***************************

// ********** Begin Class UInventoryWidgetBase Function HandleDropClicked **************************
struct Z_Construct_UFunction_UInventoryWidgetBase_HandleDropClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleDropClicked constinit property declarations *********************
// ********** End Function HandleDropClicked constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_HandleDropClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "HandleDropClicked", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_HandleDropClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_HandleDropClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_HandleDropClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_HandleDropClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryWidgetBase::execHandleDropClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleDropClicked();
	P_NATIVE_END;
}
// ********** End Class UInventoryWidgetBase Function HandleDropClicked ****************************

// ********** Begin Class UInventoryWidgetBase Function HandleInspectClicked ***********************
struct Z_Construct_UFunction_UInventoryWidgetBase_HandleInspectClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleInspectClicked constinit property declarations ******************
// ********** End Function HandleInspectClicked constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_HandleInspectClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "HandleInspectClicked", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_HandleInspectClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_HandleInspectClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_HandleInspectClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_HandleInspectClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryWidgetBase::execHandleInspectClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleInspectClicked();
	P_NATIVE_END;
}
// ********** End Class UInventoryWidgetBase Function HandleInspectClicked *************************

// ********** Begin Class UInventoryWidgetBase Function HandleInventoryChanged *********************
struct Z_Construct_UFunction_UInventoryWidgetBase_HandleInventoryChanged_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleInventoryChanged constinit property declarations ****************
// ********** End Function HandleInventoryChanged constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_HandleInventoryChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "HandleInventoryChanged", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_HandleInventoryChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_HandleInventoryChanged_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_HandleInventoryChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_HandleInventoryChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryWidgetBase::execHandleInventoryChanged)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleInventoryChanged();
	P_NATIVE_END;
}
// ********** End Class UInventoryWidgetBase Function HandleInventoryChanged ***********************

// ********** Begin Class UInventoryWidgetBase Function HandleUseClicked ***************************
struct Z_Construct_UFunction_UInventoryWidgetBase_HandleUseClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleUseClicked constinit property declarations **********************
// ********** End Function HandleUseClicked constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_HandleUseClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "HandleUseClicked", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_HandleUseClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_HandleUseClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_HandleUseClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_HandleUseClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryWidgetBase::execHandleUseClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleUseClicked();
	P_NATIVE_END;
}
// ********** End Class UInventoryWidgetBase Function HandleUseClicked *****************************

// ********** Begin Class UInventoryWidgetBase Function InitializeInventory ************************
struct Z_Construct_UFunction_UInventoryWidgetBase_InitializeInventory_Statics
{
	struct InventoryWidgetBase_eventInitializeInventory_Parms
	{
		UInventoryComponent* InInventory;
		UInventoryUIComponent* InCoordinator;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InInventory_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InCoordinator_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function InitializeInventory constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InInventory;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InCoordinator;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InitializeInventory constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InitializeInventory Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryWidgetBase_InitializeInventory_Statics::NewProp_InInventory = { "InInventory", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryWidgetBase_eventInitializeInventory_Parms, InInventory), Z_Construct_UClass_UInventoryComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InInventory_MetaData), NewProp_InInventory_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryWidgetBase_InitializeInventory_Statics::NewProp_InCoordinator = { "InCoordinator", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryWidgetBase_eventInitializeInventory_Parms, InCoordinator), Z_Construct_UClass_UInventoryUIComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InCoordinator_MetaData), NewProp_InCoordinator_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryWidgetBase_InitializeInventory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryWidgetBase_InitializeInventory_Statics::NewProp_InInventory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryWidgetBase_InitializeInventory_Statics::NewProp_InCoordinator,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_InitializeInventory_Statics::PropPointers) < 2048);
// ********** End Function InitializeInventory Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_InitializeInventory_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "InitializeInventory", 	Z_Construct_UFunction_UInventoryWidgetBase_InitializeInventory_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_InitializeInventory_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryWidgetBase_InitializeInventory_Statics::InventoryWidgetBase_eventInitializeInventory_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_InitializeInventory_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_InitializeInventory_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryWidgetBase_InitializeInventory_Statics::InventoryWidgetBase_eventInitializeInventory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_InitializeInventory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_InitializeInventory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryWidgetBase::execInitializeInventory)
{
	P_GET_OBJECT(UInventoryComponent,Z_Param_InInventory);
	P_GET_OBJECT(UInventoryUIComponent,Z_Param_InCoordinator);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeInventory(Z_Param_InInventory,Z_Param_InCoordinator);
	P_NATIVE_END;
}
// ********** End Class UInventoryWidgetBase Function InitializeInventory **************************

// ********** Begin Class UInventoryWidgetBase Function InspectSelectedItem ************************
struct Z_Construct_UFunction_UInventoryWidgetBase_InspectSelectedItem_Statics
{
	struct InventoryWidgetBase_eventInspectSelectedItem_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function InspectSelectedItem constinit property declarations *******************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InspectSelectedItem constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InspectSelectedItem Property Definitions ******************************
void Z_Construct_UFunction_UInventoryWidgetBase_InspectSelectedItem_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventoryWidgetBase_eventInspectSelectedItem_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryWidgetBase_InspectSelectedItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventoryWidgetBase_eventInspectSelectedItem_Parms), &Z_Construct_UFunction_UInventoryWidgetBase_InspectSelectedItem_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryWidgetBase_InspectSelectedItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryWidgetBase_InspectSelectedItem_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_InspectSelectedItem_Statics::PropPointers) < 2048);
// ********** End Function InspectSelectedItem Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_InspectSelectedItem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "InspectSelectedItem", 	Z_Construct_UFunction_UInventoryWidgetBase_InspectSelectedItem_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_InspectSelectedItem_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryWidgetBase_InspectSelectedItem_Statics::InventoryWidgetBase_eventInspectSelectedItem_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_InspectSelectedItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_InspectSelectedItem_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryWidgetBase_InspectSelectedItem_Statics::InventoryWidgetBase_eventInspectSelectedItem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_InspectSelectedItem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_InspectSelectedItem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryWidgetBase::execInspectSelectedItem)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->InspectSelectedItem();
	P_NATIVE_END;
}
// ********** End Class UInventoryWidgetBase Function InspectSelectedItem **************************

// ********** Begin Class UInventoryWidgetBase Function IsClosing **********************************
struct Z_Construct_UFunction_UInventoryWidgetBase_IsClosing_Statics
{
	struct InventoryWidgetBase_eventIsClosing_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsClosing constinit property declarations *****************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsClosing constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsClosing Property Definitions ****************************************
void Z_Construct_UFunction_UInventoryWidgetBase_IsClosing_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventoryWidgetBase_eventIsClosing_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryWidgetBase_IsClosing_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventoryWidgetBase_eventIsClosing_Parms), &Z_Construct_UFunction_UInventoryWidgetBase_IsClosing_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryWidgetBase_IsClosing_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryWidgetBase_IsClosing_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_IsClosing_Statics::PropPointers) < 2048);
// ********** End Function IsClosing Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_IsClosing_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "IsClosing", 	Z_Construct_UFunction_UInventoryWidgetBase_IsClosing_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_IsClosing_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryWidgetBase_IsClosing_Statics::InventoryWidgetBase_eventIsClosing_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_IsClosing_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_IsClosing_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryWidgetBase_IsClosing_Statics::InventoryWidgetBase_eventIsClosing_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_IsClosing()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_IsClosing_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryWidgetBase::execIsClosing)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsClosing();
	P_NATIVE_END;
}
// ********** End Class UInventoryWidgetBase Function IsClosing ************************************

// ********** Begin Class UInventoryWidgetBase Function OnInventoryOperationFailed *****************
struct InventoryWidgetBase_eventOnInventoryOperationFailed_Parms
{
	EInventoryOperationResult Result;
};
static FName NAME_UInventoryWidgetBase_OnInventoryOperationFailed = FName(TEXT("OnInventoryOperationFailed"));
void UInventoryWidgetBase::OnInventoryOperationFailed(EInventoryOperationResult Result)
{
	InventoryWidgetBase_eventOnInventoryOperationFailed_Parms Parms;
	Parms.Result=Result;
	UFunction* Func = FindFunctionChecked(NAME_UInventoryWidgetBase_OnInventoryOperationFailed);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryOperationFailed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnInventoryOperationFailed constinit property declarations ************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Result;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnInventoryOperationFailed constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnInventoryOperationFailed Property Definitions ***********************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryOperationFailed_Statics::NewProp_Result_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryOperationFailed_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryWidgetBase_eventOnInventoryOperationFailed_Parms, Result), Z_Construct_UEnum_InventorySystem_EInventoryOperationResult, METADATA_PARAMS(0, nullptr) }; // 935842388
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryOperationFailed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryOperationFailed_Statics::NewProp_Result_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryOperationFailed_Statics::NewProp_Result,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryOperationFailed_Statics::PropPointers) < 2048);
// ********** End Function OnInventoryOperationFailed Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryOperationFailed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "OnInventoryOperationFailed", 	Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryOperationFailed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryOperationFailed_Statics::PropPointers), 
sizeof(InventoryWidgetBase_eventOnInventoryOperationFailed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryOperationFailed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryOperationFailed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InventoryWidgetBase_eventOnInventoryOperationFailed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryOperationFailed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryOperationFailed_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UInventoryWidgetBase Function OnInventoryOperationFailed *******************

// ********** Begin Class UInventoryWidgetBase Function OnInventoryRefreshed ***********************
struct InventoryWidgetBase_eventOnInventoryRefreshed_Parms
{
	TArray<FInventorySlot> CurrentSlots;
};
static FName NAME_UInventoryWidgetBase_OnInventoryRefreshed = FName(TEXT("OnInventoryRefreshed"));
void UInventoryWidgetBase::OnInventoryRefreshed(TArray<FInventorySlot> const& CurrentSlots)
{
	InventoryWidgetBase_eventOnInventoryRefreshed_Parms Parms;
	Parms.CurrentSlots=CurrentSlots;
	UFunction* Func = FindFunctionChecked(NAME_UInventoryWidgetBase_OnInventoryRefreshed);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryRefreshed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** C++ \xea\xb8\xb0\xeb\xb3\xb8 \xea\xb0\xb1\xec\x8b\xa0 \xec\x9d\xb4\xed\x9b\x84 \xea\xb2\x8c\xec\x9e\x84\xeb\xb3\x84 \xec\x97\xb0\xec\xb6\x9c\xec\x9d\xb4 \xeb\x8d\x94 \xed\x95\x84\xec\x9a\x94\xed\x95\xa0 \xeb\x95\x8c\xeb\xa7\x8c \xea\xb5\xac\xed\x98\x84\xed\x95\x9c\xeb\x8b\xa4. */" },
#endif
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "C++ \xea\xb8\xb0\xeb\xb3\xb8 \xea\xb0\xb1\xec\x8b\xa0 \xec\x9d\xb4\xed\x9b\x84 \xea\xb2\x8c\xec\x9e\x84\xeb\xb3\x84 \xec\x97\xb0\xec\xb6\x9c\xec\x9d\xb4 \xeb\x8d\x94 \xed\x95\x84\xec\x9a\x94\xed\x95\xa0 \xeb\x95\x8c\xeb\xa7\x8c \xea\xb5\xac\xed\x98\x84\xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentSlots_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnInventoryRefreshed constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentSlots_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CurrentSlots;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnInventoryRefreshed constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnInventoryRefreshed Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryRefreshed_Statics::NewProp_CurrentSlots_Inner = { "CurrentSlots", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FInventorySlot, METADATA_PARAMS(0, nullptr) }; // 3353780059
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryRefreshed_Statics::NewProp_CurrentSlots = { "CurrentSlots", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryWidgetBase_eventOnInventoryRefreshed_Parms, CurrentSlots), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentSlots_MetaData), NewProp_CurrentSlots_MetaData) }; // 3353780059
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryRefreshed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryRefreshed_Statics::NewProp_CurrentSlots_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryRefreshed_Statics::NewProp_CurrentSlots,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryRefreshed_Statics::PropPointers) < 2048);
// ********** End Function OnInventoryRefreshed Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryRefreshed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "OnInventoryRefreshed", 	Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryRefreshed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryRefreshed_Statics::PropPointers), 
sizeof(InventoryWidgetBase_eventOnInventoryRefreshed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryRefreshed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryRefreshed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InventoryWidgetBase_eventOnInventoryRefreshed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryRefreshed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryRefreshed_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UInventoryWidgetBase Function OnInventoryRefreshed *************************

// ********** Begin Class UInventoryWidgetBase Function OnSelectionChanged *************************
struct InventoryWidgetBase_eventOnSelectionChanged_Parms
{
	int32 NewSlotIndex;
	FInventorySlot SelectedSlot;
};
static FName NAME_UInventoryWidgetBase_OnSelectionChanged = FName(TEXT("OnSelectionChanged"));
void UInventoryWidgetBase::OnSelectionChanged(int32 NewSlotIndex, FInventorySlot const& SelectedSlot)
{
	InventoryWidgetBase_eventOnSelectionChanged_Parms Parms;
	Parms.NewSlotIndex=NewSlotIndex;
	Parms.SelectedSlot=SelectedSlot;
	UFunction* Func = FindFunctionChecked(NAME_UInventoryWidgetBase_OnSelectionChanged);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UInventoryWidgetBase_OnSelectionChanged_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** C++ \xea\xb8\xb0\xeb\xb3\xb8 \xec\x83\x81\xec\x84\xb8 \xec\xa0\x95\xeb\xb3\xb4 \xea\xb0\xb1\xec\x8b\xa0 \xec\x9d\xb4\xed\x9b\x84 \xea\xb2\x8c\xec\x9e\x84\xeb\xb3\x84 \xec\x97\xb0\xec\xb6\x9c\xec\x9d\xb4 \xeb\x8d\x94 \xed\x95\x84\xec\x9a\x94\xed\x95\xa0 \xeb\x95\x8c\xeb\xa7\x8c \xea\xb5\xac\xed\x98\x84\xed\x95\x9c\xeb\x8b\xa4. */" },
#endif
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "C++ \xea\xb8\xb0\xeb\xb3\xb8 \xec\x83\x81\xec\x84\xb8 \xec\xa0\x95\xeb\xb3\xb4 \xea\xb0\xb1\xec\x8b\xa0 \xec\x9d\xb4\xed\x9b\x84 \xea\xb2\x8c\xec\x9e\x84\xeb\xb3\x84 \xec\x97\xb0\xec\xb6\x9c\xec\x9d\xb4 \xeb\x8d\x94 \xed\x95\x84\xec\x9a\x94\xed\x95\xa0 \xeb\x95\x8c\xeb\xa7\x8c \xea\xb5\xac\xed\x98\x84\xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedSlot_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnSelectionChanged constinit property declarations ********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_NewSlotIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SelectedSlot;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnSelectionChanged constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnSelectionChanged Property Definitions *******************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryWidgetBase_OnSelectionChanged_Statics::NewProp_NewSlotIndex = { "NewSlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryWidgetBase_eventOnSelectionChanged_Parms, NewSlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryWidgetBase_OnSelectionChanged_Statics::NewProp_SelectedSlot = { "SelectedSlot", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryWidgetBase_eventOnSelectionChanged_Parms, SelectedSlot), Z_Construct_UScriptStruct_FInventorySlot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedSlot_MetaData), NewProp_SelectedSlot_MetaData) }; // 3353780059
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryWidgetBase_OnSelectionChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryWidgetBase_OnSelectionChanged_Statics::NewProp_NewSlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryWidgetBase_OnSelectionChanged_Statics::NewProp_SelectedSlot,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_OnSelectionChanged_Statics::PropPointers) < 2048);
// ********** End Function OnSelectionChanged Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_OnSelectionChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "OnSelectionChanged", 	Z_Construct_UFunction_UInventoryWidgetBase_OnSelectionChanged_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_OnSelectionChanged_Statics::PropPointers), 
sizeof(InventoryWidgetBase_eventOnSelectionChanged_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_OnSelectionChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_OnSelectionChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InventoryWidgetBase_eventOnSelectionChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_OnSelectionChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_OnSelectionChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UInventoryWidgetBase Function OnSelectionChanged ***************************

// ********** Begin Class UInventoryWidgetBase Function RefreshInventory ***************************
struct Z_Construct_UFunction_UInventoryWidgetBase_RefreshInventory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshInventory constinit property declarations **********************
// ********** End Function RefreshInventory constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_RefreshInventory_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "RefreshInventory", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_RefreshInventory_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_RefreshInventory_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_RefreshInventory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_RefreshInventory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryWidgetBase::execRefreshInventory)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshInventory();
	P_NATIVE_END;
}
// ********** End Class UInventoryWidgetBase Function RefreshInventory *****************************

// ********** Begin Class UInventoryWidgetBase Function RequestClose *******************************
struct Z_Construct_UFunction_UInventoryWidgetBase_RequestClose_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestClose constinit property declarations **************************
// ********** End Function RequestClose constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_RequestClose_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "RequestClose", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_RequestClose_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_RequestClose_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_RequestClose()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_RequestClose_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryWidgetBase::execRequestClose)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestClose();
	P_NATIVE_END;
}
// ********** End Class UInventoryWidgetBase Function RequestClose *********************************

// ********** Begin Class UInventoryWidgetBase Function SelectSlot *********************************
struct Z_Construct_UFunction_UInventoryWidgetBase_SelectSlot_Statics
{
	struct InventoryWidgetBase_eventSelectSlot_Parms
	{
		int32 SlotIndex;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SelectSlot constinit property declarations ****************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SelectSlot constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SelectSlot Property Definitions ***************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryWidgetBase_SelectSlot_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryWidgetBase_eventSelectSlot_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UInventoryWidgetBase_SelectSlot_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventoryWidgetBase_eventSelectSlot_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryWidgetBase_SelectSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventoryWidgetBase_eventSelectSlot_Parms), &Z_Construct_UFunction_UInventoryWidgetBase_SelectSlot_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryWidgetBase_SelectSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryWidgetBase_SelectSlot_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryWidgetBase_SelectSlot_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_SelectSlot_Statics::PropPointers) < 2048);
// ********** End Function SelectSlot Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_SelectSlot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "SelectSlot", 	Z_Construct_UFunction_UInventoryWidgetBase_SelectSlot_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_SelectSlot_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryWidgetBase_SelectSlot_Statics::InventoryWidgetBase_eventSelectSlot_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_SelectSlot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_SelectSlot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryWidgetBase_SelectSlot_Statics::InventoryWidgetBase_eventSelectSlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_SelectSlot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_SelectSlot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryWidgetBase::execSelectSlot)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SelectSlot(Z_Param_SlotIndex);
	P_NATIVE_END;
}
// ********** End Class UInventoryWidgetBase Function SelectSlot ***********************************

// ********** Begin Class UInventoryWidgetBase Function UseSelectedItem ****************************
struct Z_Construct_UFunction_UInventoryWidgetBase_UseSelectedItem_Statics
{
	struct InventoryWidgetBase_eventUseSelectedItem_Parms
	{
		EInventoryOperationResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function UseSelectedItem constinit property declarations ***********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UseSelectedItem constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UseSelectedItem Property Definitions **********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UInventoryWidgetBase_UseSelectedItem_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UInventoryWidgetBase_UseSelectedItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryWidgetBase_eventUseSelectedItem_Parms, ReturnValue), Z_Construct_UEnum_InventorySystem_EInventoryOperationResult, METADATA_PARAMS(0, nullptr) }; // 935842388
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryWidgetBase_UseSelectedItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryWidgetBase_UseSelectedItem_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryWidgetBase_UseSelectedItem_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_UseSelectedItem_Statics::PropPointers) < 2048);
// ********** End Function UseSelectedItem Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryWidgetBase_UseSelectedItem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryWidgetBase, nullptr, "UseSelectedItem", 	Z_Construct_UFunction_UInventoryWidgetBase_UseSelectedItem_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_UseSelectedItem_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryWidgetBase_UseSelectedItem_Statics::InventoryWidgetBase_eventUseSelectedItem_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryWidgetBase_UseSelectedItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryWidgetBase_UseSelectedItem_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryWidgetBase_UseSelectedItem_Statics::InventoryWidgetBase_eventUseSelectedItem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryWidgetBase_UseSelectedItem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryWidgetBase_UseSelectedItem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryWidgetBase::execUseSelectedItem)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EInventoryOperationResult*)Z_Param__Result=P_THIS->UseSelectedItem();
	P_NATIVE_END;
}
// ********** End Class UInventoryWidgetBase Function UseSelectedItem ******************************

// ********** Begin Class UInventoryWidgetBase *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UInventoryWidgetBase;
UClass* UInventoryWidgetBase::GetPrivateStaticClass()
{
	using TClass = UInventoryWidgetBase;
	if (!Z_Registration_Info_UClass_UInventoryWidgetBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("InventoryWidgetBase"),
			Z_Registration_Info_UClass_UInventoryWidgetBase.InnerSingleton,
			StaticRegisterNativesUInventoryWidgetBase,
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
	return Z_Registration_Info_UClass_UInventoryWidgetBase.InnerSingleton;
}
UClass* Z_Construct_UClass_UInventoryWidgetBase_NoRegister()
{
	return UInventoryWidgetBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UInventoryWidgetBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \xec\xa0\x84\xec\xb2\xb4 \xec\x9d\xb8\xeb\xb2\xa4\xed\x86\xa0\xeb\xa6\xac UI\xec\x9d\x98 \xea\xb3\xb5\xed\x86\xb5 \xeb\x8f\x99\xec\x9e\x91\xec\x9d\x84 \xeb\x8b\xb4\xeb\x8b\xb9\xed\x95\x9c\xeb\x8b\xa4.\n * \xed\x8c\x8c\xec\x83\x9d Widget Blueprint\xeb\x8a\x94 BindWidget \xec\x9d\xb4\xeb\xa6\x84\xec\x97\x90 \xeb\xa7\x9e\xec\xb6\xb0 UI\xeb\xa5\xbc \xeb\xb0\xb0\xec\xb9\x98\xed\x95\x98\xea\xb3\xa0 \xeb\x94\x94\xec\x9e\x90\xec\x9d\xb8\xeb\xa7\x8c \xed\x95\x9c\xeb\x8b\xa4.\n */" },
#endif
		{ "IncludePath", "UI/InventoryWidgetBase.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa0\x84\xec\xb2\xb4 \xec\x9d\xb8\xeb\xb2\xa4\xed\x86\xa0\xeb\xa6\xac UI\xec\x9d\x98 \xea\xb3\xb5\xed\x86\xb5 \xeb\x8f\x99\xec\x9e\x91\xec\x9d\x84 \xeb\x8b\xb4\xeb\x8b\xb9\xed\x95\x9c\xeb\x8b\xa4.\n\xed\x8c\x8c\xec\x83\x9d Widget Blueprint\xeb\x8a\x94 BindWidget \xec\x9d\xb4\xeb\xa6\x84\xec\x97\x90 \xeb\xa7\x9e\xec\xb6\xb0 UI\xeb\xa5\xbc \xeb\xb0\xb0\xec\xb9\x98\xed\x95\x98\xea\xb3\xa0 \xeb\x94\x94\xec\x9e\x90\xec\x9d\xb8\xeb\xa7\x8c \xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCloseRequested_MetaData[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCloseTransitionFinished_MetaData[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnInspectTransitionFinished_MetaData[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotWidgetClass_MetaData[] = {
		{ "Category", "Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** WBP_InventorySlot\xec\xb2\x98\xeb\x9f\xbc UInventorySlotWidgetBase\xec\x97\x90\xec\x84\x9c \xed\x8c\x8c\xec\x83\x9d\xeb\x90\x9c Widget Blueprint\xeb\xa5\xbc \xec\xa7\x80\xec\xa0\x95\xed\x95\x9c\xeb\x8b\xa4. */" },
#endif
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "WBP_InventorySlot\xec\xb2\x98\xeb\x9f\xbc UInventorySlotWidgetBase\xec\x97\x90\xec\x84\x9c \xed\x8c\x8c\xec\x83\x9d\xeb\x90\x9c Widget Blueprint\xeb\xa5\xbc \xec\xa7\x80\xec\xa0\x95\xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridColumnCount_MetaData[] = {
		{ "Category", "Inventory|UI" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowEmptySlots_MetaData[] = {
		{ "Category", "Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** true\xec\x9d\xb4\xeb\xa9\xb4 \xec\x9d\xb8\xeb\xb2\xa4\xed\x86\xa0\xeb\xa6\xac \xec\xb5\x9c\xeb\x8c\x80 \xec\x9a\xa9\xeb\x9f\x89\xeb\xa7\x8c\xed\x81\xbc \xeb\xb9\x88 \xec\x8a\xac\xeb\xa1\xaf\xea\xb9\x8c\xec\xa7\x80 \xed\x91\x9c\xec\x8b\x9c\xed\x95\xb4 \xea\xb3\xa0\xec\xa0\x95 Grid\xeb\xa5\xbc \xeb\xa7\x8c\xeb\x93\xa0\xeb\x8b\xa4. */" },
#endif
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "true\xec\x9d\xb4\xeb\xa9\xb4 \xec\x9d\xb8\xeb\xb2\xa4\xed\x86\xa0\xeb\xa6\xac \xec\xb5\x9c\xeb\x8c\x80 \xec\x9a\xa9\xeb\x9f\x89\xeb\xa7\x8c\xed\x81\xbc \xeb\xb9\x88 \xec\x8a\xac\xeb\xa1\xaf\xea\xb9\x8c\xec\xa7\x80 \xed\x91\x9c\xec\x8b\x9c\xed\x95\xb4 \xea\xb3\xa0\xec\xa0\x95 Grid\xeb\xa5\xbc \xeb\xa7\x8c\xeb\x93\xa0\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UniformGridPanel_Items_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xeb\xb0\x98\xeb\x93\x9c\xec\x8b\x9c WBP_Inventory\xec\x97\x90 \xea\xb0\x99\xec\x9d\x80 \xec\x9d\xb4\xeb\xa6\x84\xec\x9d\x98 Uniform Grid Panel\xec\x9d\xb4 \xec\x9e\x88\xec\x96\xb4\xec\x95\xbc \xed\x95\x9c\xeb\x8b\xa4. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb0\x98\xeb\x93\x9c\xec\x8b\x9c WBP_Inventory\xec\x97\x90 \xea\xb0\x99\xec\x9d\x80 \xec\x9d\xb4\xeb\xa6\x84\xec\x9d\x98 Uniform Grid Panel\xec\x9d\xb4 \xec\x9e\x88\xec\x96\xb4\xec\x95\xbc \xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_Capacity_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Image_SelectedIcon_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_SelectedName_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_SelectedQuantity_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_SelectedDescription_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_SelectedCategory_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_SelectedFlavor_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_EmptyHint_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HorizontalBox_Actions_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Overlay_Root_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Border_BackgroundDim_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Border_InventoryWindow_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_DisabledReason_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Button_Use_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Button_Drop_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Button_Inspect_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Button_Close_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventoryComponent_MetaData[] = {
		{ "Category", "Inventory|UI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Coordinator_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedSlotIndex_MetaData[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpenTransitionDuration_MetaData[] = {
		{ "Category", "Inventory|UI|Animation" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CloseTransitionDuration_MetaData[] = {
		{ "Category", "Inventory|UI|Animation" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/UI/InventoryWidgetBase.h" },
		{ "Units", "s" },
	};
#endif // WITH_METADATA

// ********** Begin Class UInventoryWidgetBase constinit property declarations *********************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCloseRequested;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCloseTransitionFinished;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInspectTransitionFinished;
	static const UECodeGen_Private::FClassPropertyParams NewProp_SlotWidgetClass;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridColumnCount;
	static void NewProp_bShowEmptySlots_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowEmptySlots;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UniformGridPanel_Items;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Text_Capacity;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Image_SelectedIcon;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Text_SelectedName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Text_SelectedQuantity;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Text_SelectedDescription;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Text_SelectedCategory;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Text_SelectedFlavor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Text_EmptyHint;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HorizontalBox_Actions;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Overlay_Root;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Border_BackgroundDim;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Border_InventoryWindow;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Text_DisabledReason;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Button_Use;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Button_Drop;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Button_Inspect;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Button_Close;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InventoryComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Coordinator;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SelectedSlotIndex;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OpenTransitionDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CloseTransitionDuration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UInventoryWidgetBase constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("BeginCloseTransition"), .Pointer = &UInventoryWidgetBase::execBeginCloseTransition },
		{ .NameUTF8 = UTF8TEXT("BeginInspectorReturnTransition"), .Pointer = &UInventoryWidgetBase::execBeginInspectorReturnTransition },
		{ .NameUTF8 = UTF8TEXT("BeginInspectTransition"), .Pointer = &UInventoryWidgetBase::execBeginInspectTransition },
		{ .NameUTF8 = UTF8TEXT("BeginOpenTransition"), .Pointer = &UInventoryWidgetBase::execBeginOpenTransition },
		{ .NameUTF8 = UTF8TEXT("DropSelectedItem"), .Pointer = &UInventoryWidgetBase::execDropSelectedItem },
		{ .NameUTF8 = UTF8TEXT("FocusSelectedSlot"), .Pointer = &UInventoryWidgetBase::execFocusSelectedSlot },
		{ .NameUTF8 = UTF8TEXT("GetInventoryComponent"), .Pointer = &UInventoryWidgetBase::execGetInventoryComponent },
		{ .NameUTF8 = UTF8TEXT("GetSelectedSlot"), .Pointer = &UInventoryWidgetBase::execGetSelectedSlot },
		{ .NameUTF8 = UTF8TEXT("GetSelectedSlotIndex"), .Pointer = &UInventoryWidgetBase::execGetSelectedSlotIndex },
		{ .NameUTF8 = UTF8TEXT("HandleCloseClicked"), .Pointer = &UInventoryWidgetBase::execHandleCloseClicked },
		{ .NameUTF8 = UTF8TEXT("HandleDropClicked"), .Pointer = &UInventoryWidgetBase::execHandleDropClicked },
		{ .NameUTF8 = UTF8TEXT("HandleInspectClicked"), .Pointer = &UInventoryWidgetBase::execHandleInspectClicked },
		{ .NameUTF8 = UTF8TEXT("HandleInventoryChanged"), .Pointer = &UInventoryWidgetBase::execHandleInventoryChanged },
		{ .NameUTF8 = UTF8TEXT("HandleUseClicked"), .Pointer = &UInventoryWidgetBase::execHandleUseClicked },
		{ .NameUTF8 = UTF8TEXT("InitializeInventory"), .Pointer = &UInventoryWidgetBase::execInitializeInventory },
		{ .NameUTF8 = UTF8TEXT("InspectSelectedItem"), .Pointer = &UInventoryWidgetBase::execInspectSelectedItem },
		{ .NameUTF8 = UTF8TEXT("IsClosing"), .Pointer = &UInventoryWidgetBase::execIsClosing },
		{ .NameUTF8 = UTF8TEXT("RefreshInventory"), .Pointer = &UInventoryWidgetBase::execRefreshInventory },
		{ .NameUTF8 = UTF8TEXT("RequestClose"), .Pointer = &UInventoryWidgetBase::execRequestClose },
		{ .NameUTF8 = UTF8TEXT("SelectSlot"), .Pointer = &UInventoryWidgetBase::execSelectSlot },
		{ .NameUTF8 = UTF8TEXT("UseSelectedItem"), .Pointer = &UInventoryWidgetBase::execUseSelectedItem },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventoryWidgetBase_BeginCloseTransition, "BeginCloseTransition" }, // 3133849819
		{ &Z_Construct_UFunction_UInventoryWidgetBase_BeginInspectorReturnTransition, "BeginInspectorReturnTransition" }, // 3265047481
		{ &Z_Construct_UFunction_UInventoryWidgetBase_BeginInspectTransition, "BeginInspectTransition" }, // 4207321336
		{ &Z_Construct_UFunction_UInventoryWidgetBase_BeginOpenTransition, "BeginOpenTransition" }, // 2753694562
		{ &Z_Construct_UFunction_UInventoryWidgetBase_DropSelectedItem, "DropSelectedItem" }, // 394002513
		{ &Z_Construct_UFunction_UInventoryWidgetBase_FocusSelectedSlot, "FocusSelectedSlot" }, // 3373734313
		{ &Z_Construct_UFunction_UInventoryWidgetBase_GetInventoryComponent, "GetInventoryComponent" }, // 1370126770
		{ &Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlot, "GetSelectedSlot" }, // 2761527273
		{ &Z_Construct_UFunction_UInventoryWidgetBase_GetSelectedSlotIndex, "GetSelectedSlotIndex" }, // 3178279363
		{ &Z_Construct_UFunction_UInventoryWidgetBase_HandleCloseClicked, "HandleCloseClicked" }, // 1290133826
		{ &Z_Construct_UFunction_UInventoryWidgetBase_HandleDropClicked, "HandleDropClicked" }, // 4122682456
		{ &Z_Construct_UFunction_UInventoryWidgetBase_HandleInspectClicked, "HandleInspectClicked" }, // 2332640829
		{ &Z_Construct_UFunction_UInventoryWidgetBase_HandleInventoryChanged, "HandleInventoryChanged" }, // 2896758892
		{ &Z_Construct_UFunction_UInventoryWidgetBase_HandleUseClicked, "HandleUseClicked" }, // 3858134785
		{ &Z_Construct_UFunction_UInventoryWidgetBase_InitializeInventory, "InitializeInventory" }, // 4212386796
		{ &Z_Construct_UFunction_UInventoryWidgetBase_InspectSelectedItem, "InspectSelectedItem" }, // 3072666985
		{ &Z_Construct_UFunction_UInventoryWidgetBase_IsClosing, "IsClosing" }, // 4118251128
		{ &Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryOperationFailed, "OnInventoryOperationFailed" }, // 3466613140
		{ &Z_Construct_UFunction_UInventoryWidgetBase_OnInventoryRefreshed, "OnInventoryRefreshed" }, // 3023721658
		{ &Z_Construct_UFunction_UInventoryWidgetBase_OnSelectionChanged, "OnSelectionChanged" }, // 1324999078
		{ &Z_Construct_UFunction_UInventoryWidgetBase_RefreshInventory, "RefreshInventory" }, // 1570656981
		{ &Z_Construct_UFunction_UInventoryWidgetBase_RequestClose, "RequestClose" }, // 1396162480
		{ &Z_Construct_UFunction_UInventoryWidgetBase_SelectSlot, "SelectSlot" }, // 945147989
		{ &Z_Construct_UFunction_UInventoryWidgetBase_UseSelectedItem, "UseSelectedItem" }, // 1733793826
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryWidgetBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UInventoryWidgetBase_Statics

// ********** Begin Class UInventoryWidgetBase Property Definitions ********************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_OnCloseRequested = { "OnCloseRequested", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, OnCloseRequested), Z_Construct_UDelegateFunction_InventorySystem_InventoryWidgetCloseRequestedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCloseRequested_MetaData), NewProp_OnCloseRequested_MetaData) }; // 1296413921
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_OnCloseTransitionFinished = { "OnCloseTransitionFinished", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, OnCloseTransitionFinished), Z_Construct_UDelegateFunction_InventorySystem_InventoryWidgetTransitionFinishedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCloseTransitionFinished_MetaData), NewProp_OnCloseTransitionFinished_MetaData) }; // 4154487014
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_OnInspectTransitionFinished = { "OnInspectTransitionFinished", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, OnInspectTransitionFinished), Z_Construct_UDelegateFunction_InventorySystem_InventoryWidgetTransitionFinishedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnInspectTransitionFinished_MetaData), NewProp_OnInspectTransitionFinished_MetaData) }; // 4154487014
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_SlotWidgetClass = { "SlotWidgetClass", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, SlotWidgetClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UInventorySlotWidgetBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotWidgetClass_MetaData), NewProp_SlotWidgetClass_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_GridColumnCount = { "GridColumnCount", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, GridColumnCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridColumnCount_MetaData), NewProp_GridColumnCount_MetaData) };
void Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_bShowEmptySlots_SetBit(void* Obj)
{
	((UInventoryWidgetBase*)Obj)->bShowEmptySlots = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_bShowEmptySlots = { "bShowEmptySlots", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UInventoryWidgetBase), &Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_bShowEmptySlots_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowEmptySlots_MetaData), NewProp_bShowEmptySlots_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_UniformGridPanel_Items = { "UniformGridPanel_Items", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, UniformGridPanel_Items), Z_Construct_UClass_UUniformGridPanel_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UniformGridPanel_Items_MetaData), NewProp_UniformGridPanel_Items_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Text_Capacity = { "Text_Capacity", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, Text_Capacity), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_Capacity_MetaData), NewProp_Text_Capacity_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Image_SelectedIcon = { "Image_SelectedIcon", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, Image_SelectedIcon), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Image_SelectedIcon_MetaData), NewProp_Image_SelectedIcon_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Text_SelectedName = { "Text_SelectedName", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, Text_SelectedName), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_SelectedName_MetaData), NewProp_Text_SelectedName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Text_SelectedQuantity = { "Text_SelectedQuantity", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, Text_SelectedQuantity), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_SelectedQuantity_MetaData), NewProp_Text_SelectedQuantity_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Text_SelectedDescription = { "Text_SelectedDescription", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, Text_SelectedDescription), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_SelectedDescription_MetaData), NewProp_Text_SelectedDescription_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Text_SelectedCategory = { "Text_SelectedCategory", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, Text_SelectedCategory), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_SelectedCategory_MetaData), NewProp_Text_SelectedCategory_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Text_SelectedFlavor = { "Text_SelectedFlavor", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, Text_SelectedFlavor), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_SelectedFlavor_MetaData), NewProp_Text_SelectedFlavor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Text_EmptyHint = { "Text_EmptyHint", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, Text_EmptyHint), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_EmptyHint_MetaData), NewProp_Text_EmptyHint_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_HorizontalBox_Actions = { "HorizontalBox_Actions", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, HorizontalBox_Actions), Z_Construct_UClass_UHorizontalBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HorizontalBox_Actions_MetaData), NewProp_HorizontalBox_Actions_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Overlay_Root = { "Overlay_Root", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, Overlay_Root), Z_Construct_UClass_UOverlay_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Overlay_Root_MetaData), NewProp_Overlay_Root_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Border_BackgroundDim = { "Border_BackgroundDim", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, Border_BackgroundDim), Z_Construct_UClass_UBorder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Border_BackgroundDim_MetaData), NewProp_Border_BackgroundDim_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Border_InventoryWindow = { "Border_InventoryWindow", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, Border_InventoryWindow), Z_Construct_UClass_UBorder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Border_InventoryWindow_MetaData), NewProp_Border_InventoryWindow_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Text_DisabledReason = { "Text_DisabledReason", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, Text_DisabledReason), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_DisabledReason_MetaData), NewProp_Text_DisabledReason_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Button_Use = { "Button_Use", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, Button_Use), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Button_Use_MetaData), NewProp_Button_Use_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Button_Drop = { "Button_Drop", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, Button_Drop), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Button_Drop_MetaData), NewProp_Button_Drop_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Button_Inspect = { "Button_Inspect", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, Button_Inspect), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Button_Inspect_MetaData), NewProp_Button_Inspect_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Button_Close = { "Button_Close", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, Button_Close), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Button_Close_MetaData), NewProp_Button_Close_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_InventoryComponent = { "InventoryComponent", nullptr, (EPropertyFlags)0x012408000008201c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, InventoryComponent), Z_Construct_UClass_UInventoryComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryComponent_MetaData), NewProp_InventoryComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Coordinator = { "Coordinator", nullptr, (EPropertyFlags)0x0124080000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, Coordinator), Z_Construct_UClass_UInventoryUIComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Coordinator_MetaData), NewProp_Coordinator_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_SelectedSlotIndex = { "SelectedSlotIndex", nullptr, (EPropertyFlags)0x0020080000002014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, SelectedSlotIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedSlotIndex_MetaData), NewProp_SelectedSlotIndex_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_OpenTransitionDuration = { "OpenTransitionDuration", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, OpenTransitionDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpenTransitionDuration_MetaData), NewProp_OpenTransitionDuration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_CloseTransitionDuration = { "CloseTransitionDuration", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryWidgetBase, CloseTransitionDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CloseTransitionDuration_MetaData), NewProp_CloseTransitionDuration_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventoryWidgetBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_OnCloseRequested,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_OnCloseTransitionFinished,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_OnInspectTransitionFinished,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_SlotWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_GridColumnCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_bShowEmptySlots,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_UniformGridPanel_Items,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Text_Capacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Image_SelectedIcon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Text_SelectedName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Text_SelectedQuantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Text_SelectedDescription,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Text_SelectedCategory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Text_SelectedFlavor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Text_EmptyHint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_HorizontalBox_Actions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Overlay_Root,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Border_BackgroundDim,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Border_InventoryWindow,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Text_DisabledReason,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Button_Use,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Button_Drop,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Button_Inspect,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Button_Close,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_InventoryComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_Coordinator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_SelectedSlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_OpenTransitionDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryWidgetBase_Statics::NewProp_CloseTransitionDuration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidgetBase_Statics::PropPointers) < 2048);
// ********** End Class UInventoryWidgetBase Property Definitions **********************************
UObject* (*const Z_Construct_UClass_UInventoryWidgetBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_InventorySystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidgetBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventoryWidgetBase_Statics::ClassParams = {
	&UInventoryWidgetBase::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UInventoryWidgetBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidgetBase_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryWidgetBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UInventoryWidgetBase_Statics::Class_MetaDataParams)
};
void UInventoryWidgetBase::StaticRegisterNativesUInventoryWidgetBase()
{
	UClass* Class = UInventoryWidgetBase::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UInventoryWidgetBase_Statics::Funcs));
}
UClass* Z_Construct_UClass_UInventoryWidgetBase()
{
	if (!Z_Registration_Info_UClass_UInventoryWidgetBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventoryWidgetBase.OuterSingleton, Z_Construct_UClass_UInventoryWidgetBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInventoryWidgetBase.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UInventoryWidgetBase);
UInventoryWidgetBase::~UInventoryWidgetBase() {}
// ********** End Class UInventoryWidgetBase *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryWidgetBase_h__Script_InventorySystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInventoryWidgetBase, UInventoryWidgetBase::StaticClass, TEXT("UInventoryWidgetBase"), &Z_Registration_Info_UClass_UInventoryWidgetBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventoryWidgetBase), 3500648352U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryWidgetBase_h__Script_InventorySystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryWidgetBase_h__Script_InventorySystem_2915414857{
	TEXT("/Script/InventorySystem"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryWidgetBase_h__Script_InventorySystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryWidgetBase_h__Script_InventorySystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
