// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Types/JMGameplayEventTypes.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMGameplayEventTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
JMGAMEPLAYEVENT_API UEnum* Z_Construct_UEnum_JMGameplayEvent_EJMGameplayEventMatchType();
JMGAMEPLAYEVENT_API UFunction* Z_Construct_UDelegateFunction_JMGameplayEvent_JMGameplayEventDynamicDelegate__DelegateSignature();
JMGAMEPLAYEVENT_API UScriptStruct* Z_Construct_UScriptStruct_FJMGameplayEventMessage();
JMGAMEPLAYEVENT_API UScriptStruct* Z_Construct_UScriptStruct_FJMGameplayEventSubscriptionHandle();
UPackage* Z_Construct_UPackage__Script_JMGameplayEvent();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EJMGameplayEventMatchType *************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMGameplayEventMatchType;
static UEnum* EJMGameplayEventMatchType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMGameplayEventMatchType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMGameplayEventMatchType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMGameplayEvent_EJMGameplayEventMatchType, (UObject*)Z_Construct_UPackage__Script_JMGameplayEvent(), TEXT("EJMGameplayEventMatchType"));
	}
	return Z_Registration_Info_UEnum_EJMGameplayEventMatchType.OuterSingleton;
}
template<> JMGAMEPLAYEVENT_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMGameplayEventMatchType>()
{
	return EJMGameplayEventMatchType_StaticEnum();
}
struct Z_Construct_UEnum_JMGameplayEvent_EJMGameplayEventMatchType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Exact.DisplayName", "Exact Match" },
		{ "Exact.Name", "EJMGameplayEventMatchType::Exact" },
		{ "IncludeChildren.DisplayName", "Include Child Tags" },
		{ "IncludeChildren.Name", "EJMGameplayEventMatchType::IncludeChildren" },
		{ "ModuleRelativePath", "Public/Types/JMGameplayEventTypes.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMGameplayEventMatchType::Exact", (int64)EJMGameplayEventMatchType::Exact },
		{ "EJMGameplayEventMatchType::IncludeChildren", (int64)EJMGameplayEventMatchType::IncludeChildren },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMGameplayEvent_EJMGameplayEventMatchType_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMGameplayEvent_EJMGameplayEventMatchType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMGameplayEvent,
	nullptr,
	"EJMGameplayEventMatchType",
	"EJMGameplayEventMatchType",
	Z_Construct_UEnum_JMGameplayEvent_EJMGameplayEventMatchType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMGameplayEvent_EJMGameplayEventMatchType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMGameplayEvent_EJMGameplayEventMatchType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMGameplayEvent_EJMGameplayEventMatchType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMGameplayEvent_EJMGameplayEventMatchType()
{
	if (!Z_Registration_Info_UEnum_EJMGameplayEventMatchType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMGameplayEventMatchType.InnerSingleton, Z_Construct_UEnum_JMGameplayEvent_EJMGameplayEventMatchType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMGameplayEventMatchType.InnerSingleton;
}
// ********** End Enum EJMGameplayEventMatchType ***************************************************

// ********** Begin ScriptStruct FJMGameplayEventSubscriptionHandle ********************************
struct Z_Construct_UScriptStruct_FJMGameplayEventSubscriptionHandle_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMGameplayEventSubscriptionHandle); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMGameplayEventSubscriptionHandle); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMGameplayEventTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[] = {
		{ "Category", "JM Gameplay Event" },
		{ "ModuleRelativePath", "Public/Types/JMGameplayEventTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMGameplayEventSubscriptionHandle constinit property declarations 
	static const UECodeGen_Private::FStructPropertyParams NewProp_Id;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMGameplayEventSubscriptionHandle constinit property declarations **
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMGameplayEventSubscriptionHandle>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMGameplayEventSubscriptionHandle_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMGameplayEventSubscriptionHandle;
class UScriptStruct* FJMGameplayEventSubscriptionHandle::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMGameplayEventSubscriptionHandle.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMGameplayEventSubscriptionHandle.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMGameplayEventSubscriptionHandle, (UObject*)Z_Construct_UPackage__Script_JMGameplayEvent(), TEXT("JMGameplayEventSubscriptionHandle"));
	}
	return Z_Registration_Info_UScriptStruct_FJMGameplayEventSubscriptionHandle.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMGameplayEventSubscriptionHandle Property Definitions ***********
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMGameplayEventSubscriptionHandle_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMGameplayEventSubscriptionHandle, Id), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Id_MetaData), NewProp_Id_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMGameplayEventSubscriptionHandle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMGameplayEventSubscriptionHandle_Statics::NewProp_Id,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMGameplayEventSubscriptionHandle_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMGameplayEventSubscriptionHandle Property Definitions *************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMGameplayEventSubscriptionHandle_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMGameplayEvent,
	nullptr,
	&NewStructOps,
	"JMGameplayEventSubscriptionHandle",
	Z_Construct_UScriptStruct_FJMGameplayEventSubscriptionHandle_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMGameplayEventSubscriptionHandle_Statics::PropPointers),
	sizeof(FJMGameplayEventSubscriptionHandle),
	alignof(FJMGameplayEventSubscriptionHandle),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMGameplayEventSubscriptionHandle_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMGameplayEventSubscriptionHandle_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMGameplayEventSubscriptionHandle()
{
	if (!Z_Registration_Info_UScriptStruct_FJMGameplayEventSubscriptionHandle.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMGameplayEventSubscriptionHandle.InnerSingleton, Z_Construct_UScriptStruct_FJMGameplayEventSubscriptionHandle_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMGameplayEventSubscriptionHandle.InnerSingleton);
}
// ********** End ScriptStruct FJMGameplayEventSubscriptionHandle **********************************

// ********** Begin ScriptStruct FJMGameplayEventMessage *******************************************
struct Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMGameplayEventMessage); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMGameplayEventMessage); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Types/JMGameplayEventTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EventTag_MetaData[] = {
		{ "Category", "JM Gameplay Event" },
		{ "ModuleRelativePath", "Public/Types/JMGameplayEventTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Source_MetaData[] = {
		{ "Category", "JM Gameplay Event" },
		{ "ModuleRelativePath", "Public/Types/JMGameplayEventTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Instigator_MetaData[] = {
		{ "Category", "JM Gameplay Event" },
		{ "ModuleRelativePath", "Public/Types/JMGameplayEventTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[] = {
		{ "Category", "JM Gameplay Event" },
		{ "ModuleRelativePath", "Public/Types/JMGameplayEventTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContextTags_MetaData[] = {
		{ "Category", "JM Gameplay Event" },
		{ "ModuleRelativePath", "Public/Types/JMGameplayEventTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Payload_MetaData[] = {
		{ "Category", "JM Gameplay Event" },
		{ "ModuleRelativePath", "Public/Types/JMGameplayEventTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMGameplayEventMessage constinit property declarations ***********
	static const UECodeGen_Private::FStructPropertyParams NewProp_EventTag;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Source;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Instigator;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ContextTags;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Payload;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMGameplayEventMessage constinit property declarations *************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMGameplayEventMessage>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMGameplayEventMessage;
class UScriptStruct* FJMGameplayEventMessage::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMGameplayEventMessage.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMGameplayEventMessage.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMGameplayEventMessage, (UObject*)Z_Construct_UPackage__Script_JMGameplayEvent(), TEXT("JMGameplayEventMessage"));
	}
	return Z_Registration_Info_UScriptStruct_FJMGameplayEventMessage.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMGameplayEventMessage Property Definitions **********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics::NewProp_EventTag = { "EventTag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMGameplayEventMessage, EventTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EventTag_MetaData), NewProp_EventTag_MetaData) }; // 517357616
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics::NewProp_Source = { "Source", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMGameplayEventMessage, Source), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Source_MetaData), NewProp_Source_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMGameplayEventMessage, Instigator), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Instigator_MetaData), NewProp_Instigator_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMGameplayEventMessage, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Target_MetaData), NewProp_Target_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics::NewProp_ContextTags = { "ContextTags", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMGameplayEventMessage, ContextTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContextTags_MetaData), NewProp_ContextTags_MetaData) }; // 3438578166
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics::NewProp_Payload = { "Payload", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMGameplayEventMessage, Payload), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Payload_MetaData), NewProp_Payload_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics::NewProp_EventTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics::NewProp_Source,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics::NewProp_Instigator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics::NewProp_ContextTags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics::NewProp_Payload,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMGameplayEventMessage Property Definitions ************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMGameplayEvent,
	nullptr,
	&NewStructOps,
	"JMGameplayEventMessage",
	Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics::PropPointers),
	sizeof(FJMGameplayEventMessage),
	alignof(FJMGameplayEventMessage),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMGameplayEventMessage()
{
	if (!Z_Registration_Info_UScriptStruct_FJMGameplayEventMessage.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMGameplayEventMessage.InnerSingleton, Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMGameplayEventMessage.InnerSingleton);
}
// ********** End ScriptStruct FJMGameplayEventMessage *********************************************

// ********** Begin Delegate FJMGameplayEventDynamicDelegate ***************************************
struct Z_Construct_UDelegateFunction_JMGameplayEvent_JMGameplayEventDynamicDelegate__DelegateSignature_Statics
{
	struct _Script_JMGameplayEvent_eventJMGameplayEventDynamicDelegate_Parms
	{
		FJMGameplayEventMessage Message;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Types/JMGameplayEventTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMGameplayEventDynamicDelegate constinit property declarations *******
	static const UECodeGen_Private::FStructPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMGameplayEventDynamicDelegate constinit property declarations *********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMGameplayEventDynamicDelegate Property Definitions ******************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_JMGameplayEvent_JMGameplayEventDynamicDelegate__DelegateSignature_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMGameplayEvent_eventJMGameplayEventDynamicDelegate_Parms, Message), Z_Construct_UScriptStruct_FJMGameplayEventMessage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) }; // 638734400
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMGameplayEvent_JMGameplayEventDynamicDelegate__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMGameplayEvent_JMGameplayEventDynamicDelegate__DelegateSignature_Statics::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMGameplayEvent_JMGameplayEventDynamicDelegate__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMGameplayEventDynamicDelegate Property Definitions ********************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMGameplayEvent_JMGameplayEventDynamicDelegate__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMGameplayEvent, nullptr, "JMGameplayEventDynamicDelegate__DelegateSignature", 	Z_Construct_UDelegateFunction_JMGameplayEvent_JMGameplayEventDynamicDelegate__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMGameplayEvent_JMGameplayEventDynamicDelegate__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMGameplayEvent_JMGameplayEventDynamicDelegate__DelegateSignature_Statics::_Script_JMGameplayEvent_eventJMGameplayEventDynamicDelegate_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMGameplayEvent_JMGameplayEventDynamicDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMGameplayEvent_JMGameplayEventDynamicDelegate__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMGameplayEvent_JMGameplayEventDynamicDelegate__DelegateSignature_Statics::_Script_JMGameplayEvent_eventJMGameplayEventDynamicDelegate_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMGameplayEvent_JMGameplayEventDynamicDelegate__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMGameplayEvent_JMGameplayEventDynamicDelegate__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMGameplayEventDynamicDelegate_DelegateWrapper(const FMulticastScriptDelegate& JMGameplayEventDynamicDelegate, FJMGameplayEventMessage const& Message)
{
	struct _Script_JMGameplayEvent_eventJMGameplayEventDynamicDelegate_Parms
	{
		FJMGameplayEventMessage Message;
	};
	_Script_JMGameplayEvent_eventJMGameplayEventDynamicDelegate_Parms Parms;
	Parms.Message=Message;
	JMGameplayEventDynamicDelegate.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMGameplayEventDynamicDelegate *****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Types_JMGameplayEventTypes_h__Script_JMGameplayEvent_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EJMGameplayEventMatchType_StaticEnum, TEXT("EJMGameplayEventMatchType"), &Z_Registration_Info_UEnum_EJMGameplayEventMatchType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2796311245U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FJMGameplayEventSubscriptionHandle::StaticStruct, Z_Construct_UScriptStruct_FJMGameplayEventSubscriptionHandle_Statics::NewStructOps, TEXT("JMGameplayEventSubscriptionHandle"),&Z_Registration_Info_UScriptStruct_FJMGameplayEventSubscriptionHandle, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMGameplayEventSubscriptionHandle), 2850831731U) },
		{ FJMGameplayEventMessage::StaticStruct, Z_Construct_UScriptStruct_FJMGameplayEventMessage_Statics::NewStructOps, TEXT("JMGameplayEventMessage"),&Z_Registration_Info_UScriptStruct_FJMGameplayEventMessage, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMGameplayEventMessage), 638734400U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Types_JMGameplayEventTypes_h__Script_JMGameplayEvent_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Types_JMGameplayEventTypes_h__Script_JMGameplayEvent_280679427{
	TEXT("/Script/JMGameplayEvent"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Types_JMGameplayEventTypes_h__Script_JMGameplayEvent_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Types_JMGameplayEventTypes_h__Script_JMGameplayEvent_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Types_JMGameplayEventTypes_h__Script_JMGameplayEvent_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Types_JMGameplayEventTypes_h__Script_JMGameplayEvent_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
