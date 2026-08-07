#include "Misc/AutomationTest.h"

#include "Prototype/JMPrototypeLevelPortal.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FJMPrototypePortalPIEPathNormalizationTest,
	"JM.Prototype.Portal.PIEPathNormalization",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FJMPrototypePortalPIEPathNormalizationTest::RunTest(const FString& Parameters)
{
	TestEqual(TEXT("PIE base map path is restored"),
		AJMPrototypeLevelPortal::NormalizeDestinationPackageName(
			TEXT("/Game/Prototype/Maps/UEDPIE_0_Level_Prototype")),
		FString(TEXT("/Game/Prototype/Maps/Level_Prototype")));
	TestEqual(TEXT("PIE dungeon map path is restored"),
		AJMPrototypeLevelPortal::NormalizeDestinationPackageName(
			TEXT("/Game/Level/UEDPIE_2_Level_Mapgenerate")),
		FString(TEXT("/Game/Level/Level_Mapgenerate")));
	TestEqual(TEXT("Non-PIE map path is unchanged"),
		AJMPrototypeLevelPortal::NormalizeDestinationPackageName(
			TEXT("/Game/Level/Level_Mapgenerate")),
		FString(TEXT("/Game/Level/Level_Mapgenerate")));

	const AJMPrototypeLevelPortal* PortalDefaults = GetDefault<AJMPrototypeLevelPortal>();
	TestNotNull(TEXT("Portal defaults exist"), PortalDefaults);
	if (PortalDefaults)
	{
		TestTrue(TEXT("Default arrival message array is populated"), PortalDefaults->ArrivalMessages.Num() > 1);
		for (const FText& Message : PortalDefaults->ArrivalMessages)
		{
			TestFalse(TEXT("Arrival messages are not empty"), Message.IsEmpty());
		}
	}
	return true;
}

#endif
