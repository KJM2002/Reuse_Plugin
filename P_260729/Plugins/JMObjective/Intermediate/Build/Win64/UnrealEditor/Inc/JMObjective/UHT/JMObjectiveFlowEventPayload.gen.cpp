// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Runtime/JMObjectiveFlowEventPayload.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMObjectiveFlowEventPayload() {}

// ********** Begin Cross Module References ********************************************************
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventPayloadBase();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveFlowEventPayload();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveFlowEventPayload_NoRegister();
JMOBJECTIVE_API UEnum* Z_Construct_UEnum_JMObjective_EJMObjectiveFlowState();
UPackage* Z_Construct_UPackage__Script_JMObjective();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMObjectiveFlowEventPayload *********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMObjectiveFlowEventPayload;
UClass* UJMObjectiveFlowEventPayload::GetPrivateStaticClass()
{
	using TClass = UJMObjectiveFlowEventPayload;
	if (!Z_Registration_Info_UClass_UJMObjectiveFlowEventPayload.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMObjectiveFlowEventPayload"),
			Z_Registration_Info_UClass_UJMObjectiveFlowEventPayload.InnerSingleton,
			StaticRegisterNativesUJMObjectiveFlowEventPayload,
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
	return Z_Registration_Info_UClass_UJMObjectiveFlowEventPayload.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMObjectiveFlowEventPayload_NoRegister()
{
	return UJMObjectiveFlowEventPayload::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Runtime/JMObjectiveFlowEventPayload.h" },
		{ "ModuleRelativePath", "Public/Runtime/JMObjectiveFlowEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlowId_MetaData[] = {
		{ "Category", "JM Objective Flow|Events" },
		{ "ModuleRelativePath", "Public/Runtime/JMObjectiveFlowEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlowState_MetaData[] = {
		{ "Category", "JM Objective Flow|Events" },
		{ "ModuleRelativePath", "Public/Runtime/JMObjectiveFlowEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentStepIndex_MetaData[] = {
		{ "Category", "JM Objective Flow|Events" },
		{ "ModuleRelativePath", "Public/Runtime/JMObjectiveFlowEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentObjectiveId_MetaData[] = {
		{ "Category", "JM Objective Flow|Events" },
		{ "ModuleRelativePath", "Public/Runtime/JMObjectiveFlowEventPayload.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalStepCount_MetaData[] = {
		{ "Category", "JM Objective Flow|Events" },
		{ "ModuleRelativePath", "Public/Runtime/JMObjectiveFlowEventPayload.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMObjectiveFlowEventPayload constinit property declarations *************
	static const UECodeGen_Private::FStructPropertyParams NewProp_FlowId;
	static const UECodeGen_Private::FBytePropertyParams NewProp_FlowState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_FlowState;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentStepIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentObjectiveId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalStepCount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMObjectiveFlowEventPayload constinit property declarations ***************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMObjectiveFlowEventPayload>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics

// ********** Begin Class UJMObjectiveFlowEventPayload Property Definitions ************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics::NewProp_FlowId = { "FlowId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveFlowEventPayload, FlowId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlowId_MetaData), NewProp_FlowId_MetaData) }; // 517357616
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics::NewProp_FlowState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics::NewProp_FlowState = { "FlowState", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveFlowEventPayload, FlowState), Z_Construct_UEnum_JMObjective_EJMObjectiveFlowState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlowState_MetaData), NewProp_FlowState_MetaData) }; // 1681952767
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics::NewProp_CurrentStepIndex = { "CurrentStepIndex", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveFlowEventPayload, CurrentStepIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentStepIndex_MetaData), NewProp_CurrentStepIndex_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics::NewProp_CurrentObjectiveId = { "CurrentObjectiveId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveFlowEventPayload, CurrentObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentObjectiveId_MetaData), NewProp_CurrentObjectiveId_MetaData) }; // 517357616
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics::NewProp_TotalStepCount = { "TotalStepCount", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveFlowEventPayload, TotalStepCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalStepCount_MetaData), NewProp_TotalStepCount_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics::NewProp_FlowId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics::NewProp_FlowState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics::NewProp_FlowState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics::NewProp_CurrentStepIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics::NewProp_CurrentObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics::NewProp_TotalStepCount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics::PropPointers) < 2048);
// ********** End Class UJMObjectiveFlowEventPayload Property Definitions **************************
UObject* (*const Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UJMGameplayEventPayloadBase,
	(UObject* (*)())Z_Construct_UPackage__Script_JMObjective,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics::ClassParams = {
	&UJMObjectiveFlowEventPayload::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics::PropPointers),
	0,
	0x003010A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics::Class_MetaDataParams)
};
void UJMObjectiveFlowEventPayload::StaticRegisterNativesUJMObjectiveFlowEventPayload()
{
}
UClass* Z_Construct_UClass_UJMObjectiveFlowEventPayload()
{
	if (!Z_Registration_Info_UClass_UJMObjectiveFlowEventPayload.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMObjectiveFlowEventPayload.OuterSingleton, Z_Construct_UClass_UJMObjectiveFlowEventPayload_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMObjectiveFlowEventPayload.OuterSingleton;
}
UJMObjectiveFlowEventPayload::UJMObjectiveFlowEventPayload(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMObjectiveFlowEventPayload);
UJMObjectiveFlowEventPayload::~UJMObjectiveFlowEventPayload() {}
// ********** End Class UJMObjectiveFlowEventPayload ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveFlowEventPayload_h__Script_JMObjective_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMObjectiveFlowEventPayload, UJMObjectiveFlowEventPayload::StaticClass, TEXT("UJMObjectiveFlowEventPayload"), &Z_Registration_Info_UClass_UJMObjectiveFlowEventPayload, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMObjectiveFlowEventPayload), 3325497258U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveFlowEventPayload_h__Script_JMObjective_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveFlowEventPayload_h__Script_JMObjective_2638152449{
	TEXT("/Script/JMObjective"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveFlowEventPayload_h__Script_JMObjective_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Runtime_JMObjectiveFlowEventPayload_h__Script_JMObjective_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
