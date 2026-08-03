// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeReusableDialogueSystem_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	REUSABLEDIALOGUESYSTEM_API UFunction* Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueEndedSignature__DelegateSignature();
	REUSABLEDIALOGUESYSTEM_API UFunction* Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature();
	REUSABLEDIALOGUESYSTEM_API UFunction* Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStartedSignature__DelegateSignature();
	REUSABLEDIALOGUESYSTEM_API UFunction* Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ReusableDialogueSystem;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ReusableDialogueSystem()
	{
		if (!Z_Registration_Info_UPackage__Script_ReusableDialogueSystem.OuterSingleton)
		{
		static UObject* (*const SingletonFuncArray[])() = {
			(UObject* (*)())Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueEndedSignature__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueLineSignature__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStartedSignature__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_ReusableDialogueSystem_DialogueStateChangedSignature__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/ReusableDialogueSystem",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0xEEBC66A7,
			0xC2FE5981,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ReusableDialogueSystem.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_ReusableDialogueSystem.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ReusableDialogueSystem(Z_Construct_UPackage__Script_ReusableDialogueSystem, TEXT("/Script/ReusableDialogueSystem"), Z_Registration_Info_UPackage__Script_ReusableDialogueSystem, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xEEBC66A7, 0xC2FE5981));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
