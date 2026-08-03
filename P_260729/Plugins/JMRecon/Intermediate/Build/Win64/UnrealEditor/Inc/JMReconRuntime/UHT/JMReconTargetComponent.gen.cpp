// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/JMReconTargetComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMReconTargetComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
JMRECONRUNTIME_API UClass* Z_Construct_UClass_UJMReconDefinition_NoRegister();
JMRECONRUNTIME_API UClass* Z_Construct_UClass_UJMReconTargetComponent();
JMRECONRUNTIME_API UClass* Z_Construct_UClass_UJMReconTargetComponent_NoRegister();
JMRECONRUNTIME_API UEnum* Z_Construct_UEnum_JMReconRuntime_EJMReconMode();
UPackage* Z_Construct_UPackage__Script_JMReconRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMReconTargetComponent Function GetEffectiveDefinition ******************
struct Z_Construct_UFunction_UJMReconTargetComponent_GetEffectiveDefinition_Statics
{
	struct JMReconTargetComponent_eventGetEffectiveDefinition_Parms
	{
		UJMReconDefinition* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Recon" },
		{ "ModuleRelativePath", "Public/Components/JMReconTargetComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetEffectiveDefinition constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetEffectiveDefinition constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetEffectiveDefinition Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMReconTargetComponent_GetEffectiveDefinition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconTargetComponent_eventGetEffectiveDefinition_Parms, ReturnValue), Z_Construct_UClass_UJMReconDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconTargetComponent_GetEffectiveDefinition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTargetComponent_GetEffectiveDefinition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTargetComponent_GetEffectiveDefinition_Statics::PropPointers) < 2048);
// ********** End Function GetEffectiveDefinition Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconTargetComponent_GetEffectiveDefinition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconTargetComponent, nullptr, "GetEffectiveDefinition", 	Z_Construct_UFunction_UJMReconTargetComponent_GetEffectiveDefinition_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTargetComponent_GetEffectiveDefinition_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMReconTargetComponent_GetEffectiveDefinition_Statics::JMReconTargetComponent_eventGetEffectiveDefinition_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTargetComponent_GetEffectiveDefinition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconTargetComponent_GetEffectiveDefinition_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMReconTargetComponent_GetEffectiveDefinition_Statics::JMReconTargetComponent_eventGetEffectiveDefinition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconTargetComponent_GetEffectiveDefinition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconTargetComponent_GetEffectiveDefinition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMReconTargetComponent::execGetEffectiveDefinition)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UJMReconDefinition**)Z_Param__Result=P_THIS->GetEffectiveDefinition();
	P_NATIVE_END;
}
// ********** End Class UJMReconTargetComponent Function GetEffectiveDefinition ********************

// ********** Begin Class UJMReconTargetComponent Function GetListenCameraWorldTransform ***********
struct Z_Construct_UFunction_UJMReconTargetComponent_GetListenCameraWorldTransform_Statics
{
	struct JMReconTargetComponent_eventGetListenCameraWorldTransform_Parms
	{
		FTransform ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Recon" },
		{ "ModuleRelativePath", "Public/Components/JMReconTargetComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetListenCameraWorldTransform constinit property declarations *********
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetListenCameraWorldTransform constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetListenCameraWorldTransform Property Definitions ********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMReconTargetComponent_GetListenCameraWorldTransform_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconTargetComponent_eventGetListenCameraWorldTransform_Parms, ReturnValue), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconTargetComponent_GetListenCameraWorldTransform_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTargetComponent_GetListenCameraWorldTransform_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTargetComponent_GetListenCameraWorldTransform_Statics::PropPointers) < 2048);
// ********** End Function GetListenCameraWorldTransform Property Definitions **********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconTargetComponent_GetListenCameraWorldTransform_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconTargetComponent, nullptr, "GetListenCameraWorldTransform", 	Z_Construct_UFunction_UJMReconTargetComponent_GetListenCameraWorldTransform_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTargetComponent_GetListenCameraWorldTransform_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMReconTargetComponent_GetListenCameraWorldTransform_Statics::JMReconTargetComponent_eventGetListenCameraWorldTransform_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTargetComponent_GetListenCameraWorldTransform_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconTargetComponent_GetListenCameraWorldTransform_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMReconTargetComponent_GetListenCameraWorldTransform_Statics::JMReconTargetComponent_eventGetListenCameraWorldTransform_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconTargetComponent_GetListenCameraWorldTransform()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconTargetComponent_GetListenCameraWorldTransform_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMReconTargetComponent::execGetListenCameraWorldTransform)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FTransform*)Z_Param__Result=P_THIS->GetListenCameraWorldTransform();
	P_NATIVE_END;
}
// ********** End Class UJMReconTargetComponent Function GetListenCameraWorldTransform *************

// ********** Begin Class UJMReconTargetComponent Function GetPeekCameraWorldTransform *************
struct Z_Construct_UFunction_UJMReconTargetComponent_GetPeekCameraWorldTransform_Statics
{
	struct JMReconTargetComponent_eventGetPeekCameraWorldTransform_Parms
	{
		FTransform ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Recon" },
		{ "ModuleRelativePath", "Public/Components/JMReconTargetComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPeekCameraWorldTransform constinit property declarations ***********
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPeekCameraWorldTransform constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPeekCameraWorldTransform Property Definitions **********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMReconTargetComponent_GetPeekCameraWorldTransform_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconTargetComponent_eventGetPeekCameraWorldTransform_Parms, ReturnValue), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconTargetComponent_GetPeekCameraWorldTransform_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTargetComponent_GetPeekCameraWorldTransform_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTargetComponent_GetPeekCameraWorldTransform_Statics::PropPointers) < 2048);
// ********** End Function GetPeekCameraWorldTransform Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconTargetComponent_GetPeekCameraWorldTransform_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconTargetComponent, nullptr, "GetPeekCameraWorldTransform", 	Z_Construct_UFunction_UJMReconTargetComponent_GetPeekCameraWorldTransform_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTargetComponent_GetPeekCameraWorldTransform_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMReconTargetComponent_GetPeekCameraWorldTransform_Statics::JMReconTargetComponent_eventGetPeekCameraWorldTransform_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTargetComponent_GetPeekCameraWorldTransform_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconTargetComponent_GetPeekCameraWorldTransform_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMReconTargetComponent_GetPeekCameraWorldTransform_Statics::JMReconTargetComponent_eventGetPeekCameraWorldTransform_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconTargetComponent_GetPeekCameraWorldTransform()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconTargetComponent_GetPeekCameraWorldTransform_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMReconTargetComponent::execGetPeekCameraWorldTransform)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FTransform*)Z_Param__Result=P_THIS->GetPeekCameraWorldTransform();
	P_NATIVE_END;
}
// ********** End Class UJMReconTargetComponent Function GetPeekCameraWorldTransform ***************

// ********** Begin Class UJMReconTargetComponent Function GetPlayerWorldTransform *****************
struct Z_Construct_UFunction_UJMReconTargetComponent_GetPlayerWorldTransform_Statics
{
	struct JMReconTargetComponent_eventGetPlayerWorldTransform_Parms
	{
		FTransform ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Recon" },
		{ "ModuleRelativePath", "Public/Components/JMReconTargetComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPlayerWorldTransform constinit property declarations ***************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPlayerWorldTransform constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPlayerWorldTransform Property Definitions **************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMReconTargetComponent_GetPlayerWorldTransform_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconTargetComponent_eventGetPlayerWorldTransform_Parms, ReturnValue), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconTargetComponent_GetPlayerWorldTransform_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTargetComponent_GetPlayerWorldTransform_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTargetComponent_GetPlayerWorldTransform_Statics::PropPointers) < 2048);
// ********** End Function GetPlayerWorldTransform Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconTargetComponent_GetPlayerWorldTransform_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconTargetComponent, nullptr, "GetPlayerWorldTransform", 	Z_Construct_UFunction_UJMReconTargetComponent_GetPlayerWorldTransform_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTargetComponent_GetPlayerWorldTransform_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMReconTargetComponent_GetPlayerWorldTransform_Statics::JMReconTargetComponent_eventGetPlayerWorldTransform_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTargetComponent_GetPlayerWorldTransform_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconTargetComponent_GetPlayerWorldTransform_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMReconTargetComponent_GetPlayerWorldTransform_Statics::JMReconTargetComponent_eventGetPlayerWorldTransform_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconTargetComponent_GetPlayerWorldTransform()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconTargetComponent_GetPlayerWorldTransform_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMReconTargetComponent::execGetPlayerWorldTransform)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FTransform*)Z_Param__Result=P_THIS->GetPlayerWorldTransform();
	P_NATIVE_END;
}
// ********** End Class UJMReconTargetComponent Function GetPlayerWorldTransform *******************

// ********** Begin Class UJMReconTargetComponent Function SupportsMode ****************************
struct Z_Construct_UFunction_UJMReconTargetComponent_SupportsMode_Statics
{
	struct JMReconTargetComponent_eventSupportsMode_Parms
	{
		EJMReconMode Mode;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Recon" },
		{ "ModuleRelativePath", "Public/Components/JMReconTargetComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SupportsMode constinit property declarations **************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Mode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Mode;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SupportsMode constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SupportsMode Property Definitions *************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMReconTargetComponent_SupportsMode_Statics::NewProp_Mode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMReconTargetComponent_SupportsMode_Statics::NewProp_Mode = { "Mode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconTargetComponent_eventSupportsMode_Parms, Mode), Z_Construct_UEnum_JMReconRuntime_EJMReconMode, METADATA_PARAMS(0, nullptr) }; // 1119645649
void Z_Construct_UFunction_UJMReconTargetComponent_SupportsMode_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMReconTargetComponent_eventSupportsMode_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMReconTargetComponent_SupportsMode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMReconTargetComponent_eventSupportsMode_Parms), &Z_Construct_UFunction_UJMReconTargetComponent_SupportsMode_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconTargetComponent_SupportsMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTargetComponent_SupportsMode_Statics::NewProp_Mode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTargetComponent_SupportsMode_Statics::NewProp_Mode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconTargetComponent_SupportsMode_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTargetComponent_SupportsMode_Statics::PropPointers) < 2048);
// ********** End Function SupportsMode Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconTargetComponent_SupportsMode_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconTargetComponent, nullptr, "SupportsMode", 	Z_Construct_UFunction_UJMReconTargetComponent_SupportsMode_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTargetComponent_SupportsMode_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMReconTargetComponent_SupportsMode_Statics::JMReconTargetComponent_eventSupportsMode_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconTargetComponent_SupportsMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconTargetComponent_SupportsMode_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMReconTargetComponent_SupportsMode_Statics::JMReconTargetComponent_eventSupportsMode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconTargetComponent_SupportsMode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconTargetComponent_SupportsMode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMReconTargetComponent::execSupportsMode)
{
	P_GET_ENUM(EJMReconMode,Z_Param_Mode);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SupportsMode(EJMReconMode(Z_Param_Mode));
	P_NATIVE_END;
}
// ********** End Class UJMReconTargetComponent Function SupportsMode ******************************

// ********** Begin Class UJMReconTargetComponent **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMReconTargetComponent;
UClass* UJMReconTargetComponent::GetPrivateStaticClass()
{
	using TClass = UJMReconTargetComponent;
	if (!Z_Registration_Info_UClass_UJMReconTargetComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMReconTargetComponent"),
			Z_Registration_Info_UClass_UJMReconTargetComponent.InnerSingleton,
			StaticRegisterNativesUJMReconTargetComponent,
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
	return Z_Registration_Info_UClass_UJMReconTargetComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMReconTargetComponent_NoRegister()
{
	return UJMReconTargetComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMReconTargetComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JM" },
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "Components/JMReconTargetComponent.h" },
		{ "ModuleRelativePath", "Public/Components/JMReconTargetComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReconDefinition_MetaData[] = {
		{ "AdvancedDisplay", "" },
		{ "Category", "Recon|Advanced" },
		{ "ModuleRelativePath", "Public/Components/JMReconTargetComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[] = {
		{ "Category", "Recon" },
		{ "ModuleRelativePath", "Public/Components/JMReconTargetComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AllowedReconModes_MetaData[] = {
		{ "AdvancedDisplay", "" },
		{ "Bitmask", "" },
		{ "BitmaskEnum", "/Script/JMReconRuntime.EJMReconMode" },
		{ "Category", "Recon|Advanced" },
		{ "ModuleRelativePath", "Public/Components/JMReconTargetComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerRelativeTransform_MetaData[] = {
		{ "AdvancedDisplay", "" },
		{ "Category", "Recon|Advanced" },
		{ "ModuleRelativePath", "Public/Components/JMReconTargetComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ListenCameraRelativeTransform_MetaData[] = {
		{ "AdvancedDisplay", "" },
		{ "Category", "Recon|Advanced" },
		{ "ModuleRelativePath", "Public/Components/JMReconTargetComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PeekCameraRelativeTransform_MetaData[] = {
		{ "AdvancedDisplay", "" },
		{ "Category", "Recon|Advanced" },
		{ "ModuleRelativePath", "Public/Components/JMReconTargetComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerAnchorOverride_MetaData[] = {
		{ "AdvancedDisplay", "" },
		{ "AllowAnyActor", "" },
		{ "Category", "Recon|Advanced" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Components/JMReconTargetComponent.h" },
		{ "UseComponentPicker", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ListenCameraAnchorOverride_MetaData[] = {
		{ "AdvancedDisplay", "" },
		{ "AllowAnyActor", "" },
		{ "Category", "Recon|Advanced" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Components/JMReconTargetComponent.h" },
		{ "UseComponentPicker", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PeekCameraAnchorOverride_MetaData[] = {
		{ "AdvancedDisplay", "" },
		{ "AllowAnyActor", "" },
		{ "Category", "Recon|Advanced" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Components/JMReconTargetComponent.h" },
		{ "UseComponentPicker", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumStartDistance_MetaData[] = {
		{ "AdvancedDisplay", "" },
		{ "Category", "Recon|Advanced" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Components/JMReconTargetComponent.h" },
		{ "Units", "cm" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMReconTargetComponent constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReconDefinition;
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AllowedReconModes;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PlayerRelativeTransform;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ListenCameraRelativeTransform;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PeekCameraRelativeTransform;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerAnchorOverride;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ListenCameraAnchorOverride;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PeekCameraAnchorOverride;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaximumStartDistance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMReconTargetComponent constinit property declarations ********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetEffectiveDefinition"), .Pointer = &UJMReconTargetComponent::execGetEffectiveDefinition },
		{ .NameUTF8 = UTF8TEXT("GetListenCameraWorldTransform"), .Pointer = &UJMReconTargetComponent::execGetListenCameraWorldTransform },
		{ .NameUTF8 = UTF8TEXT("GetPeekCameraWorldTransform"), .Pointer = &UJMReconTargetComponent::execGetPeekCameraWorldTransform },
		{ .NameUTF8 = UTF8TEXT("GetPlayerWorldTransform"), .Pointer = &UJMReconTargetComponent::execGetPlayerWorldTransform },
		{ .NameUTF8 = UTF8TEXT("SupportsMode"), .Pointer = &UJMReconTargetComponent::execSupportsMode },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMReconTargetComponent_GetEffectiveDefinition, "GetEffectiveDefinition" }, // 2962366114
		{ &Z_Construct_UFunction_UJMReconTargetComponent_GetListenCameraWorldTransform, "GetListenCameraWorldTransform" }, // 1509764554
		{ &Z_Construct_UFunction_UJMReconTargetComponent_GetPeekCameraWorldTransform, "GetPeekCameraWorldTransform" }, // 1371575460
		{ &Z_Construct_UFunction_UJMReconTargetComponent_GetPlayerWorldTransform, "GetPlayerWorldTransform" }, // 348801451
		{ &Z_Construct_UFunction_UJMReconTargetComponent_SupportsMode, "SupportsMode" }, // 740647529
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMReconTargetComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMReconTargetComponent_Statics

// ********** Begin Class UJMReconTargetComponent Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMReconTargetComponent_Statics::NewProp_ReconDefinition = { "ReconDefinition", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconTargetComponent, ReconDefinition), Z_Construct_UClass_UJMReconDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReconDefinition_MetaData), NewProp_ReconDefinition_MetaData) };
void Z_Construct_UClass_UJMReconTargetComponent_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((UJMReconTargetComponent*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMReconTargetComponent_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMReconTargetComponent), &Z_Construct_UClass_UJMReconTargetComponent_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UJMReconTargetComponent_Statics::NewProp_AllowedReconModes = { "AllowedReconModes", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconTargetComponent, AllowedReconModes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AllowedReconModes_MetaData), NewProp_AllowedReconModes_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMReconTargetComponent_Statics::NewProp_PlayerRelativeTransform = { "PlayerRelativeTransform", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconTargetComponent, PlayerRelativeTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerRelativeTransform_MetaData), NewProp_PlayerRelativeTransform_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMReconTargetComponent_Statics::NewProp_ListenCameraRelativeTransform = { "ListenCameraRelativeTransform", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconTargetComponent, ListenCameraRelativeTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ListenCameraRelativeTransform_MetaData), NewProp_ListenCameraRelativeTransform_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMReconTargetComponent_Statics::NewProp_PeekCameraRelativeTransform = { "PeekCameraRelativeTransform", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconTargetComponent, PeekCameraRelativeTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PeekCameraRelativeTransform_MetaData), NewProp_PeekCameraRelativeTransform_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMReconTargetComponent_Statics::NewProp_PlayerAnchorOverride = { "PlayerAnchorOverride", nullptr, (EPropertyFlags)0x011400000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconTargetComponent, PlayerAnchorOverride), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerAnchorOverride_MetaData), NewProp_PlayerAnchorOverride_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMReconTargetComponent_Statics::NewProp_ListenCameraAnchorOverride = { "ListenCameraAnchorOverride", nullptr, (EPropertyFlags)0x011400000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconTargetComponent, ListenCameraAnchorOverride), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ListenCameraAnchorOverride_MetaData), NewProp_ListenCameraAnchorOverride_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMReconTargetComponent_Statics::NewProp_PeekCameraAnchorOverride = { "PeekCameraAnchorOverride", nullptr, (EPropertyFlags)0x011400000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconTargetComponent, PeekCameraAnchorOverride), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PeekCameraAnchorOverride_MetaData), NewProp_PeekCameraAnchorOverride_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMReconTargetComponent_Statics::NewProp_MaximumStartDistance = { "MaximumStartDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconTargetComponent, MaximumStartDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumStartDistance_MetaData), NewProp_MaximumStartDistance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMReconTargetComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconTargetComponent_Statics::NewProp_ReconDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconTargetComponent_Statics::NewProp_bEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconTargetComponent_Statics::NewProp_AllowedReconModes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconTargetComponent_Statics::NewProp_PlayerRelativeTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconTargetComponent_Statics::NewProp_ListenCameraRelativeTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconTargetComponent_Statics::NewProp_PeekCameraRelativeTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconTargetComponent_Statics::NewProp_PlayerAnchorOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconTargetComponent_Statics::NewProp_ListenCameraAnchorOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconTargetComponent_Statics::NewProp_PeekCameraAnchorOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconTargetComponent_Statics::NewProp_MaximumStartDistance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconTargetComponent_Statics::PropPointers) < 2048);
// ********** End Class UJMReconTargetComponent Property Definitions *******************************
UObject* (*const Z_Construct_UClass_UJMReconTargetComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USceneComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMReconRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconTargetComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMReconTargetComponent_Statics::ClassParams = {
	&UJMReconTargetComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMReconTargetComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconTargetComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconTargetComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMReconTargetComponent_Statics::Class_MetaDataParams)
};
void UJMReconTargetComponent::StaticRegisterNativesUJMReconTargetComponent()
{
	UClass* Class = UJMReconTargetComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMReconTargetComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMReconTargetComponent()
{
	if (!Z_Registration_Info_UClass_UJMReconTargetComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMReconTargetComponent.OuterSingleton, Z_Construct_UClass_UJMReconTargetComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMReconTargetComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMReconTargetComponent);
UJMReconTargetComponent::~UJMReconTargetComponent() {}
// ********** End Class UJMReconTargetComponent ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconTargetComponent_h__Script_JMReconRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMReconTargetComponent, UJMReconTargetComponent::StaticClass, TEXT("UJMReconTargetComponent"), &Z_Registration_Info_UClass_UJMReconTargetComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMReconTargetComponent), 491686491U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconTargetComponent_h__Script_JMReconRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconTargetComponent_h__Script_JMReconRuntime_4052663461{
	TEXT("/Script/JMReconRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconTargetComponent_h__Script_JMReconRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Components_JMReconTargetComponent_h__Script_JMReconRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
