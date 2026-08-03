// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Blueprint/JMJumpScareBlueprintLibrary.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMJumpScareBlueprintLibrary() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareBlueprintLibrary();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareBlueprintLibrary_NoRegister();
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareDefinition_NoRegister();
JMJUMPSCARE_API UEnum* Z_Construct_UEnum_JMJumpScare_EJMJumpScarePlayResult();
UPackage* Z_Construct_UPackage__Script_JMJumpScare();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMJumpScareBlueprintLibrary Function CancelJumpScare ********************
struct Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_CancelJumpScare_Statics
{
	struct JMJumpScareBlueprintLibrary_eventCancelJumpScare_Parms
	{
		UObject* WorldContextObject;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM JumpScare" },
		{ "DisplayName", "Cancel JumpScare" },
		{ "ModuleRelativePath", "Public/Blueprint/JMJumpScareBlueprintLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif // WITH_METADATA

// ********** Begin Function CancelJumpScare constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CancelJumpScare constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CancelJumpScare Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_CancelJumpScare_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMJumpScareBlueprintLibrary_eventCancelJumpScare_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_CancelJumpScare_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMJumpScareBlueprintLibrary_eventCancelJumpScare_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_CancelJumpScare_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMJumpScareBlueprintLibrary_eventCancelJumpScare_Parms), &Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_CancelJumpScare_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_CancelJumpScare_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_CancelJumpScare_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_CancelJumpScare_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_CancelJumpScare_Statics::PropPointers) < 2048);
// ********** End Function CancelJumpScare Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_CancelJumpScare_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMJumpScareBlueprintLibrary, nullptr, "CancelJumpScare", 	Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_CancelJumpScare_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_CancelJumpScare_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_CancelJumpScare_Statics::JMJumpScareBlueprintLibrary_eventCancelJumpScare_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_CancelJumpScare_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_CancelJumpScare_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_CancelJumpScare_Statics::JMJumpScareBlueprintLibrary_eventCancelJumpScare_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_CancelJumpScare()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_CancelJumpScare_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMJumpScareBlueprintLibrary::execCancelJumpScare)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UJMJumpScareBlueprintLibrary::CancelJumpScare(Z_Param_WorldContextObject);
	P_NATIVE_END;
}
// ********** End Class UJMJumpScareBlueprintLibrary Function CancelJumpScare **********************

// ********** Begin Class UJMJumpScareBlueprintLibrary Function IsJumpScarePlaying *****************
struct Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_IsJumpScarePlaying_Statics
{
	struct JMJumpScareBlueprintLibrary_eventIsJumpScarePlaying_Parms
	{
		UObject* WorldContextObject;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM JumpScare" },
		{ "DisplayName", "Is JumpScare Playing" },
		{ "ModuleRelativePath", "Public/Blueprint/JMJumpScareBlueprintLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsJumpScarePlaying constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsJumpScarePlaying constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsJumpScarePlaying Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_IsJumpScarePlaying_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMJumpScareBlueprintLibrary_eventIsJumpScarePlaying_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_IsJumpScarePlaying_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMJumpScareBlueprintLibrary_eventIsJumpScarePlaying_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_IsJumpScarePlaying_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMJumpScareBlueprintLibrary_eventIsJumpScarePlaying_Parms), &Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_IsJumpScarePlaying_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_IsJumpScarePlaying_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_IsJumpScarePlaying_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_IsJumpScarePlaying_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_IsJumpScarePlaying_Statics::PropPointers) < 2048);
// ********** End Function IsJumpScarePlaying Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_IsJumpScarePlaying_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMJumpScareBlueprintLibrary, nullptr, "IsJumpScarePlaying", 	Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_IsJumpScarePlaying_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_IsJumpScarePlaying_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_IsJumpScarePlaying_Statics::JMJumpScareBlueprintLibrary_eventIsJumpScarePlaying_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_IsJumpScarePlaying_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_IsJumpScarePlaying_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_IsJumpScarePlaying_Statics::JMJumpScareBlueprintLibrary_eventIsJumpScarePlaying_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_IsJumpScarePlaying()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_IsJumpScarePlaying_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMJumpScareBlueprintLibrary::execIsJumpScarePlaying)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UJMJumpScareBlueprintLibrary::IsJumpScarePlaying(Z_Param_WorldContextObject);
	P_NATIVE_END;
}
// ********** End Class UJMJumpScareBlueprintLibrary Function IsJumpScarePlaying *******************

// ********** Begin Class UJMJumpScareBlueprintLibrary Function PlayJumpScare **********************
struct Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_PlayJumpScare_Statics
{
	struct JMJumpScareBlueprintLibrary_eventPlayJumpScare_Parms
	{
		UObject* WorldContextObject;
		UJMJumpScareDefinition* Definition;
		APlayerController* TargetPlayer;
		EJMJumpScarePlayResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "TargetPlayer" },
		{ "Category", "JM JumpScare" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shows Definition.Image over the target player's camera. Target Player may be left empty for player 0. */" },
#endif
		{ "CPP_Default_TargetPlayer", "None" },
		{ "DisplayName", "Play 2D JumpScare" },
		{ "ModuleRelativePath", "Public/Blueprint/JMJumpScareBlueprintLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shows Definition.Image over the target player's camera. Target Player may be left empty for player 0." },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif // WITH_METADATA

// ********** Begin Function PlayJumpScare constinit property declarations *************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Definition;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetPlayer;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function PlayJumpScare constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function PlayJumpScare Property Definitions ************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_PlayJumpScare_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMJumpScareBlueprintLibrary_eventPlayJumpScare_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_PlayJumpScare_Statics::NewProp_Definition = { "Definition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMJumpScareBlueprintLibrary_eventPlayJumpScare_Parms, Definition), Z_Construct_UClass_UJMJumpScareDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_PlayJumpScare_Statics::NewProp_TargetPlayer = { "TargetPlayer", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMJumpScareBlueprintLibrary_eventPlayJumpScare_Parms, TargetPlayer), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_PlayJumpScare_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_PlayJumpScare_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMJumpScareBlueprintLibrary_eventPlayJumpScare_Parms, ReturnValue), Z_Construct_UEnum_JMJumpScare_EJMJumpScarePlayResult, METADATA_PARAMS(0, nullptr) }; // 453831882
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_PlayJumpScare_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_PlayJumpScare_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_PlayJumpScare_Statics::NewProp_Definition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_PlayJumpScare_Statics::NewProp_TargetPlayer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_PlayJumpScare_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_PlayJumpScare_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_PlayJumpScare_Statics::PropPointers) < 2048);
// ********** End Function PlayJumpScare Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_PlayJumpScare_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMJumpScareBlueprintLibrary, nullptr, "PlayJumpScare", 	Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_PlayJumpScare_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_PlayJumpScare_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_PlayJumpScare_Statics::JMJumpScareBlueprintLibrary_eventPlayJumpScare_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_PlayJumpScare_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_PlayJumpScare_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_PlayJumpScare_Statics::JMJumpScareBlueprintLibrary_eventPlayJumpScare_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_PlayJumpScare()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_PlayJumpScare_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMJumpScareBlueprintLibrary::execPlayJumpScare)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(UJMJumpScareDefinition,Z_Param_Definition);
	P_GET_OBJECT(APlayerController,Z_Param_TargetPlayer);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EJMJumpScarePlayResult*)Z_Param__Result=UJMJumpScareBlueprintLibrary::PlayJumpScare(Z_Param_WorldContextObject,Z_Param_Definition,Z_Param_TargetPlayer);
	P_NATIVE_END;
}
// ********** End Class UJMJumpScareBlueprintLibrary Function PlayJumpScare ************************

// ********** Begin Class UJMJumpScareBlueprintLibrary *********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMJumpScareBlueprintLibrary;
UClass* UJMJumpScareBlueprintLibrary::GetPrivateStaticClass()
{
	using TClass = UJMJumpScareBlueprintLibrary;
	if (!Z_Registration_Info_UClass_UJMJumpScareBlueprintLibrary.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMJumpScareBlueprintLibrary"),
			Z_Registration_Info_UClass_UJMJumpScareBlueprintLibrary.InnerSingleton,
			StaticRegisterNativesUJMJumpScareBlueprintLibrary,
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
	return Z_Registration_Info_UClass_UJMJumpScareBlueprintLibrary.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMJumpScareBlueprintLibrary_NoRegister()
{
	return UJMJumpScareBlueprintLibrary::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMJumpScareBlueprintLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Blueprint/JMJumpScareBlueprintLibrary.h" },
		{ "ModuleRelativePath", "Public/Blueprint/JMJumpScareBlueprintLibrary.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMJumpScareBlueprintLibrary constinit property declarations *************
// ********** End Class UJMJumpScareBlueprintLibrary constinit property declarations ***************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CancelJumpScare"), .Pointer = &UJMJumpScareBlueprintLibrary::execCancelJumpScare },
		{ .NameUTF8 = UTF8TEXT("IsJumpScarePlaying"), .Pointer = &UJMJumpScareBlueprintLibrary::execIsJumpScarePlaying },
		{ .NameUTF8 = UTF8TEXT("PlayJumpScare"), .Pointer = &UJMJumpScareBlueprintLibrary::execPlayJumpScare },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_CancelJumpScare, "CancelJumpScare" }, // 4146756607
		{ &Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_IsJumpScarePlaying, "IsJumpScarePlaying" }, // 4089371076
		{ &Z_Construct_UFunction_UJMJumpScareBlueprintLibrary_PlayJumpScare, "PlayJumpScare" }, // 659826833
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMJumpScareBlueprintLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMJumpScareBlueprintLibrary_Statics
UObject* (*const Z_Construct_UClass_UJMJumpScareBlueprintLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_JMJumpScare,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareBlueprintLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMJumpScareBlueprintLibrary_Statics::ClassParams = {
	&UJMJumpScareBlueprintLibrary::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMJumpScareBlueprintLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMJumpScareBlueprintLibrary_Statics::Class_MetaDataParams)
};
void UJMJumpScareBlueprintLibrary::StaticRegisterNativesUJMJumpScareBlueprintLibrary()
{
	UClass* Class = UJMJumpScareBlueprintLibrary::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMJumpScareBlueprintLibrary_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMJumpScareBlueprintLibrary()
{
	if (!Z_Registration_Info_UClass_UJMJumpScareBlueprintLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMJumpScareBlueprintLibrary.OuterSingleton, Z_Construct_UClass_UJMJumpScareBlueprintLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMJumpScareBlueprintLibrary.OuterSingleton;
}
UJMJumpScareBlueprintLibrary::UJMJumpScareBlueprintLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMJumpScareBlueprintLibrary);
UJMJumpScareBlueprintLibrary::~UJMJumpScareBlueprintLibrary() {}
// ********** End Class UJMJumpScareBlueprintLibrary ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Blueprint_JMJumpScareBlueprintLibrary_h__Script_JMJumpScare_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMJumpScareBlueprintLibrary, UJMJumpScareBlueprintLibrary::StaticClass, TEXT("UJMJumpScareBlueprintLibrary"), &Z_Registration_Info_UClass_UJMJumpScareBlueprintLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMJumpScareBlueprintLibrary), 2283223918U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Blueprint_JMJumpScareBlueprintLibrary_h__Script_JMJumpScare_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Blueprint_JMJumpScareBlueprintLibrary_h__Script_JMJumpScare_1607621145{
	TEXT("/Script/JMJumpScare"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Blueprint_JMJumpScareBlueprintLibrary_h__Script_JMJumpScare_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Blueprint_JMJumpScareBlueprintLibrary_h__Script_JMJumpScare_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
