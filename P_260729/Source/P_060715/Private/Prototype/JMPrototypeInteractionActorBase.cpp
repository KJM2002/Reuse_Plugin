#include "Prototype/JMPrototypeInteractionActorBase.h"

#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Prototype/JMPrototypeStationInteractionWidget.h"
#include "Sound/SoundBase.h"

#define LOCTEXT_NAMESPACE "JMPrototypeInteraction"

AJMPrototypeInteractionActorBase::AJMPrototypeInteractionActorBase()
{
	PrimaryActorTick.bCanEverTick = false;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	InteractionBounds = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractionBounds"));
	InteractionBounds->SetupAttachment(SceneRoot);
	InteractionBounds->SetBoxExtent(FVector(75.0f));
	InteractionBounds->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	InteractionBounds->SetCollisionResponseToAllChannels(ECR_Ignore);
	InteractionBounds->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	VisualMesh->SetupAttachment(SceneRoot);
	VisualMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	const FSoftObjectPath DefaultPing(TEXT("/Engine/EngineSounds/1kSineTonePing.1kSineTonePing"));
	OpenSound = TSoftObjectPtr<USoundBase>(DefaultPing);
	SuccessSound = TSoftObjectPtr<USoundBase>(DefaultPing);
	FailureSound = TSoftObjectPtr<USoundBase>(DefaultPing);
	CloseSound = TSoftObjectPtr<USoundBase>(DefaultPing);
	ConfirmButtonText = LOCTEXT("DefaultConfirm", "확인");
}

bool AJMPrototypeInteractionActorBase::CanInteract_Implementation(const FJMInteractionContext& Context) const
{
	return bInteractionEnabled && IsPrototypeInteractionAvailable(Context);
}

FJMInteractionResult AJMPrototypeInteractionActorBase::BeginInteract_Implementation(const FJMInteractionContext& Context)
{
	return CanInteract_Implementation(Context)
		? FJMInteractionResult::Success()
		: FJMInteractionResult::Failure(EJMInteractionResultCode::NotAllowed, LOCTEXT("Unavailable", "Interaction is not available."));
}

FJMInteractionResult AJMPrototypeInteractionActorBase::CompleteInteract_Implementation(const FJMInteractionContext& Context)
{
	if (!CanInteract_Implementation(Context))
	{
		return FJMInteractionResult::Failure(EJMInteractionResultCode::NotAllowed, LOCTEXT("CompleteUnavailable", "Interaction is not available."));
	}

	if (bUseConfirmationUI)
	{
		return OpenConfirmationUI(Context);
	}
	const FJMPrototypeOperationResult Result = PerformPrototypeInteraction(Context);
	OnPrototypeInteractionResolved(Result.bSucceeded, Result.Code, Result.Message);
	return Result.bSucceeded
		? FJMInteractionResult::Success(Result.Message)
		: FJMInteractionResult::Failure(EJMInteractionResultCode::NotAllowed, Result.Message);
}

FJMInteractionResult AJMPrototypeInteractionActorBase::OpenConfirmationUI(const FJMInteractionContext& Context)
{
	APlayerController* PlayerController = Cast<APlayerController>(Context.InstigatorController);
	if (!PlayerController && Context.InstigatorActor)
	{
		if (const APawn* Pawn = Cast<APawn>(Context.InstigatorActor))
		{
			PlayerController = Cast<APlayerController>(Pawn->GetController());
		}
	}
	if (!PlayerController || !PlayerController->IsLocalController())
	{
		return FJMInteractionResult::Failure(EJMInteractionResultCode::Failed,
			LOCTEXT("MissingStationPlayer", "상호작용 UI를 표시할 플레이어를 찾을 수 없습니다."));
	}
	if (ActiveInteractionWidget.IsValid())
	{
		return FJMInteractionResult::Failure(EJMInteractionResultCode::AlreadyInteracting,
			LOCTEXT("StationUIAlreadyOpen", "이미 상호작용 화면이 열려 있습니다."));
	}
	TSubclassOf<UJMPrototypeStationInteractionWidget> WidgetClass = InteractionWidgetClass;
	if (!WidgetClass)
	{
		WidgetClass = UJMPrototypeStationInteractionWidget::StaticClass();
	}
	UJMPrototypeStationInteractionWidget* Widget = CreateWidget<UJMPrototypeStationInteractionWidget>(PlayerController, WidgetClass);
	if (!Widget)
	{
		return FJMInteractionResult::Failure(EJMInteractionResultCode::Failed,
			LOCTEXT("StationUICreationFailed", "상호작용 UI를 생성하지 못했습니다."));
	}
	PendingInteractionContext = Context;
	ActiveInteractionWidget = Widget;
	Widget->InitializeForStation(this);
	Widget->AddToViewport(100);
	Widget->ActivateModal();
	PlayInteractionSound(OpenSound, 0.85f);
	return FJMInteractionResult::Success();
}

FJMPrototypeOperationResult AJMPrototypeInteractionActorBase::ConfirmPendingInteraction()
{
	if (!ActiveInteractionWidget.IsValid() || !IsValid(PendingInteractionContext.InstigatorActor))
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidState,
			LOCTEXT("NoPendingStationInteraction", "진행 중인 상호작용이 없습니다."));
	}
	const FJMPrototypeOperationResult Result = PerformPrototypeInteraction(PendingInteractionContext);
	OnPrototypeInteractionResolved(Result.bSucceeded, Result.Code, Result.Message);
	PlayInteractionSound(Result.bSucceeded ? SuccessSound : FailureSound, Result.bSucceeded ? 1.25f : 0.55f);
	return Result;
}

void AJMPrototypeInteractionActorBase::HandleInteractionWidgetClosed(UJMPrototypeStationInteractionWidget* Widget)
{
	if (ActiveInteractionWidget.Get() == Widget)
	{
		ActiveInteractionWidget.Reset();
		PendingInteractionContext = FJMInteractionContext();
		PlayInteractionSound(CloseSound, 0.75f);
	}
}

void AJMPrototypeInteractionActorBase::PlayInteractionSound(
	const TSoftObjectPtr<USoundBase>& Sound, const float PitchMultiplier) const
{
	if (USoundBase* LoadedSound = Sound.LoadSynchronous())
	{
		UGameplayStatics::PlaySound2D(this, LoadedSound, InteractionSoundVolume, PitchMultiplier);
	}
}

FText AJMPrototypeInteractionActorBase::BuildInteractionDescription(const FJMInteractionContext&) const
{
	return InteractionDescription;
}

void AJMPrototypeInteractionActorBase::CancelInteract_Implementation(const FJMInteractionContext& Context)
{
}

FJMInteractionPrompt AJMPrototypeInteractionActorBase::GetInteractionPrompt_Implementation(const FJMInteractionContext& Context) const
{
	FJMInteractionPrompt Prompt;
	Prompt.DisplayText = InteractionPrompt;
	Prompt.HoldDuration = InteractionDuration;
	Prompt.Priority = InteractionPriority;
	Prompt.bVisible = !InteractionPrompt.IsEmpty();
	return Prompt;
}

float AJMPrototypeInteractionActorBase::GetInteractionDuration_Implementation(const FJMInteractionContext& Context) const
{
	return FMath::Max(0.0f, InteractionDuration);
}

int32 AJMPrototypeInteractionActorBase::GetInteractionPriority_Implementation(const FJMInteractionContext& Context) const
{
	return InteractionPriority;
}

bool AJMPrototypeInteractionActorBase::IsPrototypeInteractionAvailable(const FJMInteractionContext& Context) const
{
	return IsValid(Context.InstigatorActor);
}

FJMPrototypeOperationResult AJMPrototypeInteractionActorBase::PerformPrototypeInteraction(const FJMInteractionContext& Context)
{
	return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidConfiguration, LOCTEXT("NoAction", "This prototype station has no action."));
}

#undef LOCTEXT_NAMESPACE
