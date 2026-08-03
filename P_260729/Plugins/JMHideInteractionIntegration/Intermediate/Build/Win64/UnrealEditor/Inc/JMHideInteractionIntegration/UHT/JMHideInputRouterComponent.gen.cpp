// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/JMHideInputRouterComponent.h"
#include "Types/JMInteractionTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMHideInputRouterComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
JMHIDEINTERACTIONINTEGRATION_API UClass* Z_Construct_UClass_UJMHideInputRouterComponent();
JMHIDEINTERACTIONINTEGRATION_API UClass* Z_Construct_UClass_UJMHideInputRouterComponent_NoRegister();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractionInputInterceptorInterface_NoRegister();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionResult();
UPackage* Z_Construct_UPackage__Script_JMHideInteractionIntegration();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMHideInputRouterComponent Function RouteHostInteractInput **************
struct Z_Construct_UFunction_UJMHideInputRouterComponent_RouteHostInteractInput_Statics
{
	struct JMHideInputRouterComponent_eventRouteHostInteractInput_Parms
	{
		FJMInteractionResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Hide|Input" },
		{ "ModuleRelativePath", "Public/Components/JMHideInputRouterComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RouteHostInteractInput constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RouteHostInteractInput constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RouteHostInteractInput Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMHideInputRouterComponent_RouteHostInteractInput_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMHideInputRouterComponent_eventRouteHostInteractInput_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMInteractionResult, METADATA_PARAMS(0, nullptr) }; // 240276497
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMHideInputRouterComponent_RouteHostInteractInput_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideInputRouterComponent_RouteHostInteractInput_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInputRouterComponent_RouteHostInteractInput_Statics::PropPointers) < 2048);
// ********** End Function RouteHostInteractInput Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMHideInputRouterComponent_RouteHostInteractInput_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMHideInputRouterComponent, nullptr, "RouteHostInteractInput", 	Z_Construct_UFunction_UJMHideInputRouterComponent_RouteHostInteractInput_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInputRouterComponent_RouteHostInteractInput_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMHideInputRouterComponent_RouteHostInteractInput_Statics::JMHideInputRouterComponent_eventRouteHostInteractInput_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideInputRouterComponent_RouteHostInteractInput_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMHideInputRouterComponent_RouteHostInteractInput_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMHideInputRouterComponent_RouteHostInteractInput_Statics::JMHideInputRouterComponent_eventRouteHostInteractInput_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMHideInputRouterComponent_RouteHostInteractInput()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMHideInputRouterComponent_RouteHostInteractInput_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMHideInputRouterComponent::execRouteHostInteractInput)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMInteractionResult*)Z_Param__Result=P_THIS->RouteHostInteractInput();
	P_NATIVE_END;
}
// ********** End Class UJMHideInputRouterComponent Function RouteHostInteractInput ****************

// ********** Begin Class UJMHideInputRouterComponent **********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMHideInputRouterComponent;
UClass* UJMHideInputRouterComponent::GetPrivateStaticClass()
{
	using TClass = UJMHideInputRouterComponent;
	if (!Z_Registration_Info_UClass_UJMHideInputRouterComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMHideInputRouterComponent"),
			Z_Registration_Info_UClass_UJMHideInputRouterComponent.InnerSingleton,
			StaticRegisterNativesUJMHideInputRouterComponent,
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
	return Z_Registration_Info_UClass_UJMHideInputRouterComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMHideInputRouterComponent_NoRegister()
{
	return UJMHideInputRouterComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMHideInputRouterComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JMHide" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called by host-owned input. This component never registers an Input Action. */" },
#endif
		{ "IncludePath", "Components/JMHideInputRouterComponent.h" },
		{ "ModuleRelativePath", "Public/Components/JMHideInputRouterComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called by host-owned input. This component never registers an Input Action." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UJMHideInputRouterComponent constinit property declarations **************
// ********** End Class UJMHideInputRouterComponent constinit property declarations ****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("RouteHostInteractInput"), .Pointer = &UJMHideInputRouterComponent::execRouteHostInteractInput },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMHideInputRouterComponent_RouteHostInteractInput, "RouteHostInteractInput" }, // 728121773
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMHideInputRouterComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMHideInputRouterComponent_Statics
UObject* (*const Z_Construct_UClass_UJMHideInputRouterComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideInteractionIntegration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideInputRouterComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UJMHideInputRouterComponent_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UJMInteractionInputInterceptorInterface_NoRegister, (int32)VTABLE_OFFSET(UJMHideInputRouterComponent, IJMInteractionInputInterceptorInterface), false },  // 4049927490
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMHideInputRouterComponent_Statics::ClassParams = {
	&UJMHideInputRouterComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideInputRouterComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMHideInputRouterComponent_Statics::Class_MetaDataParams)
};
void UJMHideInputRouterComponent::StaticRegisterNativesUJMHideInputRouterComponent()
{
	UClass* Class = UJMHideInputRouterComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMHideInputRouterComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMHideInputRouterComponent()
{
	if (!Z_Registration_Info_UClass_UJMHideInputRouterComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMHideInputRouterComponent.OuterSingleton, Z_Construct_UClass_UJMHideInputRouterComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMHideInputRouterComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMHideInputRouterComponent);
UJMHideInputRouterComponent::~UJMHideInputRouterComponent() {}
// ********** End Class UJMHideInputRouterComponent ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHideInteractionIntegration_Source_JMHideInteractionIntegration_Public_Components_JMHideInputRouterComponent_h__Script_JMHideInteractionIntegration_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMHideInputRouterComponent, UJMHideInputRouterComponent::StaticClass, TEXT("UJMHideInputRouterComponent"), &Z_Registration_Info_UClass_UJMHideInputRouterComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMHideInputRouterComponent), 2909449569U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHideInteractionIntegration_Source_JMHideInteractionIntegration_Public_Components_JMHideInputRouterComponent_h__Script_JMHideInteractionIntegration_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHideInteractionIntegration_Source_JMHideInteractionIntegration_Public_Components_JMHideInputRouterComponent_h__Script_JMHideInteractionIntegration_242210711{
	TEXT("/Script/JMHideInteractionIntegration"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHideInteractionIntegration_Source_JMHideInteractionIntegration_Public_Components_JMHideInputRouterComponent_h__Script_JMHideInteractionIntegration_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHideInteractionIntegration_Source_JMHideInteractionIntegration_Public_Components_JMHideInputRouterComponent_h__Script_JMHideInteractionIntegration_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
