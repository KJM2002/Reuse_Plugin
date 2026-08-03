// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interfaces/JMDoorAccessProviderInterface.h"
#include "Door/JMDoorTypes.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMDoorAccessProviderInterface() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorAccessProviderInterface();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorAccessProviderInterface_NoRegister();
JMDOORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMDoorAccessRequirement();
UPackage* Z_Construct_UPackage__Script_JMDoorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface UJMDoorAccessProviderInterface Function CanProvideDoorAccess *********
struct JMDoorAccessProviderInterface_eventCanProvideDoorAccess_Parms
{
	FJMDoorAccessRequirement Requirement;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	JMDoorAccessProviderInterface_eventCanProvideDoorAccess_Parms()
		: ReturnValue(false)
	{
	}
};
bool IJMDoorAccessProviderInterface::CanProvideDoorAccess(FJMDoorAccessRequirement const& Requirement) const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_CanProvideDoorAccess instead.");
	JMDoorAccessProviderInterface_eventCanProvideDoorAccess_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UJMDoorAccessProviderInterface_CanProvideDoorAccess = FName(TEXT("CanProvideDoorAccess"));
bool IJMDoorAccessProviderInterface::Execute_CanProvideDoorAccess(const UObject* O, FJMDoorAccessRequirement const& Requirement)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMDoorAccessProviderInterface::StaticClass()));
	JMDoorAccessProviderInterface_eventCanProvideDoorAccess_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMDoorAccessProviderInterface_CanProvideDoorAccess);
	if (Func)
	{
		Parms.Requirement=std::move(Requirement);
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IJMDoorAccessProviderInterface*)(O->GetNativeInterfaceAddress(UJMDoorAccessProviderInterface::StaticClass())))
	{
		Parms.ReturnValue = I->CanProvideDoorAccess_Implementation(Requirement);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UJMDoorAccessProviderInterface_CanProvideDoorAccess_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Access" },
		{ "ModuleRelativePath", "Public/Interfaces/JMDoorAccessProviderInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Requirement_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CanProvideDoorAccess constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Requirement;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CanProvideDoorAccess constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CanProvideDoorAccess Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorAccessProviderInterface_CanProvideDoorAccess_Statics::NewProp_Requirement = { "Requirement", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorAccessProviderInterface_eventCanProvideDoorAccess_Parms, Requirement), Z_Construct_UScriptStruct_FJMDoorAccessRequirement, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Requirement_MetaData), NewProp_Requirement_MetaData) }; // 3499309010
void Z_Construct_UFunction_UJMDoorAccessProviderInterface_CanProvideDoorAccess_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMDoorAccessProviderInterface_eventCanProvideDoorAccess_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMDoorAccessProviderInterface_CanProvideDoorAccess_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMDoorAccessProviderInterface_eventCanProvideDoorAccess_Parms), &Z_Construct_UFunction_UJMDoorAccessProviderInterface_CanProvideDoorAccess_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorAccessProviderInterface_CanProvideDoorAccess_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorAccessProviderInterface_CanProvideDoorAccess_Statics::NewProp_Requirement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorAccessProviderInterface_CanProvideDoorAccess_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorAccessProviderInterface_CanProvideDoorAccess_Statics::PropPointers) < 2048);
// ********** End Function CanProvideDoorAccess Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorAccessProviderInterface_CanProvideDoorAccess_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorAccessProviderInterface, nullptr, "CanProvideDoorAccess", 	Z_Construct_UFunction_UJMDoorAccessProviderInterface_CanProvideDoorAccess_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorAccessProviderInterface_CanProvideDoorAccess_Statics::PropPointers), 
sizeof(JMDoorAccessProviderInterface_eventCanProvideDoorAccess_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorAccessProviderInterface_CanProvideDoorAccess_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorAccessProviderInterface_CanProvideDoorAccess_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMDoorAccessProviderInterface_eventCanProvideDoorAccess_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorAccessProviderInterface_CanProvideDoorAccess()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorAccessProviderInterface_CanProvideDoorAccess_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMDoorAccessProviderInterface::execCanProvideDoorAccess)
{
	P_GET_STRUCT_REF(FJMDoorAccessRequirement,Z_Param_Out_Requirement);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanProvideDoorAccess_Implementation(Z_Param_Out_Requirement);
	P_NATIVE_END;
}
// ********** End Interface UJMDoorAccessProviderInterface Function CanProvideDoorAccess ***********

// ********** Begin Interface UJMDoorAccessProviderInterface Function ConsumeDoorAccess ************
struct JMDoorAccessProviderInterface_eventConsumeDoorAccess_Parms
{
	FJMDoorAccessRequirement Requirement;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	JMDoorAccessProviderInterface_eventConsumeDoorAccess_Parms()
		: ReturnValue(false)
	{
	}
};
bool IJMDoorAccessProviderInterface::ConsumeDoorAccess(FJMDoorAccessRequirement const& Requirement)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_ConsumeDoorAccess instead.");
	JMDoorAccessProviderInterface_eventConsumeDoorAccess_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UJMDoorAccessProviderInterface_ConsumeDoorAccess = FName(TEXT("ConsumeDoorAccess"));
bool IJMDoorAccessProviderInterface::Execute_ConsumeDoorAccess(UObject* O, FJMDoorAccessRequirement const& Requirement)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMDoorAccessProviderInterface::StaticClass()));
	JMDoorAccessProviderInterface_eventConsumeDoorAccess_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMDoorAccessProviderInterface_ConsumeDoorAccess);
	if (Func)
	{
		Parms.Requirement=std::move(Requirement);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IJMDoorAccessProviderInterface*)(O->GetNativeInterfaceAddress(UJMDoorAccessProviderInterface::StaticClass())))
	{
		Parms.ReturnValue = I->ConsumeDoorAccess_Implementation(Requirement);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UJMDoorAccessProviderInterface_ConsumeDoorAccess_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Access" },
		{ "ModuleRelativePath", "Public/Interfaces/JMDoorAccessProviderInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Requirement_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ConsumeDoorAccess constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Requirement;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ConsumeDoorAccess constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ConsumeDoorAccess Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorAccessProviderInterface_ConsumeDoorAccess_Statics::NewProp_Requirement = { "Requirement", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorAccessProviderInterface_eventConsumeDoorAccess_Parms, Requirement), Z_Construct_UScriptStruct_FJMDoorAccessRequirement, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Requirement_MetaData), NewProp_Requirement_MetaData) }; // 3499309010
void Z_Construct_UFunction_UJMDoorAccessProviderInterface_ConsumeDoorAccess_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMDoorAccessProviderInterface_eventConsumeDoorAccess_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMDoorAccessProviderInterface_ConsumeDoorAccess_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMDoorAccessProviderInterface_eventConsumeDoorAccess_Parms), &Z_Construct_UFunction_UJMDoorAccessProviderInterface_ConsumeDoorAccess_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorAccessProviderInterface_ConsumeDoorAccess_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorAccessProviderInterface_ConsumeDoorAccess_Statics::NewProp_Requirement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorAccessProviderInterface_ConsumeDoorAccess_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorAccessProviderInterface_ConsumeDoorAccess_Statics::PropPointers) < 2048);
// ********** End Function ConsumeDoorAccess Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorAccessProviderInterface_ConsumeDoorAccess_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorAccessProviderInterface, nullptr, "ConsumeDoorAccess", 	Z_Construct_UFunction_UJMDoorAccessProviderInterface_ConsumeDoorAccess_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorAccessProviderInterface_ConsumeDoorAccess_Statics::PropPointers), 
sizeof(JMDoorAccessProviderInterface_eventConsumeDoorAccess_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorAccessProviderInterface_ConsumeDoorAccess_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorAccessProviderInterface_ConsumeDoorAccess_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMDoorAccessProviderInterface_eventConsumeDoorAccess_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorAccessProviderInterface_ConsumeDoorAccess()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorAccessProviderInterface_ConsumeDoorAccess_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMDoorAccessProviderInterface::execConsumeDoorAccess)
{
	P_GET_STRUCT_REF(FJMDoorAccessRequirement,Z_Param_Out_Requirement);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ConsumeDoorAccess_Implementation(Z_Param_Out_Requirement);
	P_NATIVE_END;
}
// ********** End Interface UJMDoorAccessProviderInterface Function ConsumeDoorAccess **************

// ********** Begin Interface UJMDoorAccessProviderInterface Function GetDoorAccessTags ************
struct JMDoorAccessProviderInterface_eventGetDoorAccessTags_Parms
{
	FGameplayTagContainer ReturnValue;
};
FGameplayTagContainer IJMDoorAccessProviderInterface::GetDoorAccessTags() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetDoorAccessTags instead.");
	JMDoorAccessProviderInterface_eventGetDoorAccessTags_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UJMDoorAccessProviderInterface_GetDoorAccessTags = FName(TEXT("GetDoorAccessTags"));
FGameplayTagContainer IJMDoorAccessProviderInterface::Execute_GetDoorAccessTags(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMDoorAccessProviderInterface::StaticClass()));
	JMDoorAccessProviderInterface_eventGetDoorAccessTags_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMDoorAccessProviderInterface_GetDoorAccessTags);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IJMDoorAccessProviderInterface*)(O->GetNativeInterfaceAddress(UJMDoorAccessProviderInterface::StaticClass())))
	{
		Parms.ReturnValue = I->GetDoorAccessTags_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UJMDoorAccessProviderInterface_GetDoorAccessTags_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Access" },
		{ "ModuleRelativePath", "Public/Interfaces/JMDoorAccessProviderInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDoorAccessTags constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDoorAccessTags constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDoorAccessTags Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorAccessProviderInterface_GetDoorAccessTags_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorAccessProviderInterface_eventGetDoorAccessTags_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(0, nullptr) }; // 3438578166
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorAccessProviderInterface_GetDoorAccessTags_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorAccessProviderInterface_GetDoorAccessTags_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorAccessProviderInterface_GetDoorAccessTags_Statics::PropPointers) < 2048);
// ********** End Function GetDoorAccessTags Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorAccessProviderInterface_GetDoorAccessTags_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorAccessProviderInterface, nullptr, "GetDoorAccessTags", 	Z_Construct_UFunction_UJMDoorAccessProviderInterface_GetDoorAccessTags_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorAccessProviderInterface_GetDoorAccessTags_Statics::PropPointers), 
sizeof(JMDoorAccessProviderInterface_eventGetDoorAccessTags_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorAccessProviderInterface_GetDoorAccessTags_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorAccessProviderInterface_GetDoorAccessTags_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMDoorAccessProviderInterface_eventGetDoorAccessTags_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorAccessProviderInterface_GetDoorAccessTags()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorAccessProviderInterface_GetDoorAccessTags_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMDoorAccessProviderInterface::execGetDoorAccessTags)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGameplayTagContainer*)Z_Param__Result=P_THIS->GetDoorAccessTags_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UJMDoorAccessProviderInterface Function GetDoorAccessTags **************

// ********** Begin Interface UJMDoorAccessProviderInterface ***************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMDoorAccessProviderInterface;
UClass* UJMDoorAccessProviderInterface::GetPrivateStaticClass()
{
	using TClass = UJMDoorAccessProviderInterface;
	if (!Z_Registration_Info_UClass_UJMDoorAccessProviderInterface.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMDoorAccessProviderInterface"),
			Z_Registration_Info_UClass_UJMDoorAccessProviderInterface.InnerSingleton,
			StaticRegisterNativesUJMDoorAccessProviderInterface,
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
	return Z_Registration_Info_UClass_UJMDoorAccessProviderInterface.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMDoorAccessProviderInterface_NoRegister()
{
	return UJMDoorAccessProviderInterface::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMDoorAccessProviderInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Interfaces/JMDoorAccessProviderInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface UJMDoorAccessProviderInterface constinit property declarations *******
// ********** End Interface UJMDoorAccessProviderInterface constinit property declarations *********
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CanProvideDoorAccess"), .Pointer = &IJMDoorAccessProviderInterface::execCanProvideDoorAccess },
		{ .NameUTF8 = UTF8TEXT("ConsumeDoorAccess"), .Pointer = &IJMDoorAccessProviderInterface::execConsumeDoorAccess },
		{ .NameUTF8 = UTF8TEXT("GetDoorAccessTags"), .Pointer = &IJMDoorAccessProviderInterface::execGetDoorAccessTags },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMDoorAccessProviderInterface_CanProvideDoorAccess, "CanProvideDoorAccess" }, // 1790143457
		{ &Z_Construct_UFunction_UJMDoorAccessProviderInterface_ConsumeDoorAccess, "ConsumeDoorAccess" }, // 3391684829
		{ &Z_Construct_UFunction_UJMDoorAccessProviderInterface_GetDoorAccessTags, "GetDoorAccessTags" }, // 3083111439
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IJMDoorAccessProviderInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMDoorAccessProviderInterface_Statics
UObject* (*const Z_Construct_UClass_UJMDoorAccessProviderInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorAccessProviderInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMDoorAccessProviderInterface_Statics::ClassParams = {
	&UJMDoorAccessProviderInterface::StaticClass,
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
	0x001040A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorAccessProviderInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMDoorAccessProviderInterface_Statics::Class_MetaDataParams)
};
void UJMDoorAccessProviderInterface::StaticRegisterNativesUJMDoorAccessProviderInterface()
{
	UClass* Class = UJMDoorAccessProviderInterface::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMDoorAccessProviderInterface_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMDoorAccessProviderInterface()
{
	if (!Z_Registration_Info_UClass_UJMDoorAccessProviderInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMDoorAccessProviderInterface.OuterSingleton, Z_Construct_UClass_UJMDoorAccessProviderInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMDoorAccessProviderInterface.OuterSingleton;
}
UJMDoorAccessProviderInterface::UJMDoorAccessProviderInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMDoorAccessProviderInterface);
// ********** End Interface UJMDoorAccessProviderInterface *****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorAccessProviderInterface_h__Script_JMDoorRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMDoorAccessProviderInterface, UJMDoorAccessProviderInterface::StaticClass, TEXT("UJMDoorAccessProviderInterface"), &Z_Registration_Info_UClass_UJMDoorAccessProviderInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMDoorAccessProviderInterface), 3777507708U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorAccessProviderInterface_h__Script_JMDoorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorAccessProviderInterface_h__Script_JMDoorRuntime_1664394276{
	TEXT("/Script/JMDoorRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorAccessProviderInterface_h__Script_JMDoorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorAccessProviderInterface_h__Script_JMDoorRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
