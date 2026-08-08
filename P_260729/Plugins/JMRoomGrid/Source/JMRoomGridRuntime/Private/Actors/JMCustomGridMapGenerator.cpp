#include "Actors/JMCustomGridMapGenerator.h"

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

#define LOCTEXT_NAMESPACE "JMCustomGridMapGenerator"

namespace
{
    const FName GeneratedTag(TEXT("JMRoomGrid.Generated"));
    const FName CustomGeneratedTag(TEXT("JMRoomGrid.CustomGenerated"));

    struct FDirectionStep
    {
        EJMRoomDirection Direction;
        int32 DX;
        int32 DY;
    };

    // Custom-grid coordinates deliberately follow the user's Cartesian example: North increases Y.
    constexpr FDirectionStep DirectionSteps[] = {
        { EJMRoomDirection::North, 0, 1 }, { EJMRoomDirection::East, 1, 0 },
        { EJMRoomDirection::South, 0, -1 }, { EJMRoomDirection::West, -1, 0 }
    };

    EJMRoomJunctionType JunctionForDirectionCount(const int32 Count)
    {
        switch (Count)
        {
        case 1: return EJMRoomJunctionType::OneWay;
        case 2: return EJMRoomJunctionType::TwoWay;
        case 3: return EJMRoomJunctionType::ThreeWay;
        default: return EJMRoomJunctionType::FourWay;
        }
    }

    UJMRoomPortComponent* FindPortForWorldDirection(const AJMRoomModule* Room, const EJMRoomDirection Direction)
    {
        const TArray<UJMRoomPortComponent*> Ports { Room->PortNorth, Room->PortEast, Room->PortSouth, Room->PortWest };
        for (UJMRoomPortComponent* Port : Ports)
        {
            if (Port && Port->GetWorldDirection() == Direction) return Port;
        }
        return nullptr;
    }

    FText CellMessage(const FJMGridCoordinate& Coordinate, const FString& Message)
    {
        return FText::FromString(FString::Printf(TEXT("Cell (%d,%d): %s"), Coordinate.X, Coordinate.Y, *Message));
    }
}

AJMCustomGridMapGenerator::AJMCustomGridMapGenerator()
{
    PrimaryActorTick.bCanEverTick = false;
    GeneratorRoot = CreateDefaultSubobject<USceneComponent>(TEXT("GeneratorRoot"));
    SetRootComponent(GeneratorRoot);

    EntranceMarker = CreateDefaultSubobject<UArrowComponent>(TEXT("EntranceMarker"));
    EntranceMarker->SetupAttachment(GeneratorRoot);
    EntranceMarker->ArrowColor = FColor::Green;
    EntranceMarker->SetVisibility(false);

    ExitMarker = CreateDefaultSubobject<UArrowComponent>(TEXT("ExitMarker"));
    ExitMarker->SetupAttachment(GeneratorRoot);
    ExitMarker->ArrowColor = FColor::Blue;
    ExitMarker->SetVisibility(false);

    Cells.Reserve(GridWidth * GridHeight);
    for (int32 Y = 0; Y < GridHeight; ++Y)
    {
        for (int32 X = 0; X < GridWidth; ++X)
        {
            FJMCustomGridCell& Cell = Cells.AddDefaulted_GetRef();
            Cell.Coordinate = FJMGridCoordinate(X, Y);
        }
    }
}

void AJMCustomGridMapGenerator::BeginPlay()
{
    Super::BeginPlay();
    if (bGenerateOnBeginPlay) GeneratePreview();
}

#if WITH_EDITOR
void AJMCustomGridMapGenerator::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);
    const FName PropertyName = PropertyChangedEvent.GetPropertyName();
    if (PropertyName == GET_MEMBER_NAME_CHECKED(AJMCustomGridMapGenerator, GridWidth)
        || PropertyName == GET_MEMBER_NAME_CHECKED(AJMCustomGridMapGenerator, GridHeight))
    {
        SynchronizeGridCells();
    }
    else
    {
        UpdateRoleMarkers();
    }
}
#endif

void AJMCustomGridMapGenerator::SynchronizeGridCells()
{
    GridWidth = FMath::Clamp(GridWidth, 1, 100);
    GridHeight = FMath::Clamp(GridHeight, 1, 100);
    TMap<FJMGridCoordinate, FJMCustomGridCell> Existing;
    for (const FJMCustomGridCell& Cell : Cells)
    {
        if (Cell.Coordinate.X >= 0 && Cell.Coordinate.X < GridWidth
            && Cell.Coordinate.Y >= 0 && Cell.Coordinate.Y < GridHeight)
        {
            Existing.FindOrAdd(Cell.Coordinate) = Cell;
        }
    }

    Cells.Reset(GridWidth * GridHeight);
    for (int32 Y = 0; Y < GridHeight; ++Y)
    {
        for (int32 X = 0; X < GridWidth; ++X)
        {
            const FJMGridCoordinate Coordinate(X, Y);
            FJMCustomGridCell Cell = Existing.FindRef(Coordinate);
            Cell.Coordinate = Coordinate;
            Cells.Add(MoveTemp(Cell));
        }
    }
    UpdateRoleMarkers();
}

bool AJMCustomGridMapGenerator::SetCell(const int32 X, const int32 Y, const bool bEnabled, const int32 OpenDirections,
    const bool bEntrance, const bool bExit)
{
    FJMCustomGridCell* Cell = FindCell(X, Y);
    if (!Cell) return false;
    Cell->bEnabled = bEnabled;
    Cell->OpenDirections = OpenDirections & static_cast<int32>(EJMRoomDirection::All);
    Cell->bEntrance = bEnabled && bEntrance;
    Cell->bExit = bEnabled && bExit;
    UpdateRoleMarkers();
    return true;
}

FJMCustomGridCell AJMCustomGridMapGenerator::GetCellChecked(const int32 X, const int32 Y) const
{
    checkf(FindCell(X, Y), TEXT("Custom grid coordinate (%d,%d) is out of range or cells are not synchronized."), X, Y);
    return *FindCell(X, Y);
}

const FJMCustomGridCell* AJMCustomGridMapGenerator::FindCell(const int32 X, const int32 Y) const
{
    return Cells.FindByPredicate([X, Y](const FJMCustomGridCell& Cell)
    {
        return Cell.Coordinate.X == X && Cell.Coordinate.Y == Y;
    });
}

FJMCustomGridCell* AJMCustomGridMapGenerator::FindCell(const int32 X, const int32 Y)
{
    return Cells.FindByPredicate([X, Y](const FJMCustomGridCell& Cell)
    {
        return Cell.Coordinate.X == X && Cell.Coordinate.Y == Y;
    });
}

FVector AJMCustomGridMapGenerator::GridToLocalLocation(const FJMGridCoordinate Coordinate) const
{
    const float CenterX = (GridWidth - 1) * 0.5f;
    const float CenterY = (GridHeight - 1) * 0.5f;
    return FVector((Coordinate.X - CenterX) * RoomCellSize, (Coordinate.Y - CenterY) * RoomCellSize, 0.0f);
}

FJMRoomValidationResult AJMCustomGridMapGenerator::ValidateGridDesign() const
{
    FJMRoomValidationResult Result;
    if (GridWidth < 1 || GridHeight < 1)
        Result.AddError(LOCTEXT("InvalidGridSize", "Grid width and height must both be at least 1."));
    if (Cells.Num() != GridWidth * GridHeight)
        Result.AddError(FText::Format(LOCTEXT("UnsynchronizedCells", "Grid expects {0} cells but contains {1}. Run Synchronize Cells To Grid Size."),
            FText::AsNumber(GridWidth * GridHeight), FText::AsNumber(Cells.Num())));

    TMap<FJMGridCoordinate, const FJMCustomGridCell*> ByCoordinate;
    TArray<const FJMCustomGridCell*> ActiveCells;
    int32 EntranceCount = 0;
    int32 ExitCount = 0;
    for (const FJMCustomGridCell& Cell : Cells)
    {
        if (Cell.Coordinate.X < 0 || Cell.Coordinate.X >= GridWidth || Cell.Coordinate.Y < 0 || Cell.Coordinate.Y >= GridHeight)
        {
            Result.AddError(CellMessage(Cell.Coordinate, TEXT("coordinate is outside GridWidth/GridHeight.")));
            continue;
        }
        if (ByCoordinate.Contains(Cell.Coordinate))
        {
            Result.AddError(CellMessage(Cell.Coordinate, TEXT("coordinate is duplicated.")));
            continue;
        }
        ByCoordinate.Add(Cell.Coordinate, &Cell);
        if (!Cell.bEnabled)
        {
            if (Cell.bEntrance || Cell.bExit || !Cell.SpecialRoomDefinition.IsNull() || Cell.GetDirectionMask() != EJMRoomDirection::None)
                Result.AddWarning(CellMessage(Cell.Coordinate, TEXT("disabled cell contains settings that will be ignored.")));
            continue;
        }
        ActiveCells.Add(&Cell);
        EntranceCount += Cell.bEntrance ? 1 : 0;
        ExitCount += Cell.bExit ? 1 : 0;
        const int32 DirectionCount = UJMRoomGridLibrary::CountDirections(Cell.GetDirectionMask());
        if (DirectionCount == 0)
            Result.AddError(CellMessage(Cell.Coordinate, TEXT("enabled cell has no open direction (0-Way is unsupported).")));
    }
    if (ActiveCells.IsEmpty()) Result.AddError(LOCTEXT("NoActiveCells", "The custom grid has no enabled cells."));
    if (EntranceCount != 1)
        Result.AddError(FText::Format(LOCTEXT("EntranceCount", "Exactly one Entrance is required; found {0}."), FText::AsNumber(EntranceCount)));
    if (ExitCount != 1)
        Result.AddError(FText::Format(LOCTEXT("ExitCount", "Exactly one Exit is required; found {0}."), FText::AsNumber(ExitCount)));
    for (const FJMCustomGridCell* Cell : ActiveCells)
        if (Cell->bEntrance && Cell->bExit)
            Result.AddError(CellMessage(Cell->Coordinate, TEXT("Entrance and Exit must be different cells.")));

    for (const FJMCustomGridCell* Cell : ActiveCells)
    {
        int32 ExternalOpeningCount = 0;
        for (const FDirectionStep& Step : DirectionSteps)
        {
            const FJMGridCoordinate NeighborCoordinate(Cell->Coordinate.X + Step.DX, Cell->Coordinate.Y + Step.DY);
            const FJMCustomGridCell* const* NeighborPtr = ByCoordinate.Find(NeighborCoordinate);
            const FJMCustomGridCell* Neighbor = NeighborPtr ? *NeighborPtr : nullptr;
            const bool bOpen = EnumHasAnyFlags(Cell->GetDirectionMask(), Step.Direction);
            const bool bNeighborOpen = Neighbor && Neighbor->bEnabled
                && EnumHasAnyFlags(Neighbor->GetDirectionMask(), UJMRoomGridLibrary::OppositeDirection(Step.Direction));
            if (bOpen && (!Neighbor || !Neighbor->bEnabled))
            {
                ++ExternalOpeningCount;
                if (!Cell->bEntrance && !Cell->bExit)
                    Result.AddError(CellMessage(Cell->Coordinate, FString::Printf(TEXT("%s opens into an inactive or out-of-grid cell."),
                        *UEnum::GetValueAsString(Step.Direction))));
            }
            else if (Neighbor && Neighbor->bEnabled && bOpen != bNeighborOpen)
            {
                Result.AddError(CellMessage(Cell->Coordinate, FString::Printf(TEXT("%s does not match cell (%d,%d)'s opposite direction."),
                    *UEnum::GetValueAsString(Step.Direction), NeighborCoordinate.X, NeighborCoordinate.Y)));
            }
        }
        if ((Cell->bEntrance || Cell->bExit) && ExternalOpeningCount != 1)
            Result.AddError(CellMessage(Cell->Coordinate, FString::Printf(TEXT("%s must have exactly one direction opening outside the active grid; found %d."),
                Cell->bEntrance ? TEXT("Entrance") : TEXT("Exit"), ExternalOpeningCount)));
    }

    if (!ActiveCells.IsEmpty())
    {
        TSet<FJMGridCoordinate> Reached;
        TArray<FJMGridCoordinate> Queue { ActiveCells[0]->Coordinate };
        while (!Queue.IsEmpty())
        {
            const FJMGridCoordinate Current = Queue.Pop(EAllowShrinking::No);
            if (Reached.Contains(Current)) continue;
            const FJMCustomGridCell* const* CurrentPtr = ByCoordinate.Find(Current);
            if (!CurrentPtr || !(*CurrentPtr)->bEnabled) continue;
            Reached.Add(Current);
            for (const FDirectionStep& Step : DirectionSteps)
            {
                if (EnumHasAnyFlags((*CurrentPtr)->GetDirectionMask(), Step.Direction))
                    Queue.Add(FJMGridCoordinate(Current.X + Step.DX, Current.Y + Step.DY));
            }
        }
        if (Reached.Num() != ActiveCells.Num())
            Result.AddError(FText::Format(LOCTEXT("DisconnectedGrid", "All enabled cells must form one connected map; reached {0} of {1}."),
                FText::AsNumber(Reached.Num()), FText::AsNumber(ActiveCells.Num())));
    }
    return Result;
}

void AJMCustomGridMapGenerator::ValidateGridDesignInEditor() const
{
    const FJMRoomValidationResult Result = ValidateGridDesign();
    UE_LOG(LogJMRoomGrid, Display, TEXT("Custom grid design: %s (%d errors, %d warnings)"),
        Result.bIsValid ? TEXT("VALID") : TEXT("INVALID"), Result.Errors.Num(), Result.Warnings.Num());
    for (const FText& Error : Result.Errors) UE_LOG(LogJMRoomGrid, Error, TEXT("%s"), *Error.ToString());
    for (const FText& Warning : Result.Warnings) UE_LOG(LogJMRoomGrid, Warning, TEXT("%s"), *Warning.ToString());
}

bool AJMCustomGridMapGenerator::GeneratePreview()
{
#if WITH_EDITOR
    if (GetWorld() && !GetWorld()->IsGameWorld() && !bGenerateInEditor)
    {
        UE_LOG(LogJMRoomGrid, Warning, TEXT("Editor generation is disabled on %s."), *GetName());
        return false;
    }
#endif
    const int32 EffectiveSeed = bUseRandomSeed ? static_cast<int32>(FPlatformTime::Cycles()) : RandomSeed;
    if (bUseRandomSeed) RandomSeed = EffectiveSeed;
    return GenerateInternal(EffectiveSeed);
}

void AJMCustomGridMapGenerator::GeneratePreviewInEditor()
{
    GeneratePreview();
}

bool AJMCustomGridMapGenerator::RegenerateSameSeed()
{
    return GenerateInternal(RandomSeed);
}

void AJMCustomGridMapGenerator::RegenerateSameSeedInEditor()
{
    RegenerateSameSeed();
}

bool AJMCustomGridMapGenerator::GenerateNewSeed()
{
    RandomSeed = static_cast<int32>(FPlatformTime::Cycles());
    return GenerateInternal(RandomSeed);
}

void AJMCustomGridMapGenerator::GenerateNewSeedInEditor()
{
    GenerateNewSeed();
}

bool AJMCustomGridMapGenerator::GenerateInternal(const int32 EffectiveSeed)
{
    if (!GetWorld()) return false;
    const FJMRoomValidationResult DesignResult = ValidateGridDesign();
    if (!DesignResult.bIsValid)
    {
        UE_LOG(LogJMRoomGrid, Error, TEXT("Custom generation aborted: grid design is invalid."));
        for (const FText& Error : DesignResult.Errors) UE_LOG(LogJMRoomGrid, Error, TEXT("%s"), *Error.ToString());
        return false;
    }

    TArray<UJMRoomDefinition*> LoadedDefinitions;
    for (const TSoftObjectPtr<UJMRoomDefinition>& Reference : RoomDefinitions)
        if (UJMRoomDefinition* Definition = Reference.LoadSynchronous()) LoadedDefinitions.AddUnique(Definition);
    for (const FJMCustomGridCell& Cell : Cells)
        if (Cell.bEnabled && !Cell.SpecialRoomDefinition.IsNull())
            if (UJMRoomDefinition* Definition = Cell.SpecialRoomDefinition.LoadSynchronous()) LoadedDefinitions.AddUnique(Definition);
    if (LoadedDefinitions.IsEmpty())
    {
        UE_LOG(LogJMRoomGrid, Error, TEXT("Custom generation aborted: no valid Room Definitions are assigned."));
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
        UE_LOG(LogJMRoomGrid, Warning, TEXT("Corrected RoomCellSize %.1f to 5200.0 for 13x13 room definitions."), RoomCellSize);
        RoomCellSize = 5200.0f;
    }

    struct FRoomCandidate { UJMRoomDefinition* Definition; int32 Yaw; };
    struct FPendingSelection { const FJMCustomGridCell* Cell; UJMRoomDefinition* Definition; int32 Yaw; TSubclassOf<AJMRoomModule> RoomClass; };
    TArray<FPendingSelection> Selections;
    TMap<TObjectPtr<UJMRoomDefinition>, int32> PlannedCounts;
    FRandomStream Stream(EffectiveSeed);
    for (const FJMCustomGridCell& Cell : Cells)
    {
        if (!Cell.bEnabled) continue;
        const EJMRoomDirection RequiredMask = Cell.GetDirectionMask();
        const int32 DirectionCount = UJMRoomGridLibrary::CountDirections(RequiredMask);
        const EJMRoomJunctionType RequiredJunction = JunctionForDirectionCount(DirectionCount);
        UJMRoomDefinition* ForcedDefinition = Cell.SpecialRoomDefinition.IsNull() ? nullptr : Cell.SpecialRoomDefinition.LoadSynchronous();
        TArray<FRoomCandidate> Candidates;
        float TotalWeight = 0.0f;
        for (UJMRoomDefinition* Definition : LoadedDefinitions)
        {
            if (!Definition || (ForcedDefinition && Definition != ForcedDefinition)
                || Definition->JunctionType != RequiredJunction || Definition->SelectionWeight <= 0.0f) continue;
            const int32 ExistingCount = PlannedCounts.FindRef(Definition);
            if (Definition->MaximumSpawnCount >= 0 && ExistingCount >= Definition->MaximumSpawnCount) continue;
            for (const int32 Yaw : Definition->AllowedRotations)
            {
                if (Yaw % 90 != 0) continue;
                if (UJMRoomGridLibrary::RotateDirectionMask(static_cast<EJMRoomDirection>(Definition->CanonicalOpenDirections), Yaw) == RequiredMask)
                {
                    Candidates.Add({ Definition, UJMRoomGridLibrary::NormalizeQuarterTurn(Yaw) });
                    TotalWeight += Definition->SelectionWeight;
                }
            }
        }
        if (Candidates.IsEmpty())
        {
            UE_LOG(LogJMRoomGrid, Error,
                TEXT("Custom generation aborted: no exact %d-Way room candidate for cell (%d,%d), mask 0x%02x%s."),
                DirectionCount, Cell.Coordinate.X, Cell.Coordinate.Y, static_cast<uint8>(RequiredMask),
                DirectionCount == 1 ? TEXT(". Assign a 1-Way Room Definition (or Special Room) because the existing library contains only 2/3/4-Way rooms") : TEXT(""));
            return false;
        }

        float Pick = Stream.FRandRange(0.0f, TotalWeight);
        FRoomCandidate Selected = Candidates.Last();
        for (const FRoomCandidate& Candidate : Candidates)
        {
            Pick -= Candidate.Definition->SelectionWeight;
            if (Pick <= 0.0f) { Selected = Candidate; break; }
        }
        UClass* LoadedClass = Selected.Definition->RoomBlueprintClass.LoadSynchronous();
        if (!LoadedClass || !LoadedClass->IsChildOf(AJMRoomModule::StaticClass()))
        {
            UE_LOG(LogJMRoomGrid, Error, TEXT("Custom generation aborted: %s has no valid room Blueprint class."), *Selected.Definition->GetName());
            return false;
        }
        Selections.Add({ &Cell, Selected.Definition, Selected.Yaw, LoadedClass });
        PlannedCounts.FindOrAdd(Selected.Definition)++;
    }

    for (UJMRoomDefinition* Definition : LoadedDefinitions)
    {
        if (Definition && PlannedCounts.FindRef(Definition) < Definition->MinimumSpawnCount)
        {
            UE_LOG(LogJMRoomGrid, Error, TEXT("Custom generation aborted: minimum spawn count not met for %s."), *Definition->GetName());
            return false;
        }
    }

    ClearPreview();
    for (const FPendingSelection& Selection : Selections)
    {
        const FVector WorldLocation = GetActorTransform().TransformPosition(GridToLocalLocation(Selection.Cell->Coordinate));
        FRotator WorldRotation = GetActorRotation();
        WorldRotation.Yaw += Selection.Yaw;
        FActorSpawnParameters Params;
        Params.Owner = this;
        Params.ObjectFlags |= RF_Transactional;
#if WITH_EDITOR
        if (!GetWorld()->IsGameWorld()) Params.ObjectFlags |= RF_Transient;
#endif
        Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
        AJMRoomModule* Room = GetWorld()->SpawnActor<AJMRoomModule>(Selection.RoomClass, WorldLocation, WorldRotation, Params);
        if (!Room)
        {
            UE_LOG(LogJMRoomGrid, Error, TEXT("Custom room spawn failed at (%d,%d); rolling back."),
                Selection.Cell->Coordinate.X, Selection.Cell->Coordinate.Y);
            ClearPreview();
            return false;
        }
        Room->SetActorScale3D(FVector::OneVector);
        Room->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
        Room->SetCeilingsVisible(!bHideCeilingsForPreview);
        Room->Tags.AddUnique(GeneratedTag);
        Room->Tags.AddUnique(CustomGeneratedTag);
        FJMGeneratedRoomRecord& Record = GeneratedRooms.AddDefaulted_GetRef();
        Record.Coordinate = Selection.Cell->Coordinate;
        Record.RoomId = Selection.Definition->RoomId;
        Record.JunctionType = JunctionForDirectionCount(UJMRoomGridLibrary::CountDirections(Selection.Cell->GetDirectionMask()));
        Record.OpenDirections = Selection.Cell->GetDirectionMask();
        Record.AppliedYaw = Selection.Yaw;
        Record.RoomActor = Room;
    }
    UpdateRoleMarkers();
    DrawGeneratedDebug();
    const FJMRoomValidationResult GeneratedResult = ValidateGeneratedMap();
    UE_LOG(LogJMRoomGrid, Display, TEXT("Custom grid generated: Seed=%d Rooms=%d Valid=%s Errors=%d"),
        EffectiveSeed, GeneratedRooms.Num(), GeneratedResult.bIsValid ? TEXT("true") : TEXT("false"), GeneratedResult.Errors.Num());
    return GeneratedResult.bIsValid;
}

void AJMCustomGridMapGenerator::ClearPreview()
{
    TSet<TObjectPtr<AJMRoomModule>> RoomsToDestroy;
    for (FJMGeneratedRoomRecord& Record : GeneratedRooms)
        if (IsValid(Record.RoomActor)) RoomsToDestroy.Add(Record.RoomActor);
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

void AJMCustomGridMapGenerator::ClearAllCustomGeneratedRoomsInLevel()
{
    if (!GetWorld()) return;
    TArray<AJMRoomModule*> RoomsToDestroy;
    for (TActorIterator<AJMRoomModule> It(GetWorld()); It; ++It)
    {
        AJMRoomModule* Room = *It;
        if (IsValid(Room) && Room->ActorHasTag(CustomGeneratedTag)) RoomsToDestroy.Add(Room);
    }
    for (AJMRoomModule* Room : RoomsToDestroy) if (IsValid(Room)) Room->Destroy();
    GeneratedRooms.Reset();
    UE_LOG(LogJMRoomGrid, Display, TEXT("Cleared %d custom-generated rooms from level %s; legacy generated rooms were not touched."),
        RoomsToDestroy.Num(), *GetWorld()->GetName());
}

FJMRoomValidationResult AJMCustomGridMapGenerator::ValidateGeneratedMap() const
{
    FJMRoomValidationResult Result = ValidateGridDesign();
    int32 ExpectedCount = 0;
    for (const FJMCustomGridCell& Cell : Cells) ExpectedCount += Cell.bEnabled ? 1 : 0;
    if (GeneratedRooms.Num() != ExpectedCount)
        Result.AddError(FText::Format(LOCTEXT("GeneratedCount", "Expected {0} generated rooms, found {1}."),
            FText::AsNumber(ExpectedCount), FText::AsNumber(GeneratedRooms.Num())));

    TMap<FJMGridCoordinate, const FJMGeneratedRoomRecord*> ByCoordinate;
    const int32 GeneratorYaw = UJMRoomGridLibrary::NormalizeQuarterTurn(FMath::RoundToInt(GetActorRotation().Yaw));
    if (!FMath::IsNearlyZero(GetActorRotation().Pitch) || !FMath::IsNearlyZero(GetActorRotation().Roll)
        || !FMath::IsNearlyZero(FMath::FindDeltaAngleDegrees(GetActorRotation().Yaw, static_cast<float>(GeneratorYaw)), 0.1f))
        Result.AddError(LOCTEXT("GeneratorRotation", "Custom generator rotation must be a yaw-only multiple of 90 degrees."));

    for (const FJMGeneratedRoomRecord& Record : GeneratedRooms)
    {
        if (ByCoordinate.Contains(Record.Coordinate))
            Result.AddError(CellMessage(Record.Coordinate, TEXT("more than one generated room occupies this coordinate.")));
        ByCoordinate.Add(Record.Coordinate, &Record);
        if (!IsValid(Record.RoomActor))
        {
            Result.AddError(CellMessage(Record.Coordinate, TEXT("generated room actor is missing.")));
            continue;
        }
        if (!Record.RoomActor->GetActorScale3D().Equals(FVector::OneVector, KINDA_SMALL_NUMBER))
            Result.AddError(CellMessage(Record.Coordinate, TEXT("generated room uses mirrored or non-unit scale.")));
        const EJMRoomDirection ExpectedWorldMask = UJMRoomGridLibrary::RotateDirectionMask(Record.OpenDirections, GeneratorYaw);
        if (Record.RoomActor->GetWorldOpenDirections() != ExpectedWorldMask)
            Result.AddError(CellMessage(Record.Coordinate, TEXT("spawned Blueprint directions do not match the configured mask and yaw.")));
        const FJMRoomValidationResult RoomResult = Record.RoomActor->ValidateRoomContract();
        for (const FText& Error : RoomResult.Errors)
            Result.AddError(CellMessage(Record.Coordinate, Error.ToString()));
    }

    for (const FJMGeneratedRoomRecord& Record : GeneratedRooms)
    {
        for (const FDirectionStep& Step : DirectionSteps)
        {
            if (!EnumHasAnyFlags(Record.OpenDirections, Step.Direction)) continue;
            const FJMGridCoordinate OtherCoordinate(Record.Coordinate.X + Step.DX, Record.Coordinate.Y + Step.DY);
            const FJMGeneratedRoomRecord* const* Found = ByCoordinate.Find(OtherCoordinate);
            if (!Found) continue;
            const FJMGeneratedRoomRecord* Other = *Found;
            if (!IsValid(Record.RoomActor) || !IsValid(Other->RoomActor)) continue;
            const EJMRoomDirection WorldDirection = UJMRoomGridLibrary::RotateDirectionMask(Step.Direction, GeneratorYaw);
            const UJMRoomPortComponent* PortA = FindPortForWorldDirection(Record.RoomActor, WorldDirection);
            const UJMRoomPortComponent* PortB = FindPortForWorldDirection(Other->RoomActor, UJMRoomGridLibrary::OppositeDirection(WorldDirection));
            if (!PortA || !PortB || !PortA->GetComponentLocation().Equals(PortB->GetComponentLocation(), 1.0f))
                Result.AddError(CellMessage(Record.Coordinate, FString::Printf(TEXT("port does not meet cell (%d,%d)."), OtherCoordinate.X, OtherCoordinate.Y)));
        }
    }
    return Result;
}

void AJMCustomGridMapGenerator::ValidateGeneratedMapInEditor() const
{
    const FJMRoomValidationResult Result = ValidateGeneratedMap();
    UE_LOG(LogJMRoomGrid, Display, TEXT("Custom generated map: %s (%d errors, %d warnings)"),
        Result.bIsValid ? TEXT("VALID") : TEXT("INVALID"), Result.Errors.Num(), Result.Warnings.Num());
    for (const FText& Error : Result.Errors) UE_LOG(LogJMRoomGrid, Error, TEXT("%s"), *Error.ToString());
    for (const FText& Warning : Result.Warnings) UE_LOG(LogJMRoomGrid, Warning, TEXT("%s"), *Warning.ToString());
}

void AJMCustomGridMapGenerator::UpdateRoleMarkers()
{
    const FJMCustomGridCell* Entrance = Cells.FindByPredicate([](const FJMCustomGridCell& Cell) { return Cell.bEnabled && Cell.bEntrance; });
    const FJMCustomGridCell* Exit = Cells.FindByPredicate([](const FJMCustomGridCell& Cell) { return Cell.bEnabled && Cell.bExit; });
    EntranceMarker->SetVisibility(Entrance != nullptr);
    ExitMarker->SetVisibility(Exit != nullptr);
    if (Entrance) EntranceMarker->SetRelativeLocation(GridToLocalLocation(Entrance->Coordinate) + FVector(0, 0, RoomHeight));
    if (Exit) ExitMarker->SetRelativeLocation(GridToLocalLocation(Exit->Coordinate) + FVector(0, 0, RoomHeight));
}

void AJMCustomGridMapGenerator::DrawGridDesign() const
{
    if (!GetWorld()) return;
    const FJMRoomValidationResult Validation = ValidateGridDesign();
    for (const FJMCustomGridCell& Cell : Cells)
    {
        const FVector WorldLocation = GetActorTransform().TransformPosition(GridToLocalLocation(Cell.Coordinate));
        const FColor Color = !Cell.bEnabled ? FColor(50, 50, 50)
            : Cell.bEntrance ? FColor::Green : Cell.bExit ? FColor::Blue
            : Cell.SpecialRoomDefinition.IsNull() ? FColor::Silver : FColor::Orange;
        DrawDebugBox(GetWorld(), WorldLocation + FVector(0, 0, RoomHeight * 0.5f),
            FVector(RoomCellSize * 0.48f, RoomCellSize * 0.48f, RoomHeight * 0.5f), GetActorQuat(), Color, false, 30.0f, 0, 4.0f);
        if (!Cell.bEnabled) continue;
        DrawDebugString(GetWorld(), WorldLocation + FVector(0, 0, RoomHeight + 30.0f),
            FString::Printf(TEXT("(%d,%d) %d-Way%s%s"), Cell.Coordinate.X, Cell.Coordinate.Y,
                UJMRoomGridLibrary::CountDirections(Cell.GetDirectionMask()), Cell.bEntrance ? TEXT(" Entrance") : TEXT(""), Cell.bExit ? TEXT(" Exit") : TEXT("")),
            nullptr, Color, 30.0f, true);
        for (const FDirectionStep& Step : DirectionSteps)
        {
            if (!EnumHasAnyFlags(Cell.GetDirectionMask(), Step.Direction)) continue;
            const FVector Direction = GetActorQuat().RotateVector(UJMRoomGridLibrary::DirectionVector(Step.Direction));
            DrawDebugDirectionalArrow(GetWorld(), WorldLocation, WorldLocation + Direction * (RoomCellSize * 0.35f),
                80.0f, Validation.bIsValid ? FColor::Green : FColor::Red, false, 30.0f, 0, 8.0f);
        }
    }
    ValidateGridDesignInEditor();
}

void AJMCustomGridMapGenerator::DrawGeneratedDebug() const
{
    if (!bShowDebug || !GetWorld()) return;
    for (const FJMGeneratedRoomRecord& Record : GeneratedRooms)
    {
        if (!IsValid(Record.RoomActor)) continue;
        const FVector Location = Record.RoomActor->GetActorLocation();
        FString Label;
        if (bShowCoordinates) Label += FString::Printf(TEXT("(%d,%d) "), Record.Coordinate.X, Record.Coordinate.Y);
        Label += FString::Printf(TEXT("%s %d-Way Yaw=%d"), *Record.RoomId.ToString(),
            UJMRoomGridLibrary::CountDirections(Record.OpenDirections), Record.AppliedYaw);
        DrawDebugString(GetWorld(), Location + FVector(0, 0, RoomHeight + 30.0f), Label, nullptr, FColor::White, 30.0f, true);
        if (!bShowPortDirections) continue;
        for (const FDirectionStep& Step : DirectionSteps)
        {
            if (!EnumHasAnyFlags(Record.OpenDirections, Step.Direction)) continue;
            const FVector Direction = GetActorQuat().RotateVector(UJMRoomGridLibrary::DirectionVector(Step.Direction));
            DrawDebugDirectionalArrow(GetWorld(), Location, Location + Direction * 200.0f, 30.0f, FColor::Green, false, 30.0f, 0, 3.0f);
        }
    }
}

#undef LOCTEXT_NAMESPACE
