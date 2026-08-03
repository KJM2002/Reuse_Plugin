#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Core/JMGameplayTypes.h"
#include "Interfaces/InventoryItemUseReceiverInterface.h"
#include "JMDoorInventoryAgentComponent.generated.h"

class AJMDoorActor;
class UInventoryComponent;
class UInventoryItemDefinition;
struct FInventorySlot;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJMPendingDoorChangedSignature, AJMDoorActor*, PendingDoor);

/** Add to any player Pawn/Character to route a key's Use button to a locked door. */
UCLASS(ClassGroup=(JMGameplay), BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class JMDOORGAMEPLAYINTEGRATION_API UJMDoorInventoryAgentComponent final
    : public UActorComponent
    , public IInventoryItemUseReceiverInterface
{
    GENERATED_BODY()

public:
    UJMDoorInventoryAgentComponent();

    UPROPERTY(BlueprintAssignable, Category="JM Door|Inventory")
    FJMPendingDoorChangedSignature OnPendingDoorChanged;

    UFUNCTION(BlueprintCallable, Category="JM Door|Inventory")
    bool BeginLockedDoorItemSelection(AJMDoorActor* Door, const FJMInteractionContext& InteractionContext);

    /** Stores a locked-door target without opening UI, for custom UI and automated flows. */
    UFUNCTION(BlueprintCallable, Category="JM Door|Inventory")
    bool SetPendingDoorForItemUse(AJMDoorActor* Door, const FJMInteractionContext& InteractionContext);

    UFUNCTION(BlueprintCallable, Category="JM Door|Inventory")
    void ClearPendingDoor();

    UFUNCTION(BlueprintPure, Category="JM Door|Inventory")
    AJMDoorActor* GetPendingDoor() const { return PendingDoor.Get(); }

    /** Explicit Blueprint path: connect any inventory item's Use event to this function. */
    UFUNCTION(BlueprintCallable, Category="JM Door|Inventory", meta=(DisplayName="Use Item On Pending Door"))
    bool UseItemOnPendingDoor(UInventoryItemDefinition* ItemDefinition, AActor* User = nullptr);

    virtual bool CanReceiveInventoryItemUse_Implementation(AActor* User, UInventoryComponent* Inventory, const FInventorySlot& Slot) const override;
    virtual bool ReceiveInventoryItemUse_Implementation(AActor* User, UInventoryComponent* Inventory, const FInventorySlot& Slot) override;

protected:
    class UInventoryUIComponent* ResolveInventoryUI() const;

    TWeakObjectPtr<AJMDoorActor> PendingDoor;
    FJMInteractionContext PendingInteractionContext;
};
