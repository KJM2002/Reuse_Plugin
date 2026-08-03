// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Tests/JMJumpScareTestActor.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMJumpScareTestActor() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareActorInterface_NoRegister();
JMJUMPSCARETESTS_API UClass* Z_Construct_UClass_AJMJumpScareTestActor();
JMJUMPSCARETESTS_API UClass* Z_Construct_UClass_AJMJumpScareTestActor_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMJumpScareTests();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AJMJumpScareTestActor ****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AJMJumpScareTestActor;
UClass* AJMJumpScareTestActor::GetPrivateStaticClass()
{
	using TClass = AJMJumpScareTestActor;
	if (!Z_Registration_Info_UClass_AJMJumpScareTestActor.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMJumpScareTestActor"),
			Z_Registration_Info_UClass_AJMJumpScareTestActor.InnerSingleton,
			StaticRegisterNativesAJMJumpScareTestActor,
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
	return Z_Registration_Info_UClass_AJMJumpScareTestActor.InnerSingleton;
}
UClass* Z_Construct_UClass_AJMJumpScareTestActor_NoRegister()
{
	return AJMJumpScareTestActor::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AJMJumpScareTestActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Tests/JMJumpScareTestActor.h" },
		{ "ModuleRelativePath", "Private/Tests/JMJumpScareTestActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartedCount_MetaData[] = {
		{ "ModuleRelativePath", "Private/Tests/JMJumpScareTestActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ImpactCount_MetaData[] = {
		{ "ModuleRelativePath", "Private/Tests/JMJumpScareTestActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExitingCount_MetaData[] = {
		{ "ModuleRelativePath", "Private/Tests/JMJumpScareTestActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FinishedCount_MetaData[] = {
		{ "ModuleRelativePath", "Private/Tests/JMJumpScareTestActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CancelledCount_MetaData[] = {
		{ "ModuleRelativePath", "Private/Tests/JMJumpScareTestActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AJMJumpScareTestActor constinit property declarations ********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_StartedCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ImpactCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ExitingCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_FinishedCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CancelledCount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AJMJumpScareTestActor constinit property declarations **********************
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AJMJumpScareTestActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AJMJumpScareTestActor_Statics

// ********** Begin Class AJMJumpScareTestActor Property Definitions *******************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AJMJumpScareTestActor_Statics::NewProp_StartedCount = { "StartedCount", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMJumpScareTestActor, StartedCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartedCount_MetaData), NewProp_StartedCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AJMJumpScareTestActor_Statics::NewProp_ImpactCount = { "ImpactCount", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMJumpScareTestActor, ImpactCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ImpactCount_MetaData), NewProp_ImpactCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AJMJumpScareTestActor_Statics::NewProp_ExitingCount = { "ExitingCount", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMJumpScareTestActor, ExitingCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExitingCount_MetaData), NewProp_ExitingCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AJMJumpScareTestActor_Statics::NewProp_FinishedCount = { "FinishedCount", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMJumpScareTestActor, FinishedCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FinishedCount_MetaData), NewProp_FinishedCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AJMJumpScareTestActor_Statics::NewProp_CancelledCount = { "CancelledCount", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMJumpScareTestActor, CancelledCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CancelledCount_MetaData), NewProp_CancelledCount_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AJMJumpScareTestActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMJumpScareTestActor_Statics::NewProp_StartedCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMJumpScareTestActor_Statics::NewProp_ImpactCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMJumpScareTestActor_Statics::NewProp_ExitingCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMJumpScareTestActor_Statics::NewProp_FinishedCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMJumpScareTestActor_Statics::NewProp_CancelledCount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AJMJumpScareTestActor_Statics::PropPointers) < 2048);
// ********** End Class AJMJumpScareTestActor Property Definitions *********************************
UObject* (*const Z_Construct_UClass_AJMJumpScareTestActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_JMJumpScareTests,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AJMJumpScareTestActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AJMJumpScareTestActor_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UJMJumpScareActorInterface_NoRegister, (int32)VTABLE_OFFSET(AJMJumpScareTestActor, IJMJumpScareActorInterface), false },  // 2799978920
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_AJMJumpScareTestActor_Statics::ClassParams = {
	&AJMJumpScareTestActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AJMJumpScareTestActor_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AJMJumpScareTestActor_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x008000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AJMJumpScareTestActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AJMJumpScareTestActor_Statics::Class_MetaDataParams)
};
void AJMJumpScareTestActor::StaticRegisterNativesAJMJumpScareTestActor()
{
}
UClass* Z_Construct_UClass_AJMJumpScareTestActor()
{
	if (!Z_Registration_Info_UClass_AJMJumpScareTestActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AJMJumpScareTestActor.OuterSingleton, Z_Construct_UClass_AJMJumpScareTestActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AJMJumpScareTestActor.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AJMJumpScareTestActor);
AJMJumpScareTestActor::~AJMJumpScareTestActor() {}
// ********** End Class AJMJumpScareTestActor ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScareTests_Private_Tests_JMJumpScareTestActor_h__Script_JMJumpScareTests_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AJMJumpScareTestActor, AJMJumpScareTestActor::StaticClass, TEXT("AJMJumpScareTestActor"), &Z_Registration_Info_UClass_AJMJumpScareTestActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AJMJumpScareTestActor), 1108223055U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScareTests_Private_Tests_JMJumpScareTestActor_h__Script_JMJumpScareTests_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScareTests_Private_Tests_JMJumpScareTestActor_h__Script_JMJumpScareTests_2898646887{
	TEXT("/Script/JMJumpScareTests"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScareTests_Private_Tests_JMJumpScareTestActor_h__Script_JMJumpScareTests_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScareTests_Private_Tests_JMJumpScareTestActor_h__Script_JMJumpScareTests_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
