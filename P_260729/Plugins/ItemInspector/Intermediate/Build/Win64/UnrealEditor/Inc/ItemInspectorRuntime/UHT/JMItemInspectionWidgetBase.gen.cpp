// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ItemInspection/JMItemInspectionWidgetBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMItemInspectionWidgetBase() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture_NoRegister();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMItemInspectionData_NoRegister();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMItemInspectionWidgetBase();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMItemInspectionWidgetBase_NoRegister();
ITEMINSPECTORRUNTIME_API UEnum* Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionCloseReason();
ITEMINSPECTORRUNTIME_API UFunction* Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionCloseRequestedSignature__DelegateSignature();
ITEMINSPECTORRUNTIME_API UFunction* Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewDraggedSignature__DelegateSignature();
ITEMINSPECTORRUNTIME_API UFunction* Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewZoomedSignature__DelegateSignature();
UMG_API UClass* Z_Construct_UClass_UBorder_NoRegister();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UMG_API UClass* Z_Construct_UClass_UWidget_NoRegister();
UPackage* Z_Construct_UPackage__Script_ItemInspectorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FJMItemInspectionCloseRequestedSignature ******************************
struct Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionCloseRequestedSignature__DelegateSignature_Statics
{
	struct _Script_ItemInspectorRuntime_eventJMItemInspectionCloseRequestedSignature_Parms
	{
		EJMItemInspectionCloseReason Reason;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMItemInspectionCloseRequestedSignature constinit property declarations 
	static const UECodeGen_Private::FBytePropertyParams NewProp_Reason_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Reason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMItemInspectionCloseRequestedSignature constinit property declarations 
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMItemInspectionCloseRequestedSignature Property Definitions *********
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionCloseRequestedSignature__DelegateSignature_Statics::NewProp_Reason_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionCloseRequestedSignature__DelegateSignature_Statics::NewProp_Reason = { "Reason", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ItemInspectorRuntime_eventJMItemInspectionCloseRequestedSignature_Parms, Reason), Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionCloseReason, METADATA_PARAMS(0, nullptr) }; // 1865201677
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionCloseRequestedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionCloseRequestedSignature__DelegateSignature_Statics::NewProp_Reason_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionCloseRequestedSignature__DelegateSignature_Statics::NewProp_Reason,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionCloseRequestedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMItemInspectionCloseRequestedSignature Property Definitions ***********
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionCloseRequestedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_ItemInspectorRuntime, nullptr, "JMItemInspectionCloseRequestedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionCloseRequestedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionCloseRequestedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionCloseRequestedSignature__DelegateSignature_Statics::_Script_ItemInspectorRuntime_eventJMItemInspectionCloseRequestedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionCloseRequestedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionCloseRequestedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionCloseRequestedSignature__DelegateSignature_Statics::_Script_ItemInspectorRuntime_eventJMItemInspectionCloseRequestedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionCloseRequestedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionCloseRequestedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMItemInspectionCloseRequestedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMItemInspectionCloseRequestedSignature, EJMItemInspectionCloseReason Reason)
{
	struct _Script_ItemInspectorRuntime_eventJMItemInspectionCloseRequestedSignature_Parms
	{
		EJMItemInspectionCloseReason Reason;
	};
	_Script_ItemInspectorRuntime_eventJMItemInspectionCloseRequestedSignature_Parms Parms;
	Parms.Reason=Reason;
	JMItemInspectionCloseRequestedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMItemInspectionCloseRequestedSignature ********************************

// ********** Begin Delegate FJMItemInspectionPreviewDraggedSignature ******************************
struct Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewDraggedSignature__DelegateSignature_Statics
{
	struct _Script_ItemInspectorRuntime_eventJMItemInspectionPreviewDraggedSignature_Parms
	{
		float ScreenDeltaX;
		float ScreenDeltaY;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMItemInspectionPreviewDraggedSignature constinit property declarations 
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ScreenDeltaX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ScreenDeltaY;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMItemInspectionPreviewDraggedSignature constinit property declarations 
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMItemInspectionPreviewDraggedSignature Property Definitions *********
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewDraggedSignature__DelegateSignature_Statics::NewProp_ScreenDeltaX = { "ScreenDeltaX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ItemInspectorRuntime_eventJMItemInspectionPreviewDraggedSignature_Parms, ScreenDeltaX), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewDraggedSignature__DelegateSignature_Statics::NewProp_ScreenDeltaY = { "ScreenDeltaY", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ItemInspectorRuntime_eventJMItemInspectionPreviewDraggedSignature_Parms, ScreenDeltaY), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewDraggedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewDraggedSignature__DelegateSignature_Statics::NewProp_ScreenDeltaX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewDraggedSignature__DelegateSignature_Statics::NewProp_ScreenDeltaY,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewDraggedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMItemInspectionPreviewDraggedSignature Property Definitions ***********
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewDraggedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_ItemInspectorRuntime, nullptr, "JMItemInspectionPreviewDraggedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewDraggedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewDraggedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewDraggedSignature__DelegateSignature_Statics::_Script_ItemInspectorRuntime_eventJMItemInspectionPreviewDraggedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewDraggedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewDraggedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewDraggedSignature__DelegateSignature_Statics::_Script_ItemInspectorRuntime_eventJMItemInspectionPreviewDraggedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewDraggedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewDraggedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMItemInspectionPreviewDraggedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMItemInspectionPreviewDraggedSignature, float ScreenDeltaX, float ScreenDeltaY)
{
	struct _Script_ItemInspectorRuntime_eventJMItemInspectionPreviewDraggedSignature_Parms
	{
		float ScreenDeltaX;
		float ScreenDeltaY;
	};
	_Script_ItemInspectorRuntime_eventJMItemInspectionPreviewDraggedSignature_Parms Parms;
	Parms.ScreenDeltaX=ScreenDeltaX;
	Parms.ScreenDeltaY=ScreenDeltaY;
	JMItemInspectionPreviewDraggedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMItemInspectionPreviewDraggedSignature ********************************

// ********** Begin Delegate FJMItemInspectionPreviewZoomedSignature *******************************
struct Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewZoomedSignature__DelegateSignature_Statics
{
	struct _Script_ItemInspectorRuntime_eventJMItemInspectionPreviewZoomedSignature_Parms
	{
		float WheelDelta;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMItemInspectionPreviewZoomedSignature constinit property declarations 
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WheelDelta;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMItemInspectionPreviewZoomedSignature constinit property declarations *
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMItemInspectionPreviewZoomedSignature Property Definitions **********
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewZoomedSignature__DelegateSignature_Statics::NewProp_WheelDelta = { "WheelDelta", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ItemInspectorRuntime_eventJMItemInspectionPreviewZoomedSignature_Parms, WheelDelta), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewZoomedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewZoomedSignature__DelegateSignature_Statics::NewProp_WheelDelta,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewZoomedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMItemInspectionPreviewZoomedSignature Property Definitions ************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewZoomedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_ItemInspectorRuntime, nullptr, "JMItemInspectionPreviewZoomedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewZoomedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewZoomedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewZoomedSignature__DelegateSignature_Statics::_Script_ItemInspectorRuntime_eventJMItemInspectionPreviewZoomedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewZoomedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewZoomedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewZoomedSignature__DelegateSignature_Statics::_Script_ItemInspectorRuntime_eventJMItemInspectionPreviewZoomedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewZoomedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewZoomedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMItemInspectionPreviewZoomedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMItemInspectionPreviewZoomedSignature, float WheelDelta)
{
	struct _Script_ItemInspectorRuntime_eventJMItemInspectionPreviewZoomedSignature_Parms
	{
		float WheelDelta;
	};
	_Script_ItemInspectorRuntime_eventJMItemInspectionPreviewZoomedSignature_Parms Parms;
	Parms.WheelDelta=WheelDelta;
	JMItemInspectionPreviewZoomedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMItemInspectionPreviewZoomedSignature *********************************

// ********** Begin Class UJMItemInspectionWidgetBase Function HandleCloseButtonClicked ************
struct Z_Construct_UFunction_UJMItemInspectionWidgetBase_HandleCloseButtonClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleCloseButtonClicked constinit property declarations **************
// ********** End Function HandleCloseButtonClicked constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_HandleCloseButtonClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionWidgetBase, nullptr, "HandleCloseButtonClicked", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_HandleCloseButtonClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionWidgetBase_HandleCloseButtonClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UJMItemInspectionWidgetBase_HandleCloseButtonClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionWidgetBase_HandleCloseButtonClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMItemInspectionWidgetBase::execHandleCloseButtonClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCloseButtonClicked();
	P_NATIVE_END;
}
// ********** End Class UJMItemInspectionWidgetBase Function HandleCloseButtonClicked **************

// ********** Begin Class UJMItemInspectionWidgetBase Function OnEnterTransitionCompleted **********
static FName NAME_UJMItemInspectionWidgetBase_OnEnterTransitionCompleted = FName(TEXT("OnEnterTransitionCompleted"));
void UJMItemInspectionWidgetBase::OnEnterTransitionCompleted()
{
	UFunction* Func = FindFunctionChecked(NAME_UJMItemInspectionWidgetBase_OnEnterTransitionCompleted);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionCompleted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection|Transition" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnEnterTransitionCompleted constinit property declarations ************
// ********** End Function OnEnterTransitionCompleted constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionCompleted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionWidgetBase, nullptr, "OnEnterTransitionCompleted", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionCompleted_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UJMItemInspectionWidgetBase Function OnEnterTransitionCompleted ************

// ********** Begin Class UJMItemInspectionWidgetBase Function OnEnterTransitionStarted ************
static FName NAME_UJMItemInspectionWidgetBase_OnEnterTransitionStarted = FName(TEXT("OnEnterTransitionStarted"));
void UJMItemInspectionWidgetBase::OnEnterTransitionStarted()
{
	UFunction* Func = FindFunctionChecked(NAME_UJMItemInspectionWidgetBase_OnEnterTransitionStarted);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionStarted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection|Transition" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnEnterTransitionStarted constinit property declarations **************
// ********** End Function OnEnterTransitionStarted constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionStarted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionWidgetBase, nullptr, "OnEnterTransitionStarted", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionStarted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionStarted_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionStarted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionStarted_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UJMItemInspectionWidgetBase Function OnEnterTransitionStarted **************

// ********** Begin Class UJMItemInspectionWidgetBase Function OnEnterTransitionUpdated ************
struct JMItemInspectionWidgetBase_eventOnEnterTransitionUpdated_Parms
{
	float Alpha;
};
static FName NAME_UJMItemInspectionWidgetBase_OnEnterTransitionUpdated = FName(TEXT("OnEnterTransitionUpdated"));
void UJMItemInspectionWidgetBase::OnEnterTransitionUpdated(float Alpha)
{
	JMItemInspectionWidgetBase_eventOnEnterTransitionUpdated_Parms Parms;
	Parms.Alpha=Alpha;
	UFunction* Func = FindFunctionChecked(NAME_UJMItemInspectionWidgetBase_OnEnterTransitionUpdated);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionUpdated_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection|Transition" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnEnterTransitionUpdated constinit property declarations **************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Alpha;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnEnterTransitionUpdated constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnEnterTransitionUpdated Property Definitions *************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionUpdated_Statics::NewProp_Alpha = { "Alpha", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionWidgetBase_eventOnEnterTransitionUpdated_Parms, Alpha), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionUpdated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionUpdated_Statics::NewProp_Alpha,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionUpdated_Statics::PropPointers) < 2048);
// ********** End Function OnEnterTransitionUpdated Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionUpdated_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionWidgetBase, nullptr, "OnEnterTransitionUpdated", 	Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionUpdated_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionUpdated_Statics::PropPointers), 
sizeof(JMItemInspectionWidgetBase_eventOnEnterTransitionUpdated_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionUpdated_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionUpdated_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMItemInspectionWidgetBase_eventOnEnterTransitionUpdated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionUpdated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionUpdated_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UJMItemInspectionWidgetBase Function OnEnterTransitionUpdated **************

// ********** Begin Class UJMItemInspectionWidgetBase Function OnExitTransitionCompleted ***********
static FName NAME_UJMItemInspectionWidgetBase_OnExitTransitionCompleted = FName(TEXT("OnExitTransitionCompleted"));
void UJMItemInspectionWidgetBase::OnExitTransitionCompleted()
{
	UFunction* Func = FindFunctionChecked(NAME_UJMItemInspectionWidgetBase_OnExitTransitionCompleted);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionCompleted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection|Transition" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnExitTransitionCompleted constinit property declarations *************
// ********** End Function OnExitTransitionCompleted constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionCompleted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionWidgetBase, nullptr, "OnExitTransitionCompleted", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionCompleted_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UJMItemInspectionWidgetBase Function OnExitTransitionCompleted *************

// ********** Begin Class UJMItemInspectionWidgetBase Function OnExitTransitionStarted *************
static FName NAME_UJMItemInspectionWidgetBase_OnExitTransitionStarted = FName(TEXT("OnExitTransitionStarted"));
void UJMItemInspectionWidgetBase::OnExitTransitionStarted()
{
	UFunction* Func = FindFunctionChecked(NAME_UJMItemInspectionWidgetBase_OnExitTransitionStarted);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionStarted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection|Transition" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnExitTransitionStarted constinit property declarations ***************
// ********** End Function OnExitTransitionStarted constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionStarted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionWidgetBase, nullptr, "OnExitTransitionStarted", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionStarted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionStarted_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionStarted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionStarted_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UJMItemInspectionWidgetBase Function OnExitTransitionStarted ***************

// ********** Begin Class UJMItemInspectionWidgetBase Function OnExitTransitionUpdated *************
struct JMItemInspectionWidgetBase_eventOnExitTransitionUpdated_Parms
{
	float Alpha;
};
static FName NAME_UJMItemInspectionWidgetBase_OnExitTransitionUpdated = FName(TEXT("OnExitTransitionUpdated"));
void UJMItemInspectionWidgetBase::OnExitTransitionUpdated(float Alpha)
{
	JMItemInspectionWidgetBase_eventOnExitTransitionUpdated_Parms Parms;
	Parms.Alpha=Alpha;
	UFunction* Func = FindFunctionChecked(NAME_UJMItemInspectionWidgetBase_OnExitTransitionUpdated);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionUpdated_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection|Transition" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnExitTransitionUpdated constinit property declarations ***************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Alpha;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnExitTransitionUpdated constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnExitTransitionUpdated Property Definitions **************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionUpdated_Statics::NewProp_Alpha = { "Alpha", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionWidgetBase_eventOnExitTransitionUpdated_Parms, Alpha), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionUpdated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionUpdated_Statics::NewProp_Alpha,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionUpdated_Statics::PropPointers) < 2048);
// ********** End Function OnExitTransitionUpdated Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionUpdated_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionWidgetBase, nullptr, "OnExitTransitionUpdated", 	Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionUpdated_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionUpdated_Statics::PropPointers), 
sizeof(JMItemInspectionWidgetBase_eventOnExitTransitionUpdated_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionUpdated_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionUpdated_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMItemInspectionWidgetBase_eventOnExitTransitionUpdated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionUpdated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionUpdated_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UJMItemInspectionWidgetBase Function OnExitTransitionUpdated ***************

// ********** Begin Class UJMItemInspectionWidgetBase Function OnInspectionClosed ******************
struct JMItemInspectionWidgetBase_eventOnInspectionClosed_Parms
{
	EJMItemInspectionCloseReason Reason;
};
static FName NAME_UJMItemInspectionWidgetBase_OnInspectionClosed = FName(TEXT("OnInspectionClosed"));
void UJMItemInspectionWidgetBase::OnInspectionClosed(EJMItemInspectionCloseReason Reason)
{
	JMItemInspectionWidgetBase_eventOnInspectionClosed_Parms Parms;
	Parms.Reason=Reason;
	UFunction* Func = FindFunctionChecked(NAME_UJMItemInspectionWidgetBase_OnInspectionClosed);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionClosed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnInspectionClosed constinit property declarations ********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Reason_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Reason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnInspectionClosed constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnInspectionClosed Property Definitions *******************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionClosed_Statics::NewProp_Reason_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionClosed_Statics::NewProp_Reason = { "Reason", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionWidgetBase_eventOnInspectionClosed_Parms, Reason), Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionCloseReason, METADATA_PARAMS(0, nullptr) }; // 1865201677
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionClosed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionClosed_Statics::NewProp_Reason_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionClosed_Statics::NewProp_Reason,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionClosed_Statics::PropPointers) < 2048);
// ********** End Function OnInspectionClosed Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionClosed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionWidgetBase, nullptr, "OnInspectionClosed", 	Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionClosed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionClosed_Statics::PropPointers), 
sizeof(JMItemInspectionWidgetBase_eventOnInspectionClosed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionClosed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionClosed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMItemInspectionWidgetBase_eventOnInspectionClosed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionClosed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionClosed_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UJMItemInspectionWidgetBase Function OnInspectionClosed ********************

// ********** Begin Class UJMItemInspectionWidgetBase Function OnInspectionOpened ******************
struct JMItemInspectionWidgetBase_eventOnInspectionOpened_Parms
{
	UJMItemInspectionData* InInspectionData;
};
static FName NAME_UJMItemInspectionWidgetBase_OnInspectionOpened = FName(TEXT("OnInspectionOpened"));
void UJMItemInspectionWidgetBase::OnInspectionOpened(UJMItemInspectionData* InInspectionData)
{
	JMItemInspectionWidgetBase_eventOnInspectionOpened_Parms Parms;
	Parms.InInspectionData=InInspectionData;
	UFunction* Func = FindFunctionChecked(NAME_UJMItemInspectionWidgetBase_OnInspectionOpened);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionOpened_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnInspectionOpened constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InInspectionData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnInspectionOpened constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnInspectionOpened Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionOpened_Statics::NewProp_InInspectionData = { "InInspectionData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionWidgetBase_eventOnInspectionOpened_Parms, InInspectionData), Z_Construct_UClass_UJMItemInspectionData_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionOpened_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionOpened_Statics::NewProp_InInspectionData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionOpened_Statics::PropPointers) < 2048);
// ********** End Function OnInspectionOpened Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionOpened_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionWidgetBase, nullptr, "OnInspectionOpened", 	Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionOpened_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionOpened_Statics::PropPointers), 
sizeof(JMItemInspectionWidgetBase_eventOnInspectionOpened_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionOpened_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionOpened_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMItemInspectionWidgetBase_eventOnInspectionOpened_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionOpened()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionOpened_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UJMItemInspectionWidgetBase Function OnInspectionOpened ********************

// ********** Begin Class UJMItemInspectionWidgetBase Function RequestClose ************************
struct Z_Construct_UFunction_UJMItemInspectionWidgetBase_RequestClose_Statics
{
	struct JMItemInspectionWidgetBase_eventRequestClose_Parms
	{
		EJMItemInspectionCloseReason Reason;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "CPP_Default_Reason", "User" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestClose constinit property declarations **************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Reason_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Reason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestClose constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestClose Property Definitions *************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_RequestClose_Statics::NewProp_Reason_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_RequestClose_Statics::NewProp_Reason = { "Reason", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionWidgetBase_eventRequestClose_Parms, Reason), Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionCloseReason, METADATA_PARAMS(0, nullptr) }; // 1865201677
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionWidgetBase_RequestClose_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionWidgetBase_RequestClose_Statics::NewProp_Reason_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionWidgetBase_RequestClose_Statics::NewProp_Reason,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_RequestClose_Statics::PropPointers) < 2048);
// ********** End Function RequestClose Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_RequestClose_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionWidgetBase, nullptr, "RequestClose", 	Z_Construct_UFunction_UJMItemInspectionWidgetBase_RequestClose_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_RequestClose_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMItemInspectionWidgetBase_RequestClose_Statics::JMItemInspectionWidgetBase_eventRequestClose_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_RequestClose_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionWidgetBase_RequestClose_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMItemInspectionWidgetBase_RequestClose_Statics::JMItemInspectionWidgetBase_eventRequestClose_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionWidgetBase_RequestClose()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionWidgetBase_RequestClose_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMItemInspectionWidgetBase::execRequestClose)
{
	P_GET_ENUM(EJMItemInspectionCloseReason,Z_Param_Reason);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestClose(EJMItemInspectionCloseReason(Z_Param_Reason));
	P_NATIVE_END;
}
// ********** End Class UJMItemInspectionWidgetBase Function RequestClose **************************

// ********** Begin Class UJMItemInspectionWidgetBase Function SetAdditionalInfo *******************
struct Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetAdditionalInfo_Statics
{
	struct JMItemInspectionWidgetBase_eventSetAdditionalInfo_Parms
	{
		FText InAdditionalInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InAdditionalInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetAdditionalInfo constinit property declarations *********************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InAdditionalInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetAdditionalInfo constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetAdditionalInfo Property Definitions ********************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetAdditionalInfo_Statics::NewProp_InAdditionalInfo = { "InAdditionalInfo", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionWidgetBase_eventSetAdditionalInfo_Parms, InAdditionalInfo), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InAdditionalInfo_MetaData), NewProp_InAdditionalInfo_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetAdditionalInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetAdditionalInfo_Statics::NewProp_InAdditionalInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetAdditionalInfo_Statics::PropPointers) < 2048);
// ********** End Function SetAdditionalInfo Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetAdditionalInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionWidgetBase, nullptr, "SetAdditionalInfo", 	Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetAdditionalInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetAdditionalInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetAdditionalInfo_Statics::JMItemInspectionWidgetBase_eventSetAdditionalInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetAdditionalInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetAdditionalInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetAdditionalInfo_Statics::JMItemInspectionWidgetBase_eventSetAdditionalInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetAdditionalInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetAdditionalInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMItemInspectionWidgetBase::execSetAdditionalInfo)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_InAdditionalInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetAdditionalInfo(Z_Param_Out_InAdditionalInfo);
	P_NATIVE_END;
}
// ********** End Class UJMItemInspectionWidgetBase Function SetAdditionalInfo *********************

// ********** Begin Class UJMItemInspectionWidgetBase Function SetCategoryText *********************
struct Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetCategoryText_Statics
{
	struct JMItemInspectionWidgetBase_eventSetCategoryText_Parms
	{
		FText InCategoryText;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InCategoryText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetCategoryText constinit property declarations ***********************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InCategoryText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetCategoryText constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetCategoryText Property Definitions **********************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetCategoryText_Statics::NewProp_InCategoryText = { "InCategoryText", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionWidgetBase_eventSetCategoryText_Parms, InCategoryText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InCategoryText_MetaData), NewProp_InCategoryText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetCategoryText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetCategoryText_Statics::NewProp_InCategoryText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetCategoryText_Statics::PropPointers) < 2048);
// ********** End Function SetCategoryText Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetCategoryText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionWidgetBase, nullptr, "SetCategoryText", 	Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetCategoryText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetCategoryText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetCategoryText_Statics::JMItemInspectionWidgetBase_eventSetCategoryText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetCategoryText_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetCategoryText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetCategoryText_Statics::JMItemInspectionWidgetBase_eventSetCategoryText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetCategoryText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetCategoryText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMItemInspectionWidgetBase::execSetCategoryText)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_InCategoryText);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCategoryText(Z_Param_Out_InCategoryText);
	P_NATIVE_END;
}
// ********** End Class UJMItemInspectionWidgetBase Function SetCategoryText ***********************

// ********** Begin Class UJMItemInspectionWidgetBase Function SetDescription **********************
struct Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetDescription_Statics
{
	struct JMItemInspectionWidgetBase_eventSetDescription_Parms
	{
		FText InDescription;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InDescription_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetDescription constinit property declarations ************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InDescription;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetDescription constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetDescription Property Definitions ***********************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetDescription_Statics::NewProp_InDescription = { "InDescription", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionWidgetBase_eventSetDescription_Parms, InDescription), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InDescription_MetaData), NewProp_InDescription_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetDescription_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetDescription_Statics::NewProp_InDescription,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetDescription_Statics::PropPointers) < 2048);
// ********** End Function SetDescription Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetDescription_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionWidgetBase, nullptr, "SetDescription", 	Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetDescription_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetDescription_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetDescription_Statics::JMItemInspectionWidgetBase_eventSetDescription_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetDescription_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetDescription_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetDescription_Statics::JMItemInspectionWidgetBase_eventSetDescription_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetDescription()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetDescription_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMItemInspectionWidgetBase::execSetDescription)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_InDescription);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDescription(Z_Param_Out_InDescription);
	P_NATIVE_END;
}
// ********** End Class UJMItemInspectionWidgetBase Function SetDescription ************************

// ********** Begin Class UJMItemInspectionWidgetBase Function SetInspectionData *******************
struct Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetInspectionData_Statics
{
	struct JMItemInspectionWidgetBase_eventSetInspectionData_Parms
	{
		UJMItemInspectionData* InInspectionData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetInspectionData constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InInspectionData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetInspectionData constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetInspectionData Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetInspectionData_Statics::NewProp_InInspectionData = { "InInspectionData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionWidgetBase_eventSetInspectionData_Parms, InInspectionData), Z_Construct_UClass_UJMItemInspectionData_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetInspectionData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetInspectionData_Statics::NewProp_InInspectionData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetInspectionData_Statics::PropPointers) < 2048);
// ********** End Function SetInspectionData Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetInspectionData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionWidgetBase, nullptr, "SetInspectionData", 	Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetInspectionData_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetInspectionData_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetInspectionData_Statics::JMItemInspectionWidgetBase_eventSetInspectionData_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetInspectionData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetInspectionData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetInspectionData_Statics::JMItemInspectionWidgetBase_eventSetInspectionData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetInspectionData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetInspectionData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMItemInspectionWidgetBase::execSetInspectionData)
{
	P_GET_OBJECT(UJMItemInspectionData,Z_Param_InInspectionData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetInspectionData(Z_Param_InInspectionData);
	P_NATIVE_END;
}
// ********** End Class UJMItemInspectionWidgetBase Function SetInspectionData *********************

// ********** Begin Class UJMItemInspectionWidgetBase Function SetItemName *************************
struct Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetItemName_Statics
{
	struct JMItemInspectionWidgetBase_eventSetItemName_Parms
	{
		FText InItemName;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InItemName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetItemName constinit property declarations ***************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InItemName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetItemName constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetItemName Property Definitions **************************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetItemName_Statics::NewProp_InItemName = { "InItemName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionWidgetBase_eventSetItemName_Parms, InItemName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InItemName_MetaData), NewProp_InItemName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetItemName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetItemName_Statics::NewProp_InItemName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetItemName_Statics::PropPointers) < 2048);
// ********** End Function SetItemName Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetItemName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionWidgetBase, nullptr, "SetItemName", 	Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetItemName_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetItemName_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetItemName_Statics::JMItemInspectionWidgetBase_eventSetItemName_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetItemName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetItemName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetItemName_Statics::JMItemInspectionWidgetBase_eventSetItemName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetItemName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetItemName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMItemInspectionWidgetBase::execSetItemName)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_InItemName);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetItemName(Z_Param_Out_InItemName);
	P_NATIVE_END;
}
// ********** End Class UJMItemInspectionWidgetBase Function SetItemName ***************************

// ********** Begin Class UJMItemInspectionWidgetBase Function SetPreviewStatusText ****************
struct Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewStatusText_Statics
{
	struct JMItemInspectionWidgetBase_eventSetPreviewStatusText_Parms
	{
		FText InStatusText;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InStatusText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetPreviewStatusText constinit property declarations ******************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InStatusText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPreviewStatusText constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPreviewStatusText Property Definitions *****************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewStatusText_Statics::NewProp_InStatusText = { "InStatusText", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionWidgetBase_eventSetPreviewStatusText_Parms, InStatusText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InStatusText_MetaData), NewProp_InStatusText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewStatusText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewStatusText_Statics::NewProp_InStatusText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewStatusText_Statics::PropPointers) < 2048);
// ********** End Function SetPreviewStatusText Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewStatusText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionWidgetBase, nullptr, "SetPreviewStatusText", 	Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewStatusText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewStatusText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewStatusText_Statics::JMItemInspectionWidgetBase_eventSetPreviewStatusText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewStatusText_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewStatusText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewStatusText_Statics::JMItemInspectionWidgetBase_eventSetPreviewStatusText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewStatusText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewStatusText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMItemInspectionWidgetBase::execSetPreviewStatusText)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_InStatusText);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPreviewStatusText(Z_Param_Out_InStatusText);
	P_NATIVE_END;
}
// ********** End Class UJMItemInspectionWidgetBase Function SetPreviewStatusText ******************

// ********** Begin Class UJMItemInspectionWidgetBase Function SetPreviewTexture *******************
struct Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewTexture_Statics
{
	struct JMItemInspectionWidgetBase_eventSetPreviewTexture_Parms
	{
		UTexture* InPreviewTexture;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetPreviewTexture constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InPreviewTexture;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPreviewTexture constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPreviewTexture Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewTexture_Statics::NewProp_InPreviewTexture = { "InPreviewTexture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionWidgetBase_eventSetPreviewTexture_Parms, InPreviewTexture), Z_Construct_UClass_UTexture_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewTexture_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewTexture_Statics::NewProp_InPreviewTexture,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewTexture_Statics::PropPointers) < 2048);
// ********** End Function SetPreviewTexture Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewTexture_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionWidgetBase, nullptr, "SetPreviewTexture", 	Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewTexture_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewTexture_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewTexture_Statics::JMItemInspectionWidgetBase_eventSetPreviewTexture_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewTexture_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewTexture_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewTexture_Statics::JMItemInspectionWidgetBase_eventSetPreviewTexture_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewTexture()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewTexture_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMItemInspectionWidgetBase::execSetPreviewTexture)
{
	P_GET_OBJECT(UTexture,Z_Param_InPreviewTexture);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPreviewTexture(Z_Param_InPreviewTexture);
	P_NATIVE_END;
}
// ********** End Class UJMItemInspectionWidgetBase Function SetPreviewTexture *********************

// ********** Begin Class UJMItemInspectionWidgetBase **********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMItemInspectionWidgetBase;
UClass* UJMItemInspectionWidgetBase::GetPrivateStaticClass()
{
	using TClass = UJMItemInspectionWidgetBase;
	if (!Z_Registration_Info_UClass_UJMItemInspectionWidgetBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMItemInspectionWidgetBase"),
			Z_Registration_Info_UClass_UJMItemInspectionWidgetBase.InnerSingleton,
			StaticRegisterNativesUJMItemInspectionWidgetBase,
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
	return Z_Registration_Info_UClass_UJMItemInspectionWidgetBase.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMItemInspectionWidgetBase_NoRegister()
{
	return UJMItemInspectionWidgetBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "ItemInspection/JMItemInspectionWidgetBase.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCloseRequested_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnPreviewDragged_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnPreviewZoomed_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewPanel_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewImage_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemNameText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CategoryText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DescriptionText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdditionalInfoText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemIdText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewStatusText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CloseButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InspectionData_MetaData[] = {
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewMaterialAsset_MetaData[] = {
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewMaterialInstance_MetaData[] = {
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SimpleTransitionBackdrop_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SimpleTransitionContent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMItemInspectionWidgetBase constinit property declarations **************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCloseRequested;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPreviewDragged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPreviewZoomed;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewPanel;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewImage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CategoryText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DescriptionText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AdditionalInfoText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemIdText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewStatusText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CloseButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InspectionData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewMaterialAsset;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewMaterialInstance;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SimpleTransitionBackdrop;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SimpleTransitionContent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMItemInspectionWidgetBase constinit property declarations ****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("HandleCloseButtonClicked"), .Pointer = &UJMItemInspectionWidgetBase::execHandleCloseButtonClicked },
		{ .NameUTF8 = UTF8TEXT("RequestClose"), .Pointer = &UJMItemInspectionWidgetBase::execRequestClose },
		{ .NameUTF8 = UTF8TEXT("SetAdditionalInfo"), .Pointer = &UJMItemInspectionWidgetBase::execSetAdditionalInfo },
		{ .NameUTF8 = UTF8TEXT("SetCategoryText"), .Pointer = &UJMItemInspectionWidgetBase::execSetCategoryText },
		{ .NameUTF8 = UTF8TEXT("SetDescription"), .Pointer = &UJMItemInspectionWidgetBase::execSetDescription },
		{ .NameUTF8 = UTF8TEXT("SetInspectionData"), .Pointer = &UJMItemInspectionWidgetBase::execSetInspectionData },
		{ .NameUTF8 = UTF8TEXT("SetItemName"), .Pointer = &UJMItemInspectionWidgetBase::execSetItemName },
		{ .NameUTF8 = UTF8TEXT("SetPreviewStatusText"), .Pointer = &UJMItemInspectionWidgetBase::execSetPreviewStatusText },
		{ .NameUTF8 = UTF8TEXT("SetPreviewTexture"), .Pointer = &UJMItemInspectionWidgetBase::execSetPreviewTexture },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMItemInspectionWidgetBase_HandleCloseButtonClicked, "HandleCloseButtonClicked" }, // 2012578984
		{ &Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionCompleted, "OnEnterTransitionCompleted" }, // 757899625
		{ &Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionStarted, "OnEnterTransitionStarted" }, // 2891574467
		{ &Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnEnterTransitionUpdated, "OnEnterTransitionUpdated" }, // 2499395349
		{ &Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionCompleted, "OnExitTransitionCompleted" }, // 552827129
		{ &Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionStarted, "OnExitTransitionStarted" }, // 3841228506
		{ &Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnExitTransitionUpdated, "OnExitTransitionUpdated" }, // 1416085396
		{ &Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionClosed, "OnInspectionClosed" }, // 3506499806
		{ &Z_Construct_UFunction_UJMItemInspectionWidgetBase_OnInspectionOpened, "OnInspectionOpened" }, // 4280600324
		{ &Z_Construct_UFunction_UJMItemInspectionWidgetBase_RequestClose, "RequestClose" }, // 952362740
		{ &Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetAdditionalInfo, "SetAdditionalInfo" }, // 2873921451
		{ &Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetCategoryText, "SetCategoryText" }, // 2333868675
		{ &Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetDescription, "SetDescription" }, // 2428257474
		{ &Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetInspectionData, "SetInspectionData" }, // 2838732711
		{ &Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetItemName, "SetItemName" }, // 2460259668
		{ &Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewStatusText, "SetPreviewStatusText" }, // 722308702
		{ &Z_Construct_UFunction_UJMItemInspectionWidgetBase_SetPreviewTexture, "SetPreviewTexture" }, // 219675193
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMItemInspectionWidgetBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics

// ********** Begin Class UJMItemInspectionWidgetBase Property Definitions *************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_OnCloseRequested = { "OnCloseRequested", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionWidgetBase, OnCloseRequested), Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionCloseRequestedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCloseRequested_MetaData), NewProp_OnCloseRequested_MetaData) }; // 345508877
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_OnPreviewDragged = { "OnPreviewDragged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionWidgetBase, OnPreviewDragged), Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewDraggedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnPreviewDragged_MetaData), NewProp_OnPreviewDragged_MetaData) }; // 658224444
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_OnPreviewZoomed = { "OnPreviewZoomed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionWidgetBase, OnPreviewZoomed), Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMItemInspectionPreviewZoomedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnPreviewZoomed_MetaData), NewProp_OnPreviewZoomed_MetaData) }; // 3250650984
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_PreviewPanel = { "PreviewPanel", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionWidgetBase, PreviewPanel), Z_Construct_UClass_UBorder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewPanel_MetaData), NewProp_PreviewPanel_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_PreviewImage = { "PreviewImage", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionWidgetBase, PreviewImage), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewImage_MetaData), NewProp_PreviewImage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_ItemNameText = { "ItemNameText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionWidgetBase, ItemNameText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemNameText_MetaData), NewProp_ItemNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_CategoryText = { "CategoryText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionWidgetBase, CategoryText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CategoryText_MetaData), NewProp_CategoryText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_DescriptionText = { "DescriptionText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionWidgetBase, DescriptionText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DescriptionText_MetaData), NewProp_DescriptionText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_AdditionalInfoText = { "AdditionalInfoText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionWidgetBase, AdditionalInfoText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdditionalInfoText_MetaData), NewProp_AdditionalInfoText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_ItemIdText = { "ItemIdText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionWidgetBase, ItemIdText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemIdText_MetaData), NewProp_ItemIdText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_PreviewStatusText = { "PreviewStatusText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionWidgetBase, PreviewStatusText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewStatusText_MetaData), NewProp_PreviewStatusText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_CloseButton = { "CloseButton", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionWidgetBase, CloseButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CloseButton_MetaData), NewProp_CloseButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_InspectionData = { "InspectionData", nullptr, (EPropertyFlags)0x0124080000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionWidgetBase, InspectionData), Z_Construct_UClass_UJMItemInspectionData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InspectionData_MetaData), NewProp_InspectionData_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_PreviewMaterialAsset = { "PreviewMaterialAsset", nullptr, (EPropertyFlags)0x0124080000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionWidgetBase, PreviewMaterialAsset), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewMaterialAsset_MetaData), NewProp_PreviewMaterialAsset_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_PreviewMaterialInstance = { "PreviewMaterialInstance", nullptr, (EPropertyFlags)0x0124080000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionWidgetBase, PreviewMaterialInstance), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewMaterialInstance_MetaData), NewProp_PreviewMaterialInstance_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_SimpleTransitionBackdrop = { "SimpleTransitionBackdrop", nullptr, (EPropertyFlags)0x0124080000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionWidgetBase, SimpleTransitionBackdrop), Z_Construct_UClass_UWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SimpleTransitionBackdrop_MetaData), NewProp_SimpleTransitionBackdrop_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_SimpleTransitionContent = { "SimpleTransitionContent", nullptr, (EPropertyFlags)0x0124080000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionWidgetBase, SimpleTransitionContent), Z_Construct_UClass_UWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SimpleTransitionContent_MetaData), NewProp_SimpleTransitionContent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_OnCloseRequested,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_OnPreviewDragged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_OnPreviewZoomed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_PreviewPanel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_PreviewImage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_ItemNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_CategoryText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_DescriptionText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_AdditionalInfoText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_ItemIdText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_PreviewStatusText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_CloseButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_InspectionData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_PreviewMaterialAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_PreviewMaterialInstance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_SimpleTransitionBackdrop,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::NewProp_SimpleTransitionContent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::PropPointers) < 2048);
// ********** End Class UJMItemInspectionWidgetBase Property Definitions ***************************
UObject* (*const Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_ItemInspectorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::ClassParams = {
	&UJMItemInspectionWidgetBase::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::Class_MetaDataParams)
};
void UJMItemInspectionWidgetBase::StaticRegisterNativesUJMItemInspectionWidgetBase()
{
	UClass* Class = UJMItemInspectionWidgetBase::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMItemInspectionWidgetBase()
{
	if (!Z_Registration_Info_UClass_UJMItemInspectionWidgetBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMItemInspectionWidgetBase.OuterSingleton, Z_Construct_UClass_UJMItemInspectionWidgetBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMItemInspectionWidgetBase.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMItemInspectionWidgetBase);
UJMItemInspectionWidgetBase::~UJMItemInspectionWidgetBase() {}
// ********** End Class UJMItemInspectionWidgetBase ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionWidgetBase_h__Script_ItemInspectorRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMItemInspectionWidgetBase, UJMItemInspectionWidgetBase::StaticClass, TEXT("UJMItemInspectionWidgetBase"), &Z_Registration_Info_UClass_UJMItemInspectionWidgetBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMItemInspectionWidgetBase), 1935706007U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionWidgetBase_h__Script_ItemInspectorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionWidgetBase_h__Script_ItemInspectorRuntime_3675009112{
	TEXT("/Script/ItemInspectorRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionWidgetBase_h__Script_ItemInspectorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionWidgetBase_h__Script_ItemInspectorRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
