// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Data/JMObjectiveDefinition.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMObjectiveDefinition() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
JMGAMEPLAYEVENT_API UEnum* Z_Construct_UEnum_JMGameplayEvent_EJMGameplayEventMatchType();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveDefinition();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveDefinition_NoRegister();
JMOBJECTIVE_API UEnum* Z_Construct_UEnum_JMObjective_EJMObjectiveProgressIncrementMode();
UPackage* Z_Construct_UPackage__Script_JMObjective();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMObjectiveDefinition ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMObjectiveDefinition;
UClass* UJMObjectiveDefinition::GetPrivateStaticClass()
{
	using TClass = UJMObjectiveDefinition;
	if (!Z_Registration_Info_UClass_UJMObjectiveDefinition.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMObjectiveDefinition"),
			Z_Registration_Info_UClass_UJMObjectiveDefinition.InnerSingleton,
			StaticRegisterNativesUJMObjectiveDefinition,
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
	return Z_Registration_Info_UClass_UJMObjectiveDefinition.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMObjectiveDefinition_NoRegister()
{
	return UJMObjectiveDefinition::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMObjectiveDefinition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Data/JMObjectiveDefinition.h" },
		{ "ModuleRelativePath", "Public/Data/JMObjectiveDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectiveId_MetaData[] = {
		{ "Category", "Identity" },
		{ "ModuleRelativePath", "Public/Data/JMObjectiveDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[] = {
		{ "Category", "Display" },
		{ "ModuleRelativePath", "Public/Data/JMObjectiveDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "Display" },
		{ "ModuleRelativePath", "Public/Data/JMObjectiveDefinition.h" },
		{ "MultiLine", "TRUE" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ListeningEventTag_MetaData[] = {
		{ "Category", "Event" },
		{ "ModuleRelativePath", "Public/Data/JMObjectiveDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EventMatchType_MetaData[] = {
		{ "Category", "Event" },
		{ "ModuleRelativePath", "Public/Data/JMObjectiveDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequiredCount_MetaData[] = {
		{ "Category", "Progress" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/Data/JMObjectiveDefinition.h" },
		{ "UIMin", "1" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProgressIncrementMode_MetaData[] = {
		{ "Category", "Progress" },
		{ "ModuleRelativePath", "Public/Data/JMObjectiveDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FixedProgressAmount_MetaData[] = {
		{ "Category", "Progress" },
		{ "ClampMin", "1" },
		{ "EditCondition", "ProgressIncrementMode == EJMObjectiveProgressIncrementMode::FixedAmount" },
		{ "ModuleRelativePath", "Public/Data/JMObjectiveDefinition.h" },
		{ "UIMin", "1" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequiredContextTags_MetaData[] = {
		{ "Category", "Filters" },
		{ "ModuleRelativePath", "Public/Data/JMObjectiveDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlockedContextTags_MetaData[] = {
		{ "Category", "Filters" },
		{ "ModuleRelativePath", "Public/Data/JMObjectiveDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequiredTargetIdentifier_MetaData[] = {
		{ "Category", "Filters" },
		{ "ModuleRelativePath", "Public/Data/JMObjectiveDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoActivate_MetaData[] = {
		{ "Category", "Lifecycle" },
		{ "ModuleRelativePath", "Public/Data/JMObjectiveDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanFail_MetaData[] = {
		{ "Category", "Lifecycle" },
		{ "ModuleRelativePath", "Public/Data/JMObjectiveDefinition.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMObjectiveDefinition constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectiveId;
	static const UECodeGen_Private::FTextPropertyParams NewProp_DisplayName;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Description;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ListeningEventTag;
	static const UECodeGen_Private::FBytePropertyParams NewProp_EventMatchType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_EventMatchType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RequiredCount;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ProgressIncrementMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ProgressIncrementMode;
	static const UECodeGen_Private::FIntPropertyParams NewProp_FixedProgressAmount;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RequiredContextTags;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BlockedContextTags;
	static const UECodeGen_Private::FNamePropertyParams NewProp_RequiredTargetIdentifier;
	static void NewProp_bAutoActivate_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoActivate;
	static void NewProp_bCanFail_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanFail;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMObjectiveDefinition constinit property declarations *********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMObjectiveDefinition>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMObjectiveDefinition_Statics

// ********** Begin Class UJMObjectiveDefinition Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_ObjectiveId = { "ObjectiveId", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveDefinition, ObjectiveId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectiveId_MetaData), NewProp_ObjectiveId_MetaData) }; // 517357616
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveDefinition, DisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayName_MetaData), NewProp_DisplayName_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveDefinition, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_ListeningEventTag = { "ListeningEventTag", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveDefinition, ListeningEventTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ListeningEventTag_MetaData), NewProp_ListeningEventTag_MetaData) }; // 517357616
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_EventMatchType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_EventMatchType = { "EventMatchType", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveDefinition, EventMatchType), Z_Construct_UEnum_JMGameplayEvent_EJMGameplayEventMatchType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EventMatchType_MetaData), NewProp_EventMatchType_MetaData) }; // 2796311245
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_RequiredCount = { "RequiredCount", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveDefinition, RequiredCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequiredCount_MetaData), NewProp_RequiredCount_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_ProgressIncrementMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_ProgressIncrementMode = { "ProgressIncrementMode", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveDefinition, ProgressIncrementMode), Z_Construct_UEnum_JMObjective_EJMObjectiveProgressIncrementMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProgressIncrementMode_MetaData), NewProp_ProgressIncrementMode_MetaData) }; // 3082881662
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_FixedProgressAmount = { "FixedProgressAmount", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveDefinition, FixedProgressAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FixedProgressAmount_MetaData), NewProp_FixedProgressAmount_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_RequiredContextTags = { "RequiredContextTags", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveDefinition, RequiredContextTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequiredContextTags_MetaData), NewProp_RequiredContextTags_MetaData) }; // 3438578166
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_BlockedContextTags = { "BlockedContextTags", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveDefinition, BlockedContextTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlockedContextTags_MetaData), NewProp_BlockedContextTags_MetaData) }; // 3438578166
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_RequiredTargetIdentifier = { "RequiredTargetIdentifier", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveDefinition, RequiredTargetIdentifier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequiredTargetIdentifier_MetaData), NewProp_RequiredTargetIdentifier_MetaData) };
void Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_bAutoActivate_SetBit(void* Obj)
{
	((UJMObjectiveDefinition*)Obj)->bAutoActivate = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_bAutoActivate = { "bAutoActivate", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMObjectiveDefinition), &Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_bAutoActivate_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoActivate_MetaData), NewProp_bAutoActivate_MetaData) };
void Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_bCanFail_SetBit(void* Obj)
{
	((UJMObjectiveDefinition*)Obj)->bCanFail = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_bCanFail = { "bCanFail", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMObjectiveDefinition), &Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_bCanFail_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanFail_MetaData), NewProp_bCanFail_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMObjectiveDefinition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_ObjectiveId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_DisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_ListeningEventTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_EventMatchType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_EventMatchType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_RequiredCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_ProgressIncrementMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_ProgressIncrementMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_FixedProgressAmount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_RequiredContextTags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_BlockedContextTags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_RequiredTargetIdentifier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_bAutoActivate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveDefinition_Statics::NewProp_bCanFail,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveDefinition_Statics::PropPointers) < 2048);
// ********** End Class UJMObjectiveDefinition Property Definitions ********************************
UObject* (*const Z_Construct_UClass_UJMObjectiveDefinition_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_JMObjective,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveDefinition_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMObjectiveDefinition_Statics::ClassParams = {
	&UJMObjectiveDefinition::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMObjectiveDefinition_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveDefinition_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveDefinition_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMObjectiveDefinition_Statics::Class_MetaDataParams)
};
void UJMObjectiveDefinition::StaticRegisterNativesUJMObjectiveDefinition()
{
}
UClass* Z_Construct_UClass_UJMObjectiveDefinition()
{
	if (!Z_Registration_Info_UClass_UJMObjectiveDefinition.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMObjectiveDefinition.OuterSingleton, Z_Construct_UClass_UJMObjectiveDefinition_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMObjectiveDefinition.OuterSingleton;
}
UJMObjectiveDefinition::UJMObjectiveDefinition(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMObjectiveDefinition);
UJMObjectiveDefinition::~UJMObjectiveDefinition() {}
// ********** End Class UJMObjectiveDefinition *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Data_JMObjectiveDefinition_h__Script_JMObjective_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMObjectiveDefinition, UJMObjectiveDefinition::StaticClass, TEXT("UJMObjectiveDefinition"), &Z_Registration_Info_UClass_UJMObjectiveDefinition, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMObjectiveDefinition), 2621943156U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Data_JMObjectiveDefinition_h__Script_JMObjective_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Data_JMObjectiveDefinition_h__Script_JMObjective_617068115{
	TEXT("/Script/JMObjective"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Data_JMObjectiveDefinition_h__Script_JMObjective_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Data_JMObjectiveDefinition_h__Script_JMObjective_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
