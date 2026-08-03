// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Interfaces/InventoryItemUseReceiverInterface.h"

#ifdef INVENTORYSYSTEM_InventoryItemUseReceiverInterface_generated_h
#error "InventoryItemUseReceiverInterface.generated.h already included, missing '#pragma once' in InventoryItemUseReceiverInterface.h"
#endif
#define INVENTORYSYSTEM_InventoryItemUseReceiverInterface_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UInventoryComponent;
struct FInventorySlot;

// ********** Begin Interface UInventoryItemUseReceiverInterface ***********************************
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemUseReceiverInterface_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool ReceiveInventoryItemUse_Implementation(AActor* User, UInventoryComponent* Inventory, FInventorySlot const& Slot) { return false; }; \
	virtual bool CanReceiveInventoryItemUse_Implementation(AActor* User, UInventoryComponent* Inventory, FInventorySlot const& Slot) const { return false; }; \
	DECLARE_FUNCTION(execReceiveInventoryItemUse); \
	DECLARE_FUNCTION(execCanReceiveInventoryItemUse);


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemUseReceiverInterface_h_17_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UInventoryItemUseReceiverInterface_Statics;
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryItemUseReceiverInterface_NoRegister();

#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemUseReceiverInterface_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventoryItemUseReceiverInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UInventoryItemUseReceiverInterface(UInventoryItemUseReceiverInterface&&) = delete; \
	UInventoryItemUseReceiverInterface(const UInventoryItemUseReceiverInterface&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryItemUseReceiverInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryItemUseReceiverInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryItemUseReceiverInterface) \
	virtual ~UInventoryItemUseReceiverInterface() = default;


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemUseReceiverInterface_h_17_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUInventoryItemUseReceiverInterface(); \
	friend struct ::Z_Construct_UClass_UInventoryItemUseReceiverInterface_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend INVENTORYSYSTEM_API UClass* ::Z_Construct_UClass_UInventoryItemUseReceiverInterface_NoRegister(); \
public: \
	DECLARE_CLASS2(UInventoryItemUseReceiverInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/InventorySystem"), Z_Construct_UClass_UInventoryItemUseReceiverInterface_NoRegister) \
	DECLARE_SERIALIZER(UInventoryItemUseReceiverInterface)


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemUseReceiverInterface_h_17_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemUseReceiverInterface_h_17_GENERATED_UINTERFACE_BODY() \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemUseReceiverInterface_h_17_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemUseReceiverInterface_h_17_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IInventoryItemUseReceiverInterface() {} \
public: \
	typedef UInventoryItemUseReceiverInterface UClassType; \
	typedef IInventoryItemUseReceiverInterface ThisClass; \
	static bool Execute_CanReceiveInventoryItemUse(const UObject* O, AActor* User, UInventoryComponent* Inventory, FInventorySlot const& Slot); \
	static bool Execute_ReceiveInventoryItemUse(UObject* O, AActor* User, UInventoryComponent* Inventory, FInventorySlot const& Slot); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemUseReceiverInterface_h_14_PROLOG
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemUseReceiverInterface_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemUseReceiverInterface_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemUseReceiverInterface_h_17_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemUseReceiverInterface_h_17_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UInventoryItemUseReceiverInterface;

// ********** End Interface UInventoryItemUseReceiverInterface *************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_Interfaces_InventoryItemUseReceiverInterface_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
