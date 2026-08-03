// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Tests/JMJumpScareTestActor.h"

#ifdef JMJUMPSCARETESTS_JMJumpScareTestActor_generated_h
#error "JMJumpScareTestActor.generated.h already included, missing '#pragma once' in JMJumpScareTestActor.h"
#endif
#define JMJUMPSCARETESTS_JMJumpScareTestActor_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AJMJumpScareTestActor ****************************************************
struct Z_Construct_UClass_AJMJumpScareTestActor_Statics;
JMJUMPSCARETESTS_API UClass* Z_Construct_UClass_AJMJumpScareTestActor_NoRegister();

#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScareTests_Private_Tests_JMJumpScareTestActor_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAJMJumpScareTestActor(); \
	friend struct ::Z_Construct_UClass_AJMJumpScareTestActor_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMJUMPSCARETESTS_API UClass* ::Z_Construct_UClass_AJMJumpScareTestActor_NoRegister(); \
public: \
	DECLARE_CLASS2(AJMJumpScareTestActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMJumpScareTests"), Z_Construct_UClass_AJMJumpScareTestActor_NoRegister) \
	DECLARE_SERIALIZER(AJMJumpScareTestActor) \
	virtual UObject* _getUObject() const override { return const_cast<AJMJumpScareTestActor*>(this); }


#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScareTests_Private_Tests_JMJumpScareTestActor_h_11_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AJMJumpScareTestActor(AJMJumpScareTestActor&&) = delete; \
	AJMJumpScareTestActor(const AJMJumpScareTestActor&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AJMJumpScareTestActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AJMJumpScareTestActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AJMJumpScareTestActor) \
	NO_API virtual ~AJMJumpScareTestActor();


#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScareTests_Private_Tests_JMJumpScareTestActor_h_8_PROLOG
#define FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScareTests_Private_Tests_JMJumpScareTestActor_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScareTests_Private_Tests_JMJumpScareTestActor_h_11_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScareTests_Private_Tests_JMJumpScareTestActor_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AJMJumpScareTestActor;

// ********** End Class AJMJumpScareTestActor ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMJumpScare_Source_JMJumpScareTests_Private_Tests_JMJumpScareTestActor_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
