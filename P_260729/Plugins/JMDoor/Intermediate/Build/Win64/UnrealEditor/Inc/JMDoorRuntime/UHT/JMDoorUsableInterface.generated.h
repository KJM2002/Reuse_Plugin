// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Interfaces/JMDoorUsableInterface.h"

#ifdef JMDOORRUNTIME_JMDoorUsableInterface_generated_h
#error "JMDoorUsableInterface.generated.h already included, missing '#pragma once' in JMDoorUsableInterface.h"
#endif
#define JMDOORRUNTIME_JMDoorUsableInterface_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EJMDoorCommand : uint8;
enum class EJMDoorState : uint8;
struct FJMDoorResult;
struct FJMDoorUseContext;

// ********** Begin Interface UJMDoorUsableInterface ***********************************************
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorUsableInterface_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual EJMDoorState GetDoorState_Implementation() const { return (EJMDoorState)0; }; \
	virtual bool CanExecuteDoorCommand_Implementation(EJMDoorCommand Command, FJMDoorUseContext const& Context) const { return false; }; \
	virtual FJMDoorResult ExecuteDoorCommand_Implementation(EJMDoorCommand Command, FJMDoorUseContext const& Context) { return FJMDoorResult(); }; \
	DECLARE_FUNCTION(execGetDoorState); \
	DECLARE_FUNCTION(execCanExecuteDoorCommand); \
	DECLARE_FUNCTION(execExecuteDoorCommand);


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorUsableInterface_h_11_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UJMDoorUsableInterface_Statics;
JMDOORRUNTIME_API UClass* Z_Construct_UClass_UJMDoorUsableInterface_NoRegister();

#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorUsableInterface_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UJMDoorUsableInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMDoorUsableInterface(UJMDoorUsableInterface&&) = delete; \
	UJMDoorUsableInterface(const UJMDoorUsableInterface&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMDoorUsableInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMDoorUsableInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UJMDoorUsableInterface) \
	virtual ~UJMDoorUsableInterface() = default;


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorUsableInterface_h_11_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUJMDoorUsableInterface(); \
	friend struct ::Z_Construct_UClass_UJMDoorUsableInterface_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMDOORRUNTIME_API UClass* ::Z_Construct_UClass_UJMDoorUsableInterface_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMDoorUsableInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/JMDoorRuntime"), Z_Construct_UClass_UJMDoorUsableInterface_NoRegister) \
	DECLARE_SERIALIZER(UJMDoorUsableInterface)


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorUsableInterface_h_11_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorUsableInterface_h_11_GENERATED_UINTERFACE_BODY() \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorUsableInterface_h_11_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorUsableInterface_h_11_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IJMDoorUsableInterface() {} \
public: \
	typedef UJMDoorUsableInterface UClassType; \
	typedef IJMDoorUsableInterface ThisClass; \
	static bool Execute_CanExecuteDoorCommand(const UObject* O, EJMDoorCommand Command, FJMDoorUseContext const& Context); \
	static FJMDoorResult Execute_ExecuteDoorCommand(UObject* O, EJMDoorCommand Command, FJMDoorUseContext const& Context); \
	static EJMDoorState Execute_GetDoorState(const UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorUsableInterface_h_8_PROLOG
#define FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorUsableInterface_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorUsableInterface_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorUsableInterface_h_11_CALLBACK_WRAPPERS \
	FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorUsableInterface_h_11_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMDoorUsableInterface;

// ********** End Interface UJMDoorUsableInterface *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMDoor_Source_JMDoorRuntime_Public_Interfaces_JMDoorUsableInterface_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
