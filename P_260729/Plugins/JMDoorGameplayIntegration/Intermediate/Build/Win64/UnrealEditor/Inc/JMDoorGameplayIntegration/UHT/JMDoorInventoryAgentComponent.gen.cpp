// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/JMDoorInventoryAgentComponent.h"
#include "Types/JMInteractionTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMDoorInventoryAgentComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemDefinition_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemUseReceiverInterface_NoRegister();
JMDOORGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMDoorInventoryAgentComponent();
JMDOORGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMDoorInventoryAgentComponent_NoRegister();
JMDOORGAMEPLAYINTEGRATION_API UFunction* Z_Construct_UDelegateFunction_JMDoorGameplayIntegration_JMPendingDoorChangedSignature__DelegateSignature();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_AJMDoorActor_NoRegister();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionContext();
UPackage* Z_Construct_UPackage__Script_JMDoorGameplayIntegration();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FJMPendingDoorChangedSignature ****************************************
struct Z_Construct_UDelegateFunction_JMDoorGameplayIntegration_JMPendingDoorChangedSignature__DelegateSignature_Statics
{
	struct _Script_JMDoorGameplayIntegration_eventJMPendingDoorChangedSignature_Parms
	{
		AJMDoorActor* PendingDoor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/JMDoorInventoryAgentComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMPendingDoorChangedSignature constinit property declarations ********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PendingDoor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMPendingDoorChangedSignature constinit property declarations **********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMPendingDoorChangedSignature Property Definitions *******************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_JMDoorGameplayIntegration_JMPendingDoorChangedSignature__DelegateSignature_Statics::NewProp_PendingDoor = { "PendingDoor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMDoorGameplayIntegration_eventJMPendingDoorChangedSignature_Parms, PendingDoor), Z_Construct_UClass_AJMDoorActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMDoorGameplayIntegration_JMPendingDoorChangedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMDoorGameplayIntegration_JMPendingDoorChangedSignature__DelegateSignature_Statics::NewProp_PendingDoor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMDoorGameplayIntegration_JMPendingDoorChangedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMPendingDoorChangedSignature Property Definitions *********************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMDoorGameplayIntegration_JMPendingDoorChangedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMDoorGameplayIntegration, nullptr, "JMPendingDoorChangedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_JMDoorGameplayIntegration_JMPendingDoorChangedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMDoorGameplayIntegration_JMPendingDoorChangedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMDoorGameplayIntegration_JMPendingDoorChangedSignature__DelegateSignature_Statics::_Script_JMDoorGameplayIntegration_eventJMPendingDoorChangedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMDoorGameplayIntegration_JMPendingDoorChangedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMDoorGameplayIntegration_JMPendingDoorChangedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMDoorGameplayIntegration_JMPendingDoorChangedSignature__DelegateSignature_Statics::_Script_JMDoorGameplayIntegration_eventJMPendingDoorChangedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMDoorGameplayIntegration_JMPendingDoorChangedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMDoorGameplayIntegration_JMPendingDoorChangedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMPendingDoorChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMPendingDoorChangedSignature, AJMDoorActor* PendingDoor)
{
	struct _Script_JMDoorGameplayIntegration_eventJMPendingDoorChangedSignature_Parms
	{
		AJMDoorActor* PendingDoor;
	};
	_Script_JMDoorGameplayIntegration_eventJMPendingDoorChangedSignature_Parms Parms;
	Parms.PendingDoor=PendingDoor;
	JMPendingDoorChangedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMPendingDoorChangedSignature ******************************************

// ********** Begin Class UJMDoorInventoryAgentComponent Function BeginLockedDoorItemSelection *****
struct Z_Construct_UFunction_UJMDoorInventoryAgentComponent_BeginLockedDoorItemSelection_Statics
{
	struct JMDoorInventoryAgentComponent_eventBeginLockedDoorItemSelection_Parms
	{
		AJMDoorActor* Door;
		FJMInteractionContext InteractionContext;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Inventory" },
		{ "ModuleRelativePath", "Public/Components/JMDoorInventoryAgentComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionContext_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function BeginLockedDoorItemSelection constinit property declarations **********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Door;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InteractionContext;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BeginLockedDoorItemSelection constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BeginLockedDoorItemSelection Property Definitions *********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMDoorInventoryAgentComponent_BeginLockedDoorItemSelection_Statics::NewProp_Door = { "Door", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorInventoryAgentComponent_eventBeginLockedDoorItemSelection_Parms, Door), Z_Construct_UClass_AJMDoorActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorInventoryAgentComponent_BeginLockedDoorItemSelection_Statics::NewProp_InteractionContext = { "InteractionContext", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorInventoryAgentComponent_eventBeginLockedDoorItemSelection_Parms, InteractionContext), Z_Construct_UScriptStruct_FJMInteractionContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionContext_MetaData), NewProp_InteractionContext_MetaData) }; // 3486038698
void Z_Construct_UFunction_UJMDoorInventoryAgentComponent_BeginLockedDoorItemSelection_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMDoorInventoryAgentComponent_eventBeginLockedDoorItemSelection_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMDoorInventoryAgentComponent_BeginLockedDoorItemSelection_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMDoorInventoryAgentComponent_eventBeginLockedDoorItemSelection_Parms), &Z_Construct_UFunction_UJMDoorInventoryAgentComponent_BeginLockedDoorItemSelection_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorInventoryAgentComponent_BeginLockedDoorItemSelection_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorInventoryAgentComponent_BeginLockedDoorItemSelection_Statics::NewProp_Door,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorInventoryAgentComponent_BeginLockedDoorItemSelection_Statics::NewProp_InteractionContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorInventoryAgentComponent_BeginLockedDoorItemSelection_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorInventoryAgentComponent_BeginLockedDoorItemSelection_Statics::PropPointers) < 2048);
// ********** End Function BeginLockedDoorItemSelection Property Definitions ***********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorInventoryAgentComponent_BeginLockedDoorItemSelection_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorInventoryAgentComponent, nullptr, "BeginLockedDoorItemSelection", 	Z_Construct_UFunction_UJMDoorInventoryAgentComponent_BeginLockedDoorItemSelection_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorInventoryAgentComponent_BeginLockedDoorItemSelection_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorInventoryAgentComponent_BeginLockedDoorItemSelection_Statics::JMDoorInventoryAgentComponent_eventBeginLockedDoorItemSelection_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorInventoryAgentComponent_BeginLockedDoorItemSelection_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorInventoryAgentComponent_BeginLockedDoorItemSelection_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorInventoryAgentComponent_BeginLockedDoorItemSelection_Statics::JMDoorInventoryAgentComponent_eventBeginLockedDoorItemSelection_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorInventoryAgentComponent_BeginLockedDoorItemSelection()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorInventoryAgentComponent_BeginLockedDoorItemSelection_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorInventoryAgentComponent::execBeginLockedDoorItemSelection)
{
	P_GET_OBJECT(AJMDoorActor,Z_Param_Door);
	P_GET_STRUCT_REF(FJMInteractionContext,Z_Param_Out_InteractionContext);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->BeginLockedDoorItemSelection(Z_Param_Door,Z_Param_Out_InteractionContext);
	P_NATIVE_END;
}
// ********** End Class UJMDoorInventoryAgentComponent Function BeginLockedDoorItemSelection *******

// ********** Begin Class UJMDoorInventoryAgentComponent Function ClearPendingDoor *****************
struct Z_Construct_UFunction_UJMDoorInventoryAgentComponent_ClearPendingDoor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Inventory" },
		{ "ModuleRelativePath", "Public/Components/JMDoorInventoryAgentComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ClearPendingDoor constinit property declarations **********************
// ********** End Function ClearPendingDoor constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorInventoryAgentComponent_ClearPendingDoor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorInventoryAgentComponent, nullptr, "ClearPendingDoor", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorInventoryAgentComponent_ClearPendingDoor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorInventoryAgentComponent_ClearPendingDoor_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UJMDoorInventoryAgentComponent_ClearPendingDoor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorInventoryAgentComponent_ClearPendingDoor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorInventoryAgentComponent::execClearPendingDoor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearPendingDoor();
	P_NATIVE_END;
}
// ********** End Class UJMDoorInventoryAgentComponent Function ClearPendingDoor *******************

// ********** Begin Class UJMDoorInventoryAgentComponent Function GetPendingDoor *******************
struct Z_Construct_UFunction_UJMDoorInventoryAgentComponent_GetPendingDoor_Statics
{
	struct JMDoorInventoryAgentComponent_eventGetPendingDoor_Parms
	{
		AJMDoorActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Inventory" },
		{ "ModuleRelativePath", "Public/Components/JMDoorInventoryAgentComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPendingDoor constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPendingDoor constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPendingDoor Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMDoorInventoryAgentComponent_GetPendingDoor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorInventoryAgentComponent_eventGetPendingDoor_Parms, ReturnValue), Z_Construct_UClass_AJMDoorActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorInventoryAgentComponent_GetPendingDoor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorInventoryAgentComponent_GetPendingDoor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorInventoryAgentComponent_GetPendingDoor_Statics::PropPointers) < 2048);
// ********** End Function GetPendingDoor Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorInventoryAgentComponent_GetPendingDoor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorInventoryAgentComponent, nullptr, "GetPendingDoor", 	Z_Construct_UFunction_UJMDoorInventoryAgentComponent_GetPendingDoor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorInventoryAgentComponent_GetPendingDoor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorInventoryAgentComponent_GetPendingDoor_Statics::JMDoorInventoryAgentComponent_eventGetPendingDoor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorInventoryAgentComponent_GetPendingDoor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorInventoryAgentComponent_GetPendingDoor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorInventoryAgentComponent_GetPendingDoor_Statics::JMDoorInventoryAgentComponent_eventGetPendingDoor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorInventoryAgentComponent_GetPendingDoor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorInventoryAgentComponent_GetPendingDoor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorInventoryAgentComponent::execGetPendingDoor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AJMDoorActor**)Z_Param__Result=P_THIS->GetPendingDoor();
	P_NATIVE_END;
}
// ********** End Class UJMDoorInventoryAgentComponent Function GetPendingDoor *********************

// ********** Begin Class UJMDoorInventoryAgentComponent Function SetPendingDoorForItemUse *********
struct Z_Construct_UFunction_UJMDoorInventoryAgentComponent_SetPendingDoorForItemUse_Statics
{
	struct JMDoorInventoryAgentComponent_eventSetPendingDoorForItemUse_Parms
	{
		AJMDoorActor* Door;
		FJMInteractionContext InteractionContext;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Stores a locked-door target without opening UI, for custom UI and automated flows. */" },
#endif
		{ "ModuleRelativePath", "Public/Components/JMDoorInventoryAgentComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stores a locked-door target without opening UI, for custom UI and automated flows." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionContext_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetPendingDoorForItemUse constinit property declarations **************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Door;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InteractionContext;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPendingDoorForItemUse constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPendingDoorForItemUse Property Definitions *************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMDoorInventoryAgentComponent_SetPendingDoorForItemUse_Statics::NewProp_Door = { "Door", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorInventoryAgentComponent_eventSetPendingDoorForItemUse_Parms, Door), Z_Construct_UClass_AJMDoorActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorInventoryAgentComponent_SetPendingDoorForItemUse_Statics::NewProp_InteractionContext = { "InteractionContext", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorInventoryAgentComponent_eventSetPendingDoorForItemUse_Parms, InteractionContext), Z_Construct_UScriptStruct_FJMInteractionContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionContext_MetaData), NewProp_InteractionContext_MetaData) }; // 3486038698
void Z_Construct_UFunction_UJMDoorInventoryAgentComponent_SetPendingDoorForItemUse_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMDoorInventoryAgentComponent_eventSetPendingDoorForItemUse_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMDoorInventoryAgentComponent_SetPendingDoorForItemUse_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMDoorInventoryAgentComponent_eventSetPendingDoorForItemUse_Parms), &Z_Construct_UFunction_UJMDoorInventoryAgentComponent_SetPendingDoorForItemUse_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorInventoryAgentComponent_SetPendingDoorForItemUse_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorInventoryAgentComponent_SetPendingDoorForItemUse_Statics::NewProp_Door,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorInventoryAgentComponent_SetPendingDoorForItemUse_Statics::NewProp_InteractionContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorInventoryAgentComponent_SetPendingDoorForItemUse_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorInventoryAgentComponent_SetPendingDoorForItemUse_Statics::PropPointers) < 2048);
// ********** End Function SetPendingDoorForItemUse Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorInventoryAgentComponent_SetPendingDoorForItemUse_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorInventoryAgentComponent, nullptr, "SetPendingDoorForItemUse", 	Z_Construct_UFunction_UJMDoorInventoryAgentComponent_SetPendingDoorForItemUse_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorInventoryAgentComponent_SetPendingDoorForItemUse_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorInventoryAgentComponent_SetPendingDoorForItemUse_Statics::JMDoorInventoryAgentComponent_eventSetPendingDoorForItemUse_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorInventoryAgentComponent_SetPendingDoorForItemUse_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorInventoryAgentComponent_SetPendingDoorForItemUse_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorInventoryAgentComponent_SetPendingDoorForItemUse_Statics::JMDoorInventoryAgentComponent_eventSetPendingDoorForItemUse_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorInventoryAgentComponent_SetPendingDoorForItemUse()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorInventoryAgentComponent_SetPendingDoorForItemUse_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorInventoryAgentComponent::execSetPendingDoorForItemUse)
{
	P_GET_OBJECT(AJMDoorActor,Z_Param_Door);
	P_GET_STRUCT_REF(FJMInteractionContext,Z_Param_Out_InteractionContext);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SetPendingDoorForItemUse(Z_Param_Door,Z_Param_Out_InteractionContext);
	P_NATIVE_END;
}
// ********** End Class UJMDoorInventoryAgentComponent Function SetPendingDoorForItemUse ***********

// ********** Begin Class UJMDoorInventoryAgentComponent Function UseItemOnPendingDoor *************
struct Z_Construct_UFunction_UJMDoorInventoryAgentComponent_UseItemOnPendingDoor_Statics
{
	struct JMDoorInventoryAgentComponent_eventUseItemOnPendingDoor_Parms
	{
		UInventoryItemDefinition* ItemDefinition;
		AActor* User;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Explicit Blueprint path: connect any inventory item's Use event to this function. */" },
#endif
		{ "CPP_Default_User", "None" },
		{ "DisplayName", "Use Item On Pending Door" },
		{ "ModuleRelativePath", "Public/Components/JMDoorInventoryAgentComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Explicit Blueprint path: connect any inventory item's Use event to this function." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function UseItemOnPendingDoor constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemDefinition;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_User;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UseItemOnPendingDoor constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UseItemOnPendingDoor Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMDoorInventoryAgentComponent_UseItemOnPendingDoor_Statics::NewProp_ItemDefinition = { "ItemDefinition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorInventoryAgentComponent_eventUseItemOnPendingDoor_Parms, ItemDefinition), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMDoorInventoryAgentComponent_UseItemOnPendingDoor_Statics::NewProp_User = { "User", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorInventoryAgentComponent_eventUseItemOnPendingDoor_Parms, User), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UJMDoorInventoryAgentComponent_UseItemOnPendingDoor_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMDoorInventoryAgentComponent_eventUseItemOnPendingDoor_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMDoorInventoryAgentComponent_UseItemOnPendingDoor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMDoorInventoryAgentComponent_eventUseItemOnPendingDoor_Parms), &Z_Construct_UFunction_UJMDoorInventoryAgentComponent_UseItemOnPendingDoor_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorInventoryAgentComponent_UseItemOnPendingDoor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorInventoryAgentComponent_UseItemOnPendingDoor_Statics::NewProp_ItemDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorInventoryAgentComponent_UseItemOnPendingDoor_Statics::NewProp_User,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorInventoryAgentComponent_UseItemOnPendingDoor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorInventoryAgentComponent_UseItemOnPendingDoor_Statics::PropPointers) < 2048);
// ********** End Function UseItemOnPendingDoor Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorInventoryAgentComponent_UseItemOnPendingDoor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorInventoryAgentComponent, nullptr, "UseItemOnPendingDoor", 	Z_Construct_UFunction_UJMDoorInventoryAgentComponent_UseItemOnPendingDoor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorInventoryAgentComponent_UseItemOnPendingDoor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorInventoryAgentComponent_UseItemOnPendingDoor_Statics::JMDoorInventoryAgentComponent_eventUseItemOnPendingDoor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorInventoryAgentComponent_UseItemOnPendingDoor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorInventoryAgentComponent_UseItemOnPendingDoor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorInventoryAgentComponent_UseItemOnPendingDoor_Statics::JMDoorInventoryAgentComponent_eventUseItemOnPendingDoor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorInventoryAgentComponent_UseItemOnPendingDoor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorInventoryAgentComponent_UseItemOnPendingDoor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorInventoryAgentComponent::execUseItemOnPendingDoor)
{
	P_GET_OBJECT(UInventoryItemDefinition,Z_Param_ItemDefinition);
	P_GET_OBJECT(AActor,Z_Param_User);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->UseItemOnPendingDoor(Z_Param_ItemDefinition,Z_Param_User);
	P_NATIVE_END;
}
// ********** End Class UJMDoorInventoryAgentComponent Function UseItemOnPendingDoor ***************

// ********** Begin Class UJMDoorInventoryAgentComponent *******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMDoorInventoryAgentComponent;
UClass* UJMDoorInventoryAgentComponent::GetPrivateStaticClass()
{
	using TClass = UJMDoorInventoryAgentComponent;
	if (!Z_Registration_Info_UClass_UJMDoorInventoryAgentComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMDoorInventoryAgentComponent"),
			Z_Registration_Info_UClass_UJMDoorInventoryAgentComponent.InnerSingleton,
			StaticRegisterNativesUJMDoorInventoryAgentComponent,
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
	return Z_Registration_Info_UClass_UJMDoorInventoryAgentComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMDoorInventoryAgentComponent_NoRegister()
{
	return UJMDoorInventoryAgentComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMDoorInventoryAgentComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JMGameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Add to any player Pawn/Character to route a key's Use button to a locked door. */" },
#endif
		{ "IncludePath", "Components/JMDoorInventoryAgentComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Components/JMDoorInventoryAgentComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Add to any player Pawn/Character to route a key's Use button to a locked door." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnPendingDoorChanged_MetaData[] = {
		{ "Category", "JM Door|Inventory" },
		{ "ModuleRelativePath", "Public/Components/JMDoorInventoryAgentComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMDoorInventoryAgentComponent constinit property declarations ***********
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPendingDoorChanged;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMDoorInventoryAgentComponent constinit property declarations *************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("BeginLockedDoorItemSelection"), .Pointer = &UJMDoorInventoryAgentComponent::execBeginLockedDoorItemSelection },
		{ .NameUTF8 = UTF8TEXT("ClearPendingDoor"), .Pointer = &UJMDoorInventoryAgentComponent::execClearPendingDoor },
		{ .NameUTF8 = UTF8TEXT("GetPendingDoor"), .Pointer = &UJMDoorInventoryAgentComponent::execGetPendingDoor },
		{ .NameUTF8 = UTF8TEXT("SetPendingDoorForItemUse"), .Pointer = &UJMDoorInventoryAgentComponent::execSetPendingDoorForItemUse },
		{ .NameUTF8 = UTF8TEXT("UseItemOnPendingDoor"), .Pointer = &UJMDoorInventoryAgentComponent::execUseItemOnPendingDoor },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMDoorInventoryAgentComponent_BeginLockedDoorItemSelection, "BeginLockedDoorItemSelection" }, // 1941719592
		{ &Z_Construct_UFunction_UJMDoorInventoryAgentComponent_ClearPendingDoor, "ClearPendingDoor" }, // 3371193923
		{ &Z_Construct_UFunction_UJMDoorInventoryAgentComponent_GetPendingDoor, "GetPendingDoor" }, // 2167763028
		{ &Z_Construct_UFunction_UJMDoorInventoryAgentComponent_SetPendingDoorForItemUse, "SetPendingDoorForItemUse" }, // 1808771822
		{ &Z_Construct_UFunction_UJMDoorInventoryAgentComponent_UseItemOnPendingDoor, "UseItemOnPendingDoor" }, // 4278894719
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMDoorInventoryAgentComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMDoorInventoryAgentComponent_Statics

// ********** Begin Class UJMDoorInventoryAgentComponent Property Definitions **********************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMDoorInventoryAgentComponent_Statics::NewProp_OnPendingDoorChanged = { "OnPendingDoorChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorInventoryAgentComponent, OnPendingDoorChanged), Z_Construct_UDelegateFunction_JMDoorGameplayIntegration_JMPendingDoorChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnPendingDoorChanged_MetaData), NewProp_OnPendingDoorChanged_MetaData) }; // 3135012878
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMDoorInventoryAgentComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorInventoryAgentComponent_Statics::NewProp_OnPendingDoorChanged,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorInventoryAgentComponent_Statics::PropPointers) < 2048);
// ********** End Class UJMDoorInventoryAgentComponent Property Definitions ************************
UObject* (*const Z_Construct_UClass_UJMDoorInventoryAgentComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorGameplayIntegration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorInventoryAgentComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UJMDoorInventoryAgentComponent_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UInventoryItemUseReceiverInterface_NoRegister, (int32)VTABLE_OFFSET(UJMDoorInventoryAgentComponent, IInventoryItemUseReceiverInterface), false },  // 3734366626
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMDoorInventoryAgentComponent_Statics::ClassParams = {
	&UJMDoorInventoryAgentComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMDoorInventoryAgentComponent_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorInventoryAgentComponent_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorInventoryAgentComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMDoorInventoryAgentComponent_Statics::Class_MetaDataParams)
};
void UJMDoorInventoryAgentComponent::StaticRegisterNativesUJMDoorInventoryAgentComponent()
{
	UClass* Class = UJMDoorInventoryAgentComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMDoorInventoryAgentComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMDoorInventoryAgentComponent()
{
	if (!Z_Registration_Info_UClass_UJMDoorInventoryAgentComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMDoorInventoryAgentComponent.OuterSingleton, Z_Construct_UClass_UJMDoorInventoryAgentComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMDoorInventoryAgentComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMDoorInventoryAgentComponent);
UJMDoorInventoryAgentComponent::~UJMDoorInventoryAgentComponent() {}
// ********** End Class UJMDoorInventoryAgentComponent *********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Components_JMDoorInventoryAgentComponent_h__Script_JMDoorGameplayIntegration_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMDoorInventoryAgentComponent, UJMDoorInventoryAgentComponent::StaticClass, TEXT("UJMDoorInventoryAgentComponent"), &Z_Registration_Info_UClass_UJMDoorInventoryAgentComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMDoorInventoryAgentComponent), 3311787982U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Components_JMDoorInventoryAgentComponent_h__Script_JMDoorGameplayIntegration_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Components_JMDoorInventoryAgentComponent_h__Script_JMDoorGameplayIntegration_4182788304{
	TEXT("/Script/JMDoorGameplayIntegration"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Components_JMDoorInventoryAgentComponent_h__Script_JMDoorGameplayIntegration_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Components_JMDoorInventoryAgentComponent_h__Script_JMDoorGameplayIntegration_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
