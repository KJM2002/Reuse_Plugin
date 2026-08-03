// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/JMHideSpotComponent.h"
#include "GameplayTagContainer.h"
#include "Types/JMHideTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMHideSpotComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideDefinition_NoRegister();
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideSpotComponent();
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideSpotComponent_NoRegister();
JMHIDERUNTIME_API UEnum* Z_Construct_UEnum_JMHideRuntime_EJMHideSpotArchetype();
JMHIDERUNTIME_API UEnum* Z_Construct_UEnum_JMHideRuntime_EJMHideSpotState();
JMHIDERUNTIME_API UFunction* Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSpotStateChangedSignature__DelegateSignature();
JMHIDERUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMHideConfigOverride();
UPackage* Z_Construct_UPackage__Script_JMHideRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FJMHideSpotStateChangedSignature **************************************
struct Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSpotStateChangedSignature__DelegateSignature_Statics
{
	struct _Script_JMHideRuntime_eventJMHideSpotStateChangedSignature_Parms
	{
		EJMHideSpotState OldState;
		EJMHideSpotState NewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/JMHideSpotComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMHideSpotStateChangedSignature constinit property declarations ******
	static const UECodeGen_Private::FBytePropertyParams NewProp_OldState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OldState;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMHideSpotStateChangedSignature constinit property declarations ********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMHideSpotStateChangedSignature Property Definitions *****************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSpotStateChangedSignature__DelegateSignature_Statics::NewProp_OldState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSpotStateChangedSignature__DelegateSignature_Statics::NewProp_OldState = { "OldState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMHideRuntime_eventJMHideSpotStateChangedSignature_Parms, OldState), Z_Construct_UEnum_JMHideRuntime_EJMHideSpotState, METADATA_PARAMS(0, nullptr) }; // 3285289581
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSpotStateChangedSignature__DelegateSignature_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSpotStateChangedSignature__DelegateSignature_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMHideRuntime_eventJMHideSpotStateChangedSignature_Parms, NewState), Z_Construct_UEnum_JMHideRuntime_EJMHideSpotState, METADATA_PARAMS(0, nullptr) }; // 3285289581
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSpotStateChangedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSpotStateChangedSignature__DelegateSignature_Statics::NewProp_OldState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSpotStateChangedSignature__DelegateSignature_Statics::NewProp_OldState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSpotStateChangedSignature__DelegateSignature_Statics::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSpotStateChangedSignature__DelegateSignature_Statics::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSpotStateChangedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMHideSpotStateChangedSignature Property Definitions *******************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSpotStateChangedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMHideRuntime, nullptr, "JMHideSpotStateChangedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSpotStateChangedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSpotStateChangedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSpotStateChangedSignature__DelegateSignature_Statics::_Script_JMHideRuntime_eventJMHideSpotStateChangedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSpotStateChangedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSpotStateChangedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSpotStateChangedSignature__DelegateSignature_Statics::_Script_JMHideRuntime_eventJMHideSpotStateChangedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSpotStateChangedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSpotStateChangedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMHideSpotStateChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMHideSpotStateChangedSignature, EJMHideSpotState OldState, EJMHideSpotState NewState)
{
	struct _Script_JMHideRuntime_eventJMHideSpotStateChangedSignature_Parms
	{
		EJMHideSpotState OldState;
		EJMHideSpotState NewState;
	};
	_Script_JMHideRuntime_eventJMHideSpotStateChangedSignature_Parms Parms;
	Parms.OldState=OldState;
	Parms.NewState=NewState;
	JMHideSpotStateChangedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMHideSpotStateChangedSignature ****************************************

// ********** Begin Class UJMHideSpotComponent Function GetSpotState *******************************
struct Z_Construct_UFunction_UJMHideSpotComponent_GetSpotState_Statics
{
	struct JMHideSpotComponent_eventGetSpotState_Parms
	{
		EJMHideSpotState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Components/JMHideSpotComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSpotState constinit property declarations **************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSpotState constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSpotState Property Definitions *************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMHideSpotComponent_GetSpotState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMHideSpotComponent_GetSpotState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMHideSpotComponent_eventGetSpotState_Parms, ReturnValue), Z_Construct_UEnum_JMHideRuntime_EJMHideSpotState, METADATA_PARAMS(0, nullptr) }; // 3285289581
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMHideSpotComponent_GetSpotState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideSpotComponent_GetSpotState_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideSpotComponent_GetSpotState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideSpotComponent_GetSpotState_Statics::PropPointers) < 2048);
// ********** End Function GetSpotState Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMHideSpotComponent_GetSpotState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMHideSpotComponent, nullptr, "GetSpotState", 	Z_Construct_UFunction_UJMHideSpotComponent_GetSpotState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideSpotComponent_GetSpotState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMHideSpotComponent_GetSpotState_Statics::JMHideSpotComponent_eventGetSpotState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideSpotComponent_GetSpotState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMHideSpotComponent_GetSpotState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMHideSpotComponent_GetSpotState_Statics::JMHideSpotComponent_eventGetSpotState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMHideSpotComponent_GetSpotState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMHideSpotComponent_GetSpotState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMHideSpotComponent::execGetSpotState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EJMHideSpotState*)Z_Param__Result=P_THIS->GetSpotState();
	P_NATIVE_END;
}
// ********** End Class UJMHideSpotComponent Function GetSpotState *********************************

// ********** Begin Class UJMHideSpotComponent Function IsAvailable ********************************
struct Z_Construct_UFunction_UJMHideSpotComponent_IsAvailable_Statics
{
	struct JMHideSpotComponent_eventIsAvailable_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Components/JMHideSpotComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsAvailable constinit property declarations ***************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsAvailable constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsAvailable Property Definitions **************************************
void Z_Construct_UFunction_UJMHideSpotComponent_IsAvailable_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMHideSpotComponent_eventIsAvailable_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMHideSpotComponent_IsAvailable_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMHideSpotComponent_eventIsAvailable_Parms), &Z_Construct_UFunction_UJMHideSpotComponent_IsAvailable_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMHideSpotComponent_IsAvailable_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideSpotComponent_IsAvailable_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideSpotComponent_IsAvailable_Statics::PropPointers) < 2048);
// ********** End Function IsAvailable Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMHideSpotComponent_IsAvailable_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMHideSpotComponent, nullptr, "IsAvailable", 	Z_Construct_UFunction_UJMHideSpotComponent_IsAvailable_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideSpotComponent_IsAvailable_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMHideSpotComponent_IsAvailable_Statics::JMHideSpotComponent_eventIsAvailable_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideSpotComponent_IsAvailable_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMHideSpotComponent_IsAvailable_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMHideSpotComponent_IsAvailable_Statics::JMHideSpotComponent_eventIsAvailable_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMHideSpotComponent_IsAvailable()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMHideSpotComponent_IsAvailable_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMHideSpotComponent::execIsAvailable)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsAvailable();
	P_NATIVE_END;
}
// ********** End Class UJMHideSpotComponent Function IsAvailable **********************************

// ********** Begin Class UJMHideSpotComponent Function ValidateConfiguration **********************
struct Z_Construct_UFunction_UJMHideSpotComponent_ValidateConfiguration_Statics
{
	struct JMHideSpotComponent_eventValidateConfiguration_Parms
	{
		TArray<FText> OutErrors;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Hide|Validation" },
		{ "ModuleRelativePath", "Public/Components/JMHideSpotComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ValidateConfiguration constinit property declarations *****************
	static const UECodeGen_Private::FTextPropertyParams NewProp_OutErrors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutErrors;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ValidateConfiguration constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ValidateConfiguration Property Definitions ****************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UJMHideSpotComponent_ValidateConfiguration_Statics::NewProp_OutErrors_Inner = { "OutErrors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UJMHideSpotComponent_ValidateConfiguration_Statics::NewProp_OutErrors = { "OutErrors", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMHideSpotComponent_eventValidateConfiguration_Parms, OutErrors), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UJMHideSpotComponent_ValidateConfiguration_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMHideSpotComponent_eventValidateConfiguration_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMHideSpotComponent_ValidateConfiguration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMHideSpotComponent_eventValidateConfiguration_Parms), &Z_Construct_UFunction_UJMHideSpotComponent_ValidateConfiguration_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMHideSpotComponent_ValidateConfiguration_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideSpotComponent_ValidateConfiguration_Statics::NewProp_OutErrors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideSpotComponent_ValidateConfiguration_Statics::NewProp_OutErrors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideSpotComponent_ValidateConfiguration_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideSpotComponent_ValidateConfiguration_Statics::PropPointers) < 2048);
// ********** End Function ValidateConfiguration Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMHideSpotComponent_ValidateConfiguration_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMHideSpotComponent, nullptr, "ValidateConfiguration", 	Z_Construct_UFunction_UJMHideSpotComponent_ValidateConfiguration_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideSpotComponent_ValidateConfiguration_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMHideSpotComponent_ValidateConfiguration_Statics::JMHideSpotComponent_eventValidateConfiguration_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideSpotComponent_ValidateConfiguration_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMHideSpotComponent_ValidateConfiguration_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMHideSpotComponent_ValidateConfiguration_Statics::JMHideSpotComponent_eventValidateConfiguration_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMHideSpotComponent_ValidateConfiguration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMHideSpotComponent_ValidateConfiguration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMHideSpotComponent::execValidateConfiguration)
{
	P_GET_TARRAY_REF(FText,Z_Param_Out_OutErrors);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ValidateConfiguration(Z_Param_Out_OutErrors);
	P_NATIVE_END;
}
// ********** End Class UJMHideSpotComponent Function ValidateConfiguration ************************

// ********** Begin Class UJMHideSpotComponent *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMHideSpotComponent;
UClass* UJMHideSpotComponent::GetPrivateStaticClass()
{
	using TClass = UJMHideSpotComponent;
	if (!Z_Registration_Info_UClass_UJMHideSpotComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMHideSpotComponent"),
			Z_Registration_Info_UClass_UJMHideSpotComponent.InnerSingleton,
			StaticRegisterNativesUJMHideSpotComponent,
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
	return Z_Registration_Info_UClass_UJMHideSpotComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMHideSpotComponent_NoRegister()
{
	return UJMHideSpotComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMHideSpotComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JMHide" },
		{ "IncludePath", "Components/JMHideSpotComponent.h" },
		{ "ModuleRelativePath", "Public/Components/JMHideSpotComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Components/JMHideSpotComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Definition_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Components/JMHideSpotComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Archetype_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Components/JMHideSpotComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HideType_MetaData[] = {
		{ "Categories", "Hide.Type" },
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Components/JMHideSpotComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstanceConfigOverride_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Components/JMHideSpotComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSpotStateChanged_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Components/JMHideSpotComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMHideSpotComponent constinit property declarations *********************
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Definition;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Archetype_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Archetype;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HideType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InstanceConfigOverride;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSpotStateChanged;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMHideSpotComponent constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetSpotState"), .Pointer = &UJMHideSpotComponent::execGetSpotState },
		{ .NameUTF8 = UTF8TEXT("IsAvailable"), .Pointer = &UJMHideSpotComponent::execIsAvailable },
		{ .NameUTF8 = UTF8TEXT("ValidateConfiguration"), .Pointer = &UJMHideSpotComponent::execValidateConfiguration },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMHideSpotComponent_GetSpotState, "GetSpotState" }, // 744707455
		{ &Z_Construct_UFunction_UJMHideSpotComponent_IsAvailable, "IsAvailable" }, // 3807986960
		{ &Z_Construct_UFunction_UJMHideSpotComponent_ValidateConfiguration, "ValidateConfiguration" }, // 3981363364
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMHideSpotComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMHideSpotComponent_Statics

// ********** Begin Class UJMHideSpotComponent Property Definitions ********************************
void Z_Construct_UClass_UJMHideSpotComponent_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((UJMHideSpotComponent*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMHideSpotComponent_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMHideSpotComponent), &Z_Construct_UClass_UJMHideSpotComponent_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMHideSpotComponent_Statics::NewProp_Definition = { "Definition", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMHideSpotComponent, Definition), Z_Construct_UClass_UJMHideDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Definition_MetaData), NewProp_Definition_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMHideSpotComponent_Statics::NewProp_Archetype_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMHideSpotComponent_Statics::NewProp_Archetype = { "Archetype", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMHideSpotComponent, Archetype), Z_Construct_UEnum_JMHideRuntime_EJMHideSpotArchetype, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Archetype_MetaData), NewProp_Archetype_MetaData) }; // 3499806852
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMHideSpotComponent_Statics::NewProp_HideType = { "HideType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMHideSpotComponent, HideType), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HideType_MetaData), NewProp_HideType_MetaData) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMHideSpotComponent_Statics::NewProp_InstanceConfigOverride = { "InstanceConfigOverride", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMHideSpotComponent, InstanceConfigOverride), Z_Construct_UScriptStruct_FJMHideConfigOverride, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstanceConfigOverride_MetaData), NewProp_InstanceConfigOverride_MetaData) }; // 2145498035
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMHideSpotComponent_Statics::NewProp_OnSpotStateChanged = { "OnSpotStateChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMHideSpotComponent, OnSpotStateChanged), Z_Construct_UDelegateFunction_JMHideRuntime_JMHideSpotStateChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSpotStateChanged_MetaData), NewProp_OnSpotStateChanged_MetaData) }; // 1296571440
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMHideSpotComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideSpotComponent_Statics::NewProp_bEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideSpotComponent_Statics::NewProp_Definition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideSpotComponent_Statics::NewProp_Archetype_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideSpotComponent_Statics::NewProp_Archetype,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideSpotComponent_Statics::NewProp_HideType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideSpotComponent_Statics::NewProp_InstanceConfigOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideSpotComponent_Statics::NewProp_OnSpotStateChanged,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideSpotComponent_Statics::PropPointers) < 2048);
// ********** End Class UJMHideSpotComponent Property Definitions **********************************
UObject* (*const Z_Construct_UClass_UJMHideSpotComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideSpotComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMHideSpotComponent_Statics::ClassParams = {
	&UJMHideSpotComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMHideSpotComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideSpotComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideSpotComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMHideSpotComponent_Statics::Class_MetaDataParams)
};
void UJMHideSpotComponent::StaticRegisterNativesUJMHideSpotComponent()
{
	UClass* Class = UJMHideSpotComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMHideSpotComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMHideSpotComponent()
{
	if (!Z_Registration_Info_UClass_UJMHideSpotComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMHideSpotComponent.OuterSingleton, Z_Construct_UClass_UJMHideSpotComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMHideSpotComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMHideSpotComponent);
UJMHideSpotComponent::~UJMHideSpotComponent() {}
// ********** End Class UJMHideSpotComponent *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSpotComponent_h__Script_JMHideRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMHideSpotComponent, UJMHideSpotComponent::StaticClass, TEXT("UJMHideSpotComponent"), &Z_Registration_Info_UClass_UJMHideSpotComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMHideSpotComponent), 2414022951U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSpotComponent_h__Script_JMHideRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSpotComponent_h__Script_JMHideRuntime_669775946{
	TEXT("/Script/JMHideRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSpotComponent_h__Script_JMHideRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSpotComponent_h__Script_JMHideRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
