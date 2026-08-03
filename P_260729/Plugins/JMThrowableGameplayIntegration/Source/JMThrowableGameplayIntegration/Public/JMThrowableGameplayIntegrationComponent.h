#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryTypes.h"
#include "JMThrowableInventoryContext.h"
#include "JMThrowableTypes.h"
#include "JMThrowableGameplayIntegrationComponent.generated.h"

class UInputAction;
class UInputMappingContext;
class UInventoryComponent;
class UInventoryItemDefinition;
class UJMThrowableDefinition;
class UJMThrowableInteractorComponent;
class UJMThrowableStatusWidget;

UCLASS(ClassGroup=(JM), Blueprintable, meta=(BlueprintSpawnableComponent))
class JMTHROWABLEGAMEPLAYINTEGRATION_API UJMThrowableGameplayIntegrationComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UJMThrowableGameplayIntegrationComponent();
    virtual void EndPlay(const EEndPlayReason::Type Reason) override;

    bool BeginThrowableItemUse(UInventoryComponent* Inventory, const FInventorySlot& Slot, UJMThrowableDefinition* Definition);
    UFUNCTION(BlueprintCallable, Category="JM Throwable") void NotifyInventoryOpening();
    UFUNCTION(BlueprintNativeEvent, Category="JM Throwable|Movement") void RequestCancelSprint();
    virtual void RequestCancelSprint_Implementation();

private:
    UPROPERTY(Transient) FJMThrowableInventoryContext InventoryContext;
    UPROPERTY(Transient) TObjectPtr<UJMThrowableInteractorComponent> Interactor;
    UPROPERTY(Transient) TObjectPtr<UInputMappingContext> MappingContext;
    UPROPERTY(Transient) TObjectPtr<UInputAction> AimAction;
    UPROPERTY(Transient) TObjectPtr<UInputAction> ThrowAction;
    UPROPERTY(Transient) TObjectPtr<UInputAction> CancelAction;
    UPROPERTY(Transient) TObjectPtr<UJMThrowableStatusWidget> StatusWidget;
    float SavedMaxWalkSpeed = 0.f;
    bool bMovementModified = false;

    bool CommitInventory(const FGuid& SessionId);
    void HandleSessionEnded(const FGuid& SessionId);
    UFUNCTION() void HandleInventoryChanged();
    UFUNCTION() void HandleStateChanged(EJMThrowableUseState NewState);
    void InstallInput();
    void RemoveInput();
    void ApplyMovementRestriction();
    void RestoreMovementRestriction();
    void ShowStatusWidget();
    void HideStatusWidget();
    void CloseInventoryUI();
    void AimPressed();
    void AimReleased();
    void ThrowPressed();
    void CancelPressed();
};
