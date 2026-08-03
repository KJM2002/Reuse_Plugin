// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ItemInspection/JMItemInspectionSurfaceWidgetBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMItemInspectionSurfaceWidgetBase() {}

// ********** Begin Cross Module References ********************************************************
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_ItemInspectorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMItemInspectionSurfaceWidgetBase Function GetSurfaceContent ************
struct Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_GetSurfaceContent_Statics
{
	struct JMItemInspectionSurfaceWidgetBase_eventGetSurfaceContent_Parms
	{
		FText ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection|Surface Widget" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSurfaceWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSurfaceContent constinit property declarations *********************
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSurfaceContent constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSurfaceContent Property Definitions ********************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_GetSurfaceContent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionSurfaceWidgetBase_eventGetSurfaceContent_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_GetSurfaceContent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_GetSurfaceContent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_GetSurfaceContent_Statics::PropPointers) < 2048);
// ********** End Function GetSurfaceContent Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_GetSurfaceContent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase, nullptr, "GetSurfaceContent", 	Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_GetSurfaceContent_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_GetSurfaceContent_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_GetSurfaceContent_Statics::JMItemInspectionSurfaceWidgetBase_eventGetSurfaceContent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_GetSurfaceContent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_GetSurfaceContent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_GetSurfaceContent_Statics::JMItemInspectionSurfaceWidgetBase_eventGetSurfaceContent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_GetSurfaceContent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_GetSurfaceContent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMItemInspectionSurfaceWidgetBase::execGetSurfaceContent)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->GetSurfaceContent();
	P_NATIVE_END;
}
// ********** End Class UJMItemInspectionSurfaceWidgetBase Function GetSurfaceContent **************

// ********** Begin Class UJMItemInspectionSurfaceWidgetBase Function OnSurfaceContentChanged ******
struct JMItemInspectionSurfaceWidgetBase_eventOnSurfaceContentChanged_Parms
{
	FText InContent;
};
static FName NAME_UJMItemInspectionSurfaceWidgetBase_OnSurfaceContentChanged = FName(TEXT("OnSurfaceContentChanged"));
void UJMItemInspectionSurfaceWidgetBase::OnSurfaceContentChanged(FText const& InContent)
{
	JMItemInspectionSurfaceWidgetBase_eventOnSurfaceContentChanged_Parms Parms;
	Parms.InContent=InContent;
	UFunction* Func = FindFunctionChecked(NAME_UJMItemInspectionSurfaceWidgetBase_OnSurfaceContentChanged);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_OnSurfaceContentChanged_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection|Surface Widget" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSurfaceWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InContent_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OnSurfaceContentChanged constinit property declarations ***************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InContent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnSurfaceContentChanged constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnSurfaceContentChanged Property Definitions **************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_OnSurfaceContentChanged_Statics::NewProp_InContent = { "InContent", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionSurfaceWidgetBase_eventOnSurfaceContentChanged_Parms, InContent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InContent_MetaData), NewProp_InContent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_OnSurfaceContentChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_OnSurfaceContentChanged_Statics::NewProp_InContent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_OnSurfaceContentChanged_Statics::PropPointers) < 2048);
// ********** End Function OnSurfaceContentChanged Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_OnSurfaceContentChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase, nullptr, "OnSurfaceContentChanged", 	Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_OnSurfaceContentChanged_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_OnSurfaceContentChanged_Statics::PropPointers), 
sizeof(JMItemInspectionSurfaceWidgetBase_eventOnSurfaceContentChanged_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_OnSurfaceContentChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_OnSurfaceContentChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMItemInspectionSurfaceWidgetBase_eventOnSurfaceContentChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_OnSurfaceContentChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_OnSurfaceContentChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UJMItemInspectionSurfaceWidgetBase Function OnSurfaceContentChanged ********

// ********** Begin Class UJMItemInspectionSurfaceWidgetBase Function SetSurfaceContent ************
struct Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_SetSurfaceContent_Statics
{
	struct JMItemInspectionSurfaceWidgetBase_eventSetSurfaceContent_Parms
	{
		FText InContent;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection|Surface Widget" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSurfaceWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InContent_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetSurfaceContent constinit property declarations *********************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InContent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSurfaceContent constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSurfaceContent Property Definitions ********************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_SetSurfaceContent_Statics::NewProp_InContent = { "InContent", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMItemInspectionSurfaceWidgetBase_eventSetSurfaceContent_Parms, InContent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InContent_MetaData), NewProp_InContent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_SetSurfaceContent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_SetSurfaceContent_Statics::NewProp_InContent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_SetSurfaceContent_Statics::PropPointers) < 2048);
// ********** End Function SetSurfaceContent Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_SetSurfaceContent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase, nullptr, "SetSurfaceContent", 	Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_SetSurfaceContent_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_SetSurfaceContent_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_SetSurfaceContent_Statics::JMItemInspectionSurfaceWidgetBase_eventSetSurfaceContent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_SetSurfaceContent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_SetSurfaceContent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_SetSurfaceContent_Statics::JMItemInspectionSurfaceWidgetBase_eventSetSurfaceContent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_SetSurfaceContent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_SetSurfaceContent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMItemInspectionSurfaceWidgetBase::execSetSurfaceContent)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_InContent);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSurfaceContent(Z_Param_Out_InContent);
	P_NATIVE_END;
}
// ********** End Class UJMItemInspectionSurfaceWidgetBase Function SetSurfaceContent **************

// ********** Begin Class UJMItemInspectionSurfaceWidgetBase ***************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMItemInspectionSurfaceWidgetBase;
UClass* UJMItemInspectionSurfaceWidgetBase::GetPrivateStaticClass()
{
	using TClass = UJMItemInspectionSurfaceWidgetBase;
	if (!Z_Registration_Info_UClass_UJMItemInspectionSurfaceWidgetBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMItemInspectionSurfaceWidgetBase"),
			Z_Registration_Info_UClass_UJMItemInspectionSurfaceWidgetBase.InnerSingleton,
			StaticRegisterNativesUJMItemInspectionSurfaceWidgetBase,
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
	return Z_Registration_Info_UClass_UJMItemInspectionSurfaceWidgetBase.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase_NoRegister()
{
	return UJMItemInspectionSurfaceWidgetBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Base widget rendered on an inspected mesh surface.\n * A Blueprint may bind a TextBlock named SurfaceContentText, or leave its tree\n * empty and use the native readable fallback.\n */" },
#endif
		{ "IncludePath", "ItemInspection/JMItemInspectionSurfaceWidgetBase.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSurfaceWidgetBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base widget rendered on an inspected mesh surface.\nA Blueprint may bind a TextBlock named SurfaceContentText, or leave its tree\nempty and use the native readable fallback." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SurfaceContentText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "JM Gameplay|Item Inspection|Surface Widget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSurfaceWidgetBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SurfaceContent_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Surface Widget" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionSurfaceWidgetBase.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMItemInspectionSurfaceWidgetBase constinit property declarations *******
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SurfaceContentText;
	static const UECodeGen_Private::FTextPropertyParams NewProp_SurfaceContent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMItemInspectionSurfaceWidgetBase constinit property declarations *********
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetSurfaceContent"), .Pointer = &UJMItemInspectionSurfaceWidgetBase::execGetSurfaceContent },
		{ .NameUTF8 = UTF8TEXT("SetSurfaceContent"), .Pointer = &UJMItemInspectionSurfaceWidgetBase::execSetSurfaceContent },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_GetSurfaceContent, "GetSurfaceContent" }, // 2319213346
		{ &Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_OnSurfaceContentChanged, "OnSurfaceContentChanged" }, // 2208703264
		{ &Z_Construct_UFunction_UJMItemInspectionSurfaceWidgetBase_SetSurfaceContent, "SetSurfaceContent" }, // 3618067623
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMItemInspectionSurfaceWidgetBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase_Statics

// ********** Begin Class UJMItemInspectionSurfaceWidgetBase Property Definitions ******************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase_Statics::NewProp_SurfaceContentText = { "SurfaceContentText", nullptr, (EPropertyFlags)0x012408000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionSurfaceWidgetBase, SurfaceContentText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SurfaceContentText_MetaData), NewProp_SurfaceContentText_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase_Statics::NewProp_SurfaceContent = { "SurfaceContent", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionSurfaceWidgetBase, SurfaceContent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SurfaceContent_MetaData), NewProp_SurfaceContent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase_Statics::NewProp_SurfaceContentText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase_Statics::NewProp_SurfaceContent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase_Statics::PropPointers) < 2048);
// ********** End Class UJMItemInspectionSurfaceWidgetBase Property Definitions ********************
UObject* (*const Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_ItemInspectorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase_Statics::ClassParams = {
	&UJMItemInspectionSurfaceWidgetBase::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase_Statics::Class_MetaDataParams)
};
void UJMItemInspectionSurfaceWidgetBase::StaticRegisterNativesUJMItemInspectionSurfaceWidgetBase()
{
	UClass* Class = UJMItemInspectionSurfaceWidgetBase::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase()
{
	if (!Z_Registration_Info_UClass_UJMItemInspectionSurfaceWidgetBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMItemInspectionSurfaceWidgetBase.OuterSingleton, Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMItemInspectionSurfaceWidgetBase.OuterSingleton;
}
UJMItemInspectionSurfaceWidgetBase::UJMItemInspectionSurfaceWidgetBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMItemInspectionSurfaceWidgetBase);
UJMItemInspectionSurfaceWidgetBase::~UJMItemInspectionSurfaceWidgetBase() {}
// ********** End Class UJMItemInspectionSurfaceWidgetBase *****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionSurfaceWidgetBase_h__Script_ItemInspectorRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase, UJMItemInspectionSurfaceWidgetBase::StaticClass, TEXT("UJMItemInspectionSurfaceWidgetBase"), &Z_Registration_Info_UClass_UJMItemInspectionSurfaceWidgetBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMItemInspectionSurfaceWidgetBase), 4289149437U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionSurfaceWidgetBase_h__Script_ItemInspectorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionSurfaceWidgetBase_h__Script_ItemInspectorRuntime_4215863730{
	TEXT("/Script/ItemInspectorRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionSurfaceWidgetBase_h__Script_ItemInspectorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionSurfaceWidgetBase_h__Script_ItemInspectorRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
