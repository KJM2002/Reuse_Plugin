// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Movement/JMCustomDoorMovementComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMCustomDoorMovementComponent() {}

// ********** Begin Cross Module References ********************************************************
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMCustomDoorMovementComponent();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMCustomDoorMovementComponent_NoRegister();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorMovementComponent();
UPackage* Z_Construct_UPackage__Script_JMDoorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMCustomDoorMovementComponent *******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMCustomDoorMovementComponent;
UClass* UJMCustomDoorMovementComponent::GetPrivateStaticClass()
{
	using TClass = UJMCustomDoorMovementComponent;
	if (!Z_Registration_Info_UClass_UJMCustomDoorMovementComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMCustomDoorMovementComponent"),
			Z_Registration_Info_UClass_UJMCustomDoorMovementComponent.InnerSingleton,
			StaticRegisterNativesUJMCustomDoorMovementComponent,
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
	return Z_Registration_Info_UClass_UJMCustomDoorMovementComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMCustomDoorMovementComponent_NoRegister()
{
	return UJMCustomDoorMovementComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMCustomDoorMovementComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JMGameplay" },
		{ "DisplayName", "JM Custom Door Movement" },
		{ "IncludePath", "Movement/JMCustomDoorMovementComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Movement/JMCustomDoorMovementComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMCustomDoorMovementComponent constinit property declarations ***********
// ********** End Class UJMCustomDoorMovementComponent constinit property declarations *************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMCustomDoorMovementComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMCustomDoorMovementComponent_Statics
UObject* (*const Z_Construct_UClass_UJMCustomDoorMovementComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UJMDoorMovementComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMCustomDoorMovementComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMCustomDoorMovementComponent_Statics::ClassParams = {
	&UJMCustomDoorMovementComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMCustomDoorMovementComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMCustomDoorMovementComponent_Statics::Class_MetaDataParams)
};
void UJMCustomDoorMovementComponent::StaticRegisterNativesUJMCustomDoorMovementComponent()
{
}
UClass* Z_Construct_UClass_UJMCustomDoorMovementComponent()
{
	if (!Z_Registration_Info_UClass_UJMCustomDoorMovementComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMCustomDoorMovementComponent.OuterSingleton, Z_Construct_UClass_UJMCustomDoorMovementComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMCustomDoorMovementComponent.OuterSingleton;
}
UJMCustomDoorMovementComponent::UJMCustomDoorMovementComponent() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMCustomDoorMovementComponent);
UJMCustomDoorMovementComponent::~UJMCustomDoorMovementComponent() {}
// ********** End Class UJMCustomDoorMovementComponent *********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMCustomDoorMovementComponent_h__Script_JMDoorRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMCustomDoorMovementComponent, UJMCustomDoorMovementComponent::StaticClass, TEXT("UJMCustomDoorMovementComponent"), &Z_Registration_Info_UClass_UJMCustomDoorMovementComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMCustomDoorMovementComponent), 3782292068U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMCustomDoorMovementComponent_h__Script_JMDoorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMCustomDoorMovementComponent_h__Script_JMDoorRuntime_2569629869{
	TEXT("/Script/JMDoorRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMCustomDoorMovementComponent_h__Script_JMDoorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Movement_JMCustomDoorMovementComponent_h__Script_JMDoorRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
