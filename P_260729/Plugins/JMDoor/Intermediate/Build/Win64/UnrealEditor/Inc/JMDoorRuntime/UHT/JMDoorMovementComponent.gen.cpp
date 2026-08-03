// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Movement/JMDoorMovementComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMDoorMovementComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorMovementComponent();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorMovementComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMDoorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMDoorMovementComponent Function CalculateRelativeTransform *************
struct JMDoorMovementComponent_eventCalculateRelativeTransform_Parms
{
	float OpenFraction;
	int32 DirectionSign;
	FTransform ReturnValue;
};
static FName NAME_UJMDoorMovementComponent_CalculateRelativeTransform = FName(TEXT("CalculateRelativeTransform"));
FTransform UJMDoorMovementComponent::CalculateRelativeTransform(float OpenFraction, int32 DirectionSign) const
{
	UFunction* Func = FindFunctionChecked(NAME_UJMDoorMovementComponent_CalculateRelativeTransform);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		JMDoorMovementComponent_eventCalculateRelativeTransform_Parms Parms;
		Parms.OpenFraction=OpenFraction;
		Parms.DirectionSign=DirectionSign;
		const_cast<UJMDoorMovementComponent*>(this)->ProcessEvent(Func,&Parms);
		return Parms.ReturnValue;
	}
	else
	{
		return const_cast<UJMDoorMovementComponent*>(this)->CalculateRelativeTransform_Implementation(OpenFraction, DirectionSign);
	}
}
struct Z_Construct_UFunction_UJMDoorMovementComponent_CalculateRelativeTransform_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Movement" },
		{ "ModuleRelativePath", "Public/Movement/JMDoorMovementComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CalculateRelativeTransform constinit property declarations ************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OpenFraction;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DirectionSign;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CalculateRelativeTransform constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CalculateRelativeTransform Property Definitions ***********************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMDoorMovementComponent_CalculateRelativeTransform_Statics::NewProp_OpenFraction = { "OpenFraction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorMovementComponent_eventCalculateRelativeTransform_Parms, OpenFraction), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UJMDoorMovementComponent_CalculateRelativeTransform_Statics::NewProp_DirectionSign = { "DirectionSign", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorMovementComponent_eventCalculateRelativeTransform_Parms, DirectionSign), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorMovementComponent_CalculateRelativeTransform_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorMovementComponent_eventCalculateRelativeTransform_Parms, ReturnValue), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorMovementComponent_CalculateRelativeTransform_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorMovementComponent_CalculateRelativeTransform_Statics::NewProp_OpenFraction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorMovementComponent_CalculateRelativeTransform_Statics::NewProp_DirectionSign,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorMovementComponent_CalculateRelativeTransform_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_CalculateRelativeTransform_Statics::PropPointers) < 2048);
// ********** End Function CalculateRelativeTransform Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorMovementComponent_CalculateRelativeTransform_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorMovementComponent, nullptr, "CalculateRelativeTransform", 	Z_Construct_UFunction_UJMDoorMovementComponent_CalculateRelativeTransform_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_CalculateRelativeTransform_Statics::PropPointers), 
sizeof(JMDoorMovementComponent_eventCalculateRelativeTransform_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48820C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_CalculateRelativeTransform_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorMovementComponent_CalculateRelativeTransform_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMDoorMovementComponent_eventCalculateRelativeTransform_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorMovementComponent_CalculateRelativeTransform()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorMovementComponent_CalculateRelativeTransform_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorMovementComponent::execCalculateRelativeTransform)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_OpenFraction);
	P_GET_PROPERTY(FIntProperty,Z_Param_DirectionSign);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FTransform*)Z_Param__Result=P_THIS->CalculateRelativeTransform_Implementation(Z_Param_OpenFraction,Z_Param_DirectionSign);
	P_NATIVE_END;
}
// ********** End Class UJMDoorMovementComponent Function CalculateRelativeTransform ***************

// ********** Begin Class UJMDoorMovementComponent Function GetCollisionComponent ******************
struct Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionComponent_Statics
{
	struct JMDoorMovementComponent_eventGetCollisionComponent_Parms
	{
		UPrimitiveComponent* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Movement" },
		{ "ModuleRelativePath", "Public/Movement/JMDoorMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCollisionComponent constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCollisionComponent constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCollisionComponent Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorMovementComponent_eventGetCollisionComponent_Parms, ReturnValue), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionComponent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionComponent_Statics::PropPointers) < 2048);
// ********** End Function GetCollisionComponent Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionComponent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorMovementComponent, nullptr, "GetCollisionComponent", 	Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionComponent_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionComponent_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionComponent_Statics::JMDoorMovementComponent_eventGetCollisionComponent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionComponent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionComponent_Statics::JMDoorMovementComponent_eventGetCollisionComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorMovementComponent::execGetCollisionComponent)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UPrimitiveComponent**)Z_Param__Result=P_THIS->GetCollisionComponent();
	P_NATIVE_END;
}
// ********** End Class UJMDoorMovementComponent Function GetCollisionComponent ********************

// ********** Begin Class UJMDoorMovementComponent Function GetCollisionWorldTransformAtFraction ***
struct Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionWorldTransformAtFraction_Statics
{
	struct JMDoorMovementComponent_eventGetCollisionWorldTransformAtFraction_Parms
	{
		float OpenFraction;
		int32 DirectionSign;
		FTransform ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Movement" },
		{ "ModuleRelativePath", "Public/Movement/JMDoorMovementComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCollisionWorldTransformAtFraction constinit property declarations **
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OpenFraction;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DirectionSign;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCollisionWorldTransformAtFraction constinit property declarations ****
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCollisionWorldTransformAtFraction Property Definitions *************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionWorldTransformAtFraction_Statics::NewProp_OpenFraction = { "OpenFraction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorMovementComponent_eventGetCollisionWorldTransformAtFraction_Parms, OpenFraction), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionWorldTransformAtFraction_Statics::NewProp_DirectionSign = { "DirectionSign", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorMovementComponent_eventGetCollisionWorldTransformAtFraction_Parms, DirectionSign), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionWorldTransformAtFraction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorMovementComponent_eventGetCollisionWorldTransformAtFraction_Parms, ReturnValue), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionWorldTransformAtFraction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionWorldTransformAtFraction_Statics::NewProp_OpenFraction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionWorldTransformAtFraction_Statics::NewProp_DirectionSign,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionWorldTransformAtFraction_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionWorldTransformAtFraction_Statics::PropPointers) < 2048);
// ********** End Function GetCollisionWorldTransformAtFraction Property Definitions ***************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionWorldTransformAtFraction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorMovementComponent, nullptr, "GetCollisionWorldTransformAtFraction", 	Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionWorldTransformAtFraction_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionWorldTransformAtFraction_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionWorldTransformAtFraction_Statics::JMDoorMovementComponent_eventGetCollisionWorldTransformAtFraction_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionWorldTransformAtFraction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionWorldTransformAtFraction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionWorldTransformAtFraction_Statics::JMDoorMovementComponent_eventGetCollisionWorldTransformAtFraction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionWorldTransformAtFraction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionWorldTransformAtFraction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorMovementComponent::execGetCollisionWorldTransformAtFraction)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_OpenFraction);
	P_GET_PROPERTY(FIntProperty,Z_Param_DirectionSign);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FTransform*)Z_Param__Result=P_THIS->GetCollisionWorldTransformAtFraction(Z_Param_OpenFraction,Z_Param_DirectionSign);
	P_NATIVE_END;
}
// ********** End Class UJMDoorMovementComponent Function GetCollisionWorldTransformAtFraction *****

// ********** Begin Class UJMDoorMovementComponent Function GetDirectionProbeWorldLocationAtFraction 
struct Z_Construct_UFunction_UJMDoorMovementComponent_GetDirectionProbeWorldLocationAtFraction_Statics
{
	struct JMDoorMovementComponent_eventGetDirectionProbeWorldLocationAtFraction_Parms
	{
		float OpenFraction;
		int32 DirectionSign;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Movement" },
		{ "ModuleRelativePath", "Public/Movement/JMDoorMovementComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDirectionProbeWorldLocationAtFraction constinit property declarations 
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OpenFraction;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DirectionSign;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDirectionProbeWorldLocationAtFraction constinit property declarations 
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDirectionProbeWorldLocationAtFraction Property Definitions *********
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMDoorMovementComponent_GetDirectionProbeWorldLocationAtFraction_Statics::NewProp_OpenFraction = { "OpenFraction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorMovementComponent_eventGetDirectionProbeWorldLocationAtFraction_Parms, OpenFraction), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UJMDoorMovementComponent_GetDirectionProbeWorldLocationAtFraction_Statics::NewProp_DirectionSign = { "DirectionSign", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorMovementComponent_eventGetDirectionProbeWorldLocationAtFraction_Parms, DirectionSign), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorMovementComponent_GetDirectionProbeWorldLocationAtFraction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorMovementComponent_eventGetDirectionProbeWorldLocationAtFraction_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorMovementComponent_GetDirectionProbeWorldLocationAtFraction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorMovementComponent_GetDirectionProbeWorldLocationAtFraction_Statics::NewProp_OpenFraction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorMovementComponent_GetDirectionProbeWorldLocationAtFraction_Statics::NewProp_DirectionSign,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorMovementComponent_GetDirectionProbeWorldLocationAtFraction_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_GetDirectionProbeWorldLocationAtFraction_Statics::PropPointers) < 2048);
// ********** End Function GetDirectionProbeWorldLocationAtFraction Property Definitions ***********
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorMovementComponent_GetDirectionProbeWorldLocationAtFraction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorMovementComponent, nullptr, "GetDirectionProbeWorldLocationAtFraction", 	Z_Construct_UFunction_UJMDoorMovementComponent_GetDirectionProbeWorldLocationAtFraction_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_GetDirectionProbeWorldLocationAtFraction_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorMovementComponent_GetDirectionProbeWorldLocationAtFraction_Statics::JMDoorMovementComponent_eventGetDirectionProbeWorldLocationAtFraction_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_GetDirectionProbeWorldLocationAtFraction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorMovementComponent_GetDirectionProbeWorldLocationAtFraction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorMovementComponent_GetDirectionProbeWorldLocationAtFraction_Statics::JMDoorMovementComponent_eventGetDirectionProbeWorldLocationAtFraction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorMovementComponent_GetDirectionProbeWorldLocationAtFraction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorMovementComponent_GetDirectionProbeWorldLocationAtFraction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorMovementComponent::execGetDirectionProbeWorldLocationAtFraction)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_OpenFraction);
	P_GET_PROPERTY(FIntProperty,Z_Param_DirectionSign);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->GetDirectionProbeWorldLocationAtFraction(Z_Param_OpenFraction,Z_Param_DirectionSign);
	P_NATIVE_END;
}
// ********** End Class UJMDoorMovementComponent Function GetDirectionProbeWorldLocationAtFraction *

// ********** Begin Class UJMDoorMovementComponent Function GetMovingComponent *********************
struct Z_Construct_UFunction_UJMDoorMovementComponent_GetMovingComponent_Statics
{
	struct JMDoorMovementComponent_eventGetMovingComponent_Parms
	{
		USceneComponent* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Movement" },
		{ "ModuleRelativePath", "Public/Movement/JMDoorMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetMovingComponent constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetMovingComponent constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetMovingComponent Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMDoorMovementComponent_GetMovingComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorMovementComponent_eventGetMovingComponent_Parms, ReturnValue), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorMovementComponent_GetMovingComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorMovementComponent_GetMovingComponent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_GetMovingComponent_Statics::PropPointers) < 2048);
// ********** End Function GetMovingComponent Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorMovementComponent_GetMovingComponent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorMovementComponent, nullptr, "GetMovingComponent", 	Z_Construct_UFunction_UJMDoorMovementComponent_GetMovingComponent_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_GetMovingComponent_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorMovementComponent_GetMovingComponent_Statics::JMDoorMovementComponent_eventGetMovingComponent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_GetMovingComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorMovementComponent_GetMovingComponent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorMovementComponent_GetMovingComponent_Statics::JMDoorMovementComponent_eventGetMovingComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorMovementComponent_GetMovingComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorMovementComponent_GetMovingComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorMovementComponent::execGetMovingComponent)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(USceneComponent**)Z_Param__Result=P_THIS->GetMovingComponent();
	P_NATIVE_END;
}
// ********** End Class UJMDoorMovementComponent Function GetMovingComponent ***********************

// ********** Begin Class UJMDoorMovementComponent Function GetRelativeTransformAtFraction *********
struct Z_Construct_UFunction_UJMDoorMovementComponent_GetRelativeTransformAtFraction_Statics
{
	struct JMDoorMovementComponent_eventGetRelativeTransformAtFraction_Parms
	{
		float OpenFraction;
		int32 DirectionSign;
		FTransform ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Movement" },
		{ "ModuleRelativePath", "Public/Movement/JMDoorMovementComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetRelativeTransformAtFraction constinit property declarations ********
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OpenFraction;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DirectionSign;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetRelativeTransformAtFraction constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetRelativeTransformAtFraction Property Definitions *******************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMDoorMovementComponent_GetRelativeTransformAtFraction_Statics::NewProp_OpenFraction = { "OpenFraction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorMovementComponent_eventGetRelativeTransformAtFraction_Parms, OpenFraction), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UJMDoorMovementComponent_GetRelativeTransformAtFraction_Statics::NewProp_DirectionSign = { "DirectionSign", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorMovementComponent_eventGetRelativeTransformAtFraction_Parms, DirectionSign), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorMovementComponent_GetRelativeTransformAtFraction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorMovementComponent_eventGetRelativeTransformAtFraction_Parms, ReturnValue), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorMovementComponent_GetRelativeTransformAtFraction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorMovementComponent_GetRelativeTransformAtFraction_Statics::NewProp_OpenFraction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorMovementComponent_GetRelativeTransformAtFraction_Statics::NewProp_DirectionSign,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorMovementComponent_GetRelativeTransformAtFraction_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_GetRelativeTransformAtFraction_Statics::PropPointers) < 2048);
// ********** End Function GetRelativeTransformAtFraction Property Definitions *********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorMovementComponent_GetRelativeTransformAtFraction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorMovementComponent, nullptr, "GetRelativeTransformAtFraction", 	Z_Construct_UFunction_UJMDoorMovementComponent_GetRelativeTransformAtFraction_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_GetRelativeTransformAtFraction_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorMovementComponent_GetRelativeTransformAtFraction_Statics::JMDoorMovementComponent_eventGetRelativeTransformAtFraction_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_GetRelativeTransformAtFraction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorMovementComponent_GetRelativeTransformAtFraction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorMovementComponent_GetRelativeTransformAtFraction_Statics::JMDoorMovementComponent_eventGetRelativeTransformAtFraction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorMovementComponent_GetRelativeTransformAtFraction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorMovementComponent_GetRelativeTransformAtFraction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorMovementComponent::execGetRelativeTransformAtFraction)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_OpenFraction);
	P_GET_PROPERTY(FIntProperty,Z_Param_DirectionSign);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FTransform*)Z_Param__Result=P_THIS->GetRelativeTransformAtFraction(Z_Param_OpenFraction,Z_Param_DirectionSign);
	P_NATIVE_END;
}
// ********** End Class UJMDoorMovementComponent Function GetRelativeTransformAtFraction ***********

// ********** Begin Class UJMDoorMovementComponent Function GetWorldTransformAtFraction ************
struct Z_Construct_UFunction_UJMDoorMovementComponent_GetWorldTransformAtFraction_Statics
{
	struct JMDoorMovementComponent_eventGetWorldTransformAtFraction_Parms
	{
		float OpenFraction;
		int32 DirectionSign;
		FTransform ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Movement" },
		{ "ModuleRelativePath", "Public/Movement/JMDoorMovementComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetWorldTransformAtFraction constinit property declarations ***********
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OpenFraction;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DirectionSign;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetWorldTransformAtFraction constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetWorldTransformAtFraction Property Definitions **********************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMDoorMovementComponent_GetWorldTransformAtFraction_Statics::NewProp_OpenFraction = { "OpenFraction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorMovementComponent_eventGetWorldTransformAtFraction_Parms, OpenFraction), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UJMDoorMovementComponent_GetWorldTransformAtFraction_Statics::NewProp_DirectionSign = { "DirectionSign", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorMovementComponent_eventGetWorldTransformAtFraction_Parms, DirectionSign), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorMovementComponent_GetWorldTransformAtFraction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorMovementComponent_eventGetWorldTransformAtFraction_Parms, ReturnValue), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorMovementComponent_GetWorldTransformAtFraction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorMovementComponent_GetWorldTransformAtFraction_Statics::NewProp_OpenFraction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorMovementComponent_GetWorldTransformAtFraction_Statics::NewProp_DirectionSign,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorMovementComponent_GetWorldTransformAtFraction_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_GetWorldTransformAtFraction_Statics::PropPointers) < 2048);
// ********** End Function GetWorldTransformAtFraction Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorMovementComponent_GetWorldTransformAtFraction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorMovementComponent, nullptr, "GetWorldTransformAtFraction", 	Z_Construct_UFunction_UJMDoorMovementComponent_GetWorldTransformAtFraction_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_GetWorldTransformAtFraction_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorMovementComponent_GetWorldTransformAtFraction_Statics::JMDoorMovementComponent_eventGetWorldTransformAtFraction_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_GetWorldTransformAtFraction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorMovementComponent_GetWorldTransformAtFraction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorMovementComponent_GetWorldTransformAtFraction_Statics::JMDoorMovementComponent_eventGetWorldTransformAtFraction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorMovementComponent_GetWorldTransformAtFraction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorMovementComponent_GetWorldTransformAtFraction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorMovementComponent::execGetWorldTransformAtFraction)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_OpenFraction);
	P_GET_PROPERTY(FIntProperty,Z_Param_DirectionSign);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FTransform*)Z_Param__Result=P_THIS->GetWorldTransformAtFraction(Z_Param_OpenFraction,Z_Param_DirectionSign);
	P_NATIVE_END;
}
// ********** End Class UJMDoorMovementComponent Function GetWorldTransformAtFraction **************

// ********** Begin Class UJMDoorMovementComponent Function InitializeMovingComponent **************
struct Z_Construct_UFunction_UJMDoorMovementComponent_InitializeMovingComponent_Statics
{
	struct JMDoorMovementComponent_eventInitializeMovingComponent_Parms
	{
		USceneComponent* InMovingComponent;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Movement" },
		{ "ModuleRelativePath", "Public/Movement/JMDoorMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InMovingComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function InitializeMovingComponent constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InMovingComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InitializeMovingComponent constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InitializeMovingComponent Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMDoorMovementComponent_InitializeMovingComponent_Statics::NewProp_InMovingComponent = { "InMovingComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorMovementComponent_eventInitializeMovingComponent_Parms, InMovingComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InMovingComponent_MetaData), NewProp_InMovingComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorMovementComponent_InitializeMovingComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorMovementComponent_InitializeMovingComponent_Statics::NewProp_InMovingComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_InitializeMovingComponent_Statics::PropPointers) < 2048);
// ********** End Function InitializeMovingComponent Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorMovementComponent_InitializeMovingComponent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorMovementComponent, nullptr, "InitializeMovingComponent", 	Z_Construct_UFunction_UJMDoorMovementComponent_InitializeMovingComponent_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_InitializeMovingComponent_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorMovementComponent_InitializeMovingComponent_Statics::JMDoorMovementComponent_eventInitializeMovingComponent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_InitializeMovingComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorMovementComponent_InitializeMovingComponent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorMovementComponent_InitializeMovingComponent_Statics::JMDoorMovementComponent_eventInitializeMovingComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorMovementComponent_InitializeMovingComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorMovementComponent_InitializeMovingComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorMovementComponent::execInitializeMovingComponent)
{
	P_GET_OBJECT(USceneComponent,Z_Param_InMovingComponent);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeMovingComponent(Z_Param_InMovingComponent);
	P_NATIVE_END;
}
// ********** End Class UJMDoorMovementComponent Function InitializeMovingComponent ****************

// ********** Begin Class UJMDoorMovementComponent Function SetCollisionComponent ******************
struct Z_Construct_UFunction_UJMDoorMovementComponent_SetCollisionComponent_Statics
{
	struct JMDoorMovementComponent_eventSetCollisionComponent_Parms
	{
		UPrimitiveComponent* InCollisionComponent;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Movement" },
		{ "ModuleRelativePath", "Public/Movement/JMDoorMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InCollisionComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetCollisionComponent constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InCollisionComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCollisionComponent constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCollisionComponent Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMDoorMovementComponent_SetCollisionComponent_Statics::NewProp_InCollisionComponent = { "InCollisionComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorMovementComponent_eventSetCollisionComponent_Parms, InCollisionComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InCollisionComponent_MetaData), NewProp_InCollisionComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorMovementComponent_SetCollisionComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorMovementComponent_SetCollisionComponent_Statics::NewProp_InCollisionComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_SetCollisionComponent_Statics::PropPointers) < 2048);
// ********** End Function SetCollisionComponent Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorMovementComponent_SetCollisionComponent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorMovementComponent, nullptr, "SetCollisionComponent", 	Z_Construct_UFunction_UJMDoorMovementComponent_SetCollisionComponent_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_SetCollisionComponent_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorMovementComponent_SetCollisionComponent_Statics::JMDoorMovementComponent_eventSetCollisionComponent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_SetCollisionComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorMovementComponent_SetCollisionComponent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorMovementComponent_SetCollisionComponent_Statics::JMDoorMovementComponent_eventSetCollisionComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorMovementComponent_SetCollisionComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorMovementComponent_SetCollisionComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorMovementComponent::execSetCollisionComponent)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_InCollisionComponent);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCollisionComponent(Z_Param_InCollisionComponent);
	P_NATIVE_END;
}
// ********** End Class UJMDoorMovementComponent Function SetCollisionComponent ********************

// ********** Begin Class UJMDoorMovementComponent Function SetDirectionProbeComponent *************
struct Z_Construct_UFunction_UJMDoorMovementComponent_SetDirectionProbeComponent_Statics
{
	struct JMDoorMovementComponent_eventSetDirectionProbeComponent_Parms
	{
		USceneComponent* InDirectionProbeComponent;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Movement" },
		{ "ModuleRelativePath", "Public/Movement/JMDoorMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InDirectionProbeComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetDirectionProbeComponent constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InDirectionProbeComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetDirectionProbeComponent constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetDirectionProbeComponent Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMDoorMovementComponent_SetDirectionProbeComponent_Statics::NewProp_InDirectionProbeComponent = { "InDirectionProbeComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorMovementComponent_eventSetDirectionProbeComponent_Parms, InDirectionProbeComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InDirectionProbeComponent_MetaData), NewProp_InDirectionProbeComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorMovementComponent_SetDirectionProbeComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorMovementComponent_SetDirectionProbeComponent_Statics::NewProp_InDirectionProbeComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_SetDirectionProbeComponent_Statics::PropPointers) < 2048);
// ********** End Function SetDirectionProbeComponent Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorMovementComponent_SetDirectionProbeComponent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorMovementComponent, nullptr, "SetDirectionProbeComponent", 	Z_Construct_UFunction_UJMDoorMovementComponent_SetDirectionProbeComponent_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_SetDirectionProbeComponent_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorMovementComponent_SetDirectionProbeComponent_Statics::JMDoorMovementComponent_eventSetDirectionProbeComponent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_SetDirectionProbeComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorMovementComponent_SetDirectionProbeComponent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorMovementComponent_SetDirectionProbeComponent_Statics::JMDoorMovementComponent_eventSetDirectionProbeComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorMovementComponent_SetDirectionProbeComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorMovementComponent_SetDirectionProbeComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorMovementComponent::execSetDirectionProbeComponent)
{
	P_GET_OBJECT(USceneComponent,Z_Param_InDirectionProbeComponent);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDirectionProbeComponent(Z_Param_InDirectionProbeComponent);
	P_NATIVE_END;
}
// ********** End Class UJMDoorMovementComponent Function SetDirectionProbeComponent ***************

// ********** Begin Class UJMDoorMovementComponent Function SetOpenFraction ************************
struct Z_Construct_UFunction_UJMDoorMovementComponent_SetOpenFraction_Statics
{
	struct JMDoorMovementComponent_eventSetOpenFraction_Parms
	{
		float OpenFraction;
		int32 DirectionSign;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Movement" },
		{ "ModuleRelativePath", "Public/Movement/JMDoorMovementComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetOpenFraction constinit property declarations ***********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OpenFraction;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DirectionSign;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetOpenFraction constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetOpenFraction Property Definitions **********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMDoorMovementComponent_SetOpenFraction_Statics::NewProp_OpenFraction = { "OpenFraction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorMovementComponent_eventSetOpenFraction_Parms, OpenFraction), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UJMDoorMovementComponent_SetOpenFraction_Statics::NewProp_DirectionSign = { "DirectionSign", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorMovementComponent_eventSetOpenFraction_Parms, DirectionSign), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorMovementComponent_SetOpenFraction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorMovementComponent_SetOpenFraction_Statics::NewProp_OpenFraction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorMovementComponent_SetOpenFraction_Statics::NewProp_DirectionSign,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_SetOpenFraction_Statics::PropPointers) < 2048);
// ********** End Function SetOpenFraction Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorMovementComponent_SetOpenFraction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorMovementComponent, nullptr, "SetOpenFraction", 	Z_Construct_UFunction_UJMDoorMovementComponent_SetOpenFraction_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_SetOpenFraction_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorMovementComponent_SetOpenFraction_Statics::JMDoorMovementComponent_eventSetOpenFraction_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorMovementComponent_SetOpenFraction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorMovementComponent_SetOpenFraction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorMovementComponent_SetOpenFraction_Statics::JMDoorMovementComponent_eventSetOpenFraction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorMovementComponent_SetOpenFraction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorMovementComponent_SetOpenFraction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorMovementComponent::execSetOpenFraction)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_OpenFraction);
	P_GET_PROPERTY(FIntProperty,Z_Param_DirectionSign);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetOpenFraction(Z_Param_OpenFraction,Z_Param_DirectionSign);
	P_NATIVE_END;
}
// ********** End Class UJMDoorMovementComponent Function SetOpenFraction **************************

// ********** Begin Class UJMDoorMovementComponent *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMDoorMovementComponent;
UClass* UJMDoorMovementComponent::GetPrivateStaticClass()
{
	using TClass = UJMDoorMovementComponent;
	if (!Z_Registration_Info_UClass_UJMDoorMovementComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMDoorMovementComponent"),
			Z_Registration_Info_UClass_UJMDoorMovementComponent.InnerSingleton,
			StaticRegisterNativesUJMDoorMovementComponent,
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
	return Z_Registration_Info_UClass_UJMDoorMovementComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMDoorMovementComponent_NoRegister()
{
	return UJMDoorMovementComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMDoorMovementComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JMGameplay" },
		{ "IncludePath", "Movement/JMDoorMovementComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Movement/JMDoorMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MovingComponent_MetaData[] = {
		{ "Category", "JM Door|Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Runtime wiring only. Keep cross-component references out of inline Details\n// customization to prevent recursive component expansion in the editor.\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Movement/JMDoorMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Runtime wiring only. Keep cross-component references out of inline Details\ncustomization to prevent recursive component expansion in the editor." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollisionComponent_MetaData[] = {
		{ "Category", "JM Door|Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The primitive used for obstruction checks. It may be a child of MovingComponent. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Movement/JMDoorMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The primitive used for obstruction checks. It may be a child of MovingComponent." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DirectionProbeComponent_MetaData[] = {
		{ "Category", "JM Door|Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** A child component whose future position represents the moving door leaf. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Movement/JMDoorMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A child component whose future position represents the moving door leaf." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClosedRelativeTransform_MetaData[] = {
		{ "Category", "JM Door|Movement" },
		{ "ModuleRelativePath", "Public/Movement/JMDoorMovementComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMDoorMovementComponent constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MovingComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CollisionComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DirectionProbeComponent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ClosedRelativeTransform;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMDoorMovementComponent constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CalculateRelativeTransform"), .Pointer = &UJMDoorMovementComponent::execCalculateRelativeTransform },
		{ .NameUTF8 = UTF8TEXT("GetCollisionComponent"), .Pointer = &UJMDoorMovementComponent::execGetCollisionComponent },
		{ .NameUTF8 = UTF8TEXT("GetCollisionWorldTransformAtFraction"), .Pointer = &UJMDoorMovementComponent::execGetCollisionWorldTransformAtFraction },
		{ .NameUTF8 = UTF8TEXT("GetDirectionProbeWorldLocationAtFraction"), .Pointer = &UJMDoorMovementComponent::execGetDirectionProbeWorldLocationAtFraction },
		{ .NameUTF8 = UTF8TEXT("GetMovingComponent"), .Pointer = &UJMDoorMovementComponent::execGetMovingComponent },
		{ .NameUTF8 = UTF8TEXT("GetRelativeTransformAtFraction"), .Pointer = &UJMDoorMovementComponent::execGetRelativeTransformAtFraction },
		{ .NameUTF8 = UTF8TEXT("GetWorldTransformAtFraction"), .Pointer = &UJMDoorMovementComponent::execGetWorldTransformAtFraction },
		{ .NameUTF8 = UTF8TEXT("InitializeMovingComponent"), .Pointer = &UJMDoorMovementComponent::execInitializeMovingComponent },
		{ .NameUTF8 = UTF8TEXT("SetCollisionComponent"), .Pointer = &UJMDoorMovementComponent::execSetCollisionComponent },
		{ .NameUTF8 = UTF8TEXT("SetDirectionProbeComponent"), .Pointer = &UJMDoorMovementComponent::execSetDirectionProbeComponent },
		{ .NameUTF8 = UTF8TEXT("SetOpenFraction"), .Pointer = &UJMDoorMovementComponent::execSetOpenFraction },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMDoorMovementComponent_CalculateRelativeTransform, "CalculateRelativeTransform" }, // 2980276959
		{ &Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionComponent, "GetCollisionComponent" }, // 3220143917
		{ &Z_Construct_UFunction_UJMDoorMovementComponent_GetCollisionWorldTransformAtFraction, "GetCollisionWorldTransformAtFraction" }, // 2341999904
		{ &Z_Construct_UFunction_UJMDoorMovementComponent_GetDirectionProbeWorldLocationAtFraction, "GetDirectionProbeWorldLocationAtFraction" }, // 3862043728
		{ &Z_Construct_UFunction_UJMDoorMovementComponent_GetMovingComponent, "GetMovingComponent" }, // 2208484493
		{ &Z_Construct_UFunction_UJMDoorMovementComponent_GetRelativeTransformAtFraction, "GetRelativeTransformAtFraction" }, // 2887319585
		{ &Z_Construct_UFunction_UJMDoorMovementComponent_GetWorldTransformAtFraction, "GetWorldTransformAtFraction" }, // 2666781721
		{ &Z_Construct_UFunction_UJMDoorMovementComponent_InitializeMovingComponent, "InitializeMovingComponent" }, // 4043983666
		{ &Z_Construct_UFunction_UJMDoorMovementComponent_SetCollisionComponent, "SetCollisionComponent" }, // 3375119798
		{ &Z_Construct_UFunction_UJMDoorMovementComponent_SetDirectionProbeComponent, "SetDirectionProbeComponent" }, // 1971250266
		{ &Z_Construct_UFunction_UJMDoorMovementComponent_SetOpenFraction, "SetOpenFraction" }, // 1486981271
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMDoorMovementComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMDoorMovementComponent_Statics

// ********** Begin Class UJMDoorMovementComponent Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMDoorMovementComponent_Statics::NewProp_MovingComponent = { "MovingComponent", nullptr, (EPropertyFlags)0x011400000008201c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorMovementComponent, MovingComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MovingComponent_MetaData), NewProp_MovingComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMDoorMovementComponent_Statics::NewProp_CollisionComponent = { "CollisionComponent", nullptr, (EPropertyFlags)0x011400000008201c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorMovementComponent, CollisionComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollisionComponent_MetaData), NewProp_CollisionComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMDoorMovementComponent_Statics::NewProp_DirectionProbeComponent = { "DirectionProbeComponent", nullptr, (EPropertyFlags)0x011400000008201c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorMovementComponent, DirectionProbeComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DirectionProbeComponent_MetaData), NewProp_DirectionProbeComponent_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMDoorMovementComponent_Statics::NewProp_ClosedRelativeTransform = { "ClosedRelativeTransform", nullptr, (EPropertyFlags)0x0020080000020815, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorMovementComponent, ClosedRelativeTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClosedRelativeTransform_MetaData), NewProp_ClosedRelativeTransform_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMDoorMovementComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorMovementComponent_Statics::NewProp_MovingComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorMovementComponent_Statics::NewProp_CollisionComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorMovementComponent_Statics::NewProp_DirectionProbeComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorMovementComponent_Statics::NewProp_ClosedRelativeTransform,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorMovementComponent_Statics::PropPointers) < 2048);
// ********** End Class UJMDoorMovementComponent Property Definitions ******************************
UObject* (*const Z_Construct_UClass_UJMDoorMovementComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorMovementComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMDoorMovementComponent_Statics::ClassParams = {
	&UJMDoorMovementComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMDoorMovementComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorMovementComponent_Statics::PropPointers),
	0,
	0x00B000A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorMovementComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMDoorMovementComponent_Statics::Class_MetaDataParams)
};
void UJMDoorMovementComponent::StaticRegisterNativesUJMDoorMovementComponent()
{
	UClass* Class = UJMDoorMovementComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMDoorMovementComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMDoorMovementComponent()
{
	if (!Z_Registration_Info_UClass_UJMDoorMovementComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMDoorMovementComponent.OuterSingleton, Z_Construct_UClass_UJMDoorMovementComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMDoorMovementComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMDoorMovementComponent);
UJMDoorMovementComponent::~UJMDoorMovementComponent() {}
// ********** End Class UJMDoorMovementComponent ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMDoorMovementComponent_h__Script_JMDoorRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMDoorMovementComponent, UJMDoorMovementComponent::StaticClass, TEXT("UJMDoorMovementComponent"), &Z_Registration_Info_UClass_UJMDoorMovementComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMDoorMovementComponent), 3260632034U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMDoorMovementComponent_h__Script_JMDoorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMDoorMovementComponent_h__Script_JMDoorRuntime_414163325{
	TEXT("/Script/JMDoorRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMDoorMovementComponent_h__Script_JMDoorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMDoorMovementComponent_h__Script_JMDoorRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
