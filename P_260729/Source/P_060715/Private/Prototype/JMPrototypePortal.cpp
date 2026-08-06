#include "Prototype/JMPrototypePortal.h"

#include "Components/BoxComponent.h"
#include "Engine/GameInstance.h"
#include "NiagaraComponent.h"
#include "Prototype/JMPrototypeProgressionSubsystem.h"

#define LOCTEXT_NAMESPACE "JMPrototypePortal"

AJMPrototypePortal::AJMPrototypePortal()
{
	InteractionPrompt = LOCTEXT("UsePortal", "Use portal");
	InteractionPriority = 100;
	InteractionBounds->SetBoxExtent(FVector(220.0f, 220.0f, 260.0f));
	InteractionBounds->SetRelativeLocation(FVector(0.0f, 0.0f, 120.0f));
	PortalEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("PortalEffect"));
	PortalEffect->SetupAttachment(SceneRoot);
	PortalEffect->SetAutoActivate(true);
}

bool AJMPrototypePortal::IsPrototypeInteractionAvailable(const FJMInteractionContext& Context) const
{
	if (!Super::IsPrototypeInteractionAvailable(Context) || !IsValid(DestinationActor))
	{
		return false;
	}
	const UGameInstance* GameInstance = GetGameInstance();
	const UJMPrototypeProgressionSubsystem* Progression = GameInstance ? GameInstance->GetSubsystem<UJMPrototypeProgressionSubsystem>() : nullptr;
	return Progression && (Direction == EJMPrototypePortalDirection::EnterDungeon ? Progression->CanEnterDungeon() : Progression->CanReturnToBase());
}

FJMPrototypeOperationResult AJMPrototypePortal::PerformPrototypeInteraction(const FJMInteractionContext& Context)
{
	if (!IsValid(DestinationActor))
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::MissingDestination, LOCTEXT("MissingDestination", "Portal destination is not configured."));
	}
	AActor* Traveler = Context.InstigatorActor;
	UJMPrototypeProgressionSubsystem* Progression = GetGameInstance() ? GetGameInstance()->GetSubsystem<UJMPrototypeProgressionSubsystem>() : nullptr;
	if (!IsValid(Traveler) || !Progression)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::TravelFailed, LOCTEXT("MissingTraveler", "Portal travel could not start."));
	}

	const FTransform PreviousTransform = Traveler->GetActorTransform();
	const FVector Destination = DestinationActor->GetActorTransform().TransformPosition(ArrivalOffset);
	if (!Traveler->TeleportTo(Destination, DestinationActor->GetActorRotation(), false, true))
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::TravelFailed, LOCTEXT("TeleportFailed", "Portal travel failed."));
	}

	const FJMPrototypeOperationResult StateResult = Direction == EJMPrototypePortalDirection::EnterDungeon
		? Progression->EnterDungeon()
		: Progression->ReturnToBase();
	if (!StateResult.bSucceeded)
	{
		Traveler->SetActorTransform(PreviousTransform, false, nullptr, ETeleportType::TeleportPhysics);
	}
	return StateResult;
}

#undef LOCTEXT_NAMESPACE
