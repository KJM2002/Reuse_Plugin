// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interfaces/InventoryItemUseReceiverInterface.h"
#include "InventoryTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeInventoryItemUseReceiverInterface() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryComponent_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemUseReceiverInterface();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemUseReceiverInterface_NoRegister();
INVENTORYSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FInventorySlot();
UPackage* Z_Construct_UPackage__Script_InventorySystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface UInventoryItemUseReceiverInterface Function CanReceiveInventoryItemUse 
struct InventoryItemUseReceiverInterface_eventCanReceiveInventoryItemUse_Parms
{
	AActor* User;
	UInventoryComponent* Inventory;
	FInventorySlot Slot;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	InventoryItemUseReceiverInterface_eventCanReceiveInventoryItemUse_Parms()
		: ReturnValue(false)
	{
	}
};
bool IInventoryItemUseReceiverInterface::CanReceiveInventoryItemUse(AActor* User, UInventoryComponent* Inventory, FInventorySlot const& Slot) const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_CanReceiveInventoryItemUse instead.");
	InventoryItemUseReceiverInterface_eventCanReceiveInventoryItemUse_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UInventoryItemUseReceiverInterface_CanReceiveInventoryItemUse = FName(TEXT("CanReceiveInventoryItemUse"));
bool IInventoryItemUseReceiverInterface::Execute_CanReceiveInventoryItemUse(const UObject* O, AActor* User, UInventoryComponent* Inventory, FInventorySlot const& Slot)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UInventoryItemUseReceiverInterface::StaticClass()));
	InventoryItemUseReceiverInterface_eventCanReceiveInventoryItemUse_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UInventoryItemUseReceiverInterface_CanReceiveInventoryItemUse);
	if (Func)
	{
		Parms.User=std::move(User);
		Parms.Inventory=std::move(Inventory);
		Parms.Slot=std::move(Slot);
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IInventoryItemUseReceiverInterface*)(O->GetNativeInterfaceAddress(UInventoryItemUseReceiverInterface::StaticClass())))
	{
		Parms.ReturnValue = I->CanReceiveInventoryItemUse_Implementation(User,Inventory,Slot);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UInventoryItemUseReceiverInterface_CanReceiveInventoryItemUse_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Use Target" },
		{ "ModuleRelativePath", "Public/Interfaces/InventoryItemUseReceiverInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Inventory_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Slot_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CanReceiveInventoryItemUse constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_User;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Inventory;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Slot;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CanReceiveInventoryItemUse constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CanReceiveInventoryItemUse Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryItemUseReceiverInterface_CanReceiveInventoryItemUse_Statics::NewProp_User = { "User", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemUseReceiverInterface_eventCanReceiveInventoryItemUse_Parms, User), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryItemUseReceiverInterface_CanReceiveInventoryItemUse_Statics::NewProp_Inventory = { "Inventory", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemUseReceiverInterface_eventCanReceiveInventoryItemUse_Parms, Inventory), Z_Construct_UClass_UInventoryComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Inventory_MetaData), NewProp_Inventory_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryItemUseReceiverInterface_CanReceiveInventoryItemUse_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemUseReceiverInterface_eventCanReceiveInventoryItemUse_Parms, Slot), Z_Construct_UScriptStruct_FInventorySlot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Slot_MetaData), NewProp_Slot_MetaData) }; // 3353780059
void Z_Construct_UFunction_UInventoryItemUseReceiverInterface_CanReceiveInventoryItemUse_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventoryItemUseReceiverInterface_eventCanReceiveInventoryItemUse_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryItemUseReceiverInterface_CanReceiveInventoryItemUse_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventoryItemUseReceiverInterface_eventCanReceiveInventoryItemUse_Parms), &Z_Construct_UFunction_UInventoryItemUseReceiverInterface_CanReceiveInventoryItemUse_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryItemUseReceiverInterface_CanReceiveInventoryItemUse_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemUseReceiverInterface_CanReceiveInventoryItemUse_Statics::NewProp_User,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemUseReceiverInterface_CanReceiveInventoryItemUse_Statics::NewProp_Inventory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemUseReceiverInterface_CanReceiveInventoryItemUse_Statics::NewProp_Slot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemUseReceiverInterface_CanReceiveInventoryItemUse_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemUseReceiverInterface_CanReceiveInventoryItemUse_Statics::PropPointers) < 2048);
// ********** End Function CanReceiveInventoryItemUse Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryItemUseReceiverInterface_CanReceiveInventoryItemUse_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryItemUseReceiverInterface, nullptr, "CanReceiveInventoryItemUse", 	Z_Construct_UFunction_UInventoryItemUseReceiverInterface_CanReceiveInventoryItemUse_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemUseReceiverInterface_CanReceiveInventoryItemUse_Statics::PropPointers), 
sizeof(InventoryItemUseReceiverInterface_eventCanReceiveInventoryItemUse_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemUseReceiverInterface_CanReceiveInventoryItemUse_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryItemUseReceiverInterface_CanReceiveInventoryItemUse_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InventoryItemUseReceiverInterface_eventCanReceiveInventoryItemUse_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryItemUseReceiverInterface_CanReceiveInventoryItemUse()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryItemUseReceiverInterface_CanReceiveInventoryItemUse_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IInventoryItemUseReceiverInterface::execCanReceiveInventoryItemUse)
{
	P_GET_OBJECT(AActor,Z_Param_User);
	P_GET_OBJECT(UInventoryComponent,Z_Param_Inventory);
	P_GET_STRUCT_REF(FInventorySlot,Z_Param_Out_Slot);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanReceiveInventoryItemUse_Implementation(Z_Param_User,Z_Param_Inventory,Z_Param_Out_Slot);
	P_NATIVE_END;
}
// ********** End Interface UInventoryItemUseReceiverInterface Function CanReceiveInventoryItemUse *

// ********** Begin Interface UInventoryItemUseReceiverInterface Function ReceiveInventoryItemUse **
struct InventoryItemUseReceiverInterface_eventReceiveInventoryItemUse_Parms
{
	AActor* User;
	UInventoryComponent* Inventory;
	FInventorySlot Slot;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	InventoryItemUseReceiverInterface_eventReceiveInventoryItemUse_Parms()
		: ReturnValue(false)
	{
	}
};
bool IInventoryItemUseReceiverInterface::ReceiveInventoryItemUse(AActor* User, UInventoryComponent* Inventory, FInventorySlot const& Slot)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_ReceiveInventoryItemUse instead.");
	InventoryItemUseReceiverInterface_eventReceiveInventoryItemUse_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UInventoryItemUseReceiverInterface_ReceiveInventoryItemUse = FName(TEXT("ReceiveInventoryItemUse"));
bool IInventoryItemUseReceiverInterface::Execute_ReceiveInventoryItemUse(UObject* O, AActor* User, UInventoryComponent* Inventory, FInventorySlot const& Slot)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UInventoryItemUseReceiverInterface::StaticClass()));
	InventoryItemUseReceiverInterface_eventReceiveInventoryItemUse_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UInventoryItemUseReceiverInterface_ReceiveInventoryItemUse);
	if (Func)
	{
		Parms.User=std::move(User);
		Parms.Inventory=std::move(Inventory);
		Parms.Slot=std::move(Slot);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IInventoryItemUseReceiverInterface*)(O->GetNativeInterfaceAddress(UInventoryItemUseReceiverInterface::StaticClass())))
	{
		Parms.ReturnValue = I->ReceiveInventoryItemUse_Implementation(User,Inventory,Slot);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UInventoryItemUseReceiverInterface_ReceiveInventoryItemUse_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Use Target" },
		{ "ModuleRelativePath", "Public/Interfaces/InventoryItemUseReceiverInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Inventory_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Slot_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ReceiveInventoryItemUse constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_User;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Inventory;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Slot;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ReceiveInventoryItemUse constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ReceiveInventoryItemUse Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryItemUseReceiverInterface_ReceiveInventoryItemUse_Statics::NewProp_User = { "User", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemUseReceiverInterface_eventReceiveInventoryItemUse_Parms, User), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryItemUseReceiverInterface_ReceiveInventoryItemUse_Statics::NewProp_Inventory = { "Inventory", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemUseReceiverInterface_eventReceiveInventoryItemUse_Parms, Inventory), Z_Construct_UClass_UInventoryComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Inventory_MetaData), NewProp_Inventory_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryItemUseReceiverInterface_ReceiveInventoryItemUse_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemUseReceiverInterface_eventReceiveInventoryItemUse_Parms, Slot), Z_Construct_UScriptStruct_FInventorySlot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Slot_MetaData), NewProp_Slot_MetaData) }; // 3353780059
void Z_Construct_UFunction_UInventoryItemUseReceiverInterface_ReceiveInventoryItemUse_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventoryItemUseReceiverInterface_eventReceiveInventoryItemUse_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryItemUseReceiverInterface_ReceiveInventoryItemUse_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventoryItemUseReceiverInterface_eventReceiveInventoryItemUse_Parms), &Z_Construct_UFunction_UInventoryItemUseReceiverInterface_ReceiveInventoryItemUse_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryItemUseReceiverInterface_ReceiveInventoryItemUse_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemUseReceiverInterface_ReceiveInventoryItemUse_Statics::NewProp_User,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemUseReceiverInterface_ReceiveInventoryItemUse_Statics::NewProp_Inventory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemUseReceiverInterface_ReceiveInventoryItemUse_Statics::NewProp_Slot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemUseReceiverInterface_ReceiveInventoryItemUse_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemUseReceiverInterface_ReceiveInventoryItemUse_Statics::PropPointers) < 2048);
// ********** End Function ReceiveInventoryItemUse Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryItemUseReceiverInterface_ReceiveInventoryItemUse_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryItemUseReceiverInterface, nullptr, "ReceiveInventoryItemUse", 	Z_Construct_UFunction_UInventoryItemUseReceiverInterface_ReceiveInventoryItemUse_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemUseReceiverInterface_ReceiveInventoryItemUse_Statics::PropPointers), 
sizeof(InventoryItemUseReceiverInterface_eventReceiveInventoryItemUse_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemUseReceiverInterface_ReceiveInventoryItemUse_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryItemUseReceiverInterface_ReceiveInventoryItemUse_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InventoryItemUseReceiverInterface_eventReceiveInventoryItemUse_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryItemUseReceiverInterface_ReceiveInventoryItemUse()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryItemUseReceiverInterface_ReceiveInventoryItemUse_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IInventoryItemUseReceiverInterface::execReceiveInventoryItemUse)
{
	P_GET_OBJECT(AActor,Z_Param_User);
	P_GET_OBJECT(UInventoryComponent,Z_Param_Inventory);
	P_GET_STRUCT_REF(FInventorySlot,Z_Param_Out_Slot);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ReceiveInventoryItemUse_Implementation(Z_Param_User,Z_Param_Inventory,Z_Param_Out_Slot);
	P_NATIVE_END;
}
// ********** End Interface UInventoryItemUseReceiverInterface Function ReceiveInventoryItemUse ****

// ********** Begin Interface UInventoryItemUseReceiverInterface ***********************************
FClassRegistrationInfo Z_Registration_Info_UClass_UInventoryItemUseReceiverInterface;
UClass* UInventoryItemUseReceiverInterface::GetPrivateStaticClass()
{
	using TClass = UInventoryItemUseReceiverInterface;
	if (!Z_Registration_Info_UClass_UInventoryItemUseReceiverInterface.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("InventoryItemUseReceiverInterface"),
			Z_Registration_Info_UClass_UInventoryItemUseReceiverInterface.InnerSingleton,
			StaticRegisterNativesUInventoryItemUseReceiverInterface,
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
	return Z_Registration_Info_UClass_UInventoryItemUseReceiverInterface.InnerSingleton;
}
UClass* Z_Construct_UClass_UInventoryItemUseReceiverInterface_NoRegister()
{
	return UInventoryItemUseReceiverInterface::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UInventoryItemUseReceiverInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Interfaces/InventoryItemUseReceiverInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface UInventoryItemUseReceiverInterface constinit property declarations ***
// ********** End Interface UInventoryItemUseReceiverInterface constinit property declarations *****
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CanReceiveInventoryItemUse"), .Pointer = &IInventoryItemUseReceiverInterface::execCanReceiveInventoryItemUse },
		{ .NameUTF8 = UTF8TEXT("ReceiveInventoryItemUse"), .Pointer = &IInventoryItemUseReceiverInterface::execReceiveInventoryItemUse },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventoryItemUseReceiverInterface_CanReceiveInventoryItemUse, "CanReceiveInventoryItemUse" }, // 525624795
		{ &Z_Construct_UFunction_UInventoryItemUseReceiverInterface_ReceiveInventoryItemUse, "ReceiveInventoryItemUse" }, // 861533919
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IInventoryItemUseReceiverInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UInventoryItemUseReceiverInterface_Statics
UObject* (*const Z_Construct_UClass_UInventoryItemUseReceiverInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_InventorySystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemUseReceiverInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventoryItemUseReceiverInterface_Statics::ClassParams = {
	&UInventoryItemUseReceiverInterface::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001040A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemUseReceiverInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UInventoryItemUseReceiverInterface_Statics::Class_MetaDataParams)
};
void UInventoryItemUseReceiverInterface::StaticRegisterNativesUInventoryItemUseReceiverInterface()
{
	UClass* Class = UInventoryItemUseReceiverInterface::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UInventoryItemUseReceiverInterface_Statics::Funcs));
}
UClass* Z_Construct_UClass_UInventoryItemUseReceiverInterface()
{
	if (!Z_Registration_Info_UClass_UInventoryItemUseReceiverInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventoryItemUseReceiverInterface.OuterSingleton, Z_Construct_UClass_UInventoryItemUseReceiverInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInventoryItemUseReceiverInterface.OuterSingleton;
}
UInventoryItemUseReceiverInterface::UInventoryItemUseReceiverInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UInventoryItemUseReceiverInterface);
// ********** End Interface UInventoryItemUseReceiverInterface *************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemUseReceiverInterface_h__Script_InventorySystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInventoryItemUseReceiverInterface, UInventoryItemUseReceiverInterface::StaticClass, TEXT("UInventoryItemUseReceiverInterface"), &Z_Registration_Info_UClass_UInventoryItemUseReceiverInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventoryItemUseReceiverInterface), 3734366626U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemUseReceiverInterface_h__Script_InventorySystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemUseReceiverInterface_h__Script_InventorySystem_1095681234{
	TEXT("/Script/InventorySystem"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemUseReceiverInterface_h__Script_InventorySystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemUseReceiverInterface_h__Script_InventorySystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
