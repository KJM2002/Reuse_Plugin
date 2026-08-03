// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Interaction/ReuseDialogueInteractableComponent.h"

#ifdef REUSABLEDIALOGUESYSTEM_ReuseDialogueInteractableComponent_generated_h
#error "ReuseDialogueInteractableComponent.generated.h already included, missing '#pragma once' in ReuseDialogueInteractableComponent.h"
#endif
#define REUSABLEDIALOGUESYSTEM_ReuseDialogueInteractableComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UReuseDialogueInteractableComponent **************************************
#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Interaction_ReuseDialogueInteractableComponent_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHasStartedDialogue); \
	DECLARE_FUNCTION(execResetInteraction);


struct Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics;
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UReuseDialogueInteractableComponent_NoRegister();

#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Interaction_ReuseDialogueInteractableComponent_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUReuseDialogueInteractableComponent(); \
	friend struct ::Z_Construct_UClass_UReuseDialogueInteractableComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend REUSABLEDIALOGUESYSTEM_API UClass* ::Z_Construct_UClass_UReuseDialogueInteractableComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UReuseDialogueInteractableComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ReusableDialogueSystem"), Z_Construct_UClass_UReuseDialogueInteractableComponent_NoRegister) \
	DECLARE_SERIALIZER(UReuseDialogueInteractableComponent) \
	virtual UObject* _getUObject() const override { return const_cast<UReuseDialogueInteractableComponent*>(this); }


#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Interaction_ReuseDialogueInteractableComponent_h_18_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UReuseDialogueInteractableComponent(UReuseDialogueInteractableComponent&&) = delete; \
	UReuseDialogueInteractableComponent(const UReuseDialogueInteractableComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UReuseDialogueInteractableComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UReuseDialogueInteractableComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UReuseDialogueInteractableComponent) \
	NO_API virtual ~UReuseDialogueInteractableComponent();


#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Interaction_ReuseDialogueInteractableComponent_h_15_PROLOG
#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Interaction_ReuseDialogueInteractableComponent_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Interaction_ReuseDialogueInteractableComponent_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Interaction_ReuseDialogueInteractableComponent_h_18_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Interaction_ReuseDialogueInteractableComponent_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UReuseDialogueInteractableComponent;

// ********** End Class UReuseDialogueInteractableComponent ****************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Interaction_ReuseDialogueInteractableComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
