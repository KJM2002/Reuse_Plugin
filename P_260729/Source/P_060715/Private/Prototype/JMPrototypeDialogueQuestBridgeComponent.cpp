#include "Prototype/JMPrototypeDialogueQuestBridgeComponent.h"

#include "DialogueEventTags.h"
#include "Engine/GameInstance.h"
#include "Payloads/DialogueEventPayload.h"
#include "Prototype/JMPrototypeProgressionSubsystem.h"
#include "Data/JMObjectiveFlowDefinition.h"
#include "Subsystems/JMGameplayEventSubsystem.h"
#include "Subsystems/JMObjectiveFlowSubsystem.h"
#include "Types/JMGameplayEventTypes.h"

UJMPrototypeDialogueQuestBridgeComponent::UJMPrototypeDialogueQuestBridgeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UJMPrototypeDialogueQuestBridgeComponent::BeginPlay()
{
	Super::BeginPlay();
	UGameInstance* GameInstance = GetWorld() ? GetWorld()->GetGameInstance() : nullptr;
	UJMGameplayEventSubsystem* Events = GameInstance ? GameInstance->GetSubsystem<UJMGameplayEventSubsystem>() : nullptr;
	if (!Events)
	{
		return;
	}
	const FJMGameplayEventSubscriptionHandle Handle = Events->SubscribeEvent(
		JMDialogueEventTags::Finished,
		this,
		EJMGameplayEventMatchType::Exact,
		FJMGameplayEventNativeDelegate::CreateUObject(this, &UJMPrototypeDialogueQuestBridgeComponent::HandleDialogueFinished));
	DialogueFinishedSubscriptionId = Handle.Id;
}

void UJMPrototypeDialogueQuestBridgeComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UGameInstance* GameInstance = GetWorld() ? GetWorld()->GetGameInstance() : nullptr;
	if (UJMGameplayEventSubsystem* Events = GameInstance ? GameInstance->GetSubsystem<UJMGameplayEventSubsystem>() : nullptr)
	{
		FJMGameplayEventSubscriptionHandle Handle;
		Handle.Id = DialogueFinishedSubscriptionId;
		if (Handle.IsValid())
		{
			Events->UnsubscribeEvent(Handle);
		}
	}
	DialogueFinishedSubscriptionId.Invalidate();
	Super::EndPlay(EndPlayReason);
}

void UJMPrototypeDialogueQuestBridgeComponent::HandleDialogueFinished(const FJMGameplayEventMessage& Message)
{
	if ((bDisableAfterAcceptance && bAcceptedQuest) || QuestOfferDialogueId.IsNone())
	{
		return;
	}
	const UDialogueEventPayload* Payload = Cast<UDialogueEventPayload>(Message.Payload);
	if (!Payload || Payload->DialogueId != QuestOfferDialogueId || Payload->EndReason != EDialogueEndReason::Completed)
	{
		return;
	}
	UGameInstance* GameInstance = GetWorld() ? GetWorld()->GetGameInstance() : nullptr;
	UJMPrototypeProgressionSubsystem* Progression = GameInstance ? GameInstance->GetSubsystem<UJMPrototypeProgressionSubsystem>() : nullptr;
	const FJMPrototypeOperationResult Result = Progression
		? Progression->AcceptQuest()
		: FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidConfiguration, FText::FromString(TEXT("Prototype progression subsystem is unavailable.")));
	bAcceptedQuest = Result.bSucceeded;
	if (Result.bSucceeded && IsValid(QuestFlowDefinition))
	{
		if (UJMObjectiveFlowSubsystem* Flows = GameInstance->GetSubsystem<UJMObjectiveFlowSubsystem>())
		{
			if (!Flows->RestartObjectiveFlow(QuestFlowDefinition->FlowId))
			{
				Flows->StartObjectiveFlow(QuestFlowDefinition);
			}
		}
	}
	OnQuestAcceptanceResolved(Result);
}
