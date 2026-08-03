// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Items/InventoryUseOnActorComponentsEffect.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeInventoryUseOnActorComponentsEffect() {}

// ********** Begin Cross Module References ********************************************************
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemUseEffect();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryUseOnActorComponentsEffect();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryUseOnActorComponentsEffect_NoRegister();
UPackage* Z_Construct_UPackage__Script_InventorySystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UInventoryUseOnActorComponentsEffect *************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UInventoryUseOnActorComponentsEffect;
UClass* UInventoryUseOnActorComponentsEffect::GetPrivateStaticClass()
{
	using TClass = UInventoryUseOnActorComponentsEffect;
	if (!Z_Registration_Info_UClass_UInventoryUseOnActorComponentsEffect.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("InventoryUseOnActorComponentsEffect"),
			Z_Registration_Info_UClass_UInventoryUseOnActorComponentsEffect.InnerSingleton,
			StaticRegisterNativesUInventoryUseOnActorComponentsEffect,
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
	return Z_Registration_Info_UClass_UInventoryUseOnActorComponentsEffect.InnerSingleton;
}
UClass* Z_Construct_UClass_UInventoryUseOnActorComponentsEffect_NoRegister()
{
	return UInventoryUseOnActorComponentsEffect::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UInventoryUseOnActorComponentsEffect_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Routes an item's Use button to a compatible receiver component on the user. */" },
#endif
		{ "IncludePath", "Items/InventoryUseOnActorComponentsEffect.h" },
		{ "ModuleRelativePath", "Public/Items/InventoryUseOnActorComponentsEffect.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Routes an item's Use button to a compatible receiver component on the user." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UInventoryUseOnActorComponentsEffect constinit property declarations *****
// ********** End Class UInventoryUseOnActorComponentsEffect constinit property declarations *******
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryUseOnActorComponentsEffect>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UInventoryUseOnActorComponentsEffect_Statics
UObject* (*const Z_Construct_UClass_UInventoryUseOnActorComponentsEffect_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInventoryItemUseEffect,
	(UObject* (*)())Z_Construct_UPackage__Script_InventorySystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryUseOnActorComponentsEffect_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventoryUseOnActorComponentsEffect_Statics::ClassParams = {
	&UInventoryUseOnActorComponentsEffect::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x003010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryUseOnActorComponentsEffect_Statics::Class_MetaDataParams), Z_Construct_UClass_UInventoryUseOnActorComponentsEffect_Statics::Class_MetaDataParams)
};
void UInventoryUseOnActorComponentsEffect::StaticRegisterNativesUInventoryUseOnActorComponentsEffect()
{
}
UClass* Z_Construct_UClass_UInventoryUseOnActorComponentsEffect()
{
	if (!Z_Registration_Info_UClass_UInventoryUseOnActorComponentsEffect.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventoryUseOnActorComponentsEffect.OuterSingleton, Z_Construct_UClass_UInventoryUseOnActorComponentsEffect_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInventoryUseOnActorComponentsEffect.OuterSingleton;
}
UInventoryUseOnActorComponentsEffect::UInventoryUseOnActorComponentsEffect(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UInventoryUseOnActorComponentsEffect);
UInventoryUseOnActorComponentsEffect::~UInventoryUseOnActorComponentsEffect() {}
// ********** End Class UInventoryUseOnActorComponentsEffect ***************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryUseOnActorComponentsEffect_h__Script_InventorySystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInventoryUseOnActorComponentsEffect, UInventoryUseOnActorComponentsEffect::StaticClass, TEXT("UInventoryUseOnActorComponentsEffect"), &Z_Registration_Info_UClass_UInventoryUseOnActorComponentsEffect, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventoryUseOnActorComponentsEffect), 2513633374U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryUseOnActorComponentsEffect_h__Script_InventorySystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryUseOnActorComponentsEffect_h__Script_InventorySystem_121844015{
	TEXT("/Script/InventorySystem"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryUseOnActorComponentsEffect_h__Script_InventorySystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Items_InventoryUseOnActorComponentsEffect_h__Script_InventorySystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
