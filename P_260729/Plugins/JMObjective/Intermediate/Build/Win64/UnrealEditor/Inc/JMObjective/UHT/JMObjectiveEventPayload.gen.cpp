// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Runtime/JMObjectiveEventPayload.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMObjectiveEventPayload() {}

// ********** Begin Cross Module References ********************************************************
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventPayloadBase();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveEventPayload();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveEventPayload_NoRegister();
JMOBJECTIVE_API UEnum* Z_Construct_UEnum_JMObjective_EJMObjectiveState();
UPackage* Z_Construct_UPackage__Script_JMObjective();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMObjectiveEventPayload *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMObjectiveEventPayload;
UClass* UJMObjectiveEventPayload::GetPrivateStaticClass()
{
	using TClass = UJMObjectiveEventPayload;
	if (!Z_Registration_Info_UClass_UJMObjectiveEventPayload.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMObjectiveEventPayload"),
			Z_Registration_Info_UClass_UJMObjectiveEventPayload.InnerSingleton,
			StaticRegisterNativesUJMObjectiveEventPayload,
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
	return Z_Registration_Info_UClass_UJMObjectiveEventPayload.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMObjectiveEventPayload_NoRegister()
{
	return UJMObjectiveEventPayload::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMObjectiveEventPayload_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Runtime/JMObjectiveEventPayload.h" },
		{ "ModuleRelativePath", "Public/Runtime/JMObjectiveEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectiveId_MetaData[] = {
		{ "Category", "JM Objective|Events" },
		{ "ModuleRelativePath", "Public/Runtime/JMObjectiveEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_State_MetaData[] = {
		{ "Category", "JM Objective|Events" },
		{ "ModuleRelativePath", "Public/Runtime/JMObjectiveEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentCount_MetaData[] = {
		{ "Category", "JM Objective|Events" },
		{ "ModuleRelativePath", "Public/Runtime/JMObjectiveEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequiredCount_MetaData[] = {
		{ "Category", "JM Objective|Events" },
		{ "ModuleRelativePath", "Public/Runtime/JMObjectiveEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProgressDelta_MetaData[] = {
		{ "Category", "JM Objective|Events" },
		{ "ModuleRelativePath", "Public/Runtime/JMObjectiveEventPayload.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMObjectiveEventPayload constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RequiredCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ProgressDelta;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMObjectiveEventPayload constinit property declarations *******************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMObjectiveEventPayload>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMObjectiveEventPayload_Statics

// ********** Begin Class UJMObjectiveEventPayload Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMObjectiveEventPayload_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveEventPayload, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectiveId_MetaData), NewProp_ObjectiveId_MetaData) }; // 517357616
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMObjectiveEventPayload_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMObjectiveEventPayload_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveEventPayload, State), Z_Construct_UEnum_JMObjective_EJMObjectiveState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_State_MetaData), NewProp_State_MetaData) }; // 3203899945
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UJMObjectiveEventPayload_Statics::NewProp_CurrentCount = { "CurrentCount", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveEventPayload, CurrentCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentCount_MetaData), NewProp_CurrentCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UJMObjectiveEventPayload_Statics::NewProp_RequiredCount = { "RequiredCount", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveEventPayload, RequiredCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequiredCount_MetaData), NewProp_RequiredCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UJMObjectiveEventPayload_Statics::NewProp_ProgressDelta = { "ProgressDelta", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveEventPayload, ProgressDelta), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProgressDelta_MetaData), NewProp_ProgressDelta_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMObjectiveEventPayload_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveEventPayload_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveEventPayload_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveEventPayload_Statics::NewProp_State,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveEventPayload_Statics::NewProp_CurrentCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveEventPayload_Statics::NewProp_RequiredCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveEventPayload_Statics::NewProp_ProgressDelta,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveEventPayload_Statics::PropPointers) < 2048);
// ********** End Class UJMObjectiveEventPayload Property Definitions ******************************
UObject* (*const Z_Construct_UClass_UJMObjectiveEventPayload_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UJMGameplayEventPayloadBase,
	(UObject* (*)())Z_Construct_UPackage__Script_JMObjective,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveEventPayload_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMObjectiveEventPayload_Statics::ClassParams = {
	&UJMObjectiveEventPayload::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMObjectiveEventPayload_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveEventPayload_Statics::PropPointers),
	0,
	0x003010A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveEventPayload_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMObjectiveEventPayload_Statics::Class_MetaDataParams)
};
void UJMObjectiveEventPayload::StaticRegisterNativesUJMObjectiveEventPayload()
{
}
UClass* Z_Construct_UClass_UJMObjectiveEventPayload()
{
	if (!Z_Registration_Info_UClass_UJMObjectiveEventPayload.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMObjectiveEventPayload.OuterSingleton, Z_Construct_UClass_UJMObjectiveEventPayload_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMObjectiveEventPayload.OuterSingleton;
}
UJMObjectiveEventPayload::UJMObjectiveEventPayload(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMObjectiveEventPayload);
UJMObjectiveEventPayload::~UJMObjectiveEventPayload() {}
// ********** End Class UJMObjectiveEventPayload ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveEventPayload_h__Script_JMObjective_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMObjectiveEventPayload, UJMObjectiveEventPayload::StaticClass, TEXT("UJMObjectiveEventPayload"), &Z_Registration_Info_UClass_UJMObjectiveEventPayload, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMObjectiveEventPayload), 1969311795U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveEventPayload_h__Script_JMObjective_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveEventPayload_h__Script_JMObjective_2761755972{
	TEXT("/Script/JMObjective"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveEventPayload_h__Script_JMObjective_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveEventPayload_h__Script_JMObjective_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
