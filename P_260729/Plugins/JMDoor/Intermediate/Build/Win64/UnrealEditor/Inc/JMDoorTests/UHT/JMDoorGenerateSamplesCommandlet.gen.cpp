// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Commandlets/JMDoorGenerateSamplesCommandlet.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMDoorGenerateSamplesCommandlet() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UCommandlet();
JMDOORTESTS_API UClass* Z_Construct_UClass_UJMDoorGenerateSamplesCommandlet();
JMDOORTESTS_API UClass* Z_Construct_UClass_UJMDoorGenerateSamplesCommandlet_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMDoorTests();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMDoorGenerateSamplesCommandlet *****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMDoorGenerateSamplesCommandlet;
UClass* UJMDoorGenerateSamplesCommandlet::GetPrivateStaticClass()
{
	using TClass = UJMDoorGenerateSamplesCommandlet;
	if (!Z_Registration_Info_UClass_UJMDoorGenerateSamplesCommandlet.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMDoorGenerateSamplesCommandlet"),
			Z_Registration_Info_UClass_UJMDoorGenerateSamplesCommandlet.InnerSingleton,
			StaticRegisterNativesUJMDoorGenerateSamplesCommandlet,
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
	return Z_Registration_Info_UClass_UJMDoorGenerateSamplesCommandlet.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMDoorGenerateSamplesCommandlet_NoRegister()
{
	return UJMDoorGenerateSamplesCommandlet::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMDoorGenerateSamplesCommandlet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Commandlets/JMDoorGenerateSamplesCommandlet.h" },
		{ "ModuleRelativePath", "Public/Commandlets/JMDoorGenerateSamplesCommandlet.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMDoorGenerateSamplesCommandlet constinit property declarations *********
// ********** End Class UJMDoorGenerateSamplesCommandlet constinit property declarations ***********
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMDoorGenerateSamplesCommandlet>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMDoorGenerateSamplesCommandlet_Statics
UObject* (*const Z_Construct_UClass_UJMDoorGenerateSamplesCommandlet_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCommandlet,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorTests,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorGenerateSamplesCommandlet_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMDoorGenerateSamplesCommandlet_Statics::ClassParams = {
	&UJMDoorGenerateSamplesCommandlet::StaticClass,
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
	0x001000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorGenerateSamplesCommandlet_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMDoorGenerateSamplesCommandlet_Statics::Class_MetaDataParams)
};
void UJMDoorGenerateSamplesCommandlet::StaticRegisterNativesUJMDoorGenerateSamplesCommandlet()
{
}
UClass* Z_Construct_UClass_UJMDoorGenerateSamplesCommandlet()
{
	if (!Z_Registration_Info_UClass_UJMDoorGenerateSamplesCommandlet.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMDoorGenerateSamplesCommandlet.OuterSingleton, Z_Construct_UClass_UJMDoorGenerateSamplesCommandlet_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMDoorGenerateSamplesCommandlet.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMDoorGenerateSamplesCommandlet);
UJMDoorGenerateSamplesCommandlet::~UJMDoorGenerateSamplesCommandlet() {}
// ********** End Class UJMDoorGenerateSamplesCommandlet *******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Public_Commandlets_JMDoorGenerateSamplesCommandlet_h__Script_JMDoorTests_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMDoorGenerateSamplesCommandlet, UJMDoorGenerateSamplesCommandlet::StaticClass, TEXT("UJMDoorGenerateSamplesCommandlet"), &Z_Registration_Info_UClass_UJMDoorGenerateSamplesCommandlet, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMDoorGenerateSamplesCommandlet), 1108650766U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Public_Commandlets_JMDoorGenerateSamplesCommandlet_h__Script_JMDoorTests_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Public_Commandlets_JMDoorGenerateSamplesCommandlet_h__Script_JMDoorTests_4279981694{
	TEXT("/Script/JMDoorTests"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Public_Commandlets_JMDoorGenerateSamplesCommandlet_h__Script_JMDoorTests_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Public_Commandlets_JMDoorGenerateSamplesCommandlet_h__Script_JMDoorTests_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
