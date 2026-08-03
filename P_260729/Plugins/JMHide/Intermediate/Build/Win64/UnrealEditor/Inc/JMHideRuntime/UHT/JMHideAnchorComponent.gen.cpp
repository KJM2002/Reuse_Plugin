// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/JMHideAnchorComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMHideAnchorComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideAnchorComponent();
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideAnchorComponent_NoRegister();
JMHIDERUNTIME_API UEnum* Z_Construct_UEnum_JMHideRuntime_EJMHideAnchorRole();
UPackage* Z_Construct_UPackage__Script_JMHideRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMHideAnchorComponent ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMHideAnchorComponent;
UClass* UJMHideAnchorComponent::GetPrivateStaticClass()
{
	using TClass = UJMHideAnchorComponent;
	if (!Z_Registration_Info_UClass_UJMHideAnchorComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMHideAnchorComponent"),
			Z_Registration_Info_UClass_UJMHideAnchorComponent.InnerSingleton,
			StaticRegisterNativesUJMHideAnchorComponent,
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
	return Z_Registration_Info_UClass_UJMHideAnchorComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMHideAnchorComponent_NoRegister()
{
	return UJMHideAnchorComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMHideAnchorComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JMHide" },
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "Components/JMHideAnchorComponent.h" },
		{ "ModuleRelativePath", "Public/Components/JMHideAnchorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Role_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Components/JMHideAnchorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMHideAnchorComponent constinit property declarations *******************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Role_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Role;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMHideAnchorComponent constinit property declarations *********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMHideAnchorComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMHideAnchorComponent_Statics

// ********** Begin Class UJMHideAnchorComponent Property Definitions ******************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMHideAnchorComponent_Statics::NewProp_Role_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMHideAnchorComponent_Statics::NewProp_Role = { "Role", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMHideAnchorComponent, Role), Z_Construct_UEnum_JMHideRuntime_EJMHideAnchorRole, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Role_MetaData), NewProp_Role_MetaData) }; // 3406772772
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMHideAnchorComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideAnchorComponent_Statics::NewProp_Role_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideAnchorComponent_Statics::NewProp_Role,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideAnchorComponent_Statics::PropPointers) < 2048);
// ********** End Class UJMHideAnchorComponent Property Definitions ********************************
UObject* (*const Z_Construct_UClass_UJMHideAnchorComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USceneComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideAnchorComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMHideAnchorComponent_Statics::ClassParams = {
	&UJMHideAnchorComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMHideAnchorComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideAnchorComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideAnchorComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMHideAnchorComponent_Statics::Class_MetaDataParams)
};
void UJMHideAnchorComponent::StaticRegisterNativesUJMHideAnchorComponent()
{
}
UClass* Z_Construct_UClass_UJMHideAnchorComponent()
{
	if (!Z_Registration_Info_UClass_UJMHideAnchorComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMHideAnchorComponent.OuterSingleton, Z_Construct_UClass_UJMHideAnchorComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMHideAnchorComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMHideAnchorComponent);
UJMHideAnchorComponent::~UJMHideAnchorComponent() {}
// ********** End Class UJMHideAnchorComponent *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideAnchorComponent_h__Script_JMHideRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMHideAnchorComponent, UJMHideAnchorComponent::StaticClass, TEXT("UJMHideAnchorComponent"), &Z_Registration_Info_UClass_UJMHideAnchorComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMHideAnchorComponent), 685601109U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideAnchorComponent_h__Script_JMHideRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideAnchorComponent_h__Script_JMHideRuntime_3711768463{
	TEXT("/Script/JMHideRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideAnchorComponent_h__Script_JMHideRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideAnchorComponent_h__Script_JMHideRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
