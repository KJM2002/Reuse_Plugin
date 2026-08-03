// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Blueprint/JMDoorBlueprintLibrary.h"
#include "Door/JMDoorTypes.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMDoorBlueprintLibrary() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorBlueprintLibrary();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorBlueprintLibrary_NoRegister();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorCommand();
JMDOORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMDoorResult();
JMDOORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMDoorUseContext();
UPackage* Z_Construct_UPackage__Script_JMDoorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMDoorBlueprintLibrary Function ExecuteDoorCommandOnObject **************
struct Z_Construct_UFunction_UJMDoorBlueprintLibrary_ExecuteDoorCommandOnObject_Statics
{
	struct JMDoorBlueprintLibrary_eventExecuteDoorCommandOnObject_Parms
	{
		UObject* DoorObject;
		EJMDoorCommand Command;
		FJMDoorUseContext Context;
		FJMDoorResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door" },
		{ "ModuleRelativePath", "Public/Blueprint/JMDoorBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ExecuteDoorCommandOnObject constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DoorObject;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Command_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Command;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ExecuteDoorCommandOnObject constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ExecuteDoorCommandOnObject Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMDoorBlueprintLibrary_ExecuteDoorCommandOnObject_Statics::NewProp_DoorObject = { "DoorObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorBlueprintLibrary_eventExecuteDoorCommandOnObject_Parms, DoorObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMDoorBlueprintLibrary_ExecuteDoorCommandOnObject_Statics::NewProp_Command_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMDoorBlueprintLibrary_ExecuteDoorCommandOnObject_Statics::NewProp_Command = { "Command", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorBlueprintLibrary_eventExecuteDoorCommandOnObject_Parms, Command), Z_Construct_UEnum_JMDoorRuntime_EJMDoorCommand, METADATA_PARAMS(0, nullptr) }; // 4018727221
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorBlueprintLibrary_ExecuteDoorCommandOnObject_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorBlueprintLibrary_eventExecuteDoorCommandOnObject_Parms, Context), Z_Construct_UScriptStruct_FJMDoorUseContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3552665729
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorBlueprintLibrary_ExecuteDoorCommandOnObject_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorBlueprintLibrary_eventExecuteDoorCommandOnObject_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMDoorResult, METADATA_PARAMS(0, nullptr) }; // 1639184842
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorBlueprintLibrary_ExecuteDoorCommandOnObject_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorBlueprintLibrary_ExecuteDoorCommandOnObject_Statics::NewProp_DoorObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorBlueprintLibrary_ExecuteDoorCommandOnObject_Statics::NewProp_Command_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorBlueprintLibrary_ExecuteDoorCommandOnObject_Statics::NewProp_Command,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorBlueprintLibrary_ExecuteDoorCommandOnObject_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorBlueprintLibrary_ExecuteDoorCommandOnObject_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorBlueprintLibrary_ExecuteDoorCommandOnObject_Statics::PropPointers) < 2048);
// ********** End Function ExecuteDoorCommandOnObject Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorBlueprintLibrary_ExecuteDoorCommandOnObject_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorBlueprintLibrary, nullptr, "ExecuteDoorCommandOnObject", 	Z_Construct_UFunction_UJMDoorBlueprintLibrary_ExecuteDoorCommandOnObject_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorBlueprintLibrary_ExecuteDoorCommandOnObject_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorBlueprintLibrary_ExecuteDoorCommandOnObject_Statics::JMDoorBlueprintLibrary_eventExecuteDoorCommandOnObject_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorBlueprintLibrary_ExecuteDoorCommandOnObject_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorBlueprintLibrary_ExecuteDoorCommandOnObject_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorBlueprintLibrary_ExecuteDoorCommandOnObject_Statics::JMDoorBlueprintLibrary_eventExecuteDoorCommandOnObject_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorBlueprintLibrary_ExecuteDoorCommandOnObject()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorBlueprintLibrary_ExecuteDoorCommandOnObject_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorBlueprintLibrary::execExecuteDoorCommandOnObject)
{
	P_GET_OBJECT(UObject,Z_Param_DoorObject);
	P_GET_ENUM(EJMDoorCommand,Z_Param_Command);
	P_GET_STRUCT_REF(FJMDoorUseContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMDoorResult*)Z_Param__Result=UJMDoorBlueprintLibrary::ExecuteDoorCommandOnObject(Z_Param_DoorObject,EJMDoorCommand(Z_Param_Command),Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Class UJMDoorBlueprintLibrary Function ExecuteDoorCommandOnObject ****************

// ********** Begin Class UJMDoorBlueprintLibrary Function MakeDoorUseContext **********************
struct Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics
{
	struct JMDoorBlueprintLibrary_eventMakeDoorUseContext_Parms
	{
		AActor* InstigatorActor;
		FVector InteractionLocation;
		FGameplayTagContainer AccessTags;
		bool bIsAI;
		bool bQuiet;
		bool bFast;
		float RequestedOpenFraction;
		FJMDoorUseContext ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door" },
		{ "CPP_Default_bFast", "false" },
		{ "CPP_Default_bIsAI", "false" },
		{ "CPP_Default_bQuiet", "false" },
		{ "CPP_Default_RequestedOpenFraction", "1.000000" },
		{ "ModuleRelativePath", "Public/Blueprint/JMDoorBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AccessTags_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function MakeDoorUseContext constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InstigatorActor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InteractionLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AccessTags;
	static void NewProp_bIsAI_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsAI;
	static void NewProp_bQuiet_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bQuiet;
	static void NewProp_bFast_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFast;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RequestedOpenFraction;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MakeDoorUseContext constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MakeDoorUseContext Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::NewProp_InstigatorActor = { "InstigatorActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorBlueprintLibrary_eventMakeDoorUseContext_Parms, InstigatorActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::NewProp_InteractionLocation = { "InteractionLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorBlueprintLibrary_eventMakeDoorUseContext_Parms, InteractionLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::NewProp_AccessTags = { "AccessTags", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorBlueprintLibrary_eventMakeDoorUseContext_Parms, AccessTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AccessTags_MetaData), NewProp_AccessTags_MetaData) }; // 3438578166
void Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::NewProp_bIsAI_SetBit(void* Obj)
{
	((JMDoorBlueprintLibrary_eventMakeDoorUseContext_Parms*)Obj)->bIsAI = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::NewProp_bIsAI = { "bIsAI", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMDoorBlueprintLibrary_eventMakeDoorUseContext_Parms), &Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::NewProp_bIsAI_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::NewProp_bQuiet_SetBit(void* Obj)
{
	((JMDoorBlueprintLibrary_eventMakeDoorUseContext_Parms*)Obj)->bQuiet = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::NewProp_bQuiet = { "bQuiet", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMDoorBlueprintLibrary_eventMakeDoorUseContext_Parms), &Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::NewProp_bQuiet_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::NewProp_bFast_SetBit(void* Obj)
{
	((JMDoorBlueprintLibrary_eventMakeDoorUseContext_Parms*)Obj)->bFast = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::NewProp_bFast = { "bFast", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMDoorBlueprintLibrary_eventMakeDoorUseContext_Parms), &Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::NewProp_bFast_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::NewProp_RequestedOpenFraction = { "RequestedOpenFraction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorBlueprintLibrary_eventMakeDoorUseContext_Parms, RequestedOpenFraction), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorBlueprintLibrary_eventMakeDoorUseContext_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMDoorUseContext, METADATA_PARAMS(0, nullptr) }; // 3552665729
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::NewProp_InstigatorActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::NewProp_InteractionLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::NewProp_AccessTags,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::NewProp_bIsAI,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::NewProp_bQuiet,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::NewProp_bFast,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::NewProp_RequestedOpenFraction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::PropPointers) < 2048);
// ********** End Function MakeDoorUseContext Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorBlueprintLibrary, nullptr, "MakeDoorUseContext", 	Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::JMDoorBlueprintLibrary_eventMakeDoorUseContext_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::JMDoorBlueprintLibrary_eventMakeDoorUseContext_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorBlueprintLibrary::execMakeDoorUseContext)
{
	P_GET_OBJECT(AActor,Z_Param_InstigatorActor);
	P_GET_STRUCT(FVector,Z_Param_InteractionLocation);
	P_GET_STRUCT_REF(FGameplayTagContainer,Z_Param_Out_AccessTags);
	P_GET_UBOOL(Z_Param_bIsAI);
	P_GET_UBOOL(Z_Param_bQuiet);
	P_GET_UBOOL(Z_Param_bFast);
	P_GET_PROPERTY(FFloatProperty,Z_Param_RequestedOpenFraction);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMDoorUseContext*)Z_Param__Result=UJMDoorBlueprintLibrary::MakeDoorUseContext(Z_Param_InstigatorActor,Z_Param_InteractionLocation,Z_Param_Out_AccessTags,Z_Param_bIsAI,Z_Param_bQuiet,Z_Param_bFast,Z_Param_RequestedOpenFraction);
	P_NATIVE_END;
}
// ********** End Class UJMDoorBlueprintLibrary Function MakeDoorUseContext ************************

// ********** Begin Class UJMDoorBlueprintLibrary **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMDoorBlueprintLibrary;
UClass* UJMDoorBlueprintLibrary::GetPrivateStaticClass()
{
	using TClass = UJMDoorBlueprintLibrary;
	if (!Z_Registration_Info_UClass_UJMDoorBlueprintLibrary.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMDoorBlueprintLibrary"),
			Z_Registration_Info_UClass_UJMDoorBlueprintLibrary.InnerSingleton,
			StaticRegisterNativesUJMDoorBlueprintLibrary,
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
	return Z_Registration_Info_UClass_UJMDoorBlueprintLibrary.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMDoorBlueprintLibrary_NoRegister()
{
	return UJMDoorBlueprintLibrary::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMDoorBlueprintLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Blueprint/JMDoorBlueprintLibrary.h" },
		{ "ModuleRelativePath", "Public/Blueprint/JMDoorBlueprintLibrary.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMDoorBlueprintLibrary constinit property declarations ******************
// ********** End Class UJMDoorBlueprintLibrary constinit property declarations ********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ExecuteDoorCommandOnObject"), .Pointer = &UJMDoorBlueprintLibrary::execExecuteDoorCommandOnObject },
		{ .NameUTF8 = UTF8TEXT("MakeDoorUseContext"), .Pointer = &UJMDoorBlueprintLibrary::execMakeDoorUseContext },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMDoorBlueprintLibrary_ExecuteDoorCommandOnObject, "ExecuteDoorCommandOnObject" }, // 2065542881
		{ &Z_Construct_UFunction_UJMDoorBlueprintLibrary_MakeDoorUseContext, "MakeDoorUseContext" }, // 1695771784
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMDoorBlueprintLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMDoorBlueprintLibrary_Statics
UObject* (*const Z_Construct_UClass_UJMDoorBlueprintLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorBlueprintLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMDoorBlueprintLibrary_Statics::ClassParams = {
	&UJMDoorBlueprintLibrary::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorBlueprintLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMDoorBlueprintLibrary_Statics::Class_MetaDataParams)
};
void UJMDoorBlueprintLibrary::StaticRegisterNativesUJMDoorBlueprintLibrary()
{
	UClass* Class = UJMDoorBlueprintLibrary::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMDoorBlueprintLibrary_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMDoorBlueprintLibrary()
{
	if (!Z_Registration_Info_UClass_UJMDoorBlueprintLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMDoorBlueprintLibrary.OuterSingleton, Z_Construct_UClass_UJMDoorBlueprintLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMDoorBlueprintLibrary.OuterSingleton;
}
UJMDoorBlueprintLibrary::UJMDoorBlueprintLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMDoorBlueprintLibrary);
UJMDoorBlueprintLibrary::~UJMDoorBlueprintLibrary() {}
// ********** End Class UJMDoorBlueprintLibrary ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Blueprint_JMDoorBlueprintLibrary_h__Script_JMDoorRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMDoorBlueprintLibrary, UJMDoorBlueprintLibrary::StaticClass, TEXT("UJMDoorBlueprintLibrary"), &Z_Registration_Info_UClass_UJMDoorBlueprintLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMDoorBlueprintLibrary), 3043602219U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Blueprint_JMDoorBlueprintLibrary_h__Script_JMDoorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Blueprint_JMDoorBlueprintLibrary_h__Script_JMDoorRuntime_2253762503{
	TEXT("/Script/JMDoorRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Blueprint_JMDoorBlueprintLibrary_h__Script_JMDoorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Blueprint_JMDoorBlueprintLibrary_h__Script_JMDoorRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
