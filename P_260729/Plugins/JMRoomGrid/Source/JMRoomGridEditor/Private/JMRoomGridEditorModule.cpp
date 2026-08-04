#include "Actors/JMRoomModule.h"
#include "Actors/JMGridMapGenerator.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Blueprint/JMRoomGridLibrary.h"
#include "Data/JMRoomDefinition.h"
#include "Engine/Blueprint.h"
#include "Engine/SCS_Node.h"
#include "Engine/SimpleConstructionScript.h"
#include "Engine/StaticMesh.h"
#include "FileHelpers.h"
#include "HAL/IConsoleManager.h"
#include "HAL/FileManager.h"
#include "JMRoomGridRuntime.h"
#include "JMRoomGridEditorTools.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Misc/MessageDialog.h"
#include "Misc/PackageName.h"
#include "Modules/ModuleManager.h"
#include "Settings/JMRoomGridSettings.h"
#include "ToolMenus.h"
#include "UObject/Package.h"
#include "UObject/SavePackage.h"

#define LOCTEXT_NAMESPACE "JMRoomGridEditor"

namespace JMRoomGridEditor
{
    const TCHAR* RoomPath = TEXT("/JMRoomGrid/Blueprints/Rooms");
    const TCHAR* DataPath = TEXT("/JMRoomGrid/Data/Rooms");
    const TCHAR* Room5x5Path = TEXT("/JMRoomGrid/Blueprints/Rooms5x5");
    const TCHAR* Data5x5Path = TEXT("/JMRoomGrid/Data/Rooms5x5");
    const TCHAR* Room13x13Path = TEXT("/JMRoomGrid/Blueprints/Rooms13x13");
    const TCHAR* Data13x13Path = TEXT("/JMRoomGrid/Data/Rooms13x13");

    void ReportValidation(const TCHAR* Label, const FJMRoomValidationResult& Result)
    {
        UE_LOG(LogJMRoomGrid, Display, TEXT("%s: %s (%d errors, %d warnings)"), Label,
            Result.bIsValid ? TEXT("VALID") : TEXT("INVALID"), Result.Errors.Num(), Result.Warnings.Num());
        for (const FText& Error : Result.Errors) UE_LOG(LogJMRoomGrid, Error, TEXT("%s"), *Error.ToString());
        for (const FText& Warning : Result.Warnings) UE_LOG(LogJMRoomGrid, Warning, TEXT("%s"), *Warning.ToString());
    }

    void AddMeshCandidates(const EJMPrototypeMeshRole Role, FJMRoomValidationResult& Result)
    {
        UE_LOG(LogJMRoomGrid, Display, TEXT("Searching Asset Registry candidates for mesh role %s."),
            *StaticEnum<EJMPrototypeMeshRole>()->GetNameStringByValue(static_cast<int64>(Role)));
        FAssetRegistryModule& Registry = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
        FARFilter Filter;
        Filter.ClassPaths.Add(UStaticMesh::StaticClass()->GetClassPathName());
        Filter.bRecursivePaths = true;
        Filter.PackagePaths.Add(TEXT("/Game"));
        const FVector Expected = Role == EJMPrototypeMeshRole::Wall ? FVector(400, 20, 500) : FVector(400, 400, 20);
        const FString ExpectedTag = FString::Printf(TEXT("%dx%dx%d"),
            FMath::RoundToInt(Expected.X), FMath::RoundToInt(Expected.Y), FMath::RoundToInt(Expected.Z));
        Filter.TagsAndValues.Add(TEXT("ApproxSize"), ExpectedTag);
        TArray<FAssetData> Assets;
        Registry.Get().GetAssets(Filter, Assets);
        UE_LOG(LogJMRoomGrid, Display, TEXT("Asset Registry returned %d exact-size candidates for role %s."), Assets.Num(),
            *StaticEnum<EJMPrototypeMeshRole>()->GetNameStringByValue(static_cast<int64>(Role)));
        TArray<FString> Candidates;
        for (const FAssetData& Asset : Assets)
        {
            Candidates.Add(Asset.GetObjectPathString());
        }
        const FString RoleName = StaticEnum<EJMPrototypeMeshRole>()->GetNameStringByValue(static_cast<int64>(Role));
        if (Candidates.Num() == 1)
        {
            Result.AddWarning(FText::FromString(FString::Printf(TEXT("%s Mesh is unset. Candidate found (not auto-selected): %s"), *RoleName, *Candidates[0])));
        }
        else if (Candidates.Num() > 1)
        {
            Result.AddWarning(FText::FromString(FString::Printf(TEXT("%s Mesh is unset. %d candidates found; choose one in Project Settings."), *RoleName, Candidates.Num())));
            for (const FString& Candidate : Candidates) UE_LOG(LogJMRoomGrid, Warning, TEXT("%s candidate: %s"), *RoleName, *Candidate);
        }
    }

    FJMRoomValidationResult ValidatePrototypeAssets()
    {
        UE_LOG(LogJMRoomGrid, Display, TEXT("Starting prototype asset validation."));
        FJMRoomValidationResult Combined;
        const UJMRoomGridSettings* Settings = GetDefault<UJMRoomGridSettings>();
        const struct { TSoftObjectPtr<UStaticMesh> Reference; EJMPrototypeMeshRole Role; } Entries[] = {
            { Settings->FloorMesh, EJMPrototypeMeshRole::Floor }, { Settings->WallMesh, EJMPrototypeMeshRole::Wall },
            { Settings->CeilingMesh, EJMPrototypeMeshRole::Ceiling }
        };
        for (const auto& Entry : Entries)
        {
            UStaticMesh* Mesh = Entry.Reference.LoadSynchronous();
            if (!Mesh)
            {
                Combined.AddError(FText::Format(LOCTEXT("MissingMesh", "{0} Mesh is not assigned in Project Settings > Plugins > JM Room Grid."),
                    StaticEnum<EJMPrototypeMeshRole>()->GetDisplayNameTextByValue(static_cast<int64>(Entry.Role))));
                AddMeshCandidates(Entry.Role, Combined);
                continue;
            }
            const FJMRoomValidationResult One = UJMRoomGridLibrary::ValidatePrototypeBounds(Mesh->GetBoundingBox(), Entry.Role, Settings->SizeTolerance, Settings->PivotTolerance);
            for (const FText& Error : One.Errors) Combined.AddError(Error);
            for (const FText& Warning : One.Warnings) Combined.AddWarning(Warning);
        }
        ReportValidation(TEXT("Prototype asset validation"), Combined);
        return Combined;
    }

    bool SaveAsset(UObject* Asset)
    {
        if (!Asset) return false;
        UPackage* Package = Asset->GetOutermost();
        Package->MarkPackageDirty();
        const FString Filename = FPackageName::LongPackageNameToFilename(Package->GetName(), FPackageName::GetAssetPackageExtension());
        IFileManager::Get().MakeDirectory(*FPaths::GetPath(Filename), true);
        FSavePackageArgs Args;
        Args.TopLevelFlags = RF_Public | RF_Standalone;
        Args.SaveFlags = SAVE_NoError;
        return UPackage::SavePackage(Package, Asset, *Filename, Args);
    }

    UBlueprint* FindBlueprint(const FString& PackagePath, const FString& AssetName)
    {
        return LoadObject<UBlueprint>(nullptr, *FString::Printf(TEXT("%s/%s.%s"), *PackagePath, *AssetName, *AssetName));
    }

    UBlueprint* CreateBlueprintAtPathIfMissing(const FString& PackagePath, const FString& AssetName, UClass* ParentClass)
    {
        if (UBlueprint* Existing = FindBlueprint(PackagePath, AssetName))
        {
            UE_LOG(LogJMRoomGrid, Display, TEXT("Protected existing Blueprint: %s"), *Existing->GetPathName());
            return Existing;
        }
        UPackage* Package = CreatePackage(*FString::Printf(TEXT("%s/%s"), *PackagePath, *AssetName));
        UBlueprint* Blueprint = FKismetEditorUtilities::CreateBlueprint(
            ParentClass, Package, *AssetName, BPTYPE_Normal, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass(), NAME_None);
        if (!Blueprint) return nullptr;
        FAssetRegistryModule::AssetCreated(Blueprint);
        FKismetEditorUtilities::CompileBlueprint(Blueprint);
        SaveAsset(Blueprint);
        UE_LOG(LogJMRoomGrid, Display, TEXT("Created Blueprint: %s"), *Blueprint->GetPathName());
        return Blueprint;
    }

    UBlueprint* CreateBlueprintIfMissing(const FString& AssetName, UClass* ParentClass)
    {
        if (UBlueprint* Existing = FindBlueprint(RoomPath, AssetName))
        {
            UE_LOG(LogJMRoomGrid, Display, TEXT("Protected existing Blueprint: %s"), *Existing->GetPathName());
            return Existing;
        }
        const FString PackageName = FString::Printf(TEXT("%s/%s"), RoomPath, *AssetName);
        UPackage* Package = CreatePackage(*PackageName);
        UBlueprint* Blueprint = FKismetEditorUtilities::CreateBlueprint(
            ParentClass, Package, *AssetName, BPTYPE_Normal, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass(), NAME_None);
        if (!Blueprint) return nullptr;
        FAssetRegistryModule::AssetCreated(Blueprint);
        FKismetEditorUtilities::CompileBlueprint(Blueprint);
        SaveAsset(Blueprint);
        UE_LOG(LogJMRoomGrid, Display, TEXT("Created Blueprint: %s"), *Blueprint->GetPathName());
        return Blueprint;
    }

    bool ConfigureRoomBlueprint(UBlueprint* Blueprint, const FName RoomId, const EJMRoomJunctionType Junction, const EJMRoomDirection Mask, const bool bSetMeshes)
    {
        if (!Blueprint || !Blueprint->GeneratedClass) return false;
        AJMRoomModule* Defaults = Cast<AJMRoomModule>(Blueprint->GeneratedClass->GetDefaultObject());
        if (!Defaults) return false;
        Defaults->Modify();
        Defaults->RoomId = RoomId;
        Defaults->JunctionType = Junction;
        Defaults->CanonicalOpenDirections = static_cast<int32>(Mask);
        if (bSetMeshes)
        {
            const UJMRoomGridSettings* Settings = GetDefault<UJMRoomGridSettings>();
            Defaults->SetPrototypeMeshes(Settings->FloorMesh.LoadSynchronous(), Settings->WallMesh.LoadSynchronous(), Settings->CeilingMesh.LoadSynchronous());
        }
        Defaults->ApplyStructureVisibility();
        Blueprint->Modify();
        const bool bSaved = SaveAsset(Blueprint);
        UE_LOG(LogJMRoomGrid, Display, TEXT("Configured room defaults: %s Junction=%d Mask=0x%02x Saved=%s"),
            *Blueprint->GetPathName(), static_cast<int32>(Junction), static_cast<uint8>(Mask), bSaved ? TEXT("true") : TEXT("false"));
        return bSaved;
    }

    UJMRoomDefinition* CreateDefinitionIfMissing(const FString& Name, const FName RoomId, UBlueprint* Blueprint,
        const EJMRoomJunctionType Junction, const EJMRoomDirection Mask)
    {
        const FString ObjectPath = FString::Printf(TEXT("%s/%s.%s"), DataPath, *Name, *Name);
        if (UJMRoomDefinition* Existing = LoadObject<UJMRoomDefinition>(nullptr, *ObjectPath))
        {
            UE_LOG(LogJMRoomGrid, Display, TEXT("Protected existing Data Asset: %s"), *Existing->GetPathName());
            return Existing;
        }
        UPackage* Package = CreatePackage(*FString::Printf(TEXT("%s/%s"), DataPath, *Name));
        UJMRoomDefinition* Definition = NewObject<UJMRoomDefinition>(Package, *Name, RF_Public | RF_Standalone | RF_Transactional);
        Definition->RoomId = RoomId;
        Definition->DisplayName = FText::FromName(RoomId);
        Definition->RoomBlueprintClass = Blueprint && Blueprint->GeneratedClass ? Blueprint->GeneratedClass : nullptr;
        Definition->JunctionType = Junction;
        Definition->CanonicalOpenDirections = static_cast<int32>(Mask);
        Definition->AllowedRotations = { 0, 90, 180, 270 };
        FAssetRegistryModule::AssetCreated(Definition);
        SaveAsset(Definition);
        UE_LOG(LogJMRoomGrid, Display, TEXT("Created Data Asset: %s"), *Definition->GetPathName());
        return Definition;
    }

    UJMRoomDefinition* Create5x5DefinitionIfMissing(const FString& Name, const FName RoomId, UBlueprint* Blueprint,
        const EJMRoomJunctionType Junction, const EJMRoomDirection Mask)
    {
        const FString ObjectPath = FString::Printf(TEXT("%s/%s.%s"), Data5x5Path, *Name, *Name);
        if (UJMRoomDefinition* Existing = LoadObject<UJMRoomDefinition>(nullptr, *ObjectPath))
        {
            UE_LOG(LogJMRoomGrid, Display, TEXT("Protected existing Data Asset: %s"), *Existing->GetPathName());
            return Existing;
        }
        UPackage* Package = CreatePackage(*FString::Printf(TEXT("%s/%s"), Data5x5Path, *Name));
        UJMRoomDefinition* Definition = NewObject<UJMRoomDefinition>(Package, *Name, RF_Public | RF_Standalone | RF_Transactional);
        Definition->RoomId = RoomId;
        Definition->DisplayName = FText::FromName(RoomId);
        Definition->RoomBlueprintClass = Blueprint && Blueprint->GeneratedClass ? Blueprint->GeneratedClass : nullptr;
        Definition->JunctionType = Junction;
        Definition->CanonicalOpenDirections = static_cast<int32>(Mask);
        Definition->AllowedRotations = { 0, 90, 180, 270 };
        FAssetRegistryModule::AssetCreated(Definition);
        SaveAsset(Definition);
        UE_LOG(LogJMRoomGrid, Display, TEXT("Created Data Asset: %s"), *Definition->GetPathName());
        return Definition;
    }

    bool Configure5x5Blueprint(UBlueprint* Blueprint, const FName RoomId, const EJMRoomJunctionType Junction,
        const EJMRoomDirection Mask, const EJMRoomLayoutVariant Variant, const bool bSetMeshes)
    {
        if (!Blueprint || !Blueprint->GeneratedClass) return false;
        AJMRoomModule* Defaults = Cast<AJMRoomModule>(Blueprint->GeneratedClass->GetDefaultObject());
        if (!Defaults) return false;
        Defaults->Modify();
        Defaults->RoomId = RoomId;
        Defaults->JunctionType = Junction;
        Defaults->CanonicalOpenDirections = static_cast<int32>(Mask);
        Defaults->bUseFiveByFiveLayout = true;
        Defaults->LayoutVariant = Variant;
        if (bSetMeshes)
        {
            const UJMRoomGridSettings* Settings = GetDefault<UJMRoomGridSettings>();
            Defaults->SetPrototypeMeshes(Settings->FloorMesh.LoadSynchronous(), Settings->WallMesh.LoadSynchronous(), Settings->CeilingMesh.LoadSynchronous());
        }
        Defaults->ApplyStructureVisibility();
        Blueprint->Modify();
        return SaveAsset(Blueprint);
    }

    JMROOMGRIDEDITOR_API bool CreateFiveByFiveRoomAssets(const bool bShowDialog)
    {
        if (!ValidatePrototypeAssets().bIsValid)
        {
            if (bShowDialog) FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("Creation5Blocked", "5x5 room creation was blocked. Assign valid Floor, Wall, and Ceiling meshes first."));
            return false;
        }
        const FString BaseName(TEXT("BP_Room5x5_Base"));
        const bool bBaseExisted = FindBlueprint(Room5x5Path, BaseName) != nullptr;
        UBlueprint* Base = CreateBlueprintAtPathIfMissing(Room5x5Path, BaseName, AJMRoomModule::StaticClass());
        if (!Base || !Base->GeneratedClass) return false;
        if (!bBaseExisted) Configure5x5Blueprint(Base, TEXT("Room5x5_Base"), EJMRoomJunctionType::FourWay,
            EJMRoomDirection::All, EJMRoomLayoutVariant::A, true);

        TArray<TSoftObjectPtr<UJMRoomDefinition>> Definitions;
        const struct FSpec { const TCHAR* Way; EJMRoomJunctionType Junction; EJMRoomDirection Mask; } Ways[] = {
            { TEXT("2Way"), EJMRoomJunctionType::TwoWay, EJMRoomDirection::North | EJMRoomDirection::East },
            { TEXT("3Way"), EJMRoomJunctionType::ThreeWay, EJMRoomDirection::North | EJMRoomDirection::East | EJMRoomDirection::West },
            { TEXT("4Way"), EJMRoomJunctionType::FourWay, EJMRoomDirection::All }
        };
        for (const FSpec& Way : Ways)
        {
            for (int32 VariantIndex = 0; VariantIndex < 4; ++VariantIndex)
            {
                const TCHAR VariantLetter = static_cast<TCHAR>('A' + VariantIndex);
                const FString AssetSuffix = FString::Printf(TEXT("%s_%c"), Way.Way, VariantLetter);
                const FString BlueprintName = TEXT("BP_Room5x5_") + AssetSuffix;
                const FString DataName = TEXT("DA_Room5x5_") + AssetSuffix;
                const FName RoomId(*FString(TEXT("Room5x5_")) + AssetSuffix);
                const bool bExisted = FindBlueprint(Room5x5Path, BlueprintName) != nullptr;
                UBlueprint* Room = CreateBlueprintAtPathIfMissing(Room5x5Path, BlueprintName, Base->GeneratedClass);
                if (Room && !bExisted) Configure5x5Blueprint(Room, RoomId, Way.Junction, Way.Mask,
                    static_cast<EJMRoomLayoutVariant>(VariantIndex), false);
                if (UJMRoomDefinition* Definition = Create5x5DefinitionIfMissing(DataName, RoomId, Room, Way.Junction, Way.Mask))
                    Definitions.Add(Definition);
            }
        }

        const FString GeneratorPath(TEXT("/JMRoomGrid/Blueprints"));
        const FString GeneratorName(TEXT("BP_GridMapGenerator5x5"));
        const bool bGeneratorExisted = FindBlueprint(GeneratorPath, GeneratorName) != nullptr;
        UBlueprint* GeneratorBP = CreateBlueprintAtPathIfMissing(GeneratorPath, GeneratorName, AJMGridMapGenerator::StaticClass());
        if (GeneratorBP && GeneratorBP->GeneratedClass && !bGeneratorExisted)
        {
            AJMGridMapGenerator* Defaults = Cast<AJMGridMapGenerator>(GeneratorBP->GeneratedClass->GetDefaultObject());
            Defaults->Modify();
            Defaults->RoomCellSize = 2000.0f;
            Defaults->RoomDefinitions = Definitions;
            GeneratorBP->Modify();
            SaveAsset(GeneratorBP);
        }
        UE_LOG(LogJMRoomGrid, Display, TEXT("5x5 room library generation complete: 12 variants, %d definitions."), Definitions.Num());
        if (bShowDialog) FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("Creation5Complete", "5x5 room library created: 12 room Blueprints, 12 Definitions, and BP_GridMapGenerator5x5."));
        return Definitions.Num() == 12;
    }

    bool Configure13x13Blueprint(UBlueprint* Blueprint, const FName RoomId, const EJMRoomJunctionType Junction,
        const EJMRoomDirection Mask, const EJMRoomLayoutVariant Variant, const bool bSetMeshes)
    {
        if (!Blueprint || !Blueprint->GeneratedClass) return false;
        AJMRoomModule* Defaults = Cast<AJMRoomModule>(Blueprint->GeneratedClass->GetDefaultObject());
        if (!Defaults) return false;
        Defaults->Modify();
        Defaults->RoomId = RoomId;
        Defaults->JunctionType = Junction;
        Defaults->CanonicalOpenDirections = static_cast<int32>(Mask);
        Defaults->bUseFiveByFiveLayout = false;
        Defaults->bUseThirteenByThirteenLayout = true;
        Defaults->bUseCustomWalkableTiles = false;
        Defaults->LayoutVariant = Variant;
        TArray<FIntPoint> EditableTiles;
        for (int32 Y = 0; Y < 13; ++Y)
            for (int32 X = 0; X < 13; ++X)
                if (Defaults->IsTileWalkable(X, Y)) EditableTiles.Add(FIntPoint(X, Y));
        Defaults->CustomWalkableTiles = MoveTemp(EditableTiles);
        Defaults->bUseCustomWalkableTiles = true;
        if (bSetMeshes)
        {
            const UJMRoomGridSettings* Settings = GetDefault<UJMRoomGridSettings>();
            Defaults->SetPrototypeMeshes(Settings->FloorMesh.LoadSynchronous(), Settings->WallMesh.LoadSynchronous(), Settings->CeilingMesh.LoadSynchronous());
        }
        Defaults->ApplyStructureVisibility();
        Blueprint->Modify();
        return SaveAsset(Blueprint);
    }

    bool EnsureEditable13x13Structure(UBlueprint* Blueprint)
    {
        if (!Blueprint || !Blueprint->GeneratedClass || !Blueprint->SimpleConstructionScript) return false;
        // Version 3 rebuilds the generated mesh nodes as Movable. Room modules are
        // spawned and attached to a movable generator, so Static children cannot
        // attach to the native StructureRoot and would remain piled up at origin.
        constexpr int32 DesiredStructureVersion = 3;
        AJMRoomModule* Defaults = Cast<AJMRoomModule>(Blueprint->GeneratedClass->GetDefaultObject());
        if (!Defaults) return false;
        TArray<USCS_Node*> ExistingGeneratedNodes;
        for (USCS_Node* Node : Blueprint->SimpleConstructionScript->GetAllNodes())
        {
            if (Node && Node->GetVariableName().ToString().StartsWith(TEXT("JMGen_")))
                ExistingGeneratedNodes.Add(Node);
        }
        if (!ExistingGeneratedNodes.IsEmpty() && Defaults->GeneratedEditableStructureVersion >= DesiredStructureVersion)
        {
            UE_LOG(LogJMRoomGrid, Display, TEXT("Protected current editable room components: %s"), *Blueprint->GetPathName());
            return true;
        }
        for (USCS_Node* Node : ExistingGeneratedNodes)
        {
            Blueprint->SimpleConstructionScript->RemoveNode(Node);
        }
        const UJMRoomGridSettings* Settings = GetDefault<UJMRoomGridSettings>();
        UStaticMesh* FloorMesh = Settings->FloorMesh.LoadSynchronous();
        UStaticMesh* WallMesh = Settings->WallMesh.LoadSynchronous();
        UStaticMesh* CeilingMesh = Settings->CeilingMesh.LoadSynchronous();
        if (!FloorMesh || !WallMesh || !CeilingMesh) return false;

        Blueprint->Modify();
        Defaults->Modify();
        Defaults->bUseAutomatic13x13Structure = false;
        Defaults->bUseCustomWalkableTiles = false;
        TArray<FIntPoint> DesignedTiles;
        for (int32 Y = 0; Y < 13; ++Y)
            for (int32 X = 0; X < 13; ++X)
                if (Defaults->IsTileWalkable(X, Y)) DesignedTiles.Add(FIntPoint(X, Y));
        Defaults->CustomWalkableTiles = MoveTemp(DesignedTiles);
        Defaults->bUseCustomWalkableTiles = true;
        const auto AddMeshNode = [Blueprint](const FString& Name, UStaticMesh* Mesh, const FVector& Location, const FRotator& Rotation)
        {
            USCS_Node* Node = Blueprint->SimpleConstructionScript->CreateNode(UStaticMeshComponent::StaticClass(), FName(*Name));
            UStaticMeshComponent* Template = CastChecked<UStaticMeshComponent>(Node->ComponentTemplate);
            Template->SetStaticMesh(Mesh);
            Template->SetRelativeLocation(Location);
            Template->SetRelativeRotation(Rotation);
            Template->SetMobility(EComponentMobility::Movable);
            Template->ComponentTags.AddUnique(TEXT("JMRoomGrid.EditableGenerated"));
            Node->bIsParentComponentNative = true;
            Node->ParentComponentOrVariableName = GET_MEMBER_NAME_CHECKED(AJMRoomModule, StructureRoot);
            Blueprint->SimpleConstructionScript->AddNode(Node);
        };

        int32 FloorCount = 0, CeilingCount = 0, WallCount = 0;
        for (int32 Y = 0; Y < 13; ++Y)
        {
            for (int32 X = 0; X < 13; ++X)
            {
                if (!Defaults->IsTileWalkable(X, Y)) continue;
                const FVector Location((X - 6) * 400.0, (Y - 6) * 400.0, 0);
                AddMeshNode(FString::Printf(TEXT("JMGen_Floor_%02d_%02d"), X, Y), FloorMesh, Location, FRotator::ZeroRotator);
                AddMeshNode(FString::Printf(TEXT("JMGen_Ceiling_%02d_%02d"), X, Y), CeilingMesh, Location + FVector(0, 0, 500), FRotator::ZeroRotator);
                ++FloorCount;
                ++CeilingCount;
            }
        }
        const auto IsOpen = [Defaults](const EJMRoomDirection Direction)
        {
            return (Defaults->CanonicalOpenDirections & static_cast<int32>(Direction)) != 0;
        };
        for (int32 EdgeY = 0; EdgeY <= 13; ++EdgeY)
        {
            for (int32 X = 0; X < 13; ++X)
            {
                const bool Below = EdgeY > 0 && Defaults->IsTileWalkable(X, EdgeY - 1);
                const bool Above = EdgeY < 13 && Defaults->IsTileWalkable(X, EdgeY);
                bool bWall = Below != Above;
                if (X == 6 && ((EdgeY == 0 && IsOpen(EJMRoomDirection::South)) || (EdgeY == 13 && IsOpen(EJMRoomDirection::North)))) bWall = false;
                if (!bWall) continue;
                AddMeshNode(FString::Printf(TEXT("JMGen_WallH_%02d_%02d"), X, EdgeY), WallMesh,
                    FVector((X - 6) * 400.0, (EdgeY - 6.5) * 400.0, 0), FRotator::ZeroRotator);
                ++WallCount;
            }
        }
        for (int32 Y = 0; Y < 13; ++Y)
        {
            for (int32 EdgeX = 0; EdgeX <= 13; ++EdgeX)
            {
                const bool Left = EdgeX > 0 && Defaults->IsTileWalkable(EdgeX - 1, Y);
                const bool Right = EdgeX < 13 && Defaults->IsTileWalkable(EdgeX, Y);
                bool bWall = Left != Right;
                if (Y == 6 && ((EdgeX == 0 && IsOpen(EJMRoomDirection::West)) || (EdgeX == 13 && IsOpen(EJMRoomDirection::East)))) bWall = false;
                if (!bWall) continue;
                AddMeshNode(FString::Printf(TEXT("JMGen_WallV_%02d_%02d"), EdgeX, Y), WallMesh,
                    FVector((EdgeX - 6.5) * 400.0, (Y - 6) * 400.0, 0), FRotator(0, 90, 0));
                ++WallCount;
            }
        }
        FKismetEditorUtilities::CompileBlueprint(Blueprint);
        if (AJMRoomModule* NewDefaults = Cast<AJMRoomModule>(Blueprint->GeneratedClass->GetDefaultObject()))
        {
            NewDefaults->Modify();
            NewDefaults->bUseAutomatic13x13Structure = false;
            NewDefaults->GeneratedEditableStructureVersion = DesiredStructureVersion;
        }
        const bool bSaved = SaveAsset(Blueprint);
        UE_LOG(LogJMRoomGrid, Display, TEXT("Created editable components: %s Floors=%d Ceilings=%d Walls=%d Saved=%s"),
            *Blueprint->GetPathName(), FloorCount, CeilingCount, WallCount, bSaved ? TEXT("true") : TEXT("false"));
        return bSaved;
    }

    UJMRoomDefinition* Create13x13DefinitionIfMissing(const FString& Name, const FName RoomId, UBlueprint* Blueprint,
        const EJMRoomJunctionType Junction, const EJMRoomDirection Mask)
    {
        const FString ObjectPath = FString::Printf(TEXT("%s/%s.%s"), Data13x13Path, *Name, *Name);
        if (UJMRoomDefinition* Existing = LoadObject<UJMRoomDefinition>(nullptr, *ObjectPath))
        {
            UE_LOG(LogJMRoomGrid, Display, TEXT("Protected existing Data Asset: %s"), *Existing->GetPathName());
            return Existing;
        }
        UPackage* Package = CreatePackage(*FString::Printf(TEXT("%s/%s"), Data13x13Path, *Name));
        UJMRoomDefinition* Definition = NewObject<UJMRoomDefinition>(Package, *Name, RF_Public | RF_Standalone | RF_Transactional);
        Definition->RoomId = RoomId;
        Definition->DisplayName = FText::FromName(RoomId);
        Definition->RoomBlueprintClass = Blueprint && Blueprint->GeneratedClass ? Blueprint->GeneratedClass : nullptr;
        Definition->JunctionType = Junction;
        Definition->CanonicalOpenDirections = static_cast<int32>(Mask);
        Definition->AllowedRotations = { 0, 90, 180, 270 };
        FAssetRegistryModule::AssetCreated(Definition);
        SaveAsset(Definition);
        return Definition;
    }

    JMROOMGRIDEDITOR_API bool CreateThirteenByThirteenRoomAssets(const bool bShowDialog)
    {
        if (!ValidatePrototypeAssets().bIsValid)
        {
            if (bShowDialog) FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("Creation13Blocked", "13x13 room creation was blocked. Assign valid Floor, Wall, and Ceiling meshes first."));
            return false;
        }
        const FString BaseName(TEXT("BP_Room13x13_Base"));
        const bool bBaseExisted = FindBlueprint(Room13x13Path, BaseName) != nullptr;
        UBlueprint* Base = CreateBlueprintAtPathIfMissing(Room13x13Path, BaseName, AJMRoomModule::StaticClass());
        if (!Base || !Base->GeneratedClass) return false;
        if (!bBaseExisted) Configure13x13Blueprint(Base, TEXT("Room13x13_Base"), EJMRoomJunctionType::FourWay,
            EJMRoomDirection::All, EJMRoomLayoutVariant::A, true);

        TArray<TSoftObjectPtr<UJMRoomDefinition>> Definitions;
        const struct FSpec { const TCHAR* Way; EJMRoomJunctionType Junction; EJMRoomDirection Mask; } Ways[] = {
            { TEXT("2Way"), EJMRoomJunctionType::TwoWay, EJMRoomDirection::North | EJMRoomDirection::East },
            { TEXT("3Way"), EJMRoomJunctionType::ThreeWay, EJMRoomDirection::North | EJMRoomDirection::East | EJMRoomDirection::West },
            { TEXT("4Way"), EJMRoomJunctionType::FourWay, EJMRoomDirection::All }
        };
        for (const FSpec& Way : Ways)
        {
            for (int32 VariantIndex = 0; VariantIndex < 4; ++VariantIndex)
            {
                const TCHAR Letter = static_cast<TCHAR>('A' + VariantIndex);
                const FString Suffix = FString::Printf(TEXT("%s_%c"), Way.Way, Letter);
                const FString BlueprintName = TEXT("BP_Room13x13_") + Suffix;
                const FString DataName = TEXT("DA_Room13x13_") + Suffix;
                const FName RoomId(*FString(TEXT("Room13x13_")) + Suffix);
                const bool bExisted = FindBlueprint(Room13x13Path, BlueprintName) != nullptr;
                UBlueprint* Room = CreateBlueprintAtPathIfMissing(Room13x13Path, BlueprintName, Base->GeneratedClass);
                const AJMRoomModule* CurrentDefaults = Room && Room->GeneratedClass
                    ? Cast<AJMRoomModule>(Room->GeneratedClass->GetDefaultObject()) : nullptr;
                if (Room && (!bExisted || !CurrentDefaults || CurrentDefaults->CustomWalkableTiles.IsEmpty()))
                    Configure13x13Blueprint(Room, RoomId, Way.Junction, Way.Mask,
                        static_cast<EJMRoomLayoutVariant>(VariantIndex), false);
                if (Room) EnsureEditable13x13Structure(Room);
                if (UJMRoomDefinition* Definition = Create13x13DefinitionIfMissing(DataName, RoomId, Room, Way.Junction, Way.Mask)) Definitions.Add(Definition);
            }
        }

        const FString GeneratorPath(TEXT("/JMRoomGrid/Blueprints"));
        const FString GeneratorName(TEXT("BP_GridMapGenerator13x13"));
        const bool bGeneratorExisted = FindBlueprint(GeneratorPath, GeneratorName) != nullptr;
        UBlueprint* GeneratorBP = CreateBlueprintAtPathIfMissing(GeneratorPath, GeneratorName, AJMGridMapGenerator::StaticClass());
        if (GeneratorBP && GeneratorBP->GeneratedClass && !bGeneratorExisted)
        {
            AJMGridMapGenerator* Defaults = Cast<AJMGridMapGenerator>(GeneratorBP->GeneratedClass->GetDefaultObject());
            Defaults->Modify();
            Defaults->RoomCellSize = 5200.0f;
            Defaults->RoomDefinitions = Definitions;
            Defaults->bHideCeilingsForPreview = true;
            GeneratorBP->Modify();
            SaveAsset(GeneratorBP);
        }
        UE_LOG(LogJMRoomGrid, Display, TEXT("13x13 editable room library generation complete: 12 variants, %d definitions."), Definitions.Num());
        if (bShowDialog) FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("Creation13Complete", "13x13 editable room library created: 12 room Blueprints, 12 Definitions, and BP_GridMapGenerator13x13."));
        return Definitions.Num() == 12;
    }

    void CreateMissingRoomAssets()
    {
        if (!ValidatePrototypeAssets().bIsValid)
        {
            FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("CreationBlocked", "Room asset creation was blocked. Assign valid Floor, Wall, and Ceiling meshes in Project Settings, then run validation again."));
            return;
        }
        const bool bBaseExisted = FindBlueprint(RoomPath, TEXT("BP_RoomModuleBase")) != nullptr;
        UBlueprint* Base = CreateBlueprintIfMissing(TEXT("BP_RoomModuleBase"), AJMRoomModule::StaticClass());
        if (!Base || !Base->GeneratedClass) return;
        if (!bBaseExisted) ConfigureRoomBlueprint(Base, TEXT("RoomModuleBase"), EJMRoomJunctionType::FourWay, EJMRoomDirection::All, true);

        struct FSpec { const TCHAR* Blueprint; const TCHAR* Data; FName Id; EJMRoomJunctionType Junction; EJMRoomDirection Mask; };
        const FSpec Specs[] = {
            { TEXT("BP_Room_4Way_A"), TEXT("DA_Room_4Way_A"), TEXT("Room_4Way_A"), EJMRoomJunctionType::FourWay, EJMRoomDirection::All },
            { TEXT("BP_Room_3Way_A"), TEXT("DA_Room_3Way_A"), TEXT("Room_3Way_A"), EJMRoomJunctionType::ThreeWay, EJMRoomDirection::North | EJMRoomDirection::East | EJMRoomDirection::West },
            { TEXT("BP_Room_2Way_Corner_A"), TEXT("DA_Room_2Way_Corner_A"), TEXT("Room_2Way_Corner_A"), EJMRoomJunctionType::TwoWay, EJMRoomDirection::North | EJMRoomDirection::East }
        };
        for (const FSpec& Spec : Specs)
        {
            const bool bExisted = FindBlueprint(RoomPath, Spec.Blueprint) != nullptr;
            UBlueprint* Room = CreateBlueprintIfMissing(Spec.Blueprint, Base->GeneratedClass);
            if (Room && !bExisted) ConfigureRoomBlueprint(Room, Spec.Id, Spec.Junction, Spec.Mask, false);
            CreateDefinitionIfMissing(Spec.Data, Spec.Id, Room, Spec.Junction, Spec.Mask);
        }
        FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("CreationComplete", "Create-missing-only room asset generation completed. Existing assets were preserved; see Output Log for details."));
    }

    void RepairRoomContractDefaults()
    {
        const EAppReturnType::Type Response = FMessageDialog::Open(
            EAppMsgType::YesNo,
            LOCTEXT("RepairConfirmation",
                "Repair the generated Blueprint and Room Definition contract fields (Room ID, Blueprint Class, Junction Type, Canonical Open Directions, and wall visibility)?\n\n"
                "Blueprint components, user content, selection weights, tags, counts, and Danger Score will be preserved."));
        if (Response != EAppReturnType::Yes) return;

        struct FRepairSpec { const TCHAR* Blueprint; const TCHAR* Data; FName Id; EJMRoomJunctionType Junction; EJMRoomDirection Mask; };
        const FRepairSpec Specs[] = {
            { TEXT("BP_Room_4Way_A"), TEXT("DA_Room_4Way_A"), TEXT("Room_4Way_A"), EJMRoomJunctionType::FourWay, EJMRoomDirection::All },
            { TEXT("BP_Room_3Way_A"), TEXT("DA_Room_3Way_A"), TEXT("Room_3Way_A"), EJMRoomJunctionType::ThreeWay, EJMRoomDirection::North | EJMRoomDirection::East | EJMRoomDirection::West },
            { TEXT("BP_Room_2Way_Corner_A"), TEXT("DA_Room_2Way_Corner_A"), TEXT("Room_2Way_Corner_A"), EJMRoomJunctionType::TwoWay, EJMRoomDirection::North | EJMRoomDirection::East }
        };

        bool bAllSucceeded = true;
        for (const FRepairSpec& Spec : Specs)
        {
            UBlueprint* Blueprint = FindBlueprint(RoomPath, Spec.Blueprint);
            if (!Blueprint)
            {
                UE_LOG(LogJMRoomGrid, Error, TEXT("Cannot repair missing Blueprint: %s/%s"), RoomPath, Spec.Blueprint);
                bAllSucceeded = false;
                continue;
            }
            // Refresh the generated class first (especially after native property type changes),
            // then write the contract to the new CDO and save without compiling it away again.
            FKismetEditorUtilities::CompileBlueprint(Blueprint);
            if (Blueprint->Status == BS_Error)
            {
                UE_LOG(LogJMRoomGrid, Error, TEXT("Cannot repair Blueprint with compile errors: %s"), *Blueprint->GetPathName());
                bAllSucceeded = false;
                continue;
            }
            bAllSucceeded &= ConfigureRoomBlueprint(Blueprint, Spec.Id, Spec.Junction, Spec.Mask, false);

            const FString DefinitionPath = FString::Printf(TEXT("%s/%s.%s"), DataPath, Spec.Data, Spec.Data);
            UJMRoomDefinition* Definition = LoadObject<UJMRoomDefinition>(nullptr, *DefinitionPath);
            if (!Definition)
            {
                UE_LOG(LogJMRoomGrid, Error, TEXT("Cannot repair missing Room Definition: %s"), *DefinitionPath);
                bAllSucceeded = false;
                continue;
            }
            Definition->Modify();
            Definition->RoomId = Spec.Id;
            Definition->RoomBlueprintClass = Blueprint->GeneratedClass;
            Definition->JunctionType = Spec.Junction;
            Definition->CanonicalOpenDirections = static_cast<int32>(Spec.Mask);
            Definition->AllowedRotations = { 0, 90, 180, 270 };
            const bool bDefinitionSaved = SaveAsset(Definition);
            bAllSucceeded &= bDefinitionSaved;
            UE_LOG(LogJMRoomGrid, Display, TEXT("Configured Room Definition contract: %s Junction=%d Mask=0x%02x Saved=%s"),
                *Definition->GetPathName(), static_cast<int32>(Spec.Junction), static_cast<uint8>(Spec.Mask),
                bDefinitionSaved ? TEXT("true") : TEXT("false"));
        }

        FMessageDialog::Open(EAppMsgType::Ok,
            bAllSucceeded
                ? LOCTEXT("RepairComplete", "Blueprint and Room Definition contract fields were repaired. Run Validate Room Blueprints next.")
                : LOCTEXT("RepairFailed", "One or more room contract defaults could not be repaired. See Output Log."));
    }

    void ValidateRoomBlueprints()
    {
        FJMRoomValidationResult Combined;
        for (const TCHAR* Name : { TEXT("BP_RoomModuleBase"), TEXT("BP_Room_4Way_A"), TEXT("BP_Room_3Way_A"), TEXT("BP_Room_2Way_Corner_A") })
        {
            UBlueprint* Blueprint = FindBlueprint(RoomPath, Name);
            if (!Blueprint || !Blueprint->GeneratedClass)
            {
                Combined.AddError(FText::FromString(FString::Printf(TEXT("Missing Blueprint: %s/%s"), RoomPath, Name)));
                continue;
            }
            const AJMRoomModule* Defaults = Cast<AJMRoomModule>(Blueprint->GeneratedClass->GetDefaultObject());
            if (!Defaults) { Combined.AddError(FText::FromString(FString::Printf(TEXT("Invalid room Blueprint: %s"), Name))); continue; }
            const FJMRoomValidationResult One = Defaults->ValidateRoomContract();
            for (const FText& Error : One.Errors) Combined.AddError(FText::FromString(FString::Printf(TEXT("%s: %s"), Name, *Error.ToString())));
        }
        const struct { const TCHAR* Data; const TCHAR* Blueprint; EJMRoomJunctionType Junction; EJMRoomDirection Mask; } Definitions[] = {
            { TEXT("DA_Room_4Way_A"), TEXT("BP_Room_4Way_A"), EJMRoomJunctionType::FourWay, EJMRoomDirection::All },
            { TEXT("DA_Room_3Way_A"), TEXT("BP_Room_3Way_A"), EJMRoomJunctionType::ThreeWay, EJMRoomDirection::North | EJMRoomDirection::East | EJMRoomDirection::West },
            { TEXT("DA_Room_2Way_Corner_A"), TEXT("BP_Room_2Way_Corner_A"), EJMRoomJunctionType::TwoWay, EJMRoomDirection::North | EJMRoomDirection::East }
        };
        for (const auto& Spec : Definitions)
        {
            const FString ObjectPath = FString::Printf(TEXT("%s/%s.%s"), DataPath, Spec.Data, Spec.Data);
            const UJMRoomDefinition* Definition = LoadObject<UJMRoomDefinition>(nullptr, *ObjectPath);
            const UBlueprint* Blueprint = FindBlueprint(RoomPath, Spec.Blueprint);
            if (!Definition)
            {
                Combined.AddError(FText::FromString(FString::Printf(TEXT("Missing Room Definition: %s"), *ObjectPath)));
                continue;
            }
            if (Definition->JunctionType != Spec.Junction || Definition->CanonicalOpenDirections != static_cast<int32>(Spec.Mask))
                Combined.AddError(FText::FromString(FString::Printf(TEXT("Room Definition contract mismatch: %s"), Spec.Data)));
            for (const int32 RequiredRotation : { 0, 90, 180, 270 })
            {
                if (!Definition->AllowedRotations.Contains(RequiredRotation))
                    Combined.AddError(FText::FromString(FString::Printf(TEXT("Room Definition is missing allowed rotation %d: %s"), RequiredRotation, Spec.Data)));
            }
            if (!Blueprint || Definition->RoomBlueprintClass.ToSoftObjectPath() != FSoftObjectPath(Blueprint->GeneratedClass))
                Combined.AddError(FText::FromString(FString::Printf(TEXT("Room Definition references the wrong Blueprint class: %s"), Spec.Data)));
        }
        ReportValidation(TEXT("Room Blueprint validation"), Combined);
        FMessageDialog::Open(EAppMsgType::Ok, Combined.bIsValid ? LOCTEXT("RoomsValid", "Room Blueprints are valid. See Output Log for details.") : LOCTEXT("RoomsInvalid", "Room Blueprint validation failed. See Output Log for details."));
    }

    static FAutoConsoleCommand ValidateAssetsCommand(
        TEXT("JMRoomGrid.ValidatePrototypeAssets"),
        TEXT("Validate JM Room Grid prototype mesh settings and bounds."),
        FConsoleCommandDelegate::CreateLambda([] { ValidatePrototypeAssets(); }));

    static FAutoConsoleCommand CreateAssetsCommand(
        TEXT("JMRoomGrid.CreateMissingRoomAssets"),
        TEXT("Create missing-only JM Room Grid Blueprints and Room Definitions."),
        FConsoleCommandDelegate::CreateLambda([] { CreateMissingRoomAssets(); }));

    static FAutoConsoleCommand ValidateRoomsCommand(
        TEXT("JMRoomGrid.ValidateRoomBlueprints"),
        TEXT("Validate generated JM Room Grid Blueprints and Room Definitions."),
        FConsoleCommandDelegate::CreateLambda([] { ValidateRoomBlueprints(); }));

    static FAutoConsoleCommand RepairRoomsCommand(
        TEXT("JMRoomGrid.RepairRoomContractDefaults"),
        TEXT("Repair only generated room contract defaults while preserving user-authored components."),
        FConsoleCommandDelegate::CreateLambda([] { RepairRoomContractDefaults(); }));

    static FAutoConsoleCommand Create5x5AssetsCommand(
        TEXT("JMRoomGrid.Create5x5Assets"),
        TEXT("Create the 12-variant 5x5 room library without modal UI."),
        FConsoleCommandDelegate::CreateLambda([] { CreateFiveByFiveRoomAssets(false); }));

    static FAutoConsoleCommand Create13x13AssetsCommand(
        TEXT("JMRoomGrid.Create13x13Assets"),
        TEXT("Create the 12-variant editable 13x13 room library without modal UI."),
        FConsoleCommandDelegate::CreateLambda([] { CreateThirteenByThirteenRoomAssets(false); }));
}

class FJMRoomGridEditorModule final : public IModuleInterface
{
public:
    virtual void StartupModule() override
    {
        UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FJMRoomGridEditorModule::RegisterMenus));
    }

    virtual void ShutdownModule() override
    {
        UToolMenus::UnRegisterStartupCallback(this);
        UToolMenus::UnregisterOwner(this);
    }

private:
    void RegisterMenus()
    {
        FToolMenuOwnerScoped Owner(this);
        UToolMenu* Menu = UToolMenus::Get()->ExtendMenu(TEXT("LevelEditor.MainMenu.Tools"));
        FToolMenuSection& Section = Menu->FindOrAddSection(TEXT("JMRoomGrid"), LOCTEXT("MenuSection", "JM Room Grid"));
        Section.AddMenuEntry(TEXT("JMRoomGrid.ValidateAssets"), LOCTEXT("ValidateAssets", "Validate Prototype Assets"),
            LOCTEXT("ValidateAssetsTip", "Validate assigned prototype meshes and list dimension-matching candidates without selecting them."), FSlateIcon(),
            FUIAction(FExecuteAction::CreateLambda([] { JMRoomGridEditor::ValidatePrototypeAssets(); })));
        Section.AddMenuEntry(TEXT("JMRoomGrid.CreateAssets"), LOCTEXT("CreateAssets", "Create Missing Room Blueprints"),
            LOCTEXT("CreateAssetsTip", "Create missing room Blueprints and Room Definitions. Existing assets are never overwritten."), FSlateIcon(),
            FUIAction(FExecuteAction::CreateLambda([] { JMRoomGridEditor::CreateMissingRoomAssets(); })));
        Section.AddMenuEntry(TEXT("JMRoomGrid.RepairDefaults"), LOCTEXT("RepairDefaults", "Repair Room Contract Defaults"),
            LOCTEXT("RepairDefaultsTip", "Repair Blueprint and Room Definition contract fields. User components, weights, tags, and balance data are preserved."), FSlateIcon(),
            FUIAction(FExecuteAction::CreateLambda([] { JMRoomGridEditor::RepairRoomContractDefaults(); })));
        Section.AddMenuEntry(TEXT("JMRoomGrid.ValidateRooms"), LOCTEXT("ValidateRooms", "Validate Room Blueprints"),
            LOCTEXT("ValidateRoomsTip", "Validate the component, placement, scale, direction and junction contracts."), FSlateIcon(),
            FUIAction(FExecuteAction::CreateLambda([] { JMRoomGridEditor::ValidateRoomBlueprints(); })));
        Section.AddMenuEntry(TEXT("JMRoomGrid.Create5x5Assets"), LOCTEXT("Create5x5Assets", "Create 5x5 Room Library (12 Variants)"),
            LOCTEXT("Create5x5AssetsTip", "Create four 2-way, four 3-way, and four 4-way 5x5-tile room Blueprints plus a ready generator Blueprint."), FSlateIcon(),
            FUIAction(FExecuteAction::CreateLambda([] { JMRoomGridEditor::CreateFiveByFiveRoomAssets(true); })));
        Section.AddMenuEntry(TEXT("JMRoomGrid.Create13x13Assets"), LOCTEXT("Create13x13Assets", "Create Editable 13x13 Room Library (12 Variants)"),
            LOCTEXT("Create13x13AssetsTip", "Create editable 13x13-tile room Blueprints and a ready 5x5-room map generator."), FSlateIcon(),
            FUIAction(FExecuteAction::CreateLambda([] { JMRoomGridEditor::CreateThirteenByThirteenRoomAssets(true); })));
    }
};

IMPLEMENT_MODULE(FJMRoomGridEditorModule, JMRoomGridEditor)

#undef LOCTEXT_NAMESPACE
