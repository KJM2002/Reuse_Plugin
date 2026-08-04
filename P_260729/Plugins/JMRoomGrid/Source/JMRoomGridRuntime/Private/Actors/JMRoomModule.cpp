#include "Actors/JMRoomModule.h"

#include "Blueprint/JMRoomGridLibrary.h"
#include "Components/JMRoomPortComponent.h"
#include "Components/SceneComponent.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"

#define LOCTEXT_NAMESPACE "JMRoomModule"

AJMRoomModule::AJMRoomModule()
{
    PrimaryActorTick.bCanEverTick = false;

    RoomAnchor = CreateDefaultSubobject<USceneComponent>(TEXT("RoomAnchor"));
    SetRootComponent(RoomAnchor);

    StructureRoot = CreateDefaultSubobject<USceneComponent>(TEXT("StructureRoot"));
    StructureRoot->SetupAttachment(RoomAnchor);

    Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor"));
    Floor->SetupAttachment(StructureRoot);
    Ceiling = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ceiling"));
    Ceiling->SetupAttachment(StructureRoot);
    Ceiling->SetRelativeLocation(FVector(0.0, 0.0, 500.0));

    WallNorth = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wall_North"));
    WallNorth->SetupAttachment(StructureRoot);
    WallNorth->SetRelativeLocation(FVector(0.0, 190.0, 0.0));
    WallEast = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wall_East"));
    WallEast->SetupAttachment(StructureRoot);
    WallEast->SetRelativeLocation(FVector(190.0, 0.0, 0.0));
    WallEast->SetRelativeRotation(FRotator(0.0, 90.0, 0.0));
    WallSouth = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wall_South"));
    WallSouth->SetupAttachment(StructureRoot);
    WallSouth->SetRelativeLocation(FVector(0.0, -190.0, 0.0));
    WallWest = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wall_West"));
    WallWest->SetupAttachment(StructureRoot);
    WallWest->SetRelativeLocation(FVector(-190.0, 0.0, 0.0));
    WallWest->SetRelativeRotation(FRotator(0.0, 90.0, 0.0));

    FloorTiles.Reserve(25);
    CeilingTiles.Reserve(25);
    for (int32 Y = 0; Y < 5; ++Y)
    {
        for (int32 X = 0; X < 5; ++X)
        {
            const FVector TileLocation((X - 2) * 400.0, (Y - 2) * 400.0, 0.0);
            UStaticMeshComponent* TileFloor = CreateDefaultSubobject<UStaticMeshComponent>(
                *FString::Printf(TEXT("Floor_%d_%d"), X, Y));
            TileFloor->SetupAttachment(StructureRoot);
            TileFloor->SetRelativeLocation(TileLocation);
            FloorTiles.Add(TileFloor);

            UStaticMeshComponent* TileCeiling = CreateDefaultSubobject<UStaticMeshComponent>(
                *FString::Printf(TEXT("Ceiling_%d_%d"), X, Y));
            TileCeiling->SetupAttachment(StructureRoot);
            TileCeiling->SetRelativeLocation(TileLocation + FVector(0, 0, 500));
            CeilingTiles.Add(TileCeiling);
        }
    }
    HorizontalWalls.Reserve(30);
    for (int32 EdgeY = 0; EdgeY <= 5; ++EdgeY)
    {
        for (int32 X = 0; X < 5; ++X)
        {
            UStaticMeshComponent* Wall = CreateDefaultSubobject<UStaticMeshComponent>(
                *FString::Printf(TEXT("WallH_%d_%d"), X, EdgeY));
            Wall->SetupAttachment(StructureRoot);
            Wall->SetRelativeLocation(FVector((X - 2) * 400.0, (EdgeY - 2.5) * 400.0, 0));
            HorizontalWalls.Add(Wall);
        }
    }
    VerticalWalls.Reserve(30);
    for (int32 Y = 0; Y < 5; ++Y)
    {
        for (int32 EdgeX = 0; EdgeX <= 5; ++EdgeX)
        {
            UStaticMeshComponent* Wall = CreateDefaultSubobject<UStaticMeshComponent>(
                *FString::Printf(TEXT("WallV_%d_%d"), EdgeX, Y));
            Wall->SetupAttachment(StructureRoot);
            Wall->SetRelativeLocation(FVector((EdgeX - 2.5) * 400.0, (Y - 2) * 400.0, 0));
            Wall->SetRelativeRotation(FRotator(0, 90, 0));
            VerticalWalls.Add(Wall);
        }
    }

    FloorInstances13 = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("FloorInstances_13x13"));
    FloorInstances13->SetupAttachment(StructureRoot);
    CeilingInstances13 = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("CeilingInstances_13x13"));
    CeilingInstances13->SetupAttachment(StructureRoot);
    HorizontalWallInstances13 = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("HorizontalWalls_13x13"));
    HorizontalWallInstances13->SetupAttachment(StructureRoot);
    VerticalWallInstances13 = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("VerticalWalls_13x13"));
    VerticalWallInstances13->SetupAttachment(StructureRoot);

    PortNorth = CreateDefaultSubobject<UJMRoomPortComponent>(TEXT("Port_North"));
    ConfigurePort(PortNorth, EJMRoomDirection::North, FVector(0.0, 200.0, 0.0), 90.0f);
    PortEast = CreateDefaultSubobject<UJMRoomPortComponent>(TEXT("Port_East"));
    ConfigurePort(PortEast, EJMRoomDirection::East, FVector(200.0, 0.0, 0.0), 0.0f);
    PortSouth = CreateDefaultSubobject<UJMRoomPortComponent>(TEXT("Port_South"));
    ConfigurePort(PortSouth, EJMRoomDirection::South, FVector(0.0, -200.0, 0.0), 270.0f);
    PortWest = CreateDefaultSubobject<UJMRoomPortComponent>(TEXT("Port_West"));
    ConfigurePort(PortWest, EJMRoomDirection::West, FVector(-200.0, 0.0, 0.0), 180.0f);

    ContentRoot = CreateDefaultSubobject<USceneComponent>(TEXT("ContentRoot"));
    ContentRoot->SetupAttachment(RoomAnchor);
    ItemSpawnRoot = CreateDefaultSubobject<USceneComponent>(TEXT("ItemSpawnRoot"));
    ItemSpawnRoot->SetupAttachment(RoomAnchor);
    AISpawnRoot = CreateDefaultSubobject<USceneComponent>(TEXT("AISpawnRoot"));
    AISpawnRoot->SetupAttachment(RoomAnchor);
    DebugRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DebugRoot"));
    DebugRoot->SetupAttachment(RoomAnchor);
}

void AJMRoomModule::ConfigurePort(UJMRoomPortComponent* Port, const EJMRoomDirection Direction, const FVector& Location, const float Yaw)
{
    if (!Port->GetAttachParent()) Port->SetupAttachment(RoomAnchor);
    Port->SetRelativeLocation(Location);
    Port->SetRelativeRotation(FRotator(0.0, Yaw, 0.0));
    Port->LocalDirection = Direction;
}

void AJMRoomModule::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
    ApplyStructureVisibility();
}

void AJMRoomModule::ApplyStructureVisibility()
{
    const auto SetEnabled = [](UStaticMeshComponent* Component, const bool bEnabled)
    {
        if (!Component) return;
        Component->SetVisibility(bEnabled, true);
        Component->SetHiddenInGame(!bEnabled, true);
        Component->SetCollisionEnabled(bEnabled ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);
    };

    const auto SetInstancesEnabled = [](UInstancedStaticMeshComponent* Component, const bool bEnabled)
    {
        if (!Component) return;
        Component->SetVisibility(bEnabled, true);
        Component->SetHiddenInGame(!bEnabled, true);
        Component->SetCollisionEnabled(bEnabled ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);
    };

    if (bUseThirteenByThirteenLayout)
    {
        for (UStaticMeshComponent* Component : { Floor.Get(), Ceiling.Get(), WallNorth.Get(), WallEast.Get(), WallSouth.Get(), WallWest.Get() }) SetEnabled(Component, false);
        for (UStaticMeshComponent* Component : FloorTiles) SetEnabled(Component, false);
        for (UStaticMeshComponent* Component : CeilingTiles) SetEnabled(Component, false);
        for (UStaticMeshComponent* Component : HorizontalWalls) SetEnabled(Component, false);
        for (UStaticMeshComponent* Component : VerticalWalls) SetEnabled(Component, false);
        FloorInstances13->ClearInstances();
        CeilingInstances13->ClearInstances();
        HorizontalWallInstances13->ClearInstances();
        VerticalWallInstances13->ClearInstances();
        if (!bUseAutomatic13x13Structure)
        {
            SetInstancesEnabled(FloorInstances13, false);
            SetInstancesEnabled(CeilingInstances13, false);
            SetInstancesEnabled(HorizontalWallInstances13, false);
            SetInstancesEnabled(VerticalWallInstances13, false);
            ConfigurePort(PortNorth, EJMRoomDirection::North, FVector(0, 2600, 0), 90);
            ConfigurePort(PortEast, EJMRoomDirection::East, FVector(2600, 0, 0), 0);
            ConfigurePort(PortSouth, EJMRoomDirection::South, FVector(0, -2600, 0), 270);
            ConfigurePort(PortWest, EJMRoomDirection::West, FVector(-2600, 0, 0), 180);
#if WITH_EDITOR
            const bool bIsGameWorld = GetWorld() && GetWorld()->IsGameWorld();
            if (bHideCeilingInEditor && !bIsGameWorld) SetCeilingsVisible(false);
#endif
            return;
        }
        for (int32 Y = 0; Y < 13; ++Y)
        {
            for (int32 X = 0; X < 13; ++X)
            {
                const FVector Location((X - 6) * 400.0, (Y - 6) * 400.0, 0);
                FloorInstances13->AddInstance(FTransform(Location));
                CeilingInstances13->AddInstance(FTransform(Location + FVector(0, 0, 500)));
            }
        }
        const auto Open = [this](const EJMRoomDirection Direction) { return (CanonicalOpenDirections & static_cast<int32>(Direction)) != 0; };
        for (int32 EdgeY = 0; EdgeY <= 13; ++EdgeY)
        {
            for (int32 X = 0; X < 13; ++X)
            {
                const bool Below = EdgeY > 0 && IsTileWalkable(X, EdgeY - 1);
                const bool Above = EdgeY < 13 && IsTileWalkable(X, EdgeY);
                bool bWall = Below != Above;
                if (X == 6 && ((EdgeY == 0 && Open(EJMRoomDirection::South)) || (EdgeY == 13 && Open(EJMRoomDirection::North)))) bWall = false;
                if (bWall) HorizontalWallInstances13->AddInstance(FTransform(FVector((X - 6) * 400.0, (EdgeY - 6.5) * 400.0, 0)));
            }
        }
        for (int32 Y = 0; Y < 13; ++Y)
        {
            for (int32 EdgeX = 0; EdgeX <= 13; ++EdgeX)
            {
                const bool Left = EdgeX > 0 && IsTileWalkable(EdgeX - 1, Y);
                const bool Right = EdgeX < 13 && IsTileWalkable(EdgeX, Y);
                bool bWall = Left != Right;
                if (Y == 6 && ((EdgeX == 0 && Open(EJMRoomDirection::West)) || (EdgeX == 13 && Open(EJMRoomDirection::East)))) bWall = false;
                if (bWall) VerticalWallInstances13->AddInstance(FTransform(FRotator(0, 90, 0), FVector((EdgeX - 6.5) * 400.0, (Y - 6) * 400.0, 0)));
            }
        }
        SetInstancesEnabled(FloorInstances13, true);
        SetInstancesEnabled(CeilingInstances13, true);
        SetInstancesEnabled(HorizontalWallInstances13, true);
        SetInstancesEnabled(VerticalWallInstances13, true);
#if WITH_EDITOR
        const bool bIsGameWorld = GetWorld() && GetWorld()->IsGameWorld();
        if (bHideCeilingInEditor && !bIsGameWorld) SetCeilingsVisible(false);
#endif
        ConfigurePort(PortNorth, EJMRoomDirection::North, FVector(0, 2600, 0), 90);
        ConfigurePort(PortEast, EJMRoomDirection::East, FVector(2600, 0, 0), 0);
        ConfigurePort(PortSouth, EJMRoomDirection::South, FVector(0, -2600, 0), 270);
        ConfigurePort(PortWest, EJMRoomDirection::West, FVector(-2600, 0, 0), 180);
        return;
    }
    SetInstancesEnabled(FloorInstances13, false);
    SetInstancesEnabled(CeilingInstances13, false);
    SetInstancesEnabled(HorizontalWallInstances13, false);
    SetInstancesEnabled(VerticalWallInstances13, false);

    if (bUseFiveByFiveLayout)
    {
        for (UStaticMeshComponent* Component : { Floor.Get(), Ceiling.Get(), WallNorth.Get(), WallEast.Get(), WallSouth.Get(), WallWest.Get() })
            SetEnabled(Component, false);
        for (UStaticMeshComponent* Component : FloorTiles) SetEnabled(Component, true);
        for (UStaticMeshComponent* Component : CeilingTiles) SetEnabled(Component, true);

        const auto Open = [this](const EJMRoomDirection Direction)
        {
            return (CanonicalOpenDirections & static_cast<int32>(Direction)) != 0;
        };
        for (int32 EdgeY = 0; EdgeY <= 5; ++EdgeY)
        {
            for (int32 X = 0; X < 5; ++X)
            {
                const bool Below = EdgeY > 0 && IsTileWalkable(X, EdgeY - 1);
                const bool Above = EdgeY < 5 && IsTileWalkable(X, EdgeY);
                bool bWall = Below != Above;
                if (X == 2 && ((EdgeY == 0 && Open(EJMRoomDirection::South)) ||
                    (EdgeY == 5 && Open(EJMRoomDirection::North)))) bWall = false;
                SetEnabled(HorizontalWalls[EdgeY * 5 + X], bWall);
            }
        }
        for (int32 Y = 0; Y < 5; ++Y)
        {
            for (int32 EdgeX = 0; EdgeX <= 5; ++EdgeX)
            {
                const bool Left = EdgeX > 0 && IsTileWalkable(EdgeX - 1, Y);
                const bool Right = EdgeX < 5 && IsTileWalkable(EdgeX, Y);
                bool bWall = Left != Right;
                if (Y == 2 && ((EdgeX == 0 && Open(EJMRoomDirection::West)) ||
                    (EdgeX == 5 && Open(EJMRoomDirection::East)))) bWall = false;
                SetEnabled(VerticalWalls[Y * 6 + EdgeX], bWall);
            }
        }
        ConfigurePort(PortNorth, EJMRoomDirection::North, FVector(0, 1000, 0), 90);
        ConfigurePort(PortEast, EJMRoomDirection::East, FVector(1000, 0, 0), 0);
        ConfigurePort(PortSouth, EJMRoomDirection::South, FVector(0, -1000, 0), 270);
        ConfigurePort(PortWest, EJMRoomDirection::West, FVector(-1000, 0, 0), 180);
        return;
    }

    for (UStaticMeshComponent* Component : FloorTiles) SetEnabled(Component, false);
    for (UStaticMeshComponent* Component : CeilingTiles) SetEnabled(Component, false);
    for (UStaticMeshComponent* Component : HorizontalWalls) SetEnabled(Component, false);
    for (UStaticMeshComponent* Component : VerticalWalls) SetEnabled(Component, false);
    SetEnabled(Floor, true);
    SetEnabled(Ceiling, true);
    const auto SetWallOpen = [this](UStaticMeshComponent* Wall, const EJMRoomDirection Direction)
    {
        const bool bOpen = (CanonicalOpenDirections & static_cast<int32>(Direction)) != 0;
        Wall->SetVisibility(!bOpen, true);
        Wall->SetHiddenInGame(bOpen, true);
        Wall->SetCollisionEnabled(bOpen ? ECollisionEnabled::NoCollision : ECollisionEnabled::QueryAndPhysics);
    };
    SetWallOpen(WallNorth, EJMRoomDirection::North);
    SetWallOpen(WallEast, EJMRoomDirection::East);
    SetWallOpen(WallSouth, EJMRoomDirection::South);
    SetWallOpen(WallWest, EJMRoomDirection::West);
}

bool AJMRoomModule::IsTileWalkable(const int32 X, const int32 Y) const
{
    if (bUseThirteenByThirteenLayout)
    {
        if (X < 0 || X >= 13 || Y < 0 || Y >= 13) return false;
        if (bUseCustomWalkableTiles) return CustomWalkableTiles.Contains(FIntPoint(X, Y));
        const int32 V = static_cast<int32>(LayoutVariant);
        const auto Rect = [X, Y](int32 MinX, int32 MaxX, int32 MinY, int32 MaxY)
        { return X >= MinX && X <= MaxX && Y >= MinY && Y <= MaxY; };
        const auto H = [X, Y](int32 Row, int32 MinX, int32 MaxX)
        { return Y == Row && X >= MinX && X <= MaxX; };
        const auto VL = [X, Y](int32 Column, int32 MinY, int32 MaxY)
        { return X == Column && Y >= MinY && Y <= MaxY; };
        const bool N = VL(6, 6, 12);
        const bool E = H(6, 6, 12);
        const bool S = VL(6, 0, 6);
        const bool W = H(6, 0, 6);
        if (JunctionType == EJMRoomJunctionType::TwoWay)
        {
            if (V == 0) return N || E || Rect(2, 5, 8, 10) || H(8, 5, 6) || Rect(8, 10, 2, 5) || VL(8, 5, 6);
            if (V == 1) return VL(6, 9, 12) || H(9, 3, 6) || VL(3, 4, 9) || H(4, 3, 10) || VL(10, 4, 6) || H(6, 6, 12) || VL(6, 4, 6) || Rect(7, 10, 8, 11) || Rect(1, 4, 1, 4);
            if (V == 2) return VL(6, 6, 12) || H(10, 6, 10) || VL(10, 6, 10) || E || Rect(2, 5, 3, 7) || H(6, 5, 6) || Rect(8, 11, 8, 10);
            return N || H(8, 2, 6) || VL(2, 3, 8) || H(3, 2, 9) || VL(9, 3, 6) || H(6, 6, 12) || Rect(3, 5, 7, 10) || Rect(8, 10, 1, 4);
        }
        if (JunctionType == EJMRoomJunctionType::ThreeWay)
        {
            if (V == 0) return N || E || W || Rect(1, 4, 8, 10) || H(8, 4, 6) || Rect(8, 11, 8, 10) || H(8, 6, 8) || Rect(4, 8, 2, 4) || VL(6, 4, 6);
            if (V == 1) return VL(6, 8, 12) || Rect(4, 8, 7, 10) || VL(6, 4, 7) || H(4, 2, 10) || VL(2, 4, 6) || VL(10, 4, 6) || H(6, 0, 2) || H(6, 10, 12) || Rect(1, 4, 1, 3) || Rect(8, 11, 1, 3);
            if (V == 2) return Rect(4, 8, 4, 8) || N || E || W || Rect(1, 3, 8, 11) || H(9, 3, 4) || Rect(9, 11, 1, 4) || VL(9, 4, 6);
            return E || W || VL(6, 6, 12) || H(9, 2, 6) || Rect(1, 4, 8, 11) || H(8, 6, 10) || Rect(9, 11, 7, 10) || Rect(3, 5, 2, 5) || VL(5, 5, 6) || Rect(7, 9, 2, 4) || VL(7, 4, 6);
        }
        if (V == 0) return N || E || S || W || Rect(1, 4, 8, 11) || Rect(8, 11, 8, 11) || Rect(1, 4, 1, 4) || Rect(8, 11, 1, 4) || H(8, 4, 8) || H(4, 4, 8);
        if (V == 1) return N || E || S || W || Rect(3, 9, 4, 8) || Rect(1, 3, 9, 11) || H(9, 3, 6) || Rect(9, 11, 1, 3) || VL(9, 3, 6);
        if (V == 2) return N || E || S || W || VL(3, 3, 9) || VL(9, 3, 9) || H(3, 3, 9) || H(9, 3, 9) || Rect(4, 5, 4, 5) || Rect(7, 8, 7, 8);
        return N || E || S || W || VL(3, 2, 10) || VL(9, 2, 10) || H(3, 2, 10) || H(9, 2, 10) || Rect(1, 3, 7, 9) || Rect(9, 11, 3, 5) || Rect(4, 5, 4, 8) || Rect(7, 8, 4, 8);
    }
    if (X < 0 || X >= 5 || Y < 0 || Y >= 5) return false;
    const int32 Variant = static_cast<int32>(LayoutVariant);
    static const uint8 TwoWay[4][5] = {
        { 0, 0, 28, 4, 4 }, { 0, 28, 20, 4, 4 }, { 0, 0, 28, 12, 4 }, { 0, 0, 20, 28, 4 }
    };
    static const uint8 ThreeWay[4][5] = {
        { 0, 0, 31, 4, 4 }, { 0, 0, 21, 31, 4 }, { 0, 0, 31, 14, 4 }, { 0, 0, 31, 21, 7 }
    };
    static const uint8 FourWay[4][5] = {
        { 4, 4, 31, 4, 4 }, { 4, 14, 31, 14, 4 }, { 4, 10, 31, 10, 4 }, { 4, 6, 31, 12, 4 }
    };
    const uint8* Rows = JunctionType == EJMRoomJunctionType::TwoWay ? TwoWay[Variant]
        : JunctionType == EJMRoomJunctionType::ThreeWay ? ThreeWay[Variant] : FourWay[Variant];
    return (Rows[Y] & (1 << X)) != 0;
}

EJMRoomDirection AJMRoomModule::GetWorldOpenDirections() const
{
    return UJMRoomGridLibrary::RotateDirectionMask(static_cast<EJMRoomDirection>(CanonicalOpenDirections), FMath::RoundToInt(GetActorRotation().Yaw));
}

void AJMRoomModule::SetPrototypeMeshes(UStaticMesh* InFloor, UStaticMesh* InWall, UStaticMesh* InCeiling)
{
    Floor->SetStaticMesh(InFloor);
    Ceiling->SetStaticMesh(InCeiling);
    WallNorth->SetStaticMesh(InWall);
    WallEast->SetStaticMesh(InWall);
    WallSouth->SetStaticMesh(InWall);
    WallWest->SetStaticMesh(InWall);
    for (UStaticMeshComponent* Component : FloorTiles) Component->SetStaticMesh(InFloor);
    for (UStaticMeshComponent* Component : CeilingTiles) Component->SetStaticMesh(InCeiling);
    for (UStaticMeshComponent* Component : HorizontalWalls) Component->SetStaticMesh(InWall);
    for (UStaticMeshComponent* Component : VerticalWalls) Component->SetStaticMesh(InWall);
    FloorInstances13->SetStaticMesh(InFloor);
    CeilingInstances13->SetStaticMesh(InCeiling);
    HorizontalWallInstances13->SetStaticMesh(InWall);
    VerticalWallInstances13->SetStaticMesh(InWall);
}

void AJMRoomModule::SetCeilingsVisible(const bool bVisible)
{
    if (Ceiling)
    {
        Ceiling->SetVisibility(bVisible, true);
        Ceiling->SetHiddenInGame(!bVisible, true);
        Ceiling->SetCollisionEnabled(bVisible ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);
    }
    for (UStaticMeshComponent* Component : CeilingTiles)
    {
        if (!Component) continue;
        Component->SetVisibility(bVisible, true);
        Component->SetHiddenInGame(!bVisible, true);
        Component->SetCollisionEnabled(bVisible ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);
    }
    if (CeilingInstances13)
    {
        CeilingInstances13->SetVisibility(bVisible, true);
        CeilingInstances13->SetHiddenInGame(!bVisible, true);
        CeilingInstances13->SetCollisionEnabled(bVisible ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);
    }
    TArray<UStaticMeshComponent*> Components;
    GetComponents<UStaticMeshComponent>(Components);
    for (UStaticMeshComponent* Component : Components)
    {
        if (!Component || !Component->GetName().StartsWith(TEXT("JMGen_Ceiling_"))) continue;
        Component->SetVisibility(bVisible, true);
        Component->SetHiddenInGame(!bVisible, true);
        Component->SetCollisionEnabled(bVisible ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);
    }
}

FJMRoomValidationResult AJMRoomModule::ValidateRoomContract(const float Tolerance) const
{
    FJMRoomValidationResult Result;
    const auto Require = [&Result](const bool bCondition, const FText& Message)
    {
        if (!bCondition) Result.AddError(Message);
    };
    Require(RoomAnchor && StructureRoot && Floor && Ceiling && WallNorth && WallEast && WallSouth && WallWest,
        LOCTEXT("MissingStructure", "A required room structure component is missing."));
    Require(PortNorth && PortEast && PortSouth && PortWest,
        LOCTEXT("MissingPorts", "One or more room ports are missing."));
    Require(GetActorScale3D().Equals(FVector::OneVector, Tolerance),
        LOCTEXT("BadActorScale", "Room actor scale must be uniform (1,1,1); mirroring is forbidden."));
    const float NormalizedYaw = FRotator::NormalizeAxis(GetActorRotation().Yaw);
    Require(FMath::IsNearlyZero(FMath::Fmod(FMath::Abs(NormalizedYaw), 90.0f), Tolerance)
            || FMath::IsNearlyEqual(FMath::Fmod(FMath::Abs(NormalizedYaw), 90.0f), 90.0f, Tolerance),
        LOCTEXT("BadYaw", "Room actor yaw must be a 0, 90, 180, or 270 degree quarter turn."));
    Require(RoomAnchor && GetRootComponent() == RoomAnchor,
        LOCTEXT("BadAnchor", "RoomAnchor must remain the Actor root; its world transform is the room anchor transform."));
    if (bUseThirteenByThirteenLayout)
    {
        if (bUseAutomatic13x13Structure)
        {
            Require(FloorInstances13 && FloorInstances13->GetInstanceCount() == 169,
                LOCTEXT("BadTileCount13", "An automatic 13x13 room must contain exactly 169 floor instances."));
            Require(CeilingInstances13 && CeilingInstances13->GetInstanceCount() == 169,
                LOCTEXT("BadCeilingCount13", "An automatic 13x13 room must contain exactly 169 ceiling instances."));
        }
        if (PortNorth) Require(PortNorth->GetRelativeLocation().Equals(FVector(0, 2600, 0), Tolerance), LOCTEXT("BadNorthPort13", "13x13 north port must be at (0,2600,0)."));
        if (PortEast) Require(PortEast->GetRelativeLocation().Equals(FVector(2600, 0, 0), Tolerance), LOCTEXT("BadEastPort13", "13x13 east port must be at (2600,0,0)."));
        if (PortSouth) Require(PortSouth->GetRelativeLocation().Equals(FVector(0, -2600, 0), Tolerance), LOCTEXT("BadSouthPort13", "13x13 south port must be at (0,-2600,0)."));
        if (PortWest) Require(PortWest->GetRelativeLocation().Equals(FVector(-2600, 0, 0), Tolerance), LOCTEXT("BadWestPort13", "13x13 west port must be at (-2600,0,0)."));
        Require(IsTileWalkable(6, 6), LOCTEXT("MissingCenter13", "The 13x13 room layout must include center tile (6,6)."));
    }
    else if (bUseFiveByFiveLayout)
    {
        Require(FloorTiles.Num() == 25 && CeilingTiles.Num() == 25,
            LOCTEXT("BadTileCount", "A 5x5 room must contain exactly 25 floor and 25 ceiling tiles."));
        Require(HorizontalWalls.Num() == 30 && VerticalWalls.Num() == 30,
            LOCTEXT("BadEdgeCount", "A 5x5 room must contain 60 tile-edge wall components."));
        if (PortNorth) Require(PortNorth->GetRelativeLocation().Equals(FVector(0, 1000, 0), Tolerance), LOCTEXT("BadNorthPort5", "5x5 north port must be at (0,1000,0)."));
        if (PortEast) Require(PortEast->GetRelativeLocation().Equals(FVector(1000, 0, 0), Tolerance), LOCTEXT("BadEastPort5", "5x5 east port must be at (1000,0,0)."));
        if (PortSouth) Require(PortSouth->GetRelativeLocation().Equals(FVector(0, -1000, 0), Tolerance), LOCTEXT("BadSouthPort5", "5x5 south port must be at (0,-1000,0)."));
        if (PortWest) Require(PortWest->GetRelativeLocation().Equals(FVector(-1000, 0, 0), Tolerance), LOCTEXT("BadWestPort5", "5x5 west port must be at (-1000,0,0)."));
        Require(IsTileWalkable(2, 2), LOCTEXT("MissingCenter", "The room layout must include the center tile."));
    }
    else
    {
    if (Ceiling) Require(Ceiling->GetRelativeLocation().Equals(FVector(0, 0, 500), Tolerance), LOCTEXT("BadCeiling", "Ceiling must be at Z=500."));
    if (WallNorth) Require(WallNorth->GetRelativeLocation().Equals(FVector(0, 190, 0), Tolerance), LOCTEXT("BadNorthWall", "North wall must be at (0,190,0)."));
    if (WallEast) Require(WallEast->GetRelativeLocation().Equals(FVector(190, 0, 0), Tolerance), LOCTEXT("BadEastWall", "East wall must be at (190,0,0)."));
    if (WallSouth) Require(WallSouth->GetRelativeLocation().Equals(FVector(0, -190, 0), Tolerance), LOCTEXT("BadSouthWall", "South wall must be at (0,-190,0)."));
    if (WallWest) Require(WallWest->GetRelativeLocation().Equals(FVector(-190, 0, 0), Tolerance), LOCTEXT("BadWestWall", "West wall must be at (-190,0,0)."));
    if (PortNorth) Require(PortNorth->GetRelativeLocation().Equals(FVector(0, 200, 0), Tolerance), LOCTEXT("BadNorthPort", "North port must be at (0,200,0)."));
    if (PortEast) Require(PortEast->GetRelativeLocation().Equals(FVector(200, 0, 0), Tolerance), LOCTEXT("BadEastPort", "East port must be at (200,0,0)."));
    if (PortSouth) Require(PortSouth->GetRelativeLocation().Equals(FVector(0, -200, 0), Tolerance), LOCTEXT("BadSouthPort", "South port must be at (0,-200,0)."));
    if (PortWest) Require(PortWest->GetRelativeLocation().Equals(FVector(-200, 0, 0), Tolerance), LOCTEXT("BadWestPort", "West port must be at (-200,0,0)."));
    }

    const int32 ExpectedCount = JunctionType == EJMRoomJunctionType::TwoWay ? 2 : JunctionType == EJMRoomJunctionType::ThreeWay ? 3 : 4;
    Require(UJMRoomGridLibrary::CountDirections(static_cast<EJMRoomDirection>(CanonicalOpenDirections)) == ExpectedCount,
        LOCTEXT("BadJunction", "Junction type does not match canonical open direction count."));
    return Result;
}

#undef LOCTEXT_NAMESPACE
