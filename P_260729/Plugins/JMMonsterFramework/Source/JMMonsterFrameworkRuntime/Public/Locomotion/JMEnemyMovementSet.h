#pragma once

#include "Engine/DataAsset.h"
#include "Locomotion/JMEnemyMovementTypes.h"
#include "JMEnemyMovementSet.generated.h"

/** Reusable collection of named movement profiles for one or more enemy definitions. */
UCLASS(BlueprintType)
class JMMONSTERFRAMEWORKRUNTIME_API UJMEnemyMovementSet : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Movement")
    TArray<FJMEnemyMovementProfile> Profiles;

    const FJMEnemyMovementProfile* FindProfile(FName ProfileName) const;

    UFUNCTION(BlueprintPure, Category="JM Enemy|Movement")
    bool GetProfile(FName ProfileName, FJMEnemyMovementProfile& OutProfile) const;

#if WITH_EDITOR
    virtual EDataValidationResult IsDataValid(class FDataValidationContext& Context) const override;
#endif
};
