// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interfaces/JMJumpScareActorInterface.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMJumpScareActorInterface() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareActorInterface();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareActorInterface_NoRegister();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareDefinition_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMJumpScare();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface UJMJumpScareActorInterface Function OnJumpScareCancelled *************
struct JMJumpScareActorInterface_eventOnJumpScareCancelled_Parms
{
	UJMJumpScareDefinition* Definition;
};
void IJMJumpScareActorInterface::OnJumpScareCancelled(UJMJumpScareDefinition* Definition)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnJumpScareCancelled instead.");
}
static FName NAME_UJMJumpScareActorInterface_OnJumpScareCancelled = FName(TEXT("OnJumpScareCancelled"));
void IJMJumpScareActorInterface::Execute_OnJumpScareCancelled(UObject* O, UJMJumpScareDefinition* Definition)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMJumpScareActorInterface::StaticClass()));
	JMJumpScareActorInterface_eventOnJumpScareCancelled_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMJumpScareActorInterface_OnJumpScareCancelled);
	if (Func)
	{
		Parms.Definition=std::move(Definition);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IJMJumpScareActorInterface*)(O->GetNativeInterfaceAddress(UJMJumpScareActorInterface::StaticClass())))
	{
		I->OnJumpScareCancelled_Implementation(Definition);
	}
}
struct Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareCancelled_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Interfaces/JMJumpScareActorInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnJumpScareCancelled constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Definition;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnJumpScareCancelled constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnJumpScareCancelled Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareCancelled_Statics::NewProp_Definition = { "Definition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMJumpScareActorInterface_eventOnJumpScareCancelled_Parms, Definition), Z_Construct_UClass_UJMJumpScareDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareCancelled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareCancelled_Statics::NewProp_Definition,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareCancelled_Statics::PropPointers) < 2048);
// ********** End Function OnJumpScareCancelled Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareCancelled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMJumpScareActorInterface, nullptr, "OnJumpScareCancelled", 	Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareCancelled_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareCancelled_Statics::PropPointers), 
sizeof(JMJumpScareActorInterface_eventOnJumpScareCancelled_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareCancelled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareCancelled_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMJumpScareActorInterface_eventOnJumpScareCancelled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareCancelled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareCancelled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMJumpScareActorInterface::execOnJumpScareCancelled)
{
	P_GET_OBJECT(UJMJumpScareDefinition,Z_Param_Definition);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnJumpScareCancelled_Implementation(Z_Param_Definition);
	P_NATIVE_END;
}
// ********** End Interface UJMJumpScareActorInterface Function OnJumpScareCancelled ***************

// ********** Begin Interface UJMJumpScareActorInterface Function OnJumpScareExiting ***************
struct JMJumpScareActorInterface_eventOnJumpScareExiting_Parms
{
	UJMJumpScareDefinition* Definition;
};
void IJMJumpScareActorInterface::OnJumpScareExiting(UJMJumpScareDefinition* Definition)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnJumpScareExiting instead.");
}
static FName NAME_UJMJumpScareActorInterface_OnJumpScareExiting = FName(TEXT("OnJumpScareExiting"));
void IJMJumpScareActorInterface::Execute_OnJumpScareExiting(UObject* O, UJMJumpScareDefinition* Definition)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMJumpScareActorInterface::StaticClass()));
	JMJumpScareActorInterface_eventOnJumpScareExiting_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMJumpScareActorInterface_OnJumpScareExiting);
	if (Func)
	{
		Parms.Definition=std::move(Definition);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IJMJumpScareActorInterface*)(O->GetNativeInterfaceAddress(UJMJumpScareActorInterface::StaticClass())))
	{
		I->OnJumpScareExiting_Implementation(Definition);
	}
}
struct Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareExiting_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Interfaces/JMJumpScareActorInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnJumpScareExiting constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Definition;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnJumpScareExiting constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnJumpScareExiting Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareExiting_Statics::NewProp_Definition = { "Definition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMJumpScareActorInterface_eventOnJumpScareExiting_Parms, Definition), Z_Construct_UClass_UJMJumpScareDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareExiting_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareExiting_Statics::NewProp_Definition,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareExiting_Statics::PropPointers) < 2048);
// ********** End Function OnJumpScareExiting Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareExiting_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMJumpScareActorInterface, nullptr, "OnJumpScareExiting", 	Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareExiting_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareExiting_Statics::PropPointers), 
sizeof(JMJumpScareActorInterface_eventOnJumpScareExiting_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareExiting_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareExiting_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMJumpScareActorInterface_eventOnJumpScareExiting_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareExiting()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareExiting_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMJumpScareActorInterface::execOnJumpScareExiting)
{
	P_GET_OBJECT(UJMJumpScareDefinition,Z_Param_Definition);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnJumpScareExiting_Implementation(Z_Param_Definition);
	P_NATIVE_END;
}
// ********** End Interface UJMJumpScareActorInterface Function OnJumpScareExiting *****************

// ********** Begin Interface UJMJumpScareActorInterface Function OnJumpScareFinished **************
struct JMJumpScareActorInterface_eventOnJumpScareFinished_Parms
{
	UJMJumpScareDefinition* Definition;
};
void IJMJumpScareActorInterface::OnJumpScareFinished(UJMJumpScareDefinition* Definition)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnJumpScareFinished instead.");
}
static FName NAME_UJMJumpScareActorInterface_OnJumpScareFinished = FName(TEXT("OnJumpScareFinished"));
void IJMJumpScareActorInterface::Execute_OnJumpScareFinished(UObject* O, UJMJumpScareDefinition* Definition)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMJumpScareActorInterface::StaticClass()));
	JMJumpScareActorInterface_eventOnJumpScareFinished_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMJumpScareActorInterface_OnJumpScareFinished);
	if (Func)
	{
		Parms.Definition=std::move(Definition);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IJMJumpScareActorInterface*)(O->GetNativeInterfaceAddress(UJMJumpScareActorInterface::StaticClass())))
	{
		I->OnJumpScareFinished_Implementation(Definition);
	}
}
struct Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareFinished_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Interfaces/JMJumpScareActorInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnJumpScareFinished constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Definition;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnJumpScareFinished constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnJumpScareFinished Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareFinished_Statics::NewProp_Definition = { "Definition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMJumpScareActorInterface_eventOnJumpScareFinished_Parms, Definition), Z_Construct_UClass_UJMJumpScareDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareFinished_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareFinished_Statics::NewProp_Definition,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareFinished_Statics::PropPointers) < 2048);
// ********** End Function OnJumpScareFinished Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareFinished_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMJumpScareActorInterface, nullptr, "OnJumpScareFinished", 	Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareFinished_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareFinished_Statics::PropPointers), 
sizeof(JMJumpScareActorInterface_eventOnJumpScareFinished_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareFinished_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareFinished_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMJumpScareActorInterface_eventOnJumpScareFinished_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareFinished()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareFinished_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMJumpScareActorInterface::execOnJumpScareFinished)
{
	P_GET_OBJECT(UJMJumpScareDefinition,Z_Param_Definition);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnJumpScareFinished_Implementation(Z_Param_Definition);
	P_NATIVE_END;
}
// ********** End Interface UJMJumpScareActorInterface Function OnJumpScareFinished ****************

// ********** Begin Interface UJMJumpScareActorInterface Function OnJumpScareImpact ****************
struct JMJumpScareActorInterface_eventOnJumpScareImpact_Parms
{
	UJMJumpScareDefinition* Definition;
};
void IJMJumpScareActorInterface::OnJumpScareImpact(UJMJumpScareDefinition* Definition)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnJumpScareImpact instead.");
}
static FName NAME_UJMJumpScareActorInterface_OnJumpScareImpact = FName(TEXT("OnJumpScareImpact"));
void IJMJumpScareActorInterface::Execute_OnJumpScareImpact(UObject* O, UJMJumpScareDefinition* Definition)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMJumpScareActorInterface::StaticClass()));
	JMJumpScareActorInterface_eventOnJumpScareImpact_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMJumpScareActorInterface_OnJumpScareImpact);
	if (Func)
	{
		Parms.Definition=std::move(Definition);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IJMJumpScareActorInterface*)(O->GetNativeInterfaceAddress(UJMJumpScareActorInterface::StaticClass())))
	{
		I->OnJumpScareImpact_Implementation(Definition);
	}
}
struct Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareImpact_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Interfaces/JMJumpScareActorInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnJumpScareImpact constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Definition;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnJumpScareImpact constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnJumpScareImpact Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareImpact_Statics::NewProp_Definition = { "Definition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMJumpScareActorInterface_eventOnJumpScareImpact_Parms, Definition), Z_Construct_UClass_UJMJumpScareDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareImpact_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareImpact_Statics::NewProp_Definition,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareImpact_Statics::PropPointers) < 2048);
// ********** End Function OnJumpScareImpact Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareImpact_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMJumpScareActorInterface, nullptr, "OnJumpScareImpact", 	Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareImpact_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareImpact_Statics::PropPointers), 
sizeof(JMJumpScareActorInterface_eventOnJumpScareImpact_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareImpact_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareImpact_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMJumpScareActorInterface_eventOnJumpScareImpact_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareImpact()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareImpact_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMJumpScareActorInterface::execOnJumpScareImpact)
{
	P_GET_OBJECT(UJMJumpScareDefinition,Z_Param_Definition);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnJumpScareImpact_Implementation(Z_Param_Definition);
	P_NATIVE_END;
}
// ********** End Interface UJMJumpScareActorInterface Function OnJumpScareImpact ******************

// ********** Begin Interface UJMJumpScareActorInterface Function OnJumpScareStarted ***************
struct JMJumpScareActorInterface_eventOnJumpScareStarted_Parms
{
	UJMJumpScareDefinition* Definition;
};
void IJMJumpScareActorInterface::OnJumpScareStarted(UJMJumpScareDefinition* Definition)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnJumpScareStarted instead.");
}
static FName NAME_UJMJumpScareActorInterface_OnJumpScareStarted = FName(TEXT("OnJumpScareStarted"));
void IJMJumpScareActorInterface::Execute_OnJumpScareStarted(UObject* O, UJMJumpScareDefinition* Definition)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMJumpScareActorInterface::StaticClass()));
	JMJumpScareActorInterface_eventOnJumpScareStarted_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMJumpScareActorInterface_OnJumpScareStarted);
	if (Func)
	{
		Parms.Definition=std::move(Definition);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IJMJumpScareActorInterface*)(O->GetNativeInterfaceAddress(UJMJumpScareActorInterface::StaticClass())))
	{
		I->OnJumpScareStarted_Implementation(Definition);
	}
}
struct Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareStarted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Interfaces/JMJumpScareActorInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnJumpScareStarted constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Definition;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnJumpScareStarted constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnJumpScareStarted Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareStarted_Statics::NewProp_Definition = { "Definition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMJumpScareActorInterface_eventOnJumpScareStarted_Parms, Definition), Z_Construct_UClass_UJMJumpScareDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareStarted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareStarted_Statics::NewProp_Definition,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareStarted_Statics::PropPointers) < 2048);
// ********** End Function OnJumpScareStarted Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareStarted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMJumpScareActorInterface, nullptr, "OnJumpScareStarted", 	Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareStarted_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareStarted_Statics::PropPointers), 
sizeof(JMJumpScareActorInterface_eventOnJumpScareStarted_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareStarted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareStarted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMJumpScareActorInterface_eventOnJumpScareStarted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareStarted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareStarted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMJumpScareActorInterface::execOnJumpScareStarted)
{
	P_GET_OBJECT(UJMJumpScareDefinition,Z_Param_Definition);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnJumpScareStarted_Implementation(Z_Param_Definition);
	P_NATIVE_END;
}
// ********** End Interface UJMJumpScareActorInterface Function OnJumpScareStarted *****************

// ********** Begin Interface UJMJumpScareActorInterface *******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMJumpScareActorInterface;
UClass* UJMJumpScareActorInterface::GetPrivateStaticClass()
{
	using TClass = UJMJumpScareActorInterface;
	if (!Z_Registration_Info_UClass_UJMJumpScareActorInterface.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMJumpScareActorInterface"),
			Z_Registration_Info_UClass_UJMJumpScareActorInterface.InnerSingleton,
			StaticRegisterNativesUJMJumpScareActorInterface,
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
	return Z_Registration_Info_UClass_UJMJumpScareActorInterface.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMJumpScareActorInterface_NoRegister()
{
	return UJMJumpScareActorInterface::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMJumpScareActorInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Interfaces/JMJumpScareActorInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface UJMJumpScareActorInterface constinit property declarations ***********
// ********** End Interface UJMJumpScareActorInterface constinit property declarations *************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("OnJumpScareCancelled"), .Pointer = &IJMJumpScareActorInterface::execOnJumpScareCancelled },
		{ .NameUTF8 = UTF8TEXT("OnJumpScareExiting"), .Pointer = &IJMJumpScareActorInterface::execOnJumpScareExiting },
		{ .NameUTF8 = UTF8TEXT("OnJumpScareFinished"), .Pointer = &IJMJumpScareActorInterface::execOnJumpScareFinished },
		{ .NameUTF8 = UTF8TEXT("OnJumpScareImpact"), .Pointer = &IJMJumpScareActorInterface::execOnJumpScareImpact },
		{ .NameUTF8 = UTF8TEXT("OnJumpScareStarted"), .Pointer = &IJMJumpScareActorInterface::execOnJumpScareStarted },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareCancelled, "OnJumpScareCancelled" }, // 3821612884
		{ &Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareExiting, "OnJumpScareExiting" }, // 214124980
		{ &Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareFinished, "OnJumpScareFinished" }, // 1907076430
		{ &Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareImpact, "OnJumpScareImpact" }, // 3378858637
		{ &Z_Construct_UFunction_UJMJumpScareActorInterface_OnJumpScareStarted, "OnJumpScareStarted" }, // 395396680
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IJMJumpScareActorInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMJumpScareActorInterface_Statics
UObject* (*const Z_Construct_UClass_UJMJumpScareActorInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_JMJumpScare,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareActorInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMJumpScareActorInterface_Statics::ClassParams = {
	&UJMJumpScareActorInterface::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareActorInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMJumpScareActorInterface_Statics::Class_MetaDataParams)
};
void UJMJumpScareActorInterface::StaticRegisterNativesUJMJumpScareActorInterface()
{
	UClass* Class = UJMJumpScareActorInterface::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMJumpScareActorInterface_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMJumpScareActorInterface()
{
	if (!Z_Registration_Info_UClass_UJMJumpScareActorInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMJumpScareActorInterface.OuterSingleton, Z_Construct_UClass_UJMJumpScareActorInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMJumpScareActorInterface.OuterSingleton;
}
UJMJumpScareActorInterface::UJMJumpScareActorInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMJumpScareActorInterface);
// ********** End Interface UJMJumpScareActorInterface *********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Interfaces_JMJumpScareActorInterface_h__Script_JMJumpScare_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMJumpScareActorInterface, UJMJumpScareActorInterface::StaticClass, TEXT("UJMJumpScareActorInterface"), &Z_Registration_Info_UClass_UJMJumpScareActorInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMJumpScareActorInterface), 2799978920U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Interfaces_JMJumpScareActorInterface_h__Script_JMJumpScare_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Interfaces_JMJumpScareActorInterface_h__Script_JMJumpScare_2782818991{
	TEXT("/Script/JMJumpScare"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Interfaces_JMJumpScareActorInterface_h__Script_JMJumpScare_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Interfaces_JMJumpScareActorInterface_h__Script_JMJumpScare_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
