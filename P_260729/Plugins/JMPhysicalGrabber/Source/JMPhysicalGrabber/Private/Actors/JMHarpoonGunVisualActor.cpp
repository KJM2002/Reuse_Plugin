#include "Actors/JMHarpoonGunVisualActor.h"

#include "Actors/JMHarpoonProjectile.h"
#include "Components/ChildActorComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

AJMHarpoonGunVisualActor::AJMHarpoonGunVisualActor()
{
    PrimaryActorTick.bCanEverTick = false;

    VisualRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VisualRoot"));
    SetRootComponent(VisualRoot);

    Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
    Body->SetupAttachment(VisualRoot);

    Handle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Handle"));
    Handle->SetupAttachment(VisualRoot);

    Barrel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Barrel"));
    Barrel->SetupAttachment(VisualRoot);

    Muzzle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Muzzle"));
    Muzzle->SetupAttachment(VisualRoot);

    Winch = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Winch"));
    Winch->SetupAttachment(VisualRoot);

    MuzzlePoint = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzlePoint"));
    MuzzlePoint->SetupAttachment(VisualRoot);

    LoadedHarpoonPreview = CreateDefaultSubobject<UChildActorComponent>(TEXT("LoadedHarpoonPreview"));
    LoadedHarpoonPreview->SetupAttachment(MuzzlePoint);
    LoadedHarpoonPreview->SetChildActorClass(AJMHarpoonProjectile::StaticClass());

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeFinder(TEXT("/Engine/BasicShapes/Cube.Cube"));
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderFinder(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));

    Body->SetStaticMesh(CubeFinder.Object);
    Handle->SetStaticMesh(CubeFinder.Object);
    Barrel->SetStaticMesh(CylinderFinder.Object);
    Muzzle->SetStaticMesh(CylinderFinder.Object);
    Winch->SetStaticMesh(CylinderFinder.Object);

    Body->SetRelativeScale3D(FVector(0.38f, 0.12f, 0.13f));
    Handle->SetRelativeLocation(FVector(-8.0f, 0.0f, -16.0f));
    Handle->SetRelativeRotation(FRotator(0.0f, 0.0f, -18.0f));
    Handle->SetRelativeScale3D(FVector(0.10f, 0.08f, 0.22f));
    Barrel->SetRelativeLocation(FVector(28.0f, 0.0f, 5.0f));
    Barrel->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
    Barrel->SetRelativeScale3D(FVector(0.075f, 0.075f, 0.42f));
    Muzzle->SetRelativeLocation(FVector(66.0f, 0.0f, 5.0f));
    Muzzle->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
    Muzzle->SetRelativeScale3D(FVector(0.12f, 0.12f, 0.08f));
    Winch->SetRelativeLocation(FVector(-4.0f, 0.0f, 13.0f));
    Winch->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
    Winch->SetRelativeScale3D(FVector(0.13f, 0.13f, 0.12f));
    MuzzlePoint->SetRelativeLocation(FVector(74.0f, 0.0f, 5.0f));

    ConfigurePart(Body);
    ConfigurePart(Handle);
    ConfigurePart(Barrel);
    ConfigurePart(Muzzle);
    ConfigurePart(Winch);
}

void AJMHarpoonGunVisualActor::BeginPlay()
{
    Super::BeginPlay();

    InitialWinchRotation = Winch->GetRelativeRotation();
    TInlineComponentArray<UStaticMeshComponent*> Meshes(this);
    for (UStaticMeshComponent* Mesh : Meshes)
    {
        Mesh->SetOnlyOwnerSee(true);
    }
    ConfigureLoadedHarpoonPreview();
}

void AJMHarpoonGunVisualActor::SetWinchAngle(float AngleDegrees)
{
    if (Winch)
    {
        Winch->SetRelativeRotation(InitialWinchRotation + FRotator(0.0f, AngleDegrees, 0.0f));
    }
}

void AJMHarpoonGunVisualActor::SetLoadedHarpoonClass(TSubclassOf<AJMHarpoonProjectile> InProjectileClass)
{
    if (LoadedHarpoonPreview && InProjectileClass && LoadedHarpoonPreview->GetChildActorClass() != InProjectileClass)
    {
        LoadedHarpoonPreview->SetChildActorClass(InProjectileClass);
    }

    ConfigureLoadedHarpoonPreview();
}

void AJMHarpoonGunVisualActor::SetLoadedHarpoonVisible(bool bVisible)
{
    if (LoadedHarpoonPreview)
    {
        LoadedHarpoonPreview->SetVisibility(bVisible, true);
        if (AActor* PreviewActor = LoadedHarpoonPreview->GetChildActor())
        {
            PreviewActor->SetActorHiddenInGame(!bVisible);
        }
    }
}

void AJMHarpoonGunVisualActor::ConfigureLoadedHarpoonPreview()
{
    if (!LoadedHarpoonPreview)
    {
        return;
    }

    if (AJMHarpoonProjectile* PreviewProjectile = Cast<AJMHarpoonProjectile>(LoadedHarpoonPreview->GetChildActor()))
    {
        PreviewProjectile->SetLoadedPreviewMode(true);

        TInlineComponentArray<UStaticMeshComponent*> PreviewMeshes(PreviewProjectile);
        for (UStaticMeshComponent* Mesh : PreviewMeshes)
        {
            Mesh->SetOnlyOwnerSee(true);
            Mesh->SetCastShadow(false);
        }
    }
}

void AJMHarpoonGunVisualActor::ConfigurePart(UStaticMeshComponent* Part) const
{
    Part->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    Part->SetCanEverAffectNavigation(false);
    Part->SetCastShadow(false);
}
