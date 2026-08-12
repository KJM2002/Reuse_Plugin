#include "Overview/JMAssetOverviewEntry.h"

#include "Components/AudioComponent.h"
#include "Components/BillboardComponent.h"
#include "Components/ChildActorComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TextRenderComponent.h"
#include "Engine/Blueprint.h"
#include "Engine/LevelScriptActor.h"
#include "Engine/SkeletalMesh.h"
#include "Engine/StaticMesh.h"
#include "Engine/Texture2D.h"
#include "GameFramework/Controller.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/WorldSettings.h"
#include "Materials/MaterialInterface.h"
#include "NiagaraComponent.h"
#include "NiagaraSystem.h"
#include "Sound/SoundBase.h"
#include "UObject/ConstructorHelpers.h"

namespace
{
	constexpr float PreviewHalfExtent = 250.0f;

	float UniformPreviewScale(const FVector& Extent)
	{
		const float LargestExtent = FMath::Max3(Extent.X, Extent.Y, Extent.Z);
		return LargestExtent > KINDA_SMALL_NUMBER
			? FMath::Clamp(PreviewHalfExtent / LargestExtent, 0.015f, 6.0f) : 1.0f;
	}
}

AJMAssetOverviewEntry::AJMAssetOverviewEntry()
{
	PrimaryActorTick.bCanEverTick = false;
	SetActorEnableCollision(false);

	OverviewRoot = CreateDefaultSubobject<USceneComponent>(TEXT("OverviewRoot"));
	SetRootComponent(OverviewRoot);
	OverviewRoot->SetMobility(EComponentMobility::Static);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeFinder(TEXT("/Engine/BasicShapes/Cube.Cube"));

	Pedestal = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pedestal"));
	Pedestal->SetupAttachment(OverviewRoot);
	Pedestal->SetMobility(EComponentMobility::Static);
	Pedestal->SetStaticMesh(CubeFinder.Object);
	Pedestal->SetRelativeLocation(FVector(0.0f, 0.0f, 8.0f));
	Pedestal->SetRelativeScale3D(FVector(4.8f, 4.8f, 0.16f));
	Pedestal->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	StaticPreview = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticPreview"));
	StaticPreview->SetupAttachment(OverviewRoot);
	StaticPreview->SetMobility(EComponentMobility::Static);
	StaticPreview->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	StaticPreview->SetVisibility(false);

	SkeletalPreview = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalPreview"));
	SkeletalPreview->SetupAttachment(OverviewRoot);
	SkeletalPreview->SetMobility(EComponentMobility::Movable);
	SkeletalPreview->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SkeletalPreview->SetVisibility(false);

	TexturePreview = CreateDefaultSubobject<UBillboardComponent>(TEXT("TexturePreview"));
	TexturePreview->SetupAttachment(OverviewRoot);
	TexturePreview->SetMobility(EComponentMobility::Static);
	TexturePreview->SetRelativeLocation(FVector(0.0f, 0.0f, 260.0f));
	TexturePreview->SetVisibility(false);

	AudioPreview = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioPreview"));
	AudioPreview->SetupAttachment(OverviewRoot);
	AudioPreview->bAutoActivate = false;
	AudioPreview->SetRelativeLocation(FVector(0.0f, 0.0f, 160.0f));

	NiagaraPreview = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraPreview"));
	NiagaraPreview->SetupAttachment(OverviewRoot);
	NiagaraPreview->bAutoActivate = false;
	NiagaraPreview->SetRelativeLocation(FVector(0.0f, 0.0f, 40.0f));
	NiagaraPreview->SetVisibility(false);

	ActorPreview = CreateDefaultSubobject<UChildActorComponent>(TEXT("ActorPreview"));
	ActorPreview->SetupAttachment(OverviewRoot);
	ActorPreview->SetMobility(EComponentMobility::Static);
	ActorPreview->SetVisibility(false);

	AssetNameText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("AssetNameText"));
	AssetNameText->SetupAttachment(OverviewRoot);
	AssetNameText->SetMobility(EComponentMobility::Static);
	AssetNameText->SetRelativeLocation(FVector(0.0f, -355.0f, 82.0f));
	AssetNameText->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	AssetNameText->SetHorizontalAlignment(EHTA_Center);
	AssetNameText->SetVerticalAlignment(EVRTA_TextCenter);
	AssetNameText->SetWorldSize(30.0f);
	AssetNameText->SetTranslucentSortPriority(10);

	AssetDetailText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("AssetDetailText"));
	AssetDetailText->SetupAttachment(OverviewRoot);
	AssetDetailText->SetMobility(EComponentMobility::Static);
	AssetDetailText->SetRelativeLocation(FVector(0.0f, -355.0f, 35.0f));
	AssetDetailText->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	AssetDetailText->SetHorizontalAlignment(EHTA_Center);
	AssetDetailText->SetVerticalAlignment(EVRTA_TextCenter);
	AssetDetailText->SetWorldSize(15.0f);
	AssetDetailText->SetTextRenderColor(FColor(185, 195, 205));
	AssetDetailText->SetTranslucentSortPriority(10);
}

void AJMAssetOverviewEntry::ConfigureOverviewEntry(const FSoftObjectPath& AssetPath, FName AssetName,
	FName ClassName, FName InMountPoint, const FString& InPackagePath, FColor DisplayColor)
{
	RepresentedAsset = TSoftObjectPtr<UObject>(AssetPath);
	AssetClassName = ClassName;
	MountPoint = InMountPoint;
	PackagePath = InPackagePath;
	AssetNameText->SetText(FText::FromName(AssetName));
	AssetNameText->SetTextRenderColor(DisplayColor);

	FString ShortPath = InPackagePath;
	TArray<FString> Segments;
	InPackagePath.ParseIntoArray(Segments, TEXT("/"), true);
	if (Segments.Num() > 2)
	{
		ShortPath = FString::Printf(TEXT(".../%s/%s"), *Segments[Segments.Num() - 2], *Segments.Last());
	}
	AssetDetailText->SetText(FText::FromString(FString::Printf(TEXT("[%s]  %s"),
		*ClassName.ToString(), *ShortPath)));
	BuildPreview();
}

void AJMAssetOverviewEntry::ResetPreviews()
{
	StaticPreview->SetStaticMesh(nullptr);
	StaticPreview->EmptyOverrideMaterials();
	StaticPreview->SetVisibility(false);
	StaticPreview->SetRelativeTransform(FTransform::Identity);
	SkeletalPreview->SetSkeletalMeshAsset(nullptr);
	SkeletalPreview->SetVisibility(false);
	SkeletalPreview->SetRelativeTransform(FTransform::Identity);
	TexturePreview->SetSprite(nullptr);
	TexturePreview->SetVisibility(false);
	AudioPreview->SetSound(nullptr);
	NiagaraPreview->SetAsset(nullptr);
	NiagaraPreview->SetVisibility(false);
	ActorPreview->SetChildActorClass(nullptr);
	ActorPreview->SetVisibility(false);
	ActorPreview->SetRelativeTransform(FTransform::Identity);
}

void AJMAssetOverviewEntry::BuildPreview()
{
	ResetPreviews();
	const FString ClassName = AssetClassName.ToString();
	const bool bPreviewable = ClassName == TEXT("StaticMesh") || ClassName == TEXT("SkeletalMesh") ||
		ClassName == TEXT("Texture2D") || ClassName == TEXT("Material") ||
		ClassName == TEXT("MaterialInstanceConstant") || ClassName == TEXT("SoundWave") ||
		ClassName == TEXT("SoundCue") || ClassName == TEXT("NiagaraSystem") ||
		ClassName == TEXT("Blueprint");
	if (!bPreviewable)
	{
		return;
	}

	UObject* Asset = RepresentedAsset.LoadSynchronous();
	if (UStaticMesh* Mesh = Cast<UStaticMesh>(Asset))
	{
		const FBoxSphereBounds Bounds = Mesh->GetBounds();
		const float Scale = UniformPreviewScale(Bounds.BoxExtent);
		StaticPreview->SetStaticMesh(Mesh);
		StaticPreview->SetRelativeScale3D(FVector(Scale));
		StaticPreview->SetRelativeLocation(FVector(0.0f, 0.0f,
			25.0f + (Bounds.BoxExtent.Z - Bounds.Origin.Z) * Scale));
		StaticPreview->SetVisibility(true);
		return;
	}
	if (USkeletalMesh* Mesh = Cast<USkeletalMesh>(Asset))
	{
		const FBoxSphereBounds Bounds = Mesh->GetImportedBounds();
		const float Scale = UniformPreviewScale(Bounds.BoxExtent);
		SkeletalPreview->SetSkeletalMeshAsset(Mesh);
		SkeletalPreview->SetRelativeScale3D(FVector(Scale));
		SkeletalPreview->SetRelativeLocation(FVector(0.0f, 0.0f,
			25.0f + (Bounds.BoxExtent.Z - Bounds.Origin.Z) * Scale));
		SkeletalPreview->SetVisibility(true);
		return;
	}
	if (UTexture2D* Texture = Cast<UTexture2D>(Asset))
	{
		const float LargestDimension = FMath::Max(Texture->GetSizeX(), Texture->GetSizeY());
		const float Scale = LargestDimension > 0.0f ? 420.0f / LargestDimension : 1.0f;
		TexturePreview->SetSprite(Texture);
		TexturePreview->SetRelativeScale3D(FVector(Scale));
		TexturePreview->SetVisibility(true);
		return;
	}
	if (UMaterialInterface* Material = Cast<UMaterialInterface>(Asset))
	{
		UStaticMesh* Cube = Pedestal->GetStaticMesh();
		StaticPreview->SetStaticMesh(Cube);
		StaticPreview->SetMaterial(0, Material);
		StaticPreview->SetRelativeLocation(FVector(0.0f, 0.0f, 250.0f));
		StaticPreview->SetRelativeScale3D(FVector(4.5f, 0.25f, 4.5f));
		StaticPreview->SetVisibility(true);
		return;
	}
	if (USoundBase* Sound = Cast<USoundBase>(Asset))
	{
		AudioPreview->SetSound(Sound);
		return;
	}
	if (UNiagaraSystem* System = Cast<UNiagaraSystem>(Asset))
	{
		NiagaraPreview->SetAsset(System);
		NiagaraPreview->SetVisibility(true);
		return;
	}
	if (UBlueprint* Blueprint = Cast<UBlueprint>(Asset))
	{
		UClass* PreviewClass = Blueprint->GeneratedClass;
		const bool bSafeActorClass = PreviewClass && PreviewClass->IsChildOf(AActor::StaticClass()) &&
			!PreviewClass->IsChildOf(AController::StaticClass()) &&
			!PreviewClass->IsChildOf(AGameModeBase::StaticClass()) &&
			!PreviewClass->IsChildOf(AWorldSettings::StaticClass()) &&
			!PreviewClass->IsChildOf(ALevelScriptActor::StaticClass()) &&
			!PreviewClass->HasAnyClassFlags(CLASS_Abstract | CLASS_Deprecated | CLASS_NewerVersionExists | CLASS_NotPlaceable);
		if (bSafeActorClass)
		{
			ActorPreview->SetChildActorClass(PreviewClass);
			ActorPreview->CreateChildActor();
			ActorPreview->SetVisibility(true);
			NormalizeActorPreview();
		}
	}
}

void AJMAssetOverviewEntry::NormalizeActorPreview()
{
	AActor* Child = ActorPreview->GetChildActor();
	if (!Child)
	{
		return;
	}
	const FBox Bounds = Child->GetComponentsBoundingBox(true);
	if (!Bounds.IsValid)
	{
		return;
	}
	const FVector Extent = Bounds.GetExtent();
	const float Scale = UniformPreviewScale(Extent);
	const float LocalBottom = Bounds.Min.Z - GetActorLocation().Z;
	ActorPreview->SetRelativeScale3D(FVector(Scale));
	ActorPreview->SetRelativeLocation(FVector(0.0f, 0.0f, 25.0f - LocalBottom * Scale));
}
