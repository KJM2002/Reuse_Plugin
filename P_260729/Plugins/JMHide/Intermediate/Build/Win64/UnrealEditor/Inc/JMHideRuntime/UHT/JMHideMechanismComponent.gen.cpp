// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/JMHideMechanismComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMHideMechanismComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideMechanismComponent();
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideMechanismComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMHideRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMHideMechanismComponent ************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMHideMechanismComponent;
UClass* UJMHideMechanismComponent::GetPrivateStaticClass()
{
	using TClass = UJMHideMechanismComponent;
	if (!Z_Registration_Info_UClass_UJMHideMechanismComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMHideMechanismComponent"),
			Z_Registration_Info_UClass_UJMHideMechanismComponent.InnerSingleton,
			StaticRegisterNativesUJMHideMechanismComponent,
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
	return Z_Registration_Info_UClass_UJMHideMechanismComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMHideMechanismComponent_NoRegister()
{
	return UJMHideMechanismComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMHideMechanismComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JMHide" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Spot-side presentation boundary. It never changes Session or occupancy state. */" },
#endif
		{ "IncludePath", "Components/JMHideMechanismComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Components/JMHideMechanismComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spot-side presentation boundary. It never changes Session or occupancy state." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UJMHideMechanismComponent constinit property declarations ****************
// ********** End Class UJMHideMechanismComponent constinit property declarations ******************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMHideMechanismComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMHideMechanismComponent_Statics
UObject* (*const Z_Construct_UClass_UJMHideMechanismComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideMechanismComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMHideMechanismComponent_Statics::ClassParams = {
	&UJMHideMechanismComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B000A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideMechanismComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMHideMechanismComponent_Statics::Class_MetaDataParams)
};
void UJMHideMechanismComponent::StaticRegisterNativesUJMHideMechanismComponent()
{
}
UClass* Z_Construct_UClass_UJMHideMechanismComponent()
{
	if (!Z_Registration_Info_UClass_UJMHideMechanismComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMHideMechanismComponent.OuterSingleton, Z_Construct_UClass_UJMHideMechanismComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMHideMechanismComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMHideMechanismComponent);
UJMHideMechanismComponent::~UJMHideMechanismComponent() {}
// ********** End Class UJMHideMechanismComponent **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideMechanismComponent_h__Script_JMHideRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMHideMechanismComponent, UJMHideMechanismComponent::StaticClass, TEXT("UJMHideMechanismComponent"), &Z_Registration_Info_UClass_UJMHideMechanismComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMHideMechanismComponent), 1526470752U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideMechanismComponent_h__Script_JMHideRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideMechanismComponent_h__Script_JMHideRuntime_2392009974{
	TEXT("/Script/JMHideRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideMechanismComponent_h__Script_JMHideRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideMechanismComponent_h__Script_JMHideRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
