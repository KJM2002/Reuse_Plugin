// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/JMJumpScareOverlayWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMJumpScareOverlayWidget() {}

// ********** Begin Cross Module References ********************************************************
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareOverlayWidget();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareOverlayWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_JMJumpScare();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMJumpScareOverlayWidget ************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMJumpScareOverlayWidget;
UClass* UJMJumpScareOverlayWidget::GetPrivateStaticClass()
{
	using TClass = UJMJumpScareOverlayWidget;
	if (!Z_Registration_Info_UClass_UJMJumpScareOverlayWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMJumpScareOverlayWidget"),
			Z_Registration_Info_UClass_UJMJumpScareOverlayWidget.InnerSingleton,
			StaticRegisterNativesUJMJumpScareOverlayWidget,
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
	return Z_Registration_Info_UClass_UJMJumpScareOverlayWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMJumpScareOverlayWidget_NoRegister()
{
	return UJMJumpScareOverlayWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMJumpScareOverlayWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Internal full-screen image used by the JumpScare subsystem. */" },
#endif
		{ "IncludePath", "UI/JMJumpScareOverlayWidget.h" },
		{ "IsBlueprintBase", "false" },
		{ "ModuleRelativePath", "Public/UI/JMJumpScareOverlayWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Internal full-screen image used by the JumpScare subsystem." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ImageWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/JMJumpScareOverlayWidget.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMJumpScareOverlayWidget constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ImageWidget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMJumpScareOverlayWidget constinit property declarations ******************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMJumpScareOverlayWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMJumpScareOverlayWidget_Statics

// ********** Begin Class UJMJumpScareOverlayWidget Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMJumpScareOverlayWidget_Statics::NewProp_ImageWidget = { "ImageWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareOverlayWidget, ImageWidget), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ImageWidget_MetaData), NewProp_ImageWidget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMJumpScareOverlayWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareOverlayWidget_Statics::NewProp_ImageWidget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareOverlayWidget_Statics::PropPointers) < 2048);
// ********** End Class UJMJumpScareOverlayWidget Property Definitions *****************************
UObject* (*const Z_Construct_UClass_UJMJumpScareOverlayWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_JMJumpScare,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareOverlayWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMJumpScareOverlayWidget_Statics::ClassParams = {
	&UJMJumpScareOverlayWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMJumpScareOverlayWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareOverlayWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareOverlayWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMJumpScareOverlayWidget_Statics::Class_MetaDataParams)
};
void UJMJumpScareOverlayWidget::StaticRegisterNativesUJMJumpScareOverlayWidget()
{
}
UClass* Z_Construct_UClass_UJMJumpScareOverlayWidget()
{
	if (!Z_Registration_Info_UClass_UJMJumpScareOverlayWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMJumpScareOverlayWidget.OuterSingleton, Z_Construct_UClass_UJMJumpScareOverlayWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMJumpScareOverlayWidget.OuterSingleton;
}
UJMJumpScareOverlayWidget::UJMJumpScareOverlayWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMJumpScareOverlayWidget);
UJMJumpScareOverlayWidget::~UJMJumpScareOverlayWidget() {}
// ********** End Class UJMJumpScareOverlayWidget **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_UI_JMJumpScareOverlayWidget_h__Script_JMJumpScare_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMJumpScareOverlayWidget, UJMJumpScareOverlayWidget::StaticClass, TEXT("UJMJumpScareOverlayWidget"), &Z_Registration_Info_UClass_UJMJumpScareOverlayWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMJumpScareOverlayWidget), 1708067928U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_UI_JMJumpScareOverlayWidget_h__Script_JMJumpScare_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_UI_JMJumpScareOverlayWidget_h__Script_JMJumpScare_3884935621{
	TEXT("/Script/JMJumpScare"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_UI_JMJumpScareOverlayWidget_h__Script_JMJumpScare_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_UI_JMJumpScareOverlayWidget_h__Script_JMJumpScare_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
