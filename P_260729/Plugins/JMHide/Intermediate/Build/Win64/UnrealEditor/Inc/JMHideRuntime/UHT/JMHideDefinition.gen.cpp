// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Data/JMHideDefinition.h"
#include "GameplayTagContainer.h"
#include "Types/JMHideTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMHideDefinition() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideDefinition();
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideDefinition_NoRegister();
JMHIDERUNTIME_API UEnum* Z_Construct_UEnum_JMHideRuntime_EJMHideSpotArchetype();
JMHIDERUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMHideConfigOverride();
UPackage* Z_Construct_UPackage__Script_JMHideRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMHideDefinition ********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMHideDefinition;
UClass* UJMHideDefinition::GetPrivateStaticClass()
{
	using TClass = UJMHideDefinition;
	if (!Z_Registration_Info_UClass_UJMHideDefinition.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMHideDefinition"),
			Z_Registration_Info_UClass_UJMHideDefinition.InnerSingleton,
			StaticRegisterNativesUJMHideDefinition,
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
	return Z_Registration_Info_UClass_UJMHideDefinition.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMHideDefinition_NoRegister()
{
	return UJMHideDefinition::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMHideDefinition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Data/JMHideDefinition.h" },
		{ "ModuleRelativePath", "Public/Data/JMHideDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Archetype_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Data/JMHideDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HideType_MetaData[] = {
		{ "Categories", "Hide.Type" },
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Data/JMHideDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConfigOverride_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Data/JMHideDefinition.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMHideDefinition constinit property declarations ************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Archetype_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Archetype;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HideType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ConfigOverride;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMHideDefinition constinit property declarations **************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMHideDefinition>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMHideDefinition_Statics

// ********** Begin Class UJMHideDefinition Property Definitions ***********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMHideDefinition_Statics::NewProp_Archetype_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMHideDefinition_Statics::NewProp_Archetype = { "Archetype", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMHideDefinition, Archetype), Z_Construct_UEnum_JMHideRuntime_EJMHideSpotArchetype, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Archetype_MetaData), NewProp_Archetype_MetaData) }; // 3499806852
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMHideDefinition_Statics::NewProp_HideType = { "HideType", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMHideDefinition, HideType), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HideType_MetaData), NewProp_HideType_MetaData) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMHideDefinition_Statics::NewProp_ConfigOverride = { "ConfigOverride", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMHideDefinition, ConfigOverride), Z_Construct_UScriptStruct_FJMHideConfigOverride, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConfigOverride_MetaData), NewProp_ConfigOverride_MetaData) }; // 2145498035
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMHideDefinition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideDefinition_Statics::NewProp_Archetype_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideDefinition_Statics::NewProp_Archetype,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideDefinition_Statics::NewProp_HideType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideDefinition_Statics::NewProp_ConfigOverride,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideDefinition_Statics::PropPointers) < 2048);
// ********** End Class UJMHideDefinition Property Definitions *************************************
UObject* (*const Z_Construct_UClass_UJMHideDefinition_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideDefinition_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMHideDefinition_Statics::ClassParams = {
	&UJMHideDefinition::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMHideDefinition_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideDefinition_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideDefinition_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMHideDefinition_Statics::Class_MetaDataParams)
};
void UJMHideDefinition::StaticRegisterNativesUJMHideDefinition()
{
}
UClass* Z_Construct_UClass_UJMHideDefinition()
{
	if (!Z_Registration_Info_UClass_UJMHideDefinition.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMHideDefinition.OuterSingleton, Z_Construct_UClass_UJMHideDefinition_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMHideDefinition.OuterSingleton;
}
UJMHideDefinition::UJMHideDefinition(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMHideDefinition);
UJMHideDefinition::~UJMHideDefinition() {}
// ********** End Class UJMHideDefinition **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Data_JMHideDefinition_h__Script_JMHideRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMHideDefinition, UJMHideDefinition::StaticClass, TEXT("UJMHideDefinition"), &Z_Registration_Info_UClass_UJMHideDefinition, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMHideDefinition), 1898513169U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Data_JMHideDefinition_h__Script_JMHideRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Data_JMHideDefinition_h__Script_JMHideRuntime_3443042285{
	TEXT("/Script/JMHideRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Data_JMHideDefinition_h__Script_JMHideRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Data_JMHideDefinition_h__Script_JMHideRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
