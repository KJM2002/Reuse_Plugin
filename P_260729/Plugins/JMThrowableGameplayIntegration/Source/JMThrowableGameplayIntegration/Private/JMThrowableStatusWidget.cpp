#include "JMThrowableStatusWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/TextBlock.h"

void UJMThrowableStatusWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();
    if (!WidgetTree || WidgetTree->RootWidget) return;

    UCanvasPanel* Root = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("Root"));
    WidgetTree->RootWidget = Root;
    UBorder* Background = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("Background"));
    Background->SetBrushColor(FLinearColor(0.015f, 0.015f, 0.015f, 0.72f));
    Background->SetPadding(FMargin(18.f, 10.f));
    StatusText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("StatusText"));
    StatusText->SetColorAndOpacity(FSlateColor(FLinearColor::White));
    StatusText->SetJustification(ETextJustify::Center);
    StatusText->SetFont(FSlateFontInfo(FCoreStyle::GetDefaultFont(), 17));
    Background->SetContent(StatusText);
    UCanvasPanelSlot* CanvasSlot = Root->AddChildToCanvas(Background);
    CanvasSlot->SetAnchors(FAnchors(.5f, 1.f));
    CanvasSlot->SetAlignment(FVector2D(.5f, 1.f));
    CanvasSlot->SetPosition(FVector2D(0.f, -70.f));
    CanvasSlot->SetAutoSize(true);
}

void UJMThrowableStatusWidget::SetThrowableState(EJMThrowableUseState State)
{
    if (!StatusText) return;
    switch (State)
    {
    case EJMThrowableUseState::Ready:
        StatusText->SetText(NSLOCTEXT("JMThrowable", "ReadyHint", "THROWABLE READY  •  HOLD RMB TO AIM  •  Q CANCEL"));
        break;
    case EJMThrowableUseState::Aiming:
        StatusText->SetText(NSLOCTEXT("JMThrowable", "AimHint", "AIMING  •  LMB THROW  •  RELEASE RMB TO LOWER  •  Q CANCEL"));
        break;
    case EJMThrowableUseState::CommittingThrow:
        StatusText->SetText(NSLOCTEXT("JMThrowable", "CommitHint", "THROWING..."));
        break;
    default:
        StatusText->SetText(FText::GetEmpty());
        break;
    }
}
