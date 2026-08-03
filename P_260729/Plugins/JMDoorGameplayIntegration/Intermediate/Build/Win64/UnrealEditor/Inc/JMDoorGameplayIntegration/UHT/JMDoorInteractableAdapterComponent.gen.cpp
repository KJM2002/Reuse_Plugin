// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/JMDoorInteractableAdapterComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMDoorInteractableAdapterComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
JMDOORGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMDoorInteractableAdapterComponent();
JMDOORGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMDoorInteractableAdapterComponent_NoRegister();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractableInterface_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMDoorGameplayIntegration();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMDoorInteractableAdapterComponent **************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMDoorInteractableAdapterComponent;
UClass* UJMDoorInteractableAdapterComponent::GetPrivateStaticClass()
{
	using TClass = UJMDoorInteractableAdapterComponent;
	if (!Z_Registration_Info_UClass_UJMDoorInteractableAdapterComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMDoorInteractableAdapterComponent"),
			Z_Registration_Info_UClass_UJMDoorInteractableAdapterComponent.InnerSingleton,
			StaticRegisterNativesUJMDoorInteractableAdapterComponent,
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
	return Z_Registration_Info_UClass_UJMDoorInteractableAdapterComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMDoorInteractableAdapterComponent_NoRegister()
{
	return UJMDoorInteractableAdapterComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMDoorInteractableAdapterComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JMInteraction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * JMInteractionComponent-facing adapter automatically added to JMDoor actors.\n * Add it explicitly to a door Blueprint and enable per-door overrides when a\n * particular door needs text different from the project defaults.\n */" },
#endif
		{ "IncludePath", "Components/JMDoorInteractableAdapterComponent.h" },
		{ "ModuleRelativePath", "Public/Components/JMDoorInteractableAdapterComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "JMInteractionComponent-facing adapter automatically added to JMDoor actors.\nAdd it explicitly to a door Blueprint and enable per-door overrides when a\nparticular door needs text different from the project defaults." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverridePromptTexts_MetaData[] = {
		{ "Category", "JM Door|Interaction Prompt" },
		{ "ModuleRelativePath", "Public/Components/JMDoorInteractableAdapterComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpenDoorPrompt_MetaData[] = {
		{ "Category", "JM Door|Interaction Prompt" },
		{ "EditCondition", "bOverridePromptTexts" },
		{ "ModuleRelativePath", "Public/Components/JMDoorInteractableAdapterComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CloseDoorPrompt_MetaData[] = {
		{ "Category", "JM Door|Interaction Prompt" },
		{ "EditCondition", "bOverridePromptTexts" },
		{ "ModuleRelativePath", "Public/Components/JMDoorInteractableAdapterComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LockedDoorPrompt_MetaData[] = {
		{ "Category", "JM Door|Interaction Prompt" },
		{ "EditCondition", "bOverridePromptTexts" },
		{ "ModuleRelativePath", "Public/Components/JMDoorInteractableAdapterComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMDoorInteractableAdapterComponent constinit property declarations ******
	static void NewProp_bOverridePromptTexts_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverridePromptTexts;
	static const UECodeGen_Private::FTextPropertyParams NewProp_OpenDoorPrompt;
	static const UECodeGen_Private::FTextPropertyParams NewProp_CloseDoorPrompt;
	static const UECodeGen_Private::FTextPropertyParams NewProp_LockedDoorPrompt;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMDoorInteractableAdapterComponent constinit property declarations ********
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMDoorInteractableAdapterComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMDoorInteractableAdapterComponent_Statics

// ********** Begin Class UJMDoorInteractableAdapterComponent Property Definitions *****************
void Z_Construct_UClass_UJMDoorInteractableAdapterComponent_Statics::NewProp_bOverridePromptTexts_SetBit(void* Obj)
{
	((UJMDoorInteractableAdapterComponent*)Obj)->bOverridePromptTexts = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMDoorInteractableAdapterComponent_Statics::NewProp_bOverridePromptTexts = { "bOverridePromptTexts", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMDoorInteractableAdapterComponent), &Z_Construct_UClass_UJMDoorInteractableAdapterComponent_Statics::NewProp_bOverridePromptTexts_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverridePromptTexts_MetaData), NewProp_bOverridePromptTexts_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMDoorInteractableAdapterComponent_Statics::NewProp_OpenDoorPrompt = { "OpenDoorPrompt", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorInteractableAdapterComponent, OpenDoorPrompt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpenDoorPrompt_MetaData), NewProp_OpenDoorPrompt_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMDoorInteractableAdapterComponent_Statics::NewProp_CloseDoorPrompt = { "CloseDoorPrompt", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorInteractableAdapterComponent, CloseDoorPrompt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CloseDoorPrompt_MetaData), NewProp_CloseDoorPrompt_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMDoorInteractableAdapterComponent_Statics::NewProp_LockedDoorPrompt = { "LockedDoorPrompt", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorInteractableAdapterComponent, LockedDoorPrompt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LockedDoorPrompt_MetaData), NewProp_LockedDoorPrompt_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMDoorInteractableAdapterComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorInteractableAdapterComponent_Statics::NewProp_bOverridePromptTexts,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorInteractableAdapterComponent_Statics::NewProp_OpenDoorPrompt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorInteractableAdapterComponent_Statics::NewProp_CloseDoorPrompt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorInteractableAdapterComponent_Statics::NewProp_LockedDoorPrompt,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorInteractableAdapterComponent_Statics::PropPointers) < 2048);
// ********** End Class UJMDoorInteractableAdapterComponent Property Definitions *******************
UObject* (*const Z_Construct_UClass_UJMDoorInteractableAdapterComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorGameplayIntegration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorInteractableAdapterComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UJMDoorInteractableAdapterComponent_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UJMInteractableInterface_NoRegister, (int32)VTABLE_OFFSET(UJMDoorInteractableAdapterComponent, IJMInteractableInterface), false },  // 680874699
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMDoorInteractableAdapterComponent_Statics::ClassParams = {
	&UJMDoorInteractableAdapterComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMDoorInteractableAdapterComponent_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorInteractableAdapterComponent_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorInteractableAdapterComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMDoorInteractableAdapterComponent_Statics::Class_MetaDataParams)
};
void UJMDoorInteractableAdapterComponent::StaticRegisterNativesUJMDoorInteractableAdapterComponent()
{
}
UClass* Z_Construct_UClass_UJMDoorInteractableAdapterComponent()
{
	if (!Z_Registration_Info_UClass_UJMDoorInteractableAdapterComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMDoorInteractableAdapterComponent.OuterSingleton, Z_Construct_UClass_UJMDoorInteractableAdapterComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMDoorInteractableAdapterComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMDoorInteractableAdapterComponent);
UJMDoorInteractableAdapterComponent::~UJMDoorInteractableAdapterComponent() {}
// ********** End Class UJMDoorInteractableAdapterComponent ****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Components_JMDoorInteractableAdapterComponent_h__Script_JMDoorGameplayIntegration_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMDoorInteractableAdapterComponent, UJMDoorInteractableAdapterComponent::StaticClass, TEXT("UJMDoorInteractableAdapterComponent"), &Z_Registration_Info_UClass_UJMDoorInteractableAdapterComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMDoorInteractableAdapterComponent), 3263561367U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Components_JMDoorInteractableAdapterComponent_h__Script_JMDoorGameplayIntegration_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Components_JMDoorInteractableAdapterComponent_h__Script_JMDoorGameplayIntegration_3408305676{
	TEXT("/Script/JMDoorGameplayIntegration"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Components_JMDoorInteractableAdapterComponent_h__Script_JMDoorGameplayIntegration_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorGameplayIntegration_Source_JMDoorGameplayIntegration_Public_Components_JMDoorInteractableAdapterComponent_h__Script_JMDoorGameplayIntegration_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
