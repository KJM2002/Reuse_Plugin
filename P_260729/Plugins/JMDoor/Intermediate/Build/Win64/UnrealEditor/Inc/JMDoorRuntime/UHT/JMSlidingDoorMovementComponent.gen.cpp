// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Movement/JMSlidingDoorMovementComponent.h"
#include "Serialization/ArchiveUObjectFromStructuredArchive.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMSlidingDoorMovementComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorMovementComponent();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMSlidingDoorMovementComponent();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMSlidingDoorMovementComponent_NoRegister();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel();
UPackage* Z_Construct_UPackage__Script_JMDoorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMSlidingDoorMovementComponent Function GetPanelCollisionComponent ******
struct Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionComponent_Statics
{
	struct JMSlidingDoorMovementComponent_eventGetPanelCollisionComponent_Parms
	{
		EJMSlideDoorPanel Panel;
		UPrimitiveComponent* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Slide Door" },
		{ "ModuleRelativePath", "Public/Movement/JMSlidingDoorMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPanelCollisionComponent constinit property declarations ************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Panel_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Panel;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPanelCollisionComponent constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPanelCollisionComponent Property Definitions ***********************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionComponent_Statics::NewProp_Panel_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionComponent_Statics::NewProp_Panel = { "Panel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMSlidingDoorMovementComponent_eventGetPanelCollisionComponent_Parms, Panel), Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel, METADATA_PARAMS(0, nullptr) }; // 1478343840
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMSlidingDoorMovementComponent_eventGetPanelCollisionComponent_Parms, ReturnValue), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionComponent_Statics::NewProp_Panel_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionComponent_Statics::NewProp_Panel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionComponent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionComponent_Statics::PropPointers) < 2048);
// ********** End Function GetPanelCollisionComponent Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionComponent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMSlidingDoorMovementComponent, nullptr, "GetPanelCollisionComponent", 	Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionComponent_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionComponent_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionComponent_Statics::JMSlidingDoorMovementComponent_eventGetPanelCollisionComponent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionComponent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionComponent_Statics::JMSlidingDoorMovementComponent_eventGetPanelCollisionComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMSlidingDoorMovementComponent::execGetPanelCollisionComponent)
{
	P_GET_ENUM(EJMSlideDoorPanel,Z_Param_Panel);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UPrimitiveComponent**)Z_Param__Result=P_THIS->GetPanelCollisionComponent(EJMSlideDoorPanel(Z_Param_Panel));
	P_NATIVE_END;
}
// ********** End Class UJMSlidingDoorMovementComponent Function GetPanelCollisionComponent ********

// ********** Begin Class UJMSlidingDoorMovementComponent Function GetPanelCollisionWorldTransformAtFraction 
struct Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionWorldTransformAtFraction_Statics
{
	struct JMSlidingDoorMovementComponent_eventGetPanelCollisionWorldTransformAtFraction_Parms
	{
		EJMSlideDoorPanel Panel;
		float OpenFraction;
		FTransform ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Slide Door" },
		{ "ModuleRelativePath", "Public/Movement/JMSlidingDoorMovementComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPanelCollisionWorldTransformAtFraction constinit property declarations 
	static const UECodeGen_Private::FBytePropertyParams NewProp_Panel_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Panel;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OpenFraction;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPanelCollisionWorldTransformAtFraction constinit property declarations 
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPanelCollisionWorldTransformAtFraction Property Definitions ********
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionWorldTransformAtFraction_Statics::NewProp_Panel_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionWorldTransformAtFraction_Statics::NewProp_Panel = { "Panel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMSlidingDoorMovementComponent_eventGetPanelCollisionWorldTransformAtFraction_Parms, Panel), Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel, METADATA_PARAMS(0, nullptr) }; // 1478343840
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionWorldTransformAtFraction_Statics::NewProp_OpenFraction = { "OpenFraction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMSlidingDoorMovementComponent_eventGetPanelCollisionWorldTransformAtFraction_Parms, OpenFraction), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionWorldTransformAtFraction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMSlidingDoorMovementComponent_eventGetPanelCollisionWorldTransformAtFraction_Parms, ReturnValue), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionWorldTransformAtFraction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionWorldTransformAtFraction_Statics::NewProp_Panel_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionWorldTransformAtFraction_Statics::NewProp_Panel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionWorldTransformAtFraction_Statics::NewProp_OpenFraction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionWorldTransformAtFraction_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionWorldTransformAtFraction_Statics::PropPointers) < 2048);
// ********** End Function GetPanelCollisionWorldTransformAtFraction Property Definitions **********
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionWorldTransformAtFraction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMSlidingDoorMovementComponent, nullptr, "GetPanelCollisionWorldTransformAtFraction", 	Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionWorldTransformAtFraction_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionWorldTransformAtFraction_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionWorldTransformAtFraction_Statics::JMSlidingDoorMovementComponent_eventGetPanelCollisionWorldTransformAtFraction_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionWorldTransformAtFraction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionWorldTransformAtFraction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionWorldTransformAtFraction_Statics::JMSlidingDoorMovementComponent_eventGetPanelCollisionWorldTransformAtFraction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionWorldTransformAtFraction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionWorldTransformAtFraction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMSlidingDoorMovementComponent::execGetPanelCollisionWorldTransformAtFraction)
{
	P_GET_ENUM(EJMSlideDoorPanel,Z_Param_Panel);
	P_GET_PROPERTY(FFloatProperty,Z_Param_OpenFraction);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FTransform*)Z_Param__Result=P_THIS->GetPanelCollisionWorldTransformAtFraction(EJMSlideDoorPanel(Z_Param_Panel),Z_Param_OpenFraction);
	P_NATIVE_END;
}
// ********** End Class UJMSlidingDoorMovementComponent Function GetPanelCollisionWorldTransformAtFraction 

// ********** Begin Class UJMSlidingDoorMovementComponent Function GetPanelWorldTransformAtFraction 
struct Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelWorldTransformAtFraction_Statics
{
	struct JMSlidingDoorMovementComponent_eventGetPanelWorldTransformAtFraction_Parms
	{
		EJMSlideDoorPanel Panel;
		float OpenFraction;
		FTransform ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Slide Door" },
		{ "ModuleRelativePath", "Public/Movement/JMSlidingDoorMovementComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPanelWorldTransformAtFraction constinit property declarations ******
	static const UECodeGen_Private::FBytePropertyParams NewProp_Panel_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Panel;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OpenFraction;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPanelWorldTransformAtFraction constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPanelWorldTransformAtFraction Property Definitions *****************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelWorldTransformAtFraction_Statics::NewProp_Panel_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelWorldTransformAtFraction_Statics::NewProp_Panel = { "Panel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMSlidingDoorMovementComponent_eventGetPanelWorldTransformAtFraction_Parms, Panel), Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel, METADATA_PARAMS(0, nullptr) }; // 1478343840
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelWorldTransformAtFraction_Statics::NewProp_OpenFraction = { "OpenFraction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMSlidingDoorMovementComponent_eventGetPanelWorldTransformAtFraction_Parms, OpenFraction), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelWorldTransformAtFraction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMSlidingDoorMovementComponent_eventGetPanelWorldTransformAtFraction_Parms, ReturnValue), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelWorldTransformAtFraction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelWorldTransformAtFraction_Statics::NewProp_Panel_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelWorldTransformAtFraction_Statics::NewProp_Panel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelWorldTransformAtFraction_Statics::NewProp_OpenFraction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelWorldTransformAtFraction_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelWorldTransformAtFraction_Statics::PropPointers) < 2048);
// ********** End Function GetPanelWorldTransformAtFraction Property Definitions *******************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelWorldTransformAtFraction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMSlidingDoorMovementComponent, nullptr, "GetPanelWorldTransformAtFraction", 	Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelWorldTransformAtFraction_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelWorldTransformAtFraction_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelWorldTransformAtFraction_Statics::JMSlidingDoorMovementComponent_eventGetPanelWorldTransformAtFraction_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelWorldTransformAtFraction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelWorldTransformAtFraction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelWorldTransformAtFraction_Statics::JMSlidingDoorMovementComponent_eventGetPanelWorldTransformAtFraction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelWorldTransformAtFraction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelWorldTransformAtFraction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMSlidingDoorMovementComponent::execGetPanelWorldTransformAtFraction)
{
	P_GET_ENUM(EJMSlideDoorPanel,Z_Param_Panel);
	P_GET_PROPERTY(FFloatProperty,Z_Param_OpenFraction);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FTransform*)Z_Param__Result=P_THIS->GetPanelWorldTransformAtFraction(EJMSlideDoorPanel(Z_Param_Panel),Z_Param_OpenFraction);
	P_NATIVE_END;
}
// ********** End Class UJMSlidingDoorMovementComponent Function GetPanelWorldTransformAtFraction **

// ********** Begin Class UJMSlidingDoorMovementComponent Function HasPanel ************************
struct Z_Construct_UFunction_UJMSlidingDoorMovementComponent_HasPanel_Statics
{
	struct JMSlidingDoorMovementComponent_eventHasPanel_Parms
	{
		EJMSlideDoorPanel Panel;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Slide Door" },
		{ "ModuleRelativePath", "Public/Movement/JMSlidingDoorMovementComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HasPanel constinit property declarations ******************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Panel_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Panel;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasPanel constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasPanel Property Definitions *****************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_HasPanel_Statics::NewProp_Panel_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_HasPanel_Statics::NewProp_Panel = { "Panel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMSlidingDoorMovementComponent_eventHasPanel_Parms, Panel), Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel, METADATA_PARAMS(0, nullptr) }; // 1478343840
void Z_Construct_UFunction_UJMSlidingDoorMovementComponent_HasPanel_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMSlidingDoorMovementComponent_eventHasPanel_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_HasPanel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMSlidingDoorMovementComponent_eventHasPanel_Parms), &Z_Construct_UFunction_UJMSlidingDoorMovementComponent_HasPanel_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMSlidingDoorMovementComponent_HasPanel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMSlidingDoorMovementComponent_HasPanel_Statics::NewProp_Panel_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMSlidingDoorMovementComponent_HasPanel_Statics::NewProp_Panel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMSlidingDoorMovementComponent_HasPanel_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_HasPanel_Statics::PropPointers) < 2048);
// ********** End Function HasPanel Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_HasPanel_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMSlidingDoorMovementComponent, nullptr, "HasPanel", 	Z_Construct_UFunction_UJMSlidingDoorMovementComponent_HasPanel_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_HasPanel_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_HasPanel_Statics::JMSlidingDoorMovementComponent_eventHasPanel_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_HasPanel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMSlidingDoorMovementComponent_HasPanel_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_HasPanel_Statics::JMSlidingDoorMovementComponent_eventHasPanel_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMSlidingDoorMovementComponent_HasPanel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMSlidingDoorMovementComponent_HasPanel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMSlidingDoorMovementComponent::execHasPanel)
{
	P_GET_ENUM(EJMSlideDoorPanel,Z_Param_Panel);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->HasPanel(EJMSlideDoorPanel(Z_Param_Panel));
	P_NATIVE_END;
}
// ********** End Class UJMSlidingDoorMovementComponent Function HasPanel **************************

// ********** Begin Class UJMSlidingDoorMovementComponent Function InitializeDoorBComponent ********
struct Z_Construct_UFunction_UJMSlidingDoorMovementComponent_InitializeDoorBComponent_Statics
{
	struct JMSlidingDoorMovementComponent_eventInitializeDoorBComponent_Parms
	{
		USceneComponent* InMovingComponent;
		UPrimitiveComponent* InCollisionComponent;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Slide Door" },
		{ "ModuleRelativePath", "Public/Movement/JMSlidingDoorMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InMovingComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InCollisionComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function InitializeDoorBComponent constinit property declarations **************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InMovingComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InCollisionComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InitializeDoorBComponent constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InitializeDoorBComponent Property Definitions *************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_InitializeDoorBComponent_Statics::NewProp_InMovingComponent = { "InMovingComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMSlidingDoorMovementComponent_eventInitializeDoorBComponent_Parms, InMovingComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InMovingComponent_MetaData), NewProp_InMovingComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_InitializeDoorBComponent_Statics::NewProp_InCollisionComponent = { "InCollisionComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMSlidingDoorMovementComponent_eventInitializeDoorBComponent_Parms, InCollisionComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InCollisionComponent_MetaData), NewProp_InCollisionComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMSlidingDoorMovementComponent_InitializeDoorBComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMSlidingDoorMovementComponent_InitializeDoorBComponent_Statics::NewProp_InMovingComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMSlidingDoorMovementComponent_InitializeDoorBComponent_Statics::NewProp_InCollisionComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_InitializeDoorBComponent_Statics::PropPointers) < 2048);
// ********** End Function InitializeDoorBComponent Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_InitializeDoorBComponent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMSlidingDoorMovementComponent, nullptr, "InitializeDoorBComponent", 	Z_Construct_UFunction_UJMSlidingDoorMovementComponent_InitializeDoorBComponent_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_InitializeDoorBComponent_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_InitializeDoorBComponent_Statics::JMSlidingDoorMovementComponent_eventInitializeDoorBComponent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_InitializeDoorBComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMSlidingDoorMovementComponent_InitializeDoorBComponent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_InitializeDoorBComponent_Statics::JMSlidingDoorMovementComponent_eventInitializeDoorBComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMSlidingDoorMovementComponent_InitializeDoorBComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMSlidingDoorMovementComponent_InitializeDoorBComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMSlidingDoorMovementComponent::execInitializeDoorBComponent)
{
	P_GET_OBJECT(USceneComponent,Z_Param_InMovingComponent);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_InCollisionComponent);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeDoorBComponent(Z_Param_InMovingComponent,Z_Param_InCollisionComponent);
	P_NATIVE_END;
}
// ********** End Class UJMSlidingDoorMovementComponent Function InitializeDoorBComponent **********

// ********** Begin Class UJMSlidingDoorMovementComponent Function IsLegacySinglePanelAsset ********
struct Z_Construct_UFunction_UJMSlidingDoorMovementComponent_IsLegacySinglePanelAsset_Statics
{
	struct JMSlidingDoorMovementComponent_eventIsLegacySinglePanelAsset_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Slide Door" },
		{ "ModuleRelativePath", "Public/Movement/JMSlidingDoorMovementComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsLegacySinglePanelAsset constinit property declarations **************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsLegacySinglePanelAsset constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsLegacySinglePanelAsset Property Definitions *************************
void Z_Construct_UFunction_UJMSlidingDoorMovementComponent_IsLegacySinglePanelAsset_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMSlidingDoorMovementComponent_eventIsLegacySinglePanelAsset_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_IsLegacySinglePanelAsset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMSlidingDoorMovementComponent_eventIsLegacySinglePanelAsset_Parms), &Z_Construct_UFunction_UJMSlidingDoorMovementComponent_IsLegacySinglePanelAsset_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMSlidingDoorMovementComponent_IsLegacySinglePanelAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMSlidingDoorMovementComponent_IsLegacySinglePanelAsset_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_IsLegacySinglePanelAsset_Statics::PropPointers) < 2048);
// ********** End Function IsLegacySinglePanelAsset Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_IsLegacySinglePanelAsset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMSlidingDoorMovementComponent, nullptr, "IsLegacySinglePanelAsset", 	Z_Construct_UFunction_UJMSlidingDoorMovementComponent_IsLegacySinglePanelAsset_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_IsLegacySinglePanelAsset_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_IsLegacySinglePanelAsset_Statics::JMSlidingDoorMovementComponent_eventIsLegacySinglePanelAsset_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_IsLegacySinglePanelAsset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMSlidingDoorMovementComponent_IsLegacySinglePanelAsset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_IsLegacySinglePanelAsset_Statics::JMSlidingDoorMovementComponent_eventIsLegacySinglePanelAsset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMSlidingDoorMovementComponent_IsLegacySinglePanelAsset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMSlidingDoorMovementComponent_IsLegacySinglePanelAsset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMSlidingDoorMovementComponent::execIsLegacySinglePanelAsset)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsLegacySinglePanelAsset();
	P_NATIVE_END;
}
// ********** End Class UJMSlidingDoorMovementComponent Function IsLegacySinglePanelAsset **********

// ********** Begin Class UJMSlidingDoorMovementComponent Function SetPanelOpenFraction ************
struct Z_Construct_UFunction_UJMSlidingDoorMovementComponent_SetPanelOpenFraction_Statics
{
	struct JMSlidingDoorMovementComponent_eventSetPanelOpenFraction_Parms
	{
		EJMSlideDoorPanel Panel;
		float OpenFraction;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Slide Door" },
		{ "ModuleRelativePath", "Public/Movement/JMSlidingDoorMovementComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetPanelOpenFraction constinit property declarations ******************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Panel_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Panel;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OpenFraction;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPanelOpenFraction constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPanelOpenFraction Property Definitions *****************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_SetPanelOpenFraction_Statics::NewProp_Panel_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_SetPanelOpenFraction_Statics::NewProp_Panel = { "Panel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMSlidingDoorMovementComponent_eventSetPanelOpenFraction_Parms, Panel), Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel, METADATA_PARAMS(0, nullptr) }; // 1478343840
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_SetPanelOpenFraction_Statics::NewProp_OpenFraction = { "OpenFraction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMSlidingDoorMovementComponent_eventSetPanelOpenFraction_Parms, OpenFraction), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMSlidingDoorMovementComponent_SetPanelOpenFraction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMSlidingDoorMovementComponent_SetPanelOpenFraction_Statics::NewProp_Panel_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMSlidingDoorMovementComponent_SetPanelOpenFraction_Statics::NewProp_Panel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMSlidingDoorMovementComponent_SetPanelOpenFraction_Statics::NewProp_OpenFraction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_SetPanelOpenFraction_Statics::PropPointers) < 2048);
// ********** End Function SetPanelOpenFraction Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMSlidingDoorMovementComponent_SetPanelOpenFraction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMSlidingDoorMovementComponent, nullptr, "SetPanelOpenFraction", 	Z_Construct_UFunction_UJMSlidingDoorMovementComponent_SetPanelOpenFraction_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_SetPanelOpenFraction_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_SetPanelOpenFraction_Statics::JMSlidingDoorMovementComponent_eventSetPanelOpenFraction_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_SetPanelOpenFraction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMSlidingDoorMovementComponent_SetPanelOpenFraction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMSlidingDoorMovementComponent_SetPanelOpenFraction_Statics::JMSlidingDoorMovementComponent_eventSetPanelOpenFraction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMSlidingDoorMovementComponent_SetPanelOpenFraction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMSlidingDoorMovementComponent_SetPanelOpenFraction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMSlidingDoorMovementComponent::execSetPanelOpenFraction)
{
	P_GET_ENUM(EJMSlideDoorPanel,Z_Param_Panel);
	P_GET_PROPERTY(FFloatProperty,Z_Param_OpenFraction);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPanelOpenFraction(EJMSlideDoorPanel(Z_Param_Panel),Z_Param_OpenFraction);
	P_NATIVE_END;
}
// ********** End Class UJMSlidingDoorMovementComponent Function SetPanelOpenFraction **************

// ********** Begin Class UJMSlidingDoorMovementComponent ******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMSlidingDoorMovementComponent;
UClass* UJMSlidingDoorMovementComponent::GetPrivateStaticClass()
{
	using TClass = UJMSlidingDoorMovementComponent;
	if (!Z_Registration_Info_UClass_UJMSlidingDoorMovementComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMSlidingDoorMovementComponent"),
			Z_Registration_Info_UClass_UJMSlidingDoorMovementComponent.InnerSingleton,
			StaticRegisterNativesUJMSlidingDoorMovementComponent,
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
	return Z_Registration_Info_UClass_UJMSlidingDoorMovementComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMSlidingDoorMovementComponent_NoRegister()
{
	return UJMSlidingDoorMovementComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JMGameplay" },
		{ "IncludePath", "Movement/JMSlidingDoorMovementComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Movement/JMSlidingDoorMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LocalOpenOffset_MetaData[] = {
		{ "Category", "JM Door|Slide Door|Legacy" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Legacy single-panel offset. Existing assets continue to use this as panel A. */" },
#endif
		{ "DeprecatedProperty", "" },
		{ "DeprecationMessage", "Use Door A Open Offset." },
		{ "ModuleRelativePath", "Public/Movement/JMSlidingDoorMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Legacy single-panel offset. Existing assets continue to use this as panel A." },
#endif
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bReverseOffsetWithDirection_MetaData[] = {
		{ "Category", "JM Door|Slide Door|Legacy" },
		{ "DeprecatedProperty", "" },
		{ "DeprecationMessage", "Panel directions are fixed in the dual-panel layout." },
		{ "ModuleRelativePath", "Public/Movement/JMSlidingDoorMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DoorAOpenOffset_MetaData[] = {
		{ "Category", "JM Door|Slide Door|Door A" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Panel A always opens toward actor-local left by default. */" },
#endif
		{ "ModuleRelativePath", "Public/Movement/JMSlidingDoorMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Panel A always opens toward actor-local left by default." },
#endif
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DoorBOpenOffset_MetaData[] = {
		{ "Category", "JM Door|Slide Door|Door B" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Panel B always opens toward actor-local right by default. */" },
#endif
		{ "ModuleRelativePath", "Public/Movement/JMSlidingDoorMovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Panel B always opens toward actor-local right by default." },
#endif
		{ "Units", "cm" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DoorAClosedRelativeTransform_MetaData[] = {
		{ "Category", "JM Door|Slide Door|Door A" },
		{ "ModuleRelativePath", "Public/Movement/JMSlidingDoorMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DoorBClosedRelativeTransform_MetaData[] = {
		{ "Category", "JM Door|Slide Door|Door B" },
		{ "ModuleRelativePath", "Public/Movement/JMSlidingDoorMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MovingComponentB_MetaData[] = {
		{ "Category", "JM Door|Slide Door|Door B" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Movement/JMSlidingDoorMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollisionComponentB_MetaData[] = {
		{ "Category", "JM Door|Slide Door|Door B" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Movement/JMSlidingDoorMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLegacySinglePanelAsset_MetaData[] = {
		{ "ModuleRelativePath", "Public/Movement/JMSlidingDoorMovementComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMSlidingDoorMovementComponent constinit property declarations **********
	static const UECodeGen_Private::FStructPropertyParams NewProp_LocalOpenOffset;
	static void NewProp_bReverseOffsetWithDirection_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bReverseOffsetWithDirection;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DoorAOpenOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DoorBOpenOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DoorAClosedRelativeTransform;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DoorBClosedRelativeTransform;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MovingComponentB;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CollisionComponentB;
	static void NewProp_bLegacySinglePanelAsset_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLegacySinglePanelAsset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMSlidingDoorMovementComponent constinit property declarations ************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetPanelCollisionComponent"), .Pointer = &UJMSlidingDoorMovementComponent::execGetPanelCollisionComponent },
		{ .NameUTF8 = UTF8TEXT("GetPanelCollisionWorldTransformAtFraction"), .Pointer = &UJMSlidingDoorMovementComponent::execGetPanelCollisionWorldTransformAtFraction },
		{ .NameUTF8 = UTF8TEXT("GetPanelWorldTransformAtFraction"), .Pointer = &UJMSlidingDoorMovementComponent::execGetPanelWorldTransformAtFraction },
		{ .NameUTF8 = UTF8TEXT("HasPanel"), .Pointer = &UJMSlidingDoorMovementComponent::execHasPanel },
		{ .NameUTF8 = UTF8TEXT("InitializeDoorBComponent"), .Pointer = &UJMSlidingDoorMovementComponent::execInitializeDoorBComponent },
		{ .NameUTF8 = UTF8TEXT("IsLegacySinglePanelAsset"), .Pointer = &UJMSlidingDoorMovementComponent::execIsLegacySinglePanelAsset },
		{ .NameUTF8 = UTF8TEXT("SetPanelOpenFraction"), .Pointer = &UJMSlidingDoorMovementComponent::execSetPanelOpenFraction },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionComponent, "GetPanelCollisionComponent" }, // 2648522088
		{ &Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelCollisionWorldTransformAtFraction, "GetPanelCollisionWorldTransformAtFraction" }, // 975469405
		{ &Z_Construct_UFunction_UJMSlidingDoorMovementComponent_GetPanelWorldTransformAtFraction, "GetPanelWorldTransformAtFraction" }, // 842636978
		{ &Z_Construct_UFunction_UJMSlidingDoorMovementComponent_HasPanel, "HasPanel" }, // 2296181142
		{ &Z_Construct_UFunction_UJMSlidingDoorMovementComponent_InitializeDoorBComponent, "InitializeDoorBComponent" }, // 2818624680
		{ &Z_Construct_UFunction_UJMSlidingDoorMovementComponent_IsLegacySinglePanelAsset, "IsLegacySinglePanelAsset" }, // 3761934324
		{ &Z_Construct_UFunction_UJMSlidingDoorMovementComponent_SetPanelOpenFraction, "SetPanelOpenFraction" }, // 2608998943
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMSlidingDoorMovementComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics

// ********** Begin Class UJMSlidingDoorMovementComponent Property Definitions *********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::NewProp_LocalOpenOffset = { "LocalOpenOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMSlidingDoorMovementComponent, LocalOpenOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LocalOpenOffset_MetaData), NewProp_LocalOpenOffset_MetaData) };
void Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::NewProp_bReverseOffsetWithDirection_SetBit(void* Obj)
{
	((UJMSlidingDoorMovementComponent*)Obj)->bReverseOffsetWithDirection = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::NewProp_bReverseOffsetWithDirection = { "bReverseOffsetWithDirection", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMSlidingDoorMovementComponent), &Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::NewProp_bReverseOffsetWithDirection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bReverseOffsetWithDirection_MetaData), NewProp_bReverseOffsetWithDirection_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::NewProp_DoorAOpenOffset = { "DoorAOpenOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMSlidingDoorMovementComponent, DoorAOpenOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DoorAOpenOffset_MetaData), NewProp_DoorAOpenOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::NewProp_DoorBOpenOffset = { "DoorBOpenOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMSlidingDoorMovementComponent, DoorBOpenOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DoorBOpenOffset_MetaData), NewProp_DoorBOpenOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::NewProp_DoorAClosedRelativeTransform = { "DoorAClosedRelativeTransform", nullptr, (EPropertyFlags)0x0010000000020815, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMSlidingDoorMovementComponent, DoorAClosedRelativeTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DoorAClosedRelativeTransform_MetaData), NewProp_DoorAClosedRelativeTransform_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::NewProp_DoorBClosedRelativeTransform = { "DoorBClosedRelativeTransform", nullptr, (EPropertyFlags)0x0010000000020815, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMSlidingDoorMovementComponent, DoorBClosedRelativeTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DoorBClosedRelativeTransform_MetaData), NewProp_DoorBClosedRelativeTransform_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::NewProp_MovingComponentB = { "MovingComponentB", nullptr, (EPropertyFlags)0x011400000008201c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMSlidingDoorMovementComponent, MovingComponentB), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MovingComponentB_MetaData), NewProp_MovingComponentB_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::NewProp_CollisionComponentB = { "CollisionComponentB", nullptr, (EPropertyFlags)0x011400000008201c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMSlidingDoorMovementComponent, CollisionComponentB), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollisionComponentB_MetaData), NewProp_CollisionComponentB_MetaData) };
void Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::NewProp_bLegacySinglePanelAsset_SetBit(void* Obj)
{
	((UJMSlidingDoorMovementComponent*)Obj)->bLegacySinglePanelAsset = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::NewProp_bLegacySinglePanelAsset = { "bLegacySinglePanelAsset", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMSlidingDoorMovementComponent), &Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::NewProp_bLegacySinglePanelAsset_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLegacySinglePanelAsset_MetaData), NewProp_bLegacySinglePanelAsset_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::NewProp_LocalOpenOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::NewProp_bReverseOffsetWithDirection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::NewProp_DoorAOpenOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::NewProp_DoorBOpenOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::NewProp_DoorAClosedRelativeTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::NewProp_DoorBClosedRelativeTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::NewProp_MovingComponentB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::NewProp_CollisionComponentB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::NewProp_bLegacySinglePanelAsset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::PropPointers) < 2048);
// ********** End Class UJMSlidingDoorMovementComponent Property Definitions ***********************
UObject* (*const Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UJMDoorMovementComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::ClassParams = {
	&UJMSlidingDoorMovementComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::Class_MetaDataParams)
};
void UJMSlidingDoorMovementComponent::StaticRegisterNativesUJMSlidingDoorMovementComponent()
{
	UClass* Class = UJMSlidingDoorMovementComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMSlidingDoorMovementComponent()
{
	if (!Z_Registration_Info_UClass_UJMSlidingDoorMovementComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMSlidingDoorMovementComponent.OuterSingleton, Z_Construct_UClass_UJMSlidingDoorMovementComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMSlidingDoorMovementComponent.OuterSingleton;
}
UJMSlidingDoorMovementComponent::UJMSlidingDoorMovementComponent() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMSlidingDoorMovementComponent);
UJMSlidingDoorMovementComponent::~UJMSlidingDoorMovementComponent() {}
IMPLEMENT_FSTRUCTUREDARCHIVE_SERIALIZER(UJMSlidingDoorMovementComponent)
// ********** End Class UJMSlidingDoorMovementComponent ********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMSlidingDoorMovementComponent_h__Script_JMDoorRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMSlidingDoorMovementComponent, UJMSlidingDoorMovementComponent::StaticClass, TEXT("UJMSlidingDoorMovementComponent"), &Z_Registration_Info_UClass_UJMSlidingDoorMovementComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMSlidingDoorMovementComponent), 2201528704U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMSlidingDoorMovementComponent_h__Script_JMDoorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMSlidingDoorMovementComponent_h__Script_JMDoorRuntime_544387577{
	TEXT("/Script/JMDoorRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMSlidingDoorMovementComponent_h__Script_JMDoorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMSlidingDoorMovementComponent_h__Script_JMDoorRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
