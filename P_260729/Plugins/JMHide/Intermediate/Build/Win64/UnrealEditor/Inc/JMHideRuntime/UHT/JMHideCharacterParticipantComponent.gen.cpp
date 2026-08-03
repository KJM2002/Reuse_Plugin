// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/JMHideCharacterParticipantComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMHideCharacterParticipantComponent() {}

// ********** Begin Cross Module References ********************************************************
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideCharacterParticipantComponent();
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideCharacterParticipantComponent_NoRegister();
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideParticipantDriverComponent();
UPackage* Z_Construct_UPackage__Script_JMHideRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMHideCharacterParticipantComponent *************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMHideCharacterParticipantComponent;
UClass* UJMHideCharacterParticipantComponent::GetPrivateStaticClass()
{
	using TClass = UJMHideCharacterParticipantComponent;
	if (!Z_Registration_Info_UClass_UJMHideCharacterParticipantComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMHideCharacterParticipantComponent"),
			Z_Registration_Info_UClass_UJMHideCharacterParticipantComponent.InnerSingleton,
			StaticRegisterNativesUJMHideCharacterParticipantComponent,
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
	return Z_Registration_Info_UClass_UJMHideCharacterParticipantComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMHideCharacterParticipantComponent_NoRegister()
{
	return UJMHideCharacterParticipantComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMHideCharacterParticipantComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JMHide" },
		{ "IncludePath", "Components/JMHideCharacterParticipantComponent.h" },
		{ "ModuleRelativePath", "Public/Components/JMHideCharacterParticipantComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMHideCharacterParticipantComponent constinit property declarations *****
// ********** End Class UJMHideCharacterParticipantComponent constinit property declarations *******
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMHideCharacterParticipantComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMHideCharacterParticipantComponent_Statics
UObject* (*const Z_Construct_UClass_UJMHideCharacterParticipantComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UJMHideParticipantDriverComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideCharacterParticipantComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMHideCharacterParticipantComponent_Statics::ClassParams = {
	&UJMHideCharacterParticipantComponent::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideCharacterParticipantComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMHideCharacterParticipantComponent_Statics::Class_MetaDataParams)
};
void UJMHideCharacterParticipantComponent::StaticRegisterNativesUJMHideCharacterParticipantComponent()
{
}
UClass* Z_Construct_UClass_UJMHideCharacterParticipantComponent()
{
	if (!Z_Registration_Info_UClass_UJMHideCharacterParticipantComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMHideCharacterParticipantComponent.OuterSingleton, Z_Construct_UClass_UJMHideCharacterParticipantComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMHideCharacterParticipantComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMHideCharacterParticipantComponent);
UJMHideCharacterParticipantComponent::~UJMHideCharacterParticipantComponent() {}
// ********** End Class UJMHideCharacterParticipantComponent ***************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideCharacterParticipantComponent_h__Script_JMHideRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMHideCharacterParticipantComponent, UJMHideCharacterParticipantComponent::StaticClass, TEXT("UJMHideCharacterParticipantComponent"), &Z_Registration_Info_UClass_UJMHideCharacterParticipantComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMHideCharacterParticipantComponent), 994423944U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideCharacterParticipantComponent_h__Script_JMHideRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideCharacterParticipantComponent_h__Script_JMHideRuntime_1782245357{
	TEXT("/Script/JMHideRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideCharacterParticipantComponent_h__Script_JMHideRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideCharacterParticipantComponent_h__Script_JMHideRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
