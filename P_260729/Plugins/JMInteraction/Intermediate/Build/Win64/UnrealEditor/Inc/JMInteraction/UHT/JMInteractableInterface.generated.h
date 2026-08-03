// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Interfaces/JMInteractableInterface.h"

#ifdef JMINTERACTION_JMInteractableInterface_generated_h
#error "JMInteractableInterface.generated.h already included, missing '#pragma once' in JMInteractableInterface.h"
#endif
#define JMINTERACTION_JMInteractableInterface_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FJMInteractionContext;
struct FJMInteractionPrompt;
struct FJMInteractionResult;

// ********** Begin Interface UJMInteractableInterface *********************************************
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractableInterface_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void OnFocusEnd_Implementation(FJMInteractionContext const& Context) {}; \
	virtual void OnFocusBegin_Implementation(FJMInteractionContext const& Context) {}; \
	virtual int32 GetInteractionPriority_Implementation(FJMInteractionContext const& Context) const { return 0; }; \
	virtual float GetInteractionDuration_Implementation(FJMInteractionContext const& Context) const { return 0; }; \
	virtual FJMInteractionPrompt GetInteractionPrompt_Implementation(FJMInteractionContext const& Context) const { return FJMInteractionPrompt(); }; \
	virtual void CancelInteract_Implementation(FJMInteractionContext const& Context) {}; \
	virtual FJMInteractionResult CompleteInteract_Implementation(FJMInteractionContext const& Context) { return FJMInteractionResult(); }; \
	virtual FJMInteractionResult BeginInteract_Implementation(FJMInteractionContext const& Context) { return FJMInteractionResult(); }; \
	virtual bool CanInteract_Implementation(FJMInteractionContext const& Context) const { return false; }; \
	DECLARE_FUNCTION(execOnFocusEnd); \
	DECLARE_FUNCTION(execOnFocusBegin); \
	DECLARE_FUNCTION(execGetInteractionPriority); \
	DECLARE_FUNCTION(execGetInteractionDuration); \
	DECLARE_FUNCTION(execGetInteractionPrompt); \
	DECLARE_FUNCTION(execCancelInteract); \
	DECLARE_FUNCTION(execCompleteInteract); \
	DECLARE_FUNCTION(execBeginInteract); \
	DECLARE_FUNCTION(execCanInteract);


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractableInterface_h_11_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UJMInteractableInterface_Statics;
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractableInterface_NoRegister();

#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractableInterface_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMInteractableInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMInteractableInterface(UJMInteractableInterface&&) = delete; \
	UJMInteractableInterface(const UJMInteractableInterface&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMInteractableInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMInteractableInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMInteractableInterface) \
	virtual ~UJMInteractableInterface() = default;


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractableInterface_h_11_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUJMInteractableInterface(); \
	friend struct ::Z_Construct_UClass_UJMInteractableInterface_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMINTERACTION_API UClass* ::Z_Construct_UClass_UJMInteractableInterface_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMInteractableInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/JMInteraction"), Z_Construct_UClass_UJMInteractableInterface_NoRegister) \
	DECLARE_SERIALIZER(UJMInteractableInterface)


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractableInterface_h_11_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractableInterface_h_11_GENERATED_UINTERFACE_BODY() \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractableInterface_h_11_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractableInterface_h_11_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IJMInteractableInterface() {} \
public: \
	typedef UJMInteractableInterface UClassType; \
	typedef IJMInteractableInterface ThisClass; \
	static FJMInteractionResult Execute_BeginInteract(UObject* O, FJMInteractionContext const& Context); \
	static void Execute_CancelInteract(UObject* O, FJMInteractionContext const& Context); \
	static bool Execute_CanInteract(const UObject* O, FJMInteractionContext const& Context); \
	static FJMInteractionResult Execute_CompleteInteract(UObject* O, FJMInteractionContext const& Context); \
	static float Execute_GetInteractionDuration(const UObject* O, FJMInteractionContext const& Context); \
	static int32 Execute_GetInteractionPriority(const UObject* O, FJMInteractionContext const& Context); \
	static FJMInteractionPrompt Execute_GetInteractionPrompt(const UObject* O, FJMInteractionContext const& Context); \
	static void Execute_OnFocusBegin(UObject* O, FJMInteractionContext const& Context); \
	static void Execute_OnFocusEnd(UObject* O, FJMInteractionContext const& Context); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractableInterface_h_8_PROLOG
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractableInterface_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractableInterface_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractableInterface_h_11_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractableInterface_h_11_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMInteractableInterface;

// ********** End Interface UJMInteractableInterface ***********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractableInterface_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
