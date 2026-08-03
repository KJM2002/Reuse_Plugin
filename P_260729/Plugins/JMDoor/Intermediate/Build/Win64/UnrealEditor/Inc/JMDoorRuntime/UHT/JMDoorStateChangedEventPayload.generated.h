// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Payloads/JMDoorStateChangedEventPayload.h"

#ifdef JMDOORRUNTIME_JMDoorStateChangedEventPayload_generated_h
#error "JMDoorStateChangedEventPayload.generated.h already included, missing '#pragma once' in JMDoorStateChangedEventPayload.h"
#endif
#define JMDOORRUNTIME_JMDoorStateChangedEventPayload_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UJMDoorStateChangedEventPayload ******************************************
struct Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics;
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorStateChangedEventPayload_NoRegister();

#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Payloads_JMDoorStateChangedEventPayload_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMDoorStateChangedEventPayload(); \
	friend struct ::Z_Construct_UClass_UJMDoorStateChangedEventPayload_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMDOORRUNTIME_API UClass* ::Z_Construct_UClass_UJMDoorStateChangedEventPayload_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMDoorStateChangedEventPayload, UJMGameplayEventPayloadBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/JMDoorRuntime"), Z_Construct_UClass_UJMDoorStateChangedEventPayload_NoRegister) \
	DECLARE_SERIALIZER(UJMDoorStateChangedEventPayload)


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Payloads_JMDoorStateChangedEventPayload_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMDoorStateChangedEventPayload(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMDoorStateChangedEventPayload(UJMDoorStateChangedEventPayload&&) = delete; \
	UJMDoorStateChangedEventPayload(const UJMDoorStateChangedEventPayload&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMDoorStateChangedEventPayload); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMDoorStateChangedEventPayload); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMDoorStateChangedEventPayload) \
	NO_API virtual ~UJMDoorStateChangedEventPayload();


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Payloads_JMDoorStateChangedEventPayload_h_8_PROLOG
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Payloads_JMDoorStateChangedEventPayload_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Payloads_JMDoorStateChangedEventPayload_h_11_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Payloads_JMDoorStateChangedEventPayload_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMDoorStateChangedEventPayload;

// ********** End Class UJMDoorStateChangedEventPayload ********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Payloads_JMDoorStateChangedEventPayload_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
