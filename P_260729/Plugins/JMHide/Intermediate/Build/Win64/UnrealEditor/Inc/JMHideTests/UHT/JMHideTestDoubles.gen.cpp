// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Tests/JMHideTestDoubles.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMHideTestDoubles() {}

// ********** Begin Cross Module References ********************************************************
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideMechanismComponent();
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideParticipantDriverComponent();
JMHIDETESTS_API UClass* Z_Construct_UClass_UJMHideTestDriverComponent();
JMHIDETESTS_API UClass* Z_Construct_UClass_UJMHideTestDriverComponent_NoRegister();
JMHIDETESTS_API UClass* Z_Construct_UClass_UJMHideTestMechanismComponent();
JMHIDETESTS_API UClass* Z_Construct_UClass_UJMHideTestMechanismComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMHideTests();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMHideTestDriverComponent ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMHideTestDriverComponent;
UClass* UJMHideTestDriverComponent::GetPrivateStaticClass()
{
	using TClass = UJMHideTestDriverComponent;
	if (!Z_Registration_Info_UClass_UJMHideTestDriverComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMHideTestDriverComponent"),
			Z_Registration_Info_UClass_UJMHideTestDriverComponent.InnerSingleton,
			StaticRegisterNativesUJMHideTestDriverComponent,
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
	return Z_Registration_Info_UClass_UJMHideTestDriverComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMHideTestDriverComponent_NoRegister()
{
	return UJMHideTestDriverComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMHideTestDriverComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Tests/JMHideTestDoubles.h" },
		{ "ModuleRelativePath", "Private/Tests/JMHideTestDoubles.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMHideTestDriverComponent constinit property declarations ***************
// ********** End Class UJMHideTestDriverComponent constinit property declarations *****************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMHideTestDriverComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMHideTestDriverComponent_Statics
UObject* (*const Z_Construct_UClass_UJMHideTestDriverComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UJMHideParticipantDriverComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideTests,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideTestDriverComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMHideTestDriverComponent_Statics::ClassParams = {
	&UJMHideTestDriverComponent::StaticClass,
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
	0x00A000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideTestDriverComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMHideTestDriverComponent_Statics::Class_MetaDataParams)
};
void UJMHideTestDriverComponent::StaticRegisterNativesUJMHideTestDriverComponent()
{
}
UClass* Z_Construct_UClass_UJMHideTestDriverComponent()
{
	if (!Z_Registration_Info_UClass_UJMHideTestDriverComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMHideTestDriverComponent.OuterSingleton, Z_Construct_UClass_UJMHideTestDriverComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMHideTestDriverComponent.OuterSingleton;
}
UJMHideTestDriverComponent::UJMHideTestDriverComponent() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMHideTestDriverComponent);
UJMHideTestDriverComponent::~UJMHideTestDriverComponent() {}
// ********** End Class UJMHideTestDriverComponent *************************************************

// ********** Begin Class UJMHideTestMechanismComponent ********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMHideTestMechanismComponent;
UClass* UJMHideTestMechanismComponent::GetPrivateStaticClass()
{
	using TClass = UJMHideTestMechanismComponent;
	if (!Z_Registration_Info_UClass_UJMHideTestMechanismComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMHideTestMechanismComponent"),
			Z_Registration_Info_UClass_UJMHideTestMechanismComponent.InnerSingleton,
			StaticRegisterNativesUJMHideTestMechanismComponent,
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
	return Z_Registration_Info_UClass_UJMHideTestMechanismComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMHideTestMechanismComponent_NoRegister()
{
	return UJMHideTestMechanismComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMHideTestMechanismComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Tests/JMHideTestDoubles.h" },
		{ "ModuleRelativePath", "Private/Tests/JMHideTestDoubles.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMHideTestMechanismComponent constinit property declarations ************
// ********** End Class UJMHideTestMechanismComponent constinit property declarations **************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMHideTestMechanismComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMHideTestMechanismComponent_Statics
UObject* (*const Z_Construct_UClass_UJMHideTestMechanismComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UJMHideMechanismComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideTests,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideTestMechanismComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMHideTestMechanismComponent_Statics::ClassParams = {
	&UJMHideTestMechanismComponent::StaticClass,
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
	0x00A000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideTestMechanismComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMHideTestMechanismComponent_Statics::Class_MetaDataParams)
};
void UJMHideTestMechanismComponent::StaticRegisterNativesUJMHideTestMechanismComponent()
{
}
UClass* Z_Construct_UClass_UJMHideTestMechanismComponent()
{
	if (!Z_Registration_Info_UClass_UJMHideTestMechanismComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMHideTestMechanismComponent.OuterSingleton, Z_Construct_UClass_UJMHideTestMechanismComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMHideTestMechanismComponent.OuterSingleton;
}
UJMHideTestMechanismComponent::UJMHideTestMechanismComponent() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMHideTestMechanismComponent);
UJMHideTestMechanismComponent::~UJMHideTestMechanismComponent() {}
// ********** End Class UJMHideTestMechanismComponent **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideTests_Private_Tests_JMHideTestDoubles_h__Script_JMHideTests_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMHideTestDriverComponent, UJMHideTestDriverComponent::StaticClass, TEXT("UJMHideTestDriverComponent"), &Z_Registration_Info_UClass_UJMHideTestDriverComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMHideTestDriverComponent), 2282420772U) },
		{ Z_Construct_UClass_UJMHideTestMechanismComponent, UJMHideTestMechanismComponent::StaticClass, TEXT("UJMHideTestMechanismComponent"), &Z_Registration_Info_UClass_UJMHideTestMechanismComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMHideTestMechanismComponent), 3973817882U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideTests_Private_Tests_JMHideTestDoubles_h__Script_JMHideTests_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideTests_Private_Tests_JMHideTestDoubles_h__Script_JMHideTests_433643175{
	TEXT("/Script/JMHideTests"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideTests_Private_Tests_JMHideTestDoubles_h__Script_JMHideTests_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideTests_Private_Tests_JMHideTestDoubles_h__Script_JMHideTests_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
