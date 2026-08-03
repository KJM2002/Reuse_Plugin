// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interfaces/InventoryItemInspectorBridge.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeInventoryItemInspectorBridge() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemDefinition_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemInspectorBridge();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemInspectorBridge_NoRegister();
INVENTORYSYSTEM_API UFunction* Z_Construct_UDelegateFunction_InventorySystem_InventoryInspectorClosedSignature__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_InventorySystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FInventoryInspectorClosedSignature ************************************
struct Z_Construct_UDelegateFunction_InventorySystem_InventoryInspectorClosedSignature__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Interfaces/InventoryItemInspectorBridge.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FInventoryInspectorClosedSignature constinit property declarations ****
// ********** End Delegate FInventoryInspectorClosedSignature constinit property declarations ******
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_InventorySystem_InventoryInspectorClosedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_InventorySystem, nullptr, "InventoryInspectorClosedSignature__DelegateSignature", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_InventorySystem_InventoryInspectorClosedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_InventorySystem_InventoryInspectorClosedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_InventorySystem_InventoryInspectorClosedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_InventorySystem_InventoryInspectorClosedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FInventoryInspectorClosedSignature_DelegateWrapper(const FMulticastScriptDelegate& InventoryInspectorClosedSignature)
{
	InventoryInspectorClosedSignature.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FInventoryInspectorClosedSignature **************************************

// ********** Begin Class UInventoryItemInspectorBridge Function CloseInspector ********************
static FName NAME_UInventoryItemInspectorBridge_CloseInspector = FName(TEXT("CloseInspector"));
void UInventoryItemInspectorBridge::CloseInspector()
{
	UFunction* Func = FindFunctionChecked(NAME_UInventoryItemInspectorBridge_CloseInspector);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		CloseInspector_Implementation();
	}
}
struct Z_Construct_UFunction_UInventoryItemInspectorBridge_CloseInspector_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Inspector" },
		{ "ModuleRelativePath", "Public/Interfaces/InventoryItemInspectorBridge.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CloseInspector constinit property declarations ************************
// ********** End Function CloseInspector constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryItemInspectorBridge_CloseInspector_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryItemInspectorBridge, nullptr, "CloseInspector", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemInspectorBridge_CloseInspector_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryItemInspectorBridge_CloseInspector_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventoryItemInspectorBridge_CloseInspector()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryItemInspectorBridge_CloseInspector_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryItemInspectorBridge::execCloseInspector)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CloseInspector_Implementation();
	P_NATIVE_END;
}
// ********** End Class UInventoryItemInspectorBridge Function CloseInspector **********************

// ********** Begin Class UInventoryItemInspectorBridge Function IsInspectorOpen *******************
struct InventoryItemInspectorBridge_eventIsInspectorOpen_Parms
{
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	InventoryItemInspectorBridge_eventIsInspectorOpen_Parms()
		: ReturnValue(false)
	{
	}
};
static FName NAME_UInventoryItemInspectorBridge_IsInspectorOpen = FName(TEXT("IsInspectorOpen"));
bool UInventoryItemInspectorBridge::IsInspectorOpen() const
{
	UFunction* Func = FindFunctionChecked(NAME_UInventoryItemInspectorBridge_IsInspectorOpen);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		InventoryItemInspectorBridge_eventIsInspectorOpen_Parms Parms;
		const_cast<UInventoryItemInspectorBridge*>(this)->ProcessEvent(Func,&Parms);
		return !!Parms.ReturnValue;
	}
	else
	{
		return const_cast<UInventoryItemInspectorBridge*>(this)->IsInspectorOpen_Implementation();
	}
}
struct Z_Construct_UFunction_UInventoryItemInspectorBridge_IsInspectorOpen_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Inspector" },
		{ "ModuleRelativePath", "Public/Interfaces/InventoryItemInspectorBridge.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsInspectorOpen constinit property declarations ***********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsInspectorOpen constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsInspectorOpen Property Definitions **********************************
void Z_Construct_UFunction_UInventoryItemInspectorBridge_IsInspectorOpen_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventoryItemInspectorBridge_eventIsInspectorOpen_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryItemInspectorBridge_IsInspectorOpen_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventoryItemInspectorBridge_eventIsInspectorOpen_Parms), &Z_Construct_UFunction_UInventoryItemInspectorBridge_IsInspectorOpen_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryItemInspectorBridge_IsInspectorOpen_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemInspectorBridge_IsInspectorOpen_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemInspectorBridge_IsInspectorOpen_Statics::PropPointers) < 2048);
// ********** End Function IsInspectorOpen Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryItemInspectorBridge_IsInspectorOpen_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryItemInspectorBridge, nullptr, "IsInspectorOpen", 	Z_Construct_UFunction_UInventoryItemInspectorBridge_IsInspectorOpen_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemInspectorBridge_IsInspectorOpen_Statics::PropPointers), 
sizeof(InventoryItemInspectorBridge_eventIsInspectorOpen_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemInspectorBridge_IsInspectorOpen_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryItemInspectorBridge_IsInspectorOpen_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InventoryItemInspectorBridge_eventIsInspectorOpen_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryItemInspectorBridge_IsInspectorOpen()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryItemInspectorBridge_IsInspectorOpen_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryItemInspectorBridge::execIsInspectorOpen)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsInspectorOpen_Implementation();
	P_NATIVE_END;
}
// ********** End Class UInventoryItemInspectorBridge Function IsInspectorOpen *********************

// ********** Begin Class UInventoryItemInspectorBridge Function NotifyInspectorClosed *************
struct Z_Construct_UFunction_UInventoryItemInspectorBridge_NotifyInspectorClosed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Inspector" },
		{ "ModuleRelativePath", "Public/Interfaces/InventoryItemInspectorBridge.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function NotifyInspectorClosed constinit property declarations *****************
// ********** End Function NotifyInspectorClosed constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryItemInspectorBridge_NotifyInspectorClosed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryItemInspectorBridge, nullptr, "NotifyInspectorClosed", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemInspectorBridge_NotifyInspectorClosed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryItemInspectorBridge_NotifyInspectorClosed_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UInventoryItemInspectorBridge_NotifyInspectorClosed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryItemInspectorBridge_NotifyInspectorClosed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryItemInspectorBridge::execNotifyInspectorClosed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->NotifyInspectorClosed();
	P_NATIVE_END;
}
// ********** End Class UInventoryItemInspectorBridge Function NotifyInspectorClosed ***************

// ********** Begin Class UInventoryItemInspectorBridge Function OpenInspector *********************
struct InventoryItemInspectorBridge_eventOpenInspector_Parms
{
	APlayerController* PlayerController;
	const UInventoryItemDefinition* ItemDefinition;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	InventoryItemInspectorBridge_eventOpenInspector_Parms()
		: ReturnValue(false)
	{
	}
};
static FName NAME_UInventoryItemInspectorBridge_OpenInspector = FName(TEXT("OpenInspector"));
bool UInventoryItemInspectorBridge::OpenInspector(APlayerController* PlayerController, const UInventoryItemDefinition* ItemDefinition)
{
	UFunction* Func = FindFunctionChecked(NAME_UInventoryItemInspectorBridge_OpenInspector);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		InventoryItemInspectorBridge_eventOpenInspector_Parms Parms;
		Parms.PlayerController=PlayerController;
		Parms.ItemDefinition=ItemDefinition;
	ProcessEvent(Func,&Parms);
		return !!Parms.ReturnValue;
	}
	else
	{
		return OpenInspector_Implementation(PlayerController, ItemDefinition);
	}
}
struct Z_Construct_UFunction_UInventoryItemInspectorBridge_OpenInspector_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Inspector" },
		{ "ModuleRelativePath", "Public/Interfaces/InventoryItemInspectorBridge.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemDefinition_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OpenInspector constinit property declarations *************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemDefinition;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OpenInspector constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OpenInspector Property Definitions ************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryItemInspectorBridge_OpenInspector_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemInspectorBridge_eventOpenInspector_Parms, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryItemInspectorBridge_OpenInspector_Statics::NewProp_ItemDefinition = { "ItemDefinition", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemInspectorBridge_eventOpenInspector_Parms, ItemDefinition), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemDefinition_MetaData), NewProp_ItemDefinition_MetaData) };
void Z_Construct_UFunction_UInventoryItemInspectorBridge_OpenInspector_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventoryItemInspectorBridge_eventOpenInspector_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryItemInspectorBridge_OpenInspector_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventoryItemInspectorBridge_eventOpenInspector_Parms), &Z_Construct_UFunction_UInventoryItemInspectorBridge_OpenInspector_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryItemInspectorBridge_OpenInspector_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemInspectorBridge_OpenInspector_Statics::NewProp_PlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemInspectorBridge_OpenInspector_Statics::NewProp_ItemDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemInspectorBridge_OpenInspector_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemInspectorBridge_OpenInspector_Statics::PropPointers) < 2048);
// ********** End Function OpenInspector Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryItemInspectorBridge_OpenInspector_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryItemInspectorBridge, nullptr, "OpenInspector", 	Z_Construct_UFunction_UInventoryItemInspectorBridge_OpenInspector_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemInspectorBridge_OpenInspector_Statics::PropPointers), 
sizeof(InventoryItemInspectorBridge_eventOpenInspector_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemInspectorBridge_OpenInspector_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryItemInspectorBridge_OpenInspector_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InventoryItemInspectorBridge_eventOpenInspector_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryItemInspectorBridge_OpenInspector()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryItemInspectorBridge_OpenInspector_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryItemInspectorBridge::execOpenInspector)
{
	P_GET_OBJECT(APlayerController,Z_Param_PlayerController);
	P_GET_OBJECT(UInventoryItemDefinition,Z_Param_ItemDefinition);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->OpenInspector_Implementation(Z_Param_PlayerController,Z_Param_ItemDefinition);
	P_NATIVE_END;
}
// ********** End Class UInventoryItemInspectorBridge Function OpenInspector ***********************

// ********** Begin Class UInventoryItemInspectorBridge ********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UInventoryItemInspectorBridge;
UClass* UInventoryItemInspectorBridge::GetPrivateStaticClass()
{
	using TClass = UInventoryItemInspectorBridge;
	if (!Z_Registration_Info_UClass_UInventoryItemInspectorBridge.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("InventoryItemInspectorBridge"),
			Z_Registration_Info_UClass_UInventoryItemInspectorBridge.InnerSingleton,
			StaticRegisterNativesUInventoryItemInspectorBridge,
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
	return Z_Registration_Info_UClass_UInventoryItemInspectorBridge.InnerSingleton;
}
UClass* Z_Construct_UClass_UInventoryItemInspectorBridge_NoRegister()
{
	return UInventoryItemInspectorBridge::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UInventoryItemInspectorBridge_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Interfaces/InventoryItemInspectorBridge.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Interfaces/InventoryItemInspectorBridge.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnInspectorClosed_MetaData[] = {
		{ "Category", "Inventory|Inspector" },
		{ "ModuleRelativePath", "Public/Interfaces/InventoryItemInspectorBridge.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UInventoryItemInspectorBridge constinit property declarations ************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInspectorClosed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UInventoryItemInspectorBridge constinit property declarations **************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CloseInspector"), .Pointer = &UInventoryItemInspectorBridge::execCloseInspector },
		{ .NameUTF8 = UTF8TEXT("IsInspectorOpen"), .Pointer = &UInventoryItemInspectorBridge::execIsInspectorOpen },
		{ .NameUTF8 = UTF8TEXT("NotifyInspectorClosed"), .Pointer = &UInventoryItemInspectorBridge::execNotifyInspectorClosed },
		{ .NameUTF8 = UTF8TEXT("OpenInspector"), .Pointer = &UInventoryItemInspectorBridge::execOpenInspector },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventoryItemInspectorBridge_CloseInspector, "CloseInspector" }, // 1126990379
		{ &Z_Construct_UFunction_UInventoryItemInspectorBridge_IsInspectorOpen, "IsInspectorOpen" }, // 1717483792
		{ &Z_Construct_UFunction_UInventoryItemInspectorBridge_NotifyInspectorClosed, "NotifyInspectorClosed" }, // 3030402764
		{ &Z_Construct_UFunction_UInventoryItemInspectorBridge_OpenInspector, "OpenInspector" }, // 772401535
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryItemInspectorBridge>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UInventoryItemInspectorBridge_Statics

// ********** Begin Class UInventoryItemInspectorBridge Property Definitions ***********************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UInventoryItemInspectorBridge_Statics::NewProp_OnInspectorClosed = { "OnInspectorClosed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemInspectorBridge, OnInspectorClosed), Z_Construct_UDelegateFunction_InventorySystem_InventoryInspectorClosedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnInspectorClosed_MetaData), NewProp_OnInspectorClosed_MetaData) }; // 704108985
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventoryItemInspectorBridge_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemInspectorBridge_Statics::NewProp_OnInspectorClosed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemInspectorBridge_Statics::PropPointers) < 2048);
// ********** End Class UInventoryItemInspectorBridge Property Definitions *************************
UObject* (*const Z_Construct_UClass_UInventoryItemInspectorBridge_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_InventorySystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemInspectorBridge_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventoryItemInspectorBridge_Statics::ClassParams = {
	&UInventoryItemInspectorBridge::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UInventoryItemInspectorBridge_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemInspectorBridge_Statics::PropPointers),
	0,
	0x00B010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemInspectorBridge_Statics::Class_MetaDataParams), Z_Construct_UClass_UInventoryItemInspectorBridge_Statics::Class_MetaDataParams)
};
void UInventoryItemInspectorBridge::StaticRegisterNativesUInventoryItemInspectorBridge()
{
	UClass* Class = UInventoryItemInspectorBridge::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UInventoryItemInspectorBridge_Statics::Funcs));
}
UClass* Z_Construct_UClass_UInventoryItemInspectorBridge()
{
	if (!Z_Registration_Info_UClass_UInventoryItemInspectorBridge.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventoryItemInspectorBridge.OuterSingleton, Z_Construct_UClass_UInventoryItemInspectorBridge_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInventoryItemInspectorBridge.OuterSingleton;
}
UInventoryItemInspectorBridge::UInventoryItemInspectorBridge(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UInventoryItemInspectorBridge);
UInventoryItemInspectorBridge::~UInventoryItemInspectorBridge() {}
// ********** End Class UInventoryItemInspectorBridge **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemInspectorBridge_h__Script_InventorySystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInventoryItemInspectorBridge, UInventoryItemInspectorBridge::StaticClass, TEXT("UInventoryItemInspectorBridge"), &Z_Registration_Info_UClass_UInventoryItemInspectorBridge, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventoryItemInspectorBridge), 2763879048U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemInspectorBridge_h__Script_InventorySystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemInspectorBridge_h__Script_InventorySystem_303309631{
	TEXT("/Script/InventorySystem"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemInspectorBridge_h__Script_InventorySystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemInspectorBridge_h__Script_InventorySystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
