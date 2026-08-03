// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/JMJumpScareFocusComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMJumpScareFocusComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareFocusComponent();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareFocusComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMJumpScare();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMJumpScareFocusComponent ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMJumpScareFocusComponent;
UClass* UJMJumpScareFocusComponent::GetPrivateStaticClass()
{
	using TClass = UJMJumpScareFocusComponent;
	if (!Z_Registration_Info_UClass_UJMJumpScareFocusComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMJumpScareFocusComponent"),
			Z_Registration_Info_UClass_UJMJumpScareFocusComponent.InnerSingleton,
			StaticRegisterNativesUJMJumpScareFocusComponent,
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
	return Z_Registration_Info_UClass_UJMJumpScareFocusComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMJumpScareFocusComponent_NoRegister()
{
	return UJMJumpScareFocusComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMJumpScareFocusComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional face/eyes/focal transform used by ForcedLookAt without assuming an Actor root location. */" },
#endif
		{ "DisplayName", "JM JumpScare Focus" },
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "Components/JMJumpScareFocusComponent.h" },
		{ "ModuleRelativePath", "Public/Components/JMJumpScareFocusComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional face/eyes/focal transform used by ForcedLookAt without assuming an Actor root location." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UJMJumpScareFocusComponent constinit property declarations ***************
// ********** End Class UJMJumpScareFocusComponent constinit property declarations *****************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMJumpScareFocusComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMJumpScareFocusComponent_Statics
UObject* (*const Z_Construct_UClass_UJMJumpScareFocusComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USceneComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMJumpScare,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareFocusComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMJumpScareFocusComponent_Statics::ClassParams = {
	&UJMJumpScareFocusComponent::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareFocusComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMJumpScareFocusComponent_Statics::Class_MetaDataParams)
};
void UJMJumpScareFocusComponent::StaticRegisterNativesUJMJumpScareFocusComponent()
{
}
UClass* Z_Construct_UClass_UJMJumpScareFocusComponent()
{
	if (!Z_Registration_Info_UClass_UJMJumpScareFocusComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMJumpScareFocusComponent.OuterSingleton, Z_Construct_UClass_UJMJumpScareFocusComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMJumpScareFocusComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMJumpScareFocusComponent);
UJMJumpScareFocusComponent::~UJMJumpScareFocusComponent() {}
// ********** End Class UJMJumpScareFocusComponent *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Components_JMJumpScareFocusComponent_h__Script_JMJumpScare_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMJumpScareFocusComponent, UJMJumpScareFocusComponent::StaticClass, TEXT("UJMJumpScareFocusComponent"), &Z_Registration_Info_UClass_UJMJumpScareFocusComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMJumpScareFocusComponent), 4534236U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Components_JMJumpScareFocusComponent_h__Script_JMJumpScare_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Components_JMJumpScareFocusComponent_h__Script_JMJumpScare_3220685783{
	TEXT("/Script/JMJumpScare"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Components_JMJumpScareFocusComponent_h__Script_JMJumpScare_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Components_JMJumpScareFocusComponent_h__Script_JMJumpScare_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
