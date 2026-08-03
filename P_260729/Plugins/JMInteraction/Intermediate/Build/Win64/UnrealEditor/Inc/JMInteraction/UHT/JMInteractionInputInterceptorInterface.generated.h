// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Interfaces/JMInteractionInputInterceptorInterface.h"

#ifdef JMINTERACTION_JMInteractionInputInterceptorInterface_generated_h
#error "JMInteractionInputInterceptorInterface.generated.h already included, missing '#pragma once' in JMInteractionInputInterceptorInterface.h"
#endif
#define JMINTERACTION_JMInteractionInputInterceptorInterface_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FJMInteractionResult;

// ********** Begin Interface UJMInteractionInputInterceptorInterface ******************************
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractionInputInterceptorInterface_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool TryHandleInteractionInput_Implementation(FJMInteractionResult& OutResult) { return false; }; \
	DECLARE_FUNCTION(execTryHandleInteractionInput);


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractionInputInterceptorInterface_h_15_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UJMInteractionInputInterceptorInterface_Statics;
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractionInputInterceptorInterface_NoRegister();

#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractionInputInterceptorInterface_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMInteractionInputInterceptorInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMInteractionInputInterceptorInterface(UJMInteractionInputInterceptorInterface&&) = delete; \
	UJMInteractionInputInterceptorInterface(const UJMInteractionInputInterceptorInterface&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMInteractionInputInterceptorInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMInteractionInputInterceptorInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMInteractionInputInterceptorInterface) \
	virtual ~UJMInteractionInputInterceptorInterface() = default;


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractionInputInterceptorInterface_h_15_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUJMInteractionInputInterceptorInterface(); \
	friend struct ::Z_Construct_UClass_UJMInteractionInputInterceptorInterface_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMINTERACTION_API UClass* ::Z_Construct_UClass_UJMInteractionInputInterceptorInterface_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMInteractionInputInterceptorInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/JMInteraction"), Z_Construct_UClass_UJMInteractionInputInterceptorInterface_NoRegister) \
	DECLARE_SERIALIZER(UJMInteractionInputInterceptorInterface)


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractionInputInterceptorInterface_h_15_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractionInputInterceptorInterface_h_15_GENERATED_UINTERFACE_BODY() \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractionInputInterceptorInterface_h_15_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractionInputInterceptorInterface_h_15_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IJMInteractionInputInterceptorInterface() {} \
public: \
	typedef UJMInteractionInputInterceptorInterface UClassType; \
	typedef IJMInteractionInputInterceptorInterface ThisClass; \
	static bool Execute_TryHandleInteractionInput(UObject* O, FJMInteractionResult& OutResult); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractionInputInterceptorInterface_h_12_PROLOG
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractionInputInterceptorInterface_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractionInputInterceptorInterface_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractionInputInterceptorInterface_h_15_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractionInputInterceptorInterface_h_15_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMInteractionInputInterceptorInterface;

// ********** End Interface UJMInteractionInputInterceptorInterface ********************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractionInputInterceptorInterface_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
