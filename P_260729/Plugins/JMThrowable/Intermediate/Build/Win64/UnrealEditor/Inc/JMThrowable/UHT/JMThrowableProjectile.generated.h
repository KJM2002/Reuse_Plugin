// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "JMThrowableProjectile.h"

#ifdef JMTHROWABLE_JMThrowableProjectile_generated_h
#error "JMThrowableProjectile.generated.h already included, missing '#pragma once' in JMThrowableProjectile.h"
#endif
#define JMTHROWABLE_JMThrowableProjectile_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UJMThrowableDefinition;
struct FHitResult;
struct FJMThrowParameters;

// ********** Begin Delegate FJMProjectileEvent ****************************************************
#define FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableProjectile_h_16_DELEGATE \
JMTHROWABLE_API void FJMProjectileEvent_DelegateWrapper(const FMulticastScriptDelegate& JMProjectileEvent);


// ********** End Delegate FJMProjectileEvent ******************************************************

// ********** Begin Delegate FJMProjectileImpactEvent **********************************************
#define FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableProjectile_h_17_DELEGATE \
JMTHROWABLE_API void FJMProjectileImpactEvent_DelegateWrapper(const FMulticastScriptDelegate& JMProjectileImpactEvent, FHitResult const& Hit);


// ********** End Delegate FJMProjectileImpactEvent ************************************************

// ********** Begin Class AJMThrowableProjectile ***************************************************
#define FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableProjectile_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execConfigureDefinition); \
	DECLARE_FUNCTION(execLaunch);


struct Z_Construct_UClass_AJMThrowableProjectile_Statics;
JMTHROWABLE_API UClass* Z_Construct_UClass_AJMThrowableProjectile_NoRegister();

#define FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableProjectile_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAJMThrowableProjectile(); \
	friend struct ::Z_Construct_UClass_AJMThrowableProjectile_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMTHROWABLE_API UClass* ::Z_Construct_UClass_AJMThrowableProjectile_NoRegister(); \
public: \
	DECLARE_CLASS2(AJMThrowableProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMThrowable"), Z_Construct_UClass_AJMThrowableProjectile_NoRegister) \
	DECLARE_SERIALIZER(AJMThrowableProjectile)


#define FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableProjectile_h_22_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AJMThrowableProjectile(AJMThrowableProjectile&&) = delete; \
	AJMThrowableProjectile(const AJMThrowableProjectile&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AJMThrowableProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AJMThrowableProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AJMThrowableProjectile) \
	NO_API virtual ~AJMThrowableProjectile();


#define FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableProjectile_h_19_PROLOG
#define FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableProjectile_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableProjectile_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableProjectile_h_22_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableProjectile_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AJMThrowableProjectile;

// ********** End Class AJMThrowableProjectile *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableProjectile_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
