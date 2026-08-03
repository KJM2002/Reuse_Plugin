// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ItemInspection/JMItemInspectionTypes.h"

#ifdef ITEMINSPECTORRUNTIME_JMItemInspectionTypes_generated_h
#error "JMItemInspectionTypes.generated.h already included, missing '#pragma once' in JMItemInspectionTypes.h"
#endif
#define ITEMINSPECTORRUNTIME_JMItemInspectionTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FJMItemInspectionSurfaceWidgetSettings ****************************
struct Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics;
#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionTypes_h_59_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMItemInspectionSurfaceWidgetSettings_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMItemInspectionSurfaceWidgetSettings;
// ********** End ScriptStruct FJMItemInspectionSurfaceWidgetSettings ******************************

// ********** Begin ScriptStruct FJMItemInspectionPreviewLightingSettings **************************
struct Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics;
#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionTypes_h_99_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMItemInspectionPreviewLightingSettings_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMItemInspectionPreviewLightingSettings;
// ********** End ScriptStruct FJMItemInspectionPreviewLightingSettings ****************************

// ********** Begin ScriptStruct FJMItemInspectionViewSettings *************************************
struct Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics;
#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionTypes_h_141_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMItemInspectionViewSettings_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMItemInspectionViewSettings;
// ********** End ScriptStruct FJMItemInspectionViewSettings ***************************************

// ********** Begin ScriptStruct FJMItemInspectionTransitionSettings *******************************
struct Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics;
#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionTypes_h_181_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMItemInspectionTransitionSettings_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMItemInspectionTransitionSettings;
// ********** End ScriptStruct FJMItemInspectionTransitionSettings *********************************

// ********** Begin ScriptStruct FJMItemInspectionRequest ******************************************
struct Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics;
#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionTypes_h_223_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMItemInspectionRequest_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMItemInspectionRequest;
// ********** End ScriptStruct FJMItemInspectionRequest ********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionTypes_h

// ********** Begin Enum EJMItemInspectionState ****************************************************
#define FOREACH_ENUM_EJMITEMINSPECTIONSTATE(op) \
	op(EJMItemInspectionState::Closed) \
	op(EJMItemInspectionState::Loading) \
	op(EJMItemInspectionState::Opening) \
	op(EJMItemInspectionState::TransitioningIn) \
	op(EJMItemInspectionState::Inspecting) \
	op(EJMItemInspectionState::TransitioningOut) \
	op(EJMItemInspectionState::Closing) \
	op(EJMItemInspectionState::Failed) 

enum class EJMItemInspectionState : uint8;
template<> struct TIsUEnumClass<EJMItemInspectionState> { enum { Value = true }; };
template<> ITEMINSPECTORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMItemInspectionState>();
// ********** End Enum EJMItemInspectionState ******************************************************

// ********** Begin Enum EJMItemInspectionTransitionEasing *****************************************
#define FOREACH_ENUM_EJMITEMINSPECTIONTRANSITIONEASING(op) \
	op(EJMItemInspectionTransitionEasing::Linear) \
	op(EJMItemInspectionTransitionEasing::EaseOutCubic) \
	op(EJMItemInspectionTransitionEasing::EaseOutBack) 

enum class EJMItemInspectionTransitionEasing : uint8;
template<> struct TIsUEnumClass<EJMItemInspectionTransitionEasing> { enum { Value = true }; };
template<> ITEMINSPECTORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMItemInspectionTransitionEasing>();
// ********** End Enum EJMItemInspectionTransitionEasing *******************************************

// ********** Begin Enum EJMItemInspectionCloseReason **********************************************
#define FOREACH_ENUM_EJMITEMINSPECTIONCLOSEREASON(op) \
	op(EJMItemInspectionCloseReason::User) \
	op(EJMItemInspectionCloseReason::CloseButton) \
	op(EJMItemInspectionCloseReason::ExternalRequest) \
	op(EJMItemInspectionCloseReason::SourceInvalid) \
	op(EJMItemInspectionCloseReason::WorldTearDown) \
	op(EJMItemInspectionCloseReason::Replaced) \
	op(EJMItemInspectionCloseReason::Failed) 

enum class EJMItemInspectionCloseReason : uint8;
template<> struct TIsUEnumClass<EJMItemInspectionCloseReason> { enum { Value = true }; };
template<> ITEMINSPECTORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMItemInspectionCloseReason>();
// ********** End Enum EJMItemInspectionCloseReason ************************************************

// ********** Begin Enum EJMItemInspectionLightingPreset *******************************************
#define FOREACH_ENUM_EJMITEMINSPECTIONLIGHTINGPRESET(op) \
	op(EJMItemInspectionLightingPreset::SoftStudio) \
	op(EJMItemInspectionLightingPreset::BrightProduct) \
	op(EJMItemInspectionLightingPreset::WarmDramatic) \
	op(EJMItemInspectionLightingPreset::CoolRim) \
	op(EJMItemInspectionLightingPreset::Flat) 

enum class EJMItemInspectionLightingPreset : uint8;
template<> struct TIsUEnumClass<EJMItemInspectionLightingPreset> { enum { Value = true }; };
template<> ITEMINSPECTORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMItemInspectionLightingPreset>();
// ********** End Enum EJMItemInspectionLightingPreset *********************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
