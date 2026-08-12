#include "Overview/JMAssetOverviewAuthoringLibrary.h"

#include "AssetRegistry/AssetData.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Components/DirectionalLightComponent.h"
#include "Components/LightComponent.h"
#include "Components/PointLightComponent.h"
#include "Components/SkyAtmosphereComponent.h"
#include "Components/SkyLightComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TextRenderComponent.h"
#include "Editor.h"
#include "Camera/CameraActor.h"
#include "Engine/DirectionalLight.h"
#include "Engine/ExponentialHeightFog.h"
#include "Engine/PointLight.h"
#include "Engine/SkyLight.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/TextRenderActor.h"
#include "Engine/World.h"
#include "FileHelpers.h"
#include "GameFramework/PlayerStart.h"
#include "Misc/PackageName.h"
#include "Overview/JMAssetOverviewEntry.h"
#include "UObject/ConstructorHelpers.h"

namespace
{
	constexpr int32 EntryColumns = 10;
	constexpr int32 SectionColumns = 5;
	constexpr float EntrySpacingX = 760.0f;
	constexpr float EntrySpacingY = 900.0f;
	constexpr float SectionSpacingX = 8300.0f;
	constexpr float SectionSpacingY = 13500.0f;
	const FString OverviewMapPath = TEXT("/Game/Overview/Level_AssetOverview");

	const TArray<FString> IncludedMounts = {
		TEXT("Game"), TEXT("InventorySystem"), TEXT("ItemInspector"), TEXT("JMDoor"),
		TEXT("JMFootstep"), TEXT("JMInteraction"), TEXT("JMJumpScare"), TEXT("JMObjective"),
		TEXT("JMRecon"), TEXT("JMRoomGrid"), TEXT("JMThrowable"), TEXT("ReusableDialogueSystem"),
	};

	struct FOverviewAsset
	{
		FAssetData Data;
		FString Mount;
		FString Group;
	};

	FString GetMount(const FString& PackageName)
	{
		FString Remaining = PackageName;
		Remaining.RemoveFromStart(TEXT("/"));
		FString Mount;
		Remaining.Split(TEXT("/"), &Mount, nullptr);
		return Mount;
	}

	FString GetGroup(const FString& PackageName, const FString& Mount)
	{
		if (Mount != TEXT("Game"))
		{
			return FString::Printf(TEXT("PLUGIN / %s"), *Mount);
		}
		FString Remaining = PackageName;
		Remaining.RemoveFromStart(TEXT("/Game/"));
		FString Folder;
		if (!Remaining.Split(TEXT("/"), &Folder, nullptr))
		{
			Folder = TEXT("Root");
		}
		return FString::Printf(TEXT("GAME / %s"), *Folder);
	}

	FColor GetClassColor(const FName ClassName)
	{
		const FString Name = ClassName.ToString();
		if (Name.Contains(TEXT("Mesh"))) return FColor(95, 225, 160);
		if (Name.Contains(TEXT("Blueprint")) || Name == TEXT("BehaviorTree") || Name == TEXT("BlackboardData"))
			return FColor(80, 200, 255);
		if (Name.Contains(TEXT("Texture")) || Name.Contains(TEXT("Material"))) return FColor(255, 120, 205);
		if (Name.Contains(TEXT("Sound")) || Name.Contains(TEXT("Dialogue"))) return FColor(255, 205, 75);
		if (Name.Contains(TEXT("Anim")) || Name.Contains(TEXT("Skeleton")) || Name.Contains(TEXT("BlendSpace")))
			return FColor(205, 135, 255);
		if (Name.Contains(TEXT("Niagara"))) return FColor(80, 235, 235);
		if (Name.Contains(TEXT("Input"))) return FColor(255, 155, 75);
		return FColor(205, 215, 225);
	}

	FString SafeActorLabel(const FString& Value)
	{
		FString Result = Value;
		Result.ReplaceInline(TEXT("/"), TEXT("_"));
		Result.ReplaceInline(TEXT(" "), TEXT("_"));
		return Result.Left(90);
	}

	ATextRenderActor* SpawnText(UWorld& World, const FVector& Location, const FString& Text,
		float Size, FColor Color, const FName Folder, const FString& ActorLabel)
	{
		ATextRenderActor* Actor = World.SpawnActor<ATextRenderActor>(Location, FRotator(0.0f, -90.0f, 0.0f));
		if (!Actor)
		{
			return nullptr;
		}
		Actor->SetActorLabel(ActorLabel);
		Actor->SetFolderPath(Folder);
		UTextRenderComponent* TextComponent = Actor->GetTextRender();
		TextComponent->SetText(FText::FromString(Text));
		TextComponent->SetWorldSize(Size);
		TextComponent->SetTextRenderColor(Color);
		TextComponent->SetHorizontalAlignment(EHTA_Center);
		TextComponent->SetVerticalAlignment(EVRTA_TextCenter);
		return Actor;
	}

	FString MakeTypeSummary(const TArray<FOverviewAsset>& Assets)
	{
		TMap<FName, int32> Counts;
		for (const FOverviewAsset& Asset : Assets)
		{
			++Counts.FindOrAdd(Asset.Data.AssetClassPath.GetAssetName());
		}
		TArray<TPair<FName, int32>> Sorted;
		for (const TPair<FName, int32>& Pair : Counts)
		{
			Sorted.Add(Pair);
		}
		Sorted.Sort([](const TPair<FName, int32>& A, const TPair<FName, int32>& B)
		{
			return A.Value == B.Value ? A.Key.LexicalLess(B.Key) : A.Value > B.Value;
		});
		FString Result;
		const int32 Shown = FMath::Min(6, Sorted.Num());
		for (int32 Index = 0; Index < Shown; ++Index)
		{
			if (Index > 0) Result += TEXT("  |  ");
			Result += FString::Printf(TEXT("%s %d"), *Sorted[Index].Key.ToString(), Sorted[Index].Value);
		}
		if (Sorted.Num() > Shown)
		{
			Result += FString::Printf(TEXT("  |  +%d types"), Sorted.Num() - Shown);
		}
		return Result;
	}

	void BuildEnvironment(UWorld& World, int32 SectionCount, int32 AssetCount)
	{
		const int32 SectionRows = FMath::Max(1, FMath::DivideAndRoundUp(SectionCount, SectionColumns));
		const float FloorWidth = SectionColumns * SectionSpacingX + 2000.0f;
		const float FloorDepth = SectionRows * SectionSpacingY + 5000.0f;
		const FVector FloorCenter((SectionColumns - 1) * SectionSpacingX * 0.5f,
			(SectionRows - 1) * SectionSpacingY * 0.5f + 2500.0f, -25.0f);

		UStaticMesh* Cube = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube"));
		AStaticMeshActor* Floor = World.SpawnActor<AStaticMeshActor>(FloorCenter, FRotator::ZeroRotator);
		Floor->SetActorLabel(TEXT("Overview_Floor"));
		Floor->SetFolderPath(TEXT("Overview/Environment"));
		Floor->GetStaticMeshComponent()->SetStaticMesh(Cube);
		Floor->GetStaticMeshComponent()->SetMobility(EComponentMobility::Static);
		Floor->SetActorScale3D(FVector(FloorWidth / 100.0f, FloorDepth / 100.0f, 0.5f));

		ADirectionalLight* Sun = World.SpawnActor<ADirectionalLight>(FVector(0.0f, 0.0f, 1000.0f),
			FRotator(-48.0f, -35.0f, 0.0f));
		Sun->SetActorLabel(TEXT("Overview_Sun"));
		Sun->SetFolderPath(TEXT("Overview/Environment"));
		Sun->GetLightComponent()->SetIntensity(6.0f);

		ASkyLight* Sky = World.SpawnActor<ASkyLight>(FVector::ZeroVector, FRotator::ZeroRotator);
		Sky->SetActorLabel(TEXT("Overview_SkyLight"));
		Sky->SetFolderPath(TEXT("Overview/Environment"));
		Sky->GetLightComponent()->SetIntensity(1.0f);
		Sky->GetLightComponent()->SetMobility(EComponentMobility::Movable);

		ASkyAtmosphere* Atmosphere = World.SpawnActor<ASkyAtmosphere>();
		Atmosphere->SetActorLabel(TEXT("Overview_SkyAtmosphere"));
		Atmosphere->SetFolderPath(TEXT("Overview/Environment"));

		AExponentialHeightFog* Fog = World.SpawnActor<AExponentialHeightFog>(FVector(0.0f, 0.0f, -500.0f),
			FRotator::ZeroRotator);
		Fog->SetActorLabel(TEXT("Overview_Fog"));
		Fog->SetFolderPath(TEXT("Overview/Environment"));

		const float CenterX = (SectionColumns - 1) * SectionSpacingX * 0.5f;
		SpawnText(World, FVector(CenterX, -1900.0f, 800.0f),
			FString::Printf(TEXT("PROJECT + PLUGIN ASSET OVERVIEW\n%d SOURCE ASSETS  /  %d SECTIONS"),
				AssetCount, SectionCount), 120.0f, FColor(235, 245, 255), TEXT("Overview/Labels"),
			TEXT("Overview_Main_Title"));
		SpawnText(World, FVector(CenterX, -1850.0f, 500.0f),
			TEXT("Every entry stores a source-asset reference. Select an entry and use the Details magnifying glass.\n"
				"Mesh / Material / Texture / Niagara / safe Actor Blueprints include an in-world preview."),
			45.0f, FColor(135, 195, 225), TEXT("Overview/Labels"), TEXT("Overview_Instructions"));

		APlayerStart* PlayerStart = World.SpawnActor<APlayerStart>(FVector(CenterX, -3300.0f, 110.0f),
			FRotator(0.0f, 90.0f, 0.0f));
		PlayerStart->SetActorLabel(TEXT("Overview_PlayerStart"));
		PlayerStart->SetFolderPath(TEXT("Overview/Environment"));

		ACameraActor* Camera = World.SpawnActor<ACameraActor>(FVector(CenterX, -5000.0f, 1300.0f),
			FRotator(-12.0f, 90.0f, 0.0f));
		Camera->SetActorLabel(TEXT("Overview_Camera"));
		Camera->SetFolderPath(TEXT("Overview/Environment"));
	}
}

bool UJMAssetOverviewAuthoringLibrary::BuildAssetOverviewLevel()
{
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
	IAssetRegistry& Registry = AssetRegistryModule.Get();
	TArray<FString> ScanPaths;
	TArray<FName> PackagePaths;
	for (const FString& Mount : IncludedMounts)
	{
		ScanPaths.Add(TEXT("/") + Mount);
		PackagePaths.Add(*FString::Printf(TEXT("/%s"), *Mount));
	}
	Registry.ScanPathsSynchronous(ScanPaths, true);

	TArray<FAssetData> RegistryAssets;
	Registry.GetAssetsByPaths(PackagePaths, RegistryAssets, true, true);
	TArray<FOverviewAsset> Assets;
	for (const FAssetData& Data : RegistryAssets)
	{
		const FString PackageName = Data.PackageName.ToString();
		const FString Mount = GetMount(PackageName);
		if (!Data.IsUAsset() || !IncludedMounts.Contains(Mount) ||
			PackageName.StartsWith(TEXT("/Game/Overview/")) ||
			PackageName.Contains(TEXT("/__ExternalActors__/")) ||
			PackageName.Contains(TEXT("/__ExternalObjects__/")) ||
			Data.AssetClassPath.GetAssetName() == TEXT("ObjectRedirector"))
		{
			continue;
		}
		Assets.Add({Data, Mount, GetGroup(PackageName, Mount)});
	}
	Assets.Sort([](const FOverviewAsset& A, const FOverviewAsset& B)
	{
		if (A.Group != B.Group) return A.Group < B.Group;
		const FName AClass = A.Data.AssetClassPath.GetAssetName();
		const FName BClass = B.Data.AssetClassPath.GetAssetName();
		if (AClass != BClass) return AClass.LexicalLess(BClass);
		return A.Data.PackageName.LexicalLess(B.Data.PackageName);
	});

	TMap<FString, TArray<FOverviewAsset>> GroupedAssets;
	for (const FOverviewAsset& Asset : Assets)
	{
		GroupedAssets.FindOrAdd(Asset.Group).Add(Asset);
	}
	TArray<FString> Groups;
	GroupedAssets.GetKeys(Groups);
	Groups.Sort([](const FString& A, const FString& B)
	{
		const bool bAPlugin = A.StartsWith(TEXT("PLUGIN"));
		const bool bBPlugin = B.StartsWith(TEXT("PLUGIN"));
		return bAPlugin == bBPlugin ? A < B : !bAPlugin;
	});

	UWorld* World = UEditorLoadingAndSavingUtils::NewBlankMap(false);
	if (!World)
	{
		UE_LOG(LogTemp, Error, TEXT("JM_ASSET_OVERVIEW failed to create blank map"));
		return false;
	}
	BuildEnvironment(*World, Groups.Num(), Assets.Num());

	int32 SpawnedEntries = 0;
	for (int32 SectionIndex = 0; SectionIndex < Groups.Num(); ++SectionIndex)
	{
		const FString& Group = Groups[SectionIndex];
		const TArray<FOverviewAsset>& SectionAssets = GroupedAssets.FindChecked(Group);
		const FVector SectionOrigin((SectionIndex % SectionColumns) * SectionSpacingX,
			(SectionIndex / SectionColumns) * SectionSpacingY, 0.0f);
		const FName SectionFolder(*FString::Printf(TEXT("Overview/%s"), *SafeActorLabel(Group)));
		SpawnText(*World, SectionOrigin + FVector((EntryColumns - 1) * EntrySpacingX * 0.5f, 50.0f, 650.0f),
			FString::Printf(TEXT("%s\n%d ASSETS\n%s"), *Group, SectionAssets.Num(), *MakeTypeSummary(SectionAssets)),
			52.0f, Group.StartsWith(TEXT("PLUGIN")) ? FColor(60, 220, 220) : FColor(255, 150, 70),
			SectionFolder, FString::Printf(TEXT("Section_%02d_%s"), SectionIndex, *SafeActorLabel(Group)));

		for (int32 EntryIndex = 0; EntryIndex < SectionAssets.Num(); ++EntryIndex)
		{
			const FOverviewAsset& Asset = SectionAssets[EntryIndex];
			const int32 Column = EntryIndex % EntryColumns;
			const int32 Row = EntryIndex / EntryColumns;
			const FVector Location = SectionOrigin + FVector(Column * EntrySpacingX,
				1200.0f + Row * EntrySpacingY, 0.0f);
			AJMAssetOverviewEntry* Entry = World->SpawnActor<AJMAssetOverviewEntry>(Location, FRotator::ZeroRotator);
			if (!Entry)
			{
				continue;
			}
			const FName ClassName = Asset.Data.AssetClassPath.GetAssetName();
			Entry->SetFolderPath(SectionFolder);
			Entry->SetActorLabel(FString::Printf(TEXT("%s__%s"),
				*SafeActorLabel(Asset.Data.AssetName.ToString()), *ClassName.ToString()));
			Entry->ConfigureOverviewEntry(Asset.Data.GetSoftObjectPath(), Asset.Data.AssetName, ClassName,
				*Asset.Mount, Asset.Data.PackagePath.ToString(), GetClassColor(ClassName));
			++SpawnedEntries;
		}
	}

	World->MarkPackageDirty();
	const bool bSaved = UEditorLoadingAndSavingUtils::SaveMap(World, OverviewMapPath);
	UE_LOG(LogTemp, Display, TEXT("JM_ASSET_OVERVIEW result=%s assets=%d spawned=%d sections=%d map=%s"),
		bSaved && SpawnedEntries == Assets.Num() ? TEXT("success") : TEXT("failure"),
		Assets.Num(), SpawnedEntries, Groups.Num(), *OverviewMapPath);
	return bSaved && SpawnedEntries == Assets.Num();
}
