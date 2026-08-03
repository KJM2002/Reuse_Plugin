#include "Components/JMHideInteractableAdapterComponent.h"

#include "Components/JMHideInteractorComponent.h"
#include "Components/JMHideCharacterParticipantComponent.h"
#include "Components/JMHideInputRouterComponent.h"
#include "Components/JMHideSpotComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Pawn.h"

namespace
{
    AActor* ResolveParticipant(const FJMInteractionContext& Context)
    {
        if (AController* Controller = Cast<AController>(Context.InstigatorActor))
        {
            return Controller->GetPawn();
        }
        return Context.InstigatorActor;
    }
}

UJMHideInteractableAdapterComponent::UJMHideInteractableAdapterComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

bool UJMHideInteractableAdapterComponent::CanInteract_Implementation(const FJMInteractionContext& Context) const
{
    const UJMHideSpotComponent* Spot = GetOwner() ? GetOwner()->FindComponentByClass<UJMHideSpotComponent>() : nullptr;
    const AActor* Participant = ResolveParticipant(Context);
    const UJMHideInteractorComponent* Interactor =
        Participant ? Participant->FindComponentByClass<UJMHideInteractorComponent>() : nullptr;
    if (!Spot || !Participant)
    {
        return false;
    }
    if (Interactor && Interactor->IsHidden())
    {
        return Interactor->GetCurrentHideSpot() == Spot;
    }
    if (Interactor)
    {
        return Spot->IsAvailable() && !Interactor->HasActiveSession();
    }
    return bAutoInstallDefaultCharacterDriver && Cast<ACharacter>(Participant) && Spot->IsAvailable();
}

FJMInteractionResult UJMHideInteractableAdapterComponent::BeginInteract_Implementation(const FJMInteractionContext& Context)
{
    return CanInteract_Implementation(Context)
        ? FJMInteractionResult::Success()
        : FJMInteractionResult::Failure(EJMInteractionResultCode::NotAllowed,
            NSLOCTEXT("JMHideInteraction", "Unavailable", "This hide spot is unavailable."));
}

FJMInteractionResult UJMHideInteractableAdapterComponent::CompleteInteract_Implementation(const FJMInteractionContext& Context)
{
    AActor* Participant = ResolveParticipant(Context);
    UJMHideInteractorComponent* Interactor = ResolveOrInstallInteractor(Participant);
    UJMHideSpotComponent* Spot = GetOwner() ? GetOwner()->FindComponentByClass<UJMHideSpotComponent>() : nullptr;
    if (!Interactor || !Spot)
    {
        return FJMInteractionResult::Failure(EJMInteractionResultCode::TargetInvalid,
            NSLOCTEXT("JMHideInteraction", "MissingComponents", "Hide components are missing."));
    }
    const FJMHideResult Result = Interactor->IsHidden() && Interactor->GetCurrentHideSpot() == Spot
        ? Interactor->TryExitCurrentHideSpot()
        : Interactor->TryEnterHideSpot(Spot);
    return Result.bSucceeded
        ? FJMInteractionResult::Success(NSLOCTEXT("JMHideInteraction", "CommandAccepted", "Hide command accepted."))
        : FJMInteractionResult::Failure(EJMInteractionResultCode::NotAllowed, Result.Message);
}

void UJMHideInteractableAdapterComponent::CancelInteract_Implementation(const FJMInteractionContext& Context)
{
}

FJMInteractionPrompt UJMHideInteractableAdapterComponent::GetInteractionPrompt_Implementation(
    const FJMInteractionContext& Context) const
{
    FJMInteractionPrompt Prompt;
    const AActor* Participant = ResolveParticipant(Context);
    const UJMHideInteractorComponent* Interactor =
        Participant ? Participant->FindComponentByClass<UJMHideInteractorComponent>() : nullptr;
    Prompt.DisplayText = Interactor && Interactor->IsHidden() ? ExitPrompt : EnterPrompt;
    Prompt.bVisible = CanInteract_Implementation(Context);
    Prompt.Priority = 20;
    return Prompt;
}

float UJMHideInteractableAdapterComponent::GetInteractionDuration_Implementation(
    const FJMInteractionContext& Context) const
{
    return 0.0f;
}

int32 UJMHideInteractableAdapterComponent::GetInteractionPriority_Implementation(
    const FJMInteractionContext& Context) const
{
    return 20;
}

UJMHideInteractorComponent* UJMHideInteractableAdapterComponent::ResolveOrInstallInteractor(
    AActor* Participant) const
{
    if (!IsValid(Participant))
    {
        return nullptr;
    }
    UJMHideInputRouterComponent* Router =
        Participant->FindComponentByClass<UJMHideInputRouterComponent>();
    if (!Router)
    {
        Router = NewObject<UJMHideInputRouterComponent>(
            Participant, TEXT("JMHideInputRouter_Runtime"));
        Participant->AddInstanceComponent(Router);
        Router->RegisterComponent();
    }

    if (UJMHideInteractorComponent* Existing =
        Participant->FindComponentByClass<UJMHideInteractorComponent>())
    {
        return Existing;
    }
    if (!bAutoInstallDefaultCharacterDriver || !Cast<ACharacter>(Participant))
    {
        return nullptr;
    }

    UJMHideCharacterParticipantComponent* Driver =
        Participant->FindComponentByClass<UJMHideCharacterParticipantComponent>();
    if (!Driver)
    {
        Driver = NewObject<UJMHideCharacterParticipantComponent>(
            Participant, TEXT("JMHideCharacterParticipant_Runtime"));
        Participant->AddInstanceComponent(Driver);
        Driver->RegisterComponent();
    }

    UJMHideInteractorComponent* Interactor = NewObject<UJMHideInteractorComponent>(
        Participant, TEXT("JMHideInteractor_Runtime"));
    Participant->AddInstanceComponent(Interactor);
    Interactor->RegisterComponent();
    return Interactor;
}
