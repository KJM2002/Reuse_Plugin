#pragma once

#include "Action/JMEnemyActionTypes.h"
#include "Engine/DataAsset.h"
#include "JMEnemyActionDefinition.generated.h"

class UDamageType;
class UJMEnemyAction;

/** Shared immutable configuration. Runtime phase, context, and cooldown never live in this asset. */
UCLASS(BlueprintType)
class JMMONSTERFRAMEWORKRUNTIME_API UJMEnemyActionDefinition : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Action", meta=(Categories="JM.Enemy.Action"))
    FGameplayTag ActionId;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Action")
    TSubclassOf<UJMEnemyAction> ActionClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Timing", meta=(ClampMin="0.0"))
    float WindupDuration = 0.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Timing", meta=(ClampMin="0.0"))
    float ActiveDuration = 0.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Timing", meta=(ClampMin="0.0"))
    float RecoveryDuration = 0.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Timing", meta=(ClampMin="0.0"))
    float Cooldown = 0.0f;

    virtual bool IsRuntimeConfigValid() const;

#if WITH_EDITOR
    virtual EDataValidationResult IsDataValid(class FDataValidationContext& Context) const override;
#endif
};

UCLASS(BlueprintType)
class JMMONSTERFRAMEWORKRUNTIME_API UJMEnemyActionDefinition_Melee : public UJMEnemyActionDefinition
{
    GENERATED_BODY()

public:
    UJMEnemyActionDefinition_Melee();

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Melee", meta=(ClampMin="0.0"))
    float Damage = 25.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Melee", meta=(ClampMin="0.0"))
    float AttackRange = 150.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Melee")
    TSubclassOf<UDamageType> DamageType;

    virtual bool IsRuntimeConfigValid() const override;
};

UCLASS(BlueprintType)
class JMMONSTERFRAMEWORKRUNTIME_API UJMEnemyActionDefinition_Scream : public UJMEnemyActionDefinition
{
    GENERATED_BODY()

public:
    UJMEnemyActionDefinition_Scream();
};
