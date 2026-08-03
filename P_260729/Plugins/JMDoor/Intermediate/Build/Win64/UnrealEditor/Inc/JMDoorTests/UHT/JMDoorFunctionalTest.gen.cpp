// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Tests/JMDoorFunctionalTest.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMDoorFunctionalTest() {}

// ********** Begin Cross Module References ********************************************************
FUNCTIONALTESTING_API UClass* Z_Construct_UClass_AFunctionalTest();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_AJMRotatingDoorActor_NoRegister();
JMDOORTESTS_API UClass* Z_Construct_UClass_AJMDoorFunctionalTest();
JMDOORTESTS_API UClass* Z_Construct_UClass_AJMDoorFunctionalTest_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMDoorTests();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AJMDoorFunctionalTest Function VerifyDoorOpened **************************
struct Z_Construct_UFunction_AJMDoorFunctionalTest_VerifyDoorOpened_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Tests/JMDoorFunctionalTest.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function VerifyDoorOpened constinit property declarations **********************
// ********** End Function VerifyDoorOpened constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AJMDoorFunctionalTest_VerifyDoorOpened_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AJMDoorFunctionalTest, nullptr, "VerifyDoorOpened", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AJMDoorFunctionalTest_VerifyDoorOpened_Statics::Function_MetaDataParams), Z_Construct_UFunction_AJMDoorFunctionalTest_VerifyDoorOpened_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AJMDoorFunctionalTest_VerifyDoorOpened()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AJMDoorFunctionalTest_VerifyDoorOpened_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AJMDoorFunctionalTest::execVerifyDoorOpened)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->VerifyDoorOpened();
	P_NATIVE_END;
}
// ********** End Class AJMDoorFunctionalTest Function VerifyDoorOpened ****************************

// ********** Begin Class AJMDoorFunctionalTest ****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AJMDoorFunctionalTest;
UClass* AJMDoorFunctionalTest::GetPrivateStaticClass()
{
	using TClass = AJMDoorFunctionalTest;
	if (!Z_Registration_Info_UClass_AJMDoorFunctionalTest.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMDoorFunctionalTest"),
			Z_Registration_Info_UClass_AJMDoorFunctionalTest.InnerSingleton,
			StaticRegisterNativesAJMDoorFunctionalTest,
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
	return Z_Registration_Info_UClass_AJMDoorFunctionalTest.InnerSingleton;
}
UClass* Z_Construct_UClass_AJMDoorFunctionalTest_NoRegister()
{
	return AJMDoorFunctionalTest::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AJMDoorFunctionalTest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Actor Input Rendering HLOD" },
		{ "IncludePath", "Tests/JMDoorFunctionalTest.h" },
		{ "ModuleRelativePath", "Public/Tests/JMDoorFunctionalTest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnedDoor_MetaData[] = {
		{ "ModuleRelativePath", "Public/Tests/JMDoorFunctionalTest.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AJMDoorFunctionalTest constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawnedDoor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AJMDoorFunctionalTest constinit property declarations **********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("VerifyDoorOpened"), .Pointer = &AJMDoorFunctionalTest::execVerifyDoorOpened },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AJMDoorFunctionalTest_VerifyDoorOpened, "VerifyDoorOpened" }, // 4194786069
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AJMDoorFunctionalTest>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AJMDoorFunctionalTest_Statics

// ********** Begin Class AJMDoorFunctionalTest Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMDoorFunctionalTest_Statics::NewProp_SpawnedDoor = { "SpawnedDoor", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMDoorFunctionalTest, SpawnedDoor), Z_Construct_UClass_AJMRotatingDoorActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnedDoor_MetaData), NewProp_SpawnedDoor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AJMDoorFunctionalTest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMDoorFunctionalTest_Statics::NewProp_SpawnedDoor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AJMDoorFunctionalTest_Statics::PropPointers) < 2048);
// ********** End Class AJMDoorFunctionalTest Property Definitions *********************************
UObject* (*const Z_Construct_UClass_AJMDoorFunctionalTest_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AFunctionalTest,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorTests,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AJMDoorFunctionalTest_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AJMDoorFunctionalTest_Statics::ClassParams = {
	&AJMDoorFunctionalTest::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AJMDoorFunctionalTest_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AJMDoorFunctionalTest_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AJMDoorFunctionalTest_Statics::Class_MetaDataParams), Z_Construct_UClass_AJMDoorFunctionalTest_Statics::Class_MetaDataParams)
};
void AJMDoorFunctionalTest::StaticRegisterNativesAJMDoorFunctionalTest()
{
	UClass* Class = AJMDoorFunctionalTest::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AJMDoorFunctionalTest_Statics::Funcs));
}
UClass* Z_Construct_UClass_AJMDoorFunctionalTest()
{
	if (!Z_Registration_Info_UClass_AJMDoorFunctionalTest.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AJMDoorFunctionalTest.OuterSingleton, Z_Construct_UClass_AJMDoorFunctionalTest_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AJMDoorFunctionalTest.OuterSingleton;
}
AJMDoorFunctionalTest::AJMDoorFunctionalTest(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AJMDoorFunctionalTest);
AJMDoorFunctionalTest::~AJMDoorFunctionalTest() {}
// ********** End Class AJMDoorFunctionalTest ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Public_Tests_JMDoorFunctionalTest_h__Script_JMDoorTests_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AJMDoorFunctionalTest, AJMDoorFunctionalTest::StaticClass, TEXT("AJMDoorFunctionalTest"), &Z_Registration_Info_UClass_AJMDoorFunctionalTest, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AJMDoorFunctionalTest), 3493631200U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Public_Tests_JMDoorFunctionalTest_h__Script_JMDoorTests_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Public_Tests_JMDoorFunctionalTest_h__Script_JMDoorTests_2555694005{
	TEXT("/Script/JMDoorTests"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Public_Tests_JMDoorFunctionalTest_h__Script_JMDoorTests_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Public_Tests_JMDoorFunctionalTest_h__Script_JMDoorTests_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
