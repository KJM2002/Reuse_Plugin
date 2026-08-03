// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Data/JMObjectiveFlowDefinition.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMObjectiveFlowDefinition() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveDefinition_NoRegister();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveFlowDefinition();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveFlowDefinition_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMObjective();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMObjectiveFlowDefinition Function IsFlowDefinitionValid ****************
struct Z_Construct_UFunction_UJMObjectiveFlowDefinition_IsFlowDefinitionValid_Statics
{
	struct JMObjectiveFlowDefinition_eventIsFlowDefinitionValid_Parms
	{
		FText OutError;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Data/JMObjectiveFlowDefinition.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsFlowDefinitionValid constinit property declarations *****************
	static const UECodeGen_Private::FTextPropertyParams NewProp_OutError;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsFlowDefinitionValid constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsFlowDefinitionValid Property Definitions ****************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UJMObjectiveFlowDefinition_IsFlowDefinitionValid_Statics::NewProp_OutError = { "OutError", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMObjectiveFlowDefinition_eventIsFlowDefinitionValid_Parms, OutError), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UJMObjectiveFlowDefinition_IsFlowDefinitionValid_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMObjectiveFlowDefinition_eventIsFlowDefinitionValid_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMObjectiveFlowDefinition_IsFlowDefinitionValid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMObjectiveFlowDefinition_eventIsFlowDefinitionValid_Parms), &Z_Construct_UFunction_UJMObjectiveFlowDefinition_IsFlowDefinitionValid_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMObjectiveFlowDefinition_IsFlowDefinitionValid_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowDefinition_IsFlowDefinitionValid_Statics::NewProp_OutError,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMObjectiveFlowDefinition_IsFlowDefinitionValid_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowDefinition_IsFlowDefinitionValid_Statics::PropPointers) < 2048);
// ********** End Function IsFlowDefinitionValid Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMObjectiveFlowDefinition_IsFlowDefinitionValid_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMObjectiveFlowDefinition, nullptr, "IsFlowDefinitionValid", 	Z_Construct_UFunction_UJMObjectiveFlowDefinition_IsFlowDefinitionValid_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowDefinition_IsFlowDefinitionValid_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMObjectiveFlowDefinition_IsFlowDefinitionValid_Statics::JMObjectiveFlowDefinition_eventIsFlowDefinitionValid_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMObjectiveFlowDefinition_IsFlowDefinitionValid_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMObjectiveFlowDefinition_IsFlowDefinitionValid_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMObjectiveFlowDefinition_IsFlowDefinitionValid_Statics::JMObjectiveFlowDefinition_eventIsFlowDefinitionValid_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMObjectiveFlowDefinition_IsFlowDefinitionValid()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMObjectiveFlowDefinition_IsFlowDefinitionValid_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMObjectiveFlowDefinition::execIsFlowDefinitionValid)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_OutError);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsFlowDefinitionValid(Z_Param_Out_OutError);
	P_NATIVE_END;
}
// ********** End Class UJMObjectiveFlowDefinition Function IsFlowDefinitionValid ******************

// ********** Begin Class UJMObjectiveFlowDefinition ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMObjectiveFlowDefinition;
UClass* UJMObjectiveFlowDefinition::GetPrivateStaticClass()
{
	using TClass = UJMObjectiveFlowDefinition;
	if (!Z_Registration_Info_UClass_UJMObjectiveFlowDefinition.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMObjectiveFlowDefinition"),
			Z_Registration_Info_UClass_UJMObjectiveFlowDefinition.InnerSingleton,
			StaticRegisterNativesUJMObjectiveFlowDefinition,
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
	return Z_Registration_Info_UClass_UJMObjectiveFlowDefinition.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMObjectiveFlowDefinition_NoRegister()
{
	return UJMObjectiveFlowDefinition::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Data/JMObjectiveFlowDefinition.h" },
		{ "ModuleRelativePath", "Public/Data/JMObjectiveFlowDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlowId_MetaData[] = {
		{ "Category", "Identity" },
		{ "ModuleRelativePath", "Public/Data/JMObjectiveFlowDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[] = {
		{ "Category", "Display" },
		{ "ModuleRelativePath", "Public/Data/JMObjectiveFlowDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "Display" },
		{ "ModuleRelativePath", "Public/Data/JMObjectiveFlowDefinition.h" },
		{ "MultiLine", "TRUE" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObjectiveDefinitions_MetaData[] = {
		{ "Category", "Flow" },
		{ "ModuleRelativePath", "Public/Data/JMObjectiveFlowDefinition.h" },
		{ "TitleProperty", "DisplayName" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bStopOnObjectiveFailure_MetaData[] = {
		{ "Category", "Flow" },
		{ "ModuleRelativePath", "Public/Data/JMObjectiveFlowDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowRestart_MetaData[] = {
		{ "Category", "Flow" },
		{ "ModuleRelativePath", "Public/Data/JMObjectiveFlowDefinition.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMObjectiveFlowDefinition constinit property declarations ***************
	static const UECodeGen_Private::FStructPropertyParams NewProp_FlowId;
	static const UECodeGen_Private::FTextPropertyParams NewProp_DisplayName;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Description;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ObjectiveDefinitions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ObjectiveDefinitions;
	static void NewProp_bStopOnObjectiveFailure_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStopOnObjectiveFailure;
	static void NewProp_bAllowRestart_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowRestart;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMObjectiveFlowDefinition constinit property declarations *****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("IsFlowDefinitionValid"), .Pointer = &UJMObjectiveFlowDefinition::execIsFlowDefinitionValid },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMObjectiveFlowDefinition_IsFlowDefinitionValid, "IsFlowDefinitionValid" }, // 1620662362
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMObjectiveFlowDefinition>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics

// ********** Begin Class UJMObjectiveFlowDefinition Property Definitions **************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::NewProp_FlowId = { "FlowId", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveFlowDefinition, FlowId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlowId_MetaData), NewProp_FlowId_MetaData) }; // 517357616
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveFlowDefinition, DisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayName_MetaData), NewProp_DisplayName_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveFlowDefinition, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::NewProp_ObjectiveDefinitions_Inner = { "ObjectiveDefinitions", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UJMObjectiveDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::NewProp_ObjectiveDefinitions = { "ObjectiveDefinitions", nullptr, (EPropertyFlags)0x0114000000010015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMObjectiveFlowDefinition, ObjectiveDefinitions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObjectiveDefinitions_MetaData), NewProp_ObjectiveDefinitions_MetaData) };
void Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::NewProp_bStopOnObjectiveFailure_SetBit(void* Obj)
{
	((UJMObjectiveFlowDefinition*)Obj)->bStopOnObjectiveFailure = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::NewProp_bStopOnObjectiveFailure = { "bStopOnObjectiveFailure", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMObjectiveFlowDefinition), &Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::NewProp_bStopOnObjectiveFailure_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bStopOnObjectiveFailure_MetaData), NewProp_bStopOnObjectiveFailure_MetaData) };
void Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::NewProp_bAllowRestart_SetBit(void* Obj)
{
	((UJMObjectiveFlowDefinition*)Obj)->bAllowRestart = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::NewProp_bAllowRestart = { "bAllowRestart", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMObjectiveFlowDefinition), &Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::NewProp_bAllowRestart_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowRestart_MetaData), NewProp_bAllowRestart_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::NewProp_FlowId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::NewProp_DisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::NewProp_ObjectiveDefinitions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::NewProp_ObjectiveDefinitions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::NewProp_bStopOnObjectiveFailure,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::NewProp_bAllowRestart,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::PropPointers) < 2048);
// ********** End Class UJMObjectiveFlowDefinition Property Definitions ****************************
UObject* (*const Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_JMObjective,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::ClassParams = {
	&UJMObjectiveFlowDefinition::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::Class_MetaDataParams)
};
void UJMObjectiveFlowDefinition::StaticRegisterNativesUJMObjectiveFlowDefinition()
{
	UClass* Class = UJMObjectiveFlowDefinition::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMObjectiveFlowDefinition()
{
	if (!Z_Registration_Info_UClass_UJMObjectiveFlowDefinition.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMObjectiveFlowDefinition.OuterSingleton, Z_Construct_UClass_UJMObjectiveFlowDefinition_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMObjectiveFlowDefinition.OuterSingleton;
}
UJMObjectiveFlowDefinition::UJMObjectiveFlowDefinition(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMObjectiveFlowDefinition);
UJMObjectiveFlowDefinition::~UJMObjectiveFlowDefinition() {}
// ********** End Class UJMObjectiveFlowDefinition *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Data_JMObjectiveFlowDefinition_h__Script_JMObjective_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMObjectiveFlowDefinition, UJMObjectiveFlowDefinition::StaticClass, TEXT("UJMObjectiveFlowDefinition"), &Z_Registration_Info_UClass_UJMObjectiveFlowDefinition, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMObjectiveFlowDefinition), 3631926857U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Data_JMObjectiveFlowDefinition_h__Script_JMObjective_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Data_JMObjectiveFlowDefinition_h__Script_JMObjective_1834193018{
	TEXT("/Script/JMObjective"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Data_JMObjectiveFlowDefinition_h__Script_JMObjective_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Data_JMObjectiveFlowDefinition_h__Script_JMObjective_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
