// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JMThrowableInteractorComponent.h"
#include "JMThrowableTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMThrowableInteractorComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPointLightComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USplineComponent_NoRegister();
JMTHROWABLE_API UClass* Z_Construct_UClass_UJMThrowableInteractorComponent();
JMTHROWABLE_API UClass* Z_Construct_UClass_UJMThrowableInteractorComponent_NoRegister();
JMTHROWABLE_API UEnum* Z_Construct_UEnum_JMThrowable_EJMThrowableUseState();
JMTHROWABLE_API UFunction* Z_Construct_UDelegateFunction_JMThrowable_JMThrowableStateChanged__DelegateSignature();
JMTHROWABLE_API UFunction* Z_Construct_UDelegateFunction_JMThrowable_JMThrowableThrowCompleted__DelegateSignature();
JMTHROWABLE_API UScriptStruct* Z_Construct_UScriptStruct_FJMThrowableUseContext();
JMTHROWABLE_API UScriptStruct* Z_Construct_UScriptStruct_FJMThrowResult();
JMTHROWABLE_API UScriptStruct* Z_Construct_UScriptStruct_FJMThrowSimulationResult();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraComponent_NoRegister();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMThrowable();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMThrowableInteractorComponent Function BeginAim ************************
struct Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginAim_Statics
{
	struct JMThrowableInteractorComponent_eventBeginAim_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Throwable" },
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function BeginAim constinit property declarations ******************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BeginAim constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BeginAim Property Definitions *****************************************
void Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginAim_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMThrowableInteractorComponent_eventBeginAim_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginAim_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMThrowableInteractorComponent_eventBeginAim_Parms), &Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginAim_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginAim_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginAim_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginAim_Statics::PropPointers) < 2048);
// ********** End Function BeginAim Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginAim_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMThrowableInteractorComponent, nullptr, "BeginAim", 	Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginAim_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginAim_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginAim_Statics::JMThrowableInteractorComponent_eventBeginAim_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginAim_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginAim_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginAim_Statics::JMThrowableInteractorComponent_eventBeginAim_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginAim()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginAim_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMThrowableInteractorComponent::execBeginAim)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->BeginAim();
	P_NATIVE_END;
}
// ********** End Class UJMThrowableInteractorComponent Function BeginAim **************************

// ********** Begin Class UJMThrowableInteractorComponent Function BeginItemUse ********************
struct Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginItemUse_Statics
{
	struct JMThrowableInteractorComponent_eventBeginItemUse_Parms
	{
		FJMThrowableUseContext Context;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Throwable" },
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function BeginItemUse constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BeginItemUse constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BeginItemUse Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginItemUse_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMThrowableInteractorComponent_eventBeginItemUse_Parms, Context), Z_Construct_UScriptStruct_FJMThrowableUseContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 2710774979
void Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginItemUse_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMThrowableInteractorComponent_eventBeginItemUse_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginItemUse_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMThrowableInteractorComponent_eventBeginItemUse_Parms), &Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginItemUse_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginItemUse_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginItemUse_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginItemUse_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginItemUse_Statics::PropPointers) < 2048);
// ********** End Function BeginItemUse Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginItemUse_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMThrowableInteractorComponent, nullptr, "BeginItemUse", 	Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginItemUse_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginItemUse_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginItemUse_Statics::JMThrowableInteractorComponent_eventBeginItemUse_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginItemUse_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginItemUse_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginItemUse_Statics::JMThrowableInteractorComponent_eventBeginItemUse_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginItemUse()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginItemUse_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMThrowableInteractorComponent::execBeginItemUse)
{
	P_GET_STRUCT_REF(FJMThrowableUseContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->BeginItemUse(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Class UJMThrowableInteractorComponent Function BeginItemUse **********************

// ********** Begin Class UJMThrowableInteractorComponent Function CancelItemUse *******************
struct Z_Construct_UFunction_UJMThrowableInteractorComponent_CancelItemUse_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Throwable" },
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CancelItemUse constinit property declarations *************************
// ********** End Function CancelItemUse constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMThrowableInteractorComponent_CancelItemUse_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMThrowableInteractorComponent, nullptr, "CancelItemUse", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableInteractorComponent_CancelItemUse_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMThrowableInteractorComponent_CancelItemUse_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UJMThrowableInteractorComponent_CancelItemUse()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMThrowableInteractorComponent_CancelItemUse_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMThrowableInteractorComponent::execCancelItemUse)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CancelItemUse();
	P_NATIVE_END;
}
// ********** End Class UJMThrowableInteractorComponent Function CancelItemUse *********************

// ********** Begin Class UJMThrowableInteractorComponent Function EndAim **************************
struct Z_Construct_UFunction_UJMThrowableInteractorComponent_EndAim_Statics
{
	struct JMThrowableInteractorComponent_eventEndAim_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Throwable" },
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function EndAim constinit property declarations ********************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function EndAim constinit property declarations **********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function EndAim Property Definitions *******************************************
void Z_Construct_UFunction_UJMThrowableInteractorComponent_EndAim_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMThrowableInteractorComponent_eventEndAim_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMThrowableInteractorComponent_EndAim_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMThrowableInteractorComponent_eventEndAim_Parms), &Z_Construct_UFunction_UJMThrowableInteractorComponent_EndAim_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMThrowableInteractorComponent_EndAim_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMThrowableInteractorComponent_EndAim_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableInteractorComponent_EndAim_Statics::PropPointers) < 2048);
// ********** End Function EndAim Property Definitions *********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMThrowableInteractorComponent_EndAim_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMThrowableInteractorComponent, nullptr, "EndAim", 	Z_Construct_UFunction_UJMThrowableInteractorComponent_EndAim_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableInteractorComponent_EndAim_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMThrowableInteractorComponent_EndAim_Statics::JMThrowableInteractorComponent_eventEndAim_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableInteractorComponent_EndAim_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMThrowableInteractorComponent_EndAim_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMThrowableInteractorComponent_EndAim_Statics::JMThrowableInteractorComponent_eventEndAim_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMThrowableInteractorComponent_EndAim()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMThrowableInteractorComponent_EndAim_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMThrowableInteractorComponent::execEndAim)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->EndAim();
	P_NATIVE_END;
}
// ********** End Class UJMThrowableInteractorComponent Function EndAim ****************************

// ********** Begin Class UJMThrowableInteractorComponent Function GetPreviewResult ****************
struct Z_Construct_UFunction_UJMThrowableInteractorComponent_GetPreviewResult_Statics
{
	struct JMThrowableInteractorComponent_eventGetPreviewResult_Parms
	{
		FJMThrowSimulationResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Throwable" },
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPreviewResult constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPreviewResult constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPreviewResult Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMThrowableInteractorComponent_GetPreviewResult_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMThrowableInteractorComponent_eventGetPreviewResult_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMThrowSimulationResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 727515007
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMThrowableInteractorComponent_GetPreviewResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMThrowableInteractorComponent_GetPreviewResult_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableInteractorComponent_GetPreviewResult_Statics::PropPointers) < 2048);
// ********** End Function GetPreviewResult Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMThrowableInteractorComponent_GetPreviewResult_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMThrowableInteractorComponent, nullptr, "GetPreviewResult", 	Z_Construct_UFunction_UJMThrowableInteractorComponent_GetPreviewResult_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableInteractorComponent_GetPreviewResult_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMThrowableInteractorComponent_GetPreviewResult_Statics::JMThrowableInteractorComponent_eventGetPreviewResult_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableInteractorComponent_GetPreviewResult_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMThrowableInteractorComponent_GetPreviewResult_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMThrowableInteractorComponent_GetPreviewResult_Statics::JMThrowableInteractorComponent_eventGetPreviewResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMThrowableInteractorComponent_GetPreviewResult()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMThrowableInteractorComponent_GetPreviewResult_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMThrowableInteractorComponent::execGetPreviewResult)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMThrowSimulationResult*)Z_Param__Result=P_THIS->GetPreviewResult();
	P_NATIVE_END;
}
// ********** End Class UJMThrowableInteractorComponent Function GetPreviewResult ******************

// ********** Begin Class UJMThrowableInteractorComponent Function GetSessionId ********************
struct Z_Construct_UFunction_UJMThrowableInteractorComponent_GetSessionId_Statics
{
	struct JMThrowableInteractorComponent_eventGetSessionId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Throwable" },
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSessionId constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSessionId constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSessionId Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMThrowableInteractorComponent_GetSessionId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMThrowableInteractorComponent_eventGetSessionId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMThrowableInteractorComponent_GetSessionId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMThrowableInteractorComponent_GetSessionId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableInteractorComponent_GetSessionId_Statics::PropPointers) < 2048);
// ********** End Function GetSessionId Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMThrowableInteractorComponent_GetSessionId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMThrowableInteractorComponent, nullptr, "GetSessionId", 	Z_Construct_UFunction_UJMThrowableInteractorComponent_GetSessionId_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableInteractorComponent_GetSessionId_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMThrowableInteractorComponent_GetSessionId_Statics::JMThrowableInteractorComponent_eventGetSessionId_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableInteractorComponent_GetSessionId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMThrowableInteractorComponent_GetSessionId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMThrowableInteractorComponent_GetSessionId_Statics::JMThrowableInteractorComponent_eventGetSessionId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMThrowableInteractorComponent_GetSessionId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMThrowableInteractorComponent_GetSessionId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMThrowableInteractorComponent::execGetSessionId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetSessionId();
	P_NATIVE_END;
}
// ********** End Class UJMThrowableInteractorComponent Function GetSessionId **********************

// ********** Begin Class UJMThrowableInteractorComponent Function GetUseState *********************
struct Z_Construct_UFunction_UJMThrowableInteractorComponent_GetUseState_Statics
{
	struct JMThrowableInteractorComponent_eventGetUseState_Parms
	{
		EJMThrowableUseState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Throwable" },
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetUseState constinit property declarations ***************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetUseState constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetUseState Property Definitions **************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMThrowableInteractorComponent_GetUseState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMThrowableInteractorComponent_GetUseState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMThrowableInteractorComponent_eventGetUseState_Parms, ReturnValue), Z_Construct_UEnum_JMThrowable_EJMThrowableUseState, METADATA_PARAMS(0, nullptr) }; // 755976728
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMThrowableInteractorComponent_GetUseState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMThrowableInteractorComponent_GetUseState_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMThrowableInteractorComponent_GetUseState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableInteractorComponent_GetUseState_Statics::PropPointers) < 2048);
// ********** End Function GetUseState Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMThrowableInteractorComponent_GetUseState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMThrowableInteractorComponent, nullptr, "GetUseState", 	Z_Construct_UFunction_UJMThrowableInteractorComponent_GetUseState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableInteractorComponent_GetUseState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMThrowableInteractorComponent_GetUseState_Statics::JMThrowableInteractorComponent_eventGetUseState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableInteractorComponent_GetUseState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMThrowableInteractorComponent_GetUseState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMThrowableInteractorComponent_GetUseState_Statics::JMThrowableInteractorComponent_eventGetUseState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMThrowableInteractorComponent_GetUseState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMThrowableInteractorComponent_GetUseState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMThrowableInteractorComponent::execGetUseState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EJMThrowableUseState*)Z_Param__Result=P_THIS->GetUseState();
	P_NATIVE_END;
}
// ********** End Class UJMThrowableInteractorComponent Function GetUseState ***********************

// ********** Begin Class UJMThrowableInteractorComponent Function TryCommitThrow ******************
struct Z_Construct_UFunction_UJMThrowableInteractorComponent_TryCommitThrow_Statics
{
	struct JMThrowableInteractorComponent_eventTryCommitThrow_Parms
	{
		FJMThrowResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Throwable" },
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function TryCommitThrow constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TryCommitThrow constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TryCommitThrow Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMThrowableInteractorComponent_TryCommitThrow_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMThrowableInteractorComponent_eventTryCommitThrow_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMThrowResult, METADATA_PARAMS(0, nullptr) }; // 1994527197
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMThrowableInteractorComponent_TryCommitThrow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMThrowableInteractorComponent_TryCommitThrow_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableInteractorComponent_TryCommitThrow_Statics::PropPointers) < 2048);
// ********** End Function TryCommitThrow Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMThrowableInteractorComponent_TryCommitThrow_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMThrowableInteractorComponent, nullptr, "TryCommitThrow", 	Z_Construct_UFunction_UJMThrowableInteractorComponent_TryCommitThrow_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableInteractorComponent_TryCommitThrow_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMThrowableInteractorComponent_TryCommitThrow_Statics::JMThrowableInteractorComponent_eventTryCommitThrow_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableInteractorComponent_TryCommitThrow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMThrowableInteractorComponent_TryCommitThrow_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMThrowableInteractorComponent_TryCommitThrow_Statics::JMThrowableInteractorComponent_eventTryCommitThrow_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMThrowableInteractorComponent_TryCommitThrow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMThrowableInteractorComponent_TryCommitThrow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMThrowableInteractorComponent::execTryCommitThrow)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMThrowResult*)Z_Param__Result=P_THIS->TryCommitThrow();
	P_NATIVE_END;
}
// ********** End Class UJMThrowableInteractorComponent Function TryCommitThrow ********************

// ********** Begin Class UJMThrowableInteractorComponent ******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMThrowableInteractorComponent;
UClass* UJMThrowableInteractorComponent::GetPrivateStaticClass()
{
	using TClass = UJMThrowableInteractorComponent;
	if (!Z_Registration_Info_UClass_UJMThrowableInteractorComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMThrowableInteractorComponent"),
			Z_Registration_Info_UClass_UJMThrowableInteractorComponent.InnerSingleton,
			StaticRegisterNativesUJMThrowableInteractorComponent,
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
	return Z_Registration_Info_UClass_UJMThrowableInteractorComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMThrowableInteractorComponent_NoRegister()
{
	return UJMThrowableInteractorComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMThrowableInteractorComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JM" },
		{ "IncludePath", "JMThrowableInteractorComponent.h" },
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnStateChanged_MetaData[] = {
		{ "Category", "JM Throwable" },
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnThrowCompleted_MetaData[] = {
		{ "Category", "JM Throwable" },
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UseState_MetaData[] = {
		{ "Category", "JMThrowableInteractorComponent" },
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveContext_MetaData[] = {
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewResult_MetaData[] = {
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewSpline_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewRibbon_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewFlowRibbon_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewFlowOrb_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewGlow_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewImpactMarker_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewNiagara_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedTrajectoryNiagaraSystem_MetaData[] = {
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedPreviewMaterial_MetaData[] = {
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewTrajectoryMID_MetaData[] = {
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewFlowMID_MetaData[] = {
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewOrbMID_MetaData[] = {
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewMarkerMID_MetaData[] = {
		{ "ModuleRelativePath", "Public/JMThrowableInteractorComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMThrowableInteractorComponent constinit property declarations **********
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStateChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnThrowCompleted;
	static const UECodeGen_Private::FBytePropertyParams NewProp_UseState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_UseState;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActiveContext;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PreviewResult;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewSpline;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewRibbon;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewFlowRibbon;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewFlowOrb;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewGlow;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewImpactMarker;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewNiagara;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CachedTrajectoryNiagaraSystem;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CachedPreviewMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewTrajectoryMID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewFlowMID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewOrbMID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewMarkerMID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMThrowableInteractorComponent constinit property declarations ************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("BeginAim"), .Pointer = &UJMThrowableInteractorComponent::execBeginAim },
		{ .NameUTF8 = UTF8TEXT("BeginItemUse"), .Pointer = &UJMThrowableInteractorComponent::execBeginItemUse },
		{ .NameUTF8 = UTF8TEXT("CancelItemUse"), .Pointer = &UJMThrowableInteractorComponent::execCancelItemUse },
		{ .NameUTF8 = UTF8TEXT("EndAim"), .Pointer = &UJMThrowableInteractorComponent::execEndAim },
		{ .NameUTF8 = UTF8TEXT("GetPreviewResult"), .Pointer = &UJMThrowableInteractorComponent::execGetPreviewResult },
		{ .NameUTF8 = UTF8TEXT("GetSessionId"), .Pointer = &UJMThrowableInteractorComponent::execGetSessionId },
		{ .NameUTF8 = UTF8TEXT("GetUseState"), .Pointer = &UJMThrowableInteractorComponent::execGetUseState },
		{ .NameUTF8 = UTF8TEXT("TryCommitThrow"), .Pointer = &UJMThrowableInteractorComponent::execTryCommitThrow },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginAim, "BeginAim" }, // 4204761521
		{ &Z_Construct_UFunction_UJMThrowableInteractorComponent_BeginItemUse, "BeginItemUse" }, // 1631835307
		{ &Z_Construct_UFunction_UJMThrowableInteractorComponent_CancelItemUse, "CancelItemUse" }, // 1542704208
		{ &Z_Construct_UFunction_UJMThrowableInteractorComponent_EndAim, "EndAim" }, // 3214124922
		{ &Z_Construct_UFunction_UJMThrowableInteractorComponent_GetPreviewResult, "GetPreviewResult" }, // 324628633
		{ &Z_Construct_UFunction_UJMThrowableInteractorComponent_GetSessionId, "GetSessionId" }, // 465231662
		{ &Z_Construct_UFunction_UJMThrowableInteractorComponent_GetUseState, "GetUseState" }, // 2468335118
		{ &Z_Construct_UFunction_UJMThrowableInteractorComponent_TryCommitThrow, "TryCommitThrow" }, // 2289481777
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMThrowableInteractorComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMThrowableInteractorComponent_Statics

// ********** Begin Class UJMThrowableInteractorComponent Property Definitions *********************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_OnStateChanged = { "OnStateChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableInteractorComponent, OnStateChanged), Z_Construct_UDelegateFunction_JMThrowable_JMThrowableStateChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnStateChanged_MetaData), NewProp_OnStateChanged_MetaData) }; // 890043779
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_OnThrowCompleted = { "OnThrowCompleted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableInteractorComponent, OnThrowCompleted), Z_Construct_UDelegateFunction_JMThrowable_JMThrowableThrowCompleted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnThrowCompleted_MetaData), NewProp_OnThrowCompleted_MetaData) }; // 3121567726
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_UseState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_UseState = { "UseState", nullptr, (EPropertyFlags)0x0040000000020801, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableInteractorComponent, UseState), Z_Construct_UEnum_JMThrowable_EJMThrowableUseState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UseState_MetaData), NewProp_UseState_MetaData) }; // 755976728
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_ActiveContext = { "ActiveContext", nullptr, (EPropertyFlags)0x0040008000002000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableInteractorComponent, ActiveContext), Z_Construct_UScriptStruct_FJMThrowableUseContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveContext_MetaData), NewProp_ActiveContext_MetaData) }; // 2710774979
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewResult = { "PreviewResult", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableInteractorComponent, PreviewResult), Z_Construct_UScriptStruct_FJMThrowSimulationResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewResult_MetaData), NewProp_PreviewResult_MetaData) }; // 727515007
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewSpline = { "PreviewSpline", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableInteractorComponent, PreviewSpline), Z_Construct_UClass_USplineComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewSpline_MetaData), NewProp_PreviewSpline_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewRibbon = { "PreviewRibbon", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableInteractorComponent, PreviewRibbon), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewRibbon_MetaData), NewProp_PreviewRibbon_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewFlowRibbon = { "PreviewFlowRibbon", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableInteractorComponent, PreviewFlowRibbon), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewFlowRibbon_MetaData), NewProp_PreviewFlowRibbon_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewFlowOrb = { "PreviewFlowOrb", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableInteractorComponent, PreviewFlowOrb), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewFlowOrb_MetaData), NewProp_PreviewFlowOrb_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewGlow = { "PreviewGlow", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableInteractorComponent, PreviewGlow), Z_Construct_UClass_UPointLightComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewGlow_MetaData), NewProp_PreviewGlow_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewImpactMarker = { "PreviewImpactMarker", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableInteractorComponent, PreviewImpactMarker), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewImpactMarker_MetaData), NewProp_PreviewImpactMarker_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewNiagara = { "PreviewNiagara", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableInteractorComponent, PreviewNiagara), Z_Construct_UClass_UNiagaraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewNiagara_MetaData), NewProp_PreviewNiagara_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_CachedTrajectoryNiagaraSystem = { "CachedTrajectoryNiagaraSystem", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableInteractorComponent, CachedTrajectoryNiagaraSystem), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedTrajectoryNiagaraSystem_MetaData), NewProp_CachedTrajectoryNiagaraSystem_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_CachedPreviewMaterial = { "CachedPreviewMaterial", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableInteractorComponent, CachedPreviewMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedPreviewMaterial_MetaData), NewProp_CachedPreviewMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewTrajectoryMID = { "PreviewTrajectoryMID", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableInteractorComponent, PreviewTrajectoryMID), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewTrajectoryMID_MetaData), NewProp_PreviewTrajectoryMID_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewFlowMID = { "PreviewFlowMID", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableInteractorComponent, PreviewFlowMID), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewFlowMID_MetaData), NewProp_PreviewFlowMID_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewOrbMID = { "PreviewOrbMID", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableInteractorComponent, PreviewOrbMID), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewOrbMID_MetaData), NewProp_PreviewOrbMID_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewMarkerMID = { "PreviewMarkerMID", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableInteractorComponent, PreviewMarkerMID), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewMarkerMID_MetaData), NewProp_PreviewMarkerMID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_OnStateChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_OnThrowCompleted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_UseState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_UseState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_ActiveContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewResult,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewSpline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewRibbon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewFlowRibbon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewFlowOrb,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewGlow,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewImpactMarker,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewNiagara,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_CachedTrajectoryNiagaraSystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_CachedPreviewMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewTrajectoryMID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewFlowMID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewOrbMID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::NewProp_PreviewMarkerMID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::PropPointers) < 2048);
// ********** End Class UJMThrowableInteractorComponent Property Definitions ***********************
UObject* (*const Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMThrowable,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::ClassParams = {
	&UJMThrowableInteractorComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::Class_MetaDataParams)
};
void UJMThrowableInteractorComponent::StaticRegisterNativesUJMThrowableInteractorComponent()
{
	UClass* Class = UJMThrowableInteractorComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMThrowableInteractorComponent()
{
	if (!Z_Registration_Info_UClass_UJMThrowableInteractorComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMThrowableInteractorComponent.OuterSingleton, Z_Construct_UClass_UJMThrowableInteractorComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMThrowableInteractorComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMThrowableInteractorComponent);
UJMThrowableInteractorComponent::~UJMThrowableInteractorComponent() {}
// ********** End Class UJMThrowableInteractorComponent ********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableInteractorComponent_h__Script_JMThrowable_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMThrowableInteractorComponent, UJMThrowableInteractorComponent::StaticClass, TEXT("UJMThrowableInteractorComponent"), &Z_Registration_Info_UClass_UJMThrowableInteractorComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMThrowableInteractorComponent), 4207495241U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableInteractorComponent_h__Script_JMThrowable_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableInteractorComponent_h__Script_JMThrowable_168789290{
	TEXT("/Script/JMThrowable"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableInteractorComponent_h__Script_JMThrowable_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableInteractorComponent_h__Script_JMThrowable_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
