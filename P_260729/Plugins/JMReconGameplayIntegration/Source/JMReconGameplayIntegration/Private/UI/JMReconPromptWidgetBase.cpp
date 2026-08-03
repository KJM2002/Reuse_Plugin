#include "UI/JMReconPromptWidgetBase.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/TextBlock.h"
#include "Styling/CoreStyle.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Text/STextBlock.h"

TSharedRef<SWidget> UJMReconPromptWidgetBase::RebuildWidget()
{
    if (WidgetTree && WidgetTree->RootWidget)
    {
        return Super::RebuildWidget();
    }

    NativeFont = FCoreStyle::GetDefaultFontStyle(
        TEXT("Regular"), FMath::Max(1, AppliedStyle.FontSize));
    TSharedRef<SOverlay> Root = SNew(SOverlay);
    Root->AddSlot()
        .HAlign(HAlign_Center)
        .VAlign(VAlign_Center)
        [
            SAssignNew(NativeOffsetBox, SBox)
            [
                SAssignNew(NativeContainer, SBorder)
                .HAlign(HAlign_Center)
                .VAlign(VAlign_Center)
                [
                    SAssignNew(NativeText, STextBlock)
                    .Font(NativeFont)
                    .Justification(ETextJustify::Center)
                ]
            ]
        ];
    ApplyReconPromptStyle_Implementation(AppliedStyle);
    SetVisibility(ESlateVisibility::Collapsed);
    return Root;
}

void UJMReconPromptWidgetBase::SetReconPrompt_Implementation(
    const FText& Prompt, bool bVisible)
{
    DisplayedPrompt = Prompt;
    if (NativeText.IsValid())
    {
        NativeText->SetText(Prompt);
    }
    if (PromptText)
    {
        PromptText->SetText(Prompt);
    }
    SetVisibility(bVisible && !Prompt.IsEmpty()
        ? ESlateVisibility::HitTestInvisible
        : ESlateVisibility::Collapsed);
}

void UJMReconPromptWidgetBase::ApplyReconPromptStyle_Implementation(
    const FJMInteractionPromptStyle& Style)
{
    AppliedStyle = Style;
    AppliedStyle.FontSize = FMath::Clamp(AppliedStyle.FontSize, 1, 128);
    if (NativeOffsetBox.IsValid())
    {
        NativeOffsetBox->SetRenderTransform(FSlateRenderTransform(FVector2f(
            static_cast<float>(AppliedStyle.ScreenOffset.X),
            static_cast<float>(AppliedStyle.ScreenOffset.Y))));
    }
    if (NativeContainer.IsValid())
    {
        NativeContainer->SetPadding(AppliedStyle.Padding);
    }
    if (NativeText.IsValid())
    {
        NativeFont.Size = AppliedStyle.FontSize;
        NativeText->SetFont(NativeFont);
        NativeText->SetJustification(AppliedStyle.TextJustification.GetValue());
    }
    if (PromptText)
    {
        FSlateFontInfo Font = PromptText->GetFont();
        Font.Size = AppliedStyle.FontSize;
        PromptText->SetFont(Font);
        PromptText->SetJustification(AppliedStyle.TextJustification.GetValue());
        PromptText->SetRenderTranslation(AppliedStyle.ScreenOffset);
    }
    if (PromptContainer)
    {
        PromptContainer->SetPadding(AppliedStyle.Padding);
    }
}
