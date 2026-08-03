// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/ItemInspectorSettings.h"

#ifdef ITEMINSPECTORRUNTIME_ItemInspectorSettings_generated_h
#error "ItemInspectorSettings.generated.h already included, missing '#pragma once' in ItemInspectorSettings.h"
#endif
#define ITEMINSPECTORRUNTIME_ItemInspectorSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UItemInspectorSettings ***************************************************
struct Z_Construct_UClass_UItemInspectorSettings_Statics;
ITEMINSPECTORRUNTIME_API UClass* Z_Construct_UClass_UItemInspectorSettings_NoRegister();

#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_Core_ItemInspectorSettings_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUItemInspectorSettings(); \
	friend struct ::Z_Construct_UClass_UItemInspectorSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ITEMINSPECTORRUNTIME_API UClass* ::Z_Construct_UClass_UItemInspectorSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UItemInspectorSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/ItemInspectorRuntime"), Z_Construct_UClass_UItemInspectorSettings_NoRegister) \
	DECLARE_SERIALIZER(UItemInspectorSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_Core_ItemInspectorSettings_h_21_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UItemInspectorSettings(UItemInspectorSettings&&) = delete; \
	UItemInspectorSettings(const UItemInspectorSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UItemInspectorSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UItemInspectorSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UItemInspectorSettings) \
	NO_API virtual ~UItemInspectorSettings();


#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_Core_ItemInspectorSettings_h_18_PROLOG
#define FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_Core_ItemInspectorSettings_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_Core_ItemInspectorSettings_h_21_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_Core_ItemInspectorSettings_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UItemInspectorSettings;

// ********** End Class UItemInspectorSettings *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_ItemInspector_Source_ItemInspectorRuntime_Public_Core_ItemInspectorSettings_h

// ********** Begin Enum EJMItemInspectionDuplicatePolicy ******************************************
#define FOREACH_ENUM_EJMITEMINSPECTIONDUPLICATEPOLICY(op) \
	op(EJMItemInspectionDuplicatePolicy::RejectNewRequest) \
	op(EJMItemInspectionDuplicatePolicy::ReplaceCurrent) 

enum class EJMItemInspectionDuplicatePolicy : uint8;
template<> struct TIsUEnumClass<EJMItemInspectionDuplicatePolicy> { enum { Value = true }; };
template<> ITEMINSPECTORRUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMItemInspectionDuplicatePolicy>();
// ********** End Enum EJMItemInspectionDuplicatePolicy ********************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
