#include "Actors/JMRoomModule.h"
#include "Dungeon/Content/JMDungeonContentSpawnPoints.h"
#include "Engine/Blueprint.h"
#include "Engine/World.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationEditorCommon.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMDungeonRoomContentMarkersTest,
	"JM.Dungeon.Content.RoomBlueprintMarkers",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMDungeonRoomContentMarkersTest::RunTest(const FString&)
{
	static const TCHAR* RoomNames[] = {
		TEXT("2Way_A"), TEXT("2Way_B"), TEXT("2Way_C"), TEXT("2Way_D"), TEXT("2Way_Straight"),
		TEXT("3Way_A"), TEXT("3Way_B"), TEXT("3Way_C"), TEXT("3Way_D"),
		TEXT("4Way_A"), TEXT("4Way_B"), TEXT("4Way_C"), TEXT("4Way_D")
	};

	UWorld* World = FAutomationEditorCommonUtils::CreateNewMap();
	TestNotNull(TEXT("Automation world exists"), World);
	if (!World)
	{
		return false;
	}

	for (const TCHAR* RoomName : RoomNames)
	{
		const FString ClassPath = FString::Printf(
			TEXT("/Game/Dungeon/Rooms13x13/BP_DungeonRoom13x13_%s.BP_DungeonRoom13x13_%s_C"), RoomName, RoomName);
		UClass* RoomClass = LoadClass<AJMRoomModule>(nullptr, *ClassPath);
		TestNotNull(*FString::Printf(TEXT("%s room class loads"), RoomName), RoomClass);
		if (!RoomClass)
		{
			continue;
		}
		AJMRoomModule* Room = World->SpawnActor<AJMRoomModule>(RoomClass, FTransform::Identity);
		TestNotNull(*FString::Printf(TEXT("%s room instance spawns"), RoomName), Room);
		if (!Room)
		{
			continue;
		}

		TArray<UJMDungeonItemSpawnPointComponent*> ItemMarkers;
		TArray<UJMDungeonAIEntryPointComponent*> EntryMarkers;
		TArray<UJMDungeonAIRoutePointComponent*> RouteMarkers;
		Room->GetComponents(ItemMarkers);
		Room->GetComponents(EntryMarkers);
		Room->GetComponents(RouteMarkers);
		TestEqual(*FString::Printf(TEXT("%s has three item billboards"), RoomName), ItemMarkers.Num(), 3);
		TestEqual(*FString::Printf(TEXT("%s has one AI entry billboard"), RoomName), EntryMarkers.Num(), 1);
		TestEqual(*FString::Printf(TEXT("%s has home plus three patrol billboards"), RoomName), RouteMarkers.Num(), 4);

		int32 UniqueBatteryMarkers = 0;
		for (const UJMDungeonItemSpawnPointComponent* Marker : ItemMarkers)
		{
			TestTrue(TEXT("Every item billboard has at least one item option"), !Marker->ItemOptions.IsEmpty());
			if (Marker->SelectionPolicy == EJMDungeonItemSelectionPolicy::UniqueGroup &&
				Marker->SelectionGroup == TEXT("EmergencyBattery"))
			{
				++UniqueBatteryMarkers;
			}
		}
		TestEqual(*FString::Printf(TEXT("%s has one unique battery candidate"), RoomName), UniqueBatteryMarkers, 1);
		Room->Destroy();
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMDungeonContentMarkerDefaultsTest,
	"JM.Dungeon.Content.MarkerDefaults",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMDungeonContentMarkerDefaultsTest::RunTest(const FString&)
{
	const UJMDungeonItemSpawnPointComponent* ItemMarker = GetDefault<UJMDungeonItemSpawnPointComponent>();
	const UJMDungeonAIEntryPointComponent* EntryMarker = GetDefault<UJMDungeonAIEntryPointComponent>();
	const UJMDungeonAIRoutePointComponent* RouteMarker = GetDefault<UJMDungeonAIRoutePointComponent>();
	TestTrue(TEXT("Item billboard is hidden during play"), ItemMarker->bHiddenInGame);
	TestTrue(TEXT("AI entry billboard is hidden during play"), EntryMarker->bHiddenInGame);
	TestTrue(TEXT("AI route billboard is hidden during play"), RouteMarker->bHiddenInGame);
	TestEqual(TEXT("AI entry and route share the default route group"), EntryMarker->RouteGroup, RouteMarker->RouteGroup);
	return true;
}

#endif
