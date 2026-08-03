#include "JMThrowableInventoryUseEffect.h"
#include "JMThrowableGameplayIntegrationComponent.h"
#include "JMThrowableDefinition.h"
#include "JMThrowableProjectile.h"
#include "Components/InventoryComponent.h"
#include "GameFramework/Actor.h"

bool UJMThrowableInventoryUseEffect::CanUse_Implementation(AActor* User, const FInventorySlot& Slot) const
{
    return IsValid(User) && IsValid(ThrowableDefinition) && ThrowableDefinition->ProjectileClass
        && Slot.IsValid() && IsValid(User->FindComponentByClass<UJMThrowableGameplayIntegrationComponent>());
}

bool UJMThrowableInventoryUseEffect::ExecuteUse_Implementation(AActor* User, UInventoryComponent* Inventory, const FInventorySlot& Slot)
{
    UJMThrowableGameplayIntegrationComponent* Integration =
        IsValid(User) ? User->FindComponentByClass<UJMThrowableGameplayIntegrationComponent>() : nullptr;
    return Integration && Integration->BeginThrowableItemUse(Inventory, Slot, ThrowableDefinition);
}
