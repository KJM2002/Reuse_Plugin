// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/InventoryPickupNotificationWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeInventoryPickupNotificationWidget() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryPickupNotificationWidget();
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryPickupNotificationWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
UMG_API UClass* Z_Construct_UClass_USizeBox_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_InventorySystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UInventoryPickupNotificationWidget Function BP_OnNotificationShown *******
struct InventoryPickupNotificationWidget_eventBP_OnNotificationShown_Parms
{
	FText InMessage;
	float InDuration;
};
static FName NAME_UInventoryPickupNotificationWidget_BP_OnNotificationShown = FName(TEXT("BP_OnNotificationShown"));
void UInventoryPickupNotificationWidget::BP_OnNotificationShown(FText const& InMessage, float InDuration)
{
	InventoryPickupNotificationWidget_eventBP_OnNotificationShown_Parms Parms;
	Parms.InMessage=InMessage;
	Parms.InDuration=InDuration;
	UFunction* Func = FindFunctionChecked(NAME_UInventoryPickupNotificationWidget_BP_OnNotificationShown);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UInventoryPickupNotificationWidget_BP_OnNotificationShown_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Notification" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Widget Blueprint\xec\x97\x90\xec\x84\x9c \xeb\x93\xb1\xec\x9e\xa5 \xec\x95\xa0\xeb\x8b\x88\xeb\xa9\x94\xec\x9d\xb4\xec\x85\x98 \xeb\x93\xb1\xec\x9d\x84 \xec\x8b\xa4\xed\x96\x89\xed\x95\xa0 \xeb\x95\x8c \xec\x82\xac\xec\x9a\xa9\xed\x95\x9c\xeb\x8b\xa4. */" },
#endif
		{ "DisplayName", "On Notification Shown" },
		{ "ModuleRelativePath", "Public/UI/InventoryPickupNotificationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Widget Blueprint\xec\x97\x90\xec\x84\x9c \xeb\x93\xb1\xec\x9e\xa5 \xec\x95\xa0\xeb\x8b\x88\xeb\xa9\x94\xec\x9d\xb4\xec\x85\x98 \xeb\x93\xb1\xec\x9d\x84 \xec\x8b\xa4\xed\x96\x89\xed\x95\xa0 \xeb\x95\x8c \xec\x82\xac\xec\x9a\xa9\xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function BP_OnNotificationShown constinit property declarations ****************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InMessage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InDuration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BP_OnNotificationShown constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BP_OnNotificationShown Property Definitions ***************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UInventoryPickupNotificationWidget_BP_OnNotificationShown_Statics::NewProp_InMessage = { "InMessage", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryPickupNotificationWidget_eventBP_OnNotificationShown_Parms, InMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InMessage_MetaData), NewProp_InMessage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UInventoryPickupNotificationWidget_BP_OnNotificationShown_Statics::NewProp_InDuration = { "InDuration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryPickupNotificationWidget_eventBP_OnNotificationShown_Parms, InDuration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryPickupNotificationWidget_BP_OnNotificationShown_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryPickupNotificationWidget_BP_OnNotificationShown_Statics::NewProp_InMessage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryPickupNotificationWidget_BP_OnNotificationShown_Statics::NewProp_InDuration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryPickupNotificationWidget_BP_OnNotificationShown_Statics::PropPointers) < 2048);
// ********** End Function BP_OnNotificationShown Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryPickupNotificationWidget_BP_OnNotificationShown_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryPickupNotificationWidget, nullptr, "BP_OnNotificationShown", 	Z_Construct_UFunction_UInventoryPickupNotificationWidget_BP_OnNotificationShown_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryPickupNotificationWidget_BP_OnNotificationShown_Statics::PropPointers), 
sizeof(InventoryPickupNotificationWidget_eventBP_OnNotificationShown_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08480800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryPickupNotificationWidget_BP_OnNotificationShown_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryPickupNotificationWidget_BP_OnNotificationShown_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(InventoryPickupNotificationWidget_eventBP_OnNotificationShown_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryPickupNotificationWidget_BP_OnNotificationShown()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryPickupNotificationWidget_BP_OnNotificationShown_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UInventoryPickupNotificationWidget Function BP_OnNotificationShown *********

// ********** Begin Class UInventoryPickupNotificationWidget Function ShowItemNotification *********
struct Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowItemNotification_Statics
{
	struct InventoryPickupNotificationWidget_eventShowItemNotification_Parms
	{
		FText InMessage;
		UTexture2D* InIcon;
		float InDuration;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Notification" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xec\x95\x84\xec\x9d\xb4\xec\xbd\x98\xea\xb3\xbc \xeb\xac\xb8\xea\xb5\xac\xeb\xa5\xbc \xed\x95\xa8\xea\xbb\x98 \xed\x91\x9c\xec\x8b\x9c\xed\x95\x9c\xeb\x8b\xa4. */" },
#endif
		{ "CPP_Default_InDuration", "2.000000" },
		{ "ModuleRelativePath", "Public/UI/InventoryPickupNotificationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xec\x95\x84\xec\x9d\xb4\xec\xbd\x98\xea\xb3\xbc \xeb\xac\xb8\xea\xb5\xac\xeb\xa5\xbc \xed\x95\xa8\xea\xbb\x98 \xed\x91\x9c\xec\x8b\x9c\xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ShowItemNotification constinit property declarations ******************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InMessage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InIcon;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InDuration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ShowItemNotification constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ShowItemNotification Property Definitions *****************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowItemNotification_Statics::NewProp_InMessage = { "InMessage", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryPickupNotificationWidget_eventShowItemNotification_Parms, InMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InMessage_MetaData), NewProp_InMessage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowItemNotification_Statics::NewProp_InIcon = { "InIcon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryPickupNotificationWidget_eventShowItemNotification_Parms, InIcon), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowItemNotification_Statics::NewProp_InDuration = { "InDuration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryPickupNotificationWidget_eventShowItemNotification_Parms, InDuration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowItemNotification_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowItemNotification_Statics::NewProp_InMessage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowItemNotification_Statics::NewProp_InIcon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowItemNotification_Statics::NewProp_InDuration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowItemNotification_Statics::PropPointers) < 2048);
// ********** End Function ShowItemNotification Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowItemNotification_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryPickupNotificationWidget, nullptr, "ShowItemNotification", 	Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowItemNotification_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowItemNotification_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowItemNotification_Statics::InventoryPickupNotificationWidget_eventShowItemNotification_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowItemNotification_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowItemNotification_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowItemNotification_Statics::InventoryPickupNotificationWidget_eventShowItemNotification_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowItemNotification()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowItemNotification_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryPickupNotificationWidget::execShowItemNotification)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_InMessage);
	P_GET_OBJECT(UTexture2D,Z_Param_InIcon);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InDuration);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ShowItemNotification(Z_Param_Out_InMessage,Z_Param_InIcon,Z_Param_InDuration);
	P_NATIVE_END;
}
// ********** End Class UInventoryPickupNotificationWidget Function ShowItemNotification ***********

// ********** Begin Class UInventoryPickupNotificationWidget Function ShowNotification *************
struct Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowNotification_Statics
{
	struct InventoryPickupNotificationWidget_eventShowNotification_Parms
	{
		FText InMessage;
		float InDuration;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Inventory|Notification" },
		{ "CPP_Default_InDuration", "2.000000" },
		{ "ModuleRelativePath", "Public/UI/InventoryPickupNotificationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ShowNotification constinit property declarations **********************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InMessage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InDuration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ShowNotification constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ShowNotification Property Definitions *********************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowNotification_Statics::NewProp_InMessage = { "InMessage", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryPickupNotificationWidget_eventShowNotification_Parms, InMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InMessage_MetaData), NewProp_InMessage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowNotification_Statics::NewProp_InDuration = { "InDuration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InventoryPickupNotificationWidget_eventShowNotification_Parms, InDuration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowNotification_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowNotification_Statics::NewProp_InMessage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowNotification_Statics::NewProp_InDuration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowNotification_Statics::PropPointers) < 2048);
// ********** End Function ShowNotification Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowNotification_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UInventoryPickupNotificationWidget, nullptr, "ShowNotification", 	Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowNotification_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowNotification_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowNotification_Statics::InventoryPickupNotificationWidget_eventShowNotification_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowNotification_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowNotification_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowNotification_Statics::InventoryPickupNotificationWidget_eventShowNotification_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowNotification()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowNotification_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UInventoryPickupNotificationWidget::execShowNotification)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_InMessage);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InDuration);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ShowNotification(Z_Param_Out_InMessage,Z_Param_InDuration);
	P_NATIVE_END;
}
// ********** End Class UInventoryPickupNotificationWidget Function ShowNotification ***************

// ********** Begin Class UInventoryPickupNotificationWidget ***************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UInventoryPickupNotificationWidget;
UClass* UInventoryPickupNotificationWidget::GetPrivateStaticClass()
{
	using TClass = UInventoryPickupNotificationWidget;
	if (!Z_Registration_Info_UClass_UInventoryPickupNotificationWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("InventoryPickupNotificationWidget"),
			Z_Registration_Info_UClass_UInventoryPickupNotificationWidget.InnerSingleton,
			StaticRegisterNativesUInventoryPickupNotificationWidget,
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
	return Z_Registration_Info_UClass_UInventoryPickupNotificationWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UInventoryPickupNotificationWidget_NoRegister()
{
	return UInventoryPickupNotificationWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UInventoryPickupNotificationWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Widget Blueprint \xec\x97\x86\xec\x9d\xb4\xeb\x8f\x84 \xec\x82\xac\xec\x9a\xa9\xed\x95\xa0 \xec\x88\x98 \xec\x9e\x88\xeb\x8a\x94 \xea\xb8\xb0\xeb\xb3\xb8 \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xed\x9a\x8d\xeb\x93\x9d \xec\x95\x8c\xeb\xa6\xbc\xec\x9d\xb4\xeb\x8b\xa4. */" },
#endif
		{ "IncludePath", "UI/InventoryPickupNotificationWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryPickupNotificationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Widget Blueprint \xec\x97\x86\xec\x9d\xb4\xeb\x8f\x84 \xec\x82\xac\xec\x9a\xa9\xed\x95\xa0 \xec\x88\x98 \xec\x9e\x88\xeb\x8a\x94 \xea\xb8\xb0\xeb\xb3\xb8 \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xed\x9a\x8d\xeb\x93\x9d \xec\x95\x8c\xeb\xa6\xbc\xec\x9d\xb4\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_Message_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "Inventory|Notification" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Widget Blueprint\xec\x97\x90\xec\x84\x9c \xec\x95\x8c\xeb\xa6\xbc \xeb\xac\xb8\xea\xb5\xac\xeb\xa5\xbc \xed\x91\x9c\xec\x8b\x9c\xed\x95\xa0 TextBlock.\n\x09 * WBP \xec\x9e\x90\xec\x8b\x9d \xec\x9c\x84\xec\xa0\xaf\xec\x97\x90\xec\x84\x9c\xeb\x8a\x94 TextBlock \xec\x9d\xb4\xeb\xa6\x84\xec\x9d\x84 \xec\xa0\x95\xed\x99\x95\xed\x9e\x88 Text_Message\xeb\xa1\x9c \xeb\xa7\x8c\xeb\x93\xa4\xea\xb3\xa0\n\x09 * Is Variable\xec\x9d\x84 \xec\xb2\xb4\xed\x81\xac\xed\x95\x9c\xeb\x8b\xa4. \xec\x9c\x84\xec\xa0\xaf\xec\x9d\xb4 \xec\x97\x86\xec\x9c\xbc\xeb\xa9\xb4 C++ \xea\xb8\xb0\xeb\xb3\xb8 Slate \xec\x95\x8c\xeb\xa6\xbc\xec\x9d\x84 \xec\x82\xac\xec\x9a\xa9\xed\x95\x9c\xeb\x8b\xa4.\n\x09 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryPickupNotificationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Widget Blueprint\xec\x97\x90\xec\x84\x9c \xec\x95\x8c\xeb\xa6\xbc \xeb\xac\xb8\xea\xb5\xac\xeb\xa5\xbc \xed\x91\x9c\xec\x8b\x9c\xed\x95\xa0 TextBlock.\nWBP \xec\x9e\x90\xec\x8b\x9d \xec\x9c\x84\xec\xa0\xaf\xec\x97\x90\xec\x84\x9c\xeb\x8a\x94 TextBlock \xec\x9d\xb4\xeb\xa6\x84\xec\x9d\x84 \xec\xa0\x95\xed\x99\x95\xed\x9e\x88 Text_Message\xeb\xa1\x9c \xeb\xa7\x8c\xeb\x93\xa4\xea\xb3\xa0\nIs Variable\xec\x9d\x84 \xec\xb2\xb4\xed\x81\xac\xed\x95\x9c\xeb\x8b\xa4. \xec\x9c\x84\xec\xa0\xaf\xec\x9d\xb4 \xec\x97\x86\xec\x9c\xbc\xeb\xa9\xb4 C++ \xea\xb8\xb0\xeb\xb3\xb8 Slate \xec\x95\x8c\xeb\xa6\xbc\xec\x9d\x84 \xec\x82\xac\xec\x9a\xa9\xed\x95\x9c\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Image_ItemIcon_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "Inventory|Notification" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** WBP\xec\x9d\x98 \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xec\x95\x84\xec\x9d\xb4\xec\xbd\x98. \xec\x9c\x84\xec\xa0\xaf \xec\x9d\xb4\xeb\xa6\x84\xec\x9d\x84 \xec\xa0\x95\xed\x99\x95\xed\x9e\x88 Image_ItemIcon\xec\x9c\xbc\xeb\xa1\x9c \xeb\xa7\x8c\xeb\x93\xa0\xeb\x8b\xa4. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryPickupNotificationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "WBP\xec\x9d\x98 \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c \xec\x95\x84\xec\x9d\xb4\xec\xbd\x98. \xec\x9c\x84\xec\xa0\xaf \xec\x9d\xb4\xeb\xa6\x84\xec\x9d\x84 \xec\xa0\x95\xed\x99\x95\xed\x9e\x88 Image_ItemIcon\xec\x9c\xbc\xeb\xa1\x9c \xeb\xa7\x8c\xeb\x93\xa0\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SizeBox_Icon_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "Inventory|Notification" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xec\x95\x84\xec\x9d\xb4\xec\xbd\x98\xec\x9d\xb4 \xec\x97\x86\xeb\x8a\x94 \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c\xec\x9d\xbc \xeb\x95\x8c \xeb\xb9\x88 \xea\xb3\xb5\xea\xb0\x84\xea\xb9\x8c\xec\xa7\x80 \xec\x88\xa8\xea\xb8\xb0\xea\xb8\xb0 \xec\x9c\x84\xed\x95\x9c \xec\x84\xa0\xed\x83\x9d \xec\x9c\x84\xec\xa0\xaf. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/InventoryPickupNotificationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x95\x84\xec\x9d\xb4\xec\xbd\x98\xec\x9d\xb4 \xec\x97\x86\xeb\x8a\x94 \xec\x95\x84\xec\x9d\xb4\xed\x85\x9c\xec\x9d\xbc \xeb\x95\x8c \xeb\xb9\x88 \xea\xb3\xb5\xea\xb0\x84\xea\xb9\x8c\xec\xa7\x80 \xec\x88\xa8\xea\xb8\xb0\xea\xb8\xb0 \xec\x9c\x84\xed\x95\x9c \xec\x84\xa0\xed\x83\x9d \xec\x9c\x84\xec\xa0\xaf." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UInventoryPickupNotificationWidget constinit property declarations *******
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Text_Message;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Image_ItemIcon;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SizeBox_Icon;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UInventoryPickupNotificationWidget constinit property declarations *********
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ShowItemNotification"), .Pointer = &UInventoryPickupNotificationWidget::execShowItemNotification },
		{ .NameUTF8 = UTF8TEXT("ShowNotification"), .Pointer = &UInventoryPickupNotificationWidget::execShowNotification },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventoryPickupNotificationWidget_BP_OnNotificationShown, "BP_OnNotificationShown" }, // 797947536
		{ &Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowItemNotification, "ShowItemNotification" }, // 101076137
		{ &Z_Construct_UFunction_UInventoryPickupNotificationWidget_ShowNotification, "ShowNotification" }, // 4116106974
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryPickupNotificationWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UInventoryPickupNotificationWidget_Statics

// ********** Begin Class UInventoryPickupNotificationWidget Property Definitions ******************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryPickupNotificationWidget_Statics::NewProp_Text_Message = { "Text_Message", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryPickupNotificationWidget, Text_Message), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_Message_MetaData), NewProp_Text_Message_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryPickupNotificationWidget_Statics::NewProp_Image_ItemIcon = { "Image_ItemIcon", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryPickupNotificationWidget, Image_ItemIcon), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Image_ItemIcon_MetaData), NewProp_Image_ItemIcon_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryPickupNotificationWidget_Statics::NewProp_SizeBox_Icon = { "SizeBox_Icon", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInventoryPickupNotificationWidget, SizeBox_Icon), Z_Construct_UClass_USizeBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SizeBox_Icon_MetaData), NewProp_SizeBox_Icon_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventoryPickupNotificationWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryPickupNotificationWidget_Statics::NewProp_Text_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryPickupNotificationWidget_Statics::NewProp_Image_ItemIcon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryPickupNotificationWidget_Statics::NewProp_SizeBox_Icon,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryPickupNotificationWidget_Statics::PropPointers) < 2048);
// ********** End Class UInventoryPickupNotificationWidget Property Definitions ********************
UObject* (*const Z_Construct_UClass_UInventoryPickupNotificationWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_InventorySystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryPickupNotificationWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventoryPickupNotificationWidget_Statics::ClassParams = {
	&UInventoryPickupNotificationWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UInventoryPickupNotificationWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryPickupNotificationWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryPickupNotificationWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UInventoryPickupNotificationWidget_Statics::Class_MetaDataParams)
};
void UInventoryPickupNotificationWidget::StaticRegisterNativesUInventoryPickupNotificationWidget()
{
	UClass* Class = UInventoryPickupNotificationWidget::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UInventoryPickupNotificationWidget_Statics::Funcs));
}
UClass* Z_Construct_UClass_UInventoryPickupNotificationWidget()
{
	if (!Z_Registration_Info_UClass_UInventoryPickupNotificationWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventoryPickupNotificationWidget.OuterSingleton, Z_Construct_UClass_UInventoryPickupNotificationWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInventoryPickupNotificationWidget.OuterSingleton;
}
UInventoryPickupNotificationWidget::UInventoryPickupNotificationWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UInventoryPickupNotificationWidget);
UInventoryPickupNotificationWidget::~UInventoryPickupNotificationWidget() {}
// ********** End Class UInventoryPickupNotificationWidget *****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryPickupNotificationWidget_h__Script_InventorySystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInventoryPickupNotificationWidget, UInventoryPickupNotificationWidget::StaticClass, TEXT("UInventoryPickupNotificationWidget"), &Z_Registration_Info_UClass_UInventoryPickupNotificationWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventoryPickupNotificationWidget), 3514374219U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryPickupNotificationWidget_h__Script_InventorySystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryPickupNotificationWidget_h__Script_InventorySystem_2927879532{
	TEXT("/Script/InventorySystem"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryPickupNotificationWidget_h__Script_InventorySystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryPickupNotificationWidget_h__Script_InventorySystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
