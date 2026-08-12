#include "Prototype/JMPrototypePlayerBootstrap.h"

#include "AI/Common/JMPlayerNoiseEmitterComponent.h"
#include "Blueprint/UserWidget.h"
#include "Components/InventoryComponent.h"
#include "Components/InventoryUIComponent.h"
#include "Components/JMInteractionComponent.h"
#include "EnhancedInputComponent.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Prototype/JMPrototypeHUDWidget.h"
#include "Prototype/JMPrototypeProgressionSubsystem.h"
#include "Prototype/JMPrototypeRunResetComponent.h"
#include "TimerManager.h"
#include "Types/JMInteractionTypes.h"
#include "UI/InventoryDuckovWidgetBase.h"

AJMPrototypePlayerBootstrap::AJMPrototypePlayerBootstrap()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AJMPrototypePlayerBootstrap::BeginPlay()
{
	Super::BeginPlay();
	// Defer until the possessed pawn and its authored InventoryComponent have
	// completed BeginPlay. Restoring earlier would be followed by InitialItems
	// initialization and duplicate carried quantities on every map transition.
	GetWorldTimerManager().SetTimer(SetupTimer, this, &AJMPrototypePlayerBootstrap::SetupPlayer,
		0.25f, true, 0.05f);
}

void AJMPrototypePlayerBootstrap::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorldTimerManager().ClearTimer(SetupTimer);
	if (UInventoryUIComponent* InventoryUI = BoundInventoryUI.Get())
	{
		InventoryUI->OnInventoryOpened.RemoveDynamic(this, &ThisClass::HandleInventoryOpened);
	}
	if (UJMPrototypeProgressionSubsystem* Progression = BoundProgression.Get())
	{
		Progression->OnCurrencyChanged.RemoveDynamic(this, &ThisClass::HandleCurrencyChanged);
	}
	Super::EndPlay(EndPlayReason);
}

template <typename T>
static T* FindOrAddRuntimeComponent(AActor* Owner, const FName Name)
{
	if (T* Existing = Owner->FindComponentByClass<T>())
	{
		return Existing;
	}
	T* Component = NewObject<T>(Owner, Name);
	Owner->AddInstanceComponent(Component);
	Component->RegisterComponent();
	return Component;
}

void AJMPrototypePlayerBootstrap::SetupPlayer()
{
	APlayerController* Controller = GetWorld() ? GetWorld()->GetFirstPlayerController() : nullptr;
	APawn* Pawn = Controller ? Controller->GetPawn() : nullptr;
	if (!Pawn)
	{
		return;
	}
	PlayerPawn = Pawn;
	UInventoryComponent* Inventory = FindOrAddRuntimeComponent<UInventoryComponent>(Pawn, TEXT("PrototypeInventory"));
	UInventoryUIComponent* InventoryUI = Controller->FindComponentByClass<UInventoryUIComponent>();
	if (!InventoryUI)
	{
		InventoryUI = FindOrAddRuntimeComponent<UInventoryUIComponent>(Pawn, TEXT("PrototypeInventoryUI"));
	}
	UJMInteractionComponent* Interaction = FindOrAddRuntimeComponent<UJMInteractionComponent>(Pawn, TEXT("PrototypeInteraction"));
	Interaction->bOverrideProjectSettings = true;
	Interaction->TraceDistance = 700.0f;
	Interaction->TraceRadius = 65.0f;
	Interaction->TraceMode = EJMInteractionTraceMode::Timer;
	Interaction->TraceInterval = 0.05f;
	// A pre-existing component may already have started with another trace mode.
	// Restart detection after applying the prototype settings so prompts appear
	// while looking at an object, before the interaction key is pressed.
	Interaction->SetInteractionEnabled(false);
	Interaction->SetInteractionEnabled(true);
	UJMPrototypeRunResetComponent* Reset = FindOrAddRuntimeComponent<UJMPrototypeRunResetComponent>(Pawn, TEXT("PrototypeRunReset"));
	FindOrAddRuntimeComponent<UJMPlayerNoiseEmitterComponent>(Pawn, TEXT("DungeonNoiseEmitter"));
	InventoryUI->InventoryComponent = Inventory;
	InventoryUI->ToggleInventoryAction = InventoryAction;
	InventoryUI->ToggleInputMappingContext = InputMappingContext;
	InventoryUI->InventoryWidgetClass = InventoryWidgetClass;
	InventoryUI->OnInventoryOpened.AddUniqueDynamic(this, &ThisClass::HandleInventoryOpened);
	BoundInventoryUI = InventoryUI;
	Interaction->OnInteractionFinished.AddUniqueDynamic(this, &AJMPrototypePlayerBootstrap::HandleInteractionFinished);
	Reset->BaseRespawnTarget = BaseRespawnTarget;
	Reset->RunOnlyItems = RunOnlyItems;
	Reset->FailureLevelName = FailureLevelName;
	if (UJMPrototypeProgressionSubsystem* Progression = GetGameInstance()->GetSubsystem<UJMPrototypeProgressionSubsystem>())
	{
		Progression->OnCurrencyChanged.AddUniqueDynamic(this, &ThisClass::HandleCurrencyChanged);
		BoundProgression = Progression;
		Progression->ApplyOwnedInventoryCapacity(Inventory);
		bool bTrustedBaseInventory = false;
		if (Progression->RestoreTravelInventory(Inventory))
		{
			bTrustedBaseInventory = Progression->CommitBaseInventoryCheckpointIfPending(Inventory);
		}
		else
		{
			Progression->RestoreBaseInventoryCheckpoint(Inventory);
			bTrustedBaseInventory = true;
		}
		Progression->BeginBaseInventoryCheckpointTracking(Inventory, bTrustedBaseInventory);
	}

	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(Pawn->InputComponent);
	UInputAction* LoadedInteract = InteractAction.LoadSynchronous();
	if (!bInputBound && EnhancedInput && LoadedInteract)
	{
		EnhancedInput->BindAction(LoadedInteract, ETriggerEvent::Triggered, this, &AJMPrototypePlayerBootstrap::HandleInteract);
		InventoryUI->BindEnhancedInput(EnhancedInput);
		bInputBound = true;
	}
	if (Controller && !Controller->GetHUD())
	{
		// HUD ownership is optional; the prototype overlay is a regular viewport widget.
	}
	if (Controller && !PrototypeHUD.IsValid())
	{
		UJMPrototypeHUDWidget* Overlay = CreateWidget<UJMPrototypeHUDWidget>(Controller, UJMPrototypeHUDWidget::StaticClass());
		if (Overlay)
		{
			Overlay->AddToViewport(5);
			PrototypeHUD = Overlay;
		}
	}
	if (bInputBound)
	{
		GetWorldTimerManager().ClearTimer(SetupTimer);
	}
}

void AJMPrototypePlayerBootstrap::HandleInventoryOpened()
{
	RefreshInventoryCurrency();
}

void AJMPrototypePlayerBootstrap::HandleCurrencyChanged(int32)
{
	RefreshInventoryCurrency();
}

void AJMPrototypePlayerBootstrap::RefreshInventoryCurrency()
{
	UInventoryUIComponent* InventoryUI = BoundInventoryUI.Get();
	UJMPrototypeProgressionSubsystem* Progression = BoundProgression.Get();
	if (!InventoryUI || !Progression)
	{
		return;
	}
	if (UInventoryDuckovWidgetBase* DuckovWidget = Cast<UInventoryDuckovWidgetBase>(InventoryUI->GetInventoryWidget()))
	{
		DuckovWidget->SetCurrencyAmount(Progression->GetCurrency());
	}
}

void AJMPrototypePlayerBootstrap::HandleInteractionFinished(UObject*, FJMInteractionResult Result)
{
	if (!Result.Message.IsEmpty())
	{
		if (UJMPrototypeHUDWidget* Overlay = PrototypeHUD.Get())
		{
			Overlay->ShowNotification(Result.Message, Result.bSucceeded);
		}
	}
}

void AJMPrototypePlayerBootstrap::HandleInteract()
{
	if (APawn* Pawn = PlayerPawn.Get())
	{
		if (UJMInteractionComponent* Interaction = Pawn->FindComponentByClass<UJMInteractionComponent>())
		{
			Interaction->RefreshCurrentInteractable();
			Interaction->TryInteract();
		}
	}
}
