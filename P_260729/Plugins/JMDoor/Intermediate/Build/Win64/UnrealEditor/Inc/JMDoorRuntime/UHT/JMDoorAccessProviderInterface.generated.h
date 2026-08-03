// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Interfaces/JMDoorAccessProviderInterface.h"

#ifdef JMDOORRUNTIME_JMDoorAccessProviderInterface_generated_h
#error "JMDoorAccessProviderInterface.generated.h already included, missing '#pragma once' in JMDoorAccessProviderInterface.h"
#endif
#define JMDOORRUNTIME_JMDoorAccessProviderInterface_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGameplayTagContainer;
struct FJMDoorAccessRequirement;

// ********** Begin Interface UJMDoorAccessProviderInterface ***************************************
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorAccessProviderInterface_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool ConsumeDoorAccess_Implementation(FJMDoorAccessRequirement const& Requirement) { return false; }; \
	virtual bool CanProvideDoorAccess_Implementation(FJMDoorAccessRequirement const& Requirement) const { return false; }; \
	virtual FGameplayTagContainer GetDoorAccessTags_Implementation() const { return FGameplayTagContainer(); }; \
	DECLARE_FUNCTION(execConsumeDoorAccess); \
	DECLARE_FUNCTION(execCanProvideDoorAccess); \
	DECLARE_FUNCTION(execGetDoorAccessTags);


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorAccessProviderInterface_h_11_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UJMDoorAccessProviderInterface_Statics;
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorAccessProviderInterface_NoRegister();

#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorAccessProviderInterface_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMDoorAccessProviderInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMDoorAccessProviderInterface(UJMDoorAccessProviderInterface&&) = delete; \
	UJMDoorAccessProviderInterface(const UJMDoorAccessProviderInterface&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMDoorAccessProviderInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMDoorAccessProviderInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMDoorAccessProviderInterface) \
	virtual ~UJMDoorAccessProviderInterface() = default;


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorAccessProviderInterface_h_11_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUJMDoorAccessProviderInterface(); \
	friend struct ::Z_Construct_UClass_UJMDoorAccessProviderInterface_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMDOORRUNTIME_API UClass* ::Z_Construct_UClass_UJMDoorAccessProviderInterface_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMDoorAccessProviderInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/JMDoorRuntime"), Z_Construct_UClass_UJMDoorAccessProviderInterface_NoRegister) \
	DECLARE_SERIALIZER(UJMDoorAccessProviderInterface)


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorAccessProviderInterface_h_11_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorAccessProviderInterface_h_11_GENERATED_UINTERFACE_BODY() \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorAccessProviderInterface_h_11_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorAccessProviderInterface_h_11_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IJMDoorAccessProviderInterface() {} \
public: \
	typedef UJMDoorAccessProviderInterface UClassType; \
	typedef IJMDoorAccessProviderInterface ThisClass; \
	static bool Execute_CanProvideDoorAccess(const UObject* O, FJMDoorAccessRequirement const& Requirement); \
	static bool Execute_ConsumeDoorAccess(UObject* O, FJMDoorAccessRequirement const& Requirement); \
	static FGameplayTagContainer Execute_GetDoorAccessTags(const UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorAccessProviderInterface_h_8_PROLOG
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorAccessProviderInterface_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorAccessProviderInterface_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorAccessProviderInterface_h_11_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorAccessProviderInterface_h_11_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMDoorAccessProviderInterface;

// ********** End Interface UJMDoorAccessProviderInterface *****************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorAccessProviderInterface_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
