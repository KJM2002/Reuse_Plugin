// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JMHideInputRouterLibrary.h"
#include "Types/JMInteractionTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMHideInputRouterLibrary() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
JMHIDEINTERACTIONINTEGRATION_API UClass* Z_Construct_UClass_UJMHideInputRouterLibrary();
JMHIDEINTERACTIONINTEGRATION_API UClass* Z_Construct_UClass_UJMHideInputRouterLibrary_NoRegister();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionResult();
UPackage* Z_Construct_UPackage__Script_JMHideInteractionIntegration();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMHideInputRouterLibrary Function RouteHostInteractInput ****************
struct Z_Construct_UFunction_UJMHideInputRouterLibrary_RouteHostInteractInput_Statics
{
	struct JMHideInputRouterLibrary_eventRouteHostInteractInput_Parms
	{
		AActor* Host;
		FJMInteractionResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Hide|Input" },
		{ "DefaultToSelf", "Host" },
		{ "ModuleRelativePath", "Public/JMHideInputRouterLibrary.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RouteHostInteractInput constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Host;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RouteHostInteractInput constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RouteHostInteractInput Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMHideInputRouterLibrary_RouteHostInteractInput_Statics::NewProp_Host = { "Host", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMHideInputRouterLibrary_eventRouteHostInteractInput_Parms, Host), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMHideInputRouterLibrary_RouteHostInteractInput_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMHideInputRouterLibrary_eventRouteHostInteractInput_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMInteractionResult, METADATA_PARAMS(0, nullptr) }; // 240276497
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMHideInputRouterLibrary_RouteHostInteractInput_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideInputRouterLibrary_RouteHostInteractInput_Statics::NewProp_Host,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideInputRouterLibrary_RouteHostInteractInput_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInputRouterLibrary_RouteHostInteractInput_Statics::PropPointers) < 2048);
// ********** End Function RouteHostInteractInput Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMHideInputRouterLibrary_RouteHostInteractInput_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMHideInputRouterLibrary, nullptr, "RouteHostInteractInput", 	Z_Construct_UFunction_UJMHideInputRouterLibrary_RouteHostInteractInput_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInputRouterLibrary_RouteHostInteractInput_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMHideInputRouterLibrary_RouteHostInteractInput_Statics::JMHideInputRouterLibrary_eventRouteHostInteractInput_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInputRouterLibrary_RouteHostInteractInput_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMHideInputRouterLibrary_RouteHostInteractInput_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMHideInputRouterLibrary_RouteHostInteractInput_Statics::JMHideInputRouterLibrary_eventRouteHostInteractInput_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMHideInputRouterLibrary_RouteHostInteractInput()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMHideInputRouterLibrary_RouteHostInteractInput_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMHideInputRouterLibrary::execRouteHostInteractInput)
{
	P_GET_OBJECT(AActor,Z_Param_Host);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMInteractionResult*)Z_Param__Result=UJMHideInputRouterLibrary::RouteHostInteractInput(Z_Param_Host);
	P_NATIVE_END;
}
// ********** End Class UJMHideInputRouterLibrary Function RouteHostInteractInput ******************

// ********** Begin Class UJMHideInputRouterLibrary ************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMHideInputRouterLibrary;
UClass* UJMHideInputRouterLibrary::GetPrivateStaticClass()
{
	using TClass = UJMHideInputRouterLibrary;
	if (!Z_Registration_Info_UClass_UJMHideInputRouterLibrary.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMHideInputRouterLibrary"),
			Z_Registration_Info_UClass_UJMHideInputRouterLibrary.InnerSingleton,
			StaticRegisterNativesUJMHideInputRouterLibrary,
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
	return Z_Registration_Info_UClass_UJMHideInputRouterLibrary.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMHideInputRouterLibrary_NoRegister()
{
	return UJMHideInputRouterLibrary::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMHideInputRouterLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Host-owned interaction input route.\n * Hidden participants exit directly; everyone else keeps the normal JMInteraction path.\n */" },
#endif
		{ "IncludePath", "JMHideInputRouterLibrary.h" },
		{ "ModuleRelativePath", "Public/JMHideInputRouterLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Host-owned interaction input route.\nHidden participants exit directly; everyone else keeps the normal JMInteraction path." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UJMHideInputRouterLibrary constinit property declarations ****************
// ********** End Class UJMHideInputRouterLibrary constinit property declarations ******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("RouteHostInteractInput"), .Pointer = &UJMHideInputRouterLibrary::execRouteHostInteractInput },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMHideInputRouterLibrary_RouteHostInteractInput, "RouteHostInteractInput" }, // 2539276895
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMHideInputRouterLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMHideInputRouterLibrary_Statics
UObject* (*const Z_Construct_UClass_UJMHideInputRouterLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideInteractionIntegration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideInputRouterLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMHideInputRouterLibrary_Statics::ClassParams = {
	&UJMHideInputRouterLibrary::StaticClass,
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
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideInputRouterLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMHideInputRouterLibrary_Statics::Class_MetaDataParams)
};
void UJMHideInputRouterLibrary::StaticRegisterNativesUJMHideInputRouterLibrary()
{
	UClass* Class = UJMHideInputRouterLibrary::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMHideInputRouterLibrary_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMHideInputRouterLibrary()
{
	if (!Z_Registration_Info_UClass_UJMHideInputRouterLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMHideInputRouterLibrary.OuterSingleton, Z_Construct_UClass_UJMHideInputRouterLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMHideInputRouterLibrary.OuterSingleton;
}
UJMHideInputRouterLibrary::UJMHideInputRouterLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMHideInputRouterLibrary);
UJMHideInputRouterLibrary::~UJMHideInputRouterLibrary() {}
// ********** End Class UJMHideInputRouterLibrary **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHideInteractionIntegration_Source_JMHideInteractionIntegration_Public_JMHideInputRouterLibrary_h__Script_JMHideInteractionIntegration_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMHideInputRouterLibrary, UJMHideInputRouterLibrary::StaticClass, TEXT("UJMHideInputRouterLibrary"), &Z_Registration_Info_UClass_UJMHideInputRouterLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMHideInputRouterLibrary), 201232659U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHideInteractionIntegration_Source_JMHideInteractionIntegration_Public_JMHideInputRouterLibrary_h__Script_JMHideInteractionIntegration_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHideInteractionIntegration_Source_JMHideInteractionIntegration_Public_JMHideInputRouterLibrary_h__Script_JMHideInteractionIntegration_4056162997{
	TEXT("/Script/JMHideInteractionIntegration"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHideInteractionIntegration_Source_JMHideInteractionIntegration_Public_JMHideInputRouterLibrary_h__Script_JMHideInteractionIntegration_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHideInteractionIntegration_Source_JMHideInteractionIntegration_Public_JMHideInputRouterLibrary_h__Script_JMHideInteractionIntegration_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
