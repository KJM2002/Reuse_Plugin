// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/JMHideInteractableAdapterComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMHideInteractableAdapterComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
JMHIDEINTERACTIONINTEGRATION_API UClass* Z_Construct_UClass_UJMHideInteractableAdapterComponent();
JMHIDEINTERACTIONINTEGRATION_API UClass* Z_Construct_UClass_UJMHideInteractableAdapterComponent_NoRegister();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractableInterface_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMHideInteractionIntegration();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMHideInteractableAdapterComponent **************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMHideInteractableAdapterComponent;
UClass* UJMHideInteractableAdapterComponent::GetPrivateStaticClass()
{
	using TClass = UJMHideInteractableAdapterComponent;
	if (!Z_Registration_Info_UClass_UJMHideInteractableAdapterComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMHideInteractableAdapterComponent"),
			Z_Registration_Info_UClass_UJMHideInteractableAdapterComponent.InnerSingleton,
			StaticRegisterNativesUJMHideInteractableAdapterComponent,
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
	return Z_Registration_Info_UClass_UJMHideInteractableAdapterComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMHideInteractableAdapterComponent_NoRegister()
{
	return UJMHideInteractableAdapterComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMHideInteractableAdapterComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JMHide" },
		{ "IncludePath", "Components/JMHideInteractableAdapterComponent.h" },
		{ "ModuleRelativePath", "Public/Components/JMHideInteractableAdapterComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnterPrompt_MetaData[] = {
		{ "Category", "JM Hide|Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMHideInteractableAdapterComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExitPrompt_MetaData[] = {
		{ "Category", "JM Hide|Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMHideInteractableAdapterComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoInstallDefaultCharacterDriver_MetaData[] = {
		{ "Category", "JM Hide|Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Installs the built-in ACharacter driver on first use when the host has not added one. */" },
#endif
		{ "ModuleRelativePath", "Public/Components/JMHideInteractableAdapterComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Installs the built-in ACharacter driver on first use when the host has not added one." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UJMHideInteractableAdapterComponent constinit property declarations ******
	static const UECodeGen_Private::FTextPropertyParams NewProp_EnterPrompt;
	static const UECodeGen_Private::FTextPropertyParams NewProp_ExitPrompt;
	static void NewProp_bAutoInstallDefaultCharacterDriver_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoInstallDefaultCharacterDriver;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMHideInteractableAdapterComponent constinit property declarations ********
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMHideInteractableAdapterComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMHideInteractableAdapterComponent_Statics

// ********** Begin Class UJMHideInteractableAdapterComponent Property Definitions *****************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMHideInteractableAdapterComponent_Statics::NewProp_EnterPrompt = { "EnterPrompt", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMHideInteractableAdapterComponent, EnterPrompt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnterPrompt_MetaData), NewProp_EnterPrompt_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMHideInteractableAdapterComponent_Statics::NewProp_ExitPrompt = { "ExitPrompt", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMHideInteractableAdapterComponent, ExitPrompt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExitPrompt_MetaData), NewProp_ExitPrompt_MetaData) };
void Z_Construct_UClass_UJMHideInteractableAdapterComponent_Statics::NewProp_bAutoInstallDefaultCharacterDriver_SetBit(void* Obj)
{
	((UJMHideInteractableAdapterComponent*)Obj)->bAutoInstallDefaultCharacterDriver = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMHideInteractableAdapterComponent_Statics::NewProp_bAutoInstallDefaultCharacterDriver = { "bAutoInstallDefaultCharacterDriver", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMHideInteractableAdapterComponent), &Z_Construct_UClass_UJMHideInteractableAdapterComponent_Statics::NewProp_bAutoInstallDefaultCharacterDriver_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoInstallDefaultCharacterDriver_MetaData), NewProp_bAutoInstallDefaultCharacterDriver_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMHideInteractableAdapterComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideInteractableAdapterComponent_Statics::NewProp_EnterPrompt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideInteractableAdapterComponent_Statics::NewProp_ExitPrompt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideInteractableAdapterComponent_Statics::NewProp_bAutoInstallDefaultCharacterDriver,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideInteractableAdapterComponent_Statics::PropPointers) < 2048);
// ********** End Class UJMHideInteractableAdapterComponent Property Definitions *******************
UObject* (*const Z_Construct_UClass_UJMHideInteractableAdapterComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideInteractionIntegration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideInteractableAdapterComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UJMHideInteractableAdapterComponent_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UJMInteractableInterface_NoRegister, (int32)VTABLE_OFFSET(UJMHideInteractableAdapterComponent, IJMInteractableInterface), false },  // 680874699
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMHideInteractableAdapterComponent_Statics::ClassParams = {
	&UJMHideInteractableAdapterComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMHideInteractableAdapterComponent_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideInteractableAdapterComponent_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideInteractableAdapterComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMHideInteractableAdapterComponent_Statics::Class_MetaDataParams)
};
void UJMHideInteractableAdapterComponent::StaticRegisterNativesUJMHideInteractableAdapterComponent()
{
}
UClass* Z_Construct_UClass_UJMHideInteractableAdapterComponent()
{
	if (!Z_Registration_Info_UClass_UJMHideInteractableAdapterComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMHideInteractableAdapterComponent.OuterSingleton, Z_Construct_UClass_UJMHideInteractableAdapterComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMHideInteractableAdapterComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMHideInteractableAdapterComponent);
UJMHideInteractableAdapterComponent::~UJMHideInteractableAdapterComponent() {}
// ********** End Class UJMHideInteractableAdapterComponent ****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHideInteractionIntegration_Source_JMHideInteractionIntegration_Public_Components_JMHideInteractableAdapterComponent_h__Script_JMHideInteractionIntegration_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMHideInteractableAdapterComponent, UJMHideInteractableAdapterComponent::StaticClass, TEXT("UJMHideInteractableAdapterComponent"), &Z_Registration_Info_UClass_UJMHideInteractableAdapterComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMHideInteractableAdapterComponent), 348936984U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHideInteractionIntegration_Source_JMHideInteractionIntegration_Public_Components_JMHideInteractableAdapterComponent_h__Script_JMHideInteractionIntegration_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHideInteractionIntegration_Source_JMHideInteractionIntegration_Public_Components_JMHideInteractableAdapterComponent_h__Script_JMHideInteractionIntegration_236419711{
	TEXT("/Script/JMHideInteractionIntegration"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHideInteractionIntegration_Source_JMHideInteractionIntegration_Public_Components_JMHideInteractableAdapterComponent_h__Script_JMHideInteractionIntegration_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHideInteractionIntegration_Source_JMHideInteractionIntegration_Public_Components_JMHideInteractableAdapterComponent_h__Script_JMHideInteractionIntegration_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
