// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actors/JMObjectiveFlowStarter.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMObjectiveFlowStarter() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
JMOBJECTIVE_API UClass* Z_Construct_UClass_AJMObjectiveFlowStarter();
JMOBJECTIVE_API UClass* Z_Construct_UClass_AJMObjectiveFlowStarter_NoRegister();
JMOBJECTIVE_API UClass* Z_Construct_UClass_UJMObjectiveFlowDefinition_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMObjective();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AJMObjectiveFlowStarter **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AJMObjectiveFlowStarter;
UClass* AJMObjectiveFlowStarter::GetPrivateStaticClass()
{
	using TClass = AJMObjectiveFlowStarter;
	if (!Z_Registration_Info_UClass_AJMObjectiveFlowStarter.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMObjectiveFlowStarter"),
			Z_Registration_Info_UClass_AJMObjectiveFlowStarter.InnerSingleton,
			StaticRegisterNativesAJMObjectiveFlowStarter,
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
	return Z_Registration_Info_UClass_AJMObjectiveFlowStarter.InnerSingleton;
}
UClass* Z_Construct_UClass_AJMObjectiveFlowStarter_NoRegister()
{
	return AJMObjectiveFlowStarter::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AJMObjectiveFlowStarter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DisplayName", "JM Objective Flow Starter" },
		{ "IncludePath", "Actors/JMObjectiveFlowStarter.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Actors/JMObjectiveFlowStarter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlowDefinition_MetaData[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Actors/JMObjectiveFlowStarter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bStartOnBeginPlay_MetaData[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Actors/JMObjectiveFlowStarter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bResetFlowOnEndPlay_MetaData[] = {
		{ "Category", "JM Objective Flow" },
		{ "ModuleRelativePath", "Public/Actors/JMObjectiveFlowStarter.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AJMObjectiveFlowStarter constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FlowDefinition;
	static void NewProp_bStartOnBeginPlay_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStartOnBeginPlay;
	static void NewProp_bResetFlowOnEndPlay_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bResetFlowOnEndPlay;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AJMObjectiveFlowStarter constinit property declarations ********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AJMObjectiveFlowStarter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AJMObjectiveFlowStarter_Statics

// ********** Begin Class AJMObjectiveFlowStarter Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMObjectiveFlowStarter_Statics::NewProp_FlowDefinition = { "FlowDefinition", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMObjectiveFlowStarter, FlowDefinition), Z_Construct_UClass_UJMObjectiveFlowDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlowDefinition_MetaData), NewProp_FlowDefinition_MetaData) };
void Z_Construct_UClass_AJMObjectiveFlowStarter_Statics::NewProp_bStartOnBeginPlay_SetBit(void* Obj)
{
	((AJMObjectiveFlowStarter*)Obj)->bStartOnBeginPlay = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AJMObjectiveFlowStarter_Statics::NewProp_bStartOnBeginPlay = { "bStartOnBeginPlay", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AJMObjectiveFlowStarter), &Z_Construct_UClass_AJMObjectiveFlowStarter_Statics::NewProp_bStartOnBeginPlay_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bStartOnBeginPlay_MetaData), NewProp_bStartOnBeginPlay_MetaData) };
void Z_Construct_UClass_AJMObjectiveFlowStarter_Statics::NewProp_bResetFlowOnEndPlay_SetBit(void* Obj)
{
	((AJMObjectiveFlowStarter*)Obj)->bResetFlowOnEndPlay = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AJMObjectiveFlowStarter_Statics::NewProp_bResetFlowOnEndPlay = { "bResetFlowOnEndPlay", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AJMObjectiveFlowStarter), &Z_Construct_UClass_AJMObjectiveFlowStarter_Statics::NewProp_bResetFlowOnEndPlay_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bResetFlowOnEndPlay_MetaData), NewProp_bResetFlowOnEndPlay_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AJMObjectiveFlowStarter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMObjectiveFlowStarter_Statics::NewProp_FlowDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMObjectiveFlowStarter_Statics::NewProp_bStartOnBeginPlay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMObjectiveFlowStarter_Statics::NewProp_bResetFlowOnEndPlay,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AJMObjectiveFlowStarter_Statics::PropPointers) < 2048);
// ********** End Class AJMObjectiveFlowStarter Property Definitions *******************************
UObject* (*const Z_Construct_UClass_AJMObjectiveFlowStarter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_JMObjective,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AJMObjectiveFlowStarter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AJMObjectiveFlowStarter_Statics::ClassParams = {
	&AJMObjectiveFlowStarter::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AJMObjectiveFlowStarter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AJMObjectiveFlowStarter_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AJMObjectiveFlowStarter_Statics::Class_MetaDataParams), Z_Construct_UClass_AJMObjectiveFlowStarter_Statics::Class_MetaDataParams)
};
void AJMObjectiveFlowStarter::StaticRegisterNativesAJMObjectiveFlowStarter()
{
}
UClass* Z_Construct_UClass_AJMObjectiveFlowStarter()
{
	if (!Z_Registration_Info_UClass_AJMObjectiveFlowStarter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AJMObjectiveFlowStarter.OuterSingleton, Z_Construct_UClass_AJMObjectiveFlowStarter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AJMObjectiveFlowStarter.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AJMObjectiveFlowStarter);
AJMObjectiveFlowStarter::~AJMObjectiveFlowStarter() {}
// ********** End Class AJMObjectiveFlowStarter ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Actors_JMObjectiveFlowStarter_h__Script_JMObjective_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AJMObjectiveFlowStarter, AJMObjectiveFlowStarter::StaticClass, TEXT("AJMObjectiveFlowStarter"), &Z_Registration_Info_UClass_AJMObjectiveFlowStarter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AJMObjectiveFlowStarter), 790538380U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Actors_JMObjectiveFlowStarter_h__Script_JMObjective_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Actors_JMObjectiveFlowStarter_h__Script_JMObjective_2764405095{
	TEXT("/Script/JMObjective"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Actors_JMObjectiveFlowStarter_h__Script_JMObjective_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMObjective_Source_JMObjective_Public_Actors_JMObjectiveFlowStarter_h__Script_JMObjective_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
