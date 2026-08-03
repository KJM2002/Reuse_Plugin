// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ItemInspection/JMItemInspectionSubsystem.h"
#include "Engine/LocalPlayer.h"
#include "ItemInspection/JMItemInspectionTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMItemInspectionSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ULocalPlayerSubsystem();
ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_AJMItemInspectionPreviewActor_NoRegister();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMItemInspectionData_NoRegister();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMItemInspectionSubsystem();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMItemInspectionSubsystem_NoRegister();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMItemInspectionTransitionWidget_NoRegister();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMItemInspectionWidgetBase_NoRegister();
ITEMINSPECTORRUNTIME_API UEnum* Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionCloseReason();
ITEMINSPECTORRUNTIME_API UEnum* Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionState();
ITEMINSPECTORRUNTIME_API UFunction* Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionClosedSignature__DelegateSignature();
ITEMINSPECTORRUNTIME_API UFunction* Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionFailedSignature__DelegateSignature();
ITEMINSPECTORRUNTIME_API UFunction* Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionOpenedSignature__DelegateSignature();
ITEMINSPECTORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMItemInspectionRequest();
UPackage* Z_Construct_UPackage__Script_ItemInspectorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FJMItemInspectionOpenedSignature **************************************
struct Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionOpenedSignature__DelegateSignature_Statics
{
	struct _Script_ItemInspectorRuntime_eventJMItemInspectionOpenedSignature_Parms
	{
		UJMItemInspectionData* InspectionData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMItemInspectionOpenedSignature constinit property declarations ******
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InspectionData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMItemInspectionOpenedSignature constinit property declarations ********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMItemInspectionOpenedSignature Property Definitions *****************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionOpenedSignature__DelegateSignature_Statics::NewProp_InspectionData = { "InspectionData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ItemInspectorRuntime_eventJMItemInspectionOpenedSignature_Parms, InspectionData), Z_Construct_UClass_UJMItemInspectionData_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionOpenedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionOpenedSignature__DelegateSignature_Statics::NewProp_InspectionData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionOpenedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMItemInspectionOpenedSignature Property Definitions *******************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionOpenedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_ItemInspectorRuntime, nullptr, "JMItemInspectionOpenedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionOpenedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionOpenedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionOpenedSignature__DelegateSignature_Statics::_Script_ItemInspectorRuntime_eventJMItemInspectionOpenedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionOpenedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionOpenedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionOpenedSignature__DelegateSignature_Statics::_Script_ItemInspectorRuntime_eventJMItemInspectionOpenedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionOpenedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionOpenedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMItemInspectionOpenedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMItemInspectionOpenedSignature, UJMItemInspectionData* InspectionData)
{
	struct _Script_ItemInspectorRuntime_eventJMItemInspectionOpenedSignature_Parms
	{
		UJMItemInspectionData* InspectionData;
	};
	_Script_ItemInspectorRuntime_eventJMItemInspectionOpenedSignature_Parms Parms;
	Parms.InspectionData=InspectionData;
	JMItemInspectionOpenedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMItemInspectionOpenedSignature ****************************************

// ********** Begin Delegate FJMItemInspectionClosedSignature **************************************
struct Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionClosedSignature__DelegateSignature_Statics
{
	struct _Script_ItemInspectorRuntime_eventJMItemInspectionClosedSignature_Parms
	{
		EJMItemInspectionCloseReason Reason;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMItemInspectionClosedSignature constinit property declarations ******
	static const UECodeGen_Private::FBytePropertyParams NewProp_Reason_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Reason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMItemInspectionClosedSignature constinit property declarations ********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMItemInspectionClosedSignature Property Definitions *****************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionClosedSignature__DelegateSignature_Statics::NewProp_Reason_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionClosedSignature__DelegateSignature_Statics::NewProp_Reason = { "Reason", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ItemInspectorRuntime_eventJMItemInspectionClosedSignature_Parms, Reason), Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionCloseReason, METADATA_PARAMS(0, nullptr) }; // 1865201677
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionClosedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionClosedSignature__DelegateSignature_Statics::NewProp_Reason_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionClosedSignature__DelegateSignature_Statics::NewProp_Reason,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionClosedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMItemInspectionClosedSignature Property Definitions *******************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionClosedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_ItemInspectorRuntime, nullptr, "JMItemInspectionClosedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionClosedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionClosedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionClosedSignature__DelegateSignature_Statics::_Script_ItemInspectorRuntime_eventJMItemInspectionClosedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionClosedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionClosedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionClosedSignature__DelegateSignature_Statics::_Script_ItemInspectorRuntime_eventJMItemInspectionClosedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionClosedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionClosedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMItemInspectionClosedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMItemInspectionClosedSignature, EJMItemInspectionCloseReason Reason)
{
	struct _Script_ItemInspectorRuntime_eventJMItemInspectionClosedSignature_Parms
	{
		EJMItemInspectionCloseReason Reason;
	};
	_Script_ItemInspectorRuntime_eventJMItemInspectionClosedSignature_Parms Parms;
	Parms.Reason=Reason;
	JMItemInspectionClosedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMItemInspectionClosedSignature ****************************************

// ********** Begin Delegate FJMItemInspectionFailedSignature **************************************
struct Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionFailedSignature__DelegateSignature_Statics
{
	struct _Script_ItemInspectorRuntime_eventJMItemInspectionFailedSignature_Parms
	{
		UJMItemInspectionData* InspectionData;
		FText Reason;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMItemInspectionFailedSignature constinit property declarations ******
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InspectionData;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Reason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMItemInspectionFailedSignature constinit property declarations ********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMItemInspectionFailedSignature Property Definitions *****************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionFailedSignature__DelegateSignature_Statics::NewProp_InspectionData = { "InspectionData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ItemInspectorRuntime_eventJMItemInspectionFailedSignature_Parms, InspectionData), Z_Construct_UClass_UJMItemInspectionData_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionFailedSignature__DelegateSignature_Statics::NewProp_Reason = { "Reason", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ItemInspectorRuntime_eventJMItemInspectionFailedSignature_Parms, Reason), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionFailedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionFailedSignature__DelegateSignature_Statics::NewProp_InspectionData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionFailedSignature__DelegateSignature_Statics::NewProp_Reason,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionFailedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMItemInspectionFailedSignature Property Definitions *******************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionFailedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_ItemInspectorRuntime, nullptr, "JMItemInspectionFailedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionFailedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionFailedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionFailedSignature__DelegateSignature_Statics::_Script_ItemInspectorRuntime_eventJMItemInspectionFailedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionFailedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionFailedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionFailedSignature__DelegateSignature_Statics::_Script_ItemInspectorRuntime_eventJMItemInspectionFailedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionFailedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionFailedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMItemInspectionFailedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMItemInspectionFailedSignature, UJMItemInspectionData* InspectionData, const FText& Reason)
{
	struct _Script_ItemInspectorRuntime_eventJMItemInspectionFailedSignature_Parms
	{
		UJMItemInspectionData* InspectionData;
		FText Reason;
	};
	_Script_ItemInspectorRuntime_eventJMItemInspectionFailedSignature_Parms Parms;
	Parms.InspectionData=InspectionData;
	Parms.Reason=Reason;
	JMItemInspectionFailedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMItemInspectionFailedSignature ****************************************

// ********** Begin Class UJMItemInspectionSubsystem Function CloseInspection **********************
struct Z_Construct_UFunction_UJMItemInspectionSubsystem_CloseInspection_Statics
{
	struct JMItemInspectionSubsystem_eventCloseInspection_Parms
	{
		EJMItemInspectionCloseReason Reason;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "CPP_Default_Reason", "ExternalRequest" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CloseInspection constinit property declarations ***********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Reason_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Reason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CloseInspection constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CloseInspection Property Definitions **********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMItemInspectionSubsystem_CloseInspection_Statics::NewProp_Reason_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMItemInspectionSubsystem_CloseInspection_Statics::NewProp_Reason = { "Reason", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionSubsystem_eventCloseInspection_Parms, Reason), Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionCloseReason, METADATA_PARAMS(0, nullptr) }; // 1865201677
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionSubsystem_CloseInspection_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionSubsystem_CloseInspection_Statics::NewProp_Reason_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionSubsystem_CloseInspection_Statics::NewProp_Reason,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_CloseInspection_Statics::PropPointers) < 2048);
// ********** End Function CloseInspection Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionSubsystem_CloseInspection_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionSubsystem, nullptr, "CloseInspection", 	Z_Construct_UFunction_UJMItemInspectionSubsystem_CloseInspection_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_CloseInspection_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMItemInspectionSubsystem_CloseInspection_Statics::JMItemInspectionSubsystem_eventCloseInspection_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_CloseInspection_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionSubsystem_CloseInspection_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMItemInspectionSubsystem_CloseInspection_Statics::JMItemInspectionSubsystem_eventCloseInspection_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionSubsystem_CloseInspection()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionSubsystem_CloseInspection_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMItemInspectionSubsystem::execCloseInspection)
{
	P_GET_ENUM(EJMItemInspectionCloseReason,Z_Param_Reason);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CloseInspection(EJMItemInspectionCloseReason(Z_Param_Reason));
	P_NATIVE_END;
}
// ********** End Class UJMItemInspectionSubsystem Function CloseInspection ************************

// ********** Begin Class UJMItemInspectionSubsystem Function GetCurrentInspectionData *************
struct Z_Construct_UFunction_UJMItemInspectionSubsystem_GetCurrentInspectionData_Statics
{
	struct JMItemInspectionSubsystem_eventGetCurrentInspectionData_Parms
	{
		UJMItemInspectionData* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentInspectionData constinit property declarations **************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentInspectionData constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentInspectionData Property Definitions *************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMItemInspectionSubsystem_GetCurrentInspectionData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionSubsystem_eventGetCurrentInspectionData_Parms, ReturnValue), Z_Construct_UClass_UJMItemInspectionData_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionSubsystem_GetCurrentInspectionData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionSubsystem_GetCurrentInspectionData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_GetCurrentInspectionData_Statics::PropPointers) < 2048);
// ********** End Function GetCurrentInspectionData Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionSubsystem_GetCurrentInspectionData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionSubsystem, nullptr, "GetCurrentInspectionData", 	Z_Construct_UFunction_UJMItemInspectionSubsystem_GetCurrentInspectionData_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_GetCurrentInspectionData_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMItemInspectionSubsystem_GetCurrentInspectionData_Statics::JMItemInspectionSubsystem_eventGetCurrentInspectionData_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_GetCurrentInspectionData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionSubsystem_GetCurrentInspectionData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMItemInspectionSubsystem_GetCurrentInspectionData_Statics::JMItemInspectionSubsystem_eventGetCurrentInspectionData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionSubsystem_GetCurrentInspectionData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionSubsystem_GetCurrentInspectionData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMItemInspectionSubsystem::execGetCurrentInspectionData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UJMItemInspectionData**)Z_Param__Result=P_THIS->GetCurrentInspectionData();
	P_NATIVE_END;
}
// ********** End Class UJMItemInspectionSubsystem Function GetCurrentInspectionData ***************

// ********** Begin Class UJMItemInspectionSubsystem Function GetInspectionState *******************
struct Z_Construct_UFunction_UJMItemInspectionSubsystem_GetInspectionState_Statics
{
	struct JMItemInspectionSubsystem_eventGetInspectionState_Parms
	{
		EJMItemInspectionState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetInspectionState constinit property declarations ********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetInspectionState constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetInspectionState Property Definitions *******************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMItemInspectionSubsystem_GetInspectionState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMItemInspectionSubsystem_GetInspectionState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionSubsystem_eventGetInspectionState_Parms, ReturnValue), Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionState, METADATA_PARAMS(0, nullptr) }; // 4115607530
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionSubsystem_GetInspectionState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionSubsystem_GetInspectionState_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionSubsystem_GetInspectionState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_GetInspectionState_Statics::PropPointers) < 2048);
// ********** End Function GetInspectionState Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionSubsystem_GetInspectionState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionSubsystem, nullptr, "GetInspectionState", 	Z_Construct_UFunction_UJMItemInspectionSubsystem_GetInspectionState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_GetInspectionState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMItemInspectionSubsystem_GetInspectionState_Statics::JMItemInspectionSubsystem_eventGetInspectionState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_GetInspectionState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionSubsystem_GetInspectionState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMItemInspectionSubsystem_GetInspectionState_Statics::JMItemInspectionSubsystem_eventGetInspectionState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionSubsystem_GetInspectionState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionSubsystem_GetInspectionState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMItemInspectionSubsystem::execGetInspectionState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EJMItemInspectionState*)Z_Param__Result=P_THIS->GetInspectionState();
	P_NATIVE_END;
}
// ********** End Class UJMItemInspectionSubsystem Function GetInspectionState *********************

// ********** Begin Class UJMItemInspectionSubsystem Function HandlePreviewDragged *****************
struct Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewDragged_Statics
{
	struct JMItemInspectionSubsystem_eventHandlePreviewDragged_Parms
	{
		float ScreenDeltaX;
		float ScreenDeltaY;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandlePreviewDragged constinit property declarations ******************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ScreenDeltaX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ScreenDeltaY;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandlePreviewDragged constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandlePreviewDragged Property Definitions *****************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewDragged_Statics::NewProp_ScreenDeltaX = { "ScreenDeltaX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionSubsystem_eventHandlePreviewDragged_Parms, ScreenDeltaX), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewDragged_Statics::NewProp_ScreenDeltaY = { "ScreenDeltaY", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionSubsystem_eventHandlePreviewDragged_Parms, ScreenDeltaY), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewDragged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewDragged_Statics::NewProp_ScreenDeltaX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewDragged_Statics::NewProp_ScreenDeltaY,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewDragged_Statics::PropPointers) < 2048);
// ********** End Function HandlePreviewDragged Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewDragged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionSubsystem, nullptr, "HandlePreviewDragged", 	Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewDragged_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewDragged_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewDragged_Statics::JMItemInspectionSubsystem_eventHandlePreviewDragged_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewDragged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewDragged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewDragged_Statics::JMItemInspectionSubsystem_eventHandlePreviewDragged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewDragged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewDragged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMItemInspectionSubsystem::execHandlePreviewDragged)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_ScreenDeltaX);
	P_GET_PROPERTY(FFloatProperty,Z_Param_ScreenDeltaY);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandlePreviewDragged(Z_Param_ScreenDeltaX,Z_Param_ScreenDeltaY);
	P_NATIVE_END;
}
// ********** End Class UJMItemInspectionSubsystem Function HandlePreviewDragged *******************

// ********** Begin Class UJMItemInspectionSubsystem Function HandlePreviewZoomed ******************
struct Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewZoomed_Statics
{
	struct JMItemInspectionSubsystem_eventHandlePreviewZoomed_Parms
	{
		float WheelDelta;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandlePreviewZoomed constinit property declarations *******************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WheelDelta;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandlePreviewZoomed constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandlePreviewZoomed Property Definitions ******************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewZoomed_Statics::NewProp_WheelDelta = { "WheelDelta", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionSubsystem_eventHandlePreviewZoomed_Parms, WheelDelta), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewZoomed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewZoomed_Statics::NewProp_WheelDelta,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewZoomed_Statics::PropPointers) < 2048);
// ********** End Function HandlePreviewZoomed Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewZoomed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionSubsystem, nullptr, "HandlePreviewZoomed", 	Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewZoomed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewZoomed_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewZoomed_Statics::JMItemInspectionSubsystem_eventHandlePreviewZoomed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewZoomed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewZoomed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewZoomed_Statics::JMItemInspectionSubsystem_eventHandlePreviewZoomed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewZoomed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewZoomed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMItemInspectionSubsystem::execHandlePreviewZoomed)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_WheelDelta);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandlePreviewZoomed(Z_Param_WheelDelta);
	P_NATIVE_END;
}
// ********** End Class UJMItemInspectionSubsystem Function HandlePreviewZoomed ********************

// ********** Begin Class UJMItemInspectionSubsystem Function HandleWidgetCloseRequested ***********
struct Z_Construct_UFunction_UJMItemInspectionSubsystem_HandleWidgetCloseRequested_Statics
{
	struct JMItemInspectionSubsystem_eventHandleWidgetCloseRequested_Parms
	{
		EJMItemInspectionCloseReason Reason;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleWidgetCloseRequested constinit property declarations ************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Reason_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Reason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleWidgetCloseRequested constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleWidgetCloseRequested Property Definitions ***********************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMItemInspectionSubsystem_HandleWidgetCloseRequested_Statics::NewProp_Reason_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMItemInspectionSubsystem_HandleWidgetCloseRequested_Statics::NewProp_Reason = { "Reason", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionSubsystem_eventHandleWidgetCloseRequested_Parms, Reason), Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionCloseReason, METADATA_PARAMS(0, nullptr) }; // 1865201677
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionSubsystem_HandleWidgetCloseRequested_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionSubsystem_HandleWidgetCloseRequested_Statics::NewProp_Reason_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionSubsystem_HandleWidgetCloseRequested_Statics::NewProp_Reason,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_HandleWidgetCloseRequested_Statics::PropPointers) < 2048);
// ********** End Function HandleWidgetCloseRequested Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionSubsystem_HandleWidgetCloseRequested_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionSubsystem, nullptr, "HandleWidgetCloseRequested", 	Z_Construct_UFunction_UJMItemInspectionSubsystem_HandleWidgetCloseRequested_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_HandleWidgetCloseRequested_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMItemInspectionSubsystem_HandleWidgetCloseRequested_Statics::JMItemInspectionSubsystem_eventHandleWidgetCloseRequested_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_HandleWidgetCloseRequested_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionSubsystem_HandleWidgetCloseRequested_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMItemInspectionSubsystem_HandleWidgetCloseRequested_Statics::JMItemInspectionSubsystem_eventHandleWidgetCloseRequested_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionSubsystem_HandleWidgetCloseRequested()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionSubsystem_HandleWidgetCloseRequested_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMItemInspectionSubsystem::execHandleWidgetCloseRequested)
{
	P_GET_ENUM(EJMItemInspectionCloseReason,Z_Param_Reason);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleWidgetCloseRequested(EJMItemInspectionCloseReason(Z_Param_Reason));
	P_NATIVE_END;
}
// ********** End Class UJMItemInspectionSubsystem Function HandleWidgetCloseRequested *************

// ********** Begin Class UJMItemInspectionSubsystem Function IsInspectionOpen *********************
struct Z_Construct_UFunction_UJMItemInspectionSubsystem_IsInspectionOpen_Statics
{
	struct JMItemInspectionSubsystem_eventIsInspectionOpen_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsInspectionOpen constinit property declarations **********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsInspectionOpen constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsInspectionOpen Property Definitions *********************************
void Z_Construct_UFunction_UJMItemInspectionSubsystem_IsInspectionOpen_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMItemInspectionSubsystem_eventIsInspectionOpen_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMItemInspectionSubsystem_IsInspectionOpen_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMItemInspectionSubsystem_eventIsInspectionOpen_Parms), &Z_Construct_UFunction_UJMItemInspectionSubsystem_IsInspectionOpen_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionSubsystem_IsInspectionOpen_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionSubsystem_IsInspectionOpen_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_IsInspectionOpen_Statics::PropPointers) < 2048);
// ********** End Function IsInspectionOpen Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionSubsystem_IsInspectionOpen_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionSubsystem, nullptr, "IsInspectionOpen", 	Z_Construct_UFunction_UJMItemInspectionSubsystem_IsInspectionOpen_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_IsInspectionOpen_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMItemInspectionSubsystem_IsInspectionOpen_Statics::JMItemInspectionSubsystem_eventIsInspectionOpen_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_IsInspectionOpen_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionSubsystem_IsInspectionOpen_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMItemInspectionSubsystem_IsInspectionOpen_Statics::JMItemInspectionSubsystem_eventIsInspectionOpen_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionSubsystem_IsInspectionOpen()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionSubsystem_IsInspectionOpen_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMItemInspectionSubsystem::execIsInspectionOpen)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsInspectionOpen();
	P_NATIVE_END;
}
// ********** End Class UJMItemInspectionSubsystem Function IsInspectionOpen ***********************

// ********** Begin Class UJMItemInspectionSubsystem Function OpenInspection ***********************
struct Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspection_Statics
{
	struct JMItemInspectionSubsystem_eventOpenInspection_Parms
	{
		UJMItemInspectionData* InspectionData;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OpenInspection constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InspectionData;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OpenInspection constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OpenInspection Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspection_Statics::NewProp_InspectionData = { "InspectionData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionSubsystem_eventOpenInspection_Parms, InspectionData), Z_Construct_UClass_UJMItemInspectionData_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspection_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMItemInspectionSubsystem_eventOpenInspection_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspection_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMItemInspectionSubsystem_eventOpenInspection_Parms), &Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspection_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspection_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspection_Statics::NewProp_InspectionData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspection_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspection_Statics::PropPointers) < 2048);
// ********** End Function OpenInspection Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspection_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionSubsystem, nullptr, "OpenInspection", 	Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspection_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspection_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspection_Statics::JMItemInspectionSubsystem_eventOpenInspection_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspection_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspection_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspection_Statics::JMItemInspectionSubsystem_eventOpenInspection_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspection()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspection_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMItemInspectionSubsystem::execOpenInspection)
{
	P_GET_OBJECT(UJMItemInspectionData,Z_Param_InspectionData);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->OpenInspection(Z_Param_InspectionData);
	P_NATIVE_END;
}
// ********** End Class UJMItemInspectionSubsystem Function OpenInspection *************************

// ********** Begin Class UJMItemInspectionSubsystem Function OpenInspectionFromRequest ************
struct Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspectionFromRequest_Statics
{
	struct JMItemInspectionSubsystem_eventOpenInspectionFromRequest_Parms
	{
		FJMItemInspectionRequest Request;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Request_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OpenInspectionFromRequest constinit property declarations *************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Request;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OpenInspectionFromRequest constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OpenInspectionFromRequest Property Definitions ************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspectionFromRequest_Statics::NewProp_Request = { "Request", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionSubsystem_eventOpenInspectionFromRequest_Parms, Request), Z_Construct_UScriptStruct_FJMItemInspectionRequest, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Request_MetaData), NewProp_Request_MetaData) }; // 417983221
void Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspectionFromRequest_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMItemInspectionSubsystem_eventOpenInspectionFromRequest_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspectionFromRequest_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMItemInspectionSubsystem_eventOpenInspectionFromRequest_Parms), &Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspectionFromRequest_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspectionFromRequest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspectionFromRequest_Statics::NewProp_Request,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspectionFromRequest_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspectionFromRequest_Statics::PropPointers) < 2048);
// ********** End Function OpenInspectionFromRequest Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspectionFromRequest_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionSubsystem, nullptr, "OpenInspectionFromRequest", 	Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspectionFromRequest_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspectionFromRequest_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspectionFromRequest_Statics::JMItemInspectionSubsystem_eventOpenInspectionFromRequest_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspectionFromRequest_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspectionFromRequest_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspectionFromRequest_Statics::JMItemInspectionSubsystem_eventOpenInspectionFromRequest_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspectionFromRequest()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspectionFromRequest_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMItemInspectionSubsystem::execOpenInspectionFromRequest)
{
	P_GET_STRUCT_REF(FJMItemInspectionRequest,Z_Param_Out_Request);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->OpenInspectionFromRequest(Z_Param_Out_Request);
	P_NATIVE_END;
}
// ********** End Class UJMItemInspectionSubsystem Function OpenInspectionFromRequest **************

// ********** Begin Class UJMItemInspectionSubsystem Function ResetPreviewRotation *****************
struct Z_Construct_UFunction_UJMItemInspectionSubsystem_ResetPreviewRotation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResetPreviewRotation constinit property declarations ******************
// ********** End Function ResetPreviewRotation constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionSubsystem_ResetPreviewRotation_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionSubsystem, nullptr, "ResetPreviewRotation", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSubsystem_ResetPreviewRotation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionSubsystem_ResetPreviewRotation_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UJMItemInspectionSubsystem_ResetPreviewRotation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionSubsystem_ResetPreviewRotation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMItemInspectionSubsystem::execResetPreviewRotation)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetPreviewRotation();
	P_NATIVE_END;
}
// ********** End Class UJMItemInspectionSubsystem Function ResetPreviewRotation *******************

// ********** Begin Class UJMItemInspectionSubsystem ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMItemInspectionSubsystem;
UClass* UJMItemInspectionSubsystem::GetPrivateStaticClass()
{
	using TClass = UJMItemInspectionSubsystem;
	if (!Z_Registration_Info_UClass_UJMItemInspectionSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMItemInspectionSubsystem"),
			Z_Registration_Info_UClass_UJMItemInspectionSubsystem.InnerSingleton,
			StaticRegisterNativesUJMItemInspectionSubsystem,
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
	return Z_Registration_Info_UClass_UJMItemInspectionSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMItemInspectionSubsystem_NoRegister()
{
	return UJMItemInspectionSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMItemInspectionSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "ItemInspection/JMItemInspectionSubsystem.h" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnInspectionOpened_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnInspectionClosed_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnInspectionFailed_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_State_MetaData[] = {
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentInspectionData_MetaData[] = {
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentTransitionWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HiddenSourceActor_MetaData[] = {
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentPreviewRenderTarget_MetaData[] = {
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentPreviewActor_MetaData[] = {
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMItemInspectionSubsystem constinit property declarations ***************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInspectionOpened;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInspectionClosed;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInspectionFailed;
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentInspectionData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentTransitionWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HiddenSourceActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentPreviewRenderTarget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentPreviewActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMItemInspectionSubsystem constinit property declarations *****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CloseInspection"), .Pointer = &UJMItemInspectionSubsystem::execCloseInspection },
		{ .NameUTF8 = UTF8TEXT("GetCurrentInspectionData"), .Pointer = &UJMItemInspectionSubsystem::execGetCurrentInspectionData },
		{ .NameUTF8 = UTF8TEXT("GetInspectionState"), .Pointer = &UJMItemInspectionSubsystem::execGetInspectionState },
		{ .NameUTF8 = UTF8TEXT("HandlePreviewDragged"), .Pointer = &UJMItemInspectionSubsystem::execHandlePreviewDragged },
		{ .NameUTF8 = UTF8TEXT("HandlePreviewZoomed"), .Pointer = &UJMItemInspectionSubsystem::execHandlePreviewZoomed },
		{ .NameUTF8 = UTF8TEXT("HandleWidgetCloseRequested"), .Pointer = &UJMItemInspectionSubsystem::execHandleWidgetCloseRequested },
		{ .NameUTF8 = UTF8TEXT("IsInspectionOpen"), .Pointer = &UJMItemInspectionSubsystem::execIsInspectionOpen },
		{ .NameUTF8 = UTF8TEXT("OpenInspection"), .Pointer = &UJMItemInspectionSubsystem::execOpenInspection },
		{ .NameUTF8 = UTF8TEXT("OpenInspectionFromRequest"), .Pointer = &UJMItemInspectionSubsystem::execOpenInspectionFromRequest },
		{ .NameUTF8 = UTF8TEXT("ResetPreviewRotation"), .Pointer = &UJMItemInspectionSubsystem::execResetPreviewRotation },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMItemInspectionSubsystem_CloseInspection, "CloseInspection" }, // 2043025025
		{ &Z_Construct_UFunction_UJMItemInspectionSubsystem_GetCurrentInspectionData, "GetCurrentInspectionData" }, // 3128328657
		{ &Z_Construct_UFunction_UJMItemInspectionSubsystem_GetInspectionState, "GetInspectionState" }, // 282010944
		{ &Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewDragged, "HandlePreviewDragged" }, // 3349987621
		{ &Z_Construct_UFunction_UJMItemInspectionSubsystem_HandlePreviewZoomed, "HandlePreviewZoomed" }, // 245159854
		{ &Z_Construct_UFunction_UJMItemInspectionSubsystem_HandleWidgetCloseRequested, "HandleWidgetCloseRequested" }, // 2152057901
		{ &Z_Construct_UFunction_UJMItemInspectionSubsystem_IsInspectionOpen, "IsInspectionOpen" }, // 3242110843
		{ &Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspection, "OpenInspection" }, // 2536837891
		{ &Z_Construct_UFunction_UJMItemInspectionSubsystem_OpenInspectionFromRequest, "OpenInspectionFromRequest" }, // 555175455
		{ &Z_Construct_UFunction_UJMItemInspectionSubsystem_ResetPreviewRotation, "ResetPreviewRotation" }, // 2984840782
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMItemInspectionSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMItemInspectionSubsystem_Statics

// ********** Begin Class UJMItemInspectionSubsystem Property Definitions **************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::NewProp_OnInspectionOpened = { "OnInspectionOpened", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionSubsystem, OnInspectionOpened), Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionOpenedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnInspectionOpened_MetaData), NewProp_OnInspectionOpened_MetaData) }; // 790994600
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::NewProp_OnInspectionClosed = { "OnInspectionClosed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionSubsystem, OnInspectionClosed), Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionClosedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnInspectionClosed_MetaData), NewProp_OnInspectionClosed_MetaData) }; // 2196814118
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::NewProp_OnInspectionFailed = { "OnInspectionFailed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionSubsystem, OnInspectionFailed), Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionFailedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnInspectionFailed_MetaData), NewProp_OnInspectionFailed_MetaData) }; // 287945434
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0020080000002000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionSubsystem, State), Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_State_MetaData), NewProp_State_MetaData) }; // 4115607530
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::NewProp_CurrentInspectionData = { "CurrentInspectionData", nullptr, (EPropertyFlags)0x0124080000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionSubsystem, CurrentInspectionData), Z_Construct_UClass_UJMItemInspectionData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentInspectionData_MetaData), NewProp_CurrentInspectionData_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::NewProp_CurrentWidget = { "CurrentWidget", nullptr, (EPropertyFlags)0x0124080000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionSubsystem, CurrentWidget), Z_Construct_UClass_UJMItemInspectionWidgetBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentWidget_MetaData), NewProp_CurrentWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::NewProp_CurrentTransitionWidget = { "CurrentTransitionWidget", nullptr, (EPropertyFlags)0x0124080000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionSubsystem, CurrentTransitionWidget), Z_Construct_UClass_UJMItemInspectionTransitionWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentTransitionWidget_MetaData), NewProp_CurrentTransitionWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::NewProp_HiddenSourceActor = { "HiddenSourceActor", nullptr, (EPropertyFlags)0x0124080000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionSubsystem, HiddenSourceActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HiddenSourceActor_MetaData), NewProp_HiddenSourceActor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::NewProp_CurrentPreviewRenderTarget = { "CurrentPreviewRenderTarget", nullptr, (EPropertyFlags)0x0124080000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionSubsystem, CurrentPreviewRenderTarget), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentPreviewRenderTarget_MetaData), NewProp_CurrentPreviewRenderTarget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::NewProp_CurrentPreviewActor = { "CurrentPreviewActor", nullptr, (EPropertyFlags)0x0124080000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionSubsystem, CurrentPreviewActor), Z_Construct_UClass_AJMItemInspectionPreviewActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentPreviewActor_MetaData), NewProp_CurrentPreviewActor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::NewProp_OnInspectionOpened,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::NewProp_OnInspectionClosed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::NewProp_OnInspectionFailed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::NewProp_State,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::NewProp_CurrentInspectionData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::NewProp_CurrentWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::NewProp_CurrentTransitionWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::NewProp_HiddenSourceActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::NewProp_CurrentPreviewRenderTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::NewProp_CurrentPreviewActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::PropPointers) < 2048);
// ********** End Class UJMItemInspectionSubsystem Property Definitions ****************************
UObject* (*const Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ULocalPlayerSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_ItemInspectorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::ClassParams = {
	&UJMItemInspectionSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::Class_MetaDataParams)
};
void UJMItemInspectionSubsystem::StaticRegisterNativesUJMItemInspectionSubsystem()
{
	UClass* Class = UJMItemInspectionSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMItemInspectionSubsystem()
{
	if (!Z_Registration_Info_UClass_UJMItemInspectionSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMItemInspectionSubsystem.OuterSingleton, Z_Construct_UClass_UJMItemInspectionSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMItemInspectionSubsystem.OuterSingleton;
}
UJMItemInspectionSubsystem::UJMItemInspectionSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMItemInspectionSubsystem);
UJMItemInspectionSubsystem::~UJMItemInspectionSubsystem() {}
// ********** End Class UJMItemInspectionSubsystem *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionSubsystem_h__Script_ItemInspectorRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMItemInspectionSubsystem, UJMItemInspectionSubsystem::StaticClass, TEXT("UJMItemInspectionSubsystem"), &Z_Registration_Info_UClass_UJMItemInspectionSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMItemInspectionSubsystem), 2648657613U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionSubsystem_h__Script_ItemInspectorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionSubsystem_h__Script_ItemInspectorRuntime_1965440409{
	TEXT("/Script/ItemInspectorRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionSubsystem_h__Script_ItemInspectorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionSubsystem_h__Script_ItemInspectorRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
