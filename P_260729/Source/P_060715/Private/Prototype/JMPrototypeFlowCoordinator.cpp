#include "Prototype/JMPrototypeFlowCoordinator.h"

#include "Engine/GameInstance.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Prototype/JMPrototypeInventoryResolver.h"
#include "Prototype/JMPrototypeProgressionSubsystem.h"

AJMPrototypeFlowCoordinator::AJMPrototypeFlowCoordinator()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AJMPrototypeFlowCoordinator::BeginPlay()
{
	Super::BeginPlay();
	UJMPrototypeProgressionSubsystem* Progression = GetGameInstance() ? GetGameInstance()->GetSubsystem<UJMPrototypeProgressionSubsystem>() : nullptr;
	if (!Progression)
	{
		OnPrototypeConfigured(FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidConfiguration, FText::FromString(TEXT("Prototype progression subsystem is unavailable."))));
		return;
	}
	if (Progression->IsConfigured())
	{
		// A configured subsystem without an intentional OpenLevel marker is a fresh
		// play session (or a restarted PIE session), not an in-progress expedition.
		if (!Progression->ConsumeLevelTravelPending())
		{
			FJMPrototypeOperationResult Result = Progression->ConfigurePrototype(PrototypeConfig, bResetPermanentProgressOnBeginPlay);
			if (Result.bSucceeded && bApplyCapacityToPlayerInventory)
			{
				if (ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0))
				{
					Result = Progression->ApplyOwnedInventoryCapacity(JMPrototypeInventory::Resolve(PlayerCharacter));
				}
			}
			OnPrototypeConfigured(Result);
			return;
		}
		if (bApplyCapacityToPlayerInventory)
		{
			if (ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0))
			{
				Progression->ApplyOwnedInventoryCapacity(JMPrototypeInventory::Resolve(PlayerCharacter));
			}
		}
		OnPrototypeConfigured(FJMPrototypeOperationResult::Success());
		return;
	}

	FJMPrototypeOperationResult Result = Progression->ConfigurePrototype(PrototypeConfig, bResetPermanentProgressOnBeginPlay);
	if (Result.bSucceeded && bApplyCapacityToPlayerInventory)
	{
		ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
		if (UInventoryComponent* Inventory = JMPrototypeInventory::Resolve(PlayerCharacter))
		{
			Result = Progression->ApplyOwnedInventoryCapacity(Inventory);
		}
	}
	OnPrototypeConfigured(Result);
}
