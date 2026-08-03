// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Items/InventoryItemUseEffect.h"
#include "InventoryTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeInventoryItemUseEffect() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryComponent_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemUseEffect();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemUseEffect_NoRegister();
INVENTORYSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FInventorySlot();
UPackage* Z_Construct_UPackage__Script_InventorySystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UInventoryItemUseEffect Function CanUse **********************************
struct InventoryItemUseEffect_eventCanUse_Parms
{
	AActor* User;
	FInventorySlot Slot;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	InventoryItemUseEffect_eventCanUse_Parms()
		: ReturnValue(false)
	{
	}
};
static FName NAME_UInventoryItemUseEffect_CanUse = FName(TEXT("CanUse"));
bool UInventoryItemUseEffect::CanUse(AActor* User, FInventorySlot const& Slot) const
{
	UFunction* Func = FindFunctionChecked(NAME_UInventoryItemUseEffect_CanUse);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		InventoryItemUseEffect_eventCanUse_Parms Parms;
		Parms.User=User;
		Parms.Slot=Slot;
		const_cast<UInventoryItemUseEffect*>(this)->ProcessEvent(Func,&Parms);
		return !!Parms.ReturnValue;
	}
	else
	{
		return const_cast<UInventoryItemUseEffect*>(this)->CanUse_Implementation(User, Slot);
	}
}
struct Z_Construct_UFunction_UInventoryItemUseEffect_CanUse_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Use" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemUseEffect.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Slot_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CanUse constinit property declarations ********************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_User;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Slot;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CanUse constinit property declarations **********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CanUse Property Definitions *******************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryItemUseEffect_CanUse_Statics::NewProp_User = { "User", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemUseEffect_eventCanUse_Parms, User), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryItemUseEffect_CanUse_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemUseEffect_eventCanUse_Parms, Slot), Z_Construct_UScriptStruct_FInventorySlot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Slot_MetaData), NewProp_Slot_MetaData) }; // 3353780059
void Z_Construct_UFunction_UInventoryItemUseEffect_CanUse_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventoryItemUseEffect_eventCanUse_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryItemUseEffect_CanUse_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventoryItemUseEffect_eventCanUse_Parms), &Z_Construct_UFunction_UInventoryItemUseEffect_CanUse_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryItemUseEffect_CanUse_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemUseEffect_CanUse_Statics::NewProp_User,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemUseEffect_CanUse_Statics::NewProp_Slot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemUseEffect_CanUse_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemUseEffect_CanUse_Statics::PropPointers) < 2048);
// ********** End Function CanUse Property Definitions *********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryItemUseEffect_CanUse_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryItemUseEffect, nullptr, "CanUse", 	Z_Construct_UFunction_UInventoryItemUseEffect_CanUse_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemUseEffect_CanUse_Statics::PropPointers), 
sizeof(InventoryItemUseEffect_eventCanUse_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemUseEffect_CanUse_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryItemUseEffect_CanUse_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InventoryItemUseEffect_eventCanUse_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryItemUseEffect_CanUse()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryItemUseEffect_CanUse_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryItemUseEffect::execCanUse)
{
	P_GET_OBJECT(AActor,Z_Param_User);
	P_GET_STRUCT_REF(FInventorySlot,Z_Param_Out_Slot);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanUse_Implementation(Z_Param_User,Z_Param_Out_Slot);
	P_NATIVE_END;
}
// ********** End Class UInventoryItemUseEffect Function CanUse ************************************

// ********** Begin Class UInventoryItemUseEffect Function ExecuteUse ******************************
struct InventoryItemUseEffect_eventExecuteUse_Parms
{
	AActor* User;
	UInventoryComponent* Inventory;
	FInventorySlot Slot;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	InventoryItemUseEffect_eventExecuteUse_Parms()
		: ReturnValue(false)
	{
	}
};
static FName NAME_UInventoryItemUseEffect_ExecuteUse = FName(TEXT("ExecuteUse"));
bool UInventoryItemUseEffect::ExecuteUse(AActor* User, UInventoryComponent* Inventory, FInventorySlot const& Slot)
{
	UFunction* Func = FindFunctionChecked(NAME_UInventoryItemUseEffect_ExecuteUse);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		InventoryItemUseEffect_eventExecuteUse_Parms Parms;
		Parms.User=User;
		Parms.Inventory=Inventory;
		Parms.Slot=Slot;
	ProcessEvent(Func,&Parms);
		return !!Parms.ReturnValue;
	}
	else
	{
		return ExecuteUse_Implementation(User, Inventory, Slot);
	}
}
struct Z_Construct_UFunction_UInventoryItemUseEffect_ExecuteUse_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Use" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemUseEffect.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Inventory_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Slot_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ExecuteUse constinit property declarations ****************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_User;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Inventory;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Slot;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ExecuteUse constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ExecuteUse Property Definitions ***************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryItemUseEffect_ExecuteUse_Statics::NewProp_User = { "User", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemUseEffect_eventExecuteUse_Parms, User), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryItemUseEffect_ExecuteUse_Statics::NewProp_Inventory = { "Inventory", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemUseEffect_eventExecuteUse_Parms, Inventory), Z_Construct_UClass_UInventoryComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Inventory_MetaData), NewProp_Inventory_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryItemUseEffect_ExecuteUse_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemUseEffect_eventExecuteUse_Parms, Slot), Z_Construct_UScriptStruct_FInventorySlot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Slot_MetaData), NewProp_Slot_MetaData) }; // 3353780059
void Z_Construct_UFunction_UInventoryItemUseEffect_ExecuteUse_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventoryItemUseEffect_eventExecuteUse_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryItemUseEffect_ExecuteUse_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventoryItemUseEffect_eventExecuteUse_Parms), &Z_Construct_UFunction_UInventoryItemUseEffect_ExecuteUse_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryItemUseEffect_ExecuteUse_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemUseEffect_ExecuteUse_Statics::NewProp_User,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemUseEffect_ExecuteUse_Statics::NewProp_Inventory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemUseEffect_ExecuteUse_Statics::NewProp_Slot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemUseEffect_ExecuteUse_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemUseEffect_ExecuteUse_Statics::PropPointers) < 2048);
// ********** End Function ExecuteUse Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryItemUseEffect_ExecuteUse_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryItemUseEffect, nullptr, "ExecuteUse", 	Z_Construct_UFunction_UInventoryItemUseEffect_ExecuteUse_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemUseEffect_ExecuteUse_Statics::PropPointers), 
sizeof(InventoryItemUseEffect_eventExecuteUse_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemUseEffect_ExecuteUse_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryItemUseEffect_ExecuteUse_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InventoryItemUseEffect_eventExecuteUse_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryItemUseEffect_ExecuteUse()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryItemUseEffect_ExecuteUse_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryItemUseEffect::execExecuteUse)
{
	P_GET_OBJECT(AActor,Z_Param_User);
	P_GET_OBJECT(UInventoryComponent,Z_Param_Inventory);
	P_GET_STRUCT_REF(FInventorySlot,Z_Param_Out_Slot);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ExecuteUse_Implementation(Z_Param_User,Z_Param_Inventory,Z_Param_Out_Slot);
	P_NATIVE_END;
}
// ********** End Class UInventoryItemUseEffect Function ExecuteUse ********************************

// ********** Begin Class UInventoryItemUseEffect **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UInventoryItemUseEffect;
UClass* UInventoryItemUseEffect::GetPrivateStaticClass()
{
	using TClass = UInventoryItemUseEffect;
	if (!Z_Registration_Info_UClass_UInventoryItemUseEffect.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("InventoryItemUseEffect"),
			Z_Registration_Info_UClass_UInventoryItemUseEffect.InnerSingleton,
			StaticRegisterNativesUInventoryItemUseEffect,
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
	return Z_Registration_Info_UClass_UInventoryItemUseEffect.InnerSingleton;
}
UClass* Z_Construct_UClass_UInventoryItemUseEffect_NoRegister()
{
	return UInventoryItemUseEffect::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UInventoryItemUseEffect_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Items/InventoryItemUseEffect.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemUseEffect.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UInventoryItemUseEffect constinit property declarations ******************
// ********** End Class UInventoryItemUseEffect constinit property declarations ********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CanUse"), .Pointer = &UInventoryItemUseEffect::execCanUse },
		{ .NameUTF8 = UTF8TEXT("ExecuteUse"), .Pointer = &UInventoryItemUseEffect::execExecuteUse },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventoryItemUseEffect_CanUse, "CanUse" }, // 1305243300
		{ &Z_Construct_UFunction_UInventoryItemUseEffect_ExecuteUse, "ExecuteUse" }, // 929842250
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryItemUseEffect>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UInventoryItemUseEffect_Statics
UObject* (*const Z_Construct_UClass_UInventoryItemUseEffect_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_InventorySystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemUseEffect_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventoryItemUseEffect_Statics::ClassParams = {
	&UInventoryItemUseEffect::StaticClass,
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
	0x003010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemUseEffect_Statics::Class_MetaDataParams), Z_Construct_UClass_UInventoryItemUseEffect_Statics::Class_MetaDataParams)
};
void UInventoryItemUseEffect::StaticRegisterNativesUInventoryItemUseEffect()
{
	UClass* Class = UInventoryItemUseEffect::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UInventoryItemUseEffect_Statics::Funcs));
}
UClass* Z_Construct_UClass_UInventoryItemUseEffect()
{
	if (!Z_Registration_Info_UClass_UInventoryItemUseEffect.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventoryItemUseEffect.OuterSingleton, Z_Construct_UClass_UInventoryItemUseEffect_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInventoryItemUseEffect.OuterSingleton;
}
UInventoryItemUseEffect::UInventoryItemUseEffect(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UInventoryItemUseEffect);
UInventoryItemUseEffect::~UInventoryItemUseEffect() {}
// ********** End Class UInventoryItemUseEffect ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemUseEffect_h__Script_InventorySystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInventoryItemUseEffect, UInventoryItemUseEffect::StaticClass, TEXT("UInventoryItemUseEffect"), &Z_Registration_Info_UClass_UInventoryItemUseEffect, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventoryItemUseEffect), 330949225U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemUseEffect_h__Script_InventorySystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemUseEffect_h__Script_InventorySystem_1464906175{
	TEXT("/Script/InventorySystem"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemUseEffect_h__Script_InventorySystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemUseEffect_h__Script_InventorySystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
