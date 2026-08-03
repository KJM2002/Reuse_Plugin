#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "JMObjectiveFlowDefinition.generated.h"

class UJMObjectiveDefinition;

UCLASS(BlueprintType)
class JMOBJECTIVE_API UJMObjectiveFlowDefinition : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Identity")
    FGameplayTag FlowId;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Display")
    FText DisplayName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Display", meta = (MultiLine = true))
    FText Description;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Flow", meta = (TitleProperty = "DisplayName"))
    TArray<TObjectPtr<UJMObjectiveDefinition>> ObjectiveDefinitions;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Flow")
    bool bStopOnObjectiveFailure = true;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Flow")
    bool bAllowRestart = false;

    UFUNCTION(BlueprintPure, Category = "JM Objective Flow")
    bool IsFlowDefinitionValid(FText& OutError) const;

    virtual FPrimaryAssetId GetPrimaryAssetId() const override;

#if WITH_EDITOR
    virtual EDataValidationResult IsDataValid(class FDataValidationContext& Context) const override;
#endif
};

