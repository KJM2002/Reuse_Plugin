// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Payloads/InventoryItemEventPayload.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeInventoryItemEventPayload() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemDefinition_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemEventPayload();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemEventPayload_NoRegister();
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventPayloadBase();
UPackage* Z_Construct_UPackage__Script_InventorySystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UInventoryItemEventPayload ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UInventoryItemEventPayload;
UClass* UInventoryItemEventPayload::GetPrivateStaticClass()
{
	using TClass = UInventoryItemEventPayload;
	if (!Z_Registration_Info_UClass_UInventoryItemEventPayload.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("InventoryItemEventPayload"),
			Z_Registration_Info_UClass_UInventoryItemEventPayload.InnerSingleton,
			StaticRegisterNativesUInventoryItemEventPayload,
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
	return Z_Registration_Info_UClass_UInventoryItemEventPayload.InnerSingleton;
}
UClass* Z_Construct_UClass_UInventoryItemEventPayload_NoRegister()
{
	return UInventoryItemEventPayload::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UInventoryItemEventPayload_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Payloads/InventoryItemEventPayload.h" },
		{ "ModuleRelativePath", "Public/Payloads/InventoryItemEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemDefinition_MetaData[] = {
		{ "Category", "Inventory|Events" },
		{ "ModuleRelativePath", "Public/Payloads/InventoryItemEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quantity_MetaData[] = {
		{ "Category", "Inventory|Events" },
		{ "ModuleRelativePath", "Public/Payloads/InventoryItemEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalQuantityAfter_MetaData[] = {
		{ "Category", "Inventory|Events" },
		{ "ModuleRelativePath", "Public/Payloads/InventoryItemEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventoryOwner_MetaData[] = {
		{ "Category", "Inventory|Events" },
		{ "ModuleRelativePath", "Public/Payloads/InventoryItemEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotIndex_MetaData[] = {
		{ "Category", "Inventory|Events" },
		{ "ModuleRelativePath", "Public/Payloads/InventoryItemEventPayload.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UInventoryItemEventPayload constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemDefinition;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalQuantityAfter;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InventoryOwner;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UInventoryItemEventPayload constinit property declarations *****************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryItemEventPayload>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UInventoryItemEventPayload_Statics

// ********** Begin Class UInventoryItemEventPayload Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryItemEventPayload_Statics::NewProp_ItemDefinition = { "ItemDefinition", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemEventPayload, ItemDefinition), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemDefinition_MetaData), NewProp_ItemDefinition_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UInventoryItemEventPayload_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemEventPayload, Quantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quantity_MetaData), NewProp_Quantity_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UInventoryItemEventPayload_Statics::NewProp_TotalQuantityAfter = { "TotalQuantityAfter", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemEventPayload, TotalQuantityAfter), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalQuantityAfter_MetaData), NewProp_TotalQuantityAfter_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryItemEventPayload_Statics::NewProp_InventoryOwner = { "InventoryOwner", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemEventPayload, InventoryOwner), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryOwner_MetaData), NewProp_InventoryOwner_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UInventoryItemEventPayload_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemEventPayload, SlotIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotIndex_MetaData), NewProp_SlotIndex_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventoryItemEventPayload_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemEventPayload_Statics::NewProp_ItemDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemEventPayload_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemEventPayload_Statics::NewProp_TotalQuantityAfter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemEventPayload_Statics::NewProp_InventoryOwner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemEventPayload_Statics::NewProp_SlotIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemEventPayload_Statics::PropPointers) < 2048);
// ********** End Class UInventoryItemEventPayload Property Definitions ****************************
UObject* (*const Z_Construct_UClass_UInventoryItemEventPayload_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UJMGameplayEventPayloadBase,
	(UObject* (*)())Z_Construct_UPackage__Script_InventorySystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemEventPayload_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventoryItemEventPayload_Statics::ClassParams = {
	&UInventoryItemEventPayload::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UInventoryItemEventPayload_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemEventPayload_Statics::PropPointers),
	0,
	0x003010A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemEventPayload_Statics::Class_MetaDataParams), Z_Construct_UClass_UInventoryItemEventPayload_Statics::Class_MetaDataParams)
};
void UInventoryItemEventPayload::StaticRegisterNativesUInventoryItemEventPayload()
{
}
UClass* Z_Construct_UClass_UInventoryItemEventPayload()
{
	if (!Z_Registration_Info_UClass_UInventoryItemEventPayload.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventoryItemEventPayload.OuterSingleton, Z_Construct_UClass_UInventoryItemEventPayload_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInventoryItemEventPayload.OuterSingleton;
}
UInventoryItemEventPayload::UInventoryItemEventPayload(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UInventoryItemEventPayload);
UInventoryItemEventPayload::~UInventoryItemEventPayload() {}
// ********** End Class UInventoryItemEventPayload *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Payloads_InventoryItemEventPayload_h__Script_InventorySystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInventoryItemEventPayload, UInventoryItemEventPayload::StaticClass, TEXT("UInventoryItemEventPayload"), &Z_Registration_Info_UClass_UInventoryItemEventPayload, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventoryItemEventPayload), 3121582317U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Payloads_InventoryItemEventPayload_h__Script_InventorySystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Payloads_InventoryItemEventPayload_h__Script_InventorySystem_1654074691{
	TEXT("/Script/InventorySystem"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Payloads_InventoryItemEventPayload_h__Script_InventorySystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Payloads_InventoryItemEventPayload_h__Script_InventorySystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
