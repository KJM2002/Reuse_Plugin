// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Interfaces/JMInteractorInterface.h"

#ifdef JMINTERACTION_JMInteractorInterface_generated_h
#error "JMInteractorInterface.generated.h already included, missing '#pragma once' in JMInteractorInterface.h"
#endif
#define JMINTERACTION_JMInteractorInterface_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGameplayTagContainer;

// ********** Begin Interface UJMInteractorInterface ***********************************************
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractorInterface_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual FGameplayTagContainer GetInteractorTags_Implementation() const { return FGameplayTagContainer(); }; \
	virtual void GetInteractionView_Implementation(FVector& OutLocation, FVector& OutDirection) const {}; \
	DECLARE_FUNCTION(execGetInteractorTags); \
	DECLARE_FUNCTION(execGetInteractionView);


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractorInterface_h_11_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UJMInteractorInterface_Statics;
JMINTERACTION_API UClass* Z_Construct_UClass_UJMInteractorInterface_NoRegister();

#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractorInterface_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMInteractorInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMInteractorInterface(UJMInteractorInterface&&) = delete; \
	UJMInteractorInterface(const UJMInteractorInterface&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMInteractorInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMInteractorInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMInteractorInterface) \
	virtual ~UJMInteractorInterface() = default;


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractorInterface_h_11_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUJMInteractorInterface(); \
	friend struct ::Z_Construct_UClass_UJMInteractorInterface_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMINTERACTION_API UClass* ::Z_Construct_UClass_UJMInteractorInterface_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMInteractorInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/JMInteraction"), Z_Construct_UClass_UJMInteractorInterface_NoRegister) \
	DECLARE_SERIALIZER(UJMInteractorInterface)


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractorInterface_h_11_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractorInterface_h_11_GENERATED_UINTERFACE_BODY() \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractorInterface_h_11_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractorInterface_h_11_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IJMInteractorInterface() {} \
public: \
	typedef UJMInteractorInterface UClassType; \
	typedef IJMInteractorInterface ThisClass; \
	static void Execute_GetInteractionView(const UObject* O, FVector& OutLocation, FVector& OutDirection); \
	static FGameplayTagContainer Execute_GetInteractorTags(const UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractorInterface_h_8_PROLOG
#define FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractorInterface_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractorInterface_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractorInterface_h_11_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractorInterface_h_11_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMInteractorInterface;

// ********** End Interface UJMInteractorInterface *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMInteraction_Source_JMInteraction_Public_Interfaces_JMInteractorInterface_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
