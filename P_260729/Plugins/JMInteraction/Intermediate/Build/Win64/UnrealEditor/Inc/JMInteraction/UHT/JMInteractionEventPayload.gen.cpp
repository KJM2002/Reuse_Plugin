// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Payloads/JMInteractionEventPayload.h"
#include "Types/JMInteractionTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMInteractionEventPayload() {}

// ********** Begin Cross Module References ********************************************************
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventPayloadBase();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractionEventPayload();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractionEventPayload_NoRegister();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionContext();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionResult();
UPackage* Z_Construct_UPackage__Script_JMInteraction();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMInteractionEventPayload ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMInteractionEventPayload;
UClass* UJMInteractionEventPayload::GetPrivateStaticClass()
{
	using TClass = UJMInteractionEventPayload;
	if (!Z_Registration_Info_UClass_UJMInteractionEventPayload.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMInteractionEventPayload"),
			Z_Registration_Info_UClass_UJMInteractionEventPayload.InnerSingleton,
			StaticRegisterNativesUJMInteractionEventPayload,
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
	return Z_Registration_Info_UClass_UJMInteractionEventPayload.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMInteractionEventPayload_NoRegister()
{
	return UJMInteractionEventPayload::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMInteractionEventPayload_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Payloads/JMInteractionEventPayload.h" },
		{ "ModuleRelativePath", "Public/Payloads/JMInteractionEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Result_MetaData[] = {
		{ "Category", "JM Interaction|Events" },
		{ "ModuleRelativePath", "Public/Payloads/JMInteractionEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "Category", "JM Interaction|Events" },
		{ "ModuleRelativePath", "Public/Payloads/JMInteractionEventPayload.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMInteractionEventPayload constinit property declarations ***************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Result;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMInteractionEventPayload constinit property declarations *****************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMInteractionEventPayload>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMInteractionEventPayload_Statics

// ********** Begin Class UJMInteractionEventPayload Property Definitions **************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMInteractionEventPayload_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionEventPayload, Result), Z_Construct_UScriptStruct_FJMInteractionResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Result_MetaData), NewProp_Result_MetaData) }; // 240276497
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMInteractionEventPayload_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractionEventPayload, Context), Z_Construct_UScriptStruct_FJMInteractionContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3486038698
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMInteractionEventPayload_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionEventPayload_Statics::NewProp_Result,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractionEventPayload_Statics::NewProp_Context,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractionEventPayload_Statics::PropPointers) < 2048);
// ********** End Class UJMInteractionEventPayload Property Definitions ****************************
UObject* (*const Z_Construct_UClass_UJMInteractionEventPayload_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UJMGameplayEventPayloadBase,
	(UObject* (*)())Z_Construct_UPackage__Script_JMInteraction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractionEventPayload_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMInteractionEventPayload_Statics::ClassParams = {
	&UJMInteractionEventPayload::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMInteractionEventPayload_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractionEventPayload_Statics::PropPointers),
	0,
	0x003010A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractionEventPayload_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMInteractionEventPayload_Statics::Class_MetaDataParams)
};
void UJMInteractionEventPayload::StaticRegisterNativesUJMInteractionEventPayload()
{
}
UClass* Z_Construct_UClass_UJMInteractionEventPayload()
{
	if (!Z_Registration_Info_UClass_UJMInteractionEventPayload.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMInteractionEventPayload.OuterSingleton, Z_Construct_UClass_UJMInteractionEventPayload_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMInteractionEventPayload.OuterSingleton;
}
UJMInteractionEventPayload::UJMInteractionEventPayload(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMInteractionEventPayload);
UJMInteractionEventPayload::~UJMInteractionEventPayload() {}
// ********** End Class UJMInteractionEventPayload *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Payloads_JMInteractionEventPayload_h__Script_JMInteraction_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMInteractionEventPayload, UJMInteractionEventPayload::StaticClass, TEXT("UJMInteractionEventPayload"), &Z_Registration_Info_UClass_UJMInteractionEventPayload, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMInteractionEventPayload), 2603266221U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Payloads_JMInteractionEventPayload_h__Script_JMInteraction_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Payloads_JMInteractionEventPayload_h__Script_JMInteraction_3508031160{
	TEXT("/Script/JMInteraction"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Payloads_JMInteractionEventPayload_h__Script_JMInteraction_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Payloads_JMInteractionEventPayload_h__Script_JMInteraction_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
