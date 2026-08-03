// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Components/JMHideSimplePanelMechanismComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMHideSimplePanelMechanismComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideMechanismComponent();
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideSimplePanelMechanismComponent();
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_NoRegister();
JMHIDERUNTIME_API UEnum* Z_Construct_UEnum_JMHideRuntime_EJMHidePanelMotionType();
JMHIDERUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMHidePanelPart();
UPackage* Z_Construct_UPackage__Script_JMHideRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EJMHidePanelMotionType ****************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMHidePanelMotionType;
static UEnum* EJMHidePanelMotionType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMHidePanelMotionType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMHidePanelMotionType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_JMHideRuntime_EJMHidePanelMotionType, (UObject*)Z_Construct_UPackage__Script_JMHideRuntime(), TEXT("EJMHidePanelMotionType"));
	}
	return Z_Registration_Info_UEnum_EJMHidePanelMotionType.OuterSingleton;
}
template<> JMHIDERUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMHidePanelMotionType>()
{
	return EJMHidePanelMotionType_StaticEnum();
}
struct Z_Construct_UEnum_JMHideRuntime_EJMHidePanelMotionType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Components/JMHideSimplePanelMechanismComponent.h" },
		{ "RotationOnly.Name", "EJMHidePanelMotionType::RotationOnly" },
		{ "Transform.Name", "EJMHidePanelMotionType::Transform" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMHidePanelMotionType::Transform", (int64)EJMHidePanelMotionType::Transform },
		{ "EJMHidePanelMotionType::RotationOnly", (int64)EJMHidePanelMotionType::RotationOnly },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_JMHideRuntime_EJMHidePanelMotionType_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_JMHideRuntime_EJMHidePanelMotionType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_JMHideRuntime,
	nullptr,
	"EJMHidePanelMotionType",
	"EJMHidePanelMotionType",
	Z_Construct_UEnum_JMHideRuntime_EJMHidePanelMotionType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_JMHideRuntime_EJMHidePanelMotionType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_JMHideRuntime_EJMHidePanelMotionType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_JMHideRuntime_EJMHidePanelMotionType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_JMHideRuntime_EJMHidePanelMotionType()
{
	if (!Z_Registration_Info_UEnum_EJMHidePanelMotionType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMHidePanelMotionType.InnerSingleton, Z_Construct_UEnum_JMHideRuntime_EJMHidePanelMotionType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMHidePanelMotionType.InnerSingleton;
}
// ********** End Enum EJMHidePanelMotionType ******************************************************

// ********** Begin ScriptStruct FJMHidePanelPart **************************************************
struct Z_Construct_UScriptStruct_FJMHidePanelPart_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMHidePanelPart); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMHidePanelPart); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Components/JMHideSimplePanelMechanismComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Panel_MetaData[] = {
		{ "AllowAnyActor", "" },
		{ "Category", "JM Hide" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Components/JMHideSimplePanelMechanismComponent.h" },
		{ "UseComponentPicker", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClosedRelativeTransform_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Components/JMHideSimplePanelMechanismComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpenRelativeTransform_MetaData[] = {
		{ "Category", "JM Hide" },
		{ "ModuleRelativePath", "Public/Components/JMHideSimplePanelMechanismComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MotionType_MetaData[] = {
		{ "Category", "JM Hide" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** RotationOnly never writes the panel's relative location or scale. */" },
#endif
		{ "ModuleRelativePath", "Public/Components/JMHideSimplePanelMechanismComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "RotationOnly never writes the panel's relative location or scale." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMHidePanelPart constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Panel;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ClosedRelativeTransform;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OpenRelativeTransform;
	static const UECodeGen_Private::FBytePropertyParams NewProp_MotionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_MotionType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMHidePanelPart constinit property declarations ********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMHidePanelPart>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMHidePanelPart_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMHidePanelPart;
class UScriptStruct* FJMHidePanelPart::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMHidePanelPart.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMHidePanelPart.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMHidePanelPart, (UObject*)Z_Construct_UPackage__Script_JMHideRuntime(), TEXT("JMHidePanelPart"));
	}
	return Z_Registration_Info_UScriptStruct_FJMHidePanelPart.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMHidePanelPart Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMHidePanelPart_Statics::NewProp_Panel = { "Panel", nullptr, (EPropertyFlags)0x011400000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHidePanelPart, Panel), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Panel_MetaData), NewProp_Panel_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMHidePanelPart_Statics::NewProp_ClosedRelativeTransform = { "ClosedRelativeTransform", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHidePanelPart, ClosedRelativeTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClosedRelativeTransform_MetaData), NewProp_ClosedRelativeTransform_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMHidePanelPart_Statics::NewProp_OpenRelativeTransform = { "OpenRelativeTransform", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHidePanelPart, OpenRelativeTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpenRelativeTransform_MetaData), NewProp_OpenRelativeTransform_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMHidePanelPart_Statics::NewProp_MotionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMHidePanelPart_Statics::NewProp_MotionType = { "MotionType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMHidePanelPart, MotionType), Z_Construct_UEnum_JMHideRuntime_EJMHidePanelMotionType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MotionType_MetaData), NewProp_MotionType_MetaData) }; // 4193015253
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMHidePanelPart_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHidePanelPart_Statics::NewProp_Panel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHidePanelPart_Statics::NewProp_ClosedRelativeTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHidePanelPart_Statics::NewProp_OpenRelativeTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHidePanelPart_Statics::NewProp_MotionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMHidePanelPart_Statics::NewProp_MotionType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHidePanelPart_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMHidePanelPart Property Definitions *******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMHidePanelPart_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideRuntime,
	nullptr,
	&NewStructOps,
	"JMHidePanelPart",
	Z_Construct_UScriptStruct_FJMHidePanelPart_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHidePanelPart_Statics::PropPointers),
	sizeof(FJMHidePanelPart),
	alignof(FJMHidePanelPart),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000205),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMHidePanelPart_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMHidePanelPart_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMHidePanelPart()
{
	if (!Z_Registration_Info_UScriptStruct_FJMHidePanelPart.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMHidePanelPart.InnerSingleton, Z_Construct_UScriptStruct_FJMHidePanelPart_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMHidePanelPart.InnerSingleton);
}
// ********** End ScriptStruct FJMHidePanelPart ****************************************************

// ********** Begin Class UJMHideSimplePanelMechanismComponent Function ValidateConfiguration ******
struct Z_Construct_UFunction_UJMHideSimplePanelMechanismComponent_ValidateConfiguration_Statics
{
	struct JMHideSimplePanelMechanismComponent_eventValidateConfiguration_Parms
	{
		TArray<FText> OutErrors;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Hide|Validation" },
		{ "ModuleRelativePath", "Public/Components/JMHideSimplePanelMechanismComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ValidateConfiguration constinit property declarations *****************
	static const UECodeGen_Private::FTextPropertyParams NewProp_OutErrors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutErrors;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ValidateConfiguration constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ValidateConfiguration Property Definitions ****************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UJMHideSimplePanelMechanismComponent_ValidateConfiguration_Statics::NewProp_OutErrors_Inner = { "OutErrors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UJMHideSimplePanelMechanismComponent_ValidateConfiguration_Statics::NewProp_OutErrors = { "OutErrors", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMHideSimplePanelMechanismComponent_eventValidateConfiguration_Parms, OutErrors), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UJMHideSimplePanelMechanismComponent_ValidateConfiguration_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((JMHideSimplePanelMechanismComponent_eventValidateConfiguration_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJMHideSimplePanelMechanismComponent_ValidateConfiguration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(JMHideSimplePanelMechanismComponent_eventValidateConfiguration_Parms), &Z_Construct_UFunction_UJMHideSimplePanelMechanismComponent_ValidateConfiguration_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJMHideSimplePanelMechanismComponent_ValidateConfiguration_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideSimplePanelMechanismComponent_ValidateConfiguration_Statics::NewProp_OutErrors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideSimplePanelMechanismComponent_ValidateConfiguration_Statics::NewProp_OutErrors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJMHideSimplePanelMechanismComponent_ValidateConfiguration_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideSimplePanelMechanismComponent_ValidateConfiguration_Statics::PropPointers) < 2048);
// ********** End Function ValidateConfiguration Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UJMHideSimplePanelMechanismComponent_ValidateConfiguration_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UJMHideSimplePanelMechanismComponent, nullptr, "ValidateConfiguration", 	Z_Construct_UFunction_UJMHideSimplePanelMechanismComponent_ValidateConfiguration_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideSimplePanelMechanismComponent_ValidateConfiguration_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UJMHideSimplePanelMechanismComponent_ValidateConfiguration_Statics::JMHideSimplePanelMechanismComponent_eventValidateConfiguration_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UJMHideSimplePanelMechanismComponent_ValidateConfiguration_Statics::Function_MetaDataParams), Z_Construct_UFunction_UJMHideSimplePanelMechanismComponent_ValidateConfiguration_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UJMHideSimplePanelMechanismComponent_ValidateConfiguration_Statics::JMHideSimplePanelMechanismComponent_eventValidateConfiguration_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UJMHideSimplePanelMechanismComponent_ValidateConfiguration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UJMHideSimplePanelMechanismComponent_ValidateConfiguration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UJMHideSimplePanelMechanismComponent::execValidateConfiguration)
{
	P_GET_TARRAY_REF(FText,Z_Param_Out_OutErrors);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ValidateConfiguration(Z_Param_Out_OutErrors);
	P_NATIVE_END;
}
// ********** End Class UJMHideSimplePanelMechanismComponent Function ValidateConfiguration ********

// ********** Begin Class UJMHideSimplePanelMechanismComponent *************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMHideSimplePanelMechanismComponent;
UClass* UJMHideSimplePanelMechanismComponent::GetPrivateStaticClass()
{
	using TClass = UJMHideSimplePanelMechanismComponent;
	if (!Z_Registration_Info_UClass_UJMHideSimplePanelMechanismComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMHideSimplePanelMechanismComponent"),
			Z_Registration_Info_UClass_UJMHideSimplePanelMechanismComponent.InnerSingleton,
			StaticRegisterNativesUJMHideSimplePanelMechanismComponent,
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
	return Z_Registration_Info_UClass_UJMHideSimplePanelMechanismComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_NoRegister()
{
	return UJMHideSimplePanelMechanismComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "JMHide" },
		{ "IncludePath", "Components/JMHideSimplePanelMechanismComponent.h" },
		{ "ModuleRelativePath", "Public/Components/JMHideSimplePanelMechanismComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Panels_MetaData[] = {
		{ "Category", "JM Hide|Panel" },
		{ "ModuleRelativePath", "Public/Components/JMHideSimplePanelMechanismComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Duration_MetaData[] = {
		{ "Category", "JM Hide|Panel" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Components/JMHideSimplePanelMechanismComponent.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Delay_MetaData[] = {
		{ "Category", "JM Hide|Panel" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Components/JMHideSimplePanelMechanismComponent.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Curve_MetaData[] = {
		{ "Category", "JM Hide|Panel" },
		{ "ModuleRelativePath", "Public/Components/JMHideSimplePanelMechanismComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMHideSimplePanelMechanismComponent constinit property declarations *****
	static const UECodeGen_Private::FStructPropertyParams NewProp_Panels_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Panels;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Delay;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Curve;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMHideSimplePanelMechanismComponent constinit property declarations *******
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ValidateConfiguration"), .Pointer = &UJMHideSimplePanelMechanismComponent::execValidateConfiguration },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UJMHideSimplePanelMechanismComponent_ValidateConfiguration, "ValidateConfiguration" }, // 212657123
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMHideSimplePanelMechanismComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics

// ********** Begin Class UJMHideSimplePanelMechanismComponent Property Definitions ****************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics::NewProp_Panels_Inner = { "Panels", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FJMHidePanelPart, METADATA_PARAMS(0, nullptr) }; // 1033871268
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics::NewProp_Panels = { "Panels", nullptr, (EPropertyFlags)0x0010008000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMHideSimplePanelMechanismComponent, Panels), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Panels_MetaData), NewProp_Panels_MetaData) }; // 1033871268
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMHideSimplePanelMechanismComponent, Duration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Duration_MetaData), NewProp_Duration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics::NewProp_Delay = { "Delay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMHideSimplePanelMechanismComponent, Delay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Delay_MetaData), NewProp_Delay_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics::NewProp_Curve = { "Curve", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMHideSimplePanelMechanismComponent, Curve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Curve_MetaData), NewProp_Curve_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics::NewProp_Panels_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics::NewProp_Panels,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics::NewProp_Duration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics::NewProp_Delay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics::NewProp_Curve,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics::PropPointers) < 2048);
// ********** End Class UJMHideSimplePanelMechanismComponent Property Definitions ******************
UObject* (*const Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UJMHideMechanismComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_JMHideRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics::ClassParams = {
	&UJMHideSimplePanelMechanismComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics::Class_MetaDataParams)
};
void UJMHideSimplePanelMechanismComponent::StaticRegisterNativesUJMHideSimplePanelMechanismComponent()
{
	UClass* Class = UJMHideSimplePanelMechanismComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UJMHideSimplePanelMechanismComponent()
{
	if (!Z_Registration_Info_UClass_UJMHideSimplePanelMechanismComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMHideSimplePanelMechanismComponent.OuterSingleton, Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMHideSimplePanelMechanismComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMHideSimplePanelMechanismComponent);
UJMHideSimplePanelMechanismComponent::~UJMHideSimplePanelMechanismComponent() {}
// ********** End Class UJMHideSimplePanelMechanismComponent ***************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSimplePanelMechanismComponent_h__Script_JMHideRuntime_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EJMHidePanelMotionType_StaticEnum, TEXT("EJMHidePanelMotionType"), &Z_Registration_Info_UEnum_EJMHidePanelMotionType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4193015253U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FJMHidePanelPart::StaticStruct, Z_Construct_UScriptStruct_FJMHidePanelPart_Statics::NewStructOps, TEXT("JMHidePanelPart"),&Z_Registration_Info_UScriptStruct_FJMHidePanelPart, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMHidePanelPart), 1033871268U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMHideSimplePanelMechanismComponent, UJMHideSimplePanelMechanismComponent::StaticClass, TEXT("UJMHideSimplePanelMechanismComponent"), &Z_Registration_Info_UClass_UJMHideSimplePanelMechanismComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMHideSimplePanelMechanismComponent), 863470926U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSimplePanelMechanismComponent_h__Script_JMHideRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSimplePanelMechanismComponent_h__Script_JMHideRuntime_2715995779{
	TEXT("/Script/JMHideRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSimplePanelMechanismComponent_h__Script_JMHideRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSimplePanelMechanismComponent_h__Script_JMHideRuntime_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSimplePanelMechanismComponent_h__Script_JMHideRuntime_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSimplePanelMechanismComponent_h__Script_JMHideRuntime_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSimplePanelMechanismComponent_h__Script_JMHideRuntime_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSimplePanelMechanismComponent_h__Script_JMHideRuntime_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
