// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ItemInspection/JMInspectableComponent.h"
#include "Types/JMInteractionTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMInspectableComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMInspectableComponent();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMInspectableComponent_NoRegister();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMItemInspectionData_NoRegister();
ITEMINSPECTORRUNTIME_API UFunction* Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMInspectableInspectionEvent__DelegateSignature();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractableInterface_NoRegister();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionContext();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionResult();
UPackage* Z_Construct_UPackage__Script_ItemInspectorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FJMInspectableInspectionEvent *****************************************
struct Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMInspectableInspectionEvent__DelegateSignature_Statics
{
	struct _Script_ItemInspectorRuntime_eventJMInspectableInspectionEvent_Parms
	{
		UJMItemInspectionData* InspectionData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ItemInspection/JMInspectableComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMInspectableInspectionEvent constinit property declarations *********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InspectionData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMInspectableInspectionEvent constinit property declarations ***********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMInspectableInspectionEvent Property Definitions ********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMInspectableInspectionEvent__DelegateSignature_Statics::NewProp_InspectionData = { "InspectionData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ItemInspectorRuntime_eventJMInspectableInspectionEvent_Parms, InspectionData), Z_Construct_UClass_UJMItemInspectionData_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMInspectableInspectionEvent__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMInspectableInspectionEvent__DelegateSignature_Statics::NewProp_InspectionData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMInspectableInspectionEvent__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMInspectableInspectionEvent Property Definitions **********************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMInspectableInspectionEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_ItemInspectorRuntime, nullptr, "JMInspectableInspectionEvent__DelegateSignature", 	Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMInspectableInspectionEvent__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMInspectableInspectionEvent__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMInspectableInspectionEvent__DelegateSignature_Statics::_Script_ItemInspectorRuntime_eventJMInspectableInspectionEvent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMInspectableInspectionEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMInspectableInspectionEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMInspectableInspectionEvent__DelegateSignature_Statics::_Script_ItemInspectorRuntime_eventJMInspectableInspectionEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMInspectableInspectionEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMInspectableInspectionEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMInspectableInspectionEvent_DelegateWrapper(const FMulticastScriptDelegate& JMInspectableInspectionEvent, UJMItemInspectionData* InspectionData)
{
	struct _Script_ItemInspectorRuntime_eventJMInspectableInspectionEvent_Parms
	{
		UJMItemInspectionData* InspectionData;
	};
	_Script_ItemInspectorRuntime_eventJMInspectableInspectionEvent_Parms Parms;
	Parms.InspectionData=InspectionData;
	JMInspectableInspectionEvent.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMInspectableInspectionEvent *******************************************

// ********** Begin Class UJMInspectableComponent Function CanInspect ******************************
struct JMInspectableComponent_eventCanInspect_Parms
{
	FJMInteractionContext Context;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	JMInspectableComponent_eventCanInspect_Parms()
		: ReturnValue(false)
	{
	}
};
static FName NAME_UJMInspectableComponent_CanInspect = FName(TEXT("CanInspect"));
bool UJMInspectableComponent::CanInspect(FJMInteractionContext const& Context) const
{
	UFunction* Func = FindFunctionChecked(NAME_UJMInspectableComponent_CanInspect);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		JMInspectableComponent_eventCanInspect_Parms Parms;
		Parms.Context=Context;
		const_cast<UJMInspectableComponent*>(this)->ProcessEvent(Func,&Parms);
		return !!Parms.ReturnValue;
	}
	else
	{
		return const_cast<UJMInspectableComponent*>(this)->CanInspect_Implementation(Context);
	}
}
struct Z_Construct_UFunction_UJMInspectableComponent_CanInspect_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMInspectableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CanInspect constinit property declarations ****************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CanInspect constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CanInspect Property Definitions ***************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInspectableComponent_CanInspect_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInspectableComponent_eventCanInspect_Parms, Context), Z_Construct_UScriptStruct_FJMInteractionContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3486038698
void Z_Construct_UFunction_UJMInspectableComponent_CanInspect_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMInspectableComponent_eventCanInspect_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMInspectableComponent_CanInspect_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMInspectableComponent_eventCanInspect_Parms), &Z_Construct_UFunction_UJMInspectableComponent_CanInspect_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInspectableComponent_CanInspect_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInspectableComponent_CanInspect_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInspectableComponent_CanInspect_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInspectableComponent_CanInspect_Statics::PropPointers) < 2048);
// ********** End Function CanInspect Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInspectableComponent_CanInspect_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInspectableComponent, nullptr, "CanInspect", 	Z_Construct_UFunction_UJMInspectableComponent_CanInspect_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInspectableComponent_CanInspect_Statics::PropPointers), 
sizeof(JMInspectableComponent_eventCanInspect_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInspectableComponent_CanInspect_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInspectableComponent_CanInspect_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMInspectableComponent_eventCanInspect_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInspectableComponent_CanInspect()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInspectableComponent_CanInspect_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInspectableComponent::execCanInspect)
{
	P_GET_STRUCT_REF(FJMInteractionContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanInspect_Implementation(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Class UJMInspectableComponent Function CanInspect ********************************

// ********** Begin Class UJMInspectableComponent Function TryOpenInspection ***********************
struct Z_Construct_UFunction_UJMInspectableComponent_TryOpenInspection_Statics
{
	struct JMInspectableComponent_eventTryOpenInspection_Parms
	{
		FJMInteractionContext Context;
		FJMInteractionResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMInspectableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function TryOpenInspection constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TryOpenInspection constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TryOpenInspection Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInspectableComponent_TryOpenInspection_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInspectableComponent_eventTryOpenInspection_Parms, Context), Z_Construct_UScriptStruct_FJMInteractionContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3486038698
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInspectableComponent_TryOpenInspection_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInspectableComponent_eventTryOpenInspection_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMInteractionResult, METADATA_PARAMS(0, nullptr) }; // 240276497
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInspectableComponent_TryOpenInspection_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInspectableComponent_TryOpenInspection_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInspectableComponent_TryOpenInspection_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInspectableComponent_TryOpenInspection_Statics::PropPointers) < 2048);
// ********** End Function TryOpenInspection Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInspectableComponent_TryOpenInspection_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInspectableComponent, nullptr, "TryOpenInspection", 	Z_Construct_UFunction_UJMInspectableComponent_TryOpenInspection_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInspectableComponent_TryOpenInspection_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMInspectableComponent_TryOpenInspection_Statics::JMInspectableComponent_eventTryOpenInspection_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInspectableComponent_TryOpenInspection_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInspectableComponent_TryOpenInspection_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMInspectableComponent_TryOpenInspection_Statics::JMInspectableComponent_eventTryOpenInspection_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInspectableComponent_TryOpenInspection()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInspectableComponent_TryOpenInspection_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInspectableComponent::execTryOpenInspection)
{
	P_GET_STRUCT_REF(FJMInteractionContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMInteractionResult*)Z_Param__Result=P_THIS->TryOpenInspection(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Class UJMInspectableComponent Function TryOpenInspection *************************

// ********** Begin Class UJMInspectableComponent **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMInspectableComponent;
UClass* UJMInspectableComponent::GetPrivateStaticClass()
{
	using TClass = UJMInspectableComponent;
	if (!Z_Registration_Info_UClass_UJMInspectableComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMInspectableComponent"),
			Z_Registration_Info_UClass_UJMInspectableComponent.InnerSingleton,
			StaticRegisterNativesUJMInspectableComponent,
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
	return Z_Registration_Info_UClass_UJMInspectableComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMInspectableComponent_NoRegister()
{
	return UJMInspectableComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMInspectableComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "JMGameplay" },
		{ "IncludePath", "ItemInspection/JMInspectableComponent.h" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMInspectableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InspectionData_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMInspectableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bInspectionEnabled_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMInspectableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPauseGameDuringInspection_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMInspectableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bBlockPlayerInputDuringInspection_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMInspectableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHideSourceActorDuringInspection_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMInspectableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PromptText_MetaData[] = {
		{ "Category", "JM Gameplay|Interaction" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMInspectableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionPriority_MetaData[] = {
		{ "Category", "JM Gameplay|Interaction" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMInspectableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnInspectionRequested_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMInspectableComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMInspectableComponent constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InspectionData;
	static void NewProp_bInspectionEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInspectionEnabled;
	static void NewProp_bPauseGameDuringInspection_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPauseGameDuringInspection;
	static void NewProp_bBlockPlayerInputDuringInspection_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bBlockPlayerInputDuringInspection;
	static void NewProp_bHideSourceActorDuringInspection_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHideSourceActorDuringInspection;
	static const UECodeGen_Private::FTextPropertyParams NewProp_PromptText;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InteractionPriority;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInspectionRequested;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMInspectableComponent constinit property declarations ********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CanInspect"), .Pointer = &UJMInspectableComponent::execCanInspect },
		{ .NameUTF8 = UTF8TEXT("TryOpenInspection"), .Pointer = &UJMInspectableComponent::execTryOpenInspection },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMInspectableComponent_CanInspect, "CanInspect" }, // 1499944800
		{ &Z_Construct_UFunction_UJMInspectableComponent_TryOpenInspection, "TryOpenInspection" }, // 809079610
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMInspectableComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMInspectableComponent_Statics

// ********** Begin Class UJMInspectableComponent Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_InspectionData = { "InspectionData", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInspectableComponent, InspectionData), Z_Construct_UClass_UJMItemInspectionData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InspectionData_MetaData), NewProp_InspectionData_MetaData) };
void Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_bInspectionEnabled_SetBit(void* Obj)
{
	((UJMInspectableComponent*)Obj)->bInspectionEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_bInspectionEnabled = { "bInspectionEnabled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMInspectableComponent), &Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_bInspectionEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bInspectionEnabled_MetaData), NewProp_bInspectionEnabled_MetaData) };
void Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_bPauseGameDuringInspection_SetBit(void* Obj)
{
	((UJMInspectableComponent*)Obj)->bPauseGameDuringInspection = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_bPauseGameDuringInspection = { "bPauseGameDuringInspection", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMInspectableComponent), &Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_bPauseGameDuringInspection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPauseGameDuringInspection_MetaData), NewProp_bPauseGameDuringInspection_MetaData) };
void Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_bBlockPlayerInputDuringInspection_SetBit(void* Obj)
{
	((UJMInspectableComponent*)Obj)->bBlockPlayerInputDuringInspection = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_bBlockPlayerInputDuringInspection = { "bBlockPlayerInputDuringInspection", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMInspectableComponent), &Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_bBlockPlayerInputDuringInspection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bBlockPlayerInputDuringInspection_MetaData), NewProp_bBlockPlayerInputDuringInspection_MetaData) };
void Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_bHideSourceActorDuringInspection_SetBit(void* Obj)
{
	((UJMInspectableComponent*)Obj)->bHideSourceActorDuringInspection = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_bHideSourceActorDuringInspection = { "bHideSourceActorDuringInspection", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMInspectableComponent), &Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_bHideSourceActorDuringInspection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHideSourceActorDuringInspection_MetaData), NewProp_bHideSourceActorDuringInspection_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_PromptText = { "PromptText", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInspectableComponent, PromptText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PromptText_MetaData), NewProp_PromptText_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_InteractionPriority = { "InteractionPriority", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInspectableComponent, InteractionPriority), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionPriority_MetaData), NewProp_InteractionPriority_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_OnInspectionRequested = { "OnInspectionRequested", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInspectableComponent, OnInspectionRequested), Z_Construct_UDelegateFunction_ItemInspectorRuntime_JMInspectableInspectionEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnInspectionRequested_MetaData), NewProp_OnInspectionRequested_MetaData) }; // 3519604406
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMInspectableComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_InspectionData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_bInspectionEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_bPauseGameDuringInspection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_bBlockPlayerInputDuringInspection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_bHideSourceActorDuringInspection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_PromptText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_InteractionPriority,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInspectableComponent_Statics::NewProp_OnInspectionRequested,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInspectableComponent_Statics::PropPointers) < 2048);
// ********** End Class UJMInspectableComponent Property Definitions *******************************
UObject* (*const Z_Construct_UClass_UJMInspectableComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_ItemInspectorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInspectableComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UJMInspectableComponent_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UJMInteractableInterface_NoRegister, (int32)VTABLE_OFFSET(UJMInspectableComponent, IJMInteractableInterface), false },  // 680874699
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMInspectableComponent_Statics::ClassParams = {
	&UJMInspectableComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMInspectableComponent_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMInspectableComponent_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInspectableComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMInspectableComponent_Statics::Class_MetaDataParams)
};
void UJMInspectableComponent::StaticRegisterNativesUJMInspectableComponent()
{
	UClass* Class = UJMInspectableComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMInspectableComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMInspectableComponent()
{
	if (!Z_Registration_Info_UClass_UJMInspectableComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMInspectableComponent.OuterSingleton, Z_Construct_UClass_UJMInspectableComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMInspectableComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMInspectableComponent);
UJMInspectableComponent::~UJMInspectableComponent() {}
// ********** End Class UJMInspectableComponent ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMInspectableComponent_h__Script_ItemInspectorRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMInspectableComponent, UJMInspectableComponent::StaticClass, TEXT("UJMInspectableComponent"), &Z_Registration_Info_UClass_UJMInspectableComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMInspectableComponent), 3419407082U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMInspectableComponent_h__Script_ItemInspectorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMInspectableComponent_h__Script_ItemInspectorRuntime_820702558{
	TEXT("/Script/ItemInspectorRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMInspectableComponent_h__Script_ItemInspectorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMInspectableComponent_h__Script_ItemInspectorRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
