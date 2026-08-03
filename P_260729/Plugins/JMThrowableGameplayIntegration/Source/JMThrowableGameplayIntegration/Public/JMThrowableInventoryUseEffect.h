#pragma once

#include "CoreMinimal.h"
#include "Items/InventoryItemUseEffect.h"
#include "JMThrowableInventoryUseEffect.generated.h"

class UJMThrowableDefinition;

UCLASS(BlueprintType, EditInlineNew, DefaultToInstanced)
class JMTHROWABLEGAMEPLAYINTEGRATION_API UJMThrowableInventoryUseEffect : public UInventoryItemUseEffect
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Throwable")
    TObjectPtr<UJMThrowableDefinition> ThrowableDefinition;
    virtual bool CanUse_Implementation(AActor* User, const FInventorySlot& Slot) const override;
    virtual bool ExecuteUse_Implementation(AActor* User, UInventoryComponent* Inventory, const FInventorySlot& Slot) override;
};
