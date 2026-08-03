// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interfaces/JMReconTarget.h"
#include "Types/JMReconTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMReconTarget() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
JMRECONRUNTIME_API UClass* Z_Construct_UClass_UJMReconTarget();
JMRECONRUNTIME_API UClass* Z_Construct_UClass_UJMReconTarget_NoRegister();
JMRECONRUNTIME_API UEnum* Z_Construct_UEnum_JMReconRuntime_EJMReconEndReason();
JMRECONRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMReconRequestResult();
UPackage* Z_Construct_UPackage__Script_JMReconRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface UJMReconTarget Function BeginPeekPose ********************************
struct JMReconTarget_eventBeginPeekPose_Parms
{
	FGuid SessionId;
	float OpenFraction;
};
void IJMReconTarget::BeginPeekPose(FGuid const& SessionId, float OpenFraction)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_BeginPeekPose instead.");
}
static FName NAME_UJMReconTarget_BeginPeekPose = FName(TEXT("BeginPeekPose"));
void IJMReconTarget::Execute_BeginPeekPose(UObject* O, FGuid const& SessionId, float OpenFraction)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMReconTarget::StaticClass()));
	JMReconTarget_eventBeginPeekPose_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMReconTarget_BeginPeekPose);
	if (Func)
	{
		Parms.SessionId=std::move(SessionId);
		Parms.OpenFraction=std::move(OpenFraction);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IJMReconTarget*)(O->GetNativeInterfaceAddress(UJMReconTarget::StaticClass())))
	{
		I->BeginPeekPose_Implementation(SessionId,OpenFraction);
	}
}
struct Z_Construct_UFunction_UJMReconTarget_BeginPeekPose_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Recon" },
		{ "ModuleRelativePath", "Public/Interfaces/JMReconTarget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SessionId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function BeginPeekPose constinit property declarations *************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SessionId;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OpenFraction;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BeginPeekPose constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BeginPeekPose Property Definitions ************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMReconTarget_BeginPeekPose_Statics::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconTarget_eventBeginPeekPose_Parms, SessionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SessionId_MetaData), NewProp_SessionId_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMReconTarget_BeginPeekPose_Statics::NewProp_OpenFraction = { "OpenFraction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconTarget_eventBeginPeekPose_Parms, OpenFraction), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconTarget_BeginPeekPose_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTarget_BeginPeekPose_Statics::NewProp_SessionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTarget_BeginPeekPose_Statics::NewProp_OpenFraction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTarget_BeginPeekPose_Statics::PropPointers) < 2048);
// ********** End Function BeginPeekPose Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconTarget_BeginPeekPose_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconTarget, nullptr, "BeginPeekPose", 	Z_Construct_UFunction_UJMReconTarget_BeginPeekPose_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTarget_BeginPeekPose_Statics::PropPointers), 
sizeof(JMReconTarget_eventBeginPeekPose_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0CC20C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTarget_BeginPeekPose_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconTarget_BeginPeekPose_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMReconTarget_eventBeginPeekPose_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconTarget_BeginPeekPose()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconTarget_BeginPeekPose_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMReconTarget::execBeginPeekPose)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_SessionId);
	P_GET_PROPERTY(FFloatProperty,Z_Param_OpenFraction);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->BeginPeekPose_Implementation(Z_Param_Out_SessionId,Z_Param_OpenFraction);
	P_NATIVE_END;
}
// ********** End Interface UJMReconTarget Function BeginPeekPose **********************************

// ********** Begin Interface UJMReconTarget Function BeginRecon ***********************************
struct JMReconTarget_eventBeginRecon_Parms
{
	AActor* Interactor;
	FGuid SessionId;
};
void IJMReconTarget::BeginRecon(AActor* Interactor, FGuid const& SessionId)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_BeginRecon instead.");
}
static FName NAME_UJMReconTarget_BeginRecon = FName(TEXT("BeginRecon"));
void IJMReconTarget::Execute_BeginRecon(UObject* O, AActor* Interactor, FGuid const& SessionId)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMReconTarget::StaticClass()));
	JMReconTarget_eventBeginRecon_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMReconTarget_BeginRecon);
	if (Func)
	{
		Parms.Interactor=std::move(Interactor);
		Parms.SessionId=std::move(SessionId);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IJMReconTarget*)(O->GetNativeInterfaceAddress(UJMReconTarget::StaticClass())))
	{
		I->BeginRecon_Implementation(Interactor,SessionId);
	}
}
struct Z_Construct_UFunction_UJMReconTarget_BeginRecon_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Recon" },
		{ "ModuleRelativePath", "Public/Interfaces/JMReconTarget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SessionId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function BeginRecon constinit property declarations ****************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Interactor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SessionId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BeginRecon constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BeginRecon Property Definitions ***************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMReconTarget_BeginRecon_Statics::NewProp_Interactor = { "Interactor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconTarget_eventBeginRecon_Parms, Interactor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMReconTarget_BeginRecon_Statics::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconTarget_eventBeginRecon_Parms, SessionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SessionId_MetaData), NewProp_SessionId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconTarget_BeginRecon_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTarget_BeginRecon_Statics::NewProp_Interactor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTarget_BeginRecon_Statics::NewProp_SessionId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTarget_BeginRecon_Statics::PropPointers) < 2048);
// ********** End Function BeginRecon Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconTarget_BeginRecon_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconTarget, nullptr, "BeginRecon", 	Z_Construct_UFunction_UJMReconTarget_BeginRecon_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTarget_BeginRecon_Statics::PropPointers), 
sizeof(JMReconTarget_eventBeginRecon_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0CC20C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTarget_BeginRecon_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconTarget_BeginRecon_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMReconTarget_eventBeginRecon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconTarget_BeginRecon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconTarget_BeginRecon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMReconTarget::execBeginRecon)
{
	P_GET_OBJECT(AActor,Z_Param_Interactor);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_SessionId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->BeginRecon_Implementation(Z_Param_Interactor,Z_Param_Out_SessionId);
	P_NATIVE_END;
}
// ********** End Interface UJMReconTarget Function BeginRecon *************************************

// ********** Begin Interface UJMReconTarget Function CanEnterListen *******************************
struct JMReconTarget_eventCanEnterListen_Parms
{
	AActor* Interactor;
	FGuid SessionId;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	JMReconTarget_eventCanEnterListen_Parms()
		: ReturnValue(false)
	{
	}
};
bool IJMReconTarget::CanEnterListen(AActor* Interactor, FGuid const& SessionId) const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_CanEnterListen instead.");
	JMReconTarget_eventCanEnterListen_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UJMReconTarget_CanEnterListen = FName(TEXT("CanEnterListen"));
bool IJMReconTarget::Execute_CanEnterListen(const UObject* O, AActor* Interactor, FGuid const& SessionId)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMReconTarget::StaticClass()));
	JMReconTarget_eventCanEnterListen_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMReconTarget_CanEnterListen);
	if (Func)
	{
		Parms.Interactor=std::move(Interactor);
		Parms.SessionId=std::move(SessionId);
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IJMReconTarget*)(O->GetNativeInterfaceAddress(UJMReconTarget::StaticClass())))
	{
		Parms.ReturnValue = I->CanEnterListen_Implementation(Interactor,SessionId);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UJMReconTarget_CanEnterListen_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Recon" },
		{ "ModuleRelativePath", "Public/Interfaces/JMReconTarget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SessionId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CanEnterListen constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Interactor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SessionId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CanEnterListen constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CanEnterListen Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMReconTarget_CanEnterListen_Statics::NewProp_Interactor = { "Interactor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconTarget_eventCanEnterListen_Parms, Interactor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMReconTarget_CanEnterListen_Statics::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconTarget_eventCanEnterListen_Parms, SessionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SessionId_MetaData), NewProp_SessionId_MetaData) };
void Z_Construct_UFunction_UJMReconTarget_CanEnterListen_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMReconTarget_eventCanEnterListen_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMReconTarget_CanEnterListen_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMReconTarget_eventCanEnterListen_Parms), &Z_Construct_UFunction_UJMReconTarget_CanEnterListen_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconTarget_CanEnterListen_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTarget_CanEnterListen_Statics::NewProp_Interactor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTarget_CanEnterListen_Statics::NewProp_SessionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTarget_CanEnterListen_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTarget_CanEnterListen_Statics::PropPointers) < 2048);
// ********** End Function CanEnterListen Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconTarget_CanEnterListen_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconTarget, nullptr, "CanEnterListen", 	Z_Construct_UFunction_UJMReconTarget_CanEnterListen_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTarget_CanEnterListen_Statics::PropPointers), 
sizeof(JMReconTarget_eventCanEnterListen_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5CC20C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTarget_CanEnterListen_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconTarget_CanEnterListen_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMReconTarget_eventCanEnterListen_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconTarget_CanEnterListen()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconTarget_CanEnterListen_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMReconTarget::execCanEnterListen)
{
	P_GET_OBJECT(AActor,Z_Param_Interactor);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_SessionId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanEnterListen_Implementation(Z_Param_Interactor,Z_Param_Out_SessionId);
	P_NATIVE_END;
}
// ********** End Interface UJMReconTarget Function CanEnterListen *********************************

// ********** Begin Interface UJMReconTarget Function CanEnterPeek *********************************
struct JMReconTarget_eventCanEnterPeek_Parms
{
	AActor* Interactor;
	FGuid SessionId;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	JMReconTarget_eventCanEnterPeek_Parms()
		: ReturnValue(false)
	{
	}
};
bool IJMReconTarget::CanEnterPeek(AActor* Interactor, FGuid const& SessionId) const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_CanEnterPeek instead.");
	JMReconTarget_eventCanEnterPeek_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UJMReconTarget_CanEnterPeek = FName(TEXT("CanEnterPeek"));
bool IJMReconTarget::Execute_CanEnterPeek(const UObject* O, AActor* Interactor, FGuid const& SessionId)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMReconTarget::StaticClass()));
	JMReconTarget_eventCanEnterPeek_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMReconTarget_CanEnterPeek);
	if (Func)
	{
		Parms.Interactor=std::move(Interactor);
		Parms.SessionId=std::move(SessionId);
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IJMReconTarget*)(O->GetNativeInterfaceAddress(UJMReconTarget::StaticClass())))
	{
		Parms.ReturnValue = I->CanEnterPeek_Implementation(Interactor,SessionId);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UJMReconTarget_CanEnterPeek_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Recon" },
		{ "ModuleRelativePath", "Public/Interfaces/JMReconTarget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SessionId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CanEnterPeek constinit property declarations **************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Interactor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SessionId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CanEnterPeek constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CanEnterPeek Property Definitions *************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMReconTarget_CanEnterPeek_Statics::NewProp_Interactor = { "Interactor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconTarget_eventCanEnterPeek_Parms, Interactor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMReconTarget_CanEnterPeek_Statics::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconTarget_eventCanEnterPeek_Parms, SessionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SessionId_MetaData), NewProp_SessionId_MetaData) };
void Z_Construct_UFunction_UJMReconTarget_CanEnterPeek_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMReconTarget_eventCanEnterPeek_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMReconTarget_CanEnterPeek_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMReconTarget_eventCanEnterPeek_Parms), &Z_Construct_UFunction_UJMReconTarget_CanEnterPeek_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconTarget_CanEnterPeek_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTarget_CanEnterPeek_Statics::NewProp_Interactor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTarget_CanEnterPeek_Statics::NewProp_SessionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTarget_CanEnterPeek_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTarget_CanEnterPeek_Statics::PropPointers) < 2048);
// ********** End Function CanEnterPeek Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconTarget_CanEnterPeek_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconTarget, nullptr, "CanEnterPeek", 	Z_Construct_UFunction_UJMReconTarget_CanEnterPeek_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTarget_CanEnterPeek_Statics::PropPointers), 
sizeof(JMReconTarget_eventCanEnterPeek_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5CC20C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTarget_CanEnterPeek_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconTarget_CanEnterPeek_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMReconTarget_eventCanEnterPeek_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconTarget_CanEnterPeek()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconTarget_CanEnterPeek_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMReconTarget::execCanEnterPeek)
{
	P_GET_OBJECT(AActor,Z_Param_Interactor);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_SessionId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanEnterPeek_Implementation(Z_Param_Interactor,Z_Param_Out_SessionId);
	P_NATIVE_END;
}
// ********** End Interface UJMReconTarget Function CanEnterPeek ***********************************

// ********** Begin Interface UJMReconTarget Function CanStartRecon ********************************
struct JMReconTarget_eventCanStartRecon_Parms
{
	AActor* Interactor;
	FGuid SessionId;
	FJMReconRequestResult ReturnValue;
};
FJMReconRequestResult IJMReconTarget::CanStartRecon(AActor* Interactor, FGuid const& SessionId) const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_CanStartRecon instead.");
	JMReconTarget_eventCanStartRecon_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UJMReconTarget_CanStartRecon = FName(TEXT("CanStartRecon"));
FJMReconRequestResult IJMReconTarget::Execute_CanStartRecon(const UObject* O, AActor* Interactor, FGuid const& SessionId)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMReconTarget::StaticClass()));
	JMReconTarget_eventCanStartRecon_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMReconTarget_CanStartRecon);
	if (Func)
	{
		Parms.Interactor=std::move(Interactor);
		Parms.SessionId=std::move(SessionId);
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IJMReconTarget*)(O->GetNativeInterfaceAddress(UJMReconTarget::StaticClass())))
	{
		Parms.ReturnValue = I->CanStartRecon_Implementation(Interactor,SessionId);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UJMReconTarget_CanStartRecon_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Recon" },
		{ "ModuleRelativePath", "Public/Interfaces/JMReconTarget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SessionId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CanStartRecon constinit property declarations *************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Interactor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SessionId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CanStartRecon constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CanStartRecon Property Definitions ************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMReconTarget_CanStartRecon_Statics::NewProp_Interactor = { "Interactor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconTarget_eventCanStartRecon_Parms, Interactor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMReconTarget_CanStartRecon_Statics::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconTarget_eventCanStartRecon_Parms, SessionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SessionId_MetaData), NewProp_SessionId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMReconTarget_CanStartRecon_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconTarget_eventCanStartRecon_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMReconRequestResult, METADATA_PARAMS(0, nullptr) }; // 1431610246
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconTarget_CanStartRecon_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTarget_CanStartRecon_Statics::NewProp_Interactor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTarget_CanStartRecon_Statics::NewProp_SessionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTarget_CanStartRecon_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTarget_CanStartRecon_Statics::PropPointers) < 2048);
// ********** End Function CanStartRecon Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconTarget_CanStartRecon_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconTarget, nullptr, "CanStartRecon", 	Z_Construct_UFunction_UJMReconTarget_CanStartRecon_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTarget_CanStartRecon_Statics::PropPointers), 
sizeof(JMReconTarget_eventCanStartRecon_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5CC20C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTarget_CanStartRecon_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconTarget_CanStartRecon_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMReconTarget_eventCanStartRecon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconTarget_CanStartRecon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconTarget_CanStartRecon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMReconTarget::execCanStartRecon)
{
	P_GET_OBJECT(AActor,Z_Param_Interactor);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_SessionId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMReconRequestResult*)Z_Param__Result=P_THIS->CanStartRecon_Implementation(Z_Param_Interactor,Z_Param_Out_SessionId);
	P_NATIVE_END;
}
// ********** End Interface UJMReconTarget Function CanStartRecon **********************************

// ********** Begin Interface UJMReconTarget Function EndPeekPose **********************************
struct JMReconTarget_eventEndPeekPose_Parms
{
	FGuid SessionId;
};
void IJMReconTarget::EndPeekPose(FGuid const& SessionId)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_EndPeekPose instead.");
}
static FName NAME_UJMReconTarget_EndPeekPose = FName(TEXT("EndPeekPose"));
void IJMReconTarget::Execute_EndPeekPose(UObject* O, FGuid const& SessionId)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMReconTarget::StaticClass()));
	JMReconTarget_eventEndPeekPose_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMReconTarget_EndPeekPose);
	if (Func)
	{
		Parms.SessionId=std::move(SessionId);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IJMReconTarget*)(O->GetNativeInterfaceAddress(UJMReconTarget::StaticClass())))
	{
		I->EndPeekPose_Implementation(SessionId);
	}
}
struct Z_Construct_UFunction_UJMReconTarget_EndPeekPose_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Recon" },
		{ "ModuleRelativePath", "Public/Interfaces/JMReconTarget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SessionId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function EndPeekPose constinit property declarations ***************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SessionId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function EndPeekPose constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function EndPeekPose Property Definitions **************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMReconTarget_EndPeekPose_Statics::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconTarget_eventEndPeekPose_Parms, SessionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SessionId_MetaData), NewProp_SessionId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconTarget_EndPeekPose_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTarget_EndPeekPose_Statics::NewProp_SessionId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTarget_EndPeekPose_Statics::PropPointers) < 2048);
// ********** End Function EndPeekPose Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconTarget_EndPeekPose_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconTarget, nullptr, "EndPeekPose", 	Z_Construct_UFunction_UJMReconTarget_EndPeekPose_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTarget_EndPeekPose_Statics::PropPointers), 
sizeof(JMReconTarget_eventEndPeekPose_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0CC20C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTarget_EndPeekPose_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconTarget_EndPeekPose_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMReconTarget_eventEndPeekPose_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconTarget_EndPeekPose()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconTarget_EndPeekPose_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMReconTarget::execEndPeekPose)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_SessionId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EndPeekPose_Implementation(Z_Param_Out_SessionId);
	P_NATIVE_END;
}
// ********** End Interface UJMReconTarget Function EndPeekPose ************************************

// ********** Begin Interface UJMReconTarget Function EndRecon *************************************
struct JMReconTarget_eventEndRecon_Parms
{
	AActor* Interactor;
	FGuid SessionId;
	EJMReconEndReason Reason;
};
void IJMReconTarget::EndRecon(AActor* Interactor, FGuid const& SessionId, EJMReconEndReason Reason)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_EndRecon instead.");
}
static FName NAME_UJMReconTarget_EndRecon = FName(TEXT("EndRecon"));
void IJMReconTarget::Execute_EndRecon(UObject* O, AActor* Interactor, FGuid const& SessionId, EJMReconEndReason Reason)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMReconTarget::StaticClass()));
	JMReconTarget_eventEndRecon_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMReconTarget_EndRecon);
	if (Func)
	{
		Parms.Interactor=std::move(Interactor);
		Parms.SessionId=std::move(SessionId);
		Parms.Reason=std::move(Reason);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IJMReconTarget*)(O->GetNativeInterfaceAddress(UJMReconTarget::StaticClass())))
	{
		I->EndRecon_Implementation(Interactor,SessionId,Reason);
	}
}
struct Z_Construct_UFunction_UJMReconTarget_EndRecon_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Recon" },
		{ "ModuleRelativePath", "Public/Interfaces/JMReconTarget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SessionId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function EndRecon constinit property declarations ******************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Interactor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SessionId;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Reason_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Reason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function EndRecon constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function EndRecon Property Definitions *****************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMReconTarget_EndRecon_Statics::NewProp_Interactor = { "Interactor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconTarget_eventEndRecon_Parms, Interactor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMReconTarget_EndRecon_Statics::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconTarget_eventEndRecon_Parms, SessionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SessionId_MetaData), NewProp_SessionId_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMReconTarget_EndRecon_Statics::NewProp_Reason_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMReconTarget_EndRecon_Statics::NewProp_Reason = { "Reason", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconTarget_eventEndRecon_Parms, Reason), Z_Construct_UEnum_JMReconRuntime_EJMReconEndReason, METADATA_PARAMS(0, nullptr) }; // 3838439290
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconTarget_EndRecon_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTarget_EndRecon_Statics::NewProp_Interactor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTarget_EndRecon_Statics::NewProp_SessionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTarget_EndRecon_Statics::NewProp_Reason_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTarget_EndRecon_Statics::NewProp_Reason,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTarget_EndRecon_Statics::PropPointers) < 2048);
// ********** End Function EndRecon Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconTarget_EndRecon_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconTarget, nullptr, "EndRecon", 	Z_Construct_UFunction_UJMReconTarget_EndRecon_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTarget_EndRecon_Statics::PropPointers), 
sizeof(JMReconTarget_eventEndRecon_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0CC20C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTarget_EndRecon_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconTarget_EndRecon_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMReconTarget_eventEndRecon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconTarget_EndRecon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconTarget_EndRecon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMReconTarget::execEndRecon)
{
	P_GET_OBJECT(AActor,Z_Param_Interactor);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_SessionId);
	P_GET_ENUM(EJMReconEndReason,Z_Param_Reason);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EndRecon_Implementation(Z_Param_Interactor,Z_Param_Out_SessionId,EJMReconEndReason(Z_Param_Reason));
	P_NATIVE_END;
}
// ********** End Interface UJMReconTarget Function EndRecon ***************************************

// ********** Begin Interface UJMReconTarget *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMReconTarget;
UClass* UJMReconTarget::GetPrivateStaticClass()
{
	using TClass = UJMReconTarget;
	if (!Z_Registration_Info_UClass_UJMReconTarget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMReconTarget"),
			Z_Registration_Info_UClass_UJMReconTarget.InnerSingleton,
			StaticRegisterNativesUJMReconTarget,
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
	return Z_Registration_Info_UClass_UJMReconTarget.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMReconTarget_NoRegister()
{
	return UJMReconTarget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMReconTarget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Interfaces/JMReconTarget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface UJMReconTarget constinit property declarations ***********************
// ********** End Interface UJMReconTarget constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("BeginPeekPose"), .Pointer = &IJMReconTarget::execBeginPeekPose },
		{ .NameUTF8 = UTF8TEXT("BeginRecon"), .Pointer = &IJMReconTarget::execBeginRecon },
		{ .NameUTF8 = UTF8TEXT("CanEnterListen"), .Pointer = &IJMReconTarget::execCanEnterListen },
		{ .NameUTF8 = UTF8TEXT("CanEnterPeek"), .Pointer = &IJMReconTarget::execCanEnterPeek },
		{ .NameUTF8 = UTF8TEXT("CanStartRecon"), .Pointer = &IJMReconTarget::execCanStartRecon },
		{ .NameUTF8 = UTF8TEXT("EndPeekPose"), .Pointer = &IJMReconTarget::execEndPeekPose },
		{ .NameUTF8 = UTF8TEXT("EndRecon"), .Pointer = &IJMReconTarget::execEndRecon },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMReconTarget_BeginPeekPose, "BeginPeekPose" }, // 735606679
		{ &Z_Construct_UFunction_UJMReconTarget_BeginRecon, "BeginRecon" }, // 3169526896
		{ &Z_Construct_UFunction_UJMReconTarget_CanEnterListen, "CanEnterListen" }, // 2297794718
		{ &Z_Construct_UFunction_UJMReconTarget_CanEnterPeek, "CanEnterPeek" }, // 3171705791
		{ &Z_Construct_UFunction_UJMReconTarget_CanStartRecon, "CanStartRecon" }, // 225689695
		{ &Z_Construct_UFunction_UJMReconTarget_EndPeekPose, "EndPeekPose" }, // 3963258173
		{ &Z_Construct_UFunction_UJMReconTarget_EndRecon, "EndRecon" }, // 477601346
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IJMReconTarget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMReconTarget_Statics
UObject* (*const Z_Construct_UClass_UJMReconTarget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_JMReconRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconTarget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMReconTarget_Statics::ClassParams = {
	&UJMReconTarget::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconTarget_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMReconTarget_Statics::Class_MetaDataParams)
};
void UJMReconTarget::StaticRegisterNativesUJMReconTarget()
{
	UClass* Class = UJMReconTarget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMReconTarget_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMReconTarget()
{
	if (!Z_Registration_Info_UClass_UJMReconTarget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMReconTarget.OuterSingleton, Z_Construct_UClass_UJMReconTarget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMReconTarget.OuterSingleton;
}
UJMReconTarget::UJMReconTarget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMReconTarget);
// ********** End Interface UJMReconTarget *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Interfaces_JMReconTarget_h__Script_JMReconRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMReconTarget, UJMReconTarget::StaticClass, TEXT("UJMReconTarget"), &Z_Registration_Info_UClass_UJMReconTarget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMReconTarget), 1026615361U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Interfaces_JMReconTarget_h__Script_JMReconRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Interfaces_JMReconTarget_h__Script_JMReconRuntime_1609474938{
	TEXT("/Script/JMReconRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Interfaces_JMReconTarget_h__Script_JMReconRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Interfaces_JMReconTarget_h__Script_JMReconRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
