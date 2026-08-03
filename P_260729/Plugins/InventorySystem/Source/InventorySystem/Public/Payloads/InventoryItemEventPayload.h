#pragma once

#include "CoreMinimal.h"
#include "Payloads/JMGameplayEventPayloadBase.h"
#include "InventoryItemEventPayload.generated.h"

class UInventoryItemDefinition;

UCLASS(BlueprintType)
class INVENTORYSYSTEM_API UInventoryItemEventPayload : public UJMGameplayEventPayloadBase
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadOnly, Category = "Inventory|Events")
    TObjectPtr<UInventoryItemDefinition> ItemDefinition = nullptr;

    UPROPERTY(BlueprintReadOnly, Category = "Inventory|Events")
    int32 Quantity = 0;

    UPROPERTY(BlueprintReadOnly, Category = "Inventory|Events")
    int32 TotalQuantityAfter = 0;

    UPROPERTY(BlueprintReadOnly, Category = "Inventory|Events")
    TObjectPtr<AActor> InventoryOwner = nullptr;

    UPROPERTY(BlueprintReadOnly, Category = "Inventory|Events")
    int32 SlotIndex = INDEX_NONE;
};
