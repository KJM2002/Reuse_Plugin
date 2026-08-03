#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "JMThrowableTypes.h"
#include "JMThrowableProjectile.generated.h"

class USphereComponent;
class UJMThrowableMovementComponent;
class UJMThrowableDefinition;
class UPointLightComponent;
class UStaticMeshComponent;
class UProceduralMeshComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FJMProjectileEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJMProjectileImpactEvent, const FHitResult&, Hit);

UCLASS(Blueprintable)
class JMTHROWABLE_API AJMThrowableProjectile : public AActor
{
    GENERATED_BODY()
public:
    AJMThrowableProjectile();
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly) TObjectPtr<USphereComponent> SphereCollision;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly) TObjectPtr<UJMThrowableMovementComponent> ThrowableMovement;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly) TObjectPtr<UPointLightComponent> BurstLight;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly) TObjectPtr<UStaticMeshComponent> ProjectileVisual;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly) TObjectPtr<UProceduralMeshComponent> NativeBoxVisual;
    UPROPERTY(BlueprintAssignable) FJMProjectileEvent OnThrown;
    UPROPERTY(BlueprintAssignable) FJMProjectileImpactEvent OnBounced;
    UPROPERTY(BlueprintAssignable) FJMProjectileImpactEvent OnRested;
    UFUNCTION(BlueprintCallable) void Launch(const FJMThrowParameters& Parameters);
    UFUNCTION(BlueprintCallable) void ConfigureDefinition(UJMThrowableDefinition* Definition);
    void NotifyMovementRested(const FHitResult& Hit);
    void NotifyMovementBounced(const FHitResult& Hit);

private:
    UPROPERTY(Transient) TObjectPtr<UJMThrowableDefinition> ActiveDefinition;
    int32 CompletedBursts = 0;
    bool bActivationStarted = false;
    FTimerHandle FuseTimer;
    FTimerHandle BurstTimer;
    FTimerHandle LightTimer;
    void BeginFuse();
    void Activate();
    void ExecuteBurst();
    void EndLightFlash();
    void FinishActivation();
    void PublishEvent(FGameplayTag EventTag) const;
};
