// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interfaces/JMDoorUsableInterface.h"
#include "Door/JMDoorTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMDoorUsableInterface() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorUsableInterface();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorUsableInterface_NoRegister();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorCommand();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorState();
JMDOORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMDoorResult();
JMDOORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMDoorUseContext();
UPackage* Z_Construct_UPackage__Script_JMDoorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface UJMDoorUsableInterface Function CanExecuteDoorCommand ****************
struct JMDoorUsableInterface_eventCanExecuteDoorCommand_Parms
{
	EJMDoorCommand Command;
	FJMDoorUseContext Context;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	JMDoorUsableInterface_eventCanExecuteDoorCommand_Parms()
		: ReturnValue(false)
	{
	}
};
bool IJMDoorUsableInterface::CanExecuteDoorCommand(EJMDoorCommand Command, FJMDoorUseContext const& Context) const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_CanExecuteDoorCommand instead.");
	JMDoorUsableInterface_eventCanExecuteDoorCommand_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UJMDoorUsableInterface_CanExecuteDoorCommand = FName(TEXT("CanExecuteDoorCommand"));
bool IJMDoorUsableInterface::Execute_CanExecuteDoorCommand(const UObject* O, EJMDoorCommand Command, FJMDoorUseContext const& Context)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMDoorUsableInterface::StaticClass()));
	JMDoorUsableInterface_eventCanExecuteDoorCommand_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMDoorUsableInterface_CanExecuteDoorCommand);
	if (Func)
	{
		Parms.Command=std::move(Command);
		Parms.Context=std::move(Context);
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IJMDoorUsableInterface*)(O->GetNativeInterfaceAddress(UJMDoorUsableInterface::StaticClass())))
	{
		Parms.ReturnValue = I->CanExecuteDoorCommand_Implementation(Command,Context);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UJMDoorUsableInterface_CanExecuteDoorCommand_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door" },
		{ "ModuleRelativePath", "Public/Interfaces/JMDoorUsableInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CanExecuteDoorCommand constinit property declarations *****************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Command_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Command;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CanExecuteDoorCommand constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CanExecuteDoorCommand Property Definitions ****************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMDoorUsableInterface_CanExecuteDoorCommand_Statics::NewProp_Command_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMDoorUsableInterface_CanExecuteDoorCommand_Statics::NewProp_Command = { "Command", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorUsableInterface_eventCanExecuteDoorCommand_Parms, Command), Z_Construct_UEnum_JMDoorRuntime_EJMDoorCommand, METADATA_PARAMS(0, nullptr) }; // 4018727221
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorUsableInterface_CanExecuteDoorCommand_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorUsableInterface_eventCanExecuteDoorCommand_Parms, Context), Z_Construct_UScriptStruct_FJMDoorUseContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3552665729
void Z_Construct_UFunction_UJMDoorUsableInterface_CanExecuteDoorCommand_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMDoorUsableInterface_eventCanExecuteDoorCommand_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMDoorUsableInterface_CanExecuteDoorCommand_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMDoorUsableInterface_eventCanExecuteDoorCommand_Parms), &Z_Construct_UFunction_UJMDoorUsableInterface_CanExecuteDoorCommand_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorUsableInterface_CanExecuteDoorCommand_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorUsableInterface_CanExecuteDoorCommand_Statics::NewProp_Command_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorUsableInterface_CanExecuteDoorCommand_Statics::NewProp_Command,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorUsableInterface_CanExecuteDoorCommand_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorUsableInterface_CanExecuteDoorCommand_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorUsableInterface_CanExecuteDoorCommand_Statics::PropPointers) < 2048);
// ********** End Function CanExecuteDoorCommand Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorUsableInterface_CanExecuteDoorCommand_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorUsableInterface, nullptr, "CanExecuteDoorCommand", 	Z_Construct_UFunction_UJMDoorUsableInterface_CanExecuteDoorCommand_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorUsableInterface_CanExecuteDoorCommand_Statics::PropPointers), 
sizeof(JMDoorUsableInterface_eventCanExecuteDoorCommand_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorUsableInterface_CanExecuteDoorCommand_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorUsableInterface_CanExecuteDoorCommand_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMDoorUsableInterface_eventCanExecuteDoorCommand_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorUsableInterface_CanExecuteDoorCommand()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorUsableInterface_CanExecuteDoorCommand_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMDoorUsableInterface::execCanExecuteDoorCommand)
{
	P_GET_ENUM(EJMDoorCommand,Z_Param_Command);
	P_GET_STRUCT_REF(FJMDoorUseContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanExecuteDoorCommand_Implementation(EJMDoorCommand(Z_Param_Command),Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Interface UJMDoorUsableInterface Function CanExecuteDoorCommand ******************

// ********** Begin Interface UJMDoorUsableInterface Function ExecuteDoorCommand *******************
struct JMDoorUsableInterface_eventExecuteDoorCommand_Parms
{
	EJMDoorCommand Command;
	FJMDoorUseContext Context;
	FJMDoorResult ReturnValue;
};
FJMDoorResult IJMDoorUsableInterface::ExecuteDoorCommand(EJMDoorCommand Command, FJMDoorUseContext const& Context)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_ExecuteDoorCommand instead.");
	JMDoorUsableInterface_eventExecuteDoorCommand_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UJMDoorUsableInterface_ExecuteDoorCommand = FName(TEXT("ExecuteDoorCommand"));
FJMDoorResult IJMDoorUsableInterface::Execute_ExecuteDoorCommand(UObject* O, EJMDoorCommand Command, FJMDoorUseContext const& Context)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMDoorUsableInterface::StaticClass()));
	JMDoorUsableInterface_eventExecuteDoorCommand_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMDoorUsableInterface_ExecuteDoorCommand);
	if (Func)
	{
		Parms.Command=std::move(Command);
		Parms.Context=std::move(Context);
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IJMDoorUsableInterface*)(O->GetNativeInterfaceAddress(UJMDoorUsableInterface::StaticClass())))
	{
		Parms.ReturnValue = I->ExecuteDoorCommand_Implementation(Command,Context);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UJMDoorUsableInterface_ExecuteDoorCommand_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door" },
		{ "ModuleRelativePath", "Public/Interfaces/JMDoorUsableInterface.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ExecuteDoorCommand constinit property declarations ********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Command_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Command;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ExecuteDoorCommand constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ExecuteDoorCommand Property Definitions *******************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMDoorUsableInterface_ExecuteDoorCommand_Statics::NewProp_Command_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMDoorUsableInterface_ExecuteDoorCommand_Statics::NewProp_Command = { "Command", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorUsableInterface_eventExecuteDoorCommand_Parms, Command), Z_Construct_UEnum_JMDoorRuntime_EJMDoorCommand, METADATA_PARAMS(0, nullptr) }; // 4018727221
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorUsableInterface_ExecuteDoorCommand_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorUsableInterface_eventExecuteDoorCommand_Parms, Context), Z_Construct_UScriptStruct_FJMDoorUseContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3552665729
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMDoorUsableInterface_ExecuteDoorCommand_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorUsableInterface_eventExecuteDoorCommand_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMDoorResult, METADATA_PARAMS(0, nullptr) }; // 1639184842
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorUsableInterface_ExecuteDoorCommand_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorUsableInterface_ExecuteDoorCommand_Statics::NewProp_Command_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorUsableInterface_ExecuteDoorCommand_Statics::NewProp_Command,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorUsableInterface_ExecuteDoorCommand_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorUsableInterface_ExecuteDoorCommand_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorUsableInterface_ExecuteDoorCommand_Statics::PropPointers) < 2048);
// ********** End Function ExecuteDoorCommand Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorUsableInterface_ExecuteDoorCommand_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorUsableInterface, nullptr, "ExecuteDoorCommand", 	Z_Construct_UFunction_UJMDoorUsableInterface_ExecuteDoorCommand_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorUsableInterface_ExecuteDoorCommand_Statics::PropPointers), 
sizeof(JMDoorUsableInterface_eventExecuteDoorCommand_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorUsableInterface_ExecuteDoorCommand_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorUsableInterface_ExecuteDoorCommand_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMDoorUsableInterface_eventExecuteDoorCommand_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorUsableInterface_ExecuteDoorCommand()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorUsableInterface_ExecuteDoorCommand_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMDoorUsableInterface::execExecuteDoorCommand)
{
	P_GET_ENUM(EJMDoorCommand,Z_Param_Command);
	P_GET_STRUCT_REF(FJMDoorUseContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMDoorResult*)Z_Param__Result=P_THIS->ExecuteDoorCommand_Implementation(EJMDoorCommand(Z_Param_Command),Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Interface UJMDoorUsableInterface Function ExecuteDoorCommand *********************

// ********** Begin Interface UJMDoorUsableInterface Function GetDoorState *************************
struct JMDoorUsableInterface_eventGetDoorState_Parms
{
	EJMDoorState ReturnValue;

	/** Constructor, initializes return property only **/
	JMDoorUsableInterface_eventGetDoorState_Parms()
		: ReturnValue((EJMDoorState)0)
	{
	}
};
EJMDoorState IJMDoorUsableInterface::GetDoorState() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetDoorState instead.");
	JMDoorUsableInterface_eventGetDoorState_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UJMDoorUsableInterface_GetDoorState = FName(TEXT("GetDoorState"));
EJMDoorState IJMDoorUsableInterface::Execute_GetDoorState(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UJMDoorUsableInterface::StaticClass()));
	JMDoorUsableInterface_eventGetDoorState_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UJMDoorUsableInterface_GetDoorState);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IJMDoorUsableInterface*)(O->GetNativeInterfaceAddress(UJMDoorUsableInterface::StaticClass())))
	{
		Parms.ReturnValue = I->GetDoorState_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UJMDoorUsableInterface_GetDoorState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door" },
		{ "ModuleRelativePath", "Public/Interfaces/JMDoorUsableInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDoorState constinit property declarations **************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDoorState constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDoorState Property Definitions *************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMDoorUsableInterface_GetDoorState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMDoorUsableInterface_GetDoorState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorUsableInterface_eventGetDoorState_Parms, ReturnValue), Z_Construct_UEnum_JMDoorRuntime_EJMDoorState, METADATA_PARAMS(0, nullptr) }; // 2513049645
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorUsableInterface_GetDoorState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorUsableInterface_GetDoorState_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorUsableInterface_GetDoorState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorUsableInterface_GetDoorState_Statics::PropPointers) < 2048);
// ********** End Function GetDoorState Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorUsableInterface_GetDoorState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorUsableInterface, nullptr, "GetDoorState", 	Z_Construct_UFunction_UJMDoorUsableInterface_GetDoorState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorUsableInterface_GetDoorState_Statics::PropPointers), 
sizeof(JMDoorUsableInterface_eventGetDoorState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorUsableInterface_GetDoorState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorUsableInterface_GetDoorState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMDoorUsableInterface_eventGetDoorState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorUsableInterface_GetDoorState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorUsableInterface_GetDoorState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IJMDoorUsableInterface::execGetDoorState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EJMDoorState*)Z_Param__Result=P_THIS->GetDoorState_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UJMDoorUsableInterface Function GetDoorState ***************************

// ********** Begin Interface UJMDoorUsableInterface ***********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMDoorUsableInterface;
UClass* UJMDoorUsableInterface::GetPrivateStaticClass()
{
	using TClass = UJMDoorUsableInterface;
	if (!Z_Registration_Info_UClass_UJMDoorUsableInterface.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMDoorUsableInterface"),
			Z_Registration_Info_UClass_UJMDoorUsableInterface.InnerSingleton,
			StaticRegisterNativesUJMDoorUsableInterface,
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
	return Z_Registration_Info_UClass_UJMDoorUsableInterface.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMDoorUsableInterface_NoRegister()
{
	return UJMDoorUsableInterface::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMDoorUsableInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Interfaces/JMDoorUsableInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface UJMDoorUsableInterface constinit property declarations ***************
// ********** End Interface UJMDoorUsableInterface constinit property declarations *****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CanExecuteDoorCommand"), .Pointer = &IJMDoorUsableInterface::execCanExecuteDoorCommand },
		{ .NameUTF8 = UTF8TEXT("ExecuteDoorCommand"), .Pointer = &IJMDoorUsableInterface::execExecuteDoorCommand },
		{ .NameUTF8 = UTF8TEXT("GetDoorState"), .Pointer = &IJMDoorUsableInterface::execGetDoorState },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMDoorUsableInterface_CanExecuteDoorCommand, "CanExecuteDoorCommand" }, // 4163474791
		{ &Z_Construct_UFunction_UJMDoorUsableInterface_ExecuteDoorCommand, "ExecuteDoorCommand" }, // 316787955
		{ &Z_Construct_UFunction_UJMDoorUsableInterface_GetDoorState, "GetDoorState" }, // 3605322044
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IJMDoorUsableInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMDoorUsableInterface_Statics
UObject* (*const Z_Construct_UClass_UJMDoorUsableInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorUsableInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMDoorUsableInterface_Statics::ClassParams = {
	&UJMDoorUsableInterface::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorUsableInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMDoorUsableInterface_Statics::Class_MetaDataParams)
};
void UJMDoorUsableInterface::StaticRegisterNativesUJMDoorUsableInterface()
{
	UClass* Class = UJMDoorUsableInterface::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMDoorUsableInterface_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMDoorUsableInterface()
{
	if (!Z_Registration_Info_UClass_UJMDoorUsableInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMDoorUsableInterface.OuterSingleton, Z_Construct_UClass_UJMDoorUsableInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMDoorUsableInterface.OuterSingleton;
}
UJMDoorUsableInterface::UJMDoorUsableInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMDoorUsableInterface);
// ********** End Interface UJMDoorUsableInterface *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorUsableInterface_h__Script_JMDoorRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMDoorUsableInterface, UJMDoorUsableInterface::StaticClass, TEXT("UJMDoorUsableInterface"), &Z_Registration_Info_UClass_UJMDoorUsableInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMDoorUsableInterface), 2903801364U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorUsableInterface_h__Script_JMDoorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorUsableInterface_h__Script_JMDoorRuntime_2112490734{
	TEXT("/Script/JMDoorRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorUsableInterface_h__Script_JMDoorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorUsableInterface_h__Script_JMDoorRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
