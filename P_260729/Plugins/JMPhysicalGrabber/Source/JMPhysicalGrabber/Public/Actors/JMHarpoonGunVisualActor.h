#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JMHarpoonGunVisualActor.generated.h"

class USceneComponent;
class UChildActorComponent;
class UStaticMeshComponent;
class AJMHarpoonProjectile;

/**
 * Editable first-person presentation for the harpoon gun.
 * Create a Blueprint child to adjust every part in the Blueprint viewport.
 */
UCLASS(BlueprintType, Blueprintable)
class JMPHYSICALGRABBER_API AJMHarpoonGunVisualActor : public AActor
{
    GENERATED_BODY()

public:
    AJMHarpoonGunVisualActor();

    virtual void OnConstruction(const FTransform& Transform) override;
    virtual void BeginPlay() override;

    UFUNCTION(BlueprintPure, Category="JM|Harpoon Gun|Visual")
    USceneComponent* GetMuzzlePoint() const { return MuzzlePoint; }

    void SetWinchAngle(float AngleDegrees);
    void SetLoadedHarpoonClass(TSubclassOf<AJMHarpoonProjectile> InProjectileClass);
    void SetLoadedHarpoonVisible(bool bVisible);

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM|Harpoon Gun|Parts")
    TObjectPtr<USceneComponent> VisualRoot;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM|Harpoon Gun|Parts")
    TObjectPtr<UStaticMeshComponent> Body;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM|Harpoon Gun|Parts")
    TObjectPtr<UStaticMeshComponent> Handle;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM|Harpoon Gun|Parts")
    TObjectPtr<UStaticMeshComponent> Barrel;

    /** Common viewport transform for the muzzle, loaded harpoon, spawn point, and cable origin. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM|Harpoon Gun|Parts")
    TObjectPtr<USceneComponent> MuzzleAssembly;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM|Harpoon Gun|Parts")
    TObjectPtr<UStaticMeshComponent> Muzzle;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM|Harpoon Gun|Parts")
    TObjectPtr<UStaticMeshComponent> Winch;

    /** Fine offset inside MuzzleAssembly for the projectile spawn and cable origin. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM|Harpoon Gun|Parts")
    TObjectPtr<USceneComponent> MuzzlePoint;

    /** Uses the configured Projectile Class so loaded and fired harpoons share all visual transforms. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM|Harpoon Gun|Parts")
    TObjectPtr<UChildActorComponent> LoadedHarpoonPreview;

    /** Projectile shown inside this actor's Blueprint viewport and while the gun is loaded. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="JM|Harpoon Gun|Parts")
    TSubclassOf<AJMHarpoonProjectile> LoadedHarpoonPreviewClass;

private:
    void ConfigurePart(UStaticMeshComponent* Part) const;
    void ConfigureLoadedHarpoonPreview();

    FRotator InitialWinchRotation = FRotator::ZeroRotator;
};
