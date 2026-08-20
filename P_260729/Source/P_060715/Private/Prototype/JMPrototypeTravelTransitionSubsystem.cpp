#include "Prototype/JMPrototypeTravelTransitionSubsystem.h"

#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "Engine/GameViewportClient.h"
#include "Engine/World.h"
#include "Framework/Application/SlateApplication.h"
#include "GameFramework/PlayerController.h"
#include "Camera/PlayerCameraManager.h"
#include "Input/Reply.h"
#include "MoviePlayer.h"
#include "Styling/CoreStyle.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Text/STextBlock.h"

DEFINE_LOG_CATEGORY_STATIC(LogJMPrototypeTravelTransition, Log, All);

namespace JMPrototypeTravel
{
	class SArrivalCover final : public SCompoundWidget
	{
	public:
		SLATE_BEGIN_ARGS(SArrivalCover) {}
			SLATE_ARGUMENT(FText, Message)
			SLATE_EVENT(FSimpleDelegate, OnDismiss)
		SLATE_END_ARGS()

		void Construct(const FArguments& InArgs)
		{
			OnDismiss = InArgs._OnDismiss;
			ChildSlot
			[
				SNew(SBorder)
				.BorderImage(FCoreStyle::Get().GetBrush("WhiteBrush"))
				.BorderBackgroundColor(FLinearColor::Black)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.FillHeight(1.0f)
					.VAlign(VAlign_Center)
					.HAlign(HAlign_Center)
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						.AutoHeight()
						.HAlign(HAlign_Center)
						[
							SNew(STextBlock)
							.Text(InArgs._Message)
							.Font(FCoreStyle::GetDefaultFontStyle("Bold", 28))
							.ColorAndOpacity(FLinearColor::White)
						]
						+ SVerticalBox::Slot()
						.AutoHeight()
						.HAlign(HAlign_Center)
						.Padding(0.0f, 28.0f, 0.0f, 0.0f)
						[
							SNew(STextBlock)
							.Text(NSLOCTEXT("JMPrototypeTravel", "ClickToReveal", "클릭하여 눈을 뜹니다"))
							.Font(FCoreStyle::GetDefaultFontStyle("Regular", 15))
							.ColorAndOpacity(FLinearColor(0.55f, 0.55f, 0.55f, 1.0f))
						]
					]
				]
			];
		}

		virtual bool SupportsKeyboardFocus() const override { return true; }

		virtual FReply OnMouseButtonDown(const FGeometry&, const FPointerEvent&) override
		{
			OnDismiss.ExecuteIfBound();
			return FReply::Handled();
		}

		virtual FReply OnKeyDown(const FGeometry&, const FKeyEvent& KeyEvent) override
		{
			if (KeyEvent.GetKey() == EKeys::Enter || KeyEvent.GetKey() == EKeys::SpaceBar)
			{
				OnDismiss.ExecuteIfBound();
				return FReply::Handled();
			}
			return FReply::Unhandled();
		}

	private:
		FSimpleDelegate OnDismiss;
	};
}

void UJMPrototypeTravelTransitionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &ThisClass::HandlePostLoadMap);
}

void UJMPrototypeTravelTransitionSubsystem::Deinitialize()
{
	RemoveArrivalScreen();
	FCoreUObjectDelegates::PostLoadMapWithWorld.RemoveAll(this);
	Super::Deinitialize();
}

void UJMPrototypeTravelTransitionSubsystem::PrepareLoadingScreen(const TArray<FText>& ArrivalMessages)
{
	PendingArrivalMessage = ArrivalMessages.IsEmpty()
		? NSLOCTEXT("JMPrototypeTravel", "DefaultArrival", "포탈이 나를 삼켰다.")
		: ArrivalMessages[FMath::RandRange(0, ArrivalMessages.Num() - 1)];
	bArrivalPending = true;

	if (IsRunningDedicatedServer() || !GetMoviePlayer() || !GetMoviePlayer()->IsInitialized())
	{
		UE_LOG(LogJMPrototypeTravelTransition, Display,
			TEXT("MoviePlayer is unavailable; the post-load viewport arrival cover will still be used."));
		return;
	}

	FLoadingScreenAttributes Attributes;
	Attributes.MinimumLoadingScreenDisplayTime = -1.0f;
	Attributes.bAutoCompleteWhenLoadingCompletes = true;
	Attributes.bMoviesAreSkippable = false;
	Attributes.bWaitForManualStop = false;
	Attributes.PlaybackType = MT_LoadingLoop;
	Attributes.WidgetLoadingScreen =
		SNew(SBorder)
		.BorderImage(FCoreStyle::Get().GetBrush("WhiteBrush"))
		.BorderBackgroundColor(FLinearColor::Black);

	GetMoviePlayer()->SetupLoadingScreen(Attributes);
	UE_LOG(LogJMPrototypeTravelTransition, Display,
		TEXT("Prepared MoviePlayer black loading cover and post-load arrival message."));
}

void UJMPrototypeTravelTransitionSubsystem::HandlePostLoadMap(UWorld* LoadedWorld)
{
	if (!LoadedWorld
		|| LoadedWorld->GetGameInstance() != GetGameInstance()
		|| IsRunningDedicatedServer()
		|| !bArrivalPending)
	{
		return;
	}
	ShowArrivalScreen(LoadedWorld);
}

void UJMPrototypeTravelTransitionSubsystem::ShowArrivalScreen(UWorld* LoadedWorld)
{
	RemoveArrivalScreen();
	UGameViewportClient* GameViewport = LoadedWorld ? LoadedWorld->GetGameViewport() : nullptr;
	APlayerController* PC = LoadedWorld ? LoadedWorld->GetFirstPlayerController() : nullptr;
	if (!GameViewport || !PC)
	{
		UE_LOG(LogJMPrototypeTravelTransition, Warning,
			TEXT("Arrival cover could not be shown because the destination viewport or player controller is missing."));
		bArrivalPending = false;
		return;
	}

	ArrivalWorld = LoadedWorld;
	bPreviousShowMouseCursor = PC->bShowMouseCursor;
	PC->SetIgnoreMoveInput(true);
	PC->SetIgnoreLookInput(true);
	PC->bShowMouseCursor = true;
	if (PC->PlayerCameraManager)
	{
		PC->PlayerCameraManager->SetManualCameraFade(1.0f, FLinearColor::Black, false);
	}

	ArrivalOverlayWidget =
		SNew(JMPrototypeTravel::SArrivalCover)
		.Message(PendingArrivalMessage)
		.OnDismiss(FSimpleDelegate::CreateUObject(this, &ThisClass::DismissArrivalScreen));
	GameViewport->AddViewportWidgetContent(ArrivalOverlayWidget.ToSharedRef(), MAX_int32);
	FInputModeUIOnly InputMode;
	InputMode.SetWidgetToFocus(ArrivalOverlayWidget);
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	PC->SetInputMode(InputMode);
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().SetKeyboardFocus(ArrivalOverlayWidget, EFocusCause::SetDirectly);
	}
	UE_LOG(LogJMPrototypeTravelTransition, Display, TEXT("Showing post-load arrival cover; waiting for click."));
}

void UJMPrototypeTravelTransitionSubsystem::DismissArrivalScreen()
{
	UWorld* LoadedWorld = ArrivalWorld.Get();
	APlayerController* PC = LoadedWorld ? LoadedWorld->GetFirstPlayerController() : nullptr;
	RemoveArrivalScreen();
	bArrivalPending = false;
	PendingArrivalMessage = FText::GetEmpty();

	if (PC)
	{
		PC->SetIgnoreMoveInput(false);
		PC->SetIgnoreLookInput(false);
		PC->bShowMouseCursor = bPreviousShowMouseCursor;
		PC->SetInputMode(FInputModeGameOnly());
		if (PC->PlayerCameraManager)
		{
			PC->PlayerCameraManager->StartCameraFade(
				1.0f, 0.0f, 0.85f, FLinearColor::Black, false, false);
		}
	}
	UE_LOG(LogJMPrototypeTravelTransition, Display, TEXT("Arrival cover dismissed; revealing destination world."));
}

void UJMPrototypeTravelTransitionSubsystem::RemoveArrivalScreen()
{
	if (!ArrivalOverlayWidget.IsValid())
	{
		return;
	}
	if (UWorld* LoadedWorld = ArrivalWorld.Get())
	{
		if (UGameViewportClient* GameViewport = LoadedWorld->GetGameViewport())
		{
			GameViewport->RemoveViewportWidgetContent(ArrivalOverlayWidget.ToSharedRef());
		}
	}
	ArrivalOverlayWidget.Reset();
	ArrivalWorld.Reset();
}
