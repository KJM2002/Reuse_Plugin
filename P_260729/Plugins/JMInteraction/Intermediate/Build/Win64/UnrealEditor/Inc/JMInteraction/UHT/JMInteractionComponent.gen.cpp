// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/JMInteractionComponent.h"
#include "Types/JMInteractionTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMInteractionComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractionComponent();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractionComponent_NoRegister();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractionPromptWidgetBase_NoRegister();
JMINTERACTION_API UEnum* Z_Construct_UEnum_JMInteraction_EJMInteractionDetectionMode();
JMINTERACTION_API UEnum* Z_Construct_UEnum_JMInteraction_EJMInteractionState();
JMINTERACTION_API UEnum* Z_Construct_UEnum_JMInteraction_EJMInteractionTraceMode();
JMINTERACTION_API UFunction* Z_Construct_UDelegateFunction_JMInteraction_JMInteractableChangedSignature__DelegateSignature();
JMINTERACTION_API UFunction* Z_Construct_UDelegateFunction_JMInteraction_JMInteractionFinishedSignature__DelegateSignature();
JMINTERACTION_API UFunction* Z_Construct_UDelegateFunction_JMInteraction_JMInteractionPromptChangedSignature__DelegateSignature();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionPrompt();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionPromptStyle();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionResult();
UPackage* Z_Construct_UPackage__Script_JMInteraction();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FJMInteractableChangedSignature ***************************************
struct Z_Construct_UDelegateFunction_JMInteraction_JMInteractableChangedSignature__DelegateSignature_Statics
{
	struct _Script_JMInteraction_eventJMInteractableChangedSignature_Parms
	{
		UObject* OldInteractable;
		UObject* NewInteractable;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMInteractableChangedSignature constinit property declarations *******
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OldInteractable;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NewInteractable;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMInteractableChangedSignature constinit property declarations *********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMInteractableChangedSignature Property Definitions ******************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_JMInteraction_JMInteractableChangedSignature__DelegateSignature_Statics::NewProp_OldInteractable = { "OldInteractable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMInteraction_eventJMInteractableChangedSignature_Parms, OldInteractable), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_JMInteraction_JMInteractableChangedSignature__DelegateSignature_Statics::NewProp_NewInteractable = { "NewInteractable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMInteraction_eventJMInteractableChangedSignature_Parms, NewInteractable), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMInteraction_JMInteractableChangedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMInteraction_JMInteractableChangedSignature__DelegateSignature_Statics::NewProp_OldInteractable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMInteraction_JMInteractableChangedSignature__DelegateSignature_Statics::NewProp_NewInteractable,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMInteraction_JMInteractableChangedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMInteractableChangedSignature Property Definitions ********************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMInteraction_JMInteractableChangedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMInteraction, nullptr, "JMInteractableChangedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_JMInteraction_JMInteractableChangedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMInteraction_JMInteractableChangedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMInteraction_JMInteractableChangedSignature__DelegateSignature_Statics::_Script_JMInteraction_eventJMInteractableChangedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMInteraction_JMInteractableChangedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMInteraction_JMInteractableChangedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMInteraction_JMInteractableChangedSignature__DelegateSignature_Statics::_Script_JMInteraction_eventJMInteractableChangedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMInteraction_JMInteractableChangedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMInteraction_JMInteractableChangedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMInteractableChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMInteractableChangedSignature, UObject* OldInteractable, UObject* NewInteractable)
{
	struct _Script_JMInteraction_eventJMInteractableChangedSignature_Parms
	{
		UObject* OldInteractable;
		UObject* NewInteractable;
	};
	_Script_JMInteraction_eventJMInteractableChangedSignature_Parms Parms;
	Parms.OldInteractable=OldInteractable;
	Parms.NewInteractable=NewInteractable;
	JMInteractableChangedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMInteractableChangedSignature *****************************************

// ********** Begin Delegate FJMInteractionPromptChangedSignature **********************************
struct Z_Construct_UDelegateFunction_JMInteraction_JMInteractionPromptChangedSignature__DelegateSignature_Statics
{
	struct _Script_JMInteraction_eventJMInteractionPromptChangedSignature_Parms
	{
		FJMInteractionPrompt Prompt;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMInteractionPromptChangedSignature constinit property declarations **
	static const UECodeGen_Private::FStructPropertyParams NewProp_Prompt;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMInteractionPromptChangedSignature constinit property declarations ****
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMInteractionPromptChangedSignature Property Definitions *************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_JMInteraction_JMInteractionPromptChangedSignature__DelegateSignature_Statics::NewProp_Prompt = { "Prompt", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMInteraction_eventJMInteractionPromptChangedSignature_Parms, Prompt), Z_Construct_UScriptStruct_FJMInteractionPrompt, METADATA_PARAMS(0, nullptr) }; // 2592379790
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMInteraction_JMInteractionPromptChangedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMInteraction_JMInteractionPromptChangedSignature__DelegateSignature_Statics::NewProp_Prompt,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMInteraction_JMInteractionPromptChangedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMInteractionPromptChangedSignature Property Definitions ***************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMInteraction_JMInteractionPromptChangedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMInteraction, nullptr, "JMInteractionPromptChangedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_JMInteraction_JMInteractionPromptChangedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMInteraction_JMInteractionPromptChangedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMInteraction_JMInteractionPromptChangedSignature__DelegateSignature_Statics::_Script_JMInteraction_eventJMInteractionPromptChangedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMInteraction_JMInteractionPromptChangedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMInteraction_JMInteractionPromptChangedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMInteraction_JMInteractionPromptChangedSignature__DelegateSignature_Statics::_Script_JMInteraction_eventJMInteractionPromptChangedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMInteraction_JMInteractionPromptChangedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMInteraction_JMInteractionPromptChangedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMInteractionPromptChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMInteractionPromptChangedSignature, FJMInteractionPrompt Prompt)
{
	struct _Script_JMInteraction_eventJMInteractionPromptChangedSignature_Parms
	{
		FJMInteractionPrompt Prompt;
	};
	_Script_JMInteraction_eventJMInteractionPromptChangedSignature_Parms Parms;
	Parms.Prompt=Prompt;
	JMInteractionPromptChangedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMInteractionPromptChangedSignature ************************************

// ********** Begin Delegate FJMInteractionFinishedSignature ***************************************
struct Z_Construct_UDelegateFunction_JMInteraction_JMInteractionFinishedSignature__DelegateSignature_Statics
{
	struct _Script_JMInteraction_eventJMInteractionFinishedSignature_Parms
	{
		UObject* Interactable;
		FJMInteractionResult Result;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMInteractionFinishedSignature constinit property declarations *******
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Interactable;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Result;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMInteractionFinishedSignature constinit property declarations *********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMInteractionFinishedSignature Property Definitions ******************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_JMInteraction_JMInteractionFinishedSignature__DelegateSignature_Statics::NewProp_Interactable = { "Interactable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMInteraction_eventJMInteractionFinishedSignature_Parms, Interactable), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_JMInteraction_JMInteractionFinishedSignature__DelegateSignature_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMInteraction_eventJMInteractionFinishedSignature_Parms, Result), Z_Construct_UScriptStruct_FJMInteractionResult, METADATA_PARAMS(0, nullptr) }; // 240276497
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMInteraction_JMInteractionFinishedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMInteraction_JMInteractionFinishedSignature__DelegateSignature_Statics::NewProp_Interactable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMInteraction_JMInteractionFinishedSignature__DelegateSignature_Statics::NewProp_Result,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMInteraction_JMInteractionFinishedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMInteractionFinishedSignature Property Definitions ********************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMInteraction_JMInteractionFinishedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMInteraction, nullptr, "JMInteractionFinishedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_JMInteraction_JMInteractionFinishedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMInteraction_JMInteractionFinishedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMInteraction_JMInteractionFinishedSignature__DelegateSignature_Statics::_Script_JMInteraction_eventJMInteractionFinishedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMInteraction_JMInteractionFinishedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMInteraction_JMInteractionFinishedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMInteraction_JMInteractionFinishedSignature__DelegateSignature_Statics::_Script_JMInteraction_eventJMInteractionFinishedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMInteraction_JMInteractionFinishedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMInteraction_JMInteractionFinishedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMInteractionFinishedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMInteractionFinishedSignature, UObject* Interactable, FJMInteractionResult Result)
{
	struct _Script_JMInteraction_eventJMInteractionFinishedSignature_Parms
	{
		UObject* Interactable;
		FJMInteractionResult Result;
	};
	_Script_JMInteraction_eventJMInteractionFinishedSignature_Parms Parms;
	Parms.Interactable=Interactable;
	Parms.Result=Result;
	JMInteractionFinishedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMInteractionFinishedSignature *****************************************

// ********** Begin Class UJMInteractionComponent Function CancelInteraction ***********************
struct Z_Construct_UFunction_UJMInteractionComponent_CancelInteraction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CancelInteraction constinit property declarations *********************
// ********** End Function CancelInteraction constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractionComponent_CancelInteraction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractionComponent, nullptr, "CancelInteraction", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_CancelInteraction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractionComponent_CancelInteraction_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UJMInteractionComponent_CancelInteraction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractionComponent_CancelInteraction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInteractionComponent::execCancelInteraction)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CancelInteraction();
	P_NATIVE_END;
}
// ********** End Class UJMInteractionComponent Function CancelInteraction *************************

// ********** Begin Class UJMInteractionComponent Function CompleteInteraction *********************
struct Z_Construct_UFunction_UJMInteractionComponent_CompleteInteraction_Statics
{
	struct JMInteractionComponent_eventCompleteInteraction_Parms
	{
		FJMInteractionResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CompleteInteraction constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CompleteInteraction constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CompleteInteraction Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractionComponent_CompleteInteraction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractionComponent_eventCompleteInteraction_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMInteractionResult, METADATA_PARAMS(0, nullptr) }; // 240276497
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractionComponent_CompleteInteraction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionComponent_CompleteInteraction_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_CompleteInteraction_Statics::PropPointers) < 2048);
// ********** End Function CompleteInteraction Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractionComponent_CompleteInteraction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractionComponent, nullptr, "CompleteInteraction", 	Z_Construct_UFunction_UJMInteractionComponent_CompleteInteraction_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_CompleteInteraction_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMInteractionComponent_CompleteInteraction_Statics::JMInteractionComponent_eventCompleteInteraction_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_CompleteInteraction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractionComponent_CompleteInteraction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMInteractionComponent_CompleteInteraction_Statics::JMInteractionComponent_eventCompleteInteraction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractionComponent_CompleteInteraction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractionComponent_CompleteInteraction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInteractionComponent::execCompleteInteraction)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMInteractionResult*)Z_Param__Result=P_THIS->CompleteInteraction();
	P_NATIVE_END;
}
// ********** End Class UJMInteractionComponent Function CompleteInteraction ***********************

// ********** Begin Class UJMInteractionComponent Function GetCurrentInteractableActor *************
struct Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableActor_Statics
{
	struct JMInteractionComponent_eventGetCurrentInteractableActor_Parms
	{
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentInteractableActor constinit property declarations ***********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentInteractableActor constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentInteractableActor Property Definitions **********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractionComponent_eventGetCurrentInteractableActor_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableActor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableActor_Statics::PropPointers) < 2048);
// ********** End Function GetCurrentInteractableActor Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableActor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractionComponent, nullptr, "GetCurrentInteractableActor", 	Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableActor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableActor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableActor_Statics::JMInteractionComponent_eventGetCurrentInteractableActor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableActor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableActor_Statics::JMInteractionComponent_eventGetCurrentInteractableActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInteractionComponent::execGetCurrentInteractableActor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->GetCurrentInteractableActor();
	P_NATIVE_END;
}
// ********** End Class UJMInteractionComponent Function GetCurrentInteractableActor ***************

// ********** Begin Class UJMInteractionComponent Function GetCurrentInteractableObject ************
struct Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableObject_Statics
{
	struct JMInteractionComponent_eventGetCurrentInteractableObject_Parms
	{
		UObject* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentInteractableObject constinit property declarations **********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentInteractableObject constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentInteractableObject Property Definitions *********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableObject_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractionComponent_eventGetCurrentInteractableObject_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableObject_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableObject_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableObject_Statics::PropPointers) < 2048);
// ********** End Function GetCurrentInteractableObject Property Definitions ***********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableObject_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractionComponent, nullptr, "GetCurrentInteractableObject", 	Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableObject_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableObject_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableObject_Statics::JMInteractionComponent_eventGetCurrentInteractableObject_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableObject_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableObject_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableObject_Statics::JMInteractionComponent_eventGetCurrentInteractableObject_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableObject()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableObject_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInteractionComponent::execGetCurrentInteractableObject)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UObject**)Z_Param__Result=P_THIS->GetCurrentInteractableObject();
	P_NATIVE_END;
}
// ********** End Class UJMInteractionComponent Function GetCurrentInteractableObject **************

// ********** Begin Class UJMInteractionComponent Function GetCurrentPrompt ************************
struct Z_Construct_UFunction_UJMInteractionComponent_GetCurrentPrompt_Statics
{
	struct JMInteractionComponent_eventGetCurrentPrompt_Parms
	{
		FJMInteractionPrompt ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentPrompt constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentPrompt constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentPrompt Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractionComponent_GetCurrentPrompt_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractionComponent_eventGetCurrentPrompt_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMInteractionPrompt, METADATA_PARAMS(0, nullptr) }; // 2592379790
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractionComponent_GetCurrentPrompt_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionComponent_GetCurrentPrompt_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_GetCurrentPrompt_Statics::PropPointers) < 2048);
// ********** End Function GetCurrentPrompt Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractionComponent_GetCurrentPrompt_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractionComponent, nullptr, "GetCurrentPrompt", 	Z_Construct_UFunction_UJMInteractionComponent_GetCurrentPrompt_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_GetCurrentPrompt_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMInteractionComponent_GetCurrentPrompt_Statics::JMInteractionComponent_eventGetCurrentPrompt_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_GetCurrentPrompt_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractionComponent_GetCurrentPrompt_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMInteractionComponent_GetCurrentPrompt_Statics::JMInteractionComponent_eventGetCurrentPrompt_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractionComponent_GetCurrentPrompt()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractionComponent_GetCurrentPrompt_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInteractionComponent::execGetCurrentPrompt)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMInteractionPrompt*)Z_Param__Result=P_THIS->GetCurrentPrompt();
	P_NATIVE_END;
}
// ********** End Class UJMInteractionComponent Function GetCurrentPrompt **************************

// ********** Begin Class UJMInteractionComponent Function GetInteractionState *********************
struct Z_Construct_UFunction_UJMInteractionComponent_GetInteractionState_Statics
{
	struct JMInteractionComponent_eventGetInteractionState_Parms
	{
		EJMInteractionState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetInteractionState constinit property declarations *******************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetInteractionState constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetInteractionState Property Definitions ******************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMInteractionComponent_GetInteractionState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMInteractionComponent_GetInteractionState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractionComponent_eventGetInteractionState_Parms, ReturnValue), Z_Construct_UEnum_JMInteraction_EJMInteractionState, METADATA_PARAMS(0, nullptr) }; // 2284070030
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractionComponent_GetInteractionState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionComponent_GetInteractionState_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionComponent_GetInteractionState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_GetInteractionState_Statics::PropPointers) < 2048);
// ********** End Function GetInteractionState Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractionComponent_GetInteractionState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractionComponent, nullptr, "GetInteractionState", 	Z_Construct_UFunction_UJMInteractionComponent_GetInteractionState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_GetInteractionState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMInteractionComponent_GetInteractionState_Statics::JMInteractionComponent_eventGetInteractionState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_GetInteractionState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractionComponent_GetInteractionState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMInteractionComponent_GetInteractionState_Statics::JMInteractionComponent_eventGetInteractionState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractionComponent_GetInteractionState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractionComponent_GetInteractionState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInteractionComponent::execGetInteractionState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EJMInteractionState*)Z_Param__Result=P_THIS->GetInteractionState();
	P_NATIVE_END;
}
// ********** End Class UJMInteractionComponent Function GetInteractionState ***********************

// ********** Begin Class UJMInteractionComponent Function IsPromptSuppressed **********************
struct Z_Construct_UFunction_UJMInteractionComponent_IsPromptSuppressed_Statics
{
	struct JMInteractionComponent_eventIsPromptSuppressed_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction|UI" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsPromptSuppressed constinit property declarations ********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsPromptSuppressed constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsPromptSuppressed Property Definitions *******************************
void Z_Construct_UFunction_UJMInteractionComponent_IsPromptSuppressed_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMInteractionComponent_eventIsPromptSuppressed_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMInteractionComponent_IsPromptSuppressed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMInteractionComponent_eventIsPromptSuppressed_Parms), &Z_Construct_UFunction_UJMInteractionComponent_IsPromptSuppressed_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractionComponent_IsPromptSuppressed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionComponent_IsPromptSuppressed_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_IsPromptSuppressed_Statics::PropPointers) < 2048);
// ********** End Function IsPromptSuppressed Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractionComponent_IsPromptSuppressed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractionComponent, nullptr, "IsPromptSuppressed", 	Z_Construct_UFunction_UJMInteractionComponent_IsPromptSuppressed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_IsPromptSuppressed_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMInteractionComponent_IsPromptSuppressed_Statics::JMInteractionComponent_eventIsPromptSuppressed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_IsPromptSuppressed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractionComponent_IsPromptSuppressed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMInteractionComponent_IsPromptSuppressed_Statics::JMInteractionComponent_eventIsPromptSuppressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractionComponent_IsPromptSuppressed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractionComponent_IsPromptSuppressed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInteractionComponent::execIsPromptSuppressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsPromptSuppressed();
	P_NATIVE_END;
}
// ********** End Class UJMInteractionComponent Function IsPromptSuppressed ************************

// ********** Begin Class UJMInteractionComponent Function RefreshCurrentInteractable **************
struct Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractable_Statics
{
	struct JMInteractionComponent_eventRefreshCurrentInteractable_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshCurrentInteractable constinit property declarations ************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RefreshCurrentInteractable constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RefreshCurrentInteractable Property Definitions ***********************
void Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractable_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMInteractionComponent_eventRefreshCurrentInteractable_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractable_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMInteractionComponent_eventRefreshCurrentInteractable_Parms), &Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractable_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractable_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractable_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractable_Statics::PropPointers) < 2048);
// ********** End Function RefreshCurrentInteractable Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractable_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractionComponent, nullptr, "RefreshCurrentInteractable", 	Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractable_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractable_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractable_Statics::JMInteractionComponent_eventRefreshCurrentInteractable_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractable_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractable_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractable_Statics::JMInteractionComponent_eventRefreshCurrentInteractable_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractable()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractable_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInteractionComponent::execRefreshCurrentInteractable)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->RefreshCurrentInteractable();
	P_NATIVE_END;
}
// ********** End Class UJMInteractionComponent Function RefreshCurrentInteractable ****************

// ********** Begin Class UJMInteractionComponent Function RefreshCurrentInteractableFromTrace *****
struct Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractableFromTrace_Statics
{
	struct JMInteractionComponent_eventRefreshCurrentInteractableFromTrace_Parms
	{
		FVector TraceStart;
		FVector TraceDirection;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshCurrentInteractableFromTrace constinit property declarations ***
	static const UECodeGen_Private::FStructPropertyParams NewProp_TraceStart;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TraceDirection;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RefreshCurrentInteractableFromTrace constinit property declarations *****
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RefreshCurrentInteractableFromTrace Property Definitions **************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractableFromTrace_Statics::NewProp_TraceStart = { "TraceStart", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractionComponent_eventRefreshCurrentInteractableFromTrace_Parms, TraceStart), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractableFromTrace_Statics::NewProp_TraceDirection = { "TraceDirection", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractionComponent_eventRefreshCurrentInteractableFromTrace_Parms, TraceDirection), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractableFromTrace_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMInteractionComponent_eventRefreshCurrentInteractableFromTrace_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractableFromTrace_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMInteractionComponent_eventRefreshCurrentInteractableFromTrace_Parms), &Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractableFromTrace_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractableFromTrace_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractableFromTrace_Statics::NewProp_TraceStart,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractableFromTrace_Statics::NewProp_TraceDirection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractableFromTrace_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractableFromTrace_Statics::PropPointers) < 2048);
// ********** End Function RefreshCurrentInteractableFromTrace Property Definitions ****************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractableFromTrace_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractionComponent, nullptr, "RefreshCurrentInteractableFromTrace", 	Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractableFromTrace_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractableFromTrace_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractableFromTrace_Statics::JMInteractionComponent_eventRefreshCurrentInteractableFromTrace_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractableFromTrace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractableFromTrace_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractableFromTrace_Statics::JMInteractionComponent_eventRefreshCurrentInteractableFromTrace_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractableFromTrace()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractableFromTrace_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInteractionComponent::execRefreshCurrentInteractableFromTrace)
{
	P_GET_STRUCT(FVector,Z_Param_TraceStart);
	P_GET_STRUCT(FVector,Z_Param_TraceDirection);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->RefreshCurrentInteractableFromTrace(Z_Param_TraceStart,Z_Param_TraceDirection);
	P_NATIVE_END;
}
// ********** End Class UJMInteractionComponent Function RefreshCurrentInteractableFromTrace *******

// ********** Begin Class UJMInteractionComponent Function SetInteractionEnabled *******************
struct Z_Construct_UFunction_UJMInteractionComponent_SetInteractionEnabled_Statics
{
	struct JMInteractionComponent_eventSetInteractionEnabled_Parms
	{
		bool bNewEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetInteractionEnabled constinit property declarations *****************
	static void NewProp_bNewEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNewEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetInteractionEnabled constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetInteractionEnabled Property Definitions ****************************
void Z_Construct_UFunction_UJMInteractionComponent_SetInteractionEnabled_Statics::NewProp_bNewEnabled_SetBit(void* Obj)
{
	((JMInteractionComponent_eventSetInteractionEnabled_Parms*)Obj)->bNewEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMInteractionComponent_SetInteractionEnabled_Statics::NewProp_bNewEnabled = { "bNewEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMInteractionComponent_eventSetInteractionEnabled_Parms), &Z_Construct_UFunction_UJMInteractionComponent_SetInteractionEnabled_Statics::NewProp_bNewEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractionComponent_SetInteractionEnabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionComponent_SetInteractionEnabled_Statics::NewProp_bNewEnabled,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_SetInteractionEnabled_Statics::PropPointers) < 2048);
// ********** End Function SetInteractionEnabled Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractionComponent_SetInteractionEnabled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractionComponent, nullptr, "SetInteractionEnabled", 	Z_Construct_UFunction_UJMInteractionComponent_SetInteractionEnabled_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_SetInteractionEnabled_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMInteractionComponent_SetInteractionEnabled_Statics::JMInteractionComponent_eventSetInteractionEnabled_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_SetInteractionEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractionComponent_SetInteractionEnabled_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMInteractionComponent_SetInteractionEnabled_Statics::JMInteractionComponent_eventSetInteractionEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractionComponent_SetInteractionEnabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractionComponent_SetInteractionEnabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInteractionComponent::execSetInteractionEnabled)
{
	P_GET_UBOOL(Z_Param_bNewEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetInteractionEnabled(Z_Param_bNewEnabled);
	P_NATIVE_END;
}
// ********** End Class UJMInteractionComponent Function SetInteractionEnabled *********************

// ********** Begin Class UJMInteractionComponent Function SetPromptSuppressed *********************
struct Z_Construct_UFunction_UJMInteractionComponent_SetPromptSuppressed_Statics
{
	struct JMInteractionComponent_eventSetPromptSuppressed_Parms
	{
		bool bNewSuppressed;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Temporarily hides only the prompt. Modal UI should restore its previous value on close. */" },
#endif
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Temporarily hides only the prompt. Modal UI should restore its previous value on close." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetPromptSuppressed constinit property declarations *******************
	static void NewProp_bNewSuppressed_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNewSuppressed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPromptSuppressed constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPromptSuppressed Property Definitions ******************************
void Z_Construct_UFunction_UJMInteractionComponent_SetPromptSuppressed_Statics::NewProp_bNewSuppressed_SetBit(void* Obj)
{
	((JMInteractionComponent_eventSetPromptSuppressed_Parms*)Obj)->bNewSuppressed = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMInteractionComponent_SetPromptSuppressed_Statics::NewProp_bNewSuppressed = { "bNewSuppressed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMInteractionComponent_eventSetPromptSuppressed_Parms), &Z_Construct_UFunction_UJMInteractionComponent_SetPromptSuppressed_Statics::NewProp_bNewSuppressed_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractionComponent_SetPromptSuppressed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionComponent_SetPromptSuppressed_Statics::NewProp_bNewSuppressed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_SetPromptSuppressed_Statics::PropPointers) < 2048);
// ********** End Function SetPromptSuppressed Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractionComponent_SetPromptSuppressed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractionComponent, nullptr, "SetPromptSuppressed", 	Z_Construct_UFunction_UJMInteractionComponent_SetPromptSuppressed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_SetPromptSuppressed_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMInteractionComponent_SetPromptSuppressed_Statics::JMInteractionComponent_eventSetPromptSuppressed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_SetPromptSuppressed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractionComponent_SetPromptSuppressed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMInteractionComponent_SetPromptSuppressed_Statics::JMInteractionComponent_eventSetPromptSuppressed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractionComponent_SetPromptSuppressed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractionComponent_SetPromptSuppressed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInteractionComponent::execSetPromptSuppressed)
{
	P_GET_UBOOL(Z_Param_bNewSuppressed);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPromptSuppressed(Z_Param_bNewSuppressed);
	P_NATIVE_END;
}
// ********** End Class UJMInteractionComponent Function SetPromptSuppressed ***********************

// ********** Begin Class UJMInteractionComponent Function TryBeginInteraction *********************
struct Z_Construct_UFunction_UJMInteractionComponent_TryBeginInteraction_Statics
{
	struct JMInteractionComponent_eventTryBeginInteraction_Parms
	{
		FJMInteractionResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function TryBeginInteraction constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TryBeginInteraction constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TryBeginInteraction Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractionComponent_TryBeginInteraction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractionComponent_eventTryBeginInteraction_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMInteractionResult, METADATA_PARAMS(0, nullptr) }; // 240276497
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractionComponent_TryBeginInteraction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionComponent_TryBeginInteraction_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_TryBeginInteraction_Statics::PropPointers) < 2048);
// ********** End Function TryBeginInteraction Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractionComponent_TryBeginInteraction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractionComponent, nullptr, "TryBeginInteraction", 	Z_Construct_UFunction_UJMInteractionComponent_TryBeginInteraction_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_TryBeginInteraction_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMInteractionComponent_TryBeginInteraction_Statics::JMInteractionComponent_eventTryBeginInteraction_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_TryBeginInteraction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractionComponent_TryBeginInteraction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMInteractionComponent_TryBeginInteraction_Statics::JMInteractionComponent_eventTryBeginInteraction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractionComponent_TryBeginInteraction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractionComponent_TryBeginInteraction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInteractionComponent::execTryBeginInteraction)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMInteractionResult*)Z_Param__Result=P_THIS->TryBeginInteraction();
	P_NATIVE_END;
}
// ********** End Class UJMInteractionComponent Function TryBeginInteraction ***********************

// ********** Begin Class UJMInteractionComponent Function TryInteract *****************************
struct Z_Construct_UFunction_UJMInteractionComponent_TryInteract_Statics
{
	struct JMInteractionComponent_eventTryInteract_Parms
	{
		FJMInteractionResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function TryInteract constinit property declarations ***************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TryInteract constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TryInteract Property Definitions **************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractionComponent_TryInteract_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractionComponent_eventTryInteract_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMInteractionResult, METADATA_PARAMS(0, nullptr) }; // 240276497
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractionComponent_TryInteract_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractionComponent_TryInteract_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_TryInteract_Statics::PropPointers) < 2048);
// ********** End Function TryInteract Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractionComponent_TryInteract_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractionComponent, nullptr, "TryInteract", 	Z_Construct_UFunction_UJMInteractionComponent_TryInteract_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_TryInteract_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMInteractionComponent_TryInteract_Statics::JMInteractionComponent_eventTryInteract_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractionComponent_TryInteract_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractionComponent_TryInteract_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMInteractionComponent_TryInteract_Statics::JMInteractionComponent_eventTryInteract_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractionComponent_TryInteract()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractionComponent_TryInteract_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInteractionComponent::execTryInteract)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMInteractionResult*)Z_Param__Result=P_THIS->TryInteract();
	P_NATIVE_END;
}
// ********** End Class UJMInteractionComponent Function TryInteract *******************************

// ********** Begin Class UJMInteractionComponent **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMInteractionComponent;
UClass* UJMInteractionComponent::GetPrivateStaticClass()
{
	using TClass = UJMInteractionComponent;
	if (!Z_Registration_Info_UClass_UJMInteractionComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMInteractionComponent"),
			Z_Registration_Info_UClass_UJMInteractionComponent.InnerSingleton,
			StaticRegisterNativesUJMInteractionComponent,
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
	return Z_Registration_Info_UClass_UJMInteractionComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMInteractionComponent_NoRegister()
{
	return UJMInteractionComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMInteractionComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "JMInteraction" },
		{ "IncludePath", "Components/JMInteractionComponent.h" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCurrentInteractableChanged_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnPromptChanged_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnInteractionFinished_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bInteractionEnabled_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideProjectSettings_MetaData[] = {
		{ "Category", "JM Interaction|Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If false, detection values are initialized from Project Settings at BeginPlay. */" },
#endif
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If false, detection values are initialized from Project Settings at BeginPlay." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TraceDistance_MetaData[] = {
		{ "Category", "JM Interaction|Detection" },
		{ "ClampMin", "1.0" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TraceRadius_MetaData[] = {
		{ "Category", "JM Interaction|Detection" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TraceChannel_MetaData[] = {
		{ "Category", "JM Interaction|Detection" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DetectionMode_MetaData[] = {
		{ "Category", "JM Interaction|Detection" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TraceMode_MetaData[] = {
		{ "Category", "JM Interaction|Detection" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TraceInterval_MetaData[] = {
		{ "Category", "JM Interaction|Detection" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDrawDebug_MetaData[] = {
		{ "Category", "JM Interaction|Debug" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCreatePromptWidget_MetaData[] = {
		{ "Category", "JM Interaction|UI" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionPromptWidgetClass_MetaData[] = {
		{ "Category", "JM Interaction|UI" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverridePromptStyle_MetaData[] = {
		{ "Category", "JM Interaction|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Uses the complete style below instead of Project Settings > Plugins > JM Interaction > Prompt UI. */" },
#endif
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Uses the complete style below instead of Project Settings > Plugins > JM Interaction > Prompt UI." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PromptStyle_MetaData[] = {
		{ "Category", "JM Interaction|UI" },
		{ "EditCondition", "bOverridePromptStyle" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentInteractableObject_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentInteractableActor_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveInteractableObject_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveInteractableActor_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PromptWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionState_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastDisplayedPrompt_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasDisplayedPrompt_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPromptSuppressed_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/JMInteractionComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMInteractionComponent constinit property declarations ******************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCurrentInteractableChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPromptChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInteractionFinished;
	static void NewProp_bInteractionEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInteractionEnabled;
	static void NewProp_bOverrideProjectSettings_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideProjectSettings;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TraceDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TraceRadius;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TraceChannel;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DetectionMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DetectionMode;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TraceMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TraceMode;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TraceInterval;
	static void NewProp_bDrawDebug_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawDebug;
	static void NewProp_bCreatePromptWidget_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreatePromptWidget;
	static const UECodeGen_Private::FClassPropertyParams NewProp_InteractionPromptWidgetClass;
	static void NewProp_bOverridePromptStyle_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverridePromptStyle;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PromptStyle;
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_CurrentInteractableObject;
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_CurrentInteractableActor;
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_ActiveInteractableObject;
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_ActiveInteractableActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PromptWidget;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InteractionState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InteractionState;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LastDisplayedPrompt;
	static void NewProp_bHasDisplayedPrompt_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasDisplayedPrompt;
	static void NewProp_bPromptSuppressed_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPromptSuppressed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMInteractionComponent constinit property declarations ********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CancelInteraction"), .Pointer = &UJMInteractionComponent::execCancelInteraction },
		{ .NameUTF8 = UTF8TEXT("CompleteInteraction"), .Pointer = &UJMInteractionComponent::execCompleteInteraction },
		{ .NameUTF8 = UTF8TEXT("GetCurrentInteractableActor"), .Pointer = &UJMInteractionComponent::execGetCurrentInteractableActor },
		{ .NameUTF8 = UTF8TEXT("GetCurrentInteractableObject"), .Pointer = &UJMInteractionComponent::execGetCurrentInteractableObject },
		{ .NameUTF8 = UTF8TEXT("GetCurrentPrompt"), .Pointer = &UJMInteractionComponent::execGetCurrentPrompt },
		{ .NameUTF8 = UTF8TEXT("GetInteractionState"), .Pointer = &UJMInteractionComponent::execGetInteractionState },
		{ .NameUTF8 = UTF8TEXT("IsPromptSuppressed"), .Pointer = &UJMInteractionComponent::execIsPromptSuppressed },
		{ .NameUTF8 = UTF8TEXT("RefreshCurrentInteractable"), .Pointer = &UJMInteractionComponent::execRefreshCurrentInteractable },
		{ .NameUTF8 = UTF8TEXT("RefreshCurrentInteractableFromTrace"), .Pointer = &UJMInteractionComponent::execRefreshCurrentInteractableFromTrace },
		{ .NameUTF8 = UTF8TEXT("SetInteractionEnabled"), .Pointer = &UJMInteractionComponent::execSetInteractionEnabled },
		{ .NameUTF8 = UTF8TEXT("SetPromptSuppressed"), .Pointer = &UJMInteractionComponent::execSetPromptSuppressed },
		{ .NameUTF8 = UTF8TEXT("TryBeginInteraction"), .Pointer = &UJMInteractionComponent::execTryBeginInteraction },
		{ .NameUTF8 = UTF8TEXT("TryInteract"), .Pointer = &UJMInteractionComponent::execTryInteract },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMInteractionComponent_CancelInteraction, "CancelInteraction" }, // 3865274751
		{ &Z_Construct_UFunction_UJMInteractionComponent_CompleteInteraction, "CompleteInteraction" }, // 3631199064
		{ &Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableActor, "GetCurrentInteractableActor" }, // 3659890078
		{ &Z_Construct_UFunction_UJMInteractionComponent_GetCurrentInteractableObject, "GetCurrentInteractableObject" }, // 1871623096
		{ &Z_Construct_UFunction_UJMInteractionComponent_GetCurrentPrompt, "GetCurrentPrompt" }, // 3030548579
		{ &Z_Construct_UFunction_UJMInteractionComponent_GetInteractionState, "GetInteractionState" }, // 1735860874
		{ &Z_Construct_UFunction_UJMInteractionComponent_IsPromptSuppressed, "IsPromptSuppressed" }, // 3743231529
		{ &Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractable, "RefreshCurrentInteractable" }, // 1172548852
		{ &Z_Construct_UFunction_UJMInteractionComponent_RefreshCurrentInteractableFromTrace, "RefreshCurrentInteractableFromTrace" }, // 902791498
		{ &Z_Construct_UFunction_UJMInteractionComponent_SetInteractionEnabled, "SetInteractionEnabled" }, // 3438670152
		{ &Z_Construct_UFunction_UJMInteractionComponent_SetPromptSuppressed, "SetPromptSuppressed" }, // 1133611736
		{ &Z_Construct_UFunction_UJMInteractionComponent_TryBeginInteraction, "TryBeginInteraction" }, // 2478983164
		{ &Z_Construct_UFunction_UJMInteractionComponent_TryInteract, "TryInteract" }, // 4280715435
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMInteractionComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMInteractionComponent_Statics

// ********** Begin Class UJMInteractionComponent Property Definitions *****************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_OnCurrentInteractableChanged = { "OnCurrentInteractableChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionComponent, OnCurrentInteractableChanged), Z_Construct_UDelegateFunction_JMInteraction_JMInteractableChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCurrentInteractableChanged_MetaData), NewProp_OnCurrentInteractableChanged_MetaData) }; // 4073171887
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_OnPromptChanged = { "OnPromptChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionComponent, OnPromptChanged), Z_Construct_UDelegateFunction_JMInteraction_JMInteractionPromptChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnPromptChanged_MetaData), NewProp_OnPromptChanged_MetaData) }; // 4214510088
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_OnInteractionFinished = { "OnInteractionFinished", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionComponent, OnInteractionFinished), Z_Construct_UDelegateFunction_JMInteraction_JMInteractionFinishedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnInteractionFinished_MetaData), NewProp_OnInteractionFinished_MetaData) }; // 2011728862
void Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bInteractionEnabled_SetBit(void* Obj)
{
	((UJMInteractionComponent*)Obj)->bInteractionEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bInteractionEnabled = { "bInteractionEnabled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMInteractionComponent), &Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bInteractionEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bInteractionEnabled_MetaData), NewProp_bInteractionEnabled_MetaData) };
void Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bOverrideProjectSettings_SetBit(void* Obj)
{
	((UJMInteractionComponent*)Obj)->bOverrideProjectSettings = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bOverrideProjectSettings = { "bOverrideProjectSettings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMInteractionComponent), &Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bOverrideProjectSettings_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideProjectSettings_MetaData), NewProp_bOverrideProjectSettings_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_TraceDistance = { "TraceDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionComponent, TraceDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TraceDistance_MetaData), NewProp_TraceDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_TraceRadius = { "TraceRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionComponent, TraceRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TraceRadius_MetaData), NewProp_TraceRadius_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_TraceChannel = { "TraceChannel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionComponent, TraceChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TraceChannel_MetaData), NewProp_TraceChannel_MetaData) }; // 838391399
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_DetectionMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_DetectionMode = { "DetectionMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionComponent, DetectionMode), Z_Construct_UEnum_JMInteraction_EJMInteractionDetectionMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DetectionMode_MetaData), NewProp_DetectionMode_MetaData) }; // 1585170584
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_TraceMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_TraceMode = { "TraceMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionComponent, TraceMode), Z_Construct_UEnum_JMInteraction_EJMInteractionTraceMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TraceMode_MetaData), NewProp_TraceMode_MetaData) }; // 2566927994
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_TraceInterval = { "TraceInterval", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionComponent, TraceInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TraceInterval_MetaData), NewProp_TraceInterval_MetaData) };
void Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bDrawDebug_SetBit(void* Obj)
{
	((UJMInteractionComponent*)Obj)->bDrawDebug = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bDrawDebug = { "bDrawDebug", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMInteractionComponent), &Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bDrawDebug_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDrawDebug_MetaData), NewProp_bDrawDebug_MetaData) };
void Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bCreatePromptWidget_SetBit(void* Obj)
{
	((UJMInteractionComponent*)Obj)->bCreatePromptWidget = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bCreatePromptWidget = { "bCreatePromptWidget", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMInteractionComponent), &Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bCreatePromptWidget_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCreatePromptWidget_MetaData), NewProp_bCreatePromptWidget_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_InteractionPromptWidgetClass = { "InteractionPromptWidgetClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionComponent, InteractionPromptWidgetClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UJMInteractionPromptWidgetBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionPromptWidgetClass_MetaData), NewProp_InteractionPromptWidgetClass_MetaData) };
void Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bOverridePromptStyle_SetBit(void* Obj)
{
	((UJMInteractionComponent*)Obj)->bOverridePromptStyle = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bOverridePromptStyle = { "bOverridePromptStyle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMInteractionComponent), &Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bOverridePromptStyle_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverridePromptStyle_MetaData), NewProp_bOverridePromptStyle_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_PromptStyle = { "PromptStyle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionComponent, PromptStyle), Z_Construct_UScriptStruct_FJMInteractionPromptStyle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PromptStyle_MetaData), NewProp_PromptStyle_MetaData) }; // 2420317743
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_CurrentInteractableObject = { "CurrentInteractableObject", nullptr, (EPropertyFlags)0x0024080000002000, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionComponent, CurrentInteractableObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentInteractableObject_MetaData), NewProp_CurrentInteractableObject_MetaData) };
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_CurrentInteractableActor = { "CurrentInteractableActor", nullptr, (EPropertyFlags)0x0024080000002000, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionComponent, CurrentInteractableActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentInteractableActor_MetaData), NewProp_CurrentInteractableActor_MetaData) };
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_ActiveInteractableObject = { "ActiveInteractableObject", nullptr, (EPropertyFlags)0x0024080000002000, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionComponent, ActiveInteractableObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveInteractableObject_MetaData), NewProp_ActiveInteractableObject_MetaData) };
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_ActiveInteractableActor = { "ActiveInteractableActor", nullptr, (EPropertyFlags)0x0024080000002000, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionComponent, ActiveInteractableActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveInteractableActor_MetaData), NewProp_ActiveInteractableActor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_PromptWidget = { "PromptWidget", nullptr, (EPropertyFlags)0x0124080000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionComponent, PromptWidget), Z_Construct_UClass_UJMInteractionPromptWidgetBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PromptWidget_MetaData), NewProp_PromptWidget_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_InteractionState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_InteractionState = { "InteractionState", nullptr, (EPropertyFlags)0x0020080000002000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionComponent, InteractionState), Z_Construct_UEnum_JMInteraction_EJMInteractionState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionState_MetaData), NewProp_InteractionState_MetaData) }; // 2284070030
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_LastDisplayedPrompt = { "LastDisplayedPrompt", nullptr, (EPropertyFlags)0x0020080000002000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionComponent, LastDisplayedPrompt), Z_Construct_UScriptStruct_FJMInteractionPrompt, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastDisplayedPrompt_MetaData), NewProp_LastDisplayedPrompt_MetaData) }; // 2592379790
void Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bHasDisplayedPrompt_SetBit(void* Obj)
{
	((UJMInteractionComponent*)Obj)->bHasDisplayedPrompt = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bHasDisplayedPrompt = { "bHasDisplayedPrompt", nullptr, (EPropertyFlags)0x0020080000002000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMInteractionComponent), &Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bHasDisplayedPrompt_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasDisplayedPrompt_MetaData), NewProp_bHasDisplayedPrompt_MetaData) };
void Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bPromptSuppressed_SetBit(void* Obj)
{
	((UJMInteractionComponent*)Obj)->bPromptSuppressed = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bPromptSuppressed = { "bPromptSuppressed", nullptr, (EPropertyFlags)0x0020080000002000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMInteractionComponent), &Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bPromptSuppressed_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPromptSuppressed_MetaData), NewProp_bPromptSuppressed_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMInteractionComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_OnCurrentInteractableChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_OnPromptChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_OnInteractionFinished,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bInteractionEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bOverrideProjectSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_TraceDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_TraceRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_TraceChannel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_DetectionMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_DetectionMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_TraceMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_TraceMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_TraceInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bDrawDebug,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bCreatePromptWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_InteractionPromptWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bOverridePromptStyle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_PromptStyle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_CurrentInteractableObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_CurrentInteractableActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_ActiveInteractableObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_ActiveInteractableActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_PromptWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_InteractionState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_InteractionState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_LastDisplayedPrompt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bHasDisplayedPrompt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionComponent_Statics::NewProp_bPromptSuppressed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractionComponent_Statics::PropPointers) < 2048);
// ********** End Class UJMInteractionComponent Property Definitions *******************************
UObject* (*const Z_Construct_UClass_UJMInteractionComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMInteraction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractionComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMInteractionComponent_Statics::ClassParams = {
	&UJMInteractionComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMInteractionComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractionComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractionComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMInteractionComponent_Statics::Class_MetaDataParams)
};
void UJMInteractionComponent::StaticRegisterNativesUJMInteractionComponent()
{
	UClass* Class = UJMInteractionComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMInteractionComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMInteractionComponent()
{
	if (!Z_Registration_Info_UClass_UJMInteractionComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMInteractionComponent.OuterSingleton, Z_Construct_UClass_UJMInteractionComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMInteractionComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMInteractionComponent);
UJMInteractionComponent::~UJMInteractionComponent() {}
// ********** End Class UJMInteractionComponent ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractionComponent_h__Script_JMInteraction_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMInteractionComponent, UJMInteractionComponent::StaticClass, TEXT("UJMInteractionComponent"), &Z_Registration_Info_UClass_UJMInteractionComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMInteractionComponent), 2417177822U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractionComponent_h__Script_JMInteraction_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractionComponent_h__Script_JMInteraction_23193139{
	TEXT("/Script/JMInteraction"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractionComponent_h__Script_JMInteraction_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractionComponent_h__Script_JMInteraction_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
