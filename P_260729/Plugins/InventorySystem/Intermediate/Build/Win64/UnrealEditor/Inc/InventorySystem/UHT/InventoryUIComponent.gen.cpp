// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/InventoryUIComponent.h"
#include "InputCoreTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeInventoryUIComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UEnhancedInputComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryComponent_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemDefinition_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemInspectorBridge_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryPickupNotificationWidget_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryUIComponent();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryUIComponent_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryWidgetBase_NoRegister();
INVENTORYSYSTEM_API UFunction* Z_Construct_UDelegateFunction_InventorySystem_InventoryUIPresentationSignature__DelegateSignature();
INVENTORYSYSTEM_API UFunction* Z_Construct_UDelegateFunction_InventorySystem_InventoryUIStateSignature__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_InventorySystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FInventoryUIStateSignature ********************************************
struct Z_Construct_UDelegateFunction_InventorySystem_InventoryUIStateSignature__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FInventoryUIStateSignature constinit property declarations ************
// ********** End Delegate FInventoryUIStateSignature constinit property declarations **************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_InventorySystem_InventoryUIStateSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_InventorySystem, nullptr, "InventoryUIStateSignature__DelegateSignature", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_InventoryUIStateSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_InventorySystem_InventoryUIStateSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_InventorySystem_InventoryUIStateSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_InventorySystem_InventoryUIStateSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FInventoryUIStateSignature_DelegateWrapper(const FMulticastScriptDelegate& InventoryUIStateSignature)
{
	InventoryUIStateSignature.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FInventoryUIStateSignature **********************************************

// ********** Begin Delegate FInventoryUIPresentationSignature *************************************
struct Z_Construct_UDelegateFunction_InventorySystem_InventoryUIPresentationSignature__DelegateSignature_Statics
{
	struct _Script_InventorySystem_eventInventoryUIPresentationSignature_Parms
	{
		bool bInventoryVisible;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FInventoryUIPresentationSignature constinit property declarations *****
	static void NewProp_bInventoryVisible_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInventoryVisible;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FInventoryUIPresentationSignature constinit property declarations *******
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FInventoryUIPresentationSignature Property Definitions ****************
void Z_Construct_UDelegateFunction_InventorySystem_InventoryUIPresentationSignature__DelegateSignature_Statics::NewProp_bInventoryVisible_SetBit(void* Obj)
{
	((_Script_InventorySystem_eventInventoryUIPresentationSignature_Parms*)Obj)->bInventoryVisible = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_InventorySystem_InventoryUIPresentationSignature__DelegateSignature_Statics::NewProp_bInventoryVisible = { "bInventoryVisible", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_InventorySystem_eventInventoryUIPresentationSignature_Parms), &Z_Construct_UDelegateFunction_InventorySystem_InventoryUIPresentationSignature__DelegateSignature_Statics::NewProp_bInventoryVisible_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_InventorySystem_InventoryUIPresentationSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_InventorySystem_InventoryUIPresentationSignature__DelegateSignature_Statics::NewProp_bInventoryVisible,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_InventoryUIPresentationSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FInventoryUIPresentationSignature Property Definitions ******************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_InventorySystem_InventoryUIPresentationSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_InventorySystem, nullptr, "InventoryUIPresentationSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_InventorySystem_InventoryUIPresentationSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_InventoryUIPresentationSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_InventorySystem_InventoryUIPresentationSignature__DelegateSignature_Statics::_Script_InventorySystem_eventInventoryUIPresentationSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_InventoryUIPresentationSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_InventorySystem_InventoryUIPresentationSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_InventorySystem_InventoryUIPresentationSignature__DelegateSignature_Statics::_Script_InventorySystem_eventInventoryUIPresentationSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_InventorySystem_InventoryUIPresentationSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_InventorySystem_InventoryUIPresentationSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FInventoryUIPresentationSignature_DelegateWrapper(const FMulticastScriptDelegate& InventoryUIPresentationSignature, bool bInventoryVisible)
{
	struct _Script_InventorySystem_eventInventoryUIPresentationSignature_Parms
	{
		bool bInventoryVisible;
	};
	_Script_InventorySystem_eventInventoryUIPresentationSignature_Parms Parms;
	Parms.bInventoryVisible=bInventoryVisible ? true : false;
	InventoryUIPresentationSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FInventoryUIPresentationSignature ***************************************

// ********** Begin Class UInventoryUIComponent Function BindEnhancedInput *************************
struct Z_Construct_UFunction_UInventoryUIComponent_BindEnhancedInput_Statics
{
	struct InventoryUIComponent_eventBindEnhancedInput_Parms
	{
		UEnhancedInputComponent* EnhancedInputComponent;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Input" },
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnhancedInputComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function BindEnhancedInput constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EnhancedInputComponent;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BindEnhancedInput constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BindEnhancedInput Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryUIComponent_BindEnhancedInput_Statics::NewProp_EnhancedInputComponent = { "EnhancedInputComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryUIComponent_eventBindEnhancedInput_Parms, EnhancedInputComponent), Z_Construct_UClass_UEnhancedInputComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnhancedInputComponent_MetaData), NewProp_EnhancedInputComponent_MetaData) };
void Z_Construct_UFunction_UInventoryUIComponent_BindEnhancedInput_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventoryUIComponent_eventBindEnhancedInput_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryUIComponent_BindEnhancedInput_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventoryUIComponent_eventBindEnhancedInput_Parms), &Z_Construct_UFunction_UInventoryUIComponent_BindEnhancedInput_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryUIComponent_BindEnhancedInput_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryUIComponent_BindEnhancedInput_Statics::NewProp_EnhancedInputComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryUIComponent_BindEnhancedInput_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_BindEnhancedInput_Statics::PropPointers) < 2048);
// ********** End Function BindEnhancedInput Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryUIComponent_BindEnhancedInput_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryUIComponent, nullptr, "BindEnhancedInput", 	Z_Construct_UFunction_UInventoryUIComponent_BindEnhancedInput_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_BindEnhancedInput_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryUIComponent_BindEnhancedInput_Statics::InventoryUIComponent_eventBindEnhancedInput_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_BindEnhancedInput_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryUIComponent_BindEnhancedInput_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryUIComponent_BindEnhancedInput_Statics::InventoryUIComponent_eventBindEnhancedInput_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryUIComponent_BindEnhancedInput()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryUIComponent_BindEnhancedInput_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryUIComponent::execBindEnhancedInput)
{
	P_GET_OBJECT(UEnhancedInputComponent,Z_Param_EnhancedInputComponent);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->BindEnhancedInput(Z_Param_EnhancedInputComponent);
	P_NATIVE_END;
}
// ********** End Class UInventoryUIComponent Function BindEnhancedInput ***************************

// ********** Begin Class UInventoryUIComponent Function CloseInventory ****************************
struct Z_Construct_UFunction_UInventoryUIComponent_CloseInventory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CloseInventory constinit property declarations ************************
// ********** End Function CloseInventory constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryUIComponent_CloseInventory_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryUIComponent, nullptr, "CloseInventory", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_CloseInventory_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryUIComponent_CloseInventory_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventoryUIComponent_CloseInventory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryUIComponent_CloseInventory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryUIComponent::execCloseInventory)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CloseInventory();
	P_NATIVE_END;
}
// ********** End Class UInventoryUIComponent Function CloseInventory ******************************

// ********** Begin Class UInventoryUIComponent Function GetInventoryWidget ************************
struct Z_Construct_UFunction_UInventoryUIComponent_GetInventoryWidget_Statics
{
	struct InventoryUIComponent_eventGetInventoryWidget_Parms
	{
		UInventoryWidgetBase* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetInventoryWidget constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetInventoryWidget constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetInventoryWidget Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryUIComponent_GetInventoryWidget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryUIComponent_eventGetInventoryWidget_Parms, ReturnValue), Z_Construct_UClass_UInventoryWidgetBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryUIComponent_GetInventoryWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryUIComponent_GetInventoryWidget_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_GetInventoryWidget_Statics::PropPointers) < 2048);
// ********** End Function GetInventoryWidget Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryUIComponent_GetInventoryWidget_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryUIComponent, nullptr, "GetInventoryWidget", 	Z_Construct_UFunction_UInventoryUIComponent_GetInventoryWidget_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_GetInventoryWidget_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryUIComponent_GetInventoryWidget_Statics::InventoryUIComponent_eventGetInventoryWidget_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_GetInventoryWidget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryUIComponent_GetInventoryWidget_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryUIComponent_GetInventoryWidget_Statics::InventoryUIComponent_eventGetInventoryWidget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryUIComponent_GetInventoryWidget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryUIComponent_GetInventoryWidget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryUIComponent::execGetInventoryWidget)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UInventoryWidgetBase**)Z_Param__Result=P_THIS->GetInventoryWidget();
	P_NATIVE_END;
}
// ********** End Class UInventoryUIComponent Function GetInventoryWidget **************************

// ********** Begin Class UInventoryUIComponent Function HandleInspectorClosed *********************
struct Z_Construct_UFunction_UInventoryUIComponent_HandleInspectorClosed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleInspectorClosed constinit property declarations *****************
// ********** End Function HandleInspectorClosed constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryUIComponent_HandleInspectorClosed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryUIComponent, nullptr, "HandleInspectorClosed", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_HandleInspectorClosed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryUIComponent_HandleInspectorClosed_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventoryUIComponent_HandleInspectorClosed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryUIComponent_HandleInspectorClosed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryUIComponent::execHandleInspectorClosed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleInspectorClosed();
	P_NATIVE_END;
}
// ********** End Class UInventoryUIComponent Function HandleInspectorClosed ***********************

// ********** Begin Class UInventoryUIComponent Function HandleItemsReceived ***********************
struct Z_Construct_UFunction_UInventoryUIComponent_HandleItemsReceived_Statics
{
	struct InventoryUIComponent_eventHandleItemsReceived_Parms
	{
		UInventoryItemDefinition* ItemDefinition;
		int32 Quantity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleItemsReceived constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemDefinition;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleItemsReceived constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleItemsReceived Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryUIComponent_HandleItemsReceived_Statics::NewProp_ItemDefinition = { "ItemDefinition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryUIComponent_eventHandleItemsReceived_Parms, ItemDefinition), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryUIComponent_HandleItemsReceived_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryUIComponent_eventHandleItemsReceived_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryUIComponent_HandleItemsReceived_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryUIComponent_HandleItemsReceived_Statics::NewProp_ItemDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryUIComponent_HandleItemsReceived_Statics::NewProp_Quantity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_HandleItemsReceived_Statics::PropPointers) < 2048);
// ********** End Function HandleItemsReceived Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryUIComponent_HandleItemsReceived_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryUIComponent, nullptr, "HandleItemsReceived", 	Z_Construct_UFunction_UInventoryUIComponent_HandleItemsReceived_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_HandleItemsReceived_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryUIComponent_HandleItemsReceived_Statics::InventoryUIComponent_eventHandleItemsReceived_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_HandleItemsReceived_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryUIComponent_HandleItemsReceived_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryUIComponent_HandleItemsReceived_Statics::InventoryUIComponent_eventHandleItemsReceived_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryUIComponent_HandleItemsReceived()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryUIComponent_HandleItemsReceived_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryUIComponent::execHandleItemsReceived)
{
	P_GET_OBJECT(UInventoryItemDefinition,Z_Param_ItemDefinition);
	P_GET_PROPERTY(FIntProperty,Z_Param_Quantity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleItemsReceived(Z_Param_ItemDefinition,Z_Param_Quantity);
	P_NATIVE_END;
}
// ********** End Class UInventoryUIComponent Function HandleItemsReceived *************************

// ********** Begin Class UInventoryUIComponent Function HandleToggleInput *************************
struct Z_Construct_UFunction_UInventoryUIComponent_HandleToggleInput_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleToggleInput constinit property declarations *********************
// ********** End Function HandleToggleInput constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryUIComponent_HandleToggleInput_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryUIComponent, nullptr, "HandleToggleInput", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_HandleToggleInput_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryUIComponent_HandleToggleInput_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventoryUIComponent_HandleToggleInput()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryUIComponent_HandleToggleInput_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryUIComponent::execHandleToggleInput)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleToggleInput();
	P_NATIVE_END;
}
// ********** End Class UInventoryUIComponent Function HandleToggleInput ***************************

// ********** Begin Class UInventoryUIComponent Function HandleWidgetCloseRequested ****************
struct Z_Construct_UFunction_UInventoryUIComponent_HandleWidgetCloseRequested_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleWidgetCloseRequested constinit property declarations ************
// ********** End Function HandleWidgetCloseRequested constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryUIComponent_HandleWidgetCloseRequested_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryUIComponent, nullptr, "HandleWidgetCloseRequested", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_HandleWidgetCloseRequested_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryUIComponent_HandleWidgetCloseRequested_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventoryUIComponent_HandleWidgetCloseRequested()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryUIComponent_HandleWidgetCloseRequested_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryUIComponent::execHandleWidgetCloseRequested)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleWidgetCloseRequested();
	P_NATIVE_END;
}
// ********** End Class UInventoryUIComponent Function HandleWidgetCloseRequested ******************

// ********** Begin Class UInventoryUIComponent Function HandleWidgetCloseTransitionFinished *******
struct Z_Construct_UFunction_UInventoryUIComponent_HandleWidgetCloseTransitionFinished_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleWidgetCloseTransitionFinished constinit property declarations ***
// ********** End Function HandleWidgetCloseTransitionFinished constinit property declarations *****
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryUIComponent_HandleWidgetCloseTransitionFinished_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryUIComponent, nullptr, "HandleWidgetCloseTransitionFinished", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_HandleWidgetCloseTransitionFinished_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryUIComponent_HandleWidgetCloseTransitionFinished_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventoryUIComponent_HandleWidgetCloseTransitionFinished()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryUIComponent_HandleWidgetCloseTransitionFinished_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryUIComponent::execHandleWidgetCloseTransitionFinished)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleWidgetCloseTransitionFinished();
	P_NATIVE_END;
}
// ********** End Class UInventoryUIComponent Function HandleWidgetCloseTransitionFinished *********

// ********** Begin Class UInventoryUIComponent Function HandleWidgetInspectTransitionFinished *****
struct Z_Construct_UFunction_UInventoryUIComponent_HandleWidgetInspectTransitionFinished_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleWidgetInspectTransitionFinished constinit property declarations *
// ********** End Function HandleWidgetInspectTransitionFinished constinit property declarations ***
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryUIComponent_HandleWidgetInspectTransitionFinished_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryUIComponent, nullptr, "HandleWidgetInspectTransitionFinished", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_HandleWidgetInspectTransitionFinished_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryUIComponent_HandleWidgetInspectTransitionFinished_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventoryUIComponent_HandleWidgetInspectTransitionFinished()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryUIComponent_HandleWidgetInspectTransitionFinished_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryUIComponent::execHandleWidgetInspectTransitionFinished)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleWidgetInspectTransitionFinished();
	P_NATIVE_END;
}
// ********** End Class UInventoryUIComponent Function HandleWidgetInspectTransitionFinished *******

// ********** Begin Class UInventoryUIComponent Function InspectItem *******************************
struct Z_Construct_UFunction_UInventoryUIComponent_InspectItem_Statics
{
	struct InventoryUIComponent_eventInspectItem_Parms
	{
		UInventoryItemDefinition* ItemDefinition;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Inspector" },
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function InspectItem constinit property declarations ***************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemDefinition;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InspectItem constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InspectItem Property Definitions **************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryUIComponent_InspectItem_Statics::NewProp_ItemDefinition = { "ItemDefinition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryUIComponent_eventInspectItem_Parms, ItemDefinition), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UInventoryUIComponent_InspectItem_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventoryUIComponent_eventInspectItem_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryUIComponent_InspectItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventoryUIComponent_eventInspectItem_Parms), &Z_Construct_UFunction_UInventoryUIComponent_InspectItem_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryUIComponent_InspectItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryUIComponent_InspectItem_Statics::NewProp_ItemDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryUIComponent_InspectItem_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_InspectItem_Statics::PropPointers) < 2048);
// ********** End Function InspectItem Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryUIComponent_InspectItem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryUIComponent, nullptr, "InspectItem", 	Z_Construct_UFunction_UInventoryUIComponent_InspectItem_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_InspectItem_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryUIComponent_InspectItem_Statics::InventoryUIComponent_eventInspectItem_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_InspectItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryUIComponent_InspectItem_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryUIComponent_InspectItem_Statics::InventoryUIComponent_eventInspectItem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryUIComponent_InspectItem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryUIComponent_InspectItem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryUIComponent::execInspectItem)
{
	P_GET_OBJECT(UInventoryItemDefinition,Z_Param_ItemDefinition);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->InspectItem(Z_Param_ItemDefinition);
	P_NATIVE_END;
}
// ********** End Class UInventoryUIComponent Function InspectItem *********************************

// ********** Begin Class UInventoryUIComponent Function IsInventoryOpen ***************************
struct Z_Construct_UFunction_UInventoryUIComponent_IsInventoryOpen_Statics
{
	struct InventoryUIComponent_eventIsInventoryOpen_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsInventoryOpen constinit property declarations ***********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsInventoryOpen constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsInventoryOpen Property Definitions **********************************
void Z_Construct_UFunction_UInventoryUIComponent_IsInventoryOpen_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventoryUIComponent_eventIsInventoryOpen_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryUIComponent_IsInventoryOpen_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventoryUIComponent_eventIsInventoryOpen_Parms), &Z_Construct_UFunction_UInventoryUIComponent_IsInventoryOpen_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryUIComponent_IsInventoryOpen_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryUIComponent_IsInventoryOpen_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_IsInventoryOpen_Statics::PropPointers) < 2048);
// ********** End Function IsInventoryOpen Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryUIComponent_IsInventoryOpen_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryUIComponent, nullptr, "IsInventoryOpen", 	Z_Construct_UFunction_UInventoryUIComponent_IsInventoryOpen_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_IsInventoryOpen_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryUIComponent_IsInventoryOpen_Statics::InventoryUIComponent_eventIsInventoryOpen_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_IsInventoryOpen_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryUIComponent_IsInventoryOpen_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryUIComponent_IsInventoryOpen_Statics::InventoryUIComponent_eventIsInventoryOpen_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryUIComponent_IsInventoryOpen()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryUIComponent_IsInventoryOpen_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryUIComponent::execIsInventoryOpen)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsInventoryOpen();
	P_NATIVE_END;
}
// ********** End Class UInventoryUIComponent Function IsInventoryOpen *****************************

// ********** Begin Class UInventoryUIComponent Function IsToggleInventoryKey **********************
struct Z_Construct_UFunction_UInventoryUIComponent_IsToggleInventoryKey_Statics
{
	struct InventoryUIComponent_eventIsToggleInventoryKey_Parms
	{
		FKey Key;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xed\x98\x84\xec\x9e\xac \xed\x99\x9c\xec\x84\xb1 Enhanced Input Mapping\xec\x97\x90\xec\x84\x9c ToggleInventoryAction\xec\x97\x90 \xec\x97\xb0\xea\xb2\xb0\xeb\x90\x9c Key\xec\x9d\xb8\xec\xa7\x80 \xed\x99\x95\xec\x9d\xb8\xed\x95\x9c\xeb\x8b\xa4. */" },
#endif
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x98\x84\xec\x9e\xac \xed\x99\x9c\xec\x84\xb1 Enhanced Input Mapping\xec\x97\x90\xec\x84\x9c ToggleInventoryAction\xec\x97\x90 \xec\x97\xb0\xea\xb2\xb0\xeb\x90\x9c Key\xec\x9d\xb8\xec\xa7\x80 \xed\x99\x95\xec\x9d\xb8\xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsToggleInventoryKey constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Key;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsToggleInventoryKey constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsToggleInventoryKey Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryUIComponent_IsToggleInventoryKey_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryUIComponent_eventIsToggleInventoryKey_Parms, Key), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(0, nullptr) }; // 2693575693
void Z_Construct_UFunction_UInventoryUIComponent_IsToggleInventoryKey_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventoryUIComponent_eventIsToggleInventoryKey_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryUIComponent_IsToggleInventoryKey_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventoryUIComponent_eventIsToggleInventoryKey_Parms), &Z_Construct_UFunction_UInventoryUIComponent_IsToggleInventoryKey_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryUIComponent_IsToggleInventoryKey_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryUIComponent_IsToggleInventoryKey_Statics::NewProp_Key,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryUIComponent_IsToggleInventoryKey_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_IsToggleInventoryKey_Statics::PropPointers) < 2048);
// ********** End Function IsToggleInventoryKey Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryUIComponent_IsToggleInventoryKey_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryUIComponent, nullptr, "IsToggleInventoryKey", 	Z_Construct_UFunction_UInventoryUIComponent_IsToggleInventoryKey_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_IsToggleInventoryKey_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryUIComponent_IsToggleInventoryKey_Statics::InventoryUIComponent_eventIsToggleInventoryKey_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_IsToggleInventoryKey_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryUIComponent_IsToggleInventoryKey_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryUIComponent_IsToggleInventoryKey_Statics::InventoryUIComponent_eventIsToggleInventoryKey_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryUIComponent_IsToggleInventoryKey()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryUIComponent_IsToggleInventoryKey_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryUIComponent::execIsToggleInventoryKey)
{
	P_GET_STRUCT(FKey,Z_Param_Key);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsToggleInventoryKey(Z_Param_Key);
	P_NATIVE_END;
}
// ********** End Class UInventoryUIComponent Function IsToggleInventoryKey ************************

// ********** Begin Class UInventoryUIComponent Function OpenInventory *****************************
struct Z_Construct_UFunction_UInventoryUIComponent_OpenInventory_Statics
{
	struct InventoryUIComponent_eventOpenInventory_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OpenInventory constinit property declarations *************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OpenInventory constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OpenInventory Property Definitions ************************************
void Z_Construct_UFunction_UInventoryUIComponent_OpenInventory_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventoryUIComponent_eventOpenInventory_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryUIComponent_OpenInventory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventoryUIComponent_eventOpenInventory_Parms), &Z_Construct_UFunction_UInventoryUIComponent_OpenInventory_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryUIComponent_OpenInventory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryUIComponent_OpenInventory_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_OpenInventory_Statics::PropPointers) < 2048);
// ********** End Function OpenInventory Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryUIComponent_OpenInventory_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryUIComponent, nullptr, "OpenInventory", 	Z_Construct_UFunction_UInventoryUIComponent_OpenInventory_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_OpenInventory_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryUIComponent_OpenInventory_Statics::InventoryUIComponent_eventOpenInventory_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_OpenInventory_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryUIComponent_OpenInventory_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryUIComponent_OpenInventory_Statics::InventoryUIComponent_eventOpenInventory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryUIComponent_OpenInventory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryUIComponent_OpenInventory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryUIComponent::execOpenInventory)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->OpenInventory();
	P_NATIVE_END;
}
// ********** End Class UInventoryUIComponent Function OpenInventory *******************************

// ********** Begin Class UInventoryUIComponent Function ToggleInventory ***************************
struct Z_Construct_UFunction_UInventoryUIComponent_ToggleInventory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ToggleInventory constinit property declarations ***********************
// ********** End Function ToggleInventory constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryUIComponent_ToggleInventory_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryUIComponent, nullptr, "ToggleInventory", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryUIComponent_ToggleInventory_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryUIComponent_ToggleInventory_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventoryUIComponent_ToggleInventory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryUIComponent_ToggleInventory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryUIComponent::execToggleInventory)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ToggleInventory();
	P_NATIVE_END;
}
// ********** End Class UInventoryUIComponent Function ToggleInventory *****************************

// ********** Begin Class UInventoryUIComponent ****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UInventoryUIComponent;
UClass* UInventoryUIComponent::GetPrivateStaticClass()
{
	using TClass = UInventoryUIComponent;
	if (!Z_Registration_Info_UClass_UInventoryUIComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("InventoryUIComponent"),
			Z_Registration_Info_UClass_UInventoryUIComponent.InnerSingleton,
			StaticRegisterNativesUInventoryUIComponent,
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
	return Z_Registration_Info_UClass_UInventoryUIComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UInventoryUIComponent_NoRegister()
{
	return UInventoryUIComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UInventoryUIComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Inventory" },
		{ "IncludePath", "Components/InventoryUIComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnInventoryOpened_MetaData[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnInventoryClosed_MetaData[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnInventoryPresentationChanged_MetaData[] = {
		{ "Category", "Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Generic modal-HUD hook. Gameplay HUD layers should fade out for true and restore for false. */" },
#endif
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Generic modal-HUD hook. Gameplay HUD layers should fade out for true and restore for false." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventoryWidgetClass_MetaData[] = {
		{ "Category", "Inventory|UI" },
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToggleInventoryAction_MetaData[] = {
		{ "Category", "Inventory|Input" },
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToggleInputMappingContext_MetaData[] = {
		{ "Category", "Inventory|Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** UI\xea\xb0\x80 Action Key\xeb\xa5\xbc \xeb\xa8\xbc\xec\xa0\x80 \xec\x86\x8c\xeb\xb9\x84\xed\x95\xb4\xeb\x8f\x84 \xea\xb0\x99\xec\x9d\x80 Key\xeb\xa1\x9c \xeb\x8b\xab\xec\x9d\x84 \xec\x88\x98 \xec\x9e\x88\xeb\x8f\x84\xeb\xa1\x9d Action\xec\x9d\xb4 \xeb\x93\xa4\xec\x96\xb4 \xec\x9e\x88\xeb\x8a\x94 Mapping Context\xeb\xa5\xbc \xec\xa7\x80\xec\xa0\x95\xed\x95\x9c\xeb\x8b\xa4. */" },
#endif
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UI\xea\xb0\x80 Action Key\xeb\xa5\xbc \xeb\xa8\xbc\xec\xa0\x80 \xec\x86\x8c\xeb\xb9\x84\xed\x95\xb4\xeb\x8f\x84 \xea\xb0\x99\xec\x9d\x80 Key\xeb\xa1\x9c \xeb\x8b\xab\xec\x9d\x84 \xec\x88\x98 \xec\x9e\x88\xeb\x8f\x84\xeb\xa1\x9d Action\xec\x9d\xb4 \xeb\x93\xa4\xec\x96\xb4 \xec\x9e\x88\xeb\x8a\x94 Mapping Context\xeb\xa5\xbc \xec\xa7\x80\xec\xa0\x95\xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InspectorBridge_MetaData[] = {
		{ "Category", "Inventory|Inspector" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventoryComponent_MetaData[] = {
		{ "Category", "Inventory" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PickupNotificationWidgetClass_MetaData[] = {
		{ "Category", "Inventory|Notification" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xeb\xb9\x84\xec\x9b\x8c \xeb\x91\x90\xeb\xa9\xb4 C++ \xea\xb8\xb0\xeb\xb3\xb8 \xed\x9a\x8d\xeb\x93\x9d \xec\x95\x8c\xeb\xa6\xbc Widget\xec\x9d\x84 \xec\x82\xac\xec\x9a\xa9\xed\x95\x9c\xeb\x8b\xa4. */" },
#endif
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb9\x84\xec\x9b\x8c \xeb\x91\x90\xeb\xa9\xb4 C++ \xea\xb8\xb0\xeb\xb3\xb8 \xed\x9a\x8d\xeb\x93\x9d \xec\x95\x8c\xeb\xa6\xbc Widget\xec\x9d\x84 \xec\x82\xac\xec\x9a\xa9\xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PickupNotificationDuration_MetaData[] = {
		{ "Category", "Inventory|Notification" },
		{ "ClampMin", "0.1" },
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventoryWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PickupNotificationWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PendingInspectorItem_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/InventoryUIComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UInventoryUIComponent constinit property declarations ********************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInventoryOpened;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInventoryClosed;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInventoryPresentationChanged;
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_InventoryWidgetClass;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_ToggleInventoryAction;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_ToggleInputMappingContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InspectorBridge;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InventoryComponent;
	static const UECodeGen_Private::FClassPropertyParams NewProp_PickupNotificationWidgetClass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PickupNotificationDuration;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InventoryWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PickupNotificationWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PendingInspectorItem;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UInventoryUIComponent constinit property declarations **********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("BindEnhancedInput"), .Pointer = &UInventoryUIComponent::execBindEnhancedInput },
		{ .NameUTF8 = UTF8TEXT("CloseInventory"), .Pointer = &UInventoryUIComponent::execCloseInventory },
		{ .NameUTF8 = UTF8TEXT("GetInventoryWidget"), .Pointer = &UInventoryUIComponent::execGetInventoryWidget },
		{ .NameUTF8 = UTF8TEXT("HandleInspectorClosed"), .Pointer = &UInventoryUIComponent::execHandleInspectorClosed },
		{ .NameUTF8 = UTF8TEXT("HandleItemsReceived"), .Pointer = &UInventoryUIComponent::execHandleItemsReceived },
		{ .NameUTF8 = UTF8TEXT("HandleToggleInput"), .Pointer = &UInventoryUIComponent::execHandleToggleInput },
		{ .NameUTF8 = UTF8TEXT("HandleWidgetCloseRequested"), .Pointer = &UInventoryUIComponent::execHandleWidgetCloseRequested },
		{ .NameUTF8 = UTF8TEXT("HandleWidgetCloseTransitionFinished"), .Pointer = &UInventoryUIComponent::execHandleWidgetCloseTransitionFinished },
		{ .NameUTF8 = UTF8TEXT("HandleWidgetInspectTransitionFinished"), .Pointer = &UInventoryUIComponent::execHandleWidgetInspectTransitionFinished },
		{ .NameUTF8 = UTF8TEXT("InspectItem"), .Pointer = &UInventoryUIComponent::execInspectItem },
		{ .NameUTF8 = UTF8TEXT("IsInventoryOpen"), .Pointer = &UInventoryUIComponent::execIsInventoryOpen },
		{ .NameUTF8 = UTF8TEXT("IsToggleInventoryKey"), .Pointer = &UInventoryUIComponent::execIsToggleInventoryKey },
		{ .NameUTF8 = UTF8TEXT("OpenInventory"), .Pointer = &UInventoryUIComponent::execOpenInventory },
		{ .NameUTF8 = UTF8TEXT("ToggleInventory"), .Pointer = &UInventoryUIComponent::execToggleInventory },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventoryUIComponent_BindEnhancedInput, "BindEnhancedInput" }, // 843097768
		{ &Z_Construct_UFunction_UInventoryUIComponent_CloseInventory, "CloseInventory" }, // 1437808333
		{ &Z_Construct_UFunction_UInventoryUIComponent_GetInventoryWidget, "GetInventoryWidget" }, // 1116081552
		{ &Z_Construct_UFunction_UInventoryUIComponent_HandleInspectorClosed, "HandleInspectorClosed" }, // 1625004228
		{ &Z_Construct_UFunction_UInventoryUIComponent_HandleItemsReceived, "HandleItemsReceived" }, // 3362668447
		{ &Z_Construct_UFunction_UInventoryUIComponent_HandleToggleInput, "HandleToggleInput" }, // 3922759983
		{ &Z_Construct_UFunction_UInventoryUIComponent_HandleWidgetCloseRequested, "HandleWidgetCloseRequested" }, // 800246873
		{ &Z_Construct_UFunction_UInventoryUIComponent_HandleWidgetCloseTransitionFinished, "HandleWidgetCloseTransitionFinished" }, // 2882020518
		{ &Z_Construct_UFunction_UInventoryUIComponent_HandleWidgetInspectTransitionFinished, "HandleWidgetInspectTransitionFinished" }, // 1594178003
		{ &Z_Construct_UFunction_UInventoryUIComponent_InspectItem, "InspectItem" }, // 2128124235
		{ &Z_Construct_UFunction_UInventoryUIComponent_IsInventoryOpen, "IsInventoryOpen" }, // 173956863
		{ &Z_Construct_UFunction_UInventoryUIComponent_IsToggleInventoryKey, "IsToggleInventoryKey" }, // 1475217911
		{ &Z_Construct_UFunction_UInventoryUIComponent_OpenInventory, "OpenInventory" }, // 113112036
		{ &Z_Construct_UFunction_UInventoryUIComponent_ToggleInventory, "ToggleInventory" }, // 2015895849
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryUIComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UInventoryUIComponent_Statics

// ********** Begin Class UInventoryUIComponent Property Definitions *******************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_OnInventoryOpened = { "OnInventoryOpened", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryUIComponent, OnInventoryOpened), Z_Construct_UDelegateFunction_InventorySystem_InventoryUIStateSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnInventoryOpened_MetaData), NewProp_OnInventoryOpened_MetaData) }; // 566908224
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_OnInventoryClosed = { "OnInventoryClosed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryUIComponent, OnInventoryClosed), Z_Construct_UDelegateFunction_InventorySystem_InventoryUIStateSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnInventoryClosed_MetaData), NewProp_OnInventoryClosed_MetaData) }; // 566908224
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_OnInventoryPresentationChanged = { "OnInventoryPresentationChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryUIComponent, OnInventoryPresentationChanged), Z_Construct_UDelegateFunction_InventorySystem_InventoryUIPresentationSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnInventoryPresentationChanged_MetaData), NewProp_OnInventoryPresentationChanged_MetaData) }; // 1033194839
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_InventoryWidgetClass = { "InventoryWidgetClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryUIComponent, InventoryWidgetClass), Z_Construct_UClass_UInventoryWidgetBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryWidgetClass_MetaData), NewProp_InventoryWidgetClass_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_ToggleInventoryAction = { "ToggleInventoryAction", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryUIComponent, ToggleInventoryAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToggleInventoryAction_MetaData), NewProp_ToggleInventoryAction_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_ToggleInputMappingContext = { "ToggleInputMappingContext", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryUIComponent, ToggleInputMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToggleInputMappingContext_MetaData), NewProp_ToggleInputMappingContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_InspectorBridge = { "InspectorBridge", nullptr, (EPropertyFlags)0x011600000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryUIComponent, InspectorBridge), Z_Construct_UClass_UInventoryItemInspectorBridge_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InspectorBridge_MetaData), NewProp_InspectorBridge_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_InventoryComponent = { "InventoryComponent", nullptr, (EPropertyFlags)0x011400000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryUIComponent, InventoryComponent), Z_Construct_UClass_UInventoryComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryComponent_MetaData), NewProp_InventoryComponent_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_PickupNotificationWidgetClass = { "PickupNotificationWidgetClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryUIComponent, PickupNotificationWidgetClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UInventoryPickupNotificationWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PickupNotificationWidgetClass_MetaData), NewProp_PickupNotificationWidgetClass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_PickupNotificationDuration = { "PickupNotificationDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryUIComponent, PickupNotificationDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PickupNotificationDuration_MetaData), NewProp_PickupNotificationDuration_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_InventoryWidget = { "InventoryWidget", nullptr, (EPropertyFlags)0x0124080000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryUIComponent, InventoryWidget), Z_Construct_UClass_UInventoryWidgetBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryWidget_MetaData), NewProp_InventoryWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_PickupNotificationWidget = { "PickupNotificationWidget", nullptr, (EPropertyFlags)0x0124080000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryUIComponent, PickupNotificationWidget), Z_Construct_UClass_UInventoryPickupNotificationWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PickupNotificationWidget_MetaData), NewProp_PickupNotificationWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_PendingInspectorItem = { "PendingInspectorItem", nullptr, (EPropertyFlags)0x0124080000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryUIComponent, PendingInspectorItem), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PendingInspectorItem_MetaData), NewProp_PendingInspectorItem_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventoryUIComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_OnInventoryOpened,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_OnInventoryClosed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_OnInventoryPresentationChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_InventoryWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_ToggleInventoryAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_ToggleInputMappingContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_InspectorBridge,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_InventoryComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_PickupNotificationWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_PickupNotificationDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_InventoryWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_PickupNotificationWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryUIComponent_Statics::NewProp_PendingInspectorItem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryUIComponent_Statics::PropPointers) < 2048);
// ********** End Class UInventoryUIComponent Property Definitions *********************************
UObject* (*const Z_Construct_UClass_UInventoryUIComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_InventorySystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryUIComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventoryUIComponent_Statics::ClassParams = {
	&UInventoryUIComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UInventoryUIComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryUIComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryUIComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UInventoryUIComponent_Statics::Class_MetaDataParams)
};
void UInventoryUIComponent::StaticRegisterNativesUInventoryUIComponent()
{
	UClass* Class = UInventoryUIComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UInventoryUIComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UInventoryUIComponent()
{
	if (!Z_Registration_Info_UClass_UInventoryUIComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventoryUIComponent.OuterSingleton, Z_Construct_UClass_UInventoryUIComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInventoryUIComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UInventoryUIComponent);
UInventoryUIComponent::~UInventoryUIComponent() {}
// ********** End Class UInventoryUIComponent ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryUIComponent_h__Script_InventorySystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInventoryUIComponent, UInventoryUIComponent::StaticClass, TEXT("UInventoryUIComponent"), &Z_Registration_Info_UClass_UInventoryUIComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventoryUIComponent), 114948399U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryUIComponent_h__Script_InventorySystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryUIComponent_h__Script_InventorySystem_1871357060{
	TEXT("/Script/InventorySystem"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryUIComponent_h__Script_InventorySystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Components_InventoryUIComponent_h__Script_InventorySystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
