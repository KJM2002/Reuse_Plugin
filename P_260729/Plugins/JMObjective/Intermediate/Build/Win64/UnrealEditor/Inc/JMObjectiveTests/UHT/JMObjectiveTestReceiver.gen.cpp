// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Tests/JMObjectiveTestReceiver.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMObjectiveTestReceiver() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventPayloadBase();
JMOBJECTIVETESTS_API UClass* Z_Construct_UClass_UJMObjectiveTestPayload();
JMOBJECTIVETESTS_API UClass* Z_Construct_UClass_UJMObjectiveTestPayload_NoRegister();
JMOBJECTIVETESTS_API UClass* Z_Construct_UClass_UJMObjectiveTestReceiver();
JMOBJECTIVETESTS_API UClass* Z_Construct_UClass_UJMObjectiveTestReceiver_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMObjectiveTests();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMObjectiveTestPayload **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMObjectiveTestPayload;
UClass* UJMObjectiveTestPayload::GetPrivateStaticClass()
{
	using TClass = UJMObjectiveTestPayload;
	if (!Z_Registration_Info_UClass_UJMObjectiveTestPayload.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMObjectiveTestPayload"),
			Z_Registration_Info_UClass_UJMObjectiveTestPayload.InnerSingleton,
			StaticRegisterNativesUJMObjectiveTestPayload,
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
	return Z_Registration_Info_UClass_UJMObjectiveTestPayload.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMObjectiveTestPayload_NoRegister()
{
	return UJMObjectiveTestPayload::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMObjectiveTestPayload_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Tests/JMObjectiveTestReceiver.h" },
		{ "ModuleRelativePath", "Private/Tests/JMObjectiveTestReceiver.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMObjectiveTestPayload constinit property declarations ******************
// ********** End Class UJMObjectiveTestPayload constinit property declarations ********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMObjectiveTestPayload>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMObjectiveTestPayload_Statics
UObject* (*const Z_Construct_UClass_UJMObjectiveTestPayload_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UJMGameplayEventPayloadBase,
	(UObject* (*)())Z_Construct_UPackage__Script_JMObjectiveTests,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveTestPayload_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMObjectiveTestPayload_Statics::ClassParams = {
	&UJMObjectiveTestPayload::StaticClass,
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
	0x002010A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveTestPayload_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMObjectiveTestPayload_Statics::Class_MetaDataParams)
};
void UJMObjectiveTestPayload::StaticRegisterNativesUJMObjectiveTestPayload()
{
}
UClass* Z_Construct_UClass_UJMObjectiveTestPayload()
{
	if (!Z_Registration_Info_UClass_UJMObjectiveTestPayload.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMObjectiveTestPayload.OuterSingleton, Z_Construct_UClass_UJMObjectiveTestPayload_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMObjectiveTestPayload.OuterSingleton;
}
UJMObjectiveTestPayload::UJMObjectiveTestPayload(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMObjectiveTestPayload);
UJMObjectiveTestPayload::~UJMObjectiveTestPayload() {}
// ********** End Class UJMObjectiveTestPayload ****************************************************

// ********** Begin Class UJMObjectiveTestReceiver *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMObjectiveTestReceiver;
UClass* UJMObjectiveTestReceiver::GetPrivateStaticClass()
{
	using TClass = UJMObjectiveTestReceiver;
	if (!Z_Registration_Info_UClass_UJMObjectiveTestReceiver.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMObjectiveTestReceiver"),
			Z_Registration_Info_UClass_UJMObjectiveTestReceiver.InnerSingleton,
			StaticRegisterNativesUJMObjectiveTestReceiver,
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
	return Z_Registration_Info_UClass_UJMObjectiveTestReceiver.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMObjectiveTestReceiver_NoRegister()
{
	return UJMObjectiveTestReceiver::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMObjectiveTestReceiver_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Tests/JMObjectiveTestReceiver.h" },
		{ "ModuleRelativePath", "Private/Tests/JMObjectiveTestReceiver.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMObjectiveTestReceiver constinit property declarations *****************
// ********** End Class UJMObjectiveTestReceiver constinit property declarations *******************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMObjectiveTestReceiver>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMObjectiveTestReceiver_Statics
UObject* (*const Z_Construct_UClass_UJMObjectiveTestReceiver_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_JMObjectiveTests,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveTestReceiver_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMObjectiveTestReceiver_Statics::ClassParams = {
	&UJMObjectiveTestReceiver::StaticClass,
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
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveTestReceiver_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMObjectiveTestReceiver_Statics::Class_MetaDataParams)
};
void UJMObjectiveTestReceiver::StaticRegisterNativesUJMObjectiveTestReceiver()
{
}
UClass* Z_Construct_UClass_UJMObjectiveTestReceiver()
{
	if (!Z_Registration_Info_UClass_UJMObjectiveTestReceiver.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMObjectiveTestReceiver.OuterSingleton, Z_Construct_UClass_UJMObjectiveTestReceiver_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMObjectiveTestReceiver.OuterSingleton;
}
UJMObjectiveTestReceiver::UJMObjectiveTestReceiver(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMObjectiveTestReceiver);
UJMObjectiveTestReceiver::~UJMObjectiveTestReceiver() {}
// ********** End Class UJMObjectiveTestReceiver ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjectiveTests_Private_Tests_JMObjectiveTestReceiver_h__Script_JMObjectiveTests_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMObjectiveTestPayload, UJMObjectiveTestPayload::StaticClass, TEXT("UJMObjectiveTestPayload"), &Z_Registration_Info_UClass_UJMObjectiveTestPayload, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMObjectiveTestPayload), 1702496644U) },
		{ Z_Construct_UClass_UJMObjectiveTestReceiver, UJMObjectiveTestReceiver::StaticClass, TEXT("UJMObjectiveTestReceiver"), &Z_Registration_Info_UClass_UJMObjectiveTestReceiver, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMObjectiveTestReceiver), 2122609730U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjectiveTests_Private_Tests_JMObjectiveTestReceiver_h__Script_JMObjectiveTests_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjectiveTests_Private_Tests_JMObjectiveTestReceiver_h__Script_JMObjectiveTests_3566243821{
	TEXT("/Script/JMObjectiveTests"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjectiveTests_Private_Tests_JMObjectiveTestReceiver_h__Script_JMObjectiveTests_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjectiveTests_Private_Tests_JMObjectiveTestReceiver_h__Script_JMObjectiveTests_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
