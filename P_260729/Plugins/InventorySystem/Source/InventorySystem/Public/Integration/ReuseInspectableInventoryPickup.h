#pragma once

#include "CoreMinimal.h"
#include "Interaction/JMInteractableInterface.h"
#include "ItemInspection/JMItemInspectionTypes.h"
#include "World/InventoryWorldItemPickup.h"
#include "ReuseInspectableInventoryPickup.generated.h"

class UJMInspectableComponent;
class UJMItemInspectionSubsystem;

/**
 * InventorySystem과 ItemInspector의 연결을 이 Actor 하나에만 모은 Adapter다.
 * JMInspectableComponent가 있으면 조사 후 닫을 때 획득하고, 없으면 즉시 획득한다.
 */
UCLASS(Blueprintable)
class INVENTORYSYSTEM_API AReuseInspectableInventoryPickup : public AInventoryWorldItemPickup
{
	GENERATED_BODY()

public:
	AReuseInspectableInventoryPickup();

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Interaction")
	FText InteractionPrompt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Interaction")
	int32 InteractionPriority = 10;

	/** JMInspectableComponent가 있으면 먼저 조사 화면을 연다. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Inspection")
	bool bInspectBeforePickup = true;

	/** 정상적으로 조사 화면을 닫으면 아이템을 인벤토리에 추가한다. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Inspection", meta = (EditCondition = "bInspectBeforePickup"))
	bool bPickupAfterInspection = true;

	/** Inspector가 없거나 열기에 실패하면 일반 Pickup으로 동작한다. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Inspection")
	bool bFallbackToImmediatePickup = true;

	virtual bool CanInteract_Implementation(const FJMInteractionContext& Context) const override;
	virtual FJMInteractionResult BeginInteract_Implementation(const FJMInteractionContext& Context) override;
	virtual FJMInteractionResult CompleteInteract_Implementation(const FJMInteractionContext& Context) override;
	virtual void CancelInteract_Implementation(const FJMInteractionContext& Context) override;
	virtual FJMInteractionPrompt GetInteractionPrompt_Implementation(const FJMInteractionContext& Context) const override;
	virtual float GetInteractionDuration_Implementation(const FJMInteractionContext& Context) const override;
	virtual int32 GetInteractionPriority_Implementation(const FJMInteractionContext& Context) const override;

protected:
	UJMInspectableComponent* FindInspectableComponent() const;
	UJMItemInspectionSubsystem* ResolveInspectionSubsystem(const FJMInteractionContext& Context) const;
	void ClearInspectionBinding();

	UFUNCTION()
	void HandleInspectionClosed(EJMItemInspectionCloseReason Reason);

	TWeakObjectPtr<AActor> PendingInteractingActor;
	TWeakObjectPtr<UJMItemInspectionSubsystem> ActiveInspectionSubsystem;
};
