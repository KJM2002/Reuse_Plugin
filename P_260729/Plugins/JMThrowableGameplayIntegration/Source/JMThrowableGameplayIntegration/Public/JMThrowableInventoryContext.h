#pragma once

#include "CoreMinimal.h"
#include "JMThrowableInventoryContext.generated.h"

class UInventoryComponent;
class UInventoryItemDefinition;
class UJMThrowableDefinition;

USTRUCT(BlueprintType)
struct JMTHROWABLEGAMEPLAYINTEGRATION_API FJMThrowableInventoryContext
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadOnly) TWeakObjectPtr<UInventoryComponent> InventoryComponent;
    UPROPERTY(BlueprintReadOnly) TObjectPtr<UInventoryItemDefinition> ItemDefinition = nullptr;
    UPROPERTY(BlueprintReadOnly) TObjectPtr<UJMThrowableDefinition> ThrowableDefinition = nullptr;
    UPROPERTY(BlueprintReadOnly) int32 SlotIndex = INDEX_NONE;
    UPROPERTY(BlueprintReadOnly) FGuid EntryHandle;
    UPROPERTY(BlueprintReadOnly) int32 RequestedQuantity = 1;
    UPROPERTY(BlueprintReadOnly) FGuid SessionId;
};
