// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interaction/ReuseDialogueInteractableComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeReuseDialogueInteractableComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractableInterface_NoRegister();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueSequence_NoRegister();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UReuseDialogueInteractableComponent();
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UReuseDialogueInteractableComponent_NoRegister();
REUSABLEDIALOGUESYSTEM_API UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EDialogueInteractionMode();
REUSABLEDIALOGUESYSTEM_API UEnum* Z_Construct_UEnum_ReusableDialogueSystem_EExistingDialoguePolicy();
UPackage* Z_Construct_UPackage__Script_ReusableDialogueSystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UReuseDialogueInteractableComponent Function HasStartedDialogue **********
struct Z_Construct_UFunction_UReuseDialogueInteractableComponent_HasStartedDialogue_Statics
{
	struct ReuseDialogueInteractableComponent_eventHasStartedDialogue_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue|Interaction" },
		{ "ModuleRelativePath", "Public/Interaction/ReuseDialogueInteractableComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function HasStartedDialogue constinit property declarations ********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasStartedDialogue constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasStartedDialogue Property Definitions *******************************
void Z_Construct_UFunction_UReuseDialogueInteractableComponent_HasStartedDialogue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ReuseDialogueInteractableComponent_eventHasStartedDialogue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UReuseDialogueInteractableComponent_HasStartedDialogue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ReuseDialogueInteractableComponent_eventHasStartedDialogue_Parms), &Z_Construct_UFunction_UReuseDialogueInteractableComponent_HasStartedDialogue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UReuseDialogueInteractableComponent_HasStartedDialogue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UReuseDialogueInteractableComponent_HasStartedDialogue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UReuseDialogueInteractableComponent_HasStartedDialogue_Statics::PropPointers) < 2048);
// ********** End Function HasStartedDialogue Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UReuseDialogueInteractableComponent_HasStartedDialogue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UReuseDialogueInteractableComponent, nullptr, "HasStartedDialogue", 	Z_Construct_UFunction_UReuseDialogueInteractableComponent_HasStartedDialogue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UReuseDialogueInteractableComponent_HasStartedDialogue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UReuseDialogueInteractableComponent_HasStartedDialogue_Statics::ReuseDialogueInteractableComponent_eventHasStartedDialogue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UReuseDialogueInteractableComponent_HasStartedDialogue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UReuseDialogueInteractableComponent_HasStartedDialogue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UReuseDialogueInteractableComponent_HasStartedDialogue_Statics::ReuseDialogueInteractableComponent_eventHasStartedDialogue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UReuseDialogueInteractableComponent_HasStartedDialogue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UReuseDialogueInteractableComponent_HasStartedDialogue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UReuseDialogueInteractableComponent::execHasStartedDialogue)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->HasStartedDialogue();
	P_NATIVE_END;
}
// ********** End Class UReuseDialogueInteractableComponent Function HasStartedDialogue ************

// ********** Begin Class UReuseDialogueInteractableComponent Function ResetInteraction ************
struct Z_Construct_UFunction_UReuseDialogueInteractableComponent_ResetInteraction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dialogue|Interaction" },
		{ "ModuleRelativePath", "Public/Interaction/ReuseDialogueInteractableComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResetInteraction constinit property declarations **********************
// ********** End Function ResetInteraction constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UReuseDialogueInteractableComponent_ResetInteraction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UReuseDialogueInteractableComponent, nullptr, "ResetInteraction", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UReuseDialogueInteractableComponent_ResetInteraction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UReuseDialogueInteractableComponent_ResetInteraction_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UReuseDialogueInteractableComponent_ResetInteraction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UReuseDialogueInteractableComponent_ResetInteraction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UReuseDialogueInteractableComponent::execResetInteraction)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetInteraction();
	P_NATIVE_END;
}
// ********** End Class UReuseDialogueInteractableComponent Function ResetInteraction **************

// ********** Begin Class UReuseDialogueInteractableComponent **************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UReuseDialogueInteractableComponent;
UClass* UReuseDialogueInteractableComponent::GetPrivateStaticClass()
{
	using TClass = UReuseDialogueInteractableComponent;
	if (!Z_Registration_Info_UClass_UReuseDialogueInteractableComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ReuseDialogueInteractableComponent"),
			Z_Registration_Info_UClass_UReuseDialogueInteractableComponent.InnerSingleton,
			StaticRegisterNativesUReuseDialogueInteractableComponent,
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
	return Z_Registration_Info_UClass_UReuseDialogueInteractableComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UReuseDialogueInteractableComponent_NoRegister()
{
	return UReuseDialogueInteractableComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * JMInteraction \xec\x9a\x94\xec\xb2\xad\xec\x9d\x84 ReusableDialogueSystem \xec\x9e\xac\xec\x83\x9d \xec\x9a\x94\xec\xb2\xad\xec\x9c\xbc\xeb\xa1\x9c \xeb\xb3\x80\xed\x99\x98\xed\x95\x98\xeb\x8a\x94 \xec\x96\xb4\xeb\x8c\x91\xed\x84\xb0 \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8\xeb\x8b\xa4.\n */" },
#endif
		{ "IncludePath", "Interaction/ReuseDialogueInteractableComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Interaction/ReuseDialogueInteractableComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "JMInteraction \xec\x9a\x94\xec\xb2\xad\xec\x9d\x84 ReusableDialogueSystem \xec\x9e\xac\xec\x83\x9d \xec\x9a\x94\xec\xb2\xad\xec\x9c\xbc\xeb\xa1\x9c \xeb\xb3\x80\xed\x99\x98\xed\x95\x98\xeb\x8a\x94 \xec\x96\xb4\xeb\x8c\x91\xed\x84\xb0 \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DialogueSequence_MetaData[] = {
		{ "Category", "Dialogue|Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xec\x83\x81\xed\x98\xb8\xec\x9e\x91\xec\x9a\xa9 \xec\x8b\x9c \xec\x9e\xac\xec\x83\x9d\xed\x95\xa0 Dialogue Sequence Data Asset. */" },
#endif
		{ "ModuleRelativePath", "Public/Interaction/ReuseDialogueInteractableComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x83\x81\xed\x98\xb8\xec\x9e\x91\xec\x9a\xa9 \xec\x8b\x9c \xec\x9e\xac\xec\x83\x9d\xed\x95\xa0 Dialogue Sequence Data Asset." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionPrompt_MetaData[] = {
		{ "Category", "Dialogue|Interaction" },
		{ "ModuleRelativePath", "Public/Interaction/ReuseDialogueInteractableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionDuration_MetaData[] = {
		{ "Category", "Dialogue|Interaction" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/Interaction/ReuseDialogueInteractableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionPriority_MetaData[] = {
		{ "Category", "Dialogue|Interaction" },
		{ "ModuleRelativePath", "Public/Interaction/ReuseDialogueInteractableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionMode_MetaData[] = {
		{ "Category", "Dialogue|Playback" },
		{ "ModuleRelativePath", "Public/Interaction/ReuseDialogueInteractableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExistingDialoguePolicy_MetaData[] = {
		{ "Category", "Dialogue|Playback" },
		{ "ModuleRelativePath", "Public/Interaction/ReuseDialogueInteractableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bInteractionEnabled_MetaData[] = {
		{ "Category", "Dialogue|Interaction" },
		{ "ModuleRelativePath", "Public/Interaction/ReuseDialogueInteractableComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowRepeat_MetaData[] = {
		{ "Category", "Dialogue|Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xeb\x81\x84\xeb\xa9\xb4 Dialogue\xea\xb0\x80 \xed\x95\x9c \xeb\xb2\x88 \xec\x84\xb1\xea\xb3\xb5\xec\xa0\x81\xec\x9c\xbc\xeb\xa1\x9c \xec\x8b\x9c\xec\x9e\x91\xeb\x90\x9c \xeb\x92\xa4 \xeb\x8d\x94 \xec\x9d\xb4\xec\x83\x81 \xec\x83\x81\xed\x98\xb8\xec\x9e\x91\xec\x9a\xa9\xed\x95\xa0 \xec\x88\x98 \xec\x97\x86\xeb\x8b\xa4. */" },
#endif
		{ "ModuleRelativePath", "Public/Interaction/ReuseDialogueInteractableComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\x81\x84\xeb\xa9\xb4 Dialogue\xea\xb0\x80 \xed\x95\x9c \xeb\xb2\x88 \xec\x84\xb1\xea\xb3\xb5\xec\xa0\x81\xec\x9c\xbc\xeb\xa1\x9c \xec\x8b\x9c\xec\x9e\x91\xeb\x90\x9c \xeb\x92\xa4 \xeb\x8d\x94 \xec\x9d\xb4\xec\x83\x81 \xec\x83\x81\xed\x98\xb8\xec\x9e\x91\xec\x9a\xa9\xed\x95\xa0 \xec\x88\x98 \xec\x97\x86\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasStartedDialogue_MetaData[] = {
		{ "ModuleRelativePath", "Public/Interaction/ReuseDialogueInteractableComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UReuseDialogueInteractableComponent constinit property declarations ******
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_DialogueSequence;
	static const UECodeGen_Private::FTextPropertyParams NewProp_InteractionPrompt;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InteractionDuration;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InteractionPriority;
	static const UECodeGen_Private::FBytePropertyParams NewProp_InteractionMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InteractionMode;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ExistingDialoguePolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ExistingDialoguePolicy;
	static void NewProp_bInteractionEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInteractionEnabled;
	static void NewProp_bAllowRepeat_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowRepeat;
	static void NewProp_bHasStartedDialogue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasStartedDialogue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UReuseDialogueInteractableComponent constinit property declarations ********
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("HasStartedDialogue"), .Pointer = &UReuseDialogueInteractableComponent::execHasStartedDialogue },
		{ .NameUTF8 = UTF8TEXT("ResetInteraction"), .Pointer = &UReuseDialogueInteractableComponent::execResetInteraction },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UReuseDialogueInteractableComponent_HasStartedDialogue, "HasStartedDialogue" }, // 3177329095
		{ &Z_Construct_UFunction_UReuseDialogueInteractableComponent_ResetInteraction, "ResetInteraction" }, // 2016616888
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UReuseDialogueInteractableComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics

// ********** Begin Class UReuseDialogueInteractableComponent Property Definitions *****************
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_DialogueSequence = { "DialogueSequence", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UReuseDialogueInteractableComponent, DialogueSequence), Z_Construct_UClass_UDialogueSequence_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DialogueSequence_MetaData), NewProp_DialogueSequence_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_InteractionPrompt = { "InteractionPrompt", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UReuseDialogueInteractableComponent, InteractionPrompt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionPrompt_MetaData), NewProp_InteractionPrompt_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_InteractionDuration = { "InteractionDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UReuseDialogueInteractableComponent, InteractionDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionDuration_MetaData), NewProp_InteractionDuration_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_InteractionPriority = { "InteractionPriority", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UReuseDialogueInteractableComponent, InteractionPriority), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionPriority_MetaData), NewProp_InteractionPriority_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_InteractionMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_InteractionMode = { "InteractionMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UReuseDialogueInteractableComponent, InteractionMode), Z_Construct_UEnum_ReusableDialogueSystem_EDialogueInteractionMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionMode_MetaData), NewProp_InteractionMode_MetaData) }; // 3853692148
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_ExistingDialoguePolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_ExistingDialoguePolicy = { "ExistingDialoguePolicy", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UReuseDialogueInteractableComponent, ExistingDialoguePolicy), Z_Construct_UEnum_ReusableDialogueSystem_EExistingDialoguePolicy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExistingDialoguePolicy_MetaData), NewProp_ExistingDialoguePolicy_MetaData) }; // 3634757249
void Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_bInteractionEnabled_SetBit(void* Obj)
{
	((UReuseDialogueInteractableComponent*)Obj)->bInteractionEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_bInteractionEnabled = { "bInteractionEnabled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UReuseDialogueInteractableComponent), &Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_bInteractionEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bInteractionEnabled_MetaData), NewProp_bInteractionEnabled_MetaData) };
void Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_bAllowRepeat_SetBit(void* Obj)
{
	((UReuseDialogueInteractableComponent*)Obj)->bAllowRepeat = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_bAllowRepeat = { "bAllowRepeat", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UReuseDialogueInteractableComponent), &Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_bAllowRepeat_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowRepeat_MetaData), NewProp_bAllowRepeat_MetaData) };
void Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_bHasStartedDialogue_SetBit(void* Obj)
{
	((UReuseDialogueInteractableComponent*)Obj)->bHasStartedDialogue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_bHasStartedDialogue = { "bHasStartedDialogue", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UReuseDialogueInteractableComponent), &Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_bHasStartedDialogue_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasStartedDialogue_MetaData), NewProp_bHasStartedDialogue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_DialogueSequence,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_InteractionPrompt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_InteractionDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_InteractionPriority,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_InteractionMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_InteractionMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_ExistingDialoguePolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_ExistingDialoguePolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_bInteractionEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_bAllowRepeat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::NewProp_bHasStartedDialogue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::PropPointers) < 2048);
// ********** End Class UReuseDialogueInteractableComponent Property Definitions *******************
UObject* (*const Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_ReusableDialogueSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UJMInteractableInterface_NoRegister, (int32)VTABLE_OFFSET(UReuseDialogueInteractableComponent, IJMInteractableInterface), false },  // 680874699
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::ClassParams = {
	&UReuseDialogueInteractableComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::Class_MetaDataParams)
};
void UReuseDialogueInteractableComponent::StaticRegisterNativesUReuseDialogueInteractableComponent()
{
	UClass* Class = UReuseDialogueInteractableComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_UReuseDialogueInteractableComponent()
{
	if (!Z_Registration_Info_UClass_UReuseDialogueInteractableComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UReuseDialogueInteractableComponent.OuterSingleton, Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UReuseDialogueInteractableComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UReuseDialogueInteractableComponent);
UReuseDialogueInteractableComponent::~UReuseDialogueInteractableComponent() {}
// ********** End Class UReuseDialogueInteractableComponent ****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Interaction_ReuseDialogueInteractableComponent_h__Script_ReusableDialogueSystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UReuseDialogueInteractableComponent, UReuseDialogueInteractableComponent::StaticClass, TEXT("UReuseDialogueInteractableComponent"), &Z_Registration_Info_UClass_UReuseDialogueInteractableComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UReuseDialogueInteractableComponent), 2045573379U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Interaction_ReuseDialogueInteractableComponent_h__Script_ReusableDialogueSystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Interaction_ReuseDialogueInteractableComponent_h__Script_ReusableDialogueSystem_3316091308{
	TEXT("/Script/ReusableDialogueSystem"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Interaction_ReuseDialogueInteractableComponent_h__Script_ReusableDialogueSystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Interaction_ReuseDialogueInteractableComponent_h__Script_ReusableDialogueSystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
