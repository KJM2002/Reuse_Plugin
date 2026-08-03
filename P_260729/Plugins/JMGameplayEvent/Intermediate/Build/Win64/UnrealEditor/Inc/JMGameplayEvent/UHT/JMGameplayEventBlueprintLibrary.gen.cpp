// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Blueprint/JMGameplayEventBlueprintLibrary.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMGameplayEventBlueprintLibrary() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventBlueprintLibrary();
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventBlueprintLibrary_NoRegister();
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMGameplayEvent();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMGameplayEventBlueprintLibrary Function GetGameplayEventSubsystem ******
struct Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_GetGameplayEventSubsystem_Statics
{
	struct JMGameplayEventBlueprintLibrary_eventGetGameplayEventSubsystem_Parms
	{
		const UObject* WorldContextObject;
		UJMGameplayEventSubsystem* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay Event" },
		{ "ModuleRelativePath", "Public/Blueprint/JMGameplayEventBlueprintLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetGameplayEventSubsystem constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGameplayEventSubsystem constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGameplayEventSubsystem Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_GetGameplayEventSubsystem_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMGameplayEventBlueprintLibrary_eventGetGameplayEventSubsystem_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_GetGameplayEventSubsystem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMGameplayEventBlueprintLibrary_eventGetGameplayEventSubsystem_Parms, ReturnValue), Z_Construct_UClass_UJMGameplayEventSubsystem_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_GetGameplayEventSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_GetGameplayEventSubsystem_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_GetGameplayEventSubsystem_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_GetGameplayEventSubsystem_Statics::PropPointers) < 2048);
// ********** End Function GetGameplayEventSubsystem Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_GetGameplayEventSubsystem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMGameplayEventBlueprintLibrary, nullptr, "GetGameplayEventSubsystem", 	Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_GetGameplayEventSubsystem_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_GetGameplayEventSubsystem_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_GetGameplayEventSubsystem_Statics::JMGameplayEventBlueprintLibrary_eventGetGameplayEventSubsystem_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_GetGameplayEventSubsystem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_GetGameplayEventSubsystem_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_GetGameplayEventSubsystem_Statics::JMGameplayEventBlueprintLibrary_eventGetGameplayEventSubsystem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_GetGameplayEventSubsystem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_GetGameplayEventSubsystem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMGameplayEventBlueprintLibrary::execGetGameplayEventSubsystem)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UJMGameplayEventSubsystem**)Z_Param__Result=UJMGameplayEventBlueprintLibrary::GetGameplayEventSubsystem(Z_Param_WorldContextObject);
	P_NATIVE_END;
}
// ********** End Class UJMGameplayEventBlueprintLibrary Function GetGameplayEventSubsystem ********

// ********** Begin Class UJMGameplayEventBlueprintLibrary Function PublishGameplayEvent ***********
struct Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics
{
	struct JMGameplayEventBlueprintLibrary_eventPublishGameplayEvent_Parms
	{
		const UObject* WorldContextObject;
		FGameplayTag EventTag;
		UObject* Source;
		AActor* Instigator;
		UObject* Target;
		FGameplayTagContainer ContextTags;
		UObject* Payload;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay Event" },
		{ "DisplayName", "Publish Gameplay Event" },
		{ "ModuleRelativePath", "Public/Blueprint/JMGameplayEventBlueprintLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function PublishGameplayEvent constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EventTag;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Source;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Instigator;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ContextTags;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Payload;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function PublishGameplayEvent constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function PublishGameplayEvent Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMGameplayEventBlueprintLibrary_eventPublishGameplayEvent_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::NewProp_EventTag = { "EventTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMGameplayEventBlueprintLibrary_eventPublishGameplayEvent_Parms, EventTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::NewProp_Source = { "Source", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMGameplayEventBlueprintLibrary_eventPublishGameplayEvent_Parms, Source), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMGameplayEventBlueprintLibrary_eventPublishGameplayEvent_Parms, Instigator), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMGameplayEventBlueprintLibrary_eventPublishGameplayEvent_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::NewProp_ContextTags = { "ContextTags", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMGameplayEventBlueprintLibrary_eventPublishGameplayEvent_Parms, ContextTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(0, nullptr) }; // 3438578166
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::NewProp_Payload = { "Payload", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMGameplayEventBlueprintLibrary_eventPublishGameplayEvent_Parms, Payload), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMGameplayEventBlueprintLibrary_eventPublishGameplayEvent_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::NewProp_EventTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::NewProp_Source,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::NewProp_Instigator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::NewProp_ContextTags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::NewProp_Payload,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::PropPointers) < 2048);
// ********** End Function PublishGameplayEvent Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMGameplayEventBlueprintLibrary, nullptr, "PublishGameplayEvent", 	Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::JMGameplayEventBlueprintLibrary_eventPublishGameplayEvent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::JMGameplayEventBlueprintLibrary_eventPublishGameplayEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMGameplayEventBlueprintLibrary::execPublishGameplayEvent)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_STRUCT(FGameplayTag,Z_Param_EventTag);
	P_GET_OBJECT(UObject,Z_Param_Source);
	P_GET_OBJECT(AActor,Z_Param_Instigator);
	P_GET_OBJECT(UObject,Z_Param_Target);
	P_GET_STRUCT(FGameplayTagContainer,Z_Param_ContextTags);
	P_GET_OBJECT(UObject,Z_Param_Payload);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UJMGameplayEventBlueprintLibrary::PublishGameplayEvent(Z_Param_WorldContextObject,Z_Param_EventTag,Z_Param_Source,Z_Param_Instigator,Z_Param_Target,Z_Param_ContextTags,Z_Param_Payload);
	P_NATIVE_END;
}
// ********** End Class UJMGameplayEventBlueprintLibrary Function PublishGameplayEvent *************

// ********** Begin Class UJMGameplayEventBlueprintLibrary *****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMGameplayEventBlueprintLibrary;
UClass* UJMGameplayEventBlueprintLibrary::GetPrivateStaticClass()
{
	using TClass = UJMGameplayEventBlueprintLibrary;
	if (!Z_Registration_Info_UClass_UJMGameplayEventBlueprintLibrary.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMGameplayEventBlueprintLibrary"),
			Z_Registration_Info_UClass_UJMGameplayEventBlueprintLibrary.InnerSingleton,
			StaticRegisterNativesUJMGameplayEventBlueprintLibrary,
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
	return Z_Registration_Info_UClass_UJMGameplayEventBlueprintLibrary.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMGameplayEventBlueprintLibrary_NoRegister()
{
	return UJMGameplayEventBlueprintLibrary::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMGameplayEventBlueprintLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Blueprint/JMGameplayEventBlueprintLibrary.h" },
		{ "ModuleRelativePath", "Public/Blueprint/JMGameplayEventBlueprintLibrary.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMGameplayEventBlueprintLibrary constinit property declarations *********
// ********** End Class UJMGameplayEventBlueprintLibrary constinit property declarations ***********
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetGameplayEventSubsystem"), .Pointer = &UJMGameplayEventBlueprintLibrary::execGetGameplayEventSubsystem },
		{ .NameUTF8 = UTF8TEXT("PublishGameplayEvent"), .Pointer = &UJMGameplayEventBlueprintLibrary::execPublishGameplayEvent },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_GetGameplayEventSubsystem, "GetGameplayEventSubsystem" }, // 133584048
		{ &Z_Construct_UFunction_UJMGameplayEventBlueprintLibrary_PublishGameplayEvent, "PublishGameplayEvent" }, // 475150659
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMGameplayEventBlueprintLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMGameplayEventBlueprintLibrary_Statics
UObject* (*const Z_Construct_UClass_UJMGameplayEventBlueprintLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_JMGameplayEvent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMGameplayEventBlueprintLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMGameplayEventBlueprintLibrary_Statics::ClassParams = {
	&UJMGameplayEventBlueprintLibrary::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMGameplayEventBlueprintLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMGameplayEventBlueprintLibrary_Statics::Class_MetaDataParams)
};
void UJMGameplayEventBlueprintLibrary::StaticRegisterNativesUJMGameplayEventBlueprintLibrary()
{
	UClass* Class = UJMGameplayEventBlueprintLibrary::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMGameplayEventBlueprintLibrary_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMGameplayEventBlueprintLibrary()
{
	if (!Z_Registration_Info_UClass_UJMGameplayEventBlueprintLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMGameplayEventBlueprintLibrary.OuterSingleton, Z_Construct_UClass_UJMGameplayEventBlueprintLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMGameplayEventBlueprintLibrary.OuterSingleton;
}
UJMGameplayEventBlueprintLibrary::UJMGameplayEventBlueprintLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMGameplayEventBlueprintLibrary);
UJMGameplayEventBlueprintLibrary::~UJMGameplayEventBlueprintLibrary() {}
// ********** End Class UJMGameplayEventBlueprintLibrary *******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Blueprint_JMGameplayEventBlueprintLibrary_h__Script_JMGameplayEvent_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMGameplayEventBlueprintLibrary, UJMGameplayEventBlueprintLibrary::StaticClass, TEXT("UJMGameplayEventBlueprintLibrary"), &Z_Registration_Info_UClass_UJMGameplayEventBlueprintLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMGameplayEventBlueprintLibrary), 506816640U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Blueprint_JMGameplayEventBlueprintLibrary_h__Script_JMGameplayEvent_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Blueprint_JMGameplayEventBlueprintLibrary_h__Script_JMGameplayEvent_2113763528{
	TEXT("/Script/JMGameplayEvent"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Blueprint_JMGameplayEventBlueprintLibrary_h__Script_JMGameplayEvent_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Blueprint_JMGameplayEventBlueprintLibrary_h__Script_JMGameplayEvent_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
