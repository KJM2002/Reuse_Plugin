// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Integration/ReuseInventoryInspectorBridge.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeReuseInventoryInspectorBridge() {}

// ********** Begin Cross Module References ********************************************************
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemInspectorBridge();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UReuseInventoryInspectorBridge();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UReuseInventoryInspectorBridge_NoRegister();
ITEMINSPECTORRUNTIME_API UEnum* Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionCloseReason();
UPackage* Z_Construct_UPackage__Script_InventorySystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UReuseInventoryInspectorBridge Function HandleInspectionClosed ***********
struct Z_Construct_UFunction_UReuseInventoryInspectorBridge_HandleInspectionClosed_Statics
{
	struct ReuseInventoryInspectorBridge_eventHandleInspectionClosed_Parms
	{
		EJMItemInspectionCloseReason Reason;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Integration/ReuseInventoryInspectorBridge.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleInspectionClosed constinit property declarations ****************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Reason_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Reason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleInspectionClosed constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleInspectionClosed Property Definitions ***************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UReuseInventoryInspectorBridge_HandleInspectionClosed_Statics::NewProp_Reason_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UReuseInventoryInspectorBridge_HandleInspectionClosed_Statics::NewProp_Reason = { "Reason", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ReuseInventoryInspectorBridge_eventHandleInspectionClosed_Parms, Reason), Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionCloseReason, METADATA_PARAMS(0, nullptr) }; // 1865201677
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UReuseInventoryInspectorBridge_HandleInspectionClosed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UReuseInventoryInspectorBridge_HandleInspectionClosed_Statics::NewProp_Reason_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UReuseInventoryInspectorBridge_HandleInspectionClosed_Statics::NewProp_Reason,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UReuseInventoryInspectorBridge_HandleInspectionClosed_Statics::PropPointers) < 2048);
// ********** End Function HandleInspectionClosed Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UReuseInventoryInspectorBridge_HandleInspectionClosed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UReuseInventoryInspectorBridge, nullptr, "HandleInspectionClosed", 	Z_Construct_UFunction_UReuseInventoryInspectorBridge_HandleInspectionClosed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UReuseInventoryInspectorBridge_HandleInspectionClosed_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UReuseInventoryInspectorBridge_HandleInspectionClosed_Statics::ReuseInventoryInspectorBridge_eventHandleInspectionClosed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UReuseInventoryInspectorBridge_HandleInspectionClosed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UReuseInventoryInspectorBridge_HandleInspectionClosed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UReuseInventoryInspectorBridge_HandleInspectionClosed_Statics::ReuseInventoryInspectorBridge_eventHandleInspectionClosed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UReuseInventoryInspectorBridge_HandleInspectionClosed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UReuseInventoryInspectorBridge_HandleInspectionClosed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UReuseInventoryInspectorBridge::execHandleInspectionClosed)
{
	P_GET_ENUM(EJMItemInspectionCloseReason,Z_Param_Reason);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleInspectionClosed(EJMItemInspectionCloseReason(Z_Param_Reason));
	P_NATIVE_END;
}
// ********** End Class UReuseInventoryInspectorBridge Function HandleInspectionClosed *************

// ********** Begin Class UReuseInventoryInspectorBridge *******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UReuseInventoryInspectorBridge;
UClass* UReuseInventoryInspectorBridge::GetPrivateStaticClass()
{
	using TClass = UReuseInventoryInspectorBridge;
	if (!Z_Registration_Info_UClass_UReuseInventoryInspectorBridge.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ReuseInventoryInspectorBridge"),
			Z_Registration_Info_UClass_UReuseInventoryInspectorBridge.InnerSingleton,
			StaticRegisterNativesUReuseInventoryInspectorBridge,
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
	return Z_Registration_Info_UClass_UReuseInventoryInspectorBridge.InnerSingleton;
}
UClass* Z_Construct_UClass_UReuseInventoryInspectorBridge_NoRegister()
{
	return UReuseInventoryInspectorBridge::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UReuseInventoryInspectorBridge_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Thin host-project adapter between the portable InventorySystem bridge and\n * the existing ItemInspector item inspection subsystem.\n */" },
#endif
		{ "IncludePath", "Integration/ReuseInventoryInspectorBridge.h" },
		{ "ModuleRelativePath", "Public/Integration/ReuseInventoryInspectorBridge.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Thin host-project adapter between the portable InventorySystem bridge and\nthe existing ItemInspector item inspection subsystem." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UReuseInventoryInspectorBridge constinit property declarations ***********
// ********** End Class UReuseInventoryInspectorBridge constinit property declarations *************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("HandleInspectionClosed"), .Pointer = &UReuseInventoryInspectorBridge::execHandleInspectionClosed },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UReuseInventoryInspectorBridge_HandleInspectionClosed, "HandleInspectionClosed" }, // 1610771094
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UReuseInventoryInspectorBridge>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UReuseInventoryInspectorBridge_Statics
UObject* (*const Z_Construct_UClass_UReuseInventoryInspectorBridge_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInventoryItemInspectorBridge,
	(UObject* (*)())Z_Construct_UPackage__Script_InventorySystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UReuseInventoryInspectorBridge_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UReuseInventoryInspectorBridge_Statics::ClassParams = {
	&UReuseInventoryInspectorBridge::StaticClass,
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
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UReuseInventoryInspectorBridge_Statics::Class_MetaDataParams), Z_Construct_UClass_UReuseInventoryInspectorBridge_Statics::Class_MetaDataParams)
};
void UReuseInventoryInspectorBridge::StaticRegisterNativesUReuseInventoryInspectorBridge()
{
	UClass* Class = UReuseInventoryInspectorBridge::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UReuseInventoryInspectorBridge_Statics::Funcs));
}
UClass* Z_Construct_UClass_UReuseInventoryInspectorBridge()
{
	if (!Z_Registration_Info_UClass_UReuseInventoryInspectorBridge.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UReuseInventoryInspectorBridge.OuterSingleton, Z_Construct_UClass_UReuseInventoryInspectorBridge_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UReuseInventoryInspectorBridge.OuterSingleton;
}
UReuseInventoryInspectorBridge::UReuseInventoryInspectorBridge(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UReuseInventoryInspectorBridge);
UReuseInventoryInspectorBridge::~UReuseInventoryInspectorBridge() {}
// ********** End Class UReuseInventoryInspectorBridge *********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Integration_ReuseInventoryInspectorBridge_h__Script_InventorySystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UReuseInventoryInspectorBridge, UReuseInventoryInspectorBridge::StaticClass, TEXT("UReuseInventoryInspectorBridge"), &Z_Registration_Info_UClass_UReuseInventoryInspectorBridge, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UReuseInventoryInspectorBridge), 1066390277U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Integration_ReuseInventoryInspectorBridge_h__Script_InventorySystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Integration_ReuseInventoryInspectorBridge_h__Script_InventorySystem_395773188{
	TEXT("/Script/InventorySystem"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Integration_ReuseInventoryInspectorBridge_h__Script_InventorySystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Integration_ReuseInventoryInspectorBridge_h__Script_InventorySystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
