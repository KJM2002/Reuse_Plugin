#include "Components/InventoryUIComponent.h"

#include "Components/InventoryComponent.h"
#include "Components/InventoryContainerComponent.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "EnhancedActionKeyMapping.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "Integration/ReuseInventoryInspectorBridge.h"
#include "Interfaces/InventoryItemInspectorBridge.h"
#include "InventoryLog.h"
#include "InventoryEventTags.h"
#include "JMGameplayUIEventTags.h"
#include "Items/InventoryItemDefinition.h"
#include "Settings/InventorySystemSettings.h"
#include "Sound/SoundBase.h"
#include "Subsystems/JMGameplayEventSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "UI/InventoryPickupNotificationWidget.h"
#include "UI/InventoryWidgetBase.h"
#include "UI/InventoryDuckovWidgetBase.h"

UInventoryUIComponent::UInventoryUIComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	InspectorBridge = CreateDefaultSubobject<UReuseInventoryInspectorBridge>(TEXT("DefaultItemInspectorBridge"));
}

void UInventoryUIComponent::BeginPlay()
{
	Super::BeginPlay();

	const UInventorySystemSettings* Settings = GetDefault<UInventorySystemSettings>();
	if (Settings)
	{
		const FString ConfiguredWidgetPath = InventoryWidgetClass.ToSoftObjectPath().ToString();
		const bool bIsLegacyPluginWidget =
			ConfiguredWidgetPath == TEXT("/InventorySystem/Widget/WBP_Inventory")
			|| ConfiguredWidgetPath.StartsWith(TEXT("/InventorySystem/Widget/WBP_Inventory."));
		if (Settings->bUpgradeLegacyDefaultWidgetToNative
			&& bIsLegacyPluginWidget)
		{
			// Existing Blueprint instances often serialized the former plugin
			// default. Upgrade that one known legacy class while preserving every
			// project-specific custom presentation.
			InventoryWidgetClass = UInventoryWidgetBase::StaticClass();
		}
		if (InventoryWidgetClass.IsNull())
		{
			InventoryWidgetClass = Settings->DefaultInventoryWidgetClass;
		}
		if (ToggleInventoryAction.IsNull())
		{
			ToggleInventoryAction = Settings->DefaultToggleInventoryAction;
		}
		if (ToggleInputMappingContext.IsNull())
		{
			ToggleInputMappingContext = Settings->DefaultToggleInventoryMappingContext;
		}
	}

	if (InspectorBridge)
	{
		InspectorBridge->OnInspectorClosed.AddUniqueDynamic(this, &UInventoryUIComponent::HandleInspectorClosed);
	}

	ResolveAndBindInventoryComponent();
	if (UWorld* World = GetWorld())
	{
		// PlayerController BeginPlay can run before its Pawn is possessed. Keep this
		// lightweight check alive so notifications also survive pawn replacement.
		World->GetTimerManager().SetTimer(
			InventoryResolveTimerHandle,
			this,
			&UInventoryUIComponent::HandleInventoryResolveTimer,
			0.25f,
			true);
	}
}

void UInventoryUIComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (InspectorBridge)
	{
		InspectorBridge->OnInspectorClosed.RemoveDynamic(this, &UInventoryUIComponent::HandleInspectorClosed);
	}
	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(InventoryResolveTimerHandle);
	}
	if (UInventoryComponent* BoundInventory = BoundNotificationInventory.Get())
	{
		BoundInventory->OnItemsReceived.RemoveDynamic(this, &UInventoryUIComponent::HandleItemsReceived);
	}
	BoundNotificationInventory.Reset();
	if (PickupNotificationWidget)
	{
		PickupNotificationWidget->RemoveFromParent();
		PickupNotificationWidget = nullptr;
	}
	FinalizeCloseInventory();
	Super::EndPlay(EndPlayReason);
}

bool UInventoryUIComponent::BindEnhancedInput(UEnhancedInputComponent* EnhancedInputComponent)
{
	if (!EnhancedInputComponent || ToggleInventoryAction.IsNull())
	{
		UE_LOG(LogInventorySystem, Warning, TEXT("Inventory input binding requires both an Enhanced Input component and a toggle action."));
		return false;
	}
	if (BoundEnhancedInputComponent.Get() == EnhancedInputComponent)
	{
		return true;
	}

	UInputAction* Action = ToggleInventoryAction.LoadSynchronous();
	if (!Action)
	{
		UE_LOG(LogInventorySystem, Warning, TEXT("Configured inventory toggle input action could not be loaded."));
		return false;
	}

	// Open on release so the key-down that initiated opening cannot also reach the
	// newly focused inventory widget and immediately request a close.
	EnhancedInputComponent->BindAction(Action, ETriggerEvent::Completed, this, &UInventoryUIComponent::HandleToggleInput);
	BoundEnhancedInputComponent = EnhancedInputComponent;
	return true;
}

bool UInventoryUIComponent::OpenInventory()
{
	if (IsInventoryOpen())
	{
		return true;
	}

	APlayerController* PlayerController = ResolvePlayerController();
	if (!PlayerController)
	{
		UE_LOG(LogInventorySystem, Warning, TEXT("Cannot open inventory without a local player controller."));
		return false;
	}
	ResolveAndBindInventoryComponent();
	if (!InventoryComponent)
	{
		UE_LOG(LogInventorySystem, Warning, TEXT("Cannot open inventory because no InventoryComponent was resolved."));
		return false;
	}

	TSubclassOf<UInventoryWidgetBase> WidgetClass = InventoryWidgetClass.LoadSynchronous();
	if (!WidgetClass)
	{
		UE_LOG(LogInventorySystem, Warning, TEXT("Cannot open inventory because no inventory widget class is configured."));
		return false;
	}

	InventoryWidget = CreateWidget<UInventoryWidgetBase>(PlayerController, WidgetClass);
	if (!InventoryWidget)
	{
		return false;
	}

	InventoryWidget->InitializeInventory(InventoryComponent, this);
	if (UInventoryDuckovWidgetBase* DuckovWidget = Cast<UInventoryDuckovWidgetBase>(InventoryWidget))
	{
		DuckovWidget->SetExternalContainer(CurrentContainer);
	}
	InventoryWidget->OnCloseRequested.AddUniqueDynamic(this, &UInventoryUIComponent::HandleWidgetCloseRequested);
	InventoryWidget->OnCloseTransitionFinished.AddUniqueDynamic(this, &UInventoryUIComponent::HandleWidgetCloseTransitionFinished);
	InventoryWidget->OnInspectTransitionFinished.AddUniqueDynamic(this, &UInventoryUIComponent::HandleWidgetInspectTransitionFinished);
	InventoryWidget->AddToViewport(50);
	ApplyInputMode(PlayerController);
	InventoryWidget->FocusSelectedSlot();
	bClosePending = false;
	if (const UInventorySystemSettings* Settings = GetDefault<UInventorySystemSettings>())
	{
		PlayConfiguredSound(Settings->InventoryOpenSound);
	}
	PublishPresentationEvent(true);
	OnInventoryOpened.Broadcast();
	return true;
}

bool UInventoryUIComponent::OpenContainer(UInventoryContainerComponent* Container)
{
	if (!IsValid(Container))
	{
		return false;
	}
	SetCurrentContainer(Container);
	if (IsInventoryOpen())
	{
		return true;
	}
	return OpenInventory();
}

void UInventoryUIComponent::SetCurrentContainer(UInventoryContainerComponent* Container)
{
	CurrentContainer = Container;
	if (UInventoryDuckovWidgetBase* DuckovWidget = Cast<UInventoryDuckovWidgetBase>(InventoryWidget))
	{
		DuckovWidget->SetExternalContainer(CurrentContainer);
	}
}

void UInventoryUIComponent::CloseInventory()
{
	PendingInspectorItem = nullptr;
	if (InspectorBridge && InspectorBridge->IsInspectorOpen())
	{
		InspectorBridge->CloseInspector();
	}

	if (InventoryWidget && !bClosePending)
	{
		bClosePending = true;
		InventoryWidget->BeginCloseTransition();
	}
}

void UInventoryUIComponent::ToggleInventory()
{
	if (InspectorBridge && InspectorBridge->IsInspectorOpen())
	{
		InspectorBridge->CloseInspector();
		return;
	}
	if (IsInventoryOpen())
	{
		if (bClosePending && InventoryWidget)
		{
			// A second toggle during the short close transition reverses it instead
			// of destroying/recreating the widget or corrupting input ownership.
			bClosePending = false;
			InventoryWidget->BeginOpenTransition();
		}
		else
		{
			CloseInventory();
		}
	}
	else
	{
		OpenInventory();
	}
}

bool UInventoryUIComponent::IsInventoryOpen() const
{
	return IsValid(InventoryWidget) && InventoryWidget->IsInViewport();
}

bool UInventoryUIComponent::InspectItem(UInventoryItemDefinition* ItemDefinition)
{
	if (!IsInventoryOpen() || !IsValid(ItemDefinition) || !ItemDefinition->bCanInspect || ItemDefinition->InspectMesh.IsNull())
	{
		return false;
	}
	if (!InspectorBridge)
	{
		UE_LOG(LogInventorySystem, Warning, TEXT("Inspect requested for %s but no Inspector Bridge is configured."), *GetNameSafe(ItemDefinition));
		return false;
	}

	if (PendingInspectorItem)
	{
		return false;
	}

	PendingInspectorItem = ItemDefinition;
	InventoryWidget->BeginInspectTransition();
	return true;
}

bool UInventoryUIComponent::IsToggleInventoryKey(FKey Key) const
{
	if (!Key.IsValid() || ToggleInventoryAction.IsNull())
	{
		return false;
	}

	const UInputAction* ToggleAction = ToggleInventoryAction.Get();
	if (!ToggleAction)
	{
		ToggleAction = ToggleInventoryAction.LoadSynchronous();
	}
	const UInputMappingContext* MappingContext = ToggleInputMappingContext.Get();
	if (!MappingContext && !ToggleInputMappingContext.IsNull())
	{
		MappingContext = ToggleInputMappingContext.LoadSynchronous();
	}
	if (!MappingContext || !ToggleAction)
	{
		return false;
	}

	for (const FEnhancedActionKeyMapping& Mapping : MappingContext->GetMappings())
	{
		if (Mapping.Action == ToggleAction && Mapping.Key == Key)
		{
			return true;
		}
	}
	return false;
}

void UInventoryUIComponent::HandleToggleInput()
{
	ToggleInventory();
}

void UInventoryUIComponent::HandleWidgetCloseRequested()
{
	CloseInventory();
}

void UInventoryUIComponent::HandleWidgetCloseTransitionFinished()
{
	if (bClosePending)
	{
		FinalizeCloseInventory();
	}
}

void UInventoryUIComponent::HandleWidgetInspectTransitionFinished()
{
	UInventoryItemDefinition* ItemDefinition = PendingInspectorItem.Get();
	PendingInspectorItem = nullptr;
	if (!InventoryWidget || !IsValid(ItemDefinition) || !InspectorBridge)
	{
		if (InventoryWidget)
		{
			InventoryWidget->BeginOpenTransition();
		}
		return;
	}

	APlayerController* PlayerController = ResolvePlayerController();
	if (!InspectorBridge->OpenInspector(PlayerController, ItemDefinition))
	{
		InventoryWidget->BeginOpenTransition();
		InventoryWidget->FocusSelectedSlot();
		return;
	}

	InventoryWidget->SetVisibility(ESlateVisibility::Collapsed);
}

void UInventoryUIComponent::HandleInspectorClosed()
{
	if (InventoryWidget && !bClosePending)
	{
		InventoryWidget->SetVisibility(ESlateVisibility::Visible);
		InventoryWidget->RefreshInventory();
		InventoryWidget->BeginInspectorReturnTransition();
		InventoryWidget->FocusSelectedSlot();
	}
}

void UInventoryUIComponent::FinalizeCloseInventory()
{
	if (!InventoryWidget)
	{
		bClosePending = false;
		RestoreInputMode();
		return;
	}

	InventoryWidget->OnCloseRequested.RemoveDynamic(this, &UInventoryUIComponent::HandleWidgetCloseRequested);
	InventoryWidget->OnCloseTransitionFinished.RemoveDynamic(this, &UInventoryUIComponent::HandleWidgetCloseTransitionFinished);
	InventoryWidget->OnInspectTransitionFinished.RemoveDynamic(this, &UInventoryUIComponent::HandleWidgetInspectTransitionFinished);
	InventoryWidget->RemoveFromParent();
	InventoryWidget = nullptr;
	CurrentContainer = nullptr;
	PendingInspectorItem = nullptr;
	bClosePending = false;
	RestoreInputMode();
	if (const UInventorySystemSettings* Settings = GetDefault<UInventorySystemSettings>())
	{
		PlayConfiguredSound(Settings->InventoryCloseSound);
	}
	PublishPresentationEvent(false);
	OnInventoryClosed.Broadcast();
}

void UInventoryUIComponent::PublishPresentationEvent(bool bInventoryVisible)
{
	OnInventoryPresentationChanged.Broadcast(bInventoryVisible);

	UGameInstance* GameInstance = GetWorld() ? GetWorld()->GetGameInstance() : nullptr;
	UJMGameplayEventSubsystem* EventSubsystem = GameInstance ? GameInstance->GetSubsystem<UJMGameplayEventSubsystem>() : nullptr;
	if (!EventSubsystem)
	{
		return;
	}

	FJMGameplayEventMessage Message;
	Message.EventTag = bInventoryVisible ? JMInventoryEventTags::UIOpened : JMInventoryEventTags::UIClosed;
	Message.Source = this;
	Message.Instigator = GetOwner();
	Message.Target = ResolvePlayerController();
	EventSubsystem->PublishEvent(Message);

	Message.EventTag = bInventoryVisible ? JMGameplayUIEventTags::ModalOpened : JMGameplayUIEventTags::ModalClosed;
	Message.ContextTags.Reset();
	Message.ContextTags.AddTag(bInventoryVisible ? JMInventoryEventTags::UIOpened : JMInventoryEventTags::UIClosed);
	EventSubsystem->PublishEvent(Message);
}

void UInventoryUIComponent::PlayConfiguredSound(const TSoftObjectPtr<USoundBase>& Sound) const
{
	if (!Sound.IsNull())
	{
		if (USoundBase* LoadedSound = Sound.LoadSynchronous())
		{
			UGameplayStatics::PlaySound2D(this, LoadedSound);
		}
	}
}

void UInventoryUIComponent::HandleItemsReceived(UInventoryItemDefinition* ItemDefinition, int32 Quantity)
{
	UE_LOG(
		LogInventorySystem,
		Log,
		TEXT("Inventory pickup notification event received: UI owner=%s, item=%s, quantity=%d"),
		*GetNameSafe(GetOwner()),
		*GetNameSafe(ItemDefinition),
		Quantity);

	if (!IsValid(ItemDefinition) || Quantity <= 0)
	{
		UE_LOG(LogInventorySystem, Warning, TEXT("Pickup notification ignored because its item or quantity is invalid."));
		return;
	}

	APlayerController* PlayerController = ResolvePlayerController();
	if (!PlayerController || !PlayerController->IsLocalController())
	{
		UE_LOG(LogInventorySystem, Warning, TEXT("Pickup notification ignored because no local player controller was resolved."));
		return;
	}

	TSubclassOf<UInventoryPickupNotificationWidget> NotificationClass = PickupNotificationWidgetClass;
	if (!NotificationClass)
	{
		NotificationClass = UInventoryPickupNotificationWidget::StaticClass();
	}
	if (!PickupNotificationWidget || !PickupNotificationWidget->IsA(NotificationClass))
	{
		PickupNotificationWidget = CreateWidget<UInventoryPickupNotificationWidget>(PlayerController, NotificationClass);
	}
	if (!PickupNotificationWidget)
	{
		UE_LOG(LogInventorySystem, Warning, TEXT("Pickup notification widget creation failed for class %s."), *GetNameSafe(NotificationClass));
		return;
	}

	if (!PickupNotificationWidget->IsInViewport())
	{
		// Notification WBP is a full-screen layout. Its Canvas Panel controls the
		// toast's anchor, position and size directly in the UMG Designer.
		PickupNotificationWidget->AddToViewport(100);
	}

	const FText ItemName = ItemDefinition->DisplayName.IsEmpty()
		? FText::FromName(ItemDefinition->ItemId)
		: ItemDefinition->DisplayName;
	const FText Message = FText::Format(
		NSLOCTEXT("InventorySystem", "PickupNotification", "{0} x {1}"),
		ItemName,
		FText::AsNumber(Quantity));
	UTexture2D* ItemIcon = ItemDefinition->Icon.IsNull()
		? nullptr
		: ItemDefinition->Icon.LoadSynchronous();
	PickupNotificationWidget->ShowItemNotification(Message, ItemIcon, PickupNotificationDuration);
	UE_LOG(
		LogInventorySystem,
		Log,
		TEXT("Pickup notification displayed: message=%s, class=%s"),
		*Message.ToString(),
		*GetNameSafe(PickupNotificationWidget->GetClass()));
}

void UInventoryUIComponent::HandleInventoryResolveTimer()
{
	ResolveAndBindInventoryComponent();
}

bool UInventoryUIComponent::ResolveAndBindInventoryComponent()
{
	UInventoryComponent* ResolvedInventory = ResolveInventoryComponent();
	if (!ResolvedInventory)
	{
		ResolvedInventory = InventoryComponent;
	}

	if (BoundNotificationInventory.Get() != ResolvedInventory)
	{
		if (UInventoryComponent* PreviouslyBoundInventory = BoundNotificationInventory.Get())
		{
			PreviouslyBoundInventory->OnItemsReceived.RemoveDynamic(this, &UInventoryUIComponent::HandleItemsReceived);
		}

		BoundNotificationInventory = ResolvedInventory;
		if (ResolvedInventory)
		{
			ResolvedInventory->OnItemsReceived.AddUniqueDynamic(this, &UInventoryUIComponent::HandleItemsReceived);
			UE_LOG(
				LogInventorySystem,
				Log,
				TEXT("Inventory pickup notifications bound: UI owner=%s, inventory owner=%s"),
				*GetNameSafe(GetOwner()),
				*GetNameSafe(ResolvedInventory->GetOwner()));
		}
	}

	InventoryComponent = ResolvedInventory;
	return IsValid(InventoryComponent);
}

APlayerController* UInventoryUIComponent::ResolvePlayerController() const
{
	if (APlayerController* PlayerController = Cast<APlayerController>(GetOwner()))
	{
		return PlayerController;
	}
	if (const APawn* Pawn = Cast<APawn>(GetOwner()))
	{
		return Cast<APlayerController>(Pawn->GetController());
	}
	return GetOwner() ? Cast<APlayerController>(GetOwner()->GetInstigatorController()) : nullptr;
}

UInventoryComponent* UInventoryUIComponent::ResolveInventoryComponent() const
{
	if (AActor* Owner = GetOwner())
	{
		if (UInventoryComponent* Found = Owner->FindComponentByClass<UInventoryComponent>())
		{
			return Found;
		}
		if (const APlayerController* PlayerController = Cast<APlayerController>(Owner))
		{
			if (APawn* Pawn = PlayerController->GetPawn())
			{
				return Pawn->FindComponentByClass<UInventoryComponent>();
			}
		}
	}
	return nullptr;
}

void UInventoryUIComponent::ApplyInputMode(APlayerController* PlayerController)
{
	InputModePlayerController = PlayerController;
	bPreviousMouseCursor = PlayerController->bShowMouseCursor;
	bAppliedMoveInputBlock = !PlayerController->IsMoveInputIgnored();
	bAppliedLookInputBlock = !PlayerController->IsLookInputIgnored();
	if (bAppliedMoveInputBlock)
	{
		PlayerController->SetIgnoreMoveInput(true);
	}
	if (bAppliedLookInputBlock)
	{
		PlayerController->SetIgnoreLookInput(true);
	}
	if (APawn* ControlledPawn = PlayerController->GetPawn())
	{
		InputBlockedPawn = ControlledPawn;
		bAppliedPawnInputBlock = ControlledPawn->InputEnabled();
		if (bAppliedPawnInputBlock)
		{
			ControlledPawn->DisableInput(PlayerController);
		}
	}
	PlayerController->bShowMouseCursor = true;

	FInputModeGameAndUI InputMode;
	InputMode.SetWidgetToFocus(InventoryWidget->TakeWidget());
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputMode.SetHideCursorDuringCapture(false);
	PlayerController->SetInputMode(InputMode);
}

void UInventoryUIComponent::RestoreInputMode()
{
	if (APlayerController* PlayerController = InputModePlayerController.Get())
	{
		if (bAppliedMoveInputBlock)
		{
			PlayerController->SetIgnoreMoveInput(false);
		}
		if (bAppliedLookInputBlock)
		{
			PlayerController->SetIgnoreLookInput(false);
		}
		if (bAppliedPawnInputBlock)
		{
			if (APawn* ControlledPawn = InputBlockedPawn.Get())
			{
				ControlledPawn->EnableInput(PlayerController);
			}
		}
		PlayerController->bShowMouseCursor = bPreviousMouseCursor;
		if (bPreviousMouseCursor)
		{
			FInputModeGameAndUI InputMode;
			InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			PlayerController->SetInputMode(InputMode);
		}
		else
		{
			FInputModeGameOnly InputMode;
			PlayerController->SetInputMode(InputMode);
		}
	}

	InputModePlayerController.Reset();
	InputBlockedPawn.Reset();
	bAppliedMoveInputBlock = false;
	bAppliedLookInputBlock = false;
	bAppliedPawnInputBlock = false;
}
