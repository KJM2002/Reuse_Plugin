#include "Prototype/JMPrototypeRunResetComponent.h"

#include "Components/InventoryComponent.h"
#include "Engine/GameInstance.h"
#include "Items/InventoryItemDefinition.h"
#include "Kismet/GameplayStatics.h"
#include "Prototype/JMPrototypeInventoryResolver.h"
#include "Prototype/JMPrototypeProgressionSubsystem.h"

#define LOCTEXT_NAMESPACE "JMPrototypeRunReset"

UJMPrototypeRunResetComponent::UJMPrototypeRunResetComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FJMPrototypeOperationResult UJMPrototypeRunResetComponent::FailCurrentRun()
{
	AActor* Owner = GetOwner();
	if (!IsValid(Owner) || (FailureLevelName.IsNone() && !IsValid(BaseRespawnTarget)))
	{
		const FJMPrototypeOperationResult Result = FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::MissingDestination, LOCTEXT("MissingRespawn", "Base respawn target is not configured."));
		OnRunResetCompleted(Result);
		return Result;
	}

	if (UInventoryComponent* Inventory = JMPrototypeInventory::Resolve(Owner))
	{
		for (UInventoryItemDefinition* Item : RunOnlyItems)
		{
			if (IsValid(Item))
			{
				const int32 Quantity = Inventory->GetItemQuantity(Item);
				if (Quantity > 0)
				{
					Inventory->RemoveItem(Item, Quantity);
				}
			}
		}
	}

	UGameInstance* GameInstance = GetWorld() ? GetWorld()->GetGameInstance() : nullptr;
	UJMPrototypeProgressionSubsystem* Progression = GameInstance ? GameInstance->GetSubsystem<UJMPrototypeProgressionSubsystem>() : nullptr;
	if (Progression)
	{
		Progression->ResetCurrentRun();
	}
	if (!FailureLevelName.IsNone())
	{
		if (Progression)
		{
			Progression->MarkLevelTravelPending();
		}
		UGameplayStatics::OpenLevel(this, FailureLevelName);
		const FJMPrototypeOperationResult Result = FJMPrototypeOperationResult::Success(LOCTEXT("RunResetTravel", "The run was reset and the player returned to base."));
		OnRunResetCompleted(Result);
		return Result;
	}

	const bool bTeleported = Owner->TeleportTo(BaseRespawnTarget->GetActorLocation(), BaseRespawnTarget->GetActorRotation(), false, true);
	const FJMPrototypeOperationResult Result = bTeleported
		? FJMPrototypeOperationResult::Success(LOCTEXT("RunReset", "The run was reset."))
		: FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::TravelFailed, LOCTEXT("RespawnFailed", "The player could not return to the base."));
	OnRunResetCompleted(Result);
	return Result;
}

#undef LOCTEXT_NAMESPACE
