// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JMThrowableStatusWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMThrowableStatusWidget() {}

// ********** Begin Cross Module References ********************************************************
JMTHROWABLEGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMThrowableStatusWidget();
JMTHROWABLEGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMThrowableStatusWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_JMThrowableGameplayIntegration();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMThrowableStatusWidget *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMThrowableStatusWidget;
UClass* UJMThrowableStatusWidget::GetPrivateStaticClass()
{
	using TClass = UJMThrowableStatusWidget;
	if (!Z_Registration_Info_UClass_UJMThrowableStatusWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMThrowableStatusWidget"),
			Z_Registration_Info_UClass_UJMThrowableStatusWidget.InnerSingleton,
			StaticRegisterNativesUJMThrowableStatusWidget,
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
	return Z_Registration_Info_UClass_UJMThrowableStatusWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMThrowableStatusWidget_NoRegister()
{
	return UJMThrowableStatusWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMThrowableStatusWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Asset-free local-player status hint for the active throwable session. */" },
#endif
		{ "IncludePath", "JMThrowableStatusWidget.h" },
		{ "ModuleRelativePath", "Public/JMThrowableStatusWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Asset-free local-player status hint for the active throwable session." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StatusText_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableStatusWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMThrowableStatusWidget constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StatusText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMThrowableStatusWidget constinit property declarations *******************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMThrowableStatusWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMThrowableStatusWidget_Statics

// ********** Begin Class UJMThrowableStatusWidget Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMThrowableStatusWidget_Statics::NewProp_StatusText = { "StatusText", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableStatusWidget, StatusText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StatusText_MetaData), NewProp_StatusText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMThrowableStatusWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableStatusWidget_Statics::NewProp_StatusText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableStatusWidget_Statics::PropPointers) < 2048);
// ********** End Class UJMThrowableStatusWidget Property Definitions ******************************
UObject* (*const Z_Construct_UClass_UJMThrowableStatusWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_JMThrowableGameplayIntegration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableStatusWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMThrowableStatusWidget_Statics::ClassParams = {
	&UJMThrowableStatusWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMThrowableStatusWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableStatusWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableStatusWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMThrowableStatusWidget_Statics::Class_MetaDataParams)
};
void UJMThrowableStatusWidget::StaticRegisterNativesUJMThrowableStatusWidget()
{
}
UClass* Z_Construct_UClass_UJMThrowableStatusWidget()
{
	if (!Z_Registration_Info_UClass_UJMThrowableStatusWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMThrowableStatusWidget.OuterSingleton, Z_Construct_UClass_UJMThrowableStatusWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMThrowableStatusWidget.OuterSingleton;
}
UJMThrowableStatusWidget::UJMThrowableStatusWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMThrowableStatusWidget);
UJMThrowableStatusWidget::~UJMThrowableStatusWidget() {}
// ********** End Class UJMThrowableStatusWidget ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableStatusWidget_h__Script_JMThrowableGameplayIntegration_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMThrowableStatusWidget, UJMThrowableStatusWidget::StaticClass, TEXT("UJMThrowableStatusWidget"), &Z_Registration_Info_UClass_UJMThrowableStatusWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMThrowableStatusWidget), 3823241270U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableStatusWidget_h__Script_JMThrowableGameplayIntegration_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableStatusWidget_h__Script_JMThrowableGameplayIntegration_763506909{
	TEXT("/Script/JMThrowableGameplayIntegration"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableStatusWidget_h__Script_JMThrowableGameplayIntegration_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableStatusWidget_h__Script_JMThrowableGameplayIntegration_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
