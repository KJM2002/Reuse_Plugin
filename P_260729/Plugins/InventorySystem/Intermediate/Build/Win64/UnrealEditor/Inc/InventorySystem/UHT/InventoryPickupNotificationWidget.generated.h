// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/InventoryPickupNotificationWidget.h"

#ifdef INVENTORYSYSTEM_InventoryPickupNotificationWidget_generated_h
#error "InventoryPickupNotificationWidget.generated.h already included, missing '#pragma once' in InventoryPickupNotificationWidget.h"
#endif
#define INVENTORYSYSTEM_InventoryPickupNotificationWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UTexture2D;

// ********** Begin Class UInventoryPickupNotificationWidget ***************************************
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryPickupNotificationWidget_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execShowItemNotification); \
	DECLARE_FUNCTION(execShowNotification);


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryPickupNotificationWidget_h_17_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UInventoryPickupNotificationWidget_Statics;
INVENTORYSYSTEM_API UClass* Z_Construct_UClass_UInventoryPickupNotificationWidget_NoRegister();

#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryPickupNotificationWidget_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInventoryPickupNotificationWidget(); \
	friend struct ::Z_Construct_UClass_UInventoryPickupNotificationWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend INVENTORYSYSTEM_API UClass* ::Z_Construct_UClass_UInventoryPickupNotificationWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UInventoryPickupNotificationWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/InventorySystem"), Z_Construct_UClass_UInventoryPickupNotificationWidget_NoRegister) \
	DECLARE_SERIALIZER(UInventoryPickupNotificationWidget)


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryPickupNotificationWidget_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventoryPickupNotificationWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UInventoryPickupNotificationWidget(UInventoryPickupNotificationWidget&&) = delete; \
	UInventoryPickupNotificationWidget(const UInventoryPickupNotificationWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryPickupNotificationWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryPickupNotificationWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryPickupNotificationWidget) \
	NO_API virtual ~UInventoryPickupNotificationWidget();


#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryPickupNotificationWidget_h_14_PROLOG
#define FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryPickupNotificationWidget_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryPickupNotificationWidget_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryPickupNotificationWidget_h_17_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryPickupNotificationWidget_h_17_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryPickupNotificationWidget_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UInventoryPickupNotificationWidget;

// ********** End Class UInventoryPickupNotificationWidget *****************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_InventorySystem_Source_InventorySystem_Public_UI_InventoryPickupNotificationWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
