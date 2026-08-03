// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/JMDoorReconTargetAdapterComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMDoorReconTargetAdapterComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
JMDOORRECONINTEGRATION_API UClass* Z_Construct_UClass_UJMDoorReconTargetAdapterComponent();
JMDOORRECONINTEGRATION_API UClass* Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_NoRegister();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorComponent_NoRegister();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorState();
JMRECONRUNTIME_API UClass* Z_Construct_UClass_UJMReconTarget_NoRegister();
JMRECONRUNTIME_API UClass* Z_Construct_UClass_UJMReconTargetComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMDoorReconIntegration();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMDoorReconTargetAdapterComponent Function HandleDoorStateChanged *******
struct Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_HandleDoorStateChanged_Statics
{
	struct JMDoorReconTargetAdapterComponent_eventHandleDoorStateChanged_Parms
	{
		EJMDoorState OldState;
		EJMDoorState NewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Components/JMDoorReconTargetAdapterComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleDoorStateChanged constinit property declarations ****************
	static const UECodeGen_Private::FBytePropertyParams NewProp_OldState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OldState;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleDoorStateChanged constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleDoorStateChanged Property Definitions ***************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_HandleDoorStateChanged_Statics::NewProp_OldState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_HandleDoorStateChanged_Statics::NewProp_OldState = { "OldState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorReconTargetAdapterComponent_eventHandleDoorStateChanged_Parms, OldState), Z_Construct_UEnum_JMDoorRuntime_EJMDoorState, METADATA_PARAMS(0, nullptr) }; // 2513049645
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_HandleDoorStateChanged_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_HandleDoorStateChanged_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMDoorReconTargetAdapterComponent_eventHandleDoorStateChanged_Parms, NewState), Z_Construct_UEnum_JMDoorRuntime_EJMDoorState, METADATA_PARAMS(0, nullptr) }; // 2513049645
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_HandleDoorStateChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_HandleDoorStateChanged_Statics::NewProp_OldState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_HandleDoorStateChanged_Statics::NewProp_OldState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_HandleDoorStateChanged_Statics::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_HandleDoorStateChanged_Statics::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_HandleDoorStateChanged_Statics::PropPointers) < 2048);
// ********** End Function HandleDoorStateChanged Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_HandleDoorStateChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorReconTargetAdapterComponent, nullptr, "HandleDoorStateChanged", 	Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_HandleDoorStateChanged_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_HandleDoorStateChanged_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_HandleDoorStateChanged_Statics::JMDoorReconTargetAdapterComponent_eventHandleDoorStateChanged_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_HandleDoorStateChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_HandleDoorStateChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_HandleDoorStateChanged_Statics::JMDoorReconTargetAdapterComponent_eventHandleDoorStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_HandleDoorStateChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_HandleDoorStateChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorReconTargetAdapterComponent::execHandleDoorStateChanged)
{
	P_GET_ENUM(EJMDoorState,Z_Param_OldState);
	P_GET_ENUM(EJMDoorState,Z_Param_NewState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleDoorStateChanged(EJMDoorState(Z_Param_OldState),EJMDoorState(Z_Param_NewState));
	P_NATIVE_END;
}
// ********** End Class UJMDoorReconTargetAdapterComponent Function HandleDoorStateChanged *********

// ********** Begin Class UJMDoorReconTargetAdapterComponent Function IsTemporaryPoseActive ********
struct Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_IsTemporaryPoseActive_Statics
{
	struct JMDoorReconTargetAdapterComponent_eventIsTemporaryPoseActive_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Recon" },
		{ "ModuleRelativePath", "Public/Components/JMDoorReconTargetAdapterComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsTemporaryPoseActive constinit property declarations *****************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsTemporaryPoseActive constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsTemporaryPoseActive Property Definitions ****************************
void Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_IsTemporaryPoseActive_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMDoorReconTargetAdapterComponent_eventIsTemporaryPoseActive_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_IsTemporaryPoseActive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMDoorReconTargetAdapterComponent_eventIsTemporaryPoseActive_Parms), &Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_IsTemporaryPoseActive_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_IsTemporaryPoseActive_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_IsTemporaryPoseActive_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_IsTemporaryPoseActive_Statics::PropPointers) < 2048);
// ********** End Function IsTemporaryPoseActive Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_IsTemporaryPoseActive_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMDoorReconTargetAdapterComponent, nullptr, "IsTemporaryPoseActive", 	Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_IsTemporaryPoseActive_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_IsTemporaryPoseActive_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_IsTemporaryPoseActive_Statics::JMDoorReconTargetAdapterComponent_eventIsTemporaryPoseActive_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_IsTemporaryPoseActive_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_IsTemporaryPoseActive_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_IsTemporaryPoseActive_Statics::JMDoorReconTargetAdapterComponent_eventIsTemporaryPoseActive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_IsTemporaryPoseActive()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_IsTemporaryPoseActive_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMDoorReconTargetAdapterComponent::execIsTemporaryPoseActive)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsTemporaryPoseActive();
	P_NATIVE_END;
}
// ********** End Class UJMDoorReconTargetAdapterComponent Function IsTemporaryPoseActive **********

// ********** Begin Class UJMDoorReconTargetAdapterComponent ***************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMDoorReconTargetAdapterComponent;
UClass* UJMDoorReconTargetAdapterComponent::GetPrivateStaticClass()
{
	using TClass = UJMDoorReconTargetAdapterComponent;
	if (!Z_Registration_Info_UClass_UJMDoorReconTargetAdapterComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMDoorReconTargetAdapterComponent"),
			Z_Registration_Info_UClass_UJMDoorReconTargetAdapterComponent.InnerSingleton,
			StaticRegisterNativesUJMDoorReconTargetAdapterComponent,
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
	return Z_Registration_Info_UClass_UJMDoorReconTargetAdapterComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_NoRegister()
{
	return UJMDoorReconTargetAdapterComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Session-owned visual door pose. It never mutates JMDoor state or save data. */" },
#endif
		{ "IncludePath", "Components/JMDoorReconTargetAdapterComponent.h" },
		{ "IsBlueprintBase", "false" },
		{ "ModuleRelativePath", "Public/Components/JMDoorReconTargetAdapterComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Session-owned visual door pose. It never mutates JMDoor state or save data." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DoorComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Components/JMDoorReconTargetAdapterComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReconTarget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Components/JMDoorReconTargetAdapterComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMDoorReconTargetAdapterComponent constinit property declarations *******
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DoorComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReconTarget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMDoorReconTargetAdapterComponent constinit property declarations *********
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("HandleDoorStateChanged"), .Pointer = &UJMDoorReconTargetAdapterComponent::execHandleDoorStateChanged },
		{ .NameUTF8 = UTF8TEXT("IsTemporaryPoseActive"), .Pointer = &UJMDoorReconTargetAdapterComponent::execIsTemporaryPoseActive },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_HandleDoorStateChanged, "HandleDoorStateChanged" }, // 490538056
		{ &Z_Construct_UFunction_UJMDoorReconTargetAdapterComponent_IsTemporaryPoseActive, "IsTemporaryPoseActive" }, // 2376124790
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMDoorReconTargetAdapterComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_Statics

// ********** Begin Class UJMDoorReconTargetAdapterComponent Property Definitions ******************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_Statics::NewProp_DoorComponent = { "DoorComponent", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorReconTargetAdapterComponent, DoorComponent), Z_Construct_UClass_UJMDoorComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DoorComponent_MetaData), NewProp_DoorComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_Statics::NewProp_ReconTarget = { "ReconTarget", nullptr, (EPropertyFlags)0x0144000000082008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMDoorReconTargetAdapterComponent, ReconTarget), Z_Construct_UClass_UJMReconTargetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReconTarget_MetaData), NewProp_ReconTarget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_Statics::NewProp_DoorComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_Statics::NewProp_ReconTarget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_Statics::PropPointers) < 2048);
// ********** End Class UJMDoorReconTargetAdapterComponent Property Definitions ********************
UObject* (*const Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorReconIntegration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UJMReconTarget_NoRegister, (int32)VTABLE_OFFSET(UJMDoorReconTargetAdapterComponent, IJMReconTarget), false },  // 1026615361
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_Statics::ClassParams = {
	&UJMDoorReconTargetAdapterComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B000ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_Statics::Class_MetaDataParams)
};
void UJMDoorReconTargetAdapterComponent::StaticRegisterNativesUJMDoorReconTargetAdapterComponent()
{
	UClass* Class = UJMDoorReconTargetAdapterComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMDoorReconTargetAdapterComponent()
{
	if (!Z_Registration_Info_UClass_UJMDoorReconTargetAdapterComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMDoorReconTargetAdapterComponent.OuterSingleton, Z_Construct_UClass_UJMDoorReconTargetAdapterComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMDoorReconTargetAdapterComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMDoorReconTargetAdapterComponent);
UJMDoorReconTargetAdapterComponent::~UJMDoorReconTargetAdapterComponent() {}
// ********** End Class UJMDoorReconTargetAdapterComponent *****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorReconIntegration_Source_JMDoorReconIntegration_Public_Components_JMDoorReconTargetAdapterComponent_h__Script_JMDoorReconIntegration_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMDoorReconTargetAdapterComponent, UJMDoorReconTargetAdapterComponent::StaticClass, TEXT("UJMDoorReconTargetAdapterComponent"), &Z_Registration_Info_UClass_UJMDoorReconTargetAdapterComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMDoorReconTargetAdapterComponent), 777130093U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorReconIntegration_Source_JMDoorReconIntegration_Public_Components_JMDoorReconTargetAdapterComponent_h__Script_JMDoorReconIntegration_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorReconIntegration_Source_JMDoorReconIntegration_Public_Components_JMDoorReconTargetAdapterComponent_h__Script_JMDoorReconIntegration_502673222{
	TEXT("/Script/JMDoorReconIntegration"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorReconIntegration_Source_JMDoorReconIntegration_Public_Components_JMDoorReconTargetAdapterComponent_h__Script_JMDoorReconIntegration_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoorReconIntegration_Source_JMDoorReconIntegration_Public_Components_JMDoorReconTargetAdapterComponent_h__Script_JMDoorReconIntegration_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
