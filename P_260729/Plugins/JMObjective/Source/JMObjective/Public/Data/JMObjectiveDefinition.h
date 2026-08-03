#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Types/JMGameplayEventTypes.h"
#include "Types/JMObjectiveTypes.h"
#include "JMObjectiveDefinition.generated.h"

UCLASS(BlueprintType)
class JMOBJECTIVE_API UJMObjectiveDefinition : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Identity")
    FGameplayTag ObjectiveId;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Display")
    FText DisplayName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Display", meta = (MultiLine = true))
    FText Description;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Event")
    FGameplayTag ListeningEventTag;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Event")
    EJMGameplayEventMatchType EventMatchType = EJMGameplayEventMatchType::Exact;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Progress", meta = (ClampMin = "1", UIMin = "1"))
    int32 RequiredCount = 1;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Progress")
    EJMObjectiveProgressIncrementMode ProgressIncrementMode = EJMObjectiveProgressIncrementMode::FixedAmount;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Progress", meta = (ClampMin = "1", UIMin = "1", EditCondition = "ProgressIncrementMode == EJMObjectiveProgressIncrementMode::FixedAmount"))
    int32 FixedProgressAmount = 1;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Filters")
    FGameplayTagContainer RequiredContextTags;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Filters")
    FGameplayTagContainer BlockedContextTags;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Filters")
    FName RequiredTargetIdentifier;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lifecycle")
    bool bAutoActivate = false;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lifecycle")
    bool bCanFail = false;

    virtual FPrimaryAssetId GetPrimaryAssetId() const override;
};
