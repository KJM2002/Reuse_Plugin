#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventoryContainerActor.generated.h"

class UInventoryContainerComponent;
class UJMInteractableComponent;
class USceneComponent;
class UStaticMeshComponent;
struct FJMInteractionContext;

/** Reusable base actor for boxes, cabinets, corpses, safes, vehicles and other loot sources. */
UCLASS(Blueprintable)
class INVENTORYSYSTEM_API AInventoryContainerActor : public AActor
{
	GENERATED_BODY()

public:
	AInventoryContainerActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory|Container")
	TObjectPtr<USceneComponent> SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory|Container")
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory|Container")
	TObjectPtr<UInventoryContainerComponent> Container;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory|Interaction")
	TObjectPtr<UJMInteractableComponent> Interaction;

	UFUNCTION(BlueprintCallable, Category = "Inventory|Container")
	bool OpenFor(AActor* InteractingActor);

protected:
	UFUNCTION()
	void HandleInteracted(const FJMInteractionContext& Context);
};
