#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InventoryProviderInterface.generated.h"

class UInventoryComponent;

UINTERFACE(BlueprintType)
class INVENTORYSYSTEM_API UInventoryProviderInterface : public UInterface
{
	GENERATED_BODY()
};

class INVENTORYSYSTEM_API IInventoryProviderInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Inventory")
	UInventoryComponent* GetInventoryComponent() const;
};
