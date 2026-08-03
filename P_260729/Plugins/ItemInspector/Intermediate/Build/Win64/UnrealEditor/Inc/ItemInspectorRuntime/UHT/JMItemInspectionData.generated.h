// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ItemInspection/JMItemInspectionData.h"

#ifdef ITEMINSPECTORRUNTIME_JMItemInspectionData_generated_h
#error "JMItemInspectionData.generated.h already included, missing '#pragma once' in JMItemInspectionData.h"
#endif
#define ITEMINSPECTORRUNTIME_JMItemInspectionData_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UJMItemInspectionData ****************************************************
struct Z_Construct_UClass_UJMItemInspectionData_Statics;
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UJMItemInspectionData_NoRegister();

#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionData_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMItemInspectionData(); \
	friend struct ::Z_Construct_UClass_UJMItemInspectionData_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ITEMINSPECTORRUNTIME_API UClass* ::Z_Construct_UClass_UJMItemInspectionData_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMItemInspectionData, UPrimaryDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ItemInspectorRuntime"), Z_Construct_UClass_UJMItemInspectionData_NoRegister) \
	DECLARE_SERIALIZER(UJMItemInspectionData)


#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionData_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMItemInspectionData(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMItemInspectionData(UJMItemInspectionData&&) = delete; \
	UJMItemInspectionData(const UJMItemInspectionData&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMItemInspectionData); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMItemInspectionData); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMItemInspectionData) \
	NO_API virtual ~UJMItemInspectionData();


#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionData_h_12_PROLOG
#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionData_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionData_h_15_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionData_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMItemInspectionData;

// ********** End Class UJMItemInspectionData ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_ItemInspection_JMItemInspectionData_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
