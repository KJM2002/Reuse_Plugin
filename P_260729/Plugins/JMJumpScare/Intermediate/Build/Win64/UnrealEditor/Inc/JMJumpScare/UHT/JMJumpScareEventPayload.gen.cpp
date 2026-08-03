// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Payloads/JMJumpScareEventPayload.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMJumpScareEventPayload() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventPayloadBase();
JMJUMPSCARE_API UClass* Z_Construct_UClass_AJMJumpScareAnchor_NoRegister();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareDefinition_NoRegister();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareEventPayload();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareEventPayload_NoRegister();
JMJUMPSCARE_API UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScarePhase();
JMJUMPSCARE_API UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScarePlayResult();
JMJUMPSCARE_API UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScareState();
UPackage* Z_Construct_UPackage__Script_JMJumpScare();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMJumpScareEventPayload *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMJumpScareEventPayload;
UClass* UJMJumpScareEventPayload::GetPrivateStaticClass()
{
	using TClass = UJMJumpScareEventPayload;
	if (!Z_Registration_Info_UClass_UJMJumpScareEventPayload.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMJumpScareEventPayload"),
			Z_Registration_Info_UClass_UJMJumpScareEventPayload.InnerSingleton,
			StaticRegisterNativesUJMJumpScareEventPayload,
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
	return Z_Registration_Info_UClass_UJMJumpScareEventPayload.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMJumpScareEventPayload_NoRegister()
{
	return UJMJumpScareEventPayload::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMJumpScareEventPayload_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Payloads/JMJumpScareEventPayload.h" },
		{ "ModuleRelativePath", "Public/Payloads/JMJumpScareEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpScareId_MetaData[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Payloads/JMJumpScareEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Definition_MetaData[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Payloads/JMJumpScareEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentState_MetaData[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Payloads/JMJumpScareEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentPhase_MetaData[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Payloads/JMJumpScareEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnedActor_MetaData[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Payloads/JMJumpScareEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Anchor_MetaData[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Payloads/JMJumpScareEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Result_MetaData[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Payloads/JMJumpScareEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Trigger_MetaData[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Payloads/JMJumpScareEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetPawn_MetaData[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Payloads/JMJumpScareEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerController_MetaData[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Payloads/JMJumpScareEventPayload.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMJumpScareEventPayload constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_JumpScareId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Definition;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentState;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentPhase_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentPhase;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawnedActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Anchor;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Result;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Trigger;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetPawn;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMJumpScareEventPayload constinit property declarations *******************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMJumpScareEventPayload>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMJumpScareEventPayload_Statics

// ********** Begin Class UJMJumpScareEventPayload Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_JumpScareId = { "JumpScareId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareEventPayload, JumpScareId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpScareId_MetaData), NewProp_JumpScareId_MetaData) }; // 517357616
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_Definition = { "Definition", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareEventPayload, Definition), Z_Construct_UClass_UJMJumpScareDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Definition_MetaData), NewProp_Definition_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_CurrentState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_CurrentState = { "CurrentState", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareEventPayload, CurrentState), Z_Construct_UEnum_JMJumpScare_EJMJumpScareState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentState_MetaData), NewProp_CurrentState_MetaData) }; // 595493008
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_CurrentPhase_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_CurrentPhase = { "CurrentPhase", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareEventPayload, CurrentPhase), Z_Construct_UEnum_JMJumpScare_EJMJumpScarePhase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentPhase_MetaData), NewProp_CurrentPhase_MetaData) }; // 3098439532
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_SpawnedActor = { "SpawnedActor", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareEventPayload, SpawnedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnedActor_MetaData), NewProp_SpawnedActor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_Anchor = { "Anchor", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareEventPayload, Anchor), Z_Construct_UClass_AJMJumpScareAnchor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Anchor_MetaData), NewProp_Anchor_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_Result_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareEventPayload, Result), Z_Construct_UEnum_JMJumpScare_EJMJumpScarePlayResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Result_MetaData), NewProp_Result_MetaData) }; // 453831882
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_Trigger = { "Trigger", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareEventPayload, Trigger), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Trigger_MetaData), NewProp_Trigger_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_TargetPawn = { "TargetPawn", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareEventPayload, TargetPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetPawn_MetaData), NewProp_TargetPawn_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0114000000000014, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMJumpScareEventPayload, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerController_MetaData), NewProp_PlayerController_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMJumpScareEventPayload_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_JumpScareId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_Definition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_CurrentState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_CurrentState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_CurrentPhase_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_CurrentPhase,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_SpawnedActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_Anchor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_Result_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_Result,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_Trigger,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_TargetPawn,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMJumpScareEventPayload_Statics::NewProp_PlayerController,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareEventPayload_Statics::PropPointers) < 2048);
// ********** End Class UJMJumpScareEventPayload Property Definitions ******************************
UObject* (*const Z_Construct_UClass_UJMJumpScareEventPayload_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UJMGameplayEventPayloadBase,
	(UObject* (*)())Z_Construct_UPackage__Script_JMJumpScare,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareEventPayload_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMJumpScareEventPayload_Statics::ClassParams = {
	&UJMJumpScareEventPayload::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMJumpScareEventPayload_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareEventPayload_Statics::PropPointers),
	0,
	0x003010A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareEventPayload_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMJumpScareEventPayload_Statics::Class_MetaDataParams)
};
void UJMJumpScareEventPayload::StaticRegisterNativesUJMJumpScareEventPayload()
{
}
UClass* Z_Construct_UClass_UJMJumpScareEventPayload()
{
	if (!Z_Registration_Info_UClass_UJMJumpScareEventPayload.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMJumpScareEventPayload.OuterSingleton, Z_Construct_UClass_UJMJumpScareEventPayload_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMJumpScareEventPayload.OuterSingleton;
}
UJMJumpScareEventPayload::UJMJumpScareEventPayload(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMJumpScareEventPayload);
UJMJumpScareEventPayload::~UJMJumpScareEventPayload() {}
// ********** End Class UJMJumpScareEventPayload ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Payloads_JMJumpScareEventPayload_h__Script_JMJumpScare_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMJumpScareEventPayload, UJMJumpScareEventPayload::StaticClass, TEXT("UJMJumpScareEventPayload"), &Z_Registration_Info_UClass_UJMJumpScareEventPayload, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMJumpScareEventPayload), 252665638U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Payloads_JMJumpScareEventPayload_h__Script_JMJumpScare_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Payloads_JMJumpScareEventPayload_h__Script_JMJumpScare_93041163{
	TEXT("/Script/JMJumpScare"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Payloads_JMJumpScareEventPayload_h__Script_JMJumpScare_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Payloads_JMJumpScareEventPayload_h__Script_JMJumpScare_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
