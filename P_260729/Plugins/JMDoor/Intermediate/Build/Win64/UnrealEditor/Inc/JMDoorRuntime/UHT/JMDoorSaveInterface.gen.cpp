// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interfaces/JMDoorSaveInterface.h"
#include "Door/JMDoorTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMDoorSaveInterface() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorSaveInterface();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorSaveInterface_NoRegister();
JMDOORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMDoorSaveData();
UPackage* Z_Construct_UPackage__Script_JMDoorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface UJMDoorSaveInterface Function CaptureDoorSaveData ********************
struct JMDoorSaveInterface_eventCaptureDoorSaveData_Parms
{
	FJMDoorSaveData ReturnValue;
};
FJMDoorSaveData IJMDoorSaveInterface::CaptureDoorSaveData() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_CaptureDoorSaveData instead.");
	JMDoorSaveInterface_eventCaptureDoorSaveData_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UJMDoorSaveInterface_CaptureDoorSaveData = FName(TEXT("CaptureDoorSaveData"));
FJMDoorSaveData IJMDoorSaveInterface::Execute_CaptureDoorSaveData(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMDoorSaveInterface::StaticClass()));
	JMDoorSaveInterface_eventCaptureDoorSaveData_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMDoorSaveInterface_CaptureDoorSaveData);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IJMDoorSaveInterface*)(O->GetNativeInterfaceAddress(UJMDoorSaveInterface::StaticClass())))
	{
		Parms.ReturnValue = I->CaptureDoorSaveData_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UJMDoorSaveInterface_CaptureDoorSaveData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Save" },
		{ "ModuleRelativePath", "Public/Interfaces/JMDoorSaveInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function CaptureDoorSaveData constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CaptureDoorSaveData constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CaptureDoorSaveData Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorSaveInterface_CaptureDoorSaveData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorSaveInterface_eventCaptureDoorSaveData_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMDoorSaveData, METADATA_PARAMS(0, nullptr) }; // 362659228
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorSaveInterface_CaptureDoorSaveData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorSaveInterface_CaptureDoorSaveData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorSaveInterface_CaptureDoorSaveData_Statics::PropPointers) < 2048);
// ********** End Function CaptureDoorSaveData Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorSaveInterface_CaptureDoorSaveData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorSaveInterface, nullptr, "CaptureDoorSaveData", 	Z_Construct_UFunction_UJMDoorSaveInterface_CaptureDoorSaveData_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorSaveInterface_CaptureDoorSaveData_Statics::PropPointers), 
sizeof(JMDoorSaveInterface_eventCaptureDoorSaveData_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorSaveInterface_CaptureDoorSaveData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorSaveInterface_CaptureDoorSaveData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMDoorSaveInterface_eventCaptureDoorSaveData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorSaveInterface_CaptureDoorSaveData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorSaveInterface_CaptureDoorSaveData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMDoorSaveInterface::execCaptureDoorSaveData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMDoorSaveData*)Z_Param__Result=P_THIS->CaptureDoorSaveData_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UJMDoorSaveInterface Function CaptureDoorSaveData **********************

// ********** Begin Interface UJMDoorSaveInterface Function GetDoorPersistentId ********************
struct JMDoorSaveInterface_eventGetDoorPersistentId_Parms
{
	FGuid ReturnValue;
};
FGuid IJMDoorSaveInterface::GetDoorPersistentId() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetDoorPersistentId instead.");
	JMDoorSaveInterface_eventGetDoorPersistentId_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UJMDoorSaveInterface_GetDoorPersistentId = FName(TEXT("GetDoorPersistentId"));
FGuid IJMDoorSaveInterface::Execute_GetDoorPersistentId(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMDoorSaveInterface::StaticClass()));
	JMDoorSaveInterface_eventGetDoorPersistentId_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMDoorSaveInterface_GetDoorPersistentId);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IJMDoorSaveInterface*)(O->GetNativeInterfaceAddress(UJMDoorSaveInterface::StaticClass())))
	{
		Parms.ReturnValue = I->GetDoorPersistentId_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UJMDoorSaveInterface_GetDoorPersistentId_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Save" },
		{ "ModuleRelativePath", "Public/Interfaces/JMDoorSaveInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDoorPersistentId constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDoorPersistentId constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDoorPersistentId Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorSaveInterface_GetDoorPersistentId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorSaveInterface_eventGetDoorPersistentId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorSaveInterface_GetDoorPersistentId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorSaveInterface_GetDoorPersistentId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorSaveInterface_GetDoorPersistentId_Statics::PropPointers) < 2048);
// ********** End Function GetDoorPersistentId Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorSaveInterface_GetDoorPersistentId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorSaveInterface, nullptr, "GetDoorPersistentId", 	Z_Construct_UFunction_UJMDoorSaveInterface_GetDoorPersistentId_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorSaveInterface_GetDoorPersistentId_Statics::PropPointers), 
sizeof(JMDoorSaveInterface_eventGetDoorPersistentId_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C820C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorSaveInterface_GetDoorPersistentId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorSaveInterface_GetDoorPersistentId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMDoorSaveInterface_eventGetDoorPersistentId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorSaveInterface_GetDoorPersistentId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorSaveInterface_GetDoorPersistentId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMDoorSaveInterface::execGetDoorPersistentId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetDoorPersistentId_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UJMDoorSaveInterface Function GetDoorPersistentId **********************

// ********** Begin Interface UJMDoorSaveInterface Function RestoreDoorSaveData ********************
struct JMDoorSaveInterface_eventRestoreDoorSaveData_Parms
{
	FJMDoorSaveData SaveData;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	JMDoorSaveInterface_eventRestoreDoorSaveData_Parms()
		: ReturnValue(false)
	{
	}
};
bool IJMDoorSaveInterface::RestoreDoorSaveData(FJMDoorSaveData const& SaveData)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_RestoreDoorSaveData instead.");
	JMDoorSaveInterface_eventRestoreDoorSaveData_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UJMDoorSaveInterface_RestoreDoorSaveData = FName(TEXT("RestoreDoorSaveData"));
bool IJMDoorSaveInterface::Execute_RestoreDoorSaveData(UObject* O, FJMDoorSaveData const& SaveData)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMDoorSaveInterface::StaticClass()));
	JMDoorSaveInterface_eventRestoreDoorSaveData_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMDoorSaveInterface_RestoreDoorSaveData);
	if (Func)
	{
		Parms.SaveData=std::move(SaveData);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IJMDoorSaveInterface*)(O->GetNativeInterfaceAddress(UJMDoorSaveInterface::StaticClass())))
	{
		Parms.ReturnValue = I->RestoreDoorSaveData_Implementation(SaveData);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UJMDoorSaveInterface_RestoreDoorSaveData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Save" },
		{ "ModuleRelativePath", "Public/Interfaces/JMDoorSaveInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SaveData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RestoreDoorSaveData constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SaveData;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RestoreDoorSaveData constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RestoreDoorSaveData Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorSaveInterface_RestoreDoorSaveData_Statics::NewProp_SaveData = { "SaveData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorSaveInterface_eventRestoreDoorSaveData_Parms, SaveData), Z_Construct_UScriptStruct_FJMDoorSaveData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SaveData_MetaData), NewProp_SaveData_MetaData) }; // 362659228
void Z_Construct_UFunction_UJMDoorSaveInterface_RestoreDoorSaveData_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMDoorSaveInterface_eventRestoreDoorSaveData_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMDoorSaveInterface_RestoreDoorSaveData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMDoorSaveInterface_eventRestoreDoorSaveData_Parms), &Z_Construct_UFunction_UJMDoorSaveInterface_RestoreDoorSaveData_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorSaveInterface_RestoreDoorSaveData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorSaveInterface_RestoreDoorSaveData_Statics::NewProp_SaveData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorSaveInterface_RestoreDoorSaveData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorSaveInterface_RestoreDoorSaveData_Statics::PropPointers) < 2048);
// ********** End Function RestoreDoorSaveData Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorSaveInterface_RestoreDoorSaveData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorSaveInterface, nullptr, "RestoreDoorSaveData", 	Z_Construct_UFunction_UJMDoorSaveInterface_RestoreDoorSaveData_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorSaveInterface_RestoreDoorSaveData_Statics::PropPointers), 
sizeof(JMDoorSaveInterface_eventRestoreDoorSaveData_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorSaveInterface_RestoreDoorSaveData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorSaveInterface_RestoreDoorSaveData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMDoorSaveInterface_eventRestoreDoorSaveData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorSaveInterface_RestoreDoorSaveData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorSaveInterface_RestoreDoorSaveData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMDoorSaveInterface::execRestoreDoorSaveData)
{
	P_GET_STRUCT_REF(FJMDoorSaveData,Z_Param_Out_SaveData);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->RestoreDoorSaveData_Implementation(Z_Param_Out_SaveData);
	P_NATIVE_END;
}
// ********** End Interface UJMDoorSaveInterface Function RestoreDoorSaveData **********************

// ********** Begin Interface UJMDoorSaveInterface *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMDoorSaveInterface;
UClass* UJMDoorSaveInterface::GetPrivateStaticClass()
{
	using TClass = UJMDoorSaveInterface;
	if (!Z_Registration_Info_UClass_UJMDoorSaveInterface.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMDoorSaveInterface"),
			Z_Registration_Info_UClass_UJMDoorSaveInterface.InnerSingleton,
			StaticRegisterNativesUJMDoorSaveInterface,
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
	return Z_Registration_Info_UClass_UJMDoorSaveInterface.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMDoorSaveInterface_NoRegister()
{
	return UJMDoorSaveInterface::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMDoorSaveInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Interfaces/JMDoorSaveInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface UJMDoorSaveInterface constinit property declarations *****************
// ********** End Interface UJMDoorSaveInterface constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CaptureDoorSaveData"), .Pointer = &IJMDoorSaveInterface::execCaptureDoorSaveData },
		{ .NameUTF8 = UTF8TEXT("GetDoorPersistentId"), .Pointer = &IJMDoorSaveInterface::execGetDoorPersistentId },
		{ .NameUTF8 = UTF8TEXT("RestoreDoorSaveData"), .Pointer = &IJMDoorSaveInterface::execRestoreDoorSaveData },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMDoorSaveInterface_CaptureDoorSaveData, "CaptureDoorSaveData" }, // 2180182805
		{ &Z_Construct_UFunction_UJMDoorSaveInterface_GetDoorPersistentId, "GetDoorPersistentId" }, // 245849466
		{ &Z_Construct_UFunction_UJMDoorSaveInterface_RestoreDoorSaveData, "RestoreDoorSaveData" }, // 1824877535
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IJMDoorSaveInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMDoorSaveInterface_Statics
UObject* (*const Z_Construct_UClass_UJMDoorSaveInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorSaveInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMDoorSaveInterface_Statics::ClassParams = {
	&UJMDoorSaveInterface::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorSaveInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMDoorSaveInterface_Statics::Class_MetaDataParams)
};
void UJMDoorSaveInterface::StaticRegisterNativesUJMDoorSaveInterface()
{
	UClass* Class = UJMDoorSaveInterface::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMDoorSaveInterface_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMDoorSaveInterface()
{
	if (!Z_Registration_Info_UClass_UJMDoorSaveInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMDoorSaveInterface.OuterSingleton, Z_Construct_UClass_UJMDoorSaveInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMDoorSaveInterface.OuterSingleton;
}
UJMDoorSaveInterface::UJMDoorSaveInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMDoorSaveInterface);
// ********** End Interface UJMDoorSaveInterface ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorSaveInterface_h__Script_JMDoorRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMDoorSaveInterface, UJMDoorSaveInterface::StaticClass, TEXT("UJMDoorSaveInterface"), &Z_Registration_Info_UClass_UJMDoorSaveInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMDoorSaveInterface), 817703882U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorSaveInterface_h__Script_JMDoorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorSaveInterface_h__Script_JMDoorRuntime_1830244491{
	TEXT("/Script/JMDoorRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorSaveInterface_h__Script_JMDoorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorSaveInterface_h__Script_JMDoorRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
