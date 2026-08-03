// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interfaces/JMInteractableInterface.h"
#include "Types/JMInteractionTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMInteractableInterface() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractableInterface();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractableInterface_NoRegister();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionContext();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionPrompt();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionResult();
UPackage* Z_Construct_UPackage__Script_JMInteraction();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface UJMInteractableInterface Function BeginInteract **********************
struct JMInteractableInterface_eventBeginInteract_Parms
{
	FJMInteractionContext Context;
	FJMInteractionResult ReturnValue;
};
FJMInteractionResult IJMInteractableInterface::BeginInteract(FJMInteractionContext const& Context)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_BeginInteract instead.");
	JMInteractableInterface_eventBeginInteract_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UJMInteractableInterface_BeginInteract = FName(TEXT("BeginInteract"));
FJMInteractionResult IJMInteractableInterface::Execute_BeginInteract(UObject* O, FJMInteractionContext const& Context)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMInteractableInterface::StaticClass()));
	JMInteractableInterface_eventBeginInteract_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMInteractableInterface_BeginInteract);
	if (Func)
	{
		Parms.Context=std::move(Context);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IJMInteractableInterface*)(O->GetNativeInterfaceAddress(UJMInteractableInterface::StaticClass())))
	{
		Parms.ReturnValue = I->BeginInteract_Implementation(Context);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UJMInteractableInterface_BeginInteract_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Interfaces/JMInteractableInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function BeginInteract constinit property declarations *************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BeginInteract constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BeginInteract Property Definitions ************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractableInterface_BeginInteract_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractableInterface_eventBeginInteract_Parms, Context), Z_Construct_UScriptStruct_FJMInteractionContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3486038698
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractableInterface_BeginInteract_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractableInterface_eventBeginInteract_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMInteractionResult, METADATA_PARAMS(0, nullptr) }; // 240276497
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractableInterface_BeginInteract_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractableInterface_BeginInteract_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractableInterface_BeginInteract_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_BeginInteract_Statics::PropPointers) < 2048);
// ********** End Function BeginInteract Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractableInterface_BeginInteract_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractableInterface, nullptr, "BeginInteract", 	Z_Construct_UFunction_UJMInteractableInterface_BeginInteract_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_BeginInteract_Statics::PropPointers), 
sizeof(JMInteractableInterface_eventBeginInteract_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_BeginInteract_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractableInterface_BeginInteract_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMInteractableInterface_eventBeginInteract_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractableInterface_BeginInteract()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractableInterface_BeginInteract_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMInteractableInterface::execBeginInteract)
{
	P_GET_STRUCT_REF(FJMInteractionContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMInteractionResult*)Z_Param__Result=P_THIS->BeginInteract_Implementation(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Interface UJMInteractableInterface Function BeginInteract ************************

// ********** Begin Interface UJMInteractableInterface Function CancelInteract *********************
struct JMInteractableInterface_eventCancelInteract_Parms
{
	FJMInteractionContext Context;
};
void IJMInteractableInterface::CancelInteract(FJMInteractionContext const& Context)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_CancelInteract instead.");
}
static FName NAME_UJMInteractableInterface_CancelInteract = FName(TEXT("CancelInteract"));
void IJMInteractableInterface::Execute_CancelInteract(UObject* O, FJMInteractionContext const& Context)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMInteractableInterface::StaticClass()));
	JMInteractableInterface_eventCancelInteract_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMInteractableInterface_CancelInteract);
	if (Func)
	{
		Parms.Context=std::move(Context);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IJMInteractableInterface*)(O->GetNativeInterfaceAddress(UJMInteractableInterface::StaticClass())))
	{
		I->CancelInteract_Implementation(Context);
	}
}
struct Z_Construct_UFunction_UJMInteractableInterface_CancelInteract_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Interfaces/JMInteractableInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CancelInteract constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CancelInteract constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CancelInteract Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractableInterface_CancelInteract_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractableInterface_eventCancelInteract_Parms, Context), Z_Construct_UScriptStruct_FJMInteractionContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3486038698
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractableInterface_CancelInteract_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractableInterface_CancelInteract_Statics::NewProp_Context,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_CancelInteract_Statics::PropPointers) < 2048);
// ********** End Function CancelInteract Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractableInterface_CancelInteract_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractableInterface, nullptr, "CancelInteract", 	Z_Construct_UFunction_UJMInteractableInterface_CancelInteract_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_CancelInteract_Statics::PropPointers), 
sizeof(JMInteractableInterface_eventCancelInteract_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_CancelInteract_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractableInterface_CancelInteract_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMInteractableInterface_eventCancelInteract_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractableInterface_CancelInteract()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractableInterface_CancelInteract_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMInteractableInterface::execCancelInteract)
{
	P_GET_STRUCT_REF(FJMInteractionContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CancelInteract_Implementation(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Interface UJMInteractableInterface Function CancelInteract ***********************

// ********** Begin Interface UJMInteractableInterface Function CanInteract ************************
struct JMInteractableInterface_eventCanInteract_Parms
{
	FJMInteractionContext Context;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	JMInteractableInterface_eventCanInteract_Parms()
		: ReturnValue(false)
	{
	}
};
bool IJMInteractableInterface::CanInteract(FJMInteractionContext const& Context) const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_CanInteract instead.");
	JMInteractableInterface_eventCanInteract_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UJMInteractableInterface_CanInteract = FName(TEXT("CanInteract"));
bool IJMInteractableInterface::Execute_CanInteract(const UObject* O, FJMInteractionContext const& Context)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMInteractableInterface::StaticClass()));
	JMInteractableInterface_eventCanInteract_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMInteractableInterface_CanInteract);
	if (Func)
	{
		Parms.Context=std::move(Context);
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IJMInteractableInterface*)(O->GetNativeInterfaceAddress(UJMInteractableInterface::StaticClass())))
	{
		Parms.ReturnValue = I->CanInteract_Implementation(Context);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UJMInteractableInterface_CanInteract_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Interfaces/JMInteractableInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CanInteract constinit property declarations ***************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CanInteract constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CanInteract Property Definitions **************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractableInterface_CanInteract_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractableInterface_eventCanInteract_Parms, Context), Z_Construct_UScriptStruct_FJMInteractionContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3486038698
void Z_Construct_UFunction_UJMInteractableInterface_CanInteract_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMInteractableInterface_eventCanInteract_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMInteractableInterface_CanInteract_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMInteractableInterface_eventCanInteract_Parms), &Z_Construct_UFunction_UJMInteractableInterface_CanInteract_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractableInterface_CanInteract_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractableInterface_CanInteract_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractableInterface_CanInteract_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_CanInteract_Statics::PropPointers) < 2048);
// ********** End Function CanInteract Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractableInterface_CanInteract_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractableInterface, nullptr, "CanInteract", 	Z_Construct_UFunction_UJMInteractableInterface_CanInteract_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_CanInteract_Statics::PropPointers), 
sizeof(JMInteractableInterface_eventCanInteract_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_CanInteract_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractableInterface_CanInteract_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMInteractableInterface_eventCanInteract_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractableInterface_CanInteract()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractableInterface_CanInteract_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMInteractableInterface::execCanInteract)
{
	P_GET_STRUCT_REF(FJMInteractionContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanInteract_Implementation(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Interface UJMInteractableInterface Function CanInteract **************************

// ********** Begin Interface UJMInteractableInterface Function CompleteInteract *******************
struct JMInteractableInterface_eventCompleteInteract_Parms
{
	FJMInteractionContext Context;
	FJMInteractionResult ReturnValue;
};
FJMInteractionResult IJMInteractableInterface::CompleteInteract(FJMInteractionContext const& Context)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_CompleteInteract instead.");
	JMInteractableInterface_eventCompleteInteract_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UJMInteractableInterface_CompleteInteract = FName(TEXT("CompleteInteract"));
FJMInteractionResult IJMInteractableInterface::Execute_CompleteInteract(UObject* O, FJMInteractionContext const& Context)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMInteractableInterface::StaticClass()));
	JMInteractableInterface_eventCompleteInteract_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMInteractableInterface_CompleteInteract);
	if (Func)
	{
		Parms.Context=std::move(Context);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IJMInteractableInterface*)(O->GetNativeInterfaceAddress(UJMInteractableInterface::StaticClass())))
	{
		Parms.ReturnValue = I->CompleteInteract_Implementation(Context);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UJMInteractableInterface_CompleteInteract_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Interfaces/JMInteractableInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CompleteInteract constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CompleteInteract constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CompleteInteract Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractableInterface_CompleteInteract_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractableInterface_eventCompleteInteract_Parms, Context), Z_Construct_UScriptStruct_FJMInteractionContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3486038698
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractableInterface_CompleteInteract_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractableInterface_eventCompleteInteract_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMInteractionResult, METADATA_PARAMS(0, nullptr) }; // 240276497
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractableInterface_CompleteInteract_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractableInterface_CompleteInteract_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractableInterface_CompleteInteract_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_CompleteInteract_Statics::PropPointers) < 2048);
// ********** End Function CompleteInteract Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractableInterface_CompleteInteract_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractableInterface, nullptr, "CompleteInteract", 	Z_Construct_UFunction_UJMInteractableInterface_CompleteInteract_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_CompleteInteract_Statics::PropPointers), 
sizeof(JMInteractableInterface_eventCompleteInteract_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_CompleteInteract_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractableInterface_CompleteInteract_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMInteractableInterface_eventCompleteInteract_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractableInterface_CompleteInteract()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractableInterface_CompleteInteract_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMInteractableInterface::execCompleteInteract)
{
	P_GET_STRUCT_REF(FJMInteractionContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMInteractionResult*)Z_Param__Result=P_THIS->CompleteInteract_Implementation(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Interface UJMInteractableInterface Function CompleteInteract *********************

// ********** Begin Interface UJMInteractableInterface Function GetInteractionDuration *************
struct JMInteractableInterface_eventGetInteractionDuration_Parms
{
	FJMInteractionContext Context;
	float ReturnValue;

	/** Constructor, initializes return property only **/
	JMInteractableInterface_eventGetInteractionDuration_Parms()
		: ReturnValue(0)
	{
	}
};
float IJMInteractableInterface::GetInteractionDuration(FJMInteractionContext const& Context) const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetInteractionDuration instead.");
	JMInteractableInterface_eventGetInteractionDuration_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UJMInteractableInterface_GetInteractionDuration = FName(TEXT("GetInteractionDuration"));
float IJMInteractableInterface::Execute_GetInteractionDuration(const UObject* O, FJMInteractionContext const& Context)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMInteractableInterface::StaticClass()));
	JMInteractableInterface_eventGetInteractionDuration_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMInteractableInterface_GetInteractionDuration);
	if (Func)
	{
		Parms.Context=std::move(Context);
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IJMInteractableInterface*)(O->GetNativeInterfaceAddress(UJMInteractableInterface::StaticClass())))
	{
		Parms.ReturnValue = I->GetInteractionDuration_Implementation(Context);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UJMInteractableInterface_GetInteractionDuration_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Interfaces/JMInteractableInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetInteractionDuration constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetInteractionDuration constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetInteractionDuration Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractableInterface_GetInteractionDuration_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractableInterface_eventGetInteractionDuration_Parms, Context), Z_Construct_UScriptStruct_FJMInteractionContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3486038698
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMInteractableInterface_GetInteractionDuration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractableInterface_eventGetInteractionDuration_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractableInterface_GetInteractionDuration_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractableInterface_GetInteractionDuration_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractableInterface_GetInteractionDuration_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_GetInteractionDuration_Statics::PropPointers) < 2048);
// ********** End Function GetInteractionDuration Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractableInterface_GetInteractionDuration_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractableInterface, nullptr, "GetInteractionDuration", 	Z_Construct_UFunction_UJMInteractableInterface_GetInteractionDuration_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_GetInteractionDuration_Statics::PropPointers), 
sizeof(JMInteractableInterface_eventGetInteractionDuration_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_GetInteractionDuration_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractableInterface_GetInteractionDuration_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMInteractableInterface_eventGetInteractionDuration_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractableInterface_GetInteractionDuration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractableInterface_GetInteractionDuration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMInteractableInterface::execGetInteractionDuration)
{
	P_GET_STRUCT_REF(FJMInteractionContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetInteractionDuration_Implementation(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Interface UJMInteractableInterface Function GetInteractionDuration ***************

// ********** Begin Interface UJMInteractableInterface Function GetInteractionPriority *************
struct JMInteractableInterface_eventGetInteractionPriority_Parms
{
	FJMInteractionContext Context;
	int32 ReturnValue;

	/** Constructor, initializes return property only **/
	JMInteractableInterface_eventGetInteractionPriority_Parms()
		: ReturnValue(0)
	{
	}
};
int32 IJMInteractableInterface::GetInteractionPriority(FJMInteractionContext const& Context) const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetInteractionPriority instead.");
	JMInteractableInterface_eventGetInteractionPriority_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UJMInteractableInterface_GetInteractionPriority = FName(TEXT("GetInteractionPriority"));
int32 IJMInteractableInterface::Execute_GetInteractionPriority(const UObject* O, FJMInteractionContext const& Context)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMInteractableInterface::StaticClass()));
	JMInteractableInterface_eventGetInteractionPriority_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMInteractableInterface_GetInteractionPriority);
	if (Func)
	{
		Parms.Context=std::move(Context);
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IJMInteractableInterface*)(O->GetNativeInterfaceAddress(UJMInteractableInterface::StaticClass())))
	{
		Parms.ReturnValue = I->GetInteractionPriority_Implementation(Context);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPriority_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Interfaces/JMInteractableInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetInteractionPriority constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetInteractionPriority constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetInteractionPriority Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPriority_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractableInterface_eventGetInteractionPriority_Parms, Context), Z_Construct_UScriptStruct_FJMInteractionContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3486038698
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPriority_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractableInterface_eventGetInteractionPriority_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPriority_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPriority_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPriority_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPriority_Statics::PropPointers) < 2048);
// ********** End Function GetInteractionPriority Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPriority_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractableInterface, nullptr, "GetInteractionPriority", 	Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPriority_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPriority_Statics::PropPointers), 
sizeof(JMInteractableInterface_eventGetInteractionPriority_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPriority_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPriority_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMInteractableInterface_eventGetInteractionPriority_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPriority()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPriority_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMInteractableInterface::execGetInteractionPriority)
{
	P_GET_STRUCT_REF(FJMInteractionContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetInteractionPriority_Implementation(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Interface UJMInteractableInterface Function GetInteractionPriority ***************

// ********** Begin Interface UJMInteractableInterface Function GetInteractionPrompt ***************
struct JMInteractableInterface_eventGetInteractionPrompt_Parms
{
	FJMInteractionContext Context;
	FJMInteractionPrompt ReturnValue;
};
FJMInteractionPrompt IJMInteractableInterface::GetInteractionPrompt(FJMInteractionContext const& Context) const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetInteractionPrompt instead.");
	JMInteractableInterface_eventGetInteractionPrompt_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UJMInteractableInterface_GetInteractionPrompt = FName(TEXT("GetInteractionPrompt"));
FJMInteractionPrompt IJMInteractableInterface::Execute_GetInteractionPrompt(const UObject* O, FJMInteractionContext const& Context)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMInteractableInterface::StaticClass()));
	JMInteractableInterface_eventGetInteractionPrompt_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMInteractableInterface_GetInteractionPrompt);
	if (Func)
	{
		Parms.Context=std::move(Context);
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IJMInteractableInterface*)(O->GetNativeInterfaceAddress(UJMInteractableInterface::StaticClass())))
	{
		Parms.ReturnValue = I->GetInteractionPrompt_Implementation(Context);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPrompt_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Interfaces/JMInteractableInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetInteractionPrompt constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetInteractionPrompt constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetInteractionPrompt Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPrompt_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractableInterface_eventGetInteractionPrompt_Parms, Context), Z_Construct_UScriptStruct_FJMInteractionContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3486038698
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPrompt_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractableInterface_eventGetInteractionPrompt_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMInteractionPrompt, METADATA_PARAMS(0, nullptr) }; // 2592379790
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPrompt_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPrompt_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPrompt_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPrompt_Statics::PropPointers) < 2048);
// ********** End Function GetInteractionPrompt Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPrompt_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractableInterface, nullptr, "GetInteractionPrompt", 	Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPrompt_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPrompt_Statics::PropPointers), 
sizeof(JMInteractableInterface_eventGetInteractionPrompt_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPrompt_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPrompt_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMInteractableInterface_eventGetInteractionPrompt_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPrompt()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPrompt_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMInteractableInterface::execGetInteractionPrompt)
{
	P_GET_STRUCT_REF(FJMInteractionContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMInteractionPrompt*)Z_Param__Result=P_THIS->GetInteractionPrompt_Implementation(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Interface UJMInteractableInterface Function GetInteractionPrompt *****************

// ********** Begin Interface UJMInteractableInterface Function OnFocusBegin ***********************
struct JMInteractableInterface_eventOnFocusBegin_Parms
{
	FJMInteractionContext Context;
};
void IJMInteractableInterface::OnFocusBegin(FJMInteractionContext const& Context)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnFocusBegin instead.");
}
static FName NAME_UJMInteractableInterface_OnFocusBegin = FName(TEXT("OnFocusBegin"));
void IJMInteractableInterface::Execute_OnFocusBegin(UObject* O, FJMInteractionContext const& Context)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMInteractableInterface::StaticClass()));
	JMInteractableInterface_eventOnFocusBegin_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMInteractableInterface_OnFocusBegin);
	if (Func)
	{
		Parms.Context=std::move(Context);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IJMInteractableInterface*)(O->GetNativeInterfaceAddress(UJMInteractableInterface::StaticClass())))
	{
		I->OnFocusBegin_Implementation(Context);
	}
}
struct Z_Construct_UFunction_UJMInteractableInterface_OnFocusBegin_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Interfaces/JMInteractableInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnFocusBegin constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnFocusBegin constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnFocusBegin Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractableInterface_OnFocusBegin_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractableInterface_eventOnFocusBegin_Parms, Context), Z_Construct_UScriptStruct_FJMInteractionContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3486038698
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractableInterface_OnFocusBegin_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractableInterface_OnFocusBegin_Statics::NewProp_Context,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_OnFocusBegin_Statics::PropPointers) < 2048);
// ********** End Function OnFocusBegin Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractableInterface_OnFocusBegin_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractableInterface, nullptr, "OnFocusBegin", 	Z_Construct_UFunction_UJMInteractableInterface_OnFocusBegin_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_OnFocusBegin_Statics::PropPointers), 
sizeof(JMInteractableInterface_eventOnFocusBegin_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_OnFocusBegin_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractableInterface_OnFocusBegin_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMInteractableInterface_eventOnFocusBegin_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractableInterface_OnFocusBegin()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractableInterface_OnFocusBegin_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMInteractableInterface::execOnFocusBegin)
{
	P_GET_STRUCT_REF(FJMInteractionContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnFocusBegin_Implementation(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Interface UJMInteractableInterface Function OnFocusBegin *************************

// ********** Begin Interface UJMInteractableInterface Function OnFocusEnd *************************
struct JMInteractableInterface_eventOnFocusEnd_Parms
{
	FJMInteractionContext Context;
};
void IJMInteractableInterface::OnFocusEnd(FJMInteractionContext const& Context)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnFocusEnd instead.");
}
static FName NAME_UJMInteractableInterface_OnFocusEnd = FName(TEXT("OnFocusEnd"));
void IJMInteractableInterface::Execute_OnFocusEnd(UObject* O, FJMInteractionContext const& Context)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMInteractableInterface::StaticClass()));
	JMInteractableInterface_eventOnFocusEnd_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMInteractableInterface_OnFocusEnd);
	if (Func)
	{
		Parms.Context=std::move(Context);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IJMInteractableInterface*)(O->GetNativeInterfaceAddress(UJMInteractableInterface::StaticClass())))
	{
		I->OnFocusEnd_Implementation(Context);
	}
}
struct Z_Construct_UFunction_UJMInteractableInterface_OnFocusEnd_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Interfaces/JMInteractableInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnFocusEnd constinit property declarations ****************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnFocusEnd constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnFocusEnd Property Definitions ***************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractableInterface_OnFocusEnd_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractableInterface_eventOnFocusEnd_Parms, Context), Z_Construct_UScriptStruct_FJMInteractionContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3486038698
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractableInterface_OnFocusEnd_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractableInterface_OnFocusEnd_Statics::NewProp_Context,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_OnFocusEnd_Statics::PropPointers) < 2048);
// ********** End Function OnFocusEnd Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractableInterface_OnFocusEnd_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractableInterface, nullptr, "OnFocusEnd", 	Z_Construct_UFunction_UJMInteractableInterface_OnFocusEnd_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_OnFocusEnd_Statics::PropPointers), 
sizeof(JMInteractableInterface_eventOnFocusEnd_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableInterface_OnFocusEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractableInterface_OnFocusEnd_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMInteractableInterface_eventOnFocusEnd_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractableInterface_OnFocusEnd()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractableInterface_OnFocusEnd_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMInteractableInterface::execOnFocusEnd)
{
	P_GET_STRUCT_REF(FJMInteractionContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnFocusEnd_Implementation(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Interface UJMInteractableInterface Function OnFocusEnd ***************************

// ********** Begin Interface UJMInteractableInterface *********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMInteractableInterface;
UClass* UJMInteractableInterface::GetPrivateStaticClass()
{
	using TClass = UJMInteractableInterface;
	if (!Z_Registration_Info_UClass_UJMInteractableInterface.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMInteractableInterface"),
			Z_Registration_Info_UClass_UJMInteractableInterface.InnerSingleton,
			StaticRegisterNativesUJMInteractableInterface,
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
	return Z_Registration_Info_UClass_UJMInteractableInterface.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMInteractableInterface_NoRegister()
{
	return UJMInteractableInterface::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMInteractableInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Interfaces/JMInteractableInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface UJMInteractableInterface constinit property declarations *************
// ********** End Interface UJMInteractableInterface constinit property declarations ***************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("BeginInteract"), .Pointer = &IJMInteractableInterface::execBeginInteract },
		{ .NameUTF8 = UTF8TEXT("CancelInteract"), .Pointer = &IJMInteractableInterface::execCancelInteract },
		{ .NameUTF8 = UTF8TEXT("CanInteract"), .Pointer = &IJMInteractableInterface::execCanInteract },
		{ .NameUTF8 = UTF8TEXT("CompleteInteract"), .Pointer = &IJMInteractableInterface::execCompleteInteract },
		{ .NameUTF8 = UTF8TEXT("GetInteractionDuration"), .Pointer = &IJMInteractableInterface::execGetInteractionDuration },
		{ .NameUTF8 = UTF8TEXT("GetInteractionPriority"), .Pointer = &IJMInteractableInterface::execGetInteractionPriority },
		{ .NameUTF8 = UTF8TEXT("GetInteractionPrompt"), .Pointer = &IJMInteractableInterface::execGetInteractionPrompt },
		{ .NameUTF8 = UTF8TEXT("OnFocusBegin"), .Pointer = &IJMInteractableInterface::execOnFocusBegin },
		{ .NameUTF8 = UTF8TEXT("OnFocusEnd"), .Pointer = &IJMInteractableInterface::execOnFocusEnd },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMInteractableInterface_BeginInteract, "BeginInteract" }, // 2214334913
		{ &Z_Construct_UFunction_UJMInteractableInterface_CancelInteract, "CancelInteract" }, // 816903128
		{ &Z_Construct_UFunction_UJMInteractableInterface_CanInteract, "CanInteract" }, // 837671754
		{ &Z_Construct_UFunction_UJMInteractableInterface_CompleteInteract, "CompleteInteract" }, // 2567212718
		{ &Z_Construct_UFunction_UJMInteractableInterface_GetInteractionDuration, "GetInteractionDuration" }, // 3762103732
		{ &Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPriority, "GetInteractionPriority" }, // 2918445539
		{ &Z_Construct_UFunction_UJMInteractableInterface_GetInteractionPrompt, "GetInteractionPrompt" }, // 3515882121
		{ &Z_Construct_UFunction_UJMInteractableInterface_OnFocusBegin, "OnFocusBegin" }, // 2535151058
		{ &Z_Construct_UFunction_UJMInteractableInterface_OnFocusEnd, "OnFocusEnd" }, // 4220175944
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IJMInteractableInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMInteractableInterface_Statics
UObject* (*const Z_Construct_UClass_UJMInteractableInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_JMInteraction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractableInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMInteractableInterface_Statics::ClassParams = {
	&UJMInteractableInterface::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractableInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMInteractableInterface_Statics::Class_MetaDataParams)
};
void UJMInteractableInterface::StaticRegisterNativesUJMInteractableInterface()
{
	UClass* Class = UJMInteractableInterface::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMInteractableInterface_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMInteractableInterface()
{
	if (!Z_Registration_Info_UClass_UJMInteractableInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMInteractableInterface.OuterSingleton, Z_Construct_UClass_UJMInteractableInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMInteractableInterface.OuterSingleton;
}
UJMInteractableInterface::UJMInteractableInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMInteractableInterface);
// ********** End Interface UJMInteractableInterface ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractableInterface_h__Script_JMInteraction_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMInteractableInterface, UJMInteractableInterface::StaticClass, TEXT("UJMInteractableInterface"), &Z_Registration_Info_UClass_UJMInteractableInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMInteractableInterface), 680874699U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractableInterface_h__Script_JMInteraction_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractableInterface_h__Script_JMInteraction_573748927{
	TEXT("/Script/JMInteraction"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractableInterface_h__Script_JMInteraction_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractableInterface_h__Script_JMInteraction_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
