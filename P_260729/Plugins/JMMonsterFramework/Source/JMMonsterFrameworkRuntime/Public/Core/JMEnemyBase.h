#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "JMEnemyBase.generated.h"

class UJMEnemyDefinition;
class UJMEnemyAudioComponent;
class UJMEnemyDebugComponent;
class UJMEnemyActionComponent;
class UJMEnemyMemoryComponent;
class UJMEnemyLocomotionComponent;
class UJMEnemyPerceptionComponent;
class UJMEnemyStateComponent;

/** Minimal container shared by framework enemies. Behavior belongs to composed systems, not this class. */
UCLASS(Abstract, Blueprintable)
class JMMONSTERFRAMEWORKRUNTIME_API AJMEnemyBase : public ACharacter
{
    GENERATED_BODY()

public:
    explicit AJMEnemyBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

    UFUNCTION(BlueprintPure, Category="JM Enemy|Core")
    UJMEnemyDefinition* GetEnemyDefinition() const { return EnemyDefinition; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Core")
    UJMEnemyStateComponent* GetEnemyStateComponent() const { return StateComponent; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Core")
    UJMEnemyPerceptionComponent* GetEnemyPerceptionComponent() const { return PerceptionComponent; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Core")
    UJMEnemyMemoryComponent* GetEnemyMemoryComponent() const { return MemoryComponent; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Core")
    UJMEnemyLocomotionComponent* GetEnemyLocomotionComponent() const { return LocomotionComponent; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Core")
    UJMEnemyActionComponent* GetEnemyActionComponent() const { return ActionComponent; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Core")
    UJMEnemyAudioComponent* GetEnemyAudioComponent() const { return AudioComponent; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Core")
    UJMEnemyDebugComponent* GetEnemyDebugComponent() const { return DebugComponent; }

    virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
        AController* EventInstigator, AActor* DamageCauser) override;

protected:
    virtual void PostInitializeComponents() override;
    virtual void BeginPlay() override;

    /** Idempotent hook used by PostInitializeComponents and available to future framework extensions. */
    virtual void InitializeEnemy();

    /** Applies definition-owned state, perception, movement, and action configuration once. */
    virtual void ApplyDefinition(const UJMEnemyDefinition& Definition);

    /**
     * Runtime-generated navigation should normally treat an enemy as an agent, not as moving world geometry.
     * This policy disables navigation influence on the enemy's movable primitive components by default.
     */
    void ApplyNavigationInfluencePolicy();

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="JM Monster|Navigation",
        meta=(ToolTip="Enable only when this enemy's primitive components are intentionally meant to modify runtime NavMesh. Leave disabled for normal moving enemies."))
    bool bPrimitiveComponentsAffectNavigation = false;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="JM Enemy|Core")
    TObjectPtr<UJMEnemyDefinition> EnemyDefinition;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM Enemy|Core")
    TObjectPtr<UJMEnemyStateComponent> StateComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM Enemy|Core")
    TObjectPtr<UJMEnemyPerceptionComponent> PerceptionComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM Enemy|Core")
    TObjectPtr<UJMEnemyMemoryComponent> MemoryComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM Enemy|Core")
    TObjectPtr<UJMEnemyLocomotionComponent> LocomotionComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM Enemy|Core")
    TObjectPtr<UJMEnemyActionComponent> ActionComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM Monster|Audio")
    TObjectPtr<UJMEnemyAudioComponent> AudioComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM Monster|Debug")
    TObjectPtr<UJMEnemyDebugComponent> DebugComponent;

#if WITH_EDITOR
    virtual EDataValidationResult IsDataValid(class FDataValidationContext& Context) const override;
#endif

private:
    bool bFrameworkInitialized = false;
};
