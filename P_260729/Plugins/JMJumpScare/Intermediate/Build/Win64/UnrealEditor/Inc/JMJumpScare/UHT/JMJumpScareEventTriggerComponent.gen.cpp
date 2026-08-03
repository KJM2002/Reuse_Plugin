// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/JMJumpScareEventTriggerComponent.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMJumpScareEventTriggerComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
JMGAMEPLAYEVENT_API UEnum* Z_Construct_UEnum_JMGameplayEvent_EJMGameplayEventMatchType();
JMJUMPSCARE_API UClass* Z_Construct_UClass_AJMJumpScareAnchor_NoRegister();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareDefinition_NoRegister();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareEventTriggerComponent();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareEventTriggerComponent_NoRegister();
JMJUMPSCARE_API UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScareTriggerPolicy();
UPackage* Z_Construct_UPackage__Script_JMJumpScare();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMJumpScareEventTriggerComponent ****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMJumpScareEventTriggerComponent;
UClass* UJMJumpScareEventTriggerComponent::GetPrivateStaticClass()
{
	using TClass = UJMJumpScareEventTriggerComponent;
	if (!Z_Registration_Info_UClass_UJMJumpScareEventTriggerComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMJumpScareEventTriggerComponent"),
			Z_Registration_Info_UClass_UJMJumpScareEventTriggerComponent.InnerSingleton,
			StaticRegisterNativesUJMJumpScareEventTriggerComponent,
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
	return Z_Registration_Info_UClass_UJMJumpScareEventTriggerComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMJumpScareEventTriggerComponent_NoRegister()
{
	return UJMJumpScareEventTriggerComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional event-bus adapter. The core subsystem does not depend on Door, Interaction, or Objective systems. */" },
#endif
		{ "DisplayName", "JM JumpScare Event Trigger" },
		{ "IncludePath", "Components/JMJumpScareEventTriggerComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Components/JMJumpScareEventTriggerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional event-bus adapter. The core subsystem does not depend on Door, Interaction, or Objective systems." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TriggerEventTag_MetaData[] = {
		{ "Category", "JM JumpScare | Trigger" },
		{ "ModuleRelativePath", "Public/Components/JMJumpScareEventTriggerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EventMatchType_MetaData[] = {
		{ "Category", "JM JumpScare | Trigger" },
		{ "ModuleRelativePath", "Public/Components/JMJumpScareEventTriggerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpScareDefinition_MetaData[] = {
		{ "Category", "JM JumpScare | Trigger" },
		{ "ModuleRelativePath", "Public/Components/JMJumpScareEventTriggerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpScareAnchor_MetaData[] = {
		{ "Category", "JM JumpScare | Trigger" },
		{ "ModuleRelativePath", "Public/Components/JMJumpScareEventTriggerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TriggerPolicy_MetaData[] = {
		{ "Category", "JM JumpScare | Trigger" },
		{ "ModuleRelativePath", "Public/Components/JMJumpScareEventTriggerComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMJumpScareEventTriggerComponent constinit property declarations ********
	static const UECodeGen_Private::FStructPropertyParams NewProp_TriggerEventTag;
	static const UECodeGen_Private::FBytePropertyParams NewProp_EventMatchType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_EventMatchType;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpScareDefinition;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpScareAnchor;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TriggerPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TriggerPolicy;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMJumpScareEventTriggerComponent constinit property declarations **********
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMJumpScareEventTriggerComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics

// ********** Begin Class UJMJumpScareEventTriggerComponent Property Definitions *******************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::NewProp_TriggerEventTag = { "TriggerEventTag", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareEventTriggerComponent, TriggerEventTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TriggerEventTag_MetaData), NewProp_TriggerEventTag_MetaData) }; // 517357616
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::NewProp_EventMatchType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::NewProp_EventMatchType = { "EventMatchType", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareEventTriggerComponent, EventMatchType), Z_Construct_UEnum_JMGameplayEvent_EJMGameplayEventMatchType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EventMatchType_MetaData), NewProp_EventMatchType_MetaData) }; // 2796311245
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::NewProp_JumpScareDefinition = { "JumpScareDefinition", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareEventTriggerComponent, JumpScareDefinition), Z_Construct_UClass_UJMJumpScareDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpScareDefinition_MetaData), NewProp_JumpScareDefinition_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::NewProp_JumpScareAnchor = { "JumpScareAnchor", nullptr, (EPropertyFlags)0x0114000000000815, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareEventTriggerComponent, JumpScareAnchor), Z_Construct_UClass_AJMJumpScareAnchor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpScareAnchor_MetaData), NewProp_JumpScareAnchor_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::NewProp_TriggerPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::NewProp_TriggerPolicy = { "TriggerPolicy", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareEventTriggerComponent, TriggerPolicy), Z_Construct_UEnum_JMJumpScare_EJMJumpScareTriggerPolicy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TriggerPolicy_MetaData), NewProp_TriggerPolicy_MetaData) }; // 453019027
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::NewProp_TriggerEventTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::NewProp_EventMatchType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::NewProp_EventMatchType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::NewProp_JumpScareDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::NewProp_JumpScareAnchor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::NewProp_TriggerPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::NewProp_TriggerPolicy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::PropPointers) < 2048);
// ********** End Class UJMJumpScareEventTriggerComponent Property Definitions *********************
UObject* (*const Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMJumpScare,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::ClassParams = {
	&UJMJumpScareEventTriggerComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::Class_MetaDataParams)
};
void UJMJumpScareEventTriggerComponent::StaticRegisterNativesUJMJumpScareEventTriggerComponent()
{
}
UClass* Z_Construct_UClass_UJMJumpScareEventTriggerComponent()
{
	if (!Z_Registration_Info_UClass_UJMJumpScareEventTriggerComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMJumpScareEventTriggerComponent.OuterSingleton, Z_Construct_UClass_UJMJumpScareEventTriggerComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMJumpScareEventTriggerComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMJumpScareEventTriggerComponent);
UJMJumpScareEventTriggerComponent::~UJMJumpScareEventTriggerComponent() {}
// ********** End Class UJMJumpScareEventTriggerComponent ******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Components_JMJumpScareEventTriggerComponent_h__Script_JMJumpScare_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMJumpScareEventTriggerComponent, UJMJumpScareEventTriggerComponent::StaticClass, TEXT("UJMJumpScareEventTriggerComponent"), &Z_Registration_Info_UClass_UJMJumpScareEventTriggerComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMJumpScareEventTriggerComponent), 2272085166U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Components_JMJumpScareEventTriggerComponent_h__Script_JMJumpScare_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Components_JMJumpScareEventTriggerComponent_h__Script_JMJumpScare_2113974498{
	TEXT("/Script/JMJumpScare"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Components_JMJumpScareEventTriggerComponent_h__Script_JMJumpScare_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Components_JMJumpScareEventTriggerComponent_h__Script_JMJumpScare_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
