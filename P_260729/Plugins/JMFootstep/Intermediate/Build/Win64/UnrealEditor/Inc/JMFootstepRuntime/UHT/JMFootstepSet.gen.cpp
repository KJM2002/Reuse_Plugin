// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Data/JMFootstepSet.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMFootstepSet() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
JMFOOTSTEPRUNTIME_API UClass* Z_Construct_UClass_UJMFootstepSet();
JMFOOTSTEPRUNTIME_API UClass* Z_Construct_UClass_UJMFootstepSet_NoRegister();
JMFOOTSTEPRUNTIME_API UClass* Z_Construct_UClass_UJMFootstepSurfaceProfile_NoRegister();
JMFOOTSTEPRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMFootstepSurfaceEntry();
PHYSICSCORE_API UEnum* Z_Construct_UEnum_PhysicsCore_EPhysicalSurface();
UPackage* Z_Construct_UPackage__Script_JMFootstepRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FJMFootstepSurfaceEntry *******************************************
struct Z_Construct_UScriptStruct_FJMFootstepSurfaceEntry_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMFootstepSurfaceEntry); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMFootstepSurfaceEntry); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Data/JMFootstepSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SurfaceType_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ModuleRelativePath", "Public/Data/JMFootstepSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Profile_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ModuleRelativePath", "Public/Data/JMFootstepSet.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMFootstepSurfaceEntry constinit property declarations ***********
	static const UECodeGen_Private::FBytePropertyParams NewProp_SurfaceType;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Profile;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMFootstepSurfaceEntry constinit property declarations *************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMFootstepSurfaceEntry>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMFootstepSurfaceEntry_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMFootstepSurfaceEntry;
class UScriptStruct* FJMFootstepSurfaceEntry::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMFootstepSurfaceEntry.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMFootstepSurfaceEntry.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMFootstepSurfaceEntry, (UObject*)Z_Construct_UPackage__Script_JMFootstepRuntime(), TEXT("JMFootstepSurfaceEntry"));
	}
	return Z_Registration_Info_UScriptStruct_FJMFootstepSurfaceEntry.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMFootstepSurfaceEntry Property Definitions **********************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMFootstepSurfaceEntry_Statics::NewProp_SurfaceType = { "SurfaceType", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepSurfaceEntry, SurfaceType), Z_Construct_UEnum_PhysicsCore_EPhysicalSurface, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SurfaceType_MetaData), NewProp_SurfaceType_MetaData) }; // 2774282401
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMFootstepSurfaceEntry_Statics::NewProp_Profile = { "Profile", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMFootstepSurfaceEntry, Profile), Z_Construct_UClass_UJMFootstepSurfaceProfile_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Profile_MetaData), NewProp_Profile_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMFootstepSurfaceEntry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepSurfaceEntry_Statics::NewProp_SurfaceType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMFootstepSurfaceEntry_Statics::NewProp_Profile,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMFootstepSurfaceEntry_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMFootstepSurfaceEntry Property Definitions ************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMFootstepSurfaceEntry_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMFootstepRuntime,
	nullptr,
	&NewStructOps,
	"JMFootstepSurfaceEntry",
	Z_Construct_UScriptStruct_FJMFootstepSurfaceEntry_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMFootstepSurfaceEntry_Statics::PropPointers),
	sizeof(FJMFootstepSurfaceEntry),
	alignof(FJMFootstepSurfaceEntry),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMFootstepSurfaceEntry_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMFootstepSurfaceEntry_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMFootstepSurfaceEntry()
{
	if (!Z_Registration_Info_UScriptStruct_FJMFootstepSurfaceEntry.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMFootstepSurfaceEntry.InnerSingleton, Z_Construct_UScriptStruct_FJMFootstepSurfaceEntry_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMFootstepSurfaceEntry.InnerSingleton);
}
// ********** End ScriptStruct FJMFootstepSurfaceEntry *********************************************

// ********** Begin Class UJMFootstepSet Function FindProfile **************************************
struct Z_Construct_UFunction_UJMFootstepSet_FindProfile_Statics
{
	struct JMFootstepSet_eventFindProfile_Parms
	{
		TEnumAsByte<EPhysicalSurface> SurfaceType;
		bool bUsedFallback;
		UJMFootstepSurfaceProfile* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Footstep" },
		{ "ModuleRelativePath", "Public/Data/JMFootstepSet.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function FindProfile constinit property declarations ***************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_SurfaceType;
	static void NewProp_bUsedFallback_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUsedFallback;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FindProfile constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FindProfile Property Definitions **************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMFootstepSet_FindProfile_Statics::NewProp_SurfaceType = { "SurfaceType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMFootstepSet_eventFindProfile_Parms, SurfaceType), Z_Construct_UEnum_PhysicsCore_EPhysicalSurface, METADATA_PARAMS(0, nullptr) }; // 2774282401
void Z_Construct_UFunction_UJMFootstepSet_FindProfile_Statics::NewProp_bUsedFallback_SetBit(void* Obj)
{
	((JMFootstepSet_eventFindProfile_Parms*)Obj)->bUsedFallback = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMFootstepSet_FindProfile_Statics::NewProp_bUsedFallback = { "bUsedFallback", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMFootstepSet_eventFindProfile_Parms), &Z_Construct_UFunction_UJMFootstepSet_FindProfile_Statics::NewProp_bUsedFallback_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMFootstepSet_FindProfile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMFootstepSet_eventFindProfile_Parms, ReturnValue), Z_Construct_UClass_UJMFootstepSurfaceProfile_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMFootstepSet_FindProfile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMFootstepSet_FindProfile_Statics::NewProp_SurfaceType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMFootstepSet_FindProfile_Statics::NewProp_bUsedFallback,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMFootstepSet_FindProfile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepSet_FindProfile_Statics::PropPointers) < 2048);
// ********** End Function FindProfile Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMFootstepSet_FindProfile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMFootstepSet, nullptr, "FindProfile", 	Z_Construct_UFunction_UJMFootstepSet_FindProfile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepSet_FindProfile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMFootstepSet_FindProfile_Statics::JMFootstepSet_eventFindProfile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMFootstepSet_FindProfile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMFootstepSet_FindProfile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMFootstepSet_FindProfile_Statics::JMFootstepSet_eventFindProfile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMFootstepSet_FindProfile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMFootstepSet_FindProfile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMFootstepSet::execFindProfile)
{
	P_GET_PROPERTY(FByteProperty,Z_Param_SurfaceType);
	P_GET_UBOOL_REF(Z_Param_Out_bUsedFallback);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UJMFootstepSurfaceProfile**)Z_Param__Result=P_THIS->FindProfile(EPhysicalSurface(Z_Param_SurfaceType),Z_Param_Out_bUsedFallback);
	P_NATIVE_END;
}
// ********** End Class UJMFootstepSet Function FindProfile ****************************************

// ********** Begin Class UJMFootstepSet ***********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMFootstepSet;
UClass* UJMFootstepSet::GetPrivateStaticClass()
{
	using TClass = UJMFootstepSet;
	if (!Z_Registration_Info_UClass_UJMFootstepSet.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMFootstepSet"),
			Z_Registration_Info_UClass_UJMFootstepSet.InnerSingleton,
			StaticRegisterNativesUJMFootstepSet,
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
	return Z_Registration_Info_UClass_UJMFootstepSet.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMFootstepSet_NoRegister()
{
	return UJMFootstepSet::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMFootstepSet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Data/JMFootstepSet.h" },
		{ "ModuleRelativePath", "Public/Data/JMFootstepSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultProfile_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ModuleRelativePath", "Public/Data/JMFootstepSet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SurfaceProfiles_MetaData[] = {
		{ "Category", "Footstep" },
		{ "ModuleRelativePath", "Public/Data/JMFootstepSet.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMFootstepSet constinit property declarations ***************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultProfile;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SurfaceProfiles_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SurfaceProfiles;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMFootstepSet constinit property declarations *****************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("FindProfile"), .Pointer = &UJMFootstepSet::execFindProfile },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMFootstepSet_FindProfile, "FindProfile" }, // 4089505448
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMFootstepSet>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMFootstepSet_Statics

// ********** Begin Class UJMFootstepSet Property Definitions **************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMFootstepSet_Statics::NewProp_DefaultProfile = { "DefaultProfile", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSet, DefaultProfile), Z_Construct_UClass_UJMFootstepSurfaceProfile_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultProfile_MetaData), NewProp_DefaultProfile_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMFootstepSet_Statics::NewProp_SurfaceProfiles_Inner = { "SurfaceProfiles", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FJMFootstepSurfaceEntry, METADATA_PARAMS(0, nullptr) }; // 1132927085
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UJMFootstepSet_Statics::NewProp_SurfaceProfiles = { "SurfaceProfiles", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMFootstepSet, SurfaceProfiles), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SurfaceProfiles_MetaData), NewProp_SurfaceProfiles_MetaData) }; // 1132927085
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMFootstepSet_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSet_Statics::NewProp_DefaultProfile,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSet_Statics::NewProp_SurfaceProfiles_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMFootstepSet_Statics::NewProp_SurfaceProfiles,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMFootstepSet_Statics::PropPointers) < 2048);
// ********** End Class UJMFootstepSet Property Definitions ****************************************
UObject* (*const Z_Construct_UClass_UJMFootstepSet_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_JMFootstepRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMFootstepSet_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMFootstepSet_Statics::ClassParams = {
	&UJMFootstepSet::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMFootstepSet_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMFootstepSet_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMFootstepSet_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMFootstepSet_Statics::Class_MetaDataParams)
};
void UJMFootstepSet::StaticRegisterNativesUJMFootstepSet()
{
	UClass* Class = UJMFootstepSet::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMFootstepSet_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMFootstepSet()
{
	if (!Z_Registration_Info_UClass_UJMFootstepSet.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMFootstepSet.OuterSingleton, Z_Construct_UClass_UJMFootstepSet_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMFootstepSet.OuterSingleton;
}
UJMFootstepSet::UJMFootstepSet(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMFootstepSet);
UJMFootstepSet::~UJMFootstepSet() {}
// ********** End Class UJMFootstepSet *************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSet_h__Script_JMFootstepRuntime_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FJMFootstepSurfaceEntry::StaticStruct, Z_Construct_UScriptStruct_FJMFootstepSurfaceEntry_Statics::NewStructOps, TEXT("JMFootstepSurfaceEntry"),&Z_Registration_Info_UScriptStruct_FJMFootstepSurfaceEntry, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMFootstepSurfaceEntry), 1132927085U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMFootstepSet, UJMFootstepSet::StaticClass, TEXT("UJMFootstepSet"), &Z_Registration_Info_UClass_UJMFootstepSet, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMFootstepSet), 498348691U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSet_h__Script_JMFootstepRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSet_h__Script_JMFootstepRuntime_16760176{
	TEXT("/Script/JMFootstepRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSet_h__Script_JMFootstepRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSet_h__Script_JMFootstepRuntime_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSet_h__Script_JMFootstepRuntime_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMFootstep_Source_JMFootstepRuntime_Public_Data_JMFootstepSet_h__Script_JMFootstepRuntime_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
