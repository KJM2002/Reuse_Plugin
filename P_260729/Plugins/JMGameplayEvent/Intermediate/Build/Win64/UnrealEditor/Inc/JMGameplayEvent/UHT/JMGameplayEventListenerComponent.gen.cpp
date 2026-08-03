// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/JMGameplayEventListenerComponent.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMGameplayEventListenerComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventListenerComponent();
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventListenerComponent_NoRegister();
JMGAMEPLAYEVENT_API UEnum* Z_Construct_UEnum_JMGameplayEvent_EJMGameplayEventMatchType();
JMGAMEPLAYEVENT_API UFunction* Z_Construct_UDelegateFunction_JMGameplayEvent_JMGameplayEventDynamicDelegate__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_JMGameplayEvent();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMGameplayEventListenerComponent Function AddEventTag *******************
struct Z_Construct_UFunction_UJMGameplayEventListenerComponent_AddEventTag_Statics
{
	struct JMGameplayEventListenerComponent_eventAddEventTag_Parms
	{
		FGameplayTag EventTag;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay Event" },
		{ "ModuleRelativePath", "Public/Components/JMGameplayEventListenerComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddEventTag constinit property declarations ***************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_EventTag;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddEventTag constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddEventTag Property Definitions **************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMGameplayEventListenerComponent_AddEventTag_Statics::NewProp_EventTag = { "EventTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMGameplayEventListenerComponent_eventAddEventTag_Parms, EventTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UJMGameplayEventListenerComponent_AddEventTag_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMGameplayEventListenerComponent_eventAddEventTag_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMGameplayEventListenerComponent_AddEventTag_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMGameplayEventListenerComponent_eventAddEventTag_Parms), &Z_Construct_UFunction_UJMGameplayEventListenerComponent_AddEventTag_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMGameplayEventListenerComponent_AddEventTag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMGameplayEventListenerComponent_AddEventTag_Statics::NewProp_EventTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMGameplayEventListenerComponent_AddEventTag_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMGameplayEventListenerComponent_AddEventTag_Statics::PropPointers) < 2048);
// ********** End Function AddEventTag Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMGameplayEventListenerComponent_AddEventTag_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMGameplayEventListenerComponent, nullptr, "AddEventTag", 	Z_Construct_UFunction_UJMGameplayEventListenerComponent_AddEventTag_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMGameplayEventListenerComponent_AddEventTag_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMGameplayEventListenerComponent_AddEventTag_Statics::JMGameplayEventListenerComponent_eventAddEventTag_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMGameplayEventListenerComponent_AddEventTag_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMGameplayEventListenerComponent_AddEventTag_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMGameplayEventListenerComponent_AddEventTag_Statics::JMGameplayEventListenerComponent_eventAddEventTag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMGameplayEventListenerComponent_AddEventTag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMGameplayEventListenerComponent_AddEventTag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMGameplayEventListenerComponent::execAddEventTag)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_EventTag);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->AddEventTag(Z_Param_EventTag);
	P_NATIVE_END;
}
// ********** End Class UJMGameplayEventListenerComponent Function AddEventTag *********************

// ********** Begin Class UJMGameplayEventListenerComponent Function RefreshSubscriptions **********
struct Z_Construct_UFunction_UJMGameplayEventListenerComponent_RefreshSubscriptions_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay Event" },
		{ "ModuleRelativePath", "Public/Components/JMGameplayEventListenerComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshSubscriptions constinit property declarations ******************
// ********** End Function RefreshSubscriptions constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMGameplayEventListenerComponent_RefreshSubscriptions_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMGameplayEventListenerComponent, nullptr, "RefreshSubscriptions", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMGameplayEventListenerComponent_RefreshSubscriptions_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMGameplayEventListenerComponent_RefreshSubscriptions_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UJMGameplayEventListenerComponent_RefreshSubscriptions()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMGameplayEventListenerComponent_RefreshSubscriptions_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMGameplayEventListenerComponent::execRefreshSubscriptions)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshSubscriptions();
	P_NATIVE_END;
}
// ********** End Class UJMGameplayEventListenerComponent Function RefreshSubscriptions ************

// ********** Begin Class UJMGameplayEventListenerComponent Function RemoveEventTag ****************
struct Z_Construct_UFunction_UJMGameplayEventListenerComponent_RemoveEventTag_Statics
{
	struct JMGameplayEventListenerComponent_eventRemoveEventTag_Parms
	{
		FGameplayTag EventTag;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay Event" },
		{ "ModuleRelativePath", "Public/Components/JMGameplayEventListenerComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveEventTag constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_EventTag;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemoveEventTag constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemoveEventTag Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMGameplayEventListenerComponent_RemoveEventTag_Statics::NewProp_EventTag = { "EventTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMGameplayEventListenerComponent_eventRemoveEventTag_Parms, EventTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UJMGameplayEventListenerComponent_RemoveEventTag_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMGameplayEventListenerComponent_eventRemoveEventTag_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMGameplayEventListenerComponent_RemoveEventTag_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMGameplayEventListenerComponent_eventRemoveEventTag_Parms), &Z_Construct_UFunction_UJMGameplayEventListenerComponent_RemoveEventTag_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMGameplayEventListenerComponent_RemoveEventTag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMGameplayEventListenerComponent_RemoveEventTag_Statics::NewProp_EventTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMGameplayEventListenerComponent_RemoveEventTag_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMGameplayEventListenerComponent_RemoveEventTag_Statics::PropPointers) < 2048);
// ********** End Function RemoveEventTag Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMGameplayEventListenerComponent_RemoveEventTag_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMGameplayEventListenerComponent, nullptr, "RemoveEventTag", 	Z_Construct_UFunction_UJMGameplayEventListenerComponent_RemoveEventTag_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMGameplayEventListenerComponent_RemoveEventTag_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMGameplayEventListenerComponent_RemoveEventTag_Statics::JMGameplayEventListenerComponent_eventRemoveEventTag_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMGameplayEventListenerComponent_RemoveEventTag_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMGameplayEventListenerComponent_RemoveEventTag_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMGameplayEventListenerComponent_RemoveEventTag_Statics::JMGameplayEventListenerComponent_eventRemoveEventTag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMGameplayEventListenerComponent_RemoveEventTag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMGameplayEventListenerComponent_RemoveEventTag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMGameplayEventListenerComponent::execRemoveEventTag)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_EventTag);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->RemoveEventTag(Z_Param_EventTag);
	P_NATIVE_END;
}
// ********** End Class UJMGameplayEventListenerComponent Function RemoveEventTag ******************

// ********** Begin Class UJMGameplayEventListenerComponent Function UnsubscribeAll ****************
struct Z_Construct_UFunction_UJMGameplayEventListenerComponent_UnsubscribeAll_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay Event" },
		{ "ModuleRelativePath", "Public/Components/JMGameplayEventListenerComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function UnsubscribeAll constinit property declarations ************************
// ********** End Function UnsubscribeAll constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMGameplayEventListenerComponent_UnsubscribeAll_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMGameplayEventListenerComponent, nullptr, "UnsubscribeAll", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMGameplayEventListenerComponent_UnsubscribeAll_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMGameplayEventListenerComponent_UnsubscribeAll_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UJMGameplayEventListenerComponent_UnsubscribeAll()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMGameplayEventListenerComponent_UnsubscribeAll_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMGameplayEventListenerComponent::execUnsubscribeAll)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UnsubscribeAll();
	P_NATIVE_END;
}
// ********** End Class UJMGameplayEventListenerComponent Function UnsubscribeAll ******************

// ********** Begin Class UJMGameplayEventListenerComponent ****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMGameplayEventListenerComponent;
UClass* UJMGameplayEventListenerComponent::GetPrivateStaticClass()
{
	using TClass = UJMGameplayEventListenerComponent;
	if (!Z_Registration_Info_UClass_UJMGameplayEventListenerComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMGameplayEventListenerComponent"),
			Z_Registration_Info_UClass_UJMGameplayEventListenerComponent.InnerSingleton,
			StaticRegisterNativesUJMGameplayEventListenerComponent,
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
	return Z_Registration_Info_UClass_UJMGameplayEventListenerComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMGameplayEventListenerComponent_NoRegister()
{
	return UJMGameplayEventListenerComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JMGameplay" },
		{ "IncludePath", "Components/JMGameplayEventListenerComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Components/JMGameplayEventListenerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EventTags_MetaData[] = {
		{ "Category", "JM Gameplay Event" },
		{ "ModuleRelativePath", "Public/Components/JMGameplayEventListenerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MatchType_MetaData[] = {
		{ "Category", "JM Gameplay Event" },
		{ "ModuleRelativePath", "Public/Components/JMGameplayEventListenerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoSubscribe_MetaData[] = {
		{ "Category", "JM Gameplay Event" },
		{ "ModuleRelativePath", "Public/Components/JMGameplayEventListenerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDebugLog_MetaData[] = {
		{ "Category", "JM Gameplay Event" },
		{ "ModuleRelativePath", "Public/Components/JMGameplayEventListenerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnGameplayEventReceived_MetaData[] = {
		{ "Category", "JM Gameplay Event" },
		{ "ModuleRelativePath", "Public/Components/JMGameplayEventListenerComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMGameplayEventListenerComponent constinit property declarations ********
	static const UECodeGen_Private::FStructPropertyParams NewProp_EventTags;
	static const UECodeGen_Private::FBytePropertyParams NewProp_MatchType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_MatchType;
	static void NewProp_bAutoSubscribe_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoSubscribe;
	static void NewProp_bEnableDebugLog_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDebugLog;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnGameplayEventReceived;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMGameplayEventListenerComponent constinit property declarations **********
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddEventTag"), .Pointer = &UJMGameplayEventListenerComponent::execAddEventTag },
		{ .NameUTF8 = UTF8TEXT("RefreshSubscriptions"), .Pointer = &UJMGameplayEventListenerComponent::execRefreshSubscriptions },
		{ .NameUTF8 = UTF8TEXT("RemoveEventTag"), .Pointer = &UJMGameplayEventListenerComponent::execRemoveEventTag },
		{ .NameUTF8 = UTF8TEXT("UnsubscribeAll"), .Pointer = &UJMGameplayEventListenerComponent::execUnsubscribeAll },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMGameplayEventListenerComponent_AddEventTag, "AddEventTag" }, // 3822799610
		{ &Z_Construct_UFunction_UJMGameplayEventListenerComponent_RefreshSubscriptions, "RefreshSubscriptions" }, // 2194464193
		{ &Z_Construct_UFunction_UJMGameplayEventListenerComponent_RemoveEventTag, "RemoveEventTag" }, // 2267660631
		{ &Z_Construct_UFunction_UJMGameplayEventListenerComponent_UnsubscribeAll, "UnsubscribeAll" }, // 4250107854
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMGameplayEventListenerComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics

// ********** Begin Class UJMGameplayEventListenerComponent Property Definitions *******************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::NewProp_EventTags = { "EventTags", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMGameplayEventListenerComponent, EventTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EventTags_MetaData), NewProp_EventTags_MetaData) }; // 3438578166
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::NewProp_MatchType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::NewProp_MatchType = { "MatchType", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMGameplayEventListenerComponent, MatchType), Z_Construct_UEnum_JMGameplayEvent_EJMGameplayEventMatchType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MatchType_MetaData), NewProp_MatchType_MetaData) }; // 2796311245
void Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::NewProp_bAutoSubscribe_SetBit(void* Obj)
{
	((UJMGameplayEventListenerComponent*)Obj)->bAutoSubscribe = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::NewProp_bAutoSubscribe = { "bAutoSubscribe", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMGameplayEventListenerComponent), &Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::NewProp_bAutoSubscribe_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoSubscribe_MetaData), NewProp_bAutoSubscribe_MetaData) };
void Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::NewProp_bEnableDebugLog_SetBit(void* Obj)
{
	((UJMGameplayEventListenerComponent*)Obj)->bEnableDebugLog = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::NewProp_bEnableDebugLog = { "bEnableDebugLog", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMGameplayEventListenerComponent), &Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::NewProp_bEnableDebugLog_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDebugLog_MetaData), NewProp_bEnableDebugLog_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::NewProp_OnGameplayEventReceived = { "OnGameplayEventReceived", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMGameplayEventListenerComponent, OnGameplayEventReceived), Z_Construct_UDelegateFunction_JMGameplayEvent_JMGameplayEventDynamicDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnGameplayEventReceived_MetaData), NewProp_OnGameplayEventReceived_MetaData) }; // 2561327006
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::NewProp_EventTags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::NewProp_MatchType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::NewProp_MatchType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::NewProp_bAutoSubscribe,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::NewProp_bEnableDebugLog,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::NewProp_OnGameplayEventReceived,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::PropPointers) < 2048);
// ********** End Class UJMGameplayEventListenerComponent Property Definitions *********************
UObject* (*const Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMGameplayEvent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::ClassParams = {
	&UJMGameplayEventListenerComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::Class_MetaDataParams)
};
void UJMGameplayEventListenerComponent::StaticRegisterNativesUJMGameplayEventListenerComponent()
{
	UClass* Class = UJMGameplayEventListenerComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMGameplayEventListenerComponent()
{
	if (!Z_Registration_Info_UClass_UJMGameplayEventListenerComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMGameplayEventListenerComponent.OuterSingleton, Z_Construct_UClass_UJMGameplayEventListenerComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMGameplayEventListenerComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMGameplayEventListenerComponent);
UJMGameplayEventListenerComponent::~UJMGameplayEventListenerComponent() {}
// ********** End Class UJMGameplayEventListenerComponent ******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Components_JMGameplayEventListenerComponent_h__Script_JMGameplayEvent_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMGameplayEventListenerComponent, UJMGameplayEventListenerComponent::StaticClass, TEXT("UJMGameplayEventListenerComponent"), &Z_Registration_Info_UClass_UJMGameplayEventListenerComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMGameplayEventListenerComponent), 2325724801U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Components_JMGameplayEventListenerComponent_h__Script_JMGameplayEvent_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Components_JMGameplayEventListenerComponent_h__Script_JMGameplayEvent_289627368{
	TEXT("/Script/JMGameplayEvent"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Components_JMGameplayEventListenerComponent_h__Script_JMGameplayEvent_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Components_JMGameplayEventListenerComponent_h__Script_JMGameplayEvent_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
