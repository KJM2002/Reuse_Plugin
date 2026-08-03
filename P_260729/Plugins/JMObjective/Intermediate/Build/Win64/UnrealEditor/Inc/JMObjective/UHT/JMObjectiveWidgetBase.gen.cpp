// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/JMObjectiveWidgetBase.h"
#include "GameplayTagContainer.h"
#include "Types/JMObjectiveTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMObjectiveWidgetBase() {}

// ********** Begin Cross Module References ********************************************************
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveWidgetBase();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveWidgetBase_NoRegister();
JMOBJECTIVE_API UScriptStruct* Z_Construct_UScriptStruct_FJMObjectiveRuntimeState();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_JMObjective();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMObjectiveWidgetBase Function GetObjectiveState ************************
struct Z_Construct_UFunction_UJMObjectiveWidgetBase_GetObjectiveState_Statics
{
	struct JMObjectiveWidgetBase_eventGetObjectiveState_Parms
	{
		FJMObjectiveRuntimeState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective|UI" },
		{ "ModuleRelativePath", "Public/UI/JMObjectiveWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetObjectiveState constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetObjectiveState constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetObjectiveState Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveWidgetBase_GetObjectiveState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveWidgetBase_eventGetObjectiveState_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, METADATA_PARAMS(0, nullptr) }; // 4088304728
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveWidgetBase_GetObjectiveState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveWidgetBase_GetObjectiveState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_GetObjectiveState_Statics::PropPointers) < 2048);
// ********** End Function GetObjectiveState Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveWidgetBase_GetObjectiveState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveWidgetBase, nullptr, "GetObjectiveState", 	Z_Construct_UFunction_UJMObjectiveWidgetBase_GetObjectiveState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_GetObjectiveState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveWidgetBase_GetObjectiveState_Statics::JMObjectiveWidgetBase_eventGetObjectiveState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_GetObjectiveState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveWidgetBase_GetObjectiveState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveWidgetBase_GetObjectiveState_Statics::JMObjectiveWidgetBase_eventGetObjectiveState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveWidgetBase_GetObjectiveState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveWidgetBase_GetObjectiveState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveWidgetBase::execGetObjectiveState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMObjectiveRuntimeState*)Z_Param__Result=P_THIS->GetObjectiveState();
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveWidgetBase Function GetObjectiveState **************************

// ********** Begin Class UJMObjectiveWidgetBase Function OnObjectiveActivated *********************
struct JMObjectiveWidgetBase_eventOnObjectiveActivated_Parms
{
	FJMObjectiveRuntimeState InRuntimeState;
};
static FName NAME_UJMObjectiveWidgetBase_OnObjectiveActivated = FName(TEXT("OnObjectiveActivated"));
void UJMObjectiveWidgetBase::OnObjectiveActivated(FJMObjectiveRuntimeState const& InRuntimeState)
{
	JMObjectiveWidgetBase_eventOnObjectiveActivated_Parms Parms;
	Parms.InRuntimeState=InRuntimeState;
	UFunction* Func = FindFunctionChecked(NAME_UJMObjectiveWidgetBase_OnObjectiveActivated);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveActivated_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective|UI" },
		{ "ModuleRelativePath", "Public/UI/JMObjectiveWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InRuntimeState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnObjectiveActivated constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InRuntimeState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnObjectiveActivated constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnObjectiveActivated Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveActivated_Statics::NewProp_InRuntimeState = { "InRuntimeState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveWidgetBase_eventOnObjectiveActivated_Parms, InRuntimeState), Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InRuntimeState_MetaData), NewProp_InRuntimeState_MetaData) }; // 4088304728
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveActivated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveActivated_Statics::NewProp_InRuntimeState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveActivated_Statics::PropPointers) < 2048);
// ********** End Function OnObjectiveActivated Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveActivated_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveWidgetBase, nullptr, "OnObjectiveActivated", 	Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveActivated_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveActivated_Statics::PropPointers), 
sizeof(JMObjectiveWidgetBase_eventOnObjectiveActivated_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveActivated_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveActivated_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMObjectiveWidgetBase_eventOnObjectiveActivated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveActivated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveActivated_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UJMObjectiveWidgetBase Function OnObjectiveActivated ***********************

// ********** Begin Class UJMObjectiveWidgetBase Function OnObjectiveAdded *************************
struct JMObjectiveWidgetBase_eventOnObjectiveAdded_Parms
{
	FJMObjectiveRuntimeState InRuntimeState;
};
static FName NAME_UJMObjectiveWidgetBase_OnObjectiveAdded = FName(TEXT("OnObjectiveAdded"));
void UJMObjectiveWidgetBase::OnObjectiveAdded(FJMObjectiveRuntimeState const& InRuntimeState)
{
	JMObjectiveWidgetBase_eventOnObjectiveAdded_Parms Parms;
	Parms.InRuntimeState=InRuntimeState;
	UFunction* Func = FindFunctionChecked(NAME_UJMObjectiveWidgetBase_OnObjectiveAdded);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveAdded_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective|UI" },
		{ "ModuleRelativePath", "Public/UI/JMObjectiveWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InRuntimeState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnObjectiveAdded constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InRuntimeState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnObjectiveAdded constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnObjectiveAdded Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveAdded_Statics::NewProp_InRuntimeState = { "InRuntimeState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveWidgetBase_eventOnObjectiveAdded_Parms, InRuntimeState), Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InRuntimeState_MetaData), NewProp_InRuntimeState_MetaData) }; // 4088304728
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveAdded_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveAdded_Statics::NewProp_InRuntimeState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveAdded_Statics::PropPointers) < 2048);
// ********** End Function OnObjectiveAdded Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveAdded_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveWidgetBase, nullptr, "OnObjectiveAdded", 	Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveAdded_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveAdded_Statics::PropPointers), 
sizeof(JMObjectiveWidgetBase_eventOnObjectiveAdded_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveAdded_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveAdded_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMObjectiveWidgetBase_eventOnObjectiveAdded_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveAdded()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveAdded_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UJMObjectiveWidgetBase Function OnObjectiveAdded ***************************

// ********** Begin Class UJMObjectiveWidgetBase Function OnObjectiveCompleted *********************
struct JMObjectiveWidgetBase_eventOnObjectiveCompleted_Parms
{
	FJMObjectiveRuntimeState InRuntimeState;
};
static FName NAME_UJMObjectiveWidgetBase_OnObjectiveCompleted = FName(TEXT("OnObjectiveCompleted"));
void UJMObjectiveWidgetBase::OnObjectiveCompleted(FJMObjectiveRuntimeState const& InRuntimeState)
{
	JMObjectiveWidgetBase_eventOnObjectiveCompleted_Parms Parms;
	Parms.InRuntimeState=InRuntimeState;
	UFunction* Func = FindFunctionChecked(NAME_UJMObjectiveWidgetBase_OnObjectiveCompleted);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveCompleted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective|UI" },
		{ "ModuleRelativePath", "Public/UI/JMObjectiveWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InRuntimeState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnObjectiveCompleted constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InRuntimeState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnObjectiveCompleted constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnObjectiveCompleted Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveCompleted_Statics::NewProp_InRuntimeState = { "InRuntimeState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveWidgetBase_eventOnObjectiveCompleted_Parms, InRuntimeState), Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InRuntimeState_MetaData), NewProp_InRuntimeState_MetaData) }; // 4088304728
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveCompleted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveCompleted_Statics::NewProp_InRuntimeState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveCompleted_Statics::PropPointers) < 2048);
// ********** End Function OnObjectiveCompleted Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveCompleted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveWidgetBase, nullptr, "OnObjectiveCompleted", 	Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveCompleted_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveCompleted_Statics::PropPointers), 
sizeof(JMObjectiveWidgetBase_eventOnObjectiveCompleted_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveCompleted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMObjectiveWidgetBase_eventOnObjectiveCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UJMObjectiveWidgetBase Function OnObjectiveCompleted ***********************

// ********** Begin Class UJMObjectiveWidgetBase Function OnObjectiveFailed ************************
struct JMObjectiveWidgetBase_eventOnObjectiveFailed_Parms
{
	FJMObjectiveRuntimeState InRuntimeState;
};
static FName NAME_UJMObjectiveWidgetBase_OnObjectiveFailed = FName(TEXT("OnObjectiveFailed"));
void UJMObjectiveWidgetBase::OnObjectiveFailed(FJMObjectiveRuntimeState const& InRuntimeState)
{
	JMObjectiveWidgetBase_eventOnObjectiveFailed_Parms Parms;
	Parms.InRuntimeState=InRuntimeState;
	UFunction* Func = FindFunctionChecked(NAME_UJMObjectiveWidgetBase_OnObjectiveFailed);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveFailed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective|UI" },
		{ "ModuleRelativePath", "Public/UI/JMObjectiveWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InRuntimeState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnObjectiveFailed constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InRuntimeState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnObjectiveFailed constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnObjectiveFailed Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveFailed_Statics::NewProp_InRuntimeState = { "InRuntimeState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveWidgetBase_eventOnObjectiveFailed_Parms, InRuntimeState), Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InRuntimeState_MetaData), NewProp_InRuntimeState_MetaData) }; // 4088304728
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveFailed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveFailed_Statics::NewProp_InRuntimeState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveFailed_Statics::PropPointers) < 2048);
// ********** End Function OnObjectiveFailed Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveFailed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveWidgetBase, nullptr, "OnObjectiveFailed", 	Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveFailed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveFailed_Statics::PropPointers), 
sizeof(JMObjectiveWidgetBase_eventOnObjectiveFailed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveFailed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveFailed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMObjectiveWidgetBase_eventOnObjectiveFailed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveFailed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveFailed_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UJMObjectiveWidgetBase Function OnObjectiveFailed **************************

// ********** Begin Class UJMObjectiveWidgetBase Function OnObjectiveProgressChanged ***************
struct JMObjectiveWidgetBase_eventOnObjectiveProgressChanged_Parms
{
	FJMObjectiveRuntimeState InRuntimeState;
};
static FName NAME_UJMObjectiveWidgetBase_OnObjectiveProgressChanged = FName(TEXT("OnObjectiveProgressChanged"));
void UJMObjectiveWidgetBase::OnObjectiveProgressChanged(FJMObjectiveRuntimeState const& InRuntimeState)
{
	JMObjectiveWidgetBase_eventOnObjectiveProgressChanged_Parms Parms;
	Parms.InRuntimeState=InRuntimeState;
	UFunction* Func = FindFunctionChecked(NAME_UJMObjectiveWidgetBase_OnObjectiveProgressChanged);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveProgressChanged_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective|UI" },
		{ "ModuleRelativePath", "Public/UI/JMObjectiveWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InRuntimeState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnObjectiveProgressChanged constinit property declarations ************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InRuntimeState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnObjectiveProgressChanged constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnObjectiveProgressChanged Property Definitions ***********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveProgressChanged_Statics::NewProp_InRuntimeState = { "InRuntimeState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveWidgetBase_eventOnObjectiveProgressChanged_Parms, InRuntimeState), Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InRuntimeState_MetaData), NewProp_InRuntimeState_MetaData) }; // 4088304728
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveProgressChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveProgressChanged_Statics::NewProp_InRuntimeState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveProgressChanged_Statics::PropPointers) < 2048);
// ********** End Function OnObjectiveProgressChanged Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveProgressChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveWidgetBase, nullptr, "OnObjectiveProgressChanged", 	Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveProgressChanged_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveProgressChanged_Statics::PropPointers), 
sizeof(JMObjectiveWidgetBase_eventOnObjectiveProgressChanged_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveProgressChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveProgressChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMObjectiveWidgetBase_eventOnObjectiveProgressChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveProgressChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveProgressChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UJMObjectiveWidgetBase Function OnObjectiveProgressChanged *****************

// ********** Begin Class UJMObjectiveWidgetBase Function OnObjectiveRemoved ***********************
struct JMObjectiveWidgetBase_eventOnObjectiveRemoved_Parms
{
	FGameplayTag ObjectiveId;
};
static FName NAME_UJMObjectiveWidgetBase_OnObjectiveRemoved = FName(TEXT("OnObjectiveRemoved"));
void UJMObjectiveWidgetBase::OnObjectiveRemoved(FGameplayTag ObjectiveId)
{
	JMObjectiveWidgetBase_eventOnObjectiveRemoved_Parms Parms;
	Parms.ObjectiveId=ObjectiveId;
	UFunction* Func = FindFunctionChecked(NAME_UJMObjectiveWidgetBase_OnObjectiveRemoved);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveRemoved_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective|UI" },
		{ "ModuleRelativePath", "Public/UI/JMObjectiveWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnObjectiveRemoved constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnObjectiveRemoved constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnObjectiveRemoved Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveRemoved_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveWidgetBase_eventOnObjectiveRemoved_Parms, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveRemoved_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveRemoved_Statics::NewProp_ObjectiveId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveRemoved_Statics::PropPointers) < 2048);
// ********** End Function OnObjectiveRemoved Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveRemoved_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveWidgetBase, nullptr, "OnObjectiveRemoved", 	Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveRemoved_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveRemoved_Statics::PropPointers), 
sizeof(JMObjectiveWidgetBase_eventOnObjectiveRemoved_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveRemoved_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveRemoved_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMObjectiveWidgetBase_eventOnObjectiveRemoved_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveRemoved()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveRemoved_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UJMObjectiveWidgetBase Function OnObjectiveRemoved *************************

// ********** Begin Class UJMObjectiveWidgetBase Function SetObjectiveState ************************
struct Z_Construct_UFunction_UJMObjectiveWidgetBase_SetObjectiveState_Statics
{
	struct JMObjectiveWidgetBase_eventSetObjectiveState_Parms
	{
		FJMObjectiveRuntimeState InRuntimeState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective|UI" },
		{ "ModuleRelativePath", "Public/UI/JMObjectiveWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InRuntimeState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetObjectiveState constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InRuntimeState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetObjectiveState constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetObjectiveState Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMObjectiveWidgetBase_SetObjectiveState_Statics::NewProp_InRuntimeState = { "InRuntimeState", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveWidgetBase_eventSetObjectiveState_Parms, InRuntimeState), Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InRuntimeState_MetaData), NewProp_InRuntimeState_MetaData) }; // 4088304728
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveWidgetBase_SetObjectiveState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveWidgetBase_SetObjectiveState_Statics::NewProp_InRuntimeState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_SetObjectiveState_Statics::PropPointers) < 2048);
// ********** End Function SetObjectiveState Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveWidgetBase_SetObjectiveState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveWidgetBase, nullptr, "SetObjectiveState", 	Z_Construct_UFunction_UJMObjectiveWidgetBase_SetObjectiveState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_SetObjectiveState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveWidgetBase_SetObjectiveState_Statics::JMObjectiveWidgetBase_eventSetObjectiveState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveWidgetBase_SetObjectiveState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveWidgetBase_SetObjectiveState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveWidgetBase_SetObjectiveState_Statics::JMObjectiveWidgetBase_eventSetObjectiveState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveWidgetBase_SetObjectiveState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveWidgetBase_SetObjectiveState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveWidgetBase::execSetObjectiveState)
{
	P_GET_STRUCT_REF(FJMObjectiveRuntimeState,Z_Param_Out_InRuntimeState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetObjectiveState(Z_Param_Out_InRuntimeState);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveWidgetBase Function SetObjectiveState **************************

// ********** Begin Class UJMObjectiveWidgetBase ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMObjectiveWidgetBase;
UClass* UJMObjectiveWidgetBase::GetPrivateStaticClass()
{
	using TClass = UJMObjectiveWidgetBase;
	if (!Z_Registration_Info_UClass_UJMObjectiveWidgetBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMObjectiveWidgetBase"),
			Z_Registration_Info_UClass_UJMObjectiveWidgetBase.InnerSingleton,
			StaticRegisterNativesUJMObjectiveWidgetBase,
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
	return Z_Registration_Info_UClass_UJMObjectiveWidgetBase.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMObjectiveWidgetBase_NoRegister()
{
	return UJMObjectiveWidgetBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMObjectiveWidgetBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "UI/JMObjectiveWidgetBase.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/UI/JMObjectiveWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RuntimeState_MetaData[] = {
		{ "Category", "JM Objective|UI" },
		{ "ModuleRelativePath", "Public/UI/JMObjectiveWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectiveNameText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "JMObjectiveWidgetBase" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/JMObjectiveWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectiveDescriptionText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "JMObjectiveWidgetBase" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/JMObjectiveWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectiveProgressText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "JMObjectiveWidgetBase" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/JMObjectiveWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectiveStateText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "JMObjectiveWidgetBase" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/JMObjectiveWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMObjectiveWidgetBase constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_RuntimeState;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ObjectiveNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ObjectiveDescriptionText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ObjectiveProgressText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ObjectiveStateText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMObjectiveWidgetBase constinit property declarations *********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetObjectiveState"), .Pointer = &UJMObjectiveWidgetBase::execGetObjectiveState },
		{ .NameUTF8 = UTF8TEXT("SetObjectiveState"), .Pointer = &UJMObjectiveWidgetBase::execSetObjectiveState },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMObjectiveWidgetBase_GetObjectiveState, "GetObjectiveState" }, // 2905488745
		{ &Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveActivated, "OnObjectiveActivated" }, // 3111943669
		{ &Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveAdded, "OnObjectiveAdded" }, // 4188384826
		{ &Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveCompleted, "OnObjectiveCompleted" }, // 1712705060
		{ &Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveFailed, "OnObjectiveFailed" }, // 4155976372
		{ &Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveProgressChanged, "OnObjectiveProgressChanged" }, // 2217550251
		{ &Z_Construct_UFunction_UJMObjectiveWidgetBase_OnObjectiveRemoved, "OnObjectiveRemoved" }, // 1309919892
		{ &Z_Construct_UFunction_UJMObjectiveWidgetBase_SetObjectiveState, "SetObjectiveState" }, // 793800740
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMObjectiveWidgetBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMObjectiveWidgetBase_Statics

// ********** Begin Class UJMObjectiveWidgetBase Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMObjectiveWidgetBase_Statics::NewProp_RuntimeState = { "RuntimeState", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveWidgetBase, RuntimeState), Z_Construct_UScriptStruct_FJMObjectiveRuntimeState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RuntimeState_MetaData), NewProp_RuntimeState_MetaData) }; // 4088304728
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMObjectiveWidgetBase_Statics::NewProp_ObjectiveNameText = { "ObjectiveNameText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveWidgetBase, ObjectiveNameText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectiveNameText_MetaData), NewProp_ObjectiveNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMObjectiveWidgetBase_Statics::NewProp_ObjectiveDescriptionText = { "ObjectiveDescriptionText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveWidgetBase, ObjectiveDescriptionText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectiveDescriptionText_MetaData), NewProp_ObjectiveDescriptionText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMObjectiveWidgetBase_Statics::NewProp_ObjectiveProgressText = { "ObjectiveProgressText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveWidgetBase, ObjectiveProgressText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectiveProgressText_MetaData), NewProp_ObjectiveProgressText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMObjectiveWidgetBase_Statics::NewProp_ObjectiveStateText = { "ObjectiveStateText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveWidgetBase, ObjectiveStateText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectiveStateText_MetaData), NewProp_ObjectiveStateText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMObjectiveWidgetBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveWidgetBase_Statics::NewProp_RuntimeState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveWidgetBase_Statics::NewProp_ObjectiveNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveWidgetBase_Statics::NewProp_ObjectiveDescriptionText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveWidgetBase_Statics::NewProp_ObjectiveProgressText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveWidgetBase_Statics::NewProp_ObjectiveStateText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveWidgetBase_Statics::PropPointers) < 2048);
// ********** End Class UJMObjectiveWidgetBase Property Definitions ********************************
UObject* (*const Z_Construct_UClass_UJMObjectiveWidgetBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_JMObjective,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveWidgetBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMObjectiveWidgetBase_Statics::ClassParams = {
	&UJMObjectiveWidgetBase::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMObjectiveWidgetBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveWidgetBase_Statics::PropPointers),
	0,
	0x00B010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveWidgetBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMObjectiveWidgetBase_Statics::Class_MetaDataParams)
};
void UJMObjectiveWidgetBase::StaticRegisterNativesUJMObjectiveWidgetBase()
{
	UClass* Class = UJMObjectiveWidgetBase::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMObjectiveWidgetBase_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMObjectiveWidgetBase()
{
	if (!Z_Registration_Info_UClass_UJMObjectiveWidgetBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMObjectiveWidgetBase.OuterSingleton, Z_Construct_UClass_UJMObjectiveWidgetBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMObjectiveWidgetBase.OuterSingleton;
}
UJMObjectiveWidgetBase::UJMObjectiveWidgetBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMObjectiveWidgetBase);
UJMObjectiveWidgetBase::~UJMObjectiveWidgetBase() {}
// ********** End Class UJMObjectiveWidgetBase *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_UI_JMObjectiveWidgetBase_h__Script_JMObjective_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMObjectiveWidgetBase, UJMObjectiveWidgetBase::StaticClass, TEXT("UJMObjectiveWidgetBase"), &Z_Registration_Info_UClass_UJMObjectiveWidgetBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMObjectiveWidgetBase), 714251112U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_UI_JMObjectiveWidgetBase_h__Script_JMObjective_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_UI_JMObjectiveWidgetBase_h__Script_JMObjective_226690796{
	TEXT("/Script/JMObjective"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_UI_JMObjectiveWidgetBase_h__Script_JMObjective_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_UI_JMObjectiveWidgetBase_h__Script_JMObjective_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
