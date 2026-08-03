// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueWidgetBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDialogueWidgetBase() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueWidgetBase();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueWidgetBase_NoRegister();
UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
UMG_API UClass* Z_Construct_UClass_UPanelWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UMG_API UClass* Z_Construct_UClass_UWidget_NoRegister();
UPackage* Z_Construct_UPackage__Script_ReusableDialogueSystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDialogueWidgetBase Function OnDialogueClosed ****************************
static FName NAME_UDialogueWidgetBase_OnDialogueClosed = FName(TEXT("OnDialogueClosed"));
void UDialogueWidgetBase::OnDialogueClosed()
{
	UFunction* Func = FindFunctionChecked(NAME_UDialogueWidgetBase_OnDialogueClosed);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UDialogueWidgetBase_OnDialogueClosed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue|UI" },
		{ "ModuleRelativePath", "Public/DialogueWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnDialogueClosed constinit property declarations **********************
// ********** End Function OnDialogueClosed constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueWidgetBase_OnDialogueClosed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueWidgetBase, nullptr, "OnDialogueClosed", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_OnDialogueClosed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueWidgetBase_OnDialogueClosed_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UDialogueWidgetBase_OnDialogueClosed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueWidgetBase_OnDialogueClosed_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UDialogueWidgetBase Function OnDialogueClosed ******************************

// ********** Begin Class UDialogueWidgetBase Function OnDialogueOpened ****************************
static FName NAME_UDialogueWidgetBase_OnDialogueOpened = FName(TEXT("OnDialogueOpened"));
void UDialogueWidgetBase::OnDialogueOpened()
{
	UFunction* Func = FindFunctionChecked(NAME_UDialogueWidgetBase_OnDialogueOpened);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UDialogueWidgetBase_OnDialogueOpened_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue|UI" },
		{ "ModuleRelativePath", "Public/DialogueWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnDialogueOpened constinit property declarations **********************
// ********** End Function OnDialogueOpened constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueWidgetBase_OnDialogueOpened_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueWidgetBase, nullptr, "OnDialogueOpened", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_OnDialogueOpened_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueWidgetBase_OnDialogueOpened_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UDialogueWidgetBase_OnDialogueOpened()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueWidgetBase_OnDialogueOpened_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UDialogueWidgetBase Function OnDialogueOpened ******************************

// ********** Begin Class UDialogueWidgetBase Function OnLineCompleted *****************************
struct DialogueWidgetBase_eventOnLineCompleted_Parms
{
	FName LineId;
	int32 LineIndex;
};
static FName NAME_UDialogueWidgetBase_OnLineCompleted = FName(TEXT("OnLineCompleted"));
void UDialogueWidgetBase::OnLineCompleted(FName LineId, int32 LineIndex)
{
	DialogueWidgetBase_eventOnLineCompleted_Parms Parms;
	Parms.LineId=LineId;
	Parms.LineIndex=LineIndex;
	UFunction* Func = FindFunctionChecked(NAME_UDialogueWidgetBase_OnLineCompleted);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UDialogueWidgetBase_OnLineCompleted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue|UI" },
		{ "ModuleRelativePath", "Public/DialogueWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnLineCompleted constinit property declarations ***********************
	static const UECodeGen_Private::FNamePropertyParams NewProp_LineId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LineIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnLineCompleted constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnLineCompleted Property Definitions **********************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDialogueWidgetBase_OnLineCompleted_Statics::NewProp_LineId = { "LineId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueWidgetBase_eventOnLineCompleted_Parms, LineId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDialogueWidgetBase_OnLineCompleted_Statics::NewProp_LineIndex = { "LineIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueWidgetBase_eventOnLineCompleted_Parms, LineIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueWidgetBase_OnLineCompleted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueWidgetBase_OnLineCompleted_Statics::NewProp_LineId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueWidgetBase_OnLineCompleted_Statics::NewProp_LineIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_OnLineCompleted_Statics::PropPointers) < 2048);
// ********** End Function OnLineCompleted Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueWidgetBase_OnLineCompleted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueWidgetBase, nullptr, "OnLineCompleted", 	Z_Construct_UFunction_UDialogueWidgetBase_OnLineCompleted_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_OnLineCompleted_Statics::PropPointers), 
sizeof(DialogueWidgetBase_eventOnLineCompleted_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_OnLineCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueWidgetBase_OnLineCompleted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(DialogueWidgetBase_eventOnLineCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueWidgetBase_OnLineCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueWidgetBase_OnLineCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UDialogueWidgetBase Function OnLineCompleted *******************************

// ********** Begin Class UDialogueWidgetBase Function OnLineStarted *******************************
struct DialogueWidgetBase_eventOnLineStarted_Parms
{
	FName LineId;
	int32 LineIndex;
};
static FName NAME_UDialogueWidgetBase_OnLineStarted = FName(TEXT("OnLineStarted"));
void UDialogueWidgetBase::OnLineStarted(FName LineId, int32 LineIndex)
{
	DialogueWidgetBase_eventOnLineStarted_Parms Parms;
	Parms.LineId=LineId;
	Parms.LineIndex=LineIndex;
	UFunction* Func = FindFunctionChecked(NAME_UDialogueWidgetBase_OnLineStarted);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UDialogueWidgetBase_OnLineStarted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue|UI" },
		{ "ModuleRelativePath", "Public/DialogueWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnLineStarted constinit property declarations *************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_LineId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LineIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnLineStarted constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnLineStarted Property Definitions ************************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDialogueWidgetBase_OnLineStarted_Statics::NewProp_LineId = { "LineId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueWidgetBase_eventOnLineStarted_Parms, LineId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDialogueWidgetBase_OnLineStarted_Statics::NewProp_LineIndex = { "LineIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueWidgetBase_eventOnLineStarted_Parms, LineIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueWidgetBase_OnLineStarted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueWidgetBase_OnLineStarted_Statics::NewProp_LineId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueWidgetBase_OnLineStarted_Statics::NewProp_LineIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_OnLineStarted_Statics::PropPointers) < 2048);
// ********** End Function OnLineStarted Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueWidgetBase_OnLineStarted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueWidgetBase, nullptr, "OnLineStarted", 	Z_Construct_UFunction_UDialogueWidgetBase_OnLineStarted_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_OnLineStarted_Statics::PropPointers), 
sizeof(DialogueWidgetBase_eventOnLineStarted_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_OnLineStarted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueWidgetBase_OnLineStarted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(DialogueWidgetBase_eventOnLineStarted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueWidgetBase_OnLineStarted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueWidgetBase_OnLineStarted_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UDialogueWidgetBase Function OnLineStarted *********************************

// ********** Begin Class UDialogueWidgetBase Function OnSpeakerChanged ****************************
static FName NAME_UDialogueWidgetBase_OnSpeakerChanged = FName(TEXT("OnSpeakerChanged"));
void UDialogueWidgetBase::OnSpeakerChanged()
{
	UFunction* Func = FindFunctionChecked(NAME_UDialogueWidgetBase_OnSpeakerChanged);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UDialogueWidgetBase_OnSpeakerChanged_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue|UI" },
		{ "ModuleRelativePath", "Public/DialogueWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnSpeakerChanged constinit property declarations **********************
// ********** End Function OnSpeakerChanged constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueWidgetBase_OnSpeakerChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueWidgetBase, nullptr, "OnSpeakerChanged", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_OnSpeakerChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueWidgetBase_OnSpeakerChanged_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UDialogueWidgetBase_OnSpeakerChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueWidgetBase_OnSpeakerChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UDialogueWidgetBase Function OnSpeakerChanged ******************************

// ********** Begin Class UDialogueWidgetBase Function ResetDialogueWidget *************************
struct Z_Construct_UFunction_UDialogueWidgetBase_ResetDialogueWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue|UI" },
		{ "ModuleRelativePath", "Public/DialogueWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResetDialogueWidget constinit property declarations *******************
// ********** End Function ResetDialogueWidget constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueWidgetBase_ResetDialogueWidget_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueWidgetBase, nullptr, "ResetDialogueWidget", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_ResetDialogueWidget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueWidgetBase_ResetDialogueWidget_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UDialogueWidgetBase_ResetDialogueWidget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueWidgetBase_ResetDialogueWidget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueWidgetBase::execResetDialogueWidget)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetDialogueWidget();
	P_NATIVE_END;
}
// ********** End Class UDialogueWidgetBase Function ResetDialogueWidget ***************************

// ********** Begin Class UDialogueWidgetBase Function SetAdvanceIndicatorVisible ******************
struct Z_Construct_UFunction_UDialogueWidgetBase_SetAdvanceIndicatorVisible_Statics
{
	struct DialogueWidgetBase_eventSetAdvanceIndicatorVisible_Parms
	{
		bool bVisible;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue|UI" },
		{ "ModuleRelativePath", "Public/DialogueWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetAdvanceIndicatorVisible constinit property declarations ************
	static void NewProp_bVisible_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bVisible;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetAdvanceIndicatorVisible constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetAdvanceIndicatorVisible Property Definitions ***********************
void Z_Construct_UFunction_UDialogueWidgetBase_SetAdvanceIndicatorVisible_Statics::NewProp_bVisible_SetBit(void* Obj)
{
	((DialogueWidgetBase_eventSetAdvanceIndicatorVisible_Parms*)Obj)->bVisible = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDialogueWidgetBase_SetAdvanceIndicatorVisible_Statics::NewProp_bVisible = { "bVisible", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DialogueWidgetBase_eventSetAdvanceIndicatorVisible_Parms), &Z_Construct_UFunction_UDialogueWidgetBase_SetAdvanceIndicatorVisible_Statics::NewProp_bVisible_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueWidgetBase_SetAdvanceIndicatorVisible_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueWidgetBase_SetAdvanceIndicatorVisible_Statics::NewProp_bVisible,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_SetAdvanceIndicatorVisible_Statics::PropPointers) < 2048);
// ********** End Function SetAdvanceIndicatorVisible Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueWidgetBase_SetAdvanceIndicatorVisible_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueWidgetBase, nullptr, "SetAdvanceIndicatorVisible", 	Z_Construct_UFunction_UDialogueWidgetBase_SetAdvanceIndicatorVisible_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_SetAdvanceIndicatorVisible_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDialogueWidgetBase_SetAdvanceIndicatorVisible_Statics::DialogueWidgetBase_eventSetAdvanceIndicatorVisible_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_SetAdvanceIndicatorVisible_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueWidgetBase_SetAdvanceIndicatorVisible_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueWidgetBase_SetAdvanceIndicatorVisible_Statics::DialogueWidgetBase_eventSetAdvanceIndicatorVisible_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueWidgetBase_SetAdvanceIndicatorVisible()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueWidgetBase_SetAdvanceIndicatorVisible_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueWidgetBase::execSetAdvanceIndicatorVisible)
{
	P_GET_UBOOL(Z_Param_bVisible);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetAdvanceIndicatorVisible(Z_Param_bVisible);
	P_NATIVE_END;
}
// ********** End Class UDialogueWidgetBase Function SetAdvanceIndicatorVisible ********************

// ********** Begin Class UDialogueWidgetBase Function SetDialogueText *****************************
struct Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueText_Statics
{
	struct DialogueWidgetBase_eventSetDialogueText_Parms
	{
		FText Text;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue|UI" },
		{ "ModuleRelativePath", "Public/DialogueWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetDialogueText constinit property declarations ***********************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetDialogueText constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetDialogueText Property Definitions **********************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueText_Statics::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueWidgetBase_eventSetDialogueText_Parms, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueText_Statics::NewProp_Text,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueText_Statics::PropPointers) < 2048);
// ********** End Function SetDialogueText Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueWidgetBase, nullptr, "SetDialogueText", 	Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueText_Statics::DialogueWidgetBase_eventSetDialogueText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueText_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueText_Statics::DialogueWidgetBase_eventSetDialogueText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueWidgetBase::execSetDialogueText)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Text);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDialogueText(Z_Param_Out_Text);
	P_NATIVE_END;
}
// ********** End Class UDialogueWidgetBase Function SetDialogueText *******************************

// ********** Begin Class UDialogueWidgetBase Function SetDialogueTextSmoothed *********************
struct Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueTextSmoothed_Statics
{
	struct DialogueWidgetBase_eventSetDialogueTextSmoothed_Parms
	{
		FText Text;
		float BlendDuration;
		float StartOpacity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue|UI" },
		{ "ModuleRelativePath", "Public/DialogueWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetDialogueTextSmoothed constinit property declarations ***************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BlendDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StartOpacity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetDialogueTextSmoothed constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetDialogueTextSmoothed Property Definitions **************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueTextSmoothed_Statics::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueWidgetBase_eventSetDialogueTextSmoothed_Parms, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueTextSmoothed_Statics::NewProp_BlendDuration = { "BlendDuration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueWidgetBase_eventSetDialogueTextSmoothed_Parms, BlendDuration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueTextSmoothed_Statics::NewProp_StartOpacity = { "StartOpacity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueWidgetBase_eventSetDialogueTextSmoothed_Parms, StartOpacity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueTextSmoothed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueTextSmoothed_Statics::NewProp_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueTextSmoothed_Statics::NewProp_BlendDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueTextSmoothed_Statics::NewProp_StartOpacity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueTextSmoothed_Statics::PropPointers) < 2048);
// ********** End Function SetDialogueTextSmoothed Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueTextSmoothed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueWidgetBase, nullptr, "SetDialogueTextSmoothed", 	Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueTextSmoothed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueTextSmoothed_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueTextSmoothed_Statics::DialogueWidgetBase_eventSetDialogueTextSmoothed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueTextSmoothed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueTextSmoothed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueTextSmoothed_Statics::DialogueWidgetBase_eventSetDialogueTextSmoothed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueTextSmoothed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueTextSmoothed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueWidgetBase::execSetDialogueTextSmoothed)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Text);
	P_GET_PROPERTY(FFloatProperty,Z_Param_BlendDuration);
	P_GET_PROPERTY(FFloatProperty,Z_Param_StartOpacity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDialogueTextSmoothed(Z_Param_Out_Text,Z_Param_BlendDuration,Z_Param_StartOpacity);
	P_NATIVE_END;
}
// ********** End Class UDialogueWidgetBase Function SetDialogueTextSmoothed ***********************

// ********** Begin Class UDialogueWidgetBase Function SetPortrait *********************************
struct Z_Construct_UFunction_UDialogueWidgetBase_SetPortrait_Statics
{
	struct DialogueWidgetBase_eventSetPortrait_Parms
	{
		UTexture2D* Portrait;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue|UI" },
		{ "ModuleRelativePath", "Public/DialogueWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetPortrait constinit property declarations ***************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Portrait;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPortrait constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPortrait Property Definitions **************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDialogueWidgetBase_SetPortrait_Statics::NewProp_Portrait = { "Portrait", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueWidgetBase_eventSetPortrait_Parms, Portrait), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueWidgetBase_SetPortrait_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueWidgetBase_SetPortrait_Statics::NewProp_Portrait,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_SetPortrait_Statics::PropPointers) < 2048);
// ********** End Function SetPortrait Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueWidgetBase_SetPortrait_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueWidgetBase, nullptr, "SetPortrait", 	Z_Construct_UFunction_UDialogueWidgetBase_SetPortrait_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_SetPortrait_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDialogueWidgetBase_SetPortrait_Statics::DialogueWidgetBase_eventSetPortrait_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_SetPortrait_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueWidgetBase_SetPortrait_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueWidgetBase_SetPortrait_Statics::DialogueWidgetBase_eventSetPortrait_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueWidgetBase_SetPortrait()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueWidgetBase_SetPortrait_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueWidgetBase::execSetPortrait)
{
	P_GET_OBJECT(UTexture2D,Z_Param_Portrait);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPortrait(Z_Param_Portrait);
	P_NATIVE_END;
}
// ********** End Class UDialogueWidgetBase Function SetPortrait ***********************************

// ********** Begin Class UDialogueWidgetBase Function SetSpeakerName ******************************
struct Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerName_Statics
{
	struct DialogueWidgetBase_eventSetSpeakerName_Parms
	{
		FText Name;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue|UI" },
		{ "ModuleRelativePath", "Public/DialogueWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetSpeakerName constinit property declarations ************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Name;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSpeakerName constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSpeakerName Property Definitions ***********************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerName_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueWidgetBase_eventSetSpeakerName_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerName_Statics::NewProp_Name,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerName_Statics::PropPointers) < 2048);
// ********** End Function SetSpeakerName Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueWidgetBase, nullptr, "SetSpeakerName", 	Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerName_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerName_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerName_Statics::DialogueWidgetBase_eventSetSpeakerName_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerName_Statics::DialogueWidgetBase_eventSetSpeakerName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueWidgetBase::execSetSpeakerName)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSpeakerName(Z_Param_Out_Name);
	P_NATIVE_END;
}
// ********** End Class UDialogueWidgetBase Function SetSpeakerName ********************************

// ********** Begin Class UDialogueWidgetBase Function SetSpeakerNameColor *************************
struct Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerNameColor_Statics
{
	struct DialogueWidgetBase_eventSetSpeakerNameColor_Parms
	{
		FLinearColor Color;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue|UI" },
		{ "ModuleRelativePath", "Public/DialogueWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetSpeakerNameColor constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSpeakerNameColor constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSpeakerNameColor Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerNameColor_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueWidgetBase_eventSetSpeakerNameColor_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerNameColor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerNameColor_Statics::NewProp_Color,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerNameColor_Statics::PropPointers) < 2048);
// ********** End Function SetSpeakerNameColor Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerNameColor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueWidgetBase, nullptr, "SetSpeakerNameColor", 	Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerNameColor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerNameColor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerNameColor_Statics::DialogueWidgetBase_eventSetSpeakerNameColor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerNameColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerNameColor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerNameColor_Statics::DialogueWidgetBase_eventSetSpeakerNameColor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerNameColor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerNameColor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueWidgetBase::execSetSpeakerNameColor)
{
	P_GET_STRUCT(FLinearColor,Z_Param_Color);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSpeakerNameColor(Z_Param_Color);
	P_NATIVE_END;
}
// ********** End Class UDialogueWidgetBase Function SetSpeakerNameColor ***************************

// ********** Begin Class UDialogueWidgetBase ******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueWidgetBase;
UClass* UDialogueWidgetBase::GetPrivateStaticClass()
{
	using TClass = UDialogueWidgetBase;
	if (!Z_Registration_Info_UClass_UDialogueWidgetBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DialogueWidgetBase"),
			Z_Registration_Info_UClass_UDialogueWidgetBase.InnerSingleton,
			StaticRegisterNativesUDialogueWidgetBase,
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
	return Z_Registration_Info_UClass_UDialogueWidgetBase.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueWidgetBase_NoRegister()
{
	return UDialogueWidgetBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueWidgetBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "DialogueWidgetBase.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/DialogueWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeakerNameText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Dialogue|UI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogueText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Dialogue|UI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeakerNamePanel_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "Dialogue|UI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeakerPortrait_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "Dialogue|UI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdvanceIndicator_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "Dialogue|UI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogueContainer_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "Dialogue|UI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDialogueWidgetBase constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpeakerNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DialogueText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpeakerNamePanel;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpeakerPortrait;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AdvanceIndicator;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DialogueContainer;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDialogueWidgetBase constinit property declarations ************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ResetDialogueWidget"), .Pointer = &UDialogueWidgetBase::execResetDialogueWidget },
		{ .NameUTF8 = UTF8TEXT("SetAdvanceIndicatorVisible"), .Pointer = &UDialogueWidgetBase::execSetAdvanceIndicatorVisible },
		{ .NameUTF8 = UTF8TEXT("SetDialogueText"), .Pointer = &UDialogueWidgetBase::execSetDialogueText },
		{ .NameUTF8 = UTF8TEXT("SetDialogueTextSmoothed"), .Pointer = &UDialogueWidgetBase::execSetDialogueTextSmoothed },
		{ .NameUTF8 = UTF8TEXT("SetPortrait"), .Pointer = &UDialogueWidgetBase::execSetPortrait },
		{ .NameUTF8 = UTF8TEXT("SetSpeakerName"), .Pointer = &UDialogueWidgetBase::execSetSpeakerName },
		{ .NameUTF8 = UTF8TEXT("SetSpeakerNameColor"), .Pointer = &UDialogueWidgetBase::execSetSpeakerNameColor },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDialogueWidgetBase_OnDialogueClosed, "OnDialogueClosed" }, // 2077760254
		{ &Z_Construct_UFunction_UDialogueWidgetBase_OnDialogueOpened, "OnDialogueOpened" }, // 1051045486
		{ &Z_Construct_UFunction_UDialogueWidgetBase_OnLineCompleted, "OnLineCompleted" }, // 3728198314
		{ &Z_Construct_UFunction_UDialogueWidgetBase_OnLineStarted, "OnLineStarted" }, // 1623629717
		{ &Z_Construct_UFunction_UDialogueWidgetBase_OnSpeakerChanged, "OnSpeakerChanged" }, // 283076586
		{ &Z_Construct_UFunction_UDialogueWidgetBase_ResetDialogueWidget, "ResetDialogueWidget" }, // 1682979988
		{ &Z_Construct_UFunction_UDialogueWidgetBase_SetAdvanceIndicatorVisible, "SetAdvanceIndicatorVisible" }, // 1389406852
		{ &Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueText, "SetDialogueText" }, // 1213893185
		{ &Z_Construct_UFunction_UDialogueWidgetBase_SetDialogueTextSmoothed, "SetDialogueTextSmoothed" }, // 855811358
		{ &Z_Construct_UFunction_UDialogueWidgetBase_SetPortrait, "SetPortrait" }, // 1199664776
		{ &Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerName, "SetSpeakerName" }, // 3108888751
		{ &Z_Construct_UFunction_UDialogueWidgetBase_SetSpeakerNameColor, "SetSpeakerNameColor" }, // 2467282989
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueWidgetBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDialogueWidgetBase_Statics

// ********** Begin Class UDialogueWidgetBase Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueWidgetBase_Statics::NewProp_SpeakerNameText = { "SpeakerNameText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueWidgetBase, SpeakerNameText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeakerNameText_MetaData), NewProp_SpeakerNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueWidgetBase_Statics::NewProp_DialogueText = { "DialogueText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueWidgetBase, DialogueText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogueText_MetaData), NewProp_DialogueText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueWidgetBase_Statics::NewProp_SpeakerNamePanel = { "SpeakerNamePanel", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueWidgetBase, SpeakerNamePanel), Z_Construct_UClass_UPanelWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeakerNamePanel_MetaData), NewProp_SpeakerNamePanel_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueWidgetBase_Statics::NewProp_SpeakerPortrait = { "SpeakerPortrait", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueWidgetBase, SpeakerPortrait), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeakerPortrait_MetaData), NewProp_SpeakerPortrait_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueWidgetBase_Statics::NewProp_AdvanceIndicator = { "AdvanceIndicator", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueWidgetBase, AdvanceIndicator), Z_Construct_UClass_UWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdvanceIndicator_MetaData), NewProp_AdvanceIndicator_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueWidgetBase_Statics::NewProp_DialogueContainer = { "DialogueContainer", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueWidgetBase, DialogueContainer), Z_Construct_UClass_UWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogueContainer_MetaData), NewProp_DialogueContainer_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueWidgetBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueWidgetBase_Statics::NewProp_SpeakerNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueWidgetBase_Statics::NewProp_DialogueText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueWidgetBase_Statics::NewProp_SpeakerNamePanel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueWidgetBase_Statics::NewProp_SpeakerPortrait,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueWidgetBase_Statics::NewProp_AdvanceIndicator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueWidgetBase_Statics::NewProp_DialogueContainer,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueWidgetBase_Statics::PropPointers) < 2048);
// ********** End Class UDialogueWidgetBase Property Definitions ***********************************
UObject* (*const Z_Construct_UClass_UDialogueWidgetBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_ReusableDialogueSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueWidgetBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueWidgetBase_Statics::ClassParams = {
	&UDialogueWidgetBase::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UDialogueWidgetBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueWidgetBase_Statics::PropPointers),
	0,
	0x00B010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueWidgetBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueWidgetBase_Statics::Class_MetaDataParams)
};
void UDialogueWidgetBase::StaticRegisterNativesUDialogueWidgetBase()
{
	UClass* Class = UDialogueWidgetBase::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UDialogueWidgetBase_Statics::Funcs));
}
UClass* Z_Construct_UClass_UDialogueWidgetBase()
{
	if (!Z_Registration_Info_UClass_UDialogueWidgetBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueWidgetBase.OuterSingleton, Z_Construct_UClass_UDialogueWidgetBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueWidgetBase.OuterSingleton;
}
UDialogueWidgetBase::UDialogueWidgetBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDialogueWidgetBase);
UDialogueWidgetBase::~UDialogueWidgetBase() {}
// ********** End Class UDialogueWidgetBase ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueWidgetBase_h__Script_ReusableDialogueSystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueWidgetBase, UDialogueWidgetBase::StaticClass, TEXT("UDialogueWidgetBase"), &Z_Registration_Info_UClass_UDialogueWidgetBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueWidgetBase), 367790314U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueWidgetBase_h__Script_ReusableDialogueSystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueWidgetBase_h__Script_ReusableDialogueSystem_3270743443{
	TEXT("/Script/ReusableDialogueSystem"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueWidgetBase_h__Script_ReusableDialogueSystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueWidgetBase_h__Script_ReusableDialogueSystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
