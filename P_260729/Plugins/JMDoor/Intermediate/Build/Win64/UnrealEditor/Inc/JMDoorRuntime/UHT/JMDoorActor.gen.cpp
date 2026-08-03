// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actors/JMDoorActor.h"
#include "Door/JMDoorTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMDoorActor() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_AJMDoorActor();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_AJMDoorActor_NoRegister();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_AJMRotatingDoorActor();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_AJMRotatingDoorActor_NoRegister();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_AJMSlidingDoorActor();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_AJMSlidingDoorActor_NoRegister();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorComponent_NoRegister();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorSaveInterface_NoRegister();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorUsableInterface_NoRegister();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMRotatingDoorMovementComponent_NoRegister();
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMSlidingDoorMovementComponent_NoRegister();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMDoorState();
JMDOORRUNTIME_API UEnum* Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel();
JMDOORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMDoorResult();
JMDOORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMDoorUseContext();
UPackage* Z_Construct_UPackage__Script_JMDoorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AJMDoorActor *************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AJMDoorActor;
UClass* AJMDoorActor::GetPrivateStaticClass()
{
	using TClass = AJMDoorActor;
	if (!Z_Registration_Info_UClass_AJMDoorActor.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMDoorActor"),
			Z_Registration_Info_UClass_AJMDoorActor.InnerSingleton,
			StaticRegisterNativesAJMDoorActor,
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
	return Z_Registration_Info_UClass_AJMDoorActor.InnerSingleton;
}
UClass* Z_Construct_UClass_AJMDoorActor_NoRegister()
{
	return AJMDoorActor::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AJMDoorActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Actors/JMDoorActor.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Actors/JMDoorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneRoot_MetaData[] = {
		{ "Category", "JM Door|Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/JMDoorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrameMesh_MetaData[] = {
		{ "Category", "JM Door|Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/JMDoorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MovementRoot_MetaData[] = {
		{ "Category", "JM Door|Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/JMDoorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DoorLeafMesh_MetaData[] = {
		{ "Category", "JM Door|Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/JMDoorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LockMesh_MetaData[] = {
		{ "Category", "JM Door|Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/JMDoorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DoorComponent_MetaData[] = {
		{ "Category", "JM Door|Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/JMDoorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AJMDoorActor constinit property declarations *****************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneRoot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FrameMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MovementRoot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DoorLeafMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LockMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DoorComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AJMDoorActor constinit property declarations *******************************
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AJMDoorActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AJMDoorActor_Statics

// ********** Begin Class AJMDoorActor Property Definitions ****************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMDoorActor_Statics::NewProp_SceneRoot = { "SceneRoot", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMDoorActor, SceneRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneRoot_MetaData), NewProp_SceneRoot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMDoorActor_Statics::NewProp_FrameMesh = { "FrameMesh", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMDoorActor, FrameMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrameMesh_MetaData), NewProp_FrameMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMDoorActor_Statics::NewProp_MovementRoot = { "MovementRoot", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMDoorActor, MovementRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MovementRoot_MetaData), NewProp_MovementRoot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMDoorActor_Statics::NewProp_DoorLeafMesh = { "DoorLeafMesh", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMDoorActor, DoorLeafMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DoorLeafMesh_MetaData), NewProp_DoorLeafMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMDoorActor_Statics::NewProp_LockMesh = { "LockMesh", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMDoorActor, LockMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LockMesh_MetaData), NewProp_LockMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMDoorActor_Statics::NewProp_DoorComponent = { "DoorComponent", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMDoorActor, DoorComponent), Z_Construct_UClass_UJMDoorComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DoorComponent_MetaData), NewProp_DoorComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AJMDoorActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMDoorActor_Statics::NewProp_SceneRoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMDoorActor_Statics::NewProp_FrameMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMDoorActor_Statics::NewProp_MovementRoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMDoorActor_Statics::NewProp_DoorLeafMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMDoorActor_Statics::NewProp_LockMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMDoorActor_Statics::NewProp_DoorComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AJMDoorActor_Statics::PropPointers) < 2048);
// ********** End Class AJMDoorActor Property Definitions ******************************************
UObject* (*const Z_Construct_UClass_AJMDoorActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AJMDoorActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AJMDoorActor_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UJMDoorUsableInterface_NoRegister, (int32)VTABLE_OFFSET(AJMDoorActor, IJMDoorUsableInterface), false },  // 2903801364
	{ Z_Construct_UClass_UJMDoorSaveInterface_NoRegister, (int32)VTABLE_OFFSET(AJMDoorActor, IJMDoorSaveInterface), false },  // 817703882
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_AJMDoorActor_Statics::ClassParams = {
	&AJMDoorActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AJMDoorActor_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AJMDoorActor_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x009000A5u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AJMDoorActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AJMDoorActor_Statics::Class_MetaDataParams)
};
void AJMDoorActor::StaticRegisterNativesAJMDoorActor()
{
}
UClass* Z_Construct_UClass_AJMDoorActor()
{
	if (!Z_Registration_Info_UClass_AJMDoorActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AJMDoorActor.OuterSingleton, Z_Construct_UClass_AJMDoorActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AJMDoorActor.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AJMDoorActor);
AJMDoorActor::~AJMDoorActor() {}
// ********** End Class AJMDoorActor ***************************************************************

// ********** Begin Class AJMRotatingDoorActor *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AJMRotatingDoorActor;
UClass* AJMRotatingDoorActor::GetPrivateStaticClass()
{
	using TClass = AJMRotatingDoorActor;
	if (!Z_Registration_Info_UClass_AJMRotatingDoorActor.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMRotatingDoorActor"),
			Z_Registration_Info_UClass_AJMRotatingDoorActor.InnerSingleton,
			StaticRegisterNativesAJMRotatingDoorActor,
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
	return Z_Registration_Info_UClass_AJMRotatingDoorActor.InnerSingleton;
}
UClass* Z_Construct_UClass_AJMRotatingDoorActor_NoRegister()
{
	return AJMRotatingDoorActor::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AJMRotatingDoorActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Actors/JMDoorActor.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Actors/JMDoorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotatingMovement_MetaData[] = {
		{ "Category", "JM Door|Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/JMDoorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AJMRotatingDoorActor constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RotatingMovement;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AJMRotatingDoorActor constinit property declarations ***********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AJMRotatingDoorActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AJMRotatingDoorActor_Statics

// ********** Begin Class AJMRotatingDoorActor Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMRotatingDoorActor_Statics::NewProp_RotatingMovement = { "RotatingMovement", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMRotatingDoorActor, RotatingMovement), Z_Construct_UClass_UJMRotatingDoorMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotatingMovement_MetaData), NewProp_RotatingMovement_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AJMRotatingDoorActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMRotatingDoorActor_Statics::NewProp_RotatingMovement,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AJMRotatingDoorActor_Statics::PropPointers) < 2048);
// ********** End Class AJMRotatingDoorActor Property Definitions **********************************
UObject* (*const Z_Construct_UClass_AJMRotatingDoorActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AJMDoorActor,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AJMRotatingDoorActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AJMRotatingDoorActor_Statics::ClassParams = {
	&AJMRotatingDoorActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AJMRotatingDoorActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AJMRotatingDoorActor_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AJMRotatingDoorActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AJMRotatingDoorActor_Statics::Class_MetaDataParams)
};
void AJMRotatingDoorActor::StaticRegisterNativesAJMRotatingDoorActor()
{
}
UClass* Z_Construct_UClass_AJMRotatingDoorActor()
{
	if (!Z_Registration_Info_UClass_AJMRotatingDoorActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AJMRotatingDoorActor.OuterSingleton, Z_Construct_UClass_AJMRotatingDoorActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AJMRotatingDoorActor.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AJMRotatingDoorActor);
AJMRotatingDoorActor::~AJMRotatingDoorActor() {}
// ********** End Class AJMRotatingDoorActor *******************************************************

// ********** Begin Class AJMSlidingDoorActor Function CloseSlideDoor ******************************
struct Z_Construct_UFunction_AJMSlidingDoorActor_CloseSlideDoor_Statics
{
	struct JMSlidingDoorActor_eventCloseSlideDoor_Parms
	{
		EJMSlideDoorPanel Panel;
		FJMDoorUseContext Context;
		FJMDoorResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Slide Door" },
		{ "ModuleRelativePath", "Public/Actors/JMDoorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CloseSlideDoor constinit property declarations ************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Panel_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Panel;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CloseSlideDoor constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CloseSlideDoor Property Definitions ***********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AJMSlidingDoorActor_CloseSlideDoor_Statics::NewProp_Panel_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AJMSlidingDoorActor_CloseSlideDoor_Statics::NewProp_Panel = { "Panel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMSlidingDoorActor_eventCloseSlideDoor_Parms, Panel), Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel, METADATA_PARAMS(0, nullptr) }; // 1478343840
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AJMSlidingDoorActor_CloseSlideDoor_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMSlidingDoorActor_eventCloseSlideDoor_Parms, Context), Z_Construct_UScriptStruct_FJMDoorUseContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3552665729
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AJMSlidingDoorActor_CloseSlideDoor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMSlidingDoorActor_eventCloseSlideDoor_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMDoorResult, METADATA_PARAMS(0, nullptr) }; // 1639184842
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AJMSlidingDoorActor_CloseSlideDoor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AJMSlidingDoorActor_CloseSlideDoor_Statics::NewProp_Panel_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AJMSlidingDoorActor_CloseSlideDoor_Statics::NewProp_Panel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AJMSlidingDoorActor_CloseSlideDoor_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AJMSlidingDoorActor_CloseSlideDoor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AJMSlidingDoorActor_CloseSlideDoor_Statics::PropPointers) < 2048);
// ********** End Function CloseSlideDoor Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AJMSlidingDoorActor_CloseSlideDoor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AJMSlidingDoorActor, nullptr, "CloseSlideDoor", 	Z_Construct_UFunction_AJMSlidingDoorActor_CloseSlideDoor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AJMSlidingDoorActor_CloseSlideDoor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AJMSlidingDoorActor_CloseSlideDoor_Statics::JMSlidingDoorActor_eventCloseSlideDoor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AJMSlidingDoorActor_CloseSlideDoor_Statics::Function_MetaDataParams), Z_Construct_UFunction_AJMSlidingDoorActor_CloseSlideDoor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AJMSlidingDoorActor_CloseSlideDoor_Statics::JMSlidingDoorActor_eventCloseSlideDoor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AJMSlidingDoorActor_CloseSlideDoor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AJMSlidingDoorActor_CloseSlideDoor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AJMSlidingDoorActor::execCloseSlideDoor)
{
	P_GET_ENUM(EJMSlideDoorPanel,Z_Param_Panel);
	P_GET_STRUCT_REF(FJMDoorUseContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMDoorResult*)Z_Param__Result=P_THIS->CloseSlideDoor(EJMSlideDoorPanel(Z_Param_Panel),Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Class AJMSlidingDoorActor Function CloseSlideDoor ********************************

// ********** Begin Class AJMSlidingDoorActor Function GetSlideDoorPanelState **********************
struct Z_Construct_UFunction_AJMSlidingDoorActor_GetSlideDoorPanelState_Statics
{
	struct JMSlidingDoorActor_eventGetSlideDoorPanelState_Parms
	{
		EJMSlideDoorPanel Panel;
		EJMDoorState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Slide Door" },
		{ "ModuleRelativePath", "Public/Actors/JMDoorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSlideDoorPanelState constinit property declarations ****************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Panel_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Panel;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSlideDoorPanelState constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSlideDoorPanelState Property Definitions ***************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AJMSlidingDoorActor_GetSlideDoorPanelState_Statics::NewProp_Panel_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AJMSlidingDoorActor_GetSlideDoorPanelState_Statics::NewProp_Panel = { "Panel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMSlidingDoorActor_eventGetSlideDoorPanelState_Parms, Panel), Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel, METADATA_PARAMS(0, nullptr) }; // 1478343840
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AJMSlidingDoorActor_GetSlideDoorPanelState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AJMSlidingDoorActor_GetSlideDoorPanelState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMSlidingDoorActor_eventGetSlideDoorPanelState_Parms, ReturnValue), Z_Construct_UEnum_JMDoorRuntime_EJMDoorState, METADATA_PARAMS(0, nullptr) }; // 2513049645
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AJMSlidingDoorActor_GetSlideDoorPanelState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AJMSlidingDoorActor_GetSlideDoorPanelState_Statics::NewProp_Panel_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AJMSlidingDoorActor_GetSlideDoorPanelState_Statics::NewProp_Panel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AJMSlidingDoorActor_GetSlideDoorPanelState_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AJMSlidingDoorActor_GetSlideDoorPanelState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AJMSlidingDoorActor_GetSlideDoorPanelState_Statics::PropPointers) < 2048);
// ********** End Function GetSlideDoorPanelState Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AJMSlidingDoorActor_GetSlideDoorPanelState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AJMSlidingDoorActor, nullptr, "GetSlideDoorPanelState", 	Z_Construct_UFunction_AJMSlidingDoorActor_GetSlideDoorPanelState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AJMSlidingDoorActor_GetSlideDoorPanelState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AJMSlidingDoorActor_GetSlideDoorPanelState_Statics::JMSlidingDoorActor_eventGetSlideDoorPanelState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AJMSlidingDoorActor_GetSlideDoorPanelState_Statics::Function_MetaDataParams), Z_Construct_UFunction_AJMSlidingDoorActor_GetSlideDoorPanelState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AJMSlidingDoorActor_GetSlideDoorPanelState_Statics::JMSlidingDoorActor_eventGetSlideDoorPanelState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AJMSlidingDoorActor_GetSlideDoorPanelState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AJMSlidingDoorActor_GetSlideDoorPanelState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AJMSlidingDoorActor::execGetSlideDoorPanelState)
{
	P_GET_ENUM(EJMSlideDoorPanel,Z_Param_Panel);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EJMDoorState*)Z_Param__Result=P_THIS->GetSlideDoorPanelState(EJMSlideDoorPanel(Z_Param_Panel));
	P_NATIVE_END;
}
// ********** End Class AJMSlidingDoorActor Function GetSlideDoorPanelState ************************

// ********** Begin Class AJMSlidingDoorActor Function OpenSlideDoor *******************************
struct Z_Construct_UFunction_AJMSlidingDoorActor_OpenSlideDoor_Statics
{
	struct JMSlidingDoorActor_eventOpenSlideDoor_Parms
	{
		EJMSlideDoorPanel Panel;
		FJMDoorUseContext Context;
		FJMDoorResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "JM Door|Slide Door" },
		{ "ModuleRelativePath", "Public/Actors/JMDoorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OpenSlideDoor constinit property declarations *************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Panel_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Panel;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OpenSlideDoor constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OpenSlideDoor Property Definitions ************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AJMSlidingDoorActor_OpenSlideDoor_Statics::NewProp_Panel_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AJMSlidingDoorActor_OpenSlideDoor_Statics::NewProp_Panel = { "Panel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMSlidingDoorActor_eventOpenSlideDoor_Parms, Panel), Z_Construct_UEnum_JMDoorRuntime_EJMSlideDoorPanel, METADATA_PARAMS(0, nullptr) }; // 1478343840
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AJMSlidingDoorActor_OpenSlideDoor_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMSlidingDoorActor_eventOpenSlideDoor_Parms, Context), Z_Construct_UScriptStruct_FJMDoorUseContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 3552665729
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AJMSlidingDoorActor_OpenSlideDoor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(JMSlidingDoorActor_eventOpenSlideDoor_Parms, ReturnValue), Z_Construct_UScriptStruct_FJMDoorResult, METADATA_PARAMS(0, nullptr) }; // 1639184842
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AJMSlidingDoorActor_OpenSlideDoor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AJMSlidingDoorActor_OpenSlideDoor_Statics::NewProp_Panel_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AJMSlidingDoorActor_OpenSlideDoor_Statics::NewProp_Panel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AJMSlidingDoorActor_OpenSlideDoor_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AJMSlidingDoorActor_OpenSlideDoor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AJMSlidingDoorActor_OpenSlideDoor_Statics::PropPointers) < 2048);
// ********** End Function OpenSlideDoor Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AJMSlidingDoorActor_OpenSlideDoor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AJMSlidingDoorActor, nullptr, "OpenSlideDoor", 	Z_Construct_UFunction_AJMSlidingDoorActor_OpenSlideDoor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_AJMSlidingDoorActor_OpenSlideDoor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_AJMSlidingDoorActor_OpenSlideDoor_Statics::JMSlidingDoorActor_eventOpenSlideDoor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AJMSlidingDoorActor_OpenSlideDoor_Statics::Function_MetaDataParams), Z_Construct_UFunction_AJMSlidingDoorActor_OpenSlideDoor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AJMSlidingDoorActor_OpenSlideDoor_Statics::JMSlidingDoorActor_eventOpenSlideDoor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AJMSlidingDoorActor_OpenSlideDoor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AJMSlidingDoorActor_OpenSlideDoor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AJMSlidingDoorActor::execOpenSlideDoor)
{
	P_GET_ENUM(EJMSlideDoorPanel,Z_Param_Panel);
	P_GET_STRUCT_REF(FJMDoorUseContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FJMDoorResult*)Z_Param__Result=P_THIS->OpenSlideDoor(EJMSlideDoorPanel(Z_Param_Panel),Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Class AJMSlidingDoorActor Function OpenSlideDoor *********************************

// ********** Begin Class AJMSlidingDoorActor ******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AJMSlidingDoorActor;
UClass* AJMSlidingDoorActor::GetPrivateStaticClass()
{
	using TClass = AJMSlidingDoorActor;
	if (!Z_Registration_Info_UClass_AJMSlidingDoorActor.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMSlidingDoorActor"),
			Z_Registration_Info_UClass_AJMSlidingDoorActor.InnerSingleton,
			StaticRegisterNativesAJMSlidingDoorActor,
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
	return Z_Registration_Info_UClass_AJMSlidingDoorActor.InnerSingleton;
}
UClass* Z_Construct_UClass_AJMSlidingDoorActor_NoRegister()
{
	return AJMSlidingDoorActor::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AJMSlidingDoorActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Actors/JMDoorActor.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Actors/JMDoorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlidingMovement_MetaData[] = {
		{ "Category", "JM Door|Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/JMDoorActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DoorLeafMeshB_MetaData[] = {
		{ "Category", "JM Door|Slide Door|Door B" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Right-hand panel. The inherited DoorLeafMesh is panel A for compatibility. */" },
#endif
		{ "DisplayName", "Slide Door Mesh B" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/JMDoorActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Right-hand panel. The inherited DoorLeafMesh is panel A for compatibility." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPreviewOpenPositions_MetaData[] = {
		{ "Category", "JM Door|Slide Door|Opening Behavior" },
		{ "ModuleRelativePath", "Public/Actors/JMDoorActor.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AJMSlidingDoorActor constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SlidingMovement;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DoorLeafMeshB;
	static void NewProp_bPreviewOpenPositions_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPreviewOpenPositions;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AJMSlidingDoorActor constinit property declarations ************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CloseSlideDoor"), .Pointer = &AJMSlidingDoorActor::execCloseSlideDoor },
		{ .NameUTF8 = UTF8TEXT("GetSlideDoorPanelState"), .Pointer = &AJMSlidingDoorActor::execGetSlideDoorPanelState },
		{ .NameUTF8 = UTF8TEXT("OpenSlideDoor"), .Pointer = &AJMSlidingDoorActor::execOpenSlideDoor },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AJMSlidingDoorActor_CloseSlideDoor, "CloseSlideDoor" }, // 209030450
		{ &Z_Construct_UFunction_AJMSlidingDoorActor_GetSlideDoorPanelState, "GetSlideDoorPanelState" }, // 2557576957
		{ &Z_Construct_UFunction_AJMSlidingDoorActor_OpenSlideDoor, "OpenSlideDoor" }, // 580036029
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AJMSlidingDoorActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AJMSlidingDoorActor_Statics

// ********** Begin Class AJMSlidingDoorActor Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMSlidingDoorActor_Statics::NewProp_SlidingMovement = { "SlidingMovement", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMSlidingDoorActor, SlidingMovement), Z_Construct_UClass_UJMSlidingDoorMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlidingMovement_MetaData), NewProp_SlidingMovement_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AJMSlidingDoorActor_Statics::NewProp_DoorLeafMeshB = { "DoorLeafMeshB", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AJMSlidingDoorActor, DoorLeafMeshB), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DoorLeafMeshB_MetaData), NewProp_DoorLeafMeshB_MetaData) };
void Z_Construct_UClass_AJMSlidingDoorActor_Statics::NewProp_bPreviewOpenPositions_SetBit(void* Obj)
{
	((AJMSlidingDoorActor*)Obj)->bPreviewOpenPositions = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AJMSlidingDoorActor_Statics::NewProp_bPreviewOpenPositions = { "bPreviewOpenPositions", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AJMSlidingDoorActor), &Z_Construct_UClass_AJMSlidingDoorActor_Statics::NewProp_bPreviewOpenPositions_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPreviewOpenPositions_MetaData), NewProp_bPreviewOpenPositions_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AJMSlidingDoorActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMSlidingDoorActor_Statics::NewProp_SlidingMovement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMSlidingDoorActor_Statics::NewProp_DoorLeafMeshB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AJMSlidingDoorActor_Statics::NewProp_bPreviewOpenPositions,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AJMSlidingDoorActor_Statics::PropPointers) < 2048);
// ********** End Class AJMSlidingDoorActor Property Definitions ***********************************
UObject* (*const Z_Construct_UClass_AJMSlidingDoorActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AJMDoorActor,
	(UObject* (*)())Z_Construct_UPackage__Script_JMDoorRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AJMSlidingDoorActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AJMSlidingDoorActor_Statics::ClassParams = {
	&AJMSlidingDoorActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AJMSlidingDoorActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AJMSlidingDoorActor_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AJMSlidingDoorActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AJMSlidingDoorActor_Statics::Class_MetaDataParams)
};
void AJMSlidingDoorActor::StaticRegisterNativesAJMSlidingDoorActor()
{
	UClass* Class = AJMSlidingDoorActor::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_AJMSlidingDoorActor_Statics::Funcs));
}
UClass* Z_Construct_UClass_AJMSlidingDoorActor()
{
	if (!Z_Registration_Info_UClass_AJMSlidingDoorActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AJMSlidingDoorActor.OuterSingleton, Z_Construct_UClass_AJMSlidingDoorActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AJMSlidingDoorActor.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AJMSlidingDoorActor);
AJMSlidingDoorActor::~AJMSlidingDoorActor() {}
// ********** End Class AJMSlidingDoorActor ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h__Script_JMDoorRuntime_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AJMDoorActor, AJMDoorActor::StaticClass, TEXT("AJMDoorActor"), &Z_Registration_Info_UClass_AJMDoorActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AJMDoorActor), 1789301592U) },
		{ Z_Construct_UClass_AJMRotatingDoorActor, AJMRotatingDoorActor::StaticClass, TEXT("AJMRotatingDoorActor"), &Z_Registration_Info_UClass_AJMRotatingDoorActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AJMRotatingDoorActor), 371487893U) },
		{ Z_Construct_UClass_AJMSlidingDoorActor, AJMSlidingDoorActor::StaticClass, TEXT("AJMSlidingDoorActor"), &Z_Registration_Info_UClass_AJMSlidingDoorActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AJMSlidingDoorActor), 761056728U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h__Script_JMDoorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h__Script_JMDoorRuntime_2037006514{
	TEXT("/Script/JMDoorRuntime"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h__Script_JMDoorRuntime_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Actors_JMDoorActor_h__Script_JMDoorRuntime_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
