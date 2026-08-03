// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JMThrowableMovementComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMThrowableMovementComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
JMTHROWABLE_API UClass* Z_Construct_UClass_UJMThrowableMovementComponent();
JMTHROWABLE_API UClass* Z_Construct_UClass_UJMThrowableMovementComponent_NoRegister();
JMTHROWABLE_API UEnum* Z_Construct_UEnum_JMThrowable_EJMThrowableProjectileState();
UPackage* Z_Construct_UPackage__Script_JMThrowable();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMThrowableMovementComponent ********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMThrowableMovementComponent;
UClass* UJMThrowableMovementComponent::GetPrivateStaticClass()
{
	using TClass = UJMThrowableMovementComponent;
	if (!Z_Registration_Info_UClass_UJMThrowableMovementComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMThrowableMovementComponent"),
			Z_Registration_Info_UClass_UJMThrowableMovementComponent.InnerSingleton,
			StaticRegisterNativesUJMThrowableMovementComponent,
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
	return Z_Registration_Info_UClass_UJMThrowableMovementComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMThrowableMovementComponent_NoRegister()
{
	return UJMThrowableMovementComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMThrowableMovementComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "JM" },
		{ "IncludePath", "JMThrowableMovementComponent.h" },
		{ "ModuleRelativePath", "Public/JMThrowableMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_State_MetaData[] = {
		{ "Category", "JMThrowableMovementComponent" },
		{ "ModuleRelativePath", "Public/JMThrowableMovementComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Velocity_MetaData[] = {
		{ "Category", "JMThrowableMovementComponent" },
		{ "ModuleRelativePath", "Public/JMThrowableMovementComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMThrowableMovementComponent constinit property declarations ************
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Velocity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMThrowableMovementComponent constinit property declarations **************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMThrowableMovementComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMThrowableMovementComponent_Statics

// ********** Begin Class UJMThrowableMovementComponent Property Definitions ***********************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMThrowableMovementComponent_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMThrowableMovementComponent_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableMovementComponent, State), Z_Construct_UEnum_JMThrowable_EJMThrowableProjectileState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_State_MetaData), NewProp_State_MetaData) }; // 3369480408
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMThrowableMovementComponent_Statics::NewProp_Velocity = { "Velocity", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableMovementComponent, Velocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Velocity_MetaData), NewProp_Velocity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMThrowableMovementComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableMovementComponent_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableMovementComponent_Statics::NewProp_State,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableMovementComponent_Statics::NewProp_Velocity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableMovementComponent_Statics::PropPointers) < 2048);
// ********** End Class UJMThrowableMovementComponent Property Definitions *************************
UObject* (*const Z_Construct_UClass_UJMThrowableMovementComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMThrowable,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableMovementComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMThrowableMovementComponent_Statics::ClassParams = {
	&UJMThrowableMovementComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMThrowableMovementComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableMovementComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableMovementComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMThrowableMovementComponent_Statics::Class_MetaDataParams)
};
void UJMThrowableMovementComponent::StaticRegisterNativesUJMThrowableMovementComponent()
{
}
UClass* Z_Construct_UClass_UJMThrowableMovementComponent()
{
	if (!Z_Registration_Info_UClass_UJMThrowableMovementComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMThrowableMovementComponent.OuterSingleton, Z_Construct_UClass_UJMThrowableMovementComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMThrowableMovementComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMThrowableMovementComponent);
UJMThrowableMovementComponent::~UJMThrowableMovementComponent() {}
// ********** End Class UJMThrowableMovementComponent **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableMovementComponent_h__Script_JMThrowable_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMThrowableMovementComponent, UJMThrowableMovementComponent::StaticClass, TEXT("UJMThrowableMovementComponent"), &Z_Registration_Info_UClass_UJMThrowableMovementComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMThrowableMovementComponent), 1737093366U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableMovementComponent_h__Script_JMThrowable_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableMovementComponent_h__Script_JMThrowable_1638544024{
	TEXT("/Script/JMThrowable"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableMovementComponent_h__Script_JMThrowable_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableMovementComponent_h__Script_JMThrowable_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
