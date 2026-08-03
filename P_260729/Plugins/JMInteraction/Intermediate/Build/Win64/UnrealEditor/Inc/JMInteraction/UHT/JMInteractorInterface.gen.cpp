// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interfaces/JMInteractorInterface.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMInteractorInterface() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractorInterface();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractorInterface_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMInteraction();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface UJMInteractorInterface Function GetInteractionView *******************
struct JMInteractorInterface_eventGetInteractionView_Parms
{
	FVector OutLocation;
	FVector OutDirection;
};
void IJMInteractorInterface::GetInteractionView(FVector& OutLocation, FVector& OutDirection) const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetInteractionView instead.");
}
static FName NAME_UJMInteractorInterface_GetInteractionView = FName(TEXT("GetInteractionView"));
void IJMInteractorInterface::Execute_GetInteractionView(const UObject* O, FVector& OutLocation, FVector& OutDirection)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMInteractorInterface::StaticClass()));
	JMInteractorInterface_eventGetInteractionView_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMInteractorInterface_GetInteractionView);
	if (Func)
	{
		Parms.OutLocation=std::move(OutLocation);
		Parms.OutDirection=std::move(OutDirection);
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
		OutLocation=std::move(Parms.OutLocation);
		OutDirection=std::move(Parms.OutDirection);
	}
	else if (auto I = (const IJMInteractorInterface*)(O->GetNativeInterfaceAddress(UJMInteractorInterface::StaticClass())))
	{
		I->GetInteractionView_Implementation(OutLocation,OutDirection);
	}
}
struct Z_Construct_UFunction_UJMInteractorInterface_GetInteractionView_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Interfaces/JMInteractorInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetInteractionView constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutDirection;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetInteractionView constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetInteractionView Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractorInterface_GetInteractionView_Statics::NewProp_OutLocation = { "OutLocation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractorInterface_eventGetInteractionView_Parms, OutLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractorInterface_GetInteractionView_Statics::NewProp_OutDirection = { "OutDirection", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractorInterface_eventGetInteractionView_Parms, OutDirection), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractorInterface_GetInteractionView_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractorInterface_GetInteractionView_Statics::NewProp_OutLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractorInterface_GetInteractionView_Statics::NewProp_OutDirection,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractorInterface_GetInteractionView_Statics::PropPointers) < 2048);
// ********** End Function GetInteractionView Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractorInterface_GetInteractionView_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractorInterface, nullptr, "GetInteractionView", 	Z_Construct_UFunction_UJMInteractorInterface_GetInteractionView_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractorInterface_GetInteractionView_Statics::PropPointers), 
sizeof(JMInteractorInterface_eventGetInteractionView_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5CC20C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractorInterface_GetInteractionView_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractorInterface_GetInteractionView_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMInteractorInterface_eventGetInteractionView_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractorInterface_GetInteractionView()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractorInterface_GetInteractionView_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMInteractorInterface::execGetInteractionView)
{
	P_GET_STRUCT_REF(FVector,Z_Param_Out_OutLocation);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_OutDirection);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GetInteractionView_Implementation(Z_Param_Out_OutLocation,Z_Param_Out_OutDirection);
	P_NATIVE_END;
}
// ********** End Interface UJMInteractorInterface Function GetInteractionView *********************

// ********** Begin Interface UJMInteractorInterface Function GetInteractorTags ********************
struct JMInteractorInterface_eventGetInteractorTags_Parms
{
	FGameplayTagContainer ReturnValue;
};
FGameplayTagContainer IJMInteractorInterface::GetInteractorTags() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetInteractorTags instead.");
	JMInteractorInterface_eventGetInteractorTags_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UJMInteractorInterface_GetInteractorTags = FName(TEXT("GetInteractorTags"));
FGameplayTagContainer IJMInteractorInterface::Execute_GetInteractorTags(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMInteractorInterface::StaticClass()));
	JMInteractorInterface_eventGetInteractorTags_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMInteractorInterface_GetInteractorTags);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IJMInteractorInterface*)(O->GetNativeInterfaceAddress(UJMInteractorInterface::StaticClass())))
	{
		Parms.ReturnValue = I->GetInteractorTags_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UJMInteractorInterface_GetInteractorTags_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Interfaces/JMInteractorInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetInteractorTags constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetInteractorTags constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetInteractorTags Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractorInterface_GetInteractorTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractorInterface_eventGetInteractorTags_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(0, nullptr) }; // 3438578166
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractorInterface_GetInteractorTags_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractorInterface_GetInteractorTags_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractorInterface_GetInteractorTags_Statics::PropPointers) < 2048);
// ********** End Function GetInteractorTags Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractorInterface_GetInteractorTags_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractorInterface, nullptr, "GetInteractorTags", 	Z_Construct_UFunction_UJMInteractorInterface_GetInteractorTags_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractorInterface_GetInteractorTags_Statics::PropPointers), 
sizeof(JMInteractorInterface_eventGetInteractorTags_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractorInterface_GetInteractorTags_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractorInterface_GetInteractorTags_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMInteractorInterface_eventGetInteractorTags_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractorInterface_GetInteractorTags()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractorInterface_GetInteractorTags_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMInteractorInterface::execGetInteractorTags)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGameplayTagContainer*)Z_Param__Result=P_THIS->GetInteractorTags_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UJMInteractorInterface Function GetInteractorTags **********************

// ********** Begin Interface UJMInteractorInterface ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMInteractorInterface;
UClass* UJMInteractorInterface::GetPrivateStaticClass()
{
	using TClass = UJMInteractorInterface;
	if (!Z_Registration_Info_UClass_UJMInteractorInterface.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMInteractorInterface"),
			Z_Registration_Info_UClass_UJMInteractorInterface.InnerSingleton,
			StaticRegisterNativesUJMInteractorInterface,
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
	return Z_Registration_Info_UClass_UJMInteractorInterface.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMInteractorInterface_NoRegister()
{
	return UJMInteractorInterface::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMInteractorInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Interfaces/JMInteractorInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface UJMInteractorInterface constinit property declarations ***************
// ********** End Interface UJMInteractorInterface constinit property declarations *****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetInteractionView"), .Pointer = &IJMInteractorInterface::execGetInteractionView },
		{ .NameUTF8 = UTF8TEXT("GetInteractorTags"), .Pointer = &IJMInteractorInterface::execGetInteractorTags },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMInteractorInterface_GetInteractionView, "GetInteractionView" }, // 2262637651
		{ &Z_Construct_UFunction_UJMInteractorInterface_GetInteractorTags, "GetInteractorTags" }, // 2740999966
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IJMInteractorInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMInteractorInterface_Statics
UObject* (*const Z_Construct_UClass_UJMInteractorInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_JMInteraction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractorInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMInteractorInterface_Statics::ClassParams = {
	&UJMInteractorInterface::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractorInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMInteractorInterface_Statics::Class_MetaDataParams)
};
void UJMInteractorInterface::StaticRegisterNativesUJMInteractorInterface()
{
	UClass* Class = UJMInteractorInterface::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMInteractorInterface_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMInteractorInterface()
{
	if (!Z_Registration_Info_UClass_UJMInteractorInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMInteractorInterface.OuterSingleton, Z_Construct_UClass_UJMInteractorInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMInteractorInterface.OuterSingleton;
}
UJMInteractorInterface::UJMInteractorInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMInteractorInterface);
// ********** End Interface UJMInteractorInterface *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractorInterface_h__Script_JMInteraction_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMInteractorInterface, UJMInteractorInterface::StaticClass, TEXT("UJMInteractorInterface"), &Z_Registration_Info_UClass_UJMInteractorInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMInteractorInterface), 592510994U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractorInterface_h__Script_JMInteraction_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractorInterface_h__Script_JMInteraction_2713289080{
	TEXT("/Script/JMInteraction"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractorInterface_h__Script_JMInteraction_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractorInterface_h__Script_JMInteraction_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
