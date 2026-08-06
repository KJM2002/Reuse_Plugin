#pragma once

#include "Components/InventoryComponent.h"
#include "Interfaces/InventoryProviderInterface.h"

namespace JMPrototypeInventory
{
	inline UInventoryComponent* Resolve(AActor* Actor)
	{
		if (!IsValid(Actor))
		{
			return nullptr;
		}
		if (Actor->GetClass()->ImplementsInterface(UInventoryProviderInterface::StaticClass()))
		{
			if (UInventoryComponent* Provided = IInventoryProviderInterface::Execute_GetInventoryComponent(Actor))
			{
				return Provided;
			}
		}
		return Actor->FindComponentByClass<UInventoryComponent>();
	}
}
