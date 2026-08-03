// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeJMJumpScare_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	JMJUMPSCARE_API UFunction* Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature();
	JMJUMPSCARE_API UFunction* Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_JMJumpScare;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_JMJumpScare()
	{
		if (!Z_Registration_Info_UPackage__Script_JMJumpScare.OuterSingleton)
		{
		static UObject* (*const SingletonFuncArray[])() = {
			(UObject* (*)())Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScarePhaseChanged__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_JMJumpScare_JMJumpScareStateChanged__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/JMJumpScare",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0x3799F085,
			0xFC9F03DC,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_JMJumpScare.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_JMJumpScare.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_JMJumpScare(Z_Construct_UPackage__Script_JMJumpScare, TEXT("/Script/JMJumpScare"), Z_Registration_Info_UPackage__Script_JMJumpScare, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x3799F085, 0xFC9F03DC));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
