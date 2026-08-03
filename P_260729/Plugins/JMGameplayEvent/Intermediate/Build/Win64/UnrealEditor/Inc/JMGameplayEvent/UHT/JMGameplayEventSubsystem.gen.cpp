// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Subsystems/JMGameplayEventSubsystem.h"
#include "Engine/GameInstance.h"
#include "Types/JMGameplayEventTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMGameplayEventSubsystem() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventSubsystem();
JMGAMEPLAYEVENT_API UClass* Z_Construct_UClass_UJMGameplayEventSubsystem_NoRegister();
JMGAMEPLAYEVENT_API UScriptStruct* Z_Construct_UScriptStruct_FJMGameplayEventMessage();
JMGAMEPLAYEVENT_API UScriptStruct* Z_Construct_UScriptStruct_FJMGameplayEventSubscriptionHandle();
UPackage* Z_Construct_UPackage__Script_JMGameplayEvent();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMGameplayEventSubsystem Function PublishEvent **************************
struct Z_Construct_UFunction_UJMGameplayEventSubsystem_PublishEvent_Statics
{
	struct JMGameplayEventSubsystem_eventPublishEvent_Parms
	{
		FJMGameplayEventMessage Message;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay Event" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Publishes synchronously and returns the number of listeners invoked. */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystems/JMGameplayEventSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Publishes synchronously and returns the number of listeners invoked." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function PublishEvent constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Message;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function PublishEvent constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function PublishEvent Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMGameplayEventSubsystem_PublishEvent_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMGameplayEventSubsystem_eventPublishEvent_Parms, Message), Z_Construct_UScriptStruct_FJMGameplayEventMessage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) }; // 638734400
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UJMGameplayEventSubsystem_PublishEvent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMGameplayEventSubsystem_eventPublishEvent_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMGameplayEventSubsystem_PublishEvent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMGameplayEventSubsystem_PublishEvent_Statics::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMGameplayEventSubsystem_PublishEvent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMGameplayEventSubsystem_PublishEvent_Statics::PropPointers) < 2048);
// ********** End Function PublishEvent Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMGameplayEventSubsystem_PublishEvent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMGameplayEventSubsystem, nullptr, "PublishEvent", 	Z_Construct_UFunction_UJMGameplayEventSubsystem_PublishEvent_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMGameplayEventSubsystem_PublishEvent_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMGameplayEventSubsystem_PublishEvent_Statics::JMGameplayEventSubsystem_eventPublishEvent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMGameplayEventSubsystem_PublishEvent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMGameplayEventSubsystem_PublishEvent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMGameplayEventSubsystem_PublishEvent_Statics::JMGameplayEventSubsystem_eventPublishEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMGameplayEventSubsystem_PublishEvent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMGameplayEventSubsystem_PublishEvent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMGameplayEventSubsystem::execPublishEvent)
{
	P_GET_STRUCT_REF(FJMGameplayEventMessage,Z_Param_Out_Message);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->PublishEvent(Z_Param_Out_Message);
	P_NATIVE_END;
}
// ********** End Class UJMGameplayEventSubsystem Function PublishEvent ****************************

// ********** Begin Class UJMGameplayEventSubsystem Function UnsubscribeAll ************************
struct Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeAll_Statics
{
	struct JMGameplayEventSubsystem_eventUnsubscribeAll_Parms
	{
		UObject* Listener;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay Event" },
		{ "ModuleRelativePath", "Public/Subsystems/JMGameplayEventSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function UnsubscribeAll constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Listener;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UnsubscribeAll constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UnsubscribeAll Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeAll_Statics::NewProp_Listener = { "Listener", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMGameplayEventSubsystem_eventUnsubscribeAll_Parms, Listener), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeAll_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMGameplayEventSubsystem_eventUnsubscribeAll_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeAll_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeAll_Statics::NewProp_Listener,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeAll_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeAll_Statics::PropPointers) < 2048);
// ********** End Function UnsubscribeAll Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeAll_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMGameplayEventSubsystem, nullptr, "UnsubscribeAll", 	Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeAll_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeAll_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeAll_Statics::JMGameplayEventSubsystem_eventUnsubscribeAll_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeAll_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeAll_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeAll_Statics::JMGameplayEventSubsystem_eventUnsubscribeAll_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeAll()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeAll_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMGameplayEventSubsystem::execUnsubscribeAll)
{
	P_GET_OBJECT(UObject,Z_Param_Listener);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->UnsubscribeAll(Z_Param_Listener);
	P_NATIVE_END;
}
// ********** End Class UJMGameplayEventSubsystem Function UnsubscribeAll **************************

// ********** Begin Class UJMGameplayEventSubsystem Function UnsubscribeEvent **********************
struct Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeEvent_Statics
{
	struct JMGameplayEventSubsystem_eventUnsubscribeEvent_Parms
	{
		FJMGameplayEventSubscriptionHandle Handle;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay Event" },
		{ "ModuleRelativePath", "Public/Subsystems/JMGameplayEventSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function UnsubscribeEvent constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Handle;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UnsubscribeEvent constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UnsubscribeEvent Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeEvent_Statics::NewProp_Handle = { "Handle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMGameplayEventSubsystem_eventUnsubscribeEvent_Parms, Handle), Z_Construct_UScriptStruct_FJMGameplayEventSubscriptionHandle, METADATA_PARAMS(0, nullptr) }; // 2850831731
void Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeEvent_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMGameplayEventSubsystem_eventUnsubscribeEvent_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeEvent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMGameplayEventSubsystem_eventUnsubscribeEvent_Parms), &Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeEvent_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeEvent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeEvent_Statics::NewProp_Handle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeEvent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeEvent_Statics::PropPointers) < 2048);
// ********** End Function UnsubscribeEvent Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeEvent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMGameplayEventSubsystem, nullptr, "UnsubscribeEvent", 	Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeEvent_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeEvent_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeEvent_Statics::JMGameplayEventSubsystem_eventUnsubscribeEvent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeEvent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeEvent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeEvent_Statics::JMGameplayEventSubsystem_eventUnsubscribeEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeEvent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeEvent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMGameplayEventSubsystem::execUnsubscribeEvent)
{
	P_GET_STRUCT(FJMGameplayEventSubscriptionHandle,Z_Param_Handle);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->UnsubscribeEvent(Z_Param_Handle);
	P_NATIVE_END;
}
// ********** End Class UJMGameplayEventSubsystem Function UnsubscribeEvent ************************

// ********** Begin Class UJMGameplayEventSubsystem ************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMGameplayEventSubsystem;
UClass* UJMGameplayEventSubsystem::GetPrivateStaticClass()
{
	using TClass = UJMGameplayEventSubsystem;
	if (!Z_Registration_Info_UClass_UJMGameplayEventSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMGameplayEventSubsystem"),
			Z_Registration_Info_UClass_UJMGameplayEventSubsystem.InnerSingleton,
			StaticRegisterNativesUJMGameplayEventSubsystem,
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
	return Z_Registration_Info_UClass_UJMGameplayEventSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMGameplayEventSubsystem_NoRegister()
{
	return UJMGameplayEventSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMGameplayEventSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Synchronous, game-thread-only, process-local gameplay event bus.\n * It intentionally performs no RPC or replication.\n */" },
#endif
		{ "IncludePath", "Subsystems/JMGameplayEventSubsystem.h" },
		{ "ModuleRelativePath", "Public/Subsystems/JMGameplayEventSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Synchronous, game-thread-only, process-local gameplay event bus.\nIt intentionally performs no RPC or replication." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UJMGameplayEventSubsystem constinit property declarations ****************
// ********** End Class UJMGameplayEventSubsystem constinit property declarations ******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("PublishEvent"), .Pointer = &UJMGameplayEventSubsystem::execPublishEvent },
		{ .NameUTF8 = UTF8TEXT("UnsubscribeAll"), .Pointer = &UJMGameplayEventSubsystem::execUnsubscribeAll },
		{ .NameUTF8 = UTF8TEXT("UnsubscribeEvent"), .Pointer = &UJMGameplayEventSubsystem::execUnsubscribeEvent },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMGameplayEventSubsystem_PublishEvent, "PublishEvent" }, // 3014304371
		{ &Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeAll, "UnsubscribeAll" }, // 1971049536
		{ &Z_Construct_UFunction_UJMGameplayEventSubsystem_UnsubscribeEvent, "UnsubscribeEvent" }, // 3646998791
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMGameplayEventSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMGameplayEventSubsystem_Statics
UObject* (*const Z_Construct_UClass_UJMGameplayEventSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_JMGameplayEvent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMGameplayEventSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMGameplayEventSubsystem_Statics::ClassParams = {
	&UJMGameplayEventSubsystem::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMGameplayEventSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMGameplayEventSubsystem_Statics::Class_MetaDataParams)
};
void UJMGameplayEventSubsystem::StaticRegisterNativesUJMGameplayEventSubsystem()
{
	UClass* Class = UJMGameplayEventSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMGameplayEventSubsystem_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMGameplayEventSubsystem()
{
	if (!Z_Registration_Info_UClass_UJMGameplayEventSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMGameplayEventSubsystem.OuterSingleton, Z_Construct_UClass_UJMGameplayEventSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMGameplayEventSubsystem.OuterSingleton;
}
UJMGameplayEventSubsystem::UJMGameplayEventSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMGameplayEventSubsystem);
UJMGameplayEventSubsystem::~UJMGameplayEventSubsystem() {}
// ********** End Class UJMGameplayEventSubsystem **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Subsystems_JMGameplayEventSubsystem_h__Script_JMGameplayEvent_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMGameplayEventSubsystem, UJMGameplayEventSubsystem::StaticClass, TEXT("UJMGameplayEventSubsystem"), &Z_Registration_Info_UClass_UJMGameplayEventSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMGameplayEventSubsystem), 3394862254U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Subsystems_JMGameplayEventSubsystem_h__Script_JMGameplayEvent_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Subsystems_JMGameplayEventSubsystem_h__Script_JMGameplayEvent_3645710271{
	TEXT("/Script/JMGameplayEvent"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Subsystems_JMGameplayEventSubsystem_h__Script_JMGameplayEvent_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMGameplayEvent_Source_JMGameplayEvent_Public_Subsystems_JMGameplayEventSubsystem_h__Script_JMGameplayEvent_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
