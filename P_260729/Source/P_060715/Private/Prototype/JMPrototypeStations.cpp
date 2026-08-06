#include "Prototype/JMPrototypeStations.h"

#include "Engine/GameInstance.h"
#include "Prototype/JMPrototypeInventoryResolver.h"
#include "Prototype/JMPrototypeProgressionSubsystem.h"
#include "Subsystems/JMObjectiveSubsystem.h"

#define LOCTEXT_NAMESPACE "JMPrototypeStations"

namespace
{
	UJMPrototypeProgressionSubsystem* ResolveProgression(const AActor* Actor)
	{
		UGameInstance* GameInstance = Actor ? Actor->GetGameInstance() : nullptr;
		return GameInstance ? GameInstance->GetSubsystem<UJMPrototypeProgressionSubsystem>() : nullptr;
	}
}

AJMPrototypeQuestSubmitStation::AJMPrototypeQuestSubmitStation()
{
	InteractionPrompt = LOCTEXT("SubmitQuest", "Submit quest items");
}

FJMPrototypeOperationResult AJMPrototypeQuestSubmitStation::PerformPrototypeInteraction(const FJMInteractionContext& Context)
{
	UJMPrototypeProgressionSubsystem* Progression = ResolveProgression(this);
	if (!Progression)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidConfiguration, LOCTEXT("MissingProgression", "Prototype progression is unavailable."));
	}
	FJMPrototypeOperationResult Result = Progression->SubmitQuest(JMPrototypeInventory::Resolve(Context.InstigatorActor), QuestItem, RequiredQuantity);
	if (Result.bSucceeded && SubmissionObjectiveId.IsValid())
	{
		if (UGameInstance* GameInstance = GetGameInstance())
		{
			if (UJMObjectiveSubsystem* Objectives = GameInstance->GetSubsystem<UJMObjectiveSubsystem>())
			{
				Objectives->CompleteObjective(SubmissionObjectiveId);
			}
		}
	}
	return Result;
}

AJMPrototypeCookingStation::AJMPrototypeCookingStation()
{
	InteractionPrompt = LOCTEXT("Cook", "Cook and sell meal");
}

FJMPrototypeOperationResult AJMPrototypeCookingStation::PerformPrototypeInteraction(const FJMInteractionContext& Context)
{
	UJMPrototypeProgressionSubsystem* Progression = ResolveProgression(this);
	return Progression
		? Progression->CookAndSell(JMPrototypeInventory::Resolve(Context.InstigatorActor), Ingredient, RequiredQuantity)
		: FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidConfiguration, LOCTEXT("MissingCookingProgression", "Prototype progression is unavailable."));
}

AJMPrototypeUpgradeStation::AJMPrototypeUpgradeStation()
{
	InteractionPrompt = LOCTEXT("Upgrade", "Purchase inventory upgrade");
}

FJMPrototypeOperationResult AJMPrototypeUpgradeStation::PerformPrototypeInteraction(const FJMInteractionContext& Context)
{
	UJMPrototypeProgressionSubsystem* Progression = ResolveProgression(this);
	return Progression
		? Progression->PurchaseInventoryUpgrade(JMPrototypeInventory::Resolve(Context.InstigatorActor))
		: FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidConfiguration, LOCTEXT("MissingUpgradeProgression", "Prototype progression is unavailable."));
}

#undef LOCTEXT_NAMESPACE
