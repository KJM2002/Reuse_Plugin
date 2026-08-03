// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/JMReconPromptWidgetBase.h"
#include "Types/JMInteractionTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMReconPromptWidgetBase() {}

// ********** Begin Cross Module References ********************************************************
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionPromptStyle();
JMRECONGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMReconPromptWidgetBase();
JMRECONGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMReconPromptWidgetBase_NoRegister();
UMG_API UClass* Z_Construct_UClass_UBorder_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_JMReconGameplayIntegration();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMReconPromptWidgetBase Function ApplyReconPromptStyle ******************
struct JMReconPromptWidgetBase_eventApplyReconPromptStyle_Parms
{
	FJMInteractionPromptStyle Style;
};
static FName NAME_UJMReconPromptWidgetBase_ApplyReconPromptStyle = FName(TEXT("ApplyReconPromptStyle"));
void UJMReconPromptWidgetBase::ApplyReconPromptStyle(FJMInteractionPromptStyle const& Style)
{
	UFunction* Func = FindFunctionChecked(NAME_UJMReconPromptWidgetBase_ApplyReconPromptStyle);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		JMReconPromptWidgetBase_eventApplyReconPromptStyle_Parms Parms;
		Parms.Style=Style;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		ApplyReconPromptStyle_Implementation(Style);
	}
}
struct Z_Construct_UFunction_UJMReconPromptWidgetBase_ApplyReconPromptStyle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Recon|UI" },
		{ "ModuleRelativePath", "Public/UI/JMReconPromptWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Style_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ApplyReconPromptStyle constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Style;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ApplyReconPromptStyle constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ApplyReconPromptStyle Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMReconPromptWidgetBase_ApplyReconPromptStyle_Statics::NewProp_Style = { "Style", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconPromptWidgetBase_eventApplyReconPromptStyle_Parms, Style), Z_Construct_UScriptStruct_FJMInteractionPromptStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Style_MetaData), NewProp_Style_MetaData) }; // 2420317743
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconPromptWidgetBase_ApplyReconPromptStyle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPromptWidgetBase_ApplyReconPromptStyle_Statics::NewProp_Style,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPromptWidgetBase_ApplyReconPromptStyle_Statics::PropPointers) < 2048);
// ********** End Function ApplyReconPromptStyle Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconPromptWidgetBase_ApplyReconPromptStyle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconPromptWidgetBase, nullptr, "ApplyReconPromptStyle", 	Z_Construct_UFunction_UJMReconPromptWidgetBase_ApplyReconPromptStyle_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPromptWidgetBase_ApplyReconPromptStyle_Statics::PropPointers), 
sizeof(JMReconPromptWidgetBase_eventApplyReconPromptStyle_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPromptWidgetBase_ApplyReconPromptStyle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconPromptWidgetBase_ApplyReconPromptStyle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMReconPromptWidgetBase_eventApplyReconPromptStyle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconPromptWidgetBase_ApplyReconPromptStyle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconPromptWidgetBase_ApplyReconPromptStyle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMReconPromptWidgetBase::execApplyReconPromptStyle)
{
	P_GET_STRUCT_REF(FJMInteractionPromptStyle,Z_Param_Out_Style);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ApplyReconPromptStyle_Implementation(Z_Param_Out_Style);
	P_NATIVE_END;
}
// ********** End Class UJMReconPromptWidgetBase Function ApplyReconPromptStyle ********************

// ********** Begin Class UJMReconPromptWidgetBase Function GetDisplayedPrompt *********************
struct Z_Construct_UFunction_UJMReconPromptWidgetBase_GetDisplayedPrompt_Statics
{
	struct JMReconPromptWidgetBase_eventGetDisplayedPrompt_Parms
	{
		FText ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Recon|UI" },
		{ "ModuleRelativePath", "Public/UI/JMReconPromptWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDisplayedPrompt constinit property declarations ********************
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDisplayedPrompt constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDisplayedPrompt Property Definitions *******************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UJMReconPromptWidgetBase_GetDisplayedPrompt_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconPromptWidgetBase_eventGetDisplayedPrompt_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconPromptWidgetBase_GetDisplayedPrompt_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPromptWidgetBase_GetDisplayedPrompt_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPromptWidgetBase_GetDisplayedPrompt_Statics::PropPointers) < 2048);
// ********** End Function GetDisplayedPrompt Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconPromptWidgetBase_GetDisplayedPrompt_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconPromptWidgetBase, nullptr, "GetDisplayedPrompt", 	Z_Construct_UFunction_UJMReconPromptWidgetBase_GetDisplayedPrompt_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPromptWidgetBase_GetDisplayedPrompt_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMReconPromptWidgetBase_GetDisplayedPrompt_Statics::JMReconPromptWidgetBase_eventGetDisplayedPrompt_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPromptWidgetBase_GetDisplayedPrompt_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconPromptWidgetBase_GetDisplayedPrompt_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMReconPromptWidgetBase_GetDisplayedPrompt_Statics::JMReconPromptWidgetBase_eventGetDisplayedPrompt_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconPromptWidgetBase_GetDisplayedPrompt()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconPromptWidgetBase_GetDisplayedPrompt_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMReconPromptWidgetBase::execGetDisplayedPrompt)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->GetDisplayedPrompt();
	P_NATIVE_END;
}
// ********** End Class UJMReconPromptWidgetBase Function GetDisplayedPrompt ***********************

// ********** Begin Class UJMReconPromptWidgetBase Function SetReconPrompt *************************
struct JMReconPromptWidgetBase_eventSetReconPrompt_Parms
{
	FText Prompt;
	bool bVisible;
};
static FName NAME_UJMReconPromptWidgetBase_SetReconPrompt = FName(TEXT("SetReconPrompt"));
void UJMReconPromptWidgetBase::SetReconPrompt(FText const& Prompt, bool bVisible)
{
	UFunction* Func = FindFunctionChecked(NAME_UJMReconPromptWidgetBase_SetReconPrompt);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		JMReconPromptWidgetBase_eventSetReconPrompt_Parms Parms;
		Parms.Prompt=Prompt;
		Parms.bVisible=bVisible ? true : false;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		SetReconPrompt_Implementation(Prompt, bVisible);
	}
}
struct Z_Construct_UFunction_UJMReconPromptWidgetBase_SetReconPrompt_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Recon|UI" },
		{ "ModuleRelativePath", "Public/UI/JMReconPromptWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Prompt_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetReconPrompt constinit property declarations ************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Prompt;
	static void NewProp_bVisible_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bVisible;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetReconPrompt constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetReconPrompt Property Definitions ***********************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UJMReconPromptWidgetBase_SetReconPrompt_Statics::NewProp_Prompt = { "Prompt", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconPromptWidgetBase_eventSetReconPrompt_Parms, Prompt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Prompt_MetaData), NewProp_Prompt_MetaData) };
void Z_Construct_UFunction_UJMReconPromptWidgetBase_SetReconPrompt_Statics::NewProp_bVisible_SetBit(void* Obj)
{
	((JMReconPromptWidgetBase_eventSetReconPrompt_Parms*)Obj)->bVisible = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMReconPromptWidgetBase_SetReconPrompt_Statics::NewProp_bVisible = { "bVisible", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMReconPromptWidgetBase_eventSetReconPrompt_Parms), &Z_Construct_UFunction_UJMReconPromptWidgetBase_SetReconPrompt_Statics::NewProp_bVisible_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconPromptWidgetBase_SetReconPrompt_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPromptWidgetBase_SetReconPrompt_Statics::NewProp_Prompt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPromptWidgetBase_SetReconPrompt_Statics::NewProp_bVisible,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPromptWidgetBase_SetReconPrompt_Statics::PropPointers) < 2048);
// ********** End Function SetReconPrompt Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconPromptWidgetBase_SetReconPrompt_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconPromptWidgetBase, nullptr, "SetReconPrompt", 	Z_Construct_UFunction_UJMReconPromptWidgetBase_SetReconPrompt_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPromptWidgetBase_SetReconPrompt_Statics::PropPointers), 
sizeof(JMReconPromptWidgetBase_eventSetReconPrompt_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPromptWidgetBase_SetReconPrompt_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconPromptWidgetBase_SetReconPrompt_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMReconPromptWidgetBase_eventSetReconPrompt_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconPromptWidgetBase_SetReconPrompt()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconPromptWidgetBase_SetReconPrompt_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMReconPromptWidgetBase::execSetReconPrompt)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Prompt);
	P_GET_UBOOL(Z_Param_bVisible);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetReconPrompt_Implementation(Z_Param_Out_Prompt,Z_Param_bVisible);
	P_NATIVE_END;
}
// ********** End Class UJMReconPromptWidgetBase Function SetReconPrompt ***************************

// ********** Begin Class UJMReconPromptWidgetBase *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMReconPromptWidgetBase;
UClass* UJMReconPromptWidgetBase::GetPrivateStaticClass()
{
	using TClass = UJMReconPromptWidgetBase;
	if (!Z_Registration_Info_UClass_UJMReconPromptWidgetBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMReconPromptWidgetBase"),
			Z_Registration_Info_UClass_UJMReconPromptWidgetBase.InnerSingleton,
			StaticRegisterNativesUJMReconPromptWidgetBase,
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
	return Z_Registration_Info_UClass_UJMReconPromptWidgetBase.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMReconPromptWidgetBase_NoRegister()
{
	return UJMReconPromptWidgetBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMReconPromptWidgetBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "UI/JMReconPromptWidgetBase.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/UI/JMReconPromptWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PromptText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "JMReconPromptWidgetBase" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/JMReconPromptWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PromptContainer_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "JMReconPromptWidgetBase" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/JMReconPromptWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMReconPromptWidgetBase constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PromptText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PromptContainer;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMReconPromptWidgetBase constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ApplyReconPromptStyle"), .Pointer = &UJMReconPromptWidgetBase::execApplyReconPromptStyle },
		{ .NameUTF8 = UTF8TEXT("GetDisplayedPrompt"), .Pointer = &UJMReconPromptWidgetBase::execGetDisplayedPrompt },
		{ .NameUTF8 = UTF8TEXT("SetReconPrompt"), .Pointer = &UJMReconPromptWidgetBase::execSetReconPrompt },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMReconPromptWidgetBase_ApplyReconPromptStyle, "ApplyReconPromptStyle" }, // 4030415143
		{ &Z_Construct_UFunction_UJMReconPromptWidgetBase_GetDisplayedPrompt, "GetDisplayedPrompt" }, // 3422263115
		{ &Z_Construct_UFunction_UJMReconPromptWidgetBase_SetReconPrompt, "SetReconPrompt" }, // 4288643266
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMReconPromptWidgetBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMReconPromptWidgetBase_Statics

// ********** Begin Class UJMReconPromptWidgetBase Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMReconPromptWidgetBase_Statics::NewProp_PromptText = { "PromptText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconPromptWidgetBase, PromptText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PromptText_MetaData), NewProp_PromptText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMReconPromptWidgetBase_Statics::NewProp_PromptContainer = { "PromptContainer", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconPromptWidgetBase, PromptContainer), Z_Construct_UClass_UBorder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PromptContainer_MetaData), NewProp_PromptContainer_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMReconPromptWidgetBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconPromptWidgetBase_Statics::NewProp_PromptText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconPromptWidgetBase_Statics::NewProp_PromptContainer,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconPromptWidgetBase_Statics::PropPointers) < 2048);
// ********** End Class UJMReconPromptWidgetBase Property Definitions ******************************
UObject* (*const Z_Construct_UClass_UJMReconPromptWidgetBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_JMReconGameplayIntegration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconPromptWidgetBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMReconPromptWidgetBase_Statics::ClassParams = {
	&UJMReconPromptWidgetBase::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMReconPromptWidgetBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconPromptWidgetBase_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconPromptWidgetBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMReconPromptWidgetBase_Statics::Class_MetaDataParams)
};
void UJMReconPromptWidgetBase::StaticRegisterNativesUJMReconPromptWidgetBase()
{
	UClass* Class = UJMReconPromptWidgetBase::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMReconPromptWidgetBase_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMReconPromptWidgetBase()
{
	if (!Z_Registration_Info_UClass_UJMReconPromptWidgetBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMReconPromptWidgetBase.OuterSingleton, Z_Construct_UClass_UJMReconPromptWidgetBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMReconPromptWidgetBase.OuterSingleton;
}
UJMReconPromptWidgetBase::UJMReconPromptWidgetBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMReconPromptWidgetBase);
UJMReconPromptWidgetBase::~UJMReconPromptWidgetBase() {}
// ********** End Class UJMReconPromptWidgetBase ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_UI_JMReconPromptWidgetBase_h__Script_JMReconGameplayIntegration_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMReconPromptWidgetBase, UJMReconPromptWidgetBase::StaticClass, TEXT("UJMReconPromptWidgetBase"), &Z_Registration_Info_UClass_UJMReconPromptWidgetBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMReconPromptWidgetBase), 1695473345U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_UI_JMReconPromptWidgetBase_h__Script_JMReconGameplayIntegration_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_UI_JMReconPromptWidgetBase_h__Script_JMReconGameplayIntegration_561237710{
	TEXT("/Script/JMReconGameplayIntegration"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_UI_JMReconPromptWidgetBase_h__Script_JMReconGameplayIntegration_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_UI_JMReconPromptWidgetBase_h__Script_JMReconGameplayIntegration_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
