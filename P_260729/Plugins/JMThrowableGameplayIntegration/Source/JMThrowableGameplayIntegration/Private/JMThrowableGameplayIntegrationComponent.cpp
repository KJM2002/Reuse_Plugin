#include "JMThrowableGameplayIntegrationComponent.h"
#include "JMThrowableInteractorComponent.h"
#include "JMThrowableDefinition.h"
#include "JMThrowableSettings.h"
#include "JMThrowableStatusWidget.h"
#include "Components/InventoryComponent.h"
#include "Components/InventoryUIComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "InputAction.h"
#include "InputMappingContext.h"

UJMThrowableGameplayIntegrationComponent::UJMThrowableGameplayIntegrationComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UJMThrowableGameplayIntegrationComponent::EndPlay(const EEndPlayReason::Type Reason)
{
    if (Interactor) Interactor->CancelItemUse();
    RemoveInput();
    RestoreMovementRestriction();
    Super::EndPlay(Reason);
}

bool UJMThrowableGameplayIntegrationComponent::BeginThrowableItemUse(UInventoryComponent* Inventory, const FInventorySlot& Slot, UJMThrowableDefinition* Definition)
{
    if (!IsValid(Inventory) || !Slot.IsValid() || !Slot.InstanceId.IsValid() || !IsValid(Definition)) return false;
    Interactor = GetOwner()->FindComponentByClass<UJMThrowableInteractorComponent>();
    if (!Interactor) return false;
    if (Interactor->GetUseState() != EJMThrowableUseState::Idle) Interactor->CancelItemUse();

    int32 SlotIndex = INDEX_NONE;
    const TArray<FInventorySlot>& Slots = Inventory->GetSlotsNative();
    for (int32 Index = 0; Index < Slots.Num(); ++Index)
        if (Slots[Index].InstanceId == Slot.InstanceId) { SlotIndex = Index; break; }
    if (SlotIndex == INDEX_NONE) return false;

    FJMThrowableUseContext Use;
    Use.User = GetOwner();
    Use.Definition = Definition;
    if (!Interactor->BeginItemUse(Use)) return false;

    InventoryContext.InventoryComponent = Inventory;
    InventoryContext.ItemDefinition = Slot.ItemDefinition;
    InventoryContext.ThrowableDefinition = Definition;
    InventoryContext.SlotIndex = SlotIndex;
    InventoryContext.EntryHandle = Slot.InstanceId;
    InventoryContext.SessionId = Interactor->GetSessionId();
    Interactor->CommitDelegate.BindUObject(this, &ThisClass::CommitInventory);
    Interactor->SessionEndedDelegate.BindUObject(this, &ThisClass::HandleSessionEnded);
    Interactor->OnStateChanged.AddUniqueDynamic(this, &ThisClass::HandleStateChanged);
    Inventory->OnInventoryChanged.AddUniqueDynamic(this, &ThisClass::HandleInventoryChanged);
    InstallInput();
    ShowStatusWidget();
    CloseInventoryUI();
    // Inventory Use now enters the authored aiming flow immediately. RMB remains
    // useful after a release returns the session to Ready.
    Interactor->BeginAim();
    return true;
}

bool UJMThrowableGameplayIntegrationComponent::CommitInventory(const FGuid& SessionId)
{
    if (SessionId != InventoryContext.SessionId) return false;
    UInventoryComponent* Inventory = InventoryContext.InventoryComponent.Get();
    FInventorySlot Current;
    if (!Inventory || !Inventory->GetSlot(InventoryContext.SlotIndex, Current)
        || Current.InstanceId != InventoryContext.EntryHandle
        || Current.ItemDefinition != InventoryContext.ItemDefinition || Current.Quantity < 1) return false;
    return Inventory->RemoveItemAtSlot(InventoryContext.SlotIndex, 1) == EInventoryOperationResult::Success;
}

void UJMThrowableGameplayIntegrationComponent::HandleSessionEnded(const FGuid& SessionId)
{
    if (SessionId != InventoryContext.SessionId) return;
    if (UInventoryComponent* Inventory = InventoryContext.InventoryComponent.Get())
        Inventory->OnInventoryChanged.RemoveDynamic(this, &ThisClass::HandleInventoryChanged);
    if (Interactor) Interactor->OnStateChanged.RemoveDynamic(this, &ThisClass::HandleStateChanged);
    RemoveInput();
    RestoreMovementRestriction();
    HideStatusWidget();
    InventoryContext = FJMThrowableInventoryContext();
}

void UJMThrowableGameplayIntegrationComponent::HandleInventoryChanged()
{
    UInventoryComponent* Inventory = InventoryContext.InventoryComponent.Get();
    FInventorySlot Current;
    if (!Inventory || !Inventory->GetSlot(InventoryContext.SlotIndex, Current)
        || Current.InstanceId != InventoryContext.EntryHandle
        || Current.ItemDefinition != InventoryContext.ItemDefinition)
        if (Interactor) Interactor->CancelItemUse();
}

void UJMThrowableGameplayIntegrationComponent::NotifyInventoryOpening()
{
    if (Interactor) Interactor->CancelItemUse();
}

void UJMThrowableGameplayIntegrationComponent::HandleStateChanged(EJMThrowableUseState NewState)
{
    if (StatusWidget) StatusWidget->SetThrowableState(NewState);
    if (NewState == EJMThrowableUseState::Aiming) ApplyMovementRestriction();
    else RestoreMovementRestriction();
}

void UJMThrowableGameplayIntegrationComponent::InstallInput()
{
    APawn* Pawn = Cast<APawn>(GetOwner());
    APlayerController* PC = Pawn ? Cast<APlayerController>(Pawn->GetController()) : nullptr;
    UEnhancedInputLocalPlayerSubsystem* Subsystem = PC && PC->GetLocalPlayer()
        ? PC->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>() : nullptr;
    UEnhancedInputComponent* Input = Pawn ? Pawn->FindComponentByClass<UEnhancedInputComponent>() : nullptr;
    if (!Subsystem || !Input || MappingContext) return;
    const UJMThrowableSettings* Settings = GetDefault<UJMThrowableSettings>();
    MappingContext = NewObject<UInputMappingContext>(this);
    AimAction = NewObject<UInputAction>(this);
    ThrowAction = NewObject<UInputAction>(this);
    CancelAction = NewObject<UInputAction>(this);
    AimAction->ValueType = EInputActionValueType::Boolean;
    ThrowAction->ValueType = EInputActionValueType::Boolean;
    CancelAction->ValueType = EInputActionValueType::Boolean;
    MappingContext->MapKey(AimAction, Settings->DefaultAimKey);
    MappingContext->MapKey(ThrowAction, Settings->DefaultThrowKey);
    MappingContext->MapKey(CancelAction, Settings->DefaultCancelKey);
    Input->BindAction(AimAction, ETriggerEvent::Started, this, &ThisClass::AimPressed);
    Input->BindAction(AimAction, ETriggerEvent::Completed, this, &ThisClass::AimReleased);
    Input->BindAction(ThrowAction, ETriggerEvent::Started, this, &ThisClass::ThrowPressed);
    Input->BindAction(CancelAction, ETriggerEvent::Started, this, &ThisClass::CancelPressed);
    Subsystem->AddMappingContext(MappingContext, Settings->InputPriority);
}

void UJMThrowableGameplayIntegrationComponent::RemoveInput()
{
    APawn* Pawn = Cast<APawn>(GetOwner());
    APlayerController* PC = Pawn ? Cast<APlayerController>(Pawn->GetController()) : nullptr;
    if (UEnhancedInputComponent* Input = Pawn ? Pawn->FindComponentByClass<UEnhancedInputComponent>() : nullptr)
        Input->ClearBindingsForObject(this);
    if (MappingContext && PC && PC->GetLocalPlayer())
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = PC->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
            Subsystem->RemoveMappingContext(MappingContext);
    MappingContext = nullptr;
    AimAction = nullptr;
    ThrowAction = nullptr;
    CancelAction = nullptr;
}

void UJMThrowableGameplayIntegrationComponent::ApplyMovementRestriction()
{
    const UJMThrowableSettings* Settings = GetDefault<UJMThrowableSettings>();
    ACharacter* Character = Cast<ACharacter>(GetOwner());
    UCharacterMovementComponent* Movement = Character ? Character->GetCharacterMovement() : nullptr;
    if (Settings->bCancelSprintOnAim) RequestCancelSprint();
    if (Settings->bRestrictMovementWhileAiming && Movement && !bMovementModified)
    {
        SavedMaxWalkSpeed = Movement->MaxWalkSpeed;
        Movement->MaxWalkSpeed *= Settings->AimMovementSpeedMultiplier;
        bMovementModified = true;
    }
}

void UJMThrowableGameplayIntegrationComponent::RestoreMovementRestriction()
{
    if (!bMovementModified) return;
    if (ACharacter* Character = Cast<ACharacter>(GetOwner()))
        if (UCharacterMovementComponent* Movement = Character->GetCharacterMovement()) Movement->MaxWalkSpeed = SavedMaxWalkSpeed;
    bMovementModified = false;
}

void UJMThrowableGameplayIntegrationComponent::ShowStatusWidget()
{
    APawn* Pawn = Cast<APawn>(GetOwner());
    APlayerController* PC = Pawn ? Cast<APlayerController>(Pawn->GetController()) : nullptr;
    if (!PC || !PC->IsLocalController()) return;
    if (!StatusWidget) StatusWidget = CreateWidget<UJMThrowableStatusWidget>(PC, UJMThrowableStatusWidget::StaticClass());
    if (StatusWidget && !StatusWidget->IsInViewport()) StatusWidget->AddToViewport(60);
    if (StatusWidget && Interactor) StatusWidget->SetThrowableState(Interactor->GetUseState());
}

void UJMThrowableGameplayIntegrationComponent::HideStatusWidget()
{
    if (StatusWidget)
    {
        StatusWidget->RemoveFromParent();
        StatusWidget = nullptr;
    }
}

void UJMThrowableGameplayIntegrationComponent::CloseInventoryUI()
{
    UInventoryUIComponent* UI = GetOwner()->FindComponentByClass<UInventoryUIComponent>();
    if (!UI)
    {
        if (const APawn* Pawn = Cast<APawn>(GetOwner()))
            if (AController* Controller = Pawn->GetController())
                UI = Controller->FindComponentByClass<UInventoryUIComponent>();
    }
    if (UI && UI->IsInventoryOpen()) UI->CloseInventory();
}

void UJMThrowableGameplayIntegrationComponent::RequestCancelSprint_Implementation() {}
void UJMThrowableGameplayIntegrationComponent::AimPressed() { if (Interactor) Interactor->BeginAim(); }
void UJMThrowableGameplayIntegrationComponent::AimReleased() { if (Interactor) Interactor->EndAim(); }
void UJMThrowableGameplayIntegrationComponent::ThrowPressed() { if (Interactor && Interactor->GetUseState() == EJMThrowableUseState::Aiming) Interactor->TryCommitThrow(); }
void UJMThrowableGameplayIntegrationComponent::CancelPressed() { if (Interactor) Interactor->CancelItemUse(); }
