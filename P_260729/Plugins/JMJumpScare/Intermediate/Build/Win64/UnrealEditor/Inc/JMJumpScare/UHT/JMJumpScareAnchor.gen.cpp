// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actors/JMJumpScareAnchor.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMJumpScareAnchor() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UArrowComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBillboardComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
JMJUMPSCARE_API UClass* Z_Construct_UClass_AJMJumpScareAnchor();
JMJUMPSCARE_API UClass* Z_Construct_UClass_AJMJumpScareAnchor_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMJumpScare();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AJMJumpScareAnchor Function GetJumpScareAnchorTransform ******************
struct Z_Construct_UFunction_AJMJumpScareAnchor_GetJumpScareAnchorTransform_Statics
{
	struct JMJumpScareAnchor_eventGetJumpScareAnchorTransform_Parms
	{
		FTransform ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM JumpScare" },
		{ "ModuleRelativePath", "Public/Actors/JMJumpScareAnchor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetJumpScareAnchorTransform constinit property declarations ***********
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetJumpScareAnchorTransform constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetJumpScareAnchorTransform Property Definitions **********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AJMJumpScareAnchor_GetJumpScareAnchorTransform_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMJumpScareAnchor_eventGetJumpScareAnchorTransform_Parms, ReturnValue), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AJMJumpScareAnchor_GetJumpScareAnchorTransform_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AJMJumpScareAnchor_GetJumpScareAnchorTransform_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AJMJumpScareAnchor_GetJumpScareAnchorTransform_Statics::PropPointers) < 2048);
// ********** End Function GetJumpScareAnchorTransform Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AJMJumpScareAnchor_GetJumpScareAnchorTransform_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AJMJumpScareAnchor, nullptr, "GetJumpScareAnchorTransform", 	Z_Construct_UFunction_AJMJumpScareAnchor_GetJumpScareAnchorTransform_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AJMJumpScareAnchor_GetJumpScareAnchorTransform_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AJMJumpScareAnchor_GetJumpScareAnchorTransform_Statics::JMJumpScareAnchor_eventGetJumpScareAnchorTransform_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AJMJumpScareAnchor_GetJumpScareAnchorTransform_Statics::Function_MetaDataParams), Z_Construct_UFunction_AJMJumpScareAnchor_GetJumpScareAnchorTransform_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AJMJumpScareAnchor_GetJumpScareAnchorTransform_Statics::JMJumpScareAnchor_eventGetJumpScareAnchorTransform_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AJMJumpScareAnchor_GetJumpScareAnchorTransform()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AJMJumpScareAnchor_GetJumpScareAnchorTransform_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AJMJumpScareAnchor::execGetJumpScareAnchorTransform)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FTransform*)Z_Param__Result=P_THIS->GetJumpScareAnchorTransform();
	P_NATIVE_END;
}
// ********** End Class AJMJumpScareAnchor Function GetJumpScareAnchorTransform ********************

// ********** Begin Class AJMJumpScareAnchor *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AJMJumpScareAnchor;
UClass* AJMJumpScareAnchor::GetPrivateStaticClass()
{
	using TClass = AJMJumpScareAnchor;
	if (!Z_Registration_Info_UClass_AJMJumpScareAnchor.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMJumpScareAnchor"),
			Z_Registration_Info_UClass_AJMJumpScareAnchor.InnerSingleton,
			StaticRegisterNativesAJMJumpScareAnchor,
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
	return Z_Registration_Info_UClass_AJMJumpScareAnchor.InnerSingleton;
}
UClass* Z_Construct_UClass_AJMJumpScareAnchor_NoRegister()
{
	return AJMJumpScareAnchor::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AJMJumpScareAnchor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DisplayName", "JM JumpScare Anchor" },
		{ "IncludePath", "Actors/JMJumpScareAnchor.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Actors/JMJumpScareAnchor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneRoot_MetaData[] = {
		{ "Category", "JM JumpScare | Spawn" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/JMJumpScareAnchor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnchorId_MetaData[] = {
		{ "Categories", "JumpScare.Anchor" },
		{ "Category", "JM JumpScare | Identity" },
		{ "ModuleRelativePath", "Public/Actors/JMJumpScareAnchor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideRotation_MetaData[] = {
		{ "Category", "JM JumpScare | Spawn" },
		{ "ModuleRelativePath", "Public/Actors/JMJumpScareAnchor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotationOverride_MetaData[] = {
		{ "Category", "JM JumpScare | Spawn" },
		{ "EditCondition", "bOverrideRotation" },
		{ "ModuleRelativePath", "Public/Actors/JMJumpScareAnchor.h" },
	};
#if WITH_EDITORONLY_DATA
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DirectionArrow_MetaData[] = {
		{ "Category", "JM JumpScare | Debug" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/JMJumpScareAnchor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Billboard_MetaData[] = {
		{ "Category", "JM JumpScare | Debug" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/JMJumpScareAnchor.h" },
	};
#endif // WITH_EDITORONLY_DATA
#endif // WITH_METADATA

// ********** Begin Class AJMJumpScareAnchor constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneRoot;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AnchorId;
	static void NewProp_bOverrideRotation_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideRotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RotationOverride;
#if WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DirectionArrow;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Billboard;
#endif // WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AJMJumpScareAnchor constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetJumpScareAnchorTransform"), .Pointer = &AJMJumpScareAnchor::execGetJumpScareAnchorTransform },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AJMJumpScareAnchor_GetJumpScareAnchorTransform, "GetJumpScareAnchorTransform" }, // 1098976045
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AJMJumpScareAnchor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AJMJumpScareAnchor_Statics

// ********** Begin Class AJMJumpScareAnchor Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMJumpScareAnchor_Statics::NewProp_SceneRoot = { "SceneRoot", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMJumpScareAnchor, SceneRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneRoot_MetaData), NewProp_SceneRoot_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AJMJumpScareAnchor_Statics::NewProp_AnchorId = { "AnchorId", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMJumpScareAnchor, AnchorId), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnchorId_MetaData), NewProp_AnchorId_MetaData) }; // 517357616
void Z_Construct_UClass_AJMJumpScareAnchor_Statics::NewProp_bOverrideRotation_SetBit(void* Obj)
{
	((AJMJumpScareAnchor*)Obj)->bOverrideRotation = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AJMJumpScareAnchor_Statics::NewProp_bOverrideRotation = { "bOverrideRotation", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AJMJumpScareAnchor), &Z_Construct_UClass_AJMJumpScareAnchor_Statics::NewProp_bOverrideRotation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideRotation_MetaData), NewProp_bOverrideRotation_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AJMJumpScareAnchor_Statics::NewProp_RotationOverride = { "RotationOverride", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMJumpScareAnchor, RotationOverride), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotationOverride_MetaData), NewProp_RotationOverride_MetaData) };
#if WITH_EDITORONLY_DATA
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMJumpScareAnchor_Statics::NewProp_DirectionArrow = { "DirectionArrow", nullptr, (EPropertyFlags)0x01140008000a0009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMJumpScareAnchor, DirectionArrow), Z_Construct_UClass_UArrowComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DirectionArrow_MetaData), NewProp_DirectionArrow_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMJumpScareAnchor_Statics::NewProp_Billboard = { "Billboard", nullptr, (EPropertyFlags)0x01140008000a0009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMJumpScareAnchor, Billboard), Z_Construct_UClass_UBillboardComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Billboard_MetaData), NewProp_Billboard_MetaData) };
#endif // WITH_EDITORONLY_DATA
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AJMJumpScareAnchor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMJumpScareAnchor_Statics::NewProp_SceneRoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMJumpScareAnchor_Statics::NewProp_AnchorId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMJumpScareAnchor_Statics::NewProp_bOverrideRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMJumpScareAnchor_Statics::NewProp_RotationOverride,
#if WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMJumpScareAnchor_Statics::NewProp_DirectionArrow,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMJumpScareAnchor_Statics::NewProp_Billboard,
#endif // WITH_EDITORONLY_DATA
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AJMJumpScareAnchor_Statics::PropPointers) < 2048);
// ********** End Class AJMJumpScareAnchor Property Definitions ************************************
UObject* (*const Z_Construct_UClass_AJMJumpScareAnchor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_JMJumpScare,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AJMJumpScareAnchor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AJMJumpScareAnchor_Statics::ClassParams = {
	&AJMJumpScareAnchor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AJMJumpScareAnchor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AJMJumpScareAnchor_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AJMJumpScareAnchor_Statics::Class_MetaDataParams), Z_Construct_UClass_AJMJumpScareAnchor_Statics::Class_MetaDataParams)
};
void AJMJumpScareAnchor::StaticRegisterNativesAJMJumpScareAnchor()
{
	UClass* Class = AJMJumpScareAnchor::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AJMJumpScareAnchor_Statics::Funcs));
}
UClass* Z_Construct_UClass_AJMJumpScareAnchor()
{
	if (!Z_Registration_Info_UClass_AJMJumpScareAnchor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AJMJumpScareAnchor.OuterSingleton, Z_Construct_UClass_AJMJumpScareAnchor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AJMJumpScareAnchor.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AJMJumpScareAnchor);
AJMJumpScareAnchor::~AJMJumpScareAnchor() {}
// ********** End Class AJMJumpScareAnchor *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Actors_JMJumpScareAnchor_h__Script_JMJumpScare_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AJMJumpScareAnchor, AJMJumpScareAnchor::StaticClass, TEXT("AJMJumpScareAnchor"), &Z_Registration_Info_UClass_AJMJumpScareAnchor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AJMJumpScareAnchor), 209970740U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Actors_JMJumpScareAnchor_h__Script_JMJumpScare_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Actors_JMJumpScareAnchor_h__Script_JMJumpScare_3146886086{
	TEXT("/Script/JMJumpScare"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Actors_JMJumpScareAnchor_h__Script_JMJumpScare_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Actors_JMJumpScareAnchor_h__Script_JMJumpScare_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
