// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JMThrowableGameplayIntegrationComponent.h"
#include "JMThrowableInventoryContext.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMThrowableGameplayIntegrationComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
JMTHROWABLE_API UClass* Z_Construct_UClass_UJMThrowableInteractorComponent_NoRegister();
JMTHROWABLE_API UEnum* Z_Construct_UEnum_JMThrowable_EJMThrowableUseState();
JMTHROWABLEGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent();
JMTHROWABLEGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_NoRegister();
JMTHROWABLEGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMThrowableStatusWidget_NoRegister();
JMTHROWABLEGAMEPLAYINTEGRATION_API UScriptStruct* Z_Construct_UScriptStruct_FJMThrowableInventoryContext();
UPackage* Z_Construct_UPackage__Script_JMThrowableGameplayIntegration();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMThrowableGameplayIntegrationComponent Function HandleInventoryChanged *
struct Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleInventoryChanged_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/JMThrowableGameplayIntegrationComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleInventoryChanged constinit property declarations ****************
// ********** End Function HandleInventoryChanged constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleInventoryChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent, nullptr, "HandleInventoryChanged", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleInventoryChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleInventoryChanged_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleInventoryChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleInventoryChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMThrowableGameplayIntegrationComponent::execHandleInventoryChanged)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleInventoryChanged();
	P_NATIVE_END;
}
// ********** End Class UJMThrowableGameplayIntegrationComponent Function HandleInventoryChanged ***

// ********** Begin Class UJMThrowableGameplayIntegrationComponent Function HandleStateChanged *****
struct Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleStateChanged_Statics
{
	struct JMThrowableGameplayIntegrationComponent_eventHandleStateChanged_Parms
	{
		EJMThrowableUseState NewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/JMThrowableGameplayIntegrationComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleStateChanged constinit property declarations ********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleStateChanged constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleStateChanged Property Definitions *******************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleStateChanged_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleStateChanged_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMThrowableGameplayIntegrationComponent_eventHandleStateChanged_Parms, NewState), Z_Construct_UEnum_JMThrowable_EJMThrowableUseState, METADATA_PARAMS(0, nullptr) }; // 755976728
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleStateChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleStateChanged_Statics::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleStateChanged_Statics::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleStateChanged_Statics::PropPointers) < 2048);
// ********** End Function HandleStateChanged Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleStateChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent, nullptr, "HandleStateChanged", 	Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleStateChanged_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleStateChanged_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleStateChanged_Statics::JMThrowableGameplayIntegrationComponent_eventHandleStateChanged_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleStateChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleStateChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleStateChanged_Statics::JMThrowableGameplayIntegrationComponent_eventHandleStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleStateChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleStateChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMThrowableGameplayIntegrationComponent::execHandleStateChanged)
{
	P_GET_ENUM(EJMThrowableUseState,Z_Param_NewState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleStateChanged(EJMThrowableUseState(Z_Param_NewState));
	P_NATIVE_END;
}
// ********** End Class UJMThrowableGameplayIntegrationComponent Function HandleStateChanged *******

// ********** Begin Class UJMThrowableGameplayIntegrationComponent Function NotifyInventoryOpening *
struct Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_NotifyInventoryOpening_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Throwable" },
		{ "ModuleRelativePath", "Public/JMThrowableGameplayIntegrationComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function NotifyInventoryOpening constinit property declarations ****************
// ********** End Function NotifyInventoryOpening constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_NotifyInventoryOpening_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent, nullptr, "NotifyInventoryOpening", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_NotifyInventoryOpening_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_NotifyInventoryOpening_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_NotifyInventoryOpening()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_NotifyInventoryOpening_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMThrowableGameplayIntegrationComponent::execNotifyInventoryOpening)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->NotifyInventoryOpening();
	P_NATIVE_END;
}
// ********** End Class UJMThrowableGameplayIntegrationComponent Function NotifyInventoryOpening ***

// ********** Begin Class UJMThrowableGameplayIntegrationComponent Function RequestCancelSprint ****
static FName NAME_UJMThrowableGameplayIntegrationComponent_RequestCancelSprint = FName(TEXT("RequestCancelSprint"));
void UJMThrowableGameplayIntegrationComponent::RequestCancelSprint()
{
	UFunction* Func = FindFunctionChecked(NAME_UJMThrowableGameplayIntegrationComponent_RequestCancelSprint);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		RequestCancelSprint_Implementation();
	}
}
struct Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_RequestCancelSprint_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Throwable|Movement" },
		{ "ModuleRelativePath", "Public/JMThrowableGameplayIntegrationComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestCancelSprint constinit property declarations *******************
// ********** End Function RequestCancelSprint constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_RequestCancelSprint_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent, nullptr, "RequestCancelSprint", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_RequestCancelSprint_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_RequestCancelSprint_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_RequestCancelSprint()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_RequestCancelSprint_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMThrowableGameplayIntegrationComponent::execRequestCancelSprint)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestCancelSprint_Implementation();
	P_NATIVE_END;
}
// ********** End Class UJMThrowableGameplayIntegrationComponent Function RequestCancelSprint ******

// ********** Begin Class UJMThrowableGameplayIntegrationComponent *********************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMThrowableGameplayIntegrationComponent;
UClass* UJMThrowableGameplayIntegrationComponent::GetPrivateStaticClass()
{
	using TClass = UJMThrowableGameplayIntegrationComponent;
	if (!Z_Registration_Info_UClass_UJMThrowableGameplayIntegrationComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMThrowableGameplayIntegrationComponent"),
			Z_Registration_Info_UClass_UJMThrowableGameplayIntegrationComponent.InnerSingleton,
			StaticRegisterNativesUJMThrowableGameplayIntegrationComponent,
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
	return Z_Registration_Info_UClass_UJMThrowableGameplayIntegrationComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_NoRegister()
{
	return UJMThrowableGameplayIntegrationComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JM" },
		{ "IncludePath", "JMThrowableGameplayIntegrationComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableGameplayIntegrationComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventoryContext_MetaData[] = {
		{ "ModuleRelativePath", "Public/JMThrowableGameplayIntegrationComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Interactor_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableGameplayIntegrationComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MappingContext_MetaData[] = {
		{ "ModuleRelativePath", "Public/JMThrowableGameplayIntegrationComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimAction_MetaData[] = {
		{ "ModuleRelativePath", "Public/JMThrowableGameplayIntegrationComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThrowAction_MetaData[] = {
		{ "ModuleRelativePath", "Public/JMThrowableGameplayIntegrationComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CancelAction_MetaData[] = {
		{ "ModuleRelativePath", "Public/JMThrowableGameplayIntegrationComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StatusWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/JMThrowableGameplayIntegrationComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMThrowableGameplayIntegrationComponent constinit property declarations *
	static const UECodeGen_Private::FStructPropertyParams NewProp_InventoryContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Interactor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MappingContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AimAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ThrowAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CancelAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StatusWidget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMThrowableGameplayIntegrationComponent constinit property declarations ***
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("HandleInventoryChanged"), .Pointer = &UJMThrowableGameplayIntegrationComponent::execHandleInventoryChanged },
		{ .NameUTF8 = UTF8TEXT("HandleStateChanged"), .Pointer = &UJMThrowableGameplayIntegrationComponent::execHandleStateChanged },
		{ .NameUTF8 = UTF8TEXT("NotifyInventoryOpening"), .Pointer = &UJMThrowableGameplayIntegrationComponent::execNotifyInventoryOpening },
		{ .NameUTF8 = UTF8TEXT("RequestCancelSprint"), .Pointer = &UJMThrowableGameplayIntegrationComponent::execRequestCancelSprint },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleInventoryChanged, "HandleInventoryChanged" }, // 3423216330
		{ &Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_HandleStateChanged, "HandleStateChanged" }, // 2030368960
		{ &Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_NotifyInventoryOpening, "NotifyInventoryOpening" }, // 3437261301
		{ &Z_Construct_UFunction_UJMThrowableGameplayIntegrationComponent_RequestCancelSprint, "RequestCancelSprint" }, // 3300557210
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMThrowableGameplayIntegrationComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics

// ********** Begin Class UJMThrowableGameplayIntegrationComponent Property Definitions ************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::NewProp_InventoryContext = { "InventoryContext", nullptr, (EPropertyFlags)0x0040008000002000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableGameplayIntegrationComponent, InventoryContext), Z_Construct_UScriptStruct_FJMThrowableInventoryContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryContext_MetaData), NewProp_InventoryContext_MetaData) }; // 4063969361
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::NewProp_Interactor = { "Interactor", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableGameplayIntegrationComponent, Interactor), Z_Construct_UClass_UJMThrowableInteractorComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Interactor_MetaData), NewProp_Interactor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::NewProp_MappingContext = { "MappingContext", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableGameplayIntegrationComponent, MappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MappingContext_MetaData), NewProp_MappingContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::NewProp_AimAction = { "AimAction", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableGameplayIntegrationComponent, AimAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimAction_MetaData), NewProp_AimAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::NewProp_ThrowAction = { "ThrowAction", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableGameplayIntegrationComponent, ThrowAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThrowAction_MetaData), NewProp_ThrowAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::NewProp_CancelAction = { "CancelAction", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableGameplayIntegrationComponent, CancelAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CancelAction_MetaData), NewProp_CancelAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::NewProp_StatusWidget = { "StatusWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableGameplayIntegrationComponent, StatusWidget), Z_Construct_UClass_UJMThrowableStatusWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StatusWidget_MetaData), NewProp_StatusWidget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::NewProp_InventoryContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::NewProp_Interactor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::NewProp_MappingContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::NewProp_AimAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::NewProp_ThrowAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::NewProp_CancelAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::NewProp_StatusWidget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::PropPointers) < 2048);
// ********** End Class UJMThrowableGameplayIntegrationComponent Property Definitions **************
UObject* (*const Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMThrowableGameplayIntegration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::ClassParams = {
	&UJMThrowableGameplayIntegrationComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::Class_MetaDataParams)
};
void UJMThrowableGameplayIntegrationComponent::StaticRegisterNativesUJMThrowableGameplayIntegrationComponent()
{
	UClass* Class = UJMThrowableGameplayIntegrationComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent()
{
	if (!Z_Registration_Info_UClass_UJMThrowableGameplayIntegrationComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMThrowableGameplayIntegrationComponent.OuterSingleton, Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMThrowableGameplayIntegrationComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMThrowableGameplayIntegrationComponent);
UJMThrowableGameplayIntegrationComponent::~UJMThrowableGameplayIntegrationComponent() {}
// ********** End Class UJMThrowableGameplayIntegrationComponent ***********************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableGameplayIntegrationComponent_h__Script_JMThrowableGameplayIntegration_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMThrowableGameplayIntegrationComponent, UJMThrowableGameplayIntegrationComponent::StaticClass, TEXT("UJMThrowableGameplayIntegrationComponent"), &Z_Registration_Info_UClass_UJMThrowableGameplayIntegrationComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMThrowableGameplayIntegrationComponent), 4104473959U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableGameplayIntegrationComponent_h__Script_JMThrowableGameplayIntegration_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableGameplayIntegrationComponent_h__Script_JMThrowableGameplayIntegration_2657376560{
	TEXT("/Script/JMThrowableGameplayIntegration"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableGameplayIntegrationComponent_h__Script_JMThrowableGameplayIntegration_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowableGameplayIntegration_Source_JMThrowableGameplayIntegration_Public_JMThrowableGameplayIntegrationComponent_h__Script_JMThrowableGameplayIntegration_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
