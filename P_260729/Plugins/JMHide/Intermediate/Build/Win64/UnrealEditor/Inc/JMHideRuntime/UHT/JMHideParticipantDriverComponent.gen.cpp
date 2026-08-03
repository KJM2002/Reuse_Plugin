// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/JMHideParticipantDriverComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMHideParticipantDriverComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideParticipantDriverComponent();
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideParticipantDriverComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMHideRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMHideParticipantDriverComponent ****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMHideParticipantDriverComponent;
UClass* UJMHideParticipantDriverComponent::GetPrivateStaticClass()
{
	using TClass = UJMHideParticipantDriverComponent;
	if (!Z_Registration_Info_UClass_UJMHideParticipantDriverComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMHideParticipantDriverComponent"),
			Z_Registration_Info_UClass_UJMHideParticipantDriverComponent.InnerSingleton,
			StaticRegisterNativesUJMHideParticipantDriverComponent,
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
	return Z_Registration_Info_UClass_UJMHideParticipantDriverComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMHideParticipantDriverComponent_NoRegister()
{
	return UJMHideParticipantDriverComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMHideParticipantDriverComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JMHide" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Player-side capability boundary. Implementations must complete every accepted\n * operation exactly once through CompleteOperation.\n */" },
#endif
		{ "IncludePath", "Components/JMHideParticipantDriverComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Components/JMHideParticipantDriverComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Player-side capability boundary. Implementations must complete every accepted\noperation exactly once through CompleteOperation." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UJMHideParticipantDriverComponent constinit property declarations ********
// ********** End Class UJMHideParticipantDriverComponent constinit property declarations **********
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMHideParticipantDriverComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMHideParticipantDriverComponent_Statics
UObject* (*const Z_Construct_UClass_UJMHideParticipantDriverComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideParticipantDriverComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMHideParticipantDriverComponent_Statics::ClassParams = {
	&UJMHideParticipantDriverComponent::StaticClass,
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
	0x00B000A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideParticipantDriverComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMHideParticipantDriverComponent_Statics::Class_MetaDataParams)
};
void UJMHideParticipantDriverComponent::StaticRegisterNativesUJMHideParticipantDriverComponent()
{
}
UClass* Z_Construct_UClass_UJMHideParticipantDriverComponent()
{
	if (!Z_Registration_Info_UClass_UJMHideParticipantDriverComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMHideParticipantDriverComponent.OuterSingleton, Z_Construct_UClass_UJMHideParticipantDriverComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMHideParticipantDriverComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMHideParticipantDriverComponent);
UJMHideParticipantDriverComponent::~UJMHideParticipantDriverComponent() {}
// ********** End Class UJMHideParticipantDriverComponent ******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideParticipantDriverComponent_h__Script_JMHideRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMHideParticipantDriverComponent, UJMHideParticipantDriverComponent::StaticClass, TEXT("UJMHideParticipantDriverComponent"), &Z_Registration_Info_UClass_UJMHideParticipantDriverComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMHideParticipantDriverComponent), 2605269770U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideParticipantDriverComponent_h__Script_JMHideRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideParticipantDriverComponent_h__Script_JMHideRuntime_2267481263{
	TEXT("/Script/JMHideRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideParticipantDriverComponent_h__Script_JMHideRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideParticipantDriverComponent_h__Script_JMHideRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
