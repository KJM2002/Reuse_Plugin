#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JMHarpoonProjectile.generated.h"

class UJMHarpoonGunComponent;
class UPointLightComponent;
class UProjectileMovementComponent;
class USphereComponent;
class UStaticMeshComponent;

/** Fast swept projectile used by UJMHarpoonGunComponent. */
UCLASS(BlueprintType, Blueprintable)
class JMPHYSICALGRABBER_API AJMHarpoonProjectile : public AActor
{
    GENERATED_BODY()

public:
    AJMHarpoonProjectile();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;

    void InitializeHarpoon(UJMHarpoonGunComponent* InGun, const FVector& Direction, float Speed);
    void EmbedAtHit(const FHitResult& Hit, float EmbedDepth);
    void BeginFreeReturn();
    /** Disables gameplay behavior so this actor can be used as the loaded-gun preview. */
    void SetLoadedPreviewMode(bool bEnabled);

    FVector GetTravelDirection() const;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM|Harpoon|Parts")
    TObjectPtr<USphereComponent> Collision;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM|Harpoon|Parts")
    TObjectPtr<UStaticMeshComponent> ShaftMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM|Harpoon|Parts")
    TObjectPtr<UStaticMeshComponent> TipMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM|Harpoon|Parts")
    TObjectPtr<UStaticMeshComponent> FinMeshA;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM|Harpoon|Parts")
    TObjectPtr<UStaticMeshComponent> FinMeshB;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM|Harpoon|Parts")
    TObjectPtr<UPointLightComponent> ImpactLight;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM|Harpoon|Movement")
    TObjectPtr<UProjectileMovementComponent> ProjectileMovement;

private:
    UFUNCTION()
    void HandleCollisionHit(
        UPrimitiveComponent* HitComponent,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComponent,
        FVector NormalImpulse,
        const FHitResult& Hit);

    TWeakObjectPtr<UJMHarpoonGunComponent> OwningGun;
    FVector LastVelocity = FVector::ForwardVector;
    float ImpactFlashRemaining = 0.0f;
    bool bImpactReported = false;
};
