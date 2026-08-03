// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DialogueSubsystem.h"
#include "Engine/GameInstance.h"
#include "ReusableDialogueTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDialogueSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAudioComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueSequence_NoRegister();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueSubsystem();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueSubsystem_NoRegister();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueWidgetBase_NoRegister();
REUSABLEDIALOGUESYSTEM_API UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EDialogueEndReason();
REUSABLEDIALOGUESYSTEM_API UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EDialogueInteractionMode();
REUSABLEDIALOGUESYSTEM_API UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EDialogueState();
REUSABLEDIALOGUESYSTEM_API UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EExistingDialoguePolicy();
REUSABLEDIALOGUESYSTEM_API UFunction* Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueEndedSignature__DelegateSignature();
REUSABLEDIALOGUESYSTEM_API UFunction* Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature();
REUSABLEDIALOGUESYSTEM_API UFunction* Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStartedSignature__DelegateSignature();
REUSABLEDIALOGUESYSTEM_API UFunction* Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature();
REUSABLEDIALOGUESYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueHistoryEntry();
REUSABLEDIALOGUESYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FDialogueLine();
UPackage* Z_Construct_UPackage__Script_ReusableDialogueSystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FDialogueStartedSignature *********************************************
struct Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStartedSignature__DelegateSignature_Statics
{
	struct _Script_ReusableDialogueSystem_eventDialogueStartedSignature_Parms
	{
		UDialogueSequence* Sequence;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDialogueStartedSignature constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Sequence;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDialogueStartedSignature constinit property declarations ***************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDialogueStartedSignature Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStartedSignature__DelegateSignature_Statics::NewProp_Sequence = { "Sequence", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ReusableDialogueSystem_eventDialogueStartedSignature_Parms, Sequence), Z_Construct_UClass_UDialogueSequence_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStartedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStartedSignature__DelegateSignature_Statics::NewProp_Sequence,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStartedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FDialogueStartedSignature Property Definitions **************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStartedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_ReusableDialogueSystem, nullptr, "DialogueStartedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStartedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStartedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStartedSignature__DelegateSignature_Statics::_Script_ReusableDialogueSystem_eventDialogueStartedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStartedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStartedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStartedSignature__DelegateSignature_Statics::_Script_ReusableDialogueSystem_eventDialogueStartedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStartedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStartedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FDialogueStartedSignature_DelegateWrapper(const FMulticastScriptDelegate& DialogueStartedSignature, UDialogueSequence* Sequence)
{
	struct _Script_ReusableDialogueSystem_eventDialogueStartedSignature_Parms
	{
		UDialogueSequence* Sequence;
	};
	_Script_ReusableDialogueSystem_eventDialogueStartedSignature_Parms Parms;
	Parms.Sequence=Sequence;
	DialogueStartedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FDialogueStartedSignature ***********************************************

// ********** Begin Delegate FDialogueStateChangedSignature ****************************************
struct Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature_Statics
{
	struct _Script_ReusableDialogueSystem_eventDialogueStateChangedSignature_Parms
	{
		EDialogueState PreviousState;
		EDialogueState NewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDialogueStateChangedSignature constinit property declarations ********
	static const UECodeGen_Private::FBytePropertyParams NewProp_PreviousState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_PreviousState;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDialogueStateChangedSignature constinit property declarations **********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDialogueStateChangedSignature Property Definitions *******************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature_Statics::NewProp_PreviousState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature_Statics::NewProp_PreviousState = { "PreviousState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ReusableDialogueSystem_eventDialogueStateChangedSignature_Parms, PreviousState), Z_Construct_UEnum_ReusableDialogueSystem_EDialogueState, METADATA_PARAMS(0, nullptr) }; // 657167223
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ReusableDialogueSystem_eventDialogueStateChangedSignature_Parms, NewState), Z_Construct_UEnum_ReusableDialogueSystem_EDialogueState, METADATA_PARAMS(0, nullptr) }; // 657167223
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature_Statics::NewProp_PreviousState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature_Statics::NewProp_PreviousState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature_Statics::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature_Statics::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FDialogueStateChangedSignature Property Definitions *********************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_ReusableDialogueSystem, nullptr, "DialogueStateChangedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature_Statics::_Script_ReusableDialogueSystem_eventDialogueStateChangedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature_Statics::_Script_ReusableDialogueSystem_eventDialogueStateChangedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FDialogueStateChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& DialogueStateChangedSignature, EDialogueState PreviousState, EDialogueState NewState)
{
	struct _Script_ReusableDialogueSystem_eventDialogueStateChangedSignature_Parms
	{
		EDialogueState PreviousState;
		EDialogueState NewState;
	};
	_Script_ReusableDialogueSystem_eventDialogueStateChangedSignature_Parms Parms;
	Parms.PreviousState=PreviousState;
	Parms.NewState=NewState;
	DialogueStateChangedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FDialogueStateChangedSignature ******************************************

// ********** Begin Delegate FDialogueLineSignature ************************************************
struct Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature_Statics
{
	struct _Script_ReusableDialogueSystem_eventDialogueLineSignature_Parms
	{
		UDialogueSequence* Sequence;
		FName LineId;
		int32 LineIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDialogueLineSignature constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Sequence;
	static const UECodeGen_Private::FNamePropertyParams NewProp_LineId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LineIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDialogueLineSignature constinit property declarations ******************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDialogueLineSignature Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature_Statics::NewProp_Sequence = { "Sequence", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ReusableDialogueSystem_eventDialogueLineSignature_Parms, Sequence), Z_Construct_UClass_UDialogueSequence_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature_Statics::NewProp_LineId = { "LineId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ReusableDialogueSystem_eventDialogueLineSignature_Parms, LineId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature_Statics::NewProp_LineIndex = { "LineIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ReusableDialogueSystem_eventDialogueLineSignature_Parms, LineIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature_Statics::NewProp_Sequence,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature_Statics::NewProp_LineId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature_Statics::NewProp_LineIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FDialogueLineSignature Property Definitions *****************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_ReusableDialogueSystem, nullptr, "DialogueLineSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature_Statics::_Script_ReusableDialogueSystem_eventDialogueLineSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature_Statics::_Script_ReusableDialogueSystem_eventDialogueLineSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FDialogueLineSignature_DelegateWrapper(const FMulticastScriptDelegate& DialogueLineSignature, UDialogueSequence* Sequence, FName LineId, int32 LineIndex)
{
	struct _Script_ReusableDialogueSystem_eventDialogueLineSignature_Parms
	{
		UDialogueSequence* Sequence;
		FName LineId;
		int32 LineIndex;
	};
	_Script_ReusableDialogueSystem_eventDialogueLineSignature_Parms Parms;
	Parms.Sequence=Sequence;
	Parms.LineId=LineId;
	Parms.LineIndex=LineIndex;
	DialogueLineSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FDialogueLineSignature **************************************************

// ********** Begin Delegate FDialogueEndedSignature ***********************************************
struct Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueEndedSignature__DelegateSignature_Statics
{
	struct _Script_ReusableDialogueSystem_eventDialogueEndedSignature_Parms
	{
		UDialogueSequence* Sequence;
		EDialogueEndReason Reason;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FDialogueEndedSignature constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Sequence;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Reason_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Reason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FDialogueEndedSignature constinit property declarations *****************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FDialogueEndedSignature Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueEndedSignature__DelegateSignature_Statics::NewProp_Sequence = { "Sequence", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ReusableDialogueSystem_eventDialogueEndedSignature_Parms, Sequence), Z_Construct_UClass_UDialogueSequence_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueEndedSignature__DelegateSignature_Statics::NewProp_Reason_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueEndedSignature__DelegateSignature_Statics::NewProp_Reason = { "Reason", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ReusableDialogueSystem_eventDialogueEndedSignature_Parms, Reason), Z_Construct_UEnum_ReusableDialogueSystem_EDialogueEndReason, METADATA_PARAMS(0, nullptr) }; // 3091157201
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueEndedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueEndedSignature__DelegateSignature_Statics::NewProp_Sequence,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueEndedSignature__DelegateSignature_Statics::NewProp_Reason_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueEndedSignature__DelegateSignature_Statics::NewProp_Reason,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueEndedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FDialogueEndedSignature Property Definitions ****************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueEndedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_ReusableDialogueSystem, nullptr, "DialogueEndedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueEndedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueEndedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueEndedSignature__DelegateSignature_Statics::_Script_ReusableDialogueSystem_eventDialogueEndedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueEndedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueEndedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueEndedSignature__DelegateSignature_Statics::_Script_ReusableDialogueSystem_eventDialogueEndedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueEndedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueEndedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FDialogueEndedSignature_DelegateWrapper(const FMulticastScriptDelegate& DialogueEndedSignature, UDialogueSequence* Sequence, EDialogueEndReason Reason)
{
	struct _Script_ReusableDialogueSystem_eventDialogueEndedSignature_Parms
	{
		UDialogueSequence* Sequence;
		EDialogueEndReason Reason;
	};
	_Script_ReusableDialogueSystem_eventDialogueEndedSignature_Parms Parms;
	Parms.Sequence=Sequence;
	Parms.Reason=Reason;
	DialogueEndedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FDialogueEndedSignature *************************************************

// ********** Begin Class UDialogueSubsystem Function AdvanceDialogue ******************************
struct Z_Construct_UFunction_UDialogueSubsystem_AdvanceDialogue_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AdvanceDialogue constinit property declarations ***********************
// ********** End Function AdvanceDialogue constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueSubsystem_AdvanceDialogue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueSubsystem, nullptr, "AdvanceDialogue", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_AdvanceDialogue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueSubsystem_AdvanceDialogue_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UDialogueSubsystem_AdvanceDialogue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueSubsystem_AdvanceDialogue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueSubsystem::execAdvanceDialogue)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AdvanceDialogue();
	P_NATIVE_END;
}
// ********** End Class UDialogueSubsystem Function AdvanceDialogue ********************************

// ********** Begin Class UDialogueSubsystem Function ClearDialogueHistory *************************
struct Z_Construct_UFunction_UDialogueSubsystem_ClearDialogueHistory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ClearDialogueHistory constinit property declarations ******************
// ********** End Function ClearDialogueHistory constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueSubsystem_ClearDialogueHistory_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueSubsystem, nullptr, "ClearDialogueHistory", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_ClearDialogueHistory_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueSubsystem_ClearDialogueHistory_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UDialogueSubsystem_ClearDialogueHistory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueSubsystem_ClearDialogueHistory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueSubsystem::execClearDialogueHistory)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearDialogueHistory();
	P_NATIVE_END;
}
// ********** End Class UDialogueSubsystem Function ClearDialogueHistory ***************************

// ********** Begin Class UDialogueSubsystem Function CompleteCurrentLine **************************
struct Z_Construct_UFunction_UDialogueSubsystem_CompleteCurrentLine_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CompleteCurrentLine constinit property declarations *******************
// ********** End Function CompleteCurrentLine constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueSubsystem_CompleteCurrentLine_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueSubsystem, nullptr, "CompleteCurrentLine", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_CompleteCurrentLine_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueSubsystem_CompleteCurrentLine_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UDialogueSubsystem_CompleteCurrentLine()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueSubsystem_CompleteCurrentLine_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueSubsystem::execCompleteCurrentLine)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CompleteCurrentLine();
	P_NATIVE_END;
}
// ********** End Class UDialogueSubsystem Function CompleteCurrentLine ****************************

// ********** Begin Class UDialogueSubsystem Function GetCurrentLine *******************************
struct Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLine_Statics
{
	struct DialogueSubsystem_eventGetCurrentLine_Parms
	{
		FDialogueLine ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentLine constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentLine constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentLine Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLine_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueSubsystem_eventGetCurrentLine_Parms, ReturnValue), Z_Construct_UScriptStruct_FDialogueLine, METADATA_PARAMS(0, nullptr) }; // 3166424386
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLine_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLine_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLine_Statics::PropPointers) < 2048);
// ********** End Function GetCurrentLine Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLine_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueSubsystem, nullptr, "GetCurrentLine", 	Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLine_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLine_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLine_Statics::DialogueSubsystem_eventGetCurrentLine_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLine_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLine_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLine_Statics::DialogueSubsystem_eventGetCurrentLine_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLine()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLine_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueSubsystem::execGetCurrentLine)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FDialogueLine*)Z_Param__Result=P_THIS->GetCurrentLine();
	P_NATIVE_END;
}
// ********** End Class UDialogueSubsystem Function GetCurrentLine *********************************

// ********** Begin Class UDialogueSubsystem Function GetCurrentLineIndex **************************
struct Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLineIndex_Statics
{
	struct DialogueSubsystem_eventGetCurrentLineIndex_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentLineIndex constinit property declarations *******************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentLineIndex constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentLineIndex Property Definitions ******************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLineIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueSubsystem_eventGetCurrentLineIndex_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLineIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLineIndex_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLineIndex_Statics::PropPointers) < 2048);
// ********** End Function GetCurrentLineIndex Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLineIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueSubsystem, nullptr, "GetCurrentLineIndex", 	Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLineIndex_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLineIndex_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLineIndex_Statics::DialogueSubsystem_eventGetCurrentLineIndex_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLineIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLineIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLineIndex_Statics::DialogueSubsystem_eventGetCurrentLineIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLineIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLineIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueSubsystem::execGetCurrentLineIndex)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetCurrentLineIndex();
	P_NATIVE_END;
}
// ********** End Class UDialogueSubsystem Function GetCurrentLineIndex ****************************

// ********** Begin Class UDialogueSubsystem Function GetCurrentSequence ***************************
struct Z_Construct_UFunction_UDialogueSubsystem_GetCurrentSequence_Statics
{
	struct DialogueSubsystem_eventGetCurrentSequence_Parms
	{
		UDialogueSequence* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentSequence constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentSequence constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentSequence Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDialogueSubsystem_GetCurrentSequence_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueSubsystem_eventGetCurrentSequence_Parms, ReturnValue), Z_Construct_UClass_UDialogueSequence_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueSubsystem_GetCurrentSequence_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueSubsystem_GetCurrentSequence_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_GetCurrentSequence_Statics::PropPointers) < 2048);
// ********** End Function GetCurrentSequence Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueSubsystem_GetCurrentSequence_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueSubsystem, nullptr, "GetCurrentSequence", 	Z_Construct_UFunction_UDialogueSubsystem_GetCurrentSequence_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_GetCurrentSequence_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDialogueSubsystem_GetCurrentSequence_Statics::DialogueSubsystem_eventGetCurrentSequence_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_GetCurrentSequence_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueSubsystem_GetCurrentSequence_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueSubsystem_GetCurrentSequence_Statics::DialogueSubsystem_eventGetCurrentSequence_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueSubsystem_GetCurrentSequence()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueSubsystem_GetCurrentSequence_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueSubsystem::execGetCurrentSequence)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UDialogueSequence**)Z_Param__Result=P_THIS->GetCurrentSequence();
	P_NATIVE_END;
}
// ********** End Class UDialogueSubsystem Function GetCurrentSequence *****************************

// ********** Begin Class UDialogueSubsystem Function GetDialogueHistory ***************************
struct Z_Construct_UFunction_UDialogueSubsystem_GetDialogueHistory_Statics
{
	struct DialogueSubsystem_eventGetDialogueHistory_Parms
	{
		TArray<FDialogueHistoryEntry> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDialogueHistory constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDialogueHistory constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDialogueHistory Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDialogueSubsystem_GetDialogueHistory_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDialogueHistoryEntry, METADATA_PARAMS(0, nullptr) }; // 695882414
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDialogueSubsystem_GetDialogueHistory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueSubsystem_eventGetDialogueHistory_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 695882414
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueSubsystem_GetDialogueHistory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueSubsystem_GetDialogueHistory_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueSubsystem_GetDialogueHistory_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_GetDialogueHistory_Statics::PropPointers) < 2048);
// ********** End Function GetDialogueHistory Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueSubsystem_GetDialogueHistory_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueSubsystem, nullptr, "GetDialogueHistory", 	Z_Construct_UFunction_UDialogueSubsystem_GetDialogueHistory_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_GetDialogueHistory_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDialogueSubsystem_GetDialogueHistory_Statics::DialogueSubsystem_eventGetDialogueHistory_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_GetDialogueHistory_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueSubsystem_GetDialogueHistory_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueSubsystem_GetDialogueHistory_Statics::DialogueSubsystem_eventGetDialogueHistory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueSubsystem_GetDialogueHistory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueSubsystem_GetDialogueHistory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueSubsystem::execGetDialogueHistory)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FDialogueHistoryEntry>*)Z_Param__Result=P_THIS->GetDialogueHistory();
	P_NATIVE_END;
}
// ********** End Class UDialogueSubsystem Function GetDialogueHistory *****************************

// ********** Begin Class UDialogueSubsystem Function GetDialogueState *****************************
struct Z_Construct_UFunction_UDialogueSubsystem_GetDialogueState_Statics
{
	struct DialogueSubsystem_eventGetDialogueState_Parms
	{
		EDialogueState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDialogueState constinit property declarations **********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDialogueState constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDialogueState Property Definitions *********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDialogueSubsystem_GetDialogueState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UDialogueSubsystem_GetDialogueState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueSubsystem_eventGetDialogueState_Parms, ReturnValue), Z_Construct_UEnum_ReusableDialogueSystem_EDialogueState, METADATA_PARAMS(0, nullptr) }; // 657167223
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueSubsystem_GetDialogueState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueSubsystem_GetDialogueState_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueSubsystem_GetDialogueState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_GetDialogueState_Statics::PropPointers) < 2048);
// ********** End Function GetDialogueState Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueSubsystem_GetDialogueState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueSubsystem, nullptr, "GetDialogueState", 	Z_Construct_UFunction_UDialogueSubsystem_GetDialogueState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_GetDialogueState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDialogueSubsystem_GetDialogueState_Statics::DialogueSubsystem_eventGetDialogueState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_GetDialogueState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueSubsystem_GetDialogueState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueSubsystem_GetDialogueState_Statics::DialogueSubsystem_eventGetDialogueState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueSubsystem_GetDialogueState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueSubsystem_GetDialogueState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueSubsystem::execGetDialogueState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EDialogueState*)Z_Param__Result=P_THIS->GetDialogueState();
	P_NATIVE_END;
}
// ********** End Class UDialogueSubsystem Function GetDialogueState *******************************

// ********** Begin Class UDialogueSubsystem Function IsDialogueActive *****************************
struct Z_Construct_UFunction_UDialogueSubsystem_IsDialogueActive_Statics
{
	struct DialogueSubsystem_eventIsDialogueActive_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsDialogueActive constinit property declarations **********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsDialogueActive constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsDialogueActive Property Definitions *********************************
void Z_Construct_UFunction_UDialogueSubsystem_IsDialogueActive_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((DialogueSubsystem_eventIsDialogueActive_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDialogueSubsystem_IsDialogueActive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DialogueSubsystem_eventIsDialogueActive_Parms), &Z_Construct_UFunction_UDialogueSubsystem_IsDialogueActive_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueSubsystem_IsDialogueActive_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueSubsystem_IsDialogueActive_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_IsDialogueActive_Statics::PropPointers) < 2048);
// ********** End Function IsDialogueActive Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueSubsystem_IsDialogueActive_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueSubsystem, nullptr, "IsDialogueActive", 	Z_Construct_UFunction_UDialogueSubsystem_IsDialogueActive_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_IsDialogueActive_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDialogueSubsystem_IsDialogueActive_Statics::DialogueSubsystem_eventIsDialogueActive_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_IsDialogueActive_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueSubsystem_IsDialogueActive_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueSubsystem_IsDialogueActive_Statics::DialogueSubsystem_eventIsDialogueActive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueSubsystem_IsDialogueActive()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueSubsystem_IsDialogueActive_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueSubsystem::execIsDialogueActive)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsDialogueActive();
	P_NATIVE_END;
}
// ********** End Class UDialogueSubsystem Function IsDialogueActive *******************************

// ********** Begin Class UDialogueSubsystem Function IsLineRevealing ******************************
struct Z_Construct_UFunction_UDialogueSubsystem_IsLineRevealing_Statics
{
	struct DialogueSubsystem_eventIsLineRevealing_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsLineRevealing constinit property declarations ***********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsLineRevealing constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsLineRevealing Property Definitions **********************************
void Z_Construct_UFunction_UDialogueSubsystem_IsLineRevealing_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((DialogueSubsystem_eventIsLineRevealing_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDialogueSubsystem_IsLineRevealing_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DialogueSubsystem_eventIsLineRevealing_Parms), &Z_Construct_UFunction_UDialogueSubsystem_IsLineRevealing_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueSubsystem_IsLineRevealing_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueSubsystem_IsLineRevealing_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_IsLineRevealing_Statics::PropPointers) < 2048);
// ********** End Function IsLineRevealing Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueSubsystem_IsLineRevealing_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueSubsystem, nullptr, "IsLineRevealing", 	Z_Construct_UFunction_UDialogueSubsystem_IsLineRevealing_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_IsLineRevealing_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDialogueSubsystem_IsLineRevealing_Statics::DialogueSubsystem_eventIsLineRevealing_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_IsLineRevealing_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueSubsystem_IsLineRevealing_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueSubsystem_IsLineRevealing_Statics::DialogueSubsystem_eventIsLineRevealing_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueSubsystem_IsLineRevealing()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueSubsystem_IsLineRevealing_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueSubsystem::execIsLineRevealing)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsLineRevealing();
	P_NATIVE_END;
}
// ********** End Class UDialogueSubsystem Function IsLineRevealing ********************************

// ********** Begin Class UDialogueSubsystem Function PauseDialogue ********************************
struct Z_Construct_UFunction_UDialogueSubsystem_PauseDialogue_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function PauseDialogue constinit property declarations *************************
// ********** End Function PauseDialogue constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueSubsystem_PauseDialogue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueSubsystem, nullptr, "PauseDialogue", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_PauseDialogue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueSubsystem_PauseDialogue_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UDialogueSubsystem_PauseDialogue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueSubsystem_PauseDialogue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueSubsystem::execPauseDialogue)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PauseDialogue();
	P_NATIVE_END;
}
// ********** End Class UDialogueSubsystem Function PauseDialogue **********************************

// ********** Begin Class UDialogueSubsystem Function ResumeDialogue *******************************
struct Z_Construct_UFunction_UDialogueSubsystem_ResumeDialogue_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResumeDialogue constinit property declarations ************************
// ********** End Function ResumeDialogue constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueSubsystem_ResumeDialogue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueSubsystem, nullptr, "ResumeDialogue", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_ResumeDialogue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueSubsystem_ResumeDialogue_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UDialogueSubsystem_ResumeDialogue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueSubsystem_ResumeDialogue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueSubsystem::execResumeDialogue)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResumeDialogue();
	P_NATIVE_END;
}
// ********** End Class UDialogueSubsystem Function ResumeDialogue *********************************

// ********** Begin Class UDialogueSubsystem Function StartDialogue ********************************
struct Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics
{
	struct DialogueSubsystem_eventStartDialogue_Parms
	{
		UDialogueSequence* Sequence;
		EDialogueInteractionMode InteractionMode;
		APlayerController* PlayerController;
		EExistingDialoguePolicy ExistingPolicy;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue" },
		{ "CPP_Default_ExistingPolicy", "Reject" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function StartDialogue constinit property declarations *************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Sequence;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InteractionMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InteractionMode;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ExistingPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ExistingPolicy;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function StartDialogue constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function StartDialogue Property Definitions ************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::NewProp_Sequence = { "Sequence", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueSubsystem_eventStartDialogue_Parms, Sequence), Z_Construct_UClass_UDialogueSequence_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::NewProp_InteractionMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::NewProp_InteractionMode = { "InteractionMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueSubsystem_eventStartDialogue_Parms, InteractionMode), Z_Construct_UEnum_ReusableDialogueSystem_EDialogueInteractionMode, METADATA_PARAMS(0, nullptr) }; // 3853692148
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueSubsystem_eventStartDialogue_Parms, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::NewProp_ExistingPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::NewProp_ExistingPolicy = { "ExistingPolicy", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DialogueSubsystem_eventStartDialogue_Parms, ExistingPolicy), Z_Construct_UEnum_ReusableDialogueSystem_EExistingDialoguePolicy, METADATA_PARAMS(0, nullptr) }; // 3634757249
void Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((DialogueSubsystem_eventStartDialogue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DialogueSubsystem_eventStartDialogue_Parms), &Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::NewProp_Sequence,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::NewProp_InteractionMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::NewProp_InteractionMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::NewProp_PlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::NewProp_ExistingPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::NewProp_ExistingPolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::PropPointers) < 2048);
// ********** End Function StartDialogue Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueSubsystem, nullptr, "StartDialogue", 	Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::DialogueSubsystem_eventStartDialogue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::DialogueSubsystem_eventStartDialogue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDialogueSubsystem_StartDialogue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueSubsystem_StartDialogue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueSubsystem::execStartDialogue)
{
	P_GET_OBJECT(UDialogueSequence,Z_Param_Sequence);
	P_GET_ENUM(EDialogueInteractionMode,Z_Param_InteractionMode);
	P_GET_OBJECT(APlayerController,Z_Param_PlayerController);
	P_GET_ENUM(EExistingDialoguePolicy,Z_Param_ExistingPolicy);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->StartDialogue(Z_Param_Sequence,EDialogueInteractionMode(Z_Param_InteractionMode),Z_Param_PlayerController,EExistingDialoguePolicy(Z_Param_ExistingPolicy));
	P_NATIVE_END;
}
// ********** End Class UDialogueSubsystem Function StartDialogue **********************************

// ********** Begin Class UDialogueSubsystem Function StopDialogue *********************************
struct Z_Construct_UFunction_UDialogueSubsystem_StopDialogue_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function StopDialogue constinit property declarations **************************
// ********** End Function StopDialogue constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDialogueSubsystem_StopDialogue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDialogueSubsystem, nullptr, "StopDialogue", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDialogueSubsystem_StopDialogue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDialogueSubsystem_StopDialogue_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UDialogueSubsystem_StopDialogue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDialogueSubsystem_StopDialogue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDialogueSubsystem::execStopDialogue)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopDialogue();
	P_NATIVE_END;
}
// ********** End Class UDialogueSubsystem Function StopDialogue ***********************************

// ********** Begin Class UDialogueSubsystem *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueSubsystem;
UClass* UDialogueSubsystem::GetPrivateStaticClass()
{
	using TClass = UDialogueSubsystem;
	if (!Z_Registration_Info_UClass_UDialogueSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DialogueSubsystem"),
			Z_Registration_Info_UClass_UDialogueSubsystem.InnerSingleton,
			StaticRegisterNativesUDialogueSubsystem,
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
	return Z_Registration_Info_UClass_UDialogueSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueSubsystem_NoRegister()
{
	return UDialogueSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DialogueSubsystem.h" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDialogueStarted_MetaData[] = {
		{ "Category", "Dialogue|Events" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDialogueStateChanged_MetaData[] = {
		{ "Category", "Dialogue|Events" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnLineStarted_MetaData[] = {
		{ "Category", "Dialogue|Events" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnLineRevealCompleted_MetaData[] = {
		{ "Category", "Dialogue|Events" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnLineAdvanced_MetaData[] = {
		{ "Category", "Dialogue|Events" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDialogueFinished_MetaData[] = {
		{ "Category", "Dialogue|Events" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDialogueCancelled_MetaData[] = {
		{ "Category", "Dialogue|Events" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentSequence_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogueWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OwningPlayerController_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextAudioComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VoiceAudioComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogueHistory_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_State_MetaData[] = {
		{ "ModuleRelativePath", "Public/DialogueSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDialogueSubsystem constinit property declarations ***********************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDialogueStarted;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDialogueStateChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnLineStarted;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnLineRevealCompleted;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnLineAdvanced;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDialogueFinished;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDialogueCancelled;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentSequence;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DialogueWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OwningPlayerController;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TextAudioComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VoiceAudioComponent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DialogueHistory_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DialogueHistory;
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDialogueSubsystem constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AdvanceDialogue"), .Pointer = &UDialogueSubsystem::execAdvanceDialogue },
		{ .NameUTF8 = UTF8TEXT("ClearDialogueHistory"), .Pointer = &UDialogueSubsystem::execClearDialogueHistory },
		{ .NameUTF8 = UTF8TEXT("CompleteCurrentLine"), .Pointer = &UDialogueSubsystem::execCompleteCurrentLine },
		{ .NameUTF8 = UTF8TEXT("GetCurrentLine"), .Pointer = &UDialogueSubsystem::execGetCurrentLine },
		{ .NameUTF8 = UTF8TEXT("GetCurrentLineIndex"), .Pointer = &UDialogueSubsystem::execGetCurrentLineIndex },
		{ .NameUTF8 = UTF8TEXT("GetCurrentSequence"), .Pointer = &UDialogueSubsystem::execGetCurrentSequence },
		{ .NameUTF8 = UTF8TEXT("GetDialogueHistory"), .Pointer = &UDialogueSubsystem::execGetDialogueHistory },
		{ .NameUTF8 = UTF8TEXT("GetDialogueState"), .Pointer = &UDialogueSubsystem::execGetDialogueState },
		{ .NameUTF8 = UTF8TEXT("IsDialogueActive"), .Pointer = &UDialogueSubsystem::execIsDialogueActive },
		{ .NameUTF8 = UTF8TEXT("IsLineRevealing"), .Pointer = &UDialogueSubsystem::execIsLineRevealing },
		{ .NameUTF8 = UTF8TEXT("PauseDialogue"), .Pointer = &UDialogueSubsystem::execPauseDialogue },
		{ .NameUTF8 = UTF8TEXT("ResumeDialogue"), .Pointer = &UDialogueSubsystem::execResumeDialogue },
		{ .NameUTF8 = UTF8TEXT("StartDialogue"), .Pointer = &UDialogueSubsystem::execStartDialogue },
		{ .NameUTF8 = UTF8TEXT("StopDialogue"), .Pointer = &UDialogueSubsystem::execStopDialogue },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDialogueSubsystem_AdvanceDialogue, "AdvanceDialogue" }, // 4025159541
		{ &Z_Construct_UFunction_UDialogueSubsystem_ClearDialogueHistory, "ClearDialogueHistory" }, // 3826147214
		{ &Z_Construct_UFunction_UDialogueSubsystem_CompleteCurrentLine, "CompleteCurrentLine" }, // 2229512301
		{ &Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLine, "GetCurrentLine" }, // 2290149823
		{ &Z_Construct_UFunction_UDialogueSubsystem_GetCurrentLineIndex, "GetCurrentLineIndex" }, // 2228142697
		{ &Z_Construct_UFunction_UDialogueSubsystem_GetCurrentSequence, "GetCurrentSequence" }, // 871977368
		{ &Z_Construct_UFunction_UDialogueSubsystem_GetDialogueHistory, "GetDialogueHistory" }, // 3984053517
		{ &Z_Construct_UFunction_UDialogueSubsystem_GetDialogueState, "GetDialogueState" }, // 881035566
		{ &Z_Construct_UFunction_UDialogueSubsystem_IsDialogueActive, "IsDialogueActive" }, // 2561151070
		{ &Z_Construct_UFunction_UDialogueSubsystem_IsLineRevealing, "IsLineRevealing" }, // 4222194500
		{ &Z_Construct_UFunction_UDialogueSubsystem_PauseDialogue, "PauseDialogue" }, // 2344839088
		{ &Z_Construct_UFunction_UDialogueSubsystem_ResumeDialogue, "ResumeDialogue" }, // 1531715045
		{ &Z_Construct_UFunction_UDialogueSubsystem_StartDialogue, "StartDialogue" }, // 1258169402
		{ &Z_Construct_UFunction_UDialogueSubsystem_StopDialogue, "StopDialogue" }, // 3984092640
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDialogueSubsystem_Statics

// ********** Begin Class UDialogueSubsystem Property Definitions **********************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_OnDialogueStarted = { "OnDialogueStarted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSubsystem, OnDialogueStarted), Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStartedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDialogueStarted_MetaData), NewProp_OnDialogueStarted_MetaData) }; // 578565876
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_OnDialogueStateChanged = { "OnDialogueStateChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSubsystem, OnDialogueStateChanged), Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDialogueStateChanged_MetaData), NewProp_OnDialogueStateChanged_MetaData) }; // 4165921064
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_OnLineStarted = { "OnLineStarted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSubsystem, OnLineStarted), Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnLineStarted_MetaData), NewProp_OnLineStarted_MetaData) }; // 2323744129
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_OnLineRevealCompleted = { "OnLineRevealCompleted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSubsystem, OnLineRevealCompleted), Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnLineRevealCompleted_MetaData), NewProp_OnLineRevealCompleted_MetaData) }; // 2323744129
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_OnLineAdvanced = { "OnLineAdvanced", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSubsystem, OnLineAdvanced), Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnLineAdvanced_MetaData), NewProp_OnLineAdvanced_MetaData) }; // 2323744129
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_OnDialogueFinished = { "OnDialogueFinished", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSubsystem, OnDialogueFinished), Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueEndedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDialogueFinished_MetaData), NewProp_OnDialogueFinished_MetaData) }; // 1217320984
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_OnDialogueCancelled = { "OnDialogueCancelled", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSubsystem, OnDialogueCancelled), Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueEndedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDialogueCancelled_MetaData), NewProp_OnDialogueCancelled_MetaData) }; // 1217320984
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_CurrentSequence = { "CurrentSequence", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSubsystem, CurrentSequence), Z_Construct_UClass_UDialogueSequence_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentSequence_MetaData), NewProp_CurrentSequence_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_DialogueWidget = { "DialogueWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSubsystem, DialogueWidget), Z_Construct_UClass_UDialogueWidgetBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogueWidget_MetaData), NewProp_DialogueWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_OwningPlayerController = { "OwningPlayerController", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSubsystem, OwningPlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OwningPlayerController_MetaData), NewProp_OwningPlayerController_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_TextAudioComponent = { "TextAudioComponent", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSubsystem, TextAudioComponent), Z_Construct_UClass_UAudioComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextAudioComponent_MetaData), NewProp_TextAudioComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_VoiceAudioComponent = { "VoiceAudioComponent", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSubsystem, VoiceAudioComponent), Z_Construct_UClass_UAudioComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VoiceAudioComponent_MetaData), NewProp_VoiceAudioComponent_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_DialogueHistory_Inner = { "DialogueHistory", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDialogueHistoryEntry, METADATA_PARAMS(0, nullptr) }; // 695882414
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_DialogueHistory = { "DialogueHistory", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSubsystem, DialogueHistory), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogueHistory_MetaData), NewProp_DialogueHistory_MetaData) }; // 695882414
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueSubsystem, State), Z_Construct_UEnum_ReusableDialogueSystem_EDialogueState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_State_MetaData), NewProp_State_MetaData) }; // 657167223
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_OnDialogueStarted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_OnDialogueStateChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_OnLineStarted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_OnLineRevealCompleted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_OnLineAdvanced,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_OnDialogueFinished,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_OnDialogueCancelled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_CurrentSequence,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_DialogueWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_OwningPlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_TextAudioComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_VoiceAudioComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_DialogueHistory_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_DialogueHistory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueSubsystem_Statics::NewProp_State,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueSubsystem_Statics::PropPointers) < 2048);
// ********** End Class UDialogueSubsystem Property Definitions ************************************
UObject* (*const Z_Construct_UClass_UDialogueSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_ReusableDialogueSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueSubsystem_Statics::ClassParams = {
	&UDialogueSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UDialogueSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueSubsystem_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueSubsystem_Statics::Class_MetaDataParams)
};
void UDialogueSubsystem::StaticRegisterNativesUDialogueSubsystem()
{
	UClass* Class = UDialogueSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UDialogueSubsystem_Statics::Funcs));
}
UClass* Z_Construct_UClass_UDialogueSubsystem()
{
	if (!Z_Registration_Info_UClass_UDialogueSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueSubsystem.OuterSingleton, Z_Construct_UClass_UDialogueSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueSubsystem.OuterSingleton;
}
UDialogueSubsystem::UDialogueSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDialogueSubsystem);
UDialogueSubsystem::~UDialogueSubsystem() {}
// ********** End Class UDialogueSubsystem *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSubsystem_h__Script_ReusableDialogueSystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueSubsystem, UDialogueSubsystem::StaticClass, TEXT("UDialogueSubsystem"), &Z_Registration_Info_UClass_UDialogueSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueSubsystem), 1291804472U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSubsystem_h__Script_ReusableDialogueSystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSubsystem_h__Script_ReusableDialogueSystem_3849461426{
	TEXT("/Script/ReusableDialogueSystem"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSubsystem_h__Script_ReusableDialogueSystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_DialogueSubsystem_h__Script_ReusableDialogueSystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
