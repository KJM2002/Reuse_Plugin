#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interaction/JMInteractableInterface.h"
#include "InventoryWorldItemPickup.generated.h"

class UInventoryComponent;
class UInventoryItemDefinition;
class USceneComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class INVENTORYSYSTEM_API AInventoryWorldItemPickup : public AActor, public IJMInteractableInterface
{
	GENERATED_BODY()

public:
	AInventoryWorldItemPickup();

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TObjectPtr<USceneComponent> SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TObjectPtr<UStaticMeshComponent> ItemMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory")
	TObjectPtr<UInventoryItemDefinition> ItemDefinition = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (ClampMin = "1"))
	int32 Quantity = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Interaction")
	FText PickupInteractionPrompt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Interaction")
	int32 PickupInteractionPriority = 10;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void InitializePickup(UInventoryItemDefinition* InItemDefinition, int32 InQuantity = 1);

	/** 현재 Mesh Bounds의 최하단이 바닥에 닿도록 Actor 높이를 보정한다. */
	UFUNCTION(BlueprintCallable, Category = "Inventory|World")
	bool SnapToGround();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|World")
	bool bSnapToGroundWhenDropped = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|World", meta = (ClampMin = "0.0"))
	float GroundClearance = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool TryPickup(AActor* InteractingActor);

	virtual bool CanInteract_Implementation(const FJMInteractionContext& Context) const override;
	virtual FJMInteractionResult BeginInteract_Implementation(const FJMInteractionContext& Context) override;
	virtual FJMInteractionResult CompleteInteract_Implementation(const FJMInteractionContext& Context) override;
	virtual void CancelInteract_Implementation(const FJMInteractionContext& Context) override;
	virtual FJMInteractionPrompt GetInteractionPrompt_Implementation(const FJMInteractionContext& Context) const override;
	virtual float GetInteractionDuration_Implementation(const FJMInteractionContext& Context) const override;
	virtual int32 GetInteractionPriority_Implementation(const FJMInteractionContext& Context) const override;

	UFUNCTION(BlueprintNativeEvent, Category = "Inventory")
	void OnPickupStateChanged();
	virtual void OnPickupStateChanged_Implementation();

protected:
	UInventoryComponent* ResolveInventory(AActor* InteractingActor) const;
	void RefreshMesh();
};
