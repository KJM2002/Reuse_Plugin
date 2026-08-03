// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/JMInteractableComponent.h"
#include "GameplayTagContainer.h"
#include "Types/JMInteractionTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMInteractableComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractableComponent();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractableComponent_NoRegister();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractableInterface_NoRegister();
JMINTERACTION_API UFunction* Z_Construct_UDelegateFunction_JMInteraction_JMInteractableEvent__DelegateSignature();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionContext();
JMINTERACTION_API UScriptStruct* Z_Construct_UScriptStruct_FJMInteractionResult();
UPackage* Z_Construct_UPackage__Script_JMInteraction();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FJMInteractableEvent **************************************************
struct Z_Construct_UDelegateFunction_JMInteraction_JMInteractableEvent__DelegateSignature_Statics
{
	struct _Script_JMInteraction_eventJMInteractableEvent_Parms
	{
		FJMInteractionContext Context;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/JMInteractableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMInteractableEvent constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMInteractableEvent constinit property declarations ********************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMInteractableEvent Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_JMInteraction_JMInteractableEvent__DelegateSignature_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_JMInteraction_eventJMInteractableEvent_Parms, Context), Z_Construct_UScriptStruct_FJMInteractionContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3486038698
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMInteraction_JMInteractableEvent__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMInteraction_JMInteractableEvent__DelegateSignature_Statics::NewProp_Context,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMInteraction_JMInteractableEvent__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMInteractableEvent Property Definitions *******************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMInteraction_JMInteractableEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMInteraction, nullptr, "JMInteractableEvent__DelegateSignature", 	Z_Construct_UDelegateFunction_JMInteraction_JMInteractableEvent__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMInteraction_JMInteractableEvent__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMInteraction_JMInteractableEvent__DelegateSignature_Statics::_Script_JMInteraction_eventJMInteractableEvent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMInteraction_JMInteractableEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMInteraction_JMInteractableEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMInteraction_JMInteractableEvent__DelegateSignature_Statics::_Script_JMInteraction_eventJMInteractableEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMInteraction_JMInteractableEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMInteraction_JMInteractableEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMInteractableEvent_DelegateWrapper(const FMulticastScriptDelegate& JMInteractableEvent, FJMInteractionContext const& Context)
{
	struct _Script_JMInteraction_eventJMInteractableEvent_Parms
	{
		FJMInteractionContext Context;
	};
	_Script_JMInteraction_eventJMInteractableEvent_Parms Parms;
	Parms.Context=Context;
	JMInteractableEvent.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMInteractableEvent ****************************************************

// ********** Begin Class UJMInteractableComponent Function EvaluateCanInteract ********************
struct JMInteractableComponent_eventEvaluateCanInteract_Parms
{
	FJMInteractionContext Context;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	JMInteractableComponent_eventEvaluateCanInteract_Parms()
		: ReturnValue(false)
	{
	}
};
static FName NAME_UJMInteractableComponent_EvaluateCanInteract = FName(TEXT("EvaluateCanInteract"));
bool UJMInteractableComponent::EvaluateCanInteract(FJMInteractionContext const& Context) const
{
	UFunction* Func = FindFunctionChecked(NAME_UJMInteractableComponent_EvaluateCanInteract);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		JMInteractableComponent_eventEvaluateCanInteract_Parms Parms;
		Parms.Context=Context;
		const_cast<UJMInteractableComponent*>(this)->ProcessEvent(Func,&Parms);
		return !!Parms.ReturnValue;
	}
	else
	{
		return const_cast<UJMInteractableComponent*>(this)->EvaluateCanInteract_Implementation(Context);
	}
}
struct Z_Construct_UFunction_UJMInteractableComponent_EvaluateCanInteract_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function EvaluateCanInteract constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function EvaluateCanInteract constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function EvaluateCanInteract Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractableComponent_EvaluateCanInteract_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractableComponent_eventEvaluateCanInteract_Parms, Context), Z_Construct_UScriptStruct_FJMInteractionContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3486038698
void Z_Construct_UFunction_UJMInteractableComponent_EvaluateCanInteract_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMInteractableComponent_eventEvaluateCanInteract_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMInteractableComponent_EvaluateCanInteract_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMInteractableComponent_eventEvaluateCanInteract_Parms), &Z_Construct_UFunction_UJMInteractableComponent_EvaluateCanInteract_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractableComponent_EvaluateCanInteract_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractableComponent_EvaluateCanInteract_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractableComponent_EvaluateCanInteract_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableComponent_EvaluateCanInteract_Statics::PropPointers) < 2048);
// ********** End Function EvaluateCanInteract Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractableComponent_EvaluateCanInteract_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractableComponent, nullptr, "EvaluateCanInteract", 	Z_Construct_UFunction_UJMInteractableComponent_EvaluateCanInteract_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableComponent_EvaluateCanInteract_Statics::PropPointers), 
sizeof(JMInteractableComponent_eventEvaluateCanInteract_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableComponent_EvaluateCanInteract_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractableComponent_EvaluateCanInteract_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMInteractableComponent_eventEvaluateCanInteract_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractableComponent_EvaluateCanInteract()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractableComponent_EvaluateCanInteract_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInteractableComponent::execEvaluateCanInteract)
{
	P_GET_STRUCT_REF(FJMInteractionContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->EvaluateCanInteract_Implementation(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Class UJMInteractableComponent Function EvaluateCanInteract **********************

// ********** Begin Class UJMInteractableComponent Function HandleInteract *************************
struct JMInteractableComponent_eventHandleInteract_Parms
{
	FJMInteractionContext Context;
	FJMInteractionResult ReturnValue;
};
static FName NAME_UJMInteractableComponent_HandleInteract = FName(TEXT("HandleInteract"));
FJMInteractionResult UJMInteractableComponent::HandleInteract(FJMInteractionContext const& Context)
{
	UFunction* Func = FindFunctionChecked(NAME_UJMInteractableComponent_HandleInteract);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		JMInteractableComponent_eventHandleInteract_Parms Parms;
		Parms.Context=Context;
	ProcessEvent(Func,&Parms);
		return Parms.ReturnValue;
	}
	else
	{
		return HandleInteract_Implementation(Context);
	}
}
struct Z_Construct_UFunction_UJMInteractableComponent_HandleInteract_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleInteract constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleInteract constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleInteract Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractableComponent_HandleInteract_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractableComponent_eventHandleInteract_Parms, Context), Z_Construct_UScriptStruct_FJMInteractionContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3486038698
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMInteractableComponent_HandleInteract_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMInteractableComponent_eventHandleInteract_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMInteractionResult, METADATA_PARAMS(0, nullptr) }; // 240276497
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMInteractableComponent_HandleInteract_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractableComponent_HandleInteract_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMInteractableComponent_HandleInteract_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableComponent_HandleInteract_Statics::PropPointers) < 2048);
// ********** End Function HandleInteract Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMInteractableComponent_HandleInteract_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMInteractableComponent, nullptr, "HandleInteract", 	Z_Construct_UFunction_UJMInteractableComponent_HandleInteract_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableComponent_HandleInteract_Statics::PropPointers), 
sizeof(JMInteractableComponent_eventHandleInteract_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMInteractableComponent_HandleInteract_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMInteractableComponent_HandleInteract_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(JMInteractableComponent_eventHandleInteract_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMInteractableComponent_HandleInteract()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMInteractableComponent_HandleInteract_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMInteractableComponent::execHandleInteract)
{
	P_GET_STRUCT_REF(FJMInteractionContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMInteractionResult*)Z_Param__Result=P_THIS->HandleInteract_Implementation(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Class UJMInteractableComponent Function HandleInteract ***************************

// ********** Begin Class UJMInteractableComponent *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMInteractableComponent;
UClass* UJMInteractableComponent::GetPrivateStaticClass()
{
	using TClass = UJMInteractableComponent;
	if (!Z_Registration_Info_UClass_UJMInteractableComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMInteractableComponent"),
			Z_Registration_Info_UClass_UJMInteractableComponent.InnerSingleton,
			StaticRegisterNativesUJMInteractableComponent,
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
	return Z_Registration_Info_UClass_UJMInteractableComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMInteractableComponent_NoRegister()
{
	return UJMInteractableComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMInteractableComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JMInteraction" },
		{ "IncludePath", "Components/JMInteractableComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Components/JMInteractableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bInteractionEnabled_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionPrompt_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionTag_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionDuration_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Components/JMInteractableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionPriority_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnInteracted_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnFocused_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnUnfocused_MetaData[] = {
		{ "Category", "JM Interaction" },
		{ "ModuleRelativePath", "Public/Components/JMInteractableComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMInteractableComponent constinit property declarations *****************
	static void NewProp_bInteractionEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInteractionEnabled;
	static const UECodeGen_Private::FTextPropertyParams NewProp_InteractionPrompt;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InteractionTag;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InteractionDuration;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InteractionPriority;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInteracted;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnFocused;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnUnfocused;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMInteractableComponent constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("EvaluateCanInteract"), .Pointer = &UJMInteractableComponent::execEvaluateCanInteract },
		{ .NameUTF8 = UTF8TEXT("HandleInteract"), .Pointer = &UJMInteractableComponent::execHandleInteract },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMInteractableComponent_EvaluateCanInteract, "EvaluateCanInteract" }, // 4194082630
		{ &Z_Construct_UFunction_UJMInteractableComponent_HandleInteract, "HandleInteract" }, // 1050661982
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMInteractableComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMInteractableComponent_Statics

// ********** Begin Class UJMInteractableComponent Property Definitions ****************************
void Z_Construct_UClass_UJMInteractableComponent_Statics::NewProp_bInteractionEnabled_SetBit(void* Obj)
{
	((UJMInteractableComponent*)Obj)->bInteractionEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UJMInteractableComponent_Statics::NewProp_bInteractionEnabled = { "bInteractionEnabled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UJMInteractableComponent), &Z_Construct_UClass_UJMInteractableComponent_Statics::NewProp_bInteractionEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bInteractionEnabled_MetaData), NewProp_bInteractionEnabled_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UJMInteractableComponent_Statics::NewProp_InteractionPrompt = { "InteractionPrompt", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractableComponent, InteractionPrompt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionPrompt_MetaData), NewProp_InteractionPrompt_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMInteractableComponent_Statics::NewProp_InteractionTag = { "InteractionTag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractableComponent, InteractionTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionTag_MetaData), NewProp_InteractionTag_MetaData) }; // 517357616
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMInteractableComponent_Statics::NewProp_InteractionDuration = { "InteractionDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractableComponent, InteractionDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionDuration_MetaData), NewProp_InteractionDuration_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UJMInteractableComponent_Statics::NewProp_InteractionPriority = { "InteractionPriority", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractableComponent, InteractionPriority), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionPriority_MetaData), NewProp_InteractionPriority_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMInteractableComponent_Statics::NewProp_OnInteracted = { "OnInteracted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractableComponent, OnInteracted), Z_Construct_UDelegateFunction_JMInteraction_JMInteractableEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnInteracted_MetaData), NewProp_OnInteracted_MetaData) }; // 3812973065
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMInteractableComponent_Statics::NewProp_OnFocused = { "OnFocused", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractableComponent, OnFocused), Z_Construct_UDelegateFunction_JMInteraction_JMInteractableEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnFocused_MetaData), NewProp_OnFocused_MetaData) }; // 3812973065
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMInteractableComponent_Statics::NewProp_OnUnfocused = { "OnUnfocused", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMInteractableComponent, OnUnfocused), Z_Construct_UDelegateFunction_JMInteraction_JMInteractableEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnUnfocused_MetaData), NewProp_OnUnfocused_MetaData) }; // 3812973065
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMInteractableComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractableComponent_Statics::NewProp_bInteractionEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractableComponent_Statics::NewProp_InteractionPrompt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractableComponent_Statics::NewProp_InteractionTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractableComponent_Statics::NewProp_InteractionDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractableComponent_Statics::NewProp_InteractionPriority,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractableComponent_Statics::NewProp_OnInteracted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractableComponent_Statics::NewProp_OnFocused,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMInteractableComponent_Statics::NewProp_OnUnfocused,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractableComponent_Statics::PropPointers) < 2048);
// ********** End Class UJMInteractableComponent Property Definitions ******************************
UObject* (*const Z_Construct_UClass_UJMInteractableComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMInteraction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractableComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UJMInteractableComponent_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UJMInteractableInterface_NoRegister, (int32)VTABLE_OFFSET(UJMInteractableComponent, IJMInteractableInterface), false },  // 680874699
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMInteractableComponent_Statics::ClassParams = {
	&UJMInteractableComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMInteractableComponent_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractableComponent_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMInteractableComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMInteractableComponent_Statics::Class_MetaDataParams)
};
void UJMInteractableComponent::StaticRegisterNativesUJMInteractableComponent()
{
	UClass* Class = UJMInteractableComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMInteractableComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMInteractableComponent()
{
	if (!Z_Registration_Info_UClass_UJMInteractableComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMInteractableComponent.OuterSingleton, Z_Construct_UClass_UJMInteractableComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMInteractableComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMInteractableComponent);
UJMInteractableComponent::~UJMInteractableComponent() {}
// ********** End Class UJMInteractableComponent ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractableComponent_h__Script_JMInteraction_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMInteractableComponent, UJMInteractableComponent::StaticClass, TEXT("UJMInteractableComponent"), &Z_Registration_Info_UClass_UJMInteractableComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMInteractableComponent), 1691261066U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractableComponent_h__Script_JMInteraction_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractableComponent_h__Script_JMInteraction_1762279422{
	TEXT("/Script/JMInteraction"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractableComponent_h__Script_JMInteraction_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Components_JMInteractableComponent_h__Script_JMInteraction_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
