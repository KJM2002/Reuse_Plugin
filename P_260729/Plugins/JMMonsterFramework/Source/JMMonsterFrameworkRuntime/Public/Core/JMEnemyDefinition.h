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

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="JM Monster|Identity")
    FName EnemyId;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="JM Monster|Identity")
    FText DisplayName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="JM Monster|Identity")
    FGameplayTagContainer EnemyTags;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="JM Monster|Stats", meta=(ClampMin="1.0"))
    float MaxHealth = 100.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="JM Monster|Stats", meta=(ClampMin="0.0"))
    float BaseDamage = 10.0f;

    /** Applied before BeginPlay. Custom descendants under JM.Enemy.State are supported. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="JM Monster|State", meta=(Categories="JM.Enemy.State"))
    FGameplayTag InitialState;

    /** Sense-by-sense configuration. No enemy-type flags are stored here. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="JM Monster|Perception")
    FJMEnemyPerceptionConfig Perception;

    /** Optional profile collection. Leaving both movement fields empty preserves engine defaults. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="JM Monster|Movement")
    TObjectPtr<class UJMEnemyMovementSet> MovementSet;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="JM Monster|Movement",
        meta=(ToolTip="Profile name to apply from Movement Set when the enemy initializes."))
    FName DefaultMovementProfile;

    /** Shared immutable action data; the Action Component creates one runtime UObject per enemy. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="JM Monster|Actions")
    TArray<TObjectPtr<class UJMEnemyActionDefinition>> Actions;

    /** Optional behavior layer. Core systems remain usable when no StateTree is assigned. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="JM Monster|Behavior",
        meta=(ToolTip="Optional StateTree that composes framework tasks and conditions into this enemy's behavior."))
    TObjectPtr<class UStateTree> StateTree;

    /** Optional presentation mapping. It is never required for AI execution. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="JM Monster|Audio")
    TObjectPtr<class UJMEnemyAudioSet> AudioSet;

#if WITH_EDITOR
    virtual EDataValidationResult IsDataValid(class FDataValidationContext& Context) const override;
#endif
};
