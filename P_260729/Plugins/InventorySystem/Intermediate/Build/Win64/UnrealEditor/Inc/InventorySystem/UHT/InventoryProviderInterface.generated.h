// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Interfaces/InventoryProviderInterface.h"

#ifdef INVENTORYSYSTEM_InventoryProviderInterface_generated_h
#error "InventoryProviderInterface.generated.h already included, missing '#pragma once' in InventoryProviderInterface.h"
#endif
#define INVENTORYSYSTEM_InventoryProviderInterface_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UInventoryComponent;

// ********** Begin Interface UInventoryProviderInterface ******************************************
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryProviderInterface_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual UInventoryComponent* GetInventoryComponent_Implementation() const { return NULL; }; \
	DECLARE_FUNCTION(execGetInventoryComponent);


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryProviderInterface_h_12_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UInventoryProviderInterface_Statics;
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryProviderInterface_NoRegister();

#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryProviderInterface_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventoryProviderInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UInventoryProviderInterface(UInventoryProviderInterface&&) = delete; \
	UInventoryProviderInterface(const UInventoryProviderInterface&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryProviderInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryProviderInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryProviderInterface) \
	virtual ~UInventoryProviderInterface() = default;


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryProviderInterface_h_12_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUInventoryProviderInterface(); \
	friend struct ::Z_Construct_UClass_UInventoryProviderInterface_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend INVENTORYSYSTEM_API UClass* ::Z_Construct_UClass_UInventoryProviderInterface_NoRegister(); \
public: \
	DECLARE_CLASS2(UInventoryProviderInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/InventorySystem"), Z_Construct_UClass_UInventoryProviderInterface_NoRegister) \
	DECLARE_SERIALIZER(UInventoryProviderInterface)


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryProviderInterface_h_12_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryProviderInterface_h_12_GENERATED_UINTERFACE_BODY() \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryProviderInterface_h_12_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryProviderInterface_h_12_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IInventoryProviderInterface() {} \
public: \
	typedef UInventoryProviderInterface UClassType; \
	typedef IInventoryProviderInterface ThisClass; \
	static UInventoryComponent* Execute_GetInventoryComponent(const UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryProviderInterface_h_9_PROLOG
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryProviderInterface_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryProviderInterface_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryProviderInterface_h_12_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryProviderInterface_h_12_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UInventoryProviderInterface;

// ********** End Interface UInventoryProviderInterface ********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryProviderInterface_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
