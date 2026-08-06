#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Prototype/JMPrototypeInteractionActorBase.h"
#include "JMPrototypeStations.generated.h"

class UInventoryItemDefinition;

UCLASS(Blueprintable)
class P_060715_API AJMPrototypeQuestSubmitStation : public AJMPrototypeInteractionActorBase
{
	GENERATED_BODY()

public:
	AJMPrototypeQuestSubmitStation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	TObjectPtr<UInventoryItemDefinition> QuestItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest", meta = (ClampMin = "1"))
	int32 RequiredQuantity = 3;

	/** Optional Objective step completed after atomic item submission and reward. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	FGameplayTag SubmissionObjectiveId;

protected:
	virtual FJMPrototypeOperationResult PerformPrototypeInteraction(const FJMInteractionContext& Context) override;
};

UCLASS(Blueprintable)
class P_060715_API AJMPrototypeCookingStation : public AJMPrototypeInteractionActorBase
{
	GENERATED_BODY()

public:
	AJMPrototypeCookingStation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cooking")
	TObjectPtr<UInventoryItemDefinition> Ingredient;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cooking", meta = (ClampMin = "1"))
	int32 RequiredQuantity = 1;

protected:
	virtual FJMPrototypeOperationResult PerformPrototypeInteraction(const FJMInteractionContext& Context) override;
};

UCLASS(Blueprintable)
class P_060715_API AJMPrototypeUpgradeStation : public AJMPrototypeInteractionActorBase
{
	GENERATED_BODY()

public:
	AJMPrototypeUpgradeStation();

protected:
	virtual FJMPrototypeOperationResult PerformPrototypeInteraction(const FJMInteractionContext& Context) override;
};
