// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/JMHideSimplePanelMechanismComponent.h"

#ifdef JMHIDERUNTIME_JMHideSimplePanelMechanismComponent_generated_h
#error "JMHideSimplePanelMechanismComponent.generated.h already included, missing '#pragma once' in JMHideSimplePanelMechanismComponent.h"
#endif
#define JMHIDERUNTIME_JMHideSimplePanelMechanismComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FJMHidePanelPart **************************************************
struct Z_Construct_UScriptStruct_FJMHidePanelPart_Statics;
#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSimplePanelMechanismComponent_h_20_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FJMHidePanelPart_Statics; \
	static class UScriptStruct* StaticStruct();


struct FJMHidePanelPart;
// ********** End ScriptStruct FJMHidePanelPart ****************************************************

// ********** Begin Class UJMHideSimplePanelMechanismComponent *************************************
#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSimplePanelMechanismComponent_h_39_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execValidateConfiguration);


struct Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics;
JMHIDERUNTIME_API UClass* Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_NoRegister();

#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSimplePanelMechanismComponent_h_39_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUJMHideSimplePanelMechanismComponent(); \
	friend struct ::Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend JMHIDERUNTIME_API UClass* ::Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UJMHideSimplePanelMechanismComponent, UJMHideMechanismComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JMHideRuntime"), Z_Construct_UClass_UJMHideSimplePanelMechanismComponent_NoRegister) \
	DECLARE_SERIALIZER(UJMHideSimplePanelMechanismComponent)


#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSimplePanelMechanismComponent_h_39_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UJMHideSimplePanelMechanismComponent(UJMHideSimplePanelMechanismComponent&&) = delete; \
	UJMHideSimplePanelMechanismComponent(const UJMHideSimplePanelMechanismComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UJMHideSimplePanelMechanismComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UJMHideSimplePanelMechanismComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UJMHideSimplePanelMechanismComponent) \
	NO_API virtual ~UJMHideSimplePanelMechanismComponent();


#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSimplePanelMechanismComponent_h_36_PROLOG
#define FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSimplePanelMechanismComponent_h_39_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSimplePanelMechanismComponent_h_39_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSimplePanelMechanismComponent_h_39_INCLASS_NO_PURE_DECLS \
	FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSimplePanelMechanismComponent_h_39_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UJMHideSimplePanelMechanismComponent;

// ********** End Class UJMHideSimplePanelMechanismComponent ***************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_P_260729_Plugins_JMHide_Source_JMHideRuntime_Public_Components_JMHideSimplePanelMechanismComponent_h

// ********** Begin Enum EJMHidePanelMotionType ****************************************************
#define FOREACH_ENUM_EJMHIDEPANELMOTIONTYPE(op) \
	op(EJMHidePanelMotionType::Transform) \
	op(EJMHidePanelMotionType::RotationOnly) 

enum class EJMHidePanelMotionType : uint8;
template<> struct TIsUEnumClass<EJMHidePanelMotionType> { enum { Value = true }; };
template<> JMHIDERUNTIME_NON_ATTRIBUTED_API UEnum* StaticEnum<EJMHidePanelMotionType>();
// ********** End Enum EJMHidePanelMotionType ******************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
