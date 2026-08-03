// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ItemInspection/JMItemInspectionTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMItemInspectionTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMItemInspectionData_NoRegister();
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase_NoRegister();
ITEMINSPECTORRUNTIME_API UEnum* Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionCloseReason();
ITEMINSPECTORRUNTIME_API UEnum* Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionLightingPreset();
ITEMINSPECTORRUNTIME_API UEnum* Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionState();
ITEMINSPECTORRUNTIME_API UEnum* Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionTransitionEasing();
ITEMINSPECTORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings();
ITEMINSPECTORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMItemInspectionRequest();
ITEMINSPECTORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings();
ITEMINSPECTORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings();
ITEMINSPECTORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FJMItemInspectionViewSettings();
UPackage* Z_Construct_UPackage__Script_ItemInspectorRuntime();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EJMItemInspectionState ****************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMItemInspectionState;
static UEnum* EJMItemInspectionState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMItemInspectionState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMItemInspectionState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionState, (UObject*)Z_Construct_UPackage__Script_ItemInspectorRuntime(), TEXT("EJMItemInspectionState"));
	}
	return Z_Registration_Info_UEnum_EJMItemInspectionState.OuterSingleton;
}
template<> ITEMINSPECTORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMItemInspectionState>()
{
	return EJMItemInspectionState_StaticEnum();
}
struct Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Closed.Name", "EJMItemInspectionState::Closed" },
		{ "Closing.Name", "EJMItemInspectionState::Closing" },
		{ "Failed.Name", "EJMItemInspectionState::Failed" },
		{ "Inspecting.Name", "EJMItemInspectionState::Inspecting" },
		{ "Loading.Name", "EJMItemInspectionState::Loading" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
		{ "Opening.Name", "EJMItemInspectionState::Opening" },
		{ "TransitioningIn.Name", "EJMItemInspectionState::TransitioningIn" },
		{ "TransitioningOut.Name", "EJMItemInspectionState::TransitioningOut" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMItemInspectionState::Closed", (int64)EJMItemInspectionState::Closed },
		{ "EJMItemInspectionState::Loading", (int64)EJMItemInspectionState::Loading },
		{ "EJMItemInspectionState::Opening", (int64)EJMItemInspectionState::Opening },
		{ "EJMItemInspectionState::TransitioningIn", (int64)EJMItemInspectionState::TransitioningIn },
		{ "EJMItemInspectionState::Inspecting", (int64)EJMItemInspectionState::Inspecting },
		{ "EJMItemInspectionState::TransitioningOut", (int64)EJMItemInspectionState::TransitioningOut },
		{ "EJMItemInspectionState::Closing", (int64)EJMItemInspectionState::Closing },
		{ "EJMItemInspectionState::Failed", (int64)EJMItemInspectionState::Failed },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionState_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ItemInspectorRuntime,
	nullptr,
	"EJMItemInspectionState",
	"EJMItemInspectionState",
	Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionState()
{
	if (!Z_Registration_Info_UEnum_EJMItemInspectionState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMItemInspectionState.InnerSingleton, Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMItemInspectionState.InnerSingleton;
}
// ********** End Enum EJMItemInspectionState ******************************************************

// ********** Begin Enum EJMItemInspectionTransitionEasing *****************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMItemInspectionTransitionEasing;
static UEnum* EJMItemInspectionTransitionEasing_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMItemInspectionTransitionEasing.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMItemInspectionTransitionEasing.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionTransitionEasing, (UObject*)Z_Construct_UPackage__Script_ItemInspectorRuntime(), TEXT("EJMItemInspectionTransitionEasing"));
	}
	return Z_Registration_Info_UEnum_EJMItemInspectionTransitionEasing.OuterSingleton;
}
template<> ITEMINSPECTORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMItemInspectionTransitionEasing>()
{
	return EJMItemInspectionTransitionEasing_StaticEnum();
}
struct Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionTransitionEasing_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "EaseOutBack.Name", "EJMItemInspectionTransitionEasing::EaseOutBack" },
		{ "EaseOutCubic.Name", "EJMItemInspectionTransitionEasing::EaseOutCubic" },
		{ "Linear.Name", "EJMItemInspectionTransitionEasing::Linear" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMItemInspectionTransitionEasing::Linear", (int64)EJMItemInspectionTransitionEasing::Linear },
		{ "EJMItemInspectionTransitionEasing::EaseOutCubic", (int64)EJMItemInspectionTransitionEasing::EaseOutCubic },
		{ "EJMItemInspectionTransitionEasing::EaseOutBack", (int64)EJMItemInspectionTransitionEasing::EaseOutBack },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionTransitionEasing_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionTransitionEasing_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ItemInspectorRuntime,
	nullptr,
	"EJMItemInspectionTransitionEasing",
	"EJMItemInspectionTransitionEasing",
	Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionTransitionEasing_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionTransitionEasing_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionTransitionEasing_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionTransitionEasing_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionTransitionEasing()
{
	if (!Z_Registration_Info_UEnum_EJMItemInspectionTransitionEasing.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMItemInspectionTransitionEasing.InnerSingleton, Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionTransitionEasing_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMItemInspectionTransitionEasing.InnerSingleton;
}
// ********** End Enum EJMItemInspectionTransitionEasing *******************************************

// ********** Begin Enum EJMItemInspectionCloseReason **********************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMItemInspectionCloseReason;
static UEnum* EJMItemInspectionCloseReason_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMItemInspectionCloseReason.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMItemInspectionCloseReason.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionCloseReason, (UObject*)Z_Construct_UPackage__Script_ItemInspectorRuntime(), TEXT("EJMItemInspectionCloseReason"));
	}
	return Z_Registration_Info_UEnum_EJMItemInspectionCloseReason.OuterSingleton;
}
template<> ITEMINSPECTORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMItemInspectionCloseReason>()
{
	return EJMItemInspectionCloseReason_StaticEnum();
}
struct Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionCloseReason_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CloseButton.Name", "EJMItemInspectionCloseReason::CloseButton" },
		{ "ExternalRequest.Name", "EJMItemInspectionCloseReason::ExternalRequest" },
		{ "Failed.Name", "EJMItemInspectionCloseReason::Failed" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
		{ "Replaced.Name", "EJMItemInspectionCloseReason::Replaced" },
		{ "SourceInvalid.Name", "EJMItemInspectionCloseReason::SourceInvalid" },
		{ "User.Name", "EJMItemInspectionCloseReason::User" },
		{ "WorldTearDown.Name", "EJMItemInspectionCloseReason::WorldTearDown" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMItemInspectionCloseReason::User", (int64)EJMItemInspectionCloseReason::User },
		{ "EJMItemInspectionCloseReason::CloseButton", (int64)EJMItemInspectionCloseReason::CloseButton },
		{ "EJMItemInspectionCloseReason::ExternalRequest", (int64)EJMItemInspectionCloseReason::ExternalRequest },
		{ "EJMItemInspectionCloseReason::SourceInvalid", (int64)EJMItemInspectionCloseReason::SourceInvalid },
		{ "EJMItemInspectionCloseReason::WorldTearDown", (int64)EJMItemInspectionCloseReason::WorldTearDown },
		{ "EJMItemInspectionCloseReason::Replaced", (int64)EJMItemInspectionCloseReason::Replaced },
		{ "EJMItemInspectionCloseReason::Failed", (int64)EJMItemInspectionCloseReason::Failed },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionCloseReason_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionCloseReason_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ItemInspectorRuntime,
	nullptr,
	"EJMItemInspectionCloseReason",
	"EJMItemInspectionCloseReason",
	Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionCloseReason_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionCloseReason_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionCloseReason_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionCloseReason_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionCloseReason()
{
	if (!Z_Registration_Info_UEnum_EJMItemInspectionCloseReason.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMItemInspectionCloseReason.InnerSingleton, Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionCloseReason_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMItemInspectionCloseReason.InnerSingleton;
}
// ********** End Enum EJMItemInspectionCloseReason ************************************************

// ********** Begin Enum EJMItemInspectionLightingPreset *******************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJMItemInspectionLightingPreset;
static UEnum* EJMItemInspectionLightingPreset_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJMItemInspectionLightingPreset.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJMItemInspectionLightingPreset.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionLightingPreset, (UObject*)Z_Construct_UPackage__Script_ItemInspectorRuntime(), TEXT("EJMItemInspectionLightingPreset"));
	}
	return Z_Registration_Info_UEnum_EJMItemInspectionLightingPreset.OuterSingleton;
}
template<> ITEMINSPECTORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMItemInspectionLightingPreset>()
{
	return EJMItemInspectionLightingPreset_StaticEnum();
}
struct Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionLightingPreset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "BrightProduct.Name", "EJMItemInspectionLightingPreset::BrightProduct" },
		{ "CoolRim.Name", "EJMItemInspectionLightingPreset::CoolRim" },
		{ "Flat.Name", "EJMItemInspectionLightingPreset::Flat" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
		{ "SoftStudio.Name", "EJMItemInspectionLightingPreset::SoftStudio" },
		{ "WarmDramatic.Name", "EJMItemInspectionLightingPreset::WarmDramatic" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJMItemInspectionLightingPreset::SoftStudio", (int64)EJMItemInspectionLightingPreset::SoftStudio },
		{ "EJMItemInspectionLightingPreset::BrightProduct", (int64)EJMItemInspectionLightingPreset::BrightProduct },
		{ "EJMItemInspectionLightingPreset::WarmDramatic", (int64)EJMItemInspectionLightingPreset::WarmDramatic },
		{ "EJMItemInspectionLightingPreset::CoolRim", (int64)EJMItemInspectionLightingPreset::CoolRim },
		{ "EJMItemInspectionLightingPreset::Flat", (int64)EJMItemInspectionLightingPreset::Flat },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionLightingPreset_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionLightingPreset_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ItemInspectorRuntime,
	nullptr,
	"EJMItemInspectionLightingPreset",
	"EJMItemInspectionLightingPreset",
	Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionLightingPreset_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionLightingPreset_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionLightingPreset_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionLightingPreset_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionLightingPreset()
{
	if (!Z_Registration_Info_UEnum_EJMItemInspectionLightingPreset.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJMItemInspectionLightingPreset.InnerSingleton, Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionLightingPreset_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJMItemInspectionLightingPreset.InnerSingleton;
}
// ********** End Enum EJMItemInspectionLightingPreset *********************************************

// ********** Begin ScriptStruct FJMItemInspectionSurfaceWidgetSettings ****************************
struct Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMItemInspectionSurfaceWidgetSettings); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMItemInspectionSurfaceWidgetSettings); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Optional world-space UMG content attached to the inspected mesh.\n * The widget lives only for the inspection session and follows preview rotation/zoom.\n */" },
#endif
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional world-space UMG content attached to the inspected mesh.\nThe widget lives only for the inspection session and follows preview rotation/zoom." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Surface Widget" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WidgetClass_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Surface Widget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** A subclass of UJMItemInspectionSurfaceWidgetBase. Null safely uses the native fallback widget. */" },
#endif
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A subclass of UJMItemInspectionSurfaceWidgetBase. Null safely uses the native fallback widget." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseDescriptionAsContent_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Surface Widget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Per-item text rendered by the surface widget. */" },
#endif
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Per-item text rendered by the surface widget." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Content_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Surface Widget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Used only when bUseDescriptionAsContent is false. */" },
#endif
		{ "EditCondition", "!bUseDescriptionAsContent" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
		{ "MultiLine", "TRUE" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Used only when bUseDescriptionAsContent is false." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DrawSize_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Surface Widget" },
		{ "ClampMin", "64" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Widget render resolution. World size is controlled by SurfaceTransform.Scale3D. */" },
#endif
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Widget render resolution. World size is controlled by SurfaceTransform.Scale3D." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SurfaceTransform_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Surface Widget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Local transform relative to the same pivot that rotates the preview mesh. */" },
#endif
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Local transform relative to the same pivot that rotates the preview mesh." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bTwoSided_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Surface Widget" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMItemInspectionSurfaceWidgetSettings constinit property declarations 
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_WidgetClass;
	static void NewProp_bUseDescriptionAsContent_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseDescriptionAsContent;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Content;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DrawSize;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SurfaceTransform;
	static void NewProp_bTwoSided_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bTwoSided;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMItemInspectionSurfaceWidgetSettings constinit property declarations 
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMItemInspectionSurfaceWidgetSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings;
class UScriptStruct* FJMItemInspectionSurfaceWidgetSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings, (UObject*)Z_Construct_UPackage__Script_ItemInspectorRuntime(), TEXT("JMItemInspectionSurfaceWidgetSettings"));
	}
	return Z_Registration_Info_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMItemInspectionSurfaceWidgetSettings Property Definitions *******
void Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((FJMItemInspectionSurfaceWidgetSettings*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMItemInspectionSurfaceWidgetSettings), &Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::NewProp_WidgetClass = { "WidgetClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionSurfaceWidgetSettings, WidgetClass), Z_Construct_UClass_UJMItemInspectionSurfaceWidgetBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WidgetClass_MetaData), NewProp_WidgetClass_MetaData) };
void Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::NewProp_bUseDescriptionAsContent_SetBit(void* Obj)
{
	((FJMItemInspectionSurfaceWidgetSettings*)Obj)->bUseDescriptionAsContent = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::NewProp_bUseDescriptionAsContent = { "bUseDescriptionAsContent", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMItemInspectionSurfaceWidgetSettings), &Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::NewProp_bUseDescriptionAsContent_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseDescriptionAsContent_MetaData), NewProp_bUseDescriptionAsContent_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::NewProp_Content = { "Content", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionSurfaceWidgetSettings, Content), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Content_MetaData), NewProp_Content_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::NewProp_DrawSize = { "DrawSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionSurfaceWidgetSettings, DrawSize), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DrawSize_MetaData), NewProp_DrawSize_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::NewProp_SurfaceTransform = { "SurfaceTransform", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionSurfaceWidgetSettings, SurfaceTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SurfaceTransform_MetaData), NewProp_SurfaceTransform_MetaData) };
void Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::NewProp_bTwoSided_SetBit(void* Obj)
{
	((FJMItemInspectionSurfaceWidgetSettings*)Obj)->bTwoSided = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::NewProp_bTwoSided = { "bTwoSided", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMItemInspectionSurfaceWidgetSettings), &Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::NewProp_bTwoSided_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bTwoSided_MetaData), NewProp_bTwoSided_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::NewProp_bEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::NewProp_WidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::NewProp_bUseDescriptionAsContent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::NewProp_Content,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::NewProp_DrawSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::NewProp_SurfaceTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::NewProp_bTwoSided,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMItemInspectionSurfaceWidgetSettings Property Definitions *********
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ItemInspectorRuntime,
	nullptr,
	&NewStructOps,
	"JMItemInspectionSurfaceWidgetSettings",
	Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::PropPointers),
	sizeof(FJMItemInspectionSurfaceWidgetSettings),
	alignof(FJMItemInspectionSurfaceWidgetSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings()
{
	if (!Z_Registration_Info_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings.InnerSingleton, Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings.InnerSingleton);
}
// ********** End ScriptStruct FJMItemInspectionSurfaceWidgetSettings ******************************

// ********** Begin ScriptStruct FJMItemInspectionPreviewLightingSettings **************************
struct Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMItemInspectionPreviewLightingSettings); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMItemInspectionPreviewLightingSettings); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LightingPreset_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Lighting" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IntensityMultiplier_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Lighting" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsolateFromWorldLighting_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Lighting" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCastPreviewShadows_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Lighting" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAffectTranslucentLighting_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Lighting" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverridePreset_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Lighting|Custom" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_KeyLightIntensity_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Lighting|Custom" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bOverridePreset" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_KeyLightColor_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Lighting|Custom" },
		{ "EditCondition", "bOverridePreset" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FillLightIntensity_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Lighting|Custom" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bOverridePreset" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FillLightColor_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Lighting|Custom" },
		{ "EditCondition", "bOverridePreset" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RimLightIntensity_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Lighting|Custom" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bOverridePreset" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RimLightColor_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Lighting|Custom" },
		{ "EditCondition", "bOverridePreset" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMItemInspectionPreviewLightingSettings constinit property declarations 
	static const UECodeGen_Private::FBytePropertyParams NewProp_LightingPreset_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_LightingPreset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_IntensityMultiplier;
	static void NewProp_bIsolateFromWorldLighting_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsolateFromWorldLighting;
	static void NewProp_bCastPreviewShadows_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCastPreviewShadows;
	static void NewProp_bAffectTranslucentLighting_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAffectTranslucentLighting;
	static void NewProp_bOverridePreset_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverridePreset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_KeyLightIntensity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_KeyLightColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FillLightIntensity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FillLightColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RimLightIntensity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RimLightColor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMItemInspectionPreviewLightingSettings constinit property declarations 
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMItemInspectionPreviewLightingSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMItemInspectionPreviewLightingSettings;
class UScriptStruct* FJMItemInspectionPreviewLightingSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMItemInspectionPreviewLightingSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMItemInspectionPreviewLightingSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings, (UObject*)Z_Construct_UPackage__Script_ItemInspectorRuntime(), TEXT("JMItemInspectionPreviewLightingSettings"));
	}
	return Z_Registration_Info_UScriptStruct_FJMItemInspectionPreviewLightingSettings.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMItemInspectionPreviewLightingSettings Property Definitions *****
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_LightingPreset_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_LightingPreset = { "LightingPreset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionPreviewLightingSettings, LightingPreset), Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionLightingPreset, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LightingPreset_MetaData), NewProp_LightingPreset_MetaData) }; // 1717559547
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_IntensityMultiplier = { "IntensityMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionPreviewLightingSettings, IntensityMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IntensityMultiplier_MetaData), NewProp_IntensityMultiplier_MetaData) };
void Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_bIsolateFromWorldLighting_SetBit(void* Obj)
{
	((FJMItemInspectionPreviewLightingSettings*)Obj)->bIsolateFromWorldLighting = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_bIsolateFromWorldLighting = { "bIsolateFromWorldLighting", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMItemInspectionPreviewLightingSettings), &Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_bIsolateFromWorldLighting_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsolateFromWorldLighting_MetaData), NewProp_bIsolateFromWorldLighting_MetaData) };
void Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_bCastPreviewShadows_SetBit(void* Obj)
{
	((FJMItemInspectionPreviewLightingSettings*)Obj)->bCastPreviewShadows = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_bCastPreviewShadows = { "bCastPreviewShadows", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMItemInspectionPreviewLightingSettings), &Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_bCastPreviewShadows_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCastPreviewShadows_MetaData), NewProp_bCastPreviewShadows_MetaData) };
void Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_bAffectTranslucentLighting_SetBit(void* Obj)
{
	((FJMItemInspectionPreviewLightingSettings*)Obj)->bAffectTranslucentLighting = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_bAffectTranslucentLighting = { "bAffectTranslucentLighting", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMItemInspectionPreviewLightingSettings), &Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_bAffectTranslucentLighting_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAffectTranslucentLighting_MetaData), NewProp_bAffectTranslucentLighting_MetaData) };
void Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_bOverridePreset_SetBit(void* Obj)
{
	((FJMItemInspectionPreviewLightingSettings*)Obj)->bOverridePreset = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_bOverridePreset = { "bOverridePreset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMItemInspectionPreviewLightingSettings), &Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_bOverridePreset_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverridePreset_MetaData), NewProp_bOverridePreset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_KeyLightIntensity = { "KeyLightIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionPreviewLightingSettings, KeyLightIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_KeyLightIntensity_MetaData), NewProp_KeyLightIntensity_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_KeyLightColor = { "KeyLightColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionPreviewLightingSettings, KeyLightColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_KeyLightColor_MetaData), NewProp_KeyLightColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_FillLightIntensity = { "FillLightIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionPreviewLightingSettings, FillLightIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FillLightIntensity_MetaData), NewProp_FillLightIntensity_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_FillLightColor = { "FillLightColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionPreviewLightingSettings, FillLightColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FillLightColor_MetaData), NewProp_FillLightColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_RimLightIntensity = { "RimLightIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionPreviewLightingSettings, RimLightIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RimLightIntensity_MetaData), NewProp_RimLightIntensity_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_RimLightColor = { "RimLightColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionPreviewLightingSettings, RimLightColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RimLightColor_MetaData), NewProp_RimLightColor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_LightingPreset_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_LightingPreset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_IntensityMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_bIsolateFromWorldLighting,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_bCastPreviewShadows,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_bAffectTranslucentLighting,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_bOverridePreset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_KeyLightIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_KeyLightColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_FillLightIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_FillLightColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_RimLightIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewProp_RimLightColor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMItemInspectionPreviewLightingSettings Property Definitions *******
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ItemInspectorRuntime,
	nullptr,
	&NewStructOps,
	"JMItemInspectionPreviewLightingSettings",
	Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::PropPointers),
	sizeof(FJMItemInspectionPreviewLightingSettings),
	alignof(FJMItemInspectionPreviewLightingSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings()
{
	if (!Z_Registration_Info_UScriptStruct_FJMItemInspectionPreviewLightingSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMItemInspectionPreviewLightingSettings.InnerSingleton, Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMItemInspectionPreviewLightingSettings.InnerSingleton);
}
// ********** End ScriptStruct FJMItemInspectionPreviewLightingSettings ****************************

// ********** Begin ScriptStruct FJMItemInspectionViewSettings *************************************
struct Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMItemInspectionViewSettings); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMItemInspectionViewSettings); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewOffset_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InitialRotation_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewScale_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotationSensitivity_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowPitchRotation_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowYawRotation_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowZoom_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InitialZoom_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinZoom_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxZoom_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LightingSettings_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMItemInspectionViewSettings constinit property declarations *****
	static const UECodeGen_Private::FStructPropertyParams NewProp_PreviewOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InitialRotation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PreviewScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotationSensitivity;
	static void NewProp_bAllowPitchRotation_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowPitchRotation;
	static void NewProp_bAllowYawRotation_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowYawRotation;
	static void NewProp_bAllowZoom_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowZoom;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InitialZoom;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinZoom;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxZoom;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LightingSettings;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMItemInspectionViewSettings constinit property declarations *******
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMItemInspectionViewSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMItemInspectionViewSettings;
class UScriptStruct* FJMItemInspectionViewSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMItemInspectionViewSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMItemInspectionViewSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMItemInspectionViewSettings, (UObject*)Z_Construct_UPackage__Script_ItemInspectorRuntime(), TEXT("JMItemInspectionViewSettings"));
	}
	return Z_Registration_Info_UScriptStruct_FJMItemInspectionViewSettings.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMItemInspectionViewSettings Property Definitions ****************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_PreviewOffset = { "PreviewOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionViewSettings, PreviewOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewOffset_MetaData), NewProp_PreviewOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_InitialRotation = { "InitialRotation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionViewSettings, InitialRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InitialRotation_MetaData), NewProp_InitialRotation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_PreviewScale = { "PreviewScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionViewSettings, PreviewScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewScale_MetaData), NewProp_PreviewScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_RotationSensitivity = { "RotationSensitivity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionViewSettings, RotationSensitivity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotationSensitivity_MetaData), NewProp_RotationSensitivity_MetaData) };
void Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_bAllowPitchRotation_SetBit(void* Obj)
{
	((FJMItemInspectionViewSettings*)Obj)->bAllowPitchRotation = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_bAllowPitchRotation = { "bAllowPitchRotation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMItemInspectionViewSettings), &Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_bAllowPitchRotation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowPitchRotation_MetaData), NewProp_bAllowPitchRotation_MetaData) };
void Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_bAllowYawRotation_SetBit(void* Obj)
{
	((FJMItemInspectionViewSettings*)Obj)->bAllowYawRotation = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_bAllowYawRotation = { "bAllowYawRotation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMItemInspectionViewSettings), &Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_bAllowYawRotation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowYawRotation_MetaData), NewProp_bAllowYawRotation_MetaData) };
void Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_bAllowZoom_SetBit(void* Obj)
{
	((FJMItemInspectionViewSettings*)Obj)->bAllowZoom = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_bAllowZoom = { "bAllowZoom", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMItemInspectionViewSettings), &Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_bAllowZoom_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowZoom_MetaData), NewProp_bAllowZoom_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_InitialZoom = { "InitialZoom", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionViewSettings, InitialZoom), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InitialZoom_MetaData), NewProp_InitialZoom_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_MinZoom = { "MinZoom", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionViewSettings, MinZoom), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinZoom_MetaData), NewProp_MinZoom_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_MaxZoom = { "MaxZoom", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionViewSettings, MaxZoom), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxZoom_MetaData), NewProp_MaxZoom_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_LightingSettings = { "LightingSettings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionViewSettings, LightingSettings), Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LightingSettings_MetaData), NewProp_LightingSettings_MetaData) }; // 2876893561
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_PreviewOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_InitialRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_PreviewScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_RotationSensitivity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_bAllowPitchRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_bAllowYawRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_bAllowZoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_InitialZoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_MinZoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_MaxZoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewProp_LightingSettings,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMItemInspectionViewSettings Property Definitions ******************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ItemInspectorRuntime,
	nullptr,
	&NewStructOps,
	"JMItemInspectionViewSettings",
	Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::PropPointers),
	sizeof(FJMItemInspectionViewSettings),
	alignof(FJMItemInspectionViewSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMItemInspectionViewSettings()
{
	if (!Z_Registration_Info_UScriptStruct_FJMItemInspectionViewSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMItemInspectionViewSettings.InnerSingleton, Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMItemInspectionViewSettings.InnerSingleton);
}
// ********** End ScriptStruct FJMItemInspectionViewSettings ***************************************

// ********** Begin ScriptStruct FJMItemInspectionTransitionSettings *******************************
struct Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMItemInspectionTransitionSettings); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMItemInspectionTransitionSettings); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Controls the optional world-item-to-inspector entrance transition. */" },
#endif
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Controls the optional world-item-to-inspector entrance transition." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableEnterTransition_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Transition" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableExitTransition_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Transition" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnterDuration_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Transition" },
		{ "ClampMin", "0.01" },
		{ "EditCondition", "bEnableEnterTransition" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExitDuration_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Transition" },
		{ "ClampMin", "0.01" },
		{ "EditCondition", "bEnableExitTransition" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceHideDelay_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Transition" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bEnableEnterTransition" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
		{ "Units", "s" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InspectorFadeStartAlpha_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Transition" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bEnableEnterTransition" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Easing_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Transition" },
		{ "EditCondition", "bEnableEnterTransition" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHideSourceActorDuringInspection_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Transition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Keeps the level actor hidden after the transition until inspection closes. */" },
#endif
		{ "EditCondition", "bEnableEnterTransition" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Keeps the level actor hidden after the transition until inspection closes." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMItemInspectionTransitionSettings constinit property declarations 
	static void NewProp_bEnableEnterTransition_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableEnterTransition;
	static void NewProp_bEnableExitTransition_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableExitTransition;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EnterDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ExitDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SourceHideDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InspectorFadeStartAlpha;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Easing_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Easing;
	static void NewProp_bHideSourceActorDuringInspection_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHideSourceActorDuringInspection;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMItemInspectionTransitionSettings constinit property declarations *
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMItemInspectionTransitionSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMItemInspectionTransitionSettings;
class UScriptStruct* FJMItemInspectionTransitionSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMItemInspectionTransitionSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMItemInspectionTransitionSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings, (UObject*)Z_Construct_UPackage__Script_ItemInspectorRuntime(), TEXT("JMItemInspectionTransitionSettings"));
	}
	return Z_Registration_Info_UScriptStruct_FJMItemInspectionTransitionSettings.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMItemInspectionTransitionSettings Property Definitions **********
void Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_bEnableEnterTransition_SetBit(void* Obj)
{
	((FJMItemInspectionTransitionSettings*)Obj)->bEnableEnterTransition = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_bEnableEnterTransition = { "bEnableEnterTransition", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMItemInspectionTransitionSettings), &Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_bEnableEnterTransition_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableEnterTransition_MetaData), NewProp_bEnableEnterTransition_MetaData) };
void Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_bEnableExitTransition_SetBit(void* Obj)
{
	((FJMItemInspectionTransitionSettings*)Obj)->bEnableExitTransition = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_bEnableExitTransition = { "bEnableExitTransition", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMItemInspectionTransitionSettings), &Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_bEnableExitTransition_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableExitTransition_MetaData), NewProp_bEnableExitTransition_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_EnterDuration = { "EnterDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionTransitionSettings, EnterDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnterDuration_MetaData), NewProp_EnterDuration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_ExitDuration = { "ExitDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionTransitionSettings, ExitDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExitDuration_MetaData), NewProp_ExitDuration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_SourceHideDelay = { "SourceHideDelay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionTransitionSettings, SourceHideDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceHideDelay_MetaData), NewProp_SourceHideDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_InspectorFadeStartAlpha = { "InspectorFadeStartAlpha", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionTransitionSettings, InspectorFadeStartAlpha), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InspectorFadeStartAlpha_MetaData), NewProp_InspectorFadeStartAlpha_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_Easing_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_Easing = { "Easing", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionTransitionSettings, Easing), Z_Construct_UEnum_ItemInspectorRuntime_EJMItemInspectionTransitionEasing, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Easing_MetaData), NewProp_Easing_MetaData) }; // 268475694
void Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_bHideSourceActorDuringInspection_SetBit(void* Obj)
{
	((FJMItemInspectionTransitionSettings*)Obj)->bHideSourceActorDuringInspection = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_bHideSourceActorDuringInspection = { "bHideSourceActorDuringInspection", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMItemInspectionTransitionSettings), &Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_bHideSourceActorDuringInspection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHideSourceActorDuringInspection_MetaData), NewProp_bHideSourceActorDuringInspection_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_bEnableEnterTransition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_bEnableExitTransition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_EnterDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_ExitDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_SourceHideDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_InspectorFadeStartAlpha,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_Easing_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_Easing,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewProp_bHideSourceActorDuringInspection,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMItemInspectionTransitionSettings Property Definitions ************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ItemInspectorRuntime,
	nullptr,
	&NewStructOps,
	"JMItemInspectionTransitionSettings",
	Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::PropPointers),
	sizeof(FJMItemInspectionTransitionSettings),
	alignof(FJMItemInspectionTransitionSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings()
{
	if (!Z_Registration_Info_UScriptStruct_FJMItemInspectionTransitionSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMItemInspectionTransitionSettings.InnerSingleton, Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMItemInspectionTransitionSettings.InnerSingleton);
}
// ********** End ScriptStruct FJMItemInspectionTransitionSettings *********************************

// ********** Begin ScriptStruct FJMItemInspectionRequest ******************************************
struct Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FJMItemInspectionRequest); }
	static inline consteval int16 GetStructAlignment() { return alignof(FJMItemInspectionRequest); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InspectionData_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceActor_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequestSource_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPauseGame_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bBlockPlayerInput_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHideSourceActor_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowClose_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideTransitionSettings_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Transition" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDisableExitTransition_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Transition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Integration paths such as inspect-before-pickup can suppress returning to a world source. */" },
#endif
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Integration paths such as inspect-before-pickup can suppress returning to a world source." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseSimpleUITransition_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Transition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Uses a simple full-widget fade when opening from another UI instead of a world actor. */" },
#endif
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Uses a simple full-widget fade when opening from another UI instead of a world actor." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TransitionSettings_MetaData[] = {
		{ "Category", "JM Gameplay|Item Inspection|Transition" },
		{ "EditCondition", "bOverrideTransitionSettings" },
		{ "ModuleRelativePath", "Public/ItemInspection/JMItemInspectionTypes.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FJMItemInspectionRequest constinit property declarations **********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InspectionData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SourceActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RequestSource;
	static void NewProp_bPauseGame_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPauseGame;
	static void NewProp_bBlockPlayerInput_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bBlockPlayerInput;
	static void NewProp_bHideSourceActor_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHideSourceActor;
	static void NewProp_bAllowClose_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowClose;
	static void NewProp_bOverrideTransitionSettings_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideTransitionSettings;
	static void NewProp_bDisableExitTransition_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDisableExitTransition;
	static void NewProp_bUseSimpleUITransition_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseSimpleUITransition;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TransitionSettings;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FJMItemInspectionRequest constinit property declarations ************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJMItemInspectionRequest>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FJMItemInspectionRequest;
class UScriptStruct* FJMItemInspectionRequest::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FJMItemInspectionRequest.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FJMItemInspectionRequest.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJMItemInspectionRequest, (UObject*)Z_Construct_UPackage__Script_ItemInspectorRuntime(), TEXT("JMItemInspectionRequest"));
	}
	return Z_Registration_Info_UScriptStruct_FJMItemInspectionRequest.OuterSingleton;
	}

// ********** Begin ScriptStruct FJMItemInspectionRequest Property Definitions *********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_InspectionData = { "InspectionData", nullptr, (EPropertyFlags)0x0114000000000004, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionRequest, InspectionData), Z_Construct_UClass_UJMItemInspectionData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InspectionData_MetaData), NewProp_InspectionData_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_SourceActor = { "SourceActor", nullptr, (EPropertyFlags)0x0114000000000004, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionRequest, SourceActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceActor_MetaData), NewProp_SourceActor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_RequestSource = { "RequestSource", nullptr, (EPropertyFlags)0x0114000000000004, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionRequest, RequestSource), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequestSource_MetaData), NewProp_RequestSource_MetaData) };
void Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bPauseGame_SetBit(void* Obj)
{
	((FJMItemInspectionRequest*)Obj)->bPauseGame = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bPauseGame = { "bPauseGame", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMItemInspectionRequest), &Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bPauseGame_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPauseGame_MetaData), NewProp_bPauseGame_MetaData) };
void Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bBlockPlayerInput_SetBit(void* Obj)
{
	((FJMItemInspectionRequest*)Obj)->bBlockPlayerInput = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bBlockPlayerInput = { "bBlockPlayerInput", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMItemInspectionRequest), &Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bBlockPlayerInput_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bBlockPlayerInput_MetaData), NewProp_bBlockPlayerInput_MetaData) };
void Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bHideSourceActor_SetBit(void* Obj)
{
	((FJMItemInspectionRequest*)Obj)->bHideSourceActor = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bHideSourceActor = { "bHideSourceActor", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMItemInspectionRequest), &Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bHideSourceActor_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHideSourceActor_MetaData), NewProp_bHideSourceActor_MetaData) };
void Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bAllowClose_SetBit(void* Obj)
{
	((FJMItemInspectionRequest*)Obj)->bAllowClose = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bAllowClose = { "bAllowClose", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMItemInspectionRequest), &Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bAllowClose_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowClose_MetaData), NewProp_bAllowClose_MetaData) };
void Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bOverrideTransitionSettings_SetBit(void* Obj)
{
	((FJMItemInspectionRequest*)Obj)->bOverrideTransitionSettings = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bOverrideTransitionSettings = { "bOverrideTransitionSettings", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMItemInspectionRequest), &Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bOverrideTransitionSettings_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOverrideTransitionSettings_MetaData), NewProp_bOverrideTransitionSettings_MetaData) };
void Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bDisableExitTransition_SetBit(void* Obj)
{
	((FJMItemInspectionRequest*)Obj)->bDisableExitTransition = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bDisableExitTransition = { "bDisableExitTransition", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMItemInspectionRequest), &Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bDisableExitTransition_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDisableExitTransition_MetaData), NewProp_bDisableExitTransition_MetaData) };
void Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bUseSimpleUITransition_SetBit(void* Obj)
{
	((FJMItemInspectionRequest*)Obj)->bUseSimpleUITransition = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bUseSimpleUITransition = { "bUseSimpleUITransition", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FJMItemInspectionRequest), &Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bUseSimpleUITransition_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseSimpleUITransition_MetaData), NewProp_bUseSimpleUITransition_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_TransitionSettings = { "TransitionSettings", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FJMItemInspectionRequest, TransitionSettings), Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TransitionSettings_MetaData), NewProp_TransitionSettings_MetaData) }; // 1121746411
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_InspectionData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_SourceActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_RequestSource,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bPauseGame,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bBlockPlayerInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bHideSourceActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bAllowClose,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bOverrideTransitionSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bDisableExitTransition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_bUseSimpleUITransition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewProp_TransitionSettings,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FJMItemInspectionRequest Property Definitions ***********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ItemInspectorRuntime,
	nullptr,
	&NewStructOps,
	"JMItemInspectionRequest",
	Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::PropPointers),
	sizeof(FJMItemInspectionRequest),
	alignof(FJMItemInspectionRequest),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FJMItemInspectionRequest()
{
	if (!Z_Registration_Info_UScriptStruct_FJMItemInspectionRequest.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FJMItemInspectionRequest.InnerSingleton, Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FJMItemInspectionRequest.InnerSingleton);
}
// ********** End ScriptStruct FJMItemInspectionRequest ********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionTypes_h__Script_ItemInspectorRuntime_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EJMItemInspectionState_StaticEnum, TEXT("EJMItemInspectionState"), &Z_Registration_Info_UEnum_EJMItemInspectionState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4115607530U) },
		{ EJMItemInspectionTransitionEasing_StaticEnum, TEXT("EJMItemInspectionTransitionEasing"), &Z_Registration_Info_UEnum_EJMItemInspectionTransitionEasing, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 268475694U) },
		{ EJMItemInspectionCloseReason_StaticEnum, TEXT("EJMItemInspectionCloseReason"), &Z_Registration_Info_UEnum_EJMItemInspectionCloseReason, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1865201677U) },
		{ EJMItemInspectionLightingPreset_StaticEnum, TEXT("EJMItemInspectionLightingPreset"), &Z_Registration_Info_UEnum_EJMItemInspectionLightingPreset, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1717559547U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FJMItemInspectionSurfaceWidgetSettings::StaticStruct, Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics::NewStructOps, TEXT("JMItemInspectionSurfaceWidgetSettings"),&Z_Registration_Info_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMItemInspectionSurfaceWidgetSettings), 2221587353U) },
		{ FJMItemInspectionPreviewLightingSettings::StaticStruct, Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics::NewStructOps, TEXT("JMItemInspectionPreviewLightingSettings"),&Z_Registration_Info_UScriptStruct_FJMItemInspectionPreviewLightingSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMItemInspectionPreviewLightingSettings), 2876893561U) },
		{ FJMItemInspectionViewSettings::StaticStruct, Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics::NewStructOps, TEXT("JMItemInspectionViewSettings"),&Z_Registration_Info_UScriptStruct_FJMItemInspectionViewSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMItemInspectionViewSettings), 1658798872U) },
		{ FJMItemInspectionTransitionSettings::StaticStruct, Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics::NewStructOps, TEXT("JMItemInspectionTransitionSettings"),&Z_Registration_Info_UScriptStruct_FJMItemInspectionTransitionSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMItemInspectionTransitionSettings), 1121746411U) },
		{ FJMItemInspectionRequest::StaticStruct, Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics::NewStructOps, TEXT("JMItemInspectionRequest"),&Z_Registration_Info_UScriptStruct_FJMItemInspectionRequest, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJMItemInspectionRequest), 417983221U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionTypes_h__Script_ItemInspectorRuntime_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionTypes_h__Script_ItemInspectorRuntime_3482899741{
	TEXT("/Script/ItemInspectorRuntime"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionTypes_h__Script_ItemInspectorRuntime_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionTypes_h__Script_ItemInspectorRuntime_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionTypes_h__Script_ItemInspectorRuntime_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionTypes_h__Script_ItemInspectorRuntime_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
