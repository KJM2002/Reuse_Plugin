// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Data/JMDoorConfigData.h"

#ifdef JMDOORRUNTIME_JMDoorConfigData_generated_h
#error "JMDoorConfigData.generated.h already included, missing '#pragma once' in JMDoorConfigData.h"
#endif
#define JMDOORRUNTIME_JMDoorConfigData_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UJMDoorConfigData ********************************************************
struct Z_Construct_UClass_UJMDoorConfigData_Statics;
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorConfigData_NoRegister();

#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Data_JMDoorConfigData_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMDoorConfigData(); \
	friend struct ::Z_Construct_UClass_UJMDoorConfigData_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMDOORRUNTIME_API UClass* ::Z_Construct_UClass_UJMDoorConfigData_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMDoorConfigData, UPrimaryDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/JMDoorRuntime"), Z_Construct_UClass_UJMDoorConfigData_NoRegister) \
	DECLARE_SERIALIZER(UJMDoorConfigData)


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Data_JMDoorConfigData_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMDoorConfigData(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMDoorConfigData(UJMDoorConfigData&&) = delete; \
	UJMDoorConfigData(const UJMDoorConfigData&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMDoorConfigData); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMDoorConfigData); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMDoorConfigData) \
	NO_API virtual ~UJMDoorConfigData();


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Data_JMDoorConfigData_h_9_PROLOG
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Data_JMDoorConfigData_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Data_JMDoorConfigData_h_12_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Data_JMDoorConfigData_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMDoorConfigData;

// ********** End Class UJMDoorConfigData **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Data_JMDoorConfigData_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
