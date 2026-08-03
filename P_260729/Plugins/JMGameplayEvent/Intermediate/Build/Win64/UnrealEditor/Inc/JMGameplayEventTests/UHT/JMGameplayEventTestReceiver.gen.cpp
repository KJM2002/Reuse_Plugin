// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Tests/JMGameplayEventTestReceiver.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMGameplayEventTestReceiver() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventSubsystem_NoRegister();
JMGAMEPLAYEVENTTESTS_API UClass* Z_Construct_UClass_UJMGameplayEventTestReceiver();
JMGAMEPLAYEVENTTESTS_API UClass* Z_Construct_UClass_UJMGameplayEventTestReceiver_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMGameplayEventTests();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMGameplayEventTestReceiver *********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMGameplayEventTestReceiver;
UClass* UJMGameplayEventTestReceiver::GetPrivateStaticClass()
{
	using TClass = UJMGameplayEventTestReceiver;
	if (!Z_Registration_Info_UClass_UJMGameplayEventTestReceiver.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMGameplayEventTestReceiver"),
			Z_Registration_Info_UClass_UJMGameplayEventTestReceiver.InnerSingleton,
			StaticRegisterNativesUJMGameplayEventTestReceiver,
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
	return Z_Registration_Info_UClass_UJMGameplayEventTestReceiver.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMGameplayEventTestReceiver_NoRegister()
{
	return UJMGameplayEventTestReceiver::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMGameplayEventTestReceiver_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Tests/JMGameplayEventTestReceiver.h" },
		{ "ModuleRelativePath", "Private/Tests/JMGameplayEventTestReceiver.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Subsystem_MetaData[] = {
		{ "ModuleRelativePath", "Private/Tests/JMGameplayEventTestReceiver.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMGameplayEventTestReceiver constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Subsystem;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMGameplayEventTestReceiver constinit property declarations ***************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMGameplayEventTestReceiver>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMGameplayEventTestReceiver_Statics

// ********** Begin Class UJMGameplayEventTestReceiver Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMGameplayEventTestReceiver_Statics::NewProp_Subsystem = { "Subsystem", nullptr, (EPropertyFlags)0x0114000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMGameplayEventTestReceiver, Subsystem), Z_Construct_UClass_UJMGameplayEventSubsystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Subsystem_MetaData), NewProp_Subsystem_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMGameplayEventTestReceiver_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMGameplayEventTestReceiver_Statics::NewProp_Subsystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMGameplayEventTestReceiver_Statics::PropPointers) < 2048);
// ********** End Class UJMGameplayEventTestReceiver Property Definitions **************************
UObject* (*const Z_Construct_UClass_UJMGameplayEventTestReceiver_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_JMGameplayEventTests,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMGameplayEventTestReceiver_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMGameplayEventTestReceiver_Statics::ClassParams = {
	&UJMGameplayEventTestReceiver::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMGameplayEventTestReceiver_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMGameplayEventTestReceiver_Statics::PropPointers),
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMGameplayEventTestReceiver_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMGameplayEventTestReceiver_Statics::Class_MetaDataParams)
};
void UJMGameplayEventTestReceiver::StaticRegisterNativesUJMGameplayEventTestReceiver()
{
}
UClass* Z_Construct_UClass_UJMGameplayEventTestReceiver()
{
	if (!Z_Registration_Info_UClass_UJMGameplayEventTestReceiver.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMGameplayEventTestReceiver.OuterSingleton, Z_Construct_UClass_UJMGameplayEventTestReceiver_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMGameplayEventTestReceiver.OuterSingleton;
}
UJMGameplayEventTestReceiver::UJMGameplayEventTestReceiver(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMGameplayEventTestReceiver);
UJMGameplayEventTestReceiver::~UJMGameplayEventTestReceiver() {}
// ********** End Class UJMGameplayEventTestReceiver ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEventTests_Private_Tests_JMGameplayEventTestReceiver_h__Script_JMGameplayEventTests_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMGameplayEventTestReceiver, UJMGameplayEventTestReceiver::StaticClass, TEXT("UJMGameplayEventTestReceiver"), &Z_Registration_Info_UClass_UJMGameplayEventTestReceiver, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMGameplayEventTestReceiver), 752491535U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEventTests_Private_Tests_JMGameplayEventTestReceiver_h__Script_JMGameplayEventTests_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEventTests_Private_Tests_JMGameplayEventTestReceiver_h__Script_JMGameplayEventTests_361504407{
	TEXT("/Script/JMGameplayEventTests"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEventTests_Private_Tests_JMGameplayEventTestReceiver_h__Script_JMGameplayEventTests_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEventTests_Private_Tests_JMGameplayEventTestReceiver_h__Script_JMGameplayEventTests_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
