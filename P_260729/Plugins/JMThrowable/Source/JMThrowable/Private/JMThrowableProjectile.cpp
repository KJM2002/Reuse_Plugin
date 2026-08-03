#include "JMThrowableProjectile.h"
#include "JMThrowableMovementComponent.h"
#include "JMThrowableDefinition.h"
#include "JMThrowableEventTags.h"
#include "Components/SphereComponent.h"
#include "Components/PointLightComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ProceduralMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInterface.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "Kismet/GameplayStatics.h"
#include "Perception/AISense_Hearing.h"
#include "Subsystems/JMGameplayEventSubsystem.h"
#include "Types/JMGameplayEventTypes.h"
#include "TimerManager.h"

namespace JMThrowableProjectileVisual
{
    void BuildBox(UProceduralMeshComponent* Mesh, const FVector& RequestedSize)
    {
        if (!Mesh)
        {
            return;
        }

        const FVector Size(
            FMath::Max(.1f, FMath::Abs(RequestedSize.X)),
            FMath::Max(.1f, FMath::Abs(RequestedSize.Y)),
            FMath::Max(.1f, FMath::Abs(RequestedSize.Z)));
        const FVector Half = Size * .5f;
        const TArray<FVector> Vertices = {
            {-Half.X, -Half.Y, -Half.Z},
            { Half.X, -Half.Y, -Half.Z},
            { Half.X,  Half.Y, -Half.Z},
            {-Half.X,  Half.Y, -Half.Z},
            {-Half.X, -Half.Y,  Half.Z},
            { Half.X, -Half.Y,  Half.Z},
            { Half.X,  Half.Y,  Half.Z},
            {-Half.X,  Half.Y,  Half.Z}};
        const TArray<int32> Triangles = {
            0, 2, 1, 0, 3, 2,
            4, 5, 6, 4, 6, 7,
            1, 2, 6, 1, 6, 5,
            0, 4, 7, 0, 7, 3,
            3, 7, 6, 3, 6, 2,
            0, 1, 5, 0, 5, 4};
        TArray<FVector> Normals;
        TArray<FVector2D> UVs;
        TArray<FLinearColor> Colors;
        TArray<FProcMeshTangent> Tangents;
        for (const FVector& Vertex : Vertices)
        {
            Normals.Add(Vertex.GetSafeNormal());
            UVs.Add(FVector2D::ZeroVector);
            Colors.Add(FLinearColor::White);
            Tangents.Add(FProcMeshTangent(FVector::ForwardVector, false));
        }
        Mesh->CreateMeshSection_LinearColor(
            0,
            Vertices,
            Triangles,
            Normals,
            UVs,
            Colors,
            Tangents,
            false);
    }
}

AJMThrowableProjectile::AJMThrowableProjectile()
{
    PrimaryActorTick.bCanEverTick = false;
    SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
    SetRootComponent(SphereCollision);
    SphereCollision->SetCollisionProfileName(TEXT("BlockAll"));
    ThrowableMovement = CreateDefaultSubobject<UJMThrowableMovementComponent>(TEXT("ThrowableMovement"));
    BurstLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("BurstLight"));
    BurstLight->SetupAttachment(SphereCollision);
    BurstLight->SetIntensity(0.f);
    BurstLight->SetCastShadows(false);
    ProjectileVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileVisual"));
    ProjectileVisual->SetupAttachment(SphereCollision);
    ProjectileVisual->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    ProjectileVisual->SetGenerateOverlapEvents(false);
    ProjectileVisual->SetCastShadow(true);
    ProjectileVisual->SetVisibility(false);
    NativeBoxVisual = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("NativeBoxVisual"));
    NativeBoxVisual->SetupAttachment(SphereCollision);
    NativeBoxVisual->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    NativeBoxVisual->SetGenerateOverlapEvents(false);
    NativeBoxVisual->SetCastShadow(true);
    JMThrowableProjectileVisual::BuildBox(NativeBoxVisual, FVector(8.5f, 5.5f, 2.2f));
}

void AJMThrowableProjectile::ConfigureDefinition(UJMThrowableDefinition* Definition)
{
    ActiveDefinition = Definition;
    if (!ActiveDefinition)
    {
        return;
    }

    UMaterialInterface* VisualMaterial =
        ActiveDefinition->ProjectileVisualMaterial.LoadSynchronous();
    UStaticMesh* VisualMesh = ActiveDefinition->ProjectileVisualMesh.LoadSynchronous();
    if (VisualMesh)
    {
        ProjectileVisual->SetStaticMesh(VisualMesh);
        const FVector MeshSize = VisualMesh->GetBoundingBox().GetSize();
        const FVector TargetSize = ActiveDefinition->ProjectileVisualSize.GetAbs();
        ProjectileVisual->SetRelativeScale3D(FVector(
            MeshSize.X > KINDA_SMALL_NUMBER ? TargetSize.X / MeshSize.X : 1.f,
            MeshSize.Y > KINDA_SMALL_NUMBER ? TargetSize.Y / MeshSize.Y : 1.f,
            MeshSize.Z > KINDA_SMALL_NUMBER ? TargetSize.Z / MeshSize.Z : 1.f));
        ProjectileVisual->SetVisibility(true);
        NativeBoxVisual->SetVisibility(false);
        if (VisualMaterial)
        {
            ProjectileVisual->SetMaterial(0, VisualMaterial);
        }
    }
    else
    {
        JMThrowableProjectileVisual::BuildBox(
            NativeBoxVisual,
            ActiveDefinition->ProjectileVisualSize);
        NativeBoxVisual->SetVisibility(true);
        ProjectileVisual->SetVisibility(false);
        if (VisualMaterial)
        {
            NativeBoxVisual->SetMaterial(0, VisualMaterial);
        }
    }
}

void AJMThrowableProjectile::Launch(const FJMThrowParameters& Parameters)
{
    SphereCollision->SetSphereRadius(Parameters.ProjectileRadius);
    SphereCollision->SetCollisionProfileName(Parameters.CollisionProfile);
    if (AActor* Thrower = GetOwner())
    {
        SphereCollision->IgnoreActorWhenMoving(Thrower, true);
        TInlineComponentArray<UPrimitiveComponent*> ThrowerPrimitives;
        Thrower->GetComponents(ThrowerPrimitives);
        for (UPrimitiveComponent* Primitive : ThrowerPrimitives)
        {
            if (Primitive)
            {
                Primitive->IgnoreActorWhenMoving(this, true);
            }
        }
    }
    ThrowableMovement->Launch(Parameters);
    OnThrown.Broadcast();
    PublishEvent(JMThrowableEventTags::Thrown);
}

void AJMThrowableProjectile::NotifyMovementBounced(const FHitResult& Hit)
{
    OnBounced.Broadcast(Hit);
    if (ActiveDefinition && Hit.GetComponent() && Hit.GetComponent()->IsSimulatingPhysics())
    {
        const FVector Impulse = ThrowableMovement->Velocity.GetClampedToMaxSize(ActiveDefinition->DynamicImpactImpulse);
        Hit.GetComponent()->AddImpulseAtLocation(Impulse, Hit.ImpactPoint);
    }
    PublishEvent(JMThrowableEventTags::Bounced);
}

void AJMThrowableProjectile::NotifyMovementRested(const FHitResult& Hit)
{
    OnRested.Broadcast(Hit);
    PublishEvent(JMThrowableEventTags::Rested);
    BeginFuse();
}

void AJMThrowableProjectile::BeginFuse()
{
    if (bActivationStarted || !ActiveDefinition || !GetWorld()) return;
    bActivationStarted = true;
    ThrowableMovement->State = EJMThrowableProjectileState::Fuse;
    GetWorldTimerManager().SetTimer(FuseTimer, this, &ThisClass::Activate,
        FMath::Max(0.01f, ActiveDefinition->FuseDelay), false);
}

void AJMThrowableProjectile::Activate()
{
    if (!ActiveDefinition || IsActorBeingDestroyed()) return;
    ThrowableMovement->State = EJMThrowableProjectileState::Activated;
    CompletedBursts = 0;
    PublishEvent(JMThrowableEventTags::Activated);
    ExecuteBurst();
    if (ActiveDefinition->BurstCount > 1)
        GetWorldTimerManager().SetTimer(BurstTimer, this, &ThisClass::ExecuteBurst,
            FMath::Max(.01f, ActiveDefinition->BurstInterval), true);
}

void AJMThrowableProjectile::ExecuteBurst()
{
    if (!ActiveDefinition || IsActorBeingDestroyed()) return;
    ++CompletedBursts;
    if (!ActiveDefinition->BurstParticle.IsNull())
        if (UNiagaraSystem* Particle = ActiveDefinition->BurstParticle.LoadSynchronous())
            UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, Particle, GetActorLocation());
    if (!ActiveDefinition->BurstSound.IsNull())
        if (USoundBase* Sound = ActiveDefinition->BurstSound.LoadSynchronous())
            UGameplayStatics::PlaySoundAtLocation(this, Sound, GetActorLocation(), 1.f, 1.f, 0.f,
                ActiveDefinition->SoundAttenuation.LoadSynchronous());
    BurstLight->SetIntensity(ActiveDefinition->LightIntensity);
    GetWorldTimerManager().ClearTimer(LightTimer);
    GetWorldTimerManager().SetTimer(LightTimer, this, &ThisClass::EndLightFlash,
        FMath::Max(.01f, ActiveDefinition->LightDuration), false);
    UAISense_Hearing::ReportNoiseEvent(this, GetActorLocation(), ActiveDefinition->NoiseLoudness,
        this, ActiveDefinition->NoiseRadius, TEXT("Throwable.Firework"));
    PublishEvent(JMThrowableEventTags::Burst);
    if (CompletedBursts >= FMath::Max(1, ActiveDefinition->BurstCount))
    {
        GetWorldTimerManager().ClearTimer(BurstTimer);
        GetWorldTimerManager().SetTimer(BurstTimer, this, &ThisClass::FinishActivation,
            FMath::Max(.01f, ActiveDefinition->LightDuration), false);
    }
}

void AJMThrowableProjectile::EndLightFlash()
{
    if (BurstLight) BurstLight->SetIntensity(0.f);
}

void AJMThrowableProjectile::FinishActivation()
{
    EndLightFlash();
    ThrowableMovement->State = EJMThrowableProjectileState::Finished;
    PublishEvent(JMThrowableEventTags::Finished);
    Destroy();
}

void AJMThrowableProjectile::PublishEvent(FGameplayTag EventTag) const
{
    UGameInstance* GI = GetWorld() ? GetWorld()->GetGameInstance() : nullptr;
    UJMGameplayEventSubsystem* Events = GI ? GI->GetSubsystem<UJMGameplayEventSubsystem>() : nullptr;
    if (!Events) return;
    FJMGameplayEventMessage Message;
    Message.EventTag = EventTag;
    Message.Source = const_cast<AJMThrowableProjectile*>(this);
    Message.Instigator = GetInstigator();
    Message.Target = const_cast<AJMThrowableProjectile*>(this);
    Events->PublishEvent(Message);
}
