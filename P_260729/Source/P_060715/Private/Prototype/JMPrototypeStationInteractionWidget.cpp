#include "Prototype/JMPrototypeStationInteractionWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/Spacer.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Framework/Application/SlateApplication.h"
#include "GameFramework/PlayerController.h"
#include "InputCoreTypes.h"
#include "Prototype/JMPrototypeInteractionActorBase.h"

#define LOCTEXT_NAMESPACE "JMPrototypeStationUI"

void UJMPrototypeStationInteractionWidget::InitializeForStation(AJMPrototypeInteractionActorBase* InStation)
{
	Station = InStation;
}

void UJMPrototypeStationInteractionWidget::NativeConstruct()
{
	Super::NativeConstruct();
	CloseButtonText = CloseButtonText.IsEmpty() ? LOCTEXT("Close", "닫기") : CloseButtonText;
	RetryButtonText = RetryButtonText.IsEmpty() ? LOCTEXT("Retry", "다시 시도") : RetryButtonText;
	if (!WidgetTree->RootWidget)
	{
		BuildFallbackLayout();
	}
	if (Button_Confirm) Button_Confirm->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleConfirmClicked);
	if (Button_Close) Button_Close->OnClicked.AddUniqueDynamic(this, &ThisClass::HandleCloseClicked);
	RefreshStationText();
}

void UJMPrototypeStationInteractionWidget::NativeDestruct()
{
	if (Button_Confirm) Button_Confirm->OnClicked.RemoveDynamic(this, &ThisClass::HandleConfirmClicked);
	if (Button_Close) Button_Close->OnClicked.RemoveDynamic(this, &ThisClass::HandleCloseClicked);
	if (AJMPrototypeInteractionActorBase* OwnerStation = Station.Get())
	{
		OwnerStation->HandleInteractionWidgetClosed(this);
	}
	Super::NativeDestruct();
}

void UJMPrototypeStationInteractionWidget::BuildFallbackLayout()
{
	UCanvasPanel* Root = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("Canvas_StationModal"));
	WidgetTree->RootWidget = Root;

	UBorder* Dimmer = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("Border_Dimmer"));
	Dimmer->SetBrushColor(FLinearColor(0.0f, 0.0f, 0.0f, 0.62f));
	if (UCanvasPanelSlot* DimmerSlot = Root->AddChildToCanvas(Dimmer))
	{
		DimmerSlot->SetAnchors(FAnchors(0.0f, 0.0f, 1.0f, 1.0f));
		DimmerSlot->SetOffsets(FMargin(0.0f));
	}

	UBorder* Panel = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("Border_StationPanel"));
	Panel->SetBrushColor(PanelColor);
	Panel->SetPadding(FMargin(28.0f, 24.0f));
	if (UCanvasPanelSlot* PanelSlot = Root->AddChildToCanvas(Panel))
	{
		PanelSlot->SetAnchors(FAnchors(0.5f));
		PanelSlot->SetAlignment(FVector2D(0.5f));
		PanelSlot->SetSize(FVector2D(620.0f, 380.0f));
	}

	UVerticalBox* Layout = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("VerticalBox_Station"));
	Panel->SetContent(Layout);
	Text_Title = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("Text_Title"));
	Text_Title->SetColorAndOpacity(FSlateColor(AccentColor));
	FSlateFontInfo TitleFont = Text_Title->GetFont(); TitleFont.Size = 30; Text_Title->SetFont(TitleFont);
	Layout->AddChildToVerticalBox(Text_Title);

	Text_Description = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("Text_Description"));
	Text_Description->SetAutoWrapText(true);
	Text_Description->SetColorAndOpacity(FSlateColor(FLinearColor(0.9f, 0.94f, 0.96f, 1.0f)));
	FSlateFontInfo BodyFont = Text_Description->GetFont(); BodyFont.Size = 20; Text_Description->SetFont(BodyFont);
	if (UVerticalBoxSlot* DescriptionSlot = Layout->AddChildToVerticalBox(Text_Description))
	{
		DescriptionSlot->SetPadding(FMargin(0.0f, 18.0f, 0.0f, 12.0f));
	}

	Text_Result = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("Text_Result"));
	Text_Result->SetAutoWrapText(true);
	FSlateFontInfo ResultFont = Text_Result->GetFont(); ResultFont.Size = 20; Text_Result->SetFont(ResultFont);
	Layout->AddChildToVerticalBox(Text_Result);

	USpacer* Spacer = WidgetTree->ConstructWidget<USpacer>(USpacer::StaticClass(), TEXT("Spacer_Fill"));
	if (UVerticalBoxSlot* SpacerSlot = Layout->AddChildToVerticalBox(Spacer))
	{
		SpacerSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
	}

	UHorizontalBox* Actions = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("HorizontalBox_Actions"));
	Layout->AddChildToVerticalBox(Actions);
	Button_Confirm = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("Button_Confirm"));
	Text_ConfirmButton = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("Text_ConfirmButton"));
	Text_ConfirmButton->SetJustification(ETextJustify::Center);
	Button_Confirm->SetContent(Text_ConfirmButton);
	if (UHorizontalBoxSlot* ConfirmSlot = Actions->AddChildToHorizontalBox(Button_Confirm))
	{
		ConfirmSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
		ConfirmSlot->SetPadding(FMargin(0.0f, 0.0f, 8.0f, 0.0f));
	}
	Button_Close = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("Button_Close"));
	Text_CloseButton = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("Text_CloseButton"));
	Text_CloseButton->SetJustification(ETextJustify::Center);
	Button_Close->SetContent(Text_CloseButton);
	if (UHorizontalBoxSlot* CloseSlot = Actions->AddChildToHorizontalBox(Button_Close))
	{
		CloseSlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
		CloseSlot->SetPadding(FMargin(8.0f, 0.0f, 0.0f, 0.0f));
	}
}

void UJMPrototypeStationInteractionWidget::RefreshStationText()
{
	AJMPrototypeInteractionActorBase* OwnerStation = Station.Get();
	if (!OwnerStation) return;
	if (Text_Title) Text_Title->SetText(OwnerStation->InteractionTitle);
	if (Text_Description) Text_Description->SetText(OwnerStation->BuildInteractionDescription(FJMInteractionContext()));
	if (Text_Result) Text_Result->SetText(FText::GetEmpty());
	if (Text_ConfirmButton) Text_ConfirmButton->SetText(OwnerStation->ConfirmButtonText);
	if (Text_CloseButton) Text_CloseButton->SetText(CloseButtonText);
}

void UJMPrototypeStationInteractionWidget::ActivateModal()
{
	APlayerController* PlayerController = GetOwningPlayer();
	if (!PlayerController) return;
	ModalPlayerController = PlayerController;
	PlayerController->SetShowMouseCursor(true);
	FInputModeUIOnly InputMode;
	InputMode.SetWidgetToFocus(TakeWidget());
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	PlayerController->SetInputMode(InputMode);
	SetIsFocusable(true);
	SetKeyboardFocus();
}

void UJMPrototypeStationInteractionWidget::HandleConfirmClicked()
{
	AJMPrototypeInteractionActorBase* OwnerStation = Station.Get();
	if (!OwnerStation || bOperationSucceeded) return;
	const FJMPrototypeOperationResult Result = OwnerStation->ConfirmPendingInteraction();
	bOperationSucceeded = Result.bSucceeded;
	if (Text_Description)
	{
		Text_Description->SetText(OwnerStation->BuildInteractionDescription(FJMInteractionContext()));
	}
	if (Text_Result)
	{
		Text_Result->SetText(Result.Message.IsEmpty()
			? (Result.bSucceeded ? LOCTEXT("GenericSuccess", "처리되었습니다.") : LOCTEXT("GenericFailure", "처리하지 못했습니다."))
			: Result.Message);
		Text_Result->SetColorAndOpacity(FSlateColor(Result.bSucceeded ? SuccessColor : FailureColor));
	}
	if (Result.bSucceeded)
	{
		if (Button_Confirm) Button_Confirm->SetIsEnabled(false);
		if (Text_ConfirmButton) Text_ConfirmButton->SetText(LOCTEXT("Completed", "완료"));
	}
	else if (Text_ConfirmButton)
	{
		Text_ConfirmButton->SetText(RetryButtonText);
	}
}

void UJMPrototypeStationInteractionWidget::HandleCloseClicked()
{
	CloseModal();
}

void UJMPrototypeStationInteractionWidget::CloseModal()
{
	if (APlayerController* PlayerController = ModalPlayerController.Get())
	{
		PlayerController->SetInputMode(FInputModeGameOnly());
		PlayerController->SetShowMouseCursor(false);
	}
	RemoveFromParent();
}

FReply UJMPrototypeStationInteractionWidget::NativeOnPreviewKeyDown(
	const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	if (InKeyEvent.GetKey() == EKeys::Escape)
	{
		CloseModal();
		return FReply::Handled();
	}
	if ((InKeyEvent.GetKey() == EKeys::Enter || InKeyEvent.GetKey() == EKeys::E) && !bOperationSucceeded)
	{
		HandleConfirmClicked();
		return FReply::Handled();
	}
	return Super::NativeOnPreviewKeyDown(InGeometry, InKeyEvent);
}

#undef LOCTEXT_NAMESPACE
