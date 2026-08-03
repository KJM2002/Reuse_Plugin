// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Interfaces/JMReconTarget.h"

#ifdef JMRECONRUNTIME_JMReconTarget_generated_h
#error "JMReconTarget.generated.h already included, missing '#pragma once' in JMReconTarget.h"
#endif
#define JMRECONRUNTIME_JMReconTarget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
enum class EJMReconEndReason : uint8;
struct FGuid;
struct FJMReconRequestResult;

// ********** Begin Interface UJMReconTarget *******************************************************
#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Interfaces_JMReconTarget_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void EndPeekPose_Implementation(FGuid const& SessionId) {}; \
	virtual void BeginPeekPose_Implementation(FGuid const& SessionId, float OpenFraction) {}; \
	virtual void EndRecon_Implementation(AActor* Interactor, FGuid const& SessionId, EJMReconEndReason Reason) {}; \
	virtual void BeginRecon_Implementation(AActor* Interactor, FGuid const& SessionId) {}; \
	virtual bool CanEnterPeek_Implementation(AActor* Interactor, FGuid const& SessionId) const { return false; }; \
	virtual bool CanEnterListen_Implementation(AActor* Interactor, FGuid const& SessionId) const { return false; }; \
	virtual FJMReconRequestResult CanStartRecon_Implementation(AActor* Interactor, FGuid const& SessionId) const { return FJMReconRequestResult(); }; \
	DECLARE_FUNCTION(execEndPeekPose); \
	DECLARE_FUNCTION(execBeginPeekPose); \
	DECLARE_FUNCTION(execEndRecon); \
	DECLARE_FUNCTION(execBeginRecon); \
	DECLARE_FUNCTION(execCanEnterPeek); \
	DECLARE_FUNCTION(execCanEnterListen); \
	DECLARE_FUNCTION(execCanStartRecon);


#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Interfaces_JMReconTarget_h_13_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UJMReconTarget_Statics;
JMRECONRUNTIME_API UClass* Z_Construct_UClass_UJMReconTarget_NoRegister();

#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Interfaces_JMReconTarget_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMReconTarget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMReconTarget(UJMReconTarget&&) = delete; \
	UJMReconTarget(const UJMReconTarget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMReconTarget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMReconTarget); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMReconTarget) \
	virtual ~UJMReconTarget() = default;


#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Interfaces_JMReconTarget_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUJMReconTarget(); \
	friend struct ::Z_Construct_UClass_UJMReconTarget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMRECONRUNTIME_API UClass* ::Z_Construct_UClass_UJMReconTarget_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMReconTarget, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/JMReconRuntime"), Z_Construct_UClass_UJMReconTarget_NoRegister) \
	DECLARE_SERIALIZER(UJMReconTarget)


#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Interfaces_JMReconTarget_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Interfaces_JMReconTarget_h_13_GENERATED_UINTERFACE_BODY() \
	FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Interfaces_JMReconTarget_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Interfaces_JMReconTarget_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IJMReconTarget() {} \
public: \
	typedef UJMReconTarget UClassType; \
	typedef IJMReconTarget ThisClass; \
	static void Execute_BeginPeekPose(UObject* O, FGuid const& SessionId, float OpenFraction); \
	static void Execute_BeginRecon(UObject* O, AActor* Interactor, FGuid const& SessionId); \
	static bool Execute_CanEnterListen(const UObject* O, AActor* Interactor, FGuid const& SessionId); \
	static bool Execute_CanEnterPeek(const UObject* O, AActor* Interactor, FGuid const& SessionId); \
	static FJMReconRequestResult Execute_CanStartRecon(const UObject* O, AActor* Interactor, FGuid const& SessionId); \
	static void Execute_EndPeekPose(UObject* O, FGuid const& SessionId); \
	static void Execute_EndRecon(UObject* O, AActor* Interactor, FGuid const& SessionId, EJMReconEndReason Reason); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Interfaces_JMReconTarget_h_10_PROLOG
#define FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Interfaces_JMReconTarget_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Interfaces_JMReconTarget_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Interfaces_JMReconTarget_h_13_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Interfaces_JMReconTarget_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMReconTarget;

// ********** End Interface UJMReconTarget *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMRecon_Source_JMReconRuntime_Public_Interfaces_JMReconTarget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
