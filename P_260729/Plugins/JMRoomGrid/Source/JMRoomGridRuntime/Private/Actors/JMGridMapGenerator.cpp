#include "Actors/JMGridMapGenerator.h"

#include "Actors/JMRoomModule.h"
#include "Blueprint/JMRoomGridLibrary.h"
#include "Components/ArrowComponent.h"
#include "Components/JMRoomPortComponent.h"
#include "Components/SceneComponent.h"
#include "Data/JMRoomDefinition.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "JMRoomGridRuntime.h"

#define LOCTEXT_NAMESPACE "JMGridMapGenerator"

namespace
{
    constexpr int32 GridSize = 5;

    struct FRoomCandidate
    {
        UJMRoomDefinition* Definition = nullptr;
        int32 Yaw = 0;
    };

    UJMRoomPortComponent* FindPortForWorldDirection(const AJMRoomModule* Room, const EJMRoomDirection Direction)
    {
        const TArray<UJMRoomPortComponent*> Ports { Room->PortNorth, Room->PortEast, Room->PortSouth, Room->PortWest };
        for (UJMRoomPortComponent* Port : Ports)
        {
            if (Port && Port->GetWorldDirection() == Direction) return Port;
        }
        return nullptr;
    }
}

AJMGridMapGenerator::AJMGridMapGenerator()
{
    PrimaryActorTick.bCanEverTick = false;
    GeneratorRoot = CreateDefaultSubobject<USceneComponent>(TEXT("GeneratorRoot"));
    SetRootComponent(GeneratorRoot);

    EntranceMarker = CreateDefaultSubobject<UArrowComponent>(TEXT("Entrance_South"));
    EntranceMarker->SetupAttachment(GeneratorRoot);
    EntranceMarker->SetRelativeLocation(FVector(0.0, -1000.0, 0.0));
    EntranceMarker->SetRelativeRotation(FRotator(0.0, 90.0, 0.0));
    EntranceMarker->ArrowColor = FColor::Green;

    ExitMarker = CreateDefaultSubobject<UArrowComponent>(TEXT("Exit_North"));
    ExitMarker->SetupAttachment(GeneratorRoot);
    ExitMarker->SetRelativeLocation(FVector(0.0, 1000.0, 0.0));
    ExitMarker->SetRelativeRotation(FRotator(0.0, 90.0, 0.0));
    ExitMarker->ArrowColor = FColor::Blue;
}

void AJMGridMapGenerator::BeginPlay()
{
    Super::BeginPlay();
    if (bGenerateOnBeginPlay) GeneratePreview();
}

TArray<FJMRoomCellRequirement> AJMGridMapGenerator::BuildStandardTopology()
{
    TArray<FJMRoomCellRequirement> Cells;
    Cells.Reserve(GridSize * GridSize);
    for (int32 Y = 0; Y < GridSize; ++Y)
    {
        for (int32 X = 0; X < GridSize; ++X)
        {
            FJMRoomCellRequirement Cell;
            Cell.Coordinate = FJMGridCoordinate(X, Y);
            if (Y > 0) Cell.RequiredOpenDirections |= EJMRoomDirection::North;
            if (X < GridSize - 1) Cell.RequiredOpenDirections |= EJMRoomDirection::East;
            if (Y < GridSize - 1) Cell.RequiredOpenDirections |= EJMRoomDirection::South;
            if (X > 0) Cell.RequiredOpenDirections |= EJMRoomDirection::West;
            Cell.bHasExit = X == 2 && Y == 0;
            Cell.bHasEntrance = X == 2 && Y == GridSize - 1;
            if (Cell.bHasExit) Cell.RequiredOpenDirections |= EJMRoomDirection::North;
            if (Cell.bHasEntrance) Cell.RequiredOpenDirections |= EJMRoomDirection::South;
            const int32 Count = UJMRoomGridLibrary::CountDirections(Cell.RequiredOpenDirections);
            Cell.JunctionType = Count == 2 ? EJMRoomJunctionType::TwoWay : Count == 3 ? EJMRoomJunctionType::ThreeWay : EJMRoomJunctionType::FourWay;
            Cells.Add(Cell);
        }
    }
    return Cells;
}

FVector AJMGridMapGenerator::GridToLocalLocation(const FJMGridCoordinate Coordinate) const
{
    return FVector((Coordinate.X - 2) * RoomCellSize, (2 - Coordinate.Y) * RoomCellSize, 0.0f);
}

bool AJMGridMapGenerator::GeneratePreview()
{
#if WITH_EDITOR
    if (!GetWorld()->IsGameWorld() && !bGenerateInEditor)
    {
        UE_LOG(LogJMRoomGrid, Warning, TEXT("Editor generation is disabled on %s."), *GetName());
        return false;
    }
#endif
    const int32 EffectiveSeed = bUseRandomSeed ? static_cast<int32>(FPlatformTime::Cycles()) : RandomSeed;
    if (bUseRandomSeed) RandomSeed = EffectiveSeed;
    return GenerateInternal(EffectiveSeed);
}

void AJMGridMapGenerator::GeneratePreviewInEditor()
{
    GeneratePreview();
}

bool AJMGridMapGenerator::RegenerateSameSeed()
{
    return GenerateInternal(RandomSeed);
}

void AJMGridMapGenerator::RegenerateSameSeedInEditor()
{
    RegenerateSameSeed();
}

bool AJMGridMapGenerator::GenerateNewSeed()
{
    RandomSeed = static_cast<int32>(FPlatformTime::Cycles());
    return GenerateInternal(RandomSeed);
}

void AJMGridMapGenerator::GenerateNewSeedInEditor()
{
    GenerateNewSeed();
}

bool AJMGridMapGenerator::GenerateInternal(const int32 EffectiveSeed)
{
    if (!GetWorld()) return false;

    TArray<UJMRoomDefinition*> LoadedDefinitions;
    for (const TSoftObjectPtr<UJMRoomDefinition>& Reference : RoomDefinitions)
    {
        if (UJMRoomDefinition* Definition = Reference.LoadSynchronous()) LoadedDefinitions.Add(Definition);
    }
    if (LoadedDefinitions.IsEmpty())
    {
        UE_LOG(LogJMRoomGrid, Error, TEXT("Generation aborted: no valid Room Definitions are assigned."));
        return false;
    }

    bool bUses13x13Rooms = false;
    for (UJMRoomDefinition* Definition : LoadedDefinitions)
    {
        UClass* RoomClass = Definition ? Definition->RoomBlueprintClass.LoadSynchronous() : nullptr;
        const AJMRoomModule* Defaults = RoomClass ? Cast<AJMRoomModule>(RoomClass->GetDefaultObject()) : nullptr;
        if (Defaults && Defaults->bUseThirteenByThirteenLayout) { bUses13x13Rooms = true; break; }
    }
    if (bUses13x13Rooms && !FMath::IsNearlyEqual(RoomCellSize, 5200.0f))
    {
        UE_LOG(LogJMRoomGrid, Warning, TEXT("Corrected stale RoomCellSize %.1f to 5200.0 for 13x13 room definitions."), RoomCellSize);
        RoomCellSize = 5200.0f;
    }
    EntranceMarker->SetRelativeLocation(FVector(0.0, -2.5f * RoomCellSize, 0.0));
    ExitMarker->SetRelativeLocation(FVector(0.0, 2.5f * RoomCellSize, 0.0));

    struct FPendingSelection { FJMRoomCellRequirement Cell; UJMRoomDefinition* Definition; int32 Yaw; };
    TArray<FPendingSelection> Selections;
    TMap<TObjectPtr<UJMRoomDefinition>, int32> PlannedCounts;
    FRandomStream Stream(EffectiveSeed);
    for (const FJMRoomCellRequirement& Cell : BuildStandardTopology())
    {
        TArray<FRoomCandidate> Candidates;
        float TotalWeight = 0.0f;
        for (UJMRoomDefinition* Definition : LoadedDefinitions)
        {
            if (!Definition || Definition->JunctionType != Cell.JunctionType || Definition->SelectionWeight <= 0.0f) continue;
            const int32 ExistingCount = PlannedCounts.FindRef(Definition);
            if (Definition->MaximumSpawnCount >= 0 && ExistingCount >= Definition->MaximumSpawnCount) continue;
            for (const int32 Yaw : Definition->AllowedRotations)
            {
                if (Yaw % 90 != 0) continue;
                if (UJMRoomGridLibrary::RotateDirectionMask(static_cast<EJMRoomDirection>(Definition->CanonicalOpenDirections), Yaw) == Cell.RequiredOpenDirections)
                {
                    Candidates.Add({ Definition, UJMRoomGridLibrary::NormalizeQuarterTurn(Yaw) });
                    TotalWeight += Definition->SelectionWeight;
                }
            }
        }
        if (Candidates.IsEmpty())
        {
            UE_LOG(LogJMRoomGrid, Error, TEXT("Generation aborted: no exact room candidate for cell (%d,%d), mask 0x%02x."),
                Cell.Coordinate.X, Cell.Coordinate.Y, static_cast<uint8>(Cell.RequiredOpenDirections));
            return false;
        }

        float Pick = Stream.FRandRange(0.0f, TotalWeight);
        FRoomCandidate Selected = Candidates.Last();
        for (const FRoomCandidate& Candidate : Candidates)
        {
            Pick -= Candidate.Definition->SelectionWeight;
            if (Pick <= 0.0f) { Selected = Candidate; break; }
        }
        Selections.Add({ Cell, Selected.Definition, Selected.Yaw });
        PlannedCounts.FindOrAdd(Selected.Definition)++;
    }

    for (UJMRoomDefinition* Definition : LoadedDefinitions)
    {
        if (Definition && PlannedCounts.FindRef(Definition) < Definition->MinimumSpawnCount)
        {
            UE_LOG(LogJMRoomGrid, Error, TEXT("Generation aborted: minimum spawn count not met for %s."), *Definition->GetName());
            return false;
        }
    }

    TArray<TSubclassOf<AJMRoomModule>> Classes;
    Classes.Reserve(Selections.Num());
    for (const FPendingSelection& Selection : Selections)
    {
        UClass* LoadedClass = Selection.Definition->RoomBlueprintClass.LoadSynchronous();
        if (!LoadedClass || !LoadedClass->IsChildOf(AJMRoomModule::StaticClass()))
        {
            UE_LOG(LogJMRoomGrid, Error, TEXT("Generation aborted: %s has no valid room Blueprint class."), *Selection.Definition->GetName());
            return false;
        }
        Classes.Add(LoadedClass);
    }

    ClearPreview();
    for (int32 Index = 0; Index < Selections.Num(); ++Index)
    {
        const FPendingSelection& Selection = Selections[Index];
        const FVector WorldLocation = GetActorLocation() + GridToLocalLocation(Selection.Cell.Coordinate);
        const FRotator WorldRotation(0.0, Selection.Yaw, 0.0);
        FActorSpawnParameters Params;
        Params.Owner = this;
        Params.ObjectFlags |= RF_Transactional;
#if WITH_EDITOR
        if (!GetWorld()->IsGameWorld()) Params.ObjectFlags |= RF_Transient;
#endif
        Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
        AJMRoomModule* Room = GetWorld()->SpawnActor<AJMRoomModule>(Classes[Index], WorldLocation, WorldRotation, Params);
        if (!Room)
        {
            UE_LOG(LogJMRoomGrid, Error, TEXT("Room spawn failed at (%d,%d); rolling back."), Selection.Cell.Coordinate.X, Selection.Cell.Coordinate.Y);
            ClearPreview();
            return false;
        }
        Room->SetActorScale3D(FVector::OneVector);
        Room->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
        Room->SetCeilingsVisible(!bHideCeilingsForPreview);
        Room->Tags.AddUnique(TEXT("JMRoomGrid.Generated"));
        FJMGeneratedRoomRecord& Record = GeneratedRooms.AddDefaulted_GetRef();
        Record.Coordinate = Selection.Cell.Coordinate;
        Record.RoomId = Selection.Definition->RoomId;
        Record.JunctionType = Selection.Cell.JunctionType;
        Record.OpenDirections = Selection.Cell.RequiredOpenDirections;
        Record.AppliedYaw = Selection.Yaw;
        Record.RoomActor = Room;
    }
    DrawGenerationDebug();
    PrintGenerationReport();
    return true;
}

void AJMGridMapGenerator::ClearPreview()
{
    TSet<TObjectPtr<AJMRoomModule>> RoomsToDestroy;
    for (FJMGeneratedRoomRecord& Record : GeneratedRooms)
    {
        if (IsValid(Record.RoomActor)) RoomsToDestroy.Add(Record.RoomActor);
    }
    if (GetWorld())
    {
        for (TActorIterator<AJMRoomModule> It(GetWorld()); It; ++It)
        {
            AJMRoomModule* Room = *It;
            if (IsValid(Room) && (Room->GetOwner() == this || Room->GetAttachParentActor() == this)) RoomsToDestroy.Add(Room);
        }
    }
    for (AJMRoomModule* Room : RoomsToDestroy) if (IsValid(Room)) Room->Destroy();
    GeneratedRooms.Reset();
}

void AJMGridMapGenerator::ClearAllGeneratedRoomsInLevel()
{
    if (!GetWorld()) return;
    TArray<AJMRoomModule*> RoomsToDestroy;
    for (TActorIterator<AJMRoomModule> It(GetWorld()); It; ++It)
    {
        AJMRoomModule* Room = *It;
        if (IsValid(Room) && Room->ActorHasTag(TEXT("JMRoomGrid.Generated"))) RoomsToDestroy.Add(Room);
    }
    for (AJMRoomModule* Room : RoomsToDestroy) if (IsValid(Room)) Room->Destroy();
    GeneratedRooms.Reset();
    UE_LOG(LogJMRoomGrid, Display, TEXT("Cleared %d generated room actors from level %s."), RoomsToDestroy.Num(), *GetWorld()->GetName());
}

FJMRoomValidationResult AJMGridMapGenerator::ValidateGeneratedMap() const
{
    FJMRoomValidationResult Result;
    if (GeneratedRooms.Num() != 25) Result.AddError(FText::Format(LOCTEXT("BadCount", "Expected 25 rooms, found {0}."), FText::AsNumber(GeneratedRooms.Num())));
    int32 Counts[3] = { 0, 0, 0 };
    TMap<FJMGridCoordinate, const FJMGeneratedRoomRecord*> ByCoordinate;
    for (const FJMGeneratedRoomRecord& Record : GeneratedRooms)
    {
        Counts[static_cast<int32>(Record.JunctionType)]++;
        ByCoordinate.Add(Record.Coordinate, &Record);
        if (!IsValid(Record.RoomActor)) { Result.AddError(LOCTEXT("MissingActor", "A generated room actor is missing.")); continue; }
        if (!Record.RoomActor->GetActorScale3D().Equals(FVector::OneVector, KINDA_SMALL_NUMBER))
            Result.AddError(FText::FromString(FString::Printf(TEXT("Cell (%d,%d), %s: generated room uses mirrored or non-unit scale."),
                Record.Coordinate.X, Record.Coordinate.Y, *Record.RoomActor->GetClass()->GetName())));
        const EJMRoomDirection ActualWorldMask = Record.RoomActor->GetWorldOpenDirections();
        if (ActualWorldMask != Record.OpenDirections)
            Result.AddError(FText::FromString(FString::Printf(
                TEXT("Cell (%d,%d), %s, yaw %d: direction mask mismatch (expected 0x%02x, actual 0x%02x, canonical 0x%02x)."),
                Record.Coordinate.X, Record.Coordinate.Y, *Record.RoomActor->GetClass()->GetName(), Record.AppliedYaw,
                static_cast<uint8>(Record.OpenDirections), static_cast<uint8>(ActualWorldMask), Record.RoomActor->CanonicalOpenDirections)));
        const FJMRoomValidationResult RoomResult = Record.RoomActor->ValidateRoomContract();
        for (const FText& Error : RoomResult.Errors)
            Result.AddError(FText::FromString(FString::Printf(TEXT("Cell (%d,%d), %s: %s"),
                Record.Coordinate.X, Record.Coordinate.Y, *Record.RoomActor->GetClass()->GetName(), *Error.ToString())));
    }
    if (Counts[0] != 4 || Counts[1] != 10 || Counts[2] != 11) Result.AddError(LOCTEXT("BadDistribution", "Expected junction distribution is 2-Way=4, 3-Way=10, 4-Way=11."));

    const struct { EJMRoomDirection Direction; int32 DX; int32 DY; } Neighbors[] = {
        { EJMRoomDirection::North, 0, -1 }, { EJMRoomDirection::East, 1, 0 },
        { EJMRoomDirection::South, 0, 1 }, { EJMRoomDirection::West, -1, 0 }
    };
    for (const FJMGeneratedRoomRecord& Record : GeneratedRooms)
    {
        for (const auto& Neighbor : Neighbors)
        {
            const FJMGridCoordinate OtherCoordinate(Record.Coordinate.X + Neighbor.DX, Record.Coordinate.Y + Neighbor.DY);
            const FJMGeneratedRoomRecord* const* Found = ByCoordinate.Find(OtherCoordinate);
            if (!Found) continue;
            const FJMGeneratedRoomRecord* Other = *Found;
            const bool bOpen = EnumHasAnyFlags(Record.OpenDirections, Neighbor.Direction);
            const bool bOtherOpen = EnumHasAnyFlags(Other->OpenDirections, UJMRoomGridLibrary::OppositeDirection(Neighbor.Direction));
            if (!bOpen || !bOtherOpen) Result.AddError(LOCTEXT("OneWay", "An adjacent connection is not bidirectional."));
            if (IsValid(Record.RoomActor) && IsValid(Other->RoomActor))
            {
                const UJMRoomPortComponent* PortA = FindPortForWorldDirection(Record.RoomActor, Neighbor.Direction);
                const UJMRoomPortComponent* PortB = FindPortForWorldDirection(Other->RoomActor, UJMRoomGridLibrary::OppositeDirection(Neighbor.Direction));
                if (!PortA || !PortB || !PortA->GetComponentLocation().Equals(PortB->GetComponentLocation(), 1.0f)) Result.AddError(LOCTEXT("PortPosition", "Adjacent room ports do not meet at the same world position."));
            }
        }
    }
    return Result;
}

void AJMGridMapGenerator::ValidateGeneratedMapInEditor()
{
    const FJMRoomValidationResult Result = ValidateGeneratedMap();
    UE_LOG(LogJMRoomGrid, Display, TEXT("Generated map validation: %s (%d errors, %d warnings)"),
        Result.bIsValid ? TEXT("VALID") : TEXT("INVALID"), Result.Errors.Num(), Result.Warnings.Num());
    for (const FText& Error : Result.Errors) UE_LOG(LogJMRoomGrid, Error, TEXT("%s"), *Error.ToString());
    for (const FText& Warning : Result.Warnings) UE_LOG(LogJMRoomGrid, Warning, TEXT("%s"), *Warning.ToString());
}

void AJMGridMapGenerator::PrintGenerationReport() const
{
    const FJMRoomValidationResult Validation = ValidateGeneratedMap();
    int32 Two = 0, Three = 0, Four = 0;
    for (const FJMGeneratedRoomRecord& Record : GeneratedRooms)
    {
        if (Record.JunctionType == EJMRoomJunctionType::TwoWay) ++Two;
        else if (Record.JunctionType == EJMRoomJunctionType::ThreeWay) ++Three;
        else ++Four;
    }
    FBox RoomCenters(EForceInit::ForceInit);
    for (const FJMGeneratedRoomRecord& Record : GeneratedRooms)
        if (IsValid(Record.RoomActor)) RoomCenters += Record.RoomActor->GetActorLocation();
    UE_LOG(LogJMRoomGrid, Display, TEXT("Seed=%d Rooms=%d 2-Way=%d 3-Way=%d 4-Way=%d CellSize=%.1f CenterBoundsMin=%s CenterBoundsMax=%s Valid=%s Errors=%d"),
        RandomSeed, GeneratedRooms.Num(), Two, Three, Four, RoomCellSize,
        *RoomCenters.Min.ToCompactString(), *RoomCenters.Max.ToCompactString(),
        Validation.bIsValid ? TEXT("true") : TEXT("false"), Validation.Errors.Num());
    for (const FText& Error : Validation.Errors) UE_LOG(LogJMRoomGrid, Error, TEXT("%s"), *Error.ToString());
}

void AJMGridMapGenerator::DrawGenerationDebug() const
{
    if (!bShowDebug || !GetWorld()) return;
    for (const FJMGeneratedRoomRecord& Record : GeneratedRooms)
    {
        if (!IsValid(Record.RoomActor)) continue;
        const FVector Location = Record.RoomActor->GetActorLocation();
        if (bShowRoomBounds) DrawDebugBox(GetWorld(), Location + FVector(0, 0, RoomHeight * 0.5f), FVector(RoomCellSize * 0.5f, RoomCellSize * 0.5f, RoomHeight * 0.5f), GetActorQuat(), FColor::Silver, false, 30.0f);
        FString Label;
        if (bShowCoordinates) Label += FString::Printf(TEXT("(%d,%d) "), Record.Coordinate.X, Record.Coordinate.Y);
        Label += Record.RoomId.ToString();
        if (bShowRoomType) Label += FString::Printf(TEXT(" %d-Way Yaw=%d"), UJMRoomGridLibrary::CountDirections(Record.OpenDirections), Record.AppliedYaw);
        DrawDebugString(GetWorld(), Location + FVector(0, 0, RoomHeight + 30.0f), Label, nullptr, FColor::White, 30.0f, true);
        if (bShowPortDirections)
        {
            for (const EJMRoomDirection Direction : { EJMRoomDirection::North, EJMRoomDirection::East, EJMRoomDirection::South, EJMRoomDirection::West })
            {
                if (!EnumHasAnyFlags(Record.OpenDirections, Direction)) continue;
                const FVector Vector = UJMRoomGridLibrary::DirectionVector(Direction);
                DrawDebugDirectionalArrow(GetWorld(), Location, Location + Vector * 200.0f, 30.0f, FColor::Green, false, 30.0f, 0, 3.0f);
            }
        }
    }
}

#undef LOCTEXT_NAMESPACE
