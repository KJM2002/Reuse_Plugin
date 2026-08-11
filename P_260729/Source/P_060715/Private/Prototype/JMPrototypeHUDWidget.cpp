#include "Prototype/JMPrototypeHUDWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Prototype/JMPrototypeProgressionSubsystem.h"
#include "TimerManager.h"

#define LOCTEXT_NAMESPACE "JMPrototypeHUD"

void UJMPrototypeHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (!WidgetTree->RootWidget)
	{
		UCanvasPanel* Canvas = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("PrototypeCanvas"));
		WidgetTree->RootWidget = Canvas;
		UBorder* Panel = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("PrototypePanel"));
		Panel->SetPadding(FMargin(18.0f, 12.0f));
		Panel->SetBrushColor(FLinearColor(0.01f, 0.02f, 0.025f, 0.82f));
		UVerticalBox* Box = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("PrototypeInfo"));
		Panel->SetContent(Box);
		if (UCanvasPanelSlot* PanelSlot = Canvas->AddChildToCanvas(Panel))
		{
			PanelSlot->SetPosition(FVector2D(24.0f, 24.0f));
			PanelSlot->SetSize(FVector2D(760.0f, 140.0f));
		}
		StateText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("StateText"));
		StateText->SetColorAndOpacity(FSlateColor(FLinearColor(0.72f, 1.0f, 0.78f)));
		StateText->SetFont(FSlateFontInfo(StateText->GetFont().FontObject, 24));
		Box->AddChildToVerticalBox(StateText);
		CurrencyText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("CurrencyText"));
		CurrencyText->SetColorAndOpacity(FSlateColor(FLinearColor(1.0f, 0.82f, 0.25f)));
		CurrencyText->SetFont(FSlateFontInfo(CurrencyText->GetFont().FontObject, 20));
		Box->AddChildToVerticalBox(CurrencyText);
		NotificationText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("NotificationText"));
		NotificationText->SetFont(FSlateFontInfo(NotificationText->GetFont().FontObject, 18));
		Box->AddChildToVerticalBox(NotificationText);
	}
	if (UGameInstance* GameInstance = GetGameInstance())
	{
		Progression = GameInstance->GetSubsystem<UJMPrototypeProgressionSubsystem>();
	}
	if (UJMPrototypeProgressionSubsystem* System = Progression.Get())
	{
		System->OnRunStateChanged.AddUniqueDynamic(this, &UJMPrototypeHUDWidget::HandleStateChanged);
		System->OnCurrencyChanged.AddUniqueDynamic(this, &UJMPrototypeHUDWidget::HandleCurrencyChanged);
		System->OnInventoryUpgradeChanged.AddUniqueDynamic(this, &UJMPrototypeHUDWidget::HandleUpgradeChanged);
	}
	Refresh();
}

void UJMPrototypeHUDWidget::NativeDestruct()
{
	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(NotificationTimer);
	}
	if (UJMPrototypeProgressionSubsystem* System = Progression.Get())
	{
		System->OnRunStateChanged.RemoveDynamic(this, &UJMPrototypeHUDWidget::HandleStateChanged);
		System->OnCurrencyChanged.RemoveDynamic(this, &UJMPrototypeHUDWidget::HandleCurrencyChanged);
		System->OnInventoryUpgradeChanged.RemoveDynamic(this, &UJMPrototypeHUDWidget::HandleUpgradeChanged);
	}
	Super::NativeDestruct();
}

void UJMPrototypeHUDWidget::HandleStateChanged(EJMPrototypeRunState, EJMPrototypeRunState) { Refresh(); }
void UJMPrototypeHUDWidget::HandleCurrencyChanged(int32) { Refresh(); }
void UJMPrototypeHUDWidget::HandleUpgradeChanged(bool) { Refresh(); }

void UJMPrototypeHUDWidget::ShowNotification(const FText& Message, bool bSucceeded)
{
	if (!NotificationText)
	{
		return;
	}
	NotificationText->SetText(Message);
	NotificationText->SetColorAndOpacity(FSlateColor(bSucceeded ? FLinearColor(0.45f, 1.0f, 0.55f) : FLinearColor(1.0f, 0.35f, 0.3f)));
	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().SetTimer(NotificationTimer, FTimerDelegate::CreateWeakLambda(this, [this]()
		{
			if (NotificationText)
			{
				NotificationText->SetText(FText::GetEmpty());
			}
		}), 3.0f, false);
	}
}

FText UJMPrototypeHUDWidget::GetObjectiveText(EJMPrototypeRunState State) const
{
	const UJMPrototypeProgressionSubsystem* System = Progression.Get();
	if (!System || !System->HasActiveQuest())
	{
		return LOCTEXT("NoActiveQuest", "[진행 중인 의뢰가 없습니다]");
	}
	const bool bSecondQuest = System->GetActiveQuestIndex() == 1;
	switch (State)
	{
	case EJMPrototypeRunState::AwaitingQuest: return LOCTEXT("Awaiting", "[아직 의뢰가 없습니다]");
	case EJMPrototypeRunState::QuestAccepted:
	case EJMPrototypeRunState::Exploring:
	case EJMPrototypeRunState::Returned:
		return bSecondQuest
			? LOCTEXT("SecondQuest", "의뢰 2: 점액 부산물 2개를 제출하세요")
			: LOCTEXT("FirstQuest", "의뢰 1: 점액 샘플 3개를 제출하세요");
	case EJMPrototypeRunState::QuestCompleted: return LOCTEXT("Completed", "[아직 의뢰가 없습니다]");
	default: return FText::GetEmpty();
	}
}

void UJMPrototypeHUDWidget::Refresh()
{
	UJMPrototypeProgressionSubsystem* System = Progression.Get();
	if (!System || !StateText || !CurrencyText)
	{
		return;
	}
	StateText->SetText(GetObjectiveText(System->GetRunState()));
	const FJMPrototypeConfig Config = System->GetPrototypeConfig();
	CurrencyText->SetText(FText::Format(LOCTEXT("Currency", "기지 화폐: {0}  |  인벤토리: {1}칸{2}"),
		FText::AsNumber(System->GetCurrency()),
		FText::AsNumber(System->HasInventoryUpgrade() ? Config.UpgradedInventorySlots : Config.BaseInventorySlots),
		System->HasInventoryUpgrade() ? LOCTEXT("Upgraded", " (업그레이드 완료)") : FText::GetEmpty()));
}

#undef LOCTEXT_NAMESPACE
