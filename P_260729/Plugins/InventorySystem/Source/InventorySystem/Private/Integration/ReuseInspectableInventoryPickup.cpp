#include "Integration/ReuseInspectableInventoryPickup.h"

#include "Engine/LocalPlayer.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "ItemInspection/JMInspectableComponent.h"
#include "ItemInspection/JMItemInspectionSubsystem.h"
#include "Items/InventoryItemDefinition.h"

AReuseInspectableInventoryPickup::AReuseInspectableInventoryPickup()
{
	PrimaryActorTick.bCanEverTick = false;
	InteractionPrompt = NSLOCTEXT("JMInventory", "InspectAndPickupPrompt", "E키를 눌러 조사");
}

void AReuseInspectableInventoryPickup::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	ClearInspectionBinding();
	Super::EndPlay(EndPlayReason);
}

bool AReuseInspectableInventoryPickup::CanInteract_Implementation(const FJMInteractionContext& Context) const
{
	if (!IsValid(ItemDefinition) || Quantity <= 0)
	{
		return false;
	}

	if (!bInspectBeforePickup)
	{
		return true;
	}

	const UJMInspectableComponent* Inspectable = FindInspectableComponent();
	return (Inspectable && Inspectable->CanInspect(Context)) || bFallbackToImmediatePickup;
}

FJMInteractionResult AReuseInspectableInventoryPickup::BeginInteract_Implementation(const FJMInteractionContext& Context)
{
	return IJMInteractableInterface::Execute_CanInteract(this, Context)
		? FJMInteractionResult::Success()
		: FJMInteractionResult::Failure(EJMInteractionResultCode::NotAllowed, NSLOCTEXT("BaseUpgrade", "InventoryPickupNotAvailable", "이 아이템을 획득할 수 없습니다."));
}

FJMInteractionResult AReuseInspectableInventoryPickup::CompleteInteract_Implementation(const FJMInteractionContext& Context)
{
	if (!IJMInteractableInterface::Execute_CanInteract(this, Context))
	{
		return FJMInteractionResult::Failure(EJMInteractionResultCode::NotAllowed, NSLOCTEXT("BaseUpgrade", "InventoryPickupCompleteNotAllowed", "이 아이템을 획득할 수 없습니다."));
	}

	if (bInspectBeforePickup)
	{
		if (UJMInspectableComponent* Inspectable = FindInspectableComponent())
		{
			if (UJMItemInspectionSubsystem* Subsystem = ResolveInspectionSubsystem(Context))
			{
				PendingInteractingActor = Context.InstigatorActor;
				ActiveInspectionSubsystem = Subsystem;
				Subsystem->OnInspectionClosed.AddUniqueDynamic(this, &AReuseInspectableInventoryPickup::HandleInspectionClosed);
				const FJMInteractionResult InspectionResult = Inspectable->TryOpenInspectionWithOptions(Context, true);
				if (InspectionResult.bSucceeded)
				{
					return InspectionResult;
				}
				ClearInspectionBinding();
				if (!bFallbackToImmediatePickup)
				{
					return InspectionResult;
				}
			}
			else if (!bFallbackToImmediatePickup)
			{
				return FJMInteractionResult::Failure(EJMInteractionResultCode::Failed, NSLOCTEXT("BaseUpgrade", "InventoryPickupInspectorSubsystemMissing", "아이템 조사 시스템을 찾을 수 없습니다."));
			}
		}
		else if (!bFallbackToImmediatePickup)
		{
			return FJMInteractionResult::Failure(EJMInteractionResultCode::Failed, NSLOCTEXT("BaseUpgrade", "InventoryPickupInspectableMissing", "JMInspectableComponent가 필요합니다."));
		}
	}

	return TryPickup(Context.InstigatorActor)
		? FJMInteractionResult::Success(NSLOCTEXT("BaseUpgrade", "InventoryPickupSucceeded", "아이템을 획득했습니다."))
		: FJMInteractionResult::Failure(EJMInteractionResultCode::Failed, NSLOCTEXT("BaseUpgrade", "InventoryPickupFailed", "인벤토리에 아이템을 추가하지 못했습니다."));
}

void AReuseInspectableInventoryPickup::CancelInteract_Implementation(const FJMInteractionContext& Context)
{
}

FJMInteractionPrompt AReuseInspectableInventoryPickup::GetInteractionPrompt_Implementation(const FJMInteractionContext& Context) const
{
	FJMInteractionPrompt Prompt;
	Prompt.DisplayText = InteractionPrompt;
	Prompt.Priority = InteractionPriority;
	Prompt.HoldDuration = 0.0f;
	Prompt.bVisible = IJMInteractableInterface::Execute_CanInteract(this, Context);
	return Prompt;
}

float AReuseInspectableInventoryPickup::GetInteractionDuration_Implementation(const FJMInteractionContext& Context) const
{
	return 0.0f;
}

int32 AReuseInspectableInventoryPickup::GetInteractionPriority_Implementation(const FJMInteractionContext& Context) const
{
	return InteractionPriority;
}

UJMInspectableComponent* AReuseInspectableInventoryPickup::FindInspectableComponent() const
{
	return FindComponentByClass<UJMInspectableComponent>();
}

UJMItemInspectionSubsystem* AReuseInspectableInventoryPickup::ResolveInspectionSubsystem(const FJMInteractionContext& Context) const
{
	APlayerController* PlayerController = Cast<APlayerController>(Context.InstigatorController);
	if (!PlayerController)
	{
		if (const APawn* Pawn = Cast<APawn>(Context.InstigatorActor))
		{
			PlayerController = Cast<APlayerController>(Pawn->GetController());
		}
	}
	if (!PlayerController)
	{
		PlayerController = Cast<APlayerController>(Context.InstigatorActor);
	}

	ULocalPlayer* LocalPlayer = PlayerController ? PlayerController->GetLocalPlayer() : nullptr;
	return LocalPlayer ? LocalPlayer->GetSubsystem<UJMItemInspectionSubsystem>() : nullptr;
}

void AReuseInspectableInventoryPickup::ClearInspectionBinding()
{
	if (UJMItemInspectionSubsystem* Subsystem = ActiveInspectionSubsystem.Get())
	{
		Subsystem->OnInspectionClosed.RemoveDynamic(this, &AReuseInspectableInventoryPickup::HandleInspectionClosed);
	}
	ActiveInspectionSubsystem.Reset();
	PendingInteractingActor.Reset();
}

void AReuseInspectableInventoryPickup::HandleInspectionClosed(EJMItemInspectionCloseReason Reason)
{
	AActor* InteractingActor = PendingInteractingActor.Get();
	const bool bShouldPickup = bPickupAfterInspection
		&& (Reason == EJMItemInspectionCloseReason::User
			|| Reason == EJMItemInspectionCloseReason::CloseButton
			|| Reason == EJMItemInspectionCloseReason::ExternalRequest);
	ClearInspectionBinding();

	if (bShouldPickup && IsValid(InteractingActor))
	{
		TryPickup(InteractingActor);
	}
}
