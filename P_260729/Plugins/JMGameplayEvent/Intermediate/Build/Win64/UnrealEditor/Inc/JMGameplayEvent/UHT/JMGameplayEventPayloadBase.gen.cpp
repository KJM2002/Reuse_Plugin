// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Payloads/JMGameplayEventPayloadBase.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMGameplayEventPayloadBase() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventPayloadBase();
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventPayloadBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMGameplayEvent();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMGameplayEventPayloadBase **********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMGameplayEventPayloadBase;
UClass* UJMGameplayEventPayloadBase::GetPrivateStaticClass()
{
	using TClass = UJMGameplayEventPayloadBase;
	if (!Z_Registration_Info_UClass_UJMGameplayEventPayloadBase.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMGameplayEventPayloadBase"),
			Z_Registration_Info_UClass_UJMGameplayEventPayloadBase.InnerSingleton,
			StaticRegisterNativesUJMGameplayEventPayloadBase,
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
	return Z_Registration_Info_UClass_UJMGameplayEventPayloadBase.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMGameplayEventPayloadBase_NoRegister()
{
	return UJMGameplayEventPayloadBase::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMGameplayEventPayloadBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Base class for transient, domain-owned event data. Feature plugins subclass this type. */" },
#endif
		{ "IncludePath", "Payloads/JMGameplayEventPayloadBase.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Payloads/JMGameplayEventPayloadBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base class for transient, domain-owned event data. Feature plugins subclass this type." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectiveTargetIdentifier_MetaData[] = {
		{ "Category", "JM Gameplay Event|Routing" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional stable content identifier used by event consumers such as objective systems. */" },
#endif
		{ "ModuleRelativePath", "Public/Payloads/JMGameplayEventPayloadBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional stable content identifier used by event consumers such as objective systems." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectiveProgressAmount_MetaData[] = {
		{ "Category", "JM Gameplay Event|Routing" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional event quantity. Producers should keep this positive when it represents progress. */" },
#endif
		{ "ModuleRelativePath", "Public/Payloads/JMGameplayEventPayloadBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional event quantity. Producers should keep this positive when it represents progress." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectiveContextTags_MetaData[] = {
		{ "Category", "JM Gameplay Event|Routing" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional payload-owned context merged with the message context by generic consumers. */" },
#endif
		{ "ModuleRelativePath", "Public/Payloads/JMGameplayEventPayloadBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional payload-owned context merged with the message context by generic consumers." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UJMGameplayEventPayloadBase constinit property declarations **************
	static const UECodeGen_Private::FNamePropertyParams NewProp_ObjectiveTargetIdentifier;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ObjectiveProgressAmount;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveContextTags;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMGameplayEventPayloadBase constinit property declarations ****************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMGameplayEventPayloadBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMGameplayEventPayloadBase_Statics

// ********** Begin Class UJMGameplayEventPayloadBase Property Definitions *************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UJMGameplayEventPayloadBase_Statics::NewProp_ObjectiveTargetIdentifier = { "ObjectiveTargetIdentifier", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMGameplayEventPayloadBase, ObjectiveTargetIdentifier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectiveTargetIdentifier_MetaData), NewProp_ObjectiveTargetIdentifier_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UJMGameplayEventPayloadBase_Statics::NewProp_ObjectiveProgressAmount = { "ObjectiveProgressAmount", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMGameplayEventPayloadBase, ObjectiveProgressAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectiveProgressAmount_MetaData), NewProp_ObjectiveProgressAmount_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMGameplayEventPayloadBase_Statics::NewProp_ObjectiveContextTags = { "ObjectiveContextTags", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMGameplayEventPayloadBase, ObjectiveContextTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectiveContextTags_MetaData), NewProp_ObjectiveContextTags_MetaData) }; // 3438578166
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMGameplayEventPayloadBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMGameplayEventPayloadBase_Statics::NewProp_ObjectiveTargetIdentifier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMGameplayEventPayloadBase_Statics::NewProp_ObjectiveProgressAmount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMGameplayEventPayloadBase_Statics::NewProp_ObjectiveContextTags,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMGameplayEventPayloadBase_Statics::PropPointers) < 2048);
// ********** End Class UJMGameplayEventPayloadBase Property Definitions ***************************
UObject* (*const Z_Construct_UClass_UJMGameplayEventPayloadBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_JMGameplayEvent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMGameplayEventPayloadBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMGameplayEventPayloadBase_Statics::ClassParams = {
	&UJMGameplayEventPayloadBase::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMGameplayEventPayloadBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMGameplayEventPayloadBase_Statics::PropPointers),
	0,
	0x003010A9u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMGameplayEventPayloadBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMGameplayEventPayloadBase_Statics::Class_MetaDataParams)
};
void UJMGameplayEventPayloadBase::StaticRegisterNativesUJMGameplayEventPayloadBase()
{
}
UClass* Z_Construct_UClass_UJMGameplayEventPayloadBase()
{
	if (!Z_Registration_Info_UClass_UJMGameplayEventPayloadBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMGameplayEventPayloadBase.OuterSingleton, Z_Construct_UClass_UJMGameplayEventPayloadBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMGameplayEventPayloadBase.OuterSingleton;
}
UJMGameplayEventPayloadBase::UJMGameplayEventPayloadBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMGameplayEventPayloadBase);
UJMGameplayEventPayloadBase::~UJMGameplayEventPayloadBase() {}
// ********** End Class UJMGameplayEventPayloadBase ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Payloads_JMGameplayEventPayloadBase_h__Script_JMGameplayEvent_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMGameplayEventPayloadBase, UJMGameplayEventPayloadBase::StaticClass, TEXT("UJMGameplayEventPayloadBase"), &Z_Registration_Info_UClass_UJMGameplayEventPayloadBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMGameplayEventPayloadBase), 1852971666U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Payloads_JMGameplayEventPayloadBase_h__Script_JMGameplayEvent_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Payloads_JMGameplayEventPayloadBase_h__Script_JMGameplayEvent_2601542092{
	TEXT("/Script/JMGameplayEvent"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Payloads_JMGameplayEventPayloadBase_h__Script_JMGameplayEvent_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Payloads_JMGameplayEventPayloadBase_h__Script_JMGameplayEvent_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
