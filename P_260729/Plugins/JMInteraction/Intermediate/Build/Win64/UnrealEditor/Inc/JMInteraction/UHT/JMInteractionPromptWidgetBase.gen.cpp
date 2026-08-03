// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/JMInteractionPromptWidgetBase.h"
#include "Types/JMInteractionTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMInteractionPromptWidgetBase() {}

// ********** Begin Cross Module References ********************************************************
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractionPromptWidgetBase();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractionPromptWidgetBase_NoRegister();
JMINTERACTION_API UFunction* Z_Construct_UDelegateFunction_JMInteraction_JMPromptStyleEvent__DelegateSignature();
JMINTERACTION_API UFunction* Z_Construct_UDelegateFunction_JMInteraction_JMPromptTextEvent__DelegateSignature();
JMINTERACTION_API UFunction* Z_Construct_UDelegateFunction_JMInteraction_JMPromptVisibilityEvent__DelegateSignature();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionPrompt();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionPromptStyle();
UMG_API UClass* Z_Construct_UClass_UBorder_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_JMInteraction();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FJMPromptTextEvent ****************************************************
struct Z_Construct_UDelegateFunction_JMInteraction_JMPromptTextEvent__DelegateSignature_Statics
{
	struct _Script_JMInteraction_eventJMPromptTextEvent_Parms
	{
		FText PromptText;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/JMInteractionPromptWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMPromptTextEvent constinit property declarations ********************
	static const UECodeGen_Private::FTextPropertyParams NewProp_PromptText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMPromptTextEvent constinit property declarations **********************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMPromptTextEvent Property Definitions *******************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UDelegateFunction_JMInteraction_JMPromptTextEvent__DelegateSignature_Statics::NewProp_PromptText = { "PromptText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMInteraction_eventJMPromptTextEvent_Parms, PromptText), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMInteraction_JMPromptTextEvent__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMInteraction_JMPromptTextEvent__DelegateSignature_Statics::NewProp_PromptText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMInteraction_JMPromptTextEvent__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMPromptTextEvent Property Definitions *********************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMInteraction_JMPromptTextEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMInteraction, nullptr, "JMPromptTextEvent__DelegateSignature", 	Z_Construct_UDelegateFunction_JMInteraction_JMPromptTextEvent__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMInteraction_JMPromptTextEvent__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMInteraction_JMPromptTextEvent__DelegateSignature_Statics::_Script_JMInteraction_eventJMPromptTextEvent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMInteraction_JMPromptTextEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMInteraction_JMPromptTextEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMInteraction_JMPromptTextEvent__DelegateSignature_Statics::_Script_JMInteraction_eventJMPromptTextEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMInteraction_JMPromptTextEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMInteraction_JMPromptTextEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMPromptTextEvent_DelegateWrapper(const FMulticastScriptDelegate& JMPromptTextEvent, const FText& PromptText)
{
	struct _Script_JMInteraction_eventJMPromptTextEvent_Parms
	{
		FText PromptText;
	};
	_Script_JMInteraction_eventJMPromptTextEvent_Parms Parms;
	Parms.PromptText=PromptText;
	JMPromptTextEvent.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMPromptTextEvent ******************************************************

// ********** Begin Delegate FJMPromptVisibilityEvent **********************************************
struct Z_Construct_UDelegateFunction_JMInteraction_JMPromptVisibilityEvent__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/JMInteractionPromptWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMPromptVisibilityEvent constinit property declarations **************
// ********** End Delegate FJMPromptVisibilityEvent constinit property declarations ****************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMInteraction_JMPromptVisibilityEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMInteraction, nullptr, "JMPromptVisibilityEvent__DelegateSignature", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMInteraction_JMPromptVisibilityEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMInteraction_JMPromptVisibilityEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_JMInteraction_JMPromptVisibilityEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMInteraction_JMPromptVisibilityEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMPromptVisibilityEvent_DelegateWrapper(const FMulticastScriptDelegate& JMPromptVisibilityEvent)
{
	JMPromptVisibilityEvent.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FJMPromptVisibilityEvent ************************************************

// ********** Begin Delegate FJMPromptStyleEvent ***************************************************
struct Z_Construct_UDelegateFunction_JMInteraction_JMPromptStyleEvent__DelegateSignature_Statics
{
	struct _Script_JMInteraction_eventJMPromptStyleEvent_Parms
	{
		FJMInteractionPromptStyle PromptStyle;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/JMInteractionPromptWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMPromptStyleEvent constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_PromptStyle;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMPromptStyleEvent constinit property declarations *********************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMPromptStyleEvent Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_JMInteraction_JMPromptStyleEvent__DelegateSignature_Statics::NewProp_PromptStyle = { "PromptStyle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMInteraction_eventJMPromptStyleEvent_Parms, PromptStyle), Z_Construct_UScriptStruct_FJMInteractionPromptStyle, METADATA_PARAMS(0, nullptr) }; // 2420317743
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMInteraction_JMPromptStyleEvent__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMInteraction_JMPromptStyleEvent__DelegateSignature_Statics::NewProp_PromptStyle,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMInteraction_JMPromptStyleEvent__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMPromptStyleEvent Property Definitions ********************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMInteraction_JMPromptStyleEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMInteraction, nullptr, "JMPromptStyleEvent__DelegateSignature", 	Z_Construct_UDelegateFunction_JMInteraction_JMPromptStyleEvent__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMInteraction_JMPromptStyleEvent__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMInteraction_JMPromptStyleEvent__DelegateSignature_Statics::_Script_JMInteraction_eventJMPromptStyleEvent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMInteraction_JMPromptStyleEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMInteraction_JMPromptStyleEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMInteraction_JMPromptStyleEvent__DelegateSignature_Statics::_Script_JMInteraction_eventJMPromptStyleEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMInteraction_JMPromptStyleEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMInteraction_JMPromptStyleEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMPromptStyleEvent_DelegateWrapper(const FMulticastScriptDelegate& JMPromptStyleEvent, FJMInteractionPromptStyle PromptStyle)
{
	struct _Script_JMInteraction_eventJMPromptStyleEvent_Parms
	{
		FJMInteractionPromptStyle PromptStyle;
	};
	_Script_JMInteraction_eventJMPromptStyleEvent_Parms Parms;
	Parms.PromptStyle=PromptStyle;
	JMPromptStyleEvent.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMPromptStyleEvent *****************************************************

// ********** Begin Class UJMInteractionPromptWidgetBase Function ApplyPromptStyle *****************
struct JMInteractionPromptWidgetBase_eventApplyPromptStyle_Parms
{
	FJMInteractionPromptStyle NewStyle;
};
static FName NAME_UJMInteractionPromptWidgetBase_ApplyPromptStyle = FName(TEXT("ApplyPromptStyle"));
void UJMInteractionPromptWidgetBase::ApplyPromptStyle(FJMInteractionPromptStyle const& NewStyle)
{
	UFunction* Func = FindFunctionChecked(NAME_UJMInteractionPromptWidgetBase_ApplyPromptStyle);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		JMInteractionPromptWidgetBase_eventApplyPromptStyle_Parms Parms;
		Parms.NewStyle=NewStyle;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		ApplyPromptStyle_Implementation(NewStyle);
	}
}
struct Z_Construct_UFunction_UJMInteractionPromptWidgetBase_ApplyPromptStyle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction|UI" },
		{ "ModuleRelativePath", "Public/UI/JMInteractionPromptWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewStyle_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ApplyPromptStyle constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewStyle;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ApplyPromptStyle constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ApplyPromptStyle Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractionPromptWidgetBase_ApplyPromptStyle_Statics::NewProp_NewStyle = { "NewStyle", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractionPromptWidgetBase_eventApplyPromptStyle_Parms, NewStyle), Z_Construct_UScriptStruct_FJMInteractionPromptStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewStyle_MetaData), NewProp_NewStyle_MetaData) }; // 2420317743
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractionPromptWidgetBase_ApplyPromptStyle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionPromptWidgetBase_ApplyPromptStyle_Statics::NewProp_NewStyle,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_ApplyPromptStyle_Statics::PropPointers) < 2048);
// ********** End Function ApplyPromptStyle Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractionPromptWidgetBase_ApplyPromptStyle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractionPromptWidgetBase, nullptr, "ApplyPromptStyle", 	Z_Construct_UFunction_UJMInteractionPromptWidgetBase_ApplyPromptStyle_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_ApplyPromptStyle_Statics::PropPointers), 
sizeof(JMInteractionPromptWidgetBase_eventApplyPromptStyle_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_ApplyPromptStyle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractionPromptWidgetBase_ApplyPromptStyle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMInteractionPromptWidgetBase_eventApplyPromptStyle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractionPromptWidgetBase_ApplyPromptStyle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractionPromptWidgetBase_ApplyPromptStyle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInteractionPromptWidgetBase::execApplyPromptStyle)
{
	P_GET_STRUCT_REF(FJMInteractionPromptStyle,Z_Param_Out_NewStyle);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ApplyPromptStyle_Implementation(Z_Param_Out_NewStyle);
	P_NATIVE_END;
}
// ********** End Class UJMInteractionPromptWidgetBase Function ApplyPromptStyle *******************

// ********** Begin Class UJMInteractionPromptWidgetBase Function ClearInteractionPrompt ***********
static FName NAME_UJMInteractionPromptWidgetBase_ClearInteractionPrompt = FName(TEXT("ClearInteractionPrompt"));
void UJMInteractionPromptWidgetBase::ClearInteractionPrompt()
{
	UFunction* Func = FindFunctionChecked(NAME_UJMInteractionPromptWidgetBase_ClearInteractionPrompt);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		ClearInteractionPrompt_Implementation();
	}
}
struct Z_Construct_UFunction_UJMInteractionPromptWidgetBase_ClearInteractionPrompt_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction|UI" },
		{ "ModuleRelativePath", "Public/UI/JMInteractionPromptWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ClearInteractionPrompt constinit property declarations ****************
// ********** End Function ClearInteractionPrompt constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractionPromptWidgetBase_ClearInteractionPrompt_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractionPromptWidgetBase, nullptr, "ClearInteractionPrompt", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_ClearInteractionPrompt_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractionPromptWidgetBase_ClearInteractionPrompt_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UJMInteractionPromptWidgetBase_ClearInteractionPrompt()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractionPromptWidgetBase_ClearInteractionPrompt_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInteractionPromptWidgetBase::execClearInteractionPrompt)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearInteractionPrompt_Implementation();
	P_NATIVE_END;
}
// ********** End Class UJMInteractionPromptWidgetBase Function ClearInteractionPrompt *************

// ********** Begin Class UJMInteractionPromptWidgetBase Function GetAppliedPromptStyle ************
struct Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetAppliedPromptStyle_Statics
{
	struct JMInteractionPromptWidgetBase_eventGetAppliedPromptStyle_Parms
	{
		FJMInteractionPromptStyle ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction|UI" },
		{ "ModuleRelativePath", "Public/UI/JMInteractionPromptWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAppliedPromptStyle constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAppliedPromptStyle constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAppliedPromptStyle Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetAppliedPromptStyle_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractionPromptWidgetBase_eventGetAppliedPromptStyle_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMInteractionPromptStyle, METADATA_PARAMS(0, nullptr) }; // 2420317743
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetAppliedPromptStyle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetAppliedPromptStyle_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetAppliedPromptStyle_Statics::PropPointers) < 2048);
// ********** End Function GetAppliedPromptStyle Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetAppliedPromptStyle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractionPromptWidgetBase, nullptr, "GetAppliedPromptStyle", 	Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetAppliedPromptStyle_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetAppliedPromptStyle_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetAppliedPromptStyle_Statics::JMInteractionPromptWidgetBase_eventGetAppliedPromptStyle_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetAppliedPromptStyle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetAppliedPromptStyle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetAppliedPromptStyle_Statics::JMInteractionPromptWidgetBase_eventGetAppliedPromptStyle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetAppliedPromptStyle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetAppliedPromptStyle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInteractionPromptWidgetBase::execGetAppliedPromptStyle)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMInteractionPromptStyle*)Z_Param__Result=P_THIS->GetAppliedPromptStyle();
	P_NATIVE_END;
}
// ********** End Class UJMInteractionPromptWidgetBase Function GetAppliedPromptStyle **************

// ********** Begin Class UJMInteractionPromptWidgetBase Function GetDisplayedPromptText ***********
struct Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetDisplayedPromptText_Statics
{
	struct JMInteractionPromptWidgetBase_eventGetDisplayedPromptText_Parms
	{
		FText ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction|UI" },
		{ "ModuleRelativePath", "Public/UI/JMInteractionPromptWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDisplayedPromptText constinit property declarations ****************
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDisplayedPromptText constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDisplayedPromptText Property Definitions ***************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetDisplayedPromptText_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractionPromptWidgetBase_eventGetDisplayedPromptText_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetDisplayedPromptText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetDisplayedPromptText_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetDisplayedPromptText_Statics::PropPointers) < 2048);
// ********** End Function GetDisplayedPromptText Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetDisplayedPromptText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractionPromptWidgetBase, nullptr, "GetDisplayedPromptText", 	Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetDisplayedPromptText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetDisplayedPromptText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetDisplayedPromptText_Statics::JMInteractionPromptWidgetBase_eventGetDisplayedPromptText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetDisplayedPromptText_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetDisplayedPromptText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetDisplayedPromptText_Statics::JMInteractionPromptWidgetBase_eventGetDisplayedPromptText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetDisplayedPromptText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetDisplayedPromptText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInteractionPromptWidgetBase::execGetDisplayedPromptText)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->GetDisplayedPromptText();
	P_NATIVE_END;
}
// ********** End Class UJMInteractionPromptWidgetBase Function GetDisplayedPromptText *************

// ********** Begin Class UJMInteractionPromptWidgetBase Function IsPromptVisible ******************
struct Z_Construct_UFunction_UJMInteractionPromptWidgetBase_IsPromptVisible_Statics
{
	struct JMInteractionPromptWidgetBase_eventIsPromptVisible_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction|UI" },
		{ "ModuleRelativePath", "Public/UI/JMInteractionPromptWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsPromptVisible constinit property declarations ***********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsPromptVisible constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsPromptVisible Property Definitions **********************************
void Z_Construct_UFunction_UJMInteractionPromptWidgetBase_IsPromptVisible_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMInteractionPromptWidgetBase_eventIsPromptVisible_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMInteractionPromptWidgetBase_IsPromptVisible_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMInteractionPromptWidgetBase_eventIsPromptVisible_Parms), &Z_Construct_UFunction_UJMInteractionPromptWidgetBase_IsPromptVisible_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractionPromptWidgetBase_IsPromptVisible_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionPromptWidgetBase_IsPromptVisible_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_IsPromptVisible_Statics::PropPointers) < 2048);
// ********** End Function IsPromptVisible Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractionPromptWidgetBase_IsPromptVisible_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractionPromptWidgetBase, nullptr, "IsPromptVisible", 	Z_Construct_UFunction_UJMInteractionPromptWidgetBase_IsPromptVisible_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_IsPromptVisible_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_IsPromptVisible_Statics::JMInteractionPromptWidgetBase_eventIsPromptVisible_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_IsPromptVisible_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractionPromptWidgetBase_IsPromptVisible_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_IsPromptVisible_Statics::JMInteractionPromptWidgetBase_eventIsPromptVisible_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractionPromptWidgetBase_IsPromptVisible()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractionPromptWidgetBase_IsPromptVisible_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInteractionPromptWidgetBase::execIsPromptVisible)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsPromptVisible();
	P_NATIVE_END;
}
// ********** End Class UJMInteractionPromptWidgetBase Function IsPromptVisible ********************

// ********** Begin Class UJMInteractionPromptWidgetBase Function SetInteractionPrompt *************
struct JMInteractionPromptWidgetBase_eventSetInteractionPrompt_Parms
{
	FJMInteractionPrompt Prompt;
};
static FName NAME_UJMInteractionPromptWidgetBase_SetInteractionPrompt = FName(TEXT("SetInteractionPrompt"));
void UJMInteractionPromptWidgetBase::SetInteractionPrompt(FJMInteractionPrompt const& Prompt)
{
	UFunction* Func = FindFunctionChecked(NAME_UJMInteractionPromptWidgetBase_SetInteractionPrompt);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		JMInteractionPromptWidgetBase_eventSetInteractionPrompt_Parms Parms;
		Parms.Prompt=Prompt;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		SetInteractionPrompt_Implementation(Prompt);
	}
}
struct Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetInteractionPrompt_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction|UI" },
		{ "ModuleRelativePath", "Public/UI/JMInteractionPromptWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Prompt_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetInteractionPrompt constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Prompt;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetInteractionPrompt constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetInteractionPrompt Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetInteractionPrompt_Statics::NewProp_Prompt = { "Prompt", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractionPromptWidgetBase_eventSetInteractionPrompt_Parms, Prompt), Z_Construct_UScriptStruct_FJMInteractionPrompt, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Prompt_MetaData), NewProp_Prompt_MetaData) }; // 2592379790
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetInteractionPrompt_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetInteractionPrompt_Statics::NewProp_Prompt,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetInteractionPrompt_Statics::PropPointers) < 2048);
// ********** End Function SetInteractionPrompt Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetInteractionPrompt_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractionPromptWidgetBase, nullptr, "SetInteractionPrompt", 	Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetInteractionPrompt_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetInteractionPrompt_Statics::PropPointers), 
sizeof(JMInteractionPromptWidgetBase_eventSetInteractionPrompt_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetInteractionPrompt_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetInteractionPrompt_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMInteractionPromptWidgetBase_eventSetInteractionPrompt_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetInteractionPrompt()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetInteractionPrompt_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInteractionPromptWidgetBase::execSetInteractionPrompt)
{
	P_GET_STRUCT_REF(FJMInteractionPrompt,Z_Param_Out_Prompt);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetInteractionPrompt_Implementation(Z_Param_Out_Prompt);
	P_NATIVE_END;
}
// ********** End Class UJMInteractionPromptWidgetBase Function SetInteractionPrompt ***************

// ********** Begin Class UJMInteractionPromptWidgetBase Function SetPromptText ********************
struct JMInteractionPromptWidgetBase_eventSetPromptText_Parms
{
	FText NewPrompt;
};
static FName NAME_UJMInteractionPromptWidgetBase_SetPromptText = FName(TEXT("SetPromptText"));
void UJMInteractionPromptWidgetBase::SetPromptText(FText const& NewPrompt)
{
	UFunction* Func = FindFunctionChecked(NAME_UJMInteractionPromptWidgetBase_SetPromptText);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		JMInteractionPromptWidgetBase_eventSetPromptText_Parms Parms;
		Parms.NewPrompt=NewPrompt;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		SetPromptText_Implementation(NewPrompt);
	}
}
struct Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptText_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction|UI" },
		{ "ModuleRelativePath", "Public/UI/JMInteractionPromptWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewPrompt_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetPromptText constinit property declarations *************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_NewPrompt;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPromptText constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPromptText Property Definitions ************************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptText_Statics::NewProp_NewPrompt = { "NewPrompt", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractionPromptWidgetBase_eventSetPromptText_Parms, NewPrompt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewPrompt_MetaData), NewProp_NewPrompt_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptText_Statics::NewProp_NewPrompt,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptText_Statics::PropPointers) < 2048);
// ********** End Function SetPromptText Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractionPromptWidgetBase, nullptr, "SetPromptText", 	Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptText_Statics::PropPointers), 
sizeof(JMInteractionPromptWidgetBase_eventSetPromptText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptText_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMInteractionPromptWidgetBase_eventSetPromptText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInteractionPromptWidgetBase::execSetPromptText)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_NewPrompt);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPromptText_Implementation(Z_Param_Out_NewPrompt);
	P_NATIVE_END;
}
// ********** End Class UJMInteractionPromptWidgetBase Function SetPromptText **********************

// ********** Begin Class UJMInteractionPromptWidgetBase Function SetPromptVisible *****************
struct JMInteractionPromptWidgetBase_eventSetPromptVisible_Parms
{
	bool bVisible;
};
static FName NAME_UJMInteractionPromptWidgetBase_SetPromptVisible = FName(TEXT("SetPromptVisible"));
void UJMInteractionPromptWidgetBase::SetPromptVisible(bool bVisible)
{
	UFunction* Func = FindFunctionChecked(NAME_UJMInteractionPromptWidgetBase_SetPromptVisible);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		JMInteractionPromptWidgetBase_eventSetPromptVisible_Parms Parms;
		Parms.bVisible=bVisible ? true : false;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		SetPromptVisible_Implementation(bVisible);
	}
}
struct Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptVisible_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction|UI" },
		{ "ModuleRelativePath", "Public/UI/JMInteractionPromptWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetPromptVisible constinit property declarations **********************
	static void NewProp_bVisible_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bVisible;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPromptVisible constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPromptVisible Property Definitions *********************************
void Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptVisible_Statics::NewProp_bVisible_SetBit(void* Obj)
{
	((JMInteractionPromptWidgetBase_eventSetPromptVisible_Parms*)Obj)->bVisible = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptVisible_Statics::NewProp_bVisible = { "bVisible", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMInteractionPromptWidgetBase_eventSetPromptVisible_Parms), &Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptVisible_Statics::NewProp_bVisible_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptVisible_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptVisible_Statics::NewProp_bVisible,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptVisible_Statics::PropPointers) < 2048);
// ********** End Function SetPromptVisible Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptVisible_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractionPromptWidgetBase, nullptr, "SetPromptVisible", 	Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptVisible_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptVisible_Statics::PropPointers), 
sizeof(JMInteractionPromptWidgetBase_eventSetPromptVisible_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptVisible_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptVisible_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMInteractionPromptWidgetBase_eventSetPromptVisible_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptVisible()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptVisible_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInteractionPromptWidgetBase::execSetPromptVisible)
{
	P_GET_UBOOL(Z_Param_bVisible);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPromptVisible_Implementation(Z_Param_bVisible);
	P_NATIVE_END;
}
// ********** End Class UJMInteractionPromptWidgetBase Function SetPromptVisible *******************

// ********** Begin Class UJMInteractionPromptWidgetBase *******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMInteractionPromptWidgetBase;
UClass* UJMInteractionPromptWidgetBase::GetPrivateStaticClass()
{
	using TClass = UJMInteractionPromptWidgetBase;
	if (!Z_Registration_Info_UClass_UJMInteractionPromptWidgetBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMInteractionPromptWidgetBase"),
			Z_Registration_Info_UClass_UJMInteractionPromptWidgetBase.InnerSingleton,
			StaticRegisterNativesUJMInteractionPromptWidgetBase,
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
	return Z_Registration_Info_UClass_UJMInteractionPromptWidgetBase.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMInteractionPromptWidgetBase_NoRegister()
{
	return UJMInteractionPromptWidgetBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "UI/JMInteractionPromptWidgetBase.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/UI/JMInteractionPromptWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnPromptShown_MetaData[] = {
		{ "Category", "JM Interaction|UI" },
		{ "ModuleRelativePath", "Public/UI/JMInteractionPromptWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnPromptHidden_MetaData[] = {
		{ "Category", "JM Interaction|UI" },
		{ "ModuleRelativePath", "Public/UI/JMInteractionPromptWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnPromptTextChanged_MetaData[] = {
		{ "Category", "JM Interaction|UI" },
		{ "ModuleRelativePath", "Public/UI/JMInteractionPromptWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnPromptStyleApplied_MetaData[] = {
		{ "Category", "JM Interaction|UI" },
		{ "ModuleRelativePath", "Public/UI/JMInteractionPromptWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PromptText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "JM Interaction|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Optional Designer binding. Name a TextBlock \"PromptText\" and enable Is Variable.\n     * The base class then updates text, font size, justification, offset, and scale automatically.\n     */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/JMInteractionPromptWidgetBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional Designer binding. Name a TextBlock \"PromptText\" and enable Is Variable.\nThe base class then updates text, font size, justification, offset, and scale automatically." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PromptContainer_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "JM Interaction|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Optional Designer binding for a background/padded container.\n     * Omit it for a text-only prompt, or name a Border \"PromptContainer\" to style the whole prompt.\n     */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/JMInteractionPromptWidgetBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional Designer binding for a background/padded container.\nOmit it for a text-only prompt, or name a Border \"PromptContainer\" to style the whole prompt." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayedPromptText_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/JMInteractionPromptWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AppliedStyle_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/JMInteractionPromptWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPromptVisible_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/JMInteractionPromptWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMInteractionPromptWidgetBase constinit property declarations ***********
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPromptShown;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPromptHidden;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPromptTextChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPromptStyleApplied;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PromptText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PromptContainer;
	static const UECodeGen_Private::FTextPropertyParams NewProp_DisplayedPromptText;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AppliedStyle;
	static void NewProp_bPromptVisible_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPromptVisible;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMInteractionPromptWidgetBase constinit property declarations *************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ApplyPromptStyle"), .Pointer = &UJMInteractionPromptWidgetBase::execApplyPromptStyle },
		{ .NameUTF8 = UTF8TEXT("ClearInteractionPrompt"), .Pointer = &UJMInteractionPromptWidgetBase::execClearInteractionPrompt },
		{ .NameUTF8 = UTF8TEXT("GetAppliedPromptStyle"), .Pointer = &UJMInteractionPromptWidgetBase::execGetAppliedPromptStyle },
		{ .NameUTF8 = UTF8TEXT("GetDisplayedPromptText"), .Pointer = &UJMInteractionPromptWidgetBase::execGetDisplayedPromptText },
		{ .NameUTF8 = UTF8TEXT("IsPromptVisible"), .Pointer = &UJMInteractionPromptWidgetBase::execIsPromptVisible },
		{ .NameUTF8 = UTF8TEXT("SetInteractionPrompt"), .Pointer = &UJMInteractionPromptWidgetBase::execSetInteractionPrompt },
		{ .NameUTF8 = UTF8TEXT("SetPromptText"), .Pointer = &UJMInteractionPromptWidgetBase::execSetPromptText },
		{ .NameUTF8 = UTF8TEXT("SetPromptVisible"), .Pointer = &UJMInteractionPromptWidgetBase::execSetPromptVisible },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMInteractionPromptWidgetBase_ApplyPromptStyle, "ApplyPromptStyle" }, // 4085590945
		{ &Z_Construct_UFunction_UJMInteractionPromptWidgetBase_ClearInteractionPrompt, "ClearInteractionPrompt" }, // 2994487471
		{ &Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetAppliedPromptStyle, "GetAppliedPromptStyle" }, // 4036491528
		{ &Z_Construct_UFunction_UJMInteractionPromptWidgetBase_GetDisplayedPromptText, "GetDisplayedPromptText" }, // 3771582032
		{ &Z_Construct_UFunction_UJMInteractionPromptWidgetBase_IsPromptVisible, "IsPromptVisible" }, // 3866326183
		{ &Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetInteractionPrompt, "SetInteractionPrompt" }, // 4039442002
		{ &Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptText, "SetPromptText" }, // 2793024780
		{ &Z_Construct_UFunction_UJMInteractionPromptWidgetBase_SetPromptVisible, "SetPromptVisible" }, // 3642625833
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMInteractionPromptWidgetBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics

// ********** Begin Class UJMInteractionPromptWidgetBase Property Definitions **********************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::NewProp_OnPromptShown = { "OnPromptShown", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionPromptWidgetBase, OnPromptShown), Z_Construct_UDelegateFunction_JMInteraction_JMPromptVisibilityEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnPromptShown_MetaData), NewProp_OnPromptShown_MetaData) }; // 3404147160
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::NewProp_OnPromptHidden = { "OnPromptHidden", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionPromptWidgetBase, OnPromptHidden), Z_Construct_UDelegateFunction_JMInteraction_JMPromptVisibilityEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnPromptHidden_MetaData), NewProp_OnPromptHidden_MetaData) }; // 3404147160
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::NewProp_OnPromptTextChanged = { "OnPromptTextChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionPromptWidgetBase, OnPromptTextChanged), Z_Construct_UDelegateFunction_JMInteraction_JMPromptTextEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnPromptTextChanged_MetaData), NewProp_OnPromptTextChanged_MetaData) }; // 379998650
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::NewProp_OnPromptStyleApplied = { "OnPromptStyleApplied", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionPromptWidgetBase, OnPromptStyleApplied), Z_Construct_UDelegateFunction_JMInteraction_JMPromptStyleEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnPromptStyleApplied_MetaData), NewProp_OnPromptStyleApplied_MetaData) }; // 3955019690
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::NewProp_PromptText = { "PromptText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionPromptWidgetBase, PromptText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PromptText_MetaData), NewProp_PromptText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::NewProp_PromptContainer = { "PromptContainer", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionPromptWidgetBase, PromptContainer), Z_Construct_UClass_UBorder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PromptContainer_MetaData), NewProp_PromptContainer_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::NewProp_DisplayedPromptText = { "DisplayedPromptText", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionPromptWidgetBase, DisplayedPromptText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayedPromptText_MetaData), NewProp_DisplayedPromptText_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::NewProp_AppliedStyle = { "AppliedStyle", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionPromptWidgetBase, AppliedStyle), Z_Construct_UScriptStruct_FJMInteractionPromptStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AppliedStyle_MetaData), NewProp_AppliedStyle_MetaData) }; // 2420317743
void Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::NewProp_bPromptVisible_SetBit(void* Obj)
{
	((UJMInteractionPromptWidgetBase*)Obj)->bPromptVisible = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::NewProp_bPromptVisible = { "bPromptVisible", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMInteractionPromptWidgetBase), &Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::NewProp_bPromptVisible_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPromptVisible_MetaData), NewProp_bPromptVisible_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::NewProp_OnPromptShown,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::NewProp_OnPromptHidden,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::NewProp_OnPromptTextChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::NewProp_OnPromptStyleApplied,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::NewProp_PromptText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::NewProp_PromptContainer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::NewProp_DisplayedPromptText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::NewProp_AppliedStyle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::NewProp_bPromptVisible,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::PropPointers) < 2048);
// ********** End Class UJMInteractionPromptWidgetBase Property Definitions ************************
UObject* (*const Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_JMInteraction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::ClassParams = {
	&UJMInteractionPromptWidgetBase::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::Class_MetaDataParams)
};
void UJMInteractionPromptWidgetBase::StaticRegisterNativesUJMInteractionPromptWidgetBase()
{
	UClass* Class = UJMInteractionPromptWidgetBase::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMInteractionPromptWidgetBase()
{
	if (!Z_Registration_Info_UClass_UJMInteractionPromptWidgetBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMInteractionPromptWidgetBase.OuterSingleton, Z_Construct_UClass_UJMInteractionPromptWidgetBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMInteractionPromptWidgetBase.OuterSingleton;
}
UJMInteractionPromptWidgetBase::UJMInteractionPromptWidgetBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMInteractionPromptWidgetBase);
UJMInteractionPromptWidgetBase::~UJMInteractionPromptWidgetBase() {}
// ********** End Class UJMInteractionPromptWidgetBase *********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_UI_JMInteractionPromptWidgetBase_h__Script_JMInteraction_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMInteractionPromptWidgetBase, UJMInteractionPromptWidgetBase::StaticClass, TEXT("UJMInteractionPromptWidgetBase"), &Z_Registration_Info_UClass_UJMInteractionPromptWidgetBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMInteractionPromptWidgetBase), 2553567576U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_UI_JMInteractionPromptWidgetBase_h__Script_JMInteraction_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_UI_JMInteractionPromptWidgetBase_h__Script_JMInteraction_3572194702{
	TEXT("/Script/JMInteraction"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_UI_JMInteractionPromptWidgetBase_h__Script_JMInteraction_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_UI_JMInteractionPromptWidgetBase_h__Script_JMInteraction_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
