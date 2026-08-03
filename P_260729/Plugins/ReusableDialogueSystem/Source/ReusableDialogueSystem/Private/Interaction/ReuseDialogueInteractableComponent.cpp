#include "Interaction/ReuseDialogueInteractableComponent.h"

#include "DialogueAssets.h"
#include "DialogueSubsystem.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"

UReuseDialogueInteractableComponent::UReuseDialogueInteractableComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	InteractionPrompt = NSLOCTEXT("JMDialogue", "DialogueInteractionPrompt", "E키를 눌러 대화");
}

void UReuseDialogueInteractableComponent::ResetInteraction()
{
	bHasStartedDialogue = false;
}

bool UReuseDialogueInteractableComponent::CanInteract_Implementation(const FJMInteractionContext& Context) const
{
	if (!bInteractionEnabled || DialogueSequence.IsNull() || (!bAllowRepeat && bHasStartedDialogue))
	{
		return false;
	}

	const UDialogueSubsystem* Subsystem = ResolveDialogueSubsystem();
	if (!Subsystem)
	{
		return false;
	}

	return !Subsystem->IsDialogueActive() || ExistingDialoguePolicy == EExistingDialoguePolicy::ReplaceCurrent;
}

FJMInteractionResult UReuseDialogueInteractableComponent::BeginInteract_Implementation(const FJMInteractionContext& Context)
{
	return IJMInteractableInterface::Execute_CanInteract(this, Context)
		? FJMInteractionResult::Success()
		: FJMInteractionResult::Failure(
			EJMInteractionResultCode::NotAllowed,
			NSLOCTEXT("BaseUpgrade", "DialogueInteractionNotAllowed", "지금은 대화를 시작할 수 없습니다."));
}

FJMInteractionResult UReuseDialogueInteractableComponent::CompleteInteract_Implementation(const FJMInteractionContext& Context)
{
	if (!IJMInteractableInterface::Execute_CanInteract(this, Context))
	{
		return FJMInteractionResult::Failure(
			EJMInteractionResultCode::NotAllowed,
			NSLOCTEXT("BaseUpgrade", "DialogueInteractionCompleteNotAllowed", "지금은 대화를 시작할 수 없습니다."));
	}

	UDialogueSequence* Sequence = DialogueSequence.LoadSynchronous();
	if (!IsValid(Sequence))
	{
		return FJMInteractionResult::Failure(
			EJMInteractionResultCode::TargetInvalid,
			NSLOCTEXT("BaseUpgrade", "DialogueSequenceLoadFailed", "Dialogue Sequence를 불러오지 못했습니다."));
	}

	UDialogueSubsystem* Subsystem = ResolveDialogueSubsystem();
	if (!Subsystem)
	{
		return FJMInteractionResult::Failure(
			EJMInteractionResultCode::Failed,
			NSLOCTEXT("BaseUpgrade", "DialogueSubsystemMissing", "Dialogue Subsystem을 찾을 수 없습니다."));
	}

	if (!Subsystem->StartDialogue(Sequence, InteractionMode, ResolvePlayerController(Context), ExistingDialoguePolicy))
	{
		return FJMInteractionResult::Failure(
			EJMInteractionResultCode::Failed,
			NSLOCTEXT("BaseUpgrade", "DialogueStartFailed", "Dialogue를 시작하지 못했습니다. 위젯과 시퀀스 설정을 확인하세요."));
	}

	bHasStartedDialogue = true;
	return FJMInteractionResult::Success(NSLOCTEXT("BaseUpgrade", "DialogueStarted", "Dialogue를 시작했습니다."));
}

void UReuseDialogueInteractableComponent::CancelInteract_Implementation(const FJMInteractionContext& Context)
{
}

FJMInteractionPrompt UReuseDialogueInteractableComponent::GetInteractionPrompt_Implementation(const FJMInteractionContext& Context) const
{
	FJMInteractionPrompt Prompt;
	Prompt.DisplayText = InteractionPrompt;
	Prompt.HoldDuration = FMath::Max(InteractionDuration, 0.0f);
	Prompt.Priority = InteractionPriority;
	Prompt.bVisible = IJMInteractableInterface::Execute_CanInteract(this, Context);
	return Prompt;
}

float UReuseDialogueInteractableComponent::GetInteractionDuration_Implementation(const FJMInteractionContext& Context) const
{
	return FMath::Max(InteractionDuration, 0.0f);
}

int32 UReuseDialogueInteractableComponent::GetInteractionPriority_Implementation(const FJMInteractionContext& Context) const
{
	return InteractionPriority;
}

UDialogueSubsystem* UReuseDialogueInteractableComponent::ResolveDialogueSubsystem() const
{
	const UWorld* World = GetWorld();
	UGameInstance* GameInstance = World ? World->GetGameInstance() : nullptr;
	return GameInstance ? GameInstance->GetSubsystem<UDialogueSubsystem>() : nullptr;
}

APlayerController* UReuseDialogueInteractableComponent::ResolvePlayerController(const FJMInteractionContext& Context) const
{
	if (APlayerController* PlayerController = Cast<APlayerController>(Context.InstigatorController))
	{
		return PlayerController;
	}

	if (const APawn* Pawn = Cast<APawn>(Context.InstigatorActor))
	{
		return Cast<APlayerController>(Pawn->GetController());
	}

	return Cast<APlayerController>(Context.InstigatorActor);
}
