// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/JMReconPlayerBridgeComponent.h"
#include "Types/JMReconTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMReconPlayerBridgeComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
ENGINE_API UClass* Z_Construct_UClass_ACameraActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ENGINE_API UClass* Z_Construct_UClass_UInputComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpotLightComponent_NoRegister();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractionComponent_NoRegister();
JMRECONGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMReconPlayerBridgeComponent();
JMRECONGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMReconPlayerBridgeComponent_NoRegister();
JMRECONGAMEPLAYINTEGRATION_API UClass* Z_Construct_UClass_UJMReconPromptWidgetBase_NoRegister();
JMRECONGAMEPLAYINTEGRATION_API UFunction* Z_Construct_UDelegateFunction_JMReconGameplayIntegration_JMReconFlashlightStateChangedSignature__DelegateSignature();
JMRECONRUNTIME_API UClass* Z_Construct_UClass_UJMReconInteractorComponent_NoRegister();
JMRECONRUNTIME_API UClass* Z_Construct_UClass_UJMReconTargetComponent_NoRegister();
JMRECONRUNTIME_API UEnum* Z_Construct_UEnum_JMReconRuntime_EJMReconEndReason();
JMRECONRUNTIME_API UEnum* Z_Construct_UEnum_JMReconRuntime_EJMReconState();
JMRECONRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMReconRequestResult();
UPackage* Z_Construct_UPackage__Script_JMReconGameplayIntegration();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FJMReconFlashlightStateChangedSignature *******************************
struct Z_Construct_UDelegateFunction_JMReconGameplayIntegration_JMReconFlashlightStateChangedSignature__DelegateSignature_Statics
{
	struct _Script_JMReconGameplayIntegration_eventJMReconFlashlightStateChangedSignature_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/JMReconPlayerBridgeComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FJMReconFlashlightStateChangedSignature constinit property declarations 
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FJMReconFlashlightStateChangedSignature constinit property declarations *
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FJMReconFlashlightStateChangedSignature Property Definitions **********
void Z_Construct_UDelegateFunction_JMReconGameplayIntegration_JMReconFlashlightStateChangedSignature__DelegateSignature_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((_Script_JMReconGameplayIntegration_eventJMReconFlashlightStateChangedSignature_Parms*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_JMReconGameplayIntegration_JMReconFlashlightStateChangedSignature__DelegateSignature_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_JMReconGameplayIntegration_eventJMReconFlashlightStateChangedSignature_Parms), &Z_Construct_UDelegateFunction_JMReconGameplayIntegration_JMReconFlashlightStateChangedSignature__DelegateSignature_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_JMReconGameplayIntegration_JMReconFlashlightStateChangedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_JMReconGameplayIntegration_JMReconFlashlightStateChangedSignature__DelegateSignature_Statics::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMReconGameplayIntegration_JMReconFlashlightStateChangedSignature__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FJMReconFlashlightStateChangedSignature Property Definitions ************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_JMReconGameplayIntegration_JMReconFlashlightStateChangedSignature__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_JMReconGameplayIntegration, nullptr, "JMReconFlashlightStateChangedSignature__DelegateSignature", 	Z_Construct_UDelegateFunction_JMReconGameplayIntegration_JMReconFlashlightStateChangedSignature__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMReconGameplayIntegration_JMReconFlashlightStateChangedSignature__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_JMReconGameplayIntegration_JMReconFlashlightStateChangedSignature__DelegateSignature_Statics::_Script_JMReconGameplayIntegration_eventJMReconFlashlightStateChangedSignature_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_JMReconGameplayIntegration_JMReconFlashlightStateChangedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_JMReconGameplayIntegration_JMReconFlashlightStateChangedSignature__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_JMReconGameplayIntegration_JMReconFlashlightStateChangedSignature__DelegateSignature_Statics::_Script_JMReconGameplayIntegration_eventJMReconFlashlightStateChangedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_JMReconGameplayIntegration_JMReconFlashlightStateChangedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_JMReconGameplayIntegration_JMReconFlashlightStateChangedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FJMReconFlashlightStateChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& JMReconFlashlightStateChangedSignature, bool bEnabled)
{
	struct _Script_JMReconGameplayIntegration_eventJMReconFlashlightStateChangedSignature_Parms
	{
		bool bEnabled;
	};
	_Script_JMReconGameplayIntegration_eventJMReconFlashlightStateChangedSignature_Parms Parms;
	Parms.bEnabled=bEnabled ? true : false;
	JMReconFlashlightStateChangedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FJMReconFlashlightStateChangedSignature *********************************

// ********** Begin Class UJMReconPlayerBridgeComponent Function FindFocusedReconTarget ************
struct Z_Construct_UFunction_UJMReconPlayerBridgeComponent_FindFocusedReconTarget_Statics
{
	struct JMReconPlayerBridgeComponent_eventFindFocusedReconTarget_Parms
	{
		UJMReconTargetComponent* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Recon|Integration" },
		{ "ModuleRelativePath", "Public/Components/JMReconPlayerBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function FindFocusedReconTarget constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FindFocusedReconTarget constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FindFocusedReconTarget Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_FindFocusedReconTarget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconPlayerBridgeComponent_eventFindFocusedReconTarget_Parms, ReturnValue), Z_Construct_UClass_UJMReconTargetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconPlayerBridgeComponent_FindFocusedReconTarget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPlayerBridgeComponent_FindFocusedReconTarget_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_FindFocusedReconTarget_Statics::PropPointers) < 2048);
// ********** End Function FindFocusedReconTarget Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_FindFocusedReconTarget_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconPlayerBridgeComponent, nullptr, "FindFocusedReconTarget", 	Z_Construct_UFunction_UJMReconPlayerBridgeComponent_FindFocusedReconTarget_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_FindFocusedReconTarget_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_FindFocusedReconTarget_Statics::JMReconPlayerBridgeComponent_eventFindFocusedReconTarget_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_FindFocusedReconTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconPlayerBridgeComponent_FindFocusedReconTarget_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_FindFocusedReconTarget_Statics::JMReconPlayerBridgeComponent_eventFindFocusedReconTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconPlayerBridgeComponent_FindFocusedReconTarget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconPlayerBridgeComponent_FindFocusedReconTarget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMReconPlayerBridgeComponent::execFindFocusedReconTarget)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UJMReconTargetComponent**)Z_Param__Result=P_THIS->FindFocusedReconTarget();
	P_NATIVE_END;
}
// ********** End Class UJMReconPlayerBridgeComponent Function FindFocusedReconTarget **************

// ********** Begin Class UJMReconPlayerBridgeComponent Function HandleCameraRestoreRequested ******
struct Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraRestoreRequested_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/JMReconPlayerBridgeComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleCameraRestoreRequested constinit property declarations **********
// ********** End Function HandleCameraRestoreRequested constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraRestoreRequested_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconPlayerBridgeComponent, nullptr, "HandleCameraRestoreRequested", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraRestoreRequested_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraRestoreRequested_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraRestoreRequested()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraRestoreRequested_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMReconPlayerBridgeComponent::execHandleCameraRestoreRequested)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCameraRestoreRequested();
	P_NATIVE_END;
}
// ********** End Class UJMReconPlayerBridgeComponent Function HandleCameraRestoreRequested ********

// ********** Begin Class UJMReconPlayerBridgeComponent Function HandleCameraTransformRequested ****
struct Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraTransformRequested_Statics
{
	struct JMReconPlayerBridgeComponent_eventHandleCameraTransformRequested_Parms
	{
		FTransform WorldTransform;
		EJMReconState State;
		float BlendTime;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/JMReconPlayerBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldTransform_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleCameraTransformRequested constinit property declarations ********
	static const UECodeGen_Private::FStructPropertyParams NewProp_WorldTransform;
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BlendTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleCameraTransformRequested constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleCameraTransformRequested Property Definitions *******************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraTransformRequested_Statics::NewProp_WorldTransform = { "WorldTransform", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconPlayerBridgeComponent_eventHandleCameraTransformRequested_Parms, WorldTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldTransform_MetaData), NewProp_WorldTransform_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraTransformRequested_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraTransformRequested_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconPlayerBridgeComponent_eventHandleCameraTransformRequested_Parms, State), Z_Construct_UEnum_JMReconRuntime_EJMReconState, METADATA_PARAMS(0, nullptr) }; // 3305027711
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraTransformRequested_Statics::NewProp_BlendTime = { "BlendTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconPlayerBridgeComponent_eventHandleCameraTransformRequested_Parms, BlendTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraTransformRequested_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraTransformRequested_Statics::NewProp_WorldTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraTransformRequested_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraTransformRequested_Statics::NewProp_State,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraTransformRequested_Statics::NewProp_BlendTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraTransformRequested_Statics::PropPointers) < 2048);
// ********** End Function HandleCameraTransformRequested Property Definitions *********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraTransformRequested_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconPlayerBridgeComponent, nullptr, "HandleCameraTransformRequested", 	Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraTransformRequested_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraTransformRequested_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraTransformRequested_Statics::JMReconPlayerBridgeComponent_eventHandleCameraTransformRequested_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C40401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraTransformRequested_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraTransformRequested_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraTransformRequested_Statics::JMReconPlayerBridgeComponent_eventHandleCameraTransformRequested_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraTransformRequested()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraTransformRequested_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMReconPlayerBridgeComponent::execHandleCameraTransformRequested)
{
	P_GET_STRUCT_REF(FTransform,Z_Param_Out_WorldTransform);
	P_GET_ENUM(EJMReconState,Z_Param_State);
	P_GET_PROPERTY(FFloatProperty,Z_Param_BlendTime);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCameraTransformRequested(Z_Param_Out_WorldTransform,EJMReconState(Z_Param_State),Z_Param_BlendTime);
	P_NATIVE_END;
}
// ********** End Class UJMReconPlayerBridgeComponent Function HandleCameraTransformRequested ******

// ********** Begin Class UJMReconPlayerBridgeComponent Function HandleFocusedInteractableChanged **
struct Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleFocusedInteractableChanged_Statics
{
	struct JMReconPlayerBridgeComponent_eventHandleFocusedInteractableChanged_Parms
	{
		UObject* OldInteractable;
		UObject* NewInteractable;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/JMReconPlayerBridgeComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleFocusedInteractableChanged constinit property declarations ******
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OldInteractable;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NewInteractable;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleFocusedInteractableChanged constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleFocusedInteractableChanged Property Definitions *****************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleFocusedInteractableChanged_Statics::NewProp_OldInteractable = { "OldInteractable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconPlayerBridgeComponent_eventHandleFocusedInteractableChanged_Parms, OldInteractable), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleFocusedInteractableChanged_Statics::NewProp_NewInteractable = { "NewInteractable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconPlayerBridgeComponent_eventHandleFocusedInteractableChanged_Parms, NewInteractable), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleFocusedInteractableChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleFocusedInteractableChanged_Statics::NewProp_OldInteractable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleFocusedInteractableChanged_Statics::NewProp_NewInteractable,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleFocusedInteractableChanged_Statics::PropPointers) < 2048);
// ********** End Function HandleFocusedInteractableChanged Property Definitions *******************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleFocusedInteractableChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconPlayerBridgeComponent, nullptr, "HandleFocusedInteractableChanged", 	Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleFocusedInteractableChanged_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleFocusedInteractableChanged_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleFocusedInteractableChanged_Statics::JMReconPlayerBridgeComponent_eventHandleFocusedInteractableChanged_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleFocusedInteractableChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleFocusedInteractableChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleFocusedInteractableChanged_Statics::JMReconPlayerBridgeComponent_eventHandleFocusedInteractableChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleFocusedInteractableChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleFocusedInteractableChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMReconPlayerBridgeComponent::execHandleFocusedInteractableChanged)
{
	P_GET_OBJECT(UObject,Z_Param_OldInteractable);
	P_GET_OBJECT(UObject,Z_Param_NewInteractable);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleFocusedInteractableChanged(Z_Param_OldInteractable,Z_Param_NewInteractable);
	P_NATIVE_END;
}
// ********** End Class UJMReconPlayerBridgeComponent Function HandleFocusedInteractableChanged ****

// ********** Begin Class UJMReconPlayerBridgeComponent Function HandleIlluminateRequested *********
struct Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleIlluminateRequested_Statics
{
	struct JMReconPlayerBridgeComponent_eventHandleIlluminateRequested_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/JMReconPlayerBridgeComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleIlluminateRequested constinit property declarations *************
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleIlluminateRequested constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleIlluminateRequested Property Definitions ************************
void Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleIlluminateRequested_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((JMReconPlayerBridgeComponent_eventHandleIlluminateRequested_Parms*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleIlluminateRequested_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMReconPlayerBridgeComponent_eventHandleIlluminateRequested_Parms), &Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleIlluminateRequested_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleIlluminateRequested_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleIlluminateRequested_Statics::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleIlluminateRequested_Statics::PropPointers) < 2048);
// ********** End Function HandleIlluminateRequested Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleIlluminateRequested_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconPlayerBridgeComponent, nullptr, "HandleIlluminateRequested", 	Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleIlluminateRequested_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleIlluminateRequested_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleIlluminateRequested_Statics::JMReconPlayerBridgeComponent_eventHandleIlluminateRequested_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleIlluminateRequested_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleIlluminateRequested_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleIlluminateRequested_Statics::JMReconPlayerBridgeComponent_eventHandleIlluminateRequested_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleIlluminateRequested()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleIlluminateRequested_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMReconPlayerBridgeComponent::execHandleIlluminateRequested)
{
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleIlluminateRequested(Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class UJMReconPlayerBridgeComponent Function HandleIlluminateRequested ***********

// ********** Begin Class UJMReconPlayerBridgeComponent Function HandleSessionEnded ****************
struct Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionEnded_Statics
{
	struct JMReconPlayerBridgeComponent_eventHandleSessionEnded_Parms
	{
		FGuid SessionId;
		EJMReconEndReason Reason;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/JMReconPlayerBridgeComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSessionEnded constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SessionId;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Reason_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Reason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleSessionEnded constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleSessionEnded Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionEnded_Statics::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconPlayerBridgeComponent_eventHandleSessionEnded_Parms, SessionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionEnded_Statics::NewProp_Reason_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionEnded_Statics::NewProp_Reason = { "Reason", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconPlayerBridgeComponent_eventHandleSessionEnded_Parms, Reason), Z_Construct_UEnum_JMReconRuntime_EJMReconEndReason, METADATA_PARAMS(0, nullptr) }; // 3838439290
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionEnded_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionEnded_Statics::NewProp_SessionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionEnded_Statics::NewProp_Reason_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionEnded_Statics::NewProp_Reason,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionEnded_Statics::PropPointers) < 2048);
// ********** End Function HandleSessionEnded Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionEnded_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconPlayerBridgeComponent, nullptr, "HandleSessionEnded", 	Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionEnded_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionEnded_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionEnded_Statics::JMReconPlayerBridgeComponent_eventHandleSessionEnded_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionEnded_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionEnded_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionEnded_Statics::JMReconPlayerBridgeComponent_eventHandleSessionEnded_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionEnded()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionEnded_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMReconPlayerBridgeComponent::execHandleSessionEnded)
{
	P_GET_STRUCT(FGuid,Z_Param_SessionId);
	P_GET_ENUM(EJMReconEndReason,Z_Param_Reason);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSessionEnded(Z_Param_SessionId,EJMReconEndReason(Z_Param_Reason));
	P_NATIVE_END;
}
// ********** End Class UJMReconPlayerBridgeComponent Function HandleSessionEnded ******************

// ********** Begin Class UJMReconPlayerBridgeComponent Function HandleSessionStarted **************
struct Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionStarted_Statics
{
	struct JMReconPlayerBridgeComponent_eventHandleSessionStarted_Parms
	{
		FGuid SessionId;
		UJMReconTargetComponent* Target;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/JMReconPlayerBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleSessionStarted constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SessionId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleSessionStarted constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleSessionStarted Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionStarted_Statics::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconPlayerBridgeComponent_eventHandleSessionStarted_Parms, SessionId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionStarted_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconPlayerBridgeComponent_eventHandleSessionStarted_Parms, Target), Z_Construct_UClass_UJMReconTargetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Target_MetaData), NewProp_Target_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionStarted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionStarted_Statics::NewProp_SessionId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionStarted_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionStarted_Statics::PropPointers) < 2048);
// ********** End Function HandleSessionStarted Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionStarted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconPlayerBridgeComponent, nullptr, "HandleSessionStarted", 	Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionStarted_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionStarted_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionStarted_Statics::JMReconPlayerBridgeComponent_eventHandleSessionStarted_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionStarted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionStarted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionStarted_Statics::JMReconPlayerBridgeComponent_eventHandleSessionStarted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionStarted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionStarted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMReconPlayerBridgeComponent::execHandleSessionStarted)
{
	P_GET_STRUCT(FGuid,Z_Param_SessionId);
	P_GET_OBJECT(UJMReconTargetComponent,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSessionStarted(Z_Param_SessionId,Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UJMReconPlayerBridgeComponent Function HandleSessionStarted ****************

// ********** Begin Class UJMReconPlayerBridgeComponent Function HandleStateChanged ****************
struct Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleStateChanged_Statics
{
	struct JMReconPlayerBridgeComponent_eventHandleStateChanged_Parms
	{
		EJMReconState OldState;
		EJMReconState NewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/JMReconPlayerBridgeComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleStateChanged constinit property declarations ********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_OldState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OldState;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleStateChanged constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleStateChanged Property Definitions *******************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleStateChanged_Statics::NewProp_OldState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleStateChanged_Statics::NewProp_OldState = { "OldState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconPlayerBridgeComponent_eventHandleStateChanged_Parms, OldState), Z_Construct_UEnum_JMReconRuntime_EJMReconState, METADATA_PARAMS(0, nullptr) }; // 3305027711
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleStateChanged_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleStateChanged_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconPlayerBridgeComponent_eventHandleStateChanged_Parms, NewState), Z_Construct_UEnum_JMReconRuntime_EJMReconState, METADATA_PARAMS(0, nullptr) }; // 3305027711
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleStateChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleStateChanged_Statics::NewProp_OldState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleStateChanged_Statics::NewProp_OldState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleStateChanged_Statics::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleStateChanged_Statics::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleStateChanged_Statics::PropPointers) < 2048);
// ********** End Function HandleStateChanged Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleStateChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconPlayerBridgeComponent, nullptr, "HandleStateChanged", 	Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleStateChanged_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleStateChanged_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleStateChanged_Statics::JMReconPlayerBridgeComponent_eventHandleStateChanged_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleStateChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleStateChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleStateChanged_Statics::JMReconPlayerBridgeComponent_eventHandleStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleStateChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleStateChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMReconPlayerBridgeComponent::execHandleStateChanged)
{
	P_GET_ENUM(EJMReconState,Z_Param_OldState);
	P_GET_ENUM(EJMReconState,Z_Param_NewState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleStateChanged(EJMReconState(Z_Param_OldState),EJMReconState(Z_Param_NewState));
	P_NATIVE_END;
}
// ********** End Class UJMReconPlayerBridgeComponent Function HandleStateChanged ******************

// ********** Begin Class UJMReconPlayerBridgeComponent Function TryStartReconFromFocusedTarget ****
struct Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconFromFocusedTarget_Statics
{
	struct JMReconPlayerBridgeComponent_eventTryStartReconFromFocusedTarget_Parms
	{
		FJMReconRequestResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Recon|Integration" },
		{ "ModuleRelativePath", "Public/Components/JMReconPlayerBridgeComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function TryStartReconFromFocusedTarget constinit property declarations ********
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TryStartReconFromFocusedTarget constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TryStartReconFromFocusedTarget Property Definitions *******************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconFromFocusedTarget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconPlayerBridgeComponent_eventTryStartReconFromFocusedTarget_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMReconRequestResult, METADATA_PARAMS(0, nullptr) }; // 1431610246
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconFromFocusedTarget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconFromFocusedTarget_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconFromFocusedTarget_Statics::PropPointers) < 2048);
// ********** End Function TryStartReconFromFocusedTarget Property Definitions *********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconFromFocusedTarget_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconPlayerBridgeComponent, nullptr, "TryStartReconFromFocusedTarget", 	Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconFromFocusedTarget_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconFromFocusedTarget_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconFromFocusedTarget_Statics::JMReconPlayerBridgeComponent_eventTryStartReconFromFocusedTarget_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconFromFocusedTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconFromFocusedTarget_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconFromFocusedTarget_Statics::JMReconPlayerBridgeComponent_eventTryStartReconFromFocusedTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconFromFocusedTarget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconFromFocusedTarget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMReconPlayerBridgeComponent::execTryStartReconFromFocusedTarget)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMReconRequestResult*)Z_Param__Result=P_THIS->TryStartReconFromFocusedTarget();
	P_NATIVE_END;
}
// ********** End Class UJMReconPlayerBridgeComponent Function TryStartReconFromFocusedTarget ******

// ********** Begin Class UJMReconPlayerBridgeComponent Function TryStartReconWithTarget ***********
struct Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconWithTarget_Statics
{
	struct JMReconPlayerBridgeComponent_eventTryStartReconWithTarget_Parms
	{
		UJMReconTargetComponent* Target;
		FJMReconRequestResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Recon|Integration" },
		{ "ModuleRelativePath", "Public/Components/JMReconPlayerBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function TryStartReconWithTarget constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TryStartReconWithTarget constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TryStartReconWithTarget Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconWithTarget_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconPlayerBridgeComponent_eventTryStartReconWithTarget_Parms, Target), Z_Construct_UClass_UJMReconTargetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Target_MetaData), NewProp_Target_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconWithTarget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMReconPlayerBridgeComponent_eventTryStartReconWithTarget_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMReconRequestResult, METADATA_PARAMS(0, nullptr) }; // 1431610246
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconWithTarget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconWithTarget_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconWithTarget_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconWithTarget_Statics::PropPointers) < 2048);
// ********** End Function TryStartReconWithTarget Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconWithTarget_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMReconPlayerBridgeComponent, nullptr, "TryStartReconWithTarget", 	Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconWithTarget_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconWithTarget_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconWithTarget_Statics::JMReconPlayerBridgeComponent_eventTryStartReconWithTarget_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconWithTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconWithTarget_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconWithTarget_Statics::JMReconPlayerBridgeComponent_eventTryStartReconWithTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconWithTarget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconWithTarget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMReconPlayerBridgeComponent::execTryStartReconWithTarget)
{
	P_GET_OBJECT(UJMReconTargetComponent,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMReconRequestResult*)Z_Param__Result=P_THIS->TryStartReconWithTarget(Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UJMReconPlayerBridgeComponent Function TryStartReconWithTarget *************

// ********** Begin Class UJMReconPlayerBridgeComponent ********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMReconPlayerBridgeComponent;
UClass* UJMReconPlayerBridgeComponent::GetPrivateStaticClass()
{
	using TClass = UJMReconPlayerBridgeComponent;
	if (!Z_Registration_Info_UClass_UJMReconPlayerBridgeComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMReconPlayerBridgeComponent"),
			Z_Registration_Info_UClass_UJMReconPlayerBridgeComponent.InnerSingleton,
			StaticRegisterNativesUJMReconPlayerBridgeComponent,
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
	return Z_Registration_Info_UClass_UJMReconPlayerBridgeComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMReconPlayerBridgeComponent_NoRegister()
{
	return UJMReconPlayerBridgeComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JM" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Consumer-side bridge that reuses JMInteraction focus, binds the project's\n * default Recon keys, and applies camera requests without Blueprint glue.\n */" },
#endif
		{ "IncludePath", "Components/JMReconPlayerBridgeComponent.h" },
		{ "ModuleRelativePath", "Public/Components/JMReconPlayerBridgeComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Consumer-side bridge that reuses JMInteraction focus, binds the project's\ndefault Recon keys, and applies camera requests without Blueprint glue." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnFlashlightStateChanged_MetaData[] = {
		{ "Category", "JM Recon|Integration" },
		{ "ModuleRelativePath", "Public/Components/JMReconPlayerBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Components/JMReconPlayerBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReconInteractor_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Components/JMReconPlayerBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReconCameraActor_MetaData[] = {
		{ "ModuleRelativePath", "Public/Components/JMReconPlayerBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReconIlluminateLight_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Components/JMReconPlayerBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReconPromptWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Components/JMReconPlayerBridgeComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReconInputComponent_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Separate high-priority input layer so Recon can exclusively own its flashlight key. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Components/JMReconPlayerBridgeComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Separate high-priority input layer so Recon can exclusively own its flashlight key." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UJMReconPlayerBridgeComponent constinit property declarations ************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnFlashlightStateChanged;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InteractionComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReconInteractor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReconCameraActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReconIlluminateLight;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReconPromptWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReconInputComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMReconPlayerBridgeComponent constinit property declarations **************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("FindFocusedReconTarget"), .Pointer = &UJMReconPlayerBridgeComponent::execFindFocusedReconTarget },
		{ .NameUTF8 = UTF8TEXT("HandleCameraRestoreRequested"), .Pointer = &UJMReconPlayerBridgeComponent::execHandleCameraRestoreRequested },
		{ .NameUTF8 = UTF8TEXT("HandleCameraTransformRequested"), .Pointer = &UJMReconPlayerBridgeComponent::execHandleCameraTransformRequested },
		{ .NameUTF8 = UTF8TEXT("HandleFocusedInteractableChanged"), .Pointer = &UJMReconPlayerBridgeComponent::execHandleFocusedInteractableChanged },
		{ .NameUTF8 = UTF8TEXT("HandleIlluminateRequested"), .Pointer = &UJMReconPlayerBridgeComponent::execHandleIlluminateRequested },
		{ .NameUTF8 = UTF8TEXT("HandleSessionEnded"), .Pointer = &UJMReconPlayerBridgeComponent::execHandleSessionEnded },
		{ .NameUTF8 = UTF8TEXT("HandleSessionStarted"), .Pointer = &UJMReconPlayerBridgeComponent::execHandleSessionStarted },
		{ .NameUTF8 = UTF8TEXT("HandleStateChanged"), .Pointer = &UJMReconPlayerBridgeComponent::execHandleStateChanged },
		{ .NameUTF8 = UTF8TEXT("TryStartReconFromFocusedTarget"), .Pointer = &UJMReconPlayerBridgeComponent::execTryStartReconFromFocusedTarget },
		{ .NameUTF8 = UTF8TEXT("TryStartReconWithTarget"), .Pointer = &UJMReconPlayerBridgeComponent::execTryStartReconWithTarget },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMReconPlayerBridgeComponent_FindFocusedReconTarget, "FindFocusedReconTarget" }, // 707847084
		{ &Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraRestoreRequested, "HandleCameraRestoreRequested" }, // 2049775306
		{ &Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleCameraTransformRequested, "HandleCameraTransformRequested" }, // 1759208566
		{ &Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleFocusedInteractableChanged, "HandleFocusedInteractableChanged" }, // 3081024364
		{ &Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleIlluminateRequested, "HandleIlluminateRequested" }, // 2498472753
		{ &Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionEnded, "HandleSessionEnded" }, // 2473084048
		{ &Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleSessionStarted, "HandleSessionStarted" }, // 1062108790
		{ &Z_Construct_UFunction_UJMReconPlayerBridgeComponent_HandleStateChanged, "HandleStateChanged" }, // 3319475566
		{ &Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconFromFocusedTarget, "TryStartReconFromFocusedTarget" }, // 229175015
		{ &Z_Construct_UFunction_UJMReconPlayerBridgeComponent_TryStartReconWithTarget, "TryStartReconWithTarget" }, // 3699958223
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMReconPlayerBridgeComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics

// ********** Begin Class UJMReconPlayerBridgeComponent Property Definitions ***********************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::NewProp_OnFlashlightStateChanged = { "OnFlashlightStateChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconPlayerBridgeComponent, OnFlashlightStateChanged), Z_Construct_UDelegateFunction_JMReconGameplayIntegration_JMReconFlashlightStateChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnFlashlightStateChanged_MetaData), NewProp_OnFlashlightStateChanged_MetaData) }; // 1886724127
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::NewProp_InteractionComponent = { "InteractionComponent", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconPlayerBridgeComponent, InteractionComponent), Z_Construct_UClass_UJMInteractionComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionComponent_MetaData), NewProp_InteractionComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::NewProp_ReconInteractor = { "ReconInteractor", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconPlayerBridgeComponent, ReconInteractor), Z_Construct_UClass_UJMReconInteractorComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReconInteractor_MetaData), NewProp_ReconInteractor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::NewProp_ReconCameraActor = { "ReconCameraActor", nullptr, (EPropertyFlags)0x0144000000002000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconPlayerBridgeComponent, ReconCameraActor), Z_Construct_UClass_ACameraActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReconCameraActor_MetaData), NewProp_ReconCameraActor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::NewProp_ReconIlluminateLight = { "ReconIlluminateLight", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconPlayerBridgeComponent, ReconIlluminateLight), Z_Construct_UClass_USpotLightComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReconIlluminateLight_MetaData), NewProp_ReconIlluminateLight_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::NewProp_ReconPromptWidget = { "ReconPromptWidget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconPlayerBridgeComponent, ReconPromptWidget), Z_Construct_UClass_UJMReconPromptWidgetBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReconPromptWidget_MetaData), NewProp_ReconPromptWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::NewProp_ReconInputComponent = { "ReconInputComponent", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMReconPlayerBridgeComponent, ReconInputComponent), Z_Construct_UClass_UInputComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReconInputComponent_MetaData), NewProp_ReconInputComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::NewProp_OnFlashlightStateChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::NewProp_InteractionComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::NewProp_ReconInteractor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::NewProp_ReconCameraActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::NewProp_ReconIlluminateLight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::NewProp_ReconPromptWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::NewProp_ReconInputComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::PropPointers) < 2048);
// ********** End Class UJMReconPlayerBridgeComponent Property Definitions *************************
UObject* (*const Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMReconGameplayIntegration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::ClassParams = {
	&UJMReconPlayerBridgeComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::Class_MetaDataParams)
};
void UJMReconPlayerBridgeComponent::StaticRegisterNativesUJMReconPlayerBridgeComponent()
{
	UClass* Class = UJMReconPlayerBridgeComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMReconPlayerBridgeComponent()
{
	if (!Z_Registration_Info_UClass_UJMReconPlayerBridgeComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMReconPlayerBridgeComponent.OuterSingleton, Z_Construct_UClass_UJMReconPlayerBridgeComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMReconPlayerBridgeComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMReconPlayerBridgeComponent);
UJMReconPlayerBridgeComponent::~UJMReconPlayerBridgeComponent() {}
// ********** End Class UJMReconPlayerBridgeComponent **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Components_JMReconPlayerBridgeComponent_h__Script_JMReconGameplayIntegration_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMReconPlayerBridgeComponent, UJMReconPlayerBridgeComponent::StaticClass, TEXT("UJMReconPlayerBridgeComponent"), &Z_Registration_Info_UClass_UJMReconPlayerBridgeComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMReconPlayerBridgeComponent), 1341983555U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Components_JMReconPlayerBridgeComponent_h__Script_JMReconGameplayIntegration_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Components_JMReconPlayerBridgeComponent_h__Script_JMReconGameplayIntegration_2475363868{
	TEXT("/Script/JMReconGameplayIntegration"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Components_JMReconPlayerBridgeComponent_h__Script_JMReconGameplayIntegration_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMReconGameplayIntegration_Source_JMReconGameplayIntegration_Public_Components_JMReconPlayerBridgeComponent_h__Script_JMReconGameplayIntegration_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
