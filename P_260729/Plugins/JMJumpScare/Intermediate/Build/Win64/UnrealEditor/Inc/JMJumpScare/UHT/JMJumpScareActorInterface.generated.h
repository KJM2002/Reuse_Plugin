// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Interfaces/JMJumpScareActorInterface.h"

#ifdef JMJUMPSCARE_JMJumpScareActorInterface_generated_h
#error "JMJumpScareActorInterface.generated.h already included, missing '#pragma once' in JMJumpScareActorInterface.h"
#endif
#define JMJUMPSCARE_JMJumpScareActorInterface_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UJMJumpScareDefinition;

// ********** Begin Interface UJMJumpScareActorInterface *******************************************
#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Interfaces_JMJumpScareActorInterface_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void OnJumpScareCancelled_Implementation(UJMJumpScareDefinition* Definition) {}; \
	virtual void OnJumpScareFinished_Implementation(UJMJumpScareDefinition* Definition) {}; \
	virtual void OnJumpScareExiting_Implementation(UJMJumpScareDefinition* Definition) {}; \
	virtual void OnJumpScareImpact_Implementation(UJMJumpScareDefinition* Definition) {}; \
	virtual void OnJumpScareStarted_Implementation(UJMJumpScareDefinition* Definition) {}; \
	DECLARE_FUNCTION(execOnJumpScareCancelled); \
	DECLARE_FUNCTION(execOnJumpScareFinished); \
	DECLARE_FUNCTION(execOnJumpScareExiting); \
	DECLARE_FUNCTION(execOnJumpScareImpact); \
	DECLARE_FUNCTION(execOnJumpScareStarted);


#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Interfaces_JMJumpScareActorInterface_h_12_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UJMJumpScareActorInterface_Statics;
JMJUMPSCARE_API UClass* Z_Construct_UClass_UJMJumpScareActorInterface_NoRegister();

#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Interfaces_JMJumpScareActorInterface_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMJumpScareActorInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMJumpScareActorInterface(UJMJumpScareActorInterface&&) = delete; \
	UJMJumpScareActorInterface(const UJMJumpScareActorInterface&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMJumpScareActorInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMJumpScareActorInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMJumpScareActorInterface) \
	virtual ~UJMJumpScareActorInterface() = default;


#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Interfaces_JMJumpScareActorInterface_h_12_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUJMJumpScareActorInterface(); \
	friend struct ::Z_Construct_UClass_UJMJumpScareActorInterface_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMJUMPSCARE_API UClass* ::Z_Construct_UClass_UJMJumpScareActorInterface_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMJumpScareActorInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/JMJumpScare"), Z_Construct_UClass_UJMJumpScareActorInterface_NoRegister) \
	DECLARE_SERIALIZER(UJMJumpScareActorInterface)


#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Interfaces_JMJumpScareActorInterface_h_12_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Interfaces_JMJumpScareActorInterface_h_12_GENERATED_UINTERFACE_BODY() \
	FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Interfaces_JMJumpScareActorInterface_h_12_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Interfaces_JMJumpScareActorInterface_h_12_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IJMJumpScareActorInterface() {} \
public: \
	typedef UJMJumpScareActorInterface UClassType; \
	typedef IJMJumpScareActorInterface ThisClass; \
	static void Execute_OnJumpScareCancelled(UObject* O, UJMJumpScareDefinition* Definition); \
	static void Execute_OnJumpScareExiting(UObject* O, UJMJumpScareDefinition* Definition); \
	static void Execute_OnJumpScareFinished(UObject* O, UJMJumpScareDefinition* Definition); \
	static void Execute_OnJumpScareImpact(UObject* O, UJMJumpScareDefinition* Definition); \
	static void Execute_OnJumpScareStarted(UObject* O, UJMJumpScareDefinition* Definition); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Interfaces_JMJumpScareActorInterface_h_9_PROLOG
#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Interfaces_JMJumpScareActorInterface_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Interfaces_JMJumpScareActorInterface_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Interfaces_JMJumpScareActorInterface_h_12_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Interfaces_JMJumpScareActorInterface_h_12_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMJumpScareActorInterface;

// ********** End Interface UJMJumpScareActorInterface *********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScare_Public_Interfaces_JMJumpScareActorInterface_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
