// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ItemInspection/JMItemInspectionTransitionWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMItemInspectionTransitionWidget() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMItemInspectionTransitionWidget();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMItemInspectionTransitionWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UCanvasPanel_NoRegister();
UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_ItemInspectorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMItemInspectionTransitionWidget ****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMItemInspectionTransitionWidget;
UClass* UJMItemInspectionTransitionWidget::GetPrivateStaticClass()
{
	using TClass = UJMItemInspectionTransitionWidget;
	if (!Z_Registration_Info_UClass_UJMItemInspectionTransitionWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMItemInspectionTransitionWidget"),
			Z_Registration_Info_UClass_UJMItemInspectionTransitionWidget.InnerSingleton,
			StaticRegisterNativesUJMItemInspectionTransitionWidget,
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
	return Z_Registration_Info_UClass_UJMItemInspectionTransitionWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMItemInspectionTransitionWidget_NoRegister()
{
	return UJMItemInspectionTransitionWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMItemInspectionTransitionWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Full-viewport, hit-test-invisible image used while a world item flies into the inspector. */" },
#endif
		{ "IncludePath", "ItemInspection/JMItemInspectionTransitionWidget.h" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTransitionWidget.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Full-viewport, hit-test-invisible image used while a world item flies into the inspector." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RootCanvas_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTransitionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TransitionImage_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTransitionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewMaterialAsset_MetaData[] = {
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTransitionWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewMaterialInstance_MetaData[] = {
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTransitionWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMItemInspectionTransitionWidget constinit property declarations ********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RootCanvas;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TransitionImage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewMaterialAsset;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewMaterialInstance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMItemInspectionTransitionWidget constinit property declarations **********
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMItemInspectionTransitionWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMItemInspectionTransitionWidget_Statics

// ********** Begin Class UJMItemInspectionTransitionWidget Property Definitions *******************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionTransitionWidget_Statics::NewProp_RootCanvas = { "RootCanvas", nullptr, (EPropertyFlags)0x0124080000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionTransitionWidget, RootCanvas), Z_Construct_UClass_UCanvasPanel_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RootCanvas_MetaData), NewProp_RootCanvas_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionTransitionWidget_Statics::NewProp_TransitionImage = { "TransitionImage", nullptr, (EPropertyFlags)0x0124080000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionTransitionWidget, TransitionImage), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TransitionImage_MetaData), NewProp_TransitionImage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionTransitionWidget_Statics::NewProp_PreviewMaterialAsset = { "PreviewMaterialAsset", nullptr, (EPropertyFlags)0x0124080000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionTransitionWidget, PreviewMaterialAsset), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewMaterialAsset_MetaData), NewProp_PreviewMaterialAsset_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMItemInspectionTransitionWidget_Statics::NewProp_PreviewMaterialInstance = { "PreviewMaterialInstance", nullptr, (EPropertyFlags)0x0124080000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMItemInspectionTransitionWidget, PreviewMaterialInstance), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewMaterialInstance_MetaData), NewProp_PreviewMaterialInstance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMItemInspectionTransitionWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionTransitionWidget_Statics::NewProp_RootCanvas,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionTransitionWidget_Statics::NewProp_TransitionImage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionTransitionWidget_Statics::NewProp_PreviewMaterialAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMItemInspectionTransitionWidget_Statics::NewProp_PreviewMaterialInstance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMItemInspectionTransitionWidget_Statics::PropPointers) < 2048);
// ********** End Class UJMItemInspectionTransitionWidget Property Definitions *********************
UObject* (*const Z_Construct_UClass_UJMItemInspectionTransitionWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_ItemInspectorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMItemInspectionTransitionWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMItemInspectionTransitionWidget_Statics::ClassParams = {
	&UJMItemInspectionTransitionWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMItemInspectionTransitionWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMItemInspectionTransitionWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMItemInspectionTransitionWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMItemInspectionTransitionWidget_Statics::Class_MetaDataParams)
};
void UJMItemInspectionTransitionWidget::StaticRegisterNativesUJMItemInspectionTransitionWidget()
{
}
UClass* Z_Construct_UClass_UJMItemInspectionTransitionWidget()
{
	if (!Z_Registration_Info_UClass_UJMItemInspectionTransitionWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMItemInspectionTransitionWidget.OuterSingleton, Z_Construct_UClass_UJMItemInspectionTransitionWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMItemInspectionTransitionWidget.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMItemInspectionTransitionWidget);
UJMItemInspectionTransitionWidget::~UJMItemInspectionTransitionWidget() {}
// ********** End Class UJMItemInspectionTransitionWidget ******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionTransitionWidget_h__Script_ItemInspectorRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMItemInspectionTransitionWidget, UJMItemInspectionTransitionWidget::StaticClass, TEXT("UJMItemInspectionTransitionWidget"), &Z_Registration_Info_UClass_UJMItemInspectionTransitionWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMItemInspectionTransitionWidget), 1268305427U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionTransitionWidget_h__Script_ItemInspectorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionTransitionWidget_h__Script_ItemInspectorRuntime_4203232904{
	TEXT("/Script/ItemInspectorRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionTransitionWidget_h__Script_ItemInspectorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionTransitionWidget_h__Script_ItemInspectorRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
