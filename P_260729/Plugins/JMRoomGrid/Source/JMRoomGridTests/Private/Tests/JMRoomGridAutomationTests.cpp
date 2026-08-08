#if WITH_DEV_AUTOMATION_TESTS

#include "Actors/JMGridMapGenerator.h"
#include "Actors/JMCustomGridMapGenerator.h"
#include "Actors/JMRoomModule.h"
#include "Blueprint/JMRoomGridLibrary.h"
#include "Components/JMRoomPortComponent.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Data/JMRoomDefinition.h"
#include "Misc/AutomationTest.h"
#include "UObject/UnrealType.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMDirectionRotationTest, "JM.RoomGrid.DirectionRotation",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMDirectionRotationTest::RunTest(const FString& Parameters)
{
    TestEqual(TEXT("Positive yaw follows Unreal rotation: North +90 = West"),
        UJMRoomGridLibrary::RotateDirectionMask(EJMRoomDirection::North, 90), EJMRoomDirection::West);
    TestEqual(TEXT("East +90 = North"),
        UJMRoomGridLibrary::RotateDirectionMask(EJMRoomDirection::East, 90), EJMRoomDirection::North);
    const EJMRoomDirection Mixed = EJMRoomDirection::North | EJMRoomDirection::East;
    EJMRoomDirection Rotated = Mixed;
    for (int32 Turn = 0; Turn < 4; ++Turn) Rotated = UJMRoomGridLibrary::RotateDirectionMask(Rotated, 90);
    TestEqual(TEXT("Four quarter turns return the original mask"), Rotated, Mixed);
    TestEqual(TEXT("Negative and equivalent positive yaw agree"),
        UJMRoomGridLibrary::RotateDirectionMask(Mixed, -90), UJMRoomGridLibrary::RotateDirectionMask(Mixed, 270));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMPrototypeBoundsTest, "JM.RoomGrid.PrototypeBounds",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMPrototypeBoundsTest::RunTest(const FString& Parameters)
{
    TestTrue(TEXT("Floor size and top-face pivot"), UJMRoomGridLibrary::ValidatePrototypeBounds(
        FBox(FVector(-200, -200, -20), FVector(200, 200, 0)), EJMPrototypeMeshRole::Floor).bIsValid);
    TestTrue(TEXT("Wall size and bottom pivot"), UJMRoomGridLibrary::ValidatePrototypeBounds(
        FBox(FVector(-200, -10, 0), FVector(200, 10, 500)), EJMPrototypeMeshRole::Wall).bIsValid);
    TestTrue(TEXT("Ceiling size and bottom-face pivot"), UJMRoomGridLibrary::ValidatePrototypeBounds(
        FBox(FVector(-200, -200, 0), FVector(200, 200, 20)), EJMPrototypeMeshRole::Ceiling).bIsValid);
    TestFalse(TEXT("Incorrect floor pivot is rejected"), UJMRoomGridLibrary::ValidatePrototypeBounds(
        FBox(FVector(-200, -200, 0), FVector(200, 200, 20)), EJMPrototypeMeshRole::Floor).bIsValid);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMStandardTopologyTest, "JM.RoomGrid.Standard5x5",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMStandardTopologyTest::RunTest(const FString& Parameters)
{
    const TArray<FJMRoomCellRequirement> Cells = AJMGridMapGenerator::BuildStandardTopology();
    TestEqual(TEXT("Cell count"), Cells.Num(), 25);
    int32 Two = 0, Three = 0, Four = 0;
    bool bEntrance = false, bExit = false;
    TSet<FJMGridCoordinate> Visited;
    TArray<FJMGridCoordinate> Queue { FJMGridCoordinate(2, 4) };
    while (!Queue.IsEmpty())
    {
        const FJMGridCoordinate Current = Queue[0]; Queue.RemoveAt(0);
        if (Visited.Contains(Current)) continue;
        Visited.Add(Current);
        const FJMRoomCellRequirement* Cell = Cells.FindByPredicate([&](const FJMRoomCellRequirement& Value) { return Value.Coordinate == Current; });
        if (!Cell) continue;
        const struct { EJMRoomDirection D; int32 DX; int32 DY; } Steps[] = {
            {EJMRoomDirection::North,0,-1}, {EJMRoomDirection::East,1,0}, {EJMRoomDirection::South,0,1}, {EJMRoomDirection::West,-1,0}
        };
        for (const auto& Step : Steps)
        {
            if (!EnumHasAnyFlags(Cell->RequiredOpenDirections, Step.D)) continue;
            const FJMGridCoordinate Next(Current.X + Step.DX, Current.Y + Step.DY);
            if (Next.X >= 0 && Next.X < 5 && Next.Y >= 0 && Next.Y < 5) Queue.Add(Next);
        }
    }
    for (const FJMRoomCellRequirement& Cell : Cells)
    {
        const int32 Count = UJMRoomGridLibrary::CountDirections(Cell.RequiredOpenDirections);
        if (Count == 2) ++Two; else if (Count == 3) ++Three; else if (Count == 4) ++Four;
        if (Cell.Coordinate == FJMGridCoordinate(2, 4)) bEntrance = Cell.bHasEntrance && EnumHasAnyFlags(Cell.RequiredOpenDirections, EJMRoomDirection::South);
        if (Cell.Coordinate == FJMGridCoordinate(2, 0)) bExit = Cell.bHasExit && EnumHasAnyFlags(Cell.RequiredOpenDirections, EJMRoomDirection::North);
    }
    TestEqual(TEXT("2-Way count"), Two, 4);
    TestEqual(TEXT("3-Way count"), Three, 10);
    TestEqual(TEXT("4-Way count"), Four, 11);
    TestTrue(TEXT("South center entrance"), bEntrance);
    TestTrue(TEXT("North center exit"), bExit);
    TestEqual(TEXT("Every cell is reachable"), Visited.Num(), 25);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMCustomTopologyValidationTest, "JM.RoomGrid.CustomTopologyValidation",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMCustomTopologyValidationTest::RunTest(const FString& Parameters)
{
    AJMCustomGridMapGenerator* Generator = NewObject<AJMCustomGridMapGenerator>();
    Generator->GridWidth = 3;
    Generator->GridHeight = 2;
    Generator->SynchronizeGridCells();
    Generator->SetCell(0, 0, true, static_cast<int32>(EJMRoomDirection::East | EJMRoomDirection::South), true, false);
    Generator->SetCell(1, 0, true, static_cast<int32>(EJMRoomDirection::West | EJMRoomDirection::East));
    Generator->SetCell(2, 0, true, static_cast<int32>(EJMRoomDirection::West | EJMRoomDirection::North));
    Generator->SetCell(2, 1, true, static_cast<int32>(EJMRoomDirection::South | EJMRoomDirection::North), false, true);
    TestTrue(TEXT("Irregular connected custom topology with external entrance/exit is valid"), Generator->ValidateGridDesign().bIsValid);

    Generator->SetCell(1, 0, true, static_cast<int32>(EJMRoomDirection::West));
    const FJMRoomValidationResult BrokenResult = Generator->ValidateGridDesign();
    TestFalse(TEXT("One-sided adjacent opening is rejected"), BrokenResult.bIsValid);
    TestTrue(TEXT("Mismatch produces an actionable validation error"), BrokenResult.Errors.ContainsByPredicate([](const FText& Error)
    {
        return Error.ToString().Contains(TEXT("does not match"));
    }));

    AJMRoomModule* OneWayRoom = NewObject<AJMRoomModule>();
    OneWayRoom->JunctionType = EJMRoomJunctionType::OneWay;
    OneWayRoom->CanonicalOpenDirections = static_cast<int32>(EJMRoomDirection::North);
    TestTrue(TEXT("Native room contract accepts one canonical direction for OneWay"), OneWayRoom->ValidateRoomContract().bIsValid);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMRoomDefaultsTest, "JM.RoomGrid.RoomDefaultsAndNoMirroring",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMRoomDefaultsTest::RunTest(const FString& Parameters)
{
    const AJMRoomModule* Room = GetDefault<AJMRoomModule>();
    const FIntProperty* RoomMaskProperty = FindFProperty<FIntProperty>(AJMRoomModule::StaticClass(), GET_MEMBER_NAME_CHECKED(AJMRoomModule, CanonicalOpenDirections));
    const FIntProperty* DefinitionMaskProperty = FindFProperty<FIntProperty>(UJMRoomDefinition::StaticClass(), GET_MEMBER_NAME_CHECKED(UJMRoomDefinition, CanonicalOpenDirections));
    TestTrue(TEXT("Room canonical directions use an editable integer bitmask"), RoomMaskProperty && RoomMaskProperty->HasMetaData(TEXT("Bitmask")));
    TestTrue(TEXT("Definition canonical directions use an editable integer bitmask"), DefinitionMaskProperty && DefinitionMaskProperty->HasMetaData(TEXT("Bitmask")));
    TestTrue(TEXT("Default component contract"), Room->ValidateRoomContract().bIsValid);
    TestTrue(TEXT("Floor at origin"), Room->Floor->GetRelativeLocation().Equals(FVector::ZeroVector));
    TestTrue(TEXT("Ceiling at 500"), Room->Ceiling->GetRelativeLocation().Equals(FVector(0,0,500)));
    TestTrue(TEXT("North wall at +190"), Room->WallNorth->GetRelativeLocation().Equals(FVector(0,190,0)));
    TestTrue(TEXT("East wall at +190 and yaw 90"), Room->WallEast->GetRelativeLocation().Equals(FVector(190,0,0)) && FMath::IsNearlyEqual(Room->WallEast->GetRelativeRotation().Yaw, 90.0));
    TestTrue(TEXT("Ports use cell boundary"), Room->PortNorth->GetRelativeLocation().Equals(FVector(0,200,0)) && Room->PortWest->GetRelativeLocation().Equals(FVector(-200,0,0)));
    const FVector NegativeX(-1, 1, 1), NegativeY(1, -1, 1), NonUniform(1, 2, 1);
    TestFalse(TEXT("Negative X scale is forbidden"), NegativeX.Equals(FVector::OneVector));
    TestFalse(TEXT("Negative Y scale is forbidden"), NegativeY.Equals(FVector::OneVector));
    TestFalse(TEXT("Non-uniform scale is forbidden"), NonUniform.Equals(FVector::OneVector));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMDeterminismTest, "JM.RoomGrid.Determinism",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMDeterminismTest::RunTest(const FString& Parameters)
{
    FRandomStream A(8675309), B(8675309), C(42);
    TArray<int32> SignatureA, SignatureB, SignatureC;
    for (int32 Index = 0; Index < 25; ++Index)
    {
        SignatureA.Add(A.RandRange(0, 100000)); SignatureB.Add(B.RandRange(0, 100000)); SignatureC.Add(C.RandRange(0, 100000));
    }
    TestEqual(TEXT("Same seed produces the same selection stream"), SignatureA, SignatureB);
    TestNotEqual(TEXT("Different seeds can produce a different selection stream"), SignatureA, SignatureC);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMFiveByFiveLayoutsTest, "JM.RoomGrid.Room5x5Layouts",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFiveByFiveLayoutsTest::RunTest(const FString& Parameters)
{
    AJMRoomModule* Room = NewObject<AJMRoomModule>();
    Room->bUseFiveByFiveLayout = true;
    TestEqual(TEXT("25 floor tiles"), Room->FloorTiles.Num(), 25);
    TestEqual(TEXT("25 ceiling tiles"), Room->CeilingTiles.Num(), 25);
    TestEqual(TEXT("60 wall edges"), Room->HorizontalWalls.Num() + Room->VerticalWalls.Num(), 60);
    const struct { EJMRoomJunctionType Junction; EJMRoomDirection Mask; } Ways[] = {
        { EJMRoomJunctionType::TwoWay, EJMRoomDirection::North | EJMRoomDirection::East },
        { EJMRoomJunctionType::ThreeWay, EJMRoomDirection::North | EJMRoomDirection::East | EJMRoomDirection::West },
        { EJMRoomJunctionType::FourWay, EJMRoomDirection::All }
    };
    TSet<FString> Signatures;
    for (const auto& Way : Ways)
    {
        Room->JunctionType = Way.Junction;
        Room->CanonicalOpenDirections = static_cast<int32>(Way.Mask);
        for (int32 Variant = 0; Variant < 4; ++Variant)
        {
            Room->LayoutVariant = static_cast<EJMRoomLayoutVariant>(Variant);
            FString Signature;
            for (int32 Y = 0; Y < 5; ++Y) for (int32 X = 0; X < 5; ++X)
                Signature.AppendChar(Room->IsTileWalkable(X, Y) ? static_cast<TCHAR>('1') : static_cast<TCHAR>('0'));
            TestTrue(TEXT("Every layout contains center"), Room->IsTileWalkable(2, 2));
            TestTrue(TEXT("North endpoint"), Room->IsTileWalkable(2, 4));
            if (EnumHasAnyFlags(Way.Mask, EJMRoomDirection::East)) TestTrue(TEXT("East endpoint"), Room->IsTileWalkable(4, 2));
            if (EnumHasAnyFlags(Way.Mask, EJMRoomDirection::West)) TestTrue(TEXT("West endpoint"), Room->IsTileWalkable(0, 2));
            if (EnumHasAnyFlags(Way.Mask, EJMRoomDirection::South)) TestTrue(TEXT("South endpoint"), Room->IsTileWalkable(2, 0));
            Signatures.Add(FString::Printf(TEXT("%d:%s"), static_cast<int32>(Way.Junction), *Signature));
        }
    }
    TestEqual(TEXT("All 12 junction/variant layouts are distinct"), Signatures.Num(), 12);
    Room->ApplyStructureVisibility();
    TestTrue(TEXT("5x5 room contract"), Room->ValidateRoomContract().bIsValid);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMThirteenByThirteenLayoutsTest, "JM.RoomGrid.Room13x13Layouts",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMThirteenByThirteenLayoutsTest::RunTest(const FString& Parameters)
{
    AJMRoomModule* Room = NewObject<AJMRoomModule>();
    Room->bUseThirteenByThirteenLayout = true;
    Room->bUseFiveByFiveLayout = false;
    const struct { EJMRoomJunctionType Junction; EJMRoomDirection Mask; } Ways[] = {
        { EJMRoomJunctionType::TwoWay, EJMRoomDirection::North | EJMRoomDirection::East },
        { EJMRoomJunctionType::ThreeWay, EJMRoomDirection::North | EJMRoomDirection::East | EJMRoomDirection::West },
        { EJMRoomJunctionType::FourWay, EJMRoomDirection::All }
    };
    TSet<FString> Signatures;
    for (const auto& Way : Ways)
    {
        Room->JunctionType = Way.Junction;
        Room->CanonicalOpenDirections = static_cast<int32>(Way.Mask);
        for (int32 Variant = 0; Variant < 4; ++Variant)
        {
            Room->LayoutVariant = static_cast<EJMRoomLayoutVariant>(Variant);
            FString Signature;
            for (int32 Y = 0; Y < 13; ++Y) for (int32 X = 0; X < 13; ++X)
                Signature.AppendChar(Room->IsTileWalkable(X, Y) ? static_cast<TCHAR>('1') : static_cast<TCHAR>('0'));
            TestTrue(TEXT("13x13 center"), Room->IsTileWalkable(6, 6));
            TestTrue(TEXT("13x13 north endpoint"), Room->IsTileWalkable(6, 12));
            if (EnumHasAnyFlags(Way.Mask, EJMRoomDirection::East)) TestTrue(TEXT("13x13 east endpoint"), Room->IsTileWalkable(12, 6));
            if (EnumHasAnyFlags(Way.Mask, EJMRoomDirection::West)) TestTrue(TEXT("13x13 west endpoint"), Room->IsTileWalkable(0, 6));
            if (EnumHasAnyFlags(Way.Mask, EJMRoomDirection::South)) TestTrue(TEXT("13x13 south endpoint"), Room->IsTileWalkable(6, 0));
            TSet<FIntPoint> AllTiles;
            for (int32 TileY = 0; TileY < 13; ++TileY) for (int32 TileX = 0; TileX < 13; ++TileX)
                if (Room->IsTileWalkable(TileX, TileY)) AllTiles.Add(FIntPoint(TileX, TileY));
            TSet<FIntPoint> Reached;
            TArray<FIntPoint> Queue { FIntPoint(6, 6) };
            while (!Queue.IsEmpty())
            {
                const FIntPoint Current = Queue.Pop(EAllowShrinking::No);
                if (!AllTiles.Contains(Current) || Reached.Contains(Current)) continue;
                Reached.Add(Current);
                Queue.Add(Current + FIntPoint(1, 0)); Queue.Add(Current + FIntPoint(-1, 0));
                Queue.Add(Current + FIntPoint(0, 1)); Queue.Add(Current + FIntPoint(0, -1));
            }
            TestEqual(TEXT("Every designed floor tile belongs to one connected room"), Reached.Num(), AllTiles.Num());
            Signatures.Add(FString::Printf(TEXT("%d:%s"), static_cast<int32>(Way.Junction), *Signature));
        }
    }
    TestEqual(TEXT("All 12 13x13 layouts are distinct"), Signatures.Num(), 12);
    Room->JunctionType = EJMRoomJunctionType::FourWay;
    Room->CanonicalOpenDirections = static_cast<int32>(EJMRoomDirection::All);
    Room->LayoutVariant = EJMRoomLayoutVariant::A;
    Room->ApplyStructureVisibility();
    TestEqual(TEXT("169 floor instances"), Room->FloorInstances13->GetInstanceCount(), 169);
    TestEqual(TEXT("169 ceiling instances"), Room->CeilingInstances13->GetInstanceCount(), 169);
    TestTrue(TEXT("13x13 room contract"), Room->ValidateRoomContract().bIsValid);
    return true;
}

#endif
