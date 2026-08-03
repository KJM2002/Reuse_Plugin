#include "UI/JMObjectiveDefaultWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/BorderSlot.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"

TSharedRef<SWidget> UJMObjectiveDefaultWidget::RebuildWidget()
{
    if (WidgetTree && !WidgetTree->RootWidget)
    {
        UCanvasPanel* Canvas = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("ObjectiveCanvas"));
        WidgetTree->RootWidget = Canvas;

        UBorder* Border = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("ObjectiveRoot"));
        Border->SetBrushColor(FLinearColor(0.02f, 0.02f, 0.02f, 0.82f));
        Border->SetPadding(FMargin(18.0f, 12.0f));
        UCanvasPanelSlot* BorderCanvasSlot = Canvas->AddChildToCanvas(Border);
        BorderCanvasSlot->SetAnchors(FAnchors(0.0f, 0.0f));
        BorderCanvasSlot->SetPosition(FVector2D(40.0f, 40.0f));
        BorderCanvasSlot->SetSize(FVector2D(430.0f, 150.0f));

        UVerticalBox* Column = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("ObjectiveColumn"));
        Border->SetContent(Column);

        ObjectiveNameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ObjectiveNameText"));
        ObjectiveDescriptionText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ObjectiveDescriptionText"));
        ObjectiveProgressText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ObjectiveProgressText"));
        ObjectiveStateText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ObjectiveStateText"));

        ObjectiveNameText->SetColorAndOpacity(FSlateColor(FLinearColor::White));
        ObjectiveDescriptionText->SetColorAndOpacity(FSlateColor(FLinearColor(0.8f, 0.8f, 0.8f)));
        ObjectiveProgressText->SetColorAndOpacity(FSlateColor(FLinearColor(0.9f, 0.8f, 0.25f)));
        ObjectiveStateText->SetColorAndOpacity(FSlateColor(FLinearColor(0.55f, 0.8f, 1.0f)));

        Column->AddChildToVerticalBox(ObjectiveNameText);
        Column->AddChildToVerticalBox(ObjectiveDescriptionText);
        Column->AddChildToVerticalBox(ObjectiveProgressText);
        Column->AddChildToVerticalBox(ObjectiveStateText);
    }
    return Super::RebuildWidget();
}
