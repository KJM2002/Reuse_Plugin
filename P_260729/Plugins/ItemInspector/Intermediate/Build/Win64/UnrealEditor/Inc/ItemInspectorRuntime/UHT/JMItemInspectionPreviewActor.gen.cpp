// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ItemInspection/JMItemInspectionPreviewActor.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMItemInspectionPreviewActor() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UPointLightComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneCaptureComponent2D_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpotLightComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_AJMItemInspectionPreviewActor();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_AJMItemInspectionPreviewActor_NoRegister();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMItemInspectionData_NoRegister();
UMG_API UClass* Z_Construct_UClass_UWidgetComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_ItemInspectorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AJMItemInspectionPreviewActor ********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AJMItemInspectionPreviewActor;
UClass* AJMItemInspectionPreviewActor::GetPrivateStaticClass()
{
	using TClass = AJMItemInspectionPreviewActor;
	if (!Z_Registration_Info_UClass_AJMItemInspectionPreviewActor.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMItemInspectionPreviewActor"),
			Z_Registration_Info_UClass_AJMItemInspectionPreviewActor.InnerSingleton,
			StaticRegisterNativesAJMItemInspectionPreviewActor,
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
	return Z_Registration_Info_UClass_AJMItemInspectionPreviewActor.InnerSingleton;
}
UClass* Z_Construct_UClass_AJMItemInspectionPreviewActor_NoRegister()
{
	return AJMItemInspectionPreviewActor::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "ItemInspection/JMItemInspectionPreviewActor.h" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionPreviewActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneRoot_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionPreviewActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewPivot_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionPreviewActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewMeshComponent_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionPreviewActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SurfaceWidgetComponent_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional world-space UMG surface attached to PreviewPivot. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionPreviewActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional world-space UMG surface attached to PreviewPivot." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneCapture_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionPreviewActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_KeyLight_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionPreviewActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FillLight_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionPreviewActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RimLight_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionPreviewActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentInspectionData_MetaData[] = {
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionPreviewActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AJMItemInspectionPreviewActor constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneRoot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewPivot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PreviewMeshComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SurfaceWidgetComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneCapture;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_KeyLight;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FillLight;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RimLight;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentInspectionData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AJMItemInspectionPreviewActor constinit property declarations **************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AJMItemInspectionPreviewActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics

// ********** Begin Class AJMItemInspectionPreviewActor Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::NewProp_SceneRoot = { "SceneRoot", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMItemInspectionPreviewActor, SceneRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneRoot_MetaData), NewProp_SceneRoot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::NewProp_PreviewPivot = { "PreviewPivot", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMItemInspectionPreviewActor, PreviewPivot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewPivot_MetaData), NewProp_PreviewPivot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::NewProp_PreviewMeshComponent = { "PreviewMeshComponent", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMItemInspectionPreviewActor, PreviewMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewMeshComponent_MetaData), NewProp_PreviewMeshComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::NewProp_SurfaceWidgetComponent = { "SurfaceWidgetComponent", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMItemInspectionPreviewActor, SurfaceWidgetComponent), Z_Construct_UClass_UWidgetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SurfaceWidgetComponent_MetaData), NewProp_SurfaceWidgetComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::NewProp_SceneCapture = { "SceneCapture", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMItemInspectionPreviewActor, SceneCapture), Z_Construct_UClass_USceneCaptureComponent2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneCapture_MetaData), NewProp_SceneCapture_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::NewProp_KeyLight = { "KeyLight", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMItemInspectionPreviewActor, KeyLight), Z_Construct_UClass_USpotLightComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_KeyLight_MetaData), NewProp_KeyLight_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::NewProp_FillLight = { "FillLight", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMItemInspectionPreviewActor, FillLight), Z_Construct_UClass_UPointLightComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FillLight_MetaData), NewProp_FillLight_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::NewProp_RimLight = { "RimLight", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMItemInspectionPreviewActor, RimLight), Z_Construct_UClass_UPointLightComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RimLight_MetaData), NewProp_RimLight_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::NewProp_CurrentInspectionData = { "CurrentInspectionData", nullptr, (EPropertyFlags)0x0124080000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMItemInspectionPreviewActor, CurrentInspectionData), Z_Construct_UClass_UJMItemInspectionData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentInspectionData_MetaData), NewProp_CurrentInspectionData_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::NewProp_SceneRoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::NewProp_PreviewPivot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::NewProp_PreviewMeshComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::NewProp_SurfaceWidgetComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::NewProp_SceneCapture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::NewProp_KeyLight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::NewProp_FillLight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::NewProp_RimLight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::NewProp_CurrentInspectionData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::PropPointers) < 2048);
// ********** End Class AJMItemInspectionPreviewActor Property Definitions *************************
UObject* (*const Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_ItemInspectorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::ClassParams = {
	&AJMItemInspectionPreviewActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::PropPointers),
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::Class_MetaDataParams)
};
void AJMItemInspectionPreviewActor::StaticRegisterNativesAJMItemInspectionPreviewActor()
{
}
UClass* Z_Construct_UClass_AJMItemInspectionPreviewActor()
{
	if (!Z_Registration_Info_UClass_AJMItemInspectionPreviewActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AJMItemInspectionPreviewActor.OuterSingleton, Z_Construct_UClass_AJMItemInspectionPreviewActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AJMItemInspectionPreviewActor.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AJMItemInspectionPreviewActor);
AJMItemInspectionPreviewActor::~AJMItemInspectionPreviewActor() {}
// ********** End Class AJMItemInspectionPreviewActor **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionPreviewActor_h__Script_ItemInspectorRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AJMItemInspectionPreviewActor, AJMItemInspectionPreviewActor::StaticClass, TEXT("AJMItemInspectionPreviewActor"), &Z_Registration_Info_UClass_AJMItemInspectionPreviewActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AJMItemInspectionPreviewActor), 2777416958U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionPreviewActor_h__Script_ItemInspectorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionPreviewActor_h__Script_ItemInspectorRuntime_3384182840{
	TEXT("/Script/ItemInspectorRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionPreviewActor_h__Script_ItemInspectorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionPreviewActor_h__Script_ItemInspectorRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
