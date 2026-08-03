// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Interfaces/JMDoorSaveInterface.h"

#ifdef JMDOORRUNTIME_JMDoorSaveInterface_generated_h
#error "JMDoorSaveInterface.generated.h already included, missing '#pragma once' in JMDoorSaveInterface.h"
#endif
#define JMDOORRUNTIME_JMDoorSaveInterface_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGuid;
struct FJMDoorSaveData;

// ********** Begin Interface UJMDoorSaveInterface *************************************************
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorSaveInterface_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool RestoreDoorSaveData_Implementation(FJMDoorSaveData const& SaveData) { return false; }; \
	virtual FJMDoorSaveData CaptureDoorSaveData_Implementation() const { return FJMDoorSaveData(); }; \
	virtual FGuid GetDoorPersistentId_Implementation() const { return FGuid(); }; \
	DECLARE_FUNCTION(execRestoreDoorSaveData); \
	DECLARE_FUNCTION(execCaptureDoorSaveData); \
	DECLARE_FUNCTION(execGetDoorPersistentId);


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorSaveInterface_h_11_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UJMDoorSaveInterface_Statics;
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorSaveInterface_NoRegister();

#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorSaveInterface_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMDoorSaveInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMDoorSaveInterface(UJMDoorSaveInterface&&) = delete; \
	UJMDoorSaveInterface(const UJMDoorSaveInterface&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMDoorSaveInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMDoorSaveInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMDoorSaveInterface) \
	virtual ~UJMDoorSaveInterface() = default;


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorSaveInterface_h_11_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUJMDoorSaveInterface(); \
	friend struct ::Z_Construct_UClass_UJMDoorSaveInterface_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMDOORRUNTIME_API UClass* ::Z_Construct_UClass_UJMDoorSaveInterface_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMDoorSaveInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/JMDoorRuntime"), Z_Construct_UClass_UJMDoorSaveInterface_NoRegister) \
	DECLARE_SERIALIZER(UJMDoorSaveInterface)


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorSaveInterface_h_11_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorSaveInterface_h_11_GENERATED_UINTERFACE_BODY() \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorSaveInterface_h_11_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorSaveInterface_h_11_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IJMDoorSaveInterface() {} \
public: \
	typedef UJMDoorSaveInterface UClassType; \
	typedef IJMDoorSaveInterface ThisClass; \
	static FJMDoorSaveData Execute_CaptureDoorSaveData(const UObject* O); \
	static FGuid Execute_GetDoorPersistentId(const UObject* O); \
	static bool Execute_RestoreDoorSaveData(UObject* O, FJMDoorSaveData const& SaveData); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorSaveInterface_h_8_PROLOG
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorSaveInterface_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorSaveInterface_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorSaveInterface_h_11_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorSaveInterface_h_11_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMDoorSaveInterface;

// ********** End Interface UJMDoorSaveInterface ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorSaveInterface_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
