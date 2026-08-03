// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/JMHideDoorMechanismComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMHideDoorMechanismComponent() {}

// ********** Begin Cross Module References ********************************************************
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorState();
JMHIDEDOORINTEGRATION_API UClass* Z_Construct_UClass_UJMHideDoorMechanismComponent();
JMHIDEDOORINTEGRATION_API UClass* Z_Construct_UClass_UJMHideDoorMechanismComponent_NoRegister();
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideMechanismComponent();
UPackage* Z_Construct_UPackage__Script_JMHideDoorIntegration();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMHideDoorMechanismComponent Function HandleDoorStateChanged ************
struct Z_Construct_UFunction_UJMHideDoorMechanismComponent_HandleDoorStateChanged_Statics
{
	struct JMHideDoorMechanismComponent_eventHandleDoorStateChanged_Parms
	{
		EJMDoorState OldState;
		EJMDoorState NewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/JMHideDoorMechanismComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleDoorStateChanged constinit property declarations ****************
	static const UECodeGen_Private::FBytePropertyParams NewProp_OldState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OldState;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleDoorStateChanged constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleDoorStateChanged Property Definitions ***************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMHideDoorMechanismComponent_HandleDoorStateChanged_Statics::NewProp_OldState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMHideDoorMechanismComponent_HandleDoorStateChanged_Statics::NewProp_OldState = { "OldState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMHideDoorMechanismComponent_eventHandleDoorStateChanged_Parms, OldState), Z_Construct_UEnum_JMDoorRuntime_EJMDoorState, METADATA_PARAMS(0, nullptr) }; // 2513049645
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMHideDoorMechanismComponent_HandleDoorStateChanged_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMHideDoorMechanismComponent_HandleDoorStateChanged_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMHideDoorMechanismComponent_eventHandleDoorStateChanged_Parms, NewState), Z_Construct_UEnum_JMDoorRuntime_EJMDoorState, METADATA_PARAMS(0, nullptr) }; // 2513049645
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMHideDoorMechanismComponent_HandleDoorStateChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideDoorMechanismComponent_HandleDoorStateChanged_Statics::NewProp_OldState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideDoorMechanismComponent_HandleDoorStateChanged_Statics::NewProp_OldState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideDoorMechanismComponent_HandleDoorStateChanged_Statics::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideDoorMechanismComponent_HandleDoorStateChanged_Statics::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideDoorMechanismComponent_HandleDoorStateChanged_Statics::PropPointers) < 2048);
// ********** End Function HandleDoorStateChanged Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMHideDoorMechanismComponent_HandleDoorStateChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMHideDoorMechanismComponent, nullptr, "HandleDoorStateChanged", 	Z_Construct_UFunction_UJMHideDoorMechanismComponent_HandleDoorStateChanged_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideDoorMechanismComponent_HandleDoorStateChanged_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMHideDoorMechanismComponent_HandleDoorStateChanged_Statics::JMHideDoorMechanismComponent_eventHandleDoorStateChanged_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideDoorMechanismComponent_HandleDoorStateChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMHideDoorMechanismComponent_HandleDoorStateChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMHideDoorMechanismComponent_HandleDoorStateChanged_Statics::JMHideDoorMechanismComponent_eventHandleDoorStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMHideDoorMechanismComponent_HandleDoorStateChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMHideDoorMechanismComponent_HandleDoorStateChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMHideDoorMechanismComponent::execHandleDoorStateChanged)
{
	P_GET_ENUM(EJMDoorState,Z_Param_OldState);
	P_GET_ENUM(EJMDoorState,Z_Param_NewState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleDoorStateChanged(EJMDoorState(Z_Param_OldState),EJMDoorState(Z_Param_NewState));
	P_NATIVE_END;
}
// ********** End Class UJMHideDoorMechanismComponent Function HandleDoorStateChanged **************

// ********** Begin Class UJMHideDoorMechanismComponent ********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMHideDoorMechanismComponent;
UClass* UJMHideDoorMechanismComponent::GetPrivateStaticClass()
{
	using TClass = UJMHideDoorMechanismComponent;
	if (!Z_Registration_Info_UClass_UJMHideDoorMechanismComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMHideDoorMechanismComponent"),
			Z_Registration_Info_UClass_UJMHideDoorMechanismComponent.InnerSingleton,
			StaticRegisterNativesUJMHideDoorMechanismComponent,
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
	return Z_Registration_Info_UClass_UJMHideDoorMechanismComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMHideDoorMechanismComponent_NoRegister()
{
	return UJMHideDoorMechanismComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMHideDoorMechanismComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JMHide" },
		{ "IncludePath", "Components/JMHideDoorMechanismComponent.h" },
		{ "ModuleRelativePath", "Public/Components/JMHideDoorMechanismComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMHideDoorMechanismComponent constinit property declarations ************
// ********** End Class UJMHideDoorMechanismComponent constinit property declarations **************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("HandleDoorStateChanged"), .Pointer = &UJMHideDoorMechanismComponent::execHandleDoorStateChanged },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMHideDoorMechanismComponent_HandleDoorStateChanged, "HandleDoorStateChanged" }, // 4231188019
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMHideDoorMechanismComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMHideDoorMechanismComponent_Statics
UObject* (*const Z_Construct_UClass_UJMHideDoorMechanismComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UJMHideMechanismComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideDoorIntegration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideDoorMechanismComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMHideDoorMechanismComponent_Statics::ClassParams = {
	&UJMHideDoorMechanismComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideDoorMechanismComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMHideDoorMechanismComponent_Statics::Class_MetaDataParams)
};
void UJMHideDoorMechanismComponent::StaticRegisterNativesUJMHideDoorMechanismComponent()
{
	UClass* Class = UJMHideDoorMechanismComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMHideDoorMechanismComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMHideDoorMechanismComponent()
{
	if (!Z_Registration_Info_UClass_UJMHideDoorMechanismComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMHideDoorMechanismComponent.OuterSingleton, Z_Construct_UClass_UJMHideDoorMechanismComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMHideDoorMechanismComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMHideDoorMechanismComponent);
UJMHideDoorMechanismComponent::~UJMHideDoorMechanismComponent() {}
// ********** End Class UJMHideDoorMechanismComponent **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHideDoorIntegration_Source_JMHideDoorIntegration_Public_Components_JMHideDoorMechanismComponent_h__Script_JMHideDoorIntegration_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMHideDoorMechanismComponent, UJMHideDoorMechanismComponent::StaticClass, TEXT("UJMHideDoorMechanismComponent"), &Z_Registration_Info_UClass_UJMHideDoorMechanismComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMHideDoorMechanismComponent), 378962867U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHideDoorIntegration_Source_JMHideDoorIntegration_Public_Components_JMHideDoorMechanismComponent_h__Script_JMHideDoorIntegration_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHideDoorIntegration_Source_JMHideDoorIntegration_Public_Components_JMHideDoorMechanismComponent_h__Script_JMHideDoorIntegration_2831414748{
	TEXT("/Script/JMHideDoorIntegration"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHideDoorIntegration_Source_JMHideDoorIntegration_Public_Components_JMHideDoorMechanismComponent_h__Script_JMHideDoorIntegration_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHideDoorIntegration_Source_JMHideDoorIntegration_Public_Components_JMHideDoorMechanismComponent_h__Script_JMHideDoorIntegration_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
