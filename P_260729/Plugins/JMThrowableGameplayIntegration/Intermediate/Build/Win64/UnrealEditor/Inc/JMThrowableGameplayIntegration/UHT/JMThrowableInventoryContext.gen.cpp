// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JMThrowableInventoryContext.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMThrowableInventoryContext() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryComponent_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemDefinition_NoRegister();
JMTHROWABLE_API UClass* Z_Construct_UClass_UJMThrowableDefinition_NoRegister();
JMTHROWABLEGAMEPLAYINTEGRATION_API UScriptStruct* Z_Construct_UScriptStruct_FJMThrowableInventoryContext();
UPackage* Z_Construct_UPackage__Script_JMThrowableGameplayIntegration();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FJMThrowableInventoryContext **************************************
struct Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMThrowableInventoryContext); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMThrowableInventoryContext); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableInventoryContext.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventoryComponent_MetaData[] = {
		{ "Category", "JMThrowableInventoryContext" },
		{ "ModuleRelativePath", "Public/JMThrowableInventoryContext.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemDefinition_MetaData[] = {
		{ "Category", "JMThrowableInventoryContext" },
		{ "ModuleRelativePath", "Public/JMThrowableInventoryContext.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThrowableDefinition_MetaData[] = {
		{ "Category", "JMThrowableInventoryContext" },
		{ "ModuleRelativePath", "Public/JMThrowableInventoryContext.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotIndex_MetaData[] = {
		{ "Category", "JMThrowableInventoryContext" },
		{ "ModuleRelativePath", "Public/JMThrowableInventoryContext.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntryHandle_MetaData[] = {
		{ "Category", "JMThrowableInventoryContext" },
		{ "ModuleRelativePath", "Public/JMThrowableInventoryContext.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequestedQuantity_MetaData[] = {
		{ "Category", "JMThrowableInventoryContext" },
		{ "ModuleRelativePath", "Public/JMThrowableInventoryContext.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SessionId_MetaData[] = {
		{ "Category", "JMThrowableInventoryContext" },
		{ "ModuleRelativePath", "Public/JMThrowableInventoryContext.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMThrowableInventoryContext constinit property declarations ******
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_InventoryComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemDefinition;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ThrowableDefinition;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EntryHandle;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RequestedQuantity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SessionId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMThrowableInventoryContext constinit property declarations ********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMThrowableInventoryContext>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMThrowableInventoryContext;
class UScriptStruct* FJMThrowableInventoryContext::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMThrowableInventoryContext.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMThrowableInventoryContext.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMThrowableInventoryContext, (UObject*)Z_Construct_UPackage__Script_JMThrowableGameplayIntegration(), TEXT("JMThrowableInventoryContext"));
	}
	return Z_Registration_Info_UScriptStruct_FJMThrowableInventoryContext.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMThrowableInventoryContext Property Definitions *****************
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics::NewProp_InventoryComponent = { "InventoryComponent", nullptr, (EPropertyFlags)0x001400000008001c, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowableInventoryContext, InventoryComponent), Z_Construct_UClass_UInventoryComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryComponent_MetaData), NewProp_InventoryComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics::NewProp_ItemDefinition = { "ItemDefinition", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowableInventoryContext, ItemDefinition), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemDefinition_MetaData), NewProp_ItemDefinition_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics::NewProp_ThrowableDefinition = { "ThrowableDefinition", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowableInventoryContext, ThrowableDefinition), Z_Construct_UClass_UJMThrowableDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThrowableDefinition_MetaData), NewProp_ThrowableDefinition_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowableInventoryContext, SlotIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotIndex_MetaData), NewProp_SlotIndex_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics::NewProp_EntryHandle = { "EntryHandle", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowableInventoryContext, EntryHandle), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntryHandle_MetaData), NewProp_EntryHandle_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics::NewProp_RequestedQuantity = { "RequestedQuantity", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowableInventoryContext, RequestedQuantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequestedQuantity_MetaData), NewProp_RequestedQuantity_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMThrowableInventoryContext, SessionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SessionId_MetaData), NewProp_SessionId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics::NewProp_InventoryComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics::NewProp_ItemDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics::NewProp_ThrowableDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics::NewProp_EntryHandle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics::NewProp_RequestedQuantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics::NewProp_SessionId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMThrowableInventoryContext Property Definitions *******************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMThrowableGameplayIntegration,
	nullptr,
	&NewStructOps,
	"JMThrowableInventoryContext",
	Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics::PropPointers),
	sizeof(FJMThrowableInventoryContext),
	alignof(FJMThrowableInventoryContext),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000205),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMThrowableInventoryContext()
{
	if (!Z_Registration_Info_UScriptStruct_FJMThrowableInventoryContext.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMThrowableInventoryContext.InnerSingleton, Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMThrowableInventoryContext.InnerSingleton);
}
// ********** End ScriptStruct FJMThrowableInventoryContext ****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableInventoryContext_h__Script_JMThrowableGameplayIntegration_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FJMThrowableInventoryContext::StaticStruct, Z_Construct_UScriptStruct_FJMThrowableInventoryContext_Statics::NewStructOps, TEXT("JMThrowableInventoryContext"),&Z_Registration_Info_UScriptStruct_FJMThrowableInventoryContext, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMThrowableInventoryContext), 4063969361U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableInventoryContext_h__Script_JMThrowableGameplayIntegration_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableInventoryContext_h__Script_JMThrowableGameplayIntegration_396009218{
	TEXT("/Script/JMThrowableGameplayIntegration"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableInventoryContext_h__Script_JMThrowableGameplayIntegration_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableInventoryContext_h__Script_JMThrowableGameplayIntegration_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
