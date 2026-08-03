// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JMThrowableProjectile.h"
#include "Engine/HitResult.h"
#include "JMThrowableTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMThrowableProjectile() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UPointLightComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
JMTHROWABLE_API UClass* Z_Construct_UClass_AJMThrowableProjectile();
JMTHROWABLE_API UClass* Z_Construct_UClass_AJMThrowableProjectile_NoRegister();
JMTHROWABLE_API UClass* Z_Construct_UClass_UJMThrowableDefinition_NoRegister();
JMTHROWABLE_API UClass* Z_Construct_UClass_UJMThrowableMovementComponent_NoRegister();
JMTHROWABLE_API UFunction* Z_Construct_UDelegateFunction_JMThrowable_JMProjectileEvent__DelegateSignature();
JMTHROWABLE_API UFunction* Z_Construct_UDelegateFunction_JMThrowable_JMProjectileImpactEvent__DelegateSignature();
JMTHROWABLE_API UScriptStruct* Z_Construct_UScriptStruct_FJMThrowParameters();
PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMThrowable();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FJMProjectileEvent ****************************************************
struct Z_Construct_UDelegateFunction_JMThrowable_JMProjectileEvent__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/JMThrowableProjectile.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMProjectileEvent constinit property declarations ********************
// ********** End Delegate FJMProjectileEvent constinit property declarations **********************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMThrowable_JMProjectileEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMThrowable, nullptr, "JMProjectileEvent__DelegateSignature", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMThrowable_JMProjectileEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMThrowable_JMProjectileEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_JMThrowable_JMProjectileEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMThrowable_JMProjectileEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMProjectileEvent_DelegateWrapper(const FMulticastScriptDelegate& JMProjectileEvent)
{
	JMProjectileEvent.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FJMProjectileEvent ******************************************************

// ********** Begin Delegate FJMProjectileImpactEvent **********************************************
struct Z_Construct_UDelegateFunction_JMThrowable_JMProjectileImpactEvent__DelegateSignature_Statics
{
	struct _Script_JMThrowable_eventJMProjectileImpactEvent_Parms
	{
		FHitResult Hit;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/JMThrowableProjectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMProjectileImpactEvent constinit property declarations **************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Hit;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMProjectileImpactEvent constinit property declarations ****************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMProjectileImpactEvent Property Definitions *************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_JMThrowable_JMProjectileImpactEvent__DelegateSignature_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMThrowable_eventJMProjectileImpactEvent_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hit_MetaData), NewProp_Hit_MetaData) }; // 222120718
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMThrowable_JMProjectileImpactEvent__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMThrowable_JMProjectileImpactEvent__DelegateSignature_Statics::NewProp_Hit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMThrowable_JMProjectileImpactEvent__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMProjectileImpactEvent Property Definitions ***************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMThrowable_JMProjectileImpactEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMThrowable, nullptr, "JMProjectileImpactEvent__DelegateSignature", 	Z_Construct_UDelegateFunction_JMThrowable_JMProjectileImpactEvent__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMThrowable_JMProjectileImpactEvent__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMThrowable_JMProjectileImpactEvent__DelegateSignature_Statics::_Script_JMThrowable_eventJMProjectileImpactEvent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMThrowable_JMProjectileImpactEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMThrowable_JMProjectileImpactEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMThrowable_JMProjectileImpactEvent__DelegateSignature_Statics::_Script_JMThrowable_eventJMProjectileImpactEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMThrowable_JMProjectileImpactEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMThrowable_JMProjectileImpactEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMProjectileImpactEvent_DelegateWrapper(const FMulticastScriptDelegate& JMProjectileImpactEvent, FHitResult const& Hit)
{
	struct _Script_JMThrowable_eventJMProjectileImpactEvent_Parms
	{
		FHitResult Hit;
	};
	_Script_JMThrowable_eventJMProjectileImpactEvent_Parms Parms;
	Parms.Hit=Hit;
	JMProjectileImpactEvent.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMProjectileImpactEvent ************************************************

// ********** Begin Class AJMThrowableProjectile Function ConfigureDefinition **********************
struct Z_Construct_UFunction_AJMThrowableProjectile_ConfigureDefinition_Statics
{
	struct JMThrowableProjectile_eventConfigureDefinition_Parms
	{
		UJMThrowableDefinition* Definition;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/JMThrowableProjectile.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ConfigureDefinition constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Definition;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ConfigureDefinition constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ConfigureDefinition Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AJMThrowableProjectile_ConfigureDefinition_Statics::NewProp_Definition = { "Definition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMThrowableProjectile_eventConfigureDefinition_Parms, Definition), Z_Construct_UClass_UJMThrowableDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AJMThrowableProjectile_ConfigureDefinition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AJMThrowableProjectile_ConfigureDefinition_Statics::NewProp_Definition,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AJMThrowableProjectile_ConfigureDefinition_Statics::PropPointers) < 2048);
// ********** End Function ConfigureDefinition Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AJMThrowableProjectile_ConfigureDefinition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AJMThrowableProjectile, nullptr, "ConfigureDefinition", 	Z_Construct_UFunction_AJMThrowableProjectile_ConfigureDefinition_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AJMThrowableProjectile_ConfigureDefinition_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AJMThrowableProjectile_ConfigureDefinition_Statics::JMThrowableProjectile_eventConfigureDefinition_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AJMThrowableProjectile_ConfigureDefinition_Statics::Function_MetaDataParams), Z_Construct_UFunction_AJMThrowableProjectile_ConfigureDefinition_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AJMThrowableProjectile_ConfigureDefinition_Statics::JMThrowableProjectile_eventConfigureDefinition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AJMThrowableProjectile_ConfigureDefinition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AJMThrowableProjectile_ConfigureDefinition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AJMThrowableProjectile::execConfigureDefinition)
{
	P_GET_OBJECT(UJMThrowableDefinition,Z_Param_Definition);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ConfigureDefinition(Z_Param_Definition);
	P_NATIVE_END;
}
// ********** End Class AJMThrowableProjectile Function ConfigureDefinition ************************

// ********** Begin Class AJMThrowableProjectile Function Launch ***********************************
struct Z_Construct_UFunction_AJMThrowableProjectile_Launch_Statics
{
	struct JMThrowableProjectile_eventLaunch_Parms
	{
		FJMThrowParameters Parameters;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/JMThrowableProjectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Parameters_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Launch constinit property declarations ********************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Parameters;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Launch constinit property declarations **********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Launch Property Definitions *******************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AJMThrowableProjectile_Launch_Statics::NewProp_Parameters = { "Parameters", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMThrowableProjectile_eventLaunch_Parms, Parameters), Z_Construct_UScriptStruct_FJMThrowParameters, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Parameters_MetaData), NewProp_Parameters_MetaData) }; // 1204343964
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AJMThrowableProjectile_Launch_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AJMThrowableProjectile_Launch_Statics::NewProp_Parameters,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AJMThrowableProjectile_Launch_Statics::PropPointers) < 2048);
// ********** End Function Launch Property Definitions *********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AJMThrowableProjectile_Launch_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AJMThrowableProjectile, nullptr, "Launch", 	Z_Construct_UFunction_AJMThrowableProjectile_Launch_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AJMThrowableProjectile_Launch_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AJMThrowableProjectile_Launch_Statics::JMThrowableProjectile_eventLaunch_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AJMThrowableProjectile_Launch_Statics::Function_MetaDataParams), Z_Construct_UFunction_AJMThrowableProjectile_Launch_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AJMThrowableProjectile_Launch_Statics::JMThrowableProjectile_eventLaunch_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AJMThrowableProjectile_Launch()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AJMThrowableProjectile_Launch_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AJMThrowableProjectile::execLaunch)
{
	P_GET_STRUCT_REF(FJMThrowParameters,Z_Param_Out_Parameters);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Launch(Z_Param_Out_Parameters);
	P_NATIVE_END;
}
// ********** End Class AJMThrowableProjectile Function Launch *************************************

// ********** Begin Class AJMThrowableProjectile ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AJMThrowableProjectile;
UClass* AJMThrowableProjectile::GetPrivateStaticClass()
{
	using TClass = AJMThrowableProjectile;
	if (!Z_Registration_Info_UClass_AJMThrowableProjectile.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMThrowableProjectile"),
			Z_Registration_Info_UClass_AJMThrowableProjectile.InnerSingleton,
			StaticRegisterNativesAJMThrowableProjectile,
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
	return Z_Registration_Info_UClass_AJMThrowableProjectile.InnerSingleton;
}
UClass* Z_Construct_UClass_AJMThrowableProjectile_NoRegister()
{
	return AJMThrowableProjectile::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AJMThrowableProjectile_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "JMThrowableProjectile.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableProjectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SphereCollision_MetaData[] = {
		{ "Category", "JMThrowableProjectile" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableProjectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThrowableMovement_MetaData[] = {
		{ "Category", "JMThrowableProjectile" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableProjectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BurstLight_MetaData[] = {
		{ "Category", "JMThrowableProjectile" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableProjectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileVisual_MetaData[] = {
		{ "Category", "JMThrowableProjectile" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableProjectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NativeBoxVisual_MetaData[] = {
		{ "Category", "JMThrowableProjectile" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableProjectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnThrown_MetaData[] = {
		{ "ModuleRelativePath", "Public/JMThrowableProjectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnBounced_MetaData[] = {
		{ "ModuleRelativePath", "Public/JMThrowableProjectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnRested_MetaData[] = {
		{ "ModuleRelativePath", "Public/JMThrowableProjectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveDefinition_MetaData[] = {
		{ "ModuleRelativePath", "Public/JMThrowableProjectile.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AJMThrowableProjectile constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SphereCollision;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ThrowableMovement;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BurstLight;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ProjectileVisual;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NativeBoxVisual;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnThrown;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnBounced;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnRested;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveDefinition;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AJMThrowableProjectile constinit property declarations *********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ConfigureDefinition"), .Pointer = &AJMThrowableProjectile::execConfigureDefinition },
		{ .NameUTF8 = UTF8TEXT("Launch"), .Pointer = &AJMThrowableProjectile::execLaunch },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AJMThrowableProjectile_ConfigureDefinition, "ConfigureDefinition" }, // 1263885862
		{ &Z_Construct_UFunction_AJMThrowableProjectile_Launch, "Launch" }, // 3373979446
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AJMThrowableProjectile>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AJMThrowableProjectile_Statics

// ********** Begin Class AJMThrowableProjectile Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMThrowableProjectile_Statics::NewProp_SphereCollision = { "SphereCollision", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMThrowableProjectile, SphereCollision), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SphereCollision_MetaData), NewProp_SphereCollision_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMThrowableProjectile_Statics::NewProp_ThrowableMovement = { "ThrowableMovement", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMThrowableProjectile, ThrowableMovement), Z_Construct_UClass_UJMThrowableMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThrowableMovement_MetaData), NewProp_ThrowableMovement_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMThrowableProjectile_Statics::NewProp_BurstLight = { "BurstLight", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMThrowableProjectile, BurstLight), Z_Construct_UClass_UPointLightComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BurstLight_MetaData), NewProp_BurstLight_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMThrowableProjectile_Statics::NewProp_ProjectileVisual = { "ProjectileVisual", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMThrowableProjectile, ProjectileVisual), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileVisual_MetaData), NewProp_ProjectileVisual_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMThrowableProjectile_Statics::NewProp_NativeBoxVisual = { "NativeBoxVisual", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMThrowableProjectile, NativeBoxVisual), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NativeBoxVisual_MetaData), NewProp_NativeBoxVisual_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AJMThrowableProjectile_Statics::NewProp_OnThrown = { "OnThrown", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMThrowableProjectile, OnThrown), Z_Construct_UDelegateFunction_JMThrowable_JMProjectileEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnThrown_MetaData), NewProp_OnThrown_MetaData) }; // 4067751329
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AJMThrowableProjectile_Statics::NewProp_OnBounced = { "OnBounced", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMThrowableProjectile, OnBounced), Z_Construct_UDelegateFunction_JMThrowable_JMProjectileImpactEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnBounced_MetaData), NewProp_OnBounced_MetaData) }; // 2269770564
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AJMThrowableProjectile_Statics::NewProp_OnRested = { "OnRested", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMThrowableProjectile, OnRested), Z_Construct_UDelegateFunction_JMThrowable_JMProjectileImpactEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnRested_MetaData), NewProp_OnRested_MetaData) }; // 2269770564
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMThrowableProjectile_Statics::NewProp_ActiveDefinition = { "ActiveDefinition", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMThrowableProjectile, ActiveDefinition), Z_Construct_UClass_UJMThrowableDefinition_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveDefinition_MetaData), NewProp_ActiveDefinition_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AJMThrowableProjectile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMThrowableProjectile_Statics::NewProp_SphereCollision,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMThrowableProjectile_Statics::NewProp_ThrowableMovement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMThrowableProjectile_Statics::NewProp_BurstLight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMThrowableProjectile_Statics::NewProp_ProjectileVisual,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMThrowableProjectile_Statics::NewProp_NativeBoxVisual,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMThrowableProjectile_Statics::NewProp_OnThrown,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMThrowableProjectile_Statics::NewProp_OnBounced,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMThrowableProjectile_Statics::NewProp_OnRested,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMThrowableProjectile_Statics::NewProp_ActiveDefinition,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AJMThrowableProjectile_Statics::PropPointers) < 2048);
// ********** End Class AJMThrowableProjectile Property Definitions ********************************
UObject* (*const Z_Construct_UClass_AJMThrowableProjectile_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_JMThrowable,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AJMThrowableProjectile_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AJMThrowableProjectile_Statics::ClassParams = {
	&AJMThrowableProjectile::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AJMThrowableProjectile_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AJMThrowableProjectile_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AJMThrowableProjectile_Statics::Class_MetaDataParams), Z_Construct_UClass_AJMThrowableProjectile_Statics::Class_MetaDataParams)
};
void AJMThrowableProjectile::StaticRegisterNativesAJMThrowableProjectile()
{
	UClass* Class = AJMThrowableProjectile::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AJMThrowableProjectile_Statics::Funcs));
}
UClass* Z_Construct_UClass_AJMThrowableProjectile()
{
	if (!Z_Registration_Info_UClass_AJMThrowableProjectile.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AJMThrowableProjectile.OuterSingleton, Z_Construct_UClass_AJMThrowableProjectile_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AJMThrowableProjectile.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AJMThrowableProjectile);
AJMThrowableProjectile::~AJMThrowableProjectile() {}
// ********** End Class AJMThrowableProjectile *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableProjectile_h__Script_JMThrowable_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AJMThrowableProjectile, AJMThrowableProjectile::StaticClass, TEXT("AJMThrowableProjectile"), &Z_Registration_Info_UClass_AJMThrowableProjectile, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AJMThrowableProjectile), 908412329U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableProjectile_h__Script_JMThrowable_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableProjectile_h__Script_JMThrowable_4046629009{
	TEXT("/Script/JMThrowable"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableProjectile_h__Script_JMThrowable_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableProjectile_h__Script_JMThrowable_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
