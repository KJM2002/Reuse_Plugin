#include "Components/JMDoorInteractableAdapterComponent.h"

#include "Actors/JMDoorActor.h"
#include "Components/JMDoorInventoryAgentComponent.h"
#include "Door/JMDoorComponent.h"
#include "GameFramework/Controller.h"
#include "Settings/JMDoorGameplayIntegrationSettings.h"

namespace
{
    FJMDoorUseContext MakeDoorContext(const FJMInteractionContext& Context)
    {
        FJMDoorUseContext DoorContext;
        DoorContext.InstigatorActor = Context.InstigatorActor;
        DoorContext.InstigatorController = Context.InstigatorController;
        DoorContext.InteractionLocation = Context.InteractionLocation;
        DoorContext.InteractionDirection = Context.InteractionDirection;
        DoorContext.AccessTags = Context.InstigatorTags;
        return DoorContext;
    }
}

UJMDoorInteractableAdapterComponent::UJMDoorInteractableAdapterComponent()
{
    PrimaryComponentTick.bCanEverTick = false;

    const UJMDoorGameplayIntegrationSettings* Settings =
        GetDefault<UJMDoorGameplayIntegrationSettings>();
    OpenDoorPrompt = Settings->OpenDoorPrompt;
    CloseDoorPrompt = Settings->CloseDoorPrompt;
    LockedDoorPrompt = Settings->LockedDoorPrompt;
}

bool UJMDoorInteractableAdapterComponent::CanInteract_Implementation(const FJMInteractionContext& Context) const
{
    const AJMDoorActor* Door = Cast<AJMDoorActor>(GetOwner());
    if (!Door || !Door->DoorComponent)
    {
        return false;
    }
    const EJMDoorState State = Door->DoorComponent->GetState();
    return State != EJMDoorState::Broken && State != EJMDoorState::Jammed;
}

FJMInteractionResult UJMDoorInteractableAdapterComponent::BeginInteract_Implementation(const FJMInteractionContext& Context)
{
    return CanInteract_Implementation(Context)
        ? FJMInteractionResult::Success()
        : FJMInteractionResult::Failure(EJMInteractionResultCode::NotAllowed, NSLOCTEXT("JMDoorIntegration", "DoorUnavailable", "This door cannot be used."));
}

FJMInteractionResult UJMDoorInteractableAdapterComponent::CompleteInteract_Implementation(const FJMInteractionContext& Context)
{
    AJMDoorActor* Door = Cast<AJMDoorActor>(GetOwner());
    if (!Door || !Door->DoorComponent)
    {
        return FJMInteractionResult::Failure(EJMInteractionResultCode::TargetInvalid, NSLOCTEXT("JMDoorIntegration", "DoorInvalid", "The door is no longer valid."));
    }

    const FJMDoorResult Result = Door->DoorComponent->ToggleDoor(MakeDoorContext(Context));
    if (Result.bSucceeded)
    {
        return FJMInteractionResult::Success(Result.Message);
    }

    if ((Result.Code == EJMDoorResultCode::AccessDenied || Result.Code == EJMDoorResultCode::Locked) && IsValid(Context.InstigatorActor))
    {
        AActor* AgentOwner = Context.InstigatorActor;
        if (AController* Controller = Cast<AController>(AgentOwner); Controller && IsValid(Controller->GetPawn()))
        {
            AgentOwner = Controller->GetPawn();
        }

        UJMDoorInventoryAgentComponent* Agent = AgentOwner->FindComponentByClass<UJMDoorInventoryAgentComponent>();
        if (!Agent)
        {
            Agent = NewObject<UJMDoorInventoryAgentComponent>(AgentOwner, TEXT("JMDoorInventoryAgent"));
            AgentOwner->AddInstanceComponent(Agent);
            Agent->RegisterComponent();
        }
        if (Agent)
        {
            if (Agent->BeginLockedDoorItemSelection(Door, Context))
            {
                return FJMInteractionResult::Success(NSLOCTEXT("JMDoorIntegration", "ChooseAccessItem", "Choose an access item from the inventory."));
            }
        }
    }

    return FJMInteractionResult::Failure(EJMInteractionResultCode::NotAllowed, Result.Message);
}

void UJMDoorInteractableAdapterComponent::CancelInteract_Implementation(const FJMInteractionContext& Context)
{
}

FJMInteractionPrompt UJMDoorInteractableAdapterComponent::GetInteractionPrompt_Implementation(const FJMInteractionContext& Context) const
{
    FJMInteractionPrompt Prompt;
    const UJMDoorGameplayIntegrationSettings* Settings =
        GetDefault<UJMDoorGameplayIntegrationSettings>();
    const AJMDoorActor* Door = Cast<AJMDoorActor>(GetOwner());
    const bool bLocked = Door && Door->DoorComponent && Door->DoorComponent->IsLocked();
    const EJMDoorState DoorState = Door && Door->DoorComponent ? Door->DoorComponent->GetState() : EJMDoorState::Closed;
    const bool bOpenOrOpening = DoorState == EJMDoorState::Open || DoorState == EJMDoorState::Opening;
    const FText& EffectiveOpenPrompt =
        bOverridePromptTexts ? OpenDoorPrompt : Settings->OpenDoorPrompt;
    const FText& EffectiveClosePrompt =
        bOverridePromptTexts ? CloseDoorPrompt : Settings->CloseDoorPrompt;
    const FText& EffectiveLockedPrompt =
        bOverridePromptTexts ? LockedDoorPrompt : Settings->LockedDoorPrompt;
    Prompt.DisplayText = bLocked
        ? EffectiveLockedPrompt
        : (bOpenOrOpening ? EffectiveClosePrompt : EffectiveOpenPrompt);
    Prompt.bVisible = CanInteract_Implementation(Context);
    Prompt.Priority = 10;
    return Prompt;
}

float UJMDoorInteractableAdapterComponent::GetInteractionDuration_Implementation(const FJMInteractionContext& Context) const
{
    return 0.0f;
}

int32 UJMDoorInteractableAdapterComponent::GetInteractionPriority_Implementation(const FJMInteractionContext& Context) const
{
    return 10;
}
