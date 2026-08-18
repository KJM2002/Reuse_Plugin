#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Perception/JMEnemyPerceptionTypes.h"
#include "JMEnemyDefinition.generated.h"

/** Stable identity, baseline stats, and core initialization data for one enemy type. */
UCLASS(BlueprintType)
class JMMONSTERFRAMEWORKRUNTIME_API UJMEnemyDefinition : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UJMEnemyDefinition();

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Identity")
    FName EnemyId;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Identity")
    FText DisplayName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Identity")
    FGameplayTagContainer EnemyTags;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Stats", meta=(ClampMin="1.0"))
    float MaxHealth = 100.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Stats", meta=(ClampMin="0.0"))
    float BaseDamage = 10.0f;

    /** Applied before BeginPlay. Custom descendants under JM.Enemy.State are supported. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Core Configuration", meta=(Categories="JM.Enemy.State"))
    FGameplayTag InitialState;

    /** Sense-by-sense configuration. No enemy-type flags are stored here. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Perception")
    FJMEnemyPerceptionConfig Perception;

    /** Optional profile collection. Leaving both movement fields empty preserves engine defaults. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Movement")
    TObjectPtr<class UJMEnemyMovementSet> MovementSet;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Movement")
    FName DefaultMovementProfile;

    /** Shared immutable action data; the Action Component creates one runtime UObject per enemy. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Actions")
    TArray<TObjectPtr<class UJMEnemyActionDefinition>> Actions;

    /** Optional behavior layer. Core systems remain usable when no StateTree is assigned. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Behavior")
    TObjectPtr<class UStateTree> StateTree;

#if WITH_EDITOR
    virtual EDataValidationResult IsDataValid(class FDataValidationContext& Context) const override;
#endif
};
