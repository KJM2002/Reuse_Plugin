// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeJMObjectiveTests_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_JMObjectiveTests;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_JMObjectiveTests()
	{
		if (!Z_Registration_Info_UPackage__Script_JMObjectiveTests.OuterSingleton)
		{
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/JMObjectiveTests",
			nullptr,
			0,
			PKG_CompiledIn | 0x00000040,
			0x1B62484D,
			0x81EF4057,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_JMObjectiveTests.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_JMObjectiveTests.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_JMObjectiveTests(Z_Construct_UPackage__Script_JMObjectiveTests, TEXT("/Script/JMObjectiveTests"), Z_Registration_Info_UPackage__Script_JMObjectiveTests, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x1B62484D, 0x81EF4057));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
