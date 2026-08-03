// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JMThrowableInventoryUseEffect.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMThrowableInventoryUseEffect() {}

// ********** Begin Cross Module References ********************************************************
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemUseEffect();
JMTHROWABLE_API UClass* Z_Construct_UClass_UJMThrowableDefinition_NoRegister();
JMTHROWABLEGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMThrowableInventoryUseEffect();
JMTHROWABLEGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMThrowableInventoryUseEffect_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMThrowableGameplayIntegration();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMThrowableInventoryUseEffect *******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMThrowableInventoryUseEffect;
UClass* UJMThrowableInventoryUseEffect::GetPrivateStaticClass()
{
	using TClass = UJMThrowableInventoryUseEffect;
	if (!Z_Registration_Info_UClass_UJMThrowableInventoryUseEffect.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMThrowableInventoryUseEffect"),
			Z_Registration_Info_UClass_UJMThrowableInventoryUseEffect.InnerSingleton,
			StaticRegisterNativesUJMThrowableInventoryUseEffect,
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
	return Z_Registration_Info_UClass_UJMThrowableInventoryUseEffect.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMThrowableInventoryUseEffect_NoRegister()
{
	return UJMThrowableInventoryUseEffect::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMThrowableInventoryUseEffect_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "JMThrowableInventoryUseEffect.h" },
		{ "ModuleRelativePath", "Public/JMThrowableInventoryUseEffect.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThrowableDefinition_MetaData[] = {
		{ "Category", "Throwable" },
		{ "ModuleRelativePath", "Public/JMThrowableInventoryUseEffect.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMThrowableInventoryUseEffect constinit property declarations ***********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ThrowableDefinition;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMThrowableInventoryUseEffect constinit property declarations *************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMThrowableInventoryUseEffect>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMThrowableInventoryUseEffect_Statics

// ********** Begin Class UJMThrowableInventoryUseEffect Property Definitions **********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMThrowableInventoryUseEffect_Statics::NewProp_ThrowableDefinition = { "ThrowableDefinition", nullptr, (EPropertyFlags)0x0114000000010015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableInventoryUseEffect, ThrowableDefinition), Z_Construct_UClass_UJMThrowableDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThrowableDefinition_MetaData), NewProp_ThrowableDefinition_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMThrowableInventoryUseEffect_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableInventoryUseEffect_Statics::NewProp_ThrowableDefinition,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableInventoryUseEffect_Statics::PropPointers) < 2048);
// ********** End Class UJMThrowableInventoryUseEffect Property Definitions ************************
UObject* (*const Z_Construct_UClass_UJMThrowableInventoryUseEffect_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInventoryItemUseEffect,
	(UObject* (*)())Z_Construct_UPackage__Script_JMThrowableGameplayIntegration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableInventoryUseEffect_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMThrowableInventoryUseEffect_Statics::ClassParams = {
	&UJMThrowableInventoryUseEffect::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMThrowableInventoryUseEffect_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableInventoryUseEffect_Statics::PropPointers),
	0,
	0x003010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableInventoryUseEffect_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMThrowableInventoryUseEffect_Statics::Class_MetaDataParams)
};
void UJMThrowableInventoryUseEffect::StaticRegisterNativesUJMThrowableInventoryUseEffect()
{
}
UClass* Z_Construct_UClass_UJMThrowableInventoryUseEffect()
{
	if (!Z_Registration_Info_UClass_UJMThrowableInventoryUseEffect.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMThrowableInventoryUseEffect.OuterSingleton, Z_Construct_UClass_UJMThrowableInventoryUseEffect_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMThrowableInventoryUseEffect.OuterSingleton;
}
UJMThrowableInventoryUseEffect::UJMThrowableInventoryUseEffect(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMThrowableInventoryUseEffect);
UJMThrowableInventoryUseEffect::~UJMThrowableInventoryUseEffect() {}
// ********** End Class UJMThrowableInventoryUseEffect *********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableInventoryUseEffect_h__Script_JMThrowableGameplayIntegration_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMThrowableInventoryUseEffect, UJMThrowableInventoryUseEffect::StaticClass, TEXT("UJMThrowableInventoryUseEffect"), &Z_Registration_Info_UClass_UJMThrowableInventoryUseEffect, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMThrowableInventoryUseEffect), 4212042050U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableInventoryUseEffect_h__Script_JMThrowableGameplayIntegration_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableInventoryUseEffect_h__Script_JMThrowableGameplayIntegration_2221083560{
	TEXT("/Script/JMThrowableGameplayIntegration"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableInventoryUseEffect_h__Script_JMThrowableGameplayIntegration_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableInventoryUseEffect_h__Script_JMThrowableGameplayIntegration_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
