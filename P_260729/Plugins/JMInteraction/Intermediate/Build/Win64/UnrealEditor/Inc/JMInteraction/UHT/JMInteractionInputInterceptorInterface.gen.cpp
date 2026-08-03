// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interfaces/JMInteractionInputInterceptorInterface.h"
#include "Types/JMInteractionTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMInteractionInputInterceptorInterface() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractionInputInterceptorInterface();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractionInputInterceptorInterface_NoRegister();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionResult();
UPackage* Z_Construct_UPackage__Script_JMInteraction();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface UJMInteractionInputInterceptorInterface Function TryHandleInteractionInput 
struct JMInteractionInputInterceptorInterface_eventTryHandleInteractionInput_Parms
{
	FJMInteractionResult OutResult;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	JMInteractionInputInterceptorInterface_eventTryHandleInteractionInput_Parms()
		: ReturnValue(false)
	{
	}
};
bool IJMInteractionInputInterceptorInterface::TryHandleInteractionInput(FJMInteractionResult& OutResult)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_TryHandleInteractionInput instead.");
	JMInteractionInputInterceptorInterface_eventTryHandleInteractionInput_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UJMInteractionInputInterceptorInterface_TryHandleInteractionInput = FName(TEXT("TryHandleInteractionInput"));
bool IJMInteractionInputInterceptorInterface::Execute_TryHandleInteractionInput(UObject* O, FJMInteractionResult& OutResult)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMInteractionInputInterceptorInterface::StaticClass()));
	JMInteractionInputInterceptorInterface_eventTryHandleInteractionInput_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMInteractionInputInterceptorInterface_TryHandleInteractionInput);
	if (Func)
	{
		Parms.OutResult=std::move(OutResult);
		O->ProcessEvent(Func, &Parms);
		OutResult=std::move(Parms.OutResult);
	}
	else if (auto I = (IJMInteractionInputInterceptorInterface*)(O->GetNativeInterfaceAddress(UJMInteractionInputInterceptorInterface::StaticClass())))
	{
		Parms.ReturnValue = I->TryHandleInteractionInput_Implementation(OutResult);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UJMInteractionInputInterceptorInterface_TryHandleInteractionInput_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction|Input" },
		{ "ModuleRelativePath", "Public/Interfaces/JMInteractionInputInterceptorInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function TryHandleInteractionInput constinit property declarations *************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutResult;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TryHandleInteractionInput constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TryHandleInteractionInput Property Definitions ************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractionInputInterceptorInterface_TryHandleInteractionInput_Statics::NewProp_OutResult = { "OutResult", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractionInputInterceptorInterface_eventTryHandleInteractionInput_Parms, OutResult), Z_Construct_UScriptStruct_FJMInteractionResult, METADATA_PARAMS(0, nullptr) }; // 240276497
void Z_Construct_UFunction_UJMInteractionInputInterceptorInterface_TryHandleInteractionInput_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMInteractionInputInterceptorInterface_eventTryHandleInteractionInput_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMInteractionInputInterceptorInterface_TryHandleInteractionInput_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMInteractionInputInterceptorInterface_eventTryHandleInteractionInput_Parms), &Z_Construct_UFunction_UJMInteractionInputInterceptorInterface_TryHandleInteractionInput_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractionInputInterceptorInterface_TryHandleInteractionInput_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionInputInterceptorInterface_TryHandleInteractionInput_Statics::NewProp_OutResult,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionInputInterceptorInterface_TryHandleInteractionInput_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionInputInterceptorInterface_TryHandleInteractionInput_Statics::PropPointers) < 2048);
// ********** End Function TryHandleInteractionInput Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractionInputInterceptorInterface_TryHandleInteractionInput_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractionInputInterceptorInterface, nullptr, "TryHandleInteractionInput", 	Z_Construct_UFunction_UJMInteractionInputInterceptorInterface_TryHandleInteractionInput_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionInputInterceptorInterface_TryHandleInteractionInput_Statics::PropPointers), 
sizeof(JMInteractionInputInterceptorInterface_eventTryHandleInteractionInput_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionInputInterceptorInterface_TryHandleInteractionInput_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractionInputInterceptorInterface_TryHandleInteractionInput_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMInteractionInputInterceptorInterface_eventTryHandleInteractionInput_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractionInputInterceptorInterface_TryHandleInteractionInput()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractionInputInterceptorInterface_TryHandleInteractionInput_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMInteractionInputInterceptorInterface::execTryHandleInteractionInput)
{
	P_GET_STRUCT_REF(FJMInteractionResult,Z_Param_Out_OutResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->TryHandleInteractionInput_Implementation(Z_Param_Out_OutResult);
	P_NATIVE_END;
}
// ********** End Interface UJMInteractionInputInterceptorInterface Function TryHandleInteractionInput 

// ********** Begin Interface UJMInteractionInputInterceptorInterface ******************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMInteractionInputInterceptorInterface;
UClass* UJMInteractionInputInterceptorInterface::GetPrivateStaticClass()
{
	using TClass = UJMInteractionInputInterceptorInterface;
	if (!Z_Registration_Info_UClass_UJMInteractionInputInterceptorInterface.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMInteractionInputInterceptorInterface"),
			Z_Registration_Info_UClass_UJMInteractionInputInterceptorInterface.InnerSingleton,
			StaticRegisterNativesUJMInteractionInputInterceptorInterface,
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
	return Z_Registration_Info_UClass_UJMInteractionInputInterceptorInterface.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMInteractionInputInterceptorInterface_NoRegister()
{
	return UJMInteractionInputInterceptorInterface::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMInteractionInputInterceptorInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Interfaces/JMInteractionInputInterceptorInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface UJMInteractionInputInterceptorInterface constinit property declarations 
// ********** End Interface UJMInteractionInputInterceptorInterface constinit property declarations 
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("TryHandleInteractionInput"), .Pointer = &IJMInteractionInputInterceptorInterface::execTryHandleInteractionInput },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMInteractionInputInterceptorInterface_TryHandleInteractionInput, "TryHandleInteractionInput" }, // 3052098956
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IJMInteractionInputInterceptorInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMInteractionInputInterceptorInterface_Statics
UObject* (*const Z_Construct_UClass_UJMInteractionInputInterceptorInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_JMInteraction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractionInputInterceptorInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMInteractionInputInterceptorInterface_Statics::ClassParams = {
	&UJMInteractionInputInterceptorInterface::StaticClass,
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
	0x001040A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractionInputInterceptorInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMInteractionInputInterceptorInterface_Statics::Class_MetaDataParams)
};
void UJMInteractionInputInterceptorInterface::StaticRegisterNativesUJMInteractionInputInterceptorInterface()
{
	UClass* Class = UJMInteractionInputInterceptorInterface::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMInteractionInputInterceptorInterface_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMInteractionInputInterceptorInterface()
{
	if (!Z_Registration_Info_UClass_UJMInteractionInputInterceptorInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMInteractionInputInterceptorInterface.OuterSingleton, Z_Construct_UClass_UJMInteractionInputInterceptorInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMInteractionInputInterceptorInterface.OuterSingleton;
}
UJMInteractionInputInterceptorInterface::UJMInteractionInputInterceptorInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMInteractionInputInterceptorInterface);
// ********** End Interface UJMInteractionInputInterceptorInterface ********************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractionInputInterceptorInterface_h__Script_JMInteraction_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMInteractionInputInterceptorInterface, UJMInteractionInputInterceptorInterface::StaticClass, TEXT("UJMInteractionInputInterceptorInterface"), &Z_Registration_Info_UClass_UJMInteractionInputInterceptorInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMInteractionInputInterceptorInterface), 4049927490U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractionInputInterceptorInterface_h__Script_JMInteraction_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractionInputInterceptorInterface_h__Script_JMInteraction_76103983{
	TEXT("/Script/JMInteraction"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractionInputInterceptorInterface_h__Script_JMInteraction_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractionInputInterceptorInterface_h__Script_JMInteraction_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
