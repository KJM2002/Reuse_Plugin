// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/JMObjectiveDefaultWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMObjectiveDefaultWidget() {}

// ********** Begin Cross Module References ********************************************************
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveDefaultWidget();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveDefaultWidget_NoRegister();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveWidgetBase();
UPackage* Z_Construct_UPackage__Script_JMObjective();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMObjectiveDefaultWidget ************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMObjectiveDefaultWidget;
UClass* UJMObjectiveDefaultWidget::GetPrivateStaticClass()
{
	using TClass = UJMObjectiveDefaultWidget;
	if (!Z_Registration_Info_UClass_UJMObjectiveDefaultWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMObjectiveDefaultWidget"),
			Z_Registration_Info_UClass_UJMObjectiveDefaultWidget.InnerSingleton,
			StaticRegisterNativesUJMObjectiveDefaultWidget,
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
	return Z_Registration_Info_UClass_UJMObjectiveDefaultWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMObjectiveDefaultWidget_NoRegister()
{
	return UJMObjectiveDefaultWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMObjectiveDefaultWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Minimal no-Blueprint fallback UI. Projects can replace it in Project Settings > Plugins > JM Objective. */" },
#endif
		{ "IncludePath", "UI/JMObjectiveDefaultWidget.h" },
		{ "ModuleRelativePath", "Public/UI/JMObjectiveDefaultWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Minimal no-Blueprint fallback UI. Projects can replace it in Project Settings > Plugins > JM Objective." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UJMObjectiveDefaultWidget constinit property declarations ****************
// ********** End Class UJMObjectiveDefaultWidget constinit property declarations ******************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMObjectiveDefaultWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMObjectiveDefaultWidget_Statics
UObject* (*const Z_Construct_UClass_UJMObjectiveDefaultWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UJMObjectiveWidgetBase,
	(UObject* (*)())Z_Construct_UPackage__Script_JMObjective,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveDefaultWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMObjectiveDefaultWidget_Statics::ClassParams = {
	&UJMObjectiveDefaultWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveDefaultWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMObjectiveDefaultWidget_Statics::Class_MetaDataParams)
};
void UJMObjectiveDefaultWidget::StaticRegisterNativesUJMObjectiveDefaultWidget()
{
}
UClass* Z_Construct_UClass_UJMObjectiveDefaultWidget()
{
	if (!Z_Registration_Info_UClass_UJMObjectiveDefaultWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMObjectiveDefaultWidget.OuterSingleton, Z_Construct_UClass_UJMObjectiveDefaultWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMObjectiveDefaultWidget.OuterSingleton;
}
UJMObjectiveDefaultWidget::UJMObjectiveDefaultWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMObjectiveDefaultWidget);
UJMObjectiveDefaultWidget::~UJMObjectiveDefaultWidget() {}
// ********** End Class UJMObjectiveDefaultWidget **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_UI_JMObjectiveDefaultWidget_h__Script_JMObjective_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMObjectiveDefaultWidget, UJMObjectiveDefaultWidget::StaticClass, TEXT("UJMObjectiveDefaultWidget"), &Z_Registration_Info_UClass_UJMObjectiveDefaultWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMObjectiveDefaultWidget), 3225403622U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_UI_JMObjectiveDefaultWidget_h__Script_JMObjective_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_UI_JMObjectiveDefaultWidget_h__Script_JMObjective_3413113605{
	TEXT("/Script/JMObjective"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_UI_JMObjectiveDefaultWidget_h__Script_JMObjective_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_UI_JMObjectiveDefaultWidget_h__Script_JMObjective_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
