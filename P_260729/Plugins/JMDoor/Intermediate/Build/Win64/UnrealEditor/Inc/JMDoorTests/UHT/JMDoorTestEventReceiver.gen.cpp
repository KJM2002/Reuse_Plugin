// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Tests/JMDoorTestEventReceiver.h"
#include "Door/JMDoorTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMDoorTestEventReceiver() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
JMDOORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMDoorNoiseEvent();
JMDOORTESTS_API UClass* Z_Construct_UClass_UJMDoorTestEventReceiver();
JMDOORTESTS_API UClass* Z_Construct_UClass_UJMDoorTestEventReceiver_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMDoorTests();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMDoorTestEventReceiver Function HandleNoise ****************************
struct Z_Construct_UFunction_UJMDoorTestEventReceiver_HandleNoise_Statics
{
	struct JMDoorTestEventReceiver_eventHandleNoise_Parms
	{
		FJMDoorNoiseEvent NoiseEvent;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/Tests/JMDoorTestEventReceiver.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleNoise constinit property declarations ***************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_NoiseEvent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleNoise constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleNoise Property Definitions **************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorTestEventReceiver_HandleNoise_Statics::NewProp_NoiseEvent = { "NoiseEvent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorTestEventReceiver_eventHandleNoise_Parms, NoiseEvent), Z_Construct_UScriptStruct_FJMDoorNoiseEvent, METADATA_PARAMS(0, nullptr) }; // 386806309
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorTestEventReceiver_HandleNoise_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorTestEventReceiver_HandleNoise_Statics::NewProp_NoiseEvent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorTestEventReceiver_HandleNoise_Statics::PropPointers) < 2048);
// ********** End Function HandleNoise Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorTestEventReceiver_HandleNoise_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorTestEventReceiver, nullptr, "HandleNoise", 	Z_Construct_UFunction_UJMDoorTestEventReceiver_HandleNoise_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorTestEventReceiver_HandleNoise_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorTestEventReceiver_HandleNoise_Statics::JMDoorTestEventReceiver_eventHandleNoise_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorTestEventReceiver_HandleNoise_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorTestEventReceiver_HandleNoise_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorTestEventReceiver_HandleNoise_Statics::JMDoorTestEventReceiver_eventHandleNoise_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorTestEventReceiver_HandleNoise()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorTestEventReceiver_HandleNoise_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorTestEventReceiver::execHandleNoise)
{
	P_GET_STRUCT(FJMDoorNoiseEvent,Z_Param_NoiseEvent);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleNoise(Z_Param_NoiseEvent);
	P_NATIVE_END;
}
// ********** End Class UJMDoorTestEventReceiver Function HandleNoise ******************************

// ********** Begin Class UJMDoorTestEventReceiver *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMDoorTestEventReceiver;
UClass* UJMDoorTestEventReceiver::GetPrivateStaticClass()
{
	using TClass = UJMDoorTestEventReceiver;
	if (!Z_Registration_Info_UClass_UJMDoorTestEventReceiver.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMDoorTestEventReceiver"),
			Z_Registration_Info_UClass_UJMDoorTestEventReceiver.InnerSingleton,
			StaticRegisterNativesUJMDoorTestEventReceiver,
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
	return Z_Registration_Info_UClass_UJMDoorTestEventReceiver.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMDoorTestEventReceiver_NoRegister()
{
	return UJMDoorTestEventReceiver::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMDoorTestEventReceiver_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Tests/JMDoorTestEventReceiver.h" },
		{ "ModuleRelativePath", "Private/Tests/JMDoorTestEventReceiver.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMDoorTestEventReceiver constinit property declarations *****************
// ********** End Class UJMDoorTestEventReceiver constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("HandleNoise"), .Pointer = &UJMDoorTestEventReceiver::execHandleNoise },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMDoorTestEventReceiver_HandleNoise, "HandleNoise" }, // 3535765743
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMDoorTestEventReceiver>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMDoorTestEventReceiver_Statics
UObject* (*const Z_Construct_UClass_UJMDoorTestEventReceiver_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorTests,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorTestEventReceiver_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMDoorTestEventReceiver_Statics::ClassParams = {
	&UJMDoorTestEventReceiver::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorTestEventReceiver_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMDoorTestEventReceiver_Statics::Class_MetaDataParams)
};
void UJMDoorTestEventReceiver::StaticRegisterNativesUJMDoorTestEventReceiver()
{
	UClass* Class = UJMDoorTestEventReceiver::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMDoorTestEventReceiver_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMDoorTestEventReceiver()
{
	if (!Z_Registration_Info_UClass_UJMDoorTestEventReceiver.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMDoorTestEventReceiver.OuterSingleton, Z_Construct_UClass_UJMDoorTestEventReceiver_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMDoorTestEventReceiver.OuterSingleton;
}
UJMDoorTestEventReceiver::UJMDoorTestEventReceiver(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMDoorTestEventReceiver);
UJMDoorTestEventReceiver::~UJMDoorTestEventReceiver() {}
// ********** End Class UJMDoorTestEventReceiver ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Private_Tests_JMDoorTestEventReceiver_h__Script_JMDoorTests_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMDoorTestEventReceiver, UJMDoorTestEventReceiver::StaticClass, TEXT("UJMDoorTestEventReceiver"), &Z_Registration_Info_UClass_UJMDoorTestEventReceiver, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMDoorTestEventReceiver), 1581953523U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Private_Tests_JMDoorTestEventReceiver_h__Script_JMDoorTests_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Private_Tests_JMDoorTestEventReceiver_h__Script_JMDoorTests_749253770{
	TEXT("/Script/JMDoorTests"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Private_Tests_JMDoorTestEventReceiver_h__Script_JMDoorTests_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorTests_Private_Tests_JMDoorTestEventReceiver_h__Script_JMDoorTests_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
