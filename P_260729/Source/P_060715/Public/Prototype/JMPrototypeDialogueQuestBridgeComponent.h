#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "Prototype/JMPrototypeTypes.h"
#include "JMPrototypeDialogueQuestBridgeComponent.generated.h"

struct FJMGameplayEventMessage;
class UJMObjectiveFlowDefinition;

/** Accepts the prototype quest after one configured Dialogue sequence finishes. */
UCLASS(ClassGroup = (Prototype), BlueprintType, meta = (BlueprintSpawnableComponent))
class P_060715_API UJMPrototypeDialogueQuestBridgeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UJMPrototypeDialogueQuestBridgeComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Upgrade Prototype|Dialogue")
	FName QuestOfferDialogueId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Upgrade Prototype|Dialogue")
	bool bDisableAfterAcceptance = false;

	/** Optional collection/submission flow started after the offer dialogue completes. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Upgrade Prototype|Objective")
	TObjectPtr<UJMObjectiveFlowDefinition> QuestFlowDefinition;

	UFUNCTION(BlueprintImplementableEvent, Category = "Base Upgrade Prototype|Dialogue")
	void OnQuestAcceptanceResolved(const FJMPrototypeOperationResult& Result);

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	void HandleDialogueFinished(const FJMGameplayEventMessage& Message);

	FGuid DialogueFinishedSubscriptionId;
	bool bAcceptedQuest = false;
};
