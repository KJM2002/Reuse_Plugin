// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ItemInspection/JMItemInspectionData.h"
#include "ItemInspection/JMItemInspectionTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMItemInspectionData() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMItemInspectionData();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMItemInspectionData_NoRegister();
ITEMINSPECTORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings();
ITEMINSPECTORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings();
ITEMINSPECTORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMItemInspectionViewSettings();
UPackage* Z_Construct_UPackage__Script_ItemInspectorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMItemInspectionData ****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMItemInspectionData;
UClass* UJMItemInspectionData::GetPrivateStaticClass()
{
	using TClass = UJMItemInspectionData;
	if (!Z_Registration_Info_UClass_UJMItemInspectionData.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMItemInspectionData"),
			Z_Registration_Info_UClass_UJMItemInspectionData.InnerSingleton,
			StaticRegisterNativesUJMItemInspectionData,
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
	return Z_Registration_Info_UClass_UJMItemInspectionData.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMItemInspectionData_NoRegister()
{
	return UJMItemInspectionData::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMItemInspectionData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "ItemInspection/JMItemInspectionData.h" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemId_MetaData[] = {
		{ "Category", "Identity" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[] = {
		{ "Category", "Text" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayCategory_MetaData[] = {
		{ "Category", "Text" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "Text" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionData.h" },
		{ "MultiLine", "TRUE" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdditionalInfo_MetaData[] = {
		{ "Category", "Text" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionData.h" },
		{ "MultiLine", "TRUE" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewMesh_MetaData[] = {
		{ "Category", "Preview" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterialOverrides_MetaData[] = {
		{ "Category", "Preview" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ViewSettings_MetaData[] = {
		{ "Category", "Preview" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideTransitionSettings_MetaData[] = {
		{ "Category", "Preview|Transition" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TransitionSettings_MetaData[] = {
		{ "Category", "Preview|Transition" },
		{ "EditCondition", "bOverrideTransitionSettings" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SurfaceWidget_MetaData[] = {
		{ "Category", "Preview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional dynamic UMG content rendered on the preview surface (notes, cards, screens). */" },
#endif
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional dynamic UMG content rendered on the preview surface (notes, cards, screens)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UJMItemInspectionData constinit property declarations ********************
	static const UECodeGen_Private::FNamePropertyParams NewProp_ItemId;
	static const UECodeGen_Private::FTextPropertyParams NewProp_DisplayName;
	static const UECodeGen_Private::FTextPropertyParams NewProp_DisplayCategory;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Description;
	static const UECodeGen_Private::FTextPropertyParams NewProp_AdditionalInfo;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_PreviewMesh;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_MaterialOverrides_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MaterialOverrides;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ViewSettings;
	static void NewProp_bOverrideTransitionSettings_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideTransitionSettings;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TransitionSettings;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SurfaceWidget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMItemInspectionData constinit property declarations **********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMItemInspectionData>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMItemInspectionData_Statics

// ********** Begin Class UJMItemInspectionData Property Definitions *******************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_ItemId = { "ItemId", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionData, ItemId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemId_MetaData), NewProp_ItemId_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionData, DisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayName_MetaData), NewProp_DisplayName_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_DisplayCategory = { "DisplayCategory", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionData, DisplayCategory), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayCategory_MetaData), NewProp_DisplayCategory_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionData, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_AdditionalInfo = { "AdditionalInfo", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionData, AdditionalInfo), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdditionalInfo_MetaData), NewProp_AdditionalInfo_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_PreviewMesh = { "PreviewMesh", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionData, PreviewMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewMesh_MetaData), NewProp_PreviewMesh_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_MaterialOverrides_Inner = { "MaterialOverrides", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_MaterialOverrides = { "MaterialOverrides", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionData, MaterialOverrides), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterialOverrides_MetaData), NewProp_MaterialOverrides_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_ViewSettings = { "ViewSettings", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionData, ViewSettings), Z_Construct_UScriptStruct_FJMItemInspectionViewSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ViewSettings_MetaData), NewProp_ViewSettings_MetaData) }; // 1658798872
void Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_bOverrideTransitionSettings_SetBit(void* Obj)
{
	((UJMItemInspectionData*)Obj)->bOverrideTransitionSettings = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_bOverrideTransitionSettings = { "bOverrideTransitionSettings", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMItemInspectionData), &Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_bOverrideTransitionSettings_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideTransitionSettings_MetaData), NewProp_bOverrideTransitionSettings_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_TransitionSettings = { "TransitionSettings", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionData, TransitionSettings), Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TransitionSettings_MetaData), NewProp_TransitionSettings_MetaData) }; // 1121746411
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_SurfaceWidget = { "SurfaceWidget", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionData, SurfaceWidget), Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SurfaceWidget_MetaData), NewProp_SurfaceWidget_MetaData) }; // 2221587353
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMItemInspectionData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_ItemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_DisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_DisplayCategory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_AdditionalInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_PreviewMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_MaterialOverrides_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_MaterialOverrides,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_ViewSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_bOverrideTransitionSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_TransitionSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionData_Statics::NewProp_SurfaceWidget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMItemInspectionData_Statics::PropPointers) < 2048);
// ********** End Class UJMItemInspectionData Property Definitions *********************************
UObject* (*const Z_Construct_UClass_UJMItemInspectionData_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_ItemInspectorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMItemInspectionData_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMItemInspectionData_Statics::ClassParams = {
	&UJMItemInspectionData::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMItemInspectionData_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMItemInspectionData_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMItemInspectionData_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMItemInspectionData_Statics::Class_MetaDataParams)
};
void UJMItemInspectionData::StaticRegisterNativesUJMItemInspectionData()
{
}
UClass* Z_Construct_UClass_UJMItemInspectionData()
{
	if (!Z_Registration_Info_UClass_UJMItemInspectionData.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMItemInspectionData.OuterSingleton, Z_Construct_UClass_UJMItemInspectionData_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMItemInspectionData.OuterSingleton;
}
UJMItemInspectionData::UJMItemInspectionData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMItemInspectionData);
UJMItemInspectionData::~UJMItemInspectionData() {}
// ********** End Class UJMItemInspectionData ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionData_h__Script_ItemInspectorRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMItemInspectionData, UJMItemInspectionData::StaticClass, TEXT("UJMItemInspectionData"), &Z_Registration_Info_UClass_UJMItemInspectionData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMItemInspectionData), 401297384U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionData_h__Script_ItemInspectorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionData_h__Script_ItemInspectorRuntime_1282824157{
	TEXT("/Script/ItemInspectorRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionData_h__Script_ItemInspectorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionData_h__Script_ItemInspectorRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
