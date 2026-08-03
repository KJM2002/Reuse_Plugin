#include "Commandlets/JMDoorGenerateSamplesCommandlet.h"

#include "Actors/JMDoorActor.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Components/StaticMeshComponent.h"
#include "Data/JMDoorConfigData.h"
#include "Door/JMDoorComponent.h"
#include "Door/JMDoorTags.h"
#include "Editor.h"
#include "Engine/Blueprint.h"
#include "Engine/StaticMesh.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/World.h"
#include "FileHelpers.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Misc/PackageName.h"
#include "Movement/JMSlidingDoorMovementComponent.h"
#include "Tests/JMDoorFunctionalTest.h"
#include "UObject/Package.h"
#include "UObject/SavePackage.h"

namespace
{
    UPackage* LoadOrCreateAssetPackage(const FString& PackageName)
    {
        if (UPackage* ExistingPackage = FindPackage(nullptr, *PackageName))
        {
            return ExistingPackage;
        }
        if (UPackage* LoadedPackage = LoadPackage(nullptr, *PackageName, LOAD_None))
        {
            return LoadedPackage;
        }
        return CreatePackage(*PackageName);
    }

    bool SaveAssetPackage(UPackage* Package, UObject* Asset)
    {
        if (!Package || !Asset)
        {
            return false;
        }
        Package->MarkPackageDirty();
        const FString Filename = FPackageName::LongPackageNameToFilename(Package->GetName(), FPackageName::GetAssetPackageExtension());
        FSavePackageArgs SaveArgs;
        SaveArgs.TopLevelFlags = RF_Public | RF_Standalone;
        SaveArgs.SaveFlags = SAVE_NoError;
        return UPackage::SavePackage(Package, Asset, *Filename, SaveArgs);
    }

    UJMDoorConfigData* CreateDoorConfig()
    {
        const FString PackageName = TEXT("/JMDoor/Demo/Data/DA_JMDoorDemoConfig");
        UPackage* Package = LoadOrCreateAssetPackage(PackageName);
        UJMDoorConfigData* Config = FindObject<UJMDoorConfigData>(Package, TEXT("DA_JMDoorDemoConfig"));
        if (!Config)
        {
            Config = NewObject<UJMDoorConfigData>(Package, TEXT("DA_JMDoorDemoConfig"), RF_Public | RF_Standalone);
            FAssetRegistryModule::AssetCreated(Config);
        }
        Config->OpenDuration = 1.0f;
        Config->CloseDuration = 1.0f;
        Config->OpenDirectionMode = EJMDoorOpenDirectionMode::AwayFromInteractor;
        Config->bAutoClose = true;
        Config->AutoCloseDelay = 3.0f;
        Config->BlockBehavior = EJMDoorBlockBehavior::Reverse;
        Config->bInitiallyLocked = false;
        Config->AccessRequirement.RequiredTags.Reset();
        Config->AcceptedAccessObjects.Reset();
        return SaveAssetPackage(Package, Config) ? Config : nullptr;
    }

    UJMDoorConfigData* CreateLockedDoorConfig()
    {
        const FString PackageName = TEXT("/JMDoor/Demo/Data/DA_JMDoorDemoLockedConfig");
        UPackage* Package = LoadOrCreateAssetPackage(PackageName);
        UJMDoorConfigData* Config = FindObject<UJMDoorConfigData>(Package, TEXT("DA_JMDoorDemoLockedConfig"));
        if (!Config)
        {
            Config = NewObject<UJMDoorConfigData>(Package, TEXT("DA_JMDoorDemoLockedConfig"), RF_Public | RF_Standalone);
            FAssetRegistryModule::AssetCreated(Config);
        }
        Config->OpenDuration = 1.0f;
        Config->CloseDuration = 1.0f;
        Config->OpenDirectionMode = EJMDoorOpenDirectionMode::AwayFromInteractor;
        Config->bAutoClose = false;
        Config->bInitiallyLocked = true;
        Config->AccessRequirement.RequiredTags.Reset();
        Config->AccessRequirement.RequiredTags.AddTag(TAG_JMDoor_Demo_Key);
        Config->AccessRequirement.MatchMode = EJMDoorAccessMatchMode::AllRequired;
        // Item consumption is owned by InventorySystem's Item Definition.
        Config->AccessRequirement.bConsumeAccess = false;
        return SaveAssetPackage(Package, Config) ? Config : nullptr;
    }

    UBlueprint* CreateDoorBlueprint(const FString& PackageName, const FName AssetName, UClass* ParentClass, UJMDoorConfigData* Config, UStaticMesh* CubeMesh, bool bRotating)
    {
        UPackage* Package = LoadOrCreateAssetPackage(PackageName);
        UBlueprint* Blueprint = FindObject<UBlueprint>(Package, AssetName.ToString());
        if (!Blueprint)
        {
            Blueprint = FKismetEditorUtilities::CreateBlueprint(ParentClass, Package, AssetName, BPTYPE_Normal, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass());
            FAssetRegistryModule::AssetCreated(Blueprint);
        }
        FKismetEditorUtilities::CompileBlueprint(Blueprint);
        AJMDoorActor* DoorCDO = Blueprint && Blueprint->GeneratedClass ? Cast<AJMDoorActor>(Blueprint->GeneratedClass->GetDefaultObject()) : nullptr;
        if (DoorCDO)
        {
            DoorCDO->DoorComponent->Config = Config;
            DoorCDO->DoorLeafMesh->SetStaticMesh(CubeMesh);
            DoorCDO->DoorLeafMesh->SetRelativeScale3D(bRotating ? FVector(0.12f, 1.0f, 2.0f) : FVector(0.12f, 1.5f, 2.0f));
            DoorCDO->DoorLeafMesh->SetRelativeLocation(bRotating ? FVector(0.0f, 50.0f, 100.0f) : FVector(0.0f, 0.0f, 100.0f));
            if (AJMSlidingDoorActor* SlidingDoorCDO = Cast<AJMSlidingDoorActor>(DoorCDO))
            {
                SlidingDoorCDO->DoorLeafMesh->SetRelativeLocation(FVector(0.0f, -75.0f, 100.0f));
                SlidingDoorCDO->DoorLeafMeshB->SetStaticMesh(CubeMesh);
                SlidingDoorCDO->DoorLeafMeshB->SetRelativeScale3D(FVector(0.12f, 0.75f, 2.0f));
                SlidingDoorCDO->DoorLeafMeshB->SetRelativeLocation(FVector(0.0f, 75.0f, 100.0f));
                SlidingDoorCDO->SlidingMovement->DoorAOpenOffset = FVector(0.0f, -150.0f, 0.0f);
                SlidingDoorCDO->SlidingMovement->DoorBOpenOffset = FVector(0.0f, 150.0f, 0.0f);
            }
        }
        return SaveAssetPackage(Package, Blueprint) ? Blueprint : nullptr;
    }

    bool CreateDemoMap(UBlueprint* RotatingBlueprint, UBlueprint* SlidingBlueprint, UBlueprint* LockedBlueprint, UStaticMesh* CubeMesh)
    {
        UWorld* World = UEditorLoadingAndSavingUtils::NewBlankMap(false);
        if (!World || !RotatingBlueprint || !SlidingBlueprint || !LockedBlueprint)
        {
            return false;
        }
        World->SpawnActor<AActor>(RotatingBlueprint->GeneratedClass, FVector(0.0f, -300.0f, 0.0f), FRotator::ZeroRotator);
        World->SpawnActor<AActor>(SlidingBlueprint->GeneratedClass, FVector(350.0f, -300.0f, 0.0f), FRotator::ZeroRotator);
        World->SpawnActor<AActor>(LockedBlueprint->GeneratedClass, FVector(250.0f, 0.0f, 0.0f), FRotator::ZeroRotator);
        if (AStaticMeshActor* Floor = World->SpawnActor<AStaticMeshActor>(FVector(0.0f, -100.0f, -20.0f), FRotator::ZeroRotator))
        {
            Floor->GetStaticMeshComponent()->SetStaticMesh(CubeMesh);
            Floor->GetStaticMeshComponent()->SetWorldScale3D(FVector(12.0f, 7.0f, 0.2f));
        }
        return UEditorLoadingAndSavingUtils::SaveMap(World, TEXT("/JMDoor/Demo/Maps/L_JMDoorDemo"));
    }

    bool CreateFunctionalTestMap()
    {
        UWorld* World = UEditorLoadingAndSavingUtils::NewBlankMap(false);
        if (!World)
        {
            return false;
        }
        World->SpawnActor<AJMDoorFunctionalTest>(FVector::ZeroVector, FRotator::ZeroRotator);
        return UEditorLoadingAndSavingUtils::SaveMap(World, TEXT("/JMDoor/Tests/Maps/L_JMDoorFunctionalTests"));
    }
}

UJMDoorGenerateSamplesCommandlet::UJMDoorGenerateSamplesCommandlet()
{
    IsClient = false;
    IsEditor = true;
    LogToConsole = true;
    ShowErrorCount = true;
}

int32 UJMDoorGenerateSamplesCommandlet::Main(const FString& Params)
{
    UStaticMesh* CubeMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube"));
    UJMDoorConfigData* Config = CreateDoorConfig();
    UJMDoorConfigData* LockedConfig = CreateLockedDoorConfig();
    UBlueprint* RotatingBlueprint = CreateDoorBlueprint(TEXT("/JMDoor/Demo/Blueprints/BP_JMRotatingDoorExample"), TEXT("BP_JMRotatingDoorExample"), AJMRotatingDoorActor::StaticClass(), Config, CubeMesh, true);
    UBlueprint* SlidingBlueprint = CreateDoorBlueprint(TEXT("/JMDoor/Demo/Blueprints/BP_JMSlidingDoorExample"), TEXT("BP_JMSlidingDoorExample"), AJMSlidingDoorActor::StaticClass(), Config, CubeMesh, false);
    UBlueprint* LockedBlueprint = CreateDoorBlueprint(TEXT("/JMDoor/Demo/Blueprints/BP_JMRotatingDoorLockedExample"), TEXT("BP_JMRotatingDoorLockedExample"), AJMRotatingDoorActor::StaticClass(), LockedConfig, CubeMesh, true);
    const bool bSucceeded = CubeMesh && Config && LockedConfig && RotatingBlueprint && SlidingBlueprint && LockedBlueprint &&
        CreateDemoMap(RotatingBlueprint, SlidingBlueprint, LockedBlueprint, CubeMesh) && CreateFunctionalTestMap();
    UE_LOG(LogTemp, Display, TEXT("JMDoor sample generation %s."), bSucceeded ? TEXT("succeeded") : TEXT("failed"));
    return bSucceeded ? 0 : 1;
}
