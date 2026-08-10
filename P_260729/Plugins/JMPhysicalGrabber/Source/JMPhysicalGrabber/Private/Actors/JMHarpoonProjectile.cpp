#include "Actors/JMHarpoonProjectile.h"

#include "Components/JMHarpoonGunComponent.h"
#include "Components/PointLightComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"

AJMHarpoonProjectile::AJMHarpoonProjectile()
{
    PrimaryActorTick.bCanEverTick = true;

    Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
    SetRootComponent(Collision);
    Collision->InitSphereRadius(6.0f);
    Collision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    Collision->SetCollisionObjectType(ECC_WorldDynamic);
    Collision->SetCollisionResponseToAllChannels(ECR_Block);
    Collision->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
    Collision->SetNotifyRigidBodyCollision(true);
    Collision->SetCanEverAffectNavigation(false);
    Collision->BodyInstance.bUseCCD = true;
    Collision->OnComponentHit.AddDynamic(this, &AJMHarpoonProjectile::HandleCollisionHit);

    ShaftMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Shaft"));
    ShaftMesh->SetupAttachment(Collision);
    ShaftMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    ShaftMesh->SetRelativeLocation(FVector(-30.0f, 0.0f, 0.0f));
    ShaftMesh->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
    ShaftMesh->SetRelativeScale3D(FVector(0.045f, 0.045f, 0.55f));

    TipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tip"));
    TipMesh->SetupAttachment(Collision);
    TipMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    TipMesh->SetRelativeLocation(FVector(-1.0f, 0.0f, 0.0f));
    TipMesh->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
    TipMesh->SetRelativeScale3D(FVector(0.11f, 0.11f, 0.22f));

    FinMeshA = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FinA"));
    FinMeshA->SetupAttachment(Collision);
    FinMeshA->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    FinMeshA->SetRelativeLocation(FVector(-55.0f, 0.0f, 5.0f));
    FinMeshA->SetRelativeScale3D(FVector(0.14f, 0.025f, 0.08f));

    FinMeshB = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FinB"));
    FinMeshB->SetupAttachment(Collision);
    FinMeshB->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    FinMeshB->SetRelativeLocation(FVector(-55.0f, 0.0f, -5.0f));
    FinMeshB->SetRelativeScale3D(FVector(0.14f, 0.025f, 0.08f));

    CableAnchor = CreateDefaultSubobject<USceneComponent>(TEXT("CableAnchor"));
    CableAnchor->SetupAttachment(Collision);
    CableAnchor->SetRelativeLocation(FVector(-62.0f, 0.0f, 0.0f));

    ImpactLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("ImpactLight"));
    ImpactLight->SetupAttachment(Collision);
    ImpactLight->SetLightColor(FLinearColor(1.0f, 0.22f, 0.04f));
    ImpactLight->SetIntensity(0.0f);
    ImpactLight->SetAttenuationRadius(180.0f);
    ImpactLight->SetCastShadows(false);

    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
    ProjectileMovement->UpdatedComponent = Collision;
    ProjectileMovement->InitialSpeed = 6500.0f;
    ProjectileMovement->MaxSpeed = 6500.0f;
    ProjectileMovement->ProjectileGravityScale = 0.12f;
    ProjectileMovement->bRotationFollowsVelocity = true;
    ProjectileMovement->bShouldBounce = false;
    ProjectileMovement->bForceSubStepping = true;
    ProjectileMovement->MaxSimulationTimeStep = 0.025f;
    ProjectileMovement->MaxSimulationIterations = 8;
    ProjectileMovement->Deactivate();

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderFinder(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ConeFinder(TEXT("/Engine/BasicShapes/Cone.Cone"));
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeFinder(TEXT("/Engine/BasicShapes/Cube.Cube"));
    ShaftMesh->SetStaticMesh(CylinderFinder.Object);
    TipMesh->SetStaticMesh(ConeFinder.Object);
    FinMeshA->SetStaticMesh(CubeFinder.Object);
    FinMeshB->SetStaticMesh(CubeFinder.Object);
}

void AJMHarpoonProjectile::BeginPlay()
{
    Super::BeginPlay();

    if (AActor* OwnerActor = GetOwner())
    {
        Collision->IgnoreActorWhenMoving(OwnerActor, true);
    }
}

void AJMHarpoonProjectile::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    if (ProjectileMovement->IsActive() && !ProjectileMovement->Velocity.IsNearlyZero())
    {
        LastVelocity = ProjectileMovement->Velocity;
    }

    if (ImpactFlashRemaining > 0.0f)
    {
        ImpactFlashRemaining = FMath::Max(0.0f, ImpactFlashRemaining - DeltaSeconds);
        ImpactLight->SetIntensity(12000.0f * (ImpactFlashRemaining / 0.09f));
    }
    else
    {
        ImpactLight->SetIntensity(0.0f);
    }
}

void AJMHarpoonProjectile::InitializeHarpoon(UJMHarpoonGunComponent* InGun, const FVector& Direction, float Speed)
{
    OwningGun = InGun;
    bImpactReported = false;
    LastVelocity = Direction.GetSafeNormal() * Speed;
    ProjectileMovement->InitialSpeed = Speed;
    ProjectileMovement->MaxSpeed = Speed;
    ProjectileMovement->Velocity = LastVelocity;
    ProjectileMovement->Activate(true);
}

void AJMHarpoonProjectile::EmbedAtHit(const FHitResult& Hit, float EmbedDepth)
{
    ProjectileMovement->StopMovementImmediately();
    ProjectileMovement->Deactivate();
    Collision->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    const FVector Direction = GetTravelDirection();
    SetActorLocationAndRotation(Hit.ImpactPoint + Direction * EmbedDepth, Direction.Rotation(), false, nullptr, ETeleportType::TeleportPhysics);

    if (UPrimitiveComponent* HitComponent = Hit.GetComponent())
    {
        AttachToComponent(HitComponent, FAttachmentTransformRules::KeepWorldTransform, Hit.BoneName);
    }

    ImpactFlashRemaining = 0.09f;
    ImpactLight->SetIntensity(12000.0f);
}

void AJMHarpoonProjectile::BeginFreeReturn()
{
    ProjectileMovement->StopMovementImmediately();
    ProjectileMovement->Deactivate();
    Collision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
}

void AJMHarpoonProjectile::SetLoadedPreviewMode(bool bEnabled)
{
    SetActorEnableCollision(!bEnabled);
    Collision->SetCollisionEnabled(bEnabled ? ECollisionEnabled::NoCollision : ECollisionEnabled::QueryAndPhysics);

    if (bEnabled)
    {
        ProjectileMovement->StopMovementImmediately();
        ProjectileMovement->Deactivate();
        ImpactFlashRemaining = 0.0f;
        ImpactLight->SetIntensity(0.0f);
        ImpactLight->SetVisibility(false);
        SetActorTickEnabled(false);
    }
    else
    {
        ImpactLight->SetVisibility(true);
        SetActorTickEnabled(true);
    }
}

FVector AJMHarpoonProjectile::GetTravelDirection() const
{
    return LastVelocity.GetSafeNormal(SMALL_NUMBER, GetActorForwardVector());
}

void AJMHarpoonProjectile::HandleCollisionHit(
    UPrimitiveComponent* HitComponent,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComponent,
    FVector NormalImpulse,
    const FHitResult& Hit)
{
    if (bImpactReported || OtherActor == GetOwner())
    {
        return;
    }

    bImpactReported = true;
    if (OwningGun.IsValid())
    {
        OwningGun->NotifyProjectileImpact(this, Hit, LastVelocity);
    }
}
