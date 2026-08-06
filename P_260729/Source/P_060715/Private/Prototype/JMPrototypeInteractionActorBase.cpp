#include "Prototype/JMPrototypeInteractionActorBase.h"

#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

#define LOCTEXT_NAMESPACE "JMPrototypeInteraction"

AJMPrototypeInteractionActorBase::AJMPrototypeInteractionActorBase()
{
	PrimaryActorTick.bCanEverTick = false;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	InteractionBounds = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractionBounds"));
	InteractionBounds->SetupAttachment(SceneRoot);
	InteractionBounds->SetBoxExtent(FVector(75.0f));
	InteractionBounds->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	InteractionBounds->SetCollisionResponseToAllChannels(ECR_Ignore);
	InteractionBounds->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	VisualMesh->SetupAttachment(SceneRoot);
	VisualMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

bool AJMPrototypeInteractionActorBase::CanInteract_Implementation(const FJMInteractionContext& Context) const
{
	return bInteractionEnabled && IsPrototypeInteractionAvailable(Context);
}

FJMInteractionResult AJMPrototypeInteractionActorBase::BeginInteract_Implementation(const FJMInteractionContext& Context)
{
	return CanInteract_Implementation(Context)
		? FJMInteractionResult::Success()
		: FJMInteractionResult::Failure(EJMInteractionResultCode::NotAllowed, LOCTEXT("Unavailable", "Interaction is not available."));
}

FJMInteractionResult AJMPrototypeInteractionActorBase::CompleteInteract_Implementation(const FJMInteractionContext& Context)
{
	if (!CanInteract_Implementation(Context))
	{
		return FJMInteractionResult::Failure(EJMInteractionResultCode::NotAllowed, LOCTEXT("CompleteUnavailable", "Interaction is not available."));
	}

	const FJMPrototypeOperationResult Result = PerformPrototypeInteraction(Context);
	OnPrototypeInteractionResolved(Result.bSucceeded, Result.Code, Result.Message);
	return Result.bSucceeded
		? FJMInteractionResult::Success(Result.Message)
		: FJMInteractionResult::Failure(EJMInteractionResultCode::NotAllowed, Result.Message);
}

void AJMPrototypeInteractionActorBase::CancelInteract_Implementation(const FJMInteractionContext& Context)
{
}

FJMInteractionPrompt AJMPrototypeInteractionActorBase::GetInteractionPrompt_Implementation(const FJMInteractionContext& Context) const
{
	FJMInteractionPrompt Prompt;
	Prompt.DisplayText = InteractionPrompt;
	Prompt.HoldDuration = InteractionDuration;
	Prompt.Priority = InteractionPriority;
	Prompt.bVisible = !InteractionPrompt.IsEmpty();
	return Prompt;
}

float AJMPrototypeInteractionActorBase::GetInteractionDuration_Implementation(const FJMInteractionContext& Context) const
{
	return FMath::Max(0.0f, InteractionDuration);
}

int32 AJMPrototypeInteractionActorBase::GetInteractionPriority_Implementation(const FJMInteractionContext& Context) const
{
	return InteractionPriority;
}

bool AJMPrototypeInteractionActorBase::IsPrototypeInteractionAvailable(const FJMInteractionContext& Context) const
{
	return IsValid(Context.InstigatorActor);
}

FJMPrototypeOperationResult AJMPrototypeInteractionActorBase::PerformPrototypeInteraction(const FJMInteractionContext& Context)
{
	return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidConfiguration, LOCTEXT("NoAction", "This prototype station has no action."));
}

#undef LOCTEXT_NAMESPACE
