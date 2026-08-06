#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Prototype/JMPrototypeTypes.h"
#include "JMPrototypePickupSpawner.generated.h"

class AInventoryWorldItemPickup;
class UInventoryItemDefinition;
class USceneComponent;
class UStaticMesh;

/** Persistent level marker that replenishes a collected resource for every new expedition. */
UCLASS(Blueprintable)
class P_060715_API AJMPrototypePickupSpawner : public AActor
{
	GENERATED_BODY()

public:
	AJMPrototypePickupSpawner();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Prototype|Pickup")
	TObjectPtr<USceneComponent> SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prototype|Pickup")
	TObjectPtr<UInventoryItemDefinition> ItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prototype|Pickup", meta = (ClampMin = "1"))
	int32 Quantity = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prototype|Pickup|Visual")
	TObjectPtr<UStaticMesh> PickupMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prototype|Pickup|Visual")
	FVector PickupMeshScale = FVector(0.35f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prototype|Pickup|Interaction")
	FText PickupPrompt;

	UFUNCTION(BlueprintCallable, Category = "Prototype|Pickup")
	AInventoryWorldItemPickup* ReplenishPickup();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	UFUNCTION()
	void HandleRunStateChanged(EJMPrototypeRunState PreviousState, EJMPrototypeRunState NewState);

	UPROPERTY(Transient)
	TObjectPtr<AInventoryWorldItemPickup> SpawnedPickup;
};
