// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Items/InventoryItemDefinition.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeInventoryItemDefinition() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_AInventoryWorldItemPickup_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemDefinition();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemDefinition_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemUseEffect_NoRegister();
UPackage* Z_Construct_UPackage__Script_InventorySystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UInventoryItemDefinition Function GetEffectiveMaxStackSize ***************
struct Z_Construct_UFunction_UInventoryItemDefinition_GetEffectiveMaxStackSize_Statics
{
	struct InventoryItemDefinition_eventGetEffectiveMaxStackSize_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemDefinition.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetEffectiveMaxStackSize constinit property declarations **************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetEffectiveMaxStackSize constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetEffectiveMaxStackSize Property Definitions *************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryItemDefinition_GetEffectiveMaxStackSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryItemDefinition_eventGetEffectiveMaxStackSize_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryItemDefinition_GetEffectiveMaxStackSize_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryItemDefinition_GetEffectiveMaxStackSize_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemDefinition_GetEffectiveMaxStackSize_Statics::PropPointers) < 2048);
// ********** End Function GetEffectiveMaxStackSize Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryItemDefinition_GetEffectiveMaxStackSize_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryItemDefinition, nullptr, "GetEffectiveMaxStackSize", 	Z_Construct_UFunction_UInventoryItemDefinition_GetEffectiveMaxStackSize_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemDefinition_GetEffectiveMaxStackSize_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryItemDefinition_GetEffectiveMaxStackSize_Statics::InventoryItemDefinition_eventGetEffectiveMaxStackSize_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryItemDefinition_GetEffectiveMaxStackSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryItemDefinition_GetEffectiveMaxStackSize_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryItemDefinition_GetEffectiveMaxStackSize_Statics::InventoryItemDefinition_eventGetEffectiveMaxStackSize_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryItemDefinition_GetEffectiveMaxStackSize()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryItemDefinition_GetEffectiveMaxStackSize_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryItemDefinition::execGetEffectiveMaxStackSize)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetEffectiveMaxStackSize();
	P_NATIVE_END;
}
// ********** End Class UInventoryItemDefinition Function GetEffectiveMaxStackSize *****************

// ********** Begin Class UInventoryItemDefinition *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UInventoryItemDefinition;
UClass* UInventoryItemDefinition::GetPrivateStaticClass()
{
	using TClass = UInventoryItemDefinition;
	if (!Z_Registration_Info_UClass_UInventoryItemDefinition.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("InventoryItemDefinition"),
			Z_Registration_Info_UClass_UInventoryItemDefinition.InnerSingleton,
			StaticRegisterNativesUInventoryItemDefinition,
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
	return Z_Registration_Info_UClass_UInventoryItemDefinition.InnerSingleton;
}
UClass* Z_Construct_UClass_UInventoryItemDefinition_NoRegister()
{
	return UInventoryItemDefinition::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UInventoryItemDefinition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Items/InventoryItemDefinition.h" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemId_MetaData[] = {
		{ "Category", "Identity" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[] = {
		{ "Category", "Text" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "Text" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemDefinition.h" },
		{ "MultiLine", "TRUE" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CategoryText_MetaData[] = {
		{ "Category", "Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional short presentation label such as \"\xec\xa4\x91\xec\x9a\x94 \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c\" or \"\xec\x86\x8c\xeb\xaa\xa8\xed\x92\x88\". */" },
#endif
		{ "ModuleRelativePath", "Public/Items/InventoryItemDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional short presentation label such as \"\xec\xa4\x91\xec\x9a\x94 \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c\" or \"\xec\x86\x8c\xeb\xaa\xa8\xed\x92\x88\"." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlavorText_MetaData[] = {
		{ "Category", "Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional secondary lore text. Kept separate so the detail hierarchy stays readable. */" },
#endif
		{ "ModuleRelativePath", "Public/Items/InventoryItemDefinition.h" },
		{ "MultiLine", "TRUE" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional secondary lore text. Kept separate so the detail hierarchy stays readable." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Icon_MetaData[] = {
		{ "Category", "Presentation" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InspectMesh_MetaData[] = {
		{ "Category", "Presentation" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldItemClass_MetaData[] = {
		{ "Category", "Presentation" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InspectorData_MetaData[] = {
		{ "AllowedClasses", "/Script/Engine.PrimaryDataAsset" },
		{ "Category", "Presentation" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanUse_MetaData[] = {
		{ "Category", "Rules" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanDrop_MetaData[] = {
		{ "Category", "Rules" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanInspect_MetaData[] = {
		{ "Category", "Rules" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bStackable_MetaData[] = {
		{ "Category", "Rules" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxStackSize_MetaData[] = {
		{ "Category", "Rules" },
		{ "ClampMin", "1" },
		{ "EditCondition", "bStackable" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Weight_MetaData[] = {
		{ "Category", "Rules" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemTags_MetaData[] = {
		{ "Category", "Rules" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UseButtonText_MetaData[] = {
		{ "Category", "Text" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CannotUseReason_MetaData[] = {
		{ "Category", "Text" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UseEffect_MetaData[] = {
		{ "Category", "Use" },
		{ "EditCondition", "bCanUse" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bConsumeOnUse_MetaData[] = {
		{ "Category", "Use" },
		{ "EditCondition", "bCanUse" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConsumeQuantity_MetaData[] = {
		{ "Category", "Use" },
		{ "ClampMin", "1" },
		{ "EditCondition", "bCanUse && bConsumeOnUse" },
		{ "ModuleRelativePath", "Public/Items/InventoryItemDefinition.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UInventoryItemDefinition constinit property declarations *****************
	static const UECodeGen_Private::FNamePropertyParams NewProp_ItemId;
	static const UECodeGen_Private::FTextPropertyParams NewProp_DisplayName;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Description;
	static const UECodeGen_Private::FTextPropertyParams NewProp_CategoryText;
	static const UECodeGen_Private::FTextPropertyParams NewProp_FlavorText;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Icon;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_InspectMesh;
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_WorldItemClass;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_InspectorData;
	static void NewProp_bCanUse_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanUse;
	static void NewProp_bCanDrop_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanDrop;
	static void NewProp_bCanInspect_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanInspect;
	static void NewProp_bStackable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStackable;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxStackSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Weight;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemTags;
	static const UECodeGen_Private::FTextPropertyParams NewProp_UseButtonText;
	static const UECodeGen_Private::FTextPropertyParams NewProp_CannotUseReason;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UseEffect;
	static void NewProp_bConsumeOnUse_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bConsumeOnUse;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ConsumeQuantity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UInventoryItemDefinition constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetEffectiveMaxStackSize"), .Pointer = &UInventoryItemDefinition::execGetEffectiveMaxStackSize },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventoryItemDefinition_GetEffectiveMaxStackSize, "GetEffectiveMaxStackSize" }, // 897343945
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryItemDefinition>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UInventoryItemDefinition_Statics

// ********** Begin Class UInventoryItemDefinition Property Definitions ****************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_ItemId = { "ItemId", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemDefinition, ItemId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemId_MetaData), NewProp_ItemId_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemDefinition, DisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayName_MetaData), NewProp_DisplayName_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemDefinition, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_CategoryText = { "CategoryText", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemDefinition, CategoryText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CategoryText_MetaData), NewProp_CategoryText_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_FlavorText = { "FlavorText", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemDefinition, FlavorText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlavorText_MetaData), NewProp_FlavorText_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_Icon = { "Icon", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemDefinition, Icon), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Icon_MetaData), NewProp_Icon_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_InspectMesh = { "InspectMesh", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemDefinition, InspectMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InspectMesh_MetaData), NewProp_InspectMesh_MetaData) };
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_WorldItemClass = { "WorldItemClass", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemDefinition, WorldItemClass), Z_Construct_UClass_AInventoryWorldItemPickup_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldItemClass_MetaData), NewProp_WorldItemClass_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_InspectorData = { "InspectorData", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemDefinition, InspectorData), Z_Construct_UClass_UPrimaryDataAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InspectorData_MetaData), NewProp_InspectorData_MetaData) };
void Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_bCanUse_SetBit(void* Obj)
{
	((UInventoryItemDefinition*)Obj)->bCanUse = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_bCanUse = { "bCanUse", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UInventoryItemDefinition), &Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_bCanUse_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanUse_MetaData), NewProp_bCanUse_MetaData) };
void Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_bCanDrop_SetBit(void* Obj)
{
	((UInventoryItemDefinition*)Obj)->bCanDrop = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_bCanDrop = { "bCanDrop", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UInventoryItemDefinition), &Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_bCanDrop_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanDrop_MetaData), NewProp_bCanDrop_MetaData) };
void Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_bCanInspect_SetBit(void* Obj)
{
	((UInventoryItemDefinition*)Obj)->bCanInspect = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_bCanInspect = { "bCanInspect", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UInventoryItemDefinition), &Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_bCanInspect_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanInspect_MetaData), NewProp_bCanInspect_MetaData) };
void Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_bStackable_SetBit(void* Obj)
{
	((UInventoryItemDefinition*)Obj)->bStackable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_bStackable = { "bStackable", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UInventoryItemDefinition), &Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_bStackable_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bStackable_MetaData), NewProp_bStackable_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_MaxStackSize = { "MaxStackSize", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemDefinition, MaxStackSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxStackSize_MetaData), NewProp_MaxStackSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_Weight = { "Weight", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemDefinition, Weight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Weight_MetaData), NewProp_Weight_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_ItemTags = { "ItemTags", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemDefinition, ItemTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemTags_MetaData), NewProp_ItemTags_MetaData) }; // 3438578166
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_UseButtonText = { "UseButtonText", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemDefinition, UseButtonText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UseButtonText_MetaData), NewProp_UseButtonText_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_CannotUseReason = { "CannotUseReason", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemDefinition, CannotUseReason), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CannotUseReason_MetaData), NewProp_CannotUseReason_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_UseEffect = { "UseEffect", nullptr, (EPropertyFlags)0x011600000009001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemDefinition, UseEffect), Z_Construct_UClass_UInventoryItemUseEffect_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UseEffect_MetaData), NewProp_UseEffect_MetaData) };
void Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_bConsumeOnUse_SetBit(void* Obj)
{
	((UInventoryItemDefinition*)Obj)->bConsumeOnUse = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_bConsumeOnUse = { "bConsumeOnUse", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UInventoryItemDefinition), &Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_bConsumeOnUse_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bConsumeOnUse_MetaData), NewProp_bConsumeOnUse_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_ConsumeQuantity = { "ConsumeQuantity", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryItemDefinition, ConsumeQuantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConsumeQuantity_MetaData), NewProp_ConsumeQuantity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventoryItemDefinition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_ItemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_DisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_CategoryText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_FlavorText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_Icon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_InspectMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_WorldItemClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_InspectorData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_bCanUse,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_bCanDrop,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_bCanInspect,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_bStackable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_MaxStackSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_Weight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_ItemTags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_UseButtonText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_CannotUseReason,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_UseEffect,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_bConsumeOnUse,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryItemDefinition_Statics::NewProp_ConsumeQuantity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemDefinition_Statics::PropPointers) < 2048);
// ********** End Class UInventoryItemDefinition Property Definitions ******************************
UObject* (*const Z_Construct_UClass_UInventoryItemDefinition_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_InventorySystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemDefinition_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventoryItemDefinition_Statics::ClassParams = {
	&UInventoryItemDefinition::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UInventoryItemDefinition_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemDefinition_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryItemDefinition_Statics::Class_MetaDataParams), Z_Construct_UClass_UInventoryItemDefinition_Statics::Class_MetaDataParams)
};
void UInventoryItemDefinition::StaticRegisterNativesUInventoryItemDefinition()
{
	UClass* Class = UInventoryItemDefinition::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UInventoryItemDefinition_Statics::Funcs));
}
UClass* Z_Construct_UClass_UInventoryItemDefinition()
{
	if (!Z_Registration_Info_UClass_UInventoryItemDefinition.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventoryItemDefinition.OuterSingleton, Z_Construct_UClass_UInventoryItemDefinition_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInventoryItemDefinition.OuterSingleton;
}
UInventoryItemDefinition::UInventoryItemDefinition(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UInventoryItemDefinition);
UInventoryItemDefinition::~UInventoryItemDefinition() {}
// ********** End Class UInventoryItemDefinition ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemDefinition_h__Script_InventorySystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInventoryItemDefinition, UInventoryItemDefinition::StaticClass, TEXT("UInventoryItemDefinition"), &Z_Registration_Info_UClass_UInventoryItemDefinition, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventoryItemDefinition), 2919718966U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemDefinition_h__Script_InventorySystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemDefinition_h__Script_InventorySystem_1175672175{
	TEXT("/Script/InventorySystem"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemDefinition_h__Script_InventorySystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryItemDefinition_h__Script_InventorySystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
