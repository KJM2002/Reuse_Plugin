// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "World/InventoryWorldItemPickup.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeInventoryWorldItemPickup() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_AInventoryWorldItemPickup();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_AInventoryWorldItemPickup_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemDefinition_NoRegister();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractableInterface_NoRegister();
UPackage* Z_Construct_UPackage__Script_InventorySystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AInventoryWorldItemPickup Function InitializePickup **********************
struct Z_Construct_UFunction_AInventoryWorldItemPickup_InitializePickup_Statics
{
	struct InventoryWorldItemPickup_eventInitializePickup_Parms
	{
		UInventoryItemDefinition* InItemDefinition;
		int32 InQuantity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "CPP_Default_InQuantity", "1" },
		{ "ModuleRelativePath", "Public/World/InventoryWorldItemPickup.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function InitializePickup constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InItemDefinition;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InQuantity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InitializePickup constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InitializePickup Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AInventoryWorldItemPickup_InitializePickup_Statics::NewProp_InItemDefinition = { "InItemDefinition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryWorldItemPickup_eventInitializePickup_Parms, InItemDefinition), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AInventoryWorldItemPickup_InitializePickup_Statics::NewProp_InQuantity = { "InQuantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryWorldItemPickup_eventInitializePickup_Parms, InQuantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AInventoryWorldItemPickup_InitializePickup_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AInventoryWorldItemPickup_InitializePickup_Statics::NewProp_InItemDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AInventoryWorldItemPickup_InitializePickup_Statics::NewProp_InQuantity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AInventoryWorldItemPickup_InitializePickup_Statics::PropPointers) < 2048);
// ********** End Function InitializePickup Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AInventoryWorldItemPickup_InitializePickup_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AInventoryWorldItemPickup, nullptr, "InitializePickup", 	Z_Construct_UFunction_AInventoryWorldItemPickup_InitializePickup_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AInventoryWorldItemPickup_InitializePickup_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AInventoryWorldItemPickup_InitializePickup_Statics::InventoryWorldItemPickup_eventInitializePickup_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AInventoryWorldItemPickup_InitializePickup_Statics::Function_MetaDataParams), Z_Construct_UFunction_AInventoryWorldItemPickup_InitializePickup_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AInventoryWorldItemPickup_InitializePickup_Statics::InventoryWorldItemPickup_eventInitializePickup_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AInventoryWorldItemPickup_InitializePickup()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AInventoryWorldItemPickup_InitializePickup_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AInventoryWorldItemPickup::execInitializePickup)
{
	P_GET_OBJECT(UInventoryItemDefinition,Z_Param_InItemDefinition);
	P_GET_PROPERTY(FIntProperty,Z_Param_InQuantity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializePickup(Z_Param_InItemDefinition,Z_Param_InQuantity);
	P_NATIVE_END;
}
// ********** End Class AInventoryWorldItemPickup Function InitializePickup ************************

// ********** Begin Class AInventoryWorldItemPickup Function OnPickupStateChanged ******************
static FName NAME_AInventoryWorldItemPickup_OnPickupStateChanged = FName(TEXT("OnPickupStateChanged"));
void AInventoryWorldItemPickup::OnPickupStateChanged()
{
	UFunction* Func = FindFunctionChecked(NAME_AInventoryWorldItemPickup_OnPickupStateChanged);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		OnPickupStateChanged_Implementation();
	}
}
struct Z_Construct_UFunction_AInventoryWorldItemPickup_OnPickupStateChanged_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/World/InventoryWorldItemPickup.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnPickupStateChanged constinit property declarations ******************
// ********** End Function OnPickupStateChanged constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AInventoryWorldItemPickup_OnPickupStateChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AInventoryWorldItemPickup, nullptr, "OnPickupStateChanged", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AInventoryWorldItemPickup_OnPickupStateChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_AInventoryWorldItemPickup_OnPickupStateChanged_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AInventoryWorldItemPickup_OnPickupStateChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AInventoryWorldItemPickup_OnPickupStateChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AInventoryWorldItemPickup::execOnPickupStateChanged)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnPickupStateChanged_Implementation();
	P_NATIVE_END;
}
// ********** End Class AInventoryWorldItemPickup Function OnPickupStateChanged ********************

// ********** Begin Class AInventoryWorldItemPickup Function SnapToGround **************************
struct Z_Construct_UFunction_AInventoryWorldItemPickup_SnapToGround_Statics
{
	struct InventoryWorldItemPickup_eventSnapToGround_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|World" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xed\x98\x84\xec\x9e\xac Mesh Bounds\xec\x9d\x98 \xec\xb5\x9c\xed\x95\x98\xeb\x8b\xa8\xec\x9d\xb4 \xeb\xb0\x94\xeb\x8b\xa5\xec\x97\x90 \xeb\x8b\xbf\xeb\x8f\x84\xeb\xa1\x9d Actor \xeb\x86\x92\xec\x9d\xb4\xeb\xa5\xbc \xeb\xb3\xb4\xec\xa0\x95\xed\x95\x9c\xeb\x8b\xa4. */" },
#endif
		{ "ModuleRelativePath", "Public/World/InventoryWorldItemPickup.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x98\x84\xec\x9e\xac Mesh Bounds\xec\x9d\x98 \xec\xb5\x9c\xed\x95\x98\xeb\x8b\xa8\xec\x9d\xb4 \xeb\xb0\x94\xeb\x8b\xa5\xec\x97\x90 \xeb\x8b\xbf\xeb\x8f\x84\xeb\xa1\x9d Actor \xeb\x86\x92\xec\x9d\xb4\xeb\xa5\xbc \xeb\xb3\xb4\xec\xa0\x95\xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SnapToGround constinit property declarations **************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SnapToGround constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SnapToGround Property Definitions *************************************
void Z_Construct_UFunction_AInventoryWorldItemPickup_SnapToGround_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventoryWorldItemPickup_eventSnapToGround_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AInventoryWorldItemPickup_SnapToGround_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventoryWorldItemPickup_eventSnapToGround_Parms), &Z_Construct_UFunction_AInventoryWorldItemPickup_SnapToGround_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AInventoryWorldItemPickup_SnapToGround_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AInventoryWorldItemPickup_SnapToGround_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AInventoryWorldItemPickup_SnapToGround_Statics::PropPointers) < 2048);
// ********** End Function SnapToGround Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AInventoryWorldItemPickup_SnapToGround_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AInventoryWorldItemPickup, nullptr, "SnapToGround", 	Z_Construct_UFunction_AInventoryWorldItemPickup_SnapToGround_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AInventoryWorldItemPickup_SnapToGround_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AInventoryWorldItemPickup_SnapToGround_Statics::InventoryWorldItemPickup_eventSnapToGround_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AInventoryWorldItemPickup_SnapToGround_Statics::Function_MetaDataParams), Z_Construct_UFunction_AInventoryWorldItemPickup_SnapToGround_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AInventoryWorldItemPickup_SnapToGround_Statics::InventoryWorldItemPickup_eventSnapToGround_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AInventoryWorldItemPickup_SnapToGround()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AInventoryWorldItemPickup_SnapToGround_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AInventoryWorldItemPickup::execSnapToGround)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SnapToGround();
	P_NATIVE_END;
}
// ********** End Class AInventoryWorldItemPickup Function SnapToGround ****************************

// ********** Begin Class AInventoryWorldItemPickup Function TryPickup *****************************
struct Z_Construct_UFunction_AInventoryWorldItemPickup_TryPickup_Statics
{
	struct InventoryWorldItemPickup_eventTryPickup_Parms
	{
		AActor* InteractingActor;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/World/InventoryWorldItemPickup.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function TryPickup constinit property declarations *****************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InteractingActor;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TryPickup constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TryPickup Property Definitions ****************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AInventoryWorldItemPickup_TryPickup_Statics::NewProp_InteractingActor = { "InteractingActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryWorldItemPickup_eventTryPickup_Parms, InteractingActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AInventoryWorldItemPickup_TryPickup_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((InventoryWorldItemPickup_eventTryPickup_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AInventoryWorldItemPickup_TryPickup_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(InventoryWorldItemPickup_eventTryPickup_Parms), &Z_Construct_UFunction_AInventoryWorldItemPickup_TryPickup_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AInventoryWorldItemPickup_TryPickup_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AInventoryWorldItemPickup_TryPickup_Statics::NewProp_InteractingActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AInventoryWorldItemPickup_TryPickup_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AInventoryWorldItemPickup_TryPickup_Statics::PropPointers) < 2048);
// ********** End Function TryPickup Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AInventoryWorldItemPickup_TryPickup_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AInventoryWorldItemPickup, nullptr, "TryPickup", 	Z_Construct_UFunction_AInventoryWorldItemPickup_TryPickup_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AInventoryWorldItemPickup_TryPickup_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AInventoryWorldItemPickup_TryPickup_Statics::InventoryWorldItemPickup_eventTryPickup_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AInventoryWorldItemPickup_TryPickup_Statics::Function_MetaDataParams), Z_Construct_UFunction_AInventoryWorldItemPickup_TryPickup_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AInventoryWorldItemPickup_TryPickup_Statics::InventoryWorldItemPickup_eventTryPickup_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AInventoryWorldItemPickup_TryPickup()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AInventoryWorldItemPickup_TryPickup_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AInventoryWorldItemPickup::execTryPickup)
{
	P_GET_OBJECT(AActor,Z_Param_InteractingActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->TryPickup(Z_Param_InteractingActor);
	P_NATIVE_END;
}
// ********** End Class AInventoryWorldItemPickup Function TryPickup *******************************

// ********** Begin Class AInventoryWorldItemPickup ************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AInventoryWorldItemPickup;
UClass* AInventoryWorldItemPickup::GetPrivateStaticClass()
{
	using TClass = AInventoryWorldItemPickup;
	if (!Z_Registration_Info_UClass_AInventoryWorldItemPickup.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("InventoryWorldItemPickup"),
			Z_Registration_Info_UClass_AInventoryWorldItemPickup.InnerSingleton,
			StaticRegisterNativesAInventoryWorldItemPickup,
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
	return Z_Registration_Info_UClass_AInventoryWorldItemPickup.InnerSingleton;
}
UClass* Z_Construct_UClass_AInventoryWorldItemPickup_NoRegister()
{
	return AInventoryWorldItemPickup::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AInventoryWorldItemPickup_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "World/InventoryWorldItemPickup.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/World/InventoryWorldItemPickup.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneRoot_MetaData[] = {
		{ "Category", "Inventory" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/World/InventoryWorldItemPickup.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemMesh_MetaData[] = {
		{ "Category", "Inventory" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/World/InventoryWorldItemPickup.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemDefinition_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/World/InventoryWorldItemPickup.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quantity_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/World/InventoryWorldItemPickup.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PickupInteractionPrompt_MetaData[] = {
		{ "Category", "Inventory|Interaction" },
		{ "ModuleRelativePath", "Public/World/InventoryWorldItemPickup.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PickupInteractionPriority_MetaData[] = {
		{ "Category", "Inventory|Interaction" },
		{ "ModuleRelativePath", "Public/World/InventoryWorldItemPickup.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSnapToGroundWhenDropped_MetaData[] = {
		{ "Category", "Inventory|World" },
		{ "ModuleRelativePath", "Public/World/InventoryWorldItemPickup.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GroundClearance_MetaData[] = {
		{ "Category", "Inventory|World" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/World/InventoryWorldItemPickup.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AInventoryWorldItemPickup constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneRoot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemDefinition;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FTextPropertyParams NewProp_PickupInteractionPrompt;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PickupInteractionPriority;
	static void NewProp_bSnapToGroundWhenDropped_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSnapToGroundWhenDropped;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GroundClearance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AInventoryWorldItemPickup constinit property declarations ******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("InitializePickup"), .Pointer = &AInventoryWorldItemPickup::execInitializePickup },
		{ .NameUTF8 = UTF8TEXT("OnPickupStateChanged"), .Pointer = &AInventoryWorldItemPickup::execOnPickupStateChanged },
		{ .NameUTF8 = UTF8TEXT("SnapToGround"), .Pointer = &AInventoryWorldItemPickup::execSnapToGround },
		{ .NameUTF8 = UTF8TEXT("TryPickup"), .Pointer = &AInventoryWorldItemPickup::execTryPickup },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AInventoryWorldItemPickup_InitializePickup, "InitializePickup" }, // 3748035826
		{ &Z_Construct_UFunction_AInventoryWorldItemPickup_OnPickupStateChanged, "OnPickupStateChanged" }, // 3856743725
		{ &Z_Construct_UFunction_AInventoryWorldItemPickup_SnapToGround, "SnapToGround" }, // 2285090716
		{ &Z_Construct_UFunction_AInventoryWorldItemPickup_TryPickup, "TryPickup" }, // 965458195
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AInventoryWorldItemPickup>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AInventoryWorldItemPickup_Statics

// ********** Begin Class AInventoryWorldItemPickup Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AInventoryWorldItemPickup_Statics::NewProp_SceneRoot = { "SceneRoot", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AInventoryWorldItemPickup, SceneRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneRoot_MetaData), NewProp_SceneRoot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AInventoryWorldItemPickup_Statics::NewProp_ItemMesh = { "ItemMesh", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AInventoryWorldItemPickup, ItemMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemMesh_MetaData), NewProp_ItemMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AInventoryWorldItemPickup_Statics::NewProp_ItemDefinition = { "ItemDefinition", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AInventoryWorldItemPickup, ItemDefinition), Z_Construct_UClass_UInventoryItemDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemDefinition_MetaData), NewProp_ItemDefinition_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AInventoryWorldItemPickup_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AInventoryWorldItemPickup, Quantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quantity_MetaData), NewProp_Quantity_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_AInventoryWorldItemPickup_Statics::NewProp_PickupInteractionPrompt = { "PickupInteractionPrompt", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AInventoryWorldItemPickup, PickupInteractionPrompt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PickupInteractionPrompt_MetaData), NewProp_PickupInteractionPrompt_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AInventoryWorldItemPickup_Statics::NewProp_PickupInteractionPriority = { "PickupInteractionPriority", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AInventoryWorldItemPickup, PickupInteractionPriority), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PickupInteractionPriority_MetaData), NewProp_PickupInteractionPriority_MetaData) };
void Z_Construct_UClass_AInventoryWorldItemPickup_Statics::NewProp_bSnapToGroundWhenDropped_SetBit(void* Obj)
{
	((AInventoryWorldItemPickup*)Obj)->bSnapToGroundWhenDropped = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AInventoryWorldItemPickup_Statics::NewProp_bSnapToGroundWhenDropped = { "bSnapToGroundWhenDropped", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AInventoryWorldItemPickup), &Z_Construct_UClass_AInventoryWorldItemPickup_Statics::NewProp_bSnapToGroundWhenDropped_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSnapToGroundWhenDropped_MetaData), NewProp_bSnapToGroundWhenDropped_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AInventoryWorldItemPickup_Statics::NewProp_GroundClearance = { "GroundClearance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AInventoryWorldItemPickup, GroundClearance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GroundClearance_MetaData), NewProp_GroundClearance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AInventoryWorldItemPickup_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInventoryWorldItemPickup_Statics::NewProp_SceneRoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInventoryWorldItemPickup_Statics::NewProp_ItemMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInventoryWorldItemPickup_Statics::NewProp_ItemDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInventoryWorldItemPickup_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInventoryWorldItemPickup_Statics::NewProp_PickupInteractionPrompt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInventoryWorldItemPickup_Statics::NewProp_PickupInteractionPriority,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInventoryWorldItemPickup_Statics::NewProp_bSnapToGroundWhenDropped,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInventoryWorldItemPickup_Statics::NewProp_GroundClearance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AInventoryWorldItemPickup_Statics::PropPointers) < 2048);
// ********** End Class AInventoryWorldItemPickup Property Definitions *****************************
UObject* (*const Z_Construct_UClass_AInventoryWorldItemPickup_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_InventorySystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AInventoryWorldItemPickup_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AInventoryWorldItemPickup_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UJMInteractableInterface_NoRegister, (int32)VTABLE_OFFSET(AInventoryWorldItemPickup, IJMInteractableInterface), false },  // 680874699
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_AInventoryWorldItemPickup_Statics::ClassParams = {
	&AInventoryWorldItemPickup::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AInventoryWorldItemPickup_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AInventoryWorldItemPickup_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AInventoryWorldItemPickup_Statics::Class_MetaDataParams), Z_Construct_UClass_AInventoryWorldItemPickup_Statics::Class_MetaDataParams)
};
void AInventoryWorldItemPickup::StaticRegisterNativesAInventoryWorldItemPickup()
{
	UClass* Class = AInventoryWorldItemPickup::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AInventoryWorldItemPickup_Statics::Funcs));
}
UClass* Z_Construct_UClass_AInventoryWorldItemPickup()
{
	if (!Z_Registration_Info_UClass_AInventoryWorldItemPickup.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AInventoryWorldItemPickup.OuterSingleton, Z_Construct_UClass_AInventoryWorldItemPickup_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AInventoryWorldItemPickup.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AInventoryWorldItemPickup);
AInventoryWorldItemPickup::~AInventoryWorldItemPickup() {}
// ********** End Class AInventoryWorldItemPickup **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_World_InventoryWorldItemPickup_h__Script_InventorySystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AInventoryWorldItemPickup, AInventoryWorldItemPickup::StaticClass, TEXT("AInventoryWorldItemPickup"), &Z_Registration_Info_UClass_AInventoryWorldItemPickup, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AInventoryWorldItemPickup), 2121724970U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_World_InventoryWorldItemPickup_h__Script_InventorySystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_World_InventoryWorldItemPickup_h__Script_InventorySystem_4251345339{
	TEXT("/Script/InventorySystem"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_World_InventoryWorldItemPickup_h__Script_InventorySystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_World_InventoryWorldItemPickup_h__Script_InventorySystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
