// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Movement/JMRotatingDoorMovementComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMRotatingDoorMovementComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorMovementComponent();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMRotatingDoorMovementComponent();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMRotatingDoorMovementComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMDoorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMRotatingDoorMovementComponent *****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMRotatingDoorMovementComponent;
UClass* UJMRotatingDoorMovementComponent::GetPrivateStaticClass()
{
	using TClass = UJMRotatingDoorMovementComponent;
	if (!Z_Registration_Info_UClass_UJMRotatingDoorMovementComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMRotatingDoorMovementComponent"),
			Z_Registration_Info_UClass_UJMRotatingDoorMovementComponent.InnerSingleton,
			StaticRegisterNativesUJMRotatingDoorMovementComponent,
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
	return Z_Registration_Info_UClass_UJMRotatingDoorMovementComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMRotatingDoorMovementComponent_NoRegister()
{
	return UJMRotatingDoorMovementComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMRotatingDoorMovementComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JMGameplay" },
		{ "IncludePath", "Movement/JMRotatingDoorMovementComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Movement/JMRotatingDoorMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpenAngle_MetaData[] = {
		{ "Category", "JM Door|Rotation" },
		{ "ClampMax", "360.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Movement/JMRotatingDoorMovementComponent.h" },
		{ "Units", "deg" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LocalRotationAxis_MetaData[] = {
		{ "Category", "JM Door|Rotation" },
		{ "ModuleRelativePath", "Public/Movement/JMRotatingDoorMovementComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMRotatingDoorMovementComponent constinit property declarations *********
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OpenAngle;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LocalRotationAxis;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMRotatingDoorMovementComponent constinit property declarations ***********
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMRotatingDoorMovementComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMRotatingDoorMovementComponent_Statics

// ********** Begin Class UJMRotatingDoorMovementComponent Property Definitions ********************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMRotatingDoorMovementComponent_Statics::NewProp_OpenAngle = { "OpenAngle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMRotatingDoorMovementComponent, OpenAngle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpenAngle_MetaData), NewProp_OpenAngle_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMRotatingDoorMovementComponent_Statics::NewProp_LocalRotationAxis = { "LocalRotationAxis", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMRotatingDoorMovementComponent, LocalRotationAxis), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LocalRotationAxis_MetaData), NewProp_LocalRotationAxis_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMRotatingDoorMovementComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMRotatingDoorMovementComponent_Statics::NewProp_OpenAngle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMRotatingDoorMovementComponent_Statics::NewProp_LocalRotationAxis,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMRotatingDoorMovementComponent_Statics::PropPointers) < 2048);
// ********** End Class UJMRotatingDoorMovementComponent Property Definitions **********************
UObject* (*const Z_Construct_UClass_UJMRotatingDoorMovementComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UJMDoorMovementComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMRotatingDoorMovementComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMRotatingDoorMovementComponent_Statics::ClassParams = {
	&UJMRotatingDoorMovementComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMRotatingDoorMovementComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMRotatingDoorMovementComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMRotatingDoorMovementComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMRotatingDoorMovementComponent_Statics::Class_MetaDataParams)
};
void UJMRotatingDoorMovementComponent::StaticRegisterNativesUJMRotatingDoorMovementComponent()
{
}
UClass* Z_Construct_UClass_UJMRotatingDoorMovementComponent()
{
	if (!Z_Registration_Info_UClass_UJMRotatingDoorMovementComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMRotatingDoorMovementComponent.OuterSingleton, Z_Construct_UClass_UJMRotatingDoorMovementComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMRotatingDoorMovementComponent.OuterSingleton;
}
UJMRotatingDoorMovementComponent::UJMRotatingDoorMovementComponent() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMRotatingDoorMovementComponent);
UJMRotatingDoorMovementComponent::~UJMRotatingDoorMovementComponent() {}
// ********** End Class UJMRotatingDoorMovementComponent *******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMRotatingDoorMovementComponent_h__Script_JMDoorRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMRotatingDoorMovementComponent, UJMRotatingDoorMovementComponent::StaticClass, TEXT("UJMRotatingDoorMovementComponent"), &Z_Registration_Info_UClass_UJMRotatingDoorMovementComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMRotatingDoorMovementComponent), 9599462U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMRotatingDoorMovementComponent_h__Script_JMDoorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMRotatingDoorMovementComponent_h__Script_JMDoorRuntime_2485086836{
	TEXT("/Script/JMDoorRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMRotatingDoorMovementComponent_h__Script_JMDoorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMRotatingDoorMovementComponent_h__Script_JMDoorRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
