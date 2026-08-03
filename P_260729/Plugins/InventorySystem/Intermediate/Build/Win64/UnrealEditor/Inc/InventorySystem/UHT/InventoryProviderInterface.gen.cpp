// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interfaces/InventoryProviderInterface.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeInventoryProviderInterface() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryComponent_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryProviderInterface();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryProviderInterface_NoRegister();
UPackage* Z_Construct_UPackage__Script_InventorySystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface UInventoryProviderInterface Function GetInventoryComponent ***********
struct InventoryProviderInterface_eventGetInventoryComponent_Parms
{
	UInventoryComponent* ReturnValue;

	/** Constructor, initializes return property only **/
	InventoryProviderInterface_eventGetInventoryComponent_Parms()
		: ReturnValue(NULL)
	{
	}
};
UInventoryComponent* IInventoryProviderInterface::GetInventoryComponent() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetInventoryComponent instead.");
	InventoryProviderInterface_eventGetInventoryComponent_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UInventoryProviderInterface_GetInventoryComponent = FName(TEXT("GetInventoryComponent"));
UInventoryComponent* IInventoryProviderInterface::Execute_GetInventoryComponent(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UInventoryProviderInterface::StaticClass()));
	InventoryProviderInterface_eventGetInventoryComponent_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UInventoryProviderInterface_GetInventoryComponent);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IInventoryProviderInterface*)(O->GetNativeInterfaceAddress(UInventoryProviderInterface::StaticClass())))
	{
		Parms.ReturnValue = I->GetInventoryComponent_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UInventoryProviderInterface_GetInventoryComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/Interfaces/InventoryProviderInterface.h" },
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
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryProviderInterface_GetInventoryComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryProviderInterface_eventGetInventoryComponent_Parms, ReturnValue), Z_Construct_UClass_UInventoryComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryProviderInterface_GetInventoryComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryProviderInterface_GetInventoryComponent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryProviderInterface_GetInventoryComponent_Statics::PropPointers) < 2048);
// ********** End Function GetInventoryComponent Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryProviderInterface_GetInventoryComponent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryProviderInterface, nullptr, "GetInventoryComponent", 	Z_Construct_UFunction_UInventoryProviderInterface_GetInventoryComponent_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryProviderInterface_GetInventoryComponent_Statics::PropPointers), 
sizeof(InventoryProviderInterface_eventGetInventoryComponent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryProviderInterface_GetInventoryComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryProviderInterface_GetInventoryComponent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InventoryProviderInterface_eventGetInventoryComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryProviderInterface_GetInventoryComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryProviderInterface_GetInventoryComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IInventoryProviderInterface::execGetInventoryComponent)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UInventoryComponent**)Z_Param__Result=P_THIS->GetInventoryComponent_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UInventoryProviderInterface Function GetInventoryComponent *************

// ********** Begin Interface UInventoryProviderInterface ******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UInventoryProviderInterface;
UClass* UInventoryProviderInterface::GetPrivateStaticClass()
{
	using TClass = UInventoryProviderInterface;
	if (!Z_Registration_Info_UClass_UInventoryProviderInterface.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("InventoryProviderInterface"),
			Z_Registration_Info_UClass_UInventoryProviderInterface.InnerSingleton,
			StaticRegisterNativesUInventoryProviderInterface,
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
	return Z_Registration_Info_UClass_UInventoryProviderInterface.InnerSingleton;
}
UClass* Z_Construct_UClass_UInventoryProviderInterface_NoRegister()
{
	return UInventoryProviderInterface::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UInventoryProviderInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Interfaces/InventoryProviderInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface UInventoryProviderInterface constinit property declarations **********
// ********** End Interface UInventoryProviderInterface constinit property declarations ************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetInventoryComponent"), .Pointer = &IInventoryProviderInterface::execGetInventoryComponent },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventoryProviderInterface_GetInventoryComponent, "GetInventoryComponent" }, // 1365442149
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IInventoryProviderInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UInventoryProviderInterface_Statics
UObject* (*const Z_Construct_UClass_UInventoryProviderInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_InventorySystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryProviderInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventoryProviderInterface_Statics::ClassParams = {
	&UInventoryProviderInterface::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryProviderInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UInventoryProviderInterface_Statics::Class_MetaDataParams)
};
void UInventoryProviderInterface::StaticRegisterNativesUInventoryProviderInterface()
{
	UClass* Class = UInventoryProviderInterface::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UInventoryProviderInterface_Statics::Funcs));
}
UClass* Z_Construct_UClass_UInventoryProviderInterface()
{
	if (!Z_Registration_Info_UClass_UInventoryProviderInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventoryProviderInterface.OuterSingleton, Z_Construct_UClass_UInventoryProviderInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInventoryProviderInterface.OuterSingleton;
}
UInventoryProviderInterface::UInventoryProviderInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UInventoryProviderInterface);
// ********** End Interface UInventoryProviderInterface ********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryProviderInterface_h__Script_InventorySystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInventoryProviderInterface, UInventoryProviderInterface::StaticClass, TEXT("UInventoryProviderInterface"), &Z_Registration_Info_UClass_UInventoryProviderInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventoryProviderInterface), 292850657U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryProviderInterface_h__Script_InventorySystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryProviderInterface_h__Script_InventorySystem_631125796{
	TEXT("/Script/InventorySystem"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryProviderInterface_h__Script_InventorySystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryProviderInterface_h__Script_InventorySystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
