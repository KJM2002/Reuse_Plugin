// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Payloads/DialogueEventPayload.h"

#ifdef REUSABLEDIALOGUESYSTEM_DialogueEventPayload_generated_h
#error "DialogueEventPayload.generated.h already included, missing '#pragma once' in DialogueEventPayload.h"
#endif
#define REUSABLEDIALOGUESYSTEM_DialogueEventPayload_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UDialogueEventPayload ****************************************************
struct Z_Construct_UClass_UDialogueEventPayload_Statics;
REUSABLEDIALOGUESYSTEM_API UClass* Z_Construct_UClass_UDialogueEventPayload_NoRegister();

#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Payloads_DialogueEventPayload_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDialogueEventPayload(); \
	friend struct ::Z_Construct_UClass_UDialogueEventPayload_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend REUSABLEDIALOGUESYSTEM_API UClass* ::Z_Construct_UClass_UDialogueEventPayload_NoRegister(); \
public: \
	DECLARE_CLASS2(UDialogueEventPayload, UJMGameplayEventPayloadBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/ReusableDialogueSystem"), Z_Construct_UClass_UDialogueEventPayload_NoRegister) \
	DECLARE_SERIALIZER(UDialogueEventPayload)


#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Payloads_DialogueEventPayload_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDialogueEventPayload(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDialogueEventPayload(UDialogueEventPayload&&) = delete; \
	UDialogueEventPayload(const UDialogueEventPayload&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDialogueEventPayload); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDialogueEventPayload); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDialogueEventPayload) \
	NO_API virtual ~UDialogueEventPayload();


#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Payloads_DialogueEventPayload_h_11_PROLOG
#define FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Payloads_DialogueEventPayload_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Payloads_DialogueEventPayload_h_14_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Payloads_DialogueEventPayload_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDialogueEventPayload;

// ********** End Class UDialogueEventPayload ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_ReusableDialogueSystem_Source_ReusableDialogueSystem_Public_Payloads_DialogueEventPayload_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
