// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Payloads/DialogueEventPayload.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDialogueEventPayload() {}

// ********** Begin Cross Module References ********************************************************
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventPayloadBase();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueEventPayload();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueEventPayload_NoRegister();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueSequence_NoRegister();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueSpeakerProfile_NoRegister();
REUSABLEDIALOGUESYSTEM_API UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EDialogueEndReason();
UPackage* Z_Construct_UPackage__Script_ReusableDialogueSystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDialogueEventPayload ****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDialogueEventPayload;
UClass* UDialogueEventPayload::GetPrivateStaticClass()
{
	using TClass = UDialogueEventPayload;
	if (!Z_Registration_Info_UClass_UDialogueEventPayload.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DialogueEventPayload"),
			Z_Registration_Info_UClass_UDialogueEventPayload.InnerSingleton,
			StaticRegisterNativesUDialogueEventPayload,
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
	return Z_Registration_Info_UClass_UDialogueEventPayload.InnerSingleton;
}
UClass* Z_Construct_UClass_UDialogueEventPayload_NoRegister()
{
	return UDialogueEventPayload::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDialogueEventPayload_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Payloads/DialogueEventPayload.h" },
		{ "ModuleRelativePath", "Public/Payloads/DialogueEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Sequence_MetaData[] = {
		{ "Category", "Dialogue|Events" },
		{ "ModuleRelativePath", "Public/Payloads/DialogueEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogueId_MetaData[] = {
		{ "Category", "Dialogue|Events" },
		{ "ModuleRelativePath", "Public/Payloads/DialogueEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConversationId_MetaData[] = {
		{ "Category", "Dialogue|Events" },
		{ "ModuleRelativePath", "Public/Payloads/DialogueEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Speaker_MetaData[] = {
		{ "Category", "Dialogue|Events" },
		{ "ModuleRelativePath", "Public/Payloads/DialogueEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChoiceId_MetaData[] = {
		{ "Category", "Dialogue|Events" },
		{ "ModuleRelativePath", "Public/Payloads/DialogueEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChoiceIndex_MetaData[] = {
		{ "Category", "Dialogue|Events" },
		{ "ModuleRelativePath", "Public/Payloads/DialogueEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EndReason_MetaData[] = {
		{ "Category", "Dialogue|Events" },
		{ "ModuleRelativePath", "Public/Payloads/DialogueEventPayload.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDialogueEventPayload constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Sequence;
	static const UECodeGen_Private::FNamePropertyParams NewProp_DialogueId;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ConversationId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Speaker;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ChoiceId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ChoiceIndex;
	static const UECodeGen_Private::FBytePropertyParams NewProp_EndReason_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_EndReason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDialogueEventPayload constinit property declarations **********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDialogueEventPayload>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDialogueEventPayload_Statics

// ********** Begin Class UDialogueEventPayload Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueEventPayload_Statics::NewProp_Sequence = { "Sequence", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueEventPayload, Sequence), Z_Construct_UClass_UDialogueSequence_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Sequence_MetaData), NewProp_Sequence_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDialogueEventPayload_Statics::NewProp_DialogueId = { "DialogueId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueEventPayload, DialogueId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogueId_MetaData), NewProp_DialogueId_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDialogueEventPayload_Statics::NewProp_ConversationId = { "ConversationId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueEventPayload, ConversationId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConversationId_MetaData), NewProp_ConversationId_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDialogueEventPayload_Statics::NewProp_Speaker = { "Speaker", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueEventPayload, Speaker), Z_Construct_UClass_UDialogueSpeakerProfile_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Speaker_MetaData), NewProp_Speaker_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UDialogueEventPayload_Statics::NewProp_ChoiceId = { "ChoiceId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueEventPayload, ChoiceId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChoiceId_MetaData), NewProp_ChoiceId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDialogueEventPayload_Statics::NewProp_ChoiceIndex = { "ChoiceIndex", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueEventPayload, ChoiceIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChoiceIndex_MetaData), NewProp_ChoiceIndex_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UDialogueEventPayload_Statics::NewProp_EndReason_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UDialogueEventPayload_Statics::NewProp_EndReason = { "EndReason", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDialogueEventPayload, EndReason), Z_Construct_UEnum_ReusableDialogueSystem_EDialogueEndReason, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EndReason_MetaData), NewProp_EndReason_MetaData) }; // 3091157201
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDialogueEventPayload_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueEventPayload_Statics::NewProp_Sequence,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueEventPayload_Statics::NewProp_DialogueId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueEventPayload_Statics::NewProp_ConversationId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueEventPayload_Statics::NewProp_Speaker,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueEventPayload_Statics::NewProp_ChoiceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueEventPayload_Statics::NewProp_ChoiceIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueEventPayload_Statics::NewProp_EndReason_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDialogueEventPayload_Statics::NewProp_EndReason,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueEventPayload_Statics::PropPointers) < 2048);
// ********** End Class UDialogueEventPayload Property Definitions *********************************
UObject* (*const Z_Construct_UClass_UDialogueEventPayload_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UJMGameplayEventPayloadBase,
	(UObject* (*)())Z_Construct_UPackage__Script_ReusableDialogueSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueEventPayload_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDialogueEventPayload_Statics::ClassParams = {
	&UDialogueEventPayload::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDialogueEventPayload_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueEventPayload_Statics::PropPointers),
	0,
	0x003010A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDialogueEventPayload_Statics::Class_MetaDataParams), Z_Construct_UClass_UDialogueEventPayload_Statics::Class_MetaDataParams)
};
void UDialogueEventPayload::StaticRegisterNativesUDialogueEventPayload()
{
}
UClass* Z_Construct_UClass_UDialogueEventPayload()
{
	if (!Z_Registration_Info_UClass_UDialogueEventPayload.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDialogueEventPayload.OuterSingleton, Z_Construct_UClass_UDialogueEventPayload_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDialogueEventPayload.OuterSingleton;
}
UDialogueEventPayload::UDialogueEventPayload(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDialogueEventPayload);
UDialogueEventPayload::~UDialogueEventPayload() {}
// ********** End Class UDialogueEventPayload ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Payloads_DialogueEventPayload_h__Script_ReusableDialogueSystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDialogueEventPayload, UDialogueEventPayload::StaticClass, TEXT("UDialogueEventPayload"), &Z_Registration_Info_UClass_UDialogueEventPayload, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDialogueEventPayload), 686000388U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Payloads_DialogueEventPayload_h__Script_ReusableDialogueSystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Payloads_DialogueEventPayload_h__Script_ReusableDialogueSystem_1180291062{
	TEXT("/Script/ReusableDialogueSystem"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Payloads_DialogueEventPayload_h__Script_ReusableDialogueSystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Payloads_DialogueEventPayload_h__Script_ReusableDialogueSystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
